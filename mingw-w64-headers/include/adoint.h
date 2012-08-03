/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _ADOINT_H_
#define _ADOINT_H_

#include <tchar.h>

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif
#include "rpc.h"
#include "rpcndr.h"
#ifndef __m_bobj_h__
#define __m_bobj_h__

#ifndef ___ADOCollection_FWD_DEFINED__
#define ___ADOCollection_FWD_DEFINED__
typedef struct _ADOCollection _ADOCollection;
#endif
#ifndef ___ADODynaCollection_FWD_DEFINED__
#define ___ADODynaCollection_FWD_DEFINED__
typedef struct _ADODynaCollection _ADODynaCollection;
#endif
#ifndef ___ADO_FWD_DEFINED__
#define ___ADO_FWD_DEFINED__
typedef struct _ADO _ADO;
#endif
#ifndef __Error_FWD_DEFINED__
#define __Error_FWD_DEFINED__
typedef struct ADOError Error;
#endif
#ifndef __Errors_FWD_DEFINED__
#define __Errors_FWD_DEFINED__
typedef struct ADOErrors Errors;
#endif
#ifndef __Command15_FWD_DEFINED__
#define __Command15_FWD_DEFINED__
typedef struct Command15 Command15;
#endif
#ifndef __Command25_FWD_DEFINED__
#define __Command25_FWD_DEFINED__
typedef struct Command25 Command25;
#endif
#ifndef ___Command_FWD_DEFINED__
#define ___Command_FWD_DEFINED__
typedef struct _ADOCommand _Command;
#endif
#ifndef __ConnectionEventsVt_FWD_DEFINED__
#define __ConnectionEventsVt_FWD_DEFINED__
typedef struct ConnectionEventsVt ConnectionEventsVt;
#endif
#ifndef __RecordsetEventsVt_FWD_DEFINED__
#define __RecordsetEventsVt_FWD_DEFINED__
typedef struct RecordsetEventsVt RecordsetEventsVt;
#endif
#ifndef __ConnectionEvents_FWD_DEFINED__
#define __ConnectionEvents_FWD_DEFINED__
typedef struct ConnectionEvents ConnectionEvents;
#endif
#ifndef __RecordsetEvents_FWD_DEFINED__
#define __RecordsetEvents_FWD_DEFINED__
typedef struct RecordsetEvents RecordsetEvents;
#endif
#ifndef __Connection15_FWD_DEFINED__
#define __Connection15_FWD_DEFINED__
typedef struct Connection15 Connection15;
#endif
#ifndef ___Connection_FWD_DEFINED__
#define ___Connection_FWD_DEFINED__
typedef struct _ADOConnection _Connection;
#endif
#ifndef __ADOConnectionConstruction15_FWD_DEFINED__
#define __ADOConnectionConstruction15_FWD_DEFINED__
typedef struct ADOConnectionConstruction15 ADOConnectionConstruction15;
#endif
#ifndef __ADOConnectionConstruction_FWD_DEFINED__
#define __ADOConnectionConstruction_FWD_DEFINED__
typedef struct ADOConnectionConstruction ADOConnectionConstruction;
#endif
#ifndef __Connection_FWD_DEFINED__
#define __Connection_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOConnection Connection;
#else
typedef struct ADOConnection Connection;
#endif
#endif
#ifndef ___Record_FWD_DEFINED__
#define ___Record_FWD_DEFINED__
typedef struct _ADORecord _Record;
#endif
#ifndef __Record_FWD_DEFINED__
#define __Record_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADORecord Record;
#else
typedef struct ADORecord Record;
#endif
#endif
#ifndef ___Stream_FWD_DEFINED__
#define ___Stream_FWD_DEFINED__
typedef struct _ADOStream _Stream;
#endif
#ifndef __Stream_FWD_DEFINED__
#define __Stream_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOStream Stream;
#else
typedef struct ADOStream Stream;
#endif
#endif
#ifndef __ADORecordConstruction_FWD_DEFINED__
#define __ADORecordConstruction_FWD_DEFINED__
typedef struct ADORecordConstruction ADORecordConstruction;
#endif
#ifndef __ADOStreamConstruction_FWD_DEFINED__
#define __ADOStreamConstruction_FWD_DEFINED__
typedef struct ADOStreamConstruction ADOStreamConstruction;
#endif
#ifndef __ADOCommandConstruction_FWD_DEFINED__
#define __ADOCommandConstruction_FWD_DEFINED__
typedef struct ADOCommandConstruction ADOCommandConstruction;
#endif
#ifndef __Command_FWD_DEFINED__
#define __Command_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOCommand Command;
#else
typedef struct ADOCommand Command;
#endif
#endif
#ifndef __Recordset_FWD_DEFINED__
#define __Recordset_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADORecordset Recordset;
#else
typedef struct ADORecordset Recordset;
#endif
#endif
#ifndef __Recordset15_FWD_DEFINED__
#define __Recordset15_FWD_DEFINED__
typedef struct Recordset15 Recordset15;
#endif
#ifndef __Recordset20_FWD_DEFINED__
#define __Recordset20_FWD_DEFINED__
typedef struct Recordset20 Recordset20;
#endif
#ifndef __Recordset21_FWD_DEFINED__
#define __Recordset21_FWD_DEFINED__
typedef struct Recordset21 Recordset21;
#endif
#ifndef ___Recordset_FWD_DEFINED__
#define ___Recordset_FWD_DEFINED__
typedef struct _ADORecordset _Recordset;
#endif
#ifndef __ADORecordsetConstruction_FWD_DEFINED__
#define __ADORecordsetConstruction_FWD_DEFINED__
typedef struct ADORecordsetConstruction ADORecordsetConstruction;
#endif
#ifndef __Field15_FWD_DEFINED__
#define __Field15_FWD_DEFINED__
typedef struct Field15 Field15;
#endif
#ifndef __Field20_FWD_DEFINED__
#define __Field20_FWD_DEFINED__
typedef struct Field20 Field20;
#endif
#ifndef __Field_FWD_DEFINED__
#define __Field_FWD_DEFINED__
typedef struct ADOField Field;
#endif
#ifndef __Fields15_FWD_DEFINED__
#define __Fields15_FWD_DEFINED__
typedef struct Fields15 Fields15;
#endif
#ifndef __Fields20_FWD_DEFINED__
#define __Fields20_FWD_DEFINED__
typedef struct Fields20 Fields20;
#endif
#ifndef __Fields_FWD_DEFINED__
#define __Fields_FWD_DEFINED__
typedef struct ADOFields Fields;
#endif
#ifndef ___Parameter_FWD_DEFINED__
#define ___Parameter_FWD_DEFINED__
typedef struct _ADOParameter _Parameter;
#endif
#ifndef __Parameter_FWD_DEFINED__
#define __Parameter_FWD_DEFINED__
#ifdef __cplusplus
typedef class ADOParameter Parameter;
#else
typedef struct ADOParameter Parameter;
#endif
#endif
#ifndef __Parameters_FWD_DEFINED__
#define __Parameters_FWD_DEFINED__
typedef struct ADOParameters Parameters;
#endif
#ifndef __Property_FWD_DEFINED__
#define __Property_FWD_DEFINED__
typedef struct ADOProperty Property;
#endif
#ifndef __Properties_FWD_DEFINED__
#define __Properties_FWD_DEFINED__
typedef struct ADOProperties Properties;
#endif
#ifdef __cplusplus
extern "C"{
#endif

#ifndef __MIDL_user_allocate_free_DEFINED__
#define __MIDL_user_allocate_free_DEFINED__
  void *__RPC_API MIDL_user_allocate(size_t);
  void __RPC_API MIDL_user_free(void *);
#endif

#ifdef _WIN64
  typedef LONGLONG ADO_LONGPTR;
#else
  typedef LONG ADO_LONGPTR;
#endif

  extern RPC_IF_HANDLE __MIDL_itf_m_bobj_0000_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_m_bobj_0000_v0_0_s_ifspec;

#ifndef __ADODB_LIBRARY_DEFINED__
#define __ADODB_LIBRARY_DEFINED__
  typedef enum CursorTypeEnum {
    adOpenUnspecified = -1,adOpenForwardOnly = 0,adOpenKeyset = 1,adOpenDynamic = 2,adOpenStatic = 3
  } CursorTypeEnum;
  typedef enum CursorOptionEnum {
    adHoldRecords = 0x100,adMovePrevious = 0x200,adAddNew = 0x1000400,adDelete = 0x1000800,adUpdate = 0x1008000,adBookmark = 0x2000,
    adApproxPosition = 0x4000,adUpdateBatch = 0x10000,adResync = 0x20000,adNotify = 0x40000,adFind = 0x80000,adSeek = 0x400000,adIndex = 0x800000
  } CursorOptionEnum;
  typedef enum LockTypeEnum {
    adLockUnspecified = -1,adLockReadOnly = 1,adLockPessimistic = 2,adLockOptimistic = 3,adLockBatchOptimistic = 4
  } LockTypeEnum;
  typedef enum ExecuteOptionEnum {
    adOptionUnspecified = -1,adAsyncExecute = 0x10,adAsyncFetch = 0x20,adAsyncFetchNonBlocking = 0x40,adExecuteNoRecords = 0x80,
    adExecuteStream = 0x400,adExecuteRecord = 0x800
  } ExecuteOptionEnum;
  typedef enum ConnectOptionEnum {
    adConnectUnspecified = -1,adAsyncConnect = 0x10
  } ConnectOptionEnum;
  typedef enum ObjectStateEnum {
    adStateClosed = 0,adStateOpen = 0x1,adStateConnecting = 0x2,adStateExecuting = 0x4,adStateFetching = 0x8
  } ObjectStateEnum;
  typedef enum CursorLocationEnum {
    adUseNone = 1,adUseServer = 2,adUseClient = 3,adUseClientBatch = 3
  } CursorLocationEnum;
  typedef enum DataTypeEnum {
    adEmpty = 0,adTinyInt = 16,adSmallInt = 2,adInteger = 3,adBigInt = 20,adUnsignedTinyInt = 17,adUnsignedSmallInt = 18,adUnsignedInt = 19,
    adUnsignedBigInt = 21,adSingle = 4,adDouble = 5,adCurrency = 6,adDecimal = 14,adNumeric = 131,adBoolean = 11,adError = 10,adUserDefined = 132,
    adVariant = 12,adIDispatch = 9,adIUnknown = 13,adGUID = 72,adDate = 7,adDBDate = 133,adDBTime = 134,adDBTimeStamp = 135,adBSTR = 8,adChar = 129,
    adVarChar = 200,adLongVarChar = 201,adWChar = 130,adVarWChar = 202,adLongVarWChar = 203,adBinary = 128,adVarBinary = 204,adLongVarBinary = 205,
    adChapter = 136,adFileTime = 64,adPropVariant = 138,adVarNumeric = 139,adArray = 0x2000
  } DataTypeEnum;
  typedef enum FieldAttributeEnum {
    adFldUnspecified = -1,adFldMayDefer = 0x2,adFldUpdatable = 0x4,adFldUnknownUpdatable = 0x8,adFldFixed = 0x10,adFldIsNullable = 0x20,
    adFldMayBeNull = 0x40,adFldLong = 0x80,adFldRowID = 0x100,adFldRowVersion = 0x200,adFldCacheDeferred = 0x1000,adFldIsChapter = 0x2000,
    adFldNegativeScale = 0x4000,adFldKeyColumn = 0x8000,adFldIsRowURL = 0x10000,adFldIsDefaultStream = 0x20000,adFldIsCollection = 0x40000
  } FieldAttributeEnum;
  typedef enum EditModeEnum {
    adEditNone = 0,adEditInProgress = 0x1,adEditAdd = 0x2,adEditDelete = 0x4
  } EditModeEnum;
  typedef enum RecordStatusEnum {
    adRecOK = 0,adRecNew = 0x1,adRecModified = 0x2,adRecDeleted = 0x4,adRecUnmodified = 0x8,adRecInvalid = 0x10,adRecMultipleChanges = 0x40,
    adRecPendingChanges = 0x80,adRecCanceled = 0x100,adRecCantRelease = 0x400,adRecConcurrencyViolation = 0x800,adRecIntegrityViolation = 0x1000,
    adRecMaxChangesExceeded = 0x2000,adRecObjectOpen = 0x4000,adRecOutOfMemory = 0x8000,adRecPermissionDenied = 0x10000,
    adRecSchemaViolation = 0x20000,adRecDBDeleted = 0x40000
  } RecordStatusEnum;
  typedef enum GetRowsOptionEnum {
    adGetRowsRest = -1
  } GetRowsOptionEnum;
  typedef enum PositionEnum {
    adPosUnknown = -1,adPosBOF = -2,adPosEOF = -3
  } PositionEnum;
#ifdef _WIN64
  typedef LONGLONG PositionEnum_Param;
#else
  typedef PositionEnum PositionEnum_Param;
#endif
  typedef enum BookmarkEnum {
    adBookmarkCurrent = 0,adBookmarkFirst = 1,adBookmarkLast = 2
  } BookmarkEnum;
  typedef enum MarshalOptionsEnum {
    adMarshalAll = 0,adMarshalModifiedOnly = 1
  } MarshalOptionsEnum;
  typedef enum AffectEnum {
    adAffectCurrent = 1,adAffectGroup = 2,adAffectAll = 3,adAffectAllChapters = 4
  } AffectEnum;
  typedef enum ResyncEnum {
    adResyncUnderlyingValues = 1,adResyncAllValues = 2
  } ResyncEnum;
  typedef enum CompareEnum {
    adCompareLessThan = 0,adCompareEqual = 1,adCompareGreaterThan = 2,adCompareNotEqual = 3,adCompareNotComparable = 4
  } CompareEnum;
  typedef enum FilterGroupEnum {
    adFilterNone = 0,adFilterPendingRecords = 1,adFilterAffectedRecords = 2,adFilterFetchedRecords = 3,adFilterPredicate = 4,
    adFilterConflictingRecords = 5
  } FilterGroupEnum;
  typedef enum SearchDirectionEnum {
    adSearchForward = 1,adSearchBackward = -1
  } SearchDirectionEnum;
  typedef SearchDirectionEnum SearchDirection;
  typedef enum PersistFormatEnum {
    adPersistADTG = 0,adPersistXML = 1
  } PersistFormatEnum;
  typedef enum StringFormatEnum {
    adClipString = 2
  } StringFormatEnum;
  typedef enum ConnectPromptEnum {
    adPromptAlways = 1,adPromptComplete = 2,adPromptCompleteRequired = 3,adPromptNever = 4
  } ConnectPromptEnum;
  typedef enum ConnectModeEnum {
    adModeUnknown = 0,adModeRead = 1,adModeWrite = 2,adModeReadWrite = 3,adModeShareDenyRead = 4,adModeShareDenyWrite = 8,adModeShareExclusive = 0xc,
    adModeShareDenyNone = 0x10,adModeRecursive = 0x400000
  } ConnectModeEnum;
  typedef enum RecordCreateOptionsEnum {
    adCreateCollection = 0x2000,adCreateStructDoc = 0x80000000,adCreateNonCollection = 0,adOpenIfExists = 0x2000000,adCreateOverwrite = 0x4000000,
    adFailIfNotExists = -1
  } RecordCreateOptionsEnum;
  typedef enum RecordOpenOptionsEnum {
    adOpenRecordUnspecified = -1,adOpenSource = 0x800000,adOpenOutput = 0x800000,adOpenAsync = 0x1000,adDelayFetchStream = 0x4000,
    adDelayFetchFields = 0x8000,adOpenExecuteCommand = 0x10000
  } RecordOpenOptionsEnum;
  typedef enum IsolationLevelEnum {
    adXactUnspecified = 0xffffffff,adXactChaos = 0x10,adXactReadUncommitted = 0x100,adXactBrowse = 0x100,adXactCursorStability = 0x1000,
    adXactReadCommitted = 0x1000,adXactRepeatableRead = 0x10000,adXactSerializable = 0x100000,adXactIsolated = 0x100000
  } IsolationLevelEnum;
  typedef enum XactAttributeEnum {
    adXactCommitRetaining = 0x20000,adXactAbortRetaining = 0x40000,adXactAsyncPhaseOne = 0x80000,adXactSyncPhaseOne = 0x100000
  } XactAttributeEnum;
  typedef enum PropertyAttributesEnum {
    adPropNotSupported = 0,adPropRequired = 0x1,adPropOptional = 0x2,adPropRead = 0x200,adPropWrite = 0x400
  } PropertyAttributesEnum;
  typedef enum ErrorValueEnum {
    adErrProviderFailed = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbb8),
    adErrInvalidArgument = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbb9),
    adErrOpeningFile = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbba),
    adErrReadFile = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbbb),
    adErrWriteFile = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbbc),
    adErrNoCurrentRecord = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xbcd),
    adErrIllegalOperation = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xc93),
    adErrCantChangeProvider = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xc94),
    adErrInTransaction = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xcae),
    adErrFeatureNotAvailable = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xcb3),
    adErrItemNotFound = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xcc1),
    adErrObjectInCollection = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xd27),
    adErrObjectNotSet = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xd5c),
    adErrDataConversion = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xd5d),
    adErrObjectClosed = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe78),
    adErrObjectOpen = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe79),
    adErrProviderNotFound = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7a),
    adErrBoundToCommand = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7b),
    adErrInvalidParamInfo = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7c),
    adErrInvalidConnection = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7d),
    adErrNotReentrant = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7e),
    adErrStillExecuting = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe7f),
    adErrOperationCancelled = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe80),
    adErrStillConnecting = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe81),
    adErrInvalidTransaction = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe82),
    adErrNotExecuting = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe83),
    adErrUnsafeOperation = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe84),
    adwrnSecurityDialog = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe85),
    adwrnSecurityDialogHeader = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe86),
    adErrIntegrityViolation = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe87),
    adErrPermissionDenied = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe88),
    adErrDataOverflow = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe89),
    adErrSchemaViolation = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8a),
    adErrSignMismatch = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8b),
    adErrCantConvertvalue = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8c),
    adErrCantCreate = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8d),
    adErrColumnNotOnThisRow = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8e),
    adErrURLDoesNotExist = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe8f),
    adErrTreePermissionDenied = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe90),
    adErrInvalidURL = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe91),
    adErrResourceLocked = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe92),
    adErrResourceExists = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe93),
    adErrCannotComplete = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe94),
    adErrVolumeNotFound = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe95),
    adErrOutOfSpace = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe96),
    adErrResourceOutOfScope = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe97),
    adErrUnavailable = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe98),
    adErrURLNamedRowDoesNotExist = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe99),
    adErrDelResOutOfScope = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9a),
    adErrPropInvalidColumn = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9b),
    adErrPropInvalidOption = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9c),
    adErrPropInvalidValue = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9d),
    adErrPropConflicting = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9e),
    adErrPropNotAllSettable = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xe9f),
    adErrPropNotSet = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea0),
    adErrPropNotSettable = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea1),
    adErrPropNotSupported = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea2),
    adErrCatalogNotSet = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea3),
    adErrCantChangeConnection = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea4),
    adErrFieldsUpdateFailed = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea5),
    adErrDenyNotSupported = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea6),
    adErrDenyTypeNotSupported = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea7),
    adErrProviderNotSpecified = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xea9),
    adErrConnectionStringTooLong = MAKE_HRESULT(SEVERITY_ERROR,FACILITY_CONTROL,0xeaa)
  } ErrorValueEnum;
  typedef enum ParameterAttributesEnum {
    adParamSigned = 0x10,adParamNullable = 0x40,adParamLong = 0x80
  } ParameterAttributesEnum;
  typedef enum ParameterDirectionEnum {
    adParamUnknown = 0,adParamInput = 0x1,adParamOutput = 0x2,adParamInputOutput = 0x3,adParamReturnValue = 0x4
  } ParameterDirectionEnum;
  typedef enum CommandTypeEnum {
    adCmdUnspecified = -1,adCmdUnknown = 0x8,adCmdText = 0x1,adCmdTable = 0x2,adCmdStoredProc = 0x4,adCmdFile = 0x100,adCmdTableDirect = 0x200
  } CommandTypeEnum;
  typedef enum EventStatusEnum {
    adStatusOK = 0x1,adStatusErrorsOccurred = 0x2,adStatusCantDeny = 0x3,adStatusCancel = 0x4,adStatusUnwantedEvent = 0x5
  } EventStatusEnum;
  typedef enum EventReasonEnum {
    adRsnAddNew = 1,adRsnDelete = 2,adRsnUpdate = 3,adRsnUndoUpdate = 4,adRsnUndoAddNew = 5,adRsnUndoDelete = 6,adRsnRequery = 7,adRsnResynch = 8,
    adRsnClose = 9,adRsnMove = 10,adRsnFirstChange = 11,adRsnMoveFirst = 12,adRsnMoveNext = 13,adRsnMovePrevious = 14,adRsnMoveLast = 15
  } EventReasonEnum;
  typedef enum SchemaEnum {
    adSchemaProviderSpecific = -1,adSchemaAsserts = 0,adSchemaCatalogs = 1,adSchemaCharacterSets = 2,adSchemaCollations = 3,adSchemaColumns = 4,
    adSchemaCheckConstraints = 5,adSchemaConstraintColumnUsage = 6,adSchemaConstraintTableUsage = 7,adSchemaKeyColumnUsage = 8,
    adSchemaReferentialContraints = 9,adSchemaReferentialConstraints = 9,adSchemaTableConstraints = 10,adSchemaColumnsDomainUsage = 11,
    adSchemaIndexes = 12,adSchemaColumnPrivileges = 13,adSchemaTablePrivileges = 14,adSchemaUsagePrivileges = 15,adSchemaProcedures = 16,
    adSchemaSchemata = 17,adSchemaSQLLanguages = 18,adSchemaStatistics = 19,adSchemaTables = 20,adSchemaTranslations = 21,adSchemaProviderTypes = 22,
    adSchemaViews = 23,adSchemaViewColumnUsage = 24,adSchemaViewTableUsage = 25,adSchemaProcedureParameters = 26,adSchemaForeignKeys = 27,
    adSchemaPrimaryKeys = 28,adSchemaProcedureColumns = 29,adSchemaDBInfoKeywords = 30,adSchemaDBInfoLiterals = 31,adSchemaCubes = 32,
    adSchemaDimensions = 33,adSchemaHierarchies = 34,adSchemaLevels = 35,adSchemaMeasures = 36,adSchemaProperties = 37,adSchemaMembers = 38,
    adSchemaTrustees = 39,adSchemaFunctions = 40,adSchemaActions = 41,adSchemaCommands = 42,adSchemaSets = 43
  } SchemaEnum;
  typedef enum FieldStatusEnum {
    adFieldOK = 0,adFieldCantConvertValue = 2,adFieldIsNull = 3,adFieldTruncated = 4,adFieldSignMismatch = 5,adFieldDataOverflow = 6,
    adFieldCantCreate = 7,adFieldUnavailable = 8,adFieldPermissionDenied = 9,adFieldIntegrityViolation = 10,adFieldSchemaViolation = 11,
    adFieldBadStatus = 12,adFieldDefault = 13,adFieldIgnore = 15,adFieldDoesNotExist = 16,adFieldInvalidURL = 17,adFieldResourceLocked = 18,
    adFieldResourceExists = 19,adFieldCannotComplete = 20,adFieldVolumeNotFound = 21,adFieldOutOfSpace = 22,adFieldCannotDeleteSource = 23,
    adFieldReadOnly = 24,adFieldResourceOutOfScope = 25,adFieldAlreadyExists = 26,adFieldPendingInsert = 0x10000,adFieldPendingDelete = 0x20000,
    adFieldPendingChange = 0x40000,adFieldPendingUnknown = 0x80000,adFieldPendingUnknownDelete = 0x100000
  } FieldStatusEnum;
  typedef enum SeekEnum {
    adSeekFirstEQ = 0x1,adSeekLastEQ = 0x2,adSeekAfterEQ = 0x4,adSeekAfter = 0x8,adSeekBeforeEQ = 0x10,adSeekBefore = 0x20
  } SeekEnum;

#ifndef _COMMON_ADC_AND_ADO_PROPS_
#define _COMMON_ADC_AND_ADO_PROPS_
  typedef enum ADCPROP_UPDATECRITERIA_ENUM {
    adCriteriaKey = 0,adCriteriaAllCols = 1,adCriteriaUpdCols = 2,adCriteriaTimeStamp = 3
  } ADCPROP_UPDATECRITERIA_ENUM;
  typedef enum ADCPROP_ASYNCTHREADPRIORITY_ENUM {
    adPriorityLowest = 1,adPriorityBelowNormal = 2,adPriorityNormal = 3,adPriorityAboveNormal = 4,adPriorityHighest = 5
  } ADCPROP_ASYNCTHREADPRIORITY_ENUM;
  typedef enum ADCPROP_AUTORECALC_ENUM {
    adRecalcUpFront = 0,adRecalcAlways = 1
  } ADCPROP_AUTORECALC_ENUM;
  typedef enum ADCPROP_UPDATERESYNC_ENUM {
    adResyncNone = 0,adResyncAutoIncrement = 1,adResyncConflicts = 2,adResyncUpdates = 4,adResyncInserts = 8,adResyncAll = 15
  } ADCPROP_UPDATERESYNC_ENUM;
#endif
  typedef ADCPROP_UPDATERESYNC_ENUM CEResyncEnum;
  typedef enum MoveRecordOptionsEnum {
    adMoveUnspecified = -1,adMoveOverWrite = 1,adMoveDontUpdateLinks = 2,adMoveAllowEmulation = 4
  } MoveRecordOptionsEnum;
  typedef enum CopyRecordOptionsEnum {
    adCopyUnspecified = -1,adCopyOverWrite = 1,adCopyAllowEmulation = 4,adCopyNonRecursive = 2
  } CopyRecordOptionsEnum;
  typedef enum StreamTypeEnum {
    adTypeBinary = 1,adTypeText = 2
  } StreamTypeEnum;
  typedef enum LineSeparatorEnum {
    adLF = 10,adCR = 13,adCRLF = -1
  } LineSeparatorEnum;
  typedef enum StreamOpenOptionsEnum {
    adOpenStreamUnspecified = -1,adOpenStreamAsync = 1,adOpenStreamFromRecord = 4
  } StreamOpenOptionsEnum;
  typedef enum StreamWriteEnum {
    adWriteChar = 0,adWriteLine = 1,stWriteChar = 0,stWriteLine = 1
  } StreamWriteEnum;
  typedef enum SaveOptionsEnum {
    adSaveCreateNotExist = 1,adSaveCreateOverWrite = 2
  } SaveOptionsEnum;
  typedef enum FieldEnum {
    adDefaultStream = -1,adRecordURL = -2
  } FieldEnum;
  typedef enum StreamReadEnum {
    adReadAll = -1,adReadLine = -2
  } StreamReadEnum;
  typedef enum RecordTypeEnum {
    adSimpleRecord = 0,adCollectionRecord = 1,adStructDoc = 2
  } RecordTypeEnum;
  EXTERN_C const IID LIBID_ADODB;

#ifndef ___ADOCollection_INTERFACE_DEFINED__
#define ___ADOCollection_INTERFACE_DEFINED__
  EXTERN_C const IID IID__ADOCollection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOCollection : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Count(__LONG32 *c) = 0;
    virtual HRESULT WINAPI _NewEnum(IUnknown **ppvObject) = 0;
    virtual HRESULT WINAPI Refresh(void) = 0;
  };
