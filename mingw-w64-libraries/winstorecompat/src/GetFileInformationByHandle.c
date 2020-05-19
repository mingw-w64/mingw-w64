/*
    Copyright (c) 2020 mingw-w64 project

    Contributing authors: Steve Lhomme

    Permission is hereby granted, free of charge, to any person obtaining a
    copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
    DEALINGS IN THE SOFTWARE.
*/

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x602 /* FILE_ID_INFO is available since win8 */
#endif

#define GetFileInformationByHandle __GetFileInformationByHandle
#include <windef.h>
#include <winbase.h>
#undef GetFileInformationByHandle

WINBOOL WINAPI GetFileInformationByHandle(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpInfo)
{
    FILE_ID_INFO id_info;
    FILE_STANDARD_INFO standard_info;
    FILE_BASIC_INFO basic_info;
    if (!GetFileInformationByHandleEx(hFile, FileIdInfo, &id_info, sizeof (id_info)) ||
        !GetFileInformationByHandleEx(hFile, FileStandardInfo, &standard_info, sizeof (standard_info)) ||
        !GetFileInformationByHandleEx(hFile, FileBasicInfo, &basic_info, sizeof (basic_info)))
    {
        return FALSE;
    }

    lpInfo->dwFileAttributes = basic_info.FileAttributes;

    lpInfo->ftCreationTime.dwHighDateTime   = basic_info.CreationTime.HighPart;
    lpInfo->ftCreationTime.dwLowDateTime    = basic_info.CreationTime.LowPart;
    lpInfo->ftLastAccessTime.dwHighDateTime = basic_info.LastAccessTime.HighPart;
    lpInfo->ftLastAccessTime.dwLowDateTime  = basic_info.LastAccessTime.LowPart;
    lpInfo->ftLastWriteTime.dwHighDateTime  = basic_info.LastWriteTime.HighPart;
    lpInfo->ftLastWriteTime.dwLowDateTime   = basic_info.LastWriteTime.LowPart;

    lpInfo->dwVolumeSerialNumber = id_info.VolumeSerialNumber;

    lpInfo->nFileSizeHigh = standard_info.EndOfFile.HighPart;
    lpInfo->nFileSizeLow  = standard_info.EndOfFile.LowPart;

    lpInfo->nNumberOfLinks = standard_info.NumberOfLinks;

    /* The nFileIndex from GetFileInformationByHandle is equal to the low
             64 bits of the 128-bit FileId from GetFileInformationByHandleEx,
             and the high 64 bits of this 128-bit FileId are zero. */
    lpInfo->nFileIndexLow  = (id_info.FileId.Identifier[12] << 24) | (id_info.FileId.Identifier[13] << 16) | (id_info.FileId.Identifier[14] << 8) | id_info.FileId.Identifier[15];
    lpInfo->nFileIndexHigh = (id_info.FileId.Identifier[ 8] << 24) | (id_info.FileId.Identifier[ 9] << 16) | (id_info.FileId.Identifier[10] << 8) | id_info.FileId.Identifier[11];

    return TRUE;
}

#ifdef _X86_
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(GetFileInformationByHandle))(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpInfo) __asm__("__imp__GetFileInformationByHandle@8") = GetFileInformationByHandle;
#else
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(GetFileInformationByHandle))(HANDLE hFile, LPBY_HANDLE_FILE_INFORMATION lpInfo) __asm__("__imp_GetFileInformationByHandle") = GetFileInformationByHandle;
#endif
