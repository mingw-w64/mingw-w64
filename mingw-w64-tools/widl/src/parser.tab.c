/* A Bison parser, made by GNU Bison 3.7.2.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.2"

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
#line 1 "parser.y"

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
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs);
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


#line 210 "parser.tab.c"

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
    tALLOCATE = 282,               /* tALLOCATE  */
    tANNOTATION = 283,             /* tANNOTATION  */
    tAPPOBJECT = 284,              /* tAPPOBJECT  */
    tASYNC = 285,                  /* tASYNC  */
    tASYNCUUID = 286,              /* tASYNCUUID  */
    tAUTOHANDLE = 287,             /* tAUTOHANDLE  */
    tBINDABLE = 288,               /* tBINDABLE  */
    tBOOLEAN = 289,                /* tBOOLEAN  */
    tBROADCAST = 290,              /* tBROADCAST  */
    tBYTE = 291,                   /* tBYTE  */
    tBYTECOUNT = 292,              /* tBYTECOUNT  */
    tCALLAS = 293,                 /* tCALLAS  */
    tCALLBACK = 294,               /* tCALLBACK  */
    tCASE = 295,                   /* tCASE  */
    tCDECL = 296,                  /* tCDECL  */
    tCHAR = 297,                   /* tCHAR  */
    tCOCLASS = 298,                /* tCOCLASS  */
    tCODE = 299,                   /* tCODE  */
    tCOMMSTATUS = 300,             /* tCOMMSTATUS  */
    tCONST = 301,                  /* tCONST  */
    tCONTEXTHANDLE = 302,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 303, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 304, /* tCONTEXTHANDLESERIALIZE  */
    tCONTROL = 305,                /* tCONTROL  */
    tCPPQUOTE = 306,               /* tCPPQUOTE  */
    tDECODE = 307,                 /* tDECODE  */
    tDEFAULT = 308,                /* tDEFAULT  */
    tDEFAULTBIND = 309,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 310,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 311,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 312,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 313, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 314,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 315,          /* tDISPINTERFACE  */
    tDLLNAME = 316,                /* tDLLNAME  */
    tDOUBLE = 317,                 /* tDOUBLE  */
    tDUAL = 318,                   /* tDUAL  */
    tENABLEALLOCATE = 319,         /* tENABLEALLOCATE  */
    tENCODE = 320,                 /* tENCODE  */
    tENDPOINT = 321,               /* tENDPOINT  */
    tENTRY = 322,                  /* tENTRY  */
    tENUM = 323,                   /* tENUM  */
    tERRORSTATUST = 324,           /* tERRORSTATUST  */
    tEXPLICITHANDLE = 325,         /* tEXPLICITHANDLE  */
    tEXTERN = 326,                 /* tEXTERN  */
    tFALSE = 327,                  /* tFALSE  */
    tFASTCALL = 328,               /* tFASTCALL  */
    tFAULTSTATUS = 329,            /* tFAULTSTATUS  */
    tFLOAT = 330,                  /* tFLOAT  */
    tFORCEALLOCATE = 331,          /* tFORCEALLOCATE  */
    tHANDLE = 332,                 /* tHANDLE  */
    tHANDLET = 333,                /* tHANDLET  */
    tHELPCONTEXT = 334,            /* tHELPCONTEXT  */
    tHELPFILE = 335,               /* tHELPFILE  */
    tHELPSTRING = 336,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 337,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 338,          /* tHELPSTRINGDLL  */
    tHIDDEN = 339,                 /* tHIDDEN  */
    tHYPER = 340,                  /* tHYPER  */
    tID = 341,                     /* tID  */
    tIDEMPOTENT = 342,             /* tIDEMPOTENT  */
    tIGNORE = 343,                 /* tIGNORE  */
    tIIDIS = 344,                  /* tIIDIS  */
    tIMMEDIATEBIND = 345,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 346,         /* tIMPLICITHANDLE  */
    tIMPORT = 347,                 /* tIMPORT  */
    tIMPORTLIB = 348,              /* tIMPORTLIB  */
    tIN = 349,                     /* tIN  */
    tIN_LINE = 350,                /* tIN_LINE  */
    tINLINE = 351,                 /* tINLINE  */
    tINPUTSYNC = 352,              /* tINPUTSYNC  */
    tINT = 353,                    /* tINT  */
    tINT32 = 354,                  /* tINT32  */
    tINT3264 = 355,                /* tINT3264  */
    tINT64 = 356,                  /* tINT64  */
    tINTERFACE = 357,              /* tINTERFACE  */
    tLCID = 358,                   /* tLCID  */
    tLENGTHIS = 359,               /* tLENGTHIS  */
    tLIBRARY = 360,                /* tLIBRARY  */
    tLICENSED = 361,               /* tLICENSED  */
    tLOCAL = 362,                  /* tLOCAL  */
    tLONG = 363,                   /* tLONG  */
    tMAYBE = 364,                  /* tMAYBE  */
    tMESSAGE = 365,                /* tMESSAGE  */
    tMETHODS = 366,                /* tMETHODS  */
    tMODULE = 367,                 /* tMODULE  */
    tNAMESPACE = 368,              /* tNAMESPACE  */
    tNOCODE = 369,                 /* tNOCODE  */
    tNONBROWSABLE = 370,           /* tNONBROWSABLE  */
    tNONCREATABLE = 371,           /* tNONCREATABLE  */
    tNONEXTENSIBLE = 372,          /* tNONEXTENSIBLE  */
    tNOTIFY = 373,                 /* tNOTIFY  */
    tNOTIFYFLAG = 374,             /* tNOTIFYFLAG  */
    tNULL = 375,                   /* tNULL  */
    tOBJECT = 376,                 /* tOBJECT  */
    tODL = 377,                    /* tODL  */
    tOLEAUTOMATION = 378,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 379,               /* tOPTIMIZE  */
    tOPTIONAL = 380,               /* tOPTIONAL  */
    tOUT = 381,                    /* tOUT  */
    tPARTIALIGNORE = 382,          /* tPARTIALIGNORE  */
    tPASCAL = 383,                 /* tPASCAL  */
    tPOINTERDEFAULT = 384,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 385,         /* tPRAGMA_WARNING  */
    tPROGID = 386,                 /* tPROGID  */
    tPROPERTIES = 387,             /* tPROPERTIES  */
    tPROPGET = 388,                /* tPROPGET  */
    tPROPPUT = 389,                /* tPROPPUT  */
    tPROPPUTREF = 390,             /* tPROPPUTREF  */
    tPROXY = 391,                  /* tPROXY  */
    tPTR = 392,                    /* tPTR  */
    tPUBLIC = 393,                 /* tPUBLIC  */
    tRANGE = 394,                  /* tRANGE  */
    tREADONLY = 395,               /* tREADONLY  */
    tREF = 396,                    /* tREF  */
    tREGISTER = 397,               /* tREGISTER  */
    tREPRESENTAS = 398,            /* tREPRESENTAS  */
    tREQUESTEDIT = 399,            /* tREQUESTEDIT  */
    tRESTRICTED = 400,             /* tRESTRICTED  */
    tRETVAL = 401,                 /* tRETVAL  */
    tSAFEARRAY = 402,              /* tSAFEARRAY  */
    tSHORT = 403,                  /* tSHORT  */
    tSIGNED = 404,                 /* tSIGNED  */
    tSIZEIS = 405,                 /* tSIZEIS  */
    tSIZEOF = 406,                 /* tSIZEOF  */
    tSMALL = 407,                  /* tSMALL  */
    tSOURCE = 408,                 /* tSOURCE  */
    tSTATIC = 409,                 /* tSTATIC  */
    tSTDCALL = 410,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 411,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 412,                 /* tSTRING  */
    tSTRUCT = 413,                 /* tSTRUCT  */
    tSWITCH = 414,                 /* tSWITCH  */
    tSWITCHIS = 415,               /* tSWITCHIS  */
    tSWITCHTYPE = 416,             /* tSWITCHTYPE  */
    tTHREADING = 417,              /* tTHREADING  */
    tTRANSMITAS = 418,             /* tTRANSMITAS  */
    tTRUE = 419,                   /* tTRUE  */
    tTYPEDEF = 420,                /* tTYPEDEF  */
    tUIDEFAULT = 421,              /* tUIDEFAULT  */
    tUNION = 422,                  /* tUNION  */
    tUNIQUE = 423,                 /* tUNIQUE  */
    tUNSIGNED = 424,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 425,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 426,            /* tUSERMARSHAL  */
    tUUID = 427,                   /* tUUID  */
    tV1ENUM = 428,                 /* tV1ENUM  */
    tVARARG = 429,                 /* tVARARG  */
    tVERSION = 430,                /* tVERSION  */
    tVIPROGID = 431,               /* tVIPROGID  */
    tVOID = 432,                   /* tVOID  */
    tWCHAR = 433,                  /* tWCHAR  */
    tWIREMARSHAL = 434,            /* tWIREMARSHAL  */
    tAPARTMENT = 435,              /* tAPARTMENT  */
    tNEUTRAL = 436,                /* tNEUTRAL  */
    tSINGLE = 437,                 /* tSINGLE  */
    tFREE = 438,                   /* tFREE  */
    tBOTH = 439,                   /* tBOTH  */
    CAST = 440,                    /* CAST  */
    PPTR = 441,                    /* PPTR  */
    POS = 442,                     /* POS  */
    NEG = 443,                     /* NEG  */
    ADDRESSOF = 444                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 132 "parser.y"

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

