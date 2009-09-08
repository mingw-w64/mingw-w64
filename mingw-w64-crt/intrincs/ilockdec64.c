#include <intrin.h>

__int64 _InterlockedDecrement64(__int64 volatile *Addend)
{
  __int64 ret = -1LL;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddq %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret - 1LL;
}

