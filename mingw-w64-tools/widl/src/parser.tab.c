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

struct _import_t
{
  char *name;
  int import_performed;
};

static str_list_t *append_str(str_list_t *list, char *str);
static type_list_t *append_type(type_list_t *list, type_t *type);
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
static void push_parameters_namespace(const char *name);
static void pop_parameters_namespace(const char *name);

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
static struct namespace *parameters_namespace = NULL;

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
    tEVENTADD = 332,               /* tEVENTADD  */
    tEVENTREMOVE = 333,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 334,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 335,         /* tEXPLICITHANDLE  */
    tEXTERN = 336,                 /* tEXTERN  */
    tFALSE = 337,                  /* tFALSE  */
    tFASTCALL = 338,               /* tFASTCALL  */
    tFAULTSTATUS = 339,            /* tFAULTSTATUS  */
    tFLAGS = 340,                  /* tFLAGS  */
    tFLOAT = 341,                  /* tFLOAT  */
    tFORCEALLOCATE = 342,          /* tFORCEALLOCATE  */
    tHANDLE = 343,                 /* tHANDLE  */
    tHANDLET = 344,                /* tHANDLET  */
    tHELPCONTEXT = 345,            /* tHELPCONTEXT  */
    tHELPFILE = 346,               /* tHELPFILE  */
    tHELPSTRING = 347,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 348,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 349,          /* tHELPSTRINGDLL  */
    tHIDDEN = 350,                 /* tHIDDEN  */
    tHYPER = 351,                  /* tHYPER  */
    tID = 352,                     /* tID  */
    tIDEMPOTENT = 353,             /* tIDEMPOTENT  */
    tIGNORE = 354,                 /* tIGNORE  */
    tIIDIS = 355,                  /* tIIDIS  */
    tIMMEDIATEBIND = 356,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 357,         /* tIMPLICITHANDLE  */
    tIMPORT = 358,                 /* tIMPORT  */
    tIMPORTLIB = 359,              /* tIMPORTLIB  */
    tIN = 360,                     /* tIN  */
    tIN_LINE = 361,                /* tIN_LINE  */
    tINLINE = 362,                 /* tINLINE  */
    tINPUTSYNC = 363,              /* tINPUTSYNC  */
    tINT = 364,                    /* tINT  */
    tINT32 = 365,                  /* tINT32  */
    tINT3264 = 366,                /* tINT3264  */
    tINT64 = 367,                  /* tINT64  */
    tINTERFACE = 368,              /* tINTERFACE  */
    tLCID = 369,                   /* tLCID  */
    tLENGTHIS = 370,               /* tLENGTHIS  */
    tLIBRARY = 371,                /* tLIBRARY  */
    tLICENSED = 372,               /* tLICENSED  */
    tLOCAL = 373,                  /* tLOCAL  */
    tLONG = 374,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 375,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 376,                  /* tMAYBE  */
    tMESSAGE = 377,                /* tMESSAGE  */
    tMETHODS = 378,                /* tMETHODS  */
    tMODULE = 379,                 /* tMODULE  */
    tMTA = 380,                    /* tMTA  */
    tNAMESPACE = 381,              /* tNAMESPACE  */
    tNOCODE = 382,                 /* tNOCODE  */
    tNONBROWSABLE = 383,           /* tNONBROWSABLE  */
    tNONCREATABLE = 384,           /* tNONCREATABLE  */
    tNONE = 385,                   /* tNONE  */
    tNONEXTENSIBLE = 386,          /* tNONEXTENSIBLE  */
    tNOTIFY = 387,                 /* tNOTIFY  */
    tNOTIFYFLAG = 388,             /* tNOTIFYFLAG  */
    tNULL = 389,                   /* tNULL  */
    tOBJECT = 390,                 /* tOBJECT  */
    tODL = 391,                    /* tODL  */
    tOLEAUTOMATION = 392,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 393,               /* tOPTIMIZE  */
    tOPTIONAL = 394,               /* tOPTIONAL  */
    tOUT = 395,                    /* tOUT  */
    tPARTIALIGNORE = 396,          /* tPARTIALIGNORE  */
    tPASCAL = 397,                 /* tPASCAL  */
    tPOINTERDEFAULT = 398,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 399,         /* tPRAGMA_WARNING  */
    tPROGID = 400,                 /* tPROGID  */
    tPROPERTIES = 401,             /* tPROPERTIES  */
    tPROPGET = 402,                /* tPROPGET  */
    tPROPPUT = 403,                /* tPROPPUT  */
    tPROPPUTREF = 404,             /* tPROPPUTREF  */
    tPROXY = 405,                  /* tPROXY  */
    tPTR = 406,                    /* tPTR  */
    tPUBLIC = 407,                 /* tPUBLIC  */
    tRANGE = 408,                  /* tRANGE  */
    tREADONLY = 409,               /* tREADONLY  */
    tREF = 410,                    /* tREF  */
    tREGISTER = 411,               /* tREGISTER  */
    tREPRESENTAS = 412,            /* tREPRESENTAS  */
    tREQUESTEDIT = 413,            /* tREQUESTEDIT  */
    tREQUIRES = 414,               /* tREQUIRES  */
    tRESTRICTED = 415,             /* tRESTRICTED  */
    tRETVAL = 416,                 /* tRETVAL  */
    tRUNTIMECLASS = 417,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 418,              /* tSAFEARRAY  */
    tSHORT = 419,                  /* tSHORT  */
    tSIGNED = 420,                 /* tSIGNED  */
    tSINGLENODE = 421,             /* tSINGLENODE  */
    tSIZEIS = 422,                 /* tSIZEIS  */
    tSIZEOF = 423,                 /* tSIZEOF  */
    tSMALL = 424,                  /* tSMALL  */
    tSOURCE = 425,                 /* tSOURCE  */
    tSTANDARD = 426,               /* tSTANDARD  */
    tSTATIC = 427,                 /* tSTATIC  */
    tSTDCALL = 428,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 429,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 430,                 /* tSTRING  */
    tSTRUCT = 431,                 /* tSTRUCT  */
    tSWITCH = 432,                 /* tSWITCH  */
    tSWITCHIS = 433,               /* tSWITCHIS  */
    tSWITCHTYPE = 434,             /* tSWITCHTYPE  */
    tTHREADING = 435,              /* tTHREADING  */
    tTRANSMITAS = 436,             /* tTRANSMITAS  */
    tTRUE = 437,                   /* tTRUE  */
    tTYPEDEF = 438,                /* tTYPEDEF  */
    tUIDEFAULT = 439,              /* tUIDEFAULT  */
    tUNION = 440,                  /* tUNION  */
    tUNIQUE = 441,                 /* tUNIQUE  */
    tUNSIGNED = 442,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 443,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 444,            /* tUSERMARSHAL  */
    tUUID = 445,                   /* tUUID  */
    tV1ENUM = 446,                 /* tV1ENUM  */
    tVARARG = 447,                 /* tVARARG  */
    tVERSION = 448,                /* tVERSION  */
    tVIPROGID = 449,               /* tVIPROGID  */
    tVOID = 450,                   /* tVOID  */
    tWCHAR = 451,                  /* tWCHAR  */
    tWIREMARSHAL = 452,            /* tWIREMARSHAL  */
    tAPARTMENT = 453,              /* tAPARTMENT  */
    tNEUTRAL = 454,                /* tNEUTRAL  */
    tSINGLE = 455,                 /* tSINGLE  */
    tFREE = 456,                   /* tFREE  */
    tBOTH = 457,                   /* tBOTH  */
    CAST = 458,                    /* CAST  */
    PPTR = 459,                    /* PPTR  */
    POS = 460,                     /* POS  */
    NEG = 461,                     /* NEG  */
    ADDRESSOF = 462                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 124 "tools/widl/parser.y"

	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	type_t *type;
	type_list_t *type_list;
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
  YYSYMBOL_tEVENTADD = 77,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 78,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 79,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 80,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 81,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 82,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 83,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 84,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 85,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 86,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 87,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 88,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 89,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 90,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 91,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 92,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 93,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 94,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 95,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 96,                    /* tHYPER  */
  YYSYMBOL_tID = 97,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 98,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 99,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 100,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 101,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 102,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 103,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 104,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 105,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 106,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 107,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 108,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 109,                     /* tINT  */
  YYSYMBOL_tINT32 = 110,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 111,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 112,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 113,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 114,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 115,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 116,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 117,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 118,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 119,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 120,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 121,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 122,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 123,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 124,                  /* tMODULE  */
  YYSYMBOL_tMTA = 125,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 126,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 127,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 128,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 129,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 130,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 131,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 132,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 133,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 134,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 135,                  /* tOBJECT  */
  YYSYMBOL_tODL = 136,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 137,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 138,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 139,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 140,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 141,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 142,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 143,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 144,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 145,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 146,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 147,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 148,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 149,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 150,                   /* tPROXY  */
  YYSYMBOL_tPTR = 151,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 152,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 153,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 154,                /* tREADONLY  */
  YYSYMBOL_tREF = 155,                     /* tREF  */
  YYSYMBOL_tREGISTER = 156,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 157,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 158,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 159,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 160,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 161,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 162,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 163,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 164,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 165,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 166,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 167,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 168,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 169,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 170,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 171,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 172,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 173,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 174,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 175,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 176,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 177,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 178,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 179,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 180,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 181,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 182,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 183,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 184,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 185,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 186,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 187,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 188,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 189,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 190,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 191,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 192,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 193,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 194,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 195,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 196,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 197,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 198,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 199,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 200,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 201,                    /* tFREE  */
  YYSYMBOL_tBOTH = 202,                    /* tBOTH  */
  YYSYMBOL_203_ = 203,                     /* ','  */
  YYSYMBOL_204_ = 204,                     /* '?'  */
  YYSYMBOL_205_ = 205,                     /* ':'  */
  YYSYMBOL_206_ = 206,                     /* '|'  */
  YYSYMBOL_207_ = 207,                     /* '^'  */
  YYSYMBOL_208_ = 208,                     /* '&'  */
  YYSYMBOL_209_ = 209,                     /* '<'  */
  YYSYMBOL_210_ = 210,                     /* '>'  */
  YYSYMBOL_211_ = 211,                     /* '-'  */
  YYSYMBOL_212_ = 212,                     /* '+'  */
  YYSYMBOL_213_ = 213,                     /* '*'  */
  YYSYMBOL_214_ = 214,                     /* '/'  */
  YYSYMBOL_215_ = 215,                     /* '%'  */
  YYSYMBOL_216_ = 216,                     /* '!'  */
  YYSYMBOL_217_ = 217,                     /* '~'  */
  YYSYMBOL_CAST = 218,                     /* CAST  */
  YYSYMBOL_PPTR = 219,                     /* PPTR  */
  YYSYMBOL_POS = 220,                      /* POS  */
  YYSYMBOL_NEG = 221,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 222,                /* ADDRESSOF  */
  YYSYMBOL_223_ = 223,                     /* '.'  */
  YYSYMBOL_224_ = 224,                     /* '['  */
  YYSYMBOL_225_ = 225,                     /* ']'  */
  YYSYMBOL_226_ = 226,                     /* '{'  */
  YYSYMBOL_227_ = 227,                     /* '}'  */
  YYSYMBOL_228_ = 228,                     /* ';'  */
  YYSYMBOL_229_ = 229,                     /* '('  */
  YYSYMBOL_230_ = 230,                     /* ')'  */
  YYSYMBOL_231_ = 231,                     /* '='  */
  YYSYMBOL_YYACCEPT = 232,                 /* $accept  */
  YYSYMBOL_input = 233,                    /* input  */
  YYSYMBOL_m_acf = 234,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 235,           /* gbl_statements  */
  YYSYMBOL_236_1 = 236,                    /* $@1  */
  YYSYMBOL_imp_statements = 237,           /* imp_statements  */
  YYSYMBOL_238_2 = 238,                    /* $@2  */
  YYSYMBOL_int_statements = 239,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 240,            /* semicolon_opt  */
  YYSYMBOL_statement = 241,                /* statement  */
  YYSYMBOL_pragma_warning = 242,           /* pragma_warning  */
  YYSYMBOL_warnings = 243,                 /* warnings  */
  YYSYMBOL_typedecl = 244,                 /* typedecl  */
  YYSYMBOL_cppquote = 245,                 /* cppquote  */
  YYSYMBOL_import_start = 246,             /* import_start  */
  YYSYMBOL_import = 247,                   /* import  */
  YYSYMBOL_importlib = 248,                /* importlib  */
  YYSYMBOL_libraryhdr = 249,               /* libraryhdr  */
  YYSYMBOL_library_start = 250,            /* library_start  */
  YYSYMBOL_librarydef = 251,               /* librarydef  */
  YYSYMBOL_m_args = 252,                   /* m_args  */
  YYSYMBOL_arg_list = 253,                 /* arg_list  */
  YYSYMBOL_args = 254,                     /* args  */
  YYSYMBOL_arg = 255,                      /* arg  */
  YYSYMBOL_array = 256,                    /* array  */
  YYSYMBOL_m_attributes = 257,             /* m_attributes  */
  YYSYMBOL_attributes = 258,               /* attributes  */
  YYSYMBOL_attrib_list = 259,              /* attrib_list  */
  YYSYMBOL_str_list = 260,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 261,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 262,             /* contract_ver  */
  YYSYMBOL_contract_req = 263,             /* contract_req  */
  YYSYMBOL_static_attr = 264,              /* static_attr  */
  YYSYMBOL_attribute = 265,                /* attribute  */
  YYSYMBOL_uuid_string = 266,              /* uuid_string  */
  YYSYMBOL_callconv = 267,                 /* callconv  */
  YYSYMBOL_cases = 268,                    /* cases  */
  YYSYMBOL_case = 269,                     /* case  */
  YYSYMBOL_enums = 270,                    /* enums  */
  YYSYMBOL_enum_list = 271,                /* enum_list  */
  YYSYMBOL_enum_member = 272,              /* enum_member  */
  YYSYMBOL_enum = 273,                     /* enum  */
  YYSYMBOL_enumdef = 274,                  /* enumdef  */
  YYSYMBOL_m_exprs = 275,                  /* m_exprs  */
  YYSYMBOL_m_expr = 276,                   /* m_expr  */
  YYSYMBOL_expr = 277,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 278,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 279,           /* expr_int_const  */
  YYSYMBOL_expr_const = 280,               /* expr_const  */
  YYSYMBOL_fields = 281,                   /* fields  */
  YYSYMBOL_field = 282,                    /* field  */
  YYSYMBOL_ne_union_field = 283,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 284,          /* ne_union_fields  */
  YYSYMBOL_union_field = 285,              /* union_field  */
  YYSYMBOL_s_field = 286,                  /* s_field  */
  YYSYMBOL_funcdef = 287,                  /* funcdef  */
  YYSYMBOL_declaration = 288,              /* declaration  */
  YYSYMBOL_m_ident = 289,                  /* m_ident  */
  YYSYMBOL_m_typename = 290,               /* m_typename  */
  YYSYMBOL_typename = 291,                 /* typename  */
  YYSYMBOL_ident = 292,                    /* ident  */
  YYSYMBOL_base_type = 293,                /* base_type  */
  YYSYMBOL_m_int = 294,                    /* m_int  */
  YYSYMBOL_int_std = 295,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 296,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 297,           /* qualified_type  */
  YYSYMBOL_coclass = 298,                  /* coclass  */
  YYSYMBOL_coclassdef = 299,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 300,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_def = 301,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 302,              /* apicontract  */
  YYSYMBOL_apicontract_def = 303,          /* apicontract_def  */
  YYSYMBOL_namespacedef = 304,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 305,         /* class_interfaces  */
  YYSYMBOL_class_interface = 306,          /* class_interface  */
  YYSYMBOL_dispinterface = 307,            /* dispinterface  */
  YYSYMBOL_dispattributes = 308,           /* dispattributes  */
  YYSYMBOL_dispint_props = 309,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 310,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 311,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 312,                  /* inherit  */
  YYSYMBOL_type_parameter = 313,           /* type_parameter  */
  YYSYMBOL_type_parameters = 314,          /* type_parameters  */
  YYSYMBOL_interface = 315,                /* interface  */
  YYSYMBOL_316_3 = 316,                    /* $@3  */
  YYSYMBOL_317_4 = 317,                    /* $@4  */
  YYSYMBOL_required_types = 318,           /* required_types  */
  YYSYMBOL_requires = 319,                 /* requires  */
  YYSYMBOL_interfacedef = 320,             /* interfacedef  */
  YYSYMBOL_321_5 = 321,                    /* $@5  */
  YYSYMBOL_interfaceref = 322,             /* interfaceref  */
  YYSYMBOL_dispinterfaceref = 323,         /* dispinterfaceref  */
  YYSYMBOL_module = 324,                   /* module  */
  YYSYMBOL_moduledef = 325,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 326,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 327,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 328,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 329,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 330,                /* decl_spec  */
  YYSYMBOL_unqualified_decl_spec = 331,    /* unqualified_decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 332,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 333,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 334,               /* declarator  */
  YYSYMBOL_direct_declarator = 335,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 336,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 337, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 338,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 339, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 340,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 341, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 342,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 343,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 344,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 345,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 346,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 347,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 348,          /* init_declarator  */
  YYSYMBOL_threading_type = 349,           /* threading_type  */
  YYSYMBOL_pointer_type = 350,             /* pointer_type  */
  YYSYMBOL_structdef = 351,                /* structdef  */
  YYSYMBOL_unqualified_type = 352,         /* unqualified_type  */
  YYSYMBOL_type = 353,                     /* type  */
  YYSYMBOL_typedef = 354,                  /* typedef  */
  YYSYMBOL_uniondef = 355,                 /* uniondef  */
  YYSYMBOL_version = 356,                  /* version  */
  YYSYMBOL_acf_statements = 357,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 358,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 359,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 360,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 361,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 362,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 363,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 364,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 365           /* allocate_option  */
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
#define YYLAST   3530

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  232
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  462
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  832

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   462


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
       2,     2,     2,   216,     2,     2,     2,   215,   208,     2,
     229,   230,   213,   212,   203,   211,   223,   214,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   205,   228,
     209,   231,   210,   204,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   224,     2,   225,   207,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   226,   206,   227,   217,     2,     2,     2,
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
     195,   196,   197,   198,   199,   200,   201,   202,   218,   219,
     220,   221,   222
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   343,   343,   357,   357,   359,   360,   360,   362,   363,
     364,   365,   368,   371,   372,   374,   375,   377,   378,   379,
     382,   383,   384,   385,   385,   387,   388,   389,   392,   393,
     395,   396,   398,   399,   400,   401,   404,   405,   408,   409,
     413,   414,   415,   416,   417,   418,   419,   422,   433,   434,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   449,
     451,   459,   465,   469,   471,   475,   479,   480,   483,   484,
     487,   488,   492,   497,   504,   508,   509,   512,   513,   517,
     520,   521,   522,   525,   526,   530,   531,   532,   536,   537,
     540,   546,   551,   552,   553,   554,   555,   556,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   590,
     591,   592,   593,   594,   595,   596,   597,   598,   599,   600,
     601,   602,   603,   604,   605,   606,   607,   608,   609,   610,
     611,   612,   613,   614,   616,   617,   618,   619,   620,   621,
     622,   623,   624,   625,   626,   627,   628,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   642,   643,   644,
     645,   646,   647,   648,   649,   650,   651,   652,   653,   654,
     655,   656,   657,   658,   659,   660,   661,   662,   663,   664,
     665,   666,   670,   671,   676,   677,   678,   679,   682,   683,
     686,   690,   696,   697,   698,   701,   705,   717,   722,   726,
     731,   734,   735,   738,   739,   742,   743,   744,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   762,   763,   764,   765,   766,
     767,   768,   769,   770,   771,   772,   773,   774,   775,   776,
     777,   778,   779,   781,   783,   784,   787,   788,   791,   797,
     803,   804,   807,   812,   819,   820,   823,   824,   828,   829,
     832,   836,   842,   850,   854,   859,   860,   863,   864,   867,
     868,   871,   874,   875,   876,   877,   878,   879,   880,   881,
     882,   883,   884,   887,   888,   891,   892,   893,   894,   895,
     896,   897,   898,   899,   903,   904,   908,   909,   912,   915,
     919,   922,   926,   929,   933,   936,   937,   941,   942,   945,
     948,   951,   952,   955,   956,   960,   962,   966,   967,   970,
     974,   975,   979,   980,   980,   980,   985,   986,   988,   989,
     992,   992,  1005,  1009,  1010,  1014,  1017,  1020,  1025,  1026,
    1027,  1031,  1035,  1038,  1039,  1042,  1043,  1047,  1049,  1053,
    1054,  1058,  1059,  1060,  1064,  1066,  1067,  1071,  1072,  1073,
    1074,  1079,  1081,  1082,  1087,  1089,  1093,  1094,  1099,  1100,
    1101,  1102,  1106,  1114,  1116,  1117,  1122,  1124,  1128,  1129,
    1136,  1137,  1138,  1139,  1140,  1144,  1151,  1152,  1155,  1156,
    1159,  1166,  1167,  1172,  1173,  1177,  1178,  1179,  1180,  1181,
    1182,  1186,  1187,  1188,  1191,  1195,  1196,  1197,  1198,  1199,
    1200,  1201,  1202,  1203,  1204,  1208,  1209,  1212,  1219,  1221,
    1227,  1228,  1229,  1233,  1234,  1238,  1239,  1243,  1250,  1259,
    1260,  1264,  1265,  1269,  1271,  1272,  1273,  1277,  1278,  1283,
    1284,  1285,  1286
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
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES",
  "tRESTRICTED", "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE",
  "tSTANDARD", "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING",
  "tSTRUCT", "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING",
  "tTRANSMITAS", "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE",
  "tUNSIGNED", "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM",
  "tVARARG", "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL",
  "tAPARTMENT", "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'",
  "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'",
  "'['", "']'", "'{'", "'}'", "';'", "'('", "')'", "'='", "$accept",
  "input", "m_acf", "gbl_statements", "$@1", "imp_statements", "$@2",
  "int_statements", "semicolon_opt", "statement", "pragma_warning",
  "warnings", "typedecl", "cppquote", "import_start", "import",
  "importlib", "libraryhdr", "library_start", "librarydef", "m_args",
  "arg_list", "args", "arg", "array", "m_attributes", "attributes",
  "attrib_list", "str_list", "marshaling_behavior", "contract_ver",
  "contract_req", "static_attr", "attribute", "uuid_string", "callconv",
  "cases", "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident",
  "m_typename", "typename", "ident", "base_type", "m_int", "int_std",
  "namespace_pfx", "qualified_type", "coclass", "coclassdef",
  "runtimeclass", "runtimeclass_def", "apicontract", "apicontract_def",
  "namespacedef", "class_interfaces", "class_interface", "dispinterface",
  "dispattributes", "dispint_props", "dispint_meths", "dispinterfacedef",
  "inherit", "type_parameter", "type_parameters", "interface", "$@3",
  "$@4", "required_types", "requires", "interfacedef", "$@5",
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
     455,   456,   457,    44,    63,    58,   124,    94,    38,    60,
      62,    45,    43,    42,    47,    37,    33,   126,   458,   459,
     460,   461,   462,    46,    91,    93,   123,   125,    59,    40,
      41,    61
};
#endif

