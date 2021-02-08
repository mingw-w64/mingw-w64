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
static type_t *find_type_or_error(struct namespace *parent, const char *name);
static struct namespace *find_namespace_or_error(struct namespace *namespace, const char *name);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);

static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_member_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
const char *get_attr_display_name(enum attr_type type);
static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func);

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

static typelib_t *current_typelib;


#line 204 "tools/widl/parser.tab.c"

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
    aNUM = 261,                    /* aNUM  */
    aHEXNUM = 262,                 /* aHEXNUM  */
    aDOUBLE = 263,                 /* aDOUBLE  */
    aSTRING = 264,                 /* aSTRING  */
    aWSTRING = 265,                /* aWSTRING  */
    aSQSTRING = 266,               /* aSQSTRING  */
    aUUID = 267,                   /* aUUID  */
    aEOF = 268,                    /* aEOF  */
    aACF = 269,                    /* aACF  */
    SHL = 270,                     /* SHL  */
    SHR = 271,                     /* SHR  */
    MEMBERPTR = 272,               /* MEMBERPTR  */
    EQUALITY = 273,                /* EQUALITY  */
    INEQUALITY = 274,              /* INEQUALITY  */
    GREATEREQUAL = 275,            /* GREATEREQUAL  */
    LESSEQUAL = 276,               /* LESSEQUAL  */
    LOGICALOR = 277,               /* LOGICALOR  */
    LOGICALAND = 278,              /* LOGICALAND  */
    ELLIPSIS = 279,                /* ELLIPSIS  */
    tAGGREGATABLE = 280,           /* tAGGREGATABLE  */
    tAGILE = 281,                  /* tAGILE  */
    tALLNODES = 282,               /* tALLNODES  */
    tALLOCATE = 283,               /* tALLOCATE  */
    tANNOTATION = 284,             /* tANNOTATION  */
    tAPICONTRACT = 285,            /* tAPICONTRACT  */
    tAPPOBJECT = 286,              /* tAPPOBJECT  */
    tASYNC = 287,                  /* tASYNC  */
    tASYNCUUID = 288,              /* tASYNCUUID  */
    tAUTOHANDLE = 289,             /* tAUTOHANDLE  */
    tBINDABLE = 290,               /* tBINDABLE  */
    tBOOLEAN = 291,                /* tBOOLEAN  */
    tBROADCAST = 292,              /* tBROADCAST  */
    tBYTE = 293,                   /* tBYTE  */
    tBYTECOUNT = 294,              /* tBYTECOUNT  */
    tCALLAS = 295,                 /* tCALLAS  */
    tCALLBACK = 296,               /* tCALLBACK  */
    tCASE = 297,                   /* tCASE  */
    tCDECL = 298,                  /* tCDECL  */
    tCHAR = 299,                   /* tCHAR  */
    tCOCLASS = 300,                /* tCOCLASS  */
    tCODE = 301,                   /* tCODE  */
    tCOMMSTATUS = 302,             /* tCOMMSTATUS  */
    tCONST = 303,                  /* tCONST  */
    tCONTEXTHANDLE = 304,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 305, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 306, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 307,               /* tCONTRACT  */
    tCONTRACTVERSION = 308,        /* tCONTRACTVERSION  */
    tCONTROL = 309,                /* tCONTROL  */
    tCPPQUOTE = 310,               /* tCPPQUOTE  */
    tCUSTOM = 311,                 /* tCUSTOM  */
    tDECODE = 312,                 /* tDECODE  */
    tDEFAULT = 313,                /* tDEFAULT  */
    tDEFAULTBIND = 314,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 315,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 316,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 317,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 318, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 319,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 320,          /* tDISPINTERFACE  */
    tDLLNAME = 321,                /* tDLLNAME  */
    tDONTFREE = 322,               /* tDONTFREE  */
    tDOUBLE = 323,                 /* tDOUBLE  */
    tDUAL = 324,                   /* tDUAL  */
    tENABLEALLOCATE = 325,         /* tENABLEALLOCATE  */
    tENCODE = 326,                 /* tENCODE  */
    tENDPOINT = 327,               /* tENDPOINT  */
    tENTRY = 328,                  /* tENTRY  */
    tENUM = 329,                   /* tENUM  */
    tERRORSTATUST = 330,           /* tERRORSTATUST  */
    tEVENTADD = 331,               /* tEVENTADD  */
    tEVENTREMOVE = 332,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 333,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 334,         /* tEXPLICITHANDLE  */
    tEXTERN = 335,                 /* tEXTERN  */
    tFALSE = 336,                  /* tFALSE  */
    tFASTCALL = 337,               /* tFASTCALL  */
    tFAULTSTATUS = 338,            /* tFAULTSTATUS  */
    tFLAGS = 339,                  /* tFLAGS  */
    tFLOAT = 340,                  /* tFLOAT  */
    tFORCEALLOCATE = 341,          /* tFORCEALLOCATE  */
    tHANDLE = 342,                 /* tHANDLE  */
    tHANDLET = 343,                /* tHANDLET  */
    tHELPCONTEXT = 344,            /* tHELPCONTEXT  */
    tHELPFILE = 345,               /* tHELPFILE  */
    tHELPSTRING = 346,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 347,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 348,          /* tHELPSTRINGDLL  */
    tHIDDEN = 349,                 /* tHIDDEN  */
    tHYPER = 350,                  /* tHYPER  */
    tID = 351,                     /* tID  */
    tIDEMPOTENT = 352,             /* tIDEMPOTENT  */
    tIGNORE = 353,                 /* tIGNORE  */
    tIIDIS = 354,                  /* tIIDIS  */
    tIMMEDIATEBIND = 355,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 356,         /* tIMPLICITHANDLE  */
    tIMPORT = 357,                 /* tIMPORT  */
    tIMPORTLIB = 358,              /* tIMPORTLIB  */
    tIN = 359,                     /* tIN  */
    tIN_LINE = 360,                /* tIN_LINE  */
    tINLINE = 361,                 /* tINLINE  */
    tINPUTSYNC = 362,              /* tINPUTSYNC  */
    tINT = 363,                    /* tINT  */
    tINT32 = 364,                  /* tINT32  */
    tINT3264 = 365,                /* tINT3264  */
    tINT64 = 366,                  /* tINT64  */
    tINTERFACE = 367,              /* tINTERFACE  */
    tLCID = 368,                   /* tLCID  */
    tLENGTHIS = 369,               /* tLENGTHIS  */
    tLIBRARY = 370,                /* tLIBRARY  */
    tLICENSED = 371,               /* tLICENSED  */
    tLOCAL = 372,                  /* tLOCAL  */
    tLONG = 373,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 374,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 375,                  /* tMAYBE  */
    tMESSAGE = 376,                /* tMESSAGE  */
    tMETHODS = 377,                /* tMETHODS  */
    tMODULE = 378,                 /* tMODULE  */
    tMTA = 379,                    /* tMTA  */
    tNAMESPACE = 380,              /* tNAMESPACE  */
    tNOCODE = 381,                 /* tNOCODE  */
    tNONBROWSABLE = 382,           /* tNONBROWSABLE  */
    tNONCREATABLE = 383,           /* tNONCREATABLE  */
    tNONE = 384,                   /* tNONE  */
    tNONEXTENSIBLE = 385,          /* tNONEXTENSIBLE  */
    tNOTIFY = 386,                 /* tNOTIFY  */
    tNOTIFYFLAG = 387,             /* tNOTIFYFLAG  */
    tNULL = 388,                   /* tNULL  */
    tOBJECT = 389,                 /* tOBJECT  */
    tODL = 390,                    /* tODL  */
    tOLEAUTOMATION = 391,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 392,               /* tOPTIMIZE  */
    tOPTIONAL = 393,               /* tOPTIONAL  */
    tOUT = 394,                    /* tOUT  */
    tPARTIALIGNORE = 395,          /* tPARTIALIGNORE  */
    tPASCAL = 396,                 /* tPASCAL  */
    tPOINTERDEFAULT = 397,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 398,         /* tPRAGMA_WARNING  */
    tPROGID = 399,                 /* tPROGID  */
    tPROPERTIES = 400,             /* tPROPERTIES  */
    tPROPGET = 401,                /* tPROPGET  */
    tPROPPUT = 402,                /* tPROPPUT  */
    tPROPPUTREF = 403,             /* tPROPPUTREF  */
    tPROXY = 404,                  /* tPROXY  */
    tPTR = 405,                    /* tPTR  */
    tPUBLIC = 406,                 /* tPUBLIC  */
    tRANGE = 407,                  /* tRANGE  */
    tREADONLY = 408,               /* tREADONLY  */
    tREF = 409,                    /* tREF  */
    tREGISTER = 410,               /* tREGISTER  */
    tREPRESENTAS = 411,            /* tREPRESENTAS  */
    tREQUESTEDIT = 412,            /* tREQUESTEDIT  */
    tRESTRICTED = 413,             /* tRESTRICTED  */
    tRETVAL = 414,                 /* tRETVAL  */
    tRUNTIMECLASS = 415,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 416,              /* tSAFEARRAY  */
    tSHORT = 417,                  /* tSHORT  */
    tSIGNED = 418,                 /* tSIGNED  */
    tSINGLENODE = 419,             /* tSINGLENODE  */
    tSIZEIS = 420,                 /* tSIZEIS  */
    tSIZEOF = 421,                 /* tSIZEOF  */
    tSMALL = 422,                  /* tSMALL  */
    tSOURCE = 423,                 /* tSOURCE  */
    tSTANDARD = 424,               /* tSTANDARD  */
    tSTATIC = 425,                 /* tSTATIC  */
    tSTDCALL = 426,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 427,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 428,                 /* tSTRING  */
    tSTRUCT = 429,                 /* tSTRUCT  */
    tSWITCH = 430,                 /* tSWITCH  */
    tSWITCHIS = 431,               /* tSWITCHIS  */
    tSWITCHTYPE = 432,             /* tSWITCHTYPE  */
    tTHREADING = 433,              /* tTHREADING  */
    tTRANSMITAS = 434,             /* tTRANSMITAS  */
    tTRUE = 435,                   /* tTRUE  */
    tTYPEDEF = 436,                /* tTYPEDEF  */
    tUIDEFAULT = 437,              /* tUIDEFAULT  */
    tUNION = 438,                  /* tUNION  */
    tUNIQUE = 439,                 /* tUNIQUE  */
    tUNSIGNED = 440,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 441,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 442,            /* tUSERMARSHAL  */
    tUUID = 443,                   /* tUUID  */
    tV1ENUM = 444,                 /* tV1ENUM  */
    tVARARG = 445,                 /* tVARARG  */
    tVERSION = 446,                /* tVERSION  */
    tVIPROGID = 447,               /* tVIPROGID  */
    tVOID = 448,                   /* tVOID  */
    tWCHAR = 449,                  /* tWCHAR  */
    tWIREMARSHAL = 450,            /* tWIREMARSHAL  */
    tAPARTMENT = 451,              /* tAPARTMENT  */
    tNEUTRAL = 452,                /* tNEUTRAL  */
    tSINGLE = 453,                 /* tSINGLE  */
    tFREE = 454,                   /* tFREE  */
    tBOTH = 455,                   /* tBOTH  */
    CAST = 456,                    /* CAST  */
    PPTR = 457,                    /* PPTR  */
    POS = 458,                     /* POS  */
    NEG = 459,                     /* NEG  */
    ADDRESSOF = 460                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 126 "tools/widl/parser.y"

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
	struct namespace *namespace;

