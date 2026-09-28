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

#include "test.h"

/**
 * Test Summary:
 *
 * Main thread M creates robust recursive mutex L,
 * then it creates threads A, B and C.
 *
 * A locks L.
 *
 * While A holds L, B enter wait state in order to lock L.
 *
 * While B is blocked waiting for L to be released,
 * A terminates but does not release L.
 *
 * B gains ownership for L and is notified that state protected by L
 * may be inconsistent; call to `pthread_mutex_lock` must return `EOWNERDEAD`.
 *
 * After B locks L, C enters wait state in order to lock L.
 *
 * B recursively locks L.
 *
 * B unlocks L without calling `pthread_mutex_consistent`; the first call to
 * `pthread_mutex_unlock` must simply decrement recursive lock count.
 *
 * B unlocks L without calling `pthread_mutex_consistent`; the second call to
 * `pthread_mutex_unlock` must mark state protected by L as unrecoverable.
 *
 * C fails to gain ownership for L;
 * call to `pthread_mutex_lock` must fail with `ENOTRECOVERABLE`.
 *
 * C attempts to unlock L;
 * call to `pthread_mutex_unlock` must fail with `EPERM`.
 *
 * M waits for A, B and C to return, and then destroys L.
 */

static LONG Started = FALSE;
static LONG Locked  = FALSE;
static LONG Lock    = FALSE;
static LONG Blocked = FALSE;

static void *ThreadA (void *arg) {
  pthread_mutex_t *mutex = arg;

  while (!Started) {
    YieldProcessor ();
  }
  assert (pthread_mutex_lock (mutex) == 0);
  InterlockedExchange (&Locked, TRUE);
  /**
   * Give B time to enter wait state.
   */
  Sleep (10);

  return arg;
}

static void *ThreadB (void *arg) {
  pthread_mutex_t *mutex = arg;

  InterlockedExchange (&Started, TRUE);
  while (!Locked) {
    YieldProcessor ();
  }
  assert (pthread_mutex_lock (mutex) == EOWNERDEAD);
  InterlockedExchange (&Lock, TRUE);
  while (!Blocked) {
    YieldProcessor ();
  }
  /**
   * Give C time to enter wait state.
   */
  Sleep (10);
  assert (pthread_mutex_lock (mutex) == 0);
  assert (pthread_mutex_unlock (mutex) == 0);
  /**
   * C must be blocked.
   */
  Sleep (10);
  assert (Blocked);
  assert (pthread_mutex_unlock (mutex) == 0);

  return arg;
}

static void *ThreadC (void *arg) {
  pthread_mutex_t *mutex = arg;

  while (!Lock) {
    YieldProcessor ();
  }
  InterlockedExchange (&Blocked, TRUE);
  assert (pthread_mutex_lock (mutex) == ENOTRECOVERABLE);
  InterlockedExchange (&Blocked, FALSE);
  assert (pthread_mutex_unlock (mutex) == EPERM);

  return arg;
}

int main (void)
{
  pthread_mutexattr_t mutexAttr;
  pthread_mutex_t mutex;
  pthread_t threadA;
  pthread_t threadB;
  pthread_t threadC;
  void *result;

  assert (pthread_mutexattr_init (&mutexAttr) == 0);
  assert (pthread_mutexattr_settype (&mutexAttr, PTHREAD_MUTEX_RECURSIVE) == 0);
  assert (pthread_mutexattr_setrobust (&mutexAttr, PTHREAD_MUTEX_ROBUST) == 0);
  assert (pthread_mutex_init (&mutex, &mutexAttr) == 0);
  assert (pthread_create (&threadA, NULL, ThreadA, &mutex) == 0);
  assert (pthread_create (&threadB, NULL, ThreadB, &mutex) == 0);
  assert (pthread_create (&threadC, NULL, ThreadC, &mutex) == 0);
  assert (pthread_join (threadA, &result) == 0);
  assert (result == &mutex);
  assert (pthread_join (threadB, &result) == 0);
  assert (result == &mutex);
  assert (pthread_join (threadC, &result) == 0);
  assert (result == &mutex);
  assert (pthread_mutex_destroy (&mutex) == 0);
  assert (pthread_mutexattr_destroy (&mutexAttr) == 0);

  return 0;
}
