/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <time.h>

static wchar_t *__cdecl emu__wctime64(const __time64_t *timeptr)
{
    struct tm *tmptr = _localtime64(timeptr);
    return tmptr ? _wasctime(tmptr) : NULL;
}

#define RETT wchar_t *
#define FUNC _wctime64
#define ARGS const __time64_t *timeptr
#define CALL timeptr
#include "msvcrt_or_emu_glue.h"
