/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>

void (__cdecl *__mingw_prepare_thread_local_exe_atexit_callback_ptr)(void) __attribute__((common)); /* tentative */
extern void (__cdecl *__MINGW_IMP_SYMBOL(__msvcrt_exit))(int code) __MINGW_ATTRIB_NORETURN;

__MINGW_ATTRIB_NORETURN void __cdecl exit(int code)
{
  /* __mingw_prepare_thread_local_exe_atexit_callback_ptr is thread safe and
   * also can be called multiple times. Registration is done under CRT lock
   * and execution of the registered callback is done exactly once. */
  if (__mingw_prepare_thread_local_exe_atexit_callback_ptr)
    __mingw_prepare_thread_local_exe_atexit_callback_ptr();
  __MINGW_IMP_SYMBOL(__msvcrt_exit)(code);
}
typeof(exit) *__MINGW_IMP_SYMBOL(exit) = exit;
