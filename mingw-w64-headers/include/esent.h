/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_ESENT
#define _INC_ESENT

#ifdef __cplusplus
extern "C" {
#endif

#ifndef JET_API
#define JET_API WINAPI
#endif

#if defined(_WIN64)
typedef unsigned __int64 JET_API_PTR;
#elif !defined(__midl) && (defined(_X86_) || defined(_M_IX86)) && _MSC_VER >= 1300
typedef __w64 unsigned long JET_API_PTR;
#else
typedef unsigned long JET_API_PTR;
#endif

#ifndef __WCHAR_DEFINED
#define __WCHAR_DEFINED
typedef wchar_t WCHAR;
#endif

typedef enum _JET_CBTYP {
  JET_cbtypNull = 0x00000000,
  JET_cbtypFinalize = 0x00000001,
  JET_cbtypBeforeInsert = 0x00000002,
  JET_cbtypAfterInsert = 0x00000004,
  JET_cbtypBeforeReplace = 0x00000008,
  JET_cbtypAfterReplace = 0x00000010,
  JET_cbtypBeforeDelete = 0x00000020,
  JET_cbtypAfterDelete = 0x00000040,
  JET_cbtypUserDefinedDefaultValue = 0x00000080,
  JET_cbtypOnlineDefragCompleted = 0x00000100,
  JET_cbtypFreeCursorLS = 0x00000200,
  JET_cbtypFreeTableLS = 0x00000400
} JET_CBTYP;

typedef enum _JET_COLTYP {
  JET_coltypNil = 0,
  JET_coltypBit,
  JET_coltypUnsignedByte,
  JET_coltypShort,
  JET_coltypLong,
  JET_coltypCurrency,
  JET_coltypIEEESingle,
  JET_coltypIEEEDouble,
  JET_coltypDateTime,
  JET_coltypBinary,
  JET_coltypText,
  JET_coltypLongBinary,
  JET_coltypLongText,
  JET_coltypSLV,
#if (_WIN32_WINNT >= 0x0600)
  JET_coltypUnsignedLong,
  JET_coltypLongLong,
  JET_coltypGUID,
  JET_coltypUnsignedShort,
#endif
  JET_coltypMax
} JET_COLTYP;

typedef enum _JET_OBJTYP {
  JET_objtypNil = 0,
  JET_objtypTable
} JET_OBJTYP;

typedef enum _JET_SNP {
  JET_snpRepair = 2,
  JET_snpCompact = 4,
  JET_snpRestore = 8,
  JET_snpBackup = 9,
  JET_snpUpgrade = 10,
  JET_snpScrub = 11,
  JET_snpUpgradeRecordFormat = 12
} JET_SNP;

typedef enum _JET_SNT {
  JET_sntBegin = 5,
  JET_sntRequirements = 7,
  JET_sntProgress = 0,
  JET_sntComplete = 6,
  JET_sntFail = 3
} JET_SNT;

#define JET_errSuccess 0
#define JET_wrnRemainingVersions 321
#define JET_wrnUniqueKey 345
#define JET_wrnSeparateLongValue 406
#define JET_wrnExistingLogFileHasBadSignature 558
#define JET_wrnExistingLogFileIsNotContiguous 559
#define JET_wrnSkipThisRecord 564
#define JET_wrnTargetInstanceRunning 578
#define JET_wrnDatabaseRepaired 595
#define JET_wrnColumnNull 1004
#define JET_wrnBufferTruncated 1006
#define JET_wrnDatabaseAttached 1007
#define JET_wrnSortOverflow 1009
#define JET_wrnSeekNotEqual 1039
#define JET_wrnRecordFoundGreater JET_wrnSeekNotEqual
#define JET_wrnRecordFoundLess JET_wrnSeekNotEqual
#define JET_wrnNoErrorInfo 1055
#define JET_wrnNoIdleActivity 1058
#define JET_wrnNoWriteLock 1067
#define JET_wrnColumnSetNull 1068
#define JET_wrnTableEmpty 1301
#define JET_wrnTableInUseBySystem 1327
#define JET_wrnCorruptIndexDeleted 1415
#define JET_wrnColumnMaxTruncated 1512
#define JET_wrnCopyLongValue 1520
#define JET_wrnColumnSkipped 1531
#define JET_wrnColumnNotLocal 1532
#define JET_wrnColumnMoreTags 1533
#define JET_wrnColumnTruncated 1534
#define JET_wrnColumnPresent 1535
#define JET_wrnColumnSingleValue 1536
#define JET_wrnColumnDefault 1537
#define JET_wrnDataHasChanged 1610
#define JET_wrnKeyChanged 1618
#define JET_wrnFileOpenReadOnly 1813
#define JET_wrnIdleFull 1908
#define JET_wrnDefragAlreadyRunning 2000
#define JET_wrnDefragNotRunning 2001
#define JET_wrnCallbackNotRegistered 2100
#define JET_wrnNyi -1
#define JET_errRfsFailure -100
#define JET_errRfsNotArmed -101
#define JET_errFileClose -102
#define JET_errOutOfThreads -103
#define JET_errTooManyIO -105
#define JET_errTaskDropped -106
#define JET_errInternalError -107
#define JET_errDatabaseBufferDependenciesCorrupted -255
#define JET_errPreviousVersion -322
#define JET_errPageBoundary -323
#define JET_errKeyBoundary -324
#define JET_errBadPageLink -327
#define JET_errBadBookmark -328
#define JET_errNTSystemCallFailed -334
#define JET_errBadParentPageLink -338
#define JET_errSPAvailExtCacheOutOfSync -340
#define JET_errSPAvailExtCorrupted -341
#define JET_errSPAvailExtCacheOutOfMemory -342
#define JET_errSPOwnExtCorrupted -343
#define JET_errDbTimeCorrupted -344
#define JET_errKeyTruncated -346
#define JET_errKeyTooBig -408
#define JET_errInvalidLoggedOperation -500
#define JET_errLogFileCorrupt -501
#define JET_errNoBackupDirectory -503
#define JET_errBackupDirectoryNotEmpty -504
#define JET_errBackupInProgress -505
#define JET_errRestoreInProgress -506
#define JET_errMissingPreviousLogFile -509
#define JET_errLogWriteFail -510
#define JET_errLogDisabledDueToRecoveryFailure -511
#define JET_errCannotLogDuringRecoveryRedo -512
#define JET_errLogGenerationMismatch -513
#define JET_errBadLogVersion -514
#define JET_errInvalidLogSequence -515
#define JET_errLoggingDisabled -516
#define JET_errLogBufferTooSmall -517
#define JET_errLogSequenceEnd -519
#define JET_errNoBackup -520
#define JET_errInvalidBackupSequence -521
#define JET_errBackupNotAllowedYet -523
#define JET_errDeleteBackupFileFail -524
#define JET_errMakeBackupDirectoryFail -525
#define JET_errInvalidBackup -526
#define JET_errRecoveredWithErrors -527
#define JET_errMissingLogFile -528
#define JET_errLogDiskFull -529
#define JET_errBadLogSignature -530
#define JET_errBadDbSignature -531
#define JET_errBadCheckpointSignature -532
#define JET_errCheckpointCorrupt -533
#define JET_errMissingPatchPage -534
#define JET_errBadPatchPage -535
#define JET_errRedoAbruptEnded -536
#define JET_errBadSLVSignature -537
#define JET_errPatchFileMissing -538
#define JET_errDatabaseLogSetMismatch -539
#define JET_errDatabaseStreamingFileMismatch -540
#define JET_errLogFileSizeMismatch -541
#define JET_errCheckpointFileNotFound -542
#define JET_errRequiredLogFilesMissing -543
#define JET_errSoftRecoveryOnBackupDatabase -544
#define JET_errLogFileSizeMismatchDatabasesConsistent -545
#define JET_errLogSectorSizeMismatch -546
#define JET_errLogSectorSizeMismatchDatabasesConsistent -547
#define JET_errLogSequenceEndDatabasesConsistent -548
#define JET_errStreamingDataNotLogged -549
#define JET_errDatabaseDirtyShutdown -550
#define JET_errDatabaseInconsistent JET_errDatabaseDirtyShutdown
#define JET_errConsistentTimeMismatch -551
#define JET_errDatabasePatchFileMismatch -552
#define JET_errEndingRestoreLogTooLow -553
#define JET_errStartingRestoreLogTooHigh -554
#define JET_errGivenLogFileHasBadSignature -555
#define JET_errGivenLogFileIsNotContiguous -556
#define JET_errMissingRestoreLogFiles -557
#define JET_errMissingFullBackup -560
#define JET_errBadBackupDatabaseSize -561
#define JET_errDatabaseAlreadyUpgraded -562
#define JET_errDatabaseIncompleteUpgrade -563
#define JET_errMissingCurrentLogFiles -565
#define JET_errDbTimeTooOld -566
#define JET_errDbTimeTooNew -567
#define JET_errMissingFileToBackup -569
#define JET_errLogTornWriteDuringHardRestore -570
#define JET_errLogTornWriteDuringHardRecovery -571
#define JET_errLogCorruptDuringHardRestore -573
#define JET_errLogCorruptDuringHardRecovery -574
#define JET_errMustDisableLoggingForDbUpgrade -575
#define JET_errBadRestoreTargetInstance -577
#define JET_errRecoveredWithoutUndo -579
#define JET_errDatabasesNotFromSameSnapshot -580
#define JET_errSoftRecoveryOnSnapshot -581
#define JET_errUnicodeTranslationBufferTooSmall -601
#define JET_errUnicodeTranslationFail -602
#define JET_errUnicodeNormalizationNotSupported -603
#define JET_errExistingLogFileHasBadSignature -610
#define JET_errExistingLogFileIsNotContiguous -611
#define JET_errLogReadVerifyFailure -612
#define JET_errSLVReadVerifyFailure -613
#define JET_errCheckpointDepthTooDeep -614
#define JET_errRestoreOfNonBackupDatabase -615
#define JET_errInvalidGrbit -900
#define JET_errTermInProgress -1000
#define JET_errFeatureNotAvailable -1001
#define JET_errInvalidName -1002
#define JET_errInvalidParameter -1003
#define JET_errDatabaseFileReadOnly -1008
#define JET_errInvalidDatabaseId -1010
#define JET_errOutOfMemory -1011
#define JET_errOutOfDatabaseSpace -1012
#define JET_errOutOfCursors -1013
#define JET_errOutOfBuffers -1014
#define JET_errTooManyIndexes -1015
#define JET_errTooManyKeys -1016
#define JET_errRecordDeleted -1017
#define JET_errReadVerifyFailure -1018
#define JET_errPageNotInitialized -1019
#define JET_errOutOfFileHandles -1020
#define JET_errDiskIO -1022
#define JET_errInvalidPath -1023
#define JET_errInvalidSystemPath -1024
#define JET_errInvalidLogDirectory -1025
#define JET_errRecordTooBig -1026
#define JET_errTooManyOpenDatabases -1027
#define JET_errInvalidDatabase -1028
#define JET_errNotInitialized -1029
#define JET_errAlreadyInitialized -1030
#define JET_errInitInProgress -1031
#define JET_errFileAccessDenied -1032
#define JET_errBufferTooSmall -1038
#define JET_errTooManyColumns -1040
#define JET_errContainerNotEmpty -1043
#define JET_errInvalidFilename -1044
#define JET_errInvalidBookmark -1045
#define JET_errColumnInUse -1046
#define JET_errInvalidBufferSize -1047
#define JET_errColumnNotUpdatable -1048
#define JET_errIndexInUse -1051
#define JET_errLinkNotSupported -1052
#define JET_errNullKeyDisallowed -1053
#define JET_errNotInTransaction -1054
#define JET_errTooManyActiveUsers -1059
#define JET_errInvalidCountry -1061
#define JET_errInvalidLanguageId -1062
#define JET_errInvalidCodePage -1063
#define JET_errInvalidLCMapStringFlags -1064
#define JET_errVersionStoreEntryTooBig -1065
#define JET_errVersionStoreOutOfMemoryAndCleanupTimedOut -1066
#define JET_errVersionStoreOutOfMemory -1069
#define JET_errCannotIndex -1071
#define JET_errRecordNotDeleted -1072
#define JET_errTooManyMempoolEntries -1073
#define JET_errOutOfObjectIDs -1074
#define JET_errOutOfLongValueIDs -1075
#define JET_errOutOfAutoincrementValues -1076
#define JET_errOutOfDbtimeValues -1077
#define JET_errOutOfSequentialIndexValues -1078
#define JET_errRunningInOneInstanceMode -1080
#define JET_errRunningInMultiInstanceMode -1081
#define JET_errSystemParamsAlreadySet -1082
#define JET_errSystemPathInUse -1083
#define JET_errLogFilePathInUse -1084
#define JET_errTempPathInUse -1085
#define JET_errInstanceNameInUse -1086
#define JET_errInstanceUnavailable -1090
#define JET_errDatabaseUnavailable -1091
#define JET_errInstanceUnavailableDueToFatalLogDiskFull -1092
#define JET_errOutOfSessions -1101
#define JET_errWriteConflict -1102
#define JET_errTransTooDeep -1103
#define JET_errInvalidSesid -1104
#define JET_errWriteConflictPrimaryIndex -1105
#define JET_errInTransaction -1108
#define JET_errRollbackRequired -1109
#define JET_errTransReadOnly -1110
#define JET_errSessionWriteConflict -1111
#define JET_errRecordTooBigForBackwardCompatibility -1112
#define JET_errCannotMaterializeForwardOnlySort -1113
#define JET_errSesidTableIdMismatch -1114
#define JET_errInvalidInstance -1115
#define JET_errDatabaseDuplicate -1201
#define JET_errDatabaseInUse -1202
#define JET_errDatabaseNotFound -1203
#define JET_errDatabaseInvalidName -1204
#define JET_errDatabaseInvalidPages -1205
#define JET_errDatabaseCorrupted -1206
#define JET_errDatabaseLocked -1207
#define JET_errCannotDisableVersioning -1208
#define JET_errInvalidDatabaseVersion -1209
#define JET_errDatabase200Format -1210
#define JET_errDatabase400Format -1211
#define JET_errDatabase500Format -1212
#define JET_errPageSizeMismatch -1213
#define JET_errTooManyInstances -1214
#define JET_errDatabaseSharingViolation -1215
#define JET_errAttachedDatabaseMismatch -1216
#define JET_errDatabaseInvalidPath -1217
#define JET_errDatabaseIdInUse -1218
#define JET_errForceDetachNotAllowed -1219
#define JET_errCatalogCorrupted -1220
#define JET_errPartiallyAttachedDB -1221
#define JET_errDatabaseSignInUse -1222
#define JET_errDatabaseCorruptedNoRepair -1224
#define JET_errInvalidCreateDbVersion -1225
#define JET_errTableLocked -1302
#define JET_errTableDuplicate -1303
#define JET_errTableInUse -1304
#define JET_errObjectNotFound -1305
#define JET_errDensityInvalid -1307
#define JET_errTableNotEmpty -1308
#define JET_errInvalidTableId -1310
#define JET_errTooManyOpenTables -1311
#define JET_errIllegalOperation -1312
#define JET_errTooManyOpenTablesAndCleanupTimedOut -1313
#define JET_errObjectDuplicate -1314
#define JET_errInvalidObject -1316
#define JET_errCannotDeleteTempTable -1317
#define JET_errCannotDeleteSystemTable -1318
#define JET_errCannotDeleteTemplateTable -1319
#define JET_errExclusiveTableLockRequired -1322
#define JET_errFixedDDL -1323
#define JET_errFixedInheritedDDL -1324
#define JET_errCannotNestDDL -1325
#define JET_errDDLNotInheritable -1326
#define JET_errInvalidSettings -1328
#define JET_errClientRequestToStopJetService -1329
#define JET_errCannotAddFixedVarColumnToDerivedTable -1330
#define JET_errIndexCantBuild -1401
#define JET_errIndexHasPrimary -1402
#define JET_errIndexDuplicate -1403
#define JET_errIndexNotFound -1404
#define JET_errIndexMustStay -1405
#define JET_errIndexInvalidDef -1406
#define JET_errInvalidCreateIndex -1409
#define JET_errTooManyOpenIndexes -1410
#define JET_errMultiValuedIndexViolation -1411
#define JET_errIndexBuildCorrupted -1412
#define JET_errPrimaryIndexCorrupted -1413
#define JET_errSecondaryIndexCorrupted -1414
#define JET_errInvalidIndexId -1416
#define JET_errIndexTuplesSecondaryIndexOnly -1430
#define JET_errIndexTuplesTooManyColumns -1431
#define JET_errIndexTuplesNonUniqueOnly -1432
#define JET_errIndexTuplesTextBinaryColumnsOnly -1433
#define JET_errIndexTuplesVarSegMacNotAllowed -1434
#define JET_errIndexTuplesInvalidLimits -1435
#define JET_errIndexTuplesCannotRetrieveFromIndex -1436
#define JET_errIndexTuplesKeyTooSmall -1437
#define JET_errColumnLong -1501
#define JET_errColumnNoChunk -1502
#define JET_errColumnDoesNotFit -1503
#define JET_errNullInvalid -1504
#define JET_errColumnIllegalNull JET_errNullInvalid
#define JET_errColumnIndexed -1505
#define JET_errColumnTooBig -1506
#define JET_errColumnNotFound -1507
#define JET_errColumnDuplicate -1508
#define JET_errMultiValuedColumnMustBeTagged -1509
#define JET_errColumnRedundant -1510
#define JET_errInvalidColumnType -1511
#define JET_errTaggedNotNULL -1514
#define JET_errNoCurrentIndex -1515
#define JET_errKeyIsMade -1516
#define JET_errBadColumnId -1517
#define JET_errBadItagSequence -1518
#define JET_errColumnInRelationship -1519
#define JET_errCannotBeTagged -1521
#define JET_errDefaultValueTooBig -1524
#define JET_errMultiValuedDuplicate -1525
#define JET_errLVCorrupted -1526
#define JET_errMultiValuedDuplicateAfterTruncation -1528
#define JET_errDerivedColumnCorruption -1529
#define JET_errInvalidPlaceholderColumn -1530
#define JET_errRecordNotFound -1601
#define JET_errRecordNoCopy -1602
#define JET_errNoCurrentRecord -1603
#define JET_errRecordPrimaryChanged -1604
#define JET_errKeyDuplicate -1605
#define JET_errAlreadyPrepared -1607
#define JET_errKeyNotMade -1608
#define JET_errUpdateNotPrepared -1609
#define JET_errDataHasChanged -1611
#define JET_errLanguageNotSupported -1619
#define JET_errTooManySorts -1701
#define JET_errInvalidOnSort -1702
#define JET_errTempFileOpenError -1803
#define JET_errTooManyAttachedDatabases -1805
#define JET_errDiskFull -1808
#define JET_errPermissionDenied -1809
#define JET_errFileNotFound -1811
#define JET_errFileInvalidType -1812
#define JET_errAfterInitialization -1850
#define JET_errLogCorrupted -1852
#define JET_errInvalidOperation -1906
#define JET_errAccessDenied -1907
#define JET_errTooManySplits -1909
#define JET_errSessionSharingViolation -1910
#define JET_errEntryPointNotFound -1911
#define JET_errSessionContextAlreadySet -1912
#define JET_errSessionContextNotSetByThisThread -1913
#define JET_errSessionInUse -1914
#define JET_errRecordFormatConversionFailed -1915
#define JET_errOneDatabasePerSession -1916
#define JET_errRollbackError -1917
#define JET_errCallbackFailed -2101
#define JET_errCallbackNotResolved -2102
#define JET_errOSSnapshotInvalidSequence -2401
#define JET_errOSSnapshotTimeOut -2402
#define JET_errOSSnapshotNotAllowed -2403
#define JET_errOSSnapshotInvalidSnapId -2404
#define JET_errLSCallbackNotSpecified -3000
#define JET_errLSAlreadySet -3001
#define JET_errLSNotSet -3002
#define JET_errFileIOSparse -4000
#define JET_errFileIOBeyondEOF -4001
#define JET_errFileIOAbort -4002
#define JET_errFileIORetry -4003
#define JET_errFileIOFail -4004
#define JET_errFileCompressed -4005

#define JET_ExceptionMsgBox 0x0001
#define JET_ExceptionNone 0x0002

#define JET_EventLoggingDisable 0
#define JET_EventLoggingLevelMax 100

#define JET_instanceNil (~(JET_INSTANCE)0)
#define JET_sesidNil (~(JET_SESID)0)
#define JET_tableidNil (~(JET_TABLEID)0)
#define JET_bitNil ((JET_GRBIT)0)
#define JET_LSNil (~(JET_LS)0)
#define JET_dbidNil ((JET_DBID) 0xFFFFFFFF)

#define JET_BASE_NAME_LENGTH 3
#define JET_MAX_COMPUTERNAME_LENGTH 15
#define JET_cbBookmarkMost 256
#if UNICODE
#define JET_cbNameMost 128
#define JET_cbFullNameMost 510
#else
#define JET_cbNameMost 64
#define JET_cbFullNameMost 255
#endif
#define JET_cbColumnLVPageOverhead 82
#define JET_cbColumnMost 255
#define JET_cbLVDefaultValueMost 255
#define JET_cbKeyMost 255
#if (_WIN32_WINNT >= 0x0600)
#define JET_cbKeyMost2KBytePage 500
#define JET_cbKeyMost4KBytePage 1000
#define JET_cbKeyMost8KBytePage 2000
#define JET_cbKeyMostMin 255
#define JET_ccolKeyMost 12
#endif /*(_WIN32_WINNT >= 0x0600)*/
#define JET_cbLimitKeyMost 256
#define JET_cbPrimaryKeyMost 255
#define JET_cbSecondaryKeyMost 255
#if (_WIN32_WINNT == 0x500)
#define JET_ccolMost 0x00007ffe
#else
#define JET_ccolMost 0x0000fee0
#endif /*(_WIN32_WINNT == 0x500)*/
#define JET_ccolFixedMost 0x0000007f
#define JET_ccolVarMost 0x00000080
#define JET_ccolTaggedMost ( JET_ccolMost - 0x000000ff ) /*64993*/

typedef unsigned long JET_COLUMNID;
typedef double JET_DATESERIAL;
typedef unsigned long JET_DBID;
typedef long JET_ERR;
typedef unsigned long JET_GRBIT;
typedef JET_API_PTR JET_HANDLE;
typedef JET_API_PTR JET_INSTANCE;
typedef JET_API_PTR JET_LS;
typedef JET_API_PTR JET_OSSNAPID;
typedef const char *  JET_PCSTR; /*__nullterminated*/
typedef const WCHAR * JET_PCWSTR;/*__nullterminated*/
typedef char *  JET_PSTR;        /*__nullterminated*/
typedef WCHAR * JET_PWSTR;       /*__nullterminated*/
typedef JET_API_PTR JET_SESID;
typedef JET_API_PTR JET_TABLEID;

typedef struct _JET_ENUMCOLUMNVALUE JET_ENUMCOLUMNVALUE;

typedef struct _JET_LGPOS {
  unsigned short ib;
  unsigned short isec;
  long lGeneration;
} JET_LGPOS;

typedef struct _JET_LOGTIME {
  char bSeconds;
  char bMinutes;
  char bHours;
  char bDay;
  char bMonth;
  char bYear;
  char bFiller1;
  char bFiller2;
} JET_LOGTIME;

typedef struct _JET_BKLOGTIME {
  char bSeconds;
  char bMinutes;
  char bHours;
  char bDay;
  char bMonth;
  char bYear;
  char bFiller1;
  __C89_NAMELESS union {
    char bFiller2;
    __C89_NAMELESS struct {
      unsigned char fOSSnapshot  :1;
      unsigned char fReserved  :7;
    };
  };
} JET_BKLOGTIME;

typedef struct _JET_SIGNATURE {
  unsigned long ulRandom;
  JET_LOGTIME logtimeCreate;
  char szComputerName[JET_MAX_COMPUTERNAME_LENGTH + 1];
} JET_SIGNATURE;

typedef struct tagJET_UNICODEINDEX {
  unsigned long lcid;
  unsigned long dwMapFlags;
} JET_UNICODEINDEX;

typedef struct tagJET_TUPLELIMITS {
  unsigned long chLengthMin;
  unsigned long chLengthMax;
  unsigned long chToIndexMax;
  unsigned long cchIncrement;
  unsigned long ichStart;
} JET_TUPLELIMITS;

typedef struct _JET_BKINFO {
  JET_LGPOS lgposMark;
  __C89_NAMELESS union {
    JET_LOGTIME logtimeMark;
    JET_BKLOGTIME bklogtimeMark;
  };
  unsigned long genLow;
  unsigned long genHigh;
} JET_BKINFO;

typedef struct _JET_COLUMNBASE_A{
  unsigned long cbStruct;
  JET_COLUMNID columnid;
  JET_COLTYP coltyp;
  unsigned short wCountry;
  unsigned short langid;
  unsigned short cp;
  unsigned short wFiller;
  unsigned long cbMax;
  JET_GRBIT grbit;
  char szBaseTableName[256];
  char szBaseColumnName[256];
} JET_COLUMNBASE_A;

typedef struct _JET_COLUMNBASE_W{
  unsigned long cbStruct;
  JET_COLUMNID columnid;
  JET_COLTYP coltyp;
  unsigned short wCountry;
  unsigned short langid;
  unsigned short cp;
  unsigned short wFiller;
  unsigned long cbMax;
  JET_GRBIT grbit;
  WCHAR szBaseTableName[256];
  WCHAR szBaseColumnName[256];
} JET_COLUMNBASE_W;

#define JET_COLUMNBASE __MINGW_NAME_AW(JET_COLUMNBASE_)

typedef struct tag_JET_COLUMNCREATE_A {
  unsigned long cbStruct;
  char* szColumnName;
  JET_COLTYP coltyp;
  unsigned long cbMax;
  JET_GRBIT grbit;
  void* pvDefault;
  unsigned long cbDefault;
  unsigned long cp;
  JET_COLUMNID columnid;
  JET_ERR err;
} JET_COLUMNCREATE_A;

typedef struct tag_JET_COLUMNCREATE_W {
  unsigned long cbStruct;
  WCHAR* szColumnName;
  JET_COLTYP coltyp;
  unsigned long cbMax;
  JET_GRBIT grbit;
  void* pvDefault;
  unsigned long cbDefault;
  unsigned long cp;
  JET_COLUMNID columnid;
  JET_ERR err;
} JET_COLUMNCREATE_W;

#define JET_COLUMNCREATE __MINGW_NAME_AW(JET_COLUMNCREATE_)

typedef struct _JET_COLUMNDEF {
  unsigned long cbStruct;
  JET_COLUMNID columnid;
  JET_COLTYP coltyp;
  unsigned short wCountry;
  unsigned short langid;
  unsigned short cp;
  unsigned short wCollate;
  unsigned long cbMax;
  JET_GRBIT grbit;
} JET_COLUMNDEF;

typedef struct _JET_COLUMNLIST {
  unsigned long cbStruct;
  JET_TABLEID tableid;
  unsigned long cRecord;
  JET_COLUMNID columnidPresentationOrder;
  JET_COLUMNID columnidcolumnname;
  JET_COLUMNID columnidcolumnid;
  JET_COLUMNID columnidcoltyp;
  JET_COLUMNID columnidCountry;
  JET_COLUMNID columnidLangid;
  JET_COLUMNID columnidCp;
  JET_COLUMNID columnidCollate;
  JET_COLUMNID columnidcbMax;
  JET_COLUMNID columnidgrbit;
  JET_COLUMNID columnidDefault;
  JET_COLUMNID columnidBaseTableName;
  JET_COLUMNID columnidBaseColumnName;
  JET_COLUMNID columnidDefinitionName;
} JET_COLUMNLIST;

typedef struct tagJET_CONDITIONALCOLUMN_A {
  unsigned long cbStruct;
  char* szColumnName;
  JET_GRBIT grbit;
} JET_CONDITIONALCOLUMN_A;

typedef struct tagJET_CONDITIONALCOLUMN_W {
  unsigned long cbStruct;
  WCHAR* szColumnName;
  JET_GRBIT grbit;
} JET_CONDITIONALCOLUMN_W;

#define JET_CONDITIONALCOLUMN __MINGW_NAME_AW(JET_CONDITIONALCOLUMN_)

typedef struct tagCONVERT_A {
  char* SzOldDll;
  __C89_NAMELESS union {
    unsigned long fFlags;
    __C89_NAMELESS struct {
      unsigned long fSchemaChangesOnly  :1;
    };
  };
} JET_CONVERT_A;

typedef struct tagCONVERT_W {
  WCHAR* SzOldDll;
  __C89_NAMELESS union {
    unsigned long fFlags;
    __C89_NAMELESS struct {
      unsigned long fSchemaChangesOnly  :1;
    };
  };
} JET_CONVERT_W;

#define JET_CONVERT __MINGW_NAME_AW(JET_CONVERT_)

#define JET_dbstateJustCreated 1
#define JET_dbstateDirtyShutdown 2
#define JET_dbstateCleanShutdown 3
#define JET_dbstateBeingConverted 4
#define JET_dbstateForceDetach 5

typedef struct _JET_DBINFOMISC {
  unsigned long ulVersion;
  unsigned long ulUpdate;
  JET_SIGNATURE signDb;
  unsigned long dbstate;
  JET_LGPOS lgposConsistent;
  JET_LOGTIME logtimeConsistent;
  JET_LOGTIME logtimeAttach;
  JET_LGPOS lgposAttach;
  JET_LOGTIME logtimeDetach;
  JET_LGPOS lgposDetach;
  JET_SIGNATURE signLog;
  JET_BKINFO bkinfoFullPrev;
  JET_BKINFO bkinfoIncPrev;
  JET_BKINFO bkinfoFullCur;
  unsigned long fShadowingDisabled;
  unsigned long fUpgradeDb;
  unsigned long dwMajorVersion;
  unsigned long dwMinorVersion;
  unsigned long dwBuildNumber;
  long lSPNumber;
  unsigned long cbPageSize;
} JET_DBINFOMISC;

typedef struct _JET_DBINFOUPGRADE {
  unsigned long cbStruct;
  unsigned long cbFilesizeLow;
  unsigned long cbFilesizeHigh;
  unsigned long cbFreeSpaceRequiredLow;
  unsigned long  cbFreeSpaceRequiredHigh;
  unsigned long csecToUpgrade;
  __C89_NAMELESS union {
    unsigned long ulFlags;
    __C89_NAMELESS struct {
      unsigned long fUpgradable  :1;
      unsigned long fAlreadyUpgraded  :1;
    };
  };
} JET_DBINFOUPGRADE;

typedef struct _JET_ENUMCOLUMNVALUE {
  unsigned long itagSequence;
  JET_ERR err;
  unsigned long cbData;
  void* pvData;
} JET_ENUMCOLUMNVALUE;

typedef struct _JET_ENUMCOLUMN {
  JET_COLUMNID columnid;
  JET_ERR err;
  __C89_NAMELESS union {
    __C89_NAMELESS struct {
      unsigned long cEnumColumnValue;
      JET_ENUMCOLUMNVALUE rgEnumColumnValue;
    };
    __C89_NAMELESS struct {
      unsigned long cbData;
      void *pvData;
    };
  } DUMMYNIONNAME1;
} JET_ENUMCOLUMN;

typedef struct _JET_ENUMCOLUMNID {
  JET_COLUMNID columnid;
  unsigned long ctagSequence;
  unsigned long* rgtagSequence;
} JET_ENUMCOLUMNID;

typedef struct tagJET_INDEXCREATE_A {
  unsigned long cbStruct;
  char* szIndexName;
  char* szKey;
  unsigned long cbKey;
  JET_GRBIT grbit;
  unsigned long ulDensity;
  __C89_NAMELESS union {
    unsigned long lcid;
    JET_UNICODEINDEX* pidxunicode;
  };
  __C89_NAMELESS union {
    unsigned long cbVarSegMac;
    JET_TUPLELIMITS* ptuplelimits;
  };
  JET_CONDITIONALCOLUMN* rgconditionalcolumn;
  unsigned long cConditionalColumn;
  JET_ERR err;
  unsigned long cbKeyMost;
} JET_INDEXCREATE_A;

typedef struct tagJET_INDEXCREATE_W {
  unsigned long cbStruct;
  WCHAR* szIndexName;
  WCHAR* szKey;
  unsigned long cbKey;
  JET_GRBIT grbit;
  unsigned long ulDensity;
  __C89_NAMELESS union {
    unsigned long lcid;
    JET_UNICODEINDEX* pidxunicode;
  };
  __C89_NAMELESS union {
    unsigned long cbVarSegMac;
    JET_TUPLELIMITS* ptuplelimits;
  };
  JET_CONDITIONALCOLUMN* rgconditionalcolumn;
  unsigned long cConditionalColumn;
  JET_ERR err;
  unsigned long cbKeyMost;
} JET_INDEXCREATE_W;
#define JET_INDEXCREATE __MINGW_NAME_AW(JET_INDEXCREATE_)

typedef struct tagJET_INDEXID {
  unsigned long cbStruct;
  char rgbIndexId[];
} JET_INDEXID;

typedef struct _JET_INDEXLIST {
  unsigned long cbStruct;
  JET_TABLEID tableid;
  unsigned long cRecord;
  JET_COLUMNID columnidindexname;
  JET_COLUMNID columnidgrbitIndex;
  JET_COLUMNID columnidcKey;
  JET_COLUMNID columnidcEntry;
  JET_COLUMNID columnidcPage;
  JET_COLUMNID columnidcColumn;
  JET_COLUMNID columnidiColumn;
  JET_COLUMNID columnidcolumnid;
  JET_COLUMNID columnidcoltyp; 
  JET_COLUMNID columnidCountry;
  JET_COLUMNID columnidLangid;
  JET_COLUMNID columnidCp;
  JET_COLUMNID columnidCollate;
  JET_COLUMNID columnidgrbitColumn;
  JET_COLUMNID columnidcolumnname;
  JET_COLUMNID columnidLCMapFlags;
} JET_INDEXLIST;

typedef struct _JET_INDEXRANGE {
  unsigned long cbStruct; 
  JET_TABLEID tableid;
  JET_GRBIT grbit;
} JET_INDEXRANGE;

typedef struct _JET_INSTANCE_INFO_A {
  JET_INSTANCE hInstanceId;
  char* szInstanceName;
  JET_API_PTR cDatabases;
  char** szDatabaseFileName;
  char** szDatabaseDisplayName;
  char** szDatabaseSLVFileName;
} JET_INSTANCE_INFO_A;

typedef struct _JET_INSTANCE_INFO_W {
  JET_INSTANCE hInstanceId;
  WCHAR* szInstanceName;
  JET_API_PTR cDatabases;
  WCHAR** szDatabaseFileName;
  WCHAR** szDatabaseDisplayName;
  WCHAR** szDatabaseSLVFileName;
} JET_INSTANCE_INFO_W;

#define JET_INSTANCE_INFO __MINGW_NAME_AW(JET_INSTANCE_INFO_)

typedef struct _JET_LOGINFO_A {
  unsigned long cbSize;
  unsigned long ulGenLow;
  unsigned long ulGenHigh;
  char szBaseName[JET_BASE_NAME_LENGTH + 1];
} JET_LOGINFO_A;

typedef struct JET_LOGINFO_W {
  unsigned long cbSize;
  unsigned long ulGenLow;
  unsigned long ulGenHigh;
  WCHAR szBaseName[JET_BASE_NAME_LENGTH + 1];
} JET_LOGINFO_W;

#define JET_LOGINFO __MINGW_NAME_AW(JET_LOGINFO_)

typedef struct _JET_OBJECTINFO {
  unsigned long cbStruct;
  JET_OBJTYP objtyp;
  JET_DATESERIAL dtCreate;
  JET_DATESERIAL dtUpdate;
  JET_GRBIT grbit;
  unsigned long flags;
  unsigned long cRecord;
  unsigned long cPage;
} JET_OBJECTINFO;

typedef struct _JET_OBJECTLIST {
  unsigned long cbStruct;
  JET_TABLEID tableid;
  unsigned long cRecord;
  JET_COLUMNID columnidcontainername;
  JET_COLUMNID columnidobjectname;
  JET_COLUMNID columnidobjtyp;
  JET_COLUMNID columniddtCreate;
  JET_COLUMNID columniddtUpdate;
  JET_COLUMNID columnidgrbit;
  JET_COLUMNID columnidflags;
  JET_COLUMNID columnidcRecord;
  JET_COLUMNID columnidcPage;
} JET_OBJECTLIST;

#if (_WIN32_WINNT >= 0x0600)
typedef struct tagJET_OPENTEMPORARYTABLE {
  unsigned long cbStruct;
  const JET_COLUMNDEF* prgcolumndef;
  unsigned long ccolumn;
  JET_UNICODEINDEX* pidxunicode;
  JET_GRBIT grbit;
  JET_COLUMNID* prgcolumnid;
  unsigned long cbKeyMost;
  unsigned long cbVarSegMac;
  JET_TABLEID tableid;
} JET_OPENTEMPORARYTABLE;
#endif /*(_WIN32_WINNT >= 0x0600)*/

typedef struct _JET_RECORDLIST{
  unsigned long cbStruct;
  JET_TABLEID tableid;
  unsigned long cRecord;
  JET_COLUMNID columnidBookmark;
} JET_RECORDLIST;

typedef struct _JET_RECPOS {
  unsigned long cbStruct;
  unsigned long centriesLT;
  unsigned long centriesInRange;
  unsigned long centriesTotal;
} JET_RECPOS;

#if (_WIN32_WINNT >= 0x0600)
typedef struct _JET_RECSIZE {
  unsigned __int64 cbData;
  unsigned __int64 cbLongValueData;
  unsigned __int64 cbOverhead;
  unsigned __int64 cbLongValueOverhead;
  unsigned __int64 cNonTaggedColumns;
  unsigned __int64 cTaggedColumns;
  unsigned __int64 cLongValues;
  unsigned __int64 cMultiValues;
} JET_RECSIZE;
#endif /*(_WIN32_WINNT >= 0x0600)*/

typedef struct _JET_RETINFO {
  unsigned long cbStruct;
  unsigned long ibLongValue;
  unsigned long itagSequence;
  JET_COLUMNID columnidNextTagged;
} JET_RETINFO;

typedef struct _JET_RETRIEVECOLUMN {
  JET_COLUMNID columnid;
  void* pvData;  unsigned long cbData;
  unsigned long cbActual;
  JET_GRBIT grbit;
  unsigned long ibLongValue;
  unsigned long itagSequence;
  JET_COLUMNID columnidNextTagged;
  JET_ERR err;
} JET_RETRIEVECOLUMN;

#ifndef xRPC_STRING
#define xRPC_STRING
#endif

typedef struct _JET_RSTMAP_A{
  xRPC_STRING char* szDatabaseName;
  xRPC_STRING char* szNewDatabaseName;
} JET_RSTMAP_A;

typedef struct _JET_RSTMAP_W{
  xRPC_STRING WCHAR* szDatabaseName;
  xRPC_STRING WCHAR* szNewDatabaseName;
} JET_RSTMAP_W;

typedef JET_ERR (JET_API *JET_PFNSTATUS)(
  JET_SESID  sesid,
  JET_SNP snp,
  JET_SNT snt,
  void* pv
);

typedef struct _JET_RSTINFO_A{
  unsigned long cbStruct;
  JET_RSTMAP_A* rgrstmap;
  long crstmap;
  JET_LGPOS lgposStop;
  JET_LOGTIME logtimeStop;
  JET_PFNSTATUS pfnStatus;
} JET_RSTINFO_A;

typedef struct _JET_RSTINFO_W{
  unsigned long cbStruct;
  JET_RSTMAP_W* rgrstmap;
  long crstmap;
  JET_LGPOS lgposStop;
  JET_LOGTIME logtimeStop;
  JET_PFNSTATUS pfnStatus;
} JET_RSTINFO_W;

#define JET_RSTMAP __MINGW_NAME_AW(JET_RSTMAP_)
#define JET_RSTINFO __MINGW_NAME_AW(JET_RSTINFO_)

typedef struct _JET_SETCOLUMN {
  JET_COLUMNID columnid;
  const void* pvData;
  unsigned long cbData;
  JET_GRBIT grbit;
  unsigned long ibLongValue; 
  unsigned long itagSequence;
  JET_ERR err;
} JET_SETCOLUMN;

typedef struct _JET_SETINFO {
  unsigned long cbStruct;
  unsigned long ibLongValue;
  unsigned long itagSequence;
} JET_SETINFO;

typedef struct _JET_SETSYSPARAM_A {
  unsigned long paramid;
  JET_API_PTR lParam;
  const char* sz;
  JET_ERR err;
} JET_SETSYSPARAM_A;

typedef struct _JET_SETSYSPARAM_W {
  unsigned long paramid;
  JET_API_PTR lParam;
  const WCHAR* sz;
  JET_ERR err;
} JET_SETSYSPARAM_W;

#define JET_SETSYSPARAM __MINGW_NAME_AW(JET_SETSYSPARAM_)

typedef struct _JET_SNPROG {
  unsigned long cbStruct;
  unsigned long cunitDone;
  unsigned long cunitTotal;
} JET_SNPROG;

typedef struct tagJET_TABLECREATE_A {
  unsigned long cbStruct;
  char* szTableName;
  char* szTemplateTableName;
  unsigned long ulPages;
  unsigned long ulDensity;
  JET_COLUMNCREATE* rgcolumncreate;
  unsigned long cColumns;
  JET_INDEXCREATE_A* rgindexcreate;
  unsigned long cIndexes;
  JET_GRBIT grbit;
  JET_TABLEID tableid;
  unsigned long cCreated;
} JET_TABLECREATE_A;

typedef struct tagJET_TABLECREATE_W {
  unsigned long cbStruct;
  WCHAR* szTableName;
  WCHAR* szTemplateTableName;
  unsigned long ulPages;
  unsigned long ulDensity;
  JET_COLUMNCREATE* rgcolumncreate;
  unsigned long cColumns;
  JET_INDEXCREATE_W* rgindexcreate;
  unsigned long cIndexes;
  JET_GRBIT grbit;
  JET_TABLEID tableid;
  unsigned long cCreated;
} JET_TABLECREATE_W;

#define JET_TABLECREATE __MINGW_NAME_AW(JET_TABLECREATE_)

typedef struct tagJET_TABLECREATE2_A {
  unsigned long cbStruct;
  char* szTableName;
  char* szTemplateTableName;
  unsigned long ulPages;
  unsigned long ulDensity;
  JET_COLUMNCREATE_A* rgcolumncreate;
  unsigned long cColumns;
  JET_INDEXCREATE_A* rgindexcreate;
  unsigned long cIndexes;
  char* szCallback;
  JET_CBTYP cbtyp;
  JET_GRBIT grbit;
  JET_TABLEID tableid;
  unsigned long cCreated;
} JET_TABLECREATE2_A;

typedef struct tagJET_TABLECREATE2_W {
  unsigned long cbStruct;
  WCHAR* szTableName;
  WCHAR* szTemplateTableName;
  unsigned long ulPages;
  unsigned long ulDensity;
  JET_COLUMNCREATE_W* rgcolumncreate;
  unsigned long cColumns;
  JET_INDEXCREATE_W* rgindexcreate;
  unsigned long cIndexes;
  WCHAR* szCallback;
  JET_CBTYP cbtyp;
  JET_GRBIT grbit;
  JET_TABLEID tableid;
  unsigned long cCreated;
} JET_TABLECREATE2_W;

#define JET_TABLECREATE2 __MINGW_NAME_AW(JET_TABLECREATE2_)

#if (_WIN32_WINNT >= 0x0600)
typedef struct _JET_THREADSTATS {
  unsigned long cbStruct;
  unsigned long cPageReferenced;
  unsigned long cPageRead;
  unsigned long cPagePreread;
  unsigned long cPageDirtied;
  unsigned long cPageRedirtied;
  unsigned long cLogRecord;
  unsigned long cbLogRecord;
} JET_THREADSTATS;

#endif /*(_WIN32_WINNT >= 0x0600)*/

typedef struct tag_JET_USERDEFINEDDEFAULT_A {
  char* szCallback;
  unsigned char* pbUserData;
  unsigned long cbUserData;
  char* szDependantColumns;
} JET_USERDEFINEDDEFAULT_A;

typedef struct tag_JET_USERDEFINEDDEFAULT_W {
  WCHAR* szCallback;
  unsigned char* pbUserData;
  unsigned long cbUserData;
  WCHAR* szDependantColumns;
} JET_USERDEFINEDDEFAULT_W;

#define JET_USERDEFINEDDEFAULT __MINGW_NAME_AW(JET_USERDEFINEDDEFAULT_)

typedef JET_ERR (JET_API* JET_CALLBACK)(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_TABLEID tableid,
  JET_CBTYP cbtyp,
  void* pvArg1,
  void* pvArg2,
  void* pvContext,
  JET_API_PTR ulUnused
);

typedef void * (JET_API *JET_PFNREALLOC)(
  void* pvContext,
  void* pv,
  unsigned long cb
);

JET_ERR JET_API JetAddColumnA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szColumnName,
  const JET_COLUMNDEF* pcolumndef,
  const void* pvDefault,
  unsigned long cbDefault,
  JET_COLUMNID* pcolumnid
);

