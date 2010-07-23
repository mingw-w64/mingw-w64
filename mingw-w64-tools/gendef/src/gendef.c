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
#include "fsredir.h"
#ifdef HAVE_LIBMANGLE
#include <libmangle.h>
#endif

#define ENABLE_DEBUG 0

#if ENABLE_DEBUG == 1
#define PRDEBUG(ARG...)  fprintf(stderr,ARG)
#else
#define PRDEBUG(ARG...) do { } while(0)
#endif

static void decode_mangle (FILE *fp, const char *n);
static int load_pep (void);
static void do_pedef (void);
static void do_pepdef (void);
static void do_import_read32 (uint32_t va_imp, uint32_t sz_imp);
static void do_export_read (uint32_t va_exp,uint32_t sz_exp,int be64);
static void add_export_list (uint32_t ord,uint32_t func,const char *name, const char *forward,int be64,int beData);
static void dump_def (void);
static int disassembleRet (uint32_t func,uint32_t *retpop,const char *name, sImportname **ppimpname, int *seen_ret);
static size_t getMemonic (int *aCode,uint32_t pc,volatile uint32_t *jmp_pc,const char *name, sImportname **ppimpname);

static sImportname *imp32_add (const char *dll, const char *name, uint32_t addr, uint16_t ord);
static void imp32_free (void);
static sImportname *imp32_findbyaddress (uint32_t addr);

static sImportname *theImports = NULL;

static void *map_va (uint32_t va);
static int is_data (uint32_t va);
static int is_reloc (uint32_t va);

static int disassembleRetIntern (uint32_t pc, uint32_t *retpop, sAddresses *seen, sAddresses *stack,
				 int *hasret, int *atleast_one, const char *name, sImportname **ppimpname);
static sAddresses*init_addr (void);
static void dest_addr (sAddresses *ad);
static int push_addr (sAddresses *ad,uint32_t val);
static int pop_addr (sAddresses *ad,uint32_t *val);

static sExportName *gExp = NULL;
static sExportName *gExpTail = NULL;
char *fninput;
char *fnoutput;
char *fndllname;

size_t gDta_size;
unsigned char *gDta;
PIMAGE_DOS_HEADER gMZDta;
PIMAGE_NT_HEADERS32 gPEDta;
PIMAGE_NT_HEADERS64 gPEPDta;

#ifdef REDIRECTOR
static int use_redirector = 0; /* Use/Disable FS redirector */
#endif

static int std_output = 0;
static int assume_stdcall = 0; /* Set to one, if function symbols should be assumed to have stdcall.  */
static int no_forward_output = 0; /* Set to one, if in .def files forwarders shouldn't be displayed.  */

static Gendefopts *chain_ptr = NULL;
 __attribute__((noreturn)) static void show_usage (void);
static int opt_chain (const char *, const char *);

static int
opt_chain (const char *opts, const char *next)
{
  static Gendefopts *prev, *current;
  char *r1, *r2;
  
  if (!strncmp (opts, "-", 2))
    {
      std_output = 1;
      return 0;
    }
  if (!strcmp (opts, "--help") || !strcmp (opts, "-h"))
    {
      show_usage();
      return 0;
    }
  if (!strcmp (opts, "--assume-stdcall") || !strcmp (opts, "-a"))
    {
      assume_stdcall = 1;
      return 0;
    }
  if (!strcmp (opts, "--include-def-path") || !strcmp (opts, "-I"))
    {
      if (!next)
        {
	  fprintf (stderr, "Error: %s expects path as next arguement.", opts);
	  return 0;
        }
      gendef_addpath_def (next);
      return 1;
    }
  if (!strcmp (opts, "--no-forward-output") || !strcmp (opts, "-f"))
    {
      no_forward_output = 1;
      return 0;
    }

#ifdef REDIRECTOR
  if (!strcmp (opts, "--disable-fs-redirector") || !strcmp (opts, "-r"))
    {
      use_redirector = 1;
      return 0;
    }
#endif

  current = malloc (sizeof(Gendefopts));
  if (current)
    {
      memset (current, 0, sizeof (Gendefopts));
      current->next = NULL;

      if (!prev)
        chain_ptr = current;
      else
        prev->next = current;
      r1 = strrchr (opts,'/');
      r2 = strrchr (opts,'\\');
      current->fninput = strdup (opts);
      
      if (!r1 && r2 != NULL)
        r1 = r2 + 1;
      else if(r1 == NULL && r2 == NULL)
        r1 = current->fninput;
      else if (r2 != NULL && r1 != NULL && r1 < r2)
        r1 = r2 + 1;
      else
        r1++;
      current->fnoutput = (char *) malloc (strlen (current->fninput) + 5);
      strcpy (current->fnoutput,r1);

      r1 = strrchr (current->fnoutput,'.');
      if (r1)
        strcpy (r1,".def");
      else
        strcat (current->fnoutput,".def");
      prev = current;
   }
  return 0;
}

