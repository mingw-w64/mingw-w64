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
 *
 * Before Windows 7, Windows supported at most 64 processors;
 * 32 on 32-bit systems and 64 on 64-bit systems.
 *
 * Starting with Windows 7, 64-bit Windows supports more than 64 processors.
 *
 * It introduced notion of processor groups; each processor is assigned to
 * processor group. On system with 64 or less processors, there is only one
 * processor group 0.
 *
 * By default, all threads in a process are assigned to processor group 0.
 * Any thread can be assigned to any processor group at any point.
 *
 * Starting with Windows 11, the default behavior was changed so that instead
 * of assigning all threads in a process to processor group 0, they can be
 * assigned to any processor group; that processor group is referred to as
 * the process' Primary Group.
 *
 * By default, all threads in a process are assigned to that Primary Group.
 * The processor group a thread is assigned to is referred to as
 * the thread's Primary Group.
 */

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7 || WINPTHREADS_WIN9X
#define RUNTIME_CHECKS
#endif

/**
 * Function type corresponding to `GetProcessAffinityMask`.
 */
typedef BOOL (WINAPI *FuncGetProcessAffinityMask) (HANDLE, DWORD_PTR *, DWORD_PTR *);

/**
 * Function type corresponding to `SetThreadAffinityMask`.
 */
typedef DWORD_PTR (WINAPI *FuncSetThreadAffinityMask) (HANDLE, DWORD_PTR);

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
/**
 * Replacement for `GetProcessAffinityMask`.
 *
 * A simple stub; always returns active processor mask as returned by
 * `GetSystemInfo`.
 */
static BOOL WINAPI WinpthreadsGetProcessAffinityMask (HANDLE , DWORD_PTR *, DWORD_PTR *);

/**
 * Replacement for `SetThreadAffinityMask`.
 *
 * A simple stub; succeeds if new thread affinity mask is the same as
 * the process affinity mask returned by `GetProcessAffinityMask`.
 */
static DWORD_PTR WINAPI WinpthreadsSetThreadAffinityMask (HANDLE, DWORD_PTR);
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

/**
 * Function type corresponding to `GetProcessGroupAffinity`.
 */
typedef BOOL (WINAPI *FuncGetProcessGroupAffinity) (HANDLE, USHORT *, USHORT *);

/**
 * Function type corresponding to `GetThreadGroupAffinity`.
 */
typedef BOOL (WINAPI *FuncGetThreadGroupAffinity) (HANDLE, PGROUP_AFFINITY);

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
/**
 * Replacement for `GetProcessGroupAffinity`.
 *
 * Before Windows 7, Windows did not support more than 64 processors
 * as well as did not have notion of processor groups.
 *
 * This function simply acts as if there is only one processor group 0.
 */
static BOOL WINAPI WinpthreadsGetProcessGroupAffinity (HANDLE, USHORT *, USHORT *);

/**
 * Replacement for `GetThreadGroupAffinity`.
 *
 * Before Windows 7, Windows did not support more than 64 processors
 * as well as did not have notion of processor groups.
 *
 * This function simply acts as if the calling thread belongs to
 * processor group 0 and returns the calling thread's affinity mask.
 */
static BOOL WINAPI WinpthreadsGetThreadGroupAffinity (HANDLE, PGROUP_AFFINITY);
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
  /**
   * Function `SetThreadAffinityMask` is available since Windows NT 3.5;
   * it is available on all Win9x systems.
   */
  FuncSetThreadAffinityMask PtrSetThreadAffinityMask;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  /**
   * Function `SetProcessAffinityMask` is available since Windows NT 4.0
   * and Windows 98.
   */
  FuncSetProcessAffinityMask PtrSetProcessAffinityMask;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
  /**
   * Function `GetProcessGroupAffinity` is available since Windows 7.
   */
  FuncGetProcessGroupAffinity PtrGetProcessGroupAffinity;
  /**
   * Function `GetThreadGroupAffinity` is available since Windows 7.
   */
  FuncGetThreadGroupAffinity PtrGetThreadGroupAffinity;
