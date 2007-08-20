/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <stdio.h>

_off64_t
ftello64 (FILE * stream)
{
  return (_off64_t) _ftelli64(stream);
}
