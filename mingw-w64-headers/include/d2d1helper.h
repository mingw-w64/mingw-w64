/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_D2D1HELPER
#define _INC_D2D1HELPER

#ifdef __cplusplus

namespace D2D1 {

D2D1FORCEINLINE D2D1_MATRIX_3X2_F IdentityMatrix();

static inline FLOAT FloatMax() {
    return 3.402823466e+38f;
}

D2D1FORCEINLINE D2D1_POINT_2F Point2F(FLOAT x = 0.f, FLOAT y = 0.f) {
    D2D1_POINT_2F r = {x,y};
    return r;
}

D2D1FORCEINLINE D2D1_SIZE_F SizeF(FLOAT width = 0.0f, FLOAT height = 0.0f) {
    D2D1_SIZE_F r = {width, height};
    return r;
}

D2D1FORCEINLINE D2D1_SIZE_U SizeU(UINT32 width = 0, UINT32 height = 0) {
    D2D1_SIZE_U r = {width, height};
    return r;
}

D2D1FORCEINLINE D2D1_RECT_F RectF(FLOAT left = 0.0f, FLOAT top = 0.0f, FLOAT right = 0.0f, FLOAT bottom = 0.0f) {
    D2D1_RECT_F r = {left, top, right, bottom};
    return r;
}

D2D1FORCEINLINE D2D1_RECT_F InfiniteRect() {
    D2D1_RECT_F r = {-FloatMax(), -FloatMax(), FloatMax(),  FloatMax()};
    return r;
}

D2D1FORCEINLINE D2D1_ARC_SEGMENT ArcSegment(const D2D1_POINT_2F &point, const D2D1_SIZE_F &size, const FLOAT rotationAngle, D2D1_SWEEP_DIRECTION sweepDirection, D2D1_ARC_SIZE arcSize) {
    D2D1_ARC_SEGMENT r = {point, size, rotationAngle, sweepDirection, arcSize};
    return r;
}

D2D1FORCEINLINE D2D1_BEZIER_SEGMENT BezierSegment(const D2D1_POINT_2F &point1, const D2D1_POINT_2F &point2, const D2D1_POINT_2F &point3) {
    D2D1_BEZIER_SEGMENT r = {point1, point2, point3};
    return r;
}

D2D1FORCEINLINE D2D1_BRUSH_PROPERTIES BrushProperties(
        FLOAT opacity = 1.0f,
        const D2D1_MATRIX_3X2_F &transform = D2D1::IdentityMatrix()) {
    D2D1_BRUSH_PROPERTIES r = {opacity, transform};
    return r;
}

D2D1FORCEINLINE D2D1_QUADRATIC_BEZIER_SEGMENT QuadraticBezierSegment(const D2D1_POINT_2F &point1, const D2D1_POINT_2F &point2) {
    D2D1_QUADRATIC_BEZIER_SEGMENT r = {point1, point2};
    return r;
}

D2D1FORCEINLINE D2D1_STROKE_STYLE_PROPERTIES StrokeStyleProperties(
        D2D1_CAP_STYLE startCap = D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE endCap = D2D1_CAP_STYLE_FLAT,
        D2D1_CAP_STYLE dashCap = D2D1_CAP_STYLE_FLAT,
        D2D1_LINE_JOIN lineJoin = D2D1_LINE_JOIN_MITER,
        FLOAT miterLimit = 10.0f,
        D2D1_DASH_STYLE dashStyle = D2D1_DASH_STYLE_SOLID,
        FLOAT dashOffset = 0.0f) {
    D2D1_STROKE_STYLE_PROPERTIES r = {startCap, endCap, dashCap, lineJoin, miterLimit, dashStyle, dashOffset};
    return r;
}

D2D1FORCEINLINE D2D1_BITMAP_BRUSH_PROPERTIES BitmapBrushProperties(
        D2D1_EXTEND_MODE extendModeX = D2D1_EXTEND_MODE_CLAMP,
        D2D1_EXTEND_MODE extendModeY = D2D1_EXTEND_MODE_CLAMP,
        D2D1_BITMAP_INTERPOLATION_MODE interpolationMode = D2D1_BITMAP_INTERPOLATION_MODE_LINEAR) {
    D2D1_BITMAP_BRUSH_PROPERTIES r = {extendModeX, extendModeY, interpolationMode};
    return r;
}

D2D1FORCEINLINE D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES LinearGradientBrushProperties(const D2D1_POINT_2F &startPoint, const D2D1_POINT_2F &endPoint) {
    D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES r = {startPoint, endPoint};
    return r;
}

D2D1FORCEINLINE D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES RadialGradientBrushProperties(const D2D1_POINT_2F &center, const D2D1_POINT_2F &gradientOriginOffset, FLOAT radiusX, FLOAT radiusY) {
    D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES r = {center, gradientOriginOffset, radiusX, radiusY};
    return r;
}

D2D1FORCEINLINE D2D1_PIXEL_FORMAT PixelFormat(
        DXGI_FORMAT dxgiFormat = DXGI_FORMAT_UNKNOWN,
        D2D1_ALPHA_MODE alphaMode = D2D1_ALPHA_MODE_UNKNOWN)
{
    D2D1_PIXEL_FORMAT r = {dxgiFormat, alphaMode};
    return r;
}

D2D1FORCEINLINE D2D1_BITMAP_PROPERTIES BitmapProperties(CONST D2D1_PIXEL_FORMAT &pixelFormat = D2D1::PixelFormat(),
        FLOAT dpiX = 96.0f, FLOAT dpiY = 96.0f) {
    D2D1_BITMAP_PROPERTIES r = {pixelFormat, dpiX, dpiY};
    return r;
}

D2D1FORCEINLINE D2D1_RENDER_TARGET_PROPERTIES RenderTargetProperties(
        D2D1_RENDER_TARGET_TYPE type =  D2D1_RENDER_TARGET_TYPE_DEFAULT,
        CONST D2D1_PIXEL_FORMAT &pixelFormat = D2D1::PixelFormat(),
        FLOAT dpiX = 0.0,
        FLOAT dpiY = 0.0,
        D2D1_RENDER_TARGET_USAGE usage = D2D1_RENDER_TARGET_USAGE_NONE,
        D2D1_FEATURE_LEVEL  minLevel = D2D1_FEATURE_LEVEL_DEFAULT)
{
    D2D1_RENDER_TARGET_PROPERTIES r = {type, pixelFormat, dpiX, dpiY, usage, minLevel};
    return r;
}

D2D1FORCEINLINE D2D1_LAYER_PARAMETERS LayerParameters(
        CONST D2D1_RECT_F &contentBounds = D2D1::InfiniteRect(),
        ID2D1Geometry *geometricMask = NULL,
        D2D1_ANTIALIAS_MODE maskAntialiasMode = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
        D2D1_MATRIX_3X2_F maskTransform = D2D1::IdentityMatrix(),
        FLOAT opacity = 1.0,
        ID2D1Brush *opacityBrush = NULL,
        D2D1_LAYER_OPTIONS layerOptions = D2D1_LAYER_OPTIONS_NONE) {
    D2D1_LAYER_PARAMETERS r =
        {contentBounds, geometricMask, maskAntialiasMode, maskTransform, opacity, opacityBrush, layerOptions };
    return r;
}

class ColorF : public D2D1_COLOR_F {
public:
    enum Enum {
        AliceBlue = 0xF0F8FF
        /* FIXME: fill with values */
    };

