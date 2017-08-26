/* Copyright (C) 1995-2015 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#include "deflex.h" 
#include "genlib.h"
#include <string.h>
#include <libgen.h>

typedef struct ifunct
{
  char *         name;   /* Name of function being imported.  */
  char *     its_name;	 /* Optional import table symbol name.  */
  int            ord;    /* Two-byte ordinal value associated with function.  */
  struct ifunct *next;
} ifunctype;

typedef struct iheadt
{
  char *         dllname;  /* Name of dll file imported from.  */
  long           nfuncs;   /* Number of functions in list.  */
  struct ifunct *funchead; /* First function in list.  */
  struct ifunct *functail; /* Last  function in list.  */
  struct iheadt *next;     /* Next dll file in list.  */
} iheadtype;

/* Structure containing all import information as defined in .def file
   (qv "ihead structure").  */

static iheadtype *import_list = NULL;


typedef struct dlist
{
  char *text;
  struct dlist *next;
}dlist_type;

typedef struct export
{
  const char *name;
  const char *internal_name;
  const char *import_name;
  const char *its_name;
  int ordinal;
  int constant;
  int noname;		/* Don't put name in image file.  */
  int private;	/* Don't put reference in import lib.  */
  int data;
  int hint;
  int forward;	/* Number of forward label, 0 means no forward.  */
  struct export *next;
}export_type;

char *def_file;
char *dll_name;

/**********************************************************************/

/* Communications with the parser.  */

int d_nfuncs;		/* Number of functions exported.  */
//static int d_named_nfuncs;	/* Number of named functions exported.  */
//static int d_low_ord;		/* Lowest ordinal index.  */
//static int d_high_ord;		/* Highest ordinal index.  */
export_type *d_exports;	/* List of exported functions.  */
//static export_type **d_exports_lexically;  /* Vector of exported functions in alpha order.  */
static dlist_type *d_list;	/* Descriptions.  */
static dlist_type *a_list;	/* Stuff to go in directives.  */
static int d_nforwards = 0;	/* Number of forwarded exports.  */

static int d_is_dll;
static int d_is_exe;

int
yyerror (const char * err __attribute__ ((__unused__)))
{
  PRDEBUG("Syntax error in def file %s:%d", def_file, linenumber);
  return 0;
}

void
def_exports (const char *name, const char *internal_name, int ordinal,
	     int noname, int constant, int data, int private,
	     const char *its_name)
{
  struct export *p = (struct export *) malloc (sizeof (*p));

  p->name = name;
  p->internal_name = internal_name ? internal_name : name;
  p->its_name = its_name;
  p->import_name = name;
  p->ordinal = ordinal;
  p->constant = constant;
  p->noname = noname;
  p->private = private;
  p->data = data;
  p->next = d_exports;
  d_exports = p;
  d_nfuncs++;

  if ((internal_name != NULL)
      && (strchr (internal_name, '.') != NULL))
    p->forward = ++d_nforwards;
  else
    p->forward = 0; /* no forward */
}

static void
set_dll_name_from_def (const char *name, char is_dll)
{
  const char *image_basename = basename ((char*)name);
  if (image_basename != name)
    PRDEBUG("%s: Path components stripped from image name, '%s'\n",
	      def_file, name);
  /* Append the default suffix, if none specified.  */ 
  if (strchr (image_basename, '.') == 0)
    {
      const char * suffix = is_dll ? ".dll" : ".exe";

      dll_name = malloc (strlen (image_basename) + strlen (suffix) + 1);
      sprintf (dll_name, "%s%s", image_basename, suffix);
    }
  else
    dll_name = strdup (image_basename);
}

void
def_name (const char *name, int base)
{
  PRDEBUG("NAME: %s base: %x", name, base);

  /* If --dllname not provided, use the one in the DEF file.
     FIXME: Is this appropriate for executables?  */
  if (!dll_name)
    set_dll_name_from_def (name, 0);
  d_is_exe = 1;
}

void
def_library (const char *name, int base)
{
  PRDEBUG("LIBRARY: %s base: %x\n", name, base);

  /* If --dllname not provided, use the one in the DEF file.  */
  if (!dll_name)
    set_dll_name_from_def (name, 1);
  d_is_dll = 1;
}

void
def_description (const char *desc)
{
  dlist_type *d = (dlist_type *) malloc (sizeof (dlist_type));
  d->text = strdup (desc);
  d->next = d_list;
  d_list = d;
}

static void
new_directive (char *dir)
{
  dlist_type *d = (dlist_type *) malloc (sizeof (dlist_type));
  d->text = strdup (dir);
  d->next = a_list;
  a_list = d;
}

