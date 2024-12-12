/* A Bison parser, made by GNU Bison 3.8.2.  */

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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PARSER_STYPE
#define YYLTYPE         PARSER_LTYPE
/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs

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
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
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
static void append_chain_callconv( struct location where, type_t *chain, char *callconv );
static warning_list_t *append_warning(warning_list_t *, int);

static type_t *reg_typedefs( struct location where, decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs );
static type_t *find_type_or_error(struct namespace *parent, const char *name);
static struct namespace *find_namespace_or_error(struct namespace *namespace, const char *name);

static var_t *reg_const(var_t *var);

static void push_namespaces(str_list_t *names);
static void pop_namespaces(str_list_t *names);
static void push_parameters_namespace(const char *name);
static void pop_parameters_namespace(const char *name);

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
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
static statement_t *make_statement_typedef(var_list_t *names, bool is_defined);
static statement_t *make_statement_import(const char *str);
static statement_t *make_statement_parameterized_type(type_t *type, typeref_list_t *params);
static statement_t *make_statement_delegate(type_t *ret, var_list_t *args);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *parameters_namespace = NULL;
static statement_list_t *parameterized_type_stmts = NULL;

static typelib_t *current_typelib;


#line 186 "tools/widl/parser.tab.c"

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
#ifndef PARSER_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define PARSER_DEBUG 1
#  else
#   define PARSER_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define PARSER_DEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined PARSER_DEBUG */
#if PARSER_DEBUG
extern int parser_debug;
#endif
/* "%code requires" blocks.  */
#line 110 "tools/widl/parser.y"


#define PARSER_LTYPE struct location


#line 232 "tools/widl/parser.tab.c"

