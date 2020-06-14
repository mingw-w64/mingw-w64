/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef DWRITE_1_H_INCLUDED
#define DWRITE_1_H_INCLUDED

#include <dwrite.h>

#ifndef __IDWriteFont1_FWD_DEFINED__
#define __IDWriteFont1_FWD_DEFINED__
typedef struct IDWriteFont1 IDWriteFont1;
#endif

#ifndef __IDWriteFontFace1_FWD_DEFINED__
#define __IDWriteFontFace1_FWD_DEFINED__
typedef struct IDWriteFontFace1 IDWriteFontFace1;
#endif

#ifndef __IDWriteRenderingParams1_FWD_DEFINED__
#define __IDWriteRenderingParams1_FWD_DEFINED__
typedef struct IDWriteRenderingParams1 IDWriteRenderingParams1;
#endif

#ifndef __IDWriteTextAnalysisSource1_FWD_DEFINED__
#define __IDWriteTextAnalysisSource1_FWD_DEFINED__
typedef struct IDWriteTextAnalysisSource1 IDWriteTextAnalysisSource1;
#endif

#ifndef __IDWriteTextAnalysisSink1_FWD_DEFINED__
#define __IDWriteTextAnalysisSink1_FWD_DEFINED__
typedef struct IDWriteTextAnalysisSink1 IDWriteTextAnalysisSink1;
#endif

#ifndef __IDWriteTextAnalyzer1_FWD_DEFINED__
#define __IDWriteTextAnalyzer1_FWD_DEFINED__
typedef struct IDWriteTextAnalyzer1 IDWriteTextAnalyzer1;
#endif

#ifndef __IDWriteTextLayout1_FWD_DEFINED__
#define __IDWriteTextLayout1_FWD_DEFINED__
typedef struct IDWriteTextLayout1 IDWriteTextLayout1;
#endif

#ifndef __IDWriteFactory1_FWD_DEFINED__
#define __IDWriteFactory1_FWD_DEFINED__
typedef struct IDWriteFactory1 IDWriteFactory1;
#endif

#ifndef __IDWriteBitmapRenderTarget1_FWD_DEFINED__
#define __IDWriteBitmapRenderTarget1_FWD_DEFINED__
typedef struct IDWriteBitmapRenderTarget1 IDWriteBitmapRenderTarget1;
#endif

enum DWRITE_OUTLINE_THRESHOLD {
    DWRITE_OUTLINE_THRESHOLD_ANTIALIASED,
    DWRITE_OUTLINE_THRESHOLD_ALIASED
};

enum DWRITE_BASELINE
{
    DWRITE_BASELINE_DEFAULT,
    DWRITE_BASELINE_ROMAN,
    DWRITE_BASELINE_CENTRAL,
    DWRITE_BASELINE_MATH,
    DWRITE_BASELINE_HANGING,
    DWRITE_BASELINE_IDEOGRAPHIC_BOTTOM,
    DWRITE_BASELINE_IDEOGRAPHIC_TOP,
    DWRITE_BASELINE_MINIMUM,
    DWRITE_BASELINE_MAXIMUM,
};

enum DWRITE_GLYPH_ORIENTATION_ANGLE
{
    DWRITE_GLYPH_ORIENTATION_ANGLE_0_DEGREES,
    DWRITE_GLYPH_ORIENTATION_ANGLE_90_DEGREES,
    DWRITE_GLYPH_ORIENTATION_ANGLE_180_DEGREES,
    DWRITE_GLYPH_ORIENTATION_ANGLE_270_DEGREES,
};

enum DWRITE_TEXT_ANTIALIAS_MODE
{
    DWRITE_TEXT_ANTIALIAS_MODE_CLEARTYPE,
    DWRITE_TEXT_ANTIALIAS_MODE_GRAYSCALE
};

