/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <fsrmenums.h>
#include <fsrm.h>

#ifndef _INC_FSRMQUOTA
#define _INC_FSRMQUOTA
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
#define INTERFACE IFsrmQuotaBase
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaBase,IFsrmObject)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaBase_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaBase_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaBase_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaBase_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaBase_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmQuotaBase_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmQuotaBase_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmQuotaBase_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmQuotaBase_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmQuotaBase_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaBase_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaBase_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaBase_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaBase_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmQuotaBase_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmQuotaBase_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmQuotaBase_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmQuotaBase_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmQuotaBase_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuotaObject
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaObject,IFsrmQuotaBase)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    /* IFsrmQuotaObject methods */
    STDMETHOD_(HRESULT,get_Path)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,get_SourceTemplateName)(THIS_ BSTR *quotaTemplateName) PURE;
    STDMETHOD_(HRESULT,get_MatchesSourceTemplate)(THIS_ VARIANT_BOOL *matches) PURE;
    STDMETHOD_(HRESULT,ApplyTemplate)(THIS_ BSTR quotaTemplateName) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaObject_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaObject_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaObject_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaObject_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaObject_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmQuotaObject_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmQuotaObject_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmQuotaObject_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmQuotaObject_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmQuotaObject_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaObject_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaObject_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaObject_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaObject_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmQuotaObject_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmQuotaObject_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmQuotaObject_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmQuotaObject_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmQuotaObject_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#define IFsrmQuotaObject_get_Path(This,path) (This)->lpVtbl->get_Path(This,path)
#define IFsrmQuotaObject_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmQuotaObject_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmQuotaObject_get_SourceTemplateName(This,quotaTemplateName) (This)->lpVtbl->get_SourceTemplateName(This,quotaTemplateName)
#define IFsrmQuotaObject_get_MatchesSourceTemplate(This,matches) (This)->lpVtbl->get_MatchesSourceTemplate(This,matches)
#define IFsrmQuotaObject_ApplyTemplate(This,quotaTemplateName) (This)->lpVtbl->ApplyTemplate(This,quotaTemplateName)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmAutoApplyQuota
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmAutoApplyQuota,IFsrmQuotaObject)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    /* IFsrmQuotaObject methods */
    STDMETHOD_(HRESULT,get_Path)(THIS_ BSTR *path) PURE;
    STDMETHOD_(HRESULT,get_UserSid)(THIS_ BSTR *userSid) PURE;
    STDMETHOD_(HRESULT,get_UserAccount)(THIS_ BSTR *userAccount) PURE;
    STDMETHOD_(HRESULT,get_SourceTemplateName)(THIS_ BSTR *quotaTemplateName) PURE;
    STDMETHOD_(HRESULT,get_MatchesSourceTemplate)(THIS_ VARIANT_BOOL *matches) PURE;
    STDMETHOD_(HRESULT,ApplyTemplate)(THIS_ BSTR quotaTemplateName) PURE;

    /* IFsrmAutoApplyQuota methods */
    STDMETHOD_(HRESULT,get_ExcludeFolders)(THIS_ SAFEARRAY **folders) PURE;
    STDMETHOD_(HRESULT,put_ExcludeFolders)(THIS_ SAFEARRAY *folders) PURE;
    STDMETHOD_(HRESULT,CommitAndUpdateDerived)(THIS_ FsrmCommitOptions commitOptions,FsrmTemplateApplyOptions applyOptions,IFsrmDerivedObjectsResult **derivedObjectsResult) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmAutoApplyQuota_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmAutoApplyQuota_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmAutoApplyQuota_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmAutoApplyQuota_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmAutoApplyQuota_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmAutoApplyQuota_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmAutoApplyQuota_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmAutoApplyQuota_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmAutoApplyQuota_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmAutoApplyQuota_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmAutoApplyQuota_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmAutoApplyQuota_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmAutoApplyQuota_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmAutoApplyQuota_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmAutoApplyQuota_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmAutoApplyQuota_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmAutoApplyQuota_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmAutoApplyQuota_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmAutoApplyQuota_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmAutoApplyQuota_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmAutoApplyQuota_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmAutoApplyQuota_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#define IFsrmAutoApplyQuota_get_Path(This,path) (This)->lpVtbl->get_Path(This,path)