void
show_usage (void)
{
  fprintf (stderr, "Usage: gendef [OPTION]... [DLL]...\n");
  fprintf (stderr, "Dumps DLL exports information from PE32/PE32+ executables\n");
  fprintf (stderr, "\n");
  fprintf (stderr, "Options:\n"
    "  -                        Dump to stdout\n"
    "  -h, --help               Show this help.\n"
    "  -a, --assume-stdcall     Assume functions with ambiguous call\n"
    "                           convention as stdcall.\n"
    "  -I, --include-def-path <path>\n"
    "                           Add additional search paths to find\n"
    "                           hint .def files.\n"
    "  -f, --no-forward-output  Don't output forwarders in .def file\n"
#ifdef REDIRECTOR
    "  -r, --disable-fs-redirector\n"
    "                           Disable Win64 FS redirection, for 32-bit\n"
    "                           gendef on 64-bit Windows\n"
#endif
  );
  fprintf (stderr, "\n");
  fprintf (stderr, "Usage example: \n"
                   "  By default, the output files are named after their DLL counterparts\n"
                   "  gendef MYDLL.DLL     Produces MYDLL.def\n"
                   "  gendef - MYDLL.DLL   Prints the exports to stdout\n");
  fprintf (stderr, "\nBuilt on %s\n", __DATE__);
  fprintf (stderr, "\nReport bugs to <mingw-w64-public@lists.sourceforge.net>\n");
  exit (0);
}

int main(int argc,char **argv)
{
  int i;
  Gendefopts *opt;

  if (argc < 2)
  {
    show_usage ();
    return 0;
  }

  for (i = 1; i < argc; i++)
    i += opt_chain (argv[i], ((i+1) < argc ? argv[i+1] : NULL));
#ifdef REDIRECTOR
  doredirect(use_redirector);
#endif
  opt = chain_ptr;
  while (opt)
    {
      fninput = opt->fninput;
      fnoutput = opt->fnoutput;

      if (load_pep ())
        {
	  if (gPEDta || gPEPDta)
	    {
	      if (gPEDta)
		do_pedef ();
	      else
		do_pepdef ();
	      dump_def ();
	    }
	}
      if (fndllname)
	free (fndllname);
      fndllname = NULL;
      if (gDta)
	{
	  free (gDta);
	  gDta = NULL;
	}
      free(opt->fninput);
      free(opt->fnoutput);
      free(opt);
      opt = opt->next;
    }
  return 0;
}

static int
load_pep (void)
{
  FILE *fp = fopen (fninput, "rb");

  if (!fp)
    {
      fprintf (stderr, "*** [%s] failed to open()\n", fninput);
      return 0;
    }
  fseek (fp, 0, SEEK_END);
  gDta_size = (size_t) ftell (fp);
  if (gDta_size > 0) {
    fseek (fp,0,SEEK_SET);
    gDta = (unsigned char *) malloc (gDta_size + 1);
    if (gDta)
      {
        if (fread (gDta, gDta_size, 1, fp) != 1)
	  {
	    free (gDta);
	    gDta = NULL;
	  }
	else
          gDta[gDta_size] = 0;
    }
  }
  fclose (fp);
  if (!gDta)
    {
      fprintf (stderr, "*** [%s] unable to allocate %lu bytes\n", fninput,
	       (unsigned long) gDta_size);
      return 0;
    }
  gMZDta = (PIMAGE_DOS_HEADER) gDta;
  if (gDta_size < sizeof(IMAGE_DOS_HEADER) || gDta[0]!='M' || gDta[1]!='Z'
      || gMZDta->e_lfanew <= 0
      || gMZDta->e_lfanew >= (int32_t) gDta_size)
  {
    fprintf(stderr,"*** [%s] not a PE(+) file\n", fninput);
    free(gDta);
    gDta = NULL;
    return 0;
  }
  gPEDta = (PIMAGE_NT_HEADERS32) &gDta[gMZDta->e_lfanew];
  gPEPDta = (PIMAGE_NT_HEADERS64) gPEDta;
  if (gPEDta->Signature != IMAGE_NT_SIGNATURE)
    {
      fprintf (stderr, "*** [%s] no PE(+) signature\n", fninput);
      free (gDta);
      gDta = NULL;
      gPEPDta = NULL;
      gPEDta = NULL;
      return 0;
    }
  if (gPEDta->FileHeader.SizeOfOptionalHeader == IMAGE_SIZEOF_NT_OPTIONAL32_HEADER
      && gPEDta->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR32_MAGIC)
    {
      gPEPDta = NULL;
      fprintf (stderr, " * [%s] Found PE image\n", fninput);
    }
  else if (gPEPDta->FileHeader.SizeOfOptionalHeader == IMAGE_SIZEOF_NT_OPTIONAL64_HEADER
    && gPEPDta->OptionalHeader.Magic == IMAGE_NT_OPTIONAL_HDR64_MAGIC)
    {
      gPEDta = NULL;
      fprintf (stderr, " * [%s] Found PE+ image\n", fninput);
    }
  else
    {
      free (gDta);
      gDta = NULL;
      fprintf (stderr, "*** [%s] no PE(+) optional header\n", fninput);
      gPEPDta = NULL;
      gPEDta = NULL;
      return 0;
    }
  return 1;
}

