/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSENUMS_H
#define _GDIPLUSENUMS_H

const float FlatnessDefault = 1.0f/4.0f;

typedef UINT GraphicsState;
typedef UINT GraphicsContainer;

enum FillMode {
  FillModeAlternate,FillModeWinding
};

enum QualityMode {
  QualityModeInvalid = -1,QualityModeDefault = 0,QualityModeLow = 1,QualityModeHigh = 2
};

enum CompositingMode {
  CompositingModeSourceOver,CompositingModeSourceCopy
};

enum CompositingQuality {
  CompositingQualityInvalid = QualityModeInvalid,CompositingQualityDefault = QualityModeDefault,CompositingQualityHighSpeed = QualityModeLow,
  CompositingQualityHighQuality = QualityModeHigh,CompositingQualityGammaCorrected,CompositingQualityAssumeLinear
};

enum Unit {
  UnitWorld,UnitDisplay,UnitPixel,UnitPoint,UnitInch,UnitDocument,UnitMillimeter
};

enum MetafileFrameUnit {
  MetafileFrameUnitPixel = UnitPixel,MetafileFrameUnitPoint = UnitPoint,MetafileFrameUnitInch = UnitInch,MetafileFrameUnitDocument = UnitDocument,
  MetafileFrameUnitMillimeter = UnitMillimeter,MetafileFrameUnitGdi
};

enum CoordinateSpace {
  CoordinateSpaceWorld,CoordinateSpacePage,CoordinateSpaceDevice
};

enum WrapMode {
  WrapModeTile,WrapModeTileFlipX,WrapModeTileFlipY,WrapModeTileFlipXY,WrapModeClamp
};

enum HatchStyle {
  HatchStyleHorizontal,HatchStyleVertical,HatchStyleForwardDiagonal,HatchStyleBackwardDiagonal,HatchStyleCross,HatchStyleDiagonalCross,
  HatchStyle05Percent,HatchStyle10Percent,HatchStyle20Percent,HatchStyle25Percent,HatchStyle30Percent,HatchStyle40Percent,HatchStyle50Percent,
  HatchStyle60Percent,HatchStyle70Percent,HatchStyle75Percent,HatchStyle80Percent,HatchStyle90Percent,HatchStyleLightDownwardDiagonal,
  HatchStyleLightUpwardDiagonal,HatchStyleDarkDownwardDiagonal,HatchStyleDarkUpwardDiagonal,HatchStyleWideDownwardDiagonal,
  HatchStyleWideUpwardDiagonal,HatchStyleLightVertical,HatchStyleLightHorizontal,HatchStyleNarrowVertical,HatchStyleNarrowHorizontal,
  HatchStyleDarkVertical,HatchStyleDarkHorizontal,HatchStyleDashedDownwardDiagonal,HatchStyleDashedUpwardDiagonal,HatchStyleDashedHorizontal,
  HatchStyleDashedVertical,HatchStyleSmallConfetti,HatchStyleLargeConfetti,HatchStyleZigZag,HatchStyleWave,HatchStyleDiagonalBrick,
  HatchStyleHorizontalBrick,HatchStyleWeave,HatchStylePlaid,HatchStyleDivot,HatchStyleDottedGrid,HatchStyleDottedDiamond,HatchStyleShingle,
  HatchStyleTrellis,HatchStyleSphere,HatchStyleSmallGrid,HatchStyleSmallCheckerBoard,HatchStyleLargeCheckerBoard,HatchStyleOutlinedDiamond,
  HatchStyleSolidDiamond,HatchStyleTotal,HatchStyleLargeGrid = HatchStyleCross,HatchStyleMin = HatchStyleHorizontal,
  HatchStyleMax = HatchStyleTotal - 1
};

enum DashStyle {
  DashStyleSolid,DashStyleDash,DashStyleDot,DashStyleDashDot,DashStyleDashDotDot,DashStyleCustom
};

enum DashCap {
  DashCapFlat = 0,DashCapRound = 2,DashCapTriangle = 3
};

