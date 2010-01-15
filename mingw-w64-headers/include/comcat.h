/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
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

#ifndef __comcat_h__
#define __comcat_h__

#ifndef __IEnumGUID_FWD_DEFINED__
#define __IEnumGUID_FWD_DEFINED__
typedef struct IEnumGUID IEnumGUID;
#endif

#ifndef __IEnumCATEGORYINFO_FWD_DEFINED__
#define __IEnumCATEGORYINFO_FWD_DEFINED__
typedef struct IEnumCATEGORYINFO IEnumCATEGORYINFO;
#endif

#ifndef __ICatRegister_FWD_DEFINED__
#define __ICatRegister_FWD_DEFINED__
typedef struct ICatRegister ICatRegister;
#endif

#ifndef __ICatInformation_FWD_DEFINED__
#define __ICatInformation_FWD_DEFINED__
typedef struct ICatInformation ICatInformation;
#endif

#include "unknwn.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

  EXTERN_C const CLSID CLSID_StdComponentCategoriesMgr;

  typedef GUID CATID;

  typedef REFGUID REFCATID;

#define IID_IEnumCLSID IID_IEnumGUID
#define IEnumCLSID IEnumGUID
#define LPENUMCLSID LPENUMGUID
#define CATID_NULL GUID_NULL
#define IsEqualCATID(rcatid1,rcatid2) IsEqualGUID(rcatid1,rcatid2)
#define IID_IEnumCATID IID_IEnumGUID
#define IEnumCATID IEnumGUID

  EXTERN_C const CATID CATID_Insertable;
  EXTERN_C const CATID CATID_Control;
  EXTERN_C const CATID CATID_Programmable;
  EXTERN_C const CATID CATID_IsShortcut;
  EXTERN_C const CATID CATID_NeverShowExt;
  EXTERN_C const CATID CATID_DocObject;
  EXTERN_C const CATID CATID_Printable;
  EXTERN_C const CATID CATID_RequiresDataPathHost;
  EXTERN_C const CATID CATID_PersistsToMoniker;
  EXTERN_C const CATID CATID_PersistsToStorage;
  EXTERN_C const CATID CATID_PersistsToStreamInit;
  EXTERN_C const CATID CATID_PersistsToStream;
  EXTERN_C const CATID CATID_PersistsToMemory;
  EXTERN_C const CATID CATID_PersistsToFile;
  EXTERN_C const CATID CATID_PersistsToPropertyBag;
  EXTERN_C const CATID CATID_InternetAware;
  EXTERN_C const CATID CATID_DesignTimeUIActivatableControl;

#ifndef _LPENUMGUID_DEFINED
#define _LPENUMGUID_DEFINED

  extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0000_v0_0_s_ifspec;

#ifndef __IEnumGUID_INTERFACE_DEFINED__
#define __IEnumGUID_INTERFACE_DEFINED__
  typedef IEnumGUID *LPENUMGUID;
  EXTERN_C const IID IID_IEnumGUID;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumGUID : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,GUID *rgelt,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumGUID **ppenum) = 0;
  };
#else
  typedef struct IEnumGUIDVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumGUID *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumGUID *This);
      ULONG (WINAPI *Release)(IEnumGUID *This);
      HRESULT (WINAPI *Next)(IEnumGUID *This,ULONG celt,GUID *rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumGUID *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumGUID *This);
      HRESULT (WINAPI *Clone)(IEnumGUID *This,IEnumGUID **ppenum);
    END_INTERFACE
  } IEnumGUIDVtbl;
  struct IEnumGUID {
    CONST_VTBL struct IEnumGUIDVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumGUID_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumGUID_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumGUID_Release(This) (This)->lpVtbl->Release(This)
#define IEnumGUID_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumGUID_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumGUID_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumGUID_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#endif
#endif
  HRESULT WINAPI IEnumGUID_Next_Proxy(IEnumGUID *This,ULONG celt,GUID *rgelt,ULONG *pceltFetched);
  void __RPC_STUB IEnumGUID_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumGUID_Skip_Proxy(IEnumGUID *This,ULONG celt);
  void __RPC_STUB IEnumGUID_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumGUID_Reset_Proxy(IEnumGUID *This);
  void __RPC_STUB IEnumGUID_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumGUID_Clone_Proxy(IEnumGUID *This,IEnumGUID **ppenum);
  void __RPC_STUB IEnumGUID_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPENUMCATEGORYINFO_DEFINED
#define _LPENUMCATEGORYINFO_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0009_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0009_v0_0_s_ifspec;
#ifndef __IEnumCATEGORYINFO_INTERFACE_DEFINED__
#define __IEnumCATEGORYINFO_INTERFACE_DEFINED__
  typedef IEnumCATEGORYINFO *LPENUMCATEGORYINFO;
  typedef struct tagCATEGORYINFO {
    CATID catid;
    LCID lcid;
    OLECHAR szDescription[128 ];
  } CATEGORYINFO;

  typedef struct tagCATEGORYINFO *LPCATEGORYINFO;
  EXTERN_C const IID IID_IEnumCATEGORYINFO;

#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumCATEGORYINFO : public IUnknown {
  public:
    virtual HRESULT WINAPI Next(ULONG celt,CATEGORYINFO *rgelt,ULONG *pceltFetched) = 0;
    virtual HRESULT WINAPI Skip(ULONG celt) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Clone(IEnumCATEGORYINFO **ppenum) = 0;
  };