static int
is_data (uint32_t va)
{
  PIMAGE_SECTION_HEADER sec;
  uint32_t sec_cnt,i;

  /* If export va is directly relocated, so it must be data.  */  
  if (is_reloc (va))
    return 1;
  
  if (gPEDta)
    {
      sec_cnt = gPEDta->FileHeader.NumberOfSections;
      sec = IMAGE_FIRST_SECTION(gPEDta);
    }
  else
    {
      sec_cnt = gPEPDta->FileHeader.NumberOfSections;
      sec = IMAGE_FIRST_SECTION(gPEPDta);
    }
  if (!sec)
    return 0;
  for (i = 0;i < sec_cnt;i++)
    {
      if (va >= sec[i].VirtualAddress && va < (sec[i].VirtualAddress+sec[i].Misc.VirtualSize))
        break;
    }
  if (i == sec_cnt)
    return 0; 
  if ((sec[i].Characteristics & (IMAGE_SCN_MEM_EXECUTE | IMAGE_SCN_CNT_CODE)) != 0)
    return 0;
  if ((sec[i].Characteristics & IMAGE_SCN_MEM_DISCARDABLE) != 0)
    return 1;
  if ((sec[i].Characteristics & IMAGE_SCN_MEM_READ) ==0)
    return 0;
  if ((sec[i].Characteristics & (IMAGE_SCN_CNT_INITIALIZED_DATA | IMAGE_SCN_CNT_UNINITIALIZED_DATA | IMAGE_SCN_LNK_COMDAT)) != 0)
    return 1;
  return 1;
}

static int
is_reloc (uint32_t va)
{
  uint32_t va_rel, sz_rel, pos;
  unsigned char *p;
  PIMAGE_BASE_RELOCATION brel;

  if (gPEDta)
    {
      va_rel = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
      sz_rel = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;
    }
  else
    {
      va_rel = gPEPDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].VirtualAddress;
      sz_rel = gPEPDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC].Size;
    }
  if (va_rel == 0 || sz_rel < IMAGE_SIZEOF_BASE_RELOCATION)
    return 0;
  p = (unsigned char *) map_va (va_rel);
  for (pos = 0; pos < sz_rel;)
    {
      uint16_t *r;
      uint32_t nums, j;
      if ((sz_rel - pos) < IMAGE_SIZEOF_BASE_RELOCATION)
        break;
      brel = (PIMAGE_BASE_RELOCATION) &p[pos];
      if (brel->SizeOfBlock == 0)
         break;
      pos += IMAGE_SIZEOF_BASE_RELOCATION;
      nums = (brel->SizeOfBlock - IMAGE_SIZEOF_BASE_RELOCATION) / 2;
      r = (uint16_t *) &p[pos];
      if (va >= brel->VirtualAddress && va < (brel->VirtualAddress + 0x1008))
        {
          for (j = 0; j < nums; j++)
            {
              uint32_t relsz = 0;
              uint32_t offs = (uint32_t) (r[j] & 0xfff) + brel->VirtualAddress;
              uint16_t typ = (r[j] >> 12) & 0xf;
              if (typ == IMAGE_REL_BASED_HIGHADJ)
                j++;
              switch (typ)
                {
                case IMAGE_REL_BASED_HIGHLOW:
                  relsz = 4;
                  break;
                case IMAGE_REL_BASED_DIR64:
                  relsz = 8;
                  break;
                }
              if (relsz != 0 && va >= offs && va < (offs + relsz))
                return 1;
            }
        }
      pos += (brel->SizeOfBlock - IMAGE_SIZEOF_BASE_RELOCATION);
    }
  return 0;
}

static void *
map_va (uint32_t va)
{
  PIMAGE_SECTION_HEADER sec;
  uint32_t sec_cnt,i;
  char *dptr;

  if (gPEDta)
    {
      sec_cnt = gPEDta->FileHeader.NumberOfSections;
      sec = IMAGE_FIRST_SECTION(gPEDta);
    }
  else
    {
      sec_cnt = gPEPDta->FileHeader.NumberOfSections;
      sec = IMAGE_FIRST_SECTION(gPEPDta);
    }
  for (i = 0;i < sec_cnt;i++)
    {
      if (va >= sec[i].VirtualAddress && va < (sec[i].VirtualAddress+sec[i].Misc.VirtualSize))
        {
          dptr = (char *) &gDta[va-sec[i].VirtualAddress+sec[i].PointerToRawData];
          return (void *)dptr;
        }
    }
  return NULL;
}

/* For pep we can take the exports itself, there is no additional decoration necessary.  */
static void
do_pepdef (void)
{
  uint32_t va_exp = gPEPDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
  uint32_t sz_exp = gPEPDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;

  do_export_read (va_exp, sz_exp, 1);
}

static void
do_pedef (void)
{
  uint32_t va_exp = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
  uint32_t sz_exp = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].Size;
  uint32_t va_imp = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].VirtualAddress;
  uint32_t sz_imp = gPEDta->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT].Size;

  imp32_free ();
  do_import_read32 (va_imp, sz_imp);
  do_export_read (va_exp, sz_exp, 0);
}

