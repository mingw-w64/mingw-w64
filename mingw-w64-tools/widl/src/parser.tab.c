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
static statement_t *make_statement_typedef(var_list_t *names, int declonly);
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
    tDEFAULTCOLLELEM = 322,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 323,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 324,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 325, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 326,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 327,          /* tDISPINTERFACE  */
    tDLLNAME = 328,                /* tDLLNAME  */
    tDONTFREE = 329,               /* tDONTFREE  */
    tDOUBLE = 330,                 /* tDOUBLE  */
    tDUAL = 331,                   /* tDUAL  */
    tENABLEALLOCATE = 332,         /* tENABLEALLOCATE  */
    tENCODE = 333,                 /* tENCODE  */
    tENDPOINT = 334,               /* tENDPOINT  */
    tENTRY = 335,                  /* tENTRY  */
    tENUM = 336,                   /* tENUM  */
    tERRORSTATUST = 337,           /* tERRORSTATUST  */
    tEVENTADD = 338,               /* tEVENTADD  */
    tEVENTREMOVE = 339,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 340,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 341,         /* tEXPLICITHANDLE  */
    tEXTERN = 342,                 /* tEXTERN  */
    tFALSE = 343,                  /* tFALSE  */
    tFAULTSTATUS = 344,            /* tFAULTSTATUS  */
    tFLAGS = 345,                  /* tFLAGS  */
    tFLOAT = 346,                  /* tFLOAT  */
    tFORCEALLOCATE = 347,          /* tFORCEALLOCATE  */
    tHANDLE = 348,                 /* tHANDLE  */
    tHANDLET = 349,                /* tHANDLET  */
    tHELPCONTEXT = 350,            /* tHELPCONTEXT  */
    tHELPFILE = 351,               /* tHELPFILE  */
    tHELPSTRING = 352,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 353,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 354,          /* tHELPSTRINGDLL  */
    tHIDDEN = 355,                 /* tHIDDEN  */
    tHYPER = 356,                  /* tHYPER  */
    tID = 357,                     /* tID  */
    tIDEMPOTENT = 358,             /* tIDEMPOTENT  */
    tIGNORE = 359,                 /* tIGNORE  */
    tIIDIS = 360,                  /* tIIDIS  */
    tIMMEDIATEBIND = 361,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 362,         /* tIMPLICITHANDLE  */
    tIMPORT = 363,                 /* tIMPORT  */
    tIMPORTLIB = 364,              /* tIMPORTLIB  */
    tIN = 365,                     /* tIN  */
    tIN_LINE = 366,                /* tIN_LINE  */
    tINLINE = 367,                 /* tINLINE  */
    tINPUTSYNC = 368,              /* tINPUTSYNC  */
    tINT = 369,                    /* tINT  */
    tINT32 = 370,                  /* tINT32  */
    tINT3264 = 371,                /* tINT3264  */
    tINT64 = 372,                  /* tINT64  */
    tINTERFACE = 373,              /* tINTERFACE  */
    tLCID = 374,                   /* tLCID  */
    tLENGTHIS = 375,               /* tLENGTHIS  */
    tLIBRARY = 376,                /* tLIBRARY  */
    tLICENSED = 377,               /* tLICENSED  */
    tLOCAL = 378,                  /* tLOCAL  */
    tLONG = 379,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 380,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 381,                  /* tMAYBE  */
    tMESSAGE = 382,                /* tMESSAGE  */
    tMETHODS = 383,                /* tMETHODS  */
    tMODULE = 384,                 /* tMODULE  */
    tMTA = 385,                    /* tMTA  */
    tNAMESPACE = 386,              /* tNAMESPACE  */
    tNOCODE = 387,                 /* tNOCODE  */
    tNONBROWSABLE = 388,           /* tNONBROWSABLE  */
    tNONCREATABLE = 389,           /* tNONCREATABLE  */
    tNONE = 390,                   /* tNONE  */
    tNONEXTENSIBLE = 391,          /* tNONEXTENSIBLE  */
    tNOTIFY = 392,                 /* tNOTIFY  */
    tNOTIFYFLAG = 393,             /* tNOTIFYFLAG  */
    tNULL = 394,                   /* tNULL  */
    tOBJECT = 395,                 /* tOBJECT  */
    tODL = 396,                    /* tODL  */
    tOLEAUTOMATION = 397,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 398,               /* tOPTIMIZE  */
    tOPTIONAL = 399,               /* tOPTIONAL  */
    tOUT = 400,                    /* tOUT  */
    tOVERLOAD = 401,               /* tOVERLOAD  */
    tPARTIALIGNORE = 402,          /* tPARTIALIGNORE  */
    tPOINTERDEFAULT = 403,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 404,         /* tPRAGMA_WARNING  */
    tPROGID = 405,                 /* tPROGID  */
    tPROPERTIES = 406,             /* tPROPERTIES  */
    tPROPGET = 407,                /* tPROPGET  */
    tPROPPUT = 408,                /* tPROPPUT  */
    tPROPPUTREF = 409,             /* tPROPPUTREF  */
    tPROTECTED = 410,              /* tPROTECTED  */
    tPROXY = 411,                  /* tPROXY  */
    tPTR = 412,                    /* tPTR  */
    tPUBLIC = 413,                 /* tPUBLIC  */
    tRANGE = 414,                  /* tRANGE  */
    tREADONLY = 415,               /* tREADONLY  */
    tREF = 416,                    /* tREF  */
    tREGISTER = 417,               /* tREGISTER  */
    tREPRESENTAS = 418,            /* tREPRESENTAS  */
    tREQUESTEDIT = 419,            /* tREQUESTEDIT  */
    tREQUIRES = 420,               /* tREQUIRES  */
    tRESTRICTED = 421,             /* tRESTRICTED  */
    tRETVAL = 422,                 /* tRETVAL  */
    tRUNTIMECLASS = 423,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 424,              /* tSAFEARRAY  */
    tSHORT = 425,                  /* tSHORT  */
    tSIGNED = 426,                 /* tSIGNED  */
    tSINGLENODE = 427,             /* tSINGLENODE  */
    tSIZEIS = 428,                 /* tSIZEIS  */
    tSIZEOF = 429,                 /* tSIZEOF  */
    tSMALL = 430,                  /* tSMALL  */
    tSOURCE = 431,                 /* tSOURCE  */
    tSTANDARD = 432,               /* tSTANDARD  */
    tSTATIC = 433,                 /* tSTATIC  */
    tSTRICTCONTEXTHANDLE = 434,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 435,                 /* tSTRING  */
    tSTRUCT = 436,                 /* tSTRUCT  */
    tSWITCH = 437,                 /* tSWITCH  */
    tSWITCHIS = 438,               /* tSWITCHIS  */
    tSWITCHTYPE = 439,             /* tSWITCHTYPE  */
    tTHREADING = 440,              /* tTHREADING  */
    tTRANSMITAS = 441,             /* tTRANSMITAS  */
    tTRUE = 442,                   /* tTRUE  */
    tTYPEDEF = 443,                /* tTYPEDEF  */
    tUIDEFAULT = 444,              /* tUIDEFAULT  */
    tUNION = 445,                  /* tUNION  */
    tUNIQUE = 446,                 /* tUNIQUE  */
    tUNSIGNED = 447,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 448,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 449,            /* tUSERMARSHAL  */
    tUUID = 450,                   /* tUUID  */
    tV1ENUM = 451,                 /* tV1ENUM  */
    tVARARG = 452,                 /* tVARARG  */
    tVERSION = 453,                /* tVERSION  */
    tVIPROGID = 454,               /* tVIPROGID  */
    tVOID = 455,                   /* tVOID  */
    tWCHAR = 456,                  /* tWCHAR  */
    tWIREMARSHAL = 457,            /* tWIREMARSHAL  */
    tAPARTMENT = 458,              /* tAPARTMENT  */
    tNEUTRAL = 459,                /* tNEUTRAL  */
    tSINGLE = 460,                 /* tSINGLE  */
    tFREE = 461,                   /* tFREE  */
    tBOTH = 462,                   /* tBOTH  */
    CAST = 463,                    /* CAST  */
    PPTR = 464,                    /* PPTR  */
    POS = 465,                     /* POS  */
    NEG = 466,                     /* NEG  */
    ADDRESSOF = 467                /* ADDRESSOF  */
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
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;
	struct namespace *namespace;

#line 491 "tools/widl/parser.tab.c"

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
void pop_import( PARSER_LTYPE *yylloc );

# define YYLLOC_DEFAULT( cur, rhs, n ) \
        do { if (n) init_location( &(cur), &YYRHSLOC( rhs, 1 ), &YYRHSLOC( rhs, n ) ); \
             else init_location( &(cur), &YYRHSLOC( rhs, 0 ), NULL ); } while(0)


