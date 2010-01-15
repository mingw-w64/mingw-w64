/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _RICHOLE_
#define _RICHOLE_

#include "richedit.h"

typedef struct _reobject {
  DWORD cbStruct;
  LONG cp;
  CLSID clsid;
  LPOLEOBJECT poleobj;
  LPSTORAGE pstg;
  LPOLECLIENTSITE polesite;
  SIZEL sizel;
  DWORD dvaspect;
  DWORD dwFlags;
  DWORD dwUser;
} REOBJECT;

#define REO_GETOBJ_NO_INTERFACES (0x00000000L)
#define REO_GETOBJ_POLEOBJ (0x00000001L)
#define REO_GETOBJ_PSTG (0x00000002L)
#define REO_GETOBJ_POLESITE (0x00000004L)
#define REO_GETOBJ_ALL_INTERFACES (0x00000007L)

#define REO_CP_SELECTION ((ULONG) -1L)

#define REO_IOB_SELECTION ((ULONG) -1L)
#define REO_IOB_USE_CP ((ULONG) -2L)

#define REO_NULL (0x00000000L)
#define REO_READWRITEMASK (0x0000003FL)
#define REO_DONTNEEDPALETTE (0x00000020L)
#define REO_BLANK (0x00000010L)
#define REO_DYNAMICSIZE (0x00000008L)
#define REO_INVERTEDSELECT (0x00000004L)
#define REO_BELOWBASELINE (0x00000002L)
#define REO_RESIZABLE (0x00000001L)
#define REO_LINK (0x80000000L)
#define REO_STATIC (0x40000000L)
#define REO_SELECTED (0x08000000L)
#define REO_OPEN (0x04000000L)
#define REO_INPLACEACTIVE (0x02000000L)
#define REO_HILITED (0x01000000L)
#define REO_LINKAVAILABLE (0x00800000L)
#define REO_GETMETAFILE (0x00400000L)

#define RECO_PASTE (0x00000000L)
#define RECO_DROP (0x00000001L)
#define RECO_COPY (0x00000002L)
#define RECO_CUT (0x00000003L)
#define RECO_DRAG (0x00000004L)

#undef INTERFACE
#define INTERFACE IRichEditOle
DECLARE_INTERFACE_(IRichEditOle,IUnknown) {
  STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *lplpObj) PURE;
  STDMETHOD_(ULONG,AddRef) (THIS) PURE;
  STDMETHOD_(ULONG,Release) (THIS) PURE;
  STDMETHOD(GetClientSite) (THIS_ LPOLECLIENTSITE *lplpolesite) PURE;
  STDMETHOD_(LONG,GetObjectCount) (THIS) PURE;
  STDMETHOD_(LONG,GetLinkCount) (THIS) PURE;
  STDMETHOD(GetObject) (THIS_ LONG iob,REOBJECT *lpreobject,DWORD dwFlags) PURE;
  STDMETHOD(InsertObject) (THIS_ REOBJECT *lpreobject) PURE;
  STDMETHOD(ConvertObject) (THIS_ LONG iob,REFCLSID rclsidNew,LPCSTR lpstrUserTypeNew) PURE;
  STDMETHOD(ActivateAs) (THIS_ REFCLSID rclsid,REFCLSID rclsidAs) PURE;
  STDMETHOD(SetHostNames) (THIS_ LPCSTR lpstrContainerApp,LPCSTR lpstrContainerObj) PURE;
  STDMETHOD(SetLinkAvailable) (THIS_ LONG iob,WINBOOL fAvailable) PURE;
  STDMETHOD(SetDvaspect) (THIS_ LONG iob,DWORD dvaspect) PURE;
  STDMETHOD(HandsOffStorage) (THIS_ LONG iob) PURE;
  STDMETHOD(SaveCompleted) (THIS_ LONG iob,LPSTORAGE lpstg) PURE;
  STDMETHOD(InPlaceDeactivate) (THIS) PURE;
  STDMETHOD(ContextSensitiveHelp) (THIS_ WINBOOL fEnterMode) PURE;
  STDMETHOD(GetClipboardData) (THIS_ CHARRANGE *lpchrg,DWORD reco,LPDATAOBJECT *lplpdataobj) PURE;
  STDMETHOD(ImportDataObject) (THIS_ LPDATAOBJECT lpdataobj,CLIPFORMAT cf,HGLOBAL hMetaPict) PURE;
};
typedef IRichEditOle *LPRICHEDITOLE;

#undef INTERFACE
#define INTERFACE IRichEditOleCallback
DECLARE_INTERFACE_(IRichEditOleCallback,IUnknown) {
  STDMETHOD(QueryInterface) (THIS_ REFIID riid,LPVOID *lplpObj) PURE;
  STDMETHOD_(ULONG,AddRef) (THIS) PURE;
  STDMETHOD_(ULONG,Release) (THIS) PURE;
  STDMETHOD(GetNewStorage) (THIS_ LPSTORAGE *lplpstg) PURE;
  STDMETHOD(GetInPlaceContext) (THIS_ LPOLEINPLACEFRAME *lplpFrame,LPOLEINPLACEUIWINDOW *lplpDoc,LPOLEINPLACEFRAMEINFO lpFrameInfo) PURE;
  STDMETHOD(ShowContainerUI) (THIS_ WINBOOL fShow) PURE;
  STDMETHOD(QueryInsertObject) (THIS_ LPCLSID lpclsid,LPSTORAGE lpstg,LONG cp) PURE;
  STDMETHOD(DeleteObject) (THIS_ LPOLEOBJECT lpoleobj) PURE;
  STDMETHOD(QueryAcceptData) (THIS_ LPDATAOBJECT lpdataobj,CLIPFORMAT *lpcfFormat,DWORD reco,WINBOOL fReally,HGLOBAL hMetaPict) PURE;
  STDMETHOD(ContextSensitiveHelp) (THIS_ WINBOOL fEnterMode) PURE;
  STDMETHOD(GetClipboardData) (THIS_ CHARRANGE *lpchrg,DWORD reco,LPDATAOBJECT *lplpdataobj) PURE;
  STDMETHOD(GetDragDropEffect) (THIS_ WINBOOL fDrag,DWORD grfKeyState,LPDWORD pdwEffect) PURE;
  STDMETHOD(GetContextMenu) (THIS_ WORD seltype,LPOLEOBJECT lpoleobj,CHARRANGE *lpchrg,HMENU *lphmenu) PURE;
};
typedef IRichEditOleCallback *LPRICHEDITOLECALLBACK;

DEFINE_GUID(IID_IRichEditOle,0x00020D00,0,0,0xC0,0,0,0,0,0,0,0x46);
DEFINE_GUID(IID_IRichEditOleCallback,0x00020D03,0,0,0xC0,0,0,0,0,0,0,0x46);
#endif