#line 486 "tools/widl/parser.tab.c"

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
  YYSYMBOL_aNUM = 6,                       /* aNUM  */
  YYSYMBOL_aHEXNUM = 7,                    /* aHEXNUM  */
  YYSYMBOL_aDOUBLE = 8,                    /* aDOUBLE  */
  YYSYMBOL_aSTRING = 9,                    /* aSTRING  */
  YYSYMBOL_aWSTRING = 10,                  /* aWSTRING  */
  YYSYMBOL_aSQSTRING = 11,                 /* aSQSTRING  */
  YYSYMBOL_aUUID = 12,                     /* aUUID  */
  YYSYMBOL_aEOF = 13,                      /* aEOF  */
  YYSYMBOL_aACF = 14,                      /* aACF  */
  YYSYMBOL_SHL = 15,                       /* SHL  */
  YYSYMBOL_SHR = 16,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 17,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 18,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 19,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 20,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 21,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 22,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 23,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 24,                  /* ELLIPSIS  */
  YYSYMBOL_tAGGREGATABLE = 25,             /* tAGGREGATABLE  */
  YYSYMBOL_tAGILE = 26,                    /* tAGILE  */
  YYSYMBOL_tALLNODES = 27,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 28,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 29,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 30,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 31,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 32,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 33,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 34,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 35,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 36,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 37,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 38,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 39,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 40,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 41,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 42,                     /* tCASE  */
  YYSYMBOL_tCDECL = 43,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 44,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 45,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 46,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 47,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 48,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 49,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 50, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 51,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 52,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 53,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 54,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 55,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 56,                   /* tCUSTOM  */
  YYSYMBOL_tDECODE = 57,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 58,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 59,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 60,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 61,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 62,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 63,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 64,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 65,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 66,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 67,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 68,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 69,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 70,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 71,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 72,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 73,                    /* tENTRY  */
  YYSYMBOL_tENUM = 74,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 75,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 76,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 77,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 78,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 79,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 80,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 81,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 82,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 83,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 84,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 85,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 86,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 87,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 88,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 89,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 90,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 91,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 92,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 93,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 94,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 95,                    /* tHYPER  */
  YYSYMBOL_tID = 96,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 97,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 98,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 99,                    /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 100,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 101,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 102,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 103,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 104,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 105,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 106,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 107,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 108,                     /* tINT  */
  YYSYMBOL_tINT32 = 109,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 110,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 111,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 112,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 113,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 114,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 115,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 116,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 117,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 118,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 119,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 120,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 121,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 122,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 123,                  /* tMODULE  */
  YYSYMBOL_tMTA = 124,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 125,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 126,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 127,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 128,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 129,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 130,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 131,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 132,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 133,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 134,                  /* tOBJECT  */
  YYSYMBOL_tODL = 135,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 136,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 137,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 138,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 139,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 140,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 141,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 142,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 143,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 144,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 145,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 146,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 147,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 148,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 149,                   /* tPROXY  */
  YYSYMBOL_tPTR = 150,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 151,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 152,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 153,                /* tREADONLY  */
  YYSYMBOL_tREF = 154,                     /* tREF  */
  YYSYMBOL_tREGISTER = 155,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 156,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 157,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 158,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 159,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 160,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 161,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 162,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 163,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 164,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 165,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 166,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 167,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 168,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 169,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 170,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 171,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 172,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 173,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 174,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 175,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 176,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 177,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 178,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 179,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 180,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 181,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 182,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 183,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 184,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 185,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 186,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 187,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 188,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 189,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 190,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 191,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 192,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 193,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 194,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 195,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 196,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 197,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 198,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 199,                    /* tFREE  */
  YYSYMBOL_tBOTH = 200,                    /* tBOTH  */
  YYSYMBOL_201_ = 201,                     /* ','  */
  YYSYMBOL_202_ = 202,                     /* '?'  */
  YYSYMBOL_203_ = 203,                     /* ':'  */
  YYSYMBOL_204_ = 204,                     /* '|'  */
  YYSYMBOL_205_ = 205,                     /* '^'  */
  YYSYMBOL_206_ = 206,                     /* '&'  */
  YYSYMBOL_207_ = 207,                     /* '<'  */
  YYSYMBOL_208_ = 208,                     /* '>'  */
  YYSYMBOL_209_ = 209,                     /* '-'  */
  YYSYMBOL_210_ = 210,                     /* '+'  */
  YYSYMBOL_211_ = 211,                     /* '*'  */
  YYSYMBOL_212_ = 212,                     /* '/'  */
  YYSYMBOL_213_ = 213,                     /* '%'  */
  YYSYMBOL_214_ = 214,                     /* '!'  */
  YYSYMBOL_215_ = 215,                     /* '~'  */
  YYSYMBOL_CAST = 216,                     /* CAST  */
  YYSYMBOL_PPTR = 217,                     /* PPTR  */
  YYSYMBOL_POS = 218,                      /* POS  */
  YYSYMBOL_NEG = 219,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 220,                /* ADDRESSOF  */
  YYSYMBOL_221_ = 221,                     /* '.'  */
  YYSYMBOL_222_ = 222,                     /* '['  */
  YYSYMBOL_223_ = 223,                     /* ']'  */
  YYSYMBOL_224_ = 224,                     /* '{'  */
  YYSYMBOL_225_ = 225,                     /* '}'  */
  YYSYMBOL_226_ = 226,                     /* ';'  */
  YYSYMBOL_227_ = 227,                     /* '('  */
  YYSYMBOL_228_ = 228,                     /* ')'  */
  YYSYMBOL_229_ = 229,                     /* '='  */
  YYSYMBOL_YYACCEPT = 230,                 /* $accept  */
  YYSYMBOL_input = 231,                    /* input  */
  YYSYMBOL_m_acf = 232,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 233,           /* gbl_statements  */
  YYSYMBOL_234_1 = 234,                    /* $@1  */
  YYSYMBOL_imp_statements = 235,           /* imp_statements  */
  YYSYMBOL_236_2 = 236,                    /* $@2  */
  YYSYMBOL_int_statements = 237,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 238,            /* semicolon_opt  */
  YYSYMBOL_statement = 239,                /* statement  */
  YYSYMBOL_pragma_warning = 240,           /* pragma_warning  */
  YYSYMBOL_warnings = 241,                 /* warnings  */
  YYSYMBOL_typedecl = 242,                 /* typedecl  */
  YYSYMBOL_cppquote = 243,                 /* cppquote  */
  YYSYMBOL_import_start = 244,             /* import_start  */
  YYSYMBOL_import = 245,                   /* import  */
  YYSYMBOL_importlib = 246,                /* importlib  */
  YYSYMBOL_libraryhdr = 247,               /* libraryhdr  */
  YYSYMBOL_library_start = 248,            /* library_start  */
  YYSYMBOL_librarydef = 249,               /* librarydef  */
  YYSYMBOL_m_args = 250,                   /* m_args  */
  YYSYMBOL_arg_list = 251,                 /* arg_list  */
  YYSYMBOL_args = 252,                     /* args  */
  YYSYMBOL_arg = 253,                      /* arg  */
  YYSYMBOL_array = 254,                    /* array  */
  YYSYMBOL_m_attributes = 255,             /* m_attributes  */
  YYSYMBOL_attributes = 256,               /* attributes  */
  YYSYMBOL_attrib_list = 257,              /* attrib_list  */
  YYSYMBOL_str_list = 258,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 259,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 260,             /* contract_ver  */
  YYSYMBOL_contract_req = 261,             /* contract_req  */
  YYSYMBOL_attribute = 262,                /* attribute  */
  YYSYMBOL_uuid_string = 263,              /* uuid_string  */
  YYSYMBOL_callconv = 264,                 /* callconv  */
  YYSYMBOL_cases = 265,                    /* cases  */
  YYSYMBOL_case = 266,                     /* case  */
  YYSYMBOL_enums = 267,                    /* enums  */
  YYSYMBOL_enum_list = 268,                /* enum_list  */
  YYSYMBOL_enum_member = 269,              /* enum_member  */
  YYSYMBOL_enum = 270,                     /* enum  */
  YYSYMBOL_enumdef = 271,                  /* enumdef  */
  YYSYMBOL_m_exprs = 272,                  /* m_exprs  */
  YYSYMBOL_m_expr = 273,                   /* m_expr  */
  YYSYMBOL_expr = 274,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 275,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 276,           /* expr_int_const  */
  YYSYMBOL_expr_const = 277,               /* expr_const  */
  YYSYMBOL_fields = 278,                   /* fields  */
  YYSYMBOL_field = 279,                    /* field  */
  YYSYMBOL_ne_union_field = 280,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 281,          /* ne_union_fields  */
  YYSYMBOL_union_field = 282,              /* union_field  */
  YYSYMBOL_s_field = 283,                  /* s_field  */
  YYSYMBOL_funcdef = 284,                  /* funcdef  */
  YYSYMBOL_declaration = 285,              /* declaration  */
  YYSYMBOL_m_ident = 286,                  /* m_ident  */
  YYSYMBOL_m_typename = 287,               /* m_typename  */
  YYSYMBOL_typename = 288,                 /* typename  */
  YYSYMBOL_ident = 289,                    /* ident  */
  YYSYMBOL_base_type = 290,                /* base_type  */
  YYSYMBOL_m_int = 291,                    /* m_int  */
  YYSYMBOL_int_std = 292,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 293,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 294,           /* qualified_type  */
  YYSYMBOL_coclass = 295,                  /* coclass  */
  YYSYMBOL_coclassdef = 296,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 297,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 298,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 299,              /* apicontract  */
  YYSYMBOL_apicontract_def = 300,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 301,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 302,         /* class_interfaces  */
  YYSYMBOL_class_interface = 303,          /* class_interface  */
  YYSYMBOL_dispinterface = 304,            /* dispinterface  */
  YYSYMBOL_dispattributes = 305,           /* dispattributes  */
  YYSYMBOL_dispint_props = 306,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 307,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 308,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 309,                  /* inherit  */
  YYSYMBOL_interface = 310,                /* interface  */
  YYSYMBOL_interfacedef = 311,             /* interfacedef  */
  YYSYMBOL_interfaceref = 312,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 313,         /* dispinterfaceref  */
  YYSYMBOL_module = 314,                   /* module  */
  YYSYMBOL_moduledef = 315,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 316,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 317,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 318,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 319,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 320,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 321,    /* unqualified_decl_spec  */
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
  YYSYMBOL_unqualified_type = 342,         /* unqualified_type  */
  YYSYMBOL_type = 343,                     /* type  */
  YYSYMBOL_typedef = 344,                  /* typedef  */
  YYSYMBOL_uniondef = 345,                 /* uniondef  */
  YYSYMBOL_version = 346,                  /* version  */
  YYSYMBOL_acf_statements = 347,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 348,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 349,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 350,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 351,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 352,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 353,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 354,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 355           /* allocate_option  */
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
#define YYLAST   3446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  230
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  126
/* YYNRULES -- Number of rules.  */
#define YYNRULES  448
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  805

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   460


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
       2,     2,     2,   214,     2,     2,     2,   213,   206,     2,
     227,   228,   211,   210,   201,   209,   221,   212,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   203,   226,
     207,   229,   208,   202,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   222,     2,   223,   205,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   224,   204,   225,   215,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   216,   217,   218,   219,
     220
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   338,   338,   352,   352,   354,   355,   355,   357,   358,
     359,   360,   363,   366,   367,   369,   370,   372,   373,   374,
     377,   378,   379,   380,   380,   382,   383,   384,   387,   388,
     390,   391,   393,   394,   395,   396,   399,   400,   403,   404,
     408,   409,   410,   411,   412,   413,   414,   417,   428,   429,
     433,   434,   435,   436,   437,   438,   439,   440,   441,   444,
     446,   454,   460,   464,   466,   470,   474,   475,   478,   479,
     482,   483,   487,   492,   499,   503,   504,   507,   508,   512,
     515,   516,   517,   520,   521,   525,   526,   527,   531,   532,
     535,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,   574,   575,   576,   579,   580,   581,
     582,   583,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   595,   596,   597,   598,   599,   600,   601,
     602,   603,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,   620,   621,   622,
     623,   624,   625,   626,   627,   631,   632,   633,   634,   635,
     636,   637,   638,   639,   640,   641,   642,   643,   644,   645,
     646,   647,   648,   649,   650,   651,   652,   653,   654,   658,
     659,   664,   665,   666,   667,   670,   671,   674,   678,   684,
     685,   686,   689,   693,   705,   710,   714,   719,   722,   723,
     726,   727,   730,   731,   732,   733,   734,   735,   736,   737,
     738,   739,   740,   741,   742,   743,   744,   745,   746,   747,
     748,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,   766,   767,
     769,   771,   772,   775,   776,   779,   785,   791,   792,   795,
     800,   807,   808,   811,   812,   816,   817,   820,   824,   830,
     838,   842,   847,   848,   851,   852,   855,   856,   859,   862,
     863,   864,   865,   866,   867,   868,   869,   870,   871,   872,
     875,   876,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   891,   892,   896,   897,   900,   903,   907,   910,   914,
     917,   921,   924,   925,   929,   930,   933,   936,   939,   940,
     943,   944,   948,   950,   954,   955,   958,   961,   965,   969,
     970,   974,   977,   980,   985,   986,   987,   991,   995,   998,
     999,  1002,  1003,  1007,  1009,  1013,  1014,  1018,  1019,  1020,
    1024,  1026,  1027,  1031,  1032,  1033,  1034,  1039,  1041,  1042,
    1047,  1049,  1053,  1054,  1059,  1060,  1061,  1062,  1066,  1074,
    1076,  1077,  1082,  1084,  1088,  1089,  1096,  1097,  1098,  1099,
    1100,  1104,  1111,  1112,  1115,  1116,  1119,  1126,  1127,  1132,
    1133,  1137,  1138,  1139,  1140,  1141,  1142,  1146,  1147,  1148,
    1151,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1162,  1163,
    1164,  1168,  1169,  1172,  1179,  1181,  1187,  1188,  1189,  1193,
    1194,  1198,  1199,  1203,  1210,  1219,  1220,  1224,  1225,  1229,
    1231,  1232,  1233,  1237,  1238,  1243,  1244,  1245,  1246
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
  "aPRAGMA", "aKNOWNTYPE", "aNUM", "aHEXNUM", "aDOUBLE", "aSTRING",
  "aWSTRING", "aSQSTRING", "aUUID", "aEOF", "aACF", "SHL", "SHR",
  "MEMBERPTR", "EQUALITY", "INEQUALITY", "GREATEREQUAL", "LESSEQUAL",
  "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tAGGREGATABLE", "tAGILE",
  "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT", "tAPPOBJECT",
  "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN",
  "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE",
  "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE",
  "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEVENTADD", "tEVENTREMOVE", "tEXCLUSIVETO",
  "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL", "tFAULTSTATUS",
  "tFLAGS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE",
  "tMETHODS", "tMODULE", "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE",
  "tNONCREATABLE", "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG",
  "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL",
  "tOUT", "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT",
  "tPRAGMA_WARNING", "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT",
  "tPROPPUTREF", "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY",
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tRESTRICTED",
  "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT", "tSIGNED",
  "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTANDARD",
  "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT",
  "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS",
  "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED",
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
  "declaration", "m_ident", "m_typename", "typename", "ident", "base_type",
  "m_int", "int_std", "namespace_pfx", "qualified_type", "coclass",
  "coclassdef", "runtimeclass", "runtimeclass_def", "apicontract",
  "apicontract_def", "namespacedef", "class_interfaces", "class_interface",
  "dispinterface", "dispattributes", "dispint_props", "dispint_meths",
  "dispinterfacedef", "inherit", "interface", "interfacedef",
  "interfaceref", "dispinterfaceref", "module", "moduledef",
  "storage_cls_spec", "function_specifier", "type_qualifier",
  "m_type_qual_list", "decl_spec", "unqualified_decl_spec",
  "m_decl_spec_no_type", "decl_spec_no_type", "declarator",
  "direct_declarator", "abstract_declarator",
  "abstract_declarator_no_direct", "m_abstract_declarator",
  "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "unqualified_type", "type", "typedef",
  "uniondef", "version", "acf_statements", "acf_int_statements",
  "acf_int_statement", "acf_interface", "acf_attributes",
  "acf_attribute_list", "acf_attribute", "allocate_option_list",
  "allocate_option", YY_NULLPTR
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
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,    44,    63,    58,   124,    94,    38,    60,    62,    45,
      43,    42,    47,    37,    33,   126,   456,   457,   458,   459,
     460,    46,    91,    93,   123,   125,    59,    40,    41,    61
};
#endif

