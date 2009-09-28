#include <intrin.h>

unsigned char _BitScanForward64(unsigned long *Index, unsigned __int64 Mask)
{
  __asm__ __volatile__("bsfq %1,%0" : "=r" (Mask),"=m" ((*(volatile long long *)Index)));
  return (Mask != 0);
}

