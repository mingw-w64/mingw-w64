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
    tDEPRECATED = 325,             /* tDEPRECATED  */
    tDISABLECONSISTENCYCHECK = 326, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 327,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 328,          /* tDISPINTERFACE  */
    tDLLNAME = 329,                /* tDLLNAME  */
    tDONTFREE = 330,               /* tDONTFREE  */
    tDOUBLE = 331,                 /* tDOUBLE  */
    tDUAL = 332,                   /* tDUAL  */
    tENABLEALLOCATE = 333,         /* tENABLEALLOCATE  */
    tENCODE = 334,                 /* tENCODE  */
    tENDPOINT = 335,               /* tENDPOINT  */
    tENTRY = 336,                  /* tENTRY  */
    tENUM = 337,                   /* tENUM  */
    tERRORSTATUST = 338,           /* tERRORSTATUST  */
    tEVENTADD = 339,               /* tEVENTADD  */
    tEVENTREMOVE = 340,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 341,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 342,         /* tEXPLICITHANDLE  */
    tEXTERN = 343,                 /* tEXTERN  */
    tFALSE = 344,                  /* tFALSE  */
    tFAULTSTATUS = 345,            /* tFAULTSTATUS  */
    tFLAGS = 346,                  /* tFLAGS  */
    tFLOAT = 347,                  /* tFLOAT  */
    tFORCEALLOCATE = 348,          /* tFORCEALLOCATE  */
    tHANDLE = 349,                 /* tHANDLE  */
    tHANDLET = 350,                /* tHANDLET  */
    tHELPCONTEXT = 351,            /* tHELPCONTEXT  */
    tHELPFILE = 352,               /* tHELPFILE  */
    tHELPSTRING = 353,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 354,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 355,          /* tHELPSTRINGDLL  */
    tHIDDEN = 356,                 /* tHIDDEN  */
    tHYPER = 357,                  /* tHYPER  */
    tID = 358,                     /* tID  */
    tIDEMPOTENT = 359,             /* tIDEMPOTENT  */
    tIGNORE = 360,                 /* tIGNORE  */
    tIIDIS = 361,                  /* tIIDIS  */
    tIMMEDIATEBIND = 362,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 363,         /* tIMPLICITHANDLE  */
    tIMPORT = 364,                 /* tIMPORT  */
    tIMPORTLIB = 365,              /* tIMPORTLIB  */
    tIN = 366,                     /* tIN  */
    tIN_LINE = 367,                /* tIN_LINE  */
    tINLINE = 368,                 /* tINLINE  */
    tINPUTSYNC = 369,              /* tINPUTSYNC  */
    tINT = 370,                    /* tINT  */
    tINT32 = 371,                  /* tINT32  */
    tINT3264 = 372,                /* tINT3264  */
    tINT64 = 373,                  /* tINT64  */
    tINTERFACE = 374,              /* tINTERFACE  */
    tLCID = 375,                   /* tLCID  */
    tLENGTHIS = 376,               /* tLENGTHIS  */
    tLIBRARY = 377,                /* tLIBRARY  */
    tLICENSED = 378,               /* tLICENSED  */
    tLOCAL = 379,                  /* tLOCAL  */
    tLONG = 380,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 381,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 382,                  /* tMAYBE  */
    tMESSAGE = 383,                /* tMESSAGE  */
    tMETHODS = 384,                /* tMETHODS  */
    tMODULE = 385,                 /* tMODULE  */
    tMTA = 386,                    /* tMTA  */
    tNAMESPACE = 387,              /* tNAMESPACE  */
    tNOCODE = 388,                 /* tNOCODE  */
    tNONBROWSABLE = 389,           /* tNONBROWSABLE  */
    tNONCREATABLE = 390,           /* tNONCREATABLE  */
    tNONE = 391,                   /* tNONE  */
    tNONEXTENSIBLE = 392,          /* tNONEXTENSIBLE  */
    tNOTIFY = 393,                 /* tNOTIFY  */
    tNOTIFYFLAG = 394,             /* tNOTIFYFLAG  */
    tNULL = 395,                   /* tNULL  */
    tOBJECT = 396,                 /* tOBJECT  */
    tODL = 397,                    /* tODL  */
    tOLEAUTOMATION = 398,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 399,               /* tOPTIMIZE  */
    tOPTIONAL = 400,               /* tOPTIONAL  */
    tOUT = 401,                    /* tOUT  */
    tOVERLOAD = 402,               /* tOVERLOAD  */
    tPARTIALIGNORE = 403,          /* tPARTIALIGNORE  */
    tPOINTERDEFAULT = 404,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 405,         /* tPRAGMA_WARNING  */
    tPROGID = 406,                 /* tPROGID  */
    tPROPERTIES = 407,             /* tPROPERTIES  */
    tPROPGET = 408,                /* tPROPGET  */
    tPROPPUT = 409,                /* tPROPPUT  */
    tPROPPUTREF = 410,             /* tPROPPUTREF  */
    tPROTECTED = 411,              /* tPROTECTED  */
    tPROXY = 412,                  /* tPROXY  */
    tPTR = 413,                    /* tPTR  */
    tPUBLIC = 414,                 /* tPUBLIC  */
    tRANGE = 415,                  /* tRANGE  */
    tREADONLY = 416,               /* tREADONLY  */
    tREF = 417,                    /* tREF  */
    tREGISTER = 418,               /* tREGISTER  */
    tREPRESENTAS = 419,            /* tREPRESENTAS  */
    tREQUESTEDIT = 420,            /* tREQUESTEDIT  */
    tREQUIRES = 421,               /* tREQUIRES  */
    tRESTRICTED = 422,             /* tRESTRICTED  */
    tRETVAL = 423,                 /* tRETVAL  */
    tRUNTIMECLASS = 424,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 425,              /* tSAFEARRAY  */
    tSHORT = 426,                  /* tSHORT  */
    tSIGNED = 427,                 /* tSIGNED  */
    tSINGLENODE = 428,             /* tSINGLENODE  */
    tSIZEIS = 429,                 /* tSIZEIS  */
    tSIZEOF = 430,                 /* tSIZEOF  */
    tSMALL = 431,                  /* tSMALL  */
    tSOURCE = 432,                 /* tSOURCE  */
    tSTANDARD = 433,               /* tSTANDARD  */
    tSTATIC = 434,                 /* tSTATIC  */
    tSTRICTCONTEXTHANDLE = 435,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 436,                 /* tSTRING  */
    tSTRUCT = 437,                 /* tSTRUCT  */
    tSWITCH = 438,                 /* tSWITCH  */
    tSWITCHIS = 439,               /* tSWITCHIS  */
    tSWITCHTYPE = 440,             /* tSWITCHTYPE  */
    tTHREADING = 441,              /* tTHREADING  */
    tTRANSMITAS = 442,             /* tTRANSMITAS  */
    tTRUE = 443,                   /* tTRUE  */
    tTYPEDEF = 444,                /* tTYPEDEF  */
    tUIDEFAULT = 445,              /* tUIDEFAULT  */
    tUNION = 446,                  /* tUNION  */
    tUNIQUE = 447,                 /* tUNIQUE  */
    tUNSIGNED = 448,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 449,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 450,            /* tUSERMARSHAL  */
    tUUID = 451,                   /* tUUID  */
    tV1ENUM = 452,                 /* tV1ENUM  */
    tVARARG = 453,                 /* tVARARG  */
    tVERSION = 454,                /* tVERSION  */
    tVIPROGID = 455,               /* tVIPROGID  */
    tVOID = 456,                   /* tVOID  */
    tWCHAR = 457,                  /* tWCHAR  */
    tWIREMARSHAL = 458,            /* tWIREMARSHAL  */
    tAPARTMENT = 459,              /* tAPARTMENT  */
    tNEUTRAL = 460,                /* tNEUTRAL  */
    tSINGLE = 461,                 /* tSINGLE  */
    tFREE = 462,                   /* tFREE  */
    tBOTH = 463,                   /* tBOTH  */
    CAST = 464,                    /* CAST  */
    PPTR = 465,                    /* PPTR  */
    POS = 466,                     /* POS  */
    NEG = 467,                     /* NEG  */
    ADDRESSOF = 468                /* ADDRESSOF  */
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

#line 492 "tools/widl/parser.tab.c"

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


