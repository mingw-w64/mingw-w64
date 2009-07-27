#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
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

LONG InterlockedExchange(LONG volatile *Target,LONG Value)
  __attribute__((alias("_InterlockedExchange")));

