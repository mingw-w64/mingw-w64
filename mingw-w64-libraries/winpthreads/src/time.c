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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <time.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define WINPTHREAD_TIME_DECL WINPTHREAD_API

/* public header files */
#include "pthread.h"
/* internal header files */
#include "thread.h"           /* _pthread_delay_np_ms */
#include "winpthreads-time.h"

/**
 * File Summary:
 *
 * This file contains all time-related definitions used by the library,
 * as well as public functions declared in pthread_time.h.
 */

/**
 * Reference:
 *
 * nanosleep():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/nanosleep.html>
 *
 * clock_getres(), clock_gettime(), clock_settime():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/clock_getres.html>
 *
 * clock_nanosleep():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/clock_nanosleep.html>
 *
 * clock_getcpuclockid():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/clock_getcpuclockid.html>
 *
 * This following functions are not implemented:
 *
 * - clock_getcpuclockid()
 */

#define POW10_3 1000
#define POW10_4 10000
#define POW10_6 1000000
#define POW10_7 10000000
#define POW10_9 1000000000

/**
 * This is the maximum amount of milliseconds `nanosleep` can sleep at a time.
 */
#define MAX_SLEEP_IN_MS (INFINITE - 1)

/**
 * Number of 100ns intervals between the beginning of the Windows epoch
 * (Jan. 1, 1601) and the Unix epoch (Jan. 1, 1970)
 */
#define DELTA_EPOCH_IN_100NS INT64_C(116444736000000000)

/*******************************************************************************
 * In order to provide the best coverage in terms of backward compatibility
 * and feature support, we lookup functions which may not be available on older
 * Windows versions at runtime, and use them if they are available.
 *
 * If some function is not available, we provide a simple replacement or stub.
 */

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
#define RUNTIME_CHECKS
#endif

/**
 * Function type corresponding to `GetProcessTimes` and `GetThreadTimes`.
 */
typedef BOOL (WINAPI *FuncGetTimes) (HANDLE, FILETIME *, FILETIME *, FILETIME *, FILETIME *);

/**
 * Function type corresponding to `GetSystemTimeAsFileTime` and
 * `GetSystemTimePreciseAsFileTime`.
 */
typedef VOID (WINAPI *FuncGetSystemTimeAsFileTime) (FILETIME *);

/**
 * Function type corresponding to `GetSystemTimeAdjustment`.
 */
typedef BOOL (WINAPI *FuncGetSystemTimeAdjustment) (DWORD *, DWORD *, BOOL *);

/**
 * Function type corresponding to `GetTickCount64`.
 */
typedef ULONGLONG (WINAPI *FuncGetTickCount64) (VOID);

#ifdef RUNTIME_CHECKS
/**
 * Functions which are looked up at runtime.
 */
typedef struct TimeApi {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
  /**
   * Function `GetSystemTimeAsFileTime` is available since Windows NT 3.51.
   */
  FuncGetSystemTimeAsFileTime PtrGetSystemTimeAsFileTime;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
  /**
   * Function `GetSystemTimePreciseAsFileTime` is available since Windows 8.
   */
  FuncGetSystemTimeAsFileTime PtrGetSystemTimePreciseAsFileTime;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  /**
   * Function `GetSystemTimeAdjustment` is available since Windows NT 3.5.
   */
  FuncGetSystemTimeAdjustment PtrGetSystemTimeAdjustment;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
  /**
   * Function `GetTickCount64` is available since Windows Vista.
   */
  FuncGetTickCount64 PtrGetTickCount64;
#endif
} TimeApi;

static TimeApi WinpthreadsTimeApi;

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
#define GetSystemTimeAdjustment WinpthreadsTimeApi.PtrGetSystemTimeAdjustment
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
#define GetSystemTimeAsFileTime WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
#define GetTickCount64 WinpthreadsTimeApi.PtrGetTickCount64
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
#define GetSystemTimePreciseAsFileTime WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime
#endif
#endif /* RUNTIME_CHECKS */

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
/**
 * Replacement for `GetSystemTimeAsFileTime`;
 * a wrapper around `GetSystemTime` and `SystemTimeToFileTime`
 */
static VOID WINAPI WinpthreadsGetSystemTimeAsFileTime (FILETIME *fileTime) {
  SYSTEMTIME systemTime;

  GetSystemTime (&systemTime);

  /**
   * If call to `SystemTimeToFileTime` fails, store Unix epoch in `fileTime`.
   */
  if (unlikely (!SystemTimeToFileTime (&systemTime, fileTime))) {
    fileTime->dwHighDateTime = (ULARGE_INTEGER) {.QuadPart = DELTA_EPOCH_IN_100NS}.HighPart;
    fileTime->dwLowDateTime  = (ULARGE_INTEGER) {.QuadPart = DELTA_EPOCH_IN_100NS}.LowPart;
  }
}
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
/**
 * Replacement for `GetSystemTimeAdjustment`;
 * a simple stab that always fails.
 */