#line 531 "tools/widl/parser.tab.c"


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
  YYSYMBOL_tDEFAULTCOLLELEM = 67,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 68,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 69,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 70,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 71,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 72,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 73,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 74,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 75,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 76,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 77,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 78,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 79,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 80,                    /* tENTRY  */
  YYSYMBOL_tENUM = 81,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 82,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 83,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 84,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 85,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 86,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 87,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 88,                    /* tFALSE  */
  YYSYMBOL_tFAULTSTATUS = 89,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 90,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 91,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 92,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 93,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 94,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 95,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 96,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 97,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 98,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 99,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 100,                  /* tHIDDEN  */
  YYSYMBOL_tHYPER = 101,                   /* tHYPER  */
  YYSYMBOL_tID = 102,                      /* tID  */
  YYSYMBOL_tIDEMPOTENT = 103,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 104,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 105,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 106,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 107,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 108,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 109,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 110,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 111,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 112,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 113,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 114,                     /* tINT  */
  YYSYMBOL_tINT32 = 115,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 116,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 117,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 118,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 119,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 120,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 121,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 122,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 123,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 124,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 125,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 126,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 127,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 128,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 129,                  /* tMODULE  */
  YYSYMBOL_tMTA = 130,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 131,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 132,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 133,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 134,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 135,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 136,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 137,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 138,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 139,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 140,                  /* tOBJECT  */
  YYSYMBOL_tODL = 141,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 142,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 143,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 144,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 145,                     /* tOUT  */
  YYSYMBOL_tOVERLOAD = 146,                /* tOVERLOAD  */
  YYSYMBOL_tPARTIALIGNORE = 147,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPOINTERDEFAULT = 148,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 149,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 150,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 151,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 152,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 153,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 154,              /* tPROPPUTREF  */
  YYSYMBOL_tPROTECTED = 155,               /* tPROTECTED  */
  YYSYMBOL_tPROXY = 156,                   /* tPROXY  */
  YYSYMBOL_tPTR = 157,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 158,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 159,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 160,                /* tREADONLY  */
  YYSYMBOL_tREF = 161,                     /* tREF  */
  YYSYMBOL_tREGISTER = 162,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 163,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 164,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 165,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 166,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 167,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 168,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 169,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 170,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 171,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 172,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 173,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 174,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 175,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 176,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 177,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 178,                  /* tSTATIC  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 179,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 180,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 181,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 182,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 183,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 184,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 185,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 186,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 187,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 188,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 189,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 190,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 191,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 192,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 193,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 194,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 195,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 196,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 197,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 198,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 199,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 200,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 201,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 202,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 203,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 204,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 205,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 206,                    /* tFREE  */
  YYSYMBOL_tBOTH = 207,                    /* tBOTH  */
  YYSYMBOL_208_ = 208,                     /* ','  */
  YYSYMBOL_209_ = 209,                     /* '?'  */
  YYSYMBOL_210_ = 210,                     /* ':'  */
  YYSYMBOL_211_ = 211,                     /* '|'  */
  YYSYMBOL_212_ = 212,                     /* '^'  */
  YYSYMBOL_213_ = 213,                     /* '&'  */
  YYSYMBOL_214_ = 214,                     /* '<'  */
  YYSYMBOL_215_ = 215,                     /* '>'  */
  YYSYMBOL_216_ = 216,                     /* '-'  */
  YYSYMBOL_217_ = 217,                     /* '+'  */
  YYSYMBOL_218_ = 218,                     /* '*'  */
  YYSYMBOL_219_ = 219,                     /* '/'  */
  YYSYMBOL_220_ = 220,                     /* '%'  */
  YYSYMBOL_221_ = 221,                     /* '!'  */
  YYSYMBOL_222_ = 222,                     /* '~'  */
  YYSYMBOL_CAST = 223,                     /* CAST  */
  YYSYMBOL_PPTR = 224,                     /* PPTR  */
  YYSYMBOL_POS = 225,                      /* POS  */
  YYSYMBOL_NEG = 226,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 227,                /* ADDRESSOF  */
  YYSYMBOL_228_ = 228,                     /* '.'  */
  YYSYMBOL_229_ = 229,                     /* '['  */
  YYSYMBOL_230_ = 230,                     /* ']'  */
  YYSYMBOL_231_ = 231,                     /* ';'  */
  YYSYMBOL_232_ = 232,                     /* '{'  */
  YYSYMBOL_233_ = 233,                     /* '}'  */
  YYSYMBOL_234_ = 234,                     /* '('  */
  YYSYMBOL_235_ = 235,                     /* ')'  */
  YYSYMBOL_236_ = 236,                     /* '='  */
  YYSYMBOL_YYACCEPT = 237,                 /* $accept  */
  YYSYMBOL_input = 238,                    /* input  */
  YYSYMBOL_m_acf = 239,                    /* m_acf  */
  YYSYMBOL_decl_statements = 240,          /* decl_statements  */
  YYSYMBOL_decl_block = 241,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 242,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 243,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 244,           /* gbl_statements  */
  YYSYMBOL_245_1 = 245,                    /* $@1  */
  YYSYMBOL_imp_statements = 246,           /* imp_statements  */
  YYSYMBOL_247_2 = 247,                    /* $@2  */
  YYSYMBOL_int_statements = 248,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 249,            /* semicolon_opt  */
  YYSYMBOL_statement = 250,                /* statement  */
  YYSYMBOL_pragma_warning = 251,           /* pragma_warning  */
  YYSYMBOL_warnings = 252,                 /* warnings  */
  YYSYMBOL_typedecl = 253,                 /* typedecl  */
  YYSYMBOL_cppquote = 254,                 /* cppquote  */
  YYSYMBOL_import_start = 255,             /* import_start  */
  YYSYMBOL_import = 256,                   /* import  */
  YYSYMBOL_importlib = 257,                /* importlib  */
  YYSYMBOL_libraryhdr = 258,               /* libraryhdr  */
  YYSYMBOL_library_start = 259,            /* library_start  */
  YYSYMBOL_librarydef = 260,               /* librarydef  */
  YYSYMBOL_m_args = 261,                   /* m_args  */
  YYSYMBOL_arg_list = 262,                 /* arg_list  */
  YYSYMBOL_args = 263,                     /* args  */
  YYSYMBOL_arg = 264,                      /* arg  */
  YYSYMBOL_array = 265,                    /* array  */
  YYSYMBOL_m_attributes = 266,             /* m_attributes  */
  YYSYMBOL_attributes = 267,               /* attributes  */
  YYSYMBOL_attrib_list = 268,              /* attrib_list  */
  YYSYMBOL_str_list = 269,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 270,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 271,             /* contract_ver  */
  YYSYMBOL_contract_req = 272,             /* contract_req  */
  YYSYMBOL_static_attr = 273,              /* static_attr  */
  YYSYMBOL_activatable_attr = 274,         /* activatable_attr  */
  YYSYMBOL_access_attr = 275,              /* access_attr  */
  YYSYMBOL_composable_attr = 276,          /* composable_attr  */
  YYSYMBOL_attribute = 277,                /* attribute  */
  YYSYMBOL_callconv = 278,                 /* callconv  */
  YYSYMBOL_cases = 279,                    /* cases  */
  YYSYMBOL_case = 280,                     /* case  */
  YYSYMBOL_enums = 281,                    /* enums  */
  YYSYMBOL_enum_list = 282,                /* enum_list  */
  YYSYMBOL_enum_member = 283,              /* enum_member  */
  YYSYMBOL_enum = 284,                     /* enum  */
  YYSYMBOL_enumdef = 285,                  /* enumdef  */
  YYSYMBOL_m_exprs = 286,                  /* m_exprs  */
  YYSYMBOL_m_expr = 287,                   /* m_expr  */
  YYSYMBOL_expr = 288,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 289,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 290,           /* expr_int_const  */
  YYSYMBOL_expr_const = 291,               /* expr_const  */
  YYSYMBOL_fields = 292,                   /* fields  */
  YYSYMBOL_field = 293,                    /* field  */
  YYSYMBOL_ne_union_field = 294,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 295,          /* ne_union_fields  */
  YYSYMBOL_union_field = 296,              /* union_field  */
  YYSYMBOL_s_field = 297,                  /* s_field  */
  YYSYMBOL_funcdef = 298,                  /* funcdef  */
  YYSYMBOL_declaration = 299,              /* declaration  */
  YYSYMBOL_m_ident = 300,                  /* m_ident  */
  YYSYMBOL_m_typename = 301,               /* m_typename  */
  YYSYMBOL_typename = 302,                 /* typename  */
  YYSYMBOL_ident = 303,                    /* ident  */
  YYSYMBOL_base_type = 304,                /* base_type  */
  YYSYMBOL_m_int = 305,                    /* m_int  */
  YYSYMBOL_int_std = 306,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 307,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 308,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 309,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 310,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 311,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 312,                  /* coclass  */
  YYSYMBOL_coclassdef = 313,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 314,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 315,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 316,              /* apicontract  */
  YYSYMBOL_apicontract_def = 317,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 318,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 319,         /* class_interfaces  */
  YYSYMBOL_class_interface = 320,          /* class_interface  */
  YYSYMBOL_dispinterface = 321,            /* dispinterface  */
  YYSYMBOL_dispattributes = 322,           /* dispattributes  */
  YYSYMBOL_dispint_props = 323,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 324,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 325,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 326,                  /* inherit  */
  YYSYMBOL_type_parameter = 327,           /* type_parameter  */
  YYSYMBOL_type_parameters = 328,          /* type_parameters  */
  YYSYMBOL_interface = 329,                /* interface  */
  YYSYMBOL_330_3 = 330,                    /* $@3  */
  YYSYMBOL_331_4 = 331,                    /* $@4  */
  YYSYMBOL_delegatedef = 332,              /* delegatedef  */
  YYSYMBOL_333_5 = 333,                    /* $@5  */
  YYSYMBOL_334_6 = 334,                    /* $@6  */
  YYSYMBOL_required_types = 335,           /* required_types  */
  YYSYMBOL_requires = 336,                 /* requires  */
  YYSYMBOL_interfacedef = 337,             /* interfacedef  */
  YYSYMBOL_338_7 = 338,                    /* $@7  */
  YYSYMBOL_interfaceref = 339,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 340,         /* dispinterfaceref  */
  YYSYMBOL_module = 341,                   /* module  */
  YYSYMBOL_moduledef = 342,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 343,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 344,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 345,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 346,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 347,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 348,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 349,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 350,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 351,               /* declarator  */
  YYSYMBOL_direct_declarator = 352,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 353,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 354, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 355,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 356, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 357,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 358, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 359,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 360,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 361,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 362,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 363,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 364,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 365,          /* init_declarator  */
  YYSYMBOL_threading_type = 366,           /* threading_type  */
  YYSYMBOL_pointer_type = 367,             /* pointer_type  */
  YYSYMBOL_structdef = 368,                /* structdef  */
  YYSYMBOL_unqualified_type = 369,         /* unqualified_type  */
  YYSYMBOL_type = 370,                     /* type  */
  YYSYMBOL_typedef = 371,                  /* typedef  */
  YYSYMBOL_uniondef = 372,                 /* uniondef  */
  YYSYMBOL_version = 373,                  /* version  */
  YYSYMBOL_acf_statements = 374,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 375,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 376,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 377,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 378,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 379,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 380,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 381,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 382           /* allocate_option  */
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
#define YYLAST   3718

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  237
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  146
/* YYNRULES -- Number of rules.  */
#define YYNRULES  497
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  915

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   467


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
       2,     2,     2,   221,     2,     2,     2,   220,   213,     2,
     234,   235,   218,   217,   208,   216,   228,   219,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   210,   231,
     214,   236,   215,   209,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   229,     2,   230,   212,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   232,   211,   233,   222,     2,     2,     2,
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
     205,   206,   207,   223,   224,   225,   226,   227
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   366,   366,   382,   383,   387,   388,   394,   398,   399,
     404,   408,   409,   409,   411,   412,   413,   414,   415,   418,
     421,   422,   424,   425,   427,   428,   429,   430,   434,   435,
     436,   437,   437,   439,   440,   441,   442,   445,   446,   448,
     449,   451,   452,   453,   454,   455,   459,   460,   464,   465,
     469,   470,   471,   472,   473,   474,   475,   478,   486,   494,
     495,   499,   500,   501,   502,   503,   504,   505,   506,   507,
     510,   513,   515,   518,   522,   524,   528,   533,   534,   537,
     538,   541,   542,   546,   551,   558,   562,   563,   567,   568,
     572,   575,   576,   577,   580,   581,   585,   586,   587,   591,
     592,   596,   604,   611,   615,   619,   620,   624,   632,   633,
     634,   635,   636,   637,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   649,   650,   651,   652,   656,
     657,   658,   659,   660,   661,   662,   663,   664,   665,   666,
     667,   668,   669,   670,   671,   672,   676,   677,   678,   679,
     680,   681,   682,   683,   684,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   703,   704,   705,   706,   707,   708,   709,   710,   711,
     712,   713,   714,   715,   716,   717,   718,   719,   720,   721,
     722,   723,   724,   725,   726,   727,   732,   733,   734,   735,
     736,   737,   738,   739,   740,   741,   742,   743,   744,   745,
     746,   747,   748,   749,   750,   751,   752,   753,   754,   755,
     756,   759,   760,   761,   762,   766,   767,   770,   774,   781,
     782,   783,   786,   790,   802,   807,   811,   816,   819,   820,
     824,   825,   828,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   838,   839,   840,   841,   842,   843,   844,   845,
     846,   847,   848,   849,   850,   851,   852,   853,   854,   855,
     856,   857,   858,   859,   860,   861,   862,   863,   864,   865,
     867,   869,   870,   873,   874,   877,   883,   890,   891,   894,
     899,   906,   907,   911,   912,   916,   917,   920,   924,   930,
     938,   942,   948,   949,   953,   954,   957,   958,   961,   964,
     965,   966,   967,   968,   969,   970,   971,   972,   973,   974,
     978,   979,   982,   983,   984,   985,   986,   987,   988,   989,
     990,   994,   995,   999,  1000,  1003,  1008,  1009,  1010,  1011,
    1012,  1016,  1017,  1021,  1024,  1028,  1031,  1036,  1039,  1043,
    1044,  1048,  1049,  1053,  1054,  1057,  1060,  1063,  1064,  1067,
    1068,  1072,  1074,  1079,  1080,  1081,  1084,  1088,  1089,  1093,
    1094,  1094,  1094,  1098,  1103,  1104,  1102,  1111,  1112,  1113,
    1114,  1118,  1119,  1122,  1122,  1135,  1139,  1140,  1141,  1145,
    1148,  1151,  1156,  1157,  1158,  1162,  1166,  1170,  1171,  1174,
    1175,  1179,  1181,  1186,  1187,  1191,  1192,  1193,  1197,  1199,
    1200,  1204,  1205,  1206,  1207,  1212,  1214,  1215,  1220,  1222,
    1227,  1228,  1233,  1234,  1235,  1236,  1240,  1248,  1250,  1251,
    1256,  1258,  1263,  1264,  1271,  1272,  1273,  1274,  1275,  1279,
    1286,  1287,  1291,  1292,  1295,  1302,  1303,  1308,  1309,  1313,
    1314,  1315,  1316,  1317,  1318,  1322,  1323,  1324,  1327,  1331,
    1332,  1333,  1334,  1335,  1336,  1337,  1338,  1339,  1340,  1344,
    1345,  1346,  1349,  1356,  1358,  1364,  1365,  1366,  1370,  1371,
    1375,  1376,  1380,  1387,  1396,  1397,  1401,  1402,  1406,  1408,
    1409,  1410,  1414,  1415,  1420,  1421,  1422,  1423
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
  "tDEFAULTCOLLELEM", "tDEFAULTVALUE", "tDEFAULTVTABLE",
  "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME",
  "tDONTFREE", "tDOUBLE", "tDUAL", "tENABLEALLOCATE", "tENCODE",
  "tENDPOINT", "tENTRY", "tENUM", "tERRORSTATUST", "tEVENTADD",
  "tEVENTREMOVE", "tEXCLUSIVETO", "tEXPLICITHANDLE", "tEXTERN", "tFALSE",
  "tFAULTSTATUS", "tFLAGS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE",
  "tHANDLET", "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING",
  "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID",
  "tIDEMPOTENT", "tIGNORE", "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE",
  "tIMPORT", "tIMPORTLIB", "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC",
  "tINT", "tINT32", "tINT3264", "tINT64", "tINTERFACE", "tLCID",
  "tLENGTHIS", "tLIBRARY", "tLICENSED", "tLOCAL", "tLONG",
  "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT",
  "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tOVERLOAD",
  "tPARTIALIGNORE", "tPOINTERDEFAULT", "tPRAGMA_WARNING", "tPROGID",
  "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF", "tPROTECTED",
  "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER",
  "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES", "tRESTRICTED", "tRETVAL",
  "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT", "tSIGNED", "tSINGLENODE",
  "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTANDARD", "tSTATIC",
  "tSTRICTCONTEXTHANDLE", "tSTRING", "tSTRUCT", "tSWITCH", "tSWITCHIS",
  "tSWITCHTYPE", "tTHREADING", "tTRANSMITAS", "tTRUE", "tTYPEDEF",
  "tUIDEFAULT", "tUNION", "tUNIQUE", "tUNSIGNED", "tUSESGETLASTERROR",
  "tUSERMARSHAL", "tUUID", "tV1ENUM", "tVARARG", "tVERSION", "tVIPROGID",
  "tVOID", "tWCHAR", "tWIREMARSHAL", "tAPARTMENT", "tNEUTRAL", "tSINGLE",
  "tFREE", "tBOTH", "','", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'-'", "'+'", "'*'", "'/'", "'%'", "'!'", "'~'", "CAST", "PPTR", "POS",
  "NEG", "ADDRESSOF", "'.'", "'['", "']'", "';'", "'{'", "'}'", "'('",
  "')'", "'='", "$accept", "input", "m_acf", "decl_statements",
  "decl_block", "imp_decl_statements", "imp_decl_block", "gbl_statements",
  "$@1", "imp_statements", "$@2", "int_statements", "semicolon_opt",
  "statement", "pragma_warning", "warnings", "typedecl", "cppquote",
  "import_start", "import", "importlib", "libraryhdr", "library_start",
  "librarydef", "m_args", "arg_list", "args", "arg", "array",
  "m_attributes", "attributes", "attrib_list", "str_list",
  "marshaling_behavior", "contract_ver", "contract_req", "static_attr",
  "activatable_attr", "access_attr", "composable_attr", "attribute",
  "callconv", "cases", "case", "enums", "enum_list", "enum_member", "enum",
  "enumdef", "m_exprs", "m_expr", "expr", "expr_list_int_const",
  "expr_int_const", "expr_const", "fields", "field", "ne_union_field",
  "ne_union_fields", "union_field", "s_field", "funcdef", "declaration",
  "m_ident", "m_typename", "typename", "ident", "base_type", "m_int",
  "int_std", "namespace_pfx", "qualified_type", "parameterized_type",
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