#define YYPACT_NINF (-583)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-436)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -583,   105,  1710,  -583,  -178,  -583,  -583,   -61,   184,  -583,
    -583,  -583,   184,  -583,  -115,   184,  -583,   202,  -583,  -583,
    -583,  -583,    52,   124,  -583,  -583,  -583,  -583,  -583,   184,
      52,   148,    -7,  -583,   184,    26,    52,   261,  -583,  -583,
     281,   320,   261,  -583,  -583,  3251,  -583,  -583,  -583,   -14,
    -583,  -583,  -583,  -583,  -583,    54,  2797,    40,    62,  -583,
    -583,   330,    66,  -583,    69,  -583,    85,  -583,    24,    89,
     195,    90,    96,  -583,  -583,    38,    38,    38,    91,  3000,
     100,  -583,    38,   103,   104,  -583,    59,  -583,   -61,   241,
    -583,  -583,  -583,  -583,   343,  -583,   112,   133,  -583,  -583,
    -583,   135,  -583,  -583,  -583,   362,  -583,  3000,  -583,  -583,
     113,   142,   -85,   -84,  -583,  -583,   146,  -583,  -583,   150,
    -583,  -583,  -583,   154,   156,  -583,  -583,  -583,  -583,  -583,
     158,   159,  -583,   161,  -583,  -583,  -583,  -583,   166,  -583,
    -583,  -583,   168,  -583,  -583,  -583,   173,   178,  -583,  -583,
     180,  -583,  -583,  -583,  -583,  -583,   181,   182,   185,   186,
     187,  -583,   197,  -583,  -583,   198,  -583,   199,  -583,  -583,
     200,   203,  -583,  -583,   205,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,   206,  -583,  -583,  -583,
     218,   221,  -583,  -583,  -583,  -583,  -583,  -583,   222,  -583,
    -583,   223,  -583,  -583,  -583,   226,  -583,  -583,  -583,   227,
     228,   229,   231,  -583,  -583,  -583,   232,   233,  -583,  -583,
     243,   244,   247,   -88,  -583,  -583,  -583,  1883,   958,   207,
     338,   184,   184,   339,   359,   255,   196,   258,   259,   260,
     282,   263,    91,   267,   270,  -583,   269,  -583,  -583,  -583,
    -583,  -583,  -583,   273,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,    91,    91,  -583,  -583,
     275,   -75,  -583,  -583,  -583,    38,  -583,  -583,  -583,   272,
    -583,  -583,  -583,   -77,  -583,  -583,   503,   283,   -50,  -583,
     306,   284,  -583,   286,  -583,   501,   171,   184,   825,  2888,
     509,   171,   825,   507,   513,   825,  2888,   825,   523,   524,
     825,   535,   825,   825,  2307,   825,   825,    48,   537,   -65,
     538,   825,  3000,   825,   825,  3000,   266,  3000,  3000,   171,
     264,   539,  3000,  3251,   296,  -583,   322,  -583,  -583,  -583,
     324,  -583,   325,  -583,   326,  -583,   331,   328,   332,  -583,
    -583,    90,  2888,  -583,   333,  -583,  -583,   333,   -76,  -583,
    -583,  -583,   334,   371,   336,  -583,  -583,  -583,  -583,   -17,
      63,   337,  -583,   825,   188,  2307,  -583,  -583,    55,    59,
    -583,   342,  -583,   184,   344,   360,   341,  -583,   556,  -583,
     -11,   207,    21,   340,  -583,  -583,   346,   348,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,   350,  -583,   825,
     825,   825,   825,   825,   825,   772,  2576,   -99,  -583,   351,
     366,   357,   352,   380,  2576,   354,   355,  -583,   -92,   356,
     364,   365,   367,   369,   370,   372,   373,  2341,   374,  2888,
      74,   375,   -91,  -583,  2576,  -583,  -583,  -583,   376,   378,
     379,   382,   386,   383,   -86,  2411,   387,  -583,  -583,  -583,
    -583,  -583,  -583,   388,   389,   390,   391,   399,  -583,   393,
     394,   395,  -583,  3251,   590,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,    91,    51,    53,    90,  -178,  -583,   330,  -583,
    -583,  1377,  1244,   405,   -51,   398,  -583,  -583,  -583,  -583,
     689,  -583,  2487,   397,   425,  -583,  -583,  -583,  -583,  -583,
    -583,   -78,  -583,  -583,   447,  -583,  -583,    57,   825,  -583,
      49,  -583,  2888,  -583,  2888,   401,  -583,   406,  -583,   408,
    -583,  -583,  -583,  3048,    43,    43,    43,    43,    43,    43,
    2436,   250,  3096,    38,   825,   825,   628,   825,   825,   825,
     825,   825,   825,   825,   825,   825,   825,   825,   825,   825,
     825,   825,   825,   825,   634,   825,   825,  -583,  -583,   509,
     638,  -583,   825,  -583,  -583,   637,  -583,  -583,  -583,  -583,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,    74,  -583,  1974,
    -583,    74,  -583,  -583,  -583,   -53,  -583,   825,  -583,  -583,
    -583,  -583,  -583,   825,  -583,  -583,  -583,  -583,  -583,  -583,
    -583,  -583,   642,  -583,  -583,  -583,  -583,   428,  -583,  -583,
     456,    90,     8,  -583,    90,  -583,  -583,  1498,    90,  -583,
    2888,  -583,  -583,   455,   433,  1589,   436,  -583,  -583,  -583,
    2216,    55,  -583,   440,   438,   447,  -583,  -583,  -583,  -583,
      74,   439,    91,   152,   184,  -583,  -583,   250,  -583,  -583,
    2095,  -583,   250,  -583,   441,   -43,    38,  -583,   230,   230,
    -583,   138,   138,   225,   225,   520,  2610,  2555,   952,   664,
    1629,   225,   225,    87,    87,    43,    43,    43,  -583,  2515,
    -583,  -583,  -583,   442,  -583,  -583,    45,  -583,   443,    74,
     444,  -583,  2307,  -583,  -583,   446,  -583,    90,  1101,    91,
    -583,   184,   371,   449,   450,  -583,    90,  -583,  -583,  -583,
    -583,  2888,   451,  -583,  -583,  -583,  -583,  -583,   659,  -583,
    -583,   464,  -583,  -101,  -583,  -583,   454,  -583,   458,   246,
    -583,   459,    74,   460,  -583,   825,  2307,  -583,  -583,   825,
    -583,  -583,  -583,    45,  -583,  -583,  -583,   461,  -583,  -583,
    -583,  -583,  -583,  -583,   330,  -583,  -583,  -583,  -583,   467,
     825,  -583,    74,  -583,  -583,  -583,  -583,    45,  -583,  -583,
    -583,    43,   462,  2576,  -583,  -583,  -583,  -583,  -583,  -583,
      56,  -583,  -583,   825,   465,  -583,  -583,   491,   -59,   -59,
    -583,  -583,   475,  -583,  -583
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,     0,    45,   420,   429,     0,   297,
     289,   308,     0,   348,     0,     0,   296,   284,   298,   344,
     295,   299,   300,     0,   347,   302,   309,   310,   307,     0,
     300,     0,     0,   346,     0,     0,   300,     0,   304,   345,
     284,   284,   294,   411,   290,    91,     2,    19,    46,     0,
      40,    20,    43,    20,    18,     0,    78,   413,     0,   412,
     291,     0,     0,    12,     0,    16,     0,    14,     0,     0,
       0,    38,     0,    10,    17,   355,   355,   355,     0,     0,
     415,   421,   355,     0,   417,   311,     0,     4,   429,     0,
     286,   287,   319,   315,     0,   326,   414,     0,   285,   301,
     306,     0,   336,   305,   321,     0,   317,     0,   303,   292,
     416,     0,   418,     0,   293,    92,     0,    94,    95,     0,
      96,    97,    98,     0,     0,   101,   102,   103,   104,   105,
       0,     0,   108,     0,   110,   111,   112,   113,     0,   115,
     116,   117,     0,   119,   120,   121,     0,     0,   124,   125,
       0,   127,   128,   129,   130,   131,     0,     0,     0,     0,
       0,   137,     0,   139,   140,     0,   142,     0,   144,   145,
     148,     0,   149,   150,     0,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,     0,   164,   165,   166,
       0,     0,   169,   170,   171,   172,   409,   173,     0,   175,
     407,     0,   177,   178,   179,     0,   181,   182,   183,     0,
       0,     0,     0,   188,   408,   189,     0,     0,   193,   194,
       0,     0,     0,     0,    80,   198,    41,    77,    77,    77,
     284,     0,     0,   284,   284,     0,   413,     0,     0,     0,
     334,     0,     0,   415,   417,    42,   286,   422,    11,    15,
      13,     6,     9,     0,    39,   338,     8,   359,   356,   358,
     357,   201,   202,   203,   204,   349,     0,     0,   288,   363,
     399,   362,   281,   413,   415,   355,   417,   351,    44,     0,
     441,   440,   442,     0,   437,   430,     0,     0,    77,    60,
       0,     0,   267,     0,   273,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    91,    79,    61,     0,    33,    34,    35,
       0,    27,     0,    31,     0,    29,     0,     0,     0,    25,
      32,    38,     0,    78,   414,    63,   342,   416,   418,    64,
     322,   322,     0,     0,     0,    36,   280,   312,     5,     0,
       0,     0,   361,     0,     0,    66,   365,   352,     0,     0,
     436,     0,    59,     0,     0,   211,   216,   212,     0,   419,
      77,    77,    77,     0,   200,   199,     0,     0,   231,   222,
     223,   224,   228,   229,   230,   225,   226,     0,   227,     0,
       0,     0,     0,     0,     0,     0,   265,     0,   263,     0,
       0,    88,     0,     0,   266,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     384,     0,     0,   218,   221,    85,    86,    87,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   406,   401,   402,
     403,   404,   405,     0,     0,     0,     0,   426,   428,     0,
       0,     0,    81,    91,     0,    26,    30,    28,    23,    22,
      21,    65,     0,    77,    77,    38,   286,   313,     0,   335,
      36,    77,    77,     0,    77,     0,   350,   360,   364,   400,
       0,    76,     0,     0,    70,    67,    68,   447,   445,   448,
     446,     0,   443,   438,   431,   214,   217,    77,     0,    48,
       0,   410,     0,   268,     0,     0,   424,    78,   274,     0,
      93,   192,    99,     0,   255,   254,   253,   256,   251,   252,
       0,   372,     0,   355,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   100,   106,     0,
       0,   107,     0,   114,   118,     0,   122,   123,   126,   132,
     133,   134,   135,   136,   138,   141,   143,   384,   349,    66,
     389,   384,   386,   385,    73,   381,   147,   220,   146,   151,
     163,   167,   168,     0,   176,   180,   184,   185,   187,   186,
     190,   191,     0,   195,   196,   197,    82,     0,    20,   392,
     423,    38,     0,   323,    38,   320,   314,    77,    38,    37,
      78,     7,   328,     0,     0,     0,     0,    75,    74,   366,
       0,     0,   439,   435,     0,   431,   213,   215,    49,    47,
       0,   417,     0,   415,   282,   272,   271,   372,   262,   349,
      66,   376,   372,   373,     0,   369,   355,   353,   244,   245,
     257,   238,   239,   242,   243,   233,   234,     0,   235,   236,
     237,   241,   240,   247,   246,   249,   250,   248,   258,     0,
     264,    90,    89,     0,    84,    72,   384,   349,     0,   384,
       0,   380,    66,   388,   219,     0,   427,    38,    77,     0,
     316,     0,     0,     0,     0,   318,    38,   343,   330,   329,
     332,     0,     0,   279,   333,    71,    69,   444,     0,   434,
     432,   394,   397,     0,   270,   277,     0,   283,     0,   372,
     349,     0,   384,     0,   368,     0,    66,   375,   354,     0,
     261,   109,   379,   384,   390,   383,   387,     0,   174,    62,
      24,   393,   341,   339,     0,   324,   325,   337,   331,     0,
       0,   396,     0,   269,   205,   260,   367,   384,   377,   371,
     374,   259,     0,   232,   382,   391,   340,   433,   395,   398,
       0,   370,   378,     0,     0,   425,   206,     0,    77,    77,
     276,   208,     0,   207,   275
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -583,  -583,  -583,   345,  -583,   -47,  -583,   215,  -297,    15,
    -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,  -583,    28,
    -517,  -583,  -583,  -273,  -261,  -226,     0,  -583,  -583,  -583,
     137,  -583,  -291,  -198,   -66,  -583,  -583,  -583,  -583,  -583,
     190,    11,   392,   115,   240,  -583,  -263,  -289,  -583,  -583,
    -583,  -583,   -90,  -284,  -583,    75,  -583,    16,    -8,   -64,
    -583,   132,    84,  -323,  -583,    22,    29,    25,    32,    27,
      33,    34,   353,  -583,     6,  -583,  -583,  -583,  -583,  -583,
      13,    36,  -583,  -583,  -583,    37,  -583,  -583,  -333,  -527,
     -55,   183,   -54,   -57,  -221,  -583,  -583,  -583,  -582,  -583,
    -580,  -583,  -490,  -583,  -583,  -583,   -52,  -583,   476,  -583,
     402,     3,  -352,   -15,  -583,     9,  -583,   635,    77,  -583,
    -583,    92,  -583,   358,  -583,    93
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    46,     2,   368,   227,   618,   491,   255,   337,
      48,   520,    49,    50,    51,    52,   338,   235,    53,   339,
     503,   504,   505,   506,   590,    55,   353,   223,   428,   448,
     422,   419,   224,   396,   591,   790,   796,   384,   385,   386,
     387,   273,   442,   443,   416,   417,   418,   425,   390,   523,
     528,   392,   801,   802,   722,    58,   736,    97,   268,   592,
      59,   100,    60,    61,   489,   340,   341,   342,   343,   344,
     345,   346,   483,   623,   347,    70,   494,   635,    71,   364,
     348,   349,   713,   714,   241,   350,    75,    76,    77,   370,
      78,   541,   257,    79,   270,   271,   663,   743,   664,   665,
     593,   700,   594,   595,   620,   771,   732,   733,   272,   463,
     225,   274,    81,    82,    83,   276,   469,    87,   644,   645,
      88,    89,   283,   284,   511,   512
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      92,   242,    56,   352,    93,    80,   228,    95,    69,    98,
     376,    84,   267,    57,   269,    72,   429,    47,   258,   258,
     258,   102,   259,   260,    62,   258,   106,    64,   277,    66,
      54,    63,    98,    98,    65,    67,    68,   496,    73,    74,
     488,   438,   472,    85,   431,   371,   372,   434,    90,   436,
      91,  -435,   441,   247,   481,   648,   111,   113,   452,   243,
     546,   696,   383,   543,   275,   244,    90,   236,    91,   240,
     731,   633,   698,   711,   445,   738,   253,    90,   237,    91,
     744,   238,   507,   239,   499,   196,    13,   279,   261,   200,
    -286,   293,   291,    13,    90,    29,    91,   695,   793,  -286,
     772,   701,   566,   423,   546,     3,   261,   525,   529,   575,
     597,    13,    94,   333,   794,   597,   280,   261,    19,   214,
     712,   109,   508,   641,   379,   773,   114,   262,   493,   567,
     281,   466,   739,   101,   261,   334,   576,   598,   282,  -286,
     294,   -55,   605,   741,    24,   262,   380,   374,  -286,   497,
     642,   104,   375,   544,   545,   546,   262,   776,   549,   550,
      99,    86,   103,    45,   522,   524,   524,   800,   108,   374,
     753,    45,    45,   262,   702,  -209,   267,   446,   269,   374,
     394,   543,   616,   395,   746,   757,   263,    90,   625,    91,
     666,   398,   731,    33,   399,   400,   401,   402,   403,   404,
     267,   267,   269,   269,   263,    96,   752,    91,    39,   755,
     634,    45,   226,   777,   521,   263,   264,   447,   258,   509,
     105,   377,    98,   355,   356,    98,    98,    56,    56,   782,
      80,    80,   263,   397,   264,   229,    84,    84,    57,    57,
     544,   545,   546,    45,   420,   264,   526,   546,   251,   111,
     113,   430,   779,   107,   510,   647,   588,   622,   622,   440,
      15,   619,   264,   784,   564,   565,   -50,   374,   524,   405,
     467,   468,   589,    45,   265,    45,   621,   649,   624,    45,
     661,   795,  -210,   693,   110,   588,    91,   791,   245,   261,
     266,   383,   248,   261,    13,   249,   374,   482,   561,   562,
     563,   589,   265,   690,   267,    11,   269,   453,   564,   565,
     456,   250,   464,   465,   439,   252,   254,   471,   266,   515,
     440,   406,   256,   112,   710,    91,   -52,   715,   262,   278,
     -54,   717,   262,   246,   703,    91,  -286,  -286,   -51,   -53,
     705,   354,   357,    91,    91,   557,   558,   559,   560,   561,
     562,   563,   287,   286,   407,   487,    22,   288,   542,   564,
     565,   289,   358,   496,    91,   290,   292,   726,   408,    25,
      26,    27,    28,   295,   486,   439,    91,   296,  -278,    30,
    -278,   297,   495,   298,   587,   299,   300,   263,   301,   764,
     457,   263,   527,   302,   409,   303,   661,   410,   411,   500,
     304,   661,   413,   414,   747,   305,   496,   306,   307,   308,
     759,   501,   309,   310,   311,   415,   267,   264,   269,   767,
     496,   264,   -56,    36,   312,   313,   314,   315,    38,    45,
     316,   735,   317,   318,   559,   560,   561,   562,   563,   559,
     560,   561,   562,   563,   496,   319,   564,   565,   320,   321,
     322,   564,   565,   323,   324,   325,   326,   659,   327,   328,
     329,   659,   458,   459,   460,   461,   462,   650,   374,   652,
     330,   331,   374,   660,   332,   662,   542,   660,   661,   359,
     626,   788,   360,   361,   362,   363,   258,   365,   761,   667,
     367,   630,    56,   -57,    80,    80,   -58,   369,    69,   378,
      84,    84,    57,    57,   373,    72,   629,    47,   381,   388,
     393,   382,   389,   391,    62,   421,   426,    64,   473,    66,
      54,    63,   427,   699,    65,    67,    68,   653,    73,    74,
     797,   651,   432,   433,   440,   544,   545,   546,   547,   548,
     549,   550,   424,   552,   435,   424,   449,   451,   470,   474,
     475,   476,   477,   437,   479,   478,   444,  -286,   480,   485,
     490,   517,   519,   444,   455,   498,   514,   569,   530,   516,
     518,   708,   524,   524,   531,   242,   532,   533,   570,   568,
     571,   572,   573,   574,   577,   440,   267,   603,   269,   439,
     737,   662,   578,   579,   742,   580,   662,   581,   582,   617,
     583,   584,   586,   596,   599,   440,   600,   601,   632,   258,
     602,   604,   748,   424,   502,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   636,   639,   640,   630,   643,   654,
      80,   670,   655,   243,   656,   721,    84,   688,    57,   244,
     439,   236,   629,   267,   692,   269,   694,   440,   706,   534,
     535,   536,   537,   538,   539,   540,   707,   709,   718,   719,
     439,   724,    86,   729,   769,   734,   242,   770,   798,   745,
     751,   754,   756,   662,   758,   765,   766,   768,   774,   544,
     545,   546,   547,   548,   549,   550,   775,   778,   780,   785,
     792,   440,   398,   787,   799,   399,   400,   401,   402,   403,
     404,   804,   439,   762,   763,   627,   691,   646,    56,   803,
     723,    80,   704,   492,   484,   454,   657,    84,   366,    57,
     789,   450,   730,   285,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   727,   728,     0,   513,     0,     0,
     537,   564,   565,     0,     0,     0,   439,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   786,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     405,     0,     0,     0,     0,   398,     0,     6,   399,   400,
     401,   402,   403,   404,   668,   669,     0,   671,   672,   673,
     674,   675,   676,   677,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,     0,   689,     0,     0,     9,     0,
      10,     0,   424,     0,     0,     0,    11,     0,     0,     0,
      13,     0,   406,     0,     0,     0,     0,     0,   398,     0,
       0,   399,   400,   401,   402,   403,   404,   444,     0,     0,
      16,     0,     0,     0,     0,     0,   230,    18,     0,     0,
       0,     0,    19,   405,     0,   407,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    22,     0,   408,
     556,   557,   558,   559,   560,   561,   562,   563,    24,     0,
      25,    26,    27,    28,     0,   564,   565,     0,     0,     0,
      30,     0,     0,     0,     0,   409,     0,     0,   410,   411,
     412,     0,     0,   413,   414,   406,   405,     0,     0,     0,
       0,     0,   637,     0,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,    35,    36,    37,     0,     0,   407,    38,
       0,     0,    39,     0,     0,     0,   233,     0,     0,     0,
       0,     0,   408,     0,     0,   234,     0,    42,   406,     0,
       0,     4,     5,     6,     0,    43,    44,   544,   545,   546,
     547,   548,   549,   550,     0,     0,     0,     0,   409,     0,
       0,   410,   411,   412,     0,   781,   413,   414,     8,   783,
       0,   407,     0,     0,     9,     0,    10,     0,     0,   415,
       0,     0,    11,    12,     0,   408,    13,     0,     0,     0,
     424,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,     0,     0,    16,     0,     0,     0,
       0,   409,    17,    18,   410,   411,   412,     0,    19,   413,
     414,     0,     0,    20,     0,     0,    21,     0,     0,     0,
       0,     0,   415,    22,     0,     0,     0,     0,     0,     0,
      23,   336,     0,     0,    24,     0,    25,    26,    27,    28,
      29,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     4,     5,     6,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,    34,    35,
      36,    37,     0,     0,     0,    38,     0,     0,    39,     0,
       0,     8,    40,     0,     0,     0,     0,     9,     0,    10,
       0,    41,     0,    42,     0,    11,    12,     0,     0,    13,
       0,    43,    44,     0,     0,     0,    14,   555,   556,   557,
     558,   559,   560,   561,   562,   563,    15,     0,     0,    16,
       0,     0,     0,   564,   565,    17,    18,     0,     0,     0,
      45,    19,     0,   351,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,   336,     0,     0,    24,     0,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     4,     5,     6,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,    39,     0,     0,     8,    40,     0,     0,     0,     0,
       9,     0,    10,     0,    41,     0,    42,     0,    11,    12,
       0,     0,    13,     0,    43,    44,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,    16,     0,     0,     0,     0,     0,    17,    18,
       0,     0,     0,    45,    19,     0,   760,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      24,     0,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     9,    39,    10,     0,     0,    40,     0,
       0,    11,     0,     0,     0,    13,     0,    41,     0,    42,
       0,     0,    14,     0,     0,     0,     0,    43,    44,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,     0,     0,    21,    45,     0,     0,   631,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    24,     0,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     9,     0,    10,     0,    35,    36,
      37,     0,    11,     0,    38,     0,    13,    39,     0,     0,
       0,    40,     0,    14,     0,     0,     0,     0,     0,     0,
      41,     0,    42,     0,     0,     0,    16,     0,     0,     0,
      43,    44,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     4,    22,     6,     0,     0,     0,     0,    45,
      23,     0,   628,     0,    24,     0,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,     0,    11,     0,     0,     0,    13,     0,     0,
       0,    32,     0,     0,   544,   545,   546,   547,   548,   549,
     550,     0,     0,    33,     0,     0,     0,    16,     0,    35,
      36,    37,     0,   230,    18,    38,     0,     0,    39,    19,
       0,     0,    40,     0,    20,     0,     0,    21,     0,     0,
       0,    41,     0,    42,    22,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,    24,     0,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     4,     5,     6,     0,     0,     0,     0,
      45,     0,     0,   716,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,    33,     0,     9,     0,    10,     0,
      35,    36,    37,     0,    11,    12,    38,     0,    13,    39,
       0,     0,     0,   233,     0,    14,     0,     0,     0,     0,
       0,     0,   234,     0,    42,    15,     0,     0,    16,     0,
       0,     0,    43,    44,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,    45,    23,     0,   720,     0,    24,     0,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    31,   557,   558,   559,   560,
     561,   562,   563,     0,     0,     0,     0,     0,     0,     0,
     564,   565,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
      34,    35,    36,    37,     0,     0,     0,    38,     0,     0,
      39,     0,     0,     0,    40,     0,     4,     5,     6,     0,
       0,   -77,     0,    41,     0,    42,   335,     0,     0,     0,
       0,     0,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     9,
       0,    10,     0,     0,     0,     0,     0,    11,    12,     0,
       0,    13,    45,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,     0,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,     0,
       0,    21,     0,     0,     0,     0,     0,     4,    22,     6,
       0,     0,     0,     0,     0,    23,   336,     0,     0,    24,
       0,    25,    26,    27,    28,    29,     0,     0,     0,     0,
       0,    30,     0,     0,     0,     0,     0,     0,    31,     0,
       9,     0,    10,     0,     0,     0,     0,   261,    11,     0,
       0,     0,    13,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,    16,    34,    35,    36,    37,     0,   230,    18,
      38,     0,     0,    39,    19,     0,   262,    40,     0,    20,
       0,     0,    21,     0,     0,     0,    41,     0,    42,    22,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     4,     0,
       6,     0,     0,     0,     0,    45,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   263,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     9,     0,    10,     0,    35,    36,    37,   261,    11,
       0,    38,     0,    13,    39,   264,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,   234,     0,    42,
       0,     0,     0,    16,     0,     0,     0,    43,    44,   230,
      18,     0,     0,     0,     0,    19,     0,   262,     0,     0,
      20,     0,     0,    21,     0,   697,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,    45,     0,     0,     0,
       0,    24,     0,    25,    26,    27,    28,     0,     0,     0,
       0,     0,     0,    30,     0,     0,     0,     0,     0,     4,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   263,     0,     0,     0,
     725,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     9,     0,    10,     0,    35,    36,    37,     0,
      11,     0,    38,     0,    13,    39,   264,     0,     0,   233,
       0,     0,     0,     0,     0,     0,     0,     0,   234,     0,
      42,     0,     0,     0,    16,     0,     0,     0,    43,    44,
     230,    18,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    20,     0,     0,    21,     0,   740,     0,     0,     0,
       4,    22,     6,     0,     0,     0,     0,    45,     0,     0,
       0,     0,    24,     0,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,     0,
       0,    11,     0,     0,     0,    13,   544,   545,   546,   547,
     548,   549,   550,   551,   552,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     0,    16,     0,    35,    36,    37,
       0,   230,    18,    38,     0,     0,    39,    19,     0,     0,
     233,     0,    20,     0,     0,    21,     0,     0,     0,   234,
       0,    42,    22,     0,     0,     0,     0,     0,     0,    43,
      44,     0,     0,    24,     0,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    30,   544,   545,   546,   547,
     548,   549,   550,   551,   552,     0,     0,     0,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,   545,   546,   547,   548,   549,   550,   551,   552,
       0,     0,    33,     0,     0,     0,     0,     0,    35,    36,
      37,     0,     0,     0,    38,     0,     0,    39,     0,     0,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
     234,     0,    42,     0,     0,     0,     0,     0,     0,     0,
      43,    44,   544,   545,   546,   547,   548,   549,   550,   551,
     552,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    45,
     544,   545,   546,   547,   548,   549,   550,   551,   552,     0,
       0,     0,     0,   553,     0,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,     0,     0,     0,     0,     0,
       0,     0,   564,   565,     0,     0,     0,     0,     0,   585,
     544,   545,   546,   547,   548,   549,   550,   551,   552,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   544,   545,   546,   547,   548,   549,   550,   551,   552,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   553,     0,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   544,   545,   546,   547,   548,
     549,   550,   564,   565,     0,     0,     0,     0,   553,   606,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
       0,     0,     0,     0,     0,     0,     0,   564,   565,     0,
       0,     0,     0,     0,   658,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   553,
       0,   554,   555,   556,   557,   558,   559,   560,   561,   562,
     563,     0,     0,     0,     0,     0,     0,     0,   564,   565,
     638,     0,     0,     0,     0,     0,     0,   553,     0,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,     0,
       0,     0,     0,     0,     0,     0,   564,   565,   750,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   553,   749,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,     0,
       0,     0,     0,     0,     0,     0,   564,   565,   553,     0,
     554,   555,   556,   557,   558,   559,   560,   561,   562,   563,
       0,     0,     0,     0,     0,     0,     0,   564,   565,     0,
       4,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,     0,     0,     0,     8,     0,     0,
       0,   564,   565,     9,     0,    10,     0,     0,     0,     0,
       0,    11,    12,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -327,     0,     0,    16,     0,     0,     0,     0,
       0,   230,    18,     0,     0,     0,     0,    19,     0,     0,
       0,     0,    20,     0,     0,    21,     0,     0,     0,     0,
       0,     4,    22,     6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,     0,    25,    26,    27,    28,    29,
       0,     0,   231,     0,     0,    30,     0,     0,     0,     0,
     232,     0,     0,     0,     9,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,    16,    34,    35,    36,
      37,     0,   230,    18,    38,     0,     0,    39,    19,     0,
       0,   233,     0,    20,     0,     0,    21,     0,     0,     0,
     234,     0,    42,    22,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,    24,     0,    25,    26,    27,    28,
       0,     0,     0,     4,     0,     6,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,    10,     0,
       0,     0,     0,    33,    11,     0,     0,     0,     0,    35,
      36,    37,     0,     6,     0,    38,     0,     0,    39,     0,
       0,     0,   233,     0,     0,     0,     0,     0,    16,     0,
       0,   234,     0,    42,   230,    18,     0,     0,     0,     0,
       0,    43,    44,     0,     9,    20,    10,     0,    21,     0,
       0,     0,    11,     0,     0,    22,    13,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,    25,    26,
      27,    28,     0,     0,     0,     0,    16,     0,    30,     0,
       0,     0,   230,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     9,    20,    10,     0,    21,     0,     0,     0,
      11,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    24,     0,    25,    26,    27,    28,
       0,    35,    36,    37,    16,     0,    30,    38,     0,     0,
     230,    18,     0,     0,   233,     0,     0,     0,     0,     0,
       0,    20,     0,   234,    21,    42,     0,     0,     0,     0,
       0,    22,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    25,    26,    27,    28,     0,    35,
      36,    37,     0,     0,    30,    38,     0,     0,    39,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,    37,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
     233,     0,     0,     0,     0,     0,   115,     0,     0,   234,
     116,    42,   117,   118,   119,   120,   121,     0,   122,    43,
      44,   123,     0,   124,     0,     0,     0,   125,   126,     0,
     127,   128,   129,   130,   131,   132,     0,   133,   134,   135,
     136,   137,   138,   139,   140,   141,     0,   142,     0,     0,
     143,   144,   145,   146,   147,     0,     0,   148,   149,   150,
     151,     0,     0,     0,   152,   153,     0,   154,   155,     0,
     156,   157,   158,   159,   160,   161,     0,   162,   163,   164,
     165,   166,   167,     0,     0,   168,     0,     0,   169,     0,
       0,     0,     0,     0,   170,   171,     0,   172,   173,     0,
     174,   175,   176,     0,     0,     0,     0,   177,   178,   179,
       0,   180,   181,   182,     0,   183,   184,   185,   186,   187,
     188,   189,     0,   190,     0,   191,     0,   192,   193,   194,
     195,   196,   197,   198,   199,   200,     0,   201,   202,   203,
     204,     0,     0,     0,     0,     0,   205,     0,     0,   206,
       0,     0,     0,   207,   208,     0,     0,   209,   210,   211,
     212,     0,     0,   213,     0,   214,     0,   215,   216,   217,
     218,   219,   220,   221,     0,     0,   222
};

