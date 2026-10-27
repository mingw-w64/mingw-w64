/*
   Copyright (c) 2011-2016 mingw-w64 project

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

/*
 * Parts of this library are derived by:
 *
 * Posix Threads library for Microsoft Windows
 *
 * Use at own risk, there is no implied warranty to this code.
 * It uses undocumented features of Microsoft Windows that can change
 * at any time in the future.
 *
 * (C) 2010 Lockless Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  * Neither the name of Lockless Inc. nor the names of its contributors may be
 *    used to endorse or promote products derived from this software without
 *    specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AN
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef WIN_PTHREADS_H
#define WIN_PTHREADS_H

#include <stddef.h>
#include <errno.h>
#include <sys/types.h>

#include <process.h>
#include <limits.h>
#include <signal.h>
#include <time.h>

#include "pthread_compat.h"
#include "sched.h"

#ifdef _MSC_VER
#include "pthread_time.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define __WINPTHREADS_VERSION_MAJOR 0
#define __WINPTHREADS_VERSION_MINOR 5
#define __WINPTHREADS_VERSION_PATCHLEVEL 0

/* MSB 8-bit major version, 8-bit minor version, 16-bit patch level.  */
#define __WINPTHREADS_VERSION 0x00050000

/* Compatibility stuff: */
#define RWLS_PER_THREAD						8

/* pthread specific defines.  */

#define PTHREAD_CANCEL_DISABLE 0
#define PTHREAD_CANCEL_ENABLE 0x01

#define PTHREAD_CANCEL_DEFERRED 0
#define PTHREAD_CANCEL_ASYNCHRONOUS 0x02

#define PTHREAD_CREATE_JOINABLE 0
#define PTHREAD_CREATE_DETACHED 0x04

#define PTHREAD_EXPLICIT_SCHED 0
#define PTHREAD_INHERIT_SCHED 0x08

#define PTHREAD_SCOPE_PROCESS 0
#define PTHREAD_SCOPE_SYSTEM 0x10

#define PTHREAD_DEFAULT_ATTR (PTHREAD_CANCEL_ENABLE)

#define PTHREAD_CANCELED ((void *) (intptr_t) 0xDEADBEEF)

#define _PTHREAD_NULL_THREAD ((pthread_t) 0)

#define PTHREAD_ONCE_INIT 0

#define PTHREAD_DESTRUCTOR_ITERATIONS 256
#define PTHREAD_KEYS_MAX (1<<20)

#define PTHREAD_PRIO_NONE 0
#define PTHREAD_PRIO_INHERIT 8
#define PTHREAD_PRIO_PROTECT 16
#define PTHREAD_PROCESS_SHARED 1
#define PTHREAD_PROCESS_PRIVATE 0

WINPTHREAD_API void * pthread_timechange_handler_np(void * dummy);
WINPTHREAD_API int    pthread_delay32_np (const struct _timespec32 *interval);
WINPTHREAD_API int    pthread_delay64_np (const struct _timespec64 *interval);
WINPTHREAD_THREAD_DECL int    pthread_delay_np (const struct timespec *interval)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_delay32_np ((const struct _timespec32 *) interval);
#else
  return pthread_delay64_np ((const struct _timespec64 *) interval);
#endif
}
WINPTHREAD_API int    pthread_num_processors_np(void);
WINPTHREAD_API int    pthread_set_num_processors_np(int n);

#define PTHREAD_BARRIER_SERIAL_THREAD 1

/* maximum number of times a read lock may be obtained */
#define	MAX_READ_LOCKS		(INT_MAX - 1)

/* No fork() in windows - so ignore this */
#define pthread_atfork(F1,F2,F3) 0

/* unsupported stuff: */
#define pthread_getcpuclockid(T, C) ENOTSUP
#define pthread_attr_getguardsize(A, S) ENOTSUP
#define pthread_attr_setguardsize(A, S) ENOTSUP

typedef long pthread_once_t;
typedef unsigned pthread_key_t;
typedef void *pthread_barrierattr_t;
typedef int pthread_condattr_t;
typedef int pthread_rwlockattr_t;
typedef uintptr_t pthread_t;

typedef struct _pthread_cleanup _pthread_cleanup;
struct _pthread_cleanup
{
    void (*func)(void *);
    void *arg;
    _pthread_cleanup *next;
};

/* Using MemoryBarrier() requires including Windows headers. User code
 * may want to use pthread_cleanup_push without including Windows headers
 * first, thus prefer GCC specific intrinsics where possible. */
