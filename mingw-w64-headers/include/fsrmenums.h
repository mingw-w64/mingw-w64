/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FSRMENUMS
#define _INC_FSRMENUMS
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _FsrmAccountType {
  FsrmAccountType_Unknown          = 0,
  FsrmAccountType_NetworkService   = 1,
  FsrmAccountType_LocalService     = 2,
  FsrmAccountType_LocalSystem      = 3,
  FsrmAccountType_InProc           = 4,
  FsrmAccountType_External         = 5 
} FsrmAccountType;

typedef enum _FsrmActionType {
  FsrmActionType_Unknown    = 0,
  FsrmActionType_EventLog   = 1,
  FsrmActionType_Email      = 2,
  FsrmActionType_Command    = 3,
  FsrmActionType_Report     = 4 
} FsrmActionType;

typedef enum _FsrmClassificationLoggingFlags {
  FsrmClassificationLoggingFlags_None                         = 0x00000000,
  FsrmClassificationLoggingFlags_ClassificationsInLogFile     = 0x00000001,
  FsrmClassificationLoggingFlags_ErrorsInLogFile              = 0x00000002,
  FsrmClassificationLoggingFlags_ClassificationsInSystemLog   = 0x00000004,
  FsrmClassificationLoggingFlags_ErrorsInSystemLog            = 0x00000008 
} FsrmClassificationLoggingFlags;

typedef enum _FsrmCollectionState {
  FsrmCollectionState_Fetching     = 1,
  FsrmCollectionState_Committing   = 2,
  FsrmCollectionState_Complete     = 3,
  FsrmCollectionState_Cancelled    = 4 
} FsrmCollectionState;

typedef enum _FsrmCommitOptions {
  FsrmCommitOptions_None           = 0x00000000,
  FsrmCommitOptions_Asynchronous   = 0x00000001 
} FsrmCommitOptions;

typedef enum _FsrmEnumOptions {
  FsrmEnumOptions_None                  = 0x00000000,
  FsrmEnumOptions_Asynchronous          = 0x00000001,
  FsrmEnumOptions_CheckRecycleBin       = 0x00000002,
  FsrmEnumOptions_IncludeClusterNodes   = 0x00000004 
} FsrmEnumOptions;

typedef enum _FsrmEventType {
  FsrmEventType_Unknown       = 0,
  FsrmEventType_Information   = 1,
  FsrmEventType_Warning       = 2,
  FsrmEventType_Error         = 3 
} FsrmEventType;

typedef enum _FsrmExecutionOption {
  FsrmExecutionOption_Unknown                            = 0,
  FsrmExecutionOption_EvaluateUnset                      = 1,
  FsrmExecutionOption_ReEvaluate_ConsiderExistingValue   = 2,
  FsrmExecutionOption_ReEvaluate_IgnoreExistingValue     = 3 
} FsrmExecutionOption;

typedef enum _FsrmFileManagementLoggingFlags {
  FsrmFileManagementLoggingFlags_None          = 0x00000000,
  FsrmFileManagementLoggingFlags_Error         = 0x00000001,
  FsrmFileManagementLoggingFlags_Information   = 0x00000002,
  FsrmFileManagementLoggingFlags_Audit         = 0x00000004 
} FsrmFileManagementLoggingFlags;

typedef enum _FsrmFileManagementType {
  FsrmFileManagementType_Unknown      = 0,
  FsrmFileManagementType_Expiration   = 1,
  FsrmFileManagementType_Custom       = 2 
} FsrmFileManagementType;

typedef enum _FsrmFileStreamingInterfaceType {
  FsrmFileStreamingInterfaceType_Unknown      = 0x00000000,
  FsrmFileStreamingInterfaceType_ILockBytes   = 0x00000001,
  FsrmFileStreamingInterfaceType_IStream      = 0x00000002 
} FsrmFileStreamingInterfaceType;

typedef enum _FsrmFileStreamingMode {
  FsrmFileStreamingMode_Unknown   = 0x00000000,
  FsrmFileStreamingMode_Read      = 0x00000001,
  FsrmFileStreamingMode_Write     = 0x00000002 
} FsrmFileStreamingMode;

