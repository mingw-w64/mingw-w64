/*
    genidl - Generate interface listing from a Portable Executable.
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

#define _CRT_SECURE_NO_WARNINGS
#include "genidl_cfg.h"
#include "genidl_readpe.h"
#include "genidl_typeinfo.h"
#include "genidl_typinfo.h"
#include "fsredir.h"

/* Configure globals.  */
int show_dump_too = 0;
int generate_header = 0;
int is_verbose = 0;

/* Process files.  */
size_t file_args_cnt = 0;
char **file_args = NULL;
const char *basedumpname = "";

static char *get_idl_basename (const char *file);

#ifdef REDIRECTOR
static int use_redirector = 0; /* Use/Disable FS redirector */
#endif

static void
show_usage (void)
{
  fprintf (stderr, "Usage: genidl [OPTION]... [FILE]...\n");
  fprintf (stderr, "Dumps IDL information from typelib data found in PE32/PE32+ executables and\n"
                   "TLB files.\n");
  fprintf (stderr, "\n");
  fprintf (stderr, "Options:\n"
    "  -b ARG, --basedumpname=ARG\n"
    "                           Specify ARG as prefix of generated idl files.\n"
    "  -H, --header				Generate header\n"
    "  -d, --dump               Dump additional internal debugging information.\n"
    "  -v, --verbose            Show additional status prints.\n"
    "  -h, --help               Show this help.\n"
#ifdef REDIRECTOR
    "  -r, --disable-fs-redirector\n"
    "                           Disable Win64 FS redirection, for 32-bit\n"
    "                           gendef on 64-bit Windows\n"
#endif
  );
  fprintf (stderr, "\nReport bugs to <mingw-w64-public@lists.sourceforge.net>\n");
  exit (1);
}

static int
scanArgs (int argc, char **argv)
{
  int seen_error = 0;
  if (!argc)
    return -1;
  file_args = (char **) malloc (sizeof (char *) * argc);
  while (argc > 0)
    {
      char *h = *argv;
      if (h[0]  == '-')
	{
	  h++;
	  switch (*h) {
      case '-': /* Long arguments section */
        h++;
        switch (*h) {
		case 'H':
		  generate_header = 1;
		  break;
        case 'd':
            if(! strcmp (h, "dump"))
                {
                    show_dump_too = 1;
                    break;
                }
            else
                goto unknown_fail;
        case 'h':
        	if (!strcmp (h, "header"))
        	  {
				  generate_header = 1;
				  break;
			  }
            if (!strcmp (h, "help")) return -2;
            goto unknown_fail;
        case 'v':
	    if (! strcmp (h, "verbose"))
	       is_verbose++;
	    else
	      goto unknown_fail;
	    break;
        case 'b':
            if (! strncmp(h, "basedumpname=", 13))
                {
                    basedumpname = &(h[13]);
                    break;
                }
            else
                goto unknown_fail;
#ifdef REDIRECTOR
        case 'r':
            if(! strcmp (h, "disable-fs-redirector"))
                {
                    use_redirector = 1;
                    break;
                }
            else
                goto unknown_fail;
#endif
        default: goto unknown_fail;
        }
        break;
        /* Short arguments section */
	  case 'd':
	    if (h[1] == 0)
	      show_dump_too = 1;
	    else
	      goto unknown_fail;
	    break;
	  case 'h':
	    if (h[1] == 0)
	      return -2;
	       goto unknown_fail;
	  case 'b':
	    if (h[1] == 0)
	      {
		basedumpname = *(++argv);
		--argc;
		break;
	      }
	    goto unknown_fail;
	  case 'v':
	    if (h[1] != 0)
	      goto unknown_fail;
	    is_verbose++;
	    break;
#ifdef REDIRECTOR
	  case 'r':
	    if (h[1] != 0)
	      goto unknown_fail;
	    use_redirector = 1;
	    break;
#endif
	  default:
unknown_fail:
	    fprintf (stderr, "Option %s' is unknown.\n", *argv);
	    seen_error = 1;
	    break;
	  }
	}
      else
	{
	  file_args[file_args_cnt++] = *argv;
	}
      --argc;
      ++argv;
    }
  if (seen_error || file_args_cnt == 0)
    return -2;
  return 0;
}

