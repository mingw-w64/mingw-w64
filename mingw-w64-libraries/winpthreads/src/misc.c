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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* public header files */
#include "pthread.h"
/* internal header files */
#include "winpthreads-time.h"

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
#define RUNTIME_CHECKS
#endif

/**
 * Function type corrsponding to `GetHandleInformation`.
 */
typedef BOOL (WINAPI *FuncGetHandleInformation) (HANDLE, LPDWORD);

/**
 * Function type corrsponding to `SetThreadDescription`.
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

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
#define SetThreadDescription WinpthreadsApi.PtrSetThreadDescription
#endif
#endif /* RUNTIME_CHECKS */

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

#if WINPTHREADS_WINNT <= WINPTHREADS_WINNT_WIN10
/**
 * Implementation based on functions available at runtime.
 */
static struct {
  /**
   * Implementation for `winpthreads_set_thread_description_ansi`.
   */
  FuncWinpthreadsSetThreadDescriptionAnsi PtrWinpthreadsSetThreadDescriptionAnsi;
} WinpthreadsImpl;
#endif

#if defined(__GNUC__) || defined(__clang__)
#if __GNUC__ >= 9 && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wprio-ctor-dtor"
#endif
__attribute__ ((constructor (0)))
#endif
static void winpthreads_init (void)
{
#ifdef RUNTIME_CHECKS
  HMODULE kernel32   = GetModuleHandleA ("kernel32.dll");
  HMODULE kernelbase = GetModuleHandleA ("kernelbase.dll");

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  FuncGetHandleInformation ptrGetHandleInformation = NULL;
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

  winpthreads_time_init ();
}
#if defined(__GNUC__) && __GNUC__ >= 9 && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

#if defined(_MSC_VER) && !defined(__clang__)
/* Force a reference to __xc_t to prevent whole program optimization
 * from discarding the variable. */

/* On x86, symbols are prefixed with an underscore. */
#if defined(_M_IX86)
#pragma comment(linker, "/include:___xc_t")
#else
#pragma comment(linker, "/include:__xc_t")
#endif

#pragma section(".CRT$XCT", long, read)
__declspec (allocate (".CRT$XCT"))
extern const _PVFV __xc_t;
const _PVFV __xc_t = winpthreads_init;
#endif

#if WINPTHREADS_WINNT > WINPTHREADS_WINNT_WIN10
#define SetThreadDescriptionAnsi WinpthreadsSetThreadDescriptionAnsi
#else
#define SetThreadDescriptionAnsi WinpthreadsImpl.PtrWinpthreadsSetThreadDescriptionAnsi
#endif

unsigned long winpthreads_wait_for_single_object (void *handle, unsigned long timeout)
{
  DWORD result;
  unsigned long long start_time, end_time;
  unsigned long wait_time;
  long long frequency = 0;

  if (timeout == INFINITE || timeout == 0) {
    return WaitForSingleObject ((HANDLE) handle, (DWORD) timeout);
  }

  start_time = winpthreads_windows_time_ms (&frequency);
  end_time = start_time + timeout;
  wait_time = timeout;

  do {
    unsigned long long current_time;

    result = WaitForSingleObject ((HANDLE) handle, (DWORD) wait_time);

    if (result != WAIT_TIMEOUT) {
      break;
    }

    current_time = winpthreads_windows_time_ms (&frequency);

    if (current_time >= end_time) {
      break;
    }

    wait_time = (DWORD) (end_time - current_time);
  } while (TRUE);

  return result;
}

unsigned long winpthreads_wait_for_multiple_objects (unsigned long count, void **handles, unsigned int all, unsigned long timeout)
{
  DWORD result;
  unsigned long long start_time, end_time;
  unsigned long wait_time;
  long long frequency = 0;

  if (timeout == INFINITE || timeout == 0) {
    return WaitForMultipleObjects ((DWORD) count, (HANDLE *) handles, all, (DWORD) timeout);
  }

  start_time = winpthreads_windows_time_ms (&frequency);
  end_time = start_time + timeout;
  wait_time = timeout;

  do {
    unsigned long long current_time;

    result = WaitForMultipleObjects ((DWORD) count, (HANDLE *) handles, all, (DWORD) wait_time);

    if (result != WAIT_TIMEOUT) {
      break;
    }

    current_time = winpthreads_windows_time_ms (&frequency);

    if (current_time >= end_time) {
      break;
    }

    wait_time = (DWORD) (end_time - current_time);
  } while (TRUE);

  return result;
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