#define IFsrmAutoApplyQuota_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmAutoApplyQuota_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmAutoApplyQuota_get_SourceTemplateName(This,quotaTemplateName) (This)->lpVtbl->get_SourceTemplateName(This,quotaTemplateName)
#define IFsrmAutoApplyQuota_get_MatchesSourceTemplate(This,matches) (This)->lpVtbl->get_MatchesSourceTemplate(This,matches)
#define IFsrmAutoApplyQuota_ApplyTemplate(This,quotaTemplateName) (This)->lpVtbl->ApplyTemplate(This,quotaTemplateName)
#define IFsrmAutoApplyQuota_get_ExcludeFolders(This,folders) (This)->lpVtbl->get_ExcludeFolders(This,folders)
#define IFsrmAutoApplyQuota_put_ExcludeFolders(This,folders) (This)->lpVtbl->put_ExcludeFolders(This,folders)
#define IFsrmAutoApplyQuota_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) (This)->lpVtbl->CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuota
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuota,IFsrmQuotaObject)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    /* IFsrmQuota methods */
    STDMETHOD_(HRESULT,get_QuotaUsed)(THIS_ VARIANT *used) PURE;
    STDMETHOD_(HRESULT,get_QuotaPeakUsage)(THIS_ VARIANT *peakUsage) PURE;
    STDMETHOD_(HRESULT,get_QuotaPeakUsageTime)(THIS_ DATE *peakUsageDateTime) PURE;
    STDMETHOD_(HRESULT,ResetPeakUsage)(THIS) PURE;
    STDMETHOD_(HRESULT,RefreshUsageProperties)(THIS) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuota_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuota_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuota_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuota_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuota_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuota_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuota_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuota_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmQuota_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmQuota_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmQuota_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmQuota_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmQuota_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmQuota_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmQuota_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmQuota_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmQuota_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmQuota_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmQuota_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmQuota_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmQuota_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmQuota_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#define IFsrmQuota_get_Path(This,path) (This)->lpVtbl->get_Path(This,path)
#define IFsrmQuota_get_UserSid(This,userSid) (This)->lpVtbl->get_UserSid(This,userSid)
#define IFsrmQuota_get_UserAccount(This,userAccount) (This)->lpVtbl->get_UserAccount(This,userAccount)
#define IFsrmQuota_get_SourceTemplateName(This,quotaTemplateName) (This)->lpVtbl->get_SourceTemplateName(This,quotaTemplateName)
#define IFsrmQuota_get_MatchesSourceTemplate(This,matches) (This)->lpVtbl->get_MatchesSourceTemplate(This,matches)
#define IFsrmQuota_ApplyTemplate(This,quotaTemplateName) (This)->lpVtbl->ApplyTemplate(This,quotaTemplateName)
#define IFsrmQuota_get_QuotaUsed(This,used) (This)->lpVtbl->get_QuotaUsed(This,used)
#define IFsrmQuota_get_QuotaPeakUsage(This,peakUsage) (This)->lpVtbl->get_QuotaPeakUsage(This,peakUsage)
#define IFsrmQuota_get_QuotaPeakUsageTime(This,peakUsageDateTime) (This)->lpVtbl->get_QuotaPeakUsageTime(This,peakUsageDateTime)
#define IFsrmQuota_ResetPeakUsage() (This)->lpVtbl->ResetPeakUsage(This)
#define IFsrmQuota_RefreshUsageProperties() (This)->lpVtbl->RefreshUsageProperties(This)
#endif /*COBJMACROS*/


