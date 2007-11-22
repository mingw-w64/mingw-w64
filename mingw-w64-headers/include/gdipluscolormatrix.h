/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSCOLORMATRIX_H
#define _GDIPLUSCOLORMATRIX_H

struct ColorMatrix {
  REAL m[5][5];
};

enum ColorMatrixFlags {
  ColorMatrixFlagsDefault = 0,ColorMatrixFlagsSkipGrays = 1,ColorMatrixFlagsAltGray = 2
};

enum ColorAdjustType {
  ColorAdjustTypeDefault,ColorAdjustTypeBitmap,ColorAdjustTypeBrush,ColorAdjustTypePen,ColorAdjustTypeText,ColorAdjustTypeCount,
  ColorAdjustTypeAny
};

struct ColorMap {
  Color oldColor;
  Color newColor;
};
#endif
