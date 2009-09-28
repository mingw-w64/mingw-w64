#include <intrin.h>

void __stosb(unsigned char *Dest, unsigned char Data, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; stosb" :
    [Dest] "=D" (Dest), [Count] "=c" (Count) :
    "[Dest]" (Dest), "a" (Data), "[Count]" (Count)
  );
}

