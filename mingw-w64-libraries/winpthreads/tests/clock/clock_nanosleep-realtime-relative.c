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
 * Test `clock_nanosleep` with `CLOCK_REALTIME`.
 *
 * Use zero for the `flags` argument; `clock_nanosleep` must sleep
 * for duration specified by the `request` argument.
 */

#define POW10_6 1000000
#define POW10_9 1000000000

int main(void)
{
  struct timespec res;
  struct timespec ts1;
  struct timespec ts2;
  struct timespec request;

  assert(clock_getres(CLOCK_REALTIME, &res) == 0);
  assert(clock_gettime(CLOCK_REALTIME, &ts1) == 0);
  request.tv_sec  = 0;
  request.tv_nsec = res.tv_nsec * (res.tv_nsec / POW10_6 > 0 ? 10 : POW10_6);
  if (request.tv_nsec >= POW10_9) {
    request.tv_sec  += request.tv_nsec / POW10_9;
    request.tv_nsec %= POW10_9;
  }
  assert(clock_nanosleep(CLOCK_REALTIME, 0, &request, NULL) == 0);
  assert(clock_gettime(CLOCK_REALTIME, &ts2) == 0);

  wprintf(L"Time 1: %.0f.%09ld\n", (double) ts1.tv_sec, ts1.tv_nsec);
  wprintf(L"Time 2: %.0f.%09ld\n", (double) ts2.tv_sec, ts2.tv_nsec);

  return 0;
}
