/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSPEN_H
#define _GDIPLUSPEN_H

class Pen : public GdiplusBase {
public:
  friend class GraphicsPath;
  friend class Graphics;
  Pen(const Color &color,REAL width = 1.0f) {
    Unit unit = UnitWorld;
    nativePen = NULL;
    lastResult = DllExports::GdipCreatePen1(color.GetValue(),width,unit,&nativePen);
  }
  Pen(const Brush *brush,REAL width = 1.0f) {
    Unit unit = UnitWorld;
    nativePen = NULL;
    lastResult = DllExports::GdipCreatePen2(brush->nativeBrush,width,unit,&nativePen);
  }
  ~Pen() { DllExports::GdipDeletePen(nativePen); }
  Pen *Clone() const {
    GpPen *clonePen = NULL;
    lastResult = DllExports::GdipClonePen(nativePen,&clonePen);
    return new Pen(clonePen,lastResult);
  }
  Status SetWidth(REAL width) { return SetStatus(DllExports::GdipSetPenWidth(nativePen,width)); }
  REAL GetWidth() const {
    REAL width;
    SetStatus(DllExports::GdipGetPenWidth(nativePen,&width));
    return width;
  }
  Status SetLineCap(LineCap startCap,LineCap endCap,DashCap dashCap) { return SetStatus(DllExports::GdipSetPenLineCap197819(nativePen,startCap,endCap,dashCap)); }
  Status SetStartCap(LineCap startCap) { return SetStatus(DllExports::GdipSetPenStartCap(nativePen,startCap)); }
  Status SetEndCap(LineCap endCap) { return SetStatus(DllExports::GdipSetPenEndCap(nativePen,endCap)); }
  Status SetDashCap(DashCap dashCap) { return SetStatus(DllExports::GdipSetPenDashCap197819(nativePen,dashCap)); }
  LineCap GetStartCap() const {
    LineCap startCap;
    SetStatus(DllExports::GdipGetPenStartCap(nativePen,&startCap));
    return startCap;
  }
  LineCap GetEndCap() const {
    LineCap endCap;
    SetStatus(DllExports::GdipGetPenEndCap(nativePen,&endCap));
    return endCap;
  }
  DashCap GetDashCap() const {
    DashCap dashCap;
    SetStatus(DllExports::GdipGetPenDashCap197819(nativePen,&dashCap));
    return dashCap;
  }
  Status SetLineJoin(LineJoin lineJoin) { return SetStatus(DllExports::GdipSetPenLineJoin(nativePen,lineJoin)); }
  LineJoin GetLineJoin() const {
    LineJoin lineJoin;
    SetStatus(DllExports::GdipGetPenLineJoin(nativePen,&lineJoin));
    return lineJoin;
  }
  Status SetCustomStartCap(const CustomLineCap *customCap) {
    GpCustomLineCap *nativeCap = NULL;
    if(customCap) nativeCap = customCap->nativeCap;
    return SetStatus(DllExports::GdipSetPenCustomStartCap(nativePen,nativeCap));
  }
  Status GetCustomStartCap(CustomLineCap *customCap) const {
    if(!customCap) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipGetPenCustomStartCap(nativePen,&(customCap->nativeCap)));
  }
  Status SetCustomEndCap(const CustomLineCap *customCap) {
    GpCustomLineCap *nativeCap = NULL;
    if(customCap) nativeCap = customCap->nativeCap;
    return SetStatus(DllExports::GdipSetPenCustomEndCap(nativePen,nativeCap));
  }
  Status GetCustomEndCap(CustomLineCap *customCap) const {
    if(!customCap) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipGetPenCustomEndCap(nativePen,&(customCap->nativeCap)));
  }
  Status SetMiterLimit(REAL miterLimit) { return SetStatus(DllExports::GdipSetPenMiterLimit(nativePen,miterLimit)); }
  REAL GetMiterLimit() const {
    REAL miterLimit;
    SetStatus(DllExports::GdipGetPenMiterLimit(nativePen,&miterLimit));
    return miterLimit;
  }
  Status SetAlignment(PenAlignment penAlignment) { return SetStatus(DllExports::GdipSetPenMode(nativePen,penAlignment)); }
  PenAlignment GetAlignment() const {
    PenAlignment penAlignment;
    SetStatus(DllExports::GdipGetPenMode(nativePen,&penAlignment));
    return penAlignment;
  }
  Status SetTransform(const Matrix *matrix) { return SetStatus(DllExports::GdipSetPenTransform(nativePen,matrix->nativeMatrix)); }
  Status GetTransform(Matrix *matrix) const { return SetStatus(DllExports::GdipGetPenTransform(nativePen,matrix->nativeMatrix)); }
  Status ResetTransform() { return SetStatus(DllExports::GdipResetPenTransform(nativePen)); }
  Status MultiplyTransform(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyPenTransform(nativePen,matrix->nativeMatrix,order)); }
  Status TranslateTransform(REAL dx,REAL dy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslatePenTransform(nativePen,dx,dy,order)); }
  Status ScaleTransform(REAL sx,REAL sy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScalePenTransform(nativePen,sx,sy,order)); }
  Status RotateTransform(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotatePenTransform(nativePen,angle,order)); }
  PenType GetPenType() const {
    PenType type;
    SetStatus(DllExports::GdipGetPenFillType(nativePen,&type));
    return type;
  }
  Status SetColor(const Color &color) { return SetStatus(DllExports::GdipSetPenColor(nativePen,color.GetValue())); }
  Status SetBrush(const Brush *brush) { return SetStatus(DllExports::GdipSetPenBrushFill(nativePen,brush->nativeBrush)); }
  Status GetColor(Color *color) const {
    if(!color) return SetStatus(InvalidParameter);
    PenType type = GetPenType();
    if(type!=PenTypeSolidColor) return WrongState;
    ARGB argb;
    SetStatus(DllExports::GdipGetPenColor(nativePen,&argb));
    if(lastResult==Ok) color->SetValue(argb);
    return lastResult;
  }
  Brush *GetBrush() const {
    PenType type = GetPenType();
    Brush *brush = NULL;
    switch(type) {
	   case PenTypeSolidColor:
	     brush = new SolidBrush();
	     break;
	   case PenTypeHatchFill:
	     brush = new HatchBrush();
	     break;
	   case PenTypeTextureFill:
	     brush = new TextureBrush();
	     break;
	   case PenTypePathGradient:
	     brush = new Brush();
	     break;
	   case PenTypeLinearGradient:
	     brush = new LinearGradientBrush();
	     break;
	   default:
	     break;
    }
    if(brush) {
      GpBrush *nativeBrush;
      SetStatus(DllExports::GdipGetPenBrushFill(nativePen,&nativeBrush));
      brush->SetNativeBrush(nativeBrush);
    }
    return brush;
  }
  DashStyle GetDashStyle() const {
    DashStyle dashStyle;
    SetStatus(DllExports::GdipGetPenDashStyle(nativePen,&dashStyle));
    return dashStyle;
  }
  Status SetDashStyle(DashStyle dashStyle) { return SetStatus(DllExports::GdipSetPenDashStyle(nativePen,dashStyle)); }
  REAL GetDashOffset() const {
    REAL dashOffset;
    SetStatus(DllExports::GdipGetPenDashOffset(nativePen,&dashOffset));
    return dashOffset;
  }
  Status SetDashOffset(REAL dashOffset) { return SetStatus(DllExports::GdipSetPenDashOffset(nativePen,dashOffset)); }
  Status SetDashPattern(const REAL *dashArray,INT count) { return SetStatus(DllExports::GdipSetPenDashArray(nativePen,dashArray,count)); }
  INT GetDashPatternCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetPenDashCount(nativePen,&count));
    return count;
  }
  Status GetDashPattern(REAL *dashArray,INT count) const {
    if(!dashArray || count <= 0) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipGetPenDashArray(nativePen,dashArray,count));
  }
  Status SetCompoundArray(const REAL *compoundArray,INT count) { return SetStatus(DllExports::GdipSetPenCompoundArray(nativePen,compoundArray,count)); }
  INT GetCompoundArrayCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetPenCompoundCount(nativePen,&count));
    return count;
  }
  Status GetCompoundArray(REAL *compoundArray,INT count) const {
    if(!compoundArray || count <= 0) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipGetPenCompoundArray(nativePen,compoundArray,count));
  }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
private:
  Pen(const Pen &);
  Pen &operator=(const Pen &);
protected:
  Pen(GpPen *nativePen,Status status) {
    lastResult = status;
    SetNativePen(nativePen);
  }
  VOID SetNativePen(GpPen *nativePen) { this->nativePen = nativePen; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    return status;
  }
protected:
  GpPen *nativePen;
  mutable Status lastResult;
};

#endif