#line 532 "tools/widl/parser.tab.c"


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
  YYSYMBOL_tDEPRECATED = 70,               /* tDEPRECATED  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 71,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 72,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 73,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 74,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 75,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 76,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 77,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 78,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 79,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 80,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 81,                    /* tENTRY  */
  YYSYMBOL_tENUM = 82,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 83,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 84,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 85,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 86,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 87,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 88,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 89,                    /* tFALSE  */
  YYSYMBOL_tFAULTSTATUS = 90,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 91,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 92,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 93,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 94,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 95,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 96,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 97,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 98,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 99,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 100,           /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 101,                  /* tHIDDEN  */
  YYSYMBOL_tHYPER = 102,                   /* tHYPER  */
  YYSYMBOL_tID = 103,                      /* tID  */
  YYSYMBOL_tIDEMPOTENT = 104,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 105,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 106,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 107,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 108,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 109,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 110,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 111,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 112,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 113,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 114,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 115,                     /* tINT  */
  YYSYMBOL_tINT32 = 116,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 117,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 118,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 119,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 120,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 121,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 122,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 123,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 124,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 125,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 126,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 127,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 128,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 129,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 130,                  /* tMODULE  */
  YYSYMBOL_tMTA = 131,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 132,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 133,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 134,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 135,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 136,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 137,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 138,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 139,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 140,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 141,                  /* tOBJECT  */
  YYSYMBOL_tODL = 142,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 143,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 144,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 145,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 146,                     /* tOUT  */
  YYSYMBOL_tOVERLOAD = 147,                /* tOVERLOAD  */
  YYSYMBOL_tPARTIALIGNORE = 148,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPOINTERDEFAULT = 149,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 150,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 151,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 152,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 153,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 154,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 155,              /* tPROPPUTREF  */
  YYSYMBOL_tPROTECTED = 156,               /* tPROTECTED  */
  YYSYMBOL_tPROXY = 157,                   /* tPROXY  */
  YYSYMBOL_tPTR = 158,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 159,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 160,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 161,                /* tREADONLY  */
  YYSYMBOL_tREF = 162,                     /* tREF  */
  YYSYMBOL_tREGISTER = 163,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 164,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 165,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 166,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 167,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 168,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 169,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 170,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 171,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 172,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 173,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 174,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 175,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 176,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 177,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 178,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 179,                  /* tSTATIC  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 180,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 181,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 182,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 183,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 184,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 185,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 186,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 187,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 188,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 189,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 190,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 191,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 192,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 193,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 194,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 195,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 196,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 197,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 198,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 199,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 200,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 201,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 202,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 203,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 204,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 205,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 206,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 207,                    /* tFREE  */
  YYSYMBOL_tBOTH = 208,                    /* tBOTH  */
  YYSYMBOL_209_ = 209,                     /* ','  */
  YYSYMBOL_210_ = 210,                     /* '?'  */
  YYSYMBOL_211_ = 211,                     /* ':'  */
  YYSYMBOL_212_ = 212,                     /* '|'  */
  YYSYMBOL_213_ = 213,                     /* '^'  */
  YYSYMBOL_214_ = 214,                     /* '&'  */
  YYSYMBOL_215_ = 215,                     /* '<'  */
  YYSYMBOL_216_ = 216,                     /* '>'  */
  YYSYMBOL_217_ = 217,                     /* '-'  */
  YYSYMBOL_218_ = 218,                     /* '+'  */
  YYSYMBOL_219_ = 219,                     /* '*'  */
  YYSYMBOL_220_ = 220,                     /* '/'  */
  YYSYMBOL_221_ = 221,                     /* '%'  */
  YYSYMBOL_222_ = 222,                     /* '!'  */
  YYSYMBOL_223_ = 223,                     /* '~'  */
  YYSYMBOL_CAST = 224,                     /* CAST  */
  YYSYMBOL_PPTR = 225,                     /* PPTR  */
  YYSYMBOL_POS = 226,                      /* POS  */
  YYSYMBOL_NEG = 227,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 228,                /* ADDRESSOF  */
  YYSYMBOL_229_ = 229,                     /* '.'  */
  YYSYMBOL_230_ = 230,                     /* '['  */
  YYSYMBOL_231_ = 231,                     /* ']'  */
  YYSYMBOL_232_ = 232,                     /* ';'  */
  YYSYMBOL_233_ = 233,                     /* '{'  */
  YYSYMBOL_234_ = 234,                     /* '}'  */
  YYSYMBOL_235_ = 235,                     /* '('  */
  YYSYMBOL_236_ = 236,                     /* ')'  */
  YYSYMBOL_237_ = 237,                     /* '='  */
  YYSYMBOL_YYACCEPT = 238,                 /* $accept  */
  YYSYMBOL_input = 239,                    /* input  */
  YYSYMBOL_m_acf = 240,                    /* m_acf  */
  YYSYMBOL_decl_statements = 241,          /* decl_statements  */
  YYSYMBOL_decl_block = 242,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 243,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 244,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 245,           /* gbl_statements  */
  YYSYMBOL_246_1 = 246,                    /* $@1  */
  YYSYMBOL_imp_statements = 247,           /* imp_statements  */
  YYSYMBOL_248_2 = 248,                    /* $@2  */
  YYSYMBOL_int_statements = 249,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 250,            /* semicolon_opt  */
  YYSYMBOL_statement = 251,                /* statement  */
  YYSYMBOL_pragma_warning = 252,           /* pragma_warning  */
  YYSYMBOL_warnings = 253,                 /* warnings  */
  YYSYMBOL_typedecl = 254,                 /* typedecl  */
  YYSYMBOL_cppquote = 255,                 /* cppquote  */
  YYSYMBOL_import_start = 256,             /* import_start  */
  YYSYMBOL_import = 257,                   /* import  */
  YYSYMBOL_importlib = 258,                /* importlib  */
  YYSYMBOL_libraryhdr = 259,               /* libraryhdr  */
  YYSYMBOL_library_start = 260,            /* library_start  */
  YYSYMBOL_librarydef = 261,               /* librarydef  */
  YYSYMBOL_m_args = 262,                   /* m_args  */
  YYSYMBOL_arg_list = 263,                 /* arg_list  */
  YYSYMBOL_args = 264,                     /* args  */
  YYSYMBOL_arg = 265,                      /* arg  */
  YYSYMBOL_array = 266,                    /* array  */
  YYSYMBOL_m_attributes = 267,             /* m_attributes  */
  YYSYMBOL_attributes = 268,               /* attributes  */
  YYSYMBOL_attrib_list = 269,              /* attrib_list  */
  YYSYMBOL_str_list = 270,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 271,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 272,             /* contract_ver  */
  YYSYMBOL_contract_req = 273,             /* contract_req  */
  YYSYMBOL_static_attr = 274,              /* static_attr  */
  YYSYMBOL_activatable_attr = 275,         /* activatable_attr  */
  YYSYMBOL_access_attr = 276,              /* access_attr  */
  YYSYMBOL_composable_attr = 277,          /* composable_attr  */
  YYSYMBOL_deprecated_attr = 278,          /* deprecated_attr  */
  YYSYMBOL_attribute = 279,                /* attribute  */
  YYSYMBOL_callconv = 280,                 /* callconv  */
  YYSYMBOL_cases = 281,                    /* cases  */
  YYSYMBOL_case = 282,                     /* case  */
  YYSYMBOL_enums = 283,                    /* enums  */
  YYSYMBOL_enum_list = 284,                /* enum_list  */
  YYSYMBOL_enum_member = 285,              /* enum_member  */
  YYSYMBOL_enum = 286,                     /* enum  */
  YYSYMBOL_enumdef = 287,                  /* enumdef  */
  YYSYMBOL_m_exprs = 288,                  /* m_exprs  */
  YYSYMBOL_m_expr = 289,                   /* m_expr  */
  YYSYMBOL_expr = 290,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 291,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 292,           /* expr_int_const  */
  YYSYMBOL_expr_const = 293,               /* expr_const  */
  YYSYMBOL_fields = 294,                   /* fields  */
  YYSYMBOL_field = 295,                    /* field  */
  YYSYMBOL_ne_union_field = 296,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 297,          /* ne_union_fields  */
  YYSYMBOL_union_field = 298,              /* union_field  */
  YYSYMBOL_s_field = 299,                  /* s_field  */
  YYSYMBOL_funcdef = 300,                  /* funcdef  */
  YYSYMBOL_declaration = 301,              /* declaration  */
  YYSYMBOL_m_ident = 302,                  /* m_ident  */
  YYSYMBOL_m_typename = 303,               /* m_typename  */
  YYSYMBOL_typename = 304,                 /* typename  */
  YYSYMBOL_ident = 305,                    /* ident  */
  YYSYMBOL_base_type = 306,                /* base_type  */
  YYSYMBOL_m_int = 307,                    /* m_int  */
  YYSYMBOL_int_std = 308,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 309,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 310,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 311,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 312,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 313,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 314,                  /* coclass  */
  YYSYMBOL_coclassdef = 315,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 316,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 317,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 318,              /* apicontract  */
  YYSYMBOL_apicontract_def = 319,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 320,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 321,         /* class_interfaces  */
  YYSYMBOL_class_interface = 322,          /* class_interface  */
  YYSYMBOL_dispinterface = 323,            /* dispinterface  */
  YYSYMBOL_dispattributes = 324,           /* dispattributes  */
  YYSYMBOL_dispint_props = 325,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 326,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 327,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 328,                  /* inherit  */
  YYSYMBOL_type_parameter = 329,           /* type_parameter  */
  YYSYMBOL_type_parameters = 330,          /* type_parameters  */
  YYSYMBOL_interface = 331,                /* interface  */
  YYSYMBOL_332_3 = 332,                    /* $@3  */
  YYSYMBOL_333_4 = 333,                    /* $@4  */
  YYSYMBOL_delegatedef = 334,              /* delegatedef  */
  YYSYMBOL_335_5 = 335,                    /* $@5  */
  YYSYMBOL_336_6 = 336,                    /* $@6  */
  YYSYMBOL_required_types = 337,           /* required_types  */
  YYSYMBOL_requires = 338,                 /* requires  */
  YYSYMBOL_interfacedef = 339,             /* interfacedef  */
  YYSYMBOL_340_7 = 340,                    /* $@7  */
  YYSYMBOL_interfaceref = 341,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 342,         /* dispinterfaceref  */
  YYSYMBOL_module = 343,                   /* module  */
  YYSYMBOL_moduledef = 344,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 345,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 346,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 347,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 348,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 349,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 350,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 351,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 352,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 353,               /* declarator  */
  YYSYMBOL_direct_declarator = 354,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 355,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 356, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 357,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 358, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 359,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 360, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 361,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 362,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 363,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 364,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 365,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 366,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 367,          /* init_declarator  */
  YYSYMBOL_threading_type = 368,           /* threading_type  */
  YYSYMBOL_pointer_type = 369,             /* pointer_type  */
  YYSYMBOL_structdef = 370,                /* structdef  */
  YYSYMBOL_unqualified_type = 371,         /* unqualified_type  */
  YYSYMBOL_type = 372,                     /* type  */
  YYSYMBOL_typedef = 373,                  /* typedef  */
  YYSYMBOL_uniondef = 374,                 /* uniondef  */
  YYSYMBOL_version = 375,                  /* version  */
  YYSYMBOL_acf_statements = 376,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 377,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 378,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 379,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 380,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 381,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 382,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 383,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 384           /* allocate_option  */
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
#define YYLAST   3739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  238
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  147
/* YYNRULES -- Number of rules.  */
#define YYNRULES  499
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  924

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   468


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
       2,     2,     2,   222,     2,     2,     2,   221,   214,     2,
     235,   236,   219,   218,   209,   217,   229,   220,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   211,   232,
     215,   237,   216,   210,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   230,     2,   231,   213,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   233,   212,   234,   223,     2,     2,     2,
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
     205,   206,   207,   208,   224,   225,   226,   227,   228
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   368,   368,   384,   385,   389,   390,   396,   400,   401,
     406,   410,   411,   411,   413,   414,   415,   416,   417,   420,
     423,   424,   426,   427,   429,   430,   431,   432,   436,   437,
     438,   439,   439,   441,   442,   443,   444,   447,   448,   450,
     451,   453,   454,   455,   456,   457,   461,   462,   466,   467,
     471,   472,   473,   474,   475,   476,   477,   480,   488,   496,
     497,   501,   502,   503,   504,   505,   506,   507,   508,   509,
     512,   515,   517,   520,   524,   526,   530,   535,   536,   539,
     540,   543,   544,   548,   553,   560,   564,   565,   569,   570,
     574,   577,   578,   579,   582,   583,   587,   588,   589,   593,
     594,   598,   606,   613,   617,   621,   622,   626,   634,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   651,   652,   653,   654,   655,   656,   657,   658,   659,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   694,   695,   696,
     697,   698,   699,   700,   701,   702,   703,   704,   705,   706,
     707,   708,   709,   711,   712,   713,   714,   715,   716,   717,
     718,   719,   720,   721,   722,   723,   724,   725,   726,   727,
     728,   729,   730,   731,   732,   733,   734,   735,   740,   741,
     742,   743,   744,   745,   746,   747,   748,   749,   750,   751,
     752,   753,   754,   755,   756,   757,   758,   759,   760,   761,
     762,   763,   764,   767,   768,   769,   770,   774,   775,   778,
     782,   789,   790,   791,   794,   798,   810,   815,   819,   824,
     827,   828,   832,   833,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   849,   850,   851,
     852,   853,   854,   855,   856,   857,   858,   859,   860,   861,
     862,   863,   864,   865,   866,   867,   868,   869,   870,   871,
     872,   873,   875,   877,   878,   881,   882,   885,   891,   898,
     899,   902,   907,   914,   915,   919,   920,   924,   925,   928,
     932,   938,   946,   950,   956,   957,   961,   962,   965,   966,
     969,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     981,   982,   986,   987,   990,   991,   992,   993,   994,   995,
     996,   997,   998,  1002,  1003,  1007,  1008,  1011,  1016,  1017,
    1018,  1019,  1020,  1024,  1025,  1029,  1032,  1036,  1039,  1044,
    1047,  1051,  1052,  1056,  1057,  1061,  1062,  1065,  1068,  1071,
    1072,  1075,  1076,  1080,  1082,  1087,  1088,  1089,  1092,  1096,
    1097,  1101,  1102,  1102,  1102,  1106,  1111,  1112,  1110,  1119,
    1120,  1121,  1122,  1126,  1127,  1130,  1130,  1143,  1147,  1148,
    1149,  1153,  1156,  1159,  1164,  1165,  1166,  1170,  1174,  1178,
    1179,  1182,  1183,  1187,  1189,  1194,  1195,  1199,  1200,  1201,
    1205,  1207,  1208,  1212,  1213,  1214,  1215,  1220,  1222,  1223,
    1228,  1230,  1235,  1236,  1241,  1242,  1243,  1244,  1248,  1256,
    1258,  1259,  1264,  1266,  1271,  1272,  1279,  1280,  1281,  1282,
    1283,  1287,  1294,  1295,  1299,  1300,  1303,  1310,  1311,  1316,
    1317,  1321,  1322,  1323,  1324,  1325,  1326,  1330,  1331,  1332,
    1335,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1348,  1352,  1353,  1354,  1357,  1364,  1366,  1372,  1373,  1374,
    1378,  1379,  1383,  1384,  1388,  1395,  1404,  1405,  1409,  1410,
    1414,  1416,  1417,  1418,  1422,  1423,  1428,  1429,  1430,  1431
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
  "tDEFAULTCOLLELEM", "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDEPRECATED",
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
  "activatable_attr", "access_attr", "composable_attr", "deprecated_attr",
  "attribute", "callconv", "cases", "case", "enums", "enum_list",
  "enum_member", "enum", "enumdef", "m_exprs", "m_expr", "expr",
  "expr_list_int_const", "expr_int_const", "expr_const", "fields", "field",
  "ne_union_field", "ne_union_fields", "union_field", "s_field", "funcdef",
  "declaration", "m_ident", "m_typename", "typename", "ident", "base_type",
  "m_int", "int_std", "namespace_pfx", "qualified_type",
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

