/*
   Copyright (c) 2009-2016  mingw-w64 project

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
#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif
#include <string.h>
#include <inttypes.h>
#include <stdint.h>

#include "m_token.h"
#include "m_ms.h"

#ifdef __MSVCRT__
#define MY_LL  "I64"
#else
#define MY_LL  "ll"
#endif

static char *mt_strcat (char *h, const char *add);


libmangle_gc_context_t *
libmangle_generate_gc (void)
{
  libmangle_gc_context_t *h = (libmangle_gc_context_t *) malloc (sizeof (libmangle_gc_context_t));
  if (h)
    memset (h, 0, sizeof (libmangle_gc_context_t));
  return h;
}

static void *
alloc_gc (libmangle_gc_context_t *gc, size_t size)
{
  sGcElem *n = (sGcElem *) malloc (size + sizeof (sGcElem));
  if (!n)
    {
      fprintf (stderr, "error: Run out of memory for %" MY_LL "x byte(s)\n",
        (unsigned long long) size);
      abort ();
    }
  memset (n, 0, size + sizeof (sGcElem));
  n->length = size;
  if (gc->head == NULL)
    gc->head = n;
  else
    gc->tail->chain = n;
  gc->tail = n;
  return & n->dta[0];
}

void
libmangle_release_gc (libmangle_gc_context_t *gc)
{
  sGcElem *n;
  if (!gc)
    return;
  while ((n = gc->head) != NULL)
    {
      gc->head = n->chain;
      free (n);
    }
  gc->tail = NULL;
  free (gc);
}

static void
free_gc (libmangle_gc_context_t *gc, const void *p)
{
  sGcElem *n, *l = NULL;

  if (!gc || !p)
    return;
  n = gc->head;
  while (n != NULL)
    {
      const void *ptr = &n->dta[0];
      if (ptr == p)
        {
          if (!l)
            gc->head = n->chain;
          else
            l->chain = n->chain;
          if (gc->tail == n)
            gc->tail = l;
          free (n);
          return;
        }
      l = n;
      n = n->chain;
    }
}

uMToken *
gen_tok (libmangle_gc_context_t *gc, enum eMToken kind, enum eMSToken subkind, size_t addend)
{
  uMToken *ret;
  switch (kind)
    {
    case eMToken_value:
      addend += sizeof (sMToken_value);
      break;
    case eMToken_name:
      addend += sizeof (sMToken_name);
      break;
    case eMToken_dim:
      addend += sizeof (sMToken_dim);
      break;
    case eMToken_unary:
      addend += sizeof (sMToken_Unary);
      break;
    case eMToken_binary:
      addend += sizeof (sMToken_binary);
      break;
    default:
      abort ();
    }
  addend += (addend + 15) & ~15;
  ret = (uMToken *) alloc_gc (gc, addend);
  if (!ret)
    abort ();

  MTOKEN_KIND (ret) = kind;
  MTOKEN_SUBKIND (ret) = subkind;

  return ret;
}

static void
dump_tok1 (FILE *fp, uMToken *p)
{
  if (!p)
    return;
  switch (MTOKEN_KIND (p))
    {
      case eMToken_value:
        fprintf (fp, "'value:%d: ", MTOKEN_SUBKIND (p));
        if (MTOKEN_VALUE_SIGNED (p))
          {
            fprintf(fp, "%"MY_LL "dLL", MTOKEN_VALUE (p));
          }
        else
          {
            fprintf(fp, "0x%"MY_LL"xULL", MTOKEN_VALUE (p));
          }
        fprintf (fp,"'");
        break;
      case eMToken_name:
        fprintf (fp,"'name:%d %s'", MTOKEN_SUBKIND (p), MTOKEN_NAME (p));
        break;
      case eMToken_dim:
        fprintf (fp,"'dim:%d %s", MTOKEN_SUBKIND (p), MTOKEN_DIM_NEGATE (p) ? "-" : "");
        libmangle_dump_tok (fp, MTOKEN_DIM_VALUE (p));
        if (MTOKEN_DIM_NTTP (p))
          {
            fprintf (fp," ");
            libmangle_dump_tok (fp, MTOKEN_DIM_NTTP (p));
          }
        fprintf (fp,"'");
        break;
      case eMToken_unary:
        fprintf (fp,"'unary:%d ", MTOKEN_SUBKIND (p));
        libmangle_dump_tok (fp, MTOKEN_UNARY (p));
        fprintf (fp, "'");
        break;
      case eMToken_binary:
        fprintf (fp,"'binary:%d ", MTOKEN_SUBKIND (p));
        libmangle_dump_tok (fp, MTOKEN_BINARY_LEFT (p));
        fprintf (fp," ");
        libmangle_dump_tok (fp, MTOKEN_BINARY_RIGHT (p));
        fprintf (fp, "'");
        break;
      default:
        fprintf (fp,"'kind(%d/%d):", MTOKEN_KIND (p), MTOKEN_SUBKIND(p));
        abort ();
    }
}

void
libmangle_dump_tok (FILE *fp, uMToken *p)
{
  if (!p)
    return;
  fprintf (fp, "'[");

  while (p)
    {
      dump_tok1 (fp, p);
      p = MTOKEN_CHAIN (p);
      if (p) fprintf (fp,",");
    }
  fprintf (fp,"]'");
}

uMToken *
chain_tok (uMToken *l, uMToken *add)
{
  uMToken *p = l;
  if (!l)
    return add;
  if (!add)
    return l;
  while (MTOKEN_CHAIN (p))
    p = MTOKEN_CHAIN (p);
  MTOKEN_CHAIN (p) = add;

  return l;
}

uMToken *
gen_value (libmangle_gc_context_t *gc, enum eMSToken skind, uint64_t val, int is_signed, int size)
{
  uMToken *ret = gen_tok (gc, eMToken_value, skind, 0);
  MTOKEN_VALUE (ret) = val;
  MTOKEN_VALUE_SIGNED (ret) = is_signed;
  MTOKEN_VALUE_SIZE (ret) = size;
  
  return ret;
}

uMToken *
gen_name (libmangle_gc_context_t *gc, enum eMSToken skind, const char *name)
{
  uMToken *ret;
  
  if (!name)
    name = "";
  ret = gen_tok (gc, eMToken_name, skind, strlen (name) + 1);
  strcpy (MTOKEN_NAME (ret), name);

  return ret;
}

uMToken *
gen_dim (libmangle_gc_context_t *gc, enum eMSToken skind, uint64_t val, const char *non_tt_param, int fSigned, int fNegate)
{
  uMToken *ret = gen_tok (gc, eMToken_dim, skind, 0);
  
  MTOKEN_DIM_VALUE(ret) = gen_value (gc, eMST_val, val, fSigned, 8);
  if (non_tt_param)
    MTOKEN_DIM_NTTP(ret) = gen_name (gc, eMST_nttp, non_tt_param);
  MTOKEN_DIM_NEGATE(ret) = fNegate;
  return ret;
}

uMToken *
gen_unary (libmangle_gc_context_t *gc, enum eMSToken skind, uMToken *un)
{
  uMToken *ret = gen_tok (gc, eMToken_unary, skind, 0);
  MTOKEN_UNARY (ret) = un;
  return ret;
}

uMToken *
gen_binary (libmangle_gc_context_t *gc, enum eMSToken skind, uMToken *l, uMToken *r)
{
  uMToken *ret = gen_tok (gc, eMToken_binary, skind, 0);
  MTOKEN_BINARY_LEFT (ret) = l;
  MTOKEN_BINARY_RIGHT (ret) = r;
  return ret;
}

static char *
mt_strcat (char *h, const char *add)
{
  char *ret;
  if (!add || *add == 0)
    return h;
  if (!h)
    ret = strdup (add);
  else
    {
      ret = (char *) malloc (strlen (h) + strlen (add) + 1);
      if (ret)
        {
	  strcpy (ret, h);
	  strcat (ret, add);
        }
      free (h);
    }
  if (!ret)
    {
      fprintf (stderr, " *** Run out of memory.\n");
      abort ();
    }
  return ret;
}

static char *
sprint_decl1 (char *txt, uMToken *r)
{
  while (r != NULL)
    {
      switch (MTOKEN_KIND (r))
	{
        case eMToken_name:
	  switch (MTOKEN_SUBKIND (r))
	    {
	    default:
	    case eMST_unmangled: case eMST_name:
	    case eMST_vftable: case eMST_vbtable: case eMST_vcall:
	    case eMST_nttp: case eMST_rtti:
	    case eMST_cv: case eMST_type: case eMST_opname:
	      txt = mt_strcat (txt, MTOKEN_NAME (r));
	      break;
	    case eMST_colon:
	      txt = mt_strcat (txt, MTOKEN_NAME (r));
	      txt = mt_strcat (txt, ":");
	      break;
	    }
	  break;
	case eMToken_value:
	  switch (MTOKEN_SUBKIND (r))
	    {
	    default:
	      break;
	    case eMST_gcarray:
		txt = mt_strcat (txt, "__gc[");
	    case eMST_val:
	      if (! MTOKEN_VALUE_SIGNED (r))
	        {
		  char s[128];
		  if ((MTOKEN_VALUE (r) >> 32) != 0)
		    sprintf (s, "0x%lx%08lx", (unsigned long) (MTOKEN_VALUE (r) >> 32), (unsigned long) MTOKEN_VALUE (r));
		  else
		    sprintf (s,"0x%lx", (unsigned long) MTOKEN_VALUE (r));
		  strcat (s, "U");
		  txt = mt_strcat (txt, s);
	        }
	      else
	        {
		  char s[128];
		  sprintf (s,"%"MY_LL"d", (long long) MTOKEN_VALUE (r));
		  txt = mt_strcat (txt, s);
	        }
	      if (MTOKEN_VALUE_SIZE (r) == 8)
		txt = mt_strcat (txt, "LL");
	      else if (MTOKEN_VALUE_SIZE (r) == 4)
		txt = mt_strcat (txt, "L");
	      if (MTOKEN_SUBKIND (r) == eMST_gcarray)
		txt = mt_strcat (txt, "]");
	      break;
	    }
	  break;
	case eMToken_dim:
	  switch (MTOKEN_SUBKIND (r))
	    {
	      default:
		/* FALL THROUGH */
	      case eMST_dim:
		if (MTOKEN_DIM_NEGATE (r))
		  txt = mt_strcat (txt, "-");
		if (MTOKEN_DIM_NTTP (r))
		  txt = sprint_decl1 (txt, MTOKEN_DIM_NTTP (r));
		if (MTOKEN_DIM_VALUE (r))
		  txt = sprint_decl1 (txt, MTOKEN_DIM_VALUE (r));
		break;
	    }
	  break;
	case eMToken_unary:
	  switch (MTOKEN_SUBKIND (r))
	    {
  	    case eMST_slashed:
	      txt = mt_strcat (txt, "/");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, "/");
	      break;
	    case eMST_array:
	      txt = mt_strcat (txt, "[");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, "]");
	      break;
	    case eMST_ltgt:
	      txt = mt_strcat (txt, "<");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, ">");
	      break;
	    case eMST_frame:
	      txt = mt_strcat (txt, "{");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, "}");
	      break;
	    case eMST_rframe:
	      txt = mt_strcat (txt, "(");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, ")");
	      break;
	    case eMST_lexical_frame:
	      txt = mt_strcat (txt, "'");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      txt = mt_strcat (txt, "'");
	      break;
	    case eMST_throw:
	      txt = mt_strcat (txt, "throw ");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      break;
	    case eMST_destructor:
	      txt = mt_strcat (txt, "~");
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      break;
	    case eMST_element: case eMST_template_argument_list:
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      if (MTOKEN_CHAIN (r) != NULL)
		txt = mt_strcat (txt, ",");
	      break;
	    default:
	    case eMST_oper: case eMST_scope:
	      txt = sprint_decl1 (txt, MTOKEN_UNARY (r));
	      break;
	    }
	  break;
	case eMToken_binary:
	  switch (MTOKEN_SUBKIND (r))
	    {
	    default:
	    case eMST_combine: case eMST_ecsu:
	    case eMST_based:
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_LEFT (r));
	      txt = mt_strcat (txt, " ");
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_RIGHT (r));
	      break;
	    case eMST_coloncolon:
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_LEFT (r));
	      txt = mt_strcat (txt, "::");
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_RIGHT (r));
	      break;
	    case eMST_assign:
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_LEFT (r));
	      txt = mt_strcat (txt, "=");
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_RIGHT (r));
	      break;
	    case eMST_templateparam: case eMST_nonetypetemplateparam:
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_LEFT (r));
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_RIGHT (r));
	      break;
	    case eMST_exp:
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_LEFT (r));
	      txt = mt_strcat (txt, "e");
	      txt = sprint_decl1 (txt, MTOKEN_BINARY_RIGHT (r));
	      break;
	    }
	  break;
	default:
	  break;
	}
      r = MTOKEN_CHAIN (r);
    }
  return txt;
}

