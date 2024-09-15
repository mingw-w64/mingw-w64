/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

/* crtdll.dll's dev_t is short, msvcrt.dll's dev_t is unsigned int */
typedef short __crtdll_dev_t;

struct __crtdll_stat {
  __crtdll_dev_t st_dev;
  _ino_t st_ino;
  unsigned short st_mode;
  short st_nlink;
  short st_uid;
  short st_gid;
  __crtdll_dev_t st_rdev;
  _off_t st_size;
  __time32_t st_atime;
  __time32_t st_mtime;
  __time32_t st_ctime;
};

#define copy_stat_members(dest, src) do { \
  (dest)->st_dev   = (src)->st_dev;       \
  (dest)->st_ino   = (src)->st_ino;       \
  (dest)->st_mode  = (src)->st_mode;      \
  (dest)->st_nlink = (src)->st_nlink;     \
  (dest)->st_uid   = (src)->st_uid;       \
  (dest)->st_gid   = (src)->st_gid;       \
  (dest)->st_rdev  = (src)->st_rdev;      \
  (dest)->st_size  = (src)->st_size;      \
  (dest)->st_atime = (src)->st_atime;     \
  (dest)->st_mtime = (src)->st_mtime;     \
  (dest)->st_ctime = (src)->st_ctime;     \
} while (0)
