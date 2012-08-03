/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ADOCTINT_H_
#define _ADOCTINT_H_

#include <tchar.h>

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif
#include "rpc.h"
#include "rpcndr.h"
#ifndef __m_adocat_h__
#define __m_adocat_h__

#ifndef ___ADOCollection_FWD_DEFINED__
#define ___ADOCollection_FWD_DEFINED__
typedef struct _ADOADOCollection _ADOCollection;
typedef struct _ADOADOCollection _ADOADOCollection;
#endif
#ifndef ___ADODynaCollection_FWD_DEFINED__
#define ___ADODynaCollection_FWD_DEFINED__
typedef struct _ADODynaADOCollection _ADODynaCollection;
#endif
#ifndef ___Catalog_FWD_DEFINED__
#define ___Catalog_FWD_DEFINED__
typedef struct _ADOCatalog _Catalog;
#endif
#ifndef ___Table_FWD_DEFINED__
#define ___Table_FWD_DEFINED__
typedef struct _ADOTable _Table;
#endif
#ifndef ___Group25_FWD_DEFINED__
#define ___Group25_FWD_DEFINED__
typedef struct _Group25 _Group25;
#endif
#ifndef ___Group_FWD_DEFINED__
#define ___Group_FWD_DEFINED__
typedef struct _ADOGroup _Group;
#endif
#ifndef ___User25_FWD_DEFINED__
#define ___User25_FWD_DEFINED__
typedef struct _User25 _User25;
#endif
#ifndef ___User_FWD_DEFINED__
#define ___User_FWD_DEFINED__
typedef struct _ADOUser _User;
#endif
#ifndef ___Column_FWD_DEFINED__
#define ___Column_FWD_DEFINED__
typedef struct _ADOColumn _Column;
#endif
#ifndef ___Index_FWD_DEFINED__
#define ___Index_FWD_DEFINED__
typedef struct _ADOIndex _Index;
#endif
#ifndef ___Key_FWD_DEFINED__
#define ___Key_FWD_DEFINED__
typedef struct _ADOKey _Key;
#endif
#ifndef __View_FWD_DEFINED__
#define __View_FWD_DEFINED__
typedef struct ADOView View;
#endif
#ifndef __Procedure_FWD_DEFINED__
#define __Procedure_FWD_DEFINED__
typedef struct ADOProcedure Procedure;
#endif
#ifndef __Catalog_FWD_DEFINED__
#define __Catalog_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOCatalog Catalog;
#else
typedef struct ADOCatalog Catalog;
#endif
#endif
#ifndef __Table_FWD_DEFINED__
#define __Table_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOTable Table;
#else
typedef struct ADOTable Table;
#endif
#endif
#ifndef __Property_FWD_DEFINED__
#define __Property_FWD_DEFINED__
typedef struct ADOProperty Property;
#endif
#ifndef __Group_FWD_DEFINED__
#define __Group_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOGroup Group;
#else
typedef struct ADOGroup Group;
#endif
#endif
#ifndef __User_FWD_DEFINED__
#define __User_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOUser User;
#else
typedef struct ADOUser User;
#endif
#endif
#ifndef __Column_FWD_DEFINED__
#define __Column_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOColumn Column;
#else
typedef struct ADOColumn Column;
#endif
#endif
#ifndef __Index_FWD_DEFINED__
#define __Index_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOIndex Index;
#else
typedef struct ADOIndex Index;
#endif
#endif
#ifndef __Key_FWD_DEFINED__
#define __Key_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOKey Key;
#else
typedef struct ADOKey Key;
#endif
#endif
#ifndef __Tables_FWD_DEFINED__
#define __Tables_FWD_DEFINED__
typedef struct ADOTables Tables;
#endif
#ifndef __Columns_FWD_DEFINED__
#define __Columns_FWD_DEFINED__
typedef struct ADOColumns Columns;
#endif
#ifndef __Procedures_FWD_DEFINED__
#define __Procedures_FWD_DEFINED__
typedef struct ADOProcedures Procedures;
#endif
#ifndef __Views_FWD_DEFINED__
#define __Views_FWD_DEFINED__
typedef struct ADOViews Views;
#endif
#ifndef __Indexes_FWD_DEFINED__
#define __Indexes_FWD_DEFINED__
typedef struct ADOIndexes Indexes;
#endif
#ifndef __Keys_FWD_DEFINED__
#define __Keys_FWD_DEFINED__
typedef struct ADOKeys Keys;
#endif
#ifndef __Users_FWD_DEFINED__
#define __Users_FWD_DEFINED__
typedef struct ADOUsers Users;
#endif
#ifndef __Groups_FWD_DEFINED__
#define __Groups_FWD_DEFINED__
typedef struct ADOGroups Groups;
#endif
#ifndef __Properties_FWD_DEFINED__
#define __Properties_FWD_DEFINED__
typedef struct ADOProperties Properties;
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

  typedef enum RuleEnum {
    adRINone = 0,adRICascade = 1,adRISetNull = 2,adRISetDefault = 3
  } RuleEnum;

  typedef enum KeyTypeEnum {
    adKeyPrimary = 1,adKeyForeign = 2,adKeyUnique = 3
  } KeyTypeEnum;

  typedef enum ActionEnum {
    adAccessGrant = 1,adAccessSet = 2,adAccessDeny = 3,adAccessRevoke = 4
  } ActionEnum;

  typedef enum ColumnAttributesEnum {
    adColFixed = 1,adColNullable = 2
  } ColumnAttributesEnum;

  typedef enum SortOrderEnum {
    adSortAscending = 1,adSortDescending = 2
  } SortOrderEnum;

  typedef enum RightsEnum {
    adRightNone = 0,adRightDrop = 0x100,adRightExclusive = 0x200,adRightReadDesign = 0x400,adRightWriteDesign = 0x800,
    adRightWithGrant = 0x1000,adRightReference = 0x2000,adRightCreate = 0x4000,adRightInsert = 0x8000,adRightDelete = 0x10000,
    adRightReadPermissions = 0x20000,adRightWritePermissions = 0x40000,adRightWriteOwner = 0x80000,adRightMaximumAllowed = 0x2000000,
    adRightFull = 0x10000000,adRightExecute = 0x20000000,adRightUpdate = 0x40000000,adRightRead = 0x80000000
  } RightsEnum;

#ifdef _ADOINT_H_
  typedef class dummy dummy;
#else
  typedef enum DataTypeEnum {
    adEmpty = 0,adTinyInt = 16,adSmallInt = 2,adInteger = 3,adBigInt = 20,adUnsignedTinyInt = 17,adUnsignedSmallInt = 18,adUnsignedInt = 19,
    adUnsignedBigInt = 21,adSingle = 4,adDouble = 5,adCurrency = 6,adDecimal = 14,adNumeric = 131,adBoolean = 11,adError = 10,adUserDefined = 132,
    adVariant = 12,adIDispatch = 9,adIUnknown = 13,adGUID = 72,adDate = 7,adDBDate = 133,adDBTime = 134,adDBTimeStamp = 135,adBSTR = 8,adChar = 129,
    adVarChar = 200,adLongVarChar = 201,adWChar = 130,adVarWChar = 202,adLongVarWChar = 203,adBinary = 128,adVarBinary = 204,adLongVarBinary = 205,
    adChapter = 136,adFileTime = 64,adPropVariant = 138,adVarNumeric = 139
  } DataTypeEnum;
#endif

  typedef enum AllowNullsEnum {
    adIndexNullsAllow = 0,adIndexNullsDisallow = 1,adIndexNullsIgnore = 2,adIndexNullsIgnoreAny = 4
  } AllowNullsEnum;

  typedef enum ObjectTypeEnum {
    adPermObjProviderSpecific = -1,adPermObjTable = 1,adPermObjColumn = 2,adPermObjDatabase = 3,adPermObjProcedure = 4,adPermObjView = 5
  } ObjectTypeEnum;

  typedef enum InheritTypeEnum {
    adInheritNone = 0,adInheritObjects = 1,adInheritContainers = 2,adInheritBoth = 3,adInheritNoPropogate = 4
  } InheritTypeEnum;

  extern RPC_IF_HANDLE __MIDL_itf_AdoCat_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_AdoCat_0000_v0_0_s_ifspec;
#ifndef __ADOX_LIBRARY_DEFINED__
#define __ADOX_LIBRARY_DEFINED__

  EXTERN_C const IID LIBID_ADOX;
#ifndef ___ADOCollection_INTERFACE_DEFINED__
#define ___ADOCollection_INTERFACE_DEFINED__
  EXTERN_C const IID IID__ADOCollection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOADOCollection : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(__LONG32 *c) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppvObject) = 0;
    virtual HRESULT WINAPI Refresh(void) = 0;
  };
