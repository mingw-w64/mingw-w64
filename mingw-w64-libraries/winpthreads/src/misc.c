/*
   Copyright (c) 2011-2016, 2026 mingw-w64 project

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#include "misc.h"

#include <stdlib.h> /* free, malloc */

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
#define RUNTIME_CHECKS
#endif

/**
 * Function type corresponding to `GetHandleInformation`.
 */
typedef BOOL (WINAPI *FuncGetHandleInformation) (HANDLE, LPDWORD);

/**
 * Function type corresponding to `WaitOnAddress`.
 */
typedef BOOL (WINAPI *FuncWaitOnAddress) (VOID volatile *, VOID *, SIZE_T, DWORD);

/**
 * Function type corresponding to `WakeByAddressSingle` and `WakeByAddressAll`.
 */
typedef VOID (WINAPI *FuncWakeByAddress) (VOID *);

/**
 * Function type corresponding to `SetThreadDescription`.
 */
typedef HRESULT (WINAPI *FuncSetThreadDescription) (HANDLE, PCWSTR);

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
/**
 * Replacement for `GetHandleInformation`;
 * a simple stub that always fails.
 */
static BOOL WINAPI WinpthreadsGetHandleInformation (HANDLE handle, LPDWORD flags) {
  SetLastError (ERROR_CALL_NOT_IMPLEMENTED);
  return FALSE;
  UNREFERENCED_PARAMETER (handle);
  UNREFERENCED_PARAMETER (flags);
}
#endif

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
/**
 * Replacement for `SetThreadDescription`;
 * a simple stub that always fails.
 */
static HRESULT WINAPI WinpthreadsSetThreadDescription (HANDLE handle, PCWSTR description) {
  return HRESULT_FROM_WIN32 (ERROR_CALL_NOT_IMPLEMENTED);
  UNREFERENCED_PARAMETER (handle);
  UNREFERENCED_PARAMETER (description);
}
#endif

#ifdef RUNTIME_CHECKS
/**
 * Functions which are looked up at runtime.
 */
static struct {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  /**
   * Function `GetHandleInformation` is available since Windows NT 3.5.
   */
  FuncGetHandleInformation PtrGetHandleInformation;
#endif
  /**
   * Functions `WaitOnAddress`, `WakeByAddressSingle` and `WakeByAddressAll`
   * are available since Windows 8.
   */
#if !WINPTHREADS_DEFAULT_FEATURE_WAIT_ON_ADDRESS
  FuncWaitOnAddress PtrWaitOnAddress;
  FuncWakeByAddress PtrWakeByAddressSingle;
  FuncWakeByAddress PtrWakeByAddressAll;
#endif
#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
  /**
   * Function `SetThreadDescription` is available since Windows 10 1607.
   */
  FuncSetThreadDescription PtrSetThreadDescription;
#endif
} WinpthreadsApi;

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
#define GetHandleInformation WinpthreadsApi.PtrGetHandleInformation
#endif

#if !WINPTHREADS_DEFAULT_FEATURE_WAIT_ON_ADDRESS
#define WaitOnAddress       WinpthreadsApi.PtrWaitOnAddress
#define WakeByAddressSingle WinpthreadsApi.PtrWakeByAddressSingle
#define WakeByAddressAll    WinpthreadsApi.PtrWakeByAddressAll
#endif

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
#define SetThreadDescription WinpthreadsApi.PtrSetThreadDescription
#endif
#endif /* RUNTIME_CHECKS */

/**
 * Function type corresponding to `winpthreads_tls`.
 */
typedef unsigned (* FuncWinpthreadsTls) (void);

/**
 * Initialization routine for `winpthreads_tls`
 */
static unsigned WinpthreadsTlsInit (void);

/**
 * Implementation for `winpthreads_tls`.
 */
static unsigned WinpthreadsTls (void);

/**
 * Function type corresponding to `winpthreads_set_thread_description_ansi`.
 */
typedef int (* FuncWinpthreadsSetThreadDescriptionAnsi) (void *, const char *);

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
/**
 * Stubbed implementation for `winpthreads_set_thread_description_ansi`.
 */
