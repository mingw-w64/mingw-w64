/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <stdio.h>
#include <io.h>
#include <errno.h>
#include <internal.h>

#define _IOYOURBUF      0x0100
#define _IOSETVBUF      0x0400
#define _IOFEOF         0x0800
#define _IOFLRTN        0x1000
#define _IOCTRLZ        0x2000
#define _IOCOMMIT       0x4000

/* General use macros */

#define inuse(s)        ((s)->_flag & (_IOREAD|_IOWRT|_IORW))
#define mbuf(s)         ((s)->_flag & _IOMYBUF)
#define nbuf(s)         ((s)->_flag & _IONBF)
#define ybuf(s)         ((s)->_flag & _IOYOURBUF)
#define bigbuf(s)       ((s)->_flag & (_IOMYBUF|_IOYOURBUF))
#define anybuf(s)       ((s)->_flag & (_IOMYBUF|_IONBF|_IOYOURBUF))

#define _INTERNAL_BUFSIZ    4096
#define _SMALL_BUFSIZ       512

#define FOPEN           0x01    /* file handle open */
#define FEOFLAG         0x02    /* end of file has been encountered */
#define FCRLF           0x04    /* CR-LF across read buffer (in text mode) */
#define FPIPE           0x08    /* file handle refers to a pipe */
#define FNOINHERIT      0x10    /* file handle opened _O_NOINHERIT */
#define FAPPEND         0x20    /* file handle opened O_APPEND */
#define FDEV            0x40    /* file handle refers to device */
#define FTEXT           0x80    /* file handle is in text mode */

_CRTIMP __int64 __cdecl _lseeki64(int fh,__int64 pos,int mthd);
__int64 __cdecl _ftelli64(FILE *str);

#if !defined(__arm__) && !defined(__aarch64__) /* we have F_ARM_ANY(_fseeki64) in msvcrt.def.in */
int __cdecl _flush (FILE *str);

int __cdecl _flush (FILE *str)
{
  FILE *stream;
  int rc = 0; /* assume good return */
  __int64 nchar;

  stream = str;
  if ((stream->_flag & (_IOREAD | _IOWRT)) == _IOWRT && bigbuf(stream)
      && (nchar = (__int64) (stream->_ptr - stream->_base)) > 0ll)
  {
    if ( _write(_fileno(stream), stream->_base, nchar) == nchar) {
      if (_IORW & stream->_flag)
        stream->_flag &= ~_IOWRT;
    } else {
      stream->_flag |= _IOERR;
      rc = EOF;
    }
  }
  stream->_ptr = stream->_base;
  stream->_cnt = 0ll;
  return rc;
}

int __cdecl _fseeki64(FILE *str,__int64 offset,int whence)
{
        FILE *stream;
        /* Init stream pointer */
        stream = str;
        errno=0;
        if(!stream || ((whence != SEEK_SET) && (whence != SEEK_CUR) && (whence != SEEK_END)))
	{
	  errno=EINVAL;
	  return -1;
        }
        /* Clear EOF flag */
        stream->_flag &= ~_IOEOF;

        if (whence == SEEK_CUR) {
	  offset += _ftelli64(stream);
	  whence = SEEK_SET;
	}
        /* Flush buffer as necessary */
        _flush(stream);

        /* If file opened for read/write, clear flags since we don't know
           what the user is going to do next. If the file was opened for
           read access only, decrease _bufsiz so that the next _filbuf
           won't cost quite so much */

        if (stream->_flag & _IORW)
                stream->_flag &= ~(_IOWRT|_IOREAD);
        else if ( (stream->_flag & _IOREAD) && (stream->_flag & _IOMYBUF) &&
                  !(stream->_flag & _IOSETVBUF) )
                stream->_bufsiz = _SMALL_BUFSIZ;

        /* Seek to the desired locale and return. */

        return (_lseeki64(_fileno(stream), offset, whence) == -1ll ? -1 : 0);
}

int __cdecl (*__MINGW_IMP_SYMBOL(_fseeki64))(FILE *, __int64, int) = _fseeki64;
#endif /* !defined(__arm__) && !defined(__aarch64__) */

__int64 __cdecl _ftelli64(FILE *str)
{
        FILE *stream;
        size_t offset;
        __int64 filepos;
        register char *p;
        char *max;
        int fd;
        size_t rdcnt = 0;

	errno=0;
        stream = str;
        fd = _fileno(stream);
        if (stream->_cnt < 0ll) stream->_cnt = 0ll;
    if ((filepos = _lseeki64(fd, 0ll, SEEK_CUR)) < 0L)
      return -1ll;

    if (!bigbuf(stream))            /* _IONBF or no buffering designated */
      return (filepos - (__int64) stream->_cnt);

    offset = (size_t)(stream->_ptr - stream->_base);

    if (stream->_flag & (_IOWRT|_IOREAD))
      {
        if (_osfile(fd) & FTEXT)
          for (p = stream->_base; p < stream->_ptr; p++)
            if (*p == '\n')  /* adjust for '\r' */
              offset++;
      }
      else if (!(stream->_flag & _IORW)) {
        errno=EINVAL;
        return -1ll;
      }
      if (filepos == 0ll)
        return ((__int64)offset);

      if (stream->_flag & _IOREAD)    /* go to preceding sector */
        {
          if (stream->_cnt == 0ll)  /* filepos holds correct location */
            offset = 0ll;
          else
            {
	          rdcnt = ((size_t) stream->_cnt) + ((size_t) (size_t)(stream->_ptr - stream->_base));
		      if (_osfile(fd) & FTEXT) {
		        if (_lseeki64(fd, 0ll, SEEK_END) == filepos) {
			      max = stream->_base + rdcnt;
			    for (p = stream->_base; p < max; p++)
			      if (*p == '\n') /* adjust for '\r' */
			        rdcnt++;
			    if (stream->_flag & _IOCTRLZ)
			      ++rdcnt;
		      } else {
		        _lseeki64(fd, filepos, SEEK_SET);
		        if ( (rdcnt <= _SMALL_BUFSIZ) && (stream->_flag & _IOMYBUF) &&
		            !(stream->_flag & _IOSETVBUF))
			      rdcnt = _SMALL_BUFSIZ;
		        else
		          rdcnt = stream->_bufsiz;
		        if  (_osfile(fd) & FCRLF)
		          ++rdcnt;
		      }
		    } /* end if FTEXT */
	    }
	  filepos -= (__int64)rdcnt;
    } /* end else stream->_cnt != 0 */
  return (filepos + (__int64)offset);
}

__int64 __cdecl (*__MINGW_IMP_SYMBOL(_ftelli64))(FILE *) = _ftelli64;

