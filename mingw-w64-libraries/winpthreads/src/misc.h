/*
   Copyright (c) 2011-2016, 2026 mingw-w64 project

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

#ifndef WIN_PTHREADS_MISC_H
#define WIN_PTHREADS_MISC_H

#if defined(__GNUC__) || defined(__clang__)
#define likely(cond)   __builtin_expect ((cond) != 0, 1)
#define unlikely(cond) __builtin_expect ((cond) != 0, 0)
#else
#define likely(cond)   (cond)
#define unlikely(cond) (cond)
#endif

#if defined(__GNUC__) || defined(__clang__)
#define UNREACHABLE() __builtin_unreachable ()
#elif defined(_MSC_VER)
#define UNREACHABLE() __assume (0)
#endif

/**
 * Address of `GetHandleInformation` if available; otherwise, set to `NULL`.
 */
extern BOOL (WINAPI *_pthread_get_handle_information) (HANDLE, LPDWORD);

/**
 * Address of `SetThreadDescription` if available; otherwise, set to `NULL`.
 */
extern HRESULT (WINAPI *_pthread_set_thread_description) (HANDLE, PCWSTR);

/**
 * For gcc and clang define DUMMY_WRITABLE_DWORD as C99 compound literal.
 * For other pre-C99 compilers declare DUMMY_WRITABLE_DWORD as static variable.
 */
#if defined(__GNUC__) || defined(__clang__)
#define DUMMY_WRITABLE_DWORD (DWORD) {0}
#else
static DWORD DUMMY_WRITABLE_DWORD;
#endif

#define TEST_HANDLE(h)                                                  \
  (((h) != NULL && (h) != INVALID_HANDLE_VALUE) && (                    \
     _pthread_get_handle_information == NULL ||                         \
     _pthread_get_handle_information ((h), &DUMMY_WRITABLE_DWORD) ||     \
     GetLastError () == ERROR_CALL_NOT_IMPLEMENTED                       \
  ))

/**
 * A wrapper around `WaitForSingleObject` that ensures that
 * the wait function does not time out before the time actually runs out.
 *
 * This is needed because `WaitForSingleObject` might have poor accuracy,
 * returning earlier than expected. On the other hand, returning a bit *later*
 * than expected is acceptable in a preemptive multitasking environment.
 */
unsigned long _pthread_wait_for_single_object (void *handle, unsigned long timeout);

/**
 * A wrapper around `WaitForMultipleObjects` that ensures that
 * the wait function does not time out before the time actually runs out.
 *
 * This is needed because `WaitForMultipleObjects` might have poor accuracy,
 * returning earlier than expected. On the other hand, returning a bit *later*
 * than expected is acceptable in a preemptive multitasking environment.
 */
unsigned long _pthread_wait_for_multiple_objects (unsigned long count, void **handles, unsigned int all, unsigned long timeout);

#endif
