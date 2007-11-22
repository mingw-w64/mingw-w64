/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSTYPES_H
#define _GDIPLUSTYPES_H

extern "C" {
  typedef WINBOOL (CALLBACK *ImageAbort)(VOID *);
  typedef ImageAbort DrawImageAbort;
  typedef ImageAbort GetThumbnailImageAbort;
  typedef WINBOOL (CALLBACK *EnumerateMetafileProc)(EmfPlusRecordType,UINT,UINT,const BYTE*,VOID*);
}

typedef float REAL;

#define REAL_MAX FLT_MAX
#define REAL_MIN FLT_MIN
#define REAL_TOLERANCE (FLT_MIN *100)
#define REAL_EPSILON 1.192092896e-07F

class Size;
class SizeF;
class Point;
class PointF;
class Rect;
class RectF;
class CharacterRange;

enum Status {
  Ok = 0,GenericError = 1,InvalidParameter = 2,OutOfMemory = 3,ObjectBusy = 4,InsufficientBuffer = 5,NotImplemented = 6,Win32Error = 7,
  WrongState = 8,Aborted = 9,FileNotFound = 10,ValueOverflow = 11,AccessDenied = 12,UnknownImageFormat = 13,FontFamilyNotFound = 14,
  FontStyleNotFound = 15,NotTrueTypeFont = 16,UnsupportedGdiplusVersion = 17,GdiplusNotInitialized = 18,PropertyNotFound = 19,
  PropertyNotSupported = 20
};

class SizeF {
public:
  SizeF() { Width = Height = 0.0f; }
  SizeF(const SizeF &size) {
    Width = size.Width;
    Height = size.Height;
  }
  SizeF(REAL width,REAL height) {
    Width = width;
    Height = height;
  }
  SizeF operator+(const SizeF &sz) const { return SizeF(Width + sz.Width,Height + sz.Height); }
  SizeF operator-(const SizeF &sz) const { return SizeF(Width - sz.Width,Height - sz.Height); }
  WINBOOL Equals(const SizeF &sz) const { return (Width==sz.Width) &&(Height==sz.Height); }
  WINBOOL Empty() const { return (Width==0.0f &&Height==0.0f); }
public:
  REAL Width;
  REAL Height;
};

class Size {
public:
  Size() { Width = Height = 0; }
  Size(const Size &size) {
    Width = size.Width;
    Height = size.Height;
  }
  Size(INT width,INT height) {
    Width = width;
    Height = height;
  }
  Size operator+(const Size &sz) const { return Size(Width + sz.Width,Height + sz.Height); }
  Size operator-(const Size &sz) const { return Size(Width - sz.Width,Height - sz.Height); }
  WINBOOL Equals(const Size &sz) const { return (Width==sz.Width) &&(Height==sz.Height); }
  WINBOOL Empty() const { return (Width==0 &&Height==0); }
public:
  INT Width;
  INT Height;
};

class PointF {
public:
  PointF() { X = Y = 0.0f; }
  PointF(const PointF &point) {
    X = point.X;
    Y = point.Y;
  }
  PointF(const SizeF &size) {
    X = size.Width;
    Y = size.Height;
  }
  PointF(REAL x,REAL y) {
    X = x;
    Y = y;
  }
  PointF operator+(const PointF &point) const { return PointF(X + point.X,Y + point.Y); }
  PointF operator-(const PointF &point) const { return PointF(X - point.X,Y - point.Y); }
  WINBOOL Equals(const PointF &point) { return (X==point.X) &&(Y==point.Y); }
public:
  REAL X;
  REAL Y;
};

class Point {
public:
  Point() { X = Y = 0; }
  Point(const Point &point) {
    X = point.X;
    Y = point.Y;
  }
  Point(const Size &size) {
    X = size.Width;
    Y = size.Height;
  }
  Point(INT x,INT y) {
    X = x;
    Y = y;
  }
  Point operator+(const Point &point) const { return Point(X + point.X,Y + point.Y); }
  Point operator-(const Point &point) const { return Point(X - point.X,Y - point.Y); }
  WINBOOL Equals(const Point &point) { return (X==point.X) &&(Y==point.Y); }
public:
  INT X;
  INT Y;
};

