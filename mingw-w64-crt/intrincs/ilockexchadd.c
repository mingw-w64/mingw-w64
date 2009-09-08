#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

LONG InterlockedExchangeAdd(LONG volatile *Addend,LONG Value)
{
  LONG ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

