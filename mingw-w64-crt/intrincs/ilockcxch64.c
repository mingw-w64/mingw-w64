#include <intrin.h>

#ifndef _WIN64
__declspec(dllimport) /* FIXME: not exported on XP-x86 */
__int64 __stdcall InterlockedCompareExchange64(__int64 volatile *Destination,
   __int64 ExChange, __int64 Comperand);
#endif

__int64 _InterlockedCompareExchange64(__int64 volatile *Destination, __int64 ExChange, __int64 Comperand)
{
#ifdef _WIN64
  __int64 prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
#else
  return InterlockedCompareExchange64(Destination,ExChange,Comperand);
#endif
}
#ifdef _WIN64
__int64 InterlockedCompareExchange64(__int64 volatile *, __int64, __int64) __attribute__((alias("_InterlockedCompareExchange64")));
#endif

