#include <intrin.h>

void *_InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand)
{
  void *prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

