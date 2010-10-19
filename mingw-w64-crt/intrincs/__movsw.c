#include <intrin.h>

void __movsw(unsigned short *Dest, unsigned short const *Source, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; movsw" :
    [Dest] "=D" (Dest), [Source] "=S" (Source), [Count] "=c" (Count) :
    "[Dest]" (Dest), "[Source]" (Source), "[Count]" (Count)
  );
}

