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
 */

/**
 * Stalled (PTHREAD_MUTEX_STALLED) vs. Robust (PTHREAD_MUTEX_ROBUST) mutexes.
 *
 * Stalled mutexes are implemented using auto-reset events with fast paths:
 *
 * - `pthread_mutex_trylock` always uses the fast test-and-set path.
 *
 * - `pthread_mutex_lock` and `pthread_mutex_timedlock` will use the fast path
 *   if mutex is unlocked, and only enter wait state if required.
 *
 * Unlike stalled mutexes, robust mutexes are required to detect condition
 * when the thread that owned a mutex terminated without releasing it.
 *
 * Function `WaitForSingleObject`, when called on a Windows mutex, reports this
 * exact condition by returning `WAIT_ABANDONED`. As such, robust mutexes are
 * implemented using Windows mutexes.
 *
 * This has an implication that fast paths are not suitable for robust mutexes,
 * as they always require a call to `WaitForSingleObject` to check if the mutex
 * was abandoned. The syscall overhead may be very noticable in certain cases.
 */

/**
 * Forward declaration; see definition below.
 */
typedef union WinpthreadsMutex WinpthreadsMutex;

/**
 * Forward declaration; see definition below.
 */
typedef union WinpthreadsMutexAttributes WinpthreadsMutexAttributes;

/**
 * Mutex type-specific "init" routine.
 */
typedef int (* FuncMutexInit) (WinpthreadsMutex **, const WinpthreadsMutexAttributes *);

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
 * Mutex type-specific "mark protected state as consistent" routine.
 */
typedef int (* FuncMutexSetConsistentState) (WinpthreadsMutex *);

/**
 * Implementation for specific Mutex type.
 */
typedef struct {
  FuncMutexInit Init;
  FuncMutexDestroy Destroy;
  FuncMutexLock Lock;
  FuncMutexTryLock TryLock;
  FuncMutexUnlock Unlock;
  FuncMutexSetConsistentState SetConsistentState;
} WinpthreadsMutexVtable;

/**
 * Union stored in `pthread_mutexattr_t` objects.
 */
union WinpthreadsMutexAttributes {
  pthread_mutexattr_t Value;
  struct {
    /**
     * Can be one of the following values:
     *
     * - PTHREAD_MUTEX_NORMAL
     * - PTHREAD_MUTEX_ERRORCHECK
     * - PTHREAD_MUTEX_RECURSIVE
     */
    int Type            : 4;
    /**
     * Zero for `PTHREAD_PROCESS_PRIVATE` and non-zero for
     * `PTHREAD_PROCESS_SHARED`.
     *
     * Currently, winpthreads only supports `PTHREAD_PROCESS_PRIVATE`.
     */
    int Shared          : 1;
    /**
     * Zero for `PTHREAD_MUTEX_STALLED` and non-zero for
     * `PTHREAD_MUTEX_ROBUST`.
     */
    int Robust          : 1;
    int Reserved        : 2;
    /**
     * Can be one of the following values:
     *
     * - PTHREAD_PRIO_NONE
     * - PTHREAD_PRIO_INHERIT
     * - PTHREAD_PRIO_PROTECT
     *
     * Currently, winpthreads does not implement POSIX realtime extensions.
     * As such, the only supported value is `PTHREAD_PRIO_NONE`.
     */
    int Protocol        : 8;
    /**
     * Can be any valid `THREAD_PRIORITY_*` value.
     *
     * Only has effect when `Protocol` is `PTHREAD_PRIO_INHERIT` or
     * `PTHREAD_PRIO_PROTECT`, which are not currently supported.
     */
    int PriorityCeiling : 8;
#define WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC 0x67
    /**
     * Must be `WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC`.
     *
     * If needed, these bits may be used for future extensions.
     */
    int Magic           : 8;
  } Attributes;
};

WINPTHREADS_STATIC_ASSERT (sizeof ((WinpthreadsMutexAttributes) {}.Attributes) == sizeof (pthread_mutexattr_t), "");

/**
 * Expands into an expression of type `WinpthreadsMutexAttributes`
 * corresponding to the default mutex attributes.
 */
#define WINPTHREADS_MUTEX_ATTRIBUTES_DEFAULT ((WinpthreadsMutexAttributes) { \
    .Attributes.Type            = PTHREAD_MUTEX_NORMAL,                      \
    .Attributes.Shared          = PTHREAD_PROCESS_PRIVATE,                   \
    .Attributes.Robust          = PTHREAD_MUTEX_STALLED,                     \
    .Attributes.Reserved        = 0,                                         \
    .Attributes.Protocol        = PTHREAD_PRIO_NONE,                         \
    .Attributes.PriorityCeiling = THREAD_PRIORITY_NORMAL,                    \
    .Attributes.Magic           = WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC         \
  })

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
 * Mutex consistency states.
 */
