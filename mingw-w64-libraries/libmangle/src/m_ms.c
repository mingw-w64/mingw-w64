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

static uMToken *m_combine (sMSCtx *c, uMToken *l, uMToken *r);
static uMToken *m_type (sMSCtx *c, const char *typname);
static uMToken *m_cv (sMSCtx *c, const char *cv);
static uMToken *m_coloncolon (sMSCtx *c, uMToken *l, uMToken *r);
static uMToken *m_element (sMSCtx *c, uMToken *el);
static uMToken *m_array (sMSCtx *c, uMToken *dim);
static uMToken *m_scope (sMSCtx *c, uMToken *n);
static uMToken *m_oper (sMSCtx *c, uMToken *n);
static uMToken *m_name (sMSCtx *c, const char *str);
static uMToken *m_colon (sMSCtx *c, const char *str);
static uMToken *m_opname (sMSCtx *c, const char *str);
static uMToken *m_rtti (sMSCtx *c, const char *str);
static uMToken *m_frame (sMSCtx *c, uMToken *u);
static uMToken *m_rframe (sMSCtx *c, uMToken *u);
static uMToken *m_ltgt (sMSCtx *c, uMToken *u);
static uMToken *m_throw (sMSCtx *c, uMToken *u);
static uMToken *m_lexical_frame (sMSCtx *c, uMToken *u);

static uMToken *get_decorated_name (sMSCtx *c);
static uMToken *get_string_literal_type (sMSCtx *c);
static uMToken *get_symbol_name (sMSCtx *c);
static uMToken *get_zbuf_name (sMSCtx *c, int updateCache);
static uMToken *get_dimension_signed (sMSCtx *c);
static uMToken *get_dimension (sMSCtx *c,int fSigned, int fNegate);
static uMToken *extract_name (sMSCtx *c, char term);
static uMToken *get_scope (sMSCtx *c);
static uMToken *get_template_name (sMSCtx *c, int fReadTerminator);
static uMToken *get_operator_name (sMSCtx *c, int fIsTemplate, int *pfReadTemplateArguments);
static uMToken *get_template_argument_list (sMSCtx *c);
static uMToken *get_lexical_frame(sMSCtx *c);
static uMToken *get_string_encoding (sMSCtx *c, int wantBody);
static uMToken *get_template_constant (sMSCtx *c);
static uMToken *get_data_type (sMSCtx *c);
static uMToken *get_indirect_data_type(sMSCtx *c, uMToken *superType, char prType, uMToken *cvType, int thisFlag);
static uMToken *get_primary_data_type (sMSCtx *c, uMToken *superType);
static uMToken *get_based_type (sMSCtx *c);
static uMToken *get_scoped_name (sMSCtx *c);
static uMToken *get_basic_data_type (sMSCtx *c, uMToken *superName);
static uMToken *get_pointer_reference_type (sMSCtx *c, uMToken *cvType, uMToken *superType, char ptrChar);
static uMToken *get_indirect_function_type (sMSCtx *c, uMToken *superType);
static uMToken *get_pointer_reference_data_type (sMSCtx *c, uMToken *superType,int isPtr);
static uMToken *get_ECSU_data_type (sMSCtx *c);
static uMToken *get_enum_size_type (sMSCtx *c);
static uMToken *get_this_type (sMSCtx *c);
static uMToken *get_calling_convention (sMSCtx *c);
static uMToken *get_throw_types (sMSCtx *c);
static uMToken *get_argument_types (sMSCtx *c);
static uMToken *get_return_type (sMSCtx *c);
static uMToken *get_array_type (sMSCtx *c, uMToken *superType);
static uMToken *get_argument_list (sMSCtx *c);
static uMToken *compose_decl (sMSCtx *c, uMToken *symbol);
static uMToken *get_vftable_type (sMSCtx *c, uMToken *superType);
static int get_number_of_dimensions (sMSCtx *c);
static int get_encoded_type (sMSCtx *);
static uMToken *get_vdisp_map_type (sMSCtx *c, uMToken *superType);
static uMToken *get_ext_data_type (sMSCtx *c, uMToken *superType);

uMToken *
libmangle_decode_ms_name (libmangle_gc_context_t *gc, const char *name)
{
  sMSCtx ctx;
  sCached ZNameList, ArgList, TempArgList;
  uMToken *ret = NULL;
  if (!name || *name == 0)
    return NULL;
  
  memset (&ctx, 0, sizeof (ctx));
  ctx.gc = gc;
  memset (&ZNameList, 0, sizeof (ZNameList));
  memset (&ArgList, 0, sizeof (ArgList));
  memset (&TempArgList, 0, sizeof (TempArgList));
  ctx.name = name;
  ctx.end = name + strlen (name);
  ctx.pos = ctx.name;

  ctx.pZNameList = &ZNameList;
  ctx.pArgList = &ArgList;
  ctx.pTemplateArgList = &TempArgList;

#if 0  
  fprintf(stderr,"decode_ms_name: %s\n", name);
#endif

  if (name[0] == '?')
    {
      if (name[1] == '@')
        {
          SKIP_CHAR(&ctx,2);
          ret = get_decorated_name (&ctx);
          /* CV: ??? */
        }
      else if (name[1] == '$')
        {
           if (!(ret = get_template_name (&ctx, 0)))
             ret = get_decorated_name (&ctx);
        }
      else
        ret = get_decorated_name (&ctx);
    }
  else
    ret = get_decorated_name (&ctx);

  if (!ret)
    {
      ret = gen_name (ctx.gc, eMST_unmangled, name);
    }

  return ret;
}

char *
libmangle_encode_ms_name (libmangle_gc_context_t *gc, uMToken *tok)
{
  return NULL;
}

static uMToken *
get_decorated_name (sMSCtx *c)
{
  uMToken *n = NULL;
  uMToken *d = NULL;
  int isudc;
  if (GET_CHAR (c) != '?')
    {
      if (GET_CHAR (c) == 0)
         c->err = 1;
      fprintf (stderr,"*** get_decorated_name %s empty\n", c->name);
      return NULL;
    }
  INC_CHAR (c);
  
  n = get_symbol_name (c);
  isudc = (n && (MTOKEN_FLAGS (n) & MTOKEN_FLAGS_UDC)) ? 1 : 0;
  if (c->err)
    return n;
  if (GET_CHAR (c) != 0 && GET_CHAR (c) != '@')
    {
      d = get_scope (c);
      if (d)
        {
	  if (c->fExplicitTemplateParams == 0)
	    n = m_coloncolon (c, d, n);
	  else
	    {
	      c->fExplicitTemplateParams = 0;
	      n = m_combine (c, n, d);
	      if (GET_CHAR (c) != '@')
	        {
		  d = get_scope (c);
		  n = m_coloncolon (c, d, n);
	        }
	    }
        }
    }
  if (!n)
    return n;
  if (isudc)
    MTOKEN_FLAGS (n) |= MTOKEN_FLAGS_UDC;
  if (MTOKEN_FLAGS (n) & MTOKEN_FLAGS_NOTE)
    return n;
  if (GET_CHAR (c) != 0)
    {
      if (GET_CHAR (c) != '@')
	return NULL;
      INC_CHAR (c);
    }
  return compose_decl (c, n);
}


static uMToken *
get_symbol_name (sMSCtx *c)
{
  if (GET_CHAR (c) != '?')
    return get_zbuf_name (c, 1);
  if (c->pos[1] == '$')
    return get_template_name (c, 1);
  INC_CHAR (c);
  return get_operator_name (c, 0, NULL);
}

static uMToken *
get_zbuf_name (sMSCtx *c, int updateCache)
{
  const char *ntmp;
  uMToken *dim, *ret = NULL, *n = NULL;
  
  if (GET_CHAR(c) >= '0' && GET_CHAR (c) <= '9')
    {
      ret = c->pZNameList->arr[GET_CHAR (c) - '0'];
      INC_CHAR (c);
      return ret;
    }
  if (GET_CHAR (c) == '?')
    {
      n = get_template_name (c, 0);
      if (GET_CHAR (c) == '@')
        INC_CHAR (c);
      if (updateCache && c->pZNameList->count < 10)
        {
          c->pZNameList->arr[c->pZNameList->count] = n;
          c->pZNameList->count += 1;
        }
      return n;
    }
  ntmp="template-parameter-";
  if (!strncmp(c->pos,"template-parameter-",19))
    SKIP_CHAR (c,19);
  else
    {
      ntmp="generic-type-";
      if (!strncmp(c->pos, "generic-type-", 13))
        SKIP_CHAR (c,13);
      else
        {
          n = extract_name (c, '@');
          if (updateCache && c->pZNameList->count < 10)
            {
              c->pZNameList->arr[c->pZNameList->count] = n;
              c->pZNameList->count += 1;
            }
          return n;
        }
    }
  dim=get_dimension_signed (c);
  n=chain_tok (gen_name (c->gc, eMST_templargname, ntmp), dim);
  if (updateCache && c->pZNameList->count < 10)
    {
      c->pZNameList->arr[c->pZNameList->count] = n;
      c->pZNameList->count += 1;
    }
  return n;
}

