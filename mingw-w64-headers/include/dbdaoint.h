/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _DBDAOINT_H_
#define _DBDAOINT_H_

#include <tchar.h>

struct _DAODBEngine;
#define DAODBEngine _DAODBEngine
struct DAOError;
struct _DAOCollection;
#define DAOCollection _DAOCollection
struct DAOErrors;
struct DAOProperty;
struct _DAODynaCollection;
#define DAODynaCollection _DAODynaCollection
struct DAOProperties;
struct DAOWorkspace;
struct DAOWorkspaces;
struct DAOConnection;
struct DAOConnections;
struct DAODatabase;
struct DAODatabases;
struct _DAOTableDef;
#define DAOTableDef _DAOTableDef
struct DAOTableDefs;
struct _DAOQueryDef;
#define DAOQueryDef _DAOQueryDef
struct DAOQueryDefs;
struct DAORecordset;
struct DAORecordsets;
struct _DAOField;
#define DAOField _DAOField
struct DAOFields;
struct _DAOIndex;
#define DAOIndex _DAOIndex
struct DAOIndexes;
struct DAOParameter;
struct DAOParameters;
struct _DAOUser;
#define DAOUser _DAOUser
struct DAOUsers;
struct _DAOGroup;
#define DAOGroup _DAOGroup
struct DAOGroups;
struct _DAORelation;
#define DAORelation _DAORelation
struct DAORelations;
struct DAOContainer;
struct DAOContainers;
struct DAODocument;
struct DAODocuments;
struct DAOIndexFields;

typedef enum RecordsetTypeEnum {
  dbOpenTable = 1,dbOpenDynaset = 2,dbOpenSnapshot = 4,dbOpenForwardOnly = 8,dbOpenDynamic = 16
} RecordsetTypeEnum;

typedef enum EditModeEnum {
  dbEditNone = 0,dbEditInProgress = 1,dbEditAdd = 2,dbEditChanged = 4,dbEditDeleted = 8,dbEditNew = 16
} EditModeEnum;

typedef enum RecordsetOptionEnum {
  dbDenyWrite = 0x1,dbDenyRead = 0x2,dbReadOnly = 0x4,dbAppendOnly = 0x8,dbInconsistent = 0x10,dbConsistent = 0x20,dbSQLPassThrough = 0x40,
  dbFailOnError = 0x80,dbForwardOnly = 0x100,dbSeeChanges = 0x200,dbRunAsync = 0x400,dbExecDirect = 0x800
} RecordsetOptionEnum;

typedef enum LockTypeEnum {
  dbPessimistic = 0x2,dbOptimistic = 0x3,dbOptimisticValue = 0x1,dbOptimisticBatch = 0x5
} LockTypeEnum;

typedef enum UpdateCriteriaEnum {
  dbCriteriaKey = 0x1,dbCriteriaModValues = 0x2,dbCriteriaAllCols = 0x4,dbCriteriaTimestamp = 0x8,dbCriteriaDeleteInsert = 0x10,
  dbCriteriaUpdate = 0x20
} UpdateCriteriaEnum;

typedef enum FieldAttributeEnum {
  dbFixedField = 0x1,dbVariableField = 0x2,dbAutoIncrField = 0x10,dbUpdatableField = 0x20,dbSystemField = 0x2000,dbHyperlinkField = 0x8000,
  dbDescending = 0x1
} FieldAttributeEnum;

typedef enum DataTypeEnum {
  dbBoolean = 1,dbByte = 2,dbInteger = 3,dbLong = 4,dbCurrency = 5,dbSingle = 6,dbDouble = 7,dbDate = 8,dbBinary = 9,dbText = 10,
  dbLongBinary = 11,dbMemo = 12,dbGUID = 15,dbBigInt = 16,dbVarBinary = 17,dbChar = 18,dbNumeric = 19,dbDecimal = 20,dbFloat = 21,
  dbTime = 22,dbTimeStamp = 23
} DataTypeEnum;

typedef enum RelationAttributeEnum {
  dbRelationUnique = 0x1,dbRelationDontEnforce = 0x2,dbRelationInherited = 0x4,dbRelationUpdateCascade = 0x100,dbRelationDeleteCascade = 0x1000,
  dbRelationLeft = 0x1000000,dbRelationRight = 0x2000000
} RelationAttributeEnum;

typedef enum TableDefAttributeEnum {
  dbAttachExclusive = 0x10000,dbAttachSavePWD = 0x20000,dbSystemObject = 0x80000002,dbAttachedTable = 0x40000000,dbAttachedODBC = 0x20000000,
  dbHiddenObject = 0x1
} TableDefAttributeEnum;

typedef enum QueryDefTypeEnum {
  dbQSelect = 0,dbQProcedure = 0xe0,dbQAction = 0xf0,dbQCrosstab = 0x10,dbQDelete = 0x20,dbQUpdate = 0x30,dbQAppend = 0x40,
  dbQMakeTable = 0x50,dbQDDL = 0x60,dbQSQLPassThrough = 0x70,dbQSetOperation = 0x80,dbQSPTBulk = 0x90,dbQCompound = 0xa0
} QueryDefTypeEnum;

typedef enum QueryDefStateEnum {
  dbQPrepare = 1,dbQUnprepare = 2
} QueryDefStateEnum;

typedef enum DatabaseTypeEnum {
  dbVersion10 = 1,dbEncrypt = 2,dbDecrypt = 4,dbVersion11 = 8,dbVersion20 = 16,dbVersion30 = 32,dbVersion40 = 64
} DatabaseTypeEnum;

