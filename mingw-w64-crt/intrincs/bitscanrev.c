#include <intrin.h>

unsigned char _BitScanReverse(unsigned __LONG32 *Index, unsigned __LONG32 Mask)
{
  unsigned __LONG32 n;
  __asm__ __volatile__("bsrl %0,%1" : "+r" (Mask),"=rm" (n) : : "memory");
  *Index = n;
  return (Mask != 0);
}

