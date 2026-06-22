/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

/**
 * Convert wide character string `wcs` to code page `cp`.
 *
 * The converted string is written to `buffer` with size `buffer_size`.
 *
 * If `buffer_size` is less than buffer size required to store converted `wcs`,
 * set `truncated` to `true`; in this case, this function will convert as much
 * wide characters in `wcs` as fits into `buffer`.
 */
static void conv (char *buffer, int buffer_size, const wchar_t *wcs, unsigned cp, bool truncated) {
    if (!truncated) {
        /**
         * Calling `WideCharToMultiByte` with zero flags allows best-fit
         * conversion and makes it replace characters which cannot be converted
         * to `cp` with '?'.
         *
         * This allows us to preserve and display as much information as possible.
         */
        int written = WideCharToMultiByte (cp, 0, wcs, -1, buffer, buffer_size, NULL, NULL);

        if (written == 0) {
            buffer[0] = '\0';
        }

        return;
    }

    /**
     * `WideCharToMultiByte` fails with `ERROR_INSUFFICIENT_BUFFER` when called
     * with insufficient buffer size. We have to convert wide characters in
     * `wcs` one-by-one.
     */

    /**
     * If `wcs` is being truncated, reserve space in `buffer` to add "...".
     */
    buffer_size -= 4;

    /**
     * Total number of bytes written to `buffer`.
     */
    int written = 0;

    while (1) {
        if (wcs[0] == L'\0') {
            break;
        }

        /**
         * Buffer to store next converted character from `wcs`.
         */
        char buf[MB_LEN_MAX] = {'?', '\0', '\0', '\0', '\0'};

        int wcLength = 1;
        int mbLength = 1;

        if (IS_LOW_SURROGATE (wcs[0])) {
            goto invalid_unicode;
        }

        if (IS_HIGH_SURROGATE (wcs[0])) {
            if (!IS_LOW_SURROGATE (wcs[1])) {
                goto invalid_unicode;
            }

            wcLength = 2;
        }

        mbLength = WideCharToMultiByte (cp, 0, wcs, wcLength, buf, MB_LEN_MAX, NULL, NULL);

        if (mbLength == 0) {
            break;
        }

        if (written + mbLength > buffer_size) {
            break;
        }

invalid_unicode:
        memcpy (buffer, buf, mbLength);

        buffer += mbLength;
        written += mbLength;
        wcs += wcLength;

        if (written == buffer_size) {
            break;
        }
    }

    /**
     * Append "..." to the end of `buffer`.
     */
    memcpy (buffer, (const char[]) {'.', '.', '.', '\0'}, 4);
}

/* _wassert is not available on XP, so forward it to _assert if needed */
static void __cdecl emu__wassert(const wchar_t *_Message, const wchar_t *_File, unsigned _Line)
{
    /**
     * _assert() prints `_Message` to stderr or displays a message box,
     * depending on `_set_error_mode` setting.
     *
     * When printing message to stderr, we want to convert `_Message` to
     * code page used by active CRT locale.
     *
     * When displaying a message box, we want to convert `_Message` to active
     * ANSI code page; most ANSI APIs interpret strings using that code page.
     *
     * Perfectly, we would call `_set_error_mode (_REPORT_ERRMODE)` to query
     * current setting and decide which code page to use; we cannot do this
     * because `_set_error_mode` is not available in crtdll.dll, msvcrt10.dll
     * and msvcrt20.dll.
     *
     * Use active ANSI code page as the conservative option.
     */
    unsigned cp = GetACP ();

    /**
     * After _assert() displays the message, it calls abort() to terminate
     * the process, which makes it possible to escape from _assert() by
     * setting signal handler for SIGABRT which calls longjmp().
     *
     * As the result, we should avoid dynamic memory allocations to avoid
     * possible memory leaks.
     *
     * Also, since msvcrt40.dll, _assert() can return if application has
     * called `_set_error_mode (_OUT_TO_MSGBOX)` and user pressed "Ignore"
     * button in the popped up message box.
     *
     * As the result, we should avoid using static buffer to avoid race
     * condition when multiple threads call _wassert() at the same time.
     */
    char *message = NULL;
    char *file = NULL;

    /**
     * We use `_alloca` to allocate buffers to hold converted `_Message` and
     * `_File`. In order to reduce possibility of stack overflow, we limit
     * allocation size for each buffer.
     *
     * In case when buffer size is not enough to store full converted string,
     * we will truncate the string.
     */
    bool truncate_message = false;
    bool truncate_file = false;

    /**
     * Call `WideCharToMultiByte` to calculate buffer size required to hold
     * converted `_Message` and `_File`.
     *
     * On failure, it returns zero; we must be careful not to allocate
     * zero-length buffer.
     */
    int message_length = WideCharToMultiByte (cp, 0, _Message, -1, NULL, 0, NULL, NULL);
    int file_length = WideCharToMultiByte (cp, 0, _File, -1, NULL, 0, NULL, NULL);

    if (message_length == 0) {
        message_length = 1;
    } else if (message_length > BUFSIZ) {
        truncate_message = true;
        message_length = BUFSIZ;
    }

    if (file_length == 0) {
        file_length = 1;
    } else if (file_length > FILENAME_MAX) {
        truncate_file = true;
        file_length = FILENAME_MAX;
    }

    message = _alloca (message_length);
    file = _alloca (file_length);

    conv (message, message_length, _Message, cp, truncate_message);
    conv (file, file_length, _File, cp, truncate_file);

    _assert(message, file, _Line);
}

#define RETT void
#define FUNC _wassert
#define ARGS const wchar_t * message, const wchar_t * file, unsigned line
#define CALL message, file, line
#include "msvcrt_or_emu_glue.h"
