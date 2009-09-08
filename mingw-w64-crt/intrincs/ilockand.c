#include <intrin.h>

long _InterlockedAnd(long volatile *Destination, long Value)
{
  __asm__ __volatile__("lock ; andl %0,%1"
    : :"r"(Value),"m"(*Destination)
    : "memory");
  return *Destination;
}

