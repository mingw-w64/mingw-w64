/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>
#include <stdlib.h>
#include <windows.h>
#define _DECL_DLLMAIN
#include <process.h>
#include <crtdbg.h>

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif
#include <sect_attribs.h>
#include <locale.h>

extern void __cdecl __mingw_do_global_ctors (void);
extern void __cdecl __mingw_do_global_dtors (void);
extern void _pei386_runtime_relocator (void);
extern _PIFV __xi_a[];
extern _PIFV __xi_z[];
extern _PVFV __xc_a[];
extern _PVFV __xc_z[];


/* TLS initialization hook.  */
const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback __attribute__((common)); /* tentative */

void (WINAPI *const __mingw_TLScallback_ptr)(HANDLE,DWORD,LPVOID) __attribute__((common)); /* tentative */
const int __mingw_TLScallback_caller_provider = 1; /* crtdll.c calls __mingw_TLScallback_ptr */

WINBOOL (WINAPI *const __mingw_atexit_tls_callback_ptr)(HANDLE,DWORD,LPVOID) __attribute__((common)); /* tentative */
const int __mingw_atexit_tls_callback_caller_provider = 1; /* crtdll.c calls __mingw_atexit_tls_callback_ptr */

int (__cdecl *const __mingw_dll_atexit_table_func_ptr)(int) __attribute__((common)); /* tentative */

static int __proc_attached = 0;

extern int __mingw_app_type;

WINBOOL WINAPI _CRT_INIT (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  if (dwReason == DLL_PROCESS_DETACH)
    {
      if (__proc_attached > 0)
	__proc_attached--;
      else
	return FALSE;
    }
  if (dwReason == DLL_PROCESS_ATTACH)
    {
      void *lock_free = NULL;
      void *fiberid = ((PNT_TIB)NtCurrentTeb ())->StackBase;
      BOOL nested = FALSE;
      int ret = 0;
      
      while ((lock_free = InterlockedCompareExchangePointer (&__native_startup_lock,
							     fiberid, NULL)) != 0)
	{
	  if (lock_free == fiberid)
	    {
	      nested = TRUE;
	      break;
	    }
	  Sleep(1000);
	}
      if (__native_startup_state != __uninitialized)
	{
	  _amsg_exit (31);
	}
      else
	{
	  __native_startup_state = __initializing;
	  
	  _pei386_runtime_relocator ();
	  if (__mingw_TLScallback_ptr != NULL)
	    __mingw_TLScallback_ptr (hDllHandle, dwReason, lpreserved);
	  if (__mingw_dll_atexit_table_func_ptr != NULL)
	    {
	      ret = __mingw_dll_atexit_table_func_ptr (0 /*init*/);
	      if (ret != 0)
		goto i__leave;
	    }
	  if (__mingw_atexit_tls_callback_ptr != NULL)
	    {
	      if (! __mingw_atexit_tls_callback_ptr (hDllHandle, dwReason, lpreserved))
		{
		  ret = 1;
		  goto i__leave;
		}
	    }
	  ret = _initterm_e (__xi_a, __xi_z);
	  if (ret != 0)
	    goto i__leave;
	  _initterm (__xc_a, __xc_z);
	  __mingw_do_global_ctors ();

	  __native_startup_state = __initialized;
	}
i__leave:
      if (! nested)
	{
	  (void) InterlockedExchangePointer (&__native_startup_lock, NULL);
	}
      if (ret != 0)
	{
	  if (__mingw_atexit_tls_callback_ptr != NULL)
	    __mingw_atexit_tls_callback_ptr (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	  return FALSE;
	}
      if (__dyn_tls_init_callback != NULL)
	{
	  __dyn_tls_init_callback (hDllHandle, DLL_THREAD_ATTACH, lpreserved);
	}
      __proc_attached++;
    }
  else if (dwReason == DLL_PROCESS_DETACH)
    {
      void *lock_free = NULL;
      void *fiberid = ((PNT_TIB)NtCurrentTeb ())->StackBase;
      BOOL nested = FALSE;

      while ((lock_free = InterlockedCompareExchangePointer (&__native_startup_lock, fiberid, NULL)) != 0)
	{
	  if (lock_free == fiberid)
	    {
	      nested = TRUE;
	      break;
	    }
	  Sleep(1000);
	}
      if (__native_startup_state != __initialized)
	{
	  _amsg_exit (31);
	}
      else
	{
	  if (__mingw_TLScallback_ptr != NULL)
	    __mingw_TLScallback_ptr (hDllHandle, dwReason, lpreserved);
	  if (__mingw_atexit_tls_callback_ptr != NULL)
	    __mingw_atexit_tls_callback_ptr (hDllHandle, dwReason, lpreserved);
	  if (__mingw_dll_atexit_table_func_ptr != NULL)
	    __mingw_dll_atexit_table_func_ptr (1 /*execute*/);
	  __mingw_do_global_dtors ();

	  __native_startup_state = __uninitialized;
	}
      if (! nested)
	{
	  (void) InterlockedExchangePointer (&__native_startup_lock, NULL);
	}
    }
  else if (dwReason == DLL_THREAD_DETACH)
    {
      if (__mingw_TLScallback_ptr != NULL)
	 __mingw_TLScallback_ptr (hDllHandle, dwReason, lpreserved);
      if (__mingw_atexit_tls_callback_ptr != NULL)
	{
	  if (! __mingw_atexit_tls_callback_ptr (hDllHandle, dwReason, lpreserved))
	    return FALSE;
	}
    }
  return TRUE;
}

WINBOOL WINAPI DllMainCRTStartup (HANDLE, DWORD, LPVOID);

#if defined(__i386__) || defined(_X86_)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE
   opts in DllMain or in functions called from DllMain.  */
__attribute__((force_align_arg_pointer))
#endif
__attribute__((used)) /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
WINBOOL WINAPI
DllMainCRTStartup (HANDLE hDllHandle, DWORD dwReason, LPVOID lpreserved)
{
  WINBOOL retcode = TRUE;

  if (dwReason == DLL_PROCESS_ATTACH)
    __mingw_app_type = 0;

  __native_dllmain_reason = dwReason;
  if (dwReason == DLL_PROCESS_DETACH && __proc_attached <= 0)
    {
	retcode = FALSE;
	goto i__leave;
    }

  if (dwReason == DLL_PROCESS_ATTACH || dwReason == DLL_THREAD_ATTACH)
    {
        retcode = _CRT_INIT (hDllHandle, dwReason, lpreserved);
        if (!retcode)
          goto i__leave;
    }
  retcode = DllMain(hDllHandle,dwReason,lpreserved);
  if (dwReason == DLL_PROCESS_ATTACH && ! retcode)
    {
	DllMain (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
	_CRT_INIT (hDllHandle, DLL_PROCESS_DETACH, lpreserved);
    }
  if (dwReason == DLL_PROCESS_DETACH || dwReason == DLL_THREAD_DETACH)
    {
	retcode = _CRT_INIT (hDllHandle, dwReason, lpreserved);
    }
i__leave:
  __native_dllmain_reason = UINT_MAX;
  return retcode ;
}

char __mingw_module_is_dll = 1;
