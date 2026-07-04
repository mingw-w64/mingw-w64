/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>
#include <excpt.h>
#include <process.h>
#include <signal.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <sect_attribs.h>
#include <locale.h>
#include <float.h>
#include <corecrt_startup.h>

#if defined(__SEH__) && (!defined(__clang__) || __clang_major__ >= 7)
#define SEH_INLINE_ASM
#ifdef __arm__
#define ASM_SEH_EXCEPT "%%except"
#else
#define ASM_SEH_EXCEPT "@except"
#endif
#ifdef __arm64ec__
#define ASM_SEH_PREFIX "\"#"
#define ASM_SEH_SUFFIX "\""
#else
#define ASM_SEH_PREFIX ""
#define ASM_SEH_SUFFIX ""
#endif
#endif

extern IMAGE_DOS_HEADER __ImageBase;

int *__cdecl __p__commode(void);

#undef _fmode
extern int _fmode;
#undef _commode
extern int _commode;
extern int _dowildcard;
extern int __globallocalestatus;

static int __cdecl check_managed_app (void);

extern _PIFV __xi_a[];
extern _PIFV __xi_z[];
extern _PVFV __xc_a[];
extern _PVFV __xc_z[];


/* TLS initialization hook.  */
extern const PIMAGE_TLS_CALLBACK __dyn_tls_init_callback;

extern int __mingw_app_type;

static int argc;
extern void __main(void);
static _TCHAR **argv;
static _TCHAR **envp;

static int managedapp;
static int has_cctor = 0;

extern void _pei386_runtime_relocator (void);
EXCEPTION_DISPOSITION __cdecl __mingw_SEH_error_handler (struct _EXCEPTION_RECORD *, void *, struct _CONTEXT *, void *);
static int duplicate_ppstrings (int ac, _TCHAR ***av);

extern int _MINGW_INSTALL_DEBUG_MATHERR;

#ifdef __MINGW_SHOW_INVALID_PARAMETER_EXCEPTION
#define __UNUSED_PARAM_1(x) x
#else
#define __UNUSED_PARAM_1	__UNUSED_PARAM
#endif
static void
__mingw_invalidParameterHandler (const wchar_t * __UNUSED_PARAM_1(expression),
				 const wchar_t * __UNUSED_PARAM_1(function),
				 const wchar_t * __UNUSED_PARAM_1(file),
				 unsigned int    __UNUSED_PARAM_1(line),
				 uintptr_t __UNUSED_PARAM(pReserved))
{
#ifdef __MINGW_SHOW_INVALID_PARAMETER_EXCEPTION
  wprintf(L"Invalid parameter detected in function %s. File: %s Line: %d\n", function, file, line);
  wprintf(L"Expression: %s\n", expression);
#endif
}

#define GCC_MAGIC (('G' << 16) | ('C' << 8) | 'C' | (1U << 29))

#if defined(__i386__) || defined(_X86_)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static LONG WINAPI
cpp_unhandled_exception_filter (EXCEPTION_POINTERS *exception_data)
{
  /* C++ gcc SEH exception is thrown by the libgcc __cxa_throw() function
   * (which calls _Unwind_RaiseException()) or _Unwind_ForcedUnwind() function
   * as a normal continuable SEH exception with the STATUS_GCC_THROW (0x20474343)
   * or STATUS_GCC_FORCED (0x22474343) exception code via the WinAPI RaiseException()
   * call. Both _Unwind_RaiseException() and _Unwind_ForcedUnwind() are expected
   * to return back to the caller (for example __cxa_throw()) if the exception
   * was not handled. So if the gcc SEH exception reaches the application
   * top-level exception handler then handler needs to return execution back to
   * the place which called the RaiseException(). This is done by returning the
   * EXCEPTION_CONTINUE_EXECUTION value from the handler itself.
   * This is needed for proper propagation of unhandled C++ gcc exceptions
   * into the std::terminate() call or into the application handler
   * registered by the std::set_terminate() call.
   */
  if ((exception_data->ExceptionRecord->ExceptionCode & 0x20ffffff) == GCC_MAGIC &&
      !(exception_data->ExceptionRecord->ExceptionFlags & EXCEPTION_NONCONTINUABLE))
    return EXCEPTION_CONTINUE_EXECUTION;

  return EXCEPTION_CONTINUE_SEARCH;
}