enum LineCap {
  LineCapFlat = 0,LineCapSquare = 1,LineCapRound = 2,LineCapTriangle = 3,LineCapNoAnchor = 0x10,LineCapSquareAnchor = 0x11,LineCapRoundAnchor = 0x12,
  LineCapDiamondAnchor = 0x13,LineCapArrowAnchor = 0x14,LineCapCustom = 0xff,LineCapAnchorMask = 0xf0
};

enum CustomLineCapType {
  CustomLineCapTypeDefault = 0,CustomLineCapTypeAdjustableArrow = 1
};

enum LineJoin {
  LineJoinMiter = 0,LineJoinBevel = 1,LineJoinRound = 2,LineJoinMiterClipped = 3
};

enum PathPointType {
  PathPointTypeStart = 0,PathPointTypeLine = 1,PathPointTypeBezier = 3,PathPointTypePathTypeMask = 0x07,PathPointTypeDashMode = 0x10,
  PathPointTypePathMarker = 0x20,PathPointTypeCloseSubpath = 0x80,PathPointTypeBezier3 = 3
};

enum WarpMode {
  WarpModePerspective,WarpModeBilinear
};

enum LinearGradientMode {
  LinearGradientModeHorizontal,LinearGradientModeVertical,LinearGradientModeForwardDiagonal,LinearGradientModeBackwardDiagonal
};

enum CombineMode {
  CombineModeReplace,CombineModeIntersect,CombineModeUnion,CombineModeXor,CombineModeExclude,CombineModeComplement
};

enum ImageType {
  ImageTypeUnknown,ImageTypeBitmap,ImageTypeMetafile
};

enum InterpolationMode {
  InterpolationModeInvalid = QualityModeInvalid,InterpolationModeDefault = QualityModeDefault,InterpolationModeLowQuality = QualityModeLow,
  InterpolationModeHighQuality = QualityModeHigh,InterpolationModeBilinear,InterpolationModeBicubic,InterpolationModeNearestNeighbor,
  InterpolationModeHighQualityBilinear,InterpolationModeHighQualityBicubic
};

enum PenAlignment {
  PenAlignmentCenter = 0,PenAlignmentInset = 1
};

enum BrushType {
  BrushTypeSolidColor = 0,BrushTypeHatchFill = 1,BrushTypeTextureFill = 2,BrushTypePathGradient = 3,BrushTypeLinearGradient = 4
};

enum PenType {
  PenTypeSolidColor = BrushTypeSolidColor,PenTypeHatchFill = BrushTypeHatchFill,PenTypeTextureFill = BrushTypeTextureFill,
  PenTypePathGradient = BrushTypePathGradient,PenTypeLinearGradient = BrushTypeLinearGradient,PenTypeUnknown = -1
};

enum MatrixOrder {
  MatrixOrderPrepend = 0,MatrixOrderAppend = 1
};

enum GenericFontFamily {
  GenericFontFamilySerif,GenericFontFamilySansSerif,GenericFontFamilyMonospace
};

enum FontStyle {
  FontStyleRegular = 0,FontStyleBold = 1,FontStyleItalic = 2,FontStyleBoldItalic = 3,FontStyleUnderline = 4,FontStyleStrikeout = 8
};

enum SmoothingMode {
  SmoothingModeInvalid = QualityModeInvalid,SmoothingModeDefault = QualityModeDefault,SmoothingModeHighSpeed = QualityModeLow,SmoothingModeHighQuality = QualityModeHigh,SmoothingModeNone,SmoothingModeAntiAlias
};

enum PixelOffsetMode {
  PixelOffsetModeInvalid = QualityModeInvalid,PixelOffsetModeDefault = QualityModeDefault,PixelOffsetModeHighSpeed = QualityModeLow,
  PixelOffsetModeHighQuality = QualityModeHigh,PixelOffsetModeNone,PixelOffsetModeHalf
};

enum TextRenderingHint {
  TextRenderingHintSystemDefault = 0,TextRenderingHintSingleBitPerPixelGridFit,TextRenderingHintSingleBitPerPixel,
  TextRenderingHintAntiAliasGridFit,TextRenderingHintAntiAlias,TextRenderingHintClearTypeGridFit
};

