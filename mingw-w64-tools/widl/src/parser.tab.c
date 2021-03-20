/* A Bison parser, made by GNU Bison 3.7.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
#define YYBISON 30705

/* Bison version string.  */
#define YYBISON_VERSION "3.7.5"

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

struct _import_t
{
  char *name;
  int import_performed;
};

static str_list_t *append_str(str_list_t *list, char *str);
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_custom_attr(UUID *id, expr_t *pval);
static expr_list_t *append_expr(expr_list_t *list, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
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
static void push_parameters_namespace(const char *name);
static void pop_parameters_namespace(const char *name);

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts);
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
static statement_t *make_statement_parameterized_type(type_t *type, typeref_list_t *params);
static statement_t *make_statement_delegate(type_t *ret, var_list_t *args);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *parameters_namespace = NULL;
static statement_list_t *parameterized_type_stmts = NULL;

static typelib_t *current_typelib;


#line 201 "tools/widl/parser.tab.c"

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
    tACTIVATABLE = 280,            /* tACTIVATABLE  */
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
    tDECLARE = 313,                /* tDECLARE  */
    tDECODE = 314,                 /* tDECODE  */
    tDEFAULT = 315,                /* tDEFAULT  */
    tDEFAULTBIND = 316,            /* tDEFAULTBIND  */
    tDELEGATE = 317,               /* tDELEGATE  */
    tDEFAULTCOLLELEM = 318,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 319,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 320,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 321, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 322,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 323,          /* tDISPINTERFACE  */
    tDLLNAME = 324,                /* tDLLNAME  */
    tDONTFREE = 325,               /* tDONTFREE  */
    tDOUBLE = 326,                 /* tDOUBLE  */
    tDUAL = 327,                   /* tDUAL  */
    tENABLEALLOCATE = 328,         /* tENABLEALLOCATE  */
    tENCODE = 329,                 /* tENCODE  */
    tENDPOINT = 330,               /* tENDPOINT  */
    tENTRY = 331,                  /* tENTRY  */
    tENUM = 332,                   /* tENUM  */
    tERRORSTATUST = 333,           /* tERRORSTATUST  */
    tEVENTADD = 334,               /* tEVENTADD  */
    tEVENTREMOVE = 335,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 336,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 337,         /* tEXPLICITHANDLE  */
    tEXTERN = 338,                 /* tEXTERN  */
    tFALSE = 339,                  /* tFALSE  */
    tFASTCALL = 340,               /* tFASTCALL  */
    tFAULTSTATUS = 341,            /* tFAULTSTATUS  */
    tFLAGS = 342,                  /* tFLAGS  */
    tFLOAT = 343,                  /* tFLOAT  */
    tFORCEALLOCATE = 344,          /* tFORCEALLOCATE  */
    tHANDLE = 345,                 /* tHANDLE  */
    tHANDLET = 346,                /* tHANDLET  */
    tHELPCONTEXT = 347,            /* tHELPCONTEXT  */
    tHELPFILE = 348,               /* tHELPFILE  */
    tHELPSTRING = 349,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 350,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 351,          /* tHELPSTRINGDLL  */
    tHIDDEN = 352,                 /* tHIDDEN  */
    tHYPER = 353,                  /* tHYPER  */
    tID = 354,                     /* tID  */
    tIDEMPOTENT = 355,             /* tIDEMPOTENT  */
    tIGNORE = 356,                 /* tIGNORE  */
    tIIDIS = 357,                  /* tIIDIS  */
    tIMMEDIATEBIND = 358,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 359,         /* tIMPLICITHANDLE  */
    tIMPORT = 360,                 /* tIMPORT  */
    tIMPORTLIB = 361,              /* tIMPORTLIB  */
    tIN = 362,                     /* tIN  */
    tIN_LINE = 363,                /* tIN_LINE  */
    tINLINE = 364,                 /* tINLINE  */
    tINPUTSYNC = 365,              /* tINPUTSYNC  */
    tINT = 366,                    /* tINT  */
    tINT32 = 367,                  /* tINT32  */
    tINT3264 = 368,                /* tINT3264  */
    tINT64 = 369,                  /* tINT64  */
    tINTERFACE = 370,              /* tINTERFACE  */
    tLCID = 371,                   /* tLCID  */
    tLENGTHIS = 372,               /* tLENGTHIS  */
    tLIBRARY = 373,                /* tLIBRARY  */
    tLICENSED = 374,               /* tLICENSED  */
    tLOCAL = 375,                  /* tLOCAL  */
    tLONG = 376,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 377,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 378,                  /* tMAYBE  */
    tMESSAGE = 379,                /* tMESSAGE  */
    tMETHODS = 380,                /* tMETHODS  */
    tMODULE = 381,                 /* tMODULE  */
    tMTA = 382,                    /* tMTA  */
    tNAMESPACE = 383,              /* tNAMESPACE  */
    tNOCODE = 384,                 /* tNOCODE  */
    tNONBROWSABLE = 385,           /* tNONBROWSABLE  */
    tNONCREATABLE = 386,           /* tNONCREATABLE  */
    tNONE = 387,                   /* tNONE  */
    tNONEXTENSIBLE = 388,          /* tNONEXTENSIBLE  */
    tNOTIFY = 389,                 /* tNOTIFY  */
    tNOTIFYFLAG = 390,             /* tNOTIFYFLAG  */
    tNULL = 391,                   /* tNULL  */
    tOBJECT = 392,                 /* tOBJECT  */
    tODL = 393,                    /* tODL  */
    tOLEAUTOMATION = 394,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 395,               /* tOPTIMIZE  */
    tOPTIONAL = 396,               /* tOPTIONAL  */
    tOUT = 397,                    /* tOUT  */
    tPARTIALIGNORE = 398,          /* tPARTIALIGNORE  */
    tPASCAL = 399,                 /* tPASCAL  */
    tPOINTERDEFAULT = 400,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 401,         /* tPRAGMA_WARNING  */
    tPROGID = 402,                 /* tPROGID  */
    tPROPERTIES = 403,             /* tPROPERTIES  */
    tPROPGET = 404,                /* tPROPGET  */
    tPROPPUT = 405,                /* tPROPPUT  */
    tPROPPUTREF = 406,             /* tPROPPUTREF  */
    tPROXY = 407,                  /* tPROXY  */
    tPTR = 408,                    /* tPTR  */
    tPUBLIC = 409,                 /* tPUBLIC  */
    tRANGE = 410,                  /* tRANGE  */
    tREADONLY = 411,               /* tREADONLY  */
    tREF = 412,                    /* tREF  */
    tREGISTER = 413,               /* tREGISTER  */
    tREPRESENTAS = 414,            /* tREPRESENTAS  */
    tREQUESTEDIT = 415,            /* tREQUESTEDIT  */
    tREQUIRES = 416,               /* tREQUIRES  */
    tRESTRICTED = 417,             /* tRESTRICTED  */
    tRETVAL = 418,                 /* tRETVAL  */
    tRUNTIMECLASS = 419,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 420,              /* tSAFEARRAY  */
    tSHORT = 421,                  /* tSHORT  */
    tSIGNED = 422,                 /* tSIGNED  */
    tSINGLENODE = 423,             /* tSINGLENODE  */
    tSIZEIS = 424,                 /* tSIZEIS  */
    tSIZEOF = 425,                 /* tSIZEOF  */
    tSMALL = 426,                  /* tSMALL  */
    tSOURCE = 427,                 /* tSOURCE  */
    tSTANDARD = 428,               /* tSTANDARD  */
    tSTATIC = 429,                 /* tSTATIC  */
    tSTDCALL = 430,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 431,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 432,                 /* tSTRING  */
    tSTRUCT = 433,                 /* tSTRUCT  */
    tSWITCH = 434,                 /* tSWITCH  */
    tSWITCHIS = 435,               /* tSWITCHIS  */
    tSWITCHTYPE = 436,             /* tSWITCHTYPE  */
    tTHREADING = 437,              /* tTHREADING  */
    tTRANSMITAS = 438,             /* tTRANSMITAS  */
    tTRUE = 439,                   /* tTRUE  */
    tTYPEDEF = 440,                /* tTYPEDEF  */
    tUIDEFAULT = 441,              /* tUIDEFAULT  */
    tUNION = 442,                  /* tUNION  */
    tUNIQUE = 443,                 /* tUNIQUE  */
    tUNSIGNED = 444,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 445,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 446,            /* tUSERMARSHAL  */
    tUUID = 447,                   /* tUUID  */
    tV1ENUM = 448,                 /* tV1ENUM  */
    tVARARG = 449,                 /* tVARARG  */
    tVERSION = 450,                /* tVERSION  */
    tVIPROGID = 451,               /* tVIPROGID  */
    tVOID = 452,                   /* tVOID  */
    tWCHAR = 453,                  /* tWCHAR  */
    tWIREMARSHAL = 454,            /* tWIREMARSHAL  */
    tAPARTMENT = 455,              /* tAPARTMENT  */
    tNEUTRAL = 456,                /* tNEUTRAL  */
    tSINGLE = 457,                 /* tSINGLE  */
    tFREE = 458,                   /* tFREE  */
    tBOTH = 459,                   /* tBOTH  */
    CAST = 460,                    /* CAST  */
    PPTR = 461,                    /* PPTR  */
    POS = 462,                     /* POS  */
    NEG = 463,                     /* NEG  */
    ADDRESSOF = 464                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 123 "tools/widl/parser.y"

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
	typeref_t *typeref;
	typeref_list_t *typeref_list;
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