static const yytype_int16 yycheck[] =
{
       8,    56,     2,   229,    12,     2,    53,    15,     2,    17,
     271,     2,    78,     2,    78,     2,   305,     2,    75,    76,
      77,    29,    76,    77,     2,    82,    34,     2,    82,     2,
       2,     2,    40,    41,     2,     2,     2,   370,     2,     2,
     363,   314,   333,   221,   307,   266,   267,   310,     3,   312,
       5,   112,   315,    61,   351,     6,    40,    41,   321,    56,
      17,   588,   288,   415,    79,    56,     3,    56,     5,    56,
     650,   122,   589,    65,    26,   657,    70,     3,    56,     5,
     662,    56,    27,    56,   373,   150,    48,    28,    43,   154,
     175,   175,   107,    48,     3,   112,     5,   587,    42,   175,
     201,   591,   201,   301,    17,     0,    43,   391,   392,   201,
     201,    48,   227,   201,    58,   201,    57,    43,    80,   184,
     112,    37,    67,   201,   201,   226,    42,    82,   145,   228,
      71,   329,   659,     9,    43,   223,   228,   228,    79,   224,
     224,   226,   228,   660,   106,    82,   223,   222,   224,   370,
     228,     3,   227,    15,    16,    17,    82,   739,    20,    21,
     108,   222,    30,   222,   390,   391,   392,   226,    36,   222,
     697,   222,   222,    82,   227,   225,   242,   129,   242,   222,
       9,   533,   473,    12,   227,   702,   141,     3,   485,     5,
     542,     3,   772,   155,     6,     7,     8,     9,    10,    11,
     266,   267,   266,   267,   141,     3,   696,     5,   170,   699,
     494,   222,   226,   740,   225,   141,   171,   169,   275,   164,
     227,   275,   230,   231,   232,   233,   234,   227,   228,   746,
     227,   228,   141,   297,   171,   181,   227,   228,   227,   228,
      15,    16,    17,   222,   299,   171,   225,    17,   224,   233,
     234,   306,   742,   227,   199,   518,   211,   483,   484,   314,
      65,   482,   171,   753,   221,   222,   226,   222,   494,    81,
       6,     7,   227,   222,   211,   222,   225,   228,   225,   222,
     541,   225,   225,   572,     3,   211,     5,   777,   226,    43,
     227,   517,   226,    43,    48,   226,   222,   352,   211,   212,
     213,   227,   211,   566,   370,    44,   370,   322,   221,   222,
     325,   226,   327,   328,   314,   226,   226,   332,   227,   383,
     375,   133,   226,     3,   621,     5,   226,   624,    82,   226,
     226,   628,    82,     3,   595,     5,   224,   224,   226,   226,
     603,     3,     3,     5,     5,   207,   208,   209,   210,   211,
     212,   213,     9,   112,   166,   363,    95,   224,   415,   221,
     222,   226,     3,   696,     5,     3,   224,   640,   180,   108,
     109,   110,   111,   227,     3,   375,     5,   227,   226,   118,
     228,   227,   369,   227,   439,   227,   227,   141,   227,   712,
     124,   141,   392,   227,   206,   227,   657,   209,   210,   211,
     227,   662,   214,   215,   665,   227,   739,   227,   227,   227,
     707,   223,   227,   227,   227,   227,   482,   171,   482,   716,
     753,   171,   226,   162,   227,   227,   227,   227,   167,   222,
     227,   652,   227,   227,   209,   210,   211,   212,   213,   209,
     210,   211,   212,   213,   777,   227,   221,   222,   227,   227,
     227,   221,   222,   227,   227,   227,   227,   211,   227,   227,
     227,   211,   196,   197,   198,   199,   200,   522,   222,   524,
     227,   227,   222,   227,   227,   541,   533,   227,   739,   224,
     488,   770,   224,   224,   224,   203,   543,   224,   709,   543,
     221,   491,   492,   226,   491,   492,   226,   224,   492,   227,
     491,   492,   491,   492,   229,   492,   491,   492,     5,   203,
       9,   228,   228,   227,   492,     6,     9,   492,   222,   492,
     492,   492,     9,   589,   492,   492,   492,   524,   492,   492,
     793,   522,     9,     9,   589,    15,    16,    17,    18,    19,
      20,    21,   302,    23,     9,   305,     9,     9,     9,   227,
     226,   226,   226,   313,   226,   224,   316,   224,   226,   225,
     224,   201,     6,   323,   324,   228,   224,   201,   228,   225,
     229,   618,   798,   799,   228,   630,   228,   227,   221,   228,
     228,   201,   228,   228,   228,   640,   652,   201,   652,   589,
     654,   657,   228,   228,   660,   228,   662,   228,   228,     9,
     228,   228,   228,   228,   228,   660,   228,   228,   203,   666,
     228,   228,   666,   373,   374,   228,   228,   228,   228,   228,
     221,   228,   228,   228,   226,   228,   201,   627,   181,   228,
     627,     3,   226,   630,   226,   635,   627,     3,   627,   630,
     640,   630,   627,   709,     6,   709,     9,   702,     6,   409,
     410,   411,   412,   413,   414,   415,   228,   201,   203,   226,
     660,   225,   222,   225,     5,   226,   721,   203,   203,   228,
     228,   228,   228,   739,   228,   226,   226,   226,   224,    15,
      16,    17,    18,    19,    20,    21,   228,   228,   228,   228,
     228,   746,     3,   226,   203,     6,     7,     8,     9,    10,
      11,   226,   702,   711,   712,   490,   569,   517,   708,   799,
     635,   708,   597,   368,   361,   323,   533,   708,   242,   708,
     772,   319,   645,    88,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   641,   643,    -1,   379,    -1,    -1,
     500,   221,   222,    -1,    -1,    -1,   746,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   764,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,   544,   545,    -1,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,    -1,   565,    -1,    -1,    36,    -1,
      38,    -1,   572,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      48,    -1,   133,    -1,    -1,    -1,    -1,    -1,     3,    -1,
      -1,     6,     7,     8,     9,    10,    11,   597,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,    -1,
      -1,    -1,    80,    81,    -1,   166,    -1,    85,    -1,    -1,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,   180,
     206,   207,   208,   209,   210,   211,   212,   213,   106,    -1,
     108,   109,   110,   111,    -1,   221,   222,    -1,    -1,    -1,
     118,    -1,    -1,    -1,    -1,   206,    -1,    -1,   209,   210,
     211,    -1,    -1,   214,   215,   133,    81,    -1,    -1,    -1,
      -1,    -1,   223,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,
      -1,    -1,    -1,   161,   162,   163,    -1,    -1,   166,   167,
      -1,    -1,   170,    -1,    -1,    -1,   174,    -1,    -1,    -1,
      -1,    -1,   180,    -1,    -1,   183,    -1,   185,   133,    -1,
      -1,     3,     4,     5,    -1,   193,   194,    15,    16,    17,
      18,    19,    20,    21,    -1,    -1,    -1,    -1,   206,    -1,
      -1,   209,   210,   211,    -1,   745,   214,   215,    30,   749,
      -1,   166,    -1,    -1,    36,    -1,    38,    -1,    -1,   227,
      -1,    -1,    44,    45,    -1,   180,    48,    -1,    -1,    -1,
     770,    -1,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,
      -1,   206,    74,    75,   209,   210,   211,    -1,    80,   214,
     215,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,   227,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     102,   103,    -1,    -1,   106,    -1,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   143,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,   160,   161,
     162,   163,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,
      -1,    30,   174,    -1,    -1,    -1,    -1,    36,    -1,    38,
      -1,   183,    -1,   185,    -1,    44,    45,    -1,    -1,    48,
      -1,   193,   194,    -1,    -1,    -1,    55,   205,   206,   207,
     208,   209,   210,   211,   212,   213,    65,    -1,    -1,    68,
      -1,    -1,    -1,   221,   222,    74,    75,    -1,    -1,    -1,
     222,    80,    -1,   225,    -1,    -1,    85,    -1,    -1,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   103,    -1,    -1,   106,    -1,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,   118,
      -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   143,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,
      -1,   160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,
      -1,   170,    -1,    -1,    30,   174,    -1,    -1,    -1,    -1,
      36,    -1,    38,    -1,   183,    -1,   185,    -1,    44,    45,
      -1,    -1,    48,    -1,   193,   194,    -1,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,
      -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,
      -1,    -1,    -1,   222,    80,    -1,   225,    -1,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
     106,    -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,   143,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,    -1,    -1,    -1,   160,   161,   162,   163,    -1,    -1,
      -1,   167,    -1,    36,   170,    38,    -1,    -1,   174,    -1,
      -1,    44,    -1,    -1,    -1,    48,    -1,   183,    -1,   185,
      -1,    -1,    55,    -1,    -1,    -1,    -1,   193,   194,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,   222,    -1,    -1,   225,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,    -1,   106,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     143,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    36,    -1,    38,    -1,   161,   162,
     163,    -1,    44,    -1,   167,    -1,    48,   170,    -1,    -1,
      -1,   174,    -1,    55,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,   185,    -1,    -1,    -1,    68,    -1,    -1,    -1,
     193,   194,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
      -1,    -1,     3,    95,     5,    -1,    -1,    -1,    -1,   222,
     102,    -1,   225,    -1,   106,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,   143,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    -1,    -1,   155,    -1,    -1,    -1,    68,    -1,   161,
     162,   163,    -1,    74,    75,   167,    -1,    -1,   170,    80,
      -1,    -1,   174,    -1,    85,    -1,    -1,    88,    -1,    -1,
      -1,   183,    -1,   185,    95,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,   106,    -1,   108,   109,   110,
     111,    -1,    -1,    -1,    -1,    -1,    -1,   118,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
     222,    -1,    -1,   225,    14,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    -1,    -1,    -1,   155,    -1,    36,    -1,    38,    -1,
     161,   162,   163,    -1,    44,    45,   167,    -1,    48,   170,
      -1,    -1,    -1,   174,    -1,    55,    -1,    -1,    -1,    -1,
      -1,    -1,   183,    -1,   185,    65,    -1,    -1,    68,    -1,
      -1,    -1,   193,   194,    74,    75,    -1,    -1,    -1,    -1,
      80,    -1,    -1,    -1,    -1,    85,    -1,    -1,    88,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,   222,   102,    -1,   225,    -1,   106,    -1,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,    -1,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,   207,   208,   209,   210,
     211,   212,   213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,    -1,   143,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   155,    -1,    -1,    -1,    -1,
     160,   161,   162,   163,    -1,    -1,    -1,   167,    -1,    -1,
     170,    -1,    -1,    -1,   174,    -1,     3,     4,     5,    -1,
      -1,   181,    -1,   183,    -1,   185,    13,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,    -1,    36,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    48,   222,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,
      -1,    68,    -1,    -1,    -1,    -1,    -1,    74,    75,    -1,
      -1,    -1,    -1,    80,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    88,    -1,    -1,    -1,    -1,    -1,     3,    95,     5,
      -1,    -1,    -1,    -1,    -1,   102,   103,    -1,    -1,   106,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,   118,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      36,    -1,    38,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,   143,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,    -1,
      -1,    -1,    68,   160,   161,   162,   163,    -1,    74,    75,
     167,    -1,    -1,   170,    80,    -1,    82,   174,    -1,    85,
      -1,    -1,    88,    -1,    -1,    -1,   183,    -1,   185,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,    -1,
     106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,    -1,
      -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   155,
      -1,    36,    -1,    38,    -1,   161,   162,   163,    43,    44,
      -1,   167,    -1,    48,   170,   171,    -1,    -1,   174,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,   185,
      -1,    -1,    -1,    68,    -1,    -1,    -1,   193,   194,    74,
      75,    -1,    -1,    -1,    -1,    80,    -1,    82,    -1,    -1,
      85,    -1,    -1,    88,    -1,   211,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,   222,    -1,    -1,    -1,
      -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,    -1,
      -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     155,    -1,    36,    -1,    38,    -1,   161,   162,   163,    -1,
      44,    -1,   167,    -1,    48,   170,   171,    -1,    -1,   174,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   183,    -1,
     185,    -1,    -1,    -1,    68,    -1,    -1,    -1,   193,   194,
      74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    88,    -1,   211,    -1,    -1,    -1,
       3,    95,     5,    -1,    -1,    -1,    -1,   222,    -1,    -1,
      -1,    -1,   106,    -1,   108,   109,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,   118,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    48,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      -1,   155,    -1,    -1,    -1,    68,    -1,   161,   162,   163,
      -1,    74,    75,   167,    -1,    -1,   170,    80,    -1,    -1,
     174,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,   183,
      -1,   185,    95,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,    -1,    -1,   106,    -1,   108,   109,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,   118,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,   222,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,   155,    -1,    -1,    -1,    -1,    -1,   161,   162,
     163,    -1,    -1,    -1,   167,    -1,    -1,   170,    -1,    -1,
      -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     183,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   222,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,   202,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,    -1,    -1,    -1,    -1,    -1,   228,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,    15,    16,    17,    18,    19,
      20,    21,   221,   222,    -1,    -1,    -1,    -1,   202,   228,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
      -1,    -1,    -1,    -1,   228,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
      -1,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,
     223,    -1,    -1,    -1,    -1,    -1,    -1,   202,    -1,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   202,    -1,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   221,   222,    -1,
       3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,    -1,    -1,    -1,    30,    -1,    -1,
      -1,   221,   222,    36,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    45,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    65,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,    -1,
      -1,     3,    95,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,    -1,   108,   109,   110,   111,   112,
      -1,    -1,   115,    -1,    -1,   118,    -1,    -1,    -1,    -1,
     123,    -1,    -1,    -1,    36,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   155,    -1,    -1,    -1,    68,   160,   161,   162,
     163,    -1,    74,    75,   167,    -1,    -1,   170,    80,    -1,
      -1,   174,    -1,    85,    -1,    -1,    88,    -1,    -1,    -1,
     183,    -1,   185,    95,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,    -1,    -1,   106,    -1,   108,   109,   110,   111,
      -1,    -1,    -1,     3,    -1,     5,   118,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    36,    -1,    38,    -1,
      -1,    -1,    -1,   155,    44,    -1,    -1,    -1,    -1,   161,
     162,   163,    -1,     5,    -1,   167,    -1,    -1,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,   183,    -1,   185,    74,    75,    -1,    -1,    -1,    -1,
      -1,   193,   194,    -1,    36,    85,    38,    -1,    88,    -1,
      -1,    -1,    44,    -1,    -1,    95,    48,    -1,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,    -1,    -1,    -1,    -1,    68,    -1,   118,    -1,
      -1,    -1,    74,    75,    -1,    -1,    -1,    -1,    80,    -1,
      -1,    -1,    36,    85,    38,    -1,    88,    -1,    -1,    -1,
      44,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,   108,   109,   110,   111,
      -1,   161,   162,   163,    68,    -1,   118,   167,    -1,    -1,
      74,    75,    -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,   183,    88,   185,    -1,    -1,    -1,    -1,
      -1,    95,    -1,   193,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   155,   108,   109,   110,   111,    -1,   161,
     162,   163,    -1,    -1,   118,   167,    -1,    -1,   170,    -1,
      -1,    -1,   174,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   183,    -1,   185,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   161,   162,   163,
      -1,    -1,    -1,   167,    -1,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,   183,
      29,   185,    31,    32,    33,    34,    35,    -1,    37,   193,
     194,    40,    -1,    42,    -1,    -1,    -1,    46,    47,    -1,
      49,    50,    51,    52,    53,    54,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    66,    -1,    -1,
      69,    70,    71,    72,    73,    -1,    -1,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    84,    -1,    86,    87,    -1,
      89,    90,    91,    92,    93,    94,    -1,    96,    97,    98,
      99,   100,   101,    -1,    -1,   104,    -1,    -1,   107,    -1,
      -1,    -1,    -1,    -1,   113,   114,    -1,   116,   117,    -1,
     119,   120,   121,    -1,    -1,    -1,    -1,   126,   127,   128,
      -1,   130,   131,   132,    -1,   134,   135,   136,   137,   138,
     139,   140,    -1,   142,    -1,   144,    -1,   146,   147,   148,
     149,   150,   151,   152,   153,   154,    -1,   156,   157,   158,
     159,    -1,    -1,    -1,    -1,    -1,   165,    -1,    -1,   168,
      -1,    -1,    -1,   172,   173,    -1,    -1,   176,   177,   178,
     179,    -1,    -1,   182,    -1,   184,    -1,   186,   187,   188,
     189,   190,   191,   192,    -1,    -1,   195
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   231,   233,     0,     3,     4,     5,    14,    30,    36,
      38,    44,    45,    48,    55,    65,    68,    74,    75,    80,
      85,    88,    95,   102,   106,   108,   109,   110,   111,   112,
     118,   125,   143,   155,   160,   161,   162,   163,   167,   170,
     174,   183,   185,   193,   194,   222,   232,   239,   240,   242,
     243,   244,   245,   248,   249,   255,   256,   271,   285,   290,
     292,   293,   295,   296,   297,   298,   299,   300,   301,   304,
     305,   308,   310,   311,   315,   316,   317,   318,   320,   323,
     341,   342,   343,   344,   345,   221,   222,   347,   350,   351,
       3,     5,   288,   288,   227,   288,     3,   287,   288,   108,
     291,     9,   288,   291,     3,   227,   288,   227,   291,   292,
       3,   287,     3,   287,   292,    25,    29,    31,    32,    33,
      34,    35,    37,    40,    42,    46,    47,    49,    50,    51,
      52,    53,    54,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    66,    69,    70,    71,    72,    73,    76,    77,
      78,    79,    83,    84,    86,    87,    89,    90,    91,    92,
      93,    94,    96,    97,    98,    99,   100,   101,   104,   107,
     113,   114,   116,   117,   119,   120,   121,   126,   127,   128,
     130,   131,   132,   134,   135,   136,   137,   138,   139,   140,
     142,   144,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   156,   157,   158,   159,   165,   168,   172,   173,   176,
     177,   178,   179,   182,   184,   186,   187,   188,   189,   190,
     191,   192,   195,   257,   262,   340,   226,   235,   235,   181,
      74,   115,   123,   174,   183,   247,   271,   295,   297,   299,
     310,   314,   320,   341,   345,   226,     3,   288,   226,   226,
     226,   224,   226,   304,   226,   238,   226,   322,   323,   322,
     322,    43,    82,   141,   171,   211,   227,   264,   288,   289,
     324,   325,   338,   271,   341,   343,   345,   322,   226,    28,
      57,    71,    79,   352,   353,   347,   112,     9,   224,   226,
       3,   343,   224,   175,   224,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   201,   223,    13,   103,   239,   246,   249,
     295,   296,   297,   298,   299,   300,   301,   304,   310,   311,
     315,   225,   255,   256,     3,   288,   288,     3,     3,   224,
     224,   224,   224,   203,   309,   224,   338,   221,   234,   224,
     319,   324,   324,   229,   222,   227,   254,   322,   227,   201,
     223,     5,   228,   255,   267,   268,   269,   270,   203,   228,
     278,   227,   281,     9,     9,    12,   263,   289,     3,     6,
       7,     8,     9,    10,    11,    81,   133,   166,   180,   206,
     209,   210,   211,   214,   215,   227,   274,   275,   276,   261,
     320,     6,   260,   263,   274,   277,     9,     9,   258,   277,
     320,   276,     9,     9,   276,     9,   276,   274,   253,   256,
     320,   276,   272,   273,   274,    26,   129,   169,   259,     9,
     340,     9,   276,   343,   272,   274,   343,   124,   196,   197,
     198,   199,   200,   339,   343,   343,   263,     6,     7,   346,
       9,   343,   262,   222,   227,   226,   226,   226,   224,   226,
     226,   238,   320,   302,   302,   225,     3,   288,   293,   294,
     224,   237,   233,   145,   306,   310,   318,   324,   228,   277,
     211,   223,   274,   250,   251,   252,   253,    27,    67,   164,
     199,   354,   355,   353,   224,   289,   225,   201,   229,     6,
     241,   225,   255,   279,   255,   283,   225,   256,   280,   283,
     228,   228,   228,   227,   274,   274,   274,   274,   274,   274,
     274,   321,   323,   342,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   202,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   221,   222,   201,   228,   228,   201,
     221,   228,   201,   228,   228,   201,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   320,   211,   227,
     254,   264,   289,   330,   332,   333,   228,   201,   228,   228,
     228,   228,   228,   201,   228,   228,   228,   228,   228,   228,
     228,   228,   221,   228,   228,   228,   262,     9,   236,   324,
     334,   225,   255,   303,   225,   238,   288,   237,   225,   239,
     256,   225,   203,   122,   283,   307,   226,   223,   223,   228,
     201,   201,   228,   181,   348,   349,   270,   276,     6,   228,
     320,   345,   320,   341,   228,   226,   226,   321,   228,   211,
     227,   254,   264,   326,   328,   329,   342,   322,   274,   274,
       3,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,     3,   274,
     276,   260,     6,   277,     9,   332,   319,   211,   250,   264,
     331,   332,   227,   254,   273,   276,     6,   228,   235,   201,
     238,    65,   112,   312,   313,   238,   225,   238,   203,   226,
     225,   256,   284,   285,   225,    24,   253,   355,   351,   225,
     348,   330,   336,   337,   226,   324,   286,   289,   328,   319,
     211,   250,   264,   327,   328,   228,   227,   254,   322,   203,
     223,   228,   332,   319,   228,   332,   228,   250,   228,   238,
     225,   324,   288,   288,   293,   226,   226,   238,   226,     5,
     203,   335,   201,   226,   224,   228,   328,   319,   228,   332,
     228,   274,   250,   274,   332,   228,   288,   226,   277,   336,
     265,   332,   228,    42,    58,   225,   266,   276,   203,   203,
     226,   282,   283,   282,   226
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   230,   231,   232,   232,   233,   234,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     235,   235,   235,   236,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   237,   237,   238,   238,
     239,   239,   239,   239,   239,   239,   239,   240,   241,   241,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   250,   251,   251,
     252,   252,   253,   253,   254,   254,   254,   255,   255,   256,
     257,   257,   257,   258,   258,   259,   259,   259,   260,   260,
     261,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   262,
     262,   262,   262,   262,   262,   262,   262,   262,   262,   263,
     263,   264,   264,   264,   264,   265,   265,   266,   266,   267,
     267,   267,   268,   268,   269,   270,   270,   271,   272,   272,
     273,   273,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   274,   274,   274,   274,
     274,   274,   274,   275,   275,   276,   277,   278,   278,   279,
     279,   280,   280,   281,   281,   282,   282,   283,   283,   284,
     285,   285,   286,   286,   287,   287,   288,   288,   289,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     291,   291,   292,   292,   292,   292,   292,   292,   292,   292,
     292,   293,   293,   294,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   302,   303,   303,   304,   305,   306,   306,
     307,   307,   308,   308,   309,   309,   310,   311,   311,   312,
     312,   313,   314,   315,   316,   316,   316,   317,   318,   319,
     319,   320,   320,   321,   321,   322,   322,   323,   323,   323,
     324,   324,   324,   325,   325,   325,   325,   326,   326,   326,
     327,   327,   328,   328,   329,   329,   329,   329,   329,   330,
     330,   330,   331,   331,   332,   332,   333,   333,   333,   333,
     333,   333,   334,   334,   335,   335,   336,   337,   337,   338,
     338,   339,   339,   339,   339,   339,   339,   340,   340,   340,
     341,   342,   342,   342,   342,   342,   342,   342,   342,   342,
     342,   343,   343,   344,   345,   345,   346,   346,   346,   347,
     347,   348,   348,   349,   350,   351,   351,   352,   352,   353,
     353,   353,   353,   354,   354,   355,   355,   355,   355
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     3,     3,
       2,     3,     2,     3,     2,     3,     2,     2,     2,     2,
       0,     3,     3,     0,     6,     2,     3,     2,     3,     2,
       3,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       1,     2,     1,     2,     1,     2,     2,     2,     2,     4,
       3,     3,     5,     2,     3,     4,     0,     1,     1,     3,
       1,     3,     3,     2,     3,     3,     2,     0,     1,     3,
       1,     3,     4,     1,     3,     1,     1,     1,     1,     3,
       3,     0,     1,     4,     1,     1,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     1,     4,     4,     1,     6,
       1,     1,     1,     1,     4,     1,     1,     1,     4,     1,
       1,     1,     4,     4,     1,     1,     4,     1,     1,     1,
       1,     1,     4,     4,     4,     4,     4,     1,     4,     1,
       1,     4,     1,     4,     1,     1,     4,     4,     1,     1,
       1,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     4,     1,
       1,     1,     1,     1,     6,     1,     4,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     4,     3,     0,
       2,     1,     1,     3,     2,     3,     1,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       5,     4,     3,     1,     3,     1,     1,     0,     2,     4,
       3,     2,     2,     0,     2,     2,     1,     3,     2,     1,
       3,     2,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     2,     3,     1,     2,     2,     6,     2,     6,     2,
       5,     2,     0,     2,     3,     3,     2,     1,     2,     3,
       2,     3,     6,     6,     0,     2,     2,     7,     2,     2,
       3,     2,     2,     6,     1,     1,     1,     1,     1,     0,
       2,     2,     3,     2,     3,     0,     1,     2,     2,     2,
       3,     2,     1,     1,     3,     2,     4,     3,     2,     1,
       3,     2,     0,     1,     3,     2,     1,     3,     4,     3,
       2,     1,     3,     2,     0,     1,     1,     3,     2,     1,
       3,     4,     1,     3,     0,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     1,     2,     1,     2,     1,     2,     4,
       1,     1,     2,     5,     5,    10,     1,     3,     1,     0,
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
#line 338 "tools/widl/parser.y"
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
#line 3278 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 354 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3284 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 355 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3290 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 356 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3296 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interface ';'  */
#line 357 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3302 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 358 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3308 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements interfacedef  */
#line 359 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3314 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclass ';'  */
#line 360 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3322 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements coclassdef  */
#line 363 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3330 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements apicontract ';'  */
#line 366 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3336 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements apicontract_def  */
#line 367 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3343 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 369 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3349 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 370 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3356 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements moduledef  */
#line 372 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3362 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements librarydef  */
#line 373 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3368 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements statement  */
#line 374 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3374 "tools/widl/parser.tab.c"
    break;

  case 20: /* imp_statements: %empty  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3380 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements interface ';'  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3386 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements dispinterface ';'  */
#line 379 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3392 "tools/widl/parser.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 380 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3398 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 381 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3404 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements interfacedef  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3410 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: imp_statements coclass ';'  */
#line 383 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3416 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements coclassdef  */
#line 384 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3424 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: imp_statements apicontract ';'  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3430 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements apicontract_def  */
#line 388 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3437 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements runtimeclass ';'  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3443 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements runtimeclass_def  */
#line 391 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3450 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements moduledef  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3456 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements statement  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3462 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements importlib  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3468 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements librarydef  */
#line 396 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3474 "tools/widl/parser.tab.c"
    break;

  case 36: /* int_statements: %empty  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3480 "tools/widl/parser.tab.c"
    break;

  case 37: /* int_statements: int_statements statement  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3486 "tools/widl/parser.tab.c"
    break;

  case 40: /* statement: cppquote  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3492 "tools/widl/parser.tab.c"
    break;

  case 41: /* statement: typedecl ';'  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3498 "tools/widl/parser.tab.c"
    break;

  case 42: /* statement: declaration ';'  */
#line 410 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3504 "tools/widl/parser.tab.c"
    break;

  case 43: /* statement: import  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3510 "tools/widl/parser.tab.c"
    break;

  case 44: /* statement: typedef ';'  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3516 "tools/widl/parser.tab.c"
    break;

  case 45: /* statement: aPRAGMA  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3522 "tools/widl/parser.tab.c"
    break;

  case 46: /* statement: pragma_warning  */
#line 414 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3528 "tools/widl/parser.tab.c"
    break;

  case 47: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 418 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3540 "tools/widl/parser.tab.c"
    break;

  case 48: /* warnings: aNUM  */
#line 428 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3546 "tools/widl/parser.tab.c"
    break;

  case 49: /* warnings: warnings aNUM  */
#line 429 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3552 "tools/widl/parser.tab.c"
    break;

  case 51: /* typedecl: tENUM aIDENTIFIER  */
#line 434 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3558 "tools/widl/parser.tab.c"
    break;

  case 53: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3564 "tools/widl/parser.tab.c"
    break;

  case 55: /* typedecl: tUNION aIDENTIFIER  */
#line 438 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3570 "tools/widl/parser.tab.c"
    break;

  case 56: /* typedecl: attributes enumdef  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3576 "tools/widl/parser.tab.c"
    break;

  case 57: /* typedecl: attributes structdef  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3582 "tools/widl/parser.tab.c"
    break;

  case 58: /* typedecl: attributes uniondef  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3588 "tools/widl/parser.tab.c"
    break;

  case 59: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3594 "tools/widl/parser.tab.c"
    break;

  case 60: /* import_start: tIMPORT aSTRING ';'  */
#line 446 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3605 "tools/widl/parser.tab.c"
    break;

  case 61: /* import: import_start imp_statements aEOF  */
#line 454 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3614 "tools/widl/parser.tab.c"
    break;

  case 62: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 461 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3620 "tools/widl/parser.tab.c"
    break;

  case 63: /* libraryhdr: tLIBRARY typename  */
#line 464 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3626 "tools/widl/parser.tab.c"
    break;

  case 64: /* library_start: attributes libraryhdr '{'  */
#line 466 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3634 "tools/widl/parser.tab.c"
    break;

  case 65: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3640 "tools/widl/parser.tab.c"
    break;

  case 66: /* m_args: %empty  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3646 "tools/widl/parser.tab.c"
    break;

  case 68: /* arg_list: arg  */
#line 478 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3652 "tools/widl/parser.tab.c"
    break;

  case 69: /* arg_list: arg_list ',' arg  */
#line 479 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3658 "tools/widl/parser.tab.c"
    break;

  case 71: /* args: arg_list ',' ELLIPSIS  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3664 "tools/widl/parser.tab.c"
    break;

  case 72: /* arg: attributes decl_spec m_any_declarator  */
#line 487 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3674 "tools/widl/parser.tab.c"
    break;

  case 73: /* arg: decl_spec m_any_declarator  */
#line 492 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3684 "tools/widl/parser.tab.c"
    break;

  case 74: /* array: '[' expr ']'  */
#line 499 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3693 "tools/widl/parser.tab.c"
    break;

  case 75: /* array: '[' '*' ']'  */
#line 503 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3699 "tools/widl/parser.tab.c"
    break;

  case 76: /* array: '[' ']'  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3705 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_attributes: %empty  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3711 "tools/widl/parser.tab.c"
    break;

  case 79: /* attributes: '[' attrib_list ']'  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3717 "tools/widl/parser.tab.c"
    break;

  case 80: /* attrib_list: attribute  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3723 "tools/widl/parser.tab.c"
    break;

  case 81: /* attrib_list: attrib_list ',' attribute  */
#line 516 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3729 "tools/widl/parser.tab.c"
    break;

  case 82: /* attrib_list: attrib_list ']' '[' attribute  */
#line 517 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3735 "tools/widl/parser.tab.c"
    break;

  case 83: /* str_list: aSTRING  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3741 "tools/widl/parser.tab.c"
    break;

  case 84: /* str_list: str_list ',' aSTRING  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3747 "tools/widl/parser.tab.c"
    break;

  case 85: /* marshaling_behavior: tAGILE  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3753 "tools/widl/parser.tab.c"
    break;

  case 86: /* marshaling_behavior: tNONE  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3759 "tools/widl/parser.tab.c"
    break;

  case 87: /* marshaling_behavior: tSTANDARD  */
#line 527 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3765 "tools/widl/parser.tab.c"
    break;

  case 88: /* contract_ver: aNUM  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3771 "tools/widl/parser.tab.c"
    break;

  case 89: /* contract_ver: aNUM '.' aNUM  */
#line 532 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3777 "tools/widl/parser.tab.c"
    break;

  case 90: /* contract_req: decl_spec ',' contract_ver  */
#line 535 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3787 "tools/widl/parser.tab.c"
    break;

  case 91: /* attribute: %empty  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3793 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: tAGGREGATABLE  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3799 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 543 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3805 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tAPPOBJECT  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3811 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tASYNC  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3817 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tAUTOHANDLE  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3823 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tBINDABLE  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3829 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tBROADCAST  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3835 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tCALLAS '(' ident ')'  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3841 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3847 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tCODE  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3853 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tCOMMSTATUS  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3859 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tCONTEXTHANDLE  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3865 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3871 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3877 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3883 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3889 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tCONTROL  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3895 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 559 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3901 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tDECODE  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3907 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tDEFAULT  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3913 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tDEFAULTBIND  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3919 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tDEFAULTCOLLELEM  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3925 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3931 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tDEFAULTVTABLE  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3937 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3943 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tDISPLAYBIND  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3949 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3955 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tDUAL  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3961 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tENABLEALLOCATE  */
#line 570 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3967 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tENCODE  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3973 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tENDPOINT '(' str_list ')'  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3979 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tENTRY '(' expr_const ')'  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3985 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tEVENTADD  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 3991 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tEVENTREMOVE  */
#line 575 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 3997 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 576 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4005 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tEXPLICITHANDLE  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4011 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tFAULTSTATUS  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4017 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tFLAGS  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4023 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tFORCEALLOCATE  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4029 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tHANDLE  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4035 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4041 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4047 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4053 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 587 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4059 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4065 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tHIDDEN  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4071 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tID '(' expr_int_const ')'  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4077 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tIDEMPOTENT  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4083 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tIGNORE  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4089 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tIIDIS '(' expr ')'  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4095 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tIMMEDIATEBIND  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4101 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4107 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tIN  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4113 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tINPUTSYNC  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4119 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4125 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tLCID '(' expr_int_const ')'  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4131 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tLCID  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4137 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tLICENSED  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4143 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tLOCAL  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4149 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4155 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tMAYBE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4161 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tMESSAGE  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4167 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tNOCODE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4173 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tNONBROWSABLE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4179 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tNONCREATABLE  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4185 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tNONEXTENSIBLE  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4191 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tNOTIFY  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4197 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tNOTIFYFLAG  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4203 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tOBJECT  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4209 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tODL  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4215 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tOLEAUTOMATION  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4221 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4227 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tOPTIONAL  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4233 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tOUT  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4239 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tPARTIALIGNORE  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4245 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4251 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tPROGID '(' aSTRING ')'  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4257 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tPROPGET  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4263 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tPROPPUT  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4269 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tPROPPUTREF  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4275 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tPROXY  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4281 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tPUBLIC  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4287 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 628 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4295 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tREADONLY  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4301 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tREPRESENTAS '(' type ')'  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4307 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tREQUESTEDIT  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4313 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tRESTRICTED  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4319 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tRETVAL  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4325 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4331 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tSOURCE  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4337 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4343 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tSTRING  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4349 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tSWITCHIS '(' expr ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4355 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4361 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tTRANSMITAS '(' type ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4367 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tTHREADING '(' threading_type ')'  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4373 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tUIDEFAULT  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4379 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tUSESGETLASTERROR  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4385 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4391 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tUUID '(' uuid_string ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4397 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4403 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tV1ENUM  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4409 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tVARARG  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4415 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tVERSION '(' version ')'  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4421 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4427 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4433 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: pointer_type  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4439 "tools/widl/parser.tab.c"
    break;

  case 200: /* uuid_string: aSTRING  */
#line 659 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4447 "tools/widl/parser.tab.c"
    break;

  case 201: /* callconv: tCDECL  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4453 "tools/widl/parser.tab.c"
    break;

  case 202: /* callconv: tFASTCALL  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4459 "tools/widl/parser.tab.c"
    break;

  case 203: /* callconv: tPASCAL  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4465 "tools/widl/parser.tab.c"
    break;

  case 204: /* callconv: tSTDCALL  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4471 "tools/widl/parser.tab.c"
    break;

  case 205: /* cases: %empty  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4477 "tools/widl/parser.tab.c"
    break;

  case 206: /* cases: cases case  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4483 "tools/widl/parser.tab.c"
    break;

  case 207: /* case: tCASE expr_int_const ':' union_field  */
#line 674 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4492 "tools/widl/parser.tab.c"
    break;

  case 208: /* case: tDEFAULT ':' union_field  */
#line 678 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4501 "tools/widl/parser.tab.c"
    break;

  case 209: /* enums: %empty  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4507 "tools/widl/parser.tab.c"
    break;

  case 210: /* enums: enum_list ','  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4513 "tools/widl/parser.tab.c"
    break;

  case 212: /* enum_list: enum  */
#line 689 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4522 "tools/widl/parser.tab.c"
    break;

  case 213: /* enum_list: enum_list ',' enum  */
#line 693 "tools/widl/parser.y"
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
#line 4537 "tools/widl/parser.tab.c"
    break;

  case 214: /* enum_member: m_attributes ident  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4545 "tools/widl/parser.tab.c"
    break;

  case 215: /* enum: enum_member '=' expr_int_const  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4554 "tools/widl/parser.tab.c"
    break;

  case 216: /* enum: enum_member  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4562 "tools/widl/parser.tab.c"
    break;

  case 217: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4568 "tools/widl/parser.tab.c"
    break;

  case 218: /* m_exprs: m_expr  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4574 "tools/widl/parser.tab.c"
    break;

  case 219: /* m_exprs: m_exprs ',' m_expr  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4580 "tools/widl/parser.tab.c"
    break;

  case 220: /* m_expr: %empty  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4586 "tools/widl/parser.tab.c"
    break;

  case 222: /* expr: aNUM  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4592 "tools/widl/parser.tab.c"
    break;

  case 223: /* expr: aHEXNUM  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4598 "tools/widl/parser.tab.c"
    break;

  case 224: /* expr: aDOUBLE  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4604 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: tFALSE  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4610 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: tNULL  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4616 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: tTRUE  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4622 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: aSTRING  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4628 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: aWSTRING  */
#line 737 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4634 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: aSQSTRING  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4640 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: aIDENTIFIER  */
#line 739 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4646 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: expr '?' expr ':' expr  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4652 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: expr LOGICALOR expr  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4658 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: expr LOGICALAND expr  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4664 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '|' expr  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4670 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: expr '^' expr  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4676 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: expr '&' expr  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4682 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: expr EQUALITY expr  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4688 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: expr INEQUALITY expr  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4694 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: expr '>' expr  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4700 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: expr '<' expr  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4706 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr GREATEREQUAL expr  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4712 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr LESSEQUAL expr  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4718 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr SHL expr  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4724 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: expr SHR expr  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4730 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr '+' expr  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4736 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr '-' expr  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4742 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr '%' expr  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4748 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '*' expr  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4754 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr '/' expr  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4760 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: '!' expr  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4766 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: '~' expr  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4772 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: '+' expr  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4778 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: '-' expr  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4784 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: '&' expr  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4790 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: '*' expr  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4796 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 765 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4802 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '.' aIDENTIFIER  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4808 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 768 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4814 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4820 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '[' expr ']'  */
#line 771 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4826 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: '(' expr ')'  */
#line 772 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4832 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr_list_int_const: expr_int_const  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4838 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 776 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4844 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr_int_const: expr  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4853 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr_const: expr  */
#line 785 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4862 "tools/widl/parser.tab.c"
    break;

  case 267: /* fields: %empty  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4868 "tools/widl/parser.tab.c"
    break;

  case 268: /* fields: fields field  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4874 "tools/widl/parser.tab.c"
    break;

  case 269: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 796 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4883 "tools/widl/parser.tab.c"
    break;

  case 270: /* field: m_attributes uniondef ';'  */
#line 800 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4892 "tools/widl/parser.tab.c"
    break;

  case 271: /* ne_union_field: s_field ';'  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4898 "tools/widl/parser.tab.c"
    break;

  case 272: /* ne_union_field: attributes ';'  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4904 "tools/widl/parser.tab.c"
    break;

  case 273: /* ne_union_fields: %empty  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4910 "tools/widl/parser.tab.c"
    break;

  case 274: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4916 "tools/widl/parser.tab.c"
    break;

  case 275: /* union_field: s_field ';'  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4922 "tools/widl/parser.tab.c"
    break;

  case 276: /* union_field: ';'  */
#line 817 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4928 "tools/widl/parser.tab.c"
    break;

  case 277: /* s_field: m_attributes decl_spec declarator  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4937 "tools/widl/parser.tab.c"
    break;

  case 278: /* s_field: m_attributes structdef  */
#line 824 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4946 "tools/widl/parser.tab.c"
    break;

  case 279: /* funcdef: declaration  */
#line 830 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4956 "tools/widl/parser.tab.c"
    break;

  case 280: /* declaration: attributes decl_spec init_declarator  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4964 "tools/widl/parser.tab.c"
    break;

  case 281: /* declaration: decl_spec init_declarator  */
#line 842 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4972 "tools/widl/parser.tab.c"
    break;

  case 282: /* m_ident: %empty  */
#line 847 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4978 "tools/widl/parser.tab.c"
    break;

  case 284: /* m_typename: %empty  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 4984 "tools/widl/parser.tab.c"
    break;

  case 288: /* ident: typename  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4990 "tools/widl/parser.tab.c"
    break;

  case 289: /* base_type: tBYTE  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 4996 "tools/widl/parser.tab.c"
    break;

  case 290: /* base_type: tWCHAR  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5002 "tools/widl/parser.tab.c"
    break;

  case 292: /* base_type: tSIGNED int_std  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5008 "tools/widl/parser.tab.c"
    break;

  case 293: /* base_type: tUNSIGNED int_std  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5014 "tools/widl/parser.tab.c"
    break;

  case 294: /* base_type: tUNSIGNED  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5020 "tools/widl/parser.tab.c"
    break;

  case 295: /* base_type: tFLOAT  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5026 "tools/widl/parser.tab.c"
    break;

  case 296: /* base_type: tDOUBLE  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5032 "tools/widl/parser.tab.c"
    break;

  case 297: /* base_type: tBOOLEAN  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5038 "tools/widl/parser.tab.c"
    break;

  case 298: /* base_type: tERRORSTATUST  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5044 "tools/widl/parser.tab.c"
    break;

  case 299: /* base_type: tHANDLET  */
#line 872 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5050 "tools/widl/parser.tab.c"
    break;

  case 302: /* int_std: tINT  */
#line 879 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5056 "tools/widl/parser.tab.c"
    break;

  case 303: /* int_std: tSHORT m_int  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5062 "tools/widl/parser.tab.c"
    break;

  case 304: /* int_std: tSMALL  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5068 "tools/widl/parser.tab.c"
    break;

  case 305: /* int_std: tLONG m_int  */
#line 882 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5074 "tools/widl/parser.tab.c"
    break;

  case 306: /* int_std: tHYPER m_int  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5080 "tools/widl/parser.tab.c"
    break;

  case 307: /* int_std: tINT64  */
#line 884 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5086 "tools/widl/parser.tab.c"
    break;

  case 308: /* int_std: tCHAR  */
#line 885 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5092 "tools/widl/parser.tab.c"
    break;

  case 309: /* int_std: tINT32  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5098 "tools/widl/parser.tab.c"
    break;

  case 310: /* int_std: tINT3264  */
#line 887 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5104 "tools/widl/parser.tab.c"
    break;

  case 311: /* namespace_pfx: aIDENTIFIER '.'  */
#line 891 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5110 "tools/widl/parser.tab.c"
    break;

  case 312: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 892 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5116 "tools/widl/parser.tab.c"
    break;

  case 313: /* qualified_type: typename  */
#line 896 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5122 "tools/widl/parser.tab.c"
    break;

  case 314: /* qualified_type: namespace_pfx typename  */
#line 897 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5128 "tools/widl/parser.tab.c"
    break;

  case 315: /* coclass: tCOCLASS typename  */
#line 900 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5134 "tools/widl/parser.tab.c"
    break;

  case 316: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5140 "tools/widl/parser.tab.c"
    break;

  case 317: /* runtimeclass: tRUNTIMECLASS typename  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5146 "tools/widl/parser.tab.c"
    break;

  case 318: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 911 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5152 "tools/widl/parser.tab.c"
    break;

  case 319: /* apicontract: tAPICONTRACT typename  */
#line 914 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5158 "tools/widl/parser.tab.c"
    break;

  case 320: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 918 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5164 "tools/widl/parser.tab.c"
    break;

  case 321: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5170 "tools/widl/parser.tab.c"
    break;

  case 322: /* class_interfaces: %empty  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5176 "tools/widl/parser.tab.c"
    break;

  case 323: /* class_interfaces: class_interfaces class_interface  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5182 "tools/widl/parser.tab.c"
    break;

  case 324: /* class_interface: m_attributes interfaceref ';'  */
#line 929 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[-1].type)); (yyval.ifref)->attrs = (yyvsp[-2].attr_list); }
#line 5188 "tools/widl/parser.tab.c"
    break;

  case 325: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[-1].type)); (yyval.ifref)->attrs = (yyvsp[-2].attr_list); }
