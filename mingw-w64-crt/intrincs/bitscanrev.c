#include <intrin.h>

unsigned char _BitScanReverse(unsigned long *Index, unsigned long Mask)
{
  __asm__ __volatile__("bsrl %1,%0" : "=r" (Mask),"=m" ((*(volatile long *)Index)));
  return (Mask != 0);
}