#define YYPACT_NINF (-602)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-450)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -602,    97,  1713,  -602,  -117,  -602,  -602,   -71,   170,  -602,
    -602,  -602,   170,  -602,   -95,   170,  -602,   218,  -602,  -602,
    -602,  -602,    46,   131,  -602,  -602,  -602,  -602,  -602,   170,
      46,   159,   -55,  -602,   170,   -12,    46,   523,  -602,  -602,
     312,   316,   523,  -602,  -602,  3333,  -602,  -602,  -602,   -61,
    -602,  -602,  -602,  -602,  -602,   -17,  2811,   -39,     7,  -602,
    -602,   323,    26,  -602,    40,  -602,    51,  -602,   -45,    54,
     122,    71,    77,  -602,  -602,   171,   171,   171,   181,  3016,
      86,  -602,   171,    94,   103,  -602,    55,  -602,   -71,   146,
    -602,  -602,  -602,  -602,   233,  -602,   109,    43,  -602,  -602,
    -602,   114,   137,  -602,  -602,   280,  -602,  3016,  -602,  -602,
     129,   125,  -127,  -108,  -602,   130,  -602,   134,  -602,  -602,
     143,  -602,  -602,  -602,   151,   152,  -602,  -602,  -602,  -602,
    -602,   157,   167,  -602,   168,  -602,  -602,  -602,  -602,   179,
    -602,  -602,  -602,   183,  -602,  -602,  -602,   186,   191,  -602,
    -602,   203,  -602,  -602,  -602,  -602,  -602,   204,   206,   208,
     209,   211,  -602,   212,  -602,  -602,   213,  -602,   214,  -602,
    -602,   217,   219,  -602,  -602,   220,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,   221,  -602,  -602,
    -602,   222,   223,  -602,  -602,  -602,  -602,  -602,  -602,   224,
    -602,  -602,   226,  -602,  -602,  -602,   227,  -602,   228,  -602,
    -602,   229,   230,   231,   232,  -602,  -602,  -602,   235,   237,
    -602,  -602,   238,   239,   240,  -103,  -602,  -602,  -602,  1889,
     955,   247,   359,   170,   170,   399,   404,   132,   234,   251,
     252,   253,  -602,   254,   181,   256,   259,  -602,   258,  -602,
    -602,  -602,  -602,  -602,  -602,   263,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,   181,   181,
    -602,  -602,   216,  -109,  -602,  -602,  -602,   171,  -602,  -602,
    -602,   262,  -602,  -602,  -602,   -75,  -602,  -602,   477,   260,
     -44,  -602,  -602,   287,   277,  -602,   264,  -602,  2903,   499,
     189,   170,   534,  2903,   505,   189,   534,   514,   520,   534,
    2903,   534,   521,   522,   534,   527,   534,   534,  2317,   534,
     534,    34,   529,   -63,   530,   534,  3016,   534,  2903,   534,
    3016,   274,  3016,  3016,   189,   142,   537,  3016,  3333,   324,
    -602,   318,  -602,  -602,  -602,   321,  -602,   322,  -602,   325,
    -602,   326,   327,   328,  -602,  -602,    71,  2903,  -602,   331,
    -602,  -602,   331,   -97,  -602,  -602,  -602,   332,   349,  -602,
    -602,  -602,  -602,   -43,   107,   341,  -602,   534,   136,  2317,
    -602,  -602,    21,    55,  -602,   346,  -602,   170,   347,   355,
     342,  -602,   170,   570,  -602,    13,   247,    33,   350,   376,
     352,  -602,  -602,   353,   354,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,   356,  -602,   534,   534,   534,   534,
     534,   534,   768,  2589,  -105,  -602,   357,   366,   363,   389,
    2589,   364,   365,  -602,   -98,   367,   371,   372,   373,   375,
     381,   382,   384,  2352,   387,  2903,   116,   388,   -94,  -602,
    2589,  -602,  -602,  -602,   390,   391,   392,   393,   403,   394,
     -92,   395,   423,  2422,   397,  -602,  -602,  -602,  -602,  -602,
    -602,   398,   400,   406,   407,   417,  -602,   411,   414,   416,
    -602,  3333,   620,  -602,  -602,  -602,  -602,  -602,  -602,  -602,
     181,    67,    74,    71,   421,   492,  1377,  1243,   449,   -48,
     428,  -602,  -602,  -602,  -602,   205,  -602,  2499,   427,   455,
    -602,  -602,  -602,  -602,  -602,  -602,   -89,  -602,  -602,   476,
    -602,  -602,    76,   534,  -602,  -602,   457,  -602,    37,  -602,
    2903,  -602,  2903,   431,  -602,   435,  -602,   436,  -602,   505,
    -602,  -602,  -602,  3064,    38,    38,    38,    38,    38,    38,
    2447,   241,  3177,   171,   534,   534,   663,   534,   534,   534,
     534,   534,   534,   534,   534,   534,   534,   534,   534,   534,
     534,   534,   534,   534,   664,   534,   534,  -602,  -602,   665,
    -602,   534,  -602,  -602,   660,  -602,  -602,  -602,  -602,  -602,
    -602,  -602,  -602,  -602,  -602,  -602,   116,  -602,  1981,  -602,
     116,  -602,  -602,  -602,   -72,  -602,   534,  -602,  -602,  -602,
    -602,  -602,   534,  -602,  -602,  -602,  2903,  -602,  -602,  -602,
    -602,  -602,  -602,   667,  -602,  -602,  -602,  -602,   440,  -602,
    -602,   472,    71,    17,  -602,    71,  -602,  -117,  -602,   323,
    -602,   421,   458,    71,  -602,  2903,  -602,  -602,   480,   460,
    1591,   459,  -602,  -602,  -602,  2225,    21,  -602,   465,   463,
     476,  -602,  -602,   170,   481,  -602,  -602,   116,   466,   181,
     199,   170,  -602,  -602,  -602,   241,  -602,  -602,  2103,  -602,
     241,  -602,   468,   -70,   171,  -602,   155,   155,  -602,  1092,
    1092,   177,   177,   877,  2623,  2568,   545,  1632,   694,   177,
     177,   161,   161,    38,    38,    38,  -602,  2527,  -602,  -602,
     469,  -602,  -602,    82,  -602,   470,   116,   471,  -602,  2317,
    -602,  -602,   473,  -602,  -602,    71,  1099,   181,  -602,   170,
     421,   478,   479,  -602,  -602,  -602,   490,  -602,  -602,  -602,
    -602,  -602,  2903,   491,  -602,  -602,  -602,  -602,  -602,   691,
    -602,  -602,  -602,  -602,   500,  -602,  -112,  -602,  -602,   482,
    -602,   474,   362,  -602,   488,   116,   493,  -602,   534,  2317,
    -602,  -602,   534,  -602,  -602,  -602,    82,  -602,  -602,  -602,
     495,  -602,  -602,  -602,  -602,  -602,  -602,   323,  -602,  -602,
     421,  1499,  -602,   501,   534,  -602,   116,  -602,  -602,  -602,
    -602,    82,  -602,  -602,  -602,    38,   497,  2589,  -602,  -602,
    -602,  -602,    71,  -602,  -602,  -602,    14,  -602,  -602,  -602,
     534,   515,  -602,  -602,   516,  -120,  -120,  -602,  -602,   503,
    -602,  -602
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,     0,    45,   434,   443,     0,   300,
     292,   311,     0,   362,     0,     0,   299,   287,   301,   358,
     298,   302,   303,     0,   361,   305,   312,   313,   310,     0,
     303,     0,     0,   360,     0,     0,   303,     0,   307,   359,
     287,   287,   297,   425,   293,    92,     2,    19,    46,     0,
      40,    20,    43,    20,    18,     0,    78,   427,     0,   426,
     294,     0,     0,    12,     0,    16,     0,    14,     0,     0,
       0,    38,     0,    10,    17,   369,   369,   369,     0,     0,
     429,   435,   369,     0,   431,   314,     0,     4,   443,     0,
     289,   290,   322,   318,     0,   329,   428,     0,   288,   304,
     309,     0,   342,   308,   324,     0,   320,     0,   306,   295,
     430,     0,   432,     0,   296,     0,    94,     0,    96,    97,
       0,    98,    99,   100,     0,     0,   103,   104,   105,   106,
     107,     0,     0,   110,     0,   112,   113,   114,   115,     0,
     117,   118,   119,     0,   121,   122,   123,     0,     0,   126,
     127,     0,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,   139,     0,   141,   142,     0,   144,     0,   146,
     147,   150,     0,   151,   152,     0,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,     0,   166,   167,
     168,     0,     0,   171,   172,   173,   174,   423,   175,     0,
     177,   421,     0,   179,   180,   181,     0,   183,     0,   185,
     186,     0,     0,     0,     0,   191,   422,   192,     0,     0,
     196,   197,     0,     0,     0,     0,    80,   201,    41,    77,
      77,    77,   287,     0,     0,   287,   287,     0,   427,     0,
       0,     0,   350,     0,     0,   429,   431,    42,   289,   436,
      11,    15,    13,     6,     9,     0,    39,   352,     8,   373,
     370,   372,   371,   204,   205,   206,   207,   363,     0,     0,
     291,   377,   413,   376,   284,   427,   429,   369,   431,   365,
      44,     0,   455,   454,   456,     0,   451,   444,     0,     0,
      77,    60,   343,     0,     0,   270,     0,   276,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,     0,     0,     0,     0,     0,   223,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    92,    79,
      61,     0,    33,    34,    35,     0,    27,     0,    31,     0,
      29,     0,     0,     0,    25,    32,    38,     0,    78,   428,
      63,   356,   430,   432,    64,   325,   325,     0,   337,    36,
     283,   315,     5,     0,     0,     0,   375,     0,     0,    66,
     379,   366,     0,     0,   450,     0,    59,     0,     0,   214,
     219,   215,     0,     0,   433,    77,    77,    77,     0,     0,
       0,   203,   202,     0,     0,   234,   225,   226,   227,   231,
     232,   233,   228,   229,     0,   230,     0,     0,     0,     0,
       0,     0,     0,   268,     0,   266,     0,    88,     0,     0,
     269,     0,     0,    83,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   398,     0,     0,   221,
     224,    85,    86,    87,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   420,   415,   416,   417,   418,
     419,     0,     0,     0,     0,   440,   442,     0,     0,     0,
      81,    92,     0,    26,    30,    28,    23,    22,    21,    65,
       0,    77,    77,    38,     0,   348,    77,    77,     0,    77,
       0,   364,   374,   378,   414,     0,    76,     0,     0,    70,
      67,    68,   461,   459,   462,   460,     0,   457,   452,   445,
     217,   220,    77,     0,   339,   340,   344,    48,     0,   424,
       0,   271,     0,     0,   438,    78,   277,     0,    93,     0,
      95,   195,   101,     0,   258,   257,   256,   259,   254,   255,
       0,   386,     0,   369,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   102,   108,     0,
     109,     0,   116,   120,     0,   124,   125,   128,   134,   135,
     136,   137,   138,   140,   143,   145,   398,   363,    66,   403,
     398,   400,   399,    73,   395,   149,   223,   148,   153,   165,
     169,   170,     0,   178,   182,   184,     0,   187,   188,   190,
     189,   193,   194,     0,   198,   199,   200,    82,     0,    20,
     406,   437,    38,     0,   326,    38,   323,   289,   316,     0,
     338,     0,     0,    38,    37,    78,     7,   331,     0,     0,
       0,     0,    75,    74,   380,     0,     0,   453,   449,     0,
     445,   216,   218,     0,     0,    49,    47,     0,   431,     0,
     429,   285,   275,   274,    90,   386,   265,   363,    66,   390,
     386,   387,     0,   383,   369,   367,   247,   248,   260,   241,
     242,   245,   246,   236,   237,     0,   238,   239,   240,   244,
     243,   250,   249,   252,   253,   251,   261,     0,   267,    89,
       0,    84,    72,   398,   363,     0,   398,     0,   394,    66,
     402,   222,     0,    91,   441,    38,    77,     0,   319,     0,
       0,     0,     0,   321,   317,   346,   349,    36,   357,   333,
     332,   335,     0,     0,   282,   336,    71,    69,   458,     0,
     448,   446,   341,   345,   408,   411,     0,   273,   280,     0,
     286,     0,   386,   363,     0,   398,     0,   382,     0,    66,
     389,   368,     0,   264,   111,   393,   398,   404,   397,   401,
       0,   176,    62,    24,   407,   355,   353,     0,   327,   328,
       0,    77,   334,     0,     0,   410,     0,   272,   208,   263,
     381,   398,   391,   385,   388,   262,     0,   235,   396,   405,
     354,   347,    38,   447,   409,   412,     0,   384,   392,   351,
       0,     0,   439,   209,     0,    77,    77,   279,   211,     0,
     210,   278
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -602,  -602,  -602,   360,  -602,   -52,  -602,    -4,  -302,     6,
    -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,  -602,    22,
    -481,  -602,  -602,  -284,  -244,  -226,    -2,  -602,  -602,  -602,
     195,  -266,  -602,  -279,  -227,   -65,  -602,  -602,  -602,  -602,
    -602,   215,     2,   408,   133,   261,  -602,  -304,  -306,  -602,
    -602,  -602,  -602,   -90,  -303,  -602,    88,  -602,    41,    11,
     -62,  -602,    66,   121,  -456,  -564,    12,    23,    18,    25,
      20,    28,    29,   377,  -602,    16,  -602,  -602,  -602,  -602,
    -602,    81,  -602,     9,  -602,  -602,  -602,  -602,    30,  -602,
    -602,  -602,  -602,    31,  -602,  -602,  -357,  -553,   -47,   242,
     -41,   -29,  -206,  -602,  -602,  -602,  -585,  -602,  -601,  -602,
    -463,  -602,  -602,  -602,   -35,  -602,   504,  -602,   426,     0,
    -343,   -40,  -602,     4,  -602,   674,   104,  -602,  -602,   112,
    -602,   401,  -602,   124
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    46,     2,   372,   229,   629,   496,   257,   342,
      48,   528,    49,    50,    51,    52,   343,   237,    53,   344,
     508,   509,   510,   511,   599,    55,   358,   225,   434,   454,
     428,   398,   461,   226,   403,   600,   816,   823,   388,   389,
     390,   391,   275,   448,   449,   423,   424,   425,   431,   395,
     531,   536,   397,   828,   829,   743,    58,   759,    97,   270,
     601,    59,   100,    60,    61,   640,   345,   346,   347,   348,
     349,   350,   351,   491,   634,   352,    70,   499,   650,    71,
     495,   525,   526,   353,   392,   664,   736,   642,   354,   368,
     731,   732,   243,   355,    75,    76,    77,   374,    78,   551,
     259,    79,   272,   273,   681,   766,   682,   683,   602,   717,
     603,   604,   631,   795,   755,   756,   274,   471,   227,   276,
      81,    82,    83,   278,   477,    87,   659,   660,    88,    89,
     285,   286,   516,   517
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   230,    80,   435,    57,   357,    84,   437,    47,   244,
     440,    72,   442,   269,    62,   447,   271,   501,    69,    92,
      64,   458,    66,    93,    54,    63,    95,    65,    98,   380,
      67,    68,    73,    74,   444,   261,   262,   426,   639,   277,
     102,   279,  -449,   665,   713,   106,   260,   260,   260,   512,
    -289,    98,    98,   260,   489,   556,   245,   820,   238,   480,
     246,   451,   375,   376,   387,   242,   754,   294,   239,   296,
      29,   504,   249,   821,   240,   648,   241,   735,   429,   553,
    -289,   111,   113,   729,   281,    90,   255,    91,   197,   513,
     761,   796,   201,   533,   537,   767,   103,     3,   576,  -289,
     338,   -55,   108,   498,    45,   584,    85,   474,   827,   606,
      90,   606,    91,   282,   656,   378,   797,   715,   297,    90,
     379,    91,   339,   216,   762,   577,   263,   283,   383,  -289,
     730,    13,   585,   712,    94,   284,   607,   718,   614,   405,
     101,   657,   406,   407,   408,   409,   410,   411,   475,   476,
     384,   263,   378,    86,   378,    99,    13,   719,   109,   769,
     263,   776,   104,   114,   452,   264,   231,   228,   502,   530,
     532,   532,   556,    90,   105,    91,    45,   800,   556,   269,
      45,   253,   271,  -212,    90,   639,    91,   514,    15,   -50,
     264,   636,   554,   555,   556,   754,   649,   764,   401,   264,
     553,   402,   627,   269,   269,   453,   271,   271,   405,   684,
     801,   406,   407,   408,   409,   410,   411,   107,   412,   662,
      13,    96,   515,    91,   265,   263,   811,    56,    56,    80,
      80,    57,    57,    84,    84,   247,   381,    45,   780,   404,
     529,   822,   289,    98,   360,   361,    98,    98,   260,   265,
     775,   399,    19,   778,   250,   266,   399,    45,   265,   288,
     534,   574,   575,   436,   264,   633,   633,   666,   251,   290,
     413,   446,   708,   532,   787,   710,   111,   113,    24,   252,
     266,   462,   254,   293,   630,   263,   459,   412,   806,   266,
     464,    45,   472,   473,   632,   597,   387,   479,    45,   256,
      45,   635,   803,  -213,   414,   258,   378,   679,   722,   269,
     490,   598,   271,   808,   -52,   110,   445,    91,   415,   112,
     267,    91,   280,   265,   264,   520,   248,    33,    91,   597,
     728,   -54,   446,   733,   639,  -289,   268,   -51,   817,   413,
     378,   738,   291,    39,   416,   598,   292,   417,   418,   505,
     723,   295,   420,   421,   266,  -289,   501,   -53,   364,   298,
     720,   506,   359,   299,    91,   422,   569,   570,   571,   572,
     573,   747,   300,   414,   571,   572,   573,   445,   574,   575,
     301,   302,   500,   265,   574,   575,   303,   415,   569,   570,
     571,   572,   573,   552,   267,   535,   304,   305,   596,   465,
     574,   575,   362,   524,    91,   501,   263,   363,   306,    91,
     268,    13,   307,   416,   266,   308,   417,   418,   419,   501,
     309,   420,   421,   782,   637,   269,    91,  -281,   271,  -281,
     652,   679,   310,   311,   422,   312,   679,   313,   314,   770,
     315,   316,   317,   318,   501,   264,   319,   377,   320,   321,
     322,   323,   324,   325,   677,   326,   327,   328,   329,   330,
     331,   332,   -56,   758,   333,   378,   334,   335,   336,   337,
     678,    45,   466,   467,   468,   469,   470,   365,   366,   367,
     369,   371,   385,   667,   -57,   669,   680,   -58,   814,   373,
     386,   382,   393,   396,   645,    56,    80,    80,    57,    57,
      84,    84,   644,    47,   265,   638,    72,   394,   400,    62,
     819,   427,   685,    69,   552,    64,   824,    66,   679,    54,
      63,   784,    65,   432,   260,    67,    68,    73,    74,   433,
     438,   439,   670,   716,   668,   266,   441,   405,   455,   457,
     406,   407,   408,   409,   410,   411,   478,   482,   481,   483,
     484,   446,   486,   485,   494,   487,   488,  -289,   522,   493,
     554,   555,   556,   557,   558,   559,   560,   430,    11,   399,
     430,   503,   519,   523,   521,   677,   527,   726,   443,   539,
     538,   450,   540,   541,   542,   543,   378,   578,   450,   579,
     463,   678,   581,   580,   582,   583,   445,   586,   244,   532,
     532,   587,   588,   589,   269,   590,   612,   271,   446,   760,
     680,   591,   592,   765,   593,   680,   412,   595,   605,    22,
     608,   609,   610,   611,   613,   615,   616,   618,   619,   628,
     620,   446,    25,    26,    27,    28,   621,   622,   430,   507,
     623,   624,    30,   771,   625,   245,   626,   238,   742,   246,
     734,   641,   638,   445,   647,   260,   651,   654,   655,   658,
     663,   671,   269,   672,   673,   271,   688,   706,   413,   711,
     725,   709,   446,   724,   524,   727,   445,   544,   545,   546,
     547,   548,   549,   550,   737,   739,   745,    36,   740,    86,
     750,   753,    38,   790,   757,   244,   793,   680,   768,   774,
     777,   779,   414,   781,   799,   794,   788,   789,   798,   554,
     555,   556,   557,   558,   559,   560,   415,   445,   802,   792,
     825,   826,   446,   804,    56,   809,    80,   818,    57,   813,
      84,   831,   497,   791,   674,   460,   830,   661,   744,   721,
     785,   786,   416,   492,   752,   417,   418,   419,   370,   456,
     420,   421,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   815,   287,   422,   751,     0,   547,   445,   574,   575,
     749,   405,     0,     6,   406,   407,   408,   409,   410,   411,
     748,     0,     0,     0,   518,   675,     0,     0,     0,   645,
       0,    80,     0,    57,     0,    84,     0,   644,   810,     0,
       0,   638,     0,     0,     0,     9,     0,    10,     0,     0,
       0,     0,     0,    11,     0,   686,   687,    13,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,     0,   707,    16,     0,     0,
       0,     0,   430,   232,    18,     0,     0,     0,     0,    19,
     412,     0,     0,     0,    20,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    22,     0,     0,   450,     0,     0,
       0,     0,     0,     0,     0,    24,     0,    25,    26,    27,
      28,     0,     0,     0,     0,     0,     0,    30,     0,     0,
       0,     0,   554,   555,   556,   557,   558,   559,   560,     0,
     562,     0,   413,   567,   568,   569,   570,   571,   572,   573,
       0,     0,     0,     0,     0,     0,     0,   574,   575,     0,
       0,     0,     0,     0,    33,     0,     0,     0,     0,     0,
       0,    35,    36,    37,     0,     0,   414,    38,     0,     0,
      39,     0,     0,     0,   235,     0,     0,     0,     0,     0,
     415,     0,     0,   236,     0,    42,     0,     0,     4,     5,
       6,     0,     0,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   416,     0,     0,   417,
     418,   419,     0,     0,   420,   421,     8,     0,     0,     0,
       0,     0,     9,     0,    10,     0,     0,   422,     0,     0,
      11,    12,     0,     0,    13,     0,     0,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    15,     0,     0,    16,     0,     0,     0,     0,   805,
      17,    18,     0,   807,     0,     0,    19,     0,     0,     0,
       0,    20,     0,     0,    21,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,   430,     0,     0,    23,   341,
       0,     0,    24,     0,    25,    26,    27,    28,    29,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,    31,     0,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,     0,    32,
     574,   575,     4,     5,     6,     0,     0,   554,   555,   556,
       0,    33,   559,   560,     0,     0,     0,    34,    35,    36,
      37,     0,     0,     0,    38,     0,     0,    39,     0,     0,
       8,    40,     0,     0,     0,     0,     9,     0,    10,     0,
      41,     0,    42,     0,    11,    12,     0,     0,    13,     0,
      43,    44,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,     0,    45,
      19,     0,   356,     0,     0,    20,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,    23,   341,     0,     0,    24,     0,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     4,     5,     6,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,    39,     0,     0,     8,    40,     0,     0,     0,     0,
       9,     0,    10,     0,    41,     0,    42,     0,    11,    12,
       0,     0,    13,     0,    43,    44,     0,     0,     0,    14,
       0,   567,   568,   569,   570,   571,   572,   573,     0,    15,
       0,     0,    16,     0,     0,   574,   575,     0,    17,    18,
       0,     0,     0,    45,    19,     0,   783,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      24,     0,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     0,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     9,    39,    10,     0,     0,    40,
       0,     0,    11,     0,     0,     0,    13,     0,    41,     0,
      42,     0,     0,    14,     0,     0,     0,     0,    43,    44,
       0,     0,     0,     0,     0,     0,    16,     0,     0,     0,
       0,     0,    17,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,     0,    21,    45,     0,     0,
     646,     0,     0,    22,     0,     0,     0,     0,     0,     0,
      23,     0,     0,     0,    24,     0,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,     0,     0,     9,     0,    10,     0,
      35,    36,    37,     0,    11,     0,    38,     0,    13,    39,
       0,     0,     0,    40,     0,    14,     0,     0,     0,     0,
       0,     0,    41,     0,    42,     0,     0,     0,    16,     0,
       0,     0,    43,    44,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,     0,     0,    21,     0,
       0,     0,     0,     0,     4,    22,     6,     0,     0,     0,
       0,    45,    23,     0,   643,     0,    24,     0,    25,    26,
      27,    28,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     9,     0,
      10,     0,     0,     0,     0,     0,    11,     0,     0,     0,
      13,     0,     0,    32,     0,     0,     0,   554,   555,   556,
     557,   558,   559,   560,     0,    33,     0,     0,     0,     0,
      16,     0,    35,    36,    37,     0,   232,    18,    38,     0,
       0,    39,    19,     0,     0,    40,     0,    20,     0,     0,
      21,     0,     0,     0,    41,     0,    42,    22,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,    24,     0,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,    45,     0,     0,   812,     7,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,     0,     0,    33,     0,     0,
       9,     0,    10,     0,    35,    36,    37,     0,    11,    12,
      38,     0,    13,    39,     0,     0,     0,   235,     0,    14,
       0,     0,     0,     0,     0,     0,   236,     0,    42,    15,
       0,     0,    16,     0,     0,     0,    43,    44,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,    45,    23,     0,   741,     0,
      24,     0,    25,    26,    27,    28,    29,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,    31,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,     0,   574,   575,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,    39,     0,     0,     0,    40,
       0,     0,     4,     5,     6,     0,   -77,     0,    41,     0,
      42,     0,   340,     0,     0,     0,     0,     0,    43,    44,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       8,     0,     0,     0,     0,     0,     9,     0,    10,     0,
       0,     0,     0,     0,    11,    12,     0,    45,    13,     0,
       0,     0,     0,     0,     0,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    16,     0,
       0,     0,     0,     0,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,     0,    20,     0,     0,    21,     0,
       0,     0,     0,     0,     4,    22,     6,     0,     0,     0,
       0,     0,    23,   341,     0,     0,    24,     0,    25,    26,
      27,    28,    29,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,    31,     0,     0,     9,     0,
      10,     0,     0,     0,     0,   263,    11,     0,     0,     0,
      13,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
      16,    34,    35,    36,    37,     0,   232,    18,    38,     0,
       0,    39,    19,     0,   264,    40,     0,    20,     0,     0,
      21,     0,     0,     0,    41,     0,    42,    22,     0,     0,
       0,     0,     0,     0,    43,    44,     0,     0,    24,     0,
      25,    26,    27,    28,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     4,     0,     6,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   265,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       9,     0,    10,     0,    35,    36,    37,   263,    11,     0,
      38,     0,    13,    39,   266,     0,     0,   235,     0,     0,
       0,     0,     0,     0,     0,     0,   236,     0,    42,     0,
       0,     0,    16,     0,     0,     0,    43,    44,   232,    18,
       0,     0,     0,     0,    19,     0,   264,     0,     0,    20,
       0,     0,    21,     0,   714,     0,     0,     0,     0,    22,
       0,     0,     0,     0,     0,    45,     0,     0,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     4,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   265,     0,     0,     0,   746,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     9,     0,    10,     0,    35,    36,    37,     0,
      11,     0,    38,     0,    13,    39,   266,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
      42,     0,     0,     0,    16,     0,     0,     0,    43,    44,
     232,    18,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    20,     0,     0,    21,     0,   763,     0,     0,     0,
       4,    22,     6,     0,     0,     0,     0,    45,     0,     0,
       0,     0,    24,     0,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     9,     0,    10,     0,     0,     0,
       0,     0,    11,     0,     0,     0,    13,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,     0,     0,
       0,    33,     0,     0,     0,     0,    16,     0,    35,    36,
      37,     0,   232,    18,    38,     0,     0,    39,    19,     0,
       0,   235,     0,    20,     0,     0,    21,     0,     0,     0,
     236,     0,    42,    22,     0,     0,     0,     0,     0,     0,
      43,    44,     0,     0,    24,     0,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,    30,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,     0,    45,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   554,   555,   556,   557,   558,   559,   560,   561,
     562,     0,     0,    33,     0,     0,     0,     0,     0,     0,
      35,    36,    37,     0,     0,     0,    38,     0,     0,    39,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,   236,     0,    42,     0,     0,     0,     0,     0,
       0,     0,    43,    44,   554,   555,   556,   557,   558,   559,
     560,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,   554,   555,   556,   557,   558,   559,   560,   561,
     562,     0,     0,     0,     0,     0,   563,     0,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,     0,     0,
       0,     0,     0,     0,     0,   574,   575,     0,     0,     0,
       0,     0,   594,   554,   555,   556,   557,   558,   559,   560,
     561,   562,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,   558,   559,
     560,   561,   562,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   563,     0,   564,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   554,   555,
     556,   557,   558,   559,   560,   574,   575,     0,     0,     0,
       0,   563,   617,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,     0,     0,
     574,   575,     0,     0,     0,     0,     0,   676,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   563,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,     0,     0,     0,     0,     0,
       0,     0,   574,   575,   653,     0,     0,     0,     0,     0,
       0,   563,     0,   564,   565,   566,   567,   568,   569,   570,
     571,   572,   573,     0,     0,     0,     0,     0,     0,     0,
     574,   575,   773,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   563,   772,   564,   565,   566,   567,   568,   569,
     570,   571,   572,   573,     0,     0,     0,     0,     0,     0,
       0,   574,   575,   563,     0,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,     0,     0,     0,     0,     0,
       0,     0,   574,   575,     4,     0,     6,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   564,
     565,   566,   567,   568,   569,   570,   571,   572,   573,     0,
       0,     0,     8,     0,     0,     0,   574,   575,     9,     0,
      10,     0,     0,     0,     0,     0,    11,    12,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -330,     0,     0,
      16,     0,     0,     0,     0,     0,   232,    18,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     4,    22,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,     0,
      25,    26,    27,    28,    29,     0,     0,   233,     0,     0,
      30,     0,     0,     0,     0,   234,     0,     0,     0,     0,
       9,     0,    10,     0,     0,     0,     0,     0,    11,     0,
       0,     0,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
       0,     0,    16,    34,    35,    36,    37,     0,   232,    18,
      38,     0,     0,    39,    19,     0,     0,   235,     0,    20,
       0,     0,    21,     0,     0,     0,   236,     0,    42,    22,
       0,     0,     0,     0,     0,     0,    43,    44,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     4,
       0,     6,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,     0,    10,     0,     0,     0,    33,
       0,    11,     0,     0,     0,     0,    35,    36,    37,     6,
       0,     0,    38,     0,     0,    39,     0,     0,     0,   235,
       0,     0,     0,     0,     0,    16,     0,     0,   236,     0,
      42,   232,    18,     0,     0,     0,     0,     0,    43,    44,
       0,     9,    20,    10,     0,    21,     0,     0,     0,    11,
       0,     0,    22,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,     0,
       0,     0,     0,    16,     0,    30,     0,     0,     0,   232,
      18,     0,     0,     0,     0,    19,     0,     0,     0,     0,
      20,     0,     0,    21,     0,     0,     0,     0,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,     0,    25,    26,    27,    28,     0,     0,    35,
      36,    37,     6,    30,     0,    38,     0,     0,     0,     0,
       0,     0,   235,     0,     0,     0,     0,     0,     0,     0,
       0,   236,     0,    42,     0,     0,     0,     0,     0,     0,
       0,    43,    44,     0,     9,     0,    10,     0,     0,     0,
      33,     0,    11,     0,     0,     0,     0,    35,    36,    37,
       0,     0,     0,    38,     0,     0,    39,     0,     0,     0,
     235,     0,     0,     0,     0,     0,    16,     0,     0,   236,
       0,    42,   232,    18,     0,     0,     0,     0,     0,    43,
      44,     0,     0,    20,     0,     0,    21,     0,     0,     0,
       0,     0,     0,    22,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      35,    36,    37,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,   235,     0,     0,     0,     0,   115,   116,
       0,     0,   236,   117,    42,   118,   119,   120,   121,   122,
       0,   123,    43,    44,   124,     0,   125,     0,     0,     0,
     126,   127,     0,   128,   129,   130,   131,   132,   133,     0,
     134,   135,   136,   137,   138,   139,   140,   141,   142,     0,
     143,     0,     0,   144,   145,   146,   147,   148,     0,     0,
     149,   150,   151,   152,     0,     0,     0,   153,   154,     0,
     155,   156,     0,   157,   158,   159,   160,   161,   162,     0,
     163,   164,   165,   166,   167,   168,     0,     0,   169,     0,
       0,   170,     0,     0,     0,     0,     0,   171,   172,     0,
     173,   174,     0,   175,   176,   177,     0,     0,     0,     0,
     178,   179,   180,     0,   181,   182,   183,     0,   184,   185,
     186,   187,   188,   189,   190,     0,   191,     0,   192,     0,
     193,   194,   195,   196,   197,   198,   199,   200,   201,     0,
     202,   203,     0,   204,   205,     0,     0,     0,     0,     0,
     206,     0,     0,   207,     0,   208,     0,   209,   210,     0,
       0,   211,   212,   213,   214,     0,     0,   215,     0,   216,
       0,   217,   218,   219,   220,   221,   222,   223,     0,     0,
     224
};

