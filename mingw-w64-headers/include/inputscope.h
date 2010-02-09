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
#error This stub requires an updated version of <rpcndr.h>
#endif

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif

#ifndef __inputscope_h__
#define __inputscope_h__

#ifndef __ITfInputScope_FWD_DEFINED__
#define __ITfInputScope_FWD_DEFINED__
typedef struct ITfInputScope ITfInputScope;
#endif

#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef INPUTSCOPE_DEFINED
#define INPUTSCOPE_DEFINED

#include <windows.h>

#ifdef __cplusplus
  extern "C" {
#endif

    typedef enum __MIDL___MIDL_itf_inputscope_0000_0001 {
      IS_DEFAULT = 0,IS_URL = 1,IS_FILE_FULLFILEPATH = 2,IS_FILE_FILENAME = 3,IS_EMAIL_USERNAME = 4,IS_EMAIL_SMTPEMAILADDRESS = 5,
      IS_LOGINNAME = 6,IS_PERSONALNAME_FULLNAME = 7,IS_PERSONALNAME_PREFIX = 8,IS_PERSONALNAME_GIVENNAME = 9,IS_PERSONALNAME_MIDDLENAME = 10,
      IS_PERSONALNAME_SURNAME = 11,IS_PERSONALNAME_SUFFIX = 12,IS_ADDRESS_FULLPOSTALADDRESS = 13,IS_ADDRESS_POSTALCODE = 14,IS_ADDRESS_STREET = 15,
      IS_ADDRESS_STATEORPROVINCE = 16,IS_ADDRESS_CITY = 17,IS_ADDRESS_COUNTRYNAME = 18,IS_ADDRESS_COUNTRYSHORTNAME = 19,
      IS_CURRENCY_AMOUNTANDSYMBOL = 20,IS_CURRENCY_AMOUNT = 21,IS_DATE_FULLDATE = 22,IS_DATE_MONTH = 23,IS_DATE_DAY = 24,
      IS_DATE_YEAR = 25,IS_DATE_MONTHNAME = 26,IS_DATE_DAYNAME = 27,IS_DIGITS = 28,IS_NUMBER = 29,IS_ONECHAR = 30,IS_PASSWORD = 31,
      IS_TELEPHONE_FULLTELEPHONENUMBER = 32,IS_TELEPHONE_COUNTRYCODE = 33,IS_TELEPHONE_AREACODE = 34,IS_TELEPHONE_LOCALNUMBER = 35,
      IS_TIME_FULLTIME = 36,IS_TIME_HOUR = 37,IS_TIME_MINORSEC = 38,IS_NUMBER_FULLWIDTH = 39,IS_ALPHANUMERIC_HALFWIDTH = 40,
      IS_ALPHANUMERIC_FULLWIDTH = 41,IS_CURRENCY_CHINESE = 42,IS_BOPOMOFO = 43,IS_HIRAGANA = 44,IS_KATAKANA_HALFWIDTH = 45,
      IS_KATAKANA_FULLWIDTH = 46,IS_HANJA = 47,IS_PHRASELIST = -1,IS_REGULAREXPRESSION = -2,IS_SRGS = -3,IS_XML = -4
    } InputScope;

    HRESULT WINAPI SetInputScope(HWND hwnd,InputScope inputscope);
    HRESULT WINAPI SetInputScopes(HWND hwnd,const InputScope *pInputScopes,UINT cInputScopes,WCHAR **ppszPhraseList,UINT cPhrases,WCHAR *pszRegExp,WCHAR *pszSRGS);
    HRESULT WINAPI SetInputScopeXML(HWND hwnd,WCHAR *pszXML);

    DEFINE_GUID(IID_ITfInputScope,0xfde1eaee,0x6924,0x4cdf,0x91,0xe7,0xda,0x38,0xcf,0xf5,0x55,0x9d);
    DEFINE_GUID(GUID_PROP_INPUTSCOPE,0x1713dd5a,0x68e7,0x4a5b,0x9a,0xf6,0x59,0x2a,0x59,0x5c,0x77,0x8d);

#ifdef __cplusplus
  }
