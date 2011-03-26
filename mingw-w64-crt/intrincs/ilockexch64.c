#include <intrin.h>

#ifdef _WIN64
__int64 _InterlockedExchange64(__int64 volatile *Target, __int64 Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 _InterlockedExchange64(__int64 volatile *Target,__int64 Value);
__int64 _InterlockedExchange64(__int64 volatile *Target,__int64 Value)
{
  __int64 Old;
  do {
    Old = *Target;
  } while(InterlockedCompareExchange64(Target,Value,Old)!=Old);
  return Old;
}
#endif

#ifdef _WIN64
__int64 InterlockedExchange64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedExchange64")));
#else
__int64 __stdcall InterlockedExchange64(__int64 volatile *Target, __int64 Value);
__int64 __stdcall InterlockedExchange64(__int64 volatile *Target, __int64 Value)
{
  return _InterlockedExchange64(Target, Value);
}
#endif

