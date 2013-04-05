#include <intrin.h>

/* for __x86_64 only */
void __writegsdword(unsigned __LONG32 Offset, unsigned __LONG32 Data)
{
   __asm__ volatile ("movl	%0,%%gs:%1"
     : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
}