typedef enum CollatingOrderEnum {
  dbSortNeutral = 0x400,dbSortArabic = 0x401,dbSortCyrillic = 0x419,dbSortCzech = 0x405,dbSortDutch = 0x413,dbSortGeneral = 0x409,
  dbSortGreek = 0x408,dbSortHebrew = 0x40d,dbSortHungarian = 0x40e,dbSortIcelandic = 0x40f,dbSortNorwdan = 0x406,dbSortPDXIntl = 0x409,
  dbSortPDXNor = 0x406,dbSortPDXSwe = 0x41d,dbSortPolish = 0x415,dbSortSpanish = 0x40a,dbSortSwedFin = 0x41d,dbSortTurkish = 0x41f,
  dbSortJapanese = 0x411,dbSortChineseSimplified = 0x804,dbSortChineseTraditional = 0x404,dbSortKorean = 0x412,dbSortThai = 0x41e,
  dbSortSlovenian = 0x424,dbSortUndefined = -1
} CollatingOrderEnum;

typedef enum IdleEnum {
  dbFreeLocks = 1,dbRefreshCache = 8
} IdleEnum;

typedef enum PermissionEnum {
  dbSecNoAccess = 0,dbSecFullAccess = 0xfffff,dbSecDelete = 0x10000,dbSecReadSec = 0x20000,dbSecWriteSec = 0x40000,dbSecWriteOwner = 0x80000,
  dbSecDBCreate = 0x1,dbSecDBOpen = 0x2,dbSecDBExclusive = 0x4,dbSecDBAdmin = 0x8,dbSecCreate = 0x1,dbSecReadDef = 0x4,dbSecWriteDef = 0x1000c,
  dbSecRetrieveData = 0x14,dbSecInsertData = 0x20,dbSecReplaceData = 0x40,dbSecDeleteData = 0x80
} PermissionEnum;

typedef enum SynchronizeTypeEnum {
  dbRepExportChanges = 0x1,dbRepImportChanges = 0x2,dbRepImpExpChanges = 0x4,dbRepSyncInternet = 0x10
} SynchronizeTypeEnum;

typedef enum ReplicaTypeEnum {
  dbRepMakeReadOnly = 0x2,dbRepMakePartial = 0x1
} ReplicaTypeEnum;

typedef enum WorkspaceTypeEnum {
  dbUseODBC = 1,dbUseJet = 2
} WorkspaceTypeEnum;

typedef enum CursorDriverEnum {
  dbUseDefaultCursor = -1,dbUseODBCCursor = 1,dbUseServerCursor = 2,dbUseClientBatchCursor = 3,dbUseNoCursor = 4
} CursorDriverEnum;

typedef enum DriverPromptEnum {
  dbDriverPrompt = 2,dbDriverNoPrompt = 1,dbDriverComplete = 0,dbDriverCompleteRequired = 3
} DriverPromptEnum;

typedef enum SetOptionEnum {
  dbPageTimeout = 6,dbLockRetry = 57,dbMaxBufferSize = 8,dbUserCommitSync = 58,dbImplicitCommitSync = 59,dbExclusiveAsyncDelay = 60,
  dbSharedAsyncDelay = 61,dbMaxLocksPerFile = 62,dbLockDelay = 63,dbRecycleLVs = 65,dbFlushTransactionTimeout = 66
} SetOptionEnum;

typedef enum ParameterDirectionEnum {
  dbParamInput = 1,dbParamOutput = 2,dbParamInputOutput = 3,dbParamReturnValue = 4
} ParameterDirectionEnum;

typedef enum UpdateTypeEnum {
  dbUpdateBatch = 4,dbUpdateRegular = 1,dbUpdateCurrentRecord = 2
} UpdateTypeEnum;

typedef enum RecordStatusEnum {
  dbRecordUnmodified = 0,dbRecordModified = 1,dbRecordNew = 2,dbRecordDeleted = 3,dbRecordDBDeleted = 4
} RecordStatusEnum;

typedef enum CommitTransOptionsEnum {
  dbForceOSFlush = 1
} CommitTransOptionsEnum;

typedef enum _DAOSuppHelp {
  LogMessages = 0,KeepLocal = 0,Replicable = 0,ReplicableBool = 0,V1xNullBehavior = 0
} _DAOSuppHelp;

#define dbLangArabic _T(";LANGID=0x0401;CP=1256;COUNTRY=0")
#define dbLangCzech _T(";LANGID=0x0405;CP=1250;COUNTRY=0")
#define dbLangDutch _T(";LANGID=0x0413;CP=1252;COUNTRY=0")
#define dbLangGeneral _T(";LANGID=0x0409;CP=1252;COUNTRY=0")
#define dbLangGreek _T(";LANGID=0x0408;CP=1253;COUNTRY=0")
#define dbLangHebrew _T(";LANGID=0x040D;CP=1255;COUNTRY=0")
#define dbLangHungarian _T(";LANGID=0x040E;CP=1250;COUNTRY=0")
#define dbLangIcelandic _T(";LANGID=0x040F;CP=1252;COUNTRY=0")
#define dbLangNordic _T(";LANGID=0x041D;CP=1252;COUNTRY=0")
#define dbLangNorwDan _T(";LANGID=0x0414;CP=1252;COUNTRY=0")
#define dbLangPolish _T(";LANGID=0x0415;CP=1250;COUNTRY=0")
#define dbLangCyrillic _T(";LANGID=0x0419;CP=1251;COUNTRY=0")
#define dbLangSpanish _T(";LANGID=0x040A;CP=1252;COUNTRY=0")
#define dbLangSwedFin _T(";LANGID=0x040B;CP=1252;COUNTRY=0")
#define dbLangTurkish _T(";LANGID=0x041F;CP=1254;COUNTRY=0")
#define dbLangJapanese _T(";LANGID=0x0411;CP=932;COUNTRY=0")
#define dbLangChineseSimplified _T(";LANGID=0x0804;CP=936;COUNTRY=0")
#define dbLangChineseTraditional _T(";LANGID=0x0404;CP=950;COUNTRY=0")
#define dbLangKorean _T(";LANGID=0x0412;CP=949;COUNTRY=0")
#define dbLangThai _T(";LANGID=0x041E;CP=874;COUNTRY=0")
#define dbLangSlovenian _T(";LANGID=0x0424;CP=1250;COUNTRY=0")

