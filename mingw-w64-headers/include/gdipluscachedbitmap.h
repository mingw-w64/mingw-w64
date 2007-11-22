/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSCACHEDBITMAP_H
#define _GDIPLUSCACHEDBITMAP_H

inline CachedBitmap::CachedBitmap(Bitmap *bitmap,Graphics *graphics) {
  nativeCachedBitmap = NULL;
  lastResult = DllExports::GdipCreateCachedBitmap((GpBitmap *)bitmap->nativeImage,graphics->nativeGraphics,&nativeCachedBitmap);
}
inline CachedBitmap::~CachedBitmap() { DllExports::GdipDeleteCachedBitmap(nativeCachedBitmap); }
inline Status CachedBitmap::GetLastStatus() const {
  Status lastStatus = lastResult;
  lastResult = Ok;
  return (lastStatus);
}
#endif
