/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_WCHAR_INTERNAL_H
#define __MINGW_WCHAR_INTERNAL_H
#include <wchar.h>

size_t __cdecl __mingw_mbrtowc_cp(wchar_t * __restrict__ _DstCh,const char * __restrict__ _SrcCh,size_t _SizeInBytes,mbstate_t * __restrict__ _State, unsigned _Cp, int _MbCurMax);
#endif
