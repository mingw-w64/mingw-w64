#include <intrin.h>

unsigned char _InterlockedBitTestAndComplement(long *Base, long Bit);			/* not in intrin.h */
unsigned char _InterlockedBitTestAndComplement(long *Base, long Bit)
{
  int old = 0;
  __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Bit));
  return (old != 0);
}

unsigned char InterlockedBitTestAndComplement(long *Base, long Bit) __attribute__((alias("_InterlockedBitTestAndComplement")));