typedef enum {
  /**
   * State protected by the mutex is consistent.
   *
   * If the thread that owns a mutex terminates without unlocking it,
   * the next thread which tries to lock the mutex will gain the ownership,
   * while the state protected by the mutex will be marked as inconsistent.
   */
  Consistent,
  /**
   * State protected by the mutex is inconsistent.
   *
   * This state is set by `pthread_mutex_unlock` when it detects that mutex
   * it tries to unlock was abandoned; the mutex becomes unlocked.
   *
   * The next thread to gain ownership of the mutex will upgrade this state
   * to `Inconsistent`.
   */
  OwnerDied,
  /**
   * State protected by the mutex is inconsistent.
   *
   * After state protected by the mutex is marked as inconsistent,
   * the thread that now owns the mutex has two options:
   *
   * 1. Call `pthread_mutex_consistent`; this will mark state protected by
   *   the mutex as consistent, and make mutex usable once again.
   *
   * 2. Call `pthread_mutex_unlock`; this will mark state protected by
   *   the mutex as unrecoverable, and the only permitted operation on such
   *   a mutex is to pass it to `pthread_mutex_destroy`.
   */
  Inconsistent,
  /**
   * State protected by the mutex is unrecoverable.
   *
   * Once state protected by the mutex is marked as unrecoverable, the mutex
   * becomes unusable and the only permitted operation is to destroy it.
   */
  Unrecoverable,
} WinpthreadsMutexConsistencyState;

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
 * Data specific to Error Checking Robust Mutex implementation.
 */
typedef struct {
  WinpthreadsMutexBase Base;
  /**
   * Mutex.
   *
   * Error Checking Robust Mutexes are implemented using mutexes.
   */
  HANDLE Mutex;
  /**
   * One of `WinpthreadsMutexConsistencyState` values.
   */
  LONG State;
  /**
   * ID of the thread owning the mutex.
   * If mutex has no owner, this field is set to `THREAD_ID_NO_OWNER`.
   */
  DWORD Owner;
} WinpthreadsErrorCheckRobustMutex;

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsErrorCheckRobustMutex, Base.Vtable), "");

/**
 * Data specific to Recursive Robust Mutex implementation.
 */
typedef struct {
  WinpthreadsMutexBase Base;
  /**
   * Mutex.
   *
   * Recursive Robust Mutexes are implemented using mutexes.
   */
  HANDLE Mutex;
  /**
   * One of `WinpthreadsMutexConsistencyState` values.
   */
  LONG State;
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
   *
   * This lock count is kept in sync with lock count for `Mutex` managed by
   * the operating system.
   */
  unsigned int LockCount;
} WinpthreadsRecursiveRobustMutex;

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsRecursiveRobustMutex, Base.Vtable), "");

/**
 * Union pointed to by `pthread_mutex_t` objects.
 */
union WinpthreadsMutex {
  WinpthreadsMutexBase       Base;
  WinpthreadsNormalMutex     NormalMutex;
  WinpthreadsErrorCheckMutex ErrorCheckMutex;
  WinpthreadsRecursiveMutex  RecursiveMutex;
  WinpthreadsErrorCheckRobustMutex ErrorCheckRobustMutex;
  WinpthreadsRecursiveRobustMutex  RecursiveRobustMutex;
};

WINPTHREADS_STATIC_ASSERT (offsetof (WinpthreadsMutexBase, Vtable) == offsetof (WinpthreadsMutex, Base.Vtable), "");

/*******************************************************************************
 * Common helper functions.
 */

/**
 * Common wait logic for stalled mutexes.
 *
 * Wait until `event` becomes signaled or timeout specified by `waitUntil`
 * has expired.
 *
 * If `waitUntil` is `NULL`, this function waits indefinitely until `event`
 * becomes signaled.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int WinpthreadsStalledMutexTimedLock (HANDLE event, LONG *lockState, const struct _timespec64 *waitUntil) {
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
   * `Winpthreads*MutexUnlock` functions to signal `event`.
   */
  LONG oldLockState = InterlockedExchange (lockState, LockedWithBlocking);

  while (oldLockState != Unlocked) {
    switch (_pthread_wait_for_single_object (event, (DWORD) waitTimeout)) {
      /**
       * `event` was in signaled state (unlocked) or it became signaled
       * within `waitTimeout`.
       */
      case WAIT_OBJECT_0:
        break;
      /**
       * `event` was not signaled (unlocked) before `waitTimeout` expired.
       */
      case WAIT_TIMEOUT:
        return ETIMEDOUT;
      default:
        return EINVAL;
    }

    /**
     * There is a small chance that another thread grabs the lock faster
     * than we do; lock state is updated before event is signaled.
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

/**
 * Common implementation for `pthread_mutex_consistent` for stalled mutexes.
 *
 * Always fails with `EINVAL`.
 */
static int WinpthreadsStalledMutexSetConsistentState (WinpthreadsMutex *wMutex) {
  /**
   * The pthread_mutex_consistent() function shall fail if:
   *
   * [EINVAL]
   *   The mutex object referenced by mutex is not robust or does not protect
   *   an inconsistent state.
   */
  return EINVAL;
  UNREFERENCED_PARAMETER (wMutex);
}

/**
 * Common wait logic for robust mutexes.
 *
 * Wait until `mutex` becomes signaled or timeout specified by `waitUntil`
 * has expired.
 *
 * If `waitUntil` is `NULL` and `withTimeout` is `FALSE`, this function waits
 * indefinitely until `mutex` becomes signaled.
 *
 * If `waitUntil` is `NULL` and `withTimeout` is `TRUE`, this function checks
 * whether `mutex` is in signaled state and then returns immedeately.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int WinpthreadsRobustMutexTimedLock (HANDLE mutex, LONG *state, BOOL withTimeout, const struct _timespec64 *waitUntil) {
  unsigned __int64 waitStartTime = 0;
  unsigned __int64 waitEndTime   = 0;
  unsigned __int64 waitTimeout   = INFINITE;

  if (withTimeout || waitUntil != NULL) {
    waitTimeout = 0;
  }

  if (waitUntil != NULL) {
    waitStartTime = _pthread_time_in_ms ();
    waitEndTime   = _pthread_time_in_ms_from_timespec (waitUntil);

    if (waitStartTime < waitEndTime) {
      waitTimeout = waitEndTime - waitStartTime;

      if (waitTimeout > INFINITE) {
        waitTimeout = INFINITE;
      }
    }
  }

  DWORD errorCode;
  int error_code;

  switch (_pthread_wait_for_single_object (mutex, (DWORD) waitTimeout)) {
    /**
     * `mutex` was in signaled state (unlocked) or it became signaled before
     * `waitTimeout` expired.
     */
    case WAIT_OBJECT_0:
      error_code = 0;
      break;
    /**
     * Previous owner of `mutex` terminated without releasing it;
     * the calling thread owns the mutex now.
     */
    case WAIT_ABANDONED:
      /**
       * Set `state` to `Inconsistent`.
       *
       * There is a non-zero possibility that `state` is `Unrecoverable`,
       * but the previous owner of `mutex` terminated before releasing it
       * following the unlikely path below.
       *
       * In such case, `state` must remain `Unrecoverable`.
       */
      if (likely (*state != Unrecoverable)) {
        *state = Inconsistent;
      }
      error_code = EOWNERDEAD;
      break;
    /**
     * `mutex` was not signaled (unlocked) before `waitTimeout` expired.
     */
    case WAIT_TIMEOUT:
      error_code = waitUntil == NULL ? EBUSY : ETIMEDOUT;
      break;
    case WAIT_FAILED:
      errorCode = GetLastError ();

      /**
       * Recursive lock count has been exceeded.
       */
      if (errorCode == ERROR_MUTANT_LIMIT_EXCEEDED) {
        error_code = EAGAIN;
        break;
      }

      /* FALLTHROUGH */
    default:
      error_code = EINVAL;
      break;
  }

  if (unlikely (*state == Unrecoverable)) {
    switch (error_code) {
      case EOWNERDEAD:
      case 0:
        /**
         * If state protected by the mutex was marked as unrecoverable,
         * release all other threads waiting on `mutex` one by one.
         */
        ReleaseMutex (mutex);
        /* FALLTHROUGH */
      case ETIMEDOUT:
      case EBUSY:
        error_code = ENOTRECOVERABLE;
    }
  }

  return error_code;
}

