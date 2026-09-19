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
 * Test functions `pthread_mutexattr_setprioceiling` and
 * `pthread_mutexattr_getprioceiling`.
 */

static void DoTest (int value, int expectedValue, int expectedReturn1, int expectedReturn2) {
  pthread_mutexattr_t mutexAttr;
  pthread_mutex_t mutex;

  assert (pthread_mutexattr_init (&mutexAttr) == 0);
  assert (pthread_mutexattr_setprioceiling (&mutexAttr, value) == expectedReturn1);
  assert (pthread_mutexattr_getprioceiling (&mutexAttr, &value) == 0);
  assert (value == expectedValue);
  assert (pthread_mutex_init (&mutex, &mutexAttr) == expectedReturn2);
  if (expectedReturn2 == 0) {
    assert (pthread_mutex_destroy (&mutex) == 0);
  }
  assert (pthread_mutexattr_destroy (&mutexAttr) == 0);
}

int main (void) {
  /**
   * Any valid `THREAD_PRIORITY_*` value can be set for prioceiling attribute.
   *
   * Currently, it has no effect; POSIX realtime extensions are not implemented.
   */
  for (int value = THREAD_PRIORITY_IDLE; value <= THREAD_PRIORITY_TIME_CRITICAL; ++value) {
    DoTest (value, value, 0, 0);
  }

  /**
   * Try setting an invalid value; default attribute value must be used.
   */
  DoTest (0xFF, THREAD_PRIORITY_NORMAL, EINVAL, 0);

  return 0;
}
