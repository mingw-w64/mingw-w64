/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdio.h>
#include <io.h>
#include <stdlib.h>
#include <windows.h>

void __cdecl __attribute__((__noreturn__)) __chk_fail(void);

void __cdecl __attribute__((__noreturn__)) __chk_fail(void) {
  static const char msg[] = "*** buffer overflow detected ***: terminated\n";
  write(STDERR_FILENO, msg, strlen(msg));
  if (IsProcessorFeaturePresent(PF_FASTFAIL_AVAILABLE)) {
    __fastfail(FAST_FAIL_RANGE_CHECK_FAILURE);
  } else {
    TerminateProcess(GetCurrentProcess(), STATUS_STACK_BUFFER_OVERRUN);
    __builtin_unreachable();
  }
}
