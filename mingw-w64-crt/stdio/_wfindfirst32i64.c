#include <io.h>
#include <string.h>

intptr_t __cdecl _wfindfirst32i64(const wchar_t *_Filename, struct _wfinddata32i64_t *_FindData)
{
  struct _wfinddata64_t fd;
  intptr_t ret = _wfindfirst64(_Filename, &fd);
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
intptr_t (__cdecl *__MINGW_IMP_SYMBOL(_wfindfirst32i64))(const wchar_t *, struct _wfinddata32i64_t *) = _wfindfirst32i64;

#ifndef _WIN64
#undef _wfindfirsti64
intptr_t __attribute__ ((alias ("_wfindfirst32i64"))) __cdecl _wfindfirsti64(const wchar_t *, struct _wfinddata32i64_t *);
extern intptr_t __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_wfindfirst32i64))))) (__cdecl *__MINGW_IMP_SYMBOL(_wfindfirsti64))(const wchar_t *, struct _wfinddata32i64_t *);
#endif