static void
do_import_read32 (uint32_t va_imp, uint32_t sz_imp)
{
  IMAGE_IMPORT_DESCRIPTOR *pid;
  if (!sz_imp || !va_imp)
    return;
  pid = (IMAGE_IMPORT_DESCRIPTOR *) map_va (va_imp);
  while (pid != NULL && sz_imp >= 20 && pid->Name != 0 && pid->OriginalFirstThunk != 0)
    {
      uint32_t index = 0;
      PIMAGE_THUNK_DATA32 pIAT;
      PIMAGE_THUNK_DATA32 pFT;
      char *imp_name = (char *) map_va (pid->Name);

      for (;;) {
	char *fctname;
	pIAT = (PIMAGE_THUNK_DATA32) map_va (pid->OriginalFirstThunk + index);
	pFT = (PIMAGE_THUNK_DATA32) map_va (pid->FirstThunk + index);
	if (pIAT->u1.Ordinal == 0 || pFT->u1.Ordinal == 0)
	  break;
	if (IMAGE_SNAP_BY_ORDINAL32 (pIAT->u1.Ordinal))
	  fctname = NULL;
	else
	  fctname = (char *) map_va (pIAT->u1.Function + 2);
	if (fctname)
	  imp32_add (imp_name, fctname,
	  //pid->OriginalFirstThunk + index + gPEDta->OptionalHeader.ImageBase,
	  pid->FirstThunk + index + gPEDta->OptionalHeader.ImageBase,
	    *((uint16_t *) map_va (pIAT->u1.Function)));
	index += 4;
      }
      sz_imp -= 20;
      va_imp += 20;
      if (sz_imp >= 20)
	pid = (IMAGE_IMPORT_DESCRIPTOR *) map_va (va_imp);
    }
}

static sImportname *
imp32_findbyaddress (uint32_t addr)
{
  sImportname *h = theImports;
  while (h != NULL && h->addr_iat != addr)
    h = h->next;
  return h;
}

static void
imp32_free (void)
{
  while (theImports != NULL)
    {
      sImportname *h = theImports;
      theImports = theImports->next;
      if (h->dll)
	free (h->dll);
      if (h->name)
	free (h->name);
      free (h);
    }
}

static sImportname *
imp32_add (const char *dll, const char *name, uint32_t addr, uint16_t ord)
{
  sImportname *n = (sImportname *) malloc (sizeof (sImportname));
  memset (n, 0, sizeof (sImportname));
  n->dll = strdup (dll);
  n->name = strdup (name);
  n->ord = ord;
  n->addr_iat = addr;
  n->next = theImports;
  theImports = n;
  return n;
}

static void
do_export_read (uint32_t va_exp, uint32_t sz_exp, int be64)
{
  uint32_t i;
  PIMAGE_EXPORT_DIRECTORY exp_dir;
  uint32_t *functions;
  uint16_t *ordinals;
  uint32_t *name;

  if (va_exp == 0 || sz_exp == 0)
    return;
  exp_dir = (PIMAGE_EXPORT_DIRECTORY) map_va (va_exp);
  PRDEBUG(" * export directory at VA = 0x%x size=0x%x\n", (unsigned int) va_exp, (unsigned int) sz_exp);
  fndllname = strdup ((char *) map_va (exp_dir->Name));
  PRDEBUG(" * Name: %s\n * Base: %u\n", fndllname, (unsigned int) exp_dir->Base);
  functions = (uint32_t *) map_va (exp_dir->AddressOfFunctions);
  ordinals = (uint16_t *) map_va (exp_dir->AddressOfNameOrdinals);
  name = (uint32_t *) map_va (exp_dir->AddressOfNames);
  
  for (i = 0;i < exp_dir->NumberOfFunctions;i++)
    {
      uint32_t entryPointRVA = functions[i];
      uint32_t j;
      char *fname;
      uint32_t ord;
      fname = NULL;
      if (!entryPointRVA)
        continue;
      ord = i + exp_dir->Base;
      for (j = 0;j < exp_dir->NumberOfNames;j++)
        if (ordinals[j]==i)
          fname = (char *) map_va (name[j]);
      if (entryPointRVA >= va_exp && entryPointRVA <= (va_exp + sz_exp))
        add_export_list (ord, 0, fname,(char *) map_va (entryPointRVA), be64, 0);
      else
        add_export_list(ord, entryPointRVA, fname, NULL, be64, is_data (entryPointRVA));
    }
}

static void
add_export_list(uint32_t ord,uint32_t func,const char *name, const char *forward,int be64,int beData)
{
  sExportName *exp = NULL;

  if (!name)
    name = "";
  if (!forward)
    forward = "";
  exp = (sExportName *) malloc (sizeof (sExportName) + strlen (name) + strlen (forward) + 2);
  if (!exp)
    return;
  exp->name = (char *) &exp[1];
  exp->forward = exp->name + strlen (name) + 1;
  strcpy (exp->name, name);
  strcpy (exp->forward, forward);
  exp->next = NULL;
  exp->ord = ord;
  exp->func = func;
  exp->be64 = be64;
  exp->beData = beData;
  exp->retpop = (uint32_t)-1;
  if (gExpTail)
    gExpTail->next = exp;
  else
    gExp = exp;
  gExpTail = exp;
}

