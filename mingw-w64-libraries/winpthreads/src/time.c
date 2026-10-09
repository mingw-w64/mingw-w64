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

#include <stdint.h>
#include <time.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* public header files */
#include "pthread.h"
/* internal header files */
#include "misc.h"
#include "winpthreads-time.h"

/**
 * File Summary:
 *
 * This file contains all time-related definitions used by the library.
 */

#define POW10_3 1000
#define POW10_4 10000
#define POW10_6 1000000

/**
 * Number of 100ns intervals between the beginning of the Windows epoch
 * (Jan. 1, 1601) and the Unix epoch (Jan. 1, 1970)
 */
#define DELTA_EPOCH_IN_100NS INT64_C(116444736000000000)

VOID (WINAPI *_pthread_get_system_time_best_as_file_time) (LPFILETIME) = NULL;
ULONGLONG (WINAPI *_pthread_get_tick_count_64) (VOID) = NULL;

unsigned __int64 _pthread_time_in_ms (void)
{
  FILETIME fileTime;

  _pthread_get_system_time_best_as_file_time (&fileTime);

  ULARGE_INTEGER value = {
    .HighPart = fileTime.dwHighDateTime,
    .LowPart  = fileTime.dwLowDateTime
  };

  return (value.QuadPart - DELTA_EPOCH_IN_100NS) / POW10_4;
}

unsigned __int64 _pthread_time_in_ms_from_timespec (const struct _timespec64 *ts)
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

unsigned long long _pthread_rel_time_in_ms (const struct _timespec64 *ts)
{
  unsigned long long t1 = _pthread_time_in_ms_from_timespec (ts);
  unsigned long long t2 = _pthread_time_in_ms ();

  /* Prevent underflow */
  if (t1 < t2) {
    return 0;
  }

  return t1 - t2;
}

unsigned long long _pthread_get_tick_count (long long *frequency)
{
  if (_pthread_get_tick_count_64 != NULL) {
    return _pthread_get_tick_count_64 ();
  }

  LARGE_INTEGER freq, timestamp;

  if (*frequency == 0) {
    if (QueryPerformanceFrequency (&freq)) {
      *frequency = freq.QuadPart;
    } else {
      *frequency = -1;
    }
  }

  if (*frequency > 0 && QueryPerformanceCounter (&timestamp)) {
    return timestamp.QuadPart / (*frequency / 1000);
  }

  /* Fallback */
  return GetTickCount ();
}
