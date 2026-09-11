/*
   Copyright (c) 2011, 2014, 2026 mingw-w64 project
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

#include <limits.h>
#include <stdlib.h>

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

/**
 * Forward declaration; see definition below.
 */
typedef union WinpthreadsMutex WinpthreadsMutex;

/**
 * Mutex type-specific "init" routine.
 */
typedef int (* FuncMutexInit) (WinpthreadsMutex **, const pthread_mutexattr_t *);

/**
 * Mutex type-specific "destroy" routine.
 */
typedef void (* FuncMutexDestroy) (WinpthreadsMutex *);

/**
 * Mutex type-specific "lock" routine.
 *
 * If second argument is `NULL`, this function will block indefinitely.
 */
typedef int (* FuncMutexLock) (WinpthreadsMutex *, const struct _timespec64 *);

/**
 * Mutex type-specific "try lock" routine.
 *
 * If second argument is `TRUE`, this function will only succeed if mutex is
 * not owned by any thread, including the calling thread.
 */
typedef int (* FuncMutexTryLock) (WinpthreadsMutex *, BOOL);

/**
 * Mutex type-specific "unlock" routine.
 */
typedef int (* FuncMutexUnlock) (WinpthreadsMutex *);

/**
 * Implementation for specific Mutex type.
 */
typedef struct {
  FuncMutexInit Init;
  FuncMutexDestroy Destroy;
  FuncMutexLock Lock;
  FuncMutexTryLock TryLock;
  FuncMutexUnlock Unlock;
} WinpthreadsMutexVtable;

#define THREAD_ID_NO_OWNER ((DWORD) -1)

/**
 * Mutex lock states.
 */
typedef enum {
  /**
   * Mutex is unlocked.
   */
  Unlocked,
  /**
   * Mutex is locked.
   *
   * This state inicates that there are no blocked threads waiting for
   * the mutex to be released.
   *
   * While in this state, if any thread blocks waiting for the mutex to be
   * released, the lock state will change to `LockedWithBlocking`.
   */
  Locked,
  /**
   * Mutex is locked.
   *
   * This state indicates that there can be one or more blocked threads waiting
   * for the mutex to be released.
   */
  LockedWithBlocking,
} WinpthreadsMutexLockState;

/**
 * Common base for `Winpthreads{Type}Mutex` structures defined below.
 */
typedef struct {
  const WinpthreadsMutexVtable *Vtable;
} WinpthreadsMutexBase;

/**
 * Data specific to Normal Mutex implementation.
 */
typedef struct {
  WinpthreadsMutexBase Base;
  /**
   * Auto-reset event.
   *
   * Normal Mutexes are implemented using auto-reset events.
   */
  HANDLE Event;
  /**
   * One of `WinpthreadsMutexLockState` values.
   */
  LONG LockState;
} WinpthreadsNormalMutex;

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsNormalMutex, Base.Vtable), "");

/**
 * Data specific to Error Checking Mutex implementation.
 */
typedef struct {
  WinpthreadsMutexBase Base;
  /**
   * Auto-reset event.
   *
   * Error Checking Mutexes are implemented using auto-reset events.
   */
  HANDLE Event;
  /**
   * One of `WinpthreadsMutexLockState` values.
   */
  LONG LockState;
  /**
   * ID of the thread owning the mutex.
   * If mutex has no owner, this field is set to `THREAD_ID_NO_OWNER`.
   */
  DWORD Owner;
} WinpthreadsErrorCheckMutex;

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsErrorCheckMutex, Base.Vtable), "");

/**
 * Data specific to Recursive Mutex implementation.
 */