enum MetafileType {
  MetafileTypeInvalid,MetafileTypeWmf,MetafileTypeWmfPlaceable,MetafileTypeEmf,MetafileTypeEmfPlusOnly,MetafileTypeEmfPlusDual
};

enum EmfType {
  EmfTypeEmfOnly = MetafileTypeEmf,EmfTypeEmfPlusOnly = MetafileTypeEmfPlusOnly,EmfTypeEmfPlusDual = MetafileTypeEmfPlusDual
};

enum ObjectType {
  ObjectTypeInvalid,ObjectTypeBrush,ObjectTypePen,ObjectTypePath,ObjectTypeRegion,ObjectTypeImage,ObjectTypeFont,ObjectTypeStringFormat,
  ObjectTypeImageAttributes,ObjectTypeCustomLineCap,ObjectTypeMax = ObjectTypeCustomLineCap,ObjectTypeMin = ObjectTypeBrush
};

inline WINBOOL ObjectTypeIsValid(ObjectType type) { return ((type >= ObjectTypeMin) && (type <= ObjectTypeMax)); }

enum EmfPlusRecordType;

#define GDIP_EMFPLUS_RECORD_BASE 0x00004000
#define GDIP_WMF_RECORD_BASE 0x00010000
#define GDIP_WMF_RECORD_TO_EMFPLUS(n) ((EmfPlusRecordType)((n) | GDIP_WMF_RECORD_BASE))
#define GDIP_EMFPLUS_RECORD_TO_WMF(n) ((n) & (~GDIP_WMF_RECORD_BASE))
#define GDIP_IS_WMF_RECORDTYPE(n) (((n) & GDIP_WMF_RECORD_BASE)!=0)