/* Token kinds.  */
#ifndef PARSER_TOKENTYPE
# define PARSER_TOKENTYPE
  enum parser_tokentype
  {
    PARSER_EMPTY = -2,
    PARSER_EOF = 0,                /* "end of file"  */
    PARSER_error = 256,            /* error  */
    PARSER_UNDEF = 257,            /* "invalid token"  */
    aIDENTIFIER = 258,             /* aIDENTIFIER  */
    aPRAGMA = 259,                 /* aPRAGMA  */
    aKNOWNTYPE = 260,              /* aKNOWNTYPE  */
    aNUM = 261,                    /* aNUM  */
    aHEXNUM = 262,                 /* aHEXNUM  */
    aDOUBLE = 263,                 /* aDOUBLE  */
    aSTRING = 264,                 /* aSTRING  */
    aWSTRING = 265,                /* aWSTRING  */
    aSQSTRING = 266,               /* aSQSTRING  */
    tCDECL = 267,                  /* tCDECL  */
    tFASTCALL = 268,               /* tFASTCALL  */
    tPASCAL = 269,                 /* tPASCAL  */
    tSTDCALL = 270,                /* tSTDCALL  */
    aUUID = 271,                   /* aUUID  */
    aEOF = 272,                    /* aEOF  */
    aACF = 273,                    /* aACF  */
    SHL = 274,                     /* SHL  */
    SHR = 275,                     /* SHR  */
    MEMBERPTR = 276,               /* MEMBERPTR  */
    EQUALITY = 277,                /* EQUALITY  */
    INEQUALITY = 278,              /* INEQUALITY  */
    GREATEREQUAL = 279,            /* GREATEREQUAL  */
    LESSEQUAL = 280,               /* LESSEQUAL  */
    LOGICALOR = 281,               /* LOGICALOR  */
    LOGICALAND = 282,              /* LOGICALAND  */
    ELLIPSIS = 283,                /* ELLIPSIS  */
    tACTIVATABLE = 284,            /* tACTIVATABLE  */
    tAGGREGATABLE = 285,           /* tAGGREGATABLE  */
    tAGILE = 286,                  /* tAGILE  */
    tALLNODES = 287,               /* tALLNODES  */
    tALLOCATE = 288,               /* tALLOCATE  */
    tANNOTATION = 289,             /* tANNOTATION  */
    tAPICONTRACT = 290,            /* tAPICONTRACT  */
    tAPPOBJECT = 291,              /* tAPPOBJECT  */
    tASYNC = 292,                  /* tASYNC  */
    tASYNCUUID = 293,              /* tASYNCUUID  */
    tAUTOHANDLE = 294,             /* tAUTOHANDLE  */
    tBINDABLE = 295,               /* tBINDABLE  */
    tBOOLEAN = 296,                /* tBOOLEAN  */
    tBROADCAST = 297,              /* tBROADCAST  */
    tBYTE = 298,                   /* tBYTE  */
    tBYTECOUNT = 299,              /* tBYTECOUNT  */
    tCALLAS = 300,                 /* tCALLAS  */
    tCALLBACK = 301,               /* tCALLBACK  */
    tCASE = 302,                   /* tCASE  */
    tCHAR = 303,                   /* tCHAR  */
    tCOCLASS = 304,                /* tCOCLASS  */
    tCODE = 305,                   /* tCODE  */
    tCOMMSTATUS = 306,             /* tCOMMSTATUS  */
    tCOMPOSABLE = 307,             /* tCOMPOSABLE  */
    tCONST = 308,                  /* tCONST  */
    tCONTEXTHANDLE = 309,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 310, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 311, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 312,               /* tCONTRACT  */
    tCONTRACTVERSION = 313,        /* tCONTRACTVERSION  */
    tCONTROL = 314,                /* tCONTROL  */
    tCPPQUOTE = 315,               /* tCPPQUOTE  */
    tCUSTOM = 316,                 /* tCUSTOM  */
    tDECLARE = 317,                /* tDECLARE  */
    tDECODE = 318,                 /* tDECODE  */
    tDEFAULT = 319,                /* tDEFAULT  */
    tDEFAULTBIND = 320,            /* tDEFAULTBIND  */
    tDELEGATE = 321,               /* tDELEGATE  */
    tDEFAULT_OVERLOAD = 322,       /* tDEFAULT_OVERLOAD  */
    tDEFAULTCOLLELEM = 323,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 324,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 325,          /* tDEFAULTVTABLE  */
    tDEPRECATED = 326,             /* tDEPRECATED  */
    tDISABLECONSISTENCYCHECK = 327, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 328,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 329,          /* tDISPINTERFACE  */
    tDLLNAME = 330,                /* tDLLNAME  */
    tDONTFREE = 331,               /* tDONTFREE  */
    tDOUBLE = 332,                 /* tDOUBLE  */
    tDUAL = 333,                   /* tDUAL  */
    tENABLEALLOCATE = 334,         /* tENABLEALLOCATE  */
    tENCODE = 335,                 /* tENCODE  */
    tENDPOINT = 336,               /* tENDPOINT  */
    tENTRY = 337,                  /* tENTRY  */
    tENUM = 338,                   /* tENUM  */
    tERRORSTATUST = 339,           /* tERRORSTATUST  */
    tEVENTADD = 340,               /* tEVENTADD  */
    tEVENTREMOVE = 341,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 342,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 343,         /* tEXPLICITHANDLE  */
    tEXTERN = 344,                 /* tEXTERN  */
    tFALSE = 345,                  /* tFALSE  */
    tFAULTSTATUS = 346,            /* tFAULTSTATUS  */
    tFLAGS = 347,                  /* tFLAGS  */
    tFLOAT = 348,                  /* tFLOAT  */
    tFORCEALLOCATE = 349,          /* tFORCEALLOCATE  */
    tHANDLE = 350,                 /* tHANDLE  */
    tHANDLET = 351,                /* tHANDLET  */
    tHELPCONTEXT = 352,            /* tHELPCONTEXT  */
    tHELPFILE = 353,               /* tHELPFILE  */
    tHELPSTRING = 354,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 355,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 356,          /* tHELPSTRINGDLL  */
    tHIDDEN = 357,                 /* tHIDDEN  */
    tHYPER = 358,                  /* tHYPER  */
    tID = 359,                     /* tID  */
    tIDEMPOTENT = 360,             /* tIDEMPOTENT  */
    tIGNORE = 361,                 /* tIGNORE  */
    tIIDIS = 362,                  /* tIIDIS  */
    tIMMEDIATEBIND = 363,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 364,         /* tIMPLICITHANDLE  */
    tIMPORT = 365,                 /* tIMPORT  */
    tIMPORTLIB = 366,              /* tIMPORTLIB  */
    tIN = 367,                     /* tIN  */
    tIN_LINE = 368,                /* tIN_LINE  */
    tINLINE = 369,                 /* tINLINE  */
    tINPUTSYNC = 370,              /* tINPUTSYNC  */
    tINT = 371,                    /* tINT  */
    tINT32 = 372,                  /* tINT32  */
    tINT3264 = 373,                /* tINT3264  */
    tINT64 = 374,                  /* tINT64  */
    tINTERFACE = 375,              /* tINTERFACE  */
    tLCID = 376,                   /* tLCID  */
    tLENGTHIS = 377,               /* tLENGTHIS  */
    tLIBRARY = 378,                /* tLIBRARY  */
    tLICENSED = 379,               /* tLICENSED  */
    tLOCAL = 380,                  /* tLOCAL  */
    tLONG = 381,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 382,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 383,                  /* tMAYBE  */
    tMESSAGE = 384,                /* tMESSAGE  */
    tMETHODS = 385,                /* tMETHODS  */
    tMODULE = 386,                 /* tMODULE  */
    tMTA = 387,                    /* tMTA  */
    tNAMESPACE = 388,              /* tNAMESPACE  */
    tNOCODE = 389,                 /* tNOCODE  */
    tNONBROWSABLE = 390,           /* tNONBROWSABLE  */
    tNONCREATABLE = 391,           /* tNONCREATABLE  */
    tNONE = 392,                   /* tNONE  */
    tNONEXTENSIBLE = 393,          /* tNONEXTENSIBLE  */
    tNOTIFY = 394,                 /* tNOTIFY  */
    tNOTIFYFLAG = 395,             /* tNOTIFYFLAG  */
    tNULL = 396,                   /* tNULL  */
    tOBJECT = 397,                 /* tOBJECT  */
    tODL = 398,                    /* tODL  */
    tOLEAUTOMATION = 399,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 400,               /* tOPTIMIZE  */
    tOPTIONAL = 401,               /* tOPTIONAL  */
    tOUT = 402,                    /* tOUT  */
    tOVERLOAD = 403,               /* tOVERLOAD  */
    tPARTIALIGNORE = 404,          /* tPARTIALIGNORE  */
    tPOINTERDEFAULT = 405,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 406,         /* tPRAGMA_WARNING  */
    tPROGID = 407,                 /* tPROGID  */
    tPROPERTIES = 408,             /* tPROPERTIES  */
    tPROPGET = 409,                /* tPROPGET  */
    tPROPPUT = 410,                /* tPROPPUT  */
    tPROPPUTREF = 411,             /* tPROPPUTREF  */
    tPROTECTED = 412,              /* tPROTECTED  */
    tPROXY = 413,                  /* tPROXY  */
    tPTR = 414,                    /* tPTR  */
    tPUBLIC = 415,                 /* tPUBLIC  */
    tRANGE = 416,                  /* tRANGE  */
    tREADONLY = 417,               /* tREADONLY  */
    tREF = 418,                    /* tREF  */
    tREGISTER = 419,               /* tREGISTER  */
    tREPRESENTAS = 420,            /* tREPRESENTAS  */
    tREQUESTEDIT = 421,            /* tREQUESTEDIT  */
    tREQUIRES = 422,               /* tREQUIRES  */
    tRESTRICTED = 423,             /* tRESTRICTED  */
    tRETVAL = 424,                 /* tRETVAL  */
    tRUNTIMECLASS = 425,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 426,              /* tSAFEARRAY  */
    tSHORT = 427,                  /* tSHORT  */
    tSIGNED = 428,                 /* tSIGNED  */
    tSINGLENODE = 429,             /* tSINGLENODE  */
    tSIZEIS = 430,                 /* tSIZEIS  */
    tSIZEOF = 431,                 /* tSIZEOF  */
    tSMALL = 432,                  /* tSMALL  */
    tSOURCE = 433,                 /* tSOURCE  */
    tSTANDARD = 434,               /* tSTANDARD  */
    tSTATIC = 435,                 /* tSTATIC  */
    tSTRICTCONTEXTHANDLE = 436,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 437,                 /* tSTRING  */
    tSTRUCT = 438,                 /* tSTRUCT  */
    tSWITCH = 439,                 /* tSWITCH  */
    tSWITCHIS = 440,               /* tSWITCHIS  */
    tSWITCHTYPE = 441,             /* tSWITCHTYPE  */
    tTHREADING = 442,              /* tTHREADING  */
    tTRANSMITAS = 443,             /* tTRANSMITAS  */
    tTRUE = 444,                   /* tTRUE  */
    tTYPEDEF = 445,                /* tTYPEDEF  */
    tUIDEFAULT = 446,              /* tUIDEFAULT  */
    tUNION = 447,                  /* tUNION  */
    tUNIQUE = 448,                 /* tUNIQUE  */
    tUNSIGNED = 449,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 450,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 451,            /* tUSERMARSHAL  */
    tUUID = 452,                   /* tUUID  */
    tV1ENUM = 453,                 /* tV1ENUM  */
    tVARARG = 454,                 /* tVARARG  */
    tVERSION = 455,                /* tVERSION  */
    tVIPROGID = 456,               /* tVIPROGID  */
    tVOID = 457,                   /* tVOID  */
    tWCHAR = 458,                  /* tWCHAR  */
    tWIREMARSHAL = 459,            /* tWIREMARSHAL  */
    tAPARTMENT = 460,              /* tAPARTMENT  */
    tNEUTRAL = 461,                /* tNEUTRAL  */
    tSINGLE = 462,                 /* tSINGLE  */
    tFREE = 463,                   /* tFREE  */
    tBOTH = 464,                   /* tBOTH  */
    CAST = 465,                    /* CAST  */
    PPTR = 466,                    /* PPTR  */
    POS = 467,                     /* POS  */
    NEG = 468,                     /* NEG  */
    ADDRESSOF = 469                /* ADDRESSOF  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
{
#line 134 "tools/widl/parser.y"

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
	struct uuid *uuid;
	unsigned int num;
	struct integer integer;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;
	struct namespace *namespace;

#line 494 "tools/widl/parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined PARSER_LTYPE && ! defined PARSER_LTYPE_IS_DECLARED
typedef struct PARSER_LTYPE PARSER_LTYPE;
struct PARSER_LTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define PARSER_LTYPE_IS_DECLARED 1
# define PARSER_LTYPE_IS_TRIVIAL 1
#endif




int parser_parse (void);

/* "%code provides" blocks.  */
#line 117 "tools/widl/parser.y"


int parser_lex( PARSER_STYPE *yylval, PARSER_LTYPE *yylloc );
void push_import( const char *fname, PARSER_LTYPE *yylloc );
PARSER_LTYPE pop_import(void);

# define YYLLOC_DEFAULT( cur, rhs, n ) \
        do { if (n) init_location( &(cur), &YYRHSLOC( rhs, 1 ), &YYRHSLOC( rhs, n ) ); \
             else init_location( &(cur), &YYRHSLOC( rhs, 0 ), NULL ); } while(0)


#line 534 "tools/widl/parser.tab.c"


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
  YYSYMBOL_tCDECL = 12,                    /* tCDECL  */
  YYSYMBOL_tFASTCALL = 13,                 /* tFASTCALL  */
  YYSYMBOL_tPASCAL = 14,                   /* tPASCAL  */
  YYSYMBOL_tSTDCALL = 15,                  /* tSTDCALL  */
  YYSYMBOL_aUUID = 16,                     /* aUUID  */
  YYSYMBOL_aEOF = 17,                      /* aEOF  */
  YYSYMBOL_aACF = 18,                      /* aACF  */
  YYSYMBOL_SHL = 19,                       /* SHL  */
  YYSYMBOL_SHR = 20,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 21,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 22,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 23,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 24,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 25,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 26,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 27,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 28,                  /* ELLIPSIS  */
  YYSYMBOL_tACTIVATABLE = 29,              /* tACTIVATABLE  */
  YYSYMBOL_tAGGREGATABLE = 30,             /* tAGGREGATABLE  */
  YYSYMBOL_tAGILE = 31,                    /* tAGILE  */
  YYSYMBOL_tALLNODES = 32,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 33,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 34,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 35,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 36,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 37,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 38,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 39,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 40,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 41,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 42,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 43,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 44,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 45,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 46,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 47,                     /* tCASE  */
  YYSYMBOL_tCHAR = 48,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 49,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 50,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 51,               /* tCOMMSTATUS  */
  YYSYMBOL_tCOMPOSABLE = 52,               /* tCOMPOSABLE  */
  YYSYMBOL_tCONST = 53,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 54,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 55, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 56,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 57,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 58,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 59,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 60,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 61,                   /* tCUSTOM  */
  YYSYMBOL_tDECLARE = 62,                  /* tDECLARE  */
  YYSYMBOL_tDECODE = 63,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 64,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 65,              /* tDEFAULTBIND  */
  YYSYMBOL_tDELEGATE = 66,                 /* tDELEGATE  */
  YYSYMBOL_tDEFAULT_OVERLOAD = 67,         /* tDEFAULT_OVERLOAD  */
  YYSYMBOL_tDEFAULTCOLLELEM = 68,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 69,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 70,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDEPRECATED = 71,               /* tDEPRECATED  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 72,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 73,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 74,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 75,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 76,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 77,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 78,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 79,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 80,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 81,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 82,                    /* tENTRY  */
  YYSYMBOL_tENUM = 83,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 84,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 85,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 86,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 87,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 88,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 89,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 90,                    /* tFALSE  */
  YYSYMBOL_tFAULTSTATUS = 91,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 92,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 93,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 94,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 95,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 96,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 97,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 98,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 99,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 100,       /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 101,           /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 102,                  /* tHIDDEN  */
  YYSYMBOL_tHYPER = 103,                   /* tHYPER  */
  YYSYMBOL_tID = 104,                      /* tID  */
  YYSYMBOL_tIDEMPOTENT = 105,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 106,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 107,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 108,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 109,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 110,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 111,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 112,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 113,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 114,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 115,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 116,                     /* tINT  */
  YYSYMBOL_tINT32 = 117,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 118,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 119,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 120,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 121,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 122,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 123,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 124,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 125,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 126,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 127,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 128,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 129,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 130,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 131,                  /* tMODULE  */
  YYSYMBOL_tMTA = 132,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 133,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 134,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 135,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 136,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 137,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 138,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 139,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 140,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 141,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 142,                  /* tOBJECT  */
  YYSYMBOL_tODL = 143,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 144,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 145,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 146,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 147,                     /* tOUT  */
  YYSYMBOL_tOVERLOAD = 148,                /* tOVERLOAD  */
  YYSYMBOL_tPARTIALIGNORE = 149,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPOINTERDEFAULT = 150,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 151,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 152,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 153,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 154,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 155,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 156,              /* tPROPPUTREF  */
  YYSYMBOL_tPROTECTED = 157,               /* tPROTECTED  */
  YYSYMBOL_tPROXY = 158,                   /* tPROXY  */
  YYSYMBOL_tPTR = 159,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 160,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 161,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 162,                /* tREADONLY  */
  YYSYMBOL_tREF = 163,                     /* tREF  */
  YYSYMBOL_tREGISTER = 164,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 165,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 166,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 167,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 168,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 169,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 170,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 171,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 172,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 173,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 174,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 175,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 176,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 177,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 178,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 179,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 180,                  /* tSTATIC  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 181,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 182,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 183,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 184,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 185,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 186,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 187,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 188,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 189,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 190,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 191,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 192,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 193,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 194,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 195,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 196,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 197,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 198,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 199,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 200,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 201,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 202,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 203,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 204,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 205,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 206,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 207,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 208,                    /* tFREE  */
  YYSYMBOL_tBOTH = 209,                    /* tBOTH  */
  YYSYMBOL_210_ = 210,                     /* ','  */
  YYSYMBOL_211_ = 211,                     /* '?'  */
  YYSYMBOL_212_ = 212,                     /* ':'  */
  YYSYMBOL_213_ = 213,                     /* '|'  */
  YYSYMBOL_214_ = 214,                     /* '^'  */
  YYSYMBOL_215_ = 215,                     /* '&'  */
  YYSYMBOL_216_ = 216,                     /* '<'  */
  YYSYMBOL_217_ = 217,                     /* '>'  */
  YYSYMBOL_218_ = 218,                     /* '-'  */
  YYSYMBOL_219_ = 219,                     /* '+'  */
  YYSYMBOL_220_ = 220,                     /* '*'  */
  YYSYMBOL_221_ = 221,                     /* '/'  */
  YYSYMBOL_222_ = 222,                     /* '%'  */
  YYSYMBOL_223_ = 223,                     /* '!'  */
  YYSYMBOL_224_ = 224,                     /* '~'  */
  YYSYMBOL_CAST = 225,                     /* CAST  */
  YYSYMBOL_PPTR = 226,                     /* PPTR  */
  YYSYMBOL_POS = 227,                      /* POS  */
  YYSYMBOL_NEG = 228,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 229,                /* ADDRESSOF  */
  YYSYMBOL_230_ = 230,                     /* '.'  */
  YYSYMBOL_231_ = 231,                     /* '['  */
  YYSYMBOL_232_ = 232,                     /* ']'  */
  YYSYMBOL_233_ = 233,                     /* ';'  */
  YYSYMBOL_234_ = 234,                     /* '{'  */
  YYSYMBOL_235_ = 235,                     /* '}'  */
  YYSYMBOL_236_ = 236,                     /* '('  */
  YYSYMBOL_237_ = 237,                     /* ')'  */
  YYSYMBOL_238_ = 238,                     /* '='  */
  YYSYMBOL_YYACCEPT = 239,                 /* $accept  */
  YYSYMBOL_input = 240,                    /* input  */
  YYSYMBOL_m_acf = 241,                    /* m_acf  */
  YYSYMBOL_decl_statements = 242,          /* decl_statements  */
  YYSYMBOL_decl_block = 243,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 244,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 245,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 246,           /* gbl_statements  */
  YYSYMBOL_247_1 = 247,                    /* $@1  */
  YYSYMBOL_imp_statements = 248,           /* imp_statements  */
  YYSYMBOL_249_2 = 249,                    /* $@2  */
  YYSYMBOL_int_statements = 250,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 251,            /* semicolon_opt  */
  YYSYMBOL_statement = 252,                /* statement  */
  YYSYMBOL_pragma_warning = 253,           /* pragma_warning  */
  YYSYMBOL_warnings = 254,                 /* warnings  */
  YYSYMBOL_typedecl = 255,                 /* typedecl  */
  YYSYMBOL_cppquote = 256,                 /* cppquote  */
  YYSYMBOL_import_start = 257,             /* import_start  */
  YYSYMBOL_import = 258,                   /* import  */
  YYSYMBOL_importlib = 259,                /* importlib  */
  YYSYMBOL_libraryhdr = 260,               /* libraryhdr  */
  YYSYMBOL_library_start = 261,            /* library_start  */
  YYSYMBOL_librarydef = 262,               /* librarydef  */
  YYSYMBOL_m_args = 263,                   /* m_args  */
  YYSYMBOL_arg_list = 264,                 /* arg_list  */
  YYSYMBOL_args = 265,                     /* args  */
  YYSYMBOL_arg = 266,                      /* arg  */
  YYSYMBOL_array = 267,                    /* array  */
  YYSYMBOL_m_attributes = 268,             /* m_attributes  */
  YYSYMBOL_attributes = 269,               /* attributes  */
  YYSYMBOL_attrib_list = 270,              /* attrib_list  */
  YYSYMBOL_str_list = 271,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 272,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 273,             /* contract_ver  */
  YYSYMBOL_contract_req = 274,             /* contract_req  */
  YYSYMBOL_static_attr = 275,              /* static_attr  */
  YYSYMBOL_activatable_attr = 276,         /* activatable_attr  */
  YYSYMBOL_access_attr = 277,              /* access_attr  */
  YYSYMBOL_composable_attr = 278,          /* composable_attr  */
  YYSYMBOL_deprecated_attr = 279,          /* deprecated_attr  */
  YYSYMBOL_attribute = 280,                /* attribute  */
  YYSYMBOL_callconv = 281,                 /* callconv  */
  YYSYMBOL_cases = 282,                    /* cases  */
  YYSYMBOL_case = 283,                     /* case  */
  YYSYMBOL_enums = 284,                    /* enums  */
  YYSYMBOL_enum_list = 285,                /* enum_list  */
  YYSYMBOL_enum_member = 286,              /* enum_member  */
  YYSYMBOL_enum = 287,                     /* enum  */
  YYSYMBOL_enumdef = 288,                  /* enumdef  */
  YYSYMBOL_m_exprs = 289,                  /* m_exprs  */
  YYSYMBOL_m_expr = 290,                   /* m_expr  */
  YYSYMBOL_expr = 291,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 292,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 293,           /* expr_int_const  */
  YYSYMBOL_expr_const = 294,               /* expr_const  */
  YYSYMBOL_fields = 295,                   /* fields  */
  YYSYMBOL_field = 296,                    /* field  */
  YYSYMBOL_ne_union_field = 297,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 298,          /* ne_union_fields  */
  YYSYMBOL_union_field = 299,              /* union_field  */
  YYSYMBOL_s_field = 300,                  /* s_field  */
  YYSYMBOL_funcdef = 301,                  /* funcdef  */
  YYSYMBOL_declaration = 302,              /* declaration  */
  YYSYMBOL_m_ident = 303,                  /* m_ident  */
  YYSYMBOL_m_typename = 304,               /* m_typename  */
  YYSYMBOL_typename = 305,                 /* typename  */
  YYSYMBOL_ident = 306,                    /* ident  */
  YYSYMBOL_base_type = 307,                /* base_type  */
  YYSYMBOL_m_int = 308,                    /* m_int  */
  YYSYMBOL_int_std = 309,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 310,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 311,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 312,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 313,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 314,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 315,                  /* coclass  */
  YYSYMBOL_coclassdef = 316,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 317,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 318,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 319,              /* apicontract  */
  YYSYMBOL_apicontract_def = 320,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 321,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 322,         /* class_interfaces  */
  YYSYMBOL_class_interface = 323,          /* class_interface  */
  YYSYMBOL_dispinterface = 324,            /* dispinterface  */
  YYSYMBOL_dispattributes = 325,           /* dispattributes  */
  YYSYMBOL_dispint_props = 326,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 327,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 328,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 329,                  /* inherit  */
  YYSYMBOL_type_parameter = 330,           /* type_parameter  */
  YYSYMBOL_type_parameters = 331,          /* type_parameters  */
  YYSYMBOL_interface = 332,                /* interface  */
  YYSYMBOL_333_3 = 333,                    /* $@3  */
  YYSYMBOL_334_4 = 334,                    /* $@4  */
  YYSYMBOL_delegatedef = 335,              /* delegatedef  */
  YYSYMBOL_336_5 = 336,                    /* $@5  */
  YYSYMBOL_337_6 = 337,                    /* $@6  */
  YYSYMBOL_required_types = 338,           /* required_types  */
  YYSYMBOL_requires = 339,                 /* requires  */
  YYSYMBOL_interfacedef = 340,             /* interfacedef  */
  YYSYMBOL_341_7 = 341,                    /* $@7  */
  YYSYMBOL_interfaceref = 342,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 343,         /* dispinterfaceref  */
  YYSYMBOL_module = 344,                   /* module  */
  YYSYMBOL_moduledef = 345,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 346,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 347,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 348,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 349,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 350,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 351,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 352,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 353,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 354,               /* declarator  */
  YYSYMBOL_direct_declarator = 355,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 356,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 357, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 358,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 359, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 360,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 361, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 362,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 363,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 364,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 365,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 366,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 367,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 368,          /* init_declarator  */
  YYSYMBOL_threading_type = 369,           /* threading_type  */
  YYSYMBOL_pointer_type = 370,             /* pointer_type  */
  YYSYMBOL_structdef = 371,                /* structdef  */
  YYSYMBOL_unqualified_type = 372,         /* unqualified_type  */
  YYSYMBOL_type = 373,                     /* type  */
  YYSYMBOL_typedef = 374,                  /* typedef  */
  YYSYMBOL_uniondef = 375,                 /* uniondef  */
  YYSYMBOL_version = 376,                  /* version  */
  YYSYMBOL_acf_statements = 377,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 378,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 379,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 380,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 381,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 382,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 383,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 384,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 385           /* allocate_option  */
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

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
         || (defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL \
             && defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   3682

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  500
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  924

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   469


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
       2,     2,     2,   223,     2,     2,     2,   222,   215,     2,
     236,   237,   220,   219,   210,   218,   230,   221,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   212,   233,
     216,   238,   217,   211,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   231,     2,   232,   214,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   234,   213,   235,   224,     2,     2,     2,
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
     205,   206,   207,   208,   209,   225,   226,   227,   228,   229
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   370,   370,   387,   388,   392,   393,   399,   403,   404,
     409,   413,   414,   414,   416,   417,   418,   419,   420,   423,
     426,   427,   429,   430,   432,   433,   434,   435,   439,   440,
     441,   442,   442,   444,   445,   446,   447,   450,   451,   453,
     454,   456,   457,   458,   459,   460,   464,   465,   469,   470,
     474,   475,   476,   477,   478,   479,   480,   483,   491,   499,
     500,   504,   505,   506,   507,   508,   509,   510,   511,   512,
     515,   518,   520,   523,   527,   529,   533,   538,   539,   542,
     543,   546,   547,   551,   556,   563,   567,   568,   572,   573,
     577,   580,   581,   582,   585,   586,   590,   591,   592,   596,
     597,   601,   611,   618,   622,   626,   627,   631,   639,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     668,   669,   670,   671,   672,   673,   674,   675,   676,   677,
     678,   679,   680,   681,   682,   683,   684,   685,   686,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   700,   701,
     702,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   717,   718,   719,   720,   721,   722,
     723,   724,   725,   726,   727,   728,   729,   730,   731,   732,
     733,   734,   735,   736,   737,   738,   739,   740,   741,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   773,   774,   775,   776,   780,   781,
     784,   788,   795,   796,   797,   800,   806,   823,   828,   832,
     837,   840,   841,   845,   846,   849,   850,   851,   852,   854,
     856,   858,   859,   860,   861,   862,   863,   864,   865,   866,
     867,   868,   869,   870,   871,   872,   873,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,   885,   886,
     887,   888,   889,   891,   893,   894,   897,   898,   901,   907,
     914,   915,   918,   923,   930,   931,   935,   936,   940,   941,
     944,   948,   954,   962,   966,   972,   973,   977,   978,   981,
     982,   985,   988,   989,   990,   991,   992,   993,   994,   995,
     996,   997,   998,  1002,  1003,  1006,  1007,  1008,  1009,  1010,
    1011,  1012,  1013,  1014,  1018,  1019,  1023,  1024,  1027,  1032,
    1033,  1034,  1035,  1036,  1040,  1041,  1045,  1048,  1052,  1055,
    1060,  1063,  1067,  1068,  1072,  1073,  1077,  1078,  1081,  1084,
    1087,  1088,  1091,  1092,  1096,  1098,  1103,  1104,  1105,  1108,
    1112,  1113,  1117,  1118,  1118,  1118,  1122,  1127,  1128,  1126,
    1135,  1136,  1137,  1138,  1142,  1143,  1146,  1146,  1159,  1163,
    1164,  1165,  1169,  1172,  1175,  1180,  1181,  1182,  1186,  1190,
    1194,  1195,  1198,  1199,  1203,  1205,  1210,  1211,  1215,  1216,
    1217,  1221,  1223,  1224,  1228,  1229,  1230,  1231,  1236,  1238,
    1239,  1244,  1246,  1251,  1252,  1257,  1258,  1259,  1260,  1264,
    1272,  1274,  1275,  1280,  1282,  1287,  1288,  1295,  1296,  1297,
    1298,  1299,  1303,  1310,  1311,  1315,  1316,  1319,  1326,  1327,
    1332,  1333,  1337,  1338,  1339,  1340,  1341,  1342,  1346,  1347,
    1348,  1351,  1355,  1356,  1357,  1358,  1359,  1360,  1361,  1362,
    1363,  1364,  1368,  1369,  1370,  1373,  1380,  1382,  1388,  1389,
    1390,  1394,  1395,  1399,  1400,  1404,  1411,  1420,  1421,  1425,
    1426,  1430,  1432,  1433,  1434,  1438,  1439,  1444,  1445,  1446,
    1447
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
  "aWSTRING", "aSQSTRING", "tCDECL", "tFASTCALL", "tPASCAL", "tSTDCALL",
  "aUUID", "aEOF", "aACF", "SHL", "SHR", "MEMBERPTR", "EQUALITY",
  "INEQUALITY", "GREATEREQUAL", "LESSEQUAL", "LOGICALOR", "LOGICALAND",
  "ELLIPSIS", "tACTIVATABLE", "tAGGREGATABLE", "tAGILE", "tALLNODES",
  "tALLOCATE", "tANNOTATION", "tAPICONTRACT", "tAPPOBJECT", "tASYNC",
  "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN", "tBROADCAST",
  "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE", "tCHAR",
  "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCOMPOSABLE", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTRACT", "tCONTRACTVERSION", "tCONTROL", "tCPPQUOTE", "tCUSTOM",
  "tDECLARE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDELEGATE",
  "tDEFAULT_OVERLOAD", "tDEFAULTCOLLELEM", "tDEFAULTVALUE",
  "tDEFAULTVTABLE", "tDEPRECATED", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE",
  "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEVENTADD", "tEVENTREMOVE", "tEXCLUSIVETO",
  "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFAULTSTATUS", "tFLAGS",
  "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET", "tHELPCONTEXT",
  "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL",
  "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE", "tIIDIS",
  "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB", "tIN",
  "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE",
  "tMETHODS", "tMODULE", "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE",
  "tNONCREATABLE", "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG",
  "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL",
  "tOUT", "tOVERLOAD", "tPARTIALIGNORE", "tPOINTERDEFAULT",
  "tPRAGMA_WARNING", "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT",
  "tPROPPUTREF", "tPROTECTED", "tPROXY", "tPTR", "tPUBLIC", "tRANGE",
  "tREADONLY", "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT",
  "tREQUIRES", "tRESTRICTED", "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY",
  "tSHORT", "tSIGNED", "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL",
  "tSOURCE", "tSTANDARD", "tSTATIC", "tSTRICTCONTEXTHANDLE", "tSTRING",
  "tSTRUCT", "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING",
  "tTRANSMITAS", "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE",
  "tUNSIGNED", "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM",
  "tVARARG", "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL",
  "tAPARTMENT", "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'",
  "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'",
  "'['", "']'", "';'", "'{'", "'}'", "'('", "')'", "'='", "$accept",
  "input", "m_acf", "decl_statements", "decl_block", "imp_decl_statements",
  "imp_decl_block", "gbl_statements", "$@1", "imp_statements", "$@2",
  "int_statements", "semicolon_opt", "statement", "pragma_warning",
  "warnings", "typedecl", "cppquote", "import_start", "import",
  "importlib", "libraryhdr", "library_start", "librarydef", "m_args",
  "arg_list", "args", "arg", "array", "m_attributes", "attributes",
  "attrib_list", "str_list", "marshaling_behavior", "contract_ver",
  "contract_req", "static_attr", "activatable_attr", "access_attr",
  "composable_attr", "deprecated_attr", "attribute", "callconv", "cases",
  "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident",
  "m_typename", "typename", "ident", "base_type", "m_int", "int_std",
  "namespace_pfx", "qualified_type", "parameterized_type",
  "parameterized_type_arg", "parameterized_type_args", "coclass",
  "coclassdef", "runtimeclass", "runtimeclass_def", "apicontract",
  "apicontract_def", "namespacedef", "class_interfaces", "class_interface",
  "dispinterface", "dispattributes", "dispint_props", "dispint_meths",
  "dispinterfacedef", "inherit", "type_parameter", "type_parameters",
  "interface", "$@3", "$@4", "delegatedef", "$@5", "$@6", "required_types",
  "requires", "interfacedef", "$@7", "interfaceref", "dispinterfaceref",
  "module", "moduledef", "storage_cls_spec", "function_specifier",
  "type_qualifier", "m_type_qual_list", "decl_spec",
  "unqualified_decl_spec", "m_decl_spec_no_type", "decl_spec_no_type",
  "declarator", "direct_declarator", "abstract_declarator",
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

#define YYPACT_NINF (-670)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-488)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -670,    72,  1817,  -670,  -120,  -670,   -88,   -40,   372,  -670,
    -670,  -670,   372,  -670,   -56,   -67,   372,  -670,   372,  -670,
    -670,  -670,  -670,    76,   200,  -670,  -670,  -670,  -670,  -670,
     372,    76,   176,   -24,  -670,   372,   -12,    76,   565,  -670,
    -670,   372,   372,   565,  -670,  -670,  3478,  -670,  -670,  -670,
    -670,    11,  -670,  -670,  -670,  -670,  -670,    94,  2869,    65,
      97,  -670,  -670,  -670,   389,    33,  -670,   117,  -670,   123,
    -670,   137,  -670,   -53,   188,   191,   193,   197,  -670,  -670,
    -670,    41,    41,    41,   159,  3145,   213,  -670,    41,   214,
     215,  -670,    57,  -670,   -40,   264,  -670,  -670,  -670,  -670,
     253,  -670,  -670,   153,   -91,  -670,  -670,   216,   187,  -670,
    -670,    58,  -670,  3145,  -670,  -670,   219,   -75,   -82,   -80,
    -670,   222,  -670,   230,  -670,  -670,   234,  -670,  -670,  -670,
     237,   238,  -670,  -670,   239,  -670,  -670,  -670,   246,   247,
    -670,   250,  -670,  -670,  -670,  -670,  -670,   251,  -670,   252,
    -670,  -670,   255,  -670,  -670,  -670,   256,   258,  -670,  -670,
     259,  -670,  -670,  -670,  -670,  -670,   260,   262,   265,   266,
     275,  -670,   276,  -670,  -670,   277,  -670,   278,  -670,  -670,
     279,   280,  -670,  -670,   281,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,   284,  -670,  -670,   285,
    -670,   286,   291,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
     292,  -670,  -670,   293,  -670,  -670,  -670,   297,  -670,   299,
    -670,  -670,   300,   302,   305,   309,  -670,  -670,  -670,   310,
     318,  -670,  -670,   327,   332,   333,  -119,  -670,  -670,  -670,
    1950,  1089,  3145,   372,   224,   231,   372,   372,   372,   372,
     337,   345,   346,   367,   349,  -670,   159,   352,   358,  -670,
     377,   273,  3081,  -670,  -670,  -670,   605,  -670,  -670,   375,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,  -670,   159,   159,  -670,  -670,   374,    63,  -670,  -670,
    -670,    41,  -670,  -670,  -670,   380,  -670,  -670,  -670,   -64,
    -670,  -670,   614,   373,   -57,    69,  -670,  -670,   409,   410,
     386,  -670,   388,  -670,  3053,   616,   612,   372,   261,  3053,
    3053,   623,   617,   261,   621,   628,   629,   261,  3053,   261,
     632,   635,   261,   644,   261,   261,  2359,   261,   261,    80,
     645,   646,   -32,   647,   261,  3145,   261,  3053,   261,  3145,
     391,  3145,  3145,   620,   272,   648,  3145,  3478,   427,  -670,
     426,   425,  -670,  -670,  -670,  -670,   429,  -670,   430,  -670,
     431,  -670,    98,   437,   440,  -670,  -670,  -670,   193,   372,
    -670,  3053,  -670,  -670,   442,  -670,   442,   -59,  -670,  -670,
     422,   443,   439,   367,  -670,  -670,  -670,   389,   149,   458,
    -670,   114,  -670,  -670,   -21,   103,   448,  -670,   261,   192,
    2359,  -670,  -670,    89,    57,  -670,   446,  -670,   422,  -670,
     372,   452,   478,   454,  -670,   372,   684,   684,  -670,   141,
     224,   151,  -670,   456,   484,   459,   460,   461,  -670,  -670,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,   464,  -670,   261,
     261,   261,   261,   261,   261,   887,  2613,   -98,  -670,   465,
     485,   466,   494,   477,   471,   506,  2613,   480,   508,   482,
     486,  -670,     8,   488,   490,   491,   492,   493,   496,   497,
     498,  1017,   501,  3053,   135,   502,    51,  -670,  2613,  -670,
    -670,  -670,   503,   504,   507,   523,   524,   511,   526,   108,
     527,   521,  2394,   528,  -670,  -670,  -670,  -670,  -670,  -670,
     529,   530,   531,   532,   513,  -670,   533,   535,   536,  -670,
    3478,  -670,   736,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
     -50,   159,  1457,   154,    33,  -670,  -670,   193,   608,  -670,
    -670,  -670,  3081,  -670,  1355,   564,   -61,   544,  -670,  -670,
    -670,  -670,   220,  -670,  2492,   541,   569,  -670,  -670,  -670,
    -670,  -670,  -670,   112,  -670,  -670,   590,   566,  -670,  -670,
     162,   261,  -670,  -670,   573,  -670,    36,    49,  -670,  3053,
    -670,  3053,   547,  -670,   552,  -670,   553,  -670,  2961,  -670,
    -670,  -670,  3237,    50,    50,    50,    50,    50,    50,  -670,
    2467,   170,  3319,    41,   261,   261,   785,   261,   261,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   788,   261,   261,  -670,  -670,   -31,
    -670,   623,   789,  -670,   261,  -670,   791,  -670,  -670,   787,
    -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,  -670,
    -670,   135,  -670,  2083,  -670,   135,  -670,  -670,  -670,   127,
    -670,   261,  -670,  -670,  -670,  -670,  -670,  -670,   261,  -670,
    -670,  -670,  3053,  -670,  -670,  -670,  -670,  -670,  -670,   792,
    -670,  -670,  -670,  -670,   -20,   560,  -670,  -670,  2359,  -670,
     591,   193,  -670,   610,  3053,   193,    13,  -670,   182,  -670,
     422,   568,  -670,  -670,  -670,   593,   570,  1661,   571,  -670,
    -670,  -670,  2267,    89,  -670,   577,   575,   590,  3081,  -670,
    -670,   372,   594,  -670,  -670,  -670,   135,   579,   159,   185,
     372,  -670,  -670,  -670,  -670,   170,  -670,  -670,  2175,  -670,
     170,  -670,   576,   131,    41,  -670,   384,   384,  -670,   288,
     288,   627,   627,   802,  2632,  2572,   727,  2649,  2671,   627,
     627,   211,   211,    50,    50,    50,  -670,  2544,  -670,  -670,
    -670,   604,  -670,   578,   606,  -670,  -670,    83,  -670,   581,
     135,   582,  -670,  2359,  -670,  -670,   583,  -670,  -670,   422,
    -670,   193,  1222,   372,   595,   159,  -670,  -670,   372,   422,
     597,   598,   193,    33,  -670,   624,  -670,  -670,  -670,  -670,
    3053,   600,  -670,  -670,  -670,  -670,  -670,   830,  -670,  -670,
     130,  -670,  -670,   625,  -670,   -76,  -670,  -670,   609,  -670,
     601,    70,  -670,   602,   135,   603,  -670,   261,  2359,  -670,
    -670,   261,  -670,  3053,  -670,  3053,  -670,    83,  -670,  -670,
    -670,   607,  -670,   626,  -670,  -670,   136,   193,  -670,  -670,
     618,   389,  -670,  -670,  -670,  -670,   422,  1559,  -670,   630,
     631,   261,  -670,   135,  -670,  -670,  -670,  -670,    83,  -670,
    -670,  -670,    50,   622,  2613,  -670,  -670,  -670,  -670,  3081,
     633,  -670,   637,    33,  -670,   193,  -670,  -670,  -670,  -670,
      60,  -670,  -670,   142,  2359,  -670,   261,   641,  -670,  -670,
     638,   636,   642,   203,  -670,  -670,   203,  -670,  -670,   643,
     193,  -670,  -670,  -670
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   309,    55,   471,   481,     0,   320,
     312,   331,     0,   399,     0,     0,     0,   319,   307,   321,
     395,   318,   322,   323,     0,   398,   325,   332,   333,   330,
       0,   323,     0,     0,   397,     0,     0,   323,     0,   327,
     396,   307,   307,   317,   462,   313,   109,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   464,
       0,   336,   463,   314,     0,     0,   474,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   406,   406,   406,     0,     0,   466,   472,   406,     0,
     468,   334,     0,     4,   481,     0,   309,   310,   350,   346,
       0,     5,   358,     0,   465,   324,   329,     0,   372,   328,
     352,     0,   348,     0,   326,   315,     0,   467,     0,   469,
     316,     0,   111,     0,   113,   114,     0,   115,   116,   117,
       0,     0,   120,   122,     0,   123,   124,   125,     0,     0,
     128,     0,   130,   131,   133,   132,   134,     0,   136,     0,
     138,   139,     0,   141,   142,   143,     0,     0,   146,   147,
       0,   149,   150,   151,   152,   153,     0,     0,     0,     0,
       0,   159,     0,   161,   162,     0,   164,     0,   166,   167,
     170,     0,   171,   172,     0,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,     0,   186,   187,     0,
     189,     0,     0,   192,   193,   194,   195,   196,   460,   197,
       0,   199,   458,     0,   201,   202,   203,     0,   205,     0,
     207,   208,     0,     0,     0,     0,   213,   459,   214,     0,
       0,   218,   219,     0,     0,     0,     0,    91,   223,    51,
      88,    88,     0,     0,    88,     0,   307,     0,   307,   307,
       0,   464,     0,   366,     0,   386,     0,   466,   468,    52,
     309,   473,     0,    18,    22,    20,     0,    12,    15,     0,
      49,   388,    14,   410,   407,   409,   408,   224,   225,   226,
     227,   400,     0,     0,   311,   414,   450,   413,   304,   464,
     466,   406,   468,   402,    54,     0,   493,   492,   494,     0,
     489,   482,     0,     0,     0,    88,    71,   373,     0,     0,
       0,   290,     0,   296,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   243,     0,
       0,     0,     0,     0,     0,     0,   243,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,    90,    72,
       0,     0,    45,    42,    43,    44,     0,    36,     0,    40,
       0,    38,     0,     0,     0,    34,    33,    41,    48,     0,
     393,     0,    89,    46,   465,    74,   467,   469,    75,   354,
       0,     0,     0,   366,   303,   335,   339,     0,   340,   342,
     344,     0,   353,    11,     0,     0,     0,   412,     0,     0,
      77,   416,   403,     0,     0,   488,     0,    70,     0,     7,
       0,     0,   234,   239,   235,     0,     0,     0,   470,    88,
      88,    88,   104,     0,     0,     0,     0,     0,   254,   245,
     246,   247,   251,   252,   253,   248,   249,     0,   250,     0,
       0,     0,     0,     0,     0,     0,   288,     0,   286,     0,
       0,     0,     0,    99,     0,     0,   289,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   435,     0,     0,   241,   244,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   457,   452,   453,   454,   455,   456,
       0,     0,     0,     0,   478,   480,     0,     0,     0,    92,
     109,     8,     0,    35,    39,    37,    31,    30,    29,    76,
       0,     0,    88,    88,   367,   368,   354,    48,   384,   337,
     341,   343,     0,   338,    88,     0,    88,     0,   401,   411,
     415,   451,     0,    87,     0,     0,    81,    78,    79,   499,
     497,   500,   498,     0,   495,   490,   483,     0,   237,   240,
      88,     0,   369,   370,   374,    59,     0,     0,   461,     0,
     291,     0,     0,   476,    89,   297,     0,   110,     0,   112,
     217,   118,     0,   278,   277,   276,   279,   274,   275,   471,
       0,   423,     0,   406,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   121,     0,
     126,     0,     0,   127,     0,   135,     0,   137,   140,     0,
     144,   145,   148,   154,   155,   156,   157,   158,   160,   163,
     165,   435,   400,    77,   440,   435,   437,   436,    84,   432,
     169,   243,   168,   173,   185,   188,   190,   191,     0,   200,
     204,   206,     0,   209,   210,   212,   211,   215,   216,     0,
     220,   221,   222,    93,     0,     0,    28,   377,    77,   443,
     475,    48,    47,     0,    89,    48,     0,   355,    88,   351,
       0,     0,   345,    13,   360,     0,     0,     0,     0,    86,
      85,   417,     0,     0,   491,   487,     0,   483,     0,   236,
     238,     0,     0,    60,    57,    58,     0,   468,     0,   466,
     305,   295,   294,   101,   103,   423,   285,   400,    77,   427,
     423,   424,     0,   420,   406,   404,   267,   268,   280,   261,
     262,   265,   266,   256,   257,     0,   258,   259,   260,   264,
     263,   270,   269,   272,   273,   271,   281,     0,   287,   106,
     105,     0,   100,     0,     0,    95,    83,   435,   400,     0,
     435,     0,   431,    77,   439,   242,     0,   102,   479,     0,
      10,    48,    88,     0,     0,     0,   394,   347,     0,     0,
       0,     0,    48,   380,   381,   385,    46,   362,   361,   364,
       0,     0,   302,   365,    82,    80,   496,     0,   486,   484,
       0,   371,   375,   445,   448,     0,   293,   300,     0,   306,
       0,   423,   400,     0,   435,     0,   419,     0,    77,   426,
     405,     0,   284,     0,   129,     0,   430,   435,   441,   434,
     438,     0,   198,     0,    73,    32,     0,    48,   444,   392,
     336,     0,   391,   356,   357,   349,     0,    88,   363,     0,
       0,     0,   447,     0,   292,   228,   283,   418,   435,   428,
     422,   425,   282,     0,   255,   107,   108,   433,   442,     0,
       0,   376,   337,   382,   383,    48,   485,     6,   446,   449,
       0,   421,   429,     0,    77,   387,     0,     0,   477,   229,
       0,     0,     0,    88,     9,   378,    88,   299,   231,     0,
      48,   230,   298,   379
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -670,  -670,  -670,  -670,  -670,  -670,  -670,   457,  -670,   -51,
    -670,    55,  -331,    -1,  -670,   435,  -670,  -670,  -670,  -670,
    -670,  -670,  -670,    29,  -587,  -670,  -670,  -314,  -276,  -241,
      -2,  -670,  -670,  -670,   554,  -268,  -670,  -670,  -670,  -670,
    -670,  -298,   -69,  -670,  -670,  -670,  -670,  -670,   298,    17,
     534,   217,   304,  -670,  -288,  -319,  -670,  -670,  -670,  -670,
     -39,  -338,  -670,   174,  -670,    26,    -6,   -63,  -257,   229,
     173,  -249,  -255,  -246,   341,  -656,    18,    30,    21,    32,
      23,    37,    38,   350,  -670,    28,  -670,  -670,  -670,  -670,
     495,   164,    96,    16,  -670,  -670,    43,  -670,  -670,  -670,
    -670,    46,  -670,  -670,  -670,  -670,    48,  -670,  -670,  -354,
    -543,     7,   295,   -45,   -55,  -229,  -670,  -670,  -670,  -621,
    -670,  -669,  -670,  -277,  -670,  -670,  -670,    27,  -670,   649,
    -670,   549,    12,  -395,    -8,  -670,    15,  -670,   805,   184,
    -670,  -670,   189,  -670,   489,  -670,   194
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    47,   304,    48,   684,   362,     2,   403,   240,
     686,   532,   271,   363,    50,   576,    51,    52,    53,    54,
     364,   250,    55,   365,   555,   556,   557,   558,   654,    57,
     382,   236,   472,   492,   733,   432,   500,   433,   771,   459,
     469,   237,   655,   900,   909,   421,   422,   423,   424,   289,
     486,   487,   456,   457,   458,   467,   429,   580,   585,   431,
     918,   919,   811,    60,   828,   103,    61,   656,    62,   106,
      63,    64,    65,    66,   400,   401,   366,   367,   368,   369,
     370,   371,   372,   533,   697,   373,    75,   546,   707,    76,
     391,   573,   574,   374,   425,   722,   375,   793,   920,   805,
     701,   376,   393,   800,   801,   245,   377,    81,    82,    83,
     405,   484,   601,   273,    85,   286,   287,   741,   835,   742,
     743,   657,   781,   658,   659,   690,   872,   824,   825,   288,
     510,   238,   290,    87,    88,    89,   292,   516,    93,   716,
     717,    94,    95,   299,   300,   563,   564
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    49,    98,   381,   241,   396,    99,   398,   473,    84,
     102,   411,   104,   397,    86,   283,   399,    90,    77,    59,
      67,   285,   482,    69,   108,    71,   274,   274,   274,   112,
      74,    56,    68,   274,    70,   117,   119,   275,   276,    72,
      73,   475,   723,   293,   478,    78,   480,   529,    79,   485,
      80,   548,   461,   406,   407,   723,   497,   823,   261,   519,
     603,   308,   820,   418,   420,   256,   779,   116,   118,   705,
     257,   606,     3,   258,   255,   251,   252,   291,   284,   253,
    -487,   254,   277,   278,   279,   280,    96,   798,    97,   551,
     295,   357,   582,   586,    13,   277,   278,   279,   280,    30,
     789,   794,   312,   269,  -308,   310,    96,   906,    97,   777,
      91,   489,   626,   358,   830,   277,   278,   279,   280,   836,
     296,   559,   309,    13,   907,  -308,   769,   208,  -310,   770,
      20,   212,   545,   799,   873,   534,    13,   297,    96,   627,
      97,   397,   -62,  -308,   535,   298,   414,   277,   278,   279,
     280,   833,   313,   -66,  -308,    25,    13,   874,   -64,  -308,
     242,   227,    96,   567,    97,   560,   687,   101,   415,   397,
      46,   277,   278,   279,   280,  -308,   549,   266,   419,   110,
     100,   267,   277,   278,   279,   280,   688,   283,   579,   581,
     581,    92,   105,   285,   831,   438,   851,   603,   439,   440,
     441,   442,   443,   444,   823,    34,   699,   744,   706,   107,
     877,   115,   111,   283,   283,   790,   120,   490,   639,   285,
     285,    40,   683,   438,   113,   243,   439,   440,   441,   442,
     443,   444,   606,   903,   379,   847,   274,   380,    58,    58,
     384,   385,   386,   387,   239,   640,   412,    84,    84,   262,
     284,   883,    86,    86,   437,    90,    90,    59,    59,   491,
     109,   661,   303,   561,   438,    16,   114,   439,   440,   441,
     442,   443,   444,   724,   116,   118,   284,   284,   514,   515,
     624,   625,   445,   720,   244,   396,   725,   398,   662,   878,
     737,   693,   696,   397,   409,   908,   399,   562,   -61,   410,
      46,   409,   689,   652,  -232,   581,   738,   604,   605,   606,
     445,   284,   609,   610,   409,   773,   530,   911,   661,   653,
     734,   434,   713,   281,   542,   739,   460,   462,   266,   420,
     259,   543,   526,   446,   483,   474,   283,   498,   768,   282,
     542,   503,   285,   511,   512,   670,   721,   870,   518,   714,
     263,   445,   542,   890,   501,   652,   264,   568,   409,   910,
     796,   446,   409,   783,   797,   262,   409,   838,   447,   540,
     265,   653,    46,   284,   776,    96,   578,    97,   782,   281,
     786,   448,    46,   784,   302,    46,   583,   305,   531,   695,
     737,   539,   260,    46,    97,   282,   447,  -233,   815,   284,
     602,   409,   446,   307,   787,   606,   738,   449,   483,   448,
     450,   451,   552,    46,   284,   453,   454,   802,  -301,   572,
     547,   268,  -301,   548,   553,     4,   270,    97,   455,   584,
     272,   621,   622,   623,    46,   449,   917,   447,   450,   451,
     452,   624,   625,   453,   454,   803,   -63,   294,   -65,   306,
     448,   397,   709,   311,   804,    46,   455,   696,   314,   739,
     854,   396,   283,   398,   739,   383,   315,   839,   285,   397,
     316,   865,   399,   317,   318,   319,   449,   548,   284,   450,
     451,   452,   320,   321,   453,   454,   322,   323,   324,  -337,
     651,   325,   326,   548,   327,   328,   329,   455,   330,   827,
     846,   331,   332,   849,   617,   618,   619,   620,   621,   622,
     623,   333,   334,   335,   336,   337,   338,   339,   624,   625,
     340,   341,   342,   504,   548,   284,   891,   343,   344,   345,
     694,   692,   740,   346,   853,   347,   348,   602,   349,    84,
     397,   350,    58,    49,    86,   351,   352,    90,   274,    59,
     861,    84,   898,   862,   353,   739,    86,   880,   745,    90,
      77,    59,    67,   354,   905,    69,   858,    71,   355,   356,
     887,   388,    74,    56,    68,   885,    70,   886,   -67,   390,
     389,    72,    73,   392,   780,   -68,   726,    78,   728,   923,
      79,   -69,    80,   729,   727,   462,   505,   506,   507,   508,
     509,   901,   619,   620,   621,   622,   623,   395,   402,   404,
     417,   893,   408,    11,   624,   625,   413,   397,   912,   416,
     894,   426,   427,   428,   430,   435,   693,   466,   436,   463,
     468,   466,   396,   465,   398,   792,   513,   470,   471,   481,
     397,   476,   488,   399,   477,   284,   604,   605,   606,   284,
     488,   483,   502,   479,   493,   494,   496,   517,   520,   283,
     521,   522,   523,   524,   525,   285,   740,   829,    23,   834,
     527,   740,   581,   528,   537,   581,  -308,   536,   541,   462,
     566,    26,    27,    28,    29,   550,   483,   569,   570,   274,
     575,    31,   571,   587,   588,   629,   589,   590,   591,   840,
     592,   256,   628,   630,   631,   810,   257,   632,   633,   258,
     483,   251,   466,   554,    84,   572,   634,   635,   636,   637,
     284,   668,   284,   638,   284,   641,   283,   642,   643,   644,
     645,   672,   285,   646,   647,   648,   483,    37,   650,   660,
     663,   664,    39,   679,   665,   685,   604,   605,   606,   607,
     608,   609,   610,   593,   594,   595,   596,   597,   598,   600,
     666,   667,   740,   669,   671,   674,   675,   676,   677,   678,
     680,   284,   681,   682,   284,   700,   704,   708,   711,   712,
     715,   483,   718,   721,   730,   731,   732,   572,   748,   284,
      58,   766,   859,   860,   774,   772,   775,   791,   788,    84,
     244,   795,   806,   808,    86,   807,   813,    90,    92,    59,
     818,   822,   826,   837,   843,   844,   845,   256,   848,   850,
     852,   604,   605,   606,   607,   608,   609,   610,   284,   612,
     863,   864,   857,   868,   866,   869,   483,   871,   876,   879,
     881,   284,   889,   875,   888,   619,   620,   621,   622,   623,
     462,  -389,   462,   913,   916,   892,   596,   624,   625,   902,
     544,   867,   577,   896,   897,   694,   692,   284,   719,   904,
    -390,   914,   284,   915,    84,   464,   922,   921,   785,    86,
     499,   812,    90,   702,    59,   821,   698,   735,   538,   856,
     438,   495,   599,   439,   440,   441,   442,   443,   444,   301,
     899,   819,   483,   565,   817,   394,     0,   816,   746,   747,
       0,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,     9,   767,
      10,     0,     0,     0,     0,    11,     0,     0,   466,     0,
      13,   615,   616,   617,   618,   619,   620,   621,   622,   623,
       0,     0,     0,     0,     0,     0,     0,   624,   625,     0,
       0,     0,     0,     0,    17,   488,     0,     0,     0,     0,
     246,    19,     0,     0,     0,     0,    20,   445,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,     0,     0,     0,   446,     0,
       0,     0,   624,   625,     0,     0,   604,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,   447,    39,     0,     0,    40,     0,     0,
     248,     0,     0,     0,     0,     0,   448,     0,     0,   249,
       0,    43,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,   449,     0,     0,   450,   451,   452,     0,     0,
     453,   454,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   455,     8,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,    11,    12,     0,
       0,   882,    13,     0,     0,   884,     0,     0,     0,    14,
       0,   360,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    17,     0,     0,     0,
       0,     0,    18,    19,     0,   466,     0,     0,    20,     0,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
     361,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     4,     5,     6,   613,     0,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
      33,     0,     0,     0,     0,     0,     0,   624,   625,     0,
       0,     0,     0,    34,   649,     0,     0,     8,     0,    35,
      36,    37,    38,     9,     0,    10,    39,     0,     0,    40,
      11,    12,    41,     0,     0,    13,     0,     0,     0,     0,
       0,    42,    14,    43,   360,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,    16,     0,     0,    17,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     0,     0,    22,     0,
      46,     0,     0,     0,   378,    23,     0,     0,     0,     0,
       0,     0,    24,   361,     0,     0,    25,     0,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       8,     0,    35,    36,    37,    38,     9,     0,    10,    39,
       0,     0,    40,    11,    12,    41,     0,     0,    13,     0,
       0,     0,     0,     0,    42,    14,    43,    15,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,     0,    16,
       0,     0,    17,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,    22,     0,    46,     0,     0,     0,   855,    23,     0,
       4,     5,     6,     0,     0,    24,     0,     0,     0,    25,
       0,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    33,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    14,     0,    34,
       0,     0,     0,     0,     0,    35,    36,    37,    38,     0,
       0,     0,    39,     0,    17,    40,     0,     0,    41,     0,
      18,    19,     0,     0,     0,     0,    20,    42,     0,    43,
      21,     0,     0,    22,     0,     0,     0,    44,    45,     0,
      23,     0,     4,     5,     6,     0,     0,    24,     0,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,    46,     0,     0,     0,
     703,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,    11,    33,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,    14,
       0,    34,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,    17,    40,     0,     0,
      41,     0,    18,    19,     0,     0,     0,     0,    20,    42,
       0,    43,    21,     0,     0,    22,     0,     0,     0,    44,
      45,     0,    23,     0,     4,     0,     6,     0,     0,    24,
       0,     0,     0,    25,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,    46,     0,
       0,     0,   691,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,    11,
      33,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,    17,    40,
       0,     0,    41,     0,   246,    19,     0,     0,     0,     0,
      20,    42,     0,    43,    21,     0,     0,    22,     0,     0,
       0,    44,    45,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
      46,     0,     0,     0,   895,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    -3,     0,     0,
       4,     5,     6,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     7,     0,     0,    39,     0,
       0,    40,     0,     0,   248,     0,     0,     0,     0,     0,
       0,     0,     8,   249,     0,    43,     0,     0,     9,     0,
      10,     0,     0,    44,    45,    11,    12,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,    14,     0,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    46,     0,    17,     0,   809,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,     0,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,     0,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   359,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     8,     0,    35,    36,    37,
      38,     9,     0,    10,    39,     0,     0,    40,    11,    12,
      41,     0,     0,    13,     0,     0,     0,     0,     0,    42,
      14,    43,   360,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    16,     0,     0,    17,     0,     0,
       0,     0,     0,    18,    19,     0,     0,     0,     0,    20,
       0,     0,     0,    21,     0,     0,    22,     0,    46,     0,
       0,     0,     0,    23,     0,     0,     0,     0,     0,     0,
      24,   361,     0,     0,    25,     0,    26,    27,    28,    29,
      30,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     4,     0,     6,     0,
       0,     0,     0,     0,     0,   277,   278,   279,   280,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
      35,    36,    37,    38,     9,     0,    10,    39,     0,     0,
      40,    11,     0,    41,     0,     0,    13,     0,     0,     0,
       0,     0,    42,     0,    43,     0,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
      17,     0,     0,     0,     0,     0,   246,    19,     0,     0,
       0,     0,    20,     0,     0,     0,    21,     0,     4,    22,
       6,    46,     0,     0,     0,     0,    23,   277,   278,   279,
     280,     0,     0,     0,     0,     0,     0,    25,     0,    26,
      27,    28,    29,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     9,     0,    10,     0,
       0,     0,     0,    11,     0,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    17,     0,    36,    37,    38,     0,   246,    19,
      39,     0,     0,    40,    20,     0,   248,     0,    21,     0,
       4,    22,     6,     0,     0,   249,     0,    43,    23,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,    25,
       0,    26,    27,    28,    29,   814,     0,     0,     0,     0,
       0,    31,     0,   778,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,    46,    11,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    17,     0,    36,    37,    38,     0,
     246,    19,    39,     0,     0,    40,    20,     0,   248,     0,
      21,     0,     4,    22,     6,     0,     0,   249,     0,    43,
      23,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,   832,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,    46,    11,     0,     0,
       0,     0,    13,   604,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,    17,     0,    36,    37,
      38,     0,   246,    19,    39,     0,     0,    40,    20,     0,
     248,     0,    21,     0,     0,    22,     0,     0,     0,   249,
       0,    43,    23,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,    25,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,   604,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,    46,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,   248,     0,     0,     0,     0,     0,     0,     0,
       0,   249,     0,    43,     0,     0,     0,     0,     0,     0,
       0,    44,    45,   604,   605,   606,   607,   608,   609,   610,
     611,   612,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      46,   604,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,   613,     0,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,     0,     0,     0,
       0,     0,     0,     0,   624,   625,     0,     0,     0,     0,
       0,   673,   604,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   604,   605,   606,   607,   608,   609,   610,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   604,   605,
     606,   607,   608,   609,   610,     0,     0,     0,   613,     0,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     604,   605,   606,   607,   608,   609,   610,   624,   625,     0,
       0,     0,     0,   613,   736,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,     0,     0,     0,     0,     0,
       0,     0,   624,   625,   710,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,     0,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,     0,     0,     0,
       0,     0,     0,     0,   624,   625,   842,     0,     0,     0,
       0,     0,     0,   613,   841,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,     0,     0,     0,     0,     0,
       0,     0,   624,   625,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   613,     0,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,     0,     0,     0,     0,
       0,     0,     0,   624,   625,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,     0,     0,     0,     0,     0,
       0,     0,   624,   625,   616,   617,   618,   619,   620,   621,
     622,   623,     4,     0,     6,     0,     0,     0,     0,   624,
     625,     0,     0,     0,     0,     0,     0,   617,   618,   619,
     620,   621,   622,   623,     0,     0,     0,     0,     0,     0,
       0,   624,   625,     0,     8,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,    11,    12,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -359,     0,     0,    17,     0,     0,     0,
       0,     0,   246,    19,     0,     0,     0,     0,    20,     0,
       0,     0,    21,     0,     4,    22,     6,   463,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,   247,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,    17,    35,
      36,    37,    38,     0,   246,    19,    39,     0,     0,    40,
      20,     0,   248,     0,    21,     0,     4,    22,     6,     0,
       0,   249,     0,    43,    23,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     4,     0,    97,    31,     0,     0,
       0,     0,     0,     0,     9,     0,    10,     0,     0,     0,
       0,    11,     0,     0,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,    34,     0,     0,     0,    11,
      17,     0,    36,    37,    38,     0,   246,    19,    39,     0,
       0,    40,    20,     0,   248,     0,    21,     0,     4,    22,
       6,     0,     0,   249,     0,    43,    23,     0,    17,     0,
       0,     0,     0,    44,    45,    19,     0,    25,     0,    26,
      27,    28,    29,     0,    21,     0,     0,    22,     0,    31,
       0,     0,     0,     0,    23,     0,     9,     0,    10,     0,
       0,     0,     0,    11,     0,     0,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,    17,     0,    36,    37,    38,     0,   246,    19,
      39,     0,     0,    40,     0,     0,   248,     0,    21,     0,
       0,    22,   599,     0,     0,   249,     0,    43,    23,     0,
       0,     0,     0,    37,    38,    44,    45,     0,    39,     0,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,    43,     0,     0,     9,     0,
      10,     0,     0,     0,    45,    11,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     0,    36,    37,    38,     0,
     246,    19,    39,     0,   599,     0,    20,     0,   248,     0,
      21,     0,     0,    22,     0,     0,     0,   249,     0,    43,
      23,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       9,     0,    10,    31,     0,     0,     0,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     0,
       0,    34,   246,    19,     0,     0,     0,     0,    36,    37,
      38,     0,    21,     0,    39,    22,     0,    40,     0,     0,
     248,     0,    23,     0,     0,     0,     0,     0,     0,   249,
       0,    43,     0,     0,     0,    26,    27,    28,    29,    44,
      45,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   121,   122,     0,
       0,   249,   123,    43,   124,   125,   126,   127,   128,     0,
     129,    44,    45,   130,     0,   131,     0,     0,   132,   133,
     134,     0,   135,   136,   137,   138,   139,   140,     0,   141,
       0,   142,   143,   144,     0,   145,   146,   147,   148,   149,
     150,   151,     0,   152,     0,     0,   153,   154,   155,   156,
     157,     0,     0,   158,   159,   160,   161,     0,     0,   162,
     163,     0,   164,   165,     0,   166,   167,   168,   169,   170,
     171,     0,   172,   173,   174,   175,   176,   177,     0,     0,
     178,     0,     0,   179,     0,     0,     0,     0,     0,   180,
     181,     0,   182,   183,     0,   184,   185,   186,     0,     0,
       0,     0,   187,   188,   189,     0,   190,   191,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,     0,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,     0,   213,   214,     0,   215,   216,     0,     0,
       0,     0,     0,   217,     0,     0,   218,     0,   219,   220,
     221,     0,     0,   222,   223,   224,   225,     0,     0,   226,
       0,   227,     0,   228,   229,   230,   231,   232,   233,   234,
       0,     0,   235
};

static const yytype_int16 yycheck[] =
{
       2,     2,     8,   244,    55,   262,    12,   262,   327,     2,
      16,   287,    18,   262,     2,    84,   262,     2,     2,     2,
       2,    84,   336,     2,    30,     2,    81,    82,    83,    35,
       2,     2,     2,    88,     2,    41,    42,    82,    83,     2,
       2,   329,     6,    88,   332,     2,   334,   378,     2,   337,
       2,   405,   320,   282,   283,     6,   344,   726,    64,   357,
     455,     3,   718,   120,   305,    58,   653,    41,    42,   130,
      58,    21,     0,    58,    58,    58,    58,    85,    84,    58,
     120,    58,    12,    13,    14,    15,     3,    74,     5,   408,
      33,   210,   430,   431,    53,    12,    13,    14,    15,   120,
     120,   688,   184,    75,   184,   113,     3,    47,     5,   652,
     230,    31,   210,   232,   735,    12,    13,    14,    15,   740,
      63,    32,    64,    53,    64,   184,   157,   159,   216,   160,
      89,   163,   153,   120,   210,   390,    53,    80,     3,   237,
       5,   390,   233,   234,   390,    88,   210,    12,    13,    14,
      15,   738,   234,   233,   234,   114,    53,   233,   233,   234,
      66,   193,     3,   418,     5,    76,   216,   234,   232,   418,
     231,    12,    13,    14,    15,   234,   405,   230,   235,     3,
     236,   234,    12,    13,    14,    15,   236,   256,   429,   430,
     431,   231,   116,   256,   737,     3,   783,   592,     6,     7,
       8,     9,    10,    11,   873,   164,   537,   602,   546,     9,
     831,    38,   236,   282,   283,   235,    43,   137,   210,   282,
     283,   180,   520,     3,   236,   131,     6,     7,     8,     9,
      10,    11,    21,   889,   242,   778,   291,   243,   240,   241,
     246,   247,   248,   249,   233,   237,   291,   240,   241,   216,
     256,   838,   240,   241,   317,   240,   241,   240,   241,   179,
      31,   210,     9,   174,     3,    74,    37,     6,     7,     8,
       9,    10,    11,   237,   248,   249,   282,   283,     6,     7,
     230,   231,    90,   571,   190,   542,   237,   542,   237,   832,
     220,   532,   533,   542,   231,   235,   542,   208,   233,   236,
     231,   231,   531,   220,   235,   546,   236,    19,    20,    21,
      90,   317,    24,    25,   231,   634,   379,   904,   210,   236,
     588,   314,   210,   220,   210,   601,   319,   320,   230,   570,
     233,   217,   234,   141,   336,   328,   405,   345,   626,   236,
     210,   349,   405,   351,   352,   237,   210,   217,   356,   237,
     233,    90,   210,   217,   347,   220,   233,   420,   231,   217,
     691,   141,   231,   236,   695,   216,   231,   236,   176,   220,
     233,   236,   231,   379,   651,     3,   235,     5,   655,   220,
     668,   189,   231,   659,   120,   231,   235,   234,   381,   235,
     220,   397,     3,   231,     5,   236,   176,   235,   712,   405,
     455,   231,   141,   216,   672,    21,   236,   215,   410,   189,
     218,   219,   220,   231,   420,   223,   224,   235,   233,   425,
     404,   233,   237,   777,   232,     3,   233,     5,   236,   431,
     233,   220,   221,   222,   231,   215,   233,   176,   218,   219,
     220,   230,   231,   223,   224,   700,   233,   233,   233,   233,
     189,   700,   232,   234,   700,   231,   236,   698,   236,   735,
     791,   718,   531,   718,   740,   234,   236,   743,   531,   718,
     236,   802,   718,   236,   236,   236,   215,   831,   484,   218,
     219,   220,   236,   236,   223,   224,   236,   236,   236,   216,
     483,   236,   236,   847,   236,   236,   236,   236,   236,   728,
     777,   236,   236,   780,   216,   217,   218,   219,   220,   221,
     222,   236,   236,   236,   236,   236,   236,   236,   230,   231,
     236,   236,   236,   132,   878,   531,   857,   236,   236,   236,
     532,   532,   601,   236,   789,   236,   236,   592,   236,   532,
     789,   236,   544,   544,   532,   236,   236,   532,   603,   532,
     799,   544,   871,   799,   236,   831,   544,   834,   603,   544,
     544,   544,   544,   236,   895,   544,   795,   544,   236,   236,
     847,   234,   544,   544,   544,   843,   544,   845,   233,   212,
     234,   544,   544,   234,   653,   233,   579,   544,   581,   920,
     544,   233,   544,   581,   579,   588,   205,   206,   207,   208,
     209,   878,   218,   219,   220,   221,   222,   230,     3,   234,
     237,   866,   238,    48,   230,   231,   236,   866,   906,     5,
     866,   212,   212,   237,   236,     9,   867,   323,    16,     6,
       9,   327,   889,    16,   889,   686,    16,     9,     9,   335,
     889,     9,   338,   889,     9,   651,    19,    20,    21,   655,
     346,   653,   348,     9,     9,     9,     9,     9,   231,   728,
     234,   236,   233,   233,   233,   728,   735,   730,   103,   738,
     233,   740,   913,   233,   235,   916,   234,   234,   220,   672,
     234,   116,   117,   118,   119,   237,   688,   235,   210,   744,
       6,   126,   238,   237,   210,   210,   237,   237,   237,   744,
     236,   694,   237,   237,   210,   707,   694,   230,   237,   694,
     712,   694,   408,   409,   707,   721,   210,   237,   210,   237,
     726,   210,   728,   237,   730,   237,   795,   237,   237,   237,
     237,   210,   795,   237,   237,   237,   738,   172,   237,   237,
     237,   237,   177,   230,   237,     9,    19,    20,    21,    22,
      23,    24,    25,   449,   450,   451,   452,   453,   454,   455,
     237,   237,   831,   237,   237,   237,   237,   237,   237,   237,
     237,   777,   237,   237,   780,   167,   212,   233,   237,   210,
     190,   783,   216,   210,   237,   233,   233,   793,     3,   795,
     792,     3,   798,   799,     3,     6,     9,   237,     6,   792,
     190,   210,   234,   233,   792,   212,   235,   792,   231,   792,
     235,   217,   233,   237,   210,   237,   210,   810,   237,   237,
     237,    19,    20,    21,    22,    23,    24,    25,   834,    27,
     233,   233,   237,   233,   210,     5,   838,   212,   237,   237,
     237,   847,   216,   234,   237,   218,   219,   220,   221,   222,
     843,   233,   845,   212,   212,   861,   552,   230,   231,   237,
     403,   806,   427,   233,   233,   867,   867,   873,   570,   236,
     233,   233,   878,   237,   867,   321,   233,   916,   661,   867,
     346,   707,   867,   542,   867,   721,   536,   592,   393,   793,
       3,   342,     5,     6,     7,     8,     9,    10,    11,    94,
     873,   717,   904,   414,   715,   256,    -1,   713,   604,   605,
      -1,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,    41,   625,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,   634,    -1,
      53,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,    -1,
      -1,    -1,    -1,    -1,    77,   661,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    89,    90,    -1,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   114,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,   141,    -1,
      -1,    -1,   230,   231,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,   176,   177,    -1,    -1,   180,    -1,    -1,
     183,    -1,    -1,    -1,    -1,    -1,   189,    -1,    -1,   192,
      -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   215,    -1,    -1,   218,   219,   220,    -1,    -1,
     223,   224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   236,    35,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,   837,    53,    -1,    -1,   841,    -1,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,   871,    -1,    -1,    89,    -1,
      -1,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   110,
     111,    -1,    -1,   114,    -1,   116,   117,   118,   119,   120,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,   133,    -1,    -1,     3,     4,     5,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     151,    -1,    -1,    -1,    -1,    -1,    -1,   230,   231,    -1,
      -1,    -1,    -1,   164,   237,    -1,    -1,    35,    -1,   170,
     171,   172,   173,    41,    -1,    43,   177,    -1,    -1,   180,
      48,    49,   183,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,   192,    60,   194,    62,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    93,    -1,    -1,    96,    -1,
     231,    -1,    -1,    -1,   235,   103,    -1,    -1,    -1,    -1,
      -1,    -1,   110,   111,    -1,    -1,   114,    -1,   116,   117,
     118,   119,   120,    -1,    -1,    -1,    -1,    -1,   126,    -1,
      -1,    -1,    -1,    -1,    -1,   133,    -1,    -1,     3,     4,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,
      35,    -1,   170,   171,   172,   173,    41,    -1,    43,   177,
      -1,    -1,   180,    48,    49,   183,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,   192,    60,   194,    62,    -1,    -1,
      -1,    -1,    -1,    -1,   202,   203,    -1,    -1,    -1,    74,
      -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    83,    84,
      -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,    93,    -1,
      -1,    96,    -1,   231,    -1,    -1,    -1,   235,   103,    -1,
       3,     4,     5,    -1,    -1,   110,    -1,    -1,    -1,   114,
      -1,   116,   117,   118,   119,   120,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,   133,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    48,   151,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,   164,
      -1,    -1,    -1,    -1,    -1,   170,   171,   172,   173,    -1,
      -1,    -1,   177,    -1,    77,   180,    -1,    -1,   183,    -1,
      83,    84,    -1,    -1,    -1,    -1,    89,   192,    -1,   194,
      93,    -1,    -1,    96,    -1,    -1,    -1,   202,   203,    -1,
     103,    -1,     3,     4,     5,    -1,    -1,   110,    -1,    -1,
      -1,   114,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,   231,    -1,    -1,    -1,
     235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    48,   151,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    -1,    -1,   177,    -1,    77,   180,    -1,    -1,
     183,    -1,    83,    84,    -1,    -1,    -1,    -1,    89,   192,
      -1,   194,    93,    -1,    -1,    96,    -1,    -1,    -1,   202,
     203,    -1,   103,    -1,     3,    -1,     5,    -1,    -1,   110,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,   231,    -1,
      -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
     151,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,    77,   180,
      -1,    -1,   183,    -1,    83,    84,    -1,    -1,    -1,    -1,
      89,   192,    -1,   194,    93,    -1,    -1,    96,    -1,    -1,
      -1,   202,   203,    -1,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   114,    -1,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,
     231,    -1,    -1,    -1,   235,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,
       3,     4,     5,    -1,    -1,   164,    -1,    -1,    -1,    -1,
      -1,    -1,   171,   172,   173,    18,    -1,    -1,   177,    -1,
      -1,   180,    -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,   192,    -1,   194,    -1,    -1,    41,    -1,
      43,    -1,    -1,   202,   203,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,   231,    -1,    77,    -1,   235,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   110,    -1,    -1,
      -1,   114,    -1,   116,   117,   118,   119,   120,    -1,    -1,
      -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,    -1,    -1,
     133,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,   151,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    35,    -1,   170,   171,   172,
     173,    41,    -1,    43,   177,    -1,    -1,   180,    48,    49,
     183,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   192,
      60,   194,    62,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    -1,    93,    -1,    -1,    96,    -1,   231,    -1,
      -1,    -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,
     110,   111,    -1,    -1,   114,    -1,   116,   117,   118,   119,
     120,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,
      -1,    -1,    -1,   133,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,
      -1,   151,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,   173,    41,    -1,    43,   177,    -1,    -1,
     180,    48,    -1,   183,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,   192,    -1,   194,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   202,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    83,    84,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    -1,    93,    -1,     3,    96,
       5,   231,    -1,    -1,    -1,    -1,   103,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,   114,    -1,   116,
     117,   118,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    77,    -1,   171,   172,   173,    -1,    83,    84,
     177,    -1,    -1,   180,    89,    -1,   183,    -1,    93,    -1,
       3,    96,     5,    -1,    -1,   192,    -1,   194,   103,    -1,
      -1,    -1,    -1,    -1,    -1,   202,   203,    -1,    -1,   114,
      -1,   116,   117,   118,   119,    28,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   220,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,   231,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,
      -1,    -1,    -1,    -1,    77,    -1,   171,   172,   173,    -1,
      83,    84,   177,    -1,    -1,   180,    89,    -1,   183,    -1,
      93,    -1,     3,    96,     5,    -1,    -1,   192,    -1,   194,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,    -1,
      -1,   114,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      -1,    -1,    -1,   126,    -1,   220,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,   231,    48,    -1,    -1,
      -1,    -1,    53,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   164,    -1,    -1,    -1,    -1,    77,    -1,   171,   172,
     173,    -1,    83,    84,   177,    -1,    -1,   180,    89,    -1,
     183,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,   192,
      -1,   194,   103,    -1,    -1,    -1,    -1,    -1,    -1,   202,
     203,    -1,    -1,   114,    -1,   116,   117,   118,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,   180,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,    -1,   194,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     231,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,    -1,    -1,    -1,    -1,
      -1,   237,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,   211,    -1,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
      19,    20,    21,    22,    23,    24,    25,   230,   231,    -1,
      -1,    -1,    -1,   211,   237,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,   232,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   211,    -1,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,   232,    -1,    -1,    -1,
      -1,    -1,    -1,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   211,    -1,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,   215,   216,   217,   218,   219,   220,
     221,   222,     3,    -1,     5,    -1,    -1,    -1,    -1,   230,
     231,    -1,    -1,    -1,    -1,    -1,    -1,   216,   217,   218,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,   231,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    83,    84,    -1,    -1,    -1,    -1,    89,    -1,
      -1,    -1,    93,    -1,     3,    96,     5,     6,    -1,    -1,
      -1,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   114,    -1,   116,   117,   118,   119,   120,
      -1,    -1,   123,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   164,    -1,    -1,    -1,    -1,    77,   170,
     171,   172,   173,    -1,    83,    84,   177,    -1,    -1,   180,
      89,    -1,   183,    -1,    93,    -1,     3,    96,     5,    -1,
      -1,   192,    -1,   194,   103,    -1,    -1,    -1,    -1,    -1,
      -1,   202,   203,    -1,    -1,   114,    -1,   116,   117,   118,
     119,    -1,    -1,    -1,     3,    -1,     5,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,   164,    -1,    -1,    -1,    48,
      77,    -1,   171,   172,   173,    -1,    83,    84,   177,    -1,
      -1,   180,    89,    -1,   183,    -1,    93,    -1,     3,    96,
       5,    -1,    -1,   192,    -1,   194,   103,    -1,    77,    -1,
      -1,    -1,    -1,   202,   203,    84,    -1,   114,    -1,   116,
     117,   118,   119,    -1,    93,    -1,    -1,    96,    -1,   126,
      -1,    -1,    -1,    -1,   103,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,   116,   117,   118,
     119,    -1,    -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    -1,
      -1,    -1,    77,    -1,   171,   172,   173,    -1,    83,    84,
     177,    -1,    -1,   180,    -1,    -1,   183,    -1,    93,    -1,
      -1,    96,     5,    -1,    -1,   192,    -1,   194,   103,    -1,
      -1,    -1,    -1,   172,   173,   202,   203,    -1,   177,    -1,
      -1,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,    -1,    -1,   194,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,   203,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    77,    -1,   171,   172,   173,    -1,
      83,    84,   177,    -1,     5,    -1,    89,    -1,   183,    -1,
      93,    -1,    -1,    96,    -1,    -1,    -1,   192,    -1,   194,
     103,    -1,    -1,    -1,    -1,    -1,    -1,   202,   203,    -1,
      -1,   114,    -1,   116,   117,   118,   119,    -1,    -1,    -1,
      41,    -1,    43,   126,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,    -1,    -1,
      -1,   164,    83,    84,    -1,    -1,    -1,    -1,   171,   172,
     173,    -1,    93,    -1,   177,    96,    -1,   180,    -1,    -1,
     183,    -1,   103,    -1,    -1,    -1,    -1,    -1,    -1,   192,
      -1,   194,    -1,    -1,    -1,   116,   117,   118,   119,   202,
     203,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     171,   172,   173,    -1,    -1,    -1,   177,    -1,    -1,    -1,
      -1,    -1,   183,    -1,    -1,    -1,    -1,    29,    30,    -1,
      -1,   192,    34,   194,    36,    37,    38,    39,    40,    -1,
      42,   202,   203,    45,    -1,    47,    -1,    -1,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    -1,    61,
      -1,    63,    64,    65,    -1,    67,    68,    69,    70,    71,
      72,    73,    -1,    75,    -1,    -1,    78,    79,    80,    81,
      82,    -1,    -1,    85,    86,    87,    88,    -1,    -1,    91,
      92,    -1,    94,    95,    -1,    97,    98,    99,   100,   101,
     102,    -1,   104,   105,   106,   107,   108,   109,    -1,    -1,
     112,    -1,    -1,   115,    -1,    -1,    -1,    -1,    -1,   121,
     122,    -1,   124,   125,    -1,   127,   128,   129,    -1,    -1,
      -1,    -1,   134,   135,   136,    -1,   138,   139,   140,    -1,
     142,   143,   144,   145,   146,   147,   148,   149,   150,    -1,
     152,    -1,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,    -1,   165,   166,    -1,   168,   169,    -1,    -1,
      -1,    -1,    -1,   175,    -1,    -1,   178,    -1,   180,   181,
     182,    -1,    -1,   185,   186,   187,   188,    -1,    -1,   191,
      -1,   193,    -1,   195,   196,   197,   198,   199,   200,   201,
      -1,    -1,   204
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   240,   246,     0,     3,     4,     5,    18,    35,    41,
      43,    48,    49,    53,    60,    62,    74,    77,    83,    84,
      89,    93,    96,   103,   110,   114,   116,   117,   118,   119,
     120,   126,   133,   151,   164,   170,   171,   172,   173,   177,
     180,   183,   192,   194,   202,   203,   231,   241,   243,   252,
     253,   255,   256,   257,   258,   261,   262,   268,   269,   288,
     302,   305,   307,   309,   310,   311,   312,   315,   316,   317,
     318,   319,   320,   321,   324,   325,   328,   332,   335,   340,
     345,   346,   347,   348,   350,   353,   371,   372,   373,   374,
     375,   230,   231,   377,   380,   381,     3,     5,   305,   305,
     236,   234,   305,   304,   305,   116,   308,     9,   305,   308,
       3,   236,   305,   236,   308,   309,   304,   305,   304,   305,
     309,    29,    30,    34,    36,    37,    38,    39,    40,    42,
      45,    47,    50,    51,    52,    54,    55,    56,    57,    58,
      59,    61,    63,    64,    65,    67,    68,    69,    70,    71,
      72,    73,    75,    78,    79,    80,    81,    82,    85,    86,
      87,    88,    91,    92,    94,    95,    97,    98,    99,   100,
     101,   102,   104,   105,   106,   107,   108,   109,   112,   115,
     121,   122,   124,   125,   127,   128,   129,   134,   135,   136,
     138,   139,   140,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   152,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   165,   166,   168,   169,   175,   178,   180,
     181,   182,   185,   186,   187,   188,   191,   193,   195,   196,
     197,   198,   199,   200,   201,   204,   270,   280,   370,   233,
     248,   248,    66,   131,   190,   344,    83,   123,   183,   192,
     260,   288,   315,   317,   319,   332,   350,   371,   375,   233,
       3,   305,   216,   233,   233,   233,   230,   234,   233,   324,
     233,   251,   233,   352,   353,   352,   352,    12,    13,    14,
      15,   220,   236,   281,   305,   306,   354,   355,   368,   288,
     371,   373,   375,   352,   233,    33,    63,    80,    88,   382,
     383,   377,   120,     9,   242,   234,   233,   216,     3,    64,
     373,   234,   184,   234,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   210,   232,    17,
      62,   111,   245,   252,   259,   262,   315,   316,   317,   318,
     319,   320,   321,   324,   332,   335,   340,   345,   235,   373,
     305,   268,   269,   234,   305,   305,   305,   305,   234,   234,
     212,   329,   234,   341,   368,   230,   307,   310,   311,   312,
     313,   314,     3,   247,   234,   349,   354,   354,   238,   231,
     236,   267,   352,   236,   210,   232,     5,   237,   120,   235,
     268,   284,   285,   286,   287,   333,   212,   212,   237,   295,
     236,   298,   274,   276,   350,     9,    16,   306,     3,     6,
       7,     8,     9,    10,    11,    90,   141,   176,   189,   215,
     218,   219,   220,   223,   224,   236,   291,   292,   293,   278,
     350,   274,   350,     6,   273,    16,   291,   294,     9,   279,
       9,     9,   271,   294,   350,   293,     9,     9,   293,     9,
     293,   291,   266,   269,   350,   293,   289,   290,   291,    31,
     137,   179,   272,     9,     9,   370,     9,   293,   373,   289,
     275,   350,   291,   373,   132,   205,   206,   207,   208,   209,
     369,   373,   373,    16,     6,     7,   376,     9,   373,   280,
     231,   234,   236,   233,   233,   233,   234,   233,   233,   251,
     306,   350,   250,   322,   311,   312,   234,   235,   329,   305,
     220,   220,   210,   217,   246,   153,   326,   332,   348,   354,
     237,   294,   220,   232,   291,   263,   264,   265,   266,    32,
      76,   174,   208,   384,   385,   383,   234,   311,   306,   235,
     210,   238,   305,   330,   331,     6,   254,   254,   235,   268,
     296,   268,   300,   235,   269,   297,   300,   237,   210,   237,
     237,   237,   236,   291,   291,   291,   291,   291,   291,     5,
     291,   351,   353,   372,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   211,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   230,   231,   210,   237,   237,   210,
     237,   210,   230,   237,   210,   237,   210,   237,   237,   210,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   350,   220,   236,   267,   281,   306,   360,   362,   363,
     237,   210,   237,   237,   237,   237,   237,   237,   210,   237,
     237,   237,   210,   237,   237,   237,   237,   237,   237,   230,
     237,   237,   237,   280,   244,     9,   249,   216,   236,   354,
     364,   235,   252,   268,   269,   235,   268,   323,   322,   251,
     167,   339,   313,   235,   212,   130,   300,   327,   233,   232,
     232,   237,   210,   210,   237,   190,   378,   379,   216,   287,
     293,   210,   334,     6,   237,   237,   350,   375,   350,   371,
     237,   233,   233,   273,   274,   351,   237,   220,   236,   267,
     281,   356,   358,   359,   372,   352,   291,   291,     3,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,     3,   291,   293,   157,
     160,   277,     6,   294,     3,     9,   362,   349,   220,   263,
     281,   361,   362,   236,   267,   290,   293,   274,     6,   120,
     235,   237,   248,   336,   263,   210,   251,   251,    74,   120,
     342,   343,   235,   311,   312,   338,   234,   212,   233,   235,
     269,   301,   302,   235,    28,   266,   385,   381,   235,   378,
     314,   330,   217,   360,   366,   367,   233,   354,   303,   306,
     358,   349,   220,   263,   281,   357,   358,   237,   236,   267,
     352,   212,   232,   210,   237,   210,   362,   349,   237,   362,
     237,   263,   237,   311,   251,   235,   331,   237,   354,   305,
     305,   310,   312,   233,   233,   251,   210,   250,   233,     5,
     217,   212,   365,   210,   233,   234,   237,   358,   349,   237,
     362,   237,   291,   263,   291,   274,   274,   362,   237,   216,
     217,   251,   305,   311,   312,   235,   233,   233,   294,   366,
     282,   362,   237,   314,   236,   251,    47,    64,   235,   283,
     217,   263,   293,   212,   233,   237,   212,   233,   299,   300,
     337,   299,   233,   251
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   239,   240,   241,   241,   242,   242,   243,   244,   244,
     245,   246,   247,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   248,   248,
     248,   249,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   250,   250,   251,   251,
     252,   252,   252,   252,   252,   252,   252,   253,   253,   254,
     254,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     256,   257,   258,   259,   260,   261,   262,   263,   263,   264,
     264,   265,   265,   266,   266,   267,   267,   267,   268,   268,
     269,   270,   270,   270,   271,   271,   272,   272,   272,   273,
     273,   274,   275,   276,   276,   277,   277,   278,   279,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   281,   281,   281,   281,   282,   282,
     283,   283,   284,   284,   284,   285,   285,   286,   287,   287,
     288,   289,   289,   290,   290,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   292,   292,   293,   294,
     295,   295,   296,   296,   297,   297,   298,   298,   299,   299,
     300,   300,   301,   302,   302,   303,   303,   304,   304,   305,
     305,   306,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   307,   307,   308,   308,   309,   309,   309,   309,   309,
     309,   309,   309,   309,   310,   310,   311,   311,   312,   313,
     313,   313,   313,   313,   314,   314,   315,   316,   317,   318,
     319,   320,   321,   321,   322,   322,   323,   323,   324,   325,
     326,   326,   327,   327,   328,   328,   329,   329,   329,   330,
     331,   331,   332,   333,   334,   332,   335,   336,   337,   335,
     338,   338,   338,   338,   339,   339,   341,   340,   340,   342,
     342,   342,   343,   344,   345,   346,   346,   346,   347,   348,
     349,   349,   350,   350,   351,   351,   352,   352,   353,   353,
     353,   354,   354,   354,   355,   355,   355,   355,   356,   356,
     356,   357,   357,   358,   358,   359,   359,   359,   359,   359,
     360,   360,   360,   361,   361,   362,   362,   363,   363,   363,
     363,   363,   363,   364,   364,   365,   365,   366,   367,   367,
     368,   368,   369,   369,   369,   369,   369,   369,   370,   370,
     370,   371,   372,   372,   372,   372,   372,   372,   372,   372,
     372,   372,   373,   373,   373,   374,   375,   375,   376,   376,
     376,   377,   377,   378,   378,   379,   380,   381,   381,   382,
     382,   383,   383,   383,   383,   384,   384,   385,   385,   385,
     385
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
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
       3,     3,     3,     3,     1,     1,     1,     5,     5,     0,
       4,     1,     4,     1,     1,     1,     1,     1,     4,     4,
       1,     4,     1,     1,     1,     1,     4,     4,     1,     6,
       1,     1,     1,     1,     1,     4,     1,     4,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     1,
       4,     1,     1,     4,     1,     4,     1,     1,     4,     4,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     4,     1,
       4,     4,     1,     1,     1,     1,     1,     1,     6,     1,
       4,     1,     1,     1,     4,     1,     4,     1,     1,     4,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     1,     1,     1,     0,     2,
       4,     3,     0,     2,     1,     1,     3,     2,     3,     1,
       5,     1,     3,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     2,     2,     2,
       3,     3,     5,     5,     4,     3,     1,     3,     1,     1,
       0,     2,     4,     3,     2,     2,     0,     2,     2,     1,
       3,     2,     1,     3,     2,     0,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     1,     1,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     2,     2,
       1,     1,     1,     1,     2,     3,     1,     2,     4,     1,
       1,     2,     1,     2,     1,     3,     2,     6,     2,     7,
       2,     5,     2,     3,     0,     2,     3,     3,     2,     1,
       2,     3,     2,     3,     6,     6,     0,     2,     2,     1,
       1,     3,     2,     0,     0,     7,     8,     0,     0,    13,
       1,     1,     3,     3,     0,     2,     0,     9,     2,     2,
       3,     2,     2,     2,     6,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     2,     3,     0,     1,     2,     2,
       2,     3,     2,     1,     1,     3,     2,     4,     3,     2,
       1,     3,     2,     0,     1,     3,     2,     1,     3,     4,
       3,     2,     1,     3,     2,     0,     1,     1,     3,     2,
       1,     3,     4,     1,     3,     0,     2,     2,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     2,     1,     2,     1,     2,
       4,     1,     1,     2,     1,     5,     5,    10,     1,     3,
       1,     0,     2,     0,     2,     4,     6,     0,     3,     1,
       3,     4,     1,     1,     1,     1,     3,     1,     1,     1,
       1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = PARSER_EMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == PARSER_EMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if PARSER_DEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !PARSER_DEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !PARSER_DEBUG */


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
  YYLTYPE *yylloc;
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined PARSER_LTYPE_IS_TRIVIAL && PARSER_LTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
    YYNOMEM;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc);
    }

  if (yychar <= PARSER_EOF)
    {
      yychar = PARSER_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == PARSER_error)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = PARSER_UNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = PARSER_EMPTY;
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: gbl_statements m_acf  */
#line 370 "tools/widl/parser.y"
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
                                                  (void)parser_nerrs;  /* avoid unused variable warning */
						}