#endif
} WinpthreadsAffinityApi = {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  .PtrGetProcessAffinityMask = WinpthreadsGetProcessAffinityMask,
  .PtrSetThreadAffinityMask  = WinpthreadsSetThreadAffinityMask,
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  .PtrSetProcessAffinityMask = WinpthreadsSetProcessAffinityMask,
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
  .PtrGetProcessGroupAffinity = WinpthreadsGetProcessGroupAffinity,
  .PtrGetThreadGroupAffinity  = WinpthreadsGetThreadGroupAffinity,
#endif
};

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
#define GetProcessAffinityMask WinpthreadsAffinityApi.PtrGetProcessAffinityMask
#define SetThreadAffinityMask  WinpthreadsAffinityApi.PtrSetThreadAffinityMask
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
#define SetProcessAffinityMask WinpthreadsAffinityApi.PtrSetProcessAffinityMask
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
#define GetProcessGroupAffinity WinpthreadsAffinityApi.PtrGetProcessGroupAffinity
#define GetThreadGroupAffinity  WinpthreadsAffinityApi.PtrGetThreadGroupAffinity
#endif

#endif /* RUNTIME_CHECKS */

/**
 * Internal data.
 */
static struct {
  /**
   * The process' Primary Group.
   */
  unsigned PrimaryGroup;
} WinpthreadsAffinityImpl = {
  .PrimaryGroup = 0,
};

