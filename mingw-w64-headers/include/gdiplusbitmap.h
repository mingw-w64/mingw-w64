/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSBITMAP_H
#define _GDIPLUSBITMAP_H

inline Image::Image(const WCHAR *filename,WINBOOL useEmbeddedColorManagement) {
  nativeImage = NULL;
  if(useEmbeddedColorManagement) {
    lastResult = DllExports::GdipLoadImageFromFileICM(filename,&nativeImage);
  } else {
    lastResult = DllExports::GdipLoadImageFromFile(filename,&nativeImage);
  }
}

inline Image::Image(IStream *stream,WINBOOL useEmbeddedColorManagement) {
  nativeImage = NULL;
  if(useEmbeddedColorManagement) {
    lastResult = DllExports::GdipLoadImageFromStreamICM(stream,&nativeImage);
  } else {
    lastResult = DllExports::GdipLoadImageFromStream(stream,&nativeImage);
  }
}

inline Image *Image::FromFile(const WCHAR *filename,WINBOOL useEmbeddedColorManagement) { return new Image(filename,useEmbeddedColorManagement); }
inline Image *Image::FromStream(IStream *stream,WINBOOL useEmbeddedColorManagement) { return new Image(stream,useEmbeddedColorManagement); }
inline Image::~Image() { DllExports::GdipDisposeImage(nativeImage); }
inline Image *Image::Clone() {
  GpImage *cloneimage = NULL;
  SetStatus(DllExports::GdipCloneImage(nativeImage,&cloneimage));
  return new Image(cloneimage,lastResult);
}

inline UINT Image::GetEncoderParameterListSize(const CLSID *clsidEncoder) {
  UINT size = 0;
  SetStatus(DllExports::GdipGetEncoderParameterListSize(nativeImage,clsidEncoder,&size));
  return size;
}

inline Status Image::GetEncoderParameterList(const CLSID *clsidEncoder,UINT size,EncoderParameters *buffer) { return SetStatus(DllExports::GdipGetEncoderParameterList(nativeImage,clsidEncoder,size,buffer)); }
inline Status Image::Save(const WCHAR *filename,const CLSID *clsidEncoder,const EncoderParameters *encoderParams) { return SetStatus(DllExports::GdipSaveImageToFile(nativeImage,filename,clsidEncoder,encoderParams)); }
inline Status Image::Save(IStream *stream,const CLSID *clsidEncoder,const EncoderParameters *encoderParams) { return SetStatus(DllExports::GdipSaveImageToStream(nativeImage,stream,clsidEncoder,encoderParams)); }
inline Status Image::SaveAdd(const EncoderParameters *encoderParams) { return SetStatus(DllExports::GdipSaveAdd(nativeImage,encoderParams)); }
inline Status Image::SaveAdd(Image *newImage,const EncoderParameters *encoderParams) {
  if(!newImage) return SetStatus(InvalidParameter);
  return SetStatus(DllExports::GdipSaveAddImage(nativeImage,newImage->nativeImage,encoderParams));
}

inline ImageType Image::GetType() const {
  ImageType type = ImageTypeUnknown;
  SetStatus(DllExports::GdipGetImageType(nativeImage,&type));
  return type;
}

inline Status Image::GetPhysicalDimension(SizeF *size) {
  if(!size) return SetStatus(InvalidParameter);
  REAL width,height;
  Status status;
  status = SetStatus(DllExports::GdipGetImageDimension(nativeImage,&width,&height));
  size->Width = width;
  size->Height = height;
  return status;
}

inline Status Image::GetBounds(RectF *srcRect,Unit *srcUnit) { return SetStatus(DllExports::GdipGetImageBounds(nativeImage,srcRect,srcUnit)); }
inline UINT Image::GetWidth() {
  UINT width = 0;
  SetStatus(DllExports::GdipGetImageWidth(nativeImage,&width));
  return width;
}