#define YYPACT_NINF (-659)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-487)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -659,   137,  1874,  -659,   -61,  -659,   -35,   -15,   176,  -659,
    -659,  -659,   176,  -659,   -33,   -25,   176,  -659,   327,  -659,
    -659,  -659,  -659,   101,   214,  -659,  -659,  -659,  -659,  -659,
     176,   101,   259,    60,  -659,   176,    71,   101,   497,  -659,
    -659,   328,   362,   497,  -659,  -659,  3536,  -659,  -659,  -659,
    -659,    50,  -659,  -659,  -659,  -659,  -659,    -4,  2935,    81,
      87,  -659,  -659,  -659,   366,   138,  -659,   143,  -659,   149,
    -659,   164,  -659,  -105,   171,   195,   173,   175,  -659,  -659,
    -659,   177,   177,   177,   147,  1427,   178,  -659,   177,   179,
     181,  -659,   120,  -659,   -15,   290,  -659,  -659,  -659,  -659,
     406,  -659,  -659,   129,   183,  -659,  -659,  -659,   185,   203,
    -659,  -659,   111,  -659,  1427,  -659,  -659,   169,   188,   -68,
     -84,  -659,   187,  -659,   189,  -659,  -659,   191,  -659,  -659,
    -659,   192,   193,  -659,  -659,   196,  -659,  -659,  -659,   198,
     199,  -659,   204,  -659,  -659,  -659,  -659,   207,  -659,   208,
    -659,  -659,   209,  -659,  -659,  -659,   211,   212,  -659,  -659,
     213,  -659,  -659,  -659,  -659,  -659,   215,   217,   220,   221,
     223,  -659,   230,  -659,  -659,   231,  -659,   235,  -659,  -659,
     239,   240,  -659,  -659,   241,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,   244,  -659,  -659,   245,
    -659,   246,   257,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
     260,  -659,  -659,   261,  -659,  -659,  -659,   262,  -659,   263,
    -659,  -659,   270,   271,   272,   273,  -659,  -659,  -659,   274,
     275,  -659,  -659,   276,   279,   280,   -53,  -659,  -659,  -659,
    2006,  1135,  1427,   176,   200,   205,   367,   176,   371,   374,
     258,   284,   285,   306,   286,  -659,   147,   288,   289,  -659,
     265,   307,  3241,  -659,  -659,  -659,   470,  -659,  -659,   294,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,  -659,   147,   147,  -659,  -659,   291,   -38,  -659,  -659,
    -659,   177,  -659,  -659,  -659,   298,  -659,  -659,  -659,   -27,
    -659,  -659,   518,   293,   -31,    54,  -659,  -659,   324,   325,
     302,  -659,   311,  -659,  3139,   532,   538,   176,   946,  3139,
    3139,   551,   547,   946,   559,   560,   561,   946,  3139,   946,
     562,   569,   946,   570,   946,   946,  2472,   946,   946,    55,
     571,   574,   -37,   576,   946,  1427,   946,  3139,   946,  1427,
     281,  1427,  1427,   580,   238,   588,  1427,  3536,   368,  -659,
     370,   365,  -659,  -659,  -659,  -659,   369,  -659,   373,  -659,
     376,  -659,    68,   377,   378,  -659,  -659,  -659,   173,   176,
    -659,  3139,  -659,  -659,   383,  -659,   383,   -75,  -659,  -659,
     387,   386,   389,   306,  -659,  -659,  -659,   366,    93,   385,
    -659,   -86,  -659,  -659,   -21,   104,   388,  -659,   946,   218,
    2472,  -659,  -659,    25,   120,  -659,   392,  -659,   387,  -659,
     176,   394,   397,   384,  -659,   176,   623,   623,  -659,    88,
     200,    94,  -659,   400,   421,   401,   402,   405,  -659,  -659,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,   398,  -659,   946,
     946,   946,   946,   946,   946,   887,  2716,  -107,  -659,   408,
     437,   411,   439,   424,   418,   446,  2716,   420,   448,   422,
     425,  -659,   -97,   426,   427,   428,   434,   438,   440,   441,
     442,  2363,   449,  3139,   133,   451,   -96,  -659,  2716,  -659,
    -659,  -659,   452,   454,   455,   458,   459,   487,   461,   -66,
     462,   491,  2477,   466,  -659,  -659,  -659,  -659,  -659,  -659,
     467,   468,   471,   472,   431,  -659,   480,   481,   482,  -659,
    3536,  -659,   710,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
     -93,   147,  1582,   115,   138,  -659,  -659,   173,   555,  -659,
    -659,  -659,  3241,  -659,  1445,   512,   -44,   493,  -659,  -659,
    -659,  -659,   936,  -659,  2607,   492,   520,  -659,  -659,  -659,
    -659,  -659,  -659,   -42,  -659,  -659,   541,   516,  -659,  -659,
     116,   946,  -659,  -659,   524,  -659,    36,    53,  -659,  3139,
    -659,  3139,   498,  -659,   495,  -659,   503,  -659,  3037,  -659,
    -659,  -659,  3286,    34,    34,    34,    34,    34,    34,  -659,
    2582,   159,  3378,   177,   946,   946,   734,   946,   946,   946,
     946,   946,   946,   946,   946,   946,   946,   946,   946,   946,
     946,   946,   946,   946,   735,   946,   946,  -659,  -659,   144,
    -659,   551,   733,  -659,   946,  -659,   737,  -659,  -659,   732,
    -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,  -659,
    -659,   133,  -659,  2138,  -659,   133,  -659,  -659,  -659,   -13,
    -659,   946,  -659,  -659,  -659,  -659,  -659,  -659,   946,  -659,
    -659,  -659,  3139,  -659,  -659,  -659,  -659,  -659,  -659,   736,
    -659,  -659,  -659,  -659,   -29,   507,  -659,  -659,  2472,  -659,
     535,   173,  -659,   556,  3139,   173,    47,  -659,   117,  -659,
     387,   513,  -659,  -659,  -659,   536,   517,  1031,   514,  -659,
    -659,  -659,  2370,    25,  -659,   521,   526,   541,  3241,  -659,
    -659,   176,   534,  -659,  -659,  -659,   133,   529,   147,   123,
     176,  -659,  -659,  -659,  -659,   159,  -659,  -659,  2254,  -659,
     159,  -659,   527,    51,   177,  -659,   283,   283,  -659,   777,
     777,   463,   463,   802,  2735,  2695,   824,  1631,  1071,   463,
     463,    40,    40,    34,    34,    34,  -659,  2656,  -659,  -659,
    -659,   543,  -659,   528,   557,  -659,  -659,    79,  -659,   531,
     133,   533,  -659,  2472,  -659,  -659,   537,  -659,  -659,   387,
    -659,   173,  1290,   176,   539,   147,  -659,  -659,   176,   387,
     540,   544,   173,   138,  -659,   568,  -659,  -659,  -659,  -659,
    3139,   546,  -659,  -659,  -659,  -659,  -659,   760,  -659,  -659,
     -32,  -659,  -659,   572,  -659,   -98,  -659,  -659,   549,  -659,
     548,   372,  -659,   550,   133,   552,  -659,   946,  2472,  -659,
    -659,   946,  -659,  3139,  -659,  3139,  -659,    79,  -659,  -659,
    -659,   558,  -659,   553,  -659,  -659,    62,   173,  -659,  -659,
     563,   366,  -659,  -659,  -659,  -659,   387,  1719,  -659,   573,
     578,   946,  -659,   133,  -659,  -659,  -659,  -659,    79,  -659,
    -659,  -659,    34,   564,  2716,  -659,  -659,  -659,  -659,  3241,
     545,  -659,   579,   138,  -659,   173,  -659,  -659,  -659,  -659,
      33,  -659,  -659,    64,  2472,  -659,   946,   592,  -659,  -659,
     581,   582,   595,   165,  -659,  -659,   165,  -659,  -659,   583,
     173,  -659,  -659,  -659
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   308,    55,   470,   480,     0,   319,
     311,   330,     0,   398,     0,     0,     0,   318,   306,   320,
     394,   317,   321,   322,     0,   397,   324,   331,   332,   329,
       0,   322,     0,     0,   396,     0,     0,   322,     0,   326,
     395,   306,   306,   316,   461,   312,   109,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   463,
       0,   335,   462,   313,     0,     0,   473,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   405,   405,   405,     0,     0,   465,   471,   405,     0,
     467,   333,     0,     4,   480,     0,   308,   309,   349,   345,
       0,     5,   357,   464,     0,   307,   323,   328,     0,   371,
     327,   351,     0,   347,     0,   325,   314,   466,     0,   468,
       0,   315,     0,   111,     0,   113,   114,     0,   115,   116,
     117,     0,     0,   120,   122,     0,   123,   124,   125,     0,
       0,   128,     0,   130,   131,   132,   133,     0,   135,     0,
     137,   138,     0,   140,   141,   142,     0,     0,   145,   146,
       0,   148,   149,   150,   151,   152,     0,     0,     0,     0,
       0,   158,     0,   160,   161,     0,   163,     0,   165,   166,
     169,     0,   170,   171,     0,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,     0,   185,   186,     0,
     188,     0,     0,   191,   192,   193,   194,   195,   459,   196,
       0,   198,   457,     0,   200,   201,   202,     0,   204,     0,
     206,   207,     0,     0,     0,     0,   212,   458,   213,     0,
       0,   217,   218,     0,     0,     0,     0,    91,   222,    51,
      88,    88,     0,     0,    88,     0,   306,     0,   306,   306,
       0,   463,     0,   365,     0,   385,     0,   465,   467,    52,
     308,   472,     0,    18,    22,    20,     0,    12,    15,     0,
      49,   387,    14,   409,   406,   408,   407,   223,   224,   225,
     226,   399,     0,     0,   310,   413,   449,   412,   303,   463,
     465,   405,   467,   401,    54,     0,   492,   491,   493,     0,
     488,   481,     0,     0,     0,    88,    71,   372,     0,     0,
       0,   289,     0,   295,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   242,     0,
       0,     0,     0,     0,     0,     0,   242,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,    90,    72,
       0,     0,    45,    42,    43,    44,     0,    36,     0,    40,
       0,    38,     0,     0,     0,    34,    33,    41,    48,     0,
     392,     0,    89,    46,   464,    74,   466,   468,    75,   353,
       0,     0,     0,   365,   302,   334,   338,     0,   339,   341,
     343,     0,   352,    11,     0,     0,     0,   411,     0,     0,
      77,   415,   402,     0,     0,   487,     0,    70,     0,     7,
       0,     0,   233,   238,   234,     0,     0,     0,   469,    88,
      88,    88,   104,     0,     0,     0,     0,     0,   253,   244,
     245,   246,   250,   251,   252,   247,   248,     0,   249,     0,
       0,     0,     0,     0,     0,     0,   287,     0,   285,     0,
       0,     0,     0,    99,     0,     0,   288,     0,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   434,     0,     0,   240,   243,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   456,   451,   452,   453,   454,   455,
       0,     0,     0,     0,   477,   479,     0,     0,     0,    92,
     109,     8,     0,    35,    39,    37,    31,    30,    29,    76,
       0,     0,    88,    88,   366,   367,   353,    48,   383,   336,
     340,   342,     0,   337,    88,     0,    88,     0,   400,   410,
     414,   450,     0,    87,     0,     0,    81,    78,    79,   498,
     496,   499,   497,     0,   494,   489,   482,     0,   236,   239,
      88,     0,   368,   369,   373,    59,     0,     0,   460,     0,
     290,     0,     0,   475,    89,   296,     0,   110,     0,   112,
     216,   118,     0,   277,   276,   275,   278,   273,   274,   470,
       0,   422,     0,   405,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   121,     0,
     126,     0,     0,   127,     0,   134,     0,   136,   139,     0,
     143,   144,   147,   153,   154,   155,   156,   157,   159,   162,
     164,   434,   399,    77,   439,   434,   436,   435,    84,   431,
     168,   242,   167,   172,   184,   187,   189,   190,     0,   199,
     203,   205,     0,   208,   209,   211,   210,   214,   215,     0,
     219,   220,   221,    93,     0,     0,    28,   376,    77,   442,
     474,    48,    47,     0,    89,    48,     0,   354,    88,   350,
       0,     0,   344,    13,   359,     0,     0,     0,     0,    86,
      85,   416,     0,     0,   490,   486,     0,   482,     0,   235,
     237,     0,     0,    60,    57,    58,     0,   467,     0,   465,
     304,   294,   293,   101,   103,   422,   284,   399,    77,   426,
     422,   423,     0,   419,   405,   403,   266,   267,   279,   260,
     261,   264,   265,   255,   256,     0,   257,   258,   259,   263,
     262,   269,   268,   271,   272,   270,   280,     0,   286,   106,
     105,     0,   100,     0,     0,    95,    83,   434,   399,     0,
     434,     0,   430,    77,   438,   241,     0,   102,   478,     0,
      10,    48,    88,     0,     0,     0,   393,   346,     0,     0,
       0,     0,    48,   379,   380,   384,    46,   361,   360,   363,
       0,     0,   301,   364,    82,    80,   495,     0,   485,   483,
       0,   370,   374,   444,   447,     0,   292,   299,     0,   305,
       0,   422,   399,     0,   434,     0,   418,     0,    77,   425,
     404,     0,   283,     0,   129,     0,   429,   434,   440,   433,
     437,     0,   197,     0,    73,    32,     0,    48,   443,   391,
     335,     0,   390,   355,   356,   348,     0,    88,   362,     0,
       0,     0,   446,     0,   291,   227,   282,   417,   434,   427,
     421,   424,   281,     0,   254,   107,   108,   432,   441,     0,
       0,   375,   336,   381,   382,    48,   484,     6,   445,   448,
       0,   420,   428,     0,    77,   386,     0,     0,   476,   228,
       0,     0,     0,    88,     9,   377,    88,   298,   230,     0,
      48,   229,   297,   378
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -659,  -659,  -659,  -659,  -659,  -659,  -659,   382,  -659,   -51,
    -659,   -36,  -331,    -1,  -659,   352,  -659,  -659,  -659,  -659,
    -659,  -659,  -659,    29,  -587,  -659,  -659,  -314,  -276,  -241,
      -2,  -659,  -659,  -659,   499,  -268,  -659,  -659,  -659,  -659,
    -659,  -285,   -69,  -659,  -659,  -659,  -659,  -659,   242,    17,
     445,   153,   304,  -659,  -288,  -319,  -659,  -659,  -659,  -659,
    -108,  -335,  -659,   109,  -659,    26,    -6,   -63,  -257,    96,
     256,  -249,  -255,  -246,   277,  -658,    18,    30,    21,    32,
      23,    37,    38,   295,  -659,    28,  -659,  -659,  -659,  -659,
     444,   112,    39,    16,  -659,  -659,    43,  -659,  -659,  -659,
    -659,    46,  -659,  -659,  -659,  -659,    48,  -659,  -659,  -354,
    -583,     7,   243,   -45,   -55,  -229,  -659,  -659,  -659,  -630,
    -659,  -655,  -659,  -568,  -659,  -659,  -659,   -43,  -659,   584,
    -659,   496,    12,  -392,    -8,  -659,    15,  -659,   740,   122,
    -659,  -659,   127,  -659,   443,  -659,   140
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
     918,   919,   811,    60,   828,   104,    61,   656,    62,   107,
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
     102,   411,   105,   397,    86,   283,   399,    90,    77,    59,
      67,   285,   482,    69,   109,    71,   274,   274,   274,   113,
      74,    56,    68,   274,    70,   105,   105,   275,   276,    72,
      73,   475,   723,   293,   478,    78,   480,   529,    79,   485,
      80,   548,   461,   406,   407,   606,   497,   559,   261,   723,
     820,   606,   242,   603,   420,   256,   779,   118,   120,   777,
     257,   823,   519,   258,   255,   251,   252,   291,   284,   253,
     906,   254,    96,   776,    97,   705,   489,   782,   418,   551,
     789,   277,   278,   279,   280,   582,   586,   907,    30,   312,
     560,   794,   626,   269,  -486,   830,   310,    96,  -308,    97,
     836,   873,   639,   661,   308,  -308,   277,   278,   279,   280,
     798,   208,   687,   542,   266,   212,   243,   110,   267,   627,
     543,   545,    13,   115,   874,   534,    96,     3,    97,   640,
     662,   397,   688,   661,   535,   277,   278,   279,   280,   313,
      96,   833,    97,   295,   831,   227,   357,    13,  -308,   277,
     278,   279,   280,   567,   -66,  -308,   799,   713,    91,   397,
     670,   277,   278,   279,   280,   309,   549,   542,   358,    96,
    -309,    97,   414,   296,   870,   244,    46,   283,   579,   581,
     581,   490,   409,   285,   714,   847,   851,   410,   561,   297,
     603,   877,   100,   419,   415,   790,   699,   298,   101,   846,
     744,   706,   849,   283,   283,    92,   106,   409,   823,   285,
     285,   438,   783,   108,   439,   440,   441,   442,   443,   444,
      13,   903,   562,   491,   379,   683,   274,   380,    58,    58,
     105,   385,   105,   105,   514,   515,   412,    84,    84,   878,
     284,   883,    86,    86,   437,    90,    90,    59,    59,   621,
     622,   623,   111,   624,   625,    20,   880,   908,    16,   624,
     625,   721,   724,   542,   118,   120,   284,   284,   890,   887,
     910,   409,   239,   720,    46,   396,   838,   398,  -231,   725,
      25,   693,   696,   397,   116,   112,   399,   266,   652,   121,
     769,   526,   689,   770,   606,   581,   114,   445,   262,   409,
     901,   284,   540,   -61,   653,   773,   530,   911,    46,   259,
     734,   434,   578,   281,    46,   739,   460,   462,   583,   420,
     103,   117,    97,    97,   483,   474,   283,   498,   768,   282,
      34,   503,   285,   511,   512,    46,    46,    46,   518,   695,
    -232,   802,   652,   262,   501,  -300,    40,   568,   446,  -300,
     796,   -62,  -308,   409,   797,   119,   281,    97,   653,   260,
     384,    97,    97,   284,   386,   263,    97,   387,   737,    97,
     786,   264,   282,   784,   277,   278,   279,   280,   531,   409,
       4,   539,    97,   447,   738,    46,   265,   917,   815,   284,
     602,   -64,  -308,   268,   787,   270,   448,   272,   483,   302,
     -63,   294,   504,   -65,   284,   303,   305,   306,   307,   572,
     547,   311,   314,   548,   315,    13,   316,   317,   318,   584,
      46,   319,   449,   320,   321,   450,   451,   552,   383,   322,
     453,   454,   323,   324,   325,   803,   326,   327,   328,   553,
     329,   397,   330,   455,   804,   331,   332,   696,   333,   739,
     854,   396,   283,   398,   739,   334,   335,   839,   285,   397,
     336,   865,   399,   402,   337,   338,   339,   548,   284,   340,
     341,   342,   604,   605,   606,   505,   506,   507,   508,   509,
     651,   388,   343,   548,   395,   344,   345,   346,   347,   827,
     619,   620,   621,   622,   623,   348,   349,   350,   351,   352,
     353,   354,   624,   625,   355,   356,   -67,   390,   389,   392,
     -68,   -69,  -336,   416,   548,   284,   891,   404,   408,   417,
     694,   692,   740,   413,   853,   426,   427,   602,   428,    84,
     397,   435,    58,    49,    86,    11,   430,    90,   274,    59,
     861,    84,   898,   862,   436,   739,    86,   463,   745,    90,
      77,    59,    67,   465,   905,    69,   858,    71,   468,   470,
     471,   476,    74,    56,    68,   885,    70,   886,   477,   479,
     493,    72,    73,   494,   780,   496,   726,    78,   728,   923,
      79,   737,    80,   729,   727,   462,   513,   517,   520,    23,
     522,   523,   409,   521,   541,   524,   570,   738,   525,   527,
     528,   893,    26,    27,    28,    29,  -308,   397,   912,   536,
     894,   571,    31,   537,   550,   566,   693,   466,   569,   575,
     588,   466,   396,   592,   398,   792,   587,   589,   590,   481,
     397,   591,   488,   399,   628,   284,   629,   630,   631,   284,
     488,   483,   502,   632,   633,   634,   635,   636,   637,   283,
     679,   638,   641,   642,   643,   285,   740,   829,    37,   834,
     644,   740,   581,    39,   645,   581,   646,   647,   648,   462,
     619,   620,   621,   622,   623,   650,   483,   660,   663,   274,
     664,   665,   624,   625,   666,   667,   668,   669,   671,   840,
     672,   256,   674,   675,   676,   810,   257,   677,   678,   258,
     483,   251,   466,   554,    84,   572,   680,   681,   682,   685,
     284,   700,   284,   704,   284,   708,   283,   731,   711,   712,
     715,   718,   285,   721,   730,   732,   483,   748,   766,   772,
     774,   775,   788,   791,   795,   244,   806,   807,   813,   808,
     822,    92,   843,   593,   594,   595,   596,   597,   598,   600,
     818,   826,   740,   837,   844,   869,   845,   848,   889,   850,
     867,   284,   863,   852,   284,   857,   864,   866,   868,   577,
     904,   483,   875,   871,   876,   544,   879,   572,   881,   284,
      58,   499,   859,   860,   888,  -388,   604,   605,   606,    84,
     902,   609,   610,   913,    86,   896,   916,    90,   921,    59,
     897,  -389,   719,   914,   785,   922,   812,   256,   915,   702,
     464,   604,   605,   606,   607,   608,   609,   610,   284,   612,
     899,   698,   856,   821,   301,   735,   483,   538,   495,   819,
     394,   284,   817,   604,   605,   606,   607,   608,   609,   610,
     462,     0,   462,   816,     0,   892,   596,   565,     0,     0,
       0,     0,     0,     0,     0,   694,   692,   284,     0,     0,
       0,     0,   284,     0,    84,     0,     0,     0,     0,    86,
       0,     0,    90,     0,    59,     0,     0,     0,     0,     0,
     438,     0,   599,   439,   440,   441,   442,   443,   444,     0,
       0,     0,   483,     0,     0,     0,     0,     0,   746,   747,
       0,   749,   750,   751,   752,   753,   754,   755,   756,   757,
     758,   759,   760,   761,   762,   763,   764,   765,     9,   767,
      10,     0,     0,     0,     0,    11,     0,     0,   466,   438,
      13,     0,   439,   440,   441,   442,   443,   444,     0,   438,
       0,     0,   439,   440,   441,   442,   443,   444,     0,     0,
       0,     0,     0,    17,     0,   488,     0,     0,     0,   246,
      19,     0,     0,     0,     0,    20,   445,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,   617,   618,   619,   620,   621,   622,   623,     0,
      25,     0,    26,    27,    28,    29,   624,   625,     0,     0,
       0,     0,    31,     0,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,     0,   445,     0,   446,     0,     0,
       0,   624,   625,     0,     4,   445,     6,   615,   616,   617,
     618,   619,   620,   621,   622,   623,     0,     0,     0,     0,
      34,     0,     0,   624,   625,     0,     0,    36,    37,    38,
       0,     0,   447,    39,     0,     0,    40,     0,     0,   248,
       0,     0,     9,     0,    10,   448,   446,     0,   249,    11,
      43,     0,     0,     0,    13,     0,   446,     0,    44,    45,
     604,   605,   606,   607,   608,   609,   610,     0,     0,     0,
       0,   449,     0,     0,   450,   451,   452,    17,     0,   453,
     454,   447,     0,   246,    19,     0,     0,     0,     0,    20,
       0,   447,   455,    21,   448,     0,    22,     0,     0,     0,
       0,     0,     0,    23,   448,     0,     0,     0,     4,     5,
       6,   882,     0,     0,    25,   884,    26,    27,    28,    29,
     449,     0,     0,   450,   451,   452,    31,     0,   453,   454,
     449,     0,     0,   450,   451,   452,     0,   709,   453,   454,
       8,   455,     0,     0,     0,   466,     9,     0,    10,     0,
       0,   455,     0,    11,    12,     0,     0,     0,    13,     0,
       0,     0,     0,     0,    34,    14,     0,   360,     0,     0,
       0,    36,    37,    38,     0,     0,     0,    39,    16,     0,
      40,    17,     0,   248,     0,     0,     0,    18,    19,     0,
       0,     0,   249,    20,    43,     0,     0,    21,     0,     0,
      22,     0,    44,    45,     0,     0,     0,    23,     0,     0,
       0,     0,     0,     0,    24,   361,     0,     0,    25,     0,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
      31,    46,     0,     0,     0,   809,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,   617,   618,   619,   620,
     621,   622,   623,     4,     5,     6,     0,     0,    34,     0,
     624,   625,     0,     0,    35,    36,    37,    38,     0,     0,
       0,    39,     0,     0,    40,     0,     0,    41,     0,     0,
       0,     0,     0,     0,     0,     8,    42,     0,    43,     0,
       0,     9,     0,    10,     0,     0,    44,    45,    11,    12,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      14,     0,   360,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16,     0,    46,    17,     0,     0,   378,
       0,     0,    18,    19,     0,     0,     0,     0,    20,     0,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
     361,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       4,     0,     6,     0,     0,     0,     0,     0,     0,     0,
      33,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     0,     0,    34,     0,     0,     0,     0,     0,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     9,    40,
      10,     0,    41,     0,     0,    11,     0,     0,     0,     0,
       8,    42,     0,    43,     0,     0,     9,     0,    10,     0,
       0,    44,    45,    11,    12,     0,     0,     0,    13,     0,
       0,     0,     0,    17,     0,    14,     0,    15,     0,   246,
      19,     0,     0,     0,     0,     0,     0,     0,    16,    21,
      46,    17,    22,     0,   855,     0,     0,    18,    19,    23,
       0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
      22,     0,    26,    27,    28,    29,     0,    23,     0,     0,
       0,     0,    31,     0,    24,     0,     0,     0,    25,     0,
      26,    27,    28,    29,    30,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     0,    33,     0,    36,    37,    38,
       0,     0,     0,    39,     0,     0,     0,     0,    34,   248,
       0,     0,     0,     0,    35,    36,    37,    38,   249,     0,
      43,    39,     0,     9,    40,    10,     0,    41,    44,    45,
      11,     0,     0,     0,     0,    13,    42,     0,    43,     0,
       0,     0,    14,     0,     0,     0,    44,    45,     0,     0,
     604,   605,   606,   607,   608,   609,   610,     0,    17,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,     0,
      20,     0,     0,     0,    21,    46,     0,    22,     0,   703,
       0,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    24,     0,     0,     0,    25,     0,    26,    27,    28,
      29,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    39,     0,
       9,    40,    10,     0,    41,     0,     0,    11,     0,     0,
       0,     0,    13,    42,     0,    43,     0,     0,     0,    14,
       0,     0,     0,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,    20,     0,     0,
       0,    21,    46,     0,    22,     0,   691,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,    24,     0,
       0,     0,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,   616,   617,   618,   619,   620,
     621,   622,   623,     0,     0,     0,     0,     0,     0,     0,
     624,   625,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,    -3,     0,     0,     4,     5,     6,
       0,     0,    34,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     7,     0,     0,    39,     0,     0,    40,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     8,
      42,     0,    43,     0,     0,     9,     0,    10,     0,     0,
      44,    45,    11,    12,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    14,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,    46,
      17,     0,     0,   895,     0,     0,    18,    19,     0,     0,
       0,     0,    20,     0,     0,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,    24,     0,     0,     0,    25,     0,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     4,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   359,    33,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     8,     0,    35,    36,    37,    38,     9,     0,    10,
      39,     0,     0,    40,    11,    12,    41,     0,     0,    13,
       0,     0,     0,     0,     0,    42,    14,    43,   360,     0,
       0,     0,     0,     0,     0,    44,    45,     0,     0,    16,
       0,     0,    17,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,    22,     0,     0,    46,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,    24,   361,     0,     0,    25,
       0,    26,    27,    28,    29,    30,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     4,     0,     6,     0,     0,     0,     0,     0,     0,
     277,   278,   279,   280,     0,     0,    33,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,    35,    36,    37,    38,     9,
       0,    10,    39,     0,     0,    40,    11,     0,    41,     0,
       0,    13,     0,     0,     0,     0,     0,    42,     0,    43,
       0,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,     0,    17,     0,     0,     0,     0,     0,
     246,    19,     0,     0,     0,     0,    20,     0,     0,     0,
      21,     0,     0,    22,     0,     0,    46,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,     0,    26,    27,    28,    29,     4,     0,     6,
       0,     0,     0,    31,     0,     0,   277,   278,   279,   280,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,    34,    11,     0,     0,     0,     0,    13,    36,    37,
      38,     0,     0,     0,    39,     0,     0,    40,     0,     0,
     248,     0,     0,     0,     0,     0,     0,     0,     0,   249,
      17,    43,     0,     0,     0,     0,   246,    19,     0,    44,
      45,     0,    20,     0,     0,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,   778,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    46,    26,
      27,    28,    29,     4,     0,     6,     0,     0,     0,    31,
       0,     0,   604,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,   814,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,     0,     0,     0,    34,    11,     0,
       0,     0,     0,    13,    36,    37,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     0,   248,     0,     0,     0,
       0,     0,     0,     0,     0,   249,    17,    43,     0,     0,
       0,     0,   246,    19,     0,    44,    45,     0,    20,     0,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,   832,     0,     4,     0,     6,     0,     0,
       0,     0,     0,    25,    46,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,   604,   605,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,     0,
      11,     0,     0,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,    17,    40,
       0,     0,   248,     0,   246,    19,     0,     0,     0,     0,
      20,   249,     0,    43,    21,     0,     0,    22,     0,     0,
       0,    44,    45,   613,    23,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,    25,     0,    26,    27,    28,
      29,     0,   624,   625,     0,     0,     0,    31,     0,   649,
      46,   604,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   604,   605,   606,   607,
     608,   609,   610,   611,   612,    34,     0,     0,     0,     0,
       0,     0,    36,    37,    38,     0,     0,     0,    39,     0,
       0,    40,     0,     0,   248,     0,     0,     0,     0,     0,
       0,     0,     0,   249,     0,    43,     0,     0,     0,     0,
       0,     0,     0,    44,    45,   604,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,   613,     0,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,     0,
       0,     0,    46,     0,     0,     0,   624,   625,     0,     0,
       0,     0,     0,   673,   604,   605,   606,   607,   608,   609,
     610,   611,   612,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   604,   605,   606,   607,   608,
     609,   610,   611,   612,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   604,   605,   606,   607,   608,   609,
     610,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   613,     0,   614,   615,   616,   617,   618,   619,
     620,   621,   622,   623,     0,     0,     0,     0,     0,     0,
       0,   624,   625,     0,     0,     0,     0,   613,   736,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,     0,
       0,     0,     0,     0,     0,     0,   624,   625,   710,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   613,     0,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,     0,     0,
       0,     0,     0,     0,     0,   624,   625,   842,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   613,   841,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,     0,     0,     0,
       0,     0,     0,     0,   624,   625,   613,     0,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,     4,     0,
       6,     0,     0,     0,     0,   624,   625,   614,   615,   616,
     617,   618,   619,   620,   621,   622,   623,     0,     0,     0,
       0,     0,     0,     0,   624,   625,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     9,     0,    10,     0,
       0,     0,     0,    11,    12,     0,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -358,     0,
       0,    17,     0,     0,     0,     0,     0,   246,    19,     0,
       0,     0,     0,    20,     0,     0,     0,    21,     0,     0,
      22,     0,     0,     0,     0,     0,     0,    23,     0,     0,
       4,     0,     6,   463,     0,     0,     0,     0,    25,     0,
      26,    27,    28,    29,    30,     0,     0,   247,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,    35,    36,    37,    38,     0,     0,
       0,    39,     0,    17,    40,     0,     0,   248,     0,   246,
      19,     0,     0,     0,     0,    20,   249,     0,    43,    21,
       0,     0,    22,     0,     0,     0,    44,    45,     0,    23,
       0,     0,     4,     0,     6,     0,     0,     0,     0,     0,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,    11,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,    39,     0,    17,    40,     0,     0,   248,
       0,   246,    19,     0,     0,     0,     0,    20,   249,     0,
      43,    21,     0,     0,    22,     0,     0,     0,    44,    45,
       0,    23,     0,     0,     4,     0,    97,     0,     0,     0,
       0,     0,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,     0,     0,    11,
       0,   599,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,     0,    39,     0,    17,    40,     0,
       0,   248,     0,     0,    19,     0,     0,     9,     0,    10,
     249,     0,    43,    21,    11,     0,    22,     0,     0,    13,
      44,    45,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,    27,    28,    29,
       0,     0,    17,     0,     0,     0,    31,     0,   246,    19,
       0,     0,     0,     0,    20,     0,     0,     0,    21,     0,
       0,    22,     0,   599,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,    37,    38,     0,     0,     0,    39,     0,     9,
       0,    10,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,    17,     0,    36,    37,    38,     0,
     246,    19,    39,     0,     0,    40,     0,     0,   248,     0,
      21,     0,     0,    22,     0,     0,     0,   249,     0,    43,
      23,     0,     0,     0,     0,     0,     0,    44,    45,     0,
       0,     0,     0,    26,    27,    28,    29,     0,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    36,    37,
      38,     0,     0,     0,    39,     0,     0,     0,     0,     0,
     248,     0,     0,     0,     0,   122,   123,     0,     0,   249,
     124,    43,   125,   126,   127,   128,   129,     0,   130,    44,
      45,   131,     0,   132,     0,     0,   133,   134,   135,     0,
     136,   137,   138,   139,   140,   141,     0,   142,     0,   143,
     144,   145,     0,   146,   147,   148,   149,   150,   151,     0,
     152,     0,     0,   153,   154,   155,   156,   157,     0,     0,
     158,   159,   160,   161,     0,     0,   162,   163,     0,   164,
     165,     0,   166,   167,   168,   169,   170,   171,     0,   172,
     173,   174,   175,   176,   177,     0,     0,   178,     0,     0,
     179,     0,     0,     0,     0,     0,   180,   181,     0,   182,
     183,     0,   184,   185,   186,     0,     0,     0,     0,   187,
     188,   189,     0,   190,   191,   192,     0,   193,   194,   195,
     196,   197,   198,   199,   200,   201,     0,   202,     0,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,     0,
     213,   214,     0,   215,   216,     0,     0,     0,     0,     0,
     217,     0,     0,   218,     0,   219,   220,   221,     0,     0,
     222,   223,   224,   225,     0,     0,   226,     0,   227,     0,
     228,   229,   230,   231,   232,   233,   234,     0,     0,   235
};