void winpthreads_affinity_init (void) {
#ifdef RUNTIME_CHECKS
  HMODULE kernel32 = GetModuleHandleA ("kernel32.dll");

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  FuncGetProcessAffinityMask ptrGetProcessAffinityMask = NULL;
  FuncSetThreadAffinityMask  ptrSetThreadAffinityMask  = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  FuncSetProcessAffinityMask ptrSetProcessAffinityMask = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
  FuncGetProcessGroupAffinity ptrGetProcessGroupAffinity = NULL;
  FuncGetThreadGroupAffinity  ptrGetThreadGroupAffinity  = NULL;
#endif

  if (kernel32 != NULL) {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
    ptrGetProcessAffinityMask = (FuncGetProcessAffinityMask) (UINT_PTR) GetProcAddress (kernel32, "GetProcessAffinityMask");
    ptrSetThreadAffinityMask  = (FuncSetThreadAffinityMask) (UINT_PTR) GetProcAddress (kernel32, "SetThreadAffinityMask");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
    ptrSetProcessAffinityMask = (FuncSetProcessAffinityMask) (UINT_PTR) GetProcAddress (kernel32, "SetProcessAffinityMask");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
    ptrGetProcessGroupAffinity = (FuncGetProcessGroupAffinity) (UINT_PTR) GetProcAddress (kernel32, "GetProcessGroupAffinity");
    ptrGetThreadGroupAffinity  = (FuncGetThreadGroupAffinity) (UINT_PTR) GetProcAddress (kernel32, "GetThreadGroupAffinity");
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

  if (ptrSetThreadAffinityMask != NULL) {
    WinpthreadsAffinityApi.PtrSetThreadAffinityMask = ptrSetThreadAffinityMask;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_4 || WINPTHREADS_WIN9X
  if (ptrSetProcessAffinityMask != NULL) {
    WinpthreadsAffinityApi.PtrSetProcessAffinityMask = ptrSetProcessAffinityMask;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
  if (ptrGetProcessGroupAffinity != NULL) {
    WinpthreadsAffinityApi.PtrGetProcessGroupAffinity = ptrGetProcessGroupAffinity;
  }

  if (ptrGetThreadGroupAffinity != NULL) {
    WinpthreadsAffinityApi.PtrGetThreadGroupAffinity = ptrGetThreadGroupAffinity;
  }
#endif
#endif /* RUNTIME CHECKS */

  /**
   * Functions such as `GetProcessAffinityMask` and `SetProcessAffinityMask`
   * are unaware of processor groups:
   *
   * 1. Starting with Windows 7, they fail if the calling process contains
   *  threads in multiple processor groups.
   *
   * 2. Starting with Windows 11, they were changed to operate on the calling
   *  thread's Primary Group.
   *
   * While new threads are assigned to the calling process' Primary Group
   * by default, they can be assigned to a different processor group at any
   * point. Since the calling thread's Primary Group may be not the same as the
   * calling process' Primary Group, they may result in unexpected behavior.
   *
   * In order to avoid unexpected results, try to figure out the calling
   * process' Primary Group.
   */
  USHORT groupCount = 1;
  USHORT group;

  /**
   * If threads in the calling process are in the same processor group,
   * call to `GetProcessGroupAffinity` will return this group number in `group`.
   */
  if (GetProcessGroupAffinity (GetCurrentProcess (), &groupCount, &group)) {
    WinpthreadsAffinityImpl.PrimaryGroup = group;
  } else {
    /**
     * Otherwise, we rely on somewhat unsafe assumption that the calling thread
     * is in the calling process' Primary Group; this initialization occurs
     * before execution reaches `main`, so chances are good we are called from
     * the main thread.
     */
    GROUP_AFFINITY groupAffinity;

    if (GetThreadGroupAffinity (GetCurrentThread (), &groupAffinity)) {
      WinpthreadsAffinityImpl.PrimaryGroup = groupAffinity.Group;
    }
  }
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

static DWORD_PTR WINAPI WinpthreadsSetThreadAffinityMask (HANDLE thread, DWORD_PTR newThreadAffinityMask) {
  /**
   * We must be called with the pseudo handle returned by `GetCurrentThread`.
   */
  if (thread != GetCurrentThread ()) {
    return 0;
  }

  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;

  if (!GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask)) {
    return 0;
  }

  if (newThreadAffinityMask != processAffinityMask) {
    return 0;
  }

  return newThreadAffinityMask;
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

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN7
static BOOL WINAPI WinpthreadsGetProcessGroupAffinity (HANDLE process, USHORT *groupCount, USHORT *groups) {
  /**
   * We must be called with the pseudo handle returned by `GetCurrentProcess`.
   */
  if (process != GetCurrentProcess ()) {
    return FALSE;
  }

  if (*groupCount == 0) {
    *groupCount = 1;
    SetLastError (ERROR_INSUFFICIENT_BUFFER);
    return FALSE;
  }

  *groupCount = 1;
  groups[0]   = 0;

  return TRUE;
}

static BOOL WINAPI WinpthreadsGetThreadGroupAffinity (HANDLE thread, PGROUP_AFFINITY groupAffinity) {
  /**
   * We must be called with the pseudo handle returned by `GetCurrentThread`.
   */
  if (thread != GetCurrentThread ()) {
    return FALSE;
  }

  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;
  DWORD_PTR threadAffinityMask;

  if (!GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask)) {
    return FALSE;
  }

  /**
   * Before Windows 7, which introduced `GetThreadGroupAffinity`, the only way
   * to obtain the calling thread's affinity mask was to set new affinity mask
   * with `SetThreadAffinityMask`; it returns previous affinity mask.
   */
  threadAffinityMask = SetThreadAffinityMask (thread, processAffinityMask);

  if (threadAffinityMask == 0) {
    return FALSE;
  }

  /**
   * The only reason why this can fail is if the process affinity mask was
   * modified between the calls to `SetThreadAffinityMask`, which is unlikely.
   */
  if (!SetThreadAffinityMask (thread, threadAffinityMask)) {
    threadAffinityMask = processAffinityMask;
  }

  groupAffinity->Group = 0;
  groupAffinity->Mask  = threadAffinityMask;

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
  /**
   * Starting with Windows 11, if the calling process contain threads in
   * multiple processor groups, `GetProcessAffinityMask` operates on
   * the calling thread's Primary Group, which may lead to unexpected results.
   *
   * Check if the calling thread is assigned to the calling process'
   * Primary Group, and fail if not.
   */
  GROUP_AFFINITY threadGroupAffinity;

  if (!GetThreadGroupAffinity (GetCurrentThread (), &threadGroupAffinity)) {
    return 0;
  }

  if (threadGroupAffinity.Group != WinpthreadsAffinityImpl.PrimaryGroup) {
    return 0;
  }

  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;

  if (!GetProcessAffinityMask (GetCurrentProcess (), &processAffinityMask, &systemAffinityMask)) {
    return 0;
  }

  return WinpthreadsBitCount (processAffinityMask);
}

int pthread_set_num_processors_np (int processorCount) {
  HANDLE currentProcess = GetCurrentProcess ();
  HANDLE currentThread  = GetCurrentThread ();

  if (processorCount < 0) {
    return 0;
  }

  /**
   * See comment in `pthread_num_processors_np`.
   */
  GROUP_AFFINITY threadGroupAffinity;

  if (!GetThreadGroupAffinity (currentThread, &threadGroupAffinity)) {
    return 0;
  }

  if (threadGroupAffinity.Group != WinpthreadsAffinityImpl.PrimaryGroup) {
    return 0;
  }

  /**
   * The process affinity mask passed to `SetProcessAffinityMask` must be
   * strict subset of the system affinity mask; otherwise, the call will fail
   * with `ERROR_INVALID_PARAMETER`.
   */
  DWORD_PTR systemAffinityMask;
  DWORD_PTR processAffinityMask;

  if (!GetProcessAffinityMask (currentProcess, &processAffinityMask, &systemAffinityMask)) {
    return 0;
  }

  int maxProcessorCount = WinpthreadsBitCount (systemAffinityMask);
  int oldProcessorCount = WinpthreadsBitCount (processAffinityMask);
  int newProcessorCount = oldProcessorCount;

  /**
   * The calling process' affinity mask is already set to `processorCount`
   * processors.
   */
  if (processorCount == oldProcessorCount) {
    return newProcessorCount;
  }

  /**
   * If the caller requests `maxProcessorCount` or more processors,
   * set the calling process' affinity mask to the system affinity mask.
   *
   * Additionally, treat zero `processorCount` as request to reset
   * the affinity mask of the calling process.
   */
  if (processorCount == 0 || processorCount >= maxProcessorCount) {
    if (SetProcessAffinityMask (currentProcess, systemAffinityMask)) {
      newProcessorCount = maxProcessorCount;
    }

    return newProcessorCount;
  }

  /**
   * When updating the affinity mask, we want to preserve as many bits as
   * possible from `processAffinityMask` instead of populating it from scratch;
   * in some cases, this allows us to prevent unnecessary rescheduling of
   * threads running on processor that otherwise would be removed from
   * the process affinity mask.
   *
   * Consider an example: A process sets the affinity mask so that its threads
   * run on processor 1, 3 and 5.
   *
   * If the process desires to increase number of processors in the affinity
   * mask to 4, this approach will make it use processor 1, 2, 3 and 5 instead
   * of 1, 2, 3, and 4; the thread running on processor 5 is not rescheduled
   * on another processor.
   *
   * If the process desires to decrease number of processors in the affinity
   * mask to 2, this approach will make it use processor 1 and 3 instead
   * of 1 and 2; only the thread running on processor 5 is rescheduled
   * on another processor instead of threads running on processors 3 and 5.
   */
  if (processorCount > oldProcessorCount) {
    for (int i = 0; newProcessorCount != processorCount; ++i) {
      DWORD_PTR processor = (DWORD_PTR) 1 << i;

      if ((systemAffinityMask & processor) && !(processAffinityMask & processor)) {
        processAffinityMask |= processor;
        newProcessorCount   += 1;
      }
    }
  } else {
    for (int i = sizeof(DWORD_PTR) * 8 - 1; newProcessorCount != processorCount; --i) {
      DWORD_PTR processor = (DWORD_PTR) 1 << i;

      if ((processAffinityMask & processor)) {
        processAffinityMask &= ~processor;
        newProcessorCount   -= 1;
      }
    }
  }

  if (!SetProcessAffinityMask (currentProcess, processAffinityMask)) {
    newProcessorCount = oldProcessorCount;
  }

  return newProcessorCount;
}
