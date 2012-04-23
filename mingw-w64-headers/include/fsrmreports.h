/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fsrmenums.h>
#include <fsrm.h>
#include <fsrmquota.h>
#include <fsrmscreen.h>

#ifndef _INC_FSRMREPORTS
#define _INC_FSRMREPORTS

#if (_WIN32_WINNT >= 0x0600)
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

#undef  INTERFACE
#define INTERFACE IFsrmReport
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmReport,IDispatch)
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

    /* IFsrmReport methods */
    STDMETHOD_(HRESULT,get_Type)(THIS_ FsrmReportType *reportType) PURE;
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,get_Description)(THIS_ BSTR *description) PURE;
    STDMETHOD_(HRESULT,put_Description)(THIS_ BSTR description) PURE;
    STDMETHOD_(HRESULT,get_LastGeneratedFileNamePrefix)(THIS_ BSTR *prefix) PURE;
    STDMETHOD_(HRESULT,GetFilter)(THIS_ FsrmReportFilter filter,VARIANT *filterValue) PURE;
    STDMETHOD_(HRESULT,Delete)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmReport_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmReport_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmReport_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmReport_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmReport_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmReport_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmReport_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmReport_get_Type(This,reportType) (This)->lpVtbl->get_Type(This,reportType)
#define IFsrmReport_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmReport_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmReport_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmReport_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmReport_get_LastGeneratedFileNamePrefix(This,prefix) (This)->lpVtbl->get_LastGeneratedFileNamePrefix(This,prefix)
#define IFsrmReport_GetFilter(This,filter,filterValue) (This)->lpVtbl->GetFilter(This,filter,filterValue)
#define IFsrmReport_Delete() (This)->lpVtbl->Delete(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmReportJob
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmReportJob,IFsrmObject)
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

    /* IFsrmReportJob methods */
    STDMETHOD_(HRESULT,get_Task)(THIS_ BSTR *taskName) PURE;
    STDMETHOD_(HRESULT,put_Task)(THIS_ BSTR taskName) PURE;
    STDMETHOD_(HRESULT,get_NamespaceRoots)(THIS_ SAFEARRAY *namespaceRoots) PURE;
    STDMETHOD_(HRESULT,put_NamespaceRoots)(THIS_ SAFEARRAY namespaceRoots) PURE;
    STDMETHOD_(HRESULT,get_Formats)(THIS_ SAFEARRAY *formats) PURE;
    STDMETHOD_(HRESULT,put_Formats)(THIS_ SAFEARRAY formats) PURE;
    STDMETHOD_(HRESULT,get_MailTo)(THIS_ BSTR *mailTo) PURE;
    STDMETHOD_(HRESULT,put_MailTo)(THIS_ BSTR mailTo) PURE;
    STDMETHOD_(HRESULT,get_RunningStatus)(THIS_ FsrmReportRunningStatus *runningStatus) PURE;
    STDMETHOD_(HRESULT,get_LastRun)(THIS_ DATE *lastRun) PURE;
    STDMETHOD_(HRESULT,get_LastError)(THIS_ BSTR *lastError) PURE;
    STDMETHOD_(HRESULT,get_LastGeneratedInDirectory)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,EnumReports)(THIS_ IFsrmCollection **reports) PURE;
    STDMETHOD_(HRESULT,CreateReport)(THIS_ FsrmReportType reportType,IFsrmReport **report) PURE;
    STDMETHOD_(HRESULT,Run)(THIS_ FsrmReportGenerationContext context) PURE;
    STDMETHOD_(HRESULT,WaitForCompletion)(THIS_ long waitSeconds,VARIANT_BOOL *completed) PURE;
    STDMETHOD_(HRESULT,Cancel)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmReportJob_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmReportJob_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmReportJob_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmReportJob_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmReportJob_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmReportJob_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmReportJob_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmReportJob_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmReportJob_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmReportJob_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmReportJob_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmReportJob_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmReportJob_get_Task(This,taskName) (This)->lpVtbl->get_Task(This,taskName)
