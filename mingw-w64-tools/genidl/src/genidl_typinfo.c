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
#include <malloc.h>
#include <string.h>
#include <memory.h>

int32_t
TI_init_typs (sTITyps *ptyp)
{
  if (!ptyp)
    return -1;
  memset (ptyp, 0, sizeof (sTITyps));
  return 0;
}

int32_t
TI_dest_typs (sTITyps *ptyp)
{
  size_t i;
  int32_t j;
  if (!ptyp)
    return -1;
  for (j=0;j<TITYP_MAX;j++)
    {
      if (ptyp->buc[j].arr != NULL)
	{
	  for (i = 0; i < ptyp->buc[j].count; i++)
	    {
	      if (ptyp->buc[j].arr[i]->refstr)
		free (ptyp->buc[j].arr[i]->refstr);
	      if (ptyp->buc[j].arr[i]->poststr)
		free (ptyp->buc[j].arr[i]->poststr);
	      free (ptyp->buc[j].arr[i]);
	    }
	  free (ptyp->buc[j].arr);
	}
    }
  memset (ptyp, 0, sizeof (sTITyps));
  return 0;
}

int32_t TI_add_typ (sTITyps *ptyp, uint32_t memid, int32_t kind, int32_t refkind, uint32_t refmem,
		const char *refstr, const char *name, const char *poststr)
{
  sTITyp *t, **h;
  if (TI_get_typ (ptyp, memid, kind) != NULL || kind >= TITYP_MAX)
    return -1;
  if (!name)
    name = "";
  if (!refstr)
    refstr="";
  if (!poststr)
    poststr = "";
  if (ptyp->buc[kind].count >= ptyp->buc[kind].max)
    {
      h = (sTITyp **) malloc (sizeof (sTITyp *) * (ptyp->buc[kind].count + 32));
      if (ptyp->buc[kind].arr)
	{
	  memcpy (h, ptyp->buc[kind].arr, sizeof (sTITyp*) * ptyp->buc[kind].count);
	  free (ptyp->buc[kind].arr);
	}
      ptyp->buc[kind].arr = h;
      ptyp->buc[kind].max += 32;
    }
  t = (sTITyp *) malloc (sizeof (sTITyp) + strlen (name));
  t->memid = memid;
  t->kind = kind;
  t->refkind = refkind;
  t->refmem = refmem;
  t->refstr = strdup (refstr);
  t->poststr = strdup (poststr);
  strcpy (t->name, name);
  ptyp->buc[kind].arr[ptyp->buc[kind].count] = t;
  ptyp->buc[kind].count += 1;
  return 0;
}

sTITyp *
TI_get_typ (sTITyps *ptyp, uint32_t memid, int32_t kind)
{
  size_t i;
  if (!ptyp || kind < 0 || kind >= TITYP_MAX)
    return NULL;
  for (i = 0; i < ptyp->buc[kind].count; i++)
    {
      if (ptyp->buc[kind].arr[i]->kind == kind && ptyp->buc[kind].arr[i]->memid == memid)
	return ptyp->buc[kind].arr[i];
    }
  return NULL;
}

static char *
ti_cat (const char *t, const char *r)
{
  char *ret;
  size_t l;
  if (!t)
    t = "";
  if (!r)
    r = "";
  l = strlen (t) + strlen (r) +1;
  ret = (char *) malloc (l);
  strcpy (ret, t);
  strcat (ret, r);
  return ret;
}

static char *
ti_cat_freel (char *t, const char *r)
{
  char *ret = ti_cat (t, r);
  if (t)
    free (t);
  return ret;
}

static int32_t
end_isref (const char *ret)
{
  if (!ret || *ret == 0)
    return 1;
  ret += strlen (ret);
  if (ret[-1] == '&' || ret[-1] == '*' || ret[-1] == ']')
    return 1;
  return 0;
}


