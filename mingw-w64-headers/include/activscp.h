/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
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

#ifndef __activscp_h__
#define __activscp_h__

#ifndef __IActiveScriptSite_FWD_DEFINED__
#define __IActiveScriptSite_FWD_DEFINED__
typedef struct IActiveScriptSite IActiveScriptSite;
#endif

#ifndef __IActiveScriptError_FWD_DEFINED__
#define __IActiveScriptError_FWD_DEFINED__
typedef struct IActiveScriptError IActiveScriptError;
#endif

#ifndef __IActiveScriptError64_FWD_DEFINED__
#define __IActiveScriptError64_FWD_DEFINED__
typedef struct IActiveScriptError64 IActiveScriptError64;
#endif

#ifndef __IActiveScriptSiteWindow_FWD_DEFINED__
#define __IActiveScriptSiteWindow_FWD_DEFINED__
typedef struct IActiveScriptSiteWindow IActiveScriptSiteWindow;
#endif

#ifndef __IActiveScriptSiteInterruptPoll_FWD_DEFINED__
#define __IActiveScriptSiteInterruptPoll_FWD_DEFINED__
typedef struct IActiveScriptSiteInterruptPoll IActiveScriptSiteInterruptPoll;
#endif

#ifndef __IActiveScript_FWD_DEFINED__
#define __IActiveScript_FWD_DEFINED__
typedef struct IActiveScript IActiveScript;
#endif

#ifndef __IActiveScriptParse32_FWD_DEFINED__
#define __IActiveScriptParse32_FWD_DEFINED__
typedef struct IActiveScriptParse32 IActiveScriptParse32;
#endif

#ifndef __IActiveScriptParse64_FWD_DEFINED__
#define __IActiveScriptParse64_FWD_DEFINED__
typedef struct IActiveScriptParse64 IActiveScriptParse64;
#endif

#ifndef __IActiveScriptParseProcedureOld32_FWD_DEFINED__
#define __IActiveScriptParseProcedureOld32_FWD_DEFINED__
typedef struct IActiveScriptParseProcedureOld32 IActiveScriptParseProcedureOld32;
#endif

#ifndef __IActiveScriptParseProcedureOld64_FWD_DEFINED__
#define __IActiveScriptParseProcedureOld64_FWD_DEFINED__
typedef struct IActiveScriptParseProcedureOld64 IActiveScriptParseProcedureOld64;
#endif

#ifndef __IActiveScriptParseProcedure32_FWD_DEFINED__
#define __IActiveScriptParseProcedure32_FWD_DEFINED__
typedef struct IActiveScriptParseProcedure32 IActiveScriptParseProcedure32;
#endif

#ifndef __IActiveScriptParseProcedure64_FWD_DEFINED__
#define __IActiveScriptParseProcedure64_FWD_DEFINED__
typedef struct IActiveScriptParseProcedure64 IActiveScriptParseProcedure64;
#endif

#ifndef __IActiveScriptParseProcedure2_32_FWD_DEFINED__
#define __IActiveScriptParseProcedure2_32_FWD_DEFINED__
typedef struct IActiveScriptParseProcedure2_32 IActiveScriptParseProcedure2_32;
#endif

#ifndef __IActiveScriptParseProcedure2_64_FWD_DEFINED__
#define __IActiveScriptParseProcedure2_64_FWD_DEFINED__
typedef struct IActiveScriptParseProcedure2_64 IActiveScriptParseProcedure2_64;
#endif

#ifndef __IActiveScriptEncode_FWD_DEFINED__
#define __IActiveScriptEncode_FWD_DEFINED__
typedef struct IActiveScriptEncode IActiveScriptEncode;
#endif

#ifndef __IActiveScriptHostEncode_FWD_DEFINED__
#define __IActiveScriptHostEncode_FWD_DEFINED__
typedef struct IActiveScriptHostEncode IActiveScriptHostEncode;
#endif

#ifndef __IBindEventHandler_FWD_DEFINED__
#define __IBindEventHandler_FWD_DEFINED__
typedef struct IBindEventHandler IBindEventHandler;
#endif

#ifndef __IActiveScriptStats_FWD_DEFINED__
#define __IActiveScriptStats_FWD_DEFINED__
typedef struct IActiveScriptStats IActiveScriptStats;
#endif

#ifndef __IActiveScriptProperty_FWD_DEFINED__
#define __IActiveScriptProperty_FWD_DEFINED__
typedef struct IActiveScriptProperty IActiveScriptProperty;
#endif

#ifndef __ITridentEventSink_FWD_DEFINED__
#define __ITridentEventSink_FWD_DEFINED__
typedef struct ITridentEventSink ITridentEventSink;
#endif

#ifndef __IActiveScriptGarbageCollector_FWD_DEFINED__
#define __IActiveScriptGarbageCollector_FWD_DEFINED__
typedef struct IActiveScriptGarbageCollector IActiveScriptGarbageCollector;
#endif

#ifndef __IActiveScriptSIPInfo_FWD_DEFINED__
#define __IActiveScriptSIPInfo_FWD_DEFINED__
typedef struct IActiveScriptSIPInfo IActiveScriptSIPInfo;
#endif

#ifndef __IActiveScriptSiteTraceInfo_FWD_DEFINED__
#define __IActiveScriptSiteTraceInfo_FWD_DEFINED__
typedef struct IActiveScriptSiteTraceInfo IActiveScriptSiteTraceInfo;
#endif

#ifndef __IActiveScriptTraceInfo_FWD_DEFINED__
#define __IActiveScriptTraceInfo_FWD_DEFINED__
typedef struct IActiveScriptTraceInfo IActiveScriptTraceInfo;
#endif

#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifndef __ActivScp_h
#define __ActivScp_h

