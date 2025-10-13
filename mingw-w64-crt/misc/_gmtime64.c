/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <time.h>

#include "filetime_to_time64.h"

static const short int days_in_year[] = { -1, 30, 58, 89, 119, 150, 180, 211, 242, 272, 303, 333, 364 };

static struct tm *__cdecl emu__gmtime64(const __time64_t *timeptr)
{
    struct tm *tmptr;
    FILETIME filetime;
    SYSTEMTIME systemtime;
    int is_leap_year;
    int has_leap_day;

    time64_to_filetime(*timeptr, &filetime);
    if (!FileTimeToSystemTime(&filetime, &systemtime))
        return NULL;

    /* retrieve thread local storage for gmtime tm */
    tmptr = _gmtime32(&(__time32_t){0});
    if (!tmptr)
        return NULL;

    is_leap_year = ((systemtime.wYear % 4 == 0 && systemtime.wYear % 100 != 0) || systemtime.wYear % 400 == 0);
    has_leap_day = (systemtime.wMonth >= 3 && is_leap_year);

    tmptr->tm_sec = systemtime.wSecond;
    tmptr->tm_min = systemtime.wMinute;
    tmptr->tm_hour = systemtime.wHour;
    tmptr->tm_mday = systemtime.wDay;
    tmptr->tm_mon = systemtime.wMonth - 1;
    tmptr->tm_year = systemtime.wYear - 1900;
    tmptr->tm_wday = systemtime.wDayOfWeek;
    tmptr->tm_yday = days_in_year[tmptr->tm_mon] + systemtime.wDay + (has_leap_day ? 1 : 0);
    tmptr->tm_isdst = 0;
    return tmptr;
}

#define RETT struct tm *
#define FUNC _gmtime64
#define ARGS const __time64_t *timeptr
#define CALL timeptr
#include "msvcrt_or_emu_glue.h"