#undef INTERFACE
#define INTERFACE _DAOCollection
DECLARE_INTERFACE_(_DAOCollection,IDispatch) {
  STDMETHOD(get_Count) (THIS_ short *c) PURE;
  STDMETHOD(_NewEnum) (THIS_ IUnknown **ppunk) PURE;
  STDMETHOD(Refresh) (THIS) PURE;
};

#undef INTERFACE
#define INTERFACE _DAODynaCollection
DECLARE_INTERFACE_(_DAODynaCollection,_DAOCollection) {
  STDMETHOD(Append) (THIS_ IDispatch *Object) PURE;
  STDMETHOD(Delete) (THIS_ BSTR Name) PURE;
};

#undef INTERFACE
#define INTERFACE _DAO
DECLARE_INTERFACE_(_DAO,IDispatch) {
  STDMETHOD(get_Properties) (THIS_ DAOProperties **ppprops) PURE;
};

#undef INTERFACE
#define INTERFACE _DAODBEngine
DECLARE_INTERFACE_(_DAODBEngine,_DAO) {
  STDMETHOD(get_Properties) (DAOProperties **ppprops);
  STDMETHOD(get_Version) (BSTR *pbstr) PURE;
  STDMETHOD(get_IniPath) (BSTR *pbstr) PURE;
  STDMETHOD(put_IniPath) (BSTR path) PURE;
  STDMETHOD(put_DefaultUser) (BSTR user) PURE;
  STDMETHOD(put_DefaultPassword) (BSTR pw) PURE;
  STDMETHOD(get_LoginTimeout) (short *ps) PURE;
  STDMETHOD(put_LoginTimeout) (short Timeout) PURE;
  STDMETHOD(get_Workspaces) (DAOWorkspaces **ppworks) PURE;
  STDMETHOD(get_Errors) (DAOErrors **pperrs) PURE;
  STDMETHOD(Idle) (VARIANT Action) PURE;
  STDMETHOD(CompactDatabase) (BSTR SrcName,BSTR DstName,VARIANT DstLocale,VARIANT Options,VARIANT SrcLocale) PURE;
  STDMETHOD(RepairDatabase) (BSTR Name) PURE;
  STDMETHOD(RegisterDatabase) (BSTR Dsn,BSTR Driver,VARIANT_BOOL Silent,BSTR Attributes) PURE;
  STDMETHOD(_30_CreateWorkspace) (BSTR Name,BSTR UserName,BSTR Password,DAOWorkspace **ppwrk) PURE;
  STDMETHOD(OpenDatabase) (BSTR Name,VARIANT Options,VARIANT ReadOnly,VARIANT Connect,DAODatabase **ppdb) PURE;
  STDMETHOD(CreateDatabase) (BSTR Name,BSTR Locale,VARIANT Option,DAODatabase **ppdb) PURE;
  STDMETHOD(FreeLocks) (VOID) PURE;
  STDMETHOD(BeginTrans) (VOID) PURE;
  STDMETHOD(CommitTrans) (long Option) PURE;
  STDMETHOD(Rollback) (VOID) PURE;
  STDMETHOD(SetDefaultWorkspace) (BSTR Name,BSTR Password) PURE;
  STDMETHOD(SetDataAccessOption) (short Option,VARIANT Value) PURE;
  STDMETHOD(ISAMStats) (long StatNum,VARIANT Reset,long *pl) PURE;
  STDMETHOD(get_SystemDB) (BSTR *pbstr) PURE;
  STDMETHOD(put_SystemDB) (BSTR SystemDBPath) PURE;
  STDMETHOD(CreateWorkspace) (BSTR Name,BSTR UserName,BSTR Password,VARIANT UseType,DAOWorkspace **ppwrk) PURE;
  STDMETHOD(OpenConnection) (BSTR Name,VARIANT Options,VARIANT ReadOnly,VARIANT Connect,DAOConnection **ppconn) PURE;
  STDMETHOD(get_DefaultType) (long *Option) PURE;
  STDMETHOD(put_DefaultType) (long Option) PURE;
  STDMETHOD(SetOption) (LONG Option,VARIANT Value) PURE;
  STDMETHOD(DumpObjects) (BSTR *pbstr) PURE;
  STDMETHOD(DebugPrint) (BSTR bstr) PURE;
};

#undef INTERFACE
#define INTERFACE DAOError
DECLARE_INTERFACE_(DAOError,IDispatch) {
  STDMETHOD(get_Number) (long *pl) PURE;
  STDMETHOD(get_Source) (BSTR *pbstr) PURE;
  STDMETHOD(get_Description) (BSTR *pbstr) PURE;
  STDMETHOD(get_HelpFile) (BSTR *pbstr) PURE;
  STDMETHOD(get_HelpContext) (long *pl) PURE;
};

#undef INTERFACE
#define INTERFACE DAOErrors
DECLARE_INTERFACE_(DAOErrors,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOError **pperr) PURE;
};

#undef INTERFACE
#define INTERFACE DAOProperty
DECLARE_INTERFACE_(DAOProperty,_DAO) {
  STDMETHOD(get_Value) (VARIANT *pval) PURE;
  STDMETHOD(put_Value) (VARIANT val) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(get_Type) (short *ptype) PURE;
  STDMETHOD(put_Type) (short type) PURE;
  STDMETHOD(get_Inherited) (VARIANT_BOOL *pb) PURE;
};

#undef INTERFACE
#define INTERFACE DAOProperties
DECLARE_INTERFACE_(DAOProperties,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOProperty **ppprop) PURE;
};