#define YYPACT_NINF (-660)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-485)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -660,   115,  1885,  -660,  -105,  -660,   -67,   -35,   282,  -660,
    -660,  -660,   282,  -660,   -77,   -72,   282,  -660,   309,  -660,
    -660,  -660,  -660,   130,   255,  -660,  -660,  -660,  -660,  -660,
     282,   130,   300,    81,  -660,   282,   109,   130,   674,  -660,
    -660,   318,   389,   674,  -660,  -660,  3516,  -660,  -660,  -660,
    -660,   126,  -660,  -660,  -660,  -660,  -660,    10,  2947,   132,
     145,  -660,  -660,  -660,   400,   168,  -660,   165,  -660,   171,
    -660,   185,  -660,   -60,   194,   272,   209,   214,  -660,  -660,
    -660,   212,   212,   212,   121,  3223,   224,  -660,   212,   225,
     226,  -660,    62,  -660,   -35,   303,  -660,  -660,  -660,  -660,
     434,  -660,  -660,   218,   228,  -660,  -660,  -660,   227,   247,
    -660,  -660,    65,  -660,  3223,  -660,  -660,   221,   235,  -100,
    -113,  -660,   230,  -660,   236,  -660,  -660,   241,  -660,  -660,
    -660,   245,   249,  -660,  -660,   250,  -660,  -660,  -660,   251,
     253,  -660,   254,  -660,  -660,  -660,  -660,   257,  -660,  -660,
    -660,   258,  -660,  -660,  -660,   259,   261,  -660,  -660,   271,
    -660,  -660,  -660,  -660,  -660,   276,   280,   281,   283,   285,
    -660,   288,  -660,  -660,   289,  -660,   291,  -660,  -660,   294,
     295,  -660,  -660,   296,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,   297,  -660,  -660,   307,  -660,
     312,   314,  -660,  -660,  -660,  -660,  -660,  -660,  -660,   316,
    -660,  -660,   317,  -660,  -660,  -660,   319,  -660,   320,  -660,
    -660,   322,   325,   330,   331,  -660,  -660,  -660,   333,   338,
    -660,  -660,   339,   341,   343,  -102,  -660,  -660,  -660,  2009,
    1159,  3223,   282,   277,   286,   404,   282,   410,   417,   302,
     306,   348,   377,   360,  -660,   121,   362,   363,  -660,   367,
     275,  2230,  -660,  -660,  -660,   593,  -660,  -660,   365,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,   121,   121,  -660,  -660,   364,    -9,  -660,  -660,  -660,
     212,  -660,  -660,  -660,   368,  -660,  -660,  -660,   -22,  -660,
    -660,   594,   366,   -57,    -3,  -660,  -660,   393,   395,   371,
    -660,   373,  -660,  3131,   589,   597,   282,   668,  3131,  3131,
     603,   600,   668,   601,   605,   668,  3131,   668,   611,   615,
     668,   616,   668,   668,  2458,   668,   668,    32,   617,   618,
     -50,   619,   668,  3223,   668,  3131,   668,  3223,   232,  3223,
    3223,   622,   287,   623,  3223,  3516,   402,  -660,   401,   408,
    -660,  -660,  -660,  -660,   413,  -660,   415,  -660,   416,  -660,
     106,   418,   419,  -660,  -660,  -660,   209,   282,  -660,  3131,
    -660,  -660,   403,  -660,   403,   -74,  -660,  -660,   423,   420,
     422,   377,  -660,  -660,  -660,   400,   122,   439,  -660,   -98,
    -660,  -660,   -38,   170,   424,  -660,   668,   143,  2458,  -660,
    -660,    56,    62,  -660,   426,  -660,   423,  -660,   282,   427,
     453,   428,  -660,   282,   656,   656,  -660,   112,   277,   113,
    -660,   430,   459,   433,   435,   437,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,   447,  -660,   668,   668,   668,
     668,   668,   668,   967,  2669,  -123,  -660,   449,   474,   450,
     478,   460,   452,   481,  2669,   455,   456,  -660,  -108,   457,
     458,   461,   462,   463,   466,   467,   471,   726,   476,  3131,
     190,   477,   -92,  -660,  2669,  -660,  -660,  -660,   480,   482,
     484,   488,   490,   486,   491,    71,   492,   520,   884,   494,
    -660,  -660,  -660,  -660,  -660,  -660,   496,   498,   500,   501,
     509,  -660,   503,   504,   505,  -660,  3516,  -660,   732,  -660,
    -660,  -660,  -660,  -660,  -660,  -660,  -112,   121,  1538,   137,
     168,  -660,  -660,   209,   577,  -660,  -660,  -660,  2230,  -660,
    1414,   534,   -64,   523,  -660,  -660,  -660,  -660,   260,  -660,
    2564,   522,   547,  -660,  -660,  -660,  -660,  -660,  -660,    73,
    -660,  -660,   570,   545,  -660,  -660,   139,   668,  -660,  -660,
     552,  -660,    51,    54,  -660,  3131,  -660,  3131,   526,  -660,
     531,  -660,   532,  -660,  3039,  -660,  -660,  -660,  3267,    31,
      31,    31,    31,    31,    31,  -660,  2493,   149,  3359,   212,
     668,   668,   762,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     763,   668,   668,  -660,  -660,    69,  -660,   603,   764,  -660,
     668,  -660,  -660,   759,  -660,  -660,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,  -660,  -660,   190,  -660,  2133,  -660,   190,
    -660,  -660,  -660,    44,  -660,   668,  -660,  -660,  -660,  -660,
    -660,  -660,   668,  -660,  -660,  -660,  3131,  -660,  -660,  -660,
    -660,  -660,  -660,   765,  -660,  -660,  -660,  -660,   -41,   537,
    -660,  -660,  2458,  -660,   561,   209,  -660,   585,  3131,   209,
       2,  -660,   146,  -660,   423,   544,  -660,  -660,  -660,   567,
     548,  1754,   551,  -660,  -660,  -660,  2366,    56,  -660,   549,
     554,   570,  2230,  -660,  -660,   282,   566,  -660,  -660,  -660,
     190,   562,   121,   150,   282,  -660,  -660,  -660,  -660,   149,
    -660,  -660,  2274,  -660,   149,  -660,   564,    82,   212,  -660,
     284,   284,  -660,   598,   598,   213,   213,  2710,  2729,  2641,
    2747,  1010,   906,   213,   213,   279,   279,    31,    31,    31,
    -660,  2586,  -660,  -660,  -660,   588,  -660,   568,  -660,  -660,
     166,  -660,   569,   190,   571,  -660,  2458,  -660,  -660,   573,
    -660,  -660,   423,  -660,   209,  1290,   282,   574,   121,  -660,
    -660,   282,   423,   580,   591,   209,   168,  -660,   612,  -660,
    -660,  -660,  -660,  3131,   592,  -660,  -660,  -660,  -660,  -660,
     796,  -660,  -660,   -94,  -660,  -660,   595,  -660,    53,  -660,
    -660,   587,  -660,   590,    84,  -660,   596,   190,   599,  -660,
     668,  2458,  -660,  -660,   668,  -660,  3131,  -660,  -660,   166,
    -660,  -660,  -660,   610,  -660,   614,  -660,  -660,     3,   209,
    -660,  -660,   620,   400,  -660,  -660,  -660,  -660,   423,  1662,
    -660,   621,   625,   668,  -660,   190,  -660,  -660,  -660,  -660,
     166,  -660,  -660,  -660,    31,   613,  2669,  -660,  -660,  -660,
    2230,   626,  -660,   630,   168,  -660,   209,  -660,  -660,  -660,
    -660,    20,  -660,  -660,    14,  2458,  -660,   668,   636,  -660,
    -660,   631,   628,   640,   162,  -660,  -660,   162,  -660,  -660,
     634,   209,  -660,  -660,  -660
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   306,    55,   468,   478,     0,   317,
     309,   328,     0,   396,     0,     0,     0,   316,   304,   318,
     392,   315,   319,   320,     0,   395,   322,   329,   330,   327,
       0,   320,     0,     0,   394,     0,     0,   320,     0,   324,
     393,   304,   304,   314,   459,   310,   108,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   461,
       0,   333,   460,   311,     0,     0,   471,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   403,   403,   403,     0,     0,   463,   469,   403,     0,
     465,   331,     0,     4,   478,     0,   306,   307,   347,   343,
       0,     5,   355,   462,     0,   305,   321,   326,     0,   369,
     325,   349,     0,   345,     0,   323,   312,   464,     0,   466,
       0,   313,     0,   110,     0,   112,   113,     0,   114,   115,
     116,     0,     0,   119,   121,     0,   122,   123,   124,     0,
       0,   127,     0,   129,   130,   131,   132,     0,   134,   135,
     136,     0,   138,   139,   140,     0,     0,   143,   144,     0,
     146,   147,   148,   149,   150,     0,     0,     0,     0,     0,
     156,     0,   158,   159,     0,   161,     0,   163,   164,   167,
       0,   168,   169,     0,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,     0,   183,   184,     0,   186,
       0,     0,   189,   190,   191,   192,   193,   457,   194,     0,
     196,   455,     0,   198,   199,   200,     0,   202,     0,   204,
     205,     0,     0,     0,     0,   210,   456,   211,     0,     0,
     215,   216,     0,     0,     0,     0,    91,   220,    51,    88,
      88,     0,     0,    88,     0,   304,     0,   304,   304,     0,
     461,     0,   363,     0,   383,     0,   463,   465,    52,   306,
     470,     0,    18,    22,    20,     0,    12,    15,     0,    49,
     385,    14,   407,   404,   406,   405,   221,   222,   223,   224,
     397,     0,     0,   308,   411,   447,   410,   301,   461,   463,
     403,   465,   399,    54,     0,   490,   489,   491,     0,   486,
     479,     0,     0,     0,    88,    71,   370,     0,     0,     0,
     287,     0,   293,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   240,     0,     0,     0,
       0,     0,     0,     0,   240,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,    90,    72,     0,     0,
      45,    42,    43,    44,     0,    36,     0,    40,     0,    38,
       0,     0,     0,    34,    33,    41,    48,     0,   390,     0,
      89,    46,   462,    74,   464,   466,    75,   351,     0,     0,
       0,   363,   300,   332,   336,     0,   337,   339,   341,     0,
     350,    11,     0,     0,     0,   409,     0,     0,    77,   413,
     400,     0,     0,   485,     0,    70,     0,     7,     0,     0,
     231,   236,   232,     0,     0,     0,   467,    88,    88,    88,
     104,     0,     0,     0,     0,     0,   251,   242,   243,   244,
     248,   249,   250,   245,   246,     0,   247,     0,     0,     0,
       0,     0,     0,     0,   285,     0,   283,     0,     0,     0,
       0,    99,     0,     0,   286,     0,     0,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,     0,     0,   238,   241,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     454,   449,   450,   451,   452,   453,     0,     0,     0,     0,
     475,   477,     0,     0,     0,    92,   108,     8,     0,    35,
      39,    37,    31,    30,    29,    76,     0,     0,    88,    88,
     364,   365,   351,    48,   381,   334,   338,   340,     0,   335,
      88,     0,    88,     0,   398,   408,   412,   448,     0,    87,
       0,     0,    81,    78,    79,   496,   494,   497,   495,     0,
     492,   487,   480,     0,   234,   237,    88,     0,   366,   367,
     371,    59,     0,     0,   458,     0,   288,     0,     0,   473,
      89,   294,     0,   109,     0,   111,   214,   117,     0,   275,
     274,   273,   276,   271,   272,   468,     0,   420,     0,   403,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   118,   120,     0,   125,     0,     0,   126,
       0,   133,   137,     0,   141,   142,   145,   151,   152,   153,
     154,   155,   157,   160,   162,   432,   397,    77,   437,   432,
     434,   433,    84,   429,   166,   240,   165,   170,   182,   185,
     187,   188,     0,   197,   201,   203,     0,   206,   207,   209,
     208,   212,   213,     0,   217,   218,   219,    93,     0,     0,
      28,   374,    77,   440,   472,    48,    47,     0,    89,    48,
       0,   352,    88,   348,     0,     0,   342,    13,   357,     0,
       0,     0,     0,    86,    85,   414,     0,     0,   488,   484,
       0,   480,     0,   233,   235,     0,     0,    60,    57,    58,
       0,   465,     0,   463,   302,   292,   291,   101,   103,   420,
     282,   397,    77,   424,   420,   421,     0,   417,   403,   401,
     264,   265,   277,   258,   259,   262,   263,   253,   254,     0,
     255,   256,   257,   261,   260,   267,   266,   269,   270,   268,
     278,     0,   284,   106,   105,     0,   100,     0,    95,    83,
     432,   397,     0,   432,     0,   428,    77,   436,   239,     0,
     102,   476,     0,    10,    48,    88,     0,     0,     0,   391,
     344,     0,     0,     0,     0,    48,   377,   378,   382,    46,
     359,   358,   361,     0,     0,   299,   362,    82,    80,   493,
       0,   483,   481,     0,   368,   372,   442,   445,     0,   290,
     297,     0,   303,     0,   420,   397,     0,   432,     0,   416,
       0,    77,   423,   402,     0,   281,     0,   128,   427,   432,
     438,   431,   435,     0,   195,     0,    73,    32,     0,    48,
     441,   389,   333,     0,   388,   353,   354,   346,     0,    88,
     360,     0,     0,     0,   444,     0,   289,   225,   280,   415,
     432,   425,   419,   422,   279,     0,   252,   107,   430,   439,
       0,     0,   373,   334,   379,   380,    48,   482,     6,   443,
     446,     0,   418,   426,     0,    77,   384,     0,     0,   474,
     226,     0,     0,     0,    88,     9,   375,    88,   296,   228,
       0,    48,   227,   295,   376
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -660,  -660,  -660,  -660,  -660,  -660,  -660,   429,  -660,   -51,
    -660,    25,  -275,    -1,  -660,   407,  -660,  -660,  -660,  -660,
    -660,  -660,  -660,    36,  -588,  -660,  -660,  -288,  -266,  -238,
      -2,  -660,  -660,  -660,   533,  -265,  -660,  -660,  -660,  -660,
    -304,   -81,  -660,  -660,  -660,  -660,  -660,   301,    17,   510,
     215,   388,  -660,  -293,  -303,  -660,  -660,  -660,  -660,   -39,
    -336,  -660,   172,  -660,    49,    -6,   -68,  -240,   179,   234,
    -250,  -246,  -243,   334,  -659,    23,    38,    28,    39,    29,
      41,    43,   337,  -660,    30,  -660,  -660,  -660,  -660,   487,
     160,    91,    21,  -660,  -660,    45,  -660,  -660,  -660,  -660,
      46,  -660,  -660,  -660,  -660,    48,  -660,  -660,  -359,  -575,
       7,   292,   -75,   -55,  -226,  -660,  -660,  -660,  -625,  -660,
    -648,  -660,  -490,  -660,  -660,  -660,    18,  -660,   624,  -660,
     542,    12,  -391,     4,  -660,    15,  -660,   793,   177,  -660,
    -660,   182,  -660,   483,  -660,   187
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    47,   303,    48,   678,   360,     2,   401,   239,
     680,   528,   270,   361,    50,   572,    51,    52,    53,    54,
     362,   249,    55,   363,   551,   552,   553,   554,   648,    57,
     380,   235,   468,   488,   727,   430,   496,   431,   765,   457,
     236,   649,   891,   900,   419,   420,   421,   422,   288,   482,
     483,   454,   455,   456,   465,   427,   576,   581,   429,   909,
     910,   804,    60,   821,   104,    61,   650,    62,   107,    63,
      64,    65,    66,   398,   399,   364,   365,   366,   367,   368,
     369,   370,   529,   691,   371,    75,   542,   701,    76,   389,
     569,   570,   372,   423,   716,   373,   786,   911,   798,   695,
     374,   391,   793,   794,   244,   375,    81,    82,    83,   403,
     480,   597,   272,    85,   285,   286,   735,   828,   736,   737,
     651,   774,   652,   653,   684,   864,   817,   818,   287,   506,
     237,   289,    87,    88,    89,   291,   512,    93,   710,   711,
      94,    95,   298,   299,   559,   560
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    49,    98,   282,   240,   379,    99,   274,   275,    84,
     102,   395,   105,   292,    86,   396,   284,    90,   397,    59,
     409,   394,   469,    77,   109,    67,   273,   273,   273,   113,
      69,    71,    74,   273,   471,   105,   105,   474,    56,   476,
      68,    70,   481,    72,   544,    73,   478,    78,    79,   493,
      80,   515,   602,   813,   459,   404,   405,   717,   260,   772,
     717,   416,   599,   485,   699,   255,   418,   897,   307,   311,
     256,   770,   816,   257,   791,   250,   241,   782,   283,   254,
      30,   251,  -306,  -484,   898,   622,   252,   253,   555,   290,
     118,   120,   578,   582,   787,   294,   276,   277,   278,   279,
     633,   525,   681,   547,   823,   268,   355,   207,  -306,   829,
     538,   211,   623,   541,   538,     3,   655,   539,   309,   312,
     792,   862,   682,    91,    96,   295,    97,   634,   356,   308,
     556,   -66,  -306,   276,   277,   278,   279,    13,   395,   242,
     296,   226,   530,   656,   826,   531,   436,  -307,   297,   437,
     438,   439,   440,   441,   442,   769,   824,   100,  -306,   775,
     101,   276,   277,   278,   279,    46,   395,   486,   265,    96,
     563,    97,   266,    96,   282,    97,   417,   545,   276,   277,
     278,   279,   276,   277,   278,   279,   412,   284,   843,   575,
     577,   577,   783,    96,    92,    97,   839,   599,   243,   869,
     282,   282,   276,   277,   278,   279,   700,   738,   413,   487,
     110,   715,   677,   284,   284,   410,   115,   816,   881,    13,
     407,   894,   538,    13,   763,   408,    46,   764,   557,   901,
    -229,   443,   600,   601,   602,   273,   378,    58,    58,   105,
     383,   105,   105,   875,   106,   377,    84,    84,   435,   283,
     870,    86,    86,   899,    90,    90,    59,    59,   693,   620,
     621,   865,   558,   436,   108,    13,   437,   438,   439,   440,
     441,   442,   116,   407,   714,   283,   283,   121,   776,   655,
     838,   707,   444,   841,   866,    96,   718,    97,   395,   719,
     687,   690,   396,   510,   511,   397,   118,   120,   394,    20,
     602,   683,   731,   111,   577,   602,   664,   902,   708,   526,
     283,   407,   103,   407,    97,   112,   831,   445,   732,   728,
     432,   117,   282,    97,    25,   458,   460,   767,   418,   762,
     446,   733,   479,   470,   265,   284,   261,   872,   522,   280,
     536,    46,    46,   114,    16,   574,   579,   494,   443,   878,
     564,   499,   497,   507,   508,   281,   447,   238,   514,   448,
     449,   548,   500,   -61,   451,   452,    46,   731,    46,   779,
     689,   283,  -230,   549,    34,    46,   258,   453,   407,   795,
     892,  -298,   261,   732,   646,  -298,   527,   777,   280,   535,
      40,    46,   119,   908,    97,   407,   262,   283,   598,   444,
     647,   780,   263,   259,   281,    97,   479,   382,   646,    97,
     789,   544,   283,   384,   790,    97,   264,   568,   808,   407,
     385,   301,    97,   543,   647,   267,     4,   580,    97,   615,
     616,   617,   618,   619,   445,   501,   502,   503,   504,   505,
     269,   620,   621,   302,   395,   271,   282,   446,   796,   -62,
    -306,   797,   -64,  -306,   690,   -63,   293,   -65,   305,   284,
     304,   306,   395,   733,   313,   544,   396,   310,   733,   397,
     314,   832,   394,   447,   283,   315,   448,   449,   450,   316,
     544,   451,   452,   317,   318,   319,   645,   320,   321,  -334,
     703,   322,   323,   324,   453,   325,   820,   617,   618,   619,
     615,   616,   617,   618,   619,   326,    46,   620,   621,   846,
     327,   544,   620,   621,   328,   329,   734,   330,   381,   331,
     857,   283,   332,   333,   739,   334,   688,   686,   335,   336,
     337,   338,   395,   598,   386,    84,   845,   -67,    58,    49,
      86,   339,   853,    90,   273,    59,   340,    84,   341,   854,
     342,   343,    86,   344,   345,    90,   346,    59,   733,   347,
     889,    77,   850,    67,   348,   349,   773,   350,    69,    71,
      74,   877,   351,   352,   882,   353,    56,   354,    68,    70,
     387,    72,   720,    73,   722,    78,    79,   388,    80,   723,
     721,   460,   390,   -68,   -69,   393,   400,   402,   433,   414,
     406,   415,   411,   424,   903,   425,   426,   428,   395,   461,
     466,   896,   884,   434,   467,   885,   463,   600,   601,   602,
     472,   687,   605,   606,   473,   475,   489,   490,   492,   785,
     395,   516,   513,   517,   396,  -306,   914,   397,   509,   283,
     394,   282,   518,   283,   519,   479,   520,   521,   734,   523,
     524,   827,   532,   734,   284,   533,   822,   537,   562,   546,
     565,   566,   571,   833,   567,   583,   577,   584,   585,   577,
     586,   436,   587,   460,   437,   438,   439,   440,   441,   442,
     479,   588,   625,   273,   624,   626,   627,   629,   628,   630,
     631,   632,   635,   636,   662,   255,   637,   638,   639,   803,
     256,   640,   641,   257,   479,   250,   642,   282,    84,   568,
     464,   644,   654,   464,   283,   657,   283,   658,   283,   659,
     284,   477,    11,   660,   484,   661,   663,   665,   666,   668,
     479,   669,   484,   670,   498,   671,   672,   673,   674,   675,
     676,   679,   694,   734,   698,   600,   601,   602,   603,   604,
     605,   606,   607,   608,   702,   706,   443,   705,   709,   712,
     715,   724,   725,   726,   283,   742,   760,   283,   768,   788,
     766,   781,   784,   243,   479,    23,   799,   800,    92,   801,
     568,   815,   283,    58,   806,   851,   852,   811,    26,    27,
      28,    29,    84,   819,   464,   550,   836,    86,    31,   830,
      90,   861,    59,   837,   840,   863,   842,   444,   844,   849,
     255,   855,   613,   614,   615,   616,   617,   618,   619,   867,
     858,   283,   856,   860,   859,   868,   620,   621,   880,   479,
     540,   871,   573,   283,   873,   589,   590,   591,   592,   593,
     594,   596,   445,   460,    37,   879,   904,   883,   893,    39,
     907,  -386,   887,   462,   495,   446,   888,   688,   686,   283,
     895,  -387,   905,   906,   283,   913,    84,   713,   912,   692,
     778,    86,   696,   805,    90,   814,    59,   848,   534,   392,
     729,   447,   491,   890,   448,   449,   450,   300,   812,   451,
     452,   810,     0,   479,   809,   561,     0,     0,     0,     0,
       0,     0,   453,   600,   601,   602,   603,   604,   605,   606,
     607,   608,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,   601,   602,   603,   604,
     605,   606,     0,     0,     0,   609,   592,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,     0,     0,     0,
       0,     0,     0,     0,   620,   621,     0,     0,     0,     0,
       0,   643,     0,     0,     0,     0,     0,     0,     0,     0,
     436,     0,   595,   437,   438,   439,   440,   441,   442,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   740,   741,
       0,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,     9,   761,
      10,     0,     0,     0,     0,    11,     0,     0,   464,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,   600,
     601,   602,   603,   604,   605,   606,     0,     0,     0,     0,
       0,     0,    17,   484,     0,     0,     0,     0,   245,    19,
       0,     0,     0,     0,    20,   443,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,     0,   609,     0,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,     0,   444,     0,     0,     0,
       0,     0,   620,   621,     0,     0,     0,     0,     0,   667,
     613,   614,   615,   616,   617,   618,   619,     0,     0,    34,
       0,     0,     0,     0,   620,   621,    36,    37,    38,     0,
       0,   445,    39,     0,     0,    40,     0,     0,   247,     0,
       0,     0,     0,     0,   446,     0,     0,   248,     0,    43,
       0,     0,     4,     5,     6,     0,     0,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     447,     0,     0,   448,   449,   450,     0,     0,   451,   452,
       0,     0,     0,     0,     8,     0,     0,     0,     0,     0,
       9,   453,    10,     0,     0,     0,     0,    11,    12,     0,
       0,     0,    13,     0,     0,     0,     0,     0,   874,    14,
       0,   358,   876,   612,   613,   614,   615,   616,   617,   618,
     619,    16,     0,     0,    17,     0,     0,     0,   620,   621,
      18,    19,     0,     0,     0,     0,    20,     0,     0,     0,
      21,   464,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    24,   359,     0,
       0,    25,     0,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     8,     0,    35,    36,    37,
      38,     9,     0,    10,    39,     0,     0,    40,    11,    12,
      41,     0,     0,    13,     0,     0,     0,     0,     0,    42,
      14,    43,   358,     0,     0,     0,     0,     0,     0,    44,
      45,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    20,     0,     0,
       0,    21,     0,     0,    22,     0,     0,     0,    46,     0,
       0,    23,   376,     0,     0,     0,     0,     0,    24,   359,
       0,     0,    25,     0,    26,    27,    28,    29,    30,     0,
       0,     0,     0,     0,    31,     0,     0,     4,     5,     6,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,    34,     0,     0,     9,     0,    10,    35,    36,
      37,    38,    11,    12,     0,    39,     0,    13,    40,     0,
       0,    41,     0,     0,    14,     0,    15,     0,     0,     0,
      42,     0,    43,     0,     0,     0,    16,     0,     0,    17,
      44,    45,     0,     0,     0,    18,    19,     0,     0,     0,
       0,    20,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,    46,
       0,     0,    24,   847,     0,     0,    25,     0,    26,    27,
      28,    29,    30,     0,     0,     0,     0,     0,    31,     0,
       0,     4,     5,     6,     0,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     9,
       0,    10,    35,    36,    37,    38,    11,     0,     0,    39,
       0,    13,    40,     0,     0,    41,     0,     0,    14,     0,
       0,     0,     0,     0,    42,     0,    43,     0,     0,     0,
       0,     0,     0,    17,    44,    45,     0,     0,     0,    18,
      19,     0,     0,     0,     0,    20,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,    46,     0,     0,    24,   697,     0,     0,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     9,     0,    10,     0,    36,    37,    38,
      11,     0,     0,    39,     0,    13,    40,     0,     0,    41,
       0,     0,    14,     0,     0,     0,     0,     0,    42,     0,
      43,     0,     0,     0,     0,     0,     0,    17,    44,    45,
       0,     0,     0,    18,    19,     0,     0,     0,     0,    20,
       0,     0,     0,    21,     0,     0,    22,     4,     0,     6,
       0,     0,     0,    23,     0,     0,     0,    46,     0,     0,
      24,   685,     0,     0,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,    11,     0,     0,     0,     0,    13,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,    17,
       0,    36,    37,    38,     0,   245,    19,    39,     0,     0,
      40,    20,     0,    41,     0,    21,     0,     0,    22,     0,
       0,     0,    42,     0,    43,    23,     0,     0,     0,     0,
       0,     0,    44,    45,     0,     0,    25,     0,    26,    27,
      28,    29,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    -3,     0,     0,     4,     5,
       6,    46,     0,     0,     0,   886,     0,     0,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       8,     0,     0,    36,    37,    38,     9,     0,    10,    39,
       0,     0,    40,    11,    12,   247,     0,     0,    13,     0,
       0,     0,     0,     0,   248,    14,    43,    15,     0,     0,
       0,     0,     0,     0,    44,    45,     0,    16,     0,     0,
      17,     0,     0,     0,     0,     0,    18,    19,     0,     0,
       0,     0,    20,     0,     0,     0,    21,     0,     0,    22,
       0,     0,     0,    46,     0,     0,    23,   802,     0,     0,
       0,     0,     0,    24,     0,     0,     0,    25,     0,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,    31,
       0,     0,     4,     5,     6,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   357,     0,     0,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,    34,     0,     0,
       9,     0,    10,    35,    36,    37,    38,    11,    12,     0,
      39,     0,    13,    40,     0,     0,    41,     0,     0,    14,
       0,   358,     0,     0,     0,    42,     0,    43,     0,     0,
       0,    16,     0,     0,    17,    44,    45,     0,     0,     0,
      18,    19,     0,     0,     0,     0,    20,     0,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,    46,     0,     0,    24,   359,     0,
       0,    25,     0,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,    31,     0,     0,     4,     0,     6,     0,
      32,     0,     0,     0,     0,   276,   277,   278,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     9,     0,    10,    35,    36,    37,
      38,    11,     0,     0,    39,     0,    13,    40,     0,     0,
      41,     0,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    43,     0,     0,     0,     0,     0,     0,    17,    44,
      45,     0,     0,     0,   245,    19,     0,     0,     0,     0,
      20,     0,     0,     0,    21,     0,     0,    22,     0,     0,
       0,     0,     0,     4,    23,    97,     0,     0,    46,     0,
       0,     0,     0,     0,     0,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,     0,     0,     0,     4,    11,     6,
       0,     0,     0,     0,     0,     0,   276,   277,   278,   279,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,    17,     0,     0,    39,     0,
       0,    40,    19,     0,   247,     9,     0,    10,     0,     0,
       0,    21,    11,   248,    22,    43,     0,    13,     0,     0,
       0,    23,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    26,    27,    28,    29,     0,    17,
       0,   771,     0,     0,    31,   245,    19,     0,     0,     0,
       0,    20,    46,     0,     0,    21,     0,     0,    22,     4,
       0,     6,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    26,    27,
      28,    29,     0,     0,   807,     0,     0,     0,    31,     0,
      37,    38,     0,     0,     0,    39,     0,     9,     0,    10,
       0,     0,     0,     0,    11,     0,     0,     0,     0,    13,
       0,     0,    43,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,    34,     0,     0,     0,
       0,    17,     0,    36,    37,    38,     0,   245,    19,    39,
       0,     0,    40,    20,     0,   247,     0,    21,     0,     0,
      22,     4,     0,     6,   248,     0,    43,    23,     0,     0,
       0,     0,     0,     0,    44,    45,     0,     0,    25,     0,
      26,    27,    28,    29,     0,     0,     0,     0,     0,     0,
      31,     0,   825,     0,     0,     0,     0,     0,     0,     9,
       0,    10,     0,    46,     0,     0,    11,     0,     0,     0,
       0,    13,   600,   601,   602,   603,   604,   605,   606,   607,
     608,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,    17,     0,    36,    37,    38,     0,   245,
      19,    39,     0,     0,    40,    20,     0,   247,     0,    21,
       0,     0,    22,     0,     0,     0,   248,     0,    43,    23,
       0,     0,     0,     0,     0,     0,    44,    45,     0,     0,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,   600,   601,   602,   603,   604,   605,   606,
     607,   608,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   600,   601,   602,   603,   604,
     605,   606,   607,   608,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,    39,     0,     0,    40,     0,     0,   247,
       0,     0,     0,     0,     0,     0,     0,     0,   248,     0,
      43,     0,     0,     0,     0,     0,     0,     0,    44,    45,
     600,   601,   602,   603,   604,   605,   606,   607,   608,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,   600,   601,
     602,   603,   604,   605,   606,   607,   608,     0,     0,     0,
       0,     0,   609,     0,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,     0,     0,     0,     0,     0,     0,
       0,   620,   621,     0,     0,     0,     0,     0,   730,   600,
     601,   602,   603,   604,   605,   606,     0,   608,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   600,   601,
     602,   603,   604,   605,   606,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   600,   601,   602,   603,
     604,   605,   606,   609,     0,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,     0,     0,     0,     0,     0,
       0,     0,   620,   621,   704,   609,     0,   610,   611,   612,
     613,   614,   615,   616,   617,   618,   619,     0,     0,     0,
       0,     0,     0,     0,   620,   621,   835,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     609,   834,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,     0,     0,     0,     0,     0,     0,     0,   620,
     621,     0,     0,     0,     0,     0,     0,     0,   609,     0,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
       0,     0,     0,     0,     0,     0,     0,   620,   621,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,     0,     0,     0,     0,     0,     0,     0,   620,   621,
     610,   611,   612,   613,   614,   615,   616,   617,   618,   619,
       4,     0,     6,     0,     0,     0,     0,   620,   621,   611,
     612,   613,   614,   615,   616,   617,   618,   619,     0,     0,
       0,     0,     0,     0,     0,   620,   621,     0,     0,     0,
       0,     0,     8,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,    11,    12,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,  -356,
       0,     0,    17,     0,     0,     0,     0,     0,   245,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,    22,     4,     0,     6,   461,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,    30,     0,     0,   246,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    17,    35,    36,    37,    38,     0,
     245,    19,    39,     0,     0,    40,    20,     0,   247,     0,
      21,     0,     0,    22,     4,     0,     6,   248,     0,    43,
      23,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,    25,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,    11,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,    17,     0,    36,    37,
      38,     0,   245,    19,    39,     0,     0,    40,    20,     0,
     247,     0,    21,     0,     0,    22,     4,     0,     6,   248,
       0,    43,    23,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,    25,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,    10,     0,     0,     0,
       0,    11,   595,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,    17,     0,
      36,    37,    38,     0,   245,    19,    39,     0,     9,    40,
      10,     0,   247,     0,    21,    11,     0,    22,     0,     0,
      13,   248,     0,    43,    23,     0,     0,     0,     0,     0,
       0,    44,    45,     0,     0,     0,     0,    26,    27,    28,
      29,     0,    17,     0,     0,     0,     0,    31,   245,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,    22,     0,     0,   595,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,    36,    37,    38,     0,     0,     0,    39,     0,
       9,     0,    10,     0,   247,     0,     0,    11,     0,     0,
       0,     0,     0,   248,     0,    43,     0,     0,     0,     0,
       0,     0,     0,    44,    45,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    17,     0,    36,    37,    38,     0,
     245,    19,    39,     0,     0,    40,     0,     0,   247,     0,
      21,     0,     0,    22,     0,     0,     0,   248,     0,    43,
      23,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,     0,     0,     0,     0,
     247,     0,     0,     0,     0,   122,   123,     0,     0,   248,
     124,    43,   125,   126,   127,   128,   129,     0,   130,    44,
      45,   131,     0,   132,     0,     0,   133,   134,   135,     0,
     136,   137,   138,   139,   140,   141,     0,   142,     0,   143,
     144,   145,     0,   146,   147,   148,   149,   150,     0,   151,
       0,     0,   152,   153,   154,   155,   156,     0,     0,   157,
     158,   159,   160,     0,     0,   161,   162,     0,   163,   164,
       0,   165,   166,   167,   168,   169,   170,     0,   171,   172,
     173,   174,   175,   176,     0,     0,   177,     0,     0,   178,
       0,     0,     0,     0,     0,   179,   180,     0,   181,   182,
       0,   183,   184,   185,     0,     0,     0,     0,   186,   187,
     188,     0,   189,   190,   191,     0,   192,   193,   194,   195,
     196,   197,   198,   199,   200,     0,   201,     0,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,     0,   212,
     213,     0,   214,   215,     0,     0,     0,     0,     0,   216,
       0,     0,   217,     0,   218,   219,   220,     0,     0,   221,
     222,   223,   224,     0,     0,   225,     0,   226,     0,   227,
     228,   229,   230,   231,   232,   233,     0,     0,   234
};

