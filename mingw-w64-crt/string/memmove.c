/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <string.h>

void *memmove(void *dest, const void *src, size_t n) {
  memmove_s(dest, n, src, n);
  return dest;
}
