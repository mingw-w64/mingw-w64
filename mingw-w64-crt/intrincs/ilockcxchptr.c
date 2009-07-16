#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

PVOID InterlockedCompareExchangePointer(PVOID volatile *Destination,PVOID ExChange,PVOID Comperand)
{
  PVOID prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

