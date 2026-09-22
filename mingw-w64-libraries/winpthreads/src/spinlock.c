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

#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/* public header files */
#include "pthread.h"
/* internal header files */
#include "misc.h"

/**
 * Reference:
 *
 * pthread_spin_init(), pthread_spin_destroy():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_spin_destroy.html>
 *
 * pthread_spin_lock(), pthread_spin_trylock():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_spin_lock.html>
 *
 * pthread_spin_unlock():
 *  <https://pubs.opengroup.org/onlinepubs/9799919799.2024edition/functions/pthread_spin_unlock.html>
 */

/**
 * Spinlock lock state.
 */
typedef enum {
  /**
   * Spinlock is unlocked.
   */
  Unlocked,
  /**
   * Spinlock is locked.
   *
   * This state inicates that there are no blocked threads waiting for
   * the spinlock to be released.
   *
   * While in this state, if any thread blocks waiting for the spinlock to be
   * released, the lock state will change to `LockedWithBlocking`.
   */
  Locked,
  /**
   * Spinlock is locked.
   *
   * This state indicates that there can be one or more blocked threads
   * waiting for the spinlock to be released.
   */
  LockedWithBlocking,
} WinpthreadsSpinlockLockState;

/**
 * Internal structure pointed to by `pthread_spinlock_t` objects.
 */
typedef struct {
  /**
   * One of `WinpthreadsSpinlockLockState` values.
   */
  LONG State;
  /**
   * This value is used to indicate that spin lock has no owner.
   */
#define THREAD_ID_NO_OWNER ((DWORD)-1)
  /**
   * ID of the thread which holds the lock.
   */
  DWORD ThreadId;
  /**
   * Auto-reset event.
   *
   * When a thread releases the spinlock and `State` is `LockedWithBlocking`,
   * this event will be signaled in order to release one blocked thread.
   */
  HANDLE Event;
} WinpthreadsSpinlock;

#define WINPTHREADS_SPINLOCK_INITIALIZER ((WinpthreadsSpinlock *) PTHREAD_SPINLOCK_INITIALIZER)

/**
 * Obtain pointer to `WinpthreadsSpinlock` structure pointed to by `lock`.
 *
 * If `lock` points to statically initialized `pthread_spinlock_t` object,
 * allocate `WinpthreadsSpinlock` structure and store its address in `*lock`.
 *
 * On success, stores pointer to `WinpthreadsSpinlock` structure in `*spinlock`.
 *
 * Returns zero on success and an error-code on failure.
 */
static WINPTHREADS_INLINE int WinpthreadsSpinlockGet (pthread_spinlock_t *lock, WinpthreadsSpinlock **spinlock)
{
  WinpthreadsSpinlock **pSpinlock = (WinpthreadsSpinlock **) lock;

  /**
   * POSIX:
   *
   * If an implementation detects that the value specified by the lock argument
   * to pthread_spin_*() does not refer to an initialized spin lock object,
   * it is recommended that the function should fail and report an [EINVAL] error.
   */
  if (unlikely (pSpinlock == NULL)) {
    return EINVAL;
  }

  if (*pSpinlock == WINPTHREADS_SPINLOCK_INITIALIZER) {
    /**
     * We need to avoid race condition when more than one thread calls
     * `pthread_spin_[try]lock` on statically initialized `pthread_spinlock_t`
     * at the same time.
     *
     * Store newly initialized spinlock in `spinlock`, which points to local
     * variable supplied by the caller, and then store it in `*lock`.
     *
     * If some other thread was faster then us, destroy newly created spinlock
     * and use spinlock pointed to by `lock`.
     */
    int error_code = pthread_spin_init ((pthread_spinlock_t *) spinlock, PTHREAD_PROCESS_PRIVATE);

    if (error_code) {
      return error_code;
    }

    WinpthreadsSpinlock *oldLock = (WinpthreadsSpinlock *) InterlockedCompareExchangePointer (
      (void **) pSpinlock, *spinlock, WINPTHREADS_SPINLOCK_INITIALIZER
    );

    /**
     * Some other thread was faster than us.
     */
    if (unlikely (oldLock != WINPTHREADS_SPINLOCK_INITIALIZER)) {
      pthread_spin_destroy ((pthread_spinlock_t *) spinlock);
      *spinlock = oldLock;
    }
  } else {
    *spinlock = *pSpinlock;
  }

  if (unlikely (*spinlock == NULL)) {
    return EINVAL;
  }

  return 0;
}

int pthread_spin_init (pthread_spinlock_t *lock, int pshared)
{
  WinpthreadsSpinlock **pSpinlock = (WinpthreadsSpinlock **) lock;

  if (unlikely (pSpinlock == NULL)) {
    return EINVAL;
  }

  if (unlikely (pshared != PTHREAD_PROCESS_PRIVATE && pshared != PTHREAD_PROCESS_SHARED)) {
    return EINVAL;
  }

  if (unlikely (pshared == PTHREAD_PROCESS_SHARED)) {
    return ENOSYS;
  }

  WinpthreadsSpinlock *wSpinlock = calloc (1, sizeof (WinpthreadsSpinlock));

  /**
   * The pthread_spin_init() function shall fail if:
   *
   * [ENOMEM]
   *  Insufficient memory exists to initialize the lock.
   */
  if (wSpinlock == NULL) {
    return ENOMEM;
  }

  wSpinlock->State    = Unlocked;
  wSpinlock->ThreadId = THREAD_ID_NO_OWNER;
  wSpinlock->Event    = CreateEventW (NULL, FALSE, FALSE, NULL);

  /**
   * The pthread_spin_init() function shall fail if:
   *
   * [EAGAIN]
   *  The system lacks the necessary resources to initialize another spin lock.
   */
  if (wSpinlock->Event == NULL) {
    free (wSpinlock);
    return EAGAIN;
  }

  *pSpinlock = wSpinlock;

  return 0;
}

