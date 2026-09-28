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
 * Create robust error checking mutex and test basic assumptions about mutex
 * ownership and lifetime.
 */

int main (void)
{
  pthread_mutexattr_t mutexAttr;
  pthread_mutex_t mutex;

  assert (pthread_mutexattr_init (&mutexAttr) == 0);
  assert (pthread_mutexattr_settype (&mutexAttr, PTHREAD_MUTEX_ERRORCHECK) == 0);
  assert (pthread_mutexattr_setrobust (&mutexAttr, PTHREAD_MUTEX_ROBUST) == 0);
  assert (pthread_mutex_init (&mutex, &mutexAttr) == 0);
  assert (mutex != (pthread_mutex_t) 0);
  assert (pthread_mutex_lock (&mutex) == 0);
  assert (pthread_mutex_lock (&mutex) == EDEADLK);
  assert (pthread_mutex_trylock (&mutex) == EBUSY);
  assert (pthread_mutex_destroy (&mutex) == EBUSY);
  assert (pthread_mutex_consistent (&mutex) == EINVAL);
  assert (pthread_mutex_unlock (&mutex) == 0);
  assert (pthread_mutex_unlock (&mutex) == EPERM);
  assert (pthread_mutex_destroy (&mutex) == 0);
  assert (mutex == (pthread_mutex_t) 0);
  assert (pthread_mutex_lock (&mutex) == EINVAL);
  assert (pthread_mutexattr_destroy (&mutexAttr) == 0);

  return 0;
}
