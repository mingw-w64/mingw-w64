/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <fenv.h> 

extern int __mingw_has_sse (void);

/* 7.6.2.5 
   The fetestexcept function determines which of a specified subset of
   the exception flags are currently set. The excepts argument
   specifies the exception flags to be queried.
   The fetestexcept function returns the value of the bitwise OR of the
   exception macros corresponding to the currently set exceptions
   included in excepts. */

int fetestexcept (int excepts)
{
  unsigned short _sw;
  __asm__ __volatile__ ("fnstsw %%ax" : "=a" (_sw));

  if (__mingw_has_sse ())
    {
      int sse_sw;
      __asm__ __volatile__ ("stmxcsr %0;" : "=m" (sse_sw));
      _sw |= sse_sw;
    }

  return _sw & excepts & FE_ALL_EXCEPT;
}