#ifndef _NO_SCRIPT_GUIDS
  DEFINE_GUID(CATID_ActiveScript,0xf0b7a1a1,0x9847,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(CATID_ActiveScriptParse,0xf0b7a1a2,0x9847,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(CATID_ActiveScriptEncode,0xf0b7a1a3,0x9847,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScript,0xbb1a2ae1,0xa4f9,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptParse32,0xbb1a2ae2,0xa4f9,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptParse64,0xc7ef7658,0xe1ee,0x480e,0x97,0xea,0xd5,0x2c,0xb4,0xd7,0x6d,0x17);
  DEFINE_GUID(IID_IActiveScriptEncode,0xbb1a2ae3,0xa4f9,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptHostEncode,0xbee9b76e,0xcfe3,0x11d1,0xb7,0x47,0x00,0xc0,0x4f,0xc2,0xb0,0x85);
  DEFINE_GUID(IID_IActiveScriptParseProcedureOld32,0x1cff0050,0x6fdd,0x11d0,0x93,0x28,0x00,0xa0,0xc9,0x0d,0xca,0xa9);
  DEFINE_GUID(IID_IActiveScriptParseProcedureOld64,0x21f57128,0x08c9,0x4638,0xba,0x12,0x22,0xd1,0x5d,0x88,0xdc,0x5c);
  DEFINE_GUID(IID_IActiveScriptParseProcedure32,0xaa5b6a80,0xb834,0x11d0,0x93,0x2f,0x00,0xa0,0xc9,0x0d,0xca,0xa9);
  DEFINE_GUID(IID_IActiveScriptParseProcedure64,0xc64713b6,0xe029,0x4cc5,0x92,0x00,0x43,0x8b,0x72,0x89,0x0b,0x6a);
  DEFINE_GUID(IID_IActiveScriptParseProcedure2_32,0x71ee5b20,0xfb04,0x11d1,0xb3,0xa8,0x00,0xa0,0xc9,0x11,0xe8,0xb2);
  DEFINE_GUID(IID_IActiveScriptParseProcedure2_64,0xfe7c4271,0x210c,0x448d,0x9f,0x54,0x76,0xda,0xb7,0x04,0x7b,0x28);
  DEFINE_GUID(IID_IActiveScriptSite,0xdb01a1e3,0xa42b,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptSiteTraceInfo,0x4b7272ae,0x1955,0x4bfe,0x98,0xb0,0x78,0x6,0x21,0x88,0x85,0x69);
  DEFINE_GUID(IID_IActiveScriptSiteWindow,0xd10f6761,0x83e9,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptSiteInterruptPoll,0x539698a0,0xcdca,0x11cf,0xa5,0xeb,0x00,0xaa,0x00,0x47,0xa0,0x63);
  DEFINE_GUID(IID_IActiveScriptError,0xeae1ba61,0xa4ed,0x11cf,0x8f,0x20,0x00,0x80,0x5f,0x2c,0xd0,0x64);
  DEFINE_GUID(IID_IActiveScriptError64,0xb21fb2a1,0x5b8f,0x4963,0x8c,0x21,0x21,0x45,0x0f,0x84,0xed,0x7f);
  DEFINE_GUID(IID_IBindEventHandler,0x63cdbcb0,0xc1b1,0x11d0,0x93,0x36,0x00,0xa0,0xc9,0x0d,0xca,0xa9);
  DEFINE_GUID(IID_IActiveScriptStats,0xb8da6310,0xe19b,0x11d0,0x93,0x3c,0x00,0xa0,0xc9,0x0d,0xca,0xa9);
  DEFINE_GUID(IID_IActiveScriptProperty,0x4954E0D0,0xFBC7,0x11D1,0x84,0x10,0x00,0x60,0x08,0xC3,0xFB,0xFC);
  DEFINE_GUID(IID_ITridentEventSink,0x1dc9ca50,0x6ef,0x11d2,0x84,0x15,0x00,0x60,0x08,0xc3,0xfb,0xfc);
  DEFINE_GUID(IID_IActiveScriptGarbageCollector,0x6aa2c4a0,0x2b53,0x11d4,0xa2,0xa0,0x00,0x10,0x4b,0xd3,0x50,0x90);
  DEFINE_GUID(IID_IActiveScriptSIPInfo,0x764651d0,0x38de,0x11d4,0xa2,0xa3,0x00,0x10,0x4b,0xd3,0x50,0x90);
  DEFINE_GUID(IID_IActiveScriptTraceInfo,0xC35456E7,0xBEBF,0x4a1b,0x86,0xA9,0x24,0xD5,0x6B,0xE8,0xB3,0x69);
  DEFINE_GUID(OID_VBSSIP,0x1629f04e,0x2799,0x4db5,0x8f,0xe5,0xac,0xe1,0x0f,0x17,0xeb,0xab);
  DEFINE_GUID(OID_JSSIP,0x6c9e010,0x38ce,0x11d4,0xa2,0xa3,0x00,0x10,0x4b,0xd3,0x50,0x90);
  DEFINE_GUID(OID_WSFSIP,0x1a610570,0x38ce,0x11d4,0xa2,0xa3,0x00,0x10,0x4b,0xd3,0x50,0x90);
#endif

#define SCRIPTITEM_ISVISIBLE 0x00000002
#define SCRIPTITEM_ISSOURCE 0x00000004
#define SCRIPTITEM_GLOBALMEMBERS 0x00000008
#define SCRIPTITEM_ISPERSISTENT 0x00000040
#define SCRIPTITEM_CODEONLY 0x00000200
#define SCRIPTITEM_NOCODE 0x00000400

#define SCRIPTITEM_ALL_FLAGS (SCRIPTITEM_ISSOURCE | SCRIPTITEM_ISVISIBLE | SCRIPTITEM_ISPERSISTENT | SCRIPTITEM_GLOBALMEMBERS | SCRIPTITEM_NOCODE | SCRIPTITEM_CODEONLY)

#define SCRIPTTYPELIB_ISCONTROL 0x00000010
#define SCRIPTTYPELIB_ISPERSISTENT 0x00000040
#define SCRIPTTYPELIB_ALL_FLAGS (SCRIPTTYPELIB_ISCONTROL | SCRIPTTYPELIB_ISPERSISTENT)

#define SCRIPTTEXT_DELAYEXECUTION 0x00000001
#define SCRIPTTEXT_ISVISIBLE 0x00000002
#define SCRIPTTEXT_ISEXPRESSION 0x00000020
#define SCRIPTTEXT_ISPERSISTENT 0x00000040
#define SCRIPTTEXT_HOSTMANAGESSOURCE 0x00000080
#define SCRIPTTEXT_ALL_FLAGS (SCRIPTTEXT_DELAYEXECUTION | SCRIPTTEXT_ISVISIBLE | SCRIPTTEXT_ISEXPRESSION | SCRIPTTEXT_ISPERSISTENT | SCRIPTTEXT_HOSTMANAGESSOURCE)

#define SCRIPTPROC_ISEXPRESSION 0x00000020
#define SCRIPTPROC_HOSTMANAGESSOURCE 0x00000080
#define SCRIPTPROC_IMPLICIT_THIS 0x00000100
#define SCRIPTPROC_IMPLICIT_PARENTS 0x00000200
#define SCRIPTPROC_ALL_FLAGS (SCRIPTPROC_HOSTMANAGESSOURCE | SCRIPTPROC_ISEXPRESSION | SCRIPTPROC_IMPLICIT_THIS | SCRIPTPROC_IMPLICIT_PARENTS)

#define SCRIPTINFO_IUNKNOWN 0x00000001
#define SCRIPTINFO_ITYPEINFO 0x00000002
#define SCRIPTINFO_ALL_FLAGS (SCRIPTINFO_IUNKNOWN | SCRIPTINFO_ITYPEINFO)

#define SCRIPTINTERRUPT_DEBUG 0x00000001
#define SCRIPTINTERRUPT_RAISEEXCEPTION 0x00000002
#define SCRIPTINTERRUPT_ALL_FLAGS (SCRIPTINTERRUPT_DEBUG | SCRIPTINTERRUPT_RAISEEXCEPTION)

#define SCRIPTSTAT_STATEMENT_COUNT 1
#define SCRIPTSTAT_INSTRUCTION_COUNT 2
#define SCRIPTSTAT_INTSTRUCTION_TIME 3
#define SCRIPTSTAT_TOTAL_TIME 4

#define SCRIPT_ENCODE_SECTION 0x00000001

#define SCRIPT_ENCODE_DEFAULT_LANGUAGE 0x00000001
#define SCRIPT_ENCODE_NO_ASP_LANGUAGE 0x00000002

#define SCRIPTPROP_NAME 0x00000000
#define SCRIPTPROP_MAJORVERSION 0x00000001
#define SCRIPTPROP_MINORVERSION 0x00000002
#define SCRIPTPROP_BUILDNUMBER 0x00000003

#define SCRIPTPROP_DELAYEDEVENTSINKING 0x00001000
#define SCRIPTPROP_CATCHEXCEPTION 0x00001001
#define SCRIPTPROP_CONVERSIONLCID 0x00001002
#define SCRIPTPROP_HOSTSTACKREQUIRED 0x00001003

#define SCRIPTPROP_DEBUGGER 0x00001100
#define SCRIPTPROP_JITDEBUG 0x00001101

#define SCRIPTPROP_HACK_FIBERSUPPORT 0x70000000
#define SCRIPTPROP_HACK_TRIDENTEVENTSINK 0x70000001

  typedef enum tagSCRIPTSTATE {
    SCRIPTSTATE_UNINITIALIZED = 0,SCRIPTSTATE_INITIALIZED = 5,SCRIPTSTATE_STARTED = 1,SCRIPTSTATE_CONNECTED = 2,
    SCRIPTSTATE_DISCONNECTED = 3,SCRIPTSTATE_CLOSED = 4
  } SCRIPTSTATE;

  typedef enum tagSCRIPTTRACEINFO {
    SCRIPTTRACEINFO_SCRIPTSTART = 0,SCRIPTTRACEINFO_SCRIPTEND = 1,SCRIPTTRACEINFO_COMCALLSTART = 2,
    SCRIPTTRACEINFO_COMCALLEND = 3,SCRIPTTRACEINFO_CREATEOBJSTART = 4,SCRIPTTRACEINFO_CREATEOBJEND = 5,
    SCRIPTTRACEINFO_GETOBJSTART = 6,SCRIPTTRACEINFO_GETOBJEND = 7
  } SCRIPTTRACEINFO;

  typedef enum tagSCRIPTTHREADSTATE {
    SCRIPTTHREADSTATE_NOTINSCRIPT = 0,SCRIPTTHREADSTATE_RUNNING = 1
  } SCRIPTTHREADSTATE;

  typedef enum tagSCRIPTGCTYPE {
    SCRIPTGCTYPE_NORMAL = 0,SCRIPTGCTYPE_EXHAUSTIVE = 1
  } SCRIPTGCTYPE;

  typedef DWORD SCRIPTTHREADID;

#define SCRIPTTHREADID_CURRENT ((SCRIPTTHREADID)-1)
#define SCRIPTTHREADID_BASE ((SCRIPTTHREADID)-2)
#define SCRIPTTHREADID_ALL ((SCRIPTTHREADID)-3)

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0000_v0_0_s_ifspec;

#ifndef __IActiveScriptSite_INTERFACE_DEFINED__
#define __IActiveScriptSite_INTERFACE_DEFINED__

  EXTERN_C const IID IID_IActiveScriptSite;

#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptSite : public IUnknown {
  public:
    virtual HRESULT WINAPI GetLCID(LCID *plcid) = 0;
    virtual HRESULT WINAPI GetItemInfo(LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti) = 0;
    virtual HRESULT WINAPI GetDocVersionString(BSTR *pbstrVersion) = 0;
    virtual HRESULT WINAPI OnScriptTerminate(const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo) = 0;
    virtual HRESULT WINAPI OnStateChange(SCRIPTSTATE ssScriptState) = 0;
    virtual HRESULT WINAPI OnScriptError(IActiveScriptError *pscripterror) = 0;
    virtual HRESULT WINAPI OnEnterScript(void) = 0;
    virtual HRESULT WINAPI OnLeaveScript(void) = 0;
  };
#else
  typedef struct IActiveScriptSiteVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptSite *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptSite *This);
      ULONG (WINAPI *Release)(IActiveScriptSite *This);
      HRESULT (WINAPI *GetLCID)(IActiveScriptSite *This,LCID *plcid);
      HRESULT (WINAPI *GetItemInfo)(IActiveScriptSite *This,LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti);
      HRESULT (WINAPI *GetDocVersionString)(IActiveScriptSite *This,BSTR *pbstrVersion);
      HRESULT (WINAPI *OnScriptTerminate)(IActiveScriptSite *This,const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo);
      HRESULT (WINAPI *OnStateChange)(IActiveScriptSite *This,SCRIPTSTATE ssScriptState);
      HRESULT (WINAPI *OnScriptError)(IActiveScriptSite *This,IActiveScriptError *pscripterror);
      HRESULT (WINAPI *OnEnterScript)(IActiveScriptSite *This);
      HRESULT (WINAPI *OnLeaveScript)(IActiveScriptSite *This);
    END_INTERFACE
  } IActiveScriptSiteVtbl;
  struct IActiveScriptSite {
    CONST_VTBL struct IActiveScriptSiteVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptSite_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptSite_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptSite_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptSite_GetLCID(This,plcid) (This)->lpVtbl->GetLCID(This,plcid)
#define IActiveScriptSite_GetItemInfo(This,pstrName,dwReturnMask,ppiunkItem,ppti) (This)->lpVtbl->GetItemInfo(This,pstrName,dwReturnMask,ppiunkItem,ppti)
#define IActiveScriptSite_GetDocVersionString(This,pbstrVersion) (This)->lpVtbl->GetDocVersionString(This,pbstrVersion)
#define IActiveScriptSite_OnScriptTerminate(This,pvarResult,pexcepinfo) (This)->lpVtbl->OnScriptTerminate(This,pvarResult,pexcepinfo)
#define IActiveScriptSite_OnStateChange(This,ssScriptState) (This)->lpVtbl->OnStateChange(This,ssScriptState)
#define IActiveScriptSite_OnScriptError(This,pscripterror) (This)->lpVtbl->OnScriptError(This,pscripterror)
#define IActiveScriptSite_OnEnterScript(This) (This)->lpVtbl->OnEnterScript(This)
#define IActiveScriptSite_OnLeaveScript(This) (This)->lpVtbl->OnLeaveScript(This)
#endif
#endif

  HRESULT WINAPI IActiveScriptSite_GetLCID_Proxy(IActiveScriptSite *This,LCID *plcid);
  void __RPC_STUB IActiveScriptSite_GetLCID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_GetItemInfo_Proxy(IActiveScriptSite *This,LPCOLESTR pstrName,DWORD dwReturnMask,IUnknown **ppiunkItem,ITypeInfo **ppti);
  void __RPC_STUB IActiveScriptSite_GetItemInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_GetDocVersionString_Proxy(IActiveScriptSite *This,BSTR *pbstrVersion);
  void __RPC_STUB IActiveScriptSite_GetDocVersionString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_OnScriptTerminate_Proxy(IActiveScriptSite *This,const VARIANT *pvarResult,const EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptSite_OnScriptTerminate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_OnStateChange_Proxy(IActiveScriptSite *This,SCRIPTSTATE ssScriptState);
  void __RPC_STUB IActiveScriptSite_OnStateChange_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_OnScriptError_Proxy(IActiveScriptSite *This,IActiveScriptError *pscripterror);
  void __RPC_STUB IActiveScriptSite_OnScriptError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_OnEnterScript_Proxy(IActiveScriptSite *This);
  void __RPC_STUB IActiveScriptSite_OnEnterScript_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSite_OnLeaveScript_Proxy(IActiveScriptSite *This);
  void __RPC_STUB IActiveScriptSite_OnLeaveScript_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptError_INTERFACE_DEFINED__
#define __IActiveScriptError_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptError;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptError : public IUnknown {
  public:
    virtual HRESULT WINAPI GetExceptionInfo(EXCEPINFO *pexcepinfo) = 0;
    virtual HRESULT WINAPI GetSourcePosition(DWORD *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition) = 0;
    virtual HRESULT WINAPI GetSourceLineText(BSTR *pbstrSourceLine) = 0;
  };
#else
  typedef struct IActiveScriptErrorVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptError *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptError *This);
      ULONG (WINAPI *Release)(IActiveScriptError *This);
      HRESULT (WINAPI *GetExceptionInfo)(IActiveScriptError *This,EXCEPINFO *pexcepinfo);
      HRESULT (WINAPI *GetSourcePosition)(IActiveScriptError *This,DWORD *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition);
      HRESULT (WINAPI *GetSourceLineText)(IActiveScriptError *This,BSTR *pbstrSourceLine);
    END_INTERFACE
  } IActiveScriptErrorVtbl;
  struct IActiveScriptError {
    CONST_VTBL struct IActiveScriptErrorVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptError_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptError_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptError_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptError_GetExceptionInfo(This,pexcepinfo) (This)->lpVtbl->GetExceptionInfo(This,pexcepinfo)
#define IActiveScriptError_GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition) (This)->lpVtbl->GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition)
#define IActiveScriptError_GetSourceLineText(This,pbstrSourceLine) (This)->lpVtbl->GetSourceLineText(This,pbstrSourceLine)
#endif
#endif

  HRESULT WINAPI IActiveScriptError_RemoteGetExceptionInfo_Proxy(IActiveScriptError *This,EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptError_RemoteGetExceptionInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptError_GetSourcePosition_Proxy(IActiveScriptError *This,DWORD *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition);
  void __RPC_STUB IActiveScriptError_GetSourcePosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptError_GetSourceLineText_Proxy(IActiveScriptError *This,BSTR *pbstrSourceLine);
  void __RPC_STUB IActiveScriptError_GetSourceLineText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptError64_INTERFACE_DEFINED__
#define __IActiveScriptError64_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptError64;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptError64 : public IActiveScriptError {
  public:
    virtual HRESULT WINAPI GetSourcePosition64(DWORDLONG *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition) = 0;
  };
#else
  typedef struct IActiveScriptError64Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptError64 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptError64 *This);
      ULONG (WINAPI *Release)(IActiveScriptError64 *This);
      HRESULT (WINAPI *GetExceptionInfo)(IActiveScriptError64 *This,EXCEPINFO *pexcepinfo);
      HRESULT (WINAPI *GetSourcePosition)(IActiveScriptError64 *This,DWORD *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition);
      HRESULT (WINAPI *GetSourceLineText)(IActiveScriptError64 *This,BSTR *pbstrSourceLine);
      HRESULT (WINAPI *GetSourcePosition64)(IActiveScriptError64 *This,DWORDLONG *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition);
    END_INTERFACE
  } IActiveScriptError64Vtbl;
  struct IActiveScriptError64 {
    CONST_VTBL struct IActiveScriptError64Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptError64_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptError64_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptError64_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptError64_GetExceptionInfo(This,pexcepinfo) (This)->lpVtbl->GetExceptionInfo(This,pexcepinfo)
#define IActiveScriptError64_GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition) (This)->lpVtbl->GetSourcePosition(This,pdwSourceContext,pulLineNumber,plCharacterPosition)
#define IActiveScriptError64_GetSourceLineText(This,pbstrSourceLine) (This)->lpVtbl->GetSourceLineText(This,pbstrSourceLine)
#define IActiveScriptError64_GetSourcePosition64(This,pdwSourceContext,pulLineNumber,plCharacterPosition) (This)->lpVtbl->GetSourcePosition64(This,pdwSourceContext,pulLineNumber,plCharacterPosition)
#endif
#endif

  HRESULT WINAPI IActiveScriptError64_GetSourcePosition64_Proxy(IActiveScriptError64 *This,DWORDLONG *pdwSourceContext,ULONG *pulLineNumber,LONG *plCharacterPosition);
  void __RPC_STUB IActiveScriptError64_GetSourcePosition64_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptSiteWindow_INTERFACE_DEFINED__
#define __IActiveScriptSiteWindow_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptSiteWindow;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptSiteWindow : public IUnknown {
  public:
    virtual HRESULT WINAPI GetWindow(HWND *phwnd) = 0;
    virtual HRESULT WINAPI EnableModeless(WINBOOL fEnable) = 0;
  };
