/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <stdlib.h>
#include <errno.h>
#include <process.h>
#include <windows.h>

#include "i386_sse_float_exception_handler.h"

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static unsigned __stdcall thread_func(void *data)
{
  unsigned ret;
  void **thread_args = data;
  _beginthreadex_proc_type start_address = thread_args[0];
  void *arglist = thread_args[1];
  free(thread_args);
  EXCEPTION_REGISTRATION_RECORD exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)sse_float_exception_handler,
  };
  __writefsdword(0, (DWORD)&exception_record);
  ret = start_address(arglist);
  __writefsdword(0, (DWORD)exception_record.Next);
  return ret;
}

uintptr_t __cdecl __msvcrt_beginthreadex(void *security, unsigned stack_size, _beginthreadex_proc_type start_address, void *arglist, unsigned initflag, unsigned *thrdaddr);
uintptr_t __cdecl _beginthreadex(void *security, unsigned stack_size, _beginthreadex_proc_type start_address, void *arglist, unsigned initflag, unsigned *thrdaddr)
{
  uintptr_t ret;
  void **thread_args = malloc(2 * sizeof(void *));
  if (!thread_args) {
    errno = ENOMEM;
    return 0;
  }
  thread_args[0] = (void *)start_address;
  thread_args[1] = arglist;
  ret = __msvcrt_beginthreadex(security, stack_size, thread_func, thread_args, initflag, thrdaddr);
  if (!ret)
    free(thread_args);
  return ret;
}
uintptr_t (__cdecl *__MINGW_IMP_SYMBOL(_beginthreadex))(void *, unsigned, _beginthreadex_proc_type, void *, unsigned, unsigned *) = _beginthreadex;

#endif