#ifdef __GNUC__
#define __pthread_MemoryBarrier() __sync_synchronize()
#else
#define __pthread_MemoryBarrier() MemoryBarrier()
#endif

#define pthread_cleanup_push(F, A)                                      \
    do {                                                                \
        const _pthread_cleanup _pthread_cup =                           \
            { (F), (A), *pthread_getclean() };                          \
        __pthread_MemoryBarrier();                                      \
        *pthread_getclean() = (_pthread_cleanup *) &_pthread_cup;       \
        __pthread_MemoryBarrier();                                      \
        do {                                                            \
            do {} while (0)

/* Note that if async cancelling is used, then there is a race here */
#define pthread_cleanup_pop(E)                                          \
        } while (0);                                                    \
        *pthread_getclean() = _pthread_cup.next;                        \
        if ((E)) _pthread_cup.func((pthread_once_t *)_pthread_cup.arg); \
    } while (0)

typedef struct pthread_attr_t pthread_attr_t;
struct pthread_attr_t
{
    unsigned p_state;
    void *stack;
    size_t s_size;
    struct sched_param param;
};

WINPTHREAD_API int pthread_attr_setschedparam(pthread_attr_t *attr, const struct sched_param *param);
WINPTHREAD_API int pthread_attr_getschedparam(const pthread_attr_t *attr, struct sched_param *param);
WINPTHREAD_API int pthread_getschedparam(pthread_t thread, int *pol, struct sched_param *param);
WINPTHREAD_API int pthread_setschedparam(pthread_t thread, int pol, const struct sched_param *param);
WINPTHREAD_API int pthread_attr_setschedpolicy (pthread_attr_t *attr, int pol);
WINPTHREAD_API int pthread_attr_getschedpolicy (const pthread_attr_t *attr, int *pol);

/**
 * Mutex (pthread_mutex_t) declarations, definitions and functions.
 */

#define PTHREAD_MUTEX_DEFAULT    PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_NORMAL     0
#define PTHREAD_MUTEX_ERRORCHECK 1
#define PTHREAD_MUTEX_RECURSIVE  2

/**
 * Implementation-defined mutex types.
 */
#define PTHREAD_MUTEX_ADAPTIVE_NP   PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_FAST_NP       PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_TIMED_NP      PTHREAD_MUTEX_NORMAL
#define PTHREAD_MUTEX_ERRORCHECK_NP PTHREAD_MUTEX_ERRORCHECK
#define PTHREAD_MUTEX_RECURSIVE_NP  PTHREAD_MUTEX_RECURSIVE

/**
 * Not POSIX; pthread-win32 compatibility?
 */
#define PTHREAD_MUTEX_PRIVATE 0
#define PTHREAD_MUTEX_SHARED  1

#define PTHREAD_MUTEX_STALLED 0
#define PTHREAD_MUTEX_ROBUST  1

typedef unsigned pthread_mutexattr_t;

WINPTHREAD_API int pthread_mutexattr_init(pthread_mutexattr_t *);
WINPTHREAD_API int pthread_mutexattr_destroy(pthread_mutexattr_t *);
WINPTHREAD_API int pthread_mutexattr_settype(pthread_mutexattr_t *, int);
WINPTHREAD_API int pthread_mutexattr_gettype(const pthread_mutexattr_t *, int *);
WINPTHREAD_API int pthread_mutexattr_setpshared(pthread_mutexattr_t *, int);
WINPTHREAD_API int pthread_mutexattr_getpshared(const pthread_mutexattr_t *, int *);
WINPTHREAD_API int pthread_mutexattr_setprotocol(pthread_mutexattr_t *, int);
WINPTHREAD_API int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *, int *);
WINPTHREAD_API int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *, int);
WINPTHREAD_API int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *, int *);
WINPTHREAD_API int pthread_mutexattr_setrobust(pthread_mutexattr_t *, int);
WINPTHREAD_API int pthread_mutexattr_getrobust(const pthread_mutexattr_t *, int *);

typedef intptr_t pthread_mutex_t;

#define PTHREAD_MUTEX_INITIALIZER            PTHREAD_DEFAULT_MUTEX_INITIALIZER
#define PTHREAD_DEFAULT_MUTEX_INITIALIZER    PTHREAD_NORMAL_MUTEX_INITIALIZER
#define PTHREAD_NORMAL_MUTEX_INITIALIZER     ((pthread_mutex_t)-1)
#define PTHREAD_ERRORCHECK_MUTEX_INITIALIZER ((pthread_mutex_t)-2)
#define PTHREAD_RECURSIVE_MUTEX_INITIALIZER  ((pthread_mutex_t)-3)