int pthread_spin_destroy (pthread_spinlock_t *lock)
{
  WinpthreadsSpinlock **pSpinlock = (WinpthreadsSpinlock **) lock;

  /**
   * POSIX:
   *
   * If an implementation detects that the value specified by the lock argument
   * to pthread_spin_destroy() does not refer to an initialized spin lock object,
   * it is recommended that the function should fail and report an [EINVAL] error.
   */
  if (unlikely (pSpinlock == NULL)) {
    return EINVAL;
  }

  /**
   * If `lock` points to statically initialized `pthread_spinlock_t` object,
   * this will immediately invalidate it, minimizing the window for
   * `pthread_spin_lock` and `pthread_spin_trylock` to attempt using it.
   */
  WinpthreadsSpinlock *wSpinlock = InterlockedCompareExchangePointer (
    (void **) pSpinlock, NULL, WINPTHREADS_SPINLOCK_INITIALIZER
  );

  if (unlikely (wSpinlock == NULL)) {
    return EINVAL;
  }

  if (unlikely (wSpinlock == WINPTHREADS_SPINLOCK_INITIALIZER)) {
    return 0;
  }

  /**
   * POSIX:
   *
   * If an implementation detects that the value specified by the lock argument
   * to pthread_spin_destroy() or pthread_spin_init() refers to a locked spin
   * lock object, or detects that the value specified by the lock argument to
   * pthread_spin_init() refers to an already initialized spin lock object,
   * it is recommended that the function should fail and report an [EBUSY] error.
   */
  if (unlikely (InterlockedCompareExchange (&wSpinlock->State, Locked, Unlocked) != Unlocked)) {
    return EBUSY;
  }

  /**
   * Invalidate `pthread_spinlock_t` object pointed by `lock`.
   */
  InterlockedExchangePointer ((void **) pSpinlock, NULL);

  CloseHandle (wSpinlock->Event);
  free (wSpinlock);

  return 0;
}

int pthread_spin_lock (pthread_spinlock_t *lock)
{
  WinpthreadsSpinlock *wSpinlock = NULL;

  int error_code = WinpthreadsSpinlockGet (lock, &wSpinlock);

  if (error_code) {
    return error_code;
  }

  DWORD threadId = GetCurrentThreadId ();

  /**
   * The pthread_spin_lock() function may fail if:
   *
   * [EDEADLK]
   *  A deadlock condition was detected.
   */
  if (unlikely (wSpinlock->ThreadId == threadId)) {
    return EDEADLK;
  }

  /**
   * Try fast path.
   */
  if (InterlockedCompareExchange (&wSpinlock->State, Locked, Unlocked) == Unlocked) {
    goto locked;
  }

  /**
   * Setting `wSpinlock->State` to `LockedWithBlocking` causes
   * `pthread_spin_unlock` to signal `wSpinlock->Event`.
   */
  LONG oldLockState = InterlockedExchange (&wSpinlock->State, LockedWithBlocking);

  if (likely (oldLockState != Unlocked)) {
    do {
      switch (_pthread_wait_for_single_object (wSpinlock->Event, INFINITE)) {
        /**
         * `wSpinlock->Event` was signaled.
         *
         * There is a small chance that another thread grabs the lock faster
         * than we do; lock state is updated before wait handle is signaled.
         */
        case WAIT_OBJECT_0:
          break;
        default:
          return EINVAL;
      }
    } while (unlikely (InterlockedExchange (&wSpinlock->State, LockedWithBlocking) != Unlocked));
  }

locked:
  wSpinlock->ThreadId = threadId;

  return 0;
}

int pthread_spin_trylock (pthread_spinlock_t *lock)
{
  WinpthreadsSpinlock *wSpinlock = NULL;

  int error_code = WinpthreadsSpinlockGet (lock, &wSpinlock);

  if (error_code) {
    return error_code;
  }

  /**
   * The pthread_spin_trylock() function shall fail if:
   *
   * [EBUSY]
   *  A thread currently holds the lock.
   */
  if (InterlockedCompareExchange (&wSpinlock->State, Locked, Unlocked) != Unlocked) {
    return EBUSY;
  }

  wSpinlock->ThreadId = GetCurrentThreadId ();

  return 0;
}

int pthread_spin_unlock (pthread_spinlock_t *lock)
{
  WinpthreadsSpinlock *wSpinlock = NULL;

  int error_code = WinpthreadsSpinlockGet (lock, &wSpinlock);

  if (error_code) {
    return error_code;
  }

  DWORD threadId = GetCurrentThreadId ();

  /**
   * POSIX:
   *
   * If an implementation detects that the value specified by the lock argument
   * to pthread_spin_unlock() refers to a spin lock object for which the
   * current thread does not hold the lock, it is recommended that the function
   * should fail and report an [EPERM] error.
   */
  if (unlikely (wSpinlock->ThreadId != threadId)) {
    return EPERM;
  }

  wSpinlock->ThreadId = THREAD_ID_NO_OWNER;

  /**
   * If `wSpinlock->State` is `LockedWithBlocking`, then some other thread is
   * waiting for `wSpinlock->Event` to become signaled.
   */
  if (InterlockedExchange (&wSpinlock->State, Unlocked) == LockedWithBlocking) {
    if (!SetEvent (wSpinlock->Event)) {
      return EINVAL;
    }
  }

  return 0;
}