#line 475 "parser.tab.c"

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
  YYSYMBOL_tALLOCATE = 27,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 28,               /* tANNOTATION  */
  YYSYMBOL_tAPPOBJECT = 29,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 30,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 31,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 32,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 33,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 34,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 35,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 36,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 37,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 38,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 39,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 40,                     /* tCASE  */
  YYSYMBOL_tCDECL = 41,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 42,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 43,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 44,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 45,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 46,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 47,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 48, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 49,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTROL = 50,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 51,                 /* tCPPQUOTE  */
  YYSYMBOL_tDECODE = 52,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 53,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 54,              /* tDEFAULTBIND  */
  YYSYMBOL_tDEFAULTCOLLELEM = 55,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 56,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 57,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 58,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 59,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 60,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 61,                  /* tDLLNAME  */
  YYSYMBOL_tDOUBLE = 62,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 63,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 64,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 65,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 66,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 67,                    /* tENTRY  */
  YYSYMBOL_tENUM = 68,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 69,             /* tERRORSTATUST  */
  YYSYMBOL_tEXPLICITHANDLE = 70,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 71,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 72,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 73,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 74,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLOAT = 75,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 76,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 77,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 78,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 79,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 80,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 81,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 82,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 83,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 84,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 85,                    /* tHYPER  */
  YYSYMBOL_tID = 86,                       /* tID  */
  YYSYMBOL_tIDEMPOTENT = 87,               /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 88,                   /* tIGNORE  */
  YYSYMBOL_tIIDIS = 89,                    /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 90,            /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 91,           /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 92,                   /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 93,                /* tIMPORTLIB  */
  YYSYMBOL_tIN = 94,                       /* tIN  */
  YYSYMBOL_tIN_LINE = 95,                  /* tIN_LINE  */
  YYSYMBOL_tINLINE = 96,                   /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 97,                /* tINPUTSYNC  */
  YYSYMBOL_tINT = 98,                      /* tINT  */
  YYSYMBOL_tINT32 = 99,                    /* tINT32  */
  YYSYMBOL_tINT3264 = 100,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 101,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 102,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 103,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 104,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 105,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 106,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 107,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 108,                    /* tLONG  */
  YYSYMBOL_tMAYBE = 109,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 110,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 111,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 112,                  /* tMODULE  */
  YYSYMBOL_tNAMESPACE = 113,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 114,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 115,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 116,            /* tNONCREATABLE  */
  YYSYMBOL_tNONEXTENSIBLE = 117,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 118,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 119,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 120,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 121,                  /* tOBJECT  */
  YYSYMBOL_tODL = 122,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 123,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 124,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 125,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 126,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 127,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 128,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 129,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 130,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 131,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 132,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 133,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 134,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 135,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 136,                   /* tPROXY  */
  YYSYMBOL_tPTR = 137,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 138,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 139,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 140,                /* tREADONLY  */
  YYSYMBOL_tREF = 141,                     /* tREF  */
  YYSYMBOL_tREGISTER = 142,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 143,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 144,             /* tREQUESTEDIT  */
  YYSYMBOL_tRESTRICTED = 145,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 146,                  /* tRETVAL  */
  YYSYMBOL_tSAFEARRAY = 147,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 148,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 149,                  /* tSIGNED  */
  YYSYMBOL_tSIZEIS = 150,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 151,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 152,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 153,                  /* tSOURCE  */
  YYSYMBOL_tSTATIC = 154,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 155,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 156,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 157,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 158,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 159,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 160,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 161,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 162,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 163,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 164,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 165,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 166,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 167,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 168,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 169,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 170,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 171,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 172,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 173,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 174,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 175,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 176,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 177,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 178,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 179,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 180,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 181,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 182,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 183,                    /* tFREE  */
  YYSYMBOL_tBOTH = 184,                    /* tBOTH  */
  YYSYMBOL_185_ = 185,                     /* ','  */
  YYSYMBOL_186_ = 186,                     /* '?'  */
  YYSYMBOL_187_ = 187,                     /* ':'  */
  YYSYMBOL_188_ = 188,                     /* '|'  */
  YYSYMBOL_189_ = 189,                     /* '^'  */
  YYSYMBOL_190_ = 190,                     /* '&'  */
  YYSYMBOL_191_ = 191,                     /* '<'  */
  YYSYMBOL_192_ = 192,                     /* '>'  */
  YYSYMBOL_193_ = 193,                     /* '-'  */
  YYSYMBOL_194_ = 194,                     /* '+'  */
  YYSYMBOL_195_ = 195,                     /* '*'  */
  YYSYMBOL_196_ = 196,                     /* '/'  */
  YYSYMBOL_197_ = 197,                     /* '%'  */
  YYSYMBOL_198_ = 198,                     /* '!'  */
  YYSYMBOL_199_ = 199,                     /* '~'  */
  YYSYMBOL_CAST = 200,                     /* CAST  */
  YYSYMBOL_PPTR = 201,                     /* PPTR  */
  YYSYMBOL_POS = 202,                      /* POS  */
  YYSYMBOL_NEG = 203,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 204,                /* ADDRESSOF  */
  YYSYMBOL_205_ = 205,                     /* '.'  */
  YYSYMBOL_206_ = 206,                     /* '['  */
  YYSYMBOL_207_ = 207,                     /* ']'  */
  YYSYMBOL_208_ = 208,                     /* '{'  */
  YYSYMBOL_209_ = 209,                     /* '}'  */
  YYSYMBOL_210_ = 210,                     /* ';'  */
  YYSYMBOL_211_ = 211,                     /* '('  */
  YYSYMBOL_212_ = 212,                     /* ')'  */
  YYSYMBOL_213_ = 213,                     /* '='  */
  YYSYMBOL_YYACCEPT = 214,                 /* $accept  */
  YYSYMBOL_input = 215,                    /* input  */
  YYSYMBOL_m_acf = 216,                    /* m_acf  */
  YYSYMBOL_gbl_statements = 217,           /* gbl_statements  */
  YYSYMBOL_218_1 = 218,                    /* $@1  */
  YYSYMBOL_imp_statements = 219,           /* imp_statements  */
  YYSYMBOL_220_2 = 220,                    /* $@2  */
  YYSYMBOL_int_statements = 221,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 222,            /* semicolon_opt  */
  YYSYMBOL_statement = 223,                /* statement  */
  YYSYMBOL_pragma_warning = 224,           /* pragma_warning  */
  YYSYMBOL_warnings = 225,                 /* warnings  */
  YYSYMBOL_typedecl = 226,                 /* typedecl  */
  YYSYMBOL_cppquote = 227,                 /* cppquote  */
  YYSYMBOL_import_start = 228,             /* import_start  */
  YYSYMBOL_import = 229,                   /* import  */
  YYSYMBOL_importlib = 230,                /* importlib  */
  YYSYMBOL_libraryhdr = 231,               /* libraryhdr  */
  YYSYMBOL_library_start = 232,            /* library_start  */
  YYSYMBOL_librarydef = 233,               /* librarydef  */
  YYSYMBOL_m_args = 234,                   /* m_args  */
  YYSYMBOL_arg_list = 235,                 /* arg_list  */
  YYSYMBOL_args = 236,                     /* args  */
  YYSYMBOL_arg = 237,                      /* arg  */
  YYSYMBOL_array = 238,                    /* array  */
  YYSYMBOL_m_attributes = 239,             /* m_attributes  */
  YYSYMBOL_attributes = 240,               /* attributes  */
  YYSYMBOL_attrib_list = 241,              /* attrib_list  */
  YYSYMBOL_str_list = 242,                 /* str_list  */
  YYSYMBOL_attribute = 243,                /* attribute  */
  YYSYMBOL_uuid_string = 244,              /* uuid_string  */
  YYSYMBOL_callconv = 245,                 /* callconv  */
  YYSYMBOL_cases = 246,                    /* cases  */
  YYSYMBOL_case = 247,                     /* case  */
  YYSYMBOL_enums = 248,                    /* enums  */
  YYSYMBOL_enum_list = 249,                /* enum_list  */
  YYSYMBOL_enum = 250,                     /* enum  */
  YYSYMBOL_enumdef = 251,                  /* enumdef  */
  YYSYMBOL_m_exprs = 252,                  /* m_exprs  */
  YYSYMBOL_m_expr = 253,                   /* m_expr  */
  YYSYMBOL_expr = 254,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 255,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 256,           /* expr_int_const  */
  YYSYMBOL_expr_const = 257,               /* expr_const  */
  YYSYMBOL_fields = 258,                   /* fields  */
  YYSYMBOL_field = 259,                    /* field  */
  YYSYMBOL_ne_union_field = 260,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 261,          /* ne_union_fields  */
  YYSYMBOL_union_field = 262,              /* union_field  */
  YYSYMBOL_s_field = 263,                  /* s_field  */
  YYSYMBOL_funcdef = 264,                  /* funcdef  */
  YYSYMBOL_declaration = 265,              /* declaration  */
  YYSYMBOL_m_ident = 266,                  /* m_ident  */
  YYSYMBOL_t_ident = 267,                  /* t_ident  */
  YYSYMBOL_ident = 268,                    /* ident  */
  YYSYMBOL_base_type = 269,                /* base_type  */
  YYSYMBOL_m_int = 270,                    /* m_int  */
  YYSYMBOL_int_std = 271,                  /* int_std  */
  YYSYMBOL_qualified_seq = 272,            /* qualified_seq  */
  YYSYMBOL_273_3 = 273,                    /* $@3  */
  YYSYMBOL_qualified_type = 274,           /* qualified_type  */
  YYSYMBOL_275_4 = 275,                    /* $@4  */
  YYSYMBOL_coclass = 276,                  /* coclass  */
  YYSYMBOL_coclasshdr = 277,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 278,               /* coclassdef  */
  YYSYMBOL_namespacedef = 279,             /* namespacedef  */
  YYSYMBOL_coclass_ints = 280,             /* coclass_ints  */
  YYSYMBOL_coclass_int = 281,              /* coclass_int  */
  YYSYMBOL_dispinterface = 282,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 283,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 284,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 285,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 286,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 287,                  /* inherit  */
  YYSYMBOL_interface = 288,                /* interface  */
  YYSYMBOL_interfacehdr = 289,             /* interfacehdr  */
  YYSYMBOL_interfacedef = 290,             /* interfacedef  */
  YYSYMBOL_interfacedec = 291,             /* interfacedec  */
  YYSYMBOL_module = 292,                   /* module  */
  YYSYMBOL_modulehdr = 293,                /* modulehdr  */
  YYSYMBOL_moduledef = 294,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 295,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 296,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 297,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 298,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 299,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 300,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 301,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 302,               /* declarator  */
  YYSYMBOL_direct_declarator = 303,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 304,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 305, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 306,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 307, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 308,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 309, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 310,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 311,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 312,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 313,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 314,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 315,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 316,          /* init_declarator  */
  YYSYMBOL_threading_type = 317,           /* threading_type  */
  YYSYMBOL_pointer_type = 318,             /* pointer_type  */
  YYSYMBOL_structdef = 319,                /* structdef  */
  YYSYMBOL_type = 320,                     /* type  */
  YYSYMBOL_typedef = 321,                  /* typedef  */
  YYSYMBOL_uniondef = 322,                 /* uniondef  */
  YYSYMBOL_version = 323,                  /* version  */
  YYSYMBOL_acf_statements = 324,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 325,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 326,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 327,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 328,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 329,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 330             /* acf_attribute  */
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
#define YYLAST   3205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  117
/* YYNRULES -- Number of rules.  */
#define YYNRULES  417
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  729

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   444


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
       2,     2,     2,   198,     2,     2,     2,   197,   190,     2,
     211,   212,   195,   194,   185,   193,   205,   196,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   187,   210,
     191,   213,   192,   186,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   206,     2,   207,   189,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   208,   188,   209,   199,     2,     2,     2,
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
     200,   201,   202,   203,   204
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   318,   318,   332,   332,   334,   335,   335,   337,   338,
     339,   342,   345,   346,   347,   350,   351,   352,   352,   354,
     355,   356,   359,   360,   361,   362,   365,   366,   369,   370,
     374,   375,   376,   377,   378,   379,   380,   383,   394,   395,
     399,   400,   401,   402,   403,   404,   405,   406,   407,   410,
     412,   420,   426,   430,   431,   433,   437,   441,   442,   445,
     446,   449,   450,   454,   459,   466,   470,   471,   474,   475,
     479,   482,   483,   484,   487,   488,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,   548,   549,   550,   551,   552,   553,   554,
     555,   556,   557,   558,   559,   560,   561,   562,   563,   564,
     565,   566,   570,   571,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   582,   583,   584,   585,   586,   587,
     588,   589,   590,   591,   592,   593,   597,   598,   603,   604,
     605,   606,   609,   610,   613,   617,   623,   624,   625,   628,
     632,   644,   648,   653,   656,   657,   660,   661,   664,   665,
     666,   667,   668,   669,   670,   671,   672,   673,   674,   675,
     676,   677,   678,   679,   680,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   690,   691,   692,   693,   694,   695,
     696,   697,   698,   699,   700,   701,   703,   705,   706,   709,
     710,   713,   719,   725,   726,   729,   734,   741,   742,   745,
     746,   750,   751,   754,   758,   764,   772,   776,   781,   782,
     785,   786,   787,   790,   792,   795,   796,   797,   798,   799,
     800,   801,   802,   803,   804,   805,   808,   809,   812,   813,
     814,   815,   816,   817,   818,   819,   820,   824,   825,   825,
     829,   830,   830,   833,   834,   842,   848,   852,   853,   856,
     857,   861,   864,   865,   868,   877,   878,   881,   882,   885,
     891,   897,   898,   901,   902,   905,   912,   921,   926,   930,
     931,   934,   935,   938,   943,   950,   951,   952,   956,   960,
     963,   964,   967,   968,   972,   973,   977,   978,   979,   983,
     985,   986,   990,   991,   992,   993,   998,  1000,  1001,  1006,
    1008,  1012,  1013,  1018,  1019,  1020,  1021,  1025,  1033,  1035,
    1036,  1041,  1043,  1047,  1048,  1055,  1056,  1057,  1058,  1059,
    1063,  1070,  1071,  1074,  1075,  1078,  1085,  1086,  1091,  1092,
    1096,  1097,  1098,  1099,  1100,  1104,  1105,  1106,  1109,  1112,
    1113,  1114,  1115,  1116,  1117,  1118,  1119,  1120,  1121,  1124,
    1131,  1133,  1139,  1140,  1141,  1145,  1146,  1149,  1150,  1153,
    1158,  1166,  1167,  1170,  1171,  1174,  1175,  1176
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
  "tALLOCATE", "tANNOTATION", "tAPPOBJECT", "tASYNC", "tASYNCUUID",
  "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN", "tBROADCAST", "tBYTE",
  "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE", "tCDECL", "tCHAR",
  "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST", "tCONTEXTHANDLE",
  "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE", "tCONTROL",
  "tCPPQUOTE", "tDECODE", "tDEFAULT", "tDEFAULTBIND", "tDEFAULTCOLLELEM",
  "tDEFAULTVALUE", "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK",
  "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME", "tDOUBLE", "tDUAL",
  "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL",
  "tFAULTSTATUS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMAYBE", "tMESSAGE", "tMETHODS", "tMODULE",
  "tNAMESPACE", "tNOCODE", "tNONBROWSABLE", "tNONCREATABLE",
  "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG", "tNULL", "tOBJECT", "tODL",
  "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL", "tOUT", "tPARTIALIGNORE",
  "tPASCAL", "tPOINTERDEFAULT", "tPRAGMA_WARNING", "tPROGID",
  "tPROPERTIES", "tPROPGET", "tPROPPUT", "tPROPPUTREF", "tPROXY", "tPTR",
  "tPUBLIC", "tRANGE", "tREADONLY", "tREF", "tREGISTER", "tREPRESENTAS",
  "tREQUESTEDIT", "tRESTRICTED", "tRETVAL", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE", "tSTATIC",
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
  "attribute", "uuid_string", "callconv", "cases", "case", "enums",
  "enum_list", "enum", "enumdef", "m_exprs", "m_expr", "expr",
  "expr_list_int_const", "expr_int_const", "expr_const", "fields", "field",
  "ne_union_field", "ne_union_fields", "union_field", "s_field", "funcdef",
  "declaration", "m_ident", "t_ident", "ident", "base_type", "m_int",
  "int_std", "qualified_seq", "$@3", "qualified_type", "$@4", "coclass",
  "coclasshdr", "coclassdef", "namespacedef", "coclass_ints",
  "coclass_int", "dispinterface", "dispinterfacehdr", "dispint_props",
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
  "acf_interface", "acf_attributes", "acf_attribute_list", "acf_attribute", YY_NULLPTR
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
     435,   436,   437,   438,   439,    44,    63,    58,   124,    94,
      38,    60,    62,    45,    43,    42,    47,    37,    33,   126,
     440,   441,   442,   443,   444,    46,    91,    93,   123,   125,
      59,    40,    41,    61
};
#endif