enum DWRITE_VERTICAL_GLYPH_ORIENTATION
{
    DWRITE_VERTICAL_GLYPH_ORIENTATION_DEFAULT,
    DWRITE_VERTICAL_GLYPH_ORIENTATION_STACKED
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

struct DWRITE_FONT_METRICS1
#ifdef __cplusplus
    : public DWRITE_FONT_METRICS
#endif
{
#ifndef __cplusplus
    UINT16 designUnitsPerEm;
    UINT16 ascent;
    UINT16 descent;
    INT16 lineGap;
    UINT16 capHeight;
    UINT16 xHeight;
    INT16 underlinePosition;
    UINT16 underlineThickness;
    INT16 strikethroughPosition;
    UINT16 strikethroughThickness;
#endif
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
    WINBOOL hasTypographicMetrics;
};

struct DWRITE_SCRIPT_PROPERTIES
{
    UINT32 isoScriptCode;
    UINT32 isoScriptNumber;
    UINT32 clusterLookahead;
    UINT32 justificationCharacter;
    UINT32 restrictCaretToClusters      : 1;
    UINT32 usesWordDividers             : 1;
    UINT32 isDiscreteWriting            : 1;
    UINT32 isBlockWriting               : 1;
    UINT32 isDistributedWithinCluster   : 1;
    UINT32 isConnectedWriting           : 1;
    UINT32 isCursiveWriting             : 1;
    UINT32 reserved                     : 25;
};

struct DWRITE_JUSTIFICATION_OPPORTUNITY
{
    FLOAT expansionMinimum;
    FLOAT expansionMaximum;
    FLOAT compressionMaximum;
    UINT32 expansionPriority         : 8;
    UINT32 compressionPriority       : 8;
    UINT32 allowResidualExpansion    : 1;
    UINT32 allowResidualCompression  : 1;
    UINT32 applyToLeadingEdge        : 1;
    UINT32 applyToTrailingEdge       : 1;
    UINT32 reserved                  : 12;
};

union DWRITE_PANOSE {
    UINT8 values[10];
    UINT8 familyKind;
    struct {
        UINT8 familyKind;
        UINT8 serifStyle;
        UINT8 weight;
        UINT8 proportion;
        UINT8 contrast;
        UINT8 strokeVariation;
        UINT8 armStyle;
        UINT8 letterform;
        UINT8 midline;
        UINT8 xHeight;
    } text;
    struct {
        UINT8 familyKind;
        UINT8 toolKind;
        UINT8 weight;
        UINT8 spacing;
        UINT8 aspectRatio;
        UINT8 contrast;
        UINT8 scriptTopology;
        UINT8 scriptForm;
        UINT8 finials;
        UINT8 xAscent;
    } script;
    struct {
        UINT8 familyKind;
        UINT8 decorativeClass;
        UINT8 weight;
        UINT8 aspect;
        UINT8 contrast;
        UINT8 serifVariant;
        UINT8 fill;
        UINT8 lining;
        UINT8 decorativeTopology;
        UINT8 characterRange;
    } decorative;
    struct {
        UINT8 familyKind;
        UINT8 symbolKind;
        UINT8 weight;
        UINT8 spacing;
        UINT8 aspectRatioAndContrast;
        UINT8 aspectRatio94;
        UINT8 aspectRatio119;
        UINT8 aspectRatio157;
        UINT8 aspectRatio163;
        UINT8 aspectRatio211;
    } symbol;
};

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteFont1
DECLARE_INTERFACE_(IDWriteFont1,IDWriteFont)
{
    BEGIN_INTERFACE

    STDMETHOD_(void, GetMetrics)(DWRITE_FONT_METRICS1 *fontMetrics) PURE;

    STDMETHOD_(void, GetPanose)(DWRITE_PANOSE *panose) PURE;

    STDMETHOD(GetUnicodeRanges)(UINT32 maxCount,
        DWRITE_UNICODE_RANGE *ranges,
        UINT32 *actualCount) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteFont1Vtbl
{
    IDWriteFontVtbl Base;

    STDMETHOD_(void, GetMetrics)(IDWriteFont1 *This,
        struct DWRITE_FONT_METRICS1 *fontMetrics) PURE;

    STDMETHOD_(void, GetPanose)(IDWriteFont1 *This,
        union DWRITE_PANOSE *panose) PURE;

    STDMETHOD(GetUnicodeRanges)(IDWriteFont1 *This,
        UINT32 maxCount,
        struct DWRITE_UNICODE_RANGE *ranges,
        UINT32 *actualCount) PURE;
}
IDWriteFont1Vtbl;

interface IDWriteFont1
{
    const IDWriteFont1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteFont1, 0xacd16696,0x8c14,0x4f5d,0x87,0x7e,0xfe,0x3f,0xc1,0xd3,0x27,0x38);

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteFontFace1
DECLARE_INTERFACE_(IDWriteFontFace1, IDWriteFontFace)
{
    BEGIN_INTERFACE

    STDMETHOD_(void, GetMetrics)(DWRITE_FONT_METRICS1*) PURE;
    STDMETHOD(GetGdiCompatibleMetrics)(FLOAT,FLOAT,DWRITE_MATRIX const*,DWRITE_FONT_METRICS1*) PURE;
    STDMETHOD_(void, GetCaretMetrics)(DWRITE_CARET_METRICS*) PURE;
    STDMETHOD(GetUnicodeRanges)(UINT32, DWRITE_UNICODE_RANGE*,UINT32*) PURE;
    STDMETHOD_(BOOL, IsMonospacedFont)(void) PURE;
    STDMETHOD(GetDesignGlyphAdvances)(UINT32,UINT16 const*,INT32*,BOOL isSideways __MINGW_DEF_ARG_VAL(FALSE)) PURE;
    STDMETHOD(GetGdiCompatibleGlyphAdvances)(FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,BOOL,UINT32,
            UINT16 const*,INT32*) PURE;
    STDMETHOD(GetKerningPairAdjustments)(UINT32,UINT16 const*,INT32*) PURE;
    STDMETHOD_(BOOL, HasKerningPairs)(void);
    STDMETHOD(GetRecommendedRenderingMode)(FLOAT,FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,
            DWRITE_OUTLINE_THRESHOLD,DWRITE_MEASURING_MODE,DWRITE_RENDERING_MODE*) PURE;
    STDMETHOD(GetVerticalGlyphVariants)(UINT32,UINT16 const*,UINT16*);
    STDMETHOD_(BOOL, HasVerticalGlyphVariants)(void);

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteFontFace1Vtbl
{
    IDWriteFontFaceVtbl Base;

    STDMETHOD_(void, GetMetrics)(IDWriteFontFace1 *This, struct DWRITE_FONT_METRICS1*) PURE;
    STDMETHOD(GetGdiCompatibleMetrics)(IDWriteFontFace1 *This, FLOAT,FLOAT,DWRITE_MATRIX const*,struct DWRITE_FONT_METRICS1*) PURE;
    STDMETHOD_(void, GetCaretMetrics)(IDWriteFontFace1 *This, struct DWRITE_CARET_METRICS*) PURE;
    STDMETHOD(GetUnicodeRanges)(IDWriteFontFace1 *This, UINT32, struct DWRITE_UNICODE_RANGE*,UINT32*) PURE;
    STDMETHOD_(BOOL, IsMonospacedFont)(IDWriteFontFace1 *This) PURE;
    STDMETHOD(GetDesignGlyphAdvances)(IDWriteFontFace1 *This, UINT32,UINT16 const*,INT32*,BOOL isSideways) PURE;
    STDMETHOD(GetGdiCompatibleGlyphAdvances)(IDWriteFontFace1 *This, FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,BOOL,UINT32,
            UINT16 const*,INT32*) PURE;
    STDMETHOD(GetKerningPairAdjustments)(IDWriteFontFace1 *This, UINT32,UINT16 const*,INT32*) PURE;
    STDMETHOD_(BOOL, HasKerningPairs)(IDWriteFontFace1 *This);
    STDMETHOD(GetRecommendedRenderingMode)(IDWriteFontFace1 *This, FLOAT,FLOAT,FLOAT,DWRITE_MATRIX const*,BOOL,
            enum DWRITE_OUTLINE_THRESHOLD,DWRITE_MEASURING_MODE,DWRITE_RENDERING_MODE*) PURE;
    STDMETHOD(GetVerticalGlyphVariants)(IDWriteFontFace1 *This, UINT32,UINT16 const*,UINT16*);
    STDMETHOD_(BOOL, HasVerticalGlyphVariants)(IDWriteFontFace1 *This);
}
IDWriteFontFace1Vtbl;

interface IDWriteFontFace1
{
    const IDWriteFontFace1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteFontFace1, 0xa71efdb4,0x9fdb,0x4838,0xad,0x90,0xcf,0xc3,0xbe,0x8c,0x3d,0xaf);

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteRenderingParams1
DECLARE_INTERFACE_(IDWriteRenderingParams1,IDWriteRenderingParams)
{
    BEGIN_INTERFACE

    STDMETHOD_(FLOAT, GetGrayscaleEnhancedContrast)(void) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteRenderingParams1Vtbl
{
    IDWriteRenderingParamsVtbl Base;

    STDMETHOD_(FLOAT, GetGrayscaleEnhancedContrast)(IDWriteRenderingParams1 *This) PURE;
}
IDWriteRenderingParams1Vtbl;

interface IDWriteRenderingParams1
{
    const IDWriteRenderingParams1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteRenderingParams1, 0x94413cf4,0xa6fc,0x4248,0x8b,0x50,0x66,0x74,0x34,0x8f,0xca,0xd3)

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteTextAnalysisSource1
DECLARE_INTERFACE_(IDWriteTextAnalysisSource1,IDWriteTextAnalysisSource)
{
    BEGIN_INTERFACE

    STDMETHOD(GetVerticalGlyphOrientation)(
        UINT32 textPosition,
        UINT32 *textLength,
        DWRITE_VERTICAL_GLYPH_ORIENTATION *orientation,
        UINT8 *bidiLevel) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteTextAnalysisSource1Vtbl
{
    IDWriteTextAnalysisSourceVtbl Base;

    STDMETHOD(GetVerticalGlyphOrientation)(IDWriteTextAnalysisSource1 *This,
        UINT32 textPosition,
        UINT32 *textLength,
        enum DWRITE_VERTICAL_GLYPH_ORIENTATION *orientation,
        UINT8 *bidiLevel) PURE;
}
IDWriteTextAnalysisSource1Vtbl;

interface IDWriteTextAnalysisSource1
{
    const IDWriteTextAnalysisSource1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteTextAnalysisSource1, 0x639cfad8,0x0fb4,0x4b21,0xa5,0x8a,0x06,0x79,0x20,0x12,0x00,0x09);

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteTextAnalysisSink1
DECLARE_INTERFACE_(IDWriteTextAnalysisSink1,IDWriteTextAnalysisSink)
{
    BEGIN_INTERFACE

    STDMETHOD(SetGlyphOrientation)(
            UINT32 textPosition,
            UINT32 textLength,
            DWRITE_GLYPH_ORIENTATION_ANGLE angle,
            UINT8 adjustedBidilevel,
            WINBOOL isSideways,
            WINBOOL isRtl) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteTextAnalysisSink1Vtbl
{
    IDWriteTextAnalysisSinkVtbl Base;

    STDMETHOD(SetGlyphOrientation)(IDWriteTextAnalysisSink1 *This,
            UINT32 textPosition,
            UINT32 textLength,
            enum DWRITE_GLYPH_ORIENTATION_ANGLE angle,
            UINT8 adjustedBidilevel,
            WINBOOL isSideways,
            WINBOOL isRtl) PURE;
}
IDWriteTextAnalysisSink1Vtbl;

interface IDWriteTextAnalysisSink1
{
    const IDWriteTextAnalysisSink1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteTextAnalysisSink1, 0xb0d941a0,0x85e7,0x4d8b,0x9f,0xd3,0x5c,0xed,0x99,0x34,0x48,0x2a);

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteTextAnalyzer1
DECLARE_INTERFACE_(IDWriteTextAnalyzer1,IDWriteTextAnalyzer)
{
    BEGIN_INTERFACE

    STDMETHOD(ApplyCharacterSpacing)(
        FLOAT leadingSpacing,
        FLOAT trailingSpacing,
        FLOAT minimumAdvanceWidth,
        UINT32 textLength,
        UINT32 glyphCount,
        UINT16 const* clusterMap,
        FLOAT const* glyphAdvances,
        DWRITE_GLYPH_OFFSET const* glyphOffsets,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        FLOAT* modifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* modifiedGlyphOffsets) PURE;

    STDMETHOD(GetBaseline)(
        IDWriteFontFace* fontFace,
        DWRITE_BASELINE baseline,
        BOOL isVertical,
        BOOL isSimulationAllowed,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        WCHAR const* localeName,
        INT32* baselineCoordinate,
        BOOL* exists
        ) PURE;

    STDMETHOD(AnalyzeVerticalGlyphOrientation)(
        IDWriteTextAnalysisSource1* analysisSource,
        UINT32 textPosition,
        UINT32 textLength,
        IDWriteTextAnalysisSink1* analysisSink
        ) PURE;

    STDMETHOD(GetGlyphOrientationTransform)(
        DWRITE_GLYPH_ORIENTATION_ANGLE glyphOrientationAngle,
        BOOL isSideways,
        DWRITE_MATRIX* transform
        ) PURE;

    STDMETHOD(GetScriptProperties)(
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        DWRITE_SCRIPT_PROPERTIES* scriptProperties
        ) PURE;

    STDMETHOD(GetTextComplexity)(
        WCHAR const* textString,
        UINT32 textLength,
        IDWriteFontFace* fontFace,
        BOOL* isTextSimple,
        UINT32* textLengthRead,
        UINT16* glyphIndices
        ) PURE;

    STDMETHOD(GetJustificationOpportunities)(
        IDWriteFontFace* fontFace,
        FLOAT fontEmSize,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        UINT32 textLength,
        UINT32 glyphCount,
        WCHAR const* textString,
        UINT16 const* clusterMap,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        DWRITE_JUSTIFICATION_OPPORTUNITY* justificationOpportunities
        ) PURE;

    STDMETHOD(JustifyGlyphAdvances)(
        FLOAT lineWidth,
        UINT32 glyphCount,
        DWRITE_JUSTIFICATION_OPPORTUNITY const* justificationOpportunities,
        FLOAT const* glyphAdvances,
        DWRITE_GLYPH_OFFSET const* glyphOffsets,
        FLOAT* justifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* justifiedGlyphOffsets
        ) PURE;

    STDMETHOD(GetJustifiedGlyphs)(
        IDWriteFontFace* fontFace,
        FLOAT fontEmSize,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        UINT32 textLength,
        UINT32 glyphCount,
        UINT32 maxGlyphCount,
        UINT16 const* clusterMap,
        UINT16 const* glyphIndices,
        FLOAT const* glyphAdvances,
        FLOAT const* justifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET const* justifiedGlyphOffsets,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        UINT32* actualGlyphCount,
        UINT16* modifiedClusterMap,
        UINT16* modifiedGlyphIndices,
        FLOAT* modifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* modifiedGlyphOffsets
        ) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteTextAnalyzer1Vtbl
{
    IDWriteTextAnalyzerVtbl Base;

    STDMETHOD(ApplyCharacterSpacing)(IDWriteTextAnalyzer1 *This,
        FLOAT leadingSpacing,
        FLOAT trailingSpacing,
        FLOAT minimumAdvanceWidth,
        UINT32 textLength,
        UINT32 glyphCount,
        UINT16 const* clusterMap,
        FLOAT const* glyphAdvances,
        DWRITE_GLYPH_OFFSET const* glyphOffsets,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        FLOAT* modifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* modifiedGlyphOffsets) PURE;

    STDMETHOD(GetBaseline)(IDWriteTextAnalyzer1 *This,
        IDWriteFontFace* fontFace,
        enum DWRITE_BASELINE baseline,
        BOOL isVertical,
        BOOL isSimulationAllowed,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        WCHAR const* localeName,
        INT32* baselineCoordinate,
        BOOL* exists
        ) PURE;

    STDMETHOD(AnalyzeVerticalGlyphOrientation)(IDWriteTextAnalyzer1 *This,
        IDWriteTextAnalysisSource1* analysisSource,
        UINT32 textPosition,
        UINT32 textLength,
        IDWriteTextAnalysisSink1* analysisSink
        ) PURE;

    STDMETHOD(GetGlyphOrientationTransform)(IDWriteTextAnalyzer1 *This,
        enum DWRITE_GLYPH_ORIENTATION_ANGLE glyphOrientationAngle,
        BOOL isSideways,
        DWRITE_MATRIX* transform
        ) PURE;

    STDMETHOD(GetScriptProperties)(IDWriteTextAnalyzer1 *This,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        struct DWRITE_SCRIPT_PROPERTIES* scriptProperties
        ) PURE;

    STDMETHOD(GetTextComplexity)(IDWriteTextAnalyzer1 *This,
        WCHAR const* textString,
        UINT32 textLength,
        IDWriteFontFace* fontFace,
        BOOL* isTextSimple,
        UINT32* textLengthRead,
        UINT16* glyphIndices
        ) PURE;

    STDMETHOD(GetJustificationOpportunities)(IDWriteTextAnalyzer1 *This,
        IDWriteFontFace* fontFace,
        FLOAT fontEmSize,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        UINT32 textLength,
        UINT32 glyphCount,
        WCHAR const* textString,
        UINT16 const* clusterMap,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        struct DWRITE_JUSTIFICATION_OPPORTUNITY* justificationOpportunities
        ) PURE;

    STDMETHOD(JustifyGlyphAdvances)(IDWriteTextAnalyzer1 *This,
        FLOAT lineWidth,
        UINT32 glyphCount,
        struct DWRITE_JUSTIFICATION_OPPORTUNITY const* justificationOpportunities,
        FLOAT const* glyphAdvances,
        DWRITE_GLYPH_OFFSET const* glyphOffsets,
        FLOAT* justifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* justifiedGlyphOffsets
        ) PURE;

    STDMETHOD(GetJustifiedGlyphs)(IDWriteTextAnalyzer1 *This,
        IDWriteFontFace* fontFace,
        FLOAT fontEmSize,
        DWRITE_SCRIPT_ANALYSIS scriptAnalysis,
        UINT32 textLength,
        UINT32 glyphCount,
        UINT32 maxGlyphCount,
        UINT16 const* clusterMap,
        UINT16 const* glyphIndices,
        FLOAT const* glyphAdvances,
        FLOAT const* justifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET const* justifiedGlyphOffsets,
        DWRITE_SHAPING_GLYPH_PROPERTIES const* glyphProperties,
        UINT32* actualGlyphCount,
        UINT16* modifiedClusterMap,
        UINT16* modifiedGlyphIndices,
        FLOAT* modifiedGlyphAdvances,
        DWRITE_GLYPH_OFFSET* modifiedGlyphOffsets
        ) PURE;
}
IDWriteTextAnalyzer1Vtbl;

interface IDWriteTextAnalyzer1
{
    const IDWriteTextAnalyzer1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteTextAnalyzer1, 0x80dad800,0xe21f,0x4e83,0x4e,0xce,0xbf,0xcc,0xe5,0x00,0xdb,0x7c);

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteTextLayout1
DECLARE_INTERFACE_(IDWriteTextLayout1,IDWriteTextLayout)
{
    BEGIN_INTERFACE

    STDMETHOD(SetPairKerning)(WINBOOL isPairKerningEnabled,
            DWRITE_TEXT_RANGE textRange) PURE;
    STDMETHOD(GetPairKerning)(UINT32 position,
            WINBOOL *isPairKerningEnabled,
            DWRITE_TEXT_RANGE *textRange __MINGW_DEF_ARG_VAL(NULL)) PURE;
    STDMETHOD(SetCharacterSpacing)(FLOAT leadingSpacing,
            FLOAT trailingSpacing,
            FLOAT minimumAdvance,
            DWRITE_TEXT_RANGE textRange) PURE;
    STDMETHOD(GetCharacterSpacing)(FLOAT *leadingSpacing,
            FLOAT *trailingSpacing,
            FLOAT *minimumAdvance,
            DWRITE_TEXT_RANGE *textRange __MINGW_DEF_ARG_VAL(NULL)) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteTextLayout1Vtbl
{
    IDWriteTextLayoutVtbl Base;

    STDMETHOD(SetPairKerning)(IDWriteTextLayout1 *This,
            WINBOOL isPairKerningEnabled,
            DWRITE_TEXT_RANGE textRange) PURE;
    STDMETHOD(GetPairKerning)(IDWriteTextLayout1 *This,
            UINT32 position,
            WINBOOL *isPairKerningEnabled,
            DWRITE_TEXT_RANGE *textRange) PURE;
    STDMETHOD(SetCharacterSpacing)(IDWriteTextLayout1 *This,
            FLOAT leadingSpacing,
            FLOAT trailingSpacing,
            FLOAT minimumAdvance,
            DWRITE_TEXT_RANGE textRange) PURE;
    STDMETHOD(GetCharacterSpacing)(IDWriteTextLayout1 *This,
            FLOAT *leadingSpacing,
            FLOAT *trailingSpacing,
            FLOAT *minimumAdvance,
            DWRITE_TEXT_RANGE *textRange) PURE;
}
IDWriteTextLayout1Vtbl;

interface IDWriteTextLayout1
{
    const IDWriteTextLayout1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteTextLayout1, 0x9064d822,0x80a7,0x465c,0xa9,0x86,0xdf,0x65,0xf7,0x8b,0x8f,0xeb)

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteFactory1
DECLARE_INTERFACE_(IDWriteFactory1,IDWriteFactory)
{
    BEGIN_INTERFACE

    STDMETHOD(GetEudcFontCollection)(IDWriteFontCollection **fontCollection,
        BOOL checkForUpdates __MINGW_DEF_ARG_VAL(FALSE)) PURE;

    STDMETHOD(CreateCustomRenderingParams)(FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT enhancedContrastGrayscale,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        IDWriteRenderingParams1 **renderingParams) PURE;

    using IDWriteFactory::CreateCustomRenderingParams;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteFactory1Vtbl
{
    IDWriteFactoryVtbl Base;

    STDMETHOD(GetEudcFontCollection)(IDWriteFactory1 *This,
        IDWriteFontCollection **fontCollection,
        BOOL checkForUpdates) PURE;

    STDMETHOD(CreateCustomRenderingParams)(IDWriteFactory1 *This,
        FLOAT gamma,
        FLOAT enhancedContrast,
        FLOAT enhancedContrastGrayscale,
        FLOAT clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY pixelGeometry,
        DWRITE_RENDERING_MODE renderingMode,
        IDWriteRenderingParams1 **renderingParams) PURE;
}
IDWriteFactory1Vtbl;

interface IDWriteFactory1
{
    const IDWriteFactory1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

DEFINE_GUID(IID_IDWriteFactory1, 0x30572f99,0xdac6,0x41db,0xa1,0x6e,0x04,0x86,0x30,0x7e,0x60,0x6a);
__CRT_UUID_DECL(IDWriteFactory1, 0x30572f99,0xdac6,0x41db,0xa1,0x6e,0x04,0x86,0x30,0x7e,0x60,0x6a)

#ifndef D2D_USE_C_DEFINITIONS

#undef  INTERFACE
#define INTERFACE IDWriteBitmapRenderTarget1
DECLARE_INTERFACE_(IDWriteBitmapRenderTarget1,IDWriteBitmapRenderTarget)
{
    BEGIN_INTERFACE

    STDMETHOD_(DWRITE_TEXT_ANTIALIAS_MODE, GetTextAntialiasMode)(void) PURE;

    STDMETHOD(SetTextAntialiasMode)(
        DWRITE_TEXT_ANTIALIAS_MODE antialiasMode) PURE;

    END_INTERFACE
};

#else  /* D2D_USE_C_DEFINITIONS */

typedef struct IDWriteBitmapRenderTarget1Vtbl
{
    IDWriteBitmapRenderTargetVtbl Base;

    STDMETHOD_(enum DWRITE_TEXT_ANTIALIAS_MODE, GetTextAntialiasMode)(IDWriteBitmapRenderTarget1 *This) PURE;

    STDMETHOD(SetTextAntialiasMode)(IDWriteBitmapRenderTarget1 *This,
        enum DWRITE_TEXT_ANTIALIAS_MODE antialiasMode) PURE;
}
IDWriteBitmapRenderTarget1Vtbl;

interface IDWriteBitmapRenderTarget1
{
    const IDWriteBitmapRenderTarget1Vtbl *lpVtbl;
};

#endif  /* D2D_USE_C_DEFINITIONS */

__CRT_UUID_DECL(IDWriteBitmapRenderTarget1, 0x791e8298,0x3ef3,0x4230,0x98,0x80,0xc9,0xbd,0xec,0xc4,0x20,0x64)

#endif /* DWRITE_1_H_INCLUDED */
