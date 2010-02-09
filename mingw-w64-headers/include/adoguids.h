/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __ADOGUIDS_H__
#define __ADOGUIDS_H__

#define STRING_GUID(l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) l##-##w1##-##w2##-##b1##b2##-##b3##b4##b5##b6##b7##b8
#define GUID_BUILDER(n,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) DEFINE_GUID(n,0x##l,0x##w1,0x##w2,0x##b1,0x##b2,0x##b3,0x##b4,0x##b5,0x##b6,0x##b7,0x##b8)
#define IMMEDIATE_GUID_USE

#define INCLUDING_ADOGUIDS
#include "adogpool.h"

#undef INCLUDING_ADOGUIDS
#undef IMMEDIATE_GUID_USE
#endif
