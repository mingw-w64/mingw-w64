#include <intrin.h>

long _InterlockedDecrement(long volatile *Addend)
{
  long ret = -1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddl %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret - 1;
}

#ifdef _WIN64
long InterlockedDecrement(long volatile *) __attribute__((alias("_InterlockedDecrement")));
#else
long __stdcall InterlockedDecrement(long volatile *Addend);
long __stdcall InterlockedDecrement(long volatile *Addend)
{
  return _InterlockedDecrement(Addend);
}
#endif

