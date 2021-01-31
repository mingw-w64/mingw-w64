/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs
#define yylval          parser_lval
#define yychar          parser_char

/* First part of user prologue.  */
#line 1 "tools/widl/parser.y"

/*
 * IDL Compiler
 *
 * Copyright 2002 Ove Kaaven
 * Copyright 2006-2008 Robert Shearman
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "widl.h"
#include "utils.h"
#include "parser.h"
#include "header.h"
#include "typelib.h"
#include "typegen.h"
#include "expr.h"
#include "typetree.h"

typedef struct list typelist_t;
struct typenode {
  type_t *type;
  struct list entry;
};

struct _import_t
{
  char *name;
  int import_performed;
};

static str_list_t *append_str(str_list_t *list, char *str);
static attr_list_t *append_attr(attr_list_t *list, attr_t *attr);
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_attrp(enum attr_type type, void *val);
static attr_t *make_custom_attr(UUID *id, expr_t *pval);
static expr_list_t *append_expr(expr_list_t *list, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface);
static ifref_t *make_ifref(type_t *iface);
static var_list_t *append_var_list(var_list_t *list, var_list_t *vars);
static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *p);
static declarator_t *make_declarator(var_t *var);
static type_t *make_safearray(type_t *type);
static typelib_t *make_library(const char *name, const attr_list_t *attrs);
static void append_array(declarator_t *decl, expr_t *expr);
static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual);
static void append_chain_callconv(type_t *chain, char *callconv);
static warning_list_t *append_warning(warning_list_t *, int);

static type_t *reg_typedefs(decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs);
static type_t *find_type_or_error(const char *name, int t);
static type_t *find_type_or_error2(char *name, int t);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);
static void init_lookup_namespace(const char *name);
static void push_lookup_namespace(const char *name);

static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_member_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs);
const char *get_attr_display_name(enum attr_type type);
static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func);
static void check_def(const type_t *t);

static void check_async_uuid(type_t *iface);

static statement_t *make_statement(enum statement_type type);
static statement_t *make_statement_type_decl(type_t *type);
static statement_t *make_statement_reference(type_t *type);
static statement_t *make_statement_declaration(var_t *var);
static statement_t *make_statement_library(typelib_t *typelib);
static statement_t *make_statement_pragma(const char *str);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names, int declonly);
static statement_t *make_statement_import(const char *str);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *lookup_namespace = &global_namespace;

static typelib_t *current_typelib;


#line 214 "tools/widl/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    aIDENTIFIER = 258,             /* aIDENTIFIER  */
    aPRAGMA = 259,                 /* aPRAGMA  */
    aKNOWNTYPE = 260,              /* aKNOWNTYPE  */
    aNAMESPACE = 261,              /* aNAMESPACE  */
    aNUM = 262,                    /* aNUM  */
    aHEXNUM = 263,                 /* aHEXNUM  */
    aDOUBLE = 264,                 /* aDOUBLE  */
    aSTRING = 265,                 /* aSTRING  */
    aWSTRING = 266,                /* aWSTRING  */
    aSQSTRING = 267,               /* aSQSTRING  */
    aUUID = 268,                   /* aUUID  */
    aEOF = 269,                    /* aEOF  */
    aACF = 270,                    /* aACF  */
    SHL = 271,                     /* SHL  */
    SHR = 272,                     /* SHR  */
    MEMBERPTR = 273,               /* MEMBERPTR  */
    EQUALITY = 274,                /* EQUALITY  */
    INEQUALITY = 275,              /* INEQUALITY  */
    GREATEREQUAL = 276,            /* GREATEREQUAL  */
    LESSEQUAL = 277,               /* LESSEQUAL  */
    LOGICALOR = 278,               /* LOGICALOR  */
    LOGICALAND = 279,              /* LOGICALAND  */
    ELLIPSIS = 280,                /* ELLIPSIS  */
    tAGGREGATABLE = 281,           /* tAGGREGATABLE  */
    tAGILE = 282,                  /* tAGILE  */
    tALLNODES = 283,               /* tALLNODES  */
    tALLOCATE = 284,               /* tALLOCATE  */
    tANNOTATION = 285,             /* tANNOTATION  */
    tAPICONTRACT = 286,            /* tAPICONTRACT  */
    tAPPOBJECT = 287,              /* tAPPOBJECT  */
    tASYNC = 288,                  /* tASYNC  */
    tASYNCUUID = 289,              /* tASYNCUUID  */
    tAUTOHANDLE = 290,             /* tAUTOHANDLE  */
    tBINDABLE = 291,               /* tBINDABLE  */
    tBOOLEAN = 292,                /* tBOOLEAN  */
    tBROADCAST = 293,              /* tBROADCAST  */
    tBYTE = 294,                   /* tBYTE  */
    tBYTECOUNT = 295,              /* tBYTECOUNT  */
    tCALLAS = 296,                 /* tCALLAS  */
    tCALLBACK = 297,               /* tCALLBACK  */
    tCASE = 298,                   /* tCASE  */
    tCDECL = 299,                  /* tCDECL  */
    tCHAR = 300,                   /* tCHAR  */
    tCOCLASS = 301,                /* tCOCLASS  */
    tCODE = 302,                   /* tCODE  */
    tCOMMSTATUS = 303,             /* tCOMMSTATUS  */
    tCONST = 304,                  /* tCONST  */
    tCONTEXTHANDLE = 305,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 306, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 307, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 308,               /* tCONTRACT  */
    tCONTRACTVERSION = 309,        /* tCONTRACTVERSION  */
    tCONTROL = 310,                /* tCONTROL  */
    tCPPQUOTE = 311,               /* tCPPQUOTE  */
    tCUSTOM = 312,                 /* tCUSTOM  */
    tDECODE = 313,                 /* tDECODE  */
    tDEFAULT = 314,                /* tDEFAULT  */
    tDEFAULTBIND = 315,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 316,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 317,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 318,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 319, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 320,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 321,          /* tDISPINTERFACE  */
    tDLLNAME = 322,                /* tDLLNAME  */
    tDONTFREE = 323,               /* tDONTFREE  */
    tDOUBLE = 324,                 /* tDOUBLE  */
    tDUAL = 325,                   /* tDUAL  */
    tENABLEALLOCATE = 326,         /* tENABLEALLOCATE  */
    tENCODE = 327,                 /* tENCODE  */
    tENDPOINT = 328,               /* tENDPOINT  */
    tENTRY = 329,                  /* tENTRY  */
    tENUM = 330,                   /* tENUM  */
    tERRORSTATUST = 331,           /* tERRORSTATUST  */
    tEXCLUSIVETO = 332,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 333,         /* tEXPLICITHANDLE  */
    tEXTERN = 334,                 /* tEXTERN  */
    tFALSE = 335,                  /* tFALSE  */
    tFASTCALL = 336,               /* tFASTCALL  */
    tFAULTSTATUS = 337,            /* tFAULTSTATUS  */
    tFLOAT = 338,                  /* tFLOAT  */
    tFORCEALLOCATE = 339,          /* tFORCEALLOCATE  */
    tHANDLE = 340,                 /* tHANDLE  */
    tHANDLET = 341,                /* tHANDLET  */
    tHELPCONTEXT = 342,            /* tHELPCONTEXT  */
    tHELPFILE = 343,               /* tHELPFILE  */
    tHELPSTRING = 344,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 345,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 346,          /* tHELPSTRINGDLL  */
    tHIDDEN = 347,                 /* tHIDDEN  */
    tHYPER = 348,                  /* tHYPER  */
    tID = 349,                     /* tID  */
    tIDEMPOTENT = 350,             /* tIDEMPOTENT  */
    tIGNORE = 351,                 /* tIGNORE  */
    tIIDIS = 352,                  /* tIIDIS  */
    tIMMEDIATEBIND = 353,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 354,         /* tIMPLICITHANDLE  */
    tIMPORT = 355,                 /* tIMPORT  */
    tIMPORTLIB = 356,              /* tIMPORTLIB  */
    tIN = 357,                     /* tIN  */
    tIN_LINE = 358,                /* tIN_LINE  */
    tINLINE = 359,                 /* tINLINE  */
    tINPUTSYNC = 360,              /* tINPUTSYNC  */
    tINT = 361,                    /* tINT  */
    tINT32 = 362,                  /* tINT32  */
    tINT3264 = 363,                /* tINT3264  */
    tINT64 = 364,                  /* tINT64  */
    tINTERFACE = 365,              /* tINTERFACE  */
    tLCID = 366,                   /* tLCID  */
    tLENGTHIS = 367,               /* tLENGTHIS  */
    tLIBRARY = 368,                /* tLIBRARY  */
    tLICENSED = 369,               /* tLICENSED  */
    tLOCAL = 370,                  /* tLOCAL  */
    tLONG = 371,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 372,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 373,                  /* tMAYBE  */
    tMESSAGE = 374,                /* tMESSAGE  */
    tMETHODS = 375,                /* tMETHODS  */
    tMODULE = 376,                 /* tMODULE  */
    tMTA = 377,                    /* tMTA  */
    tNAMESPACE = 378,              /* tNAMESPACE  */
    tNOCODE = 379,                 /* tNOCODE  */
    tNONBROWSABLE = 380,           /* tNONBROWSABLE  */
    tNONCREATABLE = 381,           /* tNONCREATABLE  */
    tNONE = 382,                   /* tNONE  */
    tNONEXTENSIBLE = 383,          /* tNONEXTENSIBLE  */
    tNOTIFY = 384,                 /* tNOTIFY  */
    tNOTIFYFLAG = 385,             /* tNOTIFYFLAG  */
    tNULL = 386,                   /* tNULL  */
    tOBJECT = 387,                 /* tOBJECT  */
    tODL = 388,                    /* tODL  */
    tOLEAUTOMATION = 389,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 390,               /* tOPTIMIZE  */
    tOPTIONAL = 391,               /* tOPTIONAL  */
    tOUT = 392,                    /* tOUT  */
    tPARTIALIGNORE = 393,          /* tPARTIALIGNORE  */
    tPASCAL = 394,                 /* tPASCAL  */
    tPOINTERDEFAULT = 395,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 396,         /* tPRAGMA_WARNING  */
    tPROGID = 397,                 /* tPROGID  */
    tPROPERTIES = 398,             /* tPROPERTIES  */
    tPROPGET = 399,                /* tPROPGET  */
    tPROPPUT = 400,                /* tPROPPUT  */
    tPROPPUTREF = 401,             /* tPROPPUTREF  */
    tPROXY = 402,                  /* tPROXY  */
    tPTR = 403,                    /* tPTR  */
    tPUBLIC = 404,                 /* tPUBLIC  */
    tRANGE = 405,                  /* tRANGE  */
    tREADONLY = 406,               /* tREADONLY  */
    tREF = 407,                    /* tREF  */
    tREGISTER = 408,               /* tREGISTER  */
    tREPRESENTAS = 409,            /* tREPRESENTAS  */
    tREQUESTEDIT = 410,            /* tREQUESTEDIT  */
    tRESTRICTED = 411,             /* tRESTRICTED  */
    tRETVAL = 412,                 /* tRETVAL  */
    tRUNTIMECLASS = 413,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 414,              /* tSAFEARRAY  */
    tSHORT = 415,                  /* tSHORT  */
    tSIGNED = 416,                 /* tSIGNED  */
    tSINGLENODE = 417,             /* tSINGLENODE  */
    tSIZEIS = 418,                 /* tSIZEIS  */
    tSIZEOF = 419,                 /* tSIZEOF  */
    tSMALL = 420,                  /* tSMALL  */
    tSOURCE = 421,                 /* tSOURCE  */
    tSTANDARD = 422,               /* tSTANDARD  */
    tSTATIC = 423,                 /* tSTATIC  */
    tSTDCALL = 424,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 425,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 426,                 /* tSTRING  */
    tSTRUCT = 427,                 /* tSTRUCT  */
    tSWITCH = 428,                 /* tSWITCH  */
    tSWITCHIS = 429,               /* tSWITCHIS  */
    tSWITCHTYPE = 430,             /* tSWITCHTYPE  */
    tTHREADING = 431,              /* tTHREADING  */
    tTRANSMITAS = 432,             /* tTRANSMITAS  */
    tTRUE = 433,                   /* tTRUE  */
    tTYPEDEF = 434,                /* tTYPEDEF  */
    tUIDEFAULT = 435,              /* tUIDEFAULT  */
    tUNION = 436,                  /* tUNION  */
    tUNIQUE = 437,                 /* tUNIQUE  */
    tUNSIGNED = 438,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 439,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 440,            /* tUSERMARSHAL  */
    tUUID = 441,                   /* tUUID  */
    tV1ENUM = 442,                 /* tV1ENUM  */
    tVARARG = 443,                 /* tVARARG  */
    tVERSION = 444,                /* tVERSION  */
    tVIPROGID = 445,               /* tVIPROGID  */
    tVOID = 446,                   /* tVOID  */
    tWCHAR = 447,                  /* tWCHAR  */
    tWIREMARSHAL = 448,            /* tWIREMARSHAL  */
    tAPARTMENT = 449,              /* tAPARTMENT  */
    tNEUTRAL = 450,                /* tNEUTRAL  */
    tSINGLE = 451,                 /* tSINGLE  */
    tFREE = 452,                   /* tFREE  */
    tBOTH = 453,                   /* tBOTH  */
    CAST = 454,                    /* CAST  */
    PPTR = 455,                    /* PPTR  */
    POS = 456,                     /* POS  */
    NEG = 457,                     /* NEG  */
    ADDRESSOF = 458                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 136 "tools/widl/parser.y"

	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	type_t *type;
	var_t *var;
	var_list_t *var_list;
	declarator_t *declarator;
	declarator_list_t *declarator_list;
	statement_t *statement;
	statement_list_t *stmt_list;
	warning_t *warning;
	warning_list_t *warning_list;
	ifref_t *ifref;
	ifref_list_t *ifref_list;
	char *str;
	UUID *uuid;
	unsigned int num;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;

