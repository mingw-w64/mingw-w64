/* Examine - a tool for memory leak detection on Windows
 *
 * Copyright (C) 2012-2013 Vincent Torri.
 * All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HAVE_CONFIG_H
# include <config.h>
#endif

#include <stdio.h>

#ifndef WIN32_LEAN_AND_MEAN
# define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#undef WIN32_LEAN_AND_MEAN

#include "examine_list.h"
#include "examine_pe.h"

struct _Exm_Pe_File
{
    HANDLE file;
    HANDLE file_map;
    void *base;
    IMAGE_NT_HEADERS *nt_header;
};

static const char *_exm_pe_dll_supp[] =
{
    "API-MS-WIN-CORE-CONSOLE-L1-1-0.DLL",
    "API-MS-WIN-CORE-DATETIME-L1-1-0.DLL",
    "API-MS-WIN-CORE-DEBUG-L1-1-0.DLL",
    "API-MS-WIN-CORE-ERRORHANDLING-L1-1-0.DLL",
    "API-MS-WIN-CORE-FIBERS-L1-1-0.DLL",
    "API-MS-WIN-CORE-FILE-L1-1-0.DLL",
    "API-MS-WIN-CORE-HANDLE-L1-1-0.DLL",
    "API-MS-WIN-CORE-HEAP-L1-1-0.DLL",
    "API-MS-WIN-CORE-IO-L1-1-0.DLL",
    "API-MS-WIN-CORE-LIBRARYLOADER-L1-1-0.DLL",
    "API-MS-WIN-CORE-LOCALIZATION-L1-1-0.DLL",
    "API-MS-WIN-CORE-MEMORY-L1-1-0.DLL",
    "API-MS-WIN-CORE-MISC-L1-1-0.DLL",
    "API-MS-WIN-CORE-NAMEDPIPE-L1-1-0.DLL",
    "API-MS-WIN-CORE-PROCESSENVIRONMENT-L1-1-0.DLL",
    "API-MS-WIN-CORE-PROCESSTHREADS-L1-1-0.DLL",
    "API-MS-WIN-CORE-PROFILE-L1-1-0.DLL",
    "API-MS-WIN-CORE-RTLSUPPORT-L1-1-0.DLL",
    "API-MS-WIN-CORE-STRING-L1-1-0.DLL",
    "API-MS-WIN-CORE-SYNCH-L1-1-0.DLL",
    "API-MS-WIN-CORE-SYSINFO-L1-1-0.DLL",
    "API-MS-WIN-CORE-THREADPOOL-L1-1-0.DLL",
    "API-MS-WIN-CORE-UTIL-L1-1-0.DLL",
    "API-MS-WIN-SECURITY-BASE-L1-1-0.DLL",
    "kernel32.dll",
    "kernelbase.dll",
    "msvcrt.dll",
    "msvcr90.dll",
    "msvcr90d.dll",
    "ntdll.dll",
    "user32.dll",
    NULL
};

static int
_exm_pe_path_is_absolute(const char *filename)
{
    if (!filename)
        return 0;

    if (strlen(filename) < 3)
        return 0;

    if ((((*filename >= 'a') && (*filename <= 'z')) ||
         ((*filename >= 'A') && (*filename <= 'Z'))) &&
        (filename[1] == ':') &&
        ((filename[2] == '/') || (filename[2] == '\\')))
        return 1;

    return 0;
}

static int
_exm_pe_module_name_cmp(void *d1, void *d2)
{
    char **iter;
    int is_dll_sup = 0;

    iter = (char **)_exm_pe_dll_supp;
    while (*iter)
    {
        if (stricmp((const char *)d2, *iter) == 0)
        {
            is_dll_sup = 1;
            break;
        }
        iter++;
    }

    if (is_dll_sup == 1)
        return 0;

    return _stricmp((const char *)d1, (const char *)d2);
}

static void *
_exm_pe_rva_to_ptr_get(Exm_Pe_File *file, DWORD rva)
{
    IMAGE_SECTION_HEADER *sh;
    IMAGE_SECTION_HEADER *sh_iter;
    int delta;
    int i;

    sh = NULL;
    sh_iter = IMAGE_FIRST_SECTION(file->nt_header);
    for (i = 0; i < file->nt_header->FileHeader.NumberOfSections; i++, sh_iter++)
    {
        if ((rva >= sh_iter->VirtualAddress) &&
            (rva < (sh_iter->VirtualAddress + sh_iter->Misc.VirtualSize)))
        {
            sh = sh_iter;
            break;
        }
    }

    if (!sh)
        return NULL;

    delta = (int)(sh->VirtualAddress - sh->PointerToRawData);

return (void *)((unsigned char *)file->base + rva - delta);
}

static IMAGE_IMPORT_DESCRIPTOR *
_exm_pe_iat_get(Exm_Pe_File *file)
{
    IMAGE_IMPORT_DESCRIPTOR *import_desc;
    DWORD import_dir;

    if (!file)
        return NULL;

    import_dir = file->nt_header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
    if (!import_dir)
    {
        /* printf("not a valid import table\n"); */
        return NULL;
    }

    import_desc = (IMAGE_IMPORT_DESCRIPTOR *)_exm_pe_rva_to_ptr_get(file, import_dir);
    if (!import_desc)
    {
        printf("not a valid import table descriptor\n");
        return NULL;
    }

    return import_desc;
}

