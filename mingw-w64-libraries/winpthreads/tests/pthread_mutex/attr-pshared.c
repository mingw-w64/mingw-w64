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
 * Test functions `pthread_mutexattr_setpshared` and
 * `pthread_mutexattr_getpshared`.
 */

static void DoTest (int value, int expectedValue, int expectedReturn1, int expectedReturn2) {
  pthread_mutexattr_t mutexAttr;
  pthread_mutex_t mutex;

  assert (pthread_mutexattr_init (&mutexAttr) == 0);
  assert (pthread_mutexattr_setpshared (&mutexAttr, value) == expectedReturn1);
  assert (pthread_mutexattr_getpshared (&mutexAttr, &value) == 0);
  assert (value == expectedValue);
  assert (pthread_mutex_init (&mutex, &mutexAttr) == expectedReturn2);
  if (expectedReturn2 == 0) {
    assert (pthread_mutex_destroy (&mutex) == 0);
  }
  assert (pthread_mutexattr_destroy (&mutexAttr) == 0);
}

int main (void) {
  /**
   * Currently winpthreads only supports `PTHREAD_PROCESS_PRIVATE`.
   */
  DoTest (PTHREAD_PROCESS_PRIVATE, PTHREAD_PROCESS_PRIVATE, 0, 0);
  DoTest (PTHREAD_PROCESS_SHARED, PTHREAD_PROCESS_SHARED, 0, ENOSYS);

  /**
   * Try setting an invalid value; default attribute value must be used.
   */
  DoTest (0xFF, PTHREAD_PROCESS_PRIVATE, EINVAL, 0);

  return 0;
}