#line 5194 "tools/widl/parser.tab.c"
    break;

  case 326: /* dispinterface: tDISPINTERFACE typename  */
#line 933 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5200 "tools/widl/parser.tab.c"
    break;

  case 327: /* dispattributes: attributes  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5206 "tools/widl/parser.tab.c"
    break;

  case 328: /* dispint_props: tPROPERTIES ':'  */
#line 939 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5212 "tools/widl/parser.tab.c"
    break;

  case 329: /* dispint_props: dispint_props s_field ';'  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5218 "tools/widl/parser.tab.c"
    break;

  case 330: /* dispint_meths: tMETHODS ':'  */
#line 943 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5224 "tools/widl/parser.tab.c"
    break;

  case 331: /* dispint_meths: dispint_meths funcdef ';'  */
#line 944 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5230 "tools/widl/parser.tab.c"
    break;

  case 332: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 949 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5236 "tools/widl/parser.tab.c"
    break;

  case 333: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 951 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5242 "tools/widl/parser.tab.c"
    break;

  case 334: /* inherit: %empty  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5248 "tools/widl/parser.tab.c"
    break;

  case 335: /* inherit: ':' qualified_type  */
#line 955 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5254 "tools/widl/parser.tab.c"
    break;

  case 336: /* interface: tINTERFACE typename  */
