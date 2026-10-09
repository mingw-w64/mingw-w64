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
 * Test `clock_getres` with `CLOCK_PROCESS_CPUTIME_ID`.
 */

#define POW10_6 1000000
#define POW10_9 1000000000

/**
 * Get number of intervals `r` that occured between `ts1` and `ts2`.
 */
static double sub_and_div(const struct timespec *ts1, const struct timespec *ts2, const struct timespec *r)
{
  __int64 diff = (ts2->tv_sec - ts1->tv_sec) * POW10_9 + (ts2->tv_nsec - ts1->tv_nsec);
  return diff / (double) (r->tv_sec * POW10_9 + r->tv_nsec);
}

int main(void)
{
  struct timespec res;
  struct timespec ts1;
  struct timespec ts2;
  double intervals;

  assert(clock_getres(CLOCK_PROCESS_CPUTIME_ID, &res) == 0);
  assert(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts1) == 0);
  /**
   * `CLOCK_PROCESS_CPUTIME_ID` does not include time process spent sleeping.
   */
  do {
    assert(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2) == 0);
  } while (ts1.tv_sec == ts2.tv_sec && ts1.tv_nsec == ts2.tv_nsec);
  assert(clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts2) == 0);
  intervals = sub_and_div(&ts1, &ts2, &res);

  wprintf(L"Resolution: %.0f.%09ld sec\n", (double) res.tv_sec, res.tv_nsec);
  wprintf(L"Time 1: %.0f.%09ld sec\n", (double) ts1.tv_sec, ts1.tv_nsec);
  wprintf(L"Time 2: %.0f.%09ld sec\n",(double) ts2.tv_sec, ts2.tv_nsec);
  wprintf(L"Intervals: %.3lf\n", intervals);

  return 0;
}
