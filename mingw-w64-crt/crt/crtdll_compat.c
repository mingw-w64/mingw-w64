/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>
#include <math.h>

/* Define __initenv and __winitenv as crtdll.dll does not provide them */
static char ** local__initenv;
static wchar_t ** local__winitenv;
char *** __MINGW_IMP_SYMBOL(__initenv) = &local__initenv;
wchar_t *** __MINGW_IMP_SYMBOL(__winitenv) = &local__winitenv;

/* Define dummy __setusermatherr() function as crtdll.dll does not provide it */
#undef __setusermatherr
void __setusermatherr(__UNUSED_PARAM(int (__cdecl *f)(struct _exception *))) { }

/* Define dummy _lock() and _unlock() functions as crtdll.dll does not provide them */
void __cdecl _lock(int locknum);
void __cdecl _unlock(int locknum);
void __cdecl _lock(__UNUSED_PARAM(int locknum)) { }
void __cdecl _unlock(__UNUSED_PARAM(int locknum)) { }

/* Define __getmainargs() function via crtdll.dll __GetMainArgs() function */
extern void __GetMainArgs(int *argc, char ***argv, char ***envp, int expand_wildcards);
int __cdecl __getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, __UNUSED_PARAM(_startupinfo *startup_info))
{
  __GetMainArgs(argc, argv, envp, expand_wildcards);
  return 0;
}
