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
#include <inttypes.h>
#include "genidl_cfg.h"
#include "genidl_typeinfo.h"
#include "genidl_typinfo.h"

void dumpHexFp (FILE *fp,size_t off, const unsigned char *dta, size_t len);
void dumpDecFp (FILE *fp, const unsigned char *dta, size_t len, const char *prefix);
void printPrefix (FILE *fp, const char *name, int32_t val);
void printPrefix2 (FILE *fp, const char *name, int32_t val);

uint32_t printVT (FILE *fp, uint32_t vt, unsigned char *dta);
void printVTData (FILE * fp,uint32_t vt,unsigned char *dta, uint32_t sz);
const char *getFunkKindName (int32_t fkind);
const char *getInvokeKindName (int32_t ikind);
const char *getParamFlagName (uint32_t pflag);
const char *getTKindName (uint32_t tkind);
void printVarflags (FILE *fp, uint32_t flags);
void printFuncFlags (FILE *fp, uint32_t flags);
void printTypFlags (FILE *fp, uint32_t flags);

static void
dumpMemInfo (FILE *fp, unsigned char *dta,uint32_t cVar, uint32_t cFunc,uint32_t tkind);

static const char *getVTTypeName (uint32_t vt, uint32_t *dataSize);
static void dumpMem (FILE *fp, unsigned char *dta,unsigned char *umap, uint32_t cVar, uint32_t cFunc);
static void dumpImpFile (FILE *fp, unsigned char *segImp, uint32_t length, int32_t importinfos);
static void dumpTypeInfo (FILE *fp, unsigned char *segImp, uint32_t length, int32_t nr, unsigned char *umap, unsigned char *dta, size_t size, uint32_t *typinfo);
static void
dumpString (FILE *fp, unsigned char *segString, uint32_t length);
static void
dumpName (FILE *fp, unsigned char *segName, uint32_t len);
static void
dumpGuid (FILE *fp, unsigned char *d, uint32_t length);
static void
dumpRefTab (FILE *fp, unsigned char *d, uint32_t len);
static void
dumpTypedesc (FILE *fp, unsigned char *d,uint32_t len);
static void
dumpImpFiles (FILE *fp, unsigned char *d, uint32_t len);
static void
dumpArrayDesc (FILE *fp, unsigned char *d, uint32_t len);
static void
dumpCustomData (FILE *fp, unsigned char *d, uint32_t len);
static void
dumpCustomDataGuid (FILE *fp, unsigned char *d, uint32_t len);

sTITyps ti2_typs;

