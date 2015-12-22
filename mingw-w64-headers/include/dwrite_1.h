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

enum DWRITE_TEXT_ANTIALIAS_MODE
{
    DWRITE_TEXT_ANTIALIAS_MODE_CLEARTYPE,
    DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE
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

#undef  INTERFACE
#define INTERFACE IDWriteRenderingParams1
DECLARE_INTERFACE_(IDWriteRenderingParams1,IDWriteRenderingParams)
{
    BEGIN_INTERFACE

#ifndef __cplusplus
    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDWriteRenderingParams methods */
    STDMETHOD_(FLOAT, GetGamma)(THIS) PURE;
    STDMETHOD_(FLOAT, GetEnhancedContrast)(THIS) PURE;
    STDMETHOD_(FLOAT, GetClearTypeLevel)(THIS) PURE;
    STDMETHOD_(DWRITE_PIXEL_GEOMETRY, GetPixelGeometry)(THIS) PURE;
    STDMETHOD_(DWRITE_RENDERING_MODE, GetRenderingMode)(THIS) PURE;
#endif

    /* IDWriteRenderingParams1 methods */
    STDMETHOD_(FLOAT, GetGrayscaleEnhancedContrast)(THIS) PURE;

    END_INTERFACE
};

__CRT_UUID_DECL(IDWriteRenderingParams1, 0x94413cf4,0xa6fc,0x4248,0x8b,0x50,0x66,0x74,0x34,0x8f,0xca,0xd3)

#undef  INTERFACE
#define INTERFACE IDWriteFactory1
DECLARE_INTERFACE_(IDWriteFactory1,IDWriteFactory)
{
    BEGIN_INTERFACE

#ifndef __cplusplus
    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDWriteFactory methods */
    STDMETHOD(GetSystemFontCollection)(THIS_
        IDWriteFontCollection **fontCollection,
        WINBOOL checkForUpdates __MINGW_DEF_ARG_VAL(FALSE)) PURE;

    STDMETHOD(CreateCustomFontCollection)(THIS_
        IDWriteFontCollectionLoader *collectionLoader,
        void const *collectionKey,
        UINT32 collectionKeySize,
        IDWriteFontCollection **fontCollection) PURE;

    STDMETHOD(RegisterFontCollectionLoader)(THIS_
        IDWriteFontCollectionLoader *fontCollectionLoader) PURE;

    STDMETHOD(UnregisterFontCollectionLoader)(THIS_
        IDWriteFontCollectionLoader *fontCollectionLoader) PURE;

    STDMETHOD(CreateFontFileReference)(THIS_
        WCHAR const *filePath,
        FILETIME const *lastWriteTime,
        IDWriteFontFile **fontFile) PURE;

    STDMETHOD(CreateCustomFontFileReference)(THIS_
        void const *fontFileReferenceKey,
        UINT32 fontFileReferenceKeySize,
        IDWriteFontFileLoader *fontFileLoader,
        IDWriteFontFile **fontFile) PURE;

    STDMETHOD(CreateFontFace)(THIS_
        DWRITE_FONT_FACE_TYPE fontFaceType,
        UINT32 numberOfFiles,
        IDWriteFontFile *const *fontFiles,
        UINT32 faceIndex,
        DWRITE_FONT_SIMULATIONS fontFaceSimulationFlags,
        IDWriteFontFace **fontFace) PURE;

    STDMETHOD(CreateRenderingParams)(THIS_
        IDWriteRenderingParams **renderingParams) PURE;

    STDMETHOD(CreateMonitorRenderingParams)(THIS_
        HMONITOR monitor,
        IDWriteRenderingParams **renderingParams) PURE;

    STDMETHOD(CreateCustomRenderingParams)(THIS_
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        IDWriteRenderingParams **renderingParams) PURE;

    STDMETHOD(RegisterFontFileLoader)(THIS_
        IDWriteFontFileLoader *fontFileLoader) PURE;

    STDMETHOD(UnregisterFontFileLoader)(THIS_
        IDWriteFontFileLoader *fontFileLoader) PURE;

    STDMETHOD(CreateTextFormat)(THIS_
        WCHAR const *fontFamilyName,
        IDWriteFontCollection *fontCollection,
        DWRITE_FONT_WEIGHT fontWeight,
        DWRITE_FONT_STYLE fontStyle,
        DWRITE_FONT_STRETCH fontStretch,
        FLOAT fontSize,
        WCHAR const *localeName,
        IDWriteTextFormat **textFormat) PURE;

    STDMETHOD(CreateTypography)(THIS_
        IDWriteTypography **typography) PURE;

    STDMETHOD(GetGdiInterop)(THIS_
        IDWriteGdiInterop **gdiInterop) PURE;

    STDMETHOD(CreateTextLayout)(THIS_
        WCHAR const *string,
        UINT32 stringLength,
        IDWriteTextFormat *textFormat,
        FLOAT maxWidth,
        FLOAT maxHeight,
        IDWriteTextLayout **textLayout) PURE;

    STDMETHOD(CreateGdiCompatibleTextLayout)(THIS_
        WCHAR const *string,
        UINT32 stringLength,
        IDWriteTextFormat *textFormat,
        FLOAT layoutWidth,
        FLOAT layoutHeight,
        FLOAT pixelsPerDip,
        DWRITE_MATRIX const *transform,
        WINBOOL useGdiNatural,
        IDWriteTextLayout **textLayout) PURE;

    STDMETHOD(CreateEllipsisTrimmingSign)(THIS_
        IDWriteTextFormat *textFormat,
        IDWriteInlineObject **trimmingSign) PURE;

    STDMETHOD(CreateTextAnalyzer)(THIS_
        IDWriteTextAnalyzer **textAnalyzer) PURE;

    STDMETHOD(CreateNumberSubstitution)(THIS_
        DWRITE_NUMBER_SUBSTITUTION_METHOD substitutionMethod,
        WCHAR const *localeName,
        WINBOOL ignoreUserOverride,
        IDWriteNumberSubstitution **numberSubstitution) PURE;

    STDMETHOD(CreateGlyphRunAnalysis)(THIS_
        DWRITE_GLYPH_RUN const *glyphRun,
        FLOAT pixelsPerDip,
        DWRITE_MATRIX const *transform,
        DWRITE_RENDERING_MODE renderingMode,
        DWRITE_MEASURING_MODE measuringMode,
        FLOAT baselineOriginX,
        FLOAT baselineOriginY,
        IDWriteGlyphRunAnalysis **glyphRunAnalysis) PURE;
#endif

    /* IDWriteFactory1 methods */
    STDMETHOD(GetEudcFontCollection)(THIS_
        IDWriteFontCollection **fontCollection,
        BOOL checkForUpdates __MINGW_DEF_ARG_VAL(FALSE)) PURE;

    STDMETHOD(CreateCustomRenderingParams)(THIS_
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT enhancedContrastGrayscale,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        IDWriteRenderingParams1 **renderingParams) PURE;

#ifdef __cplusplus
    using IDWriteFactory::CreateCustomRenderingParams;
#endif

    END_INTERFACE
};

__CRT_UUID_DECL(IDWriteFactory1, 0x30572f99,0xdac6,0x41db,0xa1,0x6e,0x04,0x86,0x30,0x7e,0x60,0x6a)

#endif /* DWRITE_1_H_INCLUDED */
