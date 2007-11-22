/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
class Matrix : public GdiplusBase {
public:
  friend class Graphics;
  friend class GraphicsPath;
  friend class TextureBrush;
  friend class LinearGradientBrush;
  friend class PathGradientBrush;
  friend class Pen;
  friend class Region;
  Matrix() {
    GpMatrix *matrix = NULL;
    lastResult = DllExports::GdipCreateMatrix(&matrix);
    SetNativeMatrix(matrix);
  }
  Matrix(REAL m11,REAL m12,REAL m21,REAL m22,REAL dx,REAL dy) {
    GpMatrix *matrix = NULL;
    lastResult = DllExports::GdipCreateMatrix2(m11,m12,m21,m22,dx,dy,&matrix);
    SetNativeMatrix(matrix);
  }
  Matrix(const RectF &rect,const PointF *dstplg) {
    GpMatrix *matrix = NULL;
    lastResult = DllExports::GdipCreateMatrix3(&rect,dstplg,&matrix);
    SetNativeMatrix(matrix);
  }
  Matrix(const Rect &rect,const Point *dstplg) {
    GpMatrix *matrix = NULL;
    lastResult = DllExports::GdipCreateMatrix3I(&rect,dstplg,&matrix);
    SetNativeMatrix(matrix);
  }
  ~Matrix() { DllExports::GdipDeleteMatrix(nativeMatrix); }
  Matrix *Clone() const {
    GpMatrix *cloneMatrix = NULL;
    SetStatus(DllExports::GdipCloneMatrix(nativeMatrix,&cloneMatrix));
    if(lastResult!=Ok) return NULL;
    return new Matrix(cloneMatrix);
  }
  Status GetElements(REAL *m) const { return SetStatus(DllExports::GdipGetMatrixElements(nativeMatrix,m)); }
  Status SetElements(REAL m11,REAL m12,REAL m21,REAL m22,REAL dx,REAL dy) { return SetStatus(DllExports::GdipSetMatrixElements(nativeMatrix,m11,m12,m21,m22,dx,dy)); }
  REAL OffsetX() const {
    REAL elements[6];
    if(GetElements(&elements[0])==Ok) return elements[4];
    else return 0.0f;
  }
  REAL OffsetY() const {
    REAL elements[6];
    if(GetElements(&elements[0])==Ok) return elements[5];
    else return 0.0f;
  }
  Status Reset() { return SetStatus(DllExports::GdipSetMatrixElements(nativeMatrix,1.0,0.0,0.0,1.0,0.0,0.0)); }
  Status Multiply(const Matrix *matrix,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipMultiplyMatrix(nativeMatrix,matrix->nativeMatrix,order)); }
  Status Translate(REAL offsetX,REAL offsetY,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipTranslateMatrix(nativeMatrix,offsetX,offsetY,order)); }
  Status Scale(REAL scaleX,REAL scaleY,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipScaleMatrix(nativeMatrix,scaleX,scaleY,order)); }
  Status Rotate(REAL angle,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipRotateMatrix(nativeMatrix,angle,order)); }
  Status RotateAt(REAL angle,const PointF &center,MatrixOrder order = MatrixOrderPrepend) {
    if(order==MatrixOrderPrepend) {
      SetStatus(DllExports::GdipTranslateMatrix(nativeMatrix,center.X,center.Y,order));
      SetStatus(DllExports::GdipRotateMatrix(nativeMatrix,angle,order));
      return SetStatus(DllExports::GdipTranslateMatrix(nativeMatrix,-center.X,-center.Y,order));
    } else {
      SetStatus(DllExports::GdipTranslateMatrix(nativeMatrix,- center.X,- center.Y,order));
      SetStatus(DllExports::GdipRotateMatrix(nativeMatrix,angle,order));
      return SetStatus(DllExports::GdipTranslateMatrix(nativeMatrix,center.X,center.Y,order));
    }
  }
  Status Shear(REAL shearX,REAL shearY,MatrixOrder order = MatrixOrderPrepend) { return SetStatus(DllExports::GdipShearMatrix(nativeMatrix,shearX,shearY,order)); }
  Status Invert() { return SetStatus(DllExports::GdipInvertMatrix(nativeMatrix)); }
  Status TransformPoints(PointF *pts,INT count = 1) const { return SetStatus(DllExports::GdipTransformMatrixPoints(nativeMatrix,pts,count)); }
  Status TransformPoints(Point *pts,INT count = 1) const { return SetStatus(DllExports::GdipTransformMatrixPointsI(nativeMatrix,pts,count)); }
  Status TransformVectors(PointF *pts,INT count = 1) const { return SetStatus(DllExports::GdipVectorTransformMatrixPoints(nativeMatrix,pts,count)); }
  Status TransformVectors(Point *pts,INT count = 1) const { return SetStatus(DllExports::GdipVectorTransformMatrixPointsI(nativeMatrix,pts,count)); }
  WINBOOL IsInvertible() const {
    WINBOOL result = FALSE;
    SetStatus(DllExports::GdipIsMatrixInvertible(nativeMatrix,&result));
    return result;
  }
  WINBOOL IsIdentity() const {
    WINBOOL result = FALSE;
    SetStatus(DllExports::GdipIsMatrixIdentity(nativeMatrix,&result));
    return result;
  }
  WINBOOL Equals(const Matrix *matrix) const {
    WINBOOL result = FALSE;
    SetStatus(DllExports::GdipIsMatrixEqual(nativeMatrix,matrix->nativeMatrix,&result));
    return result;
  }
  Status GetLastStatus() const {
    Status lastStatus = lastResult;
    lastResult = Ok;
    return lastStatus;
  }
private:
  Matrix(const Matrix &);
  Matrix &operator=(const Matrix &);
protected:
  Matrix(GpMatrix *nativeMatrix) {
    lastResult = Ok;
    SetNativeMatrix(nativeMatrix);
  }
  VOID SetNativeMatrix(GpMatrix *nativeMatrix) {
    this->nativeMatrix = nativeMatrix;
  }
  Status SetStatus(Status status) const {
    if(status!=Ok) return (lastResult = status);
    else return status;
  }
protected:
  GpMatrix *nativeMatrix;
  mutable Status lastResult;
};
