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

#ifdef _WIN64
long InterlockedAdd(long volatile *, long) __attribute__((alias("_InterlockedAdd")));
#else
long __stdcall InterlockedAdd(long volatile *Addend, long Value);
long __stdcall InterlockedAdd(long volatile *Addend, long Value)
{
  return _InterlockedAdd(Addend, Value);
}
#endif

