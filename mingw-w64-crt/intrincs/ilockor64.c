#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

LONG64 InterlockedOr64(LONG64 volatile *Destination,LONG64 Value)
{
  __asm__ __volatile__("lock ; orq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