#line 3568 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3574 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 394 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3582 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 399 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3588 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3594 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 405 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3600 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3606 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3612 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 414 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3618 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 415 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3624 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 416 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3630 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3636 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3642 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3648 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 420 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3656 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3664 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 426 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3670 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3677 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3683 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3690 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3696 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3702 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 434 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3708 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 435 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3714 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3720 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3726 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3732 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 442 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3738 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 443 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3744 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3750 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3756 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 446 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3762 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 447 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3770 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3776 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 451 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3783 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3789 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 454 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3796 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 456 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3802 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 457 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3808 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 458 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3814 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 459 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3820 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 460 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3826 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 464 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3832 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 465 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3838 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3844 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 475 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3850 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3856 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 477 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3862 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3868 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 479 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3874 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 480 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3880 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 484 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3892 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 492 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3901 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 499 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].integer).value); }
#line 3907 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 500 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].integer).value); }
#line 3913 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM typename  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 3919 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT typename  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 3925 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION typename  */
#line 509 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 3931 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 510 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3937 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 511 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3943 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3949 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3955 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 518 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); push_import( (yyvsp[-1].str), &yylloc ); }
#line 3961 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 520 "tools/widl/parser.y"
                                                { yylloc = pop_import(); }
#line 3967 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3973 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 527 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3979 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 529 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3987 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 534 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3993 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 538 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3999 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 542 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 4005 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 543 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 4011 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(xstrdup("...")) ); }
#line 4017 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 551 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4027 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 556 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4037 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 4046 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4052 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4058 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 4064 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 4070 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 4076 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 4082 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 4088 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 4094 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 4100 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 4106 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 4112 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 4118 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].integer).value); }
#line 4124 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].integer).value, (yyvsp[-2].integer).value); }
#line 4130 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 601 "tools/widl/parser.y"
                                                {
                                                  struct integer integer = {.value = (yyvsp[0].num)};
                                                  if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
                                                    error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
                                                  (yyval.expr) = make_exprl(EXPR_NUM, &integer);
                                                  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
                                                }