static void
dump_def (void)
{
  sExportName *exp;
  FILE *fp;

  if (!fndllname || gExp == NULL)
    return;
  if (!std_output)
    fp = fopen(fnoutput,"wt");
  else
    fp = stdout;
  if(!fp) {
    fprintf(stderr," * failed to create %s ...\n",fnoutput);
    return;
  }
  fprintf (fp,";\n; Definition file of %s\n; Automatic generated by gendef\n; written by Kai Tietz 2008\n;\n",
    fndllname);
  fprintf (fp,"LIBRARY \"%s\"\nEXPORTS\n",fndllname);
  while ((exp = gExp) != NULL)
    {
      sImportname *pimpname;
      int seen_ret;
      seen_ret = 1;
      gExp = exp->next;
      if (exp->name[0] == '?')
        {
          decode_mangle (fp, exp->name);
        }
      if (exp->name[0] == 0)
        fprintf (fp, "ord_%u", (unsigned int) exp->ord);
      else
        fprintf (fp, "%s", exp->name);
      if (exp->name[0] == '?' && exp->name[1] == '?')
        {
          if (!strncmp (exp->name, "??_7", 4))
	    exp->beData = 1;
        }
      pimpname = NULL;
      if (!exp->beData && !exp->be64 && exp->func != 0)
	{
	  seen_ret = 0;
	  exp->beData = disassembleRet (exp->func, &exp->retpop, exp->name, &pimpname, &seen_ret);
        }
      if (!exp->be64 && exp->retpop == (uint32_t) -1 && pimpname)
	{
	  int isD = 0;
	  uint32_t at = 0;
	  if (gendef_getsymbol_info (pimpname->dll, pimpname->name, &isD, &at))
	    {
	      exp->beData = isD;
	      if (!isD)
		exp->retpop = at;
	    }
	}
      else if (exp->func == 0 && !exp->beData)
	{
	  int isD = 0;
	  uint32_t at = 0;
	  if (gendef_getsymbol_info (exp->forward, NULL, &isD, &at))
	    {
	      exp->beData = isD;
	      if (!isD)
	        exp->retpop = at;
	    }
	}

      if (exp->be64)
        exp->retpop = 0;

      if (exp->retpop != (uint32_t) -1 && !exp->be64)
        {
          if (exp->name[0]=='?')
            fprintf(fp," ; has WINAPI (@%u)", (unsigned int) exp->retpop);
          else
            fprintf(fp,"@%u", (unsigned int) exp->retpop);
        }
      if (exp->func == 0 && no_forward_output == 0)
	fprintf (fp, " = %s", exp->forward);
      if (exp->name[0] == 0)
        fprintf(fp," @%u", (unsigned int) exp->ord);
      if (exp->beData)
        fprintf(fp," DATA");

      if (exp->retpop != (uint32_t) -1 || (exp->be64 && exp->retpop == 0))
	{
	}
      else if (pimpname)
        {
	  fprintf (fp, " ; Check!!! forwards to %s in %s (ordinal %u)",
	    pimpname->name, pimpname->dll, pimpname->ord);
        }
      else if (exp->func == 0 && !exp->beData)
	{
	  fprintf (fp, " ; Check!!! forwards to %s", exp->forward);
	}
      else if (seen_ret == 0 && !exp->beData)
        {
	  fprintf (fp, " ; Check!!! Couldn't determine function argument count. Function doesn't return. ");
        }
      fprintf(fp,"\n");
      free (exp);
    }
  gExpTail=NULL;
  if (!std_output)
    fclose(fp);
}

static sAddresses *
init_addr (void)
{
  sAddresses *r = (sAddresses*) malloc (sizeof (sAddresses));
  r->max = 8;
  r->cnt = 0;
  r->ptrs = (uint32_t *) malloc (sizeof (uint32_t) * 8);
  r->idx = 0;
  return r;
}

static void
dest_addr (sAddresses *ad)
{
  free (ad->ptrs);
  free (ad);
}

static int
push_addr (sAddresses *ad, uint32_t val)
{
  uint32_t i;

  for (i = 0;i < ad->cnt; i++)
    {
      if (ad->ptrs[i] == val)
        return 0;
    }
  if (ad->max == ad->cnt)
    {
      uint32_t *p = (uint32_t *) malloc (sizeof (uint32_t) * (ad->max + 8));

      memcpy (p, ad->ptrs, sizeof (uint32_t) * ad->max);
      ad->max += 8;
      free (ad->ptrs);
      ad->ptrs = p;
    }
  ad->ptrs[ad->cnt++] = val;
  return 1;
}

static int
pop_addr (sAddresses *ad, uint32_t *val)
{
  if (!ad || ad->idx == ad->cnt)
    return 0;
  ad->idx++;
  *val = ad->ptrs[ad->idx-1];
  return 1;
}

/* exp->beData */
static int
disassembleRet (uint32_t func, uint32_t *retpop, const char *name, sImportname **ppimpname, int *seen_ret)
{
  sAddresses *seen = init_addr ();
  sAddresses *stack = init_addr ();
  uint32_t pc;
  int hasret = 0;
  int atleast_one = 0;

  *retpop = (uint32_t) -1;
  push_addr (stack, func);

  while (!hasret && pop_addr (stack,&pc))
    {
      if (disassembleRetIntern (pc, retpop, seen, stack, &hasret, &atleast_one, name, ppimpname))
        break;
    }
  *seen_ret = hasret;
  dest_addr (seen);
  dest_addr (stack);
  return (atleast_one ? 0 : 1);
}