static void
safe_flush (void)
{
  fflush (NULL);
}

static int __tmainCRTStartup (void);

int WinMainCRTStartup (void);
__attribute__((used)) /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
int WinMainCRTStartup (void)
{
  __mingw_app_type = 1;
  return __tmainCRTStartup ();
}

int mainCRTStartup (void);
__attribute__((used)) /* required due to GNU LD bug: https://sourceware.org/bugzilla/show_bug.cgi?id=30300 */
int mainCRTStartup (void)
{
  __mingw_app_type = 0;
  return __tmainCRTStartup ();
}

static
#if defined(__i386__) || defined(_X86_)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE
   opts in main or in functions called from main.  */
__attribute__((force_align_arg_pointer))
#endif
__declspec(noinline) int
__tmainCRTStartup (void)
{
    /* Registration of SEH error handler __mingw_SEH_error_handler used for
     * delivering SEH exceptions to registered CRT signal handlers. */
#if defined(__i386__)
    EXCEPTION_REGISTRATION_RECORD exception_record = {
      .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword (0),
      .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)__mingw_SEH_error_handler,
    };
    __writefsdword (0, (DWORD)&exception_record); /* dynamically register SEH error handler, it is active until manually unregistered */
#elif defined(SEH_INLINE_ASM)
    asm volatile (".seh_handler " ASM_SEH_PREFIX "%c0" ASM_SEH_SUFFIX ", " ASM_SEH_EXCEPT :: "i" (__mingw_SEH_error_handler)); /* statically register SEH error handler, it is active only in the current function */
#else
#error unsupported platform
#endif

    void *lock_free = NULL;
    void *fiberid = ((PNT_TIB)NtCurrentTeb())->StackBase;
    BOOL nested = FALSE;
    _startupinfo startinfo;
    int ret = 0;
    while((lock_free = InterlockedCompareExchangePointer (&__native_startup_lock,
							  fiberid, NULL)) != 0)
      {
	if (lock_free == fiberid)
	  {
	    nested = TRUE;
	    break;
	  }
	Sleep(1000);
      }
    if (__native_startup_state == __initializing)
      {
	_amsg_exit (31);
      }
    else if (__native_startup_state == __uninitialized)
      {
	__native_startup_state = __initializing;

	/* Before the UCRT stderr could be opened in full buffering
	 * mode, for example when output goes to a pipe.
	 *
	 * The C standard disallows full buffering on stderr. Note
	 * that line buffering is the same as full buffering in the
	 * Windows CRT, so we have to disable buffering altogether.
	 */
	setvbuf (stderr, NULL, _IONBF, 0);

	/* The C RunTime library flushes stdio streams in response to
	 * DLL_PROCESS_DETACH. This is not entirely safe; other DLLs
	 * may cause instant termination during process shutdown.
	 * Here we add an exit handler to flush streams safely.
	 */
	if (atexit (safe_flush) != 0)
	  _amsg_exit (26); /* _RT_STDIOINIT */

	_pei386_runtime_relocator ();
	_set_invalid_parameter_handler (__mingw_invalidParameterHandler);
	_fpreset ();

	managedapp = check_managed_app ();
	if (__mingw_app_type)
	  __set_app_type (_GUI_APP);
	else
	  __set_app_type (_CONSOLE_APP);

	*__p__fmode () = _fmode;
	*__p__commode () = _commode;

#ifdef _UNICODE
	ret = _wsetargv ();
#else
	ret = _setargv ();
#endif
	if (ret < 0)
	  _amsg_exit (8); /* _RT_SPACEARG */

	if (_MINGW_INSTALL_DEBUG_MATHERR == 1)
	  __setusermatherr (_matherr);

	if (__globallocalestatus == -1)
	  _configthreadlocale (-1);

	if (_initterm_e (__xi_a, __xi_z) != 0)
	  _amsg_exit (10); /* _RT_ABORT */

	startinfo.newmode = _newmode;
#ifdef _UNICODE
	ret = __wgetmainargs (&argc, &argv, &envp, _dowildcard, &startinfo);
#else
	ret = __getmainargs (&argc, &argv, &envp, _dowildcard, &startinfo);
#endif
	if (ret < 0)
	  _amsg_exit (8); /* _RT_SPACEARG */

	ret = duplicate_ppstrings (argc, &argv);
	if (ret != 0)
	  _amsg_exit (8); /* _RT_SPACEARG */

	SetUnhandledExceptionFilter (cpp_unhandled_exception_filter);
	_initterm (__xc_a, __xc_z);
	__main (); /* C++ initialization. */

	__native_startup_state = __initialized;
      }
    else
      has_cctor = 1;
    if (! nested)
      (VOID)InterlockedExchangePointer (&__native_startup_lock, NULL);
    
    if (__dyn_tls_init_callback != NULL)
      __dyn_tls_init_callback (NULL, DLL_THREAD_ATTACH, NULL);

