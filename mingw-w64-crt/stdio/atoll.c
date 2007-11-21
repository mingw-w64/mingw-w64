/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <stdlib.h>

long long atoll (const char * _c)
	{ return _atoi64 (_c); }
