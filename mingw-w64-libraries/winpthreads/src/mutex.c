/*
   Copyright (c) 2011, 2014 mingw-w64 project
   Copyright (c) 2015 Intel Corporation

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

#include <malloc.h>
#include <stdio.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define WINPTHREAD_MUTEX_DECL WINPTHREAD_API

/* public header files */
#include "pthread.h"
/* internal header files */
#include "misc.h"

/**
 * Reference:
 *
 * pthread_mutex_init(), pthread_mutex_destroy():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutex_destroy.html>
 *
 * pthread_mutex_lock(), pthread_mutex_trylock(), pthread_mutex_unlock():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutex_lock.html>
 *
 * pthread_mutex_timedlock(), pthread_mutex_clocklock():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutex_clocklock.html>
 *
 * pthread_mutex_getprioceiling(), pthread_mutex_setprioceiling():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutex_getprioceiling.html>
 *
 * pthread_mutex_consistent():
 * <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutex_consistent.html>
 *
 * pthread_mutexattr_init(), pthread_mutexattr_destroy():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_destroy.html>
 *
 * pthread_mutexattr_gettype(), pthread_mutexattr_settype():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_gettype.html>
 *
 * pthread_mutexattr_getpshared(), pthread_mutexattr_setpshared():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_getpshared.html>
 *
 * pthread_mutexattr_getprotocol(), pthread_mutexattr_setprotocol():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_getprotocol.html>
 *
 * pthread_mutexattr_getprioceiling(), pthread_mutexattr_setprioceiling():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_getprioceiling.html>
 *
 * pthread_mutexattr_getrobust(), pthread_mutexattr_setrobust():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_mutexattr_getrobust.html>
 *
 * The following functions are not implemented:
 *
 * - pthread_mutex_clocklock()
 * - pthread_mutex_getprioceiling()
 * - pthread_mutex_setprioceiling()
 * - pthread_mutex_consistent()
 * - pthread_mutexattr_getrobust()
 * - pthread_mutexattr_setrobust()
 */

typedef enum {
  Unlocked,        /* Not locked. */
  Locked,          /* Locked but without waiters. */
  Waiting,         /* Locked, may have waiters. */
} mutex_state_t;

typedef enum {
  Normal,
  Errorcheck,
  Recursive,
} mutex_type_t;

/* The heap-allocated part of a mutex. */
typedef struct {
  mutex_state_t state;
  mutex_type_t type;
  HANDLE event;       /* Auto-reset event. */
  unsigned rec_lock;  /* For recursive mutexes, the number of times the
                         mutex has been locked in excess by the same thread. */
  volatile DWORD owner;  /* For recursive and error-checking mutexes, the
                            ID of the owning thread if the mutex is locked. */
} mutex_impl_t;

/**
 * Evaluates to non-zero if `m` is a static initializer for `pthread_mutex_t`:
 *
 * PTHREAD_DEFAULT_MUTEX_INITIALIZER:    -1
 * PTHREAD_NORMAL_MUTEX_INITIALIZER:     -1
 * PTHREAD_ERRORCHECK_MUTEX_INITIALIZER: -2
 * PTHREAD_RECURSIVE_MUTEX_INITIALIZER:  -3
 */
#define STATIC_MUTEX_INITIALIZER(m) ((uintptr_t)(m) >= (uintptr_t)-3)

/**
 * Obtain pointer to `mutex_impl_t` structure pointed to by `m`.
 *
 * If `m` points to statically initialzied `pthread_mutex_t` object,
 * allocate `mutex_impl_t` structure and store its address in `*m`.
 *
 * On success, stores pointer to `mutex_impl_t` structure in `*mi`.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int mutex_impl(pthread_mutex_t *m, mutex_impl_t **mi)
{
  *mi = (mutex_impl_t *)*m;

  /**
   * We need to avoid race condition when more than one thread attempts to use
   * same statically initialized `pthread_mutex_t` object at the same time.
   *
   * Store newly initialized mutex in `mi`, which is a local variable supplied
   * by the caller, and only then store it in `m`.
   *
   * If some other thread was faster then us, destroy newly created mutex
   * and use mutex pointed to by `m`.
   */
  if (unlikely (STATIC_MUTEX_INITIALIZER (*mi))) {
    pthread_mutexattr_t mutexAttr;
    int mutexType;

    mutex_impl_t *volatile initializer = *mi;

    switch ((pthread_mutex_t)initializer) {
      case PTHREAD_NORMAL_MUTEX_INITIALIZER:
        mutexType = PTHREAD_MUTEX_NORMAL;
        break;
      case PTHREAD_ERRORCHECK_MUTEX_INITIALIZER:
        mutexType = PTHREAD_MUTEX_ERRORCHECK;
        break;
      case PTHREAD_RECURSIVE_MUTEX_INITIALIZER:
        mutexType = PTHREAD_MUTEX_RECURSIVE;
        break;
      default:
        UNREACHABLE ();
    }

    int error_code = pthread_mutexattr_init (&mutexAttr);

    if (error_code) {
      return error_code;
    }

    pthread_mutexattr_settype (&mutexAttr, mutexType);
    error_code = pthread_mutex_init ((pthread_mutex_t *)mi, &mutexAttr);
    pthread_mutexattr_destroy (&mutexAttr);

    if (error_code) {
      return error_code;
    }

    void *mutex = InterlockedCompareExchangePointer ((void **)m, *mi, initializer);

    /**
     * Some other thread was faster than us.
     */
    if (unlikely (mutex != initializer)) {
      pthread_mutex_destroy ((pthread_mutex_t *)mi);
      *mi = mutex;
    }
  }

  if (unlikely (*mi == NULL)) {
    return EINVAL;
  }

  return 0;
}

