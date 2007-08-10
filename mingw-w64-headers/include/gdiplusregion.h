/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSREGION_H
#define _GDIPLUSREGION_H

inline Region::Region() {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegion(&region);
  SetNativeRegion(region);
}

inline Region::Region(const RectF &rect) {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegionRect(&rect,&region);
  SetNativeRegion(region);
}

inline Region::Region(const Rect &rect) {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegionRectI(&rect,&region);
  SetNativeRegion(region);
}

inline Region::Region(const GraphicsPath *path) {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegionPath(path->nativePath,&region);
  SetNativeRegion(region);
}

inline Region::Region(const BYTE *regionData,INT size) {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegionRgnData(regionData,size,&region);
  SetNativeRegion(region);
}

inline Region::Region(HRGN hRgn) {
  GpRegion *region = NULL;
  lastResult = DllExports::GdipCreateRegionHrgn(hRgn,&region);
  SetNativeRegion(region);
}

inline Region *Region::FromHRGN(HRGN hRgn) {
  GpRegion *region = NULL;
  if(DllExports::GdipCreateRegionHrgn(hRgn,&region)==Ok) {
    Region *newRegion = new Region(region);
    if(!newRegion) { DllExports::GdipDeleteRegion(region); }
    return newRegion;
  }
  return NULL;
}

inline Region::~Region() { DllExports::GdipDeleteRegion(nativeRegion); }
inline Region *Region::Clone() const {
  GpRegion *region = NULL;
  SetStatus(DllExports::GdipCloneRegion(nativeRegion,&region));
  return new Region(region);
}

inline Status Region::MakeInfinite() { return SetStatus(DllExports::GdipSetInfinite(nativeRegion)); }
inline Status Region::MakeEmpty() { return SetStatus(DllExports::GdipSetEmpty(nativeRegion)); }
inline Status Region::Intersect(const RectF &rect) { return SetStatus(DllExports::GdipCombineRegionRect(nativeRegion,&rect,CombineModeIntersect)); }
inline Status Region::Intersect(const Rect &rect) { return SetStatus(DllExports::GdipCombineRegionRectI(nativeRegion,&rect,CombineModeIntersect)); }
inline Status Region::Intersect(const GraphicsPath *path) { return SetStatus(DllExports::GdipCombineRegionPath(nativeRegion,path->nativePath,CombineModeIntersect)); }
inline Status Region::Intersect(const Region *region) { return SetStatus(DllExports::GdipCombineRegionRegion(nativeRegion,region->nativeRegion,CombineModeIntersect)); }
inline Status Region::Union(const RectF &rect) { return SetStatus(DllExports::GdipCombineRegionRect(nativeRegion,&rect,CombineModeUnion)); }
inline Status Region::Union(const Rect &rect) { return SetStatus(DllExports::GdipCombineRegionRectI(nativeRegion,&rect,CombineModeUnion)); }
inline Status Region::Union(const GraphicsPath *path) { return SetStatus(DllExports::GdipCombineRegionPath(nativeRegion,path->nativePath,CombineModeUnion)); }
inline Status Region::Union(const Region *region) { return SetStatus(DllExports::GdipCombineRegionRegion(nativeRegion,region->nativeRegion,CombineModeUnion)); }
inline Status Region::Xor(const RectF &rect) { return SetStatus(DllExports::GdipCombineRegionRect(nativeRegion,&rect,CombineModeXor)); }
inline Status Region::Xor(const Rect &rect) { return SetStatus(DllExports::GdipCombineRegionRectI(nativeRegion,&rect,CombineModeXor)); }
inline Status Region::Xor(const GraphicsPath *path) { return SetStatus(DllExports::GdipCombineRegionPath(nativeRegion,path->nativePath,CombineModeXor)); }
inline Status Region::Xor(const Region *region) { return SetStatus(DllExports::GdipCombineRegionRegion(nativeRegion,region->nativeRegion,CombineModeXor)); }
inline Status Region::Exclude(const RectF &rect) { return SetStatus(DllExports::GdipCombineRegionRect(nativeRegion,&rect,CombineModeExclude)); }
inline Status Region::Exclude(const Rect &rect) { return SetStatus(DllExports::GdipCombineRegionRectI(nativeRegion,&rect,CombineModeExclude)); }
inline Status Region::Exclude(const GraphicsPath *path) { return SetStatus(DllExports::GdipCombineRegionPath(nativeRegion,path->nativePath,CombineModeExclude)); }
inline Status Region::Exclude(const Region *region) { return SetStatus(DllExports::GdipCombineRegionRegion(nativeRegion,region->nativeRegion,CombineModeExclude)); }
inline Status Region::Complement(const RectF &rect) { return SetStatus(DllExports::GdipCombineRegionRect(nativeRegion,&rect,CombineModeComplement)); }
inline Status Region::Complement(const Rect &rect) { return SetStatus(DllExports::GdipCombineRegionRectI(nativeRegion,&rect,CombineModeComplement)); }
inline Status Region::Complement(const GraphicsPath *path) { return SetStatus(DllExports::GdipCombineRegionPath(nativeRegion,path->nativePath,CombineModeComplement)); }
inline Status Region::Complement(const Region *region) { return SetStatus(DllExports::GdipCombineRegionRegion(nativeRegion,region->nativeRegion,CombineModeComplement)); }
inline Status Region::Translate(REAL dx,REAL dy) { return SetStatus(DllExports::GdipTranslateRegion(nativeRegion,dx,dy)); }
inline Status Region::Translate(INT dx,INT dy) { return SetStatus(DllExports::GdipTranslateRegionI(nativeRegion,dx,dy)); }
inline Status Region::Transform(const Matrix *matrix) { return SetStatus(DllExports::GdipTransformRegion(nativeRegion,matrix->nativeMatrix)); }
inline Status Region::GetBounds(RectF *rect,const Graphics *g) const { return SetStatus(DllExports::GdipGetRegionBounds(nativeRegion,g->nativeGraphics,rect)); }
inline Status Region::GetBounds(Rect *rect,const Graphics *g) const { return SetStatus(DllExports::GdipGetRegionBoundsI(nativeRegion,g->nativeGraphics,rect)); }
inline HRGN Region::GetHRGN(const Graphics *g) const {
  HRGN hrgn;
  SetStatus(DllExports::GdipGetRegionHRgn(nativeRegion,g->nativeGraphics,&hrgn));
  return hrgn;
}