static const yytype_int16 yycheck[] =
{
       2,     2,     8,   244,    55,   262,    12,   262,   327,     2,
      16,   287,    18,   262,     2,    84,   262,     2,     2,     2,
       2,    84,   336,     2,    30,     2,    81,    82,    83,    35,
       2,     2,     2,    88,     2,    41,    42,    82,    83,     2,
       2,   329,     6,    88,   332,     2,   334,   378,     2,   337,
       2,   405,   320,   282,   283,    21,   344,    32,    64,     6,
     718,    21,    66,   455,   305,    58,   653,    41,    42,   652,
      58,   726,   357,    58,    58,    58,    58,    85,    84,    58,
      47,    58,     3,   651,     5,   129,    31,   655,   119,   408,
     119,    12,    13,    14,    15,   430,   431,    64,   119,   183,
      75,   688,   209,    75,   119,   735,   114,     3,   183,     5,
     740,   209,   209,   209,     3,   183,    12,    13,    14,    15,
      73,   158,   215,   209,   229,   162,   130,    31,   233,   236,
     216,   152,    53,    37,   232,   390,     3,     0,     5,   236,
     236,   390,   235,   209,   390,    12,    13,    14,    15,   233,
       3,   738,     5,    33,   737,   192,   209,    53,   233,    12,
      13,    14,    15,   418,   232,   233,   119,   209,   229,   418,
     236,    12,    13,    14,    15,    64,   405,   209,   231,     3,
     215,     5,   209,    63,   216,   189,   230,   256,   429,   430,
     431,   136,   230,   256,   236,   778,   783,   235,   173,    79,
     592,   831,   235,   234,   231,   234,   537,    87,   233,   777,
     602,   546,   780,   282,   283,   230,   115,   230,   873,   282,
     283,     3,   235,     9,     6,     7,     8,     9,    10,    11,
      53,   889,   207,   178,   242,   520,   291,   243,   240,   241,
     246,   247,   248,   249,     6,     7,   291,   240,   241,   832,
     256,   838,   240,   241,   317,   240,   241,   240,   241,   219,
     220,   221,     3,   229,   230,    88,   834,   234,    73,   229,
     230,   209,   236,   209,   248,   249,   282,   283,   216,   847,
     216,   230,   232,   571,   230,   542,   235,   542,   234,   236,
     113,   532,   533,   542,    38,   235,   542,   229,   219,    43,
     156,   233,   531,   159,    21,   546,   235,    89,   215,   230,
     878,   317,   219,   232,   235,   634,   379,   904,   230,   232,
     588,   314,   234,   219,   230,   601,   319,   320,   234,   570,
       3,     3,     5,     5,   336,   328,   405,   345,   626,   235,
     163,   349,   405,   351,   352,   230,   230,   230,   356,   234,
     234,   234,   219,   215,   347,   232,   179,   420,   140,   236,
     691,   232,   233,   230,   695,     3,   219,     5,   235,     3,
       3,     5,     5,   379,     3,   232,     5,     3,   219,     5,
     668,   232,   235,   659,    12,    13,    14,    15,   381,   230,
       3,   397,     5,   175,   235,   230,   232,   232,   712,   405,
     455,   232,   233,   232,   672,   232,   188,   232,   410,   119,
     232,   232,   131,   232,   420,     9,   233,   232,   215,   425,
     404,   233,   235,   777,   235,    53,   235,   235,   235,   431,
     230,   235,   214,   235,   235,   217,   218,   219,   233,   235,
     222,   223,   235,   235,   235,   700,   235,   235,   235,   231,
     235,   700,   235,   235,   700,   235,   235,   698,   235,   735,
     791,   718,   531,   718,   740,   235,   235,   743,   531,   718,
     235,   802,   718,     3,   235,   235,   235,   831,   484,   235,
     235,   235,    19,    20,    21,   204,   205,   206,   207,   208,
     483,   233,   235,   847,   229,   235,   235,   235,   235,   728,
     217,   218,   219,   220,   221,   235,   235,   235,   235,   235,
     235,   235,   229,   230,   235,   235,   232,   211,   233,   233,
     232,   232,   215,     5,   878,   531,   857,   233,   237,   236,
     532,   532,   601,   235,   789,   211,   211,   592,   236,   532,
     789,     9,   544,   544,   532,    48,   235,   532,   603,   532,
     799,   544,   871,   799,    16,   831,   544,     6,   603,   544,
     544,   544,   544,    16,   895,   544,   795,   544,     9,     9,
       9,     9,   544,   544,   544,   843,   544,   845,     9,     9,
       9,   544,   544,     9,   653,     9,   579,   544,   581,   920,
     544,   219,   544,   581,   579,   588,    16,     9,   230,   102,
     235,   232,   230,   233,   219,   232,   209,   235,   232,   232,
     232,   866,   115,   116,   117,   118,   233,   866,   906,   233,
     866,   237,   125,   234,   236,   233,   867,   323,   234,     6,
     209,   327,   889,   235,   889,   686,   236,   236,   236,   335,
     889,   236,   338,   889,   236,   651,   209,   236,   209,   655,
     346,   653,   348,   229,   236,   209,   236,   209,   236,   728,
     229,   236,   236,   236,   236,   728,   735,   730,   171,   738,
     236,   740,   913,   176,   236,   916,   236,   236,   236,   672,
     217,   218,   219,   220,   221,   236,   688,   236,   236,   744,
     236,   236,   229,   230,   236,   236,   209,   236,   236,   744,
     209,   694,   236,   236,   236,   707,   694,   236,   236,   694,
     712,   694,   408,   409,   707,   721,   236,   236,   236,     9,
     726,   166,   728,   211,   730,   232,   795,   232,   236,   209,
     189,   215,   795,   209,   236,   232,   738,     3,     3,     6,
       3,     9,     6,   236,   209,   189,   233,   211,   234,   232,
     216,   230,   209,   449,   450,   451,   452,   453,   454,   455,
     234,   232,   831,   236,   236,     5,   209,   236,   215,   236,
     806,   777,   232,   236,   780,   236,   232,   209,   232,   427,
     235,   783,   233,   211,   236,   403,   236,   793,   236,   795,
     792,   346,   798,   799,   236,   232,    19,    20,    21,   792,
     236,    24,    25,   211,   792,   232,   211,   792,   916,   792,
     232,   232,   570,   232,   661,   232,   707,   810,   236,   542,
     321,    19,    20,    21,    22,    23,    24,    25,   834,    27,
     873,   536,   793,   721,    94,   592,   838,   393,   342,   717,
     256,   847,   715,    19,    20,    21,    22,    23,    24,    25,
     843,    -1,   845,   713,    -1,   861,   552,   414,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   867,   867,   873,    -1,    -1,
      -1,    -1,   878,    -1,   867,    -1,    -1,    -1,    -1,   867,
      -1,    -1,   867,    -1,   867,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,   904,    -1,    -1,    -1,    -1,    -1,   604,   605,
      -1,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   617,   618,   619,   620,   621,   622,   623,    41,   625,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,   634,     3,
      53,    -1,     6,     7,     8,     9,    10,    11,    -1,     3,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    -1,    76,    -1,   661,    -1,    -1,    -1,    82,
      83,    -1,    -1,    -1,    -1,    88,    89,    -1,    -1,    92,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,   102,
      -1,    -1,   215,   216,   217,   218,   219,   220,   221,    -1,
     113,    -1,   115,   116,   117,   118,   229,   230,    -1,    -1,
      -1,    -1,   125,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    89,    -1,   140,    -1,    -1,
      -1,   229,   230,    -1,     3,    89,     5,   213,   214,   215,
     216,   217,   218,   219,   220,   221,    -1,    -1,    -1,    -1,
     163,    -1,    -1,   229,   230,    -1,    -1,   170,   171,   172,
      -1,    -1,   175,   176,    -1,    -1,   179,    -1,    -1,   182,
      -1,    -1,    41,    -1,    43,   188,   140,    -1,   191,    48,
     193,    -1,    -1,    -1,    53,    -1,   140,    -1,   201,   202,
      19,    20,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,   214,    -1,    -1,   217,   218,   219,    76,    -1,   222,
     223,   175,    -1,    82,    83,    -1,    -1,    -1,    -1,    88,
      -1,   175,   235,    92,   188,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,   102,   188,    -1,    -1,    -1,     3,     4,
       5,   837,    -1,    -1,   113,   841,   115,   116,   117,   118,
     214,    -1,    -1,   217,   218,   219,   125,    -1,   222,   223,
     214,    -1,    -1,   217,   218,   219,    -1,   231,   222,   223,
      35,   235,    -1,    -1,    -1,   871,    41,    -1,    43,    -1,
      -1,   235,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,   163,    60,    -1,    62,    -1,    -1,
      -1,   170,   171,   172,    -1,    -1,    -1,   176,    73,    -1,
     179,    76,    -1,   182,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,   191,    88,   193,    -1,    -1,    92,    -1,    -1,
      95,    -1,   201,   202,    -1,    -1,    -1,   102,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,    -1,    -1,   113,    -1,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
     125,   230,    -1,    -1,    -1,   234,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   215,   216,   217,   218,
     219,   220,   221,     3,     4,     5,    -1,    -1,   163,    -1,
     229,   230,    -1,    -1,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,   191,    -1,   193,    -1,
      -1,    41,    -1,    43,    -1,    -1,   201,   202,    48,    49,
      -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    73,    -1,   230,    76,    -1,    -1,   234,
      -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,
      -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,
     110,    -1,    -1,   113,    -1,   115,   116,   117,   118,   119,
      -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,
      -1,    -1,   132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,   169,
     170,   171,   172,    -1,    -1,    -1,   176,    -1,    41,   179,
      43,    -1,   182,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      35,   191,    -1,   193,    -1,    -1,    41,    -1,    43,    -1,
      -1,   201,   202,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    76,    -1,    60,    -1,    62,    -1,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    92,
     230,    76,    95,    -1,   234,    -1,    -1,    82,    83,   102,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,   115,   116,   117,   118,    -1,   102,    -1,    -1,
      -1,    -1,   125,    -1,   109,    -1,    -1,    -1,   113,    -1,
     115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,    -1,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,   163,   182,
      -1,    -1,    -1,    -1,   169,   170,   171,   172,   191,    -1,
     193,   176,    -1,    41,   179,    43,    -1,   182,   201,   202,
      48,    -1,    -1,    -1,    -1,    53,   191,    -1,   193,    -1,
      -1,    -1,    60,    -1,    -1,    -1,   201,   202,    -1,    -1,
      19,    20,    21,    22,    23,    24,    25,    -1,    76,    -1,
      -1,    -1,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,
      88,    -1,    -1,    -1,    92,   230,    -1,    95,    -1,   234,
      -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,    -1,    -1,
      -1,   109,    -1,    -1,    -1,   113,    -1,   115,   116,   117,
     118,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
      41,   179,    43,    -1,   182,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,   191,    -1,   193,    -1,    -1,    -1,    60,
      -1,    -1,    -1,   201,   202,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    82,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,
      -1,    92,   230,    -1,    95,    -1,   234,    -1,    -1,    -1,
      -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,
      -1,    -1,   113,    -1,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,   214,   215,   216,   217,   218,
     219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   150,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,    18,    -1,    -1,   176,    -1,    -1,   179,    -1,
      -1,   182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
     191,    -1,   193,    -1,    -1,    41,    -1,    43,    -1,    -1,
     201,   202,    48,    49,    -1,    -1,    -1,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,   230,
      76,    -1,    -1,   234,    -1,    -1,    82,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,    -1,
      -1,    -1,    -1,   109,    -1,    -1,    -1,   113,    -1,   115,
     116,   117,   118,   119,    -1,    -1,    -1,    -1,    -1,   125,
      -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,    -1,     3,
       4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,   150,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,    -1,
      -1,    35,    -1,   169,   170,   171,   172,    41,    -1,    43,
     176,    -1,    -1,   179,    48,    49,   182,    -1,    -1,    53,
      -1,    -1,    -1,    -1,    -1,   191,    60,   193,    62,    -1,
      -1,    -1,    -1,    -1,    -1,   201,   202,    -1,    -1,    73,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    -1,
      -1,    95,    -1,    -1,   230,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,    -1,    -1,   113,
      -1,   115,   116,   117,   118,   119,    -1,    -1,    -1,    -1,
      -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,   132,    -1,
      -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    -1,    -1,   150,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    -1,   169,   170,   171,   172,    41,
      -1,    43,   176,    -1,    -1,   179,    48,    -1,   182,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    -1,   191,    -1,   193,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      82,    83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,
      92,    -1,    -1,    95,    -1,    -1,   230,    -1,    -1,    -1,
     102,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   113,    -1,   115,   116,   117,   118,     3,    -1,     5,
      -1,    -1,    -1,   125,    -1,    -1,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,   163,    48,    -1,    -1,    -1,    -1,    53,   170,   171,
     172,    -1,    -1,    -1,   176,    -1,    -1,   179,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   191,
      76,   193,    -1,    -1,    -1,    -1,    82,    83,    -1,   201,
     202,    -1,    88,    -1,    -1,    -1,    92,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,   102,   219,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,   230,   115,
     116,   117,   118,     3,    -1,     5,    -1,    -1,    -1,   125,
      -1,    -1,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    43,    -1,    -1,    -1,   163,    48,    -1,
      -1,    -1,    -1,    53,   170,   171,   172,    -1,    -1,    -1,
     176,    -1,    -1,   179,    -1,    -1,   182,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   191,    76,   193,    -1,    -1,
      -1,    -1,    82,    83,    -1,   201,   202,    -1,    88,    -1,
      -1,    -1,    92,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,   102,   219,    -1,     3,    -1,     5,    -1,    -1,
      -1,    -1,    -1,   113,   230,   115,   116,   117,   118,    -1,
      -1,    -1,    -1,    -1,    -1,   125,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,
      48,    -1,    -1,    -1,    -1,    53,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
     170,   171,   172,    -1,    -1,    -1,   176,    -1,    76,   179,
      -1,    -1,   182,    -1,    82,    83,    -1,    -1,    -1,    -1,
      88,   191,    -1,   193,    92,    -1,    -1,    95,    -1,    -1,
      -1,   201,   202,   210,   102,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   113,    -1,   115,   116,   117,
     118,    -1,   229,   230,    -1,    -1,    -1,   125,    -1,   236,
     230,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,
      23,    24,    25,    26,    27,   163,    -1,    -1,    -1,    -1,
      -1,    -1,   170,   171,   172,    -1,    -1,    -1,   176,    -1,
      -1,   179,    -1,    -1,   182,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   191,    -1,   193,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   201,   202,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,   210,    -1,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,   230,    -1,    -1,    -1,   229,   230,    -1,    -1,
      -1,    -1,    -1,   236,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   210,    -1,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   229,   230,    -1,    -1,    -1,    -1,   210,   236,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   229,   230,   231,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   229,   230,   231,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,   210,    -1,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,     3,    -1,
       5,    -1,    -1,    -1,    -1,   229,   230,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,
      -1,    -1,    -1,    48,    49,    -1,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    82,    83,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,   102,    -1,    -1,
       3,    -1,     5,     6,    -1,    -1,    -1,    -1,   113,    -1,
     115,   116,   117,   118,   119,    -1,    -1,   122,    -1,    -1,
     125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   163,    -1,
      -1,    -1,    -1,    -1,   169,   170,   171,   172,    -1,    -1,
      -1,   176,    -1,    76,   179,    -1,    -1,   182,    -1,    82,
      83,    -1,    -1,    -1,    -1,    88,   191,    -1,   193,    92,
      -1,    -1,    95,    -1,    -1,    -1,   201,   202,    -1,   102,
      -1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,    -1,
     113,    -1,   115,   116,   117,   118,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,   172,
      -1,    -1,    -1,   176,    -1,    76,   179,    -1,    -1,   182,
      -1,    82,    83,    -1,    -1,    -1,    -1,    88,   191,    -1,
     193,    92,    -1,    -1,    95,    -1,    -1,    -1,   201,   202,
      -1,   102,    -1,    -1,     3,    -1,     5,    -1,    -1,    -1,
      -1,    -1,   113,    -1,   115,   116,   117,   118,    -1,    -1,
      -1,    -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    -1,    43,    -1,    -1,    -1,    -1,    48,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,   170,
     171,   172,    -1,    -1,    -1,   176,    -1,    76,   179,    -1,
      -1,   182,    -1,    -1,    83,    -1,    -1,    41,    -1,    43,
     191,    -1,   193,    92,    48,    -1,    95,    -1,    -1,    53,
     201,   202,    -1,   102,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   115,   116,   117,   118,
      -1,    -1,    76,    -1,    -1,    -1,   125,    -1,    82,    83,
      -1,    -1,    -1,    -1,    88,    -1,    -1,    -1,    92,    -1,
      -1,    95,    -1,     5,    -1,    -1,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   113,
      -1,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
      -1,   125,   171,   172,    -1,    -1,    -1,   176,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   202,    -1,    -1,    -1,    -1,    -1,   163,
      -1,    -1,    -1,    -1,    76,    -1,   170,   171,   172,    -1,
      82,    83,   176,    -1,    -1,   179,    -1,    -1,   182,    -1,
      92,    -1,    -1,    95,    -1,    -1,    -1,   191,    -1,   193,
     102,    -1,    -1,    -1,    -1,    -1,    -1,   201,   202,    -1,
      -1,    -1,    -1,   115,   116,   117,   118,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   170,   171,
     172,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
     182,    -1,    -1,    -1,    -1,    29,    30,    -1,    -1,   191,
      34,   193,    36,    37,    38,    39,    40,    -1,    42,   201,
     202,    45,    -1,    47,    -1,    -1,    50,    51,    52,    -1,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    63,
      64,    65,    -1,    67,    68,    69,    70,    71,    72,    -1,
      74,    -1,    -1,    77,    78,    79,    80,    81,    -1,    -1,
      84,    85,    86,    87,    -1,    -1,    90,    91,    -1,    93,
      94,    -1,    96,    97,    98,    99,   100,   101,    -1,   103,
     104,   105,   106,   107,   108,    -1,    -1,   111,    -1,    -1,
     114,    -1,    -1,    -1,    -1,    -1,   120,   121,    -1,   123,
     124,    -1,   126,   127,   128,    -1,    -1,    -1,    -1,   133,
     134,   135,    -1,   137,   138,   139,    -1,   141,   142,   143,
     144,   145,   146,   147,   148,   149,    -1,   151,    -1,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,    -1,
     164,   165,    -1,   167,   168,    -1,    -1,    -1,    -1,    -1,
     174,    -1,    -1,   177,    -1,   179,   180,   181,    -1,    -1,
     184,   185,   186,   187,    -1,    -1,   190,    -1,   192,    -1,
     194,   195,   196,   197,   198,   199,   200,    -1,    -1,   203
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   239,   245,     0,     3,     4,     5,    18,    35,    41,
      43,    48,    49,    53,    60,    62,    73,    76,    82,    83,
      88,    92,    95,   102,   109,   113,   115,   116,   117,   118,
     119,   125,   132,   150,   163,   169,   170,   171,   172,   176,
     179,   182,   191,   193,   201,   202,   230,   240,   242,   251,
     252,   254,   255,   256,   257,   260,   261,   267,   268,   287,
     301,   304,   306,   308,   309,   310,   311,   314,   315,   316,
     317,   318,   319,   320,   323,   324,   327,   331,   334,   339,
     344,   345,   346,   347,   349,   352,   370,   371,   372,   373,
     374,   229,   230,   376,   379,   380,     3,     5,   304,   304,
     235,   233,   304,     3,   303,   304,   115,   307,     9,   304,
     307,     3,   235,   304,   235,   307,   308,     3,   303,     3,
     303,   308,    29,    30,    34,    36,    37,    38,    39,    40,
      42,    45,    47,    50,    51,    52,    54,    55,    56,    57,
      58,    59,    61,    63,    64,    65,    67,    68,    69,    70,
      71,    72,    74,    77,    78,    79,    80,    81,    84,    85,
      86,    87,    90,    91,    93,    94,    96,    97,    98,    99,
     100,   101,   103,   104,   105,   106,   107,   108,   111,   114,
     120,   121,   123,   124,   126,   127,   128,   133,   134,   135,
     137,   138,   139,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   151,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   164,   165,   167,   168,   174,   177,   179,
     180,   181,   184,   185,   186,   187,   190,   192,   194,   195,
     196,   197,   198,   199,   200,   203,   269,   279,   369,   232,
     247,   247,    66,   130,   189,   343,    82,   122,   182,   191,
     259,   287,   314,   316,   318,   331,   349,   370,   374,   232,
       3,   304,   215,   232,   232,   232,   229,   233,   232,   323,
     232,   250,   232,   351,   352,   351,   351,    12,    13,    14,
      15,   219,   235,   280,   304,   305,   353,   354,   367,   287,
     370,   372,   374,   351,   232,    33,    63,    79,    87,   381,
     382,   376,   119,     9,   241,   233,   232,   215,     3,    64,
     372,   233,   183,   233,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   209,   231,    17,
      62,   110,   244,   251,   258,   261,   314,   315,   316,   317,
     318,   319,   320,   323,   331,   334,   339,   344,   234,   372,
     304,   267,   268,   233,     3,   304,     3,     3,   233,   233,
     211,   328,   233,   340,   367,   229,   306,   309,   310,   311,
     312,   313,     3,   246,   233,   348,   353,   353,   237,   230,
     235,   266,   351,   235,   209,   231,     5,   236,   119,   234,
     267,   283,   284,   285,   286,   332,   211,   211,   236,   294,
     235,   297,   273,   275,   349,     9,    16,   305,     3,     6,
       7,     8,     9,    10,    11,    89,   140,   175,   188,   214,
     217,   218,   219,   222,   223,   235,   290,   291,   292,   277,
     349,   273,   349,     6,   272,    16,   290,   293,     9,   278,
       9,     9,   270,   293,   349,   292,     9,     9,   292,     9,
     292,   290,   265,   268,   349,   292,   288,   289,   290,    31,
     136,   178,   271,     9,     9,   369,     9,   292,   372,   288,
     274,   349,   290,   372,   131,   204,   205,   206,   207,   208,
     368,   372,   372,    16,     6,     7,   375,     9,   372,   279,
     230,   233,   235,   232,   232,   232,   233,   232,   232,   250,
     305,   349,   249,   321,   310,   311,   233,   234,   328,   304,
     219,   219,   209,   216,   245,   152,   325,   331,   347,   353,
     236,   293,   219,   231,   290,   262,   263,   264,   265,    32,
      75,   173,   207,   383,   384,   382,   233,   310,   305,   234,
     209,   237,   304,   329,   330,     6,   253,   253,   234,   267,
     295,   267,   299,   234,   268,   296,   299,   236,   209,   236,
     236,   236,   235,   290,   290,   290,   290,   290,   290,     5,
     290,   350,   352,   371,    19,    20,    21,    22,    23,    24,
      25,    26,    27,   210,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   229,   230,   209,   236,   236,   209,
     236,   209,   229,   236,   209,   236,   209,   236,   236,   209,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   349,   219,   235,   266,   280,   305,   359,   361,   362,
     236,   209,   236,   236,   236,   236,   236,   236,   209,   236,
     236,   236,   209,   236,   236,   236,   236,   236,   236,   229,
     236,   236,   236,   279,   243,     9,   248,   215,   235,   353,
     363,   234,   251,   267,   268,   234,   267,   322,   321,   250,
     166,   338,   312,   234,   211,   129,   299,   326,   232,   231,
     231,   236,   209,   209,   236,   189,   377,   378,   215,   286,
     292,   209,   333,     6,   236,   236,   349,   374,   349,   370,
     236,   232,   232,   272,   273,   350,   236,   219,   235,   266,
     280,   355,   357,   358,   371,   351,   290,   290,     3,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,     3,   290,   292,   156,
     159,   276,     6,   293,     3,     9,   361,   348,   219,   262,
     280,   360,   361,   235,   266,   289,   292,   273,     6,   119,
     234,   236,   247,   335,   262,   209,   250,   250,    73,   119,
     341,   342,   234,   310,   311,   337,   233,   211,   232,   234,
     268,   300,   301,   234,    28,   265,   384,   380,   234,   377,
     313,   329,   216,   359,   365,   366,   232,   353,   302,   305,
     357,   348,   219,   262,   280,   356,   357,   236,   235,   266,
     351,   211,   231,   209,   236,   209,   361,   348,   236,   361,
     236,   262,   236,   310,   250,   234,   330,   236,   353,   304,
     304,   309,   311,   232,   232,   250,   209,   249,   232,     5,
     216,   211,   364,   209,   232,   233,   236,   357,   348,   236,
     361,   236,   290,   262,   290,   273,   273,   361,   236,   215,
     216,   250,   304,   310,   311,   234,   232,   232,   293,   365,
     281,   361,   236,   313,   235,   250,    47,    64,   234,   282,
     216,   262,   292,   211,   232,   236,   211,   232,   298,   299,
     336,   298,   232,   250
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   238,   239,   240,   240,   241,   241,   242,   243,   243,
     244,   245,   246,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   247,   247,
     247,   248,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   249,   249,   250,   250,
     251,   251,   251,   251,   251,   251,   251,   252,   252,   253,
     253,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   262,   263,
     263,   264,   264,   265,   265,   266,   266,   266,   267,   267,
     268,   269,   269,   269,   270,   270,   271,   271,   271,   272,
     272,   273,   274,   275,   275,   276,   276,   277,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   280,   280,   280,   280,   281,   281,   282,
     282,   283,   283,   283,   284,   284,   285,   286,   286,   287,
     288,   288,   289,   289,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   290,   290,   291,   291,   292,   293,   294,
     294,   295,   295,   296,   296,   297,   297,   298,   298,   299,
     299,   300,   301,   301,   302,   302,   303,   303,   304,   304,
     305,   306,   306,   306,   306,   306,   306,   306,   306,   306,
     306,   306,   307,   307,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   309,   309,   310,   310,   311,   312,   312,
     312,   312,   312,   313,   313,   314,   315,   316,   317,   318,
     319,   320,   320,   321,   321,   322,   322,   323,   324,   325,
     325,   326,   326,   327,   327,   328,   328,   328,   329,   330,
     330,   331,   332,   333,   331,   334,   335,   336,   334,   337,
     337,   337,   337,   338,   338,   340,   339,   339,   341,   341,
     341,   342,   343,   344,   345,   345,   345,   346,   347,   348,
     348,   349,   349,   350,   350,   351,   351,   352,   352,   352,
     353,   353,   353,   354,   354,   354,   354,   355,   355,   355,
     356,   356,   357,   357,   358,   358,   358,   358,   358,   359,
     359,   359,   360,   360,   361,   361,   362,   362,   362,   362,
     362,   362,   363,   363,   364,   364,   365,   366,   366,   367,
     367,   368,   368,   368,   368,   368,   368,   369,   369,   369,
     370,   371,   371,   371,   371,   371,   371,   371,   371,   371,
     371,   372,   372,   372,   373,   374,   374,   375,   375,   375,
     376,   376,   377,   377,   378,   379,   380,   380,   381,   381,
     382,   382,   382,   382,   383,   383,   384,   384,   384,   384
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
       1,     1,     1,     1,     4,     1,     4,     1,     1,     4,
       1,     1,     1,     4,     4,     1,     1,     4,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     1,     4,
       1,     1,     4,     1,     4,     1,     1,     4,     4,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     1,     4,     1,     4,
       4,     1,     1,     1,     1,     1,     1,     6,     1,     4,
       1,     1,     1,     4,     1,     4,     1,     1,     4,     4,
       4,     4,     1,     1,     4,     4,     4,     1,     1,     4,
       4,     4,     1,     1,     1,     1,     1,     0,     2,     4,
       3,     0,     2,     1,     1,     3,     2,     3,     1,     5,
       1,     3,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     2,     2,     3,
       3,     5,     5,     4,     3,     1,     3,     1,     1,     0,
       2,     4,     3,     2,     2,     0,     2,     2,     1,     3,
       2,     1,     3,     2,     0,     1,     0,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     1,     1,     1,     1,
       1,     1,     0,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     2,     3,     1,     2,     4,     1,     1,
       2,     1,     2,     1,     3,     2,     6,     2,     7,     2,
       5,     2,     3,     0,     2,     3,     3,     2,     1,     2,
       3,     2,     3,     6,     6,     0,     2,     2,     1,     1,
       3,     2,     0,     0,     7,     8,     0,     0,    13,     1,
       1,     3,     3,     0,     2,     0,     9,     2,     2,     3,
       2,     2,     2,     6,     1,     1,     1,     1,     1,     0,
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
#line 368 "tools/widl/parser.y"
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
#line 3571 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3577 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 391 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3585 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 396 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3591 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3597 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 402 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3603 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3609 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 410 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3615 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 411 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3621 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 412 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3627 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3633 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3639 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 415 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3645 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 416 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3651 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3659 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 420 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3667 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3673 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3680 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 426 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3686 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3693 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3699 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3705 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 431 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3711 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3717 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3723 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3729 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 438 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3735 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 439 "tools/widl/parser.y"
                                          { push_namespaces((yyvsp[-1].str_list)); }
#line 3741 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 440 "tools/widl/parser.y"
                                                { pop_namespaces((yyvsp[-4].str_list)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3747 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3753 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 442 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3759 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 443 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3765 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3773 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 447 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3779 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3786 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3792 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 451 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3799 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3805 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 454 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3811 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 455 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3817 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 456 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3823 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 457 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3829 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 461 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3835 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 462 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3841 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3847 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 472 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3853 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 473 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3859 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3865 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 475 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3871 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3877 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 477 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3883 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 481 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3895 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 489 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3904 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 496 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3910 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 497 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3916 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM aIDENTIFIER  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3922 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3928 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION aIDENTIFIER  */
#line 506 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3934 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3940 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 508 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3946 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 509 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3952 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3958 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); push_import( (yyvsp[-1].str), &yylloc ); }
#line 3964 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 517 "tools/widl/parser.y"
                                                { pop_import( &yylloc ); }
#line 3970 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3976 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3982 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3990 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3996 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 535 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4002 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 539 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 4008 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 540 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 4014 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(xstrdup("...")) ); }
#line 4020 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 548 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4030 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 553 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 4040 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 4049 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4055 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4061 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 4067 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 4073 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 4079 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 4085 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 4091 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 4097 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 4103 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 4109 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 4115 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 4121 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 4127 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 4133 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 598 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 4143 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 606 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4152 "tools/widl/parser.tab.c"
    break;

  case 103: /* activatable_attr: decl_spec ',' contract_req  */
#line 613 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4161 "tools/widl/parser.tab.c"
    break;

  case 104: /* activatable_attr: contract_req  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 4167 "tools/widl/parser.tab.c"
    break;

  case 105: /* access_attr: tPUBLIC  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4173 "tools/widl/parser.tab.c"
    break;

  case 106: /* access_attr: tPROTECTED  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4179 "tools/widl/parser.tab.c"
    break;

  case 107: /* composable_attr: decl_spec ',' access_attr ',' contract_req  */
#line 627 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].declspec)->type->type_type != TYPE_INTERFACE)
                                                      error_loc( "type %s is not an interface\n", (yyvsp[-4].declspec)->type->name );
                                                  (yyval.expr) = make_exprt( EXPR_MEMBER, declare_var( append_attr( NULL, (yyvsp[-2].attr) ), (yyvsp[-4].declspec), make_declarator( NULL ), 0 ), (yyvsp[0].expr) );
                                                }
#line 4188 "tools/widl/parser.tab.c"
    break;

  case 108: /* deprecated_attr: aSTRING ',' aIDENTIFIER ',' contract_req  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3( EXPR_MEMBER, make_exprs( EXPR_STRLIT, (yyvsp[-4].str) ), make_exprs( EXPR_IDENTIFIER, (yyvsp[-2].str) ), (yyvsp[0].expr) ); }
#line 4194 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: %empty  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 4200 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tACTIVATABLE '(' activatable_attr ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ACTIVATABLE, (yyvsp[-1].expr) ); }
#line 4206 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tAGGREGATABLE  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AGGREGATABLE, 0 ); }
#line 4212 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ANNOTATION, (yyvsp[-1].str) ); }
#line 4218 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tAPPOBJECT  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_APPOBJECT, 0 ); }
#line 4224 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tASYNC  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ASYNC, 0 ); }
#line 4230 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tAUTOHANDLE  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_AUTO_HANDLE, 0 ); }
#line 4236 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tBINDABLE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BINDABLE, 0 ); }
#line 4242 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tBROADCAST  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_BROADCAST, 0 ); }
#line 4248 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCALLAS '(' ident ')'  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CALLAS, (yyvsp[-1].var) ); }
#line 4254 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CASE, (yyvsp[-1].expr_list) ); }
#line 4260 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCODE  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CODE, 0 ); }
#line 4266 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCOMPOSABLE '(' composable_attr ')'  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_COMPOSABLE, (yyvsp[-1].expr) ); }
#line 4272 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCOMMSTATUS  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_COMMSTATUS, 0 ); }
#line 4278 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tCONTEXTHANDLE  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); }
#line 4284 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4290 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTEXTHANDLE, 0 ); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4296 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_CONTRACT, (yyvsp[-1].expr) ); }
#line 4302 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTRACTVERSION, (yyvsp[-1].num) ); }
#line 4308 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tCONTROL  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_CONTROL, 0 ); }
#line 4314 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tCUSTOM '(' aUUID ',' expr_const ')'  */
#line 659 "tools/widl/parser.y"
                                                { attr_custdata_t *data = xmalloc( sizeof(*data) );
                                                  data->id = *(yyvsp[-3].uuid); data->pval = (yyvsp[-1].expr);
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_CUSTOM, data );
                                                }
#line 4323 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDECODE  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 4329 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDEFAULT  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULT, 0 ); }
#line 4335 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDEFAULTBIND  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTBIND, 0 ); }
#line 4341 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tDEFAULTCOLLELEM  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTCOLLELEM, 0 ); }
#line 4347 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DEFAULTVALUE, (yyvsp[-1].expr) ); }
#line 4353 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tDEFAULTVTABLE  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DEFAULTVTABLE, 0 ); }
#line 4359 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tDEPRECATED '(' deprecated_attr ')'  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DEPRECATED, (yyvsp[-1].expr) ); }
#line 4365 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISABLECONSISTENCYCHECK, 0 ); }
#line 4371 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tDISPLAYBIND  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DISPLAYBIND, 0 ); }
#line 4377 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_DLLNAME, (yyvsp[-1].str) ); }
#line 4383 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tDUAL  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DUAL, 0 ); }
#line 4389 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tENABLEALLOCATE  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENABLEALLOCATE, 0 ); }
#line 4395 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tENCODE  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 4401 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tENDPOINT '(' str_list ')'  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENDPOINT, (yyvsp[-1].str_list) ); }
#line 4407 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tENTRY '(' expr_const ')'  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ENTRY, (yyvsp[-1].expr) ); }
#line 4413 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tEVENTADD  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTADD, 0 ); }
#line 4419 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tEVENTREMOVE  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EVENTREMOVE, 0 ); }
#line 4425 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 680 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
                                                      error_loc( "type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type );
                                                }
#line 4434 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tEXPLICITHANDLE  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 4440 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tFAULTSTATUS  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FAULTSTATUS, 0 ); }
#line 4446 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tFLAGS  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FLAGS, 0 ); }
#line 4452 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tFORCEALLOCATE  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_FORCEALLOCATE, 0 ); }
#line 4458 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tHANDLE  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HANDLE, 0 ); }
#line 4464 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPCONTEXT, (yyvsp[-1].expr) ); }
#line 4470 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPFILE, (yyvsp[-1].str) ); }
#line 4476 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRING, (yyvsp[-1].str) ); }
#line 4482 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr) ); }
#line 4488 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_HELPSTRINGDLL, (yyvsp[-1].str) ); }
#line 4494 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tHIDDEN  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_HIDDEN, 0 ); }
#line 4500 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tID '(' expr_int_const ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ID, (yyvsp[-1].expr) ); }
#line 4506 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tIDEMPOTENT  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IDEMPOTENT, 0 ); }
#line 4512 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tIGNORE  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IGNORE, 0 ); }
#line 4518 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tIIDIS '(' expr ')'  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IIDIS, (yyvsp[-1].expr) ); }
#line 4524 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tIMMEDIATEBIND  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IMMEDIATEBIND, 0 ); }
#line 4530 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var) ); }
#line 4536 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tIN  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_IN, 0 ); }
#line 4542 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tINPUTSYNC  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_INPUTSYNC, 0 ); }
#line 4548 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LENGTHIS, (yyvsp[-1].expr_list) ); }
#line 4554 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tLCID '(' expr_int_const ')'  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_LIBLCID, (yyvsp[-1].expr) ); }
#line 4560 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tLCID  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARAMLCID, 0 ); }
#line 4566 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tLICENSED  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LICENSED, 0 ); }
#line 4572 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tLOCAL  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_LOCAL, 0 ); }
#line 4578 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num) ); }
#line 4584 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tMAYBE  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MAYBE, 0 ); }
#line 4590 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tMESSAGE  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_MESSAGE, 0 ); }
#line 4596 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tNOCODE  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOCODE, 0 ); }
#line 4602 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tNONBROWSABLE  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONBROWSABLE, 0 ); }
#line 4608 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tNONCREATABLE  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONCREATABLE, 0 ); }
#line 4614 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tNONEXTENSIBLE  */
#line 716 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NONEXTENSIBLE, 0 ); }
#line 4620 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tNOTIFY  */
#line 717 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFY, 0 ); }
#line 4626 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tNOTIFYFLAG  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_NOTIFYFLAG, 0 ); }
#line 4632 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tOBJECT  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OBJECT, 0 ); }
#line 4638 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tODL  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ODL, 0 ); }
#line 4644 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tOLEAUTOMATION  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OLEAUTOMATION, 0 ); }
#line 4650 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OPTIMIZE, (yyvsp[-1].str) ); }
#line 4656 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tOPTIONAL  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OPTIONAL, 0 ); }
#line 4662 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tOUT  */
#line 724 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_OUT, 0 ); }
#line 4668 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tOVERLOAD '(' aSTRING ')'  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_OVERLOAD, (yyvsp[-1].str) ); }
#line 4674 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tPARTIALIGNORE  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PARTIALIGNORE, 0 ); }
#line 4680 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERDEFAULT, (yyvsp[-1].num) ); }
#line 4686 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tPROGID '(' aSTRING ')'  */
#line 728 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_PROGID, (yyvsp[-1].str) ); }
#line 4692 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tPROPGET  */
#line 729 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPGET, 0 ); }
#line 4698 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tPROPPUT  */
#line 730 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUT, 0 ); }
#line 4704 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tPROPPUTREF  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROPPUTREF, 0 ); }
#line 4710 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tPROTECTED  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROTECTED, 0 ); }
#line 4716 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tPROXY  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PROXY, 0 ); }
#line 4722 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tPUBLIC  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_PUBLIC, 0 ); }
#line 4728 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 736 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
                                                  list = append_expr( list, (yyvsp[-1].expr) );
                                                  (yyval.attr) = attr_ptr( (yyloc), ATTR_RANGE, list );
                                                }
