/**
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#define __CRT__NO_INLINE
#include <sys/stat.h>

#undef _fstati64
#if !defined(_USE_32BIT_TIME_T)
int __cdecl
_fstati64(int _Desc,struct _stat64 *_Stat);
int __cdecl
_fstati64(int _Desc,struct _stat64 *_Stat)
{
  return _fstat64(_Desc, _Stat);
}
int (*__MINGW_IMP_SYMBOL(_fstati64))(int, struct _stat64 *) = &_fstati64;
#else
int __cdecl
_fstati64(int _Desc,struct _stat32i64 *_Stat);
int __cdecl
_fstati64(int _Desc,struct _stat32i64 *_Stat)
{
  struct _stat32 st;
  int ret=_fstat32(_Desc,&st);
  if (ret == -1) {
    memset(_Stat,0,sizeof(struct _stat32i64));
    return -1;
  }
  _Stat->st_dev=st.st_dev;
  _Stat->st_ino=st.st_ino;
  _Stat->st_mode=st.st_mode;
  _Stat->st_nlink=st.st_nlink;
  _Stat->st_uid=st.st_uid;
  _Stat->st_gid=st.st_gid;
  _Stat->st_rdev=st.st_rdev;
  _Stat->st_size=(_off_t) st.st_size;
  _Stat->st_atime=st.st_atime;
  _Stat->st_mtime=st.st_mtime;
  _Stat->st_ctime=st.st_ctime;
  return ret;
}
int (*__MINGW_IMP_SYMBOL(_fstati64))(int, struct _stat32i64 *) = &_fstati64;
#endif
