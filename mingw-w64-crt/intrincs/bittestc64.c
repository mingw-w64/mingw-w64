#include <intrin.h>

unsigned char _bittestandcomplement64(__int64 *Base, __int64 Offset)
{
  int old = 0;
  __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (old != 0);
}

