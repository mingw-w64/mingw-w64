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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Substitute the type names.  */
#define YYSTYPE         PARSER_STYPE
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
static attr_t *make_custom_attr(struct uuid *id, expr_t *pval);
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


#line 202 "tools/widl/parser.tab.c"

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
    tOVERLOAD = 398,               /* tOVERLOAD  */
    tPARTIALIGNORE = 399,          /* tPARTIALIGNORE  */
    tPASCAL = 400,                 /* tPASCAL  */
    tPOINTERDEFAULT = 401,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 402,         /* tPRAGMA_WARNING  */
    tPROGID = 403,                 /* tPROGID  */
    tPROPERTIES = 404,             /* tPROPERTIES  */
    tPROPGET = 405,                /* tPROPGET  */
    tPROPPUT = 406,                /* tPROPPUT  */
    tPROPPUTREF = 407,             /* tPROPPUTREF  */
    tPROXY = 408,                  /* tPROXY  */
    tPTR = 409,                    /* tPTR  */
    tPUBLIC = 410,                 /* tPUBLIC  */
    tRANGE = 411,                  /* tRANGE  */
    tREADONLY = 412,               /* tREADONLY  */
    tREF = 413,                    /* tREF  */
    tREGISTER = 414,               /* tREGISTER  */
    tREPRESENTAS = 415,            /* tREPRESENTAS  */
    tREQUESTEDIT = 416,            /* tREQUESTEDIT  */
    tREQUIRES = 417,               /* tREQUIRES  */
    tRESTRICTED = 418,             /* tRESTRICTED  */
    tRETVAL = 419,                 /* tRETVAL  */
    tRUNTIMECLASS = 420,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 421,              /* tSAFEARRAY  */
    tSHORT = 422,                  /* tSHORT  */
    tSIGNED = 423,                 /* tSIGNED  */
    tSINGLENODE = 424,             /* tSINGLENODE  */
    tSIZEIS = 425,                 /* tSIZEIS  */
    tSIZEOF = 426,                 /* tSIZEOF  */
    tSMALL = 427,                  /* tSMALL  */
    tSOURCE = 428,                 /* tSOURCE  */
    tSTANDARD = 429,               /* tSTANDARD  */
    tSTATIC = 430,                 /* tSTATIC  */
    tSTDCALL = 431,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 432,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 433,                 /* tSTRING  */
    tSTRUCT = 434,                 /* tSTRUCT  */
    tSWITCH = 435,                 /* tSWITCH  */
    tSWITCHIS = 436,               /* tSWITCHIS  */
    tSWITCHTYPE = 437,             /* tSWITCHTYPE  */
    tTHREADING = 438,              /* tTHREADING  */
    tTRANSMITAS = 439,             /* tTRANSMITAS  */
    tTRUE = 440,                   /* tTRUE  */
    tTYPEDEF = 441,                /* tTYPEDEF  */
    tUIDEFAULT = 442,              /* tUIDEFAULT  */
    tUNION = 443,                  /* tUNION  */
    tUNIQUE = 444,                 /* tUNIQUE  */
    tUNSIGNED = 445,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 446,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 447,            /* tUSERMARSHAL  */
    tUUID = 448,                   /* tUUID  */
    tV1ENUM = 449,                 /* tV1ENUM  */
    tVARARG = 450,                 /* tVARARG  */
    tVERSION = 451,                /* tVERSION  */
    tVIPROGID = 452,               /* tVIPROGID  */
    tVOID = 453,                   /* tVOID  */
    tWCHAR = 454,                  /* tWCHAR  */
    tWIREMARSHAL = 455,            /* tWIREMARSHAL  */
    tAPARTMENT = 456,              /* tAPARTMENT  */
    tNEUTRAL = 457,                /* tNEUTRAL  */
    tSINGLE = 458,                 /* tSINGLE  */
    tFREE = 459,                   /* tFREE  */
    tBOTH = 460,                   /* tBOTH  */
    CAST = 461,                    /* CAST  */
    PPTR = 462,                    /* PPTR  */
    POS = 463,                     /* POS  */
    NEG = 464,                     /* NEG  */
    ADDRESSOF = 465                /* ADDRESSOF  */
  };
  typedef enum parser_tokentype parser_token_kind_t;
#endif

/* Value type.  */
#if ! defined PARSER_STYPE && ! defined PARSER_STYPE_IS_DECLARED
union PARSER_STYPE
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

#line 497 "tools/widl/parser.tab.c"

};
typedef union PARSER_STYPE PARSER_STYPE;
# define PARSER_STYPE_IS_TRIVIAL 1
# define PARSER_STYPE_IS_DECLARED 1
#endif


extern PARSER_STYPE parser_lval;


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
  YYSYMBOL_tOVERLOAD = 143,                /* tOVERLOAD  */
  YYSYMBOL_tPARTIALIGNORE = 144,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 145,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 146,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 147,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 148,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 149,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 150,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 151,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 152,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 153,                   /* tPROXY  */
  YYSYMBOL_tPTR = 154,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 155,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 156,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 157,                /* tREADONLY  */
  YYSYMBOL_tREF = 158,                     /* tREF  */
  YYSYMBOL_tREGISTER = 159,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 160,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 161,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 162,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 163,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 164,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 165,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 166,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 167,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 168,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 169,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 170,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 171,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 172,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 173,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 174,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 175,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 176,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 177,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 178,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 179,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 180,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 181,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 182,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 183,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 184,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 185,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 186,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 187,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 188,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 189,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 190,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 191,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 192,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 193,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 194,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 195,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 196,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 197,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 198,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 199,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 200,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 201,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 202,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 203,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 204,                    /* tFREE  */
  YYSYMBOL_tBOTH = 205,                    /* tBOTH  */
  YYSYMBOL_206_ = 206,                     /* ','  */
  YYSYMBOL_207_ = 207,                     /* '?'  */
  YYSYMBOL_208_ = 208,                     /* ':'  */
  YYSYMBOL_209_ = 209,                     /* '|'  */
  YYSYMBOL_210_ = 210,                     /* '^'  */
  YYSYMBOL_211_ = 211,                     /* '&'  */
  YYSYMBOL_212_ = 212,                     /* '<'  */
  YYSYMBOL_213_ = 213,                     /* '>'  */
  YYSYMBOL_214_ = 214,                     /* '-'  */
  YYSYMBOL_215_ = 215,                     /* '+'  */
  YYSYMBOL_216_ = 216,                     /* '*'  */
  YYSYMBOL_217_ = 217,                     /* '/'  */
  YYSYMBOL_218_ = 218,                     /* '%'  */
  YYSYMBOL_219_ = 219,                     /* '!'  */
  YYSYMBOL_220_ = 220,                     /* '~'  */
  YYSYMBOL_CAST = 221,                     /* CAST  */
  YYSYMBOL_PPTR = 222,                     /* PPTR  */
  YYSYMBOL_POS = 223,                      /* POS  */
  YYSYMBOL_NEG = 224,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 225,                /* ADDRESSOF  */
  YYSYMBOL_226_ = 226,                     /* '.'  */
  YYSYMBOL_227_ = 227,                     /* '['  */
  YYSYMBOL_228_ = 228,                     /* ']'  */
  YYSYMBOL_229_ = 229,                     /* ';'  */
  YYSYMBOL_230_ = 230,                     /* '{'  */
  YYSYMBOL_231_ = 231,                     /* '}'  */
  YYSYMBOL_232_ = 232,                     /* '('  */
  YYSYMBOL_233_ = 233,                     /* ')'  */
  YYSYMBOL_234_ = 234,                     /* '='  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_input = 236,                    /* input  */
  YYSYMBOL_m_acf = 237,                    /* m_acf  */
  YYSYMBOL_decl_statements = 238,          /* decl_statements  */
  YYSYMBOL_decl_block = 239,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 240,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 241,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 242,           /* gbl_statements  */
  YYSYMBOL_243_1 = 243,                    /* $@1  */
  YYSYMBOL_imp_statements = 244,           /* imp_statements  */
  YYSYMBOL_245_2 = 245,                    /* $@2  */
  YYSYMBOL_int_statements = 246,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 247,            /* semicolon_opt  */
  YYSYMBOL_statement = 248,                /* statement  */
  YYSYMBOL_pragma_warning = 249,           /* pragma_warning  */
  YYSYMBOL_warnings = 250,                 /* warnings  */
  YYSYMBOL_typedecl = 251,                 /* typedecl  */
  YYSYMBOL_cppquote = 252,                 /* cppquote  */
  YYSYMBOL_import_start = 253,             /* import_start  */
  YYSYMBOL_import = 254,                   /* import  */
  YYSYMBOL_importlib = 255,                /* importlib  */
  YYSYMBOL_libraryhdr = 256,               /* libraryhdr  */
  YYSYMBOL_library_start = 257,            /* library_start  */
  YYSYMBOL_librarydef = 258,               /* librarydef  */
  YYSYMBOL_m_args = 259,                   /* m_args  */
  YYSYMBOL_arg_list = 260,                 /* arg_list  */
  YYSYMBOL_args = 261,                     /* args  */
  YYSYMBOL_arg = 262,                      /* arg  */
  YYSYMBOL_array = 263,                    /* array  */
  YYSYMBOL_m_attributes = 264,             /* m_attributes  */
  YYSYMBOL_attributes = 265,               /* attributes  */
  YYSYMBOL_attrib_list = 266,              /* attrib_list  */
  YYSYMBOL_str_list = 267,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 268,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 269,             /* contract_ver  */
  YYSYMBOL_contract_req = 270,             /* contract_req  */
  YYSYMBOL_static_attr = 271,              /* static_attr  */
  YYSYMBOL_activatable_attr = 272,         /* activatable_attr  */
  YYSYMBOL_attribute = 273,                /* attribute  */
  YYSYMBOL_uuid_string = 274,              /* uuid_string  */
  YYSYMBOL_callconv = 275,                 /* callconv  */
  YYSYMBOL_cases = 276,                    /* cases  */
  YYSYMBOL_case = 277,                     /* case  */
  YYSYMBOL_enums = 278,                    /* enums  */
  YYSYMBOL_enum_list = 279,                /* enum_list  */
  YYSYMBOL_enum_member = 280,              /* enum_member  */
  YYSYMBOL_enum = 281,                     /* enum  */
  YYSYMBOL_enumdef = 282,                  /* enumdef  */
  YYSYMBOL_m_exprs = 283,                  /* m_exprs  */
  YYSYMBOL_m_expr = 284,                   /* m_expr  */
  YYSYMBOL_expr = 285,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 286,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 287,           /* expr_int_const  */
  YYSYMBOL_expr_const = 288,               /* expr_const  */
  YYSYMBOL_fields = 289,                   /* fields  */
  YYSYMBOL_field = 290,                    /* field  */
  YYSYMBOL_ne_union_field = 291,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 292,          /* ne_union_fields  */
  YYSYMBOL_union_field = 293,              /* union_field  */
  YYSYMBOL_s_field = 294,                  /* s_field  */
  YYSYMBOL_funcdef = 295,                  /* funcdef  */
  YYSYMBOL_declaration = 296,              /* declaration  */
  YYSYMBOL_m_ident = 297,                  /* m_ident  */
  YYSYMBOL_m_typename = 298,               /* m_typename  */
  YYSYMBOL_typename = 299,                 /* typename  */
  YYSYMBOL_ident = 300,                    /* ident  */
  YYSYMBOL_base_type = 301,                /* base_type  */
  YYSYMBOL_m_int = 302,                    /* m_int  */
  YYSYMBOL_int_std = 303,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 304,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 305,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 306,       /* parameterized_type  */
  YYSYMBOL_parameterized_type_arg = 307,   /* parameterized_type_arg  */
  YYSYMBOL_parameterized_type_args = 308,  /* parameterized_type_args  */
  YYSYMBOL_coclass = 309,                  /* coclass  */
  YYSYMBOL_coclassdef = 310,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 311,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 312,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 313,              /* apicontract  */
  YYSYMBOL_apicontract_def = 314,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 315,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 316,         /* class_interfaces  */
  YYSYMBOL_class_interface = 317,          /* class_interface  */
  YYSYMBOL_dispinterface = 318,            /* dispinterface  */
  YYSYMBOL_dispattributes = 319,           /* dispattributes  */
  YYSYMBOL_dispint_props = 320,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 321,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 322,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 323,                  /* inherit  */
  YYSYMBOL_type_parameter = 324,           /* type_parameter  */
  YYSYMBOL_type_parameters = 325,          /* type_parameters  */
  YYSYMBOL_interface = 326,                /* interface  */
  YYSYMBOL_327_3 = 327,                    /* $@3  */
  YYSYMBOL_328_4 = 328,                    /* $@4  */
  YYSYMBOL_delegatedef = 329,              /* delegatedef  */
  YYSYMBOL_330_5 = 330,                    /* $@5  */
  YYSYMBOL_331_6 = 331,                    /* $@6  */
  YYSYMBOL_required_types = 332,           /* required_types  */
  YYSYMBOL_requires = 333,                 /* requires  */
  YYSYMBOL_interfacedef = 334,             /* interfacedef  */
  YYSYMBOL_335_7 = 335,                    /* $@7  */
  YYSYMBOL_interfaceref = 336,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 337,         /* dispinterfaceref  */
  YYSYMBOL_module = 338,                   /* module  */
  YYSYMBOL_moduledef = 339,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 340,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 341,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 342,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 343,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 344,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 345,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 346,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 347,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 348,               /* declarator  */
  YYSYMBOL_direct_declarator = 349,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 350,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 351, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 352,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 353, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 354,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 355, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 356,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 357,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 358,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 359,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 360,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 361,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 362,          /* init_declarator  */
  YYSYMBOL_threading_type = 363,           /* threading_type  */
  YYSYMBOL_pointer_type = 364,             /* pointer_type  */
  YYSYMBOL_structdef = 365,                /* structdef  */
  YYSYMBOL_unqualified_type = 366,         /* unqualified_type  */
  YYSYMBOL_type = 367,                     /* type  */
  YYSYMBOL_typedef = 368,                  /* typedef  */
  YYSYMBOL_uniondef = 369,                 /* uniondef  */
  YYSYMBOL_version = 370,                  /* version  */
  YYSYMBOL_acf_statements = 371,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 372,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 373,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 374,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 375,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 376,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 377,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 378,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 379           /* allocate_option  */
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
         || (defined PARSER_STYPE_IS_TRIVIAL && PARSER_STYPE_IS_TRIVIAL)))

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
#define YYLAST   3873

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  145
/* YYNRULES -- Number of rules.  */
#define YYNRULES  492
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  901

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   465


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
       2,     2,     2,   219,     2,     2,     2,   218,   211,     2,
     232,   233,   216,   215,   206,   214,   226,   217,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   208,   229,
     212,   234,   213,   207,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   227,     2,   228,   210,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   230,   209,   231,   220,     2,     2,     2,
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
     205,   221,   222,   223,   224,   225
};

