#include <intrin.h>

void __movsb(unsigned char *Destination, unsigned char const *Source, size_t Count)
{
  __asm__ __volatile__
  (
    "rep; movsb" :
    [Destination] "=D" (Destination), [Source] "=S" (Source), [Count] "=c" (Count) :
    "[Destination]" (Destination), "[Source]" (Source), "[Count]" (Count)
  );
}