static void
trim_str (char *str)
{
  char *r, *l;
  l = r = str;
  while ( *r != '\0')
  {
    if ( *r == ' ') 
    {
       if (r[1]=='(' || r[1]=='[' || r[1]==' ') r++;
       else
       if (l!=str && (l[-1]=='*' || l[-1]=='&' || l[-1]==')')) r++;
       else
       if (l!=r) *l++ = *r++;
       else
       r++, l++;
    }
    else if (l!=r) *l++ = *r++;
    else r++, l++;
  }
  *l = '\0';
}

char *
libmangle_sprint_decl (uMToken *r)
{
  char *ret = NULL;
  if (r)
    ret = sprint_decl1(NULL, r);
  trim_str (ret);
  return ret;
}

void
libmangle_print_decl (FILE *fp, uMToken *r)
{
  char *ret = libmangle_sprint_decl (r);
  if (ret)
    {
      fprintf (fp, "%s\n", ret);
      free (ret);
    }
  else
    {
      fprintf (fp, "<NULL>\n");
    }
}

#if defined (TEST)

static const char *szTest[]= {
	"??_C@_0BL@CNOONJFP@?$GAplacement?5delete?5closure?8?$AA@",
	"??_C@_07LFCOJCAC@__int64?$AA@",
	"?outputString@UnDecorator@@0PADA",
	"?outputString@UnDecorator@@1PADA",
	"?outputString@UnDecorator@@2PADA",
	"?outputString@UnDecorator@@3PADA",
	"?outputString@UnDecorator@@4PADA",
	"?outputString@UnDecorator@@5PADA",
	"?outputString@UnDecorator@@6PADA",
	"?outputString@UnDecorator@@7PADA",
	"?outputString@UnDecorator@@8PADA",
	"?outputString@UnDecorator@@9PADA",
	"??_5DName@@QAEAAV0@ABV0@@Z",
	"??_7pDNameNode@@6B@",
	"??_7exception@@6B@",
	"??_Ebad_cast@@UAEPAXI@Z",
	"??_Fbad_cast@@QAEXXZ",
	"??_Gbad_cast@@UAEPAXI@Z",
	"??_M@YGXPAXIHP6EX0@Z@Z",
	"??_R1A@?0A@A@exception@@8",
	"??_R2exception@@8","??_R3exception@@8",
	"??_R0?AVexception@@@8","??_R4exception@@6B@",
	"??0Block@HeapManager@@QAE@XZ",
	"??0DNameNode@@IAE@XZ",
	"??0__non_rtti_object@@QAE@ABV0@@Z",
	"??1bad_typeid@@UAE@XZ",
	"??2@YAPAXIAAVHeapManager@@H@Z",
	"??3@YAXPAX@Z",
	"??4DName@@QAEAAV0@ABV0@@Z",
	"??4DName@@QAEAAV0@W4DNameStatus@@@Z",
	"??4DName@@QAEAAV0@D@Z",
	"??4DName@@QAEAAV0@PBD@Z",
	"??YReplicator@@QAEAAV0@ABVDName@@@Z",
	"??H@YA?AVDName@@W4DNameStatus@@ABV0@@Z",
	"??H@YA?AVDName@@PBDABV0@@Z",
	"__CallSettingFrame@12",
	"??3@YAXPAX@Z",
	"??_Etype_info@@UAEPAXI@Z",
	"??_Gtype_info@@UAEPAXI@Z",
	"??1type_info@@UAE@XZ",
	"??_R1A@?0A@A@type_info@@8",
	"??_R2type_info@@8",
	"??_R0?AVtype_info@@@8",
	"??_R4type_info@@6B@",
	"??_7type_info@@6B@",
	"??_Gtype_info@@UAEPAXI@Z",
	"??8type_info@@QBEHABV0@@Z",
/*	"@foo@bar@$bctr$q", borland */
	NULL
};

int main()
{
  int i;
  uMToken *h;
  char *txt;
  for (i = 0; szTest[i]!=NULL; i++)
  {
    libmangle_gc_context_t *gc = libmangle_generate_gc ();
    h = libmangle_decode_ms_name (gc, szTest[i]);
    txt = libmangle_sprint_decl (h);
    fprintf (stderr, "%s\n", txt);
    free (txt);
    libmangle_release_gc (gc);
  }
  return 0;
}
#endif
