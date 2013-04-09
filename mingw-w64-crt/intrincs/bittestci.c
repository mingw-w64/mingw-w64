#include <intrin.h>

unsigned char _InterlockedBitTestAndComplement(__LONG32 *Base, __LONG32 Bit);			/* not in intrin.h */
unsigned char _InterlockedBitTestAndComplement(__LONG32 *Base, __LONG32 Bit)
{
  int old = 0;
  __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile __LONG32 *) Base))
    :"Ir" (Bit) : "memory");
  return (old != 0);
}

unsigned char InterlockedBitTestAndComplement(__LONG32 *Base, __LONG32 Bit) __attribute__((alias("_InterlockedBitTestAndComplement")));

