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

#define _CRT_SECURE_NO_WARNINGS
#include "genidl_cfg.h"
#include "genidl_typeinfo.h"
#include "genidl_typinfo.h"

static void
fill_typb (sTI2TypLib *tl, sTI2TypeBase *tb, size_t off, unsigned char *dsrc, unsigned char *tdta, uint32_t length);
static void
print_typb_options (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix, const char *dllname);
static void
printInterfaceFuncVars (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix);
static void
printArgFlags (FILE *fp, uint32_t aflags);
static void
printFuncOption (FILE *fp, uint32_t flags, uint32_t id, uint32_t defid,
		 uint32_t funcKind, const char **fctPrefix, const char *prefix,
		 uint32_t invokeKind);
static void
printVarOption (FILE *fp, uint32_t flags, uint32_t id, uint32_t defid,
		uint32_t varKind, const char **varPrefix,
		const char *prefix);
static void
printEnum (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix_);

void
TI2_typlib_dest (sTI2TypLib *tl)
{
  if (!tl)
    return;
  TI_dest_typs (&tl->ti2_typs);
  if (tl->guid)
    free (tl->guid);
  if (tl->helpstring)
    free (tl->helpstring);
  if (tl->helpfile)
    free (tl->helpfile);
  if (tl->name)
    free (tl->name);
  if (tl->typinfos_hash)
    free (tl->typinfos_hash);
  if (tl->typb)
    {
      size_t i;
      for (i=0;i<tl->nr_typinfos;i++)
      {
	; /* Clean typb */
      }
      free (tl->typb);
    }
  free (tl);
}

sTI2TypLib *
TI2_typlib_init (unsigned char *dta, size_t len)
{
  sTI2TypLib *tl = NULL;
  sTypeLibMSFT *t = (sTypeLibMSFT *) dta;
  sSegMSFT *segs;
  unsigned char *d;
  int32_t *typeinfos;
  int i = 0;

  if (!len || !dta || t->magic1 != TYPELIB_MSFT_MAGIC)
    return NULL;
  tl = (sTI2TypLib *) malloc (sizeof (sTI2TypLib));
  memset (tl, 0, sizeof (sTI2TypLib));
  TI_init_typs (&tl->ti2_typs);

  i = 0;
  if (t->var_flags & 0x100)
    i++;
  typeinfos = (int32_t *) &t->dta[i];
  d = (unsigned char *) &typeinfos[t->nr_typeinfos];
  segs = (sSegMSFT *) d;
  d = (unsigned char *) &segs[eSegMSFT_MAX];

  /* Initialize constants pools.  */
  TI2_import_name (&tl->ti2_typs,dta + segs[eSegMSFT_NAME].offset, segs[eSegMSFT_NAME].length);
  TI2_import_string (&tl->ti2_typs,dta + segs[eSegMSFT_STRING].offset, segs[eSegMSFT_STRING].length);
  TI2_import_guid (&tl->ti2_typs,dta + segs[eSegMSFT_GUID].offset, segs[eSegMSFT_GUID].length);
  TI2_import_importlibs (&tl->ti2_typs, dta + segs[eSegMSFT_IMPORTFILES].offset, segs[eSegMSFT_IMPORTFILES].length);
  TI2_import_importref (&tl->ti2_typs, dta + segs[eSegMSFT_IMPORTINFO].offset, segs[eSegMSFT_IMPORTINFO].length);
  TI2_import_typinfo_names (&tl->ti2_typs,
    dta + segs[eSegMSFT_TYPEINFO].offset, segs[eSegMSFT_TYPEINFO].length);
  TI2_import_typedesc (&tl->ti2_typs,dta + segs[eSegMSFT_TYPEDESC].offset, segs[eSegMSFT_TYPEDESC].length);
  TI2_import_customdata (&tl->ti2_typs, dta + segs[eSegMSFT_CUSTDATA].offset, segs[eSegMSFT_CUSTDATA].length);
  TI2_import_array (&tl->ti2_typs, dta + segs[eSegMSFT_ARRAYDESC].offset, segs[eSegMSFT_ARRAYDESC].length);
  TI2_import_ref (&tl->ti2_typs, dta + segs[eSegMSFT_REFERENCES].offset, segs[eSegMSFT_REFERENCES].length);
  TI2_import_customdataguid (&tl->ti2_typs, dta + segs[eSegMSFT_CUSTDATAGUID].offset, segs[eSegMSFT_CUSTDATAGUID].length);

  tl->ver_major = t->ver_major;
  tl->ver_minor = t->ver_minor;
  tl->version = t->version;
  tl->lcid1 = t->lcid;
  tl->lcid2 = t->lcid2;
  if (t->pos_guid != -1)
    tl->guid = TI_get_typ_name (&tl->ti2_typs, t->pos_guid, TITYP_GUIDS, "");
  tl->flags = t->flags;
  tl->setFlags = t->var_flags;
  tl->helpstringctx = t->helpstringcontext;
  tl->helpctx = t->helpcontext;
  if (t->helpstring != -1)
    tl->helpstring = TI_get_typ_name (&tl->ti2_typs, t->helpstring, TITYP_STR, "");
  if (t->helpfile != -1)
    tl->helpfile = TI_get_typ_name (&tl->ti2_typs, t->helpfile, TITYP_STR, "");
  if (t->name_offset != -1)
    {
      tl->name = TI_get_typ_name (&tl->ti2_typs, t->name_offset, TITYP_NAME, "");
      genidl_strlwr (tl->name);
    }
  tl->dispatch = t->dispatchpos;
  tl->nr_typinfos = t->nr_typeinfos;
  tl->nr_impinfos = t->nr_impinfos;
  if (tl->nr_typinfos > 0)
    {
      size_t ii;
      tl->typinfos_hash = (uint32_t *) malloc (sizeof (uint32_t) * tl->nr_typinfos);
      memcpy (tl->typinfos_hash, typeinfos, sizeof (uint32_t) * tl->nr_typinfos);
      tl->typb = (sTI2TypeBase *) malloc (sizeof (sTI2TypeBase) * tl->nr_typinfos);
      memset (tl->typb, 0, sizeof (sTI2TypeBase) * tl->nr_typinfos);
      for (ii = 0;ii < tl->nr_typinfos; ii++)
      {
	fill_typb (tl, &tl->typb[ii], ii, dta, dta + segs[eSegMSFT_TYPEINFO].offset, segs[eSegMSFT_TYPEINFO].length);
      }
    }
  return tl;
}

