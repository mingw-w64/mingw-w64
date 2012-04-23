/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FSRM
#define _INC_FSRM
#if (_WIN32_WINNT >= 0x0600)
#include <fsrmenums.h>

#ifndef __IFsrmAction_FWD_DEFINED__
#define __IFsrmAction_FWD_DEFINED__
typedef struct IFsrmAction IFsrmAction;
#endif /* __IFsrmAction_FWD_DEFINED__ */

#ifndef __IFsrmActionCommand_FWD_DEFINED__
#define __IFsrmActionCommand_FWD_DEFINED__
typedef struct IFsrmActionCommand IFsrmActionCommand;
#endif /* __IFsrmActionCommand_FWD_DEFINED__ */

#ifndef __IFsrmActionEmail_FWD_DEFINED__
#define __IFsrmActionEmail_FWD_DEFINED__
typedef struct IFsrmActionEmail IFsrmActionEmail;
#endif /* __IFsrmActionEmail_FWD_DEFINED__ */

#ifndef __IFsrmActionEmail2_FWD_DEFINED__
#define __IFsrmActionEmail2_FWD_DEFINED__
typedef struct IFsrmActionEmail2 IFsrmActionEmail2;
#endif /* __IFsrmActionEmail2_FWD_DEFINED__ */

#ifndef __IFsrmActionEventLog_FWD_DEFINED__
#define __IFsrmActionEventLog_FWD_DEFINED__
typedef struct IFsrmActionEventLog IFsrmActionEventLog;
#endif /* __IFsrmActionEventLog_FWD_DEFINED__ */

#ifndef __IFsrmActionReport_FWD_DEFINED__
#define __IFsrmActionReport_FWD_DEFINED__
typedef struct IFsrmActionReport IFsrmActionReport;
#endif /* __IFsrmActionReport_FWD_DEFINED__ */

#ifndef __IFsrmAutoApplyQuota_FWD_DEFINED__
#define __IFsrmAutoApplyQuota_FWD_DEFINED__
typedef struct IFsrmAutoApplyQuota IFsrmAutoApplyQuota;
#endif /* __IFsrmAutoApplyQuota_FWD_DEFINED__ */

#ifndef __IFsrmClassificationManager_FWD_DEFINED__
#define __IFsrmClassificationManager_FWD_DEFINED__
typedef struct IFsrmClassificationManager IFsrmClassificationManager;
#endif /* __IFsrmClassificationManager_FWD_DEFINED__ */

#ifndef __IFsrmClassificationRule_FWD_DEFINED__
#define __IFsrmClassificationRule_FWD_DEFINED__
typedef struct IFsrmClassificationRule IFsrmClassificationRule;
#endif /* __IFsrmClassificationRule_FWD_DEFINED__ */

#ifndef __IFsrmClassifierModuleDefinition_FWD_DEFINED__
#define __IFsrmClassifierModuleDefinition_FWD_DEFINED__
typedef struct IFsrmClassifierModuleDefinition IFsrmClassifierModuleDefinition;
#endif /* __IFsrmClassifierModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmClassifierModuleImplementation_FWD_DEFINED__
#define __IFsrmClassifierModuleImplementation_FWD_DEFINED__
typedef struct IFsrmClassifierModuleImplementation IFsrmClassifierModuleImplementation;
#endif /* __IFsrmClassifierModuleImplementation_FWD_DEFINED__ */

#ifndef __IFsrmCollection_FWD_DEFINED__
#define __IFsrmCollection_FWD_DEFINED__
typedef struct IFsrmCollection IFsrmCollection;
#endif /* __IFsrmCollection_FWD_DEFINED__ */

#ifndef __IFsrmCommittableCollection_FWD_DEFINED__
#define __IFsrmCommittableCollection_FWD_DEFINED__
typedef struct IFsrmCommittableCollection IFsrmCommittableCollection;
#endif /* __IFsrmCommittableCollection_FWD_DEFINED__ */

#ifndef __IFsrmDerivedObjectsResult_FWD_DEFINED__
#define __IFsrmDerivedObjectsResult_FWD_DEFINED__
typedef struct IFsrmDerivedObjectsResult IFsrmDerivedObjectsResult;
#endif /* __IFsrmDerivedObjectsResult_FWD_DEFINED__ */

#ifndef __IFsrmExportImport_FWD_DEFINED__
#define __IFsrmExportImport_FWD_DEFINED__
typedef struct IFsrmExportImport IFsrmExportImport;
#endif /* __IFsrmExportImport_FWD_DEFINED__ */

#ifndef __IFsrmFileGroup_FWD_DEFINED__
#define __IFsrmFileGroup_FWD_DEFINED__
typedef struct IFsrmFileGroup IFsrmFileGroup;
#endif /* __IFsrmFileGroup_FWD_DEFINED__ */

#ifndef __IFsrmFileGroupImported_FWD_DEFINED__
#define __IFsrmFileGroupImported_FWD_DEFINED__
typedef struct IFsrmFileGroupImported IFsrmFileGroupImported;
#endif /* __IFsrmFileGroupImported_FWD_DEFINED__ */

#ifndef __IFsrmFileGroupManager_FWD_DEFINED__
#define __IFsrmFileGroupManager_FWD_DEFINED__
typedef struct IFsrmFileGroupManager IFsrmFileGroupManager;
#endif /* __IFsrmFileGroupManager_FWD_DEFINED__ */

#ifndef __IFsrmFileManagementJob_FWD_DEFINED__
#define __IFsrmFileManagementJob_FWD_DEFINED__
typedef struct IFsrmFileManagementJob IFsrmFileManagementJob;
#endif /* __IFsrmFileManagementJob_FWD_DEFINED__ */

#ifndef __IFsrmFileManagementJobManager_FWD_DEFINED__
#define __IFsrmFileManagementJobManager_FWD_DEFINED__
typedef struct IFsrmFileManagementJobManager IFsrmFileManagementJobManager;
#endif /* __IFsrmFileManagementJobManager_FWD_DEFINED__ */

#ifndef __IFsrmFileScreen_FWD_DEFINED__
#define __IFsrmFileScreen_FWD_DEFINED__
typedef struct IFsrmFileScreen IFsrmFileScreen;
#endif /* __IFsrmFileScreen_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenBase_FWD_DEFINED__
#define __IFsrmFileScreenBase_FWD_DEFINED__
typedef struct IFsrmFileScreenBase IFsrmFileScreenBase;
#endif /* __IFsrmFileScreenBase_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenException_FWD_DEFINED__
#define __IFsrmFileScreenException_FWD_DEFINED__
typedef struct IFsrmFileScreenException IFsrmFileScreenException;
#endif /* __IFsrmFileScreenException_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenManager_FWD_DEFINED__
#define __IFsrmFileScreenManager_FWD_DEFINED__
typedef struct IFsrmFileScreenManager IFsrmFileScreenManager;
#endif /* __IFsrmFileScreenManager_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplate_FWD_DEFINED__
#define __IFsrmFileScreenTemplate_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplate IFsrmFileScreenTemplate;
#endif /* __IFsrmFileScreenTemplate_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplateImported_FWD_DEFINED__
#define __IFsrmFileScreenTemplateImported_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplateImported IFsrmFileScreenTemplateImported;
#endif /* __IFsrmFileScreenTemplateImported_FWD_DEFINED__ */

#ifndef __IFsrmFileScreenTemplateManager_FWD_DEFINED__
#define __IFsrmFileScreenTemplateManager_FWD_DEFINED__
typedef struct IFsrmFileScreenTemplateManager IFsrmFileScreenTemplateManager;
#endif /* __IFsrmFileScreenTemplateManager_FWD_DEFINED__ */

#ifndef __IFsrmMutableCollection_FWD_DEFINED__
#define __IFsrmMutableCollection_FWD_DEFINED__
typedef struct IFsrmMutableCollection IFsrmMutableCollection;
#endif /* __IFsrmMutableCollection_FWD_DEFINED__ */

#ifndef __IFsrmObject_FWD_DEFINED__
#define __IFsrmObject_FWD_DEFINED__
typedef struct IFsrmObject IFsrmObject;
#endif /* __IFsrmObject_FWD_DEFINED__ */

#ifndef __IFsrmPathMapper_FWD_DEFINED__
#define __IFsrmPathMapper_FWD_DEFINED__
typedef struct IFsrmPathMapper IFsrmPathMapper;
#endif /* __IFsrmPathMapper_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleConnector_FWD_DEFINED__
#define __IFsrmPipelineModuleConnector_FWD_DEFINED__
typedef struct IFsrmPipelineModuleConnector IFsrmPipelineModuleConnector;
#endif /* __IFsrmPipelineModuleConnector_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleDefinition_FWD_DEFINED__
#define __IFsrmPipelineModuleDefinition_FWD_DEFINED__
typedef struct IFsrmPipelineModuleDefinition IFsrmPipelineModuleDefinition;
#endif /* __IFsrmPipelineModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmPipelineModuleImplementation_FWD_DEFINED__
#define __IFsrmPipelineModuleImplementation_FWD_DEFINED__
typedef struct IFsrmPipelineModuleImplementation IFsrmPipelineModuleImplementation;
#endif /* __IFsrmPipelineModuleImplementation_FWD_DEFINED__ */

#ifndef __IFsrmProperty_FWD_DEFINED__
#define __IFsrmProperty_FWD_DEFINED__
typedef struct IFsrmProperty IFsrmProperty;
#endif /* __IFsrmProperty_FWD_DEFINED__ */

#ifndef __IFsrmPropertyBag_FWD_DEFINED__
#define __IFsrmPropertyBag_FWD_DEFINED__
typedef struct IFsrmPropertyBag IFsrmPropertyBag;
#endif /* __IFsrmPropertyBag_FWD_DEFINED__ */

#ifndef __IFsrmPropertyCondition_FWD_DEFINED__
#define __IFsrmPropertyCondition_FWD_DEFINED__
typedef struct IFsrmPropertyCondition IFsrmPropertyCondition;
#endif /* __IFsrmPropertyCondition_FWD_DEFINED__ */

#ifndef __IFsrmPropertyDefinition_FWD_DEFINED__
#define __IFsrmPropertyDefinition_FWD_DEFINED__
typedef struct IFsrmPropertyDefinition IFsrmPropertyDefinition;
#endif /* __IFsrmPropertyDefinition_FWD_DEFINED__ */

#ifndef __IFsrmQuota_FWD_DEFINED__
#define __IFsrmQuota_FWD_DEFINED__
typedef struct IFsrmQuota IFsrmQuota;
#endif /* __IFsrmQuota_FWD_DEFINED__ */

#ifndef __IFsrmQuotaBase_FWD_DEFINED__
#define __IFsrmQuotaBase_FWD_DEFINED__
typedef struct IFsrmQuotaBase IFsrmQuotaBase;
#endif /* __IFsrmQuotaBase_FWD_DEFINED__ */

#ifndef __IFsrmQuotaManager_FWD_DEFINED__
#define __IFsrmQuotaManager_FWD_DEFINED__
typedef struct IFsrmQuotaManager IFsrmQuotaManager;
#endif /* __IFsrmQuotaManager_FWD_DEFINED__ */

#ifndef __IFsrmQuotaManagerEx_FWD_DEFINED__
#define __IFsrmQuotaManagerEx_FWD_DEFINED__
typedef struct IFsrmQuotaManagerEx IFsrmQuotaManagerEx;
#endif /* __IFsrmQuotaManagerEx_FWD_DEFINED__ */

#ifndef __IFsrmQuotaObject_FWD_DEFINED__
#define __IFsrmQuotaObject_FWD_DEFINED__
typedef struct IFsrmQuotaObject IFsrmQuotaObject;
#endif /* __IFsrmQuotaObject_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplate_FWD_DEFINED__
#define __IFsrmQuotaTemplate_FWD_DEFINED__
typedef struct IFsrmQuotaTemplate IFsrmQuotaTemplate;
#endif /* __IFsrmQuotaTemplate_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplateImported_FWD_DEFINED__
#define __IFsrmQuotaTemplateImported_FWD_DEFINED__
typedef struct IFsrmQuotaTemplateImported IFsrmQuotaTemplateImported;
#endif /* __IFsrmQuotaTemplateImported_FWD_DEFINED__ */

#ifndef __IFsrmQuotaTemplateManager_FWD_DEFINED__
#define __IFsrmQuotaTemplateManager_FWD_DEFINED__
typedef struct IFsrmQuotaTemplateManager IFsrmQuotaTemplateManager;
#endif /* __IFsrmQuotaTemplateManager_FWD_DEFINED__ */

#ifndef __IFsrmReport_FWD_DEFINED__
#define __IFsrmReport_FWD_DEFINED__
typedef struct IFsrmReport IFsrmReport;
#endif /* __IFsrmReport_FWD_DEFINED__ */

#ifndef __IFsrmReportJob_FWD_DEFINED__
#define __IFsrmReportJob_FWD_DEFINED__
typedef struct IFsrmReportJob IFsrmReportJob;
#endif /* __IFsrmReportJob_FWD_DEFINED__ */

#ifndef __IFsrmReportManager_FWD_DEFINED__
#define __IFsrmReportManager_FWD_DEFINED__
typedef struct IFsrmReportManager IFsrmReportManager;
#endif /* __IFsrmReportManager_FWD_DEFINED__ */

#ifndef __IFsrmReportScheduler_FWD_DEFINED__
#define __IFsrmReportScheduler_FWD_DEFINED__
typedef struct IFsrmReportScheduler IFsrmReportScheduler;
#endif /* __IFsrmReportScheduler_FWD_DEFINED__ */

#ifndef __IFsrmRule_FWD_DEFINED__
#define __IFsrmRule_FWD_DEFINED__
typedef struct IFsrmRule IFsrmRule;
#endif /* __IFsrmRule_FWD_DEFINED__ */

