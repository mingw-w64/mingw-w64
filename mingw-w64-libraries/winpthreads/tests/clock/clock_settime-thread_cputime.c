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

#include <assert.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>

/**
 * Test Summary:
 *
 * Test `clock_settime` with `CLOCK_THREAD_CPUTIME_ID`.
 *
 * Calling `clock_settime` with `CLOCK_THREAD_CPUTIME_ID` is not supported;
 * the call must fail with `EINVAL`.
 */

int main(void)
{
  struct timespec ts1;
  struct timespec ts2;
  int error_code;

  errno = 0;
  error_code = clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts1);
  assert(error_code == 0 || (error_code = errno) == ENOTSUP);
  /**
   * `CLOCK_THREAD_CPUTIME_ID` is not supported on Win9x.
   */
  if (error_code == ENOTSUP) {
    wprintf(L"CLOCK_THREAD_CPUTIME_ID is not supported.\n");
    return 77;
  }
  errno = 0;
  error_code = clock_settime(CLOCK_THREAD_CPUTIME_ID, &ts1);
  assert(error_code != 0 && (error_code = errno) == EINVAL);
  assert(clock_gettime(CLOCK_THREAD_CPUTIME_ID, &ts2) == 0);

  if (error_code == 0) {
    wprintf(L"Time 1: %.0f.%09ld\n", (double) ts1.tv_sec, ts1.tv_nsec);
    wprintf(L"Time 2: %.0f.%09ld\n", (double) ts2.tv_sec, ts2.tv_nsec);
  } else {
    wprintf(L"Cannot set time; errno=%d\n", error_code);
  }

  return 0;
}