/* Lock a mutex. Give up after 'timeout' ms (with ETIMEDOUT),
   or never if timeout=INFINITE. */
static WINPTHREADS_INLINE int pthread_mutex_lock_intern(pthread_mutex_t *m, DWORD timeout)
{
  mutex_impl_t *mi = NULL;

  int error_code = mutex_impl (m, &mi);

  if (error_code) {
    return error_code;
  }

  mutex_state_t old_state = InterlockedExchange((long *)&mi->state, Locked);
  if (unlikely(old_state != Unlocked)) {
    /* The mutex is already locked. */

    if (mi->type != Normal) {
      /* Recursive or Errorcheck */
      if (mi->owner == GetCurrentThreadId()) {
        /* FIXME: A recursive mutex should not need two atomic ops when locking
           recursively.  We could rewrite by doing compare-and-swap instead of
           test-and-set the first time, but it would lead to more code
           duplication and add a conditional branch to the critical path. */
        InterlockedCompareExchange((long *)&mi->state, old_state, Locked);
        if (mi->type == Recursive) {
          mi->rec_lock++;
          return 0;
        } else {
          /* type == Errorcheck */
          return EDEADLK;
        }
      }
    }

    while (InterlockedExchange((long *)&mi->state, Waiting) != Unlocked) {
      /* For timed locking attempts, it is possible (although unlikely)
         that we are woken up but someone else grabs the lock before us,
         and we have to go back to sleep again. In that case, the total
         wait may be longer than expected. */
      unsigned r = _pthread_wait_for_single_object(mi->event, timeout);
      switch (r) {
      case WAIT_TIMEOUT:
        return ETIMEDOUT;
      case WAIT_OBJECT_0:
        break;
      default:
        return EINVAL;
      }
    }
  }

  if (mi->type != Normal)
    mi->owner = GetCurrentThreadId();

  return 0;
}

int pthread_mutex_lock(pthread_mutex_t *m)
{
  return pthread_mutex_lock_intern (m, INFINITE);
}

int pthread_mutex_timedlock64(pthread_mutex_t *m, const struct _timespec64 *ts)
{
  /**
   * The pthread_mutex_timedlock() function shall fail if:
   *
   * [EINVAL]
   *  The process or thread would have blocked, and the abstime parameter
   *  specified a nanoseconds field value less than zero or greater than
   *  or equal to 1000 million.
   */
  if (ts->tv_nsec < 0 || ts->tv_nsec >= 1000000000) {
    return EINVAL;
  }

  unsigned __int64 end = _pthread_time_in_ms_from_timespec (ts);
  unsigned __int64 now = _pthread_time_in_ms ();
  unsigned __int64 patience = end > now ? end - now : 0;

  if (patience > 0xffffffff) {
    patience = INFINITE;
  }

  return pthread_mutex_lock_intern(m, (DWORD) patience);
}

int pthread_mutex_timedlock32(pthread_mutex_t *m, const struct _timespec32 *ts)
{
  struct _timespec64 ts64 = {.tv_sec = ts->tv_sec, .tv_nsec = ts->tv_nsec};
  return pthread_mutex_timedlock64 (m, &ts64);
}

int pthread_mutex_unlock(pthread_mutex_t *m)
{
  mutex_impl_t *mi = NULL;

  int error_code = mutex_impl (m, &mi);

  if (error_code) {
    return error_code;
  }

  if (unlikely(mi->type != Normal)) {
    if (mi->state == Unlocked)
      return EPERM;
    if (mi->owner != GetCurrentThreadId())
      return EPERM;
    if (mi->rec_lock > 0) {
      mi->rec_lock--;
      return 0;
    }
    mi->owner = (DWORD)-1;
  }
  if (unlikely(InterlockedExchange((long *)&mi->state, Unlocked) == Waiting)) {
    if (!SetEvent(mi->event))
      return EINVAL;
  }
  return 0;
}

