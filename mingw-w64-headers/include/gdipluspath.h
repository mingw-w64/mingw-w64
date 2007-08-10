/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSPATH_H
#define _GDIPLUSPATH_H

class GraphicsPath : public GdiplusBase {
public:
  friend class Graphics;
  friend class Region;
  friend class PathGradientBrush;
  friend class GraphicsPathIterator;
  friend class CustomLineCap;
  GraphicsPath(FillMode fillMode = FillModeAlternate) {
    nativePath = NULL;
    lastResult = DllExports::GdipCreatePath(fillMode,&nativePath);
  }
  GraphicsPath(const PointF *points,const BYTE *types,INT count,FillMode fillMode = FillModeAlternate) {
    nativePath = NULL;
    lastResult = DllExports::GdipCreatePath2(points,types,count,fillMode,&nativePath);
  }
  GraphicsPath(const Point *points,const BYTE *types,INT count,FillMode fillMode = FillModeAlternate) {
    nativePath = NULL;
    lastResult = DllExports::GdipCreatePath2I(points,types,count,fillMode,&nativePath);
  }
  ~GraphicsPath() { DllExports::GdipDeletePath(nativePath); }
  GraphicsPath *Clone() const {
    GpPath *clonepath = NULL;
    SetStatus(DllExports::GdipClonePath(nativePath,&clonepath));
    return new GraphicsPath(clonepath);
  }
  Status Reset() { return SetStatus(DllExports::GdipResetPath(nativePath)); }
  FillMode GetFillMode() const {
    FillMode fillmode = FillModeAlternate;
    SetStatus(DllExports::GdipGetPathFillMode(nativePath,&fillmode));
    return fillmode;
  }
  Status SetFillMode(FillMode fillmode) { return SetStatus(DllExports::GdipSetPathFillMode(nativePath,fillmode)); }
  Status GetPathData(PathData *pathData) const {
    if(!pathData) return SetStatus(InvalidParameter);
    INT count = GetPointCount();
    if((count <= 0) || (pathData->Count>0 && pathData->Count<count)) {
      pathData->Count = 0;
      if(pathData->Points) {
	delete pathData->Points;
	pathData->Points = NULL;
      }
      if(pathData->Types) {
	delete pathData->Types;
	pathData->Types = NULL;
      }
      if(count <= 0) return lastResult;
    }
    if(pathData->Count==0) {
      pathData->Points = new PointF[count];
      if(!(pathData->Points)) return SetStatus(OutOfMemory);
      pathData->Types = new byte[count];
      if(!(pathData->Types)) {
	delete pathData->Points;
	pathData->Points = NULL;
	return SetStatus(OutOfMemory);
      }
      pathData->Count = count;
    }
    return SetStatus(DllExports::GdipGetPathData(nativePath,pathData));
  }
  Status StartFigure() { return SetStatus(DllExports::GdipStartPathFigure(nativePath)); }
  Status CloseFigure() { return SetStatus(DllExports::GdipClosePathFigure(nativePath)); }
  Status CloseAllFigures() { return SetStatus(DllExports::GdipClosePathFigures(nativePath)); }
  Status SetMarker() { return SetStatus(DllExports::GdipSetPathMarker(nativePath)); }
  Status ClearMarkers() { return SetStatus(DllExports::GdipClearPathMarkers(nativePath)); }
  Status Reverse() { return SetStatus(DllExports::GdipReversePath(nativePath)); }
  Status GetLastPoint(PointF *lastPoint) const { return SetStatus(DllExports::GdipGetPathLastPoint(nativePath,lastPoint)); }
  Status AddLine(const PointF &pt1,const PointF &pt2) { return AddLine(pt1.X,pt1.Y,pt2.X,pt2.Y); }
  Status AddLine(REAL x1,REAL y1,REAL x2,REAL y2) { return SetStatus(DllExports::GdipAddPathLine(nativePath,x1,y1,x2,y2)); }
  Status AddLines(const PointF *points,INT count) { return SetStatus(DllExports::GdipAddPathLine2(nativePath,points,count)); }
  Status AddLine(const Point &pt1,const Point &pt2) { return AddLine(pt1.X,pt1.Y,pt2.X,pt2.Y); }
  Status AddLine(INT x1,INT y1,INT x2,INT y2) { return SetStatus(DllExports::GdipAddPathLineI(nativePath,x1,y1,x2,y2)); }
  Status AddLines(const Point *points,INT count) { return SetStatus(DllExports::GdipAddPathLine2I(nativePath,points,count)); }
  Status AddArc(const RectF &rect,REAL startAngle,REAL sweepAngle) { return AddArc(rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status AddArc(REAL x,REAL y,REAL width,REAL height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipAddPathArc(nativePath,x,y,width,height,startAngle,sweepAngle)); }
  Status AddArc(const Rect &rect,REAL startAngle,REAL sweepAngle) { return AddArc(rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status AddArc(INT x,INT y,INT width,INT height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipAddPathArcI(nativePath,x,y,width,height,startAngle,sweepAngle)); }
  Status AddBezier(const PointF &pt1,const PointF &pt2,const PointF &pt3,const PointF &pt4) { return AddBezier(pt1.X,pt1.Y,pt2.X,pt2.Y,pt3.X,pt3.Y,pt4.X,pt4.Y); }
  Status AddBezier(REAL x1,REAL y1,REAL x2,REAL y2,REAL x3,REAL y3,REAL x4,REAL y4) { return SetStatus(DllExports::GdipAddPathBezier(nativePath,x1,y1,x2,y2,x3,y3,x4,y4)); }
  Status AddBeziers(const PointF *points,INT count) { return SetStatus(DllExports::GdipAddPathBeziers(nativePath,points,count)); }
  Status AddBezier(const Point &pt1,const Point &pt2,const Point &pt3,const Point &pt4) { return AddBezier(pt1.X,pt1.Y,pt2.X,pt2.Y,pt3.X,pt3.Y,pt4.X,pt4.Y); }
  Status AddBezier(INT x1,INT y1,INT x2,INT y2,INT x3,INT y3,INT x4,INT y4) { return SetStatus(DllExports::GdipAddPathBezierI(nativePath,x1,y1,x2,y2,x3,y3,x4,y4)); }
  Status AddBeziers(const Point *points,INT count) { return SetStatus(DllExports::GdipAddPathBeziersI(nativePath,points,count)); }
  Status AddCurve(const PointF *points,INT count) { return SetStatus(DllExports::GdipAddPathCurve(nativePath,points,count)); }
  Status AddCurve(const PointF *points,INT count,REAL tension) { return SetStatus(DllExports::GdipAddPathCurve2(nativePath,points,count,tension)); }
  Status AddCurve(const PointF *points,INT count,INT offset,INT numberOfSegments,REAL tension) { return SetStatus(DllExports::GdipAddPathCurve3(nativePath,points,count,offset,numberOfSegments,tension)); }
  Status AddCurve(const Point *points,INT count) { return SetStatus(DllExports::GdipAddPathCurveI(nativePath,points,count)); }
  Status AddCurve(const Point *points,INT count,REAL tension) { return SetStatus(DllExports::GdipAddPathCurve2I(nativePath,points,count,tension)); }
  Status AddCurve(const Point *points,INT count,INT offset,INT numberOfSegments,REAL tension) { return SetStatus(DllExports::GdipAddPathCurve3I(nativePath,points,count,offset,numberOfSegments,tension)); }
  Status AddClosedCurve(const PointF *points,INT count) { return SetStatus(DllExports::GdipAddPathClosedCurve(nativePath,points,count)); }
  Status AddClosedCurve(const PointF *points,INT count,REAL tension) { return SetStatus(DllExports::GdipAddPathClosedCurve2(nativePath,points,count,tension)); }
  Status AddClosedCurve(const Point *points,INT count) { return SetStatus(DllExports::GdipAddPathClosedCurveI(nativePath,points,count)); }
  Status AddClosedCurve(const Point *points,INT count,REAL tension) { return SetStatus(DllExports::GdipAddPathClosedCurve2I(nativePath,points,count,tension)); }
  Status AddRectangle(const RectF &rect) { return SetStatus(DllExports::GdipAddPathRectangle(nativePath,rect.X,rect.Y,rect.Width,rect.Height)); }
  Status AddRectangles(const RectF *rects,INT count) { return SetStatus(DllExports::GdipAddPathRectangles(nativePath,rects,count)); }
  Status AddRectangle(const Rect &rect) { return SetStatus(DllExports::GdipAddPathRectangleI(nativePath,rect.X,rect.Y,rect.Width,rect.Height)); }
  Status AddRectangles(const Rect *rects,INT count) { return SetStatus(DllExports::GdipAddPathRectanglesI(nativePath,rects,count)); }
  Status AddEllipse(const RectF &rect) { return AddEllipse(rect.X,rect.Y,rect.Width,rect.Height); }
  Status AddEllipse(REAL x,REAL y,REAL width,REAL height) { return SetStatus(DllExports::GdipAddPathEllipse(nativePath,x,y,width,height)); }
  Status AddEllipse(const Rect &rect) { return AddEllipse(rect.X,rect.Y,rect.Width,rect.Height); }
  Status AddEllipse(INT x,INT y,INT width,INT height) { return SetStatus(DllExports::GdipAddPathEllipseI(nativePath,x,y,width,height)); }
  Status AddPie(const RectF &rect,REAL startAngle,REAL sweepAngle) { return AddPie(rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status AddPie(REAL x,REAL y,REAL width,REAL height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipAddPathPie(nativePath,x,y,width,height,startAngle,sweepAngle)); }
  Status AddPie(const Rect &rect,REAL startAngle,REAL sweepAngle) { return AddPie(rect.X,rect.Y,rect.Width,rect.Height,startAngle,sweepAngle); }
  Status AddPie(INT x,INT y,INT width,INT height,REAL startAngle,REAL sweepAngle) { return SetStatus(DllExports::GdipAddPathPieI(nativePath,x,y,width,height,startAngle,sweepAngle)); }
  Status AddPolygon(const PointF *points,INT count) { return SetStatus(DllExports::GdipAddPathPolygon(nativePath,points,count)); }
  Status AddPolygon(const Point *points,INT count) { return SetStatus(DllExports::GdipAddPathPolygonI(nativePath,points,count)); }
  Status AddPath(const GraphicsPath *addingPath,WINBOOL connect) {
    GpPath *nativePath2 = NULL;
    if(addingPath) nativePath2 = addingPath->nativePath;
    return SetStatus(DllExports::GdipAddPathPath(nativePath,nativePath2,connect));
  }
  Status AddString(const WCHAR *string,INT length,const FontFamily *family,INT style,REAL emSize,const PointF &origin,const StringFormat *format) {
    RectF rect(origin.X,origin.Y,0.0f,0.0f);
    return SetStatus(DllExports::GdipAddPathString(nativePath,string,length,family ? family->nativeFamily : NULL,style,emSize,&rect,format ? format->nativeFormat : NULL));
  }
  Status AddString(const WCHAR *string,INT length,const FontFamily *family,INT style,REAL emSize,const RectF &layoutRect,const StringFormat *format) { return SetStatus(DllExports::GdipAddPathString(nativePath,string,length,family ? family->nativeFamily : NULL,style,emSize,&layoutRect,format ? format->nativeFormat : NULL)); }
  Status AddString(const WCHAR *string,INT length,const FontFamily *family,INT style,REAL emSize,const Point &origin,const StringFormat *format) {
    Rect rect(origin.X,origin.Y,0,0);
    return SetStatus(DllExports::GdipAddPathStringI(nativePath,string,length,family ? family->nativeFamily : NULL,style,emSize,&rect,format ? format->nativeFormat : NULL));
  }
  Status AddString(const WCHAR *string,INT length,const FontFamily *family,INT style,REAL emSize,const Rect &layoutRect,const StringFormat *format) { return SetStatus(DllExports::GdipAddPathStringI(nativePath,string,length,family ? family->nativeFamily : NULL,style,emSize,&layoutRect,format ? format->nativeFormat : NULL)); }
  Status Transform(const Matrix *matrix) {
    if(matrix) return SetStatus(DllExports::GdipTransformPath(nativePath,matrix->nativeMatrix));
    return Ok;
  }
  Status GetBounds(RectF *bounds,const Matrix *matrix = NULL,const Pen *pen = NULL) const;
  Status GetBounds(Rect *bounds,const Matrix *matrix = NULL,const Pen *pen = NULL) const;
  Status Flatten(const Matrix *matrix = NULL,REAL flatness = FlatnessDefault) {
    GpMatrix *nativeMatrix = NULL;
    if(matrix) {
      nativeMatrix = matrix->nativeMatrix;
    }
    return SetStatus(DllExports::GdipFlattenPath(nativePath,nativeMatrix,flatness));
  }
  Status Widen(const Pen *pen,const Matrix *matrix = NULL,REAL flatness = FlatnessDefault) {
    GpMatrix *nativeMatrix = NULL;
    if(matrix) nativeMatrix = matrix->nativeMatrix;
    return SetStatus(DllExports::GdipWidenPath(nativePath,pen->nativePen,nativeMatrix,flatness));
  }
  Status Outline(const Matrix *matrix = NULL,REAL flatness = FlatnessDefault) {
    GpMatrix *nativeMatrix = NULL;
    if(matrix) {
      nativeMatrix = matrix->nativeMatrix;
    }
    return SetStatus(DllExports::GdipWindingModeOutline(nativePath,nativeMatrix,flatness));
  }
  Status Warp(const PointF *destPoints,INT count,const RectF &srcRect,const Matrix *matrix = NULL,WarpMode warpMode = WarpModePerspective,REAL flatness = FlatnessDefault) {
    GpMatrix *nativeMatrix = NULL;
    if(matrix) nativeMatrix = matrix->nativeMatrix;
    return SetStatus(DllExports::GdipWarpPath(nativePath,nativeMatrix,destPoints,count,srcRect.X,srcRect.Y,srcRect.Width,srcRect.Height,warpMode,flatness));
  }
  INT GetPointCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetPointCount(nativePath,&count));
    return count;
  }
  Status GetPathTypes(BYTE *types,INT count) const { return SetStatus(DllExports::GdipGetPathTypes(nativePath,types,count)); }
  Status GetPathPoints(PointF *points,INT count) const { return SetStatus(DllExports::GdipGetPathPoints(nativePath,points,count)); }
  Status GetPathPoints(Point *points,INT count) const { return SetStatus(DllExports::GdipGetPathPointsI(nativePath,points,count)); }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
  WINBOOL IsVisible(const PointF &point,const Graphics *g = NULL) const { return IsVisible(point.X,point.Y,g); }
  WINBOOL IsVisible(REAL x,REAL y,const Graphics *g = NULL) const;
  WINBOOL IsVisible(const Point &point,const Graphics *g = NULL) const { return IsVisible(point.X,point.Y,g); }
  WINBOOL IsVisible(INT x,INT y,const Graphics *g = NULL) const;
  WINBOOL IsOutlineVisible(const PointF &point,const Pen *pen,const Graphics *g = NULL) const { return IsOutlineVisible(point.X,point.Y,pen,g); }
  WINBOOL IsOutlineVisible(REAL x,REAL y,const Pen *pen,const Graphics *g = NULL) const;
  WINBOOL IsOutlineVisible(const Point &point,const Pen *pen,const Graphics *g = NULL) const { return IsOutlineVisible(point.X,point.Y,pen,g); }
  WINBOOL IsOutlineVisible(INT x,INT y,const Pen *pen,const Graphics *g = NULL) const;
protected:
  GraphicsPath(const GraphicsPath &path) {
    GpPath *clonepath = NULL;
    SetStatus(DllExports::GdipClonePath(path.nativePath,&clonepath));
    SetNativePath(clonepath);
  }
private:
  GraphicsPath &operator=(const GraphicsPath &);
protected:
  GraphicsPath(GpPath *nativePath) {
    lastResult = Ok;
    SetNativePath(nativePath);
  }
  VOID SetNativePath(GpPath *nativePath) { this->nativePath = nativePath; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    return status;
  }
protected:
  GpPath *nativePath;
  mutable Status lastResult;
};

class GraphicsPathIterator : public GdiplusBase {
public:
  GraphicsPathIterator(const GraphicsPath *path) {
    GpPath *nativePath = NULL;
    if(path) nativePath = path->nativePath;
    GpPathIterator *iter = NULL;
    lastResult = DllExports::GdipCreatePathIter(&iter,nativePath);
    SetNativeIterator(iter);
  }
  ~GraphicsPathIterator() { DllExports::GdipDeletePathIter(nativeIterator); }
  INT NextSubpath(INT *startIndex,INT *endIndex,WINBOOL *isClosed) {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterNextSubpath(nativeIterator,&resultCount,startIndex,endIndex,isClosed));
    return resultCount;
  }
  INT NextSubpath(const GraphicsPath *path,WINBOOL *isClosed) {
    GpPath *nativePath = NULL;
    INT resultCount;
    if(path) nativePath= path->nativePath;
    SetStatus(DllExports::GdipPathIterNextSubpathPath(nativeIterator,&resultCount,nativePath,isClosed));
    return resultCount;
  }
  INT NextPathType(BYTE *pathType,INT *startIndex,INT *endIndex) {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterNextPathType(nativeIterator,&resultCount,pathType,startIndex,endIndex));
    return resultCount;
  }
  INT NextMarker(INT *startIndex,INT *endIndex) {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterNextMarker(nativeIterator,&resultCount,startIndex,endIndex));
    return resultCount;
  }
  INT NextMarker(const GraphicsPath *path) {
    GpPath *nativePath = NULL;
    INT resultCount;
    if(path) nativePath= path->nativePath;
    SetStatus(DllExports::GdipPathIterNextMarkerPath(nativeIterator,&resultCount,nativePath));
    return resultCount;
  }
  INT GetCount() const {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterGetCount(nativeIterator,&resultCount));
    return resultCount;
  }
  INT GetSubpathCount() const {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterGetSubpathCount(nativeIterator,&resultCount));
    return resultCount;
  }
  WINBOOL HasCurve() const {
    WINBOOL hasCurve;
    SetStatus(DllExports::GdipPathIterHasCurve(nativeIterator,&hasCurve));
    return hasCurve;
  }
  VOID Rewind() { SetStatus(DllExports::GdipPathIterRewind(nativeIterator)); }
  INT Enumerate(PointF *points,BYTE *types,INT count) {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterEnumerate(nativeIterator,&resultCount,points,types,count));
    return resultCount;
  }
  INT CopyData(PointF *points,BYTE *types,INT startIndex,INT endIndex) {
    INT resultCount;
    SetStatus(DllExports::GdipPathIterCopyData(nativeIterator,&resultCount,points,types,startIndex,endIndex));
    return resultCount;
  }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