#else
  typedef struct IActiveScriptSiteWindowVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptSiteWindow *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptSiteWindow *This);
      ULONG (WINAPI *Release)(IActiveScriptSiteWindow *This);
      HRESULT (WINAPI *GetWindow)(IActiveScriptSiteWindow *This,HWND *phwnd);
      HRESULT (WINAPI *EnableModeless)(IActiveScriptSiteWindow *This,WINBOOL fEnable);
    END_INTERFACE
  } IActiveScriptSiteWindowVtbl;
  struct IActiveScriptSiteWindow {
    CONST_VTBL struct IActiveScriptSiteWindowVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptSiteWindow_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptSiteWindow_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptSiteWindow_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptSiteWindow_GetWindow(This,phwnd) (This)->lpVtbl->GetWindow(This,phwnd)
#define IActiveScriptSiteWindow_EnableModeless(This,fEnable) (This)->lpVtbl->EnableModeless(This,fEnable)
#endif
#endif

  HRESULT WINAPI IActiveScriptSiteWindow_GetWindow_Proxy(IActiveScriptSiteWindow *This,HWND *phwnd);
  void __RPC_STUB IActiveScriptSiteWindow_GetWindow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptSiteWindow_EnableModeless_Proxy(IActiveScriptSiteWindow *This,WINBOOL fEnable);
  void __RPC_STUB IActiveScriptSiteWindow_EnableModeless_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED__
#define __IActiveScriptSiteInterruptPoll_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptSiteInterruptPoll;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptSiteInterruptPoll : public IUnknown {
  public:
    virtual HRESULT WINAPI QueryContinue(void) = 0;
  };
