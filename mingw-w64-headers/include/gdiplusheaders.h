/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSHEADERS_H
#define _GDIPLUSHEADERS_H

class Region : public GdiplusBase {
public:
  friend class Graphics;
  Region();
  Region(const RectF &rect);
  Region(const Rect &rect);
  Region(const GraphicsPath *path);
  Region(const BYTE *regionData,INT size);
  Region(HRGN hRgn);
  static Region *FromHRGN(HRGN hRgn);
  ~Region();
  Region *Clone() const;
  Status MakeInfinite();
  Status MakeEmpty();
  UINT GetDataSize() const;
  Status GetData(BYTE *buffer,UINT bufferSize,UINT *sizeFilled = NULL) const;
  Status Intersect(const Rect &rect);
  Status Intersect(const RectF &rect);
  Status Intersect(const GraphicsPath *path);
  Status Intersect(const Region *region);
  Status Union(const Rect &rect);
  Status Union(const RectF &rect);
  Status Union(const GraphicsPath *path);
  Status Union(const Region *region);
  Status Xor(const Rect &rect);
  Status Xor(const RectF &rect);
  Status Xor(const GraphicsPath *path);
  Status Xor(const Region *region);
  Status Exclude(const Rect &rect);
  Status Exclude(const RectF &rect);
  Status Exclude(const GraphicsPath *path);
  Status Exclude(const Region *region);
  Status Complement(const Rect &rect);
  Status Complement(const RectF &rect);
  Status Complement(const GraphicsPath *path);
  Status Complement(const Region *region);
  Status Translate(REAL dx,REAL dy);
  Status Translate(INT dx,INT dy);
  Status Transform(const Matrix *matrix);
  Status GetBounds(Rect *rect,const Graphics *g) const;
  Status GetBounds(RectF *rect,const Graphics *g) const;
  HRGN GetHRGN(const Graphics *g) const;
  WINBOOL IsEmpty(const Graphics *g) const;
  WINBOOL IsInfinite(const Graphics *g) const;
  WINBOOL IsVisible(INT x,INT y,const Graphics *g = NULL) const { return IsVisible(Point(x,y),g); }
  WINBOOL IsVisible(const Point& point,const Graphics *g = NULL) const;
  WINBOOL IsVisible(REAL x,REAL y,const Graphics *g = NULL) const { return IsVisible(PointF(x,y),g); }
  WINBOOL IsVisible(const PointF& point,const Graphics *g = NULL) const;
  WINBOOL IsVisible(INT x,INT y,INT width,INT height,const Graphics *g) const { return IsVisible(Rect(x,y,width,height),g); }
  WINBOOL IsVisible(const Rect &rect,const Graphics *g = NULL) const;
  WINBOOL IsVisible(REAL x,REAL y,REAL width,REAL height,const Graphics *g = NULL) const { return IsVisible(RectF(x,y,width,height),g); }
  WINBOOL IsVisible(const RectF &rect,const Graphics *g = NULL) const;
  WINBOOL Equals(const Region *region,const Graphics *g) const;
  UINT GetRegionScansCount(const Matrix *matrix) const;
  Status GetRegionScans(const Matrix *matrix,RectF *rects,INT *count) const;
  Status GetRegionScans(const Matrix *matrix,Rect *rects,INT *count) const;
  Status GetLastStatus() const;
private:
  Region(const Region &region);
  Region &operator=(const Region &region);
protected:
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
  Region(GpRegion *nativeRegion);
  VOID SetNativeRegion(GpRegion *nativeRegion);
protected:
  GpRegion *nativeRegion;
  mutable Status lastResult;
};

