/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <time.h>

static struct tm *__cdecl emu__localtime64(const __time64_t *timeptr)
{
    struct tm *tmptr;
    struct tm tm32;
    int local_daylight;
    long local_dstbias;
    long local_timezone;
    __time64_t t64;
    __time32_t t32;

    /* _tzset() initialize _daylight, _dstbias and _timezone variables,
     * so it needs to be called before accessing those variables.
     * If those variables are already initialized then _tzset() does
     * not need to be called again. As _tzset() is an expensive call,
     * guard repeated calls by static variable. As the _tzset() is a
     * thread-safe call, the race condition is not a problem.
     */
    {
        static volatile long tzset_called = 0;
        if (!tzset_called) {
            _tzset();
            (void)InterlockedExchange(&tzset_called, 1);
        }
    }
    local_daylight = *__daylight();
    local_dstbias = *__dstbias();
    local_timezone = *__timezone();

    /* __localtime64() for the case when the timezone does not use DST */
    t64 = *timeptr - local_timezone;
    tmptr = _gmtime64(&t64);
    if (!tmptr)
        return NULL;

    /* If the timezone use DST then it is needed to check if the DST is active
     * for passed timestamp. To do that use the existing _localtime32() function
     * and its tm_isdst member of return value. As the _localtime32() function
     * works only for time structure which can be represented by signed 32-bit
     * time_t type, change year of the passed timestamp, so the timestamp can
     * be represented by 32-bit type. This expects that the DST start and end
     * days of the last addressable year matches also for all other future years.
     */
    if (local_daylight) {
        /* Prepare struct tm to be representable by 32-bit time_t value, just by changing year */
        tm32 = *tmptr;
        if (tm32.tm_year > 2037-1900)
            tm32.tm_year = 2037-1900;
        else if (tm32.tm_year < 1971-1900)
            tm32.tm_year = 1971-1900;

        /* Use _localtime32()'s tm_isdst to determinate if the DST is active for passed timestamp */
        t32 = _mkgmtime32(&tm32);
        if (t32 == -1)
            return NULL;
        t32 += local_timezone; /* Remove the fake timezone offset */
        tmptr = _localtime32(&t32);
        if (!tmptr)
            return NULL;

        /* If the DST is active for passed timestamp then recalculate the struct tm according to DST bias */
        if (tmptr->tm_isdst) {
            t64 -= local_dstbias;
            tmptr = _gmtime64(&t64);
            if (!tmptr)
                return NULL;
            tmptr->tm_isdst = 1;
        } else {
            tmptr = _gmtime64(&t64);
        }
    }

    return tmptr;
}

#define RETT struct tm *
#define FUNC _localtime64
#define ARGS const __time64_t *timeptr
#define CALL timeptr
#include "msvcrt_or_emu_glue.h"