enum EmfPlusRecordType {
  WmfRecordTypeSetBkColor = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKCOLOR),WmfRecordTypeSetBkMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETBKMODE),
  WmfRecordTypeSetMapMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPMODE),WmfRecordTypeSetROP2 = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETROP2),
  WmfRecordTypeSetRelAbs = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETRELABS),WmfRecordTypeSetPolyFillMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPOLYFILLMODE),
  WmfRecordTypeSetStretchBltMode = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETSTRETCHBLTMODE),
  WmfRecordTypeSetTextCharExtra = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCHAREXTRA),
  WmfRecordTypeSetTextColor = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTCOLOR),
  WmfRecordTypeSetTextJustification = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTJUSTIFICATION),
  WmfRecordTypeSetWindowOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWORG),WmfRecordTypeSetWindowExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETWINDOWEXT),
  WmfRecordTypeSetViewportOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTORG),
  WmfRecordTypeSetViewportExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETVIEWPORTEXT),
  WmfRecordTypeOffsetWindowOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETWINDOWORG),
  WmfRecordTypeScaleWindowExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEWINDOWEXT),
  WmfRecordTypeOffsetViewportOrg = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETVIEWPORTORG),
  WmfRecordTypeScaleViewportExt = GDIP_WMF_RECORD_TO_EMFPLUS(META_SCALEVIEWPORTEXT),
  WmfRecordTypeLineTo = GDIP_WMF_RECORD_TO_EMFPLUS(META_LINETO),WmfRecordTypeMoveTo = GDIP_WMF_RECORD_TO_EMFPLUS(META_MOVETO),
  WmfRecordTypeExcludeClipRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXCLUDECLIPRECT),
  WmfRecordTypeIntersectClipRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_INTERSECTCLIPRECT),
  WmfRecordTypeArc = GDIP_WMF_RECORD_TO_EMFPLUS(META_ARC),WmfRecordTypeEllipse = GDIP_WMF_RECORD_TO_EMFPLUS(META_ELLIPSE),
  WmfRecordTypeFloodFill = GDIP_WMF_RECORD_TO_EMFPLUS(META_FLOODFILL),WmfRecordTypePie = GDIP_WMF_RECORD_TO_EMFPLUS(META_PIE),
  WmfRecordTypeRectangle = GDIP_WMF_RECORD_TO_EMFPLUS(META_RECTANGLE),WmfRecordTypeRoundRect = GDIP_WMF_RECORD_TO_EMFPLUS(META_ROUNDRECT),
  WmfRecordTypePatBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_PATBLT),WmfRecordTypeSaveDC = GDIP_WMF_RECORD_TO_EMFPLUS(META_SAVEDC),
  WmfRecordTypeSetPixel = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPIXEL),WmfRecordTypeOffsetClipRgn = GDIP_WMF_RECORD_TO_EMFPLUS(META_OFFSETCLIPRGN),
  WmfRecordTypeTextOut = GDIP_WMF_RECORD_TO_EMFPLUS(META_TEXTOUT),WmfRecordTypeBitBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_BITBLT),
  WmfRecordTypeStretchBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHBLT),
  WmfRecordTypePolygon = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYGON),WmfRecordTypePolyline = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYLINE),
  WmfRecordTypeEscape = GDIP_WMF_RECORD_TO_EMFPLUS(META_ESCAPE),WmfRecordTypeRestoreDC = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESTOREDC),
  WmfRecordTypeFillRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_FILLREGION),WmfRecordTypeFrameRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_FRAMEREGION),
  WmfRecordTypeInvertRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_INVERTREGION),WmfRecordTypePaintRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_PAINTREGION),
  WmfRecordTypeSelectClipRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTCLIPREGION),
  WmfRecordTypeSelectObject = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTOBJECT),
  WmfRecordTypeSetTextAlign = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETTEXTALIGN),
  WmfRecordTypeDrawText = GDIP_WMF_RECORD_TO_EMFPLUS(0x062F),WmfRecordTypeChord = GDIP_WMF_RECORD_TO_EMFPLUS(META_CHORD),
  WmfRecordTypeSetMapperFlags = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETMAPPERFLAGS),WmfRecordTypeExtTextOut = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTTEXTOUT),
  WmfRecordTypeSetDIBToDev = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETDIBTODEV),WmfRecordTypeSelectPalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_SELECTPALETTE),
  WmfRecordTypeRealizePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_REALIZEPALETTE),
  WmfRecordTypeAnimatePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_ANIMATEPALETTE),
  WmfRecordTypeSetPalEntries = GDIP_WMF_RECORD_TO_EMFPLUS(META_SETPALENTRIES),WmfRecordTypePolyPolygon = GDIP_WMF_RECORD_TO_EMFPLUS(META_POLYPOLYGON),
  WmfRecordTypeResizePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_RESIZEPALETTE),WmfRecordTypeDIBBitBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBBITBLT),
  WmfRecordTypeDIBStretchBlt = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBSTRETCHBLT),
  WmfRecordTypeDIBCreatePatternBrush = GDIP_WMF_RECORD_TO_EMFPLUS(META_DIBCREATEPATTERNBRUSH),
  WmfRecordTypeStretchDIB = GDIP_WMF_RECORD_TO_EMFPLUS(META_STRETCHDIB),WmfRecordTypeExtFloodFill = GDIP_WMF_RECORD_TO_EMFPLUS(META_EXTFLOODFILL),
  WmfRecordTypeSetLayout = GDIP_WMF_RECORD_TO_EMFPLUS(0x0149),WmfRecordTypeResetDC = GDIP_WMF_RECORD_TO_EMFPLUS(0x014C),
  WmfRecordTypeStartDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x014D),WmfRecordTypeStartPage = GDIP_WMF_RECORD_TO_EMFPLUS(0x004F),
  WmfRecordTypeEndPage = GDIP_WMF_RECORD_TO_EMFPLUS(0x0050),WmfRecordTypeAbortDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x0052),
  WmfRecordTypeEndDoc = GDIP_WMF_RECORD_TO_EMFPLUS(0x005E),WmfRecordTypeDeleteObject = GDIP_WMF_RECORD_TO_EMFPLUS(META_DELETEOBJECT),
  WmfRecordTypeCreatePalette = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPALETTE),WmfRecordTypeCreateBrush = GDIP_WMF_RECORD_TO_EMFPLUS(0x00F8),
  WmfRecordTypeCreatePatternBrush = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPATTERNBRUSH),
  WmfRecordTypeCreatePenIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEPENINDIRECT),
  WmfRecordTypeCreateFontIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEFONTINDIRECT),
  WmfRecordTypeCreateBrushIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEBRUSHINDIRECT),
  WmfRecordTypeCreateBitmapIndirect = GDIP_WMF_RECORD_TO_EMFPLUS(0x02FD),
  WmfRecordTypeCreateBitmap = GDIP_WMF_RECORD_TO_EMFPLUS(0x06FE),WmfRecordTypeCreateRegion = GDIP_WMF_RECORD_TO_EMFPLUS(META_CREATEREGION),
  EmfRecordTypeHeader = EMR_HEADER,EmfRecordTypePolyBezier = EMR_POLYBEZIER,EmfRecordTypePolygon = EMR_POLYGON,
  EmfRecordTypePolyline = EMR_POLYLINE,EmfRecordTypePolyBezierTo = EMR_POLYBEZIERTO,EmfRecordTypePolyLineTo = EMR_POLYLINETO,
  EmfRecordTypePolyPolyline = EMR_POLYPOLYLINE,EmfRecordTypePolyPolygon = EMR_POLYPOLYGON,EmfRecordTypeSetWindowExtEx = EMR_SETWINDOWEXTEX,
  EmfRecordTypeSetWindowOrgEx = EMR_SETWINDOWORGEX,EmfRecordTypeSetViewportExtEx = EMR_SETVIEWPORTEXTEX,
  EmfRecordTypeSetViewportOrgEx = EMR_SETVIEWPORTORGEX,EmfRecordTypeSetBrushOrgEx = EMR_SETBRUSHORGEX,EmfRecordTypeEOF = EMR_EOF,
  EmfRecordTypeSetPixelV = EMR_SETPIXELV,EmfRecordTypeSetMapperFlags = EMR_SETMAPPERFLAGS,EmfRecordTypeSetMapMode = EMR_SETMAPMODE,
  EmfRecordTypeSetBkMode = EMR_SETBKMODE,EmfRecordTypeSetPolyFillMode = EMR_SETPOLYFILLMODE,EmfRecordTypeSetROP2 = EMR_SETROP2,
  EmfRecordTypeSetStretchBltMode = EMR_SETSTRETCHBLTMODE,EmfRecordTypeSetTextAlign = EMR_SETTEXTALIGN,
  EmfRecordTypeSetColorAdjustment = EMR_SETCOLORADJUSTMENT,EmfRecordTypeSetTextColor = EMR_SETTEXTCOLOR,EmfRecordTypeSetBkColor = EMR_SETBKCOLOR,
  EmfRecordTypeOffsetClipRgn = EMR_OFFSETCLIPRGN,EmfRecordTypeMoveToEx = EMR_MOVETOEX,EmfRecordTypeSetMetaRgn = EMR_SETMETARGN,
  EmfRecordTypeExcludeClipRect = EMR_EXCLUDECLIPRECT,EmfRecordTypeIntersectClipRect = EMR_INTERSECTCLIPRECT,
  EmfRecordTypeScaleViewportExtEx = EMR_SCALEVIEWPORTEXTEX,EmfRecordTypeScaleWindowExtEx = EMR_SCALEWINDOWEXTEX,
  EmfRecordTypeSaveDC = EMR_SAVEDC,EmfRecordTypeRestoreDC = EMR_RESTOREDC,EmfRecordTypeSetWorldTransform = EMR_SETWORLDTRANSFORM,
  EmfRecordTypeModifyWorldTransform = EMR_MODIFYWORLDTRANSFORM,EmfRecordTypeSelectObject = EMR_SELECTOBJECT,EmfRecordTypeCreatePen = EMR_CREATEPEN,
  EmfRecordTypeCreateBrushIndirect = EMR_CREATEBRUSHINDIRECT,EmfRecordTypeDeleteObject = EMR_DELETEOBJECT,EmfRecordTypeAngleArc = EMR_ANGLEARC,
  EmfRecordTypeEllipse = EMR_ELLIPSE,EmfRecordTypeRectangle = EMR_RECTANGLE,EmfRecordTypeRoundRect = EMR_ROUNDRECT,EmfRecordTypeArc = EMR_ARC,
  EmfRecordTypeChord = EMR_CHORD,EmfRecordTypePie = EMR_PIE,EmfRecordTypeSelectPalette = EMR_SELECTPALETTE,
  EmfRecordTypeCreatePalette = EMR_CREATEPALETTE,EmfRecordTypeSetPaletteEntries = EMR_SETPALETTEENTRIES,
  EmfRecordTypeResizePalette = EMR_RESIZEPALETTE,EmfRecordTypeRealizePalette = EMR_REALIZEPALETTE,
  EmfRecordTypeExtFloodFill = EMR_EXTFLOODFILL,EmfRecordTypeLineTo = EMR_LINETO,EmfRecordTypeArcTo = EMR_ARCTO,
  EmfRecordTypePolyDraw = EMR_POLYDRAW,EmfRecordTypeSetArcDirection = EMR_SETARCDIRECTION,EmfRecordTypeSetMiterLimit = EMR_SETMITERLIMIT,
  EmfRecordTypeBeginPath = EMR_BEGINPATH,EmfRecordTypeEndPath = EMR_ENDPATH,EmfRecordTypeCloseFigure = EMR_CLOSEFIGURE,
  EmfRecordTypeFillPath = EMR_FILLPATH,EmfRecordTypeStrokeAndFillPath = EMR_STROKEANDFILLPATH,EmfRecordTypeStrokePath = EMR_STROKEPATH,
  EmfRecordTypeFlattenPath = EMR_FLATTENPATH,EmfRecordTypeWidenPath = EMR_WIDENPATH,EmfRecordTypeSelectClipPath = EMR_SELECTCLIPPATH,
  EmfRecordTypeAbortPath = EMR_ABORTPATH,EmfRecordTypeReserved_069 = 69,EmfRecordTypeGdiComment = EMR_GDICOMMENT,EmfRecordTypeFillRgn = EMR_FILLRGN,
  EmfRecordTypeFrameRgn = EMR_FRAMERGN,EmfRecordTypeInvertRgn = EMR_INVERTRGN,EmfRecordTypePaintRgn = EMR_PAINTRGN,
  EmfRecordTypeExtSelectClipRgn = EMR_EXTSELECTCLIPRGN,EmfRecordTypeBitBlt = EMR_BITBLT,EmfRecordTypeStretchBlt = EMR_STRETCHBLT,
  EmfRecordTypeMaskBlt = EMR_MASKBLT,EmfRecordTypePlgBlt = EMR_PLGBLT,EmfRecordTypeSetDIBitsToDevice = EMR_SETDIBITSTODEVICE,
  EmfRecordTypeStretchDIBits = EMR_STRETCHDIBITS,EmfRecordTypeExtCreateFontIndirect = EMR_EXTCREATEFONTINDIRECTW,
  EmfRecordTypeExtTextOutA = EMR_EXTTEXTOUTA,EmfRecordTypeExtTextOutW = EMR_EXTTEXTOUTW,EmfRecordTypePolyBezier16 = EMR_POLYBEZIER16,
  EmfRecordTypePolygon16 = EMR_POLYGON16,EmfRecordTypePolyline16 = EMR_POLYLINE16,EmfRecordTypePolyBezierTo16 = EMR_POLYBEZIERTO16,
  EmfRecordTypePolylineTo16 = EMR_POLYLINETO16,EmfRecordTypePolyPolyline16 = EMR_POLYPOLYLINE16,EmfRecordTypePolyPolygon16 = EMR_POLYPOLYGON16,
  EmfRecordTypePolyDraw16 = EMR_POLYDRAW16,EmfRecordTypeCreateMonoBrush = EMR_CREATEMONOBRUSH,
  EmfRecordTypeCreateDIBPatternBrushPt = EMR_CREATEDIBPATTERNBRUSHPT,EmfRecordTypeExtCreatePen = EMR_EXTCREATEPEN,
  EmfRecordTypePolyTextOutA = EMR_POLYTEXTOUTA,EmfRecordTypePolyTextOutW = EMR_POLYTEXTOUTW,EmfRecordTypeSetICMMode = 98,
  EmfRecordTypeCreateColorSpace = 99,EmfRecordTypeSetColorSpace = 100,EmfRecordTypeDeleteColorSpace = 101,EmfRecordTypeGLSRecord = 102,
  EmfRecordTypeGLSBoundedRecord = 103,EmfRecordTypePixelFormat = 104,EmfRecordTypeDrawEscape = 105,EmfRecordTypeExtEscape = 106,
  EmfRecordTypeStartDoc = 107,EmfRecordTypeSmallTextOut = 108,EmfRecordTypeForceUFIMapping = 109,EmfRecordTypeNamedEscape = 110,
  EmfRecordTypeColorCorrectPalette = 111,EmfRecordTypeSetICMProfileA = 112,EmfRecordTypeSetICMProfileW = 113,EmfRecordTypeAlphaBlend = 114,
  EmfRecordTypeSetLayout = 115,EmfRecordTypeTransparentBlt = 116,EmfRecordTypeReserved_117 = 117,EmfRecordTypeGradientFill = 118,
  EmfRecordTypeSetLinkedUFIs = 119,EmfRecordTypeSetTextJustification = 120,EmfRecordTypeColorMatchToTargetW = 121,EmfRecordTypeCreateColorSpaceW = 122,
  EmfRecordTypeMax = 122,EmfRecordTypeMin = 1,EmfPlusRecordTypeInvalid = GDIP_EMFPLUS_RECORD_BASE,EmfPlusRecordTypeHeader,EmfPlusRecordTypeEndOfFile,
  EmfPlusRecordTypeComment,EmfPlusRecordTypeGetDC,EmfPlusRecordTypeMultiFormatStart,EmfPlusRecordTypeMultiFormatSection,EmfPlusRecordTypeMultiFormatEnd,
  EmfPlusRecordTypeObject,EmfPlusRecordTypeClear,EmfPlusRecordTypeFillRects,EmfPlusRecordTypeDrawRects,EmfPlusRecordTypeFillPolygon,
  EmfPlusRecordTypeDrawLines,EmfPlusRecordTypeFillEllipse,EmfPlusRecordTypeDrawEllipse,EmfPlusRecordTypeFillPie,EmfPlusRecordTypeDrawPie,
  EmfPlusRecordTypeDrawArc,EmfPlusRecordTypeFillRegion,EmfPlusRecordTypeFillPath,EmfPlusRecordTypeDrawPath,EmfPlusRecordTypeFillClosedCurve,
  EmfPlusRecordTypeDrawClosedCurve,EmfPlusRecordTypeDrawCurve,EmfPlusRecordTypeDrawBeziers,EmfPlusRecordTypeDrawImage,
  EmfPlusRecordTypeDrawImagePoints,EmfPlusRecordTypeDrawString,EmfPlusRecordTypeSetRenderingOrigin,EmfPlusRecordTypeSetAntiAliasMode,
  EmfPlusRecordTypeSetTextRenderingHint,EmfPlusRecordTypeSetTextContrast,EmfPlusRecordTypeSetInterpolationMode,EmfPlusRecordTypeSetPixelOffsetMode,
  EmfPlusRecordTypeSetCompositingMode,EmfPlusRecordTypeSetCompositingQuality,EmfPlusRecordTypeSave,EmfPlusRecordTypeRestore,
  EmfPlusRecordTypeBeginContainer,EmfPlusRecordTypeBeginContainerNoParams,EmfPlusRecordTypeEndContainer,EmfPlusRecordTypeSetWorldTransform,
  EmfPlusRecordTypeResetWorldTransform,EmfPlusRecordTypeMultiplyWorldTransform,EmfPlusRecordTypeTranslateWorldTransform,
  EmfPlusRecordTypeScaleWorldTransform,EmfPlusRecordTypeRotateWorldTransform,EmfPlusRecordTypeSetPageTransform,EmfPlusRecordTypeResetClip,
  EmfPlusRecordTypeSetClipRect,EmfPlusRecordTypeSetClipPath,EmfPlusRecordTypeSetClipRegion,EmfPlusRecordTypeOffsetClip,
  EmfPlusRecordTypeDrawDriverString,EmfPlusRecordTotal,EmfPlusRecordTypeMax = EmfPlusRecordTotal-1,EmfPlusRecordTypeMin = EmfPlusRecordTypeHeader
};