static const yytype_int16 yycheck[] =
{
       2,    53,     2,   309,     2,   231,     2,   311,     2,    56,
     314,     2,   316,    78,     2,   319,    78,   374,     2,     8,
       2,   325,     2,    12,     2,     2,    15,     2,    17,   273,
       2,     2,     2,     2,   318,    76,    77,   303,   494,    79,
      29,    82,   113,     6,   597,    34,    75,    76,    77,    28,
     177,    40,    41,    82,   356,    17,    56,    43,    56,   338,
      56,    27,   268,   269,   290,    56,   667,   107,    56,   177,
     113,   377,    61,    59,    56,   123,    56,   641,   305,   422,
     177,    40,    41,    66,    29,     3,    70,     5,   151,    68,
     675,   203,   155,   396,   397,   680,    30,     0,   203,   226,
     203,   228,    36,   146,   224,   203,   223,   334,   228,   203,
       3,   203,     5,    58,   203,   224,   228,   598,   226,     3,
     229,     5,   225,   186,   677,   230,    44,    72,   203,   226,
     113,    49,   230,   596,   229,    80,   230,   600,   230,     3,
       9,   230,     6,     7,     8,     9,    10,    11,     6,     7,
     225,    44,   224,   224,   224,   109,    49,   229,    37,   229,
      44,   714,     3,    42,   130,    83,   183,   228,   374,   395,
     396,   397,    17,     3,   229,     5,   224,   762,    17,   244,
     224,   226,   244,   227,     3,   641,     5,   166,    66,   228,
      83,   493,    15,    16,    17,   796,   499,   678,     9,    83,
     543,    12,   481,   268,   269,   171,   268,   269,     3,   552,
     763,     6,     7,     8,     9,    10,    11,   229,    82,   523,
      49,     3,   201,     5,   142,    44,   790,   229,   230,   229,
     230,   229,   230,   229,   230,   228,   277,   224,   719,   301,
     227,   227,     9,   232,   233,   234,   235,   236,   277,   142,
     713,   298,    81,   716,   228,   173,   303,   224,   142,   113,
     227,   223,   224,   310,    83,   491,   492,   230,   228,   226,
     134,   318,   576,   499,   730,   581,   235,   236,   107,   228,
     173,   328,   228,     3,   490,    44,   326,    82,   769,   173,
     330,   224,   332,   333,   227,   213,   522,   337,   224,   228,
     224,   227,   765,   227,   168,   228,   224,   551,   612,   374,
     357,   229,   374,   776,   228,     3,   318,     5,   182,     3,
     213,     5,   228,   142,    83,   387,     3,   156,     5,   213,
     632,   228,   379,   635,   790,   226,   229,   228,   801,   134,
     224,   643,   228,   172,   208,   229,   209,   211,   212,   213,
     616,   226,   216,   217,   173,   226,   713,   228,   226,   229,
     604,   225,     3,   229,     5,   229,   211,   212,   213,   214,
     215,   655,   229,   168,   213,   214,   215,   379,   223,   224,
     229,   229,   373,   142,   223,   224,   229,   182,   211,   212,
     213,   214,   215,   422,   213,   397,   229,   229,   445,   125,
     223,   224,     3,   392,     5,   762,    44,     3,   229,     5,
     229,    49,   229,   208,   173,   229,   211,   212,   213,   776,
     229,   216,   217,   725,     3,   490,     5,   228,   490,   230,
     225,   675,   229,   229,   229,   229,   680,   229,   229,   683,
     229,   229,   229,   229,   801,    83,   229,   231,   229,   229,
     229,   229,   229,   229,   213,   229,   229,   229,   229,   229,
     229,   229,   228,   669,   229,   224,   229,   229,   229,   229,
     229,   224,   198,   199,   200,   201,   202,   226,   226,   226,
     226,   223,     5,   530,   228,   532,   551,   228,   794,   226,
     230,   229,   205,   229,   496,   497,   496,   497,   496,   497,
     496,   497,   496,   497,   142,   494,   497,   230,     9,   497,
     812,     6,   553,   497,   543,   497,   820,   497,   762,   497,
     497,   727,   497,     9,   553,   497,   497,   497,   497,     9,
       9,     9,   532,   598,   530,   173,     9,     3,     9,     9,
       6,     7,     8,     9,    10,    11,     9,   229,   224,   228,
     228,   598,   226,   228,   205,   228,   228,   226,   203,   227,
      15,    16,    17,    18,    19,    20,    21,   306,    45,   616,
     309,   230,   226,   231,   227,   213,     6,   629,   317,   203,
     230,   320,   230,   230,   230,   229,   224,   230,   327,   223,
     329,   229,   203,   230,   230,   230,   598,   230,   645,   825,
     826,   230,   230,   230,   669,   230,   203,   669,   655,   671,
     675,   230,   230,   678,   230,   680,    82,   230,   230,    96,
     230,   230,   230,   230,   230,   230,   203,   230,   230,     9,
     230,   678,   109,   110,   111,   112,   230,   230,   377,   378,
     223,   230,   119,   684,   230,   645,   230,   645,   650,   645,
     639,   159,   641,   655,   205,   684,   228,   230,   203,   183,
     203,   230,   727,   228,   228,   727,     3,     3,   134,     9,
     230,     6,   719,     6,   663,   203,   678,   416,   417,   418,
     419,   420,   421,   422,   226,   205,   227,   164,   228,   224,
     227,   210,   169,   203,   228,   742,     5,   762,   230,   230,
     230,   230,   168,   230,   230,   205,   228,   228,   226,    15,
      16,    17,    18,    19,    20,    21,   182,   719,   230,   228,
     205,   205,   769,   230,   726,   230,   726,   230,   726,   228,
     726,   228,   372,   737,   539,   327,   826,   522,   650,   606,
     729,   730,   208,   366,   663,   211,   212,   213,   244,   323,
     216,   217,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   796,    88,   229,   660,    -1,   505,   769,   223,   224,
     658,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
     656,    -1,    -1,    -1,   383,   543,    -1,    -1,    -1,   791,
      -1,   791,    -1,   791,    -1,   791,    -1,   791,   787,    -1,
      -1,   790,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,   554,   555,    49,   557,   558,
     559,   560,   561,   562,   563,   564,   565,   566,   567,   568,
     569,   570,   571,   572,   573,    -1,   575,    69,    -1,    -1,
      -1,    -1,   581,    75,    76,    -1,    -1,    -1,    -1,    81,
      82,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    -1,   606,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   107,    -1,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,   134,   209,   210,   211,   212,   213,   214,   215,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   223,   224,    -1,
      -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,
      -1,   163,   164,   165,    -1,    -1,   168,   169,    -1,    -1,
     172,    -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,
     182,    -1,    -1,   185,    -1,   187,    -1,    -1,     3,     4,
       5,    -1,    -1,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   208,    -1,    -1,   211,
     212,   213,    -1,    -1,   216,   217,    31,    -1,    -1,    -1,
      -1,    -1,    37,    -1,    39,    -1,    -1,   229,    -1,    -1,
      45,    46,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    -1,    69,    -1,    -1,    -1,    -1,   768,
      75,    76,    -1,   772,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    96,    -1,    -1,    -1,   794,    -1,    -1,   103,   104,
      -1,    -1,   107,    -1,   109,   110,   111,   112,   113,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,   126,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     223,   224,     3,     4,     5,    -1,    -1,    15,    16,    17,
      -1,   156,    20,    21,    -1,    -1,    -1,   162,   163,   164,
     165,    -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,
      31,   176,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
     185,    -1,   187,    -1,    45,    46,    -1,    -1,    49,    -1,
     195,   196,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,   224,
      81,    -1,   227,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,   103,   104,    -1,    -1,   107,    -1,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   144,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      -1,   162,   163,   164,   165,    -1,    -1,    -1,   169,    -1,
      -1,   172,    -1,    -1,    31,   176,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,   185,    -1,   187,    -1,    45,    46,
      -1,    -1,    49,    -1,   195,   196,    -1,    -1,    -1,    56,
      -1,   209,   210,   211,   212,   213,   214,   215,    -1,    66,
      -1,    -1,    69,    -1,    -1,   223,   224,    -1,    75,    76,
      -1,    -1,    -1,   224,    81,    -1,   227,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   103,    -1,    -1,    -1,
     107,    -1,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,    -1,    -1,    -1,    -1,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    37,   172,    39,    -1,    -1,   176,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,   185,    -1,
     187,    -1,    -1,    56,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    -1,    -1,    -1,    81,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    89,   224,    -1,    -1,
     227,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     103,    -1,    -1,    -1,   107,    -1,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   156,    -1,    -1,    37,    -1,    39,    -1,
     163,   164,   165,    -1,    45,    -1,   169,    -1,    49,   172,
      -1,    -1,    -1,   176,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,   187,    -1,    -1,    -1,    69,    -1,
      -1,    -1,   195,   196,    75,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,     3,    96,     5,    -1,    -1,    -1,
      -1,   224,   103,    -1,   227,    -1,   107,    -1,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      49,    -1,    -1,   144,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    -1,   156,    -1,    -1,    -1,    -1,
      69,    -1,   163,   164,   165,    -1,    75,    76,   169,    -1,
      -1,   172,    81,    -1,    -1,   176,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,   185,    -1,   187,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,   107,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,    -1,    -1,   224,    -1,    -1,   227,    14,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    -1,    -1,   156,    -1,    -1,
      37,    -1,    39,    -1,   163,   164,   165,    -1,    45,    46,
     169,    -1,    49,   172,    -1,    -1,    -1,   176,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,   187,    66,
      -1,    -1,    69,    -1,    -1,    -1,   195,   196,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   224,   103,    -1,   227,    -1,
     107,    -1,   109,   110,   111,   112,   113,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,    -1,   126,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,   144,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    -1,    -1,    -1,   162,   163,   164,   165,    -1,
      -1,    -1,   169,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,    -1,     3,     4,     5,    -1,   183,    -1,   185,    -1,
     187,    -1,    13,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    -1,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    -1,   224,    49,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,    69,    -1,
      -1,    -1,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      81,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,     3,    96,     5,    -1,    -1,    -1,
      -1,    -1,   103,   104,    -1,    -1,   107,    -1,   109,   110,
     111,   112,   113,    -1,    -1,    -1,    -1,    -1,   119,    -1,
      -1,    -1,    -1,    -1,    -1,   126,    -1,    -1,    37,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      49,    -1,    -1,   144,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,    -1,    -1,
      69,   162,   163,   164,   165,    -1,    75,    76,   169,    -1,
      -1,   172,    81,    -1,    83,   176,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,   185,    -1,   187,    96,    -1,    -1,
      -1,    -1,    -1,    -1,   195,   196,    -1,    -1,   107,    -1,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
     119,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,    -1,
      -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      37,    -1,    39,    -1,   163,   164,   165,    44,    45,    -1,
     169,    -1,    49,   172,   173,    -1,    -1,   176,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,   187,    -1,
      -1,    -1,    69,    -1,    -1,    -1,   195,   196,    75,    76,
      -1,    -1,    -1,    -1,    81,    -1,    83,    -1,    -1,    86,
      -1,    -1,    89,    -1,   213,    -1,    -1,    -1,    -1,    96,
      -1,    -1,    -1,    -1,    -1,   224,    -1,    -1,    -1,    -1,
     107,    -1,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,     3,    -1,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,
      -1,    -1,    37,    -1,    39,    -1,   163,   164,   165,    -1,
      45,    -1,   169,    -1,    49,   172,   173,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   185,    -1,
     187,    -1,    -1,    -1,    69,    -1,    -1,    -1,   195,   196,
      75,    76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,   213,    -1,    -1,    -1,
       3,    96,     5,    -1,    -1,    -1,    -1,   224,    -1,    -1,
      -1,    -1,   107,    -1,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,   156,    -1,    -1,    -1,    -1,    69,    -1,   163,   164,
     165,    -1,    75,    76,   169,    -1,    -1,   172,    81,    -1,
      -1,   176,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
     185,    -1,   187,    96,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,   107,    -1,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,    -1,   224,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,   156,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,   172,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   185,    -1,   187,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   195,   196,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   224,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   223,   224,    -1,    -1,    -1,
      -1,    -1,   230,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   204,    -1,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,    15,    16,
      17,    18,    19,    20,    21,   223,   224,    -1,    -1,    -1,
      -1,   204,   230,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,    -1,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,   225,    -1,    -1,    -1,    -1,    -1,
      -1,   204,    -1,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     223,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   204,    -1,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   223,   224,     3,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,    -1,
      -1,    -1,    31,    -1,    -1,    -1,   223,   224,    37,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    81,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,     3,    96,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   107,    -1,
     109,   110,   111,   112,   113,    -1,    -1,   116,    -1,    -1,
     119,    -1,    -1,    -1,    -1,   124,    -1,    -1,    -1,    -1,
      37,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   156,    -1,    -1,
      -1,    -1,    69,   162,   163,   164,   165,    -1,    75,    76,
     169,    -1,    -1,   172,    81,    -1,    -1,   176,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,   185,    -1,   187,    96,
      -1,    -1,    -1,    -1,    -1,    -1,   195,   196,    -1,    -1,
     107,    -1,   109,   110,   111,   112,    -1,    -1,    -1,     3,
      -1,     5,   119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    37,    -1,    39,    -1,    -1,    -1,   156,
      -1,    45,    -1,    -1,    -1,    -1,   163,   164,   165,     5,
      -1,    -1,   169,    -1,    -1,   172,    -1,    -1,    -1,   176,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,   185,    -1,
     187,    75,    76,    -1,    -1,    -1,    -1,    -1,   195,   196,
      -1,    37,    86,    39,    -1,    89,    -1,    -1,    -1,    45,
      -1,    -1,    96,    49,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,    69,    -1,   119,    -1,    -1,    -1,    75,
      76,    -1,    -1,    -1,    -1,    81,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   107,    -1,   109,   110,   111,   112,    -1,    -1,   163,
     164,   165,     5,   119,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,   176,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   185,    -1,   187,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   195,   196,    -1,    37,    -1,    39,    -1,    -1,    -1,
     156,    -1,    45,    -1,    -1,    -1,    -1,   163,   164,   165,
      -1,    -1,    -1,   169,    -1,    -1,   172,    -1,    -1,    -1,
     176,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,   185,
      -1,   187,    75,    76,    -1,    -1,    -1,    -1,    -1,   195,
     196,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,   119,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     163,   164,   165,    -1,    -1,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,   176,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,   185,    30,   187,    32,    33,    34,    35,    36,
      -1,    38,   195,   196,    41,    -1,    43,    -1,    -1,    -1,
      47,    48,    -1,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    -1,
      67,    -1,    -1,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    79,    80,    -1,    -1,    -1,    84,    85,    -1,
      87,    88,    -1,    90,    91,    92,    93,    94,    95,    -1,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,   114,   115,    -1,
     117,   118,    -1,   120,   121,   122,    -1,    -1,    -1,    -1,
     127,   128,   129,    -1,   131,   132,   133,    -1,   135,   136,
     137,   138,   139,   140,   141,    -1,   143,    -1,   145,    -1,
     147,   148,   149,   150,   151,   152,   153,   154,   155,    -1,
     157,   158,    -1,   160,   161,    -1,    -1,    -1,    -1,    -1,
     167,    -1,    -1,   170,    -1,   172,    -1,   174,   175,    -1,
      -1,   178,   179,   180,   181,    -1,    -1,   184,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,    -1,    -1,
     197
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   233,   235,     0,     3,     4,     5,    14,    31,    37,
      39,    45,    46,    49,    56,    66,    69,    75,    76,    81,
      86,    89,    96,   103,   107,   109,   110,   111,   112,   113,
     119,   126,   144,   156,   162,   163,   164,   165,   169,   172,
     176,   185,   187,   195,   196,   224,   234,   241,   242,   244,
     245,   246,   247,   250,   251,   257,   258,   274,   288,   293,
     295,   296,   298,   299,   300,   301,   302,   303,   304,   307,
     308,   311,   315,   320,   325,   326,   327,   328,   330,   333,
     351,   352,   353,   354,   355,   223,   224,   357,   360,   361,
       3,     5,   291,   291,   229,   291,     3,   290,   291,   109,
     294,     9,   291,   294,     3,   229,   291,   229,   294,   295,
       3,   290,     3,   290,   295,    25,    26,    30,    32,    33,
      34,    35,    36,    38,    41,    43,    47,    48,    50,    51,
      52,    53,    54,    55,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    67,    70,    71,    72,    73,    74,    77,
      78,    79,    80,    84,    85,    87,    88,    90,    91,    92,
      93,    94,    95,    97,    98,    99,   100,   101,   102,   105,
     108,   114,   115,   117,   118,   120,   121,   122,   127,   128,
     129,   131,   132,   133,   135,   136,   137,   138,   139,   140,
     141,   143,   145,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   157,   158,   160,   161,   167,   170,   172,   174,
     175,   178,   179,   180,   181,   184,   186,   188,   189,   190,
     191,   192,   193,   194,   197,   259,   265,   350,   228,   237,
     237,   183,    75,   116,   124,   176,   185,   249,   274,   298,
     300,   302,   315,   324,   330,   351,   355,   228,     3,   291,
     228,   228,   228,   226,   228,   307,   228,   240,   228,   332,
     333,   332,   332,    44,    83,   142,   173,   213,   229,   267,
     291,   292,   334,   335,   348,   274,   351,   353,   355,   332,
     228,    29,    58,    72,    80,   362,   363,   357,   113,     9,
     226,   228,   209,     3,   353,   226,   177,   226,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   203,   225,
      13,   104,   241,   248,   251,   298,   299,   300,   301,   302,
     303,   304,   307,   315,   320,   325,   227,   257,   258,     3,
     291,   291,     3,     3,   226,   226,   226,   226,   321,   226,
     348,   223,   236,   226,   329,   334,   334,   231,   224,   229,
     256,   332,   229,   203,   225,     5,   230,   257,   270,   271,
     272,   273,   316,   205,   230,   281,   229,   284,   263,   330,
       9,     9,    12,   266,   292,     3,     6,     7,     8,     9,
      10,    11,    82,   134,   168,   182,   208,   211,   212,   213,
     216,   217,   229,   277,   278,   279,   263,     6,   262,   266,
     277,   280,     9,     9,   260,   280,   330,   279,     9,     9,
     279,     9,   279,   277,   255,   258,   330,   279,   275,   276,
     277,    27,   130,   171,   261,     9,   350,     9,   279,   353,
     275,   264,   330,   277,   353,   125,   198,   199,   200,   201,
     202,   349,   353,   353,   266,     6,     7,   356,     9,   353,
     265,   224,   229,   228,   228,   228,   226,   228,   228,   240,
     330,   305,   305,   227,   205,   312,   239,   235,   146,   309,
     315,   328,   334,   230,   280,   213,   225,   277,   252,   253,
     254,   255,    28,    68,   166,   201,   364,   365,   363,   226,
     292,   227,   203,   231,   291,   313,   314,     6,   243,   227,
     257,   282,   257,   286,   227,   258,   283,   286,   230,   203,
     230,   230,   230,   229,   277,   277,   277,   277,   277,   277,
     277,   331,   333,   352,    15,    16,    17,    18,    19,    20,
      21,    22,    23,   204,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   223,   224,   203,   230,   230,   223,
     230,   203,   230,   230,   203,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   330,   213,   229,   256,
     267,   292,   340,   342,   343,   230,   203,   230,   230,   230,
     230,   230,   203,   230,   230,   230,   203,   230,   230,   230,
     230,   230,   230,   223,   230,   230,   230,   265,     9,   238,
     334,   344,   227,   257,   306,   227,   240,     3,   291,   296,
     297,   159,   319,   227,   241,   258,   227,   205,   123,   286,
     310,   228,   225,   225,   230,   203,   203,   230,   183,   358,
     359,   273,   279,   203,   317,     6,   230,   330,   355,   330,
     351,   230,   228,   228,   262,   331,   230,   213,   229,   256,
     267,   336,   338,   339,   352,   332,   277,   277,     3,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,     3,   277,   279,     6,
     280,     9,   342,   329,   213,   252,   267,   341,   342,   229,
     256,   276,   279,   263,     6,   230,   237,   203,   240,    66,
     113,   322,   323,   240,   291,   297,   318,   226,   240,   205,
     228,   227,   258,   287,   288,   227,    24,   255,   365,   361,
     227,   358,   313,   210,   340,   346,   347,   228,   334,   289,
     292,   338,   329,   213,   252,   267,   337,   338,   230,   229,
     256,   332,   205,   225,   230,   342,   329,   230,   342,   230,
     252,   230,   240,   227,   334,   291,   291,   296,   228,   228,
     203,   239,   228,     5,   205,   345,   203,   228,   226,   230,
     338,   329,   230,   342,   230,   277,   252,   277,   342,   230,
     291,   297,   227,   228,   280,   346,   268,   342,   230,   240,
      43,    59,   227,   269,   279,   205,   205,   228,   285,   286,
     285,   228
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   232,   233,   234,   234,   235,   236,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     237,   237,   237,   238,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   239,   239,   240,   240,
     241,   241,   241,   241,   241,   241,   241,   242,   243,   243,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   245,
     246,   247,   248,   249,   250,   251,   252,   252,   253,   253,
     254,   254,   255,   255,   256,   256,   256,   257,   257,   258,
     259,   259,   259,   260,   260,   261,   261,   261,   262,   262,
     263,   264,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   266,   266,   267,   267,   267,   267,   268,   268,
     269,   269,   270,   270,   270,   271,   271,   272,   273,   273,
     274,   275,   275,   276,   276,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   278,   278,   279,   280,
     281,   281,   282,   282,   283,   283,   284,   284,   285,   285,
     286,   286,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   292,   293,   293,   293,   293,   293,   293,   293,   293,
     293,   293,   293,   294,   294,   295,   295,   295,   295,   295,
     295,   295,   295,   295,   296,   296,   297,   297,   298,   299,
     300,   301,   302,   303,   304,   305,   305,   306,   306,   307,
     308,   309,   309,   310,   310,   311,   311,   312,   312,   313,
     314,   314,   315,   316,   317,   315,   318,   318,   319,   319,
     321,   320,   320,   322,   322,   323,   324,   325,   326,   326,
     326,   327,   328,   329,   329,   330,   330,   331,   331,   332,
     332,   333,   333,   333,   334,   334,   334,   335,   335,   335,
     335,   336,   336,   336,   337,   337,   338,   338,   339,   339,
     339,   339,   339,   340,   340,   340,   341,   341,   342,   342,
     343,   343,   343,   343,   343,   343,   344,   344,   345,   345,
     346,   347,   347,   348,   348,   349,   349,   349,   349,   349,
     349,   350,   350,   350,   351,   352,   352,   352,   352,   352,
     352,   352,   352,   352,   352,   353,   353,   354,   355,   355,
     356,   356,   356,   357,   357,   358,   358,   359,   360,   361,
     361,   362,   362,   363,   363,   363,   363,   364,   364,   365,
     365,   365,   365
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
       3,     3,     0,     4,     1,     4,     1,     1,     1,     1,
       1,     4,     4,     1,     1,     1,     1,     1,     4,     4,
       1,     6,     1,     1,     1,     1,     4,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     1,
       4,     1,     1,     4,     1,     4,     1,     1,     4,     4,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     1,     4,
       4,     1,     1,     1,     1,     1,     6,     1,     4,     1,
       1,     1,     4,     1,     4,     1,     1,     4,     4,     4,
       4,     1,     1,     4,     4,     4,     1,     1,     4,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     0,     2,
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
       1,     1,     1,     1,     2,     3,     1,     2,     2,     6,
       2,     6,     2,     5,     2,     0,     2,     3,     3,     2,
       1,     2,     3,     2,     3,     6,     6,     0,     2,     1,
       1,     3,     2,     0,     0,     7,     1,     3,     0,     2,
       0,     9,     2,     2,     3,     2,     2,     6,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     2,     3,     0,
       1,     2,     2,     2,     3,     2,     1,     1,     3,     2,
       4,     3,     2,     1,     3,     2,     0,     1,     3,     2,
       1,     3,     4,     3,     2,     1,     3,     2,     0,     1,
       1,     3,     2,     1,     3,     4,     1,     3,     0,     2,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     1,     1,     1,     2,     1,
       2,     1,     2,     4,     1,     1,     2,     5,     5,    10,
       1,     3,     1,     0,     2,     0,     2,     4,     6,     0,
       3,     1,     3,     4,     1,     1,     1,     1,     3,     1,
       1,     1,     1
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
#line 343 "tools/widl/parser.y"
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
#line 3327 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 359 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3333 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 360 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3339 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 361 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3345 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interface ';'  */
#line 362 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3351 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements dispinterface ';'  */
#line 363 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3357 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements interfacedef  */
#line 364 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3363 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclass ';'  */
#line 365 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3371 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements coclassdef  */
#line 368 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3379 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements apicontract ';'  */
#line 371 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3385 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements apicontract_def  */
#line 372 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3392 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 374 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3398 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 375 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3405 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements moduledef  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3411 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements librarydef  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3417 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements statement  */
#line 379 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3423 "tools/widl/parser.tab.c"
    break;

  case 20: /* imp_statements: %empty  */
#line 382 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3429 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements interface ';'  */
#line 383 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3435 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements dispinterface ';'  */
#line 384 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_reference((yyvsp[-1].type))); }
#line 3441 "tools/widl/parser.tab.c"
    break;

  case 23: /* $@2: %empty  */
#line 385 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3447 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 386 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3453 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements interfacedef  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3459 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: imp_statements coclass ';'  */
#line 388 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3465 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements coclassdef  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3473 "tools/widl/parser.tab.c"
    break;

  case 28: /* imp_statements: imp_statements apicontract ';'  */
#line 392 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3479 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements apicontract_def  */
#line 393 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3486 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements runtimeclass ';'  */
#line 395 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3492 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements runtimeclass_def  */
#line 396 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3499 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements moduledef  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3505 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements statement  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3511 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements importlib  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3517 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements librarydef  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3523 "tools/widl/parser.tab.c"
    break;

  case 36: /* int_statements: %empty  */
#line 404 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3529 "tools/widl/parser.tab.c"
    break;

  case 37: /* int_statements: int_statements statement  */
#line 405 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3535 "tools/widl/parser.tab.c"
    break;

  case 40: /* statement: cppquote  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3541 "tools/widl/parser.tab.c"
    break;

  case 41: /* statement: typedecl ';'  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3547 "tools/widl/parser.tab.c"
    break;

  case 42: /* statement: declaration ';'  */
#line 415 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3553 "tools/widl/parser.tab.c"
    break;

  case 43: /* statement: import  */
#line 416 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3559 "tools/widl/parser.tab.c"
    break;

  case 44: /* statement: typedef ';'  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3565 "tools/widl/parser.tab.c"
    break;

  case 45: /* statement: aPRAGMA  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3571 "tools/widl/parser.tab.c"
    break;

  case 46: /* statement: pragma_warning  */
#line 419 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3577 "tools/widl/parser.tab.c"
    break;

  case 47: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 423 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3589 "tools/widl/parser.tab.c"
    break;

  case 48: /* warnings: aNUM  */
#line 433 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3595 "tools/widl/parser.tab.c"
    break;

  case 49: /* warnings: warnings aNUM  */
#line 434 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3601 "tools/widl/parser.tab.c"
    break;

  case 51: /* typedecl: tENUM aIDENTIFIER  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3607 "tools/widl/parser.tab.c"
    break;

  case 53: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 441 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3613 "tools/widl/parser.tab.c"
    break;

  case 55: /* typedecl: tUNION aIDENTIFIER  */
#line 443 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3619 "tools/widl/parser.tab.c"
    break;

  case 56: /* typedecl: attributes enumdef  */
#line 444 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3625 "tools/widl/parser.tab.c"
    break;

  case 57: /* typedecl: attributes structdef  */
#line 445 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3631 "tools/widl/parser.tab.c"
    break;

  case 58: /* typedecl: attributes uniondef  */
#line 446 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3637 "tools/widl/parser.tab.c"
    break;

  case 59: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 449 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3643 "tools/widl/parser.tab.c"
    break;

  case 60: /* import_start: tIMPORT aSTRING ';'  */
#line 451 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3654 "tools/widl/parser.tab.c"
    break;

  case 61: /* import: import_start imp_statements aEOF  */
#line 459 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3663 "tools/widl/parser.tab.c"
    break;

  case 62: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 466 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3669 "tools/widl/parser.tab.c"
    break;

  case 63: /* libraryhdr: tLIBRARY typename  */
#line 469 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3675 "tools/widl/parser.tab.c"
    break;

  case 64: /* library_start: attributes libraryhdr '{'  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3683 "tools/widl/parser.tab.c"
    break;

  case 65: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3689 "tools/widl/parser.tab.c"
    break;

  case 66: /* m_args: %empty  */
#line 479 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3695 "tools/widl/parser.tab.c"
    break;

  case 68: /* arg_list: arg  */
#line 483 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3701 "tools/widl/parser.tab.c"
    break;

  case 69: /* arg_list: arg_list ',' arg  */
#line 484 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3707 "tools/widl/parser.tab.c"
    break;

  case 71: /* args: arg_list ',' ELLIPSIS  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3713 "tools/widl/parser.tab.c"
    break;

  case 72: /* arg: attributes decl_spec m_any_declarator  */
#line 492 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3723 "tools/widl/parser.tab.c"
    break;

  case 73: /* arg: decl_spec m_any_declarator  */
#line 497 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3733 "tools/widl/parser.tab.c"
    break;

  case 74: /* array: '[' expr ']'  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3742 "tools/widl/parser.tab.c"
    break;

  case 75: /* array: '[' '*' ']'  */
#line 508 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3748 "tools/widl/parser.tab.c"
    break;

  case 76: /* array: '[' ']'  */
#line 509 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3754 "tools/widl/parser.tab.c"
    break;

  case 77: /* m_attributes: %empty  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3760 "tools/widl/parser.tab.c"
    break;

  case 79: /* attributes: '[' attrib_list ']'  */
#line 517 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3766 "tools/widl/parser.tab.c"
    break;

  case 80: /* attrib_list: attribute  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3772 "tools/widl/parser.tab.c"
    break;

  case 81: /* attrib_list: attrib_list ',' attribute  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3778 "tools/widl/parser.tab.c"
    break;

  case 82: /* attrib_list: attrib_list ']' '[' attribute  */
#line 522 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3784 "tools/widl/parser.tab.c"
    break;

  case 83: /* str_list: aSTRING  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3790 "tools/widl/parser.tab.c"
    break;

  case 84: /* str_list: str_list ',' aSTRING  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3796 "tools/widl/parser.tab.c"
    break;

  case 85: /* marshaling_behavior: tAGILE  */
#line 530 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3802 "tools/widl/parser.tab.c"
    break;

  case 86: /* marshaling_behavior: tNONE  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3808 "tools/widl/parser.tab.c"
    break;

  case 87: /* marshaling_behavior: tSTANDARD  */
#line 532 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3814 "tools/widl/parser.tab.c"
    break;

  case 88: /* contract_ver: aNUM  */
#line 536 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3820 "tools/widl/parser.tab.c"
    break;

  case 89: /* contract_ver: aNUM '.' aNUM  */
#line 537 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3826 "tools/widl/parser.tab.c"
    break;

  case 90: /* contract_req: decl_spec ',' contract_ver  */
#line 540 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3836 "tools/widl/parser.tab.c"
    break;

  case 91: /* static_attr: decl_spec ',' contract_req  */
#line 546 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 3845 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: %empty  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3851 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tACTIVATABLE '(' contract_req ')'  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 3857 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tAGGREGATABLE  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3863 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3869 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tAPPOBJECT  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3875 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tASYNC  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3881 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tAUTOHANDLE  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3887 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tBINDABLE  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3893 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tBROADCAST  */
#line 559 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3899 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tCALLAS '(' ident ')'  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tCODE  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3917 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tCOMMSTATUS  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3923 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tCONTEXTHANDLE  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3929 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3935 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3941 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tCONTROL  */
#line 569 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 570 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3965 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tDECODE  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3971 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tDEFAULT  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3977 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tDEFAULTBIND  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3983 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tDEFAULTCOLLELEM  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3989 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 575 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3995 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tDEFAULTVTABLE  */
#line 576 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 4001 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 4007 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tDISPLAYBIND  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 4013 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 4019 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tDUAL  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 4025 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tENABLEALLOCATE  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 4031 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tENCODE  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 4037 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tENDPOINT '(' str_list ')'  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 4043 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tENTRY '(' expr_const ')'  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 4049 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tEVENTADD  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 4055 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tEVENTREMOVE  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 4061 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 587 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 4069 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tEXPLICITHANDLE  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 4075 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tFAULTSTATUS  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 4081 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tFLAGS  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 4087 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tFORCEALLOCATE  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 4093 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tHANDLE  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 4099 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 4105 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 4111 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 4117 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 598 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 4123 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 4129 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tHIDDEN  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 4135 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tID '(' expr_int_const ')'  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 4141 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tIDEMPOTENT  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 4147 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tIGNORE  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 4153 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tIIDIS '(' expr ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 4159 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tIMMEDIATEBIND  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 4165 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 4171 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tIN  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 4177 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tINPUTSYNC  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 4183 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 4189 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tLCID '(' expr_int_const ')'  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 4195 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tLCID  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 4201 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tLICENSED  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 4207 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tLOCAL  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 4213 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4219 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tMAYBE  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4225 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tMESSAGE  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4231 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tNOCODE  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4237 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tNONBROWSABLE  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4243 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tNONCREATABLE  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4249 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tNONEXTENSIBLE  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4255 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tNOTIFY  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4261 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tNOTIFYFLAG  */
#line 623 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4267 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tOBJECT  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4273 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tODL  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4279 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tOLEAUTOMATION  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4285 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4291 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tOPTIONAL  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4297 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tOUT  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4303 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tPARTIALIGNORE  */
#line 630 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4309 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4315 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tPROGID '(' aSTRING ')'  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4321 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tPROPGET  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4327 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tPROPPUT  */
#line 634 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4333 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tPROPPUTREF  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4339 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tPROXY  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4345 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tPUBLIC  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4351 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 639 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4359 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tREADONLY  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4365 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tREPRESENTAS '(' type ')'  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4371 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tREQUESTEDIT  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4377 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tRESTRICTED  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4383 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tRETVAL  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4389 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4395 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tSOURCE  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4401 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tSTATIC '(' static_attr ')'  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4407 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4413 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tSTRING  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4419 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tSWITCHIS '(' expr ')'  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4425 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4431 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tTRANSMITAS '(' type ')'  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4437 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tTHREADING '(' threading_type ')'  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4443 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tUIDEFAULT  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4449 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tUSESGETLASTERROR  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4455 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4461 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tUUID '(' uuid_string ')'  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4467 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4473 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tV1ENUM  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4479 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tVARARG  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4485 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tVERSION '(' version ')'  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4491 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4497 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4503 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: pointer_type  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4509 "tools/widl/parser.tab.c"
    break;

  case 203: /* uuid_string: aSTRING  */
#line 671 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4517 "tools/widl/parser.tab.c"
    break;

  case 204: /* callconv: tCDECL  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4523 "tools/widl/parser.tab.c"
    break;

  case 205: /* callconv: tFASTCALL  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4529 "tools/widl/parser.tab.c"
    break;

  case 206: /* callconv: tPASCAL  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4535 "tools/widl/parser.tab.c"
    break;

  case 207: /* callconv: tSTDCALL  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4541 "tools/widl/parser.tab.c"
    break;

  case 208: /* cases: %empty  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4547 "tools/widl/parser.tab.c"
    break;

  case 209: /* cases: cases case  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4553 "tools/widl/parser.tab.c"
    break;

  case 210: /* case: tCASE expr_int_const ':' union_field  */
#line 686 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4562 "tools/widl/parser.tab.c"
    break;

  case 211: /* case: tDEFAULT ':' union_field  */
#line 690 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4571 "tools/widl/parser.tab.c"
    break;

  case 212: /* enums: %empty  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4577 "tools/widl/parser.tab.c"
    break;

  case 213: /* enums: enum_list ','  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4583 "tools/widl/parser.tab.c"
    break;

  case 215: /* enum_list: enum  */
#line 701 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4592 "tools/widl/parser.tab.c"
    break;

  case 216: /* enum_list: enum_list ',' enum  */
#line 705 "tools/widl/parser.y"
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
#line 4607 "tools/widl/parser.tab.c"
    break;

  case 217: /* enum_member: m_attributes ident  */
#line 717 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4615 "tools/widl/parser.tab.c"
    break;

  case 218: /* enum: enum_member '=' expr_int_const  */
#line 722 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 219: /* enum: enum_member  */
#line 726 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4632 "tools/widl/parser.tab.c"
    break;

  case 220: /* enumdef: tENUM m_typename '{' enums '}'  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4638 "tools/widl/parser.tab.c"
    break;

  case 221: /* m_exprs: m_expr  */
#line 734 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4644 "tools/widl/parser.tab.c"
    break;

  case 222: /* m_exprs: m_exprs ',' m_expr  */
#line 735 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4650 "tools/widl/parser.tab.c"
    break;

  case 223: /* m_expr: %empty  */
#line 738 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4656 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: aNUM  */
#line 742 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4662 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: aHEXNUM  */
#line 743 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4668 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: aDOUBLE  */
#line 744 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4674 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: tFALSE  */
#line 745 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4680 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: tNULL  */
#line 746 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4686 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: tTRUE  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4692 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: aSTRING  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4698 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: aWSTRING  */
#line 749 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4704 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: aSQSTRING  */
#line 750 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4710 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: aIDENTIFIER  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4716 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '?' expr ':' expr  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4722 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: expr LOGICALOR expr  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4728 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: expr LOGICALAND expr  */
#line 754 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4734 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: expr '|' expr  */
#line 755 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4740 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: expr '^' expr  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4746 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: expr '&' expr  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4752 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: expr EQUALITY expr  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4758 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr INEQUALITY expr  */
#line 759 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4764 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr '>' expr  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4770 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr '<' expr  */
#line 761 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4776 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: expr GREATEREQUAL expr  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4782 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr LESSEQUAL expr  */
#line 763 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4788 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr SHL expr  */
#line 764 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4794 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr SHR expr  */
#line 765 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4800 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr '+' expr  */
#line 766 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4806 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr '-' expr  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4812 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr '%' expr  */
#line 768 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4818 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr '*' expr  */
#line 769 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4824 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr '/' expr  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4830 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: '!' expr  */
#line 771 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4836 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: '~' expr  */
#line 772 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4842 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: '+' expr  */
#line 773 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4848 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: '-' expr  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4854 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: '&' expr  */
#line 775 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4860 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: '*' expr  */
#line 776 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4866 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 777 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4872 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: expr '.' aIDENTIFIER  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4878 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: '(' unqualified_decl_spec m_abstract_declarator ')' expr  */
#line 780 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4884 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: tSIZEOF '(' unqualified_decl_spec m_abstract_declarator ')'  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4890 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: expr '[' expr ']'  */
#line 783 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4896 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: '(' expr ')'  */
#line 784 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4902 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr_list_int_const: expr_int_const  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4908 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 788 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4914 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr_int_const: expr  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4923 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr_const: expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4932 "tools/widl/parser.tab.c"
    break;

  case 270: /* fields: %empty  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 271: /* fields: fields field  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4944 "tools/widl/parser.tab.c"
    break;

  case 272: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 808 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4953 "tools/widl/parser.tab.c"
    break;

  case 273: /* field: m_attributes uniondef ';'  */
#line 812 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4962 "tools/widl/parser.tab.c"
    break;

  case 274: /* ne_union_field: s_field ';'  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4968 "tools/widl/parser.tab.c"
    break;

  case 275: /* ne_union_field: attributes ';'  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4974 "tools/widl/parser.tab.c"
    break;

  case 276: /* ne_union_fields: %empty  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4980 "tools/widl/parser.tab.c"
    break;

  case 277: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4986 "tools/widl/parser.tab.c"
    break;

  case 278: /* union_field: s_field ';'  */
#line 828 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4992 "tools/widl/parser.tab.c"
    break;

  case 279: /* union_field: ';'  */
#line 829 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4998 "tools/widl/parser.tab.c"
    break;

  case 280: /* s_field: m_attributes decl_spec declarator  */
#line 832 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5007 "tools/widl/parser.tab.c"
    break;

  case 281: /* s_field: m_attributes structdef  */
#line 836 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 5016 "tools/widl/parser.tab.c"
    break;

  case 282: /* funcdef: declaration  */
#line 842 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 5026 "tools/widl/parser.tab.c"
    break;

  case 283: /* declaration: attributes decl_spec init_declarator  */
#line 851 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5034 "tools/widl/parser.tab.c"
    break;

  case 284: /* declaration: decl_spec init_declarator  */
#line 854 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 5042 "tools/widl/parser.tab.c"
    break;

  case 285: /* m_ident: %empty  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 5048 "tools/widl/parser.tab.c"
    break;

  case 287: /* m_typename: %empty  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 5054 "tools/widl/parser.tab.c"
    break;

  case 291: /* ident: typename  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 5060 "tools/widl/parser.tab.c"
    break;

  case 292: /* base_type: tBYTE  */
#line 874 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5066 "tools/widl/parser.tab.c"
    break;

  case 293: /* base_type: tWCHAR  */
#line 875 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5072 "tools/widl/parser.tab.c"
    break;

  case 295: /* base_type: tSIGNED int_std  */
#line 877 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 5078 "tools/widl/parser.tab.c"
    break;

  case 296: /* base_type: tUNSIGNED int_std  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 5084 "tools/widl/parser.tab.c"
    break;

  case 297: /* base_type: tUNSIGNED  */
#line 879 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 5090 "tools/widl/parser.tab.c"
    break;

  case 298: /* base_type: tFLOAT  */
#line 880 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5096 "tools/widl/parser.tab.c"
    break;

  case 299: /* base_type: tDOUBLE  */
#line 881 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5102 "tools/widl/parser.tab.c"
    break;

  case 300: /* base_type: tBOOLEAN  */
#line 882 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5108 "tools/widl/parser.tab.c"
    break;

  case 301: /* base_type: tERRORSTATUST  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5114 "tools/widl/parser.tab.c"
    break;

  case 302: /* base_type: tHANDLET  */
#line 884 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(NULL, (yyvsp[0].str)); }
#line 5120 "tools/widl/parser.tab.c"
    break;

  case 305: /* int_std: tINT  */
#line 891 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 5126 "tools/widl/parser.tab.c"
    break;

  case 306: /* int_std: tSHORT m_int  */
#line 892 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 5132 "tools/widl/parser.tab.c"
    break;

  case 307: /* int_std: tSMALL  */
#line 893 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 5138 "tools/widl/parser.tab.c"
    break;

  case 308: /* int_std: tLONG m_int  */
#line 894 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 5144 "tools/widl/parser.tab.c"
    break;

  case 309: /* int_std: tHYPER m_int  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 5150 "tools/widl/parser.tab.c"
    break;

  case 310: /* int_std: tINT64  */
#line 896 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 5156 "tools/widl/parser.tab.c"
    break;

  case 311: /* int_std: tCHAR  */
#line 897 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 5162 "tools/widl/parser.tab.c"
    break;

  case 312: /* int_std: tINT32  */
#line 898 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 5168 "tools/widl/parser.tab.c"
    break;

  case 313: /* int_std: tINT3264  */
#line 899 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 5174 "tools/widl/parser.tab.c"
    break;

  case 314: /* namespace_pfx: aIDENTIFIER '.'  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error(&global_namespace, (yyvsp[-1].str)); }
#line 5180 "tools/widl/parser.tab.c"
    break;

  case 315: /* namespace_pfx: namespace_pfx aIDENTIFIER '.'  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.namespace) = find_namespace_or_error((yyvsp[-2].namespace), (yyvsp[-1].str)); }
#line 5186 "tools/widl/parser.tab.c"
    break;

  case 316: /* qualified_type: typename  */
#line 908 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5192 "tools/widl/parser.tab.c"
    break;

  case 317: /* qualified_type: namespace_pfx typename  */
#line 909 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5198 "tools/widl/parser.tab.c"
    break;

  case 318: /* coclass: tCOCLASS typename  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_declare((yyvsp[0].str)); }
#line 5204 "tools/widl/parser.tab.c"
    break;

  case 319: /* coclassdef: attributes coclass '{' class_interfaces '}' semicolon_opt  */
#line 916 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5210 "tools/widl/parser.tab.c"
    break;

  case 320: /* runtimeclass: tRUNTIMECLASS typename  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_declare((yyvsp[0].str), current_namespace); }
#line 5216 "tools/widl/parser.tab.c"
    break;

  case 321: /* runtimeclass_def: attributes runtimeclass '{' class_interfaces '}' semicolon_opt  */
#line 923 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].ifref_list)); }
#line 5222 "tools/widl/parser.tab.c"
    break;

  case 322: /* apicontract: tAPICONTRACT typename  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_declare((yyvsp[0].str), current_namespace); }
#line 5228 "tools/widl/parser.tab.c"
    break;

  case 323: /* apicontract_def: attributes apicontract '{' '}' semicolon_opt  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.type) = type_apicontract_define((yyvsp[-3].type), (yyvsp[-4].attr_list)); }
#line 5234 "tools/widl/parser.tab.c"
    break;

  case 324: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 933 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5240 "tools/widl/parser.tab.c"
    break;

  case 325: /* class_interfaces: %empty  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5246 "tools/widl/parser.tab.c"
    break;

  case 326: /* class_interfaces: class_interfaces class_interface  */
#line 937 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5252 "tools/widl/parser.tab.c"
    break;

  case 327: /* class_interface: m_attributes interfaceref ';'  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[-1].type)); (yyval.ifref)->attrs = (yyvsp[-2].attr_list); }
#line 5258 "tools/widl/parser.tab.c"
    break;

  case 328: /* class_interface: m_attributes dispinterfaceref ';'  */
#line 942 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[-1].type)); (yyval.ifref)->attrs = (yyvsp[-2].attr_list); }
#line 5264 "tools/widl/parser.tab.c"
    break;

  case 329: /* dispinterface: tDISPINTERFACE typename  */
#line 945 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_declare((yyvsp[0].str)); }
#line 5270 "tools/widl/parser.tab.c"
    break;

  case 330: /* dispattributes: attributes  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[0].attr_list), make_attr(ATTR_DISPINTERFACE)); }
#line 5276 "tools/widl/parser.tab.c"
    break;

  case 331: /* dispint_props: tPROPERTIES ':'  */
#line 951 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5282 "tools/widl/parser.tab.c"
    break;

  case 332: /* dispint_props: dispint_props s_field ';'  */
#line 952 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5288 "tools/widl/parser.tab.c"
    break;

  case 333: /* dispint_meths: tMETHODS ':'  */
#line 955 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5294 "tools/widl/parser.tab.c"
    break;

  case 334: /* dispint_meths: dispint_meths funcdef ';'  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5300 "tools/widl/parser.tab.c"
    break;

  case 335: /* dispinterfacedef: dispattributes dispinterface '{' dispint_props dispint_meths '}'  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].var_list), (yyvsp[-1].var_list)); }
#line 5306 "tools/widl/parser.tab.c"
    break;

  case 336: /* dispinterfacedef: dispattributes dispinterface '{' interface ';' '}'  */
#line 963 "tools/widl/parser.y"
                                                { (yyval.type) = type_dispinterface_define_from_iface((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].type)); }
