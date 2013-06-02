#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandreset64, __int64, "lock btr", "J", /* unused param */)

unsigned char InterlockedBitTestAndReset64(__int64 volatile *, __int64) __attribute__((alias("_interlockedbittestandreset64")));
