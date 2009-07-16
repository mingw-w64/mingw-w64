#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

LONG64 InterlockedExchange64(LONG64 volatile *Target,LONG64 Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

