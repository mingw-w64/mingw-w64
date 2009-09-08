#include <intrin.h>

/* for __x86_64 only */
void __writegsdword(unsigned long Offset, unsigned long Data)
{
   __asm__ volatile ("movl	%0,%%gs:%1"
     : "=r" (Data) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
}