static void
fill_typb (sTI2TypLib *tl, sTI2TypeBase *tb, size_t off, unsigned char *dsrc, unsigned char *tdta, uint32_t length)
{
  sMSFT_TypeInfoBase *t = (sMSFT_TypeInfoBase *) &tdta[off * sizeof (sMSFT_TypeInfoBase)];
  if (length <= (off * sizeof (sMSFT_TypeInfoBase)))
    return;
  tb->kind = (t->typekind & 0xf);
  tb->kflags = (t->typekind >> 4) & 0xfff;
  tb->flags= t->flags;
  tb->cFuncs = t->cElement & 0xffff;
  tb->cVars = (t->cElement >> 16) & 0xffff;
  tb->name = TI_get_typ_name (&tl->ti2_typs, (uint32_t) (off * sizeof (sMSFT_TypeInfoBase)),
    TITYP_TYPINFO_NAMES, "");
  if (t->posguid != -1)
    tb->guid = TI_get_typ_name (&tl->ti2_typs, (uint32_t) t->posguid, TITYP_GUIDS, "");
  if (t->docstringoffs != -1)
    tb->docstr = TI_get_typ_name (&tl->ti2_typs, (uint32_t) t->docstringoffs, TITYP_STR, "");
  if (t->oCustData != -1)
    tb->custData = TI_get_typ_name (&tl->ti2_typs, (uint32_t) t->oCustData,
      TITYP_CUSTOMDATA, "");
  tb->version = t->version;
  if (t->datatype1 != -1)
    {
      switch (tb->kind)
      {
      case TKIND_COCLASS:
	tb->dataType =
	  TI_get_typ_name (&tl->ti2_typs, (uint32_t) t->datatype1, TITYP_REF, "");
	break;
      case TKIND_MODULE:
	tb->dataType =
	  TI_get_typ_name (&tl->ti2_typs, (uint32_t) t->datatype1, TITYP_STR, "");
	break;
      case TKIND_INTERFACE:
      case TKIND_DISPATCH:
	tb->dataType =
	  getTypeBOrImpRef (&tl->ti2_typs, (uint32_t) t->datatype1,"");
	break;
      default:
	tb->dataType =
	  TI_getVTorDref (&tl->ti2_typs, (uint32_t) t->datatype1, "", 0);
	break;
      }
    }
  tb->tib = t;
  if (tb->cFuncs || tb->cVars)
  {
    sMSFT_memblob *b = (sMSFT_memblob *) &dsrc[t->memoffset];
    uint32_t *doff = (uint32_t *) &b->dta[b->size];
    uint32_t offs = 0;
    size_t cf = tb->cFuncs;
    size_t cv = tb->cVars;
    size_t idx = 0;
    tb->mem.count = cf + cv;
    tb->mem.items = (sTI2TypeBaseMemItem *)
      malloc ( sizeof (sTI2TypeBaseMemItem) * tb->mem.count);
    memset (tb->mem.items, 0, sizeof (sTI2TypeBaseMemItem) * tb->mem.count);
    while (offs < b->size)
    {
      tb->mem.items[idx].mem = &b->dta[offs];
      if (cf > 0)
      {
	sMSFT_FuncParam *params;
	sMSFT_func *func;
	uint32_t oVars = 0, *pData, *pCustomData = NULL;

	func = (sMSFT_func *) &b->dta[offs];
	oVars = func->rlen - (func->nrArgs * 12);
	params = (sMSFT_FuncParam *) &b->dta[offs + oVars];
	pData = func->data;
	pCustomData = NULL;
	if (func->f.hasParamDefValue)
	  pCustomData = (uint32_t *) &b->dta[offs + oVars-func->nrArgs*4];
	tb->mem.items[idx].customData = pCustomData;
	tb->mem.items[idx].funcParam = params;
	tb->mem.items[idx].extData = doff;
	tb->mem.items[idx].max = tb->mem.count;
	tb->mem.items[idx].beFunc = 1;
	offs += func->rlen;
	--cf;
      }
      else if (cv > 0)
      {
	sMSFT_var *var = (sMSFT_var *) &b->dta[offs];
	offs += var->rlen;
	tb->mem.items[idx].extData = doff;
	tb->mem.items[idx].max = tb->mem.count;
      }
      else
	abort ();
      doff++;
      idx++;
    }
  }
}