/*******************************************************************************
 * Normal (PTHREAD_MUTEX_NORMAL) Stalled (PTHREAD_MUTEX_STALLED) Mutex
 * implementation.
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

static int WinpthreadsNormalMutexInit (WinpthreadsMutex **wMutex, const WinpthreadsMutexAttributes *wMutexAttr) {
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
  UNREFERENCED_PARAMETER (wMutexAttr);
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

  return WinpthreadsStalledMutexTimedLock (mutex->Event, &mutex->LockState, waitUntil);
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
  .SetConsistentState = WinpthreadsStalledMutexSetConsistentState,
};

/*******************************************************************************
 * Error Checking (PTHREAD_MUTEX_ERRORCHECK) Stalled (PTHREAD_MUTEX_STALLED)
 * Mutex implementation.
 *
 * Error Checking Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   fails with EDEADLK.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsErrorCheckMutexInit (WinpthreadsMutex **wMutex, const WinpthreadsMutexAttributes *wMutexAttr) {
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
  UNREFERENCED_PARAMETER (wMutexAttr);
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

  int error_code = WinpthreadsStalledMutexTimedLock (mutex->Event, &mutex->LockState, waitUntil);

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
  .SetConsistentState = WinpthreadsStalledMutexSetConsistentState,
};

/*******************************************************************************
 * Recursive (PTHREAD_MUTEX_RECURSIVE) Stalled (PTHREAD_MUTEX_STALLED) Mutex
 * implementation.
 *
 * Recursive Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   succeeds and increases recursive lock count.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsRecursiveMutexInit (WinpthreadsMutex **wMutex, const WinpthreadsMutexAttributes *wMutexAttr) {
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
  UNREFERENCED_PARAMETER (wMutexAttr);
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

  int error_code = WinpthreadsStalledMutexTimedLock (mutex->Event, &mutex->LockState, waitUntil);

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
  .SetConsistentState = WinpthreadsStalledMutexSetConsistentState,
};

/*******************************************************************************
 * Normal (PTHREAD_MUTEX_NORMAL) Robust (PTHREAD_MUTEX_ROBUST) Mutex
 * implementation.
 *
 * Normal Robust Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   results in a dead lock.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 *
 * An attempt to obtain recursive lock on a Normal Robust Mutex mutex must
 * result in a dead lock. However, calling `WaitForSingleObject` on a mutex
 * owned by the calling thread succeeds and simply increments the lock count.
 *
 * POSIX allows `pthread_mutex_lock` to fail with `EDEADLK` when a dead lock
 * condition has been detected; this is what we do.
 *
 * However, this behavior completely matches properties of Error Checking
 * Robust Mutexes. For this reason, we use the same implementation for both.
 */

