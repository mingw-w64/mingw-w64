/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h>

int __mingw_has_sse (void);

/* 7.6.4.1
   The fegetenv function stores the current floating-point environment
   in the object pointed to by envp.  */

int fegetenv (fenv_t * envp)
{
  __asm__ __volatile__ ("fnstenv %0;": "=m" (*envp));
 /* fnstenv sets control word to non-stop for all exceptions, so we
    need to reload our env to restore the original mask.  */
  __asm__ __volatile__ ("fldenv %0" : : "m" (*envp));
  if (__mingw_has_sse ())
    {
      int _mxcsr;
      __asm__ __volatile__ ("stmxcsr %0" : "=m" (_mxcsr));
      envp->__unused0 = (((unsigned int) _mxcsr) >> 16);
      envp->__unused1 = (((unsigned int) _mxcsr) & 0xffff);
    }
  return 0;
}

