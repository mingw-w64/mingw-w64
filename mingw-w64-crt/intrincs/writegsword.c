#include <intrin.h>

/* for __x86_64 only */
void __writegsword(unsigned __LONG32 Offset, unsigned short Data)
{
    __asm__ volatile ("movw	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
}