#else
  typedef struct _ADOCollectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOCollection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOCollection *This);
      ULONG (WINAPI *Release)(_ADOCollection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOCollection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOCollection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOCollection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOCollection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(_ADOCollection *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(_ADOCollection *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(_ADOCollection *This);
    END_INTERFACE
  } _ADOCollectionVtbl;
  struct _ADOCollection {
    CONST_VTBL struct _ADOCollectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _ADOCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _ADOCollection_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _ADOCollection_Release(This) (This)->lpVtbl -> Release(This)
#define _ADOCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _ADOCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _ADOCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _ADOCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Collection_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define _ADOCollection__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define _ADOCollection_Refresh(This) (This)->lpVtbl -> Refresh(This)
#endif
#endif
  HRESULT WINAPI _Collection_get_Count_Proxy(_ADOCollection *This,__LONG32 *c);
  void __RPC_STUB _Collection_get_Count_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADOCollection__NewEnum_Proxy(_ADOCollection *This,IUnknown **ppvObject);
  void __RPC_STUB _ADOCollection__NewEnum_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADOCollection_Refresh_Proxy(_ADOCollection *This);
  void __RPC_STUB _ADOCollection_Refresh_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___ADODynaCollection_INTERFACE_DEFINED__
#define ___ADODynaCollection_INTERFACE_DEFINED__
  EXTERN_C const IID IID__ADODynaCollection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADODynaCollection : public _ADOCollection {
  public:
    virtual HRESULT WINAPI Append(IDispatch *Object) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Index) = 0;
  };
#else
  typedef struct _ADODynaCollectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADODynaCollection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADODynaCollection *This);
      ULONG (WINAPI *Release)(_ADODynaCollection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADODynaCollection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADODynaCollection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADODynaCollection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADODynaCollection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(_ADODynaCollection *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(_ADODynaCollection *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(_ADODynaCollection *This);
      HRESULT (WINAPI *Append)(_ADODynaCollection *This,IDispatch *Object);
      HRESULT (WINAPI *Delete)(_ADODynaCollection *This,VARIANT Index);
    END_INTERFACE
  } _ADODynaCollectionVtbl;
  struct _ADODynaCollection {
    CONST_VTBL struct _ADODynaCollectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _ADODynaCollection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _ADODynaCollection_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _ADODynaCollection_Release(This) (This)->lpVtbl -> Release(This)
#define _ADODynaCollection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _ADODynaCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _ADODynaCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _ADODynaCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _DynaCollection_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define _ADODynaCollection__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define _ADODynaCollection_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define _ADODynaCollection_Append(This,Object) (This)->lpVtbl -> Append(This,Object)
#define _ADODynaCollection_Delete(This,Index) (This)->lpVtbl -> Delete(This,Index)
#endif
#endif
  HRESULT WINAPI _ADODynaCollection_Append_Proxy(_ADODynaCollection *This,IDispatch *Object);
  void __RPC_STUB _ADODynaCollection_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _ADODynaCollection_Delete_Proxy(_ADODynaCollection *This,VARIANT Index);
  void __RPC_STUB _ADODynaCollection_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___ADO_INTERFACE_DEFINED__
#define ___ADO_INTERFACE_DEFINED__
  EXTERN_C const IID IID__ADO;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADO : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Properties(ADOProperties **ppvObject) = 0;
  };
#else
  typedef struct _ADOVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADO *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADO *This);
      ULONG (WINAPI *Release)(_ADO *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADO *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADO *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADO *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADO *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADO *This,ADOProperties **ppvObject);
    END_INTERFACE
  } _ADOVtbl;
  struct _ADO {
    CONST_VTBL struct _ADOVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _ADO_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _ADO_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _ADO_Release(This) (This)->lpVtbl -> Release(This)
#define _ADO_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _ADO_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _ADO_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _ADO_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _ADO_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#endif
#endif
  HRESULT WINAPI _ADO_get_Properties_Proxy(_ADO *This,ADOProperties **ppvObject);
  void __RPC_STUB _ADO_get_Properties_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Error_INTERFACE_DEFINED__
#define __Error_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Error;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOError : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Number(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI get_Source(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Description(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_HelpFile(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_HelpContext(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI get_SQLState(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_NativeError(__LONG32 *pl) = 0;
  };
#else
  typedef struct ErrorVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOError *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOError *This);
      ULONG (WINAPI *Release)(ADOError *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOError *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOError *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOError *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOError *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Number)(ADOError *This,__LONG32 *pl);
      HRESULT (WINAPI *get_Source)(ADOError *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Description)(ADOError *This,BSTR *pbstr);
      HRESULT (WINAPI *get_HelpFile)(ADOError *This,BSTR *pbstr);
      HRESULT (WINAPI *get_HelpContext)(ADOError *This,__LONG32 *pl);
      HRESULT (WINAPI *get_SQLState)(ADOError *This,BSTR *pbstr);
      HRESULT (WINAPI *get_NativeError)(ADOError *This,__LONG32 *pl);
    END_INTERFACE
  } ErrorVtbl;
  struct Error {
    CONST_VTBL struct ErrorVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Error_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Error_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Error_Release(This) (This)->lpVtbl -> Release(This)
#define Error_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Error_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Error_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Error_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Error_get_Number(This,pl) (This)->lpVtbl -> get_Number(This,pl)
#define Error_get_Source(This,pbstr) (This)->lpVtbl -> get_Source(This,pbstr)
#define Error_get_Description(This,pbstr) (This)->lpVtbl -> get_Description(This,pbstr)
#define Error_get_HelpFile(This,pbstr) (This)->lpVtbl -> get_HelpFile(This,pbstr)
#define Error_get_HelpContext(This,pl) (This)->lpVtbl -> get_HelpContext(This,pl)
#define Error_get_SQLState(This,pbstr) (This)->lpVtbl -> get_SQLState(This,pbstr)
#define Error_get_NativeError(This,pl) (This)->lpVtbl -> get_NativeError(This,pl)
#endif
#endif
  HRESULT WINAPI Error_get_Number_Proxy(ADOError *This,__LONG32 *pl);
  void __RPC_STUB Error_get_Number_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_Source_Proxy(ADOError *This,BSTR *pbstr);
  void __RPC_STUB Error_get_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_Description_Proxy(ADOError *This,BSTR *pbstr);
  void __RPC_STUB Error_get_Description_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_HelpFile_Proxy(ADOError *This,BSTR *pbstr);
  void __RPC_STUB Error_get_HelpFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_HelpContext_Proxy(ADOError *This,__LONG32 *pl);
  void __RPC_STUB Error_get_HelpContext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_SQLState_Proxy(ADOError *This,BSTR *pbstr);
  void __RPC_STUB Error_get_SQLState_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Error_get_NativeError_Proxy(ADOError *This,__LONG32 *pl);
  void __RPC_STUB Error_get_NativeError_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Errors_INTERFACE_DEFINED__
#define __Errors_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Errors;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOErrors : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,ADOError **ppvObject) = 0;
    virtual HRESULT WINAPI Clear(void) = 0;
  };
#else
  typedef struct ErrorsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOErrors *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOErrors *This);
      ULONG (WINAPI *Release)(ADOErrors *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOErrors *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOErrors *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOErrors *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOErrors *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOErrors *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOErrors *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOErrors *This);
      HRESULT (WINAPI *get_Item)(ADOErrors *This,VARIANT Index,ADOError **ppvObject);
      HRESULT (WINAPI *Clear)(ADOErrors *This);
    END_INTERFACE
  } ErrorsVtbl;
  struct Errors {
    CONST_VTBL struct ErrorsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Errors_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Errors_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Errors_Release(This) (This)->lpVtbl -> Release(This)
#define Errors_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Errors_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Errors_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Errors_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Errors_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Errors__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Errors_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Errors_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Errors_Clear(This) (This)->lpVtbl -> Clear(This)
#endif
#endif
  HRESULT WINAPI Errors_get_Item_Proxy(ADOErrors *This,VARIANT Index,ADOError **ppvObject);
  void __RPC_STUB Errors_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Errors_Clear_Proxy(ADOErrors *This);
  void __RPC_STUB Errors_Clear_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Command15_INTERFACE_DEFINED__
#define __Command15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Command15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Command15 : public _ADO {
  public:
    virtual HRESULT WINAPI get_ActiveConnection(_ADOConnection **ppvObject) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(_ADOConnection *pCon) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(VARIANT vConn) = 0;
    virtual HRESULT WINAPI get_CommandText(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_CommandText(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_CommandTimeout(LONG *pl) = 0;
    virtual HRESULT WINAPI put_CommandTimeout(LONG Timeout) = 0;
    virtual HRESULT WINAPI get_Prepared(VARIANT_BOOL *pfPrepared) = 0;
    virtual HRESULT WINAPI put_Prepared(VARIANT_BOOL fPrepared) = 0;
    virtual HRESULT WINAPI Execute(VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options,_ADORecordset **ppirs) = 0;
    virtual HRESULT WINAPI CreateParameter(BSTR Name,DataTypeEnum Type,ParameterDirectionEnum Direction,ADO_LONGPTR Size,VARIANT Value,_ADOParameter **ppiprm) = 0;
    virtual HRESULT WINAPI get_Parameters(ADOParameters **ppvObject) = 0;
    virtual HRESULT WINAPI put_CommandType(CommandTypeEnum lCmdType) = 0;
    virtual HRESULT WINAPI get_CommandType(CommandTypeEnum *plCmdType) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbstrName) = 0;
    virtual HRESULT WINAPI put_Name(BSTR bstrName) = 0;
  };
#else
  typedef struct Command15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Command15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Command15 *This);
      ULONG (WINAPI *Release)(Command15 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Command15 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Command15 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Command15 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Command15 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Command15 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActiveConnection)(Command15 *This,_ADOConnection **ppvObject);
      HRESULT (WINAPI *putref_ActiveADOConnection)(Command15 *This,_ADOConnection *pCon);
      HRESULT (WINAPI *put_ActiveConnection)(Command15 *This,VARIANT vConn);
      HRESULT (WINAPI *get_CommandText)(Command15 *This,BSTR *pbstr);
      HRESULT (WINAPI *put_CommandText)(Command15 *This,BSTR bstr);
      HRESULT (WINAPI *get_CommandTimeout)(Command15 *This,LONG *pl);
      HRESULT (WINAPI *put_CommandTimeout)(Command15 *This,LONG Timeout);
      HRESULT (WINAPI *get_Prepared)(Command15 *This,VARIANT_BOOL *pfPrepared);
      HRESULT (WINAPI *put_Prepared)(Command15 *This,VARIANT_BOOL fPrepared);
      HRESULT (WINAPI *Execute)(Command15 *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options,_ADORecordset **ppirs);
      HRESULT (WINAPI *CreateParameter)(Command15 *This,BSTR Name,DataTypeEnum Type,ParameterDirectionEnum Direction,ADO_LONGPTR Size,VARIANT Value,_ADOParameter **ppiprm);
      HRESULT (WINAPI *get_Parameters)(Command15 *This,ADOParameters **ppvObject);
      HRESULT (WINAPI *put_CommandType)(Command15 *This,CommandTypeEnum lCmdType);
      HRESULT (WINAPI *get_CommandType)(Command15 *This,CommandTypeEnum *plCmdType);
      HRESULT (WINAPI *get_Name)(Command15 *This,BSTR *pbstrName);
      HRESULT (WINAPI *put_Name)(Command15 *This,BSTR bstrName);
    END_INTERFACE
  } Command15Vtbl;
  struct Command15 {
    CONST_VTBL struct Command15Vtbl *lpVtbl;
  };

#ifdef COBJMACROS
#define Command15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Command15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Command15_Release(This) (This)->lpVtbl -> Release(This)
#define Command15_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Command15_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Command15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Command15_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Command15_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Command15_get_ActiveConnection(This,ppvObject) (This)->lpVtbl -> get_ActiveConnection(This,ppvObject)
#define Command15_putref_ActiveConnection(This,pCon) (This)->lpVtbl -> putref_ActiveConnection(This,pCon)
#define Command15_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Command15_get_CommandText(This,pbstr) (This)->lpVtbl -> get_CommandText(This,pbstr)
#define Command15_put_CommandText(This,bstr) (This)->lpVtbl -> put_CommandText(This,bstr)
#define Command15_get_CommandTimeout(This,pl) (This)->lpVtbl -> get_CommandTimeout(This,pl)
#define Command15_put_CommandTimeout(This,Timeout) (This)->lpVtbl -> put_CommandTimeout(This,Timeout)
#define Command15_get_Prepared(This,pfPrepared) (This)->lpVtbl -> get_Prepared(This,pfPrepared)
#define Command15_put_Prepared(This,fPrepared) (This)->lpVtbl -> put_Prepared(This,fPrepared)
#define Command15_Execute(This,RecordsAffected,Parameters,Options,ppirs) (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define Command15_CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm) (This)->lpVtbl -> CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm)
#define Command15_get_Parameters(This,ppvObject) (This)->lpVtbl -> get_Parameters(This,ppvObject)
#define Command15_put_CommandType(This,lCmdType) (This)->lpVtbl -> put_CommandType(This,lCmdType)
#define Command15_get_CommandType(This,plCmdType) (This)->lpVtbl -> get_CommandType(This,plCmdType)
#define Command15_get_Name(This,pbstrName) (This)->lpVtbl -> get_Name(This,pbstrName)
#define Command15_put_Name(This,bstrName) (This)->lpVtbl -> put_Name(This,bstrName)
#endif
#endif
  HRESULT WINAPI Command15_get_ActiveConnection_Proxy(Command15 *This,_ADOConnection **ppvObject);
  void __RPC_STUB Command15_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_putref_ActiveConnection_Proxy(Command15 *This,_ADOConnection *pCon);
  void __RPC_STUB Command15_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_ActiveConnection_Proxy(Command15 *This,VARIANT vConn);
  void __RPC_STUB Command15_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_CommandText_Proxy(Command15 *This,BSTR *pbstr);
  void __RPC_STUB Command15_get_CommandText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_CommandText_Proxy(Command15 *This,BSTR bstr);
  void __RPC_STUB Command15_put_CommandText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_CommandTimeout_Proxy(Command15 *This,LONG *pl);
  void __RPC_STUB Command15_get_CommandTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_CommandTimeout_Proxy(Command15 *This,LONG Timeout);
  void __RPC_STUB Command15_put_CommandTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_Prepared_Proxy(Command15 *This,VARIANT_BOOL *pfPrepared);
  void __RPC_STUB Command15_get_Prepared_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_Prepared_Proxy(Command15 *This,VARIANT_BOOL fPrepared);
  void __RPC_STUB Command15_put_Prepared_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_Execute_Proxy(Command15 *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options,_ADORecordset **ppirs);
  void __RPC_STUB Command15_Execute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_CreateParameter_Proxy(Command15 *This,BSTR Name,DataTypeEnum Type,ParameterDirectionEnum Direction,ADO_LONGPTR Size,VARIANT Value,_ADOParameter **ppiprm);
  void __RPC_STUB Command15_CreateParameter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_Parameters_Proxy(Command15 *This,ADOParameters **ppvObject);
  void __RPC_STUB Command15_get_Parameters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_CommandType_Proxy(Command15 *This,CommandTypeEnum lCmdType);
  void __RPC_STUB Command15_put_CommandType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_CommandType_Proxy(Command15 *This,CommandTypeEnum *plCmdType);
  void __RPC_STUB Command15_get_CommandType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_get_Name_Proxy(Command15 *This,BSTR *pbstrName);
  void __RPC_STUB Command15_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command15_put_Name_Proxy(Command15 *This,BSTR bstrName);
  void __RPC_STUB Command15_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Command25_INTERFACE_DEFINED__
#define __Command25_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Command25;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Command25 : public Command15 {
  public:
    virtual HRESULT WINAPI get_State(LONG *plObjState) = 0;
    virtual HRESULT WINAPI Cancel(void) = 0;
  };
#else
  typedef struct Command25Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Command25 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Command25 *This);
      ULONG (WINAPI *Release)(Command25 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Command25 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Command25 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Command25 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Command25 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Command25 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActiveConnection)(Command25 *This,_ADOConnection **ppvObject);
      HRESULT (WINAPI *putref_ActiveADOConnection)(Command25 *This,_ADOConnection *pCon);
      HRESULT (WINAPI *put_ActiveConnection)(Command25 *This,VARIANT vConn);
      HRESULT (WINAPI *get_CommandText)(Command25 *This,BSTR *pbstr);
      HRESULT (WINAPI *put_CommandText)(Command25 *This,BSTR bstr);
      HRESULT (WINAPI *get_CommandTimeout)(Command25 *This,LONG *pl);
      HRESULT (WINAPI *put_CommandTimeout)(Command25 *This,LONG Timeout);
      HRESULT (WINAPI *get_Prepared)(Command25 *This,VARIANT_BOOL *pfPrepared);
      HRESULT (WINAPI *put_Prepared)(Command25 *This,VARIANT_BOOL fPrepared);
      HRESULT (WINAPI *Execute)(Command25 *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options,_ADORecordset **ppirs);
      HRESULT (WINAPI *CreateParameter)(Command25 *This,BSTR Name,DataTypeEnum Type,ParameterDirectionEnum Direction,ADO_LONGPTR Size,VARIANT Value,_ADOParameter **ppiprm);
      HRESULT (WINAPI *get_Parameters)(Command25 *This,ADOParameters **ppvObject);
      HRESULT (WINAPI *put_CommandType)(Command25 *This,CommandTypeEnum lCmdType);
      HRESULT (WINAPI *get_CommandType)(Command25 *This,CommandTypeEnum *plCmdType);
      HRESULT (WINAPI *get_Name)(Command25 *This,BSTR *pbstrName);
      HRESULT (WINAPI *put_Name)(Command25 *This,BSTR bstrName);
      HRESULT (WINAPI *get_State)(Command25 *This,LONG *plObjState);
      HRESULT (WINAPI *Cancel)(Command25 *This);
    END_INTERFACE
  } Command25Vtbl;
  struct Command25 {
    CONST_VTBL struct Command25Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Command25_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Command25_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Command25_Release(This) (This)->lpVtbl -> Release(This)
#define Command25_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Command25_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Command25_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Command25_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Command25_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Command25_get_ActiveConnection(This,ppvObject) (This)->lpVtbl -> get_ActiveConnection(This,ppvObject)
#define Command25_putref_ActiveConnection(This,pCon) (This)->lpVtbl -> putref_ActiveConnection(This,pCon)
#define Command25_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Command25_get_CommandText(This,pbstr) (This)->lpVtbl -> get_CommandText(This,pbstr)
#define Command25_put_CommandText(This,bstr) (This)->lpVtbl -> put_CommandText(This,bstr)
#define Command25_get_CommandTimeout(This,pl) (This)->lpVtbl -> get_CommandTimeout(This,pl)
#define Command25_put_CommandTimeout(This,Timeout) (This)->lpVtbl -> put_CommandTimeout(This,Timeout)
#define Command25_get_Prepared(This,pfPrepared) (This)->lpVtbl -> get_Prepared(This,pfPrepared)
#define Command25_put_Prepared(This,fPrepared) (This)->lpVtbl -> put_Prepared(This,fPrepared)
#define Command25_Execute(This,RecordsAffected,Parameters,Options,ppirs) (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define Command25_CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm) (This)->lpVtbl -> CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm)
#define Command25_get_Parameters(This,ppvObject) (This)->lpVtbl -> get_Parameters(This,ppvObject)
#define Command25_put_CommandType(This,lCmdType) (This)->lpVtbl -> put_CommandType(This,lCmdType)
#define Command25_get_CommandType(This,plCmdType) (This)->lpVtbl -> get_CommandType(This,plCmdType)
#define Command25_get_Name(This,pbstrName) (This)->lpVtbl -> get_Name(This,pbstrName)
#define Command25_put_Name(This,bstrName) (This)->lpVtbl -> put_Name(This,bstrName)
#define Command25_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define Command25_Cancel(This) (This)->lpVtbl -> Cancel(This)
#endif
#endif
  HRESULT WINAPI Command25_get_State_Proxy(Command25 *This,LONG *plObjState);
  void __RPC_STUB Command25_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Command25_Cancel_Proxy(Command25 *This);
  void __RPC_STUB Command25_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Command_INTERFACE_DEFINED__
#define ___Command_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Command;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOCommand : public Command25 {
  public:
    virtual HRESULT WINAPI putref_CommandStream(IUnknown *pStream) = 0;
    virtual HRESULT WINAPI get_CommandStream(VARIANT *pvStream) = 0;
    virtual HRESULT WINAPI put_Dialect(BSTR bstrDialect) = 0;
    virtual HRESULT WINAPI get_Dialect(BSTR *pbstrDialect) = 0;
    virtual HRESULT WINAPI put_NamedParameters(VARIANT_BOOL fNamedParameters) = 0;
    virtual HRESULT WINAPI get_NamedParameters(VARIANT_BOOL *pfNamedParameters) = 0;
  };
