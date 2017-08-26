/*
    genlib - Create a COFF short import lib from a list of exported symbols.
    Copyright (c) 2015 Martell Malone

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

/*
  About:

  1. does not need an assembler (its standalone)
  2. just needs to have a def file and arch you want to create the lib

  ALPHA VERSION

  This code has been matched to the coding styles of gendef which is why fprintf is used (a lot).
  We should replace this with structs and allocations in memory before writing to disk for
  cleaner code, better performance and ease of use. (Will do this at some point :)

  There is some very hacky code here btw :)

  HISTORY:

  version 1.0: initial support for PECOFF short import libs
  version 1.1: added support for long names members (i.e dll's longer then 15 characters)

  IN PROGRESS: Alias support

  TODO: DATA type support in .def
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif
#ifdef HAVE_INTTYPES_H
#include <inttypes.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "genlib.h"
#include "deflex.h"
#ifdef HAVE_LIBMANGLE
#include <libmangle.h>
#endif

extern char *def_file;
extern char *dll_name;

char *base_name;
uint16_t machine_type;
time_t time_now;

/* Must unify into 1 header */
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
  uint32_t data;
  uint32_t hint;
  int forward;	/* Number of forward label, 0 means no forward.  */
  struct export *next;
}export_type;

extern int d_nfuncs;
extern export_type *d_exports;

static int load_def (char *);
static int dump_def (void);
static void dump_lib (char *);

static void dump_ialnm (FILE *fp);
static void dump_iamh (FILE *fp, uint32_t size, char *name);
static void dump_ialm1 (FILE *fp, uint32_t id, uint32_t nid, uint32_t ntd);
static void dump_ialm2 (FILE *fp, uint32_t id, uint32_t nid, uint32_t ntd);
static void dump_slif (FILE *fp, export_type *exp, uint16_t count);
static void dump_ifh (FILE *fp, uint16_t nsects, uint32_t nsymbols, uint32_t offset);

static void dump_ish2 (FILE *fp, uint32_t offset, uint32_t reloc);
static void dump_ish3 (FILE *fp, uint32_t offset);
static void dump_ish4 (FILE *fp, uint32_t offset);
static void dump_ish5 (FILE *fp, uint32_t offset);
static void dump_ish6 (FILE *fp, uint32_t offset, uint32_t reloc);

#include <getopt.h>
#include <time.h>
#include <string.h>

// string.h
char *
xstrdup (const char *string)
{
  return strcpy (malloc (strlen (string) + 1), string);
}

static const char usage_string[] =
"Usage: genlib [options...] infile.def\n"
"   or: genlib [options...] infile.def liboutfile.a\n"
"   -a arch            Set the target architecture\n"
"   -o output          Set the output library name\n"
"   -d dllname         Set the input dll name\n"
"   -V                 Print version and exit\n"
"Usage example:\n"
"  By default, the output file is named after the DLL counterpart\n"
"  genlib mydef.def    Produces libmydll.a\n"
"\nBuilt on " __DATE__ "\n"
"\nReport bugs to <martellmalone@gmail.com>\n"
;

static const char version_string[] =
"Short Import Library Compiler version " PACKAGE_VERSION "\n"
"Copyright 2015 Martell Malone\n";

static const struct option long_options[] = {
    { "arch",    required_argument, NULL, 'a' },
    { "output",  required_argument, NULL, 'o' },
    { "dllname", required_argument, NULL, 'd' },
    { "version", no_argument,       NULL, 'v' },
    { NULL, 0, NULL, 0 }
};

static int set_machine(const char *target)
{
  static const struct
  {
      const char *name;
      uint16_t    type;
  } machine_names[] =
  {
    { "x86",     0x014C },
    { "x86_64",  0x8664 },
    { "arm",     0x01C4 },
    { "aarch64", 0xAA64 }
  };

  unsigned int i;
  char *spec = xstrdup(target);

  for (i = 0; i < sizeof(machine_names)/sizeof(machine_names[0]); i++)
  {
    if (!strcmp(machine_names[i].name, spec))
    {
      machine_type = machine_names[i].type;
      free(spec);
      return 0;
    }
    }
    return -1;
}

