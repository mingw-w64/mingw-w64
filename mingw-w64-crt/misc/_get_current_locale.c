/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <locale.h>

static _locale_t __cdecl emu__get_current_locale(void)
{
  return NULL;
}

#define RETT _locale_t
#define FUNC _get_current_locale
#define ARGS void
#define CALL
#include "msvcrt_or_emu_glue.h"
