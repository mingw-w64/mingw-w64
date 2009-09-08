#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

LONG64 InterlockedExchangeAdd64(LONG64 volatile *Addend,LONG64 Value)
{
  LONG64 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

