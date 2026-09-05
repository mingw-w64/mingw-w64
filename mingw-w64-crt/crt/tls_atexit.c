/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <sect_attribs.h>

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <corecrt_startup.h>
#include <process.h>


typedef void (__thiscall * dtor_fn)(void*);
int __mingw_cxa_atexit(dtor_fn dtor, void *obj, void *dso);
int __mingw_cxa_thread_atexit(dtor_fn dtor, void *obj, void *dso);

typedef struct dtor_obj dtor_obj;
struct dtor_obj {
  dtor_fn dtor;
  void *obj;
  dtor_obj *next;
};

HANDLE __dso_handle;
extern const char __mingw_module_is_dll;

static CRITICAL_SECTION lock;
static int inited = 0;
static dtor_obj *global_dtors = NULL;
static DWORD tls_dtors_slot = TLS_OUT_OF_INDEXES;

int __mingw_cxa_atexit(dtor_fn dtor, void *obj, void *dso) {
  if (!inited)
    return 1;
  assert(!dso || dso == &__dso_handle);
  dtor_obj *handler = (dtor_obj *) calloc(1, sizeof(*handler));
  if (!handler)
    return 1;
  handler->dtor = dtor;
  handler->obj = obj;
  EnterCriticalSection(&lock);
  handler->next = global_dtors;
  global_dtors = handler;
  LeaveCriticalSection(&lock);
  return 0;
}

static void run_dtor_list(dtor_obj **ptr) {
  if (!ptr)
    return;
  while (*ptr) {
    dtor_obj *cur = *ptr;
    *ptr = cur->next;
    cur->dtor(cur->obj);
    free(cur);
  }
}

int __mingw_cxa_thread_atexit(dtor_fn dtor, void *obj, void *dso) {
  if (!inited)
    return 1;
  assert(!dso || dso == &__dso_handle);

  dtor_obj **head = (dtor_obj **)TlsGetValue(tls_dtors_slot);
  if (!head) {
    head = (dtor_obj **) calloc(1, sizeof(*head));
    if (!head)
      return 1;
    TlsSetValue(tls_dtors_slot, head);
  }
  dtor_obj *handler = (dtor_obj *) calloc(1, sizeof(*handler));
  if (!handler)
    return 1;
  handler->dtor = dtor;
  handler->obj = obj;
  handler->next = *head;
  *head = handler;
  return 0;
}

static void run_thread_dtor_list(void) {
  dtor_obj **p = (dtor_obj **)TlsGetValue(tls_dtors_slot);
  run_dtor_list(p);
  free(p);
  TlsSetValue(tls_dtors_slot, NULL);
}

/*
 * For EXE builds the tls_atexit_callback() function is called by the exit()
 * function before it calls atexit callbacks. For UCRT builds this is achieved
 * by UCRT directly, for non-UCRT builds this is achieved by the mingw-w64
 * exit() wrapper function. The tls_atexit_callback() function is called
 * indirectly via the __mingw_cxa_atexit_callback_ptr from the mingw-w64
 * callback registered by the CRT _register_thread_local_exe_atexit_callback.
 * If the process does not call CRT exit function and is terminated by different
 * way (e.g. _exit(), _Exit() or ExitProcess()) then the tls_atexit_callback()
 * function is not called at all.
 *
 * For DLL builds the tls_atexit_callback() function is called explicitly from
 * the tls_callback() function which is below. This function is called also when
 * process is terminated by different way (e.g. _exit(), _Exit() or ExitProcess())
 * not just by exit() function.
 *
 * Reason for these differences is the fact that for DLL builds the tls_callback()
 * function is called before invocation of atexit callbacks, but for EXE builds
 * it is called after all atexit callbacks. For DLL builds, all atexit callbacks
 * are executed from the DLL entry point when DLL_PROCESS_DETACH event happens
 * and for EXE builds, they are executed from the CRT exit() function which is
 * called before execution of native PE TLS callbacks.
 *
 * For EXE builds the tls_callback() function is called PE TLS callback and
 * hence after all atexit callbacks. For DLL builds the tls_callback() function
 * is called from DLL entry point before all atexit callbacks. Note that for
 * DLL builds also PE TLS callbacks are executed before all atexit callbacks.
 *
 * mingw cxa dtors (executed by tls_atexit_callback) has to be run before atexit
 * callbacks because it is required for execution of global C++ destructors.
 * So this is why the different behavior for DLL and EXE builds is needed.
 */