#line 4737 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tREADONLY  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_READONLY, 0 ); }
#line 4743 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tREPRESENTAS '(' type ')'  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_REPRESENTAS, (yyvsp[-1].type) ); }
#line 4749 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tREQUESTEDIT  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_REQUESTEDIT, 0 ); }
#line 4755 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tRESTRICTED  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RESTRICTED, 0 ); }
#line 4761 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tRETVAL  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_RETVAL, 0 ); }
#line 4767 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SIZEIS, (yyvsp[-1].expr_list) ); }
#line 4773 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tSOURCE  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_SOURCE, 0 ); }
#line 4779 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tSTATIC '(' static_attr ')'  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_STATIC, (yyvsp[-1].expr) ); }
#line 4785 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRICTCONTEXTHANDLE, 0 ); }
#line 4791 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tSTRING  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_STRING, 0 ); }
#line 4797 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tSWITCHIS '(' expr ')'  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHIS, (yyvsp[-1].expr) ); }
#line 4803 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_SWITCHTYPE, (yyvsp[-1].type) ); }
#line 4809 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tTRANSMITAS '(' type ')'  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_TRANSMITAS, (yyvsp[-1].type) ); }
#line 4815 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tTHREADING '(' threading_type ')'  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_THREADING, (yyvsp[-1].num) ); }
#line 4821 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: tUIDEFAULT  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_UIDEFAULT, 0 ); }
#line 4827 "tools/widl/parser.tab.c"
    break;

  case 213: /* attribute: tUSESGETLASTERROR  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_USESGETLASTERROR, 0 ); }
#line 4833 "tools/widl/parser.tab.c"
    break;

  case 214: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_USERMARSHAL, (yyvsp[-1].type) ); }
#line 4839 "tools/widl/parser.tab.c"
    break;

  case 215: /* attribute: tUUID '(' aUUID ')'  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_UUID, (yyvsp[-1].uuid) ); }
#line 4845 "tools/widl/parser.tab.c"
    break;

  case 216: /* attribute: tASYNCUUID '(' aUUID ')'  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_ASYNCUUID, (yyvsp[-1].uuid) ); }
#line 4851 "tools/widl/parser.tab.c"
    break;

  case 217: /* attribute: tV1ENUM  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_V1ENUM, 0 ); }
#line 4857 "tools/widl/parser.tab.c"
    break;

  case 218: /* attribute: tVARARG  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VARARG, 0 ); }
#line 4863 "tools/widl/parser.tab.c"
    break;

  case 219: /* attribute: tVERSION '(' version ')'  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_VERSION, (yyvsp[-1].num) ); }
#line 4869 "tools/widl/parser.tab.c"
    break;

  case 220: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_VIPROGID, (yyvsp[-1].str) ); }
#line 4875 "tools/widl/parser.tab.c"
    break;

  case 221: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_ptr( (yyloc), ATTR_WIREMARSHAL, (yyvsp[-1].type) ); }
#line 4881 "tools/widl/parser.tab.c"
    break;

  case 222: /* attribute: pointer_type  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_POINTERTYPE, (yyvsp[0].num) ); }
#line 4887 "tools/widl/parser.tab.c"
    break;

  case 227: /* cases: %empty  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4893 "tools/widl/parser.tab.c"
    break;

  case 228: /* cases: cases case  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4899 "tools/widl/parser.tab.c"
    break;

  case 229: /* case: tCASE expr_int_const ':' union_field  */
