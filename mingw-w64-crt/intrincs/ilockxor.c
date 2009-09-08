#include <intrin.h>

long _InterlockedXor(long volatile *Destination, long Value)
{
  __asm__ __volatile__("lock ; xorl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

