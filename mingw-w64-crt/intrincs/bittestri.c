#include <intrin.h>

unsigned char _interlockedbittestandreset(__LONG32 *Base, __LONG32 Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile __LONG32 *) Base))
    :"Ir" (Offset));
  return (old != 0);
}

