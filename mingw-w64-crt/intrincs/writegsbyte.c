#include <intrin.h>

/* for __x86_64 only */
void __writegsbyte(unsigned long Offset, unsigned char Data)
{
    __asm__ volatile ("movb	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
}

