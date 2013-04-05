#include <intrin.h>

/* for __x86_64 only */
void __writegsqword(unsigned __LONG32 Offset, unsigned __int64 Data)
{
   __asm__ volatile ("movq	%0,%%gs:%1"
     : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
}

