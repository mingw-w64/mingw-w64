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
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __shldisp_h__
#define __shldisp_h__

#ifndef __IFolderViewOC_FWD_DEFINED__
#define __IFolderViewOC_FWD_DEFINED__
typedef struct IFolderViewOC IFolderViewOC;
#endif

#ifndef __DShellFolderViewEvents_FWD_DEFINED__
#define __DShellFolderViewEvents_FWD_DEFINED__
typedef struct DShellFolderViewEvents DShellFolderViewEvents;
#endif

#ifndef __ShellFolderViewOC_FWD_DEFINED__
#define __ShellFolderViewOC_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellFolderViewOC ShellFolderViewOC;
#else
typedef struct ShellFolderViewOC ShellFolderViewOC;
#endif
#endif

#ifndef __DFConstraint_FWD_DEFINED__
#define __DFConstraint_FWD_DEFINED__
typedef struct DFConstraint DFConstraint;
#endif

#ifndef __ISearchCommandExt_FWD_DEFINED__
#define __ISearchCommandExt_FWD_DEFINED__
typedef struct ISearchCommandExt ISearchCommandExt;
#endif

#ifndef __FolderItem_FWD_DEFINED__
#define __FolderItem_FWD_DEFINED__
typedef struct FolderItem FolderItem;
#endif

#ifndef __FolderItems_FWD_DEFINED__
#define __FolderItems_FWD_DEFINED__
typedef struct FolderItems FolderItems;
#endif

#ifndef __FolderItemVerb_FWD_DEFINED__
#define __FolderItemVerb_FWD_DEFINED__
typedef struct FolderItemVerb FolderItemVerb;
#endif

#ifndef __FolderItemVerbs_FWD_DEFINED__
#define __FolderItemVerbs_FWD_DEFINED__
typedef struct FolderItemVerbs FolderItemVerbs;
#endif

#ifndef __Folder_FWD_DEFINED__
#define __Folder_FWD_DEFINED__
typedef struct Folder Folder;
#endif

#ifndef __Folder2_FWD_DEFINED__
#define __Folder2_FWD_DEFINED__
typedef struct Folder2 Folder2;
#endif

#ifndef __Folder3_FWD_DEFINED__
#define __Folder3_FWD_DEFINED__
typedef struct Folder3 Folder3;
#endif

#ifndef __FolderItem2_FWD_DEFINED__
#define __FolderItem2_FWD_DEFINED__
typedef struct FolderItem2 FolderItem2;
#endif

#ifndef __ShellFolderItem_FWD_DEFINED__
#define __ShellFolderItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class ShellFolderItem ShellFolderItem;
#else
typedef struct ShellFolderItem ShellFolderItem;
#endif
#endif

#ifndef __FolderItems2_FWD_DEFINED__
#define __FolderItems2_FWD_DEFINED__
typedef struct FolderItems2 FolderItems2;
#endif

#ifndef __FolderItems3_FWD_DEFINED__
#define __FolderItems3_FWD_DEFINED__
typedef struct FolderItems3 FolderItems3;
#endif

#ifndef __IShellLinkDual_FWD_DEFINED__
#define __IShellLinkDual_FWD_DEFINED__
typedef struct IShellLinkDual IShellLinkDual;
#endif

#ifndef __IShellLinkDual2_FWD_DEFINED__
#define __IShellLinkDual2_FWD_DEFINED__
typedef struct IShellLinkDual2 IShellLinkDual2;
#endif

#ifndef __ShellLinkObject_FWD_DEFINED__
#define __ShellLinkObject_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellLinkObject ShellLinkObject;
#else
typedef struct ShellLinkObject ShellLinkObject;
#endif
#endif

#ifndef __IShellFolderViewDual_FWD_DEFINED__
#define __IShellFolderViewDual_FWD_DEFINED__
typedef struct IShellFolderViewDual IShellFolderViewDual;
#endif

#ifndef __IShellFolderViewDual2_FWD_DEFINED__
#define __IShellFolderViewDual2_FWD_DEFINED__
typedef struct IShellFolderViewDual2 IShellFolderViewDual2;
#endif

#ifndef __ShellFolderView_FWD_DEFINED__
#define __ShellFolderView_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellFolderView ShellFolderView;
#else
typedef struct ShellFolderView ShellFolderView;
#endif
#endif

#ifndef __IShellDispatch_FWD_DEFINED__
#define __IShellDispatch_FWD_DEFINED__
typedef struct IShellDispatch IShellDispatch;
#endif

#ifndef __IShellDispatch2_FWD_DEFINED__
#define __IShellDispatch2_FWD_DEFINED__
typedef struct IShellDispatch2 IShellDispatch2;
#endif

#ifndef __IShellDispatch3_FWD_DEFINED__
#define __IShellDispatch3_FWD_DEFINED__
typedef struct IShellDispatch3 IShellDispatch3;
#endif

#ifndef __IShellDispatch4_FWD_DEFINED__
#define __IShellDispatch4_FWD_DEFINED__
typedef struct IShellDispatch4 IShellDispatch4;
#endif

#ifndef __Shell_FWD_DEFINED__
#define __Shell_FWD_DEFINED__
#ifdef __cplusplus
typedef class Shell Shell;
#else
typedef struct Shell Shell;
#endif
#endif

#ifndef __ShellDispatchInproc_FWD_DEFINED__
#define __ShellDispatchInproc_FWD_DEFINED__
#ifdef __cplusplus
typedef class ShellDispatchInproc ShellDispatchInproc;
#else
typedef struct ShellDispatchInproc ShellDispatchInproc;
#endif
#endif

#ifndef __WebViewFolderContents_FWD_DEFINED__
#define __WebViewFolderContents_FWD_DEFINED__
#ifdef __cplusplus
typedef class WebViewFolderContents WebViewFolderContents;
#else
typedef struct WebViewFolderContents WebViewFolderContents;
#endif
#endif

#ifndef __DSearchCommandEvents_FWD_DEFINED__
#define __DSearchCommandEvents_FWD_DEFINED__
typedef struct DSearchCommandEvents DSearchCommandEvents;
#endif

#ifndef __SearchCommand_FWD_DEFINED__
#define __SearchCommand_FWD_DEFINED__
#ifdef __cplusplus
typedef class SearchCommand SearchCommand;
#else
typedef struct SearchCommand SearchCommand;
#endif
#endif

#ifndef __IFileSearchBand_FWD_DEFINED__
#define __IFileSearchBand_FWD_DEFINED__
typedef struct IFileSearchBand IFileSearchBand;
#endif

#ifndef __FileSearchBand_FWD_DEFINED__
#define __FileSearchBand_FWD_DEFINED__
#ifdef __cplusplus
typedef class FileSearchBand FileSearchBand;
#else
typedef struct FileSearchBand FileSearchBand;
#endif
#endif

#ifndef __IWebWizardHost_FWD_DEFINED__
#define __IWebWizardHost_FWD_DEFINED__
typedef struct IWebWizardHost IWebWizardHost;
#endif

#ifndef __INewWDEvents_FWD_DEFINED__
#define __INewWDEvents_FWD_DEFINED__
typedef struct INewWDEvents INewWDEvents;
#endif

#ifndef __IPassportClientServices_FWD_DEFINED__
#define __IPassportClientServices_FWD_DEFINED__
typedef struct IPassportClientServices IPassportClientServices;
#endif

#ifndef __PassportClientServices_FWD_DEFINED__
#define __PassportClientServices_FWD_DEFINED__
#ifdef __cplusplus
typedef class PassportClientServices PassportClientServices;
#else
typedef struct PassportClientServices PassportClientServices;
#endif
#endif

#ifndef __IAutoComplete_FWD_DEFINED__
#define __IAutoComplete_FWD_DEFINED__
typedef struct IAutoComplete IAutoComplete;
#endif

#ifndef __IAutoComplete2_FWD_DEFINED__
#define __IAutoComplete2_FWD_DEFINED__
typedef struct IAutoComplete2 IAutoComplete2;
#endif

#ifndef __IEnumACString_FWD_DEFINED__
#define __IEnumACString_FWD_DEFINED__
typedef struct IEnumACString IEnumACString;
#endif

#ifndef __IAsyncOperation_FWD_DEFINED__
#define __IAsyncOperation_FWD_DEFINED__
typedef struct IAsyncOperation IAsyncOperation;
#endif

#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0000_v0_0_s_ifspec;

#ifndef __Shell32_LIBRARY_DEFINED__
#define __Shell32_LIBRARY_DEFINED__
  typedef enum SearchCommandExecuteErrors {
    SCEE_PATHNOTFOUND = 1,
    SCEE_MAXFILESFOUND,SCEE_INDEXSEARCH,SCEE_CONSTRAINT,SCEE_SCOPEMISMATCH,
    SCEE_CASESENINDEX,SCEE_INDEXNOTCOMPLETE
  } SearchCommandExecuteErrors;

  typedef enum OfflineFolderStatus {
    OFS_INACTIVE = -1,OFS_ONLINE = 0,
    OFS_OFFLINE,OFS_SERVERBACK,OFS_DIRTYCACHE
  } OfflineFolderStatus;

  typedef enum ShellFolderViewOptions {
    SFVVO_SHOWALLOBJECTS = 0x1,SFVVO_SHOWEXTENSIONS = 0x2,SFVVO_SHOWCOMPCOLOR = 0x8,
    SFVVO_SHOWSYSFILES = 0x20,SFVVO_WIN95CLASSIC = 0x40,SFVVO_DOUBLECLICKINWEBVIEW = 0x80,
    SFVVO_DESKTOPHTML = 0x200
  } ShellFolderViewOptions;

  typedef enum ShellSpecialFolderConstants {
    ssfDESKTOP = 0,ssfPROGRAMS = 0x2,ssfCONTROLS = 0x3,ssfPRINTERS = 0x4,ssfPERSONAL = 0x5,ssfFAVORITES = 0x6,ssfSTARTUP = 0x7,ssfRECENT = 0x8,
    ssfSENDTO = 0x9,ssfBITBUCKET = 0xa,ssfSTARTMENU = 0xb,ssfDESKTOPDIRECTORY = 0x10,ssfDRIVES = 0x11,ssfNETWORK = 0x12,ssfNETHOOD = 0x13,
    ssfFONTS = 0x14,ssfTEMPLATES = 0x15,ssfCOMMONSTARTMENU = 0x16,ssfCOMMONPROGRAMS = 0x17,ssfCOMMONSTARTUP = 0x18,ssfCOMMONDESKTOPDIR = 0x19,
    ssfAPPDATA = 0x1a,ssfPRINTHOOD = 0x1b,ssfLOCALAPPDATA = 0x1c,ssfALTSTARTUP = 0x1d,ssfCOMMONALTSTARTUP = 0x1e,ssfCOMMONFAVORITES = 0x1f,
    ssfINTERNETCACHE = 0x20,ssfCOOKIES = 0x21,ssfHISTORY = 0x22,ssfCOMMONAPPDATA = 0x23,ssfWINDOWS = 0x24,ssfSYSTEM = 0x25,ssfPROGRAMFILES = 0x26,
    ssfMYPICTURES = 0x27,ssfPROFILE = 0x28,ssfSYSTEMx86 = 0x29,ssfPROGRAMFILESx86 = 0x30
  } ShellSpecialFolderConstants;

  EXTERN_C const IID LIBID_Shell32;
#ifndef __IFolderViewOC_INTERFACE_DEFINED__
#define __IFolderViewOC_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFolderViewOC;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFolderViewOC : public IDispatch {
  public:
    virtual HRESULT WINAPI SetFolderView(IDispatch *pdisp) = 0;
  };
#else
  typedef struct IFolderViewOCVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFolderViewOC *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFolderViewOC *This);
      ULONG (WINAPI *Release)(IFolderViewOC *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IFolderViewOC *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IFolderViewOC *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IFolderViewOC *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IFolderViewOC *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *SetFolderView)(IFolderViewOC *This,IDispatch *pdisp);
    END_INTERFACE
  } IFolderViewOCVtbl;
  struct IFolderViewOC {
    CONST_VTBL struct IFolderViewOCVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFolderViewOC_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFolderViewOC_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFolderViewOC_Release(This) (This)->lpVtbl->Release(This)
#define IFolderViewOC_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFolderViewOC_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFolderViewOC_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFolderViewOC_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFolderViewOC_SetFolderView(This,pdisp) (This)->lpVtbl->SetFolderView(This,pdisp)
#endif
#endif
  HRESULT WINAPI IFolderViewOC_SetFolderView_Proxy(IFolderViewOC *This,IDispatch *pdisp);
  void __RPC_STUB IFolderViewOC_SetFolderView_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __DShellFolderViewEvents_DISPINTERFACE_DEFINED__
#define __DShellFolderViewEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DShellFolderViewEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DShellFolderViewEvents : public IDispatch {
  };
#else
  typedef struct DShellFolderViewEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DShellFolderViewEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DShellFolderViewEvents *This);
      ULONG (WINAPI *Release)(DShellFolderViewEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DShellFolderViewEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DShellFolderViewEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DShellFolderViewEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DShellFolderViewEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DShellFolderViewEventsVtbl;
  struct DShellFolderViewEvents {
    CONST_VTBL struct DShellFolderViewEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DShellFolderViewEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DShellFolderViewEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DShellFolderViewEvents_Release(This) (This)->lpVtbl->Release(This)
#define DShellFolderViewEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DShellFolderViewEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DShellFolderViewEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DShellFolderViewEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

  EXTERN_C const CLSID CLSID_ShellFolderViewOC;
#ifdef __cplusplus
  class ShellFolderViewOC;
#endif

#ifndef __DFConstraint_INTERFACE_DEFINED__
#define __DFConstraint_INTERFACE_DEFINED__
  EXTERN_C const IID IID_DFConstraint;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DFConstraint : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbs) = 0;
    virtual HRESULT WINAPI get_Value(VARIANT *pv) = 0;
  };
