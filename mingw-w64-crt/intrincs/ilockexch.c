#include <intrin.h>

long _InterlockedExchange(long volatile *Target, long Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

#ifdef _WIN64
long InterlockedExchange(long volatile *, long) __attribute__((alias("_InterlockedExchange")));
#else
long __stdcall InterlockedExchange(long volatile *Target, long Value);
long __stdcall InterlockedExchange(long volatile *Target, long Value)
{
  return _InterlockedExchange(Target,Value);
}
#endif