static void
TI2_update_config (sTI2TypLib *tl, const char *orgfname)
{
  size_t no = tl->nr_typinfos;
  size_t i;
  char *tlbname;
  char *sec = NULL;

  genidl_add_lib (tl->name);
  sec = (char *) malloc (strlen (orgfname) + 5);
  /* Do we have a .tlb input file? If so add alias of name.  */
  strcpy (sec, orgfname);
  if (strrchr (sec, '.') != NULL)
    {
      if (strcmp (strrchr (sec, '.'), ".tlb") != 0)
        strcpy (strrchr (sec, '.'), ".tlb");
    }
  else
    {
      strcat (sec, ".tlb");
    }
  genidl_add_lib_alias (sec, tl->name);
  free (sec);

  /* We remove possibly old items.  */
  genidl_del_lib_item (tl->name);
  if (!no && tl->ti2_typs.buc[TITYP_NAME].count != 0
      && tl->ti2_typs.buc[TITYP_GUIDS].count != 0)
    return;
  tlbname = (char *) malloc (strlen ("TypeD_") + 8 + 1);
  *tlbname = 0;

  for (i = 0;i < no; i++)
    {
      /* uint32_t mem = tl->ti2_typs.buc[TITYP_TYPINFO_NAMES].arr[i]->memid; */
      char *name = tl->ti2_typs.buc[TITYP_TYPINFO_NAMES].arr[i]->name;
      /* sprintf (tlbname, "TypeB_%x", mem); */
      sprintf (tlbname, "TypeB_%x", (unsigned int) i);
      genidl_add_lib_item (tl->name, tlbname, name);

      if (tl->typb[i].guid)
        {
	  char *hp = strdup (tl->typb[i].guid + 1);
	  if (strrchr (hp, '\"') != NULL)
	    * strrchr (hp, '\"') = 0;
	  genidl_add_lib_item (tl->name, hp, name);
	  free (hp);
        }
      /*if (tl->typb[i].tib->NameOffset != -1)
	{
	  sprintf (tlbname, "Name_%x", tl->typb[i].tib->NameOffset);
	  genidl_add_lib_item (tl->name, tlbname, name);
	} */
    }
  free (tlbname);
}

static int
printVersion (FILE *fp, uint32_t version, int befirst, int befirstret, const char *prefix)
{
  if (befirst == 0)
    fprintf (fp, ",\n%s  ", prefix);
  else if (befirst == -1)
    fprintf (fp, ", ");
  else if (befirstret == 0)
    fprintf (fp, "%s  ", prefix);
  fprintf (fp,"version(%d.%d)", version & 0xffff, (version>>16) & 0xffff);
  return befirstret;
}

static int
print_flagsstring (FILE *fp, const char *attr, int befirst, int befirstret, const char *prefix)
{
  if (befirst == 0)
    fprintf (fp, ",\n%s  ", prefix);
  else if (befirst == -1)
    fprintf (fp, ", ");
  else if (befirstret == 0)
    fprintf (fp, "%s  ", prefix);
  fprintf (fp, "%s", attr);
  return befirstret;
}

static int
printString (FILE *fp, const char *name, const char *str, int befirst, int befirstret, const char *prefix)
{
  if (befirst == 0)
    fprintf (fp, ",\n%s  ", prefix);
  else if (befirst == -1)
    fprintf (fp, ", ");
  else if (befirstret == 0)
    fprintf (fp, "%s  ", prefix);
  if (!str) str = "";
  if (*str != '"')
    fprintf (fp, "%s(\"%s\")", name, str);
  else
    fprintf (fp, "%s(%s)", name, str);
  return befirstret;
}

static int
printUuid (FILE *fp, char *str,int befirst,int befirstret, const char *prefix)
{
  if (befirst == 0)
    fprintf (fp, ",\n%prefix  ", prefix);
  else if (befirst == -1)
    fprintf (fp, ", ");
  else if (befirstret == 0)
    fprintf (fp, "%s  ", prefix);
  if (!str || (str[0] == '"' && str[1]=='"'))
    fprintf (fp, "uuid(00000000-0000-0000-0000-000000000000)");
  else if (*str != '"')
    {
      fprintf (fp, "uuid(%s)", str);
    }
  else
    {
      str++;
      fprintf (fp, "uuid(");
      while (*str != 0 && *str != '"')
	{
	  fputc (*str,fp);
	  ++str;
	}
      fprintf (fp, ")");
    }
  return befirstret;
}

static const char *varflags[32] = {
  "readonly", "source", "bindable", "requestedit",
  "displaybind", "defaultbind", "hidden", "restricted",
  "defaultcollelem", "uidefault", "nonbrowsable", "replaceable",
  "immediatebind", "VARFLAG_2000","VARFLAG_4000","VARFLAG_8000",
  "VARFLAG_10000","VARFLAG_20000","VARFLAG_40000","VARFLAG_80000",
  "VARFLAG_100000","VARFLAG_200000","VARFLAG_400000","VARFLAG_800000",
  "VARFLAG_1000000","VARFLAG_2000000","VARFLAG_4000000","VARFLAG_8000000",
  "VARFLAG_10000000","VARFLAG_20000000","VARFLAG_40000000","VARFLAG_80000000"
};