int pthread_mutex_trylock(pthread_mutex_t *m)
{
  mutex_impl_t *mi = NULL;

  int error_code = mutex_impl (m, &mi);

  if (error_code) {
    return error_code;
  }

  if (InterlockedCompareExchange((long *)&mi->state, Locked, Unlocked) == Unlocked) {
    if (mi->type != Normal)
      mi->owner = GetCurrentThreadId();
    return 0;
  } else {
    if (mi->type == Recursive && mi->owner == GetCurrentThreadId()) {
      mi->rec_lock++;
      return 0;
    }
    return EBUSY;
  }
}

int pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *a)
{
  int pshared = PTHREAD_PROCESS_PRIVATE;
  int type    = PTHREAD_MUTEX_DEFAULT;

  if (a != NULL) {
    /**
     * POSIX:
     *
     * If an implementation detects that the value specified by the attr
     * argument to pthread_mutex_init() does not refer to an initialized mutex
     * attributes object, it is recommended that the function should fail and
     * report an [EINVAL] error.
     */
    if (pthread_mutexattr_getpshared (a, &pshared) != 0) {
      return EINVAL;
    }

    if (pthread_mutexattr_gettype (a, &type) != 0) {
      return EINVAL;
    }

    if (pshared == PTHREAD_PROCESS_SHARED) {
      return ENOSYS;
    }
  }

  mutex_impl_t *mi = calloc (1, sizeof (mutex_impl_t));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mi == NULL) {
    return ENOMEM;
  }

  mi->event = CreateEventW (NULL, FALSE, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mi->event == NULL) {
    free (mi);
    return EAGAIN;
  }

  switch (type) {
    case PTHREAD_MUTEX_RECURSIVE:
      mi->type = Recursive;
      break;
    case PTHREAD_MUTEX_ERRORCHECK:
      mi->type = Errorcheck;
      break;
    case PTHREAD_MUTEX_NORMAL:
      mi->type = Normal;
      break;
    default:
      UNREACHABLE ();
  }

  mi->owner    = (DWORD)-1;
  mi->state    = Unlocked;
  mi->rec_lock = 0;

  *m = (pthread_mutex_t)mi;

  return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *m)
{
  mutex_impl_t *mi = (mutex_impl_t *)*m;
  if (!STATIC_MUTEX_INITIALIZER(mi)) {
    CloseHandle(mi->event);
    free(mi);
    /* Sabotage attempts to re-use the mutex before initialising it again. */
    *m = (pthread_mutex_t)NULL;
  }

  return 0;
}

int pthread_mutexattr_init(pthread_mutexattr_t *a)
{
  *a = PTHREAD_MUTEX_NORMAL | (PTHREAD_PROCESS_PRIVATE << 3);
  return 0;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t *a)
{
  if (!a)
    return EINVAL;

  return 0;
}

int pthread_mutexattr_gettype(const pthread_mutexattr_t *a, int *type)
{
  if (!a || !type)
    return EINVAL;

  *type = *a & 3;

  return 0;
}

int pthread_mutexattr_settype(pthread_mutexattr_t *a, int type)
{
  if (!a)
    return EINVAL;

  if (type != PTHREAD_MUTEX_NORMAL && type != PTHREAD_MUTEX_RECURSIVE && type != PTHREAD_MUTEX_ERRORCHECK)
    return EINVAL;

  *a &= ~3;
  *a |= type;

  return 0;
}

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *a, int *type)
{
  if (!a || !type)
    return EINVAL;

  *type = (*a & 4 ? PTHREAD_PROCESS_SHARED : PTHREAD_PROCESS_PRIVATE);

  return 0;
}

int pthread_mutexattr_setpshared(pthread_mutexattr_t *a, int type)
{
  int r = 0;

  if (!a)
    return EINVAL;

  if (type != PTHREAD_PROCESS_SHARED && type != PTHREAD_PROCESS_PRIVATE)
    return EINVAL;

  if (type == PTHREAD_PROCESS_SHARED) {
    type = PTHREAD_PROCESS_PRIVATE;
    r = ENOSYS;
  }

  type = (type == PTHREAD_PROCESS_SHARED ? 4 : 0);

  *a &= ~4;
  *a |= type;

  return r;
}

int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *a, int *type)
{
  *type = *a & (8 + 16);
  return 0;
}

int pthread_mutexattr_setprotocol(pthread_mutexattr_t *a, int type)
{
  if ((type & (8 + 16)) != 8 + 16)
    return EINVAL;

  *a &= ~(8 + 16);
  *a |= type;

  return 0;
}

int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *a, int *prio)
{
  *prio = *a / PTHREAD_PRIO_MULT;
  return 0;
}

int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *a, int prio)
{
  *a &= (PTHREAD_PRIO_MULT - 1);
  *a += prio * PTHREAD_PRIO_MULT;

  return 0;
}