static void WINAPI tls_atexit_callback(HANDLE __UNUSED_PARAM(hDllHandle), DWORD dwReason, LPVOID __UNUSED_PARAM(lpReserved)) {
  if (dwReason == DLL_PROCESS_DETACH) {
    run_thread_dtor_list();
    run_dtor_list(&global_dtors);
    if (tls_dtors_slot != TLS_OUT_OF_INDEXES) {
      TlsFree(tls_dtors_slot);
      tls_dtors_slot = TLS_OUT_OF_INDEXES;
    }
  }
}
const _tls_callback_type __mingw_cxa_atexit_callback_ptr = tls_atexit_callback;

/* Force inclusion of code which registers __mingw_cxa_atexit_callback_ptr for EXE builds */
extern const uintptr_t __mingw_register_thread_local_exe_atexit_callback_provider;
static __attribute__((used)) const void *const _include_mingw_cxa_atexit_callback_caller = &__mingw_register_thread_local_exe_atexit_callback_provider;


/*
 * For EXE builds the tls_callback is called PE TLS callback. If the CRT exit
 * function was called then the PE TLS callback for DLL_PROCESS_DETACH event
 * is called after execution of exit function and so after execution of all
 * registered atexit callbacks.
 *
 * For DLL builds the tls_callback is called from DLL entry point. And for
 * the DLL_PROCESS_DETACH event, the tls_callback is called before execution
 * of atexit callbacks.
 */
static WINBOOL WINAPI tls_callback(HANDLE hDllHandle, DWORD dwReason, LPVOID __UNUSED_PARAM(lpReserved)) {
  switch (dwReason) {
  case DLL_PROCESS_ATTACH:
    if (inited == 0) {
      tls_dtors_slot = TlsAlloc();
      if (tls_dtors_slot == TLS_OUT_OF_INDEXES)
        return FALSE;
      InitializeCriticalSection(&lock);
      __dso_handle = hDllHandle;
    }
    inited = 1;
    break;
  case DLL_PROCESS_DETACH:
    /*
     * If there are other threads still running that haven't been detached,
     * we don't attempt to run their destructors (MSVC doesn't either), but
     * simply leak the destructor list and whatever resources the destructors
     * would have released.
     *
     * TL;DR, threads with pending TLS destructors for a DLL
     * need to be joined before unloading the DLL.
     *
     * This gets called both when exiting cleanly (via exit or returning from
     * main, or when a DLL is unloaded), and when exiting bypassing some of
     * the cleanup, by calling _exit or ExitProcess. In the latter cases,
     * destructors (both TLS and global) in loaded DLLs still get called,
     * but none get called for the main executable. This matches what the
     * standard says, but differs from what MSVC does with a dynamically
     * linked CRT (which still runs TLS destructors for the main thread).
     *
     * For DLLs, run dtors when detached explicitly by tls_atexit_callback().
     * For EXEs, run dtors via the thread local atexit callback, to make sure
     * they don't run when exiting the process with _exit or ExitProcess.
     * mingw-w64 thread local atexit callback calls the tls_atexit_callback()
     * and is registered for EXEs by _register_thread_local_exe_atexit_callback.
     */
    if (__mingw_module_is_dll)
      tls_atexit_callback(NULL, DLL_PROCESS_DETACH, NULL);
    if (inited == 1) {
      inited = 0;
      DeleteCriticalSection(&lock);
    }
    break;
  case DLL_THREAD_ATTACH:
    break;
  case DLL_THREAD_DETACH:
    run_thread_dtor_list();
    break;
  }
  return TRUE;
}
WINBOOL (WINAPI *const __mingw_cxa_tls_callback_ptr)(HANDLE,DWORD,LPVOID) = tls_callback;

/* Force inclusion of code which calls __mingw_cxa_tls_callback_ptr */
extern const int __mingw_cxa_tls_callback_caller_provider;
static __attribute__((used)) const void *const _include_mingw_cxa_tls_callback_caller = &__mingw_cxa_tls_callback_caller_provider;