char *
TI_get_typ_name (sTITyps *ptyp, uint32_t memid, int32_t kind, const char *varName)
{
  static const char *szKind[TITYP_MAX] = {
    "Name_", "Str_", "Guid_", "TypeB_", "TypeD_", "Arr_", "Ref_", "Imp_",
    "Unknown_", "CD_", "CDGuid_", "ImpR_"
  };
  sTITyp *t = TI_get_typ (ptyp, memid, kind);
  char s[128];
  char *ret;

  if (!t)
    {
      sprintf (s, "%s%x",szKind[kind],memid);
      ret = strdup (s);
    }
  else if (t->name[0] == 0)
    {
      ret = TI_get_typ_name (ptyp, t->refmem, t->refkind, "");
    }
  else
    ret = strdup (t->name);
  if (t && t->refstr != NULL && t->refstr[0] != 0)
    {
      if (!end_isref (ret))
	ret = ti_cat_freel (ret, " ");
      ret = ti_cat_freel (ret, t->refstr);
    }
  if (varName != NULL && varName[0] != 0)
    {
      char *hl = strchr (ret, '[');
      char *ar = NULL;
      if (hl)
      {
	ar = strdup (hl);
	*hl = 0;
      }
      if (!end_isref (ret))
	ret = ti_cat_freel (ret, " ");
      ret = ti_cat_freel (ret, varName);
      if (ar)
	{
	  ret = ti_cat_freel (ret, ar);
	  free (ar);
	}
    }
  if (t && t->poststr != NULL && t->poststr[0] != 0)
    {
      if (!end_isref (ret) && t->poststr[0] != '[')
	ret = ti_cat_freel (ret, " ");
      ret = ti_cat_freel (ret, t->poststr);
    }
  return ret;
}

int32_t
TI2_import_name (sTITyps *nptr, unsigned char *dta, uint32_t len)
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
    return 0;
  while ((off + 12) <= len)
    {
      uint32_t memid = off;
      unsigned char l;
      char *name;
      v.dta = &dta[off];
      l = v.p->v[0];

      name = (char *) malloc (l + 1);
      if (!name)
	return -1;
      if (l != 0)
	memcpy (name, &dta[off + 12], l);
      name[l] = 0;

      if (TI_add_typ (nptr,memid,TITYP_NAME, 0,0,"", name, "") < 0)
	return -1;
      free (name);
      off = (12 + off + (uint32_t) l + 3) & ~3;
    }
  return 0;
}

int32_t
TI2_import_string (sTITyps *sptr, unsigned char *dta, uint32_t len)
{
  uint32_t off = 0;
  union {
    unsigned char *dta;
    unsigned short *len;
  } v;

  if (!len)
    return 0;

  while ((off + 2) <= len)
  {
    char *h;
    v.dta = &dta[off];
    h = (char *) malloc (v.len[0] + 1);
    memcpy (h, &dta[off + 2], v.len[0]);
    h[v.len[0]]=0;
    if (TI_add_typ (sptr, off, TITYP_STR, 0, 0, "", h, "") < 0)
      return -1;
    free (h);
    off += 2 + (uint32_t) v.len[0];
    off = (off + 3) & ~3;
  }
  return 0;
}

int32_t
TI2_import_guid (sTITyps *gptr, unsigned char *dta, uint32_t length)
{
  struct sGuidTab {
    uint32_t data1;
    uint16_t data2[2];
    unsigned char data3[8];
    int32_t res1;
    int32_t res2; /* Forwarder GUID */
  };

  char str[260];
  uint32_t off = 0;
  union {
    unsigned char *d;
    struct sGuidTab *g;
  } v;
  if (!length)
    return -1;
  while ((off + 24) <= length)
    {
      v.d = &dta[off];
      sprintf (str ,"\"%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X\"",
	v.g->data1, v.g->data2[0], v.g->data2[1],
	v.g->data3[0],v.g->data3[1],v.g->data3[2],v.g->data3[3],
	v.g->data3[4],v.g->data3[5],v.g->data3[6],v.g->data3[7]);
      TI_add_typ (gptr, (uint32_t) off, TITYP_GUIDS, 0, 0, "", str, "");
      off += 24;
    }
  return 0;
}