static uMToken *
get_dimension_signed (sMSCtx *c)
{
   if (GET_CHAR (c) == 0)
     {
       c->err=1;
       return NULL;
     }
   if (GET_CHAR (c) != '?')
     return get_dimension (c, 0, 0);
   INC_CHAR (c);
   return get_dimension (c, 0, 1/* be negative*/);
}

static uMToken *
get_dimension (sMSCtx *c, int fSigned, int fNegate)
{
  const char *non_tt_param=NULL;
  uint64_t v_r = 0ULL, v1;
  
  if (GET_CHAR (c) == 'Q')
    {
      INC_CHAR (c);
      non_tt_param="'non-type-template-parameter";
    }
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return NULL;
    }
  if (GET_CHAR (c) >= '0' && GET_CHAR (c) <= '9')
    {
      uint64_t v = (uint64_t) ((GET_CHAR (c)-'0') + 1);
      INC_CHAR (c);
      return gen_dim (c->gc, eMST_dim,v, non_tt_param, fSigned, fNegate);
    }

  while (GET_CHAR (c) != '@')
    {
      if (GET_CHAR (c) == 0)
        {
          c->err = 2;
          return NULL;
        }
      if (GET_CHAR (c) < 'A' || GET_CHAR (c) > 'P')
        {
          c->err = 1;
          return NULL;
        }
      v1=(uint64_t) (GET_CHAR (c) - 'A');
      v_r = v_r*10ULL + v1;
      INC_CHAR (c);
    }
  if (GET_CHAR (c) !='@')
    {
      c->err = 1;
      return NULL;
    }
  INC_CHAR (c);
  return gen_dim (c->gc, eMST_dim,v_r, non_tt_param, fSigned, fNegate);
}

static uMToken *
extract_name (sMSCtx *c, char term)
{
  uMToken *ret;
  char *txt;
  size_t len;
  const char *sv = c->pos;
  while (GET_CHAR (c) != 0 && GET_CHAR (c) != term)
    {
      INC_CHAR (c);
    }
  if (GET_CHAR (c) != '@')
    {
      c->err = 1;
      return NULL;
    }
  len = (size_t) (c->pos - sv);
  txt = (char *) malloc (len + 1);
  memcpy (txt, sv, len);
  txt[len] = 0;
  INC_CHAR (c);
  ret = m_name (c, txt);
  free (txt);
  return ret;
}

static uMToken *
get_scope (sMSCtx *c)
{
  uMToken *n = NULL;

  while (1)
  {
    if (GET_CHAR (c) == 0 || GET_CHAR (c) == '@')
      break;
    if (c->fExplicitTemplateParams != 0 && !c->fGetTemplateArgumentList)
      return n;
    if (GET_CHAR (c) == '?')
      {
        INC_CHAR (c);
        if (GET_CHAR (c) == '$')
          {
            DEC_CHAR (c);
	    n = m_coloncolon (c, get_zbuf_name (c, 1), n);
          }
        else if (GET_CHAR (c) == '%' || GET_CHAR (c) == 'A')
          {
            while (GET_CHAR (c) != '@')
              INC_CHAR (c);
            INC_CHAR (c);
            n = m_coloncolon (c, m_name (c, "anonymous_namespace"), n);
          }
        else if (GET_CHAR (c) == '?')
          {
            if (c->pos[1] == '_' && c->pos[2] == '?')
              {
                INC_CHAR (c);
		n = m_coloncolon (c, get_operator_name (c, 0,NULL), n);
                if (GET_CHAR (c) == '@')
                  INC_CHAR (c);
              }
            else
	      {
		n = m_coloncolon (c, gen_unary (c->gc, eMST_slashed, get_decorated_name (c)), n);
	      }
          }
        else if (GET_CHAR (c) == 'I')
          {
            INC_CHAR (c);
	    n = m_coloncolon (c, m_array (c, get_zbuf_name (c, 1)), n);
          }
        else
	  n = m_coloncolon (c, get_lexical_frame (c), n);
      }
    else
      n = m_coloncolon (c, get_zbuf_name (c, 1), n);
  }
  if (n)
    n = m_scope (c, n);
  if (GET_CHAR (c))
    {
      if (GET_CHAR (c) == '@')
        return n;
    }
  else
    {
      c->err = 2;
      return n;
    }
    return n;
}

static uMToken *
get_template_name (sMSCtx *c, int fReadTerminator)
{
  sCached rep1;
  sCached rep2;
  sCached rep3;
  sCached *svZName,*svArgList,*svTempArgList;
  uMToken *n = NULL;
  int fFlag = 0;
  
  if (GET_CHAR (c) !='?' || c->pos[1] != '$')
    return NULL;
  memset (&rep1, 0, sizeof (rep1));
  memset (&rep2, 0, sizeof (rep2));
  memset (&rep3, 0, sizeof (rep3));
  
  svTempArgList = c->pTemplateArgList;
  svArgList = c->pArgList;
  svZName = c->pZNameList;
  
  SKIP_CHAR(c,2);
  
  c->pArgList=&rep1;
  c->pZNameList=&rep2;
  c->pTemplateArgList=&rep3;

  if (GET_CHAR (c) == '?')
    {
      INC_CHAR (c);
      n = get_operator_name (c, 1, &fFlag);
    }
  else
    n = get_zbuf_name (c, 1);
  if (!n)
    c->fExplicitTemplateParams = 1;
  if (!fFlag)
    {
      n = get_template_argument_list (c);
      n = m_ltgt (c, n);
      if (fReadTerminator)
        INC_CHAR (c);
    }
  c->pArgList = svArgList;
  c->pZNameList = svZName;
  c->pTemplateArgList = svTempArgList;
  return n;
}

