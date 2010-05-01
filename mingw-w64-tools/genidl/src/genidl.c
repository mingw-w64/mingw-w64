/*
 This Software is provided under the Zope Public License (ZPL) Version 2.1.

 Copyright (c) 2009, 2010 by the mingw-w64 project

 Written by Kai Tietz.

 This license has been certified as open source. It has also been designated
 as GPL compatible by the Free Software Foundation (FSF).

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

   1. Redistributions in source code must retain the accompanying copyright
      notice, this list of conditions, and the following disclaimer.
   2. Redistributions in binary form must reproduce the accompanying
      copyright notice, this list of conditions, and the following disclaimer
      in the documentation and/or other materials provided with the
      distribution.
   3. Names of the copyright holders must not be used to endorse or promote
      products derived from this software without prior written permission
      from the copyright holders.
   4. The right to distribute this software or to use it for any purpose does
      not give you the right to use Servicemarks (sm) or Trademarks (tm) of
      the copyright holders.  Use of them is covered by separate agreement
      with the copyright holders.
   5. If any files are modified, you must cause the modified files to carry
      prominent notices stating that you changed the files and the date of
      any change.

 Disclaimer

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY EXPRESSED
 OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
 EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY DIRECT, INDIRECT,
 INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define _CRT_SECURE_NO_WARNINGS
#include "genidl_cfg.h"
#include "genidl_readpe.h"
#include "genidl_typeinfo.h"
#include "genidl_typinfo.h"
#include "fsredir.h"

/* Configure globals.  */
int show_dump_too = 0;
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
        case 'd':
            if(! strcmp (h, "dump"))
                {
                    show_dump_too = 1;
                    break;
                }
            else
                goto unknown_fail;
        case 'h':
            if(! strcmp (h, "help")) return -2;
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