#else
  typedef struct IEnumCATEGORYINFOVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumCATEGORYINFO *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumCATEGORYINFO *This);
      ULONG (WINAPI *Release)(IEnumCATEGORYINFO *This);
      HRESULT (WINAPI *Next)(IEnumCATEGORYINFO *This,ULONG celt,CATEGORYINFO *rgelt,ULONG *pceltFetched);
      HRESULT (WINAPI *Skip)(IEnumCATEGORYINFO *This,ULONG celt);
      HRESULT (WINAPI *Reset)(IEnumCATEGORYINFO *This);
      HRESULT (WINAPI *Clone)(IEnumCATEGORYINFO *This,IEnumCATEGORYINFO **ppenum);
    END_INTERFACE
  } IEnumCATEGORYINFOVtbl;
  struct IEnumCATEGORYINFO {
    CONST_VTBL struct IEnumCATEGORYINFOVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumCATEGORYINFO_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumCATEGORYINFO_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumCATEGORYINFO_Release(This) (This)->lpVtbl->Release(This)
#define IEnumCATEGORYINFO_Next(This,celt,rgelt,pceltFetched) (This)->lpVtbl->Next(This,celt,rgelt,pceltFetched)
#define IEnumCATEGORYINFO_Skip(This,celt) (This)->lpVtbl->Skip(This,celt)
#define IEnumCATEGORYINFO_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumCATEGORYINFO_Clone(This,ppenum) (This)->lpVtbl->Clone(This,ppenum)
#endif
#endif
  HRESULT WINAPI IEnumCATEGORYINFO_Next_Proxy(IEnumCATEGORYINFO *This,ULONG celt,CATEGORYINFO *rgelt,ULONG *pceltFetched);
  void __RPC_STUB IEnumCATEGORYINFO_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumCATEGORYINFO_Skip_Proxy(IEnumCATEGORYINFO *This,ULONG celt);
  void __RPC_STUB IEnumCATEGORYINFO_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumCATEGORYINFO_Reset_Proxy(IEnumCATEGORYINFO *This);
  void __RPC_STUB IEnumCATEGORYINFO_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumCATEGORYINFO_Clone_Proxy(IEnumCATEGORYINFO *This,IEnumCATEGORYINFO **ppenum);
  void __RPC_STUB IEnumCATEGORYINFO_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPCATREGISTER_DEFINED
#define _LPCATREGISTER_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0010_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0010_v0_0_s_ifspec;
#ifndef __ICatRegister_INTERFACE_DEFINED__
#define __ICatRegister_INTERFACE_DEFINED__
  typedef ICatRegister *LPCATREGISTER;
  EXTERN_C const IID IID_ICatRegister;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICatRegister : public IUnknown {
  public:
    virtual HRESULT WINAPI RegisterCategories(ULONG cCategories,CATEGORYINFO rgCategoryInfo[]) = 0;
    virtual HRESULT WINAPI UnRegisterCategories(ULONG cCategories,CATID rgcatid[]) = 0;
    virtual HRESULT WINAPI RegisterClassImplCategories(REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]) = 0;
    virtual HRESULT WINAPI UnRegisterClassImplCategories(REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]) = 0;
    virtual HRESULT WINAPI RegisterClassReqCategories(REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]) = 0;
    virtual HRESULT WINAPI UnRegisterClassReqCategories(REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]) = 0;
  };
