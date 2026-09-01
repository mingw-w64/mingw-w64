/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CORECRT_MALLOC
#define _INC_CORECRT_MALLOC

#include <corecrt.h>

_CRT_BEGIN_C_HEADER

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma push_macro("calloc")
#undef calloc
#pragma push_macro("free")
#undef free
#pragma push_macro("malloc")
#undef malloc
#pragma push_macro("realloc")
#undef realloc
#pragma push_macro("_aligned_free")
#undef _aligned_free
#pragma push_macro("_aligned_malloc")
#undef _aligned_malloc
#pragma push_macro("_aligned_offset_malloc")
#undef _aligned_offset_malloc
#pragma push_macro("_aligned_realloc")
#undef _aligned_realloc
#pragma push_macro("_aligned_offset_realloc")
#undef _aligned_offset_realloc
#pragma push_macro("_recalloc")
#undef _recalloc
#pragma push_macro("_aligned_recalloc")
#undef _aligned_recalloc
#pragma push_macro("_aligned_offset_recalloc")
#undef _aligned_offset_recalloc
#pragma push_macro("_aligned_msize")
#undef _aligned_msize
#endif

  void *__cdecl calloc(size_t _NumOfElements,size_t _SizeOfElements);
  void __cdecl free(void *_Memory);
  void *__cdecl malloc(size_t _Size);
  void *__cdecl realloc(void *_Memory,size_t _NewSize);

  _CRTIMP void __cdecl _aligned_free(void *_Memory);
  _CRTIMP void *__cdecl _aligned_malloc(size_t _Size,size_t _Alignment);

  _CRTIMP void *__cdecl _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _aligned_realloc(void *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_realloc(void *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP void *__cdecl _recalloc(void *_Memory,size_t _Count,size_t _Size);
  _CRTIMP void *__cdecl _aligned_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP void *__cdecl _aligned_offset_recalloc(void *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP size_t __cdecl _aligned_msize(void *_Memory,size_t _Alignment,size_t _Offset);

#if defined(_DEBUG) && defined(_CRTDBG_MAP_ALLOC)
#pragma pop_macro("calloc")
#pragma pop_macro("free")
#pragma pop_macro("malloc")
#pragma pop_macro("realloc")
#pragma pop_macro("_aligned_free")
#pragma pop_macro("_aligned_malloc")
#pragma pop_macro("_aligned_offset_malloc")
#pragma pop_macro("_aligned_realloc")
#pragma pop_macro("_aligned_offset_realloc")
#pragma pop_macro("_recalloc")
#pragma pop_macro("_aligned_recalloc")
#pragma pop_macro("_aligned_offset_recalloc")
#pragma pop_macro("_aligned_msize")
#endif

_CRT_END_C_HEADER

#endif