#line 5312 "tools/widl/parser.tab.c"
    break;

  case 337: /* inherit: %empty  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5318 "tools/widl/parser.tab.c"
    break;

  case 338: /* inherit: ':' qualified_type  */
#line 967 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5324 "tools/widl/parser.tab.c"
    break;

  case 339: /* type_parameter: typename  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5330 "tools/widl/parser.tab.c"
    break;

  case 340: /* type_parameters: type_parameter  */
#line 974 "tools/widl/parser.y"
                                                { (yyval.type_list) = append_type(NULL, (yyvsp[0].type)); }
#line 5336 "tools/widl/parser.tab.c"
    break;

  case 341: /* type_parameters: type_parameters ',' type_parameter  */
#line 975 "tools/widl/parser.y"
                                                { (yyval.type_list) = append_type((yyvsp[-2].type_list), (yyvsp[0].type)); }
#line 5342 "tools/widl/parser.tab.c"
    break;

  case 342: /* interface: tINTERFACE typename  */
#line 979 "tools/widl/parser.y"
                                                { (yyval.type) = type_interface_declare((yyvsp[0].str), current_namespace); }
#line 5348 "tools/widl/parser.tab.c"
    break;

  case 343: /* $@3: %empty  */
#line 980 "tools/widl/parser.y"
                                  { push_parameters_namespace((yyvsp[-1].str)); }