static const yytype_int16 yycheck[] =
{
       2,     2,     8,    84,    55,   243,    12,    82,    83,     2,
      16,   261,    18,    88,     2,   261,    84,     2,   261,     2,
     286,   261,   325,     2,    30,     2,    81,    82,    83,    35,
       2,     2,     2,    88,   327,    41,    42,   330,     2,   332,
       2,     2,   335,     2,   403,     2,   334,     2,     2,   342,
       2,   355,    21,   712,   319,   281,   282,     6,    64,   647,
       6,   118,   453,    31,   128,    58,   304,    47,     3,   182,
      58,   646,   720,    58,    72,    58,    66,   118,    84,    58,
     118,    58,   182,   118,    64,   208,    58,    58,    32,    85,
      41,    42,   428,   429,   682,    33,    12,    13,    14,    15,
     208,   376,   214,   406,   729,    75,   208,   157,   182,   734,
     208,   161,   235,   151,   208,     0,   208,   215,   114,   232,
     118,   215,   234,   228,     3,    63,     5,   235,   230,    64,
      74,   231,   232,    12,    13,    14,    15,    53,   388,   129,
      78,   191,   388,   235,   732,   388,     3,   214,    86,     6,
       7,     8,     9,    10,    11,   645,   731,   234,   232,   649,
     232,    12,    13,    14,    15,   229,   416,   135,   228,     3,
     416,     5,   232,     3,   255,     5,   233,   403,    12,    13,
      14,    15,    12,    13,    14,    15,   208,   255,   776,   427,
     428,   429,   233,     3,   229,     5,   771,   588,   188,   824,
     281,   282,    12,    13,    14,    15,   542,   598,   230,   177,
      31,   208,   516,   281,   282,   290,    37,   865,   215,    53,
     229,   880,   208,    53,   155,   234,   229,   158,   172,   215,
     233,    88,    19,    20,    21,   290,   242,   239,   240,   245,
     246,   247,   248,   831,   114,   241,   239,   240,   316,   255,
     825,   239,   240,   233,   239,   240,   239,   240,   533,   228,
     229,   208,   206,     3,     9,    53,     6,     7,     8,     9,
      10,    11,    38,   229,   567,   281,   282,    43,   234,   208,
     770,   208,   139,   773,   231,     3,   235,     5,   538,   235,
     528,   529,   538,     6,     7,   538,   247,   248,   538,    87,
      21,   527,   218,     3,   542,    21,   235,   895,   235,   377,
     316,   229,     3,   229,     5,   234,   234,   174,   234,   584,
     313,     3,   403,     5,   112,   318,   319,   630,   566,   622,
     187,   597,   334,   326,   228,   403,   214,   827,   232,   218,
     218,   229,   229,   234,    72,   233,   233,   343,    88,   839,
     418,   347,   345,   349,   350,   234,   213,   231,   354,   216,
     217,   218,   130,   231,   221,   222,   229,   218,   229,   662,
     233,   377,   233,   230,   162,   229,   231,   234,   229,   233,
     870,   231,   214,   234,   218,   235,   379,   653,   218,   395,
     178,   229,     3,   231,     5,   229,   231,   403,   453,   139,
     234,   666,   231,     3,   234,     5,   408,     3,   218,     5,
     685,   770,   418,     3,   689,     5,   231,   423,   706,   229,
       3,   118,     5,   402,   234,   231,     3,   429,     5,   216,
     217,   218,   219,   220,   174,   203,   204,   205,   206,   207,
     231,   228,   229,     9,   694,   231,   527,   187,   694,   231,
     232,   694,   231,   232,   692,   231,   231,   231,   231,   527,
     232,   214,   712,   729,   234,   824,   712,   232,   734,   712,
     234,   737,   712,   213,   480,   234,   216,   217,   218,   234,
     839,   221,   222,   234,   234,   234,   479,   234,   234,   214,
     230,   234,   234,   234,   234,   234,   722,   218,   219,   220,
     216,   217,   218,   219,   220,   234,   229,   228,   229,   784,
     234,   870,   228,   229,   234,   234,   597,   234,   232,   234,
     795,   527,   234,   234,   599,   234,   528,   528,   234,   234,
     234,   234,   782,   588,   232,   528,   782,   231,   540,   540,
     528,   234,   792,   528,   599,   528,   234,   540,   234,   792,
     234,   234,   540,   234,   234,   540,   234,   540,   824,   234,
     863,   540,   788,   540,   234,   234,   647,   234,   540,   540,
     540,   836,   234,   234,   849,   234,   540,   234,   540,   540,
     232,   540,   575,   540,   577,   540,   540,   210,   540,   577,
     575,   584,   232,   231,   231,   228,     3,   232,     9,     5,
     236,   235,   234,   210,   897,   210,   235,   234,   858,     6,
       9,   886,   858,    16,     9,   858,    16,    19,    20,    21,
       9,   859,    24,    25,     9,     9,     9,     9,     9,   680,
     880,   229,     9,   232,   880,   232,   911,   880,    16,   645,
     880,   722,   234,   649,   231,   647,   231,   231,   729,   231,
     231,   732,   232,   734,   722,   233,   724,   218,   232,   235,
     233,   208,     6,   738,   236,   235,   904,   208,   235,   907,
     235,     3,   235,   666,     6,     7,     8,     9,    10,    11,
     682,   234,   208,   738,   235,   235,   208,   235,   228,   208,
     235,   235,   235,   235,   208,   688,   235,   235,   235,   701,
     688,   235,   235,   688,   706,   688,   235,   788,   701,   715,
     322,   235,   235,   325,   720,   235,   722,   235,   724,   235,
     788,   333,    48,   235,   336,   235,   235,   235,   208,   235,
     732,   235,   344,   235,   346,   235,   235,   228,   235,   235,
     235,     9,   165,   824,   210,    19,    20,    21,    22,    23,
      24,    25,    26,    27,   231,   208,    88,   235,   188,   214,
     208,   235,   231,   231,   770,     3,     3,   773,     9,   208,
       6,     6,   235,   188,   776,   101,   232,   210,   229,   231,
     786,   215,   788,   785,   233,   791,   792,   233,   114,   115,
     116,   117,   785,   231,   406,   407,   208,   785,   124,   235,
     785,     5,   785,   235,   235,   210,   235,   139,   235,   235,
     803,   231,   214,   215,   216,   217,   218,   219,   220,   232,
     208,   827,   231,   231,   799,   235,   228,   229,   214,   831,
     401,   235,   425,   839,   235,   447,   448,   449,   450,   451,
     452,   453,   174,   836,   170,   235,   210,   853,   235,   175,
     210,   231,   231,   320,   344,   187,   231,   859,   859,   865,
     234,   231,   231,   235,   870,   231,   859,   566,   907,   532,
     655,   859,   538,   701,   859,   715,   859,   786,   391,   255,
     588,   213,   340,   865,   216,   217,   218,    94,   711,   221,
     222,   709,    -1,   895,   707,   412,    -1,    -1,    -1,    -1,
      -1,    -1,   234,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    -1,    -1,    -1,   209,   548,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,    -1,
      -1,   235,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   600,   601,
      -1,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,   613,   614,   615,   616,   617,   618,   619,    41,   621,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,   630,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    75,   655,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    87,    88,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   124,    -1,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,   139,    -1,    -1,    -1,
      -1,    -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,   162,
      -1,    -1,    -1,    -1,   228,   229,   169,   170,   171,    -1,
      -1,   174,   175,    -1,    -1,   178,    -1,    -1,   181,    -1,
      -1,    -1,    -1,    -1,   187,    -1,    -1,   190,    -1,   192,
      -1,    -1,     3,     4,     5,    -1,    -1,   200,   201,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     213,    -1,    -1,   216,   217,   218,    -1,    -1,   221,   222,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      41,   234,    43,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   830,    60,
      -1,    62,   834,   213,   214,   215,   216,   217,   218,   219,
     220,    72,    -1,    -1,    75,    -1,    -1,    -1,   228,   229,
      81,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      91,   863,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,    -1,
      -1,   112,    -1,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
     131,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    35,    -1,   168,   169,   170,
     171,    41,    -1,    43,   175,    -1,    -1,   178,    48,    49,
     181,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,   190,
      60,   192,    62,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    72,    -1,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    81,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,
      -1,    91,    -1,    -1,    94,    -1,    -1,    -1,   229,    -1,
      -1,   101,   233,    -1,    -1,    -1,    -1,    -1,   108,   109,
      -1,    -1,   112,    -1,   114,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,   124,    -1,    -1,     3,     4,     5,
      -1,   131,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      -1,    -1,   162,    -1,    -1,    41,    -1,    43,   168,   169,
     170,   171,    48,    49,    -1,   175,    -1,    53,   178,    -1,
      -1,   181,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
     190,    -1,   192,    -1,    -1,    -1,    72,    -1,    -1,    75,
     200,   201,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,
      -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,    -1,    -1,    -1,   101,    -1,    -1,    -1,   229,
      -1,    -1,   108,   233,    -1,    -1,   112,    -1,   114,   115,
     116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,     3,     4,     5,    -1,   131,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    41,
      -1,    43,   168,   169,   170,   171,    48,    -1,    -1,   175,
      -1,    53,   178,    -1,    -1,   181,    -1,    -1,    60,    -1,
      -1,    -1,    -1,    -1,   190,    -1,   192,    -1,    -1,    -1,
      -1,    -1,    -1,    75,   200,   201,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,   101,
      -1,    -1,    -1,   229,    -1,    -1,   108,   233,    -1,    -1,
     112,    -1,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    41,    -1,    43,    -1,   169,   170,   171,
      48,    -1,    -1,   175,    -1,    53,   178,    -1,    -1,   181,
      -1,    -1,    60,    -1,    -1,    -1,    -1,    -1,   190,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    75,   200,   201,
      -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,    87,
      -1,    -1,    -1,    91,    -1,    -1,    94,     3,    -1,     5,
      -1,    -1,    -1,   101,    -1,    -1,    -1,   229,    -1,    -1,
     108,   233,    -1,    -1,   112,    -1,   114,   115,   116,   117,
      -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    53,    -1,    -1,
      -1,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    75,
      -1,   169,   170,   171,    -1,    81,    82,   175,    -1,    -1,
     178,    87,    -1,   181,    -1,    91,    -1,    -1,    94,    -1,
      -1,    -1,   190,    -1,   192,   101,    -1,    -1,    -1,    -1,
      -1,    -1,   200,   201,    -1,    -1,   112,    -1,   114,   115,
     116,   117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,
      -1,    -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,
       5,   229,    -1,    -1,    -1,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    18,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      35,    -1,    -1,   169,   170,   171,    41,    -1,    43,   175,
      -1,    -1,   178,    48,    49,   181,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,   190,    60,   192,    62,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,    -1,    72,    -1,    -1,
      75,    -1,    -1,    -1,    -1,    -1,    81,    82,    -1,    -1,
      -1,    -1,    87,    -1,    -1,    -1,    91,    -1,    -1,    94,
      -1,    -1,    -1,   229,    -1,    -1,   101,   233,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,   112,    -1,   114,
     115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,   124,
      -1,    -1,     3,     4,     5,    -1,   131,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   149,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,   162,    -1,    -1,
      41,    -1,    43,   168,   169,   170,   171,    48,    49,    -1,
     175,    -1,    53,   178,    -1,    -1,   181,    -1,    -1,    60,
      -1,    62,    -1,    -1,    -1,   190,    -1,   192,    -1,    -1,
      -1,    72,    -1,    -1,    75,   200,   201,    -1,    -1,    -1,
      81,    82,    -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
     101,    -1,    -1,    -1,   229,    -1,    -1,   108,   109,    -1,
      -1,   112,    -1,   114,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,     3,    -1,     5,    -1,
     131,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   149,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    41,    -1,    43,   168,   169,   170,
     171,    48,    -1,    -1,   175,    -1,    53,   178,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,
      -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    75,   200,
     201,    -1,    -1,    -1,    81,    82,    -1,    -1,    -1,    -1,
      87,    -1,    -1,    -1,    91,    -1,    -1,    94,    -1,    -1,
      -1,    -1,    -1,     3,   101,     5,    -1,    -1,   229,    -1,
      -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,   116,
     117,    -1,    -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,     3,    48,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,
      -1,    -1,   169,   170,   171,    75,    -1,    -1,   175,    -1,
      -1,   178,    82,    -1,   181,    41,    -1,    43,    -1,    -1,
      -1,    91,    48,   190,    94,   192,    -1,    53,    -1,    -1,
      -1,   101,    -1,   200,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   114,   115,   116,   117,    -1,    75,
      -1,   218,    -1,    -1,   124,    81,    82,    -1,    -1,    -1,
      -1,    87,   229,    -1,    -1,    91,    -1,    -1,    94,     3,
      -1,     5,    -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   112,    -1,   114,   115,
     116,   117,    -1,    -1,    28,    -1,    -1,    -1,   124,    -1,
     170,   171,    -1,    -1,    -1,   175,    -1,    41,    -1,    43,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    53,
      -1,    -1,   192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   201,    -1,    -1,    -1,    -1,   162,    -1,    -1,    -1,
      -1,    75,    -1,   169,   170,   171,    -1,    81,    82,   175,
      -1,    -1,   178,    87,    -1,   181,    -1,    91,    -1,    -1,
      94,     3,    -1,     5,   190,    -1,   192,   101,    -1,    -1,
      -1,    -1,    -1,    -1,   200,   201,    -1,    -1,   112,    -1,
     114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,    -1,
     124,    -1,   218,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,   229,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    53,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,    -1,
      -1,    -1,    -1,    75,    -1,   169,   170,   171,    -1,    81,
      82,   175,    -1,    -1,   178,    87,    -1,   181,    -1,    91,
      -1,    -1,    94,    -1,    -1,    -1,   190,    -1,   192,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,    -1,
     112,    -1,   114,   115,   116,   117,    -1,    -1,    -1,    -1,
      -1,    -1,   124,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,   229,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
     162,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,   171,
      -1,    -1,    -1,   175,    -1,    -1,   178,    -1,    -1,   181,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   190,    -1,
     192,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   229,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      -1,    -1,   209,    -1,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   228,   229,    -1,    -1,    -1,    -1,    -1,   235,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,   209,    -1,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   220,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   228,   229,   230,   209,    -1,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,
     229,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   209,    -1,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     220,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   228,   229,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
       3,    -1,     5,    -1,    -1,    -1,    -1,   228,   229,   212,
     213,   214,   215,   216,   217,   218,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   229,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,
      -1,    -1,    75,    -1,    -1,    -1,    -1,    -1,    81,    82,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,     3,    -1,     5,     6,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   114,   115,   116,   117,   118,    -1,    -1,   121,    -1,
      -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,    75,   168,   169,   170,   171,    -1,
      81,    82,   175,    -1,    -1,   178,    87,    -1,   181,    -1,
      91,    -1,    -1,    94,     3,    -1,     5,   190,    -1,   192,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,   112,    -1,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   162,    -1,    -1,    -1,    -1,    75,    -1,   169,   170,
     171,    -1,    81,    82,   175,    -1,    -1,   178,    87,    -1,
     181,    -1,    91,    -1,    -1,    94,     3,    -1,     5,   190,
      -1,   192,   101,    -1,    -1,    -1,    -1,    -1,    -1,   200,
     201,    -1,    -1,   112,    -1,   114,   115,   116,   117,    -1,
      -1,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,
      -1,    48,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   162,    -1,    -1,    -1,    -1,    75,    -1,
     169,   170,   171,    -1,    81,    82,   175,    -1,    41,   178,
      43,    -1,   181,    -1,    91,    48,    -1,    94,    -1,    -1,
      53,   190,    -1,   192,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   200,   201,    -1,    -1,    -1,    -1,   114,   115,   116,
     117,    -1,    75,    -1,    -1,    -1,    -1,   124,    81,    82,
      -1,    -1,    -1,    -1,    87,    -1,    -1,    -1,    91,    -1,
      -1,    94,    -1,    -1,     5,    -1,    -1,    -1,   101,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   112,
      -1,   114,   115,   116,   117,    -1,    -1,    -1,    -1,    -1,
      -1,   124,   169,   170,   171,    -1,    -1,    -1,   175,    -1,
      41,    -1,    43,    -1,   181,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    -1,   190,    -1,   192,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   200,   201,    -1,    -1,    -1,    -1,   162,
      -1,    -1,    -1,    -1,    75,    -1,   169,   170,   171,    -1,
      81,    82,   175,    -1,    -1,   178,    -1,    -1,   181,    -1,
      91,    -1,    -1,    94,    -1,    -1,    -1,   190,    -1,   192,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   200,   201,    -1,
      -1,    -1,    -1,   114,   115,   116,   117,    -1,    -1,    -1,
      -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,   170,
     171,    -1,    -1,    -1,   175,    -1,    -1,    -1,    -1,    -1,
     181,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,   190,
      34,   192,    36,    37,    38,    39,    40,    -1,    42,   200,
     201,    45,    -1,    47,    -1,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    -1,    73,
      -1,    -1,    76,    77,    78,    79,    80,    -1,    -1,    83,
      84,    85,    86,    -1,    -1,    89,    90,    -1,    92,    93,
      -1,    95,    96,    97,    98,    99,   100,    -1,   102,   103,
     104,   105,   106,   107,    -1,    -1,   110,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,   119,   120,    -1,   122,   123,
      -1,   125,   126,   127,    -1,    -1,    -1,    -1,   132,   133,
     134,    -1,   136,   137,   138,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,    -1,   150,    -1,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,    -1,   163,
     164,    -1,   166,   167,    -1,    -1,    -1,    -1,    -1,   173,
      -1,    -1,   176,    -1,   178,   179,   180,    -1,    -1,   183,
     184,   185,   186,    -1,    -1,   189,    -1,   191,    -1,   193,
     194,   195,   196,   197,   198,   199,    -1,    -1,   202
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   238,   244,     0,     3,     4,     5,    18,    35,    41,
      43,    48,    49,    53,    60,    62,    72,    75,    81,    82,
      87,    91,    94,   101,   108,   112,   114,   115,   116,   117,
     118,   124,   131,   149,   162,   168,   169,   170,   171,   175,
     178,   181,   190,   192,   200,   201,   229,   239,   241,   250,
     251,   253,   254,   255,   256,   259,   260,   266,   267,   285,
     299,   302,   304,   306,   307,   308,   309,   312,   313,   314,
     315,   316,   317,   318,   321,   322,   325,   329,   332,   337,
     342,   343,   344,   345,   347,   350,   368,   369,   370,   371,
     372,   228,   229,   374,   377,   378,     3,     5,   302,   302,
     234,   232,   302,     3,   301,   302,   114,   305,     9,   302,
     305,     3,   234,   302,   234,   305,   306,     3,   301,     3,
     301,   306,    29,    30,    34,    36,    37,    38,    39,    40,
      42,    45,    47,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    61,    63,    64,    65,    67,    68,    69,    70,
      71,    73,    76,    77,    78,    79,    80,    83,    84,    85,
      86,    89,    90,    92,    93,    95,    96,    97,    98,    99,
     100,   102,   103,   104,   105,   106,   107,   110,   113,   119,
     120,   122,   123,   125,   126,   127,   132,   133,   134,   136,
     137,   138,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   150,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   163,   164,   166,   167,   173,   176,   178,   179,
     180,   183,   184,   185,   186,   189,   191,   193,   194,   195,
     196,   197,   198,   199,   202,   268,   277,   367,   231,   246,
     246,    66,   129,   188,   341,    81,   121,   181,   190,   258,
     285,   312,   314,   316,   329,   347,   368,   372,   231,     3,
     302,   214,   231,   231,   231,   228,   232,   231,   321,   231,
     249,   231,   349,   350,   349,   349,    12,    13,    14,    15,
     218,   234,   278,   302,   303,   351,   352,   365,   285,   368,
     370,   372,   349,   231,    33,    63,    78,    86,   379,   380,
     374,   118,     9,   240,   232,   231,   214,     3,    64,   370,
     232,   182,   232,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   208,   230,    17,    62,   109,
     243,   250,   257,   260,   312,   313,   314,   315,   316,   317,
     318,   321,   329,   332,   337,   342,   233,   370,   302,   266,
     267,   232,     3,   302,     3,     3,   232,   232,   210,   326,
     232,   338,   365,   228,   304,   307,   308,   309,   310,   311,
       3,   245,   232,   346,   351,   351,   236,   229,   234,   265,
     349,   234,   208,   230,     5,   235,   118,   233,   266,   281,
     282,   283,   284,   330,   210,   210,   235,   292,   234,   295,
     272,   274,   347,     9,    16,   303,     3,     6,     7,     8,
       9,    10,    11,    88,   139,   174,   187,   213,   216,   217,
     218,   221,   222,   234,   288,   289,   290,   276,   347,   272,
     347,     6,   271,    16,   288,   291,     9,     9,   269,   291,
     347,   290,     9,     9,   290,     9,   290,   288,   264,   267,
     347,   290,   286,   287,   288,    31,   135,   177,   270,     9,
       9,   367,     9,   290,   370,   286,   273,   347,   288,   370,
     130,   203,   204,   205,   206,   207,   366,   370,   370,    16,
       6,     7,   373,     9,   370,   277,   229,   232,   234,   231,
     231,   231,   232,   231,   231,   249,   303,   347,   248,   319,
     308,   309,   232,   233,   326,   302,   218,   218,   208,   215,
     244,   151,   323,   329,   345,   351,   235,   291,   218,   230,
     288,   261,   262,   263,   264,    32,    74,   172,   206,   381,
     382,   380,   232,   308,   303,   233,   208,   236,   302,   327,
     328,     6,   252,   252,   233,   266,   293,   266,   297,   233,
     267,   294,   297,   235,   208,   235,   235,   235,   234,   288,
     288,   288,   288,   288,   288,     5,   288,   348,   350,   369,
      19,    20,    21,    22,    23,    24,    25,    26,    27,   209,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     228,   229,   208,   235,   235,   208,   235,   208,   228,   235,
     208,   235,   235,   208,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   347,   218,   234,   265,   278,
     303,   357,   359,   360,   235,   208,   235,   235,   235,   235,
     235,   235,   208,   235,   235,   235,   208,   235,   235,   235,
     235,   235,   235,   228,   235,   235,   235,   277,   242,     9,
     247,   214,   234,   351,   361,   233,   250,   266,   267,   233,
     266,   320,   319,   249,   165,   336,   310,   233,   210,   128,
     297,   324,   231,   230,   230,   235,   208,   208,   235,   188,
     375,   376,   214,   284,   290,   208,   331,     6,   235,   235,
     347,   372,   347,   368,   235,   231,   231,   271,   272,   348,
     235,   218,   234,   265,   278,   353,   355,   356,   369,   349,
     288,   288,     3,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
       3,   288,   290,   155,   158,   275,     6,   291,     9,   359,
     346,   218,   261,   278,   358,   359,   234,   265,   287,   290,
     272,     6,   118,   233,   235,   246,   333,   261,   208,   249,
     249,    72,   118,   339,   340,   233,   308,   309,   335,   232,
     210,   231,   233,   267,   298,   299,   233,    28,   264,   382,
     378,   233,   375,   311,   327,   215,   357,   363,   364,   231,
     351,   300,   303,   355,   346,   218,   261,   278,   354,   355,
     235,   234,   265,   349,   210,   230,   208,   235,   359,   346,
     235,   359,   235,   261,   235,   308,   249,   233,   328,   235,
     351,   302,   302,   307,   309,   231,   231,   249,   208,   248,
     231,     5,   215,   210,   362,   208,   231,   232,   235,   355,
     346,   235,   359,   235,   288,   261,   288,   272,   359,   235,
     214,   215,   249,   302,   308,   309,   233,   231,   231,   291,
     363,   279,   359,   235,   311,   234,   249,    47,    64,   233,
     280,   215,   261,   290,   210,   231,   235,   210,   231,   296,
     297,   334,   296,   231,   249
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   237,   238,   239,   239,   240,   240,   241,   242,   242,
     243,   244,   245,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   246,   246,
     246,   247,   246,   246,   246,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   248,   248,   249,   249,
     250,   250,   250,   250,   250,   250,   250,   251,   251,   252,
     252,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   261,   262,
     262,   263,   263,   264,   264,   265,   265,   265,   266,   266,
     267,   268,   268,   268,   269,   269,   270,   270,   270,   271,
     271,   272,   273,   274,   274,   275,   275,   276,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   278,   278,   278,   278,   279,   279,   280,   280,   281,
     281,   281,   282,   282,   283,   284,   284,   285,   286,   286,
     287,   287,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   288,   288,   288,   288,   288,   288,   288,
     288,   288,   288,   289,   289,   290,   291,   292,   292,   293,
     293,   294,   294,   295,   295,   296,   296,   297,   297,   298,
     299,   299,   300,   300,   301,   301,   302,   302,   303,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   304,
     305,   305,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   307,   307,   308,   308,   309,   310,   310,   310,   310,
     310,   311,   311,   312,   313,   314,   315,   316,   317,   318,
     318,   319,   319,   320,   320,   321,   322,   323,   323,   324,
     324,   325,   325,   326,   326,   326,   327,   328,   328,   329,
     330,   331,   329,   332,   333,   334,   332,   335,   335,   335,
     335,   336,   336,   338,   337,   337,   339,   339,   339,   340,
     341,   342,   343,   343,   343,   344,   345,   346,   346,   347,
     347,   348,   348,   349,   349,   350,   350,   350,   351,   351,
     351,   352,   352,   352,   352,   353,   353,   353,   354,   354,
     355,   355,   356,   356,   356,   356,   356,   357,   357,   357,
     358,   358,   359,   359,   360,   360,   360,   360,   360,   360,
     361,   361,   362,   362,   363,   364,   364,   365,   365,   366,
     366,   366,   366,   366,   366,   367,   367,   367,   368,   369,
     369,   369,   369,   369,   369,   369,   369,   369,   369,   370,
     370,   370,   371,   372,   372,   373,   373,   373,   374,   374,
     375,   375,   376,   377,   378,   378,   379,   379,   380,   380,
     380,   380,   381,   381,   382,   382,   382,   382
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
       3,     3,     3,     3,     1,     1,     1,     5,     0,     4,
       1,     4,     1,     1,     1,     1,     1,     4,     4,     1,
       4,     1,     1,     1,     1,     4,     4,     1,     6,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     1,     1,
       1,     4,     4,     1,     1,     4,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     1,     4,     1,     1,
       4,     1,     4,     1,     1,     4,     4,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     4,     1,     4,     4,     1,
       1,     1,     1,     1,     1,     6,     1,     4,     1,     1,
       1,     4,     1,     4,     1,     1,     4,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     4,     4,     4,
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
       1,     2,     3,     1,     2,     4,     1,     1,     2,     1,
       2,     1,     3,     2,     6,     2,     7,     2,     5,     2,
       3,     0,     2,     3,     3,     2,     1,     2,     3,     2,
       3,     6,     6,     0,     2,     2,     1,     1,     3,     2,
       0,     0,     7,     8,     0,     0,    13,     1,     1,     3,
       3,     0,     2,     0,     9,     2,     2,     3,     2,     2,
       2,     6,     1,     1,     1,     1,     1,     0,     2,     2,
       3,     2,     3,     0,     1,     2,     2,     2,     3,     2,
       1,     1,     3,     2,     4,     3,     2,     1,     3,     2,
       0,     1,     3,     2,     1,     3,     4,     3,     2,     1,
       3,     2,     0,     1,     1,     3,     2,     1,     3,     4,
       1,     3,     0,     2,     2,     1,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     2,     1,     2,     1,     2,     4,     1,     1,
       2,     1,     5,     5,    10,     1,     3,     1,     0,     2,
       0,     2,     4,     6,     0,     3,     1,     3,     4,     1,
       1,     1,     1,     3,     1,     1,     1,     1
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
#line 366 "tools/widl/parser.y"
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
#line 3560 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3566 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 389 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3574 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 394 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3580 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3586 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3592 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 404 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3598 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3604 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 409 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3610 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 410 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3616 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3622 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3628 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3634 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3640 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 415 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3648 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3656 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3662 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 422 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3669 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3675 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 425 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3682 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3688 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 428 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3694 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3700 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3706 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 434 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3712 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 435 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3718 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3724 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 437 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3730 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 438 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3736 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3742 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3748 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3754 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 442 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3762 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3768 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 446 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3775 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3781 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 449 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3788 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 451 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3794 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 452 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3800 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3806 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 454 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3812 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 455 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3818 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 459 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3824 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 460 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3830 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 469 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3836 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 470 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3842 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3848 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 472 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3854 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 473 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3860 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3866 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 475 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3872 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 479 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3884 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 487 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3893 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 494 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3899 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 495 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM aIDENTIFIER  */
#line 500 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3917 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION aIDENTIFIER  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3923 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3929 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 506 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3935 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3941 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 510 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 513 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); push_import( (yyvsp[-1].str), &yylloc ); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 515 "tools/widl/parser.y"
                                                { pop_import( &yylloc ); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 519 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3965 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 522 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3971 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3979 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 529 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3985 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 533 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3991 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 537 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3997 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 538 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 4003 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(xstrdup("...")) ); }
