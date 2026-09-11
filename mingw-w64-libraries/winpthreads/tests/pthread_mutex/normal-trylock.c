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
 * Main thread M creates mutex L with type `PTHREAD_MUTEX_NORMAL` and locks it.
 *
 * Thread A attempts to lock L; since M owns L, call to `pthread_mutex_trylock`
 * must fail with EBUSY.
 *
 * Thread M unlocks and destroys L.
 */

static void *ThreadA(void *arg)
{
  pthread_mutex_t *mutex = arg;
  assert(pthread_mutex_trylock(mutex) == EBUSY);
  return arg;
}

int main(void)
{
  pthread_mutex_t mutex = PTHREAD_NORMAL_MUTEX_INITIALIZER;
  pthread_t thread;
  void *result;

  assert(pthread_mutex_lock(&mutex) == 0);
  assert(pthread_create(&thread, NULL, ThreadA, &mutex) == 0);
  assert(pthread_join(thread, &result) == 0);
  assert(result == &mutex);
  assert(pthread_mutex_unlock(&mutex) == 0);
  assert(pthread_mutex_destroy(&mutex) == 0);

  return 0;
}