#else
  typedef struct DFConstraintVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DFConstraint *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DFConstraint *This);
      ULONG (WINAPI *Release)(DFConstraint *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DFConstraint *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DFConstraint *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DFConstraint *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DFConstraint *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(DFConstraint *This,BSTR *pbs);
      HRESULT (WINAPI *get_Value)(DFConstraint *This,VARIANT *pv);
    END_INTERFACE
  } DFConstraintVtbl;
  struct DFConstraint {
    CONST_VTBL struct DFConstraintVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DFConstraint_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DFConstraint_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DFConstraint_Release(This) (This)->lpVtbl->Release(This)
#define DFConstraint_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DFConstraint_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DFConstraint_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DFConstraint_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define DFConstraint_get_Name(This,pbs) (This)->lpVtbl->get_Name(This,pbs)
#define DFConstraint_get_Value(This,pv) (This)->lpVtbl->get_Value(This,pv)
#endif
#endif
  HRESULT WINAPI DFConstraint_get_Name_Proxy(DFConstraint *This,BSTR *pbs);
  void __RPC_STUB DFConstraint_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI DFConstraint_get_Value_Proxy(DFConstraint *This,VARIANT *pv);
  void __RPC_STUB DFConstraint_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ISearchCommandExt_INTERFACE_DEFINED__
#define __ISearchCommandExt_INTERFACE_DEFINED__
  typedef enum __MIDL_ISearchCommandExt_0001 {
    SCE_SEARCHFORFILES = 0,SCE_SEARCHFORCOMPUTERS = 1
  } SEARCH_FOR_TYPE;

  EXTERN_C const IID IID_ISearchCommandExt;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ISearchCommandExt : public IDispatch {
  public:
    virtual HRESULT WINAPI ClearResults(void) = 0;
    virtual HRESULT WINAPI NavigateToSearchResults(void) = 0;
    virtual HRESULT WINAPI get_ProgressText(BSTR *pbs) = 0;
    virtual HRESULT WINAPI SaveSearch(void) = 0;
    virtual HRESULT WINAPI GetErrorInfo(BSTR *pbs,int *phr) = 0;
    virtual HRESULT WINAPI SearchFor(int iFor) = 0;
    virtual HRESULT WINAPI GetScopeInfo(BSTR bsScope,int *pdwScopeInfo) = 0;
    virtual HRESULT WINAPI RestoreSavedSearch(VARIANT *pvarFile) = 0;
    virtual HRESULT WINAPI Execute(VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options) = 0;
    virtual HRESULT WINAPI AddConstraint(BSTR Name,VARIANT Value) = 0;
    virtual HRESULT WINAPI GetNextConstraint(VARIANT_BOOL fReset,DFConstraint **ppdfc) = 0;
  };
#else
  typedef struct ISearchCommandExtVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ISearchCommandExt *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ISearchCommandExt *This);
      ULONG (WINAPI *Release)(ISearchCommandExt *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ISearchCommandExt *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ISearchCommandExt *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ISearchCommandExt *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ISearchCommandExt *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *ClearResults)(ISearchCommandExt *This);
      HRESULT (WINAPI *NavigateToSearchResults)(ISearchCommandExt *This);
      HRESULT (WINAPI *get_ProgressText)(ISearchCommandExt *This,BSTR *pbs);
      HRESULT (WINAPI *SaveSearch)(ISearchCommandExt *This);
      HRESULT (WINAPI *GetErrorInfo)(ISearchCommandExt *This,BSTR *pbs,int *phr);
      HRESULT (WINAPI *SearchFor)(ISearchCommandExt *This,int iFor);
      HRESULT (WINAPI *GetScopeInfo)(ISearchCommandExt *This,BSTR bsScope,int *pdwScopeInfo);
      HRESULT (WINAPI *RestoreSavedSearch)(ISearchCommandExt *This,VARIANT *pvarFile);
      HRESULT (WINAPI *Execute)(ISearchCommandExt *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options);
      HRESULT (WINAPI *AddConstraint)(ISearchCommandExt *This,BSTR Name,VARIANT Value);
      HRESULT (WINAPI *GetNextConstraint)(ISearchCommandExt *This,VARIANT_BOOL fReset,DFConstraint **ppdfc);
    END_INTERFACE
  } ISearchCommandExtVtbl;
  struct ISearchCommandExt {
    CONST_VTBL struct ISearchCommandExtVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ISearchCommandExt_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ISearchCommandExt_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ISearchCommandExt_Release(This) (This)->lpVtbl->Release(This)
#define ISearchCommandExt_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define ISearchCommandExt_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ISearchCommandExt_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ISearchCommandExt_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ISearchCommandExt_ClearResults(This) (This)->lpVtbl->ClearResults(This)
#define ISearchCommandExt_NavigateToSearchResults(This) (This)->lpVtbl->NavigateToSearchResults(This)
#define ISearchCommandExt_get_ProgressText(This,pbs) (This)->lpVtbl->get_ProgressText(This,pbs)
#define ISearchCommandExt_SaveSearch(This) (This)->lpVtbl->SaveSearch(This)
#define ISearchCommandExt_GetErrorInfo(This,pbs,phr) (This)->lpVtbl->GetErrorInfo(This,pbs,phr)
#define ISearchCommandExt_SearchFor(This,iFor) (This)->lpVtbl->SearchFor(This,iFor)
#define ISearchCommandExt_GetScopeInfo(This,bsScope,pdwScopeInfo) (This)->lpVtbl->GetScopeInfo(This,bsScope,pdwScopeInfo)
#define ISearchCommandExt_RestoreSavedSearch(This,pvarFile) (This)->lpVtbl->RestoreSavedSearch(This,pvarFile)
#define ISearchCommandExt_Execute(This,RecordsAffected,Parameters,Options) (This)->lpVtbl->Execute(This,RecordsAffected,Parameters,Options)
#define ISearchCommandExt_AddConstraint(This,Name,Value) (This)->lpVtbl->AddConstraint(This,Name,Value)
#define ISearchCommandExt_GetNextConstraint(This,fReset,ppdfc) (This)->lpVtbl->GetNextConstraint(This,fReset,ppdfc)
#endif
#endif
  HRESULT WINAPI ISearchCommandExt_ClearResults_Proxy(ISearchCommandExt *This);
  void __RPC_STUB ISearchCommandExt_ClearResults_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_NavigateToSearchResults_Proxy(ISearchCommandExt *This);
  void __RPC_STUB ISearchCommandExt_NavigateToSearchResults_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_get_ProgressText_Proxy(ISearchCommandExt *This,BSTR *pbs);
  void __RPC_STUB ISearchCommandExt_get_ProgressText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_SaveSearch_Proxy(ISearchCommandExt *This);
  void __RPC_STUB ISearchCommandExt_SaveSearch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_GetErrorInfo_Proxy(ISearchCommandExt *This,BSTR *pbs,int *phr);
  void __RPC_STUB ISearchCommandExt_GetErrorInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_SearchFor_Proxy(ISearchCommandExt *This,int iFor);
  void __RPC_STUB ISearchCommandExt_SearchFor_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_GetScopeInfo_Proxy(ISearchCommandExt *This,BSTR bsScope,int *pdwScopeInfo);
  void __RPC_STUB ISearchCommandExt_GetScopeInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_RestoreSavedSearch_Proxy(ISearchCommandExt *This,VARIANT *pvarFile);
  void __RPC_STUB ISearchCommandExt_RestoreSavedSearch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_Execute_Proxy(ISearchCommandExt *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options);
  void __RPC_STUB ISearchCommandExt_Execute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_AddConstraint_Proxy(ISearchCommandExt *This,BSTR Name,VARIANT Value);
  void __RPC_STUB ISearchCommandExt_AddConstraint_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ISearchCommandExt_GetNextConstraint_Proxy(ISearchCommandExt *This,VARIANT_BOOL fReset,DFConstraint **ppdfc);
  void __RPC_STUB ISearchCommandExt_GetNextConstraint_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItem_INTERFACE_DEFINED__
#define __FolderItem_INTERFACE_DEFINED__
  typedef FolderItem *LPFOLDERITEM;

  EXTERN_C const IID IID_FolderItem;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItem : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbs) = 0;
    virtual HRESULT WINAPI put_Name(BSTR bs) = 0;
    virtual HRESULT WINAPI get_Path(BSTR *pbs) = 0;
    virtual HRESULT WINAPI get_GetLink(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_GetFolder(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_IsLink(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_IsFolder(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_IsFileSystem(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_IsBrowsable(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_ModifyDate(DATE *pdt) = 0;
    virtual HRESULT WINAPI put_ModifyDate(DATE dt) = 0;
    virtual HRESULT WINAPI get_Size(LONG *pul) = 0;
    virtual HRESULT WINAPI get_Type(BSTR *pbs) = 0;
    virtual HRESULT WINAPI Verbs(FolderItemVerbs **ppfic) = 0;
    virtual HRESULT WINAPI InvokeVerb(VARIANT vVerb) = 0;
  };
#else
  typedef struct FolderItemVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItem *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItem *This);
      ULONG (WINAPI *Release)(FolderItem *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItem *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItem *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItem *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItem *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(FolderItem *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItem *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Name)(FolderItem *This,BSTR *pbs);
      HRESULT (WINAPI *put_Name)(FolderItem *This,BSTR bs);
      HRESULT (WINAPI *get_Path)(FolderItem *This,BSTR *pbs);
      HRESULT (WINAPI *get_GetLink)(FolderItem *This,IDispatch **ppid);
      HRESULT (WINAPI *get_GetFolder)(FolderItem *This,IDispatch **ppid);
      HRESULT (WINAPI *get_IsLink)(FolderItem *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsFolder)(FolderItem *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsFileSystem)(FolderItem *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsBrowsable)(FolderItem *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_ModifyDate)(FolderItem *This,DATE *pdt);
      HRESULT (WINAPI *put_ModifyDate)(FolderItem *This,DATE dt);
      HRESULT (WINAPI *get_Size)(FolderItem *This,LONG *pul);
      HRESULT (WINAPI *get_Type)(FolderItem *This,BSTR *pbs);
      HRESULT (WINAPI *Verbs)(FolderItem *This,FolderItemVerbs **ppfic);
      HRESULT (WINAPI *InvokeVerb)(FolderItem *This,VARIANT vVerb);
    END_INTERFACE
  } FolderItemVtbl;
  struct FolderItem {
    CONST_VTBL struct FolderItemVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItem_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItem_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItem_Release(This) (This)->lpVtbl->Release(This)
#define FolderItem_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItem_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItem_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItem_get_Name(This,pbs) (This)->lpVtbl->get_Name(This,pbs)
#define FolderItem_put_Name(This,bs) (This)->lpVtbl->put_Name(This,bs)
#define FolderItem_get_Path(This,pbs) (This)->lpVtbl->get_Path(This,pbs)
#define FolderItem_get_GetLink(This,ppid) (This)->lpVtbl->get_GetLink(This,ppid)
#define FolderItem_get_GetFolder(This,ppid) (This)->lpVtbl->get_GetFolder(This,ppid)
#define FolderItem_get_IsLink(This,pb) (This)->lpVtbl->get_IsLink(This,pb)
#define FolderItem_get_IsFolder(This,pb) (This)->lpVtbl->get_IsFolder(This,pb)
#define FolderItem_get_IsFileSystem(This,pb) (This)->lpVtbl->get_IsFileSystem(This,pb)
#define FolderItem_get_IsBrowsable(This,pb) (This)->lpVtbl->get_IsBrowsable(This,pb)
#define FolderItem_get_ModifyDate(This,pdt) (This)->lpVtbl->get_ModifyDate(This,pdt)
#define FolderItem_put_ModifyDate(This,dt) (This)->lpVtbl->put_ModifyDate(This,dt)
#define FolderItem_get_Size(This,pul) (This)->lpVtbl->get_Size(This,pul)
#define FolderItem_get_Type(This,pbs) (This)->lpVtbl->get_Type(This,pbs)
#define FolderItem_Verbs(This,ppfic) (This)->lpVtbl->Verbs(This,ppfic)
#define FolderItem_InvokeVerb(This,vVerb) (This)->lpVtbl->InvokeVerb(This,vVerb)
#endif
#endif
  HRESULT WINAPI FolderItem_get_Application_Proxy(FolderItem *This,IDispatch **ppid);
  void __RPC_STUB FolderItem_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_Parent_Proxy(FolderItem *This,IDispatch **ppid);
  void __RPC_STUB FolderItem_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_Name_Proxy(FolderItem *This,BSTR *pbs);
  void __RPC_STUB FolderItem_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_put_Name_Proxy(FolderItem *This,BSTR bs);
  void __RPC_STUB FolderItem_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_Path_Proxy(FolderItem *This,BSTR *pbs);
  void __RPC_STUB FolderItem_get_Path_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_GetLink_Proxy(FolderItem *This,IDispatch **ppid);
  void __RPC_STUB FolderItem_get_GetLink_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_GetFolder_Proxy(FolderItem *This,IDispatch **ppid);
  void __RPC_STUB FolderItem_get_GetFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_IsLink_Proxy(FolderItem *This,VARIANT_BOOL *pb);
  void __RPC_STUB FolderItem_get_IsLink_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_IsFolder_Proxy(FolderItem *This,VARIANT_BOOL *pb);
  void __RPC_STUB FolderItem_get_IsFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_IsFileSystem_Proxy(FolderItem *This,VARIANT_BOOL *pb);
  void __RPC_STUB FolderItem_get_IsFileSystem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_IsBrowsable_Proxy(FolderItem *This,VARIANT_BOOL *pb);
  void __RPC_STUB FolderItem_get_IsBrowsable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_ModifyDate_Proxy(FolderItem *This,DATE *pdt);
  void __RPC_STUB FolderItem_get_ModifyDate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_put_ModifyDate_Proxy(FolderItem *This,DATE dt);
  void __RPC_STUB FolderItem_put_ModifyDate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_Size_Proxy(FolderItem *This,LONG *pul);
  void __RPC_STUB FolderItem_get_Size_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_get_Type_Proxy(FolderItem *This,BSTR *pbs);
  void __RPC_STUB FolderItem_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_Verbs_Proxy(FolderItem *This,FolderItemVerbs **ppfic);
  void __RPC_STUB FolderItem_Verbs_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem_InvokeVerb_Proxy(FolderItem *This,VARIANT vVerb);
  void __RPC_STUB FolderItem_InvokeVerb_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItems_INTERFACE_DEFINED__
#define __FolderItems_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItems;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItems : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(__LONG32 *plCount) = 0;
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI Item(VARIANT index,FolderItem **ppid) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppunk) = 0;
  };
#else
  typedef struct FolderItemsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItems *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItems *This);
      ULONG (WINAPI *Release)(FolderItems *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItems *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItems *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItems *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItems *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(FolderItems *This,__LONG32 *plCount);
      HRESULT (WINAPI *get_Application)(FolderItems *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItems *This,IDispatch **ppid);
      HRESULT (WINAPI *Item)(FolderItems *This,VARIANT index,FolderItem **ppid);
      HRESULT (WINAPI *_NewEnum)(FolderItems *This,IUnknown **ppunk);
    END_INTERFACE
  } FolderItemsVtbl;
  struct FolderItems {
    CONST_VTBL struct FolderItemsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItems_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItems_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItems_Release(This) (This)->lpVtbl->Release(This)
#define FolderItems_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItems_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItems_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItems_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItems_get_Count(This,plCount) (This)->lpVtbl->get_Count(This,plCount)
#define FolderItems_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItems_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItems_Item(This,index,ppid) (This)->lpVtbl->Item(This,index,ppid)
#define FolderItems__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#endif
#endif
  HRESULT WINAPI FolderItems_get_Count_Proxy(FolderItems *This,__LONG32 *plCount);
  void __RPC_STUB FolderItems_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItems_get_Application_Proxy(FolderItems *This,IDispatch **ppid);
  void __RPC_STUB FolderItems_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItems_get_Parent_Proxy(FolderItems *This,IDispatch **ppid);
  void __RPC_STUB FolderItems_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItems_Item_Proxy(FolderItems *This,VARIANT index,FolderItem **ppid);
  void __RPC_STUB FolderItems_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItems__NewEnum_Proxy(FolderItems *This,IUnknown **ppunk);
  void __RPC_STUB FolderItems__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItemVerb_INTERFACE_DEFINED__
#define __FolderItemVerb_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItemVerb;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItemVerb : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbs) = 0;
    virtual HRESULT WINAPI DoIt(void) = 0;
  };
#else
  typedef struct FolderItemVerbVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItemVerb *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItemVerb *This);
      ULONG (WINAPI *Release)(FolderItemVerb *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItemVerb *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItemVerb *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItemVerb *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItemVerb *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(FolderItemVerb *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItemVerb *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Name)(FolderItemVerb *This,BSTR *pbs);
      HRESULT (WINAPI *DoIt)(FolderItemVerb *This);
    END_INTERFACE
  } FolderItemVerbVtbl;
  struct FolderItemVerb {
    CONST_VTBL struct FolderItemVerbVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItemVerb_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItemVerb_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItemVerb_Release(This) (This)->lpVtbl->Release(This)
#define FolderItemVerb_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItemVerb_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItemVerb_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItemVerb_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItemVerb_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItemVerb_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItemVerb_get_Name(This,pbs) (This)->lpVtbl->get_Name(This,pbs)
#define FolderItemVerb_DoIt(This) (This)->lpVtbl->DoIt(This)
#endif
#endif
  HRESULT WINAPI FolderItemVerb_get_Application_Proxy(FolderItemVerb *This,IDispatch **ppid);
  void __RPC_STUB FolderItemVerb_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerb_get_Parent_Proxy(FolderItemVerb *This,IDispatch **ppid);
  void __RPC_STUB FolderItemVerb_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerb_get_Name_Proxy(FolderItemVerb *This,BSTR *pbs);
  void __RPC_STUB FolderItemVerb_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerb_DoIt_Proxy(FolderItemVerb *This);
  void __RPC_STUB FolderItemVerb_DoIt_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItemVerbs_INTERFACE_DEFINED__
#define __FolderItemVerbs_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItemVerbs;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItemVerbs : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(__LONG32 *plCount) = 0;
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI Item(VARIANT index,FolderItemVerb **ppid) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppunk) = 0;
  };
#else
  typedef struct FolderItemVerbsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItemVerbs *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItemVerbs *This);
      ULONG (WINAPI *Release)(FolderItemVerbs *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItemVerbs *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItemVerbs *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItemVerbs *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItemVerbs *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(FolderItemVerbs *This,__LONG32 *plCount);
      HRESULT (WINAPI *get_Application)(FolderItemVerbs *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItemVerbs *This,IDispatch **ppid);
      HRESULT (WINAPI *Item)(FolderItemVerbs *This,VARIANT index,FolderItemVerb **ppid);
      HRESULT (WINAPI *_NewEnum)(FolderItemVerbs *This,IUnknown **ppunk);
    END_INTERFACE
  } FolderItemVerbsVtbl;
  struct FolderItemVerbs {
    CONST_VTBL struct FolderItemVerbsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItemVerbs_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItemVerbs_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItemVerbs_Release(This) (This)->lpVtbl->Release(This)
#define FolderItemVerbs_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItemVerbs_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItemVerbs_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItemVerbs_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItemVerbs_get_Count(This,plCount) (This)->lpVtbl->get_Count(This,plCount)
#define FolderItemVerbs_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItemVerbs_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItemVerbs_Item(This,index,ppid) (This)->lpVtbl->Item(This,index,ppid)
#define FolderItemVerbs__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#endif
#endif
  HRESULT WINAPI FolderItemVerbs_get_Count_Proxy(FolderItemVerbs *This,__LONG32 *plCount);
  void __RPC_STUB FolderItemVerbs_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerbs_get_Application_Proxy(FolderItemVerbs *This,IDispatch **ppid);
  void __RPC_STUB FolderItemVerbs_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerbs_get_Parent_Proxy(FolderItemVerbs *This,IDispatch **ppid);
  void __RPC_STUB FolderItemVerbs_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerbs_Item_Proxy(FolderItemVerbs *This,VARIANT index,FolderItemVerb **ppid);
  void __RPC_STUB FolderItemVerbs_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItemVerbs__NewEnum_Proxy(FolderItemVerbs *This,IUnknown **ppunk);
  void __RPC_STUB FolderItemVerbs__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Folder_INTERFACE_DEFINED__
#define __Folder_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Folder;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Folder : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Title(BSTR *pbs) = 0;
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_ParentFolder(Folder **ppsf) = 0;
    virtual HRESULT WINAPI Items(FolderItems **ppid) = 0;
    virtual HRESULT WINAPI ParseName(BSTR bName,FolderItem **ppid) = 0;
    virtual HRESULT WINAPI NewFolder(BSTR bName,VARIANT vOptions) = 0;
    virtual HRESULT WINAPI MoveHere(VARIANT vItem,VARIANT vOptions) = 0;
    virtual HRESULT WINAPI CopyHere(VARIANT vItem,VARIANT vOptions) = 0;
    virtual HRESULT WINAPI GetDetailsOf(VARIANT vItem,int iColumn,BSTR *pbs) = 0;
  };