#line 487 "tools/widl/parser.tab.c"

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
  YYSYMBOL_tACTIVATABLE = 25,              /* tACTIVATABLE  */
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
  YYSYMBOL_tDECLARE = 58,                  /* tDECLARE  */
  YYSYMBOL_tDECODE = 59,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 60,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 61,              /* tDEFAULTBIND  */
  YYSYMBOL_tDELEGATE = 62,                 /* tDELEGATE  */
  YYSYMBOL_tDEFAULTCOLLELEM = 63,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 64,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 65,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 66,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 67,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 68,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 69,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 70,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 71,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 72,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 73,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 74,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 75,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 76,                    /* tENTRY  */
  YYSYMBOL_tENUM = 77,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 78,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 79,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 80,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 81,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 82,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 83,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 84,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 85,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 86,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 87,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 88,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 89,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 90,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 91,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 92,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 93,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 94,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 95,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 96,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 97,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 98,                    /* tHYPER  */
  YYSYMBOL_tID = 99,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 100,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 101,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 102,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 103,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 104,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 105,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 106,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 107,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 108,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 109,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 110,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 111,                     /* tINT  */
  YYSYMBOL_tINT32 = 112,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 113,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 114,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 115,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 116,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 117,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 118,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 119,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 120,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 121,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 122,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 123,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 124,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 125,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 126,                  /* tMODULE  */
  YYSYMBOL_tMTA = 127,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 128,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 129,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 130,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 131,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 132,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 133,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 134,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 135,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 136,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 137,                  /* tOBJECT  */
  YYSYMBOL_tODL = 138,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 139,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 140,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 141,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 142,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 143,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 144,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 145,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 146,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 147,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 148,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 149,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 150,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 151,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 152,                   /* tPROXY  */
  YYSYMBOL_tPTR = 153,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 154,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 155,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 156,                /* tREADONLY  */
  YYSYMBOL_tREF = 157,                     /* tREF  */
  YYSYMBOL_tREGISTER = 158,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 159,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 160,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 161,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 162,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 163,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 164,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 165,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 166,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 167,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 168,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 169,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 170,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 171,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 172,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 173,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 174,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 175,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 176,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 177,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 178,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 179,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 180,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 181,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 182,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 183,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 184,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 185,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 186,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 187,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 188,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 189,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 190,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 191,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 192,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 193,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 194,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 195,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 196,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 197,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 198,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 199,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 200,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 201,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 202,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 203,                    /* tFREE  */
  YYSYMBOL_tBOTH = 204,                    /* tBOTH  */
  YYSYMBOL_205_ = 205,                     /* ','  */
  YYSYMBOL_206_ = 206,                     /* '?'  */
  YYSYMBOL_207_ = 207,                     /* ':'  */
  YYSYMBOL_208_ = 208,                     /* '|'  */
  YYSYMBOL_209_ = 209,                     /* '^'  */
  YYSYMBOL_210_ = 210,                     /* '&'  */
  YYSYMBOL_211_ = 211,                     /* '<'  */
  YYSYMBOL_212_ = 212,                     /* '>'  */
  YYSYMBOL_213_ = 213,                     /* '-'  */
  YYSYMBOL_214_ = 214,                     /* '+'  */
  YYSYMBOL_215_ = 215,                     /* '*'  */
  YYSYMBOL_216_ = 216,                     /* '/'  */
  YYSYMBOL_217_ = 217,                     /* '%'  */
  YYSYMBOL_218_ = 218,                     /* '!'  */
  YYSYMBOL_219_ = 219,                     /* '~'  */
  YYSYMBOL_CAST = 220,                     /* CAST  */
  YYSYMBOL_PPTR = 221,                     /* PPTR  */
  YYSYMBOL_POS = 222,                      /* POS  */
  YYSYMBOL_NEG = 223,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 224,                /* ADDRESSOF  */
  YYSYMBOL_225_ = 225,                     /* '.'  */
  YYSYMBOL_226_ = 226,                     /* '['  */
  YYSYMBOL_227_ = 227,                     /* ']'  */
  YYSYMBOL_228_ = 228,                     /* ';'  */
  YYSYMBOL_229_ = 229,                     /* '{'  */
  YYSYMBOL_230_ = 230,                     /* '}'  */
  YYSYMBOL_231_ = 231,                     /* '('  */
  YYSYMBOL_232_ = 232,                     /* ')'  */
  YYSYMBOL_233_ = 233,                     /* '='  */
  YYSYMBOL_YYACCEPT = 234,                 /* $accept  */
  YYSYMBOL_input = 235,                    /* input  */
  YYSYMBOL_m_acf = 236,                    /* m_acf  */
  YYSYMBOL_decl_statements = 237,          /* decl_statements  */
  YYSYMBOL_decl_block = 238,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 239,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 240,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 241,           /* gbl_statements  */
  YYSYMBOL_242_1 = 242,                    /* $@1  */
  YYSYMBOL_imp_statements = 243,           /* imp_statements  */
  YYSYMBOL_244_2 = 244,                    /* $@2  */
  YYSYMBOL_int_statements = 245,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 246,            /* semicolon_opt  */
  YYSYMBOL_statement = 247,                /* statement  */
  YYSYMBOL_pragma_warning = 248,           /* pragma_warning  */
  YYSYMBOL_warnings = 249,                 /* warnings  */
  YYSYMBOL_typedecl = 250,                 /* typedecl  */
  YYSYMBOL_cppquote = 251,                 /* cppquote  */
  YYSYMBOL_import_start = 252,             /* import_start  */
  YYSYMBOL_import = 253,                   /* import  */
  YYSYMBOL_importlib = 254,                /* importlib  */
  YYSYMBOL_libraryhdr = 255,               /* libraryhdr  */
  YYSYMBOL_library_start = 256,            /* library_start  */
  YYSYMBOL_librarydef = 257,               /* librarydef  */
  YYSYMBOL_m_args = 258,                   /* m_args  */
  YYSYMBOL_arg_list = 259,                 /* arg_list  */
  YYSYMBOL_args = 260,                     /* args  */
  YYSYMBOL_arg = 261,                      /* arg  */
  YYSYMBOL_array = 262,                    /* array  */
  YYSYMBOL_m_attributes = 263,             /* m_attributes  */
  YYSYMBOL_attributes = 264,               /* attributes  */
  YYSYMBOL_attrib_list = 265,              /* attrib_list  */
  YYSYMBOL_str_list = 266,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 267,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 268,             /* contract_ver  */
  YYSYMBOL_contract_req = 269,             /* contract_req  */
  YYSYMBOL_static_attr = 270,              /* static_attr  */
  YYSYMBOL_attribute = 271,                /* attribute  */
  YYSYMBOL_uuid_string = 272,              /* uuid_string  */
  YYSYMBOL_callconv = 273,                 /* callconv  */
  YYSYMBOL_cases = 274,                    /* cases  */
  YYSYMBOL_case = 275,                     /* case  */
  YYSYMBOL_enums = 276,                    /* enums  */
  YYSYMBOL_enum_list = 277,                /* enum_list  */
  YYSYMBOL_enum_member = 278,              /* enum_member  */
  YYSYMBOL_enum = 279,                     /* enum  */
  YYSYMBOL_enumdef = 280,                  /* enumdef  */
  YYSYMBOL_m_exprs = 281,                  /* m_exprs  */
  YYSYMBOL_m_expr = 282,                   /* m_expr  */
  YYSYMBOL_expr = 283,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 284,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 285,           /* expr_int_const  */
  YYSYMBOL_expr_const = 286,               /* expr_const  */
  YYSYMBOL_fields = 287,                   /* fields  */
  YYSYMBOL_field = 288,                    /* field  */
  YYSYMBOL_ne_union_field = 289,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 290,          /* ne_union_fields  */
  YYSYMBOL_union_field = 291,              /* union_field  */
  YYSYMBOL_s_field = 292,                  /* s_field  */
  YYSYMBOL_funcdef = 293,                  /* funcdef  */
  YYSYMBOL_declaration = 294,              /* declaration  */
  YYSYMBOL_m_ident = 295,                  /* m_ident  */
  YYSYMBOL_m_typename = 296,               /* m_typename  */
  YYSYMBOL_typename = 297,                 /* typename  */
  YYSYMBOL_ident = 298,                    /* ident  */
  YYSYMBOL_base_type = 299,                /* base_type  */
  YYSYMBOL_m_int = 300,                    /* m_int  */
  YYSYMBOL_int_std = 301,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 302,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 303,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 304,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 305,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 306,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 307,                  /* coclass  */
  YYSYMBOL_coclassdef = 308,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 309,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 310,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 311,              /* apicontract  */
  YYSYMBOL_apicontract_def = 312,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 313,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 314,         /* class_interfaces  */
  YYSYMBOL_class_interface = 315,          /* class_interface  */
  YYSYMBOL_dispinterface = 316,            /* dispinterface  */
  YYSYMBOL_dispattributes = 317,           /* dispattributes  */
  YYSYMBOL_dispint_props = 318,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 319,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 320,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 321,                  /* inherit  */
  YYSYMBOL_type_parameter = 322,           /* type_parameter  */
  YYSYMBOL_type_parameters = 323,          /* type_parameters  */
  YYSYMBOL_interface = 324,                /* interface  */
  YYSYMBOL_325_3 = 325,                    /* $@3  */
  YYSYMBOL_326_4 = 326,                    /* $@4  */
  YYSYMBOL_delegatedef = 327,              /* delegatedef  */
  YYSYMBOL_328_5 = 328,                    /* $@5  */
  YYSYMBOL_329_6 = 329,                    /* $@6  */
  YYSYMBOL_required_types = 330,           /* required_types  */
  YYSYMBOL_requires = 331,                 /* requires  */
  YYSYMBOL_interfacedef = 332,             /* interfacedef  */
  YYSYMBOL_333_7 = 333,                    /* $@7  */
  YYSYMBOL_interfaceref = 334,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 335,         /* dispinterfaceref  */
  YYSYMBOL_module = 336,                   /* module  */
  YYSYMBOL_moduledef = 337,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 338,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 339,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 340,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 341,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 342,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 343,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 344,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 345,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 346,               /* declarator  */
  YYSYMBOL_direct_declarator = 347,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 348,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 349, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 350,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 351, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 352,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 353, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 354,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 355,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 356,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 357,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 358,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 359,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 360,          /* init_declarator  */
  YYSYMBOL_threading_type = 361,           /* threading_type  */
  YYSYMBOL_pointer_type = 362,             /* pointer_type  */
  YYSYMBOL_structdef = 363,                /* structdef  */
  YYSYMBOL_unqualified_type = 364,         /* unqualified_type  */
  YYSYMBOL_type = 365,                     /* type  */
  YYSYMBOL_typedef = 366,                  /* typedef  */
  YYSYMBOL_uniondef = 367,                 /* uniondef  */
  YYSYMBOL_version = 368,                  /* version  */
  YYSYMBOL_acf_statements = 369,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 370,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 371,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 372,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 373,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 374,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 375,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 376,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 377           /* allocate_option  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
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
#define YYLAST   3579

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  234
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  144
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  893

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   464


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
       2,     2,     2,   218,     2,     2,     2,   217,   210,     2,
     231,   232,   215,   214,   205,   213,   225,   216,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   207,   228,
     211,   233,   212,   206,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   226,     2,   227,   209,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   229,   208,   230,   219,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     220,   221,   222,   223,   224
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   349,   349,   364,   364,   366,   367,   373,   375,   376,
     380,   382,   383,   383,   385,   386,   387,   388,   389,   392,
     395,   396,   398,   399,   401,   402,   403,   404,   407,   408,
     409,   410,   410,   412,   413,   414,   415,   418,   419,   421,
     422,   424,   425,   426,   427,   428,   431,   432,   435,   436,
     440,   441,   442,   443,   444,   445,   446,   449,   457,   465,
     466,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     481,   483,   491,   497,   501,   503,   507,   511,   512,   515,
     516,   519,   520,   524,   529,   536,   540,   541,   544,   545,
     549,   552,   553,   554,   557,   558,   562,   563,   564,   568,
     569,   572,   578,   583,   584,   585,   586,   587,   588,   589,
     590,   591,   592,   593,   594,   595,   596,   597,   598,   599,
     600,   601,   602,   603,   604,   605,   606,   607,   608,   609,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   639,   640,   641,
     642,   643,   644,   645,   646,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   660,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   702,   703,   708,   709,   710,   711,   714,
     715,   718,   722,   728,   729,   730,   733,   737,   749,   754,
     758,   763,   766,   767,   770,   771,   774,   775,   776,   777,
     778,   779,   780,   781,   782,   783,   784,   785,   786,   787,
     788,   789,   790,   791,   792,   793,   794,   795,   796,   797,
     798,   799,   800,   801,   802,   803,   804,   805,   806,   807,
     808,   809,   810,   811,   813,   815,   816,   819,   820,   823,
     829,   835,   836,   839,   844,   851,   852,   855,   856,   860,
     861,   864,   868,   874,   882,   886,   891,   892,   895,   896,
     899,   900,   903,   906,   907,   908,   909,   910,   911,   912,
     913,   914,   915,   916,   919,   920,   923,   924,   925,   926,
     927,   928,   929,   930,   931,   935,   936,   940,   941,   944,
     949,   950,   951,   952,   953,   957,   958,   962,   965,   969,
     972,   976,   979,   983,   986,   987,   991,   992,   995,   998,
    1001,  1002,  1005,  1006,  1010,  1012,  1016,  1017,  1018,  1021,
    1025,  1026,  1030,  1031,  1031,  1031,  1035,  1040,  1041,  1039,
    1048,  1049,  1050,  1051,  1053,  1054,  1057,  1057,  1070,  1074,
    1075,  1079,  1082,  1085,  1090,  1091,  1092,  1096,  1100,  1103,
    1104,  1107,  1108,  1112,  1114,  1118,  1119,  1123,  1124,  1125,
    1129,  1131,  1132,  1136,  1137,  1138,  1139,  1144,  1146,  1147,
    1152,  1154,  1158,  1159,  1164,  1165,  1166,  1167,  1171,  1179,
    1181,  1182,  1187,  1189,  1193,  1194,  1201,  1202,  1203,  1204,
    1205,  1209,  1216,  1217,  1220,  1221,  1224,  1231,  1232,  1237,
    1238,  1242,  1243,  1244,  1245,  1246,  1247,  1251,  1252,  1253,
    1256,  1260,  1261,  1262,  1263,  1264,  1265,  1266,  1267,  1268,
    1269,  1273,  1274,  1275,  1278,  1285,  1287,  1293,  1294,  1295,
    1299,  1300,  1304,  1305,  1309,  1316,  1325,  1326,  1330,  1331,
    1335,  1337,  1338,  1339,  1343,  1344,  1349,  1350,  1351,  1352
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
  "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tACTIVATABLE", "tAGGREGATABLE",
  "tAGILE", "tALLNODES", "tALLOCATE", "tANNOTATION", "tAPICONTRACT",
  "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE",
  "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK",
  "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECLARE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDELEGATE",
  "tDEFAULTCOLLELEM", "tDEFAULTVALUE", "tDEFAULTVTABLE",
  "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME",
  "tDONTFREE", "tDOUBLE", "tDUAL", "tENABLEALLOCATE", "tENCODE",
  "tENDPOINT", "tENTRY", "tENUM", "tERRORSTATUST", "tEVENTADD",
  "tEVENTREMOVE", "tEXCLUSIVETO", "tEXPLICITHANDLE", "tEXTERN", "tFALSE",
  "tFASTCALL", "tFAULTSTATUS", "tFLAGS", "tFLOAT", "tFORCEALLOCATE",
  "tHANDLE", "tHANDLET", "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING",
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
  "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES", "tRESTRICTED", "tRETVAL",
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
  "';'", "'{'", "'}'", "'('", "')'", "'='", "$accept", "input", "m_acf",
  "decl_statements", "decl_block", "imp_decl_statements", "imp_decl_block",
  "gbl_statements", "$@1", "imp_statements", "$@2", "int_statements",
  "semicolon_opt", "statement", "pragma_warning", "warnings", "typedecl",
  "cppquote", "import_start", "import", "importlib", "libraryhdr",
  "library_start", "librarydef", "m_args", "arg_list", "args", "arg",
  "array", "m_attributes", "attributes", "attrib_list", "str_list",
  "marshaling_behavior", "contract_ver", "contract_req", "static_attr",
  "attribute", "uuid_string", "callconv", "cases", "case", "enums",
  "enum_list", "enum_member", "enum", "enumdef", "m_exprs", "m_expr",
  "expr", "expr_list_int_const", "expr_int_const", "expr_const", "fields",
  "field", "ne_union_field", "ne_union_fields", "union_field", "s_field",
  "funcdef", "declaration", "m_ident", "m_typename", "typename", "ident",
  "base_type", "m_int", "int_std", "namespace_pfx", "qualified_type",
  "parameterized_type", "parameterized_type_arg",
  "parameterized_type_args", "coclass", "coclassdef", "runtimeclass",
  "runtimeclass_def", "apicontract", "apicontract_def", "namespacedef",
  "class_interfaces", "class_interface", "dispinterface", "dispattributes",
  "dispint_props", "dispint_meths", "dispinterfacedef", "inherit",
  "type_parameter", "type_parameters", "interface", "$@3", "$@4",
  "delegatedef", "$@5", "$@6", "required_types", "requires",
  "interfacedef", "$@7", "interfaceref", "dispinterfaceref", "module",
  "moduledef", "storage_cls_spec", "function_specifier", "type_qualifier",
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
     455,   456,   457,   458,   459,    44,    63,    58,   124,    94,
      38,    60,    62,    45,    43,    42,    47,    37,    33,   126,
     460,   461,   462,   463,   464,    46,    91,    93,    59,   123,
     125,    40,    41,    61
};
#endif

#define YYPACT_NINF (-643)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-477)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -643,   115,  1791,  -643,   -89,  -643,   -39,   -45,   222,  -643,
    -643,  -643,   222,  -643,     5,   -32,   222,  -643,   288,  -643,
    -643,  -643,  -643,   138,   249,  -643,  -643,  -643,  -643,  -643,
     222,   138,   268,    54,  -643,   222,    97,   138,    39,  -643,
    -643,   301,   369,    39,  -643,  -643,  3380,  -643,  -643,  -643,
    -643,   118,  -643,  -643,  -643,  -643,  -643,    45,  2860,   125,
     143,  -643,  -643,  -643,   372,   149,  -643,   148,  -643,   151,
    -643,   155,  -643,   114,   165,   338,   193,   195,  -643,  -643,
    -643,   207,   207,   207,   126,  3036,   199,  -643,   207,   200,
     201,  -643,    75,  -643,   -45,   316,  -643,  -643,  -643,  -643,
     425,  -643,  -643,   182,   206,  -643,  -643,  -643,   208,   227,
    -643,  -643,    82,  -643,  3036,  -643,  -643,   188,   210,  -103,
     -71,  -643,   209,  -643,   211,  -643,  -643,   213,  -643,  -643,
    -643,   214,   215,  -643,  -643,  -643,  -643,  -643,   216,   220,
    -643,   228,  -643,  -643,  -643,  -643,   233,  -643,  -643,  -643,
     234,  -643,  -643,  -643,   235,   236,  -643,  -643,   240,  -643,
    -643,  -643,  -643,  -643,   242,   243,   244,   245,   247,  -643,
     248,  -643,  -643,   250,  -643,   251,  -643,  -643,   254,   255,
    -643,  -643,   256,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,   258,  -643,  -643,  -643,   262,   269,
    -643,  -643,  -643,  -643,  -643,  -643,   270,  -643,  -643,   272,
    -643,  -643,  -643,   273,  -643,   274,  -643,  -643,   278,   279,
     280,   283,  -643,  -643,  -643,   285,   286,  -643,  -643,   294,
     303,   304,  -106,  -643,  -643,  -643,  1937,  1114,  3036,   311,
     377,   222,   222,   381,   385,   212,   225,   312,   319,   323,
    -643,   324,   126,   252,   271,  -643,   315,   343,  3098,  -643,
    -643,  -643,  -643,  -643,   326,  -643,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,   126,   126,  -643,
    -643,   325,  -107,  -643,  -643,  -643,   207,  -643,  -643,  -643,
     328,  -643,  -643,  -643,   -51,  -643,  -643,   555,   331,   -34,
     -48,  -643,  -643,   360,   361,   345,  -643,   348,  -643,  2931,
     571,   314,   222,   725,  2931,   581,   314,   725,   579,   580,
     725,  2931,   725,   583,   584,   725,   585,   725,   725,  2377,
     725,   725,    59,   592,   -60,   593,   725,  3036,   725,  2931,
     725,  3036,   -36,  3036,  3036,   314,   419,   595,  3036,  3380,
     379,  -643,   378,   375,  -643,  -643,  -643,  -643,   387,  -643,
     389,  -643,   390,  -643,   384,   391,   395,  -643,  -643,  -643,
     193,   222,  2931,  -643,   393,  -643,  -643,   393,   -70,  -643,
    -643,  -643,   396,   417,  -643,  -643,  -643,  -643,   372,   102,
     412,  -643,   -95,  -643,   -10,   174,   406,  -643,   725,   137,
    2377,  -643,  -643,    30,    75,  -643,   399,  -643,   394,  -643,
     222,   409,   435,   408,  -643,   222,   636,   636,  -643,   -17,
     311,    94,   411,   439,   413,  -643,  -643,   428,   430,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,   432,  -643,
     725,   725,   725,   725,   725,   725,   923,  2615,  -110,  -643,
     433,   444,   438,   466,  2615,   442,   443,  -643,  -102,   447,
     448,   449,   451,   452,   454,   459,   461,   859,   462,  2931,
     217,   463,   -91,  -643,  2615,  -643,  -643,  -643,   464,   469,
     471,   472,   468,   474,   -49,   480,   473,  2291,   482,  -643,
    -643,  -643,  -643,  -643,  -643,   484,   485,   486,   487,   496,
    -643,   492,   493,   494,  -643,  3380,  -643,   667,  -643,  -643,
    -643,  -643,  -643,  -643,  -643,    -3,   126,   108,   109,   193,
     394,   537,  1466,  -643,  -643,  -643,  3098,  -643,  1330,   520,
     -38,   501,  -643,  -643,  -643,  -643,   575,  -643,  2461,   498,
     532,  -643,  -643,  -643,  -643,  -643,  -643,   -25,  -643,  -643,
     553,   528,  -643,  -643,   132,   725,  -643,  -643,   535,  -643,
      46,    49,  -643,  2931,  -643,  2931,   509,  -643,   514,  -643,
     515,  -643,   581,  -643,  -643,  -643,  3117,    43,    43,    43,
      43,    43,    43,  -643,  2376,   446,  3222,   207,   725,   725,
     741,   725,   725,   725,   725,   725,   725,   725,   725,   725,
     725,   725,   725,   725,   725,   725,   725,   725,   743,   725,
     725,  -643,  -643,   742,  -643,   725,  -643,  -643,   738,  -643,
    -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,  -643,
     217,  -643,  2029,  -643,   217,  -643,  -643,  -643,    53,  -643,
     725,  -643,  -643,  -643,  -643,  -643,   725,  -643,  -643,  -643,
    2931,  -643,  -643,  -643,  -643,  -643,  -643,   744,  -643,  -643,
    -643,  -643,   -27,   517,  -643,  -643,  2377,  -643,   547,   193,
      24,  -643,   193,  -643,   149,  -643,   394,   524,   193,  -643,
     570,  2931,  -643,  -643,  -643,   550,   530,  1668,   531,  -643,
    -643,  -643,  2246,    30,  -643,   534,   533,   553,  3098,  -643,
    -643,   222,   552,  -643,  -643,  -643,   217,   538,   126,   135,
     222,  -643,  -643,  -643,   446,  -643,  -643,  2175,  -643,   446,
    -643,   541,    77,   207,  -643,   383,   383,  -643,   441,   441,
     281,   281,  2542,  2634,  2594,  2664,  1033,  1463,   281,   281,
     187,   187,    43,    43,    43,  -643,  2509,  -643,  -643,   542,
    -643,  -643,   170,  -643,   544,   217,   545,  -643,  2377,  -643,
    -643,   559,  -643,  -643,   394,  -643,   193,  1259,   222,   560,
     126,  -643,   222,   394,   551,   554,  -643,   149,  -643,   557,
    -643,  -643,  -643,  -643,  -643,  2931,   556,  -643,  -643,  -643,
    -643,  -643,   765,  -643,  -643,   -94,  -643,  -643,   588,  -643,
     -93,  -643,  -643,   558,  -643,   564,   293,  -643,   565,   217,
     566,  -643,   725,  2377,  -643,  -643,   725,  -643,  -643,  -643,
     170,  -643,  -643,  -643,   567,  -643,   589,  -643,  -643,   -92,
     193,  -643,  -643,  -643,   372,  -643,  -643,   394,  1537,  -643,
     573,   576,   725,  -643,   217,  -643,  -643,  -643,  -643,   170,
    -643,  -643,  -643,    43,   578,  2615,  -643,  -643,  3098,   572,
    -643,  -643,   149,  -643,   193,  -643,  -643,  -643,  -643,    36,
    -643,  -643,    55,  2377,  -643,   725,   598,  -643,  -643,   586,
     597,   600,   194,  -643,  -643,   194,  -643,  -643,   587,   193,
    -643,  -643,  -643
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   300,    55,   460,   470,     0,   311,
     303,   322,     0,   388,     0,     0,     0,   310,   298,   312,
     384,   309,   313,   314,     0,   387,   316,   323,   324,   321,
       0,   314,     0,     0,   386,     0,     0,   314,     0,   318,
     385,   298,   298,   308,   451,   304,   103,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   453,
       0,   327,   452,   305,     0,     0,   463,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   395,   395,   395,     0,     0,   455,   461,   395,     0,
     457,   325,     0,     4,   470,     0,   300,   301,   341,   337,
       0,     5,   348,   454,     0,   299,   315,   320,     0,   362,
     319,   343,     0,   339,     0,   317,   306,   456,     0,   458,
       0,   307,     0,   105,     0,   107,   108,     0,   109,   110,
     111,     0,     0,   114,   115,   116,   117,   118,     0,     0,
     121,     0,   123,   124,   125,   126,     0,   128,   129,   130,
       0,   132,   133,   134,     0,     0,   137,   138,     0,   140,
     141,   142,   143,   144,     0,     0,     0,     0,     0,   150,
       0,   152,   153,     0,   155,     0,   157,   158,   161,     0,
     162,   163,     0,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,     0,   177,   178,   179,     0,     0,
     182,   183,   184,   185,   449,   186,     0,   188,   447,     0,
     190,   191,   192,     0,   194,     0,   196,   197,     0,     0,
       0,     0,   202,   448,   203,     0,     0,   207,   208,     0,
       0,     0,     0,    91,   212,    51,    88,    88,     0,    88,
     298,     0,     0,   298,   298,     0,   453,     0,     0,     0,
     376,     0,     0,   455,   457,    52,   300,   462,     0,    18,
      22,    20,    12,    15,     0,    49,   378,    14,   399,   396,
     398,   397,   215,   216,   217,   218,   389,     0,     0,   302,
     403,   439,   402,   295,   453,   455,   395,   457,   391,    54,
       0,   482,   481,   483,     0,   478,   471,     0,     0,     0,
      88,    71,   363,     0,     0,     0,   281,     0,   287,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   234,     0,     0,     0,     0,     0,     0,   234,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
      90,    72,     0,     0,    45,    42,    43,    44,     0,    36,
       0,    40,     0,    38,     0,     0,     0,    34,    33,    41,
      48,     0,     0,    89,   454,    74,   382,   456,   458,    75,
     344,   344,     0,   356,    46,   294,   326,   330,     0,   331,
     333,   335,     0,    11,     0,     0,     0,   401,     0,     0,
      77,   405,   392,     0,     0,   477,     0,    70,     0,     7,
       0,     0,   225,   230,   226,     0,     0,     0,   459,    88,
      88,    88,     0,     0,     0,   214,   213,     0,     0,   245,
     236,   237,   238,   242,   243,   244,   239,   240,     0,   241,
       0,     0,     0,     0,     0,     0,     0,   279,     0,   277,
       0,    99,     0,     0,   280,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     424,     0,     0,   232,   235,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   446,
     441,   442,   443,   444,   445,     0,     0,     0,     0,   467,
     469,     0,     0,     0,    92,   103,     8,     0,    35,    39,
      37,    31,    30,    29,    76,     0,     0,    88,    88,    48,
       0,   374,    88,   328,   332,   334,     0,   329,    88,     0,
      88,     0,   390,   400,   404,   440,     0,    87,     0,     0,
      81,    78,    79,   488,   486,   489,   487,     0,   484,   479,
     472,     0,   228,   231,    88,     0,   359,   360,   364,    59,
       0,     0,   450,     0,   282,     0,     0,   465,    89,   288,
       0,   104,     0,   106,   206,   112,     0,   269,   268,   267,
     270,   265,   266,   460,     0,   412,     0,   395,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   119,     0,   120,     0,   127,   131,     0,   135,
     136,   139,   145,   146,   147,   148,   149,   151,   154,   156,
     424,   389,    77,   429,   424,   426,   425,    84,   421,   160,
     234,   159,   164,   176,   180,   181,     0,   189,   193,   195,
       0,   198,   199,   201,   200,   204,   205,     0,   209,   210,
     211,    93,     0,     0,    28,   367,    77,   432,   464,    48,
       0,   345,    48,   342,   357,   358,     0,     0,    48,    47,
       0,    89,   336,    13,   350,     0,     0,     0,     0,    86,
      85,   406,     0,     0,   480,   476,     0,   472,     0,   227,
     229,     0,     0,    60,    57,    58,     0,   457,     0,   455,
     296,   286,   285,   101,   412,   276,   389,    77,   416,   412,
     413,     0,   409,   395,   393,   258,   259,   271,   252,   253,
     256,   257,   247,   248,     0,   249,   250,   251,   255,   254,
     261,   260,   263,   264,   262,   272,     0,   278,   100,     0,
      95,    83,   424,   389,     0,   424,     0,   420,    77,   428,
     233,     0,   102,   468,     0,    10,    48,    88,     0,     0,
       0,   338,     0,     0,     0,     0,   340,   370,   371,   375,
      46,   383,   352,   351,   354,     0,     0,   293,   355,    82,
      80,   485,     0,   475,   473,     0,   361,   365,   434,   437,
       0,   284,   291,     0,   297,     0,   412,   389,     0,   424,
       0,   408,     0,    77,   415,   394,     0,   275,   122,   419,
     424,   430,   423,   427,     0,   187,     0,    73,    32,     0,
      48,   433,   381,   379,     0,   346,   347,     0,    88,   353,
       0,     0,     0,   436,     0,   283,   219,   274,   407,   424,
     417,   411,   414,   273,     0,   246,   422,   431,     0,     0,
     366,   380,   372,   373,    48,   474,     6,   435,   438,     0,
     410,   418,     0,    77,   377,     0,     0,   466,   220,     0,
       0,     0,    88,     9,   368,    88,   290,   222,     0,    48,
     221,   289,   369
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -643,  -643,  -643,  -643,  -643,  -643,  -643,   420,  -643,   -50,
    -643,    32,  -254,     0,  -643,   400,  -643,  -643,  -643,  -643,
    -643,  -643,  -643,    28,  -584,  -643,  -643,  -323,  -231,  -235,
      -2,  -643,  -643,  -643,   246,  -291,  -643,  -281,  -222,   -83,
    -643,  -643,  -643,  -643,  -643,   266,    16,   478,   181,   382,
    -643,  -280,  -271,  -643,  -643,  -643,  -643,   -54,  -331,  -643,
     145,  -643,    20,    -1,   -62,  -238,   124,   163,  -246,  -221,
    -226,   308,  -641,    17,    29,    19,    33,    22,    34,    37,
     456,  -643,    23,  -643,  -643,  -643,  -643,  -643,   129,    67,
      14,  -643,  -643,    41,  -643,  -643,  -643,  -643,    42,  -643,
    -643,  -643,  -643,    44,  -643,  -643,  -357,  -553,     1,   264,
     -74,   -55,  -224,  -643,  -643,  -643,  -613,  -643,  -642,  -643,
    -563,  -643,  -643,  -643,     3,  -643,   590,  -643,   507,     8,
    -314,   -12,  -643,    11,  -643,   750,   153,  -643,  -643,   150,
    -643,   453,  -643,   158
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    47,   299,    48,   662,   354,     2,   393,   236,
     664,   522,   266,   355,    50,   560,    51,    52,    53,    54,
     356,   245,    55,   357,   539,   540,   541,   542,   633,    57,
     373,   232,   458,   478,   452,   422,   485,   233,   427,   634,
     869,   878,   411,   412,   413,   414,   284,   472,   473,   447,
     448,   449,   455,   419,   564,   569,   421,   887,   888,   786,
      60,   803,   104,    61,   635,    62,   107,    63,    64,    65,
      66,   391,   392,   358,   359,   360,   361,   362,   363,   364,
     517,   671,   365,    75,   530,   687,    76,   521,   557,   558,
     366,   415,   702,   367,   768,   889,   779,   677,   368,   383,
     774,   775,   251,   369,    81,    82,    83,   395,   470,   585,
     268,    85,   281,   282,   720,   810,   721,   722,   636,   756,
     637,   638,   668,   843,   799,   800,   283,   495,   234,   285,
      87,    88,    89,   287,   501,    93,   696,   697,    94,    95,
     294,   295,   547,   548
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,   278,    49,    84,   372,   237,   468,    98,   270,   271,
      86,    99,   388,    90,   288,   102,    77,   105,    59,    67,
     387,    69,   280,   450,    71,    74,   269,   269,   269,   109,
      56,    68,   390,   269,   113,    70,    72,   389,   532,    73,
     105,   105,   461,    78,    79,   464,    80,   466,   754,   459,
     471,   401,   703,   396,   397,   703,   482,   795,   543,   252,
     590,   118,   120,   257,   798,   410,   253,   751,   504,   254,
    -476,   757,   250,   286,   246,   247,  -300,   248,   752,   875,
     249,   408,   769,   279,    11,   303,   475,   685,   764,   566,
     570,   489,   772,   204,   453,   610,   876,   208,   264,   349,
     544,   805,   305,   618,   290,    30,   811,   238,   307,  -300,
     526,   526,   844,   701,   640,     3,   514,   527,   841,   399,
     859,   350,   611,   498,   400,   -66,  -300,   535,   223,    96,
     619,    97,   587,   808,   291,   845,    91,    23,   529,   773,
     429,   641,   304,   430,   431,   432,   433,   434,   435,   292,
      26,    27,    28,    29,   404,   110,   640,   293,   308,  -300,
      31,   115,   388,   806,   490,   491,   492,   493,   494,   278,
     272,   533,  -301,    96,   824,    97,   405,    96,    46,    97,
     693,    92,  -223,   648,   563,   565,   565,   551,    46,   819,
     280,   476,   822,   848,   278,   278,   409,   101,   545,   686,
     820,   116,   798,   765,   590,    37,   121,   694,   665,    46,
      39,   273,   402,   562,   272,   280,   280,   872,   272,    13,
      96,   436,    97,    13,   661,    96,   371,    97,   666,   854,
     239,   269,   477,   546,    58,    58,   100,    84,    84,   105,
     375,   376,   105,   105,    86,    86,   851,    90,    90,   106,
     428,   279,    59,    59,   849,   273,    13,   856,   108,   273,
     526,   272,   587,   118,   120,   673,   877,   879,   608,   609,
     274,   111,   723,   437,   388,   700,   279,   279,   704,   399,
     388,   705,   670,   670,   758,   112,   870,   680,   387,   880,
      20,   103,   667,    97,   675,   565,   588,   589,   590,   674,
     390,   275,   273,   399,   117,   389,    97,   438,   813,   515,
     423,   279,   278,   258,   274,   423,    25,   524,   274,   410,
      46,   439,   460,   425,   567,   483,   426,   469,   114,   488,
     747,   496,   497,   280,    46,    46,   503,   272,   669,   672,
     486,   276,    13,   262,   749,   275,   235,   440,   552,   275,
     441,   442,   536,   -61,   718,   444,   445,   277,    46,   762,
     258,   274,  -224,  -292,   537,    34,   761,  -292,   446,   790,
     279,   255,   119,   516,    97,   256,   259,    97,   273,   260,
     374,    40,    97,   261,   377,   631,    97,   523,   378,   276,
      97,   586,   275,   263,   279,   532,   399,     4,   469,    97,
     590,   632,   605,   606,   607,   277,    16,   759,   531,   279,
     -62,  -300,   608,   609,   556,   771,   -64,  -300,   776,   568,
      46,   265,   886,   267,   781,   499,   500,   -63,   289,   -65,
     388,   297,   631,   278,   298,   300,   301,   274,   302,   306,
     309,   379,   310,   399,   311,   312,   313,   314,   632,   532,
     778,   315,   388,   -67,   280,   777,   588,   589,   590,   316,
     387,   593,   594,   532,   317,   318,   319,   320,   275,   279,
     630,   321,   390,   322,   323,   324,   325,   389,   326,   327,
     -68,   328,   329,   718,   802,   330,   331,   332,   718,   333,
     272,   814,   532,   334,   603,   604,   605,   606,   607,   -69,
     335,   336,   719,   337,   338,   339,   608,   609,   716,   340,
     341,   342,   827,   724,   343,   279,   344,   345,   388,   399,
     681,   586,   679,    84,   717,   346,    58,   834,    49,    84,
      86,   273,   269,    90,   347,   348,    86,    46,    59,    90,
     386,   380,    77,   826,    59,    67,   831,    69,   381,   755,
      71,    74,   382,   384,  -328,   394,    56,    68,   398,   403,
     406,    70,    72,   407,   706,    73,   708,   416,   417,    78,
      79,   867,    80,   709,   707,   718,   860,   418,   429,   420,
     424,   430,   431,   432,   433,   434,   435,   451,   456,   457,
     274,   388,   462,   463,   465,   881,   603,   604,   605,   606,
     607,   479,   481,   680,   502,   505,   507,   506,   608,   609,
     874,   863,   388,   511,   767,   508,   862,   509,   510,   512,
     387,   275,  -300,   513,   520,   278,   519,   525,   550,   279,
     469,   719,   390,   279,   809,   892,   719,   389,   534,   553,
     554,   555,   559,   571,   572,   573,   280,   565,   804,   815,
     565,   423,   601,   602,   603,   604,   605,   606,   607,   436,
     574,   716,   575,   576,   469,   612,   608,   609,   269,   613,
     614,   615,   399,   646,   616,   617,   663,   717,   650,   620,
     621,   622,   252,   623,   624,   785,   625,   278,    84,   253,
     469,   626,   254,   627,   629,   639,   642,   246,   676,   454,
     556,   643,   454,   644,   645,   279,   647,   279,   280,   279,
     467,   437,   649,   474,   652,   469,   653,   654,   655,   656,
     474,   657,   487,   719,   658,   659,   660,   684,   429,   688,
     691,   430,   431,   432,   433,   434,   435,   692,   695,   698,
     701,   710,   711,   712,   727,   438,   745,   750,   748,   766,
     763,   279,   770,   780,   279,   239,   469,   782,   783,   439,
      92,   788,   837,   793,   797,    58,   801,   556,    84,   279,
     840,   832,   833,   812,   818,    86,   821,   823,    90,   835,
     454,   538,   836,    59,   839,   440,   252,   846,   441,   442,
     443,   825,   830,   444,   445,   842,   847,   850,   852,   857,
     858,   865,   689,   873,   866,   882,   446,   885,   279,   436,
     871,   469,   838,   528,   883,   891,   484,   561,   713,   279,
     699,   760,   577,   578,   579,   580,   581,   582,   584,   884,
     796,   890,   787,   861,   682,   829,   681,   518,   679,    84,
     714,   480,   385,   279,   296,   792,    86,   868,   279,    90,
     794,   791,     0,     0,    59,     0,     0,   549,     0,     0,
       0,   437,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   469,     0,     0,   588,   589,   590,   591,   592,   593,
     594,   595,   596,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   438,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   439,
       0,     0,     0,     0,     0,     0,     0,     0,   580,     0,
       0,     0,     0,     0,     0,     0,   429,     0,   583,   430,
     431,   432,   433,   434,   435,   440,     0,     0,   441,   442,
     443,     0,     0,   444,   445,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   446,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    11,     0,
     725,   726,    13,   728,   729,   730,   731,   732,   733,   734,
     735,   736,   737,   738,   739,   740,   741,   742,   743,   744,
       0,   746,     0,     0,    17,     0,     0,   454,     0,     0,
     240,    19,     0,     0,     0,     0,    20,   436,     0,     0,
       0,    21,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    23,   474,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,   588,   589,
     590,   591,   592,   593,   594,     0,     0,     0,     0,   437,
       0,     0,     0,     0,     0,   597,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,     0,     0,     0,
       0,    34,     0,     0,   608,   609,     0,     0,    36,    37,
      38,   628,     0,   438,    39,     0,     0,    40,     0,     0,
       0,   243,     0,     0,     0,     0,     0,   439,     0,     0,
     244,     0,    43,     0,     0,     0,     0,     4,     5,     6,
      44,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   440,     0,     0,   441,   442,   443,     0,
       0,   444,   445,     0,     0,     8,     0,     0,     0,     0,
       0,     9,     0,    10,   446,     0,     0,     0,     0,    11,
      12,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      14,     0,   352,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,   853,     0,     0,    20,   855,     0,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
     353,     0,     0,    25,   454,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,   600,   601,   602,   603,   604,   605,   606,
     607,     0,     0,     0,     0,     0,     0,     0,   608,   609,
      33,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,    35,    36,
      37,    38,     0,     0,     0,    39,     0,     0,    40,     0,
       8,     0,    41,     0,     0,     0,     9,     0,    10,     0,
       0,    42,     0,    43,    11,    12,     0,     0,    13,     0,
       0,    44,    45,     0,     0,    14,     0,   352,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
      17,     0,     0,     4,     5,     6,    18,    19,     0,     0,
      46,     0,    20,     0,   370,     0,     0,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       0,     8,     0,     0,    24,   353,     0,     9,    25,    10,
      26,    27,    28,    29,    30,    11,    12,     0,     0,    13,
      31,     0,     0,     0,     0,     0,    14,    32,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
       0,    17,     0,     0,     0,    33,     0,    18,    19,     0,
       0,     0,     0,    20,     0,     0,     0,    34,    21,     0,
       0,    22,     0,    35,    36,    37,    38,     0,    23,     0,
      39,     0,     0,    40,     0,    24,     0,    41,     0,    25,
       0,    26,    27,    28,    29,    30,    42,     0,    43,     0,
       0,    31,     0,     0,     0,     0,    44,    45,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     0,     0,     0,     0,    33,     0,   588,   589,
     590,   591,   592,   593,   594,    46,     0,     0,    34,   828,
       0,     0,     0,     0,    35,    36,    37,    38,     0,     0,
       0,    39,     0,     9,    40,    10,     0,     0,    41,     0,
       0,    11,     0,     0,     0,    13,     0,    42,     0,    43,
       0,     0,    14,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       4,     5,     6,    18,    19,     0,     0,     0,     0,    20,
       0,     0,     0,     0,    21,     0,    46,    22,     0,     0,
     683,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     9,    25,    10,    26,    27,    28,
      29,     0,    11,     0,     0,     0,    13,    31,     0,     0,
       0,     0,     0,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    33,     0,    18,    19,     0,     0,     0,     0,
      20,     0,     0,     0,    34,    21,     0,     0,    22,     0,
       0,    36,    37,    38,     0,    23,     0,    39,     0,     0,
      40,     0,    24,     0,    41,     0,    25,     0,    26,    27,
      28,    29,     0,    42,     0,    43,     0,     0,    31,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     4,     0,     6,   601,   602,   603,   604,   605,   606,
     607,     0,     0,    33,     0,     0,     0,     0,   608,   609,
       0,     0,    46,     0,     0,    34,   678,     0,     0,     0,
       0,     0,    36,    37,    38,     9,     0,    10,    39,     0,
       0,    40,     0,    11,     0,    41,     0,    13,     0,     0,
       0,     0,     0,     0,    42,     0,    43,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    17,
       0,     0,     0,     0,     0,   240,    19,     0,     0,     0,
       0,    20,     0,     0,     0,     0,    21,     0,     0,    22,
       0,     0,     0,    46,     0,     0,    23,   864,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,    31,
       0,    -3,     0,     0,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,     0,     0,    34,     0,     9,     0,
      10,     0,     0,    36,    37,    38,    11,    12,     0,    39,
      13,     0,    40,     0,     0,     0,   243,    14,     0,    15,
       0,     0,     0,     0,     0,   244,     0,    43,     0,    16,
       0,     0,    17,     0,     0,    44,    45,     0,    18,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,    46,     0,    24,     0,   784,     0,
      25,     0,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       4,     5,     6,     0,     0,     0,     0,     0,     0,    34,
     351,     0,     0,     0,     0,    35,    36,    37,    38,     0,
       0,     0,    39,     0,     0,    40,     0,     0,     8,    41,
       0,     0,     0,     0,     9,     0,    10,     0,    42,     0,
      43,     0,    11,    12,     0,     0,    13,     0,    44,    45,
       0,     0,     0,    14,     0,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,    17,     0,
       0,     0,     0,     0,    18,    19,     0,    46,     0,     0,
      20,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     4,     0,     6,    23,     0,     0,     0,     0,
       0,     0,    24,   353,     0,     0,    25,     0,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    32,     9,     0,    10,     0,
       0,     0,     0,   272,    11,     0,     0,     0,    13,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
      17,    35,    36,    37,    38,     0,   240,    19,    39,     0,
       0,    40,    20,     0,   273,    41,     0,    21,     0,     0,
      22,     0,     0,     0,    42,     0,    43,    23,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,    25,     0,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    46,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   274,     0,     0,     0,     0,     4,     0,
       6,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,     0,
      39,     0,     0,    40,   275,     0,     0,   243,     0,     0,
       0,     0,     9,     0,    10,     0,   244,     0,    43,   272,
      11,     0,     0,     0,    13,     0,    44,    45,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   753,     0,    17,     0,     0,     4,
       0,     6,   240,    19,     0,    46,     0,     0,    20,     0,
     273,     0,     0,    21,     0,     0,    22,     0,     0,     0,
     789,     0,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    25,    10,    26,    27,    28,    29,
       0,    11,     0,     0,     0,    13,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   588,   589,   590,   591,
     592,   593,   594,   595,   596,     0,     0,    17,     0,   274,
       0,     0,     0,   240,    19,     0,     0,     0,     0,    20,
       0,     0,     0,    34,    21,     0,     0,    22,     0,     0,
      36,    37,    38,     0,    23,     0,    39,     0,     0,    40,
     275,     0,     0,   243,     0,    25,     0,    26,    27,    28,
      29,     0,   244,     0,    43,     0,     0,    31,     0,     0,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
       4,     0,     6,     0,     0,     0,     0,     0,     0,     0,
     807,   588,   589,   590,   591,   592,   593,   594,   595,   596,
       0,    46,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     9,     0,    10,    39,     0,     0,
      40,     0,    11,     0,   243,     0,    13,     0,     0,     0,
       0,     0,     0,   244,     0,    43,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,    17,     0,
       0,     0,     0,     0,   240,    19,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,    46,     0,     0,    23,   588,   589,   590,   591,
     592,   593,   594,   595,   596,     0,    25,     0,    26,    27,
      28,    29,     0,     0,     0,     0,     0,   597,    31,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,     0,
       0,     0,     0,     0,     0,     0,   608,   609,     0,     0,
       0,     0,     0,   651,   588,   589,   590,   591,   592,   593,
     594,   595,   596,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    39,     0,
       0,    40,     0,     0,     0,   243,     0,   588,   589,   590,
     591,   592,   593,   594,   244,   596,    43,     0,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,     0,
       0,     0,   597,     0,   598,   599,   600,   601,   602,   603,
     604,   605,   606,   607,     0,     0,     0,     0,     0,     0,
       0,   608,   609,    46,     0,     0,     0,     0,   715,   588,
     589,   590,   591,   592,   593,   594,   595,   596,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     588,   589,   590,   591,   592,   593,   594,   595,   596,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   588,
     589,   590,   591,   592,   593,   594,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   597,     0,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   588,
     589,   590,   591,   592,   593,   594,   608,   609,   690,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   597,     0,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,     0,     0,     0,
       0,     0,     0,     0,   608,   609,   817,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
       0,     0,     0,     0,     0,     0,     0,   608,   609,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     597,   816,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,     0,     0,     0,     0,     0,     0,     0,   608,
     609,   597,     0,   598,   599,   600,   601,   602,   603,   604,
     605,   606,   607,     0,     0,     0,     0,     0,     0,     0,
     608,   609,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,     0,     0,     0,     0,     0,     0,     0,   608,
     609,     0,     0,     4,     0,     6,     0,     0,     0,     0,
       0,     0,     0,   599,   600,   601,   602,   603,   604,   605,
     606,   607,     0,     0,     0,     0,     0,     0,     0,   608,
     609,     8,     0,     0,     0,     0,     0,     9,     0,    10,
       0,     0,     0,     0,     0,    11,    12,     0,     0,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -349,     0,
       0,    17,     0,     0,     4,     0,     6,   240,    19,     0,
       0,     0,     0,    20,     0,     0,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    25,
      10,    26,    27,    28,    29,    30,    11,     0,   241,     0,
      13,    31,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,   240,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    34,    21,
       0,     0,    22,     0,    35,    36,    37,    38,     0,    23,
       0,    39,     0,     0,    40,     0,     0,     0,   243,     4,
      25,     6,    26,    27,    28,    29,     0,   244,     0,    43,
       0,     0,    31,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,    36,    37,    38,     0,
       0,     4,    39,    97,     0,    40,     0,    17,     0,   243,
       0,     0,     0,   240,    19,     0,     0,     0,   244,     0,
      43,     0,   583,     0,    21,     0,     0,    22,    44,    45,
       0,     0,     0,     0,    23,     9,     0,    10,     0,     0,
       0,     0,     0,    11,     0,     0,     0,    26,    27,    28,
      29,     0,     0,     0,     9,     0,    10,    31,     0,     0,
       0,     0,    11,     0,     0,     0,    13,     0,     0,    17,
       0,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,    17,    22,
       0,     0,     0,     0,   240,    19,    23,     0,     0,     0,
      20,    36,    37,    38,     0,    21,     0,    39,    22,    26,
      27,    28,    29,     0,   243,    23,     0,     0,     0,    31,
       0,     0,     0,   244,     0,    43,    25,   583,    26,    27,
      28,    29,     0,    44,    45,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     9,
       0,    10,     0,     0,    37,    38,     0,    11,     0,    39,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,    43,    39,     0,
       0,    40,     0,    17,     0,   243,    45,     0,     0,   240,
      19,     0,     0,     0,   244,     0,    43,     0,     0,     0,
      21,     0,     0,    22,    44,    45,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,    39,     0,     0,     0,     0,     0,     0,
     243,     0,     0,     0,     0,   122,   123,     0,     0,   244,
     124,    43,   125,   126,   127,   128,   129,     0,   130,    44,
      45,   131,     0,   132,     0,     0,     0,   133,   134,     0,
     135,   136,   137,   138,   139,   140,     0,   141,     0,   142,
     143,   144,     0,   145,   146,   147,   148,   149,     0,   150,
       0,     0,   151,   152,   153,   154,   155,     0,     0,   156,
     157,   158,   159,     0,     0,     0,   160,   161,     0,   162,
     163,     0,   164,   165,   166,   167,   168,   169,     0,   170,
     171,   172,   173,   174,   175,     0,     0,   176,     0,     0,
     177,     0,     0,     0,     0,     0,   178,   179,     0,   180,
     181,     0,   182,   183,   184,     0,     0,     0,     0,   185,
     186,   187,     0,   188,   189,   190,     0,   191,   192,   193,
     194,   195,   196,   197,     0,   198,     0,   199,     0,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,     0,   211,   212,     0,     0,     0,     0,     0,   213,
       0,     0,   214,     0,   215,     0,   216,   217,     0,     0,
     218,   219,   220,   221,     0,     0,   222,     0,   223,     0,
     224,   225,   226,   227,   228,   229,   230,     0,     0,   231
};

static const yytype_int16 yycheck[] =
{
       2,    84,     2,     2,   239,    55,   329,     8,    82,    83,
       2,    12,   258,     2,    88,    16,     2,    18,     2,     2,
     258,     2,    84,   314,     2,     2,    81,    82,    83,    30,
       2,     2,   258,    88,    35,     2,     2,   258,   395,     2,
      41,    42,   322,     2,     2,   325,     2,   327,   632,   320,
     330,   282,     6,   277,   278,     6,   336,   698,    28,    58,
      17,    41,    42,    64,   706,   300,    58,   630,   349,    58,
     115,   634,    58,    85,    58,    58,   179,    58,   631,    43,
      58,   115,   666,    84,    45,     3,    27,   125,   115,   420,
     421,   127,    68,   153,   316,   205,    60,   157,    75,   205,
      70,   714,   114,   205,    29,   115,   719,    62,   179,   179,
     205,   205,   205,   205,   205,     0,   370,   212,   212,   226,
     212,   227,   232,   345,   231,   228,   229,   398,   188,     3,
     232,     5,   446,   717,    59,   228,   225,    98,   148,   115,
       3,   232,    60,     6,     7,     8,     9,    10,    11,    74,
     111,   112,   113,   114,   205,    31,   205,    82,   229,   229,
     121,    37,   408,   716,   200,   201,   202,   203,   204,   252,
      44,   395,   211,     3,   758,     5,   227,     3,   226,     5,
     205,   226,   230,   232,   419,   420,   421,   408,   226,   752,
     252,   132,   755,   806,   277,   278,   230,   229,   168,   530,
     753,    38,   844,   230,    17,   166,    43,   232,   211,   226,
     171,    85,   286,   230,    44,   277,   278,   858,    44,    49,
       3,    84,     5,    49,   505,     3,   238,     5,   231,   813,
     185,   286,   173,   203,   236,   237,   231,   236,   237,   240,
     241,   242,   243,   244,   236,   237,   809,   236,   237,   111,
     312,   252,   236,   237,   807,    85,    49,   820,     9,    85,
     205,    44,   576,   243,   244,   519,   230,   212,   225,   226,
     144,     3,   586,   136,   520,   555,   277,   278,   232,   226,
     526,   232,   517,   518,   231,   231,   849,   522,   526,   873,
      83,     3,   516,     5,   520,   530,    15,    16,    17,   520,
     526,   175,    85,   226,     3,   526,     5,   170,   231,   371,
     309,   312,   395,   211,   144,   314,   109,   215,   144,   554,
     226,   184,   321,     9,   230,   337,    12,   329,   231,   341,
     610,   343,   344,   395,   226,   226,   348,    44,   230,   230,
     339,   215,    49,   229,   615,   175,   228,   210,   410,   175,
     213,   214,   215,   228,   585,   218,   219,   231,   226,   650,
     211,   144,   230,   228,   227,   158,   646,   232,   231,   692,
     371,   228,     3,   372,     5,     3,   228,     5,    85,   228,
       3,   174,     5,   228,     3,   215,     5,   388,     3,   215,
       5,   446,   175,   228,   395,   752,   226,     3,   400,     5,
      17,   231,   215,   216,   217,   231,    68,   638,   394,   410,
     228,   229,   225,   226,   415,   669,   228,   229,   672,   421,
     226,   228,   228,   228,   678,     6,     7,   228,   228,   228,
     676,   115,   215,   516,     9,   229,   228,   144,   211,   229,
     231,   229,   231,   226,   231,   231,   231,   231,   231,   806,
     676,   231,   698,   228,   516,   676,    15,    16,    17,   231,
     698,    20,    21,   820,   231,   231,   231,   231,   175,   470,
     469,   231,   698,   231,   231,   231,   231,   698,   231,   231,
     228,   231,   231,   714,   708,   231,   231,   231,   719,   231,
      44,   722,   849,   231,   213,   214,   215,   216,   217,   228,
     231,   231,   585,   231,   231,   231,   225,   226,   215,   231,
     231,   231,   766,   587,   231,   516,   231,   231,   764,   226,
     522,   576,   522,   522,   231,   231,   528,   773,   528,   528,
     522,    85,   587,   522,   231,   231,   528,   226,   522,   528,
     225,   229,   528,   764,   528,   528,   770,   528,   229,   632,
     528,   528,   229,   229,   211,   229,   528,   528,   233,   231,
       5,   528,   528,   232,   563,   528,   565,   207,   207,   528,
     528,   842,   528,   565,   563,   806,   830,   232,     3,   231,
       9,     6,     7,     8,     9,    10,    11,     6,     9,     9,
     144,   837,     9,     9,     9,   875,   213,   214,   215,   216,
     217,     9,     9,   838,     9,   226,   231,   229,   225,   226,
     864,   837,   858,   229,   664,   228,   837,   228,   228,   228,
     858,   175,   229,   228,   207,   708,   230,   215,   229,   630,
     632,   714,   858,   634,   717,   889,   719,   858,   232,   230,
     205,   233,     6,   232,   205,   232,   708,   882,   710,   723,
     885,   650,   211,   212,   213,   214,   215,   216,   217,    84,
     232,   215,   232,   231,   666,   232,   225,   226,   723,   225,
     232,   205,   226,   205,   232,   232,     9,   231,   205,   232,
     232,   232,   681,   232,   232,   687,   232,   770,   687,   681,
     692,   232,   681,   232,   232,   232,   232,   681,   161,   317,
     701,   232,   320,   232,   232,   706,   232,   708,   770,   710,
     328,   136,   232,   331,   232,   717,   232,   232,   232,   232,
     338,   225,   340,   806,   232,   232,   232,   207,     3,   228,
     232,     6,     7,     8,     9,    10,    11,   205,   185,   211,
     205,   232,   228,   228,     3,   170,     3,     9,     6,   232,
       6,   752,   205,   229,   755,   185,   758,   207,   228,   184,
     226,   230,   205,   230,   212,   767,   228,   768,   767,   770,
       5,   772,   773,   232,   232,   767,   232,   232,   767,   228,
     398,   399,   228,   767,   228,   210,   785,   229,   213,   214,
     215,   232,   232,   218,   219,   207,   232,   232,   232,   232,
     211,   228,   227,   231,   228,   207,   231,   207,   809,    84,
     232,   813,   780,   393,   228,   228,   338,   417,   572,   820,
     554,   640,   440,   441,   442,   443,   444,   445,   446,   232,
     701,   885,   687,   834,   526,   768,   838,   381,   838,   838,
     576,   334,   252,   844,    94,   695,   838,   844,   849,   838,
     697,   693,    -1,    -1,   838,    -1,    -1,   404,    -1,    -1,
      -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   873,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   170,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   184,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   536,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,   210,    -1,    -1,   213,   214,
     215,    -1,    -1,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
     588,   589,    49,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
      -1,   609,    -1,    -1,    71,    -1,    -1,   615,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    98,   640,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    15,    16,
      17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,   136,
      -1,    -1,    -1,    -1,    -1,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,   158,    -1,    -1,   225,   226,    -1,    -1,   165,   166,
     167,   232,    -1,   170,   171,    -1,    -1,   174,    -1,    -1,
      -1,   178,    -1,    -1,    -1,    -1,    -1,   184,    -1,    -1,
     187,    -1,   189,    -1,    -1,    -1,    -1,     3,     4,     5,
     197,   198,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   210,    -1,    -1,   213,   214,   215,    -1,
      -1,   218,   219,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,   231,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,   812,    -1,    -1,    83,   816,    -1,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
     106,    -1,    -1,   109,   842,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,   210,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,
     146,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,   164,   165,
     166,   167,    -1,    -1,    -1,   171,    -1,    -1,   174,    -1,
      31,    -1,   178,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,   187,    -1,   189,    45,    46,    -1,    -1,    49,    -1,
      -1,   197,   198,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      71,    -1,    -1,     3,     4,     5,    77,    78,    -1,    -1,
     226,    -1,    83,    -1,   230,    -1,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,
      -1,    31,    -1,    -1,   105,   106,    -1,    37,   109,    39,
     111,   112,   113,   114,   115,    45,    46,    -1,    -1,    49,
     121,    -1,    -1,    -1,    -1,    -1,    56,   128,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    -1,    -1,    -1,   146,    -1,    77,    78,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,   158,    88,    -1,
      -1,    91,    -1,   164,   165,   166,   167,    -1,    98,    -1,
     171,    -1,    -1,   174,    -1,   105,    -1,   178,    -1,   109,
      -1,   111,   112,   113,   114,   115,   187,    -1,   189,    -1,
      -1,   121,    -1,    -1,    -1,    -1,   197,   198,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,   146,    -1,    15,    16,
      17,    18,    19,    20,    21,   226,    -1,    -1,   158,   230,
      -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,    -1,
      -1,   171,    -1,    37,   174,    39,    -1,    -1,   178,    -1,
      -1,    45,    -1,    -1,    -1,    49,    -1,   187,    -1,   189,
      -1,    -1,    56,    -1,    -1,    -1,    -1,   197,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,    -1,
       3,     4,     5,    77,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    88,    -1,   226,    91,    -1,    -1,
     230,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,   105,    -1,    -1,    37,   109,    39,   111,   112,   113,
     114,    -1,    45,    -1,    -1,    -1,    49,   121,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    -1,
      -1,    -1,   146,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,   158,    88,    -1,    -1,    91,    -1,
      -1,   165,   166,   167,    -1,    98,    -1,   171,    -1,    -1,
     174,    -1,   105,    -1,   178,    -1,   109,    -1,   111,   112,
     113,   114,    -1,   187,    -1,   189,    -1,    -1,   121,    -1,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,     5,   211,   212,   213,   214,   215,   216,
     217,    -1,    -1,   146,    -1,    -1,    -1,    -1,   225,   226,
      -1,    -1,   226,    -1,    -1,   158,   230,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,    37,    -1,    39,   171,    -1,
      -1,   174,    -1,    45,    -1,   178,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,   187,    -1,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,   226,    -1,    -1,    98,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,
     112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,   121,
      -1,     0,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    14,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    -1,   158,    -1,    37,    -1,
      39,    -1,    -1,   165,   166,   167,    45,    46,    -1,   171,
      49,    -1,   174,    -1,    -1,    -1,   178,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,   187,    -1,   189,    -1,    68,
      -1,    -1,    71,    -1,    -1,   197,   198,    -1,    77,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,   226,    -1,   105,    -1,   230,    -1,
     109,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   146,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      13,    -1,    -1,    -1,    -1,   164,   165,   166,   167,    -1,
      -1,    -1,   171,    -1,    -1,   174,    -1,    -1,    31,   178,
      -1,    -1,    -1,    -1,    37,    -1,    39,    -1,   187,    -1,
     189,    -1,    45,    46,    -1,    -1,    49,    -1,   197,   198,
      -1,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,   226,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,     3,    -1,     5,    98,    -1,    -1,    -1,    -1,
      -1,    -1,   105,   106,    -1,    -1,   109,    -1,   111,   112,
     113,   114,   115,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,   128,    37,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    49,    -1,
      -1,    -1,    -1,   146,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      71,   164,   165,   166,   167,    -1,    77,    78,   171,    -1,
      -1,   174,    83,    -1,    85,   178,    -1,    88,    -1,    -1,
      91,    -1,    -1,    -1,   187,    -1,   189,    98,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,   109,    -1,
     111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,    -1,
     121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,    -1,    -1,    -1,
     171,    -1,    -1,   174,   175,    -1,    -1,   178,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,   187,    -1,   189,    44,
      45,    -1,    -1,    -1,    49,    -1,   197,   198,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   215,    -1,    71,    -1,    -1,     3,
      -1,     5,    77,    78,    -1,   226,    -1,    -1,    83,    -1,
      85,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      24,    -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,   109,    39,   111,   112,   113,   114,
      -1,    45,    -1,    -1,    -1,    49,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    71,    -1,   144,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,   158,    88,    -1,    -1,    91,    -1,    -1,
     165,   166,   167,    -1,    98,    -1,   171,    -1,    -1,   174,
     175,    -1,    -1,   178,    -1,   109,    -1,   111,   112,   113,
     114,    -1,   187,    -1,   189,    -1,    -1,   121,    -1,    -1,
      -1,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     215,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      -1,   226,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,
      -1,   165,   166,   167,    37,    -1,    39,   171,    -1,    -1,
     174,    -1,    45,    -1,   178,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   187,    -1,   189,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,   226,    -1,    -1,    98,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,   109,    -1,   111,   112,
     113,   114,    -1,    -1,    -1,    -1,    -1,   206,   121,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,    -1,
      -1,    -1,    -1,   232,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,    -1,   171,    -1,
      -1,   174,    -1,    -1,    -1,   178,    -1,    15,    16,    17,
      18,    19,    20,    21,   187,    23,   189,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    -1,   208,   209,   210,   211,   212,   213,
     214,   215,   216,   217,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   226,    -1,    -1,    -1,    -1,   232,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
      16,    17,    18,    19,    20,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,    15,
      16,    17,    18,    19,    20,    21,   225,   226,   227,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,    -1,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     206,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,   206,    -1,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     225,   226,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    -1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,
     226,    31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,
      -1,    71,    -1,    -1,     3,    -1,     5,    77,    78,    -1,
      -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,   109,
      39,   111,   112,   113,   114,   115,    45,    -1,   118,    -1,
      49,   121,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,   158,    88,
      -1,    -1,    91,    -1,   164,   165,   166,   167,    -1,    98,
      -1,   171,    -1,    -1,   174,    -1,    -1,    -1,   178,     3,
     109,     5,   111,   112,   113,   114,    -1,   187,    -1,   189,
      -1,    -1,   121,    -1,    -1,    -1,    -1,   197,   198,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   158,
      -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,    -1,
      -1,     3,   171,     5,    -1,   174,    -1,    71,    -1,   178,
      -1,    -1,    -1,    77,    78,    -1,    -1,    -1,   187,    -1,
     189,    -1,     5,    -1,    88,    -1,    -1,    91,   197,   198,
      -1,    -1,    -1,    -1,    98,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,    -1,    -1,    37,    -1,    39,   121,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    88,    -1,    71,    91,
      -1,    -1,    -1,    -1,    77,    78,    98,    -1,    -1,    -1,
      83,   165,   166,   167,    -1,    88,    -1,   171,    91,   111,
     112,   113,   114,    -1,   178,    98,    -1,    -1,    -1,   121,
      -1,    -1,    -1,   187,    -1,   189,   109,     5,   111,   112,
     113,   114,    -1,   197,   198,    -1,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,
      -1,    39,    -1,    -1,   166,   167,    -1,    45,    -1,   171,
      -1,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,   165,   166,   167,    -1,    -1,   189,   171,    -1,
      -1,   174,    -1,    71,    -1,   178,   198,    -1,    -1,    77,
      78,    -1,    -1,    -1,   187,    -1,   189,    -1,    -1,    -1,
      88,    -1,    -1,    91,   197,   198,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,   113,   114,    -1,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
      -1,    -1,    -1,   171,    -1,    -1,    -1,    -1,    -1,    -1,
     178,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,   187,
      30,   189,    32,    33,    34,    35,    36,    -1,    38,   197,
     198,    41,    -1,    43,    -1,    -1,    -1,    47,    48,    -1,
      50,    51,    52,    53,    54,    55,    -1,    57,    -1,    59,
      60,    61,    -1,    63,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    73,    74,    75,    76,    -1,    -1,    79,
      80,    81,    82,    -1,    -1,    -1,    86,    87,    -1,    89,
      90,    -1,    92,    93,    94,    95,    96,    97,    -1,    99,
     100,   101,   102,   103,   104,    -1,    -1,   107,    -1,    -1,
     110,    -1,    -1,    -1,    -1,    -1,   116,   117,    -1,   119,
     120,    -1,   122,   123,   124,    -1,    -1,    -1,    -1,   129,
     130,   131,    -1,   133,   134,   135,    -1,   137,   138,   139,
     140,   141,   142,   143,    -1,   145,    -1,   147,    -1,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    -1,   159,
     160,    -1,   162,   163,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,   172,    -1,   174,    -1,   176,   177,    -1,    -1,
     180,   181,   182,   183,    -1,    -1,   186,    -1,   188,    -1,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,   199
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   235,   241,     0,     3,     4,     5,    14,    31,    37,
      39,    45,    46,    49,    56,    58,    68,    71,    77,    78,
      83,    88,    91,    98,   105,   109,   111,   112,   113,   114,
     115,   121,   128,   146,   158,   164,   165,   166,   167,   171,
     174,   178,   187,   189,   197,   198,   226,   236,   238,   247,
     248,   250,   251,   252,   253,   256,   257,   263,   264,   280,
     294,   297,   299,   301,   302,   303,   304,   307,   308,   309,
     310,   311,   312,   313,   316,   317,   320,   324,   327,   332,
     337,   338,   339,   340,   342,   345,   363,   364,   365,   366,
     367,   225,   226,   369,   372,   373,     3,     5,   297,   297,
     231,   229,   297,     3,   296,   297,   111,   300,     9,   297,
     300,     3,   231,   297,   231,   300,   301,     3,   296,     3,
     296,   301,    25,    26,    30,    32,    33,    34,    35,    36,
      38,    41,    43,    47,    48,    50,    51,    52,    53,    54,
      55,    57,    59,    60,    61,    63,    64,    65,    66,    67,
      69,    72,    73,    74,    75,    76,    79,    80,    81,    82,
      86,    87,    89,    90,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   107,   110,   116,   117,
     119,   120,   122,   123,   124,   129,   130,   131,   133,   134,
     135,   137,   138,   139,   140,   141,   142,   143,   145,   147,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   159,
     160,   162,   163,   169,   172,   174,   176,   177,   180,   181,
     182,   183,   186,   188,   190,   191,   192,   193,   194,   195,
     196,   199,   265,   271,   362,   228,   243,   243,    62,   185,
      77,   118,   126,   178,   187,   255,   280,   307,   309,   311,
     324,   336,   342,   363,   367,   228,     3,   297,   211,   228,
     228,   228,   229,   228,   316,   228,   246,   228,   344,   345,
     344,   344,    44,    85,   144,   175,   215,   231,   273,   297,
     298,   346,   347,   360,   280,   363,   365,   367,   344,   228,
      29,    59,    74,    82,   374,   375,   369,   115,     9,   237,
     229,   228,   211,     3,    60,   365,   229,   179,   229,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   205,
     227,    13,    58,   106,   240,   247,   254,   257,   307,   308,
     309,   310,   311,   312,   313,   316,   324,   327,   332,   337,
     230,   365,   263,   264,     3,   297,   297,     3,     3,   229,
     229,   229,   229,   333,   229,   360,   225,   299,   302,   303,
     304,   305,   306,   242,   229,   341,   346,   346,   233,   226,
     231,   262,   344,   231,   205,   227,     5,   232,   115,   230,
     263,   276,   277,   278,   279,   325,   207,   207,   232,   287,
     231,   290,   269,   342,     9,     9,    12,   272,   298,     3,
       6,     7,     8,     9,    10,    11,    84,   136,   170,   184,
     210,   213,   214,   215,   218,   219,   231,   283,   284,   285,
     269,     6,   268,   272,   283,   286,     9,     9,   266,   286,
     342,   285,     9,     9,   285,     9,   285,   283,   261,   264,
     342,   285,   281,   282,   283,    27,   132,   173,   267,     9,
     362,     9,   285,   365,   281,   270,   342,   283,   365,   127,
     200,   201,   202,   203,   204,   361,   365,   365,   272,     6,
       7,   368,     9,   365,   271,   226,   229,   231,   228,   228,
     228,   229,   228,   228,   246,   298,   342,   314,   314,   230,
     207,   321,   245,   297,   215,   215,   205,   212,   241,   148,
     318,   324,   340,   346,   232,   286,   215,   227,   283,   258,
     259,   260,   261,    28,    70,   168,   203,   376,   377,   375,
     229,   303,   298,   230,   205,   233,   297,   322,   323,     6,
     249,   249,   230,   263,   288,   263,   292,   230,   264,   289,
     292,   232,   205,   232,   232,   232,   231,   283,   283,   283,
     283,   283,   283,     5,   283,   343,   345,   364,    15,    16,
      17,    18,    19,    20,    21,    22,    23,   206,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   225,   226,
     205,   232,   232,   225,   232,   205,   232,   232,   205,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     342,   215,   231,   262,   273,   298,   352,   354,   355,   232,
     205,   232,   232,   232,   232,   232,   205,   232,   232,   232,
     205,   232,   232,   232,   232,   232,   232,   225,   232,   232,
     232,   271,   239,     9,   244,   211,   231,   346,   356,   230,
     263,   315,   230,   246,   303,   304,   161,   331,   230,   247,
     263,   264,   305,   230,   207,   125,   292,   319,   228,   227,
     227,   232,   205,   205,   232,   185,   370,   371,   211,   279,
     285,   205,   326,     6,   232,   232,   342,   367,   342,   363,
     232,   228,   228,   268,   343,   232,   215,   231,   262,   273,
     348,   350,   351,   364,   344,   283,   283,     3,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,     3,   283,   285,     6,   286,
       9,   354,   341,   215,   258,   273,   353,   354,   231,   262,
     282,   285,   269,     6,   115,   230,   232,   243,   328,   258,
     205,   246,    68,   115,   334,   335,   246,   303,   304,   330,
     229,   246,   207,   228,   230,   264,   293,   294,   230,    24,
     261,   377,   373,   230,   370,   306,   322,   212,   352,   358,
     359,   228,   346,   295,   298,   350,   341,   215,   258,   273,
     349,   350,   232,   231,   262,   344,   207,   227,   232,   354,
     341,   232,   354,   232,   258,   232,   303,   246,   230,   323,
     232,   346,   297,   297,   302,   228,   228,   205,   245,   228,
       5,   212,   207,   357,   205,   228,   229,   232,   350,   341,
     232,   354,   232,   283,   258,   283,   354,   232,   211,   212,
     246,   297,   303,   304,   230,   228,   228,   286,   358,   274,
     354,   232,   306,   231,   246,    43,    60,   230,   275,   212,
     258,   285,   207,   228,   232,   207,   228,   291,   292,   329,
     291,   228,   246
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   234,   235,   236,   236,   237,   237,   238,   239,   239,
     240,   241,   242,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   243,   243,
     243,   244,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   245,   245,   246,   246,
     247,   247,   247,   247,   247,   247,   247,   248,   248,   249,
     249,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   258,   259,
     259,   260,   260,   261,   261,   262,   262,   262,   263,   263,
     264,   265,   265,   265,   266,   266,   267,   267,   267,   268,
     268,   269,   270,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   271,   271,   271,
     271,   271,   271,   272,   272,   273,   273,   273,   273,   274,
     274,   275,   275,   276,   276,   276,   277,   277,   278,   279,
     279,   280,   281,   281,   282,   282,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   284,   284,   285,
     286,   287,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   292,   293,   294,   294,   295,   295,   296,   296,
     297,   297,   298,   299,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   300,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   302,   302,   303,   303,   304,
     305,   305,   305,   305,   305,   306,   306,   307,   308,   309,
     310,   311,   312,   313,   314,   314,   315,   315,   316,   317,
     318,   318,   319,   319,   320,   320,   321,   321,   321,   322,
     323,   323,   324,   325,   326,   324,   327,   328,   329,   327,
     330,   330,   330,   330,   331,   331,   333,   332,   332,   334,
     334,   335,   336,   337,   338,   338,   338,   339,   340,   341,
     341,   342,   342,   343,   343,   344,   344,   345,   345,   345,
     346,   346,   346,   347,   347,   347,   347,   348,   348,   348,
     349,   349,   350,   350,   351,   351,   351,   351,   351,   352,
     352,   352,   353,   353,   354,   354,   355,   355,   355,   355,
     355,   355,   356,   356,   357,   357,   358,   359,   359,   360,
     360,   361,   361,   361,   361,   361,   361,   362,   362,   362,
     363,   364,   364,   364,   364,   364,   364,   364,   364,   364,
     364,   365,   365,   365,   366,   367,   367,   368,   368,   368,
     369,   369,   370,   370,   371,   372,   373,   373,   374,   374,
     375,   375,   375,   375,   376,   376,   377,   377,   377,   377
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     7,     4,     0,     7,
       4,     0,     0,     6,     3,     3,     2,     2,     3,     2,
       3,     2,     3,     2,     2,     2,     2,     2,     0,     3,
       3,     0,     6,     2,     2,     3,     2,     3,     2,     3,
       2,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     6,     1,
       2,     1,     2,     1,     2,     1,     2,     2,     2,     2,
       4,     3,     3,     5,     2,     3,     4,     0,     1,     1,
       3,     1,     3,     3,     2,     3,     3,     2,     0,     1,
       3,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     0,     4,     1,     4,     1,     1,     1,
       1,     1,     4,     4,     1,     1,     1,     1,     1,     4,
       4,     1,     6,     1,     1,     1,     1,     4,     1,     1,
       1,     4,     1,     1,     1,     4,     4,     1,     1,     4,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       1,     4,     1,     1,     4,     1,     4,     1,     1,     4,
       4,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       4,     4,     1,     1,     1,     1,     1,     6,     1,     4,
       1,     1,     1,     4,     1,     4,     1,     1,     4,     4,
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
       2,     1,     1,     1,     1,     2,     3,     1,     2,     4,
       1,     1,     2,     1,     2,     1,     3,     2,     6,     2,
       6,     2,     5,     2,     0,     2,     3,     3,     2,     1,
       2,     3,     2,     3,     6,     6,     0,     2,     2,     1,
       1,     3,     2,     0,     0,     7,     8,     0,     0,    13,
       1,     1,     3,     3,     0,     2,     0,     9,     2,     2,
       3,     2,     2,     6,     1,     1,     1,     1,     1,     0,
       2,     2,     3,     2,     3,     0,     1,     2,     2,     2,
       3,     2,     1,     1,     3,     2,     4,     3,     2,     1,
       3,     2,     0,     1,     3,     2,     1,     3,     4,     3,
       2,     1,     3,     2,     0,     1,     1,     3,     2,     1,
       3,     4,     1,     3,     0,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     1,     1,     1,     2,     1,     2,     1,     2,     4,
       1,     1,     2,     1,     5,     5,    10,     1,     3,     1,
       0,     2,     0,     2,     4,     6,     0,     3,     1,     3,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1
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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
#line 349 "tools/widl/parser.y"
                                                { (yyvsp[-1].stmt_list) = append_parameterized_type_stmts((yyvsp[-1].stmt_list));
						  check_statements((yyvsp[-1].stmt_list), FALSE);
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
#line 3389 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 366 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3395 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 368 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3403 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 373 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3409 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 375 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3415 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3421 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 380 "tools/widl/parser.y"
                                                     { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3427 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3433 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 383 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3439 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 384 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3445 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 385 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3451 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 386 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3457 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3463 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 388 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3469 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3477 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3485 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3491 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 396 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3498 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3504 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3511 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3517 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 402 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3523 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3529 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 404 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3535 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3541 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3547 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3553 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 410 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3559 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 411 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3565 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3571 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3577 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3583 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 415 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3591 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3597 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3604 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3610 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 422 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3617 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3623 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 425 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3629 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 426 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3635 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3641 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 428 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3647 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 431 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3653 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3659 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3665 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3671 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 442 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3677 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 443 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3683 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3689 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3695 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 446 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3701 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 450 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 458 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3722 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 465 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3728 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 466 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3734 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM aIDENTIFIER  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3740 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 473 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3746 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION aIDENTIFIER  */