static int
disassembleRetIntern (uint32_t pc, uint32_t *retpop, sAddresses *seen, sAddresses *stack,
		      int *hasret, int *atleast_one, const char *name, sImportname **ppimpname)
{
  size_t sz = 0;
  int code = 0,break_it = 0;
  volatile uint32_t tojmp = 0;

  while(1)
    {
      if (!push_addr (seen, pc))
        return 0;
      sz = getMemonic (&code, pc, &tojmp, name, ppimpname) & 0xffffffff;
      if (!sz || code == c_ill)
        {
          PRDEBUG(" %s = 0x08%x ILL (%u) at least one==%d\n",name,
	 	  (unsigned int) pc, (unsigned int) sz,atleast_one[0]);
#if ENABLE_DEBUG == 1
      {
        unsigned char *ppc = (unsigned char *) map_va (pc);
        size_t i;

        fprintf (stderr, "%s(0x%x): ",name, (unsigned int) pc);
        for (i = 0;i < sz; i++)
          {
            fprintf (stderr, "%s0x%x", (i == 0 ? " ":","), ppc[i]);
          }
        fprintf (stderr, "\n");
      }
      exit (0);
#endif
          break;
        }
#if ENABLE_DEBUG == 1
      {
        unsigned char *ppc = (unsigned char *) map_va (pc);
        size_t i;

        fprintf (stderr, "%s(0x%x): ",name, (unsigned int) pc);
        for (i = 0;i < sz; i++)
          {
            fprintf (stderr, "%s0x%x", (i == 0 ? " ":","), ppc[i]);
          }
        fprintf (stderr, "\n");
      }
#endif
      atleast_one[0] += 1;
      break_it = 0;
      pc += sz;
      switch(code)
        {
        case c_jmpnjb: case c_jmpnjv:
          pc = tojmp;
          break;
        case c_jxx:
          push_addr (stack, tojmp);
          break;
        case c_jmpfap: case c_int3:
          break_it = 1;
          break;
        case c_iret: case c_retf: case c_retn:
          *hasret = 1;
          if (assume_stdcall)
            *retpop = 0;
          return 1;
        case c_retflw: case c_retnlw:
          *hasret = 1;
          *retpop = tojmp;
          return 1;
        }
      if (break_it)
        break;
    }

  return 0;
}

static int opMap2[256] = {
  c_EG,c_EG,c_EG,c_EG,c_1,c_1,c_ill,c_ill, /* 0x00-0x07 */
  c_1,c_1,c_ill,c_ill,c_ill,c_ill,c_ill,c_ill, /* 0x08-0x0f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x10-0x17 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x18-0x1f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_ill,c_EG,c_ill, /* 0x20-0x27 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x28-0x2f */
  c_1,c_1,c_1,c_1,c_1,c_1,c_ill,c_1, /* 0x30-0x37 */
  c_ill,c_ill,c_ill,c_ill,c_ill,c_ill,c_ill,c_ill, /* 0x38-0x3f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x40-0x47 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x48-0x4f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x50-0x57 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x58-0x5f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x60-0x67 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x68-0x6f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x70-0x77 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x78-0x7f */
  c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv, /* 0x80-0x87 */
  c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv,c_jxxv, /* 0x88-0x8f */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x90-0x97 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x98-0x9f */
  c_1,c_1,c_1,c_EG,c_EGlb,c_EG,c_ill,c_ill, /* 0xa0-0xa7 */
  c_1,c_1,c_1,c_EG,c_EGlb,c_EG,c_EG,c_EG, /* 0xa8-0xaf */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xb0-0xb7 */
  c_EG,c_1,c_EGlb,c_EG, c_EG,c_EG,c_EG,c_EG, /* 0xb8-0xbf */
  c_EG,c_EG,c_EGlb,c_EG,c_EGlb,c_EGlb,c_EGlb,c_EG, /* 0xc0-0xc7 */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0xc8-0xcf */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xd0-0xd7 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xd8-0xdf */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xe0-0xe7 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xe8-0xef */
  c_ill,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xf0-0xf7 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_ill /* 0xf8-0xff */
};

