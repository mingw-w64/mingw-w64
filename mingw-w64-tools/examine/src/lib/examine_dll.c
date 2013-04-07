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
#include <winnt.h>
#include <tlhelp32.h>
#include <psapi.h>
#include <imagehlp.h>

#include "examine_log.h"
#include "examine_list.h"
#include "examine_pe.h"
#include "examine_private.h"
#include "examine_stacktrace.h"


typedef struct
{
    char        *filename;
    Exm_List    *dll;
    Exm_Overload overloads[EXM_OVERLOAD_COUNT_CRT];
    char        *crt_name;
    Exm_Sw      *stacktrace;
} Exm_Hook;

static Exm_Hook _exm_hook_instance =
{
    NULL,
    NULL,
    {
        {
            NULL,
            NULL,
            NULL
        },
        {
            NULL,
            NULL,
            NULL
        },
        {
            NULL,
            NULL,
            NULL
        },
        {
            NULL,
            NULL,
            NULL
        }
    },
    NULL,
    NULL
};

Exm_Overload *
exm_hook_instance_overloads_get(void)
{
    return _exm_hook_instance.overloads;
}

Exm_List *
exm_hook_instance_stack_frames_get(void)
{
    return exm_sw_frames_get(_exm_hook_instance.stacktrace);
}

static char *
_exm_hook_crt_name_get(void)
{
    HANDLE                   hf;
    HANDLE                   hmap;
    BYTE                    *base;
    IMAGE_DOS_HEADER        *dos_headers;
    IMAGE_NT_HEADERS        *nt_headers;
    IMAGE_IMPORT_DESCRIPTOR *import_desc;
    char                    *res = NULL;

    hf = CreateFile(_exm_hook_instance.filename, GENERIC_READ, FILE_SHARE_READ,
                    NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hf == INVALID_HANDLE_VALUE)
        return NULL;

    hmap = CreateFileMapping(hf, NULL, PAGE_READONLY | SEC_IMAGE, 0, 0, NULL);
    if (!hmap)
        goto close_file;

    base = (BYTE *)MapViewOfFile(hmap, FILE_MAP_READ, 0, 0, 0);
    if (!base)
        goto unmap;

    dos_headers = (IMAGE_DOS_HEADER *)base;
    nt_headers = (IMAGE_NT_HEADERS *)((BYTE *)dos_headers + dos_headers->e_lfanew);
    import_desc = (IMAGE_IMPORT_DESCRIPTOR *)((BYTE *)dos_headers + nt_headers->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress);

    while (import_desc->Characteristics)
    {
        if(IsBadReadPtr((BYTE *)dos_headers + import_desc->Name,1) == 0)
        {
            char *module_name;

            module_name = (char *)((BYTE *)dos_headers + import_desc->Name);
            EXM_LOG_DBG("Imports from %s\r",(BYTE *)dos_headers + import_desc->Name);
            if (lstrcmpi("msvcrt.dll", module_name) == 0)
            {
                EXM_LOG_DBG("msvcrt.dll !!");
                res = _strdup(module_name);
                break;
            }
            if (lstrcmpi("msvcr90.dll", module_name) == 0)
            {
                EXM_LOG_DBG("msvcr90.dll !!");
                res = _strdup(module_name);
                break;
            }
            if (lstrcmpi("msvcr90d.dll", module_name) == 0)
            {
                EXM_LOG_DBG("msvcr90d.dll !!");
                res = _strdup(module_name);
                break;
            }
            import_desc = (IMAGE_IMPORT_DESCRIPTOR *)((BYTE *)import_desc + sizeof(IMAGE_IMPORT_DESCRIPTOR));
        }
        else
            break;
    }

    UnmapViewOfFile(base);
    CloseHandle(hf);

    return res;

  unmap:
    UnmapViewOfFile(base);
  close_file:
    CloseHandle(hf);

    return NULL;
}

