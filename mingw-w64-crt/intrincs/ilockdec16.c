#include <intrin.h>

short _InterlockedDecrement16(short volatile *Addend)
{
  short ret = -1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddw %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret - 1;
}

short InterlockedDecrement16(short volatile *) __attribute__((alias("_InterlockedDecrement16")));