JET_ERR JET_API JetAddColumnW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szColumnName,
  const JET_COLUMNDEF* pcolumndef,
  const void* pvDefault,
  unsigned long cbDefault,
  JET_COLUMNID* pcolumnid
);

#define JetAddColumn __MINGW_NAME_AW(JetAddColumn)

JET_ERR JET_API JetAttachDatabaseA(
  JET_SESID sesid,
  const char* szFilename,
  JET_GRBIT grbit
);

JET_ERR JET_API JetAttachDatabaseW(
  JET_SESID sesid,
  const WCHAR* szFilename,
  JET_GRBIT grbit
);

#define JetAttachDatabase __MINGW_NAME_AW(JetAttachDatabase)

JET_ERR JET_API JetAttachDatabase2A(
  JET_SESID sesid,
  const char* szFilename,
  const unsigned long cpgDatabaseSizeMax,
  JET_GRBIT grbit
);

JET_ERR JET_API JetAttachDatabase2W(
  JET_SESID sesid,
  const WCHAR* szFilename,
  const unsigned long cpgDatabaseSizeMax,
  JET_GRBIT grbit
);

#define JetAttachDatabase2 __MINGW_NAME_AW(JetAttachDatabase2)

JET_ERR JET_API JetBackupA(
  JET_PCSTR szBackupPath,
  JET_GRBIT grbit,
  JET_PFNSTATUS pfnStatus
);

