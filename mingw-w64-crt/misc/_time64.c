/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <time.h>

#include "filetime_to_time64.h"

static __time64_t __cdecl emu__time64(__time64_t *timeptr)
{
    SYSTEMTIME systemtime;
    FILETIME filetime;
    __time64_t time64;
    GetSystemTime(&systemtime);
    if (SystemTimeToFileTime(&systemtime, &filetime))
        time64 = filetime_to_time64(&filetime);
    else
        time64 = -1;
    if (timeptr)
        *timeptr = time64;
    return time64;
}

#define RETT __time64_t
#define FUNC _time64
#define ARGS __time64_t *timeptr
#define CALL timeptr
#include "msvcrt_or_emu_glue.h"