static const char *funcflags[32] =
{
  "restricted", "source", "bindable", "requestedit",
  "displaybind", "defaultbind", "hidden", "uselasterror",
  "defaultcollelem", "uidefault", "nonbrowsable", "replaceable",
  "immediatebind", "FUNCFLAG_2000","FUNCFLAG_4000","FUNCFLAG_8000",
  "FUNCFLAG_10000","FUNCFLAG_20000","FUNCFLAG_40000","FUNCFLAG_80000",
  "FUNCFLAG_100000","FUNCFLAG_200000","FUNCFLAG_400000","FUNCFLAG_800000",
  "FUNCFLAG_1000000","FUNCFLAG_2000000","FUNCFLAG_4000000","FUNCFLAG_8000000",
  "FUNCFLAG_10000000","FUNCFLAG_20000000","FUNCFLAG_40000000","FUNCFLAG_80000000"
};

static const char *typb_flags[32] = {
  "appobject", "cancreate", "licensed", "predeclid",
  "hidden", "control", "dual", "nonextensible",
  "oleautomation", "restricted", "aggregatable", "replaceable",
  "dispatchable", "reversebind", "proxy", "TYPEFLAG_8000",
  "TYPEFLAG_10000","TYPEFLAG_20000","TYPEFLAG_40000","TYPEFLAG_80000",
  "TYPEFLAG_100000","TYPEFLAG_200000","TYPEFLAG_400000","TYPEFLAG_800000",
  "TYPEFLAG_1000000","TYPEFLAG_2000000","TYPEFLAG_4000000","TYPEFLAG_8000000",
  "TYPEFLAG_10000000","TYPEFLAG_20000000","TYPEFLAG_40000000","TYPEFLAG_80000000"
};

static const char *param_flags[32] = {
  "in", "out", "lcid", "retval",
  "opt", "\0hasdefault", "hascustomdata", "PARAMFLAG_80",
  "PARAMFLAG_100","PARAMFLAG_200","PARAMFLAG_400","PARAMFLAG_800",
  "PARAMFLAG_1000","PARAMFLAG_2000","PARAMFLAG_4000","PARAMFLAG_8000",
  "PARAMFLAG_10000","PARAMFLAG_20000","PARAMFLAG_40000","PARAMFLAG_80000",
  "PARAMFLAG_100000","PARAMFLAG_200000","PARAMFLAG_400000","PARAMFLAG_800000",
  "PARAMFLAG_1000000","PARAMFLAG_2000000","PARAMFLAG_4000000","PARAMFLAG_8000000",
  "PARAMFLAG_10000000","PARAMFLAG_20000000","PARAMFLAG_40000000","PARAMFLAG_80000000"
};

static void
printArgFlags (FILE *fp, uint32_t aflags)
{
  int idx = 0, befirst = 1;
  if (!aflags || (aflags & ~PARAMFLAG_FHASDEFAULT)==0)
    return;
  fprintf (fp, "[");
  while (aflags != 0 && idx < 32)
  {
    if ((aflags & 1)!=0 && param_flags[idx][0] != 0)
    {
      fprintf (fp, "%s%s", befirst ? "" : " ", param_flags[idx]);
      befirst = 0;
    }
    aflags >>= 1;
    idx++;
  }
  fprintf (fp, "] ");
}

static void
print_typb_options (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix, const char *dllname)
{
  int befirst = 1;
  uint32_t flags = tb->flags, idx = 0;

  if (tl)
    befirst = 1;
  if (!tb)
    return;
  if (tb->flags == 0 && tb->docstr == NULL && tb->guid == NULL
    && tb->version == 0 && dllname == NULL)
    return;
  fprintf (fp, "%s[\n", prefix);
  if (tb->guid != NULL)
    befirst = printUuid (fp, tb->guid,befirst, 0, prefix);
  if (tb->version != 0)
    befirst = printVersion (fp, tb->version, befirst, 0, prefix);
  if (tb->docstr)
    befirst = printString (fp, "helpstring", tb->docstr, befirst, 0, prefix);
  while (flags != 0 && idx != 32)
  {
    if ((flags & 1) != 0 && typb_flags[idx][0] != 0)
      befirst = print_flagsstring (fp, typb_flags[idx], befirst, 0, prefix);
    flags >>= 1; idx++;
  }
  if (dllname)
    befirst = printString (fp, "dllname", dllname, befirst, 0, prefix);
  if (befirst != 1)
    fprintf (fp, "\n");
  fprintf (fp, "%s]\n", prefix);
}

static void
TI2_typlib_imports (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  sTITypsHash *th = &tl->ti2_typs.buc[TITYP_IMP];
  for (i = 0;i < th->count; i++)
    {
      fprintf (fp, "%simportlib(\"%s\");\n", prefix, th->arr[i]->name);
    }
  if (i != 0)
    fprintf (fp, "\n");
}