#line 5354 "tools/widl/parser.tab.c"
    break;

  case 344: /* $@4: %empty  */
#line 980 "tools/widl/parser.y"
                                                                                     { pop_parameters_namespace((yyvsp[-3].str)); }
#line 5360 "tools/widl/parser.tab.c"
    break;

  case 345: /* interface: tINTERFACE typename '<' $@3 type_parameters $@4 '>'  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_parameterized_interface_declare((yyvsp[-5].str), current_namespace, (yyvsp[-2].type_list)); }
#line 5366 "tools/widl/parser.tab.c"
    break;

  case 346: /* required_types: qualified_type  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref(NULL, make_ifref((yyvsp[0].type))); }
#line 5372 "tools/widl/parser.tab.c"
    break;

  case 347: /* required_types: required_types ',' qualified_type  */
#line 986 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref((yyvsp[-2].ifref_list), make_ifref((yyvsp[0].type))); }
#line 5378 "tools/widl/parser.tab.c"
    break;

  case 348: /* requires: %empty  */
#line 988 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5384 "tools/widl/parser.tab.c"
    break;

  case 349: /* requires: tREQUIRES required_types  */
#line 989 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = (yyvsp[0].ifref_list); }
#line 5390 "tools/widl/parser.tab.c"
    break;

  case 350: /* $@5: %empty  */
