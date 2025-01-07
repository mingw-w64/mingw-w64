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
#include <corecrt_startup.h>

extern WINBOOL __mingw_TLScallback (HANDLE hDllHandle, DWORD reason, LPVOID reserved);

static _CRTALLOC(".CRT$XDA") _PVFV __xd_a = 0;
static _CRTALLOC(".CRT$XDZ") _PVFV __xd_z = 0;

extern int _CRT_MT;

void WINAPI __dyn_tls_init (HANDLE, DWORD, LPVOID);

void WINAPI
__dyn_tls_init (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  _PVFV *pfunc;
  uintptr_t ps;

  /* We don't let us trick here.  */
  if (_CRT_MT != 2)
   _CRT_MT = 2;

  if (dwReason != DLL_THREAD_ATTACH)
    {
      if (dwReason == DLL_PROCESS_ATTACH)
        __mingw_TLScallback (hDllHandle, dwReason, lpreserved);
      return;
    }

  ps = (uintptr_t) &__xd_a;
  ps += sizeof (uintptr_t);
  for ( ; ps != (uintptr_t) &__xd_z; ps += sizeof (uintptr_t))
    {
      pfunc = (_PVFV *) ps;
      if (*pfunc != NULL)
	(*pfunc)();
    }
}

const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback = __dyn_tls_init;
_CRTALLOC(".CRT$XLC") PIMAGE_TLS_CALLBACK __xl_c = __dyn_tls_init;

int __mingw_initltsdyn_force = 0;
