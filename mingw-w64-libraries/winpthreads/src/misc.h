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
 * A wrapper around `WaitForSingleObject` that ensures that
 * the wait function does not time out before the time actually runs out.
 *
 * This is needed because `WaitForSingleObject` might have poor accuracy,
 * returning earlier than expected. On the other hand, returning a bit *later*
 * than expected is acceptable in a preemptive multitasking environment.
 */
unsigned long winpthreads_wait_for_single_object (void *handle, unsigned long timeout);

/**
 * A wrapper around `WaitForMultipleObjects` that ensures that
 * the wait function does not time out before the time actually runs out.
 *
 * This is needed because `WaitForMultipleObjects` might have poor accuracy,
 * returning earlier than expected. On the other hand, returning a bit *later*
 * than expected is acceptable in a preemptive multitasking environment.
 */
unsigned long winpthreads_wait_for_multiple_objects (unsigned long count, void **handles, unsigned int all, unsigned long timeout);

/**
 * Portability wrapper for `GetHandleInformation`.
 */
int winpthreads_get_handle_information (void *, unsigned *);

/**
 * Portability wrapper for `SetThreadDescription`.
 *
 * Since `SetThreadDescription` expects wide character string for its
 * second argument, this wrapper converts its second argument using
 * active ANSI code page before passing it to `SetThreadDescription`.
 */
int winpthreads_set_thread_description_ansi (void *, const char *);

/**
 * Portability wrapper for `SetThreadDescription`.
 */
int winpthreads_set_thread_description_unicode (void *, const wchar_t *);

/**
 * Validate `handle`.
 *
 * Returns non-zero if `handle` is valid and zero otherwise.
 */
int winpthreads_validate_handle (void *handle);

#endif