/*******************************************************************************
 * Error Checking (PTHREAD_MUTEX_ERRORCHECK) Robust (PTHREAD_MUTEX_ROBUST)
 * Mutex implementation.
 *
 * Error Checking Robust Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   fails with EDEADLK.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsErrorCheckRobustMutexInit (WinpthreadsMutex **wMutex, const WinpthreadsMutexAttributes *wMutexAttr) {
  WinpthreadsErrorCheckRobustMutex *mutex = malloc (sizeof (WinpthreadsErrorCheckRobustMutex));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mutex == NULL) {
    return ENOMEM;
  }

  mutex->Mutex = CreateMutexW (NULL, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mutex->Mutex == NULL) {
    free (mutex);
    return EAGAIN;
  }

  mutex->State = Consistent;
  mutex->Owner = THREAD_ID_NO_OWNER;

  *wMutex = (WinpthreadsMutex *) mutex;

  return 0;
  UNREFERENCED_PARAMETER (wMutexAttr);
}

static void WinpthreadsErrorCheckRobustMutexDestroy (WinpthreadsMutex *wMutex) {
  WinpthreadsErrorCheckRobustMutex *mutex = &wMutex->ErrorCheckRobustMutex;
  HANDLE mutexHandle = InterlockedExchangePointer ((void **) &mutex->Mutex, NULL);

  if (mutexHandle != NULL) {
    CloseHandle (mutexHandle);
  }

  free (mutex);
}

static int WinpthreadsErrorCheckRobustMutexLock (WinpthreadsMutex *wMutex, const struct _timespec64 *waitUntil) {
  WinpthreadsErrorCheckRobustMutex *mutex = &wMutex->ErrorCheckRobustMutex;

  /**
   * The pthread_mutex_lock() function shall fail if:
   *
   * [ENOTRECOVERABLE]
   *   The state protected by the mutex is not recoverable.
   */
  if (unlikely (mutex->State == Unrecoverable)) {
    return ENOTRECOVERABLE;
  }

  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, FALSE, waitUntil);

  /**
   * Recursive lock count has been exceeded.
   * Normally, this must never happen.
   */
  if (unlikely (error_code == EAGAIN)) {
    return EDEADLK;
  }

  if (error_code == 0 || error_code == EOWNERDEAD) {
    DWORD threadId = GetCurrentThreadId ();

    if (likely (error_code == 0)) {
      /**
       * Avoid recursive locking.
       */
      if (unlikely (mutex->Owner == threadId)) {
        ReleaseMutex (mutex->Mutex);
        return EDEADLK;
      }

      if (unlikely (mutex->State == OwnerDied)) {
        mutex->State = Inconsistent;
        error_code = EOWNERDEAD;
      }
    }

    mutex->Owner = threadId;
  }

  return error_code;
}

static int WinpthreadsErrorCheckRobustMutexTryLock (WinpthreadsMutex *wMutex, BOOL exclusiveLock) {
  WinpthreadsErrorCheckRobustMutex *mutex = &wMutex->ErrorCheckRobustMutex;

  /**
   * The pthread_mutex_trylock() function shall fail if:
   *
   * [ENOTRECOVERABLE]
   *   The state protected by the mutex is not recoverable.
   */
  if (unlikely (mutex->State == Unrecoverable)) {
    return ENOTRECOVERABLE;
  }

  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, TRUE, NULL);

  /**
   * Recursive lock count has been exceeded.
   * Normally, this must never happen.
   */
  if (unlikely (error_code == EAGAIN)) {
    return EBUSY;
  }

  if (error_code == 0 || error_code == EOWNERDEAD) {
    DWORD threadId = GetCurrentThreadId ();

    if (likely (error_code == 0)) {
      /**
       * Avoid recursive locking.
       */
      if (unlikely (mutex->Owner == threadId)) {
        ReleaseMutex (mutex->Mutex);
        return EBUSY;
      }

      if (unlikely (mutex->State == OwnerDied)) {
        mutex->State = Inconsistent;
        error_code = EOWNERDEAD;
      }
    }

    mutex->Owner = threadId;
  }

  return error_code;
  UNREFERENCED_PARAMETER (exclusiveLock);
}

static int WinpthreadsErrorCheckRobustMutexUnlock (WinpthreadsMutex *wMutex) {
  WinpthreadsErrorCheckRobustMutex *mutex = &wMutex->ErrorCheckRobustMutex;

  DWORD threadId = GetCurrentThreadId ();

  /**
   * It is possible, though very unlikely, that the previous owner of `mutex`
   * had the same `threadId` and terminated without releasing the mutex.
   */
  if (mutex->Owner != threadId) {
    return EPERM;
  }

  /**
   * Attempt to obtain recursive lock.
   *
   * We do this in order to validate ownership of the `mutex`; in case if
   * previous owner with the same `threadId` terminated without releasing it,
   * we will be notified about it with `EOWNERDEAD` error.
   */
  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, TRUE, NULL);

  switch (error_code) {
    /**
     * We locked the mutex.
     */
    case 0:
      ReleaseMutex (mutex->Mutex);

      /**
       * Check if lock is recursive.
       *
       * This may occur if previous owner of the mutex with the same `threadId`
       * abandoned it, and then another thread locked and unlocked it.
       */
      if (unlikely (mutex->Owner != threadId)) {
        return EPERM;
      }

      break;
    /**
     * Recursive lock count has been exceeded; we own the mutex.
     */
    case EAGAIN:
      break;
    /**
     * An unlikely case when previous thread with the same `threadId`
     * terminated while owning the mutex.
     *
     * Set `mutex->State` to `OwnerDied` and release the mutex.
     * The next thread to gain ownership of the mutex will return `EOWNERDEAD`.
     */
    case EOWNERDEAD:
      mutex->Owner = THREAD_ID_NO_OWNER;
      mutex->State = OwnerDied;
      ReleaseMutex (mutex->Mutex);
      return EPERM;
    /**
     * Some other thread owns the mutex.
     *
     * This may occur if previous owner of the mutex with the same `threadId`
     * abandoned it, and then another thread locked it just before us.
     */
    case EBUSY:
    /**
     * This may occur if previous owner of the mutex with the same `threadId`
     * abandoned it, then another thread locked and unlocked it without
     * calling `pthread_mutex_consistent`.
     */
    case ENOTRECOVERABLE:
      return EPERM;
    default:
      return error_code;
  }

  mutex->Owner = THREAD_ID_NO_OWNER;

  /**
   * Set `mutex->State` to `Unrecoverable`, which will signal unblocked threads
   * that state protected by the mutex is unrecoverable.
   */
  if (mutex->State == Inconsistent) {
    mutex->State = Unrecoverable;
  }

  if (!ReleaseMutex (mutex->Mutex)) {
    return EINVAL;
  }

  return 0;
}