#define YYPACT_NINF (-561)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-412)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -561,    58,  1724,  -561,  -561,  -561,  -134,   -71,  -561,  -561,
    -561,   151,  -561,  -130,   201,  -561,   217,  -561,  -561,  -561,
    -561,     2,   122,  -561,  -561,  -561,  -561,  -561,   223,     2,
     120,   -38,  -561,   -34,     2,   437,  -561,  -561,   244,   259,
     437,  -561,  -561,  3026,  -561,  -561,  -561,   -46,  -561,  -561,
    -561,  -561,  -561,    27,  2707,   -26,   -25,  -561,  -561,  -561,
     -21,   -15,  -561,    -8,    -5,     3,    51,    57,    71,  -561,
    -561,    60,  -561,    28,    28,    28,    48,  2873,    62,    28,
      63,    66,  -561,    50,  -561,   -71,   110,  -561,  -561,   228,
    -561,  -561,    72,  -561,    69,  -561,  -561,    75,  -561,  -561,
    -561,  -561,  -561,   241,  2873,  -561,  -561,    78,    82,  -112,
    -113,  -561,  -561,    84,  -561,  -561,    87,  -561,  -561,  -561,
      98,   106,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,   107,  -561,  -561,  -561,   123,  -561,  -561,  -561,
     125,   135,  -561,  -561,  -561,  -561,   136,   141,   142,   144,
     147,  -561,   154,  -561,  -561,   155,  -561,   157,  -561,  -561,
     160,   167,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,   169,  -561,  -561,  -561,   170,
     171,  -561,  -561,  -561,  -561,  -561,  -561,   172,  -561,  -561,
     173,  -561,  -561,  -561,   177,  -561,  -561,  -561,   178,   179,
     190,   191,  -561,  -561,  -561,   193,   194,  -561,  -561,   195,
     198,   202,   -68,  -561,  -561,  -561,  1854,   903,   153,   291,
     302,   305,   309,   310,   161,   121,  -561,  -561,  -561,  -561,
      48,   181,   197,  -561,  -561,  -561,  -561,  -561,   -42,  -561,
    -561,  -561,   196,   204,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,  -561,    48,    48,  -561,   203,
     -81,  -561,  -561,  -561,    28,  -561,  -561,  -561,   322,  -561,
    -561,  -561,   -32,  -561,  -561,   409,   205,   323,  -561,   231,
     207,  -561,   209,  -561,   405,   128,   323,   737,   737,   412,
     413,   737,   737,   414,   415,   737,   416,   737,   737,  2237,
     737,   737,   417,   -75,   418,   737,  2873,   737,   737,  2873,
     158,  2873,  2873,   128,   104,   419,  2873,  3026,   224,  -561,
     220,  -561,  -561,  -561,   226,  -561,   225,  -561,  -561,  -561,
      51,  2752,  -561,   229,  -561,  -561,  -561,  -561,   229,  -102,
    -561,  -561,   -51,  -561,   247,   -69,   236,   239,  -561,  -561,
    1260,    24,   237,  -561,   737,    76,  2237,  -561,  -561,   243,
    -561,  -561,    50,  -561,   242,  -561,   246,   267,  -561,   245,
     469,  -561,     4,   153,    30,   266,  -561,  -561,   268,   270,
    -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,   272,
    -561,   737,   737,   737,   737,   737,   737,   727,  2439,  -107,
    -561,  2439,   273,   274,  -561,  -105,   275,   276,   277,   279,
     281,   283,   284,   376,   286,  2752,   124,   287,   -94,  -561,
    2439,   288,   289,   290,   299,   293,   -93,  1494,   294,  -561,
    -561,  -561,  -561,  -561,   297,   298,   303,   306,   312,  -561,
     307,   308,   311,  -561,  3026,   493,  -561,  -561,  -561,    48,
      51,    -1,  -561,  1141,  -561,   334,  2752,   315,  1573,   317,
     435,  1379,    51,  -561,  2752,  -561,  -561,  -561,  -561,   623,
    -561,  2330,   316,   345,  -561,  -561,  -561,  -561,   366,  -561,
     323,   737,  -561,    25,  -561,  2752,  -561,   320,  -561,   324,
    -561,   330,  -561,  -561,  -561,  2752,    36,    36,    36,    36,
      36,    36,  2242,   756,   737,   737,   539,   737,   737,   737,
     737,   737,   737,   737,   737,   737,   737,   737,   737,   737,
     737,   737,   737,   737,   540,   737,   737,  -561,  -561,  -561,
     536,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,  -561,
    -561,   124,  -561,  1973,  -561,   124,  -561,  -561,  -561,   -40,
    -561,   737,  -561,  -561,  -561,  -561,   737,  -561,  -561,  -561,
    -561,  -561,  -561,  -561,  -561,   541,  -561,  -561,  -561,  -561,
     338,  -561,  -561,   367,  -561,  -561,  -561,  -561,    48,   133,
    -561,  -561,  2752,   341,  -561,  -561,  -561,    51,  -561,  -561,
    -561,  -561,  2149,   322,   347,   346,   366,  -561,  -561,  -561,
    -561,   124,   344,   323,  -561,  -561,   756,  -561,  -561,  2061,
    -561,   756,  -561,   351,   -37,   180,   180,  -561,   422,   422,
     127,   127,  2458,  2477,  2400,  2512,  2534,   667,   127,   127,
      96,    96,    36,    36,    36,  -561,  2352,  -561,  -561,  -561,
     105,  -561,   362,   124,   363,  -561,  2237,  -561,  -561,   364,
    -561,    51,  1022,    48,  -561,  -561,  1498,  -561,  -561,  -561,
    -561,   552,  -561,  -561,   371,  -561,  -116,  -561,   369,  -561,
     368,   625,  -561,   372,   124,   374,  -561,   737,  2237,  -561,
     737,  -561,  -561,   105,  -561,  -561,  -561,   375,  -561,  -561,
    -561,  -561,    51,   349,   737,  -561,   124,  -561,  -561,  -561,
    -561,   105,  -561,  -561,  -561,    36,   380,  2439,  -561,  -561,
    -561,  -561,  -561,  -561,    23,  -561,  -561,   737,   391,  -561,
    -561,   392,   -97,   -97,  -561,  -561,   384,  -561,  -561
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    35,   290,     0,   405,   273,   265,
     284,     0,   329,     0,     0,   272,   260,   274,   325,   271,
     275,   276,     0,   328,   278,   285,   286,   283,     0,   276,
       0,     0,   327,     0,   276,     0,   280,   326,   260,   260,
     270,   389,   266,    76,     2,    14,    36,     0,    30,    15,
      33,    15,    13,     0,    69,   392,     0,   391,   267,   390,
       0,     0,    11,     0,     0,     0,    28,     0,   311,     9,
       8,     0,    12,   334,   334,   334,     0,     0,   394,   334,
       0,   396,   291,     0,     4,   405,     0,   293,   294,     0,
     302,   303,   393,   262,     0,   277,   282,     0,   313,   314,
     281,   297,   298,     0,     0,   279,   268,   395,     0,   397,
       0,   269,    77,     0,    79,    80,     0,    81,    82,    83,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   115,     0,   117,   118,     0,   120,     0,   122,   123,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   141,   142,   143,     0,
       0,   146,   147,   148,   149,   387,   150,     0,   152,   385,
       0,   154,   155,   156,     0,   158,   159,   160,     0,     0,
       0,     0,   165,   386,   166,     0,     0,   170,   171,     0,
       0,     0,     0,    71,   175,    31,    68,    68,    68,   260,
       0,     0,   260,   260,     0,   392,   295,   304,   315,   323,
       0,   394,   396,    32,    10,   299,     6,   320,     0,    29,
     318,   319,     0,     0,    26,   338,   335,   337,   336,   263,
     264,   178,   179,   180,   181,   330,     0,     0,   342,   378,
     341,   257,   392,   394,   334,   396,   332,    34,     0,   416,
     415,   417,     0,   413,   406,     0,     0,   186,    50,     0,
       0,   243,     0,   249,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,     0,     0,     0,     0,     0,   196,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    70,    51,
       0,    23,    24,    25,     0,    21,     0,    19,    16,    22,
      28,     0,    69,   393,    53,    54,   321,   322,   395,   397,
      55,   256,    68,     5,     0,    68,     0,     0,   312,    26,
      68,     0,     0,   340,     0,     0,    57,   344,   333,     0,
     287,   292,     0,   412,     0,    49,     0,   188,   189,   192,
       0,   398,    68,    68,    68,     0,   177,   176,     0,     0,
     207,   198,   199,   200,   204,   205,   206,   201,   202,     0,
     203,     0,     0,     0,     0,     0,     0,     0,   241,     0,
     239,   242,     0,     0,    74,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   363,     0,     0,   194,
     197,     0,     0,     0,     0,     0,     0,     0,     0,   380,
     381,   382,   383,   384,     0,     0,     0,     0,   402,   404,
       0,     0,     0,    72,    76,     0,    20,    17,    56,     0,
      28,     0,   300,    68,   305,     0,     0,     0,     0,     0,
       0,    68,    28,    27,    69,   331,   339,   343,   379,     0,
      67,     0,     0,    61,    58,    59,   288,   414,   407,   193,
     187,     0,    38,     0,   388,     0,   244,     0,   400,    69,
     250,     0,    78,   169,    84,     0,   231,   230,   229,   232,
     227,   228,     0,   351,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    96,   100,
       0,   104,   105,   110,   111,   112,   113,   114,   116,   119,
     121,   363,   330,    57,   368,   363,   365,   364,    64,   360,
     125,   196,   124,   140,   144,   145,     0,   153,   157,   161,
     162,   164,   163,   167,   168,     0,   172,   173,   174,    73,
       0,    15,   371,   399,   296,   301,     7,   307,     0,   394,
     306,   309,     0,     0,   255,   310,    26,    28,   324,    66,
      65,   345,     0,     0,   411,     0,   407,   190,   191,    39,
      37,     0,   396,   258,   248,   247,   351,   238,   330,    57,
     355,   351,   352,     0,   348,   220,   221,   233,   214,   215,
     218,   219,   209,   210,     0,   211,   212,   213,   217,   216,
     223,   222,   225,   226,   224,   234,     0,   240,    75,    63,
     363,   330,     0,   363,     0,   359,    57,   367,   195,     0,
     403,    28,    68,     0,   253,   308,    68,   316,    62,    60,
     289,     0,   410,   408,   373,   376,     0,   246,     0,   259,
       0,   351,   330,     0,   363,     0,   347,     0,    57,   354,
       0,   237,   358,   363,   369,   362,   366,     0,   151,    52,
      18,   372,    28,     0,     0,   375,     0,   245,   182,   236,
     346,   363,   356,   350,   353,   235,     0,   208,   361,   370,
     317,   409,   374,   377,     0,   349,   357,     0,     0,   401,
     183,     0,    68,    68,   252,   185,     0,   184,   251
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -561,  -561,  -561,   252,  -561,   -47,  -561,  -323,  -322,     0,
    -561,  -561,  -561,  -561,  -561,   145,  -561,  -561,  -561,    11,
    -487,  -561,  -561,  -288,  -250,  -211,    -2,  -561,  -561,  -287,
     295,   -62,  -561,  -561,  -561,  -561,   116,    13,   304,    53,
     206,  -561,  -272,  -286,  -561,  -561,  -561,  -561,  -117,  -270,
    -561,   152,  -561,    34,   -70,  -561,   138,   148,    29,  -561,
     370,  -561,    10,  -561,    17,    19,  -561,  -561,   566,  -561,
    -561,  -561,  -561,  -561,   -17,  -561,    20,    16,  -561,  -561,
      22,  -561,  -561,  -334,  -492,   -53,   -30,   -39,  -218,  -561,
    -561,  -561,  -529,  -561,  -560,  -561,  -493,  -561,  -561,  -561,
     -73,  -561,   394,  -561,   318,     1,   -61,  -561,     7,  -561,
     544,    40,  -561,  -561,    43,  -561,   278
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    44,     2,   343,   216,   571,   350,   240,   321,
      46,   483,    47,    48,    49,    50,   322,   224,    51,   323,
     472,   473,   474,   475,   544,    53,   332,   212,   405,   213,
     378,   545,   714,   720,   366,   367,   368,   262,   418,   419,
     398,   399,   400,   402,   372,   486,   490,   374,   725,   726,
     583,    56,   668,    94,   546,    57,    96,    58,   361,   593,
      59,   268,   324,    61,   325,   326,   342,   452,    64,    65,
     345,   458,    66,   243,    67,    68,   327,   328,   229,    71,
     329,    73,    74,    75,   351,    76,   245,    77,   259,   260,
     612,   675,   613,   614,   547,   644,   548,   549,   573,   695,
     665,   666,   261,   434,   214,   263,    79,    80,   265,   440,
      84,   595,   596,    85,    86,   272,   273
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   230,    45,    78,   217,   406,   258,   331,   448,    81,
     357,   414,    60,    52,   257,    55,   264,   465,    70,    62,
     407,    63,    69,   410,    72,   412,   461,   249,   417,   250,
     443,  -411,   599,   424,   246,   246,   246,   228,   352,   353,
     246,   664,   455,   280,   247,   248,   282,  -261,   639,   266,
     640,   249,   645,   250,   506,   231,   642,  -261,     3,    14,
      28,   232,   185,   717,   226,   251,   189,   225,   468,   696,
      12,    82,   108,   110,    12,   457,   718,   670,   526,   380,
     530,    89,   676,   381,   382,   383,   384,   385,   386,   251,
     344,   551,   551,   203,   697,   283,  -261,   252,   -45,    18,
      95,    28,   269,   487,   491,   527,  -261,   531,   249,    43,
     250,   438,   439,   724,   506,   270,   671,   317,   552,   558,
     271,   252,   673,   101,    23,   355,   102,   249,   574,   250,
     356,   451,    97,   466,   456,    83,   664,    43,   376,   318,
     588,   377,   700,   504,   505,   506,   251,   682,   387,   683,
     685,    12,   253,   362,    87,    43,    88,   569,   450,   687,
     258,   485,   456,   456,   215,   251,   355,   100,   257,   355,
      32,   646,   105,   103,   678,   363,   253,   104,   252,   254,
     701,   703,    37,   106,   -40,   233,   258,   258,   111,   234,
     708,   706,   218,   235,   257,   257,   388,   252,   506,   347,
     236,     5,     6,   254,    90,   237,    91,   369,   715,   598,
      43,   238,   275,   484,    54,    54,   379,    78,    78,   255,
      92,   346,    93,    81,    81,   246,    98,   389,    99,    55,
      55,   572,   719,   253,   358,   256,    43,   600,   276,   488,
     390,   524,   525,   255,   279,   425,   416,   107,   428,    93,
     435,   436,   253,   610,   637,   442,   108,   110,   242,   256,
     254,   239,   109,   656,    93,   657,   391,   241,   244,   392,
     393,   469,   -42,   267,   395,   396,   -44,   277,   449,   254,
    -261,   258,   -41,   470,   649,   278,  -261,   397,   -43,   257,
     281,   521,   522,   523,   333,   284,    93,   415,   285,   647,
     542,   524,   525,   416,   659,   334,   465,   335,   336,   286,
     337,   355,   338,   339,    93,    93,   543,   287,   288,   542,
     519,   520,   521,   522,   523,   359,   249,   360,   250,   689,
     355,   -46,   524,   525,   289,   543,   290,   465,   429,   430,
     431,   432,   433,  -254,   503,  -254,   291,   292,   464,   465,
     463,    78,   293,   294,   415,   295,   610,    81,   296,    43,
     654,   610,   541,    55,   679,   297,   298,   465,   299,   340,
     710,   300,   489,   519,   520,   521,   522,   523,   301,   258,
     302,   303,   304,   305,   306,   524,   525,   257,   307,   308,
     309,   -47,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   310,   311,   578,   312,   313,   314,   -48,   712,   315,
     369,   230,   349,   316,   364,   375,   354,   365,   370,   371,
     373,   610,   403,   404,   408,   409,   411,   421,   423,   441,
     444,   445,   601,   447,   454,   691,   446,  -261,   504,   505,
     506,   611,   606,   509,   510,   721,   459,   460,   476,   467,
     478,    54,   480,    45,    78,   479,   582,   579,   481,   464,
      81,   463,    78,    60,    52,   231,    55,   575,    81,    70,
      62,   232,    63,    69,    55,    72,   482,   225,   492,    10,
     493,   643,   494,   495,   556,   528,   529,   532,   533,   534,
     416,   535,   602,   536,   401,   537,   538,   401,   540,   550,
     553,   554,   555,   570,   413,   557,   560,   420,   258,   561,
     562,   456,   456,   420,   427,   563,   257,   565,   564,   566,
     567,   577,    21,   568,   652,   580,   585,    22,   591,   230,
     592,   594,   603,   669,   604,    24,    25,    26,    27,   416,
     605,   415,   617,   635,   611,    29,   638,   674,   650,   611,
     651,   655,   653,    83,   667,   662,   416,   693,   694,   711,
     401,   471,   513,   677,   514,   515,   516,   517,   518,   519,
     520,   521,   522,   523,   684,   686,   688,   698,   722,   723,
     699,   524,   525,   258,   702,    34,   704,   709,   539,    36,
     415,   257,   716,   416,   728,   453,   597,   496,   497,   498,
     499,   500,   501,   502,   648,   586,   727,   415,   437,   611,
     584,   426,   348,   517,   518,   519,   520,   521,   522,   523,
     227,   422,   660,   713,   341,   416,   380,   524,   525,   274,
     381,   382,   383,   384,   385,   386,   663,   661,     0,     0,
     477,     0,     0,     0,   415,     0,     0,     0,     0,     0,
      54,     0,     0,    78,   464,     0,   463,    78,     0,    81,
       0,     0,     0,    81,     0,    55,   251,     0,     0,    55,
       0,    12,     0,     0,     0,   499,   415,     0,     0,     0,
       0,     0,     0,   504,   505,   506,   507,   508,   509,   510,
       0,     0,     0,     0,     0,   387,     0,     0,   252,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     615,   616,     0,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,   633,   634,
     380,   636,     5,     6,   381,   382,   383,   384,   385,   386,
     380,     0,     0,   388,   381,   382,   383,   384,   385,   386,
       0,     0,     0,   253,     0,     0,     0,   420,     0,     0,
       0,     8,     0,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    12,   389,     0,     0,     0,     0,     0,
     254,     0,     0,     0,     0,     0,     0,   390,     0,    15,
       0,     0,     0,     0,     0,   219,    17,   251,    18,   387,
       0,     0,    19,     0,     0,    20,     0,     0,     0,   387,
       0,     0,    21,   391,     0,     0,   392,   393,   394,     0,
     608,   395,   396,    23,     0,    24,    25,    26,    27,   252,
     589,   355,     0,     0,   397,    29,   609,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   388,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   388,   517,   518,
     519,   520,   521,   522,   523,     0,     0,     0,     0,    32,
       0,     0,   524,   525,    33,    34,    35,     0,   389,    36,
       0,    37,     0,   705,   253,   222,   707,     0,   389,     0,
       0,   390,     0,     0,   223,     0,    40,     0,     0,     0,
     401,   390,     0,     0,    41,    42,     0,     4,     5,     6,
       0,   254,     0,     0,     0,     0,     0,   391,     0,     0,
     392,   393,   394,     0,     0,   395,   396,   391,     0,     0,
     392,   393,   394,     0,     0,   395,   396,     8,   397,     9,
       0,     0,     0,     0,     0,    10,    11,     0,   397,    12,
       0,   608,     0,     0,    13,     0,     0,     0,     0,     0,
       0,     0,   355,    14,     0,    15,     0,   609,     0,     0,
       0,    16,    17,     0,    18,     0,     0,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,    22,   320,     0,     0,    23,
       0,    24,    25,    26,    27,    28,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,     0,     0,    36,     8,    37,     9,     0,
       0,    38,     0,     0,    10,    11,     0,     0,    12,     0,
      39,     0,    40,    13,     0,     0,     0,     0,     0,     0,
      41,    42,    14,     0,    15,     0,     0,     0,     0,     0,
      16,    17,     0,    18,     0,     0,     0,    19,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,    43,
       0,     0,   330,     0,    22,   320,     0,     0,    23,     0,
      24,    25,    26,    27,    28,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     0,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,    33,
      34,    35,     0,     0,    36,     8,    37,     9,     0,     0,
      38,     0,     0,    10,    11,     0,     0,    12,     0,    39,
       0,    40,    13,     0,     0,     0,     0,     0,     0,    41,
      42,    14,     0,    15,     0,     0,     0,     0,     0,    16,
      17,     0,    18,     0,     0,     0,    19,     0,     0,    20,
       0,     0,     0,     0,     0,     0,    21,     0,    43,     0,
       0,   690,     0,    22,     0,     0,     0,    23,     0,    24,
      25,    26,    27,    28,     0,     0,     0,     0,     0,    29,
       0,     0,     0,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     6,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,    33,    34,
      35,     0,     0,    36,     8,    37,     9,     0,     0,    38,
       0,     0,    10,     0,     0,     0,    12,     0,    39,     0,
      40,    13,     0,     0,     0,     0,     0,     0,    41,    42,
       0,     0,    15,     0,     0,     0,     0,     0,    16,    17,
       0,    18,     0,     0,     0,    19,     0,     0,    20,     0,
       0,     0,     0,     0,     0,    21,     0,    43,     0,     0,
     576,     0,    22,     0,     0,     0,    23,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     0,     0,     0,     0,
      31,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,     0,     0,     0,     0,    33,    34,    35,
       0,     0,    36,     8,    37,     9,     0,     0,    38,     0,
       0,    10,     0,     0,     0,    12,     0,    39,     0,    40,
      13,     0,     0,     0,     0,     0,     0,    41,    42,     0,
       0,    15,     0,     0,     0,     0,     0,    16,    17,     0,
      18,     0,     0,     0,    19,     0,     0,    20,     0,     0,
       0,     0,     0,     0,    21,     0,    43,     0,     0,   462,
       0,    22,     0,     0,     0,    23,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     6,     0,     0,     0,     0,    31,
     504,   505,   506,   507,   508,   509,   510,   511,   512,     0,
       0,    32,     0,     0,     0,     0,    33,    34,    35,     0,
       0,    36,     8,    37,     9,     0,     0,    38,     0,     0,
      10,     0,     0,     0,    12,     0,    39,     0,    40,    13,
       0,     0,     0,     0,     0,     0,    41,    42,     0,     0,
      15,     0,     0,     0,     0,     0,    16,    17,     0,    18,
       0,     0,     0,    19,     0,     0,    20,     0,     5,     6,
       0,     0,     0,    21,     0,    43,     0,     0,   587,     0,
      22,     0,     0,     0,    23,     0,    24,    25,    26,    27,
       0,     0,     0,     0,     0,     0,    29,     8,     0,     9,
       0,     0,     0,     0,     0,    10,     0,     0,     0,    12,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
      32,   219,    17,     0,    18,    33,    34,    35,    19,     0,
      36,    20,    37,     0,     0,     0,    38,     0,    21,     0,
       0,     0,     0,     0,     0,    39,     0,    40,     0,    23,
       0,    24,    25,    26,    27,    41,    42,     0,     0,     0,
     513,    29,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,     0,     0,     0,     0,     0,     0,     0,   524,
     525,     0,     0,     0,    43,     0,   559,   692,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,     0,     0,    36,     0,    37,     4,     5,
       6,   222,     0,     0,     0,     0,     0,     0,     0,     7,
     223,     0,    40,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,     0,     0,     0,     0,     0,     8,     0,
       9,     0,     0,     0,     0,     0,    10,    11,     0,     0,
      12,     0,     0,     0,     0,    13,     0,     0,     0,    43,
       0,     0,   581,     0,    14,     0,    15,     0,     0,     0,
       0,     0,    16,    17,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
      23,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     4,     5,
       6,     0,     0,     0,     0,     0,    32,     0,   319,     0,
       0,    33,    34,    35,     0,     0,    36,     0,    37,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     8,   -68,
       9,    39,     0,    40,     0,     0,    10,    11,     0,     0,
      12,    41,    42,     0,     0,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,    15,     0,     0,     0,
       0,     0,    16,    17,     0,    18,     0,     0,     0,    19,
      43,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,   320,     0,     0,
      23,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,    33,    34,    35,     0,     0,    36,     8,    37,     9,
       0,     0,    38,     0,   251,    10,     0,     0,     0,    12,
       0,    39,     0,    40,     0,     0,     0,     0,     0,     0,
       0,    41,    42,     0,     0,    15,     0,     0,     0,     0,
       0,   219,    17,     0,    18,     0,   252,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
      43,     0,     0,     0,     0,     0,     5,     6,     0,    23,
       0,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     8,     0,     9,     0,     0,
       0,   253,   251,    10,     0,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,    15,     0,    36,     0,    37,   254,   219,
      17,   222,    18,     0,   252,     0,    19,     0,     0,    20,
     223,     0,    40,     0,     0,     0,    21,     0,     0,     0,
      41,    42,     0,     0,     5,     6,     0,    23,     0,    24,
      25,    26,    27,     0,     0,     0,     0,     0,   641,    29,
       0,     0,     0,     0,   658,     0,     0,     0,     0,    43,
       0,     0,     0,     8,     0,     9,     0,     0,     0,   253,
       0,    10,     0,     0,     0,    12,     0,     0,     0,     0,
       0,     0,     0,    32,     0,     0,     0,     0,    33,    34,
      35,    15,     0,    36,     0,    37,   254,   219,    17,   222,
      18,     0,     0,     0,    19,     0,     0,    20,   223,     0,
      40,     0,     0,     0,    21,     0,     0,     0,    41,    42,
       0,     0,     5,     6,     0,    23,     0,    24,    25,    26,
      27,     0,     0,     0,     0,     0,   672,    29,   504,   505,
     506,   507,   508,   509,   510,   511,   512,    43,     0,     0,
       0,     8,     0,     9,     0,     0,     0,     0,     0,    10,
       0,     0,     0,    12,     0,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,    33,    34,    35,    15,
       0,    36,     0,    37,     0,   219,    17,   222,    18,     0,
       0,     0,    19,     0,     0,    20,   223,     0,    40,     0,
       0,     0,    21,     0,     0,     0,    41,    42,     0,     0,
       0,     0,     0,    23,     0,    24,    25,    26,    27,     0,
       0,     0,     0,     0,     0,    29,   504,   505,   506,   507,
     508,   509,   510,   511,   512,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   504,   505,
     506,   507,   508,   509,   510,   511,   512,     0,     0,    32,
       0,     0,     0,     0,    33,    34,    35,     0,     0,    36,
       0,    37,     0,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    41,    42,   504,   505,   506,   507,
     508,   509,   510,   511,   512,     0,     0,     0,   513,     0,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
       0,     0,     0,    43,     0,     0,     0,   524,   525,     0,
       0,     0,     0,     0,   607,   504,   505,   506,   507,   508,
     509,   510,   511,   512,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,   505,   506,   507,   508,   509,
     510,     0,   512,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   504,   505,   506,   507,   508,   509,   510,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,     0,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   504,   505,
     506,   507,   508,   509,   510,   524,   525,   590,   513,     0,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     504,   505,   506,   507,   508,   509,   510,   524,   525,   681,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   513,   680,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,     0,     0,
       0,     0,     0,     0,     0,   524,   525,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   513,     0,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,     0,     0,     0,
       0,     0,     0,     0,   524,   525,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,     0,     0,     0,     0,
       0,     0,     0,   524,   525,   514,   515,   516,   517,   518,
     519,   520,   521,   522,   523,     0,     0,     0,     0,     0,
       0,     0,   524,   525,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   515,   516,   517,   518,   519,   520,   521,   522,   523,
       0,     0,     5,     6,     0,     0,     0,   524,   525,     0,
       0,     0,     0,     0,   516,   517,   518,   519,   520,   521,
     522,   523,     0,     0,     0,     0,     0,     0,     0,   524,
     525,     8,     0,     9,     0,     0,     0,     0,     0,    10,
      11,     0,     0,    12,     0,     0,     0,     5,     6,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
       0,     0,     0,     0,     0,   219,    17,     0,    18,     0,
       0,     0,    19,     0,     0,    20,     8,     0,     9,     0,
       0,     0,    21,     0,    10,     0,     0,     0,    12,     0,
       0,     0,     0,    23,     0,    24,    25,    26,    27,    28,
       0,     0,   220,     0,    15,    29,     0,     0,     0,   221,
     219,    17,     0,    18,     0,     0,     0,    19,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    23,    32,
      24,    25,    26,    27,    33,    34,    35,     0,     0,    36,
      29,    37,     0,     0,     0,   222,     0,     0,     0,     0,
       0,     0,     0,     0,   223,     0,    40,     0,     5,     6,
       0,     0,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,    33,
      34,    35,     0,     0,    36,     0,    37,     8,     0,     9,
     222,     0,     0,     0,     0,    10,     0,     0,     0,   223,
       0,    40,     0,     0,     0,     0,     0,     0,     0,    41,
      42,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,   219,    17,     0,     0,     0,     0,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,     0,     0,    36,     0,     0,     0,     0,
       0,   222,     0,     0,     0,     0,     0,     0,     0,     0,
     223,     0,    40,     0,     0,     0,     0,     0,     0,     0,
      41,    42,   112,     0,   113,   114,   115,   116,   117,   118,
       0,   119,     0,     0,   120,     0,   121,     0,     0,     0,
     122,   123,     0,   124,   125,   126,   127,     0,   128,   129,
     130,   131,   132,   133,   134,   135,     0,   136,     0,   137,
     138,   139,   140,   141,     0,     0,   142,     0,     0,     0,
     143,     0,   144,   145,     0,   146,   147,   148,   149,   150,
     151,     0,   152,   153,   154,   155,   156,   157,     0,     0,
     158,     0,     0,   159,     0,     0,     0,     0,     0,   160,
     161,     0,   162,   163,     0,   164,   165,     0,     0,     0,
     166,   167,   168,   169,   170,   171,     0,   172,   173,   174,
     175,   176,   177,   178,     0,   179,     0,   180,     0,   181,
     182,   183,   184,   185,   186,   187,   188,   189,     0,   190,
     191,   192,   193,     0,     0,     0,   194,     0,     0,   195,
       0,     0,   196,   197,     0,     0,   198,   199,   200,   201,
       0,     0,   202,     0,   203,     0,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211
};