class FontFamily : public GdiplusBase {
public:
  friend class Font;
  friend class Graphics;
  friend class GraphicsPath;
  friend class FontCollection;
  FontFamily();
  FontFamily(const WCHAR *name,const FontCollection *fontCollection = NULL);
  ~FontFamily();
  static const FontFamily *GenericSansSerif();
  static const FontFamily *GenericSerif();
  static const FontFamily *GenericMonospace();
  Status GetFamilyName(WCHAR name[LF_FACESIZE],LANGID language = 0) const;
  FontFamily *Clone() const;
  WINBOOL IsAvailable() const { return (nativeFamily!=NULL); };
  WINBOOL IsStyleAvailable(INT style) const;
  UINT16 GetEmHeight(INT style) const;
  UINT16 GetCellAscent(INT style) const;
  UINT16 GetCellDescent(INT style) const;
  UINT16 GetLineSpacing(INT style) const;
  Status GetLastStatus() const;
private:
  FontFamily(const FontFamily &);
  FontFamily& operator=(const FontFamily &);
protected:
  Status SetStatus(Status status) const;
  FontFamily(GpFontFamily *nativeFamily,Status status);
protected:
  GpFontFamily *nativeFamily;
  mutable Status lastResult;
};

static FontFamily *GenericSansSerifFontFamily = NULL;
static FontFamily *GenericSerifFontFamily = NULL;
static FontFamily *GenericMonospaceFontFamily = NULL;
static BYTE GenericSansSerifFontFamilyBuffer[sizeof(FontFamily)] = {0};
static BYTE GenericSerifFontFamilyBuffer [sizeof(FontFamily)] = {0};
static BYTE GenericMonospaceFontFamilyBuffer[sizeof(FontFamily)] = {0};

class Font : public GdiplusBase {
public:
  friend class Graphics;
  Font(HDC hdc);
  Font(HDC hdc,const LOGFONTA *logfont);
  Font(HDC hdc,const LOGFONTW *logfont);
  Font(HDC hdc,const HFONT hfont);
  Font(const FontFamily *family,REAL emSize,INT style = FontStyleRegular,Unit unit = UnitPoint);
  Font(const WCHAR *familyName,REAL emSize,INT style = FontStyleRegular,Unit unit = UnitPoint,const FontCollection *fontCollection = NULL);
  Status GetLogFontA(const Graphics *g,LOGFONTA *logfontA) const;
  Status GetLogFontW(const Graphics *g,LOGFONTW *logfontW) const;
  Font *Clone() const;
  ~Font();
  WINBOOL IsAvailable() const;
  INT GetStyle() const;
  REAL GetSize() const;
  Unit GetUnit() const;
  Status GetLastStatus() const;
  REAL GetHeight(const Graphics *graphics) const;
  REAL GetHeight(REAL dpi) const;
  Status GetFamily(FontFamily *family) const;
private:
  Font(const Font &);
  Font &operator=(const Font &);
protected:
  Font(GpFont *font,Status status);
  VOID SetNativeFont(GpFont *Font);
  Status SetStatus(Status status) const;
protected:
  GpFont *nativeFont;
  mutable Status lastResult;
};

class FontCollection : public GdiplusBase {
public:
  friend class FontFamily;
  FontCollection();
  virtual ~FontCollection();
  INT GetFamilyCount() const;
  Status GetFamilies(INT numSought,FontFamily *gpfamilies,INT *numFound) const;
  Status GetLastStatus() const;
private:
  FontCollection(const FontCollection &);
  FontCollection& operator=(const FontCollection &);
protected:
  Status SetStatus(Status status) const;
  GpFontCollection *nativeFontCollection;
  mutable Status lastResult;
};

class InstalledFontCollection : public FontCollection {
public:
  InstalledFontCollection();
  ~InstalledFontCollection();
private:
  InstalledFontCollection(const InstalledFontCollection &);
  InstalledFontCollection& operator=(const InstalledFontCollection &);
protected:
  Status SetStatus(Status status) const;
};

class PrivateFontCollection : public FontCollection {
public:
  PrivateFontCollection();
  ~PrivateFontCollection();
  Status AddFontFile(const WCHAR *filename);
  Status AddMemoryFont(const VOID *memory,INT length);
private:
  PrivateFontCollection(const PrivateFontCollection &);
  PrivateFontCollection& operator=(const PrivateFontCollection &);
};