JET_ERR JET_API JetBackupW(
  JET_PCWSTR szBackupPath,
  JET_GRBIT grbit,
  JET_PFNSTATUS pfnStatus
);

#define JetBackup __MINGW_NAME_AW(JetBackup)

JET_ERR JET_API JetBackupInstanceA(
  JET_INSTANCE instance,
  JET_PCSTR szBackupPath,
  JET_GRBIT grbit,
  JET_PFNSTATUS pfnStatus
);

JET_ERR JET_API JetBackupInstanceW(
  JET_INSTANCE instance,
  JET_PCWSTR szBackupPath,
  JET_GRBIT grbit,
  JET_PFNSTATUS pfnStatus
);

#define JetBackupInstance __MINGW_NAME_AW(JetBackupInstance)

JET_ERR JET_API JetBeginExternalBackup(
  JET_GRBIT grbit
);

JET_ERR JET_API JetBeginExternalBackupInstance(
  JET_INSTANCE instance,
  JET_GRBIT grbit
);

JET_ERR JET_API JetBeginSessionA(
  JET_INSTANCE instance,
  JET_SESID* psesid,
  JET_PCSTR szUserName,
  JET_PCSTR szPassword
);

JET_ERR JET_API JetBeginSessionW(
  JET_INSTANCE instance,
  JET_SESID* psesid,
  JET_PCWSTR szUserName,
  JET_PCWSTR szPassword
);

