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

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* public header files */
#include "pthread.h"
/* internal header files */
#include "misc.h"
#include "winpthreads-time.h"

/**
 * Function type corrsponding to `GetHandleInformation`.
 */
typedef BOOL (WINAPI *FuncGetHandleInformation) (HANDLE, LPDWORD);

/**
 * Function type corrsponding to `SetThreadDescription`.
 */
typedef HRESULT (WINAPI *FuncSetThreadDescription) (HANDLE, PCWSTR);

FuncGetHandleInformation _pthread_get_handle_information = NULL;
FuncSetThreadDescription _pthread_set_thread_description = NULL;

#if defined(__GNUC__) || defined(__clang__)
#if __GNUC__ >= 9 && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wprio-ctor-dtor"
#endif
__attribute__ ((constructor (0)))
#endif
static void winpthreads_init (void)
{
  HMODULE kernel32   = GetModuleHandleA ("kernel32.dll");
  HMODULE kernelbase = GetModuleHandleA ("kernelbase.dll");

  if (kernel32 != NULL) {
    _pthread_get_handle_information = (FuncGetHandleInformation) (UINT_PTR) GetProcAddress (kernel32, "GetHandleInformation");
    _pthread_set_thread_description = (FuncSetThreadDescription) (UINT_PTR) GetProcAddress (kernel32, "SetThreadDescription");
  }

  if (kernelbase != NULL) {
    /**
     * Although `SetThreadDescription` lives in kernel32.dll,
     * on Windows Server 2016, Windows 10 LTSB 2016 and Windows 10 version 1607,
     * it was only available in kernelbase.dll.
     */
    if (_pthread_set_thread_description == NULL) {
      _pthread_set_thread_description = (FuncSetThreadDescription) (UINT_PTR) GetProcAddress (kernelbase, "SetThreadDescription");
    }
  }

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