int main(int argc, char *argv[])
{

  int optc;
  int opti = 0;
  char *arch_name   = NULL;
  char *output_name = NULL;

  time_now = time(NULL);

  while((optc = getopt_long_only(argc, argv, ":a:o:V", long_options, &opti)) != EOF) {
    switch(optc) {
    case 'a':
      arch_name = xstrdup(optarg);
      break;
    case 'o':
      output_name = xstrdup(optarg);
      break;
    case 'd':
      dll_name = xstrdup(optarg);
      break;
    case 'V':
      printf("%s", version_string);
      return 0;
    default:
      fprintf(stderr, "%s", usage_string);
      return 1;
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "%s", usage_string);
    return 1;
  }

  if(arch_name == NULL) {
    printf("Please set the Arch");
    return 1;
  }

  if(set_machine(arch_name) < 0) {
    printf("Invalid Machine Name");
    return 1;
  }

  if (load_def(argv[optind])) {
    dump_def ();
    dump_lib (output_name);
    return 0;
  }
  return -1;
}

static int
load_def (char *fninput)
{
  FILE *fp = fopen (fninput, "r");

  if (!fp)
    {
      fprintf (stderr, "*** [%s] failed to open()\n", fninput);
      return 0;
    }

  yyin = fp;

  PRDEBUG("Parsing def file: %s\n", fninput);
  def_file = fninput;
  yyparse ();
  PRDEBUG("Parsed def file\n");
  return 1;
}

static int
dump_def (void)
{
  export_type *exp;
  PRDEBUG("Number of funcs: %d\n", d_nfuncs);
  PRDEBUG("dll name: %s\n", dll_name);

  for (exp = d_exports; exp; exp = exp->next)
  {
    PRDEBUG("Weak name: %s\n", exp->name);
    //PRDEBUG("Internal name: %s\n", exp->internal_name);
    //PRDEBUG("Import   name: %s\n", exp->import_name);
    if (exp->its_name)
    PRDEBUG("Real name: %s\n", exp->its_name);

    PRDEBUG("ordinal:  %d\n", exp->ordinal);
    PRDEBUG("constant: %d\n", exp->constant);
    PRDEBUG("noname:   %d\n", exp->noname);
    PRDEBUG("private:  %d\n", exp->private);
    PRDEBUG("data:     %d\n", exp->data);
    PRDEBUG("hint:     %d\n", exp->hint);
    PRDEBUG("forward:  %d\n", exp->forward);
  }
  return 0;
}

# define BYTESWAP32(x)   ((((x)&0xFF)<<24) \
         |(((x)>>24)&0xFF) \
         |(((x)&0x0000FF00)<<8)    \
         |(((x)&0x00FF0000)>>8)    )

// 4-> numofsymb
// dnfunc -> x2 *4
// 12-> null thunk
#define OFFSETTABLE1(x) (4+(((x)*2)*4)+12)
// same as offset1 but without __imp_ doubles
#define OFFSETTABLE2(x) (4+((x)*4)+12)

// 4-> numofsymb
// dnfunc -> x2 *2
// 6-> null thunk
#define INDEXTABLE2(x) (4+((x)*2*2)+6)

static inline uint32_t SYMBOLTABLE(export_type *exp)
{
  uint32_t stsize = 0;
  export_type *lexp = 0;
  //MessageBoxA. +1
  //__imp_MessageBoxA. + 7
  // TODO: account for alias later
  for(lexp=exp;lexp;lexp=lexp->next)
    stsize += (strlen(lexp->name)*2) + 8;
  //__IMPORT_DESCRIPTOR_user32. +21
  //__NULL_IMPORT_DESCRIPTOR. +25
  //Xuser32_NULL_THUNK_DATA. +17 +1 at start for \x7f
  stsize += (strlen(base_name)*2) + 21 + 25 + 17 + 1;
  return stsize;
}