int32_t
TI2_import_typinfo_names (sTITyps *tptr, unsigned char *dta, uint32_t length)
{
  char name_unk[32];
  char prefix_unk[32];
  char *h;
  char *name;
  const char *prefix;
  sMSFT_TypeInfoBase *t = (sMSFT_TypeInfoBase *) dta;
  int32_t i;
  int32_t free_name;
  uint32_t off = 0;

  if (!length)
    return 0;
  i = 0;
  while ((off + sizeof (sMSFT_TypeInfoBase)) <= length)
  {
    free_name = 1;
    name = TI_get_typ_name (tptr, (uint32_t) t[i].NameOffset, TITYP_NAME,"");
    prefix = "";
    if (!name)
    {
      free_name = 0;
      sprintf (name_unk,"Name_%0x", t[i].NameOffset);
      name = &name_unk[0];
    }
    switch (t[i].typekind & 0xf)
    {
    case TKIND_ENUM: prefix = "enum "; break;
    case TKIND_RECORD: prefix = "struct "; break;
    case TKIND_MODULE: prefix = "module "; break;
    case TKIND_INTERFACE: prefix = "interface "; break;
    case TKIND_DISPATCH: prefix = "dispinterface "; break;
    case TKIND_COCLASS: prefix = "coclass "; break;
    case TKIND_ALIAS: break;
    case TKIND_UNION: prefix = "union "; break;
    default:
      prefix = &prefix_unk[0];
      sprintf (prefix_unk, "TK_%u ", t[i].typekind&0xf);
      break;
    }
    h = (char *) malloc (strlen (prefix) + strlen (name) + 1);
    sprintf (h, "%s%s", prefix, name);
    TI_add_typ (tptr, (uint32_t) off, TITYP_TYPINFO_NAMES, 0,0, "", h, "");
    free (h);
    if (free_name)
      free (name);
    off += sizeof (sMSFT_TypeInfoBase);
    i++;
  }
  return 0;
}

char *
getTypeBOrImpRef (sTITyps *dptr, uint32_t off, const char *var)
{
  if (off == (uint32_t) -1)
    return NULL;
  if ((off&1) != 0)
    return TI_get_typ_name (dptr, off & ~1U,TITYP_IMPREF, var);
  return TI_get_typ_name (dptr, off, TITYP_TYPINFO_NAMES, var);
}