static const yytype_int16 yycheck[] =
{
       2,    54,     2,     2,    51,   291,    76,   218,   330,     2,
     260,   299,     2,     2,    76,     2,    77,   351,     2,     2,
     292,     2,     2,   295,     2,   297,   349,     3,   300,     5,
     317,   102,     7,   305,    73,    74,    75,    54,   256,   257,
      79,   601,   111,   104,    74,    75,   159,   159,   541,    79,
     542,     3,   545,     5,    18,    54,   543,   159,     0,    60,
     102,    54,   137,    40,    54,    41,   141,    54,   354,   185,
      46,   205,    38,    39,    46,   345,    53,   606,   185,     3,
     185,   211,   611,     7,     8,     9,    10,    11,    12,    41,
     132,   185,   185,   168,   210,   208,   208,    73,   210,    71,
      98,   102,    52,   373,   374,   212,   208,   212,     3,   206,
       5,     7,     8,   210,    18,    65,   608,   185,   212,   212,
      70,    73,   609,     3,    96,   206,     6,     3,   450,     5,
     211,   342,    10,   351,   345,   206,   696,   206,    10,   207,
     462,    13,   671,    16,    17,    18,    41,   640,    72,   641,
     643,    46,   128,   185,     3,   206,     5,   444,   209,   646,
     230,   372,   373,   374,   210,    41,   206,    29,   230,   206,
     142,   211,    34,   211,   211,   207,   128,   211,    73,   155,
     672,   674,   154,    35,   210,   210,   256,   257,    40,   210,
     683,   678,   165,   208,   256,   257,   120,    73,    18,     3,
     208,     5,     6,   155,     3,   210,     5,   277,   701,   481,
     206,   208,   102,   209,   216,   217,   286,   216,   217,   195,
       3,   238,     5,   216,   217,   264,     3,   151,     5,   216,
     217,   449,   209,   128,   264,   211,   206,   212,    10,   209,
     164,   205,   206,   195,     3,   306,   299,     3,   309,     5,
     311,   312,   128,   503,   526,   316,   222,   223,   187,   211,
     155,   210,     3,   586,     5,   587,   190,   210,   208,   193,
     194,   195,   210,   210,   198,   199,   210,   208,   331,   155,
     208,   351,   210,   207,   556,   210,   208,   211,   210,   351,
     208,   195,   196,   197,     3,   211,     5,   299,   211,   549,
     195,   205,   206,   356,   592,     3,   640,     5,     3,   211,
       5,   206,     3,     3,     5,     5,   211,   211,   211,   195,
     193,   194,   195,   196,   197,     3,     3,     5,     5,   651,
     206,   210,   205,   206,   211,   211,   211,   671,   180,   181,
     182,   183,   184,   210,   397,   212,   211,   211,   350,   683,
     350,   350,   211,   211,   356,   211,   606,   350,   211,   206,
     578,   611,   415,   350,   614,   211,   211,   701,   211,   208,
     692,   211,   374,   193,   194,   195,   196,   197,   211,   449,
     211,   211,   211,   211,   211,   205,   206,   449,   211,   211,
     211,   210,    16,    17,    18,    19,    20,    21,    22,    23,
      24,   211,   211,   456,   211,   211,   211,   210,   694,   211,
     480,   464,   208,   211,     5,    10,   213,   212,   187,   212,
     211,   671,    10,    10,    10,    10,    10,    10,    10,    10,
     206,   211,   485,   208,   187,   653,   210,   208,    16,    17,
      18,   503,   495,    21,    22,   717,   210,   208,   205,   212,
     208,   453,   185,   453,   453,   209,   458,   456,   213,   461,
     453,   461,   461,   453,   453,   464,   453,   451,   461,   453,
     453,   464,   453,   453,   461,   453,     7,   464,   212,    42,
     212,   543,   212,   211,   185,   212,   212,   212,   212,   212,
     543,   212,   485,   212,   288,   212,   212,   291,   212,   212,
     212,   212,   212,    10,   298,   212,   212,   301,   578,   212,
     212,   722,   723,   307,   308,   212,   578,   205,   212,   212,
     212,   187,    85,   212,   571,   210,   209,    92,   212,   582,
     185,   165,   212,   603,   210,    98,    99,   100,   101,   592,
     210,   543,     3,     3,   606,   108,    10,   609,     7,   611,
     212,   210,   185,   206,   210,   209,   609,     5,   187,   210,
     354,   355,   186,   212,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   212,   212,   212,   208,   187,   187,
     212,   205,   206,   653,   212,   148,   212,   212,   212,   152,
     592,   653,   212,   646,   210,   343,   480,   391,   392,   393,
     394,   395,   396,   397,   551,   460,   723,   609,   313,   671,
     458,   307,   242,   191,   192,   193,   194,   195,   196,   197,
      54,   303,   593,   696,   230,   678,     3,   205,   206,    85,
       7,     8,     9,    10,    11,    12,   596,   594,    -1,    -1,
     362,    -1,    -1,    -1,   646,    -1,    -1,    -1,    -1,    -1,
     652,    -1,    -1,   652,   656,    -1,   656,   656,    -1,   652,
      -1,    -1,    -1,   656,    -1,   652,    41,    -1,    -1,   656,
      -1,    46,    -1,    -1,    -1,   469,   678,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     504,   505,    -1,   507,   508,   509,   510,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
       3,   525,     5,     6,     7,     8,     9,    10,    11,    12,
       3,    -1,    -1,   120,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,   128,    -1,    -1,    -1,   551,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,   151,    -1,    -1,    -1,    -1,    -1,
     155,    -1,    -1,    -1,    -1,    -1,    -1,   164,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    41,    71,    72,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    72,
      -1,    -1,    85,   190,    -1,    -1,   193,   194,   195,    -1,
     195,   198,   199,    96,    -1,    98,    99,   100,   101,    73,
     207,   206,    -1,    -1,   211,   108,   211,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,   142,
      -1,    -1,   205,   206,   147,   148,   149,    -1,   151,   152,
      -1,   154,    -1,   677,   128,   158,   680,    -1,   151,    -1,
      -1,   164,    -1,    -1,   167,    -1,   169,    -1,    -1,    -1,
     694,   164,    -1,    -1,   177,   178,    -1,     4,     5,     6,
      -1,   155,    -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,
     193,   194,   195,    -1,    -1,   198,   199,   190,    -1,    -1,
     193,   194,   195,    -1,    -1,   198,   199,    34,   211,    36,
      -1,    -1,    -1,    -1,    -1,    42,    43,    -1,   211,    46,
      -1,   195,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   206,    60,    -1,    62,    -1,   211,    -1,    -1,
      -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,    96,
      -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,   152,    34,   154,    36,    -1,
      -1,   158,    -1,    -1,    42,    43,    -1,    -1,    46,    -1,
     167,    -1,   169,    51,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,   206,
      -1,    -1,   209,    -1,    92,    93,    -1,    -1,    96,    -1,
      98,    99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,   152,    34,   154,    36,    -1,    -1,
     158,    -1,    -1,    42,    43,    -1,    -1,    46,    -1,   167,
      -1,   169,    51,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,    60,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,   206,    -1,
      -1,   209,    -1,    92,    -1,    -1,    -1,    96,    -1,    98,
      99,   100,   101,   102,    -1,    -1,    -1,    -1,    -1,   108,
      -1,    -1,    -1,    -1,   113,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,
     149,    -1,    -1,   152,    34,   154,    36,    -1,    -1,   158,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,   167,    -1,
     169,    51,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,
      -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,
      -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,
      -1,    -1,    -1,    -1,    -1,    85,    -1,   206,    -1,    -1,
     209,    -1,    92,    -1,    -1,    -1,    96,    -1,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
     130,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,
      -1,    -1,   152,    34,   154,    36,    -1,    -1,   158,    -1,
      -1,    42,    -1,    -1,    -1,    46,    -1,   167,    -1,   169,
      51,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,    -1,
      -1,    62,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    -1,   206,    -1,    -1,   209,
      -1,    92,    -1,    -1,    -1,    96,    -1,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,   130,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,    -1,
      -1,   152,    34,   154,    36,    -1,    -1,   158,    -1,    -1,
      42,    -1,    -1,    -1,    46,    -1,   167,    -1,   169,    51,
      -1,    -1,    -1,    -1,    -1,    -1,   177,   178,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    -1,     5,     6,
      -1,    -1,    -1,    85,    -1,   206,    -1,    -1,   209,    -1,
      92,    -1,    -1,    -1,    96,    -1,    98,    99,   100,   101,
      -1,    -1,    -1,    -1,    -1,    -1,   108,    34,    -1,    36,
      -1,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
     142,    68,    69,    -1,    71,   147,   148,   149,    75,    -1,
     152,    78,   154,    -1,    -1,    -1,   158,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,   169,    -1,    96,
      -1,    98,    99,   100,   101,   177,   178,    -1,    -1,    -1,
     186,   108,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,    -1,    -1,    -1,   206,    -1,   212,   209,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,   152,    -1,   154,     4,     5,
       6,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,
     167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      36,    -1,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,   206,
      -1,    -1,   209,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    -1,    -1,    -1,
      96,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,   142,    -1,    14,    -1,
      -1,   147,   148,   149,    -1,    -1,   152,    -1,   154,    -1,
      -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    34,   165,
      36,   167,    -1,   169,    -1,    -1,    42,    43,    -1,    -1,
      46,   177,   178,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
     206,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    92,    93,    -1,    -1,
      96,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,     6,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,    -1,   152,    34,   154,    36,
      -1,    -1,   158,    -1,    41,    42,    -1,    -1,    -1,    46,
      -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    71,    -1,    73,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
     206,    -1,    -1,    -1,    -1,    -1,     5,     6,    -1,    96,
      -1,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,
      -1,   128,    41,    42,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     147,   148,   149,    62,    -1,   152,    -1,   154,   155,    68,
      69,   158,    71,    -1,    73,    -1,    75,    -1,    -1,    78,
     167,    -1,   169,    -1,    -1,    -1,    85,    -1,    -1,    -1,
     177,   178,    -1,    -1,     5,     6,    -1,    96,    -1,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,   195,   108,
      -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,   206,
      -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,   128,
      -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,   148,
     149,    62,    -1,   152,    -1,   154,   155,    68,    69,   158,
      71,    -1,    -1,    -1,    75,    -1,    -1,    78,   167,    -1,
     169,    -1,    -1,    -1,    85,    -1,    -1,    -1,   177,   178,
      -1,    -1,     5,     6,    -1,    96,    -1,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,   195,   108,    16,    17,
      18,    19,    20,    21,    22,    23,    24,   206,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    -1,    -1,    -1,    -1,   147,   148,   149,    62,
      -1,   152,    -1,   154,    -1,    68,    69,   158,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,   167,    -1,   169,    -1,
      -1,    -1,    85,    -1,    -1,    -1,   177,   178,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    99,   100,   101,    -1,
      -1,    -1,    -1,    -1,    -1,   108,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,   142,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,    -1,   152,
      -1,   154,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   206,    -1,    -1,    -1,   205,   206,    -1,
      -1,    -1,    -1,    -1,   212,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    17,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    16,    17,
      18,    19,    20,    21,    22,   205,   206,   207,   186,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      16,    17,    18,    19,    20,    21,    22,   205,   206,   207,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   186,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   205,   206,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   205,   206,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,     5,     6,    -1,    -1,    -1,   205,   206,    -1,
      -1,    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,
     206,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    34,    -1,    36,    -1,
      -1,    -1,    85,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    96,    -1,    98,    99,   100,   101,   102,
      -1,    -1,   105,    -1,    62,   108,    -1,    -1,    -1,   112,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,   142,
      98,    99,   100,   101,   147,   148,   149,    -1,    -1,   152,
     108,   154,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   167,    -1,   169,    -1,     5,     6,
      -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,   152,    -1,   154,    34,    -1,    36,
     158,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,   167,
      -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,   152,    -1,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,    26,    -1,    28,    29,    30,    31,    32,    33,
      -1,    35,    -1,    -1,    38,    -1,    40,    -1,    -1,    -1,
      44,    45,    -1,    47,    48,    49,    50,    -1,    52,    53,
      54,    55,    56,    57,    58,    59,    -1,    61,    -1,    63,
      64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,    -1,
      74,    -1,    76,    77,    -1,    79,    80,    81,    82,    83,
      84,    -1,    86,    87,    88,    89,    90,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,   103,
     104,    -1,   106,   107,    -1,   109,   110,    -1,    -1,    -1,
     114,   115,   116,   117,   118,   119,    -1,   121,   122,   123,
     124,   125,   126,   127,    -1,   129,    -1,   131,    -1,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    -1,   143,
     144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,   153,
      -1,    -1,   156,   157,    -1,    -1,   160,   161,   162,   163,
      -1,    -1,   166,    -1,   168,    -1,   170,   171,   172,   173,
     174,   175,   176,    -1,    -1,   179
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   215,   217,     0,     4,     5,     6,    15,    34,    36,
      42,    43,    46,    51,    60,    62,    68,    69,    71,    75,
      78,    85,    92,    96,    98,    99,   100,   101,   102,   108,
     113,   130,   142,   147,   148,   149,   152,   154,   158,   167,
     169,   177,   178,   206,   216,   223,   224,   226,   227,   228,
     229,   232,   233,   239,   240,   251,   265,   269,   271,   274,
     276,   277,   278,   279,   282,   283,   286,   288,   289,   290,
     291,   293,   294,   295,   296,   297,   299,   301,   319,   320,
     321,   322,   205,   206,   324,   327,   328,     3,     5,   211,
       3,     5,     3,     5,   267,    98,   270,    10,     3,     5,
     270,     3,     6,   211,   211,   270,   271,     3,   267,     3,
     267,   271,    26,    28,    29,    30,    31,    32,    33,    35,
      38,    40,    44,    45,    47,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    61,    63,    64,    65,
      66,    67,    70,    74,    76,    77,    79,    80,    81,    82,
      83,    84,    86,    87,    88,    89,    90,    91,    94,    97,
     103,   104,   106,   107,   109,   110,   114,   115,   116,   117,
     118,   119,   121,   122,   123,   124,   125,   126,   127,   129,
     131,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     143,   144,   145,   146,   150,   153,   156,   157,   160,   161,
     162,   163,   166,   168,   170,   171,   172,   173,   174,   175,
     176,   179,   241,   243,   318,   210,   219,   219,   165,    68,
     105,   112,   158,   167,   231,   251,   276,   282,   288,   292,
     299,   319,   322,   210,   210,   208,   208,   210,   208,   210,
     222,   210,   187,   287,   208,   300,   301,   300,   300,     3,
       5,    41,    73,   128,   155,   195,   211,   245,   268,   302,
     303,   316,   251,   319,   320,   322,   300,   210,   275,    52,
      65,    70,   329,   330,   324,   102,    10,   208,   210,     3,
     320,   208,   159,   208,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   185,   207,    14,
      93,   223,   230,   233,   276,   278,   279,   290,   291,   294,
     209,   239,   240,     3,     3,     5,     3,     5,     3,     3,
     208,   316,   280,   218,   132,   284,   288,     3,   274,   208,
     221,   298,   302,   302,   213,   206,   211,   238,   300,     3,
       5,   272,   185,   207,     5,   212,   248,   249,   250,   268,
     187,   212,   258,   211,   261,    10,    10,    13,   244,   268,
       3,     7,     8,     9,    10,    11,    12,    72,   120,   151,
     164,   190,   193,   194,   195,   198,   199,   211,   254,   255,
     256,   254,   257,    10,    10,   242,   257,   256,    10,    10,
     256,    10,   256,   254,   237,   240,   299,   256,   252,   253,
     254,    10,   318,    10,   256,   320,   252,   254,   320,   180,
     181,   182,   183,   184,   317,   320,   320,   244,     7,     8,
     323,    10,   320,   243,   206,   211,   210,   208,   222,   299,
     209,   239,   281,   217,   187,   111,   239,   263,   285,   210,
     208,   221,   209,   223,   240,   297,   302,   212,   257,   195,
     207,   254,   234,   235,   236,   237,   205,   330,   208,   209,
     185,   213,     7,   225,   209,   239,   259,   263,   209,   240,
     260,   263,   212,   212,   212,   211,   254,   254,   254,   254,
     254,   254,   254,   299,    16,    17,    18,    19,    20,    21,
      22,    23,    24,   186,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   205,   206,   185,   212,   212,   212,
     185,   212,   212,   212,   212,   212,   212,   212,   212,   212,
     212,   299,   195,   211,   238,   245,   268,   308,   310,   311,
     212,   185,   212,   212,   212,   212,   185,   212,   212,   212,
     212,   212,   212,   212,   212,   205,   212,   212,   212,   243,
      10,   220,   302,   312,   222,   291,   209,   187,   299,   319,
     210,   209,   240,   264,   265,   209,   229,   209,   222,   207,
     207,   212,   185,   273,   165,   325,   326,   250,   256,     7,
     212,   299,   322,   212,   210,   210,   299,   212,   195,   211,
     238,   245,   304,   306,   307,   254,   254,     3,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,     3,   254,   256,    10,   310,
     298,   195,   234,   245,   309,   310,   211,   238,   253,   256,
       7,   212,   219,   185,   302,   210,   221,   222,    25,   237,
     272,   328,   209,   325,   308,   314,   315,   210,   266,   268,
     306,   298,   195,   234,   245,   305,   306,   212,   211,   238,
     187,   207,   310,   298,   212,   310,   212,   234,   212,   222,
     209,   302,   209,     5,   187,   313,   185,   210,   208,   212,
     306,   298,   212,   310,   212,   254,   234,   254,   310,   212,
     222,   210,   257,   314,   246,   310,   212,    40,    53,   209,
     247,   256,   187,   187,   210,   262,   263,   262,   210
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   214,   215,   216,   216,   217,   218,   217,   217,   217,
     217,   217,   217,   217,   217,   219,   219,   220,   219,   219,
     219,   219,   219,   219,   219,   219,   221,   221,   222,   222,
     223,   223,   223,   223,   223,   223,   223,   224,   225,   225,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   227,
     228,   229,   230,   231,   231,   232,   233,   234,   234,   235,
     235,   236,   236,   237,   237,   238,   238,   238,   239,   239,
     240,   241,   241,   241,   242,   242,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   244,   244,   245,   245,
     245,   245,   246,   246,   247,   247,   248,   248,   248,   249,
     249,   250,   250,   251,   252,   252,   253,   253,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   255,
     255,   256,   257,   258,   258,   259,   259,   260,   260,   261,
     261,   262,   262,   263,   263,   264,   265,   265,   266,   266,
     267,   267,   267,   268,   268,   269,   269,   269,   269,   269,
     269,   269,   269,   269,   269,   269,   270,   270,   271,   271,
     271,   271,   271,   271,   271,   271,   271,   272,   273,   272,
     274,   275,   274,   276,   276,   277,   278,   279,   279,   280,
     280,   281,   282,   282,   283,   284,   284,   285,   285,   286,
     286,   287,   287,   288,   288,   289,   290,   290,   290,   291,
     291,   292,   292,   293,   294,   295,   295,   295,   296,   297,
     298,   298,   299,   299,   300,   300,   301,   301,   301,   302,
     302,   302,   303,   303,   303,   303,   304,   304,   304,   305,
     305,   306,   306,   307,   307,   307,   307,   307,   308,   308,
     308,   309,   309,   310,   310,   311,   311,   311,   311,   311,
     311,   312,   312,   313,   313,   314,   315,   315,   316,   316,
     317,   317,   317,   317,   317,   318,   318,   318,   319,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   321,
     322,   322,   323,   323,   323,   324,   324,   325,   325,   326,
     327,   328,   328,   329,   329,   330,   330,   330
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     0,     6,     2,     2,
       3,     2,     2,     2,     2,     0,     2,     0,     6,     2,
       3,     2,     2,     2,     2,     2,     0,     2,     0,     1,
       1,     2,     2,     1,     2,     1,     1,     6,     1,     2,
       1,     2,     1,     2,     1,     2,     2,     2,     2,     4,
       3,     3,     5,     2,     2,     3,     4,     0,     1,     1,
       3,     1,     3,     3,     2,     3,     3,     2,     0,     1,
       3,     1,     3,     4,     1,     3,     0,     1,     4,     1,
       1,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     1,     4,     1,     1,     4,
       1,     4,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     4,     4,     1,     1,     1,     1,
       1,     6,     1,     4,     1,     1,     1,     4,     1,     1,
       1,     4,     4,     4,     4,     1,     1,     4,     4,     4,
       1,     1,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     0,     2,     4,     3,     0,     2,     1,     1,
       3,     3,     1,     5,     1,     3,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     3,     3,     5,     5,     4,     3,     1,
       3,     1,     1,     0,     2,     4,     3,     2,     2,     0,
       2,     2,     1,     3,     2,     1,     3,     2,     0,     1,
       0,     1,     1,     1,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     0,     1,     1,     2,
       1,     2,     2,     1,     1,     1,     1,     1,     0,     4,
       1,     0,     4,     2,     2,     2,     5,     2,     2,     0,
       2,     2,     2,     2,     2,     2,     3,     2,     3,     5,
       5,     0,     2,     2,     2,     2,     6,     8,     2,     2,
       2,     2,     2,     2,     5,     1,     1,     1,     1,     1,
       0,     2,     2,     3,     0,     1,     2,     2,     2,     3,
       2,     1,     1,     3,     2,     4,     3,     2,     1,     3,
       2,     0,     1,     3,     2,     1,     3,     4,     3,     2,
       1,     3,     2,     0,     1,     1,     3,     2,     1,     3,
       4,     1,     3,     0,     2,     2,     1,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     1,
       1,     1,     1,     2,     1,     2,     1,     2,     4,     5,
       5,    10,     1,     3,     1,     0,     2,     0,     2,     4,
       6,     0,     3,     1,     3,     1,     1,     1
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
#line 318 "parser.y"
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
#line 3148 "parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 334 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3154 "parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 335 "parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3160 "parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 336 "parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3166 "parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interfacedec  */
#line 337 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3172 "parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements interfacedef  */
#line 338 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3178 "parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements coclass ';'  */
#line 339 "parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3186 "parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclassdef  */
#line 342 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3194 "parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements moduledef  */
#line 345 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3200 "parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements librarydef  */
#line 346 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3206 "parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements statement  */
#line 347 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3212 "parser.tab.c"
    break;

  case 15: /* imp_statements: %empty  */
#line 350 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3218 "parser.tab.c"
    break;

  case 16: /* imp_statements: imp_statements interfacedec  */
#line 351 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3224 "parser.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 352 "parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3230 "parser.tab.c"
    break;

  case 18: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 353 "parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3236 "parser.tab.c"
    break;

  case 19: /* imp_statements: imp_statements interfacedef  */
#line 354 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3242 "parser.tab.c"
    break;

  case 20: /* imp_statements: imp_statements coclass ';'  */
#line 355 "parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3248 "parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements coclassdef  */
#line 356 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3256 "parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements moduledef  */
#line 359 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3262 "parser.tab.c"
    break;

  case 23: /* imp_statements: imp_statements statement  */
#line 360 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3268 "parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements importlib  */
#line 361 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3274 "parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements librarydef  */
#line 362 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3280 "parser.tab.c"
    break;

  case 26: /* int_statements: %empty  */
#line 365 "parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3286 "parser.tab.c"
    break;

  case 27: /* int_statements: int_statements statement  */
#line 366 "parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3292 "parser.tab.c"
    break;

  case 30: /* statement: cppquote  */
#line 374 "parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3298 "parser.tab.c"
    break;

  case 31: /* statement: typedecl ';'  */
#line 375 "parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3304 "parser.tab.c"
    break;

  case 32: /* statement: declaration ';'  */
#line 376 "parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3310 "parser.tab.c"
    break;

  case 33: /* statement: import  */
#line 377 "parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3316 "parser.tab.c"
    break;

  case 34: /* statement: typedef ';'  */
#line 378 "parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3322 "parser.tab.c"
    break;

  case 35: /* statement: aPRAGMA  */
#line 379 "parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3328 "parser.tab.c"
    break;

  case 36: /* statement: pragma_warning  */
#line 380 "parser.y"
                         { (yyval.statement) = NULL; }
#line 3334 "parser.tab.c"
    break;

  case 37: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 384 "parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3346 "parser.tab.c"
    break;

  case 38: /* warnings: aNUM  */
#line 394 "parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3352 "parser.tab.c"
    break;

  case 39: /* warnings: warnings aNUM  */
#line 395 "parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3358 "parser.tab.c"
    break;

  case 41: /* typedecl: tENUM aIDENTIFIER  */
#line 400 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3364 "parser.tab.c"
    break;

  case 43: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 402 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3370 "parser.tab.c"
    break;

  case 45: /* typedecl: tUNION aIDENTIFIER  */
#line 404 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3376 "parser.tab.c"
    break;

  case 46: /* typedecl: attributes enumdef  */
#line 405 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3382 "parser.tab.c"
    break;

  case 47: /* typedecl: attributes structdef  */
#line 406 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3388 "parser.tab.c"
    break;

  case 48: /* typedecl: attributes uniondef  */
#line 407 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3394 "parser.tab.c"
    break;

  case 49: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 410 "parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3400 "parser.tab.c"
    break;

  case 50: /* import_start: tIMPORT aSTRING ';'  */
#line 412 "parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3411 "parser.tab.c"
    break;

  case 51: /* import: import_start imp_statements aEOF  */
#line 420 "parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3420 "parser.tab.c"
    break;

  case 52: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 427 "parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3426 "parser.tab.c"
    break;

  case 53: /* libraryhdr: tLIBRARY aIDENTIFIER  */
#line 430 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3432 "parser.tab.c"
    break;

  case 54: /* libraryhdr: tLIBRARY aKNOWNTYPE  */
#line 431 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3438 "parser.tab.c"
    break;

  case 55: /* library_start: attributes libraryhdr '{'  */
#line 433 "parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3446 "parser.tab.c"
    break;

  case 56: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 438 "parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3452 "parser.tab.c"
    break;

  case 57: /* m_args: %empty  */
#line 441 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3458 "parser.tab.c"
    break;

  case 59: /* arg_list: arg  */
#line 445 "parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3464 "parser.tab.c"
    break;

  case 60: /* arg_list: arg_list ',' arg  */
#line 446 "parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3470 "parser.tab.c"
    break;

  case 62: /* args: arg_list ',' ELLIPSIS  */
#line 450 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3476 "parser.tab.c"
    break;

  case 63: /* arg: attributes decl_spec m_any_declarator  */
#line 454 "parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3486 "parser.tab.c"
    break;

  case 64: /* arg: decl_spec m_any_declarator  */
#line 459 "parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3496 "parser.tab.c"
    break;

  case 65: /* array: '[' expr ']'  */
#line 466 "parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3505 "parser.tab.c"
    break;

  case 66: /* array: '[' '*' ']'  */
#line 470 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3511 "parser.tab.c"
    break;

  case 67: /* array: '[' ']'  */
#line 471 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3517 "parser.tab.c"
    break;

  case 68: /* m_attributes: %empty  */
#line 474 "parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3523 "parser.tab.c"
    break;

  case 70: /* attributes: '[' attrib_list ']'  */
#line 479 "parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3529 "parser.tab.c"
    break;

  case 71: /* attrib_list: attribute  */
#line 482 "parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3535 "parser.tab.c"
    break;

  case 72: /* attrib_list: attrib_list ',' attribute  */
#line 483 "parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3541 "parser.tab.c"
    break;

  case 73: /* attrib_list: attrib_list ']' '[' attribute  */
#line 484 "parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3547 "parser.tab.c"
    break;

  case 74: /* str_list: aSTRING  */
#line 487 "parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3553 "parser.tab.c"
    break;

  case 75: /* str_list: str_list ',' aSTRING  */
#line 488 "parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3559 "parser.tab.c"
    break;

  case 76: /* attribute: %empty  */
#line 491 "parser.y"
                                                { (yyval.attr) = NULL; }
#line 3565 "parser.tab.c"
    break;

  case 77: /* attribute: tAGGREGATABLE  */
#line 492 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3571 "parser.tab.c"
    break;

  case 78: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 493 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3577 "parser.tab.c"
    break;

  case 79: /* attribute: tAPPOBJECT  */
#line 494 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3583 "parser.tab.c"
    break;

  case 80: /* attribute: tASYNC  */
#line 495 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3589 "parser.tab.c"
    break;

  case 81: /* attribute: tAUTOHANDLE  */
#line 496 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3595 "parser.tab.c"
    break;

  case 82: /* attribute: tBINDABLE  */
#line 497 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3601 "parser.tab.c"
    break;

  case 83: /* attribute: tBROADCAST  */
#line 498 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3607 "parser.tab.c"
    break;

  case 84: /* attribute: tCALLAS '(' ident ')'  */
#line 499 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3613 "parser.tab.c"
    break;

  case 85: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 500 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3619 "parser.tab.c"
    break;

  case 86: /* attribute: tCODE  */
#line 501 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3625 "parser.tab.c"
    break;

  case 87: /* attribute: tCOMMSTATUS  */
#line 502 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3631 "parser.tab.c"
    break;

  case 88: /* attribute: tCONTEXTHANDLE  */
#line 503 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3637 "parser.tab.c"
    break;

  case 89: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 504 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3643 "parser.tab.c"
    break;

  case 90: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 505 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3649 "parser.tab.c"
    break;

  case 91: /* attribute: tCONTROL  */
#line 506 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3655 "parser.tab.c"
    break;

  case 92: /* attribute: tDECODE  */
#line 507 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3661 "parser.tab.c"
    break;

  case 93: /* attribute: tDEFAULT  */
#line 508 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3667 "parser.tab.c"
    break;

  case 94: /* attribute: tDEFAULTBIND  */
#line 509 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3673 "parser.tab.c"
    break;

  case 95: /* attribute: tDEFAULTCOLLELEM  */
#line 510 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3679 "parser.tab.c"
    break;

  case 96: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 511 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3685 "parser.tab.c"
    break;

  case 97: /* attribute: tDEFAULTVTABLE  */
#line 512 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3691 "parser.tab.c"
    break;

  case 98: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 513 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3697 "parser.tab.c"
    break;

  case 99: /* attribute: tDISPLAYBIND  */
#line 514 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3703 "parser.tab.c"
    break;

  case 100: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 515 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3709 "parser.tab.c"
    break;

  case 101: /* attribute: tDUAL  */
#line 516 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3715 "parser.tab.c"
    break;

  case 102: /* attribute: tENABLEALLOCATE  */
#line 517 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3721 "parser.tab.c"
    break;

  case 103: /* attribute: tENCODE  */
#line 518 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3727 "parser.tab.c"
    break;

  case 104: /* attribute: tENDPOINT '(' str_list ')'  */
#line 519 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3733 "parser.tab.c"
    break;

  case 105: /* attribute: tENTRY '(' expr_const ')'  */
#line 520 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3739 "parser.tab.c"
    break;

  case 106: /* attribute: tEXPLICITHANDLE  */
#line 521 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3745 "parser.tab.c"
    break;

  case 107: /* attribute: tFAULTSTATUS  */
#line 522 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3751 "parser.tab.c"
    break;

  case 108: /* attribute: tFORCEALLOCATE  */
#line 523 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3757 "parser.tab.c"
    break;

  case 109: /* attribute: tHANDLE  */
#line 524 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3763 "parser.tab.c"
    break;

  case 110: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 525 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3769 "parser.tab.c"
    break;

  case 111: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 526 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3775 "parser.tab.c"
    break;

  case 112: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 527 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3781 "parser.tab.c"
    break;

  case 113: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 528 "parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3787 "parser.tab.c"
    break;

  case 114: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 529 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3793 "parser.tab.c"
    break;

  case 115: /* attribute: tHIDDEN  */
#line 530 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3799 "parser.tab.c"
    break;

  case 116: /* attribute: tID '(' expr_int_const ')'  */
#line 531 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3805 "parser.tab.c"
    break;

  case 117: /* attribute: tIDEMPOTENT  */
#line 532 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3811 "parser.tab.c"
    break;

  case 118: /* attribute: tIGNORE  */
#line 533 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3817 "parser.tab.c"
    break;

  case 119: /* attribute: tIIDIS '(' expr ')'  */
#line 534 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3823 "parser.tab.c"
    break;

  case 120: /* attribute: tIMMEDIATEBIND  */
#line 535 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3829 "parser.tab.c"
    break;

  case 121: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 536 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3835 "parser.tab.c"
    break;

  case 122: /* attribute: tIN  */
#line 537 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 3841 "parser.tab.c"
    break;

  case 123: /* attribute: tINPUTSYNC  */
#line 538 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3847 "parser.tab.c"
    break;

  case 124: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 539 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3853 "parser.tab.c"
    break;

  case 125: /* attribute: tLCID '(' expr_int_const ')'  */
#line 540 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3859 "parser.tab.c"
    break;

  case 126: /* attribute: tLCID  */
#line 541 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3865 "parser.tab.c"
    break;

  case 127: /* attribute: tLICENSED  */
#line 542 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3871 "parser.tab.c"
    break;

  case 128: /* attribute: tLOCAL  */
#line 543 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3877 "parser.tab.c"
    break;

  case 129: /* attribute: tMAYBE  */
#line 544 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3883 "parser.tab.c"
    break;

  case 130: /* attribute: tMESSAGE  */
#line 545 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3889 "parser.tab.c"
    break;

  case 131: /* attribute: tNOCODE  */
#line 546 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3895 "parser.tab.c"
    break;

  case 132: /* attribute: tNONBROWSABLE  */
#line 547 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3901 "parser.tab.c"
    break;

  case 133: /* attribute: tNONCREATABLE  */
#line 548 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3907 "parser.tab.c"
    break;

  case 134: /* attribute: tNONEXTENSIBLE  */
#line 549 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3913 "parser.tab.c"
    break;

  case 135: /* attribute: tNOTIFY  */
#line 550 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3919 "parser.tab.c"
    break;

  case 136: /* attribute: tNOTIFYFLAG  */
#line 551 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3925 "parser.tab.c"
    break;

  case 137: /* attribute: tOBJECT  */
#line 552 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3931 "parser.tab.c"
    break;

  case 138: /* attribute: tODL  */
#line 553 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3937 "parser.tab.c"
    break;

  case 139: /* attribute: tOLEAUTOMATION  */
#line 554 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3943 "parser.tab.c"
    break;

  case 140: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 555 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3949 "parser.tab.c"
    break;

  case 141: /* attribute: tOPTIONAL  */
#line 556 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3955 "parser.tab.c"
    break;

  case 142: /* attribute: tOUT  */
#line 557 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3961 "parser.tab.c"
    break;

  case 143: /* attribute: tPARTIALIGNORE  */
#line 558 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3967 "parser.tab.c"
    break;

  case 144: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 559 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3973 "parser.tab.c"
    break;

  case 145: /* attribute: tPROGID '(' aSTRING ')'  */
#line 560 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3979 "parser.tab.c"
    break;

  case 146: /* attribute: tPROPGET  */
#line 561 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3985 "parser.tab.c"
    break;

  case 147: /* attribute: tPROPPUT  */
#line 562 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3991 "parser.tab.c"
    break;

  case 148: /* attribute: tPROPPUTREF  */
#line 563 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3997 "parser.tab.c"
    break;

  case 149: /* attribute: tPROXY  */
#line 564 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4003 "parser.tab.c"
    break;

  case 150: /* attribute: tPUBLIC  */
#line 565 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4009 "parser.tab.c"
    break;

  case 151: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 567 "parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4017 "parser.tab.c"
    break;

  case 152: /* attribute: tREADONLY  */
#line 570 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4023 "parser.tab.c"
    break;

  case 153: /* attribute: tREPRESENTAS '(' type ')'  */
#line 571 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4029 "parser.tab.c"
    break;

  case 154: /* attribute: tREQUESTEDIT  */
#line 572 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4035 "parser.tab.c"
    break;

  case 155: /* attribute: tRESTRICTED  */
#line 573 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4041 "parser.tab.c"
    break;

  case 156: /* attribute: tRETVAL  */
#line 574 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4047 "parser.tab.c"
    break;

  case 157: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 575 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4053 "parser.tab.c"
    break;

  case 158: /* attribute: tSOURCE  */
#line 576 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4059 "parser.tab.c"
    break;

  case 159: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 577 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4065 "parser.tab.c"
    break;

  case 160: /* attribute: tSTRING  */
#line 578 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4071 "parser.tab.c"
    break;

  case 161: /* attribute: tSWITCHIS '(' expr ')'  */
#line 579 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4077 "parser.tab.c"
    break;

  case 162: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 580 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4083 "parser.tab.c"
    break;

  case 163: /* attribute: tTRANSMITAS '(' type ')'  */
#line 581 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4089 "parser.tab.c"
    break;

  case 164: /* attribute: tTHREADING '(' threading_type ')'  */
#line 582 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4095 "parser.tab.c"
    break;

  case 165: /* attribute: tUIDEFAULT  */
#line 583 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4101 "parser.tab.c"
    break;

  case 166: /* attribute: tUSESGETLASTERROR  */
#line 584 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4107 "parser.tab.c"
    break;

  case 167: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 585 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4113 "parser.tab.c"
    break;

  case 168: /* attribute: tUUID '(' uuid_string ')'  */
#line 586 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4119 "parser.tab.c"
    break;

  case 169: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 587 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4125 "parser.tab.c"
    break;

  case 170: /* attribute: tV1ENUM  */
#line 588 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4131 "parser.tab.c"
    break;

  case 171: /* attribute: tVARARG  */
#line 589 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4137 "parser.tab.c"
    break;

  case 172: /* attribute: tVERSION '(' version ')'  */
#line 590 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4143 "parser.tab.c"
    break;

  case 173: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 591 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4149 "parser.tab.c"
    break;

  case 174: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 592 "parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4155 "parser.tab.c"
    break;

  case 175: /* attribute: pointer_type  */
#line 593 "parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4161 "parser.tab.c"
    break;

  case 177: /* uuid_string: aSTRING  */
#line 598 "parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4169 "parser.tab.c"
    break;

  case 178: /* callconv: tCDECL  */
#line 603 "parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4175 "parser.tab.c"
    break;

  case 179: /* callconv: tFASTCALL  */
#line 604 "parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4181 "parser.tab.c"
    break;

  case 180: /* callconv: tPASCAL  */
#line 605 "parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4187 "parser.tab.c"
    break;

  case 181: /* callconv: tSTDCALL  */
#line 606 "parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4193 "parser.tab.c"
    break;

  case 182: /* cases: %empty  */
#line 609 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4199 "parser.tab.c"
    break;

  case 183: /* cases: cases case  */
#line 610 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4205 "parser.tab.c"
    break;

  case 184: /* case: tCASE expr_int_const ':' union_field  */
#line 613 "parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4214 "parser.tab.c"
    break;

  case 185: /* case: tDEFAULT ':' union_field  */
#line 617 "parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4223 "parser.tab.c"
    break;

  case 186: /* enums: %empty  */
#line 623 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4229 "parser.tab.c"
    break;

  case 187: /* enums: enum_list ','  */
#line 624 "parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4235 "parser.tab.c"
    break;

  case 189: /* enum_list: enum  */
#line 628 "parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4244 "parser.tab.c"
    break;

  case 190: /* enum_list: enum_list ',' enum  */
#line 632 "parser.y"
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
#line 4259 "parser.tab.c"
    break;

  case 191: /* enum: ident '=' expr_int_const  */
#line 644 "parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4268 "parser.tab.c"
    break;

  case 192: /* enum: ident  */
#line 648 "parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4276 "parser.tab.c"
    break;

  case 193: /* enumdef: tENUM t_ident '{' enums '}'  */
#line 653 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4282 "parser.tab.c"
    break;

  case 194: /* m_exprs: m_expr  */
#line 656 "parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4288 "parser.tab.c"
    break;

  case 195: /* m_exprs: m_exprs ',' m_expr  */
#line 657 "parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4294 "parser.tab.c"
    break;

  case 196: /* m_expr: %empty  */
#line 660 "parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4300 "parser.tab.c"
    break;

  case 198: /* expr: aNUM  */
#line 664 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4306 "parser.tab.c"
    break;

  case 199: /* expr: aHEXNUM  */
#line 665 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4312 "parser.tab.c"
    break;

  case 200: /* expr: aDOUBLE  */
#line 666 "parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4318 "parser.tab.c"
    break;

  case 201: /* expr: tFALSE  */
#line 667 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4324 "parser.tab.c"
    break;

  case 202: /* expr: tNULL  */
#line 668 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4330 "parser.tab.c"
    break;

  case 203: /* expr: tTRUE  */
#line 669 "parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4336 "parser.tab.c"
    break;

  case 204: /* expr: aSTRING  */
#line 670 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4342 "parser.tab.c"
    break;

  case 205: /* expr: aWSTRING  */
#line 671 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4348 "parser.tab.c"
    break;

  case 206: /* expr: aSQSTRING  */
#line 672 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4354 "parser.tab.c"
    break;

  case 207: /* expr: aIDENTIFIER  */
#line 673 "parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4360 "parser.tab.c"
    break;

  case 208: /* expr: expr '?' expr ':' expr  */
#line 674 "parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4366 "parser.tab.c"
    break;

  case 209: /* expr: expr LOGICALOR expr  */
#line 675 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4372 "parser.tab.c"
    break;

  case 210: /* expr: expr LOGICALAND expr  */
#line 676 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4378 "parser.tab.c"
    break;

  case 211: /* expr: expr '|' expr  */
#line 677 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4384 "parser.tab.c"
    break;

  case 212: /* expr: expr '^' expr  */
#line 678 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4390 "parser.tab.c"
    break;

  case 213: /* expr: expr '&' expr  */
#line 679 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4396 "parser.tab.c"
    break;

  case 214: /* expr: expr EQUALITY expr  */
#line 680 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4402 "parser.tab.c"
    break;

  case 215: /* expr: expr INEQUALITY expr  */
#line 681 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4408 "parser.tab.c"
    break;

  case 216: /* expr: expr '>' expr  */
#line 682 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4414 "parser.tab.c"
    break;

  case 217: /* expr: expr '<' expr  */
#line 683 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4420 "parser.tab.c"
    break;

  case 218: /* expr: expr GREATEREQUAL expr  */
#line 684 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4426 "parser.tab.c"
    break;

  case 219: /* expr: expr LESSEQUAL expr  */
#line 685 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4432 "parser.tab.c"
    break;

  case 220: /* expr: expr SHL expr  */
#line 686 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4438 "parser.tab.c"
    break;

  case 221: /* expr: expr SHR expr  */
#line 687 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4444 "parser.tab.c"
    break;

  case 222: /* expr: expr '+' expr  */
#line 688 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4450 "parser.tab.c"
    break;

  case 223: /* expr: expr '-' expr  */
#line 689 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4456 "parser.tab.c"
    break;

  case 224: /* expr: expr '%' expr  */
#line 690 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4462 "parser.tab.c"
    break;

  case 225: /* expr: expr '*' expr  */
#line 691 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4468 "parser.tab.c"
    break;

  case 226: /* expr: expr '/' expr  */
#line 692 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4474 "parser.tab.c"
    break;

  case 227: /* expr: '!' expr  */
#line 693 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4480 "parser.tab.c"
    break;

  case 228: /* expr: '~' expr  */
#line 694 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4486 "parser.tab.c"
    break;

  case 229: /* expr: '+' expr  */
#line 695 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4492 "parser.tab.c"
    break;

  case 230: /* expr: '-' expr  */
#line 696 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4498 "parser.tab.c"
    break;

  case 231: /* expr: '&' expr  */
#line 697 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4504 "parser.tab.c"
    break;

  case 232: /* expr: '*' expr  */
#line 698 "parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4510 "parser.tab.c"
    break;

  case 233: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 699 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4516 "parser.tab.c"
    break;

  case 234: /* expr: expr '.' aIDENTIFIER  */
#line 700 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4522 "parser.tab.c"
    break;

  case 235: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 702 "parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4528 "parser.tab.c"
    break;

  case 236: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 704 "parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4534 "parser.tab.c"
    break;

  case 237: /* expr: expr '[' expr ']'  */
#line 705 "parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4540 "parser.tab.c"
    break;

  case 238: /* expr: '(' expr ')'  */
#line 706 "parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4546 "parser.tab.c"
    break;

  case 239: /* expr_list_int_const: expr_int_const  */
#line 709 "parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4552 "parser.tab.c"
    break;

  case 240: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 710 "parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4558 "parser.tab.c"
    break;

  case 241: /* expr_int_const: expr  */
#line 713 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4567 "parser.tab.c"
    break;

  case 242: /* expr_const: expr  */
#line 719 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4576 "parser.tab.c"
    break;

  case 243: /* fields: %empty  */
#line 725 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4582 "parser.tab.c"
    break;

  case 244: /* fields: fields field  */
#line 726 "parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4588 "parser.tab.c"
    break;

  case 245: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 730 "parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4597 "parser.tab.c"
    break;

  case 246: /* field: m_attributes uniondef ';'  */
#line 734 "parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4606 "parser.tab.c"
    break;

  case 247: /* ne_union_field: s_field ';'  */
#line 741 "parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4612 "parser.tab.c"
    break;

  case 248: /* ne_union_field: attributes ';'  */
#line 742 "parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4618 "parser.tab.c"
    break;

  case 249: /* ne_union_fields: %empty  */
#line 745 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4624 "parser.tab.c"
    break;

  case 250: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 746 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4630 "parser.tab.c"
    break;

  case 251: /* union_field: s_field ';'  */
#line 750 "parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4636 "parser.tab.c"
    break;

  case 252: /* union_field: ';'  */
#line 751 "parser.y"
                                                { (yyval.var) = NULL; }
#line 4642 "parser.tab.c"
    break;

  case 253: /* s_field: m_attributes decl_spec declarator  */
#line 754 "parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4651 "parser.tab.c"
    break;

  case 254: /* s_field: m_attributes structdef  */
#line 758 "parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4660 "parser.tab.c"
    break;

  case 255: /* funcdef: declaration  */
#line 764 "parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4670 "parser.tab.c"
    break;

  case 256: /* declaration: attributes decl_spec init_declarator  */
#line 773 "parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4678 "parser.tab.c"
    break;

  case 257: /* declaration: decl_spec init_declarator  */
#line 776 "parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4686 "parser.tab.c"
    break;

  case 258: /* m_ident: %empty  */
#line 781 "parser.y"
                                                { (yyval.var) = NULL; }
#line 4692 "parser.tab.c"
    break;

  case 260: /* t_ident: %empty  */
#line 785 "parser.y"
                                                { (yyval.str) = NULL; }
#line 4698 "parser.tab.c"
    break;

  case 261: /* t_ident: aIDENTIFIER  */
#line 786 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4704 "parser.tab.c"
    break;

  case 262: /* t_ident: aKNOWNTYPE  */
#line 787 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4710 "parser.tab.c"
    break;

  case 263: /* ident: aIDENTIFIER  */
#line 790 "parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4716 "parser.tab.c"
    break;

  case 264: /* ident: aKNOWNTYPE  */
#line 792 "parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4722 "parser.tab.c"
    break;

  case 265: /* base_type: tBYTE  */
#line 795 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4728 "parser.tab.c"
    break;

  case 266: /* base_type: tWCHAR  */
#line 796 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4734 "parser.tab.c"
    break;

  case 268: /* base_type: tSIGNED int_std  */
#line 798 "parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4740 "parser.tab.c"
    break;

  case 269: /* base_type: tUNSIGNED int_std  */
#line 799 "parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4746 "parser.tab.c"
    break;

  case 270: /* base_type: tUNSIGNED  */
#line 800 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4752 "parser.tab.c"
    break;

  case 271: /* base_type: tFLOAT  */
#line 801 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4758 "parser.tab.c"
    break;

  case 272: /* base_type: tDOUBLE  */
#line 802 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4764 "parser.tab.c"
    break;

  case 273: /* base_type: tBOOLEAN  */
#line 803 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4770 "parser.tab.c"
    break;

  case 274: /* base_type: tERRORSTATUST  */
#line 804 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4776 "parser.tab.c"
    break;

  case 275: /* base_type: tHANDLET  */
#line 805 "parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4782 "parser.tab.c"
    break;

  case 278: /* int_std: tINT  */
#line 812 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4788 "parser.tab.c"
    break;

  case 279: /* int_std: tSHORT m_int  */
#line 813 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4794 "parser.tab.c"
    break;

  case 280: /* int_std: tSMALL  */
#line 814 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4800 "parser.tab.c"
    break;

  case 281: /* int_std: tLONG m_int  */
#line 815 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4806 "parser.tab.c"
    break;

  case 282: /* int_std: tHYPER m_int  */
#line 816 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4812 "parser.tab.c"
    break;

  case 283: /* int_std: tINT64  */
#line 817 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4818 "parser.tab.c"
    break;

  case 284: /* int_std: tCHAR  */
#line 818 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4824 "parser.tab.c"
    break;

  case 285: /* int_std: tINT32  */
#line 819 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4830 "parser.tab.c"
    break;

  case 286: /* int_std: tINT3264  */
#line 820 "parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4836 "parser.tab.c"
    break;

  case 287: /* qualified_seq: aKNOWNTYPE  */
#line 824 "parser.y"
                      { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4842 "parser.tab.c"
    break;

  case 288: /* $@3: %empty  */
#line 825 "parser.y"
                      { push_lookup_namespace((yyvsp[-1].str)); }
#line 4848 "parser.tab.c"
    break;

  case 289: /* qualified_seq: aIDENTIFIER '.' $@3 qualified_seq  */
#line 825 "parser.y"
                                                                   { (yyval.type) = (yyvsp[0].type); }
#line 4854 "parser.tab.c"
    break;

  case 290: /* qualified_type: aKNOWNTYPE  */
#line 829 "parser.y"
                     { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4860 "parser.tab.c"
    break;

  case 291: /* $@4: %empty  */
#line 830 "parser.y"
                     { init_lookup_namespace((yyvsp[-1].str)); }
#line 4866 "parser.tab.c"
    break;

  case 292: /* qualified_type: aNAMESPACE '.' $@4 qualified_seq  */
#line 830 "parser.y"
                                                                  { (yyval.type) = (yyvsp[0].type); }
#line 4872 "parser.tab.c"
    break;

  case 293: /* coclass: tCOCLASS aIDENTIFIER  */
#line 833 "parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4878 "parser.tab.c"
    break;

  case 294: /* coclass: tCOCLASS aKNOWNTYPE  */
#line 834 "parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4889 "parser.tab.c"
    break;

  case 295: /* coclasshdr: attributes coclass  */
#line 842 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4898 "parser.tab.c"
    break;

  case 296: /* coclassdef: coclasshdr '{' coclass_ints '}' semicolon_opt  */
#line 849 "parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4904 "parser.tab.c"
    break;

  case 297: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 852 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4910 "parser.tab.c"
    break;

  case 298: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 853 "parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4916 "parser.tab.c"
    break;

  case 299: /* coclass_ints: %empty  */
#line 856 "parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 4922 "parser.tab.c"
    break;

  case 300: /* coclass_ints: coclass_ints coclass_int  */
#line 857 "parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4928 "parser.tab.c"
    break;

  case 301: /* coclass_int: m_attributes interfacedec  */
#line 861 "parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4934 "parser.tab.c"
    break;

  case 302: /* dispinterface: tDISPINTERFACE aIDENTIFIER  */
#line 864 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4940 "parser.tab.c"
    break;

  case 303: /* dispinterface: tDISPINTERFACE aKNOWNTYPE  */
#line 865 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4946 "parser.tab.c"
    break;

  case 304: /* dispinterfacehdr: attributes dispinterface  */
#line 868 "parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4958 "parser.tab.c"
    break;

  case 305: /* dispint_props: tPROPERTIES ':'  */
#line 877 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4964 "parser.tab.c"
    break;

  case 306: /* dispint_props: dispint_props s_field ';'  */
#line 878 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4970 "parser.tab.c"
    break;

  case 307: /* dispint_meths: tMETHODS ':'  */
#line 881 "parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4976 "parser.tab.c"
    break;

  case 308: /* dispint_meths: dispint_meths funcdef ';'  */
#line 882 "parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4982 "parser.tab.c"
    break;

  case 309: /* dispinterfacedef: dispinterfacehdr '{' dispint_props dispint_meths '}'  */
#line 888 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4990 "parser.tab.c"
    break;

  case 310: /* dispinterfacedef: dispinterfacehdr '{' interface ';' '}'  */
#line 892 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4998 "parser.tab.c"
    break;

  case 311: /* inherit: %empty  */
#line 897 "parser.y"
                                                { (yyval.type) = NULL; }
#line 5004 "parser.tab.c"
    break;

  case 312: /* inherit: ':' qualified_type  */
#line 898 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5010 "parser.tab.c"
    break;

  case 313: /* interface: tINTERFACE aIDENTIFIER  */
#line 901 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5016 "parser.tab.c"
    break;

  case 314: /* interface: tINTERFACE aKNOWNTYPE  */
#line 902 "parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5022 "parser.tab.c"
    break;

  case 315: /* interfacehdr: attributes interface  */
#line 905 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 5032 "parser.tab.c"
    break;

  case 316: /* interfacedef: interfacehdr inherit '{' int_statements '}' semicolon_opt  */
#line 913 "parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5043 "parser.tab.c"
    break;

  case 317: /* interfacedef: interfacehdr ':' aIDENTIFIER '{' import int_statements '}' semicolon_opt  */
#line 923 "parser.y"
                                                { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 5051 "parser.tab.c"
    break;

  case 318: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 926 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5057 "parser.tab.c"
    break;

  case 319: /* interfacedec: interface ';'  */
#line 930 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5063 "parser.tab.c"
    break;

  case 320: /* interfacedec: dispinterface ';'  */
#line 931 "parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5069 "parser.tab.c"
    break;

  case 321: /* module: tMODULE aIDENTIFIER  */
#line 934 "parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5075 "parser.tab.c"
    break;

  case 322: /* module: tMODULE aKNOWNTYPE  */
#line 935 "parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5081 "parser.tab.c"
    break;

  case 323: /* modulehdr: attributes module  */
#line 938 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5089 "parser.tab.c"
    break;

  case 324: /* moduledef: modulehdr '{' int_statements '}' semicolon_opt  */
#line 944 "parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5097 "parser.tab.c"
    break;

  case 325: /* storage_cls_spec: tEXTERN  */
#line 950 "parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5103 "parser.tab.c"
    break;

  case 326: /* storage_cls_spec: tSTATIC  */
#line 951 "parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5109 "parser.tab.c"
    break;

  case 327: /* storage_cls_spec: tREGISTER  */
#line 952 "parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5115 "parser.tab.c"
    break;

  case 328: /* function_specifier: tINLINE  */
#line 956 "parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5121 "parser.tab.c"
    break;

  case 329: /* type_qualifier: tCONST  */
#line 960 "parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5127 "parser.tab.c"
    break;

  case 330: /* m_type_qual_list: %empty  */
#line 963 "parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5133 "parser.tab.c"
    break;

  case 331: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 964 "parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5139 "parser.tab.c"
    break;

  case 332: /* decl_spec: type m_decl_spec_no_type  */
#line 967 "parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5145 "parser.tab.c"
    break;

  case 333: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 969 "parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5151 "parser.tab.c"
    break;

  case 334: /* m_decl_spec_no_type: %empty  */
#line 972 "parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5157 "parser.tab.c"
    break;

  case 336: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 977 "parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5163 "parser.tab.c"
    break;

  case 337: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 978 "parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5169 "parser.tab.c"
    break;

  case 338: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 979 "parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5175 "parser.tab.c"
    break;

  case 339: /* declarator: '*' m_type_qual_list declarator  */
#line 984 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5181 "parser.tab.c"
    break;

  case 340: /* declarator: callconv declarator  */
#line 985 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5187 "parser.tab.c"
    break;

  case 342: /* direct_declarator: ident  */
#line 990 "parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5193 "parser.tab.c"
    break;

  case 343: /* direct_declarator: '(' declarator ')'  */
#line 991 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5199 "parser.tab.c"
    break;

  case 344: /* direct_declarator: direct_declarator array  */
#line 992 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5205 "parser.tab.c"
    break;

  case 345: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 993 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5211 "parser.tab.c"
    break;

  case 346: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 999 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5217 "parser.tab.c"
    break;

  case 347: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1000 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5223 "parser.tab.c"
    break;

  case 349: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1007 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5229 "parser.tab.c"
    break;

  case 350: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1008 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5235 "parser.tab.c"
    break;

  case 351: /* m_abstract_declarator: %empty  */
#line 1012 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5241 "parser.tab.c"
    break;

  case 353: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1018 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5247 "parser.tab.c"
    break;

  case 354: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1019 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5253 "parser.tab.c"
    break;

  case 355: /* abstract_direct_declarator: array  */
#line 1020 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5259 "parser.tab.c"
    break;

  case 356: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1022 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5267 "parser.tab.c"
    break;

  case 357: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1026 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5275 "parser.tab.c"
    break;

  case 358: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1034 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5281 "parser.tab.c"
    break;

  case 359: /* any_declarator: callconv m_any_declarator  */
#line 1035 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5287 "parser.tab.c"
    break;

  case 361: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1042 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5293 "parser.tab.c"
    break;

  case 362: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1043 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5299 "parser.tab.c"
    break;

  case 363: /* m_any_declarator: %empty  */
#line 1047 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5305 "parser.tab.c"
    break;

  case 365: /* any_direct_declarator: ident  */
#line 1055 "parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5311 "parser.tab.c"
    break;

  case 366: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1056 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5317 "parser.tab.c"
    break;

  case 367: /* any_direct_declarator: any_direct_declarator array  */
#line 1057 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5323 "parser.tab.c"
    break;

  case 368: /* any_direct_declarator: array  */
#line 1058 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5329 "parser.tab.c"
    break;

  case 369: /* any_direct_declarator: '(' m_args ')'  */
#line 1060 "parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5337 "parser.tab.c"
    break;

  case 370: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1064 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5345 "parser.tab.c"
    break;

  case 371: /* declarator_list: declarator  */
#line 1070 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5351 "parser.tab.c"
    break;

  case 372: /* declarator_list: declarator_list ',' declarator  */
#line 1071 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5357 "parser.tab.c"
    break;

  case 373: /* m_bitfield: %empty  */
#line 1074 "parser.y"
                                                { (yyval.expr) = NULL; }
#line 5363 "parser.tab.c"
    break;

  case 374: /* m_bitfield: ':' expr_const  */
#line 1075 "parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5369 "parser.tab.c"
    break;

  case 375: /* struct_declarator: any_declarator m_bitfield  */
#line 1078 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5378 "parser.tab.c"
    break;

  case 376: /* struct_declarator_list: struct_declarator  */
#line 1085 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5384 "parser.tab.c"
    break;

  case 377: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1087 "parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5390 "parser.tab.c"
    break;

  case 378: /* init_declarator: declarator  */
#line 1091 "parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5396 "parser.tab.c"
    break;

  case 379: /* init_declarator: declarator '=' expr_const  */
#line 1092 "parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5402 "parser.tab.c"
    break;

  case 380: /* threading_type: tAPARTMENT  */
#line 1096 "parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5408 "parser.tab.c"
    break;

  case 381: /* threading_type: tNEUTRAL  */
#line 1097 "parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5414 "parser.tab.c"
    break;

  case 382: /* threading_type: tSINGLE  */
#line 1098 "parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5420 "parser.tab.c"
    break;

  case 383: /* threading_type: tFREE  */
#line 1099 "parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5426 "parser.tab.c"
    break;

  case 384: /* threading_type: tBOTH  */
#line 1100 "parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5432 "parser.tab.c"
    break;

  case 385: /* pointer_type: tREF  */
#line 1104 "parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5438 "parser.tab.c"
    break;

  case 386: /* pointer_type: tUNIQUE  */
#line 1105 "parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5444 "parser.tab.c"
    break;

  case 387: /* pointer_type: tPTR  */
#line 1106 "parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5450 "parser.tab.c"
    break;

  case 388: /* structdef: tSTRUCT t_ident '{' fields '}'  */
#line 1109 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5456 "parser.tab.c"
    break;

  case 389: /* type: tVOID  */
#line 1112 "parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5462 "parser.tab.c"
    break;

  case 390: /* type: qualified_type  */
#line 1113 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5468 "parser.tab.c"
    break;

  case 391: /* type: base_type  */
#line 1114 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5474 "parser.tab.c"
    break;

  case 392: /* type: enumdef  */
#line 1115 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5480 "parser.tab.c"
    break;

  case 393: /* type: tENUM aIDENTIFIER  */
#line 1116 "parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5486 "parser.tab.c"
    break;

  case 394: /* type: structdef  */
#line 1117 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5492 "parser.tab.c"
    break;

  case 395: /* type: tSTRUCT aIDENTIFIER  */
#line 1118 "parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5498 "parser.tab.c"
    break;

  case 396: /* type: uniondef  */
#line 1119 "parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5504 "parser.tab.c"
    break;

  case 397: /* type: tUNION aIDENTIFIER  */
#line 1120 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5510 "parser.tab.c"
    break;

  case 398: /* type: tSAFEARRAY '(' type ')'  */
#line 1121 "parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5516 "parser.tab.c"
    break;

  case 399: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1125 "parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5525 "parser.tab.c"
    break;

  case 400: /* uniondef: tUNION t_ident '{' ne_union_fields '}'  */
#line 1132 "parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5531 "parser.tab.c"
    break;

  case 401: /* uniondef: tUNION t_ident tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1135 "parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5537 "parser.tab.c"
    break;

  case 402: /* version: aNUM  */
#line 1139 "parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5543 "parser.tab.c"
    break;

  case 403: /* version: aNUM '.' aNUM  */
#line 1140 "parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5549 "parser.tab.c"
    break;

  case 404: /* version: aHEXNUM  */
#line 1141 "parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5555 "parser.tab.c"
    break;

  case 409: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1154 "parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5563 "parser.tab.c"
    break;

  case 410: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1159 "parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5573 "parser.tab.c"
    break;

  case 411: /* acf_attributes: %empty  */
#line 1166 "parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5579 "parser.tab.c"
    break;

  case 412: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1167 "parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5585 "parser.tab.c"
    break;

  case 413: /* acf_attribute_list: acf_attribute  */
#line 1170 "parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5591 "parser.tab.c"
    break;

  case 414: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1171 "parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5597 "parser.tab.c"
    break;

  case 415: /* acf_attribute: tENCODE  */
#line 1174 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5603 "parser.tab.c"
    break;

  case 416: /* acf_attribute: tDECODE  */
#line 1175 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5609 "parser.tab.c"
    break;

  case 417: /* acf_attribute: tEXPLICITHANDLE  */
#line 1176 "parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5615 "parser.tab.c"
    break;


#line 5619 "parser.tab.c"

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

#line 1178 "parser.y"


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

static attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
{
    attr_t *attr_existing;
    if (!attr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    LIST_FOR_EACH_ENTRY(attr_existing, list, attr_t, entry)
        if (attr_existing->type == attr->type)
        {
            parser_warning("duplicate attribute %s\n", get_attr_display_name(attr->type));
            /* use the last attribute, like MIDL does */
            list_remove(&attr_existing->entry);
            break;
        }
    list_add_tail( list, &attr->entry );
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
    type->c_name = format_namespace(namespace, "__x_", "_C", name);
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
    unsigned int on_interface : 1;
    unsigned int on_function : 1;
    unsigned int on_arg : 1;
    unsigned int on_type : 1;
    unsigned int on_enum : 1;
    unsigned int on_struct : 2;
    unsigned int on_union : 1;
    unsigned int on_field : 1;
    unsigned int on_library : 1;
    unsigned int on_dispinterface : 1;
    unsigned int on_module : 1;
    unsigned int on_coclass : 1;
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF I Fn ARG T En St Un Fi  L  DI M  C  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "aggregatable" },
    /* ATTR_ANNOTATION */          { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTROL */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, "control" },
    /* ATTR_DECODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MAYBE */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 1, 0, 0, 1, 1, 2, 0, 0, 1, 0, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

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
        return FALSE;
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
