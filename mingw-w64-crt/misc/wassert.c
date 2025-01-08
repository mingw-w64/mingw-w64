/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <assert.h>
#include <stdlib.h>

/* _wassert is not available on XP, so forward it to _assert if needed */
__MINGW_ATTRIB_NORETURN
static void __cdecl emu__wassert(const wchar_t *_Message, const wchar_t *_File, unsigned _Line)
{
    char *message = NULL, *file = NULL;
    size_t len;

    if ((len = wcstombs(NULL, _Message, 0)) != (size_t)-1)
    {
        message = malloc(len + 1);
        wcstombs(message, _Message, len + 1);
    }

    if ((len = wcstombs(NULL, _File, 0)) != (size_t)-1)
    {
        file = malloc(len + 1);
        wcstombs(file, _File, len + 1);
    }

    _assert(message, file, _Line);
}

#define NORETURN
#define RETT void
#define FUNC _wassert
#define ARGS const wchar_t * message, const wchar_t * file, unsigned line
#define CALL message, file, line
#include "msvcrt_or_emu_glue.h"
