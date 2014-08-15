/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef DWRITE_1_H_INCLUDED
#define DWRITE_1_H_INCLUDED

#include <dwrite.h>

enum DWRITE_OUTLINE_THRESHOLD {
    DWRITE_OUTLINE_THRESHOLD_ANTIALIASED,
    DWRITE_OUTLINE_THRESHOLD_ALIASED
};

struct DWRITE_CARET_METRICS {
    INT16 slopeRise;
    INT16 slopeRun;
    INT16 offset;
};

struct DWRITE_UNICODE_RANGE {
    UINT32 first;
    UINT32 last;
};

struct DWRITE_FONT_METRICS1 : public DWRITE_FONT_METRICS {
    INT16 glyphBoxLeft;
    INT16 glyphBoxTop;
    INT16 glyphBoxRight;
    INT16 glyphBoxBottom;
    INT16 subscriptPositionX;
    INT16 subscriptPositionY;
    INT16 subscriptSizeX;
    INT16 subscriptSizeY;
    INT16 superscriptPositionX;
    INT16 superscriptPositionY;
    INT16 superscriptSizeX;
    INT16 superscriptSizeY;
    BOOL hasTypographicMetrics;
};

#undef  INTERFACE
#define INTERFACE IDWriteFontCollection
DECLARE_INTERFACE_(IDWriteFontFace1, IDWriteFontFace)
{
    BEGIN_INTERFACE

#ifndef __cplusplus
    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDWriteFontFace methods */
    STDMETHOD_(DWRITE_FONT_FACE_TYPE, GetType)(THIS) PURE;

    STDMETHOD(GetFiles)(THIS_
        UINT32 *numberOfFiles,
        IDWriteFontFile **fontFiles) PURE;

    STDMETHOD_(UINT32, GetIndex)(THIS) PURE;
    STDMETHOD_(DWRITE_FONT_SIMULATIONS, GetSimulations)(THIS) PURE;
    STDMETHOD_(WINBOOL, IsSymbolFont)(THIS) PURE;

    STDMETHOD_(void, GetMetrics)(THIS_
        DWRITE_FONT_METRICS *fontFaceMetrics) PURE;

    STDMETHOD_(UINT16, GetGlyphCount)(THIS) PURE;

    STDMETHOD(GetDesignGlyphMetrics)(THIS_
        UINT16 const *glyphIndices,
        UINT32 glyphCount,
        DWRITE_GLYPH_METRICS *glyphMetrics,
        WINBOOL isSideways __MINGW_DEF_ARG_VAL(FALSE)) PURE;

    STDMETHOD(GetGlyphIndices)(THIS_
        UINT32 const *codePoints,
        UINT32 codePointCount,
        UINT16 *glyphIndices) PURE;

    STDMETHOD(TryGetFontTable)(THIS_
        UINT32 openTypeTableTag,
        const void **tableData,
        UINT32 *tableSize,
        void **tableContext,
        WINBOOL *exists) PURE;

    STDMETHOD_(void, ReleaseFontTable)(THIS_
        void *tableContext) PURE;

    STDMETHOD(GetGlyphRunOutline)(THIS_
        FLOAT emSize,
        UINT16 const *glyphIndices,
        FLOAT const *glyphAdvances,
        DWRITE_GLYPH_OFFSET const *glyphOffsets,
        UINT32 glyphCount,
        WINBOOL isSideways,
        WINBOOL isRightToLeft,
        IDWriteGeometrySink *geometrySink) PURE;

    STDMETHOD(GetRecommendedRenderingMode)(THIS_
        FLOAT emSize,
        FLOAT pixelsPerDip,
        DWRITE_MEASURING_MODE measuringMode,
        IDWriteRenderingParams *renderingParams,
        DWRITE_RENDERING_MODE *renderingMode) PURE;

    STDMETHOD(GetGdiCompatibleMetrics)(THIS_
        FLOAT emSize,
        FLOAT pixelsPerDip,
        DWRITE_MATRIX const *transform,
        DWRITE_FONT_METRICS *fontFaceMetrics) PURE;


    STDMETHOD(GetGdiCompatibleGlyphMetrics)(THIS_
        FLOAT emSize,
        FLOAT pixelsPerDip,
        DWRITE_MATRIX const *transform,
        WINBOOL useGdiNatural,
        UINT16 const *glyphIndices,
        UINT32 glyphCount,
        DWRITE_GLYPH_METRICS *glyphMetrics,
        WINBOOL isSideways __MINGW_DEF_ARG_VAL(FALSE)) PURE;
#endif

    /* IDWriteFontFace1 methods */
    STDMETHOD_(void, GetMetrics)(THIS_ DWRITE_FONT_METRICS*) PURE;
    STDMETHOD(GetGdiCompatibleMetrics)(THIS_ FLOAT,FLOAT,DWRITE_MATRIX const*,DWRITE_FONT_METRICS1*) PURE;
    STDMETHOD_(void, GetCaretMetrics)(THIS_ DWRITE_CARET_METRICS*) PURE;
    STDMETHOD(GetUnicodeRanges)(THIS_ UINT32, DWRITE_UNICODE_RANGE*,UINT32*) PURE;
    STDMETHOD_(BOOL, IsMonospacedFont)(THIS) PURE;
    STDMETHOD(GetDesignGlyphAdvances)(THIS_ UINT32,UINT16 const*,INT32*,BOOL isSideways __MINGW_DEF_ARG_VAL(FALSE)) PURE;
    STDMETHOD(GetGdiCompatibleGlyphAdvances)(THIS_ FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,BOOL,UINT32,
            UINT16 const*,INT32*) PURE;
    STDMETHOD(GetKerningPairAdjustments)(THIS_ UINT32,UINT16 const*,INT32*) PURE;
    STDMETHOD_(BOOL, HasKerningPairs)(THIS);
    STDMETHOD(GetRecommendedRenderingMode)(FLOAT,FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,
            DWRITE_OUTLINE_THRESHOLD,DWRITE_MEASURING_MODE,DWRITE_RENDERING_MODE*) PURE;
    STDMETHOD(GetVerticalGlyphVariants)(THIS_ UINT32,UINT16 const*,UINT16*);
    STDMETHOD_(BOOL, HasVerticalGlyphVariants)(THIS);
};

__CRT_UUID_DECL(IDWriteFontFace1, 0xa71efdb4,0x9fdb,0x4838,0xad,0x90,0xcf,0xc3,0xbe,0x8c,0x3d,0xaf);


#endif /* DWRITE_1_H_INCLUDED */
