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
   *
   * In the same way was changed also ABI of msvcrt40.dll __wgetmainargs()
   * function. In the original Visual C++ 4.0/4.1 version and in Windows 9x
   * versions, it had void return type. But in all Windows NT versions,
   * it is just redirect to the msvcrt.dll __wgetmainargs() function. And
   * since Windows XP, this function has int return type.
   */
  int local_argc = -1;
  wchar_t **local_argv = NULL;
  wchar_t **local_envp = NULL;
  (void)__msvcrt_wgetmainargs(&local_argc, &local_argv, &local_envp, expand_wildcards, startup_info);
  if (local_argc == -1 || local_argv == NULL || local_envp == NULL)
    return -1;
  *argc = local_argc;
  *argv = local_argv;
  *envp = local_envp;
  return 0;
}
int __cdecl (*__MINGW_IMP_SYMBOL(__wgetmainargs))(int *, wchar_t ***, wchar_t ***, int, _startupinfo *) = __wgetmainargs;
