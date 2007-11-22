/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUS_FONT_FAMILY_H
#define _GDIPLUS_FONT_FAMILY_H

inline FontFamily::FontFamily() : nativeFamily(NULL),lastResult(Ok) { }
inline FontFamily::FontFamily(const WCHAR *name,const FontCollection *fontCollection) {
  nativeFamily = NULL;
  lastResult = DllExports::GdipCreateFontFamilyFromName(name,fontCollection ? fontCollection->nativeFontCollection : NULL,&nativeFamily);
}

inline FontFamily::FontFamily(GpFontFamily *nativeOrig,Status status) {
  lastResult = status;
  nativeFamily = nativeOrig;
}

inline const FontFamily *FontFamily::GenericSansSerif() {
  if(GenericSansSerifFontFamily!=NULL) return GenericSansSerifFontFamily;
  GenericSansSerifFontFamily = (FontFamily*) GenericSansSerifFontFamilyBuffer;
  GenericSansSerifFontFamily->lastResult = DllExports::GdipGetGenericFontFamilySansSerif(&(GenericSansSerifFontFamily->nativeFamily));
  return GenericSansSerifFontFamily;
}

inline const FontFamily *FontFamily::GenericSerif() {
  if(GenericSerifFontFamily!=NULL) return GenericSerifFontFamily;
  GenericSerifFontFamily = (FontFamily*) GenericSerifFontFamilyBuffer;
  GenericSerifFontFamily->lastResult = DllExports::GdipGetGenericFontFamilySerif(&(GenericSerifFontFamily->nativeFamily));
  return GenericSerifFontFamily;
}

inline const FontFamily *FontFamily::GenericMonospace() {
  if(GenericMonospaceFontFamily!=NULL) return GenericMonospaceFontFamily;
  GenericMonospaceFontFamily = (FontFamily*) GenericMonospaceFontFamilyBuffer;
  GenericMonospaceFontFamily->lastResult = DllExports::GdipGetGenericFontFamilyMonospace(&(GenericMonospaceFontFamily->nativeFamily));
  return GenericMonospaceFontFamily;
}

inline FontFamily::~FontFamily() { DllExports::GdipDeleteFontFamily (nativeFamily); }
inline FontFamily *FontFamily::Clone() const {
  GpFontFamily *clonedFamily = NULL;
  SetStatus(DllExports::GdipCloneFontFamily (nativeFamily,&clonedFamily));
  return new FontFamily(clonedFamily,lastResult);
}

inline Status FontFamily::GetFamilyName(WCHAR name[LF_FACESIZE],LANGID language) const { return SetStatus(DllExports::GdipGetFamilyName(nativeFamily,name,language)); }
inline WINBOOL FontFamily::IsStyleAvailable(INT style) const {
  WINBOOL StyleAvailable;
  Status status;
  status = SetStatus(DllExports::GdipIsStyleAvailable(nativeFamily,style,&StyleAvailable));
  if(status!=Ok) StyleAvailable = FALSE;
  return StyleAvailable;
}

inline UINT16 FontFamily::GetEmHeight(INT style) const {
  UINT16 EmHeight;
  SetStatus(DllExports::GdipGetEmHeight(nativeFamily,style,&EmHeight));
  return EmHeight;
}

inline UINT16 FontFamily::GetCellAscent(INT style) const {
  UINT16 CellAscent;
  SetStatus(DllExports::GdipGetCellAscent(nativeFamily,style,&CellAscent));
  return CellAscent;
}

inline UINT16 FontFamily::GetCellDescent(INT style) const {
  UINT16 CellDescent;
  SetStatus(DllExports::GdipGetCellDescent(nativeFamily,style,&CellDescent));
  return CellDescent;
}

inline UINT16 FontFamily::GetLineSpacing(INT style) const {
  UINT16 LineSpacing;
  SetStatus(DllExports::GdipGetLineSpacing(nativeFamily,style,&LineSpacing));
  return LineSpacing;
}

inline Status FontFamily::GetLastStatus() const {
  Status lastStatus = lastResult;
  lastResult = Ok;
  return lastStatus;
}

inline Status FontFamily::SetStatus(Status status) const {
  if(status!=Ok) return (lastResult = status);
  else return status;
}
#endif