static int opMap1[256] = {
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x00-0x07 */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_0f, /* 0x08-0x0f */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x10-0x17 */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x18-0x1f */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x20-0x27 */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x28-0x2f */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x30-0x37 */
  c_EG,c_EG,c_EG,c_EG,c_lb,c_lv,c_1,c_1, /* 0x38-0x3f */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0x40-0x47 */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0x48-0x4f */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0x50-0x57 */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0x58-0x5f */
  c_1,c_1,c_EG,c_EG,c_1,c_1,c_op,c_ad, /* 0x60-0x67 */
  c_lv,c_EGlv,c_lb,c_EGlb,c_1,c_1,c_1,c_1, /* 0x68-0x6f */
  c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx, /* 0x70-0x77 */
  c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx,c_jxx, /* 0x78-0x7f */
  c_EGlb,c_EGlv,c_EGlb,c_EGlb,c_EG,c_EG,c_EG,c_EG, /* 0x80-0x87 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0x88-0x8f */
  c_1,c_1,c_1,c_1,c_1,c_1,c_1,c_1, /* 0x90-0x97 */
  c_1,c_1,c_callfar,c_1,c_1,c_1,c_1,c_1, /* 0x98-0x9f */
  c_O,c_O,c_O,c_O,c_1,c_1,c_1,c_1, /* 0xa0-0xa7 */
  c_lb,c_lv,c_1,c_1,c_1,c_1,c_1,c_1, /* 0xa8- 0xaf */
  c_2,c_2,c_2,c_2,c_2,c_2,c_2,c_2, /* 0xb0-0xb7 */
  c_lv,c_lv,c_lv,c_lv,c_lv,c_lv,c_lv,c_lv, /* 0xb8-0xbf */
  c_EGlb,c_EGlb,c_retnlw,c_retn,c_EG,c_EG,c_EGlb,c_EGlv, /* 0xc0-0xc7 */
  c_4,c_1,c_retflw,c_retf,c_int3,c_2,c_1,c_iret, /* 0xc8-0xcf */
  c_EG,c_EG,c_EG,c_EG,c_2,c_2,c_1,c_1, /* 0xd0-0xd7 */
  c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG,c_EG, /* 0xd8-0xdf */
  c_jxx,c_jxx,c_jxx,c_jxx,c_2,c_2,c_2,c_2, /* 0xe0-0xe7 */
  c_calljv,c_jmpnjv,c_jmpfap,c_jmpnjb,c_1,c_1,c_1,c_1, /* 0xe8-0xef */
  c_1,c_1,c_1,c_1, c_1,c_1,c_EGg3b,c_EGg3v, /* 0xf0-0xf7 */
  c_1,c_1,c_1,c_1,c_1,c_1,c_g4,c_g4 /* 0xf8-0xff */
};

#if ENABLE_DEBUG == 1

#define MAX_INSN_SAVE	20

static void
enter_save_insn (unsigned char *s, unsigned char b)
{
  int i;
  for (i=0;i<MAX_INSN_SAVE-1;i++)
    s[i]=s[i+1];
  s[MAX_INSN_SAVE-1]=b;
}

static void
print_save_insn (const char *name, unsigned char *s)
{
  int i;
  
  PRDEBUG("From %s: ",name);
  for (i=0;i<MAX_INSN_SAVE;i++)
  {
    PRDEBUG("%s0x%x",(i!=0 ? "," : ""), (unsigned int) s[i]);
  }
}
#endif