#else
  typedef struct ICatRegisterVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICatRegister *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICatRegister *This);
      ULONG (WINAPI *Release)(ICatRegister *This);
      HRESULT (WINAPI *RegisterCategories)(ICatRegister *This,ULONG cCategories,CATEGORYINFO rgCategoryInfo[]);
      HRESULT (WINAPI *UnRegisterCategories)(ICatRegister *This,ULONG cCategories,CATID rgcatid[]);
      HRESULT (WINAPI *RegisterClassImplCategories)(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
      HRESULT (WINAPI *UnRegisterClassImplCategories)(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
      HRESULT (WINAPI *RegisterClassReqCategories)(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
      HRESULT (WINAPI *UnRegisterClassReqCategories)(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
    END_INTERFACE
  } ICatRegisterVtbl;
  struct ICatRegister {
    CONST_VTBL struct ICatRegisterVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICatRegister_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICatRegister_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICatRegister_Release(This) (This)->lpVtbl->Release(This)
#define ICatRegister_RegisterCategories(This,cCategories,rgCategoryInfo) (This)->lpVtbl->RegisterCategories(This,cCategories,rgCategoryInfo)
#define ICatRegister_UnRegisterCategories(This,cCategories,rgcatid) (This)->lpVtbl->UnRegisterCategories(This,cCategories,rgcatid)
#define ICatRegister_RegisterClassImplCategories(This,rclsid,cCategories,rgcatid) (This)->lpVtbl->RegisterClassImplCategories(This,rclsid,cCategories,rgcatid)
#define ICatRegister_UnRegisterClassImplCategories(This,rclsid,cCategories,rgcatid) (This)->lpVtbl->UnRegisterClassImplCategories(This,rclsid,cCategories,rgcatid)
#define ICatRegister_RegisterClassReqCategories(This,rclsid,cCategories,rgcatid) (This)->lpVtbl->RegisterClassReqCategories(This,rclsid,cCategories,rgcatid)
#define ICatRegister_UnRegisterClassReqCategories(This,rclsid,cCategories,rgcatid) (This)->lpVtbl->UnRegisterClassReqCategories(This,rclsid,cCategories,rgcatid)
#endif
#endif
  HRESULT WINAPI ICatRegister_RegisterCategories_Proxy(ICatRegister *This,ULONG cCategories,CATEGORYINFO rgCategoryInfo[]);
  void __RPC_STUB ICatRegister_RegisterCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatRegister_UnRegisterCategories_Proxy(ICatRegister *This,ULONG cCategories,CATID rgcatid[]);
  void __RPC_STUB ICatRegister_UnRegisterCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatRegister_RegisterClassImplCategories_Proxy(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
  void __RPC_STUB ICatRegister_RegisterClassImplCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatRegister_UnRegisterClassImplCategories_Proxy(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
  void __RPC_STUB ICatRegister_UnRegisterClassImplCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatRegister_RegisterClassReqCategories_Proxy(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
  void __RPC_STUB ICatRegister_RegisterClassReqCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatRegister_UnRegisterClassReqCategories_Proxy(ICatRegister *This,REFCLSID rclsid,ULONG cCategories,CATID rgcatid[]);
  void __RPC_STUB ICatRegister_UnRegisterClassReqCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifndef _LPCATINFORMATION_DEFINED
#define _LPCATINFORMATION_DEFINED
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0011_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0011_v0_0_s_ifspec;
#ifndef __ICatInformation_INTERFACE_DEFINED__
#define __ICatInformation_INTERFACE_DEFINED__
  typedef ICatInformation *LPCATINFORMATION;
  EXTERN_C const IID IID_ICatInformation;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ICatInformation : public IUnknown {
  public:
    virtual HRESULT WINAPI EnumCategories(LCID lcid,IEnumCATEGORYINFO **ppenumCategoryInfo) = 0;
    virtual HRESULT WINAPI GetCategoryDesc(REFCATID rcatid,LCID lcid,LPWSTR *pszDesc) = 0;
    virtual HRESULT WINAPI EnumClassesOfCategories(ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[],IEnumGUID **ppenumClsid) = 0;
    virtual HRESULT WINAPI IsClassOfCategories(REFCLSID rclsid,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[]) = 0;
    virtual HRESULT WINAPI EnumImplCategoriesOfClass(REFCLSID rclsid,IEnumGUID **ppenumCatid) = 0;
    virtual HRESULT WINAPI EnumReqCategoriesOfClass(REFCLSID rclsid,IEnumGUID **ppenumCatid) = 0;
  };
#else
  typedef struct ICatInformationVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ICatInformation *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ICatInformation *This);
      ULONG (WINAPI *Release)(ICatInformation *This);
      HRESULT (WINAPI *EnumCategories)(ICatInformation *This,LCID lcid,IEnumCATEGORYINFO **ppenumCategoryInfo);
      HRESULT (WINAPI *GetCategoryDesc)(ICatInformation *This,REFCATID rcatid,LCID lcid,LPWSTR *pszDesc);
      HRESULT (WINAPI *EnumClassesOfCategories)(ICatInformation *This,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[],IEnumGUID **ppenumClsid);
      HRESULT (WINAPI *IsClassOfCategories)(ICatInformation *This,REFCLSID rclsid,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[]);
      HRESULT (WINAPI *EnumImplCategoriesOfClass)(ICatInformation *This,REFCLSID rclsid,IEnumGUID **ppenumCatid);
      HRESULT (WINAPI *EnumReqCategoriesOfClass)(ICatInformation *This,REFCLSID rclsid,IEnumGUID **ppenumCatid);
    END_INTERFACE
  } ICatInformationVtbl;
  struct ICatInformation {
    CONST_VTBL struct ICatInformationVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ICatInformation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ICatInformation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ICatInformation_Release(This) (This)->lpVtbl->Release(This)
#define ICatInformation_EnumCategories(This,lcid,ppenumCategoryInfo) (This)->lpVtbl->EnumCategories(This,lcid,ppenumCategoryInfo)
#define ICatInformation_GetCategoryDesc(This,rcatid,lcid,pszDesc) (This)->lpVtbl->GetCategoryDesc(This,rcatid,lcid,pszDesc)
#define ICatInformation_EnumClassesOfCategories(This,cImplemented,rgcatidImpl,cRequired,rgcatidReq,ppenumClsid) (This)->lpVtbl->EnumClassesOfCategories(This,cImplemented,rgcatidImpl,cRequired,rgcatidReq,ppenumClsid)
#define ICatInformation_IsClassOfCategories(This,rclsid,cImplemented,rgcatidImpl,cRequired,rgcatidReq) (This)->lpVtbl->IsClassOfCategories(This,rclsid,cImplemented,rgcatidImpl,cRequired,rgcatidReq)
#define ICatInformation_EnumImplCategoriesOfClass(This,rclsid,ppenumCatid) (This)->lpVtbl->EnumImplCategoriesOfClass(This,rclsid,ppenumCatid)
#define ICatInformation_EnumReqCategoriesOfClass(This,rclsid,ppenumCatid) (This)->lpVtbl->EnumReqCategoriesOfClass(This,rclsid,ppenumCatid)
#endif
#endif
  HRESULT WINAPI ICatInformation_EnumCategories_Proxy(ICatInformation *This,LCID lcid,IEnumCATEGORYINFO **ppenumCategoryInfo);
  void __RPC_STUB ICatInformation_EnumCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatInformation_GetCategoryDesc_Proxy(ICatInformation *This,REFCATID rcatid,LCID lcid,LPWSTR *pszDesc);
  void __RPC_STUB ICatInformation_GetCategoryDesc_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatInformation_RemoteEnumClassesOfCategories_Proxy(ICatInformation *This,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[],IEnumGUID **ppenumClsid);
  void __RPC_STUB ICatInformation_RemoteEnumClassesOfCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatInformation_RemoteIsClassOfCategories_Proxy(ICatInformation *This,REFCLSID rclsid,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[]);
  void __RPC_STUB ICatInformation_RemoteIsClassOfCategories_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatInformation_EnumImplCategoriesOfClass_Proxy(ICatInformation *This,REFCLSID rclsid,IEnumGUID **ppenumCatid);
  void __RPC_STUB ICatInformation_EnumImplCategoriesOfClass_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ICatInformation_EnumReqCategoriesOfClass_Proxy(ICatInformation *This,REFCLSID rclsid,IEnumGUID **ppenumCatid);
  void __RPC_STUB ICatInformation_EnumReqCategoriesOfClass_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_comcat_0012_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_comcat_0012_v0_0_s_ifspec;
  HRESULT WINAPI ICatInformation_EnumClassesOfCategories_Proxy(ICatInformation *This,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[],IEnumGUID **ppenumClsid);
  HRESULT WINAPI ICatInformation_EnumClassesOfCategories_Stub(ICatInformation *This,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[],IEnumGUID **ppenumClsid);
  HRESULT WINAPI ICatInformation_IsClassOfCategories_Proxy(ICatInformation *This,REFCLSID rclsid,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[]);
  HRESULT WINAPI ICatInformation_IsClassOfCategories_Stub(ICatInformation *This,REFCLSID rclsid,ULONG cImplemented,CATID rgcatidImpl[],ULONG cRequired,CATID rgcatidReq[]);
#ifdef __cplusplus
}
#endif
#endif