#line 4009 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 546 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4019 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 551 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4029 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 4038 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4044 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4050 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 4056 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 4062 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 575 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 4068 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 576 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 4074 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 4080 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 4086 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 4092 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 4098 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 4104 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 4110 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 4116 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 4122 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 596 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 4132 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 604 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4141 "tools/widl/parser.tab.c"
    break;

  case 103: /* activatable_attr: decl_spec ',' contract_req  */
#line 611 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4150 "tools/widl/parser.tab.c"
    break;

  case 104: /* activatable_attr: contract_req  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 4156 "tools/widl/parser.tab.c"
    break;

  case 105: /* access_attr: tPUBLIC  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4162 "tools/widl/parser.tab.c"
    break;

  case 106: /* access_attr: tPROTECTED  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4168 "tools/widl/parser.tab.c"
    break;

  case 107: /* composable_attr: decl_spec ',' access_attr ',' contract_req  */
#line 625 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].declspec)->type->type_type != TYPE_INTERFACE)
                                                      error_loc( "type %s is not an interface\n", (yyvsp[-4].declspec)->type->name );
                                                  (yyval.expr) = make_exprt( EXPR_MEMBER, declare_var( append_attr( NULL, (yyvsp[-2].attr) ), (yyvsp[-4].declspec), make_declarator( NULL ), 0 ), (yyvsp[0].expr) );
                                                }
