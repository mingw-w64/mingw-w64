/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <_mingw.h>

/* Define 64-bit _filelengthi64() function via 32-bit _filelength() function */
_CRTIMP long __cdecl _filelength(int _FileHandle);
__int64 __cdecl _filelengthi64(int _FileHandle);
__int64 __cdecl _filelengthi64(int _FileHandle)
{
  return _filelength(_FileHandle);
}
__int64 (__cdecl *__MINGW_IMP_SYMBOL(_filelengthi64))(int _FileHandle) = _filelengthi64;