static int WinpthreadsErrorCheckRobustMutexSetConsistentState (WinpthreadsMutex *wMutex) {
  WinpthreadsErrorCheckRobustMutex *mutex = &wMutex->ErrorCheckRobustMutex;

  /**
   * The pthread_mutex_consistent() function shall fail if:
   *
   * [EINVAL]
   *   The mutex object referenced by mutex is not robust or does not protect
   *   an inconsistent state.
   */
  if (mutex->State != Inconsistent) {
    return EINVAL;
  }

  mutex->State = Consistent;
  return 0;
}

static const WinpthreadsMutexVtable WinpthreadsErrorCheckRobustMutexVtable = {
  .Init               = WinpthreadsErrorCheckRobustMutexInit,
  .Destroy            = WinpthreadsErrorCheckRobustMutexDestroy,
  .Lock               = WinpthreadsErrorCheckRobustMutexLock,
  .TryLock            = WinpthreadsErrorCheckRobustMutexTryLock,
  .Unlock             = WinpthreadsErrorCheckRobustMutexUnlock,
  .SetConsistentState = WinpthreadsErrorCheckRobustMutexSetConsistentState,
};

/*******************************************************************************
 * Recursive (PTHREAD_MUTEX_RECURSIVE) Robust (PTHREAD_MUTEX_ROBUST)
 * Mutex implementation.
 *
 * Recursive Robust Mutexes have the following properties:
 *
 * - Attempt to relock a mutex that is already owned by the calling thread
 *   succeeds and increases recursive lock count.
 * - Attempt to unlock a mutex that is not owned by the calling thread fails
 *   with EPERM.
 * - Attempt to unlock an unlocked mutex fails with EPERM.
 */

static int WinpthreadsRecursiveRobustMutexInit (WinpthreadsMutex **wMutex, const WinpthreadsMutexAttributes *wMutexAttr) {
  WinpthreadsRecursiveRobustMutex *mutex = malloc (sizeof (WinpthreadsRecursiveRobustMutex));

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [ENOMEM]
   *   Insufficient memory exists to initialize the mutex.
   */
  if (mutex == NULL) {
    return ENOMEM;
  }

  mutex->Mutex = CreateMutexW (NULL, FALSE, NULL);

  /**
   * The pthread_mutex_init() function shall fail if:
   *
   * [EAGAIN]
   *   The system lacked the necessary resources (other than memory) to
   *   initialize another mutex.
   */
  if (mutex->Mutex == NULL) {
    free (mutex);
    return EAGAIN;
  }

  mutex->State     = Consistent;
  mutex->Owner     = THREAD_ID_NO_OWNER;
  mutex->LockCount = 0;

  *wMutex = (WinpthreadsMutex *) mutex;

  return 0;
  UNREFERENCED_PARAMETER (wMutexAttr);
}

static void WinpthreadsRecursiveRobustMutexDestroy (WinpthreadsMutex *wMutex) {
  WinpthreadsRecursiveRobustMutex *mutex = &wMutex->RecursiveRobustMutex;
  HANDLE mutexHandle = InterlockedExchangePointer ((void **) &mutex->Mutex, NULL);

  if (mutexHandle != NULL) {
    CloseHandle (mutexHandle);
  }

  free (mutex);
}

static int WinpthreadsRecursiveRobustMutexLock (WinpthreadsMutex *wMutex, const struct _timespec64 *waitUntil) {
  WinpthreadsRecursiveRobustMutex *mutex = &wMutex->RecursiveRobustMutex;

  /**
   * The pthread_mutex_lock() function shall fail if:
   *
   * [ENOTRECOVERABLE]
   *   The state protected by the mutex is not recoverable.
   */
  if (unlikely (mutex->State == Unrecoverable)) {
    return ENOTRECOVERABLE;
  }

  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, FALSE, waitUntil);

  if (error_code == 0 || error_code == EOWNERDEAD) {
    DWORD threadId = GetCurrentThreadId ();

    if (unlikely (error_code == EOWNERDEAD)) {
      mutex->Owner     = threadId;
      mutex->LockCount = 1;
      return EOWNERDEAD;
    }

    if (unlikely (mutex->State == OwnerDied)) {
      mutex->State     = Inconsistent;
      mutex->Owner     = threadId;
      mutex->LockCount = 1;
      return EOWNERDEAD;
    }

    if (mutex->LockCount == 0) {
      mutex->Owner = threadId;
    } else {
      if (unlikely (mutex->LockCount == UINT_MAX)) {
        ReleaseMutex (mutex->Mutex);
        return EAGAIN;
      }
    }

    mutex->LockCount++;
  }

  return error_code;
}

