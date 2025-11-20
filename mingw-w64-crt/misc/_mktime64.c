/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <windows.h>
#include <time.h>

#include "__tm_to_secs.h"

static __time64_t __cdecl emu__mktime64(struct tm *tmptr)
{
    __time64_t time64;
    struct tm *tmptr2;
    int tm_isdst;
    long local_dstbias;
    long local_timezone;

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
    local_dstbias = *__dstbias();
    local_timezone = *__timezone();

    tm_isdst = tmptr->tm_isdst;
    time64 = __tm_to_secs(tmptr);
    time64 += local_timezone;

    tmptr2 = _localtime64(&time64);
    if (!tmptr2)
        return -1;

    if (tm_isdst > 0 || (tm_isdst < 0 && tmptr2->tm_isdst > 0)) {
        time64 += local_dstbias;
        tmptr2 = _localtime64(&time64);
        if (!tmptr2)
            return -1;
    }

    *tmptr = *tmptr2;
    return time64;
}

#define RETT __time64_t
#define FUNC _mktime64
#define ARGS struct tm *tmptr
#define CALL tmptr
#include "msvcrt_or_emu_glue.h"