static uMToken *
get_operator_name (sMSCtx *c, int fIsTemplate, int *pfReadTemplateArguments)
{
  const char *svName;
  char ch = GET_CHAR (c);
  uMToken *n = NULL,*h = NULL;
  
  if (!ch)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  switch(ch)
    {
      case '0': case '1':
        if (fIsTemplate)
          {
            h = m_ltgt (c, get_template_argument_list (c));
            if (pfReadTemplateArguments)
              *pfReadTemplateArguments = 1;
            ch = GET_CHAR (c);
            if (ch == 0)
              return m_oper (c, h);
            INC_CHAR (c);
          }
        svName = c->pos;
        n = get_zbuf_name (c, 0);
        c->pos = svName;
        if (n && ch == '1')
          n=gen_unary (c->gc, eMST_destructor, n);
        n = chain_tok (n, h);
        return m_oper (c, n);
      case '2':
        return m_oper (c, m_opname (c, "operator new"));
      case '3':
        return m_oper (c, m_opname (c, "operator delete"));
      case '4':
        return m_oper (c, m_opname (c, "operator ="));
      case '5':
        return m_oper (c, m_opname (c, "operator >>"));
      case '6':
        return m_oper (c, m_opname (c, "operator <<"));
      case '7':
        return m_oper (c, m_opname (c, "operator !"));
      case '8':
        return m_oper (c, m_opname (c, "operator =="));
      case '9':
        return m_oper (c, m_opname (c, "operator !="));
      case 'A':
        return m_oper (c, m_opname (c, "operator []"));
      case 'B':
        n = m_opname (c,  "operator");
        MTOKEN_FLAGS(n) |= MTOKEN_FLAGS_UDC;
        n = m_oper (c, n);
        MTOKEN_FLAGS(n) |= MTOKEN_FLAGS_UDC;
        return n;
      case 'C':
        return m_oper (c, m_opname (c, "operator ->"));
      case 'D':
        return m_oper (c, m_opname (c, "operator *"));
      case 'E':
        return m_oper (c, m_opname (c, "operator ++"));
      case 'F':
        return m_oper (c, m_opname (c, "operator --"));
      case 'G':
        return m_oper (c, m_opname (c, "operator -"));
      case 'H':
        return m_oper (c, m_opname (c, "operator +"));
      case 'I':
        return m_oper (c, m_opname (c, "operator &"));
      case 'J':
        return m_oper (c, m_opname (c, "operator ->*"));
      case 'K':
        return m_oper (c, m_opname (c, "operator /"));
      case 'L':
        return m_oper (c, m_opname (c, "operator %"));
      case 'M':
        return m_oper (c, m_opname (c, "operator <"));
      case 'N':
        return m_oper (c, m_opname (c, "operator <="));
      case 'O':
        return m_oper (c, m_opname (c, "operator >"));
      case 'P':
        return m_oper (c, m_opname (c, "operator >="));
      case 'Q':
        return m_oper (c, m_opname (c, "operator ,"));
      case 'R':
        return m_oper (c, m_opname (c, "operator ()"));
      case 'S':
        return m_oper (c, m_opname (c, "operator ~"));
      case 'T':
        return m_oper (c, m_opname (c, "operator ^"));
      case 'U':
        return m_oper (c, m_opname (c, "operator |"));
      case 'V':
        return m_oper (c, m_opname (c, "operator &&"));
      case 'W':
        return m_oper (c, m_opname (c, "operator ||"));
      case 'X':
        return m_oper (c, m_opname (c, "operator *="));
      case 'Y':
        return m_oper (c, m_opname (c, "operator +="));
      case 'Z':
        return m_oper (c, m_opname (c, "operator -="));
      case '_':
        break;
      default:
        fprintf (stderr, " *** get_operator_name unknown '%c'\n", ch);
        return NULL;
    }
  ch = GET_CHAR (c);
  if (! ch)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  switch(ch)
    {
      case '_':
        ch = GET_CHAR (c);
        INC_CHAR (c);
        switch (ch)
          {
            case 'A':
              return m_oper (c, m_opname (c, "__man_vec_ctor"));
            case 'B':
              return m_oper (c, m_opname (c, "__man_vec_dtor"));
            case 'C':
              return m_oper (c, m_opname (c, "__ehvec_copy_ctor"));
            case 'D':
              return m_oper (c, m_opname (c, "__ehvec_copy_ctor_vb"));
          }
        fprintf (stderr, " *** get_operator_name unknown '__%c'\n", ch);
        return NULL;

      case '0':
        return m_oper (c, m_opname (c, "operator /="));
      case '1':
        return m_oper (c, m_opname (c, "operator %="));
      case '2':
        return m_oper (c, m_opname (c, "operator >>="));
      case '3':
        return m_oper (c, m_opname (c, "operator <<="));
      case '4':
        return m_oper (c, m_opname (c, "operator &="));
      case '5':
        return m_oper (c, m_opname (c, "operator |="));
      case '6':
        return m_oper (c, m_opname (c, "operator ^="));
      case '7':
        return m_oper (c, gen_name (c->gc, eMST_vftable, "$vftable"));
      case '8':
        return m_oper (c, gen_name (c->gc, eMST_vbtable, "$vbtable"));
      case '9':
        return m_oper (c, gen_name (c->gc, eMST_vcall, "vcall"));
      case 'A':
        return m_oper (c, m_opname (c,"typeof"));
      case 'B':
        return m_oper (c, m_opname (c,"local_static_guard"));
      case 'C':
        n = get_string_encoding (c, 1);
        MTOKEN_FLAGS(n) |= MTOKEN_FLAGS_NOTE;
        return n;
      case 'D':
        return m_oper (c, m_opname (c,"vbase_destructor"));
      case 'E':
        return m_oper (c, m_opname (c,"__vecDelDtor"));
      case 'F':
        return m_oper (c, m_opname (c,"__dflt_ctor_closure"));
      case 'G':
        return m_oper (c, m_opname (c, "__delDtor"));
      case 'H':
        return m_oper (c, m_opname (c, "__vec_ctor"));
      case 'I':
        return m_oper (c, m_opname (c, "__vec_dtor"));
      case 'J':
        return m_oper (c, m_opname (c, "__vec_ctor_vb"));
      case 'K':
        return m_oper (c, m_opname (c, "$vdispmap"));
      case 'L':
        return m_oper (c, m_opname (c, "__ehvec_ctor"));
      case 'M':
        return m_oper (c, m_opname (c, "__ehvec_dtor"));
      case 'N':
        return m_oper (c, m_name (c, "__ehvec_ctor_vb"));
      case 'O':
        return m_oper (c, m_opname (c, "__copy_ctor_closure"));
      case 'P':
        return gen_unary (c->gc, eMST_udt_returning, get_operator_name (c, 0, NULL));
      case 'Q':
        return m_oper (c, m_opname (c,  "operator 'EH'"));
      case 'R':
        ch = GET_CHAR (c);
        INC_CHAR (c);
        switch (ch)
          {
            case '0':
              h = m_rtti (c, "$type_descriptor");
              return m_oper (c, m_combine (c, get_data_type (c) , h));
            case '1':
              h = m_rtti (c, "base_class_descriptor");
              n = m_element (c, get_dimension_signed (c));
              n = chain_tok (n, m_element (c, get_dimension_signed (c)));
              n = chain_tok (n, m_element (c, get_dimension_signed (c)));
              n = chain_tok (n, m_element (c, get_dimension (c, 0, 0)));
	      n = m_frame (c, n);
              return m_oper (c, gen_binary (c->gc, eMST_assign, h, n));
            case '2':
              return m_oper (c, m_rtti (c, "base_class_array"));
            case '3':
	      return m_oper (c, m_rtti (c, "class_hierarchy_descriptor"));
            case '4':
              return m_oper (c, m_rtti (c, "complete_object_locator"));
          }
        DEC_CHAR (c);
        fprintf (stderr, " *** Unkown RTTI %c\n", ch);
        c->err = 2;
        return NULL;
      case 'S':
        return m_oper (c, m_opname (c, "$locvftable"));
      case 'T':
        return m_oper (c, m_opname (c, "__local_vftable_ctor_closure"));
      case 'U':
        n = m_opname (c, "operator new[]");
        return m_oper (c, n);
      case 'V':
        n = m_opname (c,  "operator delete[]");
        return m_oper (c, n);
      case 'W': /* omni callsig ??? */
      default:
        fprintf (stderr, " *** get_operator_name unknown '_%c'\n", ch);
        return NULL;
      case 'X':
        return m_oper (c, m_opname (c,  "__placement_delete_closure"));
      case 'Y':
        return m_oper (c, m_opname (c,  "__placement_arrayDelete_closure"));
      case '?':
        break;
    }
  ch = GET_CHAR (c);
  if (!ch)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  switch(ch)
    {
      case '0':
	m_combine (c, m_name (c, "using namespace"), get_string_encoding (c, 0));
        MTOKEN_FLAGS (n) |= MTOKEN_FLAGS_NOTE;
        return n;
    }
  fprintf (stderr, " *** get_operator_name unknown '__?%c'\n", ch);
  return NULL;
}

static uMToken *
get_template_argument_list (sMSCtx *c)
{
  uMToken *n = NULL;
  uMToken *h = NULL;
  int idx;
  int beFirst=1;
  c->fGetTemplateArgumentList = 1;
  do
    {
      if (GET_CHAR (c) == 0 || GET_CHAR (c) == '@')
        break;
      idx = (int) (GET_CHAR (c) - '0');
      if (GET_CHAR (c) >= '0' && GET_CHAR (c) <= '9')
        {
          h = c->pTemplateArgList->arr[idx];
          INC_CHAR (c);
        }
      else
        {
          const char *svPos = c->pos;
          if (GET_CHAR (c) =='X')
            {
              INC_CHAR (c);
              h = m_type (c, "void");
            }
          else if (GET_CHAR (c) == '$' && c->pos[1] != '$')
            {
              INC_CHAR (c);
              h = get_template_constant (c);
            }
          else if (GET_CHAR (c) == '?')
            {
              uMToken *sdim = get_dimension_signed (c);
              h = gen_binary (c->gc, eMST_templateparam, m_name (c, "template-parameter"), sdim);
            }
          else
            h = get_primary_data_type (c, NULL);
          if ((int)(c->pos-svPos)>1 &&
              c->pTemplateArgList->count < 10)
            {
              c->pTemplateArgList->arr[c->pTemplateArgList->count] = h;
              c->pTemplateArgList->count += 1;
            }
        }
      h = m_element (c, h);
      if (beFirst)
        {
          n = h;
          beFirst = 0;
        }
      else
        {
          n = chain_tok (n, h);
        }
    }
  while (c->err == 0);
  c->fGetTemplateArgumentList = 0;
  if (n)
    n = gen_unary (c->gc, eMST_template_argument_list, n);
  return n;
}