#else
  typedef struct _CommandVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOCommand *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOCommand *This);
      ULONG (WINAPI *Release)(_ADOCommand *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOCommand *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOCommand *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOCommand *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOCommand *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADOCommand *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActiveConnection)(_ADOCommand *This,_ADOConnection **ppvObject);
      HRESULT (WINAPI *putref_ActiveADOConnection)(_ADOCommand *This,_ADOConnection *pCon);
      HRESULT (WINAPI *put_ActiveConnection)(_ADOCommand *This,VARIANT vConn);
      HRESULT (WINAPI *get_CommandText)(_ADOCommand *This,BSTR *pbstr);
      HRESULT (WINAPI *put_CommandText)(_ADOCommand *This,BSTR bstr);
      HRESULT (WINAPI *get_CommandTimeout)(_ADOCommand *This,LONG *pl);
      HRESULT (WINAPI *put_CommandTimeout)(_ADOCommand *This,LONG Timeout);
      HRESULT (WINAPI *get_Prepared)(_ADOCommand *This,VARIANT_BOOL *pfPrepared);
      HRESULT (WINAPI *put_Prepared)(_ADOCommand *This,VARIANT_BOOL fPrepared);
      HRESULT (WINAPI *Execute)(_ADOCommand *This,VARIANT *RecordsAffected,VARIANT *Parameters,__LONG32 Options,_ADORecordset **ppirs);
      HRESULT (WINAPI *CreateParameter)(_ADOCommand *This,BSTR Name,DataTypeEnum Type,ParameterDirectionEnum Direction,ADO_LONGPTR Size,VARIANT Value,_ADOParameter **ppiprm);
      HRESULT (WINAPI *get_Parameters)(_ADOCommand *This,ADOParameters **ppvObject);
      HRESULT (WINAPI *put_CommandType)(_ADOCommand *This,CommandTypeEnum lCmdType);
      HRESULT (WINAPI *get_CommandType)(_ADOCommand *This,CommandTypeEnum *plCmdType);
      HRESULT (WINAPI *get_Name)(_ADOCommand *This,BSTR *pbstrName);
      HRESULT (WINAPI *put_Name)(_ADOCommand *This,BSTR bstrName);
      HRESULT (WINAPI *get_State)(_ADOCommand *This,LONG *plObjState);
      HRESULT (WINAPI *Cancel)(_ADOCommand *This);
      HRESULT (WINAPI *putref_CommandADOStream)(_ADOCommand *This,IUnknown *pStream);
      HRESULT (WINAPI *get_CommandStream)(_ADOCommand *This,VARIANT *pvStream);
      HRESULT (WINAPI *put_Dialect)(_ADOCommand *This,BSTR bstrDialect);
      HRESULT (WINAPI *get_Dialect)(_ADOCommand *This,BSTR *pbstrDialect);
      HRESULT (WINAPI *put_NamedParameters)(_ADOCommand *This,VARIANT_BOOL fNamedParameters);
      HRESULT (WINAPI *get_NamedParameters)(_ADOCommand *This,VARIANT_BOOL *pfNamedParameters);
    END_INTERFACE
  } _CommandVtbl;
  struct _Command {
    CONST_VTBL struct _CommandVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Command_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Command_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Command_Release(This) (This)->lpVtbl -> Release(This)
#define _Command_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Command_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Command_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Command_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Command_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Command_get_ActiveConnection(This,ppvObject) (This)->lpVtbl -> get_ActiveConnection(This,ppvObject)
#define _Command_putref_ActiveConnection(This,pCon) (This)->lpVtbl -> putref_ActiveConnection(This,pCon)
#define _Command_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define _Command_get_CommandText(This,pbstr) (This)->lpVtbl -> get_CommandText(This,pbstr)
#define _Command_put_CommandText(This,bstr) (This)->lpVtbl -> put_CommandText(This,bstr)
#define _Command_get_CommandTimeout(This,pl) (This)->lpVtbl -> get_CommandTimeout(This,pl)
#define _Command_put_CommandTimeout(This,Timeout) (This)->lpVtbl -> put_CommandTimeout(This,Timeout)
#define _Command_get_Prepared(This,pfPrepared) (This)->lpVtbl -> get_Prepared(This,pfPrepared)
#define _Command_put_Prepared(This,fPrepared) (This)->lpVtbl -> put_Prepared(This,fPrepared)
#define _Command_Execute(This,RecordsAffected,Parameters,Options,ppirs) (This)->lpVtbl -> Execute(This,RecordsAffected,Parameters,Options,ppirs)
#define _Command_CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm) (This)->lpVtbl -> CreateParameter(This,Name,Type,Direction,Size,Value,ppiprm)
#define _Command_get_Parameters(This,ppvObject) (This)->lpVtbl -> get_Parameters(This,ppvObject)
#define _Command_put_CommandType(This,lCmdType) (This)->lpVtbl -> put_CommandType(This,lCmdType)
#define _Command_get_CommandType(This,plCmdType) (This)->lpVtbl -> get_CommandType(This,plCmdType)
#define _Command_get_Name(This,pbstrName) (This)->lpVtbl -> get_Name(This,pbstrName)
#define _Command_put_Name(This,bstrName) (This)->lpVtbl -> put_Name(This,bstrName)
#define _Command_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define _Command_Cancel(This) (This)->lpVtbl -> Cancel(This)
#define _Command_putref_CommandStream(This,pStream) (This)->lpVtbl -> putref_CommandStream(This,pStream)
#define _Command_get_CommandStream(This,pvStream) (This)->lpVtbl -> get_CommandStream(This,pvStream)
#define _Command_put_Dialect(This,bstrDialect) (This)->lpVtbl -> put_Dialect(This,bstrDialect)
#define _Command_get_Dialect(This,pbstrDialect) (This)->lpVtbl -> get_Dialect(This,pbstrDialect)
#define _Command_put_NamedParameters(This,fNamedParameters) (This)->lpVtbl -> put_NamedParameters(This,fNamedParameters)
#define _Command_get_NamedParameters(This,pfNamedParameters) (This)->lpVtbl -> get_NamedParameters(This,pfNamedParameters)
#endif
#endif
  HRESULT WINAPI _Command_putref_CommandStream_Proxy(_ADOCommand *This,IUnknown *pStream);
  void __RPC_STUB _Command_putref_CommandStream_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Command_get_CommandStream_Proxy(_ADOCommand *This,VARIANT *pvStream);
  void __RPC_STUB _Command_get_CommandStream_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Command_put_Dialect_Proxy(_ADOCommand *This,BSTR bstrDialect);
  void __RPC_STUB _Command_put_Dialect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Command_get_Dialect_Proxy(_ADOCommand *This,BSTR *pbstrDialect);
  void __RPC_STUB _Command_get_Dialect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Command_put_NamedParameters_Proxy(_ADOCommand *This,VARIANT_BOOL fNamedParameters);
  void __RPC_STUB _Command_put_NamedParameters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Command_get_NamedParameters_Proxy(_ADOCommand *This,VARIANT_BOOL *pfNamedParameters);
  void __RPC_STUB _Command_get_NamedParameters_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ConnectionEventsVt_INTERFACE_DEFINED__
#define __ConnectionEventsVt_INTERFACE_DEFINED__

  EXTERN_C const IID IID_ConnectionEventsVt;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ConnectionEventsVt : public IUnknown {
  public:
    virtual HRESULT WINAPI InfoMessage(ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI BeginTransComplete(LONG TransactionLevel,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI CommitTransComplete(ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI RollbackTransComplete(ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI WillExecute(BSTR *Source,CursorTypeEnum *CursorType,LockTypeEnum *LockType,__LONG32 *Options,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI ExecuteComplete(LONG RecordsAffected,ADOError *pError,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI WillConnect(BSTR *ConnectionString,BSTR *UserID,BSTR *Password,__LONG32 *Options,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI ConnectComplete(ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
    virtual HRESULT WINAPI Disconnect(EventStatusEnum *adStatus,_ADOConnection *pConnection) = 0;
  };
#else
  typedef struct ConnectionEventsVtVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ConnectionEventsVt *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ConnectionEventsVt *This);
      ULONG (WINAPI *Release)(ConnectionEventsVt *This);
      HRESULT (WINAPI *InfoMessage)(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *BeginTransComplete)(ConnectionEventsVt *This,LONG TransactionLevel,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *CommitTransComplete)(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *RollbackTransComplete)(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *WillExecute)(ConnectionEventsVt *This,BSTR *Source,CursorTypeEnum *CursorType,LockTypeEnum *LockType,__LONG32 *Options,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection);
      HRESULT (WINAPI *ExecuteComplete)(ConnectionEventsVt *This,LONG RecordsAffected,ADOError *pError,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection);
      HRESULT (WINAPI *WillConnect)(ConnectionEventsVt *This,BSTR *ConnectionString,BSTR *UserID,BSTR *Password,__LONG32 *Options,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *ConnectComplete)(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
      HRESULT (WINAPI *Disconnect)(ConnectionEventsVt *This,EventStatusEnum *adStatus,_ADOConnection *pConnection);
    END_INTERFACE
  } ConnectionEventsVtVtbl;
  struct ConnectionEventsVt {
    CONST_VTBL struct ConnectionEventsVtVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ConnectionEventsVt_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ConnectionEventsVt_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ConnectionEventsVt_Release(This) (This)->lpVtbl -> Release(This)
#define ConnectionEventsVt_InfoMessage(This,pError,adStatus,pConnection) (This)->lpVtbl -> InfoMessage(This,pError,adStatus,pConnection)
#define ConnectionEventsVt_BeginTransComplete(This,TransactionLevel,pError,adStatus,pConnection) (This)->lpVtbl -> BeginTransComplete(This,TransactionLevel,pError,adStatus,pConnection)
#define ConnectionEventsVt_CommitTransComplete(This,pError,adStatus,pConnection) (This)->lpVtbl -> CommitTransComplete(This,pError,adStatus,pConnection)
#define ConnectionEventsVt_RollbackTransComplete(This,pError,adStatus,pConnection) (This)->lpVtbl -> RollbackTransComplete(This,pError,adStatus,pConnection)
#define ConnectionEventsVt_WillExecute(This,Source,CursorType,LockType,Options,adStatus,pCommand,pRecordset,pConnection) (This)->lpVtbl -> WillExecute(This,Source,CursorType,LockType,Options,adStatus,pCommand,pRecordset,pConnection)
#define ConnectionEventsVt_ExecuteComplete(This,RecordsAffected,pError,adStatus,pCommand,pRecordset,pConnection) (This)->lpVtbl -> ExecuteComplete(This,RecordsAffected,pError,adStatus,pCommand,pRecordset,pConnection)
#define ConnectionEventsVt_WillConnect(This,ConnectionString,UserID,Password,Options,adStatus,pConnection) (This)->lpVtbl -> WillConnect(This,ConnectionString,UserID,Password,Options,adStatus,pConnection)
#define ConnectionEventsVt_ConnectComplete(This,pError,adStatus,pConnection) (This)->lpVtbl -> ConnectComplete(This,pError,adStatus,pConnection)
#define ConnectionEventsVt_Disconnect(This,adStatus,pConnection) (This)->lpVtbl -> Disconnect(This,adStatus,pConnection)
#endif
#endif
  HRESULT WINAPI ConnectionEventsVt_InfoMessage_Proxy(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_InfoMessage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_BeginTransComplete_Proxy(ConnectionEventsVt *This,LONG TransactionLevel,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_BeginTransComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_CommitTransComplete_Proxy(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_CommitTransComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_RollbackTransComplete_Proxy(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_RollbackTransComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_WillExecute_Proxy(ConnectionEventsVt *This,BSTR *Source,CursorTypeEnum *CursorType,LockTypeEnum *LockType,__LONG32 *Options,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_WillExecute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_ExecuteComplete_Proxy(ConnectionEventsVt *This,LONG RecordsAffected,ADOError *pError,EventStatusEnum *adStatus,_ADOCommand *pCommand,_ADORecordset *pRecordset,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_ExecuteComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_WillConnect_Proxy(ConnectionEventsVt *This,BSTR *ConnectionString,BSTR *UserID,BSTR *Password,__LONG32 *Options,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_WillConnect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_ConnectComplete_Proxy(ConnectionEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_ConnectComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ConnectionEventsVt_Disconnect_Proxy(ConnectionEventsVt *This,EventStatusEnum *adStatus,_ADOConnection *pConnection);
  void __RPC_STUB ConnectionEventsVt_Disconnect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __RecordsetEventsVt_INTERFACE_DEFINED__
#define __RecordsetEventsVt_INTERFACE_DEFINED__
  EXTERN_C const IID IID_RecordsetEventsVt;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct RecordsetEventsVt : public IUnknown {
  public:
    virtual HRESULT WINAPI WillChangeField(LONG cFields,VARIANT Fields,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI FieldChangeComplete(LONG cFields,VARIANT Fields,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI WillChangeRecord(EventReasonEnum adReason,LONG cRecords,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI RecordChangeComplete(EventReasonEnum adReason,LONG cRecords,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI WillChangeRecordset(EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI RecordsetChangeComplete(EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI WillMove(EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI MoveComplete(EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI EndOfRecordset(VARIANT_BOOL *fMoreData,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI FetchProgress(__LONG32 Progress,__LONG32 MaxProgress,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
    virtual HRESULT WINAPI FetchComplete(ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset) = 0;
  };
#else
  typedef struct RecordsetEventsVtVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(RecordsetEventsVt *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(RecordsetEventsVt *This);
      ULONG (WINAPI *Release)(RecordsetEventsVt *This);
      HRESULT (WINAPI *WillChangeADOField)(RecordsetEventsVt *This,LONG cFields,VARIANT Fields,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *FieldChangeComplete)(RecordsetEventsVt *This,LONG cFields,VARIANT Fields,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *WillChangeADORecord)(RecordsetEventsVt *This,EventReasonEnum adReason,LONG cRecords,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *RecordChangeComplete)(RecordsetEventsVt *This,EventReasonEnum adReason,LONG cRecords,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *WillChangeADORecordset)(RecordsetEventsVt *This,EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *RecordsetChangeComplete)(RecordsetEventsVt *This,EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *WillMove)(RecordsetEventsVt *This,EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *MoveComplete)(RecordsetEventsVt *This,EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *EndOfADORecordset)(RecordsetEventsVt *This,VARIANT_BOOL *fMoreData,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *FetchProgress)(RecordsetEventsVt *This,__LONG32 Progress,__LONG32 MaxProgress,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
      HRESULT (WINAPI *FetchComplete)(RecordsetEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
    END_INTERFACE
  } RecordsetEventsVtVtbl;
  struct RecordsetEventsVt {
    CONST_VTBL struct RecordsetEventsVtVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define RecordsetEventsVt_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define RecordsetEventsVt_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define RecordsetEventsVt_Release(This) (This)->lpVtbl -> Release(This)
#define RecordsetEventsVt_WillChangeField(This,cFields,Fields,adStatus,pRecordset) (This)->lpVtbl -> WillChangeField(This,cFields,Fields,adStatus,pRecordset)
#define RecordsetEventsVt_FieldChangeComplete(This,cFields,Fields,pError,adStatus,pRecordset) (This)->lpVtbl -> FieldChangeComplete(This,cFields,Fields,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillChangeRecord(This,adReason,cRecords,adStatus,pRecordset) (This)->lpVtbl -> WillChangeRecord(This,adReason,cRecords,adStatus,pRecordset)
#define RecordsetEventsVt_RecordChangeComplete(This,adReason,cRecords,pError,adStatus,pRecordset) (This)->lpVtbl -> RecordChangeComplete(This,adReason,cRecords,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillChangeRecordset(This,adReason,adStatus,pRecordset) (This)->lpVtbl -> WillChangeRecordset(This,adReason,adStatus,pRecordset)
#define RecordsetEventsVt_RecordsetChangeComplete(This,adReason,pError,adStatus,pRecordset) (This)->lpVtbl -> RecordsetChangeComplete(This,adReason,pError,adStatus,pRecordset)
#define RecordsetEventsVt_WillMove(This,adReason,adStatus,pRecordset) (This)->lpVtbl -> WillMove(This,adReason,adStatus,pRecordset)
#define RecordsetEventsVt_MoveComplete(This,adReason,pError,adStatus,pRecordset) (This)->lpVtbl -> MoveComplete(This,adReason,pError,adStatus,pRecordset)
#define RecordsetEventsVt_EndOfRecordset(This,fMoreData,adStatus,pRecordset) (This)->lpVtbl -> EndOfRecordset(This,fMoreData,adStatus,pRecordset)
#define RecordsetEventsVt_FetchProgress(This,Progress,MaxProgress,adStatus,pRecordset) (This)->lpVtbl -> FetchProgress(This,Progress,MaxProgress,adStatus,pRecordset)
#define RecordsetEventsVt_FetchComplete(This,pError,adStatus,pRecordset) (This)->lpVtbl -> FetchComplete(This,pError,adStatus,pRecordset)
#endif
#endif
  HRESULT WINAPI RecordsetEventsVt_WillChangeField_Proxy(RecordsetEventsVt *This,LONG cFields,VARIANT Fields,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_WillChangeField_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_FieldChangeComplete_Proxy(RecordsetEventsVt *This,LONG cFields,VARIANT Fields,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_FieldChangeComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_WillChangeRecord_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,LONG cRecords,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_WillChangeRecord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_RecordChangeComplete_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,LONG cRecords,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_RecordChangeComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_WillChangeRecordset_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_WillChangeRecordset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_RecordsetChangeComplete_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_RecordsetChangeComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_WillMove_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_WillMove_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_MoveComplete_Proxy(RecordsetEventsVt *This,EventReasonEnum adReason,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_MoveComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_EndOfRecordset_Proxy(RecordsetEventsVt *This,VARIANT_BOOL *fMoreData,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_EndOfRecordset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_FetchProgress_Proxy(RecordsetEventsVt *This,__LONG32 Progress,__LONG32 MaxProgress,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_FetchProgress_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI RecordsetEventsVt_FetchComplete_Proxy(RecordsetEventsVt *This,ADOError *pError,EventStatusEnum *adStatus,_ADORecordset *pRecordset);
  void __RPC_STUB RecordsetEventsVt_FetchComplete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ConnectionEvents_DISPINTERFACE_DEFINED__
#define __ConnectionEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_ConnectionEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ConnectionEvents : public IDispatch {
  };
#else
  typedef struct ConnectionEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ConnectionEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ConnectionEvents *This);
      ULONG (WINAPI *Release)(ConnectionEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ConnectionEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ConnectionEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ConnectionEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ConnectionEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } ConnectionEventsVtbl;
  struct ConnectionEvents {
    CONST_VTBL struct ConnectionEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ConnectionEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ConnectionEvents_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ConnectionEvents_Release(This) (This)->lpVtbl -> Release(This)
#define ConnectionEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ConnectionEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ConnectionEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ConnectionEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

#ifndef __RecordsetEvents_DISPINTERFACE_DEFINED__
#define __RecordsetEvents_DISPINTERFACE_DEFINED__
  EXTERN_C const IID DIID_RecordsetEvents;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct RecordsetEvents : public IDispatch {
  };
#else
  typedef struct RecordsetEventsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(RecordsetEvents *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(RecordsetEvents *This);
      ULONG (WINAPI *Release)(RecordsetEvents *This);
      HRESULT (WINAPI *GetTypeInfoCount)(RecordsetEvents *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(RecordsetEvents *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(RecordsetEvents *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(RecordsetEvents *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
    END_INTERFACE
  } RecordsetEventsVtbl;
  struct RecordsetEvents {
    CONST_VTBL struct RecordsetEventsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define RecordsetEvents_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define RecordsetEvents_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define RecordsetEvents_Release(This) (This)->lpVtbl -> Release(This)
#define RecordsetEvents_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define RecordsetEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define RecordsetEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define RecordsetEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#endif
#endif
#endif

#ifndef __Connection15_INTERFACE_DEFINED__
#define __Connection15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Connection15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Connection15 : public _ADO {
  public:
    virtual HRESULT WINAPI get_ConnectionString(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_ConnectionString(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_CommandTimeout(LONG *plTimeout) = 0;
    virtual HRESULT WINAPI put_CommandTimeout(LONG lTimeout) = 0;
    virtual HRESULT WINAPI get_ConnectionTimeout(LONG *plTimeout) = 0;
    virtual HRESULT WINAPI put_ConnectionTimeout(LONG lTimeout) = 0;
    virtual HRESULT WINAPI get_Version(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI Execute(BSTR CommandText,VARIANT *RecordsAffected,__LONG32 Options,_ADORecordset **ppiRset) = 0;
    virtual HRESULT WINAPI BeginTrans(__LONG32 *TransactionLevel) = 0;
    virtual HRESULT WINAPI CommitTrans(void) = 0;
    virtual HRESULT WINAPI RollbackTrans(void) = 0;
    virtual HRESULT WINAPI Open(BSTR ConnectionString = NULL,BSTR UserID = NULL,BSTR Password = NULL,__LONG32 Options = adOptionUnspecified) = 0;
    virtual HRESULT WINAPI get_Errors(ADOErrors **ppvObject) = 0;
    virtual HRESULT WINAPI get_DefaultDatabase(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_DefaultDatabase(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_IsolationLevel(IsolationLevelEnum *Level) = 0;
    virtual HRESULT WINAPI put_IsolationLevel(IsolationLevelEnum Level) = 0;
    virtual HRESULT WINAPI get_Attributes(__LONG32 *plAttr) = 0;
    virtual HRESULT WINAPI put_Attributes(__LONG32 lAttr) = 0;
    virtual HRESULT WINAPI get_CursorLocation(CursorLocationEnum *plCursorLoc) = 0;
    virtual HRESULT WINAPI put_CursorLocation(CursorLocationEnum lCursorLoc) = 0;
    virtual HRESULT WINAPI get_Mode(ConnectModeEnum *plMode) = 0;
    virtual HRESULT WINAPI put_Mode(ConnectModeEnum lMode) = 0;
    virtual HRESULT WINAPI get_Provider(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_Provider(BSTR Provider) = 0;
    virtual HRESULT WINAPI get_State(LONG *plObjState) = 0;
    virtual HRESULT WINAPI OpenSchema(SchemaEnum Schema,VARIANT Restrictions,VARIANT SchemaID,_ADORecordset **pprset) = 0;
  };
#else
  typedef struct Connection15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Connection15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Connection15 *This);
      ULONG (WINAPI *Release)(Connection15 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Connection15 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Connection15 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Connection15 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Connection15 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Connection15 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ConnectionString)(Connection15 *This,BSTR *pbstr);
      HRESULT (WINAPI *put_ConnectionString)(Connection15 *This,BSTR bstr);
      HRESULT (WINAPI *get_CommandTimeout)(Connection15 *This,LONG *plTimeout);
      HRESULT (WINAPI *put_CommandTimeout)(Connection15 *This,LONG lTimeout);
      HRESULT (WINAPI *get_ConnectionTimeout)(Connection15 *This,LONG *plTimeout);
      HRESULT (WINAPI *put_ConnectionTimeout)(Connection15 *This,LONG lTimeout);
      HRESULT (WINAPI *get_Version)(Connection15 *This,BSTR *pbstr);
      HRESULT (WINAPI *Close)(Connection15 *This);
      HRESULT (WINAPI *Execute)(Connection15 *This,BSTR CommandText,VARIANT *RecordsAffected,__LONG32 Options,_ADORecordset **ppiRset);
      HRESULT (WINAPI *BeginTrans)(Connection15 *This,__LONG32 *TransactionLevel);
      HRESULT (WINAPI *CommitTrans)(Connection15 *This);
      HRESULT (WINAPI *RollbackTrans)(Connection15 *This);
      HRESULT (WINAPI *Open)(Connection15 *This,BSTR ConnectionString,BSTR UserID,BSTR Password,__LONG32 Options);
      HRESULT (WINAPI *get_Errors)(Connection15 *This,ADOErrors **ppvObject);
      HRESULT (WINAPI *get_DefaultDatabase)(Connection15 *This,BSTR *pbstr);
      HRESULT (WINAPI *put_DefaultDatabase)(Connection15 *This,BSTR bstr);
      HRESULT (WINAPI *get_IsolationLevel)(Connection15 *This,IsolationLevelEnum *Level);
      HRESULT (WINAPI *put_IsolationLevel)(Connection15 *This,IsolationLevelEnum Level);
      HRESULT (WINAPI *get_Attributes)(Connection15 *This,__LONG32 *plAttr);
      HRESULT (WINAPI *put_Attributes)(Connection15 *This,__LONG32 lAttr);
      HRESULT (WINAPI *get_CursorLocation)(Connection15 *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(Connection15 *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *get_Mode)(Connection15 *This,ConnectModeEnum *plMode);
      HRESULT (WINAPI *put_Mode)(Connection15 *This,ConnectModeEnum lMode);
      HRESULT (WINAPI *get_Provider)(Connection15 *This,BSTR *pbstr);
      HRESULT (WINAPI *put_Provider)(Connection15 *This,BSTR Provider);
      HRESULT (WINAPI *get_State)(Connection15 *This,LONG *plObjState);
      HRESULT (WINAPI *OpenSchema)(Connection15 *This,SchemaEnum Schema,VARIANT Restrictions,VARIANT SchemaID,_ADORecordset **pprset);
    END_INTERFACE
  } Connection15Vtbl;
  struct Connection15 {
    CONST_VTBL struct Connection15Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Connection15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Connection15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Connection15_Release(This) (This)->lpVtbl -> Release(This)
#define Connection15_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Connection15_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Connection15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Connection15_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Connection15_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Connection15_get_ConnectionString(This,pbstr) (This)->lpVtbl -> get_ConnectionString(This,pbstr)
#define Connection15_put_ConnectionString(This,bstr) (This)->lpVtbl -> put_ConnectionString(This,bstr)
#define Connection15_get_CommandTimeout(This,plTimeout) (This)->lpVtbl -> get_CommandTimeout(This,plTimeout)
#define Connection15_put_CommandTimeout(This,lTimeout) (This)->lpVtbl -> put_CommandTimeout(This,lTimeout)
#define Connection15_get_ConnectionTimeout(This,plTimeout) (This)->lpVtbl -> get_ConnectionTimeout(This,plTimeout)
#define Connection15_put_ConnectionTimeout(This,lTimeout) (This)->lpVtbl -> put_ConnectionTimeout(This,lTimeout)
#define Connection15_get_Version(This,pbstr) (This)->lpVtbl -> get_Version(This,pbstr)
#define Connection15_Close(This) (This)->lpVtbl -> Close(This)
#define Connection15_Execute(This,CommandText,RecordsAffected,Options,ppiRset) (This)->lpVtbl -> Execute(This,CommandText,RecordsAffected,Options,ppiRset)
#define Connection15_BeginTrans(This,TransactionLevel) (This)->lpVtbl -> BeginTrans(This,TransactionLevel)
#define Connection15_CommitTrans(This) (This)->lpVtbl -> CommitTrans(This)
#define Connection15_RollbackTrans(This) (This)->lpVtbl -> RollbackTrans(This)
#define Connection15_Open(This,ConnectionString,UserID,Password,Options) (This)->lpVtbl -> Open(This,ConnectionString,UserID,Password,Options)
#define Connection15_get_Errors(This,ppvObject) (This)->lpVtbl -> get_Errors(This,ppvObject)
#define Connection15_get_DefaultDatabase(This,pbstr) (This)->lpVtbl -> get_DefaultDatabase(This,pbstr)
#define Connection15_put_DefaultDatabase(This,bstr) (This)->lpVtbl -> put_DefaultDatabase(This,bstr)
#define Connection15_get_IsolationLevel(This,Level) (This)->lpVtbl -> get_IsolationLevel(This,Level)
#define Connection15_put_IsolationLevel(This,Level) (This)->lpVtbl -> put_IsolationLevel(This,Level)
#define Connection15_get_Attributes(This,plAttr) (This)->lpVtbl -> get_Attributes(This,plAttr)
#define Connection15_put_Attributes(This,lAttr) (This)->lpVtbl -> put_Attributes(This,lAttr)
#define Connection15_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Connection15_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Connection15_get_Mode(This,plMode) (This)->lpVtbl -> get_Mode(This,plMode)
#define Connection15_put_Mode(This,lMode) (This)->lpVtbl -> put_Mode(This,lMode)
#define Connection15_get_Provider(This,pbstr) (This)->lpVtbl -> get_Provider(This,pbstr)
#define Connection15_put_Provider(This,Provider) (This)->lpVtbl -> put_Provider(This,Provider)
#define Connection15_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define Connection15_OpenSchema(This,Schema,Restrictions,SchemaID,pprset) (This)->lpVtbl -> OpenSchema(This,Schema,Restrictions,SchemaID,pprset)
#endif
#endif
  HRESULT WINAPI Connection15_get_ConnectionString_Proxy(Connection15 *This,BSTR *pbstr);
  void __RPC_STUB Connection15_get_ConnectionString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_ConnectionString_Proxy(Connection15 *This,BSTR bstr);
  void __RPC_STUB Connection15_put_ConnectionString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_CommandTimeout_Proxy(Connection15 *This,LONG *plTimeout);
  void __RPC_STUB Connection15_get_CommandTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_CommandTimeout_Proxy(Connection15 *This,LONG lTimeout);
  void __RPC_STUB Connection15_put_CommandTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_ConnectionTimeout_Proxy(Connection15 *This,LONG *plTimeout);
  void __RPC_STUB Connection15_get_ConnectionTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_ConnectionTimeout_Proxy(Connection15 *This,LONG lTimeout);
  void __RPC_STUB Connection15_put_ConnectionTimeout_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_Version_Proxy(Connection15 *This,BSTR *pbstr);
  void __RPC_STUB Connection15_get_Version_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_Close_Proxy(Connection15 *This);
  void __RPC_STUB Connection15_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_Execute_Proxy(Connection15 *This,BSTR CommandText,VARIANT *RecordsAffected,__LONG32 Options,_ADORecordset **ppiRset);
  void __RPC_STUB Connection15_Execute_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_BeginTrans_Proxy(Connection15 *This,__LONG32 *TransactionLevel);
  void __RPC_STUB Connection15_BeginTrans_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_CommitTrans_Proxy(Connection15 *This);
  void __RPC_STUB Connection15_CommitTrans_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_RollbackTrans_Proxy(Connection15 *This);
  void __RPC_STUB Connection15_RollbackTrans_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_Open_Proxy(Connection15 *This,BSTR ConnectionString,BSTR UserID,BSTR Password,__LONG32 Options);
  void __RPC_STUB Connection15_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_Errors_Proxy(Connection15 *This,ADOErrors **ppvObject);
  void __RPC_STUB Connection15_get_Errors_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_DefaultDatabase_Proxy(Connection15 *This,BSTR *pbstr);
  void __RPC_STUB Connection15_get_DefaultDatabase_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_DefaultDatabase_Proxy(Connection15 *This,BSTR bstr);
  void __RPC_STUB Connection15_put_DefaultDatabase_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_IsolationLevel_Proxy(Connection15 *This,IsolationLevelEnum *Level);
  void __RPC_STUB Connection15_get_IsolationLevel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_IsolationLevel_Proxy(Connection15 *This,IsolationLevelEnum Level);
  void __RPC_STUB Connection15_put_IsolationLevel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_Attributes_Proxy(Connection15 *This,__LONG32 *plAttr);
  void __RPC_STUB Connection15_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_Attributes_Proxy(Connection15 *This,__LONG32 lAttr);
  void __RPC_STUB Connection15_put_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_CursorLocation_Proxy(Connection15 *This,CursorLocationEnum *plCursorLoc);
  void __RPC_STUB Connection15_get_CursorLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_CursorLocation_Proxy(Connection15 *This,CursorLocationEnum lCursorLoc);
  void __RPC_STUB Connection15_put_CursorLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_Mode_Proxy(Connection15 *This,ConnectModeEnum *plMode);
  void __RPC_STUB Connection15_get_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_Mode_Proxy(Connection15 *This,ConnectModeEnum lMode);
  void __RPC_STUB Connection15_put_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_Provider_Proxy(Connection15 *This,BSTR *pbstr);
  void __RPC_STUB Connection15_get_Provider_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_put_Provider_Proxy(Connection15 *This,BSTR Provider);
  void __RPC_STUB Connection15_put_Provider_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_get_State_Proxy(Connection15 *This,LONG *plObjState);
  void __RPC_STUB Connection15_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Connection15_OpenSchema_Proxy(Connection15 *This,SchemaEnum Schema,VARIANT Restrictions,VARIANT SchemaID,_ADORecordset **pprset);
  void __RPC_STUB Connection15_OpenSchema_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Connection_INTERFACE_DEFINED__
#define ___Connection_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Connection;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOConnection : public Connection15 {
  public:
    virtual HRESULT WINAPI Cancel(void) = 0;
  };
#else
  typedef struct _ConnectionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOConnection *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOConnection *This);
      ULONG (WINAPI *Release)(_ADOConnection *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOConnection *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOConnection *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOConnection *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOConnection *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADOConnection *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ConnectionString)(_ADOConnection *This,BSTR *pbstr);
      HRESULT (WINAPI *put_ConnectionString)(_ADOConnection *This,BSTR bstr);
      HRESULT (WINAPI *get_CommandTimeout)(_ADOConnection *This,LONG *plTimeout);
      HRESULT (WINAPI *put_CommandTimeout)(_ADOConnection *This,LONG lTimeout);
      HRESULT (WINAPI *get_ConnectionTimeout)(_ADOConnection *This,LONG *plTimeout);
      HRESULT (WINAPI *put_ConnectionTimeout)(_ADOConnection *This,LONG lTimeout);
      HRESULT (WINAPI *get_Version)(_ADOConnection *This,BSTR *pbstr);
      HRESULT (WINAPI *Close)(_ADOConnection *This);
      HRESULT (WINAPI *Execute)(_ADOConnection *This,BSTR CommandText,VARIANT *RecordsAffected,__LONG32 Options,_ADORecordset **ppiRset);
      HRESULT (WINAPI *BeginTrans)(_ADOConnection *This,__LONG32 *TransactionLevel);
      HRESULT (WINAPI *CommitTrans)(_ADOConnection *This);
      HRESULT (WINAPI *RollbackTrans)(_ADOConnection *This);
      HRESULT (WINAPI *Open)(_ADOConnection *This,BSTR ConnectionString,BSTR UserID,BSTR Password,__LONG32 Options);
      HRESULT (WINAPI *get_Errors)(_ADOConnection *This,ADOErrors **ppvObject);
      HRESULT (WINAPI *get_DefaultDatabase)(_ADOConnection *This,BSTR *pbstr);
      HRESULT (WINAPI *put_DefaultDatabase)(_ADOConnection *This,BSTR bstr);
      HRESULT (WINAPI *get_IsolationLevel)(_ADOConnection *This,IsolationLevelEnum *Level);
      HRESULT (WINAPI *put_IsolationLevel)(_ADOConnection *This,IsolationLevelEnum Level);
      HRESULT (WINAPI *get_Attributes)(_ADOConnection *This,__LONG32 *plAttr);
      HRESULT (WINAPI *put_Attributes)(_ADOConnection *This,__LONG32 lAttr);
      HRESULT (WINAPI *get_CursorLocation)(_ADOConnection *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(_ADOConnection *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *get_Mode)(_ADOConnection *This,ConnectModeEnum *plMode);
      HRESULT (WINAPI *put_Mode)(_ADOConnection *This,ConnectModeEnum lMode);
      HRESULT (WINAPI *get_Provider)(_ADOConnection *This,BSTR *pbstr);
      HRESULT (WINAPI *put_Provider)(_ADOConnection *This,BSTR Provider);
      HRESULT (WINAPI *get_State)(_ADOConnection *This,LONG *plObjState);
      HRESULT (WINAPI *OpenSchema)(_ADOConnection *This,SchemaEnum Schema,VARIANT Restrictions,VARIANT SchemaID,_ADORecordset **pprset);
      HRESULT (WINAPI *Cancel)(_ADOConnection *This);
    END_INTERFACE
  } _ConnectionVtbl;
  struct _Connection {
    CONST_VTBL struct _ConnectionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Connection_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Connection_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Connection_Release(This) (This)->lpVtbl -> Release(This)
#define _Connection_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Connection_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Connection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Connection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Connection_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Connection_get_ConnectionString(This,pbstr) (This)->lpVtbl -> get_ConnectionString(This,pbstr)
#define _Connection_put_ConnectionString(This,bstr) (This)->lpVtbl -> put_ConnectionString(This,bstr)
#define _Connection_get_CommandTimeout(This,plTimeout) (This)->lpVtbl -> get_CommandTimeout(This,plTimeout)
#define _Connection_put_CommandTimeout(This,lTimeout) (This)->lpVtbl -> put_CommandTimeout(This,lTimeout)
#define _Connection_get_ConnectionTimeout(This,plTimeout) (This)->lpVtbl -> get_ConnectionTimeout(This,plTimeout)
#define _Connection_put_ConnectionTimeout(This,lTimeout) (This)->lpVtbl -> put_ConnectionTimeout(This,lTimeout)
#define _Connection_get_Version(This,pbstr) (This)->lpVtbl -> get_Version(This,pbstr)
#define _Connection_Close(This) (This)->lpVtbl -> Close(This)
#define _Connection_Execute(This,CommandText,RecordsAffected,Options,ppiRset) (This)->lpVtbl -> Execute(This,CommandText,RecordsAffected,Options,ppiRset)
#define _Connection_BeginTrans(This,TransactionLevel) (This)->lpVtbl -> BeginTrans(This,TransactionLevel)
#define _Connection_CommitTrans(This) (This)->lpVtbl -> CommitTrans(This)
#define _Connection_RollbackTrans(This) (This)->lpVtbl -> RollbackTrans(This)
#define _Connection_Open(This,ConnectionString,UserID,Password,Options) (This)->lpVtbl -> Open(This,ConnectionString,UserID,Password,Options)
#define _Connection_get_Errors(This,ppvObject) (This)->lpVtbl -> get_Errors(This,ppvObject)
#define _Connection_get_DefaultDatabase(This,pbstr) (This)->lpVtbl -> get_DefaultDatabase(This,pbstr)
#define _Connection_put_DefaultDatabase(This,bstr) (This)->lpVtbl -> put_DefaultDatabase(This,bstr)
#define _Connection_get_IsolationLevel(This,Level) (This)->lpVtbl -> get_IsolationLevel(This,Level)
#define _Connection_put_IsolationLevel(This,Level) (This)->lpVtbl -> put_IsolationLevel(This,Level)
#define _Connection_get_Attributes(This,plAttr) (This)->lpVtbl -> get_Attributes(This,plAttr)
#define _Connection_put_Attributes(This,lAttr) (This)->lpVtbl -> put_Attributes(This,lAttr)
#define _Connection_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define _Connection_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define _Connection_get_Mode(This,plMode) (This)->lpVtbl -> get_Mode(This,plMode)
#define _Connection_put_Mode(This,lMode) (This)->lpVtbl -> put_Mode(This,lMode)
#define _Connection_get_Provider(This,pbstr) (This)->lpVtbl -> get_Provider(This,pbstr)
#define _Connection_put_Provider(This,Provider) (This)->lpVtbl -> put_Provider(This,Provider)
#define _Connection_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define _Connection_OpenSchema(This,Schema,Restrictions,SchemaID,pprset) (This)->lpVtbl -> OpenSchema(This,Schema,Restrictions,SchemaID,pprset)
#define _Connection_Cancel(This) (This)->lpVtbl -> Cancel(This)
#endif
#endif
  HRESULT WINAPI _Connection_Cancel_Proxy(_ADOConnection *This);
  void __RPC_STUB _Connection_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ADOConnectionConstruction15_INTERFACE_DEFINED__
#define __ADOConnectionConstruction15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADOConnectionConstruction15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOConnectionConstruction15 : public IUnknown {
  public:
    virtual HRESULT WINAPI get_DSO(IUnknown **ppDSO) = 0;
    virtual HRESULT WINAPI get_Session(IUnknown **ppSession) = 0;
    virtual HRESULT WINAPI WrapDSOandSession(IUnknown *pDSO,IUnknown *pSession) = 0;
  };
#else
  typedef struct ADOConnectionConstruction15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOConnectionConstruction15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOConnectionConstruction15 *This);
      ULONG (WINAPI *Release)(ADOConnectionConstruction15 *This);
      HRESULT (WINAPI *get_DSO)(ADOConnectionConstruction15 *This,IUnknown **ppDSO);
      HRESULT (WINAPI *get_Session)(ADOConnectionConstruction15 *This,IUnknown **ppSession);
      HRESULT (WINAPI *WrapDSOandSession)(ADOConnectionConstruction15 *This,IUnknown *pDSO,IUnknown *pSession);
    END_INTERFACE
  } ADOConnectionConstruction15Vtbl;
  struct ADOConnectionConstruction15 {
    CONST_VTBL struct ADOConnectionConstruction15Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADOConnectionConstruction15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOConnectionConstruction15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADOConnectionConstruction15_Release(This) (This)->lpVtbl -> Release(This)
#define ADOConnectionConstruction15_get_DSO(This,ppDSO) (This)->lpVtbl -> get_DSO(This,ppDSO)
#define ADOConnectionConstruction15_get_Session(This,ppSession) (This)->lpVtbl -> get_Session(This,ppSession)
#define ADOConnectionConstruction15_WrapDSOandSession(This,pDSO,pSession) (This)->lpVtbl -> WrapDSOandSession(This,pDSO,pSession)
#endif
#endif
  HRESULT WINAPI ADOConnectionConstruction15_get_DSO_Proxy(ADOConnectionConstruction15 *This,IUnknown **ppDSO);
  void __RPC_STUB ADOConnectionConstruction15_get_DSO_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADOConnectionConstruction15_get_Session_Proxy(ADOConnectionConstruction15 *This,IUnknown **ppSession);
  void __RPC_STUB ADOConnectionConstruction15_get_Session_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADOConnectionConstruction15_WrapDSOandSession_Proxy(ADOConnectionConstruction15 *This,IUnknown *pDSO,IUnknown *pSession);
  void __RPC_STUB ADOConnectionConstruction15_WrapDSOandSession_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ADOConnectionConstruction_INTERFACE_DEFINED__
#define __ADOConnectionConstruction_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADOConnectionConstruction;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOConnectionConstruction : public ADOConnectionConstruction15 {
  public:
  };
#else
  typedef struct ADOConnectionConstructionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOConnectionConstruction *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOConnectionConstruction *This);
      ULONG (WINAPI *Release)(ADOConnectionConstruction *This);
      HRESULT (WINAPI *get_DSO)(ADOConnectionConstruction *This,IUnknown **ppDSO);
      HRESULT (WINAPI *get_Session)(ADOConnectionConstruction *This,IUnknown **ppSession);
      HRESULT (WINAPI *WrapDSOandSession)(ADOConnectionConstruction *This,IUnknown *pDSO,IUnknown *pSession);
    END_INTERFACE
  } ADOConnectionConstructionVtbl;
  struct ADOConnectionConstruction {
    CONST_VTBL struct ADOConnectionConstructionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADOConnectionConstruction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOConnectionConstruction_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADOConnectionConstruction_Release(This) (This)->lpVtbl -> Release(This)
#define ADOConnectionConstruction_get_DSO(This,ppDSO) (This)->lpVtbl -> get_DSO(This,ppDSO)
#define ADOConnectionConstruction_get_Session(This,ppSession) (This)->lpVtbl -> get_Session(This,ppSession)
#define ADOConnectionConstruction_WrapDSOandSession(This,pDSO,pSession) (This)->lpVtbl -> WrapDSOandSession(This,pDSO,pSession)
#endif
#endif
#endif
  EXTERN_C const CLSID CLSID_Connection;
#ifdef __cplusplus
  Connection;
#endif

#ifndef ___Record_INTERFACE_DEFINED__
#define ___Record_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Record;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADORecord : public _ADO {
  public:
    virtual HRESULT WINAPI get_ActiveConnection(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(BSTR bstrConn) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(_ADOConnection *Con) = 0;
    virtual HRESULT WINAPI get_State(ObjectStateEnum *pState) = 0;
    virtual HRESULT WINAPI get_Source(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Source(BSTR Source) = 0;
    virtual HRESULT WINAPI putref_Source(IDispatch *Source) = 0;
    virtual HRESULT WINAPI get_Mode(ConnectModeEnum *pMode) = 0;
    virtual HRESULT WINAPI put_Mode(ConnectModeEnum Mode) = 0;
    virtual HRESULT WINAPI get_ParentURL(BSTR *pbstrParentURL) = 0;
    virtual HRESULT WINAPI MoveRecord(BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,MoveRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL) = 0;
    virtual HRESULT WINAPI CopyRecord(BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,CopyRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL) = 0;
    virtual HRESULT WINAPI DeleteRecord(BSTR Source = NULL,VARIANT_BOOL Async = 0) = 0;
    virtual HRESULT WINAPI Open(VARIANT Source,VARIANT ActiveConnection,ConnectModeEnum Mode = adModeUnknown,RecordCreateOptionsEnum CreateOptions = adFailIfNotExists,RecordOpenOptionsEnum Options = adOpenRecordUnspecified,BSTR UserName = NULL,BSTR Password = NULL) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI get_Fields(ADOFields **ppFlds) = 0;
    virtual HRESULT WINAPI get_RecordType(RecordTypeEnum *pType) = 0;
    virtual HRESULT WINAPI GetChildren(_ADORecordset **ppRSet) = 0;
    virtual HRESULT WINAPI Cancel(void) = 0;
  };
#else
  typedef struct _RecordVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADORecord *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADORecord *This);
      ULONG (WINAPI *Release)(_ADORecord *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADORecord *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADORecord *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADORecord *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADORecord *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADORecord *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActiveConnection)(_ADORecord *This,VARIANT *pvar);
      HRESULT (WINAPI *put_ActiveConnection)(_ADORecord *This,BSTR bstrConn);
      HRESULT (WINAPI *putref_ActiveADOConnection)(_ADORecord *This,_ADOConnection *Con);
      HRESULT (WINAPI *get_State)(_ADORecord *This,ObjectStateEnum *pState);
      HRESULT (WINAPI *get_Source)(_ADORecord *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Source)(_ADORecord *This,BSTR Source);
      HRESULT (WINAPI *putref_Source)(_ADORecord *This,IDispatch *Source);
      HRESULT (WINAPI *get_Mode)(_ADORecord *This,ConnectModeEnum *pMode);
      HRESULT (WINAPI *put_Mode)(_ADORecord *This,ConnectModeEnum Mode);
      HRESULT (WINAPI *get_ParentURL)(_ADORecord *This,BSTR *pbstrParentURL);
      HRESULT (WINAPI *MoveADORecord)(_ADORecord *This,BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,MoveRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL);
      HRESULT (WINAPI *CopyADORecord)(_ADORecord *This,BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,CopyRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL);
      HRESULT (WINAPI *DeleteADORecord)(_ADORecord *This,BSTR Source,VARIANT_BOOL Async);
      HRESULT (WINAPI *Open)(_ADORecord *This,VARIANT Source,VARIANT ActiveConnection,ConnectModeEnum Mode,RecordCreateOptionsEnum CreateOptions,RecordOpenOptionsEnum Options,BSTR UserName,BSTR Password);
      HRESULT (WINAPI *Close)(_ADORecord *This);
      HRESULT (WINAPI *get_Fields)(_ADORecord *This,ADOFields **ppFlds);
      HRESULT (WINAPI *get_RecordType)(_ADORecord *This,RecordTypeEnum *pType);
      HRESULT (WINAPI *GetChildren)(_ADORecord *This,_ADORecordset **ppRSet);
      HRESULT (WINAPI *Cancel)(_ADORecord *This);
    END_INTERFACE
  } _RecordVtbl;
  struct _Record {
    CONST_VTBL struct _RecordVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Record_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Record_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Record_Release(This) (This)->lpVtbl -> Release(This)
#define _Record_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Record_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Record_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Record_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Record_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Record_get_ActiveConnection(This,pvar) (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define _Record_put_ActiveConnection(This,bstrConn) (This)->lpVtbl -> put_ActiveConnection(This,bstrConn)
#define _Record_putref_ActiveConnection(This,Con) (This)->lpVtbl -> putref_ActiveConnection(This,Con)
#define _Record_get_State(This,pState) (This)->lpVtbl -> get_State(This,pState)
#define _Record_get_Source(This,pvar) (This)->lpVtbl -> get_Source(This,pvar)
#define _Record_put_Source(This,Source) (This)->lpVtbl -> put_Source(This,Source)
#define _Record_putref_Source(This,Source) (This)->lpVtbl -> putref_Source(This,Source)
#define _Record_get_Mode(This,pMode) (This)->lpVtbl -> get_Mode(This,pMode)
#define _Record_put_Mode(This,Mode) (This)->lpVtbl -> put_Mode(This,Mode)
#define _Record_get_ParentURL(This,pbstrParentURL) (This)->lpVtbl -> get_ParentURL(This,pbstrParentURL)
#define _Record_MoveRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL) (This)->lpVtbl -> MoveRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)
#define _Record_CopyRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL) (This)->lpVtbl -> CopyRecord(This,Source,Destination,UserName,Password,Options,Async,pbstrNewURL)
#define _Record_DeleteRecord(This,Source,Async) (This)->lpVtbl -> DeleteRecord(This,Source,Async)
#define _Record_Open(This,Source,ActiveConnection,Mode,CreateOptions,Options,UserName,Password) (This)->lpVtbl -> Open(This,Source,ActiveConnection,Mode,CreateOptions,Options,UserName,Password)
#define _Record_Close(This) (This)->lpVtbl -> Close(This)
#define _Record_get_Fields(This,ppFlds) (This)->lpVtbl -> get_Fields(This,ppFlds)
#define _Record_get_RecordType(This,pType) (This)->lpVtbl -> get_RecordType(This,pType)
#define _Record_GetChildren(This,ppRSet) (This)->lpVtbl -> GetChildren(This,ppRSet)
#define _Record_Cancel(This) (This)->lpVtbl -> Cancel(This)
#endif
#endif
  HRESULT WINAPI _Record_get_ActiveConnection_Proxy(_ADORecord *This,VARIANT *pvar);
  void __RPC_STUB _Record_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_put_ActiveConnection_Proxy(_ADORecord *This,BSTR bstrConn);
  void __RPC_STUB _Record_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_putref_ActiveConnection_Proxy(_ADORecord *This,_ADOConnection *Con);
  void __RPC_STUB _Record_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_State_Proxy(_ADORecord *This,ObjectStateEnum *pState);
  void __RPC_STUB _Record_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_Source_Proxy(_ADORecord *This,VARIANT *pvar);
  void __RPC_STUB _Record_get_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_put_Source_Proxy(_ADORecord *This,BSTR Source);
  void __RPC_STUB _Record_put_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_putref_Source_Proxy(_ADORecord *This,IDispatch *Source);
  void __RPC_STUB _Record_putref_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_Mode_Proxy(_ADORecord *This,ConnectModeEnum *pMode);
  void __RPC_STUB _Record_get_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_put_Mode_Proxy(_ADORecord *This,ConnectModeEnum Mode);
  void __RPC_STUB _Record_put_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_ParentURL_Proxy(_ADORecord *This,BSTR *pbstrParentURL);
  void __RPC_STUB _Record_get_ParentURL_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_MoveRecord_Proxy(_ADORecord *This,BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,MoveRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL);
  void __RPC_STUB _Record_MoveRecord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_CopyRecord_Proxy(_ADORecord *This,BSTR Source,BSTR Destination,BSTR UserName,BSTR Password,CopyRecordOptionsEnum Options,VARIANT_BOOL Async,BSTR *pbstrNewURL);
  void __RPC_STUB _Record_CopyRecord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_DeleteRecord_Proxy(_ADORecord *This,BSTR Source,VARIANT_BOOL Async);
  void __RPC_STUB _Record_DeleteRecord_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_Open_Proxy(_ADORecord *This,VARIANT Source,VARIANT ActiveConnection,ConnectModeEnum Mode,RecordCreateOptionsEnum CreateOptions,RecordOpenOptionsEnum Options,BSTR UserName,BSTR Password);
  void __RPC_STUB _Record_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_Close_Proxy(_ADORecord *This);
  void __RPC_STUB _Record_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_Fields_Proxy(_ADORecord *This,ADOFields **ppFlds);
  void __RPC_STUB _Record_get_Fields_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_get_RecordType_Proxy(_ADORecord *This,RecordTypeEnum *pType);
  void __RPC_STUB _Record_get_RecordType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_GetChildren_Proxy(_ADORecord *This,_ADORecordset **ppRSet);
  void __RPC_STUB _Record_GetChildren_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Record_Cancel_Proxy(_ADORecord *This);
  void __RPC_STUB _Record_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Record;
#ifdef __cplusplus
  Record;
#endif

#ifndef ___Stream_INTERFACE_DEFINED__
#define ___Stream_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Stream;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOStream : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Size(ADO_LONGPTR *pSize) = 0;
    virtual HRESULT WINAPI get_EOS(VARIANT_BOOL *pEOS) = 0;
    virtual HRESULT WINAPI get_Position(ADO_LONGPTR *pPos) = 0;
    virtual HRESULT WINAPI put_Position(ADO_LONGPTR Position) = 0;
    virtual HRESULT WINAPI get_Type(StreamTypeEnum *pType) = 0;
    virtual HRESULT WINAPI put_Type(StreamTypeEnum Type) = 0;
    virtual HRESULT WINAPI get_LineSeparator(LineSeparatorEnum *pLS) = 0;
    virtual HRESULT WINAPI put_LineSeparator(LineSeparatorEnum LineSeparator) = 0;
    virtual HRESULT WINAPI get_State(ObjectStateEnum *pState) = 0;
    virtual HRESULT WINAPI get_Mode(ConnectModeEnum *pMode) = 0;
    virtual HRESULT WINAPI put_Mode(ConnectModeEnum Mode) = 0;
    virtual HRESULT WINAPI get_Charset(BSTR *pbstrCharset) = 0;
    virtual HRESULT WINAPI put_Charset(BSTR Charset) = 0;
    virtual HRESULT WINAPI Read(__LONG32 NumBytes,VARIANT *pVal) = 0;
    virtual HRESULT WINAPI Open(VARIANT Source,ConnectModeEnum Mode = adModeUnknown,StreamOpenOptionsEnum Options = adOpenStreamUnspecified,BSTR UserName = NULL,BSTR Password = NULL) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI SkipLine(void) = 0;
    virtual HRESULT WINAPI Write(VARIANT Buffer) = 0;
    virtual HRESULT WINAPI SetEOS(void) = 0;
    virtual HRESULT WINAPI CopyTo(_ADOStream *DestStream,ADO_LONGPTR CharNumber = -1) = 0;
    virtual HRESULT WINAPI Flush(void) = 0;
    virtual HRESULT WINAPI SaveToFile(BSTR FileName,SaveOptionsEnum Options = adSaveCreateNotExist) = 0;
    virtual HRESULT WINAPI LoadFromFile(BSTR FileName) = 0;
    virtual HRESULT WINAPI ReadText(__LONG32 NumChars,BSTR *pbstr) = 0;
    virtual HRESULT WINAPI WriteText(BSTR Data,StreamWriteEnum Options = adWriteChar) = 0;
    virtual HRESULT WINAPI Cancel(void) = 0;
  };
#else
  typedef struct _StreamVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOStream *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOStream *This);
      ULONG (WINAPI *Release)(_ADOStream *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOStream *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOStream *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOStream *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOStream *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Size)(_ADOStream *This,ADO_LONGPTR *pSize);
      HRESULT (WINAPI *get_EOS)(_ADOStream *This,VARIANT_BOOL *pEOS);
      HRESULT (WINAPI *get_Position)(_ADOStream *This,ADO_LONGPTR *pPos);
      HRESULT (WINAPI *put_Position)(_ADOStream *This,ADO_LONGPTR Position);
      HRESULT (WINAPI *get_Type)(_ADOStream *This,StreamTypeEnum *pType);
      HRESULT (WINAPI *put_Type)(_ADOStream *This,StreamTypeEnum Type);
      HRESULT (WINAPI *get_LineSeparator)(_ADOStream *This,LineSeparatorEnum *pLS);
      HRESULT (WINAPI *put_LineSeparator)(_ADOStream *This,LineSeparatorEnum LineSeparator);
      HRESULT (WINAPI *get_State)(_ADOStream *This,ObjectStateEnum *pState);
      HRESULT (WINAPI *get_Mode)(_ADOStream *This,ConnectModeEnum *pMode);
      HRESULT (WINAPI *put_Mode)(_ADOStream *This,ConnectModeEnum Mode);
      HRESULT (WINAPI *get_Charset)(_ADOStream *This,BSTR *pbstrCharset);
      HRESULT (WINAPI *put_Charset)(_ADOStream *This,BSTR Charset);
      HRESULT (WINAPI *Read)(_ADOStream *This,__LONG32 NumBytes,VARIANT *pVal);
      HRESULT (WINAPI *Open)(_ADOStream *This,VARIANT Source,ConnectModeEnum Mode,StreamOpenOptionsEnum Options,BSTR UserName,BSTR Password);
      HRESULT (WINAPI *Close)(_ADOStream *This);
      HRESULT (WINAPI *SkipLine)(_ADOStream *This);
      HRESULT (WINAPI *Write)(_ADOStream *This,VARIANT Buffer);
      HRESULT (WINAPI *SetEOS)(_ADOStream *This);
      HRESULT (WINAPI *CopyTo)(_ADOStream *This,_ADOStream *DestStream,ADO_LONGPTR CharNumber);
      HRESULT (WINAPI *Flush)(_ADOStream *This);
      HRESULT (WINAPI *SaveToFile)(_ADOStream *This,BSTR FileName,SaveOptionsEnum Options);
      HRESULT (WINAPI *LoadFromFile)(_ADOStream *This,BSTR FileName);
      HRESULT (WINAPI *ReadText)(_ADOStream *This,__LONG32 NumChars,BSTR *pbstr);
      HRESULT (WINAPI *WriteText)(_ADOStream *This,BSTR Data,StreamWriteEnum Options);
      HRESULT (WINAPI *Cancel)(_ADOStream *This);
    END_INTERFACE
  } _StreamVtbl;
  struct _Stream {
    CONST_VTBL struct _StreamVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Stream_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Stream_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Stream_Release(This) (This)->lpVtbl -> Release(This)
#define _Stream_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Stream_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Stream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Stream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Stream_get_Size(This,pSize) (This)->lpVtbl -> get_Size(This,pSize)
#define _Stream_get_EOS(This,pEOS) (This)->lpVtbl -> get_EOS(This,pEOS)
#define _Stream_get_Position(This,pPos) (This)->lpVtbl -> get_Position(This,pPos)
#define _Stream_put_Position(This,Position) (This)->lpVtbl -> put_Position(This,Position)
#define _Stream_get_Type(This,pType) (This)->lpVtbl -> get_Type(This,pType)
#define _Stream_put_Type(This,Type) (This)->lpVtbl -> put_Type(This,Type)
#define _Stream_get_LineSeparator(This,pLS) (This)->lpVtbl -> get_LineSeparator(This,pLS)
#define _Stream_put_LineSeparator(This,LineSeparator) (This)->lpVtbl -> put_LineSeparator(This,LineSeparator)
#define _Stream_get_State(This,pState) (This)->lpVtbl -> get_State(This,pState)
#define _Stream_get_Mode(This,pMode) (This)->lpVtbl -> get_Mode(This,pMode)
#define _Stream_put_Mode(This,Mode) (This)->lpVtbl -> put_Mode(This,Mode)
#define _Stream_get_Charset(This,pbstrCharset) (This)->lpVtbl -> get_Charset(This,pbstrCharset)
#define _Stream_put_Charset(This,Charset) (This)->lpVtbl -> put_Charset(This,Charset)
#define _Stream_Read(This,NumBytes,pVal) (This)->lpVtbl -> Read(This,NumBytes,pVal)
#define _Stream_Open(This,Source,Mode,Options,UserName,Password) (This)->lpVtbl -> Open(This,Source,Mode,Options,UserName,Password)
#define _Stream_Close(This) (This)->lpVtbl -> Close(This)
#define _Stream_SkipLine(This) (This)->lpVtbl -> SkipLine(This)
#define _Stream_Write(This,Buffer) (This)->lpVtbl -> Write(This,Buffer)
#define _Stream_SetEOS(This) (This)->lpVtbl -> SetEOS(This)
#define _Stream_CopyTo(This,DestStream,CharNumber) (This)->lpVtbl -> CopyTo(This,DestStream,CharNumber)
#define _Stream_Flush(This) (This)->lpVtbl -> Flush(This)
#define _Stream_SaveToFile(This,FileName,Options) (This)->lpVtbl -> SaveToFile(This,FileName,Options)
#define _Stream_LoadFromFile(This,FileName) (This)->lpVtbl -> LoadFromFile(This,FileName)
#define _Stream_ReadText(This,NumChars,pbstr) (This)->lpVtbl -> ReadText(This,NumChars,pbstr)
#define _Stream_WriteText(This,Data,Options) (This)->lpVtbl -> WriteText(This,Data,Options)
#define _Stream_Cancel(This) (This)->lpVtbl -> Cancel(This)
#endif
#endif
  HRESULT WINAPI _Stream_get_Size_Proxy(_ADOStream *This,ADO_LONGPTR *pSize);
  void __RPC_STUB _Stream_get_Size_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_EOS_Proxy(_ADOStream *This,VARIANT_BOOL *pEOS);
  void __RPC_STUB _Stream_get_EOS_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_Position_Proxy(_ADOStream *This,ADO_LONGPTR *pPos);
  void __RPC_STUB _Stream_get_Position_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_put_Position_Proxy(_ADOStream *This,ADO_LONGPTR Position);
  void __RPC_STUB _Stream_put_Position_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_Type_Proxy(_ADOStream *This,StreamTypeEnum *pType);
  void __RPC_STUB _Stream_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_put_Type_Proxy(_ADOStream *This,StreamTypeEnum Type);
  void __RPC_STUB _Stream_put_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_LineSeparator_Proxy(_ADOStream *This,LineSeparatorEnum *pLS);
  void __RPC_STUB _Stream_get_LineSeparator_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_put_LineSeparator_Proxy(_ADOStream *This,LineSeparatorEnum LineSeparator);
  void __RPC_STUB _Stream_put_LineSeparator_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_State_Proxy(_ADOStream *This,ObjectStateEnum *pState);
  void __RPC_STUB _Stream_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_Mode_Proxy(_ADOStream *This,ConnectModeEnum *pMode);
  void __RPC_STUB _Stream_get_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_put_Mode_Proxy(_ADOStream *This,ConnectModeEnum Mode);
  void __RPC_STUB _Stream_put_Mode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_get_Charset_Proxy(_ADOStream *This,BSTR *pbstrCharset);
  void __RPC_STUB _Stream_get_Charset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_put_Charset_Proxy(_ADOStream *This,BSTR Charset);
  void __RPC_STUB _Stream_put_Charset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Read_Proxy(_ADOStream *This,__LONG32 NumBytes,VARIANT *pVal);
  void __RPC_STUB _Stream_Read_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Open_Proxy(_ADOStream *This,VARIANT Source,ConnectModeEnum Mode,StreamOpenOptionsEnum Options,BSTR UserName,BSTR Password);
  void __RPC_STUB _Stream_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Close_Proxy(_ADOStream *This);
  void __RPC_STUB _Stream_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_SkipLine_Proxy(_ADOStream *This);
  void __RPC_STUB _Stream_SkipLine_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Write_Proxy(_ADOStream *This,VARIANT Buffer);
  void __RPC_STUB _Stream_Write_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_SetEOS_Proxy(_ADOStream *This);
  void __RPC_STUB _Stream_SetEOS_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_CopyTo_Proxy(_ADOStream *This,_ADOStream *DestStream,ADO_LONGPTR CharNumber);
  void __RPC_STUB _Stream_CopyTo_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Flush_Proxy(_ADOStream *This);
  void __RPC_STUB _Stream_Flush_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_SaveToFile_Proxy(_ADOStream *This,BSTR FileName,SaveOptionsEnum Options);
  void __RPC_STUB _Stream_SaveToFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_LoadFromFile_Proxy(_ADOStream *This,BSTR FileName);
  void __RPC_STUB _Stream_LoadFromFile_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_ReadText_Proxy(_ADOStream *This,__LONG32 NumChars,BSTR *pbstr);
  void __RPC_STUB _Stream_ReadText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_WriteText_Proxy(_ADOStream *This,BSTR Data,StreamWriteEnum Options);
  void __RPC_STUB _Stream_WriteText_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Stream_Cancel_Proxy(_ADOStream *This);
  void __RPC_STUB _Stream_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Stream;
#ifdef __cplusplus
  Stream;
#endif

#ifndef __ADORecordConstruction_INTERFACE_DEFINED__
#define __ADORecordConstruction_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADORecordConstruction;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADORecordConstruction : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Row(IUnknown **ppRow) = 0;
    virtual HRESULT WINAPI put_Row(IUnknown *pRow) = 0;
    virtual HRESULT WINAPI put_ParentRow(IUnknown *pRow) = 0;
  };
#else
  typedef struct ADORecordConstructionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADORecordConstruction *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADORecordConstruction *This);
      ULONG (WINAPI *Release)(ADORecordConstruction *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADORecordConstruction *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADORecordConstruction *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADORecordConstruction *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADORecordConstruction *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Row)(ADORecordConstruction *This,IUnknown **ppRow);
      HRESULT (WINAPI *put_Row)(ADORecordConstruction *This,IUnknown *pRow);
      HRESULT (WINAPI *put_ParentRow)(ADORecordConstruction *This,IUnknown *pRow);
    END_INTERFACE
  } ADORecordConstructionVtbl;
  struct ADORecordConstruction {
    CONST_VTBL struct ADORecordConstructionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADORecordConstruction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADORecordConstruction_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADORecordConstruction_Release(This) (This)->lpVtbl -> Release(This)
#define ADORecordConstruction_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADORecordConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADORecordConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADORecordConstruction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ADORecordConstruction_get_Row(This,ppRow) (This)->lpVtbl -> get_Row(This,ppRow)
#define ADORecordConstruction_put_Row(This,pRow) (This)->lpVtbl -> put_Row(This,pRow)
#define ADORecordConstruction_put_ParentRow(This,pRow) (This)->lpVtbl -> put_ParentRow(This,pRow)
#endif
#endif
  HRESULT WINAPI ADORecordConstruction_get_Row_Proxy(ADORecordConstruction *This,IUnknown **ppRow);
  void __RPC_STUB ADORecordConstruction_get_Row_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordConstruction_put_Row_Proxy(ADORecordConstruction *This,IUnknown *pRow);
  void __RPC_STUB ADORecordConstruction_put_Row_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordConstruction_put_ParentRow_Proxy(ADORecordConstruction *This,IUnknown *pRow);
  void __RPC_STUB ADORecordConstruction_put_ParentRow_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ADOStreamConstruction_INTERFACE_DEFINED__
#define __ADOStreamConstruction_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADOStreamConstruction;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOStreamConstruction : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Stream(IUnknown **ppStm) = 0;
    virtual HRESULT WINAPI put_Stream(IUnknown *pStm) = 0;
  };
#else
  typedef struct ADOStreamConstructionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOStreamConstruction *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOStreamConstruction *This);
      ULONG (WINAPI *Release)(ADOStreamConstruction *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOStreamConstruction *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOStreamConstruction *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOStreamConstruction *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOStreamConstruction *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Stream)(ADOStreamConstruction *This,IUnknown **ppStm);
      HRESULT (WINAPI *put_Stream)(ADOStreamConstruction *This,IUnknown *pStm);
    END_INTERFACE
  } ADOStreamConstructionVtbl;
  struct ADOStreamConstruction {
    CONST_VTBL struct ADOStreamConstructionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADOStreamConstruction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOStreamConstruction_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADOStreamConstruction_Release(This) (This)->lpVtbl -> Release(This)
#define ADOStreamConstruction_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADOStreamConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADOStreamConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADOStreamConstruction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ADOStreamConstruction_get_Stream(This,ppStm) (This)->lpVtbl -> get_Stream(This,ppStm)
#define ADOStreamConstruction_put_Stream(This,pStm) (This)->lpVtbl -> put_Stream(This,pStm)
#endif
#endif
  HRESULT WINAPI ADOStreamConstruction_get_Stream_Proxy(ADOStreamConstruction *This,IUnknown **ppStm);
  void __RPC_STUB ADOStreamConstruction_get_Stream_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADOStreamConstruction_put_Stream_Proxy(ADOStreamConstruction *This,IUnknown *pStm);
  void __RPC_STUB ADOStreamConstruction_put_Stream_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ADOCommandConstruction_INTERFACE_DEFINED__
#define __ADOCommandConstruction_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADOCommandConstruction;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOCommandConstruction : public IUnknown {
  public:
    virtual HRESULT WINAPI get_OLEDBCommand(IUnknown **ppOLEDBCommand) = 0;
    virtual HRESULT WINAPI put_OLEDBCommand(IUnknown *pOLEDBCommand) = 0;
  };
#else
  typedef struct ADOCommandConstructionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOCommandConstruction *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOCommandConstruction *This);
      ULONG (WINAPI *Release)(ADOCommandConstruction *This);
      HRESULT (WINAPI *get_OLEDBCommand)(ADOCommandConstruction *This,IUnknown **ppOLEDBCommand);
      HRESULT (WINAPI *put_OLEDBCommand)(ADOCommandConstruction *This,IUnknown *pOLEDBCommand);
    END_INTERFACE
  } ADOCommandConstructionVtbl;
  struct ADOCommandConstruction {
    CONST_VTBL struct ADOCommandConstructionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADOCommandConstruction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADOCommandConstruction_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADOCommandConstruction_Release(This) (This)->lpVtbl -> Release(This)
#define ADOCommandConstruction_get_OLEDBCommand(This,ppOLEDBCommand) (This)->lpVtbl -> get_OLEDBCommand(This,ppOLEDBCommand)
#define ADOCommandConstruction_put_OLEDBCommand(This,pOLEDBCommand) (This)->lpVtbl -> put_OLEDBCommand(This,pOLEDBCommand)
#endif
#endif
  HRESULT WINAPI ADOCommandConstruction_get_OLEDBCommand_Proxy(ADOCommandConstruction *This,IUnknown **ppOLEDBCommand);
  void __RPC_STUB ADOCommandConstruction_get_OLEDBCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADOCommandConstruction_put_OLEDBCommand_Proxy(ADOCommandConstruction *This,IUnknown *pOLEDBCommand);
  void __RPC_STUB ADOCommandConstruction_put_OLEDBCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Command;
#ifdef __cplusplus
  Command;
#endif
  EXTERN_C const CLSID CLSID_Recordset;
#ifdef __cplusplus
  Recordset;
#endif

#ifndef __Recordset15_INTERFACE_DEFINED__
#define __Recordset15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Recordset15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Recordset15 : public _ADO {
  public:
    virtual HRESULT WINAPI get_AbsolutePosition(PositionEnum_Param *pl) = 0;
    virtual HRESULT WINAPI put_AbsolutePosition(PositionEnum_Param Position) = 0;
    virtual HRESULT WINAPI putref_ActiveConnection(IDispatch *pconn) = 0;
    virtual HRESULT WINAPI put_ActiveConnection(VARIANT vConn) = 0;
    virtual HRESULT WINAPI get_ActiveConnection(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_BOF(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_Bookmark(VARIANT *pvBookmark) = 0;
    virtual HRESULT WINAPI put_Bookmark(VARIANT vBookmark) = 0;
    virtual HRESULT WINAPI get_CacheSize(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI put_CacheSize(__LONG32 CacheSize) = 0;
    virtual HRESULT WINAPI get_CursorType(CursorTypeEnum *plCursorType) = 0;
    virtual HRESULT WINAPI put_CursorType(CursorTypeEnum lCursorType) = 0;
    virtual HRESULT WINAPI get_EOF(VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_Fields(ADOFields **ppvObject) = 0;
    virtual HRESULT WINAPI get_LockType(LockTypeEnum *plLockType) = 0;
    virtual HRESULT WINAPI put_LockType(LockTypeEnum lLockType) = 0;
    virtual HRESULT WINAPI get_MaxRecords(ADO_LONGPTR *plMaxRecords) = 0;
    virtual HRESULT WINAPI put_MaxRecords(ADO_LONGPTR lMaxRecords) = 0;
    virtual HRESULT WINAPI get_RecordCount(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI putref_Source(IDispatch *pcmd) = 0;
    virtual HRESULT WINAPI put_Source(BSTR bstrConn) = 0;
    virtual HRESULT WINAPI get_Source(VARIANT *pvSource) = 0;
    virtual HRESULT WINAPI AddNew(VARIANT FieldList,VARIANT Values) = 0;
    virtual HRESULT WINAPI CancelUpdate(void) = 0;
    virtual HRESULT WINAPI Close(void) = 0;
    virtual HRESULT WINAPI Delete(AffectEnum AffectRecords = adAffectCurrent) = 0;
    virtual HRESULT WINAPI GetRows(__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar) = 0;
    virtual HRESULT WINAPI Move(ADO_LONGPTR NumRecords,VARIANT Start) = 0;
    virtual HRESULT WINAPI MoveNext(void) = 0;
    virtual HRESULT WINAPI MovePrevious(void) = 0;
    virtual HRESULT WINAPI MoveFirst(void) = 0;
    virtual HRESULT WINAPI MoveLast(void) = 0;
    virtual HRESULT WINAPI Open(VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType = adOpenUnspecified,LockTypeEnum LockType = adLockUnspecified,LONG Options = adCmdUnspecified) = 0;
    virtual HRESULT WINAPI Requery(LONG Options = adOptionUnspecified) = 0;
    virtual HRESULT WINAPI _xResync(AffectEnum AffectRecords = adAffectAll) = 0;
    virtual HRESULT WINAPI Update(VARIANT Fields,VARIANT Values) = 0;
    virtual HRESULT WINAPI get_AbsolutePage(PositionEnum_Param *pl) = 0;
    virtual HRESULT WINAPI put_AbsolutePage(PositionEnum_Param Page) = 0;
    virtual HRESULT WINAPI get_EditMode(EditModeEnum *pl) = 0;
    virtual HRESULT WINAPI get_Filter(VARIANT *Criteria) = 0;
    virtual HRESULT WINAPI put_Filter(VARIANT Criteria) = 0;
    virtual HRESULT WINAPI get_PageCount(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI get_PageSize(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI put_PageSize(__LONG32 PageSize) = 0;
    virtual HRESULT WINAPI get_Sort(BSTR *Criteria) = 0;
    virtual HRESULT WINAPI put_Sort(BSTR Criteria) = 0;
    virtual HRESULT WINAPI get_Status(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI get_State(LONG *plObjState) = 0;
    virtual HRESULT WINAPI _xClone(_ADORecordset **ppvObject) = 0;
    virtual HRESULT WINAPI UpdateBatch(AffectEnum AffectRecords = adAffectAll) = 0;
    virtual HRESULT WINAPI CancelBatch(AffectEnum AffectRecords = adAffectAll) = 0;
    virtual HRESULT WINAPI get_CursorLocation(CursorLocationEnum *plCursorLoc) = 0;
    virtual HRESULT WINAPI put_CursorLocation(CursorLocationEnum lCursorLoc) = 0;
    virtual HRESULT WINAPI NextRecordset(VARIANT *RecordsAffected,_ADORecordset **ppiRs) = 0;
    virtual HRESULT WINAPI Supports(CursorOptionEnum CursorOptions,VARIANT_BOOL *pb) = 0;
    virtual HRESULT WINAPI get_Collect(VARIANT Index,VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Collect(VARIANT Index,VARIANT value) = 0;
    virtual HRESULT WINAPI get_MarshalOptions(MarshalOptionsEnum *peMarshal) = 0;
    virtual HRESULT WINAPI put_MarshalOptions(MarshalOptionsEnum eMarshal) = 0;
    virtual HRESULT WINAPI Find(BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start) = 0;
  };
#else
  typedef struct Recordset15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Recordset15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Recordset15 *This);
      ULONG (WINAPI *Release)(Recordset15 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Recordset15 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Recordset15 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Recordset15 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Recordset15 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Recordset15 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_AbsolutePosition)(Recordset15 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePosition)(Recordset15 *This,PositionEnum_Param Position);
      HRESULT (WINAPI *putref_ActiveADOConnection)(Recordset15 *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(Recordset15 *This,VARIANT vConn);
      HRESULT (WINAPI *get_ActiveConnection)(Recordset15 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_BOF)(Recordset15 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Bookmark)(Recordset15 *This,VARIANT *pvBookmark);
      HRESULT (WINAPI *put_Bookmark)(Recordset15 *This,VARIANT vBookmark);
      HRESULT (WINAPI *get_CacheSize)(Recordset15 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_CacheSize)(Recordset15 *This,__LONG32 CacheSize);
      HRESULT (WINAPI *get_CursorType)(Recordset15 *This,CursorTypeEnum *plCursorType);
      HRESULT (WINAPI *put_CursorType)(Recordset15 *This,CursorTypeEnum lCursorType);
      HRESULT (WINAPI *get_EOF)(Recordset15 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Fields)(Recordset15 *This,ADOFields **ppvObject);
      HRESULT (WINAPI *get_LockType)(Recordset15 *This,LockTypeEnum *plLockType);
      HRESULT (WINAPI *put_LockType)(Recordset15 *This,LockTypeEnum lLockType);
      HRESULT (WINAPI *get_MaxRecords)(Recordset15 *This,ADO_LONGPTR *plMaxRecords);
      HRESULT (WINAPI *put_MaxRecords)(Recordset15 *This,ADO_LONGPTR lMaxRecords);
      HRESULT (WINAPI *get_RecordCount)(Recordset15 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *putref_Source)(Recordset15 *This,IDispatch *pcmd);
      HRESULT (WINAPI *put_Source)(Recordset15 *This,BSTR bstrConn);
      HRESULT (WINAPI *get_Source)(Recordset15 *This,VARIANT *pvSource);
      HRESULT (WINAPI *AddNew)(Recordset15 *This,VARIANT FieldList,VARIANT Values);
      HRESULT (WINAPI *CancelUpdate)(Recordset15 *This);
      HRESULT (WINAPI *Close)(Recordset15 *This);
      HRESULT (WINAPI *Delete)(Recordset15 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *GetRows)(Recordset15 *This,__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar);
      HRESULT (WINAPI *Move)(Recordset15 *This,ADO_LONGPTR NumRecords,VARIANT Start);
      HRESULT (WINAPI *MoveNext)(Recordset15 *This);
      HRESULT (WINAPI *MovePrevious)(Recordset15 *This);
      HRESULT (WINAPI *MoveFirst)(Recordset15 *This);
      HRESULT (WINAPI *MoveLast)(Recordset15 *This);
      HRESULT (WINAPI *Open)(Recordset15 *This,VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType,LockTypeEnum LockType,LONG Options);
      HRESULT (WINAPI *Requery)(Recordset15 *This,LONG Options);
      HRESULT (WINAPI *_xResync)(Recordset15 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *Update)(Recordset15 *This,VARIANT Fields,VARIANT Values);
      HRESULT (WINAPI *get_AbsolutePage)(Recordset15 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePage)(Recordset15 *This,PositionEnum_Param Page);
      HRESULT (WINAPI *get_EditMode)(Recordset15 *This,EditModeEnum *pl);
      HRESULT (WINAPI *get_Filter)(Recordset15 *This,VARIANT *Criteria);
      HRESULT (WINAPI *put_Filter)(Recordset15 *This,VARIANT Criteria);
      HRESULT (WINAPI *get_PageCount)(Recordset15 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_PageSize)(Recordset15 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_PageSize)(Recordset15 *This,__LONG32 PageSize);
      HRESULT (WINAPI *get_Sort)(Recordset15 *This,BSTR *Criteria);
      HRESULT (WINAPI *put_Sort)(Recordset15 *This,BSTR Criteria);
      HRESULT (WINAPI *get_Status)(Recordset15 *This,__LONG32 *pl);
      HRESULT (WINAPI *get_State)(Recordset15 *This,LONG *plObjState);
      HRESULT (WINAPI *_xClone)(Recordset15 *This,_ADORecordset **ppvObject);
      HRESULT (WINAPI *UpdateBatch)(Recordset15 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *CancelBatch)(Recordset15 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *get_CursorLocation)(Recordset15 *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(Recordset15 *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *NextADORecordset)(Recordset15 *This,VARIANT *RecordsAffected,_ADORecordset **ppiRs);
      HRESULT (WINAPI *Supports)(Recordset15 *This,CursorOptionEnum CursorOptions,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Collect)(Recordset15 *This,VARIANT Index,VARIANT *pvar);
      HRESULT (WINAPI *put_Collect)(Recordset15 *This,VARIANT Index,VARIANT value);
      HRESULT (WINAPI *get_MarshalOptions)(Recordset15 *This,MarshalOptionsEnum *peMarshal);
      HRESULT (WINAPI *put_MarshalOptions)(Recordset15 *This,MarshalOptionsEnum eMarshal);
      HRESULT (WINAPI *Find)(Recordset15 *This,BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start);
    END_INTERFACE
  } Recordset15Vtbl;
  struct Recordset15 {
    CONST_VTBL struct Recordset15Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Recordset15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Recordset15_Release(This) (This)->lpVtbl -> Release(This)
#define Recordset15_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset15_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset15_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Recordset15_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset15_get_AbsolutePosition(This,pl) (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset15_put_AbsolutePosition(This,Position) (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset15_putref_ActiveConnection(This,pconn) (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset15_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset15_get_ActiveConnection(This,pvar) (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset15_get_BOF(This,pb) (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset15_get_Bookmark(This,pvBookmark) (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset15_put_Bookmark(This,vBookmark) (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset15_get_CacheSize(This,pl) (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset15_put_CacheSize(This,CacheSize) (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset15_get_CursorType(This,plCursorType) (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset15_put_CursorType(This,lCursorType) (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset15_get_EOF(This,pb) (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset15_get_Fields(This,ppvObject) (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset15_get_LockType(This,plLockType) (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset15_put_LockType(This,lLockType) (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset15_get_MaxRecords(This,plMaxRecords) (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset15_put_MaxRecords(This,lMaxRecords) (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset15_get_RecordCount(This,pl) (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset15_putref_Source(This,pcmd) (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset15_put_Source(This,bstrConn) (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset15_get_Source(This,pvSource) (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset15_AddNew(This,FieldList,Values) (This)->lpVtbl -> AddNew(This,FieldList,Values)
#define Recordset15_CancelUpdate(This) (This)->lpVtbl -> CancelUpdate(This)
#define Recordset15_Close(This) (This)->lpVtbl -> Close(This)
#define Recordset15_Delete(This,AffectRecords) (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset15_GetRows(This,Rows,Start,Fields,pvar) (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset15_Move(This,NumRecords,Start) (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset15_MoveNext(This) (This)->lpVtbl -> MoveNext(This)
#define Recordset15_MovePrevious(This) (This)->lpVtbl -> MovePrevious(This)
#define Recordset15_MoveFirst(This) (This)->lpVtbl -> MoveFirst(This)
#define Recordset15_MoveLast(This) (This)->lpVtbl -> MoveLast(This)
#define Recordset15_Open(This,Source,ActiveConnection,CursorType,LockType,Options) (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset15_Requery(This,Options) (This)->lpVtbl -> Requery(This,Options)
#define Recordset15__xResync(This,AffectRecords) (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset15_Update(This,Fields,Values) (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset15_get_AbsolutePage(This,pl) (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset15_put_AbsolutePage(This,Page) (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset15_get_EditMode(This,pl) (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset15_get_Filter(This,Criteria) (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset15_put_Filter(This,Criteria) (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset15_get_PageCount(This,pl) (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset15_get_PageSize(This,pl) (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset15_put_PageSize(This,PageSize) (This)->lpVtbl -> put_PageSize(This,PageSize)
#define Recordset15_get_Sort(This,Criteria) (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset15_put_Sort(This,Criteria) (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset15_get_Status(This,pl) (This)->lpVtbl -> get_Status(This,pl)
#define Recordset15_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset15__xClone(This,ppvObject) (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset15_UpdateBatch(This,AffectRecords) (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset15_CancelBatch(This,AffectRecords) (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset15_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset15_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset15_NextRecordset(This,RecordsAffected,ppiRs) (This)->lpVtbl -> NextRecordset(This,RecordsAffected,ppiRs)
#define Recordset15_Supports(This,CursorOptions,pb) (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset15_get_Collect(This,Index,pvar) (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset15_put_Collect(This,Index,value) (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset15_get_MarshalOptions(This,peMarshal) (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset15_put_MarshalOptions(This,eMarshal) (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset15_Find(This,Criteria,SkipRecords,SearchDirection,Start) (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#endif
#endif
  HRESULT WINAPI Recordset15_get_AbsolutePosition_Proxy(Recordset15 *This,PositionEnum_Param *pl);
  void __RPC_STUB Recordset15_get_AbsolutePosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_AbsolutePosition_Proxy(Recordset15 *This,PositionEnum_Param Position);
  void __RPC_STUB Recordset15_put_AbsolutePosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_putref_ActiveConnection_Proxy(Recordset15 *This,IDispatch *pconn);
  void __RPC_STUB Recordset15_putref_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_ActiveConnection_Proxy(Recordset15 *This,VARIANT vConn);
  void __RPC_STUB Recordset15_put_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_ActiveConnection_Proxy(Recordset15 *This,VARIANT *pvar);
  void __RPC_STUB Recordset15_get_ActiveConnection_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_BOF_Proxy(Recordset15 *This,VARIANT_BOOL *pb);
  void __RPC_STUB Recordset15_get_BOF_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Bookmark_Proxy(Recordset15 *This,VARIANT *pvBookmark);
  void __RPC_STUB Recordset15_get_Bookmark_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_Bookmark_Proxy(Recordset15 *This,VARIANT vBookmark);
  void __RPC_STUB Recordset15_put_Bookmark_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_CacheSize_Proxy(Recordset15 *This,__LONG32 *pl);
  void __RPC_STUB Recordset15_get_CacheSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_CacheSize_Proxy(Recordset15 *This,__LONG32 CacheSize);
  void __RPC_STUB Recordset15_put_CacheSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_CursorType_Proxy(Recordset15 *This,CursorTypeEnum *plCursorType);
  void __RPC_STUB Recordset15_get_CursorType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_CursorType_Proxy(Recordset15 *This,CursorTypeEnum lCursorType);
  void __RPC_STUB Recordset15_put_CursorType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_EOF_Proxy(Recordset15 *This,VARIANT_BOOL *pb);
  void __RPC_STUB Recordset15_get_EOF_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Fields_Proxy(Recordset15 *This,ADOFields **ppvObject);
  void __RPC_STUB Recordset15_get_Fields_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_LockType_Proxy(Recordset15 *This,LockTypeEnum *plLockType);
  void __RPC_STUB Recordset15_get_LockType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_LockType_Proxy(Recordset15 *This,LockTypeEnum lLockType);
  void __RPC_STUB Recordset15_put_LockType_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_MaxRecords_Proxy(Recordset15 *This,ADO_LONGPTR *plMaxRecords);
  void __RPC_STUB Recordset15_get_MaxRecords_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_MaxRecords_Proxy(Recordset15 *This,ADO_LONGPTR lMaxRecords);
  void __RPC_STUB Recordset15_put_MaxRecords_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_RecordCount_Proxy(Recordset15 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Recordset15_get_RecordCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_putref_Source_Proxy(Recordset15 *This,IDispatch *pcmd);
  void __RPC_STUB Recordset15_putref_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_Source_Proxy(Recordset15 *This,BSTR bstrConn);
  void __RPC_STUB Recordset15_put_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Source_Proxy(Recordset15 *This,VARIANT *pvSource);
  void __RPC_STUB Recordset15_get_Source_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_AddNew_Proxy(Recordset15 *This,VARIANT FieldList,VARIANT Values);
  void __RPC_STUB Recordset15_AddNew_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_CancelUpdate_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_CancelUpdate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Close_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_Close_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Delete_Proxy(Recordset15 *This,AffectEnum AffectRecords);
  void __RPC_STUB Recordset15_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_GetRows_Proxy(Recordset15 *This,__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar);
  void __RPC_STUB Recordset15_GetRows_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Move_Proxy(Recordset15 *This,ADO_LONGPTR NumRecords,VARIANT Start);
  void __RPC_STUB Recordset15_Move_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_MoveNext_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_MoveNext_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_MovePrevious_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_MovePrevious_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_MoveFirst_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_MoveFirst_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_MoveLast_Proxy(Recordset15 *This);
  void __RPC_STUB Recordset15_MoveLast_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Open_Proxy(Recordset15 *This,VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType,LockTypeEnum LockType,LONG Options);
  void __RPC_STUB Recordset15_Open_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Requery_Proxy(Recordset15 *This,LONG Options);
  void __RPC_STUB Recordset15_Requery_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15__xResync_Proxy(Recordset15 *This,AffectEnum AffectRecords);
  void __RPC_STUB Recordset15__xResync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Update_Proxy(Recordset15 *This,VARIANT Fields,VARIANT Values);
  void __RPC_STUB Recordset15_Update_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_AbsolutePage_Proxy(Recordset15 *This,PositionEnum_Param *pl);
  void __RPC_STUB Recordset15_get_AbsolutePage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_AbsolutePage_Proxy(Recordset15 *This,PositionEnum_Param Page);
  void __RPC_STUB Recordset15_put_AbsolutePage_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_EditMode_Proxy(Recordset15 *This,EditModeEnum *pl);
  void __RPC_STUB Recordset15_get_EditMode_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Filter_Proxy(Recordset15 *This,VARIANT *Criteria);
  void __RPC_STUB Recordset15_get_Filter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_Filter_Proxy(Recordset15 *This,VARIANT Criteria);
  void __RPC_STUB Recordset15_put_Filter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_PageCount_Proxy(Recordset15 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Recordset15_get_PageCount_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_PageSize_Proxy(Recordset15 *This,__LONG32 *pl);
  void __RPC_STUB Recordset15_get_PageSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_PageSize_Proxy(Recordset15 *This,__LONG32 PageSize);
  void __RPC_STUB Recordset15_put_PageSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Sort_Proxy(Recordset15 *This,BSTR *Criteria);
  void __RPC_STUB Recordset15_get_Sort_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_Sort_Proxy(Recordset15 *This,BSTR Criteria);
  void __RPC_STUB Recordset15_put_Sort_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Status_Proxy(Recordset15 *This,__LONG32 *pl);
  void __RPC_STUB Recordset15_get_Status_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_State_Proxy(Recordset15 *This,LONG *plObjState);
  void __RPC_STUB Recordset15_get_State_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15__xClone_Proxy(Recordset15 *This,_ADORecordset **ppvObject);
  void __RPC_STUB Recordset15__xClone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_UpdateBatch_Proxy(Recordset15 *This,AffectEnum AffectRecords);
  void __RPC_STUB Recordset15_UpdateBatch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_CancelBatch_Proxy(Recordset15 *This,AffectEnum AffectRecords);
  void __RPC_STUB Recordset15_CancelBatch_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_CursorLocation_Proxy(Recordset15 *This,CursorLocationEnum *plCursorLoc);
  void __RPC_STUB Recordset15_get_CursorLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_CursorLocation_Proxy(Recordset15 *This,CursorLocationEnum lCursorLoc);
  void __RPC_STUB Recordset15_put_CursorLocation_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_NextRecordset_Proxy(Recordset15 *This,VARIANT *RecordsAffected,_ADORecordset **ppiRs);
  void __RPC_STUB Recordset15_NextRecordset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Supports_Proxy(Recordset15 *This,CursorOptionEnum CursorOptions,VARIANT_BOOL *pb);
  void __RPC_STUB Recordset15_Supports_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_Collect_Proxy(Recordset15 *This,VARIANT Index,VARIANT *pvar);
  void __RPC_STUB Recordset15_get_Collect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_Collect_Proxy(Recordset15 *This,VARIANT Index,VARIANT value);
  void __RPC_STUB Recordset15_put_Collect_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_get_MarshalOptions_Proxy(Recordset15 *This,MarshalOptionsEnum *peMarshal);
  void __RPC_STUB Recordset15_get_MarshalOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_put_MarshalOptions_Proxy(Recordset15 *This,MarshalOptionsEnum eMarshal);
  void __RPC_STUB Recordset15_put_MarshalOptions_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset15_Find_Proxy(Recordset15 *This,BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start);
  void __RPC_STUB Recordset15_Find_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Recordset20_INTERFACE_DEFINED__
#define __Recordset20_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Recordset20;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Recordset20 : public Recordset15 {
  public:
    virtual HRESULT WINAPI Cancel(void) = 0;
    virtual HRESULT WINAPI get_DataSource(IUnknown **ppunkDataSource) = 0;
    virtual HRESULT WINAPI putref_DataSource(IUnknown *punkDataSource) = 0;
    virtual HRESULT WINAPI _xSave(BSTR FileName = NULL,PersistFormatEnum PersistFormat = adPersistADTG) = 0;
    virtual HRESULT WINAPI get_ActiveCommand(IDispatch **ppCmd) = 0;
    virtual HRESULT WINAPI put_StayInSync(VARIANT_BOOL bStayInSync) = 0;
    virtual HRESULT WINAPI get_StayInSync(VARIANT_BOOL *pbStayInSync) = 0;
    virtual HRESULT WINAPI GetString(StringFormatEnum StringFormat,__LONG32 NumRows,BSTR ColumnDelimeter,BSTR RowDelimeter,BSTR NullExpr,BSTR *pRetString) = 0;
    virtual HRESULT WINAPI get_DataMember(BSTR *pbstrDataMember) = 0;
    virtual HRESULT WINAPI put_DataMember(BSTR bstrDataMember) = 0;
    virtual HRESULT WINAPI CompareBookmarks(VARIANT Bookmark1,VARIANT Bookmark2,CompareEnum *pCompare) = 0;
    virtual HRESULT WINAPI Clone(LockTypeEnum LockType,_ADORecordset **ppvObject) = 0;
    virtual HRESULT WINAPI Resync(AffectEnum AffectRecords = adAffectAll,ResyncEnum ResyncValues = adResyncAllValues) = 0;
  };
#else
  typedef struct Recordset20Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Recordset20 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Recordset20 *This);
      ULONG (WINAPI *Release)(Recordset20 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Recordset20 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Recordset20 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Recordset20 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Recordset20 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Recordset20 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_AbsolutePosition)(Recordset20 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePosition)(Recordset20 *This,PositionEnum_Param Position);
      HRESULT (WINAPI *putref_ActiveADOConnection)(Recordset20 *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(Recordset20 *This,VARIANT vConn);
      HRESULT (WINAPI *get_ActiveConnection)(Recordset20 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_BOF)(Recordset20 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Bookmark)(Recordset20 *This,VARIANT *pvBookmark);
      HRESULT (WINAPI *put_Bookmark)(Recordset20 *This,VARIANT vBookmark);
      HRESULT (WINAPI *get_CacheSize)(Recordset20 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_CacheSize)(Recordset20 *This,__LONG32 CacheSize);
      HRESULT (WINAPI *get_CursorType)(Recordset20 *This,CursorTypeEnum *plCursorType);
      HRESULT (WINAPI *put_CursorType)(Recordset20 *This,CursorTypeEnum lCursorType);
      HRESULT (WINAPI *get_EOF)(Recordset20 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Fields)(Recordset20 *This,ADOFields **ppvObject);
      HRESULT (WINAPI *get_LockType)(Recordset20 *This,LockTypeEnum *plLockType);
      HRESULT (WINAPI *put_LockType)(Recordset20 *This,LockTypeEnum lLockType);
      HRESULT (WINAPI *get_MaxRecords)(Recordset20 *This,ADO_LONGPTR *plMaxRecords);
      HRESULT (WINAPI *put_MaxRecords)(Recordset20 *This,ADO_LONGPTR lMaxRecords);
      HRESULT (WINAPI *get_RecordCount)(Recordset20 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *putref_Source)(Recordset20 *This,IDispatch *pcmd);
      HRESULT (WINAPI *put_Source)(Recordset20 *This,BSTR bstrConn);
      HRESULT (WINAPI *get_Source)(Recordset20 *This,VARIANT *pvSource);
      HRESULT (WINAPI *AddNew)(Recordset20 *This,VARIANT FieldList,VARIANT Values);
      HRESULT (WINAPI *CancelUpdate)(Recordset20 *This);
      HRESULT (WINAPI *Close)(Recordset20 *This);
      HRESULT (WINAPI *Delete)(Recordset20 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *GetRows)(Recordset20 *This,__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar);
      HRESULT (WINAPI *Move)(Recordset20 *This,ADO_LONGPTR NumRecords,VARIANT Start);
      HRESULT (WINAPI *MoveNext)(Recordset20 *This);
      HRESULT (WINAPI *MovePrevious)(Recordset20 *This);
      HRESULT (WINAPI *MoveFirst)(Recordset20 *This);
      HRESULT (WINAPI *MoveLast)(Recordset20 *This);
      HRESULT (WINAPI *Open)(Recordset20 *This,VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType,LockTypeEnum LockType,LONG Options);
      HRESULT (WINAPI *Requery)(Recordset20 *This,LONG Options);
      HRESULT (WINAPI *_xResync)(Recordset20 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *Update)(Recordset20 *This,VARIANT Fields,VARIANT Values);
      HRESULT (WINAPI *get_AbsolutePage)(Recordset20 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePage)(Recordset20 *This,PositionEnum_Param Page);
      HRESULT (WINAPI *get_EditMode)(Recordset20 *This,EditModeEnum *pl);
      HRESULT (WINAPI *get_Filter)(Recordset20 *This,VARIANT *Criteria);
      HRESULT (WINAPI *put_Filter)(Recordset20 *This,VARIANT Criteria);
      HRESULT (WINAPI *get_PageCount)(Recordset20 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_PageSize)(Recordset20 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_PageSize)(Recordset20 *This,__LONG32 PageSize);
      HRESULT (WINAPI *get_Sort)(Recordset20 *This,BSTR *Criteria);
      HRESULT (WINAPI *put_Sort)(Recordset20 *This,BSTR Criteria);
      HRESULT (WINAPI *get_Status)(Recordset20 *This,__LONG32 *pl);
      HRESULT (WINAPI *get_State)(Recordset20 *This,LONG *plObjState);
      HRESULT (WINAPI *_xClone)(Recordset20 *This,_ADORecordset **ppvObject);
      HRESULT (WINAPI *UpdateBatch)(Recordset20 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *CancelBatch)(Recordset20 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *get_CursorLocation)(Recordset20 *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(Recordset20 *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *NextADORecordset)(Recordset20 *This,VARIANT *RecordsAffected,_ADORecordset **ppiRs);
      HRESULT (WINAPI *Supports)(Recordset20 *This,CursorOptionEnum CursorOptions,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Collect)(Recordset20 *This,VARIANT Index,VARIANT *pvar);
      HRESULT (WINAPI *put_Collect)(Recordset20 *This,VARIANT Index,VARIANT value);
      HRESULT (WINAPI *get_MarshalOptions)(Recordset20 *This,MarshalOptionsEnum *peMarshal);
      HRESULT (WINAPI *put_MarshalOptions)(Recordset20 *This,MarshalOptionsEnum eMarshal);
      HRESULT (WINAPI *Find)(Recordset20 *This,BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start);
      HRESULT (WINAPI *Cancel)(Recordset20 *This);
      HRESULT (WINAPI *get_DataSource)(Recordset20 *This,IUnknown **ppunkDataSource);
      HRESULT (WINAPI *putref_DataSource)(Recordset20 *This,IUnknown *punkDataSource);
      HRESULT (WINAPI *_xSave)(Recordset20 *This,BSTR FileName,PersistFormatEnum PersistFormat);
      HRESULT (WINAPI *get_ActiveCommand)(Recordset20 *This,IDispatch **ppCmd);
      HRESULT (WINAPI *put_StayInSync)(Recordset20 *This,VARIANT_BOOL bStayInSync);
      HRESULT (WINAPI *get_StayInSync)(Recordset20 *This,VARIANT_BOOL *pbStayInSync);
      HRESULT (WINAPI *GetString)(Recordset20 *This,StringFormatEnum StringFormat,__LONG32 NumRows,BSTR ColumnDelimeter,BSTR RowDelimeter,BSTR NullExpr,BSTR *pRetString);
      HRESULT (WINAPI *get_DataMember)(Recordset20 *This,BSTR *pbstrDataMember);
      HRESULT (WINAPI *put_DataMember)(Recordset20 *This,BSTR bstrDataMember);
      HRESULT (WINAPI *CompareBookmarks)(Recordset20 *This,VARIANT Bookmark1,VARIANT Bookmark2,CompareEnum *pCompare);
      HRESULT (WINAPI *Clone)(Recordset20 *This,LockTypeEnum LockType,_ADORecordset **ppvObject);
      HRESULT (WINAPI *Resync)(Recordset20 *This,AffectEnum AffectRecords,ResyncEnum ResyncValues);
    END_INTERFACE
  } Recordset20Vtbl;
  struct Recordset20 {
    CONST_VTBL struct Recordset20Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Recordset20_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset20_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Recordset20_Release(This) (This)->lpVtbl -> Release(This)
#define Recordset20_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset20_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset20_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Recordset20_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset20_get_AbsolutePosition(This,pl) (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset20_put_AbsolutePosition(This,Position) (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset20_putref_ActiveConnection(This,pconn) (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset20_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset20_get_ActiveConnection(This,pvar) (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset20_get_BOF(This,pb) (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset20_get_Bookmark(This,pvBookmark) (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset20_put_Bookmark(This,vBookmark) (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset20_get_CacheSize(This,pl) (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset20_put_CacheSize(This,CacheSize) (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset20_get_CursorType(This,plCursorType) (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset20_put_CursorType(This,lCursorType) (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset20_get_EOF(This,pb) (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset20_get_Fields(This,ppvObject) (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset20_get_LockType(This,plLockType) (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset20_put_LockType(This,lLockType) (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset20_get_MaxRecords(This,plMaxRecords) (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset20_put_MaxRecords(This,lMaxRecords) (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset20_get_RecordCount(This,pl) (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset20_putref_Source(This,pcmd) (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset20_put_Source(This,bstrConn) (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset20_get_Source(This,pvSource) (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset20_AddNew(This,FieldList,Values) (This)->lpVtbl -> AddNew(This,FieldList,Values)
#define Recordset20_CancelUpdate(This) (This)->lpVtbl -> CancelUpdate(This)
#define Recordset20_Close(This) (This)->lpVtbl -> Close(This)
#define Recordset20_Delete(This,AffectRecords) (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset20_GetRows(This,Rows,Start,Fields,pvar) (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset20_Move(This,NumRecords,Start) (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset20_MoveNext(This) (This)->lpVtbl -> MoveNext(This)
#define Recordset20_MovePrevious(This) (This)->lpVtbl -> MovePrevious(This)
#define Recordset20_MoveFirst(This) (This)->lpVtbl -> MoveFirst(This)
#define Recordset20_MoveLast(This) (This)->lpVtbl -> MoveLast(This)
#define Recordset20_Open(This,Source,ActiveConnection,CursorType,LockType,Options) (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset20_Requery(This,Options) (This)->lpVtbl -> Requery(This,Options)
#define Recordset20__xResync(This,AffectRecords) (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset20_Update(This,Fields,Values) (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset20_get_AbsolutePage(This,pl) (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset20_put_AbsolutePage(This,Page) (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset20_get_EditMode(This,pl) (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset20_get_Filter(This,Criteria) (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset20_put_Filter(This,Criteria) (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset20_get_PageCount(This,pl) (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset20_get_PageSize(This,pl) (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset20_put_PageSize(This,PageSize) (This)->lpVtbl -> put_PageSize(This,PageSize)
#define Recordset20_get_Sort(This,Criteria) (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset20_put_Sort(This,Criteria) (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset20_get_Status(This,pl) (This)->lpVtbl -> get_Status(This,pl)
#define Recordset20_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset20__xClone(This,ppvObject) (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset20_UpdateBatch(This,AffectRecords) (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset20_CancelBatch(This,AffectRecords) (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset20_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset20_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset20_NextRecordset(This,RecordsAffected,ppiRs) (This)->lpVtbl -> NextRecordset(This,RecordsAffected,ppiRs)
#define Recordset20_Supports(This,CursorOptions,pb) (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset20_get_Collect(This,Index,pvar) (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset20_put_Collect(This,Index,value) (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset20_get_MarshalOptions(This,peMarshal) (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset20_put_MarshalOptions(This,eMarshal) (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset20_Find(This,Criteria,SkipRecords,SearchDirection,Start) (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define Recordset20_Cancel(This) (This)->lpVtbl -> Cancel(This)
#define Recordset20_get_DataSource(This,ppunkDataSource) (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define Recordset20_putref_DataSource(This,punkDataSource) (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define Recordset20__xSave(This,FileName,PersistFormat) (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define Recordset20_get_ActiveCommand(This,ppCmd) (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define Recordset20_put_StayInSync(This,bStayInSync) (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define Recordset20_get_StayInSync(This,pbStayInSync) (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define Recordset20_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString) (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define Recordset20_get_DataMember(This,pbstrDataMember) (This)->lpVtbl -> get_DataMember(This,pbstrDataMember)
#define Recordset20_put_DataMember(This,bstrDataMember) (This)->lpVtbl -> put_DataMember(This,bstrDataMember)
#define Recordset20_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare) (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define Recordset20_Clone(This,LockType,ppvObject) (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define Recordset20_Resync(This,AffectRecords,ResyncValues) (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#endif
#endif
  HRESULT WINAPI Recordset20_Cancel_Proxy(Recordset20 *This);
  void __RPC_STUB Recordset20_Cancel_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_get_DataSource_Proxy(Recordset20 *This,IUnknown **ppunkDataSource);
  void __RPC_STUB Recordset20_get_DataSource_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_putref_DataSource_Proxy(Recordset20 *This,IUnknown *punkDataSource);
  void __RPC_STUB Recordset20_putref_DataSource_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20__xSave_Proxy(Recordset20 *This,BSTR FileName,PersistFormatEnum PersistFormat);
  void __RPC_STUB Recordset20__xSave_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_get_ActiveCommand_Proxy(Recordset20 *This,IDispatch **ppCmd);
  void __RPC_STUB Recordset20_get_ActiveCommand_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_put_StayInSync_Proxy(Recordset20 *This,VARIANT_BOOL bStayInSync);
  void __RPC_STUB Recordset20_put_StayInSync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_get_StayInSync_Proxy(Recordset20 *This,VARIANT_BOOL *pbStayInSync);
  void __RPC_STUB Recordset20_get_StayInSync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_GetString_Proxy(Recordset20 *This,StringFormatEnum StringFormat,__LONG32 NumRows,BSTR ColumnDelimeter,BSTR RowDelimeter,BSTR NullExpr,BSTR *pRetString);
  void __RPC_STUB Recordset20_GetString_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_get_DataMember_Proxy(Recordset20 *This,BSTR *pbstrDataMember);
  void __RPC_STUB Recordset20_get_DataMember_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_put_DataMember_Proxy(Recordset20 *This,BSTR bstrDataMember);
  void __RPC_STUB Recordset20_put_DataMember_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_CompareBookmarks_Proxy(Recordset20 *This,VARIANT Bookmark1,VARIANT Bookmark2,CompareEnum *pCompare);
  void __RPC_STUB Recordset20_CompareBookmarks_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_Clone_Proxy(Recordset20 *This,LockTypeEnum LockType,_ADORecordset **ppvObject);
  void __RPC_STUB Recordset20_Clone_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset20_Resync_Proxy(Recordset20 *This,AffectEnum AffectRecords,ResyncEnum ResyncValues);
  void __RPC_STUB Recordset20_Resync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Recordset21_INTERFACE_DEFINED__
#define __Recordset21_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Recordset21;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Recordset21 : public Recordset20 {
  public:
    virtual HRESULT WINAPI Seek(VARIANT KeyValues,SeekEnum SeekOption = adSeekFirstEQ) = 0;
    virtual HRESULT WINAPI put_Index(BSTR Index) = 0;
    virtual HRESULT WINAPI get_Index(BSTR *pbstrIndex) = 0;
  };
#else
  typedef struct Recordset21Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Recordset21 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Recordset21 *This);
      ULONG (WINAPI *Release)(Recordset21 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Recordset21 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Recordset21 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Recordset21 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Recordset21 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Recordset21 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_AbsolutePosition)(Recordset21 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePosition)(Recordset21 *This,PositionEnum_Param Position);
      HRESULT (WINAPI *putref_ActiveADOConnection)(Recordset21 *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(Recordset21 *This,VARIANT vConn);
      HRESULT (WINAPI *get_ActiveConnection)(Recordset21 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_BOF)(Recordset21 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Bookmark)(Recordset21 *This,VARIANT *pvBookmark);
      HRESULT (WINAPI *put_Bookmark)(Recordset21 *This,VARIANT vBookmark);
      HRESULT (WINAPI *get_CacheSize)(Recordset21 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_CacheSize)(Recordset21 *This,__LONG32 CacheSize);
      HRESULT (WINAPI *get_CursorType)(Recordset21 *This,CursorTypeEnum *plCursorType);
      HRESULT (WINAPI *put_CursorType)(Recordset21 *This,CursorTypeEnum lCursorType);
      HRESULT (WINAPI *get_EOF)(Recordset21 *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Fields)(Recordset21 *This,ADOFields **ppvObject);
      HRESULT (WINAPI *get_LockType)(Recordset21 *This,LockTypeEnum *plLockType);
      HRESULT (WINAPI *put_LockType)(Recordset21 *This,LockTypeEnum lLockType);
      HRESULT (WINAPI *get_MaxRecords)(Recordset21 *This,ADO_LONGPTR *plMaxRecords);
      HRESULT (WINAPI *put_MaxRecords)(Recordset21 *This,ADO_LONGPTR lMaxRecords);
      HRESULT (WINAPI *get_RecordCount)(Recordset21 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *putref_Source)(Recordset21 *This,IDispatch *pcmd);
      HRESULT (WINAPI *put_Source)(Recordset21 *This,BSTR bstrConn);
      HRESULT (WINAPI *get_Source)(Recordset21 *This,VARIANT *pvSource);
      HRESULT (WINAPI *AddNew)(Recordset21 *This,VARIANT FieldList,VARIANT Values);
      HRESULT (WINAPI *CancelUpdate)(Recordset21 *This);
      HRESULT (WINAPI *Close)(Recordset21 *This);
      HRESULT (WINAPI *Delete)(Recordset21 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *GetRows)(Recordset21 *This,__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar);
      HRESULT (WINAPI *Move)(Recordset21 *This,ADO_LONGPTR NumRecords,VARIANT Start);
      HRESULT (WINAPI *MoveNext)(Recordset21 *This);
      HRESULT (WINAPI *MovePrevious)(Recordset21 *This);
      HRESULT (WINAPI *MoveFirst)(Recordset21 *This);
      HRESULT (WINAPI *MoveLast)(Recordset21 *This);
      HRESULT (WINAPI *Open)(Recordset21 *This,VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType,LockTypeEnum LockType,LONG Options);
      HRESULT (WINAPI *Requery)(Recordset21 *This,LONG Options);
      HRESULT (WINAPI *_xResync)(Recordset21 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *Update)(Recordset21 *This,VARIANT Fields,VARIANT Values);
      HRESULT (WINAPI *get_AbsolutePage)(Recordset21 *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePage)(Recordset21 *This,PositionEnum_Param Page);
      HRESULT (WINAPI *get_EditMode)(Recordset21 *This,EditModeEnum *pl);
      HRESULT (WINAPI *get_Filter)(Recordset21 *This,VARIANT *Criteria);
      HRESULT (WINAPI *put_Filter)(Recordset21 *This,VARIANT Criteria);
      HRESULT (WINAPI *get_PageCount)(Recordset21 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_PageSize)(Recordset21 *This,__LONG32 *pl);
      HRESULT (WINAPI *put_PageSize)(Recordset21 *This,__LONG32 PageSize);
      HRESULT (WINAPI *get_Sort)(Recordset21 *This,BSTR *Criteria);
      HRESULT (WINAPI *put_Sort)(Recordset21 *This,BSTR Criteria);
      HRESULT (WINAPI *get_Status)(Recordset21 *This,__LONG32 *pl);
      HRESULT (WINAPI *get_State)(Recordset21 *This,LONG *plObjState);
      HRESULT (WINAPI *_xClone)(Recordset21 *This,_ADORecordset **ppvObject);
      HRESULT (WINAPI *UpdateBatch)(Recordset21 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *CancelBatch)(Recordset21 *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *get_CursorLocation)(Recordset21 *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(Recordset21 *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *NextADORecordset)(Recordset21 *This,VARIANT *RecordsAffected,_ADORecordset **ppiRs);
      HRESULT (WINAPI *Supports)(Recordset21 *This,CursorOptionEnum CursorOptions,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Collect)(Recordset21 *This,VARIANT Index,VARIANT *pvar);
      HRESULT (WINAPI *put_Collect)(Recordset21 *This,VARIANT Index,VARIANT value);
      HRESULT (WINAPI *get_MarshalOptions)(Recordset21 *This,MarshalOptionsEnum *peMarshal);
      HRESULT (WINAPI *put_MarshalOptions)(Recordset21 *This,MarshalOptionsEnum eMarshal);
      HRESULT (WINAPI *Find)(Recordset21 *This,BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start);
      HRESULT (WINAPI *Cancel)(Recordset21 *This);
      HRESULT (WINAPI *get_DataSource)(Recordset21 *This,IUnknown **ppunkDataSource);
      HRESULT (WINAPI *putref_DataSource)(Recordset21 *This,IUnknown *punkDataSource);
      HRESULT (WINAPI *_xSave)(Recordset21 *This,BSTR FileName,PersistFormatEnum PersistFormat);
      HRESULT (WINAPI *get_ActiveCommand)(Recordset21 *This,IDispatch **ppCmd);
      HRESULT (WINAPI *put_StayInSync)(Recordset21 *This,VARIANT_BOOL bStayInSync);
      HRESULT (WINAPI *get_StayInSync)(Recordset21 *This,VARIANT_BOOL *pbStayInSync);
      HRESULT (WINAPI *GetString)(Recordset21 *This,StringFormatEnum StringFormat,__LONG32 NumRows,BSTR ColumnDelimeter,BSTR RowDelimeter,BSTR NullExpr,BSTR *pRetString);
      HRESULT (WINAPI *get_DataMember)(Recordset21 *This,BSTR *pbstrDataMember);
      HRESULT (WINAPI *put_DataMember)(Recordset21 *This,BSTR bstrDataMember);
      HRESULT (WINAPI *CompareBookmarks)(Recordset21 *This,VARIANT Bookmark1,VARIANT Bookmark2,CompareEnum *pCompare);
      HRESULT (WINAPI *Clone)(Recordset21 *This,LockTypeEnum LockType,_ADORecordset **ppvObject);
      HRESULT (WINAPI *Resync)(Recordset21 *This,AffectEnum AffectRecords,ResyncEnum ResyncValues);
      HRESULT (WINAPI *Seek)(Recordset21 *This,VARIANT KeyValues,SeekEnum SeekOption);
      HRESULT (WINAPI *put_Index)(Recordset21 *This,BSTR Index);
      HRESULT (WINAPI *get_Index)(Recordset21 *This,BSTR *pbstrIndex);
    END_INTERFACE
  } Recordset21Vtbl;
  struct Recordset21 {
    CONST_VTBL struct Recordset21Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Recordset21_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Recordset21_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Recordset21_Release(This) (This)->lpVtbl -> Release(This)
#define Recordset21_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Recordset21_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Recordset21_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Recordset21_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Recordset21_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Recordset21_get_AbsolutePosition(This,pl) (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define Recordset21_put_AbsolutePosition(This,Position) (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define Recordset21_putref_ActiveConnection(This,pconn) (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define Recordset21_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define Recordset21_get_ActiveConnection(This,pvar) (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define Recordset21_get_BOF(This,pb) (This)->lpVtbl -> get_BOF(This,pb)
#define Recordset21_get_Bookmark(This,pvBookmark) (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define Recordset21_put_Bookmark(This,vBookmark) (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define Recordset21_get_CacheSize(This,pl) (This)->lpVtbl -> get_CacheSize(This,pl)
#define Recordset21_put_CacheSize(This,CacheSize) (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define Recordset21_get_CursorType(This,plCursorType) (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define Recordset21_put_CursorType(This,lCursorType) (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define Recordset21_get_EOF(This,pb) (This)->lpVtbl -> get_EOF(This,pb)
#define Recordset21_get_Fields(This,ppvObject) (This)->lpVtbl -> get_Fields(This,ppvObject)
#define Recordset21_get_LockType(This,plLockType) (This)->lpVtbl -> get_LockType(This,plLockType)
#define Recordset21_put_LockType(This,lLockType) (This)->lpVtbl -> put_LockType(This,lLockType)
#define Recordset21_get_MaxRecords(This,plMaxRecords) (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define Recordset21_put_MaxRecords(This,lMaxRecords) (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define Recordset21_get_RecordCount(This,pl) (This)->lpVtbl -> get_RecordCount(This,pl)
#define Recordset21_putref_Source(This,pcmd) (This)->lpVtbl -> putref_Source(This,pcmd)
#define Recordset21_put_Source(This,bstrConn) (This)->lpVtbl -> put_Source(This,bstrConn)
#define Recordset21_get_Source(This,pvSource) (This)->lpVtbl -> get_Source(This,pvSource)
#define Recordset21_AddNew(This,FieldList,Values) (This)->lpVtbl -> AddNew(This,FieldList,Values)
#define Recordset21_CancelUpdate(This) (This)->lpVtbl -> CancelUpdate(This)
#define Recordset21_Close(This) (This)->lpVtbl -> Close(This)
#define Recordset21_Delete(This,AffectRecords) (This)->lpVtbl -> Delete(This,AffectRecords)
#define Recordset21_GetRows(This,Rows,Start,Fields,pvar) (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define Recordset21_Move(This,NumRecords,Start) (This)->lpVtbl -> Move(This,NumRecords,Start)
#define Recordset21_MoveNext(This) (This)->lpVtbl -> MoveNext(This)
#define Recordset21_MovePrevious(This) (This)->lpVtbl -> MovePrevious(This)
#define Recordset21_MoveFirst(This) (This)->lpVtbl -> MoveFirst(This)
#define Recordset21_MoveLast(This) (This)->lpVtbl -> MoveLast(This)
#define Recordset21_Open(This,Source,ActiveConnection,CursorType,LockType,Options) (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define Recordset21_Requery(This,Options) (This)->lpVtbl -> Requery(This,Options)
#define Recordset21__xResync(This,AffectRecords) (This)->lpVtbl -> _xResync(This,AffectRecords)
#define Recordset21_Update(This,Fields,Values) (This)->lpVtbl -> Update(This,Fields,Values)
#define Recordset21_get_AbsolutePage(This,pl) (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define Recordset21_put_AbsolutePage(This,Page) (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define Recordset21_get_EditMode(This,pl) (This)->lpVtbl -> get_EditMode(This,pl)
#define Recordset21_get_Filter(This,Criteria) (This)->lpVtbl -> get_Filter(This,Criteria)
#define Recordset21_put_Filter(This,Criteria) (This)->lpVtbl -> put_Filter(This,Criteria)
#define Recordset21_get_PageCount(This,pl) (This)->lpVtbl -> get_PageCount(This,pl)
#define Recordset21_get_PageSize(This,pl) (This)->lpVtbl -> get_PageSize(This,pl)
#define Recordset21_put_PageSize(This,PageSize) (This)->lpVtbl -> put_PageSize(This,PageSize)
#define Recordset21_get_Sort(This,Criteria) (This)->lpVtbl -> get_Sort(This,Criteria)
#define Recordset21_put_Sort(This,Criteria) (This)->lpVtbl -> put_Sort(This,Criteria)
#define Recordset21_get_Status(This,pl) (This)->lpVtbl -> get_Status(This,pl)
#define Recordset21_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define Recordset21__xClone(This,ppvObject) (This)->lpVtbl -> _xClone(This,ppvObject)
#define Recordset21_UpdateBatch(This,AffectRecords) (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define Recordset21_CancelBatch(This,AffectRecords) (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define Recordset21_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define Recordset21_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define Recordset21_NextRecordset(This,RecordsAffected,ppiRs) (This)->lpVtbl -> NextRecordset(This,RecordsAffected,ppiRs)
#define Recordset21_Supports(This,CursorOptions,pb) (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define Recordset21_get_Collect(This,Index,pvar) (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define Recordset21_put_Collect(This,Index,value) (This)->lpVtbl -> put_Collect(This,Index,value)
#define Recordset21_get_MarshalOptions(This,peMarshal) (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define Recordset21_put_MarshalOptions(This,eMarshal) (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define Recordset21_Find(This,Criteria,SkipRecords,SearchDirection,Start) (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define Recordset21_Cancel(This) (This)->lpVtbl -> Cancel(This)
#define Recordset21_get_DataSource(This,ppunkDataSource) (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define Recordset21_putref_DataSource(This,punkDataSource) (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define Recordset21__xSave(This,FileName,PersistFormat) (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define Recordset21_get_ActiveCommand(This,ppCmd) (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define Recordset21_put_StayInSync(This,bStayInSync) (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define Recordset21_get_StayInSync(This,pbStayInSync) (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define Recordset21_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString) (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define Recordset21_get_DataMember(This,pbstrDataMember) (This)->lpVtbl -> get_DataMember(This,pbstrDataMember)
#define Recordset21_put_DataMember(This,bstrDataMember) (This)->lpVtbl -> put_DataMember(This,bstrDataMember)
#define Recordset21_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare) (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define Recordset21_Clone(This,LockType,ppvObject) (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define Recordset21_Resync(This,AffectRecords,ResyncValues) (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#define Recordset21_Seek(This,KeyValues,SeekOption) (This)->lpVtbl -> Seek(This,KeyValues,SeekOption)
#define Recordset21_put_Index(This,Index) (This)->lpVtbl -> put_Index(This,Index)
#define Recordset21_get_Index(This,pbstrIndex) (This)->lpVtbl -> get_Index(This,pbstrIndex)
#endif
#endif
  HRESULT WINAPI Recordset21_Seek_Proxy(Recordset21 *This,VARIANT KeyValues,SeekEnum SeekOption);
  void __RPC_STUB Recordset21_Seek_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset21_put_Index_Proxy(Recordset21 *This,BSTR Index);
  void __RPC_STUB Recordset21_put_Index_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Recordset21_get_Index_Proxy(Recordset21 *This,BSTR *pbstrIndex);
  void __RPC_STUB Recordset21_get_Index_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Recordset_INTERFACE_DEFINED__
#define ___Recordset_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Recordset;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADORecordset : public Recordset21 {
  public:
    virtual HRESULT WINAPI Save(VARIANT Destination,PersistFormatEnum PersistFormat = adPersistADTG) = 0;
  };
#else
  typedef struct _RecordsetVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADORecordset *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADORecordset *This);
      ULONG (WINAPI *Release)(_ADORecordset *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADORecordset *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADORecordset *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADORecordset *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADORecordset *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADORecordset *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_AbsolutePosition)(_ADORecordset *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePosition)(_ADORecordset *This,PositionEnum_Param Position);
      HRESULT (WINAPI *putref_ActiveADOConnection)(_ADORecordset *This,IDispatch *pconn);
      HRESULT (WINAPI *put_ActiveConnection)(_ADORecordset *This,VARIANT vConn);
      HRESULT (WINAPI *get_ActiveConnection)(_ADORecordset *This,VARIANT *pvar);
      HRESULT (WINAPI *get_BOF)(_ADORecordset *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Bookmark)(_ADORecordset *This,VARIANT *pvBookmark);
      HRESULT (WINAPI *put_Bookmark)(_ADORecordset *This,VARIANT vBookmark);
      HRESULT (WINAPI *get_CacheSize)(_ADORecordset *This,__LONG32 *pl);
      HRESULT (WINAPI *put_CacheSize)(_ADORecordset *This,__LONG32 CacheSize);
      HRESULT (WINAPI *get_CursorType)(_ADORecordset *This,CursorTypeEnum *plCursorType);
      HRESULT (WINAPI *put_CursorType)(_ADORecordset *This,CursorTypeEnum lCursorType);
      HRESULT (WINAPI *get_EOF)(_ADORecordset *This,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Fields)(_ADORecordset *This,ADOFields **ppvObject);
      HRESULT (WINAPI *get_LockType)(_ADORecordset *This,LockTypeEnum *plLockType);
      HRESULT (WINAPI *put_LockType)(_ADORecordset *This,LockTypeEnum lLockType);
      HRESULT (WINAPI *get_MaxRecords)(_ADORecordset *This,ADO_LONGPTR *plMaxRecords);
      HRESULT (WINAPI *put_MaxRecords)(_ADORecordset *This,ADO_LONGPTR lMaxRecords);
      HRESULT (WINAPI *get_RecordCount)(_ADORecordset *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *putref_Source)(_ADORecordset *This,IDispatch *pcmd);
      HRESULT (WINAPI *put_Source)(_ADORecordset *This,BSTR bstrConn);
      HRESULT (WINAPI *get_Source)(_ADORecordset *This,VARIANT *pvSource);
      HRESULT (WINAPI *AddNew)(_ADORecordset *This,VARIANT FieldList,VARIANT Values);
      HRESULT (WINAPI *CancelUpdate)(_ADORecordset *This);
      HRESULT (WINAPI *Close)(_ADORecordset *This);
      HRESULT (WINAPI *Delete)(_ADORecordset *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *GetRows)(_ADORecordset *This,__LONG32 Rows,VARIANT Start,VARIANT Fields,VARIANT *pvar);
      HRESULT (WINAPI *Move)(_ADORecordset *This,ADO_LONGPTR NumRecords,VARIANT Start);
      HRESULT (WINAPI *MoveNext)(_ADORecordset *This);
      HRESULT (WINAPI *MovePrevious)(_ADORecordset *This);
      HRESULT (WINAPI *MoveFirst)(_ADORecordset *This);
      HRESULT (WINAPI *MoveLast)(_ADORecordset *This);
      HRESULT (WINAPI *Open)(_ADORecordset *This,VARIANT Source,VARIANT ActiveConnection,CursorTypeEnum CursorType,LockTypeEnum LockType,LONG Options);
      HRESULT (WINAPI *Requery)(_ADORecordset *This,LONG Options);
      HRESULT (WINAPI *_xResync)(_ADORecordset *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *Update)(_ADORecordset *This,VARIANT Fields,VARIANT Values);
      HRESULT (WINAPI *get_AbsolutePage)(_ADORecordset *This,PositionEnum_Param *pl);
      HRESULT (WINAPI *put_AbsolutePage)(_ADORecordset *This,PositionEnum_Param Page);
      HRESULT (WINAPI *get_EditMode)(_ADORecordset *This,EditModeEnum *pl);
      HRESULT (WINAPI *get_Filter)(_ADORecordset *This,VARIANT *Criteria);
      HRESULT (WINAPI *put_Filter)(_ADORecordset *This,VARIANT Criteria);
      HRESULT (WINAPI *get_PageCount)(_ADORecordset *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_PageSize)(_ADORecordset *This,__LONG32 *pl);
      HRESULT (WINAPI *put_PageSize)(_ADORecordset *This,__LONG32 PageSize);
      HRESULT (WINAPI *get_Sort)(_ADORecordset *This,BSTR *Criteria);
      HRESULT (WINAPI *put_Sort)(_ADORecordset *This,BSTR Criteria);
      HRESULT (WINAPI *get_Status)(_ADORecordset *This,__LONG32 *pl);
      HRESULT (WINAPI *get_State)(_ADORecordset *This,LONG *plObjState);
      HRESULT (WINAPI *_xClone)(_ADORecordset *This,_ADORecordset **ppvObject);
      HRESULT (WINAPI *UpdateBatch)(_ADORecordset *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *CancelBatch)(_ADORecordset *This,AffectEnum AffectRecords);
      HRESULT (WINAPI *get_CursorLocation)(_ADORecordset *This,CursorLocationEnum *plCursorLoc);
      HRESULT (WINAPI *put_CursorLocation)(_ADORecordset *This,CursorLocationEnum lCursorLoc);
      HRESULT (WINAPI *NextADORecordset)(_ADORecordset *This,VARIANT *RecordsAffected,_ADORecordset **ppiRs);
      HRESULT (WINAPI *Supports)(_ADORecordset *This,CursorOptionEnum CursorOptions,VARIANT_BOOL *pb);
      HRESULT (WINAPI *get_Collect)(_ADORecordset *This,VARIANT Index,VARIANT *pvar);
      HRESULT (WINAPI *put_Collect)(_ADORecordset *This,VARIANT Index,VARIANT value);
      HRESULT (WINAPI *get_MarshalOptions)(_ADORecordset *This,MarshalOptionsEnum *peMarshal);
      HRESULT (WINAPI *put_MarshalOptions)(_ADORecordset *This,MarshalOptionsEnum eMarshal);
      HRESULT (WINAPI *Find)(_ADORecordset *This,BSTR Criteria,ADO_LONGPTR SkipRecords,SearchDirectionEnum SearchDirection,VARIANT Start);
      HRESULT (WINAPI *Cancel)(_ADORecordset *This);
      HRESULT (WINAPI *get_DataSource)(_ADORecordset *This,IUnknown **ppunkDataSource);
      HRESULT (WINAPI *putref_DataSource)(_ADORecordset *This,IUnknown *punkDataSource);
      HRESULT (WINAPI *_xSave)(_ADORecordset *This,BSTR FileName,PersistFormatEnum PersistFormat);
      HRESULT (WINAPI *get_ActiveCommand)(_ADORecordset *This,IDispatch **ppCmd);
      HRESULT (WINAPI *put_StayInSync)(_ADORecordset *This,VARIANT_BOOL bStayInSync);
      HRESULT (WINAPI *get_StayInSync)(_ADORecordset *This,VARIANT_BOOL *pbStayInSync);
      HRESULT (WINAPI *GetString)(_ADORecordset *This,StringFormatEnum StringFormat,__LONG32 NumRows,BSTR ColumnDelimeter,BSTR RowDelimeter,BSTR NullExpr,BSTR *pRetString);
      HRESULT (WINAPI *get_DataMember)(_ADORecordset *This,BSTR *pbstrDataMember);
      HRESULT (WINAPI *put_DataMember)(_ADORecordset *This,BSTR bstrDataMember);
      HRESULT (WINAPI *CompareBookmarks)(_ADORecordset *This,VARIANT Bookmark1,VARIANT Bookmark2,CompareEnum *pCompare);
      HRESULT (WINAPI *Clone)(_ADORecordset *This,LockTypeEnum LockType,_ADORecordset **ppvObject);
      HRESULT (WINAPI *Resync)(_ADORecordset *This,AffectEnum AffectRecords,ResyncEnum ResyncValues);
      HRESULT (WINAPI *Seek)(_ADORecordset *This,VARIANT KeyValues,SeekEnum SeekOption);
      HRESULT (WINAPI *put_Index)(_ADORecordset *This,BSTR Index);
      HRESULT (WINAPI *get_Index)(_ADORecordset *This,BSTR *pbstrIndex);
      HRESULT (WINAPI *Save)(_ADORecordset *This,VARIANT Destination,PersistFormatEnum PersistFormat);
    END_INTERFACE
  } _RecordsetVtbl;
  struct _Recordset {
    CONST_VTBL struct _RecordsetVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Recordset_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Recordset_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Recordset_Release(This) (This)->lpVtbl -> Release(This)
#define _Recordset_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Recordset_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Recordset_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Recordset_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Recordset_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Recordset_get_AbsolutePosition(This,pl) (This)->lpVtbl -> get_AbsolutePosition(This,pl)
#define _Recordset_put_AbsolutePosition(This,Position) (This)->lpVtbl -> put_AbsolutePosition(This,Position)
#define _Recordset_putref_ActiveConnection(This,pconn) (This)->lpVtbl -> putref_ActiveConnection(This,pconn)
#define _Recordset_put_ActiveConnection(This,vConn) (This)->lpVtbl -> put_ActiveConnection(This,vConn)
#define _Recordset_get_ActiveConnection(This,pvar) (This)->lpVtbl -> get_ActiveConnection(This,pvar)
#define _Recordset_get_BOF(This,pb) (This)->lpVtbl -> get_BOF(This,pb)
#define _Recordset_get_Bookmark(This,pvBookmark) (This)->lpVtbl -> get_Bookmark(This,pvBookmark)
#define _Recordset_put_Bookmark(This,vBookmark) (This)->lpVtbl -> put_Bookmark(This,vBookmark)
#define _Recordset_get_CacheSize(This,pl) (This)->lpVtbl -> get_CacheSize(This,pl)
#define _Recordset_put_CacheSize(This,CacheSize) (This)->lpVtbl -> put_CacheSize(This,CacheSize)
#define _Recordset_get_CursorType(This,plCursorType) (This)->lpVtbl -> get_CursorType(This,plCursorType)
#define _Recordset_put_CursorType(This,lCursorType) (This)->lpVtbl -> put_CursorType(This,lCursorType)
#define _Recordset_get_EOF(This,pb) (This)->lpVtbl -> get_EOF(This,pb)
#define _Recordset_get_Fields(This,ppvObject) (This)->lpVtbl -> get_Fields(This,ppvObject)
#define _Recordset_get_LockType(This,plLockType) (This)->lpVtbl -> get_LockType(This,plLockType)
#define _Recordset_put_LockType(This,lLockType) (This)->lpVtbl -> put_LockType(This,lLockType)
#define _Recordset_get_MaxRecords(This,plMaxRecords) (This)->lpVtbl -> get_MaxRecords(This,plMaxRecords)
#define _Recordset_put_MaxRecords(This,lMaxRecords) (This)->lpVtbl -> put_MaxRecords(This,lMaxRecords)
#define _Recordset_get_RecordCount(This,pl) (This)->lpVtbl -> get_RecordCount(This,pl)
#define _Recordset_putref_Source(This,pcmd) (This)->lpVtbl -> putref_Source(This,pcmd)
#define _Recordset_put_Source(This,bstrConn) (This)->lpVtbl -> put_Source(This,bstrConn)
#define _Recordset_get_Source(This,pvSource) (This)->lpVtbl -> get_Source(This,pvSource)
#define _Recordset_AddNew(This,FieldList,Values) (This)->lpVtbl -> AddNew(This,FieldList,Values)
#define _Recordset_CancelUpdate(This) (This)->lpVtbl -> CancelUpdate(This)
#define _Recordset_Close(This) (This)->lpVtbl -> Close(This)
#define _Recordset_Delete(This,AffectRecords) (This)->lpVtbl -> Delete(This,AffectRecords)
#define _Recordset_GetRows(This,Rows,Start,Fields,pvar) (This)->lpVtbl -> GetRows(This,Rows,Start,Fields,pvar)
#define _Recordset_Move(This,NumRecords,Start) (This)->lpVtbl -> Move(This,NumRecords,Start)
#define _Recordset_MoveNext(This) (This)->lpVtbl -> MoveNext(This)
#define _Recordset_MovePrevious(This) (This)->lpVtbl -> MovePrevious(This)
#define _Recordset_MoveFirst(This) (This)->lpVtbl -> MoveFirst(This)
#define _Recordset_MoveLast(This) (This)->lpVtbl -> MoveLast(This)
#define _Recordset_Open(This,Source,ActiveConnection,CursorType,LockType,Options) (This)->lpVtbl -> Open(This,Source,ActiveConnection,CursorType,LockType,Options)
#define _Recordset_Requery(This,Options) (This)->lpVtbl -> Requery(This,Options)
#define _Recordset__xResync(This,AffectRecords) (This)->lpVtbl -> _xResync(This,AffectRecords)
#define _Recordset_Update(This,Fields,Values) (This)->lpVtbl -> Update(This,Fields,Values)
#define _Recordset_get_AbsolutePage(This,pl) (This)->lpVtbl -> get_AbsolutePage(This,pl)
#define _Recordset_put_AbsolutePage(This,Page) (This)->lpVtbl -> put_AbsolutePage(This,Page)
#define _Recordset_get_EditMode(This,pl) (This)->lpVtbl -> get_EditMode(This,pl)
#define _Recordset_get_Filter(This,Criteria) (This)->lpVtbl -> get_Filter(This,Criteria)
#define _Recordset_put_Filter(This,Criteria) (This)->lpVtbl -> put_Filter(This,Criteria)
#define _Recordset_get_PageCount(This,pl) (This)->lpVtbl -> get_PageCount(This,pl)
#define _Recordset_get_PageSize(This,pl) (This)->lpVtbl -> get_PageSize(This,pl)
#define _Recordset_put_PageSize(This,PageSize) (This)->lpVtbl -> put_PageSize(This,PageSize)
#define _Recordset_get_Sort(This,Criteria) (This)->lpVtbl -> get_Sort(This,Criteria)
#define _Recordset_put_Sort(This,Criteria) (This)->lpVtbl -> put_Sort(This,Criteria)
#define _Recordset_get_Status(This,pl) (This)->lpVtbl -> get_Status(This,pl)
#define _Recordset_get_State(This,plObjState) (This)->lpVtbl -> get_State(This,plObjState)
#define _Recordset__xClone(This,ppvObject) (This)->lpVtbl -> _xClone(This,ppvObject)
#define _Recordset_UpdateBatch(This,AffectRecords) (This)->lpVtbl -> UpdateBatch(This,AffectRecords)
#define _Recordset_CancelBatch(This,AffectRecords) (This)->lpVtbl -> CancelBatch(This,AffectRecords)
#define _Recordset_get_CursorLocation(This,plCursorLoc) (This)->lpVtbl -> get_CursorLocation(This,plCursorLoc)
#define _Recordset_put_CursorLocation(This,lCursorLoc) (This)->lpVtbl -> put_CursorLocation(This,lCursorLoc)
#define _Recordset_NextRecordset(This,RecordsAffected,ppiRs) (This)->lpVtbl -> NextRecordset(This,RecordsAffected,ppiRs)
#define _Recordset_Supports(This,CursorOptions,pb) (This)->lpVtbl -> Supports(This,CursorOptions,pb)
#define _Recordset_get_Collect(This,Index,pvar) (This)->lpVtbl -> get_Collect(This,Index,pvar)
#define _Recordset_put_Collect(This,Index,value) (This)->lpVtbl -> put_Collect(This,Index,value)
#define _Recordset_get_MarshalOptions(This,peMarshal) (This)->lpVtbl -> get_MarshalOptions(This,peMarshal)
#define _Recordset_put_MarshalOptions(This,eMarshal) (This)->lpVtbl -> put_MarshalOptions(This,eMarshal)
#define _Recordset_Find(This,Criteria,SkipRecords,SearchDirection,Start) (This)->lpVtbl -> Find(This,Criteria,SkipRecords,SearchDirection,Start)
#define _Recordset_Cancel(This) (This)->lpVtbl -> Cancel(This)
#define _Recordset_get_DataSource(This,ppunkDataSource) (This)->lpVtbl -> get_DataSource(This,ppunkDataSource)
#define _Recordset_putref_DataSource(This,punkDataSource) (This)->lpVtbl -> putref_DataSource(This,punkDataSource)
#define _Recordset__xSave(This,FileName,PersistFormat) (This)->lpVtbl -> _xSave(This,FileName,PersistFormat)
#define _Recordset_get_ActiveCommand(This,ppCmd) (This)->lpVtbl -> get_ActiveCommand(This,ppCmd)
#define _Recordset_put_StayInSync(This,bStayInSync) (This)->lpVtbl -> put_StayInSync(This,bStayInSync)
#define _Recordset_get_StayInSync(This,pbStayInSync) (This)->lpVtbl -> get_StayInSync(This,pbStayInSync)
#define _Recordset_GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString) (This)->lpVtbl -> GetString(This,StringFormat,NumRows,ColumnDelimeter,RowDelimeter,NullExpr,pRetString)
#define _Recordset_get_DataMember(This,pbstrDataMember) (This)->lpVtbl -> get_DataMember(This,pbstrDataMember)
#define _Recordset_put_DataMember(This,bstrDataMember) (This)->lpVtbl -> put_DataMember(This,bstrDataMember)
#define _Recordset_CompareBookmarks(This,Bookmark1,Bookmark2,pCompare) (This)->lpVtbl -> CompareBookmarks(This,Bookmark1,Bookmark2,pCompare)
#define _Recordset_Clone(This,LockType,ppvObject) (This)->lpVtbl -> Clone(This,LockType,ppvObject)
#define _Recordset_Resync(This,AffectRecords,ResyncValues) (This)->lpVtbl -> Resync(This,AffectRecords,ResyncValues)
#define _Recordset_Seek(This,KeyValues,SeekOption) (This)->lpVtbl -> Seek(This,KeyValues,SeekOption)
#define _Recordset_put_Index(This,Index) (This)->lpVtbl -> put_Index(This,Index)
#define _Recordset_get_Index(This,pbstrIndex) (This)->lpVtbl -> get_Index(This,pbstrIndex)
#define _Recordset_Save(This,Destination,PersistFormat) (This)->lpVtbl -> Save(This,Destination,PersistFormat)
#endif
#endif
  HRESULT WINAPI _Recordset_Save_Proxy(_ADORecordset *This,VARIANT Destination,PersistFormatEnum PersistFormat);
  void __RPC_STUB _Recordset_Save_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __ADORecordsetConstruction_INTERFACE_DEFINED__
#define __ADORecordsetConstruction_INTERFACE_DEFINED__
  EXTERN_C const IID IID_ADORecordsetConstruction;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADORecordsetConstruction : public IDispatch {
  public:
    virtual HRESULT WINAPI get_Rowset(IUnknown **ppRowset) = 0;
    virtual HRESULT WINAPI put_Rowset(IUnknown *pRowset) = 0;
    virtual HRESULT WINAPI get_Chapter(ADO_LONGPTR *plChapter) = 0;
    virtual HRESULT WINAPI put_Chapter(ADO_LONGPTR lChapter) = 0;
    virtual HRESULT WINAPI get_RowPosition(IUnknown **ppRowPos) = 0;
    virtual HRESULT WINAPI put_RowPosition(IUnknown *pRowPos) = 0;
  };
#else
  typedef struct ADORecordsetConstructionVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADORecordsetConstruction *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADORecordsetConstruction *This);
      ULONG (WINAPI *Release)(ADORecordsetConstruction *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADORecordsetConstruction *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADORecordsetConstruction *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADORecordsetConstruction *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADORecordsetConstruction *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Rowset)(ADORecordsetConstruction *This,IUnknown **ppRowset);
      HRESULT (WINAPI *put_Rowset)(ADORecordsetConstruction *This,IUnknown *pRowset);
      HRESULT (WINAPI *get_Chapter)(ADORecordsetConstruction *This,ADO_LONGPTR *plChapter);
      HRESULT (WINAPI *put_Chapter)(ADORecordsetConstruction *This,ADO_LONGPTR lChapter);
      HRESULT (WINAPI *get_RowPosition)(ADORecordsetConstruction *This,IUnknown **ppRowPos);
      HRESULT (WINAPI *put_RowPosition)(ADORecordsetConstruction *This,IUnknown *pRowPos);
    END_INTERFACE
  } ADORecordsetConstructionVtbl;
  struct ADORecordsetConstruction {
    CONST_VTBL struct ADORecordsetConstructionVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define ADORecordsetConstruction_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define ADORecordsetConstruction_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define ADORecordsetConstruction_Release(This) (This)->lpVtbl -> Release(This)
#define ADORecordsetConstruction_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define ADORecordsetConstruction_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define ADORecordsetConstruction_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define ADORecordsetConstruction_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define ADORecordsetConstruction_get_Rowset(This,ppRowset) (This)->lpVtbl -> get_Rowset(This,ppRowset)
#define ADORecordsetConstruction_put_Rowset(This,pRowset) (This)->lpVtbl -> put_Rowset(This,pRowset)
#define ADORecordsetConstruction_get_Chapter(This,plChapter) (This)->lpVtbl -> get_Chapter(This,plChapter)
#define ADORecordsetConstruction_put_Chapter(This,lChapter) (This)->lpVtbl -> put_Chapter(This,lChapter)
#define ADORecordsetConstruction_get_RowPosition(This,ppRowPos) (This)->lpVtbl -> get_RowPosition(This,ppRowPos)
#define ADORecordsetConstruction_put_RowPosition(This,pRowPos) (This)->lpVtbl -> put_RowPosition(This,pRowPos)
#endif
#endif
  HRESULT WINAPI ADORecordsetConstruction_get_Rowset_Proxy(ADORecordsetConstruction *This,IUnknown **ppRowset);
  void __RPC_STUB ADORecordsetConstruction_get_Rowset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordsetConstruction_put_Rowset_Proxy(ADORecordsetConstruction *This,IUnknown *pRowset);
  void __RPC_STUB ADORecordsetConstruction_put_Rowset_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordsetConstruction_get_Chapter_Proxy(ADORecordsetConstruction *This,ADO_LONGPTR *plChapter);
  void __RPC_STUB ADORecordsetConstruction_get_Chapter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordsetConstruction_put_Chapter_Proxy(ADORecordsetConstruction *This,ADO_LONGPTR lChapter);
  void __RPC_STUB ADORecordsetConstruction_put_Chapter_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordsetConstruction_get_RowPosition_Proxy(ADORecordsetConstruction *This,IUnknown **ppRowPos);
  void __RPC_STUB ADORecordsetConstruction_get_RowPosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI ADORecordsetConstruction_put_RowPosition_Proxy(ADORecordsetConstruction *This,IUnknown *pRowPos);
  void __RPC_STUB ADORecordsetConstruction_put_RowPosition_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Field15_INTERFACE_DEFINED__
#define __Field15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Field15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Field15 : public _ADO {
  public:
    virtual HRESULT WINAPI get_ActualSize(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI get_Attributes(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI get_DefinedSize(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Type(DataTypeEnum *pDataType) = 0;
    virtual HRESULT WINAPI get_Value(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Value(VARIANT Val) = 0;
    virtual HRESULT WINAPI get_Precision(BYTE *pbPrecision) = 0;
    virtual HRESULT WINAPI get_NumericScale(BYTE *pbNumericScale) = 0;
    virtual HRESULT WINAPI AppendChunk(VARIANT Data) = 0;
    virtual HRESULT WINAPI GetChunk(__LONG32 Length,VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_OriginalValue(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_UnderlyingValue(VARIANT *pvar) = 0;
  };
#else
  typedef struct Field15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Field15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Field15 *This);
      ULONG (WINAPI *Release)(Field15 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Field15 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Field15 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Field15 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Field15 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Field15 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActualSize)(Field15 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Attributes)(Field15 *This,__LONG32 *pl);
      HRESULT (WINAPI *get_DefinedSize)(Field15 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Name)(Field15 *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Type)(Field15 *This,DataTypeEnum *pDataType);
      HRESULT (WINAPI *get_Value)(Field15 *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Value)(Field15 *This,VARIANT Val);
      HRESULT (WINAPI *get_Precision)(Field15 *This,BYTE *pbPrecision);
      HRESULT (WINAPI *get_NumericScale)(Field15 *This,BYTE *pbNumericScale);
      HRESULT (WINAPI *AppendChunk)(Field15 *This,VARIANT Data);
      HRESULT (WINAPI *GetChunk)(Field15 *This,__LONG32 Length,VARIANT *pvar);
      HRESULT (WINAPI *get_OriginalValue)(Field15 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_UnderlyingValue)(Field15 *This,VARIANT *pvar);
    END_INTERFACE
  } Field15Vtbl;
  struct Field15 {
    CONST_VTBL struct Field15Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Field15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Field15_Release(This) (This)->lpVtbl -> Release(This)
#define Field15_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field15_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field15_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Field15_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field15_get_ActualSize(This,pl) (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field15_get_Attributes(This,pl) (This)->lpVtbl -> get_Attributes(This,pl)
#define Field15_get_DefinedSize(This,pl) (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field15_get_Name(This,pbstr) (This)->lpVtbl -> get_Name(This,pbstr)
#define Field15_get_Type(This,pDataType) (This)->lpVtbl -> get_Type(This,pDataType)
#define Field15_get_Value(This,pvar) (This)->lpVtbl -> get_Value(This,pvar)
#define Field15_put_Value(This,Val) (This)->lpVtbl -> put_Value(This,Val)
#define Field15_get_Precision(This,pbPrecision) (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field15_get_NumericScale(This,pbNumericScale) (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field15_AppendChunk(This,Data) (This)->lpVtbl -> AppendChunk(This,Data)
#define Field15_GetChunk(This,Length,pvar) (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field15_get_OriginalValue(This,pvar) (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field15_get_UnderlyingValue(This,pvar) (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#endif
#endif
  HRESULT WINAPI Field15_get_ActualSize_Proxy(Field15 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Field15_get_ActualSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_Attributes_Proxy(Field15 *This,__LONG32 *pl);
  void __RPC_STUB Field15_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_DefinedSize_Proxy(Field15 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Field15_get_DefinedSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_Name_Proxy(Field15 *This,BSTR *pbstr);
  void __RPC_STUB Field15_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_Type_Proxy(Field15 *This,DataTypeEnum *pDataType);
  void __RPC_STUB Field15_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_Value_Proxy(Field15 *This,VARIANT *pvar);
  void __RPC_STUB Field15_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_put_Value_Proxy(Field15 *This,VARIANT Val);
  void __RPC_STUB Field15_put_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_Precision_Proxy(Field15 *This,BYTE *pbPrecision);
  void __RPC_STUB Field15_get_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_NumericScale_Proxy(Field15 *This,BYTE *pbNumericScale);
  void __RPC_STUB Field15_get_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_AppendChunk_Proxy(Field15 *This,VARIANT Data);
  void __RPC_STUB Field15_AppendChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_GetChunk_Proxy(Field15 *This,__LONG32 Length,VARIANT *pvar);
  void __RPC_STUB Field15_GetChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_OriginalValue_Proxy(Field15 *This,VARIANT *pvar);
  void __RPC_STUB Field15_get_OriginalValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field15_get_UnderlyingValue_Proxy(Field15 *This,VARIANT *pvar);
  void __RPC_STUB Field15_get_UnderlyingValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Field20_INTERFACE_DEFINED__
#define __Field20_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Field20;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Field20 : public _ADO {
  public:
    virtual HRESULT WINAPI get_ActualSize(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI get_Attributes(__LONG32 *pl) = 0;
    virtual HRESULT WINAPI get_DefinedSize(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI get_Type(DataTypeEnum *pDataType) = 0;
    virtual HRESULT WINAPI get_Value(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Value(VARIANT Val) = 0;
    virtual HRESULT WINAPI get_Precision(BYTE *pbPrecision) = 0;
    virtual HRESULT WINAPI get_NumericScale(BYTE *pbNumericScale) = 0;
    virtual HRESULT WINAPI AppendChunk(VARIANT Data) = 0;
    virtual HRESULT WINAPI GetChunk(__LONG32 Length,VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_OriginalValue(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_UnderlyingValue(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI get_DataFormat(IUnknown **ppiDF) = 0;
    virtual HRESULT WINAPI putref_DataFormat(IUnknown *piDF) = 0;
    virtual HRESULT WINAPI put_Precision(BYTE bPrecision) = 0;
    virtual HRESULT WINAPI put_NumericScale(BYTE bScale) = 0;
    virtual HRESULT WINAPI put_Type(DataTypeEnum DataType) = 0;
    virtual HRESULT WINAPI put_DefinedSize(ADO_LONGPTR lSize) = 0;
    virtual HRESULT WINAPI put_Attributes(__LONG32 lAttributes) = 0;
  };
#else
  typedef struct Field20Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Field20 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Field20 *This);
      ULONG (WINAPI *Release)(Field20 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Field20 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Field20 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Field20 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Field20 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(Field20 *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActualSize)(Field20 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Attributes)(Field20 *This,__LONG32 *pl);
      HRESULT (WINAPI *get_DefinedSize)(Field20 *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Name)(Field20 *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Type)(Field20 *This,DataTypeEnum *pDataType);
      HRESULT (WINAPI *get_Value)(Field20 *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Value)(Field20 *This,VARIANT Val);
      HRESULT (WINAPI *get_Precision)(Field20 *This,BYTE *pbPrecision);
      HRESULT (WINAPI *get_NumericScale)(Field20 *This,BYTE *pbNumericScale);
      HRESULT (WINAPI *AppendChunk)(Field20 *This,VARIANT Data);
      HRESULT (WINAPI *GetChunk)(Field20 *This,__LONG32 Length,VARIANT *pvar);
      HRESULT (WINAPI *get_OriginalValue)(Field20 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_UnderlyingValue)(Field20 *This,VARIANT *pvar);
      HRESULT (WINAPI *get_DataFormat)(Field20 *This,IUnknown **ppiDF);
      HRESULT (WINAPI *putref_DataFormat)(Field20 *This,IUnknown *piDF);
      HRESULT (WINAPI *put_Precision)(Field20 *This,BYTE bPrecision);
      HRESULT (WINAPI *put_NumericScale)(Field20 *This,BYTE bScale);
      HRESULT (WINAPI *put_Type)(Field20 *This,DataTypeEnum DataType);
      HRESULT (WINAPI *put_DefinedSize)(Field20 *This,ADO_LONGPTR lSize);
      HRESULT (WINAPI *put_Attributes)(Field20 *This,__LONG32 lAttributes);
    END_INTERFACE
  } Field20Vtbl;
  struct Field20 {
    CONST_VTBL struct Field20Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Field20_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field20_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Field20_Release(This) (This)->lpVtbl -> Release(This)
#define Field20_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field20_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field20_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Field20_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field20_get_ActualSize(This,pl) (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field20_get_Attributes(This,pl) (This)->lpVtbl -> get_Attributes(This,pl)
#define Field20_get_DefinedSize(This,pl) (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field20_get_Name(This,pbstr) (This)->lpVtbl -> get_Name(This,pbstr)
#define Field20_get_Type(This,pDataType) (This)->lpVtbl -> get_Type(This,pDataType)
#define Field20_get_Value(This,pvar) (This)->lpVtbl -> get_Value(This,pvar)
#define Field20_put_Value(This,Val) (This)->lpVtbl -> put_Value(This,Val)
#define Field20_get_Precision(This,pbPrecision) (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field20_get_NumericScale(This,pbNumericScale) (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field20_AppendChunk(This,Data) (This)->lpVtbl -> AppendChunk(This,Data)
#define Field20_GetChunk(This,Length,pvar) (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field20_get_OriginalValue(This,pvar) (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field20_get_UnderlyingValue(This,pvar) (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#define Field20_get_DataFormat(This,ppiDF) (This)->lpVtbl -> get_DataFormat(This,ppiDF)
#define Field20_putref_DataFormat(This,piDF) (This)->lpVtbl -> putref_DataFormat(This,piDF)
#define Field20_put_Precision(This,bPrecision) (This)->lpVtbl -> put_Precision(This,bPrecision)
#define Field20_put_NumericScale(This,bScale) (This)->lpVtbl -> put_NumericScale(This,bScale)
#define Field20_put_Type(This,DataType) (This)->lpVtbl -> put_Type(This,DataType)
#define Field20_put_DefinedSize(This,lSize) (This)->lpVtbl -> put_DefinedSize(This,lSize)
#define Field20_put_Attributes(This,lAttributes) (This)->lpVtbl -> put_Attributes(This,lAttributes)
#endif
#endif
  HRESULT WINAPI Field20_get_ActualSize_Proxy(Field20 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Field20_get_ActualSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_Attributes_Proxy(Field20 *This,__LONG32 *pl);
  void __RPC_STUB Field20_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_DefinedSize_Proxy(Field20 *This,ADO_LONGPTR *pl);
  void __RPC_STUB Field20_get_DefinedSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_Name_Proxy(Field20 *This,BSTR *pbstr);
  void __RPC_STUB Field20_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_Type_Proxy(Field20 *This,DataTypeEnum *pDataType);
  void __RPC_STUB Field20_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_Value_Proxy(Field20 *This,VARIANT *pvar);
  void __RPC_STUB Field20_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_Value_Proxy(Field20 *This,VARIANT Val);
  void __RPC_STUB Field20_put_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_Precision_Proxy(Field20 *This,BYTE *pbPrecision);
  void __RPC_STUB Field20_get_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_NumericScale_Proxy(Field20 *This,BYTE *pbNumericScale);
  void __RPC_STUB Field20_get_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_AppendChunk_Proxy(Field20 *This,VARIANT Data);
  void __RPC_STUB Field20_AppendChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_GetChunk_Proxy(Field20 *This,__LONG32 Length,VARIANT *pvar);
  void __RPC_STUB Field20_GetChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_OriginalValue_Proxy(Field20 *This,VARIANT *pvar);
  void __RPC_STUB Field20_get_OriginalValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_UnderlyingValue_Proxy(Field20 *This,VARIANT *pvar);
  void __RPC_STUB Field20_get_UnderlyingValue_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_get_DataFormat_Proxy(Field20 *This,IUnknown **ppiDF);
  void __RPC_STUB Field20_get_DataFormat_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_putref_DataFormat_Proxy(Field20 *This,IUnknown *piDF);
  void __RPC_STUB Field20_putref_DataFormat_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_Precision_Proxy(Field20 *This,BYTE bPrecision);
  void __RPC_STUB Field20_put_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_NumericScale_Proxy(Field20 *This,BYTE bScale);
  void __RPC_STUB Field20_put_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_Type_Proxy(Field20 *This,DataTypeEnum DataType);
  void __RPC_STUB Field20_put_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_DefinedSize_Proxy(Field20 *This,ADO_LONGPTR lSize);
  void __RPC_STUB Field20_put_DefinedSize_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Field20_put_Attributes_Proxy(Field20 *This,__LONG32 lAttributes);
  void __RPC_STUB Field20_put_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Field_INTERFACE_DEFINED__
#define __Field_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Field;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOField : public Field20 {
  public:
    virtual HRESULT WINAPI get_Status(__LONG32 *pFStatus) = 0;
  };
#else
  typedef struct FieldVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOField *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOField *This);
      ULONG (WINAPI *Release)(ADOField *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOField *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOField *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOField *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOField *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(ADOField *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_ActualSize)(ADOField *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Attributes)(ADOField *This,__LONG32 *pl);
      HRESULT (WINAPI *get_DefinedSize)(ADOField *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *get_Name)(ADOField *This,BSTR *pbstr);
      HRESULT (WINAPI *get_Type)(ADOField *This,DataTypeEnum *pDataType);
      HRESULT (WINAPI *get_Value)(ADOField *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Value)(ADOField *This,VARIANT Val);
      HRESULT (WINAPI *get_Precision)(ADOField *This,BYTE *pbPrecision);
      HRESULT (WINAPI *get_NumericScale)(ADOField *This,BYTE *pbNumericScale);
      HRESULT (WINAPI *AppendChunk)(ADOField *This,VARIANT Data);
      HRESULT (WINAPI *GetChunk)(ADOField *This,__LONG32 Length,VARIANT *pvar);
      HRESULT (WINAPI *get_OriginalValue)(ADOField *This,VARIANT *pvar);
      HRESULT (WINAPI *get_UnderlyingValue)(ADOField *This,VARIANT *pvar);
      HRESULT (WINAPI *get_DataFormat)(ADOField *This,IUnknown **ppiDF);
      HRESULT (WINAPI *putref_DataFormat)(ADOField *This,IUnknown *piDF);
      HRESULT (WINAPI *put_Precision)(ADOField *This,BYTE bPrecision);
      HRESULT (WINAPI *put_NumericScale)(ADOField *This,BYTE bScale);
      HRESULT (WINAPI *put_Type)(ADOField *This,DataTypeEnum DataType);
      HRESULT (WINAPI *put_DefinedSize)(ADOField *This,ADO_LONGPTR lSize);
      HRESULT (WINAPI *put_Attributes)(ADOField *This,__LONG32 lAttributes);
      HRESULT (WINAPI *get_Status)(ADOField *This,__LONG32 *pFStatus);
    END_INTERFACE
  } FieldVtbl;
  struct Field {
    CONST_VTBL struct FieldVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Field_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Field_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Field_Release(This) (This)->lpVtbl -> Release(This)
#define Field_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Field_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Field_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Field_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Field_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define Field_get_ActualSize(This,pl) (This)->lpVtbl -> get_ActualSize(This,pl)
#define Field_get_Attributes(This,pl) (This)->lpVtbl -> get_Attributes(This,pl)
#define Field_get_DefinedSize(This,pl) (This)->lpVtbl -> get_DefinedSize(This,pl)
#define Field_get_Name(This,pbstr) (This)->lpVtbl -> get_Name(This,pbstr)
#define Field_get_Type(This,pDataType) (This)->lpVtbl -> get_Type(This,pDataType)
#define Field_get_Value(This,pvar) (This)->lpVtbl -> get_Value(This,pvar)
#define Field_put_Value(This,Val) (This)->lpVtbl -> put_Value(This,Val)
#define Field_get_Precision(This,pbPrecision) (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define Field_get_NumericScale(This,pbNumericScale) (This)->lpVtbl -> get_NumericScale(This,pbNumericScale)
#define Field_AppendChunk(This,Data) (This)->lpVtbl -> AppendChunk(This,Data)
#define Field_GetChunk(This,Length,pvar) (This)->lpVtbl -> GetChunk(This,Length,pvar)
#define Field_get_OriginalValue(This,pvar) (This)->lpVtbl -> get_OriginalValue(This,pvar)
#define Field_get_UnderlyingValue(This,pvar) (This)->lpVtbl -> get_UnderlyingValue(This,pvar)
#define Field_get_DataFormat(This,ppiDF) (This)->lpVtbl -> get_DataFormat(This,ppiDF)
#define Field_putref_DataFormat(This,piDF) (This)->lpVtbl -> putref_DataFormat(This,piDF)
#define Field_put_Precision(This,bPrecision) (This)->lpVtbl -> put_Precision(This,bPrecision)
#define Field_put_NumericScale(This,bScale) (This)->lpVtbl -> put_NumericScale(This,bScale)
#define Field_put_Type(This,DataType) (This)->lpVtbl -> put_Type(This,DataType)
#define Field_put_DefinedSize(This,lSize) (This)->lpVtbl -> put_DefinedSize(This,lSize)
#define Field_put_Attributes(This,lAttributes) (This)->lpVtbl -> put_Attributes(This,lAttributes)
#define Field_get_Status(This,pFStatus) (This)->lpVtbl -> get_Status(This,pFStatus)
#endif
#endif
  HRESULT WINAPI Field_get_Status_Proxy(ADOField *This,__LONG32 *pFStatus);
  void __RPC_STUB Field_get_Status_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Fields15_INTERFACE_DEFINED__
#define __Fields15_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Fields15;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Fields15 : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,ADOField **ppvObject) = 0;
  };
#else
  typedef struct Fields15Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Fields15 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Fields15 *This);
      ULONG (WINAPI *Release)(Fields15 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Fields15 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Fields15 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Fields15 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Fields15 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(Fields15 *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(Fields15 *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(Fields15 *This);
      HRESULT (WINAPI *get_Item)(Fields15 *This,VARIANT Index,ADOField **ppvObject);
    END_INTERFACE
  } Fields15Vtbl;
  struct Fields15 {
    CONST_VTBL struct Fields15Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Fields15_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields15_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Fields15_Release(This) (This)->lpVtbl -> Release(This)
#define Fields15_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields15_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields15_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields15_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Fields15_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Fields15__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields15_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Fields15_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Fields15_get_Item_Proxy(Fields15 *This,VARIANT Index,ADOField **ppvObject);
  void __RPC_STUB Fields15_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Fields20_INTERFACE_DEFINED__
#define __Fields20_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Fields20;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct Fields20 : public Fields15 {
  public:
    virtual HRESULT WINAPI _Append(BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize = 0,FieldAttributeEnum Attrib = adFldUnspecified) = 0;
    virtual HRESULT WINAPI Delete(VARIANT Index) = 0;
  };
#else
  typedef struct Fields20Vtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(Fields20 *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(Fields20 *This);
      ULONG (WINAPI *Release)(Fields20 *This);
      HRESULT (WINAPI *GetTypeInfoCount)(Fields20 *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(Fields20 *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(Fields20 *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(Fields20 *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(Fields20 *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(Fields20 *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(Fields20 *This);
      HRESULT (WINAPI *get_Item)(Fields20 *This,VARIANT Index,ADOField **ppvObject);
      HRESULT (WINAPI *_Append)(Fields20 *This,BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib);
      HRESULT (WINAPI *Delete)(Fields20 *This,VARIANT Index);
    END_INTERFACE
  } Fields20Vtbl;
  struct Fields20 {
    CONST_VTBL struct Fields20Vtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Fields20_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields20_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Fields20_Release(This) (This)->lpVtbl -> Release(This)
#define Fields20_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields20_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields20_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields20_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Fields20_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Fields20__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields20_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Fields20_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Fields20__Append(This,Name,Type,DefinedSize,Attrib) (This)->lpVtbl -> _Append(This,Name,Type,DefinedSize,Attrib)
#define Fields20_Delete(This,Index) (This)->lpVtbl -> Delete(This,Index)
#endif
#endif
  HRESULT WINAPI Fields20__Append_Proxy(Fields20 *This,BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib);
  void __RPC_STUB Fields20__Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Fields20_Delete_Proxy(Fields20 *This,VARIANT Index);
  void __RPC_STUB Fields20_Delete_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef __Fields_INTERFACE_DEFINED__
#define __Fields_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Fields;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOFields : public Fields20 {
  public:
    virtual HRESULT WINAPI Append(BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib,VARIANT FieldValue) = 0;
    virtual HRESULT WINAPI Update(void) = 0;
    virtual HRESULT WINAPI Resync(ResyncEnum ResyncValues = adResyncAllValues) = 0;
    virtual HRESULT WINAPI CancelUpdate(void) = 0;
  };
#else
  typedef struct FieldsVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOFields *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOFields *This);
      ULONG (WINAPI *Release)(ADOFields *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOFields *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOFields *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOFields *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOFields *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOFields *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOFields *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOFields *This);
      HRESULT (WINAPI *get_Item)(ADOFields *This,VARIANT Index,ADOField **ppvObject);
      HRESULT (WINAPI *_Append)(ADOFields *This,BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib);
      HRESULT (WINAPI *Delete)(ADOFields *This,VARIANT Index);
      HRESULT (WINAPI *Append)(ADOFields *This,BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib,VARIANT FieldValue);
      HRESULT (WINAPI *Update)(ADOFields *This);
      HRESULT (WINAPI *Resync)(ADOFields *This,ResyncEnum ResyncValues);
      HRESULT (WINAPI *CancelUpdate)(ADOFields *This);
    END_INTERFACE
  } FieldsVtbl;
  struct Fields {
    CONST_VTBL struct FieldsVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Fields_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Fields_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Fields_Release(This) (This)->lpVtbl -> Release(This)
#define Fields_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Fields_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Fields_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Fields_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Fields_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Fields__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Fields_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Fields_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#define Fields__Append(This,Name,Type,DefinedSize,Attrib) (This)->lpVtbl -> _Append(This,Name,Type,DefinedSize,Attrib)
#define Fields_Delete(This,Index) (This)->lpVtbl -> Delete(This,Index)
#define Fields_Append(This,Name,Type,DefinedSize,Attrib,FieldValue) (This)->lpVtbl -> Append(This,Name,Type,DefinedSize,Attrib,FieldValue)
#define Fields_Update(This) (This)->lpVtbl -> Update(This)
#define Fields_Resync(This,ResyncValues) (This)->lpVtbl -> Resync(This,ResyncValues)
#define Fields_CancelUpdate(This) (This)->lpVtbl -> CancelUpdate(This)
#endif
#endif
  HRESULT WINAPI Fields_Append_Proxy(ADOFields *This,BSTR Name,DataTypeEnum Type,ADO_LONGPTR DefinedSize,FieldAttributeEnum Attrib,VARIANT FieldValue);
  void __RPC_STUB Fields_Append_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Fields_Update_Proxy(ADOFields *This);
  void __RPC_STUB Fields_Update_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Fields_Resync_Proxy(ADOFields *This,ResyncEnum ResyncValues);
  void __RPC_STUB Fields_Resync_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI Fields_CancelUpdate_Proxy(ADOFields *This);
  void __RPC_STUB Fields_CancelUpdate_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif

#ifndef ___Parameter_INTERFACE_DEFINED__
#define ___Parameter_INTERFACE_DEFINED__
  EXTERN_C const IID IID__Parameter;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct _ADOParameter : public _ADO {
  public:
    virtual HRESULT WINAPI get_Name(BSTR *pbstr) = 0;
    virtual HRESULT WINAPI put_Name(BSTR bstr) = 0;
    virtual HRESULT WINAPI get_Value(VARIANT *pvar) = 0;
    virtual HRESULT WINAPI put_Value(VARIANT val) = 0;
    virtual HRESULT WINAPI get_Type(DataTypeEnum *psDataType) = 0;
    virtual HRESULT WINAPI put_Type(DataTypeEnum sDataType) = 0;
    virtual HRESULT WINAPI put_Direction(ParameterDirectionEnum lParmDirection) = 0;
    virtual HRESULT WINAPI get_Direction(ParameterDirectionEnum *plParmDirection) = 0;
    virtual HRESULT WINAPI put_Precision(BYTE bPrecision) = 0;
    virtual HRESULT WINAPI get_Precision(BYTE *pbPrecision) = 0;
    virtual HRESULT WINAPI put_NumericScale(BYTE bScale) = 0;
    virtual HRESULT WINAPI get_NumericScale(BYTE *pbScale) = 0;
    virtual HRESULT WINAPI put_Size(ADO_LONGPTR l) = 0;
    virtual HRESULT WINAPI get_Size(ADO_LONGPTR *pl) = 0;
    virtual HRESULT WINAPI AppendChunk(VARIANT Val) = 0;
    virtual HRESULT WINAPI get_Attributes(LONG *plParmAttribs) = 0;
    virtual HRESULT WINAPI put_Attributes(LONG lParmAttribs) = 0;
  };
#else
  typedef struct _ParameterVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(_ADOParameter *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(_ADOParameter *This);
      ULONG (WINAPI *Release)(_ADOParameter *This);
      HRESULT (WINAPI *GetTypeInfoCount)(_ADOParameter *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(_ADOParameter *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(_ADOParameter *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(_ADOParameter *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Properties)(_ADOParameter *This,ADOProperties **ppvObject);
      HRESULT (WINAPI *get_Name)(_ADOParameter *This,BSTR *pbstr);
      HRESULT (WINAPI *put_Name)(_ADOParameter *This,BSTR bstr);
      HRESULT (WINAPI *get_Value)(_ADOParameter *This,VARIANT *pvar);
      HRESULT (WINAPI *put_Value)(_ADOParameter *This,VARIANT val);
      HRESULT (WINAPI *get_Type)(_ADOParameter *This,DataTypeEnum *psDataType);
      HRESULT (WINAPI *put_Type)(_ADOParameter *This,DataTypeEnum sDataType);
      HRESULT (WINAPI *put_Direction)(_ADOParameter *This,ParameterDirectionEnum lParmDirection);
      HRESULT (WINAPI *get_Direction)(_ADOParameter *This,ParameterDirectionEnum *plParmDirection);
      HRESULT (WINAPI *put_Precision)(_ADOParameter *This,BYTE bPrecision);
      HRESULT (WINAPI *get_Precision)(_ADOParameter *This,BYTE *pbPrecision);
      HRESULT (WINAPI *put_NumericScale)(_ADOParameter *This,BYTE bScale);
      HRESULT (WINAPI *get_NumericScale)(_ADOParameter *This,BYTE *pbScale);
      HRESULT (WINAPI *put_Size)(_ADOParameter *This,ADO_LONGPTR l);
      HRESULT (WINAPI *get_Size)(_ADOParameter *This,ADO_LONGPTR *pl);
      HRESULT (WINAPI *AppendChunk)(_ADOParameter *This,VARIANT Val);
      HRESULT (WINAPI *get_Attributes)(_ADOParameter *This,LONG *plParmAttribs);
      HRESULT (WINAPI *put_Attributes)(_ADOParameter *This,LONG lParmAttribs);
    END_INTERFACE
  } _ParameterVtbl;
  struct _Parameter {
    CONST_VTBL struct _ParameterVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define _Parameter_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define _Parameter_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define _Parameter_Release(This) (This)->lpVtbl -> Release(This)
#define _Parameter_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define _Parameter_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define _Parameter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define _Parameter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define _Parameter_get_Properties(This,ppvObject) (This)->lpVtbl -> get_Properties(This,ppvObject)
#define _Parameter_get_Name(This,pbstr) (This)->lpVtbl -> get_Name(This,pbstr)
#define _Parameter_put_Name(This,bstr) (This)->lpVtbl -> put_Name(This,bstr)
#define _Parameter_get_Value(This,pvar) (This)->lpVtbl -> get_Value(This,pvar)
#define _Parameter_put_Value(This,val) (This)->lpVtbl -> put_Value(This,val)
#define _Parameter_get_Type(This,psDataType) (This)->lpVtbl -> get_Type(This,psDataType)
#define _Parameter_put_Type(This,sDataType) (This)->lpVtbl -> put_Type(This,sDataType)
#define _Parameter_put_Direction(This,lParmDirection) (This)->lpVtbl -> put_Direction(This,lParmDirection)
#define _Parameter_get_Direction(This,plParmDirection) (This)->lpVtbl -> get_Direction(This,plParmDirection)
#define _Parameter_put_Precision(This,bPrecision) (This)->lpVtbl -> put_Precision(This,bPrecision)
#define _Parameter_get_Precision(This,pbPrecision) (This)->lpVtbl -> get_Precision(This,pbPrecision)
#define _Parameter_put_NumericScale(This,bScale) (This)->lpVtbl -> put_NumericScale(This,bScale)
#define _Parameter_get_NumericScale(This,pbScale) (This)->lpVtbl -> get_NumericScale(This,pbScale)
#define _Parameter_put_Size(This,l) (This)->lpVtbl -> put_Size(This,l)
#define _Parameter_get_Size(This,pl) (This)->lpVtbl -> get_Size(This,pl)
#define _Parameter_AppendChunk(This,Val) (This)->lpVtbl -> AppendChunk(This,Val)
#define _Parameter_get_Attributes(This,plParmAttribs) (This)->lpVtbl -> get_Attributes(This,plParmAttribs)
#define _Parameter_put_Attributes(This,lParmAttribs) (This)->lpVtbl -> put_Attributes(This,lParmAttribs)
#endif
#endif
  HRESULT WINAPI _Parameter_get_Name_Proxy(_ADOParameter *This,BSTR *pbstr);
  void __RPC_STUB _Parameter_get_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Name_Proxy(_ADOParameter *This,BSTR bstr);
  void __RPC_STUB _Parameter_put_Name_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Value_Proxy(_ADOParameter *This,VARIANT *pvar);
  void __RPC_STUB _Parameter_get_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Value_Proxy(_ADOParameter *This,VARIANT val);
  void __RPC_STUB _Parameter_put_Value_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Type_Proxy(_ADOParameter *This,DataTypeEnum *psDataType);
  void __RPC_STUB _Parameter_get_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Type_Proxy(_ADOParameter *This,DataTypeEnum sDataType);
  void __RPC_STUB _Parameter_put_Type_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Direction_Proxy(_ADOParameter *This,ParameterDirectionEnum lParmDirection);
  void __RPC_STUB _Parameter_put_Direction_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Direction_Proxy(_ADOParameter *This,ParameterDirectionEnum *plParmDirection);
  void __RPC_STUB _Parameter_get_Direction_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Precision_Proxy(_ADOParameter *This,BYTE bPrecision);
  void __RPC_STUB _Parameter_put_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Precision_Proxy(_ADOParameter *This,BYTE *pbPrecision);
  void __RPC_STUB _Parameter_get_Precision_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_NumericScale_Proxy(_ADOParameter *This,BYTE bScale);
  void __RPC_STUB _Parameter_put_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_NumericScale_Proxy(_ADOParameter *This,BYTE *pbScale);
  void __RPC_STUB _Parameter_get_NumericScale_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Size_Proxy(_ADOParameter *This,ADO_LONGPTR l);
  void __RPC_STUB _Parameter_put_Size_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Size_Proxy(_ADOParameter *This,ADO_LONGPTR *pl);
  void __RPC_STUB _Parameter_get_Size_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_AppendChunk_Proxy(_ADOParameter *This,VARIANT Val);
  void __RPC_STUB _Parameter_AppendChunk_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_get_Attributes_Proxy(_ADOParameter *This,LONG *plParmAttribs);
  void __RPC_STUB _Parameter_get_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
  HRESULT WINAPI _Parameter_put_Attributes_Proxy(_ADOParameter *This,LONG lParmAttribs);
  void __RPC_STUB _Parameter_put_Attributes_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
  EXTERN_C const CLSID CLSID_Parameter;
#ifdef __cplusplus
  Parameter;
#endif

#ifndef __Parameters_INTERFACE_DEFINED__
#define __Parameters_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Parameters;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct
ADOParameters : public _ADODynaCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,_ADOParameter **ppvObject) = 0;
  };
#else
  typedef struct ParametersVtbl {
    BEGIN_INTERFACE
      HRESULT (WINAPI *QueryInterface)(ADOParameters *This,REFIID riid,void **ppvObject);
      ULONG (WINAPI *AddRef)(ADOParameters *This);
      ULONG (WINAPI *Release)(ADOParameters *This);
      HRESULT (WINAPI *GetTypeInfoCount)(ADOParameters *This,UINT *pctinfo);
      HRESULT (WINAPI *GetTypeInfo)(ADOParameters *This,UINT iTInfo,LCID lcid,ITypeInfo **ppTInfo);
      HRESULT (WINAPI *GetIDsOfNames)(ADOParameters *This,REFIID riid,LPOLESTR *rgszNames,UINT cNames,LCID lcid,DISPID *rgDispId);
      HRESULT (WINAPI *Invoke)(ADOParameters *This,DISPID dispIdMember,REFIID riid,LCID lcid,WORD wFlags,DISPPARAMS *pDispParams,VARIANT *pVarResult,EXCEPINFO *pExcepInfo,UINT *puArgErr);
      HRESULT (WINAPI *get_Count)(ADOParameters *This,__LONG32 *c);
      HRESULT (WINAPI *_NewEnum)(ADOParameters *This,IUnknown **ppvObject);
      HRESULT (WINAPI *Refresh)(ADOParameters *This);
      HRESULT (WINAPI *Append)(ADOParameters *This,IDispatch *Object);
      HRESULT (WINAPI *Delete)(ADOParameters *This,VARIANT Index);
      HRESULT (WINAPI *get_Item)(ADOParameters *This,VARIANT Index,_ADOParameter **ppvObject);
    END_INTERFACE
  } ParametersVtbl;
  struct Parameters {
    CONST_VTBL struct ParametersVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Parameters_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Parameters_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Parameters_Release(This) (This)->lpVtbl -> Release(This)
#define Parameters_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Parameters_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Parameters_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Parameters_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Parameters_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Parameters__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Parameters_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Parameters_Append(This,Object) (This)->lpVtbl -> Append(This,Object)
#define Parameters_Delete(This,Index) (This)->lpVtbl -> Delete(This,Index)
#define Parameters_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Parameters_get_Item_Proxy(ADOParameters *This,VARIANT Index,_ADOParameter **ppvObject);
  void __RPC_STUB Parameters_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
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
#define Property_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Property_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Property_Release(This) (This)->lpVtbl -> Release(This)
#define Property_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Property_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Property_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Property_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Property_get_Value(This,pval) (This)->lpVtbl -> get_Value(This,pval)
#define Property_put_Value(This,val) (This)->lpVtbl -> put_Value(This,val)
#define Property_get_Name(This,pbstr) (This)->lpVtbl -> get_Name(This,pbstr)
#define Property_get_Type(This,ptype) (This)->lpVtbl -> get_Type(This,ptype)
#define Property_get_Attributes(This,plAttributes) (This)->lpVtbl -> get_Attributes(This,plAttributes)
#define Property_put_Attributes(This,lAttributes) (This)->lpVtbl -> put_Attributes(This,lAttributes)
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

#ifndef __Properties_INTERFACE_DEFINED__
#define __Properties_INTERFACE_DEFINED__
  EXTERN_C const IID IID_Properties;
#if defined(__cplusplus) && !defined(CINTERFACE)
  struct ADOProperties : public _ADOCollection {
  public:
    virtual HRESULT WINAPI get_Item(VARIANT Index,ADOProperty **ppvObject) = 0;

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
      HRESULT (WINAPI *get_Item)(ADOProperties *This,VARIANT Index,ADOProperty **ppvObject);
    END_INTERFACE
  } PropertiesVtbl;
  struct Properties {
    CONST_VTBL struct PropertiesVtbl *lpVtbl;
  };
#ifdef COBJMACROS
#define Properties_QueryInterface(This,riid,ppvObject) (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)
#define Properties_AddRef(This) (This)->lpVtbl -> AddRef(This)
#define Properties_Release(This) (This)->lpVtbl -> Release(This)
#define Properties_GetTypeInfoCount(This,pctinfo) (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)
#define Properties_GetTypeInfo(This,iTInfo,lcid,ppTInfo) (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)
#define Properties_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)
#define Properties_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)
#define Properties_get_Count(This,c) (This)->lpVtbl -> get_Count(This,c)
#define Properties__NewEnum(This,ppvObject) (This)->lpVtbl -> _NewEnum(This,ppvObject)
#define Properties_Refresh(This) (This)->lpVtbl -> Refresh(This)
#define Properties_get_Item(This,Index,ppvObject) (This)->lpVtbl -> get_Item(This,Index,ppvObject)
#endif
#endif
  HRESULT WINAPI Properties_get_Item_Proxy(ADOProperties *This,VARIANT Index,ADOProperty **ppvObject);
  void __RPC_STUB Properties_get_Item_Stub(IRpcStubBuffer *This,IRpcChannelBuffer *_pRpcChannelBuffer,PRPC_MESSAGE _pRpcMessage,DWORD *_pdwStubPhase);
#endif
#endif

  extern RPC_IF_HANDLE __MIDL_itf_m_bobj_0150_v0_0_c_ifspec;
  extern RPC_IF_HANDLE __MIDL_itf_m_bobj_0150_v0_0_s_ifspec;

#ifdef __cplusplus
}
#endif
#endif
#define ADOCommand _ADOCommand
#define ADORecordset _ADORecordset
#define ADOTransaction _ADOTransaction
#define ADOParameter _ADOParameter
#define ADOConnection _ADOConnection
#define ADOCollection _ADOCollection
#define ADODynaCollection _ADODynaCollection
#define ADORecord _ADORecord
#define ADORecField _ADORecField
#define ADOStream _ADOStream
#endif
