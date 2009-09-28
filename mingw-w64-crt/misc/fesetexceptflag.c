/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <fenv.h>

extern int __mingw_has_sse (void);

/* 7.6.2.4
   The fesetexceptflag function sets the complete status for those
   exception flags indicated by the argument excepts, according to the
   representation in the object pointed to by flagp. The value of
   *flagp shall have been set by a previous call to fegetexceptflag
   whose second argument represented at least those exceptions
   represented by the argument excepts. This function does not raise
   exceptions, but only sets the state of the flags. */ 

int fesetexceptflag (const fexcept_t * flagp, int excepts) 
{
  fenv_t _env;

  excepts &= FE_ALL_EXCEPT;
  __asm__ volatile ("fnstenv %0;" : "=m" (_env));
  _env.__status_word &= ~excepts;
  _env.__status_word |= (*flagp & excepts);
  __asm__ volatile ("fldenv %0;" : : "m" (_env));

  if (__mingw_has_sse ())
    {
      int sse_cw;
      __asm__ volatile ("stmxcsr %0;" : "=m" (sse_cw));
      sse_cw &= ~(excepts << 7);
      sse_cw |= ((*flagp & excepts) << 7);
      __asm__ volatile ("ldmxcsr %0" : : "m" (sse_cw));
    }

  return 0;
}