void dumpInfo (FILE *fp, unsigned char *dta, size_t size)
{
  char *umap;
  sTypeLibMSFT *t = (sTypeLibMSFT *) dta;
  unsigned char *d;
  sSegMSFT *segs;
  int32_t *typeinfos;
  int i;

  TI_init_typs (&ti2_typs);

  if (!t || !size)
    return;
  if (t->magic1 != TYPELIB_MSFT_MAGIC)
  {
    size_t k,j;
    fprintf (fp, "Unknown magic 0x%x (%"PRIxMAX")\n", t->magic1, (uintmax_t) size);
    for (k = 0; k < size && k < (16 * 32);)
    {
      fprintf (fp, "0x%08"PRIxMAX": ", (uintmax_t)k);
      for (j=0; j < 16 && k < size && k < (16 * 32); j++, k++)
      {
	fprintf (fp, " %02X", dta[k]);
      }
      fprintf (fp,"\n");
    }
    return;
  }
  umap = (char *) malloc (size + 1);
  memset (umap, 0, size);
  umap[size]=1;
  i = 0;
  if (t->var_flags & 0x100)
    i++;
  typeinfos= (int32_t *) &t->dta[i];
  d = (unsigned char *) &typeinfos[t->nr_typeinfos];

  segs = (sSegMSFT *) d;
  d = (unsigned char *) &segs[eSegMSFT_MAX];
  memset (umap, 1, (size_t) (d-dta));

  for (i=0;i<eSegMSFT_MAX;i++)
    {
      if (segs[i].length != 0)
	memset (umap + segs[i].offset, 1, segs[i].length);
    }

  /* Initialize constants pools.  */
  TI2_import_name (&ti2_typs,dta + segs[eSegMSFT_NAME].offset, segs[eSegMSFT_NAME].length);
  TI2_import_string (&ti2_typs,dta + segs[eSegMSFT_STRING].offset, segs[eSegMSFT_STRING].length);
  TI2_import_guid (&ti2_typs,dta + segs[eSegMSFT_GUID].offset, segs[eSegMSFT_GUID].length);
  TI2_import_importlibs (&ti2_typs, dta + segs[eSegMSFT_IMPORTFILES].offset, segs[eSegMSFT_IMPORTFILES].length);
  TI2_import_importref (&ti2_typs, dta + segs[eSegMSFT_IMPORTINFO].offset, segs[eSegMSFT_IMPORTINFO].length);
  TI2_import_typinfo_names (&ti2_typs,
    dta + segs[eSegMSFT_TYPEINFO].offset, segs[eSegMSFT_TYPEINFO].length);
  TI2_import_typedesc (&ti2_typs,dta + segs[eSegMSFT_TYPEDESC].offset, segs[eSegMSFT_TYPEDESC].length);
  TI2_import_customdata (&ti2_typs, dta + segs[eSegMSFT_CUSTDATA].offset, segs[eSegMSFT_CUSTDATA].length);
  TI2_import_customdataguid (&ti2_typs, dta + segs[eSegMSFT_CUSTDATAGUID].offset, segs[eSegMSFT_CUSTDATAGUID].length);
  TI2_import_array (&ti2_typs, dta + segs[eSegMSFT_ARRAYDESC].offset, segs[eSegMSFT_ARRAYDESC].length);
  TI2_import_ref (&ti2_typs, dta + segs[eSegMSFT_REFERENCES].offset, segs[eSegMSFT_REFERENCES].length);
  fprintf (fp, "/* TypeLib V%u.%u Version:%d, SetFlags:0x%x */\n", t->ver_major,t->ver_minor,t->version,
    t->flags);
  fprintf (fp, " Guid at ");
  printPrefix (fp, "Guid_", t->pos_guid);
  fprintf (fp, ", Lcid1: %d Lcide2: %d\n", t->lcid,t->lcid2);
  fprintf (fp, " var flags: 0x%x\n", t->var_flags);
  fprintf (fp, " # of typeinfos: %d, # of import infos: %d\n",
    t->nr_typeinfos, t->nr_impinfos);
  fprintf (fp, " helpstring: ");
  printPrefix (fp, "Str_", t->helpstring);
  fprintf (fp, ", helpfile: ");
  printPrefix (fp, "Str_", t->helpfile);
  fprintf (fp, ", helpstring-context:%d, help-context:%d\n",
    t->helpstringcontext, t->helpcontext);
  fprintf (fp, " Nametable strings:%d with %u # of characters. Name is ",
    t->nametable_count,t->nametable_size);
  printPrefix (fp, "Name_", t->name_offset);
  fprintf (fp, "\n");
  fprintf (fp," Custom data offset: %d, Res44(Hash):0x%x, Res48(name hash):0x%x\n",
    t->custom_data_offset, t->res44, t->res48);
  fprintf (fp, " Dispatch: %d\n", t->dispatchpos);
  if (t->var_flags & 0x100)
  {
    fprintf (fp, " HelpstringDll: ");
    printPrefix (fp, "Str_", t->dta[0]);
    fprintf (fp, "\n");
  }

  for (i=0;i<eSegMSFT_MAX;i++)
  {
    fprintf (fp," Seg %d: offset=", i);
    if (((int) segs[i].offset) < 0)
      fprintf (fp, "%d", segs[i].offset);
    else
      fprintf (fp, "0x%x length=0x%x", segs[i].offset, segs[i].length);
    fprintf (fp, ", res08=%d, res0c=%d\n",
      segs[i].res08,segs[i].res0c);
  }
  for (i=0;i<eSegMSFT_MAX;i++)
  {
    switch (i) {
    case eSegMSFT_TYPEINFO:
      dumpTypeInfo (fp, dta + segs[eSegMSFT_TYPEINFO].offset, segs[eSegMSFT_TYPEINFO].length,
	t->nr_typeinfos, (unsigned char *) umap, dta, size, (uint32_t *) typeinfos);
      break;
    case eSegMSFT_IMPORTINFO:
      dumpImpFile (fp, dta + segs[eSegMSFT_IMPORTINFO].offset, segs[eSegMSFT_IMPORTINFO].length,
	t->nr_impinfos);
      break;
    case eSegMSFT_TYPEDESC:
      dumpTypedesc (fp ,dta + segs[eSegMSFT_TYPEDESC].offset, segs[eSegMSFT_TYPEDESC].length);
      break;
    case eSegMSFT_IMPORTFILES:
      dumpImpFiles (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_ARRAYDESC:
      dumpArrayDesc (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_CUSTDATA:
      dumpCustomData (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_CUSTDATAGUID:
      dumpCustomDataGuid (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_REFERENCES:
      dumpRefTab (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_STRING:
      dumpString (fp, dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_NAME:
      dumpName (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_GUID:
      dumpGuid (fp ,dta + segs[i].offset, segs[i].length);
      break;
    case eSegMSFT_GUIDHASH:
      fprintf (fp,"GUIDHASH:\n");
      dumpDecFp(fp, dta + segs[i].offset, segs[i].length,"Guid_");
      break;
    case eSegMSFT_NAMEHASH:
      fprintf (fp,"NAMEHASH:\n");
      dumpDecFp(fp, dta + segs[i].offset, segs[i].length,"Name_");
      break;
    default:
      if(segs[i].length == 0)
	break;
      fprintf (fp,"Segment %d\n", i);
      dumpHexFp (fp, 0, dta + segs[i].offset, segs[i].length);
      break;
    }
  }
  {
    size_t lr, off = 0;
    size_t li = 0;
    while (li < size)
      {
	if (umap[li] == 1)
	{
	  do { li++; } while (li < size && umap[li] == 1);
	  off = 0;
	  continue;
	}
	lr = li + 1;
	while (lr < size && umap[lr] == 0)
	  lr++;
	if (umap[li] == 3)
	  fprintf (fp, "\n");
	else
	{
	  off = 0;
	  fprintf (fp," mem:0x%x\n", (int32_t) li);
	}
	dumpHexFp (fp,off, &dta[li], (lr-li));
	off += (lr-li);
	li = lr;
      }
  }
  TI_dest_typs (&ti2_typs);
}

static void
dumpTypeInfo (FILE *fp, unsigned char *segImp, uint32_t length, int32_t nr, unsigned char *umap,
	      unsigned char *dta, size_t size, uint32_t*typinfo)
{
  sMSFT_TypeInfoBase *t = (sMSFT_TypeInfoBase *) segImp;
  int32_t i;
  uint32_t off = 0;

  if (!length)
    return;
  fprintf (fp,"Has %d typeinfo blocks\n", nr);
  for (i=0;i<nr;i++) {
    if (t[i].memoffset > 0 && umap[t[i].memoffset]!=1)
      umap[t[i].memoffset]=2;
    fprintf (fp, " ");
    printPrefix2 (fp, "TypeB_", (int32_t) off);
    fprintf (fp, ": #%d, TypInfoId:%d",i, typinfo[i]);
    if (t[i].cElement != 0)
      fprintf (fp, "(mem:0x%x) ", t[i].memoffset);
    off += sizeof (sMSFT_TypeInfoBase);
    fprintf (fp, ", typekind:#%u, %s:0x%x, res2:%u, res3:%d, res4:%d\n",
      (t[i].typekind >> 16) % 0xffff,
      getTKindName (t[i].typekind & 0xf),
      (t[i].typekind >> 4) & 0xfff,t[i].res2, t[i].res3, t[i].res4);
    fprintf (fp, "\t");
    if (t[i].res5 != 0)
      fprintf (fp, "res5:%d!=0,", t[i].res5);
    if (t[i].res7 != 0)
      fprintf (fp, "res7:%d!=0,", t[i].res7);
    if (t[i].res8 != 0)
      fprintf (fp, "res8:%d!=0,", t[i].res8);
    if (t[i].res9 != 0)
      fprintf (fp, "res9:%d!=0,", t[i].res9);
    fprintf (fp, "cVar:0x%x,cFunc:0x%x\n", (t[i].cElement>>16)&0xffff,t[i].cElement&0xffff);
    if (t[i].resA != 0)
      fprintf (fp, "\tresA:%d!=0,GUID:",t[i].resA);
    else
      fprintf (fp, "\tGUID:");
    printPrefix (fp, "Guid_", t[i].posguid);
    fprintf (fp, "\n\tName:");
    printPrefix (fp, "Name_", t[i].NameOffset);

    fprintf (fp, "\n\tVersion:%d\n\t", t[i].version);
    printTypFlags (fp, t[i].flags);
    if (t[i].docstringoffs != -1)
      {
	fprintf (fp, " Doc:");
	printPrefix (fp, "Str_", t[i].docstringoffs);
	fprintf (fp, "\n");
      }
    fprintf (fp, "\tHelpStringCtx:%d,HelpCtx:%d,ImplTypes:%d\n",
      t[i].helpstringcontext,t[i].helpcontext,t[i].cImplTypes);
    if (t[i].oCustData != -1)
      {
	fprintf (fp, "\tCustomData:");
	printPrefix (fp, "CD_", t[i].oCustData);
	fprintf (fp, "\n");
      }
    fprintf (fp,"\t");
    if (t[i].res18 != 0)
      fprintf (fp, "res18:%d != 0, ",t[i].res18);
    if (t[i].res19 != -1)
      fprintf (fp, "res19:%d != -1, ",t[i].res19);
    fprintf (fp, "VirtualTableSize+Inherits:%d,TypeSize:%d,OffsetTDT|BI|COC|INTF:0x%x\n"
      "\t#InheritFuncts:%d,unkown:%d\n",
      t[i].cbSizeVft,t[i].size,t[i].datatype1,
      (t[i].datatype2 >> 16)&0xffff, t[i].datatype2 & 0xffff);
    if (t[i].memoffset > 0 && t[i].memoffset < size)
      dumpMem (fp, dta + t[i].memoffset,&umap[t[i].memoffset],
	       (t[i].cElement>>16)&0xfff,t[i].cElement&0xfff);
    dumpMemInfo (fp, dta + t[i].memoffset,(t[i].cElement>>16)&0xfff,t[i].cElement&0xfff,
      t[i].typekind & 0xf);
  }
}

static void
dumpMemInfo (FILE *fp, unsigned char *dta, uint32_t cVar, uint32_t cFunc, uint32_t tkind)
{
  uint32_t off = 0;
  int32_t max = cVar + cFunc;
  sMSFT_memblob *b;
  sMSFT_func *func;
  sMSFT_var *var;
  uint32_t *d;
  if (!cVar && !cFunc)
    return;
  b = (sMSFT_memblob *) dta;
  d = (uint32_t *) &b->dta[b->size];
  while (off < b->size)
    {
      if (cFunc)
      {
	sMSFT_FuncParam *params;
	uint32_t oVars, *pData , *pCustData;
	int32_t c,cc;
	char *rettyp = NULL;
	char *fctname = NULL;

	func = (sMSFT_func *) &b->dta[off];
	c = func->nrArgs;
	oVars = func->rlen;
	oVars -= (c * 12);
	params = (sMSFT_FuncParam *) &b->dta[off+oVars];
	pData = func->data;
	pCustData = NULL;
	if (func->f.hasParamDefValue)
	  pCustData = (uint32_t *) &b->dta[off+oVars-c*4];
	off += func->rlen;
	fprintf (fp, "   #%u:", func->id);
	fprintf (fp, " oVTable:0x%x FuncDescSize:0x%x #Args:%u,#OptArgs:%u\n",
	  func->vtableOffset,func->funcdescSize,func->nrArgs,func->nrOptArgs);
	fprintf (fp, "\t  invokekind:%s nextIndexWithSameID:%u",
	  getInvokeKindName(func->f.invokeKind),
	  func->f.nextIndexWithSameID
	  );
	fprintf (fp, ", Offset:0x%x\n", d[max*2]);
	rettyp = TI_getVTorDref (&ti2_typs, func->datatype, "", 0);
	fctname = TI_get_typ_name (&ti2_typs, d[max], TITYP_NAME, "");
	if (d[0] < 0x100)
	  fprintf (fp, "\t[id(%u)", d[0]);
	else
	  fprintf (fp, "\t[id(0x%x)", d[0]);
	printFuncFlags (fp, func->flags);
	while ((char*) pData < (char *) params
	       && (!pCustData || ((char*) pData < (char*) pCustData)))
	{
	  int32_t jj;
	  fprintf (fp, "\t");
	  for (jj=0;jj<8 && (char*) pData < (char *) params
	       && (!pCustData || ((char*)pData < (char*) pCustData)); jj++,pData++)
	  {
	    fprintf (fp, "%s0x%x", (jj== 0 ? "" : ", "), *pData);
	  }
	  fprintf (fp,"\n");
	}
	fprintf (fp, "%s%s%s%s%s",
	  func->f.hasCustomData ? " customData" : "",
	  func->f.hasParamDefValue ? " paramDefValue" : "",
	  func->f.isOEntryNumeric ? " oEntryNumeric" : "",
	  func->f.hasRetvalParam ? " retvalParam" : "",
	  func->f.reserved1 ? " reserved1" : "");
	fprintf (fp, "]\n");
	fprintf (fp, "\t%s %s %s %s (",
	  rettyp,
	  getFunkKindName (func->f.funcKind),
	  getCallConvName (func->f.callconv),
	  fctname);
	free (rettyp);
	free (fctname);
	for (cc=0;cc< c;cc++)
	{
	  char *x, *n;
	  if (params[cc].oName == -1)
	    n = strdup ("");
	  else
	    n = TI_get_typ_name (&ti2_typs, (uint32_t) params[cc].oName, TITYP_NAME, "");
	  x = TI_getVTorDref (&ti2_typs,params[cc].dataType, n, 0);
	  free (n);
	  fprintf(fp,"[%s] %s",getParamFlagName(params[cc].flags), x);
	  free (x);
	  if (pCustData && (params[cc].flags & PARAMFLAG_FHASDEFAULT) != 0)
	  {
	    fprintf (fp," = ");
	    printValue(fp, &ti2_typs, pCustData[cc]);
	  }
	  if ((cc+1)!=c)
	  {
	    fprintf (fp, ",");
	    if ((cc&1)!=0)
	      fprintf(fp, "\n\t  ");
	  }
	}
	if (c == 0)
	  fprintf (fp, "void");
	fprintf (fp, ");\n");
	--cFunc;
      }
      else if (cVar)
      {
	char *varType,*varName;
	cVar--;
	var = (sMSFT_var *) &b->dta[off];
	off += var->rlen;
	fprintf (fp, "   #%u:", var->id);
	fprintf (fp, "\n\tvarKind:0x%x vardescSize:0x%x",var->varKind, var->vardescSize);
	fprintf (fp, ", Offset:0x%x\n", d[max*2]);
	varName = TI_get_typ_name (&ti2_typs, d[max], TITYP_NAME, "");
	varType = TI_getVTorDref (&ti2_typs,var->datatype, varName, 0);
	free (varName);
        if (d[0] < 0x100)
          fprintf (fp, "\t[id(%u)", d[0]);
        else
          fprintf (fp, "\t[id(0x%x)", d[0]);
	printVarflags (fp, var->flags);
	fprintf (fp, "] %s", varType);
	free (varType);
	if (var->varKind == tkind)
	  {
	    fprintf (fp, " = ");
	    printValue (fp, &ti2_typs, var->oValue);
	  }
	fprintf (fp,";\n");
      }
      else
	return;
      d++;
    }
}

static void
dumpMem (FILE *fp, unsigned char *dta, unsigned char *umap, uint32_t cVar, uint32_t cFunc)
{
  uint32_t off;
  unsigned char *d = dta;
  uint32_t oData1, oData2;
  if (fp)
    oData1 = 0;
  if (!cVar && !cFunc)
    return;
  oData1 = ((uint32_t *) d)[0];
  umap[4]=3;
  umap[4+(oData1&0xffff)]=3;
  off = 0;
  d += 4;
  while (off < oData1)
  {
    oData2 = ((uint32_t *) d)[0];
    d+= (oData2 & 0xffff);
    off+=oData2 & 0xffff;
    umap[(d-dta)]=3;
  }
}

/*
  default_type = 0x80000000 | (vt << 16) | vt;
    VT_LPSTR = 30,
    VT_LPWSTR = 31,
    case VT_LPSTR:
    case VT_LPWSTR:
        *encoded_type = 0xfffe0000 | vt;
  VT_BYREF VT_PTR
  VT_USERDEFINED
  VT_SAFEARRAY
  kind: 0x1a 26 == VT_PTR
    base-vt16: vt: if (0x80000000) -> vt + base-vt16
    base-vt16  if (!0x80000000) -> TypeD(vt&0xffff)
    0x7fff -> TypeD(vt&0xffff)
    0x7ffe -> vt&0xffff
  kind: 0x1b 27 == SAFEARRAY
  kind: 0x1c 28 == VT_CARRAY
    0x7ffe -> ArrayD(vt&0xffff)
  kind: 0x1d 29 == VT_USERDEFINED
    0x7fff -> (if !(vt&1) TypeB (vt&0xffff)
              if (vt&1) Imp (vt&0xfffe)
$$$$ */
static void
dumpTypedesc (FILE *fp, unsigned char *d, uint32_t len)
{
  sMSFT_TypeDesc *p;
  uint32_t off = 0;
  if (!len)
    return;
  fprintf (fp, "Type Description\n");
  while ((off + 7) < len)
  {
    p = (sMSFT_TypeDesc *) &d[off];
    fprintf (fp, " ");
    printPrefix2 (fp, "TypeD_", (int32_t) off);
    fprintf (fp, ": kind:0x%x, flags:0x%x, vt:0x%x, ",p->kind, p->flag, p->vt);
    
    switch ((p->kind))
    {
    case 26: /* VT_PTR */
      if ((p->vt & 0x80000000) != 0)
        {
          printVT (fp, ((uint32_t) p->vt) & 0xffff, NULL);
          if ((p->flag & 0x7fff) != 0x7ffe)
            fprintf (fp, " *");
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    printPrefix (fp, "ImpI_", p->oTypeB & 0xfffffffe);
	  else
	    printPrefix (fp, "TypeD_", p->oTypeB);
	  if ((p->flag & 0x7fff) != 0x7ffe)
	    fprintf (fp, " *");
        }
      break;
    case 27: /* SAFEARRAY */
      if ((p->vt & 0x80000000) != 0)
        {
          printVT (fp, ((uint32_t) p->vt) & 0xffff, NULL);
          if ((p->flag & 0x7fff) != 0x7ffe)
            fprintf (fp, " []");
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    printPrefix (fp, "ImpI_", p->oTypeB & 0xfffffffe);
	  else
	    printPrefix (fp, "TypeD_", p->oTypeB);
	  if ((p->flag & 0x7fff) != 0x7ffe)
	    fprintf (fp, " []");
        }
      break;
    case 28: /* VT_CARRAY */
      printPrefix (fp, "ArrayD_", p->oArrayD & 0xffff);
      break;
    case 29: /* VT_USERDEFINED */
      if ((p->vt & 0x80000000) != 0)
        {
          printVT (fp, ((uint32_t) p->vt) & 0xffff, NULL);
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    printPrefix (fp, "ImpI_", p->oTypeB & 0xfffffffe);
	  else
	    printPrefix (fp, "TypeB_", p->oTypeB);
        }
      break;
    default:
      fprintf (fp, " !!!");
      printVT (fp, (((uint32_t) (p->vt)) & 0xffff), NULL);
      if ((p->flag & 0xf000) == 0x4000)
	fprintf (fp, " *");
      break;
    }
    off += 8;
    fprintf (fp, "\n");
  }
}

static void
dumpImpFile (FILE *fp, unsigned char *segImp, uint32_t length, int32_t importinfos)
{
  MSFT_ImpInfo *p;
  uint32_t off = 0;
  if (!length)
    return;
  fprintf (fp, "ImportFile Information. Has %d Import Files\n", importinfos);
  while ((off + 11) < length)
  {
    p=(MSFT_ImpInfo *) &segImp[off];
    fprintf (fp, " ");
    printPrefix (fp, "ImpI_", (int) off);
    fprintf (fp, ": count:%d, flags:0x%x, tkind:%s, ",
      p->count, p->flags, getTKindName(p->tkind));
    printPrefix2 (fp, "Imp_", p->oImpFile);
    fprintf(fp, ", ");
    printPrefix2 (fp, ((p->flags & 0x1) != 0 ? "Guid_" : "TypeB_"), p->oGuid);
    fprintf(fp, "\n");
    off += 12;
  }
}

static void
dumpArrayDesc (FILE *fp, unsigned char *d, uint32_t len)
{
  uint32_t off = 0;
  sMSFT_ArrayDesc *p;
  if (!len)
    return;
  fprintf (fp, "Array Description\n");
  while ((off + 7) < len)
  {
    int i;
    p = (sMSFT_ArrayDesc *) &d[off];
    fprintf (fp, " ");
    printPrefix (fp, "ArrayD_", (int) off);
    fprintf (fp, ": vt:(0x%x)",p->vt);
    printVT (fp, p->vt >> 16, NULL);
    off += 8;
    fprintf (fp,", %u (%d bytes)", p->count, p->size);
    for (i=0;i<p->count;i++)
      fprintf (fp, ",[%u]", p->vt_offset[i*2]);
    off += p->size;
    off +=3; off &= ~3;
    fprintf (fp,"\n");
  }
}

static void
dumpImpFiles (FILE *fp, unsigned char *d, uint32_t len)
{
  sMSFT_ImpFiles *p;
  uint32_t off = 0;
  if (!len)
    return;
  fprintf (fp, "Import Files\n");
  while ((off + 13) < len)
  {
    uint16_t l;
    p = (sMSFT_ImpFiles *) &d[off];
    fprintf (fp, " ");
    printPrefix (fp, "Imp_", (int) off);
    off+=14;
    l = (p->flag >> 2);
    fprintf (fp, ": %d,%d,%d, flag:%u, \"",
      p->res1,p->res2,p->res3, (p->flag & 3));
    while (l > 0 && off < len)
    {
      if (d[off] >=0x20 && d[off] <= 0x7f)
	fprintf (fp,"%c", d[off++]);
      else
	fprintf (fp,"\\%03o", d[off++]);
      --l;
    }
    fprintf (fp, "\"\n");
    off += 3;
    off &= ~3;
  }
}

static void
dumpRefTab (FILE *fp, unsigned char *d, uint32_t len)
{
  sMSFT_RefTab *p;
  uint32_t off = 0;
  if (!len)
    return;
  fprintf (fp, "Reference Table\n");
  while ((off + 15) < len)
    {
      p = (sMSFT_RefTab *) & d[off];
      fprintf (fp, " ");
      printPrefix (fp, "Ref_", (int) off);
      fprintf (fp,": ");
      printPrefix (fp, "TypeB_", p->oData1);
      fprintf (fp,", %d, %d, ",p->no, p->data2);
      printPrefix (fp, "Ref_", p->oNextRef);
      fprintf (fp, "\n");
      off += sizeof (sMSFT_RefTab);
    }
}

static void
dumpName (FILE *fp, unsigned char *segName, uint32_t len)
{
  struct sMSFTNamePrologue {
    int32_t res1;
    int32_t res2;
#ifdef __GNUC__
    __extension__
#endif
    union {
      unsigned char v[4];
      uint16_t us[2];
    };
  };
#ifdef __GNUC__
  __extension__
#endif
  union {
    unsigned char *dta;
    struct sMSFTNamePrologue *p;
  } v;
  uint32_t off = 0;
  if (!len)
    return;
  fprintf (fp,"NameTable\n");
  while ((off + 12) < len)
  {
    unsigned char l;
    v.dta=&segName[off];
    fprintf (fp, " Name_%x", (int32_t) off);
    fprintf (fp, ": %d,",v.p->res1);
    printPrefix (fp,"Name_", v.p->res2);
    fprintf (fp, ", 0x%02x,0x%04x, \"", v.p->v[1], v.p->us[1]);
    l = v.p->v[0];
    off += 12;
    while (l > 0)
    {
      if (segName[off]>=0x20 && segName[off]<=0x7f)
	fprintf (fp, "%c", segName[off++]);
      else
	fprintf (fp, "\\%03o", segName[off++]);

      --l;
    }
    off = (off + 3) & ~3;
    fprintf (fp,"\"\n");
  }
}

static void
dumpGuid (FILE *fp, unsigned char *d, uint32_t length)
{
  uint32_t off = 0;
  struct sGuidTab {
    uint32_t data1;
    uint16_t data2[2];
    unsigned char data3[8];
    int32_t res1;
    int32_t res2; /* Forwarder GUID */
  };
  union {
    unsigned char *d;
    struct sGuidTab *g;
  } v;
  if (length==0)
    return;
  fprintf (fp,"GuidTab:\n");
  while ((off + 24) <= length)
    {
      fprintf (fp," ");
      printPrefix2 (fp, "Guid_", (int32_t) off);
      fprintf (fp,": ");
      v.d = &d[off];
      fprintf (fp,"%d,",v.g->res1);
      printPrefix2 (fp, "Guid_", v.g->res2);
      fprintf (fp,", \"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X\"\n",
	v.g->data1, v.g->data2[0], v.g->data2[1],
	v.g->data3[0],v.g->data3[1],v.g->data3[2],v.g->data3[3],
	v.g->data3[4],v.g->data3[5],v.g->data3[6],v.g->data3[7]);
      off += 24;
    }
  if (length != off)
    fprintf (fp," Junk at end of %u bytes\n", (length-off));
}

static void
dumpCustomDataGuid (FILE *fp, unsigned char *d, uint32_t len)
{
  uint32_t off = 0;
  sMSFT_CDGuid *p;

  if(!len)
    return;
  fprintf (fp, "CustomData GUIDs\n");
  while ((off + 11) < len)
  {
    p = (sMSFT_CDGuid *) &d[off];
    fprintf(fp," ");
    printPrefix2 (fp, "CDGuid_", (int) off);
    fprintf (fp, ": ");
    printPrefix (fp, "Guid_", p->oGuid);
    fprintf (fp,", ");
    printValue (fp, &ti2_typs, p->oData);
    fprintf (fp,", ");
    printPrefix (fp, "CDGuid_", p->next);
    fprintf (fp,"\n");
    off += 12;
  }
}

static void
dumpCustomData (FILE *fp, unsigned char *d, uint32_t len)
{
  sMSFT_CustomData *p;
  uint32_t off = 0;
  if (!len)
    return;
  fprintf (fp, "CustomData\n");
  while (off < len)
  {
    p = (sMSFT_CustomData *) &d[off];
    fprintf (fp, " ");
    printPrefix2 (fp, "CD_", (int32_t) off);
    fprintf (fp, ": ");
    off += printVT (fp,p->vt,p->dta) - 2;
    off = (off + 3) & ~3;
    fprintf (fp, "\n");
  }
}

static void
dumpString (FILE *fp, unsigned char *segString, uint32_t length)
{
  uint32_t off = 0;
  uint16_t len;
  union {
    unsigned char *dta;
    uint16_t *len;
  } v;
  if (!length)
    return;
  fprintf (fp,"StringTable\n");
  while ((off + 2) < length)
  {
    v.dta=&segString[off];
    len = v.len[0];
    fprintf (fp," ");
    printPrefix2 (fp, "Str_", (int) off);
    fprintf (fp,": \"");
    off+=2;
    while (len > 0)
    {
      if (segString[off]>=0x20 && segString[off]<=0x7f)
	fprintf (fp, "%c", segString[off++]);
      else
	fprintf (fp, "\\%03o", segString[off++]);

      --len;
    }
    fprintf(fp,"\"\n");
    off = (off + 3)&~3;
  }
}

void
dumpHexFp (FILE *fp, size_t off, const unsigned char *dta, size_t len)
{
  size_t i,k;
  char s[17];
  if (!len || !fp)
    return;
  for (i = 0; i < len;)
    {
      fprintf (fp, "0x%08x:", (uint32_t) (off + i));
      for (k=0; i < len && k < 16;k++,i++)
	{
	  fprintf (fp, " %02X", dta[i]);
	  if (dta[i] >= 0x20 && dta[i]<=0x7f)
	    s[k]=(char) dta[i];
	  else
	    s[k]='.';
	  s[k+1]=0;
	}
      fprintf (fp, " ; %s\n",s);
    }
}

void
dumpDecFp (FILE *fp, const unsigned char *dta, size_t len, const char *prefix)
{
  size_t i,j;
  if (!len)
    return;
  if ((len&3)!=0)
    fprintf (fp, "Has not 4 byte alignment!\n");
  len = (len & ~3);
  for (i = 0; i < len;)
  {
    fprintf (fp,"0x%x:", (uint32_t) (i/4));
    for (j=0;j< 4 && i < len;j++,i+=4)
    {
      fprintf (fp, "%s", (j == 0 ? " " : ","));
      printPrefix2 (fp, prefix ? prefix : "0x", *((const int32_t *) &dta[i]));
    }
    fprintf (fp,"\n");
  }
}

void
printPrefix2 (FILE *fp, const char *name, int32_t val)
{
  if (!name)
    name = "";
  if (val <= -1)
    fprintf (fp, "%d", val);
  else
    fprintf (fp, "%s%x", name, val);
}

void
printPrefix (FILE *fp, const char *name, int32_t val)
{
  if (!name)
    name = "";
  if (val <= -1)
    fprintf (fp, "%d", val);
  else
  {
    char *nam = NULL;
    if (!strcmp (name, "Name_"))
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_NAME, "");
    else if (!strcmp (name, "Str_"))
    {
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_STR, "");
      if (nam)
      {
	fprintf (fp, "\"%s\"", nam);
	free (nam);
	return;
      }
    }
    else if (!strcmp (name, "Guid_"))
    {
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_GUIDS, "");
    }
    else if (!strcmp (name, "TypeB_"))
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_TYPINFO_NAMES, "");
    else if (!strcmp (name, "TypeD_"))
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_DEREF, "");
    else if (!strcmp (name, "CD_"))
      nam = TI_get_typ_name (&ti2_typs, (uint32_t) val, TITYP_CUSTOMDATA, "");
    if (nam)
    {
      fprintf (fp,"%s",nam);
      free (nam);
    }
    else
      printPrefix2 (fp, name, val);
  }
}

static const char *
getVTTypeName (uint32_t vt, uint32_t *dataSize)
{
  static char str[128];
  const char *name = "";
  uint32_t sz = 0;
  switch ((vt&0xfff))
  {
  case 0: /* VT_EMPTY */ name = "EMPTY"; break;
  case 1: /* VT_NULL */ name = "NULL"; break;
  case 2: /* VT_I2 */ name = "short"; sz=2; break;
  case 3: /* VT_I4 */ name = "long"; sz=4; break;
  case 4: /* VT_R4 */ name = "FLOAT"; sz=4; break;
  case 5: /* VT_R8 */ name = "DOUBLE"; sz=8; break;
  case 6: /* VT_CY */ name = "CY"; sz=8; break;
  case 7: /* VT_DATE */ name = "DATE"; sz = 0xffffffff; break;
  case 8: /* VT_BSTR */ name = "BSTR"; sz = 0xfffffffe; break;
  case 9: /* VT_DISPATCH */ name = "IDispatch *"; sz = 0xffffffff; break;
  case 10: /* VT_ERROR */ name = "SCODE"; sz = 4; break;
  case 11: /* VT_BOOL */ name = "WINBOOL"; sz = 2; break;
  case 12: /* VT_VARIANT */ name = "VARIANT"; sz = 0xffffffff; break;
  case 13: /* VT_UNKNOWN */ name = "IUnknown *"; sz = 0xffffffff; break;
  case 14: /* VT_DECIMAL */ name = "DECIMAL"; sz = 16; break;
  case 16: /* VT_I1 */ name = "CHAR"; sz=1; break;
  case 17: /* VT_UI1 */ name = "UCHAR"; sz=1; break;
  case 18: /* VT_UI2 */ name = "USHORT"; sz=2; break;
  case 19: /* VT_UI4 */ name = "UINT"; sz=4; break;
  case 20: /* VT_I8 */ name = "LONGLONG"; sz=8; break;
  case 21: /* VT_UI8 */ name = "ULONGLONG"; sz=8; break;
  case 22: /* VT_INT */ name = "int"; sz=4; break;
  case 23: /* VT_UINT */ name = "unsigned int"; sz=4; break;
  case 24: /* VT_VOID */ name = "VOID"; sz=0; break;
  case 25: /* VT_HRESULT */ name = "HRESULT"; sz = 4; break;
  case 26: /* VT_PTR */ name = "PTR"; sz = 4; break;
  case 27: /* VT_SAFEARRAY */ name = "SAFEARRAY"; sz = 0xfffffffe; break;
  case 28: /* VT_CARRAY */ name = "CARRAY"; sz = 0xfffffffe; break;
  case 29: /* VT_USERDEFINED */ name = "USERDEFINED"; sz = 0xfffffffe; break;
  case 30: /* VT_LPSTR */ name = "LPSTR"; sz = 4; break;
  case 31: /* VT_LPWSTR */ name = "LPWSTR"; sz = 4; break;
  case 36: /* VT_RECORD */ name = "RECORD"; sz = 0xfffffffe; break;
  case 37: /* VT_INT_PTR */ name = "INT_PTR"; sz=4; break;
  case 38: /* VT_UINT_PTR */ name = "UINT_PTR"; sz = 4; break;
  case 64: /* VT_FILETIME */ name = "FILETIME"; sz = 8; break;
  case 65: /* VT_BLOB */ name = "BLOB"; sz = 0xfffffffe; /* Has 4 bytes size */ break;
  case 66: /* VT_STREAM */ name = "STREAM"; sz = 0xffffffff; break;
  case 67: /* VT_STORAGE */ name = "STORAGE";  sz = 0xffffffff; break;
  case 68: /* VT_STREAMED_OBJECT */ name = "STREAMED_OBJECT"; sz = 0xfffffffe; break;
  case 69: /* VT_STORED_OBJECT */ name = "STORED_OBJECT"; sz = 0xffffffff; break;
  case 70: /* VT_BLOB_OBJECT */ name = "BLOB_OBJECT"; sz = 0xfffffffe; break;
  case 71: /* VT_CF*/ name = "CF"; sz = 0xfffffffe; break;
  case 72: /* VT_CLSID */ name = "CLSID";sz = 0xfffffffe; break;
  case 73: /* VT_VERSIONED_STREAM */ name = "VERSIONED_STREAM";sz = 0xfffffffe; break;
  case  0xfff: /* VT_BSTR_BLOB */ name = "BSTR_BLOB"; sz = 0xfffffffe; break;
  default:
    sprintf (str, "VT_%08x", vt & 0xfff);
    name = &str[0]; sz = 0xffffffff;
    break;
  }
  if ((vt &0xf000) == 0x4000)
    sprintf (str, " *");
  if (dataSize)
    *dataSize = sz;
  return name;
}

uint32_t
printVT (FILE *fp, uint32_t vt, unsigned char *dta)
{
  uint32_t sz = 0;
  fprintf (fp, "%s", getVTTypeName (vt, &sz));
  if ((vt & 0x1000)!=0)
    fprintf (fp, " vector");
  if ((vt & 0x2000)!=0)
    fprintf (fp, " array");
  if ((vt & 0x4000)!=0)
    fprintf (fp, " byref");
  if ((vt & 0xf000)!=0)
    return 4;
  if (!dta)
    return sz + 4;
  if (sz == 0xfffffffe)
  {
    sz = *((uint32_t *) dta);
    printVTData (fp, vt & 0x7ff, &dta[4], sz);
    sz += 4;
  }
  else
    printVTData (fp, vt & 0x7ff, dta, sz);
  sz += 4;
  return sz;
}

void
printVTData (FILE * fp,uint32_t vt, unsigned char *dta, uint32_t sz)
{
  if (!sz && vt != 8)
    return;
  switch (vt) {
  case 16: /* VT_I1 */ fprintf (fp," = %d", *((char *) dta)); break;
  case 17: /* VT_UI1 */ fprintf (fp," = %u", *((unsigned char *) dta)); break;
  case 18: /* VT_UI2 */ fprintf (fp," = %u", *((uint16_t *) dta)); break;
  case 23: /* VT_UINT */
  case 19: /* VT_UI4 */ fprintf (fp," = %uU", *((uint32_t *) dta)); break;
  case 20: /* VT_I8 */
#ifdef _WIN32
    fprintf (fp," = %I64dLL", *((int64_t *) dta)); break;
#else
    fprintf (fp," = %lldLL", *((int64_t *) dta)); break;
#endif
  case 21: /* VT_UI8 */
#ifdef _WIN32
  fprintf (fp," = %I64uULL", *((uint64_t *) dta)); break;
#else
  fprintf (fp," = %lluULL", *((uint64_t *) dta)); break;
#endif
  case 10: /* VT_ERROR */
          fprintf (fp, " = (SCODE) %dL", *((int32_t *) dta)); break;
  case 11: /* VT_BOOL */
  case 2: /* VT_I2 */ fprintf (fp," = %d", *((int16_t *) dta)); break;
  case 22: /* VT_INT */
  case 3: /* VT_I4 */ fprintf (fp," = %d", *((int32_t *) dta)); break;
  case 4: /* VT_R4 */ fprintf (fp," = %f", *((float *) dta)); break;
  case 5: /* VT_R8 */ fprintf (fp," = %g", *((double *) dta)); break;
  case 6: /* VT_CY */
#ifdef _WIN32
    fprintf (fp," = %I64dLL", *((int64_t *) dta)); break;
#else
    fprintf (fp," = %lldLL", *((int64_t *) dta)); break;
#endif
  case 8: /* VT_BSTR */
    fprintf (fp," = \"");
    while (sz>0)
    {
      if (*dta >= 0x20 && *dta <= 0x7f)
	fprintf (fp, "%c", *dta);
      else
	fprintf (fp,"\\%03o", *dta);
      dta++; --sz;
    }
    fprintf (fp,"\"");
    break;
  case 25: /* VT_HRESULT */
  case 26: /* VT_PTR */
     fprintf (fp," = 0x%x", *((int *) dta)); break;
  default:
    break;
  }
}

const char *
getInvokeKindName (int32_t ikind)
{
  static char name[260];
  const char *ret;
  name[0] = 0;
  if ((ikind & INVOKIND_FUNC) != 0)
    strcat (name," function");
  if ((ikind & INVOKIND_PROPERTYGET) != 0)
    strcat (name," propertyget");
  if ((ikind & INVOKIND_PROPERTYPUT)!=0)
    strcat (name, " propertyput");
  if ((ikind & INVOKIND_PROPERTYPUTREF)!=0)
    strcat (name, " propertyputref");
  if ((ikind & ~0xf)!=0)
    sprintf (name + strlen (name)," | 0x%x",ikind & ~0xf);
  ret = &name[0];
  if (*ret == ' ')
    ret++;
  return ret;
}

const char *
getFunkKindName (int32_t fkind)
{
  static char name[260];
  const char *ret;
  switch (fkind)
  {
  case FUNCTKIND_VIRTUAL: ret = "virtual"; break;
  case FUNCTKIND_PUREVIRTUAL: ret = "pure virtual"; break;
  case FUNCTKIND_NONVIRTUAL: ret = ""; break;
  case FUNCTKIND_STATIC: ret = "static"; break;
  case FUNCTKIND_DISPATCH: ret = "dispatch"; break;
  default:
    sprintf (name, "FunkKind_%d", fkind);
    ret = &name[0];
    break;
  }
  return ret;
}

const char *
getCallConvName (int32_t cc)
{
  static char name[260];
  const char *ret = &name[0];
  switch (cc) {
  case CALLCONV_FASTCALL: ret = "__fastcall"; break;
  case CALLCONV_CDECL: ret = "__cdecl"; break;
  case CALLCONV_PASCAL: ret = "__pascal"; break;
  case CALLCONV_MACPASCAL: ret = "__macpascal"; break;
  case CALLCONV_STDCALL: ret = "__stdcall"; break;
  case CALLCONV_FPFASTCALL: ret = "__fpfastcall"; break;
  case CALLCONV_SYSCALL: ret = "__syscall"; break;
  case CALLCONV_MPWCDECL: ret = "__mpwcdecl"; break;
  case CALLCONV_MPWPASCAL: ret = "__mpwpascal"; break;
  default:
    sprintf (name, "CC_%d", cc);
    break;
  }
  return ret;
}

const char *
getParamFlagName (uint32_t pflag)
{
  static char name[260];
  const char *ret = &name[0];
  name[0]=0;
  if ((pflag&PARAMFLAG_FIN)!=0)
    strcat (name, " IN");
  if ((pflag&PARAMFLAG_FOUT)!=0)
    strcat (name, " OUT");
  if ((pflag&4)!=0)
    strcat (name, " | 4");
  if ((pflag &PARAMFLAG_FRETVAL)!=0)
    strcat (name," RETVAL");
  if ((pflag & PARAMFLAG_FOPT)!=0)
    strcat (name, " OPT");
  if ((pflag & PARAMFLAG_FHASDEFAULT)!=0)
    strcat (name, " DEFAULT");
  if ((pflag & ~0x3f)!=0)
    sprintf (name + strlen(name)," | 0x%x", pflag & ~0x3f);
  return ret;
}

void
printValue (FILE *fp, sTITyps *typs, uint32_t val)
{
  if ((val & 0x80000000) != 0)
    {
      union {
        long long i8;
        unsigned long long ui8;
        uint32_t ui4;
        int32_t i4;
        int16_t i2;
        uint16_t ui2;
        char i1;
        unsigned char ui1;
        float f4;
        double f8;
      } u;
      uint32_t vt = (val >> 26) & 0x1f;
      u.ui4 = val & 0x3fffffff;
      switch (vt)
        {
        case 0: case 1:
          break;
        case 2: /* VT_I2 */
	  if (abs ((int) u.i2) < 0x100)
            fprintf (fp, "(short) %d", u.i2);
	  else if (u.i2 < 0)
	    fprintf (fp, "(short) -0x%x", -u.i2);
	  else
	    fprintf (fp, "(short) 0x%x", u.i2);
          break;
	case 22: /* VT_INT */
        case 3: /* VT_I4 */
	  if (abs (u.i4) < 0x100)
            fprintf (fp, "(int) %d", u.i4);
	  else if (u.i4 < 0)
	    fprintf (fp, "(int) -0x%x", -u.i4);
          else
	    fprintf (fp, "(int) 0x%x", u.i4);
          break;
        case 4: /* VT_R4 */
          fprintf (fp, "(float) %g", u.f4); break;
        case 5: /* VT_R8 */
          fprintf (fp, "(double) %g", u.f8); break;
        case 6: /* VT_CY */
          fprintf (fp, "(CY) 0x%x", u.ui4); break;
	case 7: /* VT_DATE */
          fprintf (fp, "(DATE) 0x%x", u.ui4); break;
	case 8: /* VT_BSTR */
          fprintf (fp, "(BSTR) 0x%x", u.ui4); break;
	case 9: /* VT_DISPATCH */
          fprintf (fp, "(IDispatch *) 0x%x", u.ui4); break;
	case 10: /* VT_ERROR */
          fprintf (fp, "(SCODE) %d", u.i4); break;
	case 11: /* VT_BOOL */
          fprintf (fp, "(WINBOOL) %d", u.i2); break;
	case 12: /* VT_VARIANT */
          fprintf (fp, "(VARIANT) 0x%x", u.ui4); break;
	case 13: /* VT_UNKNOWN */
          fprintf (fp, "(IUnknown *) 0x%x", u.ui4); break;
	case 14: /* VT_DECIMAL */
          fprintf (fp, "(DECIMAL) 0x%x", u.ui4); break;
	case 16: /* VT_I1 */
          fprintf (fp, "(CHAR) %d", u.i1); break;
	case 17: /* VT_UI1 */
          fprintf (fp, "(UCHAR) 0x%x", u.ui1); break;
	case 18: /* VT_UI2 */
          fprintf (fp, "(USHORT) 0x%x", u.ui2); break;
	case 19: /* VT_UI4 */
          fprintf (fp, "(UINT) 0x%xU", u.ui4); break;
	case 20: /* VT_I8 */
#ifdef _WIN32
          fprintf (fp, "(LONGLONG) %I64dLL", u.i8); break;
#else
          fprintf (fp, "(LONGLONG) %lldLL", u.i8); break;
#endif
	case 21: /* VT_UI8 */
#ifdef _WIN32
          fprintf (fp, "(ULONGLONG) 0x%I64xULL", u.ui8); break;
#else
          fprintf (fp, "(ULONGLONG) 0x%llxULL", u.ui8); break;
#endif
	case 23: /* VT_UINT */
          fprintf (fp, "(unsigned int) 0x%xU", u.ui4); break;
	case 24: /* VT_VOID */
	  break;
	case 25: /* VT_HRESULT */
          fprintf (fp, "(HRESULT) %dL", u.i4); break;
	case 26: /* VT_PTR */
          fprintf (fp, "(void *) %u", u.ui4); break;
	case 27: /* VT_SAFEARRAY */
          fprintf (fp, "(SAFEARRAY) %u", u.ui4); break;
	case 28: /* VT_CARRAY */
          fprintf (fp, "(CARRAY) %u", u.ui4); break;
	case 29: /* VT_USERDEFINED */
          fprintf (fp, "%u", u.ui4); break;
	case 30: /* VT_LPSTR */
          fprintf (fp, "(LPSTR) %u", u.ui4); break;
	case 31: /* VT_LPWSTR */
          fprintf (fp, "(LPWSTR) %u", u.ui4); break;
        }
    }
  else
    {
      char *h = NULL;
      h = TI_get_typ_name (typs, (uint32_t) val, TITYP_CUSTOMDATA,"");
      if (h)
	{
	  fprintf (fp, "%s", h);
	  free (h);
	}
      else
	fprintf (fp, "CD_%x", val);
    }
}

const char *
getTKindName (uint32_t tkind)
{
  static char name[260];
  const char *ret = &name[0];

  switch (tkind)
  {
  case TKIND_ENUM: ret = "enum"; break;
  case TKIND_RECORD: return "struct"; break;
  case TKIND_MODULE: return "module"; break;
  case TKIND_INTERFACE: return "interface"; break;
  case TKIND_DISPATCH: return "dispatch"; break;
  case TKIND_COCLASS: return "coclass"; break;
  case TKIND_ALIAS: return "alias"; break;
  case TKIND_UNION: return "union"; break;
  default:
    sprintf (name,"TKIND_%u", tkind);
    break;
  }
  return ret;
}

void
printVarflags (FILE *fp, uint32_t flags)
{
  if (!flags)
    return;
  if ((flags & VARFLAG_FREADONLY)!=0)
    fprintf (fp, " readonly");
  if ((flags & VARFLAG_FSOURCE) != 0)
    fprintf (fp, " source");
  if ((flags & VARFLAG_FBINDABLE) != 0)
    fprintf (fp, " bindable");
  if ((flags & VARFLAG_FREQUESTEDIT)!=0)
    fprintf (fp, " requestedit");
  if ((flags & VARFLAG_FDISPLAYBIND)!=0)
    fprintf (fp, " displaybind");
  if ((flags & VARFLAG_FDEFAULTBIND)!=0)
    fprintf (fp, " defaultbind");
  if ((flags & VARFLAG_FHIDDEN)!=0)
    fprintf (fp, " hidden");
  if ((flags & VARFLAG_FRESTRICTED)!=0)
    fprintf (fp, " restricted");
  if ((flags & VARFLAG_FDEFAULTCOLLELEM)!=0)
    fprintf (fp, " defaultcollelem");
  if ((flags & VARFLAG_FUIDEFAULT)!=0)
    fprintf (fp, " uidefault");
  if ((flags & VARFLAG_FNONBROWSABLE)!=0)
    fprintf (fp, " nonbrowsable");
  if ((flags & VARFLAG_FREPLACEABLE)!=0)
    fprintf (fp, " replaceable");
  if ((flags & VARFLAG_FIMMEDIATEBIND)!=0)
    fprintf (fp, "immediatebind");
  if ((flags & ~0x1fff)!=0)
    fprintf (fp, " /* flags:0x%x */", (flags & ~0x1fff));
}

void
printFuncFlags (FILE *fp, uint32_t flags)
{
  if ((flags & FUNCFLAG_FRESTRICTED) != 0)
    fprintf (fp, " restricted");
  if ((flags & FUNCFLAG_FSOURCE) != 0)
    fprintf (fp, " source");
  if ((flags & FUNCFLAG_FBINDABLE) != 0)
    fprintf (fp, " bindable");
  if ((flags & FUNCFLAG_FREQUESTEDIT) != 0)
    fprintf (fp, " requestedit");
  if ((flags & FUNCFLAG_FDISPLAYBIND) != 0)
    fprintf (fp, " displaybind");
  if ((flags & FUNCFLAG_FDEFAULTBIND) != 0)
    fprintf (fp, " defaultbind");
  if ((flags & FUNCFLAG_FHIDDEN) != 0)
    fprintf (fp, " hidden");
  if ((flags & FUNCFLAG_FUSESGETLASTERROR) != 0)
    fprintf (fp, " usegetlasterror");
  if ((flags & FUNCFLAG_FDEFAULTCOLLELEM) != 0)
    fprintf (fp, " defaultcollelem");
  if ((flags & FUNCFLAG_FUIDEFAULT) != 0)
    fprintf (fp, " uidefault");
  if ((flags & FUNCFLAG_FNONBROWSABLE) != 0)
    fprintf (fp, " nobrowsable");
  if ((flags & FUNCFLAG_FREPLACEABLE) != 0)
    fprintf (fp, " replaceable");
  if ((flags & FUNCFLAG_FIMMEDIATEBIND) != 0)
    fprintf (fp, " immediatebind");
  if ((flags & ~0x1fff)!=0)
    fprintf (fp, " /* flags:0x%x */", (flags & ~0x1fff));
}

void
printTypFlags (FILE *fp, uint32_t flags)
{
  const char *first = "";
  if (flags!=0)
    fprintf (fp,"[");
  if ((flags & TYPEFLAG_FAPPOBJECT) != 0)
  { fprintf (fp, "%sappobject", first); first=" "; }
  if ((flags & TYPEFLAG_FCANCREATE) != 0)
    { fprintf (fp, "%scancreate", first); first=" "; }
  if ((flags & TYPEFLAG_FLICENSED) != 0)
    { fprintf (fp, "%slicensed", first); first=" "; }
  if ((flags & TYPEFLAG_FPREDECLID) != 0)
    { fprintf (fp, "%spredclid", first); first=" "; }
  if ((flags & TYPEFLAG_FHIDDEN) != 0)
    { fprintf (fp, "%shidden", first); first=" "; }
  if ((flags & TYPEFLAG_FCONTROL) != 0)
    { fprintf (fp, "%scontrol", first); first=" "; }
  if ((flags & TYPEFLAG_FDUAL) != 0)
    { fprintf (fp, "%sdual", first); first=" "; }
  if ((flags & TYPEFLAG_FNONEXTENSIBLE) != 0)
    { fprintf (fp, "%snonextensible", first); first=" "; }
  if ((flags & TYPEFLAG_FOLEAUTOMATION) != 0)
    { fprintf (fp, "%soleautomation", first); first=" "; }
  if ((flags & TYPEFLAG_FRESTRICTED) != 0)
    { fprintf (fp, "%srestricted", first); first=" "; }
  if ((flags & TYPEFLAG_FAGGREGATABLE) != 0)
    { fprintf (fp, "%saggregatable", first); first=" "; }
  if ((flags & TYPEFLAG_FREPLACEABLE) != 0)
    { fprintf (fp, "%sreplaceable", first); first=" "; }
  if ((flags & TYPEFLAG_FDISPATCHABLE) != 0)
    { fprintf (fp, "%sdispatchable", first); first=" "; }
  if ((flags & TYPEFLAG_FREVERSEBIND) != 0)
    { fprintf (fp, "%sreversbind", first); first=" "; }
  if ((flags & TYPEFLAG_FPROXY) != 0)
    { fprintf (fp, "%sproxy", first); first=" "; }
  if ((flags & ~0x7fff)!=0)
    fprintf (fp, " /* TYPFLAG:0x%x */", flags & ~0x7fff);
  if (flags!=0)
    fprintf (fp,"] ");
}