#line 475 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3752 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3758 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 477 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3764 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3770 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 481 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3776 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 483 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3787 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 491 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3796 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 498 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3802 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 501 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3808 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 503 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3816 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 508 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3822 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 511 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3828 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 515 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3834 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 516 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3840 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3846 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 524 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3856 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 529 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3866 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 536 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3875 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3881 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3887 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3893 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3899 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3917 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3923 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3929 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3935 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3941 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 572 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3969 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 578 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 3978 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: %empty  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3984 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tACTIVATABLE '(' contract_req ')'  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 3990 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tAGGREGATABLE  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3996 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 4002 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tAPPOBJECT  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 4008 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tASYNC  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 4014 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tAUTOHANDLE  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 4020 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tBINDABLE  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 4026 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tBROADCAST  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 4032 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tCALLAS '(' ident ')'  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 4038 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 4044 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tCODE  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 4050 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tCOMMSTATUS  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 4056 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tCONTEXTHANDLE  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 4062 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4068 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4074 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 4080 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 4086 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCONTROL  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 4092 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 602 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 4098 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tDECODE  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 4104 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tDEFAULT  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 4110 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tDEFAULTBIND  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 4116 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tDEFAULTCOLLELEM  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 4122 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 4128 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tDEFAULTVTABLE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 4134 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 4140 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDISPLAYBIND  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 4146 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 4152 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDUAL  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 4158 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tENABLEALLOCATE  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 4164 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tENCODE  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4170 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tENDPOINT '(' str_list ')'  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4176 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tENTRY '(' expr_const ')'  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4182 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tEVENTADD  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4188 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tEVENTREMOVE  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4194 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 619 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4202 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tEXPLICITHANDLE  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4208 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tFAULTSTATUS  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4214 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tFLAGS  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4220 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tFORCEALLOCATE  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4226 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tHANDLE  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4232 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4238 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4244 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4250 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 630 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4256 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4262 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tHIDDEN  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4268 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tID '(' expr_int_const ')'  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4274 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tIDEMPOTENT  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4280 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tIGNORE  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4286 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tIIDIS '(' expr ')'  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4292 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tIMMEDIATEBIND  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4298 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4304 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tIN  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4310 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tINPUTSYNC  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4316 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4322 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tLCID '(' expr_int_const ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4328 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tLCID  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4334 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tLICENSED  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4340 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tLOCAL  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4346 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4352 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tMAYBE  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4358 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tMESSAGE  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4364 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tNOCODE  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4370 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tNONBROWSABLE  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4376 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tNONCREATABLE  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4382 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tNONEXTENSIBLE  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4388 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tNOTIFY  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4394 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tNOTIFYFLAG  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4400 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tOBJECT  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4406 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tODL  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4412 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tOLEAUTOMATION  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4418 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4424 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tOPTIONAL  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4430 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tOUT  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4436 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tPARTIALIGNORE  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4442 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4448 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tPROGID '(' aSTRING ')'  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4454 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tPROPGET  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4460 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tPROPPUT  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4466 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tPROPPUTREF  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4472 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tPROXY  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4478 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tPUBLIC  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4484 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 671 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4492 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tREADONLY  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4498 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tREPRESENTAS '(' type ')'  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4504 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tREQUESTEDIT  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4510 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tRESTRICTED  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4516 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tRETVAL  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4522 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4528 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tSOURCE  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4534 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tSTATIC '(' static_attr ')'  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4540 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4546 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tSTRING  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4552 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tSWITCHIS '(' expr ')'  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4558 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4564 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tTRANSMITAS '(' type ')'  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4570 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tTHREADING '(' threading_type ')'  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4576 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tUIDEFAULT  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4582 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tUSESGETLASTERROR  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4588 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4594 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tUUID '(' uuid_string ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4600 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4606 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tV1ENUM  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4612 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tVARARG  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4618 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tVERSION '(' version ')'  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4630 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4636 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: pointer_type  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4642 "tools/widl/parser.tab.c"
    break;

  case 214: /* uuid_string: aSTRING  */
