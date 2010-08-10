/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_FILEEXTD
#define _INC_FILEEXTD

#if (_WIN32_WINNT < 0x0600) /*XP & 2003*/

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _FILE_ALLOCATION_INFO {
  LARGE_INTEGER AllocationSize;
} FILE_ALLOCATION_INFO, *PFILE_ALLOCATION_INFO;

typedef struct _FILE_ATTRIBUTE_TAG_INFO {
  DWORD FileAttributes;
  DWORD ReparseTag;
} FILE_ATTRIBUTE_TAG_INFO, *PFILE_ATTRIBUTE_TAG_INFO;

typedef struct _FILE_BASIC_INFO {
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  DWORD         FileAttributes;
} FILE_BASIC_INFO, *PFILE_BASIC_INFO;

typedef struct _FILE_COMPRESSION_INFO {
  LARGE_INTEGER CompressedFileSize;
  WORD          CompressionFormat;
  UCHAR         CompressionUnitShift;
  UCHAR         ChunkShift;
  UCHAR         ClusterShift;
  UCHAR         Reserved[3];
} FILE_COMPRESSION_INFO, *PFILE_COMPRESSION_INFO;

typedef struct _FILE_DISPOSITION_INFO {
  WINBOOL DeleteFile;
} FILE_DISPOSITION_INFO, *PFILE_DISPOSITION_INFO;

typedef struct _FILE_END_OF_FILE_INFO {
  LARGE_INTEGER EndOfFile;
} FILE_END_OF_FILE_INFO, *PFILE_END_OF_FILE_INFO;

typedef struct _FILE_ID_BOTH_DIR_INFO {
  DWORD         NextEntryOffset;
  DWORD         FileIndex;
  LARGE_INTEGER CreationTime;
  LARGE_INTEGER LastAccessTime;
  LARGE_INTEGER LastWriteTime;
  LARGE_INTEGER ChangeTime;
  LARGE_INTEGER EndOfFile;
  LARGE_INTEGER AllocationSize;
  DWORD         FileAttributes;
  DWORD         FileNameLength;
  DWORD         EaSize;
  CCHAR         ShortNameLength;
  WCHAR         ShortName[12];
  LARGE_INTEGER FileId;
  WCHAR         FileName[1];
} FILE_ID_BOTH_DIR_INFO, *PFILE_ID_BOTH_DIR_INFO;

typedef struct _FILE_ID_DESCRIPTOR{
  DWORD        dwSize;
  FILE_ID_TYPE Type;
  __MINGW_EXTENSION union {
    LARGE_INTEGER FileId;
    GUID          ObjectId;
  };
} FILE_ID_DESCRIPTOR, *LPFILE_ID_DESCRIPTOR;

typedef enum _FILE_ID_TYPE {
  FileIdType,
  ObjectIdType,
  MaximumFileIdType
} FILE_ID_TYPE, *PFILE_ID_TYPE;

typedef enum _FILE_INFO_BY_HANDLE_CLASS {
  FileBasicInfo                    = 0,
  FileStandardInfo                 = 1,
  FileNameInfo                     = 2,
  FileRenameInfo                   = 3,
  FileDispositionInfo              = 4,
  FileAllocationInfo               = 5,
  FileEndOfFileInfo                = 6,
  FileStreamInfo                   = 7,
  FileCompressionInfo              = 8,
  FileAttributeTagInfo             = 9,
  FileIdBothDirectoryInfo          = 10,  // 0xA
  FileIdBothDirectoryRestartInfo   = 11,  // 0xB
  FileIoPriorityHintInfo           = 12,  // 0xC
  FileRemoteProtocolInfo           = 13,  // 0xD
  MaximumFileInfoByHandlesClass    = 14   // 0xE
} FILE_INFO_BY_HANDLE_CLASS, *PFILE_INFO_BY_HANDLE_CLASS;

typedef struct _FILE_NAME_INFO {
  DWORD FileNameLength;
  WCHAR FileName[1];
} FILE_NAME_INFO, *PFILE_NAME_INFO;

typedef struct _FILE_RENAME_INFO {
  BOOL   ReplaceIfExists;
  HANDLE RootDirectory;
  DWORD  FileNameLength;
  WCHAR  FileName[1];
} FILE_RENAME_INFO, *PFILE_RENAME_INFO;

typedef struct _FILE_STANDARD_INFO {
  LARGE_INTEGER AllocationSize;
  LARGE_INTEGER EndOfFile;
  DWORD          NumberOfLinks;
  WINBOOL        DeletePending;
  WINBOOL        Directory;
} FILE_STANDARD_INFO, *PFILE_STANDARD_INFO;

typedef struct _FILE_STREAM_INFO {
  DWORD         NextEntryOffset;
  DWORD         StreamNameLength;
  LARGE_INTEGER StreamSize;
  LARGE_INTEGER StreamAllocationSize;
  WCHAR         StreamName[1];
} FILE_STREAM_INFO, *PFILE_STREAM_INFO;

WINBASEAPI WINBOOL WINAPI GetFileInformationByHandleEx(
  HANDLE hFile,
  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
  LPVOID lpFileInformation,
  DWORD dwBufferSize
);

WINBASEAPI HANDLE WINAPI OpenFileById(
  HANDLE hFile,
  LPFILE_ID_DESCRIPTOR lpFileID,
  DWORD dwDesiredAccess,
  DWORD dwShareMode,
  LPSECURITY_ATTRIBUTES lpSecurityAttributes,
  DWORD dwFlags
);

WINBOOL WINAPI SetFileInformationByHandle(
  HANDLE hFile,
  FILE_INFO_BY_HANDLE_CLASS FileInformationClass,
  LPVOID lpFileInformation,
  DWORD dwBufferSize
);

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT < 0x0600)*/

#endif /*_INC_FILEEXTD*/
