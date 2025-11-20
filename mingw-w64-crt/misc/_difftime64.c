/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <time.h>

static double __cdecl emu__difftime64(__time64_t _Time1, __time64_t _Time2)
{
    return (double)(_Time1 - _Time2);
}

#define RETT double
#define FUNC _difftime64
#define ARGS __time64_t _Time1, __time64_t _Time2
#define CALL _Time1, _Time2
#include "msvcrt_or_emu_glue.h"