    FORCEINLINE ColorF(UINT32 rgb, FLOAT _a = 1.0) {
        init(rgb, _a);
    }

    D2D1FORCEINLINE ColorF(Enum knownColor, FLOAT _a = 1.0) {
        init(knownColor, _a);
    }

    D2D1FORCEINLINE ColorF(FLOAT _r, FLOAT _g, FLOAT _b, FLOAT _a = 1.0) {
        r = _r;
        g = _g;
        b = _b;
        a = _a;
    }
private:
    D2D1FORCEINLINE void init(UINT32 rgb, FLOAT _a) {
        r = static_cast<float>((rgb>>16)&0xff)/255.0f;
        g = static_cast<float>((rgb>>8)&0xff)/255.0f;
        b = static_cast<float>(rgb&0xff)/255.0f;
        a = _a;
    }
};

class Matrix3x2F : public D2D1_MATRIX_3X2_F {
public:
    D2D1FORCEINLINE Matrix3x2F(FLOAT __11, FLOAT __12, FLOAT __21, FLOAT __22, FLOAT __31, FLOAT __32) {
        _11 = __11;
        _12 = __12;
        _21 = __21;
        _22 = __22;
        _31 = __31;
        _32 = __32;
    }

    D2D1FORCEINLINE Matrix3x2F() {}

    static D2D1FORCEINLINE Matrix3x2F Identity() {
        return Matrix3x2F(1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    }
};

D2D1FORCEINLINE D2D1_MATRIX_3X2_F IdentityMatrix() {
    return Matrix3x2F::Identity();
}

}

#endif /* __cplusplus */

#endif /*_INC_D2D1HELPER*/
