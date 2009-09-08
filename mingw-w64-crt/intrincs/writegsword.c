#include <intrin.h>

/* for __x86_64 only */
void __writegsword(unsigned long Offset, unsigned short Data)
{
    __asm__ volatile ("movw	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (unsigned __int64) Offset)));
}

