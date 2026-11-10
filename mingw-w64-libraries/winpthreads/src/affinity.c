/*
   Copyright (c) 2026 mingw-w64 project

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

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 * File Summary:
 *
 * This file defines function to deal with process and thread affinity.
 */

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
#define RUNTIME_CHECKS
#endif

/**
 * Function type corresponding to `GetProcessAffinityMask`.
 */
typedef BOOL (WINAPI *FuncGetProcessAffinityMask) (HANDLE, DWORD_PTR *, DWORD_PTR *);

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
/**
 * Replacement for `GetProcessAffinityMask`.
 *
 * A simple stub; always returns active processor mask as returned by
 * `GetSystemInfo`.
 */
static BOOL WINAPI WinpthreadsGetProcessAffinityMask (HANDLE , DWORD_PTR *, DWORD_PTR *);
#endif

/**
 * Function type corresponding to `SetProcessAffinityMask`.
 */
typedef BOOL (WINAPI *FuncSetProcessAffinityMask) (HANDLE, DWORD_PTR);

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
/**
 * Replacement for `SetProcessAffinityMask`.
 *
 * A simple stub; succeeds if new process affinity mask is the same as
 * the process affinity mask returned by `GetProcessAffinityMask`.
 */
static BOOL WINAPI WinpthreadsSetProcessAffinityMask (HANDLE, DWORD_PTR);
#endif

#ifdef RUNTIME_CHECKS
/**
 * Functions which are looked up at runtime.
 */
static struct {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  /**
   * Mask of active processors in the system as returned by `GetSystemInfo`;
   * used to implement emulation for `GetProcessAffinityMask`.
   */
  DWORD_PTR ActiveProcessorMask;
  /**
   * Function `GetProcessAffinityMask` is available since Windows NT 3.5;
   * it is available on all Win9x systems.
   */
  FuncGetProcessAffinityMask PtrGetProcessAffinityMask;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  /**
   * Function `SetProcessAffinityMask` is available since Windows NT 4.0
   * and Windows 98.
   */
  FuncSetProcessAffinityMask PtrSetProcessAffinityMask;
#endif
} WinpthreadsAffinityApi = {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  .PtrGetProcessAffinityMask = WinpthreadsGetProcessAffinityMask,
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  .PtrSetProcessAffinityMask = WinpthreadsSetProcessAffinityMask,
#endif
};

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
#define GetProcessAffinityMask WinpthreadsAffinityApi.PtrGetProcessAffinityMask
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
#define SetProcessAffinityMask WinpthreadsAffinityApi.PtrSetProcessAffinityMask
#endif

#endif /* RUNTIME_CHECKS */

void winpthreads_affinity_init (void) {
#ifdef RUNTIME_CHECKS
  HMODULE kernel32 = GetModuleHandleA ("kernel32.dll");

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  FuncGetProcessAffinityMask ptrGetProcessAffinityMask = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  FuncSetProcessAffinityMask ptrSetProcessAffinityMask = NULL;
#endif

  if (kernel32 != NULL) {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
    ptrGetProcessAffinityMask = (FuncGetProcessAffinityMask) (UINT_PTR) GetProcAddress (kernel32, "GetProcessAffinityMask");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
    ptrSetProcessAffinityMask = (FuncSetProcessAffinityMask) (UINT_PTR) GetProcAddress (kernel32, "SetProcessAffinityMask");
#endif
  }

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  if (ptrGetProcessAffinityMask != NULL) {
     WinpthreadsAffinityApi.PtrGetProcessAffinityMask = ptrGetProcessAffinityMask;
  } else {
    /**
     * Function `GetProcessAffinityMask` is only missing on Windows NT 3.1;
     * we can obtain number of active processor in the system by calling
     * `GetSystemInfo`; the emulation for `GetProcessAffinityMask` simply
     * returns this value.
     *
     * Since `SetProcessAffinityMask` is also missing on Windows NT 3.1,
     * the application cannot set process affinity mask, so returning the same
     * value is acceptable.
     */
    SYSTEM_INFO systemInfo;

    GetSystemInfo (&systemInfo);
    WinpthreadsAffinityApi.ActiveProcessorMask = systemInfo.dwActiveProcessorMask;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  if (ptrSetProcessAffinityMask != NULL) {
    WinpthreadsAffinityApi.PtrSetProcessAffinityMask = ptrSetProcessAffinityMask;
  }
#endif
#endif /* RUNTIME CHECKS */
}

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
static BOOL WINAPI WinpthreadsGetProcessAffinityMask (HANDLE process, DWORD_PTR *processAffinityMask, DWORD_PTR *systemAffinityMask) {
  /**
   * We must be called with the pseudo handle returned by `GetCurrentProcess`.
   */
  if (process != GetCurrentProcess ()) {
    return FALSE;
  }

  *processAffinityMask = WinpthreadsAffinityApi.ActiveProcessorMask;
  *systemAffinityMask  = WinpthreadsAffinityApi.ActiveProcessorMask;

  return TRUE;
}
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
static BOOL WINAPI WinpthreadsSetProcessAffinityMask (HANDLE process, DWORD_PTR newProcessAffinityMask) {
  /**
   * We must be called with the pseudo handle returned by `GetCurrentProcess`.
   */
  if (process != GetCurrentProcess ()) {
    return FALSE;
  }

  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;

  if (!GetProcessAffinityMask (process, &processAffinityMask, &systemAffinityMask)) {
    return FALSE;
  }

  if (newProcessAffinityMask != processAffinityMask) {
    return FALSE;
  }

  return TRUE;
}
#endif

/**
 * Returns number of bits set in `value`.
 */
static int WinpthreadsBitCount (uintptr_t value) {
  int count = 0;

  for (; value != 0; value >>= 1) {
    if (value & 0x01) {
      count += 1;
    }
  }

  return count;
}

/*******************************************************************************
 * Public Functions.
 */

int pthread_num_processors_np (void) {
  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;

  if (!GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask)) {
    return 0;
  }

  return WinpthreadsBitCount (processAffinityMask);
}

int pthread_set_num_processors_np (int n) {
  DWORD_PTR SystemAffinityMask;
  DWORD_PTR ProcessAffinityMask;
  DWORD_PTR ProcessNewAffinityMask = 0;
  int r = 0;

  /* need at least 1 */
  n = n ? n : 1;

  if (GetProcessAffinityMask (GetCurrentProcess (), &ProcessAffinityMask, &SystemAffinityMask)) {
    for (; ProcessAffinityMask != 0; ProcessAffinityMask >>= 1) {
      ProcessNewAffinityMask <<= 1;

      if ((ProcessAffinityMask & 1) != 0 && r < n) {
        ProcessNewAffinityMask |= 1;
        r++;
      }
    }

    SetProcessAffinityMask (GetCurrentProcess (), ProcessNewAffinityMask);
  }

  return r;
}
