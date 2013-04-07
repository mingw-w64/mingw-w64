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

#include <stdlib.h>
#include <stdio.h>

#include <windows.h>
#include <dbghelp.h>

#include "examine_list.h"
#include "examine_stacktrace.h"

#define STACKWALK_MAX_NAMELEN 1024

struct _Exm_Sw_Data
{
    char *filename;
    char *function;
    int   line;
};

struct _Exm_Sw
{
    HANDLE proc;
    HANDLE thread;
    unsigned int resume_thread : 1;
};

static BOOL __stdcall _sw_read_memory_cb(HANDLE      hProcess,
                                         DWORD64     qwBaseAddress,
                                         PVOID       lpBuffer,
                                         DWORD       nSize,
                                         LPDWORD     lpNumberOfBytesRead)
{
    SIZE_T st;
    BOOL ret;

    ret = ReadProcessMemory(hProcess, (LPVOID)(DWORD_PTR)qwBaseAddress, lpBuffer, nSize, &st);
    *lpNumberOfBytesRead = (DWORD)st;
    return ret;
}

Exm_Sw *
exm_sw_init(void)
{
    Exm_Sw *sw;
    DWORD   options;

    sw = (Exm_Sw *)calloc(1, sizeof(Exm_Sw));
    if (!sw)
        return NULL;

    options = SymGetOptions();
    SymSetOptions(options |
                  SYMOPT_LOAD_LINES |
                  SYMOPT_FAIL_CRITICAL_ERRORS |
                  SYMOPT_UNDNAME |
                  SYMOPT_DEBUG);

    if (!SymInitialize(GetCurrentProcess(), NULL, TRUE))
        goto free_sw;

    sw->proc = GetCurrentProcess();
    sw->thread = GetCurrentThread();

    return sw;

  free_sw:
    free(sw);

    return NULL;
}

void
exm_sw_shutdown(Exm_Sw *sw)
{
    if (!sw)
        return;

    if (sw->resume_thread)
        ResumeThread(sw->thread);
    SymCleanup(sw->proc);
    free(sw);
}

Exm_List *
exm_sw_frames_get(Exm_Sw *sw)
{
    CONTEXT context;
    STACKFRAME64 sf;
    IMAGEHLP_LINE64 line;
    SYMBOL_INFO *sym;
    Exm_List *list = NULL;
    DWORD arch;
    int frame_num;

    memset(&context, 0, sizeof(CONTEXT));
    context.ContextFlags = CONTEXT_FULL;
    RtlCaptureContext(&context);

    memset(&sf, 0, sizeof(STACKFRAME64));
#ifdef _M_IX86
    arch = IMAGE_FILE_MACHINE_I386;
    sf.AddrPC.Offset    = context.Eip;
    sf.AddrPC.Mode      = AddrModeFlat;
    sf.AddrFrame.Offset = context.Ebp;
    sf.AddrFrame.Mode   = AddrModeFlat;
    sf.AddrStack.Offset = context.Esp;
    sf.AddrStack.Mode   = AddrModeFlat;
#elif _M_X64
    arch = IMAGE_FILE_MACHINE_AMD64;
    sf.AddrPC.Offset    = context.Rip;
    sf.AddrPC.Mode      = AddrModeFlat;
    sf.AddrFrame.Offset = context.Rsp;
    sf.AddrFrame.Mode   = AddrModeFlat;
    sf.AddrStack.Offset = context.Rsp;
    sf.AddrStack.Mode   = AddrModeFlat;
#elif _M_IA64
    arch = IMAGE_FILE_MACHINE_IA64;
    sf.AddrPC.Offset     = context.StIIP;
    sf.AddrPC.Mode       = AddrModeFlat;
    sf.AddrFrame.Offset  = context.IntSp;
    sf.AddrFrame.Mode    = AddrModeFlat;
    sf.AddrBStore.Offset = context.RsBSP;
    sf.AddrBStore.Mode   = AddrModeFlat;
    sf.AddrStack.Offset  = context.IntSp;
    sf.AddrStack.Mode    = AddrModeFlat;
#else
# error "Platform not supported!"
#endif

    sym = (SYMBOL_INFO *)calloc(1, sizeof(SYMBOL_INFO) + STACKWALK_MAX_NAMELEN + 1);
    if (!sym)
        return NULL;

    sym->SizeOfStruct = sizeof(SYMBOL_INFO);
    sym->MaxNameLen = STACKWALK_MAX_NAMELEN;

    memset(&line, 0, sizeof(line));
    line.SizeOfStruct = sizeof(line);

    for (frame_num = 0; ; frame_num++)
    {
        if (!StackWalk64(arch, sw->proc, sw->thread, &sf, &context,
                         _sw_read_memory_cb,
                         SymFunctionTableAccess64,
                         SymGetModuleBase64,
                         NULL))
        {
            printf("StackWalk64() failed\n");
            break;
        }

        if (sf.AddrPC.Offset == sf.AddrReturn.Offset)
        {
            printf("StackWalk64-Endless-Callstack!");
            break;
        }

        if ((sf.AddrPC.Offset != 0) && (sf.AddrReturn.Offset != 0))
        {
            Exm_Sw_Data *sw_data;

            sw_data = (Exm_Sw_Data *)calloc(1, sizeof(Exm_Sw_Data));
            if (sw_data)
            {
                DWORD64 offset_from_symbol;
                DWORD offset_from_line;
                size_t l;

                /* function name */
                if (SymFromAddr(sw->proc, sf.AddrPC.Offset,
                                &offset_from_symbol, sym))
                {
                    l = strlen(sym->Name) + 1;
                    sw_data->function = (char *)malloc(l * sizeof(char));
                    if (sw_data->function)
                        memcpy(sw_data->function, sym->Name, l);
                }

                /* line number and file name */
                if (SymGetLineFromAddr64(sw->proc, sf.AddrPC.Offset,
                                         &offset_from_line, &line))
                {
                    sw_data->line = line.LineNumber;
                    l = strlen(line.FileName) + 1;
                    sw_data->filename = (char *)malloc(l * sizeof(char));
                    if (sw_data->filename)
                        memcpy(sw_data->filename, line.FileName, l);
                }
                list = exm_list_append(list, sw_data);
            }
        }

        if (sf.AddrReturn.Offset == 0)
        {
            /* callstack_entry(SW_CALLSTACK_ENTRY_LAST, cse); */
            break;
        }
    }

    return list;
}

const char *
exm_sw_data_filename_get(Exm_Sw_Data *data)
{
    if (!data)
        return NULL;

    return data->filename;
}

const char *
exm_sw_data_function_get(Exm_Sw_Data *data)
{
    if (!data)
        return NULL;

    return data->function;
}

int
exm_sw_data_line_get(Exm_Sw_Data *data)
{
    if (!data)
        return 0;

    return data->line;
}

void
exm_sw_data_free(void *ptr)
{
    Exm_Sw_Data *data;

    if (!ptr)
        return;

    data = (Exm_Sw_Data *)ptr;
    if (data->filename)
        free(data->filename);
    if (data->function)
        free(data->function);
    free(data);
}