#line 703 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4650 "tools/widl/parser.tab.c"
    break;

  case 215: /* callconv: tCDECL  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4656 "tools/widl/parser.tab.c"
    break;

  case 216: /* callconv: tFASTCALL  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4662 "tools/widl/parser.tab.c"
    break;

  case 217: /* callconv: tPASCAL  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4668 "tools/widl/parser.tab.c"
    break;

  case 218: /* callconv: tSTDCALL  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4674 "tools/widl/parser.tab.c"
    break;

  case 219: /* cases: %empty  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4680 "tools/widl/parser.tab.c"
    break;

  case 220: /* cases: cases case  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4686 "tools/widl/parser.tab.c"
    break;

  case 221: /* case: tCASE expr_int_const ':' union_field  */
#line 718 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4695 "tools/widl/parser.tab.c"
    break;

  case 222: /* case: tDEFAULT ':' union_field  */
#line 722 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4704 "tools/widl/parser.tab.c"
    break;

  case 223: /* enums: %empty  */
#line 728 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4710 "tools/widl/parser.tab.c"
    break;

  case 224: /* enums: enum_list ','  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4716 "tools/widl/parser.tab.c"
    break;

  case 226: /* enum_list: enum  */
#line 733 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4725 "tools/widl/parser.tab.c"
    break;

  case 227: /* enum_list: enum_list ',' enum  */