#line 493 "tools/widl/parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_aIDENTIFIER = 3,                /* aIDENTIFIER  */
  YYSYMBOL_aPRAGMA = 4,                    /* aPRAGMA  */
  YYSYMBOL_aKNOWNTYPE = 5,                 /* aKNOWNTYPE  */
  YYSYMBOL_aNAMESPACE = 6,                 /* aNAMESPACE  */
  YYSYMBOL_aNUM = 7,                       /* aNUM  */
  YYSYMBOL_aHEXNUM = 8,                    /* aHEXNUM  */
  YYSYMBOL_aDOUBLE = 9,                    /* aDOUBLE  */
  YYSYMBOL_aSTRING = 10,                   /* aSTRING  */
  YYSYMBOL_aWSTRING = 11,                  /* aWSTRING  */
  YYSYMBOL_aSQSTRING = 12,                 /* aSQSTRING  */
  YYSYMBOL_aUUID = 13,                     /* aUUID  */
  YYSYMBOL_aEOF = 14,                      /* aEOF  */
  YYSYMBOL_aACF = 15,                      /* aACF  */
  YYSYMBOL_SHL = 16,                       /* SHL  */
  YYSYMBOL_SHR = 17,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 18,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 19,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 20,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 21,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 22,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 23,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 24,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 25,                  /* ELLIPSIS  */
  YYSYMBOL_tAGGREGATABLE = 26,             /* tAGGREGATABLE  */
  YYSYMBOL_tAGILE = 27,                    /* tAGILE  */
  YYSYMBOL_tALLNODES = 28,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 29,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 30,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 31,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 32,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 33,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 34,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 35,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 36,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 37,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 38,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 39,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 40,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 41,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 42,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 43,                     /* tCASE  */
  YYSYMBOL_tCDECL = 44,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 45,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 46,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 47,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 48,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 49,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 50,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 51, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 52,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 53,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 54,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 55,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 56,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 57,                   /* tCUSTOM  */
  YYSYMBOL_tDECODE = 58,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 59,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 60,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 61,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 62,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 63,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 64,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 65,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 66,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 67,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 68,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 69,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 70,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 71,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 72,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 73,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 74,                    /* tENTRY  */
  YYSYMBOL_tENUM = 75,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 76,             /* tERRORSTATUST  */
  YYSYMBOL_tEXCLUSIVETO = 77,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 78,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 79,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 80,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 81,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 82,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLOAT = 83,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 84,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 85,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 86,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 87,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 88,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 89,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 90,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 91,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 92,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 93,                    /* tHYPER  */
  YYSYMBOL_tID = 94,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 95,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 96,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 97,                    /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 98,            /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 99,           /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 100,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 101,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 102,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 103,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 104,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 105,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 106,                     /* tINT  */
  YYSYMBOL_tINT32 = 107,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 108,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 109,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 110,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 111,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 112,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 113,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 114,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 115,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 116,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 117,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 118,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 119,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 120,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 121,                  /* tMODULE  */
  YYSYMBOL_tMTA = 122,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 123,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 124,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 125,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 126,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 127,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 128,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 129,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 130,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 131,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 132,                  /* tOBJECT  */
  YYSYMBOL_tODL = 133,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 134,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 135,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 136,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 137,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 138,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 139,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 140,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 141,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 142,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 143,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 144,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 145,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 146,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 147,                   /* tPROXY  */
  YYSYMBOL_tPTR = 148,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 149,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 150,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 151,                /* tREADONLY  */
  YYSYMBOL_tREF = 152,                     /* tREF  */
  YYSYMBOL_tREGISTER = 153,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 154,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 155,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 156,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 157,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 158,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 159,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 160,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 161,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 162,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 163,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 164,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 165,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 166,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 167,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 168,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 169,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 170,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 171,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 172,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 173,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 174,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 175,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 176,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 177,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 178,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 179,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 180,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 181,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 182,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 183,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 184,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 185,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 186,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 187,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 188,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 189,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 190,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 191,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 192,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 193,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 194,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 195,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 196,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 197,                    /* tFREE  */
  YYSYMBOL_tBOTH = 198,                    /* tBOTH  */
  YYSYMBOL_199_ = 199,                     /* ','  */
  YYSYMBOL_200_ = 200,                     /* '?'  */
  YYSYMBOL_201_ = 201,                     /* ':'  */
  YYSYMBOL_202_ = 202,                     /* '|'  */
  YYSYMBOL_203_ = 203,                     /* '^'  */
  YYSYMBOL_204_ = 204,                     /* '&'  */
  YYSYMBOL_205_ = 205,                     /* '<'  */
  YYSYMBOL_206_ = 206,                     /* '>'  */
  YYSYMBOL_207_ = 207,                     /* '-'  */
  YYSYMBOL_208_ = 208,                     /* '+'  */
  YYSYMBOL_209_ = 209,                     /* '*'  */
  YYSYMBOL_210_ = 210,                     /* '/'  */
  YYSYMBOL_211_ = 211,                     /* '%'  */
  YYSYMBOL_212_ = 212,                     /* '!'  */
  YYSYMBOL_213_ = 213,                     /* '~'  */
  YYSYMBOL_CAST = 214,                     /* CAST  */
  YYSYMBOL_PPTR = 215,                     /* PPTR  */
  YYSYMBOL_POS = 216,                      /* POS  */
  YYSYMBOL_NEG = 217,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 218,                /* ADDRESSOF  */
  YYSYMBOL_219_ = 219,                     /* '.'  */
  YYSYMBOL_220_ = 220,                     /* '['  */
  YYSYMBOL_221_ = 221,                     /* ']'  */
  YYSYMBOL_222_ = 222,                     /* '{'  */
  YYSYMBOL_223_ = 223,                     /* '}'  */
  YYSYMBOL_224_ = 224,                     /* ';'  */
  YYSYMBOL_225_ = 225,                     /* '('  */
  YYSYMBOL_226_ = 226,                     /* ')'  */
  YYSYMBOL_227_ = 227,                     /* '='  */
  YYSYMBOL_YYACCEPT = 228,                 /* $accept  */
  YYSYMBOL_input = 229,                    /* input  */
  YYSYMBOL_m_acf = 230,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 231,           /* gbl_statements  */
  YYSYMBOL_232_1 = 232,                    /* $@1  */
  YYSYMBOL_imp_statements = 233,           /* imp_statements  */
  YYSYMBOL_234_2 = 234,                    /* $@2  */
  YYSYMBOL_int_statements = 235,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 236,            /* semicolon_opt  */
  YYSYMBOL_statement = 237,                /* statement  */
  YYSYMBOL_pragma_warning = 238,           /* pragma_warning  */
  YYSYMBOL_warnings = 239,                 /* warnings  */
  YYSYMBOL_typedecl = 240,                 /* typedecl  */
  YYSYMBOL_cppquote = 241,                 /* cppquote  */
  YYSYMBOL_import_start = 242,             /* import_start  */
  YYSYMBOL_import = 243,                   /* import  */
  YYSYMBOL_importlib = 244,                /* importlib  */
  YYSYMBOL_libraryhdr = 245,               /* libraryhdr  */
  YYSYMBOL_library_start = 246,            /* library_start  */
  YYSYMBOL_librarydef = 247,               /* librarydef  */
  YYSYMBOL_m_args = 248,                   /* m_args  */
  YYSYMBOL_arg_list = 249,                 /* arg_list  */
  YYSYMBOL_args = 250,                     /* args  */
  YYSYMBOL_arg = 251,                      /* arg  */
  YYSYMBOL_array = 252,                    /* array  */
  YYSYMBOL_m_attributes = 253,             /* m_attributes  */
  YYSYMBOL_attributes = 254,               /* attributes  */
  YYSYMBOL_attrib_list = 255,              /* attrib_list  */
  YYSYMBOL_str_list = 256,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 257,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 258,             /* contract_ver  */
  YYSYMBOL_contract_req = 259,             /* contract_req  */
  YYSYMBOL_attribute = 260,                /* attribute  */
  YYSYMBOL_uuid_string = 261,              /* uuid_string  */
  YYSYMBOL_callconv = 262,                 /* callconv  */
  YYSYMBOL_cases = 263,                    /* cases  */
  YYSYMBOL_case = 264,                     /* case  */
  YYSYMBOL_enums = 265,                    /* enums  */
  YYSYMBOL_enum_list = 266,                /* enum_list  */
  YYSYMBOL_enum_member = 267,              /* enum_member  */
  YYSYMBOL_enum = 268,                     /* enum  */
  YYSYMBOL_enumdef = 269,                  /* enumdef  */
  YYSYMBOL_m_exprs = 270,                  /* m_exprs  */
  YYSYMBOL_m_expr = 271,                   /* m_expr  */
  YYSYMBOL_expr = 272,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 273,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 274,           /* expr_int_const  */
  YYSYMBOL_expr_const = 275,               /* expr_const  */
  YYSYMBOL_fields = 276,                   /* fields  */
  YYSYMBOL_field = 277,                    /* field  */
  YYSYMBOL_ne_union_field = 278,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 279,          /* ne_union_fields  */
  YYSYMBOL_union_field = 280,              /* union_field  */
  YYSYMBOL_s_field = 281,                  /* s_field  */
  YYSYMBOL_funcdef = 282,                  /* funcdef  */
  YYSYMBOL_declaration = 283,              /* declaration  */
  YYSYMBOL_m_ident = 284,                  /* m_ident  */
  YYSYMBOL_t_ident = 285,                  /* t_ident  */
  YYSYMBOL_ident = 286,                    /* ident  */
  YYSYMBOL_base_type = 287,                /* base_type  */
  YYSYMBOL_m_int = 288,                    /* m_int  */
  YYSYMBOL_int_std = 289,                  /* int_std  */
  YYSYMBOL_qualified_seq = 290,            /* qualified_seq  */
  YYSYMBOL_291_3 = 291,                    /* $@3  */
  YYSYMBOL_qualified_type = 292,           /* qualified_type  */
  YYSYMBOL_293_4 = 293,                    /* $@4  */
  YYSYMBOL_coclass = 294,                  /* coclass  */
  YYSYMBOL_coclasshdr = 295,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 296,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 297,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_hdr = 298,         /* runtimeclass_hdr  */
  YYSYMBOL_runtimeclass_def = 299,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 300,              /* apicontract  */
  YYSYMBOL_namespacedef = 301,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 302,         /* class_interfaces  */
  YYSYMBOL_class_interface = 303,          /* class_interface  */
  YYSYMBOL_dispinterface = 304,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 305,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 306,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 307,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 308,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 309,                  /* inherit  */
  YYSYMBOL_interface = 310,                /* interface  */
  YYSYMBOL_interfacehdr = 311,             /* interfacehdr  */
  YYSYMBOL_interfacedef = 312,             /* interfacedef  */
  YYSYMBOL_interfacedec = 313,             /* interfacedec  */
  YYSYMBOL_module = 314,                   /* module  */
  YYSYMBOL_modulehdr = 315,                /* modulehdr  */
  YYSYMBOL_moduledef = 316,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 317,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 318,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 319,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 320,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 321,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 322,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 323,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 324,               /* declarator  */
  YYSYMBOL_direct_declarator = 325,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 326,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 327, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 328,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 329, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 330,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 331, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 332,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 333,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 334,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 335,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 336,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 337,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 338,          /* init_declarator  */
  YYSYMBOL_threading_type = 339,           /* threading_type  */
  YYSYMBOL_pointer_type = 340,             /* pointer_type  */
  YYSYMBOL_structdef = 341,                /* structdef  */
  YYSYMBOL_type = 342,                     /* type  */
  YYSYMBOL_typedef = 343,                  /* typedef  */
  YYSYMBOL_uniondef = 344,                 /* uniondef  */
  YYSYMBOL_version = 345,                  /* version  */
  YYSYMBOL_acf_statements = 346,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 347,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 348,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 349,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 350,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 351,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 352,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 353,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 354           /* allocate_option  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3307

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  228
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  127
/* YYNRULES -- Number of rules.  */
#define YYNRULES  448
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  797

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   458


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   212,     2,     2,     2,   211,   204,     2,
     225,   226,   209,   208,   199,   207,   219,   210,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   201,   224,
     205,   227,   206,   200,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   220,     2,   221,   203,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   222,   202,   223,   213,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   214,   215,   216,   217,   218
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   341,   341,   355,   355,   357,   358,   358,   360,   361,
     362,   365,   368,   370,   371,   373,   374,   375,   378,   379,
     380,   380,   382,   383,   384,   387,   389,   390,   392,   393,
     394,   395,   398,   399,   402,   403,   407,   408,   409,   410,
     411,   412,   413,   416,   427,   428,   432,   433,   434,   435,
     436,   437,   438,   439,   440,   443,   445,   453,   459,   463,
     464,   466,   470,   474,   475,   478,   479,   482,   483,   487,
     492,   499,   503,   504,   507,   508,   512,   515,   516,   517,
     520,   521,   525,   526,   527,   531,   532,   535,   541,   542,
     543,   544,   545,   546,   547,   548,   549,   550,   551,   552,
     553,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,   564,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   591,   592,   593,   594,
     595,   596,   597,   598,   599,   600,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,   624,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   646,   647,   648,
     649,   650,   651,   655,   656,   661,   662,   663,   664,   667,
     668,   671,   675,   681,   682,   683,   686,   690,   702,   707,
     711,   716,   719,   720,   723,   724,   727,   728,   729,   730,
     731,   732,   733,   734,   735,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,   753,   754,   755,   756,   757,   758,   759,   760,
     761,   762,   763,   764,   766,   768,   769,   772,   773,   776,
     782,   788,   789,   792,   797,   804,   805,   808,   809,   813,
     814,   817,   821,   827,   835,   839,   844,   845,   848,   849,
     850,   853,   855,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   871,   872,   875,   876,   877,   878,
     879,   880,   881,   882,   883,   887,   888,   888,   892,   893,
     893,   896,   897,   905,   911,   916,   917,   924,   930,   934,
     941,   942,   945,   946,   950,   953,   954,   957,   966,   967,
     970,   971,   974,   980,   986,   987,   990,   991,   994,  1001,
    1010,  1015,  1019,  1020,  1023,  1024,  1027,  1032,  1039,  1040,
    1041,  1045,  1049,  1052,  1053,  1056,  1057,  1061,  1062,  1066,
    1067,  1068,  1072,  1074,  1075,  1079,  1080,  1081,  1082,  1087,
    1089,  1090,  1095,  1097,  1101,  1102,  1107,  1108,  1109,  1110,
    1114,  1122,  1124,  1125,  1130,  1132,  1136,  1137,  1144,  1145,
    1146,  1147,  1148,  1152,  1159,  1160,  1163,  1164,  1167,  1174,
    1175,  1180,  1181,  1185,  1186,  1187,  1188,  1189,  1190,  1194,
    1195,  1196,  1199,  1202,  1203,  1204,  1205,  1206,  1207,  1208,
    1209,  1210,  1211,  1214,  1221,  1223,  1229,  1230,  1231,  1235,
    1236,  1240,  1241,  1245,  1252,  1261,  1262,  1266,  1267,  1271,
    1273,  1274,  1275,  1279,  1280,  1285,  1286,  1287,  1288
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "aIDENTIFIER",
  "aPRAGMA", "aKNOWNTYPE", "aNAMESPACE", "aNUM", "aHEXNUM", "aDOUBLE",
  "aSTRING", "aWSTRING", "aSQSTRING", "aUUID", "aEOF", "aACF", "SHL",
  "SHR", "MEMBERPTR", "EQUALITY", "INEQUALITY", "GREATEREQUAL",
  "LESSEQUAL", "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tAGGREGATABLE",
  "tAGILE", "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT",
  "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE",
  "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK",
  "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE",
  "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEXCLUSIVETO", "tEXPLICITHANDLE", "tEXTERN", "tFALSE",
  "tFASTCALL", "tFAULTSTATUS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE",
  "tHANDLET", "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING",
  "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID",
  "tIDEMPOTENT", "tIGNORE", "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE",
  "tIMPORT", "tIMPORTLIB", "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC",
  "tINT", "tINT32", "tINT3264", "tINT64", "tINTERFACE", "tLCID",
  "tLENGTHIS", "tLIBRARY", "tLICENSED", "tLOCAL", "tLONG",
  "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT",
  "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT",
  "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT", "tPRAGMA_WARNING",
  "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF",
  "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER",
  "tREPRESENTAS", "tREQUESTEDIT", "tRESTRICTED", "tRETVAL",
  "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT", "tSIGNED", "tSINGLENODE",
  "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTANDARD", "tSTATIC",
  "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT", "tSWITCH",
  "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS", "tTRUE",
  "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
  "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG",
  "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT",
  "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'", "':'", "'|'",
  "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'", "'%'", "'!'",
  "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'", "'['", "']'",
  "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept", "input", "m_acf",
  "gbl_statements", "$@1", "imp_statements", "$@2", "int_statements",
  "semicolon_opt", "statement", "pragma_warning", "warnings", "typedecl",
  "cppquote", "import_start", "import", "importlib", "libraryhdr",
  "library_start", "librarydef", "m_args", "arg_list", "args", "arg",
  "array", "m_attributes", "attributes", "attrib_list", "str_list",
  "marshaling_behavior", "contract_ver", "contract_req", "attribute",
  "uuid_string", "callconv", "cases", "case", "enums", "enum_list",
  "enum_member", "enum", "enumdef", "m_exprs", "m_expr", "expr",
  "expr_list_int_const", "expr_int_const", "expr_const", "fields", "field",
  "ne_union_field", "ne_union_fields", "union_field", "s_field", "funcdef",
  "declaration", "m_ident", "t_ident", "ident", "base_type", "m_int",
  "int_std", "qualified_seq", "$@3", "qualified_type", "$@4", "coclass",
  "coclasshdr", "coclassdef", "runtimeclass", "runtimeclass_hdr",
  "runtimeclass_def", "apicontract", "namespacedef", "class_interfaces",
  "class_interface", "dispinterface", "dispinterfacehdr", "dispint_props",
  "dispint_meths", "dispinterfacedef", "inherit", "interface",
  "interfacehdr", "interfacedef", "interfacedec", "module", "modulehdr",
  "moduledef", "storage_cls_spec", "function_specifier", "type_qualifier",
  "m_type_qual_list", "decl_spec", "m_decl_spec_no_type",
  "decl_spec_no_type", "declarator", "direct_declarator",
  "abstract_declarator", "abstract_declarator_no_direct",
  "m_abstract_declarator", "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version",
  "acf_statements", "acf_int_statements", "acf_int_statement",
  "acf_interface", "acf_attributes", "acf_attribute_list", "acf_attribute",
  "allocate_option_list", "allocate_option", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,    44,
      63,    58,   124,    94,    38,    60,    62,    45,    43,    42,
      47,    37,    33,   126,   454,   455,   456,   457,   458,    46,
      91,    93,   123,   125,    59,    40,    41,    61
};
#endif

