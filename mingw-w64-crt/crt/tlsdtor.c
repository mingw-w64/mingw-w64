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

extern WINBOOL __mingw_TLScallback (HANDLE hDllHandle, DWORD reason, LPVOID reserved);

#define FUNCS_PER_NODE 30

typedef struct TlsDtorNode {
  int count;
  struct TlsDtorNode *next;
  _PVFV funcs[FUNCS_PER_NODE];
} TlsDtorNode;

#ifndef __CRT_THREAD
#ifdef HAVE_ATTRIBUTE_THREAD
#define __CRT_THREAD	__declspec(thread)
#else
#define __CRT_THREAD    __thread
#endif
#endif

#define DISABLE_MS_TLS 1

#if !defined (DISABLE_MS_TLS)
static __CRT_THREAD TlsDtorNode *dtor_list;
static __CRT_THREAD TlsDtorNode dtor_list_head;
#endif

void WINAPI __dyn_tls_dtor (HANDLE, DWORD, LPVOID);

int __cdecl __tlregdtor (_PVFV);

int __cdecl
__tlregdtor (_PVFV func)
{
  if (!func)
    return 0;
#if !defined (DISABLE_MS_TLS)
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
#endif
  return 0;
}

void WINAPI
__dyn_tls_dtor (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
#if !defined (DISABLE_MS_TLS)
  TlsDtorNode *pnode, *pnext;
  int i;
#endif

  if (dwReason != DLL_THREAD_DETACH && dwReason != DLL_PROCESS_DETACH)
    return;
  /* As TLS variables are detroyed already by DLL_THREAD_DETACH
     call, we have to avoid access on the possible DLL_PROCESS_DETACH
     call the already destroyed TLS vars.
     TODO: The used local thread based variables have to be handled
     manually, so that we can control their lifetime here.  */
#if !defined (DISABLE_MS_TLS)
  if (dwReason != DLL_PROCESS_DETACH)
    {
      for (pnode = dtor_list; pnode != NULL; pnode = pnext)
        {
          for (i = pnode->count - 1; i >= 0; --i)
	    {
	      if (pnode->funcs[i] != NULL)
	        (*pnode->funcs[i])();
	    }
          pnext = pnode->next;
          if (pnext != NULL)
	    free ((void *) pnode);
        }
    }
#endif
  __mingw_TLScallback (hDllHandle, dwReason, lpreserved);
}

_CRTALLOC(".CRT$XLD") PIMAGE_TLS_CALLBACK __xl_d = __dyn_tls_dtor;

int __mingw_initltsdrot_force = 0;