enum StringFormatFlags {
  StringFormatFlagsDirectionRightToLeft = 0x00000001,StringFormatFlagsDirectionVertical = 0x00000002,StringFormatFlagsNoFitBlackBox = 0x00000004,
  StringFormatFlagsDisplayFormatControl = 0x00000020,StringFormatFlagsNoFontFallback = 0x00000400,StringFormatFlagsMeasureTrailingSpaces = 0x00000800,
  StringFormatFlagsNoWrap = 0x00001000,StringFormatFlagsLineLimit = 0x00002000,StringFormatFlagsNoClip = 0x00004000
};

enum StringTrimming {
  StringTrimmingNone = 0,StringTrimmingCharacter = 1,StringTrimmingWord = 2,StringTrimmingEllipsisCharacter = 3,StringTrimmingEllipsisWord = 4,
  StringTrimmingEllipsisPath = 5
};

enum StringDigitSubstitute {
  StringDigitSubstituteUser = 0,StringDigitSubstituteNone = 1,StringDigitSubstituteNational = 2,StringDigitSubstituteTraditional = 3
};

enum HotkeyPrefix {
  HotkeyPrefixNone = 0,HotkeyPrefixShow = 1,HotkeyPrefixHide = 2
};

enum StringAlignment {
  StringAlignmentNear = 0,StringAlignmentCenter = 1,StringAlignmentFar = 2
};

