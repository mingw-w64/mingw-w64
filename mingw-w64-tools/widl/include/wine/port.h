
#include <fcntl.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifdef _WIN32

#include <direct.h>
#include <io.h>
#include <process.h>

#else

#ifndef __int64
#  if defined(__x86_64__) || defined(__aarch64__) || defined(_WIN64)
#    define __int64 long
#  else
#    define __int64 long long
#  endif
#endif

#endif

#ifndef O_BINARY
# define O_BINARY 0
#endif

#ifndef HAVE_MKSTEMPS
extern int mkstemps(char *template, int suffix_len);
#endif