#else
  typedef struct FolderVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Folder *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Folder *This);
      ULONG (WINAPI *Release)(Folder *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Folder *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Folder *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Folder *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Folder *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Title)(Folder *This,BSTR *pbs);
      HRESULT (WINAPI *get_Application)(Folder *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(Folder *This,IDispatch **ppid);
      HRESULT (WINAPI *get_ParentFolder)(Folder *This,Folder **ppsf);
      HRESULT (WINAPI *Items)(Folder *This,FolderItems **ppid);
      HRESULT (WINAPI *ParseName)(Folder *This,BSTR bName,FolderItem **ppid);
      HRESULT (WINAPI *NewFolder)(Folder *This,BSTR bName,VARIANT vOptions);
      HRESULT (WINAPI *MoveHere)(Folder *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *CopyHere)(Folder *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *GetDetailsOf)(Folder *This,VARIANT vItem,int iColumn,BSTR *pbs);
    END_INTERFACE
  } FolderVtbl;
  struct Folder {
    CONST_VTBL struct FolderVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Folder_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Folder_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Folder_Release(This) (This)->lpVtbl->Release(This)
#define Folder_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Folder_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Folder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Folder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Folder_get_Title(This,pbs) (This)->lpVtbl->get_Title(This,pbs)
#define Folder_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define Folder_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define Folder_get_ParentFolder(This,ppsf) (This)->lpVtbl->get_ParentFolder(This,ppsf)
#define Folder_Items(This,ppid) (This)->lpVtbl->Items(This,ppid)
#define Folder_ParseName(This,bName,ppid) (This)->lpVtbl->ParseName(This,bName,ppid)
#define Folder_NewFolder(This,bName,vOptions) (This)->lpVtbl->NewFolder(This,bName,vOptions)
#define Folder_MoveHere(This,vItem,vOptions) (This)->lpVtbl->MoveHere(This,vItem,vOptions)
#define Folder_CopyHere(This,vItem,vOptions) (This)->lpVtbl->CopyHere(This,vItem,vOptions)
#define Folder_GetDetailsOf(This,vItem,iColumn,pbs) (This)->lpVtbl->GetDetailsOf(This,vItem,iColumn,pbs)
#endif
#endif
  HRESULT WINAPI Folder_get_Title_Proxy(Folder *This,BSTR *pbs);
  void __RPC_STUB Folder_get_Title_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_get_Application_Proxy(Folder *This,IDispatch **ppid);
  void __RPC_STUB Folder_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_get_Parent_Proxy(Folder *This,IDispatch **ppid);
  void __RPC_STUB Folder_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_get_ParentFolder_Proxy(Folder *This,Folder **ppsf);
  void __RPC_STUB Folder_get_ParentFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_Items_Proxy(Folder *This,FolderItems **ppid);
  void __RPC_STUB Folder_Items_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_ParseName_Proxy(Folder *This,BSTR bName,FolderItem **ppid);
  void __RPC_STUB Folder_ParseName_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_NewFolder_Proxy(Folder *This,BSTR bName,VARIANT vOptions);
  void __RPC_STUB Folder_NewFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_MoveHere_Proxy(Folder *This,VARIANT vItem,VARIANT vOptions);
  void __RPC_STUB Folder_MoveHere_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_CopyHere_Proxy(Folder *This,VARIANT vItem,VARIANT vOptions);
  void __RPC_STUB Folder_CopyHere_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder_GetDetailsOf_Proxy(Folder *This,VARIANT vItem,int iColumn,BSTR *pbs);
  void __RPC_STUB Folder_GetDetailsOf_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Folder2_INTERFACE_DEFINED__
#define __Folder2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Folder2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Folder2 : public Folder {
  public:
    virtual HRESULT WINAPI get_Self(FolderItem **ppfi) = 0;
    virtual HRESULT WINAPI get_OfflineStatus(LONG *pul) = 0;
    virtual HRESULT WINAPI Synchronize(void) = 0;
    virtual HRESULT WINAPI get_HaveToShowWebViewBarricade(VARIANT_BOOL *pbHaveToShowWebViewBarricade) = 0;
    virtual HRESULT WINAPI DismissedWebViewBarricade(void) = 0;
  };
#else
  typedef struct Folder2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Folder2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Folder2 *This);
      ULONG (WINAPI *Release)(Folder2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Folder2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Folder2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Folder2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Folder2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Title)(Folder2 *This,BSTR *pbs);
      HRESULT (WINAPI *get_Application)(Folder2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(Folder2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_ParentFolder)(Folder2 *This,Folder **ppsf);
      HRESULT (WINAPI *Items)(Folder2 *This,FolderItems **ppid);
      HRESULT (WINAPI *ParseName)(Folder2 *This,BSTR bName,FolderItem **ppid);
      HRESULT (WINAPI *NewFolder)(Folder2 *This,BSTR bName,VARIANT vOptions);
      HRESULT (WINAPI *MoveHere)(Folder2 *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *CopyHere)(Folder2 *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *GetDetailsOf)(Folder2 *This,VARIANT vItem,int iColumn,BSTR *pbs);
      HRESULT (WINAPI *get_Self)(Folder2 *This,FolderItem **ppfi);
      HRESULT (WINAPI *get_OfflineStatus)(Folder2 *This,LONG *pul);
      HRESULT (WINAPI *Synchronize)(Folder2 *This);
      HRESULT (WINAPI *get_HaveToShowWebViewBarricade)(Folder2 *This,VARIANT_BOOL *pbHaveToShowWebViewBarricade);
      HRESULT (WINAPI *DismissedWebViewBarricade)(Folder2 *This);
    END_INTERFACE
  } Folder2Vtbl;
  struct Folder2 {
    CONST_VTBL struct Folder2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Folder2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Folder2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Folder2_Release(This) (This)->lpVtbl->Release(This)
#define Folder2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Folder2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Folder2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Folder2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Folder2_get_Title(This,pbs) (This)->lpVtbl->get_Title(This,pbs)
#define Folder2_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define Folder2_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define Folder2_get_ParentFolder(This,ppsf) (This)->lpVtbl->get_ParentFolder(This,ppsf)
#define Folder2_Items(This,ppid) (This)->lpVtbl->Items(This,ppid)
#define Folder2_ParseName(This,bName,ppid) (This)->lpVtbl->ParseName(This,bName,ppid)
#define Folder2_NewFolder(This,bName,vOptions) (This)->lpVtbl->NewFolder(This,bName,vOptions)
#define Folder2_MoveHere(This,vItem,vOptions) (This)->lpVtbl->MoveHere(This,vItem,vOptions)
#define Folder2_CopyHere(This,vItem,vOptions) (This)->lpVtbl->CopyHere(This,vItem,vOptions)
#define Folder2_GetDetailsOf(This,vItem,iColumn,pbs) (This)->lpVtbl->GetDetailsOf(This,vItem,iColumn,pbs)
#define Folder2_get_Self(This,ppfi) (This)->lpVtbl->get_Self(This,ppfi)
#define Folder2_get_OfflineStatus(This,pul) (This)->lpVtbl->get_OfflineStatus(This,pul)
#define Folder2_Synchronize(This) (This)->lpVtbl->Synchronize(This)
#define Folder2_get_HaveToShowWebViewBarricade(This,pbHaveToShowWebViewBarricade) (This)->lpVtbl->get_HaveToShowWebViewBarricade(This,pbHaveToShowWebViewBarricade)
#define Folder2_DismissedWebViewBarricade(This) (This)->lpVtbl->DismissedWebViewBarricade(This)
#endif
#endif
  HRESULT WINAPI Folder2_get_Self_Proxy(Folder2 *This,FolderItem **ppfi);
  void __RPC_STUB Folder2_get_Self_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder2_get_OfflineStatus_Proxy(Folder2 *This,LONG *pul);
  void __RPC_STUB Folder2_get_OfflineStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder2_Synchronize_Proxy(Folder2 *This);
  void __RPC_STUB Folder2_Synchronize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder2_get_HaveToShowWebViewBarricade_Proxy(Folder2 *This,VARIANT_BOOL *pbHaveToShowWebViewBarricade);
  void __RPC_STUB Folder2_get_HaveToShowWebViewBarricade_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder2_DismissedWebViewBarricade_Proxy(Folder2 *This);
  void __RPC_STUB Folder2_DismissedWebViewBarricade_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Folder3_INTERFACE_DEFINED__
#define __Folder3_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Folder3;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Folder3 : public Folder2 {
  public:
    virtual HRESULT WINAPI get_ShowWebViewBarricade(VARIANT_BOOL *pbShowWebViewBarricade) = 0;
    virtual HRESULT WINAPI put_ShowWebViewBarricade(VARIANT_BOOL bShowWebViewBarricade) = 0;
  };
#else
  typedef struct Folder3Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Folder3 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Folder3 *This);
      ULONG (WINAPI *Release)(Folder3 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Folder3 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Folder3 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Folder3 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Folder3 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Title)(Folder3 *This,BSTR *pbs);
      HRESULT (WINAPI *get_Application)(Folder3 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(Folder3 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_ParentFolder)(Folder3 *This,Folder **ppsf);
      HRESULT (WINAPI *Items)(Folder3 *This,FolderItems **ppid);
      HRESULT (WINAPI *ParseName)(Folder3 *This,BSTR bName,FolderItem **ppid);
      HRESULT (WINAPI *NewFolder)(Folder3 *This,BSTR bName,VARIANT vOptions);
      HRESULT (WINAPI *MoveHere)(Folder3 *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *CopyHere)(Folder3 *This,VARIANT vItem,VARIANT vOptions);
      HRESULT (WINAPI *GetDetailsOf)(Folder3 *This,VARIANT vItem,int iColumn,BSTR *pbs);
      HRESULT (WINAPI *get_Self)(Folder3 *This,FolderItem **ppfi);
      HRESULT (WINAPI *get_OfflineStatus)(Folder3 *This,LONG *pul);
      HRESULT (WINAPI *Synchronize)(Folder3 *This);
      HRESULT (WINAPI *get_HaveToShowWebViewBarricade)(Folder3 *This,VARIANT_BOOL *pbHaveToShowWebViewBarricade);
      HRESULT (WINAPI *DismissedWebViewBarricade)(Folder3 *This);
      HRESULT (WINAPI *get_ShowWebViewBarricade)(Folder3 *This,VARIANT_BOOL *pbShowWebViewBarricade);
      HRESULT (WINAPI *put_ShowWebViewBarricade)(Folder3 *This,VARIANT_BOOL bShowWebViewBarricade);
    END_INTERFACE
  } Folder3Vtbl;
  struct Folder3 {
    CONST_VTBL struct Folder3Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Folder3_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Folder3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Folder3_Release(This) (This)->lpVtbl->Release(This)
#define Folder3_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Folder3_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Folder3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Folder3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Folder3_get_Title(This,pbs) (This)->lpVtbl->get_Title(This,pbs)
#define Folder3_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define Folder3_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define Folder3_get_ParentFolder(This,ppsf) (This)->lpVtbl->get_ParentFolder(This,ppsf)
#define Folder3_Items(This,ppid) (This)->lpVtbl->Items(This,ppid)
#define Folder3_ParseName(This,bName,ppid) (This)->lpVtbl->ParseName(This,bName,ppid)
#define Folder3_NewFolder(This,bName,vOptions) (This)->lpVtbl->NewFolder(This,bName,vOptions)
#define Folder3_MoveHere(This,vItem,vOptions) (This)->lpVtbl->MoveHere(This,vItem,vOptions)
#define Folder3_CopyHere(This,vItem,vOptions) (This)->lpVtbl->CopyHere(This,vItem,vOptions)
#define Folder3_GetDetailsOf(This,vItem,iColumn,pbs) (This)->lpVtbl->GetDetailsOf(This,vItem,iColumn,pbs)
#define Folder3_get_Self(This,ppfi) (This)->lpVtbl->get_Self(This,ppfi)
#define Folder3_get_OfflineStatus(This,pul) (This)->lpVtbl->get_OfflineStatus(This,pul)
#define Folder3_Synchronize(This) (This)->lpVtbl->Synchronize(This)
#define Folder3_get_HaveToShowWebViewBarricade(This,pbHaveToShowWebViewBarricade) (This)->lpVtbl->get_HaveToShowWebViewBarricade(This,pbHaveToShowWebViewBarricade)
#define Folder3_DismissedWebViewBarricade(This) (This)->lpVtbl->DismissedWebViewBarricade(This)
#define Folder3_get_ShowWebViewBarricade(This,pbShowWebViewBarricade) (This)->lpVtbl->get_ShowWebViewBarricade(This,pbShowWebViewBarricade)
#define Folder3_put_ShowWebViewBarricade(This,bShowWebViewBarricade) (This)->lpVtbl->put_ShowWebViewBarricade(This,bShowWebViewBarricade)
#endif
#endif
  HRESULT WINAPI Folder3_get_ShowWebViewBarricade_Proxy(Folder3 *This,VARIANT_BOOL *pbShowWebViewBarricade);
  void __RPC_STUB Folder3_get_ShowWebViewBarricade_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Folder3_put_ShowWebViewBarricade_Proxy(Folder3 *This,VARIANT_BOOL bShowWebViewBarricade);
  void __RPC_STUB Folder3_put_ShowWebViewBarricade_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItem2_INTERFACE_DEFINED__
#define __FolderItem2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItem2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItem2 : public FolderItem {
  public:
    virtual HRESULT WINAPI InvokeVerbEx(VARIANT vVerb,VARIANT vArgs) = 0;
    virtual HRESULT WINAPI ExtendedProperty(BSTR bstrPropName,VARIANT *pvRet) = 0;
  };
#else
  typedef struct FolderItem2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItem2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItem2 *This);
      ULONG (WINAPI *Release)(FolderItem2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItem2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItem2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItem2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItem2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(FolderItem2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItem2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Name)(FolderItem2 *This,BSTR *pbs);
      HRESULT (WINAPI *put_Name)(FolderItem2 *This,BSTR bs);
      HRESULT (WINAPI *get_Path)(FolderItem2 *This,BSTR *pbs);
      HRESULT (WINAPI *get_GetLink)(FolderItem2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_GetFolder)(FolderItem2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_IsLink)(FolderItem2 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsFolder)(FolderItem2 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsFileSystem)(FolderItem2 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_IsBrowsable)(FolderItem2 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_ModifyDate)(FolderItem2 *This,DATE *pdt);
      HRESULT (WINAPI *put_ModifyDate)(FolderItem2 *This,DATE dt);
      HRESULT (WINAPI *get_Size)(FolderItem2 *This,LONG *pul);
      HRESULT (WINAPI *get_Type)(FolderItem2 *This,BSTR *pbs);
      HRESULT (WINAPI *Verbs)(FolderItem2 *This,FolderItemVerbs **ppfic);
      HRESULT (WINAPI *InvokeVerb)(FolderItem2 *This,VARIANT vVerb);
      HRESULT (WINAPI *InvokeVerbEx)(FolderItem2 *This,VARIANT vVerb,VARIANT vArgs);
      HRESULT (WINAPI *ExtendedProperty)(FolderItem2 *This,BSTR bstrPropName,VARIANT *pvRet);
    END_INTERFACE
  } FolderItem2Vtbl;
  struct FolderItem2 {
    CONST_VTBL struct FolderItem2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItem2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItem2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItem2_Release(This) (This)->lpVtbl->Release(This)
#define FolderItem2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItem2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItem2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItem2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItem2_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItem2_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItem2_get_Name(This,pbs) (This)->lpVtbl->get_Name(This,pbs)
#define FolderItem2_put_Name(This,bs) (This)->lpVtbl->put_Name(This,bs)
#define FolderItem2_get_Path(This,pbs) (This)->lpVtbl->get_Path(This,pbs)
#define FolderItem2_get_GetLink(This,ppid) (This)->lpVtbl->get_GetLink(This,ppid)
#define FolderItem2_get_GetFolder(This,ppid) (This)->lpVtbl->get_GetFolder(This,ppid)
#define FolderItem2_get_IsLink(This,pb) (This)->lpVtbl->get_IsLink(This,pb)
#define FolderItem2_get_IsFolder(This,pb) (This)->lpVtbl->get_IsFolder(This,pb)
#define FolderItem2_get_IsFileSystem(This,pb) (This)->lpVtbl->get_IsFileSystem(This,pb)
#define FolderItem2_get_IsBrowsable(This,pb) (This)->lpVtbl->get_IsBrowsable(This,pb)
#define FolderItem2_get_ModifyDate(This,pdt) (This)->lpVtbl->get_ModifyDate(This,pdt)
#define FolderItem2_put_ModifyDate(This,dt) (This)->lpVtbl->put_ModifyDate(This,dt)
#define FolderItem2_get_Size(This,pul) (This)->lpVtbl->get_Size(This,pul)
#define FolderItem2_get_Type(This,pbs) (This)->lpVtbl->get_Type(This,pbs)
#define FolderItem2_Verbs(This,ppfic) (This)->lpVtbl->Verbs(This,ppfic)
#define FolderItem2_InvokeVerb(This,vVerb) (This)->lpVtbl->InvokeVerb(This,vVerb)
#define FolderItem2_InvokeVerbEx(This,vVerb,vArgs) (This)->lpVtbl->InvokeVerbEx(This,vVerb,vArgs)
#define FolderItem2_ExtendedProperty(This,bstrPropName,pvRet) (This)->lpVtbl->ExtendedProperty(This,bstrPropName,pvRet)
#endif
#endif
  HRESULT WINAPI FolderItem2_InvokeVerbEx_Proxy(FolderItem2 *This,VARIANT vVerb,VARIANT vArgs);
  void __RPC_STUB FolderItem2_InvokeVerbEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItem2_ExtendedProperty_Proxy(FolderItem2 *This,BSTR bstrPropName,VARIANT *pvRet);
  void __RPC_STUB FolderItem2_ExtendedProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellFolderItem;
#ifdef __cplusplus
  class ShellFolderItem;
#endif

#ifndef __FolderItems2_INTERFACE_DEFINED__
#define __FolderItems2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItems2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItems2 : public FolderItems {
  public:
    virtual HRESULT WINAPI InvokeVerbEx(VARIANT vVerb,VARIANT vArgs) = 0;
  };