JET_ERR JET_API JetBeginTransaction(
  JET_SESID sesid
);

JET_ERR JET_API JetBeginTransaction2(
  JET_SESID sesid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCloseDatabase(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCloseFile(
  JET_HANDLE hfFile
);

JET_ERR JET_API JetCloseFileInstance(
  JET_INSTANCE instance,
  JET_HANDLE hfFile
);

JET_ERR JET_API JetCloseTable(
  JET_SESID sesid,
  JET_TABLEID tableid
);

JET_ERR JET_API JetCommitTransaction(
  JET_SESID sesid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCompactA(
  JET_SESID sesid,
  JET_PCSTR szDatabaseSrc,
  JET_PCSTR szDatabaseDest,
  JET_PFNSTATUS pfnStatus,
  JET_CONVERT_A* pconvert,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCompactW(
  JET_SESID sesid,
  JET_PCWSTR szDatabaseSrc,
  JET_PCWSTR szDatabaseDest,
  JET_PFNSTATUS pfnStatus,
  JET_CONVERT_W* pconvert,
  JET_GRBIT grbit
);

#define JetCompact __MINGW_NAME_AW(JetCompact)

JET_ERR JET_API JetComputeStats(
  JET_SESID sesid,
  JET_TABLEID tableid
);

JET_ERR JET_API JetCreateDatabaseA(
  JET_SESID sesid,
  JET_PCSTR szFilename,
  JET_PCSTR szConnect,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCreateDatabaseW(
  JET_SESID sesid,
  JET_PCWSTR szFilename,
  JET_PCWSTR szConnect,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

#define JetCreateDatabase __MINGW_NAME_AW(JetCreateDatabase)

JET_ERR JET_API JetCreateDatabase2A(
  JET_SESID sesid,
  const char* szFilename,
  const unsigned long cpgDatabaseSizeMax,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCreateDatabase2W(
  JET_SESID sesid,
  const WCHAR* szFilename,
  const unsigned long cpgDatabaseSizeMax,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

#define JetCreateDatabase2 __MINGW_NAME_AW(JetCreateDatabase2)

JET_ERR JET_API JetCreateIndexA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName,
  JET_GRBIT grbit,
  const char* szKey,
  unsigned long cbKey,
  unsigned long lDensity
);

JET_ERR JET_API JetCreateIndexW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName,
  JET_GRBIT grbit,
  const WCHAR* szKey,
  unsigned long cbKey,
  unsigned long lDensity
);

#define JetCreateIndex __MINGW_NAME_AW(JetCreateIndex)

JET_ERR JET_API JetCreateIndex2A(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_INDEXCREATE_A* pindexcreate,
  unsigned long cIndexCreate
);

JET_ERR JET_API JetCreateIndex2W(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_INDEXCREATE_W* pindexcreate,
  unsigned long cIndexCreate
);

#define JetCreateIndex2 __MINGW_NAME_AW(JetCreateIndex2)

JET_ERR JET_API JetCreateInstanceA(
  JET_INSTANCE* pinstance,
  const char* szInstanceName
);

JET_ERR JET_API JetCreateInstanceW(
  JET_INSTANCE* pinstance,
  const WCHAR* szInstanceName
);

#define JetCreateInstance __MINGW_NAME_AW(JetCreateInstance)

JET_ERR JET_API JetCreateInstance2A(
  JET_INSTANCE* pinstance,
  const char* szInstanceName,
  const char* szDisplayName,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCreateInstance2W(
  JET_INSTANCE* pinstance,
  const WCHAR* szInstanceName,
  const WCHAR* szDisplayName,
  JET_GRBIT grbit
);

JET_ERR JET_API JetCreateTableA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szTableName,
  unsigned long lPages,
  unsigned long lDensity,
  JET_TABLEID* ptableid
);

JET_ERR JET_API JetCreateTableW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szTableName,
  unsigned long lPages,
  unsigned long lDensity,
  JET_TABLEID* ptableid
);

JET_ERR JET_API JetCreateTableColumnIndexA(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_TABLECREATE_A* ptablecreate
);

JET_ERR JET_API JetCreateTableColumnIndexW(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_TABLECREATE_W* ptablecreate
);

#define JetCreateInstance2 __MINGW_NAME_AW(JetCreateInstance2)

JET_ERR JET_API JetCreateTableColumnIndex2A(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_TABLECREATE2_A* ptablecreate
);

JET_ERR JET_API JetCreateTableColumnIndex2W(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_TABLECREATE2_W* ptablecreate
);

#define JetCreateTableColumnIndex2 __MINGW_NAME_AW(JetCreateTableColumnIndex2)

JET_ERR JET_API JetDefragmentA(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCSTR szTableName,
  unsigned long* pcPasses,
  unsigned long* pcSeconds,
  JET_GRBIT grbit
);

JET_ERR JET_API JetDefragmentW(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCWSTR szTableName,
  unsigned long* pcPasses,
  unsigned long* pcSeconds,
  JET_GRBIT grbit
);

#define JetDefragment __MINGW_NAME_AW(JetDefragment)

JET_ERR JET_API JetDefragment2A(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCSTR szTableName,
  unsigned long* pcPasses,
  unsigned long* pcSeconds,
  JET_CALLBACK callback,
  JET_GRBIT grbit
);

JET_ERR JET_API JetDefragment2W(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCWSTR szTableName,
  unsigned long* pcPasses,
  unsigned long* pcSeconds,
  JET_CALLBACK callback,
  JET_GRBIT grbit
);

#define JetDefragment2 __MINGW_NAME_AW(JetDefragment2)

JET_ERR JET_API JetDelete(
  JET_SESID sesid,
  JET_TABLEID tableid
);

JET_ERR JET_API JetDeleteColumnA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const char* szColumnName
);

JET_ERR JET_API JetDeleteColumnW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const WCHAR* szColumnName
);

#define JetDeleteColumn __MINGW_NAME_AW(JetDeleteColumn)

JET_ERR JET_API JetDeleteColumn2A(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const char* szColumnName,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetDeleteColumn2W(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const WCHAR* szColumnName,
  const JET_GRBIT grbit
);

#define JetDeleteColumn2 __MINGW_NAME_AW(JetDeleteColumn2)

JET_ERR JET_API JetDeleteIndexA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName
);

JET_ERR JET_API JetDeleteIndexW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName
);

#define JetDeleteColumn2 __MINGW_NAME_AW(JetDeleteColumn2)

JET_ERR JET_API JetDeleteIndexA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName
);

JET_ERR JET_API JetDeleteIndexW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName
);