#define YYPACT_NINF (-618)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-436)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -618,    71,  1776,  -618,  -618,  -618,  -136,   -68,  -618,  -618,
    -618,   185,  -618,  -121,   229,  -618,   263,  -618,  -618,  -618,
    -618,    35,   117,  -618,  -618,  -618,  -618,  -618,   299,    35,
     164,   -51,  -618,   306,   -47,    35,   325,  -618,  -618,   315,
     318,   325,  -618,  -618,  3114,  -618,  -618,  -618,   -35,  -618,
    -618,  -618,  -618,  -618,   -23,  2774,   -26,   -11,  -618,  -618,
    -618,     4,   -45,  -618,    15,    -3,  -618,    51,    36,    55,
      54,    58,    70,    37,  -618,  -618,    88,  -618,    -5,    -5,
      -5,    81,  2962,    90,    -5,    98,   104,  -618,    40,  -618,
     -68,   195,  -618,  -618,   322,  -618,  -618,   105,  -618,   115,
    -618,  -618,   114,  -618,  -618,  -618,  -618,  -618,   360,  -618,
    -618,  2962,  -618,  -618,   109,   153,  -107,  -101,  -618,  -618,
     158,  -618,  -618,   159,  -618,  -618,  -618,   170,   174,  -618,
    -618,  -618,  -618,  -618,   175,   180,  -618,   197,  -618,  -618,
    -618,  -618,   202,  -618,  -618,  -618,   210,  -618,  -618,  -618,
     211,   212,   213,  -618,  -618,  -618,  -618,   215,   217,   225,
     235,   236,  -618,   237,  -618,  -618,   239,  -618,   240,  -618,
    -618,   241,   243,  -618,  -618,   244,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,   245,  -618,  -618,
    -618,   246,   247,  -618,  -618,  -618,  -618,  -618,  -618,   248,
    -618,  -618,   252,  -618,  -618,  -618,   253,  -618,  -618,  -618,
     255,   256,   257,   259,  -618,  -618,  -618,   261,   264,  -618,
    -618,   266,   267,   268,   -53,  -618,  -618,  -618,  1926,   887,
     274,   480,   356,   359,   363,   366,   369,   273,   301,  -618,
    -618,  -618,  -618,  -618,    81,   302,   304,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,   -58,  -618,  -618,  -618,   194,
     307,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,    81,    81,  -618,   305,  -150,  -618,  -618,
    -618,    -5,  -618,  -618,  -618,   384,   308,  -618,  -618,  -618,
     -46,  -618,  -618,   483,   309,    -9,  -618,   330,   310,  -618,
     312,  -618,   524,   230,   385,   742,  2868,   531,   230,   742,
     529,   530,   742,  2868,   742,   532,   533,   742,   536,   742,
     742,  2381,   742,   742,    12,   537,   -59,   538,   742,  2962,
     742,   742,  2962,   258,  2962,  2962,   230,    83,   539,  2962,
    3114,   321,  -618,   327,  -618,  -618,  -618,   326,  -618,   329,
    -618,   331,   332,  -618,  -618,  -618,    58,  2868,  -618,   334,
     335,  -618,  -618,  -618,  -618,   335,   -93,  -618,  -618,    32,
      34,  -618,   357,   -94,   336,   339,  -618,  -618,  1304,    56,
     337,  -618,   742,   616,  2381,  -618,  -618,   343,  -618,  -618,
      91,    40,  -618,   342,  -618,   385,   344,   367,   338,  -618,
     562,  -618,    66,   274,    72,   347,  -618,  -618,   348,   349,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,   345,
    -618,   742,   742,   742,   742,   742,   742,   605,  2626,   -88,
    -618,   350,   378,   361,   352,   380,  2626,   355,   358,  -618,
     -83,   362,   364,   365,   370,   371,   372,   374,   375,  1347,
     376,  2868,    76,   379,   -57,  -618,  2626,  -618,  -618,  -618,
     381,   383,   392,   394,   386,   395,   -54,  2388,   414,  -618,
    -618,  -618,  -618,  -618,  -618,   415,   417,   419,   423,   368,
    -618,   426,   429,   430,  -618,  3114,   573,  -618,  -618,  -618,
    -618,  -618,    81,   434,    58,    21,  -618,    58,  1165,  -618,
     403,  2868,   382,  1658,   436,   486,  1422,    58,  -618,  2868,
    -618,  -618,  -618,  -618,   696,  -618,  2482,   435,   454,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,   -39,  -618,  -618,   481,
    -618,  -618,    80,   742,  -618,    18,  -618,  2868,  -618,   446,
    -618,   449,  -618,   451,  -618,  -618,  -618,  2868,    27,    27,
      27,    27,    27,    27,  2415,   254,   742,   742,   673,   742,
     742,   742,   742,   742,   742,   742,   742,   742,   742,   742,
     742,   742,   742,   742,   742,   742,   674,   742,   742,  -618,
    -618,   531,   671,  -618,   742,  -618,  -618,   669,  -618,  -618,
    -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,  -618,    76,
    -618,  2051,  -618,    76,  -618,  -618,  -618,   -85,  -618,   742,
    -618,  -618,  -618,  -618,  -618,   742,  -618,  -618,  -618,  -618,
    -618,  -618,  -618,  -618,   675,  -618,  -618,  -618,  -618,   457,
    -618,  -618,   487,  -618,  -618,  -618,  -618,  -618,  -618,    81,
     204,  -618,  -618,  2868,   463,  -618,  -618,  -618,    58,  -618,
    -618,  -618,  -618,  2287,   384,    91,  -618,   469,   467,   481,
    -618,  -618,  -618,  -618,    76,   468,   385,  -618,  -618,   254,
    -618,  -618,  2169,  -618,   254,  -618,   471,   -24,   206,   206,
    -618,   880,   880,   200,   200,   647,   427,  2558,  1780,  2094,
    1017,   200,   200,   106,   106,    27,    27,    27,  -618,  2504,
    -618,  -618,  -618,   474,  -618,  -618,    52,  -618,   475,    76,
     476,  -618,  2381,  -618,  -618,   489,  -618,    58,  1026,    81,
    -618,  -618,  1540,  -618,  -618,  -618,  -618,  -618,   688,  -618,
    -618,   493,  -618,   -69,  -618,   495,  -618,   492,    53,  -618,
     498,    76,   500,  -618,   742,  2381,  -618,   742,  -618,  -618,
    -618,    52,  -618,  -618,  -618,   501,  -618,  -618,  -618,  -618,
      58,   504,   742,  -618,    76,  -618,  -618,  -618,  -618,    52,
    -618,  -618,  -618,    27,   506,  2626,  -618,  -618,  -618,  -618,
    -618,  -618,     8,  -618,  -618,   742,   540,  -618,  -618,   541,
     -92,   -92,  -618,  -618,   509,  -618,  -618
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    41,   308,     0,   429,   291,   283,
     302,     0,   352,     0,     0,   290,   278,   292,   348,   289,
     293,   294,     0,   351,   296,   303,   304,   301,     0,   294,
       0,     0,   350,     0,     0,   294,     0,   298,   349,   278,
     278,   288,   413,   284,    88,     2,    17,    42,     0,    36,
      18,    39,    18,    16,     0,    75,   416,     0,   415,   285,
     414,     0,     0,    11,     0,     0,    14,     0,     0,     0,
       0,    34,     0,   334,     9,     8,     0,    15,   357,   357,
     357,     0,     0,   418,   357,     0,   420,   309,     0,     4,
     429,     0,   311,   312,     0,   325,   326,   417,   280,     0,
     295,   300,     0,   336,   337,   299,   320,   321,     0,   315,
     316,     0,   297,   286,   419,     0,   421,     0,   287,    89,
       0,    91,    92,     0,    93,    94,    95,     0,     0,    98,
      99,   100,   101,   102,     0,     0,   105,     0,   107,   108,
     109,   110,     0,   112,   113,   114,     0,   116,   117,   118,
       0,     0,     0,   122,   123,   124,   125,     0,     0,     0,
       0,     0,   131,     0,   133,   134,     0,   136,     0,   138,
     139,   142,     0,   143,   144,     0,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,     0,   158,   159,
     160,     0,     0,   163,   164,   165,   166,   411,   167,     0,
     169,   409,     0,   171,   172,   173,     0,   175,   176,   177,
       0,     0,     0,     0,   182,   410,   183,     0,     0,   187,
     188,     0,     0,     0,     0,    77,   192,    37,    74,    74,
      74,     0,   278,     0,     0,   278,   278,     0,   416,   313,
     317,   327,   338,   346,     0,   418,   420,    38,    10,   322,
      13,   322,    12,     6,   343,     0,    35,   341,   342,     0,
       0,    32,   361,   358,   360,   359,   281,   282,   195,   196,
     197,   198,   353,     0,     0,   365,   401,   364,   275,   416,
     418,   357,   420,   355,    40,     0,     0,   441,   440,   442,
       0,   437,   430,     0,     0,    74,    56,     0,     0,   261,
       0,   267,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   214,     0,     0,     0,     0,     0,     0,
     214,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    76,    57,     0,    29,    30,    31,     0,    24,     0,
      27,     0,     0,    22,    19,    28,    34,     0,    75,     0,
     417,    59,    60,   344,   345,   419,   421,    61,   274,    74,
      74,     5,     0,    74,     0,     0,   335,    32,    74,     0,
       0,   363,     0,     0,    63,   367,   356,     0,   305,   310,
       0,     0,   436,     0,    55,     0,     0,   205,   210,   206,
       0,   422,    74,    74,    74,     0,   194,   193,     0,     0,
     225,   216,   217,   218,   222,   223,   224,   219,   220,     0,
     221,     0,     0,     0,     0,     0,     0,     0,   259,     0,
     257,     0,     0,    85,     0,     0,   260,     0,     0,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   386,     0,     0,   212,   215,    82,    83,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   408,
     403,   404,   405,   406,   407,     0,     0,     0,     0,   426,
     428,     0,     0,     0,    78,    88,     0,    23,    26,    25,
      20,    62,     0,     0,    34,     0,   323,    34,    74,   328,
       0,     0,     0,     0,     0,     0,    74,    34,    33,    75,
     354,   362,   366,   402,     0,    73,     0,     0,    67,    64,
      65,   306,   447,   445,   448,   446,     0,   443,   438,   431,
     208,   211,    74,     0,    44,     0,   412,     0,   262,     0,
     424,    75,   268,     0,    90,   186,    96,     0,   249,   248,
     247,   250,   245,   246,     0,   374,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    97,
     103,     0,     0,   104,     0,   111,   115,     0,   119,   120,
     121,   126,   127,   128,   129,   130,   132,   135,   137,   386,
     353,    63,   391,   386,   388,   387,    70,   383,   141,   214,
     140,   145,   157,   161,   162,     0,   170,   174,   178,   179,
     181,   180,   184,   185,     0,   189,   190,   191,    79,     0,
      18,   394,   423,   319,   314,   324,   318,     7,   330,     0,
     418,   329,   332,     0,     0,   273,   333,    32,    34,   347,
      72,    71,   368,     0,     0,     0,   439,   435,     0,   431,
     207,   209,    45,    43,     0,   420,   276,   266,   265,   374,
     256,   353,    63,   378,   374,   375,     0,   371,   238,   239,
     251,   232,   233,   236,   237,   227,   228,     0,   229,   230,
     231,   235,   234,   241,   240,   243,   244,   242,   252,     0,
     258,    87,    86,     0,    81,    69,   386,   353,     0,   386,
       0,   382,    63,   390,   213,     0,   427,    34,    74,     0,
     271,   331,    74,   339,    68,    66,   307,   444,     0,   434,
     432,   396,   399,     0,   264,     0,   277,     0,   374,   353,
       0,   386,     0,   370,     0,    63,   377,     0,   255,   106,
     381,   386,   392,   385,   389,     0,   168,    58,    21,   395,
      34,     0,     0,   398,     0,   263,   199,   254,   369,   386,
     379,   373,   376,   253,     0,   226,   384,   393,   340,   433,
     397,   400,     0,   372,   380,     0,     0,   425,   200,     0,
      74,    74,   270,   202,     0,   201,   269
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -618,  -618,  -618,   373,  -618,   -48,  -618,  -364,  -336,     0,
    -618,  -618,  -618,  -618,  -618,   232,  -618,  -618,  -618,    16,
    -563,  -618,  -618,  -288,  -271,  -219,    -2,  -618,  -618,  -618,
     149,  -618,  -299,  -226,   -80,  -618,  -618,  -618,  -618,  -618,
     207,    13,   404,   129,  -217,  -618,  -285,  -304,  -618,  -618,
    -618,  -618,   -43,  -296,  -618,   260,  -618,    24,   -71,  -618,
      59,   140,    86,  -618,   496,  -618,     5,  -618,    17,    10,
    -618,    19,    20,    22,   505,  -618,   691,  -618,  -618,  -618,
    -618,  -618,   -32,  -618,    25,    14,  -618,  -618,    26,  -618,
    -618,  -365,  -527,   -50,   -44,   -30,  -243,  -618,  -618,  -618,
    -616,  -618,  -617,  -618,  -312,  -618,  -618,  -618,    -7,  -618,
     515,  -618,   441,     1,   -65,  -618,     7,  -618,   670,   102,
    -618,  -618,   111,  -618,   387,  -618,   107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    45,     2,   371,   228,   630,   378,   257,   344,
      47,   535,    48,    49,    50,    51,   345,   237,    52,   346,
     517,   518,   519,   520,   602,    54,   358,   224,   440,   460,
     434,   431,   225,   408,   603,   782,   788,   396,   397,   398,
     399,   279,   454,   455,   428,   429,   430,   437,   402,   538,
     542,   404,   793,   794,   644,    57,   735,    99,   604,    58,
     101,    59,   389,   654,    60,   285,   347,    62,   348,   349,
      65,   350,   351,   352,   369,   496,    69,    70,   373,   503,
      71,   260,    72,    73,   353,   354,   243,    76,   355,    78,
      79,    80,   379,    81,   262,    82,   276,   277,   675,   742,
     676,   677,   605,   710,   606,   607,   632,   763,   732,   733,
     278,   475,   226,   280,    84,    85,   282,   481,    89,   658,
     659,    90,    91,   290,   291,   526,   527
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      55,   274,    46,    83,   229,   244,   385,    61,   441,    86,
     275,   357,    64,   506,   510,    56,    75,   281,    53,    63,
     491,    66,    67,   242,    68,   662,   500,    74,    77,   443,
     380,   381,   446,   450,   448,   264,   265,   453,   708,   457,
     283,   484,  -435,   464,    12,   558,   298,   731,   263,   263,
     263,   785,    28,   737,   263,   266,   245,   267,   743,   266,
     239,   267,   246,   115,   117,   240,  -279,   786,   238,   286,
     383,     3,   300,   706,    18,   384,   395,   502,   513,   266,
    -279,   267,   435,    87,   266,   372,   267,    14,   105,   197,
     479,   480,   436,   201,   112,   436,   268,   268,   287,    23,
     268,    12,    12,   449,    94,    12,   456,   539,   543,   740,
     478,   578,   288,   456,   467,  -279,   587,   -51,   289,   522,
     268,   301,   768,   215,   558,   268,    44,   102,    44,  -279,
     764,    28,   792,   269,   269,   383,   511,   269,   579,   458,
     712,   100,   609,   588,   738,   609,   340,   731,    32,   755,
     495,   495,    88,   391,   501,   765,   230,   269,   634,   523,
     655,   636,   269,    38,   274,   436,   516,   106,   341,   610,
     107,   649,   617,   275,   108,   392,   113,   249,   111,   459,
     751,   118,   774,   537,   501,   501,   628,   656,    92,   227,
      93,   270,   270,   274,   274,   270,   383,   375,   -46,     5,
       6,   745,   275,   275,   548,   549,   550,   551,   552,   553,
     554,    44,   769,   247,  -203,   270,   556,   557,   558,   251,
     270,   271,   271,   374,   558,   271,    55,    55,   248,    83,
      83,   787,    95,   409,    96,    86,    86,   386,   259,   250,
     406,    56,    56,   407,   663,   271,   576,   577,   661,   631,
     271,   263,    44,   524,    44,   494,   432,   497,   253,   115,
     117,   600,   671,   442,   465,   272,    97,   468,    98,   476,
     477,   452,   383,   383,   483,   252,   255,   601,   672,   254,
     703,   273,   256,   722,   673,   600,    44,   705,   525,   536,
     272,   711,    44,   700,   258,   540,   383,   551,   268,   274,
      44,   601,   103,  -204,   104,   293,   273,   492,   275,   109,
     261,   110,   723,   395,   -48,   573,   574,   575,   114,   451,
      98,   116,   284,    98,   530,   576,   577,  -279,   -50,   -47,
     715,  -279,   294,   -49,   452,   269,   713,   295,   296,   678,
     679,   510,   681,   682,   683,   684,   685,   686,   687,   688,
     689,   690,   691,   692,   693,   694,   695,   696,   697,   360,
     699,    98,   361,   297,   362,   725,   363,   436,   364,   365,
      10,    98,   366,   510,    98,   299,   509,   555,   508,    83,
     469,   757,   451,   302,   303,    86,   510,   387,   266,   388,
     267,    56,   456,   270,   750,   304,   720,   753,   673,   305,
     306,   599,   541,   673,   510,   307,   746,   571,   572,   573,
     574,   575,   274,   571,   572,   573,   574,   575,    21,   576,
     577,   275,   308,   271,   778,   576,   577,   309,  -272,   771,
    -272,    24,    25,    26,    27,   310,   311,   312,   313,   776,
     314,    29,   315,   556,   557,   558,   559,   560,   561,   562,
     316,   639,   470,   471,   472,   473,   474,   783,   780,   244,
     317,   318,   319,   671,   320,   321,   322,   673,   323,   324,
     325,   326,   327,   328,   383,   674,   759,   329,   330,   672,
     331,   332,   333,   359,   334,    35,   335,   664,   393,   336,
      37,   337,   338,   339,    44,   367,    55,   669,    46,    83,
     789,   643,   640,    61,   509,    86,   508,    83,    64,   635,
     245,    56,    75,    86,    53,    63,   246,    66,    67,    56,
      68,   709,   238,    74,    77,   -52,   -53,   773,   -54,   377,
     775,   400,   382,   390,   405,   394,   401,   403,   433,   438,
     439,   485,   444,   445,   665,   436,   447,   461,   463,   482,
     487,   452,   486,   488,   490,   489,   493,  -279,   499,   274,
     504,   505,   521,   512,   529,   533,   532,   531,   275,   534,
     547,   501,   501,   544,   545,   546,   580,   581,   583,   584,
     582,   585,   718,   629,   586,   615,    22,   624,   589,   674,
     590,   591,   741,   244,   674,   736,   592,   593,   594,   451,
     595,   596,   598,   452,   638,   608,   641,   611,   410,   612,
       5,     6,   411,   412,   413,   414,   415,   416,   613,   410,
     614,   616,   452,   411,   412,   413,   414,   415,   416,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,   274,
     619,   620,     8,   621,     9,   622,   576,   577,   275,   623,
      10,   451,   625,   653,    12,   626,   627,   633,   674,   646,
     657,   652,   452,   556,   557,   558,   559,   560,   561,   562,
     451,   564,   666,   667,    15,   668,   680,   698,   702,   704,
     232,    17,   716,   717,    18,   417,   719,   721,    19,    88,
     729,    20,   734,   761,   762,   452,   417,   744,    21,   410,
     749,   752,   754,   411,   412,   413,   414,   415,   416,    23,
     451,    24,    25,    26,    27,   756,    55,   766,   767,    83,
     509,    29,   508,    83,   770,    86,   772,   777,   779,    86,
     701,    56,   784,   796,   466,    56,   418,   647,   714,   660,
     726,   790,   791,   451,   498,   410,   241,   418,   795,   411,
     412,   413,   414,   415,   416,   376,   370,   781,    32,   368,
     292,   730,   727,   645,    34,    35,    36,   462,   728,   419,
      37,     0,     0,    38,     0,     0,   417,   235,   528,     0,
     419,     0,     0,   420,     0,     0,   236,     0,    41,     0,
       0,     0,     0,     0,   420,     0,    42,    43,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   421,
       0,     0,   422,   423,   424,     0,     0,   425,   426,     0,
     421,     0,   417,   422,   423,   514,     0,   418,   425,   426,
     427,     0,     0,     0,     0,     0,     0,   515,     0,     0,
       0,   427,     0,     0,     0,     0,     0,     0,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,     0,
     419,     0,     0,     0,     0,     0,   576,   577,     0,     0,
       0,     0,     0,   418,   420,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     5,     6,     0,     0,   556,   557,   558,     0,
     421,   561,   562,   422,   423,   424,   419,     0,   425,   426,
       0,     0,     0,     0,     0,     0,     0,   650,     0,     0,
     420,   427,     0,     0,     8,     0,     9,     0,     0,     0,
       0,     0,    10,    11,     0,     0,    12,     0,     0,     0,
       0,     0,     0,    13,     0,     0,   421,     0,     0,   422,
     423,   424,     0,    14,   425,   426,    15,     0,     0,     0,
       0,     0,    16,    17,     0,     0,    18,   427,     0,     0,
      19,     0,     0,    20,     0,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    22,   343,     0,
       0,    23,     0,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       4,     5,     6,   556,   557,   558,   559,   560,   561,   562,
      32,     0,     0,     0,     0,    33,    34,    35,    36,     0,
       0,     0,    37,     0,     0,    38,     0,     0,     0,    39,
       0,     0,     0,     8,     0,     9,     0,     0,    40,     0,
      41,    10,    11,     0,     0,    12,     0,     0,    42,    43,
       0,     0,    13,     0,     0,   569,   570,   571,   572,   573,
     574,   575,    14,     0,     0,    15,     0,     0,     0,   576,
     577,    16,    17,     0,     0,    18,     0,    44,     0,    19,
     356,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,   343,     0,     0,
      23,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    33,    34,    35,    36,     0,     0,
       0,    37,     0,     0,    38,     0,     0,     0,    39,     0,
       0,     0,     8,     0,     9,     0,     0,    40,     0,    41,
      10,    11,     0,     0,    12,     0,     0,    42,    43,     0,
       0,    13,   569,   570,   571,   572,   573,   574,   575,     0,
       0,    14,     0,     0,    15,     0,   576,   577,     0,     0,
      16,    17,     0,     0,    18,     0,    44,     0,    19,   758,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,    23,
       0,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,     0,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,    34,    35,    36,     0,     0,     0,
      37,     0,     0,    38,     0,     0,     0,    39,     0,     0,
       0,     8,     0,     9,     0,     0,    40,     0,    41,    10,
       0,     0,     0,    12,     0,     0,    42,    43,     0,     0,
      13,     0,     0,   556,   557,   558,   559,   560,   561,   562,
     563,   564,     0,    15,     0,     0,     0,     0,     0,    16,
      17,     0,     0,    18,     0,    44,     0,    19,   637,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    22,     0,     0,     0,    23,     0,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     8,
       0,     9,     0,    34,    35,    36,     0,    10,     0,    37,
       0,    12,    38,     0,     0,     0,    39,     0,    13,     0,
       0,     0,     0,     0,     0,    40,     0,    41,     0,     0,
       0,    15,     0,     0,     0,    42,    43,    16,    17,     0,
       0,    18,     0,     0,     0,    19,     0,     0,    20,     0,
       0,     0,     0,     0,     0,    21,     0,     0,     0,     0,
       0,     0,    22,     0,    44,     0,    23,   507,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     4,     5,     6,   565,     0,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,     0,
       0,     0,     0,    31,     0,     0,   576,   577,     0,     0,
       0,     0,     0,   597,     0,    32,     0,     8,     0,     9,
       0,    34,    35,    36,     0,    10,     0,    37,     0,    12,
      38,     0,     0,     0,    39,     0,    13,     0,     0,     0,
       0,     0,     0,    40,     0,    41,     0,     0,     0,    15,
       0,     0,     0,    42,    43,    16,    17,     0,     0,    18,
       0,     0,     0,    19,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      22,     0,    44,     0,    23,   648,    24,    25,    26,    27,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     8,     0,     9,     0,    34,
      35,    36,     0,    10,     0,    37,     0,    12,    38,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,    40,     0,    41,     0,     0,     0,    15,     0,     0,
       0,    42,    43,   232,    17,     0,     0,    18,     0,     0,
       0,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    23,   760,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,   556,   557,   558,   559,
     560,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     8,     0,     9,     0,    34,    35,    36,
       0,    10,    11,    37,     0,    12,    38,     0,     0,     0,
     235,     0,    13,     0,     0,     0,     0,     0,     0,   236,
       0,    41,    14,     0,     0,    15,     0,     0,     0,    42,
      43,    16,    17,     0,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,    44,     0,
      23,   642,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       4,     5,     6,     0,    33,    34,    35,    36,     0,     0,
     342,    37,     0,     0,    38,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,   -74,     0,    40,     0,    41,
       0,     0,     0,     8,     0,     9,     0,    42,    43,     0,
       0,    10,    11,     0,     0,    12,     0,     0,     0,     0,
       0,     0,    13,   567,   568,   569,   570,   571,   572,   573,
     574,   575,    14,     0,     0,    15,    44,     0,     0,   576,
     577,    16,    17,     0,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,   343,     0,     0,
      23,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    33,    34,    35,    36,     8,     0,
       9,    37,     0,     0,    38,   268,    10,     0,    39,     0,
      12,     0,     0,     0,     0,     0,     0,    40,     0,    41,
     556,   557,   558,   559,   560,   561,   562,    42,    43,     0,
      15,     0,     0,     0,     0,     0,   232,    17,     0,     0,
      18,     0,   269,     0,    19,     0,     0,    20,     0,     0,
       0,     0,     0,     0,    21,     0,    44,     0,     0,     0,
       0,     0,     0,     0,     0,    23,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     270,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     8,     0,     9,     0,
      34,    35,    36,   268,    10,     0,    37,     0,    12,    38,
     271,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    41,     0,     0,     0,    15,     0,
       0,     0,    42,    43,   232,    17,     0,     0,    18,     0,
     269,     0,    19,     0,     0,    20,     0,     0,     0,     0,
     707,     0,    21,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    23,     0,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
       0,     0,     5,     6,     0,     0,     0,     0,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,   270,     0,
       0,     0,   724,   576,   577,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     8,     0,     9,     0,    34,    35,
      36,     0,    10,     0,    37,     0,    12,    38,   271,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
     236,     0,    41,     0,     0,     0,    15,     0,     0,     0,
      42,    43,   232,    17,     0,     0,    18,     0,     0,     0,
      19,     0,     0,    20,     0,     0,     0,     0,   739,     0,
      21,     0,     0,     0,     0,     0,     5,     6,     0,    44,
       0,    23,     0,    24,    25,    26,    27,     0,     0,     0,
       0,     0,     0,    29,   556,   557,   558,   559,   560,   561,
     562,   563,   564,     0,     0,     0,     0,     0,     8,     0,
       9,     0,     0,     0,     0,     0,    10,     0,     0,     0,
      12,   556,   557,   558,   559,   560,   561,   562,   563,   564,
      32,     0,     0,     0,     0,     0,    34,    35,    36,     0,
      15,     0,    37,     0,     0,    38,   232,    17,     0,   235,
      18,     0,     0,     0,    19,     0,     0,    20,   236,     0,
      41,     0,     0,     0,    21,     0,     0,     0,    42,    43,
       0,     0,     0,     0,     0,    23,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,    29,   556,   557,
     558,   559,   560,   561,   562,   563,   564,    44,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     556,   557,   558,   559,   560,   561,   562,   563,   564,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
      34,    35,    36,     0,     0,     0,    37,     0,     0,    38,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    41,     0,     0,     0,     0,     0,
       0,     0,    42,    43,   556,   557,   558,   559,   560,   561,
     562,   563,   564,     0,     0,     0,     0,     0,   565,     0,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
       0,    44,     0,     0,     0,     0,     0,   576,   577,     0,
       0,     0,     0,     0,   618,   565,     0,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,     0,     0,     0,
       0,     0,     0,     0,   576,   577,     0,     0,     0,     0,
       0,   670,   556,   557,   558,   559,   560,   561,   562,   563,
     564,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   565,     0,   566,   567,   568,   569,   570,   571,
     572,   573,   574,   575,     0,     0,     0,     0,     0,     0,
       0,   576,   577,   651,   565,     0,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,     0,     0,     0,     0,
       0,     0,     0,   576,   577,   748,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   565,   747,
     566,   567,   568,   569,   570,   571,   572,   573,   574,   575,
       0,     0,     0,     0,     0,     0,     0,   576,   577,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,     0,     0,     0,     0,
       0,     8,     0,     9,     0,     0,     0,     0,     0,    10,
      11,     0,     0,    12,     0,     0,   565,     0,   566,   567,
     568,   569,   570,   571,   572,   573,   574,   575,     0,     0,
      14,     0,     0,    15,     0,   576,   577,     0,     0,   232,
      17,     0,     0,    18,     0,     0,     0,    19,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     5,     6,     0,     0,     0,    23,     0,
      24,    25,    26,    27,    28,     0,     0,   233,     0,     0,
      29,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     9,     0,     0,
       0,     0,     0,    10,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,    33,    34,    35,    36,     0,    15,     0,    37,
       0,     0,    38,   232,    17,     0,   235,    18,     0,     0,
       0,    19,     0,     0,    20,   236,     0,    41,     0,     0,
       0,    21,     0,     0,     0,    42,    43,     5,     6,     0,
       0,     0,    23,     0,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     9,     0,     0,     0,     0,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,    34,    35,    36,
       0,    15,     0,    37,     0,     0,    38,   232,    17,     0,
     235,     0,     0,     0,     0,    19,     0,     0,    20,   236,
       0,    41,     0,     0,     0,    21,     0,     0,     0,    42,
      43,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,    35,    36,     0,     0,     0,    37,     0,     0,
       0,     0,     0,     0,   235,     0,     0,     0,     0,     0,
     119,     0,     0,   236,   120,    41,   121,   122,   123,   124,
     125,     0,   126,    42,    43,   127,     0,   128,     0,     0,
       0,   129,   130,     0,   131,   132,   133,   134,   135,   136,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
       0,   146,     0,     0,   147,   148,   149,   150,   151,     0,
       0,   152,   153,     0,     0,     0,   154,     0,   155,   156,
       0,   157,   158,   159,   160,   161,   162,     0,   163,   164,
     165,   166,   167,   168,     0,     0,   169,     0,     0,   170,
       0,     0,     0,     0,     0,   171,   172,     0,   173,   174,
       0,   175,   176,   177,     0,     0,     0,     0,   178,   179,
     180,     0,   181,   182,   183,     0,   184,   185,   186,   187,
     188,   189,   190,     0,   191,     0,   192,     0,   193,   194,
     195,   196,   197,   198,   199,   200,   201,     0,   202,   203,
     204,   205,     0,     0,     0,     0,     0,   206,     0,     0,
     207,     0,     0,     0,   208,   209,     0,     0,   210,   211,
     212,   213,     0,     0,   214,     0,   215,     0,   216,   217,
     218,   219,   220,   221,   222,     0,     0,   223
};