inline UINT Image::GetHeight() {
  UINT height = 0;
  SetStatus(DllExports::GdipGetImageHeight(nativeImage,&height));
  return height;
}

inline REAL Image::GetHorizontalResolution() {
  REAL resolution = 0.0f;
  SetStatus(DllExports::GdipGetImageHorizontalResolution(nativeImage,&resolution));
  return resolution;
}

inline REAL Image::GetVerticalResolution() {
  REAL resolution = 0.0f;
  SetStatus(DllExports::GdipGetImageVerticalResolution(nativeImage,&resolution));
  return resolution;
}

inline UINT Image::GetFlags() {
  UINT flags = 0;
  SetStatus(DllExports::GdipGetImageFlags(nativeImage,&flags));
  return flags;
}

inline Status Image::GetRawFormat(GUID *format) { return SetStatus(DllExports::GdipGetImageRawFormat(nativeImage,format)); }
inline PixelFormat Image::GetPixelFormat() {
  PixelFormat format;
  SetStatus(DllExports::GdipGetImagePixelFormat(nativeImage,&format));
  return format;
}

inline INT Image::GetPaletteSize() {
  INT size = 0;
  SetStatus(DllExports::GdipGetImagePaletteSize(nativeImage,&size));
  return size;
}

inline Status Image::GetPalette(ColorPalette *palette,INT size) { return SetStatus(DllExports::GdipGetImagePalette(nativeImage,palette,size)); }
inline Status Image::SetPalette(const ColorPalette *palette) { return SetStatus(DllExports::GdipSetImagePalette(nativeImage,palette)); }
inline Image *Image::GetThumbnailImage(UINT thumbWidth,UINT thumbHeight,GetThumbnailImageAbort callback,VOID *callbackData) {
  GpImage *thumbimage = NULL;
  SetStatus(DllExports::GdipGetImageThumbnail(nativeImage,thumbWidth,thumbHeight,&thumbimage,callback,callbackData));
  Image *newImage = new Image(thumbimage,lastResult);
  if(!newImage) {
    DllExports::GdipDisposeImage(thumbimage);
  }
  return newImage;
}

inline UINT Image::GetFrameDimensionsCount() {
  UINT count = 0;
  SetStatus(DllExports::GdipImageGetFrameDimensionsCount(nativeImage,&count));
  return count;
}

inline Status Image::GetFrameDimensionsList(GUID *dimensionIDs,UINT count) { return SetStatus(DllExports::GdipImageGetFrameDimensionsList(nativeImage,dimensionIDs,count)); }
inline UINT Image::GetFrameCount(const GUID *dimensionID) {
  UINT count = 0;
  SetStatus(DllExports::GdipImageGetFrameCount(nativeImage,dimensionID,&count));
  return count;
}

inline Status Image::SelectActiveFrame(const GUID *dimensionID,UINT frameIndex) { return SetStatus(DllExports::GdipImageSelectActiveFrame(nativeImage,dimensionID,frameIndex)); }
inline Status Image::RotateFlip(RotateFlipType rotateFlipType) { return SetStatus(DllExports::GdipImageRotateFlip(nativeImage,rotateFlipType)); }
inline UINT Image::GetPropertyCount() {
  UINT numProperty = 0;
  SetStatus(DllExports::GdipGetPropertyCount(nativeImage,&numProperty));
  return numProperty;
}

inline Status Image::GetPropertyIdList(UINT numOfProperty,PROPID *list) { return SetStatus(DllExports::GdipGetPropertyIdList(nativeImage,numOfProperty,list)); }
inline UINT Image::GetPropertyItemSize(PROPID propId) {
  UINT size = 0;
  SetStatus(DllExports::GdipGetPropertyItemSize(nativeImage,propId,&size));
  return size;
}