void
def_heapsize (int reserve, int commit)
{
  char b[200];
  if (commit > 0)
    sprintf (b, "-heap 0x%x,0x%x ", reserve, commit);
  else
    sprintf (b, "-heap 0x%x ", reserve);
  new_directive (strdup (b));
}

void
def_stacksize (int reserve, int commit)
{
  char b[200];
  if (commit > 0)
    sprintf (b, "-stack 0x%x,0x%x ", reserve, commit);
  else
    sprintf (b, "-stack 0x%x ", reserve);
  new_directive (strdup (b));
}

/* append_import simply adds the given import definition to the global
   import_list.  It is used by def_import.  */

static void
append_import (const char *symbol_name, const char *dllname, int func_ordinal,
	       const char *its_name)
{
  iheadtype **pq;
  iheadtype *q;

  for (pq = &import_list; *pq != NULL; pq = &(*pq)->next)
    {
      if (strcmp ((*pq)->dllname, dllname) == 0)
	{
	  q = *pq;
	  q->functail->next = malloc (sizeof (ifunctype));
	  q->functail = q->functail->next;
	  q->functail->ord  = func_ordinal;
	  q->functail->name = strdup (symbol_name);
	  q->functail->its_name = (its_name ? strdup (its_name) : NULL);
	  q->functail->next = NULL;
	  q->nfuncs++;
	  return;
	}
    }

  q = malloc (sizeof (iheadtype));
  q->dllname = strdup (dllname);
  q->nfuncs = 1;
  q->funchead = malloc (sizeof (ifunctype));
  q->functail = q->funchead;
  q->next = NULL;
  q->functail->name = strdup (symbol_name);
  q->functail->its_name = (its_name ? strdup (its_name) : NULL);
  q->functail->ord  = func_ordinal;
  q->functail->next = NULL;

  *pq = q;
}

/* def_import is called from within defparse.y when an IMPORT
   declaration is encountered.  Depending on the form of the
   declaration, the module name may or may not need ".dll" to be
   appended to it, the name of the function may be stored in internal
   or entry, and there may or may not be an ordinal value associated
   with it.  */

/* A note regarding the parse modes:
   In defparse.y we have to accept import declarations which follow
   any one of the following forms:
     <func_name_in_app> = <dll_name>.<func_name_in_dll>
     <func_name_in_app> = <dll_name>.<number>
     <dll_name>.<func_name_in_dll>
     <dll_name>.<number>
   Furthermore, the dll's name may or may not end with ".dll", which
   complicates the parsing a little.  Normally the dll's name is
   passed to def_import() in the "module" parameter, but when it ends
   with ".dll" it gets passed in "module" sans ".dll" and that needs
   to be reappended.

  def_import gets five parameters:
  APP_NAME - the name of the function in the application, if
             present, or NULL if not present.
  MODULE   - the name of the dll, possibly sans extension (ie, '.dll').
  DLLEXT   - the extension of the dll, if present, NULL if not present.
  ENTRY    - the name of the function in the dll, if present, or NULL.
  ORD_VAL  - the numerical tag of the function in the dll, if present,
             or NULL.  Exactly one of <entry> or <ord_val> must be
             present (i.e., not NULL).  */

void
def_import (const char *app_name, const char *module, const char *dllext,
	    const char *entry, int ord_val, const char *its_name)
{
  const char *application_name;
  char *buf;

  if (entry != NULL)
    application_name = entry;
  else
    {
      if (app_name != NULL)
	application_name = app_name;
      else
	application_name = "";
    }

  if (dllext != NULL)
    {
      buf = (char *) alloca (strlen (module) + strlen (dllext) + 2);
      sprintf (buf, "%s.%s", module, dllext);
      module = buf;
    }

  append_import (application_name, module, ord_val, its_name);
}

void
def_version (int major, int minor)
{
  PRDEBUG(("VERSION %d.%d\n"), major, minor);
}

void
def_section (const char *name, int attr)
{
  char buf[200];
  char atts[5];
  char *d = atts;
  if (attr & 1)
    *d++ = 'R';

  if (attr & 2)
    *d++ = 'W';
  if (attr & 4)
    *d++ = 'X';
  if (attr & 8)
    *d++ = 'S';
  *d++ = 0;
  sprintf (buf, "-attr %s %s", name, atts);
  new_directive (strdup (buf));
}

void
def_code (int attr)
{

  def_section ("CODE", attr);
}

void
def_data (int attr)
{
  def_section ("DATA", attr);
}

/**********************************************************************/
