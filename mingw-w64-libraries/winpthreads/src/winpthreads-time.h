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

#include "misc.h"

/**
 * Get current system time, in milliseconds.
 */
unsigned __int64 winpthreads_system_time_ms (void);

/**
 * Get absolute time from `ts`, in millseconds.
 */
unsigned __int64 winpthreads_timespec_ms (const struct _timespec64 *ts);

/**
 * Get difference between current system time and absolute time `ts`,
 * in milliseconds.
 *
 * The value is returned as an `unsigned`; it is expected to be used with
 * functions such as `WaitFor*` and `Sleep`, which take `DWORD` values.
 */
unsigned winpthreads_wait_time_ms (const struct _timespec64 *ts);

/**
 * Get current time using some monotonic clock, in milliseconds.
 */
unsigned __int64 winpthreads_windows_time_ms (void);

/**
 * Initialize time functions.
 */
void winpthreads_time_init (void);

/**
 * Obtain the current time and resolution of the `clock`.
 *
 * Either `time` or `res` argument can be `NULL`.
 *
 * Returns zero on success and an error code on failure.
 *
 * This function never fails when `clock` argument is `CLOCK_REALTIME`,
 * `CLOCK_MONOTONIC` or `CLOCK_REALTIME_COARSE`.
 */
int winpthreads_time (clockid_t clock, struct _timespec64 *time, struct _timespec64 *res);

/**
 * Compare `ts1` and `ts2`.
 *
 * Return value follows `strcmp` convention.
 */
int winpthreads_timespec_diff (const struct _timespec64 *ts1, const struct _timespec64 *ts2);

/**
 * Add `ts2` to `ts1` and store result in `out`.
 */
void winpthreads_timespec_add (const struct _timespec64 *ts1, const struct _timespec64 *ts2, struct _timespec64 *out);

/**
 * Substract `ts2` from `ts1` and store result in `out`.
 */
void winpthreads_timespec_sub (const struct _timespec64 *ts1, const struct _timespec64 *ts2, struct _timespec64 *out);

/**
 * Round `time` to `res` and store result in `out`. The `res` argument is
 * expected to be resolution of the clock used to measure `time`.
 *
 * The rounding is performed as follow:
 *
 * If `time` has value of zero, store value of zero in `out`.
 *
 * Otherwise, if `time` is less than or equal to `res`,
 * store value of `res` in `out`.
 *
 * Otherwise, if value of `time`, converted to nanoseconds, does not fit into
 * unsigned 64-bit integer, store value of `time` in `out`.
 *
 * Otherwise, store value of `time` rounded up to `res` in `out`.
 */
void winpthreads_timespec_round (const struct _timespec64 *time, const struct _timespec64 *res, struct _timespec64 *out);

/**
 * Convert duration `time` to wait time in milliseconds. The `res` argument is
 * expected to be resolution of the clock used to measure `time`.
 *
 * Note that returned value is not `time` rounded to `res`, instead:
 *
 * If value of `time` is zero, this function returns 0ms, ignoring `res`.
 *
 * Otherwise, if value of `time` is less than or equal to `res`,
 * this function returns 1ms.
 *
 * Otherwise, if value of `time`, converted to milliseconds, is greater than or
 * equal to `INFINITE`, this function returns `INFINITE - 1`.
 *
 * This allows to properly handle wait requests with timeout of `INFINITE` or
 * more milliseconds; wait for at most `INFINITE - 1` milliseconds at a time
 * and calculate new timeout once awakened.
 *
 * Otherwise, this function returns `time` reduced to the next multiple
 * of `res`; if result is less than 1ms, the returned value is 1ms.
 */
unsigned winpthreads_wait_time_from_timespec (const struct _timespec64 *time, const struct _timespec64 *res);

#endif /* WINPTHREADS_TIME_H */