static uMToken *
get_lexical_frame (sMSCtx *c)
{
  return m_lexical_frame (c, get_dimension (c, 0, 0));
}

static uMToken *
get_string_encoding (sMSCtx *c, int wantBody)
{
  uMToken *length = NULL;
  uMToken *crc = NULL, *h = NULL;
  uMToken *typ = NULL;
  const char *svName;
  size_t len;
  char *hp;

  if (GET_CHAR (c) != '@') return NULL;
  INC_CHAR (c);
  typ = get_string_literal_type (c);
  length = get_dimension (c, 0, 0);
  crc = get_dimension (c, 0, 0);
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return NULL;
    }
  svName = c->pos;
  while (GET_CHAR (c) != 0)
    {
      if (GET_CHAR (c) == '@')
        break;
      INC_CHAR (c);
  }
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return NULL;
    }
  len = (size_t) (c->pos - svName);
  hp = (char *) malloc (len + 1);
  memcpy (hp, svName, len);
  hp[len] = 0;
  INC_CHAR (c);
  h = m_name (c, hp);
  free (hp);
  if (wantBody)
    h = m_combine (c, typ, m_combine (c, h, m_array (c, length)));
  return h;
}

static uMToken *
get_template_constant (sMSCtx *c)
{
  char ch;
  uMToken *n = NULL;
  uMToken *exp;

  ch = GET_CHAR(c);
  if (!ch)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  if (ch =='E')
    return get_decorated_name (c);
  if (ch > 'E' && ch <= 'J')
    {
      if (ch >= 'H' && ch <= 'J')
        {
          exp = m_element (c, get_decorated_name (c));
          if (!n) n = exp;
          else chain_tok (n, exp);
        }
      switch(ch)
        {
          case 'G': case 'J':
            exp = m_element (c, get_dimension_signed (c));
	    if (!n) n = exp;
	    else chain_tok (n, exp);
          case 'F': case 'I':
            exp = m_element (c, get_dimension_signed (c));
	    if (!n) n = exp;
	    else chain_tok (n, exp);
          case 'H':
            exp = m_element (c, get_dimension_signed (c));
	    if (!n) n = exp;
	    else chain_tok (n, exp);
            break;
        }
      return m_frame (c, n);
    }
  if (ch == 'Q' || ch == 'D')
    {
      n = get_dimension_signed (c);
      if (ch == 'D')
        return gen_binary (c->gc, eMST_templateparam, m_name (c, "template-parameter"), n);
      return gen_binary (c->gc, eMST_nonetypetemplateparam, m_name (c, "none-type-template-parameter"), n);
    }
  if (ch == '0')
    return get_dimension_signed (c);
  if (ch == '1')
    {
      if (GET_CHAR (c) != '@')
        return m_combine (c, m_cv (c, "&"), get_decorated_name (c));
      INC_CHAR (c);
      return m_name (c, "NULL");
    }
  if (ch != '2')
    {
      fprintf (stderr, " *** get_template_constant unknown '%c'\n", ch);
      return NULL;
    }
  n = get_dimension_signed (c);
  exp = get_dimension_signed (c);
  return gen_binary (c->gc, eMST_exp, n, exp);
}

static uMToken *
get_data_type (sMSCtx *c)
{
  uMToken *n = NULL;
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return n;
    }
  if (GET_CHAR (c) == '?')
    {
      INC_CHAR (c);
      n = get_indirect_data_type (c, n, (char)0, NULL, 0);
      return get_primary_data_type (c, n);
    }
  if (GET_CHAR (c) != 'X')
    return get_primary_data_type (c, n);
  INC_CHAR (c);
  return m_combine (c, m_type (c, "void"), n);
}

static uMToken *
get_indirect_data_type (sMSCtx *c, uMToken *superType, char prType, uMToken *cvType, int thisFlag)
{
  uMToken *n = NULL, *n1 = NULL, *n2 = NULL;
  int state;

  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      if (thisFlag != 0)
        return NULL;
      if (!superType)
        {
          if (!cvType)
            return NULL;
          return cvType;
        }
      if (MTOKEN_FLAGS (superType) & MTOKEN_FLAGS_PTRREF)
        return superType;
      if (!cvType)
        return superType;
      return m_combine (c, cvType, superType);
    }
  if (GET_CHAR (c) == '$')
    {
      INC_CHAR (c);
      if (GET_CHAR (c) == 'A')
        {
          n = m_cv (c, "__gc");
          INC_CHAR (c);
        }
      else if (GET_CHAR (c) == 'B')
        {
          n = m_cv (c, "__pin");
          INC_CHAR (c);
        }
      else
        {
          state = (int)(GET_CHAR (c) - '3')*16;
          INC_CHAR (c);
          state += (int)GET_CHAR (c);
          INC_CHAR (c);
          n = gen_value (c->gc, eMST_gcarray, (uint64_t) state, 0, 4);
          if (superType)
            {
              if (!(MTOKEN_FLAGS (superType) & MTOKEN_FLAGS_ARRAY))
                superType = m_rframe (c, superType);
              n=m_combine (c, superType, n);
            }
          INC_CHAR (c);
          return n;
        }
    }
  state = (GET_CHAR (c) - (GET_CHAR (c) < 'A' ? 0x16 : 0x41));
  while (1)
    {
      if (state == 4)
        n1 = m_combine (c, n1, m_cv (c, "__ptr64"));
      else if (state == 5)
	n2 = m_combine (c, n2, m_cv (c, "__unaligned"));
      else if (state != 8)
        {
	  uMToken *ret = NULL;
          INC_CHAR (c);
          if (state > 31)
	    return NULL;
	  if (prType == '*')
	    ret = m_cv (c, "*");
	  else if (prType == '&')
	    ret = m_cv (c, "&");

	  ret = m_combine (c, n ,ret);
	  ret = m_combine (c, ret, n1);
	  ret = m_combine (c, n2, ret);
          if ((state & 0x10) != 0)
            {
              if (thisFlag != 0)
		return NULL;
              if (prType)
                {
                  if (GET_CHAR (c) == 0)
		    {
		      c->err = 2;
		      return ret;
		    }
                  else
		    {
		      if (ret)
			ret = gen_binary (c->gc, eMST_coloncolon , get_scope (c), ret);
		      else
			ret = get_scope (c);
		    }
                  if (GET_CHAR (c) == 0) c->err = 2;
                  else
                    {
		      char ch = GET_CHAR (c);
                      INC_CHAR (c);
                      if (ch != '@')
			return NULL;
                    }
                }
              else if (GET_CHAR (c) == 0)
		c->err = 2;
              else
                {
                  ret = get_scope (c);
                  if (GET_CHAR (c) != 0)
                    {
		      char ch = GET_CHAR (c);
                      INC_CHAR (c);
                      if (ch != '@')
			return NULL;
                    }
                  else
		    c->err = 2;
                }
            }
          if ((state&0xc)==0xc)
            {
              if (thisFlag != 0)
		return NULL;
              ret = m_combine (c, get_based_type (c), ret);
            }
          if ((state & 2) != 0)
	    ret = m_combine (c, m_cv (c, "volatile"), ret);
          if ((state & 1) != 0)
	    ret = m_combine (c, m_cv (c, "const"), ret);
          if (thisFlag != 0)
            {
	      if (!ret)
		ret = m_name (c, "");
	      MTOKEN_FLAGS(ret) |= MTOKEN_FLAGS_PTRREF;
              return ret;
            }
          if (!superType)
            {
              if (cvType)
		ret = m_combine (c, ret, cvType);
	      if (!ret)
		ret = m_name (c, "");
              MTOKEN_FLAGS(ret) |= MTOKEN_FLAGS_PTRREF;
              return ret;
            }
          if (MTOKEN_FLAGS(superType) & MTOKEN_FLAGS_PTRREF)
            {
              if (cvType)
                {
		  ret = m_combine (c, ret, cvType);
		  ret = m_combine (c, ret, superType);
                  MTOKEN_FLAGS(ret) |= MTOKEN_FLAGS_PTRREF;
                  return ret;
                }
            }
          if (!(MTOKEN_FLAGS(superType)&MTOKEN_FLAGS_ARRAY))
	    ret = m_combine (c, ret, superType);
          else
	    ret = superType;
          MTOKEN_FLAGS(ret) |= MTOKEN_FLAGS_PTRREF;
          return ret;
        }
      else
        {
          if (!n1)
            n1 = m_cv (c, "__restrict");
          else
            n1 = m_combine (c, n1, m_cv (c, "__restrict"));
        }
      INC_CHAR (c);
      state=GET_CHAR (c)-(GET_CHAR (c) < 'A' ? 0x16 : 0x41);
    }
}

