/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#undef __lc_codepage
__declspec(dllimport) extern unsigned int __lc_codepage;

static inline
unsigned int get_codepage (void)
{
	return __lc_codepage;
}
