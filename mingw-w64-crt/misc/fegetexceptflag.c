/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h>

#define __HAS_SSE() 1

/* 7.6.2.2  
   The fegetexceptflag function stores an implementation-defined
   representation of the exception flags indicated by the argument
   excepts in the object pointed to by the argument flagp.  */

int fegetexceptflag (fexcept_t * flagp, int excepts)
{
  int _mxcsr;
  unsigned short _status;

  __asm__ volatile ("fnstsw %0" : "=am" (_status));
  _mxcsr = 0;
  if (__HAS_SSE())
    __asm__ volatile ("stmxcsr %0" : "=m" (_mxcsr));
    
  *flagp = (_mxcsr | _status) & excepts & FE_ALL_EXCEPT;
  return 0;
}