typedef struct {
  WinpthreadsMutexBase Base;
  /**
   * Auto-reset event.
   *
   * Recursive Mutexes are implemented using auto-reset events.
   */
  HANDLE Event;
  /**
   * One of `WinpthreadsMutexLockState` values.
   */
  LONG LockState;
  /**
   * ID of the thread owning the mutex.
   * If mutex has no owner, this field is set to `THREAD_ID_NO_OWNER`.
   */
  DWORD Owner;
  /**
   * Recursive lock count.
   *
   * When a thread locks the mutex, this value is incremented by 1.
   * When a thread unlocks the mutex, this value is decremented by 1.
   *
   * A thread owns the mutes as long as lock count is greater than zero;
   * once lock count reaches zero, the owning thread releases the ownership of
   * the mutex.
   */
  unsigned int LockCount;
} WinpthreadsRecursiveMutex;

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsRecursiveMutex, Base.Vtable), "");

/**
 * Union pointed to by `pthread_mutex_t` objects.
 */
union WinpthreadsMutex {
  WinpthreadsMutexBase       Base;
  WinpthreadsNormalMutex     NormalMutex;
  WinpthreadsErrorCheckMutex ErrorCheckMutex;
  WinpthreadsRecursiveMutex  RecursiveMutex;
};

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsMutex, Base.Vtable), "");

/*******************************************************************************
 * Common helper functions.
 */

/**
 * Wait until `handle` becomes signaled or timeout specified by `waitUntil`
 * has expired. If `waitUntil` is `NULL`, this function waits indefinitely until
 * `handle` becomes signaled.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int WinpthreadsTimedWait (HANDLE handle, LONG *lockState, const struct _timespec64 *waitUntil) {
  unsigned __int64 waitStartTime = 0;
  unsigned __int64 waitEndTime   = 0;
  unsigned __int64 waitTimeout   = INFINITE;

  if (waitUntil != NULL) {
    waitStartTime = _pthread_time_in_ms ();
    waitEndTime   = _pthread_time_in_ms_from_timespec (waitUntil);
    waitTimeout   = 0;

    if (waitStartTime < waitEndTime) {
      waitTimeout = waitEndTime - waitStartTime;

      if (waitTimeout > INFINITE) {
        waitTimeout = INFINITE;
      }
    }
  }

  /**
   * Setting lock state to `LockedWithBlocking` prevents the fast lock path
   * (`lockState` cannot be set to `Locked`) and it causes
   * `Winpthreads*MutexUnlock` functions to signal `handle`.
   */
  LONG oldLockState = InterlockedExchange (lockState, LockedWithBlocking);

  while (oldLockState != Unlocked) {
    switch (_pthread_wait_for_single_object (handle, (DWORD) waitTimeout)) {
      /**
       * `handle` was in signaled state (unlocked) or it became signaled
       * within `waitTimeout`.
       */
      case WAIT_OBJECT_0:
        break;
      /**
       * `handle` was not signaled (unlocked) before `waitTimeout` expired.
       */
      case WAIT_TIMEOUT:
        return ETIMEDOUT;
      default:
        return EINVAL;
    }

    /**
     * There is a small chance that another thread grabs the lock faster
     * than we do; lock state is updated before wait handle is signaled.
     */
    oldLockState = InterlockedExchange (lockState, LockedWithBlocking);

    if (likely (oldLockState == Unlocked)) {
      break;
    }

    /**
     * Update `waitTimeout`, if not `INFINITE`.
     */
    if (waitTimeout != INFINITE) {
      waitStartTime = _pthread_time_in_ms ();

      if (waitStartTime >= waitEndTime) {
        return ETIMEDOUT;
      }

      waitTimeout = waitEndTime - waitStartTime;
    }
  }

  return 0;
}

/*******************************************************************************
 * Normal Mutex (PTHREAD_MUTEX_NORMAL) implementation.
 *
 * Normal Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   results in a dead lock.
 * - Attempt to unlock a mutex that is not owned by the calling thread is UB.
 * - Attempt to unlock an unlocked mutex is UB.
 *
 * Historically, in winpthreads, Normal Mutexes ignore ownership,
 * which results in the following well-defined behavior:
 *
 * - Calls to `pthread_mutex_unlock` always succeed; and
 * - A thread can unlock mutex owned by another thread.
 */