#undef INTERFACE
#define INTERFACE DAOWorkspace
DECLARE_INTERFACE_(DAOWorkspace,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR Name) PURE;
  STDMETHOD(get_UserName) (BSTR *pbstr) PURE;
  STDMETHOD(put__30_UserName) (BSTR UserName) PURE;
  STDMETHOD(put__30_Password) (BSTR Password) PURE;
  STDMETHOD(get_IsolateODBCTrans) (short *ps) PURE;
  STDMETHOD(put_IsolateODBCTrans) (short s) PURE;
  STDMETHOD(get_Databases) (DAODatabases **ppdbs) PURE;
  STDMETHOD(get_Users) (DAOUsers **ppusrs) PURE;
  STDMETHOD(get_Groups) (DAOGroups **ppgrps) PURE;
  STDMETHOD(BeginTrans) (VOID) PURE;
  STDMETHOD(CommitTrans) (long Options) PURE;
  STDMETHOD(Close) (VOID) PURE;
  STDMETHOD(Rollback) (VOID) PURE;
  STDMETHOD(OpenDatabase) (BSTR Name,VARIANT Options,VARIANT ReadOnly,VARIANT Connect,DAODatabase **ppdb) PURE;
  STDMETHOD(CreateDatabase) (BSTR Name,BSTR Connect,VARIANT Option,DAODatabase **ppdb) PURE;
  STDMETHOD(CreateUser) (VARIANT Name,VARIANT PID,VARIANT Password,DAOUser **ppusr) PURE;
  STDMETHOD(CreateGroup) (VARIANT Name,VARIANT PID,DAOGroup **ppgrp) PURE;
  STDMETHOD(OpenConnection) (BSTR Name,VARIANT Options,VARIANT ReadOnly,VARIANT Connect,DAOConnection **ppconn) PURE;
  STDMETHOD(get_LoginTimeout) (long *pTimeout) PURE;
  STDMETHOD(put_LoginTimeout) (long Timeout) PURE;
  STDMETHOD(get_DefaultCursorDriver) (long *pCursorType) PURE;
  STDMETHOD(put_DefaultCursorDriver) (long CursorType) PURE;
  STDMETHOD(get_hEnv) (LONG *phEnv) PURE;
  STDMETHOD(get_Type) (LONG *ptype) PURE;
  STDMETHOD(get_Connections) (DAOConnections **ppcns) PURE;
};

#undef INTERFACE
#define INTERFACE DAOWorkspaces
DECLARE_INTERFACE_(DAOWorkspaces,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOWorkspace **ppwrk) PURE;
};

#undef INTERFACE
#define INTERFACE DAOConnection
DECLARE_INTERFACE_(DAOConnection,IDispatch) {
  STDMETHOD(QueryInterface) (REFIID riid,LPVOID *ppvObj);
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_Connect) (BSTR *pbstr) PURE;
  STDMETHOD(get_Database) (DAODatabase **ppDb) PURE;
  STDMETHOD(get_hDbc) (LONG *phDbc) PURE;
  STDMETHOD(get_QueryTimeout) (SHORT *pSeconds) PURE;
  STDMETHOD(put_QueryTimeout) (SHORT Seconds) PURE;
  STDMETHOD(get_Transactions) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_RecordsAffected) (LONG *pRecords) PURE;
  STDMETHOD(get_StillExecuting) (VARIANT_BOOL *pStillExec) PURE;
  STDMETHOD(get_Updatable) (VARIANT_BOOL *pStillExec) PURE;
  STDMETHOD(get_QueryDefs) (DAOQueryDefs **ppqdfs) PURE;
  STDMETHOD(get_Recordsets) (DAORecordsets **pprsts) PURE;
  STDMETHOD(Cancel) (VOID) PURE;
  STDMETHOD(Close) (VOID) PURE;
  STDMETHOD(CreateQueryDef) (VARIANT Name,VARIANT SQLText,DAOQueryDef **ppqdf) PURE;
  STDMETHOD(Execute) (BSTR Query,VARIANT Options) PURE;
  STDMETHOD(OpenRecordset) (BSTR Name,VARIANT Type,VARIANT Options,VARIANT LockEdit,DAORecordset **pprst) PURE;
};

#undef INTERFACE
#define INTERFACE DAOConnections
DECLARE_INTERFACE_(DAOConnections,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOConnection **ppconn) PURE;
};

