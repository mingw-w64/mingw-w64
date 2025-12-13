/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef __MINGW_FIX_STAT_H
#define __MINGW_FIX_STAT_H

char* __mingw_fix_stat_path (const char* _path);
wchar_t* __mingw_fix_wstat_path (const wchar_t* _path);
int __mingw_fix_stat_finish(int ret, const void *orig_path, void *used_path,
                            unsigned short mode);
int __mingw_fix_fstat_finish(int ret, int fd, unsigned short *mode);
int __mingw_fix_wstat_fallback_fd(int ret, const wchar_t *filename, unsigned short mode);
int __mingw_fix_stat_fallback_fd(int ret, const char *filename, unsigned short mode);

#define __MINGW_FIXED_FSTAT(fstat_func, fd, obj) ({ \
   int _fstat_ret = fstat_func(fd, obj); \
   _fstat_ret = __mingw_fix_fstat_finish(_fstat_ret, fd, &(obj)->st_mode); \
   _fstat_ret; \
})

#define __MINGW_CHOOSE_CHAR_WCHART_EXPR(var, char_expr, wchart_expr, other_expr) \
  __builtin_choose_expr(__builtin_types_compatible_p(typeof(var), char), char_expr, \
    __builtin_choose_expr(__builtin_types_compatible_p(typeof(var), wchar_t), wchart_expr, \
      other_expr))

#define __MINGW_PATH_PTR_TYPE(path) \
  typeof(__MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], (char*)0, (wchar_t*)0, (void)0))

#define __MINGW_FIX_STAT_PATH(path) \
  __MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], __mingw_fix_stat_path, __mingw_fix_wstat_path, NULL)(path)

#define __MINGW_FIX_STAT_FALLBACK_FD(ret, path, mode) \
  __MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], __mingw_fix_stat_fallback_fd, __mingw_fix_wstat_fallback_fd, NULL)((ret), (path), (mode))

#define __MINGW_CREATE_FILE(path, ...) \
  __MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], CreateFileA, CreateFileW, NULL)((path), ##__VA_ARGS__)

#define __MINGW_STR_PBRK(path, accept) \
  __MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], strpbrk, wcspbrk, NULL)((path), __MINGW_CHOOSE_CHAR_WCHART_EXPR((path)[0], accept, L##accept, NULL))

#define __MINGW_FIXED_STAT(fstat_func, stat_func, filename, obj) ({ \
  /* First call CRT _stat function with mingw path correction */ \
  int _stat_ret; \
  __MINGW_PATH_PTR_TYPE(filename) path = __MINGW_FIX_STAT_PATH(filename); \
  if (path == NULL && (filename) != NULL) { \
    _stat_ret = -1; \
  } else { \
    _stat_ret = (stat_func)(path, (obj)); \
    _stat_ret = __mingw_fix_stat_finish(_stat_ret, (filename), path, (obj)->st_mode); \
    /* If the CRT _stat function failed then fallback to mingw fstat function */ \
    int _stat_fd = __MINGW_FIX_STAT_FALLBACK_FD(_stat_ret, (filename), (obj)->st_mode); \
    if (_stat_fd >= 0) { \
      _stat_ret = fstat_func(_stat_fd, (void*)(obj)); \
      int _stat_errno = errno; \
      close(_stat_fd); \
      errno = _stat_errno; \
    } \
  } \
  _stat_ret; \
})

#endif