int main(int argc,char **argv)
{
  FILE *fp,*gp;
  long p;
  int32_t be64;
  size_t len;
  size_t i;
  unsigned char *dta = NULL;
  genidl_read_config ("./genidl.conf");
  if (scanArgs (--argc, ++argv) < 0)
    {
       show_usage ();
    }
#ifdef REDIRECTOR
  doredirect(use_redirector);
#endif
  for (i = 0; i < file_args_cnt; i++)
    {
      char s[1024], *idl_basename,*org_basename;
      int start, end;
      gp = fopen (file_args[i], "rb");
      if (!gp)
	{
	  fprintf (stderr, "Failed to open file ,%s'.\n", file_args[i]);
	  continue;
	}
      p = genidl_ispe (gp, &be64);

      if (is_verbose)
        fprintf (stderr, "Found PE at %ld (%s bits)\n", p, !be64 ? "32" : "64");

      end = genidl_pe_typelib_resource_count (gp);

      if (is_verbose)
	fprintf (stderr, "Contains %d typelib resource(s)\n", end);
      org_basename = get_idl_basename (file_args[i]);
      idl_basename = strdup (org_basename);
      if (strrchr (idl_basename, '.') != NULL)
	*strrchr (idl_basename, '.') = 0;

      for (start = 0; start < end; start++)
	{
	  genidl_pe_typelib_resource_read (gp, start, &dta, &len);
	  if (generate_header == 0)
	  {
	    if (end != 1)
	      sprintf (s, "%s%s_%d.idl", idl_basename, basedumpname, start);
	    else
	      sprintf (s, "%s%s.idl", idl_basename, basedumpname);
	    fp = fopen (s, "wb");
	    if (fp)
	      {
		sTI2TypLib *tl = TI2_typlib_init (dta, (size_t) len);
		if (tl)
	      {
		TI2_typlib_idl (fp, tl, org_basename);
		TI2_typlib_dest (tl);
	      }
	      if (show_dump_too)
		dumpInfo (fp, dta, len);
	      fclose (fp);
	    }
	}
	else if (generate_header == 1)
	{
	    if (end != 1)
	      sprintf (s, "%s%s_%d.h", idl_basename, basedumpname, start);
	    else
	      sprintf (s, "%s%s.h", idl_basename, basedumpname);
	    fp = fopen (s, "wb");
	    if (fp)
		  {
		    sTI2TypLib *tl = TI2_typlib_init (dta, (size_t) len);
		    if (tl)
		  {
		    TI2_typlib_hdr (fp, tl, org_basename);
		    TI2_typlib_dest (tl);
		  }
		  fclose (fp);
		}
	    }
	}
	free (idl_basename);
	free (org_basename);
	fclose (gp);
      }
  /* genidl_save_config_fp (stderr); */
  genidl_save_config ("./genidl.conf");
  return 0;
}

static char *
get_idl_basename (const char *file)
{
  char *h, *p;
  if (!file || *file == 0)
    return strdup ("");
  h = strrchr (file, '\\');
  p = strrchr (file, '/');
  if (!h && !p)
    h = strdup (file);
  else if (!h)
    h = strdup (p + 1);
  else if (!p)
    h = strdup (h + 1);
  else if (p < h)
    h = strdup (h + 1);
  else
    h = strdup (p + 1);
  genidl_strlwr (h);
  return h;
}

char *
genidl_strlwr (char *s)
{
  char *h = s;
  if (!h)
    return NULL;
  while (*h != 0)
    {
      if (h[0] >= 'A' && h[0] <= 'Z')
        h[0] = (h[0] - 'A') + 'a';
      ++h;
    }

  return s;
}