#define IFsrmReportJob_put_Task(This,taskName) (This)->lpVtbl->put_Task(This,taskName)
#define IFsrmReportJob_get_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->get_NamespaceRoots(This,namespaceRoots)
#define IFsrmReportJob_put_NamespaceRoots(This,namespaceRoots) (This)->lpVtbl->put_NamespaceRoots(This,namespaceRoots)
#define IFsrmReportJob_get_Formats(This,formats) (This)->lpVtbl->get_Formats(This,formats)
#define IFsrmReportJob_put_Formats(This,formats) (This)->lpVtbl->put_Formats(This,formats)
#define IFsrmReportJob_get_MailTo(This,mailTo) (This)->lpVtbl->get_MailTo(This,mailTo)
#define IFsrmReportJob_put_MailTo(This,mailTo) (This)->lpVtbl->put_MailTo(This,mailTo)
#define IFsrmReportJob_get_RunningStatus(This,runningStatus) (This)->lpVtbl->get_RunningStatus(This,runningStatus)
#define IFsrmReportJob_get_LastRun(This,lastRun) (This)->lpVtbl->get_LastRun(This,lastRun)
#define IFsrmReportJob_get_LastError(This,lastError) (This)->lpVtbl->get_LastError(This,lastError)
#define IFsrmReportJob_get_LastGeneratedInDirectory(This,path) (This)->lpVtbl->get_LastGeneratedInDirectory(This,path)
#define IFsrmReportJob_EnumReports(This,reports) (This)->lpVtbl->EnumReports(This,reports)
#define IFsrmReportJob_CreateReport(This,reportType,report) (This)->lpVtbl->CreateReport(This,reportType,report)
#define IFsrmReportJob_Run(This,context) (This)->lpVtbl->Run(This,context)
#define IFsrmReportJob_WaitForCompletion(This,waitSeconds,completed) (This)->lpVtbl->WaitForCompletion(This,waitSeconds,completed)
#define IFsrmReportJob_Cancel() (This)->lpVtbl->Cancel(This)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmReportManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmReportManager,IDispatch)
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

    /* IFsrmReportManager methods */
    STDMETHOD_(HRESULT,EnumReportJobs)(THIS_ FsrmEnumOptions options,IFsrmCollection **reportJobs) PURE;
    STDMETHOD_(HRESULT,CreateReportJob)(THIS_ IFsrmReportJob **reportJob) PURE;
    STDMETHOD_(HRESULT,GetReportJob)(THIS_ BSTR taskName,IFsrmReportJob **reportJob) PURE;
    STDMETHOD_(HRESULT,GetOutputDirectory)(THIS_ FsrmReportGenerationContext context,BSTR *path) PURE;
    STDMETHOD_(HRESULT,SetOutputDirectory)(THIS_ FsrmReportGenerationContext context,BSTR path) PURE;
    STDMETHOD_(HRESULT,IsFilterValidForReportType)(THIS_ FsrmReportType reportType,FsrmReportFilter filter,VARIANT_BOOL *valid) PURE;
    STDMETHOD_(HRESULT,GetDefaultFilter)(THIS_ FsrmReportType reportType,FsrmReportFilter filter,VARIANT *filterValue) PURE;
    STDMETHOD_(HRESULT,SetDefaultFilter)(THIS_ FsrmReportType reportType,FsrmReportFilter filter,VARIANT filterValue) PURE;
    STDMETHOD_(HRESULT,GetReportSizeLimit)(THIS_ FsrmReportLimit limit,VARIANT *limitValue) PURE;
    STDMETHOD_(HRESULT,SetReportSizeLimit)(THIS_ FsrmReportLimit limit,VARIANT limitValue) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmReportManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmReportManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmReportManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmReportManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmReportManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmReportManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmReportManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmReportManager_EnumReportJobs(This,options,reportJobs) (This)->lpVtbl->EnumReportJobs(This,options,reportJobs)
