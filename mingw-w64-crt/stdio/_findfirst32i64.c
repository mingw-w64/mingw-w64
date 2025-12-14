#include <io.h>
#include <string.h>

intptr_t __cdecl _findfirst32i64(const char *_Filename, struct _finddata32i64_t *_FindData)
{
  struct __finddata64_t fd;
  intptr_t ret = _findfirst64(_Filename, &fd);
  if (ret == -1)
    return -1;
  _FindData->attrib = fd.attrib;
  _FindData->time_create = fd.time_create;
  _FindData->time_access = fd.time_access;
  _FindData->time_write = fd.time_write;
  _FindData->size = (_fsize_t)fd.size;
  _Static_assert(sizeof(_FindData->name) == sizeof(fd.name), "mismatch size of _FindData->name and fd.name");
  memcpy(_FindData->name, fd.name, sizeof(_FindData->name));
  return ret;
}
intptr_t (__cdecl *__MINGW_IMP_SYMBOL(_findfirst32i64))(const char *, struct _finddata32i64_t *) = _findfirst32i64;

#ifndef _WIN64
#undef _findfirsti64
intptr_t __attribute__ ((alias ("_findfirst32i64"))) __cdecl _findfirsti64(const char *, struct _finddata32i64_t *);
extern intptr_t __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_findfirst32i64))))) (__cdecl *__MINGW_IMP_SYMBOL(_findfirsti64))(const char *, struct _finddata32i64_t *);
#endif