class Image : public GdiplusBase {
public:
  friend class Brush;
  friend class TextureBrush;
  friend class Graphics;
  Image(const WCHAR *filename,WINBOOL useEmbeddedColorManagement = FALSE);
  Image(IStream *stream,WINBOOL useEmbeddedColorManagement = FALSE);
  static Image *FromFile(const WCHAR *filename,WINBOOL useEmbeddedColorManagement = FALSE);
  static Image *FromStream(IStream *stream,WINBOOL useEmbeddedColorManagement = FALSE);
  virtual ~Image();
  virtual Image *Clone();
  Status Save(const WCHAR *filename,const CLSID *clsidEncoder,const EncoderParameters *encoderParams = NULL);
  Status Save(IStream *stream,const CLSID *clsidEncoder,const EncoderParameters *encoderParams = NULL);
  Status SaveAdd(const EncoderParameters *encoderParams);
  Status SaveAdd(Image *newImage,const EncoderParameters *encoderParams);
  ImageType GetType() const;
  Status GetPhysicalDimension(SizeF *size);
  Status GetBounds(RectF *srcRect,Unit *srcUnit);
  UINT GetWidth();
  UINT GetHeight();
  REAL GetHorizontalResolution();
  REAL GetVerticalResolution();
  UINT GetFlags();
  Status GetRawFormat(GUID *format);
  PixelFormat GetPixelFormat();
  INT GetPaletteSize();
  Status GetPalette(ColorPalette *palette,INT size);
  Status SetPalette(const ColorPalette *palette);
  Image *GetThumbnailImage(UINT thumbWidth,UINT thumbHeight,GetThumbnailImageAbort callback = NULL,VOID *callbackData = NULL);
  UINT GetFrameDimensionsCount();
  Status GetFrameDimensionsList(GUID *dimensionIDs,UINT count);
  UINT GetFrameCount(const GUID *dimensionID);
  Status SelectActiveFrame(const GUID *dimensionID,UINT frameIndex);
  Status RotateFlip(RotateFlipType rotateFlipType);
  UINT GetPropertyCount();
  Status GetPropertyIdList(UINT numOfProperty,PROPID *list);
  UINT GetPropertyItemSize(PROPID propId);
  Status GetPropertyItem(PROPID propId,UINT propSize,PropertyItem *buffer);
  Status GetPropertySize(UINT *totalBufferSize,UINT *numProperties);
  Status GetAllPropertyItems(UINT totalBufferSize,UINT numProperties,PropertyItem *allItems);
  Status RemovePropertyItem(PROPID propId);
  Status SetPropertyItem(const PropertyItem *item);
  UINT GetEncoderParameterListSize(const CLSID *clsidEncoder);
  Status GetEncoderParameterList(const CLSID *clsidEncoder,UINT size,EncoderParameters *buffer);
  Status GetLastStatus() const;
protected:
  Image() {}
  Image(GpImage *nativeImage,Status status);
  VOID SetNativeImage(GpImage *nativeImage);
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
  GpImage *nativeImage;
  mutable Status lastResult;
  mutable Status loadStatus;
private:
  Image(const Image &C);
  Image &operator=(const Image &C);
};