#line 778 "tools/widl/parser.y"
                                                { attr_t *a = attr_ptr( (yyloc), ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ) );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4908 "tools/widl/parser.tab.c"
    break;

  case 230: /* case: tDEFAULT ':' union_field  */
#line 782 "tools/widl/parser.y"
                                                { attr_t *a = attr_int( (yyloc), ATTR_DEFAULT, 0 );
                                                  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var( NULL );
                                                  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
                                                }
#line 4917 "tools/widl/parser.tab.c"
    break;

  case 231: /* enums: %empty  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4923 "tools/widl/parser.tab.c"
    break;

  case 232: /* enums: enum_list ','  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4929 "tools/widl/parser.tab.c"
    break;

  case 234: /* enum_list: enum  */
#line 794 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 235: /* enum_list: enum_list ',' enum  */
#line 798 "tools/widl/parser.y"
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
#line 4953 "tools/widl/parser.tab.c"
    break;

  case 236: /* enum_member: m_attributes ident  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4961 "tools/widl/parser.tab.c"
    break;

  case 237: /* enum: enum_member '=' expr_int_const  */
#line 815 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4970 "tools/widl/parser.tab.c"
    break;

  case 238: /* enum: enum_member  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4978 "tools/widl/parser.tab.c"
    break;

  case 239: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4984 "tools/widl/parser.tab.c"
    break;

  case 240: /* m_exprs: m_expr  */