#else
  typedef struct IActiveScriptSiteInterruptPollVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptSiteInterruptPoll *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptSiteInterruptPoll *This);
      ULONG (WINAPI *Release)(IActiveScriptSiteInterruptPoll *This);
      HRESULT (WINAPI *QueryContinue)(IActiveScriptSiteInterruptPoll *This);
    END_INTERFACE
  } IActiveScriptSiteInterruptPollVtbl;
  struct IActiveScriptSiteInterruptPoll {
    CONST_VTBL struct IActiveScriptSiteInterruptPollVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptSiteInterruptPoll_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptSiteInterruptPoll_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptSiteInterruptPoll_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptSiteInterruptPoll_QueryContinue(This) (This)->lpVtbl->QueryContinue(This)
#endif
#endif

  HRESULT WINAPI IActiveScriptSiteInterruptPoll_QueryContinue_Proxy(IActiveScriptSiteInterruptPoll *This);
  void __RPC_STUB IActiveScriptSiteInterruptPoll_QueryContinue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScript_INTERFACE_DEFINED__
#define __IActiveScript_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScript;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScript : public IUnknown {
  public:
    virtual HRESULT WINAPI SetScriptSite(IActiveScriptSite *pass) = 0;
    virtual HRESULT WINAPI GetScriptSite(REFIID riid,void **ppvObject) = 0;
    virtual HRESULT WINAPI SetScriptState(SCRIPTSTATE ss) = 0;
    virtual HRESULT WINAPI GetScriptState(SCRIPTSTATE *pssState) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI AddNamedItem(LPCOLESTR pstrName,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI AddTypeLib(REFGUID rguidTypeLib,DWORD dwMajor,DWORD dwMinor,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI GetScriptDispatch(LPCOLESTR pstrItemName,IDispatch **ppdisp) = 0;
    virtual HRESULT WINAPI GetCurrentScriptThreadID(SCRIPTTHREADID *pstidThread) = 0;
    virtual HRESULT WINAPI GetScriptThreadID(DWORD dwWin32ThreadId,SCRIPTTHREADID *pstidThread) = 0;
    virtual HRESULT WINAPI GetScriptThreadState(SCRIPTTHREADID stidThread,SCRIPTTHREADSTATE *pstsState) = 0;
    virtual HRESULT WINAPI InterruptScriptThread(SCRIPTTHREADID stidThread,const EXCEPINFO *pexcepinfo,DWORD dwFlags) = 0;
    virtual HRESULT WINAPI Clone(IActiveScript **ppscript) = 0;
  };
#else
  typedef struct IActiveScriptVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScript *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScript *This);
      ULONG (WINAPI *Release)(IActiveScript *This);
      HRESULT (WINAPI *SetScriptSite)(IActiveScript *This,IActiveScriptSite *pass);
      HRESULT (WINAPI *GetScriptSite)(IActiveScript *This,REFIID riid,void **ppvObject);
      HRESULT (WINAPI *SetScriptState)(IActiveScript *This,SCRIPTSTATE ss);
      HRESULT (WINAPI *GetScriptState)(IActiveScript *This,SCRIPTSTATE *pssState);
      HRESULT (WINAPI *Close)(IActiveScript *This);
      HRESULT (WINAPI *AddNamedItem)(IActiveScript *This,LPCOLESTR pstrName,DWORD dwFlags);
      HRESULT (WINAPI *AddTypeLib)(IActiveScript *This,REFGUID rguidTypeLib,DWORD dwMajor,DWORD dwMinor,DWORD dwFlags);
      HRESULT (WINAPI *GetScriptDispatch)(IActiveScript *This,LPCOLESTR pstrItemName,IDispatch **ppdisp);
      HRESULT (WINAPI *GetCurrentScriptThreadID)(IActiveScript *This,SCRIPTTHREADID *pstidThread);
      HRESULT (WINAPI *GetScriptThreadID)(IActiveScript *This,DWORD dwWin32ThreadId,SCRIPTTHREADID *pstidThread);
      HRESULT (WINAPI *GetScriptThreadState)(IActiveScript *This,SCRIPTTHREADID stidThread,SCRIPTTHREADSTATE *pstsState);
      HRESULT (WINAPI *InterruptScriptThread)(IActiveScript *This,SCRIPTTHREADID stidThread,const EXCEPINFO *pexcepinfo,DWORD dwFlags);
      HRESULT (WINAPI *Clone)(IActiveScript *This,IActiveScript **ppscript);
    END_INTERFACE
  } IActiveScriptVtbl;
  struct IActiveScript {
    CONST_VTBL struct IActiveScriptVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScript_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScript_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScript_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScript_SetScriptSite(This,pass) (This)->lpVtbl->SetScriptSite(This,pass)
#define IActiveScript_GetScriptSite(This,riid,ppvObject) (This)->lpVtbl->GetScriptSite(This,riid,ppvObject)
#define IActiveScript_SetScriptState(This,ss) (This)->lpVtbl->SetScriptState(This,ss)
#define IActiveScript_GetScriptState(This,pssState) (This)->lpVtbl->GetScriptState(This,pssState)
#define IActiveScript_Close(This) (This)->lpVtbl->Close(This)
#define IActiveScript_AddNamedItem(This,pstrName,dwFlags) (This)->lpVtbl->AddNamedItem(This,pstrName,dwFlags)
#define IActiveScript_AddTypeLib(This,rguidTypeLib,dwMajor,dwMinor,dwFlags) (This)->lpVtbl->AddTypeLib(This,rguidTypeLib,dwMajor,dwMinor,dwFlags)
#define IActiveScript_GetScriptDispatch(This,pstrItemName,ppdisp) (This)->lpVtbl->GetScriptDispatch(This,pstrItemName,ppdisp)
#define IActiveScript_GetCurrentScriptThreadID(This,pstidThread) (This)->lpVtbl->GetCurrentScriptThreadID(This,pstidThread)
#define IActiveScript_GetScriptThreadID(This,dwWin32ThreadId,pstidThread) (This)->lpVtbl->GetScriptThreadID(This,dwWin32ThreadId,pstidThread)
#define IActiveScript_GetScriptThreadState(This,stidThread,pstsState) (This)->lpVtbl->GetScriptThreadState(This,stidThread,pstsState)
#define IActiveScript_InterruptScriptThread(This,stidThread,pexcepinfo,dwFlags) (This)->lpVtbl->InterruptScriptThread(This,stidThread,pexcepinfo,dwFlags)
#define IActiveScript_Clone(This,ppscript) (This)->lpVtbl->Clone(This,ppscript)
#endif
#endif

  HRESULT WINAPI IActiveScript_SetScriptSite_Proxy(IActiveScript *This,IActiveScriptSite *pass);
  void __RPC_STUB IActiveScript_SetScriptSite_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetScriptSite_Proxy(IActiveScript *This,REFIID riid,void **ppvObject);
  void __RPC_STUB IActiveScript_GetScriptSite_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_SetScriptState_Proxy(IActiveScript *This,SCRIPTSTATE ss);
  void __RPC_STUB IActiveScript_SetScriptState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetScriptState_Proxy(IActiveScript *This,SCRIPTSTATE *pssState);
  void __RPC_STUB IActiveScript_GetScriptState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_Close_Proxy(IActiveScript *This);
  void __RPC_STUB IActiveScript_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_AddNamedItem_Proxy(IActiveScript *This,LPCOLESTR pstrName,DWORD dwFlags);
  void __RPC_STUB IActiveScript_AddNamedItem_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_AddTypeLib_Proxy(IActiveScript *This,REFGUID rguidTypeLib,DWORD dwMajor,DWORD dwMinor,DWORD dwFlags);
  void __RPC_STUB IActiveScript_AddTypeLib_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetScriptDispatch_Proxy(IActiveScript *This,LPCOLESTR pstrItemName,IDispatch **ppdisp);
  void __RPC_STUB IActiveScript_GetScriptDispatch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetCurrentScriptThreadID_Proxy(IActiveScript *This,SCRIPTTHREADID *pstidThread);
  void __RPC_STUB IActiveScript_GetCurrentScriptThreadID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetScriptThreadID_Proxy(IActiveScript *This,DWORD dwWin32ThreadId,SCRIPTTHREADID *pstidThread);
  void __RPC_STUB IActiveScript_GetScriptThreadID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_GetScriptThreadState_Proxy(IActiveScript *This,SCRIPTTHREADID stidThread,SCRIPTTHREADSTATE *pstsState);
  void __RPC_STUB IActiveScript_GetScriptThreadState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_InterruptScriptThread_Proxy(IActiveScript *This,SCRIPTTHREADID stidThread,const EXCEPINFO *pexcepinfo,DWORD dwFlags);
  void __RPC_STUB IActiveScript_InterruptScriptThread_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScript_Clone_Proxy(IActiveScript *This,IActiveScript **ppscript);
  void __RPC_STUB IActiveScript_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptParse32_INTERFACE_DEFINED__
#define __IActiveScriptParse32_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParse32;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParse32 : public IUnknown {
  public:
    virtual HRESULT WINAPI InitNew(void) = 0;
    virtual HRESULT WINAPI AddScriptlet(LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo) = 0;
    virtual HRESULT WINAPI ParseScriptText(LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo) = 0;
  };
