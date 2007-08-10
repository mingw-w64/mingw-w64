/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSMETAFILE_H
#define _GDIPLUSMETAFILE_H

class Metafile : public Image {
public:
  friend class Image;
  Metafile(HMETAFILE hWmf,const WmfPlaceableFileHeader *wmfPlaceableFileHeader,WINBOOL deleteWmf = FALSE) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipCreateMetafileFromWmf(hWmf,deleteWmf,wmfPlaceableFileHeader,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(HENHMETAFILE hEmf,WINBOOL deleteEmf = FALSE) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipCreateMetafileFromEmf(hEmf,deleteEmf,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(const WCHAR *filename) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipCreateMetafileFromFile(filename,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(const WCHAR *filename,const WmfPlaceableFileHeader *wmfPlaceableFileHeader) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipCreateMetafileFromWmfFile(filename,wmfPlaceableFileHeader,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(IStream *stream) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipCreateMetafileFromStream(stream,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(HDC referenceHdc,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafile(referenceHdc,type,NULL,MetafileFrameUnitGdi,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(HDC referenceHdc,const RectF &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafile(referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(HDC referenceHdc,const Rect &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileI(referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(const WCHAR *fileName,HDC referenceHdc,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileFileName(fileName,referenceHdc,type,NULL,MetafileFrameUnitGdi,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(const WCHAR *fileName,HDC referenceHdc,const RectF &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileFileName(fileName,referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(const WCHAR *fileName,HDC referenceHdc,const Rect &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileFileNameI(fileName,referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(IStream *stream,HDC referenceHdc,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileStream(stream,referenceHdc,type,NULL,MetafileFrameUnitGdi,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(IStream *stream,HDC referenceHdc,const RectF &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileStream(stream,referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  Metafile(IStream *stream,HDC referenceHdc,const Rect &frameRect,MetafileFrameUnit frameUnit = MetafileFrameUnitGdi,EmfType type = EmfTypeEmfPlusDual,const WCHAR *description = NULL) {
    GpMetafile *metafile = NULL;
    lastResult = DllExports::GdipRecordMetafileStreamI(stream,referenceHdc,type,&frameRect,frameUnit,description,&metafile);
    SetNativeImage(metafile);
  }
  static Status GetMetafileHeader(HMETAFILE hWmf,const WmfPlaceableFileHeader *wmfPlaceableFileHeader,MetafileHeader *header) { return DllExports::GdipGetMetafileHeaderFromWmf(hWmf,wmfPlaceableFileHeader,header); }
  static Status GetMetafileHeader(HENHMETAFILE hEmf,MetafileHeader *header) { return DllExports::GdipGetMetafileHeaderFromEmf(hEmf,header); }
  static Status GetMetafileHeader(const WCHAR *filename,MetafileHeader *header) { return DllExports::GdipGetMetafileHeaderFromFile(filename,header); }
  static Status GetMetafileHeader(IStream *stream,MetafileHeader *header) { return DllExports::GdipGetMetafileHeaderFromStream(stream,header); }
  Status GetMetafileHeader(MetafileHeader *header) const { return SetStatus(DllExports::GdipGetMetafileHeaderFromMetafile((GpMetafile *)nativeImage,header)); }
  HENHMETAFILE GetHENHMETAFILE() {
    HENHMETAFILE hEmf;
    SetStatus(DllExports::GdipGetHemfFromMetafile((GpMetafile *)nativeImage,&hEmf));
    return hEmf;
  }
  Status PlayRecord(EmfPlusRecordType recordType,UINT flags,UINT dataSize,const BYTE *data) const { return SetStatus(DllExports::GdipPlayMetafileRecord((GpMetafile *)nativeImage,recordType,flags,dataSize,data)); }
  Status SetDownLevelRasterizationLimit(UINT metafileRasterizationLimitDpi) { return SetStatus(DllExports::GdipSetMetafileDownLevelRasterizationLimit((GpMetafile *)nativeImage,metafileRasterizationLimitDpi)); }
  UINT GetDownLevelRasterizationLimit() const {
    UINT metafileRasterizationLimitDpi = 0;
    SetStatus(DllExports::GdipGetMetafileDownLevelRasterizationLimit((GpMetafile *)nativeImage,&metafileRasterizationLimitDpi));
    return metafileRasterizationLimitDpi;
  }
  static UINT Metafile::EmfToWmfBits(HENHMETAFILE hemf,UINT cbData16,LPBYTE pData16,INT iMapMode = MM_ANISOTROPIC,INT eFlags = EmfToWmfBitsFlagsDefault) { return DllExports::GdipEmfToWmfBits(hemf,cbData16,pData16,iMapMode,eFlags); }
protected:
  Metafile() {
    SetNativeImage(NULL);
    lastResult = Ok;
  }
private:
  Metafile(const Metafile &);
  Metafile& operator=(const Metafile &);
};
#endif
