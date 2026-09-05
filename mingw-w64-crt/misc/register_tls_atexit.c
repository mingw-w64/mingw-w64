/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <process.h>
#include <stdlib.h>
#include <internal.h>

static _tls_callback_type callback;

static void __cdecl run_callback(void)
{
  /* Ensure that callback is called only once. */
  static int called = 0;
  if (called)
    return;
  called = 1;
  if (callback)
    callback(NULL, DLL_PROCESS_DETACH, 0);
}

/* mingw-w64 exit() wrapper calls this function pointer prior CRT atexit() call
 * to ensure that the registered callback is called before any other callback.
 * If some other code calls the exported exit DLL function directly then the
 * atexit() call inside _register_thread_local_exe_atexit_callback guarantees
 * at least that the callback is called (but does not have to as a first one). */
static void __cdecl set_atexit_callback(void)
{
  atexit(run_callback);
}
void (__cdecl *__mingw_prepare_thread_local_exe_atexit_callback_ptr)(void) = set_atexit_callback;

void __cdecl _register_thread_local_exe_atexit_callback(_tls_callback_type cb)
{
  /* _register_thread_local_exe_atexit_callback cannot be called multiple times. */
  if (callback)
    _amsg_exit(10); /* _RT_ABORT */
  callback = cb;
  /* This should guarantee that the callback is called. It won't be run in the
   * exact right spot as intended to, but it will be run. */
  set_atexit_callback();
}

typeof(_register_thread_local_exe_atexit_callback) *__MINGW_IMP_SYMBOL(_register_thread_local_exe_atexit_callback) = _register_thread_local_exe_atexit_callback;
