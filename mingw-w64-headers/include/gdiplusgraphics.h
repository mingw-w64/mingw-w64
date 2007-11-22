/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSGRAPHICS_H
#define _GDIPLUSGRAPHICS_H

class Graphics : public GdiplusBase {
public:
  friend class Region;
  friend class GraphicsPath;
  friend class Image;
  friend class Bitmap;
  friend class Metafile;
  friend class Font;
  friend class FontFamily;
  friend class FontCollection;
  friend class CachedBitmap;
  static Graphics *FromHDC(HDC hdc) { return new Graphics(hdc); }
  static Graphics *FromHDC(HDC hdc,HANDLE hdevice) { return new Graphics(hdc,hdevice); }
  static Graphics *FromHWND(HWND hwnd,WINBOOL icm = FALSE) { return new Graphics(hwnd,icm); }
  static Graphics *FromImage(Image *image) { return new Graphics(image); }
  Graphics(HDC hdc) {
    GpGraphics *graphics = NULL;
    lastResult = DllExports::GdipCreateFromHDC(hdc,&graphics);
    SetNativeGraphics(graphics);
  }
  Graphics(HDC hdc,HANDLE hdevice) {
    GpGraphics *graphics = NULL;
    lastResult = DllExports::GdipCreateFromHDC2(hdc,hdevice,&graphics);
    SetNativeGraphics(graphics);
  }
  Graphics(HWND hwnd,WINBOOL icm = FALSE) {
    GpGraphics *graphics = NULL;
    if(icm) {
      lastResult = DllExports::GdipCreateFromHWNDICM(hwnd,&graphics);
    } else {
      lastResult = DllExports::GdipCreateFromHWND(hwnd,&graphics);
    }
    SetNativeGraphics(graphics);
  }
  Graphics(Image *image) {
    GpGraphics *graphics = NULL;
    if(image!=NULL) {
      lastResult = DllExports::GdipGetImageGraphicsContext(image->nativeImage,&graphics);
    }
    SetNativeGraphics(graphics);
  }
  ~Graphics() {
    DllExports::GdipDeleteGraphics(nativeGraphics);
  }
  VOID Flush(FlushIntention intention = FlushIntentionFlush) {
    DllExports::GdipFlush(nativeGraphics,intention);
  }
  HDC GetHDC() {
    HDC hdc = NULL;
    SetStatus(DllExports::GdipGetDC(nativeGraphics,&hdc));
    return hdc;
  }
  VOID ReleaseHDC(HDC hdc) { SetStatus(DllExports::GdipReleaseDC(nativeGraphics,hdc)); }
  Status SetRenderingOrigin(INT x,INT y) { return SetStatus(DllExports::GdipSetRenderingOrigin(nativeGraphics,x,y)); }
  Status GetRenderingOrigin(INT *x,INT *y) const { return SetStatus(DllExports::GdipGetRenderingOrigin(nativeGraphics,x,y)); }
  Status SetCompositingMode(CompositingMode compositingMode) { return SetStatus(DllExports::GdipSetCompositingMode(nativeGraphics,compositingMode)); }
  CompositingMode GetCompositingMode() const {
    CompositingMode mode;
    SetStatus(DllExports::GdipGetCompositingMode(nativeGraphics,&mode));
    return mode;
  }
  Status SetCompositingQuality(CompositingQuality compositingQuality) { return SetStatus(DllExports::GdipSetCompositingQuality(nativeGraphics,compositingQuality)); }
  CompositingQuality GetCompositingQuality() const {
    CompositingQuality quality;
    SetStatus(DllExports::GdipGetCompositingQuality(nativeGraphics,&quality));
    return quality;
  }
  Status SetTextRenderingHint(TextRenderingHint newMode) { return SetStatus(DllExports::GdipSetTextRenderingHint(nativeGraphics,newMode)); }
  TextRenderingHint GetTextRenderingHint() const {
    TextRenderingHint hint;
    SetStatus(DllExports::GdipGetTextRenderingHint(nativeGraphics,&hint));
    return hint;
  }
  Status SetTextContrast(UINT contrast) { return SetStatus(DllExports::GdipSetTextContrast(nativeGraphics,contrast)); }
  UINT GetTextContrast() const {
    UINT contrast;
    SetStatus(DllExports::GdipGetTextContrast(nativeGraphics,&contrast));
    return contrast;
  }
  InterpolationMode GetInterpolationMode() const {
    InterpolationMode mode = InterpolationModeInvalid;
    SetStatus(DllExports::GdipGetInterpolationMode(nativeGraphics,&mode));
    return mode;
  }
  Status SetInterpolationMode(InterpolationMode interpolationMode) { return SetStatus(DllExports::GdipSetInterpolationMode(nativeGraphics,interpolationMode)); }
  SmoothingMode GetSmoothingMode() const {
    SmoothingMode smoothingMode = SmoothingModeInvalid;
    SetStatus(DllExports::GdipGetSmoothingMode(nativeGraphics,&smoothingMode));
    return smoothingMode;
  }
  Status SetSmoothingMode(SmoothingMode smoothingMode) { return SetStatus(DllExports::GdipSetSmoothingMode(nativeGraphics,smoothingMode)); }
  PixelOffsetMode GetPixelOffsetMode() const {
    PixelOffsetMode pixelOffsetMode = PixelOffsetModeInvalid;
    SetStatus(DllExports::GdipGetPixelOffsetMode(nativeGraphics,&pixelOffsetMode));
    return pixelOffsetMode;
  }
  Status SetPixelOffsetMode(PixelOffsetMode pixelOffsetMode) { return SetStatus(DllExports::GdipSetPixelOffsetMode(nativeGraphics,pixelOffsetMode)); }
  Status SetTransform(const Matrix *matrix) { return SetStatus(DllExports::GdipSetWorldTransform(nativeGraphics,matrix->nativeMatrix)); }
  Status ResetTransform() { return SetStatus(DllExports::GdipResetWorldTransform(nativeGraphics)); }
  Status MultiplyTransform(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyWorldTransform(nativeGraphics,matrix->nativeMatrix,order)); }
  Status TranslateTransform(REAL dx,REAL dy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslateWorldTransform(nativeGraphics,dx,dy,order)); }
  Status ScaleTransform(REAL sx,REAL sy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScaleWorldTransform(nativeGraphics,sx,sy,order)); }
  Status RotateTransform(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotateWorldTransform(nativeGraphics,angle,order)); }
  Status GetTransform(Matrix *matrix) const { return SetStatus(DllExports::GdipGetWorldTransform(nativeGraphics,matrix->nativeMatrix)); }
  Status SetPageUnit(Unit unit) { return SetStatus(DllExports::GdipSetPageUnit(nativeGraphics,unit)); }
  Status SetPageScale(REAL scale) { return SetStatus(DllExports::GdipSetPageScale(nativeGraphics,scale)); }
  Unit GetPageUnit() const {
    Unit unit;
    SetStatus(DllExports::GdipGetPageUnit(nativeGraphics,&unit));
    return unit;
  }
  REAL GetPageScale() const {
    REAL scale;
    SetStatus(DllExports::GdipGetPageScale(nativeGraphics,&scale));
    return scale;
  }
  REAL GetDpiX() const {
    REAL dpi;
    SetStatus(DllExports::GdipGetDpiX(nativeGraphics,&dpi));
    return dpi;
  }
  REAL GetDpiY() const {
    REAL dpi;
    SetStatus(DllExports::GdipGetDpiY(nativeGraphics,&dpi));
    return dpi;
  }
  Status TransformPoints(CoordinateSpace destSpace,CoordinateSpace srcSpace,PointF *pts,INT count) const { return SetStatus(DllExports::GdipTransformPoints(nativeGraphics,destSpace,srcSpace,pts,count)); }
  Status TransformPoints(CoordinateSpace destSpace,CoordinateSpace srcSpace,Point *pts,INT count) const { return SetStatus(DllExports::GdipTransformPointsI(nativeGraphics,destSpace,srcSpace,pts,count)); }
  Status GetNearestColor(Color *color) const {
    if(!color) return SetStatus(InvalidParameter);
    ARGB argb = color->GetValue();
    Status status = SetStatus(DllExports::GdipGetNearestColor(nativeGraphics,&argb));
    color->SetValue(argb);
    return status;
  }
  Status DrawLine(const Pen *pen,REAL x1,REAL y1,REAL x2,REAL y2) { return SetStatus(DllExports::GdipDrawLine(nativeGraphics,pen->nativePen,x1,y1,x2,y2)); }
  Status DrawLine(const Pen *pen,const PointF &pt1,const PointF &pt2) { return DrawLine(pen,pt1.X,pt1.Y,pt2.X,pt2.Y); }
  Status DrawLines(const Pen *pen,const PointF *points,INT count) { return SetStatus(DllExports::GdipDrawLines(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawLine(const Pen *pen,INT x1,INT y1,INT x2,INT y2) { return SetStatus(DllExports::GdipDrawLineI(nativeGraphics,pen->nativePen,x1,y1,x2,y2)); }
  Status DrawLine(const Pen *pen,const Point &pt1,const Point &pt2) { return DrawLine(pen,pt1.X,pt1.Y,pt2.X,pt2.Y); }
  Status DrawLines(const Pen *pen,const Point *points,INT count) { return SetStatus(DllExports::GdipDrawLinesI(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawArc(const Pen *pen,REAL x,REAL y,REAL width,REAL height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipDrawArc(nativeGraphics,pen->nativePen,x,y,width,height,startAngle,sweepAngle)); }
  Status DrawArc(const Pen *pen,const RectF &rect,REAL startAngle,REAL sweepAngle) { return DrawArc(pen,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status DrawArc(const Pen *pen,INT x,INT y,INT width,INT height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipDrawArcI(nativeGraphics,pen->nativePen,x,y,width,height,startAngle,sweepAngle)); }
  Status DrawArc(const Pen *pen,const Rect &rect,REAL startAngle,REAL sweepAngle) { return DrawArc(pen,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status DrawBezier(const Pen *pen,REAL x1,REAL y1,REAL x2,REAL y2,REAL x3,REAL y3,REAL x4,REAL y4) { return SetStatus(DllExports::GdipDrawBezier(nativeGraphics,pen->nativePen,x1,y1,x2,y2,x3,y3,x4,y4)); }
  Status DrawBezier(const Pen *pen,const PointF &pt1,const PointF &pt2,const PointF &pt3,const PointF &pt4) { return DrawBezier(pen,pt1.X,pt1.Y,pt2.X,pt2.Y,pt3.X,pt3.Y,pt4.X,pt4.Y); }
  Status DrawBeziers(const Pen *pen,const PointF *points,INT count) { return SetStatus(DllExports::GdipDrawBeziers(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawBezier(const Pen *pen,INT x1,INT y1,INT x2,INT y2,INT x3,INT y3,INT x4,INT y4) { return SetStatus(DllExports::GdipDrawBezierI(nativeGraphics,pen->nativePen,x1,y1,x2,y2,x3,y3,x4,y4)); }
  Status DrawBezier(const Pen *pen,const Point &pt1,const Point &pt2,const Point &pt3,const Point &pt4) { return DrawBezier(pen,pt1.X,pt1.Y,pt2.X,pt2.Y,pt3.X,pt3.Y,pt4.X,pt4.Y); }
  Status DrawBeziers(const Pen *pen,const Point *points,INT count) { return SetStatus(DllExports::GdipDrawBeziersI(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawRectangle(const Pen *pen,const RectF &rect) { return DrawRectangle(pen,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawRectangle(const Pen *pen,REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipDrawRectangle(nativeGraphics,pen->nativePen,x,y,width,height)); }
  Status DrawRectangles(const Pen *pen,const RectF *rects,INT count) { return SetStatus(DllExports::GdipDrawRectangles(nativeGraphics,pen->nativePen,rects,count)); }
  Status DrawRectangle(const Pen *pen,const Rect &rect) { return DrawRectangle(pen,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawRectangle(const Pen *pen,INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipDrawRectangleI(nativeGraphics,pen->nativePen,x,y,width,height)); }
  Status DrawRectangles(const Pen *pen,const Rect *rects,INT count) { return SetStatus(DllExports::GdipDrawRectanglesI(nativeGraphics,pen->nativePen,rects,count)); }
  Status DrawEllipse(const Pen *pen,const RectF &rect) { return DrawEllipse(pen,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawEllipse(const Pen *pen,REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipDrawEllipse(nativeGraphics,pen->nativePen,x,y,width,height)); }
  Status DrawEllipse(const Pen *pen,const Rect &rect) { return DrawEllipse(pen,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawEllipse(const Pen *pen,INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipDrawEllipseI(nativeGraphics,pen->nativePen,x,y,width,height)); }
  Status DrawPie(const Pen *pen,const RectF &rect,REAL startAngle,REAL sweepAngle) { return DrawPie(pen,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status DrawPie(const Pen *pen,REAL x,REAL y,REAL width,REAL height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipDrawPie(nativeGraphics,pen->nativePen,x,y,width,height,startAngle,sweepAngle)); }
  Status DrawPie(const Pen *pen,const Rect &rect,REAL startAngle,REAL sweepAngle) { return DrawPie(pen,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status DrawPie(const Pen *pen,INT x,INT y,INT width,INT height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipDrawPieI(nativeGraphics,pen->nativePen,x,y,width,height,startAngle,sweepAngle)); }
  Status DrawPolygon(const Pen *pen,const PointF *points,INT count) { return SetStatus(DllExports::GdipDrawPolygon(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawPolygon(const Pen *pen,const Point *points,INT count) { return SetStatus(DllExports::GdipDrawPolygonI(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawPath(const Pen *pen,const GraphicsPath *path) { return SetStatus(DllExports::GdipDrawPath(nativeGraphics,pen ? pen->nativePen : NULL,path ? path->nativePath : NULL)); }
  Status DrawCurve(const Pen *pen,const PointF *points,INT count) { return SetStatus(DllExports::GdipDrawCurve(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawCurve(const Pen *pen,const PointF *points,INT count,REAL tension) { return SetStatus(DllExports::GdipDrawCurve2(nativeGraphics,pen->nativePen,points,count,tension)); }
  Status DrawCurve(const Pen *pen,const PointF *points,INT count,INT offset,INT numberOfSegments,REAL tension = 0.5f) { return SetStatus(DllExports::GdipDrawCurve3(nativeGraphics,pen->nativePen,points,count,offset,numberOfSegments,tension)); }
  Status DrawCurve(const Pen *pen,const Point *points,INT count) { return SetStatus(DllExports::GdipDrawCurveI(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawCurve(const Pen *pen,const Point *points,INT count,REAL tension) { return SetStatus(DllExports::GdipDrawCurve2I(nativeGraphics,pen->nativePen,points,count,tension)); }
  Status DrawCurve(const Pen *pen,const Point *points,INT count,INT offset,INT numberOfSegments,REAL tension = 0.5f) { return SetStatus(DllExports::GdipDrawCurve3I(nativeGraphics,pen->nativePen,points,count,offset,numberOfSegments,tension)); }
  Status DrawClosedCurve(const Pen *pen,const PointF *points,INT count) { return SetStatus(DllExports::GdipDrawClosedCurve(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawClosedCurve(const Pen *pen,const PointF *points,INT count,REAL tension) { return SetStatus(DllExports::GdipDrawClosedCurve2(nativeGraphics,pen->nativePen,points,count,tension)); }
  Status DrawClosedCurve(const Pen *pen,const Point *points,INT count) { return SetStatus(DllExports::GdipDrawClosedCurveI(nativeGraphics,pen->nativePen,points,count)); }
  Status DrawClosedCurve(const Pen *pen,const Point *points,INT count,REAL tension) { return SetStatus(DllExports::GdipDrawClosedCurve2I(nativeGraphics,pen->nativePen,points,count,tension)); }
  Status Clear(const Color &color) { return SetStatus(DllExports::GdipGraphicsClear(nativeGraphics,color.GetValue())); }
  Status FillRectangle(const Brush *brush,const RectF &rect) { return FillRectangle(brush,rect.X,rect.Y,rect.Width,rect.Height); }
  Status FillRectangle(const Brush *brush,REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipFillRectangle(nativeGraphics,brush->nativeBrush,x,y,width,height)); }
  Status FillRectangles(const Brush *brush,const RectF *rects,INT count) { return SetStatus(DllExports::GdipFillRectangles(nativeGraphics,brush->nativeBrush,rects,count)); }
  Status FillRectangle(const Brush *brush,const Rect &rect) { return FillRectangle(brush,rect.X,rect.Y,rect.Width,rect.Height); }
  Status FillRectangle(const Brush *brush,INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipFillRectangleI(nativeGraphics,brush->nativeBrush,x,y,width,height)); }
  Status FillRectangles(const Brush *brush,const Rect *rects,INT count) { return SetStatus(DllExports::GdipFillRectanglesI(nativeGraphics,brush->nativeBrush,rects,count)); }
  Status FillPolygon(const Brush *brush,const PointF *points,INT count) { return FillPolygon(brush,points,count,FillModeAlternate); }
  Status FillPolygon(const Brush *brush,const PointF *points,INT count,FillMode fillMode) { return SetStatus(DllExports::GdipFillPolygon(nativeGraphics,brush->nativeBrush,points,count,fillMode)); }
  Status FillPolygon(const Brush *brush,const Point *points,INT count) { return FillPolygon(brush,points,count,FillModeAlternate); }
  Status FillPolygon(const Brush *brush,const Point *points,INT count,FillMode fillMode) { return SetStatus(DllExports::GdipFillPolygonI(nativeGraphics,brush->nativeBrush,points,count,fillMode)); }
  Status FillEllipse(const Brush *brush,const RectF &rect) { return FillEllipse(brush,rect.X,rect.Y,rect.Width,rect.Height); }
  Status FillEllipse(const Brush *brush,REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipFillEllipse(nativeGraphics,brush->nativeBrush,x,y,width,height)); }
  Status FillEllipse(const Brush *brush,const Rect &rect) { return FillEllipse(brush,rect.X,rect.Y,rect.Width,rect.Height); }
  Status FillEllipse(const Brush *brush,INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipFillEllipseI(nativeGraphics,brush->nativeBrush,x,y,width,height)); }
  Status FillPie(const Brush *brush,const RectF &rect,REAL startAngle,REAL sweepAngle) { return FillPie(brush,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status FillPie(const Brush *brush,REAL x,REAL y,REAL width,REAL height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipFillPie(nativeGraphics,brush->nativeBrush,x,y,width,height,startAngle,sweepAngle)); }
  Status FillPie(const Brush *brush,const Rect &rect,REAL startAngle,REAL sweepAngle) { return FillPie(brush,rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status FillPie(const Brush *brush,INT x,INT y,INT width,INT height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipFillPieI(nativeGraphics,brush->nativeBrush,x,y,width,height,startAngle,sweepAngle)); }
  Status FillPath(const Brush *brush,const GraphicsPath *path) { return SetStatus(DllExports::GdipFillPath(nativeGraphics,brush->nativeBrush,path->nativePath)); }
  Status FillClosedCurve(const Brush *brush,const PointF *points,INT count) { return SetStatus(DllExports::GdipFillClosedCurve(nativeGraphics,brush->nativeBrush,points,count)); }
  Status FillClosedCurve(const Brush *brush,const PointF *points,INT count,FillMode fillMode,REAL tension = 0.5f) { return SetStatus(DllExports::GdipFillClosedCurve2(nativeGraphics,brush->nativeBrush,points,count,tension,fillMode)); }
  Status FillClosedCurve(const Brush *brush,const Point *points,INT count) { return SetStatus(DllExports::GdipFillClosedCurveI(nativeGraphics,brush->nativeBrush,points,count)); }
  Status FillClosedCurve(const Brush *brush,const Point *points,INT count,FillMode fillMode,REAL tension = 0.5f) { return SetStatus(DllExports::GdipFillClosedCurve2I(nativeGraphics,brush->nativeBrush,points,count,tension,fillMode)); }
  Status FillRegion(const Brush *brush,const Region *region) { return SetStatus(DllExports::GdipFillRegion(nativeGraphics,brush->nativeBrush,region->nativeRegion)); }
  Status DrawString(const WCHAR *string,INT length,const Font *font,const RectF &layoutRect,const StringFormat *stringFormat,const Brush *brush) { return SetStatus(DllExports::GdipDrawString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&layoutRect,stringFormat ? stringFormat->nativeFormat : NULL,brush ? brush->nativeBrush : NULL)); }
  Status DrawString(const WCHAR *string,INT length,const Font *font,const PointF &origin,const Brush *brush) {
    RectF rect(origin.X,origin.Y,0.0f,0.0f);
    return SetStatus(DllExports::GdipDrawString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&rect,NULL,brush ? brush->nativeBrush : NULL));
  }
  Status DrawString(const WCHAR *string,INT length,const Font *font,const PointF &origin,const StringFormat *stringFormat,const Brush *brush) {
    RectF rect(origin.X,origin.Y,0.0f,0.0f);
    return SetStatus(DllExports::GdipDrawString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&rect,stringFormat ? stringFormat->nativeFormat : NULL,brush ? brush->nativeBrush : NULL));
  }
  Status MeasureString(const WCHAR *string,INT length,const Font *font,const RectF &layoutRect,const StringFormat *stringFormat,RectF *boundingBox,INT *codepointsFitted = 0,INT *linesFilled = 0) const { return SetStatus(DllExports::GdipMeasureString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&layoutRect,stringFormat ? stringFormat->nativeFormat : NULL,boundingBox,codepointsFitted,linesFilled)); }
  Status MeasureString(const WCHAR *string,INT length,const Font *font,const SizeF &layoutRectSize,const StringFormat *stringFormat,SizeF *size,INT *codepointsFitted = 0,INT *linesFilled = 0) const {
    RectF layoutRect(0,0,layoutRectSize.Width,layoutRectSize.Height);
    RectF boundingBox;
    Status status;
    if(!size) return SetStatus(InvalidParameter);
    status = SetStatus(DllExports::GdipMeasureString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&layoutRect,stringFormat ? stringFormat->nativeFormat : NULL,size ? &boundingBox : NULL,codepointsFitted,linesFilled));
    if(size && status==Ok) {
      size->Width = boundingBox.Width;
      size->Height = boundingBox.Height;
    }
    return status;
  }
  Status MeasureString(const WCHAR *string,INT length,const Font *font,const PointF &origin,const StringFormat *stringFormat,RectF *boundingBox) const {
    RectF rect(origin.X,origin.Y,0.0f,0.0f);
    return SetStatus(DllExports::GdipMeasureString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&rect,stringFormat ? stringFormat->nativeFormat : NULL,boundingBox,NULL,NULL));
  }
  Status MeasureString(const WCHAR *string,INT length,const Font *font,const RectF &layoutRect,RectF *boundingBox) const { return SetStatus(DllExports::GdipMeasureString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&layoutRect,NULL,boundingBox,NULL,NULL)); }
  Status MeasureString(const WCHAR *string,INT length,const Font *font,const PointF &origin,RectF *boundingBox) const {
    RectF rect(origin.X,origin.Y,0.0f,0.0f);
    return SetStatus(DllExports::GdipMeasureString(nativeGraphics,string,length,font ? font->nativeFont : NULL,&rect,NULL,boundingBox,NULL,NULL));
  }
  Status MeasureCharacterRanges(const WCHAR *string,INT length,const Font *font,const RectF &layoutRect,const StringFormat *stringFormat,INT regionCount,Region *regions) const {
    if(!regions || regionCount<=0) return InvalidParameter;
    GpRegion **nativeRegions = new GpRegion *[regionCount];
    if(!nativeRegions) return OutOfMemory;
    for(INT i = 0;i < regionCount;i++) {
      nativeRegions[i] = regions[i].nativeRegion;
    }
    Status status = SetStatus(DllExports::GdipMeasureCharacterRanges(nativeGraphics,string,length,font ? font->nativeFont : NULL,layoutRect,stringFormat ? stringFormat->nativeFormat : NULL,regionCount,nativeRegions));
    delete [] nativeRegions;
    return status;
  }
  Status DrawDriverString(const UINT16 *text,INT length,const Font *font,const Brush *brush,const PointF *positions,INT flags,const Matrix *matrix) { return SetStatus(DllExports::GdipDrawDriverString(nativeGraphics,text,length,font ? font->nativeFont : NULL,brush ? brush->nativeBrush : NULL,positions,flags,matrix ? matrix->nativeMatrix : NULL)); }
  Status MeasureDriverString(const UINT16 *text,INT length,const Font *font,const PointF *positions,INT flags,const Matrix *matrix,RectF *boundingBox) const { return SetStatus(DllExports::GdipMeasureDriverString(nativeGraphics,text,length,font ? font->nativeFont : NULL,positions,flags,matrix ? matrix->nativeMatrix : NULL,boundingBox)); }
  Status DrawCachedBitmap(CachedBitmap *cb,INT x,INT y) { return SetStatus(DllExports::GdipDrawCachedBitmap(nativeGraphics,cb->nativeCachedBitmap,x,y)); }
  Status DrawImage(Image *image,const PointF &point) { return DrawImage(image,point.X,point.Y); }
  Status DrawImage(Image *image,REAL x,REAL y) { return SetStatus(DllExports::GdipDrawImage(nativeGraphics,image ? image->nativeImage : NULL,x,y)); }
  Status DrawImage(Image *image,const RectF &rect) { return DrawImage(image,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawImage(Image *image,REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipDrawImageRect(nativeGraphics,image ? image->nativeImage : NULL,x,y,width,height)); }
  Status DrawImage(Image *image,const Point &point) { return DrawImage(image,point.X,point.Y); }
  Status DrawImage(Image *image,INT x,INT y) { return SetStatus(DllExports::GdipDrawImageI(nativeGraphics,image ? image->nativeImage : NULL,x,y)); }
  Status DrawImage(Image *image,const Rect &rect) { return DrawImage(image,rect.X,rect.Y,rect.Width,rect.Height); }
  Status DrawImage(Image *image,INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipDrawImageRectI(nativeGraphics,image ? image->nativeImage : NULL,x,y,width,height)); }
  Status DrawImage(Image *image,const PointF *destPoints,INT count) {
    if(count!=3 && count!=4) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipDrawImagePoints(nativeGraphics,image ? image->nativeImage : NULL,destPoints,count));
  }
  Status DrawImage(Image *image,const Point *destPoints,INT count) {
    if(count!=3 && count!=4) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipDrawImagePointsI(nativeGraphics,image ? image->nativeImage : NULL,destPoints,count));
  }
  Status DrawImage(Image *image,REAL x,REAL y,REAL srcx,REAL srcy,REAL srcwidth,REAL srcheight,Unit srcUnit) { return SetStatus(DllExports::GdipDrawImagePointRect(nativeGraphics,image ? image->nativeImage : NULL,x,y,srcx,srcy,srcwidth,srcheight,srcUnit)); }
  Status DrawImage(Image *image,const RectF &destRect,REAL srcx,REAL srcy,REAL srcwidth,REAL srcheight,Unit srcUnit,const ImageAttributes *imageAttributes = NULL,DrawImageAbort callback = NULL,VOID *callbackData = NULL) { return SetStatus(DllExports::GdipDrawImageRectRect(nativeGraphics,image ? image->nativeImage : NULL,destRect.X,destRect.Y,destRect.Width,destRect.Height,srcx,srcy,srcwidth,srcheight,srcUnit,imageAttributes ? imageAttributes->nativeImageAttr : NULL,callback,callbackData)); }
  Status DrawImage(Image *image,const PointF *destPoints,INT count,REAL srcx,REAL srcy,REAL srcwidth,REAL srcheight,Unit srcUnit,const ImageAttributes *imageAttributes = NULL,DrawImageAbort callback = NULL,VOID *callbackData = NULL) { return SetStatus(DllExports::GdipDrawImagePointsRect(nativeGraphics,image ? image->nativeImage : NULL,destPoints,count,srcx,srcy,srcwidth,srcheight,srcUnit,imageAttributes ? imageAttributes->nativeImageAttr : NULL,callback,callbackData)); }
  Status DrawImage(Image *image,INT x,INT y,INT srcx,INT srcy,INT srcwidth,INT srcheight,Unit srcUnit) { return SetStatus(DllExports::GdipDrawImagePointRectI(nativeGraphics,image ? image->nativeImage : NULL,x,y,srcx,srcy,srcwidth,srcheight,srcUnit)); }
  Status DrawImage(Image *image,const Rect &destRect,INT srcx,INT srcy,INT srcwidth,INT srcheight,Unit srcUnit,const ImageAttributes *imageAttributes = NULL,DrawImageAbort callback = NULL,VOID *callbackData = NULL) { return SetStatus(DllExports::GdipDrawImageRectRectI(nativeGraphics,image ? image->nativeImage : NULL,destRect.X,destRect.Y,destRect.Width,destRect.Height,srcx,srcy,srcwidth,srcheight,srcUnit,imageAttributes ? imageAttributes->nativeImageAttr : NULL,callback,callbackData)); }
  Status DrawImage(Image *image,const Point *destPoints,INT count,INT srcx,INT srcy,INT srcwidth,INT srcheight,Unit srcUnit,const ImageAttributes *imageAttributes = NULL,DrawImageAbort callback = NULL,VOID *callbackData = NULL) { return SetStatus(DllExports::GdipDrawImagePointsRectI(nativeGraphics,image ? image->nativeImage : NULL,destPoints,count,srcx,srcy,srcwidth,srcheight,srcUnit,imageAttributes ? imageAttributes->nativeImageAttr : NULL,callback,callbackData)); }
  Status EnumerateMetafile(const Metafile *metafile,const PointF &destPoint,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestPoint(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoint,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Point &destPoint,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestPointI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoint,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const RectF &destRect,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestRect(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destRect,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Rect &destRect,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestRectI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destRect,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const PointF *destPoints,INT count,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestPoints(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoints,count,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Point *destPoints,INT count,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileDestPointsI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoints,count,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const PointF &destPoint,const RectF &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestPoint(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoint,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Point &destPoint,const Rect &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestPointI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoint,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const RectF &destRect,const RectF &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestRect(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destRect,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Rect &destRect,const Rect &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestRectI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destRect,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const PointF *destPoints,INT count,const RectF &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestPoints(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoints,count,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status EnumerateMetafile(const Metafile *metafile,const Point *destPoints,INT count,const Rect &srcRect,Unit srcUnit,EnumerateMetafileProc callback,VOID *callbackData = NULL,const ImageAttributes *imageAttributes = NULL) { return SetStatus(DllExports::GdipEnumerateMetafileSrcRectDestPointsI(nativeGraphics,(const GpMetafile *)(metafile ? metafile->nativeImage:NULL),destPoints,count,srcRect,srcUnit,callback,callbackData,imageAttributes ? imageAttributes->nativeImageAttr : NULL)); }
  Status SetClip(const Graphics *g,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipGraphics(nativeGraphics,g->nativeGraphics,combineMode)); }
  Status SetClip(const RectF &rect,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipRect(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,combineMode)); }
  Status SetClip(const Rect &rect,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipRectI(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,combineMode)); }
  Status SetClip(const GraphicsPath *path,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipPath(nativeGraphics,path->nativePath,combineMode)); }
  Status SetClip(const Region *region,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipRegion(nativeGraphics,region->nativeRegion,combineMode)); }
  Status SetClip(HRGN hRgn,CombineMode combineMode = CombineModeReplace) { return SetStatus(DllExports::GdipSetClipHrgn(nativeGraphics,hRgn,combineMode)); }
  Status IntersectClip(const RectF &rect) { return SetStatus(DllExports::GdipSetClipRect(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,CombineModeIntersect)); }
  Status IntersectClip(const Rect &rect) { return SetStatus(DllExports::GdipSetClipRectI(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,CombineModeIntersect)); }
  Status IntersectClip(const Region *region) { return SetStatus(DllExports::GdipSetClipRegion(nativeGraphics,region->nativeRegion,CombineModeIntersect)); }
  Status ExcludeClip(const RectF &rect) { return SetStatus(DllExports::GdipSetClipRect(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,CombineModeExclude)); }
  Status ExcludeClip(const Rect &rect) { return SetStatus(DllExports::GdipSetClipRectI(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,CombineModeExclude)); }
  Status ExcludeClip(const Region *region) { return SetStatus(DllExports::GdipSetClipRegion(nativeGraphics,region->nativeRegion,CombineModeExclude)); }
  Status ResetClip() { return SetStatus(DllExports::GdipResetClip(nativeGraphics)); }
  Status TranslateClip(REAL dx,REAL dy) { return SetStatus(DllExports::GdipTranslateClip(nativeGraphics,dx,dy)); }
  Status TranslateClip(INT dx,INT dy) { return SetStatus(DllExports::GdipTranslateClipI(nativeGraphics,dx,dy)); }
  Status GetClip(Region *region) const { return SetStatus(DllExports::GdipGetClip(nativeGraphics,region->nativeRegion)); }
  Status GetClipBounds(RectF *rect) const { return SetStatus(DllExports::GdipGetClipBounds(nativeGraphics,rect)); }
  Status GetClipBounds(Rect *rect) const { return SetStatus(DllExports::GdipGetClipBoundsI(nativeGraphics,rect)); }
  WINBOOL IsClipEmpty() const {
    WINBOOL booln = FALSE;
    SetStatus(DllExports::GdipIsClipEmpty(nativeGraphics,&booln));
    return booln;
  }
  Status GetVisibleClipBounds(RectF *rect) const { return SetStatus(DllExports::GdipGetVisibleClipBounds(nativeGraphics,rect)); }
  Status GetVisibleClipBounds(Rect *rect) const { return SetStatus(DllExports::GdipGetVisibleClipBoundsI(nativeGraphics,rect)); }
  WINBOOL IsVisibleClipEmpty() const {
    WINBOOL booln = FALSE;
    SetStatus(DllExports::GdipIsVisibleClipEmpty(nativeGraphics,&booln));
    return booln;
  }
  WINBOOL IsVisible(INT x,INT y) const { return IsVisible(Point(x,y)); }
  WINBOOL IsVisible(const Point &point) const {
    WINBOOL booln = FALSE;
    SetStatus(DllExports::GdipIsVisiblePointI(nativeGraphics,point.X,point.Y,&booln));
    return booln;
  }
  WINBOOL IsVisible(INT x,INT y,INT width,INT height) const { return IsVisible(Rect(x,y,width,height)); }
  WINBOOL IsVisible(const Rect &rect) const {
    WINBOOL booln = TRUE;
    SetStatus(DllExports::GdipIsVisibleRectI(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,&booln));
    return booln;
  }
  WINBOOL IsVisible(REAL x,REAL y) const { return IsVisible(PointF(x,y)); }
  WINBOOL IsVisible(const PointF &point) const {
    WINBOOL booln = FALSE;
    SetStatus(DllExports::GdipIsVisiblePoint(nativeGraphics,point.X,point.Y,&booln));
    return booln;
  }
  WINBOOL IsVisible(REAL x,REAL y,REAL width,REAL height) const { return IsVisible(RectF(x,y,width,height)); }
  WINBOOL IsVisible(const RectF &rect) const {
    WINBOOL booln = TRUE;
    SetStatus(DllExports::GdipIsVisibleRect(nativeGraphics,rect.X,rect.Y,rect.Width,rect.Height,&booln));
    return booln;
  }
  GraphicsState Save() const {
    GraphicsState gstate;
    SetStatus(DllExports::GdipSaveGraphics(nativeGraphics,&gstate));
    return gstate;
  }
  Status Restore(GraphicsState gstate) { return SetStatus(DllExports::GdipRestoreGraphics(nativeGraphics,gstate)); }
  GraphicsContainer BeginContainer(const RectF &dstrect,const RectF &srcrect,Unit unit) {
    GraphicsContainer state;
    SetStatus(DllExports::GdipBeginContainer(nativeGraphics,&dstrect,&srcrect,unit,&state));
    return state;
  }
  GraphicsContainer BeginContainer(const Rect &dstrect,const Rect &srcrect,Unit unit) {
    GraphicsContainer state;
    SetStatus(DllExports::GdipBeginContainerI(nativeGraphics,&dstrect,&srcrect,unit,&state));
    return state;
  }
  GraphicsContainer BeginContainer() {
    GraphicsContainer state;
    SetStatus(DllExports::GdipBeginContainer2(nativeGraphics,&state));
    return state;
  }
  Status EndContainer(GraphicsContainer state) { return SetStatus(DllExports::GdipEndContainer(nativeGraphics,state)); }
  Status AddMetafileComment(const BYTE *data,UINT sizeData) { return SetStatus(DllExports::GdipComment(nativeGraphics,sizeData,data)); }
  static HPALETTE GetHalftonePalette() { return DllExports::GdipCreateHalftonePalette(); }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
private:
  Graphics(const Graphics &);
  Graphics& operator=(const Graphics &);
protected:
  Graphics(GpGraphics *graphics) {
    lastResult = Ok;
    SetNativeGraphics(graphics);
  }
  VOID SetNativeGraphics(GpGraphics *graphics) {
    this->nativeGraphics = graphics;
  }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
  GpGraphics *GetNativeGraphics() const { return this->nativeGraphics; }
  GpPen *GetNativePen(const Pen *pen) { return pen->nativePen; }
protected:
  GpGraphics *nativeGraphics;
  mutable Status lastResult;
};

inline Status GraphicsPath::GetBounds(RectF *bounds,const Matrix *matrix,const Pen *pen) const {
  GpMatrix *nativeMatrix = NULL;
  GpPen *nativePen = NULL;
  if(matrix) nativeMatrix = matrix->nativeMatrix;
  if(pen) nativePen = pen->nativePen;
  return SetStatus(DllExports::GdipGetPathWorldBounds(nativePath,bounds,nativeMatrix,nativePen));
}

inline Status GraphicsPath::GetBounds(Rect *bounds,const Matrix *matrix,const Pen *pen) const {
  GpMatrix *nativeMatrix = NULL;
  GpPen *nativePen = NULL;
  if(matrix) nativeMatrix = matrix->nativeMatrix;
  if(pen) nativePen = pen->nativePen;
  return SetStatus(DllExports::GdipGetPathWorldBoundsI(nativePath,bounds,nativeMatrix,nativePen));
}

inline WINBOOL GraphicsPath::IsVisible(REAL x,REAL y,const Graphics *g) const {
  WINBOOL booln = FALSE;
  GpGraphics *nativeGraphics = NULL;
  if(g) nativeGraphics = g->nativeGraphics;
  SetStatus(DllExports::GdipIsVisiblePathPoint(nativePath,x,y,nativeGraphics,&booln));
  return booln;
}

inline WINBOOL GraphicsPath::IsVisible(INT x,INT y,const Graphics *g) const {
  WINBOOL booln = FALSE;
  GpGraphics *nativeGraphics = NULL;
  if(g) nativeGraphics = g->nativeGraphics;
  SetStatus(DllExports::GdipIsVisiblePathPointI(nativePath,x,y,nativeGraphics,&booln));
  return booln;
}

inline WINBOOL GraphicsPath::IsOutlineVisible(REAL x,REAL y,const Pen *pen,const Graphics *g) const {
  WINBOOL booln = FALSE;
  GpGraphics *nativeGraphics = NULL;
  GpPen *nativePen = NULL;
  if(g) nativeGraphics = g->nativeGraphics;
  if(pen) nativePen = pen->nativePen;
  SetStatus(DllExports::GdipIsOutlineVisiblePathPoint(nativePath,x,y,nativePen,nativeGraphics,&booln));
  return booln;
}

inline WINBOOL GraphicsPath::IsOutlineVisible(INT x,INT y,const Pen *pen,const Graphics *g) const {
  WINBOOL booln = FALSE;
  GpGraphics *nativeGraphics = NULL;
  GpPen *nativePen = NULL;
  if(g) nativeGraphics = g->nativeGraphics;
  if(pen) nativePen = pen->nativePen;
  SetStatus(DllExports::GdipIsOutlineVisiblePathPointI(nativePath,x,y,nativePen,nativeGraphics,&booln));
  return booln;
}

#endif
