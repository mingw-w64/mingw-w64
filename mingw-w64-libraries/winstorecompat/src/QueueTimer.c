/*
    Copyright (c) 2013-2016 mingw-w64 project

    Contributing authors: Rafaël Carré

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

#define CreateTimerQueueTimer _CreateTimerQueueTimer
#define DeleteTimerQueueTimer _DeleteTimerQueueTimer
#include <windows.h>
#include <threadpoollegacyapiset.h>
#undef CreateTimerQueueTimer
#undef DeleteTimerQueueTimer

WINBOOL WINAPI CreateTimerQueueTimer (PHANDLE phNewTimer, HANDLE TimerQueue, WAITORTIMERCALLBACK Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags);

WINBOOL WINAPI CreateTimerQueueTimer (PHANDLE phNewTimer, HANDLE TimerQueue, WAITORTIMERCALLBACK Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags)
{
    SetLastError(ERROR_ACCESS_DENIED);
    return 0;
}

WINBOOL WINAPI DeleteTimerQueueTimer (HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent);

WINBOOL WINAPI DeleteTimerQueueTimer (HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent)
{
    SetLastError(ERROR_ACCESS_DENIED);
    return 0;
}

#ifdef _X86_
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(CreateTimerQueueTimer)) (PHANDLE phNewTimer, HANDLE TimerQueue, WAITORTIMERCALLBACK Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags) __asm__("__imp__CreateTimerQueueTimer@28") = CreateTimerQueueTimer;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(DeleteTimerQueueTimer)) (HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent) __asm__("__imp__DeleteTimerQueueTimer@12") = DeleteTimerQueueTimer;
#else
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(CreateTimerQueueTimer)) (PHANDLE phNewTimer, HANDLE TimerQueue, WAITORTIMERCALLBACK Callback, PVOID Parameter, DWORD DueTime, DWORD Period, ULONG Flags) __asm__("__imp_CreateTimerQueueTimer") = CreateTimerQueueTimer;
WINBOOL (WINAPI *__MINGW_IMP_SYMBOL(DeleteTimerQueueTimer)) (HANDLE TimerQueue, HANDLE Timer, HANDLE CompletionEvent) __asm__("__imp_DeleteTimerQueueTimer") = DeleteTimerQueueTimer;
#endif
