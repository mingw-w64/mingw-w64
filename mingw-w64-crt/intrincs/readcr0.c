/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#define __CRT__NO_INLINE
#include <_mingw.h>

/* Register sizes are different between 32/64 bit mode.
 * So we have to do this for _WIN64 and _WIN32 seperatly.
 */

#ifdef _WIN64
  unsigned __int64 __readcr0(void)
  {
      unsigned __int64 value;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      return value;
  }
#else
  unsigned long __readcr0(void)
  {
      unsigned long value;
      __asm__ __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      return value;
  }
#endif

