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
 * A basic test for `nanosleep` function.
 */

#define POW10_3 1000
#define POW10_6 1000000

static __int64 timespec_diff_as_ms(struct timespec *ts1, struct timespec *ts2)
{
  return (ts2->tv_sec - ts1->tv_sec) * POW10_3 + (ts2->tv_nsec - ts1->tv_nsec) / POW10_6;
}

int main(void)
{
  struct timespec ts1;
  struct timespec ts2;
  struct timespec request;
  __int64 diff;

  assert(clock_gettime(CLOCK_REALTIME, &ts1) == 0);
  request.tv_sec  = 0;
  request.tv_nsec = 50 * POW10_6;
  assert(nanosleep(&request, NULL) == 0);
  assert(clock_gettime(CLOCK_REALTIME, &ts2) == 0);

  diff = timespec_diff_as_ms(&ts1, &ts2);
  assert(diff > 0);

  wprintf(L"Sleep start time: %.0f.%09ld\n", (double) ts1.tv_sec, ts1.tv_nsec);
  wprintf(L"Sleep end time: %.0f.%09ld\n", (double) ts2.tv_sec, ts2.tv_nsec);
  wprintf(L"Slept for %.0f ms\n", (double) diff);

  return 0;
}
