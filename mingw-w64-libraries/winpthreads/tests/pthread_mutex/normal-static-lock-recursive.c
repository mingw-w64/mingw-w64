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
 * Main thread M creates (statically initialized) mutex L with type
 * `PTHREAD_MUTEX_NORMAL`.
 *
 * Thread A locks L.
 *
 * Thread A attempts to lock L again; this must result in a dead lock.
 *
 * Thread M unlocks and destroys L.
 */

static LONG IsThreadABlocked = FALSE;

static void *ThreadA(void *arg)
{
  pthread_mutex_t *mutex = arg;

  assert(pthread_mutex_lock(mutex) == 0);
  /**
   * Signal thread M that thread A locked L.
   */
  InterlockedExchange(&IsThreadABlocked, TRUE);
  /**
   * Attempt to recursively lock NORMAL mutex must result in a dead lock.
   * Wait for main thread to unlock...
   */
  assert(pthread_mutex_lock(mutex) == 0);
  /**
   * Signal thread M that thread A was unblocked.
   */
  InterlockedExchange(&IsThreadABlocked, FALSE);
  assert(pthread_mutex_unlock(mutex) == 0);

  return arg;
}

int main(void)
{
  pthread_mutex_t mutex = PTHREAD_NORMAL_MUTEX_INITIALIZER;
  pthread_t thread;
  void *result;

  assert(pthread_create(&thread, NULL, ThreadA, &mutex) == 0);
  /**
   * Wait until thread A locks L.
   */
  while (!IsThreadABlocked) {
    YieldProcessor();
  }
  Sleep(10);
  /**
   * Thread A must be deadlocked.
   */
  assert(IsThreadABlocked);
  /**
   * POSIX states that calling `pthread_mutex_unlock` on NORMAL mutex that is
   * not owned by the calling thread is undefined behavior.
   *
   * Our implementation for NORMAL mutexes does not check ownership at all,
   * so call to `pthread_mutex_unlock` on a valid NORMAL mutex always succeeds.
   */
  do {
    assert(pthread_mutex_unlock(&mutex) == 0);
    YieldProcessor();
  } while (IsThreadABlocked);
  assert(pthread_join (thread, &result) == 0);
  assert(result == &mutex);
  assert(pthread_mutex_destroy(&mutex) == 0);

  return 0;
}