#else
  typedef struct IActiveScriptParse32Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParse32 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParse32 *This);
      ULONG (WINAPI *Release)(IActiveScriptParse32 *This);
      HRESULT (WINAPI *InitNew)(IActiveScriptParse32 *This);
      HRESULT (WINAPI *AddScriptlet)(IActiveScriptParse32 *This,LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo);
      HRESULT (WINAPI *ParseScriptText)(IActiveScriptParse32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo);
    END_INTERFACE
  } IActiveScriptParse32Vtbl;
  struct IActiveScriptParse32 {
    CONST_VTBL struct IActiveScriptParse32Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParse32_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParse32_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParse32_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParse32_InitNew(This) (This)->lpVtbl->InitNew(This)
#define IActiveScriptParse32_AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo) (This)->lpVtbl->AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo)
#define IActiveScriptParse32_ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo) (This)->lpVtbl->ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo)
#endif
#endif

  HRESULT WINAPI IActiveScriptParse32_InitNew_Proxy(IActiveScriptParse32 *This);
  void __RPC_STUB IActiveScriptParse32_InitNew_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptParse32_AddScriptlet_Proxy(IActiveScriptParse32 *This,LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptParse32_AddScriptlet_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptParse32_ParseScriptText_Proxy(IActiveScriptParse32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptParse32_ParseScriptText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptParse64_INTERFACE_DEFINED__
#define __IActiveScriptParse64_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParse64;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParse64 : public IUnknown {
  public:
    virtual HRESULT WINAPI InitNew(void) = 0;
    virtual HRESULT WINAPI AddScriptlet(LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo) = 0;
    virtual HRESULT WINAPI ParseScriptText(LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo) = 0;
  };
#else
  typedef struct IActiveScriptParse64Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParse64 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParse64 *This);
      ULONG (WINAPI *Release)(IActiveScriptParse64 *This);
      HRESULT (WINAPI *InitNew)(IActiveScriptParse64 *This);
      HRESULT (WINAPI *AddScriptlet)(IActiveScriptParse64 *This,LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo);
      HRESULT (WINAPI *ParseScriptText)(IActiveScriptParse64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo);
    END_INTERFACE
  } IActiveScriptParse64Vtbl;
  struct IActiveScriptParse64 {
    CONST_VTBL struct IActiveScriptParse64Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParse64_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParse64_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParse64_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParse64_InitNew(This) (This)->lpVtbl->InitNew(This)
#define IActiveScriptParse64_AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo) (This)->lpVtbl->AddScriptlet(This,pstrDefaultName,pstrCode,pstrItemName,pstrSubItemName,pstrEventName,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pbstrName,pexcepinfo)
#define IActiveScriptParse64_ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo) (This)->lpVtbl->ParseScriptText(This,pstrCode,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,pvarResult,pexcepinfo)
#endif
#endif

  HRESULT WINAPI IActiveScriptParse64_InitNew_Proxy(IActiveScriptParse64 *This);
  void __RPC_STUB IActiveScriptParse64_InitNew_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptParse64_AddScriptlet_Proxy(IActiveScriptParse64 *This,LPCOLESTR pstrDefaultName,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,LPCOLESTR pstrSubItemName,LPCOLESTR pstrEventName,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,BSTR *pbstrName,EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptParse64_AddScriptlet_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptParse64_ParseScriptText_Proxy(IActiveScriptParse64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,VARIANT *pvarResult,EXCEPINFO *pexcepinfo);
  void __RPC_STUB IActiveScriptParse64_ParseScriptText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef _WIN64
#define IActiveScriptParse IActiveScriptParse64
#define IID_IActiveScriptParse IID_IActiveScriptParse64
#else
#define IActiveScriptParse IActiveScriptParse32
#define IID_IActiveScriptParse IID_IActiveScriptParse32
#endif
  typedef IActiveScriptParse *PIActiveScriptParse;

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0270_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0270_v0_0_s_ifspec;

#ifndef __IActiveScriptParseProcedureOld32_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedureOld32_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedureOld32;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedureOld32 : public IUnknown {
  public:
    virtual HRESULT WINAPI ParseProcedureText(LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp) = 0;
  };
#else
  typedef struct IActiveScriptParseProcedureOld32Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedureOld32 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedureOld32 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedureOld32 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedureOld32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedureOld32Vtbl;
  struct IActiveScriptParseProcedureOld32 {
    CONST_VTBL struct IActiveScriptParseProcedureOld32Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedureOld32_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedureOld32_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedureOld32_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedureOld32_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif

  HRESULT WINAPI IActiveScriptParseProcedureOld32_ParseProcedureText_Proxy(IActiveScriptParseProcedureOld32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
  void __RPC_STUB IActiveScriptParseProcedureOld32_ParseProcedureText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptParseProcedureOld64_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedureOld64_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedureOld64;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedureOld64 : public IUnknown {
  public:
    virtual HRESULT WINAPI ParseProcedureText(LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp) = 0;
  };
#else
  typedef struct IActiveScriptParseProcedureOld64Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedureOld64 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedureOld64 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedureOld64 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedureOld64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedureOld64Vtbl;
  struct IActiveScriptParseProcedureOld64 {
    CONST_VTBL struct IActiveScriptParseProcedureOld64Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedureOld64_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedureOld64_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedureOld64_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedureOld64_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif

  HRESULT WINAPI IActiveScriptParseProcedureOld64_ParseProcedureText_Proxy(IActiveScriptParseProcedureOld64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
  void __RPC_STUB IActiveScriptParseProcedureOld64_ParseProcedureText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef _WIN64
#define IActiveScriptParseProcedureOld IActiveScriptParseProcedureOld64
#define IID_IActiveScriptParseProcedureOld IID_IActiveScriptParseProcedureOld64
#else
#define IActiveScriptParseProcedureOld IActiveScriptParseProcedureOld32
#define IID_IActiveScriptParseProcedureOld IID_IActiveScriptParseProcedureOld32
#endif
  typedef IActiveScriptParseProcedureOld *PIActiveScriptParseProcedureOld;

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0272_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0272_v0_0_s_ifspec;

#ifndef __IActiveScriptParseProcedure32_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedure32_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedure32;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedure32 : public IUnknown {
  public:
    virtual HRESULT WINAPI ParseProcedureText(LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp) = 0;
  };
#else
  typedef struct IActiveScriptParseProcedure32Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedure32 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedure32 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedure32 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedure32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedure32Vtbl;
  struct IActiveScriptParseProcedure32 {
    CONST_VTBL struct IActiveScriptParseProcedure32Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedure32_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedure32_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedure32_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedure32_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif

  HRESULT WINAPI IActiveScriptParseProcedure32_ParseProcedureText_Proxy(IActiveScriptParseProcedure32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
  void __RPC_STUB IActiveScriptParseProcedure32_ParseProcedureText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptParseProcedure64_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedure64_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedure64;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedure64 : public IUnknown {
  public:
    virtual HRESULT WINAPI ParseProcedureText(LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp) = 0;
  };
#else
  typedef struct IActiveScriptParseProcedure64Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedure64 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedure64 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedure64 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedure64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedure64Vtbl;
  struct IActiveScriptParseProcedure64 {
    CONST_VTBL struct IActiveScriptParseProcedure64Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedure64_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedure64_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedure64_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedure64_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif

  HRESULT WINAPI IActiveScriptParseProcedure64_ParseProcedureText_Proxy(IActiveScriptParseProcedure64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
  void __RPC_STUB IActiveScriptParseProcedure64_ParseProcedureText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifdef _WIN64
#define IActiveScriptParseProcedure IActiveScriptParseProcedure64
#define IID_IActiveScriptParseProcedure IID_IActiveScriptParseProcedure64
#else
#define IActiveScriptParseProcedure IActiveScriptParseProcedure32
#define IID_IActiveScriptParseProcedure IID_IActiveScriptParseProcedure32
#endif
  typedef IActiveScriptParseProcedure *PIActiveScriptParseProcedure;

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0274_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0274_v0_0_s_ifspec;

#ifndef __IActiveScriptParseProcedure2_32_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedure2_32_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedure2_32;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedure2_32 : public IActiveScriptParseProcedure32 {
  public:
  };
#else
  typedef struct IActiveScriptParseProcedure2_32Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedure2_32 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedure2_32 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedure2_32 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedure2_32 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORD dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedure2_32Vtbl;
  struct IActiveScriptParseProcedure2_32 {
    CONST_VTBL struct IActiveScriptParseProcedure2_32Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedure2_32_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedure2_32_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedure2_32_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedure2_32_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif
#endif

#ifndef __IActiveScriptParseProcedure2_64_INTERFACE_DEFINED__
#define __IActiveScriptParseProcedure2_64_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptParseProcedure2_64;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptParseProcedure2_64 : public IActiveScriptParseProcedure64 {
  public:
  };
#else
  typedef struct IActiveScriptParseProcedure2_64Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptParseProcedure2_64 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptParseProcedure2_64 *This);
      ULONG (WINAPI *Release)(IActiveScriptParseProcedure2_64 *This);
      HRESULT (WINAPI *ParseProcedureText)(IActiveScriptParseProcedure2_64 *This,LPCOLESTR pstrCode,LPCOLESTR pstrFormalParams,LPCOLESTR pstrProcedureName,LPCOLESTR pstrItemName,IUnknown *punkContext,LPCOLESTR pstrDelimiter,DWORDLONG dwSourceContextCookie,ULONG ulStartingLineNumber,DWORD dwFlags,IDispatch **ppdisp);
    END_INTERFACE
  } IActiveScriptParseProcedure2_64Vtbl;
  struct IActiveScriptParseProcedure2_64 {
    CONST_VTBL struct IActiveScriptParseProcedure2_64Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptParseProcedure2_64_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptParseProcedure2_64_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptParseProcedure2_64_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptParseProcedure2_64_ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp) (This)->lpVtbl->ParseProcedureText(This,pstrCode,pstrFormalParams,pstrProcedureName,pstrItemName,punkContext,pstrDelimiter,dwSourceContextCookie,ulStartingLineNumber,dwFlags,ppdisp)
#endif
#endif
#endif

#ifdef _WIN64
#define IActiveScriptParseProcedure2 IActiveScriptParseProcedure2_64
#define IID_IActiveScriptParseProcedure2 IID_IActiveScriptParseProcedure2_64
#else
#define IActiveScriptParseProcedure2 IActiveScriptParseProcedure2_32
#define IID_IActiveScriptParseProcedure2 IID_IActiveScriptParseProcedure2_32
#endif
  typedef IActiveScriptParseProcedure2 *PIActiveScriptParseProcedure2;

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0276_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0276_v0_0_s_ifspec;

#ifndef __IActiveScriptEncode_INTERFACE_DEFINED__
#define __IActiveScriptEncode_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptEncode;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptEncode : public IUnknown {
  public:
    virtual HRESULT WINAPI EncodeSection(LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet) = 0;
    virtual HRESULT WINAPI DecodeScript(LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet) = 0;
    virtual HRESULT WINAPI GetEncodeProgId(BSTR *pbstrOut) = 0;
  };
#else
  typedef struct IActiveScriptEncodeVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptEncode *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptEncode *This);
      ULONG (WINAPI *Release)(IActiveScriptEncode *This);
      HRESULT (WINAPI *EncodeSection)(IActiveScriptEncode *This,LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet);
      HRESULT (WINAPI *DecodeScript)(IActiveScriptEncode *This,LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet);
      HRESULT (WINAPI *GetEncodeProgId)(IActiveScriptEncode *This,BSTR *pbstrOut);
    END_INTERFACE
  } IActiveScriptEncodeVtbl;
  struct IActiveScriptEncode {
    CONST_VTBL struct IActiveScriptEncodeVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptEncode_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptEncode_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptEncode_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptEncode_EncodeSection(This,pchIn,cchIn,pchOut,cchOut,pcchRet) (This)->lpVtbl->EncodeSection(This,pchIn,cchIn,pchOut,cchOut,pcchRet)
#define IActiveScriptEncode_DecodeScript(This,pchIn,cchIn,pchOut,cchOut,pcchRet) (This)->lpVtbl->DecodeScript(This,pchIn,cchIn,pchOut,cchOut,pcchRet)
#define IActiveScriptEncode_GetEncodeProgId(This,pbstrOut) (This)->lpVtbl->GetEncodeProgId(This,pbstrOut)
#endif
#endif

  HRESULT WINAPI IActiveScriptEncode_EncodeSection_Proxy(IActiveScriptEncode *This,LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet);
  void __RPC_STUB IActiveScriptEncode_EncodeSection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptEncode_DecodeScript_Proxy(IActiveScriptEncode *This,LPCOLESTR pchIn,DWORD cchIn,LPOLESTR pchOut,DWORD cchOut,DWORD *pcchRet);
  void __RPC_STUB IActiveScriptEncode_DecodeScript_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptEncode_GetEncodeProgId_Proxy(IActiveScriptEncode *This,BSTR *pbstrOut);
  void __RPC_STUB IActiveScriptEncode_GetEncodeProgId_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptHostEncode_INTERFACE_DEFINED__
#define __IActiveScriptHostEncode_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptHostEncode;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptHostEncode : public IUnknown {
  public:
    virtual HRESULT WINAPI EncodeScriptHostFile(BSTR bstrInFile,BSTR *pbstrOutFile,unsigned __LONG32 cFlags,BSTR bstrDefaultLang) = 0;
  };
#else
  typedef struct IActiveScriptHostEncodeVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptHostEncode *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptHostEncode *This);
      ULONG (WINAPI *Release)(IActiveScriptHostEncode *This);
      HRESULT (WINAPI *EncodeScriptHostFile)(IActiveScriptHostEncode *This,BSTR bstrInFile,BSTR *pbstrOutFile,unsigned __LONG32 cFlags,BSTR bstrDefaultLang);
    END_INTERFACE
  } IActiveScriptHostEncodeVtbl;
  struct IActiveScriptHostEncode {
    CONST_VTBL struct IActiveScriptHostEncodeVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptHostEncode_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptHostEncode_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptHostEncode_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptHostEncode_EncodeScriptHostFile(This,bstrInFile,pbstrOutFile,cFlags,bstrDefaultLang) (This)->lpVtbl->EncodeScriptHostFile(This,bstrInFile,pbstrOutFile,cFlags,bstrDefaultLang)
#endif
#endif

  HRESULT WINAPI IActiveScriptHostEncode_EncodeScriptHostFile_Proxy(IActiveScriptHostEncode *This,BSTR bstrInFile,BSTR *pbstrOutFile,unsigned __LONG32 cFlags,BSTR bstrDefaultLang);
  void __RPC_STUB IActiveScriptHostEncode_EncodeScriptHostFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IBindEventHandler_INTERFACE_DEFINED__
#define __IBindEventHandler_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IBindEventHandler;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IBindEventHandler : public IUnknown {
  public:
    virtual HRESULT WINAPI BindHandler(LPCOLESTR pstrEvent,IDispatch *pdisp) = 0;

  };