static const yytype_int16 yycheck[] =
{
       2,    81,     2,     2,    52,    55,   277,     2,   312,     2,
      81,   230,     2,   377,   379,     2,     2,    82,     2,     2,
     356,     2,     2,    55,     2,     7,   120,     2,     2,   314,
     273,   274,   317,   321,   319,    79,    80,   322,   601,    27,
      84,   340,   110,   328,    49,    18,   111,   664,    78,    79,
      80,    43,   110,   669,    84,     3,    55,     5,   674,     3,
      55,     5,    55,    39,    40,    55,   173,    59,    55,    29,
     220,     0,   173,   600,    79,   225,   295,   373,   382,     3,
     173,     5,   308,   219,     3,   143,     5,    66,    29,   148,
       7,     8,   309,   152,    35,   312,    44,    44,    58,   104,
      44,    49,    49,   320,   225,    49,   323,   403,   404,   672,
     336,   199,    72,   330,   331,   222,   199,   224,    78,    28,
      44,   222,   738,   182,    18,    44,   220,    10,   220,   222,
     199,   110,   224,    81,    81,   220,   379,    81,   226,   127,
     225,   106,   199,   226,   671,   199,   199,   764,   153,   712,
     369,   370,   220,   199,   373,   224,   179,    81,   494,    68,
     199,   497,    81,   168,   244,   382,   383,     3,   221,   226,
       6,   507,   226,   244,   225,   221,    36,   222,   225,   167,
     707,    41,   745,   402,   403,   404,   485,   226,     3,   224,
       5,   139,   139,   273,   274,   139,   220,     3,   224,     5,
       6,   225,   273,   274,   421,   422,   423,   424,   425,   426,
     427,   220,   739,   224,   223,   139,    16,    17,    18,   222,
     139,   169,   169,   255,    18,   169,   228,   229,   224,   228,
     229,   223,     3,   304,     5,   228,   229,   281,   201,   224,
      10,   228,   229,    13,   226,   169,   219,   220,   533,   492,
     169,   281,   220,   162,   220,   223,   306,   223,   222,   235,
     236,   209,   209,   313,   329,   209,     3,   332,     5,   334,
     335,   321,   220,   220,   339,   224,   222,   225,   225,   224,
     584,   225,   224,   647,   555,   209,   220,   599,   197,   223,
     209,   603,   220,   578,   224,   223,   220,   514,    44,   379,
     220,   225,     3,   223,     5,   110,   225,   357,   379,     3,
     222,     5,   648,   532,   224,   209,   210,   211,     3,   321,
       5,     3,   224,     5,   395,   219,   220,   222,   224,   224,
     615,   222,    10,   224,   384,    81,   607,   222,   224,   556,
     557,   706,   559,   560,   561,   562,   563,   564,   565,   566,
     567,   568,   569,   570,   571,   572,   573,   574,   575,     3,
     577,     5,     3,     3,     5,   653,     3,   584,     5,     3,
      45,     5,     3,   738,     5,   222,   378,   427,   378,   378,
     122,   717,   384,   225,   225,   378,   751,     3,     3,     5,
       5,   378,   609,   139,   706,   225,   639,   709,   669,   225,
     225,   451,   404,   674,   769,   225,   677,   207,   208,   209,
     210,   211,   492,   207,   208,   209,   210,   211,    93,   219,
     220,   492,   225,   169,   760,   219,   220,   225,   224,   741,
     226,   106,   107,   108,   109,   225,   225,   225,   225,   751,
     225,   116,   225,    16,    17,    18,    19,    20,    21,    22,
     225,   501,   194,   195,   196,   197,   198,   769,   762,   509,
     225,   225,   225,   209,   225,   225,   225,   738,   225,   225,
     225,   225,   225,   225,   220,   555,   719,   225,   225,   225,
     225,   225,   225,     3,   225,   160,   225,   537,     5,   225,
     165,   225,   225,   225,   220,   222,   498,   547,   498,   498,
     785,   503,   501,   498,   506,   498,   506,   506,   498,   495,
     509,   498,   498,   506,   498,   498,   509,   498,   498,   506,
     498,   601,   509,   498,   498,   224,   224,   744,   224,   222,
     747,   201,   227,   225,    10,   226,   226,   225,     7,    10,
      10,   220,    10,    10,   537,   762,    10,    10,    10,    10,
     224,   601,   225,   224,   222,   224,   222,   222,   201,   639,
     224,   222,   219,   226,   222,   227,   199,   223,   639,     7,
     225,   790,   791,   226,   226,   226,   226,   199,   226,   199,
     219,   226,   630,    10,   226,   199,   100,   219,   226,   669,
     226,   226,   672,   643,   674,   666,   226,   226,   226,   601,
     226,   226,   226,   653,   201,   226,   224,   226,     3,   226,
       5,     6,     7,     8,     9,    10,    11,    12,   226,     3,
     226,   226,   672,     7,     8,     9,    10,    11,    12,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   719,
     226,   226,    37,   226,    39,   226,   219,   220,   719,   226,
      45,   653,   226,   199,    49,   226,   226,   223,   738,   223,
     179,   226,   712,    16,    17,    18,    19,    20,    21,    22,
     672,    24,   226,   224,    69,   224,     3,     3,     7,    10,
      75,    76,     7,   226,    79,    80,   199,   224,    83,   220,
     223,    86,   224,     5,   201,   745,    80,   226,    93,     3,
     226,   226,   226,     7,     8,     9,    10,    11,    12,   104,
     712,   106,   107,   108,   109,   226,   718,   222,   226,   718,
     722,   116,   722,   722,   226,   718,   226,   226,   224,   722,
     581,   718,   226,   224,   330,   722,   131,   505,   609,   532,
     654,   201,   201,   745,   371,     3,    55,   131,   791,     7,
       8,     9,    10,    11,    12,   259,   251,   764,   153,   244,
      90,   659,   655,   503,   159,   160,   161,   326,   657,   164,
     165,    -1,    -1,   168,    -1,    -1,    80,   172,   391,    -1,
     164,    -1,    -1,   178,    -1,    -1,   181,    -1,   183,    -1,
      -1,    -1,    -1,    -1,   178,    -1,   191,   192,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,
      -1,    -1,   207,   208,   209,    -1,    -1,   212,   213,    -1,
     204,    -1,    80,   207,   208,   209,    -1,   131,   212,   213,
     225,    -1,    -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,
      -1,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
     164,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,   131,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,    16,    17,    18,    -1,
     204,    21,    22,   207,   208,   209,   164,    -1,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,    -1,    -1,
     178,   225,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,   204,    -1,    -1,   207,
     208,   209,    -1,    66,   212,   213,    69,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    79,   225,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,
      -1,   104,    -1,   106,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,
       4,     5,     6,    16,    17,    18,    19,    20,    21,    22,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,
      -1,    -1,   165,    -1,    -1,   168,    -1,    -1,    -1,   172,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,   181,    -1,
     183,    45,    46,    -1,    -1,    49,    -1,    -1,   191,   192,
      -1,    -1,    56,    -1,    -1,   205,   206,   207,   208,   209,
     210,   211,    66,    -1,    -1,    69,    -1,    -1,    -1,   219,
     220,    75,    76,    -1,    -1,    79,    -1,   220,    -1,    83,
     223,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,
      -1,   165,    -1,    -1,   168,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    37,    -1,    39,    -1,    -1,   181,    -1,   183,
      45,    46,    -1,    -1,    49,    -1,    -1,   191,   192,    -1,
      -1,    56,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    66,    -1,    -1,    69,    -1,   219,   220,    -1,    -1,
      75,    76,    -1,    -1,    79,    -1,   220,    -1,    83,   223,
      -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,   104,
      -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,    -1,    -1,    -1,
     165,    -1,    -1,   168,    -1,    -1,    -1,   172,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,   181,    -1,   183,    45,
      -1,    -1,    -1,    49,    -1,    -1,   191,   192,    -1,    -1,
      56,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    69,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    -1,    79,    -1,   220,    -1,    83,   223,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,    -1,   100,    -1,    -1,    -1,   104,    -1,
     106,   107,   108,   109,    -1,    -1,    -1,    -1,    -1,    -1,
     116,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    37,
      -1,    39,    -1,   159,   160,   161,    -1,    45,    -1,   165,
      -1,    49,   168,    -1,    -1,    -1,   172,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,   181,    -1,   183,    -1,    -1,
      -1,    69,    -1,    -1,    -1,   191,   192,    75,    76,    -1,
      -1,    79,    -1,    -1,    -1,    83,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,
      -1,    -1,   100,    -1,   220,    -1,   104,   223,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,    -1,   141,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,   226,    -1,   153,    -1,    37,    -1,    39,
      -1,   159,   160,   161,    -1,    45,    -1,   165,    -1,    49,
     168,    -1,    -1,    -1,   172,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,   181,    -1,   183,    -1,    -1,    -1,    69,
      -1,    -1,    -1,   191,   192,    75,    76,    -1,    -1,    79,
      -1,    -1,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,
     100,    -1,   220,    -1,   104,   223,   106,   107,   108,   109,
      -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    37,    -1,    39,    -1,   159,
     160,   161,    -1,    45,    -1,   165,    -1,    49,   168,    -1,
      -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   181,    -1,   183,    -1,    -1,    -1,    69,    -1,    -1,
      -1,   191,   192,    75,    76,    -1,    -1,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     220,    -1,   104,   223,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    37,    -1,    39,    -1,   159,   160,   161,
      -1,    45,    46,   165,    -1,    49,   168,    -1,    -1,    -1,
     172,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,   181,
      -1,   183,    66,    -1,    -1,    69,    -1,    -1,    -1,   191,
     192,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,    -1,   220,    -1,
     104,   223,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
       4,     5,     6,    -1,   158,   159,   160,   161,    -1,    -1,
      14,   165,    -1,    -1,   168,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,    -1,    -1,   179,    -1,   181,    -1,   183,
      -1,    -1,    -1,    37,    -1,    39,    -1,   191,   192,    -1,
      -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    66,    -1,    -1,    69,   220,    -1,    -1,   219,
     220,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,    83,
      -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    -1,    -1,    -1,   100,   101,    -1,    -1,
     104,    -1,   106,   107,   108,   109,   110,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,   123,
      -1,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,    37,    -1,
      39,   165,    -1,    -1,   168,    44,    45,    -1,   172,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,   181,    -1,   183,
      16,    17,    18,    19,    20,    21,    22,   191,   192,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    93,    -1,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   104,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     139,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    37,    -1,    39,    -1,
     159,   160,   161,    44,    45,    -1,   165,    -1,    49,   168,
     169,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,    -1,   183,    -1,    -1,    -1,    69,    -1,
      -1,    -1,   191,   192,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    -1,    -1,    86,    -1,    -1,    -1,    -1,
     209,    -1,    93,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   220,    -1,   104,    -1,   106,   107,   108,   109,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,     5,     6,    -1,    -1,    -1,    -1,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,   139,    -1,
      -1,    -1,    25,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    37,    -1,    39,    -1,   159,   160,
     161,    -1,    45,    -1,   165,    -1,    49,   168,   169,    -1,
      -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     181,    -1,   183,    -1,    -1,    -1,    69,    -1,    -1,    -1,
     191,   192,    75,    76,    -1,    -1,    79,    -1,    -1,    -1,
      83,    -1,    -1,    86,    -1,    -1,    -1,    -1,   209,    -1,
      93,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,   220,
      -1,   104,    -1,   106,   107,   108,   109,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     153,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,    -1,
      69,    -1,   165,    -1,    -1,   168,    75,    76,    -1,   172,
      79,    -1,    -1,    -1,    83,    -1,    -1,    86,   181,    -1,
     183,    -1,    -1,    -1,    93,    -1,    -1,    -1,   191,   192,
      -1,    -1,    -1,    -1,    -1,   104,    -1,   106,   107,   108,
     109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,    -1,
     159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,   168,
      -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   181,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   191,   192,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,   200,    -1,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,   220,    -1,    -1,    -1,    -1,    -1,   219,   220,    -1,
      -1,    -1,    -1,    -1,   226,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,    -1,    -1,    -1,    -1,
      -1,   226,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   200,    -1,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   200,    -1,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,   221,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    -1,    -1,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
      66,    -1,    -1,    69,    -1,   219,   220,    -1,    -1,    75,
      76,    -1,    -1,    79,    -1,    -1,    -1,    83,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    93,    -1,    -1,
      -1,    -1,    -1,     5,     6,    -1,    -1,    -1,   104,    -1,
     106,   107,   108,   109,   110,    -1,    -1,   113,    -1,    -1,
     116,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,
      -1,    -1,   158,   159,   160,   161,    -1,    69,    -1,   165,
      -1,    -1,   168,    75,    76,    -1,   172,    79,    -1,    -1,
      -1,    83,    -1,    -1,    86,   181,    -1,   183,    -1,    -1,
      -1,    93,    -1,    -1,    -1,   191,   192,     5,     6,    -1,
      -1,    -1,   104,    -1,   106,   107,   108,   109,    -1,    -1,
      -1,    -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   153,    -1,    -1,    -1,    -1,    -1,   159,   160,   161,
      -1,    69,    -1,   165,    -1,    -1,   168,    75,    76,    -1,
     172,    -1,    -1,    -1,    -1,    83,    -1,    -1,    86,   181,
      -1,   183,    -1,    -1,    -1,    93,    -1,    -1,    -1,   191,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,    -1,    -1,    -1,    -1,    -1,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,   161,    -1,    -1,    -1,   165,    -1,    -1,
      -1,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,   181,    30,   183,    32,    33,    34,    35,
      36,    -1,    38,   191,   192,    41,    -1,    43,    -1,    -1,
      -1,    47,    48,    -1,    50,    51,    52,    53,    54,    55,
      -1,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      -1,    67,    -1,    -1,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    -1,    82,    -1,    84,    85,
      -1,    87,    88,    89,    90,    91,    92,    -1,    94,    95,
      96,    97,    98,    99,    -1,    -1,   102,    -1,    -1,   105,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,   114,   115,
      -1,   117,   118,   119,    -1,    -1,    -1,    -1,   124,   125,
     126,    -1,   128,   129,   130,    -1,   132,   133,   134,   135,
     136,   137,   138,    -1,   140,    -1,   142,    -1,   144,   145,
     146,   147,   148,   149,   150,   151,   152,    -1,   154,   155,
     156,   157,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
     166,    -1,    -1,    -1,   170,   171,    -1,    -1,   174,   175,
     176,   177,    -1,    -1,   180,    -1,   182,    -1,   184,   185,
     186,   187,   188,   189,   190,    -1,    -1,   193
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   229,   231,     0,     4,     5,     6,    15,    37,    39,
      45,    46,    49,    56,    66,    69,    75,    76,    79,    83,
      86,    93,   100,   104,   106,   107,   108,   109,   110,   116,
     123,   141,   153,   158,   159,   160,   161,   165,   168,   172,
     181,   183,   191,   192,   220,   230,   237,   238,   240,   241,
     242,   243,   246,   247,   253,   254,   269,   283,   287,   289,
     292,   294,   295,   296,   297,   298,   299,   300,   301,   304,
     305,   308,   310,   311,   312,   313,   315,   316,   317,   318,
     319,   321,   323,   341,   342,   343,   344,   219,   220,   346,
     349,   350,     3,     5,   225,     3,     5,     3,     5,   285,
     106,   288,    10,     3,     5,   288,     3,     6,   225,     3,
       5,   225,   288,   289,     3,   285,     3,   285,   289,    26,
      30,    32,    33,    34,    35,    36,    38,    41,    43,    47,
      48,    50,    51,    52,    53,    54,    55,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    67,    70,    71,    72,
      73,    74,    77,    78,    82,    84,    85,    87,    88,    89,
      90,    91,    92,    94,    95,    96,    97,    98,    99,   102,
     105,   111,   112,   114,   115,   117,   118,   119,   124,   125,
     126,   128,   129,   130,   132,   133,   134,   135,   136,   137,
     138,   140,   142,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   154,   155,   156,   157,   163,   166,   170,   171,
     174,   175,   176,   177,   180,   182,   184,   185,   186,   187,
     188,   189,   190,   193,   255,   260,   340,   224,   233,   233,
     179,    31,    75,   113,   121,   172,   181,   245,   269,   294,
     297,   304,   310,   314,   321,   341,   344,   224,   224,   222,
     224,   222,   224,   222,   224,   222,   224,   236,   224,   201,
     309,   222,   322,   323,   322,   322,     3,     5,    44,    81,
     139,   169,   209,   225,   262,   286,   324,   325,   338,   269,
     341,   342,   344,   322,   224,   293,    29,    58,    72,    78,
     351,   352,   346,   110,    10,   222,   224,     3,   342,   222,
     173,   222,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     199,   221,    14,   101,   237,   244,   247,   294,   296,   297,
     299,   300,   301,   312,   313,   316,   223,   253,   254,     3,
       3,     3,     5,     3,     5,     3,     3,   222,   338,   302,
     302,   232,   143,   306,   310,     3,   292,   222,   235,   320,
     324,   324,   227,   220,   225,   252,   322,     3,     5,   290,
     225,   199,   221,     5,   226,   253,   265,   266,   267,   268,
     201,   226,   276,   225,   279,    10,    10,    13,   261,   286,
       3,     7,     8,     9,    10,    11,    12,    80,   131,   164,
     178,   204,   207,   208,   209,   212,   213,   225,   272,   273,
     274,   259,   321,     7,   258,   261,   272,   275,    10,    10,
     256,   275,   321,   274,    10,    10,   274,    10,   274,   272,
     251,   254,   321,   274,   270,   271,   272,    27,   127,   167,
     257,    10,   340,    10,   274,   342,   270,   272,   342,   122,
     194,   195,   196,   197,   198,   339,   342,   342,   261,     7,
       8,   345,    10,   342,   260,   220,   225,   224,   224,   224,
     222,   236,   321,   222,   223,   253,   303,   223,   231,   201,
     120,   253,   281,   307,   224,   222,   235,   223,   237,   254,
     319,   324,   226,   275,   209,   221,   272,   248,   249,   250,
     251,   219,    28,    68,   162,   197,   353,   354,   352,   222,
     286,   223,   199,   227,     7,   239,   223,   253,   277,   281,
     223,   254,   278,   281,   226,   226,   226,   225,   272,   272,
     272,   272,   272,   272,   272,   321,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   200,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   219,   220,   199,   226,
     226,   199,   219,   226,   199,   226,   226,   199,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   321,
     209,   225,   252,   262,   286,   330,   332,   333,   226,   199,
     226,   226,   226,   226,   226,   199,   226,   226,   226,   226,
     226,   226,   226,   226,   219,   226,   226,   226,   260,    10,
     234,   324,   334,   223,   236,   313,   236,   223,   201,   321,
     341,   224,   223,   254,   282,   283,   223,   243,   223,   236,
     221,   221,   226,   199,   291,   199,   226,   179,   347,   348,
     268,   274,     7,   226,   321,   344,   226,   224,   224,   321,
     226,   209,   225,   252,   262,   326,   328,   329,   272,   272,
       3,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,     3,   272,
     274,   258,     7,   275,    10,   332,   320,   209,   248,   262,
     331,   332,   225,   252,   271,   274,     7,   226,   233,   199,
     324,   224,   235,   236,    25,   251,   290,   354,   350,   223,
     347,   330,   336,   337,   224,   284,   286,   328,   320,   209,
     248,   262,   327,   328,   226,   225,   252,   201,   221,   226,
     332,   320,   226,   332,   226,   248,   226,   236,   223,   324,
     223,     5,   201,   335,   199,   224,   222,   226,   328,   320,
     226,   332,   226,   272,   248,   272,   332,   226,   236,   224,
     275,   336,   263,   332,   226,    43,    59,   223,   264,   274,
     201,   201,   224,   280,   281,   280,   224
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   228,   229,   230,   230,   231,   232,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   233,   233,
     234,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   235,   235,   236,   236,   237,   237,   237,   237,
     237,   237,   237,   238,   239,   239,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   242,   243,   244,   245,
     245,   246,   247,   248,   248,   249,   249,   250,   250,   251,
     251,   252,   252,   252,   253,   253,   254,   255,   255,   255,
     256,   256,   257,   257,   257,   258,   258,   259,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   261,   261,   262,   262,   262,   262,   263,
     263,   264,   264,   265,   265,   265,   266,   266,   267,   268,
     268,   269,   270,   270,   271,   271,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   273,   273,   274,
     275,   276,   276,   277,   277,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   283,   283,   284,   284,   285,   285,
     285,   286,   286,   287,   287,   287,   287,   287,   287,   287,
     287,   287,   287,   287,   288,   288,   289,   289,   289,   289,
     289,   289,   289,   289,   289,   290,   291,   290,   292,   293,
     292,   294,   294,   295,   296,   297,   297,   298,   299,   300,
     301,   301,   302,   302,   303,   304,   304,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   310,   311,   312,
     312,   312,   313,   313,   314,   314,   315,   316,   317,   317,
     317,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   323,   324,   324,   324,   325,   325,   325,   325,   326,
     326,   326,   327,   327,   328,   328,   329,   329,   329,   329,
     329,   330,   330,   330,   331,   331,   332,   332,   333,   333,
     333,   333,   333,   333,   334,   334,   335,   335,   336,   337,
     337,   338,   338,   339,   339,   339,   339,   339,   339,   340,
     340,   340,   341,   342,   342,   342,   342,   342,   342,   342,
     342,   342,   342,   343,   344,   344,   345,   345,   345,   346,
     346,   347,   347,   348,   349,   350,   350,   351,   351,   352,
     352,   352,   352,   353,   353,   354,   354,   354,   354
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     2,     2,
       3,     2,     3,     3,     2,     2,     2,     2,     0,     2,
       0,     6,     2,     3,     2,     3,     3,     2,     2,     2,
       2,     2,     0,     2,     0,     1,     1,     2,     2,     1,
       2,     1,     1,     6,     1,     2,     1,     2,     1,     2,
       1,     2,     2,     2,     2,     4,     3,     3,     5,     2,
       2,     3,     4,     0,     1,     1,     3,     1,     3,     3,
       2,     3,     3,     2,     0,     1,     3,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     3,     3,     0,     1,
       4,     1,     1,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     1,     4,     4,     1,     6,     1,     1,     1,
       1,     4,     1,     1,     1,     4,     1,     1,     1,     4,
       4,     4,     1,     1,     1,     1,     4,     4,     4,     4,
       4,     1,     4,     1,     1,     4,     1,     4,     1,     1,
       4,     4,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     1,     6,     1,
       4,     1,     1,     1,     4,     1,     1,     1,     4,     4,
       4,     4,     1,     1,     4,     4,     4,     1,     1,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     0,
       2,     4,     3,     0,     2,     1,     1,     3,     2,     3,
       1,     5,     1,     3,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     2,     2,
       2,     3,     3,     5,     5,     4,     3,     1,     3,     1,
       1,     0,     2,     4,     3,     2,     2,     0,     2,     2,
       1,     3,     2,     1,     3,     2,     0,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       1,     1,     1,     1,     0,     1,     1,     2,     1,     2,
       2,     1,     1,     1,     1,     1,     0,     4,     1,     0,
       4,     2,     2,     2,     5,     2,     2,     2,     5,     5,
       2,     2,     0,     2,     2,     2,     2,     2,     2,     3,
       2,     3,     5,     5,     0,     2,     2,     2,     2,     6,
       8,     2,     2,     2,     2,     2,     2,     5,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     0,     1,     2,
       2,     2,     3,     2,     1,     1,     3,     2,     4,     3,
       2,     1,     3,     2,     0,     1,     3,     2,     1,     3,
       4,     3,     2,     1,     3,     2,     0,     1,     1,     3,
       2,     1,     3,     4,     1,     3,     0,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     1,     1,     2,     1,     2,
       1,     2,     4,     5,     5,    10,     1,     3,     1,     0,
       2,     0,     2,     4,     6,     0,     3,     1,     3,     4,
       1,     1,     1,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: gbl_statements m_acf  */
#line 341 "tools/widl/parser.y"
                                                { check_statements((yyvsp[-1].stmt_list), FALSE);
						  check_all_user_types((yyvsp[-1].stmt_list));
						  write_header((yyvsp[-1].stmt_list));
						  write_id_data((yyvsp[-1].stmt_list));
						  write_proxies((yyvsp[-1].stmt_list));
						  write_client((yyvsp[-1].stmt_list));
						  write_server((yyvsp[-1].stmt_list));
						  write_regscript((yyvsp[-1].stmt_list));
						  write_typelib_regscript((yyvsp[-1].stmt_list));
						  write_dlldata((yyvsp[-1].stmt_list));
						  write_local_stubs((yyvsp[-1].stmt_list));
						}
#line 3250 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 357 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3256 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 358 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3262 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 359 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3268 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interfacedec  */
#line 360 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3274 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements interfacedef  */
#line 361 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3280 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements coclass ';'  */
#line 362 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3288 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclassdef  */
#line 365 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3296 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements apicontract ';'  */
#line 368 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3303 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 370 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3309 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3316 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements moduledef  */
#line 373 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3322 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements librarydef  */
#line 374 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3328 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements statement  */
#line 375 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3334 "tools/widl/parser.tab.c"
    break;

  case 18: /* imp_statements: %empty  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3340 "tools/widl/parser.tab.c"
    break;

  case 19: /* imp_statements: imp_statements interfacedec  */
#line 379 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3346 "tools/widl/parser.tab.c"
    break;

  case 20: /* $@2: %empty  */
#line 380 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3352 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 381 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3358 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements interfacedef  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3364 "tools/widl/parser.tab.c"
    break;

  case 23: /* imp_statements: imp_statements coclass ';'  */
#line 383 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3370 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements coclassdef  */
#line 384 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3378 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements apicontract ';'  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3385 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: imp_statements runtimeclass ';'  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3391 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements runtimeclass_def  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3398 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: imp_statements moduledef  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3404 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements statement  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3410 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements importlib  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3416 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements librarydef  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3422 "tools/widl/parser.tab.c"
    break;

  case 32: /* int_statements: %empty  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3428 "tools/widl/parser.tab.c"
    break;

  case 33: /* int_statements: int_statements statement  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3434 "tools/widl/parser.tab.c"
    break;

  case 36: /* statement: cppquote  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3440 "tools/widl/parser.tab.c"
    break;

  case 37: /* statement: typedecl ';'  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3446 "tools/widl/parser.tab.c"
    break;

  case 38: /* statement: declaration ';'  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3452 "tools/widl/parser.tab.c"
    break;

  case 39: /* statement: import  */
#line 410 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3458 "tools/widl/parser.tab.c"
    break;

  case 40: /* statement: typedef ';'  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3464 "tools/widl/parser.tab.c"
    break;

  case 41: /* statement: aPRAGMA  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3470 "tools/widl/parser.tab.c"
    break;

  case 42: /* statement: pragma_warning  */
#line 413 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3476 "tools/widl/parser.tab.c"
    break;

  case 43: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 417 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3488 "tools/widl/parser.tab.c"
    break;

  case 44: /* warnings: aNUM  */
#line 427 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3494 "tools/widl/parser.tab.c"
    break;

  case 45: /* warnings: warnings aNUM  */
#line 428 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3500 "tools/widl/parser.tab.c"
    break;

  case 47: /* typedecl: tENUM aIDENTIFIER  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3506 "tools/widl/parser.tab.c"
    break;

  case 49: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 435 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3512 "tools/widl/parser.tab.c"
    break;

  case 51: /* typedecl: tUNION aIDENTIFIER  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3518 "tools/widl/parser.tab.c"
    break;

  case 52: /* typedecl: attributes enumdef  */
#line 438 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3524 "tools/widl/parser.tab.c"
    break;

  case 53: /* typedecl: attributes structdef  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3530 "tools/widl/parser.tab.c"
    break;

  case 54: /* typedecl: attributes uniondef  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3536 "tools/widl/parser.tab.c"
    break;

  case 55: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 443 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3542 "tools/widl/parser.tab.c"
    break;

  case 56: /* import_start: tIMPORT aSTRING ';'  */
#line 445 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3553 "tools/widl/parser.tab.c"
    break;

  case 57: /* import: import_start imp_statements aEOF  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3562 "tools/widl/parser.tab.c"
    break;

  case 58: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 460 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3568 "tools/widl/parser.tab.c"
    break;

  case 59: /* libraryhdr: tLIBRARY aIDENTIFIER  */
#line 463 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3574 "tools/widl/parser.tab.c"
    break;

  case 60: /* libraryhdr: tLIBRARY aKNOWNTYPE  */
#line 464 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3580 "tools/widl/parser.tab.c"
    break;

  case 61: /* library_start: attributes libraryhdr '{'  */
#line 466 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3588 "tools/widl/parser.tab.c"
    break;

  case 62: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3594 "tools/widl/parser.tab.c"
    break;

  case 63: /* m_args: %empty  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3600 "tools/widl/parser.tab.c"
    break;

  case 65: /* arg_list: arg  */
#line 478 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3606 "tools/widl/parser.tab.c"
    break;

  case 66: /* arg_list: arg_list ',' arg  */
#line 479 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3612 "tools/widl/parser.tab.c"
    break;

  case 68: /* args: arg_list ',' ELLIPSIS  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3618 "tools/widl/parser.tab.c"
    break;

  case 69: /* arg: attributes decl_spec m_any_declarator  */
#line 487 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3628 "tools/widl/parser.tab.c"
    break;

  case 70: /* arg: decl_spec m_any_declarator  */
#line 492 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3638 "tools/widl/parser.tab.c"
    break;

  case 71: /* array: '[' expr ']'  */
#line 499 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3647 "tools/widl/parser.tab.c"
    break;

  case 72: /* array: '[' '*' ']'  */
#line 503 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3653 "tools/widl/parser.tab.c"
    break;

  case 73: /* array: '[' ']'  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3659 "tools/widl/parser.tab.c"
    break;

  case 74: /* m_attributes: %empty  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3665 "tools/widl/parser.tab.c"
    break;

  case 76: /* attributes: '[' attrib_list ']'  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3671 "tools/widl/parser.tab.c"
    break;

  case 77: /* attrib_list: attribute  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3677 "tools/widl/parser.tab.c"
    break;

  case 78: /* attrib_list: attrib_list ',' attribute  */
#line 516 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3683 "tools/widl/parser.tab.c"
    break;

  case 79: /* attrib_list: attrib_list ']' '[' attribute  */
#line 517 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3689 "tools/widl/parser.tab.c"
    break;

  case 80: /* str_list: aSTRING  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3695 "tools/widl/parser.tab.c"
    break;

  case 81: /* str_list: str_list ',' aSTRING  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3701 "tools/widl/parser.tab.c"
    break;

  case 82: /* marshaling_behavior: tAGILE  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3707 "tools/widl/parser.tab.c"
    break;

  case 83: /* marshaling_behavior: tNONE  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 84: /* marshaling_behavior: tSTANDARD  */
#line 527 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3719 "tools/widl/parser.tab.c"
    break;

  case 85: /* contract_ver: aNUM  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3725 "tools/widl/parser.tab.c"
    break;

  case 86: /* contract_ver: aNUM '.' aNUM  */
#line 532 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3731 "tools/widl/parser.tab.c"
    break;

  case 87: /* contract_req: decl_spec ',' contract_ver  */
#line 535 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3741 "tools/widl/parser.tab.c"
    break;

  case 88: /* attribute: %empty  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3747 "tools/widl/parser.tab.c"
    break;

  case 89: /* attribute: tAGGREGATABLE  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3753 "tools/widl/parser.tab.c"
    break;

  case 90: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 543 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3759 "tools/widl/parser.tab.c"
    break;

  case 91: /* attribute: tAPPOBJECT  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3765 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: tASYNC  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3771 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tAUTOHANDLE  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3777 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tBINDABLE  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3783 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tBROADCAST  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3789 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tCALLAS '(' ident ')'  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3795 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3801 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tCODE  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3807 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tCOMMSTATUS  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3813 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tCONTEXTHANDLE  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3819 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3825 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3831 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3837 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3843 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tCONTROL  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3849 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 559 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3855 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tDECODE  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3861 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tDEFAULT  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3867 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tDEFAULTBIND  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3873 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tDEFAULTCOLLELEM  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3879 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3885 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tDEFAULTVTABLE  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3891 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3897 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tDISPLAYBIND  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3903 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3909 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tDUAL  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3915 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tENABLEALLOCATE  */
#line 570 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3921 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tENCODE  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3927 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tENDPOINT '(' str_list ')'  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3933 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tENTRY '(' expr_const ')'  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3939 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 574 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tEXPLICITHANDLE  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tFAULTSTATUS  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tFORCEALLOCATE  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3965 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tHANDLE  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3971 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3977 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3983 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3989 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 584 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3995 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4001 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tHIDDEN  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4007 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tID '(' expr_int_const ')'  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4013 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tIDEMPOTENT  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4019 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tIGNORE  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4025 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tIIDIS '(' expr ')'  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4031 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tIMMEDIATEBIND  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4037 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4043 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tIN  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4049 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tINPUTSYNC  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4055 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4061 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tLCID '(' expr_int_const ')'  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4067 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tLCID  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4073 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tLICENSED  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4079 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tLOCAL  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4085 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4091 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tMAYBE  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4097 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tMESSAGE  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4103 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tNOCODE  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4109 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tNONBROWSABLE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4115 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tNONCREATABLE  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4121 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tNONEXTENSIBLE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4127 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tNOTIFY  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4133 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tNOTIFYFLAG  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4139 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tOBJECT  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4145 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tODL  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4151 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tOLEAUTOMATION  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4157 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4163 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tOPTIONAL  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4169 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tOUT  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4175 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tPARTIALIGNORE  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4181 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4187 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tPROGID '(' aSTRING ')'  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4193 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tPROPGET  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4199 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tPROPPUT  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4205 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tPROPPUTREF  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4211 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tPROXY  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4217 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tPUBLIC  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4223 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 625 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4231 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tREADONLY  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4237 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tREPRESENTAS '(' type ')'  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4243 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tREQUESTEDIT  */
#line 630 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4249 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tRESTRICTED  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4255 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tRETVAL  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4261 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4267 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tSOURCE  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4273 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4279 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tSTRING  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4285 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tSWITCHIS '(' expr ')'  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4291 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4297 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tTRANSMITAS '(' type ')'  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4303 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tTHREADING '(' threading_type ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4309 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tUIDEFAULT  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4315 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tUSESGETLASTERROR  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4321 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4327 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tUUID '(' uuid_string ')'  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4333 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4339 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tV1ENUM  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4345 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tVARARG  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4351 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tVERSION '(' version ')'  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4357 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4363 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4369 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: pointer_type  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4375 "tools/widl/parser.tab.c"
    break;

  case 194: /* uuid_string: aSTRING  */
#line 656 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4383 "tools/widl/parser.tab.c"
    break;

  case 195: /* callconv: tCDECL  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4389 "tools/widl/parser.tab.c"
    break;

  case 196: /* callconv: tFASTCALL  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4395 "tools/widl/parser.tab.c"
    break;

  case 197: /* callconv: tPASCAL  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4401 "tools/widl/parser.tab.c"
    break;

  case 198: /* callconv: tSTDCALL  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4407 "tools/widl/parser.tab.c"
    break;

  case 199: /* cases: %empty  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4413 "tools/widl/parser.tab.c"
    break;

  case 200: /* cases: cases case  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4419 "tools/widl/parser.tab.c"
    break;

  case 201: /* case: tCASE expr_int_const ':' union_field  */
#line 671 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4428 "tools/widl/parser.tab.c"
    break;

  case 202: /* case: tDEFAULT ':' union_field  */
#line 675 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4437 "tools/widl/parser.tab.c"
    break;

  case 203: /* enums: %empty  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4443 "tools/widl/parser.tab.c"
    break;

  case 204: /* enums: enum_list ','  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4449 "tools/widl/parser.tab.c"
    break;

  case 206: /* enum_list: enum  */
#line 686 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4458 "tools/widl/parser.tab.c"
    break;

  case 207: /* enum_list: enum_list ',' enum  */
#line 690 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
                                                  {
                                                    var_t *last = LIST_ENTRY( list_tail((yyval.var_list)), var_t, entry );
                                                    enum expr_type type = EXPR_NUM;
                                                    if (last->eval->type == EXPR_HEXNUM) type = EXPR_HEXNUM;
                                                    if (last->eval->cval + 1 < 0) type = EXPR_HEXNUM;
                                                    (yyvsp[0].var)->eval = make_exprl(type, last->eval->cval + 1);
                                                  }
                                                  (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) );
						}