static int WinpthreadsNormalMutexInit (WinpthreadsMutex **wMutex, const pthread_mutexattr_t *attr) {
  WinpthreadsNormalMutex *mutex = malloc (sizeof (WinpthreadsNormalMutex));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mutex == NULL) {
    return ENOMEM;
  }

  mutex->Event = CreateEventW (NULL, FALSE, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mutex->Event == NULL) {
    free (mutex);
    return EAGAIN;
  }

  mutex->LockState = Unlocked;
  *wMutex = (WinpthreadsMutex *) mutex;

  return 0;
  UNREFERENCED_PARAMETER (attr);
}

static void WinpthreadsNormalMutexDestroy (WinpthreadsMutex *wMutex) {
  WinpthreadsNormalMutex *mutex = &wMutex->NormalMutex;
  HANDLE event = InterlockedExchangePointer ((void **) &mutex->Event, NULL);

  if (event != NULL) {
    CloseHandle (event);
  }

  free (mutex);
}

static int WinpthreadsNormalMutexLock (WinpthreadsMutex *wMutex, const struct _timespec64 *waitUntil) {
  WinpthreadsNormalMutex *mutex = &wMutex->NormalMutex;

  /**
   * Try the fast path.
   */
  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) == Unlocked) {
    return 0;
  }

  return WinpthreadsTimedWait (mutex->Event, &mutex->LockState, waitUntil);
}

static int WinpthreadsNormalMutexTryLock (WinpthreadsMutex *wMutex, BOOL exclusiveLock) {
  WinpthreadsNormalMutex *mutex = &wMutex->NormalMutex;

  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) != Unlocked) {
    return EBUSY;
  }

  return 0;
  UNREFERENCED_PARAMETER (exclusiveLock);
}

static int WinpthreadsNormalMutexUnlock (WinpthreadsMutex *wMutex) {
  WinpthreadsNormalMutex *mutex = &wMutex->NormalMutex;

  /**
   * If `mutex->LockState` is `LockedWithBlocking`, then some other thread is
   * waiting for `mutex->Event` to become signaled.
   */
  if (InterlockedExchange (&mutex->LockState, Unlocked) == LockedWithBlocking) {
    if (!SetEvent (mutex->Event)) {
      return EINVAL;
    }
  }

  return 0;
}

static const WinpthreadsMutexVtable WinpthreadsNormalMutexVtable = {
  .Init    = WinpthreadsNormalMutexInit,
  .Destroy = WinpthreadsNormalMutexDestroy,
  .Lock    = WinpthreadsNormalMutexLock,
  .TryLock = WinpthreadsNormalMutexTryLock,
  .Unlock  = WinpthreadsNormalMutexUnlock,
};

/*******************************************************************************
 * Error Checking Mutex (PTHREAD_MUTEX_ERRORCHECK) implementation.
 *
 * Error Checking Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   fails with EDEADLK.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsErrorCheckMutexInit (WinpthreadsMutex **wMutex, const pthread_mutexattr_t *attr) {
  WinpthreadsErrorCheckMutex *mutex = malloc (sizeof (WinpthreadsErrorCheckMutex));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mutex == NULL) {
    return ENOMEM;
  }

  mutex->Event = CreateEventW (NULL, FALSE, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mutex->Event == NULL) {
    free (mutex);
    return EAGAIN;
  }

  mutex->LockState = Unlocked;
  mutex->Owner     = THREAD_ID_NO_OWNER;

  *wMutex = (WinpthreadsMutex *) mutex;

  return 0;
  UNREFERENCED_PARAMETER (attr);
}

static void WinpthreadsErrorCheckMutexDestroy (WinpthreadsMutex *wMutex) {
  WinpthreadsErrorCheckMutex *mutex = &wMutex->ErrorCheckMutex;
  HANDLE event = InterlockedExchangePointer ((void **) &mutex->Event, NULL);

  if (event != NULL) {
    CloseHandle (event);
  }

  free (mutex);
}

static int WinpthreadsErrorCheckMutexLock (WinpthreadsMutex *wMutex, const struct _timespec64 *waitUntil) {
  WinpthreadsErrorCheckMutex *mutex = &wMutex->ErrorCheckMutex;

  DWORD threadId = GetCurrentThreadId ();

  if (mutex->Owner == threadId) {
    return EDEADLK;
  }

  /**
   * Try the fast path.
   */
  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) == Unlocked) {
    goto done;
  }

  int error_code = WinpthreadsTimedWait (mutex->Event, &mutex->LockState, waitUntil);

  if (error_code) {
    return error_code;
  }

