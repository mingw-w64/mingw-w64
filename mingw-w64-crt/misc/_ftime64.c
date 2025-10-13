/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <sys/timeb.h>

#include "filetime_to_time64.h"

static void __cdecl emu__ftime64(struct __timeb64 *tb64)
{
    struct __timeb32 tb32;
    SYSTEMTIME systemtime;
    FILETIME filetime;

    _ftime32(&tb32);
    tb64->timezone = tb32.timezone;
    tb64->dstflag = tb32.dstflag;

    GetSystemTime(&systemtime);
    if (SystemTimeToFileTime(&systemtime, &filetime))
    {
        tb64->time = filetime_to_time64(&filetime);
        tb64->millitm = systemtime.wMilliseconds;
    }
    else
    {
        tb64->time = (__time64_t)tb32.time; /* truncated */
        tb64->millitm = tb32.millitm;
    }
}

#define RETT void
#define FUNC _ftime64
#define ARGS struct __timeb64 *tb
#define CALL tb
#include "msvcrt_or_emu_glue.h"