int32_t
TI2_import_typedesc (sTITyps *dptr, unsigned char *dta, uint32_t len)
{
  sMSFT_TypeDesc *p;
  uint32_t off = 0;
  if (!len)
    return -1;
  while ((off + 7) < len)
  {
    p = (sMSFT_TypeDesc *) &dta[off];
    
    switch ((p->kind))
    {
    case 26: /* VT_PTR */
      if ((p->vt & 0x80000000) != 0)
        {
	  const char *name;
	  name = decode_VT_name_tmp (((uint32_t) (p->vt)) & 0xffff);
	  TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF, TITYP_UNKNOWN,
	      (uint32_t) p->oArrayD & 0xffff,
	      ((p->flag & 0x7fff) != 0x7ffe ? "*" : ""), &name[0], "");
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_IMPREF, (uint32_t) p->oTypeB & 0xfffffffe,
	      ((p->flag & 0x7fff) != 0x7ffe ? "*" : ""), "", "");
	  else
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_DEREF, (uint32_t) p->oTypeB,
	      ((p->flag & 0x7fff) != 0x7ffe ? "*" : ""), "", "");
        }
      break;
    case 27: /* SAFEARRAY */
      if ((p->vt & 0x80000000) != 0)
        {
	  const char *name;
	  name = decode_VT_name_tmp (((uint32_t) (p->vt)) & 0xffff);
	  TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF, TITYP_UNKNOWN,
	      (uint32_t) p->oArrayD  & 0xffff,
	      "", &name[0], ((p->flag & 0x7fff) != 0x7ffe ? "[]" : ""));
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_IMPREF, (uint32_t) p->oTypeB & 0xfffffffe,
	      "", "", ((p->flag & 0x7fff) != 0x7ffe ? "[]" : ""));
	  else
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_DEREF, (uint32_t) p->oTypeB,
	      "", "", ((p->flag & 0x7fff) != 0x7ffe ? "[]" : ""));
        }
      break;
    case 28: /* VT_CARRAY */
	TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF, TITYP_ARRAY,
	  (uint32_t) p->oArrayD & 0xffff, "", "", "");
	break;
    case 29: /* VT_USERDEFINED */
      if ((p->vt & 0x80000000) != 0)
        {
	  const char *name;
	  name = decode_VT_name_tmp (((uint32_t) (p->vt)) & 0xffff);
	  TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF, TITYP_UNKNOWN,
	      (uint32_t) p->oArrayD  & 0xffff,
	      "", &name[0], "");
        }
      else
        {
	  if ((p->oTypeB & 1) != 0)
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_IMPREF, (uint32_t) p->oTypeB & 0xfffffffe,
	      "", "", "");
	  else
	    TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF,
	      TITYP_TYPINFO_NAMES, (uint32_t) p->oTypeB,
	      "", "", "");
        }
      break;
    default:
      {
	const char *name;
	const char *prefix = "";
	name = decode_VT_name_tmp (((uint32_t) (p->vt)) & 0xffff);
	if ((p->flag & 0xf000) == 0x4000)
	  prefix = "*";
	TI_add_typ (dptr, (uint32_t) off, TITYP_DEREF, TITYP_UNKNOWN,
	    (uint32_t) p->oArrayD, prefix, &name[0], "");
      }
      break;
    }
    off += 8;
  }
  return 0;
}

int32_t
TI2_import_customdata (sTITyps *dptr, unsigned char *dta, uint32_t length)
{
  sMSFT_CustomData *p;
  uint32_t off = 0;
  if (!length)
    return 0;
  while (off < length)
  {
    uint32_t soff = off;
    char *s;
    s = NULL;
    p = (sMSFT_CustomData *) &dta[off];
    off += getVT_data (dptr, p->vt, p->dta, &s);
    TI_add_typ (dptr,soff,TITYP_CUSTOMDATA,0,0,"",s,"");
    if(s) free (s);
    off = (off + 3) & ~3;
    //fprintf (fp, "\n");
  }
  return 0;
}

