#include <intrin.h>

/* for x86 only */
unsigned __LONG32 __readfsdword(unsigned __LONG32 Offset)
{
   unsigned __LONG32 ret;
   __asm__ volatile ("movl	%%fs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) Offset)));
   return ret;
}