#if PARSER_DEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   354,   354,   369,   369,   371,   372,   378,   380,   381,
     385,   387,   388,   388,   390,   391,   392,   393,   394,   397,
     400,   401,   403,   404,   406,   407,   408,   409,   412,   413,
     414,   415,   415,   417,   418,   419,   420,   423,   424,   426,
     427,   429,   430,   431,   432,   433,   436,   437,   440,   441,
     445,   446,   447,   448,   449,   450,   451,   454,   462,   470,
     471,   475,   476,   477,   478,   479,   480,   481,   482,   483,
     486,   488,   495,   501,   505,   507,   511,   515,   516,   519,
     520,   523,   524,   528,   533,   540,   544,   545,   548,   549,
     553,   556,   557,   558,   561,   562,   566,   567,   568,   572,
     573,   576,   582,   588,   592,   594,   595,   596,   597,   598,
     599,   600,   601,   602,   603,   604,   605,   606,   607,   608,
     609,   610,   611,   612,   613,   614,   615,   616,   617,   618,
     619,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   633,   634,   635,   636,   637,   638,   639,   640,
     641,   642,   643,   644,   645,   646,   647,   648,   649,   650,
     651,   652,   653,   654,   655,   656,   657,   659,   660,   661,
     662,   663,   664,   665,   666,   667,   668,   669,   670,   671,
     672,   673,   674,   675,   676,   677,   678,   679,   680,   681,
     682,   686,   687,   688,   689,   690,   691,   692,   693,   694,
     695,   696,   697,   698,   699,   700,   701,   702,   703,   704,
     705,   706,   707,   708,   709,   710,   714,   715,   720,   721,
     722,   723,   726,   727,   730,   734,   740,   741,   742,   745,
     749,   761,   766,   770,   775,   778,   779,   782,   783,   786,
     787,   788,   789,   790,   791,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   803,   804,   805,   806,
     807,   808,   809,   810,   811,   812,   813,   814,   815,   816,
     817,   818,   819,   820,   821,   822,   823,   825,   827,   828,
     831,   832,   835,   841,   847,   848,   851,   856,   863,   864,
     867,   868,   872,   873,   876,   880,   886,   894,   898,   903,
     904,   907,   908,   911,   912,   915,   918,   919,   920,   921,
     922,   923,   924,   925,   926,   927,   928,   931,   932,   935,
     936,   937,   938,   939,   940,   941,   942,   943,   947,   948,
     952,   953,   956,   961,   962,   963,   964,   965,   969,   970,
     974,   977,   981,   984,   988,   991,   995,   998,   999,  1003,
    1004,  1007,  1010,  1013,  1014,  1017,  1018,  1022,  1024,  1028,
    1029,  1030,  1033,  1037,  1038,  1042,  1043,  1043,  1043,  1047,
    1052,  1053,  1051,  1060,  1061,  1062,  1063,  1065,  1066,  1069,
    1069,  1082,  1086,  1087,  1091,  1094,  1097,  1102,  1103,  1104,
    1108,  1112,  1115,  1116,  1119,  1120,  1124,  1126,  1130,  1131,
    1135,  1136,  1137,  1141,  1143,  1144,  1148,  1149,  1150,  1151,
    1156,  1158,  1159,  1164,  1166,  1170,  1171,  1176,  1177,  1178,
    1179,  1183,  1191,  1193,  1194,  1199,  1201,  1205,  1206,  1213,
    1214,  1215,  1216,  1217,  1221,  1228,  1229,  1232,  1233,  1236,
    1243,  1244,  1249,  1250,  1254,  1255,  1256,  1257,  1258,  1259,
    1263,  1264,  1265,  1268,  1272,  1273,  1274,  1275,  1276,  1277,
    1278,  1279,  1280,  1281,  1285,  1286,  1287,  1290,  1297,  1299,
    1305,  1306,  1307,  1311,  1312,  1316,  1317,  1321,  1328,  1337,
    1338,  1342,  1343,  1347,  1349,  1350,  1351,  1355,  1356,  1361,
    1362,  1363,  1364
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
  "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tOVERLOAD",
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
  "activatable_attr", "attribute", "uuid_string", "callconv", "cases",
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