#line 992 "tools/widl/parser.y"
                                                { if ((yyvsp[0].type)->type_type == TYPE_PARAMETERIZED_TYPE) push_parameters_namespace((yyvsp[0].type)->name); }
#line 5396 "tools/widl/parser.tab.c"
    break;

  case 351: /* interfacedef: attributes interface $@5 inherit requires '{' int_statements '}' semicolon_opt  */
#line 994 "tools/widl/parser.y"
                                                { if ((yyvsp[-7].type)->type_type == TYPE_PARAMETERIZED_TYPE)
						  {
						      (yyval.type) = type_parameterized_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].ifref_list));
						      pop_parameters_namespace((yyvsp[-7].type)->name);
						  }
						  else
						  {
						      (yyval.type) = type_interface_define((yyvsp[-7].type), (yyvsp[-8].attr_list), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].ifref_list));
						      check_async_uuid((yyval.type));
						  }
						}
#line 5412 "tools/widl/parser.tab.c"
    break;

  case 352: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1005 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5418 "tools/widl/parser.tab.c"
    break;

  case 353: /* interfaceref: tINTERFACE typename  */
#line 1009 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 354: /* interfaceref: tINTERFACE namespace_pfx typename  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), (yyvsp[-1].namespace), 0); }
#line 5430 "tools/widl/parser.tab.c"
    break;

  case 355: /* dispinterfaceref: tDISPINTERFACE typename  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5436 "tools/widl/parser.tab.c"
    break;

  case 356: /* module: tMODULE typename  */
