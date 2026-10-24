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

#include <sdkddkver.h>

/**
 * Windows NT 3.1
 *
 * Major version: 3
 * Minor version: 10
 */
#define WINPTHREADS_WINNT_NT_3_1  (0x030A)
/**
 * Windows NT 3.5
 *
 * Major version: 3
 * Minor version: 50
 */
#define WINPTHREADS_WINNT_NT_3_5  (0x0332)
/**
 * Windows NT 3.51
 *
 * Major version: 3
 * Minor version: 51
 */
#define WINPTHREADS_WINNT_NT_3_51 (0x0333)
/**
 * Windows NT 4
 *
 * Major version: 4
 * Minor version: 0
 */
#define WINPTHREADS_WINNT_NT_4    _WIN32_WINNT_NT4
/**
 * Windows 2000
 *
 * Major version: 5
 * Minor version: 0
 */
#define WINPTHREADS_WINNT_2000    _WIN32_WINNT_WIN2K
/**
 * Windows XP
 *
 * Major version: 5
 * Minor version: 1
 */
#define WINPTHREADS_WINNT_XP      _WIN32_WINNT_WINXP
/**
 * Windows Vista
 *
 * Major version: 6
 * Minor version: 0
 */
#define WINPTHREADS_WINNT_VISTA   _WIN32_WINNT_VISTA
/**
 * Windows 7
 *
 * Major version: 6
 * Minor version: 1
 */
#define WINPTHREADS_WINNT_WIN7    _WIN32_WINNT_WIN7
/**
 * Windows 8
 *
 * Major version: 6
 * Minor version: 2
 */
#define WINPTHREADS_WINNT_WIN8    _WIN32_WINNT_WIN8
/**
 * Windows 8.1
 *
 * Major version: 6
 * Minor version: 3
 */
#define WINPTHREADS_WINNT_WIN8_1  _WIN32_WINNT_WINBLUE
/**
 * Windows 10
 *
 * Major version: 10
 * Minor version: 0
 */
#define WINPTHREADS_WINNT_WIN10   _WIN32_WINNT_WIN10

/**
 * Define `WINPTHREADS_WINNT` macro.
 *
 * Minimal Windows NT version to be supported by the library.
 */

/**
 * All Windows NT versions support x86.
 * x86 builds can also be configured with Win9x support.
 */
#if defined(_M_IX86)

/**
 * For x86 builds with MSVC, use Windows XP as the minimal version as recent
 * MSVC does not support targeting older Windows versions.
 */
#if defined(_MSC_VER)

#ifndef WINPTHREADS_WINNT
#define WINPTHREADS_WINNT WINPTHREADS_WINNT_XP
#endif

/**
 * For x86 build with mingw-w64, use NT 3.1 as the minimal version and enable
 * Win9x support if not disabled explicitly.
 */
#else /* mingw-w64 */

#ifndef WINPTHREADS_WINNT
#define WINPTHREADS_WINNT WINPTHREADS_WINNT_NT_3_1
#endif

#ifndef WINPTHREADS_WIN9X
#define WINPTHREADS_WIN9X 1
#endif

#endif /* mingw-w64 */

/**
 * Native x64, not arm64ec.
 * Support for x64 is only available since Windows XP.
 */
#elif defined(_M_X64) && !defined(_M_ARM64EC)

#if defined(WINPTHREADS_WINNT) && WINPTHREADS_WINNT < WINPTHREADS_WINNT_XP
#undef WINPTHREADS_WINNT
#endif

#ifndef WINPTHREADS_WINNT
#define WINPTHREADS_WINNT WINPTHREADS_WINNT_XP
#endif

#ifdef WINPTHREADS_WIN9X
#undef WINPTHREADS_WIN9X
#endif

/**
 * Support for arm32 is available since Windows 8.
 */
#elif defined(_M_ARM)

#if defined(WINPTHREADS_WINNT) && WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN8
#undef WINPTHREADS_WINNT
#endif

#ifndef WINPTHREADS_WINNT
#define WINPTHREADS_WINNT WINPTHREADS_WINNT_WIN8
#endif

#ifdef WINPTHREADS_WIN9X
#undef WINPTHREADS_WIN9X
#endif

/**
 * Support for arm64 and arm64ec is available since Windows 10.
 */
#elif defined(_M_ARM64) || defined(_M_ARM64EC)

#if defined(WINPTHREADS_WINNT) && WINPTHREADS_WINNT < WINPTHREADS_WINNT_WIN10
#undef WINPTHREADS_WINNT
#endif

#ifndef WINPTHREADS_WINNT
#define WINPTHREADS_WINNT WINPTHREADS_WINNT_WIN10
#endif

#ifdef WINPTHREADS_WIN9X
#undef WINPTHREADS_WIN9X
#endif

#else  /* unknown arch */
#error Unsupported architecture
#endif /* unknown arch */

/**
 * Whether to include code for Win9x support.
 */
#ifndef WINPTHREADS_WIN9X
#define WINPTHREADS_WIN9X 0
#endif

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
