/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <signal.h>
#include <float.h>
#include <excpt.h>
#include <windows.h>

int __cdecl __msvcrt_XcptFilter(unsigned long _ExceptionNum, struct _EXCEPTION_POINTERS *_ExceptionPtr);
int __cdecl _XcptFilter(unsigned long _ExceptionNum, struct _EXCEPTION_POINTERS *_ExceptionPtr)
{
  /* Function _XcptFilter() in pre-msvcr100 libraries do not handle STATUS_FLOAT_MULTIPLE_FAULTS and STATUS_FLOAT_MULTIPLE_TRAPS SEH exceptions.
   * These two SEH exceptions are thrown by Windows system for 32-bit x86 processes when SSE floating point exception occurs.
   * So fix the pre-msvcr100 behavior and correctly calls SIGFPE signal handler for these exceptions.
   * x87 floating point exceptions and also 64-bit x86 processes are correctly handled by msvcr* libraries. */
  if (_ExceptionNum == STATUS_FLOAT_MULTIPLE_FAULTS || _ExceptionNum == STATUS_FLOAT_MULTIPLE_TRAPS)
  {
    __p_sig_fn_t handler = signal(SIGFPE, SIG_GET);

    /* Function signal() in pre-msvcr80 libraries do not support SIG_GET, it sets the signal handler to SIG_GET.
     * Detect this behavior and restore the retrieved signal handler back to the correct one. */
    if (signal(SIGFPE, SIG_GET) == SIG_GET)
      signal(SIGFPE, handler);

    if (handler == SIG_DFL)
      return EXCEPTION_CONTINUE_SEARCH;
    else if (handler == SIG_IGN)
      return EXCEPTION_CONTINUE_EXECUTION;
    else
    {
      void *old_pxcptinfoptrs = _pxcptinfoptrs;
      int old_fpecode = _fpecode;

      _pxcptinfoptrs = _ExceptionPtr;
      if (_ExceptionNum == STATUS_FLOAT_MULTIPLE_FAULTS)
        _fpecode = _FPE_MULTIPLE_FAULTS;
      else
        _fpecode = _FPE_MULTIPLE_TRAPS;

      signal(SIGFPE, SIG_DFL);
      ((void(__cdecl*)(int,int))(void(*)(void))handler)(SIGFPE, _fpecode);

      _fpecode = old_fpecode;
      _pxcptinfoptrs = old_pxcptinfoptrs;

      return EXCEPTION_CONTINUE_EXECUTION;
    }
  }
  return __msvcrt_XcptFilter(_ExceptionNum, _ExceptionPtr);
}
int __cdecl (*__MINGW_IMP_SYMBOL(_XcptFilter))(unsigned long, struct _EXCEPTION_POINTERS *) = _XcptFilter;

#endif
