#include <intrin.h>

long _InterlockedAdd(long volatile *, long);			/* not in intrin.h */
long _InterlockedAdd(long volatile *Addend, long Value)
{
/* return InterlockedExchangeAdd(Addend,Value) + Value; */
  long ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret + Value;
}

long InterlockedAdd(long volatile *, long) __attribute__((alias("_InterlockedAdd")));