static BOOL WINAPI WinpthreadsGetSystemTimeAdjustment (DWORD *adjustment, DWORD *increment, BOOL *disable) {
  SetLastError (ERROR_CALL_NOT_IMPLEMENTED);
  return FALSE;
  UNREFERENCED_PARAMETER (adjustment);
  UNREFERENCED_PARAMETER (increment);
  UNREFERENCED_PARAMETER (disable);
}
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
/**
 * Replacement for `GetTickCount64`;
 * a simple wrapper around `GetTickCount`.
 */
static ULONGLONG WINAPI WinpthreadsGetTickCount64 (VOID) {
  return GetTickCount ();
}
#endif

/**
 * Function type for internal implementation of `clock_gettime` and
 * `clock_getres` for a specific clock (`clockid_t`) type.
 *
 * The first argument, if non-NULL, recieves the time.
 * The second argument, if non-NULL, recieves the clock resolution.
 *
 * Returns zero on success and an error-code on failure.
 */
typedef int (* FuncWinpthreadsTimeImpl) (struct _timespec64 *, struct _timespec64 *);

/**
 * Implementation for `CLOCK_REALTIME` using `GetSystemTimeAsFileTime`.
 *
 * This function always succeeds.
 */
static int WinpthreadsTimeImplRealtime (struct _timespec64 *, struct _timespec64 *);

/**
 * Implementation for `CLOCK_REALTIME` using `GetSystemTimePreciseAsFileTime`.
 *
 * This function always succeeds.
 */
static int WinpthreadsTimeImplRealtimePrecise (struct _timespec64 *, struct _timespec64 *);

/**
 * Implementation for `CLOCK_MONOTONIC` using `GetTickCount*`.
 *
 * This function always succeeds.
 */
static int WinpthreadsTimeImplMonotonicFromTickCount (struct _timespec64 *, struct _timespec64 *);

/**
 * Implementation for `CLOCK_MONOTONIC` using `QueryPerformanceCounter`.
 *
 * This function always succeeds.
 *
 * In an unlikely case when call to `QueryPerformanceCounter` fails,
 * this function simply forwards to `WinpthreadsTimeImplMonotonicFromTickCount`.
 */
static int WinpthreadsTimeImplMonotonicFromPerformanceCounter (struct _timespec64 *, struct _timespec64 *);

/**
 * Implementation for `CLOCK_PROCESS_CPUTIME_ID`.
 *
 * This function always fails on Win9x systems.
 */
static int WinpthreadsTimeImplProcessCpuTime (struct _timespec64 *time, struct _timespec64 *res);

/**
 * Implementation for `CLOCK_THREAD_CPUTIME_ID`.
 *
 * This function always fails on Win9x systems.
 */
static int WinpthreadsTimeImplThreadCpuTime (struct _timespec64 *time, struct _timespec64 *res);

/**
 * Time-related data.
 */
typedef struct TimeImpl {
/**
 * If set, then `GetSystemTimePreciseAsFileTime` is available.
 */
#define HIGH_RESOLUTION_SYSTEM_TIME 0x01
/**
 * If set, then the performance counter is supported.
 */
#define HIGH_RESOLUTION_WINDOWS_TIME 0x02
  int Flags;
  /**
   * Data related to the system clock.
   */
  struct {
    /**
     * Resolution of the system clock, in nanoseconds.
     *
     * System clock resolution is set at boot time, which means we can obtain
     * this value once and then treat it as a constant at runtime.
     */
    long Resolution;
  } SystemClock;
  /**
   * Data related to the performance counter.
   */
  struct {
    /**
     * Frequency of the performance counter as returned by
     * `QueryPerformanceFrequency`.
     *
     * This value is set once at boot time, which means we can obtain
     * this value once and then treat it as a constant at runtime.
     */
    __int64 Frequency;
    /**
     * Resolution of the performance counter , in nanoseconds.
     */
    long Resolution;
  } PerformanceCounter;
  /**
   * Implementation for `CLOCK_REALTIME`.
   *
   * 1. Implementation using `GetSystemTimePreciseAsFileTime`.
   *
   *  This is the preferred implementation; it is used when both
   *  `GetSystemTimePreciseAsFileTime` is available and the performance counter
   *  is supported.
   *
   *  This implementation provides <1us resolution.
   *
   * 2. Implementation using `GetSystemTimeAsFileTime`.
   *
   *  This implementation is used when either `GetSystemTimePreciseAsFileTime`
   *  is not available or the performance counter is not supported.
   *
   *  This implementation provides the same resolution as the system clock.
   */
  FuncWinpthreadsTimeImpl TimeImplRealtime;
  /**
   * Implementation for `CLOCK_MONOTONIC`.
   *
   * 1. Implementation using `QueryPerformanceCounter`.
   *
   *  This is the preferred implementation and is always used when
   *  the performance counter is supported.
   *
   *  This implementation provides <1us resolution.
   *
   * 2. Implementation using `GetTickCount*`.
   *
   *  This implementation is only used when the performance counter
   *  is not supported.
   *
   *  This implementation provides the same resolution as the system clock.
   *
   *  On pre-Vista systems, where `GetTickCount64` is not available,
   *  we use `GetTickCount`, which wraps around to zero after ~49 days.
   *
   * The issues resulting from using `GetTickCount*` shall not affect modern
   * systems since the performance counter is always supported starting
   * with Windows XP.
   */
  FuncWinpthreadsTimeImpl TimeImplMonotonic;
} TimeImpl;

