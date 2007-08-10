/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSBRUSH_H
#define _GDIPLUSBRUSH_H

class GraphicsPath;

class Brush : public GdiplusBase {
public:
  friend class Pen;
  friend class Graphics;
  virtual ~Brush() { DllExports::GdipDeleteBrush(nativeBrush); }
  virtual Brush *Clone() const {
    GpBrush *brush = NULL;
    SetStatus(DllExports::GdipCloneBrush(nativeBrush,&brush));
    Brush *newBrush = new Brush(brush,lastResult);
    if(!newBrush) {
      DllExports::GdipDeleteBrush(brush);
    }
    return newBrush;
  }
  BrushType GetType() const {
    BrushType type = static_cast<BrushType>(-1);
    SetStatus(DllExports::GdipGetBrushType(nativeBrush,&type));
    return type;
  }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
protected:
  Brush() {
    SetStatus(NotImplemented);
  }
private:
  Brush(const Brush &brush);
  Brush &operator=(const Brush &brush);
protected:
  Brush(GpBrush *nativeBrush,Status status) {
    lastResult = status;
    SetNativeBrush(nativeBrush);
  }
  VOID SetNativeBrush(GpBrush *nativeBrush) { this->nativeBrush = nativeBrush; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
  GpBrush *nativeBrush;
  mutable Status lastResult;
};

class SolidBrush : public Brush {
public:
  friend class Pen;
  SolidBrush(const Color &color) {
    GpSolidFill *brush = NULL;
    lastResult = DllExports::GdipCreateSolidFill(color.GetValue(),&brush);
    SetNativeBrush(brush);
  }
  Status GetColor(Color *color) const {
    ARGB argb;
    if(!color) return SetStatus(InvalidParameter);
    SetStatus(DllExports::GdipGetSolidFillColor((GpSolidFill*)nativeBrush,&argb));
    *color = Color(argb);
    return lastResult;
  }

  Status SetColor(const Color &color) { return SetStatus(DllExports::GdipSetSolidFillColor((GpSolidFill*)nativeBrush,color.GetValue())); }
private:
  SolidBrush(const SolidBrush &);
  SolidBrush &operator=(const SolidBrush &);
protected:
  SolidBrush() { }
};

class TextureBrush : public Brush {
public:
  friend class Pen;
  TextureBrush(Image *image,WrapMode wrapMode = WrapModeTile) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTexture(image->nativeImage,wrapMode,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,WrapMode wrapMode,const RectF &dstRect) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTexture2(image->nativeImage,wrapMode,dstRect.X,dstRect.Y,dstRect.Width,dstRect.Height,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,const RectF &dstRect,const ImageAttributes *imageAttributes = NULL) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTextureIA(image->nativeImage,(imageAttributes)?imageAttributes->nativeImageAttr:NULL,dstRect.X,dstRect.Y,dstRect.Width,dstRect.Height,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,const Rect &dstRect,const ImageAttributes *imageAttributes = NULL) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTextureIAI(image->nativeImage,(imageAttributes)?imageAttributes->nativeImageAttr:NULL,dstRect.X,dstRect.Y,dstRect.Width,dstRect.Height,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,WrapMode wrapMode,const Rect &dstRect) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTexture2I(image->nativeImage,wrapMode,dstRect.X,dstRect.Y,dstRect.Width,dstRect.Height,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,WrapMode wrapMode,REAL dstX,REAL dstY,REAL dstWidth,REAL dstHeight) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTexture2(image->nativeImage,wrapMode,dstX,dstY,dstWidth,dstHeight,&texture);
    SetNativeBrush(texture);
  }
  TextureBrush(Image *image,WrapMode wrapMode,INT dstX,INT dstY,INT dstWidth,INT dstHeight) {
    GpTexture *texture = NULL;
    lastResult = DllExports::GdipCreateTexture2I(image->nativeImage,wrapMode,dstX,dstY,dstWidth,dstHeight,&texture);
    SetNativeBrush(texture);
  }
  Status SetTransform(const Matrix *matrix) { return SetStatus(DllExports::GdipSetTextureTransform((GpTexture*)nativeBrush,matrix->nativeMatrix)); }
  Status GetTransform(Matrix *matrix) const { return SetStatus(DllExports::GdipGetTextureTransform((GpTexture*)nativeBrush,matrix->nativeMatrix)); }
  Status ResetTransform() { return SetStatus(DllExports::GdipResetTextureTransform((GpTexture*)nativeBrush)); }
  Status MultiplyTransform(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyTextureTransform((GpTexture*)nativeBrush,matrix->nativeMatrix,order)); }
  Status TranslateTransform(REAL dx,REAL dy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslateTextureTransform((GpTexture*)nativeBrush,dx,dy,order)); }
  Status ScaleTransform(REAL sx,REAL sy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScaleTextureTransform((GpTexture*)nativeBrush,sx,sy,order)); }
  Status RotateTransform(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotateTextureTransform((GpTexture*)nativeBrush,angle,order)); }
  Status SetWrapMode(WrapMode wrapMode) { return SetStatus(DllExports::GdipSetTextureWrapMode((GpTexture*)nativeBrush,wrapMode)); }
  WrapMode GetWrapMode() const {
    WrapMode wrapMode;
    SetStatus(DllExports::GdipGetTextureWrapMode((GpTexture*)nativeBrush,&wrapMode));
    return wrapMode;
  }
  Image *GetImage() const {
    GpImage *image;
    SetStatus(DllExports::GdipGetTextureImage((GpTexture *)nativeBrush,&image));
    Image *retimage = new Image(image,lastResult);
    if(!retimage) DllExports::GdipDisposeImage(image);
    return retimage;
  }
