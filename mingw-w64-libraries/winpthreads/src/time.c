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
#include "misc.h"
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

/**
 * Functions which are looked up at runtime.
 */
typedef struct TimeApi {
  /**
   * Function `GetSystemTimeAsFileTime` is available since Windows NT 3.51.
   */
  FuncGetSystemTimeAsFileTime PtrGetSystemTimeAsFileTime;
  /**
   * Function `GetSystemTimePreciseAsFileTime` is available since Windows 8.
   */
  FuncGetSystemTimeAsFileTime PtrGetSystemTimePreciseAsFileTime;
  /**
   * Function `GetSystemTimeAdjustment` is available since Windows NT 3.5.
   */
  FuncGetSystemTimeAdjustment PtrGetSystemTimeAdjustment;
  /**
   * Function `GetTickCount64` is available since Windows Vista.
   */
  FuncGetTickCount64 PtrGetTickCount64;
} TimeApi;

static TimeApi WinpthreadsTimeApi;

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

/**
 * Replacement for `GetTickCount64`;
 * a simple wrapper around `GetTickCount`.
 */
static ULONGLONG WINAPI WinpthreadsGetTickCount64 (VOID) {
  return GetTickCount ();
}

/**
 * Time-related data.
 */
typedef struct TimeImpl {
/**
 * If set, then `GetSystemTimePreciseAsFileTime` is available.
 */
#define HIGH_RESOLUTION_SYSTEM_TIME 0x01
  int Flags;
} TimeImpl;

static TimeImpl WinpthreadsTimeImpl = {
  .Flags = 0,
};

/**
 * Check if `bit` is set in `WinpthreadsTimeImpl.Flags`
 */
#define WINPTHREADS_TIME_HAVE(bit) (WinpthreadsTimeImpl.Flags & (bit))

void winpthreads_time_init (void) {
  HMODULE kernel32   = GetModuleHandleA ("kernel32.dll");

  FuncGetSystemTimeAsFileTime        ptrGetSystemTimeAsFileTime        = NULL;
  FuncGetSystemTimeAsFileTime        ptrGetSystemTimePreciseAsFileTime = NULL;
  FuncGetSystemTimeAdjustment        ptrGetSystemTimeAdjustment        = NULL;
  FuncGetTickCount64                 ptrGetTickCount64                 = NULL;

  if (kernel32 != NULL) {
    ptrGetSystemTimeAsFileTime        = (FuncGetSystemTimeAsFileTime) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimeAsFileTime");
    ptrGetSystemTimePreciseAsFileTime = (FuncGetSystemTimeAsFileTime) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimePreciseAsFileTime");
    ptrGetSystemTimeAdjustment        = (FuncGetSystemTimeAdjustment) (UINT_PTR) GetProcAddress (kernel32, "GetSystemTimeAdjustment");
    ptrGetTickCount64                 = (FuncGetTickCount64) (UINT_PTR) GetProcAddress (kernel32, "GetTickCount64");
  }

  if (ptrGetSystemTimeAsFileTime != NULL) {
    WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime = ptrGetSystemTimeAsFileTime;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime = WinpthreadsGetSystemTimeAsFileTime;
  }

  if (ptrGetSystemTimePreciseAsFileTime != NULL) {
    WinpthreadsTimeImpl.Flags                           |= HIGH_RESOLUTION_SYSTEM_TIME;
    WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime = ptrGetSystemTimePreciseAsFileTime;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime = WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime;
  }

  if (ptrGetSystemTimeAdjustment != NULL) {
    WinpthreadsTimeApi.PtrGetSystemTimeAdjustment = ptrGetSystemTimeAdjustment;
  } else {
    WinpthreadsTimeApi.PtrGetSystemTimeAdjustment = WinpthreadsGetSystemTimeAdjustment;
  }

  if (ptrGetTickCount64 != NULL) {
    WinpthreadsTimeApi.PtrGetTickCount64 = ptrGetTickCount64;
  } else {
    WinpthreadsTimeApi.PtrGetTickCount64 = WinpthreadsGetTickCount64;
  }
}

/*******************************************************************************
 * Private Functions.
 */