Exm_Pe_File *
exm_pe_file_new(const char *filename)
{
    IMAGE_DOS_HEADER *dos_header;
    Exm_Pe_File *file;
    char *full_filename;
    char *iter;

    if (!filename)
        return NULL;

    if (!_exm_pe_path_is_absolute(filename))
        full_filename = exm_pe_dll_path_find(filename);
    else
        full_filename = strdup(filename);

    if (!full_filename)
        return NULL;

    iter = full_filename;
    while (*iter)
    {
        if (*iter == '/') *iter = '\\';
        iter++;
    }

    file = (Exm_Pe_File *)malloc(sizeof(Exm_Pe_File));
    if (!file)
        goto free_filename;

    file->file = CreateFile(full_filename,
                            GENERIC_READ,
                            FILE_SHARE_READ,
                            NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL,
                            NULL);
    if (file->file == INVALID_HANDLE_VALUE)
        goto free_file;

    file->file_map = CreateFileMapping(file->file,
                                       NULL, PAGE_READONLY,
                                       0, 0, NULL);
    if (!file->file_map)
        goto close_file;

    file->base = MapViewOfFile(file->file_map, FILE_MAP_READ, 0, 0, 0);
    if (!file->base)
        goto close_file_map;

    dos_header = (IMAGE_DOS_HEADER *)file->base;
    if (dos_header->e_magic != IMAGE_DOS_SIGNATURE)
    {
        printf("not a valid DOS header\n");
        goto unmap_base;
    }

    file->nt_header = (IMAGE_NT_HEADERS *)((uintptr_t)dos_header + (uintptr_t)dos_header->e_lfanew);
    if (file->nt_header->Signature != IMAGE_NT_SIGNATURE)
    {
        printf("not a valid NT header\n");
        goto unmap_base;
    }

    free(full_filename);

    return file;

  unmap_base:
    UnmapViewOfFile(file->base);
  close_file_map:
    CloseHandle(file->file_map);
  close_file:
    CloseHandle(file->file);
  free_file:
    free(file);
  free_filename:
    free(full_filename);

    return NULL;
}

void
exm_pe_file_free(Exm_Pe_File *file)
{
    if (!file)
        return;

    UnmapViewOfFile(file->base);
    CloseHandle(file->file_map);
    CloseHandle(file->file);
    free(file);
}

Exm_List *
exm_pe_modules_list_get(Exm_List *l, const char *filename)
{
    Exm_Pe_File *file;
    IMAGE_IMPORT_DESCRIPTOR *import_desc;
    Exm_List *tmp;

    file = exm_pe_file_new(filename);
    import_desc = _exm_pe_iat_get(file);
    if (!import_desc)
        return l;

    while (import_desc->Name != 0)
    {
        char *dll_name;

        dll_name = (char *)_exm_pe_rva_to_ptr_get(file, import_desc->Name);
        dll_name = strdup(dll_name);
        if (dll_name)
            l = exm_list_append_if_new(l, dll_name, _exm_pe_module_name_cmp);
        tmp = exm_pe_modules_list_get(l, dll_name);
        if (tmp) l = tmp;

        import_desc++;
    }

    exm_pe_file_free(file);

    return l;
}

char *
exm_pe_dll_path_find(const char *filename)
{
    char buf[MAX_PATH];
    char full_name[MAX_PATH];
    DWORD res;

    if (_exm_pe_path_is_absolute(filename))
        return strdup(filename);

    /* system diretory */
    {
        UINT length;

        length = GetSystemDirectory(buf, sizeof(buf));
        if (length <= sizeof(buf))
        {
            snprintf(full_name, sizeof(full_name), "%s\\%s", buf, filename);
            res = GetFileAttributes(full_name);
            if (res != (DWORD)-1)
            {
                if ((res & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
                    return strdup(full_name);
            }
        }
    }

    /* windows directory */
    {
        UINT length;

        length = GetWindowsDirectory(buf, sizeof(buf));
        if (length <= sizeof(buf))
        {
            snprintf(full_name, sizeof(full_name), "%s\\%s", buf, filename);
            res = GetFileAttributes(full_name);
            if (res != (DWORD)-1)
            {
                if ((res & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
                    return strdup(full_name);
            }
        }
    }

    /* current directory */
    {
        DWORD length;

        length = GetCurrentDirectory(sizeof(buf), buf);
        if ((length <= sizeof(buf)) && (length != 0))
        {
            snprintf(full_name, sizeof(full_name), "%s\\%s", buf, filename);
            res = GetFileAttributes(full_name);
            if (res != (DWORD)-1)
            {
                if ((res & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
                    return strdup(full_name);
            }
        }
    }

    /* PATH */
    {
        char buf_path[32767];

        res = GetEnvironmentVariable("PATH", buf_path, sizeof(buf_path));
        if (res != 0)
        {
            char *iter;
            char *s;

            iter = buf_path;
            while (iter)
            {
                s = strchr(iter, ';');
                if (!s) break;
                *s = '\0';
                snprintf(full_name, sizeof(full_name), "%s\\%s", iter, filename);
                res = GetFileAttributes(full_name);
                if (res != (DWORD)-1)
                {
                    if ((res & FILE_ATTRIBUTE_ARCHIVE) == FILE_ATTRIBUTE_ARCHIVE)
                        return strdup(full_name);
                }

                iter = s + 1;
            }
        }
    }

    return strdup(filename);
}
