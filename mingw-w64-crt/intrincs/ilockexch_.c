#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

#undef InterlockedExchange
LONG _InterlockedExchange(LONG volatile *Target,LONG Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