#line 4142 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 611 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4151 "tools/widl/parser.tab.c"
    break;

  case 103: /* activatable_attr: decl_spec ',' contract_req  */
#line 618 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4160 "tools/widl/parser.tab.c"
    break;

  case 104: /* activatable_attr: contract_req  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 4166 "tools/widl/parser.tab.c"
    break;

  case 105: /* access_attr: tPUBLIC  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4172 "tools/widl/parser.tab.c"
    break;

  case 106: /* access_attr: tPROTECTED  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4178 "tools/widl/parser.tab.c"
    break;

  case 107: /* composable_attr: decl_spec ',' access_attr ',' contract_req  */
#line 632 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].declspec)->type->type_type != TYPE_INTERFACE)
                                                      error_loc( "type %s is not an interface\n", (yyvsp[-4].declspec)->type->name );
                                                  (yyval.expr) = make_exprt( EXPR_MEMBER, declare_var( append_attr( NULL, (yyvsp[-2].attr) ), (yyvsp[-4].declspec), make_declarator( NULL ), 0 ), (yyvsp[0].expr) );
                                                }
#line 4187 "tools/widl/parser.tab.c"
    break;

  case 108: /* deprecated_attr: aSTRING ',' aIDENTIFIER ',' contract_req  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3( EXPR_MEMBER, make_exprs( EXPR_STRLIT, (yyvsp[-4].str) ), make_exprs( EXPR_IDENTIFIER, (yyvsp[-2].str) ), (yyvsp[0].expr) ); }
#line 4193 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: %empty  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 4199 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tACTIVATABLE '(' activatable_attr ')'  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ACTIVATABLE, (yyvsp[-1].expr) ); }
#line 4205 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tAGGREGATABLE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AGGREGATABLE, 0 ); }
#line 4211 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ANNOTATION, (yyvsp[-1].str) ); }
#line 4217 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tAPPOBJECT  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_APPOBJECT, 0 ); }
#line 4223 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tASYNC  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ASYNC, 0 ); }
#line 4229 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tAUTOHANDLE  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AUTO_HANDLE, 0 ); }
#line 4235 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tBINDABLE  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BINDABLE, 0 ); }
#line 4241 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tBROADCAST  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BROADCAST, 0 ); }
#line 4247 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCALLAS '(' ident ')'  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CALLAS, (yyvsp[-1].var) ); }
#line 4253 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CASE, (yyvsp[-1].expr_list) ); }
#line 4259 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCODE  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CODE, 0 ); }
#line 4265 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCOMPOSABLE '(' composable_attr ')'  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_COMPOSABLE, (yyvsp[-1].expr) ); }
#line 4271 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCOMMSTATUS  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_COMMSTATUS, 0 ); }
#line 4277 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tCONTEXTHANDLE  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); }
#line 4283 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4289 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4295 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CONTRACT, (yyvsp[-1].expr) ); }
#line 4301 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTRACTVERSION, (yyvsp[-1].num) ); }
#line 4307 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tCONTROL  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTROL, 0 ); }
#line 4313 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tCUSTOM '(' aUUID ',' expr_const ')'  */
#line 664 "tools/widl/parser.y"
                                                { attr_custdata_t *data = xmalloc( sizeof(*data) );
                                                  data->id = *(yyvsp[-3].uuid); data->pval = (yyvsp[-1].expr);
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_CUSTOM, data );
                                                }