#ifndef __IFsrmSetting_FWD_DEFINED__
#define __IFsrmSetting_FWD_DEFINED__
typedef struct IFsrmSetting IFsrmSetting;
#endif /* __IFsrmSetting_FWD_DEFINED__ */

#ifndef __IFsrmStorageModuleDefinition_FWD_DEFINED__
#define __IFsrmStorageModuleDefinition_FWD_DEFINED__
typedef struct IFsrmStorageModuleDefinition IFsrmStorageModuleDefinition;
#endif /* __IFsrmStorageModuleDefinition_FWD_DEFINED__ */

#ifndef __IFsrmStorageModuleImplementation_FWD_DEFINED__
#define __IFsrmStorageModuleImplementation_FWD_DEFINED__
typedef struct IFsrmStorageModuleImplementation IFsrmStorageModuleImplementation;
#endif /* __IFsrmStorageModuleImplementation_FWD_DEFINED__ */

#ifdef __cplusplus
extern "C" {
#endif

#define FsrmNeverModified  0x0000000000000000
#define FsrmAlwaysModified 0xFFFFFFFFFFFFFFFF

typedef GUID FSRM_OBJECT_ID;
typedef long FSRM_QUOTA_THRESHOLD;

typedef enum _FsrmGetFilePropertyOptions {
  FsrmGetFilePropertyOptions_None               = 0x00000000,
  FsrmGetFilePropertyOptions_NoRuleEvaluation   = 0x00000001 
} FsrmGetFilePropertyOptions;

#ifdef __cplusplus
}
#endif

#undef  INTERFACE
#define INTERFACE IFsrmAction
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmAction,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmAction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmAction_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmAction_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmAction_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmAction_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmAction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmAction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmAction_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmAction_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmAction_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmAction_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmAction_Delete() (This)->lpVtbl->Delete(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmActionCommand
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmActionCommand,IFsrmAction)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    /* IFsrmActionCommand methods */
    STDMETHOD_(HRESULT,get_ExecutablePath)(THIS_ BSTR *executablePath) PURE;
    STDMETHOD_(HRESULT,put_ExecutablePath)(THIS_ BSTR executablePath) PURE;
    STDMETHOD_(HRESULT,get_Arguments)(THIS_ BSTR *arguments) PURE;
    STDMETHOD_(HRESULT,put_Arguments)(THIS_ BSTR arguments) PURE;
    STDMETHOD_(HRESULT,get_Account)(THIS_ FsrmAccountType *account) PURE;
    STDMETHOD_(HRESULT,put_Account)(THIS_ FsrmAccountType account) PURE;
    STDMETHOD_(HRESULT,get_WorkingDirectory)(THIS_ BSTR *workingDirectory) PURE;
    STDMETHOD_(HRESULT,put_WorkingDirectory)(THIS_ BSTR workingDirectory) PURE;
    STDMETHOD_(HRESULT,get_MonitorCommand)(THIS_ VARIANT_BOOL *monitorCommand) PURE;
    STDMETHOD_(HRESULT,put_MonitorCommand)(THIS_ VARIANT_BOOL monitorCommand) PURE;
    STDMETHOD_(HRESULT,get_KillTimeOut)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,put_KillTimeOut)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_LogResult)(THIS_ VARIANT_BOOL *logResults) PURE;
    STDMETHOD_(HRESULT,put_LogResult)(THIS_ VARIANT_BOOL logResults) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmActionCommand_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmActionCommand_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmActionCommand_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmActionCommand_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmActionCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmActionCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmActionCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmActionCommand_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmActionCommand_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmActionCommand_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmActionCommand_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmActionCommand_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmActionCommand_get_ExecutablePath(This,executablePath) (This)->lpVtbl->get_ExecutablePath(This,executablePath)
#define IFsrmActionCommand_put_ExecutablePath(This,executablePath) (This)->lpVtbl->put_ExecutablePath(This,executablePath)
#define IFsrmActionCommand_get_Arguments(This,arguments) (This)->lpVtbl->get_Arguments(This,arguments)
#define IFsrmActionCommand_put_Arguments(This,arguments) (This)->lpVtbl->put_Arguments(This,arguments)
#define IFsrmActionCommand_get_Account(This,account) (This)->lpVtbl->get_Account(This,account)
#define IFsrmActionCommand_put_Account(This,account) (This)->lpVtbl->put_Account(This,account)
#define IFsrmActionCommand_get_WorkingDirectory(This,workingDirectory) (This)->lpVtbl->get_WorkingDirectory(This,workingDirectory)
#define IFsrmActionCommand_put_WorkingDirectory(This,workingDirectory) (This)->lpVtbl->put_WorkingDirectory(This,workingDirectory)
#define IFsrmActionCommand_get_MonitorCommand(This,monitorCommand) (This)->lpVtbl->get_MonitorCommand(This,monitorCommand)
#define IFsrmActionCommand_put_MonitorCommand(This,monitorCommand) (This)->lpVtbl->put_MonitorCommand(This,monitorCommand)
#define IFsrmActionCommand_get_KillTimeOut(This,minutes) (This)->lpVtbl->get_KillTimeOut(This,minutes)
#define IFsrmActionCommand_put_KillTimeOut(This,minutes) (This)->lpVtbl->put_KillTimeOut(This,minutes)
#define IFsrmActionCommand_get_LogResult(This,logResults) (This)->lpVtbl->get_LogResult(This,logResults)
#define IFsrmActionCommand_put_LogResult(This,logResults) (This)->lpVtbl->put_LogResult(This,logResults)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmActionEmail
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmActionEmail,IFsrmAction)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    /* IFsrmActionEmail methods */
    STDMETHOD_(HRESULT,get_MailFrom)(THIS_ BSTR *mailFrom) PURE;
    STDMETHOD_(HRESULT,put_MailFrom)(THIS_ BSTR mailFrom) PURE;
    STDMETHOD_(HRESULT,get_MailReplyTo)(THIS_ BSTR *mailReplyTo) PURE;
    STDMETHOD_(HRESULT,put_MailReplyTo)(THIS_ BSTR mailReplyTo) PURE;
    STDMETHOD_(HRESULT,get_MailTo)(THIS_ BSTR *mailTo) PURE;
    STDMETHOD_(HRESULT,put_MailTo)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,get_MailCc)(THIS_ BSTR *mailCc) PURE;
    STDMETHOD_(HRESULT,put_MailCc)(THIS_ BSTR mailCc) PURE;
    STDMETHOD_(HRESULT,get_MailBcc)(THIS_ BSTR *mailBcc) PURE;
    STDMETHOD_(HRESULT,put_MailBcc)(THIS_ BSTR mailBcc) PURE;
    STDMETHOD_(HRESULT,get_MailSubject)(THIS_ BSTR *mailSubject) PURE;
    STDMETHOD_(HRESULT,put_MailSubject)(THIS_ BSTR mailSubject) PURE;
    STDMETHOD_(HRESULT,get_MessageText)(THIS_ BSTR *messageText) PURE;
    STDMETHOD_(HRESULT,put_MessageText)(THIS_ BSTR messageText) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmActionEmail_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmActionEmail_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmActionEmail_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmActionEmail_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmActionEmail_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmActionEmail_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmActionEmail_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmActionEmail_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmActionEmail_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmActionEmail_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmActionEmail_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmActionEmail_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmActionEmail_get_MailFrom(This,mailFrom) (This)->lpVtbl->get_MailFrom(This,mailFrom)
#define IFsrmActionEmail_put_MailFrom(This,mailFrom) (This)->lpVtbl->put_MailFrom(This,mailFrom)
#define IFsrmActionEmail_get_MailReplyTo(This,mailReplyTo) (This)->lpVtbl->get_MailReplyTo(This,mailReplyTo)
#define IFsrmActionEmail_put_MailReplyTo(This,mailReplyTo) (This)->lpVtbl->put_MailReplyTo(This,mailReplyTo)
#define IFsrmActionEmail_get_MailTo(This,mailTo) (This)->lpVtbl->get_MailTo(This,mailTo)
#define IFsrmActionEmail_put_MailTo(This,mailTo) (This)->lpVtbl->put_MailTo(This,mailTo)
#define IFsrmActionEmail_get_MailCc(This,mailCc) (This)->lpVtbl->get_MailCc(This,mailCc)
#define IFsrmActionEmail_put_MailCc(This,mailCc) (This)->lpVtbl->put_MailCc(This,mailCc)
#define IFsrmActionEmail_get_MailBcc(This,mailBcc) (This)->lpVtbl->get_MailBcc(This,mailBcc)
#define IFsrmActionEmail_put_MailBcc(This,mailBcc) (This)->lpVtbl->put_MailBcc(This,mailBcc)
#define IFsrmActionEmail_get_MailSubject(This,mailSubject) (This)->lpVtbl->get_MailSubject(This,mailSubject)
#define IFsrmActionEmail_put_MailSubject(This,mailSubject) (This)->lpVtbl->put_MailSubject(This,mailSubject)
#define IFsrmActionEmail_get_MessageText(This,messageText) (This)->lpVtbl->get_MessageText(This,messageText)
#define IFsrmActionEmail_put_MessageText(This,messageText) (This)->lpVtbl->put_MessageText(This,messageText)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmActionEmail2
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmActionEmail2,IFsrmActionEmail)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    /* IFsrmActionEmail methods */
    STDMETHOD_(HRESULT,get_MailFrom)(THIS_ BSTR *mailFrom) PURE;
    STDMETHOD_(HRESULT,put_MailFrom)(THIS_ BSTR mailFrom) PURE;
    STDMETHOD_(HRESULT,get_MailReplyTo)(THIS_ BSTR *mailReplyTo) PURE;
    STDMETHOD_(HRESULT,put_MailReplyTo)(THIS_ BSTR mailReplyTo) PURE;
    STDMETHOD_(HRESULT,get_MailTo)(THIS_ BSTR *mailTo) PURE;
    STDMETHOD_(HRESULT,put_MailTo)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,get_MailCc)(THIS_ BSTR *mailCc) PURE;
    STDMETHOD_(HRESULT,put_MailCc)(THIS_ BSTR mailCc) PURE;
    STDMETHOD_(HRESULT,get_MailBcc)(THIS_ BSTR *mailBcc) PURE;
    STDMETHOD_(HRESULT,put_MailBcc)(THIS_ BSTR mailBcc) PURE;
    STDMETHOD_(HRESULT,get_MailSubject)(THIS_ BSTR *mailSubject) PURE;
    STDMETHOD_(HRESULT,put_MailSubject)(THIS_ BSTR mailSubject) PURE;
    STDMETHOD_(HRESULT,get_MessageText)(THIS_ BSTR *messageText) PURE;
    STDMETHOD_(HRESULT,put_MessageText)(THIS_ BSTR messageText) PURE;

    /* IFsrmActionEmail2 methods */
    STDMETHOD_(HRESULT,get_AttachmentFileListSize)(THIS_ long *pAttachmentFileListSize) PURE;
    STDMETHOD_(HRESULT,put_AttachmentFileListSize)(THIS_ long attachmentFileListSize) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmActionEmail2_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmActionEmail2_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmActionEmail2_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmActionEmail2_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmActionEmail2_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmActionEmail2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmActionEmail2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmActionEmail2_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmActionEmail2_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmActionEmail2_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmActionEmail2_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmActionEmail2_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmActionEmail2_get_MailFrom(This,mailFrom) (This)->lpVtbl->get_MailFrom(This,mailFrom)
#define IFsrmActionEmail2_put_MailFrom(This,mailFrom) (This)->lpVtbl->put_MailFrom(This,mailFrom)
#define IFsrmActionEmail2_get_MailReplyTo(This,mailReplyTo) (This)->lpVtbl->get_MailReplyTo(This,mailReplyTo)
#define IFsrmActionEmail2_put_MailReplyTo(This,mailReplyTo) (This)->lpVtbl->put_MailReplyTo(This,mailReplyTo)
#define IFsrmActionEmail2_get_MailTo(This,mailTo) (This)->lpVtbl->get_MailTo(This,mailTo)
#define IFsrmActionEmail2_put_MailTo(This,mailTo) (This)->lpVtbl->put_MailTo(This,mailTo)
#define IFsrmActionEmail2_get_MailCc(This,mailCc) (This)->lpVtbl->get_MailCc(This,mailCc)
#define IFsrmActionEmail2_put_MailCc(This,mailCc) (This)->lpVtbl->put_MailCc(This,mailCc)
#define IFsrmActionEmail2_get_MailBcc(This,mailBcc) (This)->lpVtbl->get_MailBcc(This,mailBcc)
#define IFsrmActionEmail2_put_MailBcc(This,mailBcc) (This)->lpVtbl->put_MailBcc(This,mailBcc)
#define IFsrmActionEmail2_get_MailSubject(This,mailSubject) (This)->lpVtbl->get_MailSubject(This,mailSubject)
#define IFsrmActionEmail2_put_MailSubject(This,mailSubject) (This)->lpVtbl->put_MailSubject(This,mailSubject)
#define IFsrmActionEmail2_get_MessageText(This,messageText) (This)->lpVtbl->get_MessageText(This,messageText)
#define IFsrmActionEmail2_put_MessageText(This,messageText) (This)->lpVtbl->put_MessageText(This,messageText)
#define IFsrmActionEmail2_get_AttachmentFileListSize(This,pAttachmentFileListSize) (This)->lpVtbl->get_AttachmentFileListSize(This,pAttachmentFileListSize)
#define IFsrmActionEmail2_put_AttachmentFileListSize(This,attachmentFileListSize) (This)->lpVtbl->put_AttachmentFileListSize(This,attachmentFileListSize)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmActionEventLog
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmActionEventLog,IFsrmAction)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    /* IFsrmActionEventLog methods */
    STDMETHOD_(HRESULT,get_EventType)(THIS_ FsrmEventType *eventType) PURE;
    STDMETHOD_(HRESULT,put_EventType)(THIS_ FsrmEventType eventType) PURE;
    STDMETHOD_(HRESULT,get_MessageText)(THIS_ BSTR *messageText) PURE;
    STDMETHOD_(HRESULT,put_MessageText)(THIS_ BSTR messageText) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmActionEventLog_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmActionEventLog_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmActionEventLog_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmActionEventLog_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmActionEventLog_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmActionEventLog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmActionEventLog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmActionEventLog_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmActionEventLog_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmActionEventLog_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmActionEventLog_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmActionEventLog_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmActionEventLog_get_EventType(This,eventType) (This)->lpVtbl->get_EventType(This,eventType)
