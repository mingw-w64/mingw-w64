#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandset64, __int64, "lock bts", "J", /* unused param */)

unsigned char InterlockedBitTestAndSet64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandset64")));