#line 827 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4990 "tools/widl/parser.tab.c"
    break;

  case 241: /* m_exprs: m_exprs ',' m_expr  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4996 "tools/widl/parser.tab.c"
    break;

  case 242: /* m_expr: %empty  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 5002 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: aNUM  */
#line 836 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 5008 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: aHEXNUM  */
#line 837 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 5014 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: aDOUBLE  */
#line 838 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 5020 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: tFALSE  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 5026 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: tNULL  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 5032 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: tTRUE  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 5038 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: aSTRING  */
#line 842 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 5044 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: aWSTRING  */
#line 843 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 5050 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: aSQSTRING  */
#line 844 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 5056 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: aIDENTIFIER  */
#line 845 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 5062 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr '?' expr ':' expr  */
#line 846 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5068 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr LOGICALOR expr  */
#line 847 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5074 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr LOGICALAND expr  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5080 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr '|' expr  */
#line 849 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5086 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '^' expr  */
#line 850 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5092 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr '&' expr  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5098 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr EQUALITY expr  */
#line 852 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5104 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr INEQUALITY expr  */
#line 853 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5110 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr '>' expr  */
#line 854 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5116 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr '<' expr  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5122 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr GREATEREQUAL expr  */
#line 856 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5128 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: expr LESSEQUAL expr  */
#line 857 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5134 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: expr SHL expr  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5140 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr SHR expr  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5146 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: expr '+' expr  */
#line 860 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5152 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: expr '-' expr  */
#line 861 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5158 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: expr '%' expr  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5164 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: expr '*' expr  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5170 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: expr '/' expr  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5176 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: '!' expr  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 5182 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: '~' expr  */
#line 866 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 5188 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: '+' expr  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 5194 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '-' expr  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 5200 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr: '&' expr  */
#line 869 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 5206 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr: '*' expr  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 5212 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5218 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr: expr '.' aIDENTIFIER  */
#line 872 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5224 "tools/widl/parser.tab.c"
    break;

  case 281: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 874 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5230 "tools/widl/parser.tab.c"
    break;

  case 282: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 876 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5236 "tools/widl/parser.tab.c"
    break;

  case 283: /* expr: expr '[' expr ']'  */
#line 877 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5242 "tools/widl/parser.tab.c"
    break;

  case 284: /* expr: '(' expr ')'  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5248 "tools/widl/parser.tab.c"
    break;

  case 285: /* expr_list_int_const: expr_int_const  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5254 "tools/widl/parser.tab.c"
    break;

  case 286: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 882 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5260 "tools/widl/parser.tab.c"
    break;

  case 287: /* expr_int_const: expr  */
#line 885 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5269 "tools/widl/parser.tab.c"
    break;

  case 288: /* expr_const: expr  */
#line 891 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5278 "tools/widl/parser.tab.c"
    break;

  case 289: /* fields: %empty  */
#line 898 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5284 "tools/widl/parser.tab.c"
    break;

  case 290: /* fields: fields field  */
#line 899 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5290 "tools/widl/parser.tab.c"
    break;

  case 291: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 903 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5299 "tools/widl/parser.tab.c"
    break;

  case 292: /* field: m_attributes uniondef ';'  */
#line 907 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5308 "tools/widl/parser.tab.c"
    break;

  case 293: /* ne_union_field: s_field ';'  */
#line 914 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5314 "tools/widl/parser.tab.c"
    break;

  case 294: /* ne_union_field: attributes ';'  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5320 "tools/widl/parser.tab.c"
    break;

  case 295: /* ne_union_fields: %empty  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5326 "tools/widl/parser.tab.c"
    break;

  case 296: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 920 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5332 "tools/widl/parser.tab.c"
    break;

  case 297: /* union_field: s_field ';'  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5338 "tools/widl/parser.tab.c"
    break;

  case 298: /* union_field: ';'  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5344 "tools/widl/parser.tab.c"
    break;

  case 299: /* s_field: m_attributes decl_spec declarator  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5353 "tools/widl/parser.tab.c"
    break;

  case 300: /* s_field: m_attributes structdef  */
#line 932 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5362 "tools/widl/parser.tab.c"
    break;

  case 301: /* funcdef: declaration  */
#line 938 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5372 "tools/widl/parser.tab.c"
    break;

  case 302: /* declaration: attributes decl_spec init_declarator  */
#line 947 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5380 "tools/widl/parser.tab.c"
    break;

  case 303: /* declaration: decl_spec init_declarator  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5388 "tools/widl/parser.tab.c"
    break;

  case 304: /* m_ident: %empty  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5394 "tools/widl/parser.tab.c"
    break;

  case 306: /* m_typename: %empty  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5400 "tools/widl/parser.tab.c"
    break;

  case 310: /* ident: typename  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5406 "tools/widl/parser.tab.c"
    break;

  case 311: /* base_type: tBYTE  */
#line 972 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "byte" ); }
#line 5412 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tWCHAR  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "wchar_t" ); }
#line 5418 "tools/widl/parser.tab.c"
    break;

  case 314: /* base_type: tSIGNED int_std  */
#line 975 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 315: /* base_type: tUNSIGNED int_std  */
#line 976 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5430 "tools/widl/parser.tab.c"
    break;

  case 316: /* base_type: tUNSIGNED  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5436 "tools/widl/parser.tab.c"
    break;

  case 317: /* base_type: tFLOAT  */
#line 978 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "float" ); }
#line 5442 "tools/widl/parser.tab.c"
    break;

  case 318: /* base_type: tDOUBLE  */
#line 979 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "double" ); }
#line 5448 "tools/widl/parser.tab.c"
    break;

  case 319: /* base_type: tBOOLEAN  */
#line 980 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "boolean" ); }
#line 5454 "tools/widl/parser.tab.c"
    break;

  case 320: /* base_type: tERRORSTATUST  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "error_status_t" ); }
#line 5460 "tools/widl/parser.tab.c"
    break;

  case 321: /* base_type: tHANDLET  */
#line 982 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error( NULL, "handle_t" ); }
#line 5466 "tools/widl/parser.tab.c"
    break;

  case 324: /* int_std: tINT  */
#line 990 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5472 "tools/widl/parser.tab.c"
    break;

  case 325: /* int_std: tSHORT m_int  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5478 "tools/widl/parser.tab.c"
    break;

  case 326: /* int_std: tSMALL  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5484 "tools/widl/parser.tab.c"
    break;

  case 327: /* int_std: tLONG m_int  */
#line 993 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5490 "tools/widl/parser.tab.c"
    break;

  case 328: /* int_std: tHYPER m_int  */
#line 994 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5496 "tools/widl/parser.tab.c"
    break;

  case 329: /* int_std: tINT64  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5502 "tools/widl/parser.tab.c"
    break;

  case 330: /* int_std: tCHAR  */
#line 996 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5508 "tools/widl/parser.tab.c"
    break;

  case 331: /* int_std: tINT32  */
#line 997 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5514 "tools/widl/parser.tab.c"
    break;

  case 332: /* int_std: tINT3264  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5520 "tools/widl/parser.tab.c"
    break;

  case 333: /* namespace_pfx: aIDENTIFIER '.'  */
#line 1002 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5526 "tools/widl/parser.tab.c"
    break;

  case 334: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 1003 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5532 "tools/widl/parser.tab.c"
    break;

  case 335: /* qualified_type: typename  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5538 "tools/widl/parser.tab.c"
    break;

  case 336: /* qualified_type: namespace_pfx typename  */
#line 1008 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5544 "tools/widl/parser.tab.c"
    break;

  case 337: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 1012 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5550 "tools/widl/parser.tab.c"
    break;

  case 338: /* parameterized_type_arg: base_type  */
#line 1016 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5556 "tools/widl/parser.tab.c"
    break;

  case 339: /* parameterized_type_arg: qualified_type  */
#line 1017 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5562 "tools/widl/parser.tab.c"
    break;

  case 340: /* parameterized_type_arg: qualified_type '*'  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5568 "tools/widl/parser.tab.c"
    break;

  case 341: /* parameterized_type_arg: parameterized_type  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5574 "tools/widl/parser.tab.c"
    break;

  case 342: /* parameterized_type_arg: parameterized_type '*'  */
#line 1020 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5580 "tools/widl/parser.tab.c"
    break;

  case 343: /* parameterized_type_args: parameterized_type_arg  */
#line 1024 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5586 "tools/widl/parser.tab.c"
    break;

  case 344: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5592 "tools/widl/parser.tab.c"
    break;

  case 345: /* coclass: tCOCLASS typename  */
#line 1029 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5598 "tools/widl/parser.tab.c"
    break;

  case 346: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5604 "tools/widl/parser.tab.c"
    break;

  case 347: /* runtimeclass: tRUNTIMECLASS typename  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5610 "tools/widl/parser.tab.c"
    break;

  case 348: /* runtimeclass_def: attributes runtimeclass inherit '{' class_interfaces '}' semicolon_opt  */
#line 1040 "tools/widl/parser.y"
                                                { if ((yyvsp[-4].type) && type_get_type((yyvsp[-4].type)) != TYPE_RUNTIMECLASS) error_loc("%s is not a runtimeclass\n", (yyvsp[-4].type)->name);
						  (yyval.type) = type_runtimeclass_define((yyvsp[-5].type), (yyvsp[-6].attr_list), (yyvsp[-2].typeref_list)); }
#line 5617 "tools/widl/parser.tab.c"
    break;

  case 349: /* apicontract: tAPICONTRACT typename  */
