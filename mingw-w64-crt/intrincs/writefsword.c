#include <intrin.h>

/* for x86 only */
void __writefsword(unsigned __LONG32 Offset, unsigned short Data)
{
    __asm__ volatile ("movw	%0,%%fs:%1"
      : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) Offset)));
}