done:
  mutex->Owner = threadId;

  return 0;
}

static int WinpthreadsErrorCheckMutexTryLock (WinpthreadsMutex *wMutex, BOOL exclusiveLock) {
  WinpthreadsErrorCheckMutex *mutex = &wMutex->ErrorCheckMutex;

  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) != Unlocked) {
    return EBUSY;
  }

  mutex->Owner = GetCurrentThreadId ();

  return 0;
  UNREFERENCED_PARAMETER (exclusiveLock);
}

static int WinpthreadsErrorCheckMutexUnlock (WinpthreadsMutex *wMutex) {
  WinpthreadsErrorCheckMutex *mutex = &wMutex->ErrorCheckMutex;

  LONG threadId = (LONG) GetCurrentThreadId ();

  if (InterlockedCompareExchange ((LONG *) &mutex->Owner, (LONG) THREAD_ID_NO_OWNER, threadId) != threadId) {
    return EPERM;
  }

  /**
   * If `mutex->LockState` is `LockedWithBlocking`, then some other thread is
   * waiting for `mutex->Event` to become signaled.
   */
  if (InterlockedExchange (&mutex->LockState, Unlocked) == LockedWithBlocking) {
    if (!SetEvent (mutex->Event)) {
      return EINVAL;
    }
  }

  return 0;
}

static const WinpthreadsMutexVtable WinpthreadsErrorCheckMutexVtable = {
  .Init    = WinpthreadsErrorCheckMutexInit,
  .Destroy = WinpthreadsErrorCheckMutexDestroy,
  .Lock    = WinpthreadsErrorCheckMutexLock,
  .TryLock = WinpthreadsErrorCheckMutexTryLock,
  .Unlock  = WinpthreadsErrorCheckMutexUnlock,
};

/*******************************************************************************
 * Recursive Mutex (PTHREAD_MUTEX_RECURSIVE) implementation.
 *
 * Recursive Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   succeeds and increases recursive lock count.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsRecursiveMutexInit (WinpthreadsMutex **wMutex, const pthread_mutexattr_t *attr) {
  WinpthreadsRecursiveMutex *mutex = malloc (sizeof (WinpthreadsRecursiveMutex));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mutex == NULL) {
    return ENOMEM;
  }

  mutex->Event = CreateEventW (NULL, FALSE, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mutex->Event == NULL) {
    free (mutex);
    return EAGAIN;
  }

  mutex->LockState = Unlocked;
  mutex->Owner     = THREAD_ID_NO_OWNER;
  mutex->LockCount = 0;

  *wMutex = (WinpthreadsMutex *) mutex;

  return 0;
  UNREFERENCED_PARAMETER (attr);
}

static void WinpthreadsRecursiveMutexDestroy (WinpthreadsMutex *wMutex) {
  WinpthreadsRecursiveMutex *mutex = &wMutex->RecursiveMutex;
  HANDLE event = InterlockedExchangePointer ((void **) &mutex->Event, NULL);

  if (event != NULL) {
    CloseHandle (event);
  }

  free (mutex);
}

static int WinpthreadsRecursiveMutexLock (WinpthreadsMutex *wMutex, const struct _timespec64 *waitUntil) {
  WinpthreadsRecursiveMutex *mutex = &wMutex->RecursiveMutex;

  DWORD threadId = GetCurrentThreadId ();

  /**
   * If calling thread already owns the mutex, simply increment the lock count.
   */
  if (mutex->Owner == threadId) {
    if (unlikely (mutex->LockCount == UINT_MAX)) {
      return EAGAIN;
    }

    mutex->LockCount++;
    return 0;
  }

  /**
   * Try the fast path.
   */
  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) == Unlocked) {
    goto done;
  }

  int error_code = WinpthreadsTimedWait (mutex->Event, &mutex->LockState, waitUntil);

  if (error_code) {
    return error_code;
  }