static uMToken *
get_primary_data_type (sMSCtx *c, uMToken *superType)
{
  uMToken *superName = NULL;
  uMToken *cvType = NULL;
  switch(GET_CHAR (c))
    {
      case 0:
	c->err = 2;
	return superType;
      case 'B':
	cvType = m_cv (c, "volatile");
	/* fall through */
      case 'A':
	superName = superType;
	if (!superName)
	  superName = m_name (c, "");
	MTOKEN_FLAGS (superName) |= MTOKEN_FLAGS_PTRREF;
	INC_CHAR (c);
	return get_pointer_reference_type (c, cvType, superName, '&');
      case '$':
	if (c->pos[1] == '$')
	  {
	    SKIP_CHAR (c, 2);
	    break;
	  }
	if (c->pos[1] == 0)
	  {
	    c->err = 2;
	    return NULL;
	  }
	fprintf (stderr, " *** get_primary_data_type '$%c' unknown\n", c->pos[1]);
	return NULL;
      default:
	return get_basic_data_type (c, superType);
    }
  switch(GET_CHAR (c))
    {
      case 0:
	c->err = 2;
	return superType;
      case 'A':
	INC_CHAR (c);
	return get_indirect_function_type (c, superType);
      case 'B':
	INC_CHAR (c);
	return get_pointer_reference_data_type (c, superType, 1);
      case 'C':
	INC_CHAR (c);
	return get_basic_data_type (c, get_indirect_data_type (c, superType, (char)0, superName, 0));
    }
  fprintf (stderr, " *** get_primary_data_type '$$%c' unknown\n", GET_CHAR (c));
  return NULL;
}

static uMToken *
get_based_type (sMSCtx *c)
{
  uMToken *n = m_cv (c, "__based");
  uMToken *p = NULL;
  char ch;

  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return gen_binary (c->gc, eMST_based, n, NULL);
    }
  ch = GET_CHAR (c);
  INC_CHAR (c);
  switch(ch)
    {
      case '0':
	p = m_type (c, "void");
	break;
      case '2':
	p = get_scoped_name (c);
	break;
      case '5':
	fprintf (stderr, " *** get_based_type unknown '%c'\n", ch);
	return NULL;
      default:
	fprintf (stderr, " *** get_based_type unknown '%c' (ignored)\n", ch);
	break;
    }
  return gen_binary (c->gc, eMST_based, n, p);
}

static uMToken *
get_scoped_name (sMSCtx *c)
{
  uMToken *n = NULL;
  n = get_zbuf_name (c, 1);
  if (n && GET_CHAR (c) != 0)
    {
      if (GET_CHAR (c) =='@')
        {
	  INC_CHAR (c);
	  return n;
        }
      n = m_coloncolon (c, get_scope (c), n);
    }
  if (GET_CHAR (c) == '@')
    {
      INC_CHAR (c);
      return n;
    }
  if (GET_CHAR (c) != 0)
      return n;
  c->err = 2;
  return n;
}

static uMToken *
get_basic_data_type (sMSCtx *c, uMToken *superName)
{
  uMToken *bTyp = NULL;
  uMToken *cvName = NULL;
  uMToken *arType = NULL;
  uMToken *tmp = NULL;
  char svChar,svChar1;
  int flags;

  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return superName;
    }
  svChar1 = GET_CHAR (c);
  INC_CHAR (c);
  flags=~0;
  switch (svChar1)
    {
     case 'M':
       bTyp = m_type (c, "float");
       break;
     case 'C':
       bTyp = m_type (c, "signed char");
       break;
     case 'D':
       bTyp = m_type (c, "char");
       break;
     case 'E':
       bTyp = m_type (c, "unsigned char");
       break;
     case 'F':
       bTyp = m_type (c, "short");
       break;
     case 'G':
       bTyp = m_type (c, "unsigned short");
       break;
     case 'H':
       bTyp = m_type (c, "int");
       break;
     case 'I':
       bTyp = m_type (c, "unsigned int");
       break;
     case 'J':
       bTyp = m_type (c, "long");
       break;
     case 'K':
       bTyp = m_type (c, "unsigned long");
       break;
     case 'N':
       bTyp = m_type (c, "double");
       break;
     case 'O':
       bTyp = m_type (c, "long double");
       break;
     case 'P':
       return get_pointer_reference_type (c, bTyp, superName, '*');
     case 'Q':
       if (!superName)
	 bTyp = m_cv (c, "const");
       return get_pointer_reference_type (c, bTyp, superName, '*');
     case 'R':
       if (!superName)
	 bTyp = m_cv (c, "volatile");
       return get_pointer_reference_type (c, bTyp, superName, '*');
     case 'S':
       if (!superName)
         {
	   bTyp = m_cv (c, "const");
	   bTyp = m_combine (c, bTyp, m_cv (c, "volatile"));
         }
       return get_pointer_reference_type (c, bTyp, superName, '*');
     case '_':
       svChar = GET_CHAR (c);
       INC_CHAR (c);
       switch(svChar)
         {
           case 'N':
	     bTyp = m_type (c, "bool");
	     break;
	   case 'O':
	     if (!superName)
	       superName = m_name (c, "");
	     cvName=superName;
	     MTOKEN_FLAGS (cvName) |= MTOKEN_FLAGS_ARRAY;
	     arType = get_pointer_reference_type (c, bTyp, cvName, 0);
	     if (!(MTOKEN_FLAGS (arType)&MTOKEN_FLAGS_ARRAY))
	       arType = m_combine (c, arType, m_array (c, NULL));
	     return arType;
	   case 'W':
	     bTyp = m_type (c, "wchar_t");
	     break;
	   case 'X':
	   case 'Y':
	     DEC_CHAR (c);
	     if (!(bTyp = get_ECSU_data_type (c)))
	       return NULL;
	     break;
	   case 'D':
	     bTyp = m_type (c, "__int8");
	     break;
	   case 'E':
	     bTyp = m_type (c, "unsigned __int8");
	     break;
	   case 'F':
	     bTyp = m_type (c, "__int16");
	     break;
	   case 'G':
	     bTyp = m_type (c, "unsigned __int16");
	     break;
	   case 'H':
	     bTyp = m_type (c, "__int32");
	     break;
	   case 'I':
	     bTyp = m_type (c, "unsigned __int32");
	     break;
	   case 'J':
	     bTyp = m_type (c, "__int64");
	     break;
	   case 'K':
	     bTyp = m_type (c, "unsigned __int64");
	     break;
	   case 'L':
	     bTyp = m_type (c, "__int128");
	     break;
	   case 'M':
	     bTyp = m_type (c, "unsigned");
	     break;
	   case '$':
	     bTyp = get_basic_data_type (c, superName);
	     return m_combine (c, m_cv (c, "__w64"), bTyp);
	   default:
	     fprintf (stderr, " *** get_basic_data_type unknown '_%c' (ignored).\n", svChar);
	     bTyp = m_type (c, "UNKNOWN");
	     break;
         }
       break;
     default:
       DEC_CHAR (c);
       bTyp = get_ECSU_data_type (c);
       if (!bTyp)
	 return bTyp;
       break;
    }
  if (superName)
    bTyp = m_combine (c, bTyp, superName);
  return bTyp;
}

static uMToken *
get_pointer_reference_type (sMSCtx *c, uMToken *cvType, uMToken *superType, char ptrChar)
{
  uMToken *n = NULL;
  if (ptrChar == '&')
    n = m_cv (c, "&");
  else if (ptrChar == '*')
    n = m_cv (c, "*");
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      if (cvType)
        {
	  if (!n)
	    n = cvType;
	  else
	    n = m_combine (c, n, cvType);
        }
      if (superType)
	n = m_combine (c, n, superType);
      return n;
    }
  if (GET_CHAR (c) < '6' || GET_CHAR (c) > '9')
    {
      if (GET_CHAR (c) != '_')
	return get_pointer_reference_data_type (c,
	  get_indirect_data_type (c, superType, ptrChar, cvType, 0),(ptrChar=='*' ? 1 : 0));
    }
  if (cvType)
    {
      if (!superType || !(MTOKEN_FLAGS (superType)&MTOKEN_FLAGS_PTRREF))
        {
	  if (!n)
	    n = cvType;
	  else
	    n = m_combine (c, n, cvType);
        }
    }
  if (superType)
    {
      if (!n)
	n = superType;
      else
	n = m_combine (c, n, superType);
    }
  return get_indirect_function_type (c, n);
}