#line 737 "tools/widl/parser.y"
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
#line 4740 "tools/widl/parser.tab.c"
    break;

  case 228: /* enum_member: m_attributes ident  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4748 "tools/widl/parser.tab.c"
    break;

  case 229: /* enum: enum_member '=' expr_int_const  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4757 "tools/widl/parser.tab.c"
    break;

  case 230: /* enum: enum_member  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4765 "tools/widl/parser.tab.c"
    break;

  case 231: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4771 "tools/widl/parser.tab.c"
    break;

  case 232: /* m_exprs: m_expr  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4777 "tools/widl/parser.tab.c"
    break;

  case 233: /* m_exprs: m_exprs ',' m_expr  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4783 "tools/widl/parser.tab.c"
    break;

  case 234: /* m_expr: %empty  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4789 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: aNUM  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4795 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: aHEXNUM  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4801 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: aDOUBLE  */
#line 776 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4807 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: tFALSE  */
#line 777 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4813 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: tNULL  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4819 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: tTRUE  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4825 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: aSTRING  */
#line 780 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4831 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: aWSTRING  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4837 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: aSQSTRING  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4843 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: aIDENTIFIER  */
#line 783 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4849 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr '?' expr ':' expr  */
#line 784 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4855 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr LOGICALOR expr  */
#line 785 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4861 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr LOGICALAND expr  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4867 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '|' expr  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4873 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr '^' expr  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4879 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr '&' expr  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4885 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr EQUALITY expr  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4891 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr INEQUALITY expr  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4897 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr '>' expr  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4903 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr '<' expr  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4909 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr GREATEREQUAL expr  */
#line 794 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4915 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr LESSEQUAL expr  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4921 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr SHL expr  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4927 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr SHR expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4933 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr '+' expr  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4939 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '-' expr  */
#line 799 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4945 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr '%' expr  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4951 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr '*' expr  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4957 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr '/' expr  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4963 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: '!' expr  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4969 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: '~' expr  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4975 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: '+' expr  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4981 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: '-' expr  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4987 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: '&' expr  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4993 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: '*' expr  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4999 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5005 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: expr '.' aIDENTIFIER  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5011 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5017 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 814 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5023 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: expr '[' expr ']'  */
#line 815 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5029 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '(' expr ')'  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5035 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr_list_int_const: expr_int_const  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5041 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 820 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5047 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr_int_const: expr  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5056 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr_const: expr  */
#line 829 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5065 "tools/widl/parser.tab.c"
    break;

  case 281: /* fields: %empty  */
