/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <process.h>
#include <windows.h>

int __cdecl _getpid(void) {
  return GetCurrentProcessId();
}

int __cdecl getpid(void) {
  return _getpid();
}

int (__cdecl *__MINGW_IMP_SYMBOL(_getpid))(void) = _getpid;
