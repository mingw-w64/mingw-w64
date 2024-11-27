/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

/* Define __wgetmainargs() function via msvcrt.dll __wgetmainargs() function */
_CRTIMP int __cdecl __msvcrt_wgetmainargs(int *argc, wchar_t ***argv, wchar_t ***envp, int expand_wildcards, _startupinfo *startup_info);
int __cdecl __wgetmainargs(int *argc, wchar_t ***argv, wchar_t ***envp, int expand_wildcards, _startupinfo *startup_info)
{
  /*
   * ABI of msvcrt.dll __wgetmainargs() function was changed in Windows XP.
   * In Windows 2000 and older versions of msvcrt.dll, including the original
   * Visual C++ 6.0 msvcrt.dll version, __wgetmainargs() has void return type
   * and it terminate process on failure. Since Windows XP this function has
   * int return value and returns -1 on failure. It is up to the caller to
   * terminate process. As int return value on i386 is stored in the eax
   * register we can call this function from C even with wrong return value in
   * declaration and ignoring it return value. This function does not touch
   * argc/argv/envp arguments on error, so we can use this fact to detect
   * failure independently of return value ABI.
   */
  *argc = -1;
  *argv = NULL;
  *envp = NULL;
  (void)__msvcrt_wgetmainargs(argc, argv, envp, expand_wildcards, startup_info);
  if (*argc == -1 || *argv == NULL || *envp == NULL)
    return -1;
  return 0;
}
