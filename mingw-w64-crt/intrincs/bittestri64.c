#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

BOOLEAN _interlockedbittestandreset64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old != 0);
}

