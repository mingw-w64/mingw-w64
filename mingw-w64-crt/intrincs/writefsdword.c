#include <intrin.h>

/* for x86 only */
void __writefsdword(unsigned long Offset, unsigned long Data)
{
   __asm__ volatile ("movl	%0,%%fs:%1"
     : "=r" (Data) ,"=m" ((*(volatile long *) Offset)));
}