inline Status Image::GetPropertyItem(PROPID propId,UINT propSize,PropertyItem *buffer) { return SetStatus(DllExports::GdipGetPropertyItem(nativeImage,propId,propSize,buffer)); }
inline Status Image::GetPropertySize(UINT *totalBufferSize,UINT *numProperties) { return SetStatus(DllExports::GdipGetPropertySize(nativeImage,totalBufferSize,numProperties)); }
inline Status Image::GetAllPropertyItems(UINT totalBufferSize,UINT numProperties,PropertyItem *allItems) {
  if(!allItems) return SetStatus(InvalidParameter);
  return SetStatus(DllExports::GdipGetAllPropertyItems(nativeImage,totalBufferSize,numProperties,allItems));
}

inline Status Image::RemovePropertyItem(PROPID propId) { return SetStatus(DllExports::GdipRemovePropertyItem(nativeImage,propId)); }
inline Status Image::SetPropertyItem(const PropertyItem *item) { return SetStatus(DllExports::GdipSetPropertyItem(nativeImage,item)); }
inline Status Image::GetLastStatus() const {
  Status lastStatus = lastResult;
  lastResult = Ok;
  return lastStatus;
}

inline Image::Image(GpImage *nativeImage,Status status) {
  SetNativeImage(nativeImage);
  lastResult = status;
}