static int
_exm_hook_init(void)
{
    HANDLE handle;
    void  *base;
    Exm_List *iter;
    int    length;

    handle = OpenFileMapping(PAGE_READWRITE, FALSE, "shared_size");
    if (!handle)
        return 0;

    base = MapViewOfFile(handle, FILE_MAP_READ, 0, 0, sizeof(int));
    if (!base)
    {
        CloseHandle(handle);
        return 0;
    }

    CopyMemory(&length, base, sizeof(int));
    UnmapViewOfFile(base);
    CloseHandle(handle);

    handle = OpenFileMapping(PAGE_READWRITE, FALSE, "shared_filename");
    if (!handle)
        return 0;

    base = MapViewOfFile(handle, FILE_MAP_READ, 0, 0, length);
    if (!base)
    {
        CloseHandle(handle);
        return 0;
    }

    _exm_hook_instance.filename = malloc(length * sizeof(char));
    if (!_exm_hook_instance.filename)
    {
        UnmapViewOfFile(base);
        CloseHandle(handle);
        return 0;
    }

    CopyMemory(_exm_hook_instance.filename, base, length);
    UnmapViewOfFile(base);
    CloseHandle(handle);

    printf(" ** filename : %s\n", _exm_hook_instance.filename);

    _exm_hook_instance.dll = exm_list_append(_exm_hook_instance.dll,
                                             strdup(_exm_hook_instance.filename));
    _exm_hook_instance.dll = exm_pe_modules_list_get(_exm_hook_instance.dll,
                                                     _exm_hook_instance.filename);
    iter = _exm_hook_instance.dll;
    while (iter)
    {
        char *full_name;

        full_name = exm_pe_dll_path_find(iter->data);
        free(iter->data);
        iter->data = full_name;
        iter = iter->next;
    }

    memcpy(_exm_hook_instance.overloads, exm_overloads_instance, sizeof(_exm_hook_instance.overloads));

    _exm_hook_instance.crt_name = _exm_hook_crt_name_get();

    _exm_hook_instance.stacktrace = exm_sw_init();

    return 1;
}

static void
_exm_hook_shutdown(void)
{
    if (_exm_hook_instance.stacktrace)
        free(_exm_hook_instance.stacktrace);
    if (_exm_hook_instance.filename)
        free(_exm_hook_instance.filename);
}

static void
_exm_modules_hook_set(HMODULE module, const char *lib_name, PROC old_function_proc, PROC new_function_proc)
{
    PIMAGE_IMPORT_DESCRIPTOR iid;
    PIMAGE_THUNK_DATA        thunk;
    ULONG                    size;

    iid = (PIMAGE_IMPORT_DESCRIPTOR)ImageDirectoryEntryToData(module, TRUE, IMAGE_DIRECTORY_ENTRY_IMPORT, &size);
    if (!iid)
        return;

    while (iid->Name)
    {
        PSTR module_name;

        module_name = (PSTR)((PBYTE) module + iid->Name);
        if (_stricmp(module_name, lib_name) == 0)
            break;
        iid++;
    }

    if (!iid->Name)
        return;

    thunk = (PIMAGE_THUNK_DATA)((PBYTE)module + iid->FirstThunk );
    while (thunk->u1.Function)
    {
        PROC *func;

        func = (PROC *)&thunk->u1.Function;
        if (*func == old_function_proc)
        {
            MEMORY_BASIC_INFORMATION mbi;
            DWORD dwOldProtect;

            VirtualQuery(func, &mbi, sizeof(MEMORY_BASIC_INFORMATION));

            if (!VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_READWRITE, &mbi.Protect))
                return;

            *func = *new_function_proc;
            VirtualProtect(mbi.BaseAddress, mbi.RegionSize, mbi.Protect, &dwOldProtect);
            break;
        }
        thunk++;
    }
}

static void
_exm_hook_modules_hook(const char *lib_name, int crt)
{
    HMODULE      lib_module;
    unsigned int i;
    unsigned int start;
    unsigned int end;

    if (!crt)
    {
        start = 0;
        end = EXM_OVERLOAD_COUNT;
    }
    else
    {
        start = EXM_OVERLOAD_COUNT;
        end = EXM_OVERLOAD_COUNT_CRT;
    }

    lib_module = LoadLibrary(lib_name);

    for (i = start; i < end; i++)
        _exm_hook_instance.overloads[i].func_proc_old = GetProcAddress(lib_module, _exm_hook_instance.overloads[i].func_name_old);

    FreeLibrary(lib_module);

    {
        Exm_List *iter;
        iter = _exm_hook_instance.dll;
        while (iter)
        {
            HMODULE mod;

            mod = GetModuleHandle((char *)iter->data);
            if (mod)
            {
                for (i = start; i < end; i++)
                    _exm_modules_hook_set(mod, lib_name,
                                          _exm_hook_instance.overloads[i].func_proc_old,
                                          _exm_hook_instance.overloads[i].func_proc_new);
            }
            iter = iter->next;
        }
    }
}

static void
_exm_hook_modules_unhook(const char *lib_name, int crt)
{
    unsigned int i;
    unsigned int start;
    unsigned int end;

    if (!crt)
    {
        start = 0;
        end = EXM_OVERLOAD_COUNT;
    }
    else
    {
        start = EXM_OVERLOAD_COUNT;
        end = EXM_OVERLOAD_COUNT_CRT;
    }

    {
        Exm_List *iter;
        iter = _exm_hook_instance.dll;
        while (iter)
        {
            HMODULE mod;

            mod = GetModuleHandle((char *)iter->data);
            if (mod)
            {
                for (i = start; i < end; i++)
                    _exm_modules_hook_set(mod, lib_name,
                                          _exm_hook_instance.overloads[i].func_proc_new,
                                          _exm_hook_instance.overloads[i].func_proc_old);
            }
            iter = iter->next;
        }
    }
}