#else
  typedef struct IBindEventHandlerVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IBindEventHandler *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IBindEventHandler *This);
      ULONG (WINAPI *Release)(IBindEventHandler *This);
      HRESULT (WINAPI *BindHandler)(IBindEventHandler *This,LPCOLESTR pstrEvent,IDispatch *pdisp);
    END_INTERFACE
  } IBindEventHandlerVtbl;
  struct IBindEventHandler {
    CONST_VTBL struct IBindEventHandlerVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IBindEventHandler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IBindEventHandler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IBindEventHandler_Release(This) (This)->lpVtbl->Release(This)
#define IBindEventHandler_BindHandler(This,pstrEvent,pdisp) (This)->lpVtbl->BindHandler(This,pstrEvent,pdisp)
#endif
#endif

  HRESULT WINAPI IBindEventHandler_BindHandler_Proxy(IBindEventHandler *This,LPCOLESTR pstrEvent,IDispatch *pdisp);
  void __RPC_STUB IBindEventHandler_BindHandler_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptStats_INTERFACE_DEFINED__
#define __IActiveScriptStats_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptStats;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptStats : public IUnknown {
  public:
    virtual HRESULT WINAPI GetStat(DWORD stid,ULONG *pluHi,ULONG *pluLo) = 0;
    virtual HRESULT WINAPI GetStatEx(REFGUID guid,ULONG *pluHi,ULONG *pluLo) = 0;
    virtual HRESULT WINAPI ResetStats(void) = 0;
  };
