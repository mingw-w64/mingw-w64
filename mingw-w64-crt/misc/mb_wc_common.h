/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>
_CRTIMP unsigned int ___lc_codepage_func(void);

static inline
unsigned int get_codepage (void)
{
  return ___lc_codepage_func();
}
