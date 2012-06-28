/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __commoncontrols_h__
#define __commoncontrols_h__

#ifndef __IImageList_FWD_DEFINED__
#define __IImageList_FWD_DEFINED__
typedef struct IImageList IImageList;
#endif

#ifndef __ImageList_FWD_DEFINED__
#define __ImageList_FWD_DEFINED__
#ifdef __cplusplus
typedef class ImageList ImageList;
#else
typedef struct ImageList ImageList;
#endif
#endif

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#define ILIF_ALPHA 0x00000001

  extern RPC_IF_HANDLE __MIDL_itf_commoncontrols_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_commoncontrols_0000_v0_0_s_ifspec;

#ifndef __IImageList_INTERFACE_DEFINED__
#define __IImageList_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IImageList;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IImageList : public IUnknown {
  public:
    virtual HRESULT WINAPI Add(HBITMAP hbmImage,HBITMAP hbmMask,int *pi) = 0;
    virtual HRESULT WINAPI ReplaceIcon(int i,HICON hicon,int *pi) = 0;
    virtual HRESULT WINAPI SetOverlayImage(int iImage,int iOverlay) = 0;
    virtual HRESULT WINAPI Replace(int i,HBITMAP hbmImage,HBITMAP hbmMask) = 0;
    virtual HRESULT WINAPI AddMasked(HBITMAP hbmImage,COLORREF crMask,int *pi) = 0;
    virtual HRESULT WINAPI Draw(IMAGELISTDRAWPARAMS *pimldp) = 0;
    virtual HRESULT WINAPI Remove(int i) = 0;
    virtual HRESULT WINAPI GetIcon(int i,UINT flags,HICON *picon) = 0;
    virtual HRESULT WINAPI GetImageInfo(int i,IMAGEINFO *pImageInfo) = 0;
    virtual HRESULT WINAPI Copy(int iDst,IUnknown *punkSrc,int iSrc,UINT uFlags) = 0;
    virtual HRESULT WINAPI Merge(int i1,IUnknown *punk2,int i2,int dx,int dy,REFIID riid,PVOID *ppv) = 0;
    virtual HRESULT WINAPI Clone(REFIID riid,PVOID *ppv) = 0;
    virtual HRESULT WINAPI GetImageRect(int i,RECT *prc) = 0;
    virtual HRESULT WINAPI GetIconSize(int *cx,int *cy) = 0;
    virtual HRESULT WINAPI SetIconSize(int cx,int cy) = 0;
    virtual HRESULT WINAPI GetImageCount(int *pi) = 0;
    virtual HRESULT WINAPI SetImageCount(UINT uNewCount) = 0;
    virtual HRESULT WINAPI SetBkColor(COLORREF clrBk,COLORREF *pclr) = 0;
    virtual HRESULT WINAPI GetBkColor(COLORREF *pclr) = 0;
    virtual HRESULT WINAPI BeginDrag(int iTrack,int dxHotspot,int dyHotspot) = 0;
    virtual HRESULT WINAPI EndDrag(void) = 0;
    virtual HRESULT WINAPI DragEnter(HWND hwndLock,int x,int y) = 0;
    virtual HRESULT WINAPI DragLeave(HWND hwndLock) = 0;
    virtual HRESULT WINAPI DragMove(int x,int y) = 0;
    virtual HRESULT WINAPI SetDragCursorImage(IUnknown *punk,int iDrag,int dxHotspot,int dyHotspot) = 0;
    virtual HRESULT WINAPI DragShowNolock(WINBOOL fShow) = 0;
    virtual HRESULT WINAPI GetDragImage(POINT *ppt,POINT *pptHotspot,REFIID riid,PVOID *ppv) = 0;
    virtual HRESULT WINAPI GetItemFlags(int i,DWORD *dwFlags) = 0;
    virtual HRESULT WINAPI GetOverlayImage(int iOverlay,int *piIndex) = 0;
  };
