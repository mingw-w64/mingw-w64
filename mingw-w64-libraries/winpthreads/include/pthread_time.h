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

#ifndef WIN_PTHREADS_TIME_H
#define WIN_PTHREADS_TIME_H

#include <sys/timeb.h>
#include "pthread_compat.h"

/* `CLOCK_MONOTONIC` is supported.  */
#ifndef _POSIX_MONOTONIC_CLOCK
#define _POSIX_MONOTONIC_CLOCK 200809L
#endif

/* `CLOCK_PROCESS_CPUTIME_ID` is supported.  */
#ifndef _POSIX_CPUTIME
/**
 * Only supported on Windows NT; not supported on Win9x.
 */
#define _POSIX_CPUTIME 0
#endif

/* `CLOCK_THREAD_CPUTIME_ID` is supported.  */
#ifndef _POSIX_THREAD_CPUTIME
/**
 * Only supported on Windows NT; not supported on Win9x.
 */
#define _POSIX_THREAD_CPUTIME 0
#endif

/* POSIX timers are not supported. */
#ifdef _POSIX_TIMERS
#undef _POSIX_TIMERS
#endif

#define CLOCK_REALTIME           0
#define CLOCK_MONOTONIC          1
#define CLOCK_PROCESS_CPUTIME_ID 2
#define CLOCK_THREAD_CPUTIME_ID  3
/**
 * Not POSIX.
 *
 * Same as `CLOCK_REALTIME`, except it always uses the same resolution as
 * the system clock (10~16ms).
 */
#define CLOCK_REALTIME_COARSE    4

#define TIMER_ABSTIME 1

#ifdef __cplusplus
extern "C" {
#endif

WINPTHREAD_API int __cdecl nanosleep32(const struct _timespec32 *, struct _timespec32 *);
WINPTHREAD_API int __cdecl nanosleep64(const struct _timespec64 *, struct _timespec64 *);
WINPTHREAD_TIME_DECL int __cdecl nanosleep(const struct timespec *_T1, struct timespec *_T2)
{
#if WINPTHREADS_TIME_BITS == 32
  return nanosleep32((const struct _timespec32 *)_T1, (struct _timespec32 *)_T2);
#else
  return nanosleep64((const struct _timespec64 *)_T1, (struct _timespec64 *)_T2);
#endif
}

WINPTHREAD_API int __cdecl clock_getres32(clockid_t, struct _timespec32 *);
WINPTHREAD_API int __cdecl clock_getres64(clockid_t, struct _timespec64 *);
WINPTHREAD_TIME_DECL int __cdecl clock_getres(clockid_t _C, struct timespec *_T)
{
#if WINPTHREADS_TIME_BITS == 32
  return clock_getres32(_C, (struct _timespec32 *)_T);
#else
  return clock_getres64(_C, (struct _timespec64 *)_T);
#endif
}

WINPTHREAD_API int __cdecl clock_gettime32(clockid_t, struct _timespec32 *);
WINPTHREAD_API int __cdecl clock_gettime64(clockid_t, struct _timespec64 *);
WINPTHREAD_TIME_DECL int __cdecl clock_gettime(clockid_t _C, struct timespec *_T)
{
#if WINPTHREADS_TIME_BITS == 32
  return clock_gettime32(_C, (struct _timespec32 *)_T);
#else
  return clock_gettime64(_C, (struct _timespec64 *)_T);
#endif
}

WINPTHREAD_API int __cdecl clock_settime32(clockid_t, const struct _timespec32 *);
WINPTHREAD_API int __cdecl clock_settime64(clockid_t, const struct _timespec64 *);
WINPTHREAD_TIME_DECL int __cdecl clock_settime(clockid_t _C, const struct timespec *_T)
{
#if WINPTHREADS_TIME_BITS == 32
  return clock_settime32(_C, (const struct _timespec32 *)_T);
#else
  return clock_settime64(_C, (const struct _timespec64 *)_T);
#endif
}

WINPTHREAD_API int __cdecl clock_nanosleep32(clockid_t, int, const struct _timespec32 *, struct _timespec32 *);
WINPTHREAD_API int __cdecl clock_nanosleep64(clockid_t, int, const struct _timespec64 *, struct _timespec64 *);
WINPTHREAD_TIME_DECL int __cdecl clock_nanosleep(clockid_t _C, int _F, const struct timespec *_T1, struct timespec *_T2)
{
#if WINPTHREADS_TIME_BITS == 32
  return clock_nanosleep32(_C, _F, (const struct _timespec32 *)_T1, (struct _timespec32 *)_T2);
#else
  return clock_nanosleep64(_C, _F, (const struct _timespec64 *)_T1, (struct _timespec64 *)_T2);
#endif
}

#ifdef __cplusplus
}
#endif

#endif /* WIN_PTHREADS_TIME_H */
