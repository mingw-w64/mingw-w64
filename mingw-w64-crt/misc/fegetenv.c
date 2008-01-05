/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h>

/* 7.6.4.1
   The fegetenv function stores the current floating-point environment
   in the object pointed to by envp.  */

int fegetenv (fenv_t * envp)
{
  __asm__ ("fnstenv %0;": "=m" (*envp));
 /* fnstenv sets control word to non-stop for all exceptions, so we
    need to reload our env to restore the original mask.  */
  __asm__ ("fldenv %0" : : "m" (*envp));
  return 0;
}