#undef  INTERFACE
#define INTERFACE IFsrmQuotaTemplate
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaTemplate,IFsrmQuotaBase)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    /* IFsrmQuotaTemplate methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,CopyTemplate)(THIS_ BSTR quotaTemplateName) PURE;
    STDMETHOD_(HRESULT,CommitAndUpdateDerived)(THIS_ FsrmCommitOptions commitOptions,FsrmTemplateApplyOptions applyOptions,IFsrmDerivedObjectsResult **derivedObjectsResult) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaTemplate_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaTemplate_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaTemplate_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaTemplate_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaTemplate_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaTemplate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaTemplate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaTemplate_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmQuotaTemplate_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmQuotaTemplate_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmQuotaTemplate_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmQuotaTemplate_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmQuotaTemplate_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaTemplate_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaTemplate_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaTemplate_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaTemplate_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmQuotaTemplate_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmQuotaTemplate_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmQuotaTemplate_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmQuotaTemplate_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmQuotaTemplate_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#define IFsrmQuotaTemplate_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmQuotaTemplate_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmQuotaTemplate_CopyTemplate(This,quotaTemplateName) (This)->lpVtbl->CopyTemplate(This,quotaTemplateName)
#define IFsrmQuotaTemplate_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) (This)->lpVtbl->CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuotaTemplateImported
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaTemplateImported,IFsrmQuotaTemplate)
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

    /* IFsrmQuotaBase methods */
    STDMETHOD_(HRESULT,get_QuotaLimit)(THIS_ VARIANT *quotaLimit) PURE;
    STDMETHOD_(HRESULT,put_QuotaLimit)(THIS_ VARIANT quotaLimit) PURE;
    STDMETHOD_(HRESULT,get_QuotaFlags)(THIS_ __LONG32 *quotaFlags) PURE;
    STDMETHOD_(HRESULT,put_QuotaFlags)(THIS_ __LONG32 quotaFlags) PURE;
    STDMETHOD_(HRESULT,get_Thresholds)(THIS_ SAFEARRAY *thresholds) PURE;
    STDMETHOD_(HRESULT,AddThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,DeleteThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold) PURE;
    STDMETHOD_(HRESULT,ModifyThreshold)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FSRM_QUOTA_THRESHOLD newThreshold) PURE;
    STDMETHOD_(HRESULT,CreateThresholdAction)(THIS_ FSRM_QUOTA_THRESHOLD threshold,FsrmActionType actionType,IFsrmAction **action) PURE;
    STDMETHOD_(HRESULT,EnumThresholdActions)(THIS_ FSRM_QUOTA_THRESHOLD threshold,IFsrmCollection **actions) PURE;

    /* IFsrmQuotaTemplate methods */
    STDMETHOD_(HRESULT,get_Name)(THIS_ BSTR *name) PURE;
    STDMETHOD_(HRESULT,put_Name)(THIS_ BSTR name) PURE;
    STDMETHOD_(HRESULT,CopyTemplate)(THIS_ BSTR quotaTemplateName) PURE;
    STDMETHOD_(HRESULT,CommitAndUpdateDerived)(THIS_ FsrmCommitOptions commitOptions,FsrmTemplateApplyOptions applyOptions,IFsrmDerivedObjectsResult **derivedObjectsResult) PURE;

    /* IFsrmQuotaTemplateImported methods */
    STDMETHOD_(HRESULT,get_OverwriteOnCommit)(THIS_ VARIANT_BOOL *overwrite) PURE;
    STDMETHOD_(HRESULT,put_OverwriteOnCommit)(THIS_ VARIANT_BOOL overwrite) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaTemplateImported_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaTemplateImported_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaTemplateImported_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaTemplateImported_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaTemplateImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaTemplateImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaTemplateImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaTemplateImported_get_Id(This,id) (This)->lpVtbl->get_Id(This,id)
