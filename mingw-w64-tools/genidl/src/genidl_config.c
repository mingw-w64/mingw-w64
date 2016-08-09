/*
    genidl - Generate interface defintion language listing from a
    Portable Executable.
    Copyright (C) 2009-2016  mingw-w64 project

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "genidl_cfg.h"

#define TOK_NAME  256
#define TOK_DIGIT 257
#define TOK_STRING 258

static sCfgLib *gen_cfglib (const char *);
static sCfgLib *has_cfglib (const char *, int);
static sCfgAlias *gen_cfglib_alias (sCfgLib *, const char *);
static sCfgAlias *has_cfglib_alias (sCfgLib *, const char *);
static sCfgItem *has_cfglib_item (sCfgLib *, const char *);
static sCfgItem *gen_cfglib_item (sCfgLib *, const char *, const char *);

static int rCh (void);
static void bCh (int r);
static int pCh (void);
static int addCh (int r);
#if 0
static void delCh (void);
#endif
static void clrCh (void);
static void printError (const char *fmt, ...);
static int lex (void);

static FILE *conf_fp = NULL;
static int last_ch = -1;
static int line_no = 1;
static int seen_eof = 0;
static char *l_buffer = NULL;
static size_t l_max, l_cur;

static sCfgLib *cfg_head = NULL;
static int is_modified = 0;

static sCfgItem *
has_cfglib_item (sCfgLib *c, const char *name)
{
  sCfgItem *h;
  if (!c || c->item == NULL)
    return NULL;
  h = c->item;
  do {
    if (!strcmp (h->name, name))
      return h;
    h = h->next;
  } while (h != NULL);
  return NULL;
}

static sCfgItem *
gen_cfglib_item (sCfgLib *c, const char *name, const char *type)
{
  sCfgItem *a, *p = NULL, *e = c->item;
  int is_new = 0;
  a = has_cfglib_item (c, name);
  if (!a)
    {
      a = (sCfgItem *) malloc (sizeof (sCfgItem) + strlen (name) + 1);
      memset (a, 0, sizeof (sCfgItem));
      strcpy (a->name, name);
      is_new = 1;
    }
  is_modified = 1;
  if (a->type != NULL)
    free (a->type);
  a->type = strdup (type);
  if (!is_new)
    return a;
  while (e != NULL)
    {
      p = e;
      e = e->next;
    }
  if (!p)
    c->item = a;
  else
    p->next = a;
  return a;
}

static sCfgAlias *
gen_cfglib_alias (sCfgLib *c, const char *name)
{
  sCfgAlias *p, *e;
  sCfgAlias *a = has_cfglib_alias (c, name);
  if (a)
    return a;
  a = (sCfgAlias *) malloc (sizeof (sCfgAlias) + strlen (name) + 1);
  memset (a, 0, sizeof (sCfgAlias));
  strcpy (a->name, name);
  p = NULL; e = c->alias;
  while (e != NULL)
    {
      p = e;
      e = e->next;
    }
  if (!p)
    c->alias = a;
  else
    p->next = a;
  is_modified = 1;
  return a;
}

static sCfgAlias *
has_cfglib_alias (sCfgLib *c, const char *name)
{
  sCfgAlias *a = (c ? c->alias : NULL);
  while (a != NULL)
    {
      if (!strcmp (a->name, name))
        return a;
      a = a->next;
    }
  return NULL;
}

static sCfgLib *
has_cfglib (const char *name, int withAlias)
{
  sCfgLib *r = cfg_head;
  while (r != NULL)
    {
      if (!strcmp (r->name, name))
        return r;
      if (withAlias && has_cfglib_alias (r, name) != NULL)
        return r;
      r = r->next;
    }
  return NULL;
}

static sCfgLib *
gen_cfglib (const char *name)
{
  sCfgLib *r, *p, *e;
  if ((r = has_cfglib (name, 0)) != NULL)
    return r;
  r = (sCfgLib *) malloc (sizeof (sCfgLib) + strlen (name) + 1);
  memset (r, 0, sizeof (sCfgLib));
  strcpy (r->name, name);
  p = NULL; e = cfg_head;
  while (e != NULL)
    {
      p = e; e = e->next;
    }
  if (!p) cfg_head = r;
  else p->next = r;
  is_modified = 1;
  return r;
}

static void
printError (const char *fmt, ...)
{
  va_list argp;
  va_start (argp, fmt);
  fprintf (stderr, "configfile at ");
  if (l_buffer[0] == 0 && seen_eof)
    fprintf (stderr, "end of file");
  else if (l_buffer[0] == 0)
    fprintf (stderr, "start of file");
  else
    fprintf (stderr, "line %d near ,%s'", line_no, l_buffer);
  fprintf (stderr, ": ");
  vfprintf (stderr, fmt, argp);
  va_end (argp);
}

static int
lex (void)
{
  int r;

rescan:
  clrCh ();
  do {
   r = rCh ();
  } while (r >= 0 && r <= 0x20);

  if (r == -1)
    return -1;
  if (r == '/' && pCh () == '*')
    {
      rCh ();
      while ((r=rCh ()) != -1)
        {
	  if (r == '*' && pCh () == '/')
            {
	      rCh ();
	      break;
	    }
        }
      goto rescan;
    }
  else if (r == '/' && pCh () == '/')
    {
      while ((r=rCh ()) != -1)
        {
          if (r == '\n')
	    break;
        }
      goto rescan;
    }
  if (r == '_' || (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z'))
    {
      bCh (r);
      do {
	addCh (rCh ());
	r = pCh ();
      } while (r == '_' || (r >= 'a' && r <= 'z') || (r >= 'A' && r <= 'Z')
	       || (r >= '0' && r <= '9') || r == '$' || r == '.');
      return TOK_NAME;
    }
  if (r >= '0' && r <= '9')
    {
      addCh (r);
      if (r == '0')
	{
	  switch (pCh ()) {
	    case 'x': case 'X': addCh (rCh ()); break;
	    case 'o': case 'O': addCh (rCh ()); break;
	    case 'b': case 'B': addCh (rCh ()); break;
	    default:
	      break;
	  }
	}
      return TOK_DIGIT;
    }
  if (r == '"')
    {
      while ((r = pCh ()) != -1 && r != '"' && r != '\n')
	addCh (rCh ());
      if (r != '"')
	printError ("Missing '\"' at end of string.\n");
      else
	rCh ();
      return TOK_STRING;
    }
  addCh (r);
  switch (r)
  {
  case '=': case '{': case '}': case ',':
  case ';':
    return r;
  default:
    break;
  }
  printError ("Illegal character found.\n");
  goto rescan;
}
   
static void
clrCh (void)
{
  l_cur = 0;
  l_buffer[0] = 0;
}

#if 0
static void
delCh (void)
{
  if (l_cur == 0)
    return;
  --l_cur;
  l_buffer[l_cur] = 0;
}
#endif

static int
addCh (int r)
{
  if (r == -1)
    return r;
  if (l_cur == l_max)
    {
      char *h = (char *) realloc (l_buffer, l_max + 129);
      if (!h)
        abort ();
      l_max += 128;
    }
  l_buffer[l_cur++] = (char) r;
  l_buffer[l_cur] = 0;
  return r;
}

static int
pCh (void)
{
  int r = last_ch;
  if (r != -1)
    return r;
  r = rCh ();
  if (r != -1)
    bCh (r);
  return r;
}

static void
bCh (int r)
{
  if (r == '\n')
    line_no--;
  last_ch = r;
}

static int
rCh (void)
{
  int r;
  if ((r = last_ch) == -1)
    {
       char ch;
       if (seen_eof || feof (conf_fp))
         return -1;
       if (fread (&ch, 1, 1, conf_fp) != 1)
         return -1;
       r = ((int) ch) & 0xff;
    }
  else
    last_ch = -1;
  if (r == '\r')
    r = rCh ();
  if (r == '\n')
    line_no++;
  return r;
}

static char **
parse_export (sCfgLib *cfg, int *re, const char *tname)
{
  char **ret = NULL;
  int r = lex ();
  if (r == '=')
    r = lex ();
  if (r != '{')
    {
      printError ("Missing '{' for alias in ,%s'\n", tname);
      *re = r;
      return ret;
    }
  while ((r = lex ()) != -1)
    {
      if (r == '}')
	break;
      if (r == ',' || r == ';')
	continue;
      if (r == TOK_NAME || r == TOK_STRING)
	{
	  char *left = strdup (l_buffer);

	  r = lex ();
	  if (r == ',' || r == '=')
	    r = lex ();
	  if (r != TOK_NAME && r != TOK_STRING)
	    {
	      printError ("Expected in export second string.\n");
	    }
	  else
	    {
	      gen_cfglib_item (cfg, left, l_buffer);
	    }
	  free (left);
	}
      else
	printError ("Ignore token in alias of ,%s'.\n", tname);
    }
  return ret;
}

static char **
parse_alias (sCfgLib *cfg, int *re, const char *tname)
{
  char **ret = NULL;
  int r = lex ();
  if (r == '=')
    r = lex ();
  if (r != '{')
    {
      printError ("Missing '{' for alias in ,%s'\n", tname);
      *re = r;
      return ret;
    }
  while ((r = lex ()) != -1)
    {
      if (r == '}')
	break;
      if (r == ',' || r == ';')
	continue;
      if (r == TOK_NAME || r == TOK_STRING)
	{
	  gen_cfglib_alias (cfg, l_buffer);
	}
      else
	printError ("Ignore token in alias of ,%s'.\n", tname);
    }
  return ret;
}

static int
parseTableSub (const char *tname)
{
  char **alias = NULL;
  char **exps;
  int r = lex ();
  sCfgLib *cfg = gen_cfglib (tname);
  while (r != '}')
    {
      if (r == ';')
	{
	  r = lex ();
	  continue;
	}
      if (r != TOK_NAME)
      {
	printError ("Unknown content in ,%s'\n", tname);
	break;
      }
      if (strcmp (l_buffer, "alias")  == 0)
        {
	  alias = parse_alias (cfg, &r, tname);
	  if (r == -1)
	    break;
        }
      else if (strcmp (l_buffer, "export") == 0)
        {
	  exps = parse_export (cfg, &r, tname);
	  if (r == -1)
	    break;
        }
      else
      {
	printError ("Unknown command %s in ,%s'\n", l_buffer, tname);
	while ((r = lex ()) != -1 && r != ';');
      }
      r = lex ();
    }
  if (r != '}')
    {
    }
  return r;
}

static int
parseTable (void)
{
  char *table_name;
  int r = lex ();

  if (r == ';')
    return 0;

  switch (r)
    {
    case TOK_NAME:
    case TOK_STRING:
      table_name = strdup (l_buffer);
      break;
    case -1:
      return -1;
    default:
      printError ("Unexpected token.\n");
      return 0;
    }
  r = lex ();
  if (r == '=')
    r = lex ();
  if (r != '{')
    {
      printError ("Missing '{' after ,%s'\n", table_name);
      free (table_name);
      return 0;
    }
  r = parseTableSub (table_name);
  if (r != '}')
    printError ("Missing '}' at end of ,%s'\n", table_name);
  free (table_name);
  return 0;
}

static void
parseStmt (void)
{
  int r;

  while ((r = parseTable ()) != -1)
  {
  }
}


int
genidl_read_config (const char *fname)
{
  if (!fname)
    return -1;
  conf_fp = fopen (fname, "rb");
  if (!conf_fp)
    return -1;
  l_buffer = (char *) malloc (129);
  if (!l_buffer)
    {
      fclose (conf_fp);
      return -1;
    }
  l_max = 128;
  l_cur = 0;
  l_buffer[0] = 0;
  line_no = 1;
  seen_eof = 0;
  parseStmt ();
  is_modified = 0;
  free (l_buffer);
  fclose (conf_fp);
  return 0;
}

int
genidl_save_config (const char *file)
{
  FILE *fp;
  int ret;

  if (!genidl_ismodified_config ())
    return 1;
  if (!file)
    return 0;
  fp = fopen (file, "wb");
  ret = !genidl_save_config_fp (fp);
  if (fp)
    fclose (fp);
  is_modified = 0;
  return ret;
}

int
genidl_save_config_fp (FILE *fp)
{
  sCfgLib *h = cfg_head;
  sCfgAlias *alias;
  sCfgItem *item;

  if (!fp)
    return 1;
  fprintf (fp, "/* Configuration of genidl tool.  */\n");
  if (!h)
    return 0;
  do {
    alias = h->alias;
    item = h->item;
    fprintf (fp, "\"%s\" = {\n", h->name);
    if (alias)
      {
        fprintf (fp,"  alias = {\n");
        do {
          fprintf (fp, "    \"%s\"%s\n", alias->name, (alias->next != NULL ? "," : ""));
          alias = alias->next;
        } while (alias);
        fprintf (fp, "  };\n");
      }
    if (item)
      {
        fprintf (fp, "  export = {\n");
        do {
          fprintf (fp, "    \"%s\" = \"%s\";\n", item->name, item->type);
          item = item->next;
        } while (item);
        fprintf (fp, "  };\n");
      }
    fprintf (fp, "};\n\n");
    h = h->next;
  } while (h != NULL);
  return 0;
}

