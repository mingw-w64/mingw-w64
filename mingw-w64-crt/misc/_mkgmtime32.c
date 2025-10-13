/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <time.h>
#include <stdint.h>

static __time32_t __cdecl emu__mkgmtime32(struct tm *tmptr)
{
    struct tm tm64;
    __time64_t time64;

    tm64 = *tmptr;
    time64 = _mkgmtime64(&tm64);

    if (time64 == -1 || time64 < 0 || time64 > INT32_MAX)
        return -1;

    *tmptr = tm64;
    return (__time32_t)time64;
}

#define RETT __time32_t
#define FUNC _mkgmtime32
#define ARGS struct tm *tmptr
#define CALL tmptr
#include "msvcrt_or_emu_glue.h"

/* On 32-bit systems is _mkgmtime ABI using 32-bit time_t */
#ifndef _WIN64
time_t __attribute__((alias("_mkgmtime32"))) __cdecl _mkgmtime(struct tm *tmptr);
extern time_t __attribute__((alias(__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_mkgmtime32))))) (__cdecl *__MINGW_IMP_SYMBOL(_mkgmtime))(struct tm *tmptr);
#endif
