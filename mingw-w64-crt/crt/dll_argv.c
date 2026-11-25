/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

int __CRTDECL __setargv(void);
int __CRTDECL __wsetargv(void);

int __CRTDECL
#ifdef _UNICODE
__wsetargv (void)
#else
__setargv (void)
#endif
{
  _dowildcard = 1;
  return 0;
}