#define IFsrmActionEventLog_put_EventType(This,eventType) (This)->lpVtbl->put_EventType(This,eventType)
#define IFsrmActionEventLog_get_MessageText(This,messageText) (This)->lpVtbl->get_MessageText(This,messageText)
#define IFsrmActionEventLog_put_MessageText(This,messageText) (This)->lpVtbl->put_MessageText(This,messageText)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmActionReport
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmActionReport,IFsrmAction)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmAction methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_ActionType)(THIS_ FsrmActionType *actionType) PURE;
    STDMETHOD_(HRESULT,put_RunLimitInterval)(THIS_ long minutes) PURE;
    STDMETHOD_(HRESULT,get_RunLimitInterval)(THIS_ long *minutes) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    /* IFsrmActionReport methods */
    STDMETHOD_(HRESULT,get_ReportTypes)(THIS_ SAFEARRAY **reportTypes) PURE;
    STDMETHOD_(HRESULT,put_ReportTypes)(THIS_ SAFEARRAY *reportTypes) PURE;
    STDMETHOD_(HRESULT,get_MailTo)(THIS_ BSTR *mailTo) PURE;
    STDMETHOD_(HRESULT,put_MailTo)(THIS_ BSTR mailTo) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmActionReport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmActionReport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmActionReport_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmActionReport_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmActionReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmActionReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmActionReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmActionReport_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmActionReport_get_ActionType(This,actionType) (This)->lpVtbl->get_ActionType(This,actionType)
