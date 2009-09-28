#include <intrin.h>

/* for __x86_64 only */
void __writegsqword(unsigned long Offset, unsigned __int64 Data)
{
   __asm__ volatile ("movq	%0,%%gs:%1"
     : "=r" (Data) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
}

