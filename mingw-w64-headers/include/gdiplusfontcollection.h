/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSFONTCOLL_H
#define _GDIPLUSFONTCOLL_H

inline FontCollection::FontCollection() { nativeFontCollection = NULL; }
inline FontCollection::~FontCollection() { }
inline INT FontCollection::GetFamilyCount() const {
  INT numFound = 0;
  lastResult = DllExports::GdipGetFontCollectionFamilyCount(nativeFontCollection,&numFound);
  return numFound;
}

inline Status FontCollection::GetFamilies(INT numSought,FontFamily *gpfamilies,INT *numFound) const {
  if(numSought<=0 || !gpfamilies || !numFound) return SetStatus(InvalidParameter);
  *numFound = 0;
  GpFontFamily **nativeFamilyList = new GpFontFamily*[numSought];
  if(!nativeFamilyList) return SetStatus(OutOfMemory);
  Status status = SetStatus(DllExports::GdipGetFontCollectionFamilyList(nativeFontCollection,numSought,nativeFamilyList,numFound));
  if(status==Ok) {
    for(INT i = 0;i < *numFound;i++) {
      DllExports::GdipCloneFontFamily(nativeFamilyList[i],&gpfamilies[i].nativeFamily);
    }
  }
  delete [] nativeFamilyList;
  return status;
}

inline Status FontCollection::GetLastStatus () const { return lastResult; }
inline Status FontCollection::SetStatus(Status status) const {
  lastResult = status;
  return lastResult;
}

inline InstalledFontCollection::InstalledFontCollection() {
  nativeFontCollection = NULL;
  lastResult = DllExports::GdipNewInstalledFontCollection(&nativeFontCollection);
}

inline InstalledFontCollection::~InstalledFontCollection() { }
inline PrivateFontCollection::PrivateFontCollection() {
  nativeFontCollection = NULL;
  lastResult = DllExports::GdipNewPrivateFontCollection(&nativeFontCollection);
}

inline PrivateFontCollection::~PrivateFontCollection() { DllExports::GdipDeletePrivateFontCollection(&nativeFontCollection); }
inline Status PrivateFontCollection::AddFontFile(const WCHAR *filename) { return SetStatus(DllExports::GdipPrivateAddFontFile(nativeFontCollection,filename)); }
inline Status PrivateFontCollection::AddMemoryFont(const void *memory,INT length) { return SetStatus(DllExports::GdipPrivateAddMemoryFont(nativeFontCollection,memory,length)); }
#endif
