/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _GDIPLUSMEM_H
#define _GDIPLUSMEM_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef WINAPI
#define WINAPI __stdcall
#endif

#define WINGDIPAPI WINAPI

  WINAPI void *GdipAlloc(size_t size);
  WINAPI void GdipFree(void *ptr);

#ifdef __cplusplus
}
#endif
#endif