#define IFsrmQuotaTemplateImported_get_Description(This,description) (This)->lpVtbl->get_Description(This,description)
#define IFsrmQuotaTemplateImported_put_Description(This,description) (This)->lpVtbl->put_Description(This,description)
#define IFsrmQuotaTemplateImported_Delete() (This)->lpVtbl->Delete(This)
#define IFsrmQuotaTemplateImported_Commit() (This)->lpVtbl->Commit(This)
#define IFsrmQuotaTemplateImported_get_QuotaLimit(This,quotaLimit) (This)->lpVtbl->get_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaTemplateImported_put_QuotaLimit(This,quotaLimit) (This)->lpVtbl->put_QuotaLimit(This,quotaLimit)
#define IFsrmQuotaTemplateImported_get_QuotaFlags(This,quotaFlags) (This)->lpVtbl->get_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaTemplateImported_put_QuotaFlags(This,quotaFlags) (This)->lpVtbl->put_QuotaFlags(This,quotaFlags)
#define IFsrmQuotaTemplateImported_get_Thresholds(This,thresholds) (This)->lpVtbl->get_Thresholds(This,thresholds)
#define IFsrmQuotaTemplateImported_AddThreshold(This,threshold) (This)->lpVtbl->AddThreshold(This,threshold)
#define IFsrmQuotaTemplateImported_DeleteThreshold(This,threshold) (This)->lpVtbl->DeleteThreshold(This,threshold)
#define IFsrmQuotaTemplateImported_ModifyThreshold(This,threshold,newThreshold) (This)->lpVtbl->ModifyThreshold(This,threshold,newThreshold)
#define IFsrmQuotaTemplateImported_CreateThresholdAction(This,threshold,actionType,action) (This)->lpVtbl->CreateThresholdAction(This,threshold,actionType,action)
#define IFsrmQuotaTemplateImported_EnumThresholdActions(This,threshold,actions) (This)->lpVtbl->EnumThresholdActions(This,threshold,actions)
#define IFsrmQuotaTemplateImported_get_Name(This,name) (This)->lpVtbl->get_Name(This,name)
#define IFsrmQuotaTemplateImported_put_Name(This,name) (This)->lpVtbl->put_Name(This,name)
#define IFsrmQuotaTemplateImported_CopyTemplate(This,quotaTemplateName) (This)->lpVtbl->CopyTemplate(This,quotaTemplateName)
#define IFsrmQuotaTemplateImported_CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult) (This)->lpVtbl->CommitAndUpdateDerived(This,commitOptions,applyOptions,derivedObjectsResult)
#define IFsrmQuotaTemplateImported_get_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->get_OverwriteOnCommit(This,overwrite)
#define IFsrmQuotaTemplateImported_put_OverwriteOnCommit(This,overwrite) (This)->lpVtbl->put_OverwriteOnCommit(This,overwrite)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuotaTemplateManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaTemplateManager,IDispatch)
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

    /* IFsrmQuotaTemplateManager methods */
    STDMETHOD_(HRESULT,CreateTemplate)(THIS_ IFsrmQuotaTemplate **quotaTemplate) PURE;
    STDMETHOD_(HRESULT,GetTemplate)(THIS_ BSTR name,IFsrmQuotaTemplate **quotaTemplate) PURE;
    STDMETHOD_(HRESULT,EnumTemplates)(THIS_ FsrmEnumOptions options,IFsrmCommittableCollection **quotaTemplates) PURE;
    STDMETHOD_(HRESULT,ExportTemplates)(THIS_ VARIANT *quotaTemplateNamesArray,BSTR *serializedQuotaTemplates) PURE;
    STDMETHOD_(HRESULT,ImportTemplates)(THIS_ BSTR serializedQuotaTemplates,VARIANT *quotaTemplateNamesArray,IFsrmCommittableCollection **quotaTemplates) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaTemplateManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaTemplateManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaTemplateManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaTemplateImported_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaTemplateImported_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaTemplateImported_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaTemplateImported_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaTemplateManager_CreateTemplate(This,quotaTemplate) (This)->lpVtbl->CreateTemplate(This,quotaTemplate)