#define YYPACT_NINF (-646)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-480)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -646,   119,  1924,  -646,   -93,  -646,   -51,   -33,   307,  -646,
    -646,  -646,   307,  -646,   -47,   -37,   307,  -646,   308,  -646,
    -646,  -646,  -646,    96,   190,  -646,  -646,  -646,  -646,  -646,
     307,    96,   210,   -12,  -646,   307,    18,    96,   385,  -646,
    -646,   338,   392,   385,  -646,  -646,  3673,  -646,  -646,  -646,
    -646,    33,  -646,  -646,  -646,  -646,  -646,     0,  3007,   104,
     117,  -646,  -646,  -646,   396,    69,  -646,   120,  -646,   154,
    -646,   165,  -646,    93,   169,   206,   178,   202,  -646,  -646,
    -646,   296,   296,   296,   118,  3263,   204,  -646,   296,   205,
     207,  -646,    65,  -646,   -33,   244,  -646,  -646,  -646,  -646,
     357,  -646,  -646,    12,   143,  -646,  -646,  -646,   208,   168,
    -646,  -646,    86,  -646,  3263,  -646,  -646,   193,   189,   -88,
     -81,  -646,   158,  -646,   203,  -646,  -646,   209,  -646,  -646,
    -646,   212,   213,  -646,  -646,  -646,  -646,  -646,   214,   215,
    -646,   220,  -646,  -646,  -646,  -646,   224,  -646,  -646,  -646,
     225,  -646,  -646,  -646,   227,   230,  -646,  -646,   234,  -646,
    -646,  -646,  -646,  -646,   235,   238,   241,   242,   243,  -646,
     245,  -646,  -646,   246,  -646,   247,  -646,  -646,   249,   252,
    -646,  -646,   253,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,   254,  -646,  -646,   256,  -646,   257,
     258,  -646,  -646,  -646,  -646,  -646,  -646,   259,  -646,  -646,
     260,  -646,  -646,  -646,   261,  -646,   262,  -646,  -646,   263,
     268,   269,   270,  -646,  -646,  -646,   271,   272,  -646,  -646,
     273,   275,   276,   -63,  -646,  -646,  -646,  2071,  1122,  3263,
     307,   211,   279,   399,   307,   405,   415,   280,   282,   283,
     284,   286,  -646,   118,   289,   293,  -646,   216,   228,  3366,
    -646,  -646,  -646,  -646,  -646,   294,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,   118,   118,
    -646,  -646,   278,   -16,  -646,  -646,  -646,   296,  -646,  -646,
    -646,   291,  -646,  -646,  -646,   -58,  -646,  -646,   520,   302,
     -49,   113,  -646,  -646,   318,   331,   309,  -646,   313,  -646,
    3234,   532,   151,   307,   928,  3234,   540,   151,   928,   542,
     546,   928,  3234,   928,   549,   550,   928,   551,   928,   928,
    2577,   928,   928,    44,   555,   557,   -45,   558,   928,  3263,
     928,  3234,   928,  3263,   134,  3263,  3263,   151,   223,   560,
    3263,  3673,   345,  -646,   344,   353,  -646,  -646,  -646,  -646,
     358,  -646,   359,  -646,   360,  -646,   361,   363,   364,  -646,
    -646,  -646,   178,   307,  -646,  3234,  -646,  -646,   365,  -646,
     365,   -74,  -646,  -646,  -646,   366,   386,  -646,  -646,  -646,
     396,    80,   380,  -646,   -91,  -646,     2,   115,   367,  -646,
     928,   807,  2577,  -646,  -646,    55,    65,  -646,   369,  -646,
     423,  -646,   307,   371,   397,   370,  -646,   307,   599,   599,
    -646,   129,   211,   130,  -646,   373,   401,   375,  -646,  -646,
     376,   377,  -646,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
    -646,   381,  -646,   928,   928,   928,   928,   928,   928,   877,
    2790,  -104,  -646,   388,   408,   398,   390,   412,  2790,   393,
     394,  -646,   -99,   400,   402,   407,   410,   411,   413,   417,
     418,  1668,   420,  3234,    88,   422,   -95,  -646,  2790,  -646,
    -646,  -646,   424,   425,   427,   428,   429,   419,   430,   -76,
     432,   426,  2391,   433,  -646,  -646,  -646,  -646,  -646,  -646,
     434,   435,   437,   439,   403,  -646,   440,   441,   442,  -646,
    3673,  -646,   629,  -646,  -646,  -646,  -646,  -646,  -646,  -646,
     -57,   118,  1551,   131,   144,   178,   423,   486,  -646,  -646,
    -646,  3366,  -646,  1414,   469,   -50,   449,  -646,  -646,  -646,
    -646,   866,  -646,  2687,   446,   474,  -646,  -646,  -646,  -646,
    -646,  -646,   -66,  -646,  -646,   495,   470,  -646,  -646,   161,
     928,  -646,  -646,   477,  -646,    53,    62,  -646,  3234,  -646,
    3234,   451,  -646,   456,  -646,   458,  -646,  3131,  -646,  -646,
    -646,  3411,    73,    73,    73,    73,    73,    73,  -646,  2467,
     233,  3514,   296,   928,   928,   685,   928,   928,   928,   928,
     928,   928,   928,   928,   928,   928,   928,   928,   928,   928,
     928,   928,   928,   686,   928,   928,  -646,  -646,   540,   688,
    -646,   928,  -646,  -646,   682,  -646,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,  -646,  -646,  -646,    88,  -646,  2203,  -646,
      88,  -646,  -646,  -646,    87,  -646,   928,  -646,  -646,  -646,
    -646,  -646,  -646,   928,  -646,  -646,  -646,  3234,  -646,  -646,
    -646,  -646,  -646,  -646,   690,  -646,  -646,  -646,  -646,   -39,
     465,  -646,  -646,  2577,  -646,   497,   178,  -646,   518,  3234,
     178,    59,  -646,   178,  -646,    69,  -646,   423,   476,  -646,
    -646,  -646,   502,   483,  1778,   482,  -646,  -646,  -646,  2474,
      55,  -646,   487,   484,   495,  3366,  -646,  -646,   307,   503,
    -646,  -646,  -646,    88,   488,   118,   160,   307,  -646,  -646,
    -646,  -646,   233,  -646,  -646,  2350,  -646,   233,  -646,   485,
      94,   296,  -646,   198,   198,  -646,  1186,  1186,   137,   137,
    2117,  2809,  2762,  1117,  2288,  2816,   137,   137,    39,    39,
      73,    73,    73,  -646,  2709,  -646,  -646,   489,  -646,  -646,
      52,  -646,   491,    88,   492,  -646,  2577,  -646,  -646,   493,
    -646,  -646,   423,  -646,   178,  1268,   307,   494,   118,  -646,
    -646,   307,   423,   490,   499,  -646,    69,  -646,   514,  -646,
    -646,  -646,  -646,  3234,   500,  -646,  -646,  -646,  -646,  -646,
     716,  -646,  -646,   -35,  -646,  -646,   522,  -646,   -94,  -646,
    -646,   501,  -646,   504,    51,  -646,   505,    88,   506,  -646,
     928,  2577,  -646,  -646,   928,  -646,  -646,  -646,    52,  -646,
    -646,  -646,   507,  -646,   521,  -646,  -646,   -34,   178,  -646,
    -646,  -646,   396,  -646,  -646,   423,  1675,  -646,   523,   524,
     928,  -646,    88,  -646,  -646,  -646,  -646,    52,  -646,  -646,
    -646,    73,   516,  2790,  -646,  -646,  3366,   519,  -646,  -646,
      69,  -646,   178,  -646,  -646,  -646,  -646,    54,  -646,  -646,
       4,  2577,  -646,   928,   526,  -646,  -646,   527,   517,   528,
     200,  -646,  -646,   200,  -646,  -646,   529,   178,  -646,  -646,
    -646
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    88,     1,   303,    55,   463,   473,     0,   314,
     306,   325,     0,   391,     0,     0,     0,   313,   301,   315,
     387,   312,   316,   317,     0,   390,   319,   326,   327,   324,
       0,   317,     0,     0,   389,     0,     0,   317,     0,   321,
     388,   301,   301,   311,   454,   307,   105,     2,    27,    26,
      56,     0,    50,    28,    53,    28,    25,     0,    89,   456,
       0,   330,   455,   308,     0,     0,   466,     0,    19,     0,
      23,     0,    21,     0,     0,     0,    48,     0,    17,    16,
      24,   398,   398,   398,     0,     0,   458,   464,   398,     0,
     460,   328,     0,     4,   473,     0,   303,   304,   344,   340,
       0,     5,   351,   457,     0,   302,   318,   323,     0,   365,
     322,   346,     0,   342,     0,   320,   309,   459,     0,   461,
       0,   310,     0,   107,     0,   109,   110,     0,   111,   112,
     113,     0,     0,   116,   117,   118,   119,   120,     0,     0,
     123,     0,   125,   126,   127,   128,     0,   130,   131,   132,
       0,   134,   135,   136,     0,     0,   139,   140,     0,   142,
     143,   144,   145,   146,     0,     0,     0,     0,     0,   152,
       0,   154,   155,     0,   157,     0,   159,   160,   163,     0,
     164,   165,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,     0,   179,   180,     0,   182,     0,
       0,   185,   186,   187,   188,   452,   189,     0,   191,   450,
       0,   193,   194,   195,     0,   197,     0,   199,   200,     0,
       0,     0,     0,   205,   451,   206,     0,     0,   210,   211,
       0,     0,     0,     0,    91,   215,    51,    88,    88,     0,
       0,    88,     0,   301,     0,   301,   301,     0,   456,     0,
       0,     0,   379,     0,   458,   460,    52,   303,   465,     0,
      18,    22,    20,    12,    15,     0,    49,   381,    14,   402,
     399,   401,   400,   218,   219,   220,   221,   392,     0,     0,
     305,   406,   442,   405,   298,   456,   458,   398,   460,   394,
      54,     0,   485,   484,   486,     0,   481,   474,     0,     0,
       0,    88,    71,   366,     0,     0,     0,   284,     0,   290,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   237,     0,     0,     0,     0,     0,     0,     0,
     237,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   105,    90,    72,     0,     0,    45,    42,    43,    44,
       0,    36,     0,    40,     0,    38,     0,     0,     0,    34,
      33,    41,    48,     0,   385,     0,    89,    46,   457,    74,
     459,   461,    75,   347,   347,     0,   359,   297,   329,   333,
       0,   334,   336,   338,     0,    11,     0,     0,     0,   404,
       0,     0,    77,   408,   395,     0,     0,   480,     0,    70,
       0,     7,     0,     0,   228,   233,   229,     0,     0,     0,
     462,    88,    88,    88,   104,     0,     0,     0,   217,   216,
       0,     0,   248,   239,   240,   241,   245,   246,   247,   242,
     243,     0,   244,     0,     0,     0,     0,     0,     0,     0,
     282,     0,   280,     0,     0,    99,     0,     0,   283,     0,
       0,    94,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   427,     0,     0,   235,   238,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   449,   444,   445,   446,   447,   448,
       0,     0,     0,     0,   470,   472,     0,     0,     0,    92,
     105,     8,     0,    35,    39,    37,    31,    30,    29,    76,
       0,     0,    88,    88,    88,    48,     0,   377,   331,   335,
     337,     0,   332,    88,     0,    88,     0,   393,   403,   407,
     443,     0,    87,     0,     0,    81,    78,    79,   491,   489,
     492,   490,     0,   487,   482,   475,     0,   231,   234,    88,
       0,   362,   363,   367,    59,     0,     0,   453,     0,   285,
       0,     0,   468,    89,   291,     0,   106,     0,   108,   209,
     114,     0,   272,   271,   270,   273,   268,   269,   463,     0,
     415,     0,   398,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   115,   121,     0,     0,
     122,     0,   129,   133,     0,   137,   138,   141,   147,   148,
     149,   150,   151,   153,   156,   158,   427,   392,    77,   432,
     427,   429,   428,    84,   424,   162,   237,   161,   166,   178,
     181,   183,   184,     0,   192,   196,   198,     0,   201,   202,
     204,   203,   207,   208,     0,   212,   213,   214,    93,     0,
       0,    28,   370,    77,   435,   467,    48,    47,     0,    89,
      48,     0,   348,    48,   345,   360,   361,     0,     0,   339,
      13,   353,     0,     0,     0,     0,    86,    85,   409,     0,
       0,   483,   479,     0,   475,     0,   230,   232,     0,     0,
      60,    57,    58,     0,   460,     0,   458,   299,   289,   288,
     101,   103,   415,   279,   392,    77,   419,   415,   416,     0,
     412,   398,   396,   261,   262,   274,   255,   256,   259,   260,
     250,   251,     0,   252,   253,   254,   258,   257,   264,   263,
     266,   267,   265,   275,     0,   281,   100,     0,    95,    83,
     427,   392,     0,   427,     0,   423,    77,   431,   236,     0,
     102,   471,     0,    10,    48,    88,     0,     0,     0,   386,
     341,     0,     0,     0,     0,   343,   373,   374,   378,    46,
     355,   354,   357,     0,     0,   296,   358,    82,    80,   488,
       0,   478,   476,     0,   364,   368,   437,   440,     0,   287,
     294,     0,   300,     0,   415,   392,     0,   427,     0,   411,
       0,    77,   418,   397,     0,   278,   124,   422,   427,   433,
     426,   430,     0,   190,     0,    73,    32,     0,    48,   436,
     384,   382,     0,   349,   350,     0,    88,   356,     0,     0,
       0,   439,     0,   286,   222,   277,   410,   427,   420,   414,
     417,   276,     0,   249,   425,   434,     0,     0,   369,   383,
     375,   376,    48,   477,     6,   438,   441,     0,   413,   421,
       0,    77,   380,     0,     0,   469,   223,     0,     0,     0,
      88,     9,   371,    88,   293,   225,     0,    48,   224,   292,
     372
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -646,  -646,  -646,  -646,  -646,  -646,  -646,   337,  -646,   -52,
    -646,   -54,  -311,    -1,  -646,   336,  -646,  -646,  -646,  -646,
    -646,  -646,  -646,    37,  -575,  -646,  -646,  -296,  -258,  -234,
      -2,  -646,  -646,  -646,   443,  -261,  -646,  -646,  -287,  -189,
     -73,  -646,  -646,  -646,  -646,  -646,   201,    16,   421,   116,
     299,  -646,  -285,  -316,  -646,  -646,  -646,  -646,  -130,  -337,
    -646,    71,  -646,    63,    -6,   -70,  -251,   153,   188,  -229,
    -244,  -255,   236,  -645,    15,    38,    29,    40,    30,    43,
      45,   382,  -646,    35,  -646,  -646,  -646,  -646,  -646,    60,
      -7,    21,  -646,  -646,    46,  -646,  -646,  -646,  -646,    47,
    -646,  -646,  -646,  -646,    50,  -646,  -646,  -375,  -593,     7,
     196,   -55,   -62,  -228,  -646,  -646,  -646,  -619,  -646,  -633,
    -646,  -559,  -646,  -646,  -646,   -78,  -646,   525,  -646,   444,
      11,  -379,    31,  -646,    14,  -646,   677,    75,  -646,  -646,
      79,  -646,   378,  -646,    83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,    47,   300,    48,   669,   356,     2,   395,   237,
     671,   522,   267,   357,    50,   565,    51,    52,    53,    54,
     358,   247,    55,   359,   544,   545,   546,   547,   639,    57,
     376,   233,   462,   482,   720,   424,   490,   425,   234,   430,
     640,   877,   886,   413,   414,   415,   416,   285,   476,   477,
     450,   451,   452,   459,   421,   569,   574,   423,   895,   896,
     794,    60,   811,   104,    61,   641,    62,   107,    63,    64,
      65,    66,   393,   394,   360,   361,   362,   363,   364,   365,
     366,   523,   682,   367,    75,   535,   694,    76,   527,   562,
     563,   368,   417,   709,   369,   776,   897,   788,   688,   370,
     386,   783,   784,   242,   371,    81,    82,    83,   397,   474,
     590,   269,    85,   282,   283,   728,   818,   729,   730,   642,
     764,   643,   644,   675,   851,   807,   808,   284,   500,   235,
     286,    87,    88,    89,   288,   506,    93,   703,   704,    94,
      95,   295,   296,   552,   553
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    49,    98,   238,   392,   463,    99,   375,   389,    84,
     102,   279,   105,    86,   281,   391,    90,    67,    59,   270,
     270,   270,   537,    77,   109,   403,   270,   271,   272,   113,
     390,    69,    71,   289,   472,   105,   105,    74,   465,    56,
      68,   468,    70,   470,   760,    72,   475,    73,    78,    79,
     398,   399,    80,   487,   453,    96,   595,    97,   258,   710,
     803,   519,   239,   762,   509,   253,   410,   412,   710,   254,
     592,   479,   255,   249,   248,   692,   772,   759,   280,   252,
     806,   765,  -479,   548,   540,   571,   575,   250,   251,   304,
     595,    96,  -303,    97,   291,   273,   273,   883,   777,   308,
      13,    13,   615,   813,   118,   120,  -303,   624,   819,   205,
     265,   646,   852,   209,   884,   531,   287,    30,    96,     3,
      97,    96,   532,    97,   292,   549,   240,   781,   457,   616,
     646,   814,   273,    91,   625,   853,   274,   274,   647,   293,
     700,   -66,  -303,   351,   224,   306,   305,   294,   406,   309,
     816,   534,   593,   594,   595,   672,  -303,   655,   503,   273,
     428,  -304,   273,   429,    13,   352,   556,   701,   828,   538,
     407,   531,   708,   274,   782,   673,   480,    46,   849,   867,
     279,   390,   411,   281,   110,   100,   241,   568,   570,   570,
     115,   832,   773,   101,    92,   856,   275,   275,   693,   108,
     274,   827,   592,   274,   830,   279,   279,   106,   281,   281,
     531,   401,   731,   111,   684,   595,   402,   887,   481,   806,
     112,   880,   857,   668,   550,   270,   116,   276,   276,   504,
     505,   121,   404,   275,   374,    58,    58,   105,   379,   105,
     105,   -62,  -303,   431,    84,    84,   862,   280,    86,    86,
     114,    90,    90,    59,    59,   610,   611,   612,   859,   551,
     275,   494,   236,   275,   276,   613,   614,   724,   637,   864,
     373,   686,   280,   280,    16,   707,   392,   273,   401,   401,
     389,   259,   685,   725,   638,   885,   711,   391,   678,   681,
     681,   276,   259,   674,   276,   712,   529,   390,   878,   613,
     614,   570,   390,   520,   637,   757,   888,   280,   118,   120,
      96,   103,    97,    97,   401,   401,   721,   426,   274,   766,
     638,   401,   454,   263,   279,   412,   821,   281,   473,   464,
     755,   277,   726,   -61,   277,   495,   496,   497,   498,   499,
      46,   117,   557,    97,  -226,    13,   256,   278,   491,   260,
     278,   608,   609,   610,   611,   612,    46,    46,    46,   298,
     567,   572,   680,   613,   614,   779,   299,   280,   769,   780,
     488,    46,   785,   301,   493,   683,   501,   502,   275,    20,
     303,   508,   521,   261,   528,   537,   767,   591,    46,  -295,
     310,   280,  -227,  -295,   262,   119,   770,    97,   264,   257,
     473,    97,   378,   798,    97,    25,   280,   266,   380,   276,
      97,   561,   608,   609,   610,   611,   612,   536,   381,   307,
      97,   573,   -64,  -303,   613,   614,     4,    46,    97,   894,
      11,   268,   787,   -63,   290,   311,   -65,   302,    46,   537,
    -331,   312,   388,   786,   313,   314,   315,   316,   279,   724,
     392,   281,   317,   537,   389,    34,   318,   319,   390,   320,
     401,   391,   321,   835,   726,   725,   322,   323,   280,   726,
     324,    40,   822,   325,   326,   327,   390,   328,   329,   330,
     636,   331,   537,    23,   332,   333,   334,   810,   335,   336,
     337,   338,   339,   340,   341,   342,    26,    27,    28,    29,
     343,   344,   345,   346,   347,   348,    31,   349,   350,   377,
     382,   -67,   400,   383,   384,   280,   385,   727,   -68,   591,
     679,   677,   -69,   405,   396,   408,   418,   868,   834,    84,
     270,    58,    49,    86,   875,   409,    90,   732,    59,   419,
      84,   427,   420,   390,    86,   422,   455,    90,    67,    59,
     839,   460,    37,   842,    77,   461,   726,    39,   466,   467,
     469,   882,    69,    71,   483,   763,   484,   486,    74,   507,
      56,    68,   510,    70,   511,   713,    72,   715,    73,    78,
      79,   716,   714,    80,   454,   512,   900,   513,   514,   515,
     871,   516,   517,   518,   526,  -303,   530,   525,   889,   555,
     539,   870,   558,   559,   560,   564,   576,   577,   578,   579,
     580,   392,   678,   581,   618,   389,   390,   458,   621,   775,
     458,   617,   391,   620,   619,   653,   622,   623,   471,   664,
     280,   478,   657,   626,   280,   627,   473,   390,   670,   478,
     628,   492,   279,   629,   630,   281,   631,   812,   687,   727,
     632,   633,   817,   635,   727,   645,   570,   648,   649,   570,
     650,   651,   652,   654,   454,   656,   659,   660,   661,   270,
     662,   473,   663,   665,   666,   667,   823,   691,   695,   698,
     699,   702,   705,   708,   717,   718,   253,   719,   735,   753,
     254,   758,   793,   255,   756,   248,   771,   473,   774,   458,
     543,    84,   561,   778,   241,   279,   789,   280,   281,   280,
     790,   280,   791,   796,    92,   801,   805,   809,   820,   843,
     845,   848,   826,   473,   829,   831,   833,   838,   844,   847,
     850,   854,   533,   866,   890,   846,   893,   855,   858,   860,
     865,   727,   582,   583,   584,   585,   586,   587,   589,   879,
     892,   881,   873,   874,   280,   566,   891,   280,   899,   456,
     706,   489,   768,   898,   473,   795,   524,   689,   804,   837,
     561,   297,   280,    58,   876,   840,   841,   722,   387,   802,
     485,   800,    84,   799,   554,     0,    86,     0,     0,    90,
       0,    59,     0,     0,     0,     0,     0,     0,     0,     0,
     253,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     432,   280,     0,   433,   434,   435,   436,   437,   438,   473,
       0,     0,   280,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   869,     0,     0,     0,
     585,     0,     0,     0,   679,   677,   280,     0,     0,     0,
       0,   280,     0,    84,     0,     0,     0,    86,     0,     0,
      90,     0,    59,     0,     0,     0,     0,     0,     0,   432,
       0,     0,   433,   434,   435,   436,   437,   438,     0,   473,
     432,     0,   588,   433,   434,   435,   436,   437,   438,     0,
       0,   439,   733,   734,     0,   736,   737,   738,   739,   740,
     741,   742,   743,   744,   745,   746,   747,   748,   749,   750,
     751,   752,     0,   754,     9,     0,    10,     0,     0,     0,
     458,     0,    11,     0,     0,     0,    13,     0,     0,     0,
       0,   432,     0,     0,   433,   434,   435,   436,   437,   438,
       0,     0,     0,   440,     0,   478,     0,     0,    17,     0,
     439,     0,     0,     0,   243,    19,     0,     0,     0,     0,
      20,   439,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,     0,   441,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    26,    27,
      28,    29,   442,     0,     0,     0,     0,     0,    31,     0,
       0,     0,   440,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   439,   440,     0,     0,     0,     0,   443,     0,
       0,   444,   445,   541,     0,     0,   447,   448,     0,     0,
       0,     0,     0,     0,     0,   542,    34,   441,     0,   449,
       0,     0,     0,    36,    37,    38,     0,     0,   441,    39,
       0,   442,    40,     0,     0,     0,   245,     0,     0,     0,
       0,     0,   442,     0,   440,   246,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    44,    45,   443,     0,     0,
     444,   445,   446,     0,     0,   447,   448,     0,   443,     0,
       0,   444,   445,   446,   696,     0,   447,   448,   449,   441,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   449,
       0,     0,     0,   442,     0,     0,     0,     0,     0,   861,
       0,     0,     0,   863,     0,     4,     5,     6,     0,     0,
       0,     0,   593,   594,   595,   596,   597,   598,   599,   443,
       0,     0,   444,   445,   446,     0,     0,   447,   448,   458,
       0,     0,     0,     8,     0,     0,     0,     0,     0,     9,
     449,    10,     0,     0,     0,     0,     0,    11,    12,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    14,     0,
     354,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,    17,     0,     0,     0,     0,     0,    18,
      19,   593,   594,   595,     0,    20,   598,   599,     0,     0,
      21,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,     0,     0,     0,    24,   355,     0,
       0,    25,     0,    26,    27,    28,    29,    30,     0,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     4,     5,     6,     0,     0,     0,     0,     0,     0,
       0,    34,     0,     0,     0,     0,     0,    35,    36,    37,
      38,     0,     0,     0,    39,     0,     0,    40,     0,     8,
       0,    41,     0,     0,     0,     9,     0,    10,     0,     0,
      42,     0,    43,    11,    12,     0,     0,    13,     0,     0,
      44,    45,     0,     0,    14,     0,   354,   604,   605,   606,
     607,   608,   609,   610,   611,   612,    16,     0,     0,    17,
       0,     0,     0,   613,   614,    18,    19,     0,     0,    46,
       0,    20,     0,   372,     0,     0,    21,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
       0,     0,     0,    24,   355,     0,     0,    25,     0,    26,
      27,    28,    29,    30,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,    32,     0,   606,   607,
     608,   609,   610,   611,   612,     0,     0,     0,     0,     0,
       0,     0,   613,   614,     0,    33,     0,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,    34,     0,     0,
       0,     0,     0,    35,    36,    37,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     8,     0,    41,     0,     0,
       0,     9,     0,    10,     0,     0,    42,     0,    43,    11,
      12,     0,     0,    13,     0,     0,    44,    45,     0,     0,
      14,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,    46,     0,    20,     0,   836,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     0,     0,     0,
       0,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     9,    40,
      10,     0,     0,    41,     0,     0,    11,     0,     0,     0,
      13,     0,    42,     0,    43,     0,     0,    14,     0,     0,
       0,     0,    44,    45,     0,     0,     0,     0,     0,     0,
       0,     0,    17,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,    46,    22,     0,     0,   690,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     4,     5,
       6,     0,     0,   593,   594,   595,   596,   597,   598,   599,
     600,   601,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     9,     0,    10,     0,     0,    36,    37,    38,
      11,     0,     0,    39,    13,     0,    40,     0,     0,     0,
      41,    14,     0,     0,     0,     0,     0,     0,     0,    42,
       0,    43,     0,     0,     0,     0,    17,     0,     0,    44,
      45,     0,    18,    19,     0,     0,     0,     0,    20,     0,
       0,     0,     0,    21,     0,     0,    22,     0,     0,     0,
       0,     0,     0,    23,     0,     0,     0,     0,    46,     0,
      24,     4,   676,     6,    25,     0,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,    33,    11,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,    34,     0,     0,     0,     0,     0,
       0,    36,    37,    38,     0,     0,     0,    39,     0,    17,
      40,     0,     0,     0,    41,   243,    19,     0,     0,     0,
       0,    20,     0,    42,     0,    43,    21,     0,     0,    22,
       0,     0,     0,    44,    45,   602,    23,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,    25,     0,    26,
      27,    28,    29,     0,   613,   614,     0,     0,     0,    31,
       0,   634,    46,     0,     0,     0,   872,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    -3,     0,     0,     4,     5,     6,
       0,     0,     0,     0,     0,     0,     0,    34,     7,     0,
       0,     0,     0,     0,    36,    37,    38,     0,     0,     0,
      39,     0,     0,    40,     0,     8,     0,   245,     0,     0,
       0,     9,     0,    10,     0,     0,   246,     0,    43,    11,
      12,     0,     0,    13,     0,     0,    44,    45,     0,     0,
      14,     0,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,    17,     0,     0,     0,     0,
       0,    18,    19,     0,     0,    46,     0,    20,     0,   792,
       0,     0,    21,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,     0,    26,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,     0,     0,     4,     5,     6,     0,     0,     0,
       0,     0,     0,    34,   353,     0,     0,     0,     0,    35,
      36,    37,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,     8,    41,     0,     0,     0,     0,     9,     0,
      10,     0,    42,     0,    43,     0,    11,    12,     0,     0,
      13,     0,    44,    45,     0,     0,     0,    14,     0,   354,
       0,     0,   593,   594,   595,   596,   597,   598,   599,    16,
     601,     0,    17,     0,     0,     0,     0,     0,    18,    19,
       0,    46,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,    24,   355,     0,     0,
      25,     0,    26,    27,    28,    29,    30,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,     0,     0,     4,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,    35,    36,    37,    38,
       9,     0,    10,    39,     0,     0,    40,   273,    11,     0,
      41,     0,    13,     0,     0,     0,     0,     0,     0,    42,
       0,    43,     0,     0,     0,     0,     0,     0,     0,    44,
      45,     0,     0,     0,    17,     0,     0,     0,     0,     0,
     243,    19,     0,     0,     0,     0,    20,     0,   274,     0,
       0,    21,     0,     0,    22,     0,     0,     0,    46,     0,
       0,    23,     0,   593,   594,   595,   596,   597,   598,   599,
       0,     0,    25,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,   613,   614,     0,     0,     0,   275,     0,
       0,     0,     0,     4,     0,     6,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,     0,     0,    36,
      37,    38,     0,     0,     0,    39,     0,     0,    40,   276,
       0,     0,   245,     0,     0,     0,     0,     9,     0,    10,
       0,   246,     0,    43,   273,    11,     0,     0,     0,    13,
       0,    44,    45,     0,     0,     0,   593,   594,   595,   596,
     597,   598,   599,   600,   601,     0,     0,     0,     0,   761,
       0,    17,     0,     0,     0,     0,     0,   243,    19,     0,
      46,     0,     0,    20,     0,   274,     0,     0,    21,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    26,    27,    28,    29,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     4,     0,     6,
       0,     0,   593,   594,   595,   596,   597,   598,   599,   600,
     601,     0,     0,     0,     0,   275,     0,     0,   797,   605,
     606,   607,   608,   609,   610,   611,   612,     0,     0,    34,
       0,     9,     0,    10,   613,   614,    36,    37,    38,    11,
       0,     0,    39,    13,     0,    40,   276,     0,     0,   245,
       0,     0,     0,     0,     0,     0,     0,     0,   246,     0,
      43,     0,     0,     0,     0,    17,     0,     0,    44,    45,
       0,   243,    19,     0,     0,     0,     0,    20,     0,     0,
       0,     0,    21,     0,     0,    22,   815,     0,     0,     0,
       0,     0,    23,     0,     0,     0,     0,    46,     0,     0,
       4,     0,     6,    25,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,   602,     0,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
       0,     0,     0,     0,     9,     0,    10,   613,   614,     0,
       0,     0,    11,     0,   658,     0,    13,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,    17,    40,
       0,     0,     0,   245,   243,    19,     0,     0,     0,     0,
      20,     0,   246,     0,    43,    21,     0,     0,    22,     0,
       0,     0,    44,    45,   602,    23,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,    25,     0,    26,    27,
      28,    29,     0,   613,   614,     0,     0,     0,    31,     0,
     723,    46,   593,   594,   595,   596,   597,   598,   599,   600,
     601,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,   594,   595,   596,   597,   598,
     599,   600,   601,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,    36,    37,    38,     0,     0,     0,    39,
       0,     0,    40,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,    43,     0,     0,
       0,     0,     0,     0,     0,    44,    45,   593,   594,   595,
     596,   597,   598,   599,   600,   601,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,   593,   594,   595,   596,   597,
     598,   599,   600,   601,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   593,   594,   595,   596,   597,   598,
     599,   593,   594,   595,   596,   597,   598,   599,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   602,     0,   603,   604,   605,   606,
     607,   608,   609,   610,   611,   612,     0,     0,     0,     0,
       0,     0,     0,   613,   614,   697,   602,     0,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,     0,     0,
       0,     0,     0,     0,     0,   613,   614,   825,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   602,
     824,   603,   604,   605,   606,   607,   608,   609,   610,   611,
     612,     0,     0,     0,     0,     0,     0,     0,   613,   614,
       0,     0,     0,     0,     0,     0,     0,   602,     0,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,     0,
       4,     0,     6,     0,     0,     0,   613,   614,   603,   604,
     605,   606,   607,   608,   609,   610,   611,   612,   606,   607,
     608,   609,   610,   611,   612,   613,   614,     0,     8,     0,
       0,     0,   613,   614,     9,     0,    10,     0,     0,     0,
       0,     0,    11,    12,     0,     0,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -352,     0,     0,    17,     0,
       0,     0,     0,     0,   243,    19,     0,     0,     0,     0,
      20,     0,     0,     0,     0,    21,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,     0,    26,    27,
      28,    29,    30,     0,     0,   244,     0,     0,    31,     0,
       0,     0,     0,     0,     4,     0,     6,   455,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    34,     0,     9,     0,
      10,     0,    35,    36,    37,    38,    11,     0,     0,    39,
      13,     0,    40,     0,     0,     0,   245,     0,     0,     0,
       0,     0,     0,     0,     0,   246,     0,    43,     0,     0,
       0,     0,    17,     0,     0,    44,    45,     0,   243,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     6,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     6,     0,
       0,     9,     0,    10,     0,     0,     0,     0,     0,    11,
       0,     0,     0,    13,     0,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       9,     0,    10,    39,     0,    17,    40,     0,    11,     0,
     245,   243,    19,     0,     0,     0,     0,    20,     0,   246,
       0,    43,    21,     0,     0,    22,     0,     0,     0,    44,
      45,     0,    23,     0,    17,     0,     0,     0,     0,     0,
     243,    19,     0,    25,     0,    26,    27,    28,    29,     0,
       0,    21,     0,     0,    22,    31,     0,     0,     0,     0,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     4,
       0,    97,     0,     0,    26,    27,    28,    29,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     9,     0,    10,    39,     0,     0,    40,
       0,    11,     0,   245,     0,     0,   588,     0,     0,     0,
       0,     0,   246,     0,    43,     0,     0,     0,     0,    36,
      37,    38,    44,    45,     0,    39,     0,    17,     0,     0,
       0,     0,   245,     0,    19,     0,     0,     0,     9,     0,
      10,   246,     0,    43,    21,     0,    11,    22,     0,     0,
      13,    44,    45,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    26,    27,    28,
      29,     0,    17,     0,     0,     0,     0,    31,   243,    19,
       0,     0,     0,     0,    20,     0,     0,     0,     0,    21,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   588,
      25,     0,    26,    27,    28,    29,     0,     0,     0,     0,
       0,     0,    31,    37,    38,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     9,     0,    10,     0,     0,    43,     0,     0,    11,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,    36,    37,    38,
       0,     0,     0,    39,     0,    17,    40,     0,     0,     0,
     245,   243,    19,     0,     0,     0,     0,     0,     0,   246,
       0,    43,    21,     0,     0,    22,     0,     0,     0,    44,
      45,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    27,    28,    29,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    37,    38,     0,     0,     0,    39,     0,     0,     0,
       0,     0,     0,   245,     0,     0,     0,     0,   122,   123,
       0,     0,   246,   124,    43,   125,   126,   127,   128,   129,
       0,   130,    44,    45,   131,     0,   132,     0,     0,     0,
     133,   134,     0,   135,   136,   137,   138,   139,   140,     0,
     141,     0,   142,   143,   144,     0,   145,   146,   147,   148,
     149,     0,   150,     0,     0,   151,   152,   153,   154,   155,
       0,     0,   156,   157,   158,   159,     0,     0,     0,   160,
     161,     0,   162,   163,     0,   164,   165,   166,   167,   168,
     169,     0,   170,   171,   172,   173,   174,   175,     0,     0,
     176,     0,     0,   177,     0,     0,     0,     0,     0,   178,
     179,     0,   180,   181,     0,   182,   183,   184,     0,     0,
       0,     0,   185,   186,   187,     0,   188,   189,   190,     0,
     191,   192,   193,   194,   195,   196,   197,   198,     0,   199,
       0,   200,     0,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   211,     0,   212,   213,     0,     0,
       0,     0,     0,   214,     0,     0,   215,     0,   216,     0,
     217,   218,     0,     0,   219,   220,   221,   222,     0,     0,
     223,     0,   224,     0,   225,   226,   227,   228,   229,   230,
     231,     0,     0,   232
};