#define IFsrmActionReport_put_RunLimitInterval(This,minutes) (This)->lpVtbl->put_RunLimitInterval(This,minutes)
#define IFsrmActionReport_get_RunLimitInterval(This,minutes) (This)->lpVtbl->get_RunLimitInterval(This,minutes)
#define IFsrmActionReport_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmActionReport_get_ReportTypes(This,reportTypes) (This)->lpVtbl->get_ReportTypes(This,reportTypes)
#define IFsrmActionReport_put_ReportTypes(This,reportTypes) (This)->lpVtbl->put_ReportTypes(This,reportTypes)
#define IFsrmActionReport_get_MailTo(This,mailTo) (This)->lpVtbl->get_MailTo(This,mailTo)
#define IFsrmActionReport_put_MailTo(This,mailTo) (This)->lpVtbl->put_MailTo(This,mailTo)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmCollection
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmCollection,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmCollection methods */
    STDMETHOD_(HRESULT,get__NewEnum)(THIS_ IUnknown **unknown) PURE;
    STDMETHOD_(HRESULT,get_Item)(THIS_ long index,VARIANT *item) PURE;
    STDMETHOD_(HRESULT,get_Count)(THIS_ long *count) PURE;
    STDMETHOD_(HRESULT,get_State)(THIS_ FsrmCollectionState *state) PURE;
    STDMETHOD_(HRESULT,Cancel)(THIS) PURE;
    STDMETHOD_(HRESULT,GetById)(THIS_ FSRM_OBJECT_ID id,VARIANT *entry) PURE;
    STDMETHOD_(HRESULT,WaitForCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmCollection_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmCollection_get__NewEnum(This,unknown) (This)->lpVtbl->get__NewEnum(This,unknown)
#define IFsrmCollection_get_Item(This,index,item) (This)->lpVtbl->get_Item(This,index,item)
#define IFsrmCollection_get_Count(This,count) (This)->lpVtbl->get_Count(This,count)
#define IFsrmCollection_get_State(This,state) (This)->lpVtbl->get_State(This,state)
#define IFsrmCollection_Cancel() (This)->lpVtbl->Cancel(This)
#define IFsrmCollection_GetById(This,id,entry) (This)->lpVtbl->GetById(This,id,entry)
#define IFsrmCollection_WaitForCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForCompletion(This,waitSeconds,completed)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmDerivedObjectsResult
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmDerivedObjectsResult,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmDerivedObjectsResult methods */
    STDMETHOD_(HRESULT,get_DerivedObjects)(THIS_ IFsrmCollection **derivedObjects) PURE;
    STDMETHOD_(HRESULT,get_Results)(THIS_ IFsrmCollection **results) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmDerivedObjectsResult_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmDerivedObjectsResult_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmDerivedObjectsResult_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmDerivedObjectsResult_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmDerivedObjectsResult_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmDerivedObjectsResult_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmDerivedObjectsResult_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmDerivedObjectsResult_get_DerivedObjects(This,derivedObjects) (This)->lpVtbl->get_DerivedObjects(This,derivedObjects)
#define IFsrmDerivedObjectsResult_get_Results(This,results) (This)->lpVtbl->get_Results(This,results)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmObject
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmObject,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmObject_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmObject_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmObject_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmObject_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmObject_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmObject_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmObject_Commit() (This)->lpVtbl->Commit(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmMutableCollection
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmMutableCollection,IFsrmCollection)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmCollection methods */
    STDMETHOD_(HRESULT,get__NewEnum)(THIS_ IUnknown **unknown) PURE;
    STDMETHOD_(HRESULT,get_Item)(THIS_ long index,VARIANT *item) PURE;
    STDMETHOD_(HRESULT,get_Count)(THIS_ long *count) PURE;
    STDMETHOD_(HRESULT,get_State)(THIS_ FsrmCollectionState *state) PURE;
    STDMETHOD_(HRESULT,Cancel)(THIS) PURE;
    STDMETHOD_(HRESULT,GetById)(THIS_ FSRM_OBJECT_ID id,VARIANT *entry) PURE;
    STDMETHOD_(HRESULT,WaitForCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;

    /* IFsrmMutableCollection methods */
    STDMETHOD_(HRESULT,Add)(THIS_ VARIANT item) PURE;
    STDMETHOD_(HRESULT,Remove)(THIS_ long index) PURE;
    STDMETHOD_(HRESULT,RemoveById)(THIS_ FSRM_OBJECT_ID id) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IFsrmMutableCollection **collection) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmMutableCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmMutableCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmMutableCollection_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmMutableCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmMutableCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmMutableCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmMutableCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IIFsrmMutableCollection_get__NewEnum(This,unknown) (This)->lpVtbl->get__NewEnum(This,unknown)
#define IFsrmMutableCollection_get_Item(This,index,item) (This)->lpVtbl->get_Item(This,index,item)
#define IFsrmMutableCollection_get_Count(This,count) (This)->lpVtbl->get_Count(This,count)
#define IFsrmMutableCollection_get_State(This,state) (This)->lpVtbl->get_State(This,state)
#define IFsrmMutableCollection_Cancel() (This)->lpVtbl->Cancel(This)
#define IFsrmMutableCollection_GetById(This,id,entry) (This)->lpVtbl->GetById(This,id,entry)
#define IFsrmMutableCollection_WaitForCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForCompletion(This,waitSeconds,completed)
#define IFsrmMutableCollection_Add(This,item) (This)->lpVtbl->Add(This,item)
#define IFsrmMutableCollection_Remove(This,index) (This)->lpVtbl->Remove(This,index)
#define IFsrmMutableCollection_RemoveById(This,id) (This)->lpVtbl->RemoveById(This,id)
#define IFsrmMutableCollection_Clone(This,collection) (This)->lpVtbl->Clone(This,collection)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmCommittableCollection
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmCommittableCollection,IFsrmMutableCollection)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmCollection methods */
    STDMETHOD_(HRESULT,get__NewEnum)(THIS_ IUnknown **unknown) PURE;
    STDMETHOD_(HRESULT,get_Item)(THIS_ long index,VARIANT *item) PURE;
    STDMETHOD_(HRESULT,get_Count)(THIS_ long *count) PURE;
    STDMETHOD_(HRESULT,get_State)(THIS_ FsrmCollectionState *state) PURE;
    STDMETHOD_(HRESULT,Cancel)(THIS) PURE;
    STDMETHOD_(HRESULT,GetById)(THIS_ FSRM_OBJECT_ID id,VARIANT *entry) PURE;
    STDMETHOD_(HRESULT,WaitForCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;

    /* IFsrmMutableCollection methods */
    STDMETHOD_(HRESULT,Add)(THIS_ VARIANT item) PURE;
    STDMETHOD_(HRESULT,Remove)(THIS_ long index) PURE;
    STDMETHOD_(HRESULT,RemoveById)(THIS_ FSRM_OBJECT_ID id) PURE;
    STDMETHOD_(HRESULT,Clone)(THIS_ IFsrmMutableCollection **collection) PURE;

    /* IFsrmCommittableCollection methods */
    STDMETHOD_(HRESULT,Commit)(THIS_ FsrmCommitOptions options,IFsrmCollection** results) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmCommittableCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmCommittableCollection_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmCommittableCollection_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmCommittableCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmCommittableCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmCommittableCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmCommittableCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmCommittableCollection_get__NewEnum(This,unknown) (This)->lpVtbl->get__NewEnum(This,unknown)
#define IFsrmCommittableCollection_get_Item(This,index,item) (This)->lpVtbl->get_Item(This,index,item)
#define IFsrmCommittableCollection_get_Count(This,count) (This)->lpVtbl->get_Count(This,count)
#define IFsrmCommittableCollection_get_State(This,state) (This)->lpVtbl->get_State(This,state)
#define IFsrmCommittableCollection_Cancel() (This)->lpVtbl->Cancel(This)
#define IFsrmCommittableCollection_GetById(This,id,entry) (This)->lpVtbl->GetById(This,id,entry)
#define IFsrmCommittableCollection_WaitForCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForCompletion(This,waitSeconds,completed)
#define IFsrmCommittableCollection_Add(This,item) (This)->lpVtbl->Add(This,item)
#define IFsrmCommittableCollection_Remove(This,index) (This)->lpVtbl->Remove(This,index)
#define IFsrmCommittableCollection_RemoveById(This,id) (This)->lpVtbl->RemoveById(This,id)
#define IFsrmCommittableCollection_Clone(This,collection) (This)->lpVtbl->Clone(This,collection)
#define IFsrmCommittableCollection_Commit(This,options,results) (This)->lpVtbl->Commit(This,options,results)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmExportImport
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmExportImport,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmExportImport methods */
    STDMETHOD_(HRESULT,ExportFileGroups)(THIS_ BSTR filePath,VARIANT *fileGroupNamesSafeArray,BSTR remoteHost) PURE;
    STDMETHOD_(HRESULT,ImportFileGroups)(THIS_ BSTR filePath,VARIANT *fileGroupNamesSafeArray,BSTR remoteHost,IFsrmCommittableCollection **fileGroups) PURE;
    STDMETHOD_(HRESULT,ExportFileScreenTemplates)(THIS_ BSTR filePath,VARIANT *templateNamesSafeArray,BSTR remoteHost) PURE;
    STDMETHOD_(HRESULT,ImportFileScreenTemplates)(THIS_ BSTR filePath,VARIANT *templateNamesSafeArray,BSTR remoteHost,IFsrmCommittableCollection **templates) PURE;
    STDMETHOD_(HRESULT,ExportQuotaTemplates)(THIS_ BSTR filePath,VARIANT *templateNamesSafeArray,BSTR remoteHost) PURE;
    STDMETHOD_(HRESULT,ImportQuotaTemplates)(THIS_ BSTR filePath,VARIANT *templateNamesSafeArray,BSTR remoteHost,IFsrmCommittableCollection **templates) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmExportImport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmExportImport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmExportImport_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmCommittableCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmCommittableCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmCommittableCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmCommittableCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmExportImport_ExportFileGroups(This,filePath,fileGroupNamesSafeArray,remoteHost) (This)->lpVtbl->ExportFileGroups(This,filePath,fileGroupNamesSafeArray,remoteHost)
#define IFsrmExportImport_ImportFileGroups(This,filePath,fileGroupNamesSafeArray,remoteHost,fileGroups) (This)->lpVtbl->ImportFileGroups(This,filePath,fileGroupNamesSafeArray,remoteHost,fileGroups)
#define IFsrmExportImport_ExportFileScreenTemplates(This,filePath,templateNamesSafeArray,remoteHost) (This)->lpVtbl->ExportFileScreenTemplates(This,filePath,templateNamesSafeArray,remoteHost)
#define IFsrmExportImport_ImportFileScreenTemplates(This,filePath,templateNamesSafeArray,remoteHost,templates) (This)->lpVtbl->ImportFileScreenTemplates(This,filePath,templateNamesSafeArray,remoteHost,templates)
#define IFsrmExportImport_ExportQuotaTemplates(This,filePath,templateNamesSafeArray,remoteHost) (This)->lpVtbl->ExportQuotaTemplates(This,filePath,templateNamesSafeArray,remoteHost)
#define IFsrmExportImport_ImportQuotaTemplates(This,filePath,templateNamesSafeArray,remoteHost,templates) (This)->lpVtbl->ImportQuotaTemplates(This,filePath,templateNamesSafeArray,remoteHost,templates)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmFileManagementJob
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmFileManagementJob,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmFileManagementJob methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_NamespaceRoots)(THIS_ SAFEARRAY *pNamespaceRoots) PURE;
    STDMETHOD_(HRESULT,put_NamespaceRoots)(THIS_ SAFEARRAY namespaceRoots) PURE;
    STDMETHOD_(HRESULT,get_Enabled)(THIS_ VARIANT_BOOL *pEnabled) PURE;
    STDMETHOD_(HRESULT,put_Enabled)(THIS_ VARIANT_BOOL enabled) PURE;
    STDMETHOD_(HRESULT,get_OperationType)(THIS_ FsrmFileManagementType *pOperationType) PURE;
    STDMETHOD_(HRESULT,put_OperationType)(THIS_ FsrmFileManagementType operationType) PURE;
    STDMETHOD_(HRESULT,get_ExpirationDirectory)(THIS_ BSTR *pExpirationDirectory) PURE;
    STDMETHOD_(HRESULT,put_ExpirationDirectory)(THIS_ BSTR expirationDirectory) PURE;
    STDMETHOD_(HRESULT,get_CustomAction)(THIS_ IFsrmActionCommand **pAction) PURE;
    STDMETHOD_(HRESULT,get_Notifications)(THIS_ SAFEARRAY *pNotifications) PURE;
    STDMETHOD_(HRESULT,get_Logging)(THIS_ long *pLoggingFlags) PURE;
    STDMETHOD_(HRESULT,put_Logging)(THIS_ long loggingFlags) PURE;
    STDMETHOD_(HRESULT,get_ReportEnabled)(THIS_ VARIANT_BOOL *pReportEnabled) PURE;
    STDMETHOD_(HRESULT,put_ReportEnabled)(THIS_ VARIANT_BOOL reportEnabled) PURE;
    STDMETHOD_(HRESULT,get_Formats)(THIS_ SAFEARRAY *pFormats) PURE;
    STDMETHOD_(HRESULT,put_Formats)(THIS_ SAFEARRAY formats) PURE;
    STDMETHOD_(HRESULT,get_MailTo)(THIS_ BSTR *pMailTo) PURE;
    STDMETHOD_(HRESULT,put_MailTo)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,get_DaysSinceFileCreated)(THIS_ long *pDaysSinceCreation) PURE;
    STDMETHOD_(HRESULT,put_DaysSinceFileCreated)(THIS_ long daysSinceCreation) PURE;
    STDMETHOD_(HRESULT,get_DaysSinceFileLastAccessed)(THIS_ long *pDaysSinceAccess) PURE;
    STDMETHOD_(HRESULT,put_DaysSinceFileLastAccessed)(THIS_ long daysSinceAccess) PURE;
    STDMETHOD_(HRESULT,get_DaysSinceFileLastModified)(THIS_ long *pDaysSinceModify) PURE;
    STDMETHOD_(HRESULT,put_DaysSinceFileLastModified)(THIS_ long daysSinceModify) PURE;
    STDMETHOD_(HRESULT,get_PropertyConditions)(THIS_ IFsrmCollection **pPropertyConditions) PURE;
    STDMETHOD_(HRESULT,get_FromDate)(THIS_ DATE *pFromDate) PURE;
    STDMETHOD_(HRESULT,put_FromDate)(THIS_ DATE fromDate) PURE;
    STDMETHOD_(HRESULT,get_Task)(THIS_ BSTR *taskName) PURE;
    STDMETHOD_(HRESULT,put_Task)(THIS_ BSTR taskName) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;
    STDMETHOD_(HRESULT,get_RunningStatus)(THIS_ FsrmReportRunningStatus *pRunningStatus) PURE;
    STDMETHOD_(HRESULT,get_LastError)(THIS_ BSTR *lastError) PURE;
    STDMETHOD_(HRESULT,get_LastReportPathWithoutExtension)(THIS_ BSTR *pPath) PURE;
    STDMETHOD_(HRESULT,get_LastRun)(THIS_ DATE *lastRun) PURE;
    STDMETHOD_(HRESULT,get_FileNamePattern)(THIS_ BSTR *pFileNamePattern) PURE;
    STDMETHOD_(HRESULT,put_FileNamePattern)(THIS_ BSTR fileNamePattern) PURE;
    STDMETHOD_(HRESULT,Run)(THIS_ FsrmReportGenerationContext context) PURE;
    STDMETHOD_(HRESULT,WaitForCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;
    STDMETHOD_(HRESULT,Cancel)(THIS) PURE;
    STDMETHOD_(HRESULT,AddNotification)(THIS_ long days) PURE;
    STDMETHOD_(HRESULT,DeleteNotification)(THIS_ long days) PURE;
    STDMETHOD_(HRESULT,ModifyNotification)(THIS_ long days,long newDays) PURE;
    STDMETHOD_(HRESULT,CreateNotificationAction)(THIS_ long days,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumNotificationActions)(THIS_ long days,IFsrmCollection **actions) PURE;
    STDMETHOD_(HRESULT,CreatePropertyCondition)(THIS_ BSTR name,IFsrmPropertyCondition **pPropertyCondition) PURE;
    STDMETHOD_(HRESULT,CreateCustomAction)(THIS_ IFsrmActionCommand **customAction) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileManagementJob_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileManagementJob_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileManagementJob_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileManagementJob_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmFileManagementJob_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmFileManagementJob_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmFileManagementJob_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmFileManagementJob_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmFileManagementJob_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmFileManagementJob_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmFileManagementJob_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmFileManagementJob_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmFileManagementJob_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmFileManagementJob_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmFileManagementJob_get_NamespaceRoots(This,pNamespaceRoots) (This)->lpVtbl->get_NamespaceRoots(This,pNamespaceRoots)
#define IFsrmFileManagementJob_put_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->put_NamespaceRoots(This,namespaceRoots)
#define IFsrmFileManagementJob_get_Enabled(This,pEnabled) (This)->lpVtbl->get_Enabled(This,pEnabled)
#define IFsrmFileManagementJob_put_Enabled(This,enabled) (This)->lpVtbl->put_Enabled(This,enabled)
#define IFsrmFileManagementJob_get_OperationType(This,pOperationType) (This)->lpVtbl->get_OperationType(This,pOperationType)
#define IFsrmFileManagementJob_put_OperationType(This,operationType) (This)->lpVtbl->put_OperationType(This,operationType)
#define IFsrmFileManagementJob_get_ExpirationDirectory(This,pExpirationDirectory) (This)->lpVtbl->get_ExpirationDirectory(This,pExpirationDirectory)
#define IFsrmFileManagementJob_put_ExpirationDirectory(This,expirationDirectory) (This)->lpVtbl->put_ExpirationDirectory(This,expirationDirectory)
#define IFsrmFileManagementJob_get_CustomAction(This,pAction) (This)->lpVtbl->get_CustomAction(This,pAction)
#define IFsrmFileManagementJob_get_Notifications(This,pNotifications) (This)->lpVtbl->get_Notifications(This,pNotifications)
#define IFsrmFileManagementJob_get_Logging(This,pLoggingFlags) (This)->lpVtbl->get_Logging(This,pLoggingFlags)
#define IFsrmFileManagementJob_put_Logging(This,loggingFlags) (This)->lpVtbl->put_Logging(This,loggingFlags)
#define IFsrmFileManagementJob_get_ReportEnabled(This,pReportEnabled) (This)->lpVtbl->get_ReportEnabled(This,pReportEnabled)
#define IFsrmFileManagementJob_put_ReportEnabled(This,reportEnabled) (This)->lpVtbl->put_ReportEnabled(This,reportEnabled)
#define IFsrmFileManagementJob_get_Formats(This,pFormats) (This)->lpVtbl->get_Formats(This,pFormats)
#define IFsrmFileManagementJob_put_Formats(This,formats) (This)->lpVtbl->put_Formats(This,formats)
#define IFsrmFileManagementJob_get_MailTo(This,pMailTo) (This)->lpVtbl->get_MailTo(This,pMailTo)
#define IFsrmFileManagementJob_put_MailTo(This,mailTo) (This)->lpVtbl->put_MailTo(This,mailTo)
#define IFsrmFileManagementJob_get_DaysSinceFileCreated(This,pDaysSinceCreation) (This)->lpVtbl->get_DaysSinceFileCreated(This,pDaysSinceCreation)
#define IFsrmFileManagementJob_put_DaysSinceFileCreated(This,daysSinceCreation) (This)->lpVtbl->put_DaysSinceFileCreated(This,daysSinceCreation)
#define IFsrmFileManagementJob_get_DaysSinceFileLastAccessed(This,pDaysSinceAccess) (This)->lpVtbl->get_DaysSinceFileLastAccessed(This,pDaysSinceAccess)
#define IFsrmFileManagementJob_put_DaysSinceFileLastAccessed(This,daysSinceAccess) (This)->lpVtbl->put_DaysSinceFileLastAccessed(This,daysSinceAccess)
#define IFsrmFileManagementJob_get_DaysSinceFileLastModified(This,pDaysSinceModify) (This)->lpVtbl->get_DaysSinceFileLastModified(This,pDaysSinceModify)
#define IFsrmFileManagementJob_put_DaysSinceFileLastModified(This,daysSinceModify) (This)->lpVtbl->put_DaysSinceFileLastModified(This,daysSinceModify)
#define IFsrmFileManagementJob_get_PropertyConditions(This,pPropertyConditions) (This)->lpVtbl->get_PropertyConditions(This,pPropertyConditions)
#define IFsrmFileManagementJob_get_FromDate(This,pFromDate) (This)->lpVtbl->get_FromDate(This,pFromDate)
#define IFsrmFileManagementJob_put_FromDate(This,fromDate) (This)->lpVtbl->put_FromDate(This,fromDate)
#define IFsrmFileManagementJob_get_Task(This,taskName) (This)->lpVtbl->get_Task(This,taskName)
#define IFsrmFileManagementJob_put_Task(This,taskName) (This)->lpVtbl->put_Task(This,taskName)
#define IFsrmFileManagementJob_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmFileManagementJob_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#define IFsrmFileManagementJob_get_RunningStatus(This,pRunningStatus) (This)->lpVtbl->get_RunningStatus(This,pRunningStatus)
#define IFsrmFileManagementJob_get_LastError(This,lastError) (This)->lpVtbl->get_LastError(This,lastError)
#define IFsrmFileManagementJob_get_LastReportPathWithoutExtension(This,pPath) (This)->lpVtbl->get_LastReportPathWithoutExtension(This,pPath)
#define IFsrmFileManagementJob_get_LastRun(This,lastRun) (This)->lpVtbl->get_LastRun(This,lastRun)
#define IFsrmFileManagementJob_get_FileNamePattern(This,pFileNamePattern) (This)->lpVtbl->get_FileNamePattern(This,pFileNamePattern)
#define IFsrmFileManagementJob_put_FileNamePattern(This,fileNamePattern) (This)->lpVtbl->put_FileNamePattern(This,fileNamePattern)
#define IFsrmFileManagementJob_Run(This,context) (This)->lpVtbl->Run(This,context)
#define IFsrmFileManagementJob_WaitForCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForCompletion(This,waitSeconds,completed)
#define IFsrmFileManagementJob_Cancel() (This)->lpVtbl->Cancel(This)
#define IFsrmFileManagementJob_AddNotification(This,days) (This)->lpVtbl->AddNotification(This,days)
#define IFsrmFileManagementJob_DeleteNotification(This,days) (This)->lpVtbl->DeleteNotification(This,days)
#define IFsrmFileManagementJob_ModifyNotification(This,days,newDays) (This)->lpVtbl->ModifyNotification(This,days,newDays)
#define IFsrmFileManagementJob_CreateNotificationAction(This,days,actionType,action) (This)->lpVtbl->CreateNotificationAction(This,days,actionType,action)
#define IFsrmFileManagementJob_EnumNotificationActions(This,days,actions) (This)->lpVtbl->EnumNotificationActions(This,days,actions)
#define IFsrmFileManagementJob_CreatePropertyCondition(This,name,pPropertyCondition) (This)->lpVtbl->CreatePropertyCondition(This,name,pPropertyCondition)
#define IFsrmFileManagementJob_CreateCustomAction(This,customAction) (This)->lpVtbl->CreateCustomAction(This,customAction)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPathMapper
DECLARE_INTERFACE_(IFsrmPathMapper,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPathMapper methods */
    STDMETHOD_(HRESULT,GetSharePathsForLocalPath)(THIS_ BSTR localPath,SAFEARRAY *sharePaths) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPathMapper_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPathMapper_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPathMapper_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPathMapper_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPathMapper_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPathMapper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPathMapper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPathMapper_GetSharePathsForLocalPath(This,localPath,sharePaths) (This)->lpVtbl->GetSharePathsForLocalPath(This,localPath,sharePaths)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmSetting
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmSetting,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmSetting methods */
    STDMETHOD_(HRESULT,get_SmtpServer)(THIS_ BSTR *smtpServer) PURE;
    STDMETHOD_(HRESULT,put_SmtpServer)(THIS_ BSTR smtpServer) PURE;
    STDMETHOD_(HRESULT,get_MailFrom)(THIS_ BSTR *mailFrom) PURE;
    STDMETHOD_(HRESULT,put_MailFrom)(THIS_ BSTR mailFrom) PURE;
    STDMETHOD_(HRESULT,get_AdminEmail)(THIS_ BSTR *adminEmail) PURE;
    STDMETHOD_(HRESULT,put_AdminEmail)(THIS_ BSTR adminEmail) PURE;
    STDMETHOD_(HRESULT,get_DisableCommandLine)(THIS_ VARIANT_BOOL *disableCommandLine) PURE;
    STDMETHOD_(HRESULT,put_DisableCommandLine)(THIS_ VARIANT_BOOL disableCommandLine) PURE;
    STDMETHOD_(HRESULT,get_EnableScreeningAudit)(THIS_ VARIANT_BOOL *enableScreeningAudit) PURE;
    STDMETHOD_(HRESULT,put_EnableScreeningAudit)(THIS_ VARIANT_BOOL enableScreeningAudit) PURE;
    STDMETHOD_(HRESULT,EmailTest)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,SetActionRunLimitInterval)(THIS_ FsrmActionType actionType,long delayTimeMinutes) PURE;
    STDMETHOD_(HRESULT,GetActionRunLimitInterval)(THIS_ FsrmActionType actionType,long *delayTimeMinutes) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmSetting_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmSetting_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmSetting_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmSetting_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmSetting_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmSetting_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmSetting_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmSetting_VerifyNamespaces(This,namespacesSafeArray) (This)->lpVtbl->VerifyNamespaces(This,namespacesSafeArray)
#define IFsrmSetting_CreateScheduleTask(This,taskName,namespacesSafeArray,serializedTask) (This)->lpVtbl->CreateScheduleTask(This,taskName,namespacesSafeArray,serializedTask)
#define IFsrmSetting_ModifyScheduleTask(This,taskName,namespacesSafeArray,serializedTask) (This)->lpVtbl->ModifyScheduleTask(This,taskName,namespacesSafeArray,serializedTask)
#define IFsrmSetting_DeleteScheduleTask(This,taskName) (This)->lpVtbl->DeleteScheduleTask(This,taskName)
#define IFsrmSetting_get_SmtpServer(This,smtpServer) (This)->lpVtbl->get_SmtpServer(This,smtpServer)
#define IFsrmSetting_put_SmtpServer(This,smtpServer) (This)->lpVtbl->put_SmtpServer(This,smtpServer)
#define IFsrmSetting_get_MailFrom(This,mailFrom) (This)->lpVtbl->get_MailFrom(This,mailFrom)
#define IFsrmSetting_put_MailFrom(This,mailFrom) (This)->lpVtbl->put_MailFrom(This,mailFrom)
#define IFsrmSetting_get_AdminEmail(This,adminEmail) (This)->lpVtbl->get_AdminEmail(This,adminEmail)
#define IFsrmSetting_put_AdminEmail(This,adminEmail) (This)->lpVtbl->put_AdminEmail(This,adminEmail)
#define IFsrmSetting_get_DisableCommandLine(This,disableCommandLine) (This)->lpVtbl->get_DisableCommandLine(This,disableCommandLine)
#define IFsrmSetting_put_DisableCommandLine(This,disableCommandLine) (This)->lpVtbl->put_DisableCommandLine(This,disableCommandLine)
#define IFsrmSetting_get_EnableScreeningAudit(This,enableScreeningAudit) (This)->lpVtbl->get_EnableScreeningAudit(This,enableScreeningAudit)
#define IFsrmSetting_put_EnableScreeningAudit(This,enableScreeningAudit) (This)->lpVtbl->put_EnableScreeningAudit(This,enableScreeningAudit)
#define IFsrmSetting_EmailTest(This,mailTo) (This)->lpVtbl->EmailTest(This,mailTo)
#define IFsrmSetting_SetActionRunLimitInterval(This,actionType,delayTimeMinutes) (This)->lpVtbl->SetActionRunLimitInterval(This,actionType,delayTimeMinutes)
#define IFsrmSetting_GetActionRunLimitInterval(This,actionType,delayTimeMinutes) (This)->lpVtbl->GetActionRunLimitInterval(This,actionType,delayTimeMinutes)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/

#if (_WIN32_WINNT >= 0x0601)

#undef  INTERFACE
#define INTERFACE IFsrmRule
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmRule,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmRule methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_RuleType)(THIS_ FsrmRuleType *pRuleType) PURE;
    STDMETHOD_(HRESULT,get_ModuleDefinitionName)(THIS_ BSTR *pModuleDefinitionName) PURE;
    STDMETHOD_(HRESULT,put_ModuleDefinitionName)(THIS_ BSTR moduleDefinitionName) PURE;
    STDMETHOD_(HRESULT,get_NamespaceRoots)(THIS_ SAFEARRAY *namespaceRoots) PURE;
    STDMETHOD_(HRESULT,put_NamespaceRoots)(THIS_ SAFEARRAY namespaceRoots) PURE;
    STDMETHOD_(HRESULT,get_RuleFlags)(THIS_ long *pRuleFlags) PURE;
    STDMETHOD_(HRESULT,put_RuleFlags)(THIS_ long ruleFlags) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;
    STDMETHOD_(HRESULT,get_LastModified)(THIS_ VARIANT *pLastModified) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmRule_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmRule_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmRule_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmRule_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmRule_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmRule_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmRule_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmRule_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmRule_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmRule_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmRule_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmRule_get_RuleType(This,pRuleType) (This)->lpVtbl->get_RuleType(This,pRuleType)