done:
  mutex->Owner = threadId;
  mutex->LockCount = 1;

  return 0;
}

static int WinpthreadsRecursiveMutexTryLock (WinpthreadsMutex *wMutex, BOOL exclusiveLock) {
  WinpthreadsRecursiveMutex *mutex = &wMutex->RecursiveMutex;

  DWORD threadId = GetCurrentThreadId ();

  /**
   * If calling thread already owns the mutex, simply increment the lock count.
   */
  if (mutex->Owner == threadId) {
    if (unlikely (exclusiveLock)) {
      return EBUSY;
    }

    if (unlikely (mutex->LockCount == UINT_MAX)) {
      return EAGAIN;
    }

    mutex->LockCount++;
    return 0;
  }

  if (InterlockedCompareExchange (&mutex->LockState, Locked, Unlocked) != Unlocked) {
    return EBUSY;
  }

  mutex->Owner = threadId;
  mutex->LockCount = 1;

  return 0;
}

static int WinpthreadsRecursiveMutexUnlock (WinpthreadsMutex *wMutex) {
  WinpthreadsRecursiveMutex *mutex = &wMutex->RecursiveMutex;

  DWORD threadId = GetCurrentThreadId ();

  if (mutex->Owner != threadId) {
    return EPERM;
  }

  mutex->LockCount--;

  if (mutex->LockCount > 0) {
    return 0;
  }

  mutex->Owner = THREAD_ID_NO_OWNER;

  /**
   * If `mutex->LockState` is `LockedWithBlocking`, then some other thread is
   * waiting for `mutex->Event` to become signaled.
   */
  if (InterlockedExchange (&mutex->LockState, Unlocked) == LockedWithBlocking) {
    if (!SetEvent (mutex->Event)) {
      return EINVAL;
    }
  }

  return 0;
}

static const WinpthreadsMutexVtable WinpthreadsRecursiveMutexVtable = {
  .Init    = WinpthreadsRecursiveMutexInit,
  .Destroy = WinpthreadsRecursiveMutexDestroy,
  .Lock    = WinpthreadsRecursiveMutexLock,
  .TryLock = WinpthreadsRecursiveMutexTryLock,
  .Unlock  = WinpthreadsRecursiveMutexUnlock,
};

/*******************************************************************************
 * Implementation for public `pthread_mutex_*` functions.
 */

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
 * Obtain pointer to `WinpthreadsMutex` structure pointed to by `m`.
 *
 * If `m` points to statically initialized `pthread_mutex_t` object,
 * allocate `WinpthreadsMutex` structure and store its address in `*m`.
 *
 * On success, stores pointer to `WinpthreadsMutex` structure in `*wMutex`.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int WinpthreadsMutexGet(pthread_mutex_t *m, WinpthreadsMutex **wMutex)
{
  *wMutex = (WinpthreadsMutex *)*m;

  /**
   * We need to avoid race condition when more than one thread attempts to use
   * same statically initialized `pthread_mutex_t` object at the same time.
   *
   * Store newly initialized mutex in `wMutex`, which is a local variable
   * supplied by the caller, and only then store it in `m`.
   *
   * If some other thread was faster then us, destroy newly created mutex
   * and use mutex pointed to by `m`.
   */
  if (unlikely (STATIC_MUTEX_INITIALIZER (*wMutex))) {
    pthread_mutexattr_t mutexAttr;
    int mutexType;

    WinpthreadsMutex *volatile initializer = *wMutex;

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
    error_code = pthread_mutex_init ((pthread_mutex_t *)wMutex, &mutexAttr);
    pthread_mutexattr_destroy (&mutexAttr);

    if (error_code) {
      return error_code;
    }

    void *mutex = InterlockedCompareExchangePointer ((void **)m, *wMutex, initializer);

    /**
     * Some other thread was faster than us.
     */
    if (unlikely (mutex != initializer)) {
      pthread_mutex_destroy ((pthread_mutex_t *)wMutex);
      *wMutex = mutex;
    }
  }

  if (unlikely (*wMutex == NULL)) {
    return EINVAL;
  }

  return 0;
}

