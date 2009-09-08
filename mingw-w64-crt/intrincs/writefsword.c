#include <intrin.h>

/* for x86 only */
void __writefsword(unsigned long Offset, unsigned short Data)
{
    __asm__ volatile ("movw	%0,%%fs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) Offset)));
}