#define IFsrmRule_get_ModuleDefinitionName(This,pModuleDefinitionName) (This)->lpVtbl->get_ModuleDefinitionName(This,pModuleDefinitionName)
#define IFsrmRule_put_ModuleDefinitionName(This,moduleDefinitionName) (This)->lpVtbl->put_ModuleDefinitionName(This,moduleDefinitionName)
#define IFsrmRule_get_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->get_NamespaceRoots(This,namespaceRoots)
#define IFsrmRule_put_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->put_NamespaceRoots(This,namespaceRoots)
#define IFsrmRule_get_RuleFlags(This,pRuleFlags) (This)->lpVtbl->get_RuleFlags(This,pRuleFlags)
#define IFsrmRule_put_RuleFlags(This,ruleFlags) (This)->lpVtbl->put_RuleFlags(This,ruleFlags)
#define IFsrmRule_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmRule_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#define IFsrmRule_get_LastModified(This,pLastModified) (This)->lpVtbl->get_LastModified(This,pLastModified)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmClassificationManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmClassificationManager,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmClassificationManager methods */
    STDMETHOD_(HRESULT,get_ClassificationReportFormats)(THIS_ SAFEARRAY *pFormats) PURE;
    STDMETHOD_(HRESULT,put_ClassificationReportFormats)(THIS_ SAFEARRAY formats) PURE;
    STDMETHOD_(HRESULT,get_Logging)(THIS_ long *pLogging) PURE;
    STDMETHOD_(HRESULT,put_Logging)(THIS_ long logging) PURE;
    STDMETHOD_(HRESULT,get_ClassificationReportMailTo)(THIS_ BSTR *pMailTo) PURE;
    STDMETHOD_(HRESULT,put_ClassificationReportMailTo)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,get_ClassificationReportEnabled)(THIS_ VARIANT_BOOL *pReportEnabled) PURE;
    STDMETHOD_(HRESULT,put_ClassificationReportEnabled)(THIS_ VARIANT_BOOL reportEnabled) PURE;
    STDMETHOD_(HRESULT,get_ClassificationLastReportPathWithoutExtension)(THIS_ BSTR *pLastReportPath) PURE;
    STDMETHOD_(HRESULT,get_ClassificationLastError)(THIS_ BSTR *pLastError) PURE;
    STDMETHOD_(HRESULT,get_ClassificationRunningStatus)(THIS_ FsrmReportRunningStatus *pRunningStatus) PURE;
    STDMETHOD_(HRESULT,EnumPropertyDefinitions)(THIS_ FsrmEnumOptions options,IFsrmCollection **propertyDefinitions) PURE;
    STDMETHOD_(HRESULT,CreatePropertyDefinition)(THIS_ IFsrmPropertyDefinition **propertyDefinition) PURE;
    STDMETHOD_(HRESULT,GetPropertyDefinition)(THIS_ BSTR propertyName,IFsrmPropertyDefinition **propertyDefinition) PURE;
    STDMETHOD_(HRESULT,EnumRules)(THIS_ FsrmRuleType ruleType,FsrmEnumOptions options,IFsrmCollection **rules) PURE;
    STDMETHOD_(HRESULT,CreateRule)(THIS_ FsrmRuleType ruleType,IFsrmRule **rule) PURE;
    STDMETHOD_(HRESULT,GetRule)(THIS_ BSTR ruleName,FsrmRuleType ruleType,IFsrmRule **rule) PURE;
    STDMETHOD_(HRESULT,EnumModuleDefinitions)(THIS_ FsrmPipelineModuleType moduleType,FsrmEnumOptions options,IFsrmCollection **moduleDefinitions) PURE;
    STDMETHOD_(HRESULT,CreateModuleDefinition)(THIS_ FsrmPipelineModuleType moduleType,IFsrmPipelineModuleDefinition **moduleDefinition) PURE;
    STDMETHOD_(HRESULT,GetModuleDefinition)(THIS_ BSTR moduleName,FsrmPipelineModuleType moduleType,IFsrmPipelineModuleDefinition **moduleDefinition) PURE;
    STDMETHOD_(HRESULT,RunClassification)(THIS_ FsrmReportGenerationContext context,BSTR reserved) PURE;
    STDMETHOD_(HRESULT,WaitForClassificationCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;
    STDMETHOD_(HRESULT,CancelClassification)(THIS) PURE;
    STDMETHOD_(HRESULT,EnumFileProperties)(THIS_ BSTR filePath,FsrmGetFilePropertyOptions options,IFsrmCollection **fileProperties) PURE;
    STDMETHOD_(HRESULT,GetFileProperty)(THIS_ BSTR filePath,BSTR propertyName,FsrmGetFilePropertyOptions options,IFsrmProperty **property) PURE;
    STDMETHOD_(HRESULT,SetFileProperty)(THIS_ BSTR filePath,BSTR propertyName,BSTR propertyValue) PURE;
    STDMETHOD_(HRESULT,ClearFileProperty)(THIS_ BSTR filePath,BSTR propertyName) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmClassificationManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmClassificationManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmClassificationManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmClassificationManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmClassificationManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmClassificationManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmClassificationManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmClassificationManager_get_ClassificationReportFormats(This,pFormats) (This)->lpVtbl->get_ClassificationReportFormats(This,pFormats)
#define IFsrmClassificationManager_put_ClassificationReportFormats(This,formats) (This)->lpVtbl->put_ClassificationReportFormats(This,formats)
#define IFsrmClassificationManager_get_Logging(This,pLogging) (This)->lpVtbl->get_Logging(This,pLogging)
#define IFsrmClassificationManager_put_Logging(This,logging) (This)->lpVtbl->put_Logging(This,logging)
#define IFsrmClassificationManager_get_ClassificationReportMailTo(This,pMailTo) (This)->lpVtbl->get_ClassificationReportMailTo(This,pMailTo)
#define IFsrmClassificationManager_put_ClassificationReportMailTo(This,mailTo) (This)->lpVtbl->put_ClassificationReportMailTo(This,mailTo)
#define IFsrmClassificationManager_get_ClassificationReportEnabled(This,pReportEnabled) (This)->lpVtbl->get_ClassificationReportEnabled(This,pReportEnabled)
#define IFsrmClassificationManager_put_ClassificationReportEnabled(This,reportEnabled) (This)->lpVtbl->put_ClassificationReportEnabled(This,reportEnabled)
#define IFsrmClassificationManager_get_ClassificationLastReportPathWithoutExtension(This,pLastReportPath) (This)->lpVtbl->get_ClassificationLastReportPathWithoutExtension(This,pLastReportPath)
#define IFsrmClassificationManager_get_ClassificationLastError(This,pLastError) (This)->lpVtbl->get_ClassificationLastError(This,pLastError)
#define IFsrmClassificationManager_get_ClassificationRunningStatus(This,pRunningStatus) (This)->lpVtbl->get_ClassificationRunningStatus(This,pRunningStatus)
#define IFsrmClassificationManager_EnumPropertyDefinitions(This,options,propertyDefinitions) (This)->lpVtbl->EnumPropertyDefinitions(This,options,propertyDefinitions)
#define IFsrmClassificationManager_CreatePropertyDefinition(This,propertyDefinition) (This)->lpVtbl->CreatePropertyDefinition(This,propertyDefinition)
#define IFsrmClassificationManager_GetPropertyDefinition(This,propertyName,propertyDefinition) (This)->lpVtbl->GetPropertyDefinition(This,propertyName,propertyDefinition)
#define IFsrmClassificationManager_EnumRules(This,ruleType,options,rules) (This)->lpVtbl->EnumRules(This,ruleType,options,rules)
#define IFsrmClassificationManager_CreateRule(This,ruleType,rule) (This)->lpVtbl->CreateRule(This,ruleType,rule)
#define IFsrmClassificationManager_GetRule(This,ruleName,ruleType,rule) (This)->lpVtbl->GetRule(This,ruleName,ruleType,rule)
#define IFsrmClassificationManager_EnumModuleDefinitions(This,moduleType,options,moduleDefinitions) (This)->lpVtbl->EnumModuleDefinitions(This,moduleType,options,moduleDefinitions)
#define IFsrmClassificationManager_CreateModuleDefinition(This,moduleType,moduleDefinition) (This)->lpVtbl->CreateModuleDefinition(This,moduleType,moduleDefinition)
#define IFsrmClassificationManager_GetModuleDefinition(This,moduleName,moduleType,moduleDefinition) (This)->lpVtbl->GetModuleDefinition(This,moduleName,moduleType,moduleDefinition)
#define IFsrmClassificationManager_RunClassification(This,context,reserved) (This)->lpVtbl->RunClassification(This,context,reserved)
#define IFsrmClassificationManager_WaitForClassificationCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForClassificationCompletion(This,waitSeconds,completed)
#define IFsrmClassificationManager_CancelClassification() (This)->lpVtbl->CancelClassification(This)
#define IFsrmClassificationManager_EnumFileProperties(This,filePath,options,fileProperties) (This)->lpVtbl->EnumFileProperties(This,filePath,options,fileProperties)
#define IFsrmClassificationManager_GetFileProperty(This,filePath,propertyName,options,property) (This)->lpVtbl->GetFileProperty(This,filePath,propertyName,options,property)
#define IFsrmClassificationManager_SetFileProperty(This,filePath,propertyName,propertyValue) (This)->lpVtbl->SetFileProperty(This,filePath,propertyName,propertyValue)
#define IFsrmClassificationManager_ClearFileProperty(This,filePath,propertyName) (This)->lpVtbl->ClearFileProperty(This,filePath,propertyName)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmClassificationRule
DECLARE_INTERFACE_(IFsrmClassificationRule,IFsrmRule)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

        /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmRule methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_RuleType)(THIS_ FsrmRuleType *pRuleType) PURE;
    STDMETHOD_(HRESULT,get_ModuleDefinitionName)(THIS_ BSTR *pModuleDefinitionName) PURE;
    STDMETHOD_(HRESULT,put_ModuleDefinitionName)(THIS_ BSTR moduleDefinitionName) PURE;
    STDMETHOD_(HRESULT,get_NamespaceRoots)(THIS_ SAFEARRAY *namespaceRoots) PURE;
    STDMETHOD_(HRESULT,put_NamespaceRoots)(THIS_ SAFEARRAY namespaceRoots) PURE;
    STDMETHOD_(HRESULT,get_RuleFlags)(THIS_ long *pRuleFlags) PURE;
    STDMETHOD_(HRESULT,put_RuleFlags)(THIS_ long ruleFlags) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;
    STDMETHOD_(HRESULT,get_LastModified)(THIS_ VARIANT *pLastModified) PURE;
    
    /* IFsrmClassificationRule methods */
    STDMETHOD_(HRESULT,get_ExecutionOption)(THIS_ FsrmExecutionOption *pExecutionOption) PURE;
    STDMETHOD_(HRESULT,put_ExecutionOption)(THIS_ FsrmExecutionOption executionOption) PURE;
    STDMETHOD_(HRESULT,get_PropertyAffected)(THIS_ BSTR *pProperty) PURE;
    STDMETHOD_(HRESULT,put_PropertyAffected)(THIS_ BSTR property) PURE;
    STDMETHOD_(HRESULT,get_Value)(THIS_ BSTR *pValue) PURE;
    STDMETHOD_(HRESULT,put_Value)(THIS_ BSTR value) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmClassificationRule_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmClassificationRule_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmClassificationRule_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmClassificationRule_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmClassificationRule_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmClassificationRule_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmClassificationRule_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmClassificationRule_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmClassificationRule_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmClassificationRule_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmClassificationRule_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmClassificationRule_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmClassificationRule_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmClassificationRule_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmClassificationRule_get_RuleType(This,pRuleType) (This)->lpVtbl->get_RuleType(This,pRuleType)
