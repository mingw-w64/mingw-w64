#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandcomplement64, __int64, "lock btc", "J", /* unused param */)

unsigned char InterlockedBitTestAndComplement64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandcomplement64")));
