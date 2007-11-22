/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSBASE_H
#define _GDIPLUSBASE_H

class GdiplusBase {
public:
  void (operator delete)(void *in_pVoid) { DllExports::GdipFree(in_pVoid); }
  void *(operator new)(size_t in_size) { return DllExports::GdipAlloc(in_size); }
  void (operator delete[])(void *in_pVoid) { DllExports::GdipFree(in_pVoid); }
  void *(operator new[])(size_t in_size) { return DllExports::GdipAlloc(in_size); }
};
#endif