#define IFsrmClassificationRule_get_ModuleDefinitionName(This,pModuleDefinitionName) (This)->lpVtbl->get_ModuleDefinitionName(This,pModuleDefinitionName)
#define IFsrmClassificationRule_put_ModuleDefinitionName(This,moduleDefinitionName) (This)->lpVtbl->put_ModuleDefinitionName(This,moduleDefinitionName)
#define IFsrmClassificationRule_get_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->get_NamespaceRoots(This,namespaceRoots)
#define IFsrmClassificationRule_put_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->put_NamespaceRoots(This,namespaceRoots)
#define IFsrmClassificationRule_get_RuleFlags(This,pRuleFlags) (This)->lpVtbl->get_RuleFlags(This,pRuleFlags)
#define IFsrmClassificationRule_put_RuleFlags(This,ruleFlags) (This)->lpVtbl->put_RuleFlags(This,ruleFlags)
#define IFsrmClassificationRule_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmClassificationRule_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#define IFsrmClassificationRule_get_LastModified(This,pLastModified) (This)->lpVtbl->get_LastModified(This,pLastModified)
#define IFsrmClassificationRule_get_ExecutionOption(This,pExecutionOption) (This)->lpVtbl->get_ExecutionOption(This,pExecutionOption)
#define IFsrmClassificationRule_put_ExecutionOption(This,executionOption) (This)->lpVtbl->put_ExecutionOption(This,executionOption)
#define IFsrmClassificationRule_get_PropertyAffected(This,pProperty) (This)->lpVtbl->get_PropertyAffected(This,pProperty)
#define IFsrmClassificationRule_put_PropertyAffected(This,property) (This)->lpVtbl->put_PropertyAffected(This,property)
#define IFsrmClassificationRule_get_Value(This,pValue) (This)->lpVtbl->get_Value(This,pValue)
#define IFsrmClassificationRule_put_Value(This,value) (This)->lpVtbl->put_Value(This,value)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPipelineModuleDefinition
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPipelineModuleDefinition,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmPipelineModuleDefinition methods */
    STDMETHOD_(HRESULT,get_ModuleClsid)(THIS_ BSTR *pModuleClsid) PURE;
    STDMETHOD_(HRESULT,put_ModuleClsid)(THIS_ BSTR moduleClsid) PURE;
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Company)(THIS_ BSTR *pCompany) PURE;
    STDMETHOD_(HRESULT,put_Company)(THIS_ BSTR company) PURE;
    STDMETHOD_(HRESULT,get_Version)(THIS_ BSTR *version) PURE;
    STDMETHOD_(HRESULT,put_Version)(THIS_ BSTR version) PURE;
    STDMETHOD_(HRESULT,get_ModuleType)(THIS_ FsrmPipelineModuleType *pModuleType) PURE;
    STDMETHOD_(HRESULT,get_Enabled)(THIS_ VARIANT_BOOL *pEnabled) PURE;
    STDMETHOD_(HRESULT,put_Enabled)(THIS_ VARIANT_BOOL enabled) PURE;
    STDMETHOD_(HRESULT,get_NeedsFileContent)(THIS_ VARIANT_BOOL *pNeedsFileContent) PURE;
    STDMETHOD_(HRESULT,put_NeedsFileContent)(THIS_ VARIANT_BOOL needsFileContent) PURE;
    STDMETHOD_(HRESULT,get_Account)(THIS_ FsrmAccountType *pRetrievalAccount) PURE;
    STDMETHOD_(HRESULT,put_Account)(THIS_ FsrmAccountType retrievalAccount) PURE;
    STDMETHOD_(HRESULT,get_SupportedExtensions)(THIS_ SAFEARRAY *pSupportedExtensions) PURE;
    STDMETHOD_(HRESULT,put_SupportedExtensions)(THIS_ SAFEARRAY supportedExtensions) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPipelineModuleDefinition_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPipelineModuleDefinition_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPipelineModuleDefinition_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPipelineModuleDefinition_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPipelineModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPipelineModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPipelineModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPipelineModuleDefinition_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmPipelineModuleDefinition_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmPipelineModuleDefinition_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmPipelineModuleDefinition_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmPipelineModuleDefinition_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmPipelineModuleDefinition_get_ModuleClsid(This,pModuleClsid) (This)->lpVtbl->get_ModuleClsid(This,pModuleClsid)
#define IFsrmPipelineModuleDefinition_put_ModuleClsid(This,moduleClsid) (This)->lpVtbl->put_ModuleClsid(This,moduleClsid)
#define IFsrmPipelineModuleDefinition_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmPipelineModuleDefinition_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmPipelineModuleDefinition_get_Company(This,pCompany) (This)->lpVtbl->get_Company(This,pCompany)
#define IFsrmPipelineModuleDefinition_put_Company(This,company) (This)->lpVtbl->put_Company(This,company)
#define IFsrmPipelineModuleDefinition_get_Version(This,version) (This)->lpVtbl->get_Version(This,version)
#define IFsrmPipelineModuleDefinition_put_Version(This,version) (This)->lpVtbl->put_Version(This,version)
#define IFsrmPipelineModuleDefinition_get_ModuleType(This,pModuleType) (This)->lpVtbl->get_ModuleType(This,pModuleType)
#define IFsrmPipelineModuleDefinition_get_Enabled(This,pEnabled) (This)->lpVtbl->get_Enabled(This,pEnabled)
#define IFsrmPipelineModuleDefinition_put_Enabled(This,enabled) (This)->lpVtbl->put_Enabled(This,enabled)
#define IFsrmPipelineModuleDefinition_get_NeedsFileContent(This,pNeedsFileContent) (This)->lpVtbl->get_NeedsFileContent(This,pNeedsFileContent)
#define IFsrmPipelineModuleDefinition_put_NeedsFileContent(This,needsFileContent) (This)->lpVtbl->put_NeedsFileContent(This,needsFileContent)
#define IFsrmPipelineModuleDefinition_get_Account(This,pRetrievalAccount) (This)->lpVtbl->get_Account(This,pRetrievalAccount)
#define IFsrmPipelineModuleDefinition_put_Account(This,retrievalAccount) (This)->lpVtbl->put_Account(This,retrievalAccount)
#define IFsrmPipelineModuleDefinition_get_SupportedExtensions(This,pSupportedExtensions) (This)->lpVtbl->get_SupportedExtensions(This,pSupportedExtensions)
#define IFsrmPipelineModuleDefinition_put_SupportedExtensions(This,supportedExtensions) (This)->lpVtbl->put_SupportedExtensions(This,supportedExtensions)
#define IFsrmPipelineModuleDefinition_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmPipelineModuleDefinition_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmClassifierModuleDefinition
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmClassifierModuleDefinition,IFsrmPipelineModuleDefinition)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmPipelineModuleDefinition methods */
    STDMETHOD_(HRESULT,get_ModuleClsid)(THIS_ BSTR *pModuleClsid) PURE;
    STDMETHOD_(HRESULT,put_ModuleClsid)(THIS_ BSTR moduleClsid) PURE;
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Company)(THIS_ BSTR *pCompany) PURE;
    STDMETHOD_(HRESULT,put_Company)(THIS_ BSTR company) PURE;
    STDMETHOD_(HRESULT,get_Version)(THIS_ BSTR *version) PURE;
    STDMETHOD_(HRESULT,put_Version)(THIS_ BSTR version) PURE;
    STDMETHOD_(HRESULT,get_ModuleType)(THIS_ FsrmPipelineModuleType *pModuleType) PURE;
    STDMETHOD_(HRESULT,get_Enabled)(THIS_ VARIANT_BOOL *pEnabled) PURE;
    STDMETHOD_(HRESULT,put_Enabled)(THIS_ VARIANT_BOOL enabled) PURE;
    STDMETHOD_(HRESULT,get_NeedsFileContent)(THIS_ VARIANT_BOOL *pNeedsFileContent) PURE;
    STDMETHOD_(HRESULT,put_NeedsFileContent)(THIS_ VARIANT_BOOL needsFileContent) PURE;
    STDMETHOD_(HRESULT,get_Account)(THIS_ FsrmAccountType *pRetrievalAccount) PURE;
    STDMETHOD_(HRESULT,put_Account)(THIS_ FsrmAccountType retrievalAccount) PURE;
    STDMETHOD_(HRESULT,get_SupportedExtensions)(THIS_ SAFEARRAY *pSupportedExtensions) PURE;
    STDMETHOD_(HRESULT,put_SupportedExtensions)(THIS_ SAFEARRAY supportedExtensions) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;

    /* IFsrmClassifierModuleDefinition methods */
    STDMETHOD_(HRESULT,get_PropertiesAffected)(THIS_ SAFEARRAY *pPropertiesAffected) PURE;
    STDMETHOD_(HRESULT,put_PropertiesAffected)(THIS_ SAFEARRAY propertiesAffected) PURE;
    STDMETHOD_(HRESULT,get_PropertiesUsed)(THIS_ SAFEARRAY *pPropertiesAffected) PURE;
    STDMETHOD_(HRESULT,put_PropertiesUsed)(THIS_ SAFEARRAY propertiesAffected) PURE;
    STDMETHOD_(HRESULT,get_NeedsExplicitValue)(THIS_ VARIANT_BOOL *pNeedsExplicitValue) PURE;
    STDMETHOD_(HRESULT,put_NeedsExplicitValue)(THIS_ VARIANT_BOOL needsExplicitValue) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmClassifierModuleDefinition_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmClassifierModuleDefinition_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmClassifierModuleDefinition_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmClassifierModuleDefinition_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmClassifierModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmClassifierModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmClassifierModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmClassifierModuleDefinition_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmClassifierModuleDefinition_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmClassifierModuleDefinition_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmClassifierModuleDefinition_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmClassifierModuleDefinition_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmClassifierModuleDefinition_get_ModuleClsid(This,pModuleClsid) (This)->lpVtbl->get_ModuleClsid(This,pModuleClsid)