#line 4322 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDECODE  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 4328 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDEFAULT  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULT, 0 ); }
#line 4334 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDEFAULT_OVERLOAD  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULT_OVERLOAD, 0 ); }
#line 4340 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tDEFAULTBIND  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTBIND, 0 ); }
#line 4346 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tDEFAULTCOLLELEM  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTCOLLELEM, 0 ); }
#line 4352 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DEFAULTVALUE, (yyvsp[-1].expr) ); }
#line 4358 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tDEFAULTVTABLE  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTVTABLE, 0 ); }
#line 4364 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tDEPRECATED '(' deprecated_attr ')'  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DEPRECATED, (yyvsp[-1].expr) ); }
#line 4370 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISABLECONSISTENCYCHECK, 0 ); }
#line 4376 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tDISPLAYBIND  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISPLAYBIND, 0 ); }
#line 4382 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DLLNAME, (yyvsp[-1].str) ); }
#line 4388 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tDUAL  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DUAL, 0 ); }
#line 4394 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tENABLEALLOCATE  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENABLEALLOCATE, 0 ); }
#line 4400 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tENCODE  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 4406 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tENDPOINT '(' str_list ')'  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENDPOINT, (yyvsp[-1].str_list) ); }
#line 4412 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tENTRY '(' expr_const ')'  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENTRY, (yyvsp[-1].expr) ); }
#line 4418 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tEVENTADD  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTADD, 0 ); }
#line 4424 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tEVENTREMOVE  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTREMOVE, 0 ); }
#line 4430 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 686 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
                                                      error_loc( "type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type );
                                                }
