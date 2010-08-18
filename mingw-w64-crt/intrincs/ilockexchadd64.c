#include <intrin.h>

#ifdef _WIN64
__int64 _InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value)
{
  __int64 ret;
  __asm__ __volatile__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 __cdecl _InterlockedExchangeAdd64(__int64 volatile *Addend,__int64 Value);
__int64 __cdecl _InterlockedExchangeAdd64(__int64 volatile *Addend,__int64 Value)
{
  __int64 Old;
  do {
    Old = *Addend;
  } while(InterlockedCompareExchange64(Addend,Old + Value,Old)!=Old);
  return Old;
}
#endif

#ifdef _WIN64
__int64 InterlockedExchangeAdd64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedExchangeAdd64")));
#else
__int64 __stdcall InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value);
__int64 __stdcall InterlockedExchangeAdd64(__int64 volatile *Addend, __int64 Value)
{
  return _InterlockedExchangeAdd64(Addend, Value);
}
#endif