#line 1017 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_declare((yyvsp[0].str)); }
#line 5442 "tools/widl/parser.tab.c"
    break;

  case 357: /* moduledef: attributes module '{' int_statements '}' semicolon_opt  */
#line 1021 "tools/widl/parser.y"
                                                { (yyval.type) = type_module_define((yyvsp[-4].type), (yyvsp[-5].attr_list), (yyvsp[-2].stmt_list)); }
#line 5448 "tools/widl/parser.tab.c"
    break;

  case 358: /* storage_cls_spec: tEXTERN  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5454 "tools/widl/parser.tab.c"
    break;

  case 359: /* storage_cls_spec: tSTATIC  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5460 "tools/widl/parser.tab.c"
    break;

  case 360: /* storage_cls_spec: tREGISTER  */
#line 1027 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5466 "tools/widl/parser.tab.c"
    break;

  case 361: /* function_specifier: tINLINE  */
#line 1031 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5472 "tools/widl/parser.tab.c"
    break;

  case 362: /* type_qualifier: tCONST  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5478 "tools/widl/parser.tab.c"
    break;

  case 363: /* m_type_qual_list: %empty  */
#line 1038 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5484 "tools/widl/parser.tab.c"
    break;

  case 364: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1039 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5490 "tools/widl/parser.tab.c"
    break;

  case 365: /* decl_spec: type m_decl_spec_no_type  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5496 "tools/widl/parser.tab.c"
    break;

  case 366: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1044 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5502 "tools/widl/parser.tab.c"
    break;

  case 367: /* unqualified_decl_spec: unqualified_type m_decl_spec_no_type  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5508 "tools/widl/parser.tab.c"
    break;

  case 368: /* unqualified_decl_spec: decl_spec_no_type unqualified_type m_decl_spec_no_type  */
