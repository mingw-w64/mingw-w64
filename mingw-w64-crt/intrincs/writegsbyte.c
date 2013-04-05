#include <intrin.h>

/* for __x86_64 only */
void __writegsbyte(unsigned __LONG32 Offset, unsigned char Data)
{
    __asm__ volatile ("movb	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
}

