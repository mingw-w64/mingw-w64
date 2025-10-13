/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <time.h>

#include "filetime_to_time64.h"
#include "__tm_to_secs.h"

static const short int days_in_year[] = { -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364 };

static __time64_t __cdecl emu__mkgmtime64(struct tm *tmptr)
{
    SYSTEMTIME systemtime;
    FILETIME filetime;
    __time64_t time64;
    int is_leap_year;
    int has_leap_day;

    /*
     * WinAPI SystemTimeToFileTime() function is converting tm-like struct
     * to timestamp but it accepts only SYSTEMTIME with valid wMilliseconds,
     * wSecond, wMinute, wHour, wDay, wMonth, wYear values. CRT mkgmtime()
     * accepts also struct tm with invalid tm_sec, tm_min, tm_hour, tm_mday,
     * tm_mon, tm_year values and normalize them on return. So we cannot use
     * WinAPI SystemTimeToFileTime() function for conversion. Instead includes
     * and use the __tm_to_secs() function from the musl libc implementation.
     */

    time64 = __tm_to_secs(tmptr);

    /* Convert the timestamp back to SYSTEMTIME for normalizing struct tm */
    time64_to_filetime(time64, &filetime);
    if (!FileTimeToSystemTime(&filetime, &systemtime))
        return -1;

    is_leap_year = ((systemtime.wYear % 4 == 0 && systemtime.wYear % 100 != 0) || systemtime.wYear % 400 == 0);
    has_leap_day = (systemtime.wMonth >= 3 && is_leap_year);

    /* Set back normalized values */
    tmptr->tm_sec = systemtime.wSecond;
    tmptr->tm_min = systemtime.wMinute;
    tmptr->tm_hour = systemtime.wHour;
    tmptr->tm_mday = systemtime.wDay;
    tmptr->tm_mon = systemtime.wMonth - 1;
    tmptr->tm_year = systemtime.wYear - 1900;
    tmptr->tm_wday = systemtime.wDayOfWeek;
    tmptr->tm_yday = days_in_year[tmptr->tm_mon] + systemtime.wDay + (has_leap_day ? 1 : 0);
    tmptr->tm_isdst = 0;

    return time64;
}

#define RETT __time64_t
#define FUNC _mkgmtime64
#define ARGS struct tm *tmptr
#define CALL tmptr
#include "msvcrt_or_emu_glue.h"
