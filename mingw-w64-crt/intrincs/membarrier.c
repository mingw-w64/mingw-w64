
void MemoryBarrier (void);
void MemoryBarrier (void)
{
    __LONG32 Barrier = 0;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
}