#endif

  extern RPC_IF_HANDLE __MIDL_itf_inputscope_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_inputscope_0000_v0_0_s_ifspec;

#ifndef __ITfInputScope_INTERFACE_DEFINED__
#define __ITfInputScope_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ITfInputScope;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITfInputScope : public IUnknown {
  public:
    virtual HRESULT WINAPI GetInputScopes(InputScope **pprgInputScopes,UINT *pcCount) = 0;
    virtual HRESULT WINAPI GetPhrase(BSTR **ppbstrPhrases,UINT *pcCount) = 0;
    virtual HRESULT WINAPI GetRegularExpression(BSTR *pbstrRegExp) = 0;
    virtual HRESULT WINAPI GetSRGS(BSTR *pbstrSRGS) = 0;
    virtual HRESULT WINAPI GetXML(BSTR *pbstrXML) = 0;
  };
#else
  typedef struct ITfInputScopeVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITfInputScope *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITfInputScope *This);
      ULONG (WINAPI *Release)(ITfInputScope *This);
      HRESULT (WINAPI *GetInputScopes)(ITfInputScope *This,InputScope **pprgInputScopes,UINT *pcCount);
      HRESULT (WINAPI *GetPhrase)(ITfInputScope *This,BSTR **ppbstrPhrases,UINT *pcCount);
      HRESULT (WINAPI *GetRegularExpression)(ITfInputScope *This,BSTR *pbstrRegExp);
      HRESULT (WINAPI *GetSRGS)(ITfInputScope *This,BSTR *pbstrSRGS);
      HRESULT (WINAPI *GetXML)(ITfInputScope *This,BSTR *pbstrXML);
    END_INTERFACE
  } ITfInputScopeVtbl;
  struct ITfInputScope {
    CONST_VTBL struct ITfInputScopeVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITfInputScope_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITfInputScope_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITfInputScope_Release(This) (This)->lpVtbl->Release(This)
#define ITfInputScope_GetInputScopes(This,pprgInputScopes,pcCount) (This)->lpVtbl->GetInputScopes(This,pprgInputScopes,pcCount)
#define ITfInputScope_GetPhrase(This,ppbstrPhrases,pcCount) (This)->lpVtbl->GetPhrase(This,ppbstrPhrases,pcCount)
#define ITfInputScope_GetRegularExpression(This,pbstrRegExp) (This)->lpVtbl->GetRegularExpression(This,pbstrRegExp)
#define ITfInputScope_GetSRGS(This,pbstrSRGS) (This)->lpVtbl->GetSRGS(This,pbstrSRGS)
#define ITfInputScope_GetXML(This,pbstrXML) (This)->lpVtbl->GetXML(This,pbstrXML)
#endif
#endif
  HRESULT WINAPI ITfInputScope_GetInputScopes_Proxy(ITfInputScope *This,InputScope **pprgInputScopes,UINT *pcCount);
  void __RPC_STUB ITfInputScope_GetInputScopes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITfInputScope_GetPhrase_Proxy(ITfInputScope *This,BSTR **ppbstrPhrases,UINT *pcCount);
  void __RPC_STUB ITfInputScope_GetPhrase_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITfInputScope_GetRegularExpression_Proxy(ITfInputScope *This,BSTR *pbstrRegExp);
  void __RPC_STUB ITfInputScope_GetRegularExpression_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITfInputScope_GetSRGS_Proxy(ITfInputScope *This,BSTR *pbstrSRGS);
  void __RPC_STUB ITfInputScope_GetSRGS_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ITfInputScope_GetXML_Proxy(ITfInputScope *This,BSTR *pbstrXML);
  void __RPC_STUB ITfInputScope_GetXML_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_inputscope_0262_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_inputscope_0262_v0_0_s_ifspec;

  unsigned long __RPC_API BSTR_UserSize(unsigned long *,unsigned long,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(unsigned long *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(unsigned long *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(unsigned long *,BSTR *);

#ifdef __cplusplus
}
#endif
#endif
