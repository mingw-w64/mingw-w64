#include <intrin.h>

unsigned char _BitScanReverse64(unsigned long *Index, unsigned __int64 Mask)
{
  __asm__ __volatile__("bsrq %1,%0" : "=r" (Mask),"=m" ((*(volatile long long *)Index)));
  return (Mask != 0);
}

