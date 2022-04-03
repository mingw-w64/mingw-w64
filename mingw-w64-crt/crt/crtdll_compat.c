/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

/* Define __getmainargs() function via crtdll.dll __GetMainArgs() function */
extern void __cdecl __GetMainArgs(int *argc, char ***argv, char ***envp, int expand_wildcards);
int __cdecl __getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, __UNUSED_PARAM(_startupinfo *startup_info))
{
  __GetMainArgs(argc, argv, envp, expand_wildcards);
  return 0;
}