inline VOID Image::SetNativeImage(GpImage *nativeImage) { this->nativeImage = nativeImage; }
inline Bitmap::Bitmap(const WCHAR *filename,WINBOOL useEmbeddedColorManagement) {
  GpBitmap *bitmap = NULL;
  if(useEmbeddedColorManagement) {
    lastResult = DllExports::GdipCreateBitmapFromFileICM(filename,&bitmap);
  } else {
    lastResult = DllExports::GdipCreateBitmapFromFile(filename,&bitmap);
  }
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(IStream *stream,WINBOOL useEmbeddedColorManagement) {
  GpBitmap *bitmap = NULL;
  if(useEmbeddedColorManagement) {
    lastResult = DllExports::GdipCreateBitmapFromStreamICM(stream,&bitmap);
  } else {
    lastResult = DllExports::GdipCreateBitmapFromStream(stream,&bitmap);
  }
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(INT width,INT height,INT stride,PixelFormat format,BYTE *scan0) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromScan0(width,height,stride,format,scan0,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(INT width,INT height,PixelFormat format) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromScan0(width,height,0,format,NULL,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(INT width,INT height,Graphics *target) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromGraphics(width,height,target->nativeGraphics,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(IDirectDrawSurface7  *surface) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromDirectDrawSurface(surface,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(const BITMAPINFO *gdiBitmapInfo,VOID *gdiBitmapData) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromGdiDib(gdiBitmapInfo,gdiBitmapData,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(HBITMAP hbm,HPALETTE hpal) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromHBITMAP(hbm,hpal,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(HICON hicon) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromHICON(hicon,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap::Bitmap(HINSTANCE hInstance,const WCHAR *bitmapName) {
  GpBitmap *bitmap = NULL;
  lastResult = DllExports::GdipCreateBitmapFromResource(hInstance,bitmapName,&bitmap);
  SetNativeImage(bitmap);
}

inline Bitmap *Bitmap::FromFile(const WCHAR *filename,WINBOOL useEmbeddedColorManagement) { return new Bitmap(filename,useEmbeddedColorManagement); }
inline Bitmap *Bitmap::FromStream(IStream *stream,WINBOOL useEmbeddedColorManagement) { return new Bitmap(stream,useEmbeddedColorManagement); }
inline Bitmap *Bitmap::FromDirectDrawSurface7(IDirectDrawSurface7 *surface) { return new Bitmap(surface); }
inline Bitmap *Bitmap::FromBITMAPINFO(const BITMAPINFO *gdiBitmapInfo,VOID *gdiBitmapData) { return new Bitmap(gdiBitmapInfo,gdiBitmapData); }
inline Bitmap *Bitmap::FromHBITMAP(HBITMAP hbm,HPALETTE hpal) { return new Bitmap(hbm,hpal); }
inline Bitmap *Bitmap::FromHICON(HICON hicon) { return new Bitmap(hicon); }
inline Bitmap *Bitmap::FromResource(HINSTANCE hInstance,const WCHAR *bitmapName) { return new Bitmap(hInstance,bitmapName); }
inline Status Bitmap::GetHBITMAP(const Color &colorBackground,HBITMAP *hbmReturn) { return SetStatus(DllExports::GdipCreateHBITMAPFromBitmap(static_cast<GpBitmap*>(nativeImage),hbmReturn,colorBackground.GetValue())); }
inline Status Bitmap::GetHICON(HICON *hiconReturn) { return SetStatus(DllExports::GdipCreateHICONFromBitmap(static_cast<GpBitmap*>(nativeImage),hiconReturn)); }
inline Bitmap *Bitmap::Clone(const Rect& rect,PixelFormat format) { return Clone(rect.X,rect.Y,rect.Width,rect.Height,format); }
inline Bitmap *Bitmap::Clone(INT x,INT y,INT width,INT height,PixelFormat format) {
  GpBitmap *gpdstBitmap = NULL;
  Bitmap *bitmap;
  lastResult = DllExports::GdipCloneBitmapAreaI(x,y,width,height,format,(GpBitmap *)nativeImage,&gpdstBitmap);
  if(lastResult==Ok) {
    bitmap = new Bitmap(gpdstBitmap);
    if(!bitmap) {
      DllExports::GdipDisposeImage(gpdstBitmap);
    }
    return bitmap;
  } else return NULL;
}

inline Bitmap *Bitmap::Clone(const RectF& rect,PixelFormat format) { return Clone(rect.X,rect.Y,rect.Width,rect.Height,format); }
inline Bitmap *Bitmap::Clone(REAL x,REAL y,REAL width,REAL height,PixelFormat format) {
  GpBitmap *gpdstBitmap = NULL;
  Bitmap *bitmap;
  SetStatus(DllExports::GdipCloneBitmapArea(x,y,width,height,format,(GpBitmap *)nativeImage,&gpdstBitmap));
  if(lastResult==Ok) {
    bitmap = new Bitmap(gpdstBitmap);
    if(!bitmap) {
      DllExports::GdipDisposeImage(gpdstBitmap);
    }
    return bitmap;
  } else return NULL;
}

inline Bitmap::Bitmap(GpBitmap *nativeBitmap) {
  lastResult = Ok;
  SetNativeImage(nativeBitmap);
}

inline Status Bitmap::LockBits(const Rect *rect,UINT flags,PixelFormat format,BitmapData *lockedBitmapData) { return SetStatus(DllExports::GdipBitmapLockBits(static_cast<GpBitmap*>(nativeImage),rect,flags,format,lockedBitmapData)); }
inline Status Bitmap::UnlockBits(BitmapData *lockedBitmapData) { return SetStatus(DllExports::GdipBitmapUnlockBits(static_cast<GpBitmap*>(nativeImage),lockedBitmapData)); }
inline Status Bitmap::GetPixel(INT x,INT y,Color *color) {
  ARGB argb;
  Status status = SetStatus(DllExports::GdipBitmapGetPixel(static_cast<GpBitmap *>(nativeImage),x,y,&argb));
  if(status==Ok) {
    color->SetValue(argb);
  }
  return status;
}

inline Status Bitmap::SetPixel(INT x,INT y,const Color &color) { return SetStatus(DllExports::GdipBitmapSetPixel(static_cast<GpBitmap *>(nativeImage),x,y,color.GetValue())); }
inline Status Bitmap::SetResolution(REAL xdpi,REAL ydpi) { return SetStatus(DllExports::GdipBitmapSetResolution(static_cast<GpBitmap *>(nativeImage),xdpi,ydpi)); }
#endif