#define IFsrmReportManager_CreateReportJob(This,reportJob) (This)->lpVtbl->CreateReportJob(This,reportJob)
#define IFsrmReportManager_GetReportJob(This,taskName,reportJob) (This)->lpVtbl->GetReportJob(This,taskName,reportJob)
#define IFsrmReportManager_GetOutputDirectory(This,context,path) (This)->lpVtbl->GetOutputDirectory(This,context,path)
#define IFsrmReportManager_SetOutputDirectory(This,context,path) (This)->lpVtbl->SetOutputDirectory(This,context,path)
#define IFsrmReportManager_IsFilterValidForReportType(This,reportType,filter,valid) (This)->lpVtbl->IsFilterValidForReportType(This,reportType,filter,valid)
#define IFsrmReportManager_GetDefaultFilter(This,reportType,filter,filterValue) (This)->lpVtbl->GetDefaultFilter(This,reportType,filter,filterValue)
#define IFsrmReportManager_SetDefaultFilter(This,reportType,filter,filterValue) (This)->lpVtbl->SetDefaultFilter(This,reportType,filter,filterValue)
#define IFsrmReportManager_GetReportSizeLimit(This,limit,limitValue) (This)->lpVtbl->GetReportSizeLimit(This,limit,limitValue)
#define IFsrmReportManager_SetReportSizeLimit(This,limit,limitValue) (This)->lpVtbl->SetReportSizeLimit(This,limit,limitValue)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmReportScheduler
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmReportScheduler,IDispatch)
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

    /* IFsrmReportScheduler methods */
    STDMETHOD_(HRESULT,VerifyNamespaces)(THIS_ VARIANT *namespacesSafeArray) PURE;
    STDMETHOD_(HRESULT,CreateScheduleTask)(THIS_ BSTR taskName,VARIANT *namespacesSafeArray,BSTR serializedTask) PURE;
    STDMETHOD_(HRESULT,ModifyScheduleTask)(THIS_ BSTR taskName,VARIANT *namespacesSafeArray,BSTR serializedTask) PURE;
    STDMETHOD_(HRESULT,DeleteScheduleTask)(THIS_ BSTR taskName) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmReportScheduler_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmReportScheduler_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmReportScheduler_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmReportScheduler_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmReportScheduler_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmReportScheduler_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmReportScheduler_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmReportScheduler_VerifyNamespaces(This,namespacesSafeArray) (This)->lpVtbl->VerifyNamespaces(This,namespacesSafeArray)
#define IFsrmReportScheduler_CreateScheduleTask(This,taskName,namespacesSafeArray,serializedTask) (This)->lpVtbl->CreateScheduleTask(This,taskName,namespacesSafeArray,serializedTask)
#define IFsrmReportScheduler_ModifyScheduleTask(This,taskName,namespacesSafeArray,serializedTask) (This)->lpVtbl->ModifyScheduleTask(This,taskName,namespacesSafeArray,serializedTask)
#define IFsrmReportScheduler_DeleteScheduleTask(This,taskName) (This)->lpVtbl->DeleteScheduleTask(This,taskName)
#endif /*COBJMACROS*/

#endif /* (_WIN32_WINNT >= 0x0600) */
#if (_WIN32_WINNT >= 0x0601)

#undef  INTERFACE
#define INTERFACE IFsrmFileManagementJobManager
DECLARE_INTERFACE_(IFsrmFileManagementJobManager,IDispatch)
{
    BEGIN_INTERFACE

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, void **ppvObject) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IFsrmFileManagementJobManager methods */
    STDMETHOD_(HRESULT,get_ActionVariables)(THIS_ SAFEARRAY *variables) PURE;
    STDMETHOD_(HRESULT,get_ActionVariableDescriptions)(THIS_ SAFEARRAY *descriptions) PURE;
    STDMETHOD_(HRESULT,EnumFileManagementJobs)(THIS_ FsrmEnumOptions options,IFsrmCollection **fileManagementJobs) PURE;
    STDMETHOD_(HRESULT,CreateFileManagementJob)(THIS_ IFsrmFileManagementJob **fileManagementJob) PURE;
    STDMETHOD_(HRESULT,GetFileManagementJob)(THIS_ BSTR name,IFsrmFileManagementJob **fileManagementJob) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmFileManagementJobManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmFileManagementJobManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmFileManagementJobManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmFileManagementJobManager_get_ActionVariables(This,variables) (This)->lpVtbl->get_ActionVariables(This,variables)
#define IFsrmFileManagementJobManager_get_ActionVariableDescriptions(This,descriptions) (This)->lpVtbl->get_ActionVariableDescriptions(This,descriptions)
#define IFsrmFileManagementJobManager_EnumFileManagementJobs(This,options,fileManagementJobs) (This)->lpVtbl->EnumFileManagementJobs(This,options,fileManagementJobs)
#define IFsrmFileManagementJobManager_CreateFileManagementJob(This,fileManagementJob) (This)->lpVtbl->CreateFileManagementJob(This,fileManagementJob)
#define IFsrmFileManagementJobManager_GetFileManagementJob(This,name,fileManagementJob) (This)->lpVtbl->GetFileManagementJob(This,name,fileManagementJob)
#endif /*COBJMACROS*/
#endif /*(_WIN32_WINNT >= 0x0601)*/
#endif /*_INC_FSRMREPORTS*/
