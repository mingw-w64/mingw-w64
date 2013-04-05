#include <intrin.h>

/* for x86 only */
void __writefsdword(unsigned __LONG32 Offset, unsigned __LONG32 Data)
{
   __asm__ volatile ("movl	%0,%%fs:%1"
     : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) Offset)));
}