#define IFsrmClassifierModuleDefinition_put_ModuleClsid(This,moduleClsid) (This)->lpVtbl->put_ModuleClsid(This,moduleClsid)
#define IFsrmClassifierModuleDefinition_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmClassifierModuleDefinition_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmClassifierModuleDefinition_get_Company(This,pCompany) (This)->lpVtbl->get_Company(This,pCompany)
#define IFsrmClassifierModuleDefinition_put_Company(This,company) (This)->lpVtbl->put_Company(This,company)
#define IFsrmClassifierModuleDefinition_get_Version(This,version) (This)->lpVtbl->get_Version(This,version)
#define IFsrmClassifierModuleDefinition_put_Version(This,version) (This)->lpVtbl->put_Version(This,version)
#define IFsrmClassifierModuleDefinition_get_ModuleType(This,pModuleType) (This)->lpVtbl->get_ModuleType(This,pModuleType)
#define IFsrmClassifierModuleDefinition_get_Enabled(This,pEnabled) (This)->lpVtbl->get_Enabled(This,pEnabled)
#define IFsrmClassifierModuleDefinition_put_Enabled(This,enabled) (This)->lpVtbl->put_Enabled(This,enabled)
#define IFsrmClassifierModuleDefinition_get_NeedsFileContent(This,pNeedsFileContent) (This)->lpVtbl->get_NeedsFileContent(This,pNeedsFileContent)
#define IFsrmClassifierModuleDefinition_put_NeedsFileContent(This,needsFileContent) (This)->lpVtbl->put_NeedsFileContent(This,needsFileContent)
#define IFsrmClassifierModuleDefinition_get_Account(This,pRetrievalAccount) (This)->lpVtbl->get_Account(This,pRetrievalAccount)
#define IFsrmClassifierModuleDefinition_put_Account(This,retrievalAccount) (This)->lpVtbl->put_Account(This,retrievalAccount)
#define IFsrmClassifierModuleDefinition_get_SupportedExtensions(This,pSupportedExtensions) (This)->lpVtbl->get_SupportedExtensions(This,pSupportedExtensions)
#define IFsrmClassifierModuleDefinition_put_SupportedExtensions(This,supportedExtensions) (This)->lpVtbl->put_SupportedExtensions(This,supportedExtensions)
#define IFsrmClassifierModuleDefinition_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmClassifierModuleDefinition_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#define IFsrmClassifierModuleDefinition_get_PropertiesAffected(This,pPropertiesAffected) (This)->lpVtbl->get_PropertiesAffected(This,pPropertiesAffected)
#define IFsrmClassifierModuleDefinition_put_PropertiesAffected(This,propertiesAffected) (This)->lpVtbl->put_PropertiesAffected(This,propertiesAffected)
#define IFsrmClassifierModuleDefinition_get_PropertiesUsed(This,pPropertiesAffected) (This)->lpVtbl->get_PropertiesUsed(This,pPropertiesAffected)
#define IFsrmClassifierModuleDefinition_put_PropertiesUsed(This,propertiesAffected) (This)->lpVtbl->put_PropertiesUsed(This,propertiesAffected)
#define IFsrmClassifierModuleDefinition_get_NeedsExplicitValue(This,pNeedsExplicitValue) (This)->lpVtbl->get_NeedsExplicitValue(This,pNeedsExplicitValue)
#define IFsrmClassifierModuleDefinition_put_NeedsExplicitValue(This,needsExplicitValue) (This)->lpVtbl->put_NeedsExplicitValue(This,needsExplicitValue)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPipelineModuleImplementation
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPipelineModuleImplementation,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPipelineModuleImplementation methods */
    STDMETHOD_(HRESULT,OnLoad)(THIS_ IFsrmPipelineModuleDefinition *moduleDefinition,IFsrmPipelineModuleConnector **moduleConnector) PURE;
    STDMETHOD_(HRESULT,OnUnload)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPipelineModuleImplementation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPipelineModuleImplementation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPipelineModuleImplementation_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPipelineModuleImplementation_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPipelineModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPipelineModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPipelineModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPipelineModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector) (This)->lpVtbl->OnLoad(This,moduleDefinition,moduleConnector)
#define IFsrmPipelineModuleImplementation_OnUnload() (This)->lpVtbl->OnUnload(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmClassifierModuleImplementation
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmClassifierModuleImplementation,IFsrmPipelineModuleImplementation)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
    
    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPipelineModuleImplementation methods */
    STDMETHOD_(HRESULT,OnLoad)(THIS_ IFsrmPipelineModuleDefinition *moduleDefinition,IFsrmPipelineModuleConnector **moduleConnector) PURE;
    STDMETHOD_(HRESULT,OnUnload)(THIS) PURE;

    /* IFsrmClassifierModuleImplementation methods */
    STDMETHOD_(HRESULT,get_LastModified)(THIS_ VARIANT *pLastModified) PURE;
    STDMETHOD_(HRESULT,UseRulesAndDefinitions)(THIS_ IFsrmCollection *rules,IFsrmCollection *propertyDefinitions) PURE;
    STDMETHOD_(HRESULT,OnBeginFile)(THIS_ IFsrmPropertyBag *propertyBag,SAFEARRAY arrayRuleIds) PURE;
    STDMETHOD_(HRESULT,DoesPropertyValueApply)(THIS_ BSTR property,BSTR value,VARIANT_BOOL *applyValue,FSRM_OBJECT_ID idRule,FSRM_OBJECT_ID idPropDef) PURE;
    STDMETHOD_(HRESULT,GetPropertyValueToApply)(THIS_ BSTR property,BSTR *value,FSRM_OBJECT_ID idRule,FSRM_OBJECT_ID idPropDef) PURE;
    STDMETHOD_(HRESULT,OnEndFile)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmClassifierModuleImplementation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmClassifierModuleImplementation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmClassifierModuleImplementation_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmClassifierModuleImplementation_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmClassifierModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmClassifierModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmClassifierModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmClassifierModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector) (This)->lpVtbl->OnLoad(This,moduleDefinition,moduleConnector)
#define IFsrmClassifierModuleImplementation_OnUnload() (This)->lpVtbl->OnUnload(This)
#define IFsrmClassifierModuleImplementation_get_LastModified(This,pLastModified) (This)->lpVtbl->get_LastModified(This,pLastModified)
#define IFsrmClassifierModuleImplementation_UseRulesAndDefinitions(This,rules,propertyDefinitions) (This)->lpVtbl->UseRulesAndDefinitions(This,rules,propertyDefinitions)
#define IFsrmClassifierModuleImplementation_OnBeginFile(This,propertyBag,arrayRuleIds) (This)->lpVtbl->OnBeginFile(This,propertyBag,arrayRuleIds)
#define IFsrmClassifierModuleImplementation_DoesPropertyValueApply(This,property,value,applyValue,idRule,idPropDef) (This)->lpVtbl->DoesPropertyValueApply(This,property,value,applyValue,idRule,idPropDef)
#define IFsrmClassifierModuleImplementation_GetPropertyValueToApply(This,property,value,idRule,idPropDef) (This)->lpVtbl->GetPropertyValueToApply(This,property,value,idRule,idPropDef)
#define IFsrmClassifierModuleImplementation_OnEndFile() (This)->lpVtbl->OnEndFile(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPipelineModuleConnector
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPipelineModuleConnector,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPipelineModuleConnector methods */
    STDMETHOD_(HRESULT,get_ModuleImplementation)(THIS_ IFsrmPipelineModuleImplementation **pipelineModuleImplementation) PURE;
    STDMETHOD_(HRESULT,get_ModuleName)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,get_HostingUserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,get_HostingProcessPid)(THIS_ long *pid) PURE;
    STDMETHOD_(HRESULT,Bind)(THIS_ IFsrmPipelineModuleDefinition *moduleDefinition,IFsrmCollection *rules,IFsrmPipelineModuleImplementation *moduleImplementation) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPipelineModuleConnector_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPipelineModuleConnector_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPipelineModuleConnector_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPipelineModuleConnector_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPipelineModuleConnector_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPipelineModuleConnector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPipelineModuleConnector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPipelineModuleConnector_get_ModuleImplementation(This,pipelineModuleImplementation) (This)->lpVtbl->get_ModuleImplementation(This,pipelineModuleImplementation)
#define IFsrmPipelineModuleConnector_get_ModuleName(This,name) (This)->lpVtbl->get_ModuleName(This,name)
#define IFsrmPipelineModuleConnector_get_HostingUserAccount(This,userAccount) (This)->lpVtbl->get_HostingUserAccount(This,userAccount)
#define IFsrmPipelineModuleConnector_get_HostingProcessPid(This,pid) (This)->lpVtbl->get_HostingProcessPid(This,pid)
#define IFsrmPipelineModuleConnector_Bind(This,moduleDefinition,rules,moduleImplementation) (This)->lpVtbl->Bind(This,moduleDefinition,rules,moduleImplementation)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmProperty
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmProperty,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmProperty methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,get_Value)(THIS_ BSTR *pValue) PURE;
    STDMETHOD_(HRESULT,get_Sources)(THIS_ SAFEARRAY *pSources) PURE;
    STDMETHOD_(HRESULT,get_PropertyFlags)(THIS_ long *flags) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmProperty_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmProperty_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmProperty_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmProperty_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmProperty_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmProperty_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmProperty_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmProperty_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmProperty_get_Value(This,pValue) (This)->lpVtbl->get_Value(This,pValue)
#define IFsrmProperty_get_Sources(This,pSources) (This)->lpVtbl->get_Sources(This,pSources)
#define IFsrmProperty_get_PropertyFlags(This,flags) (This)->lpVtbl->get_PropertyFlags(This,flags)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPropertyBag
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPropertyBag,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPropertyBag methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,get_RelativePath)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,get_VolumeName)(THIS_ BSTR *volumeName) PURE;
    STDMETHOD_(HRESULT,get_RelativeNamespaceRoot)(THIS_ BSTR *relativeNamespaceRoot) PURE;
    STDMETHOD_(HRESULT,get_VolumeIndex)(THIS_ unsigned long *volumeId) PURE;
    STDMETHOD_(HRESULT,get_FileId)(THIS_ VARIANT *fileId) PURE;
    STDMETHOD_(HRESULT,get_ParentDirectoryId)(THIS_ VARIANT *parentDirectoryId) PURE;
    STDMETHOD_(HRESULT,get_Size)(THIS_ VARIANT *size) PURE;
    STDMETHOD_(HRESULT,get_SizeAllocated)(THIS_ VARIANT *sizeAllocated) PURE;
    STDMETHOD_(HRESULT,get_CreationTime)(THIS_ VARIANT *creationTime) PURE;
    STDMETHOD_(HRESULT,get_LastAccessTime)(THIS_ VARIANT *creationTime) PURE;
    STDMETHOD_(HRESULT,get_LastModificationTime)(THIS_ VARIANT *creationTime) PURE;
    STDMETHOD_(HRESULT,get_Attributes)(THIS_ unsigned long *attributes) PURE;
    STDMETHOD_(HRESULT,get_OwnerSid)(THIS_ BSTR *ownerSid) PURE;
    STDMETHOD_(HRESULT,get_FilePropertyNames)(THIS_ SAFEARRAY *filePropertyNames) PURE;
    STDMETHOD_(HRESULT,get_Messages)(THIS_ SAFEARRAY *messages) PURE;
    STDMETHOD_(HRESULT,get_PropertyBagFlags)(THIS_ unsigned long flags) PURE;
    STDMETHOD_(HRESULT,GetFileProperty)(THIS_ BSTR name,IFsrmProperty **fileProperty) PURE;
    STDMETHOD_(HRESULT,SetFileProperty)(THIS_ BSTR name,BSTR value) PURE;
    STDMETHOD_(HRESULT,AddMessage)(THIS_ BSTR message) PURE;
    STDMETHOD_(HRESULT,GetFileStreamInterface)(THIS_ FsrmFileStreamingMode accessMode,FsrmFileStreamingInterfaceType interfaceType,VARIANT **streamInterface) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPropertyBag_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPropertyBag_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPropertyBag_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPropertyBag_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPropertyBag_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPropertyBag_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPropertyBag_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPropertyBag_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmPropertyBag_get_RelativePath(This,path) (This)->lpVtbl->get_RelativePath(This,path)