WINPTHREAD_API int pthread_mutex_init(pthread_mutex_t *, const pthread_mutexattr_t *);
WINPTHREAD_API int pthread_mutex_destroy(pthread_mutex_t *);
WINPTHREAD_API int pthread_mutex_lock(pthread_mutex_t *);
WINPTHREAD_API int pthread_mutex_trylock(pthread_mutex_t *);
WINPTHREAD_API int pthread_mutex_unlock(pthread_mutex_t *);
WINPTHREAD_API int pthread_mutex_consistent(pthread_mutex_t *);
WINPTHREAD_API int pthread_mutex_timedlock32(pthread_mutex_t *, const struct _timespec32 *);
WINPTHREAD_API int pthread_mutex_timedlock64(pthread_mutex_t *, const struct _timespec64 *);
WINPTHREAD_MUTEX_DECL int pthread_mutex_timedlock(pthread_mutex_t *_M, const struct timespec *_T)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_mutex_timedlock32 (_M, (const struct _timespec32 *) _T);
#else
  return pthread_mutex_timedlock64 (_M, (const struct _timespec64 *) _T);
#endif
}

/**
 * Not implemented.
 */
#define pthread_mutex_setprioceiling(M, P) ENOTSUP
#define pthread_mutex_getprioceiling(M, P) ENOTSUP

/**
 * Spinlock (pthread_spinlock_t) declarations, definitions and functions.
 *
 * NOTE: they are not really spinlocks; they are nearly equivalent to stalled
 *   error-checking mutexes.
 */

typedef intptr_t pthread_spinlock_t;

#define PTHREAD_SPINLOCK_INITIALIZER ((pthread_spinlock_t)-1)

WINPTHREAD_API int pthread_spin_init(pthread_spinlock_t *, int);
WINPTHREAD_API int pthread_spin_destroy(pthread_spinlock_t *);
WINPTHREAD_API int pthread_spin_lock(pthread_spinlock_t *);
WINPTHREAD_API int pthread_spin_trylock(pthread_spinlock_t *);
WINPTHREAD_API int pthread_spin_unlock(pthread_spinlock_t *);

/* synchronization objects */
typedef intptr_t pthread_cond_t;
typedef intptr_t pthread_rwlock_t;
typedef void	*pthread_barrier_t;

#define PTHREAD_COND_INITIALIZER   ((pthread_cond_t)-1)
#define PTHREAD_RWLOCK_INITIALIZER ((pthread_rwlock_t)-1)

WINPTHREAD_API extern void (**_pthread_key_dest)(void *);
WINPTHREAD_API int         pthread_key_create(pthread_key_t *key, void (* dest)(void *));
WINPTHREAD_API int         pthread_key_delete(pthread_key_t key);
WINPTHREAD_API void *      pthread_getspecific(pthread_key_t key);
WINPTHREAD_API int         pthread_setspecific(pthread_key_t key, const void *value);

WINPTHREAD_API pthread_t pthread_self(void);
WINPTHREAD_API int       pthread_once(pthread_once_t *o, void (*func)(void));
WINPTHREAD_API void      pthread_testcancel(void);
WINPTHREAD_API int       pthread_equal(pthread_t t1, pthread_t t2);
WINPTHREAD_API void      pthread_tls_init(void);
WINPTHREAD_API void      _pthread_cleanup_dest(pthread_t t);
WINPTHREAD_API int       pthread_get_concurrency(int *val);
WINPTHREAD_API int       pthread_set_concurrency(int val);
WINPTHREAD_API void      pthread_exit(void *res);
WINPTHREAD_API void      _pthread_invoke_cancel(void);
WINPTHREAD_API int       pthread_cancel(pthread_t t);
WINPTHREAD_API int       pthread_kill(pthread_t t, int sig);
WINPTHREAD_API unsigned  _pthread_get_state(const pthread_attr_t *attr, unsigned flag);
WINPTHREAD_API int       _pthread_set_state(pthread_attr_t *attr, unsigned flag, unsigned val);
WINPTHREAD_API int       pthread_setcancelstate(int state, int *oldstate);
WINPTHREAD_API int       pthread_setcanceltype(int type, int *oldtype);
WINPTHREAD_API unsigned  __stdcall pthread_create_wrapper(void *args);
WINPTHREAD_API int       pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(* func)(void *), void *arg);
WINPTHREAD_API int       pthread_join(pthread_t t, void **res);
WINPTHREAD_API int       pthread_detach(pthread_t t);
WINPTHREAD_API int       pthread_setname_np(pthread_t thread, const char *name);
WINPTHREAD_API int       pthread_getname_np(pthread_t thread, char *name, size_t len);