#line 4439 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tEXPLICITHANDLE  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 4445 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tFAULTSTATUS  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FAULTSTATUS, 0 ); }
#line 4451 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tFLAGS  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FLAGS, 0 ); }
#line 4457 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tFORCEALLOCATE  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FORCEALLOCATE, 0 ); }
#line 4463 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tHANDLE  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HANDLE, 0 ); }
#line 4469 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPCONTEXT, (yyvsp[-1].expr) ); }
#line 4475 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPFILE, (yyvsp[-1].str) ); }
#line 4481 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRING, (yyvsp[-1].str) ); }
#line 4487 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr) ); }
#line 4493 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGDLL, (yyvsp[-1].str) ); }
#line 4499 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tHIDDEN  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HIDDEN, 0 ); }
#line 4505 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tID '(' expr_int_const ')'  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ID, (yyvsp[-1].expr) ); }
#line 4511 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tIDEMPOTENT  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IDEMPOTENT, 0 ); }
#line 4517 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tIGNORE  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IGNORE, 0 ); }
#line 4523 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tIIDIS '(' expr ')'  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IIDIS, (yyvsp[-1].expr) ); }
#line 4529 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tIMMEDIATEBIND  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IMMEDIATEBIND, 0 ); }
#line 4535 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var) ); }
#line 4541 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tIN  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IN, 0 ); }
#line 4547 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tINPUTSYNC  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_INPUTSYNC, 0 ); }
#line 4553 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LENGTHIS, (yyvsp[-1].expr_list) ); }
#line 4559 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tLCID '(' expr_int_const ')'  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LIBLCID, (yyvsp[-1].expr) ); }
#line 4565 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tLCID  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARAMLCID, 0 ); }
#line 4571 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tLICENSED  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LICENSED, 0 ); }
#line 4577 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tLOCAL  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LOCAL, 0 ); }
#line 4583 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 716 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num) ); }
#line 4589 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tMAYBE  */
#line 717 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MAYBE, 0 ); }
#line 4595 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tMESSAGE  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MESSAGE, 0 ); }
#line 4601 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tNOCODE  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOCODE, 0 ); }
#line 4607 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tNONBROWSABLE  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONBROWSABLE, 0 ); }
#line 4613 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tNONCREATABLE  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONCREATABLE, 0 ); }
#line 4619 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tNONEXTENSIBLE  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONEXTENSIBLE, 0 ); }
#line 4625 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tNOTIFY  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFY, 0 ); }
#line 4631 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tNOTIFYFLAG  */
#line 724 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFYFLAG, 0 ); }
#line 4637 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tOBJECT  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OBJECT, 0 ); }
#line 4643 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tODL  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ODL, 0 ); }
#line 4649 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tOLEAUTOMATION  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OLEAUTOMATION, 0 ); }
#line 4655 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 728 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OPTIMIZE, (yyvsp[-1].str) ); }
#line 4661 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tOPTIONAL  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OPTIONAL, 0 ); }
#line 4667 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tOUT  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OUT, 0 ); }
#line 4673 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tOVERLOAD '(' aSTRING ')'  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OVERLOAD, (yyvsp[-1].str) ); }
#line 4679 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tPARTIALIGNORE  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARTIALIGNORE, 0 ); }
#line 4685 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERDEFAULT, (yyvsp[-1].num) ); }
#line 4691 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tPROGID '(' aSTRING ')'  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_PROGID, (yyvsp[-1].str) ); }
#line 4697 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tPROPGET  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPGET, 0 ); }
#line 4703 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tPROPPUT  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUT, 0 ); }
#line 4709 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tPROPPUTREF  */
#line 737 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUTREF, 0 ); }
#line 4715 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tPROTECTED  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4721 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tPROXY  */
#line 739 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROXY, 0 ); }
#line 4727 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tPUBLIC  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4733 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 742 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
                                                  list = append_expr( list, (yyvsp[-1].expr) );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_RANGE, list );
                                                }
#line 4742 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tREADONLY  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_READONLY, 0 ); }
#line 4748 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tREPRESENTAS '(' type ')'  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_REPRESENTAS, (yyvsp[-1].type) ); }
#line 4754 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tREQUESTEDIT  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_REQUESTEDIT, 0 ); }
#line 4760 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tRESTRICTED  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RESTRICTED, 0 ); }
#line 4766 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tRETVAL  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RETVAL, 0 ); }
#line 4772 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SIZEIS, (yyvsp[-1].expr_list) ); }
#line 4778 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tSOURCE  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_SOURCE, 0 ); }
#line 4784 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tSTATIC '(' static_attr ')'  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_STATIC, (yyvsp[-1].expr) ); }
#line 4790 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRICTCONTEXTHANDLE, 0 ); }
#line 4796 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tSTRING  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRING, 0 ); }
#line 4802 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tSWITCHIS '(' expr ')'  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHIS, (yyvsp[-1].expr) ); }
#line 4808 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHTYPE, (yyvsp[-1].type) ); }
#line 4814 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tTRANSMITAS '(' type ')'  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_TRANSMITAS, (yyvsp[-1].type) ); }
#line 4820 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: tTHREADING '(' threading_type ')'  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_THREADING, (yyvsp[-1].num) ); }
#line 4826 "tools/widl/parser.tab.c"
    break;

  case 213: /* attribute: tUIDEFAULT  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_UIDEFAULT, 0 ); }
#line 4832 "tools/widl/parser.tab.c"
    break;

  case 214: /* attribute: tUSESGETLASTERROR  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_USESGETLASTERROR, 0 ); }
#line 4838 "tools/widl/parser.tab.c"
    break;

  case 215: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_USERMARSHAL, (yyvsp[-1].type) ); }
#line 4844 "tools/widl/parser.tab.c"
    break;

  case 216: /* attribute: tUUID '(' aUUID ')'  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_UUID, (yyvsp[-1].uuid) ); }
#line 4850 "tools/widl/parser.tab.c"
    break;

  case 217: /* attribute: tASYNCUUID '(' aUUID ')'  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ASYNCUUID, (yyvsp[-1].uuid) ); }
#line 4856 "tools/widl/parser.tab.c"
    break;

  case 218: /* attribute: tV1ENUM  */
