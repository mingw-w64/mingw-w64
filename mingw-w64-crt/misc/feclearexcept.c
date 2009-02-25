/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h>
#define __HAS_SSE() 1

/* 7.6.2.1
   The feclearexcept function clears the supported exceptions
   represented by its argument.  */

int feclearexcept (int excepts)
{
  fenv_t _env;
  int _mxcsr;

  if (excepts == FE_ALL_EXCEPT)
    {
      __asm__ volatile ("fnclex");
    }
  else
    {
      __asm__ volatile ("fnstenv %0" : "=m" (_env));
      _env.__status_word &= ~(excepts & FE_ALL_EXCEPT);
      __asm__ volatile ("fldenv %0" : : "m" (_env));
    }
  if (__HAS_SSE())
    {
      __asm__ volatile ("stmxcsr %0" : "=m" (_mxcsr));
      _mxcsr &= ~(((excepts & FE_ALL_EXCEPT)));
      __asm__ volatile ("ldmxcsr %0" : : "m" (_mxcsr));
    }
  return (0);
}