#else
  typedef struct FolderItems2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItems2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItems2 *This);
      ULONG (WINAPI *Release)(FolderItems2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItems2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItems2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItems2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItems2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(FolderItems2 *This,__LONG32 *plCount);
      HRESULT (WINAPI *get_Application)(FolderItems2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItems2 *This,IDispatch **ppid);
      HRESULT (WINAPI *Item)(FolderItems2 *This,VARIANT index,FolderItem **ppid);
      HRESULT (WINAPI *_NewEnum)(FolderItems2 *This,IUnknown **ppunk);
      HRESULT (WINAPI *InvokeVerbEx)(FolderItems2 *This,VARIANT vVerb,VARIANT vArgs);
    END_INTERFACE
  } FolderItems2Vtbl;
  struct FolderItems2 {
    CONST_VTBL struct FolderItems2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItems2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItems2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItems2_Release(This) (This)->lpVtbl->Release(This)
#define FolderItems2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItems2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItems2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItems2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItems2_get_Count(This,plCount) (This)->lpVtbl->get_Count(This,plCount)
#define FolderItems2_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItems2_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItems2_Item(This,index,ppid) (This)->lpVtbl->Item(This,index,ppid)
#define FolderItems2__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#define FolderItems2_InvokeVerbEx(This,vVerb,vArgs) (This)->lpVtbl->InvokeVerbEx(This,vVerb,vArgs)
#endif
#endif
  HRESULT WINAPI FolderItems2_InvokeVerbEx_Proxy(FolderItems2 *This,VARIANT vVerb,VARIANT vArgs);
  void __RPC_STUB FolderItems2_InvokeVerbEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __FolderItems3_INTERFACE_DEFINED__
#define __FolderItems3_INTERFACE_DEFINED__
  EXTERN_C const IID IID_FolderItems3;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct FolderItems3 : public FolderItems2 {
  public:
    virtual HRESULT WINAPI Filter(__LONG32 grfFlags,BSTR bstrFileSpec) = 0;
    virtual HRESULT WINAPI get_Verbs(FolderItemVerbs **ppfic) = 0;
  };
#else
  typedef struct FolderItems3Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(FolderItems3 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(FolderItems3 *This);
      ULONG (WINAPI *Release)(FolderItems3 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(FolderItems3 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(FolderItems3 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(FolderItems3 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(FolderItems3 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(FolderItems3 *This,__LONG32 *plCount);
      HRESULT (WINAPI *get_Application)(FolderItems3 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(FolderItems3 *This,IDispatch **ppid);
      HRESULT (WINAPI *Item)(FolderItems3 *This,VARIANT index,FolderItem **ppid);
      HRESULT (WINAPI *_NewEnum)(FolderItems3 *This,IUnknown **ppunk);
      HRESULT (WINAPI *InvokeVerbEx)(FolderItems3 *This,VARIANT vVerb,VARIANT vArgs);
      HRESULT (WINAPI *Filter)(FolderItems3 *This,__LONG32 grfFlags,BSTR bstrFileSpec);
      HRESULT (WINAPI *get_Verbs)(FolderItems3 *This,FolderItemVerbs **ppfic);
    END_INTERFACE
  } FolderItems3Vtbl;
  struct FolderItems3 {
    CONST_VTBL struct FolderItems3Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define FolderItems3_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define FolderItems3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define FolderItems3_Release(This) (This)->lpVtbl->Release(This)
#define FolderItems3_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define FolderItems3_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define FolderItems3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define FolderItems3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define FolderItems3_get_Count(This,plCount) (This)->lpVtbl->get_Count(This,plCount)
#define FolderItems3_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define FolderItems3_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define FolderItems3_Item(This,index,ppid) (This)->lpVtbl->Item(This,index,ppid)
#define FolderItems3__NewEnum(This,ppunk) (This)->lpVtbl->_NewEnum(This,ppunk)
#define FolderItems3_InvokeVerbEx(This,vVerb,vArgs) (This)->lpVtbl->InvokeVerbEx(This,vVerb,vArgs)
#define FolderItems3_Filter(This,grfFlags,bstrFileSpec) (This)->lpVtbl->Filter(This,grfFlags,bstrFileSpec)
#define FolderItems3_get_Verbs(This,ppfic) (This)->lpVtbl->get_Verbs(This,ppfic)
#endif
#endif
  HRESULT WINAPI FolderItems3_Filter_Proxy(FolderItems3 *This,__LONG32 grfFlags,BSTR bstrFileSpec);
  void __RPC_STUB FolderItems3_Filter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI FolderItems3_get_Verbs_Proxy(FolderItems3 *This,FolderItemVerbs **ppfic);
  void __RPC_STUB FolderItems3_get_Verbs_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellLinkDual_INTERFACE_DEFINED__
#define __IShellLinkDual_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellLinkDual;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellLinkDual : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Path(BSTR *pbs) = 0;
    virtual HRESULT WINAPI put_Path(BSTR bs) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbs) = 0;
    virtual HRESULT WINAPI put_Description(BSTR bs) = 0;
    virtual HRESULT WINAPI get_WorkingDirectory(BSTR *pbs) = 0;
    virtual HRESULT WINAPI put_WorkingDirectory(BSTR bs) = 0;
    virtual HRESULT WINAPI get_Arguments(BSTR *pbs) = 0;
    virtual HRESULT WINAPI put_Arguments(BSTR bs) = 0;
    virtual HRESULT WINAPI get_Hotkey(int *piHK) = 0;
    virtual HRESULT WINAPI put_Hotkey(int iHK) = 0;
    virtual HRESULT WINAPI get_ShowCommand(int *piShowCommand) = 0;
    virtual HRESULT WINAPI put_ShowCommand(int iShowCommand) = 0;
    virtual HRESULT WINAPI Resolve(int fFlags) = 0;
    virtual HRESULT WINAPI GetIconLocation(BSTR *pbs,int *piIcon) = 0;
    virtual HRESULT WINAPI SetIconLocation(BSTR bs,int iIcon) = 0;
    virtual HRESULT WINAPI Save(VARIANT vWhere) = 0;
  };
#else
  typedef struct IShellLinkDualVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellLinkDual *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellLinkDual *This);
      ULONG (WINAPI *Release)(IShellLinkDual *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellLinkDual *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellLinkDual *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellLinkDual *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellLinkDual *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Path)(IShellLinkDual *This,BSTR *pbs);
      HRESULT (WINAPI *put_Path)(IShellLinkDual *This,BSTR bs);
      HRESULT (WINAPI *get_Description)(IShellLinkDual *This,BSTR *pbs);
      HRESULT (WINAPI *put_Description)(IShellLinkDual *This,BSTR bs);
      HRESULT (WINAPI *get_WorkingDirectory)(IShellLinkDual *This,BSTR *pbs);
      HRESULT (WINAPI *put_WorkingDirectory)(IShellLinkDual *This,BSTR bs);
      HRESULT (WINAPI *get_Arguments)(IShellLinkDual *This,BSTR *pbs);
      HRESULT (WINAPI *put_Arguments)(IShellLinkDual *This,BSTR bs);
      HRESULT (WINAPI *get_Hotkey)(IShellLinkDual *This,int *piHK);
      HRESULT (WINAPI *put_Hotkey)(IShellLinkDual *This,int iHK);
      HRESULT (WINAPI *get_ShowCommand)(IShellLinkDual *This,int *piShowCommand);
      HRESULT (WINAPI *put_ShowCommand)(IShellLinkDual *This,int iShowCommand);
      HRESULT (WINAPI *Resolve)(IShellLinkDual *This,int fFlags);
      HRESULT (WINAPI *GetIconLocation)(IShellLinkDual *This,BSTR *pbs,int *piIcon);
      HRESULT (WINAPI *SetIconLocation)(IShellLinkDual *This,BSTR bs,int iIcon);
      HRESULT (WINAPI *Save)(IShellLinkDual *This,VARIANT vWhere);
    END_INTERFACE
  } IShellLinkDualVtbl;
  struct IShellLinkDual {
    CONST_VTBL struct IShellLinkDualVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellLinkDual_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellLinkDual_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellLinkDual_Release(This) (This)->lpVtbl->Release(This)
#define IShellLinkDual_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellLinkDual_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellLinkDual_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellLinkDual_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellLinkDual_get_Path(This,pbs) (This)->lpVtbl->get_Path(This,pbs)
#define IShellLinkDual_put_Path(This,bs) (This)->lpVtbl->put_Path(This,bs)
#define IShellLinkDual_get_Description(This,pbs) (This)->lpVtbl->get_Description(This,pbs)
#define IShellLinkDual_put_Description(This,bs) (This)->lpVtbl->put_Description(This,bs)
#define IShellLinkDual_get_WorkingDirectory(This,pbs) (This)->lpVtbl->get_WorkingDirectory(This,pbs)
#define IShellLinkDual_put_WorkingDirectory(This,bs) (This)->lpVtbl->put_WorkingDirectory(This,bs)
#define IShellLinkDual_get_Arguments(This,pbs) (This)->lpVtbl->get_Arguments(This,pbs)
#define IShellLinkDual_put_Arguments(This,bs) (This)->lpVtbl->put_Arguments(This,bs)
#define IShellLinkDual_get_Hotkey(This,piHK) (This)->lpVtbl->get_Hotkey(This,piHK)
#define IShellLinkDual_put_Hotkey(This,iHK) (This)->lpVtbl->put_Hotkey(This,iHK)
#define IShellLinkDual_get_ShowCommand(This,piShowCommand) (This)->lpVtbl->get_ShowCommand(This,piShowCommand)
#define IShellLinkDual_put_ShowCommand(This,iShowCommand) (This)->lpVtbl->put_ShowCommand(This,iShowCommand)
#define IShellLinkDual_Resolve(This,fFlags) (This)->lpVtbl->Resolve(This,fFlags)
#define IShellLinkDual_GetIconLocation(This,pbs,piIcon) (This)->lpVtbl->GetIconLocation(This,pbs,piIcon)
#define IShellLinkDual_SetIconLocation(This,bs,iIcon) (This)->lpVtbl->SetIconLocation(This,bs,iIcon)
#define IShellLinkDual_Save(This,vWhere) (This)->lpVtbl->Save(This,vWhere)
#endif
#endif
  HRESULT WINAPI IShellLinkDual_get_Path_Proxy(IShellLinkDual *This,BSTR *pbs);
  void __RPC_STUB IShellLinkDual_get_Path_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_Path_Proxy(IShellLinkDual *This,BSTR bs);
  void __RPC_STUB IShellLinkDual_put_Path_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_get_Description_Proxy(IShellLinkDual *This,BSTR *pbs);
  void __RPC_STUB IShellLinkDual_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_Description_Proxy(IShellLinkDual *This,BSTR bs);
  void __RPC_STUB IShellLinkDual_put_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_get_WorkingDirectory_Proxy(IShellLinkDual *This,BSTR *pbs);
  void __RPC_STUB IShellLinkDual_get_WorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_WorkingDirectory_Proxy(IShellLinkDual *This,BSTR bs);
  void __RPC_STUB IShellLinkDual_put_WorkingDirectory_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_get_Arguments_Proxy(IShellLinkDual *This,BSTR *pbs);
  void __RPC_STUB IShellLinkDual_get_Arguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_Arguments_Proxy(IShellLinkDual *This,BSTR bs);
  void __RPC_STUB IShellLinkDual_put_Arguments_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_get_Hotkey_Proxy(IShellLinkDual *This,int *piHK);
  void __RPC_STUB IShellLinkDual_get_Hotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_Hotkey_Proxy(IShellLinkDual *This,int iHK);
  void __RPC_STUB IShellLinkDual_put_Hotkey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_get_ShowCommand_Proxy(IShellLinkDual *This,int *piShowCommand);
  void __RPC_STUB IShellLinkDual_get_ShowCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_put_ShowCommand_Proxy(IShellLinkDual *This,int iShowCommand);
  void __RPC_STUB IShellLinkDual_put_ShowCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_Resolve_Proxy(IShellLinkDual *This,int fFlags);
  void __RPC_STUB IShellLinkDual_Resolve_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_GetIconLocation_Proxy(IShellLinkDual *This,BSTR *pbs,int *piIcon);
  void __RPC_STUB IShellLinkDual_GetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_SetIconLocation_Proxy(IShellLinkDual *This,BSTR bs,int iIcon);
  void __RPC_STUB IShellLinkDual_SetIconLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellLinkDual_Save_Proxy(IShellLinkDual *This,VARIANT vWhere);
  void __RPC_STUB IShellLinkDual_Save_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellLinkDual2_INTERFACE_DEFINED__
#define __IShellLinkDual2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellLinkDual2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellLinkDual2 : public IShellLinkDual {
  public:
    virtual HRESULT WINAPI get_Target(FolderItem **ppfi) = 0;
  };
#else
  typedef struct IShellLinkDual2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellLinkDual2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellLinkDual2 *This);
      ULONG (WINAPI *Release)(IShellLinkDual2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellLinkDual2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellLinkDual2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellLinkDual2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellLinkDual2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Path)(IShellLinkDual2 *This,BSTR *pbs);
      HRESULT (WINAPI *put_Path)(IShellLinkDual2 *This,BSTR bs);
      HRESULT (WINAPI *get_Description)(IShellLinkDual2 *This,BSTR *pbs);
      HRESULT (WINAPI *put_Description)(IShellLinkDual2 *This,BSTR bs);
      HRESULT (WINAPI *get_WorkingDirectory)(IShellLinkDual2 *This,BSTR *pbs);
      HRESULT (WINAPI *put_WorkingDirectory)(IShellLinkDual2 *This,BSTR bs);
      HRESULT (WINAPI *get_Arguments)(IShellLinkDual2 *This,BSTR *pbs);
      HRESULT (WINAPI *put_Arguments)(IShellLinkDual2 *This,BSTR bs);
      HRESULT (WINAPI *get_Hotkey)(IShellLinkDual2 *This,int *piHK);
      HRESULT (WINAPI *put_Hotkey)(IShellLinkDual2 *This,int iHK);
      HRESULT (WINAPI *get_ShowCommand)(IShellLinkDual2 *This,int *piShowCommand);
      HRESULT (WINAPI *put_ShowCommand)(IShellLinkDual2 *This,int iShowCommand);
      HRESULT (WINAPI *Resolve)(IShellLinkDual2 *This,int fFlags);
      HRESULT (WINAPI *GetIconLocation)(IShellLinkDual2 *This,BSTR *pbs,int *piIcon);
      HRESULT (WINAPI *SetIconLocation)(IShellLinkDual2 *This,BSTR bs,int iIcon);
      HRESULT (WINAPI *Save)(IShellLinkDual2 *This,VARIANT vWhere);
      HRESULT (WINAPI *get_Target)(IShellLinkDual2 *This,FolderItem **ppfi);
    END_INTERFACE
  } IShellLinkDual2Vtbl;
  struct IShellLinkDual2 {
    CONST_VTBL struct IShellLinkDual2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellLinkDual2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellLinkDual2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellLinkDual2_Release(This) (This)->lpVtbl->Release(This)
#define IShellLinkDual2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellLinkDual2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellLinkDual2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellLinkDual2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellLinkDual2_get_Path(This,pbs) (This)->lpVtbl->get_Path(This,pbs)
#define IShellLinkDual2_put_Path(This,bs) (This)->lpVtbl->put_Path(This,bs)
#define IShellLinkDual2_get_Description(This,pbs) (This)->lpVtbl->get_Description(This,pbs)
#define IShellLinkDual2_put_Description(This,bs) (This)->lpVtbl->put_Description(This,bs)
#define IShellLinkDual2_get_WorkingDirectory(This,pbs) (This)->lpVtbl->get_WorkingDirectory(This,pbs)
#define IShellLinkDual2_put_WorkingDirectory(This,bs) (This)->lpVtbl->put_WorkingDirectory(This,bs)
#define IShellLinkDual2_get_Arguments(This,pbs) (This)->lpVtbl->get_Arguments(This,pbs)
#define IShellLinkDual2_put_Arguments(This,bs) (This)->lpVtbl->put_Arguments(This,bs)
#define IShellLinkDual2_get_Hotkey(This,piHK) (This)->lpVtbl->get_Hotkey(This,piHK)
#define IShellLinkDual2_put_Hotkey(This,iHK) (This)->lpVtbl->put_Hotkey(This,iHK)
#define IShellLinkDual2_get_ShowCommand(This,piShowCommand) (This)->lpVtbl->get_ShowCommand(This,piShowCommand)
#define IShellLinkDual2_put_ShowCommand(This,iShowCommand) (This)->lpVtbl->put_ShowCommand(This,iShowCommand)
#define IShellLinkDual2_Resolve(This,fFlags) (This)->lpVtbl->Resolve(This,fFlags)
#define IShellLinkDual2_GetIconLocation(This,pbs,piIcon) (This)->lpVtbl->GetIconLocation(This,pbs,piIcon)
#define IShellLinkDual2_SetIconLocation(This,bs,iIcon) (This)->lpVtbl->SetIconLocation(This,bs,iIcon)
#define IShellLinkDual2_Save(This,vWhere) (This)->lpVtbl->Save(This,vWhere)
#define IShellLinkDual2_get_Target(This,ppfi) (This)->lpVtbl->get_Target(This,ppfi)
#endif
#endif
  HRESULT WINAPI IShellLinkDual2_get_Target_Proxy(IShellLinkDual2 *This,FolderItem **ppfi);
  void __RPC_STUB IShellLinkDual2_get_Target_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellLinkObject;
#ifdef __cplusplus
  class ShellLinkObject;
#endif

#ifndef __IShellFolderViewDual_INTERFACE_DEFINED__
#define __IShellFolderViewDual_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellFolderViewDual;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellFolderViewDual : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Folder(Folder **ppid) = 0;
    virtual HRESULT WINAPI SelectedItems(FolderItems **ppid) = 0;
    virtual HRESULT WINAPI get_FocusedItem(FolderItem **ppid) = 0;
    virtual HRESULT WINAPI SelectItem(VARIANT *pvfi,int dwFlags) = 0;
    virtual HRESULT WINAPI PopupItemMenu(FolderItem *pfi,VARIANT vx,VARIANT vy,BSTR *pbs) = 0;
    virtual HRESULT WINAPI get_Script(IDispatch **ppDisp) = 0;
    virtual HRESULT WINAPI get_ViewOptions(__LONG32 *plViewOptions) = 0;
  };
#else
  typedef struct IShellFolderViewDualVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellFolderViewDual *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellFolderViewDual *This);
      ULONG (WINAPI *Release)(IShellFolderViewDual *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellFolderViewDual *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellFolderViewDual *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellFolderViewDual *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellFolderViewDual *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellFolderViewDual *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellFolderViewDual *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Folder)(IShellFolderViewDual *This,Folder **ppid);
      HRESULT (WINAPI *SelectedItems)(IShellFolderViewDual *This,FolderItems **ppid);
      HRESULT (WINAPI *get_FocusedItem)(IShellFolderViewDual *This,FolderItem **ppid);
      HRESULT (WINAPI *SelectItem)(IShellFolderViewDual *This,VARIANT *pvfi,int dwFlags);
      HRESULT (WINAPI *PopupItemMenu)(IShellFolderViewDual *This,FolderItem *pfi,VARIANT vx,VARIANT vy,BSTR *pbs);
      HRESULT (WINAPI *get_Script)(IShellFolderViewDual *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_ViewOptions)(IShellFolderViewDual *This,__LONG32 *plViewOptions);
    END_INTERFACE
  } IShellFolderViewDualVtbl;
  struct IShellFolderViewDual {
    CONST_VTBL struct IShellFolderViewDualVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellFolderViewDual_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellFolderViewDual_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellFolderViewDual_Release(This) (This)->lpVtbl->Release(This)
#define IShellFolderViewDual_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellFolderViewDual_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellFolderViewDual_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellFolderViewDual_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellFolderViewDual_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellFolderViewDual_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellFolderViewDual_get_Folder(This,ppid) (This)->lpVtbl->get_Folder(This,ppid)
#define IShellFolderViewDual_SelectedItems(This,ppid) (This)->lpVtbl->SelectedItems(This,ppid)
#define IShellFolderViewDual_get_FocusedItem(This,ppid) (This)->lpVtbl->get_FocusedItem(This,ppid)
#define IShellFolderViewDual_SelectItem(This,pvfi,dwFlags) (This)->lpVtbl->SelectItem(This,pvfi,dwFlags)
#define IShellFolderViewDual_PopupItemMenu(This,pfi,vx,vy,pbs) (This)->lpVtbl->PopupItemMenu(This,pfi,vx,vy,pbs)
#define IShellFolderViewDual_get_Script(This,ppDisp) (This)->lpVtbl->get_Script(This,ppDisp)
#define IShellFolderViewDual_get_ViewOptions(This,plViewOptions) (This)->lpVtbl->get_ViewOptions(This,plViewOptions)
#endif
#endif
  HRESULT WINAPI IShellFolderViewDual_get_Application_Proxy(IShellFolderViewDual *This,IDispatch **ppid);
  void __RPC_STUB IShellFolderViewDual_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_get_Parent_Proxy(IShellFolderViewDual *This,IDispatch **ppid);
  void __RPC_STUB IShellFolderViewDual_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_get_Folder_Proxy(IShellFolderViewDual *This,Folder **ppid);
  void __RPC_STUB IShellFolderViewDual_get_Folder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_SelectedItems_Proxy(IShellFolderViewDual *This,FolderItems **ppid);
  void __RPC_STUB IShellFolderViewDual_SelectedItems_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_get_FocusedItem_Proxy(IShellFolderViewDual *This,FolderItem **ppid);
  void __RPC_STUB IShellFolderViewDual_get_FocusedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_SelectItem_Proxy(IShellFolderViewDual *This,VARIANT *pvfi,int dwFlags);
  void __RPC_STUB IShellFolderViewDual_SelectItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_PopupItemMenu_Proxy(IShellFolderViewDual *This,FolderItem *pfi,VARIANT vx,VARIANT vy,BSTR *pbs);
  void __RPC_STUB IShellFolderViewDual_PopupItemMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_get_Script_Proxy(IShellFolderViewDual *This,IDispatch **ppDisp);
  void __RPC_STUB IShellFolderViewDual_get_Script_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual_get_ViewOptions_Proxy(IShellFolderViewDual *This,__LONG32 *plViewOptions);
  void __RPC_STUB IShellFolderViewDual_get_ViewOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellFolderViewDual2_INTERFACE_DEFINED__
#define __IShellFolderViewDual2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellFolderViewDual2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellFolderViewDual2 : public IShellFolderViewDual {
  public:
    virtual HRESULT WINAPI get_CurrentViewMode(UINT *pViewMode) = 0;
    virtual HRESULT WINAPI put_CurrentViewMode(UINT ViewMode) = 0;
    virtual HRESULT WINAPI SelectItemRelative(int iRelative) = 0;
  };