size_t
getVT_data (sTITyps *dptr, uint32_t vt, unsigned char *dta, char **ret)
{
  char s[4096];
  size_t b, l, sz;
  if (dptr)
    sz = 0;
  l = getVT_size (vt, dta,&b);
  dta += b - 2;
  if (l == 0xffffffff)
    {
      if (vt == 8)
        sprintf (s, "L\"\"");
      else {
        fprintf (stderr, "vt: 0x%x with size of -1!!!\n", vt);
        sprintf (s, "vt:0x%x_zero", vt);
      }
      if (ret)
        *ret = strdup (s);
      return b;
    }
  sz = l;
  s[0] = 0;

  switch (vt) {
  case 16: /* VT_I1 */ sprintf (s,"(char) %d", *((char *) dta)); break;
  case 17: /* VT_UI1 */ sprintf (s,"(unsigned char) %u", *((unsigned char *) dta)); break;
  case 18: /* VT_UI2 */ sprintf (s,"(USHORT) %u", *((uint16_t *) dta)); break;
  case 23: /* VT_UINT */
  case 19: /* VT_UI4 */ sprintf (s,"(UINT) %uU", *((uint32_t *) dta)); break;
  case 20: /* VT_I8 */
#ifdef _WIN32
    sprintf (s,"(LONGLONG) %I64dLL", *((int64_t *) dta)); break;
#else
    sprintf (s,"(LONGLONG) %lldLL", *((int64_t *) dta)); break;
#endif
  case 21: /* VT_UI8 */
#ifdef _WIN32
  sprintf (s,"(ULONGLONG) %I64uULL", *((uint64_t *) dta)); break;
#else
  sprintf (s,"(ULONGLONG) %lluULL", *((uint64_t *) dta)); break;
#endif
  case 10: /* VT_ERROR */ sprintf (s, " = (SCODE) %dL", *((int32_t *) dta)); break;
  case 11: /* VT_BOOL */ sprintf (s,"(WINBOOL) %d", *((int16_t *) dta)); break;
  case 2: /* VT_I2 */ sprintf (s,"(short) %d", *((int16_t *) dta)); break;
  case 22: /* VT_INT */
  case 3: /* VT_I4 */ sprintf (s,"(int) %d", *((int32_t *) dta)); break;
  case 4: /* VT_R4 */ sprintf (s,"(float) %f", *((float *) dta)); break;
  case 5: /* VT_R8 */ sprintf (s,"(double) %g", *((double *) dta)); break;
  case 6: /* VT_CY */
#ifdef _WIN32
    sprintf (s,"(CY) %I64dLL", *((int64_t *) dta)); break;
#else
    sprintf (s,"(CY) %lldLL", *((int64_t *) dta)); break;
#endif
  case 8: /* VT_BSTR */
    sprintf (s,"L\"");
    while (sz>0 && sz < 4094)
    {
      if (strlen (s) >= 4080)
        {
          fprintf (stderr, "String too big (%lu)\n", (unsigned long) l);
          break;
        }
      if (*dta >= 0x20 && *dta <= 0x7f)
	sprintf (&s[strlen(s)], "%c", *dta);
      else
	sprintf (&s[strlen(s)],"\\%03o", *dta);
      dta++; --sz;
    }
    sprintf (&s[strlen(s)],"\"");
    break;
  case 25: /* VT_HRESULT */
  case 26: /* VT_PTR */
     sprintf (s,"(HRESULT) 0x%x", *((int32_t *) dta)); break;
  default:
    sprintf (s, "(%s) with %u size", decode_VT_name_tmp (vt), (uint32_t) l);
    break;
  }
  if (ret)
    *ret = strdup (s);
  return l + b;
}

