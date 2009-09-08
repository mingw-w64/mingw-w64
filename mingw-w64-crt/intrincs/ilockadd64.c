#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

LONG64 InterlockedAdd64(LONG64 volatile *Addend,LONG64 Value)
{
/* return InterlockedExchangeAdd64(Addend,Value) + Value; */
  LONG64 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret + Value;
}