#line 1044 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5623 "tools/widl/parser.tab.c"
    break;

  case 350: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5629 "tools/widl/parser.tab.c"
    break;

  case 351: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 1051 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 5635 "tools/widl/parser.tab.c"
    break;

  case 352: /* namespacedef: namespacedef '.' aIDENTIFIER  */
#line 1052 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 5641 "tools/widl/parser.tab.c"
    break;

  case 353: /* class_interfaces: %empty  */
#line 1056 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5647 "tools/widl/parser.tab.c"
    break;

  case 354: /* class_interfaces: class_interfaces class_interface  */
#line 1057 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5653 "tools/widl/parser.tab.c"
    break;

  case 355: /* class_interface: m_attributes interfaceref ';'  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5659 "tools/widl/parser.tab.c"
    break;

  case 356: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5665 "tools/widl/parser.tab.c"
    break;

  case 357: /* dispinterface: tDISPINTERFACE typename  */
#line 1065 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5671 "tools/widl/parser.tab.c"
    break;

  case 358: /* dispattributes: attributes  */
#line 1068 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[0].attr_list), attr_int( (yyloc), ATTR_DISPINTERFACE, 0 ) ); }
#line 5677 "tools/widl/parser.tab.c"
    break;

  case 359: /* dispint_props: tPROPERTIES ':'  */
#line 1071 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5683 "tools/widl/parser.tab.c"
    break;

  case 360: /* dispint_props: dispint_props s_field ';'  */
#line 1072 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5689 "tools/widl/parser.tab.c"
    break;

  case 361: /* dispint_meths: tMETHODS ':'  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5695 "tools/widl/parser.tab.c"
    break;

  case 362: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1076 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5701 "tools/widl/parser.tab.c"
    break;

  case 363: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5707 "tools/widl/parser.tab.c"
    break;

  case 364: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1083 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5713 "tools/widl/parser.tab.c"
    break;

  case 365: /* inherit: %empty  */
#line 1087 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5719 "tools/widl/parser.tab.c"
    break;

  case 366: /* inherit: ':' qualified_type  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5725 "tools/widl/parser.tab.c"
    break;

  case 367: /* inherit: ':' parameterized_type  */
#line 1089 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5731 "tools/widl/parser.tab.c"
    break;

  case 368: /* type_parameter: typename  */
#line 1092 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5737 "tools/widl/parser.tab.c"
    break;

  case 369: /* type_parameters: type_parameter  */
#line 1096 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5743 "tools/widl/parser.tab.c"
    break;

  case 370: /* type_parameters: type_parameters ',' type_parameter  */
#line 1097 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5749 "tools/widl/parser.tab.c"
    break;

  case 371: /* interface: tINTERFACE typename  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5755 "tools/widl/parser.tab.c"
    break;

  case 372: /* $@3: %empty  */
#line 1102 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5761 "tools/widl/parser.tab.c"
    break;

  case 373: /* $@4: %empty  */
#line 1102 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5767 "tools/widl/parser.tab.c"
    break;

  case 374: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5773 "tools/widl/parser.tab.c"
    break;

  case 375: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1107 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						}
#line 5781 "tools/widl/parser.tab.c"
    break;

  case 376: /* $@5: %empty  */
#line 1111 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5787 "tools/widl/parser.tab.c"
    break;

  case 377: /* $@6: %empty  */
#line 1112 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5793 "tools/widl/parser.tab.c"
    break;

  case 378: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1113 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))));
						}
#line 5801 "tools/widl/parser.tab.c"
    break;

  case 379: /* required_types: qualified_type  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5807 "tools/widl/parser.tab.c"
    break;

  case 380: /* required_types: parameterized_type  */
#line 1120 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5813 "tools/widl/parser.tab.c"
    break;

  case 381: /* required_types: required_types ',' qualified_type  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5819 "tools/widl/parser.tab.c"
    break;

  case 382: /* required_types: required_types ',' parameterized_type  */
#line 1122 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5825 "tools/widl/parser.tab.c"
    break;

  case 383: /* requires: %empty  */
#line 1126 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5831 "tools/widl/parser.tab.c"
    break;

  case 384: /* requires: tREQUIRES required_types  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5837 "tools/widl/parser.tab.c"
    break;

  case 385: /* $@7: %empty  */
#line 1130 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5843 "tools/widl/parser.tab.c"
    break;

  case 386: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1132 "tools/widl/parser.y"
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
#line 5859 "tools/widl/parser.tab.c"
    break;

  case 387: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5865 "tools/widl/parser.tab.c"
    break;

  case 388: /* interfaceref: tINTERFACE typename  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5871 "tools/widl/parser.tab.c"
    break;

  case 389: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5877 "tools/widl/parser.tab.c"
    break;

  case 390: /* interfaceref: tINTERFACE parameterized_type  */
#line 1149 "tools/widl/parser.y"
                                                { if (type_get_type(((yyval.type) = (yyvsp[0].type))) != TYPE_INTERFACE) error_loc("%s is not an interface\n", (yyval.type)->name); }
#line 5883 "tools/widl/parser.tab.c"
    break;

  case 391: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5889 "tools/widl/parser.tab.c"
    break;

  case 392: /* module: tMODULE typename  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5895 "tools/widl/parser.tab.c"
    break;

  case 393: /* moduledef: m_attributes module '{' int_statements '}' semicolon_opt  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5901 "tools/widl/parser.tab.c"
    break;

  case 394: /* storage_cls_spec: tEXTERN  */
#line 1164 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5907 "tools/widl/parser.tab.c"
    break;

  case 395: /* storage_cls_spec: tSTATIC  */
#line 1165 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5913 "tools/widl/parser.tab.c"
    break;

  case 396: /* storage_cls_spec: tREGISTER  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5919 "tools/widl/parser.tab.c"
    break;

  case 397: /* function_specifier: tINLINE  */
#line 1170 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5925 "tools/widl/parser.tab.c"
    break;

  case 398: /* type_qualifier: tCONST  */
#line 1174 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5931 "tools/widl/parser.tab.c"
    break;

  case 399: /* m_type_qual_list: %empty  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5937 "tools/widl/parser.tab.c"
    break;

  case 400: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1179 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5943 "tools/widl/parser.tab.c"
    break;

  case 401: /* decl_spec: type m_decl_spec_no_type  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5949 "tools/widl/parser.tab.c"
    break;

  case 402: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1184 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5955 "tools/widl/parser.tab.c"
    break;

  case 403: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5961 "tools/widl/parser.tab.c"
    break;

  case 404: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1190 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5967 "tools/widl/parser.tab.c"
    break;

  case 405: /* m_decl_spec_no_type: %empty  */
#line 1194 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5973 "tools/widl/parser.tab.c"
    break;

  case 407: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1199 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5979 "tools/widl/parser.tab.c"
    break;

  case 408: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1200 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5985 "tools/widl/parser.tab.c"
    break;

  case 409: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5991 "tools/widl/parser.tab.c"
    break;

  case 410: /* declarator: '*' m_type_qual_list declarator  */
#line 1206 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5997 "tools/widl/parser.tab.c"
    break;

  case 411: /* declarator: callconv declarator  */
#line 1207 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6003 "tools/widl/parser.tab.c"
    break;

  case 413: /* direct_declarator: ident  */
#line 1212 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 6009 "tools/widl/parser.tab.c"
    break;

  case 414: /* direct_declarator: '(' declarator ')'  */
#line 1213 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6015 "tools/widl/parser.tab.c"
    break;

  case 415: /* direct_declarator: direct_declarator array  */
#line 1214 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6021 "tools/widl/parser.tab.c"
    break;

  case 416: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1215 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 6027 "tools/widl/parser.tab.c"
    break;

  case 417: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1221 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6033 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6039 "tools/widl/parser.tab.c"
    break;

  case 420: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6045 "tools/widl/parser.tab.c"
    break;

  case 421: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1230 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6051 "tools/widl/parser.tab.c"
    break;

  case 422: /* m_abstract_declarator: %empty  */
#line 1235 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6057 "tools/widl/parser.tab.c"
    break;

  case 424: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1241 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6063 "tools/widl/parser.tab.c"
    break;

  case 425: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1242 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6069 "tools/widl/parser.tab.c"
    break;

  case 426: /* abstract_direct_declarator: array  */
#line 1243 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6075 "tools/widl/parser.tab.c"
    break;

  case 427: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6083 "tools/widl/parser.tab.c"
    break;

  case 428: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1249 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6091 "tools/widl/parser.tab.c"
    break;

  case 429: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1257 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6097 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_declarator: callconv m_any_declarator  */
#line 1258 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6103 "tools/widl/parser.tab.c"
    break;

  case 432: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 6109 "tools/widl/parser.tab.c"
    break;

  case 433: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1266 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv( (yyloc), (yyval.declarator)->type, (yyvsp[-1].str) ); }
#line 6115 "tools/widl/parser.tab.c"
    break;

  case 434: /* m_any_declarator: %empty  */
#line 1271 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 6121 "tools/widl/parser.tab.c"
    break;

  case 436: /* any_direct_declarator: ident  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 6127 "tools/widl/parser.tab.c"
    break;

  case 437: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 6133 "tools/widl/parser.tab.c"
    break;

  case 438: /* any_direct_declarator: any_direct_declarator array  */
#line 1281 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6139 "tools/widl/parser.tab.c"
    break;

  case 439: /* any_direct_declarator: array  */
#line 1282 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 6145 "tools/widl/parser.tab.c"
    break;

  case 440: /* any_direct_declarator: '(' m_args ')'  */
#line 1284 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6153 "tools/widl/parser.tab.c"
    break;

  case 441: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1288 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6161 "tools/widl/parser.tab.c"
    break;

  case 442: /* declarator_list: declarator  */
#line 1294 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6167 "tools/widl/parser.tab.c"
    break;

  case 443: /* declarator_list: declarator_list ',' declarator  */
#line 1295 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6173 "tools/widl/parser.tab.c"
    break;

  case 444: /* m_bitfield: %empty  */
#line 1299 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 6179 "tools/widl/parser.tab.c"
    break;

  case 445: /* m_bitfield: ':' expr_const  */
#line 1300 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 6185 "tools/widl/parser.tab.c"
    break;

  case 446: /* struct_declarator: any_declarator m_bitfield  */
#line 1303 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 6194 "tools/widl/parser.tab.c"
    break;

  case 447: /* struct_declarator_list: struct_declarator  */
#line 1310 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6200 "tools/widl/parser.tab.c"
    break;

  case 448: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1312 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6206 "tools/widl/parser.tab.c"
    break;

  case 449: /* init_declarator: declarator  */
#line 1316 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 6212 "tools/widl/parser.tab.c"
    break;

  case 450: /* init_declarator: declarator '=' expr_const  */
#line 1317 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 6218 "tools/widl/parser.tab.c"
    break;

  case 451: /* threading_type: tAPARTMENT  */
#line 1321 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 6224 "tools/widl/parser.tab.c"
    break;

  case 452: /* threading_type: tNEUTRAL  */
#line 1322 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6230 "tools/widl/parser.tab.c"
    break;

  case 453: /* threading_type: tSINGLE  */
#line 1323 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6236 "tools/widl/parser.tab.c"
    break;

  case 454: /* threading_type: tFREE  */
#line 1324 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6242 "tools/widl/parser.tab.c"
    break;

  case 455: /* threading_type: tBOTH  */
#line 1325 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6248 "tools/widl/parser.tab.c"
    break;

  case 456: /* threading_type: tMTA  */
#line 1326 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6254 "tools/widl/parser.tab.c"
    break;

  case 457: /* pointer_type: tREF  */
#line 1330 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6260 "tools/widl/parser.tab.c"
    break;

  case 458: /* pointer_type: tUNIQUE  */
#line 1331 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6266 "tools/widl/parser.tab.c"
    break;

  case 459: /* pointer_type: tPTR  */
#line 1332 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6272 "tools/widl/parser.tab.c"
    break;

  case 460: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1335 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6278 "tools/widl/parser.tab.c"
    break;

  case 461: /* unqualified_type: tVOID  */
#line 1339 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6284 "tools/widl/parser.tab.c"
    break;

  case 462: /* unqualified_type: base_type  */
#line 1340 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6290 "tools/widl/parser.tab.c"
    break;

  case 463: /* unqualified_type: enumdef  */
#line 1341 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6296 "tools/widl/parser.tab.c"
    break;

  case 464: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1342 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6302 "tools/widl/parser.tab.c"
    break;

  case 465: /* unqualified_type: structdef  */
#line 1343 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6308 "tools/widl/parser.tab.c"
    break;

  case 466: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1344 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6314 "tools/widl/parser.tab.c"
    break;

  case 467: /* unqualified_type: uniondef  */
#line 1345 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6320 "tools/widl/parser.tab.c"
    break;

  case 468: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1346 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6326 "tools/widl/parser.tab.c"
    break;

  case 469: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1347 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6332 "tools/widl/parser.tab.c"
    break;

  case 470: /* unqualified_type: aKNOWNTYPE  */
#line 1348 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6338 "tools/widl/parser.tab.c"
    break;

  case 472: /* type: namespace_pfx typename  */
#line 1353 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6344 "tools/widl/parser.tab.c"
    break;

  case 473: /* type: parameterized_type  */
#line 1354 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6350 "tools/widl/parser.tab.c"
    break;

  case 474: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1358 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs( (yyloc), (yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs( (yyvsp[-4].attr_list) ) );
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6359 "tools/widl/parser.tab.c"
    break;

  case 475: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1365 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6365 "tools/widl/parser.tab.c"
    break;

  case 476: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1368 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6371 "tools/widl/parser.tab.c"
    break;

  case 477: /* version: aNUM  */
#line 1372 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6377 "tools/widl/parser.tab.c"
    break;

  case 478: /* version: aNUM '.' aNUM  */
#line 1373 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6383 "tools/widl/parser.tab.c"
    break;

  case 479: /* version: aHEXNUM  */
#line 1374 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6389 "tools/widl/parser.tab.c"
    break;

  case 484: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1389 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6397 "tools/widl/parser.tab.c"
    break;

  case 485: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1396 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6407 "tools/widl/parser.tab.c"
    break;

  case 486: /* acf_attributes: %empty  */
#line 1404 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6413 "tools/widl/parser.tab.c"
    break;

  case 487: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1405 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6419 "tools/widl/parser.tab.c"
    break;

  case 488: /* acf_attribute_list: acf_attribute  */
#line 1409 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6425 "tools/widl/parser.tab.c"
    break;

  case 489: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1410 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6431 "tools/widl/parser.tab.c"
    break;

  case 490: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1415 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ALLOCATE, (yyvsp[-1].num) ); }
#line 6437 "tools/widl/parser.tab.c"
    break;

  case 491: /* acf_attribute: tENCODE  */
#line 1416 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_ENCODE, 0 ); }
#line 6443 "tools/widl/parser.tab.c"
    break;

  case 492: /* acf_attribute: tDECODE  */
#line 1417 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_DECODE, 0 ); }
#line 6449 "tools/widl/parser.tab.c"
    break;

  case 493: /* acf_attribute: tEXPLICITHANDLE  */
#line 1418 "tools/widl/parser.y"
                                                { (yyval.attr) = attr_int( (yyloc), ATTR_EXPLICIT_HANDLE, 0 ); }
#line 6455 "tools/widl/parser.tab.c"
    break;

  case 494: /* allocate_option_list: allocate_option  */
#line 1422 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6461 "tools/widl/parser.tab.c"
    break;

  case 495: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1424 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6467 "tools/widl/parser.tab.c"
    break;

  case 496: /* allocate_option: tDONTFREE  */
#line 1428 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6473 "tools/widl/parser.tab.c"
    break;

  case 497: /* allocate_option: tFREE  */
#line 1429 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6479 "tools/widl/parser.tab.c"
    break;

  case 498: /* allocate_option: tALLNODES  */
#line 1430 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6485 "tools/widl/parser.tab.c"
    break;

  case 499: /* allocate_option: tSINGLENODE  */
#line 1431 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6491 "tools/widl/parser.tab.c"
    break;


#line 6495 "tools/widl/parser.tab.c"

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

#line 1434 "tools/widl/parser.y"


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