#line 4177 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: %empty  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 4183 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tACTIVATABLE '(' activatable_attr ')'  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ACTIVATABLE, (yyvsp[-1].expr) ); }
#line 4189 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tAGGREGATABLE  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AGGREGATABLE, 0 ); }
#line 4195 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ANNOTATION, (yyvsp[-1].str) ); }
#line 4201 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tAPPOBJECT  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_APPOBJECT, 0 ); }
#line 4207 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tASYNC  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ASYNC, 0 ); }
#line 4213 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tAUTOHANDLE  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AUTO_HANDLE, 0 ); }
#line 4219 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tBINDABLE  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BINDABLE, 0 ); }
#line 4225 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tBROADCAST  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BROADCAST, 0 ); }
#line 4231 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCALLAS '(' ident ')'  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CALLAS, (yyvsp[-1].var) ); }
#line 4237 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CASE, (yyvsp[-1].expr_list) ); }
#line 4243 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCODE  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CODE, 0 ); }
#line 4249 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCOMPOSABLE '(' composable_attr ')'  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_COMPOSABLE, (yyvsp[-1].expr) ); }
#line 4255 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCOMMSTATUS  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_COMMSTATUS, 0 ); }
#line 4261 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCONTEXTHANDLE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); }
#line 4267 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4273 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4279 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CONTRACT, (yyvsp[-1].expr) ); }
#line 4285 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTRACTVERSION, (yyvsp[-1].num) ); }
#line 4291 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tCONTROL  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTROL, 0 ); }
#line 4297 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tCUSTOM '(' aUUID ',' expr_const ')'  */
#line 652 "tools/widl/parser.y"
                                                { attr_custdata_t *data = xmalloc( sizeof(*data) );
                                                  data->id = *(yyvsp[-3].uuid); data->pval = (yyvsp[-1].expr);
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_CUSTOM, data );
                                                }
#line 4306 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tDECODE  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 4312 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDEFAULT  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULT, 0 ); }
#line 4318 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDEFAULTBIND  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTBIND, 0 ); }
#line 4324 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDEFAULTCOLLELEM  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTCOLLELEM, 0 ); }
#line 4330 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DEFAULTVALUE, (yyvsp[-1].expr) ); }
#line 4336 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tDEFAULTVTABLE  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTVTABLE, 0 ); }
#line 4342 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISABLECONSISTENCYCHECK, 0 ); }
#line 4348 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tDISPLAYBIND  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISPLAYBIND, 0 ); }
#line 4354 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DLLNAME, (yyvsp[-1].str) ); }
#line 4360 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tDUAL  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DUAL, 0 ); }
#line 4366 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tENABLEALLOCATE  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENABLEALLOCATE, 0 ); }
#line 4372 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tENCODE  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 4378 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tENDPOINT '(' str_list ')'  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENDPOINT, (yyvsp[-1].str_list) ); }
#line 4384 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tENTRY '(' expr_const ')'  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENTRY, (yyvsp[-1].expr) ); }
#line 4390 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tEVENTADD  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTADD, 0 ); }
#line 4396 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tEVENTREMOVE  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTREMOVE, 0 ); }
#line 4402 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 672 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
                                                      error_loc( "type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type );
                                                }
