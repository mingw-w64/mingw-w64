/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __dimm_h__
#define __dimm_h__

#ifndef __IEnumRegisterWordA_FWD_DEFINED__
#define __IEnumRegisterWordA_FWD_DEFINED__
typedef struct IEnumRegisterWordA IEnumRegisterWordA;
#endif

#ifndef __IEnumRegisterWordW_FWD_DEFINED__
#define __IEnumRegisterWordW_FWD_DEFINED__
typedef struct IEnumRegisterWordW IEnumRegisterWordW;
#endif

#ifndef __IEnumInputContext_FWD_DEFINED__
#define __IEnumInputContext_FWD_DEFINED__
typedef struct IEnumInputContext IEnumInputContext;
#endif

#ifndef __IActiveIMMRegistrar_FWD_DEFINED__
#define __IActiveIMMRegistrar_FWD_DEFINED__
typedef struct IActiveIMMRegistrar IActiveIMMRegistrar;
#endif

#ifndef __IActiveIMMMessagePumpOwner_FWD_DEFINED__
#define __IActiveIMMMessagePumpOwner_FWD_DEFINED__
typedef struct IActiveIMMMessagePumpOwner IActiveIMMMessagePumpOwner;
#endif

#ifndef __IActiveIMMApp_FWD_DEFINED__
#define __IActiveIMMApp_FWD_DEFINED__
typedef struct IActiveIMMApp IActiveIMMApp;
#endif

#ifndef __IActiveIMMIME_FWD_DEFINED__
#define __IActiveIMMIME_FWD_DEFINED__
typedef struct IActiveIMMIME IActiveIMMIME;
#endif

#ifndef __IActiveIME_FWD_DEFINED__
#define __IActiveIME_FWD_DEFINED__
typedef struct IActiveIME IActiveIME;
#endif

#ifndef __IActiveIME2_FWD_DEFINED__
#define __IActiveIME2_FWD_DEFINED__
typedef struct IActiveIME2 IActiveIME2;
#endif

#ifndef __CActiveIMM_FWD_DEFINED__
#define __CActiveIMM_FWD_DEFINED__
#ifdef __cplusplus
typedef class CActiveIMM CActiveIMM;
#else
typedef struct CActiveIMM CActiveIMM;
#endif
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

  extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_dimm_0000_v0_0_s_ifspec;

#ifndef __ActiveIMM_LIBRARY_DEFINED__
#define __ActiveIMM_LIBRARY_DEFINED__

#include <imm.h>

#ifndef _DDKIMM_H_
  typedef struct __MIDL___MIDL_itf_dimm_0000_0012 {
    HWND hWnd;
    WINBOOL fOpen;
    POINT ptStatusWndPos;
    POINT ptSoftKbdPos;
    DWORD fdwConversion;
    DWORD fdwSentence;
    __C89_NAMELESS union {
      LOGFONTA A;
      LOGFONTW W;
    } lfFont;
    COMPOSITIONFORM cfCompForm;
    CANDIDATEFORM cfCandForm[4 ];
    HIMCC hCompStr;
    HIMCC hCandInfo;
    HIMCC hGuideLine;
    HIMCC hPrivate;
    DWORD dwNumMsgBuf;
    HIMCC hMsgBuf;
    DWORD fdwInit;
    DWORD dwReserve[3 ];
  } INPUTCONTEXT;

  typedef struct __MIDL___MIDL_itf_dimm_0000_0014 {
    DWORD dwPrivateDataSize;
    DWORD fdwProperty;
    DWORD fdwConversionCaps;
    DWORD fdwSentenceCaps;
    DWORD fdwUICaps;
    DWORD fdwSCSCaps;
    DWORD fdwSelectCaps;
  } IMEINFO;
#endif

  EXTERN_C const IID LIBID_ActiveIMM;
#ifndef __IEnumRegisterWordA_INTERFACE_DEFINED__
#define __IEnumRegisterWordA_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumRegisterWordA;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumRegisterWordA : public IUnknown {
  public:
    virtual HRESULT WINAPI Clone(IEnumRegisterWordA **ppEnum) = 0;
    virtual HRESULT WINAPI Next(ULONG ulCount,REGISTERWORDA *rgRegisterWord,ULONG *pcFetched) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Skip(ULONG ulCount) = 0;
  };
#else
  typedef struct IEnumRegisterWordAVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumRegisterWordA *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumRegisterWordA *This);
      ULONG (WINAPI *Release)(IEnumRegisterWordA *This);
      HRESULT (WINAPI *Clone)(IEnumRegisterWordA *This,IEnumRegisterWordA **ppEnum);
      HRESULT (WINAPI *Next)(IEnumRegisterWordA *This,ULONG ulCount,REGISTERWORDA *rgRegisterWord,ULONG *pcFetched);
      HRESULT (WINAPI *Reset)(IEnumRegisterWordA *This);
      HRESULT (WINAPI *Skip)(IEnumRegisterWordA *This,ULONG ulCount);
    END_INTERFACE
  } IEnumRegisterWordAVtbl;
  struct IEnumRegisterWordA {
    CONST_VTBL struct IEnumRegisterWordAVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumRegisterWordA_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumRegisterWordA_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumRegisterWordA_Release(This) (This)->lpVtbl->Release(This)
#define IEnumRegisterWordA_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumRegisterWordA_Next(This,ulCount,rgRegisterWord,pcFetched) (This)->lpVtbl->Next(This,ulCount,rgRegisterWord,pcFetched)
#define IEnumRegisterWordA_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumRegisterWordA_Skip(This,ulCount) (This)->lpVtbl->Skip(This,ulCount)
#endif
#endif
  HRESULT WINAPI IEnumRegisterWordA_Clone_Proxy(IEnumRegisterWordA *This,IEnumRegisterWordA **ppEnum);
  void __RPC_STUB IEnumRegisterWordA_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordA_Next_Proxy(IEnumRegisterWordA *This,ULONG ulCount,REGISTERWORDA *rgRegisterWord,ULONG *pcFetched);
  void __RPC_STUB IEnumRegisterWordA_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordA_Reset_Proxy(IEnumRegisterWordA *This);
  void __RPC_STUB IEnumRegisterWordA_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordA_Skip_Proxy(IEnumRegisterWordA *This,ULONG ulCount);
  void __RPC_STUB IEnumRegisterWordA_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumRegisterWordW_INTERFACE_DEFINED__
#define __IEnumRegisterWordW_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumRegisterWordW;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumRegisterWordW : public IUnknown {
  public:
    virtual HRESULT WINAPI Clone(IEnumRegisterWordW **ppEnum) = 0;
    virtual HRESULT WINAPI Next(ULONG ulCount,REGISTERWORDW *rgRegisterWord,ULONG *pcFetched) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Skip(ULONG ulCount) = 0;
  };
#else
  typedef struct IEnumRegisterWordWVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumRegisterWordW *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumRegisterWordW *This);
      ULONG (WINAPI *Release)(IEnumRegisterWordW *This);
      HRESULT (WINAPI *Clone)(IEnumRegisterWordW *This,IEnumRegisterWordW **ppEnum);
      HRESULT (WINAPI *Next)(IEnumRegisterWordW *This,ULONG ulCount,REGISTERWORDW *rgRegisterWord,ULONG *pcFetched);
      HRESULT (WINAPI *Reset)(IEnumRegisterWordW *This);
      HRESULT (WINAPI *Skip)(IEnumRegisterWordW *This,ULONG ulCount);
    END_INTERFACE
  } IEnumRegisterWordWVtbl;
  struct IEnumRegisterWordW {
    CONST_VTBL struct IEnumRegisterWordWVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumRegisterWordW_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumRegisterWordW_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumRegisterWordW_Release(This) (This)->lpVtbl->Release(This)
#define IEnumRegisterWordW_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumRegisterWordW_Next(This,ulCount,rgRegisterWord,pcFetched) (This)->lpVtbl->Next(This,ulCount,rgRegisterWord,pcFetched)
#define IEnumRegisterWordW_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumRegisterWordW_Skip(This,ulCount) (This)->lpVtbl->Skip(This,ulCount)
#endif
#endif
  HRESULT WINAPI IEnumRegisterWordW_Clone_Proxy(IEnumRegisterWordW *This,IEnumRegisterWordW **ppEnum);
  void __RPC_STUB IEnumRegisterWordW_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordW_Next_Proxy(IEnumRegisterWordW *This,ULONG ulCount,REGISTERWORDW *rgRegisterWord,ULONG *pcFetched);
  void __RPC_STUB IEnumRegisterWordW_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordW_Reset_Proxy(IEnumRegisterWordW *This);
  void __RPC_STUB IEnumRegisterWordW_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumRegisterWordW_Skip_Proxy(IEnumRegisterWordW *This,ULONG ulCount);
  void __RPC_STUB IEnumRegisterWordW_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IEnumInputContext_INTERFACE_DEFINED__
#define __IEnumInputContext_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IEnumInputContext;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IEnumInputContext : public IUnknown {
  public:
    virtual HRESULT WINAPI Clone(IEnumInputContext **ppEnum) = 0;
    virtual HRESULT WINAPI Next(ULONG ulCount,HIMC *rgInputContext,ULONG *pcFetched) = 0;
    virtual HRESULT WINAPI Reset(void) = 0;
    virtual HRESULT WINAPI Skip(ULONG ulCount) = 0;
  };
#else
  typedef struct IEnumInputContextVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IEnumInputContext *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IEnumInputContext *This);
      ULONG (WINAPI *Release)(IEnumInputContext *This);
      HRESULT (WINAPI *Clone)(IEnumInputContext *This,IEnumInputContext **ppEnum);
      HRESULT (WINAPI *Next)(IEnumInputContext *This,ULONG ulCount,HIMC *rgInputContext,ULONG *pcFetched);
      HRESULT (WINAPI *Reset)(IEnumInputContext *This);
      HRESULT (WINAPI *Skip)(IEnumInputContext *This,ULONG ulCount);
    END_INTERFACE
  } IEnumInputContextVtbl;
  struct IEnumInputContext {
    CONST_VTBL struct IEnumInputContextVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IEnumInputContext_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumInputContext_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumInputContext_Release(This) (This)->lpVtbl->Release(This)
#define IEnumInputContext_Clone(This,ppEnum) (This)->lpVtbl->Clone(This,ppEnum)
#define IEnumInputContext_Next(This,ulCount,rgInputContext,pcFetched) (This)->lpVtbl->Next(This,ulCount,rgInputContext,pcFetched)
#define IEnumInputContext_Reset(This) (This)->lpVtbl->Reset(This)
#define IEnumInputContext_Skip(This,ulCount) (This)->lpVtbl->Skip(This,ulCount)
#endif
#endif
  HRESULT WINAPI IEnumInputContext_Clone_Proxy(IEnumInputContext *This,IEnumInputContext **ppEnum);
  void __RPC_STUB IEnumInputContext_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumInputContext_Next_Proxy(IEnumInputContext *This,ULONG ulCount,HIMC *rgInputContext,ULONG *pcFetched);
  void __RPC_STUB IEnumInputContext_Next_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumInputContext_Reset_Proxy(IEnumInputContext *This);
  void __RPC_STUB IEnumInputContext_Reset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IEnumInputContext_Skip_Proxy(IEnumInputContext *This,ULONG ulCount);
  void __RPC_STUB IEnumInputContext_Skip_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIMMRegistrar_INTERFACE_DEFINED__
#define __IActiveIMMRegistrar_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIMMRegistrar;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIMMRegistrar : public IUnknown {
  public:
    virtual HRESULT WINAPI RegisterIME(REFCLSID rclsid,LANGID lgid,LPCWSTR pszIconFile,LPCWSTR pszDesc) = 0;
    virtual HRESULT WINAPI UnregisterIME(REFCLSID rclsid) = 0;
  };
#else
  typedef struct IActiveIMMRegistrarVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIMMRegistrar *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIMMRegistrar *This);
      ULONG (WINAPI *Release)(IActiveIMMRegistrar *This);
      HRESULT (WINAPI *RegisterIME)(IActiveIMMRegistrar *This,REFCLSID rclsid,LANGID lgid,LPCWSTR pszIconFile,LPCWSTR pszDesc);
      HRESULT (WINAPI *UnregisterIME)(IActiveIMMRegistrar *This,REFCLSID rclsid);
    END_INTERFACE
  } IActiveIMMRegistrarVtbl;
  struct IActiveIMMRegistrar {
    CONST_VTBL struct IActiveIMMRegistrarVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIMMRegistrar_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIMMRegistrar_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIMMRegistrar_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIMMRegistrar_RegisterIME(This,rclsid,lgid,pszIconFile,pszDesc) (This)->lpVtbl->RegisterIME(This,rclsid,lgid,pszIconFile,pszDesc)
#define IActiveIMMRegistrar_UnregisterIME(This,rclsid) (This)->lpVtbl->UnregisterIME(This,rclsid)
#endif
#endif
  HRESULT WINAPI IActiveIMMRegistrar_RegisterIME_Proxy(IActiveIMMRegistrar *This,REFCLSID rclsid,LANGID lgid,LPCWSTR pszIconFile,LPCWSTR pszDesc);
  void __RPC_STUB IActiveIMMRegistrar_RegisterIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMRegistrar_UnregisterIME_Proxy(IActiveIMMRegistrar *This,REFCLSID rclsid);
  void __RPC_STUB IActiveIMMRegistrar_UnregisterIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__
#define __IActiveIMMMessagePumpOwner_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIMMMessagePumpOwner;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIMMMessagePumpOwner : public IUnknown {
  public:
    virtual HRESULT WINAPI Start(void) = 0;
    virtual HRESULT WINAPI End(void) = 0;
    virtual HRESULT WINAPI OnTranslateMessage(const MSG *pMsg) = 0;
    virtual HRESULT WINAPI Pause(DWORD *pdwCookie) = 0;
    virtual HRESULT WINAPI Resume(DWORD dwCookie) = 0;
  };
