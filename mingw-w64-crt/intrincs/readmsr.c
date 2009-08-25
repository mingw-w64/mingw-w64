/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#define __CRT__NO_INLINE
#include <_mingw.h>

  unsigned __int64 __readmsr(unsigned long msr);

  unsigned __int64 __readmsr(unsigned long msr)
  {
#ifdef _WIN64
      unsigned __int64 val1, val2;
#else
      unsigned val1, val2;
#endif
       __asm__ __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      return ((unsigned __int64) val1) | (((unsigned __int64)val2) << 32);
  }