static const yytype_int16 yycheck[] =
{
       2,     2,     8,    55,   259,   321,    12,   241,   259,     2,
      16,    84,    18,     2,    84,   259,     2,     2,     2,    81,
      82,    83,   397,     2,    30,   283,    88,    82,    83,    35,
     259,     2,     2,    88,   330,    41,    42,     2,   323,     2,
       2,   326,     2,   328,   637,     2,   331,     2,     2,     2,
     278,   279,     2,   338,   315,     3,    17,     5,    64,     6,
     705,   372,    62,   638,   351,    58,   115,   301,     6,    58,
     449,    27,    58,    58,    58,   125,   115,   636,    84,    58,
     713,   640,   115,    28,   400,   422,   423,    58,    58,     3,
      17,     3,   180,     5,    29,    44,    44,    43,   673,   180,
      49,    49,   206,   722,    41,    42,   180,   206,   727,   154,
      75,   206,   206,   158,    60,   206,    85,   115,     3,     0,
       5,     3,   213,     5,    59,    70,   126,    68,   317,   233,
     206,   724,    44,   226,   233,   229,    85,    85,   233,    74,
     206,   229,   230,   206,   189,   114,    60,    82,   206,   230,
     725,   149,    15,    16,    17,   212,   230,   233,   347,    44,
       9,   212,    44,    12,    49,   228,   410,   233,   761,   397,
     228,   206,   206,    85,   115,   232,   132,   227,   213,   213,
     253,   410,   231,   253,    31,   232,   186,   421,   422,   423,
      37,   766,   231,   230,   227,   814,   145,   145,   535,     9,
      85,   760,   581,    85,   763,   278,   279,   111,   278,   279,
     206,   227,   591,     3,   525,    17,   232,   213,   174,   852,
     232,   866,   815,   510,   169,   287,    38,   176,   176,     6,
       7,    43,   287,   145,   240,   237,   238,   243,   244,   245,
     246,   229,   230,   313,   237,   238,   821,   253,   237,   238,
     232,   237,   238,   237,   238,   216,   217,   218,   817,   204,
     145,   127,   229,   145,   176,   226,   227,   216,   216,   828,
     239,   526,   278,   279,    68,   560,   531,    44,   227,   227,
     531,   212,   526,   232,   232,   231,   233,   531,   522,   523,
     524,   176,   212,   521,   176,   233,   216,   526,   857,   226,
     227,   535,   531,   373,   216,   621,   881,   313,   245,   246,
       3,     3,     5,     5,   227,   227,   577,   310,    85,   232,
     232,   227,   315,   230,   397,   559,   232,   397,   330,   322,
     615,   216,   590,   229,   216,   201,   202,   203,   204,   205,
     227,     3,   412,     5,   231,    49,   229,   232,   341,   229,
     232,   214,   215,   216,   217,   218,   227,   227,   227,   115,
     231,   231,   231,   226,   227,   676,     9,   373,   653,   680,
     339,   227,   683,   230,   343,   231,   345,   346,   145,    83,
     212,   350,   375,   229,   390,   760,   644,   449,   227,   229,
     232,   397,   231,   233,   229,     3,   657,     5,   229,     3,
     402,     5,     3,   699,     5,   109,   412,   229,     3,   176,
       5,   417,   214,   215,   216,   217,   218,   396,     3,   230,
       5,   423,   229,   230,   226,   227,     3,   227,     5,   229,
      45,   229,   687,   229,   229,   232,   229,   229,   227,   814,
     212,   232,   226,   687,   232,   232,   232,   232,   521,   216,
     705,   521,   232,   828,   705,   159,   232,   232,   687,   232,
     227,   705,   232,   774,   722,   232,   232,   232,   474,   727,
     232,   175,   730,   232,   232,   232,   705,   232,   232,   232,
     473,   232,   857,    98,   232,   232,   232,   715,   232,   232,
     232,   232,   232,   232,   232,   232,   111,   112,   113,   114,
     232,   232,   232,   232,   232,   232,   121,   232,   232,   230,
     230,   229,   234,   230,   230,   521,   230,   590,   229,   581,
     522,   522,   229,   232,   230,     5,   208,   838,   772,   522,
     592,   533,   533,   522,   850,   233,   522,   592,   522,   208,
     533,     9,   233,   772,   533,   232,     6,   533,   533,   533,
     778,     9,   167,   782,   533,     9,   814,   172,     9,     9,
       9,   872,   533,   533,     9,   638,     9,     9,   533,     9,
     533,   533,   227,   533,   230,   568,   533,   570,   533,   533,
     533,   570,   568,   533,   577,   232,   897,   229,   229,   229,
     845,   230,   229,   229,   208,   230,   216,   231,   883,   230,
     233,   845,   231,   206,   234,     6,   233,   206,   233,   233,
     233,   866,   846,   232,   206,   866,   845,   318,   206,   671,
     321,   233,   866,   233,   226,   206,   233,   233,   329,   226,
     636,   332,   206,   233,   640,   233,   638,   866,     9,   340,
     233,   342,   715,   233,   233,   715,   233,   717,   162,   722,
     233,   233,   725,   233,   727,   233,   890,   233,   233,   893,
     233,   233,   233,   233,   657,   233,   233,   233,   233,   731,
     233,   673,   233,   233,   233,   233,   731,   208,   229,   233,
     206,   186,   212,   206,   233,   229,   679,   229,     3,     3,
     679,     9,   694,   679,     6,   679,     6,   699,   233,   400,
     401,   694,   708,   206,   186,   778,   230,   713,   778,   715,
     208,   717,   229,   231,   227,   231,   213,   229,   233,   229,
     206,     5,   233,   725,   233,   233,   233,   233,   229,   229,
     208,   230,   395,   212,   208,   789,   208,   233,   233,   233,
     233,   814,   443,   444,   445,   446,   447,   448,   449,   233,
     233,   232,   229,   229,   760,   419,   229,   763,   229,   316,
     559,   340,   646,   893,   766,   694,   384,   531,   708,   776,
     776,    94,   778,   775,   852,   781,   782,   581,   253,   704,
     336,   702,   775,   700,   406,    -1,   775,    -1,    -1,   775,
      -1,   775,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     793,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,   817,    -1,     6,     7,     8,     9,    10,    11,   821,
      -1,    -1,   828,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   842,    -1,    -1,    -1,
     541,    -1,    -1,    -1,   846,   846,   852,    -1,    -1,    -1,
      -1,   857,    -1,   846,    -1,    -1,    -1,   846,    -1,    -1,
     846,    -1,   846,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,     6,     7,     8,     9,    10,    11,    -1,   881,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    84,   593,   594,    -1,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,    -1,   614,    37,    -1,    39,    -1,    -1,    -1,
     621,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    -1,
      -1,     3,    -1,    -1,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,   136,    -1,   646,    -1,    -1,    71,    -1,
      84,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,   171,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,   112,
     113,   114,   185,    -1,    -1,    -1,    -1,    -1,   121,    -1,
      -1,    -1,   136,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,   136,    -1,    -1,    -1,    -1,   211,    -1,
      -1,   214,   215,   216,    -1,    -1,   219,   220,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   228,   159,   171,    -1,   232,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,   171,   172,
      -1,   185,   175,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,   185,    -1,   136,   188,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,   199,   211,    -1,    -1,
     214,   215,   216,    -1,    -1,   219,   220,    -1,   211,    -1,
      -1,   214,   215,   216,   228,    -1,   219,   220,   232,   171,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   232,
      -1,    -1,    -1,   185,    -1,    -1,    -1,    -1,    -1,   820,
      -1,    -1,    -1,   824,    -1,     3,     4,     5,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,   211,
      -1,    -1,   214,   215,   216,    -1,    -1,   219,   220,   850,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,    -1,    37,
     232,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,
      78,    15,    16,    17,    -1,    83,    20,    21,    -1,    -1,
      88,    -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,
      -1,   109,    -1,   111,   112,   113,   114,   115,    -1,    -1,
      -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,
     128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,
      -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,
     168,    -1,    -1,    -1,   172,    -1,    -1,   175,    -1,    31,
      -1,   179,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
     188,    -1,   190,    45,    46,    -1,    -1,    49,    -1,    -1,
     198,   199,    -1,    -1,    56,    -1,    58,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    68,    -1,    -1,    71,
      -1,    -1,    -1,   226,   227,    77,    78,    -1,    -1,   227,
      -1,    83,    -1,   231,    -1,    -1,    88,    -1,    -1,    91,
      -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,   105,   106,    -1,    -1,   109,    -1,   111,
     112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,   121,
      -1,    -1,    -1,    -1,    -1,    -1,   128,    -1,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   226,   227,    -1,   147,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    -1,   165,   166,   167,   168,    -1,    -1,    -1,
     172,    -1,    -1,   175,    -1,    31,    -1,   179,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,   188,    -1,   190,    45,
      46,    -1,    -1,    49,    -1,    -1,   198,   199,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,   227,    -1,    83,    -1,   231,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    37,   175,
      39,    -1,    -1,   179,    -1,    -1,    45,    -1,    -1,    -1,
      49,    -1,   188,    -1,   190,    -1,    -1,    56,    -1,    -1,
      -1,    -1,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,   227,    91,    -1,    -1,   231,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,    -1,    -1,    -1,
     109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    37,    -1,    39,    -1,    -1,   166,   167,   168,
      45,    -1,    -1,   172,    49,    -1,   175,    -1,    -1,    -1,
     179,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,   190,    -1,    -1,    -1,    -1,    71,    -1,    -1,   198,
     199,    -1,    77,    78,    -1,    -1,    -1,    -1,    83,    -1,
      -1,    -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,   227,    -1,
     105,     3,   231,     5,   109,    -1,   111,   112,   113,   114,
      -1,    -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,   147,    45,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,   166,   167,   168,    -1,    -1,    -1,   172,    -1,    71,
     175,    -1,    -1,    -1,   179,    77,    78,    -1,    -1,    -1,
      -1,    83,    -1,   188,    -1,   190,    88,    -1,    -1,    91,
      -1,    -1,    -1,   198,   199,   207,    98,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   109,    -1,   111,
     112,   113,   114,    -1,   226,   227,    -1,    -1,    -1,   121,
      -1,   233,   227,    -1,    -1,    -1,   231,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     0,    -1,    -1,     3,     4,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    14,    -1,
      -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
     172,    -1,    -1,   175,    -1,    31,    -1,   179,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,   188,    -1,   190,    45,
      46,    -1,    -1,    49,    -1,    -1,   198,   199,    -1,    -1,
      56,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    77,    78,    -1,    -1,   227,    -1,    83,    -1,   231,
      -1,    -1,    88,    -1,    -1,    91,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,   105,
      -1,    -1,    -1,   109,    -1,   111,   112,   113,   114,   115,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,   128,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    13,    -1,    -1,    -1,    -1,   165,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,   175,
      -1,    -1,    31,   179,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,   188,    -1,   190,    -1,    45,    46,    -1,    -1,
      49,    -1,   198,   199,    -1,    -1,    -1,    56,    -1,    58,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    68,
      23,    -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,
      -1,   227,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,   105,   106,    -1,    -1,
     109,    -1,   111,   112,   113,   114,   115,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,   128,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,   165,   166,   167,   168,
      37,    -1,    39,   172,    -1,    -1,   175,    44,    45,    -1,
     179,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,
     199,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,    -1,    -1,    -1,    83,    -1,    85,    -1,
      -1,    88,    -1,    -1,    91,    -1,    -1,    -1,   227,    -1,
      -1,    98,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    -1,   109,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,    -1,    -1,    -1,   145,    -1,
      -1,    -1,    -1,     3,    -1,     5,    -1,    -1,    -1,    -1,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,   172,    -1,    -1,   175,   176,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    37,    -1,    39,
      -1,   188,    -1,   190,    44,    45,    -1,    -1,    -1,    49,
      -1,   198,   199,    -1,    -1,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,   216,
      -1,    71,    -1,    -1,    -1,    -1,    -1,    77,    78,    -1,
     227,    -1,    -1,    83,    -1,    85,    -1,    -1,    88,    -1,
      -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,
      -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,    -1,
      -1,   121,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,   145,    -1,    -1,    24,   211,
     212,   213,   214,   215,   216,   217,   218,    -1,    -1,   159,
      -1,    37,    -1,    39,   226,   227,   166,   167,   168,    45,
      -1,    -1,   172,    49,    -1,   175,   176,    -1,    -1,   179,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   188,    -1,
     190,    -1,    -1,    -1,    -1,    71,    -1,    -1,   198,   199,
      -1,    77,    78,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      -1,    -1,    88,    -1,    -1,    91,   216,    -1,    -1,    -1,
      -1,    -1,    98,    -1,    -1,    -1,    -1,   227,    -1,    -1,
       3,    -1,     5,   109,    -1,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,   207,    -1,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
      -1,    -1,    -1,    -1,    37,    -1,    39,   226,   227,    -1,
      -1,    -1,    45,    -1,   233,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    71,   175,
      -1,    -1,    -1,   179,    77,    78,    -1,    -1,    -1,    -1,
      83,    -1,   188,    -1,   190,    88,    -1,    -1,    91,    -1,
      -1,    -1,   198,   199,   207,    98,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   109,    -1,   111,   112,
     113,   114,    -1,   226,   227,    -1,    -1,    -1,   121,    -1,
     233,   227,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   198,   199,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   227,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    15,    16,    17,    18,    19,    20,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   207,    -1,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   226,   227,   228,   207,    -1,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   226,   227,   228,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
       3,    -1,     5,    -1,    -1,    -1,   226,   227,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   212,   213,
     214,   215,   216,   217,   218,   226,   227,    -1,    31,    -1,
      -1,    -1,   226,   227,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    -1,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    71,    -1,
      -1,    -1,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    88,    -1,    -1,    91,    -1,
      -1,    -1,    -1,    -1,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,    -1,   111,   112,
     113,   114,   115,    -1,    -1,   118,    -1,    -1,   121,    -1,
      -1,    -1,    -1,    -1,     3,    -1,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    37,    -1,
      39,    -1,   165,   166,   167,   168,    45,    -1,    -1,   172,
      49,    -1,   175,    -1,    -1,    -1,   179,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   188,    -1,   190,    -1,    -1,
      -1,    -1,    71,    -1,    -1,   198,   199,    -1,    77,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
     109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
      37,    -1,    39,   172,    -1,    71,   175,    -1,    45,    -1,
     179,    77,    78,    -1,    -1,    -1,    -1,    83,    -1,   188,
      -1,   190,    88,    -1,    -1,    91,    -1,    -1,    -1,   198,
     199,    -1,    98,    -1,    71,    -1,    -1,    -1,    -1,    -1,
      77,    78,    -1,   109,    -1,   111,   112,   113,   114,    -1,
      -1,    88,    -1,    -1,    91,   121,    -1,    -1,    -1,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,     5,    -1,    -1,   111,   112,   113,   114,    -1,    -1,
      -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    37,    -1,    39,   172,    -1,    -1,   175,
      -1,    45,    -1,   179,    -1,    -1,     5,    -1,    -1,    -1,
      -1,    -1,   188,    -1,   190,    -1,    -1,    -1,    -1,   166,
     167,   168,   198,   199,    -1,   172,    -1,    71,    -1,    -1,
      -1,    -1,   179,    -1,    78,    -1,    -1,    -1,    37,    -1,
      39,   188,    -1,   190,    88,    -1,    45,    91,    -1,    -1,
      49,   198,   199,    -1,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,   113,
     114,    -1,    71,    -1,    -1,    -1,    -1,   121,    77,    78,
      -1,    -1,    -1,    -1,    83,    -1,    -1,    -1,    -1,    88,
      -1,    -1,    91,    -1,    -1,    -1,    -1,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
     109,    -1,   111,   112,   113,   114,    -1,    -1,    -1,    -1,
      -1,    -1,   121,   167,   168,    -1,    -1,    -1,   172,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    -1,    39,    -1,    -1,   190,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,   199,    -1,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,
      -1,    -1,    -1,   172,    -1,    71,   175,    -1,    -1,    -1,
     179,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,   188,
      -1,   190,    88,    -1,    -1,    91,    -1,    -1,    -1,   198,
     199,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,   113,   114,    -1,
      -1,    -1,    -1,    -1,    -1,   121,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     166,   167,   168,    -1,    -1,    -1,   172,    -1,    -1,    -1,
      -1,    -1,    -1,   179,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,   188,    30,   190,    32,    33,    34,    35,    36,
      -1,    38,   198,   199,    41,    -1,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      57,    -1,    59,    60,    61,    -1,    63,    64,    65,    66,
      67,    -1,    69,    -1,    -1,    72,    73,    74,    75,    76,
      -1,    -1,    79,    80,    81,    82,    -1,    -1,    -1,    86,
      87,    -1,    89,    90,    -1,    92,    93,    94,    95,    96,
      97,    -1,    99,   100,   101,   102,   103,   104,    -1,    -1,
     107,    -1,    -1,   110,    -1,    -1,    -1,    -1,    -1,   116,
     117,    -1,   119,   120,    -1,   122,   123,   124,    -1,    -1,
      -1,    -1,   129,   130,   131,    -1,   133,   134,   135,    -1,
     137,   138,   139,   140,   141,   142,   143,   144,    -1,   146,
      -1,   148,    -1,   150,   151,   152,   153,   154,   155,   156,
     157,   158,    -1,   160,   161,    -1,   163,   164,    -1,    -1,
      -1,    -1,    -1,   170,    -1,    -1,   173,    -1,   175,    -1,
     177,   178,    -1,    -1,   181,   182,   183,   184,    -1,    -1,
     187,    -1,   189,    -1,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,   200
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,   242,     0,     3,     4,     5,    14,    31,    37,
      39,    45,    46,    49,    56,    58,    68,    71,    77,    78,
      83,    88,    91,    98,   105,   109,   111,   112,   113,   114,
     115,   121,   128,   147,   159,   165,   166,   167,   168,   172,
     175,   179,   188,   190,   198,   199,   227,   237,   239,   248,
     249,   251,   252,   253,   254,   257,   258,   264,   265,   282,
     296,   299,   301,   303,   304,   305,   306,   309,   310,   311,
     312,   313,   314,   315,   318,   319,   322,   326,   329,   334,
     339,   340,   341,   342,   344,   347,   365,   366,   367,   368,
     369,   226,   227,   371,   374,   375,     3,     5,   299,   299,
     232,   230,   299,     3,   298,   299,   111,   302,     9,   299,
     302,     3,   232,   299,   232,   302,   303,     3,   298,     3,
     298,   303,    25,    26,    30,    32,    33,    34,    35,    36,
      38,    41,    43,    47,    48,    50,    51,    52,    53,    54,
      55,    57,    59,    60,    61,    63,    64,    65,    66,    67,
      69,    72,    73,    74,    75,    76,    79,    80,    81,    82,
      86,    87,    89,    90,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   107,   110,   116,   117,
     119,   120,   122,   123,   124,   129,   130,   131,   133,   134,
     135,   137,   138,   139,   140,   141,   142,   143,   144,   146,
     148,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   163,   164,   170,   173,   175,   177,   178,   181,
     182,   183,   184,   187,   189,   191,   192,   193,   194,   195,
     196,   197,   200,   266,   273,   364,   229,   244,   244,    62,
     126,   186,   338,    77,   118,   179,   188,   256,   282,   309,
     311,   313,   326,   344,   365,   369,   229,     3,   299,   212,
     229,   229,   229,   230,   229,   318,   229,   247,   229,   346,
     347,   346,   346,    44,    85,   145,   176,   216,   232,   275,
     299,   300,   348,   349,   362,   282,   365,   367,   369,   346,
     229,    29,    59,    74,    82,   376,   377,   371,   115,     9,
     238,   230,   229,   212,     3,    60,   367,   230,   180,   230,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   206,   228,    13,    58,   106,   241,   248,   255,   258,
     309,   310,   311,   312,   313,   314,   315,   318,   326,   329,
     334,   339,   231,   367,   299,   264,   265,   230,     3,   299,
       3,     3,   230,   230,   230,   230,   335,   362,   226,   301,
     304,   305,   306,   307,   308,   243,   230,   343,   348,   348,
     234,   227,   232,   263,   346,   232,   206,   228,     5,   233,
     115,   231,   264,   278,   279,   280,   281,   327,   208,   208,
     233,   289,   232,   292,   270,   272,   344,     9,     9,    12,
     274,   300,     3,     6,     7,     8,     9,    10,    11,    84,
     136,   171,   185,   211,   214,   215,   216,   219,   220,   232,
     285,   286,   287,   270,   344,     6,   269,   274,   285,   288,
       9,     9,   267,   288,   344,   287,     9,     9,   287,     9,
     287,   285,   262,   265,   344,   287,   283,   284,   285,    27,
     132,   174,   268,     9,     9,   364,     9,   287,   367,   283,
     271,   344,   285,   367,   127,   201,   202,   203,   204,   205,
     363,   367,   367,   274,     6,     7,   370,     9,   367,   273,
     227,   230,   232,   229,   229,   229,   230,   229,   229,   247,
     300,   344,   246,   316,   316,   231,   208,   323,   299,   216,
     216,   206,   213,   242,   149,   320,   326,   342,   348,   233,
     288,   216,   228,   285,   259,   260,   261,   262,    28,    70,
     169,   204,   378,   379,   377,   230,   305,   300,   231,   206,
     234,   299,   324,   325,     6,   250,   250,   231,   264,   290,
     264,   294,   231,   265,   291,   294,   233,   206,   233,   233,
     233,   232,   285,   285,   285,   285,   285,   285,     5,   285,
     345,   347,   366,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   207,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   226,   227,   206,   233,   233,   206,   226,
     233,   206,   233,   233,   206,   233,   233,   233,   233,   233,
     233,   233,   233,   233,   233,   233,   344,   216,   232,   263,
     275,   300,   354,   356,   357,   233,   206,   233,   233,   233,
     233,   233,   233,   206,   233,   233,   233,   206,   233,   233,
     233,   233,   233,   233,   226,   233,   233,   233,   273,   240,
       9,   245,   212,   232,   348,   358,   231,   248,   264,   265,
     231,   264,   317,   231,   247,   305,   306,   162,   333,   307,
     231,   208,   125,   294,   321,   229,   228,   228,   233,   206,
     206,   233,   186,   372,   373,   212,   281,   287,   206,   328,
       6,   233,   233,   344,   369,   344,   365,   233,   229,   229,
     269,   270,   345,   233,   216,   232,   263,   275,   350,   352,
     353,   366,   346,   285,   285,     3,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,     3,   285,   287,     6,   288,     9,   356,
     343,   216,   259,   275,   355,   356,   232,   263,   284,   287,
     270,     6,   115,   231,   233,   244,   330,   259,   206,   247,
     247,    68,   115,   336,   337,   247,   305,   306,   332,   230,
     208,   229,   231,   265,   295,   296,   231,    24,   262,   379,
     375,   231,   372,   308,   324,   213,   354,   360,   361,   229,
     348,   297,   300,   352,   343,   216,   259,   275,   351,   352,
     233,   232,   263,   346,   208,   228,   233,   356,   343,   233,
     356,   233,   259,   233,   305,   247,   231,   325,   233,   348,
     299,   299,   304,   229,   229,   206,   246,   229,     5,   213,
     208,   359,   206,   229,   230,   233,   352,   343,   233,   356,
     233,   285,   259,   285,   356,   233,   212,   213,   247,   299,
     305,   306,   231,   229,   229,   288,   360,   276,   356,   233,
     308,   232,   247,    43,    60,   231,   277,   213,   259,   287,
     208,   229,   233,   208,   229,   293,   294,   331,   293,   229,
     247
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   237,   237,   238,   238,   239,   240,   240,
     241,   242,   243,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   244,   244,
     244,   245,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   244,   244,   244,   244,   246,   246,   247,   247,
     248,   248,   248,   248,   248,   248,   248,   249,   249,   250,
     250,   251,   251,   251,   251,   251,   251,   251,   251,   251,
     252,   253,   254,   255,   256,   257,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   263,   263,   264,   264,
     265,   266,   266,   266,   267,   267,   268,   268,   268,   269,
     269,   270,   271,   272,   272,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   273,   273,   273,
     273,   273,   273,   273,   273,   273,   274,   274,   275,   275,
     275,   275,   276,   276,   277,   277,   278,   278,   278,   279,
     279,   280,   281,   281,   282,   283,   283,   284,   284,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     286,   286,   287,   288,   289,   289,   290,   290,   291,   291,
     292,   292,   293,   293,   294,   294,   295,   296,   296,   297,
     297,   298,   298,   299,   299,   300,   301,   301,   301,   301,
     301,   301,   301,   301,   301,   301,   301,   302,   302,   303,
     303,   303,   303,   303,   303,   303,   303,   303,   304,   304,
     305,   305,   306,   307,   307,   307,   307,   307,   308,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   316,   317,
     317,   318,   319,   320,   320,   321,   321,   322,   322,   323,
     323,   323,   324,   325,   325,   326,   327,   328,   326,   329,
     330,   331,   329,   332,   332,   332,   332,   333,   333,   335,
     334,   334,   336,   336,   337,   338,   339,   340,   340,   340,
     341,   342,   343,   343,   344,   344,   345,   345,   346,   346,
     347,   347,   347,   348,   348,   348,   349,   349,   349,   349,
     350,   350,   350,   351,   351,   352,   352,   353,   353,   353,
     353,   353,   354,   354,   354,   355,   355,   356,   356,   357,
     357,   357,   357,   357,   357,   358,   358,   359,   359,   360,
     361,   361,   362,   362,   363,   363,   363,   363,   363,   363,
     364,   364,   364,   365,   366,   366,   366,   366,   366,   366,
     366,   366,   366,   366,   367,   367,   367,   368,   369,   369,
     370,   370,   370,   371,   371,   372,   372,   373,   374,   375,
     375,   376,   376,   377,   377,   377,   377,   378,   378,   379,
     379,   379,   379
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
       3,     3,     3,     3,     1,     0,     4,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     4,     4,     1,     6,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     1,     1,     1,     4,     4,     1,
       1,     4,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     1,     4,     1,     1,     4,     1,     4,     1,
       1,     4,     4,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     4,     1,     4,     4,     1,     1,     1,     1,     1,
       6,     1,     4,     1,     1,     1,     4,     1,     4,     1,
       1,     4,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     4,     3,     0,     2,     1,     1,
       3,     2,     3,     1,     5,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     5,     4,     3,
       1,     3,     1,     1,     0,     2,     4,     3,     2,     2,
       0,     2,     2,     1,     3,     2,     1,     3,     2,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     2,     3,
       1,     2,     4,     1,     1,     2,     1,     2,     1,     3,
       2,     6,     2,     6,     2,     5,     2,     0,     2,     3,
       3,     2,     1,     2,     3,     2,     3,     6,     6,     0,
       2,     2,     1,     1,     3,     2,     0,     0,     7,     8,
       0,     0,    13,     1,     1,     3,     3,     0,     2,     0,
       9,     2,     2,     3,     2,     2,     6,     1,     1,     1,
       1,     1,     0,     2,     2,     3,     2,     3,     0,     1,
       2,     2,     2,     3,     2,     1,     1,     3,     2,     4,
       3,     2,     1,     3,     2,     0,     1,     3,     2,     1,
       3,     4,     3,     2,     1,     3,     2,     0,     1,     1,
       3,     2,     1,     3,     4,     1,     3,     0,     2,     2,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     1,     1,     1,     2,     1,     2,
       1,     2,     4,     1,     1,     2,     1,     5,     5,    10,
       1,     3,     1,     0,     2,     0,     2,     4,     6,     0,
       3,     1,     3,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1
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
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use PARSER_error or PARSER_UNDEF. */
#define YYERRCODE PARSER_UNDEF


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

  yychar = PARSER_EMPTY; /* Cause a token to be read.  */

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
  if (yychar == PARSER_EMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* input: gbl_statements m_acf  */
#line 354 "tools/widl/parser.y"
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
#line 3439 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3445 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 373 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typeref_list)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list))));
						}
#line 3453 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 378 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3459 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 380 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3465 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_type_args '>' ';'  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typeref_list)))); }
#line 3471 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 385 "tools/widl/parser.y"
                                                     { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3477 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3483 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 388 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3489 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 389 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3495 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interface ';'  */
#line 390 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3501 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 391 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3507 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements interfacedef  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3513 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements delegatedef  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3519 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclass ';'  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3527 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements coclassdef  */
#line 397 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3535 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements apicontract ';'  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3541 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements apicontract_def  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3548 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3554 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 404 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3561 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements moduledef  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3567 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements librarydef  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3573 "tools/widl/parser.tab.c"
    break;

  case 26: /* gbl_statements: gbl_statements statement  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3579 "tools/widl/parser.tab.c"
    break;

  case 27: /* gbl_statements: gbl_statements decl_block  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3585 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: %empty  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3591 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements interface ';'  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3597 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements dispinterface ';'  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3603 "tools/widl/parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 415 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3609 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 416 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3615 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements interfacedef  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3621 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements delegatedef  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3627 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements coclass ';'  */
#line 419 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3633 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements coclassdef  */
#line 420 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3641 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements apicontract ';'  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3647 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements apicontract_def  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3654 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements runtimeclass ';'  */
#line 426 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3660 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements runtimeclass_def  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3667 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements moduledef  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3673 "tools/widl/parser.tab.c"
    break;

  case 42: /* imp_statements: imp_statements statement  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3679 "tools/widl/parser.tab.c"
    break;

  case 43: /* imp_statements: imp_statements importlib  */
#line 431 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3685 "tools/widl/parser.tab.c"
    break;

  case 44: /* imp_statements: imp_statements librarydef  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3691 "tools/widl/parser.tab.c"
    break;

  case 45: /* imp_statements: imp_statements imp_decl_block  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3697 "tools/widl/parser.tab.c"
    break;

  case 46: /* int_statements: %empty  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3703 "tools/widl/parser.tab.c"
    break;

  case 47: /* int_statements: int_statements statement  */
#line 437 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3709 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: cppquote  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3715 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: typedecl ';'  */
#line 446 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3721 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: declaration ';'  */
#line 447 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3727 "tools/widl/parser.tab.c"
    break;

  case 53: /* statement: import  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3733 "tools/widl/parser.tab.c"
    break;

  case 54: /* statement: typedef ';'  */
#line 449 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3739 "tools/widl/parser.tab.c"
    break;

  case 55: /* statement: aPRAGMA  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3745 "tools/widl/parser.tab.c"
    break;

  case 56: /* statement: pragma_warning  */
#line 451 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3751 "tools/widl/parser.tab.c"
    break;

  case 57: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 455 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\", \"enable\" or \"default\"\n");
                  }