#line 958 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5260 "tools/widl/parser.tab.c"
    break;

  case 337: /* interfacedef: attributes interface inherit '{' int_statements '}' semicolon_opt  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_define((yyvsp[-5].type), (yyvsp[-6].attr_list), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5268 "tools/widl/parser.tab.c"
    break;

  case 338: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 965 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5274 "tools/widl/parser.tab.c"
    break;

  case 339: /* interfaceref: tINTERFACE typename  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5280 "tools/widl/parser.tab.c"
    break;

  case 340: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5286 "tools/widl/parser.tab.c"
    break;

  case 341: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5292 "tools/widl/parser.tab.c"
    break;

  case 342: /* module: tMODULE typename  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5298 "tools/widl/parser.tab.c"
    break;

  case 343: /* moduledef: attributes module '{' int_statements '}' semicolon_opt  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5304 "tools/widl/parser.tab.c"
    break;

  case 344: /* storage_cls_spec: tEXTERN  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5310 "tools/widl/parser.tab.c"
    break;

  case 345: /* storage_cls_spec: tSTATIC  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5316 "tools/widl/parser.tab.c"
    break;

  case 346: /* storage_cls_spec: tREGISTER  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5322 "tools/widl/parser.tab.c"
    break;

  case 347: /* function_specifier: tINLINE  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5328 "tools/widl/parser.tab.c"
    break;

  case 348: /* type_qualifier: tCONST  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5334 "tools/widl/parser.tab.c"
    break;

  case 349: /* m_type_qual_list: %empty  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5340 "tools/widl/parser.tab.c"
    break;

  case 350: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5346 "tools/widl/parser.tab.c"
    break;

  case 351: /* decl_spec: type m_decl_spec_no_type  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5352 "tools/widl/parser.tab.c"
    break;

  case 352: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1004 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5358 "tools/widl/parser.tab.c"
    break;

  case 353: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5364 "tools/widl/parser.tab.c"
    break;

  case 354: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5370 "tools/widl/parser.tab.c"
    break;

  case 355: /* m_decl_spec_no_type: %empty  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5376 "tools/widl/parser.tab.c"
    break;

  case 357: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5382 "tools/widl/parser.tab.c"
    break;

  case 358: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1019 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5388 "tools/widl/parser.tab.c"
    break;

  case 359: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1020 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5394 "tools/widl/parser.tab.c"
    break;

  case 360: /* declarator: '*' m_type_qual_list declarator  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5400 "tools/widl/parser.tab.c"
    break;

  case 361: /* declarator: callconv declarator  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5406 "tools/widl/parser.tab.c"
    break;

  case 363: /* direct_declarator: ident  */