#else
  typedef struct _ADOCollectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOADOCollection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOADOCollection *This);
      ULONG (WINAPI *Release)(_ADOADOCollection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOADOCollection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOADOCollection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOADOCollection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOADOCollection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(_ADOADOCollection *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(_ADOADOCollection *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(_ADOADOCollection *This);
    END_INTERFACE
  } _ADOCollectionVtbl;
  struct _ADOCollection {
    CONST_VTBL struct _ADOCollectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _ADOCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _ADOCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _ADOCollection_Release(This) (This)->lpVtbl->Release(This)
#define _ADOCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _ADOCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _ADOCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _ADOCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Collection_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define _ADOCollection__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define _ADOCollection_Refresh(This) (This)->lpVtbl->Refresh(This)
#endif
#endif
  HRESULT WINAPI _Collection_get_Count_Proxy(_ADOADOCollection *This,__LONG32 *c);
  void __RPC_STUB _Collection_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADOCollection__NewEnum_Proxy(_ADOADOCollection *This,IUnknown **ppvObject);
  void __RPC_STUB _ADOCollection__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADOCollection_Refresh_Proxy(_ADOADOCollection *This);
  void __RPC_STUB _ADOCollection_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___ADODynaCollection_INTERFACE_DEFINED__
#define ___ADODynaCollection_INTERFACE_DEFINED__
  EXTERN_C const IID IID__ADODynaCollection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADODynaADOCollection : public _ADOCollection {
  public:
    virtual HRESULT WINAPI Append(IDispatch *Object) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct _ADODynaCollectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADODynaADOCollection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADODynaADOCollection *This);
      ULONG (WINAPI *Release)(_ADODynaADOCollection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADODynaADOCollection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADODynaADOCollection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADODynaADOCollection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADODynaADOCollection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(_ADODynaADOCollection *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(_ADODynaADOCollection *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(_ADODynaADOCollection *This);
      HRESULT (WINAPI *Append)(_ADODynaADOCollection *This,IDispatch *Object);
      HRESULT (WINAPI *Delete)(_ADODynaADOCollection *This,VARIANT Item);
    END_INTERFACE
  } _ADODynaCollectionVtbl;
  struct _ADODynaCollection {
    CONST_VTBL struct _ADODynaCollectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _ADODynaCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _ADODynaCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _ADODynaCollection_Release(This) (This)->lpVtbl->Release(This)
#define _ADODynaCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _ADODynaCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _ADODynaCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _ADODynaCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _DynaCollection_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define _ADODynaCollection__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define _ADODynaCollection_Refresh(This) (This)->lpVtbl->Refresh(This)
#define _ADODynaCollection_Append(This,Object) (This)->lpVtbl->Append(This,Object)
#define _ADODynaCollection_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI _ADODynaCollection_Append_Proxy(_ADODynaADOCollection *This,IDispatch *Object);
  void __RPC_STUB _ADODynaCollection_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADODynaCollection_Delete_Proxy(_ADODynaADOCollection *This,VARIANT Item);
  void __RPC_STUB _ADODynaCollection_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Catalog_INTERFACE_DEFINED__
#define ___Catalog_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Catalog;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOCatalog : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Tables(ADOTables **ppvObject) = 0;
    virtual HRESULT WINAPI get_ActiveConnection(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(VARIANT newVal) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(IDispatch *pCon) = 0;
    virtual HRESULT WINAPI get_Procedures(ADOProcedures **ppvObject) = 0;
    virtual HRESULT WINAPI get_Views(ADOViews **ppvObject) = 0;
    virtual HRESULT WINAPI get_Groups(ADOGroups **ppvObject) = 0;
    virtual HRESULT WINAPI get_Users(ADOUsers **ppvObject) = 0;
    virtual HRESULT WINAPI Create(BSTR ConnectString,VARIANT *Connection) = 0;
    virtual HRESULT WINAPI GetObjectOwner(BSTR ObjectName,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,BSTR *OwnerName) = 0;
    virtual HRESULT WINAPI SetObjectOwner(BSTR ObjectName,ObjectTypeEnum ObjectType,BSTR UserName,VARIANT ObjectTypeId) = 0;
  };
#else
  typedef struct _CatalogVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOCatalog *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOCatalog *This);
      ULONG (WINAPI *Release)(_ADOCatalog *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOCatalog *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOCatalog *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOCatalog *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOCatalog *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Tables)(_ADOCatalog *This,ADOTables **ppvObject);
      HRESULT (WINAPI *get_ActiveConnection)(_ADOCatalog *This,VARIANT *pVal);
      HRESULT (WINAPI *put_ActiveConnection)(_ADOCatalog *This,VARIANT newVal);
      HRESULT (WINAPI *putref_ActiveConnection)(_ADOCatalog *This,IDispatch *pCon);
      HRESULT (WINAPI *get_Procedures)(_ADOCatalog *This,ADOProcedures **ppvObject);
      HRESULT (WINAPI *get_Views)(_ADOCatalog *This,ADOViews **ppvObject);
      HRESULT (WINAPI *get_Groups)(_ADOCatalog *This,ADOGroups **ppvObject);
      HRESULT (WINAPI *get_Users)(_ADOCatalog *This,ADOUsers **ppvObject);
      HRESULT (WINAPI *Create)(_ADOCatalog *This,BSTR ConnectString,VARIANT *Connection);

      HRESULT (WINAPI *GetObjectOwner)(_ADOCatalog *This,BSTR ObjectName,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,BSTR *OwnerName);
      HRESULT (WINAPI *SetObjectOwner)(_ADOCatalog *This,BSTR ObjectName,ObjectTypeEnum ObjectType,BSTR UserName,VARIANT ObjectTypeId);
    END_INTERFACE
  } _CatalogVtbl;
  struct _Catalog {
    CONST_VTBL struct _CatalogVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Catalog_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Catalog_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Catalog_Release(This) (This)->lpVtbl->Release(This)
#define _Catalog_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Catalog_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Catalog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Catalog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Catalog_get_Tables(This,ppvObject) (This)->lpVtbl->get_Tables(This,ppvObject)
#define _Catalog_get_ActiveConnection(This,pVal) (This)->lpVtbl->get_ActiveConnection(This,pVal)
#define _Catalog_put_ActiveConnection(This,newVal) (This)->lpVtbl->put_ActiveConnection(This,newVal)
#define _Catalog_putref_ActiveConnection(This,pCon) (This)->lpVtbl->putref_ActiveConnection(This,pCon)
#define _Catalog_get_Procedures(This,ppvObject) (This)->lpVtbl->get_Procedures(This,ppvObject)
#define _Catalog_get_Views(This,ppvObject) (This)->lpVtbl->get_Views(This,ppvObject)
#define _Catalog_get_Groups(This,ppvObject) (This)->lpVtbl->get_Groups(This,ppvObject)
#define _Catalog_get_Users(This,ppvObject) (This)->lpVtbl->get_Users(This,ppvObject)
#define _Catalog_Create(This,ConnectString,Connection) (This)->lpVtbl->Create(This,ConnectString,Connection)
#define _Catalog_GetObjectOwner(This,ObjectName,ObjectType,ObjectTypeId,OwnerName) (This)->lpVtbl->GetObjectOwner(This,ObjectName,ObjectType,ObjectTypeId,OwnerName)
#define _Catalog_SetObjectOwner(This,ObjectName,ObjectType,UserName,ObjectTypeId) (This)->lpVtbl->SetObjectOwner(This,ObjectName,ObjectType,UserName,ObjectTypeId)
#endif
#endif
  HRESULT WINAPI _Catalog_get_Tables_Proxy(_ADOCatalog *This,ADOTables **ppvObject);
  void __RPC_STUB _Catalog_get_Tables_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_get_ActiveConnection_Proxy(_ADOCatalog *This,VARIANT *pVal);
  void __RPC_STUB _Catalog_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_put_ActiveConnection_Proxy(_ADOCatalog *This,VARIANT newVal);
  void __RPC_STUB _Catalog_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_putref_ActiveConnection_Proxy(_ADOCatalog *This,IDispatch *pCon);
  void __RPC_STUB _Catalog_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_get_Procedures_Proxy(_ADOCatalog *This,ADOProcedures **ppvObject);
  void __RPC_STUB _Catalog_get_Procedures_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_get_Views_Proxy(_ADOCatalog *This,ADOViews **ppvObject);
  void __RPC_STUB _Catalog_get_Views_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_get_Groups_Proxy(_ADOCatalog *This,ADOGroups **ppvObject);
  void __RPC_STUB _Catalog_get_Groups_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_get_Users_Proxy(_ADOCatalog *This,ADOUsers **ppvObject);
  void __RPC_STUB _Catalog_get_Users_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_Create_Proxy(_ADOCatalog *This,BSTR ConnectString,VARIANT *Connection);
  void __RPC_STUB _Catalog_Create_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_GetObjectOwner_Proxy(_ADOCatalog *This,BSTR ObjectName,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,BSTR *OwnerName);
  void __RPC_STUB _Catalog_GetObjectOwner_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Catalog_SetObjectOwner_Proxy(_ADOCatalog *This,BSTR ObjectName,ObjectTypeEnum ObjectType,BSTR UserName,VARIANT ObjectTypeId);
  void __RPC_STUB _Catalog_SetObjectOwner_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Table_INTERFACE_DEFINED__
#define ___Table_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Table;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOTable : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Columns(ADOColumns **ppvObject) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_Type(BSTR *pVal) = 0;
    virtual HRESULT WINAPI get_Indexes(ADOIndexes **ppvObject) = 0;
    virtual HRESULT WINAPI get_Keys(ADOKeys **ppvObject) = 0;
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
    virtual HRESULT WINAPI get_DateCreated(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI get_DateModified(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI get_ParentCatalog(_ADOCatalog **ppvObject) = 0;
    virtual HRESULT WINAPI put_ParentCatalog(_ADOCatalog *ppvObject) = 0;
    virtual HRESULT WINAPI putref_ParentCatalog(_ADOCatalog *ppvObject) = 0;
  };
#else
  typedef struct _TableVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOTable *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOTable *This);
      ULONG (WINAPI *Release)(_ADOTable *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOTable *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOTable *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOTable *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOTable *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Columns)(_ADOTable *This,ADOColumns **ppvObject);
      HRESULT (WINAPI *get_Name)(_ADOTable *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOTable *This,BSTR newVal);
      HRESULT (WINAPI *get_Type)(_ADOTable *This,BSTR *pVal);
      HRESULT (WINAPI *get_Indexes)(_ADOTable *This,ADOIndexes **ppvObject);
      HRESULT (WINAPI *get_Keys)(_ADOTable *This,ADOKeys **ppvObject);
      HRESULT (WINAPI *get_Properties)(_ADOTable *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_DateCreated)(_ADOTable *This,VARIANT *pVal);
      HRESULT (WINAPI *get_DateModified)(_ADOTable *This,VARIANT *pVal);
      HRESULT (WINAPI *get_ParentCatalog)(_ADOTable *This,_ADOCatalog **ppvObject);
      HRESULT (WINAPI *put_ParentCatalog)(_ADOTable *This,_ADOCatalog *ppvObject);
      HRESULT (WINAPI *putref_ParentADOCatalog)(_ADOTable *This,_ADOCatalog *ppvObject);
    END_INTERFACE
  } _TableVtbl;
  struct _Table {
    CONST_VTBL struct _TableVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Table_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Table_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Table_Release(This) (This)->lpVtbl->Release(This)
#define _Table_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Table_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Table_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Table_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Table_get_Columns(This,ppvObject) (This)->lpVtbl->get_Columns(This,ppvObject)
#define _Table_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Table_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Table_get_Type(This,pVal) (This)->lpVtbl->get_Type(This,pVal)
#define _Table_get_Indexes(This,ppvObject) (This)->lpVtbl->get_Indexes(This,ppvObject)
#define _Table_get_Keys(This,ppvObject) (This)->lpVtbl->get_Keys(This,ppvObject)
#define _Table_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define _Table_get_DateCreated(This,pVal) (This)->lpVtbl->get_DateCreated(This,pVal)
#define _Table_get_DateModified(This,pVal) (This)->lpVtbl->get_DateModified(This,pVal)
#define _Table_get_ParentCatalog(This,ppvObject) (This)->lpVtbl->get_ParentCatalog(This,ppvObject)
#define _Table_put_ParentCatalog(This,ppvObject) (This)->lpVtbl->put_ParentCatalog(This,ppvObject)
#define _Table_putref_ParentCatalog(This,ppvObject) (This)->lpVtbl->putref_ParentCatalog(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Table_get_Columns_Proxy(_ADOTable *This,ADOColumns **ppvObject);
  void __RPC_STUB _Table_get_Columns_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_Name_Proxy(_ADOTable *This,BSTR *pVal);
  void __RPC_STUB _Table_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_put_Name_Proxy(_ADOTable *This,BSTR newVal);
  void __RPC_STUB _Table_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_Type_Proxy(_ADOTable *This,BSTR *pVal);
  void __RPC_STUB _Table_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_Indexes_Proxy(_ADOTable *This,ADOIndexes **ppvObject);
  void __RPC_STUB _Table_get_Indexes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_Keys_Proxy(_ADOTable *This,ADOKeys **ppvObject);
  void __RPC_STUB _Table_get_Keys_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_Properties_Proxy(_ADOTable *This,ADOProperties **ppvObject);
  void __RPC_STUB _Table_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_DateCreated_Proxy(_ADOTable *This,VARIANT *pVal);
  void __RPC_STUB _Table_get_DateCreated_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_DateModified_Proxy(_ADOTable *This,VARIANT *pVal);
  void __RPC_STUB _Table_get_DateModified_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_get_ParentCatalog_Proxy(_ADOTable *This,_ADOCatalog **ppvObject);
  void __RPC_STUB _Table_get_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_put_ParentCatalog_Proxy(_ADOTable *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Table_put_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Table_putref_ParentCatalog_Proxy(_ADOTable *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Table_putref_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Group25_INTERFACE_DEFINED__
#define ___Group25_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Group25;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _Group25 : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI GetPermissions(VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights) = 0;
    virtual HRESULT WINAPI SetPermissions(VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId) = 0;
    virtual HRESULT WINAPI get_Users(ADOUsers **ppvObject) = 0;
  };
#else
  typedef struct _Group25Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_Group25 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_Group25 *This);
      ULONG (WINAPI *Release)(_Group25 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_Group25 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_Group25 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_Group25 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_Group25 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_Group25 *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_Group25 *This,BSTR newVal);
      HRESULT (WINAPI *GetPermissions)(_Group25 *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
      HRESULT (WINAPI *SetPermissions)(_Group25 *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
      HRESULT (WINAPI *get_Users)(_Group25 *This,ADOUsers **ppvObject);
    END_INTERFACE
  } _Group25Vtbl;
  struct _Group25 {
    CONST_VTBL struct _Group25Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Group25_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Group25_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Group25_Release(This) (This)->lpVtbl->Release(This)
#define _Group25_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Group25_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Group25_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Group25_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Group25_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Group25_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Group25_GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights) (This)->lpVtbl->GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights)
#define _Group25_SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId) (This)->lpVtbl->SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId)
#define _Group25_get_Users(This,ppvObject) (This)->lpVtbl->get_Users(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Group25_get_Name_Proxy(_Group25 *This,BSTR *pVal);
  void __RPC_STUB _Group25_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group25_put_Name_Proxy(_Group25 *This,BSTR newVal);
  void __RPC_STUB _Group25_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group25_GetPermissions_Proxy(_Group25 *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
  void __RPC_STUB _Group25_GetPermissions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group25_SetPermissions_Proxy(_Group25 *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
  void __RPC_STUB _Group25_SetPermissions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group25_get_Users_Proxy(_Group25 *This,ADOUsers **ppvObject);
  void __RPC_STUB _Group25_get_Users_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Group_INTERFACE_DEFINED__
#define ___Group_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Group;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOGroup : public _Group25 {
  public:
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
    virtual HRESULT WINAPI get_ParentCatalog(_ADOCatalog **ppvObject) = 0;
    virtual HRESULT WINAPI put_ParentCatalog(_ADOCatalog *ppvObject) = 0;
    virtual HRESULT WINAPI putref_ParentCatalog(_ADOCatalog *ppvObject) = 0;
  };
#else
  typedef struct _GroupVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOGroup *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOGroup *This);
      ULONG (WINAPI *Release)(_ADOGroup *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOGroup *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOGroup *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOGroup *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOGroup *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_ADOGroup *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOGroup *This,BSTR newVal);
      HRESULT (WINAPI *GetPermissions)(_ADOGroup *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
      HRESULT (WINAPI *SetPermissions)(_ADOGroup *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
      HRESULT (WINAPI *get_Users)(_ADOGroup *This,ADOUsers **ppvObject);
      HRESULT (WINAPI *get_Properties)(_ADOGroup *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ParentCatalog)(_ADOGroup *This,_ADOCatalog **ppvObject);
      HRESULT (WINAPI *put_ParentCatalog)(_ADOGroup *This,_ADOCatalog *ppvObject);
      HRESULT (WINAPI *putref_ParentADOCatalog)(_ADOGroup *This,_ADOCatalog *ppvObject);
    END_INTERFACE
  } _GroupVtbl;
  struct _Group {
    CONST_VTBL struct _GroupVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Group_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Group_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Group_Release(This) (This)->lpVtbl->Release(This)
#define _Group_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Group_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Group_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Group_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Group_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Group_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Group_GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights) (This)->lpVtbl->GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights)
#define _Group_SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId) (This)->lpVtbl->SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId)
#define _Group_get_Users(This,ppvObject) (This)->lpVtbl->get_Users(This,ppvObject)
#define _Group_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define _Group_get_ParentCatalog(This,ppvObject) (This)->lpVtbl->get_ParentCatalog(This,ppvObject)
#define _Group_put_ParentCatalog(This,ppvObject) (This)->lpVtbl->put_ParentCatalog(This,ppvObject)
#define _Group_putref_ParentCatalog(This,ppvObject) (This)->lpVtbl->putref_ParentCatalog(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Group_get_Properties_Proxy(_ADOGroup *This,ADOProperties **ppvObject);
  void __RPC_STUB _Group_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group_get_ParentCatalog_Proxy(_ADOGroup *This,_ADOCatalog **ppvObject);
  void __RPC_STUB _Group_get_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group_put_ParentCatalog_Proxy(_ADOGroup *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Group_put_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Group_putref_ParentCatalog_Proxy(_ADOGroup *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Group_putref_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___User25_INTERFACE_DEFINED__
#define ___User25_INTERFACE_DEFINED__
  EXTERN_C const IID IID__User25;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _User25 : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI GetPermissions(VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights) = 0;
    virtual HRESULT WINAPI SetPermissions(VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId) = 0;
    virtual HRESULT WINAPI ChangePassword(BSTR OldPassword,BSTR NewPassword) = 0;
    virtual HRESULT WINAPI get_Groups(ADOGroups **ppvObject) = 0;
  };
#else
  typedef struct _User25Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_User25 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_User25 *This);
      ULONG (WINAPI *Release)(_User25 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_User25 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_User25 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_User25 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_User25 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_User25 *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_User25 *This,BSTR newVal);
      HRESULT (WINAPI *GetPermissions)(_User25 *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
      HRESULT (WINAPI *SetPermissions)(_User25 *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
      HRESULT (WINAPI *ChangePassword)(_User25 *This,BSTR OldPassword,BSTR NewPassword);
      HRESULT (WINAPI *get_Groups)(_User25 *This,ADOGroups **ppvObject);
    END_INTERFACE
  } _User25Vtbl;
  struct _User25 {
    CONST_VTBL struct _User25Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _User25_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _User25_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _User25_Release(This) (This)->lpVtbl->Release(This)
#define _User25_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _User25_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _User25_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _User25_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _User25_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _User25_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _User25_GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights) (This)->lpVtbl->GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights)
#define _User25_SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId) (This)->lpVtbl->SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId)
#define _User25_ChangePassword(This,OldPassword,NewPassword) (This)->lpVtbl->ChangePassword(This,OldPassword,NewPassword)
#define _User25_get_Groups(This,ppvObject) (This)->lpVtbl->get_Groups(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _User25_get_Name_Proxy(_User25 *This,BSTR *pVal);
  void __RPC_STUB _User25_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User25_put_Name_Proxy(_User25 *This,BSTR newVal);
  void __RPC_STUB _User25_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User25_GetPermissions_Proxy(_User25 *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
  void __RPC_STUB _User25_GetPermissions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User25_SetPermissions_Proxy(_User25 *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
  void __RPC_STUB _User25_SetPermissions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User25_ChangePassword_Proxy(_User25 *This,BSTR OldPassword,BSTR NewPassword);
  void __RPC_STUB _User25_ChangePassword_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User25_get_Groups_Proxy(_User25 *This,ADOGroups **ppvObject);
  void __RPC_STUB _User25_get_Groups_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___User_INTERFACE_DEFINED__
#define ___User_INTERFACE_DEFINED__
  EXTERN_C const IID IID__User;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOUser : public _User25 {
  public:
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
    virtual HRESULT WINAPI get_ParentCatalog(_ADOCatalog **ppvObject) = 0;
    virtual HRESULT WINAPI put_ParentCatalog(_ADOCatalog *ppvObject) = 0;
    virtual HRESULT WINAPI putref_ParentCatalog(_ADOCatalog *ppvObject) = 0;
  };
#else
  typedef struct _UserVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOUser *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOUser *This);
      ULONG (WINAPI *Release)(_ADOUser *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOUser *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOUser *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOUser *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOUser *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_ADOUser *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOUser *This,BSTR newVal);
      HRESULT (WINAPI *GetPermissions)(_ADOUser *This,VARIANT Name,ObjectTypeEnum ObjectType,VARIANT ObjectTypeId,RightsEnum *Rights);
      HRESULT (WINAPI *SetPermissions)(_ADOUser *This,VARIANT Name,ObjectTypeEnum ObjectType,ActionEnum Action,RightsEnum Rights,InheritTypeEnum Inherit,VARIANT ObjectTypeId);
      HRESULT (WINAPI *ChangePassword)(_ADOUser *This,BSTR OldPassword,BSTR NewPassword);
      HRESULT (WINAPI *get_Groups)(_ADOUser *This,ADOGroups **ppvObject);
      HRESULT (WINAPI *get_Properties)(_ADOUser *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ParentCatalog)(_ADOUser *This,_ADOCatalog **ppvObject);
      HRESULT (WINAPI *put_ParentCatalog)(_ADOUser *This,_ADOCatalog *ppvObject);
      HRESULT (WINAPI *putref_ParentADOCatalog)(_ADOUser *This,_ADOCatalog *ppvObject);
    END_INTERFACE
  } _UserVtbl;
  struct _User {
    CONST_VTBL struct _UserVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _User_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _User_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _User_Release(This) (This)->lpVtbl->Release(This)
#define _User_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _User_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _User_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _User_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _User_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _User_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _User_GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights) (This)->lpVtbl->GetPermissions(This,Name,ObjectType,ObjectTypeId,Rights)
#define _User_SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId) (This)->lpVtbl->SetPermissions(This,Name,ObjectType,Action,Rights,Inherit,ObjectTypeId)
#define _User_ChangePassword(This,OldPassword,NewPassword) (This)->lpVtbl->ChangePassword(This,OldPassword,NewPassword)
#define _User_get_Groups(This,ppvObject) (This)->lpVtbl->get_Groups(This,ppvObject)
#define _User_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define _User_get_ParentCatalog(This,ppvObject) (This)->lpVtbl->get_ParentCatalog(This,ppvObject)
#define _User_put_ParentCatalog(This,ppvObject) (This)->lpVtbl->put_ParentCatalog(This,ppvObject)
#define _User_putref_ParentCatalog(This,ppvObject) (This)->lpVtbl->putref_ParentCatalog(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _User_get_Properties_Proxy(_ADOUser *This,ADOProperties **ppvObject);
  void __RPC_STUB _User_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User_get_ParentCatalog_Proxy(_ADOUser *This,_ADOCatalog **ppvObject);
  void __RPC_STUB _User_get_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User_put_ParentCatalog_Proxy(_ADOUser *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _User_put_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _User_putref_ParentCatalog_Proxy(_ADOUser *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _User_putref_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Column_INTERFACE_DEFINED__
#define ___Column_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Column;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOColumn : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_Attributes(ColumnAttributesEnum *pVal) = 0;
    virtual HRESULT WINAPI put_Attributes(ColumnAttributesEnum newVal) = 0;
    virtual HRESULT WINAPI get_DefinedSize(__LONG32 *pVal) = 0;
    virtual HRESULT WINAPI put_DefinedSize(__LONG32 DefinedSize) = 0;
    virtual HRESULT WINAPI get_NumericScale(BYTE *pVal) = 0;
    virtual HRESULT WINAPI put_NumericScale(BYTE newVal) = 0;
    virtual HRESULT WINAPI get_Precision(__LONG32 *pVal) = 0;
    virtual HRESULT WINAPI put_Precision(__LONG32 newVal) = 0;
    virtual HRESULT WINAPI get_RelatedColumn(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_RelatedColumn(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_SortOrder(SortOrderEnum *pVal) = 0;
    virtual HRESULT WINAPI put_SortOrder(SortOrderEnum newVal) = 0;
    virtual HRESULT WINAPI get_Type(DataTypeEnum *pVal) = 0;
    virtual HRESULT WINAPI put_Type(DataTypeEnum newVal) = 0;
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
    virtual HRESULT WINAPI get_ParentCatalog(_ADOCatalog **ppvObject) = 0;
    virtual HRESULT WINAPI put_ParentCatalog(_ADOCatalog *ppvObject) = 0;
    virtual HRESULT WINAPI putref_ParentCatalog(_ADOCatalog *ppvObject) = 0;
  };
#else
  typedef struct _ColumnVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOColumn *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOColumn *This);
      ULONG (WINAPI *Release)(_ADOColumn *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOColumn *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOColumn *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOColumn *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOColumn *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_ADOColumn *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOColumn *This,BSTR newVal);
      HRESULT (WINAPI *get_Attributes)(_ADOColumn *This,ColumnAttributesEnum *pVal);
      HRESULT (WINAPI *put_Attributes)(_ADOColumn *This,ColumnAttributesEnum newVal);
      HRESULT (WINAPI *get_DefinedSize)(_ADOColumn *This,__LONG32 *pVal);
      HRESULT (WINAPI *put_DefinedSize)(_ADOColumn *This,__LONG32 DefinedSize);
      HRESULT (WINAPI *get_NumericScale)(_ADOColumn *This,BYTE *pVal);
      HRESULT (WINAPI *put_NumericScale)(_ADOColumn *This,BYTE newVal);
      HRESULT (WINAPI *get_Precision)(_ADOColumn *This,__LONG32 *pVal);
      HRESULT (WINAPI *put_Precision)(_ADOColumn *This,__LONG32 newVal);
      HRESULT (WINAPI *get_RelatedColumn)(_ADOColumn *This,BSTR *pVal);
      HRESULT (WINAPI *put_RelatedColumn)(_ADOColumn *This,BSTR newVal);
      HRESULT (WINAPI *get_SortOrder)(_ADOColumn *This,SortOrderEnum *pVal);
      HRESULT (WINAPI *put_SortOrder)(_ADOColumn *This,SortOrderEnum newVal);
      HRESULT (WINAPI *get_Type)(_ADOColumn *This,DataTypeEnum *pVal);
      HRESULT (WINAPI *put_Type)(_ADOColumn *This,DataTypeEnum newVal);
      HRESULT (WINAPI *get_Properties)(_ADOColumn *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ParentCatalog)(_ADOColumn *This,_ADOCatalog **ppvObject);
      HRESULT (WINAPI *put_ParentCatalog)(_ADOColumn *This,_ADOCatalog *ppvObject);
      HRESULT (WINAPI *putref_ParentADOCatalog)(_ADOColumn *This,_ADOCatalog *ppvObject);
    END_INTERFACE
  } _ColumnVtbl;
  struct _Column {
    CONST_VTBL struct _ColumnVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Column_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Column_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Column_Release(This) (This)->lpVtbl->Release(This)
#define _Column_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Column_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Column_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Column_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Column_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Column_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Column_get_Attributes(This,pVal) (This)->lpVtbl->get_Attributes(This,pVal)
#define _Column_put_Attributes(This,newVal) (This)->lpVtbl->put_Attributes(This,newVal)
#define _Column_get_DefinedSize(This,pVal) (This)->lpVtbl->get_DefinedSize(This,pVal)
#define _Column_put_DefinedSize(This,DefinedSize) (This)->lpVtbl->put_DefinedSize(This,DefinedSize)
#define _Column_get_NumericScale(This,pVal) (This)->lpVtbl->get_NumericScale(This,pVal)
#define _Column_put_NumericScale(This,newVal) (This)->lpVtbl->put_NumericScale(This,newVal)
#define _Column_get_Precision(This,pVal) (This)->lpVtbl->get_Precision(This,pVal)
#define _Column_put_Precision(This,newVal) (This)->lpVtbl->put_Precision(This,newVal)
#define _Column_get_RelatedColumn(This,pVal) (This)->lpVtbl->get_RelatedColumn(This,pVal)
#define _Column_put_RelatedColumn(This,newVal) (This)->lpVtbl->put_RelatedColumn(This,newVal)
#define _Column_get_SortOrder(This,pVal) (This)->lpVtbl->get_SortOrder(This,pVal)
#define _Column_put_SortOrder(This,newVal) (This)->lpVtbl->put_SortOrder(This,newVal)
#define _Column_get_Type(This,pVal) (This)->lpVtbl->get_Type(This,pVal)
#define _Column_put_Type(This,newVal) (This)->lpVtbl->put_Type(This,newVal)
#define _Column_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#define _Column_get_ParentCatalog(This,ppvObject) (This)->lpVtbl->get_ParentCatalog(This,ppvObject)
#define _Column_put_ParentCatalog(This,ppvObject) (This)->lpVtbl->put_ParentCatalog(This,ppvObject)
#define _Column_putref_ParentCatalog(This,ppvObject) (This)->lpVtbl->putref_ParentCatalog(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Column_get_Name_Proxy(_ADOColumn *This,BSTR *pVal);
  void __RPC_STUB _Column_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_Name_Proxy(_ADOColumn *This,BSTR newVal);
  void __RPC_STUB _Column_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_Attributes_Proxy(_ADOColumn *This,ColumnAttributesEnum *pVal);
  void __RPC_STUB _Column_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_Attributes_Proxy(_ADOColumn *This,ColumnAttributesEnum newVal);
  void __RPC_STUB _Column_put_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_DefinedSize_Proxy(_ADOColumn *This,__LONG32 *pVal);
  void __RPC_STUB _Column_get_DefinedSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_DefinedSize_Proxy(_ADOColumn *This,__LONG32 DefinedSize);
  void __RPC_STUB _Column_put_DefinedSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_NumericScale_Proxy(_ADOColumn *This,BYTE *pVal);
  void __RPC_STUB _Column_get_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_NumericScale_Proxy(_ADOColumn *This,BYTE newVal);
  void __RPC_STUB _Column_put_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_Precision_Proxy(_ADOColumn *This,__LONG32 *pVal);
  void __RPC_STUB _Column_get_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_Precision_Proxy(_ADOColumn *This,__LONG32 newVal);
  void __RPC_STUB _Column_put_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_RelatedColumn_Proxy(_ADOColumn *This,BSTR *pVal);
  void __RPC_STUB _Column_get_RelatedColumn_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_RelatedColumn_Proxy(_ADOColumn *This,BSTR newVal);
  void __RPC_STUB _Column_put_RelatedColumn_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_SortOrder_Proxy(_ADOColumn *This,SortOrderEnum *pVal);
  void __RPC_STUB _Column_get_SortOrder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_SortOrder_Proxy(_ADOColumn *This,SortOrderEnum newVal);
  void __RPC_STUB _Column_put_SortOrder_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_Type_Proxy(_ADOColumn *This,DataTypeEnum *pVal);
  void __RPC_STUB _Column_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_Type_Proxy(_ADOColumn *This,DataTypeEnum newVal);
  void __RPC_STUB _Column_put_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_Properties_Proxy(_ADOColumn *This,ADOProperties **ppvObject);
  void __RPC_STUB _Column_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_get_ParentCatalog_Proxy(_ADOColumn *This,_ADOCatalog **ppvObject);
  void __RPC_STUB _Column_get_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_put_ParentCatalog_Proxy(_ADOColumn *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Column_put_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Column_putref_ParentCatalog_Proxy(_ADOColumn *This,_ADOCatalog *ppvObject);
  void __RPC_STUB _Column_putref_ParentCatalog_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Index_INTERFACE_DEFINED__
#define ___Index_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Index;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOIndex : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_Clustered(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI put_Clustered(VARIANT_BOOL newVal) = 0;
    virtual HRESULT WINAPI get_IndexNulls(AllowNullsEnum *pVal) = 0;
    virtual HRESULT WINAPI put_IndexNulls(AllowNullsEnum newVal) = 0;
    virtual HRESULT WINAPI get_PrimaryKey(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI put_PrimaryKey(VARIANT_BOOL newVal) = 0;
    virtual HRESULT WINAPI get_Unique(VARIANT_BOOL *pVal) = 0;
    virtual HRESULT WINAPI put_Unique(VARIANT_BOOL newVal) = 0;
    virtual HRESULT WINAPI get_Columns(ADOColumns **ppvObject) = 0;
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
  };
#else
  typedef struct _IndexVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOIndex *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOIndex *This);
      ULONG (WINAPI *Release)(_ADOIndex *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOIndex *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOIndex *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOIndex *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOIndex *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_ADOIndex *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOIndex *This,BSTR newVal);
      HRESULT (WINAPI *get_Clustered)(_ADOIndex *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *put_Clustered)(_ADOIndex *This,VARIANT_BOOL newVal);
      HRESULT (WINAPI *get_IndexNulls)(_ADOIndex *This,AllowNullsEnum *pVal);
      HRESULT (WINAPI *put_IndexNulls)(_ADOIndex *This,AllowNullsEnum newVal);
      HRESULT (WINAPI *get_PrimaryKey)(_ADOIndex *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *put_PrimaryKey)(_ADOIndex *This,VARIANT_BOOL newVal);
      HRESULT (WINAPI *get_Unique)(_ADOIndex *This,VARIANT_BOOL *pVal);
      HRESULT (WINAPI *put_Unique)(_ADOIndex *This,VARIANT_BOOL newVal);
      HRESULT (WINAPI *get_Columns)(_ADOIndex *This,ADOColumns **ppvObject);
      HRESULT (WINAPI *get_Properties)(_ADOIndex *This,ADOProperties **ppvObject);
    END_INTERFACE
  } _IndexVtbl;
  struct _Index {
    CONST_VTBL struct _IndexVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Index_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Index_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Index_Release(This) (This)->lpVtbl->Release(This)
#define _Index_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Index_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Index_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Index_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Index_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Index_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Index_get_Clustered(This,pVal) (This)->lpVtbl->get_Clustered(This,pVal)
#define _Index_put_Clustered(This,newVal) (This)->lpVtbl->put_Clustered(This,newVal)
#define _Index_get_IndexNulls(This,pVal) (This)->lpVtbl->get_IndexNulls(This,pVal)
#define _Index_put_IndexNulls(This,newVal) (This)->lpVtbl->put_IndexNulls(This,newVal)
#define _Index_get_PrimaryKey(This,pVal) (This)->lpVtbl->get_PrimaryKey(This,pVal)
#define _Index_put_PrimaryKey(This,newVal) (This)->lpVtbl->put_PrimaryKey(This,newVal)
#define _Index_get_Unique(This,pVal) (This)->lpVtbl->get_Unique(This,pVal)
#define _Index_put_Unique(This,newVal) (This)->lpVtbl->put_Unique(This,newVal)
#define _Index_get_Columns(This,ppvObject) (This)->lpVtbl->get_Columns(This,ppvObject)
#define _Index_get_Properties(This,ppvObject) (This)->lpVtbl->get_Properties(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Index_get_Name_Proxy(_ADOIndex *This,BSTR *pVal);
  void __RPC_STUB _Index_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_put_Name_Proxy(_ADOIndex *This,BSTR newVal);
  void __RPC_STUB _Index_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_Clustered_Proxy(_ADOIndex *This,VARIANT_BOOL *pVal);
  void __RPC_STUB _Index_get_Clustered_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_put_Clustered_Proxy(_ADOIndex *This,VARIANT_BOOL newVal);
  void __RPC_STUB _Index_put_Clustered_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_IndexNulls_Proxy(_ADOIndex *This,AllowNullsEnum *pVal);
  void __RPC_STUB _Index_get_IndexNulls_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_put_IndexNulls_Proxy(_ADOIndex *This,AllowNullsEnum newVal);
  void __RPC_STUB _Index_put_IndexNulls_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_PrimaryKey_Proxy(_ADOIndex *This,VARIANT_BOOL *pVal);
  void __RPC_STUB _Index_get_PrimaryKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_put_PrimaryKey_Proxy(_ADOIndex *This,VARIANT_BOOL newVal);
  void __RPC_STUB _Index_put_PrimaryKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_Unique_Proxy(_ADOIndex *This,VARIANT_BOOL *pVal);
  void __RPC_STUB _Index_get_Unique_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_put_Unique_Proxy(_ADOIndex *This,VARIANT_BOOL newVal);
  void __RPC_STUB _Index_put_Unique_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_Columns_Proxy(_ADOIndex *This,ADOColumns **ppvObject);
  void __RPC_STUB _Index_get_Columns_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Index_get_Properties_Proxy(_ADOIndex *This,ADOProperties **ppvObject);
  void __RPC_STUB _Index_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Key_INTERFACE_DEFINED__
#define ___Key_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Key;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOKey : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_Name(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_DeleteRule(RuleEnum *pVal) = 0;
    virtual HRESULT WINAPI put_DeleteRule(RuleEnum newVal) = 0;
    virtual HRESULT WINAPI get_Type(KeyTypeEnum *pVal) = 0;
    virtual HRESULT WINAPI put_Type(KeyTypeEnum newVal) = 0;
    virtual HRESULT WINAPI get_RelatedTable(BSTR *pVal) = 0;
    virtual HRESULT WINAPI put_RelatedTable(BSTR newVal) = 0;
    virtual HRESULT WINAPI get_UpdateRule(RuleEnum *pVal) = 0;
    virtual HRESULT WINAPI put_UpdateRule(RuleEnum newVal) = 0;
    virtual HRESULT WINAPI get_Columns(ADOColumns **ppvObject) = 0;
  };
#else
  typedef struct _KeyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOKey *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOKey *This);
      ULONG (WINAPI *Release)(_ADOKey *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOKey *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOKey *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOKey *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOKey *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Name)(_ADOKey *This,BSTR *pVal);
      HRESULT (WINAPI *put_Name)(_ADOKey *This,BSTR newVal);
      HRESULT (WINAPI *get_DeleteRule)(_ADOKey *This,RuleEnum *pVal);
      HRESULT (WINAPI *put_DeleteRule)(_ADOKey *This,RuleEnum newVal);
      HRESULT (WINAPI *get_Type)(_ADOKey *This,KeyTypeEnum *pVal);
      HRESULT (WINAPI *put_Type)(_ADOKey *This,KeyTypeEnum newVal);
      HRESULT (WINAPI *get_RelatedTable)(_ADOKey *This,BSTR *pVal);
      HRESULT (WINAPI *put_RelatedTable)(_ADOKey *This,BSTR newVal);
      HRESULT (WINAPI *get_UpdateRule)(_ADOKey *This,RuleEnum *pVal);
      HRESULT (WINAPI *put_UpdateRule)(_ADOKey *This,RuleEnum newVal);
      HRESULT (WINAPI *get_Columns)(_ADOKey *This,ADOColumns **ppvObject);
    END_INTERFACE
  } _KeyVtbl;
  struct _Key {
    CONST_VTBL struct _KeyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Key_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define _Key_AddRef(This) (This)->lpVtbl->AddRef(This)
#define _Key_Release(This) (This)->lpVtbl->Release(This)
#define _Key_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define _Key_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Key_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Key_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Key_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define _Key_put_Name(This,newVal) (This)->lpVtbl->put_Name(This,newVal)
#define _Key_get_DeleteRule(This,pVal) (This)->lpVtbl->get_DeleteRule(This,pVal)
#define _Key_put_DeleteRule(This,newVal) (This)->lpVtbl->put_DeleteRule(This,newVal)
#define _Key_get_Type(This,pVal) (This)->lpVtbl->get_Type(This,pVal)
#define _Key_put_Type(This,newVal) (This)->lpVtbl->put_Type(This,newVal)
#define _Key_get_RelatedTable(This,pVal) (This)->lpVtbl->get_RelatedTable(This,pVal)
#define _Key_put_RelatedTable(This,newVal) (This)->lpVtbl->put_RelatedTable(This,newVal)
#define _Key_get_UpdateRule(This,pVal) (This)->lpVtbl->get_UpdateRule(This,pVal)
#define _Key_put_UpdateRule(This,newVal) (This)->lpVtbl->put_UpdateRule(This,newVal)
#define _Key_get_Columns(This,ppvObject) (This)->lpVtbl->get_Columns(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _Key_get_Name_Proxy(_ADOKey *This,BSTR *pVal);
  void __RPC_STUB _Key_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_put_Name_Proxy(_ADOKey *This,BSTR newVal);
  void __RPC_STUB _Key_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_get_DeleteRule_Proxy(_ADOKey *This,RuleEnum *pVal);
  void __RPC_STUB _Key_get_DeleteRule_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_put_DeleteRule_Proxy(_ADOKey *This,RuleEnum newVal);
  void __RPC_STUB _Key_put_DeleteRule_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_get_Type_Proxy(_ADOKey *This,KeyTypeEnum *pVal);
  void __RPC_STUB _Key_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_put_Type_Proxy(_ADOKey *This,KeyTypeEnum newVal);
  void __RPC_STUB _Key_put_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_get_RelatedTable_Proxy(_ADOKey *This,BSTR *pVal);
  void __RPC_STUB _Key_get_RelatedTable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_put_RelatedTable_Proxy(_ADOKey *This,BSTR newVal);
  void __RPC_STUB _Key_put_RelatedTable_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_get_UpdateRule_Proxy(_ADOKey *This,RuleEnum *pVal);
  void __RPC_STUB _Key_get_UpdateRule_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_put_UpdateRule_Proxy(_ADOKey *This,RuleEnum newVal);
  void __RPC_STUB _Key_put_UpdateRule_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Key_get_Columns_Proxy(_ADOKey *This,ADOColumns **ppvObject);
  void __RPC_STUB _Key_get_Columns_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __View_INTERFACE_DEFINED__
#define __View_INTERFACE_DEFINED__
  EXTERN_C const IID IID_View;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOView : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Command(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI put_Command(VARIANT newVal) = 0;
    virtual HRESULT WINAPI putref_Command(IDispatch *pComm) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI get_DateCreated(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI get_DateModified(VARIANT *pVal) = 0;
  };
#else
  typedef struct ViewVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOView *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOView *This);
      ULONG (WINAPI *Release)(ADOView *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOView *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOView *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOView *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOView *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Command)(ADOView *This,VARIANT *pVal);
      HRESULT (WINAPI *put_Command)(ADOView *This,VARIANT newVal);
      HRESULT (WINAPI *putref_Command)(ADOView *This,IDispatch *pComm);
      HRESULT (WINAPI *get_Name)(ADOView *This,BSTR *pVal);
      HRESULT (WINAPI *get_DateCreated)(ADOView *This,VARIANT *pVal);
      HRESULT (WINAPI *get_DateModified)(ADOView *This,VARIANT *pVal);
    END_INTERFACE
  } ViewVtbl;
  struct View {
    CONST_VTBL struct ViewVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define View_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define View_AddRef(This) (This)->lpVtbl->AddRef(This)
#define View_Release(This) (This)->lpVtbl->Release(This)
#define View_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define View_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define View_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define View_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define View_get_Command(This,pVal) (This)->lpVtbl->get_Command(This,pVal)
#define View_put_Command(This,newVal) (This)->lpVtbl->put_Command(This,newVal)
#define View_putref_Command(This,pComm) (This)->lpVtbl->putref_Command(This,pComm)
#define View_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define View_get_DateCreated(This,pVal) (This)->lpVtbl->get_DateCreated(This,pVal)
#define View_get_DateModified(This,pVal) (This)->lpVtbl->get_DateModified(This,pVal)
#endif
#endif
  HRESULT WINAPI View_get_Command_Proxy(ADOView *This,VARIANT *pVal);
  void __RPC_STUB View_get_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI View_put_Command_Proxy(ADOView *This,VARIANT newVal);
  void __RPC_STUB View_put_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI View_putref_Command_Proxy(ADOView *This,IDispatch *pComm);
  void __RPC_STUB View_putref_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI View_get_Name_Proxy(ADOView *This,BSTR *pVal);
  void __RPC_STUB View_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI View_get_DateCreated_Proxy(ADOView *This,VARIANT *pVal);
  void __RPC_STUB View_get_DateCreated_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI View_get_DateModified_Proxy(ADOView *This,VARIANT *pVal);
  void __RPC_STUB View_get_DateModified_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Procedure_INTERFACE_DEFINED__
#define __Procedure_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Procedure;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOProcedure : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Command(VARIANT *pVar) = 0;
    virtual HRESULT WINAPI put_Command(VARIANT newVal) = 0;
    virtual HRESULT WINAPI putref_Command(IDispatch *pComm) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pVal) = 0;
    virtual HRESULT WINAPI get_DateCreated(VARIANT *pVal) = 0;
    virtual HRESULT WINAPI get_DateModified(VARIANT *pVal) = 0;
  };
#else
  typedef struct ProcedureVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOProcedure *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOProcedure *This);
      ULONG (WINAPI *Release)(ADOProcedure *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOProcedure *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOProcedure *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOProcedure *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOProcedure *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Command)(ADOProcedure *This,VARIANT *pVar);
      HRESULT (WINAPI *put_Command)(ADOProcedure *This,VARIANT newVal);
      HRESULT (WINAPI *putref_Command)(ADOProcedure *This,IDispatch *pComm);
      HRESULT (WINAPI *get_Name)(ADOProcedure *This,BSTR *pVal);
      HRESULT (WINAPI *get_DateCreated)(ADOProcedure *This,VARIANT *pVal);
      HRESULT (WINAPI *get_DateModified)(ADOProcedure *This,VARIANT *pVal);
    END_INTERFACE
  } ProcedureVtbl;
  struct Procedure {
    CONST_VTBL struct ProcedureVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Procedure_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Procedure_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Procedure_Release(This) (This)->lpVtbl->Release(This)
#define Procedure_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Procedure_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Procedure_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Procedure_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Procedure_get_Command(This,pVar) (This)->lpVtbl->get_Command(This,pVar)
#define Procedure_put_Command(This,newVal) (This)->lpVtbl->put_Command(This,newVal)
#define Procedure_putref_Command(This,pComm) (This)->lpVtbl->putref_Command(This,pComm)
#define Procedure_get_Name(This,pVal) (This)->lpVtbl->get_Name(This,pVal)
#define Procedure_get_DateCreated(This,pVal) (This)->lpVtbl->get_DateCreated(This,pVal)
#define Procedure_get_DateModified(This,pVal) (This)->lpVtbl->get_DateModified(This,pVal)
#endif
#endif
  HRESULT WINAPI Procedure_get_Command_Proxy(ADOProcedure *This,VARIANT *pVar);
  void __RPC_STUB Procedure_get_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedure_put_Command_Proxy(ADOProcedure *This,VARIANT newVal);
  void __RPC_STUB Procedure_put_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedure_putref_Command_Proxy(ADOProcedure *This,IDispatch *pComm);
  void __RPC_STUB Procedure_putref_Command_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedure_get_Name_Proxy(ADOProcedure *This,BSTR *pVal);
  void __RPC_STUB Procedure_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedure_get_DateCreated_Proxy(ADOProcedure *This,VARIANT *pVal);
  void __RPC_STUB Procedure_get_DateCreated_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedure_get_DateModified_Proxy(ADOProcedure *This,VARIANT *pVal);
  void __RPC_STUB Procedure_get_DateModified_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Catalog;
#ifdef __cplusplus
  Catalog;
#endif
  EXTERN_C const CLSID CLSID_Table;
#ifdef __cplusplus
  Table;
#endif

#ifndef __Property_INTERFACE_DEFINED__
#define __Property_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Property;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOProperty : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Value(VARIANT *pval) = 0;
    virtual HRESULT WINAPI put_Value(VARIANT val) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Type(DataTypeEnum *ptype) = 0;
    virtual HRESULT WINAPI get_Attributes(__LONG32 *plAttributes) = 0;
    virtual HRESULT WINAPI put_Attributes(__LONG32 lAttributes) = 0;
  };
#else
  typedef struct PropertyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOProperty *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOProperty *This);
      ULONG (WINAPI *Release)(ADOProperty *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOProperty *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOProperty *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOProperty *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOProperty *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Value)(ADOProperty *This,VARIANT *pval);
      HRESULT (WINAPI *put_Value)(ADOProperty *This,VARIANT val);
      HRESULT (WINAPI *get_Name)(ADOProperty *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Type)(ADOProperty *This,DataTypeEnum *ptype);
      HRESULT (WINAPI *get_Attributes)(ADOProperty *This,__LONG32 *plAttributes);
      HRESULT (WINAPI *put_Attributes)(ADOProperty *This,__LONG32 lAttributes);
    END_INTERFACE
  } PropertyVtbl;
  struct Property {
    CONST_VTBL struct PropertyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Property_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Property_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Property_Release(This) (This)->lpVtbl->Release(This)
#define Property_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Property_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Property_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Property_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Property_get_Value(This,pval) (This)->lpVtbl->get_Value(This,pval)
#define Property_put_Value(This,val) (This)->lpVtbl->put_Value(This,val)
#define Property_get_Name(This,pbstr) (This)->lpVtbl->get_Name(This,pbstr)
#define Property_get_Type(This,ptype) (This)->lpVtbl->get_Type(This,ptype)
#define Property_get_Attributes(This,plAttributes) (This)->lpVtbl->get_Attributes(This,plAttributes)
#define Property_put_Attributes(This,lAttributes) (This)->lpVtbl->put_Attributes(This,lAttributes)
#endif
#endif
  HRESULT WINAPI Property_get_Value_Proxy(ADOProperty *This,VARIANT *pval);
  void __RPC_STUB Property_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Property_put_Value_Proxy(ADOProperty *This,VARIANT val);
  void __RPC_STUB Property_put_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Property_get_Name_Proxy(ADOProperty *This,BSTR *pbstr);
  void __RPC_STUB Property_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Property_get_Type_Proxy(ADOProperty *This,DataTypeEnum *ptype);
  void __RPC_STUB Property_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Property_get_Attributes_Proxy(ADOProperty *This,__LONG32 *plAttributes);
  void __RPC_STUB Property_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Property_put_Attributes_Proxy(ADOProperty *This,__LONG32 lAttributes);
  void __RPC_STUB Property_put_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Group;
#ifdef __cplusplus
  Group;
#endif
  EXTERN_C const CLSID CLSID_User;
#ifdef __cplusplus
  User;
#endif
  EXTERN_C const CLSID CLSID_Column;
#ifdef __cplusplus
  Column;
#endif
  EXTERN_C const CLSID CLSID_Index;
#ifdef __cplusplus
  Index;
#endif
  EXTERN_C const CLSID CLSID_Key;
#ifdef __cplusplus
  Key;
#endif

#ifndef __Tables_INTERFACE_DEFINED__
#define __Tables_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Tables;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOTables : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,Table **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct TablesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOTables *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOTables *This);
      ULONG (WINAPI *Release)(ADOTables *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOTables *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOTables *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOTables *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOTables *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOTables *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOTables *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOTables *This);
      HRESULT (WINAPI *get_Item)(ADOTables *This,VARIANT Item,Table **ppvObject);
      HRESULT (WINAPI *Append)(ADOTables *This,VARIANT Item);
      HRESULT (WINAPI *Delete)(ADOTables *This,VARIANT Item);
    END_INTERFACE
  } TablesVtbl;
  struct Tables {
    CONST_VTBL struct TablesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Tables_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Tables_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Tables_Release(This) (This)->lpVtbl->Release(This)
#define Tables_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Tables_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Tables_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Tables_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Tables_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Tables__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Tables_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Tables_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Tables_Append(This,Item) (This)->lpVtbl->Append(This,Item)
#define Tables_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Tables_get_Item_Proxy(ADOTables *This,VARIANT Item,Table **ppvObject);
  void __RPC_STUB Tables_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Tables_Append_Proxy(ADOTables *This,VARIANT Item);
  void __RPC_STUB Tables_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Tables_Delete_Proxy(ADOTables *This,VARIANT Item);
  void __RPC_STUB Tables_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Columns_INTERFACE_DEFINED__
#define __Columns_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Columns;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOColumns : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,Column **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item,DataTypeEnum Type = adVarWChar,__LONG32 DefinedSize = 0) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct ColumnsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOColumns *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOColumns *This);
      ULONG (WINAPI *Release)(ADOColumns *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOColumns *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOColumns *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOColumns *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOColumns *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOColumns *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOColumns *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOColumns *This);
      HRESULT (WINAPI *get_Item)(ADOColumns *This,VARIANT Item,Column **ppvObject);
      HRESULT (WINAPI *Append)(ADOColumns *This,VARIANT Item,DataTypeEnum Type,__LONG32 DefinedSize);
      HRESULT (WINAPI *Delete)(ADOColumns *This,VARIANT Item);
    END_INTERFACE
  } ColumnsVtbl;
  struct Columns {
    CONST_VTBL struct ColumnsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Columns_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Columns_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Columns_Release(This) (This)->lpVtbl->Release(This)
#define Columns_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Columns_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Columns_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Columns_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Columns_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Columns__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Columns_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Columns_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Columns_Append(This,Item,Type,DefinedSize) (This)->lpVtbl->Append(This,Item,Type,DefinedSize)
#define Columns_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Columns_get_Item_Proxy(ADOColumns *This,VARIANT Item,Column **ppvObject);
  void __RPC_STUB Columns_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Columns_Append_Proxy(ADOColumns *This,VARIANT Item,DataTypeEnum Type,__LONG32 DefinedSize);
  void __RPC_STUB Columns_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Columns_Delete_Proxy(ADOColumns *This,VARIANT Item);
  void __RPC_STUB Columns_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Procedures_INTERFACE_DEFINED__
#define __Procedures_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Procedures;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOProcedures : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,ADOProcedure **ppvObject) = 0;
    virtual HRESULT WINAPI Append(BSTR Name,IDispatch *Command) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct ProceduresVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOProcedures *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOProcedures *This);
      ULONG (WINAPI *Release)(ADOProcedures *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOProcedures *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOProcedures *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOProcedures *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOProcedures *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOProcedures *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOProcedures *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOProcedures *This);
      HRESULT (WINAPI *get_Item)(ADOProcedures *This,VARIANT Item,ADOProcedure **ppvObject);
      HRESULT (WINAPI *Append)(ADOProcedures *This,BSTR Name,IDispatch *Command);
      HRESULT (WINAPI *Delete)(ADOProcedures *This,VARIANT Item);
    END_INTERFACE
  } ProceduresVtbl;
  struct Procedures {
    CONST_VTBL struct ProceduresVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Procedures_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Procedures_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Procedures_Release(This) (This)->lpVtbl->Release(This)
#define Procedures_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Procedures_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Procedures_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Procedures_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Procedures_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Procedures__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Procedures_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Procedures_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Procedures_Append(This,Name,Command) (This)->lpVtbl->Append(This,Name,Command)
#define Procedures_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Procedures_get_Item_Proxy(ADOProcedures *This,VARIANT Item,ADOProcedure **ppvObject);
  void __RPC_STUB Procedures_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedures_Append_Proxy(ADOProcedures *This,BSTR Name,IDispatch *Command);
  void __RPC_STUB Procedures_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Procedures_Delete_Proxy(ADOProcedures *This,VARIANT Item);
  void __RPC_STUB Procedures_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Views_INTERFACE_DEFINED__
#define __Views_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Views;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOViews : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,ADOView **ppvObject) = 0;
    virtual HRESULT WINAPI Append(BSTR Name,IDispatch *Command) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct ViewsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOViews *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOViews *This);
      ULONG (WINAPI *Release)(ADOViews *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOViews *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOViews *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOViews *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOViews *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOViews *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOViews *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOViews *This);
      HRESULT (WINAPI *get_Item)(ADOViews *This,VARIANT Item,ADOView **ppvObject);
      HRESULT (WINAPI *Append)(ADOViews *This,BSTR Name,IDispatch *Command);
      HRESULT (WINAPI *Delete)(ADOViews *This,VARIANT Item);
    END_INTERFACE
  } ViewsVtbl;
  struct Views {
    CONST_VTBL struct ViewsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Views_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Views_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Views_Release(This) (This)->lpVtbl->Release(This)
#define Views_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Views_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Views_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Views_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Views_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Views__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Views_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Views_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Views_Append(This,Name,Command) (This)->lpVtbl->Append(This,Name,Command)
#define Views_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Views_get_Item_Proxy(ADOViews *This,VARIANT Item,ADOView **ppvObject);
  void __RPC_STUB Views_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Views_Append_Proxy(ADOViews *This,BSTR Name,IDispatch *Command);
  void __RPC_STUB Views_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Views_Delete_Proxy(ADOViews *This,VARIANT Item);
  void __RPC_STUB Views_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Indexes_INTERFACE_DEFINED__
#define __Indexes_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Indexes;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOIndexes : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,Index **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item,VARIANT columns) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct IndexesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOIndexes *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOIndexes *This);
      ULONG (WINAPI *Release)(ADOIndexes *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOIndexes *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOIndexes *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOIndexes *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOIndexes *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOIndexes *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOIndexes *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOIndexes *This);
      HRESULT (WINAPI *get_Item)(ADOIndexes *This,VARIANT Item,Index **ppvObject);
      HRESULT (WINAPI *Append)(ADOIndexes *This,VARIANT Item,VARIANT columns);
      HRESULT (WINAPI *Delete)(ADOIndexes *This,VARIANT Item);
    END_INTERFACE
  } IndexesVtbl;
  struct Indexes {
    CONST_VTBL struct IndexesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Indexes_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Indexes_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Indexes_Release(This) (This)->lpVtbl->Release(This)
#define Indexes_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Indexes_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Indexes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Indexes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Indexes_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Indexes__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Indexes_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Indexes_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Indexes_Append(This,Item,columns) (This)->lpVtbl->Append(This,Item,columns)
#define Indexes_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Indexes_get_Item_Proxy(ADOIndexes *This,VARIANT Item,Index **ppvObject);
  void __RPC_STUB Indexes_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Indexes_Append_Proxy(ADOIndexes *This,VARIANT Item,VARIANT columns);
  void __RPC_STUB Indexes_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Indexes_Delete_Proxy(ADOIndexes *This,VARIANT Item);
  void __RPC_STUB Indexes_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Keys_INTERFACE_DEFINED__
#define __Keys_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Keys;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOKeys : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,Key **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item,KeyTypeEnum Type,VARIANT Column,BSTR RelatedADOTable = L"",BSTR RelatedADOColumn = L"") = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct KeysVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOKeys *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOKeys *This);
      ULONG (WINAPI *Release)(ADOKeys *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOKeys *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOKeys *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOKeys *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOKeys *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOKeys *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOKeys *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOKeys *This);
      HRESULT (WINAPI *get_Item)(ADOKeys *This,VARIANT Item,Key **ppvObject);
      HRESULT (WINAPI *Append)(ADOKeys *This,VARIANT Item,KeyTypeEnum Type,VARIANT Column,BSTR RelatedTable,BSTR RelatedColumn);
      HRESULT (WINAPI *Delete)(ADOKeys *This,VARIANT Item);
    END_INTERFACE
  } KeysVtbl;
  struct Keys {
    CONST_VTBL struct KeysVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Keys_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Keys_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Keys_Release(This) (This)->lpVtbl->Release(This)
#define Keys_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Keys_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Keys_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Keys_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Keys_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Keys__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Keys_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Keys_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Keys_Append(This,Item,Type,Column,RelatedTable,RelatedColumn) (This)->lpVtbl->Append(This,Item,Type,Column,RelatedTable,RelatedColumn)
#define Keys_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Keys_get_Item_Proxy(ADOKeys *This,VARIANT Item,Key **ppvObject);
  void __RPC_STUB Keys_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Keys_Append_Proxy(ADOKeys *This,VARIANT Item,KeyTypeEnum Type,VARIANT Column,BSTR RelatedTable,BSTR RelatedColumn);
  void __RPC_STUB Keys_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Keys_Delete_Proxy(ADOKeys *This,VARIANT Item);
  void __RPC_STUB Keys_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Users_INTERFACE_DEFINED__
#define __Users_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Users;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOUsers : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,User **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item,BSTR Password = L"") = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct UsersVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOUsers *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOUsers *This);
      ULONG (WINAPI *Release)(ADOUsers *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOUsers *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOUsers *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOUsers *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOUsers *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOUsers *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOUsers *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOUsers *This);
      HRESULT (WINAPI *get_Item)(ADOUsers *This,VARIANT Item,User **ppvObject);
      HRESULT (WINAPI *Append)(ADOUsers *This,VARIANT Item,BSTR Password);
      HRESULT (WINAPI *Delete)(ADOUsers *This,VARIANT Item);
    END_INTERFACE
  } UsersVtbl;
  struct Users {
    CONST_VTBL struct UsersVtbl *lpVtbl;
  };

#ifdef COBJMACROS
#define Users_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Users_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Users_Release(This) (This)->lpVtbl->Release(This)
#define Users_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Users_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Users_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Users_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Users_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Users__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Users_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Users_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Users_Append(This,Item,Password) (This)->lpVtbl->Append(This,Item,Password)
#define Users_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Users_get_Item_Proxy(ADOUsers *This,VARIANT Item,User **ppvObject);
  void __RPC_STUB Users_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Users_Append_Proxy(ADOUsers *This,VARIANT Item,BSTR Password);
  void __RPC_STUB Users_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Users_Delete_Proxy(ADOUsers *This,VARIANT Item);
  void __RPC_STUB Users_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Groups_INTERFACE_DEFINED__
#define __Groups_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Groups;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOGroups : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,Group **ppvObject) = 0;
    virtual HRESULT WINAPI Append(VARIANT Item) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Item) = 0;
  };
#else
  typedef struct GroupsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOGroups *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOGroups *This);
      ULONG (WINAPI *Release)(ADOGroups *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOGroups *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOGroups *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOGroups *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOGroups *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOGroups *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOGroups *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOGroups *This);
      HRESULT (WINAPI *get_Item)(ADOGroups *This,VARIANT Item,Group **ppvObject);
      HRESULT (WINAPI *Append)(ADOGroups *This,VARIANT Item);
      HRESULT (WINAPI *Delete)(ADOGroups *This,VARIANT Item);
    END_INTERFACE
  } GroupsVtbl;
  struct Groups {
    CONST_VTBL struct GroupsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Groups_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Groups_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Groups_Release(This) (This)->lpVtbl->Release(This)
#define Groups_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Groups_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Groups_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Groups_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Groups_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Groups__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Groups_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Groups_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#define Groups_Append(This,Item) (This)->lpVtbl->Append(This,Item)
#define Groups_Delete(This,Item) (This)->lpVtbl->Delete(This,Item)
#endif
#endif
  HRESULT WINAPI Groups_get_Item_Proxy(ADOGroups *This,VARIANT Item,Group **ppvObject);
  void __RPC_STUB Groups_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Groups_Append_Proxy(ADOGroups *This,VARIANT Item);
  void __RPC_STUB Groups_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Groups_Delete_Proxy(ADOGroups *This,VARIANT Item);
  void __RPC_STUB Groups_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Properties_INTERFACE_DEFINED__
#define __Properties_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Properties;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOProperties : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Item,ADOProperty **ppvObject) = 0;
  };
