#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

BOOLEAN _bittestandreset(LONG *Base,LONG Offset);

BOOLEAN _bittestandreset(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old != 0);
}