private:
  TextureBrush(const TextureBrush &);
  TextureBrush &operator=(const TextureBrush &);
protected:
  TextureBrush() { }
};

class LinearGradientBrush : public Brush {
public:
  friend class Pen;
  LinearGradientBrush(const PointF &point1,const PointF &point2,const Color &color1,const Color &color2) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrush(&point1,&point2,color1.GetValue(),color2.GetValue(),WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  LinearGradientBrush(const Point &point1,const Point &point2,const Color &color1,const Color &color2) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrushI(&point1,&point2,color1.GetValue(),color2.GetValue(),WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  LinearGradientBrush(const RectF &rect,const Color &color1,const Color &color2,LinearGradientMode mode) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrushFromRect(&rect,color1.GetValue(),color2.GetValue(),mode,WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  LinearGradientBrush(const Rect &rect,const Color &color1,const Color &color2,LinearGradientMode mode) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrushFromRectI(&rect,color1.GetValue(),color2.GetValue(),mode,WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  LinearGradientBrush(const RectF &rect,const Color &color1,const Color &color2,REAL angle,WINBOOL isAngleScalable = FALSE) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrushFromRectWithAngle(&rect,color1.GetValue(),color2.GetValue(),angle,isAngleScalable,WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  LinearGradientBrush(const Rect &rect,const Color &color1,const Color &color2,REAL angle,WINBOOL isAngleScalable = FALSE) {
    GpLineGradient *brush = NULL;
    lastResult = DllExports::GdipCreateLineBrushFromRectWithAngleI(&rect,color1.GetValue(),color2.GetValue(),angle,isAngleScalable,WrapModeTile,&brush);
    SetNativeBrush(brush);
  }
  Status SetLinearColors(const Color &color1,const Color &color2) { return SetStatus(DllExports::GdipSetLineColors((GpLineGradient*)nativeBrush,color1.GetValue(),color2.GetValue())); }
  Status GetLinearColors(Color *colors) const {
    ARGB argb[2];
    if(!colors) return SetStatus(InvalidParameter);
    SetStatus(DllExports::GdipGetLineColors((GpLineGradient*) nativeBrush,argb));
    if(lastResult==Ok) {
      colors[0] = Color(argb[0]);
      colors[1] = Color(argb[1]);
    }
    return lastResult;
  }
  Status GetRectangle(RectF *rect) const { return SetStatus(DllExports::GdipGetLineRect((GpLineGradient*)nativeBrush,rect)); }
  Status GetRectangle(Rect *rect) const { return SetStatus(DllExports::GdipGetLineRectI((GpLineGradient*)nativeBrush,rect)); }
  Status SetGammaCorrection(WINBOOL useGammaCorrection) { return SetStatus(DllExports::GdipSetLineGammaCorrection((GpLineGradient*)nativeBrush,useGammaCorrection)); }
  WINBOOL GetGammaCorrection() const {
    WINBOOL useGammaCorrection;
    SetStatus(DllExports::GdipGetLineGammaCorrection((GpLineGradient*)nativeBrush,&useGammaCorrection));
    return useGammaCorrection;
  }
  INT GetBlendCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetLineBlendCount((GpLineGradient*) nativeBrush,&count));
    return count;
  }
  Status SetBlend(const REAL *blendFactors,const REAL *blendPositions,INT count) { return SetStatus(DllExports::GdipSetLineBlend((GpLineGradient*) nativeBrush,blendFactors,blendPositions,count)); }
  Status GetBlend(REAL *blendFactors,REAL *blendPositions,INT count) const { return SetStatus(DllExports::GdipGetLineBlend((GpLineGradient*)nativeBrush,blendFactors,blendPositions,count)); }
  INT GetInterpolationColorCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetLinePresetBlendCount((GpLineGradient*) nativeBrush,&count));
    return count;
  }
  Status SetInterpolationColors(const Color *presetColors,const REAL *blendPositions,INT count) {
    if((count <= 0) || !presetColors) return SetStatus(InvalidParameter);
    ARGB *argbs = (ARGB*) new BYTE[count*sizeof(ARGB)];
    if(argbs) {
      for(INT i = 0;i < count;i++) {
	argbs[i] = presetColors[i].GetValue();
      }
      Status status = SetStatus(DllExports::GdipSetLinePresetBlend((GpLineGradient*) nativeBrush,argbs,blendPositions,count));
      delete [] argbs;
      return status;
    } else return SetStatus(OutOfMemory);
  }
  Status GetInterpolationColors(Color *presetColors,REAL *blendPositions,INT count) const {
    if((count <= 0) || !presetColors) return SetStatus(InvalidParameter);
    ARGB *argbs = (ARGB*) new BYTE[count*sizeof(ARGB)];
    if(!argbs) return SetStatus(OutOfMemory);
    Status status = SetStatus(DllExports::GdipGetLinePresetBlend((GpLineGradient*)nativeBrush,argbs,blendPositions,count));
    if(status==Ok) {
      for(INT i = 0;i < count;i++) {
	presetColors[i] = Color(argbs[i]);
      }
    }
    delete [] argbs;
    return status;
  }
  Status SetBlendBellShape(REAL focus,REAL scale = 1.0f) { return SetStatus(DllExports::GdipSetLineSigmaBlend((GpLineGradient*)nativeBrush,focus,scale)); }
  Status SetBlendTriangularShape(REAL focus,REAL scale = 1.0f) { return SetStatus(DllExports::GdipSetLineLinearBlend((GpLineGradient*)nativeBrush,focus,scale)); }
  Status SetTransform(const Matrix *matrix) { return SetStatus(DllExports::GdipSetLineTransform((GpLineGradient*)nativeBrush,matrix->nativeMatrix)); }
  Status GetTransform(Matrix *matrix) const { return SetStatus(DllExports::GdipGetLineTransform((GpLineGradient*)nativeBrush,matrix->nativeMatrix)); }
  Status ResetTransform() { return SetStatus(DllExports::GdipResetLineTransform((GpLineGradient*)nativeBrush)); }
  Status MultiplyTransform(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyLineTransform((GpLineGradient*)nativeBrush,matrix->nativeMatrix,order)); }
  Status TranslateTransform(REAL dx,REAL dy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslateLineTransform((GpLineGradient*)nativeBrush,dx,dy,order)); }
  Status ScaleTransform(REAL sx,REAL sy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScaleLineTransform((GpLineGradient*)nativeBrush,sx,sy,order)); }
  Status RotateTransform(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotateLineTransform((GpLineGradient*)nativeBrush,angle,order)); }
  Status SetWrapMode(WrapMode wrapMode) { return SetStatus(DllExports::GdipSetLineWrapMode((GpLineGradient*)nativeBrush,wrapMode)); }
  WrapMode GetWrapMode() const {
    WrapMode wrapMode;
    SetStatus(DllExports::GdipGetLineWrapMode((GpLineGradient*) nativeBrush,&wrapMode));
    return wrapMode;
  }