#define IFsrmQuotaTemplateManager_GetTemplate(This,name,quotaTemplate) (This)->lpVtbl->GetTemplate(This,name,quotaTemplate)
#define IFsrmQuotaTemplateManager_EnumTemplates(This,options,quotaTemplates) (This)->lpVtbl->EnumTemplates(This,options,quotaTemplates)
#define IFsrmQuotaTemplateManager_ExportTemplates(This,quotaTemplateNamesArray,serializedQuotaTemplates) (This)->lpVtbl->ExportTemplates(This,quotaTemplateNamesArray,serializedQuotaTemplates)
#define IFsrmQuotaTemplateManager_ImportTemplates(This,serializedQuotaTemplates,quotaTemplateNamesArray,quotaTemplates) (This)->lpVtbl->ImportTemplates(This,serializedQuotaTemplates,quotaTemplateNamesArray,quotaTemplates)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuotaManager
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaManager,IDispatch)
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

    /* IFsrmQuotaManager methods */
    STDMETHOD_(HRESULT,get_ActionVariables)(THIS_ SAFEARRAY *variables) PURE;
    STDMETHOD_(HRESULT,get_ActionVariableDescriptions)(THIS_ SAFEARRAY *descriptions) PURE;
    STDMETHOD_(HRESULT,CreateQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,CreateAutoApplyQuota)(THIS_ BSTR quotaTemplateName,BSTR path,IFsrmAutoApplyQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetAutoApplyQuota)(THIS_ BSTR path,IFsrmAutoApplyQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetRestrictiveQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,EnumQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,EnumAutoApplyQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,EnumEffectiveQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,Scan)(THIS_ BSTR strPath) PURE;
    STDMETHOD_(HRESULT,CreateQuotaCollection)(THIS_ IFsrmCommittableCollection **collection) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaManager_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaManager_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaManager_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaManager_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaManager_get_ActionVariables(This,variables) (This)->lpVtbl->get_ActionVariables(This,variables)
#define IFsrmQuotaManager_get_ActionVariableDescriptions(This,descriptions) (This)->lpVtbl->get_ActionVariableDescriptions(This,descriptions)
#define IFsrmQuotaManager_CreateQuota(This,path,quota) (This)->lpVtbl->CreateQuota(This,path,quota)
#define IFsrmQuotaManager_CreateAutoApplyQuota(This,quotaTemplateName,path,quota) (This)->lpVtbl->CreateAutoApplyQuota(This,quotaTemplateName,path,quota)
#define IFsrmQuotaManager_GetQuota(This,path,quota) (This)->lpVtbl->GetQuota(This,path,quota)
#define IFsrmQuotaManager_GetAutoApplyQuota(This,path,quota) (This)->lpVtbl->GetAutoApplyQuota(This,path,quota)
#define IFsrmQuotaManager_GetRestrictiveQuota(This,path,quota) (This)->lpVtbl->GetRestrictiveQuota(This,path,quota)
#define IFsrmQuotaManager_EnumQuotas(This,path,options,quotas) (This)->lpVtbl->EnumQuotas(This,path,options,quotas)
#define IFsrmQuotaManager_EnumAutoApplyQuotas(This,path,options,quotas) (This)->lpVtbl->EnumAutoApplyQuotas(This,path,options,quotas)
#define IFsrmQuotaManager_EnumEffectiveQuotas(This,path,options,quotas) (This)->lpVtbl->EnumEffectiveQuotas(This,path,options,quotas)
#define IFsrmQuotaManager_Scan(This,strPath) (This)->lpVtbl->Scan(This,strPath)
#define IFsrmQuotaManager_CreateQuotaCollection(This,collection) (This)->lpVtbl->CreateQuotaCollection(This,collection)
#endif /*COBJMACROS*/

