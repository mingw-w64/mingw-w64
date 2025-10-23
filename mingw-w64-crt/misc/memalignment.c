/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <stdlib.h>

size_t memalignment(const void *p)
{
    return (size_t)p & -(size_t)p;
}
