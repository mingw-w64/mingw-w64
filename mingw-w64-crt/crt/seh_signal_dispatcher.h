/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <excpt.h>
#include <stdlib.h>

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl
__mingw_SEH_error_handler (struct _EXCEPTION_RECORD* ExceptionRecord,
			   void *EstablisherFrame  __attribute__ ((unused)),
			   struct _CONTEXT* ContextRecord,
			   void *DispatcherContext __attribute__ ((unused)))
{
  long action;

  if (ExceptionRecord->ExceptionFlags & EXCEPTION_UNWINDING)
    return ExceptionContinueSearch;

  /* Despite that the CRT _XcptFilter() function is SEH __except filter function,
   * it directly executes the handler registered by CRT signal() function. Normally
   * the SEH __except handler is called based on the SEH __except filter result.
   *
   * If the CRT signal handler function (called by _XcptFilter() function) returns
   * then the CRT _XcptFilter() returns back to us and the action is set to:
   * EXCEPTION_CONTINUE_EXECUTION - execution of the process should continue
   * EXCEPTION_EXECUTE_HANDLER - execution of the process should be aborted
   * EXCEPTION_CONTINUE_SEARCH - parent SEH handler should be called
   */
  action = _XcptFilter(ExceptionRecord->ExceptionCode,
      &(EXCEPTION_POINTERS){.ExceptionRecord = ExceptionRecord, .ContextRecord = ContextRecord});
  switch (action)
    {
    case EXCEPTION_CONTINUE_SEARCH:
      return ExceptionContinueSearch;

    case EXCEPTION_CONTINUE_EXECUTION:
      return ExceptionContinueExecution;

    case EXCEPTION_EXECUTE_HANDLER:
    default:
      /* msvc CRT EXE exception handler just exit process with exception code */
      _exit(ExceptionRecord->ExceptionCode);
    }
}