#line 3763 "tools/widl/parser.tab.c"
    break;

  case 58: /* pragma_warning: tPRAGMA_WARNING '(' tDEFAULT ':' warnings ')'  */
#line 463 "tools/widl/parser.y"
                  {
                      (yyval.statement) = NULL;
                      do_warning("default", (yyvsp[-1].warning_list));
                  }
#line 3772 "tools/widl/parser.tab.c"
    break;

  case 59: /* warnings: aNUM  */
#line 470 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3778 "tools/widl/parser.tab.c"
    break;

  case 60: /* warnings: warnings aNUM  */
#line 471 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3784 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: tENUM aIDENTIFIER  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3790 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3796 "tools/widl/parser.tab.c"
    break;

  case 66: /* typedecl: tUNION aIDENTIFIER  */
#line 480 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3802 "tools/widl/parser.tab.c"
    break;

  case 67: /* typedecl: attributes enumdef  */
#line 481 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3808 "tools/widl/parser.tab.c"
    break;

  case 68: /* typedecl: attributes structdef  */
#line 482 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3814 "tools/widl/parser.tab.c"
    break;

  case 69: /* typedecl: attributes uniondef  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3820 "tools/widl/parser.tab.c"
    break;

  case 70: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 486 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3826 "tools/widl/parser.tab.c"
    break;

  case 71: /* import_start: tIMPORT aSTRING ';'  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3836 "tools/widl/parser.tab.c"
    break;

  case 72: /* import: import_start imp_statements aEOF  */
