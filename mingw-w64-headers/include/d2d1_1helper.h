/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef _D2D1_1HELPER_H_
#define _D2D1_1HELPER_H_

#ifndef D2D_USE_C_DEFINITIONS

namespace D2D1 {

    D2D1FORCEINLINE D2D1_VECTOR_2F Vector2F(FLOAT x = 0.0f, FLOAT y = 0.0f) {
        D2D1_VECTOR_2F r = {x, y};
        return r;
    }

    D2D1FORCEINLINE D2D1_LAYER_PARAMETERS1 LayerParameters1(CONST D2D1_RECT_F &contentBounds = D2D1::InfiniteRect(),
            ID2D1Geometry *geometricMask = NULL, D2D1_ANTIALIAS_MODE maskAntialiasMode = D2D1_ANTIALIAS_MODE_PER_PRIMITIVE,
            D2D1_MATRIX_3X2_F maskTransform = D2D1::IdentityMatrix(), FLOAT opacity = 1.0, ID2D1Brush *opacityBrush = NULL,
            D2D1_LAYER_OPTIONS1 layerOptions = D2D1_LAYER_OPTIONS1_NONE) {
        D2D1_LAYER_PARAMETERS1 r = {contentBounds, geometricMask, maskAntialiasMode, maskTransform, opacity,
                                    opacityBrush, layerOptions};
        return r;
    }

    D2D1FORCEINLINE D2D1_IMAGE_BRUSH_PROPERTIES ImageBrushProperties(D2D1_RECT_F sourceRectangle,
            D2D1_EXTEND_MODE extendModeX = D2D1_EXTEND_MODE_CLAMP, D2D1_EXTEND_MODE extendModeY = D2D1_EXTEND_MODE_CLAMP,
            D2D1_INTERPOLATION_MODE interpolationMode = D2D1_INTERPOLATION_MODE_LINEAR) {
        D2D1_IMAGE_BRUSH_PROPERTIES r = {sourceRectangle, extendModeX, extendModeY, interpolationMode};
        return r;
    }

    D2D1FORCEINLINE D2D1_BITMAP_PROPERTIES1 BitmapProperties1(D2D1_BITMAP_OPTIONS bitmapOptions = D2D1_BITMAP_OPTIONS_NONE,
            CONST D2D1_PIXEL_FORMAT pixelFormat = D2D1::PixelFormat(), FLOAT dpiX = 96.0f, FLOAT dpiY = 96.0f,
            ID2D1ColorContext *colorContext = NULL) {
        D2D1_BITMAP_PROPERTIES1 r = {pixelFormat, dpiX, dpiY, bitmapOptions, colorContext};
        return r;
    }

}

#endif /* D2D_USE_C_DEFINITIONS */

#endif /* _D2D1_1HELPER_H_ */