size_t
getVT_size (uint32_t vt, unsigned char *dta, size_t *basesz)
{
  size_t ret = 0;
  size_t bsz = 2;

  switch (vt&0xfff) {
  case 0: /* VT_EMPTY */ break;
  case 1: /* VT_NULL */ break;
  case 2: /* VT_I2 */ ret = 2; break;
  case 3: /* VT_I4 */ ret = 4; break;
  case 4: /* VT_R4 */ ret = 4; break;
  case 5: /* VT_R8 */ ret = 8; break;
  case 6: /* VT_CY */ ret = 16; break;
  case 7: /* VT_DATE */ ret = 16; break;
  case 8: /* VT_BSTR */ ret = 0; bsz += 4; break;
  case 9: /* VT_DISPATCH */ ret = 4; break;
  case 10: /* VT_ERROR */ ret = 4; break;
  case 11: /* VT_BOOL */ ret = 2; break;
  case 12: /* VT_VARIANT */ ret = 0; break;
  case 13: /* VT_UNKNOWN */ ret = 4; break;
  case 14: /* VT_DECIMAL */ ret = 16; break;
  case 16: /* VT_I1 */ ret = 1; break;
  case 17: /* VT_UI1 */ ret = 1; break;
  case 18: /* VT_UI2 */ ret = 2; break;
  case 19: /* VT_UI4 */ ret = 4; break;
  case 20: /* VT_I8 */ ret = 8; break;
  case 21: /* VT_UI8 */ ret = 8; break;
  case 22: /* VT_INT */ ret = 4; break;
  case 23: /* VT_UINT */ ret = 4; break;
  case 24: /* VT_VOID */ ret = 0; break;
  case 25: /* VT_HRESULT */ ret = 4; break;
  case 26: /* VT_PTR */ ret = 4; break;
  case 27: /* VT_SAFEARRAY */ ret = 0; bsz+=4; break;
  case 28: /* VT_CARRAY */ ret = 0; bsz+=4; break;
  case 29: /* VT_USERDEFINED */ ret = 0; bsz+=4; break;
  case 30: /* VT_LPSTR */ ret = 4; break;
  case 31: /* VT_LPWSTR */ ret = 4; break;
  case 36: /* VT_RECORD */  ret = 0; bsz+=4; break;
  case 37: /* VT_INT_PTR */ ret = 4; break;
  case 38: /* VT_UINT_PTR */ ret = 4; break;
  case 64: /* VT_FILETIME */ ret = 8; break;
  case 65: /* VT_BLOB */  ret = 0; bsz+=4; break;
  case 66: /* VT_STREAM */  ret = 0; bsz+=4; break;
  case 67: /* VT_STORAGE */  ret = 0; bsz+=4; break;
  case 68: /* VT_STREAMED_OBJECT */  ret = 0; bsz+=4; break;
  case 69: /* VT_STORED_OBJECT */  ret = 0; bsz+=4; break;
  case 70: /* VT_BLOB_OBJECT */  ret = 0; bsz+=4; break;
  case 71: /* VT_CF*/ ret = 0; bsz+=4; break;
  case 72: /* VT_CLSID */ ret = 0; bsz+=4; break;
  case 73: /* VT_VERSIONED_STREAM */ ret = 0; bsz+=4; break;
  case  0xfff: /* VT_BSTR_BLOB */ ret = 0; bsz+=4; break;
  default:
    ret = 0; break;
    break;
  }
  if (bsz>2)
  {
    ret = *((uint32_t *) dta);
  }
  if (basesz)
    *basesz = bsz;
  return ret;
}

