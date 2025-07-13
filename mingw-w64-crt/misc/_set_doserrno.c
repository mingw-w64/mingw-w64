/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdlib.h>

errno_t __cdecl _set_doserrno(unsigned long value)
{
  _doserrno = value;
  return 0;
}
errno_t (__cdecl *__MINGW_IMP_SYMBOL(_set_doserrno))(unsigned long) = _set_doserrno;
