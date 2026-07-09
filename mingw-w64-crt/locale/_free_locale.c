/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __MSVCRT_VERSION__
#define __MSVCRT_VERSION__ 0x0800
#include <locale.h>

static void __cdecl emu__free_locale(_locale_t locale)
{
  (void)locale;
}

#define RETT void
#define FUNC _free_locale
#define ARGS _locale_t locale
#define CALL locale
#include "msvcrt_or_emu_glue.h"
