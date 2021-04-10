/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <intrin.h>

/* GCC 11 has this as a macro.  */
#undef __rdtsc

/* Clang has support for MSVC builtins, GCC doesn't */
#ifndef __has_builtin
  #define __has_builtin(x) 0
#endif

#if !__has_builtin(__rdtsc)
unsigned __int64 __rdtsc(void)
{
#ifdef _WIN64
      unsigned __int64 val1, val2;
#else
      unsigned int val1, val2;
#endif
      __asm__ __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      return ((unsigned __int64)val1) | (((unsigned __int64)val2) << 32);
}
#endif
