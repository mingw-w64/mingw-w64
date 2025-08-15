/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <locale.h>
#include <windows.h>

extern LCID *__MINGW_IMP_SYMBOL(__lc_handle);

static LCID *__cdecl emu____lc_handle_func(void)
{
    return __MINGW_IMP_SYMBOL(__lc_handle);
}

LCID *__cdecl ___lc_handle_func(void);
#define RETT LCID*
#define FUNC ___lc_handle_func
#define ARGS void
#define CALL
#include "msvcrt_or_emu_glue.h"