static uMToken *
get_indirect_function_type (sMSCtx *c, uMToken *superType)
{
  uMToken *retType = NULL;
  uMToken *n1 = NULL, *n2 = NULL;
  int flag;
  int cidx;
  char ch = GET_CHAR (c);
  if (ch == 0)
    {
      c->err = 2;
      return superType;
    }
  if (ch != '_' && (ch < '6' || ch > '9'))
    return NULL;
  cidx = (int) (ch - '6');
  INC_CHAR (c);
  if (ch == '_')
    {
      ch = GET_CHAR (c);
      if (ch == 0)
        {
	  c->err = 2;
	  return superType;
        }
      if (ch < 'A' || ch > 'D')
	return NULL;
      cidx=(int)(ch - 'A') + 4;
      INC_CHAR (c);
    }
  n2 = superType;
  flag = cidx & 2;
  if (flag)
    {
      ch = GET_CHAR (c);
      if (ch == 0)
        {
	  c->err = 2;
	  return n2;
        }
      n2 = m_coloncolon (c, get_scope (c), n2);
      if (GET_CHAR (c) == 0)
        {
	  c->err = 2;
	  return n2;
        }
      if (GET_CHAR (c) != '@')
	return NULL;
      INC_CHAR (c);
      n1 = get_this_type (c);
    }
  if (cidx & 4)
    n2 = m_combine (c, get_based_type (c), n2);
  n2 = m_combine (c, get_calling_convention (c), n2);
  if (superType)
    n2 = m_rframe (c, n2);
  retType = get_return_type (c);
  n2 = m_combine (c, n2, m_rframe (c, get_argument_types (c)));
  if (flag)
    n2 = m_combine (c, n2, n1);
  n2 = m_combine (c, n2, get_throw_types (c));
  return m_combine (c, retType, n2);
}

static uMToken *
get_pointer_reference_data_type (sMSCtx *c, uMToken *superType,int isPtr)
{
  uMToken *n = NULL;
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return superType;
    }
  
  if (isPtr && GET_CHAR (c) == 'X')
    {
      INC_CHAR (c);
      n = m_type (c, "void");
      if (superType)
	n = m_combine (c, n, superType);
      return n;
    }
  if (GET_CHAR (c) == 'Y')
    {
      INC_CHAR (c);
      return get_array_type (c, superType);
    }
  if (GET_CHAR (c) != '_')
    return get_basic_data_type (c, superType);
  if (c->pos[1] != 'Z')
    return get_basic_data_type (c, superType);
  SKIP_CHAR (c, 2);
  n = m_cv (c, "__box");
  return m_combine (c, n, get_basic_data_type (c, superType));
}

static uMToken *
get_ECSU_data_type (sMSCtx *c)
{
  char ch = GET_CHAR (c);
  uMToken *n = NULL;

  if (!ch)
    {
      c->err = 2;
      return m_type (c, "no-ecsu");
    }
  INC_CHAR (c);
  switch (ch)
    {
      default:
	fprintf (stderr, " *** get_ECSU_data_type unknown %c\n", ch);
	n = m_type (c, "unknown ecsu");
	break;
      case 'T':
	n = m_type (c, "union");
	break;
      case 'U':
	n = m_type (c, "struct");
	break;
      case 'V':
	n = m_type (c, "class");
	break;
      case 'W':
	n = m_type (c, "enum");
	get_enum_size_type (c);
	break;
      case 'X':
	n = m_type (c, "coclass");
	break;
      case 'Y':
	n = m_type (c, "cointerface");
	break;
    }
  return gen_binary (c->gc, eMST_ecsu, n, get_scoped_name (c));
}

static uMToken *
get_string_literal_type (sMSCtx *c)
{
  uMToken *n = NULL;
  char ch = GET_CHAR (c);
  if (ch == 0)
    {
      c->err = 2;
      return NULL;
    }
  if (ch == '_')
    {
      INC_CHAR (c);
      n = m_cv (c, "const"); 
    }
  ch = GET_CHAR (c);
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  switch (ch)
    {
      case '0':
	return m_combine (c, n, m_type (c, "char"));
      case '1':
	return m_combine (c, n, m_type (c, "wchar_t"));
    }
  fprintf (stderr, " *** get_string_literal_type unknown '_%c'\n", ch);
  return NULL;
}

static uMToken *
get_enum_size_type (sMSCtx *c)
{
  uMToken *n = NULL;
  switch (GET_CHAR (c))
    {
      case 0:
	c->err = 2;
	return NULL;
      case '0':
	n = m_type (c, "char");
	break;
      case '1':
	n = m_type (c, "unsigned char");
	break;
      case '2':
	n = m_type (c, "short");
	break;
      case '3':
	n = m_type (c, "unsigned short");
	break;
      case '4':
	n = m_type (c, "int");
	break;
      case '5':
	n = m_type (c, "unsigned int");
	break;
      case '6':
	n = m_type (c, "long");
	break;
      case '7':
	n = m_type (c, "unsigned long");
	break;
      default:
	fprintf (stderr, " *** get_enum_size_type unknown ,%c'\n", GET_CHAR (c));
	return NULL;
    }
  INC_CHAR (c);
  return n;
}

static uMToken *
get_this_type (sMSCtx *c)
{
    return get_indirect_data_type (c, NULL, (char)0, NULL, 1);
}

static uMToken *
get_calling_convention (sMSCtx *c)
{
  char ch = GET_CHAR (c);

  if (ch == 0)
    {
      c->err = 2;
      return NULL;
    }
  INC_CHAR (c);
  switch(ch)
    {
      case 'A': case 'B':
	return m_cv (c, "__cdecl");
      case 'C': case 'D':
	return m_cv (c, "__pascal");
      case 'E': case 'F':
	return m_cv (c, "__thiscall");
      case 'G': case 'H':
	return m_cv (c, "__stdcall");
      case 'I': case 'J':
	return m_cv (c, "__fastcall");
      case 'K': case 'L':
	return m_cv (c, "");
      case 'M':
	return m_cv (c, "__clrcall");
    }
  fprintf (stderr, " *** get_calling_convention ,%c' unknown.\n", ch);
  return NULL;
}

static uMToken *
get_throw_types (sMSCtx *c)
{
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return m_throw (c, m_rframe (c, NULL));
    }
  if (GET_CHAR (c) == 'Z')
    {
      INC_CHAR (c);
      return m_name (c, "");
    }
  return m_throw (c, m_rframe (c, get_argument_types (c)));
}

static uMToken *
get_argument_types (sMSCtx *c)
{
  char ch = GET_CHAR (c);
  uMToken *n = NULL;

  if (ch == 'X')
    {
      INC_CHAR (c);
      return m_element (c, m_type (c, "void"));
    }
  if (ch == 'Z')
    {
      INC_CHAR (c);
      return m_element (c, m_type (c, "..."));
    }
  n = get_argument_list (c);
  if (!n || c->err)
    return n;
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return n;
    }
  if (GET_CHAR (c) == '@')
    {
      INC_CHAR (c);
      return n;
    }
  if (GET_CHAR (c) == 'Z')
    {
      INC_CHAR (c);
      return chain_tok (n, m_element (c, m_type (c, "...")));
    }
  fprintf (stderr, " *** get_argument_types unknown ,%c'\n", GET_CHAR (c));
  return NULL;
}

static uMToken *
get_return_type (sMSCtx *c)
{
  if (GET_CHAR (c) == '@')
    {
      INC_CHAR (c);
      return m_name (c, "");
    }
  return get_data_type (c);
}

static int
get_number_of_dimensions (sMSCtx *c)
{
  int ret = 0;
  if (GET_CHAR (c))
    return 0;
  if (GET_CHAR (c) >= '0' && GET_CHAR (c) <= '9')
    {
      ret = (int) (GET_CHAR (c) - '0') + 1;
      INC_CHAR (c);
      return ret;
    }
  while (GET_CHAR (c) != '@')
    {
      if (GET_CHAR (c) == 0)
	return 0;
      if (GET_CHAR (c) < 'A' || GET_CHAR (c) > 'P')
	return -1;
      ret <<= 4;
      ret += (int) (GET_CHAR (c) - 'A');
      INC_CHAR (c);
    }
  if (GET_CHAR (c) == '@')
    {
      INC_CHAR (c);
      return ret;
    }
  return -1;
}