static int WinpthreadsRecursiveRobustMutexTryLock (WinpthreadsMutex *wMutex, BOOL exclusiveLock) {
  WinpthreadsRecursiveRobustMutex *mutex = &wMutex->RecursiveRobustMutex;

  /**
   * The pthread_mutex_trylock() function shall fail if:
   *
   * [ENOTRECOVERABLE]
   *   The state protected by the mutex is not recoverable.
   */
  if (unlikely (mutex->State == Unrecoverable)) {
    return ENOTRECOVERABLE;
  }

  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, TRUE, NULL);

  if (error_code == 0 || error_code == EOWNERDEAD) {
    DWORD threadId = GetCurrentThreadId ();

    if (unlikely (error_code == EOWNERDEAD)) {
      mutex->Owner     = threadId;
      mutex->LockCount = 1;
      return EOWNERDEAD;
    }

    if (unlikely (mutex->State == OwnerDied)) {
      mutex->State     = Inconsistent;
      mutex->Owner     = threadId;
      mutex->LockCount = 1;
      return EOWNERDEAD;
    }

    if (mutex->LockCount == 0) {
      mutex->Owner = threadId;
    } else {
      if (unlikely (exclusiveLock)) {
        ReleaseMutex (mutex->Mutex);
        return EBUSY;
      }

      if (unlikely (mutex->LockCount == UINT_MAX)) {
        ReleaseMutex (mutex->Mutex);
        return EAGAIN;
      }
    }

    mutex->LockCount++;
  }

  return error_code;
}

static int WinpthreadsRecursiveRobustMutexUnlock (WinpthreadsMutex *wMutex) {
  WinpthreadsRecursiveRobustMutex *mutex = &wMutex->RecursiveRobustMutex;

  DWORD threadId = GetCurrentThreadId ();

  /**
   * It is possible, though very unlikely, that the previous owner of `mutex`
   * had the same `threadId` and terminated without releasing the mutex.
   */
  if (mutex->Owner != threadId) {
    return EPERM;
  }

  /**
   * Attempt to obtain recursive lock.
   *
   * We do this in order to validate ownership of the `mutex`; in case if
   * previous owner with the same `threadId` terminated without releasing it,
   * we will be notified about it with `EOWNERDEAD` error.
   */
  int error_code = WinpthreadsRobustMutexTimedLock (mutex->Mutex, &mutex->State, TRUE, NULL);

  switch (error_code) {
    /**
     * We locked the mutex.
     */
    case 0:
      ReleaseMutex (mutex->Mutex);

      /**
       * Check if lock is recursive.
       *
       * This may occur if previous owner of the mutex with the same `threadId`
       * abandoned it, and then another thread locked and unlocked it.
       */
      if (unlikely (mutex->Owner != threadId)) {
        return EPERM;
      }

      break;
    /**
     * Recursive lock count has been exceeded; we own the mutex.
     */
    case EAGAIN:
      break;
    /**
     * An unlikely case when previous thread with the same `threadId`
     * terminated while owning the mutex.
     *
     * Set `mutex->State` to `OwnerDied` and release the mutex.
     * The next thread to gain ownership of the mutex will return `EOWNERDEAD`.
     */
    case EOWNERDEAD:
      mutex->Owner = THREAD_ID_NO_OWNER;
      mutex->State = OwnerDied;
      ReleaseMutex (mutex->Mutex);
      return EPERM;
    /**
     * Some other thread owns the mutex.
     *
     * This may occur if previous owner of the mutex with the same `threadId`
     * abandoned it, and then another thread locked it just before us.
     */
    case EBUSY:
    /**
     * This may occur if previous owner of the mutex with the same `threadId`
     * abandoned it, then another thread locked and unlocked it without
     * calling `pthread_mutex_consistent`.
     */
    case ENOTRECOVERABLE:
      return EPERM;
    default:
      return error_code;
  }

  mutex->LockCount--;

  /**
   * When a mutex protecting an inconsistent state is unlocked without prior
   * call to `pthread_mutex_consistent`, the state protected by the mutex
   * must be marked as unrecoverable.
   *
   * POSIX, however, does specify behavior when the mutex protecting an
   * inconsistent state is locked recursively.
   *
   * For recursive mutexes, we treat "unlocking" as releasing ownership
   * of the mutex. This means that state will be marked as unrecoverable only
   * when the owning thread releases ownership of the mutex.
   */
  if (mutex->LockCount > 0) {
    ReleaseMutex (mutex->Mutex);
    return 0;
  }

  mutex->Owner = THREAD_ID_NO_OWNER;

  /**
   * Set `mutex->State` to `Unrecoverable`, which will signal released threads
   * that state protected by the mutex is unrecoverable.
   */
  if (mutex->State == Inconsistent) {
    mutex->State = Unrecoverable;
  }

  if (!ReleaseMutex (mutex->Mutex)) {
    return EPERM;
  }

  return 0;
}

