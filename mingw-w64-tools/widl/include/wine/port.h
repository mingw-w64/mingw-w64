
#include <fcntl.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifndef O_BINARY
# define O_BINARY 0
#endif

#ifndef HAVE_MKSTEMP
extern int mkstemps(char *template, int suffix_len);
#endif