#line 765 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_V1ENUM, 0 ); }
#line 4862 "tools/widl/parser.tab.c"
    break;

  case 219: /* attribute: tVARARG  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VARARG, 0 ); }
#line 4868 "tools/widl/parser.tab.c"
    break;

  case 220: /* attribute: tVERSION '(' version ')'  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VERSION, (yyvsp[-1].num) ); }
#line 4874 "tools/widl/parser.tab.c"
    break;

  case 221: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 768 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_VIPROGID, (yyvsp[-1].str) ); }
#line 4880 "tools/widl/parser.tab.c"
    break;

  case 222: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 769 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_WIREMARSHAL, (yyvsp[-1].type) ); }
#line 4886 "tools/widl/parser.tab.c"
    break;

  case 223: /* attribute: pointer_type  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERTYPE, (yyvsp[0].num) ); }
#line 4892 "tools/widl/parser.tab.c"
    break;

  case 228: /* cases: %empty  */
#line 780 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4898 "tools/widl/parser.tab.c"
    break;

  case 229: /* cases: cases case  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4904 "tools/widl/parser.tab.c"
    break;

  case 230: /* case: tCASE expr_int_const ':' union_field  */
#line 784 "tools/widl/parser.y"
                                                { attr_t *a = attr_ptr( (yyloc), ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ) );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4913 "tools/widl/parser.tab.c"
    break;

  case 231: /* case: tDEFAULT ':' union_field  */
#line 788 "tools/widl/parser.y"
                                                { attr_t *a = attr_int( (yyloc), ATTR_DEFAULT, 0 );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4922 "tools/widl/parser.tab.c"
    break;

  case 232: /* enums: %empty  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4928 "tools/widl/parser.tab.c"
    break;

  case 233: /* enums: enum_list ','  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4934 "tools/widl/parser.tab.c"
    break;

  case 235: /* enum_list: enum  */
#line 800 "tools/widl/parser.y"
                                                {
                                                  struct integer integer = {.value = 0};
                                                  if (!(yyvsp[0].var)->eval)
                                                    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, &integer);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
                                                }
#line 4945 "tools/widl/parser.tab.c"
    break;

  case 236: /* enum_list: enum_list ',' enum  */
#line 806 "tools/widl/parser.y"
                                                {
                                                  if (!(yyvsp[0].var)->eval)
                                                  {
                                                    var_t *last = LIST_ENTRY( list_tail((yyval.var_list)), var_t, entry );
                                                    struct integer integer;

                                                    if (last->eval->type == EXPR_NUM)
                                                      integer.is_hex = last->eval->u.integer.is_hex;
                                                    integer.value = last->eval->cval + 1;
                                                    if (integer.value < 0)
                                                      integer.is_hex = TRUE;
                                                    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, &integer);
                                                  }
                                                  (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) );
                                                }
#line 4965 "tools/widl/parser.tab.c"
    break;

  case 237: /* enum_member: m_attributes ident  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4973 "tools/widl/parser.tab.c"
    break;

  case 238: /* enum: enum_member '=' expr_int_const  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4982 "tools/widl/parser.tab.c"
    break;

  case 239: /* enum: enum_member  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4990 "tools/widl/parser.tab.c"
    break;

  case 240: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 837 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list), &(yylsp[-3])); }
#line 4996 "tools/widl/parser.tab.c"
    break;

  case 241: /* m_exprs: m_expr  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5002 "tools/widl/parser.tab.c"
    break;

  case 242: /* m_exprs: m_exprs ',' m_expr  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5008 "tools/widl/parser.tab.c"
    break;

  case 243: /* m_expr: %empty  */
#line 845 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 5014 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: aNUM  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, &(yyvsp[0].integer)); }
#line 5020 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: aHEXNUM  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, &(yyvsp[0].integer)); }
#line 5026 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: aDOUBLE  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 5032 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: tFALSE  */
#line 852 "tools/widl/parser.y"
                                                { struct integer integer = {.value = 0};
                                                  (yyval.expr) = make_exprl(EXPR_TRUEFALSE, &integer); }
#line 5039 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: tNULL  */
#line 854 "tools/widl/parser.y"
                                                { struct integer integer = {.value = 0};
                                                  (yyval.expr) = make_exprl(EXPR_NUM, &integer); }
#line 5046 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: tTRUE  */
#line 856 "tools/widl/parser.y"
                                                { struct integer integer = {.value = 1};
                                                  (yyval.expr) = make_exprl(EXPR_TRUEFALSE, &integer); }
#line 5053 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: aSTRING  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 5059 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: aWSTRING  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 5065 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: aSQSTRING  */
#line 860 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 5071 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: aIDENTIFIER  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 5077 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr '?' expr ':' expr  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5083 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr LOGICALOR expr  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5089 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr LOGICALAND expr  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5095 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '|' expr  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5101 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr '^' expr  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5107 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr '&' expr  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5113 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr EQUALITY expr  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5119 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr INEQUALITY expr  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5125 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr '>' expr  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5131 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr '<' expr  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5137 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: expr GREATEREQUAL expr  */
#line 872 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5143 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: expr LESSEQUAL expr  */
#line 873 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5149 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr SHL expr  */
#line 874 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5155 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: expr SHR expr  */
#line 875 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5161 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: expr '+' expr  */
#line 876 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5167 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: expr '-' expr  */
#line 877 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5173 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: expr '%' expr  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5179 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: expr '*' expr  */
#line 879 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5185 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: expr '/' expr  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5191 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: '!' expr  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 5197 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: '~' expr  */
#line 882 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 5203 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '+' expr  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 5209 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr: '-' expr  */
#line 884 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 5215 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr: '&' expr  */
#line 885 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 5221 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr: '*' expr  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 5227 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 887 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5233 "tools/widl/parser.tab.c"
    break;

  case 281: /* expr: expr '.' aIDENTIFIER  */
#line 888 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5239 "tools/widl/parser.tab.c"
    break;

  case 282: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 890 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5245 "tools/widl/parser.tab.c"
    break;

  case 283: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 892 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5251 "tools/widl/parser.tab.c"
    break;

  case 284: /* expr: expr '[' expr ']'  */
#line 893 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5257 "tools/widl/parser.tab.c"
    break;

  case 285: /* expr: '(' expr ')'  */
#line 894 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5263 "tools/widl/parser.tab.c"
    break;

  case 286: /* expr_list_int_const: expr_int_const  */
#line 897 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5269 "tools/widl/parser.tab.c"
    break;

  case 287: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 898 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5275 "tools/widl/parser.tab.c"
    break;

  case 288: /* expr_int_const: expr  */
#line 901 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5284 "tools/widl/parser.tab.c"
    break;

  case 289: /* expr_const: expr  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5293 "tools/widl/parser.tab.c"
    break;

  case 290: /* fields: %empty  */
#line 914 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5299 "tools/widl/parser.tab.c"
    break;

  case 291: /* fields: fields field  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5305 "tools/widl/parser.tab.c"
    break;

  case 292: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 919 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5314 "tools/widl/parser.tab.c"
    break;

  case 293: /* field: m_attributes uniondef ';'  */
#line 923 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5323 "tools/widl/parser.tab.c"
    break;

  case 294: /* ne_union_field: s_field ';'  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5329 "tools/widl/parser.tab.c"
    break;

  case 295: /* ne_union_field: attributes ';'  */
#line 931 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5335 "tools/widl/parser.tab.c"
    break;

  case 296: /* ne_union_fields: %empty  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5341 "tools/widl/parser.tab.c"
    break;

  case 297: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5347 "tools/widl/parser.tab.c"
    break;

  case 298: /* union_field: s_field ';'  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5353 "tools/widl/parser.tab.c"
    break;

  case 299: /* union_field: ';'  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5359 "tools/widl/parser.tab.c"
    break;

  case 300: /* s_field: m_attributes decl_spec declarator  */
#line 944 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5368 "tools/widl/parser.tab.c"
    break;

  case 301: /* s_field: m_attributes structdef  */
#line 948 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5377 "tools/widl/parser.tab.c"
    break;

  case 302: /* funcdef: declaration  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5387 "tools/widl/parser.tab.c"
    break;

  case 303: /* declaration: attributes decl_spec init_declarator  */
#line 963 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5395 "tools/widl/parser.tab.c"
    break;

  case 304: /* declaration: decl_spec init_declarator  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5403 "tools/widl/parser.tab.c"
    break;

  case 305: /* m_ident: %empty  */
#line 972 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5409 "tools/widl/parser.tab.c"
    break;

  case 307: /* m_typename: %empty  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5415 "tools/widl/parser.tab.c"
    break;

  case 311: /* ident: typename  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5421 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tBYTE  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "byte" ); }
#line 5427 "tools/widl/parser.tab.c"
    break;

  case 313: /* base_type: tWCHAR  */
#line 989 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "wchar_t" ); }
#line 5433 "tools/widl/parser.tab.c"
    break;

  case 315: /* base_type: tSIGNED int_std  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5439 "tools/widl/parser.tab.c"
    break;

  case 316: /* base_type: tUNSIGNED int_std  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5445 "tools/widl/parser.tab.c"
    break;

  case 317: /* base_type: tUNSIGNED  */
#line 993 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5451 "tools/widl/parser.tab.c"
    break;

  case 318: /* base_type: tFLOAT  */
#line 994 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "float" ); }
#line 5457 "tools/widl/parser.tab.c"
    break;

  case 319: /* base_type: tDOUBLE  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "double" ); }
#line 5463 "tools/widl/parser.tab.c"
    break;

  case 320: /* base_type: tBOOLEAN  */
#line 996 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "boolean" ); }
#line 5469 "tools/widl/parser.tab.c"
    break;

  case 321: /* base_type: tERRORSTATUST  */
#line 997 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "error_status_t" ); }
#line 5475 "tools/widl/parser.tab.c"
    break;

  case 322: /* base_type: tHANDLET  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "handle_t" ); }
#line 5481 "tools/widl/parser.tab.c"
    break;

  case 325: /* int_std: tINT  */
#line 1006 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5487 "tools/widl/parser.tab.c"
    break;

  case 326: /* int_std: tSHORT m_int  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5493 "tools/widl/parser.tab.c"
    break;

  case 327: /* int_std: tSMALL  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5499 "tools/widl/parser.tab.c"
    break;

  case 328: /* int_std: tLONG m_int  */
#line 1009 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5505 "tools/widl/parser.tab.c"
    break;

  case 329: /* int_std: tHYPER m_int  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5511 "tools/widl/parser.tab.c"
    break;

  case 330: /* int_std: tINT64  */
#line 1011 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5517 "tools/widl/parser.tab.c"
    break;

  case 331: /* int_std: tCHAR  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5523 "tools/widl/parser.tab.c"
    break;

  case 332: /* int_std: tINT32  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5529 "tools/widl/parser.tab.c"
    break;

  case 333: /* int_std: tINT3264  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5535 "tools/widl/parser.tab.c"
    break;

  case 334: /* namespace_pfx: aIDENTIFIER '.'  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5541 "tools/widl/parser.tab.c"
    break;

  case 335: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5547 "tools/widl/parser.tab.c"
    break;

  case 336: /* qualified_type: typename  */
#line 1023 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5553 "tools/widl/parser.tab.c"
    break;

  case 337: /* qualified_type: namespace_pfx typename  */
#line 1024 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5559 "tools/widl/parser.tab.c"
    break;

  case 338: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5565 "tools/widl/parser.tab.c"
    break;

  case 339: /* parameterized_type_arg: base_type  */
#line 1032 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5571 "tools/widl/parser.tab.c"
    break;

  case 340: /* parameterized_type_arg: qualified_type  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5577 "tools/widl/parser.tab.c"
    break;

  case 341: /* parameterized_type_arg: qualified_type '*'  */
#line 1034 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5583 "tools/widl/parser.tab.c"
    break;

  case 342: /* parameterized_type_arg: parameterized_type  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5589 "tools/widl/parser.tab.c"
    break;

  case 343: /* parameterized_type_arg: parameterized_type '*'  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5595 "tools/widl/parser.tab.c"
    break;

  case 344: /* parameterized_type_args: parameterized_type_arg  */
#line 1040 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5601 "tools/widl/parser.tab.c"
    break;

  case 345: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5607 "tools/widl/parser.tab.c"
    break;

  case 346: /* coclass: tCOCLASS typename  */
#line 1045 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5613 "tools/widl/parser.tab.c"
    break;

  case 347: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list), &(yylsp[-4])); }
#line 5619 "tools/widl/parser.tab.c"
    break;

  case 348: /* runtimeclass: tRUNTIMECLASS typename  */
#line 1052 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5625 "tools/widl/parser.tab.c"
    break;

  case 349: /* runtimeclass_def: attributes runtimeclass inherit '{' class_interfaces '}' semicolon_opt  */
#line 1056 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].type) && type_get_type((yyvsp[-4].type)) != TYPE_RUNTIMECLASS) error_loc("%s is not a runtimeclass\n", (yyvsp[-4].type)->name);
						  (yyval.type) = type_runtimeclass_define((yyvsp[-5].type), (yyvsp[-6].attr_list), (yyvsp[-2].typeref_list), &(yylsp[-5])); }
#line 5632 "tools/widl/parser.tab.c"
    break;

  case 350: /* apicontract: tAPICONTRACT typename  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5638 "tools/widl/parser.tab.c"
    break;

  case 351: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 1064 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list), &(yylsp[-3])); }
#line 5644 "tools/widl/parser.tab.c"
    break;

  case 352: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 1067 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 5650 "tools/widl/parser.tab.c"
    break;

  case 353: /* namespacedef: namespacedef '.' aIDENTIFIER  */
#line 1068 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 5656 "tools/widl/parser.tab.c"
    break;

  case 354: /* class_interfaces: %empty  */
#line 1072 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5662 "tools/widl/parser.tab.c"
    break;

  case 355: /* class_interfaces: class_interfaces class_interface  */
#line 1073 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5668 "tools/widl/parser.tab.c"
    break;

  case 356: /* class_interface: m_attributes interfaceref ';'  */
#line 1077 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5674 "tools/widl/parser.tab.c"
    break;

  case 357: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 1078 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5680 "tools/widl/parser.tab.c"
    break;

  case 358: /* dispinterface: tDISPINTERFACE typename  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5686 "tools/widl/parser.tab.c"
    break;

  case 359: /* dispattributes: attributes  */
#line 1084 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[0].attr_list), attr_int( (yyloc), ATTR_DISPINTERFACE, 0 ) ); }
#line 5692 "tools/widl/parser.tab.c"
    break;

  case 360: /* dispint_props: tPROPERTIES ':'  */
#line 1087 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5698 "tools/widl/parser.tab.c"
    break;

  case 361: /* dispint_props: dispint_props s_field ';'  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5704 "tools/widl/parser.tab.c"
    break;

  case 362: /* dispint_meths: tMETHODS ':'  */
#line 1091 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5710 "tools/widl/parser.tab.c"
    break;

  case 363: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1092 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5716 "tools/widl/parser.tab.c"
    break;

  case 364: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1097 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list), &(yylsp[-4])); }
#line 5722 "tools/widl/parser.tab.c"
    break;

  case 365: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type), &(yylsp[-4])); }
#line 5728 "tools/widl/parser.tab.c"
    break;

  case 366: /* inherit: %empty  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5734 "tools/widl/parser.tab.c"
    break;

  case 367: /* inherit: ':' qualified_type  */
#line 1104 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5740 "tools/widl/parser.tab.c"
    break;

  case 368: /* inherit: ':' parameterized_type  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5746 "tools/widl/parser.tab.c"
    break;

  case 369: /* type_parameter: typename  */
#line 1108 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5752 "tools/widl/parser.tab.c"
    break;

  case 370: /* type_parameters: type_parameter  */
#line 1112 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5758 "tools/widl/parser.tab.c"
    break;

  case 371: /* type_parameters: type_parameters ',' type_parameter  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5764 "tools/widl/parser.tab.c"
    break;

  case 372: /* interface: tINTERFACE typename  */
#line 1117 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5770 "tools/widl/parser.tab.c"
    break;

  case 373: /* $@3: %empty  */
#line 1118 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5776 "tools/widl/parser.tab.c"
    break;

  case 374: /* $@4: %empty  */
#line 1118 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5782 "tools/widl/parser.tab.c"
    break;

  case 375: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5788 "tools/widl/parser.tab.c"
    break;

  case 376: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))), &(yylsp[-4]));
						}
#line 5796 "tools/widl/parser.tab.c"
    break;

  case 377: /* $@5: %empty  */
#line 1127 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5802 "tools/widl/parser.tab.c"
    break;

  case 378: /* $@6: %empty  */
#line 1128 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5808 "tools/widl/parser.tab.c"
    break;

  case 379: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1129 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))), &(yylsp[-9]));
						}
#line 5816 "tools/widl/parser.tab.c"
    break;

  case 380: /* required_types: qualified_type  */
#line 1135 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5822 "tools/widl/parser.tab.c"
    break;

  case 381: /* required_types: parameterized_type  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5828 "tools/widl/parser.tab.c"
    break;

  case 382: /* required_types: required_types ',' qualified_type  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5834 "tools/widl/parser.tab.c"
    break;

  case 383: /* required_types: required_types ',' parameterized_type  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5840 "tools/widl/parser.tab.c"
    break;

  case 384: /* requires: %empty  */
#line 1142 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5846 "tools/widl/parser.tab.c"
    break;

  case 385: /* requires: tREQUIRES required_types  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5852 "tools/widl/parser.tab.c"
    break;

  case 386: /* $@7: %empty  */