#line 495 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3845 "tools/widl/parser.tab.c"
    break;

  case 73: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3851 "tools/widl/parser.tab.c"
    break;

  case 74: /* libraryhdr: tLIBRARY typename  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3857 "tools/widl/parser.tab.c"
    break;

  case 75: /* library_start: attributes libraryhdr '{'  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3865 "tools/widl/parser.tab.c"
    break;

  case 76: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3871 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_args: %empty  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3877 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg_list: arg  */
#line 519 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3883 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg_list: arg_list ',' arg  */
#line 520 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3889 "tools/widl/parser.tab.c"
    break;

  case 82: /* args: arg_list ',' ELLIPSIS  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3895 "tools/widl/parser.tab.c"
    break;

  case 83: /* arg: attributes decl_spec m_any_declarator  */
#line 528 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 84: /* arg: decl_spec m_any_declarator  */
#line 533 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3915 "tools/widl/parser.tab.c"
    break;

  case 85: /* array: '[' expr ']'  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3924 "tools/widl/parser.tab.c"
    break;

  case 86: /* array: '[' '*' ']'  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3930 "tools/widl/parser.tab.c"
    break;

  case 87: /* array: '[' ']'  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3936 "tools/widl/parser.tab.c"
    break;

  case 88: /* m_attributes: %empty  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3942 "tools/widl/parser.tab.c"
    break;

  case 90: /* attributes: '[' attrib_list ']'  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3948 "tools/widl/parser.tab.c"
    break;

  case 91: /* attrib_list: attribute  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3954 "tools/widl/parser.tab.c"
    break;

  case 92: /* attrib_list: attrib_list ',' attribute  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3960 "tools/widl/parser.tab.c"
    break;

  case 93: /* attrib_list: attrib_list ']' '[' attribute  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3966 "tools/widl/parser.tab.c"
    break;

  case 94: /* str_list: aSTRING  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3972 "tools/widl/parser.tab.c"
    break;

  case 95: /* str_list: str_list ',' aSTRING  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3978 "tools/widl/parser.tab.c"
    break;

  case 96: /* marshaling_behavior: tAGILE  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3984 "tools/widl/parser.tab.c"
    break;

  case 97: /* marshaling_behavior: tNONE  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3990 "tools/widl/parser.tab.c"
    break;

  case 98: /* marshaling_behavior: tSTANDARD  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3996 "tools/widl/parser.tab.c"
    break;

  case 99: /* contract_ver: aNUM  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 4002 "tools/widl/parser.tab.c"
    break;

  case 100: /* contract_ver: aNUM '.' aNUM  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 4008 "tools/widl/parser.tab.c"
    break;

  case 101: /* contract_req: decl_spec ',' contract_ver  */
#line 576 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 4018 "tools/widl/parser.tab.c"
    break;

  case 102: /* static_attr: decl_spec ',' contract_req  */
#line 582 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4027 "tools/widl/parser.tab.c"
    break;

  case 103: /* activatable_attr: decl_spec ',' contract_req  */
