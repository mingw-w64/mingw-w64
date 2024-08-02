/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

/* Define __getmainargs() function via msvcrt20.dll __getmainargs() function */
_CRTIMP void __cdecl __msvcrt20_getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, int newmode);
int __cdecl __getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, _startupinfo *startup_info)
{
  __msvcrt20_getmainargs(argc, argv, envp, expand_wildcards, startup_info->newmode);
  return 0;
}