#undef  INTERFACE
#define INTERFACE IFsrmQuotaManagerEx
#ifdef __GNUC__
#warning COM interfaces layout in this header has not been verified.
#warning COM interfaces with incorrect layout may not work at all.
__MINGW_BROKEN_INTERFACE(INTERFACE)
#endif
DECLARE_INTERFACE_(IFsrmQuotaManagerEx,IFsrmQuotaManager)
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

    /* IFsrmQuotaManager methods */
    STDMETHOD_(HRESULT,get_ActionVariables)(THIS_ SAFEARRAY *variables) PURE;
    STDMETHOD_(HRESULT,get_ActionVariableDescriptions)(THIS_ SAFEARRAY *descriptions) PURE;
    STDMETHOD_(HRESULT,CreateQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,CreateAutoApplyQuota)(THIS_ BSTR quotaTemplateName,BSTR path,IFsrmAutoApplyQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetAutoApplyQuota)(THIS_ BSTR path,IFsrmAutoApplyQuota **quota) PURE;
    STDMETHOD_(HRESULT,GetRestrictiveQuota)(THIS_ BSTR path,IFsrmQuota **quota) PURE;
    STDMETHOD_(HRESULT,EnumQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,EnumAutoApplyQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,EnumEffectiveQuotas)(THIS_ BSTR path,FsrmEnumOptions options,IFsrmCommittableCollection **quotas) PURE;
    STDMETHOD_(HRESULT,Scan)(THIS_ BSTR strPath) PURE;
    STDMETHOD_(HRESULT,CreateQuotaCollection)(THIS_ IFsrmCommittableCollection **collection) PURE;

    /* IFsrmQuotaManagerEx methods */
    STDMETHOD_(HRESULT,IsAffectedByQuota)(THIS_ BSTR path,FsrmEnumOptions options,VARIANT_BOOL *affected) PURE;

    END_INTERFACE
};
#ifdef COBJMACROS
#define IFsrmQuotaManagerEx_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IFsrmQuotaManagerEx_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IFsrmQuotaManagerEx_Release(This) (This)->lpVtbl->Release(This)
#define IFsrmQuotaManagerEx_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl->GetTypeInfoCount(This,pctinfo)
#define IFsrmQuotaManagerEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl->GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define IFsrmQuotaManagerEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl->GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define IFsrmQuotaManagerEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl->Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define IFsrmQuotaManagerEx_get_ActionVariables(This,variables) (This)->lpVtbl->get_ActionVariables(This,variables)
#define IFsrmQuotaManagerEx_get_ActionVariableDescriptions(This,descriptions) (This)->lpVtbl->get_ActionVariableDescriptions(This,descriptions)
#define IFsrmQuotaManagerEx_CreateQuota(This,path,quota) (This)->lpVtbl->CreateQuota(This,path,quota)
#define IFsrmQuotaManagerEx_CreateAutoApplyQuota(This,quotaTemplateName,path,quota) (This)->lpVtbl->CreateAutoApplyQuota(This,quotaTemplateName,path,quota)
#define IFsrmQuotaManagerEx_GetQuota(This,path,quota) (This)->lpVtbl->GetQuota(This,path,quota)
#define IFsrmQuotaManagerEx_GetAutoApplyQuota(This,path,quota) (This)->lpVtbl->GetAutoApplyQuota(This,path,quota)
#define IFsrmQuotaManagerEx_GetRestrictiveQuota(This,path,quota) (This)->lpVtbl->GetRestrictiveQuota(This,path,quota)
#define IFsrmQuotaManagerEx_EnumQuotas(This,path,options,quotas) (This)->lpVtbl->EnumQuotas(This,path,options,quotas)
#define IFsrmQuotaManagerEx_EnumAutoApplyQuotas(This,path,options,quotas) (This)->lpVtbl->EnumAutoApplyQuotas(This,path,options,quotas)
#define IFsrmQuotaManagerEx_EnumEffectiveQuotas(This,path,options,quotas) (This)->lpVtbl->EnumEffectiveQuotas(This,path,options,quotas)
#define IFsrmQuotaManagerEx_Scan(This,strPath) (This)->lpVtbl->Scan(This,strPath)
#define IFsrmQuotaManagerEx_CreateQuotaCollection(This,collection) (This)->lpVtbl->CreateQuotaCollection(This,collection)
#define IFsrmQuotaManagerEx_IsAffectedByQuota(This,path,options,affected) (This)->lpVtbl->IsAffectedByQuota(This,path,options,affected)
#endif /*COBJMACROS*/

#endif /*(_WIN32_WINNT >= 0x0600)*/
#include <fsrmscreen.h>
#endif /*_INC_FSRMQUOTA*/