#ifdef _UNICODE
    __winitenv = envp;
#else
    __initenv = envp;
#endif
    ret = _tmain (argc, argv, envp);
    if (!managedapp)
      exit (ret);

    if (has_cctor == 0)
      _cexit ();

#if defined(__i386__)
  __writefsdword (0, (DWORD)exception_record.Next); /* dynamically unregister SEH error handler */
#endif
  return ret;
}

extern int __mingw_initltsdrot_force;
extern int __mingw_initltsdyn_force;
extern int __mingw_initltssuo_force;

static int __cdecl
check_managed_app (void)
{
  PIMAGE_DOS_HEADER pDOSHeader;
  PIMAGE_NT_HEADERS pPEHeader;
  PIMAGE_OPTIONAL_HEADER32 pNTHeader32;
  PIMAGE_OPTIONAL_HEADER64 pNTHeader64;

  /* Force to be linked.  */
  __mingw_initltsdrot_force=1;
  __mingw_initltsdyn_force=1;
  __mingw_initltssuo_force=1;

  pDOSHeader = (PIMAGE_DOS_HEADER) &__ImageBase;
  if (pDOSHeader->e_magic != IMAGE_DOS_SIGNATURE)
    return 0;

  pPEHeader = (PIMAGE_NT_HEADERS)((char *)pDOSHeader + pDOSHeader->e_lfanew);
  if (pPEHeader->Signature != IMAGE_NT_SIGNATURE)
    return 0;

  pNTHeader32 = (PIMAGE_OPTIONAL_HEADER32) &pPEHeader->OptionalHeader;
  switch (pNTHeader32->Magic)
    {
    case IMAGE_NT_OPTIONAL_HDR32_MAGIC:
      if (pNTHeader32->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader32->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    case IMAGE_NT_OPTIONAL_HDR64_MAGIC:
      pNTHeader64 = (PIMAGE_OPTIONAL_HEADER64)pNTHeader32;
      if (pNTHeader64->NumberOfRvaAndSizes <= IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR)
	return 0;
      return !! pNTHeader64->DataDirectory[IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR].VirtualAddress;
    }
  return 0;
}

static int duplicate_ppstrings (int ac, _TCHAR ***av)
{
	_TCHAR **avl;
	int i;
	_TCHAR **n = (_TCHAR **) malloc (sizeof (_TCHAR *) * (ac + 1));
	if (!n) return 1;
	
	avl=*av;
	for (i=0; i < ac; i++)
	  {
		size_t l = sizeof (_TCHAR) * (_tcslen (avl[i]) + 1);
		n[i] = (_TCHAR *) malloc (l);
		if (!n[i]) return 1;
		memcpy (n[i], avl[i], l);
	  }
	n[i] = NULL;
	*av = n;
	return 0;
}

int __cdecl atexit (_PVFV func)
{
    /*
     * msvcrt def file renames the real atexit() function to _crt_atexit().
     * UCRT provides atexit() function only under name _crt_atexit().
     * So redirect call to _crt_atexit() function.
     */
    return _crt_atexit(func);
}

char __mingw_module_is_dll = 0;
