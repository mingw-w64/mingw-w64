
void MemoryBarrier (void);
void MemoryBarrier (void)
{
    long Barrier = 0;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
}