#else
  typedef struct PropertiesVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOProperties *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOProperties *This);
      ULONG (WINAPI *Release)(ADOProperties *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOProperties *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOProperties *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOProperties *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOProperties *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOProperties *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOProperties *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOProperties *This);
      HRESULT (WINAPI *get_Item)(ADOProperties *This,VARIANT Item,ADOProperty **ppvObject);
    END_INTERFACE
  } PropertiesVtbl;
  struct Properties {
    CONST_VTBL struct PropertiesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Properties_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define Properties_AddRef(This) (This)->lpVtbl->AddRef(This)
#define Properties_Release(This) (This)->lpVtbl->Release(This)
#define Properties_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define Properties_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Properties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Properties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Properties_get_Count(This,c) (This)->lpVtbl->get_Count(This,c)
#define Properties__NewEnum(This,ppvObject) (This)->lpVtbl->_NewEnum(This,ppvObject)
#define Properties_Refresh(This) (This)->lpVtbl->Refresh(This)
#define Properties_get_Item(This,Item,ppvObject) (This)->lpVtbl->get_Item(This,Item,ppvObject)
#endif
#endif
  HRESULT WINAPI Properties_get_Item_Proxy(ADOProperties *This,VARIANT Item,ADOProperty **ppvObject);
  void __RPC_STUB Properties_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif

#define ADOCatalog _ADOCatalog
#define ADOTable _ADOTable
#define ADOGroup _ADOGroup
#define ADOUser _ADOUser
#define ADOIndex _ADOIndex
#define ADOColumn _ADOColumn
#define ADOKey _ADOKey
#define ADOParameter _ADOParameter
#define ADOCollection _ADOCollection
#define ADODynaCollection _ADODynaCollection
#endif