#line 4411 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tEXPLICITHANDLE  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 4417 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tFAULTSTATUS  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FAULTSTATUS, 0 ); }
#line 4423 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tFLAGS  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FLAGS, 0 ); }
#line 4429 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tFORCEALLOCATE  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FORCEALLOCATE, 0 ); }
#line 4435 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tHANDLE  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HANDLE, 0 ); }
#line 4441 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPCONTEXT, (yyvsp[-1].expr) ); }
#line 4447 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPFILE, (yyvsp[-1].str) ); }
#line 4453 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRING, (yyvsp[-1].str) ); }
#line 4459 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr) ); }
#line 4465 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGDLL, (yyvsp[-1].str) ); }
#line 4471 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tHIDDEN  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HIDDEN, 0 ); }
#line 4477 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tID '(' expr_int_const ')'  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ID, (yyvsp[-1].expr) ); }
#line 4483 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tIDEMPOTENT  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IDEMPOTENT, 0 ); }
#line 4489 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tIGNORE  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IGNORE, 0 ); }
#line 4495 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tIIDIS '(' expr ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IIDIS, (yyvsp[-1].expr) ); }
#line 4501 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tIMMEDIATEBIND  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IMMEDIATEBIND, 0 ); }
#line 4507 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var) ); }
#line 4513 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tIN  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IN, 0 ); }
#line 4519 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tINPUTSYNC  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_INPUTSYNC, 0 ); }
#line 4525 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LENGTHIS, (yyvsp[-1].expr_list) ); }
#line 4531 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tLCID '(' expr_int_const ')'  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LIBLCID, (yyvsp[-1].expr) ); }
#line 4537 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tLCID  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARAMLCID, 0 ); }
#line 4543 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tLICENSED  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LICENSED, 0 ); }
#line 4549 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tLOCAL  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LOCAL, 0 ); }
#line 4555 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num) ); }
#line 4561 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tMAYBE  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MAYBE, 0 ); }
#line 4567 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tMESSAGE  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MESSAGE, 0 ); }
#line 4573 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tNOCODE  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOCODE, 0 ); }
#line 4579 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tNONBROWSABLE  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONBROWSABLE, 0 ); }
#line 4585 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tNONCREATABLE  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONCREATABLE, 0 ); }
#line 4591 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tNONEXTENSIBLE  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONEXTENSIBLE, 0 ); }
#line 4597 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tNOTIFY  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFY, 0 ); }
#line 4603 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tNOTIFYFLAG  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFYFLAG, 0 ); }
#line 4609 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tOBJECT  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OBJECT, 0 ); }
#line 4615 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tODL  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ODL, 0 ); }
#line 4621 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tOLEAUTOMATION  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OLEAUTOMATION, 0 ); }
#line 4627 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OPTIMIZE, (yyvsp[-1].str) ); }
#line 4633 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tOPTIONAL  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OPTIONAL, 0 ); }
#line 4639 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tOUT  */
#line 716 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OUT, 0 ); }
#line 4645 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tOVERLOAD '(' aSTRING ')'  */
#line 717 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OVERLOAD, (yyvsp[-1].str) ); }
#line 4651 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tPARTIALIGNORE  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARTIALIGNORE, 0 ); }
#line 4657 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERDEFAULT, (yyvsp[-1].num) ); }
#line 4663 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tPROGID '(' aSTRING ')'  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_PROGID, (yyvsp[-1].str) ); }
#line 4669 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tPROPGET  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPGET, 0 ); }
#line 4675 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tPROPPUT  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUT, 0 ); }
#line 4681 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tPROPPUTREF  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUTREF, 0 ); }
#line 4687 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tPROTECTED  */
#line 724 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4693 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tPROXY  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROXY, 0 ); }
#line 4699 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tPUBLIC  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4705 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 728 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
                                                  list = append_expr( list, (yyvsp[-1].expr) );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_RANGE, list );
                                                }
#line 4714 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tREADONLY  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_READONLY, 0 ); }
#line 4720 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tREPRESENTAS '(' type ')'  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_REPRESENTAS, (yyvsp[-1].type) ); }
#line 4726 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tREQUESTEDIT  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_REQUESTEDIT, 0 ); }
#line 4732 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tRESTRICTED  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RESTRICTED, 0 ); }
#line 4738 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tRETVAL  */
#line 736 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RETVAL, 0 ); }
#line 4744 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 737 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SIZEIS, (yyvsp[-1].expr_list) ); }
#line 4750 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tSOURCE  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_SOURCE, 0 ); }
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tSTATIC '(' static_attr ')'  */
#line 739 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_STATIC, (yyvsp[-1].expr) ); }
#line 4762 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRICTCONTEXTHANDLE, 0 ); }
#line 4768 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tSTRING  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRING, 0 ); }
#line 4774 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tSWITCHIS '(' expr ')'  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHIS, (yyvsp[-1].expr) ); }
#line 4780 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHTYPE, (yyvsp[-1].type) ); }
#line 4786 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tTRANSMITAS '(' type ')'  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_TRANSMITAS, (yyvsp[-1].type) ); }
#line 4792 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tTHREADING '(' threading_type ')'  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_THREADING, (yyvsp[-1].num) ); }
#line 4798 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tUIDEFAULT  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_UIDEFAULT, 0 ); }
#line 4804 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tUSESGETLASTERROR  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_USESGETLASTERROR, 0 ); }
#line 4810 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_USERMARSHAL, (yyvsp[-1].type) ); }
#line 4816 "tools/widl/parser.tab.c"
    break;

  case 213: /* attribute: tUUID '(' aUUID ')'  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_UUID, (yyvsp[-1].uuid) ); }
#line 4822 "tools/widl/parser.tab.c"
    break;

  case 214: /* attribute: tASYNCUUID '(' aUUID ')'  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ASYNCUUID, (yyvsp[-1].uuid) ); }
#line 4828 "tools/widl/parser.tab.c"
    break;

  case 215: /* attribute: tV1ENUM  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_V1ENUM, 0 ); }
#line 4834 "tools/widl/parser.tab.c"
    break;

  case 216: /* attribute: tVARARG  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VARARG, 0 ); }
#line 4840 "tools/widl/parser.tab.c"
    break;

  case 217: /* attribute: tVERSION '(' version ')'  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VERSION, (yyvsp[-1].num) ); }
#line 4846 "tools/widl/parser.tab.c"
    break;

  case 218: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_VIPROGID, (yyvsp[-1].str) ); }
#line 4852 "tools/widl/parser.tab.c"
    break;

  case 219: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_WIREMARSHAL, (yyvsp[-1].type) ); }
#line 4858 "tools/widl/parser.tab.c"
    break;

  case 220: /* attribute: pointer_type  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERTYPE, (yyvsp[0].num) ); }
#line 4864 "tools/widl/parser.tab.c"
    break;

  case 225: /* cases: %empty  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4870 "tools/widl/parser.tab.c"
    break;

  case 226: /* cases: cases case  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4876 "tools/widl/parser.tab.c"
    break;

  case 227: /* case: tCASE expr_int_const ':' union_field  */
#line 770 "tools/widl/parser.y"
                                                { attr_t *a = attr_ptr( (yyloc), ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ) );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4885 "tools/widl/parser.tab.c"
    break;

  case 228: /* case: tDEFAULT ':' union_field  */
#line 774 "tools/widl/parser.y"
                                                { attr_t *a = attr_int( (yyloc), ATTR_DEFAULT, 0 );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4894 "tools/widl/parser.tab.c"
    break;

  case 229: /* enums: %empty  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4900 "tools/widl/parser.tab.c"
    break;

  case 230: /* enums: enum_list ','  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4906 "tools/widl/parser.tab.c"
    break;

  case 232: /* enum_list: enum  */
#line 786 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4915 "tools/widl/parser.tab.c"
    break;

  case 233: /* enum_list: enum_list ',' enum  */
#line 790 "tools/widl/parser.y"
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
#line 4930 "tools/widl/parser.tab.c"
    break;

  case 234: /* enum_member: m_attributes ident  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 235: /* enum: enum_member '=' expr_int_const  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4947 "tools/widl/parser.tab.c"
    break;

  case 236: /* enum: enum_member  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4955 "tools/widl/parser.tab.c"
    break;

  case 237: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4961 "tools/widl/parser.tab.c"
    break;

  case 238: /* m_exprs: m_expr  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4967 "tools/widl/parser.tab.c"
    break;

  case 239: /* m_exprs: m_exprs ',' m_expr  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4973 "tools/widl/parser.tab.c"
    break;

  case 240: /* m_expr: %empty  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4979 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: aNUM  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4985 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: aHEXNUM  */
#line 829 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4991 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: aDOUBLE  */
#line 830 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4997 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: tFALSE  */
#line 831 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 5003 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: tNULL  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 5009 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: tTRUE  */
#line 833 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 5015 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: aSTRING  */
#line 834 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 5021 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: aWSTRING  */
#line 835 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 5027 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: aSQSTRING  */
#line 836 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 5033 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: aIDENTIFIER  */
#line 837 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 5039 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '?' expr ':' expr  */
#line 838 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5045 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr LOGICALOR expr  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5051 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr LOGICALAND expr  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5057 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr '|' expr  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5063 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr '^' expr  */
#line 842 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5069 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr '&' expr  */
#line 843 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5075 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr EQUALITY expr  */
#line 844 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5081 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr INEQUALITY expr  */
#line 845 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5087 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr '>' expr  */
#line 846 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5093 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '<' expr  */
#line 847 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5099 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr GREATEREQUAL expr  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5105 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr LESSEQUAL expr  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5111 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr SHL expr  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5117 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: expr SHR expr  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5123 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: expr '+' expr  */
#line 852 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5129 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr '-' expr  */
#line 853 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5135 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: expr '%' expr  */
#line 854 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5141 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: expr '*' expr  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5147 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: expr '/' expr  */
#line 856 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5153 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: '!' expr  */
#line 857 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 5159 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: '~' expr  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 5165 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: '+' expr  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 5171 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: '-' expr  */
#line 860 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 5177 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: '&' expr  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 5183 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '*' expr  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 5189 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5195 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr: expr '.' aIDENTIFIER  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5201 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5207 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5213 "tools/widl/parser.tab.c"
    break;

  case 281: /* expr: expr '[' expr ']'  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5219 "tools/widl/parser.tab.c"
    break;

  case 282: /* expr: '(' expr ')'  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5225 "tools/widl/parser.tab.c"
    break;

  case 283: /* expr_list_int_const: expr_int_const  */
#line 873 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5231 "tools/widl/parser.tab.c"
    break;

  case 284: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 874 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5237 "tools/widl/parser.tab.c"
    break;

  case 285: /* expr_int_const: expr  */
#line 877 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5246 "tools/widl/parser.tab.c"
    break;

  case 286: /* expr_const: expr  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5255 "tools/widl/parser.tab.c"
    break;

  case 287: /* fields: %empty  */
#line 890 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5261 "tools/widl/parser.tab.c"
    break;

  case 288: /* fields: fields field  */
#line 891 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5267 "tools/widl/parser.tab.c"
    break;

  case 289: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 895 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5276 "tools/widl/parser.tab.c"
    break;

  case 290: /* field: m_attributes uniondef ';'  */
#line 899 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5285 "tools/widl/parser.tab.c"
    break;

  case 291: /* ne_union_field: s_field ';'  */
#line 906 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5291 "tools/widl/parser.tab.c"
    break;

  case 292: /* ne_union_field: attributes ';'  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5297 "tools/widl/parser.tab.c"
    break;

  case 293: /* ne_union_fields: %empty  */
#line 911 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5303 "tools/widl/parser.tab.c"
    break;

  case 294: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5309 "tools/widl/parser.tab.c"
    break;

  case 295: /* union_field: s_field ';'  */
#line 916 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5315 "tools/widl/parser.tab.c"
    break;

  case 296: /* union_field: ';'  */
#line 917 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5321 "tools/widl/parser.tab.c"
    break;

  case 297: /* s_field: m_attributes decl_spec declarator  */
#line 920 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5330 "tools/widl/parser.tab.c"
    break;

  case 298: /* s_field: m_attributes structdef  */
#line 924 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5339 "tools/widl/parser.tab.c"
    break;

  case 299: /* funcdef: declaration  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5349 "tools/widl/parser.tab.c"
    break;

  case 300: /* declaration: attributes decl_spec init_declarator  */
#line 939 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5357 "tools/widl/parser.tab.c"
    break;

  case 301: /* declaration: decl_spec init_declarator  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5365 "tools/widl/parser.tab.c"
    break;

  case 302: /* m_ident: %empty  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5371 "tools/widl/parser.tab.c"
    break;

  case 304: /* m_typename: %empty  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5377 "tools/widl/parser.tab.c"
    break;

  case 308: /* ident: typename  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5383 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tBYTE  */
#line 964 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "byte" ); }
#line 5389 "tools/widl/parser.tab.c"
    break;

  case 310: /* base_type: tWCHAR  */
#line 965 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "wchar_t" ); }
#line 5395 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tSIGNED int_std  */
#line 967 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5401 "tools/widl/parser.tab.c"
    break;

  case 313: /* base_type: tUNSIGNED int_std  */
#line 968 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5407 "tools/widl/parser.tab.c"
    break;

  case 314: /* base_type: tUNSIGNED  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5413 "tools/widl/parser.tab.c"
    break;

  case 315: /* base_type: tFLOAT  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "float" ); }
#line 5419 "tools/widl/parser.tab.c"
    break;

  case 316: /* base_type: tDOUBLE  */
#line 971 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "double" ); }
#line 5425 "tools/widl/parser.tab.c"
    break;

  case 317: /* base_type: tBOOLEAN  */
#line 972 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "boolean" ); }
#line 5431 "tools/widl/parser.tab.c"
    break;

  case 318: /* base_type: tERRORSTATUST  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "error_status_t" ); }
#line 5437 "tools/widl/parser.tab.c"
    break;

  case 319: /* base_type: tHANDLET  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "handle_t" ); }
#line 5443 "tools/widl/parser.tab.c"
    break;

  case 322: /* int_std: tINT  */
#line 982 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5449 "tools/widl/parser.tab.c"
    break;

  case 323: /* int_std: tSHORT m_int  */
#line 983 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5455 "tools/widl/parser.tab.c"
    break;

  case 324: /* int_std: tSMALL  */
#line 984 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5461 "tools/widl/parser.tab.c"
    break;

  case 325: /* int_std: tLONG m_int  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5467 "tools/widl/parser.tab.c"
    break;

  case 326: /* int_std: tHYPER m_int  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5473 "tools/widl/parser.tab.c"
    break;

  case 327: /* int_std: tINT64  */
#line 987 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5479 "tools/widl/parser.tab.c"
    break;

  case 328: /* int_std: tCHAR  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5485 "tools/widl/parser.tab.c"
    break;

  case 329: /* int_std: tINT32  */
#line 989 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5491 "tools/widl/parser.tab.c"
    break;

  case 330: /* int_std: tINT3264  */
#line 990 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5497 "tools/widl/parser.tab.c"
    break;

  case 331: /* namespace_pfx: aIDENTIFIER '.'  */
#line 994 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5503 "tools/widl/parser.tab.c"
    break;

  case 332: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5509 "tools/widl/parser.tab.c"
    break;

  case 333: /* qualified_type: typename  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5515 "tools/widl/parser.tab.c"
    break;

  case 334: /* qualified_type: namespace_pfx typename  */
#line 1000 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5521 "tools/widl/parser.tab.c"
    break;

  case 335: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 1004 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5527 "tools/widl/parser.tab.c"
    break;

  case 336: /* parameterized_type_arg: base_type  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5533 "tools/widl/parser.tab.c"
    break;

  case 337: /* parameterized_type_arg: qualified_type  */
#line 1009 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5539 "tools/widl/parser.tab.c"
    break;

  case 338: /* parameterized_type_arg: qualified_type '*'  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5545 "tools/widl/parser.tab.c"
    break;

  case 339: /* parameterized_type_arg: parameterized_type  */
#line 1011 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5551 "tools/widl/parser.tab.c"
    break;

  case 340: /* parameterized_type_arg: parameterized_type '*'  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5557 "tools/widl/parser.tab.c"
    break;

  case 341: /* parameterized_type_args: parameterized_type_arg  */
#line 1016 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5563 "tools/widl/parser.tab.c"
    break;

  case 342: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5569 "tools/widl/parser.tab.c"
    break;

  case 343: /* coclass: tCOCLASS typename  */
#line 1021 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5575 "tools/widl/parser.tab.c"
    break;

  case 344: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5581 "tools/widl/parser.tab.c"
    break;

  case 345: /* runtimeclass: tRUNTIMECLASS typename  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5587 "tools/widl/parser.tab.c"
    break;

  case 346: /* runtimeclass_def: attributes runtimeclass inherit '{' class_interfaces '}' semicolon_opt  */
#line 1032 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].type) && type_get_type((yyvsp[-4].type)) != TYPE_RUNTIMECLASS) error_loc("%s is not a runtimeclass\n", (yyvsp[-4].type)->name);
						  (yyval.type) = type_runtimeclass_define((yyvsp[-5].type), (yyvsp[-6].attr_list), (yyvsp[-2].typeref_list)); }