static char *mk_guard (const char *name, const char *addition)
{
  char *r, *h;
  size_t len;
  if (!addition)
    addition = "";
  len = strlen (name) + strlen (addition) + 1 + strlen ("__");
  r = (char *) malloc (len);
  sprintf (r, "__%s%s", name, addition);
  h = r;
  while (*h != 0)
    {
      if (*h >= 'a' && *h <= 'z')
      {
        h[0] -= 'a';
        h[0] += 'A';
      }
      else if (*h <= 0x20)
        *h = '_';
      h++;
    }
  return r;
}

static void
TI2_typlib_forward_declare (FILE *fp, sTI2TypLib *tl, int behdr)
{
  size_t i;
  char *guard = NULL;
  int befirst;
  befirst = 1;
  if (!behdr)
  {
    /*
    fprintf (fp, "/ * Typedef definitions of basic types.  * /\n"
      "typedef unsigned short USHORT;\n"
      "typedef signed short SHORT;\n"
      "typedef unsigned char UCHAR;\n"
      "typedef signed char CHAR;\n"
      "typedef unsigned int UINT;\n"
      "typedef signed int INT;\n"
      "typedef int WINBOOL;\n"
      "typedef struct _tagVARIANT VARIANT;\n"
      "typedef unsigned short *BSTR;\n"
      "typedef int SCODE;\n"
      "typedef struct _CY CY;\n");
    */
  }
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_INTERFACE)
	continue;
      if (befirst)
	{
	  fprintf (fp, "/* Interface forward declarations.  */\n");
	  befirst = 0;
	}
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_FORWARDER_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%s;\n", tl->typb[i].name);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      char *hn;
      if (tl->typb[i].kind != TKIND_RECORD)
	continue;
      if (befirst)
	{
	  fprintf (fp, "/* Structure forward declarations.  */\n");
	  befirst = 0;
	}
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_FORWARDER_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      if ((hn = strchr (tl->typb[i].name, ' ')) == NULL)
        hn = tl->typb[i].name;
      else hn++;
      fprintf (fp, "typedef %s %s;\n", tl->typb[i].name, hn);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      char *hn;
      if (tl->typb[i].kind != TKIND_UNION)
	continue;
      if (befirst)
	{
	  fprintf (fp, "/* Union record forward declarations.  */\n");
	  befirst = 0;
	}
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_FORWARDER_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      if ((hn = strchr (tl->typb[i].name, ' ')) == NULL)
        hn = tl->typb[i].name;
      else hn++;
      fprintf (fp, "typedef %s %s;\n", tl->typb[i].name, hn);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_DISPATCH)
	continue;
      if (befirst)
	{
	  fprintf (fp, "/* Dispatch record forward declarations.  */\n");
	  befirst = 0;
	}
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_FORWARDER_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%s;\n", tl->typb[i].name);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_COCLASS)
	continue;
      if (befirst)
	{
	  fprintf (fp, "/* Coclass record forward declarations.  */\n");
	  befirst = 0;
	}
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_FORWARDER_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%s;\n", tl->typb[i].name);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_typedefs (FILE *fp, sTI2TypLib *tl, const char *prefix, int behdr)
{
  char *guard = NULL;
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_ALIAS)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Type definitions.  */\n", prefix);
	  befirst = 0;
	}
      if (!behdr)
        print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_TYPEDEF_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%stypedef %s %s;\n", prefix,
	(tl->typb[i].dataType ? tl->typb[i].dataType : "<unknown>"),
	tl->typb[i].name);
      if (guard)
        {
	  if (*guard != 0)
	    fprintf (fp,"#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
        }
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_enumerations (FILE *fp, sTI2TypLib *tl, const char *prefix, int behdr)
{
  char *guard = NULL;
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_ENUM)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Enumeration declarations.  */\n", prefix);
	  befirst = 0;
	}
      if (!behdr)
        print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%s%s\n", prefix, tl->typb[i].name);
      fprintf (fp, "%s{\n", prefix);
      printEnum (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
      if (guard)
      {
	if (*guard != 0)
	  fprintf (fp, "#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
      }
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_dispinterface_hdr (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_DISPATCH)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Dispatch interface declarations.  */\n", prefix);
	  befirst = 0;
	}
      //print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      fprintf (fp, "%s%s", prefix, tl->typb[i].name);
      if (tl->typb[i].dataType != NULL)
      {
	char *h = tl->typb[i].dataType;
	if (strchr (h, ' ')!=NULL)
	  h = strchr (h, ' ') + 1;
	fprintf (fp, " : %s", h);
      }
      fprintf (fp, "\n");
      fprintf (fp, "%s{\n", prefix);
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_dispinterface (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_DISPATCH)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Dispatch interface declarations.  */\n", prefix);
	  befirst = 0;
	}
      print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      fprintf (fp, "%s%s", prefix, tl->typb[i].name);
      if (tl->typb[i].dataType != NULL)
      {
	char *h = tl->typb[i].dataType;
	if (strchr (h, ' ')!=NULL)
	  h = strchr (h, ' ') + 1;
	fprintf (fp, " : %s", h);
      }
      fprintf (fp, "\n");
      fprintf (fp, "%s{\n", prefix);
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_coclass_hdr (FILE *fp, sTI2TypLib *tl, const char *prefix, uint32_t tkind)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != tkind)
	continue;
      if (befirst)
	{
	  if (tkind == TKIND_COCLASS)
	    fprintf (fp, "%s/* CoClass declarations.  */\n", prefix);
	  befirst = 0;
	}
      //print_typb_options (fp,tl,&tl->typb[i],prefix, NULL);
      fprintf (fp, "%s%s\n", prefix, tl->typb[i].name);
      fprintf (fp, "%s{\n", prefix);
      if (tl->typb[i].tib->datatype1 != -1)
      {
	int offset_ref = tl->typb[i].tib->datatype1;
	char *ifname;
	sTITyp *rtyp;
	do {
	  rtyp = TI_get_typ (&tl->ti2_typs, (uint32_t) offset_ref, TITYP_REF);
	  ifname = TI_get_typ_name (&tl->ti2_typs, (uint32_t) offset_ref, TITYP_REF, "");
	  offset_ref = (rtyp == NULL ? -1 : (int) rtyp->refmem);
	  if (ifname)
	    fprintf (fp, "%s  %s;\n",prefix,ifname);
	} while (offset_ref != -1);

      }
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_coclass (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_COCLASS)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* CoClass declarations.  */\n", prefix);
	  befirst = 0;
	}
      print_typb_options (fp,tl,&tl->typb[i],prefix, NULL);
      fprintf (fp, "%s%s\n", prefix, tl->typb[i].name);
      fprintf (fp, "%s{\n", prefix);
      if (tl->typb[i].tib->datatype1 != -1)
      {
	int offset_ref = tl->typb[i].tib->datatype1;
	char *ifname;
	sTITyp *rtyp;
	do {
	  rtyp = TI_get_typ (&tl->ti2_typs, (uint32_t) offset_ref, TITYP_REF);
	  ifname = TI_get_typ_name (&tl->ti2_typs, (uint32_t) offset_ref, TITYP_REF, "");
	  offset_ref = (rtyp == NULL ? -1 : (int) rtyp->refmem);
	  if (ifname)
	    fprintf (fp, "%s  %s;\n",prefix,ifname);
	} while (offset_ref != -1);

      }
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_structures (FILE *fp, sTI2TypLib *tl, const char *prefix, int behdr)
{
  char *guard = NULL;
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_RECORD && tl->typb[i].kind != TKIND_UNION)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Structure/union declarations.  */\n", prefix);
	  befirst = 0;
	}
      if (!behdr)
        print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      if (behdr)
        guard = mk_guard (tl->typb[i].name, "_DEFINED");
      if (guard && *guard != 0)
        fprintf (fp, "#ifndef %s\n#define %s\n", guard, guard);
      fprintf (fp, "%s%s\n", prefix, tl->typb[i].name);
      fprintf (fp, "%s{\n", prefix);
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
      if (guard)
      {
	if (*guard != 0)
	  fprintf (fp, "#endif /* %s */\n\n", guard);
	  free (guard);
	  guard = NULL;
      }
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
TI2_typlib_modules (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_MODULE)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Module declarations.  */\n", prefix);
	  befirst = 0;
	}
      print_typb_options (fp,tl, &tl->typb[i],prefix, tl->typb[i].dataType);
      fprintf (fp, "%s%s", prefix, tl->typb[i].name);
      fprintf (fp, "\n");
      fprintf (fp, "%s{\n", prefix);
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
printEnum (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix_)
{
  char *prefix;
  size_t i;
  if (!tl || !tb || (tb->cFuncs == 0 && tb->cVars == 0))
    return;
  prefix = (char *) malloc (strlen (prefix_) + 3);
  memset (prefix,' ',strlen (prefix_) + 2);
  prefix[strlen (prefix_) + 2] = 0;

  for (i = 0;i < tb->mem.count; i++)
  {
    char *name = NULL;
    sTI2TypeBaseMemItem *mi = &tb->mem.items[i];

    name = TI_get_typ_name (&tl->ti2_typs, mi->extData[mi->max], TITYP_NAME, "");
    if (mi->beFunc)
    {
      abort ();
    }
    else
    {
      fprintf (fp, "%s%s = ", prefix, name);
      printValue (fp, &tl->ti2_typs,mi->var->oValue);
      fprintf (fp, "%s\n", ((i+1) != tb->mem.count ? "," : ""));
    }
    if (name)
      free (name);
  }
  free (prefix);
}

