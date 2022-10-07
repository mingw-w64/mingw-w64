/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

/* `exit()`, C89  */
void exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(exit))(int) __attribute__((__noreturn__));

void exit(int status)
{
  (*__MINGW_IMP_SYMBOL(exit))(status);
}

/* `_exit()`, POSIX  */
void _exit(int status) __attribute__((__noreturn__));
extern void (*__MINGW_IMP_SYMBOL(_exit))(int) __attribute__((__noreturn__));

void _exit(int status)
{
  (*__MINGW_IMP_SYMBOL(_exit))(status);
}