#line 835 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5071 "tools/widl/parser.tab.c"
    break;

  case 282: /* fields: fields field  */
#line 836 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5077 "tools/widl/parser.tab.c"
    break;

  case 283: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 840 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5086 "tools/widl/parser.tab.c"
    break;

  case 284: /* field: m_attributes uniondef ';'  */
#line 844 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5095 "tools/widl/parser.tab.c"
    break;

  case 285: /* ne_union_field: s_field ';'  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5101 "tools/widl/parser.tab.c"
    break;

  case 286: /* ne_union_field: attributes ';'  */
#line 852 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5107 "tools/widl/parser.tab.c"
    break;

  case 287: /* ne_union_fields: %empty  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5113 "tools/widl/parser.tab.c"
    break;

  case 288: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 856 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5119 "tools/widl/parser.tab.c"
    break;

  case 289: /* union_field: s_field ';'  */
#line 860 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5125 "tools/widl/parser.tab.c"
    break;

  case 290: /* union_field: ';'  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5131 "tools/widl/parser.tab.c"
    break;

  case 291: /* s_field: m_attributes decl_spec declarator  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5140 "tools/widl/parser.tab.c"
    break;

  case 292: /* s_field: m_attributes structdef  */
#line 868 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5149 "tools/widl/parser.tab.c"
    break;

  case 293: /* funcdef: declaration  */