static size_t
getMemonic(int *aCode,uint32_t pc,volatile uint32_t *jmp_pc, __attribute__((unused)) const char *name, sImportname **ppimpname)
{
#if ENABLE_DEBUG == 1
  static unsigned char lw[MAX_INSN_SAVE];
#endif
  unsigned char *p;
  int addr_mode = 1;
  int oper_mode = 1;
  size_t sz = 0;
  unsigned char b;
  int tb1;

  for(;;) {
    p = (unsigned char *) map_va (pc + sz);
    if (!p) { *aCode=c_ill; return 0; }
    b = p[0];
    if (b==0x26 || b==0x2e || b==0x36 || b==0x3e || b==0x64 || b==0x65)
      ++sz;
    else if (b==0x66) { oper_mode^=1; sz++; }
    else if (b==0x67) { addr_mode^=1; sz++; }
    else if (b==0xf2 || b==0xf3 || b==0xf0) sz++;
    else break;
  }
  sz++;
  tb1=opMap1[(unsigned int) b];
  
redo_switch:
#if ENABLE_DEBUG == 1
  if (tb1!=c_ill) { enter_save_insn(lw,b); }
#endif
  switch (tb1) {
  case c_ill:
#if ENABLE_DEBUG == 1
    print_save_insn (name, lw);
    PRDEBUG(" 0x%x illegal ", (unsigned int) b);
#endif
    *aCode=c_ill; return 0;
  case c_4: sz++;
  case c_3: sz++;
  case c_lb:
  case c_2: sz++;
  case c_retn: case c_retf:
  case c_iret: case c_int3:
  case c_ad: case c_op:
  case c_1: *aCode=tb1; return sz;
  case c_lv:
    if (oper_mode) sz+=4;
    else sz+=2;
    *aCode=tb1; return sz;
  case c_O: case c_calljv:
    if (addr_mode) sz+=4;
    else sz+=2;
    *aCode=tb1; return sz;
  case c_EG: case c_EGlv: case c_EGlb: case c_g4: case c_EGg3v: case c_EGg3b:
    p = (unsigned char *) map_va (pc + sz);
    sz++;
    if (!p) { *aCode=c_ill; return 0; }
    b = p[0];
#if ENABLE_DEBUG == 1
    enter_save_insn(lw,b);
#endif
    if (addr_mode) {
      if((b&0xc0)!=0xc0 && (b&0x7)==4)
        {
          p = (unsigned char *) map_va (pc + sz);
          if (!p) { *aCode=c_ill; return 0; }
#if ENABLE_DEBUG == 1
    enter_save_insn(lw,p[0]);
#endif
          b&=~0x7; b|=(p[0]&7);
	  sz+=1;
	}
      if((b&0xc0)==0 && (b&7)==5)
        {
	  /* Here we check if for jmp instruction it points to an IAT entry.  */
	  if(tb1==c_g4 && ((b&0x38)==0x20 || (b&0x38)==0x28))
	    {
	      uint32_t vaddr;
	      sImportname *inss;
	      vaddr = *((uint32_t *) map_va (pc + sz));
	      inss = imp32_findbyaddress (vaddr);
	      if (inss)
		*ppimpname = inss;
	    }
	  sz+=4;
        }
      else if((b&0xc0)==0x40)
	sz+=1;
      else if((b&0xc0)==0x80)
	sz+=4;
    } else {
      if((b&0xc0)==0) {
	if((b&0x07)==6) sz+=2;
      } else if((b&0xc0)==0x40)
	sz+=1;
      else if((b&0xc0)==0x80)
	sz+=2;
    }
    if (tb1==c_EGlv) sz+=(oper_mode ? 4 : 2);
    else if(tb1==c_EGlb) sz++;
    else if(tb1==c_g4) {
      if ((b&0x38)==0x20 || (b&0x38)==0x28)
	tb1=c_int3;
      else if((b&0x38)==0x38)
        tb1=c_ill;
    } else if (tb1==c_EGg3v || tb1==c_EGg3b) {
      switch (((b&0x38)>>3)) {
      case 1:
      case 0: sz+= (tb1==c_EGg3v ? (oper_mode ? 4 : 2) : 1); break;
      default: break;
      }
    }
    *aCode=tb1; return sz;
  case c_jxx: case c_jmpnjb:
    p = (unsigned char *) map_va (pc + sz);
    if (!p) { *aCode=c_ill; return 0; }
    b = p[0];
    sz++;
    jmp_pc[0]=(uint32_t) pc + (uint32_t) sz;
    if ((b&0x80)!=0)
      jmp_pc[0] = jmp_pc[0] + (((uint32_t) b) | 0xffffff00);
    else
      jmp_pc[0] = jmp_pc[0] + (uint32_t) b;
    *aCode=tb1; return sz;
  case c_jmpnjv:
  case c_jxxv: 
    p = (unsigned char *) map_va (pc + sz);
    if (!p) { *aCode=c_ill; return 0; }
    if (oper_mode) { jmp_pc[0]=*((uint32_t *)p); sz+=4; }
    else {
      jmp_pc[0]=(uint32_t) *((uint16_t *)p);
      if ((jmp_pc[0]&0x8000)!=0) jmp_pc[0]|=0xffff0000;
      sz+=2;
    }
    jmp_pc[0]+=(uint32_t) pc+(uint32_t) sz;
#if ENABLE_DEBUG == 1
    if ((jmp_pc[0]&0xff000000)!=0) {
      print_save_insn (name, lw);
      PRDEBUG(" 0x%x illegal ", (unsigned int) b);
      PRDEBUG("jmp(cond) 0x%x (sz=%x,pc=%x,off=%x) ",
	      jmp_pc[0], (unsigned int) sz,(unsigned int) pc,
              (unsigned int) (jmp_pc[0]-(sz+pc)));
    }
#endif
    *aCode=(tb1==c_jxxv ? c_jxx : tb1);
    return sz;
  case c_0f:
    p = (unsigned char *) map_va (pc + sz);
    if (!p) { *aCode=c_ill; return 0; }
    b = p[0];
    sz++;
    tb1=opMap2[b];
    goto redo_switch;
  case c_jmpfap:
    sz+=4; if(oper_mode) sz+=2;
    *aCode=tb1; return sz;
  case c_callfar:
    sz+=4; if(oper_mode) sz+=2;
    *aCode=tb1; return sz;
  case c_retflw: case c_retnlw:
    p = (unsigned char *) map_va (pc + sz);
    if (!p) { *aCode=c_ill; return 0; }
    jmp_pc[0]=*((uint16_t*) p);
    sz+=2;
    *aCode=tb1;
#if ENABLE_DEBUG == 1
    if (jmp_pc[0]>0x100 || jmp_pc[0]&3) {
      print_save_insn (name, lw);
      PRDEBUG(" 0x%x illegal ", (unsigned int) b);
      PRDEBUG("ret dw 0x%x (sz=%x) ", (unsigned int) jmp_pc[0], (unsigned int) sz);
    }
#endif
    return sz;
  default:
    PRDEBUG(" * opcode 0x%x (tbl=%d) unknown\n", (unsigned int) b, tb1);
    sz=0; *aCode=c_ill; break;
  }
  return sz;
}

static void
decode_mangle (FILE *fp, const char *n)
{
#ifdef HAVE_LIBMANGLE
  libmangle_gc_context_t *gc = libmangle_generate_gc ();
  libmangle_tokens_t ptok;
#endif
  if (!fp || !n || *n == 0)
    return;
#ifdef HAVE_LIBMANGLE
  ptok = libmangle_decode_ms_name (gc, n);
  if (ptok)
    {
      char *h = libmangle_sprint_decl (ptok);
      if (h)
	{
	  fprintf (fp, "; %s\n", h);
	  free (h);
	}
    }
  libmangle_release_gc (gc);
#endif
}
