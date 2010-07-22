/*
   Copyright (c) 2009, 2010 mingw-w64 project

   Contributing authors: Kai Tietz, Jonathan Yong

   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included in
   all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "compat_string.h"
#include "gendef.h"

typedef struct sImpDef {
  struct sImpDef *next;
  char *name;
  char *data;
  size_t length;
} sImpDef;

static sImpDef *theImpDef = NULL;

typedef struct sDefPaths {
  struct sDefPaths *next;
  char path[1];
} sDefPaths;

static sDefPaths *thePathDefs;

static int find_path_def (const char *path);
static int add_path_def (const char *path);

static sImpDef *is_def_loaded (const char *);
static sImpDef *gendef_loaddef (const char *);
static FILE *fopen_def (const char *name);
static uint32_t get_uint32_by_str (const char *txt);

int
gendef_getsymbol_info (const char *dllname, const char *symbolname, int *isData, uint32_t *at)
{
  char *r1 = NULL, *r2 = NULL, *def;
  sImpDef *id;
  size_t symlen;
  int ret = 0;

  if (!dllname)
    return 0;
  if (!symbolname || *symbolname == 0)
    {
      char *h = strchr (dllname, '.');
      if (!h)
	return 0;
      r1 = strdup (h + 1);
      if (*r1 == '#')
	{
	  r2 = (char *) malloc (strlen (r1) + 5);
	  sprintf (r2, "ord_%s", r1 + 1);
	  free (r1);
	  r1 = r2;
	}
      symbolname = r1;
      r2 = strdup (dllname);
      strcpy (strchr (r2, '.'), ".dll");
      dllname = r2;
    }
  def = (char *) malloc (strlen (dllname) + 4);
  strcpy (def, dllname);
  strlwr (def);
  if (strchr (def, '.') == NULL)
    strcat (def, ".def");
  else
    strcpy (strchr (def, '.'), ".def");
  symlen = strlen (symbolname);
  id = gendef_loaddef (def);
  if (id)
    {
      char *t = id->data;
      while (t != NULL && *t != 0)
	{
	  t = strchr (t, '\n');
	  if (t)
	    t++;
	  if (t && strncmp (t, symbolname, symlen) == 0)
	    {
	      if ((t[symlen] > 0 && t[symlen] <= 0x20) || t[symlen] == '@')
		{
		  t += symlen + 1;
		  *at = get_uint32_by_str (t);
		  while (*t != 0 && *t != '\n')
		    {
		      if (!strncmp (t, "DATA", 4))
			{
			  *isData = 1;
			  break;
			}
		      t++;
		    }
		  ret = 1;
		  break;
		}

	    }
	}
    }
  if (def)
    free (def);
  if (r2 != NULL && r1 != r2)
    free (r2);
  if (r1 != NULL)
    free (r1);
  return ret;
}

static FILE *
fopen_def (const char *name)
{
  sDefPaths *l = thePathDefs;
  FILE *fp;
  if ((fp = fopen (name, "rb")) != NULL)
    return fp;
  while (l != NULL)
    {
      char *h = (char *) malloc (strlen (name) + strlen (l->path) + 1);
      if (h)
	{
	  strcpy (h, l->path);
	  strcat (h, name);
	  fp = fopen (h, "rb");
	  free (h);
	  if (fp)
	    return fp;
	}
      l = l->next;
    }
  return NULL;
}

static sImpDef *
gendef_loaddef (const char *name)
{
  sImpDef *n;
  FILE *fp;
  char *lname;
  size_t len;
  char *txt;
  if (!name || *name == 0)
    return NULL;
  lname = strdup (name);
  if (!lname)
    return NULL;
  strlwr (lname);
  n = is_def_loaded (lname);
  if (n)
    {
      free (lname);
      return n;
    }
  fp = fopen_def (name);
  if (!fp)
    {
      free (lname);
      return NULL;
    }
  fseek (fp, 0, SEEK_END);
  len = (size_t) ftell (fp);
  fseek (fp, 0, SEEK_SET);
  txt = (char *) malloc (len + 1);
  if (!txt)
    {
      fclose (fp);
      free (lname);
      return NULL;
    }
  if ((size_t) fread (txt, 1, len, fp) != len)
    {
      fclose (fp);
      free (lname);
      free (txt);
      return NULL;
    }
  fclose (fp);
  txt[len] = 0;

  n = (sImpDef *) malloc (sizeof (sImpDef));
  if (!n)
    {
      free (lname);
      free (txt);
      return NULL;
    }
  memset (n, 0, sizeof (sImpDef));
  n->name = lname;
  n->data = txt;
  n->length = len;
  n->next = theImpDef;
  theImpDef = n;
  return n;
}

static sImpDef *
is_def_loaded (const char *dname)
{
  sImpDef *h = theImpDef;
  while (h != NULL)
    {
      if (!strcasecmp (h->name, dname))
	break;
      h = h->next;
    }
  return h;
}

static uint32_t
get_uint32_by_str (const char *txt)
{
  uint32_t ret = 0;
  while (*txt != 0 && *txt >= '0' && *txt <= '9')
    {
      ret *= 10;
      ret += (uint32_t) (txt[0] - '0');
      ++txt;
    }
  return ret;
}

int
gendef_addpath_def (const char *path)
{
  if (find_path_def (path))
    return 1;
  return add_path_def (path);
}

static int
find_path_def (const char *path)
{
  char *h, *p;
  sDefPaths *l = thePathDefs;
  if (!l)
    return 0;
  h = (char *) malloc (strlen (path) + 2);
  if (!h)
    return 0;
  strcpy (h, path);
  for (p = h; *p != 0; p++)
    if (p[0] == '\\')
      p[0] = '/';
  if (p != h && p[-1] != '/')
    strcat (p, "/");
  while (l != NULL)
    {
      if (!strcmp (l->path, h))
        {
	  free (h);
	  return 1;
        }
      l = l->next;
    }
  free (h);
  return 0;
}

static int
add_path_def (const char *path)
{
  char *h, *p;
  sDefPaths *l;
  h = (char *) malloc (strlen (path) + 2);
  if (!h)
    return 0;
  strcpy (h, path);
  for (p = h; *p != 0; p++)
    if (p[0] == '\\')
      p[0] = '/';
  if (p != h && p[-1] != '/')
    strcat (p, "/");
  l = (sDefPaths *) malloc (sizeof (sDefPaths) + strlen (h) + 1);
  if (!l)
    {
      free (h);
      return 0;
    }
  memset (l, 0, sizeof (sDefPaths));
  strcpy (l->path, h);
  free (h);
  l->next = thePathDefs;
  thePathDefs = l;
  return 1;
}

