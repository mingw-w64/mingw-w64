/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h> 

/* 7.6.2.3
   The feraiseexcept function raises the supported exceptions
   represented by its argument The order in which these exceptions
   are raised is unspecified, except as stated in F.7.6.
   Whether the feraiseexcept function additionally raises
   the inexact exception whenever it raises the overflow
   or underflow exception is implementation-defined. */

int feraiseexcept (int excepts)
{
  fenv_t _env;
  __asm__ volatile ("fnstenv %0;" : "=m" (_env));
  _env.__status_word |= excepts & FE_ALL_EXCEPT;
  __asm__ volatile ("fldenv %0;"
		    "fwait;" : : "m" (_env));
  return 0;
}