#else
  typedef struct IImageListVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IImageList *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IImageList *This);
      ULONG (WINAPI *Release)(IImageList *This);
      HRESULT (WINAPI *Add)(IImageList *This,HBITMAP hbmImage,HBITMAP hbmMask,int *pi);
      HRESULT (WINAPI *ReplaceIcon)(IImageList *This,int i,HICON hicon,int *pi);
      HRESULT (WINAPI *SetOverlayImage)(IImageList *This,int iImage,int iOverlay);
      HRESULT (WINAPI *Replace)(IImageList *This,int i,HBITMAP hbmImage,HBITMAP hbmMask);
      HRESULT (WINAPI *AddMasked)(IImageList *This,HBITMAP hbmImage,COLORREF crMask,int *pi);
      HRESULT (WINAPI *Draw)(IImageList *This,IMAGELISTDRAWPARAMS *pimldp);
      HRESULT (WINAPI *Remove)(IImageList *This,int i);
      HRESULT (WINAPI *GetIcon)(IImageList *This,int i,UINT flags,HICON *picon);
      HRESULT (WINAPI *GetImageInfo)(IImageList *This,int i,IMAGEINFO *pImageInfo);
      HRESULT (WINAPI *Copy)(IImageList *This,int iDst,IUnknown *punkSrc,int iSrc,UINT uFlags);
      HRESULT (WINAPI *Merge)(IImageList *This,int i1,IUnknown *punk2,int i2,int dx,int dy,REFIID riid,PVOID *ppv);
      HRESULT (WINAPI *Clone)(IImageList *This,REFIID riid,PVOID *ppv);
      HRESULT (WINAPI *GetImageRect)(IImageList *This,int i,RECT *prc);
      HRESULT (WINAPI *GetIconSize)(IImageList *This,int *cx,int *cy);
      HRESULT (WINAPI *SetIconSize)(IImageList *This,int cx,int cy);
      HRESULT (WINAPI *GetImageCount)(IImageList *This,int *pi);
      HRESULT (WINAPI *SetImageCount)(IImageList *This,UINT uNewCount);
      HRESULT (WINAPI *SetBkColor)(IImageList *This,COLORREF clrBk,COLORREF *pclr);
      HRESULT (WINAPI *GetBkColor)(IImageList *This,COLORREF *pclr);
      HRESULT (WINAPI *BeginDrag)(IImageList *This,int iTrack,int dxHotspot,int dyHotspot);
      HRESULT (WINAPI *EndDrag)(IImageList *This);
      HRESULT (WINAPI *DragEnter)(IImageList *This,HWND hwndLock,int x,int y);
      HRESULT (WINAPI *DragLeave)(IImageList *This,HWND hwndLock);
      HRESULT (WINAPI *DragMove)(IImageList *This,int x,int y);
      HRESULT (WINAPI *SetDragCursorImage)(IImageList *This,IUnknown *punk,int iDrag,int dxHotspot,int dyHotspot);
      HRESULT (WINAPI *DragShowNolock)(IImageList *This,WINBOOL fShow);
      HRESULT (WINAPI *GetDragImage)(IImageList *This,POINT *ppt,POINT *pptHotspot,REFIID riid,PVOID *ppv);
      HRESULT (WINAPI *GetItemFlags)(IImageList *This,int i,DWORD *dwFlags);
      HRESULT (WINAPI *GetOverlayImage)(IImageList *This,int iOverlay,int *piIndex);
    END_INTERFACE
  } IImageListVtbl;
  struct IImageList {
    CONST_VTBL struct IImageListVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IImageList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IImageList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IImageList_Release(This) (This)->lpVtbl->Release(This)
#define IImageList_Add(This,hbmImage,hbmMask,pi) (This)->lpVtbl->Add(This,hbmImage,hbmMask,pi)
#define IImageList_ReplaceIcon(This,i,hicon,pi) (This)->lpVtbl->ReplaceIcon(This,i,hicon,pi)
#define IImageList_SetOverlayImage(This,iImage,iOverlay) (This)->lpVtbl->SetOverlayImage(This,iImage,iOverlay)
#define IImageList_Replace(This,i,hbmImage,hbmMask) (This)->lpVtbl->Replace(This,i,hbmImage,hbmMask)
#define IImageList_AddMasked(This,hbmImage,crMask,pi) (This)->lpVtbl->AddMasked(This,hbmImage,crMask,pi)
#define IImageList_Draw(This,pimldp) (This)->lpVtbl->Draw(This,pimldp)
#define IImageList_Remove(This,i) (This)->lpVtbl->Remove(This,i)
#define IImageList_GetIcon(This,i,flags,picon) (This)->lpVtbl->GetIcon(This,i,flags,picon)
#define IImageList_GetImageInfo(This,i,pImageInfo) (This)->lpVtbl->GetImageInfo(This,i,pImageInfo)
#define IImageList_Copy(This,iDst,punkSrc,iSrc,uFlags) (This)->lpVtbl->Copy(This,iDst,punkSrc,iSrc,uFlags)
#define IImageList_Merge(This,i1,punk2,i2,dx,dy,riid,ppv) (This)->lpVtbl->Merge(This,i1,punk2,i2,dx,dy,riid,ppv)
#define IImageList_Clone(This,riid,ppv) (This)->lpVtbl->Clone(This,riid,ppv)
#define IImageList_GetImageRect(This,i,prc) (This)->lpVtbl->GetImageRect(This,i,prc)
#define IImageList_GetIconSize(This,cx,cy) (This)->lpVtbl->GetIconSize(This,cx,cy)
#define IImageList_SetIconSize(This,cx,cy) (This)->lpVtbl->SetIconSize(This,cx,cy)
#define IImageList_GetImageCount(This,pi) (This)->lpVtbl->GetImageCount(This,pi)
#define IImageList_SetImageCount(This,uNewCount) (This)->lpVtbl->SetImageCount(This,uNewCount)
#define IImageList_SetBkColor(This,clrBk,pclr) (This)->lpVtbl->SetBkColor(This,clrBk,pclr)
#define IImageList_GetBkColor(This,pclr) (This)->lpVtbl->GetBkColor(This,pclr)
#define IImageList_BeginDrag(This,iTrack,dxHotspot,dyHotspot) (This)->lpVtbl->BeginDrag(This,iTrack,dxHotspot,dyHotspot)
#define IImageList_EndDrag(This) (This)->lpVtbl->EndDrag(This)
#define IImageList_DragEnter(This,hwndLock,x,y) (This)->lpVtbl->DragEnter(This,hwndLock,x,y)
#define IImageList_DragLeave(This,hwndLock) (This)->lpVtbl->DragLeave(This,hwndLock)
#define IImageList_DragMove(This,x,y) (This)->lpVtbl->DragMove(This,x,y)
#define IImageList_SetDragCursorImage(This,punk,iDrag,dxHotspot,dyHotspot) (This)->lpVtbl->SetDragCursorImage(This,punk,iDrag,dxHotspot,dyHotspot)
#define IImageList_DragShowNolock(This,fShow) (This)->lpVtbl->DragShowNolock(This,fShow)
#define IImageList_GetDragImage(This,ppt,pptHotspot,riid,ppv) (This)->lpVtbl->GetDragImage(This,ppt,pptHotspot,riid,ppv)
#define IImageList_GetItemFlags(This,i,dwFlags) (This)->lpVtbl->GetItemFlags(This,i,dwFlags)
#define IImageList_GetOverlayImage(This,iOverlay,piIndex) (This)->lpVtbl->GetOverlayImage(This,iOverlay,piIndex)
#endif
#endif
  HRESULT WINAPI IImageList_Add_Proxy(IImageList *This,HBITMAP hbmImage,HBITMAP hbmMask,int *pi);
  void __RPC_STUB IImageList_Add_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_ReplaceIcon_Proxy(IImageList *This,int i,HICON hicon,int *pi);
  void __RPC_STUB IImageList_ReplaceIcon_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_SetOverlayImage_Proxy(IImageList *This,int iImage,int iOverlay);
  void __RPC_STUB IImageList_SetOverlayImage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Replace_Proxy(IImageList *This,int i,HBITMAP hbmImage,HBITMAP hbmMask);
  void __RPC_STUB IImageList_Replace_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_AddMasked_Proxy(IImageList *This,HBITMAP hbmImage,COLORREF crMask,int *pi);
  void __RPC_STUB IImageList_AddMasked_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Draw_Proxy(IImageList *This,IMAGELISTDRAWPARAMS *pimldp);
  void __RPC_STUB IImageList_Draw_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Remove_Proxy(IImageList *This,int i);
  void __RPC_STUB IImageList_Remove_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetIcon_Proxy(IImageList *This,int i,UINT flags,HICON *picon);
  void __RPC_STUB IImageList_GetIcon_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetImageInfo_Proxy(IImageList *This,int i,IMAGEINFO *pImageInfo);
  void __RPC_STUB IImageList_GetImageInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Copy_Proxy(IImageList *This,int iDst,IUnknown *punkSrc,int iSrc,UINT uFlags);
  void __RPC_STUB IImageList_Copy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Merge_Proxy(IImageList *This,int i1,IUnknown *punk2,int i2,int dx,int dy,REFIID riid,PVOID *ppv);
  void __RPC_STUB IImageList_Merge_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_Clone_Proxy(IImageList *This,REFIID riid,PVOID *ppv);
  void __RPC_STUB IImageList_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetImageRect_Proxy(IImageList *This,int i,RECT *prc);
  void __RPC_STUB IImageList_GetImageRect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetIconSize_Proxy(IImageList *This,int *cx,int *cy);
  void __RPC_STUB IImageList_GetIconSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_SetIconSize_Proxy(IImageList *This,int cx,int cy);
  void __RPC_STUB IImageList_SetIconSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetImageCount_Proxy(IImageList *This,int *pi);
  void __RPC_STUB IImageList_GetImageCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_SetImageCount_Proxy(IImageList *This,UINT uNewCount);
  void __RPC_STUB IImageList_SetImageCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_SetBkColor_Proxy(IImageList *This,COLORREF clrBk,COLORREF *pclr);
  void __RPC_STUB IImageList_SetBkColor_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetBkColor_Proxy(IImageList *This,COLORREF *pclr);
  void __RPC_STUB IImageList_GetBkColor_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_BeginDrag_Proxy(IImageList *This,int iTrack,int dxHotspot,int dyHotspot);
  void __RPC_STUB IImageList_BeginDrag_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_EndDrag_Proxy(IImageList *This);
  void __RPC_STUB IImageList_EndDrag_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_DragEnter_Proxy(IImageList *This,HWND hwndLock,int x,int y);
  void __RPC_STUB IImageList_DragEnter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_DragLeave_Proxy(IImageList *This,HWND hwndLock);
  void __RPC_STUB IImageList_DragLeave_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_DragMove_Proxy(IImageList *This,int x,int y);
  void __RPC_STUB IImageList_DragMove_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_SetDragCursorImage_Proxy(IImageList *This,IUnknown *punk,int iDrag,int dxHotspot,int dyHotspot);
  void __RPC_STUB IImageList_SetDragCursorImage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_DragShowNolock_Proxy(IImageList *This,WINBOOL fShow);
  void __RPC_STUB IImageList_DragShowNolock_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetDragImage_Proxy(IImageList *This,POINT *ppt,POINT *pptHotspot,REFIID riid,PVOID *ppv);
  void __RPC_STUB IImageList_GetDragImage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetItemFlags_Proxy(IImageList *This,int i,DWORD *dwFlags);
  void __RPC_STUB IImageList_GetItemFlags_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IImageList_GetOverlayImage_Proxy(IImageList *This,int iOverlay,int *piIndex);
  void __RPC_STUB IImageList_GetOverlayImage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __CommonControlObjects_LIBRARY_DEFINED__
#define __CommonControlObjects_LIBRARY_DEFINED__
  EXTERN_C const IID LIBID_CommonControlObjects;
  EXTERN_C const CLSID CLSID_ImageList;
#ifdef __cplusplus
  class ImageList;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