class RectF {
public:
  RectF() { X = Y = Width = Height = 0.0f; }
  RectF(REAL x,REAL y,REAL width,REAL height) {
    X = x;
    Y = y;
    Width = width;
    Height = height;
  }
  RectF(const PointF &location,const SizeF &size) {
    X = location.X;
    Y = location.Y;
    Width = size.Width;
    Height = size.Height;
  }
  RectF *Clone() const { return new RectF(X,Y,Width,Height); }
  VOID GetLocation(PointF *point) const {
    point->X = X;
    point->Y = Y;
  }
  VOID GetSize(SizeF *size) const {
    size->Width = Width;
    size->Height = Height;
  }
  VOID GetBounds(RectF *rect) const {
    rect->X = X;
    rect->Y = Y;
    rect->Width = Width;
    rect->Height = Height;
  }
  REAL GetLeft() const { return X; }
  REAL GetTop() const { return Y; }
  REAL GetRight() const { return X+Width; }
  REAL GetBottom() const { return Y+Height; }
  WINBOOL IsEmptyArea() const { return (Width <= REAL_EPSILON) || (Height <= REAL_EPSILON); }
  WINBOOL Equals(const RectF &rect) const { return X==rect.X && Y==rect.Y && Width==rect.Width && Height==rect.Height; }
  WINBOOL Contains(REAL x,REAL y) const { return x >= X && x < X+Width && y >= Y && y < Y+Height; }
  WINBOOL Contains(const PointF &pt) const { return Contains(pt.X,pt.Y); }
  WINBOOL Contains(const RectF &rect) const { return (X <= rect.X) && (rect.GetRight() <= GetRight()) && (Y <= rect.Y) && (rect.GetBottom() <= GetBottom()); }
  VOID Inflate(REAL dx,REAL dy) {
    X -= dx;
    Y -= dy;
    Width += 2*dx;
    Height += 2*dy;
  }
  VOID Inflate(const PointF &point) { Inflate(point.X,point.Y); }
  WINBOOL Intersect(const RectF &rect) { return Intersect(*this,*this,rect); }
  static WINBOOL Intersect(RectF &c,const RectF &a,const RectF &b) {
    REAL right = min(a.GetRight(),b.GetRight());
    REAL bottom = min(a.GetBottom(),b.GetBottom());
    REAL left = max(a.GetLeft(),b.GetLeft());
    REAL top = max(a.GetTop(),b.GetTop());
    c.X = left;
    c.Y = top;
    c.Width = right - left;
    c.Height = bottom - top;
    return !c.IsEmptyArea();
  }
  WINBOOL IntersectsWith(const RectF &rect) const { return (GetLeft() < rect.GetRight() && GetTop() < rect.GetBottom() && GetRight() > rect.GetLeft() && GetBottom() > rect.GetTop()); }
  static WINBOOL Union(RectF &c,const RectF &a,const RectF &b) {
    REAL right = max(a.GetRight(),b.GetRight());
    REAL bottom = max(a.GetBottom(),b.GetBottom());
    REAL left = min(a.GetLeft(),b.GetLeft());
    REAL top = min(a.GetTop(),b.GetTop());
    c.X = left;
    c.Y = top;
    c.Width = right - left;
    c.Height = bottom - top;
    return !c.IsEmptyArea();
  }
  VOID Offset(const PointF &point) { Offset(point.X,point.Y); }
  VOID Offset(REAL dx,REAL dy) {
    X += dx;
    Y += dy;
  }
public:
  REAL X;
  REAL Y;
  REAL Width;
  REAL Height;
};

