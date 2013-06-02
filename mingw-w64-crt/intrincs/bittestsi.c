#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandset, __LONG32, "lock bts", "I", /* unused param */)

unsigned char InterlockedBitTestAndSet(__LONG32 volatile *, __LONG32) __attribute__((alias("_interlockedbittestandset")));