#line 1031 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5412 "tools/widl/parser.tab.c"
    break;

  case 364: /* direct_declarator: '(' declarator ')'  */
#line 1032 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5418 "tools/widl/parser.tab.c"
    break;

  case 365: /* direct_declarator: direct_declarator array  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 366: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5430 "tools/widl/parser.tab.c"
    break;

  case 367: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1040 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5436 "tools/widl/parser.tab.c"
    break;

  case 368: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1041 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5442 "tools/widl/parser.tab.c"
    break;

  case 370: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5448 "tools/widl/parser.tab.c"
    break;

  case 371: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5454 "tools/widl/parser.tab.c"
    break;

  case 372: /* m_abstract_declarator: %empty  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5460 "tools/widl/parser.tab.c"
    break;

  case 374: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1059 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5466 "tools/widl/parser.tab.c"
    break;

  case 375: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5472 "tools/widl/parser.tab.c"
    break;

  case 376: /* abstract_direct_declarator: array  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5478 "tools/widl/parser.tab.c"
    break;

  case 377: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5486 "tools/widl/parser.tab.c"
    break;

  case 378: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1067 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5494 "tools/widl/parser.tab.c"
    break;

  case 379: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5500 "tools/widl/parser.tab.c"
    break;

  case 380: /* any_declarator: callconv m_any_declarator  */
