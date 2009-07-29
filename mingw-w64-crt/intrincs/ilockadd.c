#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

/* for __x86_64 only */

LONG InterlockedAdd(LONG volatile *Addend,LONG Value)
{
/* return InterlockedExchangeAdd(Addend,Value) + Value; */
  LONG ret;
  __asm__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret + Value;
}