#line 588 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 4036 "tools/widl/parser.tab.c"
    break;

  case 104: /* activatable_attr: contract_req  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 4042 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: %empty  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 4048 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tACTIVATABLE '(' activatable_attr ')'  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 4054 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tAGGREGATABLE  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 4060 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 4066 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tAPPOBJECT  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 4072 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tASYNC  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 4078 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tAUTOHANDLE  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 4084 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tBINDABLE  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 4090 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tBROADCAST  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 4096 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tCALLAS '(' ident ')'  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 4102 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 4108 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tCODE  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 4114 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCOMMSTATUS  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 4120 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCONTEXTHANDLE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 4126 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 4132 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 4138 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 4144 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 4150 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tCONTROL  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 4156 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 613 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 4162 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tDECODE  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 4168 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tDEFAULT  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 4174 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tDEFAULTBIND  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 4180 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tDEFAULTCOLLELEM  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 4186 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 4192 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tDEFAULTVTABLE  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 4198 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 4204 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tDISPLAYBIND  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 4210 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 4216 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tDUAL  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 4222 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tENABLEALLOCATE  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 4228 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tENCODE  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4234 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tENDPOINT '(' str_list ')'  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4240 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tENTRY '(' expr_const ')'  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4246 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tEVENTADD  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4252 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tEVENTREMOVE  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4258 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 630 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4266 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tEXPLICITHANDLE  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4272 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tFAULTSTATUS  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4278 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tFLAGS  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4284 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tFORCEALLOCATE  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4290 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tHANDLE  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4296 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4302 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4308 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4314 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 641 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4320 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4326 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tHIDDEN  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4332 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tID '(' expr_int_const ')'  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4338 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tIDEMPOTENT  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4344 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tIGNORE  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4350 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tIIDIS '(' expr ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4356 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tIMMEDIATEBIND  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4362 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4368 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tIN  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4374 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tINPUTSYNC  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4380 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4386 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tLCID '(' expr_int_const ')'  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4392 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tLCID  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4398 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tLICENSED  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4404 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tLOCAL  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4410 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4416 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tMAYBE  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4422 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tMESSAGE  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4428 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tNOCODE  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4434 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tNONBROWSABLE  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4440 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tNONCREATABLE  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4446 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tNONEXTENSIBLE  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4452 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tNOTIFY  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4458 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tNOTIFYFLAG  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4464 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tOBJECT  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4470 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tODL  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4476 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tOLEAUTOMATION  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4482 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4488 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tOPTIONAL  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4494 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tOUT  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4500 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tOVERLOAD '(' aSTRING ')'  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OVERLOAD, (yyvsp[-1].str)); }
#line 4506 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tPARTIALIGNORE  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4512 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4518 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tPROGID '(' aSTRING ')'  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4524 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tPROPGET  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4530 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tPROPPUT  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4536 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tPROPPUTREF  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4542 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tPROXY  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4548 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tPUBLIC  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4554 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 683 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4562 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tREADONLY  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4568 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tREPRESENTAS '(' type ')'  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4574 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tREQUESTEDIT  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4580 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tRESTRICTED  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4586 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tRETVAL  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4592 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4598 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tSOURCE  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4604 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tSTATIC '(' static_attr ')'  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4610 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4616 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tSTRING  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4622 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tSWITCHIS '(' expr ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4628 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4634 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tTRANSMITAS '(' type ')'  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4640 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tTHREADING '(' threading_type ')'  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4646 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tUIDEFAULT  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4652 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tUSESGETLASTERROR  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4658 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4664 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: tUUID '(' uuid_string ')'  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4670 "tools/widl/parser.tab.c"
    break;

  case 209: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4676 "tools/widl/parser.tab.c"
    break;

  case 210: /* attribute: tV1ENUM  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4682 "tools/widl/parser.tab.c"
    break;

  case 211: /* attribute: tVARARG  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4688 "tools/widl/parser.tab.c"
    break;

  case 212: /* attribute: tVERSION '(' version ')'  */
#line 707 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4694 "tools/widl/parser.tab.c"
    break;

  case 213: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4700 "tools/widl/parser.tab.c"
    break;

  case 214: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 709 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4706 "tools/widl/parser.tab.c"
    break;

  case 215: /* attribute: pointer_type  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4712 "tools/widl/parser.tab.c"
    break;

  case 217: /* uuid_string: aSTRING  */
#line 715 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4720 "tools/widl/parser.tab.c"
    break;

  case 218: /* callconv: tCDECL  */
#line 720 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4726 "tools/widl/parser.tab.c"
    break;

  case 219: /* callconv: tFASTCALL  */
#line 721 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4732 "tools/widl/parser.tab.c"
    break;

  case 220: /* callconv: tPASCAL  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4738 "tools/widl/parser.tab.c"
    break;

  case 221: /* callconv: tSTDCALL  */
#line 723 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4744 "tools/widl/parser.tab.c"
    break;

  case 222: /* cases: %empty  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4750 "tools/widl/parser.tab.c"
    break;

  case 223: /* cases: cases case  */
#line 727 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 224: /* case: tCASE expr_int_const ':' union_field  */
#line 730 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4765 "tools/widl/parser.tab.c"
    break;

  case 225: /* case: tDEFAULT ':' union_field  */
#line 734 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4774 "tools/widl/parser.tab.c"
    break;

  case 226: /* enums: %empty  */
#line 740 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4780 "tools/widl/parser.tab.c"
    break;

  case 227: /* enums: enum_list ','  */
#line 741 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4786 "tools/widl/parser.tab.c"
    break;

  case 229: /* enum_list: enum  */
#line 745 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4795 "tools/widl/parser.tab.c"
    break;

  case 230: /* enum_list: enum_list ',' enum  */
#line 749 "tools/widl/parser.y"
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
#line 4810 "tools/widl/parser.tab.c"
    break;

  case 231: /* enum_member: m_attributes ident  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4818 "tools/widl/parser.tab.c"
    break;

  case 232: /* enum: enum_member '=' expr_int_const  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4827 "tools/widl/parser.tab.c"
    break;

  case 233: /* enum: enum_member  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4835 "tools/widl/parser.tab.c"
    break;

  case 234: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4841 "tools/widl/parser.tab.c"
    break;

  case 235: /* m_exprs: m_expr  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4847 "tools/widl/parser.tab.c"
    break;

  case 236: /* m_exprs: m_exprs ',' m_expr  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4853 "tools/widl/parser.tab.c"
    break;

  case 237: /* m_expr: %empty  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4859 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: aNUM  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4865 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: aHEXNUM  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4871 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: aDOUBLE  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4877 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: tFALSE  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4883 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: tNULL  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4889 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: tTRUE  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4895 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: aSTRING  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4901 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: aWSTRING  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4907 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: aSQSTRING  */
#line 794 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4913 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: aIDENTIFIER  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4919 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '?' expr ':' expr  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4925 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr LOGICALOR expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4931 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr LOGICALAND expr  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4937 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '|' expr  */
#line 799 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4943 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr '^' expr  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4949 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr '&' expr  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4955 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr EQUALITY expr  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4961 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr INEQUALITY expr  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4967 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr '>' expr  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4973 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '<' expr  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4979 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr GREATEREQUAL expr  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4985 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr LESSEQUAL expr  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4991 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr SHL expr  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4997 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: expr SHR expr  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5003 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: expr '+' expr  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5009 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr '-' expr  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5015 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: expr '%' expr  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5021 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: expr '*' expr  */
#line 813 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5027 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr '/' expr  */
#line 814 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 5033 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: '!' expr  */
#line 815 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 5039 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: '~' expr  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 5045 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: '+' expr  */
#line 817 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 5051 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: '-' expr  */
#line 818 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 5057 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: '&' expr  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 5063 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr: '*' expr  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 5069 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 821 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5075 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr: expr '.' aIDENTIFIER  */
#line 822 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 5081 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 5087 "tools/widl/parser.tab.c"
    break;

  case 277: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 826 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 5093 "tools/widl/parser.tab.c"
    break;

  case 278: /* expr: expr '[' expr ']'  */
#line 827 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 5099 "tools/widl/parser.tab.c"
    break;

  case 279: /* expr: '(' expr ')'  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 5105 "tools/widl/parser.tab.c"
    break;

  case 280: /* expr_list_int_const: expr_int_const  */
#line 831 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 5111 "tools/widl/parser.tab.c"
    break;

  case 281: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 832 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 5117 "tools/widl/parser.tab.c"
    break;

  case 282: /* expr_int_const: expr  */
#line 835 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 5126 "tools/widl/parser.tab.c"
    break;

  case 283: /* expr_const: expr  */
#line 841 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 5135 "tools/widl/parser.tab.c"
    break;

  case 284: /* fields: %empty  */
#line 847 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5141 "tools/widl/parser.tab.c"
    break;

  case 285: /* fields: fields field  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 5147 "tools/widl/parser.tab.c"
    break;

  case 286: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 852 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 5156 "tools/widl/parser.tab.c"
    break;

  case 287: /* field: m_attributes uniondef ';'  */
#line 856 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 5165 "tools/widl/parser.tab.c"
    break;

  case 288: /* ne_union_field: s_field ';'  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5171 "tools/widl/parser.tab.c"
    break;

  case 289: /* ne_union_field: attributes ';'  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 5177 "tools/widl/parser.tab.c"
    break;

  case 290: /* ne_union_fields: %empty  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5183 "tools/widl/parser.tab.c"
    break;

  case 291: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 5189 "tools/widl/parser.tab.c"
    break;

  case 292: /* union_field: s_field ';'  */
#line 872 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 5195 "tools/widl/parser.tab.c"
    break;

  case 293: /* union_field: ';'  */
#line 873 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5201 "tools/widl/parser.tab.c"
    break;

  case 294: /* s_field: m_attributes decl_spec declarator  */
#line 876 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5210 "tools/widl/parser.tab.c"
    break;

  case 295: /* s_field: m_attributes structdef  */
#line 880 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5219 "tools/widl/parser.tab.c"
    break;

  case 296: /* funcdef: declaration  */
#line 886 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5229 "tools/widl/parser.tab.c"
    break;

  case 297: /* declaration: attributes decl_spec init_declarator  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5237 "tools/widl/parser.tab.c"
    break;

  case 298: /* declaration: decl_spec init_declarator  */
#line 898 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5245 "tools/widl/parser.tab.c"
    break;

  case 299: /* m_ident: %empty  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5251 "tools/widl/parser.tab.c"
    break;

  case 301: /* m_typename: %empty  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5257 "tools/widl/parser.tab.c"
    break;

  case 305: /* ident: typename  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5263 "tools/widl/parser.tab.c"
    break;

  case 306: /* base_type: tBYTE  */
#line 918 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5269 "tools/widl/parser.tab.c"
    break;

  case 307: /* base_type: tWCHAR  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5275 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tSIGNED int_std  */
#line 921 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5281 "tools/widl/parser.tab.c"
    break;

  case 310: /* base_type: tUNSIGNED int_std  */
#line 922 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5287 "tools/widl/parser.tab.c"
    break;

  case 311: /* base_type: tUNSIGNED  */
#line 923 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5293 "tools/widl/parser.tab.c"
    break;

  case 312: /* base_type: tFLOAT  */
#line 924 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5299 "tools/widl/parser.tab.c"
    break;

  case 313: /* base_type: tDOUBLE  */
#line 925 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5305 "tools/widl/parser.tab.c"
    break;

  case 314: /* base_type: tBOOLEAN  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5311 "tools/widl/parser.tab.c"
    break;

  case 315: /* base_type: tERRORSTATUST  */
#line 927 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5317 "tools/widl/parser.tab.c"
    break;

  case 316: /* base_type: tHANDLET  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5323 "tools/widl/parser.tab.c"
    break;

  case 319: /* int_std: tINT  */
#line 935 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5329 "tools/widl/parser.tab.c"
    break;

  case 320: /* int_std: tSHORT m_int  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5335 "tools/widl/parser.tab.c"
    break;

  case 321: /* int_std: tSMALL  */
#line 937 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5341 "tools/widl/parser.tab.c"
    break;

  case 322: /* int_std: tLONG m_int  */
#line 938 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5347 "tools/widl/parser.tab.c"
    break;

  case 323: /* int_std: tHYPER m_int  */
#line 939 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5353 "tools/widl/parser.tab.c"
    break;

  case 324: /* int_std: tINT64  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5359 "tools/widl/parser.tab.c"
    break;

  case 325: /* int_std: tCHAR  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5365 "tools/widl/parser.tab.c"
    break;

  case 326: /* int_std: tINT32  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5371 "tools/widl/parser.tab.c"
    break;

  case 327: /* int_std: tINT3264  */
#line 943 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5377 "tools/widl/parser.tab.c"
    break;

  case 328: /* namespace_pfx: aIDENTIFIER '.'  */
#line 947 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5383 "tools/widl/parser.tab.c"
    break;

  case 329: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5389 "tools/widl/parser.tab.c"
    break;

  case 330: /* qualified_type: typename  */
#line 952 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5395 "tools/widl/parser.tab.c"
    break;

  case 331: /* qualified_type: namespace_pfx typename  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5401 "tools/widl/parser.tab.c"
    break;

  case 332: /* parameterized_type: qualified_type '<' parameterized_type_args '>'  */
#line 957 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typeref_list)); }
#line 5407 "tools/widl/parser.tab.c"
    break;

  case 333: /* parameterized_type_arg: base_type  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5413 "tools/widl/parser.tab.c"
    break;

  case 334: /* parameterized_type_arg: qualified_type  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5419 "tools/widl/parser.tab.c"
    break;

  case 335: /* parameterized_type_arg: qualified_type '*'  */
#line 963 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5425 "tools/widl/parser.tab.c"
    break;

  case 336: /* parameterized_type_arg: parameterized_type  */
#line 964 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5431 "tools/widl/parser.tab.c"
    break;

  case 337: /* parameterized_type_arg: parameterized_type '*'  */
#line 965 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_pointer((yyvsp[-1].type)); }
#line 5437 "tools/widl/parser.tab.c"
    break;

  case 338: /* parameterized_type_args: parameterized_type_arg  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5443 "tools/widl/parser.tab.c"
    break;

  case 339: /* parameterized_type_args: parameterized_type_args ',' parameterized_type_arg  */
#line 971 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5449 "tools/widl/parser.tab.c"
    break;

  case 340: /* coclass: tCOCLASS typename  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5455 "tools/widl/parser.tab.c"
    break;

  case 341: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 978 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5461 "tools/widl/parser.tab.c"
    break;

  case 342: /* runtimeclass: tRUNTIMECLASS typename  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5467 "tools/widl/parser.tab.c"
    break;

  case 343: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].typeref_list)); }
#line 5473 "tools/widl/parser.tab.c"
    break;

  case 344: /* apicontract: tAPICONTRACT typename  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5479 "tools/widl/parser.tab.c"
    break;

  case 345: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 992 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5485 "tools/widl/parser.tab.c"
    break;

  case 346: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 995 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5491 "tools/widl/parser.tab.c"
    break;

  case 347: /* class_interfaces: %empty  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5497 "tools/widl/parser.tab.c"
    break;

  case 348: /* class_interfaces: class_interfaces class_interface  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref( (yyvsp[-1].typeref_list), (yyvsp[0].typeref) ); }
#line 5503 "tools/widl/parser.tab.c"
    break;

  case 349: /* class_interface: m_attributes interfaceref ';'  */
#line 1003 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5509 "tools/widl/parser.tab.c"
    break;

  case 350: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 1004 "tools/widl/parser.y"
                                                { (yyval.typeref) = make_typeref((yyvsp[-1].type)); (yyval.typeref)->attrs = (yyvsp[-2].attr_list); }
#line 5515 "tools/widl/parser.tab.c"
    break;

  case 351: /* dispinterface: tDISPINTERFACE typename  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5521 "tools/widl/parser.tab.c"
    break;

  case 352: /* dispattributes: attributes  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5527 "tools/widl/parser.tab.c"
    break;

  case 353: /* dispint_props: tPROPERTIES ':'  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5533 "tools/widl/parser.tab.c"
    break;

  case 354: /* dispint_props: dispint_props s_field ';'  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5539 "tools/widl/parser.tab.c"
    break;

  case 355: /* dispint_meths: tMETHODS ':'  */
