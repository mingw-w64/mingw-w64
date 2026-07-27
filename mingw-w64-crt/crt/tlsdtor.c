/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 *
 * Written by Kai Tietz  <kai.tietz@onevision.com>
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <sect_attribs.h>
#include <memory.h>
#include <malloc.h>
#include <corecrt_startup.h>
#include <thread_local.h>

#define FUNCS_PER_NODE 30

typedef struct TlsDtorNode {
  int count;
  struct TlsDtorNode *next;
  _PVFV funcs[FUNCS_PER_NODE];
} TlsDtorNode;

static TlsDtorNode **get_dtor_list_ptr (void)
{
  TlsDtorNode **dtor_list_ptr = __MINGW_ALLOC_THREAD_LOCAL_OR_NULL(TlsDtorNode*);
  return dtor_list_ptr;
}

static TlsDtorNode *get_dtor_list_head_ptr (void)
{
  TlsDtorNode *dtor_list_head_ptr = __MINGW_ALLOC_THREAD_LOCAL_OR_NULL(TlsDtorNode);
  return dtor_list_head_ptr;
}

int __cdecl __tlregdtor (_PVFV);

int __cdecl
__tlregdtor (_PVFV func)
{
  TlsDtorNode **dtor_list_ptr = get_dtor_list_ptr();
  TlsDtorNode *dtor_list_head_ptr = get_dtor_list_head_ptr();
  if (!dtor_list_ptr || !dtor_list_head_ptr)
    return -1;
  #define dtor_list (*dtor_list_ptr)
  #define dtor_list_head (*dtor_list_head_ptr)

  if (dtor_list == NULL)
    {
      dtor_list = &dtor_list_head;
      dtor_list_head.count = 0;
    }
    else if (dtor_list->count == FUNCS_PER_NODE)
    {
      TlsDtorNode *pnode = (TlsDtorNode *) malloc (sizeof (TlsDtorNode));
      if (pnode == NULL)
	return -1;
      pnode->count = 0;
      pnode->next = dtor_list;
      dtor_list = pnode;

      dtor_list->count = 0;
    }
  dtor_list->funcs[dtor_list->count++] = func;

  return 0;
  #undef dtor_list
  #undef dtor_list_head
}

static void WINAPI
__dyn_tls_dtor (HANDLE hDllHandle __attribute__((unused)), DWORD dwReason, LPVOID lpreserved __attribute__((unused)))
{
  TlsDtorNode *pnode, *pnext;
  int i;
  TlsDtorNode **dtor_list_ptr = get_dtor_list_ptr();
  if (!dtor_list_ptr)
    return;

  if (dwReason != DLL_THREAD_DETACH && dwReason != DLL_PROCESS_DETACH)
    return;

  for (pnode = *dtor_list_ptr; pnode != NULL; pnode = pnext)
    {
      for (i = pnode->count - 1; i >= 0; --i)
        {
          if (pnode->funcs[i] != NULL)
            (*pnode->funcs[i])();
        }
      pnext = pnode->next;
      if (pnext != NULL)
        free ((void *) pnode);
      *dtor_list_ptr = pnext;
    }
}

static _CRTALLOC(".CRT$XLD") const PIMAGE_TLS_CALLBACK __xl_d = __dyn_tls_dtor;

/* Force tlssup.c (_tls_used symbol for .tls linker section) to be linked.  */
extern const IMAGE_TLS_DIRECTORY _tls_used;
static __attribute__((destructor)) void _include_tls_used(void) { asm volatile ("" :: "r" (&_tls_used)); }