#else
  typedef struct IActiveScriptStatsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptStats *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptStats *This);
      ULONG (WINAPI *Release)(IActiveScriptStats *This);
      HRESULT (WINAPI *GetStat)(IActiveScriptStats *This,DWORD stid,ULONG *pluHi,ULONG *pluLo);
      HRESULT (WINAPI *GetStatEx)(IActiveScriptStats *This,REFGUID guid,ULONG *pluHi,ULONG *pluLo);
      HRESULT (WINAPI *ResetStats)(IActiveScriptStats *This);
    END_INTERFACE
  } IActiveScriptStatsVtbl;
  struct IActiveScriptStats {
    CONST_VTBL struct IActiveScriptStatsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptStats_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptStats_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptStats_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptStats_GetStat(This,stid,pluHi,pluLo) (This)->lpVtbl->GetStat(This,stid,pluHi,pluLo)
#define IActiveScriptStats_GetStatEx(This,guid,pluHi,pluLo) (This)->lpVtbl->GetStatEx(This,guid,pluHi,pluLo)
#define IActiveScriptStats_ResetStats(This) (This)->lpVtbl->ResetStats(This)
#endif
#endif

  HRESULT WINAPI IActiveScriptStats_GetStat_Proxy(IActiveScriptStats *This,DWORD stid,ULONG *pluHi,ULONG *pluLo);
  void __RPC_STUB IActiveScriptStats_GetStat_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptStats_GetStatEx_Proxy(IActiveScriptStats *This,REFGUID guid,ULONG *pluHi,ULONG *pluLo);
  void __RPC_STUB IActiveScriptStats_GetStatEx_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptStats_ResetStats_Proxy(IActiveScriptStats *This);
  void __RPC_STUB IActiveScriptStats_ResetStats_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptProperty_INTERFACE_DEFINED__
#define __IActiveScriptProperty_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptProperty;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptProperty : public IUnknown {
  public:
    virtual HRESULT WINAPI GetProperty(DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue) = 0;
    virtual HRESULT WINAPI SetProperty(DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue) = 0;
  };
#else
  typedef struct IActiveScriptPropertyVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptProperty *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptProperty *This);
      ULONG (WINAPI *Release)(IActiveScriptProperty *This);
      HRESULT (WINAPI *GetProperty)(IActiveScriptProperty *This,DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue);
      HRESULT (WINAPI *SetProperty)(IActiveScriptProperty *This,DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue);
    END_INTERFACE
  } IActiveScriptPropertyVtbl;
  struct IActiveScriptProperty {
    CONST_VTBL struct IActiveScriptPropertyVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptProperty_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptProperty_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptProperty_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptProperty_GetProperty(This,dwProperty,pvarIndex,pvarValue) (This)->lpVtbl->GetProperty(This,dwProperty,pvarIndex,pvarValue)
#define IActiveScriptProperty_SetProperty(This,dwProperty,pvarIndex,pvarValue) (This)->lpVtbl->SetProperty(This,dwProperty,pvarIndex,pvarValue)
#endif
#endif

  HRESULT WINAPI IActiveScriptProperty_GetProperty_Proxy(IActiveScriptProperty *This,DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue);
  void __RPC_STUB IActiveScriptProperty_GetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptProperty_SetProperty_Proxy(IActiveScriptProperty *This,DWORD dwProperty,VARIANT *pvarIndex,VARIANT *pvarValue);
  void __RPC_STUB IActiveScriptProperty_SetProperty_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ITridentEventSink_INTERFACE_DEFINED__
#define __ITridentEventSink_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ITridentEventSink;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ITridentEventSink : public IUnknown {
  public:
    virtual HRESULT WINAPI FireEvent(LPCOLESTR pstrEvent,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei) = 0;
  };
#else
  typedef struct ITridentEventSinkVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ITridentEventSink *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ITridentEventSink *This);
      ULONG (WINAPI *Release)(ITridentEventSink *This);
      HRESULT (WINAPI *FireEvent)(ITridentEventSink *This,LPCOLESTR pstrEvent,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei);
    END_INTERFACE
  } ITridentEventSinkVtbl;
  struct ITridentEventSink {
    CONST_VTBL struct ITridentEventSinkVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ITridentEventSink_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define ITridentEventSink_AddRef(This) (This)->lpVtbl->AddRef(This)
#define ITridentEventSink_Release(This) (This)->lpVtbl->Release(This)
#define ITridentEventSink_FireEvent(This,pstrEvent,pdp,pvarRes,pei) (This)->lpVtbl->FireEvent(This,pstrEvent,pdp,pvarRes,pei)
#endif
#endif

  HRESULT WINAPI ITridentEventSink_FireEvent_Proxy(ITridentEventSink *This,LPCOLESTR pstrEvent,DISPPARAMS *pdp,VARIANT *pvarRes,EXCEPINFO *pei);
  void __RPC_STUB ITridentEventSink_FireEvent_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptGarbageCollector_INTERFACE_DEFINED__
#define __IActiveScriptGarbageCollector_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptGarbageCollector;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptGarbageCollector : public IUnknown {
  public:
    virtual HRESULT WINAPI CollectGarbage(SCRIPTGCTYPE scriptgctype) = 0;
  };
