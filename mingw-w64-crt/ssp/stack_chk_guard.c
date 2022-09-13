/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#define _CRT_RAND_S
#include <stdlib.h>
#include <stdint.h>

void *__stack_chk_guard;

static void __cdecl __attribute__((__constructor__)) init(void)
{
  unsigned int ui;
  if (__stack_chk_guard != 0)
    return;

  // Call rand_s from the CRT; this uses a high quality random source
  // RtlGenRandom internally. This function is available since XP, and is
  // callable in WinStore mode too (since it's from the CRT).
  // In the case of msvcrt.dll, our import library provides a small wrapper
  // which tries to load the function dynamically, and falls back on
  // using RtlRandomGen if not available.
  if (rand_s(&ui) == 0) {
    __stack_chk_guard = (void*)(intptr_t)ui;
#if __SIZEOF_POINTER__ > 4
    rand_s(&ui);
    __stack_chk_guard = (void*)(((intptr_t)__stack_chk_guard) << 32 | ui);
#endif
    return;
  }

  // If rand_s failed (it shouldn't), hardcode a nonzero default stack guard.
#if __SIZEOF_POINTER__ > 4
  __stack_chk_guard = (void*)0xdeadbeefdeadbeefULL;
#else
  __stack_chk_guard = (void*)0xdeadbeef;
#endif
}
