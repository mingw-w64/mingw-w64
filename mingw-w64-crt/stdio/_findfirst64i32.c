#include <io.h>
#include <string.h>

intptr_t __cdecl _findfirst64i32(const char *_Filename,struct _finddata64i32_t *_FindData)
{
  struct __finddata64_t fd;
  intptr_t ret = _findfirst64(_Filename,&fd);
  _FindData->attrib=fd.attrib;
  _FindData->time_create=fd.time_create;
  _FindData->time_access=fd.time_access;
  _FindData->time_write=fd.time_write;
  _FindData->size=(_fsize_t) fd.size;
  strncpy(_FindData->name,fd.name,260);
  return ret;
}

intptr_t __cdecl _wfindfirst64i32(const wchar_t *_Filename,struct _wfinddata64i32_t *_FindData)
{
  struct _wfinddata64_t fd;
  intptr_t ret = _wfindfirst64(_Filename,&fd);
  _FindData->attrib=fd.attrib;
  _FindData->time_create=fd.time_create;
  _FindData->time_access=fd.time_access;
  _FindData->time_write=fd.time_write;
  _FindData->size=(_fsize_t) fd.size;
  memcpy(_FindData->name,fd.name,260*sizeof(wchar_t));
  return ret;
}
