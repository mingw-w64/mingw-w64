/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdlib.h>

errno_t __cdecl _set_fmode(int value)
{
  _fmode = value;
  return 0;
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(_set_fmode))(int) = _set_fmode;
