#include <intrin.h>
#include <psdk_inc/intrin-mac.h>

__buildbittesti(_interlockedbittestandcomplement, __LONG32, "lock btc", "I", /* unused param */)

unsigned char InterlockedBitTestAndComplement(__LONG32 volatile *, __LONG32) __attribute__((alias("_interlockedbittestandcomplement")));
