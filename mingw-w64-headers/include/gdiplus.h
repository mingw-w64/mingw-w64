/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUS_H
#define _GDIPLUS_H

struct IDirectDrawSurface7;

typedef signed short INT16;
typedef unsigned short UINT16;

#include <pshpack8.h>

namespace Gdiplus {
  namespace DllExports {
#include "gdiplusmem.h"
  };
#include "gdiplusbase.h"
#include "gdiplusenums.h"
#include "gdiplustypes.h"
#include "gdiplusinit.h"
#include "gdipluspixelformats.h"
#include "gdipluscolor.h"
#include "gdiplusmetaheader.h"
#include "gdiplusimaging.h"
#include "gdipluscolormatrix.h"
#include "gdiplusgpstubs.h"
#include "gdiplusheaders.h"

  namespace DllExports {
#include "gdiplusflat.h"
  };
#include "gdiplusimageattributes.h"
#include "gdiplusmatrix.h"
#include "gdiplusbrush.h"
#include "gdipluspen.h"
#include "gdiplusstringFormat.h"
#include "gdipluspath.h"
#include "gdipluslinecaps.h"
#include "gdiplusmetafile.h"
#include "gdiplusgraphics.h"
#include "gdipluscachedbitmap.h"
#include "gdiplusregion.h"
#include "gdiplusfontcollection.h"
#include "gdiplusfontfamily.h"
#include "gdiplusfont.h"
#include "gdiplusbitmap.h"
#include "gdiplusimagecodec.h"
};

#include <poppack.h>
#endif