#line 4473 "tools/widl/parser.tab.c"
    break;

  case 208: /* enum_member: m_attributes ident  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4481 "tools/widl/parser.tab.c"
    break;

  case 209: /* enum: enum_member '=' expr_int_const  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4490 "tools/widl/parser.tab.c"
    break;

  case 210: /* enum: enum_member  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4498 "tools/widl/parser.tab.c"
    break;

  case 211: /* enumdef: tENUM t_ident '{' enums '}'  */
#line 716 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4504 "tools/widl/parser.tab.c"
    break;

  case 212: /* m_exprs: m_expr  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4510 "tools/widl/parser.tab.c"
    break;

  case 213: /* m_exprs: m_exprs ',' m_expr  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4516 "tools/widl/parser.tab.c"
    break;

  case 214: /* m_expr: %empty  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4522 "tools/widl/parser.tab.c"
    break;

  case 216: /* expr: aNUM  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4528 "tools/widl/parser.tab.c"
    break;

  case 217: /* expr: aHEXNUM  */
#line 728 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4534 "tools/widl/parser.tab.c"
    break;

  case 218: /* expr: aDOUBLE  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4540 "tools/widl/parser.tab.c"
    break;

  case 219: /* expr: tFALSE  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4546 "tools/widl/parser.tab.c"
    break;

  case 220: /* expr: tNULL  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4552 "tools/widl/parser.tab.c"
    break;

  case 221: /* expr: tTRUE  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4558 "tools/widl/parser.tab.c"
    break;

  case 222: /* expr: aSTRING  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4564 "tools/widl/parser.tab.c"
    break;

  case 223: /* expr: aWSTRING  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4570 "tools/widl/parser.tab.c"
    break;

  case 224: /* expr: aSQSTRING  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4576 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: aIDENTIFIER  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4582 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: expr '?' expr ':' expr  */
#line 737 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4588 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: expr LOGICALOR expr  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4594 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: expr LOGICALAND expr  */
#line 739 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4600 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: expr '|' expr  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4606 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: expr '^' expr  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4612 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: expr '&' expr  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4618 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: expr EQUALITY expr  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: expr INEQUALITY expr  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4630 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: expr '>' expr  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4636 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '<' expr  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4642 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: expr GREATEREQUAL expr  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4648 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: expr LESSEQUAL expr  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4654 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: expr SHL expr  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4660 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: expr SHR expr  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4666 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: expr '+' expr  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4672 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: expr '-' expr  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4678 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr '%' expr  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4684 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr '*' expr  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4690 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr '/' expr  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4696 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: '!' expr  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4702 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: '~' expr  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4708 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: '+' expr  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4714 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: '-' expr  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4720 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: '&' expr  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4726 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: '*' expr  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4732 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4738 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '.' aIDENTIFIER  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4744 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 765 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4750 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr '[' expr ']'  */
#line 768 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4762 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: '(' expr ')'  */
#line 769 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4768 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr_list_int_const: expr_int_const  */
#line 772 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4774 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 773 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4780 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr_int_const: expr  */
#line 776 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4789 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr_const: expr  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4798 "tools/widl/parser.tab.c"
    break;

  case 261: /* fields: %empty  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4804 "tools/widl/parser.tab.c"
    break;

  case 262: /* fields: fields field  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4810 "tools/widl/parser.tab.c"
    break;

  case 263: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 793 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4819 "tools/widl/parser.tab.c"
    break;

  case 264: /* field: m_attributes uniondef ';'  */
#line 797 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4828 "tools/widl/parser.tab.c"
    break;

  case 265: /* ne_union_field: s_field ';'  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4834 "tools/widl/parser.tab.c"
    break;

  case 266: /* ne_union_field: attributes ';'  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4840 "tools/widl/parser.tab.c"
    break;

  case 267: /* ne_union_fields: %empty  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4846 "tools/widl/parser.tab.c"
    break;

  case 268: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4852 "tools/widl/parser.tab.c"
    break;

  case 269: /* union_field: s_field ';'  */
#line 813 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4858 "tools/widl/parser.tab.c"
    break;

  case 270: /* union_field: ';'  */
#line 814 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4864 "tools/widl/parser.tab.c"
    break;

  case 271: /* s_field: m_attributes decl_spec declarator  */
#line 817 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4873 "tools/widl/parser.tab.c"
    break;

  case 272: /* s_field: m_attributes structdef  */
#line 821 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4882 "tools/widl/parser.tab.c"
    break;

  case 273: /* funcdef: declaration  */
#line 827 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4892 "tools/widl/parser.tab.c"
    break;

  case 274: /* declaration: attributes decl_spec init_declarator  */
#line 836 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4900 "tools/widl/parser.tab.c"
    break;

  case 275: /* declaration: decl_spec init_declarator  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4908 "tools/widl/parser.tab.c"
    break;

  case 276: /* m_ident: %empty  */
