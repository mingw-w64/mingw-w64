/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <locale.h>

static _locale_t __cdecl emu__create_locale(int category, const char *locale)
{
  (void)category;
  (void)locale;
  return NULL;
}

#define RETT _locale_t
#define FUNC _create_locale
#define ARGS int category, const char * locale
#define CALL category, locale
#include "msvcrt_or_emu_glue.h"
