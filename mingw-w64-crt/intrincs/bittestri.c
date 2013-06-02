#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandreset, __LONG32, "lock btr", "I", /* unused param */)

unsigned char InterlockedBitTestAndReset(__LONG32 volatile *, __LONG32) __attribute__((alias("_interlockedbittestandreset")));
