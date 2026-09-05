/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <process.h>

const _tls_callback_type __mingw_cxa_atexit_callback_ptr __attribute__((common)); /* tentative */

#if defined(__i386__)
/* We need to make sure that we align the stack to 16 bytes for the sake of SSE */
__attribute__((force_align_arg_pointer))
#endif
static void __stdcall tls_exe_atexit_callback(void *handle, unsigned long reason, void *reserved)
{
  if (__mingw_cxa_atexit_callback_ptr)
    __mingw_cxa_atexit_callback_ptr(handle, reason, reserved);
}

static void __cdecl __mingw_register_thread_local_exe_atexit_callback(void)
{
  _register_thread_local_exe_atexit_callback(tls_exe_atexit_callback);
}

void (__cdecl *const __mingw_register_thread_local_exe_atexit_callback_ptr)(void) = __mingw_register_thread_local_exe_atexit_callback; /* override tentative */
extern const uintptr_t __mingw_register_thread_local_exe_atexit_callback_provider __attribute__((alias("__mingw_register_thread_local_exe_atexit_callback_ptr"))); /* nontentative alias */
