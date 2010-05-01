#ifndef FSREDIR_HEADER
#define FSREDIR_HEADER

#if defined (_WIN32) || defined (__CYGWIN__)
#define REDIRECTOR 1 /* Allow disabling win64 FS redirection */
void doredirect(const int redir);
#endif

#endif