#undef INTERFACE
#define INTERFACE DAODatabase
DECLARE_INTERFACE_(DAODatabase,_DAO) {
  STDMETHOD(get_CollatingOrder) (LONG *pl) PURE;
  STDMETHOD(get_Connect) (BSTR *pbstr) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_QueryTimeout) (short *ps) PURE;
  STDMETHOD(put_QueryTimeout) (short Timeout) PURE;
  STDMETHOD(get_Transactions) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Updatable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Version) (BSTR *pbstr) PURE;
  STDMETHOD(get_RecordsAffected) (long *pl) PURE;
  STDMETHOD(get_TableDefs) (DAOTableDefs **pptdfs) PURE;
  STDMETHOD(get_QueryDefs) (DAOQueryDefs **ppqdfs) PURE;
  STDMETHOD(get_Relations) (DAORelations **pprls) PURE;
  STDMETHOD(get_Containers) (DAOContainers **ppctns) PURE;
  STDMETHOD(get_Recordsets) (DAORecordsets **pprsts) PURE;
  STDMETHOD(Close) (VOID) PURE;
  STDMETHOD(Execute) (BSTR Query,VARIANT Options) PURE;
  STDMETHOD(_30_OpenRecordset) (BSTR Name,VARIANT Type,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
  STDMETHOD(CreateRelation) (VARIANT Name,VARIANT Table,VARIANT ForeignTable,VARIANT Attributes,DAORelation **pprel) PURE;
  STDMETHOD(CreateTableDef) (VARIANT Name,VARIANT Attributes,VARIANT SourceTablename,VARIANT Connect,DAOTableDef **pptdf) PURE;
  STDMETHOD(BeginTrans) (VOID) PURE;
  STDMETHOD(CommitTrans) (long Options) PURE;
  STDMETHOD(Rollback) (VOID) PURE;
  STDMETHOD(CreateDynaset) (BSTR Name,VARIANT Options,VARIANT Inconsistent,DAORecordset **pprst) PURE;
  STDMETHOD(CreateQueryDef) (VARIANT Name,VARIANT SQLText,DAOQueryDef **ppqdf) PURE;
  STDMETHOD(CreateSnapshot) (BSTR Source,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(DeleteQueryDef) (BSTR Name) PURE;
  STDMETHOD(ExecuteSQL) (BSTR SQL,long *pl) PURE;
  STDMETHOD(ListFields) (BSTR Name,DAORecordset **pprst) PURE;
  STDMETHOD(ListTables) (DAORecordset **pprst) PURE;
  STDMETHOD(OpenQueryDef) (BSTR Name,DAOQueryDef **ppqdf) PURE;
  STDMETHOD(OpenTable) (BSTR Name,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(get_ReplicaID) (BSTR *pbstr) PURE;
  STDMETHOD(get_DesignMasterID) (BSTR *pbstr) PURE;
  STDMETHOD(put_DesignMasterID) (BSTR MasterID) PURE;
  STDMETHOD(Synchronize) (BSTR DbPathName,VARIANT ExchangeType) PURE;
  STDMETHOD(MakeReplica) (BSTR PathName,BSTR Description,VARIANT Options) PURE;
  STDMETHOD(put_Connect) (BSTR ODBCConnnect) PURE;
  STDMETHOD(NewPassword) (BSTR bstrOld,BSTR bstrNew) PURE;
  STDMETHOD(OpenRecordset) (BSTR Name,VARIANT Type,VARIANT Options,VARIANT LockEdit,DAORecordset **pprst) PURE;
  STDMETHOD(get_Connection) (DAOConnection **ppCn) PURE;
  STDMETHOD(PopulatePartial) (BSTR DbPathName) PURE;
};

#undef INTERFACE
#define INTERFACE DAODatabases
DECLARE_INTERFACE_(DAODatabases,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAODatabase **ppdb) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOTableDef
DECLARE_INTERFACE_(_DAOTableDef,_DAO) {
  STDMETHOD(get_Attributes) (long *pl) PURE;
  STDMETHOD(put_Attributes) (long Attributes) PURE;
  STDMETHOD(get_Connect) (BSTR *pbstr) PURE;
  STDMETHOD(put_Connect) (BSTR Connection) PURE;
  STDMETHOD(get_DateCreated) (VARIANT *pvar) PURE;
  STDMETHOD(get_LastUpdated) (VARIANT *pvar) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR Name) PURE;
  STDMETHOD(get_SourceTableName) (BSTR *pbstr) PURE;
  STDMETHOD(put_SourceTableName) (BSTR bstr) PURE;
  STDMETHOD(get_Updatable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_ValidationText) (BSTR *pbstr) PURE;
  STDMETHOD(put_ValidationText) (BSTR bstr) PURE;
  STDMETHOD(get_ValidationRule) (BSTR *pbstr) PURE;
  STDMETHOD(put_ValidationRule) (BSTR bstr) PURE;
  STDMETHOD(get_RecordCount) (long *pl) PURE;
  STDMETHOD(get_Fields) (DAOFields **ppflds) PURE;
  STDMETHOD(get_Indexes) (DAOIndexes **ppidxs) PURE;
  STDMETHOD(OpenRecordset) (VARIANT Type,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(RefreshLink) (VOID) PURE;
  STDMETHOD(CreateField) (VARIANT Name,VARIANT Type,VARIANT Size,DAOField **ppfld) PURE;
  STDMETHOD(CreateIndex) (VARIANT Name,DAOIndex **ppidx) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
  STDMETHOD(get_ConflictTable) (BSTR *pbstr) PURE;
  STDMETHOD(get_ReplicaFilter) (VARIANT *pFilter) PURE;
  STDMETHOD(put_ReplicaFilter) (VARIANT Filter) PURE;
};

#undef INTERFACE
#define INTERFACE DAOTableDefs
DECLARE_INTERFACE_(DAOTableDefs,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOTableDef **pptdf) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOQueryDef
DECLARE_INTERFACE_(_DAOQueryDef,_DAO) {
  STDMETHOD(get_DateCreated) (VARIANT *pvar) PURE;
  STDMETHOD(get_LastUpdated) (VARIANT *pvar) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(get_ODBCTimeout) (short *ps) PURE;
  STDMETHOD(put_ODBCTimeout) (short timeout) PURE;
  STDMETHOD(get_Type) (short *pi) PURE;
  STDMETHOD(get_SQL) (BSTR *pbstr) PURE;
  STDMETHOD(put_SQL) (BSTR bstr) PURE;
  STDMETHOD(get_Updatable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Connect) (BSTR *pbstr) PURE;
  STDMETHOD(put_Connect) (BSTR bstr) PURE;
  STDMETHOD(get_ReturnsRecords) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_ReturnsRecords) (VARIANT_BOOL f) PURE;
  STDMETHOD(get_RecordsAffected) (long *pl) PURE;
  STDMETHOD(get_Fields) (DAOFields **ppflds) PURE;
  STDMETHOD(get_Parameters) (DAOParameters **ppprms) PURE;
  STDMETHOD(Close) (VOID) PURE;
  STDMETHOD(_30_OpenRecordset) (VARIANT Type,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(_30__OpenRecordset) (VARIANT Type,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(_Copy) (DAOQueryDef **ppqdf) PURE;
  STDMETHOD(Execute) (VARIANT Options) PURE;
  STDMETHOD(Compare) (DAOQueryDef *pQdef,SHORT *lps) PURE;
  STDMETHOD(CreateDynaset) (VARIANT Options,VARIANT Inconsistent,DAORecordset **pprst) PURE;
  STDMETHOD(CreateSnapshot) (VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(ListParameters) (DAORecordset **pprst) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
  STDMETHOD(OpenRecordset) (VARIANT Type,VARIANT Options,VARIANT LockEdit,DAORecordset **pprst) PURE;
  STDMETHOD(_OpenRecordset) (VARIANT Type,VARIANT Options,VARIANT LockEdit,DAORecordset **pprst) PURE;
  STDMETHOD(Cancel) (VOID) PURE;
  STDMETHOD(get_hStmt) (LONG *phStmt) PURE;
  STDMETHOD(get_MaxRecords) (LONG *pMxRecs) PURE;
  STDMETHOD(put_MaxRecords) (LONG MxRecs) PURE;
  STDMETHOD(get_StillExecuting) (VARIANT_BOOL *pStillExec) PURE;
  STDMETHOD(get_CacheSize) (long *lCacheSize) PURE;
  STDMETHOD(put_CacheSize) (long lCacheSize) PURE;
  STDMETHOD(get_Prepare) (VARIANT *pb) PURE;
  STDMETHOD(put_Prepare) (VARIANT f) PURE;
};

#undef INTERFACE
#define INTERFACE DAOQueryDefs
DECLARE_INTERFACE_(DAOQueryDefs,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOQueryDef **ppqdef) PURE;
};

#undef INTERFACE
#define INTERFACE DAORecordset
DECLARE_INTERFACE_(DAORecordset,_DAO) {
  STDMETHOD(GetIDsOfNames) (REFIID riid,OLECHAR **rgszNames,UINT cNames,LCID lcid,DISPID *rgdispid);
  STDMETHOD(Invoke) (DISPID dispidMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pdispparams,VARIANT *pvarResult,EXCEPINFO *pexcepinfo,UINT *puArgErr);
  STDMETHOD(get_BOF) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Bookmark) (SAFEARRAY **ppsach) PURE;
  STDMETHOD(put_Bookmark) (SAFEARRAY **psach) PURE;
  STDMETHOD(get_Bookmarkable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_DateCreated) (VARIANT *pvar) PURE;
  STDMETHOD(get_EOF) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Filter) (BSTR *pbstr) PURE;
  STDMETHOD(put_Filter) (BSTR Filter) PURE;
  STDMETHOD(get_Index) (BSTR *pbstr) PURE;
  STDMETHOD(put_Index) (BSTR bstr) PURE;
  STDMETHOD(get_LastModified) (SAFEARRAY **ppsa) PURE;
  STDMETHOD(get_LastUpdated) (VARIANT *pvar) PURE;
  STDMETHOD(get_LockEdits) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_LockEdits) (VARIANT_BOOL Lock) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_NoMatch) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Sort) (BSTR *pbstr) PURE;
  STDMETHOD(put_Sort) (BSTR Sort) PURE;
  STDMETHOD(get_Transactions) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Type) (short *ps) PURE;
  STDMETHOD(get_RecordCount) (long *pl) PURE;
  STDMETHOD(get_Updatable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Restartable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_ValidationText) (BSTR *pbstr) PURE;
  STDMETHOD(get_ValidationRule) (BSTR *pbstr) PURE;
  STDMETHOD(get_CacheStart) (SAFEARRAY **ppsa) PURE;
  STDMETHOD(put_CacheStart) (SAFEARRAY **psa) PURE;
  STDMETHOD(get_CacheSize) (long *pl) PURE;
  STDMETHOD(put_CacheSize) (long CacheSize) PURE;
  STDMETHOD(get_PercentPosition) (float *pd) PURE;
  STDMETHOD(put_PercentPosition) (float Position) PURE;
  STDMETHOD(get_AbsolutePosition) (long *pl) PURE;
  STDMETHOD(put_AbsolutePosition) (long Position) PURE;
  STDMETHOD(get_EditMode) (short *pi) PURE;
  STDMETHOD(get_ODBCFetchCount) (long *pl) PURE;
  STDMETHOD(get_ODBCFetchDelay) (long *pl) PURE;
  STDMETHOD(get_Parent) (DAODatabase **pdb) PURE;
  STDMETHOD(get_Fields) (DAOFields **ppflds) PURE;
  STDMETHOD(get_Indexes) (DAOIndexes **ppidxs) PURE;
  STDMETHOD(_30_CancelUpdate) (VOID) PURE;
  STDMETHOD(AddNew) (VOID) PURE;
  STDMETHOD(Close) (VOID) PURE;
  STDMETHOD(OpenRecordset) (VARIANT Type,VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(Delete) (VOID) PURE;
  STDMETHOD(Edit) (VOID) PURE;
  STDMETHOD(FindFirst) (BSTR Criteria) PURE;
  STDMETHOD(FindLast) (BSTR Criteria) PURE;
  STDMETHOD(FindNext) (BSTR Criteria) PURE;
  STDMETHOD(FindPrevious) (BSTR Criteria) PURE;
  STDMETHOD(MoveFirst) (VOID) PURE;
  STDMETHOD(_30_MoveLast) (VOID) PURE;
  STDMETHOD(MoveNext) (VOID) PURE;
  STDMETHOD(MovePrevious) (VOID) PURE;
  STDMETHOD(Seek) (BSTR Comparison,VARIANT Key1,VARIANT Key2,VARIANT Key3,VARIANT Key4,VARIANT Key5,VARIANT Key6,VARIANT Key7,VARIANT Key8,VARIANT Key9,VARIANT Key10,VARIANT Key11,VARIANT Key12,VARIANT Key13) PURE;
  STDMETHOD(_30_Update) (VOID) PURE;
  STDMETHOD(Clone) (DAORecordset **pprst) PURE;
  STDMETHOD(Requery) (VARIANT NewQueryDef) PURE;
  STDMETHOD(Move) (long Rows,VARIANT StartBookmark) PURE;
  STDMETHOD(FillCache) (VARIANT Rows,VARIANT StartBookmark) PURE;
  STDMETHOD(CreateDynaset) (VARIANT Options,VARIANT Inconsistent,DAORecordset **pprst) PURE;
  STDMETHOD(CreateSnapshot) (VARIANT Options,DAORecordset **pprst) PURE;
  STDMETHOD(CopyQueryDef) (DAOQueryDef **ppqdf) PURE;
  STDMETHOD(ListFields) (DAORecordset **pprst) PURE;
  STDMETHOD(ListIndexes) (DAORecordset **pprst) PURE;
  STDMETHOD(GetRows) (VARIANT NumRows,VARIANT *pvar) PURE;
  STDMETHOD(get_Collect) (VARIANT Item,VARIANT *pvar) PURE;
  STDMETHOD(put_Collect) (VARIANT Item,VARIANT value) PURE;
  STDMETHOD(Cancel) (VOID) PURE;
  STDMETHOD(NextRecordset) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_hStmt) (LONG *phStmt) PURE;
  STDMETHOD(get_StillExecuting) (VARIANT_BOOL *pStillExec) PURE;
  STDMETHOD(get_BatchSize) (long *pl) PURE;
  STDMETHOD(put_BatchSize) (long BatchSize) PURE;
  STDMETHOD(get_BatchCollisionCount) (long *pl) PURE;
  STDMETHOD(get_BatchCollisions) (VARIANT *pvar) PURE;
  STDMETHOD(get_Connection) (DAOConnection **ppCn) PURE;
  STDMETHOD(putref_Connection) (DAOConnection *pNewCn) PURE;
  STDMETHOD(get_RecordStatus) (short *pi) PURE;
  STDMETHOD(get_UpdateOptions) (long *pl) PURE;
  STDMETHOD(put_UpdateOptions) (long l) PURE;
  STDMETHOD(CancelUpdate) (long UpdateType) PURE;
  STDMETHOD(Update) (long UpdateType,VARIANT_BOOL Force) PURE;
  STDMETHOD(MoveLast) (long Options) PURE;
};

