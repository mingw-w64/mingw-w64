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
 * This test is equivalent to `normal-basic.c`, except it uses statically
 * initialized `pthread_mutex_t` object.
 */

int main(void)
{
  pthread_mutex_t mutex = PTHREAD_NORMAL_MUTEX_INITIALIZER;

  assert(pthread_mutex_lock(&mutex) == 0);
  assert(pthread_mutex_trylock(&mutex) == EBUSY);
  assert(pthread_mutex_destroy(&mutex) == EBUSY);
  assert(pthread_mutex_unlock(&mutex) == 0);
  /**
   * POSIX states that calling `pthread_mutex_unlock` on NORMAL mutex that is
   * not owned by the calling thread is undefined behavior.
   *
   * Our implementation for NORMAL mutexes does not check ownership at all,
   * so call to `pthread_mutex_unlock` on a valid NORMAL mutex always succeeds.
   */
  assert(pthread_mutex_unlock(&mutex) == 0);
  assert(pthread_mutex_destroy(&mutex) == 0);
  assert(mutex == (pthread_mutex_t)0);
  assert(pthread_mutex_lock(&mutex) == EINVAL);

  return 0;
}
