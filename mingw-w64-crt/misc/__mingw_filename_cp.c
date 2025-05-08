/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#include <locale.h>

unsigned int __cdecl __mingw_filename_cp(void)
{
  return (___lc_codepage_func() == CP_UTF8)
         ? CP_UTF8
         : AreFileApisANSI() ? CP_ACP : CP_OEMCP;
}
