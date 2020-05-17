/*
      .Some useful path tools.
        .ASCII only for now.
   .Written by Ray Donnelly in 2014.
   .Licensed under CC0 (and anything.
  .else you need to license it under).
      .No warranties whatsoever.
  .email: <mingw.android@gmail.com>.
 */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#if defined(__linux__) || defined(__CYGWIN__) || defined(__MSYS__)
#include <alloca.h>
#endif
#include <unistd.h>

/* If you don't define this, then get_executable_path()
   can only use argv[0] which will often not work well */
#define IMPLEMENT_SYS_GET_EXECUTABLE_PATH

#if defined(IMPLEMENT_SYS_GET_EXECUTABLE_PATH)
#if defined(__linux__) || defined(__CYGWIN__) || defined(__MSYS__)
/* Nothing needed, unistd.h is enough. */
#elif defined(__APPLE__)
#include <mach-o/dyld.h>
#elif defined(_WIN32)
// widl can't include the normal Windows headers due to providing its own winnt.h (and others).
#ifdef __x86_64__
__attribute__((dllimport)) long GetModuleFileNameA (long hModule, void* lpFilename, long nSize);
#else
__attribute__((dllimport)) long __attribute__((__stdcall__)) GetModuleFileNameA (long hModule, void* lpFilename, long nSize);
#endif
#endif
#else
#define PATH_MAX 260
#endif /* defined(IMPLEMENT_SYS_GET_EXECUTABLE_PATH) */

#include "pathtools.h"

int
get_executable_path(char const * argv0, char * result, ssize_t max_size)
{
  char * system_result = (char *) alloca (max_size);
  ssize_t system_result_size = -1;
  ssize_t result_size = -1;

  if (system_result != NULL)
  {
#if defined(IMPLEMENT_SYS_GET_EXECUTABLE_PATH)
#if defined(__linux__) || defined(__CYGWIN__) || defined(__MSYS__)
    system_result_size = readlink("/proc/self/exe", system_result, max_size);
#elif defined(__APPLE__)
    uint32_t bufsize = (uint32_t)max_size;
    if (_NSGetExecutablePath(system_result, &bufsize) == 0)
    {
      system_result_size = strlen (system_result);
    }
#elif defined(_WIN32)
    unsigned long bufsize = (unsigned long)max_size;
    system_result_size = GetModuleFileNameA(0, system_result, bufsize);
    if (system_result_size == 0 || system_result_size == (ssize_t)bufsize)
    {
      /* Error, possibly not enough space. */
      system_result_size = -1;
    }
    else
    {
      /* Early conversion to unix slashes instead of more changes
         everywhere else .. */
      char * winslash;
      system_result[system_result_size] = '\0';
      while ((winslash = strchr (system_result, '\\')) != NULL)
      {
        *winslash = '/';
      }
    }
#else
#warning "Don't know how to get executable path on this system"
#endif
#endif /* defined(IMPLEMENT_SYS_GET_EXECUTABLE_PATH) */
  }
  /* Use argv0 as a default in-case of failure */
  if (system_result_size != -1)
  {
    strncpy (result, system_result, system_result_size);
    result[system_result_size] = '\0';
  }
  else
  {
    if (argv0 != NULL)
    {
      strncpy (result, argv0, max_size);
      char *slash;
      while ((slash = strchr(result, '\\')) != NULL) {
        *slash++ = '/';
        }
      result[max_size-1] = '\0';
    }
    else
    {
      result[0] = '\0';
    }
  }
  result_size = strlen (result);
  return result_size;
}