const char *
decode_VT_name_tmp (uint16_t vt)
{
  static char str[128];
  const char *name = "???";

  switch ((vt&0xfff))
  {
  case 0: /* VT_EMPTY */ name = "EMPTY"; break;
  case 1: /* VT_NULL */ name = "NULL"; break;
  case 2: /* VT_I2 */ name = "short"; break;
  case 3: /* VT_I4 */ name = "long"; break;
  case 4: /* VT_R4 */ name = "float"; break;
  case 5: /* VT_R8 */ name = "double"; break;
  case 6: /* VT_CY */ name = "CY"; break;
  case 7: /* VT_DATE */ name = "DATE"; break;
  case 8: /* VT_BSTR */ name = "BSTR"; break;
  case 9: /* VT_DISPATCH */ name = "IDispatch *"; break;
  case 10: /* VT_ERROR */ name = "SCODE"; break;
  case 11: /* VT_BOOL */ name = "WINBOOL"; break;
  case 12: /* VT_VARIANT */ name = "VARIANT"; break;
  case 13: /* VT_UNKNOWN */ name = "IUnknown *"; break;
  case 14: /* VT_DECIMAL */ name = "DECIMAL"; break;
  case 16: /* VT_I1 */ name = "CHAR"; break;
  case 17: /* VT_UI1 */ name = "UCHAR"; break;
  case 18: /* VT_UI2 */ name = "USHORT"; break;
  case 19: /* VT_UI4 */ name = "UINT"; break;
  case 20: /* VT_I8 */ name = "LONGLONG"; break;
  case 21: /* VT_UI8 */ name = "ULONGLONG"; break;
  case 22: /* VT_INT */ name = "int"; break;
  case 23: /* VT_UINT */ name = "unsigned int"; break;
  case 24: /* VT_VOID */ name = "void"; break;
  case 25: /* VT_HRESULT */ name = "HRESULT"; break;
  case 26: /* VT_PTR */ name = "PTR"; break;
  case 27: /* VT_SAFEARRAY */ name = "SAFEARRAY"; break;
  case 28: /* VT_CARRAY */ name = "CARRAY"; break;
  case 29: /* VT_USERDEFINED */ name = "USERDEFINED"; break;
  case 30: /* VT_LPSTR */ name = "LPSTR"; break;
  case 31: /* VT_LPWSTR */ name = "LPWSTR"; break;
  case 36: /* VT_RECORD */ name = "RECORD"; break;
  case 37: /* VT_INT_PTR */ name = "INT_PTR"; break;
  case 38: /* VT_UINT_PTR */ name = "UINT_PTR"; break;
  case 64: /* VT_FILETIME */ name = "FILETIME"; break;
  case 65: /* VT_BLOB */ name = "BLOB"; break;
  case 66: /* VT_STREAM */ name = "STREAM"; break;
  case 67: /* VT_STORAGE */ name = "STORAGE"; break;
  case 68: /* VT_STREAMED_OBJECT */ name = "STREAMED_OBJECT"; break;
  case 69: /* VT_STORED_OBJECT */ name = "STORED_OBJECT"; break;
  case 70: /* VT_BLOB_OBJECT */ name = "BLOB_OBJECT"; break;
  case 71: /* VT_CF*/ name = "CF"; break;
  case 72: /* VT_CLSID */ name = "CLSID"; break;
  case 73: /* VT_VERSIONED_STREAM */ name = "VERSIONED_STREAM"; break;
  case  0xfff: /* VT_BSTR_BLOB */ name = "BSTR_BLOB"; break;
  default:
    sprintf (str, "VT_%08x", vt & 0xfff);
    name = &str[0];
    break;
  }
  if ((vt & 0xf000) == 0x4000)
    strcat (str, " *");
  return name;
}

char *
TI_getVTorDref (sTITyps *ptyp,uint32_t vt, const char *varName, int beBase)
{
  char *name;
  if ((vt & 0x80000000)!=0)
  {
    name = strdup (decode_VT_name_tmp (vt));
    if (varName != NULL && varName[0] != 0)
    {
      name = ti_cat_freel (name, " ");
      name = ti_cat_freel (name, varName);
    }
  }
  else if ((vt&1)!=0)
    name = TI_get_typ_name (ptyp, vt & ~1, TITYP_IMPREF, varName);
  else if ((vt&3)!=0)
    name = TI_get_typ_name (ptyp, vt, TITYP_UNKNOWN, varName);
  else
  {
    if (!beBase)
      name = TI_get_typ_name (ptyp, vt, TITYP_DEREF, varName);
    else
      name = TI_get_typ_name (ptyp, vt, TITYP_TYPINFO_NAMES, varName);
  }
  return name;
}

int32_t
TI2_import_importlibs (sTITyps *iptr, unsigned char *dta, uint32_t len)
{
  sMSFT_ImpFiles *p;
  uint32_t off = 0;
  if (!len)
    return 0;
  while ((off + 13) < len)
  {
    char *h;
    unsigned short l;
    p = (sMSFT_ImpFiles *) &dta[off];
    l = (p->flag >> 2);
    h = (char *) malloc (l + 1);
    memcpy (h, &dta[off + 14], l);
    h[l] = 0;
    genidl_strlwr (h);
    TI_add_typ (iptr, (uint32_t) off, TITYP_IMP, 0,0,"",h,"");
    off = (off + 14 + l + 3) & ~3;
  }
  return 0;
}

