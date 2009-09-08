#include <intrin.h>

void __stosq(unsigned __int64 *Dest, unsigned __int64 Data, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; stosq" :
    [Dest] "=D" (Dest), [Count] "=c" (Count) :
    "[Dest]" (Dest), "a" (Data), "[Count]" (Count)
  );
}

