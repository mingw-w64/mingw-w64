#include <intrin.h>

void __movsd(unsigned long *Dest, unsigned long const *Source, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; movsd" :
    [Dest] "=D" (Dest), [Source] "=S" (Source), [Count] "=c" (Count) :
    "[Dest]" (Dest), "[Source]" (Source), "[Count]" (Count)
  );
}

