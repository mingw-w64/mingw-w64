#define __CRT__NO_INLINE
#include <sys/stat.h>

#if _INTEGRAL_MAX_BITS >= 64
int __cdecl _fstat64i32(int _FileDes,struct _stat64i32 *_Stat)
{
  struct _stat64 st;
  int ret=_fstat64(_FileDes,&st);
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

int __cdecl _stat64i32(const char *_Name,struct _stat64i32 *_Stat)
{
  struct _stat64 st;
  int ret=_stat64(_Name,&st);
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
#endif /* _INTEGRAL_MAX_BITS >= 64 */

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */
/* FIXME-2: Don't optimize due to strict-aliasing issues. */
#if _INTEGRAL_MAX_BITS < 64  || defined(_USE_32BIT_TIME_T)
int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
fstat(int _Desc,struct stat *_Stat)
{
  return _fstat32(_Desc,(struct _stat32 *)_Stat);
}

int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
stat(const char *_Filename,struct stat *_Stat)
{
  return _stat32(_Filename,(struct _stat32 *)_Stat);
}
#else
int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
fstat(int _Desc,struct stat *_Stat)
{
  return _fstat64i32(_Desc,(struct _stat64i32 *)_Stat);
}

int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
stat(const char *_Filename,struct stat *_Stat)
{
  return _stat64i32(_Filename,(struct _stat64i32 *)_Stat);
}
#endif

/* Add __imp__fstat and __imp__stat symbols.  */
int (*__MINGW_IMP_SYMBOL(stat))(const char *,struct stat *) = &stat;
int (*__MINGW_IMP_SYMBOL(fstat))(int, struct stat *) = &fstat;

