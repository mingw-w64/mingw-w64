/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stddef.h>
#include <errno.h>
#include <process.h>
#include <windows.h>

#if defined(__SEH__) && (!defined(__clang__) || __clang_major__ >= 7)
#define SEH_INLINE_ASM
#ifdef __arm__
#define ASM_SEH_EXCEPT "%%except"
#else
#define ASM_SEH_EXCEPT "@except"
#endif
#endif

#include "../crt/seh_signal_dispatcher.h"

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static DWORD WINAPI thread_func(void *data)
{
  unsigned ret;
  void **thread_args = data;
  _beginthreadex_proc_type start_address = thread_args[0];
  void *arglist = thread_args[1];
  free(thread_args);

  /* Registration of SEH error handler __mingw_SEH_signal_dispatcher used for
   * delivering SEH exceptions to registered CRT signal handlers. */
#if defined(__i386__)
  EXCEPTION_REGISTRATION_RECORD exception_record = {
    .Next = (EXCEPTION_REGISTRATION_RECORD *)__readfsdword(0),
    .Handler = (PEXCEPTION_ROUTINE)(INT_PTR)__mingw_SEH_signal_dispatcher,
  };
  __writefsdword(0, (DWORD)&exception_record);
#elif defined(SEH_INLINE_ASM)
  asm volatile (".seh_handler %c0, " ASM_SEH_EXCEPT :: "i" (__mingw_SEH_signal_dispatcher));
#endif

  ret = start_address(arglist);

#if defined(__i386__)
  __writefsdword(0, (DWORD)exception_record.Next);
#endif

  return ret;
}

/* mingw-w64 _beginthreadex() implementation is wrapper around the WinAPI CreateThread function with C signal handler dispatcher. */
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
  ret = (uintptr_t)CreateThread(security, stack_size, thread_func, thread_args, initflag, (DWORD *)thrdaddr ?: &(DWORD){0});
  if (!ret) {
    free(thread_args);
    errno = EINVAL;
  }
  return ret;
}
uintptr_t (__cdecl *__MINGW_IMP_SYMBOL(_beginthreadex))(void *, unsigned, _beginthreadex_proc_type, void *, unsigned, unsigned *) = _beginthreadex;
