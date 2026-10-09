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
 * Call `clock_getres` with all supported `clockid_t` values.
 */

#define POW10_6 1000000
#define POW10_9 1000000000

/**
 * Get number of intervals `r` that occured between `t1` and `t2`.
 */
static double sub_and_div(const struct timespec *t1, const struct timespec *t2, const struct timespec *r)
{
  __int64 diff = (t2->tv_sec - t1->tv_sec) * POW10_9 + (t2->tv_nsec - t1->tv_nsec);
  return diff / (double) (r->tv_sec * POW10_9 + r->tv_nsec);
}

static void test_clock_getres(const char *name, int id)
{
  struct timespec res;
  struct timespec ts1;
  struct timespec ts2;
  struct timespec request;
  double intervals;

  assert(clock_getres(id, &res) == 0);
  /**
   * If `res` is greater than or equal to 1ms, sleep to allign clock with `res`.
   */
  if (res.tv_nsec / POW10_6 > 0) {
    request.tv_sec  = 0;
    request.tv_nsec = res.tv_nsec;
    assert(clock_nanosleep(CLOCK_REALTIME, 0, &request, NULL) == 0);
  }
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
    request.tv_nsec = res.tv_nsec * 2;
    assert(clock_nanosleep(CLOCK_REALTIME, 0, &request, NULL) == 0);
    assert(clock_gettime(id, &ts2) == 0);
  }
  intervals = sub_and_div(&ts1, &ts2, &res);

  wprintf(L"%hs resolution: %.0f.%09ld sec\n", name, (double) res.tv_sec, res.tv_nsec);
  wprintf(L"%hs time: %.0f.%09ld sec\n", name, (double) ts1.tv_sec, ts1.tv_nsec);
  wprintf(L"%hs time: %.0f.%09ld sec\n", name, (double) ts2.tv_sec, ts2.tv_nsec);
  wprintf(L"%hs intervals: %.3lf\n", name, intervals);
}

int main(void)
{
  test_clock_getres("          CLOCK_REALTIME", CLOCK_REALTIME);
  test_clock_getres("         CLOCK_MONOTONIC", CLOCK_MONOTONIC);
  test_clock_getres("CLOCK_PROCESS_CPUTIME_ID", CLOCK_PROCESS_CPUTIME_ID);
  test_clock_getres(" CLOCK_THREAD_CPUTIME_ID", CLOCK_THREAD_CPUTIME_ID);

  return 0;
}