typedef enum _FsrmFileScreenFlags {
  FsrmFileScreenFlags_Enforce   = 0x00000001 
} FsrmFileScreenFlags;

typedef enum _FsrmPipelineModuleType {
  FsrmPipelineModuleType_Unknown      = 0,
  FsrmPipelineModuleType_Storage      = 1,
  FsrmPipelineModuleType_Classifier   = 2 
} FsrmPipelineModuleType;

typedef enum _FsrmPropertyBagFlags {
  FsrmPropertyBagFlags_UpdatedByClassifier           = 0x00000001,
  FsrmPropertyBagFlags_FailedLoadingProperties       = 0x00000002,
  FsrmPropertyBagFlags_FailedSavingProperties        = 0x00000004,
  FsrmPropertyBagFlags_FailedClassifyingProperties   = 0x00000008 
} FsrmPropertyBagFlags;

typedef enum _FsrmPropertyConditionType {
  FsrmPropertyConditionType_Unknown       = 0,
  FsrmPropertyConditionType_Equal         = 1,
  FsrmPropertyConditionType_NotEqual      = 2,
  FsrmPropertyConditionType_GreaterThan   = 3,
  FsrmPropertyConditionType_LessThan      = 4,
  FsrmPropertyConditionType_Contain       = 5,
  FsrmPropertyConditionType_Exist         = 6,
  FsrmPropertyConditionType_NotExist      = 7,
  FsrmPropertyConditionType_StartWith     = 8,
  FsrmPropertyConditionType_EndWith       = 9,
  FsrmPropertyConditionType_ContainedIn   = 10,
  FsrmPropertyConditionType_PrefixOf      = 11,
  FsrmPropertyConditionType_SuffixOf      = 12 
} FsrmPropertyConditionType;

typedef enum _FsrmPropertyDefinitionType {
  FsrmPropertyDefinitionType_Unknown           = 0,
  FsrmPropertyDefinitionType_OrderedList       = 1,
  FsrmPropertyDefinitionType_MultiChoiceList   = 2,
  FsrmPropertyDefinitionType_String            = 4,
  FsrmPropertyDefinitionType_MultiString       = 5,
  FsrmPropertyDefinitionType_Int               = 6,
  FsrmPropertyDefinitionType_Bool              = 7,
  FsrmPropertyDefinitionType_Date              = 8 
} FsrmPropertyDefinitionType;

typedef enum _FsrmPropertyFlags {
  FsrmPropertyFlags_Orphaned                      = 0x00000001,
  FsrmPropertyFlags_RetrievedFromCache            = 0x00000002,
  FsrmPropertyFlags_RetrievedFromStorage          = 0x00000004,
  FsrmPropertyFlags_SetByClassifier               = 0x00000008,
  FsrmPropertyFlags_Deleted                       = 0x00000010,
  FsrmPropertyFlags_Reclassified                  = 0x00000020,
  FsrmPropertyFlags_AggregationFailed             = 0x00000040,
  FsrmPropertyFlags_Existing                      = 0x00000080,
  FsrmPropertyFlags_FailedLoadingProperties       = 0x00000100,
  FsrmPropertyFlags_FailedClassifyingProperties   = 0x00000200,
  FsrmPropertyFlags_PropertySourceMask            = 0x0000000E 
} FsrmPropertyFlags;

typedef enum _FsrmQuotaFlags {
  FsrmQuotaFlags_Enforce            = 0x00000100,
  FsrmQuotaFlags_Disable            = 0x00000200,
  FsrmQuotaFlags_StatusIncomplete   = 0x00010000,
  FsrmQuotaFlags_StatusRebuilding   = 0x00020000 
} FsrmQuotaFlags;

typedef enum _FsrmReportFilter {
  FsrmReportFilter_MinSize         = 1,
  FsrmReportFilter_MinAgeDays      = 2,
  FsrmReportFilter_MaxAgeDays      = 3,
  FsrmReportFilter_MinQuotaUsage   = 4,
  FsrmReportFilter_FileGroups      = 5,
  FsrmReportFilter_Owners          = 6,
  FsrmReportFilter_NamePattern     = 7,
  FsrmReportFilter_Property        = 8 
} FsrmReportFilter;