#if WINPTHREADS_WINNT >= WINPTHREADS_WINNT_WIN8
#define WINPTHREADS_DEFAULT_TIME_API_FLAGS (HIGH_RESOLUTION_SYSTEM_TIME)
#else
#define WINPTHREADS_DEFAULT_TIME_API_FLAGS (0)
#endif

static TimeImpl WinpthreadsTimeImpl = {
  .Flags = WINPTHREADS_DEFAULT_TIME_API_FLAGS,
  .SystemClock.Resolution = 0,
  .PerformanceCounter.Frequency = 0,
  .PerformanceCounter.Resolution = 0,
  .TimeImplRealtime = WinpthreadsTimeImplRealtime,
  .TimeImplMonotonic = WinpthreadsTimeImplMonotonicFromTickCount,
};

/**
 * Check if `bit` is set in `WinpthreadsTimeImpl.Flags`
 */
#define WINPTHREADS_TIME_HAVE(bit) (WinpthreadsTimeImpl.Flags & (bit))

void winpthreads_time_init (void) {
#ifdef RUNTIME_CHECKS
  HMODULE kernel32   = GetModuleHandleA ("kernel32.dll");

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
  FuncGetSystemTimeAsFileTime ptrGetSystemTimeAsFileTime = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
  FuncGetSystemTimeAsFileTime ptrGetSystemTimePreciseAsFileTime = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  FuncGetSystemTimeAdjustment ptrGetSystemTimeAdjustment = NULL;
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
  FuncGetTickCount64 ptrGetTickCount64 = NULL;
#endif

  if (kernel32 != NULL) {
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
    ptrGetSystemTimeAsFileTime = (FuncGetSystemTimeAsFileTime) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimeAsFileTime");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
    ptrGetSystemTimePreciseAsFileTime = (FuncGetSystemTimeAsFileTime) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimePreciseAsFileTime");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
    ptrGetSystemTimeAdjustment = (FuncGetSystemTimeAdjustment) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimeAdjustment");
#endif
#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
    ptrGetTickCount64 = (FuncGetTickCount64) (UINT_PTR) GetProcAddress (kernel32, "GetTickCount64");
#endif
  }

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_51
  if (ptrGetSystemTimeAsFileTime != NULL) {
    WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime = ptrGetSystemTimeAsFileTime;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime = WinpthreadsGetSystemTimeAsFileTime;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
  if (ptrGetSystemTimePreciseAsFileTime != NULL) {
    WinpthreadsTimeImpl.Flags                           |= HIGH_RESOLUTION_SYSTEM_TIME;
    WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime = ptrGetSystemTimePreciseAsFileTime;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime = GetSystemTimeAsFileTime;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_NT_3_5
  if (ptrGetSystemTimeAdjustment != NULL) {
    WinpthreadsTimeApi.PtrGetSystemTimeAdjustment = ptrGetSystemTimeAdjustment;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimeAdjustment = WinpthreadsGetSystemTimeAdjustment;
  }
#endif

#if WINPTHREADS_WINNT < WINPTHREADS_WINNT_VISTA
  if (ptrGetTickCount64 != NULL) {
    WinpthreadsTimeApi.PtrGetTickCount64 = ptrGetTickCount64;
  } else {
    WinpthreadsTimeApi.PtrGetTickCount64 = WinpthreadsGetTickCount64;
  }
#endif
#endif /* RUNTIME_CHECKS */

  /**
   * Obtain resolution of the system clock.
   *
   * Function `GetSystemTimeAdjustment` is not available on NT 3.1;
   * this function is available on Win9x, but it always fails with
   * `ERROR_CALL_NOT_IMPLEMENTED`.
   *
   * In order to gracefully handle above cases, we default to 16ms;
   * the resolution of the system clock on Windows is 10~16ms.
   *
   * NOTE: we do not use `GetSystemTimeAdjustmentPrecise` as it appears to
   *  return meaningless values when `isTimeAdjustmentDisabled` is `TRUE`.
   */
  DWORD timeAdjustment;
  DWORD timeIncrement;
  BOOL  isTimeAdjustmentDisabled;

  if (GetSystemTimeAdjustment (&timeAdjustment, &timeIncrement, &isTimeAdjustmentDisabled)) {
    WinpthreadsTimeImpl.SystemClock.Resolution = (long) (timeIncrement * 100);
  } else {
    WinpthreadsTimeImpl.SystemClock.Resolution = 16L * POW10_6;
  }

  /**
   * Obtain frequency and resolution of the performance counter.
   *
   * If we succeed, then the performance counter is supported;
   * set `HIGH_RESOLUTION_WINDOWS_TIME` bit in `WinpthreadsTimeImpl.Flags`.
   *
   * Otherwise, the performance counter is not supported.
   *
   * Starting with Windows XP, functions `QueryPerformanceFrequency` and
   * `QueryPerformanceCounter` always succeed.
   */
  LARGE_INTEGER performanceFrequency;

  if (QueryPerformanceFrequency (&performanceFrequency)) {
    WinpthreadsTimeImpl.PerformanceCounter.Frequency = performanceFrequency.QuadPart;

    /**
     * Check if the performance counter supports sub-nanosecond resolution.
     */
    if (WinpthreadsTimeImpl.PerformanceCounter.Frequency / POW10_9 > 0) {
      WinpthreadsTimeImpl.PerformanceCounter.Resolution = 1L;
    } else {
      WinpthreadsTimeImpl.PerformanceCounter.Resolution =
        (long) (POW10_9 / WinpthreadsTimeImpl.PerformanceCounter.Frequency);
    }

    WinpthreadsTimeImpl.Flags            |= HIGH_RESOLUTION_WINDOWS_TIME;
    WinpthreadsTimeImpl.TimeImplMonotonic = WinpthreadsTimeImplMonotonicFromPerformanceCounter;

    /**
     * Even though `GetSystemTimePreciseAsFileTime` is available since
     * Windows 8, which should imply that the performance counter is supported,
     * we want to be sure that `GetSystemTimePreciseAsFileTime` is used only
     * when the performance counter is also supported.
     */
    if (WINPTHREADS_TIME_HAVE (HIGH_RESOLUTION_SYSTEM_TIME)) {
      WinpthreadsTimeImpl.TimeImplRealtime = WinpthreadsTimeImplRealtimePrecise;
    }
  }
}

/**
 * Store resolution of the system clock in `ts`.
 */
static void WinpthreadsGetSystemClockResolution (struct _timespec64 *ts) {
  ts->tv_sec  = WinpthreadsTimeImpl.SystemClock.Resolution / POW10_9;
  ts->tv_nsec = WinpthreadsTimeImpl.SystemClock.Resolution % POW10_9;
}

/**
 * Store resolution of the performance counter in `ts`.
 */
static void WinpthreadsGetPerformanceCounterResolution (struct _timespec64 *ts) {
  ts->tv_sec  = WinpthreadsTimeImpl.PerformanceCounter.Resolution / POW10_9;
  ts->tv_nsec = WinpthreadsTimeImpl.PerformanceCounter.Resolution % POW10_9;
}

/**
 * Call `getSystemTimeAsFileTime` to obtain current system time as a `FILETIME`
 * value and then store it in `struct _timespec64` structure pointed by `ts`.
 */
static void WinpthreadsGetSystemTime (struct _timespec64 *ts, FuncGetSystemTimeAsFileTime getSystemTimeAsFileTime) {
  FILETIME fileTime;

  getSystemTimeAsFileTime (&fileTime);

  ULARGE_INTEGER value = {
    .HighPart = fileTime.dwHighDateTime,
    .LowPart  = fileTime.dwLowDateTime
  };
  value.QuadPart -= DELTA_EPOCH_IN_100NS;

  ts->tv_sec  = (__time64_t) (value.QuadPart / POW10_7);
  ts->tv_nsec = (long) ((value.QuadPart % POW10_7) * 100);
}

/**
 * Call `getTimes` on `handle`, then convert and store obtained time values
 * in `struct _timespec64` structure pointed by `ts`.
 */
static int WinpthreadsGetCpuTime (struct _timespec64 *ts, FuncGetTimes getTimes, void *handle) {
  FILETIME creationTime;
  FILETIME exitTime;
  FILETIME kernelTime;
  FILETIME userTime;

  /**
   * Functions `GetProcessTimes` and `GetThreadTimes` are available on
   * Win9x systems, but they always fail with `ERROR_CALL_NOT_IMPLEMENTED`.
   *
   * `ENOTSUP` is the most fitting error code, although this error
   * condition is not specified by POSIX.
   */
  if (!getTimes (handle, &creationTime, &exitTime, &kernelTime, &userTime)) {
    return ENOTSUP;
  }

  ULARGE_INTEGER kernelValue = {
    .HighPart = kernelTime.dwHighDateTime,
    .LowPart  = kernelTime.dwLowDateTime
  };
  ULARGE_INTEGER userValue = {
    .HighPart = userTime.dwHighDateTime,
    .LowPart  = userTime.dwLowDateTime
  };
  ULONGLONG value = kernelValue.QuadPart + userValue.QuadPart;

  ts->tv_sec  = (__time64_t) (value / POW10_7);
  ts->tv_nsec = (long) ((value % POW10_7) * 100);

  return 0;
}

static int WinpthreadsTimeImplRealtime (struct _timespec64 *time, struct _timespec64 *res) {
  if (time != NULL) {
    WinpthreadsGetSystemTime (time, GetSystemTimeAsFileTime);
  }

  if (res != NULL) {
    WinpthreadsGetSystemClockResolution (res);
  }

  return 0;
}

static int WinpthreadsTimeImplRealtimePrecise (struct _timespec64 *time, struct _timespec64 *res) {
  if (time != NULL) {
    WinpthreadsGetSystemTime (time, GetSystemTimePreciseAsFileTime);
  }

  if (res != NULL) {
    WinpthreadsGetPerformanceCounterResolution (res);
  }

  return 0;
}

static int WinpthreadsTimeImplMonotonicFromTickCount (struct _timespec64 *time, struct _timespec64 *res) {
  if (time != NULL) {
    /**
     * Functions `GetTickCount*` have the same resolution as the system clock
     * but return time in milliseconds.
     *
     * In order to return more precise time, round up returned time value
     * to the resolution of the system clock.
     */
    unsigned __int64 tickCountAsFileTime   = GetTickCount64 () * POW10_4;
    unsigned __int64 systemClockResolution = WinpthreadsTimeImpl.SystemClock.Resolution / 100;

    if ((tickCountAsFileTime % systemClockResolution) != 0) {
      tickCountAsFileTime -= (tickCountAsFileTime % systemClockResolution);
      tickCountAsFileTime += systemClockResolution;
    }

    time->tv_sec  = (__time64_t) (tickCountAsFileTime / POW10_7);
    time->tv_nsec = (long) ((tickCountAsFileTime % POW10_7) * 100);
  }

  if (res != NULL) {
    WinpthreadsGetSystemClockResolution (res);
  }

  return 0;
}

static int WinpthreadsTimeImplMonotonicFromPerformanceCounter (struct _timespec64 *time, struct _timespec64 *res) {
  LARGE_INTEGER performanceCounter;

  /**
   * If call to `QueryPerformanceCounter` fails,
   * forward to `WinpthreadsTimeImplMonotonicFromTickCount`.
   */
  if (unlikely (!QueryPerformanceCounter (&performanceCounter))) {
    return WinpthreadsTimeImplMonotonicFromTickCount (time, res);
  }

  const __int64 performanceFrequency = WinpthreadsTimeImpl.PerformanceCounter.Frequency;

  if (time != NULL) {
    time->tv_sec  = (__time64_t) (performanceCounter.QuadPart / performanceFrequency);
    time->tv_nsec = (long) (((performanceCounter.QuadPart % performanceFrequency) * POW10_9) / performanceFrequency);
  }

  if (res != NULL) {
    WinpthreadsGetPerformanceCounterResolution (res);
  }

  return 0;
}

static int WinpthreadsTimeImplProcessCpuTime (struct _timespec64 *time, struct _timespec64 *res) {
  if (time != NULL) {
    int error_code = WinpthreadsGetCpuTime (time, GetProcessTimes, GetCurrentProcess ());

    if (error_code != 0) {
      return error_code;
    }
  }

  if (res != NULL) {
    WinpthreadsGetSystemClockResolution (res);
  }

  return 0;
}

static int WinpthreadsTimeImplThreadCpuTime (struct _timespec64 *time, struct _timespec64 *res) {
  if (time != NULL) {
    int error_code = WinpthreadsGetCpuTime (time, GetThreadTimes, GetCurrentThread ());

    if (error_code != 0) {
      return error_code;
    }
  }

  if (res != NULL) {
    WinpthreadsGetSystemClockResolution (res);
  }

  return 0;
}

/*******************************************************************************
 * Private Functions.
 */

unsigned __int64 winpthreads_system_time_ms (void)
{
  FILETIME fileTime;

  GetSystemTimePreciseAsFileTime (&fileTime);

  ULARGE_INTEGER value = {
    .HighPart = fileTime.dwHighDateTime,
    .LowPart  = fileTime.dwLowDateTime
  };

  return (value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_4;
}

unsigned __int64 winpthreads_timespec_ms (const struct _timespec64 *ts)
{
  unsigned __int64 msFromSec  = ts->tv_sec;
  unsigned __int64 msFromNsec = (ts->tv_nsec + POW10_6 - 1) / POW10_6;

  /**
   * Check for overflow.
   */
  if (unlikely (msFromSec > (_UI64_MAX / POW10_3))) {
    return _UI64_MAX;
  }

  msFromSec *= POW10_3;

  /**
   * Check for overflow.
   */
  if (unlikely (msFromNsec > _UI64_MAX - msFromSec)) {
    return _UI64_MAX;
  }

  return msFromSec + msFromNsec;
}

unsigned winpthreads_wait_time_ms (const struct _timespec64 *ts)
{
  unsigned __int64 msCurrent  = winpthreads_system_time_ms ();
  unsigned __int64 msAbsolute = winpthreads_timespec_ms (ts);

  /**
   * Check for underflow.
   */
  if (msAbsolute <= msCurrent) {
    return 0;
  }

  unsigned __int64 diff = msAbsolute - msCurrent;

  if (diff >= INFINITE) {
    return INFINITE;
  }

  return (unsigned) diff;
}

unsigned __int64 winpthreads_windows_time_ms (void)
{
  struct _timespec64 ts;

  WinpthreadsTimeImpl.TimeImplMonotonic (&ts, NULL);

  unsigned __int64 msFromSec  = ts.tv_sec;
  unsigned __int64 msFromNsec = ts.tv_nsec / POW10_6;

  /**
   * Check for overflow.
   */
  if (unlikely (msFromSec > (_UI64_MAX / POW10_3))) {
    return _UI64_MAX;
  }

  msFromSec *= POW10_3;

  /**
   * Check for overflow.
   */
  if (unlikely (msFromNsec > (_UI64_MAX - msFromSec))) {
    return _UI64_MAX;
  }

  return msFromSec + msFromNsec;
}

int winpthreads_timespec_diff (const struct _timespec64 *ts1, const struct _timespec64 *ts2) {
  if (ts1->tv_sec > ts2->tv_sec) {
    return 1;
  }

  if (ts1->tv_sec < ts2->tv_sec) {
    return -1;
  }

  return ts1->tv_nsec - ts2->tv_nsec;
}

void winpthreads_timespec_add (const struct _timespec64 *ts1, const struct _timespec64 *ts2, struct _timespec64 *out) {
  /**
   * Check for overflow.
   */
  if (unlikely (ts1->tv_sec > _I64_MAX - ts2->tv_sec)) {
    out->tv_sec  = _I64_MAX;
    out->tv_nsec = POW10_9 - 1;
    return;
  }

  out->tv_sec  = ts1->tv_sec + ts2->tv_sec;
  out->tv_nsec = ts1->tv_nsec + ts2->tv_nsec;

  if (out->tv_nsec >= POW10_9) {
    /**
     * Prevent overflow in `out->tv_sec`.
     */
    if (out->tv_sec == _I64_MAX) {
      out->tv_nsec = POW10_9 - 1;
    } else {
      out->tv_sec  += 1;
      out->tv_nsec -= POW10_9;
    }
  }
}

void winpthreads_timespec_sub (const struct _timespec64 *ts1, const struct _timespec64 *ts2, struct _timespec64 *out) {
  /**
   * Check for underflow.
   */
  if (ts2->tv_sec > ts1->tv_sec) {
    out->tv_sec  = 0;
    out->tv_nsec = 0;
    return;
  }

  out->tv_sec  = ts1->tv_sec - ts2->tv_sec;
  out->tv_nsec = ts1->tv_nsec - ts2->tv_nsec;

  if (out->tv_nsec < 0) {
    /**
     * Prevent underflow in `out->tv_sec`.
     */
    if (out->tv_sec == 0) {
      out->tv_nsec = 0;
    } else {
      out->tv_sec  -= 1;
      out->tv_nsec += POW10_9;
    }
  }
}

/*******************************************************************************
 * Public Functions.
 */

/**
 * Common implementation for `nanosleep` and `clock_nanosleep`.
 *
 * Returns zero on success and an error-code on failure.
 */
static int WinpthreadsSleep (FuncWinpthreadsTimeImpl timeImpl, int flags, const struct _timespec64 *request, struct _timespec64 *remain) {
  struct _timespec64 startTime;
  struct _timespec64 endTime;
  struct _timespec64 sleepUntil;
  struct _timespec64 sleepFor;

  timeImpl (&startTime, NULL);

  if (flags & TIMER_ABSTIME) {
    sleepUntil = *request;
    winpthreads_timespec_sub (&sleepUntil, &startTime, &sleepFor);
  } else {
    sleepFor = *request;
    winpthreads_timespec_add (&startTime, &sleepFor, &sleepUntil);
  }

  /**
   * Timeout already expired.
   */
  if (winpthreads_timespec_diff (&startTime, &sleepUntil) >= 0) {
    return 0;
  }

  /**
   * Total sleep time in milliseconds.
   */
  unsigned __int64 totalSleepTime = winpthreads_timespec_ms (&sleepFor);
  int error_code;

  do {
    /**
     * We can sleep for at most `INFINITE - 1` milliseconds at a time.
     */
    unsigned sleepTime;

    if (unlikely (totalSleepTime >= MAX_SLEEP_IN_MS)) {
      sleepTime = MAX_SLEEP_IN_MS;
    } else {
      sleepTime = (unsigned) totalSleepTime;
    }

    totalSleepTime -= sleepTime;
    error_code      = _pthread_delay_np_ms (sleepTime);
  } while (totalSleepTime > 0 && likely (error_code == 0));

  /**
   * Currently, function `_pthread_delay_np_ms` always returns zero.
   */
  if (unlikely (error_code != 0)) {
    error_code = EINTR;

    /**
     * FIXME:
     *
     * For `CLOCK_REALTIME`, it is possible that the system time has been
     * changed while we were sleeping, which means `ramain` will be calculated
     * relative to the new system time.
     *
     * In order to fix this we would need to re-write waiting routines,
     * and allow them return total time spent sleeping.
     */
    if ((flags & TIMER_ABSTIME) == 0 && remain != NULL) {
      timeImpl (&endTime, NULL);
      winpthreads_timespec_sub (&sleepUntil, &endTime, remain);
    }
  }

  return error_code;
}

int nanosleep64 (const struct _timespec64 *request, struct _timespec64 *remain)
{
  /**
   * The nanosleep() function shall fail if:
   *
   * [EINVAL]
   *   The request argument specified a nanosecond value less than zero or
   *   greater than or equal to 1000 million.
   */
  if (request->tv_sec < 0 || request->tv_nsec < 0 || request->tv_nsec >= POW10_9) {
    _set_errno (EINVAL);
    return -1;
  }

  int error_code = WinpthreadsSleep (WinpthreadsTimeImpl.TimeImplRealtime, 0, request, remain);

  if (error_code != 0) {
    _set_errno (error_code);
    return -1;
  }

  return error_code;
}

int nanosleep32 (const struct _timespec32 *request, struct _timespec32 *remain)
{
  struct _timespec64 request64 = {
    .tv_sec  = request->tv_sec,
    .tv_nsec = request->tv_nsec
  };
  struct _timespec64 remain64 = {0};

  int error_code = nanosleep64 (&request64, &remain64);

  if (error_code == -1) {
    if (unlikely (errno == EINTR) && remain != NULL) {
      assert (remain64.tv_sec >= 0 && remain64.tv_sec <= INT_MAX);
      remain->tv_sec = (__time32_t) remain64.tv_sec;
      assert (remain64.tv_nsec >= 0 && remain64.tv_nsec < POW10_9);
      remain->tv_nsec = remain64.tv_nsec;
    }
  }

  return error_code;
}

int clock_getres64 (clockid_t clock_id, struct _timespec64 *res)
{
  int error_code = 0;

  switch (clock_id) {
    case CLOCK_REALTIME: {
      WinpthreadsTimeImpl.TimeImplRealtime (NULL, res);
      break;
    }

    case CLOCK_REALTIME_COARSE: {
      WinpthreadsTimeImplRealtime (NULL, res);
      break;
    }

    case CLOCK_MONOTONIC: {
      WinpthreadsTimeImpl.TimeImplMonotonic (NULL, res);
      break;
    }

    case CLOCK_PROCESS_CPUTIME_ID: {
      error_code = WinpthreadsTimeImplProcessCpuTime (NULL, res);
      break;
    }

    case CLOCK_THREAD_CPUTIME_ID: {
      error_code = WinpthreadsTimeImplThreadCpuTime (NULL, res);
      break;
    }

    default: {
      error_code = EINVAL;
      break;
    }
  }

  if (error_code != 0) {
    _set_errno (error_code);
    return -1;
  }

  return 0;
}

int clock_getres32 (clockid_t clock_id, struct _timespec32 *res)
{
  struct _timespec64 res64;

  int error_code = clock_getres64 (clock_id, &res64);

  if (error_code == 0) {
    res->tv_sec  = (__time32_t) res64.tv_sec;
    res->tv_nsec = res64.tv_nsec;
  }

  return error_code;
}

int clock_gettime64 (clockid_t clock_id, struct _timespec64 *tp)
{
  int error_code = 0;

  switch (clock_id) {
    case CLOCK_REALTIME: {
      WinpthreadsTimeImpl.TimeImplRealtime (tp, NULL);
      break;
    }

    case CLOCK_REALTIME_COARSE: {
      WinpthreadsTimeImplRealtime (tp, NULL);
      break;
    }

    case CLOCK_MONOTONIC: {
      WinpthreadsTimeImpl.TimeImplMonotonic (tp, NULL);
      break;
    }

    case CLOCK_PROCESS_CPUTIME_ID: {
      error_code = WinpthreadsTimeImplProcessCpuTime (tp, NULL);
      break;
    }

    case CLOCK_THREAD_CPUTIME_ID: {
      error_code = WinpthreadsTimeImplThreadCpuTime (tp, NULL);
      break;
    }

    default: {
      error_code = EINVAL;
      break;
    }
  }

  if (error_code != 0) {
    _set_errno (error_code);
    return -1;
  }

  return 0;
}

int clock_gettime32 (clockid_t clock_id, struct _timespec32 *tp)
{
  struct _timespec64 tp64;

  int error_code = clock_gettime64 (clock_id, &tp64);

  if (error_code == 0) {
    if (tp64.tv_sec > INT_MAX) {
      _set_errno (EOVERFLOW);
      return -1;
    }

    tp->tv_sec  = (__time32_t) tp64.tv_sec;
    tp->tv_nsec = tp64.tv_nsec;
  }

  return error_code;
}

int clock_settime64 (clockid_t clock_id, const struct _timespec64 *tp)
{
  /**
   * The clock_settime() function shall fail if:
   *
   * [EINVAL]
   *   The tp argument specified a nanosecond value less than zero or
   *   greater than or equal to 1000 million.
   */
  if (tp->tv_sec < 0 || tp->tv_nsec < 0 || tp->tv_nsec >= POW10_9) {
    _set_errno (EINVAL);
    return -1;
  }

  switch (clock_id) {
    case CLOCK_REALTIME:
    case CLOCK_REALTIME_COARSE:
      break;
    /**
     * The clock_settime() function shall fail if:
     *
     * [EINVAL]
     *   The value of the clock_id argument is CLOCK_MONOTONIC.
     */
    case CLOCK_MONOTONIC:
    /**
     * Setting CPU clocks is not supported.
     */
    case CLOCK_PROCESS_CPUTIME_ID:
    case CLOCK_THREAD_CPUTIME_ID:
    /**
     * The clock_settime() function shall fail if:
     *
     * [EINVAL]
     *   The clock_id argument does not specify a known clock.
     */
    default:
      _set_errno(EINVAL);
      return -1;
  }

  ULARGE_INTEGER value = {
    .QuadPart = DELTA_EPOCH_IN_100NS + (tp->tv_sec * POW10_7) + (tp->tv_nsec / 100)
  };
  FILETIME fileTime = {
    .dwHighDateTime = value.HighPart,
    .dwLowDateTime  = value.LowPart
  };
  SYSTEMTIME systemTime;

  if (!FileTimeToSystemTime (&fileTime, &systemTime)) {
    _set_errno (EINVAL);
    return -1;
  }

  if (!SetSystemTime (&systemTime)) {
    _set_errno (EPERM);
    return -1;
  }

  return 0;
}

int clock_settime32 (clockid_t clock_id, const struct _timespec32 *tp)
{
  struct _timespec64 tp64 = {.tv_sec = tp->tv_sec, .tv_nsec = tp->tv_nsec};
  return clock_settime64 (clock_id, &tp64);
}

int clock_nanosleep64 (clockid_t clock_id, int flags, const struct _timespec64 *request, struct _timespec64 *remain)
{
  /**
   * The clock_nanosleep() function shall fail if:
   *
   * [EINVAL]
   *   The request argument specified a nanosecond value less than zero or
   *   greater than or equal to 1000 million.
   */
  if (request->tv_sec < 0 || request->tv_nsec < 0 || request->tv_nsec >= POW10_9) {
    _set_errno (EINVAL);
    return -1;
  }

  FuncWinpthreadsTimeImpl timeImpl;

  switch (clock_id) {
    /**
     * Currently, only `CLOCK_REALTIME` is supported.
     */
    case CLOCK_REALTIME:
      timeImpl = WinpthreadsTimeImpl.TimeImplRealtime;
      break;
    case CLOCK_MONOTONIC:
    /**
     * The clock_nanosleep() function shall fail if:
     *
     * [EINVAL]
     *   the clock_id argument does not specify a known clock,
     *   or specifies the CPU-time clock of the calling thread.
     */
    case CLOCK_PROCESS_CPUTIME_ID:
    case CLOCK_THREAD_CPUTIME_ID:
    default:
      _set_errno(EINVAL);
      return -1;
  }

  int error_code = WinpthreadsSleep (timeImpl, flags, request, remain);

  if (error_code != 0) {
    _set_errno (error_code);
    return -1;
  }

  return error_code;
}

int clock_nanosleep32 (clockid_t clock_id, int flags, const struct _timespec32 *request, struct _timespec32 *remain)
{
  struct _timespec64 request64 = {
    .tv_sec  = request->tv_sec,
    .tv_nsec = request->tv_nsec
  };
  struct _timespec64 remain64;

  int error_code = clock_nanosleep64 (clock_id, flags, &request64, &remain64);

  if (error_code == -1) {
    if (unlikely (errno == EINTR) && remain != NULL) {
      assert (remain64.tv_sec >= 0 && remain64.tv_sec <= INT_MAX);
      remain->tv_sec = (__time32_t) remain64.tv_sec;
      assert (remain64.tv_nsec >= 0 && remain64.tv_nsec < POW10_9);
      remain->tv_nsec = remain64.tv_nsec;
    }
  }

  return error_code;
}
