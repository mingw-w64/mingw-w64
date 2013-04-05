#include <intrin.h>

/* for x86 only */
unsigned short __readfsword(unsigned __LONG32 Offset)
{
   unsigned short ret;
   __asm__ volatile ("movw	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) Offset)));
   return ret;
}