#define IFsrmPropertyBag_get_VolumeName(This,volumeName) (This)->lpVtbl->get_VolumeName(This,volumeName)
#define IFsrmPropertyBag_get_RelativeNamespaceRoot(This,relativeNamespaceRoot) (This)->lpVtbl->get_RelativeNamespaceRoot(This,relativeNamespaceRoot)
#define IFsrmPropertyBag_get_VolumeIndex(This,volumeId) (This)->lpVtbl->get_VolumeIndex(This,volumeId)
#define IFsrmPropertyBag_get_FileId(This,fileId) (This)->lpVtbl->get_FileId(This,fileId)
#define IFsrmPropertyBag_get_ParentDirectoryId(This,parentDirectoryId) (This)->lpVtbl->get_ParentDirectoryId(This,parentDirectoryId)
#define IFsrmPropertyBag_get_Size(This,size) (This)->lpVtbl->get_Size(This,size)
#define IFsrmPropertyBag_get_SizeAllocated(This,sizeAllocated) (This)->lpVtbl->get_SizeAllocated(This,sizeAllocated)
#define IFsrmPropertyBag_get_CreationTime(This,creationTime) (This)->lpVtbl->get_CreationTime(This,creationTime)
#define IFsrmPropertyBag_get_LastAccessTime(This,creationTime) (This)->lpVtbl->get_LastAccessTime(This,creationTime)
#define IFsrmPropertyBag_get_LastModificationTime(This,creationTime) (This)->lpVtbl->get_LastModificationTime(This,creationTime)
#define IFsrmPropertyBag_get_Attributes(This,attributes) (This)->lpVtbl->get_Attributes(This,attributes)
#define IFsrmPropertyBag_get_OwnerSid(This,ownerSid) (This)->lpVtbl->get_OwnerSid(This,ownerSid)
#define IFsrmPropertyBag_get_FilePropertyNames(This,filePropertyNames) (This)->lpVtbl->get_FilePropertyNames(This,filePropertyNames)
#define IFsrmPropertyBag_get_Messages(This,messages) (This)->lpVtbl->get_Messages(This,messages)
#define IFsrmPropertyBag_get_PropertyBagFlags(This,flags) (This)->lpVtbl->get_PropertyBagFlags(This,flags)
#define IFsrmPropertyBag_GetFileProperty(This,name,fileProperty) (This)->lpVtbl->GetFileProperty(This,name,fileProperty)
#define IFsrmPropertyBag_SetFileProperty(This,name,value) (This)->lpVtbl->SetFileProperty(This,name,value)
#define IFsrmPropertyBag_AddMessage(This,message) (This)->lpVtbl->AddMessage(This,message)
#define IFsrmPropertyBag_GetFileStreamInterface(This,accessMode,interfaceType,streamInterface) (This)->lpVtbl->GetFileStreamInterface(This,accessMode,interfaceType,streamInterface)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmStorageModuleDefinition
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmStorageModuleDefinition,IFsrmPipelineModuleDefinition)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmPipelineModuleDefinition methods */
    STDMETHOD_(HRESULT,get_ModuleClsid)(THIS_ BSTR *pModuleClsid) PURE;
    STDMETHOD_(HRESULT,put_ModuleClsid)(THIS_ BSTR moduleClsid) PURE;
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Company)(THIS_ BSTR *pCompany) PURE;
    STDMETHOD_(HRESULT,put_Company)(THIS_ BSTR company) PURE;
    STDMETHOD_(HRESULT,get_Version)(THIS_ BSTR *version) PURE;
    STDMETHOD_(HRESULT,put_Version)(THIS_ BSTR version) PURE;
    STDMETHOD_(HRESULT,get_ModuleType)(THIS_ FsrmPipelineModuleType *pModuleType) PURE;
    STDMETHOD_(HRESULT,get_Enabled)(THIS_ VARIANT_BOOL *pEnabled) PURE;
    STDMETHOD_(HRESULT,put_Enabled)(THIS_ VARIANT_BOOL enabled) PURE;
    STDMETHOD_(HRESULT,get_NeedsFileContent)(THIS_ VARIANT_BOOL *pNeedsFileContent) PURE;
    STDMETHOD_(HRESULT,put_NeedsFileContent)(THIS_ VARIANT_BOOL needsFileContent) PURE;
    STDMETHOD_(HRESULT,get_Account)(THIS_ FsrmAccountType *pRetrievalAccount) PURE;
    STDMETHOD_(HRESULT,put_Account)(THIS_ FsrmAccountType retrievalAccount) PURE;
    STDMETHOD_(HRESULT,get_SupportedExtensions)(THIS_ SAFEARRAY *pSupportedExtensions) PURE;
    STDMETHOD_(HRESULT,put_SupportedExtensions)(THIS_ SAFEARRAY supportedExtensions) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY *pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;

    /* IFsrmStorageModuleDefinition methods */
    STDMETHOD_(HRESULT,get_Capabilities)(THIS_ FsrmStorageModuleCaps *pCapabilities) PURE;
    STDMETHOD_(HRESULT,put_Capabilities)(THIS_ FsrmStorageModuleCaps capabilities) PURE;
    STDMETHOD_(HRESULT,get_StorageType)(THIS_ FsrmStorageModuleType *pStorageType) PURE;
    STDMETHOD_(HRESULT,put_StorageType)(THIS_ FsrmStorageModuleType storageType) PURE;
    STDMETHOD_(HRESULT,get_UpdatesFileContent)(THIS_ VARIANT_BOOL *pUpdatesFileContent) PURE;
    STDMETHOD_(HRESULT,put_UpdatesFileContent)(THIS_ VARIANT_BOOL updatesFileContent) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmStorageModuleDefinition_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmStorageModuleDefinition_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmStorageModuleDefinition_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmStorageModuleDefinition_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmStorageModuleDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmStorageModuleDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmStorageModuleDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmStorageModuleDefinition_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmStorageModuleDefinition_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmStorageModuleDefinition_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmStorageModuleDefinition_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmStorageModuleDefinition_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmStorageModuleDefinition_get_ModuleClsid(This,pModuleClsid) (This)->lpVtbl->get_ModuleClsid(This,pModuleClsid)
#define IFsrmStorageModuleDefinition_put_ModuleClsid(This,moduleClsid) (This)->lpVtbl->put_ModuleClsid(This,moduleClsid)
#define IFsrmStorageModuleDefinition_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmStorageModuleDefinition_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmStorageModuleDefinition_get_Company(This,pCompany) (This)->lpVtbl->get_Company(This,pCompany)
#define IFsrmStorageModuleDefinition_put_Company(This,company) (This)->lpVtbl->put_Company(This,company)
#define IFsrmStorageModuleDefinition_get_Version(This,version) (This)->lpVtbl->get_Version(This,version)
#define IFsrmStorageModuleDefinition_put_Version(This,version) (This)->lpVtbl->put_Version(This,version)
#define IFsrmStorageModuleDefinition_get_ModuleType(This,pModuleType) (This)->lpVtbl->get_ModuleType(This,pModuleType)
#define IFsrmStorageModuleDefinition_get_Enabled(This,pEnabled) (This)->lpVtbl->get_Enabled(This,pEnabled)
#define IFsrmStorageModuleDefinition_put_Enabled(This,enabled) (This)->lpVtbl->put_Enabled(This,enabled)
#define IFsrmStorageModuleDefinition_get_NeedsFileContent(This,pNeedsFileContent) (This)->lpVtbl->get_NeedsFileContent(This,pNeedsFileContent)
#define IFsrmStorageModuleDefinition_put_NeedsFileContent(This,needsFileContent) (This)->lpVtbl->put_NeedsFileContent(This,needsFileContent)
#define IFsrmStorageModuleDefinition_get_Account(This,pRetrievalAccount) (This)->lpVtbl->get_Account(This,pRetrievalAccount)
#define IFsrmStorageModuleDefinition_put_Account(This,retrievalAccount) (This)->lpVtbl->put_Account(This,retrievalAccount)
#define IFsrmStorageModuleDefinition_get_SupportedExtensions(This,pSupportedExtensions) (This)->lpVtbl->get_SupportedExtensions(This,pSupportedExtensions)
#define IFsrmStorageModuleDefinition_put_SupportedExtensions(This,supportedExtensions) (This)->lpVtbl->put_SupportedExtensions(This,supportedExtensions)
#define IFsrmStorageModuleDefinition_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmStorageModuleDefinition_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#define IFsrmStorageModuleDefinition_get_Capabilities(This,pCapabilities) (This)->lpVtbl->get_Capabilities(This,pCapabilities)
#define IFsrmStorageModuleDefinition_put_Capabilities(This,capabilities) (This)->lpVtbl->put_Capabilities(This,capabilities)
#define IFsrmStorageModuleDefinition_get_StorageType(This,pStorageType) (This)->lpVtbl->get_StorageType(This,pStorageType)
#define IFsrmStorageModuleDefinition_put_StorageType(This,storageType) (This)->lpVtbl->put_StorageType(This,storageType)
#define IFsrmStorageModuleDefinition_get_UpdatesFileContent(This,pUpdatesFileContent) (This)->lpVtbl->get_UpdatesFileContent(This,pUpdatesFileContent)
#define IFsrmStorageModuleDefinition_put_UpdatesFileContent(This,updatesFileContent) (This)->lpVtbl->put_UpdatesFileContent(This,updatesFileContent)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmStorageModuleImplementation
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmStorageModuleImplementation,IFsrmPipelineModuleImplementation)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPipelineModuleImplementation methods */
    STDMETHOD_(HRESULT,OnLoad)(THIS_ IFsrmPipelineModuleDefinition *moduleDefinition,IFsrmPipelineModuleConnector **moduleConnector) PURE;
    STDMETHOD_(HRESULT,OnUnload)(THIS) PURE;

    /* IFsrmStorageModuleImplementation methods */
    STDMETHOD_(HRESULT,UseDefinitions)(THIS_ IFsrmCollection *propertyDefinitions) PURE;
    STDMETHOD_(HRESULT,LoadProperties)(THIS_ IFsrmPropertyBag *propertyBag) PURE;
    STDMETHOD_(HRESULT,SaveProperties)(THIS_ IFsrmPropertyBag *propertyBag) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmStorageModuleImplementation_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmStorageModuleImplementation_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmStorageModuleImplementation_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmStorageModuleImplementation_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmStorageModuleImplementation_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmStorageModuleImplementation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmStorageModuleImplementation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmStorageModuleImplementation_OnLoad(This,moduleDefinition,moduleConnector) (This)->lpVtbl->OnLoad(This,moduleDefinition,moduleConnector)
#define IFsrmStorageModuleImplementation_OnUnload() (This)->lpVtbl->OnUnload(This)
#define IFsrmStorageModuleImplementation_UseDefinitions(This,propertyDefinitions) (This)->lpVtbl->UseDefinitions(This,propertyDefinitions)
#define IFsrmStorageModuleImplementation_LoadProperties(This,propertyBag) (This)->lpVtbl->LoadProperties(This,propertyBag)
#define IFsrmStorageModuleImplementation_SaveProperties(This,propertyBag) (This)->lpVtbl->SaveProperties(This,propertyBag)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPropertyCondition
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPropertyCondition,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmPropertyCondition methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Type)(THIS_ FsrmPropertyConditionType *pType) PURE;
    STDMETHOD_(HRESULT,put_Type)(THIS_ FsrmPropertyConditionType type) PURE;
    STDMETHOD_(HRESULT,get_Value)(THIS_ BSTR *pValue) PURE;
    STDMETHOD_(HRESULT,put_Value)(THIS_ BSTR value) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPropertyCondition_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPropertyCondition_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPropertyCondition_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPropertyCondition_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPropertyCondition_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPropertyCondition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPropertyCondition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPropertyCondition_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmPropertyCondition_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmPropertyCondition_get_Type(This,pType) (This)->lpVtbl->get_Type(This,pType)
#define IFsrmPropertyCondition_put_Type(This,type) (This)->lpVtbl->put_Type(This,type)
#define IFsrmPropertyCondition_get_Value(This,pValue) (This)->lpVtbl->get_Value(This,pValue)
#define IFsrmPropertyCondition_put_Value(This,value) (This)->lpVtbl->put_Value(This,value)
#define IFsrmPropertyCondition_Delete() (This)->lpVtbl->Delete(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmPropertyDefinition
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmPropertyDefinition,IFsrmObject)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IDispatch methods */
    STDMETHOD_(HRESULT,GetTypeInfoCount)(THIS_ unsigned int FAR*  pctinfo) PURE;
    STDMETHOD_(HRESULT,GetTypeInfo)(THIS_ unsigned int  iTInfo,LCID  lcid,ITypeInfo FAR* FAR*  ppTInfo) PURE;
    STDMETHOD_(HRESULT,GetIDsOfNames)(THIS_ REFIID  riid,OLECHAR FAR* FAR*  rgszNames,unsigned int  cNames,LCID   lcid,DISPID FAR*  rgDispId) PURE;
    STDMETHOD_(HRESULT,Invoke)(THIS_ DISPID  dispIdMember,REFIID  riid,LCID  lcid,WORD  wFlags,DISPPARAMS FAR*  pDispParams,VARIANT FAR*  pVarResult,EXCEPINFO FAR*  pExcepInfo,unsigned int FAR*  puArgErr) PURE;

    /* IFsrmObject methods */
    STDMETHOD_(HRESULT,get_Id)(THIS_ FSRM_OBJECT_ID *id) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;
    STDMETHOD_(HRESULT,Commit)(THIS) PURE;

    /* IFsrmPropertyDefinition methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *pName) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Type)(THIS_ FsrmPropertyDefinitionType *pType) PURE;
    STDMETHOD_(HRESULT,put_Type)(THIS_ FsrmPropertyDefinitionType type) PURE;
    STDMETHOD_(HRESULT,get_PossibleValues)(THIS_ SAFEARRAY *pPossibleValues) PURE;
    STDMETHOD_(HRESULT,put_PossibleValues)(THIS_ SAFEARRAY possibleValues) PURE;
    STDMETHOD_(HRESULT,get_ValueDescriptions)(THIS_ SAFEARRAY *pPossibleValues) PURE;
    STDMETHOD_(HRESULT,put_ValueDescriptions)(THIS_ SAFEARRAY possibleValues) PURE;
    STDMETHOD_(HRESULT,get_Parameters)(THIS_ SAFEARRAY pParameters) PURE;
    STDMETHOD_(HRESULT,put_Parameters)(THIS_ SAFEARRAY parameters) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmPropertyDefinition_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmPropertyDefinition_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmPropertyDefinition_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmPropertyDefinition_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmPropertyDefinition_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmPropertyDefinition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmPropertyDefinition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmPropertyDefinition_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmPropertyDefinition_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmPropertyDefinition_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmPropertyDefinition_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmPropertyDefinition_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmPropertyDefinition_get_Name(This,pName) (This)->lpVtbl->get_Name(This,pName)
#define IFsrmPropertyDefinition_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmPropertyDefinition_get_Type(This,pType) (This)->lpVtbl->get_Type(This,pType)
#define IFsrmPropertyDefinition_put_Type(This,type) (This)->lpVtbl->put_Type(This,type)
#define IFsrmPropertyDefinition_get_PossibleValues(This,pPossibleValues) (This)->lpVtbl->get_PossibleValues(This,pPossibleValues)
#define IFsrmPropertyDefinition_put_PossibleValues(This,possibleValues) (This)->lpVtbl->put_PossibleValues(This,possibleValues)
#define IFsrmPropertyDefinition_get_ValueDescriptions(This,pPossibleValues) (This)->lpVtbl->get_ValueDescriptions(This,pPossibleValues)
#define IFsrmPropertyDefinition_put_ValueDescriptions(This,possibleValues) (This)->lpVtbl->put_ValueDescriptions(This,possibleValues)
#define IFsrmPropertyDefinition_get_Parameters(This,pParameters) (This)->lpVtbl->get_Parameters(This,pParameters)
#define IFsrmPropertyDefinition_put_Parameters(This,parameters) (This)->lpVtbl->put_Parameters(This,parameters)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0601)*/
#include <fsrmquota.h>
#include <fsrmscreen.h>
#include <fsrmreports.h>
#endif /*_INC_FSRM*/