BOOL APIENTRY DllMain(HMODULE hModule EXM_UNUSED, DWORD ulReason, LPVOID lpReserved EXM_UNUSED)
{
    switch (ulReason)
    {
     case DLL_PROCESS_ATTACH:
         EXM_LOG_DBG("process attach");
         if (!_exm_hook_init())
             return FALSE;
         break;
     case DLL_THREAD_ATTACH:
         EXM_LOG_DBG("thread attach begin");
         _exm_hook_modules_hook("kernel32.dll", 0);
         if (_exm_hook_instance.crt_name)
             _exm_hook_modules_hook(_exm_hook_instance.crt_name, 1);
         EXM_LOG_DBG("thread attach end");
         break;
     case DLL_THREAD_DETACH:
         EXM_LOG_DBG("thread detach");
         break;
     case DLL_PROCESS_DETACH:
     {
         Exm_List *iter;
         int nbr_alloc;
         int nbr_free;
         size_t bytes_allocated;
         size_t bytes_freed;

         EXM_LOG_DBG("process detach");
         nbr_alloc = exm_overload_data_alloc_list_count();
         nbr_free = exm_overload_data_free_list_count();
         bytes_allocated = 0;
         iter = exm_overload_data_alloc_list();
         while (iter)
         {
             bytes_allocated += exm_overload_data_alloc_size_get((Exm_Overload_Data_Alloc *)iter->data);
             iter = iter->next;
         }
         bytes_freed = 0;
         iter = exm_overload_data_free_list();
         while (iter)
         {
           bytes_freed += exm_overload_data_free_size_get((Exm_Overload_Data_Free *)iter->data);
             iter = iter->next;
         }

         if (nbr_alloc != nbr_free)
         {
             int records;
             int record;

             records = nbr_alloc - nbr_free;
             record = 1;
             iter = exm_overload_data_alloc_list();
             while (iter)
             {
                 Exm_Overload_Data_Alloc * da;
                 Exm_List *iter_stack;

                 da = (Exm_Overload_Data_Alloc *)iter->data;
                 if (exm_overload_data_alloc_nbr_free_get(da) != 0)
                 {
                     int at = 1;
                     EXM_LOG_INFO("%Iu bytes in 1 block(s) are definitely lost [%d/%d]",
                                  exm_overload_data_alloc_size_get(da), record, records);
                     iter_stack = exm_overload_data_alloc_stack_get(da);
                     while (iter_stack)
                     {
                         Exm_Sw_Data *frame;

                         frame = (Exm_Sw_Data *)iter_stack->data;
                         if (at)
                         {
                             EXM_LOG_INFO("   at 0x00000000: %s (%s:%d)",
                                          exm_sw_data_function_get(frame),
                                          exm_sw_data_filename_get(frame),
                                          exm_sw_data_line_get(frame));
                             at = 0;
                         }
                         else
                             EXM_LOG_INFO("   by 0x00000000: %s (%s:%d)",
                                          exm_sw_data_function_get(frame),
                                          exm_sw_data_filename_get(frame),
                                          exm_sw_data_line_get(frame));
                         iter_stack = iter_stack->next;
                     }
                     EXM_LOG_INFO("");
                     record++;
                 }
                 iter = iter->next;
             }
         }

         EXM_LOG_INFO("HEAP SUMMARY:");
         EXM_LOG_INFO("    in use at exit: %Iu bytes in %d blocks",
                      bytes_allocated - bytes_freed,
                      nbr_alloc - nbr_free);
         EXM_LOG_INFO("  total heap usage: %d allocs, %d frees, %Iu bytes allocated",
                      nbr_alloc, nbr_free, bytes_allocated);
         EXM_LOG_INFO("");
         EXM_LOG_INFO("LEAK SUMMARY:");
         EXM_LOG_INFO("   definitely lost: %Iu bytes in %d blocks",
                      bytes_allocated - bytes_freed,
                      nbr_alloc - nbr_free);
         _exm_hook_modules_unhook("kernel32.dll", 0);
         if (_exm_hook_instance.crt_name)
             _exm_hook_modules_unhook(_exm_hook_instance.crt_name, 1);
         _exm_hook_shutdown();
         break;
     }
    }

    return TRUE;
}
