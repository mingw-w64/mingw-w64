/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <string.h>

int
strcasecmp (const char *sz1,const char *sz2)
{
  return _stricmp (sz1,sz2);
}
