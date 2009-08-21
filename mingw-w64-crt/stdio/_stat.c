#define __CRT__NO_INLINE
#include <sys/stat.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */
/* FIXME-2: Don't optimize due to strict-aliasing issues. */
#if _INTEGRAL_MAX_BITS < 64  || defined(_USE_32BIT_TIME_T)
int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
stat(const char *_Filename,struct stat *_Stat)
{
  return _stat32(_Filename,(struct _stat32 *)_Stat);
}
#else
int __cdecl __MINGW_ATTRIB_NO_OPTIMIZE
stat(const char *_Filename,struct stat *_Stat)
{
  return _stat64i32(_Filename,(struct _stat64i32 *)_Stat);
}
#endif

/* Add __imp__fstat and __imp__stat symbols.  */
int (*__MINGW_IMP_SYMBOL(stat))(const char *,struct stat *) = &stat;