private:
  GraphicsPathIterator(const GraphicsPathIterator &);
  GraphicsPathIterator &operator=(const GraphicsPathIterator &);
protected:
  VOID SetNativeIterator(GpPathIterator *nativeIterator) { this->nativeIterator = nativeIterator; }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    return status;
  }
protected:
  GpPathIterator *nativeIterator;
  mutable Status lastResult;
};

class PathGradientBrush : public Brush {
public:
  friend class Pen;
  PathGradientBrush(const PointF *points,INT count,WrapMode wrapMode = WrapModeClamp) {
    GpPathGradient *brush = NULL;
    lastResult = DllExports::GdipCreatePathGradient(points,count,wrapMode,&brush);
    SetNativeBrush(brush);
  }
  PathGradientBrush(const Point *points,INT count,WrapMode wrapMode = WrapModeClamp) {
    GpPathGradient *brush = NULL;
    lastResult = DllExports::GdipCreatePathGradientI(points,count,wrapMode,&brush);
    SetNativeBrush(brush);
  }
  PathGradientBrush(const GraphicsPath *path) {
    GpPathGradient *brush = NULL;
    lastResult = DllExports::GdipCreatePathGradientFromPath(path->nativePath,&brush);
    SetNativeBrush(brush);
  }
  Status GetCenterColor(Color *color) const {
    ARGB argb;
    if(!color) return SetStatus(InvalidParameter);
    SetStatus(DllExports::GdipGetPathGradientCenterColor((GpPathGradient*) nativeBrush,&argb));
    color->SetValue(argb);
    return lastResult;
  }
  Status SetCenterColor(const Color &color) {
    SetStatus(DllExports::GdipSetPathGradientCenterColor((GpPathGradient*) nativeBrush,color.GetValue()));
    return lastResult;
  }
  INT GetPointCount() const {
    INT count;
    SetStatus(DllExports::GdipGetPathGradientPointCount((GpPathGradient*) nativeBrush,&count));
    return count;
  }
  INT GetSurroundColorCount() const {
    INT count;
    SetStatus(DllExports::GdipGetPathGradientSurroundColorCount((GpPathGradient*) nativeBrush,&count));
    return count;
  }
  Status GetSurroundColors(Color *colors,INT *count) const {
    if(!colors || !count) return SetStatus(InvalidParameter);
    INT count1;
    SetStatus(DllExports::GdipGetPathGradientSurroundColorCount((GpPathGradient*) nativeBrush,&count1));
    if(lastResult!=Ok) return lastResult;
    if((*count < count1) || (count1 <= 0)) return SetStatus(InsufficientBuffer);
    ARGB *argbs = (ARGB*) new ARGB[count1];
    if(!argbs) return SetStatus(OutOfMemory);
    SetStatus(DllExports::GdipGetPathGradientSurroundColorsWithCount((GpPathGradient*)nativeBrush,argbs,&count1));
    if(lastResult==Ok) {
      for(INT i = 0;i < count1;i++) {
	colors[i].SetValue(argbs[i]);
      }
      *count = count1;
    }
    delete [] argbs;
    return lastResult;
  }
  Status SetSurroundColors(const Color *colors,INT *count) {
    if(!colors || !count) return SetStatus(InvalidParameter);
    INT count1 = GetPointCount();
    if((*count > count1) || (count1 <= 0)) return SetStatus(InvalidParameter);
    count1 = *count;
    ARGB *argbs = (ARGB*) new ARGB[count1];
    if(!argbs) return SetStatus(OutOfMemory);
    for(INT i = 0;i < count1;i++) {
      argbs[i] = colors[i].GetValue();
    }
    SetStatus(DllExports::GdipSetPathGradientSurroundColorsWithCount((GpPathGradient*)nativeBrush,argbs,&count1));
    if(lastResult==Ok) *count = count1;
    delete [] argbs;
    return lastResult;
  }
  Status GetGraphicsPath(GraphicsPath *path) const {
    if(!path) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipGetPathGradientPath((GpPathGradient*)nativeBrush,path->nativePath));
  }
  Status SetGraphicsPath(const GraphicsPath *path) {
    if(!path) return SetStatus(InvalidParameter);
    return SetStatus(DllExports::GdipSetPathGradientPath((GpPathGradient*)nativeBrush,path->nativePath));
  }
  Status GetCenterPoint(PointF *point) const { return SetStatus(DllExports::GdipGetPathGradientCenterPoint((GpPathGradient*)nativeBrush,point)); }
  Status GetCenterPoint(Point *point) const { return SetStatus(DllExports::GdipGetPathGradientCenterPointI((GpPathGradient*)nativeBrush,point)); }
  Status SetCenterPoint(const PointF &point) { return SetStatus(DllExports::GdipSetPathGradientCenterPoint((GpPathGradient*)nativeBrush,&point)); }
  Status SetCenterPoint(const Point &point) { return SetStatus(DllExports::GdipSetPathGradientCenterPointI((GpPathGradient*)nativeBrush,&point)); }
  Status GetRectangle(RectF *rect) const { return SetStatus(DllExports::GdipGetPathGradientRect((GpPathGradient*)nativeBrush,rect)); }
  Status GetRectangle(Rect *rect) const { return SetStatus(DllExports::GdipGetPathGradientRectI((GpPathGradient*)nativeBrush,rect)); }
  Status SetGammaCorrection(WINBOOL useGammaCorrection) { return SetStatus(DllExports::GdipSetPathGradientGammaCorrection((GpPathGradient*)nativeBrush,useGammaCorrection)); }
  WINBOOL GetGammaCorrection() const {
    WINBOOL useGammaCorrection;
    SetStatus(DllExports::GdipGetPathGradientGammaCorrection((GpPathGradient*)nativeBrush,&useGammaCorrection));
    return useGammaCorrection;
  }
  INT GetBlendCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetPathGradientBlendCount((GpPathGradient*) nativeBrush,&count));
    return count;
  }
  Status GetBlend(REAL *blendFactors,REAL *blendPositions,INT count) const { return SetStatus(DllExports::GdipGetPathGradientBlend((GpPathGradient*)nativeBrush,blendFactors,blendPositions,count)); }
  Status SetBlend(const REAL *blendFactors,const REAL *blendPositions,INT count) { return SetStatus(DllExports::GdipSetPathGradientBlend((GpPathGradient*)nativeBrush,blendFactors,blendPositions,count)); }
  INT GetInterpolationColorCount() const {
    INT count = 0;
    SetStatus(DllExports::GdipGetPathGradientPresetBlendCount((GpPathGradient*) nativeBrush,&count));
    return count;
  }
  Status SetInterpolationColors(const Color *presetColors,const REAL *blendPositions,INT count) {
    if((count <= 0) || !presetColors) return SetStatus(InvalidParameter);
    ARGB *argbs = (ARGB*) new ARGB[count];
    if(argbs) {
      for(INT i = 0;i < count;i++) {
	argbs[i] = presetColors[i].GetValue();
      }
      Status status = SetStatus(DllExports::GdipSetPathGradientPresetBlend((GpPathGradient*) nativeBrush,argbs,blendPositions,count));
      delete[] argbs;
      return status;
    }
    return SetStatus(OutOfMemory);
  }
  Status GetInterpolationColors(Color *presetColors,REAL *blendPositions,INT count) const {
    if((count <= 0) || !presetColors) return SetStatus(InvalidParameter);
    ARGB *argbs = (ARGB*) new ARGB[count];
    if(!argbs) return SetStatus(OutOfMemory);
    GpStatus status = SetStatus(DllExports::GdipGetPathGradientPresetBlend((GpPathGradient*)nativeBrush,argbs,blendPositions,count));
    for(INT i = 0;i < count;i++) {
      presetColors[i] = Color(argbs[i]);
    }
    delete [] argbs;
    return status;
  }
  Status SetBlendBellShape(REAL focus,REAL scale = 1.0) { return SetStatus(DllExports::GdipSetPathGradientSigmaBlend((GpPathGradient*)nativeBrush,focus,scale)); }
  Status SetBlendTriangularShape(REAL focus,REAL scale = 1.0) { return SetStatus(DllExports::GdipSetPathGradientLinearBlend((GpPathGradient*)nativeBrush,focus,scale)); }
  Status GetTransform(Matrix *matrix) const { return SetStatus(DllExports::GdipGetPathGradientTransform((GpPathGradient*) nativeBrush,matrix->nativeMatrix)); }
  Status SetTransform(const Matrix *matrix) { return SetStatus(DllExports::GdipSetPathGradientTransform((GpPathGradient*) nativeBrush,matrix->nativeMatrix)); }
  Status ResetTransform() { return SetStatus(DllExports::GdipResetPathGradientTransform((GpPathGradient*)nativeBrush)); }
  Status MultiplyTransform(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyPathGradientTransform((GpPathGradient*)nativeBrush,matrix->nativeMatrix,order)); }
  Status TranslateTransform(REAL dx,REAL dy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslatePathGradientTransform((GpPathGradient*)nativeBrush,dx,dy,order)); }
  Status ScaleTransform(REAL sx,REAL sy,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScalePathGradientTransform((GpPathGradient*)nativeBrush,sx,sy,order)); }
  Status RotateTransform(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotatePathGradientTransform((GpPathGradient*)nativeBrush,angle,order)); }
  Status GetFocusScales(REAL *xScale,REAL *yScale) const { return SetStatus(DllExports::GdipGetPathGradientFocusScales((GpPathGradient*) nativeBrush,xScale,yScale)); }
  Status SetFocusScales(REAL xScale,REAL yScale) { return SetStatus(DllExports::GdipSetPathGradientFocusScales((GpPathGradient*) nativeBrush,xScale,yScale)); }
  WrapMode GetWrapMode() const {
    WrapMode wrapMode;
    SetStatus(DllExports::GdipGetPathGradientWrapMode((GpPathGradient*) nativeBrush,&wrapMode));
    return wrapMode;
  }
  Status SetWrapMode(WrapMode wrapMode) { return SetStatus(DllExports::GdipSetPathGradientWrapMode((GpPathGradient*) nativeBrush,wrapMode)); }
private:
  PathGradientBrush(const PathGradientBrush &);
  PathGradientBrush &operator=(const PathGradientBrush &);
protected:
  PathGradientBrush() { }
};
#endif
