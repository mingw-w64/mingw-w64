#include <process.h>

intptr_t __cdecl spawnv(int,const char *_Filename,char *const _ArgList[])
{
  return _spawnv(_Filename,(const char *const *)_ArgList);
}
