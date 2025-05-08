/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "__mingw_fix_stat.h"

static const char* next_char (unsigned int cp, const char* p)
{
  /* If it is a lead byte, skip the next byte except if it is \0.
   * If it is \0, it's not a valid DBCS string. */
  return (IsDBCSLeadByteEx (cp, *p) && p[1] != '\0') ? p + 2 : p + 1;
}

/**
 * Returns _path without trailing slash if any
 *
 * - if _path has no trailing slash, the function returns it
 * - if _path has a trailing slash, but is of the form C:/, then it returns it
 * - otherwise, the function creates a new string, which is a copy of _path
 *   without the trailing slash. It is then the responsibility of the caller
 *   to free it.
 */

char* __mingw_fix_stat_path (const char* _path)
{
  const unsigned int cp = __mingw_filename_cp ();
  size_t len;
  char *p;

  p = (char*)_path;

  if (_path && *_path) {
    len = strlen (_path);

    /* Ignore X:\
     * No ANSI or OEM code page uses ':' as a trail byte. (The code page 1361
     * cannot be used as ANSI or OEM code page.) */
    if (len <= 1 || ((len == 2 || len == 3) && _path[1] == ':'))
      return p;

    const char *r = _path;

    /* Check UNC \\abc\<name>\ */
    if ((_path[0] == '\\' || _path[0] == '/')
	&& (_path[1] == '\\' || _path[1] == '/'))
      {
	r = &_path[2];
	while (*r != 0 && *r != '\\' && *r != '/')
	  r = next_char (cp, r);
	if (*r != 0)
	  ++r;
	if (*r == 0)
	  return p;
	while (*r != 0 && *r != '\\' && *r != '/')
	  r = next_char (cp, r);
	if (*r != 0)
	  ++r;
	if (*r == 0)
	  return p;
      }

    if (_path[len - 1] == '/' || _path[len - 1] == '\\')
      {
	/* Return if the last character is a double-byte character.
	 * Its trail byte could be a '\' which must not be interpret
	 * as a directory separator. */
	while (r[1] != '\0')
	  {
	    r = next_char (cp, r);
	    if (*r == '\0')
	      return p;
	  }

	p = (char*)malloc (len);
	if (p == NULL)
	  return NULL; /* malloc has set errno. */
	memcpy (p, _path, len - 1);
	p[len - 1] = '\0';
      }
  }

  return p;
}