static int WinpthreadsStubSetThreadDescriptionAnsi (void *handle, const char *description) {
  return HRESULT_FROM_WIN32 (ERROR_CALL_NOT_IMPLEMENTED);
  UNREFERENCED_PARAMETER (handle);
  UNREFERENCED_PARAMETER (description);
}
#endif

/**
 * Implementation for `winpthreads_set_thread_description_ansi`.
 */
static int WinpthreadsSetThreadDescriptionAnsi (void *handle, const char *description) {
  HRESULT hr;

  int      bufferSize = 0;
  wchar_t *buffer     = NULL;

  bufferSize = MultiByteToWideChar (CP_ACP, 0, description, -1, buffer, bufferSize);

  if (bufferSize == 0) {
    hr = HRESULT_FROM_WIN32 (GetLastError ());
    goto fail;
  }

  buffer = malloc (bufferSize * sizeof (wchar_t));

  if (buffer == NULL) {
    hr = HRESULT_FROM_WIN32 (ERROR_OUTOFMEMORY);
    goto fail;
  }

  int written = MultiByteToWideChar (CP_ACP, 0, description, -1, buffer, bufferSize);

  if (written == 0) {
    hr = HRESULT_FROM_WIN32 (GetLastError ());
    goto fail_free;
  }

  hr = SetThreadDescription (handle, buffer);

fail_free:
  free (buffer);

fail:
  return hr;
}

/**
 * Implementation based on functions available at runtime.
 */
static struct {
  /**
   * Combination of `WINPTHREADS_FEATURE_*` bits describing features
   * available at runtime.
   */
  unsigned Features;
  /**
   * TLS index used by the library.
   */
  unsigned TlsIndex;
  /**
   * Implementation for `winpthreads_tls`.
   *
   * By default, it points to `WinpthreadsTlsInit`, which is used to allocate
   * `TlsIndex`. After `TlsIndex` is allocated, it points to `WinpthreadsTls`,
   * which simply returns `TlsIndex`.
   */
  FuncWinpthreadsTls PtrWinpthreadsTls;
#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
  /**
   * Implementation for `winpthreads_set_thread_description_ansi`.
   */
  FuncWinpthreadsSetThreadDescriptionAnsi PtrWinpthreadsSetThreadDescriptionAnsi;
#endif
} WinpthreadsImpl = {
  .Features = WINPTHREADS_DEFAULT_FEATURES,
  .TlsIndex = TLS_OUT_OF_INDEXES,
  .PtrWinpthreadsTls = WinpthreadsTlsInit,
};

/**
 * The finalization routine.
 *
 * This function is registered with `atexit` in `winpthreads_init`.
 *
 * When winpthreads is a DLL or is linked statically into another DLL,
 * the callback registered with `atexit` is called when the DLL in question
 * is unloading, after `DllMain` is called with `DLL_PROCESS_DETACH`.
 *
 * This provides us a mechanism to free any resources which may be allocated
 * in `winpthreads_init` and other `*_init` functions.
 *
 * Note that `winpthreads_init` is called before `DllMain` is called with
 * `DLL_PROCESS_ATTACH`; any resources allocated from `winpthreads_init`
 * must be deallocated after `DllMain` is called with `DLL_PROCESS_DETACH`.
 */
static void __cdecl winpthreads_fini (void) {
  if (WinpthreadsImpl.TlsIndex != TLS_OUT_OF_INDEXES) {
    TlsFree (WinpthreadsImpl.TlsIndex);
    WinpthreadsImpl.TlsIndex = TLS_OUT_OF_INDEXES;
  }
}