static void
printInterfaceFuncVars (FILE *fp, sTI2TypLib *tl, sTI2TypeBase *tb, const char *prefix_)
{
  uint32_t defid;
  char *prefix;
  size_t i;
  if (!tl || !tb || (tb->cFuncs == 0 && tb->cVars == 0))
    return;
  prefix = (char *) malloc (strlen (prefix_) + 3);
  memset (prefix,' ',strlen (prefix_) + 2);
  prefix[strlen (prefix_) + 2] = 0;

  switch (tb->kind)
  {
  case TKIND_UNION: case TKIND_RECORD:
    defid = (uint32_t) 1073741824; break;
  default:
    defid = 0xfefefefe; break;
  }

  for (i = 0;i < tb->mem.count; i++)
  {
    char *name = NULL;
    char *rtyp = NULL;
    uint32_t id;
    sTI2TypeBaseMemItem *mi = &tb->mem.items[i];

    name = TI_get_typ_name (&tl->ti2_typs, mi->extData[mi->max], TITYP_NAME, "");
    id = mi->extData[0];
    if (mi->beFunc)
    {
      const char *val = "";
      printFuncOption (fp, mi->func->flags, id, defid, mi->func->f.funcKind, &val, prefix,
	mi->func->f.invokeKind);
      rtyp = TI_getVTorDref (&tl->ti2_typs, mi->func->datatype, "", 0);
      fprintf (fp, "%s%s%s %s %s (",
	prefix, val, rtyp, getCallConvName(mi->func->f.callconv),
	name);
      if (mi->func->nrArgs == 0)
	fprintf (fp, "void);\n");
      else
	{
	  uint16_t a;
	  fprintf (fp, "\n");
	  for (a = 0; a < mi->func->nrArgs;a++)
	  {
	    char *aname = NULL;
	    char *atyp = NULL;
	    if (mi->funcParam[a].oName != -1)
	      aname = TI_get_typ_name (&tl->ti2_typs, mi->funcParam[a].oName, TITYP_NAME, "");
	    else
	      {
	        /* We have to generate an name for this argument. */
	        aname = (char *) malloc (128);
	        sprintf (aname, "argNo%u", (uint32_t) a + 1);
	      }
	    atyp = TI_getVTorDref (&tl->ti2_typs, mi->funcParam[a].dataType, aname, 0);
	    fprintf (fp, "%s  ", prefix);
	    printArgFlags (fp, mi->funcParam[a].flags);
	    fprintf (fp, "%s", atyp);
	    free (atyp);
	    free (aname);
	    if (mi->customData && (mi->funcParam[a].flags & PARAMFLAG_FHASDEFAULT) != 0)
	    {
	      fprintf (fp," = ");
	      printValue (fp, &tl->ti2_typs,mi->customData[a]);
	    }
	    if ((a + 1) != mi->func->nrArgs)
	      fprintf (fp, ",");
	    fprintf (fp, "\n");
	  }
	  fprintf (fp, "%s);\n", prefix);
	}
    }
    else
    {
      const char *val = "";
      printVarOption (fp, mi->var->flags, id, defid, mi->var->varKind, &val, prefix);
      rtyp = TI_getVTorDref (&tl->ti2_typs, mi->var->datatype, name, 0);
      fprintf (fp, "%s%s%s", prefix, val, rtyp);
      if ((tb->kind == TKIND_DISPATCH || tb->kind == TKIND_INTERFACE) && mi->var->oValue != 0)
      {
	fprintf (fp," = %d", mi->var->oValue);
      }
      else if (tb->kind != TKIND_RECORD && tb->kind != TKIND_UNION
        && !(tb->kind == TKIND_DISPATCH || tb->kind == TKIND_INTERFACE)
	&& (uint32_t) mi->var->oValue != (uint32_t) -1)
        {
	  fprintf (fp," = ");
	  printValue (fp, &tl->ti2_typs,mi->var->oValue);
        }
      fprintf (fp, ";\n");
    }
    if (rtyp)
      free (rtyp);
    if (name)
      free (name);
    defid = id + 1;
  }
  free (prefix);
}

