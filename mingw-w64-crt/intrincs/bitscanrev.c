#include <intrin.h>

unsigned char _BitScanReverse(unsigned long *Index, unsigned long Mask)
{
  unsigned long n;
  __asm__ __volatile__("bsrl %0,%1" : "+r" (Mask),"=rm" (n) : : "memory");
  *Index = n;
  return (Mask != 0);
}