static void winpthreads_init (void)
{
  /**
   * Allocate TLS index if not allocated yet.
   */
  if (WinpthreadsImpl.TlsIndex == TLS_OUT_OF_INDEXES) {
    WinpthreadsImpl.PtrWinpthreadsTls ();
  }

#ifdef RUNTIME_CHECKS
  HMODULE kernel32   = WINPTHREADS_AW (GetModuleHandle) (WINPTHREADS_TEXT ("kernel32.dll"));
  HMODULE kernelbase = WINPTHREADS_AW (GetModuleHandle) (WINPTHREADS_TEXT ("kernelbase.dll"));

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  FuncGetHandleInformation ptrGetHandleInformation = NULL;
#endif
#if !WINPTHREADS_DEFAULT_FEATURE_WAIT_ON_ADDRESS
  FuncWaitOnAddress ptrWaitOnAddress       = NULL;
  FuncWakeByAddress ptrWakeByAddressSingle = NULL;
  FuncWakeByAddress ptrWakeByAddressAll    = NULL;
#endif
#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
  FuncSetThreadDescription ptrSetThreadDescription = NULL;
#endif

  if (kernel32 != NULL) {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
    ptrGetHandleInformation = (FuncGetHandleInformation) (UINT_PTR) GetProcAddress (kernel32, "GetHandleInformation");
#endif
#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
    ptrSetThreadDescription = (FuncSetThreadDescription) (UINT_PTR) GetProcAddress (kernel32, "SetThreadDescription");
#endif
  }

  if (kernelbase != NULL) {
#if !WINPTHREADS_DEFAULT_FEATURE_WAIT_ON_ADDRESS
    ptrWaitOnAddress       = (FuncWaitOnAddress) (UINT_PTR) GetProcAddress (kernelbase, "WaitOnAddress");
    ptrWakeByAddressSingle = (FuncWakeByAddress) (UINT_PTR) GetProcAddress (kernelbase, "WakeByAddressSingle");
    ptrWakeByAddressAll    = (FuncWakeByAddress) (UINT_PTR) GetProcAddress (kernelbase, "WakeByAddressAll");
#endif
#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
    /**
     * Although `SetThreadDescription` lives in kernel32.dll,
     * on Windows Server 2016, Windows 10 LTSB 2016 and Windows 10 version 1607,
     * it was only available in kernelbase.dll.
     */
    if (ptrSetThreadDescription == NULL) {
      ptrSetThreadDescription = (FuncSetThreadDescription) (UINT_PTR) GetProcAddress (kernelbase, "SetThreadDescription");
    }
#endif
  }

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  if (ptrGetHandleInformation != NULL) {
    WinpthreadsApi.PtrGetHandleInformation = ptrGetHandleInformation;
  } else {
    WinpthreadsApi.PtrGetHandleInformation = WinpthreadsGetHandleInformation;
  }
#endif

#if !WINPTHREADS_DEFAULT_FEATURE_WAIT_ON_ADDRESS
  unsigned haveWaitOnAddress = WINPTHREADS_FEATURE_WAIT_ON_ADDRESS;

  if (ptrWaitOnAddress != NULL) {
    WinpthreadsApi.PtrWaitOnAddress = ptrWaitOnAddress;
  } else {
    haveWaitOnAddress &= ~WINPTHREADS_FEATURE_WAIT_ON_ADDRESS;
  }

  if (ptrWakeByAddressSingle != NULL) {
    WinpthreadsApi.PtrWakeByAddressSingle = ptrWakeByAddressSingle;
  } else {
    haveWaitOnAddress &= ~WINPTHREADS_FEATURE_WAIT_ON_ADDRESS;
  }

  if (ptrWakeByAddressAll != NULL) {
    WinpthreadsApi.PtrWakeByAddressAll = ptrWakeByAddressAll;
  } else {
    haveWaitOnAddress &= ~WINPTHREADS_FEATURE_WAIT_ON_ADDRESS;
  }

  WinpthreadsImpl.Features |= haveWaitOnAddress;
#endif

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
  if (ptrSetThreadDescription != NULL) {
    WinpthreadsApi.PtrSetThreadDescription                 = ptrSetThreadDescription;
    WinpthreadsImpl.PtrWinpthreadsSetThreadDescriptionAnsi = WinpthreadsSetThreadDescriptionAnsi;
  } else {
    WinpthreadsApi.PtrSetThreadDescription                 = WinpthreadsSetThreadDescription;
    WinpthreadsImpl.PtrWinpthreadsSetThreadDescriptionAnsi = WinpthreadsStubSetThreadDescriptionAnsi;
  }
#endif
#endif /* RUNTIME_CHECKS */

  winpthreads_affinity_init ();
  winpthreads_time_init ();

  if (atexit (winpthreads_fini) != 0) {
    abort ();
  }
}