WINPTHREAD_API int pthread_rwlock_init(pthread_rwlock_t *rwlock_, const pthread_rwlockattr_t *attr);
WINPTHREAD_API int pthread_rwlock_wrlock(pthread_rwlock_t *l);
WINPTHREAD_API int pthread_rwlock_timedwrlock32(pthread_rwlock_t *rwlock, const struct _timespec32 *ts);
WINPTHREAD_API int pthread_rwlock_timedwrlock64(pthread_rwlock_t *rwlock, const struct _timespec64 *ts);
WINPTHREAD_RWLOCK_DECL int pthread_rwlock_timedwrlock(pthread_rwlock_t *rwlock, const struct timespec *ts)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_rwlock_timedwrlock32 (rwlock, (const struct _timespec32 *) ts);
#else
  return pthread_rwlock_timedwrlock64 (rwlock, (const struct _timespec64 *) ts);
#endif
}
WINPTHREAD_API int pthread_rwlock_rdlock(pthread_rwlock_t *l);
WINPTHREAD_API int pthread_rwlock_timedrdlock32(pthread_rwlock_t *l, const struct _timespec32 *ts);
WINPTHREAD_API int pthread_rwlock_timedrdlock64(pthread_rwlock_t *l, const struct _timespec64 *ts);
WINPTHREAD_RWLOCK_DECL int pthread_rwlock_timedrdlock(pthread_rwlock_t *l, const struct timespec *ts)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_rwlock_timedrdlock32 (l, (const struct _timespec32 *) ts);
#else
  return pthread_rwlock_timedrdlock64 (l, (const struct _timespec64 *) ts);
#endif
}
WINPTHREAD_API int pthread_rwlock_unlock(pthread_rwlock_t *l);
WINPTHREAD_API int pthread_rwlock_tryrdlock(pthread_rwlock_t *l);
WINPTHREAD_API int pthread_rwlock_trywrlock(pthread_rwlock_t *l);
WINPTHREAD_API int pthread_rwlock_destroy (pthread_rwlock_t *l);

WINPTHREAD_API int pthread_cond_init(pthread_cond_t *cv, const pthread_condattr_t *a);
WINPTHREAD_API int pthread_cond_destroy(pthread_cond_t *cv);
WINPTHREAD_API int pthread_cond_signal (pthread_cond_t *cv);
WINPTHREAD_API int pthread_cond_broadcast (pthread_cond_t *cv);
WINPTHREAD_API int pthread_cond_wait (pthread_cond_t *cv, pthread_mutex_t *external_mutex);
WINPTHREAD_API int pthread_cond_timedwait32(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct _timespec32 *t);
WINPTHREAD_API int pthread_cond_timedwait64(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct _timespec64 *t);
WINPTHREAD_COND_DECL int pthread_cond_timedwait(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct timespec *t)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_cond_timedwait32 (cv, external_mutex, (const struct _timespec32 *) t);
#else
  return pthread_cond_timedwait64 (cv, external_mutex, (const struct _timespec64 *) t);
#endif
}
WINPTHREAD_API int pthread_cond_timedwait32_relative_np(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct _timespec32 *t);
WINPTHREAD_API int pthread_cond_timedwait64_relative_np(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct _timespec64 *t);
WINPTHREAD_COND_DECL int pthread_cond_timedwait_relative_np(pthread_cond_t *cv, pthread_mutex_t *external_mutex, const struct timespec *t)
{
#if WINPTHREADS_TIME_BITS == 32
  return pthread_cond_timedwait32_relative_np (cv, external_mutex, (const struct _timespec32 *) t);
#else
  return pthread_cond_timedwait64_relative_np (cv, external_mutex, (const struct _timespec64 *) t);
#endif
}

WINPTHREAD_API int pthread_barrier_destroy(pthread_barrier_t *b);
WINPTHREAD_API int pthread_barrier_init(pthread_barrier_t *b, const void *attr, unsigned int count);
WINPTHREAD_API int pthread_barrier_wait(pthread_barrier_t *b);