static uMToken *
get_array_type (sMSCtx *c, uMToken *superType)
{
  uMToken *n = NULL, *h = NULL;
  int dims;

  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      if (superType)
	return m_combine (c, m_rframe (c, superType), m_array (c, NULL));
      return m_array (c, NULL);
    }
  dims = get_number_of_dimensions (c);
  if ( dims < 0)
    dims=0;
  if (!dims)
    {
      c->err = 2;
      return get_basic_data_type (c, m_array (c, NULL));
    }
  if (superType && (MTOKEN_FLAGS(superType)&MTOKEN_FLAGS_ARRAY))
    h = m_array (c, NULL);
  do {
    n = m_array (c, get_dimension (c, 0, 0));
    if (!h)
      h = n;
    else
      h = m_combine (c, h, n);
  } while (--dims != 0);
  if (superType)
    {
      if (!(MTOKEN_FLAGS(superType)&MTOKEN_FLAGS_ARRAY))
	superType = m_rframe (c, superType);
      h = m_combine (c, superType, h);
    }
  n = get_primary_data_type (c, h);
  MTOKEN_FLAGS (n) |= MTOKEN_FLAGS_ARRAY;
  return n;
}

static uMToken *
get_argument_list (sMSCtx *c)
{
  uMToken *n = NULL, *h = NULL;
  int idx;
  
  if (c->err)
    return NULL;
  do {
    h = NULL;
    if (GET_CHAR (c) == '@' || GET_CHAR (c) == 'Z')
      return n;
    if (GET_CHAR (c) == 0)
      {
	c->err = 2;
	return n;
      }
    idx= (int) (GET_CHAR (c) - '0');
    if (idx < 0 || idx > 9)
      {
	const char *svName = c->pos;
	h = get_primary_data_type (c, NULL);
	if ((size_t) (c->pos - svName)>1 && c->pArgList->count < 10)
	  {
	    c->pArgList->arr[c->pArgList->count]=h;
	    c->pArgList->count += 1;
	  }
      }
    else
      {
	INC_CHAR (c);
	h = c->pArgList->arr[idx];
      }
    h = m_element (c, h);
    n = chain_tok (n, h);
  } while (c->err != 2);
  return n;
}

static uMToken *
get_vdisp_map_type (sMSCtx *c, uMToken *superType)
{
  uMToken *n = superType;
  uMToken *h = get_scope (c);
  h = m_combine (c, m_name (c, "for"), h);
  h = m_frame (c, h);
  n = m_combine (c, n, h);
  if (GET_CHAR (c) =='@')
    INC_CHAR (c);
  return n;
}

static uMToken *
get_ext_data_type (sMSCtx *c, uMToken *superType)
{
  uMToken *dt = NULL,*n = NULL;
  dt = get_data_type (c);
  n = get_indirect_data_type (c, NULL, (char)0, NULL, 0);
  if (superType)
    n = m_combine (c, n, superType);

  return m_combine (c, dt, n);
}

static uMToken *getVCallThunkType(sMSCtx *c)
{
  if (GET_CHAR (c) == 0)
    {
      c->err = 2;
      return NULL;
    }
  if (GET_CHAR (c) != 'A')
    {
      fprintf (stderr, " *** getVCallThunkType unknown '%c'\n", GET_CHAR (c));
      return NULL;
    }
  INC_CHAR (c);
  return m_cv (c, "{flat}");
}

static uMToken *
get_vftable_type (sMSCtx *c, uMToken *superType)
{
  uMToken *n = superType;
  if (c->err || GET_CHAR (c) == 0)
    {
      c->err = 2;
      return n;
    }
  n = m_combine (c, get_indirect_data_type (c, NULL, (char)0, NULL, 0), n);
  if (c->err == 2 || !n)
    return n;
  if (GET_CHAR (c) != '@')
    {
      n = m_combine (c, n, m_name (c, "{for "));
      while (c->err == 0)
        {
	  if (GET_CHAR (c) ==0 || GET_CHAR (c) =='@')
	    break;
	  n = m_combine (c, n, m_lexical_frame (c, get_scope (c)));
	  if (GET_CHAR (c) == '@')
	    INC_CHAR (c);
	  if (c->err == 0 && GET_CHAR (c) != '@')
	    n = m_combine (c, n, m_name (c, "s "));
        }
      if (c->err == 0)
        {
	  if (GET_CHAR (c) == 0)
	    c->err = 2;
	  n = m_combine (c, n, m_name (c, "}"));
        }
      if (GET_CHAR (c) != '@')
	return n;
    }
  INC_CHAR (c);
  return n;
}

static uMToken *
compose_decl (sMSCtx *c, uMToken *symbol)
{
  uMToken *n = NULL;
  int et = get_encoded_type (c);
  int nIsUDC = (symbol && (MTOKEN_FLAGS (symbol) & MTOKEN_FLAGS_UDC)) ? 1 : 0;
  if (et==0xffff)
    return NULL;
  if (et==0xfffe)
    {
      c->err = 2;
      return symbol;
    }
  if (et==0xfffd)
    return symbol;
  if ((et&0x8000)==0)
    {
      n = symbol;
      if ((et&0x7c00)==0x6800)
	return get_vftable_type (c, n);
      if ((et&0x7c00)==0x7000)
	return get_vftable_type (c, n);
      if ((et&0x7c00)==0x6000)
        {
	  uMToken *ll = m_element (c, get_dimension (c, 0, 0));
	  ll = m_frame (c, ll);
	  return m_combine (c, n, ll);
        }
      if ((et&0x7c00)==0x7c00)
	return get_vdisp_map_type (c, n);
      if ((et&0x7c00)==0x7800)
	return n;
      n = get_ext_data_type (c, n);
      if ((et&0x6000)!=0)
        {
	  if ((et&0x1000))
	    n = m_combine (c, m_colon (c, "[thunk]"), n);
	  return n;
        }
      n = m_combine (c, m_cv (c, "static"), n);
      if ((et&0x700) == 0x400 || (et&0x700) == 0x500)
	n = m_combine (c, m_cv (c, "virtual"), n);
      switch ((et&0x1800))
        {
          case 0x800:
	    n = m_combine (c, m_colon (c, "private"), n);
	    break;
	  case 0x1000:
	    n = m_combine (c, m_colon (c, "protected"), n);
	    break;
	  case 0x0:
	    n = m_combine (c, m_colon (c, "public"), n);
	    break;
        }
      if ((et&0x400))
	n = m_combine (c, m_colon (c, "[thunk]"), n);
      return n;
    }
  if ((et&0x1f00)==0x1000 || (et&0x1f00)==0x1400)
    {
      n = symbol;
      if ((et&0x6000)!=0 || (et&0x7f00)==0x1400)
	n = m_combine (c, n, m_name (c, "local_static_destructor_helper"));
      n = get_ext_data_type (c, n);
      symbol = NULL;
   }
  else if ((et&0x1f00)==0x1500 || (et&0x1f00)==0x1600)
    {
      n = symbol;
      symbol = NULL;
      if ((et&0x1f00)==0x1500) 
        n = m_combine (c, n, m_name (c, "template_static_data_member_constructor_helper"));
      else if ((et&0x1f00)==0x1600)
	n = m_combine (c, n, m_name (c, "template_static_data_member_destructor_helper"));
    }
  else
    {
      if ((et&0x4000)!=0)
	n = get_based_type (c);
      if ((et&0x1800)==0x1800)
        {
	  uMToken *hh = NULL;
	  hh = m_element (c, get_dimension (c, 0, 0));
	  hh = chain_tok (hh, m_element (c, getVCallThunkType (c)));
	  n = m_combine (c, symbol,
	    m_frame (c, hh));
	  n = m_combine (c, get_calling_convention (c), n);
        }
      else
        {
	  uMToken *h = NULL;
	  uMToken *n1 = NULL;
	  uMToken *n2 = NULL;
	  uMToken *n3 = NULL;
	  if ((et&0x1000)!=0 || (et&0x1c00)==0xc00)
	    {
	      if ((et&0x1f00)==0xd00)
		n1 = get_dimension (c, 1, 0);
	      n2 = get_dimension (c, 1, 0);
	    }
	  if (((et&0x1800)==0x800) && (et&0x700)!=0x200)
	    n3 = get_this_type (c);
	  n = m_combine (c, get_calling_convention (c), n);
	  if (symbol)
	    n = m_combine (c, n, symbol);

	  if (nIsUDC)
	    n = m_combine (c, n, get_return_type (c));
	  h = get_return_type (c);
	  if (((et&0x1800)!=0x800 ? (et&0x1000)!=0 : (et&0x400)!=0))
	    {
	      if (((et&0x1800)==0x800) && (et&0x700)==0x500)
	        {
		  n2 = chain_tok (
		    m_element (c, n1),
		    m_element (c, n2));
		  n2 = m_frame (c, n2);
		  n = m_combine (c, n, m_combine (c, m_name (c, "vtordisp"), n2));
	        }
	      else
	        {
		  n2 = m_frame (c, m_element (c, n2));
		  n = m_combine (c, n, m_combine (c, m_name (c, "adjustor"), n2));
	        }
	    }
	  n = m_combine (c, n, m_rframe (c, get_argument_types (c)));
	  if (((et&0x1800)==0x800) && (et&0x700)!=0x200)
	    n = m_combine (c, n, n3);
	  n = m_combine (c, n, get_throw_types (c));
	  if (h)
	    n = m_combine (c, h, n);
        }
    }
  if ((et&0x1800)!=0x800) {
    if ((et&0x1000))
      n = m_combine (c, m_colon (c, "[thunk]"), n);
    return n;
  }
  switch ((et&0x700))
    {
      case 0x200:
	n = m_combine (c, m_cv (c, "static"), n);
	break;
      case 0x100:
      case 0x400:
      case 0x500:
	n = m_combine (c, m_cv (c, "virtual"), n);
	break;
    }
  switch ((et&0xc0))
    {
      case 0x40:
	n = m_combine (c, m_colon (c, "private"), n);
	break;
      case 0x80:
	n = m_combine (c, m_colon (c, "protected"), n);
	break;
      case 0x0:
	n = m_combine (c, m_colon (c, "public"), n);
	break;
    }
  if ((et&0x400))
    n = m_combine (c, m_colon (c, "[thunk]"), n);
  return n;
}