#line 5594 "tools/widl/parser.tab.c"
    break;

  case 347: /* apicontract: tAPICONTRACT typename  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5600 "tools/widl/parser.tab.c"
    break;

  case 348: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 1040 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5606 "tools/widl/parser.tab.c"
    break;

  case 349: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 1043 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 5612 "tools/widl/parser.tab.c"
    break;

  case 350: /* namespacedef: namespacedef '.' aIDENTIFIER  */
#line 1044 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 5618 "tools/widl/parser.tab.c"
    break;

  case 351: /* class_interfaces: %empty  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5624 "tools/widl/parser.tab.c"
    break;

  case 352: /* class_interfaces: class_interfaces class_interface  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5630 "tools/widl/parser.tab.c"
    break;

  case 353: /* class_interface: m_attributes interfaceref ';'  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5636 "tools/widl/parser.tab.c"
    break;

  case 354: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 1054 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5642 "tools/widl/parser.tab.c"
    break;

  case 355: /* dispinterface: tDISPINTERFACE typename  */
#line 1057 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5648 "tools/widl/parser.tab.c"
    break;

  case 356: /* dispattributes: attributes  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[0].attr_list), attr_int( (yyloc), ATTR_DISPINTERFACE, 0 ) ); }
#line 5654 "tools/widl/parser.tab.c"
    break;

  case 357: /* dispint_props: tPROPERTIES ':'  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5660 "tools/widl/parser.tab.c"
    break;

  case 358: /* dispint_props: dispint_props s_field ';'  */
#line 1064 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5666 "tools/widl/parser.tab.c"
    break;

  case 359: /* dispint_meths: tMETHODS ':'  */
#line 1067 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5672 "tools/widl/parser.tab.c"
    break;

  case 360: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1068 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5678 "tools/widl/parser.tab.c"
    break;

  case 361: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1073 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5684 "tools/widl/parser.tab.c"
    break;

  case 362: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5690 "tools/widl/parser.tab.c"
    break;

  case 363: /* inherit: %empty  */
#line 1079 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5696 "tools/widl/parser.tab.c"
    break;

  case 364: /* inherit: ':' qualified_type  */
#line 1080 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5702 "tools/widl/parser.tab.c"
    break;

  case 365: /* inherit: ':' parameterized_type  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5708 "tools/widl/parser.tab.c"
    break;

  case 366: /* type_parameter: typename  */
#line 1084 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5714 "tools/widl/parser.tab.c"
    break;

  case 367: /* type_parameters: type_parameter  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5720 "tools/widl/parser.tab.c"
    break;

  case 368: /* type_parameters: type_parameters ',' type_parameter  */
#line 1089 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5726 "tools/widl/parser.tab.c"
    break;

  case 369: /* interface: tINTERFACE typename  */
#line 1093 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5732 "tools/widl/parser.tab.c"
    break;

  case 370: /* $@3: %empty  */
#line 1094 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5738 "tools/widl/parser.tab.c"
    break;

  case 371: /* $@4: %empty  */
#line 1094 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5744 "tools/widl/parser.tab.c"
    break;

  case 372: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1095 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5750 "tools/widl/parser.tab.c"
    break;

  case 373: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						}
#line 5758 "tools/widl/parser.tab.c"
    break;

  case 374: /* $@5: %empty  */
#line 1103 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5764 "tools/widl/parser.tab.c"
    break;

  case 375: /* $@6: %empty  */
#line 1104 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5770 "tools/widl/parser.tab.c"
    break;

  case 376: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))));
						}
#line 5778 "tools/widl/parser.tab.c"
    break;

  case 377: /* required_types: qualified_type  */
#line 1111 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5784 "tools/widl/parser.tab.c"
    break;

  case 378: /* required_types: parameterized_type  */
#line 1112 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5790 "tools/widl/parser.tab.c"
    break;

  case 379: /* required_types: required_types ',' qualified_type  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5796 "tools/widl/parser.tab.c"
    break;

  case 380: /* required_types: required_types ',' parameterized_type  */
#line 1114 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5802 "tools/widl/parser.tab.c"
    break;

  case 381: /* requires: %empty  */
#line 1118 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5808 "tools/widl/parser.tab.c"
    break;

  case 382: /* requires: tREQUIRES required_types  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5814 "tools/widl/parser.tab.c"
    break;

  case 383: /* $@7: %empty  */
#line 1122 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5820 "tools/widl/parser.tab.c"
    break;

  case 384: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1124 "tools/widl/parser.y"
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
#line 5836 "tools/widl/parser.tab.c"
    break;

  case 385: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1135 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5842 "tools/widl/parser.tab.c"
    break;

  case 386: /* interfaceref: tINTERFACE typename  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5848 "tools/widl/parser.tab.c"
    break;

  case 387: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1140 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5854 "tools/widl/parser.tab.c"
    break;

  case 388: /* interfaceref: tINTERFACE parameterized_type  */
#line 1141 "tools/widl/parser.y"
                                                { if (type_get_type(((yyval.type) = (yyvsp[0].type))) != TYPE_INTERFACE) error_loc("%s is not an interface\n", (yyval.type)->name); }
#line 5860 "tools/widl/parser.tab.c"
    break;

  case 389: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5866 "tools/widl/parser.tab.c"
    break;

  case 390: /* module: tMODULE typename  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5872 "tools/widl/parser.tab.c"
    break;

  case 391: /* moduledef: m_attributes module '{' int_statements '}' semicolon_opt  */
#line 1152 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5878 "tools/widl/parser.tab.c"
    break;

  case 392: /* storage_cls_spec: tEXTERN  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5884 "tools/widl/parser.tab.c"
    break;

  case 393: /* storage_cls_spec: tSTATIC  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5890 "tools/widl/parser.tab.c"
    break;

  case 394: /* storage_cls_spec: tREGISTER  */
#line 1158 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5896 "tools/widl/parser.tab.c"
    break;

  case 395: /* function_specifier: tINLINE  */
#line 1162 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5902 "tools/widl/parser.tab.c"
    break;

  case 396: /* type_qualifier: tCONST  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5908 "tools/widl/parser.tab.c"
    break;

  case 397: /* m_type_qual_list: %empty  */
#line 1170 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5914 "tools/widl/parser.tab.c"
    break;

  case 398: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1171 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5920 "tools/widl/parser.tab.c"
    break;

  case 399: /* decl_spec: type m_decl_spec_no_type  */
#line 1174 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5926 "tools/widl/parser.tab.c"
    break;

  case 400: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5932 "tools/widl/parser.tab.c"
    break;

  case 401: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5938 "tools/widl/parser.tab.c"
    break;

  case 402: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5944 "tools/widl/parser.tab.c"
    break;

  case 403: /* m_decl_spec_no_type: %empty  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5950 "tools/widl/parser.tab.c"
    break;

  case 405: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1191 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5956 "tools/widl/parser.tab.c"
    break;

  case 406: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1192 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5962 "tools/widl/parser.tab.c"
    break;

  case 407: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1193 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5968 "tools/widl/parser.tab.c"
    break;

  case 408: /* declarator: '*' m_type_qual_list declarator  */
#line 1198 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5974 "tools/widl/parser.tab.c"
    break;

  case 409: /* declarator: callconv declarator  */
#line 1199 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 5980 "tools/widl/parser.tab.c"
    break;

  case 411: /* direct_declarator: ident  */
#line 1204 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5986 "tools/widl/parser.tab.c"
    break;

  case 412: /* direct_declarator: '(' declarator ')'  */
#line 1205 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5992 "tools/widl/parser.tab.c"
    break;

  case 413: /* direct_declarator: direct_declarator array  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5998 "tools/widl/parser.tab.c"
    break;

  case 414: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1207 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 6004 "tools/widl/parser.tab.c"
    break;

  case 415: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1213 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6010 "tools/widl/parser.tab.c"
    break;

  case 416: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1214 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6016 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1221 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6022 "tools/widl/parser.tab.c"
    break;

  case 419: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6028 "tools/widl/parser.tab.c"
    break;

  case 420: /* m_abstract_declarator: %empty  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6034 "tools/widl/parser.tab.c"
    break;

  case 422: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1233 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6040 "tools/widl/parser.tab.c"
    break;

  case 423: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1234 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6046 "tools/widl/parser.tab.c"
    break;

  case 424: /* abstract_direct_declarator: array  */
#line 1235 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6052 "tools/widl/parser.tab.c"
    break;

  case 425: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1237 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6060 "tools/widl/parser.tab.c"
    break;

  case 426: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1241 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6068 "tools/widl/parser.tab.c"
    break;

  case 427: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1249 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6074 "tools/widl/parser.tab.c"
    break;

  case 428: /* any_declarator: callconv m_any_declarator  */
#line 1250 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6080 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1257 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6086 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1258 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6092 "tools/widl/parser.tab.c"
    break;

  case 432: /* m_any_declarator: %empty  */
#line 1263 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6098 "tools/widl/parser.tab.c"
    break;

  case 434: /* any_direct_declarator: ident  */
#line 1271 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 6104 "tools/widl/parser.tab.c"
    break;

  case 435: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1272 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6110 "tools/widl/parser.tab.c"
    break;

  case 436: /* any_direct_declarator: any_direct_declarator array  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6116 "tools/widl/parser.tab.c"
    break;

  case 437: /* any_direct_declarator: array  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6122 "tools/widl/parser.tab.c"
    break;

  case 438: /* any_direct_declarator: '(' m_args ')'  */
#line 1276 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6130 "tools/widl/parser.tab.c"
    break;

  case 439: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6138 "tools/widl/parser.tab.c"
    break;

  case 440: /* declarator_list: declarator  */
#line 1286 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6144 "tools/widl/parser.tab.c"
    break;

  case 441: /* declarator_list: declarator_list ',' declarator  */
#line 1287 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6150 "tools/widl/parser.tab.c"
    break;

  case 442: /* m_bitfield: %empty  */
#line 1291 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 6156 "tools/widl/parser.tab.c"
    break;

  case 443: /* m_bitfield: ':' expr_const  */
#line 1292 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 6162 "tools/widl/parser.tab.c"
    break;

  case 444: /* struct_declarator: any_declarator m_bitfield  */
#line 1295 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 6171 "tools/widl/parser.tab.c"
    break;

  case 445: /* struct_declarator_list: struct_declarator  */
#line 1302 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6177 "tools/widl/parser.tab.c"
    break;

  case 446: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1304 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6183 "tools/widl/parser.tab.c"
    break;

  case 447: /* init_declarator: declarator  */
#line 1308 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 6189 "tools/widl/parser.tab.c"
    break;

  case 448: /* init_declarator: declarator '=' expr_const  */
#line 1309 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 6195 "tools/widl/parser.tab.c"
    break;

  case 449: /* threading_type: tAPARTMENT  */
#line 1313 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 6201 "tools/widl/parser.tab.c"
    break;

  case 450: /* threading_type: tNEUTRAL  */
#line 1314 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6207 "tools/widl/parser.tab.c"
    break;

  case 451: /* threading_type: tSINGLE  */
#line 1315 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6213 "tools/widl/parser.tab.c"
    break;

  case 452: /* threading_type: tFREE  */
#line 1316 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6219 "tools/widl/parser.tab.c"
    break;

  case 453: /* threading_type: tBOTH  */
#line 1317 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6225 "tools/widl/parser.tab.c"
    break;

  case 454: /* threading_type: tMTA  */
#line 1318 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6231 "tools/widl/parser.tab.c"
    break;

  case 455: /* pointer_type: tREF  */
#line 1322 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6237 "tools/widl/parser.tab.c"
    break;

  case 456: /* pointer_type: tUNIQUE  */
#line 1323 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6243 "tools/widl/parser.tab.c"
    break;

  case 457: /* pointer_type: tPTR  */
#line 1324 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6249 "tools/widl/parser.tab.c"
    break;

  case 458: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1327 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6255 "tools/widl/parser.tab.c"
    break;

  case 459: /* unqualified_type: tVOID  */
#line 1331 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6261 "tools/widl/parser.tab.c"
    break;

  case 460: /* unqualified_type: base_type  */
#line 1332 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6267 "tools/widl/parser.tab.c"
    break;

  case 461: /* unqualified_type: enumdef  */
#line 1333 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6273 "tools/widl/parser.tab.c"
    break;

  case 462: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1334 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6279 "tools/widl/parser.tab.c"
    break;

  case 463: /* unqualified_type: structdef  */
#line 1335 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6285 "tools/widl/parser.tab.c"
    break;

  case 464: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1336 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6291 "tools/widl/parser.tab.c"
    break;

  case 465: /* unqualified_type: uniondef  */
#line 1337 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6297 "tools/widl/parser.tab.c"
    break;

  case 466: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1338 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6303 "tools/widl/parser.tab.c"
    break;

  case 467: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1339 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6309 "tools/widl/parser.tab.c"
    break;

  case 468: /* unqualified_type: aKNOWNTYPE  */
#line 1340 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6315 "tools/widl/parser.tab.c"
    break;

  case 470: /* type: namespace_pfx typename  */
#line 1345 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6321 "tools/widl/parser.tab.c"
    break;

  case 471: /* type: parameterized_type  */
#line 1346 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6327 "tools/widl/parser.tab.c"
    break;

  case 472: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1350 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs( (yyloc), (yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs( (yyvsp[-4].attr_list) ) );
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6336 "tools/widl/parser.tab.c"
    break;

  case 473: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1357 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6342 "tools/widl/parser.tab.c"
    break;

  case 474: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1360 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6348 "tools/widl/parser.tab.c"
    break;

  case 475: /* version: aNUM  */
#line 1364 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6354 "tools/widl/parser.tab.c"
    break;

  case 476: /* version: aNUM '.' aNUM  */
#line 1365 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6360 "tools/widl/parser.tab.c"
    break;

  case 477: /* version: aHEXNUM  */
#line 1366 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6366 "tools/widl/parser.tab.c"
    break;

  case 482: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1381 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6374 "tools/widl/parser.tab.c"
    break;

  case 483: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1388 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6384 "tools/widl/parser.tab.c"
    break;

  case 484: /* acf_attributes: %empty  */
#line 1396 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6390 "tools/widl/parser.tab.c"
    break;

  case 485: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1397 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6396 "tools/widl/parser.tab.c"
    break;

  case 486: /* acf_attribute_list: acf_attribute  */
#line 1401 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6402 "tools/widl/parser.tab.c"
    break;

  case 487: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1402 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6408 "tools/widl/parser.tab.c"
    break;

  case 488: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1407 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ALLOCATE, (yyvsp[-1].num) ); }
#line 6414 "tools/widl/parser.tab.c"
    break;

  case 489: /* acf_attribute: tENCODE  */
#line 1408 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 6420 "tools/widl/parser.tab.c"
    break;

  case 490: /* acf_attribute: tDECODE  */
#line 1409 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 6426 "tools/widl/parser.tab.c"
    break;

  case 491: /* acf_attribute: tEXPLICITHANDLE  */
#line 1410 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 6432 "tools/widl/parser.tab.c"
    break;

  case 492: /* allocate_option_list: allocate_option  */
#line 1414 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6438 "tools/widl/parser.tab.c"
    break;

  case 493: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1416 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6444 "tools/widl/parser.tab.c"
    break;

  case 494: /* allocate_option: tDONTFREE  */
#line 1420 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6450 "tools/widl/parser.tab.c"
    break;

  case 495: /* allocate_option: tFREE  */
#line 1421 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6456 "tools/widl/parser.tab.c"
    break;

  case 496: /* allocate_option: tALLNODES  */
#line 1422 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6462 "tools/widl/parser.tab.c"
    break;

  case 497: /* allocate_option: tSINGLENODE  */
#line 1423 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6468 "tools/widl/parser.tab.c"
    break;


#line 6472 "tools/widl/parser.tab.c"

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

#line 1426 "tools/widl/parser.y"


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
    char *dst = replace_extension( get_basename(input_idl_name), ".idl", "" );
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
