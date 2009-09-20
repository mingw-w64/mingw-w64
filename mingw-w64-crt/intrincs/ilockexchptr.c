#include <intrin.h>

void *_InterlockedExchangePointer(void * volatile *Target, void *Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

void *InterlockedExchangePointer(void * volatile *, void *) __attribute__((alias("_InterlockedExchangePointer")));

