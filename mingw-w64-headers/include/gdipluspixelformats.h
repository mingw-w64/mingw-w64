/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSPIXELFORMATS_H
#define _GDIPLUSPIXELFORMATS_H

typedef DWORD ARGB;
typedef DWORDLONG ARGB64;

#define ALPHA_SHIFT 24
#define RED_SHIFT 16
#define GREEN_SHIFT 8
#define BLUE_SHIFT 0
#define ALPHA_MASK ((ARGB) 0xff << ALPHA_SHIFT)

typedef INT PixelFormat;

#define PixelFormatIndexed 0x00010000
#define PixelFormatGDI 0x00020000
#define PixelFormatAlpha 0x00040000
#define PixelFormatPAlpha 0x00080000
#define PixelFormatExtended 0x00100000
#define PixelFormatCanonical 0x00200000

#define PixelFormatUndefined 0
#define PixelFormatDontCare 0

#define PixelFormat1bppIndexed (1 | (1 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define PixelFormat4bppIndexed (2 | (4 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define PixelFormat8bppIndexed (3 | (8 << 8) | PixelFormatIndexed | PixelFormatGDI)
#define PixelFormat16bppGrayScale (4 | (16 << 8) | PixelFormatExtended)
#define PixelFormat16bppRGB555 (5 | (16 << 8) | PixelFormatGDI)
#define PixelFormat16bppRGB565 (6 | (16 << 8) | PixelFormatGDI)
#define PixelFormat16bppARGB1555 (7 | (16 << 8) | PixelFormatAlpha | PixelFormatGDI)
#define PixelFormat24bppRGB (8 | (24 << 8) | PixelFormatGDI)
#define PixelFormat32bppRGB (9 | (32 << 8) | PixelFormatGDI)
#define PixelFormat32bppARGB (10 | (32 << 8) | PixelFormatAlpha | PixelFormatGDI | PixelFormatCanonical)
#define PixelFormat32bppPARGB (11 | (32 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatGDI)
#define PixelFormat48bppRGB (12 | (48 << 8) | PixelFormatExtended)
#define PixelFormat64bppARGB (13 | (64 << 8) | PixelFormatAlpha | PixelFormatCanonical | PixelFormatExtended)
#define PixelFormat64bppPARGB (14 | (64 << 8) | PixelFormatAlpha | PixelFormatPAlpha | PixelFormatExtended)
#define PixelFormatMax 15

inline UINT GetPixelFormatSize(PixelFormat pixfmt) { return (pixfmt >> 8) & 0xff; }
inline WINBOOL IsIndexedPixelFormat(PixelFormat pixfmt) { return (pixfmt & PixelFormatIndexed)!=0; }
inline WINBOOL IsAlphaPixelFormat(PixelFormat pixfmt) { return (pixfmt & PixelFormatAlpha)!=0; }
inline WINBOOL IsExtendedPixelFormat(PixelFormat pixfmt) { return (pixfmt & PixelFormatExtended)!=0; }
inline WINBOOL IsCanonicalPixelFormat(PixelFormat pixfmt) { return (pixfmt & PixelFormatCanonical)!=0; }

enum PaletteFlags {
  PaletteFlagsHasAlpha = 0x0001,PaletteFlagsGrayScale = 0x0002,PaletteFlagsHalftone = 0x0004
};

struct ColorPalette {
public:
  UINT Flags;
  UINT Count;
  ARGB Entries[1];
};
#endif
