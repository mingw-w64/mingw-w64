#include <intrin.h>

#ifdef _WIN64
void *_InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand)
{
  void *prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
#else
void *_InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand);

void *_InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand)
{
  void *prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
#endif

#ifdef _WIN64
void *InterlockedCompareExchangePointer(void * volatile *, void *, void *) __attribute__((alias("_InterlockedCompareExchangePointer")));
#else
void * __stdcall InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand);
void * __stdcall InterlockedCompareExchangePointer(void * volatile *Destination, void *ExChange, void *Comperand)
{
  return _InterlockedCompareExchangePointer(Destination, ExChange, Comperand);
}
#endif