int32_t
TI2_import_ref (sTITyps *gptr, unsigned char *dta, uint32_t len)
{
  sMSFT_RefTab *p;
  uint32_t off = 0;
  if (!len)
    return 0;
  while ((off + 15) < len)
    {
      char *h;
      p = (sMSFT_RefTab *) & dta[off];
      h = getTypeBOrImpRef (gptr, (uint32_t) p->oData1, "");
      TI_add_typ (gptr, (uint32_t) off, TITYP_REF, p->data2, p->oNextRef,"",h,"");
      free (h);
      off += sizeof (sMSFT_RefTab);
    }
  return 0;
}

int32_t
TI2_import_array (sTITyps *gptr, unsigned char *dta, uint32_t len)
{
  char postfix[256];
  uint32_t off = 0;
  sMSFT_ArrayDesc *p;
  if (!len)
    return 0;
  while ((off + 7) < len)
  {
    uint32_t num_dims;
    uint32_t size;
    char *name = NULL;
    uint32_t i;
    p = (sMSFT_ArrayDesc *) &dta[off];
    if ((p->vt & 0x80000000) != 0)
      name = strdup (decode_VT_name_tmp (p->vt));
    num_dims = p->count;
    size = p->size;
    if (!size)
      size = (num_dims * 2 * 4);
    postfix[0] = 0;
    for (i=0;i < num_dims; i++)
    {
      sprintf (&postfix[strlen (postfix)], "[%u]", p->vt_offset[i*2]);
    }
    TI_add_typ (gptr, (uint32_t) off, TITYP_ARRAY, TITYP_DEREF, (uint32_t) p->vt,"",
      (name ? name : ""), postfix);
    off += 8 + size;
    off +=3; off &= ~3;
  }
  return 0;
}

int32_t
TI2_import_importref (sTITyps *gptr, unsigned char *dta, uint32_t length)
{
  MSFT_ImpInfo *p;
  uint32_t off = 0;
  char *idstr;
  char *iname;
  if (!length)
    return 0;
  while ((off + 11) < length)
  {
    const char *str;
    char s[128];
    p = (MSFT_ImpInfo *) &dta[off];
    iname = TI_get_typ_name (gptr, (uint32_t) p->oImpFile, TITYP_IMP, "");
    
    if ((p->flags & 1) == 0)
      {
	sprintf (s, "TypeB_%x", p->oGuid);
      }
    else
      {
	char *ni = TI_get_typ_name (gptr, (uint32_t) p->oGuid & ~1, TITYP_GUIDS, "");
	if (ni)
	  {
	    strcpy (s, ni + 1);
	    if (strrchr (s, '\"') != NULL)
	      *strrchr (s, '\"')=0;
	    free (ni);
	  }
	else
	 sprintf (s, "Guid_%x", p->oGuid);
      }
    str = genidl_find_type (iname, &s[0]);
    /*if (!str)
      {
	 sprintf (s, "Name_%x", p->oGuid);
	 str = genidl_find_type (iname, &s[0]);
      }*/
    if (str)
      {
	TI_add_typ (gptr, (uint32_t) off, TITYP_IMPREF, 0,0, "", str, "");
      }
    else
      {
        idstr = (char *) malloc (strlen (s) + strlen (iname) + 2 + 10);
        sprintf (idstr, "%s_%s_%02x_%x", iname, s, p->flags, p->tkind);
	fprintf (stderr, "Type %s count: 0x%x tkind:0x%x not found\n", idstr, p->count, p->tkind);
        TI_add_typ (gptr, (uint32_t) off, TITYP_IMPREF, 0,0, "", idstr, "");  
        free (idstr);
      }
    if (iname)
      free (iname);
    off += 12;
  }
  return 0;
}

int32_t
TI2_import_customdataguid (sTITyps *gptr, unsigned char *dta, uint32_t len)
{
  if (gptr || dta || len)
    return 0;
  return 0;
}