#line 844 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4914 "tools/widl/parser.tab.c"
    break;

  case 278: /* t_ident: %empty  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 4920 "tools/widl/parser.tab.c"
    break;

  case 279: /* t_ident: aIDENTIFIER  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4926 "tools/widl/parser.tab.c"
    break;

  case 280: /* t_ident: aKNOWNTYPE  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4932 "tools/widl/parser.tab.c"
    break;

  case 281: /* ident: aIDENTIFIER  */
#line 853 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 282: /* ident: aKNOWNTYPE  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4944 "tools/widl/parser.tab.c"
    break;

  case 283: /* base_type: tBYTE  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4950 "tools/widl/parser.tab.c"
    break;

  case 284: /* base_type: tWCHAR  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4956 "tools/widl/parser.tab.c"
    break;

  case 286: /* base_type: tSIGNED int_std  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4962 "tools/widl/parser.tab.c"
    break;

  case 287: /* base_type: tUNSIGNED int_std  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4968 "tools/widl/parser.tab.c"
    break;

  case 288: /* base_type: tUNSIGNED  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4974 "tools/widl/parser.tab.c"
    break;

  case 289: /* base_type: tFLOAT  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4980 "tools/widl/parser.tab.c"
    break;

  case 290: /* base_type: tDOUBLE  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4986 "tools/widl/parser.tab.c"
    break;

  case 291: /* base_type: tBOOLEAN  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4992 "tools/widl/parser.tab.c"
    break;

  case 292: /* base_type: tERRORSTATUST  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4998 "tools/widl/parser.tab.c"
    break;

  case 293: /* base_type: tHANDLET  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 5004 "tools/widl/parser.tab.c"
    break;

  case 296: /* int_std: tINT  */
#line 875 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5010 "tools/widl/parser.tab.c"
    break;

  case 297: /* int_std: tSHORT m_int  */
#line 876 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5016 "tools/widl/parser.tab.c"
    break;

  case 298: /* int_std: tSMALL  */
#line 877 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5022 "tools/widl/parser.tab.c"
    break;

  case 299: /* int_std: tLONG m_int  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5028 "tools/widl/parser.tab.c"
    break;

  case 300: /* int_std: tHYPER m_int  */
#line 879 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5034 "tools/widl/parser.tab.c"
    break;

  case 301: /* int_std: tINT64  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5040 "tools/widl/parser.tab.c"
    break;

  case 302: /* int_std: tCHAR  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5046 "tools/widl/parser.tab.c"
    break;

  case 303: /* int_std: tINT32  */
#line 882 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5052 "tools/widl/parser.tab.c"
    break;

  case 304: /* int_std: tINT3264  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5058 "tools/widl/parser.tab.c"
    break;

  case 305: /* qualified_seq: aKNOWNTYPE  */
#line 887 "tools/widl/parser.y"
                      { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 5064 "tools/widl/parser.tab.c"
    break;

  case 306: /* $@3: %empty  */
#line 888 "tools/widl/parser.y"
                      { push_lookup_namespace((yyvsp[-1].str)); }
#line 5070 "tools/widl/parser.tab.c"
    break;

  case 307: /* qualified_seq: aIDENTIFIER '.' $@3 qualified_seq  */
#line 888 "tools/widl/parser.y"
                                                                   { (yyval.type) = (yyvsp[0].type); }
#line 5076 "tools/widl/parser.tab.c"
    break;

  case 308: /* qualified_type: aKNOWNTYPE  */
#line 892 "tools/widl/parser.y"
                     { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 5082 "tools/widl/parser.tab.c"
    break;

  case 309: /* $@4: %empty  */
#line 893 "tools/widl/parser.y"
                     { init_lookup_namespace((yyvsp[-1].str)); }
#line 5088 "tools/widl/parser.tab.c"
    break;

  case 310: /* qualified_type: aNAMESPACE '.' $@4 qualified_seq  */
#line 893 "tools/widl/parser.y"
                                                                  { (yyval.type) = (yyvsp[0].type); }
#line 5094 "tools/widl/parser.tab.c"
    break;

  case 311: /* coclass: tCOCLASS aIDENTIFIER  */
#line 896 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 5100 "tools/widl/parser.tab.c"
    break;

  case 312: /* coclass: tCOCLASS aKNOWNTYPE  */
#line 897 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 5111 "tools/widl/parser.tab.c"
    break;

  case 313: /* coclasshdr: attributes coclass  */
#line 905 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5120 "tools/widl/parser.tab.c"
    break;

  case 314: /* coclassdef: coclasshdr '{' class_interfaces '}' semicolon_opt  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 5126 "tools/widl/parser.tab.c"
    break;

  case 315: /* runtimeclass: tRUNTIMECLASS aIDENTIFIER  */
#line 916 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_runtimeclass((yyvsp[0].str), current_namespace); }
#line 5132 "tools/widl/parser.tab.c"
    break;

  case 316: /* runtimeclass: tRUNTIMECLASS aKNOWNTYPE  */
#line 917 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_RUNTIMECLASS)
						    error_loc("%s was not declared a runtimeclass at %s:%d\n", (yyvsp[0].str),
						              (yyval.type)->loc_info.input_name, (yyval.type)->loc_info.line_number);
						}
#line 5142 "tools/widl/parser.tab.c"
    break;

  case 317: /* runtimeclass_hdr: attributes runtimeclass  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_runtimeclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5151 "tools/widl/parser.tab.c"
    break;

  case 318: /* runtimeclass_def: runtimeclass_hdr '{' class_interfaces '}' semicolon_opt  */
#line 931 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 5157 "tools/widl/parser.tab.c"
    break;

  case 319: /* apicontract: attributes tAPICONTRACT aIDENTIFIER '{' '}'  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_APICONTRACT, (yyvsp[-2].str), current_namespace, 0);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_apicontract_attrs((yyval.type)->name, (yyvsp[-4].attr_list));
						}
#line 5166 "tools/widl/parser.tab.c"
    break;

  case 320: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5172 "tools/widl/parser.tab.c"
    break;

  case 321: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5178 "tools/widl/parser.tab.c"
    break;

  case 322: /* class_interfaces: %empty  */
#line 945 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5184 "tools/widl/parser.tab.c"
    break;

  case 323: /* class_interfaces: class_interfaces class_interface  */
#line 946 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5190 "tools/widl/parser.tab.c"
    break;

  case 324: /* class_interface: m_attributes interfacedec  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 5196 "tools/widl/parser.tab.c"
    break;

  case 325: /* dispinterface: tDISPINTERFACE aIDENTIFIER  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5202 "tools/widl/parser.tab.c"
    break;

  case 326: /* dispinterface: tDISPINTERFACE aKNOWNTYPE  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5208 "tools/widl/parser.tab.c"
    break;

  case 327: /* dispinterfacehdr: attributes dispinterface  */
#line 957 "tools/widl/parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 5220 "tools/widl/parser.tab.c"
    break;

  case 328: /* dispint_props: tPROPERTIES ':'  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5226 "tools/widl/parser.tab.c"
    break;

  case 329: /* dispint_props: dispint_props s_field ';'  */
#line 967 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5232 "tools/widl/parser.tab.c"
    break;

  case 330: /* dispint_meths: tMETHODS ':'  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5238 "tools/widl/parser.tab.c"
    break;

  case 331: /* dispint_meths: dispint_meths funcdef ';'  */
#line 971 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5244 "tools/widl/parser.tab.c"
    break;

  case 332: /* dispinterfacedef: dispinterfacehdr '{' dispint_props dispint_meths '}'  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 5252 "tools/widl/parser.tab.c"
    break;

  case 333: /* dispinterfacedef: dispinterfacehdr '{' interface ';' '}'  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 5260 "tools/widl/parser.tab.c"
    break;

  case 334: /* inherit: %empty  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5266 "tools/widl/parser.tab.c"
    break;

  case 335: /* inherit: ':' qualified_type  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5272 "tools/widl/parser.tab.c"
    break;

  case 336: /* interface: tINTERFACE aIDENTIFIER  */
#line 990 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5278 "tools/widl/parser.tab.c"
    break;

  case 337: /* interface: tINTERFACE aKNOWNTYPE  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5284 "tools/widl/parser.tab.c"
    break;

  case 338: /* interfacehdr: attributes interface  */
#line 994 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 5294 "tools/widl/parser.tab.c"
    break;

  case 339: /* interfacedef: interfacehdr inherit '{' int_statements '}' semicolon_opt  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5305 "tools/widl/parser.tab.c"
    break;

  case 340: /* interfacedef: interfacehdr ':' aIDENTIFIER '{' import int_statements '}' semicolon_opt  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 5313 "tools/widl/parser.tab.c"
    break;

  case 341: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1015 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5319 "tools/widl/parser.tab.c"
    break;

  case 342: /* interfacedec: interface ';'  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5325 "tools/widl/parser.tab.c"
    break;

  case 343: /* interfacedec: dispinterface ';'  */
#line 1020 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5331 "tools/widl/parser.tab.c"
    break;

  case 344: /* module: tMODULE aIDENTIFIER  */
#line 1023 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5337 "tools/widl/parser.tab.c"
    break;

  case 345: /* module: tMODULE aKNOWNTYPE  */
#line 1024 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5343 "tools/widl/parser.tab.c"
    break;

  case 346: /* modulehdr: attributes module  */
#line 1027 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5351 "tools/widl/parser.tab.c"
    break;

  case 347: /* moduledef: modulehdr '{' int_statements '}' semicolon_opt  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5359 "tools/widl/parser.tab.c"
    break;

  case 348: /* storage_cls_spec: tEXTERN  */
#line 1039 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5365 "tools/widl/parser.tab.c"
    break;

  case 349: /* storage_cls_spec: tSTATIC  */
#line 1040 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5371 "tools/widl/parser.tab.c"
    break;

  case 350: /* storage_cls_spec: tREGISTER  */
#line 1041 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5377 "tools/widl/parser.tab.c"
    break;

  case 351: /* function_specifier: tINLINE  */
#line 1045 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5383 "tools/widl/parser.tab.c"
    break;

  case 352: /* type_qualifier: tCONST  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5389 "tools/widl/parser.tab.c"
    break;

  case 353: /* m_type_qual_list: %empty  */
#line 1052 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5395 "tools/widl/parser.tab.c"
    break;

  case 354: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5401 "tools/widl/parser.tab.c"
    break;

  case 355: /* decl_spec: type m_decl_spec_no_type  */
#line 1056 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5407 "tools/widl/parser.tab.c"
    break;

  case 356: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1058 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5413 "tools/widl/parser.tab.c"
    break;

  case 357: /* m_decl_spec_no_type: %empty  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5419 "tools/widl/parser.tab.c"
    break;

  case 359: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1066 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5425 "tools/widl/parser.tab.c"
    break;

  case 360: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1067 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5431 "tools/widl/parser.tab.c"
    break;

  case 361: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1068 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5437 "tools/widl/parser.tab.c"
    break;

  case 362: /* declarator: '*' m_type_qual_list declarator  */
#line 1073 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5443 "tools/widl/parser.tab.c"
    break;

  case 363: /* declarator: callconv declarator  */
#line 1074 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5449 "tools/widl/parser.tab.c"
    break;

  case 365: /* direct_declarator: ident  */
#line 1079 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5455 "tools/widl/parser.tab.c"
    break;

  case 366: /* direct_declarator: '(' declarator ')'  */
#line 1080 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5461 "tools/widl/parser.tab.c"
    break;

  case 367: /* direct_declarator: direct_declarator array  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5467 "tools/widl/parser.tab.c"
    break;

  case 368: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1082 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5473 "tools/widl/parser.tab.c"
    break;

  case 369: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5479 "tools/widl/parser.tab.c"
    break;

  case 370: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1089 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5485 "tools/widl/parser.tab.c"
    break;

  case 372: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1096 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5491 "tools/widl/parser.tab.c"
    break;

  case 373: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1097 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5497 "tools/widl/parser.tab.c"
    break;

  case 374: /* m_abstract_declarator: %empty  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5503 "tools/widl/parser.tab.c"
    break;

  case 376: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1107 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5509 "tools/widl/parser.tab.c"
    break;

  case 377: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1108 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5515 "tools/widl/parser.tab.c"
    break;

  case 378: /* abstract_direct_declarator: array  */
#line 1109 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5521 "tools/widl/parser.tab.c"
    break;

  case 379: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1111 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5529 "tools/widl/parser.tab.c"
    break;

  case 380: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5537 "tools/widl/parser.tab.c"
    break;

  case 381: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5543 "tools/widl/parser.tab.c"
    break;

  case 382: /* any_declarator: callconv m_any_declarator  */
#line 1124 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5549 "tools/widl/parser.tab.c"
    break;

  case 384: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1131 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5555 "tools/widl/parser.tab.c"
    break;

  case 385: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1132 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5561 "tools/widl/parser.tab.c"
    break;

  case 386: /* m_any_declarator: %empty  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5567 "tools/widl/parser.tab.c"
    break;

  case 388: /* any_direct_declarator: ident  */
#line 1144 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5573 "tools/widl/parser.tab.c"
    break;

  case 389: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5579 "tools/widl/parser.tab.c"
    break;

  case 390: /* any_direct_declarator: any_direct_declarator array  */
#line 1146 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5585 "tools/widl/parser.tab.c"
    break;

  case 391: /* any_direct_declarator: array  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5591 "tools/widl/parser.tab.c"
    break;

  case 392: /* any_direct_declarator: '(' m_args ')'  */
#line 1149 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5599 "tools/widl/parser.tab.c"
    break;

  case 393: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5607 "tools/widl/parser.tab.c"
    break;

  case 394: /* declarator_list: declarator  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5613 "tools/widl/parser.tab.c"
    break;

  case 395: /* declarator_list: declarator_list ',' declarator  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5619 "tools/widl/parser.tab.c"
    break;

  case 396: /* m_bitfield: %empty  */
#line 1163 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5625 "tools/widl/parser.tab.c"
    break;

  case 397: /* m_bitfield: ':' expr_const  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5631 "tools/widl/parser.tab.c"
    break;

  case 398: /* struct_declarator: any_declarator m_bitfield  */
#line 1167 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5640 "tools/widl/parser.tab.c"
    break;

  case 399: /* struct_declarator_list: struct_declarator  */
#line 1174 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5646 "tools/widl/parser.tab.c"
    break;

  case 400: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5652 "tools/widl/parser.tab.c"
    break;

  case 401: /* init_declarator: declarator  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5658 "tools/widl/parser.tab.c"
    break;

  case 402: /* init_declarator: declarator '=' expr_const  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5664 "tools/widl/parser.tab.c"
    break;

  case 403: /* threading_type: tAPARTMENT  */
#line 1185 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5670 "tools/widl/parser.tab.c"
    break;

  case 404: /* threading_type: tNEUTRAL  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5676 "tools/widl/parser.tab.c"
    break;

  case 405: /* threading_type: tSINGLE  */
#line 1187 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5682 "tools/widl/parser.tab.c"
    break;

  case 406: /* threading_type: tFREE  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5688 "tools/widl/parser.tab.c"
    break;

  case 407: /* threading_type: tBOTH  */
#line 1189 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5694 "tools/widl/parser.tab.c"
    break;

  case 408: /* threading_type: tMTA  */
#line 1190 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5700 "tools/widl/parser.tab.c"
    break;

  case 409: /* pointer_type: tREF  */
#line 1194 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5706 "tools/widl/parser.tab.c"
    break;

  case 410: /* pointer_type: tUNIQUE  */
#line 1195 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5712 "tools/widl/parser.tab.c"
    break;

  case 411: /* pointer_type: tPTR  */
#line 1196 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5718 "tools/widl/parser.tab.c"
    break;

  case 412: /* structdef: tSTRUCT t_ident '{' fields '}'  */
#line 1199 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5724 "tools/widl/parser.tab.c"
    break;

  case 413: /* type: tVOID  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5730 "tools/widl/parser.tab.c"
    break;

  case 414: /* type: qualified_type  */
#line 1203 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5736 "tools/widl/parser.tab.c"
    break;

  case 415: /* type: base_type  */
#line 1204 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5742 "tools/widl/parser.tab.c"
    break;

  case 416: /* type: enumdef  */
#line 1205 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5748 "tools/widl/parser.tab.c"
    break;

  case 417: /* type: tENUM aIDENTIFIER  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5754 "tools/widl/parser.tab.c"
    break;

  case 418: /* type: structdef  */
#line 1207 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5760 "tools/widl/parser.tab.c"
    break;

  case 419: /* type: tSTRUCT aIDENTIFIER  */
#line 1208 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5766 "tools/widl/parser.tab.c"
    break;

  case 420: /* type: uniondef  */
#line 1209 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5772 "tools/widl/parser.tab.c"
    break;

  case 421: /* type: tUNION aIDENTIFIER  */
#line 1210 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5778 "tools/widl/parser.tab.c"
    break;

  case 422: /* type: tSAFEARRAY '(' type ')'  */
#line 1211 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5784 "tools/widl/parser.tab.c"
    break;

  case 423: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1215 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5793 "tools/widl/parser.tab.c"
    break;

  case 424: /* uniondef: tUNION t_ident '{' ne_union_fields '}'  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5799 "tools/widl/parser.tab.c"
    break;

  case 425: /* uniondef: tUNION t_ident tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1225 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5805 "tools/widl/parser.tab.c"
    break;

  case 426: /* version: aNUM  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5811 "tools/widl/parser.tab.c"
    break;

  case 427: /* version: aNUM '.' aNUM  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5817 "tools/widl/parser.tab.c"
    break;

  case 428: /* version: aHEXNUM  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5823 "tools/widl/parser.tab.c"
    break;

  case 433: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1246 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5831 "tools/widl/parser.tab.c"
    break;

  case 434: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1253 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5841 "tools/widl/parser.tab.c"
    break;

  case 435: /* acf_attributes: %empty  */
#line 1261 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5847 "tools/widl/parser.tab.c"
    break;

  case 436: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1262 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5853 "tools/widl/parser.tab.c"
    break;

  case 437: /* acf_attribute_list: acf_attribute  */
#line 1266 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5859 "tools/widl/parser.tab.c"
    break;

  case 438: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1267 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5865 "tools/widl/parser.tab.c"
    break;

  case 439: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1272 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5871 "tools/widl/parser.tab.c"
    break;

  case 440: /* acf_attribute: tENCODE  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5877 "tools/widl/parser.tab.c"
    break;

  case 441: /* acf_attribute: tDECODE  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5883 "tools/widl/parser.tab.c"
    break;

  case 442: /* acf_attribute: tEXPLICITHANDLE  */
#line 1275 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5889 "tools/widl/parser.tab.c"
    break;

  case 443: /* allocate_option_list: allocate_option  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5895 "tools/widl/parser.tab.c"
    break;

  case 444: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1281 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 5901 "tools/widl/parser.tab.c"
    break;

  case 445: /* allocate_option: tDONTFREE  */
#line 1285 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 5907 "tools/widl/parser.tab.c"
    break;

  case 446: /* allocate_option: tFREE  */
#line 1286 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5913 "tools/widl/parser.tab.c"
    break;

  case 447: /* allocate_option: tALLNODES  */
#line 1287 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 5919 "tools/widl/parser.tab.c"
    break;

  case 448: /* allocate_option: tSINGLENODE  */
#line 1288 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5925 "tools/widl/parser.tab.c"
    break;


#line 5929 "tools/widl/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1291 "tools/widl/parser.y"


static void decl_builtin_basic(const char *name, enum type_basic_type type)
{
  type_t *t = type_new_basic(type);
  reg_type(t, name, NULL, 0);
}

static void decl_builtin_alias(const char *name, type_t *t)
{
    const decl_spec_t ds = {.type = t};
    reg_type(type_new_alias(&ds, name), name, NULL, 0);
}

void init_types(void)
{
  decl_builtin_basic("byte", TYPE_BASIC_BYTE);
  decl_builtin_basic("wchar_t", TYPE_BASIC_WCHAR);
  decl_builtin_basic("float", TYPE_BASIC_FLOAT);
  decl_builtin_basic("double", TYPE_BASIC_DOUBLE);
  decl_builtin_basic("error_status_t", TYPE_BASIC_ERROR_STATUS_T);
  decl_builtin_basic("handle_t", TYPE_BASIC_HANDLE);
  decl_builtin_alias("boolean", type_new_basic(TYPE_BASIC_CHAR));
}

static str_list_t *append_str(str_list_t *list, char *str)
{
    struct str_list_entry_t *entry;

    if (!str) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->str = str;
    list_add_tail( list, &entry->entry );
    return list;
}

static attr_list_t *move_attr(attr_list_t *dst, attr_list_t *src, enum attr_type type)
{
  attr_t *attr;
  if (!src) return dst;
  LIST_FOR_EACH_ENTRY(attr, src, attr_t, entry)
    if (attr->type == type)
    {
      list_remove(&attr->entry);
      return append_attr(dst, attr);
    }
  return dst;
}

static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list)
{
  struct list *entry;

  if (!old_list) return new_list;

  while ((entry = list_head(old_list)))
  {
    attr_t *attr = LIST_ENTRY(entry, attr_t, entry);
    list_remove(entry);
    new_list = append_attr(new_list, attr);
  }
  return new_list;
}

typedef int (*map_attrs_filter_t)(attr_list_t*,const attr_t*);

