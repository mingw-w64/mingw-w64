#include <intrin.h>

void __movsq(unsigned long long *Dest, unsigned long long const *Source, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; movsq" :
    [Dest] "=D" (Dest), [Source] "=S" (Source), [Count] "=c" (Count) :
    "[Dest]" (Dest), "[Source]" (Source), "[Count]" (Count)
  );
}