unsigned __int64 winpthreads_system_time_ms (void)
{
  FILETIME fileTime;

  WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime (&fileTime);

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

unsigned __int64 winpthreads_windows_time_ms (__int64 *frequency)
{
  LARGE_INTEGER performanceFrequency = {.QuadPart = 0};
  LARGE_INTEGER performanceCounter   = {.QuadPart = 0};

  if (frequency == NULL || *frequency == 0) {
    if (!QueryPerformanceFrequency (&performanceFrequency)) {
      performanceFrequency.QuadPart = -1;
    }

    if (frequency != NULL) {
      *frequency = performanceFrequency.QuadPart;
    }
  } else {
    performanceFrequency.QuadPart = *frequency;
  }

  if (performanceFrequency.QuadPart > 0 && QueryPerformanceCounter (&performanceCounter)) {
    return performanceCounter.QuadPart / (performanceFrequency.QuadPart / POW10_3);
  }

  return WinpthreadsTimeApi.PtrGetTickCount64 ();
}

/*******************************************************************************
 * Public Functions.
 */

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

  /**
   * Total sleep time in milliseconds.
   */
  unsigned __int64 totalSleepTime = winpthreads_timespec_ms (request);

  if (totalSleepTime == 0) {
    return 0;
  }

  FILETIME startTime;
  FILETIME endTime;

  if (remain != NULL) {
    WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime (&startTime);
  }

  unsigned __int64 remainingSleepTime = totalSleepTime;
  int error_code;

  do {
    /**
     * We can sleep for at most `INFINITE - 1` milliseconds at a time.
     */
    unsigned sleepTime;

    if (remainingSleepTime >= MAX_SLEEP_IN_MS) {
      sleepTime = MAX_SLEEP_IN_MS;
    } else {
      sleepTime = (unsigned) remainingSleepTime;
    }

    remainingSleepTime -= sleepTime;
    error_code          = _pthread_delay_np_ms (sleepTime);
  } while (remainingSleepTime > 0 && likely (error_code == 0));

  /**
   * Currently, function `_pthread_delay_np_ms` always returns zero.
   */
  if (unlikely (error_code != 0)) {
    if (remain != NULL) {
      WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime (&endTime);

      ULARGE_INTEGER start = {
        .HighPart = startTime.dwHighDateTime,
        .LowPart  = startTime.dwLowDateTime
      };
      ULARGE_INTEGER end = {
        .HighPart = endTime.dwHighDateTime,
        .LowPart  = endTime.dwLowDateTime
      };

      remainingSleepTime = 0;

      /**
       * It is possible that system time has been changed while we were sleeping,
       * so we have to check for possible underflow.
       */
      if (likely (start.QuadPart <= end.QuadPart)) {
        unsigned __int64 elapsedSleepTime = (end.QuadPart - start.QuadPart) / POW10_4;

        if (likely (elapsedSleepTime < totalSleepTime)) {
          remainingSleepTime = totalSleepTime - elapsedSleepTime;
        }
      }

      remain->tv_sec  = (__time64_t) (remainingSleepTime / POW10_3);
      remain->tv_nsec = (long) ((remainingSleepTime % POW10_3) * POW10_6);
    }

    _set_errno (EINTR);
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
  /**
   * If `GetSystemTimePreciseAsFileTime` is not available,
   * use `GetSystemTimeAdjustment` to obtain system clock resolution.
   */
  if (clock_id == CLOCK_REALTIME && !WINPTHREADS_TIME_HAVE (HIGH_RESOLUTION_SYSTEM_TIME)) {
    clock_id = CLOCK_REALTIME_COARSE;
  }

  switch (clock_id) {
    case CLOCK_REALTIME:
    case CLOCK_MONOTONIC: {
      LARGE_INTEGER pf;

      if (!QueryPerformanceFrequency (&pf)) {
        _set_errno (EINVAL);
        return -1;
      }

      res->tv_sec  = 0;
      res->tv_nsec = (long) ((POW10_9 + (pf.QuadPart >> 1)) / pf.QuadPart);

      if (res->tv_nsec < 1) {
        res->tv_nsec = 1;
      }

      return 0;
    }

    case CLOCK_REALTIME_COARSE:
    case CLOCK_PROCESS_CPUTIME_ID:
    case CLOCK_THREAD_CPUTIME_ID: {
      DWORD timeAdjustment;
      DWORD timeIncrement;
      BOOL  isTimeAdjustmentDisabled;

      /**
       * If call to `GetSystemTimeAdjustment` fails, use 16ms as
       * the default fallback value.
       */
      if (!WinpthreadsTimeApi.PtrGetSystemTimeAdjustment (&timeAdjustment, &timeIncrement, &isTimeAdjustmentDisabled)) {
        timeIncrement = 160000;
      }

      res->tv_sec  = 0;
      res->tv_nsec = (long) (timeIncrement * 100);

      return 0;
    }
    default:
      break;
  }

  _set_errno (EINVAL);
  return -1;
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
  switch (clock_id) {
    case CLOCK_REALTIME: {
      FILETIME fileTime;

      WinpthreadsTimeApi.PtrGetSystemTimePreciseAsFileTime (&fileTime);

      ULARGE_INTEGER value = {
        .HighPart = fileTime.dwHighDateTime,
        .LowPart  = fileTime.dwLowDateTime
      };

      tp->tv_sec  = (__time64_t) ((value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_7);
      tp->tv_nsec = (long) ((value.QuadPart % POW10_7) * 100);

      return 0;
    }

    case CLOCK_REALTIME_COARSE: {
      FILETIME fileTime;

      WinpthreadsTimeApi.PtrGetSystemTimeAsFileTime (&fileTime);

      ULARGE_INTEGER value = {
        .HighPart = fileTime.dwHighDateTime,
        .LowPart  = fileTime.dwLowDateTime
      };

      tp->tv_sec  = (__time64_t) ((value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_7);
      tp->tv_nsec = (long) ((value.QuadPart % POW10_7) * 100);

      return 0;
    }

    case CLOCK_MONOTONIC: {
      LARGE_INTEGER pf;
      LARGE_INTEGER pc;

      if (!QueryPerformanceFrequency (&pf)) {
        _set_errno (EINVAL);
        return -1;
      }

      if (!QueryPerformanceCounter (&pc)) {
        _set_errno (EINVAL);
        return -1;
      }

      tp->tv_sec  = (__time64_t) (pc.QuadPart / pf.QuadPart);
      tp->tv_nsec = (long) (((pc.QuadPart % pf.QuadPart) * POW10_9 + (pf.QuadPart >> 1)) / pf.QuadPart);

      if (tp->tv_nsec >= POW10_9) {
        tp->tv_sec++;
        tp->tv_nsec -= POW10_9;
      }

      return 0;
    }

    case CLOCK_PROCESS_CPUTIME_ID: {
      FILETIME creationTime;
      FILETIME exitTime;
      FILETIME kernelTime;
      FILETIME userTime;

      /**
       * Function `GetProcessTimes` is available on Win9x systems,
       * but it always fails.
       *
       * `ENOTSUP` is the most fitting error code, although this error
       * condition is not specified by POSIX.
       */
      if (!GetProcessTimes(GetCurrentProcess(), &creationTime, &exitTime, &kernelTime, &userTime)) {
        _set_errno(ENOTSUP);
        return -1;
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

      tp->tv_sec  = (__time64_t)  (value / POW10_7);
      tp->tv_nsec = (long) ((value % POW10_7) * 100);

      return 0;
    }

    case CLOCK_THREAD_CPUTIME_ID: {
      FILETIME creationTime;
      FILETIME exitTime;
      FILETIME kernelTime;
      FILETIME userTime;

      /**
       * Function `GetThreadTimes` is available on Win9x systems,
       * but it always fails.
       *
       * `ENOTSUP` is the most fitting error code, although this error
       * condition is not specified by POSIX.
       */
      if (!GetThreadTimes(GetCurrentThread(), &creationTime, &exitTime, &kernelTime, &userTime)) {
        _set_errno(ENOTSUP);
        return -1;
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

      tp->tv_sec  = (__time64_t) (value / POW10_7);
      tp->tv_nsec = (long) ((value % POW10_7) * 100);

      return 0;
    }

    default:
      break;
  }

  _set_errno (EINVAL);
  return -1;
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

  switch (clock_id) {
    /**
     * Currently, only `CLOCK_REALTIME` is supported.
     */
    case CLOCK_REALTIME:
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

  /**
   * Calling `clock_nanosleep` with `CLOCK_REALTIME` and zero `flags`
   * is the same as calling `nanosleep`.
   */
  if ((flags & TIMER_ABSTIME) == 0) {
    return nanosleep64(request, remain);
  }

  /**
   * Calculate sleep time from the current time and absolute time `request`.
   */
  struct _timespec64 sleepTime;

  clock_gettime64 (clock_id, &sleepTime);

  /**
   * Timeout already expired.
   */
  if (sleepTime.tv_sec > request->tv_sec) {
    return 0;
  }

  sleepTime.tv_sec  = request->tv_sec - sleepTime.tv_sec;
  sleepTime.tv_nsec = request->tv_nsec - sleepTime.tv_nsec;

  if (sleepTime.tv_nsec < 0) {
    /**
     * Timeout already expired.
     */
    if (sleepTime.tv_sec == 0) {
      return 0;
    }

    sleepTime.tv_nsec += POW10_9;
    sleepTime.tv_sec--;
  }

  return nanosleep64 (&sleepTime, remain);
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