#undef INTERFACE
#define INTERFACE DAORecordsets
DECLARE_INTERFACE_(DAORecordsets,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAORecordset **pprst) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOField
DECLARE_INTERFACE_(_DAOField,_DAO) {
  STDMETHOD(get_CollatingOrder) (long *pl) PURE;
  STDMETHOD(get_Type) (short *ps) PURE;
  STDMETHOD(put_Type) (short Type) PURE;
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR Name) PURE;
  STDMETHOD(get_Size) (long *pl) PURE;
  STDMETHOD(put_Size) (long Size) PURE;
  STDMETHOD(get_SourceField) (BSTR *pbstr) PURE;
  STDMETHOD(get_SourceTable) (BSTR *pbstr) PURE;
  STDMETHOD(get_Value) (VARIANT *pvar) PURE;
  STDMETHOD(put_Value) (VARIANT Val) PURE;
  STDMETHOD(get_Attributes) (long *pl) PURE;
  STDMETHOD(put_Attributes) (long Attr) PURE;
  STDMETHOD(get_OrdinalPosition) (short *ps) PURE;
  STDMETHOD(put_OrdinalPosition) (short Pos) PURE;
  STDMETHOD(get_ValidationText) (BSTR *pbstr) PURE;
  STDMETHOD(put_ValidationText) (BSTR bstr) PURE;
  STDMETHOD(get_ValidateOnSet) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_ValidateOnSet) (VARIANT_BOOL Validate) PURE;
  STDMETHOD(get_ValidationRule) (BSTR *pbstr) PURE;
  STDMETHOD(put_ValidationRule) (BSTR bstr) PURE;
  STDMETHOD(get_DefaultValue) (VARIANT *pvar) PURE;
  STDMETHOD(put_DefaultValue) (VARIANT var) PURE;
  STDMETHOD(get_Required) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Required) (VARIANT_BOOL fReq) PURE;
  STDMETHOD(get_AllowZeroLength) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_AllowZeroLength) (VARIANT_BOOL fAllow) PURE;
  STDMETHOD(get_DataUpdatable) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_ForeignName) (BSTR *pbstr) PURE;
  STDMETHOD(put_ForeignName) (BSTR bstr) PURE;
  STDMETHOD(AppendChunk) (VARIANT Val) PURE;
  STDMETHOD(GetChunk) (long Offset,long Bytes,VARIANT *pvar) PURE;
  STDMETHOD(_30_FieldSize) (long *pl) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
  STDMETHOD(get_CollectionIndex) (short *i) PURE;
  STDMETHOD(get_OriginalValue) (VARIANT *pvar) PURE;
  STDMETHOD(get_VisibleValue) (VARIANT *pvar) PURE;
  STDMETHOD(get_FieldSize) (long *pl) PURE;
};

