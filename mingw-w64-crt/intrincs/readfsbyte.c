#include <intrin.h>

/* for x86 only */
unsigned char __readfsbyte(unsigned __LONG32 Offset)
{
   unsigned char ret;
   __asm__ volatile ("movb	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) Offset)));
   return ret;
}

