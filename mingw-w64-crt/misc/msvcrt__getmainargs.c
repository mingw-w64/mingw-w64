/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

/* Define __getmainargs() function via msvcrt.dll __getmainargs() function */
_CRTIMP int __cdecl __msvcrt_getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, _startupinfo *startup_info);
int __cdecl __getmainargs(int *argc, char ***argv, char ***envp, int expand_wildcards, _startupinfo *startup_info)
{
  /*
   * ABI of msvcrt.dll __getmainargs() function was changed in Windows XP.
   * In Windows 2000 and older versions of msvcrt.dll, including the original
   * Visual C++ 6.0 msvcrt.dll version, __getmainargs() has void return type
   * and it terminate process on failure. Since Windows XP this function has
   * int return value and returns -1 on failure. It is up to the caller to
   * terminate process. As int return value on i386 is stored in the eax
   * register we can call this function from C even with wrong return value in
   * declaration and ignoring it return value. This function does not touch
   * argc/argv/envp arguments on error, so we can use this fact to detect
   * failure independently of return value ABI.
   *
   * In the same way was changed also ABI of msvcrt40.dll __getmainargs()
   * function. In the original Visual C++ 4.0/4.1 version and in Windows 9x
   * versions, it had void return type. But in all Windows NT versions,
   * it is just redirect to the msvcrt.dll __getmainargs() function. And
   * since Windows XP, this function has int return type.
   */
  int local_argc = -1;
  char **local_argv = NULL;
  char **local_envp = NULL;
  (void)__msvcrt_getmainargs(&local_argc, &local_argv, &local_envp, expand_wildcards, startup_info);
  if (local_argc == -1 || local_argv == NULL || local_envp == NULL)
    return -1;
  *argc = local_argc;
  *argv = local_argv;
  *envp = local_envp;
  return 0;
}
int __cdecl (*__MINGW_IMP_SYMBOL(__getmainargs))(int *, char ***, char ***, int, _startupinfo *) = __getmainargs;
