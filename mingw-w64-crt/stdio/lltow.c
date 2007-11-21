/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <stdlib.h>

wchar_t* lltow(long long _n, wchar_t * _w, int _i)
	{ return _i64tow (_n, _w, _i); } 
