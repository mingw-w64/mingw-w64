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

#include "misc.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 * File Summary:
 *
 * This file defines function to deal with process and thread affinity.
 */

int pthread_num_processors_np (void) {
  DWORD_PTR SystemAffinityMask;
  DWORD_PTR ProcessAffinityMask;
  int r = 0;

  if (GetProcessAffinityMask (GetCurrentProcess (), &ProcessAffinityMask, &SystemAffinityMask)) {
    for(; ProcessAffinityMask != 0; ProcessAffinityMask >>= 1) {
      r += (ProcessAffinityMask & 1) != 0;
    }
  }

  /* assume at least 1 */
  return r ? r : 1;
}

int pthread_set_num_processors_np (int n) {
  DWORD_PTR SystemAffinityMask;
  DWORD_PTR ProcessAffinityMask;
  DWORD_PTR ProcessNewAffinityMask = 0;
  int r = 0;

  /* need at least 1 */
  n = n ? n : 1;

  if (GetProcessAffinityMask (GetCurrentProcess (), &ProcessAffinityMask, &SystemAffinityMask)) {
    for (; ProcessAffinityMask != 0; ProcessAffinityMask >>= 1) {
      ProcessNewAffinityMask <<= 1;

      if ((ProcessAffinityMask & 1) != 0 && r < n) {
        ProcessNewAffinityMask |= 1;
        r++;
      }
    }

    SetProcessAffinityMask (GetCurrentProcess (), ProcessNewAffinityMask);
  }

  return r;
}