static void
TI2_typlib_interfaces (FILE *fp, sTI2TypLib *tl, const char *prefix)
{
  size_t i;
  int befirst;
  befirst = 1;
  for (i=0;i<tl->nr_typinfos;i++)
    {
      if (tl->typb[i].kind != TKIND_INTERFACE)
	continue;
      if (befirst)
	{
	  fprintf (fp, "%s/* Interface declarations.  */\n", prefix);
	  befirst = 0;
	}
      print_typb_options (fp,tl, &tl->typb[i],prefix, NULL);
      fprintf (fp, "%s%s", prefix, tl->typb[i].name);
      if (tl->typb[i].dataType != NULL)
      {
	char *h = tl->typb[i].dataType;
	if (strchr (h, ' ')!=NULL)
	  h = strchr (h, ' ') + 1;
	fprintf (fp, " : %s", h);
      }
      fprintf (fp, "\n");
      fprintf (fp, "%s{\n", prefix);
      printInterfaceFuncVars (fp, tl, &tl->typb[i], prefix);
      fprintf (fp, "%s};\n", prefix);
    }
  if (!befirst)
    fprintf (fp, "\n");
}

static void
printVarOption (FILE *fp, uint32_t flags, uint32_t id, uint32_t defid,
		uint32_t varKind, const char **varPrefix,
		const char *prefix)
{
  int befirst = 1,idx = 0;

  switch (varKind) {
  case VARKIND_PERINSTANCE: break;
  case VARKIND_STATIC: *varPrefix = "static "; break;
  case VARKIND_CONST: *varPrefix = "CONST "; break;
  case VARKIND_DISPATCH: break;
  }
  if (id == defid && flags == 0)
    return;
  fprintf (fp, "%s[", prefix);
  if (id != defid)
  {
    if (id < 0x100)
      fprintf (fp, "id(%u)", id);
    else
      fprintf (fp, "id(0x%x)", id);
    befirst=0;
  }
  while (flags != 0)
  {
    if ((flags & 1)!=0 && varflags[idx][0]!=0)
    {
      if (!befirst) fprintf (fp, ", ");
      befirst = 0;
      fprintf (fp, "%s", varflags[idx]);
    }
    flags >>=1; idx++;
  }
  fprintf (fp, "]\n");
}

