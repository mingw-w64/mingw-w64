/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

/* Function _beginthread() in pre-msvcr100 libraries do not handle STATUS_FLOAT_MULTIPLE_FAULTS and STATUS_FLOAT_MULTIPLE_TRAPS SEH exceptions.
 * These two SEH exceptions are thrown by Windows system for 32-bit x86 processes when SSE floating point exception occurs.
 * So fix the pre-msvcr100 behavior by catching those two exceptions manually and propagating them to __mingw_SEH_error_handler() which correctly process them.
 * x87 floating point exceptions and also 64-bit x86 processes are correctly handled by msvcr* libraries. */

#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <windows.h>

EXCEPTION_DISPOSITION __cdecl __mingw_SEH_error_handler(EXCEPTION_RECORD *, PVOID, CONTEXT *, PVOID);

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static EXCEPTION_DISPOSITION __cdecl sse_float_exception_handler(EXCEPTION_RECORD *ExceptionRecord, PVOID EstablisherFrame, CONTEXT *ContextRecord, PVOID DispatcherContext)
{
  if (ExceptionRecord->ExceptionCode == STATUS_FLOAT_MULTIPLE_FAULTS || ExceptionRecord->ExceptionCode == STATUS_FLOAT_MULTIPLE_TRAPS)
    return __mingw_SEH_error_handler(ExceptionRecord, EstablisherFrame, ContextRecord, DispatcherContext);
  else
    return ExceptionContinueSearch;
}

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __cdecl thread_func(void *data)
{
  void **thread_args = data;
  _beginthread_proc_type start_address = thread_args[0];
  void *arglist = thread_args[1];
  free(thread_args);
  EXCEPTION_REGISTRATION_RECORD exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)sse_float_exception_handler,
  };
  __writefsdword(0, (DWORD)&exception_record);
  start_address(arglist);
  __writefsdword(0, (DWORD)exception_record.Next);
}

uintptr_t __cdecl __msvcrt_beginthread(_beginthread_proc_type start_address, unsigned stack_size, void *arglist);
uintptr_t __cdecl _beginthread(_beginthread_proc_type start_address, unsigned stack_size, void *arglist)
{
  uintptr_t ret;
  void **thread_args = malloc(2 * sizeof(void *));
  if (!thread_args) {
    errno = ENOMEM;
    return 0;
  }
  thread_args[0] = (void *)start_address;
  thread_args[1] = arglist;
  ret = __msvcrt_beginthread(thread_func, stack_size, thread_args);
  if (ret == (uintptr_t)-1)
    free(thread_args);
  return ret;
}
uintptr_t (__cdecl *__MINGW_IMP_SYMBOL(_beginthread))(_beginthread_proc_type, unsigned, void *) = _beginthread;

#endif
