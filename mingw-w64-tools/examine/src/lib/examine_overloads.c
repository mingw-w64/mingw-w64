/* Examine - a tool for memory leak detection on Windows
 *
 * Copyright (C) 2012-2013 Vincent Torri.
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdlib.h>
#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include "examine_list.h"
#include "examine_private.h"
#include "examine_stacktrace.h"

typedef enum
{
    EXM_OVERLOAD_FCT_HEAPALLOC,
    EXM_OVERLOAD_FCT_HEAPFREE,
    EXM_OVERLOAD_FCT_MALLOC,
    EXM_OVERLOAD_FCT_FREE
} Exm_Overload_Fct;

struct _Exm_Overload_Data_Alloc
{
    Exm_Overload_Fct fct;
    size_t size;
    void *data;  /* data returned by the allocator */
    int nbr_free_to_do; /* number of free to do, < 0 means double-free */
    Exm_List *stack;
    Exm_List *stack_free; /* the stack of the double free */
};

struct _Exm_Overload_Data_Free
{
    Exm_Overload_Fct fct;
    size_t size;
    Exm_List *stack;
};

/* list of the overloads, data are Exm_Overload_Data_Alloc and Exm_Overload_Data_Free */
typedef struct
{
    Exm_List *alloc;
    Exm_List *free;
} Exm_Overload_Data;

typedef LPVOID (WINAPI *exm_heap_alloc_t)(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
typedef BOOL   (WINAPI *exm_heap_free_t) (HANDLE hHeap, DWORD dwFlags, LPVOID lpMem);
typedef void  *(*exm_malloc_t)           (size_t size);
typedef void   (*exm_free_t)             (void *memblock);


static Exm_Overload_Data _exm_overload_data = { NULL, NULL };

static Exm_Overload_Data_Alloc *
exm_overload_data_alloc_new(Exm_Overload_Fct fct, size_t size, void *data, Exm_List *stack)
{
    Exm_Overload_Data_Alloc *da;

    da = (Exm_Overload_Data_Alloc *)malloc(sizeof(Exm_Overload_Data_Alloc));
    if (!da)
      return NULL;

    da->fct = fct;
    da->size = size;
    da->data = data;
    da->nbr_free_to_do = 1;
    da->stack = stack;
    da->stack_free = NULL;

    return da;
}

static void
exm_overload_data_alloc_free(void *ptr)
{
    Exm_Overload_Data_Alloc *da = ptr;

    if (!da)
        return;

    exm_list_free(da->stack_free, free);
    exm_list_free(da->stack, free);
    free(da);
}

static Exm_Overload_Data_Free *
exm_overload_data_free_new(Exm_Overload_Fct fct, size_t size, Exm_List *stack)
{
    Exm_Overload_Data_Free *df;

    df = (Exm_Overload_Data_Free *)malloc(sizeof(Exm_Overload_Data_Free));
    if (!df)
      return NULL;

    df->fct = fct;
    df->size = size;
    df->stack = stack;

    return df;
}

static void
exm_overload_data_free_free(void *ptr)
{
    Exm_Overload_Data_Free *df = ptr;

    if (!df)
        return;

    exm_list_free(df->stack, free);
    free(df);
}


static LPVOID WINAPI
EXM_HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes)
{
    exm_heap_alloc_t ha;
    Exm_Overload_Data_Alloc *da;
    LPVOID data;
    Exm_List *stack;

    ha = (exm_heap_alloc_t)exm_hook_instance_overloads_get()[0].func_proc_old;
    data = ha(hHeap, dwFlags, dwBytes);

    printf("HeapAlloc !!! %p\n", data);

    stack = exm_hook_instance_stack_frames_get();
    da = exm_overload_data_alloc_new(EXM_OVERLOAD_FCT_HEAPALLOC, dwBytes, data, stack);
    if (da)
    {
        _exm_overload_data.alloc = exm_list_append(_exm_overload_data.alloc, da);
    }

    return data;
}

