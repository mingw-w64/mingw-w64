/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fenv.h>

int __mingw_has_sse (void);

 /* 7.6.3.2
    The fesetround function establishes the rounding direction
    represented by its argument round. If the argument is not equal
    to the value of a rounding direction macro, the rounding direction
    is not changed.  */

int fesetround (int mode)
{
  unsigned short _cw;
  if ((mode & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
      != 0)
    return -1;
  __asm__ volatile ("fnstcw %0;": "=m" (*&_cw));
  _cw &= ~0xc00;
  _cw |= mode;
  __asm__ volatile ("fldcw %0;" : : "m" (*&_cw));
  
  if (__mingw_has_sse ())
    {
      int mxcsr;

      __asm__ volatile ("stmxcsr %0" : "=m" (*&mxcsr));
      mxcsr &= ~0x6000;
      mxcsr |= mode << 3;
      __asm__ volatile ("ldmxcsr %0" : : "m" (*&mxcsr));
    }
  return 0;
}
