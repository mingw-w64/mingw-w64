#include <intrin.h>

#ifdef _WIN64
__int64 _InterlockedDecrement64(__int64 volatile *Addend)
{
  __int64 ret = -1LL;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddq %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret - 1LL;
}
#else
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
  __int64 Exchange, __int64 Comperand);
__int64 _InterlockedDecrement64(__int64 volatile *Addend);
__int64 _InterlockedDecrement64(__int64 volatile *Addend)
{
  __int64 Old;
  do {
    Old = *Addend;
  } while(InterlockedCompareExchange64(Addend,Old - 1,Old)!=Old);
  return Old - 1;
}
#endif

#ifdef _WIN64
__int64 InterlockedDecrement64(__int64 volatile *) __attribute__((alias("_InterlockedDecrement64")));
#else
__int64 __stdcall InterlockedDecrement64(__int64 volatile *Addend);
__int64 __stdcall InterlockedDecrement64(__int64 volatile *Addend)
{
  return _InterlockedDecrement64(Addend);
}
#endif