/* Prevent whole program optimization from discarding the __xc_t variable. */
#if defined(_MSC_VER) && !defined(__clang__)
/* msvc: Tell linker to always include the public symbol for __xc_t variable. */
/* On x86, symbols are prefixed with an underscore. */
#if defined(_M_IX86)
#pragma comment(linker, "/include:___xc_t")
#else
#pragma comment(linker, "/include:__xc_t")
#endif
/* .CRT$XCB to .CRT$XCY is an array of _PVFV pointers.
 * Pick an arbitrary location for our callback. */
#pragma section(".CRT$XCT", long, read)
__declspec(allocate(".CRT$XCT")) const _PVFV __xc_t = winpthreads_init;
#else
/* gcc: Mark __xc_t variable with used attribute. */
__attribute__ ((used, section(".CRT$XCT"))) static const _PVFV __xc_t = winpthreads_init;
#endif

static unsigned WinpthreadsTlsInit (void) {
  DWORD tlsIndex = TlsAlloc ();

  if (tlsIndex != TLS_OUT_OF_INDEXES) {
    /**
     * It is possible that some other thread allocated TLS index before us.
     */
    DWORD oldTlsIndex = (DWORD) InterlockedCompareExchange (
      (LONG *) &WinpthreadsImpl.TlsIndex, (LONG) tlsIndex, (LONG) TLS_OUT_OF_INDEXES
    );

    if (likely (oldTlsIndex == TLS_OUT_OF_INDEXES)) {
      InterlockedExchangePointer ((void **) &WinpthreadsImpl.PtrWinpthreadsTls, WinpthreadsTls);
    } else {
      TlsFree (tlsIndex);
    }
  }

  /**
   * We cannot continue without TLS index.
   */
  if (WinpthreadsImpl.TlsIndex == TLS_OUT_OF_INDEXES) {
    abort ();
  }

  return WinpthreadsImpl.TlsIndex;
}

static unsigned WinpthreadsTls (void) {
  return WinpthreadsImpl.TlsIndex;
}

#if WINPTHREADS_WINNT > WINPTHREADS_WINNT_WIN10
#define SetThreadDescriptionAnsi WinpthreadsSetThreadDescriptionAnsi
#else
#define SetThreadDescriptionAnsi WinpthreadsImpl.PtrWinpthreadsSetThreadDescriptionAnsi
#endif

unsigned winpthreads_features (void) {
  return WinpthreadsImpl.Features;
}

int winpthreads_wait_on_address (void *address, void *compareAddress, size_t addressSize, unsigned timeout) {
  return WaitOnAddress (address, compareAddress, addressSize, timeout);
}

void winpthreads_wake_by_address (void *address, int wakeAll) {
  if (wakeAll) {
    WakeByAddressAll (address);
  } else {
    WakeByAddressSingle (address);
  }
}

int winpthreads_get_handle_information (void *handle, unsigned *flags) {
  return GetHandleInformation (handle, (LPDWORD) flags);
}

int winpthreads_set_thread_description_ansi (void *handle, const char *description) {
  return SetThreadDescriptionAnsi (handle, description);
}

int winpthreads_set_thread_description_unicode (void *handle, const wchar_t *description) {
  return SetThreadDescription (handle, description);
}

unsigned winpthreads_tls (void) {
  return WinpthreadsImpl.PtrWinpthreadsTls ();
}

int winpthreads_validate_handle (void *handle) {
  if (handle == NULL || handle == INVALID_HANDLE_VALUE) {
    return FALSE;
  }

  DWORD flags;

  /**
   * Function `GetHandleInformation` is available on Win9x systems,
   * but it always fails with `ERROR_CALL_NOT_IMPLEMENTED`.
   */
  if (!GetHandleInformation (handle, &flags)) {
    return GetLastError () == ERROR_CALL_NOT_IMPLEMENTED;
  }

  return TRUE;
}