#define JetDeleteIndex __MINGW_NAME_AW(JetDeleteIndex)

JET_ERR JET_API JetDeleteTableA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szTableName
);

JET_ERR JET_API JetDeleteTableW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szTableName
);

#define JetDeleteTable __MINGW_NAME_AW(JetDeleteTable)

JET_ERR JET_API JetDetachDatabaseA(
  JET_SESID sesid,
  const char* szFilename
);

JET_ERR JET_API JetDetachDatabaseW(
  JET_SESID sesid,
  const char* szFilename
);

#define JetDetachDatabase __MINGW_NAME_AW(JetDetachDatabase)

JET_ERR JET_API JetDetachDatabase2A(
  JET_SESID sesid,
  const char* szFilename,
  JET_GRBIT grbit
);

JET_ERR JET_API JetDetachDatabase2W(
  JET_SESID sesid,
  const WCHAR* szFilename,
  JET_GRBIT grbit
);

#define JetDetachDatabase2 __MINGW_NAME_AW(JetDetachDatabase2)

JET_ERR JET_API JetDupCursor(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_TABLEID* ptableid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetDupSession(
  JET_SESID sesid,
  JET_SESID* psesid
);

JET_ERR JET_API JetEnableMultiInstanceA(
  JET_SETSYSPARAM_A* psetsysparam,
  unsigned long csetsysparam,
  unsigned long* pcsetsucceed
);

JET_ERR JET_API JetEnableMultiInstanceW(
  JET_SETSYSPARAM_W* psetsysparam,
  unsigned long csetsysparam,
  unsigned long* pcsetsucceed
);

#define JetEnableMultiInstance __MINGW_NAME_AW(JetEnableMultiInstance)

JET_ERR JET_API JetEndExternalBackup(void);

JET_ERR JET_API JetEndExternalBackupInstance(
  JET_INSTANCE instance
);

JET_ERR JET_API JetEndExternalBackupInstance2(
  JET_INSTANCE instance,
  JET_GRBIT grbit
);

JET_ERR JET_API JetEndSession(
  JET_SESID sesid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetEnumerateColumns(
  JET_SESID sesid,
  JET_TABLEID tableid,
  unsigned long cEnumColumnId,
  JET_ENUMCOLUMNID* rgEnumColumnId,
  unsigned long* pcEnumColumn,
  JET_ENUMCOLUMN** prgEnumColumn,
  JET_PFNREALLOC pfnRealloc,
  void* pvReallocContext,
  unsigned long cbDataMost,
  JET_GRBIT grbit
);

JET_ERR JET_API JetEscrowUpdate(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_COLUMNID columnid,
  void* pv,
  unsigned long cbMax,
  void* pvOld,
  unsigned long cbOldMax,
  unsigned long* pcbOldActual,
  JET_GRBIT grbit
);

JET_ERR JET_API JetExternalRestoreA(
  JET_PSTR szCheckpointFilePath,
  JET_PSTR szLogPath,
  JET_RSTMAP_A* rgrstmap,
  long crstfilemap,
  JET_PSTR szBackupLogPath,
  long genLow,
  long genHigh,
  JET_PFNSTATUS pfn
);

JET_ERR JET_API JetExternalRestoreW(
  JET_PWSTR szCheckpointFilePath,
  JET_PWSTR szLogPath,
  JET_RSTMAP_W* rgrstmap,
  long crstfilemap,
  JET_PWSTR szBackupLogPath,
  long genLow,
  long genHigh,
  JET_PFNSTATUS pfn
);

#define JetExternalRestore __MINGW_NAME_AW(JetExternalRestore)

JET_ERR JET_API JetExternalRestore2A(
  JET_PSTR szCheckpointFilePath,
  JET_PSTR szLogPath,
  JET_RSTMAP_A* rgrstmap,
  long crstfilemap,
  JET_PSTR szBackupLogPath,
  JET_LOGINFO_A* pLogInfo,
  JET_PSTR szTargetInstanceName,
  JET_PSTR szTargetInstanceLogPath,
  JET_PSTR szTargetInstanceCheckpointPath,
  JET_PFNSTATUS pfn
);

JET_ERR JET_API JetExternalRestore2W(
  JET_PWSTR szCheckpointFilePath,
  JET_PWSTR szLogPath,
  JET_RSTMAP_W* rgrstmap,
  long crstfilemap,
  JET_PWSTR szBackupLogPath,
  JET_LOGINFO_W* pLogInfo,
  JET_PWSTR szTargetInstanceName,
  JET_PWSTR szTargetInstanceLogPath,
  JET_PWSTR szTargetInstanceCheckpointPath,
  JET_PFNSTATUS pfn
);

#define JetExternalRestore2 __MINGW_NAME_AW(JetExternalRestore2)

JET_ERR JET_API JetFreeBuffer(
  char* pbBuf
);

JET_ERR JET_API JetGetAttachInfoA(
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetAttachInfoW(
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

#define JetGetAttachInfo __MINGW_NAME_AW(JetGetAttachInfo)

JET_ERR JET_API JetGetAttachInfoInstanceA(
  JET_INSTANCE instance,
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetAttachInfoInstanceW(
  JET_INSTANCE instance,
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

#define JetGetAttachInfoInstance __MINGW_NAME_AW(JetGetAttachInfoInstance)

JET_ERR JET_API JetGetBookmark(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvBookmark,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetColumnInfoA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szTableName,
  const char* szColumnName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetColumnInfoW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szTableName,
  const WCHAR* szColumnName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetColumnInfo __MINGW_NAME_AW(JetGetColumnInfo)

JET_ERR JET_API JetGetCurrentIndexA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PSTR szIndexName,
  unsigned long cchIndexName
);

JET_ERR JET_API JetGetCurrentIndexW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PWSTR szIndexName,
  unsigned long cchIndexName
);

#define JetGetCurrentIndex __MINGW_NAME_AW(JetGetCurrentIndex)

JET_ERR JET_API JetGetCursorInfo(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetDatabaseFileInfoA(
  const char* szDatabaseName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetDatabaseFileInfoW(
  const WCHAR* szDatabaseName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetDatabaseFileInfo __MINGW_NAME_AW(JetGetDatabaseFileInfo)

JET_ERR JET_API JetGetDatabaseInfoA(
  JET_SESID sesid,
  JET_DBID dbid,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetDatabaseInfoW(
  JET_SESID sesid,
  JET_DBID dbid,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetDatabaseInfo __MINGW_NAME_AW(JetGetDatabaseInfo)

JET_ERR JET_API JetGetIndexInfoA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szTableName,
  const char* szIndexName,
  void* pvResult,
  unsigned long cbResult,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetIndexInfoW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szTableName,
  const WCHAR* szIndexName,
  void* pvResult,
  unsigned long cbResult,
  unsigned long InfoLevel
);

#define JetGetIndexInfo __MINGW_NAME_AW(JetGetIndexInfo)

JET_ERR JET_API JetGetInstanceInfoA(
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_A** paInstanceInfo
);

JET_ERR JET_API JetGetInstanceInfoW(
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_W** paInstanceInfo
);

#define JetGetInstanceInfo __MINGW_NAME_AW(JetGetInstanceInfo)

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetGetInstanceMiscInfo(
  JET_INSTANCE instance,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetGetLock(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetGetLogInfoA(
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetLogInfoW(
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

#define JetGetLogInfo __MINGW_NAME_AW(JetGetLogInfo)

JET_ERR JET_API JetGetLogInfoInstanceA(
  JET_INSTANCE instance,
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetLogInfoInstanceW(
  JET_INSTANCE instance,
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

#define JetGetLogInfoInstance __MINGW_NAME_AW(JetGetLogInfoInstance)

JET_ERR JET_API JetGetLogInfoInstance2A(
  JET_INSTANCE instance,
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual,
  JET_LOGINFO_A* pLogInfo
);

JET_ERR JET_API JetGetLogInfoInstance2W(
  JET_INSTANCE instance,
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual,
  JET_LOGINFO_W* pLogInfo
);

#define JetGetLogInfoInstance2 __MINGW_NAME_AW(JetGetLogInfoInstance2)

JET_ERR JET_API JetGetLS(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_LS* pls,
  JET_GRBIT grbit
);

JET_ERR JET_API JetGetObjectInfoA(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_OBJTYP objtyp,
  const char* szContainerName,
  const char* szObjectName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetObjectInfoW(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_OBJTYP objtyp,
  const WCHAR* szContainerName,
  const WCHAR* szObjectName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetObjectInfo __MINGW_NAME_AW(JetGetObjectInfo)

JET_ERR JET_API JetGetRecordPosition(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_RECPOS* precpos,
  unsigned long cbRecpos
);

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetGetRecordSize(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_RECSIZE* precsize,
  const JET_GRBIT grbit
);
#endif /* (_WIN32_WINNT >= 0x0600) */

JET_ERR JET_API JetGetSecondaryIndexBookmark(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvSecondaryKey,
  unsigned long cbSecondaryKeyMax,
  unsigned long* pcbSecondaryKeyActual,
  void* pvPrimaryBookmark,
  unsigned long cbPrimaryBookmarkMax,
  unsigned long* pcbPrimaryKeyActual,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetGetSystemParameterA(
  JET_INSTANCE instance,
  JET_SESID sesid,
  unsigned long paramid,
  JET_API_PTR* plParam,
  JET_PSTR szParam,
  unsigned long cbMax
);

JET_ERR JET_API JetGetSystemParameterW(
  JET_INSTANCE instance,
  JET_SESID sesid,
  unsigned long paramid,
  JET_API_PTR* plParam,
  JET_PWSTR szParam,
  unsigned long cbMax
);

#define JetGetSystemParameter __MINGW_NAME_AW(JetGetSystemParameter)

JET_ERR JET_API JetGetTableColumnInfoA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const char* szColumnName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetTableColumnInfoW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const WCHAR* szColumnName,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetTableColumnInfoW __MINGW_NAME_AW(JetGetTableColumnInfo)

JET_ERR JET_API JetGetTableIndexInfoA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const char* szIndexName,
  void* pvResult,
  unsigned long cbResult,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetTableIndexInfoW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const WCHAR* szIndexName,
  void* pvResult,
  unsigned long cbResult,
  unsigned long InfoLevel
);

#define JetGetTableIndexInfo __MINGW_NAME_AW(JetGetTableIndexInfo)

JET_ERR JET_API JetGetTableInfoA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

JET_ERR JET_API JetGetTableInfoW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvResult,
  unsigned long cbMax,
  unsigned long InfoLevel
);

#define JetGetTableInfo __MINGW_NAME_AW(JetGetTableInfo)

JET_ERR JET_API JetGetThreadStats(
  void* pvResult,
  unsigned long cbMax
);

JET_ERR JET_API JetGetTruncateLogInfoInstanceA(
  JET_INSTANCE instance,
  char* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetTruncateLogInfoInstanceW(
  JET_INSTANCE instance,
  WCHAR* szz,
  unsigned long cbMax,
  unsigned long* pcbActual
);

JET_ERR JET_API JetGetVersion(
  JET_SESID sesid,
  unsigned long* pwVersion
);

JET_ERR JET_API JetGotoBookmark(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvBookmark,
  unsigned long cbBookmark
);

JET_ERR JET_API JetGotoPosition(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_RECPOS* precpos
);

JET_ERR JET_API JetGotoSecondaryIndexBookmark(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvSecondaryKey,
  unsigned long cbSecondaryKey,
  void* pvPrimaryBookmark,
  unsigned long cbPrimaryBookmark,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetGrowDatabase(
  JET_SESID sesid,
  JET_DBID dbid,
  unsigned long cpg,
  unsigned long* pcpgReal
);

JET_ERR JET_API JetIdle(
  JET_SESID sesid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetIndexRecordCount(
  JET_SESID sesid,
  JET_TABLEID tableid,
  unsigned long* pcrec,
  unsigned long crecMax
);

JET_ERR JET_API JetInit(
  JET_INSTANCE* pinstance
);

JET_ERR JET_API JetInit2(
  JET_INSTANCE* pinstance,
  JET_GRBIT grbit
);

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetInit3A(
  JET_INSTANCE* pinstance,
  JET_RSTINFO_A* prstInfo,
  JET_GRBIT grbit
);

JET_ERR JET_API JetInit3W(
  JET_INSTANCE* pinstance,
  JET_RSTINFO_W* prstInfo,
  JET_GRBIT grbit
);

#define JetInit3 __MINGW_NAME_AW(JetInit3)
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetIntersectIndexes(
  JET_SESID sesid,
  JET_INDEXRANGE* rgindexrange,
  unsigned long cindexrange,
  JET_RECORDLIST* precordlist,
  JET_GRBIT grbit
);

JET_ERR JET_API JetMakeKey(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const void* pvData,
  unsigned long cbData,
  JET_GRBIT grbit
);

JET_ERR JET_API JetMove(
  JET_SESID sesid,
  JET_TABLEID tableid,
  long cRow,
  JET_GRBIT grbit
);

JET_ERR JET_API JetOpenDatabaseA(
  JET_SESID sesid,
  const char* szFilename,
  const char* szConnect,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetOpenDatabaseW(
  JET_SESID sesid,
  const WCHAR* szFilename,
  const WCHAR* szConnect,
  JET_DBID* pdbid,
  JET_GRBIT grbit
);

#define JetOpenDatabase __MINGW_NAME_AW(JetOpenDatabase)

JET_ERR JET_API JetOpenFileA(
  const char* szFileName,
  JET_HANDLE* phfFile,
  unsigned long* pulFileSizeLow,
  unsigned long* pulFileSizeHigh
);

JET_ERR JET_API JetOpenFileW(
  const WCHAR* szFileName,
  JET_HANDLE* phfFile,
  unsigned long* pulFileSizeLow,
  unsigned long* pulFileSizeHigh
);

#define JetOpenFile __MINGW_NAME_AW(JetOpenFile)

JET_ERR JET_API JetOpenFileInstanceA(
  JET_INSTANCE instance,
  JET_PCSTR szFileName,
  JET_HANDLE* phfFile,
  unsigned long* pulFileSizeLow,
  unsigned long* pulFileSizeHigh
);

JET_ERR JET_API JetOpenFileInstanceW(
  JET_INSTANCE instance,
  JET_PCWSTR szFileName,
  JET_HANDLE* phfFile,
  unsigned long* pulFileSizeLow,
  unsigned long* pulFileSizeHigh
);

#define JetOpenFileInstance __MINGW_NAME_AW(JetOpenFileInstance)

JET_ERR JET_API JetOpenTableA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szTableName,
  const void* pvParameters,
  unsigned long cbParameters,
  JET_GRBIT grbit,
  JET_TABLEID* ptableid
);

JET_ERR JET_API JetOpenTableW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szTableName,
  const void* pvParameters,
  unsigned long cbParameters,
  JET_GRBIT grbit,
  JET_TABLEID* ptableid
);

#define JetOpenTable __MINGW_NAME_AW(JetOpenTable)

JET_ERR JET_API JetOpenTemporaryTable(
  JET_SESID sesid,
  JET_OPENTEMPORARYTABLE* popentemporarytable
);

JET_ERR JET_API JetOpenTempTable(
  JET_SESID sesid,
  const JET_COLUMNDEF* prgcolumndef,
  unsigned long ccolumn,
  JET_GRBIT grbit,
  JET_TABLEID* ptableid,
  JET_COLUMNID* prgcolumnid
);

JET_ERR JET_API JetOpenTempTable2(
  JET_SESID sesid,
  const JET_COLUMNDEF* prgcolumndef,
  unsigned long ccolumn,
  unsigned long lcid,
  JET_GRBIT grbit,
  JET_TABLEID* ptableid,
  JET_COLUMNID* prgcolumnid
);

JET_ERR JET_API JetOpenTempTable3(
  JET_SESID sesid,
  const JET_COLUMNDEF* prgcolumndef,
  unsigned long ccolumn,
  JET_UNICODEINDEX* pidxunicode,
  JET_GRBIT grbit,
  JET_TABLEID* ptableid,
  JET_COLUMNID* prgcolumnid
);

JET_ERR JET_API JetOSSnapshotAbort(
  const JET_OSSNAPID snapId,
  const JET_GRBIT grbit
);

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetOSSnapshotEnd(
  const JET_OSSNAPID snapId,
  const JET_GRBIT grbit
);
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetOSSnapshotFreezeA(
  const JET_OSSNAPID snapId,
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_A** paInstanceInfo,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetOSSnapshotFreezeW(
  const JET_OSSNAPID snapId,
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_W** paInstanceInfo,
  const JET_GRBIT grbit
);

#define JetOSSnapshotFreeze __MINGW_NAME_AW(JetOSSnapshotFreeze)

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetOSSnapshotGetFreezeInfoA(
  const JET_OSSNAPID snapId,
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_A** paInstanceInfo,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetOSSnapshotGetFreezeInfoW(
  const JET_OSSNAPID snapId,
  unsigned long* pcInstanceInfo,
  JET_INSTANCE_INFO_W** paInstanceInfo,
  const JET_GRBIT grbit
);
#define JetOSSnapshotGetFreezeInfo __MINGW_NAME_AW(JetOSSnapshotGetFreezeInfo)
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetOSSnapshotPrepare(
  JET_OSSNAPID* psnapId,
  const JET_GRBIT grbit
);

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetOSSnapshotPrepareInstance(
  JET_OSSNAPID snapId,
  JET_INSTANCE instance,
  const JET_GRBIT grbit
);
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetOSSnapshotThaw(
  const JET_OSSNAPID snapId,
  const JET_GRBIT grbit
);

#if (_WIN32_WINNT >= 0x0600)
JET_ERR JET_API JetOSSnapshotTruncateLog(
  const JET_OSSNAPID snapId,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetOSSnapshotTruncateLogInstance(
  const JET_OSSNAPID snapId,
  JET_INSTANCE instance,
  const JET_GRBIT grbit
);
#endif /*(_WIN32_WINNT >= 0x0600)*/

JET_ERR JET_API JetPrepareUpdate(
  JET_SESID sesid,
  JET_TABLEID tableid,
  unsigned long prep
);

JET_ERR JET_API JetReadFile(
  JET_HANDLE hfFile,
  void* pv,
  unsigned long cb,
  unsigned long* pcbActual
);

JET_ERR JET_API JetReadFileInstance(
  JET_INSTANCE instance,
  JET_HANDLE hfFile,
  void* pv,
  unsigned long cb,
  unsigned long* pcb
);

JET_ERR JET_API JetRegisterCallback(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_CBTYP cbtyp,
  JET_CALLBACK pCallback,
  void* pvContext,
  JET_HANDLE* phCallbackId
);

JET_ERR JET_API JetRenameColumnA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szName,
  JET_PCSTR szNameNew,
  JET_GRBIT grbit
);

JET_ERR JET_API JetRenameColumnW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szName,
  JET_PCWSTR szNameNew,
  JET_GRBIT grbit
);

JET_ERR JET_API JetRenameTableA(
  JET_SESID sesid,
  JET_DBID dbid,
  const char* szName,
  const char* szNameNew
);

JET_ERR JET_API JetRenameTableW(
  JET_SESID sesid,
  JET_DBID dbid,
  const WCHAR* szName,
  const WCHAR* szNameNew
);

JET_ERR JET_API JetResetSessionContext(
  JET_SESID sesid
);

JET_ERR JET_API JetResetTableSequential(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetRestoreA(
  JET_PCSTR sz,
  JET_PFNSTATUS pfn
);

JET_ERR JET_API JetRestoreW(
  JET_PCWSTR sz,
  JET_PFNSTATUS pfn
);

#define JetRestore __MINGW_NAME_AW(JetRestore)

JET_ERR JET_API JetRestore2A(
  JET_PCSTR sz,
  JET_PCSTR szDest,
  JET_PFNSTATUS pfn
);

JET_ERR JET_API JetRestore2W(
  JET_PCWSTR sz,
  JET_PCWSTR szDest,
  JET_PFNSTATUS pfn
);

#define JetRestore2 __MINGW_NAME_AW(JetRestore2)

JET_ERR JET_API JetRestoreInstanceA(
  JET_INSTANCE instance,
  JET_PCSTR sz,
  JET_PCSTR szDest,
  JET_PFNSTATUS pfn
);

JET_ERR JET_API JetRestoreInstanceW(
  JET_INSTANCE instance,
  JET_PCWSTR sz,
  JET_PCWSTR szDest,
  JET_PFNSTATUS pfn
);

#define JetRestoreInstance __MINGW_NAME_AW(JetRestoreInstance)

JET_ERR JET_API JetRetrieveColumn(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_COLUMNID columnid,
  void* pvData,
  unsigned long cbData,
  unsigned long* pcbActual,
  JET_GRBIT grbit,
  JET_RETINFO* pretinfo
);

JET_ERR JET_API JetRetrieveColumns(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_RETRIEVECOLUMN* pretrievecolumn,
  unsigned long cretrievecolumn
);

JET_ERR JET_API JetRetrieveKey(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvData,
  unsigned long cbMax,
  unsigned long* pcbActual,
  JET_GRBIT grbit
);

JET_ERR JET_API JetRollback(
  JET_SESID sesid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetSeek(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetSetColumn(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_COLUMNID columnid,
  const void* pvData,
  unsigned long cbData,
  JET_GRBIT grbit,
  JET_SETINFO* psetinfo
);

JET_ERR JET_API JetSetColumnDefaultValueA(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCSTR szTableName,
  JET_PCSTR szColumnName,
  const void* pvData,
  const unsigned long cbData,
  const JET_GRBIT grbit
);

JET_ERR JET_API JetSetColumnDefaultValueW(
  JET_SESID sesid,
  JET_DBID dbid,
  JET_PCWSTR szTableName,
  JET_PCWSTR szColumnName,
  const void* pvData,
  const unsigned long cbData,
  const JET_GRBIT grbit
);

#define JetSetColumnDefaultValue __MINGW_NAME_AW(JetSetColumnDefaultValue)

JET_ERR JET_API JetSetColumns(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_SETCOLUMN* psetcolumn,
  unsigned long csetcolumn
);

JET_ERR JET_API JetSetCurrentIndexA(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const char* szIndexName
);

JET_ERR JET_API JetSetCurrentIndexW(
  JET_SESID sesid,
  JET_TABLEID tableid,
  const WCHAR* szIndexName
);

#define JetSetColumnDefaultValue __MINGW_NAME_AW(JetSetColumnDefaultValue)

JET_ERR JET_API JetSetCurrentIndex2A(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName,
  JET_GRBIT grbit
);

JET_ERR JET_API JetSetCurrentIndex2W(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName,
  JET_GRBIT grbit
);

#define JetSetColumnDefaultValue2 __MINGW_NAME_AW(JetSetColumnDefaultValue2)

JET_ERR JET_API JetSetCurrentIndex3A(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName,
  JET_GRBIT grbit,
  unsigned long itagSequence
);

JET_ERR JET_API JetSetCurrentIndex3W(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName,
  JET_GRBIT grbit,
  unsigned long itagSequence
);

#define JetSetColumnDefaultValue3 __MINGW_NAME_AW(JetSetColumnDefaultValue3)

JET_ERR JET_API JetSetCurrentIndex4A(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCSTR szIndexName,
  JET_INDEXID* pindexid,
  JET_GRBIT grbit,
  unsigned long itagSequence
);

JET_ERR JET_API JetSetCurrentIndex4W(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_PCWSTR szIndexName,
  JET_INDEXID* pindexid,
  JET_GRBIT grbit,
  unsigned long itagSequence
);

#define JetSetCurrentIndex4 __MINGW_NAME_AW(JetSetCurrentIndex4)

JET_ERR JET_API JetSetDatabaseSizeA(
  JET_SESID sesid,
  JET_PCSTR szDatabaseName,
  unsigned long cpg,
  unsigned long* pcpgReal
);

JET_ERR JET_API JetSetDatabaseSizeW(
  JET_SESID sesid,
  JET_PCWSTR szDatabaseName,
  unsigned long cpg,
  unsigned long* pcpgReal
);

#define JetSetDatabaseSize __MINGW_NAME_AW(JetSetDatabaseSize)

JET_ERR JET_API JetSetIndexRange(
  JET_SESID sesid,
  JET_TABLEID tableidSrc,
  JET_GRBIT grbit
);

JET_ERR JET_API JetSetLS(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_LS ls,
  JET_GRBIT grbit
);

JET_ERR JET_API JetSetSessionContext(
  JET_SESID sesid,
  JET_API_PTR ulContext
);

JET_ERR JET_API JetSetSystemParameterA(
  JET_INSTANCE* pinstance,
  JET_SESID sesid,
  unsigned long paramid,
  JET_API_PTR lParam,
  JET_PCSTR szParam
);

JET_ERR JET_API JetSetSystemParameterW(
  JET_INSTANCE* pinstance,
  JET_SESID sesid,
  unsigned long paramid,
  JET_API_PTR lParam,
  JET_PCWSTR szParam
);

#define JetSetSystemParameter __MINGW_NAME_AW(JetSetSystemParameter)

JET_ERR JET_API JetSetTableSequential(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_GRBIT grbit
);

JET_ERR JET_API JetStopBackup(void);

JET_ERR JET_API JetStopBackupInstance(
  JET_INSTANCE instance
);

JET_ERR JET_API JetStopService(void);

JET_ERR JET_API JetStopServiceInstance(
  JET_INSTANCE instance
);

JET_ERR JET_API JetTerm(
  JET_INSTANCE instance
);

JET_ERR JET_API JetTerm2(
  JET_INSTANCE instance,
  JET_GRBIT grbit
);

JET_ERR JET_API JetTruncateLog(void);

JET_ERR JET_API JetTruncateLogInstance(
  JET_INSTANCE instance
);

JET_ERR JET_API JetUnregisterCallback(
  JET_SESID sesid,
  JET_TABLEID tableid,
  JET_CBTYP cbtyp,
  JET_HANDLE hCallbackId
);

JET_ERR JET_API JetUpdate(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvBookmark,
  unsigned long cbBookmark,
  unsigned long* pcbActual
);

JET_ERR JET_API JetUpdate2(
  JET_SESID sesid,
  JET_TABLEID tableid,
  void* pvBookmark,
  unsigned long cbBookmark,
  unsigned long* pcbActual,
  const JET_GRBIT grbit
);

#ifdef __cplusplus
}
#endif
#endif /*_INC_ESENT*/
