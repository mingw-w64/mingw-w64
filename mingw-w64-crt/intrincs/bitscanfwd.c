#include <intrin.h>

unsigned char _BitScanForward(unsigned long *Index, unsigned long Mask)
{
  unsigned long n;
  __asm__ __volatile__("bsfl %0,%1" : "+r" (Mask),"=rm" (n) : : "memory");
  *Index = n;
  return (Mask != 0);
}

