/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSLINECAPS_H
#define _GDIPLUSLINECAPS_H

inline CustomLineCap::CustomLineCap(const GraphicsPath *fillPath,const GraphicsPath *strokePath,LineCap baseCap,REAL baseInset) {
  nativeCap = NULL;
  GpPath *nativeFillPath = NULL;
  GpPath *nativeStrokePath = NULL;
  if(fillPath) nativeFillPath = fillPath->nativePath;
  if(strokePath) nativeStrokePath = strokePath->nativePath;
  lastResult = DllExports::GdipCreateCustomLineCap(nativeFillPath,nativeStrokePath,baseCap,baseInset,&nativeCap);
}

inline CustomLineCap::CustomLineCap() {
  nativeCap = NULL;
  lastResult = Ok;
}

inline CustomLineCap::~CustomLineCap() { DllExports::GdipDeleteCustomLineCap(nativeCap); }
inline Status CustomLineCap::SetStrokeCaps(LineCap startCap,LineCap endCap) { return SetStatus(DllExports::GdipSetCustomLineCapStrokeCaps(nativeCap,startCap,endCap)); }
inline Status CustomLineCap::GetStrokeCaps(LineCap *startCap,LineCap *endCap) const { return SetStatus(DllExports::GdipGetCustomLineCapStrokeCaps(nativeCap,startCap,endCap)); }
inline Status CustomLineCap::SetStrokeJoin(LineJoin lineJoin) { return SetStatus(DllExports::GdipSetCustomLineCapStrokeJoin(nativeCap,lineJoin)); }
inline LineJoin CustomLineCap::GetStrokeJoin() const {
  LineJoin lineJoin;
  SetStatus(DllExports::GdipGetCustomLineCapStrokeJoin(nativeCap,&lineJoin));
  return lineJoin;
}

inline Status CustomLineCap::SetBaseCap(LineCap baseCap) { return SetStatus(DllExports::GdipSetCustomLineCapBaseCap(nativeCap,baseCap)); }
inline LineCap CustomLineCap::GetBaseCap() const {
  LineCap baseCap;
  SetStatus(DllExports::GdipGetCustomLineCapBaseCap(nativeCap,&baseCap));
  return baseCap;
}

inline Status CustomLineCap::SetBaseInset(REAL inset) { return SetStatus(DllExports::GdipSetCustomLineCapBaseInset(nativeCap,inset)); }
inline REAL CustomLineCap::GetBaseInset() const {
  REAL inset;
  SetStatus(DllExports::GdipGetCustomLineCapBaseInset(nativeCap,&inset));
  return inset;
}

inline Status CustomLineCap::SetWidthScale(REAL widthScale) { return SetStatus(DllExports::GdipSetCustomLineCapWidthScale(nativeCap,widthScale)); }
inline REAL CustomLineCap::GetWidthScale() const {
  REAL widthScale;
  SetStatus(DllExports::GdipGetCustomLineCapWidthScale(nativeCap,&widthScale));
  return widthScale;
}

inline CustomLineCap *CustomLineCap::Clone() const {
  GpCustomLineCap *newNativeLineCap = NULL;
  SetStatus(DllExports::GdipCloneCustomLineCap(nativeCap,&newNativeLineCap));
  if(lastResult==Ok) {
    CustomLineCap *newLineCap = new CustomLineCap(newNativeLineCap,lastResult);
    if(!newLineCap) {
      SetStatus(DllExports::GdipDeleteCustomLineCap(newNativeLineCap));
    }
    return newLineCap;
  }
  return NULL;
}

inline Status CustomLineCap::GetLastStatus() const {
  Status lastStatus = lastResult;
  lastResult = Ok;
  return (lastStatus);
}

class AdjustableArrowCap : public CustomLineCap {
public:
  AdjustableArrowCap(REAL height,REAL width,WINBOOL isFilled = TRUE) {
    GpAdjustableArrowCap *cap = NULL;
    lastResult = DllExports::GdipCreateAdjustableArrowCap(height,width,isFilled,&cap);
    SetNativeCap(cap);
  }
  Status SetHeight(REAL height) {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    return SetStatus(DllExports::GdipSetAdjustableArrowCapHeight(cap,height));
  }
  REAL GetHeight() const {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    REAL height;
    SetStatus(DllExports::GdipGetAdjustableArrowCapHeight(cap,&height));
    return height;
  }
  Status SetWidth(REAL width) {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    return SetStatus(DllExports::GdipSetAdjustableArrowCapWidth(cap,width));
  }
  REAL GetWidth() const {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    REAL width;
    SetStatus(DllExports::GdipGetAdjustableArrowCapWidth(cap,&width));
    return width;
  }
  Status SetMiddleInset(REAL middleInset) {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    return SetStatus(DllExports::GdipSetAdjustableArrowCapMiddleInset(cap,middleInset));
  }
  REAL GetMiddleInset() const {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    REAL middleInset;
    SetStatus(DllExports::GdipGetAdjustableArrowCapMiddleInset(cap,&middleInset));
    return middleInset;
  }
  Status SetFillState(WINBOOL isFilled) {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    return SetStatus(DllExports::GdipSetAdjustableArrowCapFillState(cap,isFilled));
  }
  WINBOOL IsFilled() const {
    GpAdjustableArrowCap *cap = (GpAdjustableArrowCap*) nativeCap;
    WINBOOL isFilled;
    SetStatus(DllExports::GdipGetAdjustableArrowCapFillState(cap,&isFilled));
    return isFilled;
  }
private:
  AdjustableArrowCap(const AdjustableArrowCap &);
  AdjustableArrowCap &operator=(const AdjustableArrowCap &);
};
#endif
