/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSMETAHEADER_H
#define _GDIPLUSMETAHEADER_H

typedef struct ENHMETAHEADER3 {
  DWORD iType;
  DWORD nSize;
  RECTL rclBounds;
  RECTL rclFrame;
  DWORD dSignature;
  DWORD nVersion;
  DWORD nBytes;
  DWORD nRecords;
  WORD nHandles;
  WORD sReserved;
  DWORD nDescription;
  DWORD offDescription;
  DWORD nPalEntries;
  SIZEL szlDevice;
  SIZEL szlMillimeters;
} ENHMETAHEADER3;

#include <pshpack2.h>

typedef struct PWMFRect16 {
  INT16 Left;
  INT16 Top;
  INT16 Right;
  INT16 Bottom;
} PWMFRect16;

typedef struct WmfPlaceableFileHeader {
  UINT32 Key;
  INT16 Hmf;
  PWMFRect16 BoundingBox;
  INT16 Inch;
  UINT32 Reserved;
  INT16 Checksum;
} WmfPlaceableFileHeader;

#include <poppack.h>

#define GDIP_EMFPLUSFLAGS_DISPLAY 0x00000001

class MetafileHeader {
public:
  MetafileType Type;
  UINT Size;
  UINT Version;
  UINT EmfPlusFlags;
  REAL DpiX;
  REAL DpiY;
  INT X;
  INT Y;
  INT Width;
  INT Height;
  union {
    METAHEADER WmfHeader;
    ENHMETAHEADER3 EmfHeader;
  };
  INT EmfPlusHeaderSize;
  INT LogicalDpiX;
  INT LogicalDpiY;
public:
  MetafileType GetType() const { return Type; }
  UINT GetMetafileSize() const { return Size; }
  UINT GetVersion() const { return Version; }
  UINT GetEmfPlusFlags() const { return EmfPlusFlags; }
  REAL GetDpiX() const { return DpiX; }
  REAL GetDpiY() const { return DpiY; }
  VOID GetBounds(Rect *rect) const {
    rect->X = X;
    rect->Y = Y;
    rect->Width = Width;
    rect->Height = Height;
  }
  WINBOOL IsWmf() const { return ((Type==MetafileTypeWmf) || (Type==MetafileTypeWmfPlaceable)); }
  WINBOOL IsWmfPlaceable() const { return (Type==MetafileTypeWmfPlaceable); }
  WINBOOL IsEmf() const { return (Type==MetafileTypeEmf); }
  WINBOOL IsEmfOrEmfPlus() const { return (Type >= MetafileTypeEmf); }
  WINBOOL IsEmfPlus() const { return (Type >= MetafileTypeEmfPlusOnly); }
  WINBOOL IsEmfPlusDual() const { return (Type==MetafileTypeEmfPlusDual); }
  WINBOOL IsEmfPlusOnly() const { return (Type==MetafileTypeEmfPlusOnly); }
  WINBOOL IsDisplay() const { return (IsEmfPlus() && ((EmfPlusFlags & GDIP_EMFPLUSFLAGS_DISPLAY)!=0)); }
  const METAHEADER *GetWmfHeader() const {
    if(IsWmf()) return &WmfHeader;
    return NULL;
  }
  const ENHMETAHEADER3 *GetEmfHeader() const {
    if(IsEmfOrEmfPlus()) return &EmfHeader;
    return NULL;
  }
};

#endif