#line 874 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5159 "tools/widl/parser.tab.c"
    break;

  case 294: /* declaration: attributes decl_spec init_declarator  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5167 "tools/widl/parser.tab.c"
    break;

  case 295: /* declaration: decl_spec init_declarator  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5175 "tools/widl/parser.tab.c"
    break;

  case 296: /* m_ident: %empty  */
#line 891 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5181 "tools/widl/parser.tab.c"
    break;

  case 298: /* m_typename: %empty  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5187 "tools/widl/parser.tab.c"
    break;

  case 302: /* ident: typename  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5193 "tools/widl/parser.tab.c"
    break;

  case 303: /* base_type: tBYTE  */
#line 906 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5199 "tools/widl/parser.tab.c"
    break;

  case 304: /* base_type: tWCHAR  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5205 "tools/widl/parser.tab.c"
    break;

  case 306: /* base_type: tSIGNED int_std  */
#line 909 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5211 "tools/widl/parser.tab.c"
    break;

  case 307: /* base_type: tUNSIGNED int_std  */
#line 910 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5217 "tools/widl/parser.tab.c"
    break;

  case 308: /* base_type: tUNSIGNED  */
#line 911 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5223 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tFLOAT  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5229 "tools/widl/parser.tab.c"
    break;

  case 310: /* base_type: tDOUBLE  */
#line 913 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5235 "tools/widl/parser.tab.c"
    break;

  case 311: /* base_type: tBOOLEAN  */
#line 914 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5241 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tERRORSTATUST  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5247 "tools/widl/parser.tab.c"
    break;

  case 313: /* base_type: tHANDLET  */
#line 916 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5253 "tools/widl/parser.tab.c"
    break;

  case 316: /* int_std: tINT  */
#line 923 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5259 "tools/widl/parser.tab.c"
    break;

  case 317: /* int_std: tSHORT m_int  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5265 "tools/widl/parser.tab.c"
    break;

  case 318: /* int_std: tSMALL  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5271 "tools/widl/parser.tab.c"
    break;

  case 319: /* int_std: tLONG m_int  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5277 "tools/widl/parser.tab.c"
    break;

  case 320: /* int_std: tHYPER m_int  */
#line 927 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5283 "tools/widl/parser.tab.c"
    break;

  case 321: /* int_std: tINT64  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5289 "tools/widl/parser.tab.c"
    break;

  case 322: /* int_std: tCHAR  */
#line 929 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5295 "tools/widl/parser.tab.c"
    break;

  case 323: /* int_std: tINT32  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5301 "tools/widl/parser.tab.c"
    break;

  case 324: /* int_std: tINT3264  */
#line 931 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5307 "tools/widl/parser.tab.c"
    break;

  case 325: /* namespace_pfx: aIDENTIFIER '.'  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5313 "tools/widl/parser.tab.c"
    break;

  case 326: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5319 "tools/widl/parser.tab.c"
    break;

  case 327: /* qualified_type: typename  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5325 "tools/widl/parser.tab.c"
    break;

  case 328: /* qualified_type: namespace_pfx typename  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5331 "tools/widl/parser.tab.c"
    break;

  case 329: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 945 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5337 "tools/widl/parser.tab.c"
    break;

  case 330: /* parameterized_type_arg: base_type  */
#line 949 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5343 "tools/widl/parser.tab.c"
    break;

  case 331: /* parameterized_type_arg: qualified_type  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5349 "tools/widl/parser.tab.c"
    break;

  case 332: /* parameterized_type_arg: qualified_type '*'  */
#line 951 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5355 "tools/widl/parser.tab.c"
    break;

  case 333: /* parameterized_type_arg: parameterized_type  */
#line 952 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5361 "tools/widl/parser.tab.c"
    break;

  case 334: /* parameterized_type_arg: parameterized_type '*'  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5367 "tools/widl/parser.tab.c"
    break;

  case 335: /* parameterized_type_args: parameterized_type_arg  */
#line 957 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5373 "tools/widl/parser.tab.c"
    break;

  case 336: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 959 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5379 "tools/widl/parser.tab.c"
    break;

  case 337: /* coclass: tCOCLASS typename  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5385 "tools/widl/parser.tab.c"
    break;

  case 338: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5391 "tools/widl/parser.tab.c"
    break;

  case 339: /* runtimeclass: tRUNTIMECLASS typename  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5397 "tools/widl/parser.tab.c"
    break;

  case 340: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5403 "tools/widl/parser.tab.c"
    break;

  case 341: /* apicontract: tAPICONTRACT typename  */
#line 976 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5409 "tools/widl/parser.tab.c"
    break;

  case 342: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 980 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5415 "tools/widl/parser.tab.c"
    break;

  case 343: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 983 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5421 "tools/widl/parser.tab.c"
    break;

  case 344: /* class_interfaces: %empty  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5427 "tools/widl/parser.tab.c"
    break;

  case 345: /* class_interfaces: class_interfaces class_interface  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5433 "tools/widl/parser.tab.c"
    break;

  case 346: /* class_interface: m_attributes interfaceref ';'  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5439 "tools/widl/parser.tab.c"
    break;

  case 347: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5445 "tools/widl/parser.tab.c"
    break;

  case 348: /* dispinterface: tDISPINTERFACE typename  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5451 "tools/widl/parser.tab.c"
    break;

  case 349: /* dispattributes: attributes  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5457 "tools/widl/parser.tab.c"
    break;

  case 350: /* dispint_props: tPROPERTIES ':'  */
#line 1001 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5463 "tools/widl/parser.tab.c"
    break;

  case 351: /* dispint_props: dispint_props s_field ';'  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5469 "tools/widl/parser.tab.c"
    break;

  case 352: /* dispint_meths: tMETHODS ':'  */
#line 1005 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5475 "tools/widl/parser.tab.c"
    break;

  case 353: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1006 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5481 "tools/widl/parser.tab.c"
    break;

  case 354: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1011 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5487 "tools/widl/parser.tab.c"
    break;

  case 355: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5493 "tools/widl/parser.tab.c"
    break;

  case 356: /* inherit: %empty  */
#line 1016 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5499 "tools/widl/parser.tab.c"
    break;

  case 357: /* inherit: ':' qualified_type  */
#line 1017 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5505 "tools/widl/parser.tab.c"
    break;

  case 358: /* inherit: ':' parameterized_type  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5511 "tools/widl/parser.tab.c"
    break;

  case 359: /* type_parameter: typename  */
#line 1021 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5517 "tools/widl/parser.tab.c"
    break;

  case 360: /* type_parameters: type_parameter  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5523 "tools/widl/parser.tab.c"
    break;

  case 361: /* type_parameters: type_parameters ',' type_parameter  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5529 "tools/widl/parser.tab.c"
    break;

  case 362: /* interface: tINTERFACE typename  */
#line 1030 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5535 "tools/widl/parser.tab.c"
    break;

  case 363: /* $@3: %empty  */
#line 1031 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5541 "tools/widl/parser.tab.c"
    break;

  case 364: /* $@4: %empty  */
#line 1031 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5547 "tools/widl/parser.tab.c"
    break;

  case 365: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1032 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5553 "tools/widl/parser.tab.c"
    break;

  case 366: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						}
#line 5561 "tools/widl/parser.tab.c"
    break;

  case 367: /* $@5: %empty  */
#line 1040 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5567 "tools/widl/parser.tab.c"
    break;

  case 368: /* $@6: %empty  */
#line 1041 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5573 "tools/widl/parser.tab.c"
    break;

  case 369: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))));
						}
#line 5581 "tools/widl/parser.tab.c"
    break;

  case 370: /* required_types: qualified_type  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5587 "tools/widl/parser.tab.c"
    break;

  case 371: /* required_types: parameterized_type  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5593 "tools/widl/parser.tab.c"
    break;

  case 372: /* required_types: required_types ',' qualified_type  */
#line 1050 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5599 "tools/widl/parser.tab.c"
    break;

  case 373: /* required_types: required_types ',' parameterized_type  */
#line 1051 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5605 "tools/widl/parser.tab.c"
    break;

  case 374: /* requires: %empty  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5611 "tools/widl/parser.tab.c"
    break;

  case 375: /* requires: tREQUIRES required_types  */
#line 1054 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5617 "tools/widl/parser.tab.c"
    break;

  case 376: /* $@7: %empty  */