#else
  typedef struct IShellFolderViewDual2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellFolderViewDual2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellFolderViewDual2 *This);
      ULONG (WINAPI *Release)(IShellFolderViewDual2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellFolderViewDual2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellFolderViewDual2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellFolderViewDual2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellFolderViewDual2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellFolderViewDual2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellFolderViewDual2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Folder)(IShellFolderViewDual2 *This,Folder **ppid);
      HRESULT (WINAPI *SelectedItems)(IShellFolderViewDual2 *This,FolderItems **ppid);
      HRESULT (WINAPI *get_FocusedItem)(IShellFolderViewDual2 *This,FolderItem **ppid);
      HRESULT (WINAPI *SelectItem)(IShellFolderViewDual2 *This,VARIANT *pvfi,int dwFlags);
      HRESULT (WINAPI *PopupItemMenu)(IShellFolderViewDual2 *This,FolderItem *pfi,VARIANT vx,VARIANT vy,BSTR *pbs);
      HRESULT (WINAPI *get_Script)(IShellFolderViewDual2 *This,IDispatch **ppDisp);
      HRESULT (WINAPI *get_ViewOptions)(IShellFolderViewDual2 *This,__LONG32 *plViewOptions);
      HRESULT (WINAPI *get_CurrentViewMode)(IShellFolderViewDual2 *This,UINT *pViewMode);
      HRESULT (WINAPI *put_CurrentViewMode)(IShellFolderViewDual2 *This,UINT ViewMode);
      HRESULT (WINAPI *SelectItemRelative)(IShellFolderViewDual2 *This,int iRelative);
    END_INTERFACE
  } IShellFolderViewDual2Vtbl;
  struct IShellFolderViewDual2 {
    CONST_VTBL struct IShellFolderViewDual2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellFolderViewDual2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellFolderViewDual2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellFolderViewDual2_Release(This) (This)->lpVtbl->Release(This)
#define IShellFolderViewDual2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellFolderViewDual2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellFolderViewDual2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellFolderViewDual2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellFolderViewDual2_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellFolderViewDual2_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellFolderViewDual2_get_Folder(This,ppid) (This)->lpVtbl->get_Folder(This,ppid)
#define IShellFolderViewDual2_SelectedItems(This,ppid) (This)->lpVtbl->SelectedItems(This,ppid)
#define IShellFolderViewDual2_get_FocusedItem(This,ppid) (This)->lpVtbl->get_FocusedItem(This,ppid)
#define IShellFolderViewDual2_SelectItem(This,pvfi,dwFlags) (This)->lpVtbl->SelectItem(This,pvfi,dwFlags)
#define IShellFolderViewDual2_PopupItemMenu(This,pfi,vx,vy,pbs) (This)->lpVtbl->PopupItemMenu(This,pfi,vx,vy,pbs)
#define IShellFolderViewDual2_get_Script(This,ppDisp) (This)->lpVtbl->get_Script(This,ppDisp)
#define IShellFolderViewDual2_get_ViewOptions(This,plViewOptions) (This)->lpVtbl->get_ViewOptions(This,plViewOptions)
#define IShellFolderViewDual2_get_CurrentViewMode(This,pViewMode) (This)->lpVtbl->get_CurrentViewMode(This,pViewMode)
#define IShellFolderViewDual2_put_CurrentViewMode(This,ViewMode) (This)->lpVtbl->put_CurrentViewMode(This,ViewMode)
#define IShellFolderViewDual2_SelectItemRelative(This,iRelative) (This)->lpVtbl->SelectItemRelative(This,iRelative)
#endif
#endif
  HRESULT WINAPI IShellFolderViewDual2_get_CurrentViewMode_Proxy(IShellFolderViewDual2 *This,UINT *pViewMode);
  void __RPC_STUB IShellFolderViewDual2_get_CurrentViewMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual2_put_CurrentViewMode_Proxy(IShellFolderViewDual2 *This,UINT ViewMode);
  void __RPC_STUB IShellFolderViewDual2_put_CurrentViewMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellFolderViewDual2_SelectItemRelative_Proxy(IShellFolderViewDual2 *This,int iRelative);
  void __RPC_STUB IShellFolderViewDual2_SelectItemRelative_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_ShellFolderView;
#ifdef __cplusplus
  class ShellFolderView;
#endif

#ifndef __IShellDispatch_INTERFACE_DEFINED__
#define __IShellDispatch_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellDispatch;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellDispatch : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Application(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI get_Parent(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI NameSpace(VARIANT vDir,Folder **ppsdf) = 0;
    virtual HRESULT WINAPI BrowseForFolder(__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf) = 0;
    virtual HRESULT WINAPI Windows(IDispatch **ppid) = 0;
    virtual HRESULT WINAPI Open(VARIANT vDir) = 0;
    virtual HRESULT WINAPI Explore(VARIANT vDir) = 0;
    virtual HRESULT WINAPI MinimizeAll(void) = 0;
    virtual HRESULT WINAPI UndoMinimizeALL(void) = 0;
    virtual HRESULT WINAPI FileRun(void) = 0;
    virtual HRESULT WINAPI CascadeWindows(void) = 0;
    virtual HRESULT WINAPI TileVertically(void) = 0;
    virtual HRESULT WINAPI TileHorizontally(void) = 0;
    virtual HRESULT WINAPI ShutdownWindows(void) = 0;
    virtual HRESULT WINAPI Suspend(void) = 0;
    virtual HRESULT WINAPI EjectPC(void) = 0;
    virtual HRESULT WINAPI SetTime(void) = 0;
    virtual HRESULT WINAPI TrayProperties(void) = 0;
    virtual HRESULT WINAPI Help(void) = 0;
    virtual HRESULT WINAPI FindFiles(void) = 0;
    virtual HRESULT WINAPI FindComputer(void) = 0;
    virtual HRESULT WINAPI RefreshMenu(void) = 0;
    virtual HRESULT WINAPI ControlPanelItem(BSTR szDir) = 0;
  };
#else
  typedef struct IShellDispatchVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellDispatch *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellDispatch *This);
      ULONG (WINAPI *Release)(IShellDispatch *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellDispatch *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellDispatch *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellDispatch *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellDispatch *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellDispatch *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellDispatch *This,IDispatch **ppid);
      HRESULT (WINAPI *NameSpace)(IShellDispatch *This,VARIANT vDir,Folder **ppsdf);
      HRESULT (WINAPI *BrowseForFolder)(IShellDispatch *This,__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf);
      HRESULT (WINAPI *Windows)(IShellDispatch *This,IDispatch **ppid);
      HRESULT (WINAPI *Open)(IShellDispatch *This,VARIANT vDir);
      HRESULT (WINAPI *Explore)(IShellDispatch *This,VARIANT vDir);
      HRESULT (WINAPI *MinimizeAll)(IShellDispatch *This);
      HRESULT (WINAPI *UndoMinimizeALL)(IShellDispatch *This);
      HRESULT (WINAPI *FileRun)(IShellDispatch *This);
      HRESULT (WINAPI *CascadeWindows)(IShellDispatch *This);
      HRESULT (WINAPI *TileVertically)(IShellDispatch *This);
      HRESULT (WINAPI *TileHorizontally)(IShellDispatch *This);
      HRESULT (WINAPI *ShutdownWindows)(IShellDispatch *This);
      HRESULT (WINAPI *Suspend)(IShellDispatch *This);
      HRESULT (WINAPI *EjectPC)(IShellDispatch *This);
      HRESULT (WINAPI *SetTime)(IShellDispatch *This);
      HRESULT (WINAPI *TrayProperties)(IShellDispatch *This);
      HRESULT (WINAPI *Help)(IShellDispatch *This);
      HRESULT (WINAPI *FindFiles)(IShellDispatch *This);
      HRESULT (WINAPI *FindComputer)(IShellDispatch *This);
      HRESULT (WINAPI *RefreshMenu)(IShellDispatch *This);
      HRESULT (WINAPI *ControlPanelItem)(IShellDispatch *This,BSTR szDir);
    END_INTERFACE
  } IShellDispatchVtbl;
  struct IShellDispatch {
    CONST_VTBL struct IShellDispatchVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellDispatch_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellDispatch_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellDispatch_Release(This) (This)->lpVtbl->Release(This)
#define IShellDispatch_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellDispatch_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellDispatch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellDispatch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellDispatch_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellDispatch_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellDispatch_NameSpace(This,vDir,ppsdf) (This)->lpVtbl->NameSpace(This,vDir,ppsdf)
#define IShellDispatch_BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf) (This)->lpVtbl->BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf)
#define IShellDispatch_Windows(This,ppid) (This)->lpVtbl->Windows(This,ppid)
#define IShellDispatch_Open(This,vDir) (This)->lpVtbl->Open(This,vDir)
#define IShellDispatch_Explore(This,vDir) (This)->lpVtbl->Explore(This,vDir)
#define IShellDispatch_MinimizeAll(This) (This)->lpVtbl->MinimizeAll(This)
#define IShellDispatch_UndoMinimizeALL(This) (This)->lpVtbl->UndoMinimizeALL(This)
#define IShellDispatch_FileRun(This) (This)->lpVtbl->FileRun(This)
#define IShellDispatch_CascadeWindows(This) (This)->lpVtbl->CascadeWindows(This)
#define IShellDispatch_TileVertically(This) (This)->lpVtbl->TileVertically(This)
#define IShellDispatch_TileHorizontally(This) (This)->lpVtbl->TileHorizontally(This)
#define IShellDispatch_ShutdownWindows(This) (This)->lpVtbl->ShutdownWindows(This)
#define IShellDispatch_Suspend(This) (This)->lpVtbl->Suspend(This)
#define IShellDispatch_EjectPC(This) (This)->lpVtbl->EjectPC(This)
#define IShellDispatch_SetTime(This) (This)->lpVtbl->SetTime(This)
#define IShellDispatch_TrayProperties(This) (This)->lpVtbl->TrayProperties(This)
#define IShellDispatch_Help(This) (This)->lpVtbl->Help(This)
#define IShellDispatch_FindFiles(This) (This)->lpVtbl->FindFiles(This)
#define IShellDispatch_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define IShellDispatch_RefreshMenu(This) (This)->lpVtbl->RefreshMenu(This)
#define IShellDispatch_ControlPanelItem(This,szDir) (This)->lpVtbl->ControlPanelItem(This,szDir)
#endif
#endif
  HRESULT WINAPI IShellDispatch_get_Application_Proxy(IShellDispatch *This,IDispatch **ppid);
  void __RPC_STUB IShellDispatch_get_Application_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_get_Parent_Proxy(IShellDispatch *This,IDispatch **ppid);
  void __RPC_STUB IShellDispatch_get_Parent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_NameSpace_Proxy(IShellDispatch *This,VARIANT vDir,Folder **ppsdf);
  void __RPC_STUB IShellDispatch_NameSpace_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_BrowseForFolder_Proxy(IShellDispatch *This,__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf);
  void __RPC_STUB IShellDispatch_BrowseForFolder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_Windows_Proxy(IShellDispatch *This,IDispatch **ppid);
  void __RPC_STUB IShellDispatch_Windows_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_Open_Proxy(IShellDispatch *This,VARIANT vDir);
  void __RPC_STUB IShellDispatch_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_Explore_Proxy(IShellDispatch *This,VARIANT vDir);
  void __RPC_STUB IShellDispatch_Explore_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_MinimizeAll_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_MinimizeAll_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_UndoMinimizeALL_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_UndoMinimizeALL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_FileRun_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_FileRun_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_CascadeWindows_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_CascadeWindows_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_TileVertically_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_TileVertically_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_TileHorizontally_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_TileHorizontally_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_ShutdownWindows_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_ShutdownWindows_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_Suspend_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_Suspend_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_EjectPC_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_EjectPC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_SetTime_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_SetTime_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_TrayProperties_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_TrayProperties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_Help_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_Help_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_FindFiles_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_FindFiles_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_FindComputer_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_FindComputer_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_RefreshMenu_Proxy(IShellDispatch *This);
  void __RPC_STUB IShellDispatch_RefreshMenu_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch_ControlPanelItem_Proxy(IShellDispatch *This,BSTR szDir);
  void __RPC_STUB IShellDispatch_ControlPanelItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellDispatch2_INTERFACE_DEFINED__
#define __IShellDispatch2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellDispatch2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellDispatch2 : public IShellDispatch {
  public:
    virtual HRESULT WINAPI IsRestricted(BSTR Group,BSTR Restriction,__LONG32 *plRestrictValue) = 0;
    virtual HRESULT WINAPI ShellExecute(BSTR File,VARIANT vArgs,VARIANT vDir,VARIANT vOperation,VARIANT vShow) = 0;
    virtual HRESULT WINAPI FindPrinter(BSTR name,BSTR location,BSTR model) = 0;
    virtual HRESULT WINAPI GetSystemInformation(BSTR name,VARIANT *pv) = 0;
    virtual HRESULT WINAPI ServiceStart(BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess) = 0;
    virtual HRESULT WINAPI ServiceStop(BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess) = 0;
    virtual HRESULT WINAPI IsServiceRunning(BSTR ServiceName,VARIANT *pRunning) = 0;
    virtual HRESULT WINAPI CanStartStopService(BSTR ServiceName,VARIANT *pCanStartStop) = 0;
    virtual HRESULT WINAPI ShowBrowserBar(BSTR bstrClsid,VARIANT bShow,VARIANT *pSuccess) = 0;
  };