static attr_list_t *map_attrs(const attr_list_t *list, map_attrs_filter_t filter)
{
  attr_list_t *new_list;
  const attr_t *attr;
  attr_t *new_attr;

  if (!list) return NULL;

  new_list = xmalloc( sizeof(*list) );
  list_init( new_list );
  LIST_FOR_EACH_ENTRY(attr, list, const attr_t, entry)
  {
    if (filter && !filter(new_list, attr)) continue;
    new_attr = xmalloc(sizeof(*new_attr));
    *new_attr = *attr;
    list_add_tail(new_list, &new_attr->entry);
  }
  return new_list;
}

static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier)
{
  decl_spec_t *declspec = left ? left : right;
  if (!declspec)
  {
    declspec = xmalloc(sizeof(*declspec));
    declspec->type = NULL;
    declspec->stgclass = STG_NONE;
    declspec->qualifier = 0;
    declspec->func_specifier = 0;
  }
  declspec->type = type;
  if (left && declspec != left)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = left->stgclass;
    else if (left->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= left->qualifier;
    declspec->func_specifier |= left->func_specifier;
    assert(!left->type);
    free(left);
  }
  if (right && declspec != right)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = right->stgclass;
    else if (right->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= right->qualifier;
    declspec->func_specifier |= right->func_specifier;
    assert(!right->type);
    free(right);
  }

  if (declspec->stgclass == STG_NONE)
    declspec->stgclass = stgclass;
  else if (stgclass != STG_NONE)
    error_loc("only one storage class can be specified\n");
  declspec->qualifier |= qual;
  declspec->func_specifier |= func_specifier;

  return declspec;
}

static attr_t *make_attr(enum attr_type type)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = 0;
  return a;
}

static attr_t *make_attrv(enum attr_type type, unsigned int val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = val;
  return a;
}

static attr_t *make_attrp(enum attr_type type, void *val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.pval = val;
  return a;
}

static attr_t *make_custom_attr(UUID *id, expr_t *pval)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  attr_custdata_t *cstdata = xmalloc(sizeof(attr_custdata_t));
  a->type = ATTR_CUSTOM;
  cstdata->id = *id;
  cstdata->pval = pval;
  a->u.pval = cstdata;
  return a;
}

static expr_list_t *append_expr(expr_list_t *list, expr_t *expr)
{
    if (!expr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &expr->entry );
    return list;
}

static void append_array(declarator_t *decl, expr_t *expr)
{
    type_t *array;

    if (!expr)
        return;

    /* An array is always a reference pointer unless explicitly marked otherwise
     * (regardless of what the default pointer attribute is). */
    array = type_new_array(NULL, NULL, FALSE, expr->is_const ? expr->cval : 0,
            expr->is_const ? NULL : expr, NULL);

    append_chain_type(decl, array, 0);
}

static struct list type_pool = LIST_INIT(type_pool);
typedef struct
{
  type_t data;
  struct list link;
} type_pool_node_t;

type_t *alloc_type(void)
{
  type_pool_node_t *node = xmalloc(sizeof *node);
  list_add_tail(&type_pool, &node->link);
  return &node->data;
}

void set_all_tfswrite(int val)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.tfswrite = val;
}

void clear_all_offsets(void)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.typestring_offset = node->data.ptrdesc = 0;
}

static void type_function_add_head_arg(type_t *type, var_t *arg)
{
    if (!type->details.function->args)
    {
        type->details.function->args = xmalloc( sizeof(*type->details.function->args) );
        list_init( type->details.function->args );
    }
    list_add_head( type->details.function->args, &arg->entry );
}

static int is_allowed_range_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_INT3264:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_WCHAR:
        case TYPE_BASIC_HYPER:
            return TRUE;
        case TYPE_BASIC_FLOAT:
        case TYPE_BASIC_DOUBLE:
        case TYPE_BASIC_ERROR_STATUS_T:
        case TYPE_BASIC_HANDLE:
            return FALSE;
        }
        return FALSE;
    default:
        return FALSE;
    }
}

static type_t *get_chain_ref(type_t *type)
{
    if (is_ptr(type))
        return type_pointer_get_ref_type(type);
    else if (is_array(type))
        return type_array_get_element_type(type);
    else if (is_func(type))
        return type_function_get_rettype(type);
    return NULL;
}

static type_t *get_chain_end(type_t *type)
{
    type_t *inner;
    while ((inner = get_chain_ref(type)))
        type = inner;
    return type;
}

static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual)
{
    type_t *chain_type;

    if (!decl->type)
    {
        decl->type = type;
        decl->qualifier = qual;
        return;
    }
    chain_type = get_chain_end(decl->type);

    if (is_ptr(chain_type))
    {
        chain_type->details.pointer.ref.type = type;
        chain_type->details.pointer.ref.qualifier = qual;
    }
    else if (is_array(chain_type))
    {
        chain_type->details.array.elem.type = type;
        chain_type->details.array.elem.qualifier = qual;
    }
    else if (is_func(chain_type))
    {
        chain_type->details.function->retval->declspec.type = type;
        chain_type->details.function->retval->declspec.qualifier = qual;
    }
    else
        assert(0);

    if (!is_func(chain_type))
        type->attrs = move_attr(type->attrs, chain_type->attrs, ATTR_CALLCONV);
}

static void append_chain_callconv(type_t *chain, char *callconv)
{
    type_t *chain_end;

    if (chain && (chain_end = get_chain_end(chain)))
        chain_end->attrs = append_attr(chain_end->attrs, make_attrp(ATTR_CALLCONV, callconv));
    else
        error_loc("calling convention applied to non-function type\n");
}

static warning_list_t *append_warning(warning_list_t *list, int num)
{
    warning_t *entry;

    if(!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->num = num;
    list_add_tail( list, &entry->entry );
    return list;
}

static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl,
                       int top)
{
  var_t *v = decl->var;
  expr_list_t *sizes = get_attrp(attrs, ATTR_SIZEIS);
  expr_list_t *lengs = get_attrp(attrs, ATTR_LENGTHIS);
  expr_t *dim;
  type_t **ptype;
  type_t *type = decl_spec->type;

  if (decl_spec->func_specifier & FUNCTION_SPECIFIER_INLINE)
  {
    if (!decl || !is_func(decl->type))
      error_loc("inline attribute applied to non-function type\n");
  }

  /* add type onto the end of the pointers in pident->type */
  append_chain_type(decl, type, decl_spec->qualifier);
  v->declspec = *decl_spec;
  v->declspec.type = decl->type;
  v->declspec.qualifier = decl->qualifier;
  v->attrs = attrs;
  v->declonly = !type->defined;

  if (is_attr(type->attrs, ATTR_CALLCONV) && !is_func(type))
    error_loc("calling convention applied to non-function type\n");

  /* check for pointer attribute being applied to non-pointer, non-array
   * type */
  if (!is_array(v->declspec.type))
  {
    int ptr_attr = get_attrv(v->attrs, ATTR_POINTERTYPE);
    const type_t *ptr = NULL;
    for (ptr = v->declspec.type; ptr && !ptr_attr; )
    {
      ptr_attr = get_attrv(ptr->attrs, ATTR_POINTERTYPE);
      if (!ptr_attr && type_is_alias(ptr))
        ptr = type_alias_get_aliasee_type(ptr);
      else
        break;
    }
    if (is_ptr(ptr))
    {
      if (ptr_attr && ptr_attr != FC_UP &&
          type_get_type(type_pointer_get_ref_type(ptr)) == TYPE_INTERFACE)
          warning_loc_info(&v->loc_info,
                           "%s: pointer attribute applied to interface "
                           "pointer type has no effect\n", v->name);
      if (!ptr_attr && top)
      {
        /* FIXME: this is a horrible hack to cope with the issue that we
         * store an offset to the typeformat string in the type object, but
         * two typeformat strings may be written depending on whether the
         * pointer is a toplevel parameter or not */
        v->declspec.type = duptype(v->declspec.type, 1);
      }
    }
    else if (ptr_attr)
       error_loc("%s: pointer attribute applied to non-pointer type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_STRING))
  {
    type_t *t = type;

    if (!is_ptr(v->declspec.type) && !is_array(v->declspec.type))
      error_loc("'%s': [string] attribute applied to non-pointer, non-array type\n",
                v->name);

    for (;;)
    {
        if (is_ptr(t))
            t = type_pointer_get_ref_type(t);
        else if (is_array(t))
            t = type_array_get_element_type(t);
        else
            break;
    }

    if (type_get_type(t) != TYPE_BASIC &&
        (get_basic_fc(t) != FC_CHAR &&
         get_basic_fc(t) != FC_BYTE &&
         get_basic_fc(t) != FC_WCHAR))
    {
      error_loc("'%s': [string] attribute is only valid on 'char', 'byte', or 'wchar_t' pointers and arrays\n",
                v->name);
    }
  }

  if (is_attr(v->attrs, ATTR_V1ENUM))
  {
    if (type_get_type_detect_alias(v->declspec.type) != TYPE_ENUM)
      error_loc("'%s': [v1_enum] attribute applied to non-enum type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_RANGE) && !is_allowed_range_type(v->declspec.type))
    error_loc("'%s': [range] attribute applied to non-integer type\n",
              v->name);

  ptype = &v->declspec.type;
  if (sizes) LIST_FOR_EACH_ENTRY(dim, sizes, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        if (!type_array_get_conformance(*ptype) ||
            type_array_get_conformance(*ptype)->type != EXPR_VOID)
          error_loc("%s: cannot specify size_is for an already sized array\n", v->name);
        else
          *ptype = type_new_array((*ptype)->name,
                                  type_array_get_element(*ptype), FALSE,
                                  0, dim, NULL);
      }
      else if (is_ptr(*ptype))
        *ptype = type_new_array((*ptype)->name, type_pointer_get_ref(*ptype), TRUE,
                                0, dim, NULL);
      else
        error_loc("%s: size_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in size_is attribute\n", v->name);
  }

  ptype = &v->declspec.type;
  if (lengs) LIST_FOR_EACH_ENTRY(dim, lengs, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        *ptype = type_new_array((*ptype)->name,
                                type_array_get_element(*ptype),
                                type_array_is_decl_as_ptr(*ptype),
                                type_array_get_dim(*ptype),
                                type_array_get_conformance(*ptype), dim);
      }
      else
        error_loc("%s: length_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in length_is attribute\n", v->name);
  }

  if (decl->bits)
    v->declspec.type = type_new_bitfield(v->declspec.type, decl->bits);

  return v;
}

static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls)
{
  declarator_t *decl, *next;
  var_list_t *var_list = NULL;

  LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
  {
    var_t *var = declare_var(attrs, decl_spec, decl, 0);
    var_list = append_var(var_list, var);
    free(decl);
  }
  free(decl_spec);
  return var_list;
}

static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface)
{
    if (!iface) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &iface->entry );
    return list;
}

static ifref_t *make_ifref(type_t *iface)
{
  ifref_t *l = xmalloc(sizeof(ifref_t));
  l->iface = iface;
  l->attrs = NULL;
  return l;
}

var_list_t *append_var(var_list_t *list, var_t *var)
{
    if (!var) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &var->entry );
    return list;
}

static var_list_t *append_var_list(var_list_t *list, var_list_t *vars)
{
    if (!vars) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_move_tail( list, vars );
    return list;
}

var_t *make_var(char *name)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  init_declspec(&v->declspec, NULL);
  v->attrs = NULL;
  v->eval = NULL;
  init_loc_info(&v->loc_info);
  v->declonly = FALSE;
  return v;
}

static var_t *copy_var(var_t *src, char *name, map_attrs_filter_t attr_filter)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  v->declspec = src->declspec;
  v->attrs = map_attrs(src->attrs, attr_filter);
  v->eval = src->eval;
  v->loc_info = src->loc_info;
  return v;
}

static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *d)
{
  if (!d) return list;
  if (!list) {
    list = xmalloc(sizeof(*list));
    list_init(list);
  }
  list_add_tail(list, &d->entry);
  return list;
}

static declarator_t *make_declarator(var_t *var)
{
  declarator_t *d = xmalloc(sizeof(*d));
  d->var = var ? var : make_var(NULL);
  d->type = NULL;
  d->qualifier = 0;
  d->bits = NULL;
  return d;
}

static type_t *make_safearray(type_t *type)
{
    decl_spec_t ds = {.type = type};
    ds.type = type_new_alias(&ds, "SAFEARRAY");
    return type_new_array(NULL, &ds, TRUE, 0, NULL, NULL);
}

static typelib_t *make_library(const char *name, const attr_list_t *attrs)
{
    typelib_t *typelib = xmalloc(sizeof(*typelib));
    memset(typelib, 0, sizeof(*typelib));
    typelib->name = xstrdup(name);
    typelib->attrs = attrs;
    list_init( &typelib->importlibs );
    return typelib;
}

static int hash_ident(const char *name)
{
  const char *p = name;
  int sum = 0;
  /* a simple sum hash is probably good enough */
  while (*p) {
    sum += *p;
    p++;
  }
  return sum & (HASHMAX-1);
}

/***** type repository *****/

static struct namespace *find_sub_namespace(struct namespace *namespace, const char *name)
{
  struct namespace *cur;

  LIST_FOR_EACH_ENTRY(cur, &namespace->children, struct namespace, entry) {
    if(!strcmp(cur->name, name))
      return cur;
  }

  return NULL;
}

static void push_namespace(const char *name)
{
  struct namespace *namespace;

  namespace = find_sub_namespace(current_namespace, name);
  if(!namespace) {
    namespace = xmalloc(sizeof(*namespace));
    namespace->name = xstrdup(name);
    namespace->parent = current_namespace;
    list_add_tail(&current_namespace->children, &namespace->entry);
    list_init(&namespace->children);
    memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
  }

  current_namespace = namespace;
}

static void pop_namespace(const char *name)
{
  assert(!strcmp(current_namespace->name, name) && current_namespace->parent);
  current_namespace = current_namespace->parent;
}

static void init_lookup_namespace(const char *name)
{
    if (!(lookup_namespace = find_sub_namespace(&global_namespace, name)))
        error_loc("namespace '%s' not found\n", name);
}

static void push_lookup_namespace(const char *name)
{
    struct namespace *namespace;
    if (!(namespace = find_sub_namespace(lookup_namespace, name)))
        error_loc("namespace '%s' not found\n", name);
    lookup_namespace = namespace;
}

struct rtype {
  const char *name;
  type_t *type;
  int t;
  struct rtype *next;
};

type_t *reg_type(type_t *type, const char *name, struct namespace *namespace, int t)
{
  struct rtype *nt;
  int hash;
  if (!name) {
    error_loc("registering named type without name\n");
    return type;
  }
  if (!namespace)
    namespace = &global_namespace;
  hash = hash_ident(name);
  nt = xmalloc(sizeof(struct rtype));
  nt->name = name;
  if (is_global_namespace(namespace))
    type->c_name = name;
  else
    type->c_name = format_namespace(namespace, "__x_", "_C", name, use_abi_namespace ? "ABI" : NULL);
  nt->type = type;
  nt->t = t;
  nt->next = namespace->type_hash[hash];
  namespace->type_hash[hash] = nt;
  return type;
}

static type_t *reg_typedefs(decl_spec_t *decl_spec, declarator_list_t *decls, attr_list_t *attrs)
{
  declarator_t *decl;
  type_t *type = decl_spec->type;

  if (is_attr(attrs, ATTR_UUID) && !is_attr(attrs, ATTR_PUBLIC))
    attrs = append_attr( attrs, make_attr(ATTR_PUBLIC) );

  /* We must generate names for tagless enum, struct or union.
     Typedef-ing a tagless enum, struct or union means we want the typedef
     to be included in a library hence the public attribute.  */
  if (type_get_type_detect_alias(type) == TYPE_ENUM ||
      type_get_type_detect_alias(type) == TYPE_STRUCT ||
      type_get_type_detect_alias(type) == TYPE_UNION ||
      type_get_type_detect_alias(type) == TYPE_ENCAPSULATED_UNION)
  {
    if (!type->name)
    {
      type->name = gen_name();
      if (!is_attr(attrs, ATTR_PUBLIC))
        attrs = append_attr(attrs, make_attr(ATTR_PUBLIC));
    }

    /* replace existing attributes when generating a typelib */
    if (do_typelib)
        type->attrs = attrs;
  }

  LIST_FOR_EACH_ENTRY( decl, decls, declarator_t, entry )
  {

    if (decl->var->name) {
      type_t *cur;
      var_t *name;

      cur = find_type(decl->var->name, current_namespace, 0);

      /*
       * MIDL allows shadowing types that are declared in imported files.
       * We don't throw an error in this case and instead add a new type
       * (which is earlier on the list in hash table, so it will be used
       * instead of shadowed type).
       *
       * FIXME: We may consider string separated type tables for each input
       *        for cleaner solution.
       */
      if (cur && input_name == cur->loc_info.input_name)
          error_loc("%s: redefinition error; original definition was at %s:%d\n",
                    cur->name, cur->loc_info.input_name,
                    cur->loc_info.line_number);

      name = declare_var(attrs, decl_spec, decl, 0);
      cur = type_new_alias(&name->declspec, name->name);
      cur->attrs = attrs;

      reg_type(cur, cur->name, current_namespace, 0);
    }
  }
  return type;
}

type_t *find_type(const char *name, struct namespace *namespace, int t)
{
  struct rtype *cur;

  if(namespace && namespace != &global_namespace) {
    for(cur = namespace->type_hash[hash_ident(name)]; cur; cur = cur->next) {
      if(cur->t == t && !strcmp(cur->name, name))
        return cur->type;
    }
  }
  for(cur = global_namespace.type_hash[hash_ident(name)]; cur; cur = cur->next) {
    if(cur->t == t && !strcmp(cur->name, name))
      return cur->type;
  }
  return NULL;
}

static type_t *find_type_or_error(const char *name, int t)
{
    type_t *type;
    if (!(type = find_type(name, current_namespace, t)) &&
        !(type = find_type(name, lookup_namespace, t)))
    {
        error_loc("type '%s' not found\n", name);
        return NULL;
    }
    return type;
}

static type_t *find_type_or_error2(char *name, int t)
{
  type_t *tp = find_type_or_error(name, t);
  free(name);
  return tp;
}

int is_type(const char *name)
{
    return find_type(name, current_namespace, 0) != NULL ||
           find_type(name, lookup_namespace, 0) != NULL;
}

int is_namespace(const char *name)
{
    if (!winrt_mode) return 0;
    return find_sub_namespace(current_namespace, name) != NULL ||
           find_sub_namespace(&global_namespace, name) != NULL;
}

type_t *get_type(enum type_type type, char *name, struct namespace *namespace, int t)
{
  type_t *tp;
  if (!namespace)
    namespace = &global_namespace;
  if (name) {
    tp = find_type(name, namespace, t);
    if (tp) {
      free(name);
      return tp;
    }
  }
  tp = make_type(type);
  tp->name = name;
  tp->namespace = namespace;
  if (!name) return tp;
  return reg_type(tp, name, namespace, t);
}

/***** constant repository *****/

struct rconst {
  char *name;
  var_t *var;
  struct rconst *next;
};

struct rconst *const_hash[HASHMAX];

static var_t *reg_const(var_t *var)
{
  struct rconst *nc;
  int hash;
  if (!var->name) {
    error_loc("registering constant without name\n");
    return var;
  }
  hash = hash_ident(var->name);
  nc = xmalloc(sizeof(struct rconst));
  nc->name = var->name;
  nc->var = var;
  nc->next = const_hash[hash];
  const_hash[hash] = nc;
  return var;
}

var_t *find_const(const char *name, int f)
{
  struct rconst *cur = const_hash[hash_ident(name)];
  while (cur && strcmp(cur->name, name))
    cur = cur->next;
  if (!cur) {
    if (f) error_loc("constant '%s' not found\n", name);
    return NULL;
  }
  return cur->var;
}

char *gen_name(void)
{
  static unsigned long n = 0;
  static const char *file_id;

  if (! file_id)
  {
    char *dst = dup_basename(input_idl_name, ".idl");
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';
  }
  return strmake("__WIDL_%s_generated_name_%08lX", file_id, n++);
}

struct allowed_attr
{
    unsigned int dce_compatible : 1;
    unsigned int acf : 1;
    unsigned int multiple : 1;

