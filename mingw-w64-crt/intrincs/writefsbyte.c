#include <intrin.h>

/* for x86 only */
void __writefsbyte(unsigned long Offset, unsigned char Data)
{
    __asm__ volatile ("movb	%0,%%fs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) Offset)));
}