class Bitmap : public Image {
public:
  friend class Image;
  friend class CachedBitmap;
  Bitmap(const WCHAR *filename,WINBOOL useEmbeddedColorManagement = FALSE);
  Bitmap(IStream *stream,WINBOOL useEmbeddedColorManagement = FALSE);
  static Bitmap *FromFile(const WCHAR *filename,WINBOOL useEmbeddedColorManagement = FALSE);
  static Bitmap *FromStream(IStream *stream,WINBOOL useEmbeddedColorManagement = FALSE);
  Bitmap(INT width,INT height,INT stride,PixelFormat format,BYTE *scan0);
  Bitmap(INT width,INT height,PixelFormat format = PixelFormat32bppARGB);
  Bitmap(INT width,INT height,Graphics *target);
  Bitmap *Clone(const Rect &rect,PixelFormat format);
  Bitmap *Clone(INT x,INT y,INT width,INT height,PixelFormat format);
  Bitmap *Clone(const RectF &rect,PixelFormat format);
  Bitmap *Clone(REAL x,REAL y,REAL width,REAL height,PixelFormat format);
  Status LockBits(const Rect *rect,UINT flags,PixelFormat format,BitmapData *lockedBitmapData);
  Status UnlockBits(BitmapData *lockedBitmapData);
  Status GetPixel(INT x,INT y,Color *color);
  Status SetPixel(INT x,INT y,const Color &color);
  Status SetResolution(REAL xdpi,REAL ydpi);
  Bitmap(IDirectDrawSurface7 *surface);
  Bitmap(const BITMAPINFO *gdiBitmapInfo,VOID *gdiBitmapData);
  Bitmap(HBITMAP hbm,HPALETTE hpal);
  Bitmap(HICON hicon);
  Bitmap(HINSTANCE hInstance,const WCHAR *bitmapName);
  static Bitmap *FromDirectDrawSurface7(IDirectDrawSurface7 *surface);
  static Bitmap *FromBITMAPINFO(const BITMAPINFO *gdiBitmapInfo,VOID *gdiBitmapData);
  static Bitmap *FromHBITMAP(HBITMAP hbm,HPALETTE hpal);
  static Bitmap *FromHICON(HICON hicon);
  static Bitmap *FromResource(HINSTANCE hInstance,const WCHAR *bitmapName);
  Status GetHBITMAP(const Color& colorBackground,HBITMAP *hbmReturn);
  Status GetHICON(HICON *hicon);
private:
  Bitmap(const Bitmap &);
  Bitmap &operator=(const Bitmap &);
protected:
  Bitmap(GpBitmap *nativeBitmap);
};

class CustomLineCap : public GdiplusBase {
public:
  friend class Pen;
  CustomLineCap(const GraphicsPath *fillPath,const GraphicsPath *strokePath,LineCap baseCap = LineCapFlat,REAL baseInset = 0);
  virtual ~CustomLineCap();
  CustomLineCap *Clone() const;
  Status SetStrokeCap(LineCap strokeCap) { return SetStrokeCaps(strokeCap,strokeCap); }
  Status SetStrokeCaps(LineCap startCap,LineCap endCap);
  Status GetStrokeCaps(LineCap *startCap,LineCap *endCap) const;
  Status SetStrokeJoin(LineJoin lineJoin);
  LineJoin GetStrokeJoin() const;
  Status SetBaseCap(LineCap baseCap);
  LineCap GetBaseCap() const;
  Status SetBaseInset(REAL inset);
  REAL GetBaseInset() const;
  Status SetWidthScale(REAL widthScale);
  REAL GetWidthScale() const;
  Status GetLastStatus() const;
protected:
  CustomLineCap();
private:
  CustomLineCap(const CustomLineCap &);
  CustomLineCap& operator=(const CustomLineCap &);
protected:
  CustomLineCap(GpCustomLineCap *nativeCap,Status status) {
    lastResult = status;
    SetNativeCap(nativeCap);
  }
  VOID SetNativeCap(GpCustomLineCap *nativeCap) { this->nativeCap = nativeCap; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
protected:
  GpCustomLineCap *nativeCap;
  mutable Status lastResult;
};

class CachedBitmap : public GdiplusBase {
  friend Graphics;
public:
  CachedBitmap(Bitmap *bitmap,Graphics *graphics);
  virtual ~CachedBitmap();
  Status GetLastStatus() const;
private:
  CachedBitmap(const CachedBitmap &);
  CachedBitmap& operator=(const CachedBitmap &);
protected:
  GpCachedBitmap *nativeCachedBitmap;
  mutable Status lastResult;
};

#endif