#undef INTERFACE
#define INTERFACE DAOFields
DECLARE_INTERFACE_(DAOFields,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOField **ppfld) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOIndex
DECLARE_INTERFACE_(_DAOIndex,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(get_Foreign) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(get_Unique) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Unique) (VARIANT_BOOL fUnique) PURE;
  STDMETHOD(get_Clustered) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Clustered) (VARIANT_BOOL fClustered) PURE;
  STDMETHOD(get_Required) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Required) (VARIANT_BOOL fRequired) PURE;
  STDMETHOD(get_IgnoreNulls) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_IgnoreNulls) (VARIANT_BOOL fIgnoreNulls) PURE;
  STDMETHOD(get_Primary) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Primary) (VARIANT_BOOL fPrimary) PURE;
  STDMETHOD(get_DistinctCount) (long *pl) PURE;
  STDMETHOD(get_Fields) (VARIANT *pv) PURE;
  STDMETHOD(put_Fields) (VARIANT v) PURE;
  STDMETHOD(CreateField) (VARIANT Name,VARIANT Type,VARIANT Size,DAOField **ppfld) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
};

#undef INTERFACE
#define INTERFACE DAOIndexes
DECLARE_INTERFACE_(DAOIndexes,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOIndex **ppidx) PURE;
};

#undef INTERFACE
#define INTERFACE DAOParameter
DECLARE_INTERFACE_(DAOParameter,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_Value) (VARIANT *pvar) PURE;
  STDMETHOD(put_Value) (VARIANT val) PURE;
  STDMETHOD(get_Type) (short *ps) PURE;
  STDMETHOD(put_Type) (short s) PURE;
  STDMETHOD(get_Direction) (short *pOption) PURE;
  STDMETHOD(put_Direction) (short Option) PURE;
};

