/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdint.h>
#include <errno.h>
#include <sys/timeb.h>

int __cdecl ftime32(struct __timeb32 *tb32);
int __cdecl ftime32(struct __timeb32 *tb32)
{
    /*
     * Both 32-bit and 64-bit MS _ftime functions have void return value and do not signal overflow.
     * So if 32-bit POSIX ftime function wants to detect overflow it has to call 64-bit _ftime function.
     * msvc defines ftime as alias to _ftime, which always fills all members even if they overflow.
     * So for compatibility with application code written for msvc ftime function, always fill
     * in our mingw-w64 POSIX ftime function all __timeb32 members, even if they are overflowed.
     * And if overflow happens, correctly sets errno to EOVERFLOW and returns negative value.
     */
    struct __timeb64 tb64;
    _ftime64(&tb64);
    tb32->time = (__time32_t)tb64.time; /* truncate */
    tb32->millitm = tb64.millitm;
    tb32->timezone = tb64.timezone;
    tb32->dstflag = tb64.dstflag;
    if (tb64.time < INT32_MIN || tb64.time > INT32_MAX) {
        errno = EOVERFLOW;
        return -1;
    }
    return 0;
}

/* On 32-bit systems is ftime ABI using 32-bit time_t */
#ifndef _WIN64
int __attribute__ ((alias("ftime32"))) __cdecl ftime(struct timeb *);
#endif