#else
  typedef struct IActiveScriptGarbageCollectorVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptGarbageCollector *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptGarbageCollector *This);
      ULONG (WINAPI *Release)(IActiveScriptGarbageCollector *This);
      HRESULT (WINAPI *CollectGarbage)(IActiveScriptGarbageCollector *This,SCRIPTGCTYPE scriptgctype);
    END_INTERFACE
  } IActiveScriptGarbageCollectorVtbl;
  struct IActiveScriptGarbageCollector {
    CONST_VTBL struct IActiveScriptGarbageCollectorVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptGarbageCollector_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptGarbageCollector_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptGarbageCollector_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptGarbageCollector_CollectGarbage(This,scriptgctype) (This)->lpVtbl->CollectGarbage(This,scriptgctype)
#endif
#endif

  HRESULT WINAPI IActiveScriptGarbageCollector_CollectGarbage_Proxy(IActiveScriptGarbageCollector *This,SCRIPTGCTYPE scriptgctype);
  void __RPC_STUB IActiveScriptGarbageCollector_CollectGarbage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptSIPInfo_INTERFACE_DEFINED__
#define __IActiveScriptSIPInfo_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptSIPInfo;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptSIPInfo : public IUnknown {
  public:
    virtual HRESULT WINAPI GetSIPOID(GUID *poid_sip) = 0;
  };
#else
  typedef struct IActiveScriptSIPInfoVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptSIPInfo *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptSIPInfo *This);
      ULONG (WINAPI *Release)(IActiveScriptSIPInfo *This);
      HRESULT (WINAPI *GetSIPOID)(IActiveScriptSIPInfo *This,GUID *poid_sip);
    END_INTERFACE
  } IActiveScriptSIPInfoVtbl;
  struct IActiveScriptSIPInfo {
    CONST_VTBL struct IActiveScriptSIPInfoVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptSIPInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptSIPInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptSIPInfo_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptSIPInfo_GetSIPOID(This,poid_sip) (This)->lpVtbl->GetSIPOID(This,poid_sip)
#endif
#endif

  HRESULT WINAPI IActiveScriptSIPInfo_GetSIPOID_Proxy(IActiveScriptSIPInfo *This,GUID *poid_sip);
  void __RPC_STUB IActiveScriptSIPInfo_GetSIPOID_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptSiteTraceInfo_INTERFACE_DEFINED__
#define __IActiveScriptSiteTraceInfo_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptSiteTraceInfo;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptSiteTraceInfo : public IUnknown {
  public:
    virtual HRESULT WINAPI SendScriptTraceInfo(SCRIPTTRACEINFO stiEventType,GUID guidContextID,DWORD dwScriptContextCookie,LONG lScriptStatementStart,LONG lScriptStatementEnd,DWORD64 dwReserved) = 0;
  };
#else
  typedef struct IActiveScriptSiteTraceInfoVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptSiteTraceInfo *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptSiteTraceInfo *This);
      ULONG (WINAPI *Release)(IActiveScriptSiteTraceInfo *This);
      HRESULT (WINAPI *SendScriptTraceInfo)(IActiveScriptSiteTraceInfo *This,SCRIPTTRACEINFO stiEventType,GUID guidContextID,DWORD dwScriptContextCookie,LONG lScriptStatementStart,LONG lScriptStatementEnd,DWORD64 dwReserved);
    END_INTERFACE
  } IActiveScriptSiteTraceInfoVtbl;
  struct IActiveScriptSiteTraceInfo {
    CONST_VTBL struct IActiveScriptSiteTraceInfoVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptSiteTraceInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptSiteTraceInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptSiteTraceInfo_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptSiteTraceInfo_SendScriptTraceInfo(This,stiEventType,guidContextID,dwScriptContextCookie,lScriptStatementStart,lScriptStatementEnd,dwReserved) (This)->lpVtbl->SendScriptTraceInfo(This,stiEventType,guidContextID,dwScriptContextCookie,lScriptStatementStart,lScriptStatementEnd,dwReserved)
#endif
#endif

  HRESULT WINAPI IActiveScriptSiteTraceInfo_SendScriptTraceInfo_Proxy(IActiveScriptSiteTraceInfo *This,SCRIPTTRACEINFO stiEventType,GUID guidContextID,DWORD dwScriptContextCookie,LONG lScriptStatementStart,LONG lScriptStatementEnd,DWORD64 dwReserved);
  void __RPC_STUB IActiveScriptSiteTraceInfo_SendScriptTraceInfo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __IActiveScriptTraceInfo_INTERFACE_DEFINED__
#define __IActiveScriptTraceInfo_INTERFACE_DEFINED__
  EXTERN_C const IID IID_IActiveScriptTraceInfo;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct IActiveScriptTraceInfo : public IUnknown {
  public:
    virtual HRESULT WINAPI StartScriptTracing(IActiveScriptSiteTraceInfo *pSiteTraceInfo,GUID guidContextID) = 0;
    virtual HRESULT WINAPI StopScriptTracing(void) = 0;
  };
#else
  typedef struct IActiveScriptTraceInfoVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(IActiveScriptTraceInfo *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(IActiveScriptTraceInfo *This);
      ULONG (WINAPI *Release)(IActiveScriptTraceInfo *This);
      HRESULT (WINAPI *StartScriptTracing)(IActiveScriptTraceInfo *This,IActiveScriptSiteTraceInfo *pSiteTraceInfo,GUID guidContextID);
      HRESULT (WINAPI *StopScriptTracing)(IActiveScriptTraceInfo *This);
    END_INTERFACE
  } IActiveScriptTraceInfoVtbl;
  struct IActiveScriptTraceInfo {
    CONST_VTBL struct IActiveScriptTraceInfoVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define IActiveScriptTraceInfo_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IActiveScriptTraceInfo_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IActiveScriptTraceInfo_Release(This) (This)->lpVtbl->Release(This)
#define IActiveScriptTraceInfo_StartScriptTracing(This,pSiteTraceInfo,guidContextID) (This)->lpVtbl->StartScriptTracing(This,pSiteTraceInfo,guidContextID)
#define IActiveScriptTraceInfo_StopScriptTracing(This) (This)->lpVtbl->StopScriptTracing(This)
#endif
#endif

  HRESULT WINAPI IActiveScriptTraceInfo_StartScriptTracing_Proxy(IActiveScriptTraceInfo *This,IActiveScriptSiteTraceInfo *pSiteTraceInfo,GUID guidContextID);
  void __RPC_STUB IActiveScriptTraceInfo_StartScriptTracing_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI IActiveScriptTraceInfo_StopScriptTracing_Proxy(IActiveScriptTraceInfo *This);
  void __RPC_STUB IActiveScriptTraceInfo_StopScriptTracing_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_activscp_0286_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_activscp_0286_v0_0_s_ifspec;

  ULONG __RPC_API BSTR_UserSize(ULONG *,ULONG,BSTR *);
  unsigned char *__RPC_API BSTR_UserMarshal(ULONG *,unsigned char *,BSTR *);
  unsigned char *__RPC_API BSTR_UserUnmarshal(ULONG *,unsigned char *,BSTR *);
  void __RPC_API BSTR_UserFree(ULONG *,BSTR *);
  ULONG __RPC_API HWND_UserSize(ULONG *,ULONG,HWND *);
  unsigned char *__RPC_API HWND_UserMarshal(ULONG *,unsigned char *,HWND *);
  unsigned char *__RPC_API HWND_UserUnmarshal(ULONG *,unsigned char *,HWND *);
  void __RPC_API HWND_UserFree(ULONG *,HWND *);
  ULONG __RPC_API VARIANT_UserSize(ULONG *,ULONG,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserMarshal(ULONG *,unsigned char *,VARIANT *);
  unsigned char *__RPC_API VARIANT_UserUnmarshal(ULONG *,unsigned char *,VARIANT *);
  void __RPC_API VARIANT_UserFree(ULONG *,VARIANT *);

  HRESULT WINAPI IActiveScriptError_GetExceptionInfo_Proxy(IActiveScriptError *This,EXCEPINFO *pexcepinfo);
  HRESULT WINAPI IActiveScriptError_GetExceptionInfo_Stub(IActiveScriptError *This,EXCEPINFO *pexcepinfo);

#ifdef __cplusplus
}
#endif
#endif
