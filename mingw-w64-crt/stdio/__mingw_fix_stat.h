/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_FIX_STAT_H
#define __MINGW_FIX_STAT_H

char* __mingw_fix_stat_path (const char* _path);
wchar_t* __mingw_fix_wstat_path (const wchar_t* _path);

#endif
