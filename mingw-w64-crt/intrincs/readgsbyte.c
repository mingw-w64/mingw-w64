#include <intrin.h>

/* for __x86_64 only */
unsigned char __readgsbyte(unsigned __LONG32 Offset)
{
   unsigned char ret;
   __asm__ volatile ("movb	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
   return ret;
}

