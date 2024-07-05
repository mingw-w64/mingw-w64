/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <internal.h>

#undef __badioinfo
static ioinfo __badioinfo = {
  .osfhnd = -1,
  .osfile = 0,
  .pipech = 10,
  .lockinitflag = 0,
};
ioinfo * __MINGW_IMP_SYMBOL(__badioinfo) = &__badioinfo;
