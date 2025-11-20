/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <time.h>

static char *__cdecl emu__ctime64(const __time64_t *timeptr)
{
    struct tm *tmptr = _localtime64(timeptr);
    return tmptr ? asctime(tmptr) : NULL;
}

#define RETT char *
#define FUNC _ctime64
#define ARGS const __time64_t *timeptr
#define CALL timeptr
#include "msvcrt_or_emu_glue.h"
