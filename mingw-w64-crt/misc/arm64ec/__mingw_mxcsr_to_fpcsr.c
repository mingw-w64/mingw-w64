/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifdef __arm64ec__

unsigned long long __mingw_mxcsr_to_fpcsr(unsigned mxcsr);
unsigned long long __mingw_mxcsr_to_fpcsr(unsigned mxcsr)
{
  unsigned fpsr = 0;
  if (mxcsr & 0x0001)    fpsr |= 0x0001;      /* invalid operation */
  if (mxcsr & 0x0004)    fpsr |= 0x0002;      /* zero-divide */
  if (mxcsr & 0x0008)    fpsr |= 0x0004;      /* overflow */
  if (mxcsr & 0x0010)    fpsr |= 0x0008;      /* underflow */
  if (mxcsr & 0x0020)    fpsr |= 0x0010;      /* precision */
  if (mxcsr & 0x0002)    fpsr |= 0x0080;      /* denormal */

  unsigned fpcr = 0;
  if (!(mxcsr & 0x0080)) fpcr |= 0x0000100;   /* invalid operation mask */
  if (!(mxcsr & 0x0200)) fpcr |= 0x0000200;   /* zero-divide mask */
  if (!(mxcsr & 0x0400)) fpcr |= 0x0000400;   /* overflow mask */
  if (!(mxcsr & 0x0800)) fpcr |= 0x0000800;   /* underflow mask */
  if (!(mxcsr & 0x1000)) fpcr |= 0x0001000;   /* precision mask */
  if (!(mxcsr & 0x0100)) fpcr |= 0x0008000;   /* denormal mask */
  if (mxcsr & 0x0040)    fpcr |= 0x0080000;   /* denormals are zero */
  if (mxcsr & 0x4000)    fpcr |= 0x0400000;   /* round up */
  if (mxcsr & 0x2000)    fpcr |= 0x0800000;   /* round down */
  if (mxcsr & 0x8000)    fpcr |= 0x1000000;   /* flush to zero */

  return ((unsigned long long)fpsr << 32) | fpcr;
}

#endif