#line 1057 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5623 "tools/widl/parser.tab.c"
    break;

  case 377: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1059 "tools/widl/parser.y"
                                                { if ((yyvsp[-7].type)->type_type == TYPE_PARAMETERIZED_TYPE)
						  {
						      (yyval.type) = type_parameterized_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list));
						      pop_parameters_namespace((yyvsp[-7].type)->name);
						  }
						  else
						  {
						      (yyval.type) = type_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list));
						      check_async_uuid((yyval.type));
						  }
						}
#line 5639 "tools/widl/parser.tab.c"
    break;

  case 378: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1070 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5645 "tools/widl/parser.tab.c"
    break;

  case 379: /* interfaceref: tINTERFACE typename  */
#line 1074 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5651 "tools/widl/parser.tab.c"
    break;

  case 380: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5657 "tools/widl/parser.tab.c"
    break;

  case 381: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1079 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5663 "tools/widl/parser.tab.c"
    break;

  case 382: /* module: tMODULE typename  */
#line 1082 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5669 "tools/widl/parser.tab.c"
    break;

  case 383: /* moduledef: attributes module '{' int_statements '}' semicolon_opt  */
#line 1086 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5675 "tools/widl/parser.tab.c"
    break;

  case 384: /* storage_cls_spec: tEXTERN  */
#line 1090 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5681 "tools/widl/parser.tab.c"
    break;

  case 385: /* storage_cls_spec: tSTATIC  */
#line 1091 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5687 "tools/widl/parser.tab.c"
    break;

  case 386: /* storage_cls_spec: tREGISTER  */
#line 1092 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5693 "tools/widl/parser.tab.c"
    break;

  case 387: /* function_specifier: tINLINE  */
#line 1096 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5699 "tools/widl/parser.tab.c"
    break;

  case 388: /* type_qualifier: tCONST  */
#line 1100 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5705 "tools/widl/parser.tab.c"
    break;

  case 389: /* m_type_qual_list: %empty  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5711 "tools/widl/parser.tab.c"
    break;

  case 390: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1104 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5717 "tools/widl/parser.tab.c"
    break;

  case 391: /* decl_spec: type m_decl_spec_no_type  */
#line 1107 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5723 "tools/widl/parser.tab.c"
    break;

  case 392: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1109 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5729 "tools/widl/parser.tab.c"
    break;

  case 393: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5735 "tools/widl/parser.tab.c"
    break;

  case 394: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5741 "tools/widl/parser.tab.c"
    break;

  case 395: /* m_decl_spec_no_type: %empty  */
#line 1118 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5747 "tools/widl/parser.tab.c"
    break;

  case 397: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5753 "tools/widl/parser.tab.c"
    break;

  case 398: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1124 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5759 "tools/widl/parser.tab.c"
    break;

  case 399: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1125 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5765 "tools/widl/parser.tab.c"
    break;

  case 400: /* declarator: '*' m_type_qual_list declarator  */
#line 1130 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5771 "tools/widl/parser.tab.c"
    break;

  case 401: /* declarator: callconv declarator  */
#line 1131 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5777 "tools/widl/parser.tab.c"
    break;

  case 403: /* direct_declarator: ident  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5783 "tools/widl/parser.tab.c"
    break;

  case 404: /* direct_declarator: '(' declarator ')'  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5789 "tools/widl/parser.tab.c"
    break;

  case 405: /* direct_declarator: direct_declarator array  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5795 "tools/widl/parser.tab.c"
    break;

  case 406: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5801 "tools/widl/parser.tab.c"
    break;

  case 407: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5807 "tools/widl/parser.tab.c"
    break;

  case 408: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1146 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5813 "tools/widl/parser.tab.c"
    break;

  case 410: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5819 "tools/widl/parser.tab.c"
    break;

  case 411: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1154 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5825 "tools/widl/parser.tab.c"
    break;

  case 412: /* m_abstract_declarator: %empty  */
#line 1158 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5831 "tools/widl/parser.tab.c"
    break;

  case 414: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5837 "tools/widl/parser.tab.c"
    break;

  case 415: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1165 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5843 "tools/widl/parser.tab.c"
    break;

  case 416: /* abstract_direct_declarator: array  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5849 "tools/widl/parser.tab.c"
    break;

  case 417: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1168 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5857 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5865 "tools/widl/parser.tab.c"
    break;

  case 419: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5871 "tools/widl/parser.tab.c"
    break;

  case 420: /* any_declarator: callconv m_any_declarator  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5877 "tools/widl/parser.tab.c"
    break;

  case 422: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5883 "tools/widl/parser.tab.c"
    break;

  case 423: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1189 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5889 "tools/widl/parser.tab.c"
    break;

  case 424: /* m_any_declarator: %empty  */
#line 1193 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5895 "tools/widl/parser.tab.c"
    break;

  case 426: /* any_direct_declarator: ident  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5901 "tools/widl/parser.tab.c"
    break;

  case 427: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5907 "tools/widl/parser.tab.c"
    break;

  case 428: /* any_direct_declarator: any_direct_declarator array  */
#line 1203 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5913 "tools/widl/parser.tab.c"
    break;

  case 429: /* any_direct_declarator: array  */
#line 1204 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5919 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_direct_declarator: '(' m_args ')'  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5927 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1210 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5935 "tools/widl/parser.tab.c"
    break;

  case 432: /* declarator_list: declarator  */
#line 1216 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5941 "tools/widl/parser.tab.c"
    break;

  case 433: /* declarator_list: declarator_list ',' declarator  */
#line 1217 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5947 "tools/widl/parser.tab.c"
    break;

  case 434: /* m_bitfield: %empty  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5953 "tools/widl/parser.tab.c"
    break;

  case 435: /* m_bitfield: ':' expr_const  */
#line 1221 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5959 "tools/widl/parser.tab.c"
    break;

  case 436: /* struct_declarator: any_declarator m_bitfield  */
#line 1224 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5968 "tools/widl/parser.tab.c"
    break;

  case 437: /* struct_declarator_list: struct_declarator  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5974 "tools/widl/parser.tab.c"
    break;

  case 438: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1233 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5980 "tools/widl/parser.tab.c"
    break;

  case 439: /* init_declarator: declarator  */
#line 1237 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5986 "tools/widl/parser.tab.c"
    break;

  case 440: /* init_declarator: declarator '=' expr_const  */
#line 1238 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5992 "tools/widl/parser.tab.c"
    break;

  case 441: /* threading_type: tAPARTMENT  */
#line 1242 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5998 "tools/widl/parser.tab.c"
    break;

  case 442: /* threading_type: tNEUTRAL  */
#line 1243 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6004 "tools/widl/parser.tab.c"
    break;

  case 443: /* threading_type: tSINGLE  */
#line 1244 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6010 "tools/widl/parser.tab.c"
    break;

  case 444: /* threading_type: tFREE  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6016 "tools/widl/parser.tab.c"
    break;

  case 445: /* threading_type: tBOTH  */
#line 1246 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6022 "tools/widl/parser.tab.c"
    break;

  case 446: /* threading_type: tMTA  */
#line 1247 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6028 "tools/widl/parser.tab.c"
    break;

  case 447: /* pointer_type: tREF  */
#line 1251 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6034 "tools/widl/parser.tab.c"
    break;

  case 448: /* pointer_type: tUNIQUE  */
#line 1252 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6040 "tools/widl/parser.tab.c"
    break;

  case 449: /* pointer_type: tPTR  */
#line 1253 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6046 "tools/widl/parser.tab.c"
    break;

  case 450: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1256 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6052 "tools/widl/parser.tab.c"
    break;

  case 451: /* unqualified_type: tVOID  */
#line 1260 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6058 "tools/widl/parser.tab.c"
    break;

  case 452: /* unqualified_type: base_type  */
#line 1261 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6064 "tools/widl/parser.tab.c"
    break;

  case 453: /* unqualified_type: enumdef  */
#line 1262 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6070 "tools/widl/parser.tab.c"
    break;

  case 454: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1263 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6076 "tools/widl/parser.tab.c"
    break;

  case 455: /* unqualified_type: structdef  */
#line 1264 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6082 "tools/widl/parser.tab.c"
    break;

  case 456: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6088 "tools/widl/parser.tab.c"
    break;

  case 457: /* unqualified_type: uniondef  */
#line 1266 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6094 "tools/widl/parser.tab.c"
    break;

  case 458: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1267 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 6100 "tools/widl/parser.tab.c"
    break;

  case 459: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1268 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6106 "tools/widl/parser.tab.c"
    break;

  case 460: /* unqualified_type: aKNOWNTYPE  */
#line 1269 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6112 "tools/widl/parser.tab.c"
    break;

  case 462: /* type: namespace_pfx typename  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6118 "tools/widl/parser.tab.c"
    break;

  case 463: /* type: parameterized_type  */
#line 1275 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6124 "tools/widl/parser.tab.c"
    break;

  case 464: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1279 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6133 "tools/widl/parser.tab.c"
    break;

  case 465: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1286 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 6139 "tools/widl/parser.tab.c"
    break;

  case 466: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1289 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6145 "tools/widl/parser.tab.c"
    break;

  case 467: /* version: aNUM  */
#line 1293 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6151 "tools/widl/parser.tab.c"
    break;

  case 468: /* version: aNUM '.' aNUM  */
#line 1294 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6157 "tools/widl/parser.tab.c"
    break;

  case 469: /* version: aHEXNUM  */
#line 1295 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6163 "tools/widl/parser.tab.c"
    break;

  case 474: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1310 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6171 "tools/widl/parser.tab.c"
    break;

  case 475: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1317 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6181 "tools/widl/parser.tab.c"
    break;

  case 476: /* acf_attributes: %empty  */
#line 1325 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6187 "tools/widl/parser.tab.c"
    break;

  case 477: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1326 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6193 "tools/widl/parser.tab.c"
    break;

  case 478: /* acf_attribute_list: acf_attribute  */
#line 1330 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6199 "tools/widl/parser.tab.c"
    break;

  case 479: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1331 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6205 "tools/widl/parser.tab.c"
    break;

  case 480: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1336 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 6211 "tools/widl/parser.tab.c"
    break;

  case 481: /* acf_attribute: tENCODE  */
#line 1337 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 6217 "tools/widl/parser.tab.c"
    break;

  case 482: /* acf_attribute: tDECODE  */
#line 1338 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 6223 "tools/widl/parser.tab.c"
    break;

  case 483: /* acf_attribute: tEXPLICITHANDLE  */
#line 1339 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 6229 "tools/widl/parser.tab.c"
    break;

  case 484: /* allocate_option_list: allocate_option  */
#line 1343 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6235 "tools/widl/parser.tab.c"
    break;

  case 485: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1345 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6241 "tools/widl/parser.tab.c"
    break;

  case 486: /* allocate_option: tDONTFREE  */
#line 1349 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6247 "tools/widl/parser.tab.c"
    break;

  case 487: /* allocate_option: tFREE  */
#line 1350 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6253 "tools/widl/parser.tab.c"
    break;

  case 488: /* allocate_option: tALLNODES  */
#line 1351 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6259 "tools/widl/parser.tab.c"
    break;

  case 489: /* allocate_option: tSINGLENODE  */
#line 1352 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6265 "tools/widl/parser.tab.c"
    break;


#line 6269 "tools/widl/parser.tab.c"

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

#line 1355 "tools/widl/parser.y"


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

attr_t *make_attrp(enum attr_type type, void *val)
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

typeref_list_t *append_typeref(typeref_list_t *list, typeref_t *ref)
{
    if (!ref) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &ref->entry );
    return list;
}

typeref_t *make_typeref(type_t *type)
{
    typeref_t *ref = xmalloc(sizeof(typeref_t));
    ref->type = type;
    ref->attrs = NULL;
    return ref;
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

static void push_parameters_namespace(const char *name)
{
    struct namespace *namespace;

    if (!(namespace = find_sub_namespace(current_namespace, name)))
    {
        namespace = xmalloc(sizeof(*namespace));
        namespace->name = xstrdup(name);
        namespace->parent = current_namespace;
        list_add_tail(&current_namespace->children, &namespace->entry);
        list_init(&namespace->children);
        memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
    }

    parameters_namespace = namespace;
}

static void pop_parameters_namespace(const char *name)
{
    assert(!strcmp(parameters_namespace->name, name) && parameters_namespace->parent);
    parameters_namespace = NULL;
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
  {
    type->c_name = name;
    type->qualified_name = name;
  }
  else
  {
    type->c_name = format_namespace(namespace, "__x_", "_C", name, use_abi_namespace ? "ABI" : NULL);
    type->qualified_name = format_namespace(namespace, "", "::", name, use_abi_namespace ? "ABI" : NULL);
  }
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
    if (!(type = find_type(name, namespace, 0)) &&
        !(type = find_type(name, parameters_namespace, 0)))
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
    return find_type(name, current_namespace, 0) != NULL ||
           find_type(name, parameters_namespace, 0);
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
    /* ATTR_ACTIVATABLE */         { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "activatable" },
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
    /* ATTR_STATIC */              { 0, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "static" },
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

attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
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
    case TYPE_DELEGATE:
        return FALSE;
    case TYPE_APICONTRACT:
    case TYPE_PARAMETERIZED_TYPE:
    case TYPE_PARAMETER:
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

    type_interface_define(async_iface, map_attrs(iface->attrs, async_iface_attrs), inherit, stmts, NULL);
    iface->details.iface->async_iface = async_iface->details.iface->async_iface = async_iface;
}

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts)
{
    statement_t *stmt, *next;

    if (stmts && parameterized_type_stmts) LIST_FOR_EACH_ENTRY_SAFE(stmt, next, parameterized_type_stmts, statement_t, entry)
    {
        switch(stmt->type)
        {
        case STMT_TYPE:
            stmt->u.type = type_parameterized_type_specialize_define(stmt->u.type);
            stmt->declonly = FALSE;
            list_remove(&stmt->entry);
            stmts = append_statement(stmts, stmt);
            break;
        default:
            assert(0); /* should not be there */
            break;
        }
    }

    return stmts;
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

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    stmt->declonly = declonly;

    LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
    {
        var_t *var = decl->var;
        type_t *type = find_type_or_error(current_namespace, var->name);
        stmt->u.type_list = append_typeref(stmt->u.type_list, make_typeref(type));
        free(decl);
        free(var);
    }

    return stmt;
}

static statement_t *make_statement_parameterized_type(type_t *type, typeref_list_t *params)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type = type_parameterized_type_specialize_partial(type, params);
    return stmt;
}

static statement_t *make_statement_delegate(type_t *ret, var_list_t *args)
{
    declarator_t *decl = make_declarator(make_var(xstrdup("Invoke")));
    decl_spec_t *spec = make_decl_spec(ret, NULL, NULL, STG_NONE, 0, 0);
    append_chain_type(decl, type_new_function(args), 0);
    return make_statement_declaration(declare_var(NULL, spec, decl, FALSE));
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

type_t *find_parameterized_type(type_t *type, typeref_list_t *params)
{
    char *name = format_parameterized_type_name(type, params);

    if (parameters_namespace)
    {
        assert(type->type_type == TYPE_PARAMETERIZED_TYPE);
        type = type_parameterized_type_specialize_partial(type, params);
    }
    else if ((type = find_type(name, type->namespace, 0)))
        assert(type->type_type != TYPE_PARAMETERIZED_TYPE);
    else
        error_loc("parameterized type '%s' not declared\n", name);

    free(name);
    return type;
}