class Rect {
public:
  Rect() { X = Y = Width = Height = 0; }
  Rect(INT x,INT y,INT width,INT height) {
    X = x;
    Y = y;
    Width = width;
    Height = height;
  }
  Rect(const Point &location,const Size &size) {
    X = location.X;
    Y = location.Y;
    Width = size.Width;
    Height = size.Height;
  }
  Rect *Clone() const { return new Rect(X,Y,Width,Height); }
  VOID GetLocation(Point *point) const {
    point->X = X;
    point->Y = Y;
  }
  VOID GetSize(Size *size) const {
    size->Width = Width;
    size->Height = Height;
  }
  VOID GetBounds(Rect *rect) const {
    rect->X = X;
    rect->Y = Y;
    rect->Width = Width;
    rect->Height = Height;
  }
  INT GetLeft() const { return X; }
  INT GetTop() const { return Y; }
  INT GetRight() const { return X+Width; }
  INT GetBottom() const { return Y+Height; }
  WINBOOL IsEmptyArea() const { return (Width <= 0) || (Height <= 0); }
  WINBOOL Equals(const Rect &rect) const { return X==rect.X && Y==rect.Y && Width==rect.Width && Height==rect.Height; }
  WINBOOL Contains(INT x,INT y) const { return x >= X && x < X+Width && y >= Y && y < Y+Height; }
  WINBOOL Contains(const Point &pt) const { return Contains(pt.X,pt.Y); }
  WINBOOL Contains(Rect &rect) const { return (X <= rect.X) && (rect.GetRight() <= GetRight()) && (Y <= rect.Y) && (rect.GetBottom() <= GetBottom()); }
  VOID Inflate(INT dx,INT dy) {
    X -= dx;
    Y -= dy;
    Width += 2*dx;
    Height += 2*dy;
  }
  VOID Inflate(const Point &point) { Inflate(point.X,point.Y); }
  WINBOOL Intersect(const Rect &rect) { return Intersect(*this,*this,rect); }
  static WINBOOL Intersect(Rect &c,const Rect &a,const Rect &b) {
    INT right = min(a.GetRight(),b.GetRight());
    INT bottom = min(a.GetBottom(),b.GetBottom());
    INT left = max(a.GetLeft(),b.GetLeft());
    INT top = max(a.GetTop(),b.GetTop());
    c.X = left;
    c.Y = top;
    c.Width = right - left;
    c.Height = bottom - top;
    return !c.IsEmptyArea();
  }
  WINBOOL IntersectsWith(const Rect &rect) const { return (GetLeft() < rect.GetRight() && GetTop() < rect.GetBottom() && GetRight() > rect.GetLeft() && GetBottom() > rect.GetTop()); }
  static WINBOOL Union(Rect &c,const Rect &a,const Rect &b) {
    INT right = max(a.GetRight(),b.GetRight());
    INT bottom = max(a.GetBottom(),b.GetBottom());
    INT left = min(a.GetLeft(),b.GetLeft());
    INT top = min(a.GetTop(),b.GetTop());
    c.X = left;
    c.Y = top;
    c.Width = right - left;
    c.Height = bottom - top;
    return !c.IsEmptyArea();
  }
  VOID Offset(const Point &point) { Offset(point.X,point.Y); }
  VOID Offset(INT dx,INT dy) {
    X += dx;
    Y += dy;
  }
public:
  INT X;
  INT Y;
  INT Width;
  INT Height;
};

class PathData {
public:
  PathData() {
    Count = 0;
    Points = NULL;
    Types = NULL;
  }
  ~PathData() {
    if(Points!=NULL) delete Points;
    if(Types!=NULL) delete Types;
  }
private:
  PathData(const PathData &);
  PathData &operator=(const PathData &);
public:
  INT Count;
  PointF *Points;
  BYTE *Types;
};

class CharacterRange {
public:
  CharacterRange(INT first,INT length) : First(first),Length(length) { }
  CharacterRange() : First(0),Length(0) { }
  CharacterRange &operator = (const CharacterRange &rhs) {
    First = rhs.First;
    Length = rhs.Length;
    return *this;
  }
  INT First;
  INT Length;
};

#endif