#line 1017 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5545 "tools/widl/parser.tab.c"
    break;

  case 356: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5551 "tools/widl/parser.tab.c"
    break;

  case 357: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 1023 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5557 "tools/widl/parser.tab.c"
    break;

  case 358: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5563 "tools/widl/parser.tab.c"
    break;

  case 359: /* inherit: %empty  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5569 "tools/widl/parser.tab.c"
    break;

  case 360: /* inherit: ':' qualified_type  */
#line 1029 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5575 "tools/widl/parser.tab.c"
    break;

  case 361: /* inherit: ':' parameterized_type  */
#line 1030 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5581 "tools/widl/parser.tab.c"
    break;

  case 362: /* type_parameter: typename  */
#line 1033 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5587 "tools/widl/parser.tab.c"
    break;

  case 363: /* type_parameters: type_parameter  */
#line 1037 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5593 "tools/widl/parser.tab.c"
    break;

  case 364: /* type_parameters: type_parameters ',' type_parameter  */
#line 1038 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5599 "tools/widl/parser.tab.c"
    break;

  case 365: /* interface: tINTERFACE typename  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5605 "tools/widl/parser.tab.c"
    break;

  case 366: /* $@3: %empty  */
#line 1043 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5611 "tools/widl/parser.tab.c"
    break;

  case 367: /* $@4: %empty  */
#line 1043 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5617 "tools/widl/parser.tab.c"
    break;

  case 368: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 1044 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].typeref_list)); }
#line 5623 "tools/widl/parser.tab.c"
    break;

  case 369: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.type) = type_delegate_declare((yyvsp[-4].var)->name, current_namespace);
						  (yyval.type) = type_delegate_define((yyval.type), (yyvsp[-7].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						}
#line 5631 "tools/widl/parser.tab.c"
    break;

  case 370: /* $@5: %empty  */
#line 1052 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5637 "tools/widl/parser.tab.c"
    break;

  case 371: /* $@6: %empty  */
#line 1053 "tools/widl/parser.y"
                         { pop_parameters_namespace((yyvsp[-7].var)->name); }
#line 5643 "tools/widl/parser.tab.c"
    break;

  case 372: /* delegatedef: m_attributes tDELEGATE type ident '<' $@5 type_parameters '>' '(' m_args ')' $@6 semicolon_opt  */
#line 1054 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_delegate_declare((yyvsp[-9].var)->name, current_namespace, (yyvsp[-6].typeref_list));
						  (yyval.type) = type_parameterized_delegate_define((yyval.type), (yyvsp[-12].attr_list), append_statement(NULL, make_statement_delegate((yyvsp[-10].type), (yyvsp[-3].var_list))));
						}
#line 5651 "tools/widl/parser.tab.c"
    break;

  case 373: /* required_types: qualified_type  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5657 "tools/widl/parser.tab.c"
    break;

  case 374: /* required_types: parameterized_type  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref(NULL, make_typeref((yyvsp[0].type))); }
#line 5663 "tools/widl/parser.tab.c"
    break;

  case 375: /* required_types: required_types ',' qualified_type  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5669 "tools/widl/parser.tab.c"
    break;

  case 376: /* required_types: required_types ',' parameterized_type  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = append_typeref((yyvsp[-2].typeref_list), make_typeref((yyvsp[0].type))); }
#line 5675 "tools/widl/parser.tab.c"
    break;

  case 377: /* requires: %empty  */
#line 1065 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = NULL; }
#line 5681 "tools/widl/parser.tab.c"
    break;

  case 378: /* requires: tREQUIRES required_types  */
#line 1066 "tools/widl/parser.y"
                                                { (yyval.typeref_list) = (yyvsp[0].typeref_list); }
#line 5687 "tools/widl/parser.tab.c"
    break;

  case 379: /* $@7: %empty  */
#line 1069 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5693 "tools/widl/parser.tab.c"
    break;

  case 380: /* interfacedef: attributes interface $@7 inherit requires '{' int_statements '}' semicolon_opt  */
#line 1071 "tools/widl/parser.y"
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
#line 5709 "tools/widl/parser.tab.c"
    break;

  case 381: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1082 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5715 "tools/widl/parser.tab.c"
    break;

  case 382: /* interfaceref: tINTERFACE typename  */
#line 1086 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5721 "tools/widl/parser.tab.c"
    break;

  case 383: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1087 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5727 "tools/widl/parser.tab.c"
    break;

  case 384: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1091 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5733 "tools/widl/parser.tab.c"
    break;

  case 385: /* module: tMODULE typename  */
#line 1094 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5739 "tools/widl/parser.tab.c"
    break;

  case 386: /* moduledef: m_attributes module '{' int_statements '}' semicolon_opt  */
#line 1098 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5745 "tools/widl/parser.tab.c"
    break;

  case 387: /* storage_cls_spec: tEXTERN  */
#line 1102 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5751 "tools/widl/parser.tab.c"
    break;

  case 388: /* storage_cls_spec: tSTATIC  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5757 "tools/widl/parser.tab.c"
    break;

  case 389: /* storage_cls_spec: tREGISTER  */
#line 1104 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5763 "tools/widl/parser.tab.c"
    break;

  case 390: /* function_specifier: tINLINE  */
#line 1108 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5769 "tools/widl/parser.tab.c"
    break;

  case 391: /* type_qualifier: tCONST  */
#line 1112 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5775 "tools/widl/parser.tab.c"
    break;

  case 392: /* m_type_qual_list: %empty  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5781 "tools/widl/parser.tab.c"
    break;

  case 393: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1116 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5787 "tools/widl/parser.tab.c"
    break;

  case 394: /* decl_spec: type m_decl_spec_no_type  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5793 "tools/widl/parser.tab.c"
    break;

  case 395: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5799 "tools/widl/parser.tab.c"
    break;

  case 396: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1125 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5805 "tools/widl/parser.tab.c"
    break;

  case 397: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5811 "tools/widl/parser.tab.c"
    break;

  case 398: /* m_decl_spec_no_type: %empty  */
#line 1130 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5817 "tools/widl/parser.tab.c"
    break;

  case 400: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1135 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5823 "tools/widl/parser.tab.c"
    break;

  case 401: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1136 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5829 "tools/widl/parser.tab.c"
    break;

  case 402: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5835 "tools/widl/parser.tab.c"
    break;

  case 403: /* declarator: '*' m_type_qual_list declarator  */
#line 1142 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5841 "tools/widl/parser.tab.c"
    break;

  case 404: /* declarator: callconv declarator  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5847 "tools/widl/parser.tab.c"
    break;

  case 406: /* direct_declarator: ident  */
#line 1148 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5853 "tools/widl/parser.tab.c"
    break;

  case 407: /* direct_declarator: '(' declarator ')'  */
#line 1149 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5859 "tools/widl/parser.tab.c"
    break;

  case 408: /* direct_declarator: direct_declarator array  */
#line 1150 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5865 "tools/widl/parser.tab.c"
    break;

  case 409: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5871 "tools/widl/parser.tab.c"
    break;

  case 410: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1157 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5877 "tools/widl/parser.tab.c"
    break;

  case 411: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1158 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5883 "tools/widl/parser.tab.c"
    break;

  case 413: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1165 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5889 "tools/widl/parser.tab.c"
    break;

  case 414: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5895 "tools/widl/parser.tab.c"
    break;

  case 415: /* m_abstract_declarator: %empty  */
#line 1170 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5901 "tools/widl/parser.tab.c"
    break;

  case 417: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5907 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1177 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5913 "tools/widl/parser.tab.c"
    break;

  case 419: /* abstract_direct_declarator: array  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5919 "tools/widl/parser.tab.c"
    break;

  case 420: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5927 "tools/widl/parser.tab.c"
    break;

  case 421: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1184 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5935 "tools/widl/parser.tab.c"
    break;

  case 422: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1192 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5941 "tools/widl/parser.tab.c"
    break;

  case 423: /* any_declarator: callconv m_any_declarator  */
#line 1193 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5947 "tools/widl/parser.tab.c"
    break;

  case 425: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1200 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5953 "tools/widl/parser.tab.c"
    break;

  case 426: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5959 "tools/widl/parser.tab.c"
    break;

  case 427: /* m_any_declarator: %empty  */
#line 1205 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5965 "tools/widl/parser.tab.c"
    break;

  case 429: /* any_direct_declarator: ident  */
#line 1213 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5971 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1214 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5977 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_direct_declarator: any_direct_declarator array  */
#line 1215 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5983 "tools/widl/parser.tab.c"
    break;

  case 432: /* any_direct_declarator: array  */
#line 1216 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5989 "tools/widl/parser.tab.c"
    break;

  case 433: /* any_direct_declarator: '(' m_args ')'  */
#line 1218 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5997 "tools/widl/parser.tab.c"
    break;

  case 434: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1222 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 6005 "tools/widl/parser.tab.c"
    break;

  case 435: /* declarator_list: declarator  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6011 "tools/widl/parser.tab.c"
    break;

  case 436: /* declarator_list: declarator_list ',' declarator  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6017 "tools/widl/parser.tab.c"
    break;

  case 437: /* m_bitfield: %empty  */
#line 1232 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 6023 "tools/widl/parser.tab.c"
    break;

  case 438: /* m_bitfield: ':' expr_const  */
#line 1233 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 6029 "tools/widl/parser.tab.c"
    break;

  case 439: /* struct_declarator: any_declarator m_bitfield  */
#line 1236 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 6038 "tools/widl/parser.tab.c"
    break;

  case 440: /* struct_declarator_list: struct_declarator  */
#line 1243 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 6044 "tools/widl/parser.tab.c"
    break;

  case 441: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1245 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 6050 "tools/widl/parser.tab.c"
    break;

  case 442: /* init_declarator: declarator  */
#line 1249 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 6056 "tools/widl/parser.tab.c"
    break;

  case 443: /* init_declarator: declarator '=' expr_const  */
#line 1250 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 6062 "tools/widl/parser.tab.c"
    break;

  case 444: /* threading_type: tAPARTMENT  */
#line 1254 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 6068 "tools/widl/parser.tab.c"
    break;

  case 445: /* threading_type: tNEUTRAL  */
#line 1255 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 6074 "tools/widl/parser.tab.c"
    break;

  case 446: /* threading_type: tSINGLE  */
#line 1256 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 6080 "tools/widl/parser.tab.c"
    break;

  case 447: /* threading_type: tFREE  */
#line 1257 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6086 "tools/widl/parser.tab.c"
    break;

  case 448: /* threading_type: tBOTH  */
#line 1258 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 6092 "tools/widl/parser.tab.c"
    break;

  case 449: /* threading_type: tMTA  */
#line 1259 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 6098 "tools/widl/parser.tab.c"
    break;

  case 450: /* pointer_type: tREF  */
#line 1263 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 6104 "tools/widl/parser.tab.c"
    break;

  case 451: /* pointer_type: tUNIQUE  */
#line 1264 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 6110 "tools/widl/parser.tab.c"
    break;

  case 452: /* pointer_type: tPTR  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 6116 "tools/widl/parser.tab.c"
    break;

  case 453: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1268 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 6122 "tools/widl/parser.tab.c"
    break;

  case 454: /* unqualified_type: tVOID  */
#line 1272 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 6128 "tools/widl/parser.tab.c"
    break;

  case 455: /* unqualified_type: base_type  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6134 "tools/widl/parser.tab.c"
    break;

  case 456: /* unqualified_type: enumdef  */
#line 1274 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6140 "tools/widl/parser.tab.c"
    break;

  case 457: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1275 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6146 "tools/widl/parser.tab.c"
    break;

  case 458: /* unqualified_type: structdef  */
#line 1276 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6152 "tools/widl/parser.tab.c"
    break;

  case 459: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1277 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 6158 "tools/widl/parser.tab.c"
    break;

  case 460: /* unqualified_type: uniondef  */
#line 1278 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6164 "tools/widl/parser.tab.c"
    break;

  case 461: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 6170 "tools/widl/parser.tab.c"
    break;

  case 462: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 6176 "tools/widl/parser.tab.c"
    break;

  case 463: /* unqualified_type: aKNOWNTYPE  */
#line 1281 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 6182 "tools/widl/parser.tab.c"
    break;

  case 465: /* type: namespace_pfx typename  */
#line 1286 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 6188 "tools/widl/parser.tab.c"
    break;

  case 466: /* type: parameterized_type  */
#line 1287 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 6194 "tools/widl/parser.tab.c"
    break;

  case 467: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1291 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 6203 "tools/widl/parser.tab.c"
    break;

  case 468: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1298 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 6209 "tools/widl/parser.tab.c"
    break;

  case 469: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1301 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 6215 "tools/widl/parser.tab.c"
    break;

  case 470: /* version: aNUM  */
#line 1305 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 6221 "tools/widl/parser.tab.c"
    break;

  case 471: /* version: aNUM '.' aNUM  */
#line 1306 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 6227 "tools/widl/parser.tab.c"
    break;

  case 472: /* version: aHEXNUM  */
#line 1307 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6233 "tools/widl/parser.tab.c"
    break;

  case 477: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1322 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 6241 "tools/widl/parser.tab.c"
    break;

  case 478: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1329 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 6251 "tools/widl/parser.tab.c"
    break;

  case 479: /* acf_attributes: %empty  */
#line 1337 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 6257 "tools/widl/parser.tab.c"
    break;

  case 480: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1338 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 6263 "tools/widl/parser.tab.c"
    break;

  case 481: /* acf_attribute_list: acf_attribute  */
#line 1342 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 6269 "tools/widl/parser.tab.c"
    break;

  case 482: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1343 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 6275 "tools/widl/parser.tab.c"
    break;

  case 483: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1348 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 6281 "tools/widl/parser.tab.c"
    break;

  case 484: /* acf_attribute: tENCODE  */
#line 1349 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 6287 "tools/widl/parser.tab.c"
    break;

  case 485: /* acf_attribute: tDECODE  */
#line 1350 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 6293 "tools/widl/parser.tab.c"
    break;

  case 486: /* acf_attribute: tEXPLICITHANDLE  */
#line 1351 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 6299 "tools/widl/parser.tab.c"
    break;

  case 487: /* allocate_option_list: allocate_option  */
#line 1355 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6305 "tools/widl/parser.tab.c"
    break;

  case 488: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1357 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6311 "tools/widl/parser.tab.c"
    break;

  case 489: /* allocate_option: tDONTFREE  */
#line 1361 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6317 "tools/widl/parser.tab.c"
    break;

  case 490: /* allocate_option: tFREE  */
#line 1362 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6323 "tools/widl/parser.tab.c"
    break;

  case 491: /* allocate_option: tALLNODES  */
#line 1363 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6329 "tools/widl/parser.tab.c"
    break;

  case 492: /* allocate_option: tSINGLENODE  */
#line 1364 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6335 "tools/widl/parser.tab.c"
    break;


#line 6339 "tools/widl/parser.tab.c"

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
  yytoken = yychar == PARSER_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
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
          YYNOMEM;
      }
    }

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
                      yytoken, &yylval);
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
  yyerror (YY_("memory exhausted"));
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

#line 1367 "tools/widl/parser.y"


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

static attr_t *make_custom_attr(struct uuid *id, expr_t *pval)
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
    char *dst = replace_extension( get_basename(input_idl_name), ".idl", "" );
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
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, "hidden" },
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
    /* ATTR_OVERLOAD */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "overload" },
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
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 1, 1, 0, 1, "version" },
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