#else
  typedef struct IShellDispatch2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellDispatch2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellDispatch2 *This);
      ULONG (WINAPI *Release)(IShellDispatch2 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellDispatch2 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellDispatch2 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellDispatch2 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellDispatch2 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellDispatch2 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellDispatch2 *This,IDispatch **ppid);
      HRESULT (WINAPI *NameSpace)(IShellDispatch2 *This,VARIANT vDir,Folder **ppsdf);
      HRESULT (WINAPI *BrowseForFolder)(IShellDispatch2 *This,__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf);
      HRESULT (WINAPI *Windows)(IShellDispatch2 *This,IDispatch **ppid);
      HRESULT (WINAPI *Open)(IShellDispatch2 *This,VARIANT vDir);
      HRESULT (WINAPI *Explore)(IShellDispatch2 *This,VARIANT vDir);
      HRESULT (WINAPI *MinimizeAll)(IShellDispatch2 *This);
      HRESULT (WINAPI *UndoMinimizeALL)(IShellDispatch2 *This);
      HRESULT (WINAPI *FileRun)(IShellDispatch2 *This);
      HRESULT (WINAPI *CascadeWindows)(IShellDispatch2 *This);
      HRESULT (WINAPI *TileVertically)(IShellDispatch2 *This);
      HRESULT (WINAPI *TileHorizontally)(IShellDispatch2 *This);
      HRESULT (WINAPI *ShutdownWindows)(IShellDispatch2 *This);
      HRESULT (WINAPI *Suspend)(IShellDispatch2 *This);
      HRESULT (WINAPI *EjectPC)(IShellDispatch2 *This);
      HRESULT (WINAPI *SetTime)(IShellDispatch2 *This);
      HRESULT (WINAPI *TrayProperties)(IShellDispatch2 *This);
      HRESULT (WINAPI *Help)(IShellDispatch2 *This);
      HRESULT (WINAPI *FindFiles)(IShellDispatch2 *This);
      HRESULT (WINAPI *FindComputer)(IShellDispatch2 *This);
      HRESULT (WINAPI *RefreshMenu)(IShellDispatch2 *This);
      HRESULT (WINAPI *ControlPanelItem)(IShellDispatch2 *This,BSTR szDir);
      HRESULT (WINAPI *IsRestricted)(IShellDispatch2 *This,BSTR Group,BSTR Restriction,__LONG32 *plRestrictValue);
      HRESULT (WINAPI *ShellExecute)(IShellDispatch2 *This,BSTR File,VARIANT vArgs,VARIANT vDir,VARIANT vOperation,VARIANT vShow);
      HRESULT (WINAPI *FindPrinter)(IShellDispatch2 *This,BSTR name,BSTR location,BSTR model);
      HRESULT (WINAPI *GetSystemInformation)(IShellDispatch2 *This,BSTR name,VARIANT *pv);
      HRESULT (WINAPI *ServiceStart)(IShellDispatch2 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *ServiceStop)(IShellDispatch2 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *IsServiceRunning)(IShellDispatch2 *This,BSTR ServiceName,VARIANT *pRunning);
      HRESULT (WINAPI *CanStartStopService)(IShellDispatch2 *This,BSTR ServiceName,VARIANT *pCanStartStop);
      HRESULT (WINAPI *ShowBrowserBar)(IShellDispatch2 *This,BSTR bstrClsid,VARIANT bShow,VARIANT *pSuccess);
    END_INTERFACE
  } IShellDispatch2Vtbl;
  struct IShellDispatch2 {
    CONST_VTBL struct IShellDispatch2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellDispatch2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellDispatch2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellDispatch2_Release(This) (This)->lpVtbl->Release(This)
#define IShellDispatch2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellDispatch2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellDispatch2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellDispatch2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellDispatch2_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellDispatch2_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellDispatch2_NameSpace(This,vDir,ppsdf) (This)->lpVtbl->NameSpace(This,vDir,ppsdf)
#define IShellDispatch2_BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf) (This)->lpVtbl->BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf)
#define IShellDispatch2_Windows(This,ppid) (This)->lpVtbl->Windows(This,ppid)
#define IShellDispatch2_Open(This,vDir) (This)->lpVtbl->Open(This,vDir)
#define IShellDispatch2_Explore(This,vDir) (This)->lpVtbl->Explore(This,vDir)
#define IShellDispatch2_MinimizeAll(This) (This)->lpVtbl->MinimizeAll(This)
#define IShellDispatch2_UndoMinimizeALL(This) (This)->lpVtbl->UndoMinimizeALL(This)
#define IShellDispatch2_FileRun(This) (This)->lpVtbl->FileRun(This)
#define IShellDispatch2_CascadeWindows(This) (This)->lpVtbl->CascadeWindows(This)
#define IShellDispatch2_TileVertically(This) (This)->lpVtbl->TileVertically(This)
#define IShellDispatch2_TileHorizontally(This) (This)->lpVtbl->TileHorizontally(This)
#define IShellDispatch2_ShutdownWindows(This) (This)->lpVtbl->ShutdownWindows(This)
#define IShellDispatch2_Suspend(This) (This)->lpVtbl->Suspend(This)
#define IShellDispatch2_EjectPC(This) (This)->lpVtbl->EjectPC(This)
#define IShellDispatch2_SetTime(This) (This)->lpVtbl->SetTime(This)
#define IShellDispatch2_TrayProperties(This) (This)->lpVtbl->TrayProperties(This)
#define IShellDispatch2_Help(This) (This)->lpVtbl->Help(This)
#define IShellDispatch2_FindFiles(This) (This)->lpVtbl->FindFiles(This)
#define IShellDispatch2_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define IShellDispatch2_RefreshMenu(This) (This)->lpVtbl->RefreshMenu(This)
#define IShellDispatch2_ControlPanelItem(This,szDir) (This)->lpVtbl->ControlPanelItem(This,szDir)
#define IShellDispatch2_IsRestricted(This,Group,Restriction,plRestrictValue) (This)->lpVtbl->IsRestricted(This,Group,Restriction,plRestrictValue)
#define IShellDispatch2_ShellExecute(This,File,vArgs,vDir,vOperation,vShow) (This)->lpVtbl->ShellExecute(This,File,vArgs,vDir,vOperation,vShow)
#define IShellDispatch2_FindPrinter(This,name,location,model) (This)->lpVtbl->FindPrinter(This,name,location,model)
#define IShellDispatch2_GetSystemInformation(This,name,pv) (This)->lpVtbl->GetSystemInformation(This,name,pv)
#define IShellDispatch2_ServiceStart(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStart(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch2_ServiceStop(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStop(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch2_IsServiceRunning(This,ServiceName,pRunning) (This)->lpVtbl->IsServiceRunning(This,ServiceName,pRunning)
#define IShellDispatch2_CanStartStopService(This,ServiceName,pCanStartStop) (This)->lpVtbl->CanStartStopService(This,ServiceName,pCanStartStop)
#define IShellDispatch2_ShowBrowserBar(This,bstrClsid,bShow,pSuccess) (This)->lpVtbl->ShowBrowserBar(This,bstrClsid,bShow,pSuccess)
#endif
#endif
  HRESULT WINAPI IShellDispatch2_IsRestricted_Proxy(IShellDispatch2 *This,BSTR Group,BSTR Restriction,__LONG32 *plRestrictValue);
  void __RPC_STUB IShellDispatch2_IsRestricted_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_ShellExecute_Proxy(IShellDispatch2 *This,BSTR File,VARIANT vArgs,VARIANT vDir,VARIANT vOperation,VARIANT vShow);
  void __RPC_STUB IShellDispatch2_ShellExecute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_FindPrinter_Proxy(IShellDispatch2 *This,BSTR name,BSTR location,BSTR model);
  void __RPC_STUB IShellDispatch2_FindPrinter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_GetSystemInformation_Proxy(IShellDispatch2 *This,BSTR name,VARIANT *pv);
  void __RPC_STUB IShellDispatch2_GetSystemInformation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_ServiceStart_Proxy(IShellDispatch2 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
  void __RPC_STUB IShellDispatch2_ServiceStart_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_ServiceStop_Proxy(IShellDispatch2 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
  void __RPC_STUB IShellDispatch2_ServiceStop_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_IsServiceRunning_Proxy(IShellDispatch2 *This,BSTR ServiceName,VARIANT *pRunning);
  void __RPC_STUB IShellDispatch2_IsServiceRunning_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_CanStartStopService_Proxy(IShellDispatch2 *This,BSTR ServiceName,VARIANT *pCanStartStop);
  void __RPC_STUB IShellDispatch2_CanStartStopService_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch2_ShowBrowserBar_Proxy(IShellDispatch2 *This,BSTR bstrClsid,VARIANT bShow,VARIANT *pSuccess);
  void __RPC_STUB IShellDispatch2_ShowBrowserBar_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellDispatch3_INTERFACE_DEFINED__
#define __IShellDispatch3_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellDispatch3;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellDispatch3 : public IShellDispatch2 {
  public:
    virtual HRESULT WINAPI AddToRecent(VARIANT varFile,BSTR bstrCategory) = 0;
  };
#else
  typedef struct IShellDispatch3Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellDispatch3 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellDispatch3 *This);
      ULONG (WINAPI *Release)(IShellDispatch3 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellDispatch3 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellDispatch3 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellDispatch3 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellDispatch3 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellDispatch3 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellDispatch3 *This,IDispatch **ppid);
      HRESULT (WINAPI *NameSpace)(IShellDispatch3 *This,VARIANT vDir,Folder **ppsdf);
      HRESULT (WINAPI *BrowseForFolder)(IShellDispatch3 *This,__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf);
      HRESULT (WINAPI *Windows)(IShellDispatch3 *This,IDispatch **ppid);
      HRESULT (WINAPI *Open)(IShellDispatch3 *This,VARIANT vDir);
      HRESULT (WINAPI *Explore)(IShellDispatch3 *This,VARIANT vDir);
      HRESULT (WINAPI *MinimizeAll)(IShellDispatch3 *This);
      HRESULT (WINAPI *UndoMinimizeALL)(IShellDispatch3 *This);
      HRESULT (WINAPI *FileRun)(IShellDispatch3 *This);
      HRESULT (WINAPI *CascadeWindows)(IShellDispatch3 *This);
      HRESULT (WINAPI *TileVertically)(IShellDispatch3 *This);
      HRESULT (WINAPI *TileHorizontally)(IShellDispatch3 *This);
      HRESULT (WINAPI *ShutdownWindows)(IShellDispatch3 *This);
      HRESULT (WINAPI *Suspend)(IShellDispatch3 *This);
      HRESULT (WINAPI *EjectPC)(IShellDispatch3 *This);
      HRESULT (WINAPI *SetTime)(IShellDispatch3 *This);
      HRESULT (WINAPI *TrayProperties)(IShellDispatch3 *This);
      HRESULT (WINAPI *Help)(IShellDispatch3 *This);
      HRESULT (WINAPI *FindFiles)(IShellDispatch3 *This);
      HRESULT (WINAPI *FindComputer)(IShellDispatch3 *This);
      HRESULT (WINAPI *RefreshMenu)(IShellDispatch3 *This);
      HRESULT (WINAPI *ControlPanelItem)(IShellDispatch3 *This,BSTR szDir);
      HRESULT (WINAPI *IsRestricted)(IShellDispatch3 *This,BSTR Group,BSTR Restriction,__LONG32 *plRestrictValue);
      HRESULT (WINAPI *ShellExecute)(IShellDispatch3 *This,BSTR File,VARIANT vArgs,VARIANT vDir,VARIANT vOperation,VARIANT vShow);
      HRESULT (WINAPI *FindPrinter)(IShellDispatch3 *This,BSTR name,BSTR location,BSTR model);
      HRESULT (WINAPI *GetSystemInformation)(IShellDispatch3 *This,BSTR name,VARIANT *pv);
      HRESULT (WINAPI *ServiceStart)(IShellDispatch3 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *ServiceStop)(IShellDispatch3 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *IsServiceRunning)(IShellDispatch3 *This,BSTR ServiceName,VARIANT *pRunning);
      HRESULT (WINAPI *CanStartStopService)(IShellDispatch3 *This,BSTR ServiceName,VARIANT *pCanStartStop);
      HRESULT (WINAPI *ShowBrowserBar)(IShellDispatch3 *This,BSTR bstrClsid,VARIANT bShow,VARIANT *pSuccess);
      HRESULT (WINAPI *AddToRecent)(IShellDispatch3 *This,VARIANT varFile,BSTR bstrCategory);
    END_INTERFACE
  } IShellDispatch3Vtbl;
  struct IShellDispatch3 {
    CONST_VTBL struct IShellDispatch3Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellDispatch3_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellDispatch3_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellDispatch3_Release(This) (This)->lpVtbl->Release(This)
#define IShellDispatch3_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellDispatch3_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellDispatch3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellDispatch3_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellDispatch3_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellDispatch3_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellDispatch3_NameSpace(This,vDir,ppsdf) (This)->lpVtbl->NameSpace(This,vDir,ppsdf)
#define IShellDispatch3_BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf) (This)->lpVtbl->BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf)
#define IShellDispatch3_Windows(This,ppid) (This)->lpVtbl->Windows(This,ppid)
#define IShellDispatch3_Open(This,vDir) (This)->lpVtbl->Open(This,vDir)
#define IShellDispatch3_Explore(This,vDir) (This)->lpVtbl->Explore(This,vDir)
#define IShellDispatch3_MinimizeAll(This) (This)->lpVtbl->MinimizeAll(This)
#define IShellDispatch3_UndoMinimizeALL(This) (This)->lpVtbl->UndoMinimizeALL(This)
#define IShellDispatch3_FileRun(This) (This)->lpVtbl->FileRun(This)
#define IShellDispatch3_CascadeWindows(This) (This)->lpVtbl->CascadeWindows(This)
#define IShellDispatch3_TileVertically(This) (This)->lpVtbl->TileVertically(This)
#define IShellDispatch3_TileHorizontally(This) (This)->lpVtbl->TileHorizontally(This)
#define IShellDispatch3_ShutdownWindows(This) (This)->lpVtbl->ShutdownWindows(This)
#define IShellDispatch3_Suspend(This) (This)->lpVtbl->Suspend(This)
#define IShellDispatch3_EjectPC(This) (This)->lpVtbl->EjectPC(This)
#define IShellDispatch3_SetTime(This) (This)->lpVtbl->SetTime(This)
#define IShellDispatch3_TrayProperties(This) (This)->lpVtbl->TrayProperties(This)
#define IShellDispatch3_Help(This) (This)->lpVtbl->Help(This)
#define IShellDispatch3_FindFiles(This) (This)->lpVtbl->FindFiles(This)
#define IShellDispatch3_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define IShellDispatch3_RefreshMenu(This) (This)->lpVtbl->RefreshMenu(This)
#define IShellDispatch3_ControlPanelItem(This,szDir) (This)->lpVtbl->ControlPanelItem(This,szDir)
#define IShellDispatch3_IsRestricted(This,Group,Restriction,plRestrictValue) (This)->lpVtbl->IsRestricted(This,Group,Restriction,plRestrictValue)
#define IShellDispatch3_ShellExecute(This,File,vArgs,vDir,vOperation,vShow) (This)->lpVtbl->ShellExecute(This,File,vArgs,vDir,vOperation,vShow)
#define IShellDispatch3_FindPrinter(This,name,location,model) (This)->lpVtbl->FindPrinter(This,name,location,model)
#define IShellDispatch3_GetSystemInformation(This,name,pv) (This)->lpVtbl->GetSystemInformation(This,name,pv)
#define IShellDispatch3_ServiceStart(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStart(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch3_ServiceStop(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStop(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch3_IsServiceRunning(This,ServiceName,pRunning) (This)->lpVtbl->IsServiceRunning(This,ServiceName,pRunning)
#define IShellDispatch3_CanStartStopService(This,ServiceName,pCanStartStop) (This)->lpVtbl->CanStartStopService(This,ServiceName,pCanStartStop)
#define IShellDispatch3_ShowBrowserBar(This,bstrClsid,bShow,pSuccess) (This)->lpVtbl->ShowBrowserBar(This,bstrClsid,bShow,pSuccess)
#define IShellDispatch3_AddToRecent(This,varFile,bstrCategory) (This)->lpVtbl->AddToRecent(This,varFile,bstrCategory)
#endif
#endif
  HRESULT WINAPI IShellDispatch3_AddToRecent_Proxy(IShellDispatch3 *This,VARIANT varFile,BSTR bstrCategory);
  void __RPC_STUB IShellDispatch3_AddToRecent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IShellDispatch4_INTERFACE_DEFINED__
#define __IShellDispatch4_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IShellDispatch4;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IShellDispatch4 : public IShellDispatch3 {
  public:
    virtual HRESULT WINAPI WindowsSecurity(void) = 0;
    virtual HRESULT WINAPI ToggleDesktop(void) = 0;
    virtual HRESULT WINAPI ExplorerPolicy(BSTR bstrPolicyName,VARIANT *pValue) = 0;
    virtual HRESULT WINAPI GetSetting(__LONG32 lSetting,VARIANT_BOOL *pResult) = 0;
  };
