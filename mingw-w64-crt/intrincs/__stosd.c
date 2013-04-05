#include <intrin.h>

void __stosd(unsigned __LONG32 *Dest, unsigned __LONG32 Data, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; stosl" :
    [Dest] "=D" (Dest), [Count] "=c" (Count) :
    "[Dest]" (Dest), "a" (Data), "[Count]" (Count)
  );
}

