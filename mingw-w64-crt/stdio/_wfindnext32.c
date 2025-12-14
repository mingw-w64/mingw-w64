#include <io.h>
#include <string.h>

int __cdecl _wfindnext32(intptr_t _FindHandle, struct _wfinddata32_t *_FindData)
{
  struct _wfinddata64_t fd;
  int ret = _wfindnext64(_FindHandle, &fd);
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
int (__cdecl *__MINGW_IMP_SYMBOL(_wfindnext32))(intptr_t, struct _wfinddata32_t *) = _wfindnext32;