    unsigned int on_interface : 1;
    unsigned int on_function : 1;
    unsigned int on_arg : 1;
    unsigned int on_type : 1;
    unsigned int on_enum : 1;
    unsigned int on_enum_member : 1;
    unsigned int on_struct : 2;
    unsigned int on_union : 1;
    unsigned int on_field : 1;
    unsigned int on_library : 1;
    unsigned int on_dispinterface : 1;
    unsigned int on_module : 1;
    unsigned int on_coclass : 1;
    unsigned int on_apicontract : 1;
    unsigned int on_runtimeclass : 1;
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF M   I Fn ARG T En Enm St Un Fi L  DI M  C AC  R  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "aggregatable" },
    /* ATTR_ALLOCATE */            { 0, 1, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "allocate" },
    /* ATTR_ANNOTATION */          { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 0,  1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTRACT */            { 0, 0, 0,  1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, "contract" },
    /* ATTR_CONTRACTVERSION */     { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "contractversion" },
    /* ATTR_CONTROL */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, "control" },
    /* ATTR_CUSTOM */              { 0, 0, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, "custom" },
    /* ATTR_DECODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EXCLUSIVETO */         { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "exclusive_to" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MARSHALING_BEHAVIOR */ { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "marshaling_behavior" },
    /* ATTR_MAYBE */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0,  0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0,  0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0,  0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 0,  1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0,  0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

static attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
{
    attr_t *attr_existing;
    if (!attr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    if (!allowed_attr[attr->type].multiple)
    {
        LIST_FOR_EACH_ENTRY(attr_existing, list, attr_t, entry)
            if (attr_existing->type == attr->type)
            {
                parser_warning("duplicate attribute %s\n", get_attr_display_name(attr->type));
                /* use the last attribute, like MIDL does */
                list_remove(&attr_existing->entry);
                break;
            }
    }
    list_add_tail( list, &attr->entry );
    return list;
}

const char *get_attr_display_name(enum attr_type type)
{
    return allowed_attr[type].display_name;
}

static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_interface)
      error_loc("inapplicable attribute %s for interface %s\n",
                allowed_attr[attr->type].display_name, name);
    if (attr->type == ATTR_IMPLICIT_HANDLE)
    {
        const var_t *var = attr->u.pval;
        if (type_get_type( var->declspec.type) == TYPE_BASIC &&
            type_basic_get_type( var->declspec.type ) == TYPE_BASIC_HANDLE)
            continue;
        if (is_aliaschain_attr( var->declspec.type, ATTR_HANDLE ))
            continue;
      error_loc("attribute %s requires a handle type in interface %s\n",
                allowed_attr[attr->type].display_name, name);
    }
  }
  return attrs;
}

static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_function)
      error_loc("inapplicable attribute %s for function %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static void check_arg_attrs(const var_t *arg)
{
  const attr_t *attr;

  if (arg->attrs)
  {
    LIST_FOR_EACH_ENTRY(attr, arg->attrs, const attr_t, entry)
    {
      if (!allowed_attr[attr->type].on_arg)
        error_loc("inapplicable attribute %s for argument %s\n",
                  allowed_attr[attr->type].display_name, arg->name);
    }
  }
}

static attr_list_t *check_typedef_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_type)
      error_loc("inapplicable attribute %s for typedef\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum)
      error_loc("inapplicable attribute %s for enum\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_member_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum_member)
      error_loc("inapplicable attribute %s for enum member\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_struct_attrs(attr_list_t *attrs)
{
  int mask = winrt_mode ? 3 : 1;
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!(allowed_attr[attr->type].on_struct & mask))
      error_loc("inapplicable attribute %s for struct\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_union_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_union)
      error_loc("inapplicable attribute %s for union\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_field)
      error_loc("inapplicable attribute %s for field %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_library)
      error_loc("inapplicable attribute %s for library %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_dispinterface)
      error_loc("inapplicable attribute %s for dispinterface %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_module)
      error_loc("inapplicable attribute %s for module %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_coclass)
      error_loc("inapplicable attribute %s for coclass %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_runtimeclass)
            error_loc("inapplicable attribute %s for runtimeclass %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_apicontract)
            error_loc("inapplicable attribute %s for apicontract %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

static int is_allowed_conf_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_HYPER:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_WCHAR:
            return TRUE;
        default:
            return FALSE;
        }
    case TYPE_ALIAS:
        /* shouldn't get here because of type_get_type call above */
        assert(0);
        /* fall through */
    case TYPE_STRUCT:
    case TYPE_UNION:
    case TYPE_ENCAPSULATED_UNION:
    case TYPE_ARRAY:
    case TYPE_POINTER:
    case TYPE_VOID:
    case TYPE_MODULE:
    case TYPE_COCLASS:
    case TYPE_FUNCTION:
    case TYPE_INTERFACE:
    case TYPE_BITFIELD:
    case TYPE_RUNTIMECLASS:
        return FALSE;
    case TYPE_APICONTRACT:
        /* not supposed to be here */
        assert(0);
        break;
    }
    return FALSE;
}

static int is_ptr_guid_type(const type_t *type)
{
    /* first, make sure it is a pointer to something */
    if (!is_ptr(type)) return FALSE;

    /* second, make sure it is a pointer to something of size sizeof(GUID),
     * i.e. 16 bytes */
    return (type_memsize(type_pointer_get_ref_type(type)) == 16);
}

static void check_conformance_expr_list(const char *attr_name, const var_t *arg, const type_t *container_type, expr_list_t *expr_list)
{
    expr_t *dim;
    struct expr_loc expr_loc;
    expr_loc.v = arg;
    expr_loc.attr = attr_name;
    if (expr_list) LIST_FOR_EACH_ENTRY(dim, expr_list, expr_t, entry)
    {
        if (dim->type != EXPR_VOID)
        {
            const type_t *expr_type = expr_resolve_type(&expr_loc, container_type, dim);
            if (!is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               attr_name);
        }
    }
}

static void check_remoting_fields(const var_t *var, type_t *type);

/* checks that properties common to fields and arguments are consistent */
static void check_field_common(const type_t *container_type,
                               const char *container_name, const var_t *arg)
{
    type_t *type = arg->declspec.type;
    int more_to_do;
    const char *container_type_name;
    const char *var_type;

    switch (type_get_type(container_type))
    {
    case TYPE_STRUCT:
        container_type_name = "struct";
        var_type = "field";
        break;
    case TYPE_UNION:
        container_type_name = "union";
        var_type = "arm";
        break;
    case TYPE_ENCAPSULATED_UNION:
        container_type_name = "encapsulated union";
        var_type = "arm";
        break;
    case TYPE_FUNCTION:
        container_type_name = "function";
        var_type = "parameter";
        break;
    default:
        /* should be no other container types */
        assert(0);
        return;
    }

    if (is_attr(arg->attrs, ATTR_LENGTHIS) &&
        (is_attr(arg->attrs, ATTR_STRING) || is_aliaschain_attr(arg->declspec.type, ATTR_STRING)))
        error_loc_info(&arg->loc_info,
                       "string and length_is specified for argument %s are mutually exclusive attributes\n",
                       arg->name);

    if (is_attr(arg->attrs, ATTR_SIZEIS))
    {
        expr_list_t *size_is_exprs = get_attrp(arg->attrs, ATTR_SIZEIS);
        check_conformance_expr_list("size_is", arg, container_type, size_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_LENGTHIS))
    {
        expr_list_t *length_is_exprs = get_attrp(arg->attrs, ATTR_LENGTHIS);
        check_conformance_expr_list("length_is", arg, container_type, length_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_IIDIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_IIDIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "iid_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_ptr_guid_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to pointer to GUID type for attribute iid_is\n");
        }
    }
    if (is_attr(arg->attrs, ATTR_SWITCHIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_SWITCHIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "switch_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               expr_loc.attr);
        }
    }

    do
    {
        more_to_do = FALSE;

        switch (typegen_detect_type(type, arg->attrs, TDT_IGNORE_STRINGS))
        {
        case TGT_STRUCT:
        case TGT_UNION:
            check_remoting_fields(arg, type);
            break;
        case TGT_INVALID:
        {
            const char *reason = "is invalid";
            switch (type_get_type(type))
            {
            case TYPE_VOID:
                reason = "cannot derive from void *";
                break;
            case TYPE_FUNCTION:
                reason = "cannot be a function pointer";
                break;
            case TYPE_BITFIELD:
                reason = "cannot be a bit-field";
                break;
            case TYPE_COCLASS:
                reason = "cannot be a class";
                break;
            case TYPE_INTERFACE:
                reason = "cannot be a non-pointer to an interface";
                break;
            case TYPE_MODULE:
                reason = "cannot be a module";
                break;
            default:
                break;
            }
            error_loc_info(&arg->loc_info, "%s \'%s\' of %s \'%s\' %s\n",
                           var_type, arg->name, container_type_name, container_name, reason);
            break;
        }
        case TGT_CTXT_HANDLE:
        case TGT_CTXT_HANDLE_POINTER:
            if (type_get_type(container_type) != TYPE_FUNCTION)
                error_loc_info(&arg->loc_info,
                               "%s \'%s\' of %s \'%s\' cannot be a context handle\n",
                               var_type, arg->name, container_type_name,
                               container_name);
            break;
        case TGT_STRING:
        {
            const type_t *t = type;
            while (is_ptr(t))
                t = type_pointer_get_ref_type(t);
            if (is_aliaschain_attr(t, ATTR_RANGE))
                warning_loc_info(&arg->loc_info, "%s: range not verified for a string of ranged types\n", arg->name);
            break;
        }
        case TGT_POINTER:
            type = type_pointer_get_ref_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ARRAY:
            type = type_array_get_element_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ENUM:
            type = type_get_real_type(type);
            if (!type_is_complete(type))
            {
                error_loc_info(&arg->loc_info, "undefined type declaration \"enum %s\"\n", type->name);
            }
        case TGT_USER_TYPE:
        case TGT_IFACE_POINTER:
        case TGT_BASIC:
        case TGT_RANGE:
            /* nothing to do */
            break;
        }
    } while (more_to_do);
}

static void check_remoting_fields(const var_t *var, type_t *type)
{
    const var_t *field;
    const var_list_t *fields = NULL;

    type = type_get_real_type(type);

    if (type->checked)
        return;

    type->checked = TRUE;

    if (type_get_type(type) == TYPE_STRUCT)
    {
        if (type_is_complete(type))
            fields = type_struct_get_fields(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"struct %s\"\n", type->name);
    }
    else if (type_get_type(type) == TYPE_UNION || type_get_type(type) == TYPE_ENCAPSULATED_UNION)
    {
        if (type_is_complete(type))
            fields = type_union_get_cases(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"union %s\"\n", type->name);
    }

    if (fields) LIST_FOR_EACH_ENTRY( field, fields, const var_t, entry )
        if (field->declspec.type) check_field_common(type, type->name, field);
}

/* checks that arguments for a function make sense for marshalling and unmarshalling */
static void check_remoting_args(const var_t *func)
{
    const char *funcname = func->name;
    const var_t *arg;

    if (!type_function_get_args(func->declspec.type))
        return;

    LIST_FOR_EACH_ENTRY( arg, type_function_get_args(func->declspec.type), const var_t, entry )
    {
        const type_t *type = arg->declspec.type;

        /* check that [out] parameters have enough pointer levels */
        if (is_attr(arg->attrs, ATTR_OUT))
        {
            switch (typegen_detect_type(type, arg->attrs, TDT_ALL_TYPES))
            {
            case TGT_BASIC:
            case TGT_ENUM:
            case TGT_RANGE:
            case TGT_STRUCT:
            case TGT_UNION:
            case TGT_CTXT_HANDLE:
            case TGT_USER_TYPE:
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' is not a pointer\n", arg->name, funcname);
                break;
            case TGT_IFACE_POINTER:
                error_loc_info(&arg->loc_info, "out interface pointer \'%s\' of function \'%s\' is not a double pointer\n", arg->name, funcname);
                break;
            case TGT_STRING:
                if (is_array(type))
                {
                    /* needs conformance or fixed dimension */
                    if (type_array_has_conformance(type) &&
                        type_array_get_conformance(type)->type != EXPR_VOID) break;
                    if (!type_array_has_conformance(type) && type_array_get_dim(type)) break;
                }
                if (is_attr( arg->attrs, ATTR_IN )) break;
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' cannot be an unsized string\n", arg->name, funcname);
                break;
            case TGT_INVALID:
                /* already error'd before we get here */
            case TGT_CTXT_HANDLE_POINTER:
            case TGT_POINTER:
            case TGT_ARRAY:
                /* OK */
                break;
            }
        }

        check_field_common(func->declspec.type, funcname, arg);
    }

    if (type_get_type(type_function_get_rettype(func->declspec.type)) != TYPE_VOID)
    {
        var_t var;
        var = *func;
        var.declspec.type = type_function_get_rettype(func->declspec.type);
        var.name = xstrdup("return value");
        check_field_common(func->declspec.type, funcname, &var);
        free(var.name);
    }
}

static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func)
{
    unsigned char explicit_fc, implicit_fc;

    /* check for a defined binding handle */
    if (!get_func_handle_var( iface, func, &explicit_fc, &implicit_fc ) || !explicit_fc)
    {
        /* no explicit handle specified so add
         * "[in] handle_t IDL_handle" as the first parameter to the
         * function */
        var_t *idl_handle = make_var(xstrdup("IDL_handle"));
        idl_handle->attrs = append_attr(NULL, make_attr(ATTR_IN));
        idl_handle->declspec.type = find_type_or_error("handle_t", 0);
        type_function_add_head_arg(func->declspec.type, idl_handle);
    }
}

static void check_functions(const type_t *iface, int is_inside_library)
{
    const statement_t *stmt;
    /* check for duplicates */
    if (is_attr(iface->attrs, ATTR_DISPINTERFACE))
    {
        var_list_t *methods = type_dispiface_get_methods(iface);
        var_t *func, *func_iter;

        if (methods) LIST_FOR_EACH_ENTRY( func, methods, var_t, entry )
        {
            LIST_FOR_EACH_ENTRY( func_iter, methods, var_t, entry )
            {
                if (func == func_iter) break;
                if (strcmp(func->name, func_iter->name)) continue;
                if (is_attr(func->attrs, ATTR_PROPGET) != is_attr(func_iter->attrs, ATTR_PROPGET)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUT) != is_attr(func_iter->attrs, ATTR_PROPPUT)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUTREF) != is_attr(func_iter->attrs, ATTR_PROPPUTREF)) continue;
                error_loc_info(&func->loc_info, "duplicated function \'%s\'\n", func->name);
            }
        }
    }
    if (is_attr(iface->attrs, ATTR_EXPLICIT_HANDLE))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            var_t *func = stmt->u.var;
            add_explicit_handle_if_necessary(iface, func);
        }
    }
    if (!is_inside_library && !is_attr(iface->attrs, ATTR_LOCAL))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            const var_t *func = stmt->u.var;
            if (!is_attr(func->attrs, ATTR_LOCAL))
                check_remoting_args(func);
        }
    }
}

static int async_iface_attrs(attr_list_t *attrs, const attr_t *attr)
{
    switch(attr->type)
    {
    case ATTR_UUID:
        return 0;
    case ATTR_ASYNCUUID:
        append_attr(attrs, make_attrp(ATTR_UUID, attr->u.pval));
        return 0;
    default:
        return 1;
    }
}

static int arg_in_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_OUT && attr->type != ATTR_RETVAL;
}

static int arg_out_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_IN;
}

static void check_async_uuid(type_t *iface)
{
    statement_list_t *stmts = NULL;
    statement_t *stmt;
    type_t *async_iface;
    type_t *inherit;

    if (!is_attr(iface->attrs, ATTR_ASYNCUUID)) return;

    inherit = type_iface_get_inherit(iface);
    if (inherit && strcmp(inherit->name, "IUnknown"))
        inherit = type_iface_get_async_iface(inherit);
    if (!inherit)
        error_loc("async_uuid applied to an interface with incompatible parent\n");

    async_iface = get_type(TYPE_INTERFACE, strmake("Async%s", iface->name), iface->namespace, 0);
    async_iface->attrs = map_attrs(iface->attrs, async_iface_attrs);

    STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
    {
        var_t *begin_func, *finish_func, *func = stmt->u.var, *arg;
        var_list_t *begin_args = NULL, *finish_args = NULL, *args;

        if (is_attr(func->attrs, ATTR_CALLAS)) continue;

        args = type_function_get_args(func->declspec.type);
        if (args) LIST_FOR_EACH_ENTRY(arg, args, var_t, entry)
        {
            if (is_attr(arg->attrs, ATTR_IN) || !is_attr(arg->attrs, ATTR_OUT))
                begin_args = append_var(begin_args, copy_var(arg, strdup(arg->name), arg_in_attrs));
            if (is_attr(arg->attrs, ATTR_OUT))
                finish_args = append_var(finish_args, copy_var(arg, strdup(arg->name), arg_out_attrs));
        }

        begin_func = copy_var(func, strmake("Begin_%s", func->name), NULL);
        begin_func->declspec.type = type_new_function(begin_args);
        begin_func->declspec.type->attrs = func->attrs;
        begin_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(begin_func));

        finish_func = copy_var(func, strmake("Finish_%s", func->name), NULL);
        finish_func->declspec.type = type_new_function(finish_args);
        finish_func->declspec.type->attrs = func->attrs;
        finish_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(finish_func));
    }

    type_interface_define(async_iface, inherit, stmts);
    iface->details.iface->async_iface = async_iface->details.iface->async_iface = async_iface;
}

static void check_statements(const statement_list_t *stmts, int is_inside_library)
{
    const statement_t *stmt;

    if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
    {
        switch(stmt->type) {
        case STMT_LIBRARY:
            check_statements(stmt->u.lib->stmts, TRUE);
            break;
        case STMT_TYPE:
            switch(type_get_type(stmt->u.type)) {
            case TYPE_INTERFACE:
                check_functions(stmt->u.type, is_inside_library);
                break;
            case TYPE_COCLASS:
                if(winrt_mode)
                    error_loc("coclass is not allowed in Windows Runtime mode\n");
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

static void check_all_user_types(const statement_list_t *stmts)
{
  const statement_t *stmt;
  const var_t *v;

  if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
  {
    if (stmt->type == STMT_LIBRARY)
      check_all_user_types(stmt->u.lib->stmts);
    else if (stmt->type == STMT_TYPE && type_get_type(stmt->u.type) == TYPE_INTERFACE &&
             !is_local(stmt->u.type->attrs))
    {
      const statement_t *stmt_func;
      STATEMENTS_FOR_EACH_FUNC(stmt_func, type_iface_get_stmts(stmt->u.type)) {
        const var_t *func = stmt_func->u.var;
        if (type_function_get_args(func->declspec.type))
          LIST_FOR_EACH_ENTRY( v, type_function_get_args(func->declspec.type), const var_t, entry )
            check_for_additional_prototype_types(v->declspec.type);
        check_for_additional_prototype_types(type_function_get_rettype(func->declspec.type));
      }
    }
  }
}

int is_valid_uuid(const char *s)
{
  int i;

  for (i = 0; i < 36; ++i)
    if (i == 8 || i == 13 || i == 18 || i == 23)
    {
      if (s[i] != '-')
        return FALSE;
    }
    else
      if (!isxdigit(s[i]))
        return FALSE;

  return s[i] == '\0';
}

static statement_t *make_statement(enum statement_type type)
{
    statement_t *stmt = xmalloc(sizeof(*stmt));
    stmt->type = type;
    return stmt;
}

static statement_t *make_statement_type_decl(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type = type;
    stmt->declonly = !type->defined;
    return stmt;
}

static statement_t *make_statement_reference(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPEREF);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_declaration(var_t *var)
{
    statement_t *stmt = make_statement(STMT_DECLARATION);
    stmt->u.var = var;
    if (var->declspec.stgclass == STG_EXTERN && var->eval)
        warning("'%s' initialised and declared extern\n", var->name);
    if (is_const_decl(var))
    {
        if (var->eval)
            reg_const(var);
    }
    else if (type_get_type(var->declspec.type) == TYPE_FUNCTION)
        check_function_attrs(var->name, var->attrs);
    else if (var->declspec.stgclass == STG_NONE || var->declspec.stgclass == STG_REGISTER)
        error_loc("instantiation of data is illegal\n");
    return stmt;
}

static statement_t *make_statement_library(typelib_t *typelib)
{
    statement_t *stmt = make_statement(STMT_LIBRARY);
    stmt->u.lib = typelib;
    return stmt;
}

static statement_t *make_statement_pragma(const char *str)
{
    statement_t *stmt = make_statement(STMT_PRAGMA);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_cppquote(const char *str)
{
    statement_t *stmt = make_statement(STMT_CPPQUOTE);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_importlib(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORTLIB);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_import(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORT);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_module(type_t *type)
{
    statement_t *stmt = make_statement(STMT_MODULE);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_typedef(declarator_list_t *decls, int declonly)
{
    declarator_t *decl, *next;
    statement_t *stmt;
    type_list_t **type_list;

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    type_list = &stmt->u.type_list;
    stmt->declonly = declonly;

    LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
    {
        var_t *var = decl->var;
        type_t *type = find_type_or_error(var->name, 0);
        *type_list = xmalloc(sizeof(type_list_t));
        (*type_list)->type = type;
        (*type_list)->next = NULL;

        type_list = &(*type_list)->next;
        free(decl);
        free(var);
    }

    return stmt;
}

static statement_list_t *append_statements(statement_list_t *l1, statement_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static attr_list_t *append_attribs(attr_list_t *l1, attr_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt)
{
    if (!stmt) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &stmt->entry );
    return list;
}

void init_loc_info(loc_info_t *i)
{
    i->input_name = input_name ? input_name : "stdin";
    i->line_number = line_number;
    i->near_text = parser_text;
}

static void check_def(const type_t *t)
{
    if (t->defined)
        error_loc("%s: redefinition error; original definition was at %s:%d\n",
                  t->name, t->loc_info.input_name, t->loc_info.line_number);
}
