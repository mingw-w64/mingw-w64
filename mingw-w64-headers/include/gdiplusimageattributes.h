/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSIMAGEATTRIBUTES_H
#define _GDIPLUSIMAGEATTRIBUTES_H

class GpImageAttributes;

class ImageAttributes : public GdiplusBase {
  friend class Graphics;
  friend class TextureBrush;
public:
  ImageAttributes() {
    nativeImageAttr = NULL;
    lastResult = DllExports::GdipCreateImageAttributes(&nativeImageAttr);
  }
  ~ImageAttributes() { DllExports::GdipDisposeImageAttributes(nativeImageAttr); }
  ImageAttributes *Clone() const {
    GpImageAttributes *clone;
    SetStatus(DllExports::GdipCloneImageAttributes(nativeImageAttr,&clone));
    return new ImageAttributes(clone,lastResult);
  }
  Status SetToIdentity(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesToIdentity(nativeImageAttr,type)); }
  Status Reset(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipResetImageAttributes(nativeImageAttr,type)); }
  Status SetColorMatrix(const ColorMatrix *colorMatrix,ColorMatrixFlags mode = ColorMatrixFlagsDefault,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorMatrix(nativeImageAttr,type,TRUE,colorMatrix,NULL,mode)); }
  Status ClearColorMatrix(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorMatrix(nativeImageAttr,type,FALSE,NULL,NULL,ColorMatrixFlagsDefault)); }
  Status SetColorMatrices(const ColorMatrix *colorMatrix,const ColorMatrix *grayMatrix,ColorMatrixFlags mode = ColorMatrixFlagsDefault,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorMatrix(nativeImageAttr,type,TRUE,colorMatrix,grayMatrix,mode)); }
  Status ClearColorMatrices(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorMatrix(nativeImageAttr,type,FALSE,NULL,NULL,ColorMatrixFlagsDefault)); }
  Status SetThreshold(REAL threshold,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesThreshold(nativeImageAttr,type,TRUE,threshold)); }
  Status ClearThreshold(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesThreshold(nativeImageAttr,type,FALSE,0.0)); }
  Status SetGamma(REAL gamma,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesGamma(nativeImageAttr,type,TRUE,gamma)); }
  Status ClearGamma(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesGamma(nativeImageAttr,type,FALSE,0.0)); }
  Status SetNoOp(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesNoOp(nativeImageAttr,type,TRUE)); }
  Status ClearNoOp(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesNoOp(nativeImageAttr,type,FALSE)); }
  Status SetColorKey(const Color &colorLow,const Color &colorHigh,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorKeys(nativeImageAttr,type,TRUE,colorLow.GetValue(),colorHigh.GetValue())); }
  Status ClearColorKey(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesColorKeys(nativeImageAttr,type,FALSE,NULL,NULL)); }
  Status SetOutputChannel(ColorChannelFlags channelFlags,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesOutputChannel(nativeImageAttr,type,TRUE,channelFlags)); }
  Status ClearOutputChannel(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesOutputChannel(nativeImageAttr,type,FALSE,ColorChannelFlagsLast)); }
  Status SetOutputChannelColorProfile(const WCHAR *colorProfileFilename,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesOutputChannelColorProfile(nativeImageAttr,type,TRUE,colorProfileFilename)); }
  Status ClearOutputChannelColorProfile(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesOutputChannelColorProfile(nativeImageAttr,type,FALSE,NULL)); }
  Status SetRemapTable(UINT mapSize,const ColorMap *map,ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesRemapTable(nativeImageAttr,type,TRUE,mapSize,map)); }
  Status ClearRemapTable(ColorAdjustType type = ColorAdjustTypeDefault) { return SetStatus(DllExports::GdipSetImageAttributesRemapTable(nativeImageAttr,type,FALSE,0,NULL)); }
  Status SetBrushRemapTable(UINT mapSize,const ColorMap *map) { return this->SetRemapTable(mapSize,map,ColorAdjustTypeBrush); }
  Status ClearBrushRemapTable() { return this->ClearRemapTable(ColorAdjustTypeBrush); }
  Status SetWrapMode(WrapMode wrap,const Color &color = Color(),WINBOOL clamp = FALSE) {
    ARGB argb = color.GetValue();
    return SetStatus(DllExports::GdipSetImageAttributesWrapMode(nativeImageAttr,wrap,argb,clamp));
  }
  Status GetAdjustedPalette(ColorPalette *colorPalette,ColorAdjustType colorAdjustType) const { return SetStatus(DllExports::GdipGetImageAttributesAdjustedPalette(nativeImageAttr,colorPalette,colorAdjustType)); }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
private:
  ImageAttributes(const ImageAttributes &);
  ImageAttributes& operator=(const ImageAttributes &);
protected:
  ImageAttributes(GpImageAttributes *imageAttr,Status status) {
    SetNativeImageAttr(imageAttr);
    lastResult = status;
  }
  VOID SetNativeImageAttr(GpImageAttributes *nativeImageAttr) { this->nativeImageAttr = nativeImageAttr; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
protected:
  GpImageAttributes *nativeImageAttr;
  mutable Status lastResult;
};
#endif