#line 1146 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5858 "tools/widl/parser.tab.c"
    break;

  case 387: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1148 "tools/widl/parser.y"
                                                { if ((yyvsp[-7].type)->type_type == TYPE_PARAMETERIZED_TYPE)
						  {
						      (yyval.type) = type_parameterized_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list), &(yylsp[-7]));
						      pop_parameters_namespace((yyvsp[-7].type)->name);
						  }
						  else
						  {
						      (yyval.type) = type_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typeref_list), &(yylsp[-7]));
						      check_async_uuid((yyval.type));
						  }
						}
#line 5874 "tools/widl/parser.tab.c"
    break;

  case 388: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5880 "tools/widl/parser.tab.c"
    break;

  case 389: /* interfaceref: tINTERFACE typename  */
#line 1163 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5886 "tools/widl/parser.tab.c"
    break;

  case 390: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5892 "tools/widl/parser.tab.c"
    break;

  case 391: /* interfaceref: tINTERFACE parameterized_type  */
#line 1165 "tools/widl/parser.y"
                                                { if (type_get_type(((yyval.type) = (yyvsp[0].type))) != TYPE_INTERFACE) error_loc("%s is not an interface\n", (yyval.type)->name); }
#line 5898 "tools/widl/parser.tab.c"
    break;

  case 392: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1169 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5904 "tools/widl/parser.tab.c"
    break;

  case 393: /* module: tMODULE typename  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5910 "tools/widl/parser.tab.c"
    break;

  case 394: /* moduledef: m_attributes module '{' int_statements '}' semicolon_opt  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list), &(yylsp[-4])); }
#line 5916 "tools/widl/parser.tab.c"
    break;

  case 395: /* storage_cls_spec: tEXTERN  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5922 "tools/widl/parser.tab.c"
    break;

  case 396: /* storage_cls_spec: tSTATIC  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5928 "tools/widl/parser.tab.c"
    break;

  case 397: /* storage_cls_spec: tREGISTER  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5934 "tools/widl/parser.tab.c"
    break;

  case 398: /* function_specifier: tINLINE  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5940 "tools/widl/parser.tab.c"
    break;

  case 399: /* type_qualifier: tCONST  */
#line 1190 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5946 "tools/widl/parser.tab.c"
    break;

  case 400: /* m_type_qual_list: %empty  */
#line 1194 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5952 "tools/widl/parser.tab.c"
    break;

  case 401: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1195 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5958 "tools/widl/parser.tab.c"
    break;

  case 402: /* decl_spec: type m_decl_spec_no_type  */
#line 1198 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5964 "tools/widl/parser.tab.c"
    break;

  case 403: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1200 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5970 "tools/widl/parser.tab.c"
    break;

  case 404: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1204 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5976 "tools/widl/parser.tab.c"
    break;

  case 405: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5982 "tools/widl/parser.tab.c"
    break;

  case 406: /* m_decl_spec_no_type: %empty  */
#line 1210 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5988 "tools/widl/parser.tab.c"
    break;

  case 408: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1215 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5994 "tools/widl/parser.tab.c"
    break;

  case 409: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1216 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 6000 "tools/widl/parser.tab.c"
    break;

  case 410: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1217 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 6006 "tools/widl/parser.tab.c"
    break;

  case 411: /* declarator: '*' m_type_qual_list declarator  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6012 "tools/widl/parser.tab.c"
    break;

  case 412: /* declarator: callconv declarator  */
#line 1223 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6018 "tools/widl/parser.tab.c"
    break;

  case 414: /* direct_declarator: ident  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 6024 "tools/widl/parser.tab.c"
    break;

  case 415: /* direct_declarator: '(' declarator ')'  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6030 "tools/widl/parser.tab.c"
    break;

  case 416: /* direct_declarator: direct_declarator array  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6036 "tools/widl/parser.tab.c"
    break;

  case 417: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 6042 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1237 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6048 "tools/widl/parser.tab.c"
    break;

  case 419: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1238 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6054 "tools/widl/parser.tab.c"
    break;

  case 421: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6060 "tools/widl/parser.tab.c"
    break;

  case 422: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1246 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6066 "tools/widl/parser.tab.c"
    break;

  case 423: /* m_abstract_declarator: %empty  */
#line 1251 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6072 "tools/widl/parser.tab.c"
    break;

  case 425: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1257 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6078 "tools/widl/parser.tab.c"
    break;

  case 426: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1258 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6084 "tools/widl/parser.tab.c"
    break;

  case 427: /* abstract_direct_declarator: array  */
#line 1259 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6090 "tools/widl/parser.tab.c"
    break;

  case 428: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1261 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6098 "tools/widl/parser.tab.c"
    break;

  case 429: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6106 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6112 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_declarator: callconv m_any_declarator  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6118 "tools/widl/parser.tab.c"
    break;

  case 433: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1281 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6124 "tools/widl/parser.tab.c"
    break;

  case 434: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1282 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6130 "tools/widl/parser.tab.c"
    break;

  case 435: /* m_any_declarator: %empty  */
#line 1287 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6136 "tools/widl/parser.tab.c"
    break;

  case 437: /* any_direct_declarator: ident  */
#line 1295 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 6142 "tools/widl/parser.tab.c"
    break;

  case 438: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1296 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6148 "tools/widl/parser.tab.c"
    break;

  case 439: /* any_direct_declarator: any_direct_declarator array  */
#line 1297 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6154 "tools/widl/parser.tab.c"
    break;

  case 440: /* any_direct_declarator: array  */
#line 1298 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6160 "tools/widl/parser.tab.c"
    break;

  case 441: /* any_direct_declarator: '(' m_args ')'  */
#line 1300 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6168 "tools/widl/parser.tab.c"
    break;

  case 442: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1304 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6176 "tools/widl/parser.tab.c"
    break;

  case 443: /* declarator_list: declarator  */
#line 1310 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6182 "tools/widl/parser.tab.c"
    break;

  case 444: /* declarator_list: declarator_list ',' declarator  */
#line 1311 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6188 "tools/widl/parser.tab.c"
    break;

  case 445: /* m_bitfield: %empty  */
#line 1315 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 6194 "tools/widl/parser.tab.c"
    break;

  case 446: /* m_bitfield: ':' expr_const  */
#line 1316 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 6200 "tools/widl/parser.tab.c"
    break;

  case 447: /* struct_declarator: any_declarator m_bitfield  */
#line 1319 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 6209 "tools/widl/parser.tab.c"
    break;

  case 448: /* struct_declarator_list: struct_declarator  */
#line 1326 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6215 "tools/widl/parser.tab.c"
    break;

  case 449: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1328 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6221 "tools/widl/parser.tab.c"
    break;

  case 450: /* init_declarator: declarator  */
#line 1332 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 6227 "tools/widl/parser.tab.c"
    break;

  case 451: /* init_declarator: declarator '=' expr_const  */
#line 1333 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 6233 "tools/widl/parser.tab.c"
    break;

  case 452: /* threading_type: tAPARTMENT  */
#line 1337 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 6239 "tools/widl/parser.tab.c"
    break;

  case 453: /* threading_type: tNEUTRAL  */
#line 1338 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6245 "tools/widl/parser.tab.c"
    break;

  case 454: /* threading_type: tSINGLE  */
#line 1339 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6251 "tools/widl/parser.tab.c"
    break;

  case 455: /* threading_type: tFREE  */
#line 1340 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6257 "tools/widl/parser.tab.c"
    break;

  case 456: /* threading_type: tBOTH  */
#line 1341 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6263 "tools/widl/parser.tab.c"
    break;

  case 457: /* threading_type: tMTA  */
#line 1342 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6269 "tools/widl/parser.tab.c"
    break;

  case 458: /* pointer_type: tREF  */
#line 1346 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6275 "tools/widl/parser.tab.c"
    break;

  case 459: /* pointer_type: tUNIQUE  */
#line 1347 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6281 "tools/widl/parser.tab.c"
    break;

  case 460: /* pointer_type: tPTR  */
#line 1348 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6287 "tools/widl/parser.tab.c"
    break;

  case 461: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1351 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list), &(yylsp[-3])); }
#line 6293 "tools/widl/parser.tab.c"
    break;

  case 462: /* unqualified_type: tVOID  */
#line 1355 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6299 "tools/widl/parser.tab.c"
    break;

  case 463: /* unqualified_type: base_type  */
#line 1356 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6305 "tools/widl/parser.tab.c"
    break;

  case 464: /* unqualified_type: enumdef  */
#line 1357 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6311 "tools/widl/parser.tab.c"
    break;

  case 465: /* unqualified_type: tENUM typename  */
#line 1358 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 6317 "tools/widl/parser.tab.c"
    break;

  case 466: /* unqualified_type: structdef  */
#line 1359 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6323 "tools/widl/parser.tab.c"
    break;

  case 467: /* unqualified_type: tSTRUCT typename  */
#line 1360 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 6329 "tools/widl/parser.tab.c"
    break;

  case 468: /* unqualified_type: uniondef  */
#line 1361 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6335 "tools/widl/parser.tab.c"
    break;

  case 469: /* unqualified_type: tUNION typename  */
#line 1362 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL, &(yyloc)); }
#line 6341 "tools/widl/parser.tab.c"
    break;

  case 470: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1363 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6347 "tools/widl/parser.tab.c"
    break;

  case 471: /* unqualified_type: aKNOWNTYPE  */
#line 1364 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6353 "tools/widl/parser.tab.c"
    break;

  case 473: /* type: namespace_pfx typename  */
#line 1369 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6359 "tools/widl/parser.tab.c"
    break;

  case 474: /* type: parameterized_type  */
#line 1370 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6365 "tools/widl/parser.tab.c"
    break;

  case 475: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1374 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs( (yyloc), (yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs( (yyvsp[-4].attr_list) ) );
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), (yyvsp[-1].declspec)->type->defined && !(yyvsp[-1].declspec)->type->defined_in_import);
						}
#line 6374 "tools/widl/parser.tab.c"
    break;

  case 476: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1381 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list), &(yylsp[-3])); }
#line 6380 "tools/widl/parser.tab.c"
    break;

  case 477: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1384 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list), &(yylsp[-8])); }
#line 6386 "tools/widl/parser.tab.c"
    break;

  case 478: /* version: aNUM  */
#line 1388 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].integer).value, 0); }
#line 6392 "tools/widl/parser.tab.c"
    break;

  case 479: /* version: aNUM '.' aNUM  */
#line 1389 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].integer).value, (yyvsp[0].integer).value); }
#line 6398 "tools/widl/parser.tab.c"
    break;

  case 480: /* version: aHEXNUM  */
#line 1390 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].integer).value; }
#line 6404 "tools/widl/parser.tab.c"
    break;

  case 485: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1405 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6412 "tools/widl/parser.tab.c"
    break;

  case 486: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1412 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6422 "tools/widl/parser.tab.c"
    break;

  case 487: /* acf_attributes: %empty  */
#line 1420 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6428 "tools/widl/parser.tab.c"
    break;

  case 488: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1421 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6434 "tools/widl/parser.tab.c"
    break;

  case 489: /* acf_attribute_list: acf_attribute  */
#line 1425 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6440 "tools/widl/parser.tab.c"
    break;

  case 490: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1426 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6446 "tools/widl/parser.tab.c"
    break;

  case 491: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1431 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ALLOCATE, (yyvsp[-1].num) ); }
#line 6452 "tools/widl/parser.tab.c"
    break;

  case 492: /* acf_attribute: tENCODE  */
#line 1432 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 6458 "tools/widl/parser.tab.c"
    break;

  case 493: /* acf_attribute: tDECODE  */
#line 1433 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 6464 "tools/widl/parser.tab.c"
    break;

  case 494: /* acf_attribute: tEXPLICITHANDLE  */
#line 1434 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 6470 "tools/widl/parser.tab.c"
    break;

  case 495: /* allocate_option_list: allocate_option  */
#line 1438 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6476 "tools/widl/parser.tab.c"
    break;

  case 496: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1440 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6482 "tools/widl/parser.tab.c"
    break;

  case 497: /* allocate_option: tDONTFREE  */
#line 1444 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6488 "tools/widl/parser.tab.c"
    break;

  case 498: /* allocate_option: tFREE  */
#line 1445 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6494 "tools/widl/parser.tab.c"
    break;

  case 499: /* allocate_option: tALLNODES  */
#line 1446 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6500 "tools/widl/parser.tab.c"
    break;

  case 500: /* allocate_option: tSINGLENODE  */
#line 1447 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6506 "tools/widl/parser.tab.c"
    break;


#line 6510 "tools/widl/parser.tab.c"

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
  *++yylsp = yyloc;

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
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
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
        yyerror (&yylloc, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= PARSER_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == PARSER_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = PARSER_EMPTY;
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
  ++yynerrs;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != PARSER_EMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
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

#line 1450 "tools/widl/parser.y"


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

static void append_chain_callconv( struct location where, type_t *chain, char *callconv )
{
    type_t *chain_end;

    if (chain && (chain_end = get_chain_end(chain)))
        chain_end->attrs = append_attr( chain_end->attrs, attr_ptr( where, ATTR_CALLCONV, callconv ) );
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
  v->is_defined = type->defined && !type->defined_in_import;

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
          warning_at( &v->where, "%s: pointer attribute applied to interface pointer type has no effect\n", v->name );
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
  init_location( &v->where, NULL, NULL );
  v->is_defined = 1;
  return v;
}

static var_t *copy_var(var_t *src, char *name, map_attrs_filter_t attr_filter)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  v->declspec = src->declspec;
  v->attrs = map_attrs(src->attrs, attr_filter);
  v->eval = src->eval;
  v->where = src->where;
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

static void push_namespaces(str_list_t *names)
{
  const struct str_list_entry_t *name;
  LIST_FOR_EACH_ENTRY(name, names, const struct str_list_entry_t, entry)
    push_namespace(name->str);
}

static void pop_namespaces(str_list_t *names)
{
  const struct str_list_entry_t *name;
  LIST_FOR_EACH_ENTRY_REV(name, names, const struct str_list_entry_t, entry)
    pop_namespace(name->str);
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

static type_t *reg_typedefs( struct location where, decl_spec_t *decl_spec, declarator_list_t *decls, attr_list_t *attrs )
{
  declarator_t *decl;
  type_t *type = decl_spec->type;

  if (is_attr(attrs, ATTR_UUID) && !is_attr(attrs, ATTR_PUBLIC))
    attrs = append_attr( attrs, attr_int( where, ATTR_PUBLIC, 0 ) );

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
        attrs = append_attr( attrs, attr_int( where, ATTR_PUBLIC, 0 ) );
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
      if (cur && input_name == cur->where.input_name)
          error_loc( "%s: redefinition error; original definition was at %s:%d\n",
                     cur->name, cur->where.input_name, cur->where.first_line );

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
    char *dst = replace_extension( idl_name, ".idl", "" );
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';
  }
  return strmake("__WIDL_%s_generated_name_%08lX", file_id, n++);
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
                error_at( &arg->where, "expression must resolve to integral type <= 32bits for attribute %s\n", attr_name );
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
        error_at( &arg->where, "string and length_is specified for argument %s are mutually exclusive attributes\n", arg->name );

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
                error_at( &arg->where, "expression must resolve to pointer to GUID type for attribute iid_is\n" );
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
                error_at( &arg->where, "expression must resolve to integral type <= 32bits for attribute %s\n", expr_loc.attr );
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
            error_at( &arg->where, "%s \'%s\' of %s \'%s\' %s\n", var_type, arg->name, container_type_name, container_name, reason );
            break;
        }
        case TGT_CTXT_HANDLE:
        case TGT_CTXT_HANDLE_POINTER:
            if (type_get_type(container_type) != TYPE_FUNCTION)
                error_at( &arg->where, "%s \'%s\' of %s \'%s\' cannot be a context handle\n",
                          var_type, arg->name, container_type_name, container_name );
            break;
        case TGT_STRING:
        {
            const type_t *t = type;
            while (is_ptr(t))
                t = type_pointer_get_ref_type(t);
            if (is_aliaschain_attr(t, ATTR_RANGE))
                warning_at( &arg->where, "%s: range not verified for a string of ranged types\n", arg->name );
            break;
        }
        case TGT_POINTER:
            if (type_get_type(type_pointer_get_ref_type(type)) != TYPE_VOID ||
                !type->name || strcmp(type->name, "HANDLE"))
            {
                type = type_pointer_get_ref_type(type);
                more_to_do = TRUE;
            }
            break;
        case TGT_ARRAY:
            type = type_array_get_element_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ENUM:
            type = type_get_real_type(type);
            if (!type_is_complete(type))
                error_at( &arg->where, "undefined type declaration \"enum %s\"\n", type->name );
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
            error_at( &var->where, "undefined type declaration \"struct %s\"\n", type->name );
    }
    else if (type_get_type(type) == TYPE_UNION || type_get_type(type) == TYPE_ENCAPSULATED_UNION)
    {
        if (type_is_complete(type))
            fields = type_union_get_cases(type);
        else
            error_at( &var->where, "undefined type declaration \"union %s\"\n", type->name );
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
                error_at( &arg->where, "out parameter \'%s\' of function \'%s\' is not a pointer\n", arg->name, funcname );
                break;
            case TGT_IFACE_POINTER:
                error_at( &arg->where, "out interface pointer \'%s\' of function \'%s\' is not a double pointer\n", arg->name, funcname );
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
                error_at( &arg->where, "out parameter \'%s\' of function \'%s\' cannot be an unsized string\n", arg->name, funcname );
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
        idl_handle->attrs = append_attr( NULL, attr_int( iface->where, ATTR_IN, 0 ) );
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
                error_at( &func->where, "duplicated function \'%s\'\n", func->name );
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
        append_attr( attrs, attr_ptr( attr->where, ATTR_UUID, attr->u.pval ) );
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
                begin_args = append_var(begin_args, copy_var(arg, xstrdup(arg->name), arg_in_attrs));
            if (is_attr(arg->attrs, ATTR_OUT))
                finish_args = append_var(finish_args, copy_var(arg, xstrdup(arg->name), arg_out_attrs));
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

    type_interface_define(async_iface, map_attrs(iface->attrs, async_iface_attrs), inherit, stmts, NULL, &iface->where);
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
            stmt->is_defined = 1;
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
    stmt->is_defined = type->defined && !type->defined_in_import;
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

static statement_t *make_statement_typedef(declarator_list_t *decls, bool is_defined)
{
    declarator_t *decl, *next;
    statement_t *stmt;

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    stmt->is_defined = is_defined;

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
