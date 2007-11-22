/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSIMAGECODEC_H
#define _GDIPLUSIMAGECODEC_H

inline Status GetImageDecodersSize(UINT *numDecoders,UINT *size) { return DllExports::GdipGetImageDecodersSize(numDecoders,size); }
inline Status GetImageDecoders(UINT numDecoders,UINT size,ImageCodecInfo *decoders) { return DllExports::GdipGetImageDecoders(numDecoders,size,decoders); }
inline Status GetImageEncodersSize(UINT *numEncoders,UINT *size) { return DllExports::GdipGetImageEncodersSize(numEncoders,size); }
inline Status GetImageEncoders(UINT numEncoders,UINT size,ImageCodecInfo *encoders) { return DllExports::GdipGetImageEncoders(numEncoders,size,encoders); }

#endif