#undef INTERFACE
#define INTERFACE DAOParameters
DECLARE_INTERFACE_(DAOParameters,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOParameter **ppprm) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOUser
DECLARE_INTERFACE_(_DAOUser,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(put_PID) (BSTR bstr) PURE;
  STDMETHOD(put_Password) (BSTR bstr) PURE;
  STDMETHOD(get_Groups) (DAOGroups **ppgrps) PURE;
  STDMETHOD(NewPassword) (BSTR bstrOld,BSTR bstrNew) PURE;
  STDMETHOD(CreateGroup) (VARIANT Name,VARIANT PID,DAOGroup **ppgrp) PURE;
};

#undef INTERFACE
#define INTERFACE DAOUsers
DECLARE_INTERFACE_(DAOUsers,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOUser **ppusr) PURE;
};

#undef INTERFACE
#define INTERFACE _DAOGroup
DECLARE_INTERFACE_(_DAOGroup,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(put_PID) (BSTR bstr) PURE;
  STDMETHOD(get_Users) (DAOUsers **ppusrs) PURE;
  STDMETHOD(CreateUser) (VARIANT Name,VARIANT PID,VARIANT Password,DAOUser **ppusr) PURE;
};

#undef INTERFACE
#define INTERFACE DAOGroups
DECLARE_INTERFACE_(DAOGroups,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOGroup **ppgrp) PURE;
};

#undef INTERFACE
#define INTERFACE _DAORelation
DECLARE_INTERFACE_(_DAORelation,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(put_Name) (BSTR bstr) PURE;
  STDMETHOD(get_Table) (BSTR *pbstr) PURE;
  STDMETHOD(put_Table) (BSTR bstr) PURE;
  STDMETHOD(get_ForeignTable) (BSTR *pbstr) PURE;
  STDMETHOD(put_ForeignTable) (BSTR bstr) PURE;
  STDMETHOD(get_Attributes) (long *pl) PURE;
  STDMETHOD(put_Attributes) (long attr) PURE;
  STDMETHOD(get_Fields) (DAOFields **ppflds) PURE;
  STDMETHOD(CreateField) (VARIANT Name,VARIANT Type,VARIANT Size,DAOField **ppfld) PURE;
  STDMETHOD(get_PartialReplica) (VARIANT_BOOL *pfPartialReplica) PURE;
  STDMETHOD(put_PartialReplica) (VARIANT_BOOL fPartialReplica) PURE;
};

#undef INTERFACE
#define INTERFACE DAORelations
DECLARE_INTERFACE_(DAORelations,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAORelation **pprel) PURE;
};

#undef INTERFACE
#define INTERFACE DAOContainer
DECLARE_INTERFACE_(DAOContainer,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_Owner) (BSTR *pbstr) PURE;
  STDMETHOD(put_Owner) (BSTR bstr) PURE;
  STDMETHOD(get_UserName) (BSTR *pbstr) PURE;
  STDMETHOD(put_UserName) (BSTR bstr) PURE;
  STDMETHOD(get_Permissions) (long *pl) PURE;
  STDMETHOD(put_Permissions) (long permissions) PURE;
  STDMETHOD(get_Inherit) (VARIANT_BOOL *pb) PURE;
  STDMETHOD(put_Inherit) (VARIANT_BOOL fInherit) PURE;
  STDMETHOD(get_Documents) (DAODocuments **ppdocs) PURE;
  STDMETHOD(get_AllPermissions) (long *pl) PURE;
};

#undef INTERFACE
#define INTERFACE DAOContainers
DECLARE_INTERFACE_(DAOContainers,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAOContainer **ppctn) PURE;
};

#undef INTERFACE
#define INTERFACE DAODocument
DECLARE_INTERFACE_(DAODocument,_DAO) {
  STDMETHOD(get_Name) (BSTR *pbstr) PURE;
  STDMETHOD(get_Owner) (BSTR *pbstr) PURE;
  STDMETHOD(put_Owner) (BSTR bstr) PURE;
  STDMETHOD(get_Container) (BSTR *pbstr) PURE;
  STDMETHOD(get_UserName) (BSTR *pbstr) PURE;
  STDMETHOD(put_UserName) (BSTR bstr) PURE;
  STDMETHOD(get_Permissions) (long *pl) PURE;
  STDMETHOD(put_Permissions) (long permissions) PURE;
  STDMETHOD(get_DateCreated) (VARIANT *pvar) PURE;
  STDMETHOD(get_LastUpdated) (VARIANT *pvar) PURE;
  STDMETHOD(get_AllPermissions) (long *pl) PURE;
  STDMETHOD(CreateProperty) (VARIANT Name,VARIANT Type,VARIANT Value,VARIANT DDL,DAOProperty **pprp) PURE;
};

#undef INTERFACE
#define INTERFACE DAODocuments
DECLARE_INTERFACE_(DAODocuments,_DAOCollection) {
  STDMETHOD(get_Item) (VARIANT Item,DAODocument **ppdoc) PURE;
};

#undef INTERFACE
#define INTERFACE DAOIndexFields
DECLARE_INTERFACE_(DAOIndexFields,_DAODynaCollection) {
  STDMETHOD(get_Item) (VARIANT Item,VARIANT *pvar) PURE;
};
#endif
