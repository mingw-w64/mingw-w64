/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* Functions _beginthread() and _beginthreadex() in 32-bit x86 pre-msvcr100 libraries do not handle STATUS_FLOAT_MULTIPLE_FAULTS and STATUS_FLOAT_MULTIPLE_TRAPS SEH exceptions.
 * These two SEH exceptions are thrown by Windows system for 32-bit x86 processes when SSE floating point exception occurs.
 * So fix the pre-msvcr100 behavior by catching those two exceptions manually and propagating them to __mingw_SEH_signal_dispatcher() which correctly process them.
 * x87 floating point exceptions and also 64-bit x86 processes are correctly handled by msvcr* libraries. */

#include "../crt/seh_signal_dispatcher.h"

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl sse_float_exception_handler(EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame, CONTEXT *ContextRecord, PVOID DispatcherContext)
{
  if (ExceptionRecord->ExceptionCode == STATUS_FLOAT_MULTIPLE_FAULTS || ExceptionRecord->ExceptionCode == STATUS_FLOAT_MULTIPLE_TRAPS)
    return __mingw_SEH_signal_dispatcher(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  else
    return ExceptionContinueSearch;
}
