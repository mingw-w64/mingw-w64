/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#if defined(__i386__)

/* This is for msvcr80+ builds, so no function is provided */
void (__cdecl * const __i386_pre_msvcr80_sse_mxcsr_reset)(void) = (void *)0;

#endif
