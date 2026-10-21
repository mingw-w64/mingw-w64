/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

#include <internal.h>

static void __cdecl sse_mxcsr_reset(void)
{
  if (__mingw_has_sse()) {
    static const unsigned int default_mxcsr = 0x1F80;
    asm volatile (
      "ldmxcsr %0"
      :
      : "m" (default_mxcsr)
    );
  }
}
void (__cdecl * const __i386_pre_msvcr80_sse_mxcsr_reset)(void) = sse_mxcsr_reset;

#endif
