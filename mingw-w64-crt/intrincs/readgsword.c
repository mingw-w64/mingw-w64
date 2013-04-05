#include <intrin.h>

/* for __x86_64 only */
unsigned short __readgsword(unsigned __LONG32 Offset)
{
   unsigned short ret;
   __asm__ volatile ("movw	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile __LONG32 *) (unsigned __int64) Offset)));
   return ret;
}

