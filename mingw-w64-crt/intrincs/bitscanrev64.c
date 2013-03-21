#include <intrin.h>

unsigned char _BitScanReverse64(unsigned long *Index, unsigned __int64 Mask)
{
  unsigned __int64 n;
  __asm__ __volatile__("bsrq %0,%1" : "+r" (Mask),"=rm" (n) : : "memory");
  *Index = (unsigned long) n;
  return (Mask != 0);
}

