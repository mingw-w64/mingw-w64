/*
	Copyright (c) 2009, 2010 KJK::Hyperion

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

#ifndef KJK_PSEH2_COMMON_H_
#define KJK_PSEH2_COMMON_H_

struct _EXCEPTION_RECORD;
struct _EXCEPTION_POINTERS;
struct _CONTEXT;

typedef int (__cdecl * _SEH2FrameHandler_t)
(
	struct _EXCEPTION_RECORD *,
	void *,
	struct _CONTEXT *,
	void *
);

typedef struct __SEH2Registration
{
	struct __SEH2Registration * SER_Prev;
	_SEH2FrameHandler_t SER_Handler;
}
_SEH2Registration_t;

typedef struct __SEH2Frame
{
	_SEH2Registration_t SF_Registration;
	volatile struct __SEH2TryLevel * volatile SF_TopTryLevel;
	volatile unsigned long SF_Code;
}
_SEH2Frame_t;

typedef struct __SEH2TryLevel
{
	volatile struct __SEH2TryLevel * ST_Next;
	void * ST_Filter;
	void * ST_Body;
}
_SEH2TryLevel_t;

typedef struct __SEH2HandleTryLevel
{
	_SEH2TryLevel_t  SHT_Common;
	void * volatile SHT_Esp;
	void * volatile SHT_Ebp;
	void * volatile SHT_Ebx;
	void * volatile SHT_Esi;
	void * volatile SHT_Edi;
}
_SEH2HandleTryLevel_t;

#ifdef __cplusplus
extern "C"
{
#endif

extern int __cdecl _SEH2EnterFrameAndTrylevel(_SEH2Frame_t *, volatile _SEH2TryLevel_t *);
extern __attribute__((returns_twice)) int __cdecl _SEH2EnterFrameAndHandleTrylevel(_SEH2Frame_t *, volatile _SEH2HandleTryLevel_t *, void *);
extern __attribute__((returns_twice)) int __cdecl _SEH2EnterHandleTrylevel(_SEH2Frame_t *, volatile _SEH2HandleTryLevel_t *, void *);
extern void __cdecl _SEH2LeaveFrame(void);
extern void __cdecl _SEH2Return(void);

#ifdef __cplusplus
}
#endif

#define __SEH_EXCEPT_RET long

#endif

/* EOF */