enum DriverStringOptions {
  DriverStringOptionsCmapLookup = 1,DriverStringOptionsVertical = 2,DriverStringOptionsRealizedAdvance = 4,DriverStringOptionsLimitSubpixel = 8
};

enum FlushIntention {
  FlushIntentionFlush = 0,FlushIntentionSync = 1
};

enum EncoderParameterValueType {
  EncoderParameterValueTypeByte = 1,EncoderParameterValueTypeASCII = 2,EncoderParameterValueTypeShort = 3,EncoderParameterValueTypeLong = 4,
  EncoderParameterValueTypeRational = 5,EncoderParameterValueTypeLongRange = 6,EncoderParameterValueTypeUndefined = 7,
  EncoderParameterValueTypeRationalRange = 8
};

enum EncoderValue {
  EncoderValueColorTypeCMYK,EncoderValueColorTypeYCCK,EncoderValueCompressionLZW,EncoderValueCompressionCCITT3,EncoderValueCompressionCCITT4,
  EncoderValueCompressionRle,EncoderValueCompressionNone,EncoderValueScanMethodInterlaced,EncoderValueScanMethodNonInterlaced,
  EncoderValueVersionGif87,EncoderValueVersionGif89,EncoderValueRenderProgressive,EncoderValueRenderNonProgressive,EncoderValueTransformRotate90,
  EncoderValueTransformRotate180,EncoderValueTransformRotate270,EncoderValueTransformFlipHorizontal,EncoderValueTransformFlipVertical,
  EncoderValueMultiFrame,EncoderValueLastFrame,EncoderValueFlush,EncoderValueFrameDimensionTime,EncoderValueFrameDimensionResolution,
  EncoderValueFrameDimensionPage
};

enum EmfToWmfBitsFlags {
  EmfToWmfBitsFlagsDefault = 0x00000000,EmfToWmfBitsFlagsEmbedEmf = 0x00000001,EmfToWmfBitsFlagsIncludePlaceable = 0x00000002,
  EmfToWmfBitsFlagsNoXORClip = 0x00000004
};

enum GpTestControlEnum {
  TestControlForceBilinear = 0,TestControlNoICM = 1,TestControlGetBuildNumber = 2
};
#endif