#define ARCHIVESYMBOLCOUNT(x) (((x)*2)+4)

static void
dump_lib (char *fnoutput)
{
  export_type *exp;
  base_name = (char *) malloc (strlen (dll_name) - 4);
  strncpy (base_name,dll_name, strlen(dll_name) - 4);

  PRDEBUG("basename:  %s\n", base_name);

  if(!fnoutput)
  {
    fnoutput = (char *) malloc (strlen (dll_name) + 1);
    strcpy (fnoutput,"lib");
    strcat (fnoutput,base_name);
    strcat (fnoutput,".a");
  }

  FILE *fp = fopen(fnoutput,"wb");

  if(!fp)
  {
    fprintf(stderr," * failed to create %s ...\n",fnoutput);
    return;
  }

  // if the weak symbol is the only on set the real name to that
  for (exp = d_exports; exp; exp = exp->next)
  {
    if (!exp->its_name)
      exp->its_name=exp->name;
  }

  uint32_t sizemagic = 8;
  /* MAGIC */
  fprintf (fp,"!<arch>\x0A"); // 21 3C 61 72 63 68 3E 0A

  uint32_t sizelm1;
  sizelm1  = OFFSETTABLE1(d_nfuncs);
  sizelm1 += SYMBOLTABLE(d_exports);

  uint32_t sizelm2;
  sizelm2  = OFFSETTABLE2(d_nfuncs);
  sizelm2 += INDEXTABLE2(d_nfuncs);
  sizelm2 += SYMBOLTABLE(d_exports);

  // TODO: a #define for this
  uint32_t sizelm3;
  sizelm3  = strlen(dll_name) + 1;
  // dont forget to handle odd obj
  if (sizelm3 % 2 != 0)
    sizelm3++;

  // ARCHIVE MEMBER 1 SIZE
  //IFH   = 20;
  //ISH   = 40*2;
  // OFFSET => 100
  //SID2  = 20;
  // RELOC => 120
  //IMGREL = 30
  // OFFSET => 150
  //SID6  = dllname + 1 (+ 1 if odd);
  //OFFSET => 150 + dllname + 1 (+ 1 if odd);
  //SYMT  = 18*8
  //SIZE = 4
  //SYMST = NULL STUFF 76

  uint32_t nidaddr = 4 + 21 + strlen(base_name);
  uint32_t ntdaddr = nidaddr + 25;
  uint32_t idaddr = ntdaddr + 18 + strlen(base_name);

  uint32_t size1even = 0;
  uint32_t sizeam1 = 20 + (40*2) + 20 + 30 + strlen(dll_name) + (18*8) + idaddr;

  // dont forget to handle odd obj
  if (strlen(dll_name) % 2 == 0)
    size1even++;
  sizeam1 +=size1even;

  // ARCHIVE MEMBER 2 SIZE
  //IFH   = 20;
  //ISH   = 40;
  // OFFSET => 60
  //SID3  = 20;
  // OFFSET => 80
  //SYMT  = 18*2
  //SIZE = 4
  //SYMST = __NULL_IMPORT_DESCRIPTOR.
  // was 25 but that is odd
  uint32_t sizeam2 = 20 + 40 + 20 + (18*2) + 4 + 26;

  // ARCHIVE MEMBER 3 SIZE
  //IFH   = 20;
  //ISH   = 40*2;
  // OFFSET => 100
  //SID5  = 8;
  //SID4  = 8;
  // OFFSET => 116
  //SYMT  = 18*2
  //SIZE = 4
  //SYMST = \x7f%s_NULL_THUNK_DATA. base_name + 18

  uint32_t size3even = 0;
  uint32_t sizeam3 = 20 + 40*2 + 16 + (18*2) + 4 + strlen(base_name) + 18;

  // dont forget to handle odd obj
  if (sizeam3 % 2 != 0)
    size3even++;
  sizeam3 +=size3even;

  //TODO: CHECK IF I NEED to add sizelm3 here

  uint32_t id  = sizemagic+sizelm1+sizelm2+120;
  uint32_t nid = sizemagic+sizelm1+sizelm2+sizeam1+181;
  uint32_t ntd = sizemagic+sizelm1+sizelm2+sizeam1+sizeam2+241;

  uint32_t prevhint = sizemagic+sizelm1+sizelm2+sizeam1+sizeam2+sizeam3+301;
  uint32_t prevhelp=0;

  /* SHORT IMPORT LIBRARY ARCHIVE MEMBERS */
  for (exp = d_exports; exp; exp = exp->next)
  {
    prevhint += prevhelp;
    exp->hint = BYTESWAP32(prevhint);
    exp->data = prevhint;
    prevhelp = 60 + 20 + strlen(exp->name) + strlen(dll_name) + 2;
    uint32_t d_imp_size = strlen(exp->name) + strlen(dll_name) + 2;
    if (d_imp_size % 2 != 0)
    {
      prevhelp++;
    }
  }


  /* LINKER MEMBER 1 */
  dump_iamh(fp, sizelm1, NULL);
  dump_ialm1(fp, BYTESWAP32(id), BYTESWAP32(nid), BYTESWAP32(ntd));

  /* LINKER MEMBER 2 */
  dump_iamh(fp, sizelm2, NULL);
  dump_ialm2(fp, id, nid, ntd);

  //TODO: if dllname is 16 chars+ then add IMAGE_ARCHIVES_LONGNAMES_MEMBER
  if(strlen(dll_name) > 15)
  {
    dump_iamh(fp, sizelm3, "//");
    dump_ialnm(fp);
  }


  uint32_t i;

  // ARCHIVE MEMBER 1 (.idata2 + .idata6)
  dump_iamh(fp, sizeam1, dll_name);
  dump_ifh (fp, 2, 8, 150 + strlen(dll_name) + 1 +size1even);
  dump_ish2(fp, 100, 120);
  dump_ish6(fp, 150, 120);

  // .idata2 is blank
  for (i = 0;i < 20; i++)
  {
    fprintf (fp,"%c",'\x00');
  }

  // IMGREL
  fprintf (fp,"%c%c%c%c",'\x0c','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x03','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x04','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  fprintf (fp,"%c%c%c%c",'\x10','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x05','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  //fprintf (fp,"%s", dll_name);
  //uint32_t j;

  //TODO: fix dllname size in idata6 must do size in header also

  fprintf (fp,"%s%c", dll_name, '\x00');

  // If dllname+1 is an odd number append 00 to close (not 0a here for some reason)
  if (strlen(dll_name) % 2 == 0)
      fprintf (fp,"%c", '\x00');

  //for (j=0;j < 12-strlen(dll_name); j++)
  //  fprintf (fp,"%c",'\x00');



  fprintf (fp,"@comp.id");
  //TODO: CHECK WHAT THIS MEANS ??? WHICH ONE ??
  //fprintf (fp,"%c%c%c%c",'\x7d','\x79','\xdd','\x00'); // CHECK LATER
  fprintf (fp,"%c%c%c%c",'\xb4','\x9c','\xef','\x00'); // CHECK LATER
  fprintf (fp,"%c%c%c%c",'\xff','\xff','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  // __IMPORT_DESCRIPTOR_%s
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x04','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x02','\x00');

  fprintf (fp,".idata$2");
  fprintf (fp,"%c%c%c%c",'\x40','\x00','\x00','\xc0');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x68','\x00');

  fprintf (fp,".idata$6");
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x03','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  fprintf (fp,".idata$4");
  fprintf (fp,"%c%c%c%c",'\x40','\x00','\x00','\xc0');
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x68','\x00');

  fprintf (fp,".idata$5");
  fprintf (fp,"%c%c%c%c",'\x40','\x00','\x00','\xc0');
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x68','\x00');

  //__NULL_IMPORT_DESCRIPTOR
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');

  fwrite (&nidaddr, sizeof(uint32_t), 1, fp);
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x00','\x00');

  //X%s_NULL_THUNK_DATA
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');

  fwrite (&ntdaddr, sizeof(uint32_t), 1, fp);
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x00','\x00');

  fwrite (&idaddr, sizeof(uint32_t), 1, fp);
  fprintf (fp,"__IMPORT_DESCRIPTOR_%s%c", base_name, '\x00');
  fprintf (fp,"__NULL_IMPORT_DESCRIPTOR%c", '\x00');
  fprintf (fp,"\x7f%s_NULL_THUNK_DATA%c", base_name, '\x00');

  // ARCHIVE MEMBER 2 (.idata3)
  dump_iamh(fp, sizeam2, dll_name);
  dump_ifh (fp, 1, 2, 80);
  dump_ish3(fp, 60);
  // Section .idata$3

  for (i = 0;i < 20; i++)
  {
    fprintf (fp,"%c",'\x00');
  }

  fprintf (fp,"@comp.id");
  //TODO: CHECK WHAT THIS MEANS ???
  fprintf (fp,"%c%c%c%c",'\xb4','\x9c','\xef','\x00'); // CHECK LATER
  fprintf (fp,"%c%c%c%c",'\xff','\xff','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  // __NULL_IMPORT_DESCRIPTOR
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x04','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x02','\x00');


  fprintf (fp,"%c%c%c%c",'\x1d','\x00','\x00','\x00');
  fprintf (fp,"__NULL_IMPORT_DESCRIPTOR%c", '\x00');

  // THIS THING CARRIES
  fprintf (fp,"%c",'\x0A');

  // ARCHIVE MEMBER 3 (.idata5 .idata4)
  dump_iamh(fp, sizeam3, dll_name);
  dump_ifh (fp, 2, 2, 116);
  dump_ish5(fp, 100);
  dump_ish4(fp, 100);

  // idata4 and idata5
  for (i = 0;i < 2*8; i++)
  {
    fprintf (fp,"%c",'\x00');
  }

  fprintf (fp,"@comp.id");
  //TODO: CHECK WHAT THIS MEANS ???
  fprintf (fp,"%c%c%c%c",'\xb4','\x9c','\xef','\x00'); // CHECK LATER
  fprintf (fp,"%c%c%c%c",'\xff','\xff','\x00','\x00');
  fprintf (fp,"%c%c",'\x03','\x00');

  //X%s_NULL_THUNK_DATA
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x04','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x00','\x00','\x00','\x00');
  fprintf (fp,"%c%c%c%c",'\x02','\x00','\x00','\x00');
  fprintf (fp,"%c%c",'\x02','\x00');

  fprintf (fp,"%c%c%c%c",'\x1c','\x00','\x00','\x00');
  fprintf (fp,"\x7f%s_NULL_THUNK_DATA%c", base_name, '\x00');

  if(size3even)
    fprintf (fp,"%c",'\x0A');

  /* SHORT IMPORT LIBRARY ARCHIVE MEMBERS */
  i = 0;
  for (exp = d_exports; exp; exp = exp->next)
  {
    dump_slif (fp,exp, i++);
  }

}

/* dump image archive long name member */
static void
dump_ialnm (FILE *fp)
{
  fprintf (fp,"%s%c", dll_name, '\x00');

  // If dllname+1 is an odd number append 0A to close
  if (strlen(dll_name) % 2 == 0)
      fprintf (fp,"\x0A");

}

/* dump image file header */
static void
dump_ifh (FILE *fp, uint16_t nsects, uint32_t nsymbols, uint32_t offset)
{
  /* Machine */
  fprintf (fp,"\x64\x86");
  /* Num Sections */
  fwrite (&nsects, sizeof(uint16_t), 1, fp);
  //TODO: SET DUMMY DATE
  fwrite (&time_now, sizeof(uint32_t), 1, fp);
  /* Pointer To Symbol Table */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Num Symbols */
  fwrite (&nsymbols, sizeof(uint32_t), 1, fp);
  /* Size Of Optional Headers */
  fprintf (fp,"%c%c",'\x00', '\x00');
  /* Characteristics */
  fprintf (fp,"%c%c",'\x00', '\x00');
}


/* dump image section header for .idata$2 */
static void
dump_ish2 (FILE *fp, uint32_t offset, uint32_t reloc)
{
  uint32_t dummy = 0x00000000;
  uint32_t sizerd = 0x14;
  uint32_t flags = 0xC0300040;

  /* NAME */
  fprintf (fp,".idata$2");
  /* Virtual Size */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* RVA */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Size of RAW Data */
  fwrite (&sizerd, sizeof(uint32_t), 1, fp);
  /* Pointer To RAW Data */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Pointer To Relocations */
  fwrite (&reloc, sizeof(uint32_t), 1, fp);
  /* Pointer To Lin Number */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  // Numer of Relocations
  fprintf (fp,"\x03%c",'\x00');
  // Num of Lines
  fprintf (fp,"%c%c",'\x00','\x00');
  /* Characteristics */
  fwrite (&flags, sizeof(uint32_t), 1, fp);
}

/* dump image section header for .idata$3 */
static void
dump_ish3 (FILE *fp , uint32_t offset)
{
  uint32_t dummy = 0x00000000;
  uint32_t sizerd = 0x14;
  uint32_t flags = 0xC0300040;

  /* NAME */
  fprintf (fp,".idata$3");
  /* Virtual Size */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* RVA */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Size of RAW Data */
  fwrite (&sizerd, sizeof(uint32_t), 1, fp);
  /* Pointer To RAW Data */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Pointer To Relocations */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Pointer To Lin Number */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  // Numer of Relocations
  fprintf (fp,"%c%c",'\x00','\x00');
  // Num of Lines
  fprintf (fp,"%c%c",'\x00','\x00');
  /* Characteristics */
  fwrite (&flags, sizeof(uint32_t), 1, fp);
}

/* dump image section header for .idata$3 */
static void
dump_ish4 (FILE *fp , uint32_t offset)
{
  uint32_t dummy = 0x00000000;
  uint32_t sizerd = 0x8;
  uint32_t flags = 0xC0400040;

  /* NAME */
  fprintf (fp,".idata$4");
  /* Virtual Size */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* RVA */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Size of RAW Data */
  fwrite (&sizerd, sizeof(uint32_t), 1, fp);
  /* Pointer To RAW Data */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Pointer To Relocations */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Pointer To Lin Number */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  // Numer of Relocations
  fprintf (fp,"%c%c",'\x00','\x00');
  // Num of Lines
  fprintf (fp,"%c%c",'\x00','\x00');
  /* Characteristics */
  fwrite (&flags, sizeof(uint32_t), 1, fp);
}

/* dump image section header for .idata$3 */
static void
dump_ish5 (FILE *fp , uint32_t offset)
{
  uint32_t dummy = 0x00000000;
  uint32_t sizerd = 0x8;
  uint32_t flags = 0xC0400040;

  /* NAME */
  fprintf (fp,".idata$5");
  /* Virtual Size */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* RVA */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Size of RAW Data */
  fwrite (&sizerd, sizeof(uint32_t), 1, fp);
  /* Pointer To RAW Data */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Pointer To Relocations */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Pointer To Lin Number */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  // Numer of Relocations
  fprintf (fp,"%c%c",'\x00','\x00');
  // Num of Lines
  fprintf (fp,"%c%c",'\x00','\x00');
  /* Characteristics */
  fwrite (&flags, sizeof(uint32_t), 1, fp);
}

/* dump image section header for .idata$6 */
static void
dump_ish6 (FILE *fp, uint32_t offset, uint32_t reloc)
{
  uint32_t dummy = 0x00000000;
  //TODO: base on dllname
  uint32_t sizerd = strlen(dll_name) + 1;
  if (strlen(dll_name) % 2 == 0)
    sizerd++;
  uint32_t flags = 0xC0200040;

  /* NAME */
  fprintf (fp,".idata$6");
  /* Virtual Size */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* RVA */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  /* Size of RAW Data */
  fwrite (&sizerd, sizeof(uint32_t), 1, fp);
  /* Pointer To RAW Data */
  fwrite (&offset, sizeof(uint32_t), 1, fp);
  /* Pointer To Relocations */
  fwrite (&reloc, sizeof(uint32_t), 1, fp);
  /* Pointer To Lin Number */
  fwrite (&dummy, sizeof(uint32_t), 1, fp);
  // Numer of Relocations
  fprintf (fp,"%c%c",'\x00','\x00');
  // Num of Lines
  fprintf (fp,"%c%c",'\x00','\x00');
  /* Characteristics */
  fwrite (&flags, sizeof(uint32_t), 1, fp);
}

/* dump image archive member header */
static void
dump_iamh (FILE *fp, uint32_t size, char *name)
{

  // 4 cases
  // name valid or invalid
  // name shorter then 15 chars or not

  /* IMAGE_ARCHIVE_MEMBER_HEADER */
  /* NAME */
  // 15 char limit on dll name ??
  // 11 char limit on base name

  if(!name)
  {
    fprintf (fp,"/               "); // 2F 20++
  }
  else
  {
    if(name[1] == '/')
    {
      fprintf (fp,"//              "); // 2F 2F 20++
    }
    else if(strlen(dll_name) > 15)
    {
      fprintf (fp,"/0              "); // 2F 30 20++
    }
    else
    {
      fprintf (fp,"%s/", dll_name);
      uint32_t j;
      for (j=0;j < 15-strlen(dll_name); j++)
        fprintf (fp," ");
    }
  }

  /* DATE */
  fprintf (fp,"\x31\x34\x33\x39\x32\x30\x34\x39\x32\x36  ");
  //fprintf (fp,"0000000000  "); // CHECK LATER
  /* USERID GROUPID */
  fprintf (fp,"            "); // 20++
  /* MODE */
  fprintf (fp,"\x30       "); // 30 20 20 20 20 20 20 20
  /* SIZE */
  fprintf (fp,"%d",size);
  uint32_t i;
  for (i = floor(log10(abs(size))) + 1;i < 10; i++)
  {
    fprintf (fp," ");
  }
  fprintf (fp,"\x60\x0A");
  /* END */
}

/* dump image archive linker member 1 */
static void
dump_ialm1 (FILE *fp, uint32_t id, uint32_t nid, uint32_t ntd)
{
  export_type *exp;
  uint32_t d_nsymbols = (d_nfuncs*2) + 3;

  /* OFFSET TABLE */
  uint32_t swap_nsymbols = BYTESWAP32(d_nsymbols);
  fwrite (&swap_nsymbols, sizeof(uint32_t), 1, fp);

  fwrite (&id,  sizeof(uint32_t), 1, fp);
  fwrite (&nid, sizeof(uint32_t), 1, fp);
  fwrite (&ntd, sizeof(uint32_t), 1, fp);

  //TODO: stop hijacking hint
  for (exp = d_exports; exp; exp = exp->next)
  {
    fwrite (&exp->hint, sizeof(uint32_t), 1, fp);
    fwrite (&exp->hint, sizeof(uint32_t), 1, fp);
  }

  fprintf (fp,"__IMPORT_DESCRIPTOR_%s%c", base_name, '\x00');
  fprintf (fp,"__NULL_IMPORT_DESCRIPTOR%c", '\x00');
  fprintf (fp,"\x7f%s_NULL_THUNK_DATA%c", base_name, '\x00');
  for (exp = d_exports; exp; exp = exp->next)
  {
    fprintf (fp,"%s%c",exp->name,'\x00');
    fprintf (fp,"__imp_%s%c",exp->name,'\x00');
  }
}

/* dump image archive linker member 2 */
static void
dump_ialm2 (FILE *fp, uint32_t id, uint32_t nid, uint32_t ntd)
{
  export_type *exp;
  uint32_t i;
  uint16_t dummy = 0x0000;
  uint32_t d_nmembers = d_nfuncs + 3;
  uint32_t d_nsymbols = (d_nfuncs*2) + 3;

  /* OFFSET TABLE */
  fwrite (&d_nmembers, sizeof(uint32_t), 1, fp);

  fwrite (&id,  sizeof(uint32_t), 1, fp);
  fwrite (&nid, sizeof(uint32_t), 1, fp);
  fwrite (&ntd, sizeof(uint32_t), 1, fp);

  for (exp = d_exports; exp; exp = exp->next)
  {
    fwrite (&exp->data, sizeof(uint32_t), 1, fp);
  }

  /* INDEX TABLE */
  fwrite (&d_nsymbols, sizeof(uint32_t), 1, fp);

  for (i = 0;i < 3; i++)
  {
    dummy++;
    fwrite (&dummy, sizeof(uint16_t), 1, fp);
  }

  for (i = 0;i < (uint32_t)d_nfuncs; i++)
  {
    dummy++;
    fwrite (&dummy, sizeof(uint16_t), 1, fp);
    fwrite (&dummy, sizeof(uint16_t), 1, fp);
  }
  /* SYMBOL TABLE */
  fprintf (fp,"__IMPORT_DESCRIPTOR_%s%c", base_name, '\x00');
  fprintf (fp,"__NULL_IMPORT_DESCRIPTOR%c", '\x00');
  fprintf (fp,"\x7f%s_NULL_THUNK_DATA%c", base_name, '\x00');
  for (exp = d_exports; exp; exp = exp->next)
  {
    fprintf (fp,"%s%c",exp->name,'\x00');
    fprintf (fp,"__imp_%s%c",exp->name,'\x00');
  }

}


/* dump short library import function */
static void
dump_slif (FILE *fp, export_type *exp, uint16_t count)
{
  uint16_t dummy1 = 0x0000;
  uint16_t dummy2 = 0xffff;
  uint32_t d_imp_size = strlen(exp->name) + strlen(dll_name) + 2;
  uint32_t oddname = 0;
  // dont forget to handle odd obj
  if (d_imp_size % 2 != 0)
    oddname++;

  d_imp_size+=oddname;

  uint32_t sizeslif = 20; // header size is 20
  sizeslif += strlen(exp->name) + strlen(dll_name) + 2 + oddname;
  /* IMAGE_ARCHIVE_MEMBER_HEADER */
  dump_iamh(fp, sizeslif, dll_name);
  // Sig1, Sig2, Version
  fwrite (&dummy1, sizeof(uint16_t), 1, fp);
  fwrite (&dummy2, sizeof(uint16_t), 1, fp);
  fwrite (&dummy1, sizeof(uint16_t), 1, fp);
  // Machine
  fwrite (&machine_type, sizeof(uint16_t), 1, fp);
  // Date
  fwrite (&time_now, sizeof(uint32_t), 1, fp);

  fwrite (&d_imp_size, sizeof(uint32_t), 1, fp);
  // Hint
  fwrite (&count, sizeof(uint16_t), 1, fp);
  // Type
  fprintf (fp,"\x04%c",'\x00');
  // Our Import :)
  fprintf (fp,"%s%c",exp->name,'\x00');
  fprintf (fp,"%s%c",dll_name,'\x00');

  if(oddname)
    fprintf (fp,"\x0A");
}
