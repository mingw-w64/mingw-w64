/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include "mb_wc_common.h"
#include <wchar.h>
#include <stdio.h>
#include <windows.h>

wint_t btowc (int c)
{
  if (c == EOF)
    return (WEOF);
  else
    {
      unsigned char ch = c;
      wchar_t wc = WEOF;
      MultiByteToWideChar (get_codepage(), MB_ERR_INVALID_CHARS,
			   (char*)&ch, 1, &wc, 1);
      return wc;
    }
}
