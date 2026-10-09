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

#ifndef WINPTHREADS_TIME_H
#define WINPTHREADS_TIME_H

#include "pthread_time.h"

/**
 * Address of `GetSystemTimePreciseAsFileTime`, if available;
 * otherwise, address of `GetSystemTimeAsFileTime`.
 */
extern VOID (WINAPI *_pthread_get_system_time_best_as_file_time) (LPFILETIME);

/**
 * Address of `GetTickCount64`, if available; otherwise, set to `NULL`.
 */
extern ULONGLONG (WINAPI *_pthread_get_tick_count_64) (VOID);

/**
 * Get current system time, in milliseconds.
 */
unsigned __int64 _pthread_time_in_ms (void);

/**
 * Get absolute time from `ts`, in millseconds.
 */
unsigned long long _pthread_time_in_ms_from_timespec (const struct _timespec64 *ts);

/**
 * Get difference between current system time and absolute time `ts`,
 * in milliseconds.
 */
unsigned long long _pthread_rel_time_in_ms (const struct _timespec64 *ts);

/**
 * Get current time using some monotonic clock, in milliseconds.
 *
 * On the first call, variable pointed to by `frequency` must be initialized
 * to zero, and then passed again in subsequent calls, if any.
 */
unsigned long long _pthread_get_tick_count (long long *frequency);

/**
 * Return `ms` as an `unsigned long` value.
 */
static WINPTHREADS_INLINE unsigned long dwMilliSecs (unsigned long long ms)
{
  if (ms >= 0xffffffffULL) {
    return 0xfffffffful;
  }

  return (unsigned long) ms;
}

#endif /* WINPTHREADS_TIME_H */