private:
  LinearGradientBrush(const LinearGradientBrush &);
  LinearGradientBrush &operator=(const LinearGradientBrush &);
protected:
  LinearGradientBrush() { }
};

class HatchBrush : public Brush {
public:
  friend class Pen;
  HatchBrush(HatchStyle hatchStyle,const Color &foreColor,const Color &backColor = Color()) {
    GpHatch *brush = NULL;
    lastResult = DllExports::GdipCreateHatchBrush(hatchStyle,foreColor.GetValue(),backColor.GetValue(),&brush);
    SetNativeBrush(brush);
  }
  HatchStyle GetHatchStyle() const {
    HatchStyle hatchStyle;
    SetStatus(DllExports::GdipGetHatchStyle((GpHatch*)nativeBrush,&hatchStyle));
    return hatchStyle;
  }
  Status GetForegroundColor(Color *color) const {
    ARGB argb;
    if(!color) return SetStatus(InvalidParameter);
    Status status = SetStatus(DllExports::GdipGetHatchForegroundColor((GpHatch*)nativeBrush,&argb));
    color->SetValue(argb);
    return status;
  }
  Status GetBackgroundColor(Color *color) const {
    ARGB argb;
    if(!color) return SetStatus(InvalidParameter);
    Status status = SetStatus(DllExports::GdipGetHatchBackgroundColor((GpHatch*)nativeBrush,&argb));
    color->SetValue(argb);
    return status;
  }
private:
  HatchBrush(const HatchBrush &);
  HatchBrush &operator=(const HatchBrush &);
protected:
  HatchBrush() { }
};
#endif
