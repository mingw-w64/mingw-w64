/*
   Copyright (c) 2011 mingw-w64 project

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

#include "pthread.h"
#include "windows.h"
#include "misc.h"

unsigned long long _pthread_time_in_ms(void)
{
    FILETIME ft;

    GetSystemTimeAsFileTime(&ft);
    return (((unsigned long long)ft.dwHighDateTime << 32) + ft.dwLowDateTime
            - 0x19DB1DED53E8000ULL) / 10000ULL;
}

unsigned long long _pthread_time_in_ms_from_timespec(const struct timespec *ts)
{
    unsigned long long t = (unsigned long long) ts->tv_sec * 1000LL;
    t += (unsigned long long) (ts->tv_nsec / 1000000);

    return t;
}

unsigned long long _pthread_rel_time_in_ms(const struct timespec *ts)
{
    unsigned long long t1 = _pthread_time_in_ms_from_timespec(ts);
    unsigned long long t2 = _pthread_time_in_ms();

    /* Prevent underflow */
    if (t1 < t2) return 0;
    return t1 - t2;
}

