#include <intrin.h>

#ifdef _WIN64
void *_InterlockedExchangePointer(void * volatile *Target, void *Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}
#else
void *_InterlockedExchangePointer(void * volatile *Target, void *Value);
void *_InterlockedExchangePointer(void * volatile *Target, void *Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}
#endif

#ifdef _WIN64
void *InterlockedExchangePointer(void * volatile *, void *) __attribute__((alias("_InterlockedExchangePointer")));
#else
void * __stdcall InterlockedExchangePointer(void * volatile *Target, void *Value);
void * __stdcall InterlockedExchangePointer(void * volatile *Target, void *Value)
{
  return _InterlockedExchangePointer(Target, Value);
}
#endif