#else
  typedef struct IShellDispatch4Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IShellDispatch4 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IShellDispatch4 *This);
      ULONG (WINAPI *Release)(IShellDispatch4 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IShellDispatch4 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IShellDispatch4 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IShellDispatch4 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IShellDispatch4 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Application)(IShellDispatch4 *This,IDispatch **ppid);
      HRESULT (WINAPI *get_Parent)(IShellDispatch4 *This,IDispatch **ppid);
      HRESULT (WINAPI *NameSpace)(IShellDispatch4 *This,VARIANT vDir,Folder **ppsdf);
      HRESULT (WINAPI *BrowseForFolder)(IShellDispatch4 *This,__LONG32 Hwnd,BSTR Title,__LONG32 Options,VARIANT RootFolder,Folder **ppsdf);
      HRESULT (WINAPI *Windows)(IShellDispatch4 *This,IDispatch **ppid);
      HRESULT (WINAPI *Open)(IShellDispatch4 *This,VARIANT vDir);
      HRESULT (WINAPI *Explore)(IShellDispatch4 *This,VARIANT vDir);
      HRESULT (WINAPI *MinimizeAll)(IShellDispatch4 *This);
      HRESULT (WINAPI *UndoMinimizeALL)(IShellDispatch4 *This);
      HRESULT (WINAPI *FileRun)(IShellDispatch4 *This);
      HRESULT (WINAPI *CascadeWindows)(IShellDispatch4 *This);
      HRESULT (WINAPI *TileVertically)(IShellDispatch4 *This);
      HRESULT (WINAPI *TileHorizontally)(IShellDispatch4 *This);
      HRESULT (WINAPI *ShutdownWindows)(IShellDispatch4 *This);
      HRESULT (WINAPI *Suspend)(IShellDispatch4 *This);
      HRESULT (WINAPI *EjectPC)(IShellDispatch4 *This);
      HRESULT (WINAPI *SetTime)(IShellDispatch4 *This);
      HRESULT (WINAPI *TrayProperties)(IShellDispatch4 *This);
      HRESULT (WINAPI *Help)(IShellDispatch4 *This);
      HRESULT (WINAPI *FindFiles)(IShellDispatch4 *This);
      HRESULT (WINAPI *FindComputer)(IShellDispatch4 *This);
      HRESULT (WINAPI *RefreshMenu)(IShellDispatch4 *This);
      HRESULT (WINAPI *ControlPanelItem)(IShellDispatch4 *This,BSTR szDir);
      HRESULT (WINAPI *IsRestricted)(IShellDispatch4 *This,BSTR Group,BSTR Restriction,__LONG32 *plRestrictValue);
      HRESULT (WINAPI *ShellExecute)(IShellDispatch4 *This,BSTR File,VARIANT vArgs,VARIANT vDir,VARIANT vOperation,VARIANT vShow);
      HRESULT (WINAPI *FindPrinter)(IShellDispatch4 *This,BSTR name,BSTR location,BSTR model);
      HRESULT (WINAPI *GetSystemInformation)(IShellDispatch4 *This,BSTR name,VARIANT *pv);
      HRESULT (WINAPI *ServiceStart)(IShellDispatch4 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *ServiceStop)(IShellDispatch4 *This,BSTR ServiceName,VARIANT Persistent,VARIANT *pSuccess);
      HRESULT (WINAPI *IsServiceRunning)(IShellDispatch4 *This,BSTR ServiceName,VARIANT *pRunning);
      HRESULT (WINAPI *CanStartStopService)(IShellDispatch4 *This,BSTR ServiceName,VARIANT *pCanStartStop);
      HRESULT (WINAPI *ShowBrowserBar)(IShellDispatch4 *This,BSTR bstrClsid,VARIANT bShow,VARIANT *pSuccess);
      HRESULT (WINAPI *AddToRecent)(IShellDispatch4 *This,VARIANT varFile,BSTR bstrCategory);
      HRESULT (WINAPI *WindowsSecurity)(IShellDispatch4 *This);
      HRESULT (WINAPI *ToggleDesktop)(IShellDispatch4 *This);
      HRESULT (WINAPI *ExplorerPolicy)(IShellDispatch4 *This,BSTR bstrPolicyName,VARIANT *pValue);
      HRESULT (WINAPI *GetSetting)(IShellDispatch4 *This,__LONG32 lSetting,VARIANT_BOOL *pResult);
    END_INTERFACE
  } IShellDispatch4Vtbl;
  struct IShellDispatch4 {
    CONST_VTBL struct IShellDispatch4Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IShellDispatch4_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IShellDispatch4_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IShellDispatch4_Release(This) (This)->lpVtbl->Release(This)
#define IShellDispatch4_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IShellDispatch4_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IShellDispatch4_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IShellDispatch4_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IShellDispatch4_get_Application(This,ppid) (This)->lpVtbl->get_Application(This,ppid)
#define IShellDispatch4_get_Parent(This,ppid) (This)->lpVtbl->get_Parent(This,ppid)
#define IShellDispatch4_NameSpace(This,vDir,ppsdf) (This)->lpVtbl->NameSpace(This,vDir,ppsdf)
#define IShellDispatch4_BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf) (This)->lpVtbl->BrowseForFolder(This,Hwnd,Title,Options,RootFolder,ppsdf)
#define IShellDispatch4_Windows(This,ppid) (This)->lpVtbl->Windows(This,ppid)
#define IShellDispatch4_Open(This,vDir) (This)->lpVtbl->Open(This,vDir)
#define IShellDispatch4_Explore(This,vDir) (This)->lpVtbl->Explore(This,vDir)
#define IShellDispatch4_MinimizeAll(This) (This)->lpVtbl->MinimizeAll(This)
#define IShellDispatch4_UndoMinimizeALL(This) (This)->lpVtbl->UndoMinimizeALL(This)
#define IShellDispatch4_FileRun(This) (This)->lpVtbl->FileRun(This)
#define IShellDispatch4_CascadeWindows(This) (This)->lpVtbl->CascadeWindows(This)
#define IShellDispatch4_TileVertically(This) (This)->lpVtbl->TileVertically(This)
#define IShellDispatch4_TileHorizontally(This) (This)->lpVtbl->TileHorizontally(This)
#define IShellDispatch4_ShutdownWindows(This) (This)->lpVtbl->ShutdownWindows(This)
#define IShellDispatch4_Suspend(This) (This)->lpVtbl->Suspend(This)
#define IShellDispatch4_EjectPC(This) (This)->lpVtbl->EjectPC(This)
#define IShellDispatch4_SetTime(This) (This)->lpVtbl->SetTime(This)
#define IShellDispatch4_TrayProperties(This) (This)->lpVtbl->TrayProperties(This)
#define IShellDispatch4_Help(This) (This)->lpVtbl->Help(This)
#define IShellDispatch4_FindFiles(This) (This)->lpVtbl->FindFiles(This)
#define IShellDispatch4_FindComputer(This) (This)->lpVtbl->FindComputer(This)
#define IShellDispatch4_RefreshMenu(This) (This)->lpVtbl->RefreshMenu(This)
#define IShellDispatch4_ControlPanelItem(This,szDir) (This)->lpVtbl->ControlPanelItem(This,szDir)
#define IShellDispatch4_IsRestricted(This,Group,Restriction,plRestrictValue) (This)->lpVtbl->IsRestricted(This,Group,Restriction,plRestrictValue)
#define IShellDispatch4_ShellExecute(This,File,vArgs,vDir,vOperation,vShow) (This)->lpVtbl->ShellExecute(This,File,vArgs,vDir,vOperation,vShow)
#define IShellDispatch4_FindPrinter(This,name,location,model) (This)->lpVtbl->FindPrinter(This,name,location,model)
#define IShellDispatch4_GetSystemInformation(This,name,pv) (This)->lpVtbl->GetSystemInformation(This,name,pv)
#define IShellDispatch4_ServiceStart(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStart(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch4_ServiceStop(This,ServiceName,Persistent,pSuccess) (This)->lpVtbl->ServiceStop(This,ServiceName,Persistent,pSuccess)
#define IShellDispatch4_IsServiceRunning(This,ServiceName,pRunning) (This)->lpVtbl->IsServiceRunning(This,ServiceName,pRunning)
#define IShellDispatch4_CanStartStopService(This,ServiceName,pCanStartStop) (This)->lpVtbl->CanStartStopService(This,ServiceName,pCanStartStop)
#define IShellDispatch4_ShowBrowserBar(This,bstrClsid,bShow,pSuccess) (This)->lpVtbl->ShowBrowserBar(This,bstrClsid,bShow,pSuccess)
#define IShellDispatch4_AddToRecent(This,varFile,bstrCategory) (This)->lpVtbl->AddToRecent(This,varFile,bstrCategory)
#define IShellDispatch4_WindowsSecurity(This) (This)->lpVtbl->WindowsSecurity(This)
#define IShellDispatch4_ToggleDesktop(This) (This)->lpVtbl->ToggleDesktop(This)
#define IShellDispatch4_ExplorerPolicy(This,bstrPolicyName,pValue) (This)->lpVtbl->ExplorerPolicy(This,bstrPolicyName,pValue)
#define IShellDispatch4_GetSetting(This,lSetting,pResult) (This)->lpVtbl->GetSetting(This,lSetting,pResult)
#endif
#endif
  HRESULT WINAPI IShellDispatch4_WindowsSecurity_Proxy(IShellDispatch4 *This);
  void __RPC_STUB IShellDispatch4_WindowsSecurity_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch4_ToggleDesktop_Proxy(IShellDispatch4 *This);
  void __RPC_STUB IShellDispatch4_ToggleDesktop_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch4_ExplorerPolicy_Proxy(IShellDispatch4 *This,BSTR bstrPolicyName,VARIANT *pValue);
  void __RPC_STUB IShellDispatch4_ExplorerPolicy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IShellDispatch4_GetSetting_Proxy(IShellDispatch4 *This,__LONG32 lSetting,VARIANT_BOOL *pResult);
  void __RPC_STUB IShellDispatch4_GetSetting_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_Shell;
#ifdef __cplusplus
  class Shell;
#endif
  EXTERN_C const CLSID CLSID_ShellDispatchInproc;
#ifdef __cplusplus
  class ShellDispatchInproc;
#endif
  EXTERN_C const CLSID CLSID_WebViewFolderContents;
#ifdef __cplusplus
  class WebViewFolderContents;
#endif

#ifndef __DSearchCommandEvents_DISPINTERFACE_DEFINED__
#define __DSearchCommandEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_DSearchCommandEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct DSearchCommandEvents : public IDispatch {
  };