typedef enum _FsrmReportFormat {
  FsrmReportFormat_Unknown   = 0,
  FsrmReportFormat_DHtml     = 1,
  FsrmReportFormat_Html      = 2,
  FsrmReportFormat_Txt       = 3,
  FsrmReportFormat_Csv       = 4,
  FsrmReportFormat_Xml       = 5 
} FsrmReportFormat;

typedef enum _FsrmReportGenerationContext {
  FsrmReportGenerationContext_Undefined           = 1,
  FsrmReportGenerationContext_ScheduledReport     = 2,
  FsrmReportGenerationContext_InteractiveReport   = 3,
  FsrmReportGenerationContext_IncidentReport      = 4 
} FsrmReportGenerationContext;

typedef enum _FsrmReportLimit {
  FsrmReportLimit_MaxFiles                   = 1,
  FsrmReportLimit_MaxFileGroups              = 2,
  FsrmReportLimit_MaxOwners                  = 3,
  FsrmReportLimit_MaxFilesPerFileGroup       = 4,
  FsrmReportLimit_MaxFilesPerOwner           = 5,
  FsrmReportLimit_MaxFilesPerDuplGroup       = 6,
  FsrmReportLimit_MaxDuplicateGroups         = 7,
  FsrmReportLimit_MaxQuotas                  = 8,
  FsrmReportLimit_MaxFileScreenEvents        = 9,
  FsrmReportLimit_MaxPropertyValues          = 10,
  FsrmReportLimit_MaxFilesPerPropertyValue   = 11 
} FsrmReportLimit;

typedef enum _FsrmReportRunningStatus {
  FsrmReportRunningStatus_Unknown      = 0,
  FsrmReportRunningStatus_NotRunning   = 1,
  FsrmReportRunningStatus_Queued       = 2,
  FsrmReportRunningStatus_Running      = 3 
} FsrmReportRunningStatus;

typedef enum _FsrmReportType {
  FsrmReportType_Unknown                   = 0,
  FsrmReportType_LargeFiles                = 1,
  FsrmReportType_FilesByType               = 2,
  FsrmReportType_LeastRecentlyAccessed     = 3,
  FsrmReportType_MostRecentlyAccessed      = 4,
  FsrmReportType_QuotaUsage                = 5,
  FsrmReportType_FilesByOwner              = 6,
  FsrmReportType_ExportReport              = 7,
  FsrmReportType_DuplicateFiles            = 8,
  FsrmReportType_FileScreenAudit           = 9,
  FsrmReportType_FilesByProperty           = 10,
  FsrmReportType_AutomaticClassification   = 11,
  FsrmReportType_Expiration                = 12 
} FsrmReportType;

typedef enum _FsrmRuleFlags {
  FsrmRuleFlags_Disabled   = 0x00000100,
  FsrmRuleFlags_Invalid    = 0x00001000 
} FsrmRuleFlags;

typedef enum _FsrmRuleType {
  FsrmRuleType_Unknown          = 0,
  FsrmRuleType_Classification   = 1,
  FsrmRuleType_Generic          = 2 
} FsrmRuleType;

typedef enum _FsrmStorageModuleCaps {
  FsrmStorageModuleCaps_Unknown   = 0x00000000,
  FsrmStorageModuleCaps_CanGet    = 0x00000001,
  FsrmStorageModuleCaps_CanSet    = 0x00000002 
} FsrmStorageModuleCaps;

typedef enum _FsrmStorageModuleType {
  FsrmStorageModuleType_Unknown    = 0,
  FsrmStorageModuleType_Cache      = 1,
  FsrmStorageModuleType_InFile     = 2,
  FsrmStorageModuleType_Database   = 3 
} FsrmStorageModuleType;

typedef enum _FsrmTemplateApplyOptions {
  FsrmTemplateApplyOptions_ApplyToDerivedMatching   = 1,
  FsrmTemplateApplyOptions_ApplyToDerivedAll        = 2 
} FsrmTemplateApplyOptions;

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_FSRMENUMS*/
