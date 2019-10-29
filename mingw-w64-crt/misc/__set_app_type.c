/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include "internal.h"

void __cdecl __set_app_type (int type) {
  (void)type;
}

void (__cdecl *__MINGW_IMP_SYMBOL(__set_app_type))(int) = __set_app_type;
