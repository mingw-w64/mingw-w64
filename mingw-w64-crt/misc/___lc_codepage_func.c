/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <locale.h>

extern unsigned int *__MINGW_IMP_SYMBOL(__lc_codepage);

static unsigned int __cdecl emu____lc_codepage_func(void)
{
    return *__MINGW_IMP_SYMBOL(__lc_codepage);
}

#define RETT unsigned int
#define FUNC ___lc_codepage_func
#define ARGS void
#define CALL
#include "msvcrt_or_emu_glue.h"