static int
get_encoded_type (sMSCtx *c)
{
  int ret;

  for(;;)
    {
      ret = 0;
      if (GET_CHAR (c) == '_')
        {
	  INC_CHAR (c);
	  ret = 0x4000;
        }
      if (GET_CHAR (c) >= 'A' && GET_CHAR (c) <= 'Z')
        {
	  int chc = (int) (GET_CHAR (c) - 'A');
	  INC_CHAR (c);
	  if ((chc & 1) == 0)
	    ret |= 0x8000;
	  else
	    ret |= 0xa000;
	  if (chc >= 0x18)
	    return ret;
	  ret |= 0x800;
	  switch((chc&0x18))
	    {
	      case 0:
		ret |= 0x40;
		break;
	      case 8:
		ret |= 0x80;
		break;
	      case 0x10:
		break;
	    }
	  switch((chc&6))
	    {
	      case 0:
		return ret;
	      case 2:
		return ret|0x200;
	      case 4:
		return ret|0x100;
	      case 6:
		return ret|0x400;
	    }
	  return 0xffff;
        }
      if (GET_CHAR (c) != '$')
        {
	  INC_CHAR (c);
	  switch(c->pos[-1])
	    {
	      case '0':
		return 0x800;
	      case '1':
		return 0x1000;
	      case '2':
		return 0;
	      case '3':
		return 0x4000;
	      case '4':
		return 0x2000;
	      case '5':
		return 0x6000;
	      case '6':
		return 0x6800;
	      case '7':
		return 0x7000;
	      case '8':
		return 0x7800;
	      case '9':
		return 0xfffd;
	      case 0:
		DEC_CHAR (c);
		return 0xfffe;
	    }
	  DEC_CHAR (c);
	  return 0xffff;
        }
      INC_CHAR (c);
      switch(GET_CHAR (c))
        {
          case 'A':
	    INC_CHAR (c);
	    return ret|0x9000;
	  case 'B':
	    INC_CHAR (c);
	    return ret|0x9800;
	  case 'C':
	    INC_CHAR (c);
	    return ret|0x7c00;
	  case 'D':
	    INC_CHAR (c);
	    return ret|0x9100;
	  case 'E':
	    INC_CHAR (c);
	    return ret|0x9200;
	  case 0:
	    INC_CHAR (c);
	    return 0xfffe;
	  case '0':
	    INC_CHAR (c);
	    return ret|0x8d40;
	  case '1':
	    INC_CHAR (c);
	    return ret|0xad40;
	  case '2':
	    INC_CHAR (c);
	    return ret|0x8d80;
	  case '3':
	    INC_CHAR (c);
	    return ret|0xad80;
	  case '4':
	    INC_CHAR (c);
	    return ret|0x8d00;
	  case '5':
	    INC_CHAR (c);
	    return ret|0xad00;
	  case '$':
	    if (c->pos[1] == 'P')
	      INC_CHAR (c);
	    break;
	  default:
	    return 0xffff;
        }
      INC_CHAR (c);
      switch(GET_CHAR (c))
        {
          case 'F': case 'G': case 'H': case 'I': case 'L': case 'M':
	    INC_CHAR (c);
	    break;
	  case 'J': case 'K': case 'N': case 'O':
	    INC_CHAR (c);
	    if (GET_CHAR (c) < '0' || GET_CHAR (c) > '9')
	      {
		INC_CHAR (c);
		return 0xffff;
	      }
	    {
	      int skip = (GET_CHAR (c) - '0') + 1;
	      SKIP_CHAR (c, skip);
	    }
	    break;
	  default:
	    INC_CHAR (c);
	    return ret;
        }
    }
}

static uMToken *
m_combine (sMSCtx *c, uMToken *l, uMToken *r)
{
  if (!l && !r)
    return NULL;
  if (!l)
    return r;
  if (!r)
    return l;
  return gen_binary (c->gc, eMST_combine, l, r);
}

static uMToken *
m_type (sMSCtx *c, const char *typname)
{
  return gen_name (c->gc, eMST_type, typname);
}

static uMToken *
m_cv (sMSCtx *c, const char *cv)
{
  return gen_name (c->gc, eMST_cv, cv);
}

static uMToken *
m_coloncolon (sMSCtx *c, uMToken *l, uMToken *r)
{
  if (!l)
    return r;
  if (!r)
    return l;
  return gen_binary (c->gc, eMST_coloncolon, l, r);
}

static uMToken *
m_element (sMSCtx *c, uMToken *el)
{
  return gen_unary (c->gc, eMST_element, el);
}

static uMToken *
m_array (sMSCtx *c, uMToken *dim)
{
  return gen_unary (c->gc, eMST_array, dim);
}

static uMToken *
m_scope (sMSCtx *c, uMToken *n)
{
  return gen_unary (c->gc, eMST_scope, n);
}

static uMToken *
m_oper (sMSCtx *c, uMToken *n)
{
  return gen_unary (c->gc, eMST_oper, n);
}

static uMToken *
m_name (sMSCtx *c, const char *str)
{
  return gen_name (c->gc, eMST_name, str);
}

static uMToken *
m_colon (sMSCtx *c, const char *str)
{
  return gen_name (c->gc, eMST_colon, str);
}

static uMToken *
m_opname (sMSCtx *c, const char *str)
{
  return gen_name (c->gc, eMST_opname, str);
}

static uMToken *
m_rtti (sMSCtx *c, const char *str)
{
  return gen_name (c->gc, eMST_rtti, str);
}

static uMToken *
m_frame (sMSCtx *c, uMToken *u)
{
  return gen_unary (c->gc, eMST_frame, u);
}

static uMToken *
m_rframe (sMSCtx *c, uMToken *u)
{
  return gen_unary (c->gc, eMST_rframe, u);
}

static uMToken *
m_ltgt (sMSCtx *c, uMToken *u)
{
  return gen_unary (c->gc, eMST_ltgt, u);
}

static uMToken *
m_throw (sMSCtx *c, uMToken *u)
{
  return gen_unary (c->gc, eMST_throw, u);
}

static uMToken *
m_lexical_frame (sMSCtx *c, uMToken *u)
{
  return gen_unary (c->gc, eMST_lexical_frame, u);
}