static int WinpthreadsRecursiveRobustMutexSetConsistentState (WinpthreadsMutex *wMutex) {
  WinpthreadsRecursiveRobustMutex *mutex = &wMutex->RecursiveRobustMutex;

  /**
   * The pthread_mutex_consistent() function shall fail if:
   *
   * [EINVAL]
   *   The mutex object referenced by mutex is not robust or does not protect
   *   an inconsistent state.
   */
  if (mutex->State != Inconsistent) {
    return EINVAL;
  }

  mutex->State = Consistent;
  return 0;
}

static const WinpthreadsMutexVtable WinpthreadsRecursiveRobustMutexVtable = {
  .Init               = WinpthreadsRecursiveRobustMutexInit,
  .Destroy            = WinpthreadsRecursiveRobustMutexDestroy,
  .Lock               = WinpthreadsRecursiveRobustMutexLock,
  .TryLock            = WinpthreadsRecursiveRobustMutexTryLock,
  .Unlock             = WinpthreadsRecursiveRobustMutexUnlock,
  .SetConsistentState = WinpthreadsRecursiveRobustMutexSetConsistentState,
};

/*******************************************************************************
 * Implementation for public `pthread_mutexattr_*` functions.
 */

int pthread_mutexattr_init(pthread_mutexattr_t *a)
{
  *a = WINPTHREADS_MUTEX_ATTRIBUTES_DEFAULT.Value;
  return 0;
}

int pthread_mutexattr_destroy(pthread_mutexattr_t *a)
{
  if (a == NULL) {
    return EINVAL;
  }

  memset (a, 0, sizeof (pthread_mutexattr_t));
  return 0;
}