int pthread_mutex_lock(pthread_mutex_t *m)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  return wMutex->Base.Vtable->Lock (wMutex, NULL);
}

int pthread_mutex_timedlock64(pthread_mutex_t *m, const struct _timespec64 *ts)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  /**
   * POSIX:
   *
   * Under no circumstance shall the function fail with a timeout if the mutex
   * can be locked immediately. The validity of the abstime parameter need
   * not be checked if the mutex can be locked immediately.
   */
  error_code = wMutex->Base.Vtable->TryLock (wMutex, FALSE);

  switch (error_code) {
    /**
     * Some thread owns the mutex.
     */
    case EBUSY:
      break;
    /**
     * Recursive lock count limit has been reached.
     */
    case EAGAIN:
    /**
     * The calling thread owns the mutex now.
     */
    case 0:
    /**
     * An unexpected error has occurred.
     */
    default:
      return error_code;
  }

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

  return wMutex->Base.Vtable->Lock (wMutex, ts);
}

int pthread_mutex_timedlock32(pthread_mutex_t *m, const struct _timespec32 *ts)
{
  struct _timespec64 ts64 = {.tv_sec = ts->tv_sec, .tv_nsec = ts->tv_nsec};
  return pthread_mutex_timedlock64 (m, &ts64);
}

int pthread_mutex_unlock(pthread_mutex_t *m)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  return wMutex->Base.Vtable->Unlock (wMutex);
}

int pthread_mutex_trylock(pthread_mutex_t *m)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  return wMutex->Base.Vtable->TryLock (wMutex, FALSE);
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

  const WinpthreadsMutexVtable *wMutexVtable = NULL;

  switch (type) {
    case PTHREAD_MUTEX_NORMAL:
      wMutexVtable = &WinpthreadsNormalMutexVtable;
      break;
    case PTHREAD_MUTEX_ERRORCHECK:
      wMutexVtable = &WinpthreadsErrorCheckMutexVtable;
      break;
    case PTHREAD_MUTEX_RECURSIVE:
      wMutexVtable = &WinpthreadsRecursiveMutexVtable;
      break;
    default:
      UNREACHABLE ();
  }

  WinpthreadsMutex *wMutex = NULL;

  int error_code = wMutexVtable->Init (&wMutex, a);

  if (error_code) {
    return error_code;
  }

  wMutex->Base.Vtable = wMutexVtable;
  MemoryBarrier ();
  *m = (pthread_mutex_t)wMutex;

  return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *m)
{
  /**
   * POSIX:
   *
   * If an implementation detects that the value specified by the mutex argument
   * to pthread_mutex_destroy() does not refer to an initialized mutex, it is
   * recommended that the function should fail and report an [EINVAL] error.
   */
  if (unlikely (m == NULL)) {
    return EINVAL;
  }

  WinpthreadsMutex *wMutex = (WinpthreadsMutex *)*m;

  if (unlikely (wMutex == NULL)) {
    return EINVAL;
  }

  /**
   * If `m` points to a static initializer, attempt to immediately invalidate
   * it in order to reduce window for other functions to attempt using it.
   */
  if (unlikely (STATIC_MUTEX_INITIALIZER (wMutex))) {
    WinpthreadsMutex *mutex = InterlockedCompareExchangePointer ((void **)m, NULL, wMutex);

    if (likely (mutex == wMutex) || unlikely (mutex == NULL)) {
      return 0;
    }

    wMutex = mutex;
  }

  int error_code = wMutex->Base.Vtable->TryLock (wMutex, TRUE);

  if (error_code) {
    return error_code;
  }

  InterlockedExchangePointer ((void **)m, NULL);
  wMutex->Base.Vtable->Destroy (wMutex);

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