#line 1050 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5514 "tools/widl/parser.tab.c"
    break;

  case 369: /* m_decl_spec_no_type: %empty  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5520 "tools/widl/parser.tab.c"
    break;

  case 371: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1058 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5526 "tools/widl/parser.tab.c"
    break;

  case 372: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1059 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5532 "tools/widl/parser.tab.c"
    break;

  case 373: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1060 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5538 "tools/widl/parser.tab.c"
    break;

  case 374: /* declarator: '*' m_type_qual_list declarator  */
#line 1065 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5544 "tools/widl/parser.tab.c"
    break;

  case 375: /* declarator: callconv declarator  */
#line 1066 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5550 "tools/widl/parser.tab.c"
    break;

  case 377: /* direct_declarator: ident  */
#line 1071 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5556 "tools/widl/parser.tab.c"
    break;

  case 378: /* direct_declarator: '(' declarator ')'  */
#line 1072 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5562 "tools/widl/parser.tab.c"
    break;

  case 379: /* direct_declarator: direct_declarator array  */
#line 1073 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5568 "tools/widl/parser.tab.c"
    break;

  case 380: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1074 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5574 "tools/widl/parser.tab.c"
    break;

  case 381: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1080 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5580 "tools/widl/parser.tab.c"
    break;

  case 382: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5586 "tools/widl/parser.tab.c"
    break;

  case 384: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1088 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5592 "tools/widl/parser.tab.c"
    break;

  case 385: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1089 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5598 "tools/widl/parser.tab.c"
    break;

  case 386: /* m_abstract_declarator: %empty  */
#line 1093 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5604 "tools/widl/parser.tab.c"
    break;

  case 388: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1099 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5610 "tools/widl/parser.tab.c"
    break;

  case 389: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1100 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5616 "tools/widl/parser.tab.c"
    break;

  case 390: /* abstract_direct_declarator: array  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5622 "tools/widl/parser.tab.c"
    break;

  case 391: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5630 "tools/widl/parser.tab.c"
    break;

  case 392: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1107 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5638 "tools/widl/parser.tab.c"
    break;

  case 393: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5644 "tools/widl/parser.tab.c"
    break;

  case 394: /* any_declarator: callconv m_any_declarator  */
#line 1116 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5650 "tools/widl/parser.tab.c"
    break;

  case 396: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5656 "tools/widl/parser.tab.c"
    break;

  case 397: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1124 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5662 "tools/widl/parser.tab.c"
    break;

  case 398: /* m_any_declarator: %empty  */
#line 1128 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5668 "tools/widl/parser.tab.c"
    break;

  case 400: /* any_direct_declarator: ident  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5674 "tools/widl/parser.tab.c"
    break;

  case 401: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1137 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5680 "tools/widl/parser.tab.c"
    break;

  case 402: /* any_direct_declarator: any_direct_declarator array  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5686 "tools/widl/parser.tab.c"
    break;

  case 403: /* any_direct_declarator: array  */
#line 1139 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5692 "tools/widl/parser.tab.c"
    break;

  case 404: /* any_direct_declarator: '(' m_args ')'  */
#line 1141 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5700 "tools/widl/parser.tab.c"
    break;

  case 405: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5708 "tools/widl/parser.tab.c"
    break;

  case 406: /* declarator_list: declarator  */
#line 1151 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5714 "tools/widl/parser.tab.c"
    break;

  case 407: /* declarator_list: declarator_list ',' declarator  */
#line 1152 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5720 "tools/widl/parser.tab.c"
    break;

  case 408: /* m_bitfield: %empty  */
#line 1155 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5726 "tools/widl/parser.tab.c"
    break;

  case 409: /* m_bitfield: ':' expr_const  */
#line 1156 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5732 "tools/widl/parser.tab.c"
    break;

  case 410: /* struct_declarator: any_declarator m_bitfield  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5741 "tools/widl/parser.tab.c"
    break;

  case 411: /* struct_declarator_list: struct_declarator  */
#line 1166 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5747 "tools/widl/parser.tab.c"
    break;

  case 412: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1168 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5753 "tools/widl/parser.tab.c"
    break;

  case 413: /* init_declarator: declarator  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5759 "tools/widl/parser.tab.c"
    break;

  case 414: /* init_declarator: declarator '=' expr_const  */
#line 1173 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5765 "tools/widl/parser.tab.c"
    break;

  case 415: /* threading_type: tAPARTMENT  */
#line 1177 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5771 "tools/widl/parser.tab.c"
    break;

  case 416: /* threading_type: tNEUTRAL  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5777 "tools/widl/parser.tab.c"
    break;

  case 417: /* threading_type: tSINGLE  */
#line 1179 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5783 "tools/widl/parser.tab.c"
    break;

  case 418: /* threading_type: tFREE  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5789 "tools/widl/parser.tab.c"
    break;

  case 419: /* threading_type: tBOTH  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5795 "tools/widl/parser.tab.c"
    break;

  case 420: /* threading_type: tMTA  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5801 "tools/widl/parser.tab.c"
    break;

  case 421: /* pointer_type: tREF  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5807 "tools/widl/parser.tab.c"
    break;

  case 422: /* pointer_type: tUNIQUE  */
#line 1187 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5813 "tools/widl/parser.tab.c"
    break;

  case 423: /* pointer_type: tPTR  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5819 "tools/widl/parser.tab.c"
    break;

  case 424: /* structdef: tSTRUCT m_typename '{' fields '}'  */
#line 1191 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5825 "tools/widl/parser.tab.c"
    break;

  case 425: /* unqualified_type: tVOID  */
#line 1195 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5831 "tools/widl/parser.tab.c"
    break;

  case 426: /* unqualified_type: base_type  */
#line 1196 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5837 "tools/widl/parser.tab.c"
    break;

  case 427: /* unqualified_type: enumdef  */
#line 1197 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5843 "tools/widl/parser.tab.c"
    break;

  case 428: /* unqualified_type: tENUM aIDENTIFIER  */
#line 1198 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5849 "tools/widl/parser.tab.c"
    break;

  case 429: /* unqualified_type: structdef  */
#line 1199 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5855 "tools/widl/parser.tab.c"
    break;

  case 430: /* unqualified_type: tSTRUCT aIDENTIFIER  */
#line 1200 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5861 "tools/widl/parser.tab.c"
    break;

  case 431: /* unqualified_type: uniondef  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5867 "tools/widl/parser.tab.c"
    break;

  case 432: /* unqualified_type: tUNION aIDENTIFIER  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5873 "tools/widl/parser.tab.c"
    break;

  case 433: /* unqualified_type: tSAFEARRAY '(' type ')'  */
#line 1203 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5879 "tools/widl/parser.tab.c"
    break;

  case 434: /* unqualified_type: aKNOWNTYPE  */
#line 1204 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error(current_namespace, (yyvsp[0].str)); }
#line 5885 "tools/widl/parser.tab.c"
    break;

  case 436: /* type: namespace_pfx typename  */
#line 1209 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[-1].namespace), (yyvsp[0].str)); }
#line 5891 "tools/widl/parser.tab.c"
    break;

  case 437: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1213 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5900 "tools/widl/parser.tab.c"
    break;

  case 438: /* uniondef: tUNION m_typename '{' ne_union_fields '}'  */
#line 1220 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5906 "tools/widl/parser.tab.c"
    break;

  case 439: /* uniondef: tUNION m_typename tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1223 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5912 "tools/widl/parser.tab.c"
    break;

  case 440: /* version: aNUM  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5918 "tools/widl/parser.tab.c"
    break;

  case 441: /* version: aNUM '.' aNUM  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5924 "tools/widl/parser.tab.c"
    break;

  case 442: /* version: aHEXNUM  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5930 "tools/widl/parser.tab.c"
    break;

  case 447: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1244 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error(current_namespace, (yyvsp[-1].str));
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5938 "tools/widl/parser.tab.c"
    break;

  case 448: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1251 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error(current_namespace, (yyvsp[-3].str));
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5948 "tools/widl/parser.tab.c"
    break;

  case 449: /* acf_attributes: %empty  */
#line 1259 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5954 "tools/widl/parser.tab.c"
    break;

  case 450: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1260 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5960 "tools/widl/parser.tab.c"
    break;

  case 451: /* acf_attribute_list: acf_attribute  */
#line 1264 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5966 "tools/widl/parser.tab.c"
    break;

  case 452: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5972 "tools/widl/parser.tab.c"
    break;

  case 453: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1270 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5978 "tools/widl/parser.tab.c"
    break;

  case 454: /* acf_attribute: tENCODE  */
#line 1271 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5984 "tools/widl/parser.tab.c"
    break;

  case 455: /* acf_attribute: tDECODE  */
#line 1272 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5990 "tools/widl/parser.tab.c"
    break;

  case 456: /* acf_attribute: tEXPLICITHANDLE  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5996 "tools/widl/parser.tab.c"
    break;

  case 457: /* allocate_option_list: allocate_option  */
#line 1277 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 6002 "tools/widl/parser.tab.c"
    break;

  case 458: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 6008 "tools/widl/parser.tab.c"
    break;

  case 459: /* allocate_option: tDONTFREE  */
#line 1283 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 6014 "tools/widl/parser.tab.c"
    break;

  case 460: /* allocate_option: tFREE  */
#line 1284 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6020 "tools/widl/parser.tab.c"
    break;

  case 461: /* allocate_option: tALLNODES  */
#line 1285 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6026 "tools/widl/parser.tab.c"
    break;

  case 462: /* allocate_option: tSINGLENODE  */
#line 1286 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6032 "tools/widl/parser.tab.c"
    break;


#line 6036 "tools/widl/parser.tab.c"

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

#line 1289 "tools/widl/parser.y"


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

static type_list_t *append_type(type_list_t *list, type_t *type)
{
    type_list_t *entry;
    if (!type) return list;
    entry = xmalloc( sizeof(*entry) );
    entry->type = type;
    entry->next = list;
    return entry;
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