#line 1076 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5506 "tools/widl/parser.tab.c"
    break;

  case 382: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1083 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5512 "tools/widl/parser.tab.c"
    break;

  case 383: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1084 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5518 "tools/widl/parser.tab.c"
    break;

  case 384: /* m_any_declarator: %empty  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5524 "tools/widl/parser.tab.c"
    break;

  case 386: /* any_direct_declarator: ident  */
#line 1096 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5530 "tools/widl/parser.tab.c"
    break;

  case 387: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1097 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5536 "tools/widl/parser.tab.c"
    break;

  case 388: /* any_direct_declarator: any_direct_declarator array  */
#line 1098 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5542 "tools/widl/parser.tab.c"
    break;

  case 389: /* any_direct_declarator: array  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5548 "tools/widl/parser.tab.c"
    break;

  case 390: /* any_direct_declarator: '(' m_args ')'  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5556 "tools/widl/parser.tab.c"
    break;

  case 391: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5564 "tools/widl/parser.tab.c"
    break;

  case 392: /* declarator_list: declarator  */
#line 1111 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5570 "tools/widl/parser.tab.c"
    break;

  case 393: /* declarator_list: declarator_list ',' declarator  */
#line 1112 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5576 "tools/widl/parser.tab.c"
    break;

  case 394: /* m_bitfield: %empty  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5582 "tools/widl/parser.tab.c"
    break;

  case 395: /* m_bitfield: ':' expr_const  */
#line 1116 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5588 "tools/widl/parser.tab.c"
    break;

  case 396: /* struct_declarator: any_declarator m_bitfield  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5597 "tools/widl/parser.tab.c"
    break;

  case 397: /* struct_declarator_list: struct_declarator  */
#line 1126 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5603 "tools/widl/parser.tab.c"
    break;

  case 398: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1128 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5609 "tools/widl/parser.tab.c"
    break;

  case 399: /* init_declarator: declarator  */
#line 1132 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5615 "tools/widl/parser.tab.c"
    break;

  case 400: /* init_declarator: declarator '=' expr_const  */
#line 1133 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5621 "tools/widl/parser.tab.c"
    break;

  case 401: /* threading_type: tAPARTMENT  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5627 "tools/widl/parser.tab.c"
    break;

  case 402: /* threading_type: tNEUTRAL  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5633 "tools/widl/parser.tab.c"
    break;

  case 403: /* threading_type: tSINGLE  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5639 "tools/widl/parser.tab.c"
    break;

  case 404: /* threading_type: tFREE  */
#line 1140 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5645 "tools/widl/parser.tab.c"
    break;

  case 405: /* threading_type: tBOTH  */
#line 1141 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5651 "tools/widl/parser.tab.c"
    break;

  case 406: /* threading_type: tMTA  */
#line 1142 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5657 "tools/widl/parser.tab.c"
    break;

  case 407: /* pointer_type: tREF  */
#line 1146 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5663 "tools/widl/parser.tab.c"
    break;

  case 408: /* pointer_type: tUNIQUE  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5669 "tools/widl/parser.tab.c"
    break;

  case 409: /* pointer_type: tPTR  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5675 "tools/widl/parser.tab.c"
    break;

  case 410: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5681 "tools/widl/parser.tab.c"
    break;

  case 411: /* unqualified_type: tVOID  */
#line 1155 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5687 "tools/widl/parser.tab.c"
    break;

  case 412: /* unqualified_type: base_type  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5693 "tools/widl/parser.tab.c"
    break;

  case 413: /* unqualified_type: enumdef  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5699 "tools/widl/parser.tab.c"
    break;

  case 414: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1158 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5705 "tools/widl/parser.tab.c"
    break;

  case 415: /* unqualified_type: structdef  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5711 "tools/widl/parser.tab.c"
    break;

  case 416: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5717 "tools/widl/parser.tab.c"
    break;

  case 417: /* unqualified_type: uniondef  */
#line 1161 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5723 "tools/widl/parser.tab.c"
    break;

  case 418: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1162 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5729 "tools/widl/parser.tab.c"
    break;

  case 419: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1163 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5735 "tools/widl/parser.tab.c"
    break;

  case 420: /* unqualified_type: aKNOWNTYPE  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5741 "tools/widl/parser.tab.c"
    break;

  case 422: /* type: namespace_pfx typename  */
#line 1169 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5747 "tools/widl/parser.tab.c"
    break;

  case 423: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1173 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5756 "tools/widl/parser.tab.c"
    break;

  case 424: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5762 "tools/widl/parser.tab.c"
    break;

  case 425: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1183 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5768 "tools/widl/parser.tab.c"
    break;

  case 426: /* version: aNUM  */
#line 1187 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5774 "tools/widl/parser.tab.c"
    break;

  case 427: /* version: aNUM '.' aNUM  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5780 "tools/widl/parser.tab.c"
    break;

  case 428: /* version: aHEXNUM  */
#line 1189 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5786 "tools/widl/parser.tab.c"
    break;

  case 433: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1204 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5794 "tools/widl/parser.tab.c"
    break;

  case 434: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1211 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5804 "tools/widl/parser.tab.c"
    break;

  case 435: /* acf_attributes: %empty  */
#line 1219 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5810 "tools/widl/parser.tab.c"
    break;

  case 436: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5816 "tools/widl/parser.tab.c"
    break;

  case 437: /* acf_attribute_list: acf_attribute  */
#line 1224 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5822 "tools/widl/parser.tab.c"
    break;

  case 438: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1225 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5828 "tools/widl/parser.tab.c"
    break;

  case 439: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5834 "tools/widl/parser.tab.c"
    break;

  case 440: /* acf_attribute: tENCODE  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5840 "tools/widl/parser.tab.c"
    break;

  case 441: /* acf_attribute: tDECODE  */
#line 1232 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5846 "tools/widl/parser.tab.c"
    break;

  case 442: /* acf_attribute: tEXPLICITHANDLE  */
#line 1233 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5852 "tools/widl/parser.tab.c"
    break;

  case 443: /* allocate_option_list: allocate_option  */
#line 1237 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5858 "tools/widl/parser.tab.c"
    break;

  case 444: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1239 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 5864 "tools/widl/parser.tab.c"
    break;

  case 445: /* allocate_option: tDONTFREE  */
#line 1243 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 5870 "tools/widl/parser.tab.c"
    break;

  case 446: /* allocate_option: tFREE  */
#line 1244 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5876 "tools/widl/parser.tab.c"
    break;

  case 447: /* allocate_option: tALLNODES  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 5882 "tools/widl/parser.tab.c"
    break;

  case 448: /* allocate_option: tSINGLENODE  */
#line 1246 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 5888 "tools/widl/parser.tab.c"
    break;


#line 5892 "tools/widl/parser.tab.c"

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

#line 1249 "tools/widl/parser.y"


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

static type_t *find_type_or_error(struct namespace *namespace, const char *name)
{
    type_t *type;
    if (!(type = find_type(name, namespace, 0)))
    {
        error_loc("type '%s' not found in %s namespace\n", name, namespace && namespace->name ? namespace->name : "global");
        return NULL;
    }
    return type;
}

static struct namespace *find_namespace_or_error(struct namespace *parent, const char *name)
{
    struct namespace *namespace = NULL;

    if (!winrt_mode)
        error_loc("namespaces are only supported in winrt mode.\n");
    else if (!(namespace = find_sub_namespace(parent, name)))
        error_loc("namespace '%s' not found in '%s'\n", name, parent->name);

    return namespace;
}

int is_type(const char *name)
{
    return find_type(name, current_namespace, 0) != NULL;
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
    /* ATTR_DISPINTERFACE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EVENTADD */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventadd" },
    /* ATTR_EVENTREMOVE */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventremove" },
    /* ATTR_EXCLUSIVETO */         { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "exclusive_to" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FLAGS */               { 0, 0, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "flags" },
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

attr_list_t *check_interface_attrs(const char *name, attr_list_t *attrs)
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

attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs)
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

attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs)
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

attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs)
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

attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_runtimeclass)
            error_loc("inapplicable attribute %s for runtimeclass %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs)
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
        idl_handle->declspec.type = find_type_or_error(NULL, "handle_t");
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
                if (is_attr(func->attrs, ATTR_EVENTADD) != is_attr(func_iter->attrs, ATTR_EVENTADD)) continue;
                if (is_attr(func->attrs, ATTR_EVENTREMOVE) != is_attr(func_iter->attrs, ATTR_EVENTREMOVE)) continue;
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

    async_iface = type_interface_declare(strmake("Async%s", iface->name), iface->namespace);

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

    type_interface_define(async_iface, map_attrs(iface->attrs, async_iface_attrs), inherit, stmts);
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
        type_t *type = find_type_or_error(current_namespace, var->name);
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