int
genidl_ismodified_config (void)
{
  return is_modified;
}

int
genidl_add_lib (const char *lib)
{
  if (!lib || *lib == 0)
    return 0;
  if (gen_cfglib (lib))
    return 1;
  return 0;
}

int
genidl_add_lib_alias (const char *lib, const char *alias)
{
  sCfgLib *l;
  if (!lib || *lib == 0 || !alias || *alias == 0)
    return 0;
  l = gen_cfglib (lib);
  if (!l)
    return 0;
  if (gen_cfglib_alias (l, alias))
    return 1;
  return 0;
}

int
genidl_add_lib_item (const char *lib, const char *name, const char *typ)
{
  sCfgLib *l;
  if (!lib || *lib == 0 || !name || *name == 0 || !typ || *typ == 0)
    return 0;
  l = gen_cfglib (lib);
  if (!l)
    return 0;
  if (gen_cfglib_item (l, name, typ))
    return 1;
  return 0;
}

const char *
genidl_find_type (const char *lib, const char *name)
{
  sCfgLib *l;
  sCfgItem *h;
  char *is_tlb;

  if (!lib || *lib == 0)
    return NULL;
  is_tlb = strstr (lib, ".tlb");
  if (is_tlb)
    {
      sCfgLib *r = cfg_head;
      while (r != NULL)
	{
	  if (!strcmp (r->name, lib))
	    {
	      sCfgAlias *a = r->alias;
	      while (a != NULL)
		{
		  const char *rs = genidl_find_type (a->name, name);
		  if (rs != NULL)
		    return rs;
		  a = a->next;
		}
	    }
	  r = r->next;
	}
      return NULL;
    }
  l = has_cfglib (lib, 1);
  if (!l)
    return NULL;
  h = has_cfglib_item (l, name);
  if (!h)
    return NULL;
  return h->type;
}

int
genidl_del_lib_item (const char *lib)
{
  sCfgLib *l;
  sCfgItem *h;
  if (!lib || *lib == 0)
    return 0;
  l = gen_cfglib (lib);
  if (!l)
    return 1;
  if (l->item == NULL)
    return 1;
  while ((h = l->item) != NULL)
    {
      l->item = h->next;
      if (h->type)
        free (h->type);
      free (h);
    }
  return 1;
}