inline WINBOOL Region::IsEmpty(const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsEmptyRegion(nativeRegion,g->nativeGraphics,&booln));
  return booln;
}

inline WINBOOL Region::IsInfinite(const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsInfiniteRegion(nativeRegion,g->nativeGraphics,&booln));
  return booln;
}

inline WINBOOL Region::Equals(const Region *region,const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsEqualRegion(nativeRegion,region->nativeRegion,g->nativeGraphics,&booln));
  return booln;
}

inline UINT Region::GetDataSize() const {
  UINT bufferSize = 0;
  SetStatus(DllExports::GdipGetRegionDataSize(nativeRegion,&bufferSize));
  return bufferSize;
}

inline Status Region::GetData(BYTE *buffer,UINT bufferSize,UINT *sizeFilled) const { return SetStatus(DllExports::GdipGetRegionData(nativeRegion,buffer,bufferSize,sizeFilled)); }
inline WINBOOL Region::IsVisible(const PointF &point,const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsVisibleRegionPoint(nativeRegion,point.X,point.Y,(!g ? NULL : g->nativeGraphics,&booln)));
  return booln;
}

inline WINBOOL Region::IsVisible(const RectF &rect,const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsVisibleRegionRect(nativeRegion,rect.X,rect.Y,rect.Width,rect.Height,(!g ? NULL : g->nativeGraphics,&booln)));
  return booln;
}

inline WINBOOL Region::IsVisible(const Point &point,const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsVisibleRegionPointI(nativeRegion,point.X,point.Y,(!g ? NULL : g->nativeGraphics,&booln)));
  return booln;
}

inline WINBOOL Region::IsVisible(const Rect &rect,const Graphics *g) const {
  WINBOOL booln = FALSE;
  SetStatus(DllExports::GdipIsVisibleRegionRectI(nativeRegion,rect.X,rect.Y,rect.Width,rect.Height,(!g ? NULL : g->nativeGraphics,&booln)));
  return booln;
}

inline UINT Region::GetRegionScansCount(const Matrix *matrix) const {
  UINT count = 0;
  SetStatus(DllExports::GdipGetRegionScansCount(nativeRegion,&count,matrix->nativeMatrix));
  return count;
}

inline Status Region::GetRegionScans(const Matrix *matrix,RectF *rects,INT *count) const { return SetStatus(DllExports::GdipGetRegionScans(nativeRegion,rects,count,matrix->nativeMatrix)); }
inline Status Region::GetRegionScans(const Matrix *matrix,Rect *rects,INT *count) const { return SetStatus(DllExports::GdipGetRegionScansI(nativeRegion,rects,count,matrix->nativeMatrix)); }
inline Region::Region(GpRegion *nativeRegion) { SetNativeRegion(nativeRegion); }
inline VOID Region::SetNativeRegion(GpRegion *nativeRegion) { this->nativeRegion = nativeRegion; }
inline Status Region::GetLastStatus() const {
  Status lastStatus = lastResult;
  lastResult = Ok;
  return lastStatus;
}

#endif