int pthread_mutexattr_settype(pthread_mutexattr_t *a, int value)
{
  if (a == NULL) {
    return EINVAL;
  }

  WinpthreadsMutexAttributes *wMutexAttr = (WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (value) {
    case PTHREAD_MUTEX_NORMAL:
    case PTHREAD_MUTEX_ERRORCHECK:
    case PTHREAD_MUTEX_RECURSIVE:
      wMutexAttr->Attributes.Type = value;
      return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_gettype(const pthread_mutexattr_t *a, int *value)
{
  if (a == NULL || value == NULL) {
    return EINVAL;
  }

  const WinpthreadsMutexAttributes *wMutexAttr = (const WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (wMutexAttr->Attributes.Type) {
    case PTHREAD_MUTEX_NORMAL:
    case PTHREAD_MUTEX_ERRORCHECK:
    case PTHREAD_MUTEX_RECURSIVE:
      *value = wMutexAttr->Attributes.Type;
      return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_setpshared(pthread_mutexattr_t *a, int value)
{
  if (a == NULL) {
    return EINVAL;
  }

  WinpthreadsMutexAttributes *wMutexAttr = (WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (value) {
    case PTHREAD_PROCESS_PRIVATE:
    case PTHREAD_PROCESS_SHARED:
      wMutexAttr->Attributes.Shared = value;
      return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_getpshared(const pthread_mutexattr_t *a, int *value)
{
  if (a == NULL || value == NULL) {
    return EINVAL;
  }

  const WinpthreadsMutexAttributes *wMutexAttr = (const WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  *value = !!wMutexAttr->Attributes.Shared;
  return 0;
}

int pthread_mutexattr_setprotocol(pthread_mutexattr_t *a, int value)
{
  if (a == NULL) {
    return EINVAL;
  }

  WinpthreadsMutexAttributes *wMutexAttr = (WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (value) {
    case PTHREAD_PRIO_NONE:
      wMutexAttr->Attributes.Protocol = value;
      return 0;
    /**
     * POSIX realtime extensions are not implemented.
     *
     * The pthread_mutexattr_setprotocol() function shall fail if:
     *
     * [ENOTSUP]
     *   The value specified by protocol is an unsupported value.
     */
    case PTHREAD_PRIO_INHERIT:
    case PTHREAD_PRIO_PROTECT:
      return ENOTSUP;
  }

  return EINVAL;
}

int pthread_mutexattr_getprotocol(const pthread_mutexattr_t *a, int *value)
{
  if (a == NULL || value == NULL) {
    return EINVAL;
  }

  const WinpthreadsMutexAttributes *wMutexAttr = (const WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (wMutexAttr->Attributes.Protocol) {
    case PTHREAD_PRIO_NONE:
    case PTHREAD_PRIO_INHERIT:
    case PTHREAD_PRIO_PROTECT:
      *value = wMutexAttr->Attributes.Protocol;
      return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_setprioceiling(pthread_mutexattr_t *a, int value)
{
  if (a == NULL) {
    return EINVAL;
  }

  WinpthreadsMutexAttributes *wMutexAttr = (WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  if (value >= THREAD_PRIORITY_IDLE && value <= THREAD_PRIORITY_TIME_CRITICAL) {
    wMutexAttr->Attributes.PriorityCeiling = value;
    return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_getprioceiling(const pthread_mutexattr_t *a, int *value)
{
  if (a == NULL || value == NULL) {
    return EINVAL;
  }

  const WinpthreadsMutexAttributes *wMutexAttr = (const WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  int priorityCeiling = wMutexAttr->Attributes.PriorityCeiling;

  if (priorityCeiling >= THREAD_PRIORITY_IDLE && priorityCeiling <= THREAD_PRIORITY_TIME_CRITICAL) {
    *value = priorityCeiling;
    return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_setrobust(pthread_mutexattr_t *a, int value)
{
  if (a == NULL) {
    return EINVAL;
  }

  WinpthreadsMutexAttributes *wMutexAttr = (WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  switch (value) {
    case PTHREAD_MUTEX_STALLED:
    case PTHREAD_MUTEX_ROBUST:
      wMutexAttr->Attributes.Robust = value;
      return 0;
  }

  return EINVAL;
}

int pthread_mutexattr_getrobust(const pthread_mutexattr_t *a, int *value)
{
  if (a == NULL || value == NULL) {
    return EINVAL;
  }

  const WinpthreadsMutexAttributes *wMutexAttr = (const WinpthreadsMutexAttributes *) a;

  if (wMutexAttr->Attributes.Magic != WINPTHREADS_MUTEX_ATTRIBUTES_MAGIC) {
    return EINVAL;
  }

  *value = !!wMutexAttr->Attributes.Robust;
  return 0;
}

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
    WinpthreadsMutexAttributes wMutexAttr = WINPTHREADS_MUTEX_ATTRIBUTES_DEFAULT;
    WinpthreadsMutex *volatile initializer = *wMutex;

    switch ((pthread_mutex_t)initializer) {
      case PTHREAD_NORMAL_MUTEX_INITIALIZER:
        wMutexAttr.Attributes.Type = PTHREAD_MUTEX_NORMAL;
        break;
      case PTHREAD_ERRORCHECK_MUTEX_INITIALIZER:
        wMutexAttr.Attributes.Type = PTHREAD_MUTEX_ERRORCHECK;
        break;
      case PTHREAD_RECURSIVE_MUTEX_INITIALIZER:
        wMutexAttr.Attributes.Type = PTHREAD_MUTEX_RECURSIVE;
        break;
      default:
        UNREACHABLE ();
    }

    int error_code = pthread_mutex_init ((pthread_mutex_t *)wMutex, &wMutexAttr.Value);

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

int pthread_mutex_init(pthread_mutex_t *m, const pthread_mutexattr_t *a)
{
  WinpthreadsMutexAttributes wMutexAttr = WINPTHREADS_MUTEX_ATTRIBUTES_DEFAULT;

  if (a != NULL) {
    int value;

    wMutexAttr.Value = *a;

    /**
     * POSIX:
     *
     * If an implementation detects that the value specified by the attr
     * argument to pthread_mutex_init() does not refer to an initialized mutex
     * attributes object, it is recommended that the function should fail and
     * report an [EINVAL] error.
     */
    if (pthread_mutexattr_gettype (&wMutexAttr.Value, &value) != 0) {
      return EINVAL;
    }

    if (pthread_mutexattr_getpshared (&wMutexAttr.Value, &value) != 0) {
      return EINVAL;
    }

    if (pthread_mutexattr_getrobust (&wMutexAttr.Value, &value) != 0) {
      return EINVAL;
    }

    if (pthread_mutexattr_getprotocol (&wMutexAttr.Value, &value) != 0) {
      return EINVAL;
    }

    if (pthread_mutexattr_getprioceiling (&wMutexAttr.Value, &value) != 0) {
      return EINVAL;
    }

    if (wMutexAttr.Attributes.Shared) {
      return ENOSYS;
    }
  }

  const WinpthreadsMutexVtable *wMutexVtable = NULL;

  switch (wMutexAttr.Attributes.Type) {
    case PTHREAD_MUTEX_NORMAL:
      if (wMutexAttr.Attributes.Robust) {
        wMutexVtable = &WinpthreadsErrorCheckRobustMutexVtable;
      } else {
        wMutexVtable = &WinpthreadsNormalMutexVtable;
      }
      break;
    case PTHREAD_MUTEX_ERRORCHECK:
      if (wMutexAttr.Attributes.Robust) {
        wMutexVtable = &WinpthreadsErrorCheckRobustMutexVtable;
      } else {
        wMutexVtable = &WinpthreadsErrorCheckMutexVtable;
      }
      break;
    case PTHREAD_MUTEX_RECURSIVE:
      if (wMutexAttr.Attributes.Robust) {
        wMutexVtable = &WinpthreadsRecursiveRobustMutexVtable;
      } else {
        wMutexVtable = &WinpthreadsRecursiveMutexVtable;
      }
      break;
    default:
      UNREACHABLE ();
  }

  WinpthreadsMutex *wMutex = NULL;

  int error_code = wMutexVtable->Init (&wMutex, &wMutexAttr);

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

  switch (error_code) {
    case EOWNERDEAD:
    case ENOTRECOVERABLE:
    case 0:
      break;
    default:
      return error_code;
  }

  InterlockedExchangePointer ((void **)m, NULL);
  wMutex->Base.Vtable->Destroy (wMutex);

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

int pthread_mutex_trylock(pthread_mutex_t *m)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  return wMutex->Base.Vtable->TryLock (wMutex, FALSE);
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
     * `wMutex` is a robust mutex and its previous owner terminated without
     * releasing it; the calling thread owns the mutex now, but state it
     * protects is marked as inconsistent.
     */
    case EOWNERDEAD:
    /**
     * `wMutex` is a robust mutex and state it protects was marked as
     * unrecoverable.
     */
    case ENOTRECOVERABLE:
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

int pthread_mutex_consistent(pthread_mutex_t *m)
{
  WinpthreadsMutex *wMutex = NULL;

  int error_code = WinpthreadsMutexGet (m, &wMutex);

  if (error_code) {
    return error_code;
  }

  return wMutex->Base.Vtable->SetConsistentState (wMutex);
}
