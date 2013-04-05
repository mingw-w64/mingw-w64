#include <intrin.h>

/* for __x86_64 only */
unsigned __LONG32 __readgsdword(unsigned __LONG32 Offset)
{
   unsigned __LONG32 ret;
   __asm__ volatile ("movl	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
   return ret;
}

