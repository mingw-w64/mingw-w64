/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <intrin.h>

/* Register sizes are different between 32/64 bit mode.
 * So we have to do this for _WIN64 and _WIN32 seperatly.
 */

#ifdef _WIN64
  void __writecr2(unsigned __int64 Data);			/* not in intrin.h */
  void __writecr2(unsigned __int64 Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
  }
#else
  void __writecr2(unsigned Data);				/* not in intrin.h */
  void __writecr2(unsigned Data)
  {
   __asm__ __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
  }
#endif