#else
  typedef struct IActiveIMMMessagePumpOwnerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIMMMessagePumpOwner *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIMMMessagePumpOwner *This);
      ULONG (WINAPI *Release)(IActiveIMMMessagePumpOwner *This);
      HRESULT (WINAPI *Start)(IActiveIMMMessagePumpOwner *This);
      HRESULT (WINAPI *End)(IActiveIMMMessagePumpOwner *This);
      HRESULT (WINAPI *OnTranslateMessage)(IActiveIMMMessagePumpOwner *This,const MSG *pMsg);
      HRESULT (WINAPI *Pause)(IActiveIMMMessagePumpOwner *This,DWORD *pdwCookie);
      HRESULT (WINAPI *Resume)(IActiveIMMMessagePumpOwner *This,DWORD dwCookie);
    END_INTERFACE
  } IActiveIMMMessagePumpOwnerVtbl;
  struct IActiveIMMMessagePumpOwner {
    CONST_VTBL struct IActiveIMMMessagePumpOwnerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIMMMessagePumpOwner_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIMMMessagePumpOwner_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIMMMessagePumpOwner_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIMMMessagePumpOwner_Start(This) (This)->lpVtbl->Start(This)
#define IActiveIMMMessagePumpOwner_End(This) (This)->lpVtbl->End(This)
#define IActiveIMMMessagePumpOwner_OnTranslateMessage(This,pMsg) (This)->lpVtbl->OnTranslateMessage(This,pMsg)
#define IActiveIMMMessagePumpOwner_Pause(This,pdwCookie) (This)->lpVtbl->Pause(This,pdwCookie)
#define IActiveIMMMessagePumpOwner_Resume(This,dwCookie) (This)->lpVtbl->Resume(This,dwCookie)
#endif
#endif
  HRESULT WINAPI IActiveIMMMessagePumpOwner_Start_Proxy(IActiveIMMMessagePumpOwner *This);
  void __RPC_STUB IActiveIMMMessagePumpOwner_Start_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMMessagePumpOwner_End_Proxy(IActiveIMMMessagePumpOwner *This);
  void __RPC_STUB IActiveIMMMessagePumpOwner_End_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMMessagePumpOwner_OnTranslateMessage_Proxy(IActiveIMMMessagePumpOwner *This,const MSG *pMsg);
  void __RPC_STUB IActiveIMMMessagePumpOwner_OnTranslateMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMMessagePumpOwner_Pause_Proxy(IActiveIMMMessagePumpOwner *This,DWORD *pdwCookie);
  void __RPC_STUB IActiveIMMMessagePumpOwner_Pause_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMMessagePumpOwner_Resume_Proxy(IActiveIMMMessagePumpOwner *This,DWORD dwCookie);
  void __RPC_STUB IActiveIMMMessagePumpOwner_Resume_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIMMApp_INTERFACE_DEFINED__
#define __IActiveIMMApp_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIMMApp;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIMMApp : public IUnknown {
  public:
    virtual HRESULT WINAPI AssociateContext(HWND hWnd,HIMC hIME,HIMC *phPrev) = 0;
    virtual HRESULT WINAPI ConfigureIMEA(HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData) = 0;
    virtual HRESULT WINAPI ConfigureIMEW(HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData) = 0;
    virtual HRESULT WINAPI CreateContext(HIMC *phIMC) = 0;
    virtual HRESULT WINAPI DestroyContext(HIMC hIME) = 0;
    virtual HRESULT WINAPI EnumRegisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum) = 0;
    virtual HRESULT WINAPI EnumRegisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum) = 0;
    virtual HRESULT WINAPI EscapeA(HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI EscapeW(HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI GetCandidateListA(HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetCandidateListW(HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetCandidateListCountA(HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen) = 0;
    virtual HRESULT WINAPI GetCandidateListCountW(HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen) = 0;
    virtual HRESULT WINAPI GetCandidateWindow(HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate) = 0;
    virtual HRESULT WINAPI GetCompositionFontA(HIMC hIMC,LOGFONTA *plf) = 0;
    virtual HRESULT WINAPI GetCompositionFontW(HIMC hIMC,LOGFONTW *plf) = 0;
    virtual HRESULT WINAPI GetCompositionStringA(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf) = 0;
    virtual HRESULT WINAPI GetCompositionStringW(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf) = 0;
    virtual HRESULT WINAPI GetCompositionWindow(HIMC hIMC,COMPOSITIONFORM *pCompForm) = 0;
    virtual HRESULT WINAPI GetContext(HWND hWnd,HIMC *phIMC) = 0;
    virtual HRESULT WINAPI GetConversionListA(HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetConversionListW(HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetConversionStatus(HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence) = 0;
    virtual HRESULT WINAPI GetDefaultIMEWnd(HWND hWnd,HWND *phDefWnd) = 0;
    virtual HRESULT WINAPI GetDescriptionA(HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetDescriptionW(HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetGuideLineA(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetGuideLineW(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetIMEFileNameA(HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetIMEFileNameW(HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetOpenStatus(HIMC hIMC) = 0;
    virtual HRESULT WINAPI GetProperty(HKL hKL,DWORD fdwIndex,DWORD *pdwProperty) = 0;
    virtual HRESULT WINAPI GetRegisterWordStyleA(HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetRegisterWordStyleW(HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetStatusWindowPos(HIMC hIMC,POINT *pptPos) = 0;
    virtual HRESULT WINAPI GetVirtualKey(HWND hWnd,UINT *puVirtualKey) = 0;
    virtual HRESULT WINAPI InstallIMEA(LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL) = 0;
    virtual HRESULT WINAPI InstallIMEW(LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL) = 0;
    virtual HRESULT WINAPI IsIME(HKL hKL) = 0;
    virtual HRESULT WINAPI IsUIMessageA(HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam) = 0;
    virtual HRESULT WINAPI IsUIMessageW(HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam) = 0;
    virtual HRESULT WINAPI NotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue) = 0;
    virtual HRESULT WINAPI RegisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister) = 0;
    virtual HRESULT WINAPI RegisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister) = 0;
    virtual HRESULT WINAPI ReleaseContext(HWND hWnd,HIMC hIMC) = 0;
    virtual HRESULT WINAPI SetCandidateWindow(HIMC hIMC,CANDIDATEFORM *pCandidate) = 0;
    virtual HRESULT WINAPI SetCompositionFontA(HIMC hIMC,LOGFONTA *plf) = 0;
    virtual HRESULT WINAPI SetCompositionFontW(HIMC hIMC,LOGFONTW *plf) = 0;
    virtual HRESULT WINAPI SetCompositionStringA(HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen) = 0;
    virtual HRESULT WINAPI SetCompositionStringW(HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen) = 0;
    virtual HRESULT WINAPI SetCompositionWindow(HIMC hIMC,COMPOSITIONFORM *pCompForm) = 0;
    virtual HRESULT WINAPI SetConversionStatus(HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence) = 0;
    virtual HRESULT WINAPI SetOpenStatus(HIMC hIMC,WINBOOL fOpen) = 0;
    virtual HRESULT WINAPI SetStatusWindowPos(HIMC hIMC,POINT *pptPos) = 0;
    virtual HRESULT WINAPI SimulateHotKey(HWND hWnd,DWORD dwHotKeyID) = 0;
    virtual HRESULT WINAPI UnregisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister) = 0;
    virtual HRESULT WINAPI UnregisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister) = 0;
    virtual HRESULT WINAPI Activate(WINBOOL fRestoreLayout) = 0;
    virtual HRESULT WINAPI Deactivate(void) = 0;
    virtual HRESULT WINAPI OnDefWindowProc(HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI FilterClientWindows(ATOM *aaClassList,UINT uSize) = 0;
    virtual HRESULT WINAPI GetCodePageA(HKL hKL,UINT *uCodePage) = 0;
    virtual HRESULT WINAPI GetLangId(HKL hKL,LANGID *plid) = 0;
    virtual HRESULT WINAPI AssociateContextEx(HWND hWnd,HIMC hIMC,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI DisableIME(DWORD idThread) = 0;
    virtual HRESULT WINAPI GetImeMenuItemsA(HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetImeMenuItemsW(HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI EnumInputContext(DWORD idThread,IEnumInputContext **ppEnum) = 0;
  };
#else
  typedef struct IActiveIMMAppVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIMMApp *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIMMApp *This);
      ULONG (WINAPI *Release)(IActiveIMMApp *This);
      HRESULT (WINAPI *AssociateContext)(IActiveIMMApp *This,HWND hWnd,HIMC hIME,HIMC *phPrev);
      HRESULT (WINAPI *ConfigureIMEA)(IActiveIMMApp *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData);
      HRESULT (WINAPI *ConfigureIMEW)(IActiveIMMApp *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData);
      HRESULT (WINAPI *CreateContext)(IActiveIMMApp *This,HIMC *phIMC);
      HRESULT (WINAPI *DestroyContext)(IActiveIMMApp *This,HIMC hIME);
      HRESULT (WINAPI *EnumRegisterWordA)(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum);
      HRESULT (WINAPI *EnumRegisterWordW)(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum);
      HRESULT (WINAPI *EscapeA)(IActiveIMMApp *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
      HRESULT (WINAPI *EscapeW)(IActiveIMMApp *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
      HRESULT (WINAPI *GetCandidateListA)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
      HRESULT (WINAPI *GetCandidateListW)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
      HRESULT (WINAPI *GetCandidateListCountA)(IActiveIMMApp *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
      HRESULT (WINAPI *GetCandidateListCountW)(IActiveIMMApp *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
      HRESULT (WINAPI *GetCandidateWindow)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate);
      HRESULT (WINAPI *GetCompositionFontA)(IActiveIMMApp *This,HIMC hIMC,LOGFONTA *plf);
      HRESULT (WINAPI *GetCompositionFontW)(IActiveIMMApp *This,HIMC hIMC,LOGFONTW *plf);
      HRESULT (WINAPI *GetCompositionStringA)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
      HRESULT (WINAPI *GetCompositionStringW)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
      HRESULT (WINAPI *GetCompositionWindow)(IActiveIMMApp *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
      HRESULT (WINAPI *GetContext)(IActiveIMMApp *This,HWND hWnd,HIMC *phIMC);
      HRESULT (WINAPI *GetConversionListA)(IActiveIMMApp *This,HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
      HRESULT (WINAPI *GetConversionListW)(IActiveIMMApp *This,HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
      HRESULT (WINAPI *GetConversionStatus)(IActiveIMMApp *This,HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence);
      HRESULT (WINAPI *GetDefaultIMEWnd)(IActiveIMMApp *This,HWND hWnd,HWND *phDefWnd);
      HRESULT (WINAPI *GetDescriptionA)(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied);
      HRESULT (WINAPI *GetDescriptionW)(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied);
      HRESULT (WINAPI *GetGuideLineA)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult);
      HRESULT (WINAPI *GetGuideLineW)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult);
      HRESULT (WINAPI *GetIMEFileNameA)(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied);
      HRESULT (WINAPI *GetIMEFileNameW)(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied);
      HRESULT (WINAPI *GetOpenStatus)(IActiveIMMApp *This,HIMC hIMC);
      HRESULT (WINAPI *GetProperty)(IActiveIMMApp *This,HKL hKL,DWORD fdwIndex,DWORD *pdwProperty);
      HRESULT (WINAPI *GetRegisterWordStyleA)(IActiveIMMApp *This,HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied);
      HRESULT (WINAPI *GetRegisterWordStyleW)(IActiveIMMApp *This,HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied);
      HRESULT (WINAPI *GetStatusWindowPos)(IActiveIMMApp *This,HIMC hIMC,POINT *pptPos);
      HRESULT (WINAPI *GetVirtualKey)(IActiveIMMApp *This,HWND hWnd,UINT *puVirtualKey);
      HRESULT (WINAPI *InstallIMEA)(IActiveIMMApp *This,LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL);
      HRESULT (WINAPI *InstallIMEW)(IActiveIMMApp *This,LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL);
      HRESULT (WINAPI *IsIME)(IActiveIMMApp *This,HKL hKL);
      HRESULT (WINAPI *IsUIMessageA)(IActiveIMMApp *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
      HRESULT (WINAPI *IsUIMessageW)(IActiveIMMApp *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
      HRESULT (WINAPI *NotifyIME)(IActiveIMMApp *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
      HRESULT (WINAPI *RegisterWordA)(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister);
      HRESULT (WINAPI *RegisterWordW)(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister);
      HRESULT (WINAPI *ReleaseContext)(IActiveIMMApp *This,HWND hWnd,HIMC hIMC);
      HRESULT (WINAPI *SetCandidateWindow)(IActiveIMMApp *This,HIMC hIMC,CANDIDATEFORM *pCandidate);
      HRESULT (WINAPI *SetCompositionFontA)(IActiveIMMApp *This,HIMC hIMC,LOGFONTA *plf);
      HRESULT (WINAPI *SetCompositionFontW)(IActiveIMMApp *This,HIMC hIMC,LOGFONTW *plf);
      HRESULT (WINAPI *SetCompositionStringA)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
      HRESULT (WINAPI *SetCompositionStringW)(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
      HRESULT (WINAPI *SetCompositionWindow)(IActiveIMMApp *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
      HRESULT (WINAPI *SetConversionStatus)(IActiveIMMApp *This,HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence);
      HRESULT (WINAPI *SetOpenStatus)(IActiveIMMApp *This,HIMC hIMC,WINBOOL fOpen);
      HRESULT (WINAPI *SetStatusWindowPos)(IActiveIMMApp *This,HIMC hIMC,POINT *pptPos);
      HRESULT (WINAPI *SimulateHotKey)(IActiveIMMApp *This,HWND hWnd,DWORD dwHotKeyID);
      HRESULT (WINAPI *UnregisterWordA)(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister);
      HRESULT (WINAPI *UnregisterWordW)(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister);
      HRESULT (WINAPI *Activate)(IActiveIMMApp *This,WINBOOL fRestoreLayout);
      HRESULT (WINAPI *Deactivate)(IActiveIMMApp *This);
      HRESULT (WINAPI *OnDefWindowProc)(IActiveIMMApp *This,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
      HRESULT (WINAPI *FilterClientWindows)(IActiveIMMApp *This,ATOM *aaClassList,UINT uSize);
      HRESULT (WINAPI *GetCodePageA)(IActiveIMMApp *This,HKL hKL,UINT *uCodePage);
      HRESULT (WINAPI *GetLangId)(IActiveIMMApp *This,HKL hKL,LANGID *plid);
      HRESULT (WINAPI *AssociateContextEx)(IActiveIMMApp *This,HWND hWnd,HIMC hIMC,DWORD dwFlags);
      HRESULT (WINAPI *DisableIME)(IActiveIMMApp *This,DWORD idThread);
      HRESULT (WINAPI *GetImeMenuItemsA)(IActiveIMMApp *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult);
      HRESULT (WINAPI *GetImeMenuItemsW)(IActiveIMMApp *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult);
      HRESULT (WINAPI *EnumInputContext)(IActiveIMMApp *This,DWORD idThread,IEnumInputContext **ppEnum);
    END_INTERFACE
  } IActiveIMMAppVtbl;
  struct IActiveIMMApp {
    CONST_VTBL struct IActiveIMMAppVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIMMApp_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIMMApp_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIMMApp_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIMMApp_AssociateContext(This,hWnd,hIME,phPrev) (This)->lpVtbl->AssociateContext(This,hWnd,hIME,phPrev)
#define IActiveIMMApp_ConfigureIMEA(This,hKL,hWnd,dwMode,pData) (This)->lpVtbl->ConfigureIMEA(This,hKL,hWnd,dwMode,pData)
#define IActiveIMMApp_ConfigureIMEW(This,hKL,hWnd,dwMode,pData) (This)->lpVtbl->ConfigureIMEW(This,hKL,hWnd,dwMode,pData)
#define IActiveIMMApp_CreateContext(This,phIMC) (This)->lpVtbl->CreateContext(This,phIMC)
#define IActiveIMMApp_DestroyContext(This,hIME) (This)->lpVtbl->DestroyContext(This,hIME)
#define IActiveIMMApp_EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) (This)->lpVtbl->EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)
#define IActiveIMMApp_EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) (This)->lpVtbl->EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)
#define IActiveIMMApp_EscapeA(This,hKL,hIMC,uEscape,pData,plResult) (This)->lpVtbl->EscapeA(This,hKL,hIMC,uEscape,pData,plResult)
#define IActiveIMMApp_EscapeW(This,hKL,hIMC,uEscape,pData,plResult) (This)->lpVtbl->EscapeW(This,hKL,hIMC,uEscape,pData,plResult)
#define IActiveIMMApp_GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) (This)->lpVtbl->GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)
#define IActiveIMMApp_GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) (This)->lpVtbl->GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)
#define IActiveIMMApp_GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen) (This)->lpVtbl->GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen)
#define IActiveIMMApp_GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen) (This)->lpVtbl->GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen)
#define IActiveIMMApp_GetCandidateWindow(This,hIMC,dwIndex,pCandidate) (This)->lpVtbl->GetCandidateWindow(This,hIMC,dwIndex,pCandidate)
#define IActiveIMMApp_GetCompositionFontA(This,hIMC,plf) (This)->lpVtbl->GetCompositionFontA(This,hIMC,plf)
#define IActiveIMMApp_GetCompositionFontW(This,hIMC,plf) (This)->lpVtbl->GetCompositionFontW(This,hIMC,plf)
#define IActiveIMMApp_GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) (This)->lpVtbl->GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)
#define IActiveIMMApp_GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) (This)->lpVtbl->GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)
#define IActiveIMMApp_GetCompositionWindow(This,hIMC,pCompForm) (This)->lpVtbl->GetCompositionWindow(This,hIMC,pCompForm)
#define IActiveIMMApp_GetContext(This,hWnd,phIMC) (This)->lpVtbl->GetContext(This,hWnd,phIMC)
#define IActiveIMMApp_GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) (This)->lpVtbl->GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)
#define IActiveIMMApp_GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) (This)->lpVtbl->GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)
#define IActiveIMMApp_GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence) (This)->lpVtbl->GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence)
#define IActiveIMMApp_GetDefaultIMEWnd(This,hWnd,phDefWnd) (This)->lpVtbl->GetDefaultIMEWnd(This,hWnd,phDefWnd)
#define IActiveIMMApp_GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied) (This)->lpVtbl->GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied)
#define IActiveIMMApp_GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied) (This)->lpVtbl->GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied)
#define IActiveIMMApp_GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) (This)->lpVtbl->GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)
#define IActiveIMMApp_GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) (This)->lpVtbl->GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)
#define IActiveIMMApp_GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied) (This)->lpVtbl->GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied)
#define IActiveIMMApp_GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied) (This)->lpVtbl->GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied)
#define IActiveIMMApp_GetOpenStatus(This,hIMC) (This)->lpVtbl->GetOpenStatus(This,hIMC)
#define IActiveIMMApp_GetProperty(This,hKL,fdwIndex,pdwProperty) (This)->lpVtbl->GetProperty(This,hKL,fdwIndex,pdwProperty)
#define IActiveIMMApp_GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied) (This)->lpVtbl->GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied)
#define IActiveIMMApp_GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied) (This)->lpVtbl->GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied)
#define IActiveIMMApp_GetStatusWindowPos(This,hIMC,pptPos) (This)->lpVtbl->GetStatusWindowPos(This,hIMC,pptPos)
#define IActiveIMMApp_GetVirtualKey(This,hWnd,puVirtualKey) (This)->lpVtbl->GetVirtualKey(This,hWnd,puVirtualKey)
#define IActiveIMMApp_InstallIMEA(This,szIMEFileName,szLayoutText,phKL) (This)->lpVtbl->InstallIMEA(This,szIMEFileName,szLayoutText,phKL)
#define IActiveIMMApp_InstallIMEW(This,szIMEFileName,szLayoutText,phKL) (This)->lpVtbl->InstallIMEW(This,szIMEFileName,szLayoutText,phKL)
#define IActiveIMMApp_IsIME(This,hKL) (This)->lpVtbl->IsIME(This,hKL)
#define IActiveIMMApp_IsUIMessageA(This,hWndIME,msg,wParam,lParam) (This)->lpVtbl->IsUIMessageA(This,hWndIME,msg,wParam,lParam)
#define IActiveIMMApp_IsUIMessageW(This,hWndIME,msg,wParam,lParam) (This)->lpVtbl->IsUIMessageW(This,hWndIME,msg,wParam,lParam)
#define IActiveIMMApp_NotifyIME(This,hIMC,dwAction,dwIndex,dwValue) (This)->lpVtbl->NotifyIME(This,hIMC,dwAction,dwIndex,dwValue)
#define IActiveIMMApp_RegisterWordA(This,hKL,szReading,dwStyle,szRegister) (This)->lpVtbl->RegisterWordA(This,hKL,szReading,dwStyle,szRegister)
#define IActiveIMMApp_RegisterWordW(This,hKL,szReading,dwStyle,szRegister) (This)->lpVtbl->RegisterWordW(This,hKL,szReading,dwStyle,szRegister)
#define IActiveIMMApp_ReleaseContext(This,hWnd,hIMC) (This)->lpVtbl->ReleaseContext(This,hWnd,hIMC)
#define IActiveIMMApp_SetCandidateWindow(This,hIMC,pCandidate) (This)->lpVtbl->SetCandidateWindow(This,hIMC,pCandidate)
#define IActiveIMMApp_SetCompositionFontA(This,hIMC,plf) (This)->lpVtbl->SetCompositionFontA(This,hIMC,plf)
#define IActiveIMMApp_SetCompositionFontW(This,hIMC,plf) (This)->lpVtbl->SetCompositionFontW(This,hIMC,plf)
#define IActiveIMMApp_SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIMMApp_SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIMMApp_SetCompositionWindow(This,hIMC,pCompForm) (This)->lpVtbl->SetCompositionWindow(This,hIMC,pCompForm)
#define IActiveIMMApp_SetConversionStatus(This,hIMC,fdwConversion,fdwSentence) (This)->lpVtbl->SetConversionStatus(This,hIMC,fdwConversion,fdwSentence)
#define IActiveIMMApp_SetOpenStatus(This,hIMC,fOpen) (This)->lpVtbl->SetOpenStatus(This,hIMC,fOpen)
#define IActiveIMMApp_SetStatusWindowPos(This,hIMC,pptPos) (This)->lpVtbl->SetStatusWindowPos(This,hIMC,pptPos)
#define IActiveIMMApp_SimulateHotKey(This,hWnd,dwHotKeyID) (This)->lpVtbl->SimulateHotKey(This,hWnd,dwHotKeyID)
#define IActiveIMMApp_UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister) (This)->lpVtbl->UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister)
#define IActiveIMMApp_UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister) (This)->lpVtbl->UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister)
#define IActiveIMMApp_Activate(This,fRestoreLayout) (This)->lpVtbl->Activate(This,fRestoreLayout)
#define IActiveIMMApp_Deactivate(This) (This)->lpVtbl->Deactivate(This)
#define IActiveIMMApp_OnDefWindowProc(This,hWnd,Msg,wParam,lParam,plResult) (This)->lpVtbl->OnDefWindowProc(This,hWnd,Msg,wParam,lParam,plResult)
#define IActiveIMMApp_FilterClientWindows(This,aaClassList,uSize) (This)->lpVtbl->FilterClientWindows(This,aaClassList,uSize)
#define IActiveIMMApp_GetCodePageA(This,hKL,uCodePage) (This)->lpVtbl->GetCodePageA(This,hKL,uCodePage)
#define IActiveIMMApp_GetLangId(This,hKL,plid) (This)->lpVtbl->GetLangId(This,hKL,plid)
#define IActiveIMMApp_AssociateContextEx(This,hWnd,hIMC,dwFlags) (This)->lpVtbl->AssociateContextEx(This,hWnd,hIMC,dwFlags)
#define IActiveIMMApp_DisableIME(This,idThread) (This)->lpVtbl->DisableIME(This,idThread)
#define IActiveIMMApp_GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) (This)->lpVtbl->GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)
#define IActiveIMMApp_GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) (This)->lpVtbl->GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)
#define IActiveIMMApp_EnumInputContext(This,idThread,ppEnum) (This)->lpVtbl->EnumInputContext(This,idThread,ppEnum)
#endif
#endif
  HRESULT WINAPI IActiveIMMApp_AssociateContext_Proxy(IActiveIMMApp *This,HWND hWnd,HIMC hIME,HIMC *phPrev);
  void __RPC_STUB IActiveIMMApp_AssociateContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_ConfigureIMEA_Proxy(IActiveIMMApp *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData);
  void __RPC_STUB IActiveIMMApp_ConfigureIMEA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_ConfigureIMEW_Proxy(IActiveIMMApp *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData);
  void __RPC_STUB IActiveIMMApp_ConfigureIMEW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_CreateContext_Proxy(IActiveIMMApp *This,HIMC *phIMC);
  void __RPC_STUB IActiveIMMApp_CreateContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_DestroyContext_Proxy(IActiveIMMApp *This,HIMC hIME);
  void __RPC_STUB IActiveIMMApp_DestroyContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_EnumRegisterWordA_Proxy(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum);
  void __RPC_STUB IActiveIMMApp_EnumRegisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_EnumRegisterWordW_Proxy(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum);
  void __RPC_STUB IActiveIMMApp_EnumRegisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_EscapeA_Proxy(IActiveIMMApp *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
  void __RPC_STUB IActiveIMMApp_EscapeA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_EscapeW_Proxy(IActiveIMMApp *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
  void __RPC_STUB IActiveIMMApp_EscapeW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCandidateListA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetCandidateListA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCandidateListW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetCandidateListW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCandidateListCountA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
  void __RPC_STUB IActiveIMMApp_GetCandidateListCountA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCandidateListCountW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
  void __RPC_STUB IActiveIMMApp_GetCandidateListCountW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCandidateWindow_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate);
  void __RPC_STUB IActiveIMMApp_GetCandidateWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCompositionFontA_Proxy(IActiveIMMApp *This,HIMC hIMC,LOGFONTA *plf);
  void __RPC_STUB IActiveIMMApp_GetCompositionFontA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCompositionFontW_Proxy(IActiveIMMApp *This,HIMC hIMC,LOGFONTW *plf);
  void __RPC_STUB IActiveIMMApp_GetCompositionFontW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCompositionStringA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
  void __RPC_STUB IActiveIMMApp_GetCompositionStringA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCompositionStringW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
  void __RPC_STUB IActiveIMMApp_GetCompositionStringW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCompositionWindow_Proxy(IActiveIMMApp *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
  void __RPC_STUB IActiveIMMApp_GetCompositionWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetContext_Proxy(IActiveIMMApp *This,HWND hWnd,HIMC *phIMC);
  void __RPC_STUB IActiveIMMApp_GetContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetConversionListA_Proxy(IActiveIMMApp *This,HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetConversionListA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetConversionListW_Proxy(IActiveIMMApp *This,HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetConversionListW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetConversionStatus_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence);
  void __RPC_STUB IActiveIMMApp_GetConversionStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetDefaultIMEWnd_Proxy(IActiveIMMApp *This,HWND hWnd,HWND *phDefWnd);
  void __RPC_STUB IActiveIMMApp_GetDefaultIMEWnd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetDescriptionA_Proxy(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetDescriptionA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetDescriptionW_Proxy(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetDescriptionW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetGuideLineA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMApp_GetGuideLineA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetGuideLineW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMApp_GetGuideLineW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetIMEFileNameA_Proxy(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetIMEFileNameA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetIMEFileNameW_Proxy(IActiveIMMApp *This,HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetIMEFileNameW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetOpenStatus_Proxy(IActiveIMMApp *This,HIMC hIMC);
  void __RPC_STUB IActiveIMMApp_GetOpenStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetProperty_Proxy(IActiveIMMApp *This,HKL hKL,DWORD fdwIndex,DWORD *pdwProperty);
  void __RPC_STUB IActiveIMMApp_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetRegisterWordStyleA_Proxy(IActiveIMMApp *This,HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetRegisterWordStyleA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetRegisterWordStyleW_Proxy(IActiveIMMApp *This,HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied);
  void __RPC_STUB IActiveIMMApp_GetRegisterWordStyleW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetStatusWindowPos_Proxy(IActiveIMMApp *This,HIMC hIMC,POINT *pptPos);
  void __RPC_STUB IActiveIMMApp_GetStatusWindowPos_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetVirtualKey_Proxy(IActiveIMMApp *This,HWND hWnd,UINT *puVirtualKey);
  void __RPC_STUB IActiveIMMApp_GetVirtualKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_InstallIMEA_Proxy(IActiveIMMApp *This,LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL);
  void __RPC_STUB IActiveIMMApp_InstallIMEA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_InstallIMEW_Proxy(IActiveIMMApp *This,LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL);
  void __RPC_STUB IActiveIMMApp_InstallIMEW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_IsIME_Proxy(IActiveIMMApp *This,HKL hKL);
  void __RPC_STUB IActiveIMMApp_IsIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_IsUIMessageA_Proxy(IActiveIMMApp *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
  void __RPC_STUB IActiveIMMApp_IsUIMessageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_IsUIMessageW_Proxy(IActiveIMMApp *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
  void __RPC_STUB IActiveIMMApp_IsUIMessageW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_NotifyIME_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
  void __RPC_STUB IActiveIMMApp_NotifyIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_RegisterWordA_Proxy(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister);
  void __RPC_STUB IActiveIMMApp_RegisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_RegisterWordW_Proxy(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister);
  void __RPC_STUB IActiveIMMApp_RegisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_ReleaseContext_Proxy(IActiveIMMApp *This,HWND hWnd,HIMC hIMC);
  void __RPC_STUB IActiveIMMApp_ReleaseContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCandidateWindow_Proxy(IActiveIMMApp *This,HIMC hIMC,CANDIDATEFORM *pCandidate);
  void __RPC_STUB IActiveIMMApp_SetCandidateWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCompositionFontA_Proxy(IActiveIMMApp *This,HIMC hIMC,LOGFONTA *plf);
  void __RPC_STUB IActiveIMMApp_SetCompositionFontA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCompositionFontW_Proxy(IActiveIMMApp *This,HIMC hIMC,LOGFONTW *plf);
  void __RPC_STUB IActiveIMMApp_SetCompositionFontW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCompositionStringA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
  void __RPC_STUB IActiveIMMApp_SetCompositionStringA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCompositionStringW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
  void __RPC_STUB IActiveIMMApp_SetCompositionStringW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetCompositionWindow_Proxy(IActiveIMMApp *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
  void __RPC_STUB IActiveIMMApp_SetCompositionWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetConversionStatus_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence);
  void __RPC_STUB IActiveIMMApp_SetConversionStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetOpenStatus_Proxy(IActiveIMMApp *This,HIMC hIMC,WINBOOL fOpen);
  void __RPC_STUB IActiveIMMApp_SetOpenStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SetStatusWindowPos_Proxy(IActiveIMMApp *This,HIMC hIMC,POINT *pptPos);
  void __RPC_STUB IActiveIMMApp_SetStatusWindowPos_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_SimulateHotKey_Proxy(IActiveIMMApp *This,HWND hWnd,DWORD dwHotKeyID);
  void __RPC_STUB IActiveIMMApp_SimulateHotKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_UnregisterWordA_Proxy(IActiveIMMApp *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister);
  void __RPC_STUB IActiveIMMApp_UnregisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_UnregisterWordW_Proxy(IActiveIMMApp *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister);
  void __RPC_STUB IActiveIMMApp_UnregisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_Activate_Proxy(IActiveIMMApp *This,WINBOOL fRestoreLayout);
  void __RPC_STUB IActiveIMMApp_Activate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_Deactivate_Proxy(IActiveIMMApp *This);
  void __RPC_STUB IActiveIMMApp_Deactivate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_OnDefWindowProc_Proxy(IActiveIMMApp *This,HWND hWnd,UINT Msg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
  void __RPC_STUB IActiveIMMApp_OnDefWindowProc_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_FilterClientWindows_Proxy(IActiveIMMApp *This,ATOM *aaClassList,UINT uSize);
  void __RPC_STUB IActiveIMMApp_FilterClientWindows_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetCodePageA_Proxy(IActiveIMMApp *This,HKL hKL,UINT *uCodePage);
  void __RPC_STUB IActiveIMMApp_GetCodePageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetLangId_Proxy(IActiveIMMApp *This,HKL hKL,LANGID *plid);
  void __RPC_STUB IActiveIMMApp_GetLangId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_AssociateContextEx_Proxy(IActiveIMMApp *This,HWND hWnd,HIMC hIMC,DWORD dwFlags);
  void __RPC_STUB IActiveIMMApp_AssociateContextEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_DisableIME_Proxy(IActiveIMMApp *This,DWORD idThread);
  void __RPC_STUB IActiveIMMApp_DisableIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetImeMenuItemsA_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMApp_GetImeMenuItemsA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_GetImeMenuItemsW_Proxy(IActiveIMMApp *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMApp_GetImeMenuItemsW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMApp_EnumInputContext_Proxy(IActiveIMMApp *This,DWORD idThread,IEnumInputContext **ppEnum);
  void __RPC_STUB IActiveIMMApp_EnumInputContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIMMIME_INTERFACE_DEFINED__
#define __IActiveIMMIME_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIMMIME;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIMMIME : public IUnknown {
  public:
    virtual HRESULT WINAPI AssociateContext(HWND hWnd,HIMC hIME,HIMC *phPrev) = 0;
    virtual HRESULT WINAPI ConfigureIMEA(HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData) = 0;
    virtual HRESULT WINAPI ConfigureIMEW(HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData) = 0;
    virtual HRESULT WINAPI CreateContext(HIMC *phIMC) = 0;
    virtual HRESULT WINAPI DestroyContext(HIMC hIME) = 0;
    virtual HRESULT WINAPI EnumRegisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum) = 0;
    virtual HRESULT WINAPI EnumRegisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum) = 0;
    virtual HRESULT WINAPI EscapeA(HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI EscapeW(HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI GetCandidateListA(HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetCandidateListW(HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetCandidateListCountA(HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen) = 0;
    virtual HRESULT WINAPI GetCandidateListCountW(HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen) = 0;
    virtual HRESULT WINAPI GetCandidateWindow(HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate) = 0;
    virtual HRESULT WINAPI GetCompositionFontA(HIMC hIMC,LOGFONTA *plf) = 0;
    virtual HRESULT WINAPI GetCompositionFontW(HIMC hIMC,LOGFONTW *plf) = 0;
    virtual HRESULT WINAPI GetCompositionStringA(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf) = 0;
    virtual HRESULT WINAPI GetCompositionStringW(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf) = 0;
    virtual HRESULT WINAPI GetCompositionWindow(HIMC hIMC,COMPOSITIONFORM *pCompForm) = 0;
    virtual HRESULT WINAPI GetContext(HWND hWnd,HIMC *phIMC) = 0;
    virtual HRESULT WINAPI GetConversionListA(HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetConversionListW(HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetConversionStatus(HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence) = 0;
    virtual HRESULT WINAPI GetDefaultIMEWnd(HWND hWnd,HWND *phDefWnd) = 0;
    virtual HRESULT WINAPI GetDescriptionA(HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetDescriptionW(HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetGuideLineA(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetGuideLineW(HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetIMEFileNameA(HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetIMEFileNameW(HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetOpenStatus(HIMC hIMC) = 0;
    virtual HRESULT WINAPI GetProperty(HKL hKL,DWORD fdwIndex,DWORD *pdwProperty) = 0;
    virtual HRESULT WINAPI GetRegisterWordStyleA(HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetRegisterWordStyleW(HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied) = 0;
    virtual HRESULT WINAPI GetStatusWindowPos(HIMC hIMC,POINT *pptPos) = 0;
    virtual HRESULT WINAPI GetVirtualKey(HWND hWnd,UINT *puVirtualKey) = 0;
    virtual HRESULT WINAPI InstallIMEA(LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL) = 0;
    virtual HRESULT WINAPI InstallIMEW(LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL) = 0;
    virtual HRESULT WINAPI IsIME(HKL hKL) = 0;
    virtual HRESULT WINAPI IsUIMessageA(HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam) = 0;
    virtual HRESULT WINAPI IsUIMessageW(HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam) = 0;
    virtual HRESULT WINAPI NotifyIME(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue) = 0;
    virtual HRESULT WINAPI RegisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister) = 0;
    virtual HRESULT WINAPI RegisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister) = 0;
    virtual HRESULT WINAPI ReleaseContext(HWND hWnd,HIMC hIMC) = 0;
    virtual HRESULT WINAPI SetCandidateWindow(HIMC hIMC,CANDIDATEFORM *pCandidate) = 0;
    virtual HRESULT WINAPI SetCompositionFontA(HIMC hIMC,LOGFONTA *plf) = 0;
    virtual HRESULT WINAPI SetCompositionFontW(HIMC hIMC,LOGFONTW *plf) = 0;
    virtual HRESULT WINAPI SetCompositionStringA(HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen) = 0;
    virtual HRESULT WINAPI SetCompositionStringW(HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen) = 0;
    virtual HRESULT WINAPI SetCompositionWindow(HIMC hIMC,COMPOSITIONFORM *pCompForm) = 0;
    virtual HRESULT WINAPI SetConversionStatus(HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence) = 0;
    virtual HRESULT WINAPI SetOpenStatus(HIMC hIMC,WINBOOL fOpen) = 0;
    virtual HRESULT WINAPI SetStatusWindowPos(HIMC hIMC,POINT *pptPos) = 0;
    virtual HRESULT WINAPI SimulateHotKey(HWND hWnd,DWORD dwHotKeyID) = 0;
    virtual HRESULT WINAPI UnregisterWordA(HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister) = 0;
    virtual HRESULT WINAPI UnregisterWordW(HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister) = 0;
    virtual HRESULT WINAPI GenerateMessage(HIMC hIMC) = 0;
    virtual HRESULT WINAPI LockIMC(HIMC hIMC,INPUTCONTEXT **ppIMC) = 0;
    virtual HRESULT WINAPI UnlockIMC(HIMC hIMC) = 0;
    virtual HRESULT WINAPI GetIMCLockCount(HIMC hIMC,DWORD *pdwLockCount) = 0;
    virtual HRESULT WINAPI CreateIMCC(DWORD dwSize,HIMCC *phIMCC) = 0;
    virtual HRESULT WINAPI DestroyIMCC(HIMCC hIMCC) = 0;
    virtual HRESULT WINAPI LockIMCC(HIMCC hIMCC,void **ppv) = 0;
    virtual HRESULT WINAPI UnlockIMCC(HIMCC hIMCC) = 0;
    virtual HRESULT WINAPI ReSizeIMCC(HIMCC hIMCC,DWORD dwSize,HIMCC *phIMCC) = 0;
    virtual HRESULT WINAPI GetIMCCSize(HIMCC hIMCC,DWORD *pdwSize) = 0;
    virtual HRESULT WINAPI GetIMCCLockCount(HIMCC hIMCC,DWORD *pdwLockCount) = 0;
    virtual HRESULT WINAPI GetHotKey(DWORD dwHotKeyID,UINT *puModifiers,UINT *puVKey,HKL *phKL) = 0;
    virtual HRESULT WINAPI SetHotKey(DWORD dwHotKeyID,UINT uModifiers,UINT uVKey,HKL hKL) = 0;
    virtual HRESULT WINAPI CreateSoftKeyboard(UINT uType,HWND hOwner,int x,int y,HWND *phSoftKbdWnd) = 0;
    virtual HRESULT WINAPI DestroySoftKeyboard(HWND hSoftKbdWnd) = 0;
    virtual HRESULT WINAPI ShowSoftKeyboard(HWND hSoftKbdWnd,int nCmdShow) = 0;
    virtual HRESULT WINAPI GetCodePageA(HKL hKL,UINT *uCodePage) = 0;
    virtual HRESULT WINAPI GetLangId(HKL hKL,LANGID *plid) = 0;
    virtual HRESULT WINAPI KeybdEvent(LANGID lgidIME,BYTE bVk,BYTE bScan,DWORD dwFlags,DWORD dwExtraInfo) = 0;
    virtual HRESULT WINAPI LockModal(void) = 0;
    virtual HRESULT WINAPI UnlockModal(void) = 0;
    virtual HRESULT WINAPI AssociateContextEx(HWND hWnd,HIMC hIMC,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI DisableIME(DWORD idThread) = 0;
    virtual HRESULT WINAPI GetImeMenuItemsA(HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI GetImeMenuItemsW(HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult) = 0;
    virtual HRESULT WINAPI EnumInputContext(DWORD idThread,IEnumInputContext **ppEnum) = 0;
    virtual HRESULT WINAPI RequestMessageA(HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI RequestMessageW(HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI SendIMCA(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI SendIMCW(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI IsSleeping(void) = 0;
  };
#else
  typedef struct IActiveIMMIMEVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIMMIME *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIMMIME *This);
      ULONG (WINAPI *Release)(IActiveIMMIME *This);
      HRESULT (WINAPI *AssociateContext)(IActiveIMMIME *This,HWND hWnd,HIMC hIME,HIMC *phPrev);
      HRESULT (WINAPI *ConfigureIMEA)(IActiveIMMIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData);
      HRESULT (WINAPI *ConfigureIMEW)(IActiveIMMIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData);
      HRESULT (WINAPI *CreateContext)(IActiveIMMIME *This,HIMC *phIMC);
      HRESULT (WINAPI *DestroyContext)(IActiveIMMIME *This,HIMC hIME);
      HRESULT (WINAPI *EnumRegisterWordA)(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum);
      HRESULT (WINAPI *EnumRegisterWordW)(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum);
      HRESULT (WINAPI *EscapeA)(IActiveIMMIME *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
      HRESULT (WINAPI *EscapeW)(IActiveIMMIME *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
      HRESULT (WINAPI *GetCandidateListA)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
      HRESULT (WINAPI *GetCandidateListW)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
      HRESULT (WINAPI *GetCandidateListCountA)(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
      HRESULT (WINAPI *GetCandidateListCountW)(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
      HRESULT (WINAPI *GetCandidateWindow)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate);
      HRESULT (WINAPI *GetCompositionFontA)(IActiveIMMIME *This,HIMC hIMC,LOGFONTA *plf);
      HRESULT (WINAPI *GetCompositionFontW)(IActiveIMMIME *This,HIMC hIMC,LOGFONTW *plf);
      HRESULT (WINAPI *GetCompositionStringA)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
      HRESULT (WINAPI *GetCompositionStringW)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
      HRESULT (WINAPI *GetCompositionWindow)(IActiveIMMIME *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
      HRESULT (WINAPI *GetContext)(IActiveIMMIME *This,HWND hWnd,HIMC *phIMC);
      HRESULT (WINAPI *GetConversionListA)(IActiveIMMIME *This,HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
      HRESULT (WINAPI *GetConversionListW)(IActiveIMMIME *This,HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
      HRESULT (WINAPI *GetConversionStatus)(IActiveIMMIME *This,HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence);
      HRESULT (WINAPI *GetDefaultIMEWnd)(IActiveIMMIME *This,HWND hWnd,HWND *phDefWnd);
      HRESULT (WINAPI *GetDescriptionA)(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied);
      HRESULT (WINAPI *GetDescriptionW)(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied);
      HRESULT (WINAPI *GetGuideLineA)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult);
      HRESULT (WINAPI *GetGuideLineW)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult);
      HRESULT (WINAPI *GetIMEFileNameA)(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied);
      HRESULT (WINAPI *GetIMEFileNameW)(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied);
      HRESULT (WINAPI *GetOpenStatus)(IActiveIMMIME *This,HIMC hIMC);
      HRESULT (WINAPI *GetProperty)(IActiveIMMIME *This,HKL hKL,DWORD fdwIndex,DWORD *pdwProperty);
      HRESULT (WINAPI *GetRegisterWordStyleA)(IActiveIMMIME *This,HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied);
      HRESULT (WINAPI *GetRegisterWordStyleW)(IActiveIMMIME *This,HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied);
      HRESULT (WINAPI *GetStatusWindowPos)(IActiveIMMIME *This,HIMC hIMC,POINT *pptPos);
      HRESULT (WINAPI *GetVirtualKey)(IActiveIMMIME *This,HWND hWnd,UINT *puVirtualKey);
      HRESULT (WINAPI *InstallIMEA)(IActiveIMMIME *This,LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL);
      HRESULT (WINAPI *InstallIMEW)(IActiveIMMIME *This,LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL);
      HRESULT (WINAPI *IsIME)(IActiveIMMIME *This,HKL hKL);
      HRESULT (WINAPI *IsUIMessageA)(IActiveIMMIME *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
      HRESULT (WINAPI *IsUIMessageW)(IActiveIMMIME *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
      HRESULT (WINAPI *NotifyIME)(IActiveIMMIME *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
      HRESULT (WINAPI *RegisterWordA)(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister);
      HRESULT (WINAPI *RegisterWordW)(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister);
      HRESULT (WINAPI *ReleaseContext)(IActiveIMMIME *This,HWND hWnd,HIMC hIMC);
      HRESULT (WINAPI *SetCandidateWindow)(IActiveIMMIME *This,HIMC hIMC,CANDIDATEFORM *pCandidate);
      HRESULT (WINAPI *SetCompositionFontA)(IActiveIMMIME *This,HIMC hIMC,LOGFONTA *plf);
      HRESULT (WINAPI *SetCompositionFontW)(IActiveIMMIME *This,HIMC hIMC,LOGFONTW *plf);
      HRESULT (WINAPI *SetCompositionStringA)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
      HRESULT (WINAPI *SetCompositionStringW)(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
      HRESULT (WINAPI *SetCompositionWindow)(IActiveIMMIME *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
      HRESULT (WINAPI *SetConversionStatus)(IActiveIMMIME *This,HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence);
      HRESULT (WINAPI *SetOpenStatus)(IActiveIMMIME *This,HIMC hIMC,WINBOOL fOpen);
      HRESULT (WINAPI *SetStatusWindowPos)(IActiveIMMIME *This,HIMC hIMC,POINT *pptPos);
      HRESULT (WINAPI *SimulateHotKey)(IActiveIMMIME *This,HWND hWnd,DWORD dwHotKeyID);
      HRESULT (WINAPI *UnregisterWordA)(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister);
      HRESULT (WINAPI *UnregisterWordW)(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister);
      HRESULT (WINAPI *GenerateMessage)(IActiveIMMIME *This,HIMC hIMC);
      HRESULT (WINAPI *LockIMC)(IActiveIMMIME *This,HIMC hIMC,INPUTCONTEXT **ppIMC);
      HRESULT (WINAPI *UnlockIMC)(IActiveIMMIME *This,HIMC hIMC);
      HRESULT (WINAPI *GetIMCLockCount)(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwLockCount);
      HRESULT (WINAPI *CreateIMCC)(IActiveIMMIME *This,DWORD dwSize,HIMCC *phIMCC);
      HRESULT (WINAPI *DestroyIMCC)(IActiveIMMIME *This,HIMCC hIMCC);
      HRESULT (WINAPI *LockIMCC)(IActiveIMMIME *This,HIMCC hIMCC,void **ppv);
      HRESULT (WINAPI *UnlockIMCC)(IActiveIMMIME *This,HIMCC hIMCC);
      HRESULT (WINAPI *ReSizeIMCC)(IActiveIMMIME *This,HIMCC hIMCC,DWORD dwSize,HIMCC *phIMCC);
      HRESULT (WINAPI *GetIMCCSize)(IActiveIMMIME *This,HIMCC hIMCC,DWORD *pdwSize);
      HRESULT (WINAPI *GetIMCCLockCount)(IActiveIMMIME *This,HIMCC hIMCC,DWORD *pdwLockCount);
      HRESULT (WINAPI *GetHotKey)(IActiveIMMIME *This,DWORD dwHotKeyID,UINT *puModifiers,UINT *puVKey,HKL *phKL);
      HRESULT (WINAPI *SetHotKey)(IActiveIMMIME *This,DWORD dwHotKeyID,UINT uModifiers,UINT uVKey,HKL hKL);
      HRESULT (WINAPI *CreateSoftKeyboard)(IActiveIMMIME *This,UINT uType,HWND hOwner,int x,int y,HWND *phSoftKbdWnd);
      HRESULT (WINAPI *DestroySoftKeyboard)(IActiveIMMIME *This,HWND hSoftKbdWnd);
      HRESULT (WINAPI *ShowSoftKeyboard)(IActiveIMMIME *This,HWND hSoftKbdWnd,int nCmdShow);
      HRESULT (WINAPI *GetCodePageA)(IActiveIMMIME *This,HKL hKL,UINT *uCodePage);
      HRESULT (WINAPI *GetLangId)(IActiveIMMIME *This,HKL hKL,LANGID *plid);
      HRESULT (WINAPI *KeybdEvent)(IActiveIMMIME *This,LANGID lgidIME,BYTE bVk,BYTE bScan,DWORD dwFlags,DWORD dwExtraInfo);
      HRESULT (WINAPI *LockModal)(IActiveIMMIME *This);
      HRESULT (WINAPI *UnlockModal)(IActiveIMMIME *This);
      HRESULT (WINAPI *AssociateContextEx)(IActiveIMMIME *This,HWND hWnd,HIMC hIMC,DWORD dwFlags);
      HRESULT (WINAPI *DisableIME)(IActiveIMMIME *This,DWORD idThread);
      HRESULT (WINAPI *GetImeMenuItemsA)(IActiveIMMIME *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult);
      HRESULT (WINAPI *GetImeMenuItemsW)(IActiveIMMIME *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult);
      HRESULT (WINAPI *EnumInputContext)(IActiveIMMIME *This,DWORD idThread,IEnumInputContext **ppEnum);
      HRESULT (WINAPI *RequestMessageA)(IActiveIMMIME *This,HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
      HRESULT (WINAPI *RequestMessageW)(IActiveIMMIME *This,HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
      HRESULT (WINAPI *SendIMCA)(IActiveIMMIME *This,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
      HRESULT (WINAPI *SendIMCW)(IActiveIMMIME *This,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
      HRESULT (WINAPI *IsSleeping)(IActiveIMMIME *This);
    END_INTERFACE
  } IActiveIMMIMEVtbl;
  struct IActiveIMMIME {
    CONST_VTBL struct IActiveIMMIMEVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIMMIME_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIMMIME_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIMMIME_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIMMIME_AssociateContext(This,hWnd,hIME,phPrev) (This)->lpVtbl->AssociateContext(This,hWnd,hIME,phPrev)
#define IActiveIMMIME_ConfigureIMEA(This,hKL,hWnd,dwMode,pData) (This)->lpVtbl->ConfigureIMEA(This,hKL,hWnd,dwMode,pData)
#define IActiveIMMIME_ConfigureIMEW(This,hKL,hWnd,dwMode,pData) (This)->lpVtbl->ConfigureIMEW(This,hKL,hWnd,dwMode,pData)
#define IActiveIMMIME_CreateContext(This,phIMC) (This)->lpVtbl->CreateContext(This,phIMC)
#define IActiveIMMIME_DestroyContext(This,hIME) (This)->lpVtbl->DestroyContext(This,hIME)
#define IActiveIMMIME_EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) (This)->lpVtbl->EnumRegisterWordA(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)
#define IActiveIMMIME_EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum) (This)->lpVtbl->EnumRegisterWordW(This,hKL,szReading,dwStyle,szRegister,pData,pEnum)
#define IActiveIMMIME_EscapeA(This,hKL,hIMC,uEscape,pData,plResult) (This)->lpVtbl->EscapeA(This,hKL,hIMC,uEscape,pData,plResult)
#define IActiveIMMIME_EscapeW(This,hKL,hIMC,uEscape,pData,plResult) (This)->lpVtbl->EscapeW(This,hKL,hIMC,uEscape,pData,plResult)
#define IActiveIMMIME_GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) (This)->lpVtbl->GetCandidateListA(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)
#define IActiveIMMIME_GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied) (This)->lpVtbl->GetCandidateListW(This,hIMC,dwIndex,uBufLen,pCandList,puCopied)
#define IActiveIMMIME_GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen) (This)->lpVtbl->GetCandidateListCountA(This,hIMC,pdwListSize,pdwBufLen)
#define IActiveIMMIME_GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen) (This)->lpVtbl->GetCandidateListCountW(This,hIMC,pdwListSize,pdwBufLen)
#define IActiveIMMIME_GetCandidateWindow(This,hIMC,dwIndex,pCandidate) (This)->lpVtbl->GetCandidateWindow(This,hIMC,dwIndex,pCandidate)
#define IActiveIMMIME_GetCompositionFontA(This,hIMC,plf) (This)->lpVtbl->GetCompositionFontA(This,hIMC,plf)
#define IActiveIMMIME_GetCompositionFontW(This,hIMC,plf) (This)->lpVtbl->GetCompositionFontW(This,hIMC,plf)
#define IActiveIMMIME_GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) (This)->lpVtbl->GetCompositionStringA(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)
#define IActiveIMMIME_GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf) (This)->lpVtbl->GetCompositionStringW(This,hIMC,dwIndex,dwBufLen,plCopied,pBuf)
#define IActiveIMMIME_GetCompositionWindow(This,hIMC,pCompForm) (This)->lpVtbl->GetCompositionWindow(This,hIMC,pCompForm)
#define IActiveIMMIME_GetContext(This,hWnd,phIMC) (This)->lpVtbl->GetContext(This,hWnd,phIMC)
#define IActiveIMMIME_GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) (This)->lpVtbl->GetConversionListA(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)
#define IActiveIMMIME_GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied) (This)->lpVtbl->GetConversionListW(This,hKL,hIMC,pSrc,uBufLen,uFlag,pDst,puCopied)
#define IActiveIMMIME_GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence) (This)->lpVtbl->GetConversionStatus(This,hIMC,pfdwConversion,pfdwSentence)
#define IActiveIMMIME_GetDefaultIMEWnd(This,hWnd,phDefWnd) (This)->lpVtbl->GetDefaultIMEWnd(This,hWnd,phDefWnd)
#define IActiveIMMIME_GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied) (This)->lpVtbl->GetDescriptionA(This,hKL,uBufLen,szDescription,puCopied)
#define IActiveIMMIME_GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied) (This)->lpVtbl->GetDescriptionW(This,hKL,uBufLen,szDescription,puCopied)
#define IActiveIMMIME_GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) (This)->lpVtbl->GetGuideLineA(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)
#define IActiveIMMIME_GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult) (This)->lpVtbl->GetGuideLineW(This,hIMC,dwIndex,dwBufLen,pBuf,pdwResult)
#define IActiveIMMIME_GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied) (This)->lpVtbl->GetIMEFileNameA(This,hKL,uBufLen,szFileName,puCopied)
#define IActiveIMMIME_GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied) (This)->lpVtbl->GetIMEFileNameW(This,hKL,uBufLen,szFileName,puCopied)
#define IActiveIMMIME_GetOpenStatus(This,hIMC) (This)->lpVtbl->GetOpenStatus(This,hIMC)
#define IActiveIMMIME_GetProperty(This,hKL,fdwIndex,pdwProperty) (This)->lpVtbl->GetProperty(This,hKL,fdwIndex,pdwProperty)
#define IActiveIMMIME_GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied) (This)->lpVtbl->GetRegisterWordStyleA(This,hKL,nItem,pStyleBuf,puCopied)
#define IActiveIMMIME_GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied) (This)->lpVtbl->GetRegisterWordStyleW(This,hKL,nItem,pStyleBuf,puCopied)
#define IActiveIMMIME_GetStatusWindowPos(This,hIMC,pptPos) (This)->lpVtbl->GetStatusWindowPos(This,hIMC,pptPos)
#define IActiveIMMIME_GetVirtualKey(This,hWnd,puVirtualKey) (This)->lpVtbl->GetVirtualKey(This,hWnd,puVirtualKey)
#define IActiveIMMIME_InstallIMEA(This,szIMEFileName,szLayoutText,phKL) (This)->lpVtbl->InstallIMEA(This,szIMEFileName,szLayoutText,phKL)
#define IActiveIMMIME_InstallIMEW(This,szIMEFileName,szLayoutText,phKL) (This)->lpVtbl->InstallIMEW(This,szIMEFileName,szLayoutText,phKL)
#define IActiveIMMIME_IsIME(This,hKL) (This)->lpVtbl->IsIME(This,hKL)
#define IActiveIMMIME_IsUIMessageA(This,hWndIME,msg,wParam,lParam) (This)->lpVtbl->IsUIMessageA(This,hWndIME,msg,wParam,lParam)
#define IActiveIMMIME_IsUIMessageW(This,hWndIME,msg,wParam,lParam) (This)->lpVtbl->IsUIMessageW(This,hWndIME,msg,wParam,lParam)
#define IActiveIMMIME_NotifyIME(This,hIMC,dwAction,dwIndex,dwValue) (This)->lpVtbl->NotifyIME(This,hIMC,dwAction,dwIndex,dwValue)
#define IActiveIMMIME_RegisterWordA(This,hKL,szReading,dwStyle,szRegister) (This)->lpVtbl->RegisterWordA(This,hKL,szReading,dwStyle,szRegister)
#define IActiveIMMIME_RegisterWordW(This,hKL,szReading,dwStyle,szRegister) (This)->lpVtbl->RegisterWordW(This,hKL,szReading,dwStyle,szRegister)
#define IActiveIMMIME_ReleaseContext(This,hWnd,hIMC) (This)->lpVtbl->ReleaseContext(This,hWnd,hIMC)
#define IActiveIMMIME_SetCandidateWindow(This,hIMC,pCandidate) (This)->lpVtbl->SetCandidateWindow(This,hIMC,pCandidate)
#define IActiveIMMIME_SetCompositionFontA(This,hIMC,plf) (This)->lpVtbl->SetCompositionFontA(This,hIMC,plf)
#define IActiveIMMIME_SetCompositionFontW(This,hIMC,plf) (This)->lpVtbl->SetCompositionFontW(This,hIMC,plf)
#define IActiveIMMIME_SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionStringA(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIMMIME_SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionStringW(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIMMIME_SetCompositionWindow(This,hIMC,pCompForm) (This)->lpVtbl->SetCompositionWindow(This,hIMC,pCompForm)
#define IActiveIMMIME_SetConversionStatus(This,hIMC,fdwConversion,fdwSentence) (This)->lpVtbl->SetConversionStatus(This,hIMC,fdwConversion,fdwSentence)
#define IActiveIMMIME_SetOpenStatus(This,hIMC,fOpen) (This)->lpVtbl->SetOpenStatus(This,hIMC,fOpen)
#define IActiveIMMIME_SetStatusWindowPos(This,hIMC,pptPos) (This)->lpVtbl->SetStatusWindowPos(This,hIMC,pptPos)
#define IActiveIMMIME_SimulateHotKey(This,hWnd,dwHotKeyID) (This)->lpVtbl->SimulateHotKey(This,hWnd,dwHotKeyID)
#define IActiveIMMIME_UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister) (This)->lpVtbl->UnregisterWordA(This,hKL,szReading,dwStyle,szUnregister)
#define IActiveIMMIME_UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister) (This)->lpVtbl->UnregisterWordW(This,hKL,szReading,dwStyle,szUnregister)
#define IActiveIMMIME_GenerateMessage(This,hIMC) (This)->lpVtbl->GenerateMessage(This,hIMC)
#define IActiveIMMIME_LockIMC(This,hIMC,ppIMC) (This)->lpVtbl->LockIMC(This,hIMC,ppIMC)
#define IActiveIMMIME_UnlockIMC(This,hIMC) (This)->lpVtbl->UnlockIMC(This,hIMC)
#define IActiveIMMIME_GetIMCLockCount(This,hIMC,pdwLockCount) (This)->lpVtbl->GetIMCLockCount(This,hIMC,pdwLockCount)
#define IActiveIMMIME_CreateIMCC(This,dwSize,phIMCC) (This)->lpVtbl->CreateIMCC(This,dwSize,phIMCC)
#define IActiveIMMIME_DestroyIMCC(This,hIMCC) (This)->lpVtbl->DestroyIMCC(This,hIMCC)
#define IActiveIMMIME_LockIMCC(This,hIMCC,ppv) (This)->lpVtbl->LockIMCC(This,hIMCC,ppv)
#define IActiveIMMIME_UnlockIMCC(This,hIMCC) (This)->lpVtbl->UnlockIMCC(This,hIMCC)
#define IActiveIMMIME_ReSizeIMCC(This,hIMCC,dwSize,phIMCC) (This)->lpVtbl->ReSizeIMCC(This,hIMCC,dwSize,phIMCC)
#define IActiveIMMIME_GetIMCCSize(This,hIMCC,pdwSize) (This)->lpVtbl->GetIMCCSize(This,hIMCC,pdwSize)
#define IActiveIMMIME_GetIMCCLockCount(This,hIMCC,pdwLockCount) (This)->lpVtbl->GetIMCCLockCount(This,hIMCC,pdwLockCount)
#define IActiveIMMIME_GetHotKey(This,dwHotKeyID,puModifiers,puVKey,phKL) (This)->lpVtbl->GetHotKey(This,dwHotKeyID,puModifiers,puVKey,phKL)
#define IActiveIMMIME_SetHotKey(This,dwHotKeyID,uModifiers,uVKey,hKL) (This)->lpVtbl->SetHotKey(This,dwHotKeyID,uModifiers,uVKey,hKL)
#define IActiveIMMIME_CreateSoftKeyboard(This,uType,hOwner,x,y,phSoftKbdWnd) (This)->lpVtbl->CreateSoftKeyboard(This,uType,hOwner,x,y,phSoftKbdWnd)
#define IActiveIMMIME_DestroySoftKeyboard(This,hSoftKbdWnd) (This)->lpVtbl->DestroySoftKeyboard(This,hSoftKbdWnd)
#define IActiveIMMIME_ShowSoftKeyboard(This,hSoftKbdWnd,nCmdShow) (This)->lpVtbl->ShowSoftKeyboard(This,hSoftKbdWnd,nCmdShow)
#define IActiveIMMIME_GetCodePageA(This,hKL,uCodePage) (This)->lpVtbl->GetCodePageA(This,hKL,uCodePage)
#define IActiveIMMIME_GetLangId(This,hKL,plid) (This)->lpVtbl->GetLangId(This,hKL,plid)
#define IActiveIMMIME_KeybdEvent(This,lgidIME,bVk,bScan,dwFlags,dwExtraInfo) (This)->lpVtbl->KeybdEvent(This,lgidIME,bVk,bScan,dwFlags,dwExtraInfo)
#define IActiveIMMIME_LockModal(This) (This)->lpVtbl->LockModal(This)
#define IActiveIMMIME_UnlockModal(This) (This)->lpVtbl->UnlockModal(This)
#define IActiveIMMIME_AssociateContextEx(This,hWnd,hIMC,dwFlags) (This)->lpVtbl->AssociateContextEx(This,hWnd,hIMC,dwFlags)
#define IActiveIMMIME_DisableIME(This,idThread) (This)->lpVtbl->DisableIME(This,idThread)
#define IActiveIMMIME_GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) (This)->lpVtbl->GetImeMenuItemsA(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)
#define IActiveIMMIME_GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult) (This)->lpVtbl->GetImeMenuItemsW(This,hIMC,dwFlags,dwType,pImeParentMenu,pImeMenu,dwSize,pdwResult)
#define IActiveIMMIME_EnumInputContext(This,idThread,ppEnum) (This)->lpVtbl->EnumInputContext(This,idThread,ppEnum)
#define IActiveIMMIME_RequestMessageA(This,hIMC,wParam,lParam,plResult) (This)->lpVtbl->RequestMessageA(This,hIMC,wParam,lParam,plResult)
#define IActiveIMMIME_RequestMessageW(This,hIMC,wParam,lParam,plResult) (This)->lpVtbl->RequestMessageW(This,hIMC,wParam,lParam,plResult)
#define IActiveIMMIME_SendIMCA(This,hWnd,uMsg,wParam,lParam,plResult) (This)->lpVtbl->SendIMCA(This,hWnd,uMsg,wParam,lParam,plResult)
#define IActiveIMMIME_SendIMCW(This,hWnd,uMsg,wParam,lParam,plResult) (This)->lpVtbl->SendIMCW(This,hWnd,uMsg,wParam,lParam,plResult)
#define IActiveIMMIME_IsSleeping(This) (This)->lpVtbl->IsSleeping(This)
#endif
#endif
  HRESULT WINAPI IActiveIMMIME_AssociateContext_Proxy(IActiveIMMIME *This,HWND hWnd,HIMC hIME,HIMC *phPrev);
  void __RPC_STUB IActiveIMMIME_AssociateContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_ConfigureIMEA_Proxy(IActiveIMMIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDA *pData);
  void __RPC_STUB IActiveIMMIME_ConfigureIMEA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_ConfigureIMEW_Proxy(IActiveIMMIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pData);
  void __RPC_STUB IActiveIMMIME_ConfigureIMEW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_CreateContext_Proxy(IActiveIMMIME *This,HIMC *phIMC);
  void __RPC_STUB IActiveIMMIME_CreateContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_DestroyContext_Proxy(IActiveIMMIME *This,HIMC hIME);
  void __RPC_STUB IActiveIMMIME_DestroyContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_EnumRegisterWordA_Proxy(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister,LPVOID pData,IEnumRegisterWordA **pEnum);
  void __RPC_STUB IActiveIMMIME_EnumRegisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_EnumRegisterWordW_Proxy(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **pEnum);
  void __RPC_STUB IActiveIMMIME_EnumRegisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_EscapeA_Proxy(IActiveIMMIME *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_EscapeA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_EscapeW_Proxy(IActiveIMMIME *This,HKL hKL,HIMC hIMC,UINT uEscape,LPVOID pData,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_EscapeW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCandidateListA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetCandidateListA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCandidateListW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,UINT uBufLen,CANDIDATELIST *pCandList,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetCandidateListW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCandidateListCountA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
  void __RPC_STUB IActiveIMMIME_GetCandidateListCountA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCandidateListCountW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwListSize,DWORD *pdwBufLen);
  void __RPC_STUB IActiveIMMIME_GetCandidateListCountW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCandidateWindow_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,CANDIDATEFORM *pCandidate);
  void __RPC_STUB IActiveIMMIME_GetCandidateWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCompositionFontA_Proxy(IActiveIMMIME *This,HIMC hIMC,LOGFONTA *plf);
  void __RPC_STUB IActiveIMMIME_GetCompositionFontA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCompositionFontW_Proxy(IActiveIMMIME *This,HIMC hIMC,LOGFONTW *plf);
  void __RPC_STUB IActiveIMMIME_GetCompositionFontW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCompositionStringA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
  void __RPC_STUB IActiveIMMIME_GetCompositionStringA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCompositionStringW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LONG *plCopied,LPVOID pBuf);
  void __RPC_STUB IActiveIMMIME_GetCompositionStringW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCompositionWindow_Proxy(IActiveIMMIME *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
  void __RPC_STUB IActiveIMMIME_GetCompositionWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetContext_Proxy(IActiveIMMIME *This,HWND hWnd,HIMC *phIMC);
  void __RPC_STUB IActiveIMMIME_GetContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetConversionListA_Proxy(IActiveIMMIME *This,HKL hKL,HIMC hIMC,LPSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetConversionListA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetConversionListW_Proxy(IActiveIMMIME *This,HKL hKL,HIMC hIMC,LPWSTR pSrc,UINT uBufLen,UINT uFlag,CANDIDATELIST *pDst,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetConversionListW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetConversionStatus_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD *pfdwConversion,DWORD *pfdwSentence);
  void __RPC_STUB IActiveIMMIME_GetConversionStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetDefaultIMEWnd_Proxy(IActiveIMMIME *This,HWND hWnd,HWND *phDefWnd);
  void __RPC_STUB IActiveIMMIME_GetDefaultIMEWnd_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetDescriptionA_Proxy(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPSTR szDescription,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetDescriptionA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetDescriptionW_Proxy(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPWSTR szDescription,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetDescriptionW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetGuideLineA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPSTR pBuf,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMIME_GetGuideLineA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetGuideLineW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,DWORD dwBufLen,LPWSTR pBuf,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMIME_GetGuideLineW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetIMEFileNameA_Proxy(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPSTR szFileName,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetIMEFileNameA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetIMEFileNameW_Proxy(IActiveIMMIME *This,HKL hKL,UINT uBufLen,LPWSTR szFileName,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetIMEFileNameW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetOpenStatus_Proxy(IActiveIMMIME *This,HIMC hIMC);
  void __RPC_STUB IActiveIMMIME_GetOpenStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetProperty_Proxy(IActiveIMMIME *This,HKL hKL,DWORD fdwIndex,DWORD *pdwProperty);
  void __RPC_STUB IActiveIMMIME_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetRegisterWordStyleA_Proxy(IActiveIMMIME *This,HKL hKL,UINT nItem,STYLEBUFA *pStyleBuf,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetRegisterWordStyleA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetRegisterWordStyleW_Proxy(IActiveIMMIME *This,HKL hKL,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puCopied);
  void __RPC_STUB IActiveIMMIME_GetRegisterWordStyleW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetStatusWindowPos_Proxy(IActiveIMMIME *This,HIMC hIMC,POINT *pptPos);
  void __RPC_STUB IActiveIMMIME_GetStatusWindowPos_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetVirtualKey_Proxy(IActiveIMMIME *This,HWND hWnd,UINT *puVirtualKey);
  void __RPC_STUB IActiveIMMIME_GetVirtualKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_InstallIMEA_Proxy(IActiveIMMIME *This,LPSTR szIMEFileName,LPSTR szLayoutText,HKL *phKL);
  void __RPC_STUB IActiveIMMIME_InstallIMEA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_InstallIMEW_Proxy(IActiveIMMIME *This,LPWSTR szIMEFileName,LPWSTR szLayoutText,HKL *phKL);
  void __RPC_STUB IActiveIMMIME_InstallIMEW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_IsIME_Proxy(IActiveIMMIME *This,HKL hKL);
  void __RPC_STUB IActiveIMMIME_IsIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_IsUIMessageA_Proxy(IActiveIMMIME *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
  void __RPC_STUB IActiveIMMIME_IsUIMessageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_IsUIMessageW_Proxy(IActiveIMMIME *This,HWND hWndIME,UINT msg,WPARAM wParam,LPARAM lParam);
  void __RPC_STUB IActiveIMMIME_IsUIMessageW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_NotifyIME_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
  void __RPC_STUB IActiveIMMIME_NotifyIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_RegisterWordA_Proxy(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szRegister);
  void __RPC_STUB IActiveIMMIME_RegisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_RegisterWordW_Proxy(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister);
  void __RPC_STUB IActiveIMMIME_RegisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_ReleaseContext_Proxy(IActiveIMMIME *This,HWND hWnd,HIMC hIMC);
  void __RPC_STUB IActiveIMMIME_ReleaseContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCandidateWindow_Proxy(IActiveIMMIME *This,HIMC hIMC,CANDIDATEFORM *pCandidate);
  void __RPC_STUB IActiveIMMIME_SetCandidateWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCompositionFontA_Proxy(IActiveIMMIME *This,HIMC hIMC,LOGFONTA *plf);
  void __RPC_STUB IActiveIMMIME_SetCompositionFontA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCompositionFontW_Proxy(IActiveIMMIME *This,HIMC hIMC,LOGFONTW *plf);
  void __RPC_STUB IActiveIMMIME_SetCompositionFontW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCompositionStringA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
  void __RPC_STUB IActiveIMMIME_SetCompositionStringA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCompositionStringW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwIndex,LPVOID pComp,DWORD dwCompLen,LPVOID pRead,DWORD dwReadLen);
  void __RPC_STUB IActiveIMMIME_SetCompositionStringW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetCompositionWindow_Proxy(IActiveIMMIME *This,HIMC hIMC,COMPOSITIONFORM *pCompForm);
  void __RPC_STUB IActiveIMMIME_SetCompositionWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetConversionStatus_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD fdwConversion,DWORD fdwSentence);
  void __RPC_STUB IActiveIMMIME_SetConversionStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetOpenStatus_Proxy(IActiveIMMIME *This,HIMC hIMC,WINBOOL fOpen);
  void __RPC_STUB IActiveIMMIME_SetOpenStatus_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetStatusWindowPos_Proxy(IActiveIMMIME *This,HIMC hIMC,POINT *pptPos);
  void __RPC_STUB IActiveIMMIME_SetStatusWindowPos_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SimulateHotKey_Proxy(IActiveIMMIME *This,HWND hWnd,DWORD dwHotKeyID);
  void __RPC_STUB IActiveIMMIME_SimulateHotKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_UnregisterWordA_Proxy(IActiveIMMIME *This,HKL hKL,LPSTR szReading,DWORD dwStyle,LPSTR szUnregister);
  void __RPC_STUB IActiveIMMIME_UnregisterWordA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_UnregisterWordW_Proxy(IActiveIMMIME *This,HKL hKL,LPWSTR szReading,DWORD dwStyle,LPWSTR szUnregister);
  void __RPC_STUB IActiveIMMIME_UnregisterWordW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GenerateMessage_Proxy(IActiveIMMIME *This,HIMC hIMC);
  void __RPC_STUB IActiveIMMIME_GenerateMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_LockIMC_Proxy(IActiveIMMIME *This,HIMC hIMC,INPUTCONTEXT **ppIMC);
  void __RPC_STUB IActiveIMMIME_LockIMC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_UnlockIMC_Proxy(IActiveIMMIME *This,HIMC hIMC);
  void __RPC_STUB IActiveIMMIME_UnlockIMC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetIMCLockCount_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD *pdwLockCount);
  void __RPC_STUB IActiveIMMIME_GetIMCLockCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_CreateIMCC_Proxy(IActiveIMMIME *This,DWORD dwSize,HIMCC *phIMCC);
  void __RPC_STUB IActiveIMMIME_CreateIMCC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_DestroyIMCC_Proxy(IActiveIMMIME *This,HIMCC hIMCC);
  void __RPC_STUB IActiveIMMIME_DestroyIMCC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_LockIMCC_Proxy(IActiveIMMIME *This,HIMCC hIMCC,void **ppv);
  void __RPC_STUB IActiveIMMIME_LockIMCC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_UnlockIMCC_Proxy(IActiveIMMIME *This,HIMCC hIMCC);
  void __RPC_STUB IActiveIMMIME_UnlockIMCC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_ReSizeIMCC_Proxy(IActiveIMMIME *This,HIMCC hIMCC,DWORD dwSize,HIMCC *phIMCC);
  void __RPC_STUB IActiveIMMIME_ReSizeIMCC_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetIMCCSize_Proxy(IActiveIMMIME *This,HIMCC hIMCC,DWORD *pdwSize);
  void __RPC_STUB IActiveIMMIME_GetIMCCSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetIMCCLockCount_Proxy(IActiveIMMIME *This,HIMCC hIMCC,DWORD *pdwLockCount);
  void __RPC_STUB IActiveIMMIME_GetIMCCLockCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetHotKey_Proxy(IActiveIMMIME *This,DWORD dwHotKeyID,UINT *puModifiers,UINT *puVKey,HKL *phKL);
  void __RPC_STUB IActiveIMMIME_GetHotKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SetHotKey_Proxy(IActiveIMMIME *This,DWORD dwHotKeyID,UINT uModifiers,UINT uVKey,HKL hKL);
  void __RPC_STUB IActiveIMMIME_SetHotKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_CreateSoftKeyboard_Proxy(IActiveIMMIME *This,UINT uType,HWND hOwner,int x,int y,HWND *phSoftKbdWnd);
  void __RPC_STUB IActiveIMMIME_CreateSoftKeyboard_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_DestroySoftKeyboard_Proxy(IActiveIMMIME *This,HWND hSoftKbdWnd);
  void __RPC_STUB IActiveIMMIME_DestroySoftKeyboard_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_ShowSoftKeyboard_Proxy(IActiveIMMIME *This,HWND hSoftKbdWnd,int nCmdShow);
  void __RPC_STUB IActiveIMMIME_ShowSoftKeyboard_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetCodePageA_Proxy(IActiveIMMIME *This,HKL hKL,UINT *uCodePage);
  void __RPC_STUB IActiveIMMIME_GetCodePageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetLangId_Proxy(IActiveIMMIME *This,HKL hKL,LANGID *plid);
  void __RPC_STUB IActiveIMMIME_GetLangId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_KeybdEvent_Proxy(IActiveIMMIME *This,LANGID lgidIME,BYTE bVk,BYTE bScan,DWORD dwFlags,DWORD dwExtraInfo);
  void __RPC_STUB IActiveIMMIME_KeybdEvent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_LockModal_Proxy(IActiveIMMIME *This);
  void __RPC_STUB IActiveIMMIME_LockModal_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_UnlockModal_Proxy(IActiveIMMIME *This);
  void __RPC_STUB IActiveIMMIME_UnlockModal_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_AssociateContextEx_Proxy(IActiveIMMIME *This,HWND hWnd,HIMC hIMC,DWORD dwFlags);
  void __RPC_STUB IActiveIMMIME_AssociateContextEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_DisableIME_Proxy(IActiveIMMIME *This,DWORD idThread);
  void __RPC_STUB IActiveIMMIME_DisableIME_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetImeMenuItemsA_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOA *pImeParentMenu,IMEMENUITEMINFOA *pImeMenu,DWORD dwSize,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMIME_GetImeMenuItemsA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_GetImeMenuItemsW_Proxy(IActiveIMMIME *This,HIMC hIMC,DWORD dwFlags,DWORD dwType,IMEMENUITEMINFOW *pImeParentMenu,IMEMENUITEMINFOW *pImeMenu,DWORD dwSize,DWORD *pdwResult);
  void __RPC_STUB IActiveIMMIME_GetImeMenuItemsW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_EnumInputContext_Proxy(IActiveIMMIME *This,DWORD idThread,IEnumInputContext **ppEnum);
  void __RPC_STUB IActiveIMMIME_EnumInputContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_RequestMessageA_Proxy(IActiveIMMIME *This,HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_RequestMessageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_RequestMessageW_Proxy(IActiveIMMIME *This,HIMC hIMC,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_RequestMessageW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SendIMCA_Proxy(IActiveIMMIME *This,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_SendIMCA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_SendIMCW_Proxy(IActiveIMMIME *This,HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam,LRESULT *plResult);
  void __RPC_STUB IActiveIMMIME_SendIMCW_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIMMIME_IsSleeping_Proxy(IActiveIMMIME *This);
  void __RPC_STUB IActiveIMMIME_IsSleeping_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIME_INTERFACE_DEFINED__
#define __IActiveIME_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIME;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIME : public IUnknown {
  public:
    virtual HRESULT WINAPI Inquire(DWORD dwSystemInfoFlags,IMEINFO *pIMEInfo,LPWSTR szWndClass,DWORD *pdwPrivate) = 0;
    virtual HRESULT WINAPI ConversionList(HIMC hIMC,LPWSTR szSource,UINT uFlag,UINT uBufLen,CANDIDATELIST *pDest,UINT *puCopied) = 0;
    virtual HRESULT WINAPI Configure(HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pRegisterWord) = 0;
    virtual HRESULT WINAPI Destroy(UINT uReserved) = 0;
    virtual HRESULT WINAPI Escape(HIMC hIMC,UINT uEscape,void *pData,LRESULT *plResult) = 0;
    virtual HRESULT WINAPI SetActiveContext(HIMC hIMC,WINBOOL fFlag) = 0;
    virtual HRESULT WINAPI ProcessKey(HIMC hIMC,UINT uVirKey,DWORD lParam,BYTE *pbKeyState) = 0;
    virtual HRESULT WINAPI Notify(HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue) = 0;
    virtual HRESULT WINAPI Select(HIMC hIMC,WINBOOL fSelect) = 0;
    virtual HRESULT WINAPI SetCompositionString(HIMC hIMC,DWORD dwIndex,void *pComp,DWORD dwCompLen,void *pRead,DWORD dwReadLen) = 0;
    virtual HRESULT WINAPI ToAsciiEx(UINT uVirKey,UINT uScanCode,BYTE *pbKeyState,UINT fuState,HIMC hIMC,DWORD *pdwTransBuf,UINT *puSize) = 0;
    virtual HRESULT WINAPI RegisterWord(LPWSTR szReading,DWORD dwStyle,LPWSTR szString) = 0;
    virtual HRESULT WINAPI UnregisterWord(LPWSTR szReading,DWORD dwStyle,LPWSTR szString) = 0;
    virtual HRESULT WINAPI GetRegisterWordStyle(UINT nItem,STYLEBUFW *pStyleBuf,UINT *puBufSize) = 0;
    virtual HRESULT WINAPI EnumRegisterWord(LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **ppEnum) = 0;
    virtual HRESULT WINAPI GetCodePageA(UINT *uCodePage) = 0;
    virtual HRESULT WINAPI GetLangId(LANGID *plid) = 0;
  };
#else
  typedef struct IActiveIMEVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIME *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIME *This);
      ULONG (WINAPI *Release)(IActiveIME *This);
      HRESULT (WINAPI *Inquire)(IActiveIME *This,DWORD dwSystemInfoFlags,IMEINFO *pIMEInfo,LPWSTR szWndClass,DWORD *pdwPrivate);
      HRESULT (WINAPI *ConversionList)(IActiveIME *This,HIMC hIMC,LPWSTR szSource,UINT uFlag,UINT uBufLen,CANDIDATELIST *pDest,UINT *puCopied);
      HRESULT (WINAPI *Configure)(IActiveIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pRegisterWord);
      HRESULT (WINAPI *Destroy)(IActiveIME *This,UINT uReserved);
      HRESULT (WINAPI *Escape)(IActiveIME *This,HIMC hIMC,UINT uEscape,void *pData,LRESULT *plResult);
      HRESULT (WINAPI *SetActiveContext)(IActiveIME *This,HIMC hIMC,WINBOOL fFlag);
      HRESULT (WINAPI *ProcessKey)(IActiveIME *This,HIMC hIMC,UINT uVirKey,DWORD lParam,BYTE *pbKeyState);
      HRESULT (WINAPI *Notify)(IActiveIME *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
      HRESULT (WINAPI *Select)(IActiveIME *This,HIMC hIMC,WINBOOL fSelect);
      HRESULT (WINAPI *SetCompositionString)(IActiveIME *This,HIMC hIMC,DWORD dwIndex,void *pComp,DWORD dwCompLen,void *pRead,DWORD dwReadLen);
      HRESULT (WINAPI *ToAsciiEx)(IActiveIME *This,UINT uVirKey,UINT uScanCode,BYTE *pbKeyState,UINT fuState,HIMC hIMC,DWORD *pdwTransBuf,UINT *puSize);
      HRESULT (WINAPI *RegisterWord)(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
      HRESULT (WINAPI *UnregisterWord)(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
      HRESULT (WINAPI *GetRegisterWordStyle)(IActiveIME *This,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puBufSize);
      HRESULT (WINAPI *EnumRegisterWord)(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **ppEnum);
      HRESULT (WINAPI *GetCodePageA)(IActiveIME *This,UINT *uCodePage);
      HRESULT (WINAPI *GetLangId)(IActiveIME *This,LANGID *plid);
    END_INTERFACE
  } IActiveIMEVtbl;
  struct IActiveIME {
    CONST_VTBL struct IActiveIMEVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIME_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIME_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIME_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIME_Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate) (This)->lpVtbl->Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate)
#define IActiveIME_ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied) (This)->lpVtbl->ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied)
#define IActiveIME_Configure(This,hKL,hWnd,dwMode,pRegisterWord) (This)->lpVtbl->Configure(This,hKL,hWnd,dwMode,pRegisterWord)
#define IActiveIME_Destroy(This,uReserved) (This)->lpVtbl->Destroy(This,uReserved)
#define IActiveIME_Escape(This,hIMC,uEscape,pData,plResult) (This)->lpVtbl->Escape(This,hIMC,uEscape,pData,plResult)
#define IActiveIME_SetActiveContext(This,hIMC,fFlag) (This)->lpVtbl->SetActiveContext(This,hIMC,fFlag)
#define IActiveIME_ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState) (This)->lpVtbl->ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState)
#define IActiveIME_Notify(This,hIMC,dwAction,dwIndex,dwValue) (This)->lpVtbl->Notify(This,hIMC,dwAction,dwIndex,dwValue)
#define IActiveIME_Select(This,hIMC,fSelect) (This)->lpVtbl->Select(This,hIMC,fSelect)
#define IActiveIME_SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIME_ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize) (This)->lpVtbl->ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize)
#define IActiveIME_RegisterWord(This,szReading,dwStyle,szString) (This)->lpVtbl->RegisterWord(This,szReading,dwStyle,szString)
#define IActiveIME_UnregisterWord(This,szReading,dwStyle,szString) (This)->lpVtbl->UnregisterWord(This,szReading,dwStyle,szString)
#define IActiveIME_GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize) (This)->lpVtbl->GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize)
#define IActiveIME_EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum) (This)->lpVtbl->EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum)
#define IActiveIME_GetCodePageA(This,uCodePage) (This)->lpVtbl->GetCodePageA(This,uCodePage)
#define IActiveIME_GetLangId(This,plid) (This)->lpVtbl->GetLangId(This,plid)
#endif
#endif
  HRESULT WINAPI IActiveIME_Inquire_Proxy(IActiveIME *This,DWORD dwSystemInfoFlags,IMEINFO *pIMEInfo,LPWSTR szWndClass,DWORD *pdwPrivate);
  void __RPC_STUB IActiveIME_Inquire_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_ConversionList_Proxy(IActiveIME *This,HIMC hIMC,LPWSTR szSource,UINT uFlag,UINT uBufLen,CANDIDATELIST *pDest,UINT *puCopied);
  void __RPC_STUB IActiveIME_ConversionList_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_Configure_Proxy(IActiveIME *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pRegisterWord);
  void __RPC_STUB IActiveIME_Configure_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_Destroy_Proxy(IActiveIME *This,UINT uReserved);
  void __RPC_STUB IActiveIME_Destroy_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_Escape_Proxy(IActiveIME *This,HIMC hIMC,UINT uEscape,void *pData,LRESULT *plResult);
  void __RPC_STUB IActiveIME_Escape_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_SetActiveContext_Proxy(IActiveIME *This,HIMC hIMC,WINBOOL fFlag);
  void __RPC_STUB IActiveIME_SetActiveContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_ProcessKey_Proxy(IActiveIME *This,HIMC hIMC,UINT uVirKey,DWORD lParam,BYTE *pbKeyState);
  void __RPC_STUB IActiveIME_ProcessKey_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_Notify_Proxy(IActiveIME *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
  void __RPC_STUB IActiveIME_Notify_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_Select_Proxy(IActiveIME *This,HIMC hIMC,WINBOOL fSelect);
  void __RPC_STUB IActiveIME_Select_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_SetCompositionString_Proxy(IActiveIME *This,HIMC hIMC,DWORD dwIndex,void *pComp,DWORD dwCompLen,void *pRead,DWORD dwReadLen);
  void __RPC_STUB IActiveIME_SetCompositionString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_ToAsciiEx_Proxy(IActiveIME *This,UINT uVirKey,UINT uScanCode,BYTE *pbKeyState,UINT fuState,HIMC hIMC,DWORD *pdwTransBuf,UINT *puSize);
  void __RPC_STUB IActiveIME_ToAsciiEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_RegisterWord_Proxy(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
  void __RPC_STUB IActiveIME_RegisterWord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_UnregisterWord_Proxy(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
  void __RPC_STUB IActiveIME_UnregisterWord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_GetRegisterWordStyle_Proxy(IActiveIME *This,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puBufSize);
  void __RPC_STUB IActiveIME_GetRegisterWordStyle_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_EnumRegisterWord_Proxy(IActiveIME *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **ppEnum);
  void __RPC_STUB IActiveIME_EnumRegisterWord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_GetCodePageA_Proxy(IActiveIME *This,UINT *uCodePage);
  void __RPC_STUB IActiveIME_GetCodePageA_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME_GetLangId_Proxy(IActiveIME *This,LANGID *plid);
  void __RPC_STUB IActiveIME_GetLangId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveIME2_INTERFACE_DEFINED__
#define __IActiveIME2_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveIME2;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveIME2 : public IActiveIME {
  public:
    virtual HRESULT WINAPI Sleep(void) = 0;
    virtual HRESULT WINAPI Unsleep(WINBOOL fDead) = 0;
  };
#else
  typedef struct IActiveIME2Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveIME2 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveIME2 *This);
      ULONG (WINAPI *Release)(IActiveIME2 *This);
      HRESULT (WINAPI *Inquire)(IActiveIME2 *This,DWORD dwSystemInfoFlags,IMEINFO *pIMEInfo,LPWSTR szWndClass,DWORD *pdwPrivate);
      HRESULT (WINAPI *ConversionList)(IActiveIME2 *This,HIMC hIMC,LPWSTR szSource,UINT uFlag,UINT uBufLen,CANDIDATELIST *pDest,UINT *puCopied);
      HRESULT (WINAPI *Configure)(IActiveIME2 *This,HKL hKL,HWND hWnd,DWORD dwMode,REGISTERWORDW *pRegisterWord);
      HRESULT (WINAPI *Destroy)(IActiveIME2 *This,UINT uReserved);
      HRESULT (WINAPI *Escape)(IActiveIME2 *This,HIMC hIMC,UINT uEscape,void *pData,LRESULT *plResult);
      HRESULT (WINAPI *SetActiveContext)(IActiveIME2 *This,HIMC hIMC,WINBOOL fFlag);
      HRESULT (WINAPI *ProcessKey)(IActiveIME2 *This,HIMC hIMC,UINT uVirKey,DWORD lParam,BYTE *pbKeyState);
      HRESULT (WINAPI *Notify)(IActiveIME2 *This,HIMC hIMC,DWORD dwAction,DWORD dwIndex,DWORD dwValue);
      HRESULT (WINAPI *Select)(IActiveIME2 *This,HIMC hIMC,WINBOOL fSelect);
      HRESULT (WINAPI *SetCompositionString)(IActiveIME2 *This,HIMC hIMC,DWORD dwIndex,void *pComp,DWORD dwCompLen,void *pRead,DWORD dwReadLen);
      HRESULT (WINAPI *ToAsciiEx)(IActiveIME2 *This,UINT uVirKey,UINT uScanCode,BYTE *pbKeyState,UINT fuState,HIMC hIMC,DWORD *pdwTransBuf,UINT *puSize);
      HRESULT (WINAPI *RegisterWord)(IActiveIME2 *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
      HRESULT (WINAPI *UnregisterWord)(IActiveIME2 *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szString);
      HRESULT (WINAPI *GetRegisterWordStyle)(IActiveIME2 *This,UINT nItem,STYLEBUFW *pStyleBuf,UINT *puBufSize);
      HRESULT (WINAPI *EnumRegisterWord)(IActiveIME2 *This,LPWSTR szReading,DWORD dwStyle,LPWSTR szRegister,LPVOID pData,IEnumRegisterWordW **ppEnum);
      HRESULT (WINAPI *GetCodePageA)(IActiveIME2 *This,UINT *uCodePage);
      HRESULT (WINAPI *GetLangId)(IActiveIME2 *This,LANGID *plid);
      HRESULT (WINAPI *Sleep)(IActiveIME2 *This);
      HRESULT (WINAPI *Unsleep)(IActiveIME2 *This,WINBOOL fDead);
    END_INTERFACE
  } IActiveIME2Vtbl;
  struct IActiveIME2 {
    CONST_VTBL struct IActiveIME2Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveIME2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveIME2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveIME2_Release(This) (This)->lpVtbl->Release(This)
#define IActiveIME2_Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate) (This)->lpVtbl->Inquire(This,dwSystemInfoFlags,pIMEInfo,szWndClass,pdwPrivate)
#define IActiveIME2_ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied) (This)->lpVtbl->ConversionList(This,hIMC,szSource,uFlag,uBufLen,pDest,puCopied)
#define IActiveIME2_Configure(This,hKL,hWnd,dwMode,pRegisterWord) (This)->lpVtbl->Configure(This,hKL,hWnd,dwMode,pRegisterWord)
#define IActiveIME2_Destroy(This,uReserved) (This)->lpVtbl->Destroy(This,uReserved)
#define IActiveIME2_Escape(This,hIMC,uEscape,pData,plResult) (This)->lpVtbl->Escape(This,hIMC,uEscape,pData,plResult)
#define IActiveIME2_SetActiveContext(This,hIMC,fFlag) (This)->lpVtbl->SetActiveContext(This,hIMC,fFlag)
#define IActiveIME2_ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState) (This)->lpVtbl->ProcessKey(This,hIMC,uVirKey,lParam,pbKeyState)
#define IActiveIME2_Notify(This,hIMC,dwAction,dwIndex,dwValue) (This)->lpVtbl->Notify(This,hIMC,dwAction,dwIndex,dwValue)
#define IActiveIME2_Select(This,hIMC,fSelect) (This)->lpVtbl->Select(This,hIMC,fSelect)
#define IActiveIME2_SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen) (This)->lpVtbl->SetCompositionString(This,hIMC,dwIndex,pComp,dwCompLen,pRead,dwReadLen)
#define IActiveIME2_ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize) (This)->lpVtbl->ToAsciiEx(This,uVirKey,uScanCode,pbKeyState,fuState,hIMC,pdwTransBuf,puSize)
#define IActiveIME2_RegisterWord(This,szReading,dwStyle,szString) (This)->lpVtbl->RegisterWord(This,szReading,dwStyle,szString)
#define IActiveIME2_UnregisterWord(This,szReading,dwStyle,szString) (This)->lpVtbl->UnregisterWord(This,szReading,dwStyle,szString)
#define IActiveIME2_GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize) (This)->lpVtbl->GetRegisterWordStyle(This,nItem,pStyleBuf,puBufSize)
#define IActiveIME2_EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum) (This)->lpVtbl->EnumRegisterWord(This,szReading,dwStyle,szRegister,pData,ppEnum)
#define IActiveIME2_GetCodePageA(This,uCodePage) (This)->lpVtbl->GetCodePageA(This,uCodePage)
#define IActiveIME2_GetLangId(This,plid) (This)->lpVtbl->GetLangId(This,plid)
#define IActiveIME2_Sleep(This) (This)->lpVtbl->Sleep(This)
#define IActiveIME2_Unsleep(This,fDead) (This)->lpVtbl->Unsleep(This,fDead)
#endif
#endif
  HRESULT WINAPI IActiveIME2_Sleep_Proxy(IActiveIME2 *This);
  void __RPC_STUB IActiveIME2_Sleep_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveIME2_Unsleep_Proxy(IActiveIME2 *This,WINBOOL fDead);
  void __RPC_STUB IActiveIME2_Unsleep_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

  EXTERN_C const CLSID CLSID_CActiveIMM;
#ifdef __cplusplus
  class CActiveIMM;
#endif
#endif

#ifdef __cplusplus
}
#endif
#endif