static BOOL WINAPI
EXM_HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
    exm_heap_free_t hf;
    Exm_Overload_Data_Free *df;
    BOOL res;
    Exm_List *stack;
    Exm_List *iter;
    size_t size = 0;

    printf("HeapFree !!! %p\n", lpMem);

    stack = exm_hook_instance_stack_frames_get();

    iter = _exm_overload_data.alloc;
    while (iter)
    {
        Exm_Overload_Data_Alloc *da;

        da = (Exm_Overload_Data_Alloc *)iter->data;
        if (lpMem == da->data)
        {
            da->nbr_free_to_do--;
            size = da->size;
            if (da->nbr_free_to_do < 0)
                da->stack_free = stack;
        }
        iter = iter->next;
    }

    /* TODO : size == 0 : free sans malloc */

    df = exm_overload_data_free_new(EXM_OVERLOAD_FCT_HEAPFREE, size, stack);
    if (df)
    {
        _exm_overload_data.free = exm_list_append(_exm_overload_data.free, df);
    }

    hf = (exm_heap_free_t)exm_hook_instance_overloads_get()[1].func_proc_old;
    res = hf(hHeap, dwFlags, lpMem);

    return res;
}

static void *
EXM_malloc(size_t size)
{
    exm_malloc_t ma;
    Exm_Overload_Data_Alloc *da;
    void *data;
    Exm_List *stack;

    ma = (exm_malloc_t)exm_hook_instance_overloads_get()[2].func_proc_old;
    data = ma(size);

    printf("malloc !!! %p\n", data);
    stack = exm_hook_instance_stack_frames_get();
    da = exm_overload_data_alloc_new(EXM_OVERLOAD_FCT_MALLOC, size, data, stack);
    if (da)
    {
        _exm_overload_data.alloc = exm_list_append(_exm_overload_data.alloc, da);
    }

    return data;
}

static void
EXM_free(void *memblock)
{
    exm_free_t f;
    Exm_Overload_Data_Free *df;
    Exm_List *stack;
    Exm_List *iter;
    size_t size = 0;

    printf("free !!! %p\n", memblock);

    stack = exm_hook_instance_stack_frames_get();

    iter = _exm_overload_data.alloc;
    while (iter)
    {
        Exm_Overload_Data_Alloc *da;

        da = (Exm_Overload_Data_Alloc *)iter->data;
        if (memblock == da->data)
        {
            da->nbr_free_to_do--;
            size = da->size;
            if (da->nbr_free_to_do < 0)
                da->stack_free = stack;
        }
        iter = iter->next;
    }

    /* TODO : size == 0 : free sans malloc */

    df = exm_overload_data_free_new(EXM_OVERLOAD_FCT_FREE, size, stack);
    if (df)
    {
        _exm_overload_data.free = exm_list_append(_exm_overload_data.free, df);
    }

    f = (exm_free_t)exm_hook_instance_overloads_get()[3].func_proc_old;
    f(memblock);
}


Exm_Overload exm_overloads_instance[EXM_OVERLOAD_COUNT_CRT] =
{
    {
        "HeapAlloc",
        NULL,
        (PROC)EXM_HeapAlloc
    },
    {
        "HeapFree",
        NULL,
        (PROC)EXM_HeapFree
    },
    {
        "malloc",
        NULL,
        (PROC)EXM_malloc
    },
    {
        "free",
        NULL,
        (PROC)EXM_free
    }
};

size_t
exm_overload_data_alloc_size_get(Exm_Overload_Data_Alloc *da)
{
    return da->size;
}

int
exm_overload_data_alloc_nbr_free_get(Exm_Overload_Data_Alloc *da)
{
    return da->nbr_free_to_do;
}

Exm_List *
exm_overload_data_alloc_stack_get(Exm_Overload_Data_Alloc *da)
{
    return da->stack;
}

size_t
exm_overload_data_free_size_get(Exm_Overload_Data_Free *df)
{
    return df->size;
}

Exm_List *
exm_overload_data_alloc_list(void)
{
    return _exm_overload_data.alloc;
}

Exm_List *
exm_overload_data_free_list(void)
{
    return _exm_overload_data.free;
}

int
exm_overload_data_alloc_list_count(void)
{
    return exm_list_count(_exm_overload_data.alloc);
}

int
exm_overload_data_free_list_count(void)
{
    return exm_list_count(_exm_overload_data.free);
}