WINPTHREAD_API int pthread_attr_init(pthread_attr_t *attr);
WINPTHREAD_API int pthread_attr_destroy(pthread_attr_t *attr);
WINPTHREAD_API int pthread_attr_setdetachstate(pthread_attr_t *a, int flag);
WINPTHREAD_API int pthread_attr_getdetachstate(const pthread_attr_t *a, int *flag);
WINPTHREAD_API int pthread_attr_setinheritsched(pthread_attr_t *a, int flag);
WINPTHREAD_API int pthread_attr_getinheritsched(const pthread_attr_t *a, int *flag);
WINPTHREAD_API int pthread_attr_setscope(pthread_attr_t *a, int flag);
WINPTHREAD_API int pthread_attr_getscope(const pthread_attr_t *a, int *flag);
WINPTHREAD_API int pthread_attr_getstack(const pthread_attr_t *attr, void **stack, size_t *size);
WINPTHREAD_API int pthread_attr_setstack(pthread_attr_t *attr, void *stack, size_t size);
WINPTHREAD_API int pthread_attr_getstackaddr(const pthread_attr_t *attr, void **stack);
WINPTHREAD_API int pthread_attr_setstackaddr(pthread_attr_t *attr, void *stack);
WINPTHREAD_API int pthread_attr_getstacksize(const pthread_attr_t *attr, size_t *size);
WINPTHREAD_API int pthread_attr_setstacksize(pthread_attr_t *attr, size_t size);

WINPTHREAD_API int pthread_getconcurrency(void);
WINPTHREAD_API int pthread_setconcurrency(int new_level);

WINPTHREAD_API int pthread_condattr_destroy(pthread_condattr_t *a);
WINPTHREAD_API int pthread_condattr_init(pthread_condattr_t *a);
WINPTHREAD_API int pthread_condattr_getpshared(const pthread_condattr_t *a, int *s);
WINPTHREAD_API int pthread_condattr_setpshared(pthread_condattr_t *a, int s);

WINPTHREAD_API int pthread_condattr_getclock (const pthread_condattr_t *attr,
       clockid_t *clock_id);
WINPTHREAD_API int pthread_condattr_setclock(pthread_condattr_t *attr,
       clockid_t clock_id);

WINPTHREAD_API int pthread_barrierattr_init(void **attr);
WINPTHREAD_API int pthread_barrierattr_destroy(void **attr);
WINPTHREAD_API int pthread_barrierattr_setpshared(void **attr, int s);
WINPTHREAD_API int pthread_barrierattr_getpshared(void **attr, int *s);

/* Private extensions for analysis and internal use.  */
WINPTHREAD_API struct _pthread_cleanup ** pthread_getclean (void);
WINPTHREAD_API void * pthread_gethandle (pthread_t t);
WINPTHREAD_API void * pthread_getevent (void);

WINPTHREAD_API int _pthread_tryjoin (pthread_t t, void **res);
WINPTHREAD_API int pthread_rwlockattr_destroy(pthread_rwlockattr_t *a);
WINPTHREAD_API int pthread_rwlockattr_getpshared(pthread_rwlockattr_t *a, int *s);
WINPTHREAD_API int pthread_rwlockattr_init(pthread_rwlockattr_t *a);
WINPTHREAD_API int pthread_rwlockattr_setpshared(pthread_rwlockattr_t *a, int s);

#ifndef SIG_BLOCK
#define SIG_BLOCK 0
#endif
#ifndef SIG_UNBLOCK
#define SIG_UNBLOCK 1
#endif
#ifndef SIG_SETMASK
#define SIG_SETMASK 2
#endif

#include <pthread_unistd.h>

#undef _POSIX_THREAD_DESTRUCTOR_ITERATIONS
#define _POSIX_THREAD_DESTRUCTOR_ITERATIONS     PTHREAD_DESTRUCTOR_ITERATIONS

#undef _POSIX_THREAD_KEYS_MAX
#define _POSIX_THREAD_KEYS_MAX                  PTHREAD_KEYS_MAX

#undef PTHREAD_THREADS_MAX
#define PTHREAD_THREADS_MAX                     2019

#undef _POSIX_SEM_NSEMS_MAX
#define _POSIX_SEM_NSEMS_MAX                    256

#undef SEM_NSEMS_MAX
#define SEM_NSEMS_MAX                           1024

/* We deal here with a gcc issue for posix threading on Windows.
   We would need to change here gcc's gthr-posix.h header, but this
   got rejected.  So we deal it within this header.  */
#ifdef _GTHREAD_USE_MUTEX_INIT_FUNC
#undef _GTHREAD_USE_MUTEX_INIT_FUNC
#endif
#define _GTHREAD_USE_MUTEX_INIT_FUNC 1

#ifdef __cplusplus
}
#endif

#endif /* WIN_PTHREADS_H */
