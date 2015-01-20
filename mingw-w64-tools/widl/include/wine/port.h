
#include <fcntl.h>
#ifdef HAVE_UNISTD_H
# include <unistd.h>
#endif

#ifndef O_BINARY
# define O_BINARY 0
#endif

#ifndef HAVE_MKSTEMPS
extern int mkstemps(char *template, int suffix_len);
#endif

