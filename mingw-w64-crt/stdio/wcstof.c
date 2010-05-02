/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <wchar.h>

float wcstof( const wchar_t *nptr, wchar_t **endptr)
{
  return (wcstod(nptr, endptr));
}
