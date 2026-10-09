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
#include <pthread.h>
#include <stdio.h>
#include <time.h>

/**
 * Test Summary:
 *
 * Call `clock_gettime` with all supported `clockid_t` values.
 */

static void test_clock_gettime(const char *name, clockid_t id)
{
  struct timespec res;
  struct timespec ts1;
  struct timespec ts2;
  struct timespec request;

  assert(clock_getres(id, &res) == 0);
  assert(clock_gettime(id, &ts1) == 0);
  /**
   * `CLOCK_PROCESS_CPUTIME_ID` and `CLOCK_THREAD_CPUTIME_ID`
   * do not include time process/thread spent sleeping.
   */
  if (id == CLOCK_PROCESS_CPUTIME_ID || id == CLOCK_THREAD_CPUTIME_ID) {
    do {
      assert(clock_gettime(id, &ts2) == 0);
    } while (ts1.tv_sec == ts2.tv_sec && ts1.tv_nsec == ts2.tv_nsec);
  } else {
    request.tv_sec  = 0;
    request.tv_nsec = res.tv_nsec;
    assert(clock_nanosleep(CLOCK_REALTIME, 0, &request, NULL) == 0);
    assert(clock_gettime(id, &ts2) == 0);
  }

  wprintf(L"%hs: %.0f.%09ld\n", name, (double) ts1.tv_sec, ts1.tv_nsec);
  wprintf(L"%hs: %.0f.%09ld\n", name, (double) ts2.tv_sec, ts2.tv_nsec);
}

int main(void)
{
  test_clock_gettime("          CLOCK_REALTIME", CLOCK_REALTIME);
  test_clock_gettime("         CLOCK_MONOTONIC", CLOCK_MONOTONIC);
  test_clock_gettime("CLOCK_PROCESS_CPUTIME_ID", CLOCK_PROCESS_CPUTIME_ID);
  test_clock_gettime(" CLOCK_THREAD_CPUTIME_ID", CLOCK_THREAD_CPUTIME_ID);

  return 0;
}