static void
printFuncOption (FILE *fp, uint32_t flags, uint32_t id, uint32_t defid,
		 uint32_t funcKind, const char **fctPrefix, const char *prefix,
		 uint32_t invokeKind)
{
  int befirst = 1, idx = 0;
  const char *invoke = "";
  switch (funcKind)
  {
  case FUNCTKIND_VIRTUAL: *fctPrefix = "virtual "; break;
  case FUNCTKIND_PUREVIRTUAL: break;
  case FUNCTKIND_NONVIRTUAL: break;
  case FUNCTKIND_STATIC: *fctPrefix = "static "; break;
  case FUNCTKIND_DISPATCH:
    break;
  }
  switch ((invokeKind & ~1))
  {
  case INVOKIND_FUNC: break;
  case INVOKIND_PROPERTYGET: invoke = "propget"; break;
  case INVOKIND_PROPERTYPUT: invoke = "propput"; break;
  case INVOKIND_PROPERTYGET | INVOKIND_PROPERTYPUT:
    invoke = "propgetput"; break;
  case INVOKIND_PROPERTYPUTREF:
    invoke = "propputref"; break;
  case INVOKIND_PROPERTYPUT | INVOKIND_PROPERTYPUTREF:
    invoke = "propputputref"; break;
  case INVOKIND_PROPERTYGET | INVOKIND_PROPERTYPUTREF:
    invoke = "propgetputref"; break;
  case INVOKIND_PROPERTYGET | INVOKIND_PROPERTYPUT | INVOKIND_PROPERTYPUTREF:
    invoke = "propgetputputref"; break;
  }
  if (id == defid && flags == 0 && invoke[0]==0)
    return;
  fprintf (fp, "%s[", prefix);
  if (id != defid)
  {
    if (id < 0x100)
      fprintf (fp, "id(%u)", id);
    else
      fprintf (fp, "id(0x%x)", id);
    befirst = 0;
  }
  if (invoke[0]!=0)
  {
    if (!befirst)
      fprintf (fp, ", ");
    fprintf (fp, "%s", invoke);
    befirst = 0;
  }
  while (flags != 0)
  {
    if ((flags & 1) != 0 && funcflags[idx][0]!=0)
      {
	if (!befirst)
	  fprintf (fp, ", ");
	fprintf (fp, "%s", funcflags[idx]);
	befirst = 0;
      }
    flags >>=1; idx++;
  }
  fprintf (fp, "]\n");
}

void
TI2_typlib_hdr (FILE *fp, sTI2TypLib *tl, const char *orgfname)
{
  //int befirst;
  if (!tl)
    return;
  fprintf (fp, "/* Automated generated header file <%s>.\n"
    " * Generated by genidl tool (c) 2009-2016 Mingw-w64 project.\n"
    " */\n\n", (tl->name ? tl->name : "unknown"));
  TI2_update_config (tl, orgfname);
  TI2_typlib_forward_declare (fp, tl, 1);
  TI2_typlib_enumerations (fp, tl, "", 1);
  TI2_typlib_structures (fp, tl, "",1);
  TI2_typlib_typedefs (fp, tl, "", 1);
  if (0) TI2_typlib_coclass_hdr (fp, tl, "", TKIND_COCLASS);
  TI2_typlib_dispinterface_hdr (fp, tl, "");
}

void
TI2_typlib_idl (FILE *fp, sTI2TypLib *tl, const char *orgfname)
{
  int befirst;
  if (!tl)
    return;
  fprintf (fp, "/* Automated generated idl file <%s>.\n"
    " * Generated by genidl tool (c) 2009-2016 Mingw-w64 project.\n"
    " */\n\n", (tl->name ? tl->name : "unknown"));

  TI2_update_config (tl, orgfname);
  TI2_typlib_forward_declare (fp, tl, 0);
  TI2_typlib_enumerations (fp, tl, "", 0);
  TI2_typlib_structures (fp, tl, "", 0);
  TI2_typlib_typedefs (fp, tl, "", 0);
  fprintf (fp, "[\n");
  befirst = 1;
  if (tl->guid)
    befirst = printUuid (fp, tl->guid, befirst, 0, "");
  if (tl->version != 0)
    befirst = printVersion (fp, tl->version, befirst, 0, "");
  if (tl->helpstring)
    befirst = printString (fp, "helpstring", tl->helpstring, befirst, 0, "");
  if (tl->helpfile)
    befirst = printString (fp, "helpfile", tl->helpfile, befirst, 0, "");
  if (befirst != 1)
    fprintf (fp, "\n");
  fprintf (fp, "]\n");
  fprintf (fp, "library %s\n{\n", tl->name);
  TI2_typlib_imports (fp, tl, "  ");
  // coclass
  TI2_typlib_coclass (fp, tl, "   ");
  // dispinterface
  TI2_typlib_dispinterface (fp, tl, "   ");
  fprintf (fp, "};\n\n");
  TI2_typlib_interfaces (fp, tl, "");
  TI2_typlib_modules (fp, tl, "");
}