#else
  typedef struct DSearchCommandEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(DSearchCommandEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(DSearchCommandEvents *This);
      ULONG (WINAPI *Release)(DSearchCommandEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(DSearchCommandEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(DSearchCommandEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(DSearchCommandEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(DSearchCommandEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } DSearchCommandEventsVtbl;
  struct DSearchCommandEvents {
    CONST_VTBL struct DSearchCommandEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define DSearchCommandEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define DSearchCommandEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define DSearchCommandEvents_Release(This) (This)->lpVtbl->Release(This)
#define DSearchCommandEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define DSearchCommandEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define DSearchCommandEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define DSearchCommandEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

  EXTERN_C const CLSID CLSID_SearchCommand;
#ifdef __cplusplus
  class SearchCommand;
#endif

#ifndef __IFileSearchBand_INTERFACE_DEFINED__
#define __IFileSearchBand_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IFileSearchBand;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IFileSearchBand : public IDispatch {
  public:
    virtual HRESULT WINAPI SetFocus(void) = 0;
    virtual HRESULT WINAPI SetSearchParameters(BSTR *pbstrSearchID,VARIANT_BOOL bNavToResults,VARIANT *pvarScope,VARIANT *pvarQueryFile) = 0;
    virtual HRESULT WINAPI get_SearchID(BSTR *pbstrSearchID) = 0;
    virtual HRESULT WINAPI get_Scope(VARIANT *pvarScope) = 0;
    virtual HRESULT WINAPI get_QueryFile(VARIANT *pvarFile) = 0;
  };
#else
  typedef struct IFileSearchBandVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IFileSearchBand *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IFileSearchBand *This);
      ULONG (WINAPI *Release)(IFileSearchBand *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IFileSearchBand *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IFileSearchBand *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IFileSearchBand *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IFileSearchBand *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *SetFocus)(IFileSearchBand *This);
      HRESULT (WINAPI *SetSearchParameters)(IFileSearchBand *This,BSTR *pbstrSearchID,VARIANT_BOOL bNavToResults,VARIANT *pvarScope,VARIANT *pvarQueryFile);
      HRESULT (WINAPI *get_SearchID)(IFileSearchBand *This,BSTR *pbstrSearchID);
      HRESULT (WINAPI *get_Scope)(IFileSearchBand *This,VARIANT *pvarScope);
      HRESULT (WINAPI *get_QueryFile)(IFileSearchBand *This,VARIANT *pvarFile);
    END_INTERFACE
  } IFileSearchBandVtbl;
  struct IFileSearchBand {
    CONST_VTBL struct IFileSearchBandVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IFileSearchBand_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFileSearchBand_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFileSearchBand_Release(This) (This)->lpVtbl->Release(This)
#define IFileSearchBand_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFileSearchBand_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFileSearchBand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFileSearchBand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFileSearchBand_SetFocus(This) (This)->lpVtbl->SetFocus(This)
#define IFileSearchBand_SetSearchParameters(This,pbstrSearchID,bNavToResults,pvarScope,pvarQueryFile) (This)->lpVtbl->SetSearchParameters(This,pbstrSearchID,bNavToResults,pvarScope,pvarQueryFile)
#define IFileSearchBand_get_SearchID(This,pbstrSearchID) (This)->lpVtbl->get_SearchID(This,pbstrSearchID)
#define IFileSearchBand_get_Scope(This,pvarScope) (This)->lpVtbl->get_Scope(This,pvarScope)
#define IFileSearchBand_get_QueryFile(This,pvarFile) (This)->lpVtbl->get_QueryFile(This,pvarFile)
#endif
#endif
  HRESULT WINAPI IFileSearchBand_SetFocus_Proxy(IFileSearchBand *This);
  void __RPC_STUB IFileSearchBand_SetFocus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFileSearchBand_SetSearchParameters_Proxy(IFileSearchBand *This,BSTR *pbstrSearchID,VARIANT_BOOL bNavToResults,VARIANT *pvarScope,VARIANT *pvarQueryFile);
  void __RPC_STUB IFileSearchBand_SetSearchParameters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFileSearchBand_get_SearchID_Proxy(IFileSearchBand *This,BSTR *pbstrSearchID);
  void __RPC_STUB IFileSearchBand_get_SearchID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFileSearchBand_get_Scope_Proxy(IFileSearchBand *This,VARIANT *pvarScope);
  void __RPC_STUB IFileSearchBand_get_Scope_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IFileSearchBand_get_QueryFile_Proxy(IFileSearchBand *This,VARIANT *pvarFile);
  void __RPC_STUB IFileSearchBand_get_QueryFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_FileSearchBand;
#ifdef __cplusplus
  class FileSearchBand;
#endif

#ifndef __IWebWizardHost_INTERFACE_DEFINED__
#define __IWebWizardHost_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IWebWizardHost;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IWebWizardHost : public IDispatch {
  public:
    virtual HRESULT WINAPI FinalBack(void) = 0;
    virtual HRESULT WINAPI FinalNext(void) = 0;
    virtual HRESULT WINAPI Cancel(void) = 0;
    virtual HRESULT WINAPI put_Caption(BSTR bstrCaption) = 0;
    virtual HRESULT WINAPI get_Caption(BSTR *pbstrCaption) = 0;
    virtual HRESULT WINAPI put_Property(BSTR bstrPropertyName,VARIANT *pvProperty) = 0;
    virtual HRESULT WINAPI get_Property(BSTR bstrPropertyName,VARIANT *pvProperty) = 0;
    virtual HRESULT WINAPI SetWizardButtons(VARIANT_BOOL vfEnableBack,VARIANT_BOOL vfEnableNext,VARIANT_BOOL vfLastPage) = 0;
    virtual HRESULT WINAPI SetHeaderText(BSTR bstrHeaderTitle,BSTR bstrHeaderSubtitle) = 0;
  };
#else
  typedef struct IWebWizardHostVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IWebWizardHost *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IWebWizardHost *This);
      ULONG (WINAPI *Release)(IWebWizardHost *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IWebWizardHost *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IWebWizardHost *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IWebWizardHost *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IWebWizardHost *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *FinalBack)(IWebWizardHost *This);
      HRESULT (WINAPI *FinalNext)(IWebWizardHost *This);
      HRESULT (WINAPI *Cancel)(IWebWizardHost *This);
      HRESULT (WINAPI *put_Caption)(IWebWizardHost *This,BSTR bstrCaption);
      HRESULT (WINAPI *get_Caption)(IWebWizardHost *This,BSTR *pbstrCaption);
      HRESULT (WINAPI *put_Property)(IWebWizardHost *This,BSTR bstrPropertyName,VARIANT *pvProperty);
      HRESULT (WINAPI *get_Property)(IWebWizardHost *This,BSTR bstrPropertyName,VARIANT *pvProperty);
      HRESULT (WINAPI *SetWizardButtons)(IWebWizardHost *This,VARIANT_BOOL vfEnableBack,VARIANT_BOOL vfEnableNext,VARIANT_BOOL vfLastPage);
      HRESULT (WINAPI *SetHeaderText)(IWebWizardHost *This,BSTR bstrHeaderTitle,BSTR bstrHeaderSubtitle);
    END_INTERFACE
  } IWebWizardHostVtbl;
  struct IWebWizardHost {
    CONST_VTBL struct IWebWizardHostVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IWebWizardHost_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWebWizardHost_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWebWizardHost_Release(This) (This)->lpVtbl->Release(This)
#define IWebWizardHost_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IWebWizardHost_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IWebWizardHost_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IWebWizardHost_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IWebWizardHost_FinalBack(This) (This)->lpVtbl->FinalBack(This)
#define IWebWizardHost_FinalNext(This) (This)->lpVtbl->FinalNext(This)
#define IWebWizardHost_Cancel(This) (This)->lpVtbl->Cancel(This)
#define IWebWizardHost_put_Caption(This,bstrCaption) (This)->lpVtbl->put_Caption(This,bstrCaption)
#define IWebWizardHost_get_Caption(This,pbstrCaption) (This)->lpVtbl->get_Caption(This,pbstrCaption)
#define IWebWizardHost_put_Property(This,bstrPropertyName,pvProperty) (This)->lpVtbl->put_Property(This,bstrPropertyName,pvProperty)
#define IWebWizardHost_get_Property(This,bstrPropertyName,pvProperty) (This)->lpVtbl->get_Property(This,bstrPropertyName,pvProperty)
#define IWebWizardHost_SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage) (This)->lpVtbl->SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)
#define IWebWizardHost_SetHeaderText(This,bstrHeaderTitle,bstrHeaderSubtitle) (This)->lpVtbl->SetHeaderText(This,bstrHeaderTitle,bstrHeaderSubtitle)
#endif
#endif
  HRESULT WINAPI IWebWizardHost_FinalBack_Proxy(IWebWizardHost *This);
  void __RPC_STUB IWebWizardHost_FinalBack_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_FinalNext_Proxy(IWebWizardHost *This);
  void __RPC_STUB IWebWizardHost_FinalNext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_Cancel_Proxy(IWebWizardHost *This);
  void __RPC_STUB IWebWizardHost_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_put_Caption_Proxy(IWebWizardHost *This,BSTR bstrCaption);
  void __RPC_STUB IWebWizardHost_put_Caption_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_get_Caption_Proxy(IWebWizardHost *This,BSTR *pbstrCaption);
  void __RPC_STUB IWebWizardHost_get_Caption_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_put_Property_Proxy(IWebWizardHost *This,BSTR bstrPropertyName,VARIANT *pvProperty);
  void __RPC_STUB IWebWizardHost_put_Property_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_get_Property_Proxy(IWebWizardHost *This,BSTR bstrPropertyName,VARIANT *pvProperty);
  void __RPC_STUB IWebWizardHost_get_Property_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_SetWizardButtons_Proxy(IWebWizardHost *This,VARIANT_BOOL vfEnableBack,VARIANT_BOOL vfEnableNext,VARIANT_BOOL vfLastPage);
  void __RPC_STUB IWebWizardHost_SetWizardButtons_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IWebWizardHost_SetHeaderText_Proxy(IWebWizardHost *This,BSTR bstrHeaderTitle,BSTR bstrHeaderSubtitle);
  void __RPC_STUB IWebWizardHost_SetHeaderText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __INewWDEvents_INTERFACE_DEFINED__
#define __INewWDEvents_INTERFACE_DEFINED__
  EXTERN_C const IID IID_INewWDEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct INewWDEvents : public IWebWizardHost {
  public:
    virtual HRESULT WINAPI PassportAuthenticate(BSTR bstrSignInUrl,VARIANT_BOOL *pvfAuthenitcated) = 0;
  };
#else
  typedef struct INewWDEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(INewWDEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(INewWDEvents *This);
      ULONG (WINAPI *Release)(INewWDEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(INewWDEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(INewWDEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(INewWDEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(INewWDEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *FinalBack)(INewWDEvents *This);
      HRESULT (WINAPI *FinalNext)(INewWDEvents *This);
      HRESULT (WINAPI *Cancel)(INewWDEvents *This);
      HRESULT (WINAPI *put_Caption)(INewWDEvents *This,BSTR bstrCaption);
      HRESULT (WINAPI *get_Caption)(INewWDEvents *This,BSTR *pbstrCaption);
      HRESULT (WINAPI *put_Property)(INewWDEvents *This,BSTR bstrPropertyName,VARIANT *pvProperty);
      HRESULT (WINAPI *get_Property)(INewWDEvents *This,BSTR bstrPropertyName,VARIANT *pvProperty);
      HRESULT (WINAPI *SetWizardButtons)(INewWDEvents *This,VARIANT_BOOL vfEnableBack,VARIANT_BOOL vfEnableNext,VARIANT_BOOL vfLastPage);
      HRESULT (WINAPI *SetHeaderText)(INewWDEvents *This,BSTR bstrHeaderTitle,BSTR bstrHeaderSubtitle);
      HRESULT (WINAPI *PassportAuthenticate)(INewWDEvents *This,BSTR bstrSignInUrl,VARIANT_BOOL *pvfAuthenitcated);
    END_INTERFACE
  } INewWDEventsVtbl;
  struct INewWDEvents {
    CONST_VTBL struct INewWDEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define INewWDEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define INewWDEvents_AddRef(This) (This)->lpVtbl->AddRef(This)
#define INewWDEvents_Release(This) (This)->lpVtbl->Release(This)
#define INewWDEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define INewWDEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define INewWDEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define INewWDEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define INewWDEvents_FinalBack(This) (This)->lpVtbl->FinalBack(This)
#define INewWDEvents_FinalNext(This) (This)->lpVtbl->FinalNext(This)
#define INewWDEvents_Cancel(This) (This)->lpVtbl->Cancel(This)
#define INewWDEvents_put_Caption(This,bstrCaption) (This)->lpVtbl->put_Caption(This,bstrCaption)
#define INewWDEvents_get_Caption(This,pbstrCaption) (This)->lpVtbl->get_Caption(This,pbstrCaption)
#define INewWDEvents_put_Property(This,bstrPropertyName,pvProperty) (This)->lpVtbl->put_Property(This,bstrPropertyName,pvProperty)
#define INewWDEvents_get_Property(This,bstrPropertyName,pvProperty) (This)->lpVtbl->get_Property(This,bstrPropertyName,pvProperty)
#define INewWDEvents_SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage) (This)->lpVtbl->SetWizardButtons(This,vfEnableBack,vfEnableNext,vfLastPage)
#define INewWDEvents_SetHeaderText(This,bstrHeaderTitle,bstrHeaderSubtitle) (This)->lpVtbl->SetHeaderText(This,bstrHeaderTitle,bstrHeaderSubtitle)
#define INewWDEvents_PassportAuthenticate(This,bstrSignInUrl,pvfAuthenitcated) (This)->lpVtbl->PassportAuthenticate(This,bstrSignInUrl,pvfAuthenitcated)
#endif
#endif
  HRESULT WINAPI INewWDEvents_PassportAuthenticate_Proxy(INewWDEvents *This,BSTR bstrSignInUrl,VARIANT_BOOL *pvfAuthenitcated);
  void __RPC_STUB INewWDEvents_PassportAuthenticate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IPassportClientServices_INTERFACE_DEFINED__
#define __IPassportClientServices_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IPassportClientServices;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IPassportClientServices : public IDispatch {
  public:
    virtual HRESULT WINAPI MemberExists(BSTR bstrUser,BSTR bstrPassword,VARIANT_BOOL *pvfExists) = 0;
  };
#else
  typedef struct IPassportClientServicesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IPassportClientServices *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IPassportClientServices *This);
      ULONG (WINAPI *Release)(IPassportClientServices *This);
      HRESULT (WINAPI *GetTypeInfoCount)(IPassportClientServices *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(IPassportClientServices *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(IPassportClientServices *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(IPassportClientServices *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *MemberExists)(IPassportClientServices *This,BSTR bstrUser,BSTR bstrPassword,VARIANT_BOOL *pvfExists);
    END_INTERFACE
  } IPassportClientServicesVtbl;
  struct IPassportClientServices {
    CONST_VTBL struct IPassportClientServicesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IPassportClientServices_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPassportClientServices_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPassportClientServices_Release(This) (This)->lpVtbl->Release(This)
#define IPassportClientServices_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IPassportClientServices_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IPassportClientServices_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IPassportClientServices_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IPassportClientServices_MemberExists(This,bstrUser,bstrPassword,pvfExists) (This)->lpVtbl->MemberExists(This,bstrUser,bstrPassword,pvfExists)
#endif
#endif
  HRESULT WINAPI IPassportClientServices_MemberExists_Proxy(IPassportClientServices *This,BSTR bstrUser,BSTR bstrPassword,VARIANT_BOOL *pvfExists);
  void __RPC_STUB IPassportClientServices_MemberExists_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_PassportClientServices;
#ifdef __cplusplus
  class PassportClientServices;
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0287_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0287_v0_0_s_ifspec;
#ifndef __IAutoComplete_INTERFACE_DEFINED__
#define __IAutoComplete_INTERFACE_DEFINED__
  typedef IAutoComplete *LPAUTOCOMPLETE;

  EXTERN_C const IID IID_IAutoComplete;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IAutoComplete : public IUnknown {
  public:
    virtual HRESULT WINAPI Init(HWND hwndEdit,IUnknown *punkACL,LPCOLESTR pwszRegKeyPath,LPCOLESTR pwszQuickComplete) = 0;
    virtual HRESULT WINAPI Enable(WINBOOL fEnable) = 0;
  };
#else
  typedef struct IAutoCompleteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IAutoComplete *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IAutoComplete *This);
      ULONG (WINAPI *Release)(IAutoComplete *This);
      HRESULT (WINAPI *Init)(IAutoComplete *This,HWND hwndEdit,IUnknown *punkACL,LPCOLESTR pwszRegKeyPath,LPCOLESTR pwszQuickComplete);
      HRESULT (WINAPI *Enable)(IAutoComplete *This,WINBOOL fEnable);
    END_INTERFACE
  } IAutoCompleteVtbl;
  struct IAutoComplete {
    CONST_VTBL struct IAutoCompleteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IAutoComplete_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAutoComplete_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAutoComplete_Release(This) (This)->lpVtbl->Release(This)
#define IAutoComplete_Init(This,hwndEdit,punkACL,pwszRegKeyPath,pwszQuickComplete) (This)->lpVtbl->Init(This,hwndEdit,punkACL,pwszRegKeyPath,pwszQuickComplete)
#define IAutoComplete_Enable(This,fEnable) (This)->lpVtbl->Enable(This,fEnable)
#endif
#endif
  HRESULT WINAPI IAutoComplete_Init_Proxy(IAutoComplete *This,HWND hwndEdit,IUnknown *punkACL,LPCOLESTR pwszRegKeyPath,LPCOLESTR pwszQuickComplete);
  void __RPC_STUB IAutoComplete_Init_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAutoComplete_Enable_Proxy(IAutoComplete *This,WINBOOL fEnable);
  void __RPC_STUB IAutoComplete_Enable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IAutoComplete2_INTERFACE_DEFINED__
#define __IAutoComplete2_INTERFACE_DEFINED__
  typedef IAutoComplete2 *LPAUTOCOMPLETE2;

  typedef enum _tagAUTOCOMPLETEOPTIONS {
    ACO_NONE = 0,ACO_AUTOSUGGEST = 0x1,ACO_AUTOAPPEND = 0x2,ACO_SEARCH = 0x4,ACO_FILTERPREFIXES = 0x8,ACO_USETAB = 0x10,ACO_UPDOWNKEYDROPSLIST = 0x20,
    ACO_RTLREADING = 0x40
  } AUTOCOMPLETEOPTIONS;

  EXTERN_C const IID IID_IAutoComplete2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IAutoComplete2 : public IAutoComplete {
  public:
    virtual HRESULT WINAPI SetOptions(DWORD dwFlag) = 0;
    virtual HRESULT WINAPI GetOptions(DWORD *pdwFlag) = 0;
  };
#else
  typedef struct IAutoComplete2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IAutoComplete2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IAutoComplete2 *This);
      ULONG (WINAPI *Release)(IAutoComplete2 *This);
      HRESULT (WINAPI *Init)(IAutoComplete2 *This,HWND hwndEdit,IUnknown *punkACL,LPCOLESTR pwszRegKeyPath,LPCOLESTR pwszQuickComplete);
      HRESULT (WINAPI *Enable)(IAutoComplete2 *This,WINBOOL fEnable);
      HRESULT (WINAPI *SetOptions)(IAutoComplete2 *This,DWORD dwFlag);
      HRESULT (WINAPI *GetOptions)(IAutoComplete2 *This,DWORD *pdwFlag);
    END_INTERFACE
  } IAutoComplete2Vtbl;
  struct IAutoComplete2 {
    CONST_VTBL struct IAutoComplete2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IAutoComplete2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAutoComplete2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAutoComplete2_Release(This) (This)->lpVtbl->Release(This)
#define IAutoComplete2_Init(This,hwndEdit,punkACL,pwszRegKeyPath,pwszQuickComplete) (This)->lpVtbl->Init(This,hwndEdit,punkACL,pwszRegKeyPath,pwszQuickComplete)
#define IAutoComplete2_Enable(This,fEnable) (This)->lpVtbl->Enable(This,fEnable)
#define IAutoComplete2_SetOptions(This,dwFlag) (This)->lpVtbl->SetOptions(This,dwFlag)
#define IAutoComplete2_GetOptions(This,pdwFlag) (This)->lpVtbl->GetOptions(This,pdwFlag)
#endif
#endif
  HRESULT WINAPI IAutoComplete2_SetOptions_Proxy(IAutoComplete2 *This,DWORD dwFlag);
  void __RPC_STUB IAutoComplete2_SetOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAutoComplete2_GetOptions_Proxy(IAutoComplete2 *This,DWORD *pdwFlag);
  void __RPC_STUB IAutoComplete2_GetOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0289_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0289_v0_0_s_ifspec;
#ifndef __IEnumACString_INTERFACE_DEFINED__
#define __IEnumACString_INTERFACE_DEFINED__
  typedef IEnumACString *PENUMACSTRING;
  typedef IEnumACString *LPENUMACSTRING;

  typedef enum _tagACENUMOPTION {
    ACEO_NONE = 0,ACEO_MOSTRECENTFIRST = 0x1,ACEO_FIRSTUNUSED = 0x10000
  } ACENUMOPTION;

  EXTERN_C const IID IID_IEnumACString;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumACString : public IEnumString {
  public:
    virtual HRESULT WINAPI NextItem(LPOLESTR pszUrl,ULONG cchMax,ULONG *pulSortIndex) = 0;
    virtual HRESULT WINAPI SetEnumOptions(DWORD dwOptions) = 0;
    virtual HRESULT WINAPI GetEnumOptions(DWORD *pdwOptions) = 0;
  };
#else
  typedef struct IEnumACStringVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumACString *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumACString *This);
      ULONG (WINAPI *Release)(IEnumACString *This);
      HRESULT (WINAPI *Next)(IEnumACString *This,ULONG celt,LPOLESTR *rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumACString *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumACString *This);
      HRESULT (WINAPI *Clone)(IEnumACString *This,IEnumString **ppenum);
      HRESULT (WINAPI *NextItem)(IEnumACString *This,LPOLESTR pszUrl,ULONG cchMax,ULONG *pulSortIndex);
      HRESULT (WINAPI *SetEnumOptions)(IEnumACString *This,DWORD dwOptions);
      HRESULT (WINAPI *GetEnumOptions)(IEnumACString *This,DWORD *pdwOptions);
    END_INTERFACE
  } IEnumACStringVtbl;
  struct IEnumACString {
    CONST_VTBL struct IEnumACStringVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumACString_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumACString_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumACString_Release(This) (This)->lpVtbl->Release(This)
#define IEnumACString_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumACString_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumACString_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumACString_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#define IEnumACString_NextItem(This,pszUrl,cchMax,pulSortIndex) (This)->lpVtbl->NextItem(This,pszUrl,cchMax,pulSortIndex)
#define IEnumACString_SetEnumOptions(This,dwOptions) (This)->lpVtbl->SetEnumOptions(This,dwOptions)
#define IEnumACString_GetEnumOptions(This,pdwOptions) (This)->lpVtbl->GetEnumOptions(This,pdwOptions)
#endif
#endif
  HRESULT WINAPI IEnumACString_NextItem_Proxy(IEnumACString *This,LPOLESTR pszUrl,ULONG cchMax,ULONG *pulSortIndex);
  void __RPC_STUB IEnumACString_NextItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumACString_SetEnumOptions_Proxy(IEnumACString *This,DWORD dwOptions);
  void __RPC_STUB IEnumACString_SetEnumOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumACString_GetEnumOptions_Proxy(IEnumACString *This,DWORD *pdwOptions);
  void __RPC_STUB IEnumACString_GetEnumOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0290_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_shldisp_0290_v0_0_s_ifspec;
#ifndef __IAsyncOperation_INTERFACE_DEFINED__
#define __IAsyncOperation_INTERFACE_DEFINED__
  typedef IAsyncOperation *LPASYNCOPERATION;

  EXTERN_C const IID IID_IAsyncOperation;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IAsyncOperation : public IUnknown {
  public:
    virtual HRESULT WINAPI SetAsyncMode(WINBOOL fDoOpAsync) = 0;
    virtual HRESULT WINAPI GetAsyncMode(WINBOOL *pfIsOpAsync) = 0;
    virtual HRESULT WINAPI StartOperation(IBindCtx *pbcReserved) = 0;
    virtual HRESULT WINAPI InOperation(WINBOOL *pfInAsyncOp) = 0;
    virtual HRESULT WINAPI EndOperation(HRESULT hResult,IBindCtx *pbcReserved,DWORD dwEffects) = 0;
  };
#else
  typedef struct IAsyncOperationVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IAsyncOperation *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IAsyncOperation *This);
      ULONG (WINAPI *Release)(IAsyncOperation *This);
      HRESULT (WINAPI *SetAsyncMode)(IAsyncOperation *This,WINBOOL fDoOpAsync);
      HRESULT (WINAPI *GetAsyncMode)(IAsyncOperation *This,WINBOOL *pfIsOpAsync);
      HRESULT (WINAPI *StartOperation)(IAsyncOperation *This,IBindCtx *pbcReserved);
      HRESULT (WINAPI *InOperation)(IAsyncOperation *This,WINBOOL *pfInAsyncOp);
      HRESULT (WINAPI *EndOperation)(IAsyncOperation *This,HRESULT hResult,IBindCtx *pbcReserved,DWORD dwEffects);
    END_INTERFACE
  } IAsyncOperationVtbl;
  struct IAsyncOperation {
    CONST_VTBL struct IAsyncOperationVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IAsyncOperation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IAsyncOperation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IAsyncOperation_Release(This) (This)->lpVtbl->Release(This)
#define IAsyncOperation_SetAsyncMode(This,fDoOpAsync) (This)->lpVtbl->SetAsyncMode(This,fDoOpAsync)
#define IAsyncOperation_GetAsyncMode(This,pfIsOpAsync) (This)->lpVtbl->GetAsyncMode(This,pfIsOpAsync)
#define IAsyncOperation_StartOperation(This,pbcReserved) (This)->lpVtbl->StartOperation(This,pbcReserved)
#define IAsyncOperation_InOperation(This,pfInAsyncOp) (This)->lpVtbl->InOperation(This,pfInAsyncOp)
#define IAsyncOperation_EndOperation(This,hResult,pbcReserved,dwEffects) (This)->lpVtbl->EndOperation(This,hResult,pbcReserved,dwEffects)
#endif
#endif
  HRESULT WINAPI IAsyncOperation_SetAsyncMode_Proxy(IAsyncOperation *This,WINBOOL fDoOpAsync);
  void __RPC_STUB IAsyncOperation_SetAsyncMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAsyncOperation_GetAsyncMode_Proxy(IAsyncOperation *This,WINBOOL *pfIsOpAsync);
  void __RPC_STUB IAsyncOperation_GetAsyncMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAsyncOperation_StartOperation_Proxy(IAsyncOperation *This,IBindCtx *pbcReserved);
  void __RPC_STUB IAsyncOperation_StartOperation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAsyncOperation_InOperation_Proxy(IAsyncOperation *This,WINBOOL *pfInAsyncOp);
  void __RPC_STUB IAsyncOperation_InOperation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IAsyncOperation_EndOperation_Proxy(IAsyncOperation *This,HRESULT hResult,IBindCtx *pbcReserved,DWORD dwEffects);
  void __RPC_STUB IAsyncOperation_EndOperation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef __cplusplus
}
#endif
#endif
