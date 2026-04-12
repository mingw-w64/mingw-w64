/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define __CRT__NO_INLINE
#include <string.h>

void * __cdecl
memset_explicit (void *d, int c, size_t len)
{
  memset(d, c, len);
  __asm__ __volatile__("" ::: "memory");
  return d;
}
