#include <io.h>
#include <string.h>

int __cdecl _findnext32i64(intptr_t _FindHandle, struct _finddata32i64_t *_FindData)
{
  struct __finddata64_t fd;
  int ret = _findnext64(_FindHandle, &fd);
  if (ret != 0)
    return ret;
  _FindData->attrib = fd.attrib;
  _FindData->time_create = fd.time_create;
  _FindData->time_access = fd.time_access;
  _FindData->time_write = fd.time_write;
  _FindData->size = (_fsize_t)fd.size;
  _Static_assert(sizeof(_FindData->name) == sizeof(fd.name), "mismatch size of _FindData->name and fd.name");
  memcpy(_FindData->name, fd.name, sizeof(_FindData->name));
  return 0;
}
int (__cdecl *__MINGW_IMP_SYMBOL(_findnext32i64))(intptr_t, struct _finddata32i64_t *) = _findnext32i64;

#ifndef _WIN64
#undef _findnexti64
int __attribute__ ((alias ("_findnext32i64"))) __cdecl _findnexti64(intptr_t, struct _finddata32i64_t *);
extern int __attribute__ ((alias (__MINGW64_STRINGIFY(__MINGW_IMP_SYMBOL(_findnext32i64))))) (__cdecl *__MINGW_IMP_SYMBOL(_findnexti64))(intptr_t, struct _finddata32i64_t *);
#endif
