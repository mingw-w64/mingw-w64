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


#line 211 "tools/widl/parser.tab.c"

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
#line 133 "tools/widl/parser.y"

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

#line 476 "tools/widl/parser.tab.c"

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
  YYSYMBOL_enum_member = 250,              /* enum_member  */
  YYSYMBOL_enum = 251,                     /* enum  */
  YYSYMBOL_enumdef = 252,                  /* enumdef  */
  YYSYMBOL_m_exprs = 253,                  /* m_exprs  */
  YYSYMBOL_m_expr = 254,                   /* m_expr  */
  YYSYMBOL_expr = 255,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 256,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 257,           /* expr_int_const  */
  YYSYMBOL_expr_const = 258,               /* expr_const  */
  YYSYMBOL_fields = 259,                   /* fields  */
  YYSYMBOL_field = 260,                    /* field  */
  YYSYMBOL_ne_union_field = 261,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 262,          /* ne_union_fields  */
  YYSYMBOL_union_field = 263,              /* union_field  */
  YYSYMBOL_s_field = 264,                  /* s_field  */
  YYSYMBOL_funcdef = 265,                  /* funcdef  */
  YYSYMBOL_declaration = 266,              /* declaration  */
  YYSYMBOL_m_ident = 267,                  /* m_ident  */
  YYSYMBOL_t_ident = 268,                  /* t_ident  */
  YYSYMBOL_ident = 269,                    /* ident  */
  YYSYMBOL_base_type = 270,                /* base_type  */
  YYSYMBOL_m_int = 271,                    /* m_int  */
  YYSYMBOL_int_std = 272,                  /* int_std  */
  YYSYMBOL_qualified_seq = 273,            /* qualified_seq  */
  YYSYMBOL_274_3 = 274,                    /* $@3  */
  YYSYMBOL_qualified_type = 275,           /* qualified_type  */
  YYSYMBOL_276_4 = 276,                    /* $@4  */
  YYSYMBOL_coclass = 277,                  /* coclass  */
  YYSYMBOL_coclasshdr = 278,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 279,               /* coclassdef  */
  YYSYMBOL_namespacedef = 280,             /* namespacedef  */
  YYSYMBOL_coclass_ints = 281,             /* coclass_ints  */
  YYSYMBOL_coclass_int = 282,              /* coclass_int  */
  YYSYMBOL_dispinterface = 283,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 284,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 285,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 286,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 287,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 288,                  /* inherit  */
  YYSYMBOL_interface = 289,                /* interface  */
  YYSYMBOL_interfacehdr = 290,             /* interfacehdr  */
  YYSYMBOL_interfacedef = 291,             /* interfacedef  */
  YYSYMBOL_interfacedec = 292,             /* interfacedec  */
  YYSYMBOL_module = 293,                   /* module  */
  YYSYMBOL_modulehdr = 294,                /* modulehdr  */
  YYSYMBOL_moduledef = 295,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 296,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 297,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 298,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 299,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 300,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 301,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 302,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 303,               /* declarator  */
  YYSYMBOL_direct_declarator = 304,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 305,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 306, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 307,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 308, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 309,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 310, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 311,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 312,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 313,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 314,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 315,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 316,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 317,          /* init_declarator  */
  YYSYMBOL_threading_type = 318,           /* threading_type  */
  YYSYMBOL_pointer_type = 319,             /* pointer_type  */
  YYSYMBOL_structdef = 320,                /* structdef  */
  YYSYMBOL_type = 321,                     /* type  */
  YYSYMBOL_typedef = 322,                  /* typedef  */
  YYSYMBOL_uniondef = 323,                 /* uniondef  */
  YYSYMBOL_version = 324,                  /* version  */
  YYSYMBOL_acf_statements = 325,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 326,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 327,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 328,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 329,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 330,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 331             /* acf_attribute  */
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
#define YYLAST   3106

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  214
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  118
/* YYNRULES -- Number of rules.  */
#define YYNRULES  418
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  731

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
       0,   319,   319,   333,   333,   335,   336,   336,   338,   339,
     340,   343,   346,   347,   348,   351,   352,   353,   353,   355,
     356,   357,   360,   361,   362,   363,   366,   367,   370,   371,
     375,   376,   377,   378,   379,   380,   381,   384,   395,   396,
     400,   401,   402,   403,   404,   405,   406,   407,   408,   411,
     413,   421,   427,   431,   432,   434,   438,   442,   443,   446,
     447,   450,   451,   455,   460,   467,   471,   472,   475,   476,
     480,   483,   484,   485,   488,   489,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   502,   503,   504,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   515,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   529,   530,   531,   532,   533,   534,   535,
     536,   537,   538,   539,   540,   541,   542,   543,   544,   545,
     546,   547,   548,   549,   550,   551,   552,   553,   554,   555,
     556,   557,   558,   559,   560,   561,   562,   563,   564,   565,
     566,   567,   571,   572,   573,   574,   575,   576,   577,   578,
     579,   580,   581,   582,   583,   584,   585,   586,   587,   588,
     589,   590,   591,   592,   593,   594,   598,   599,   604,   605,
     606,   607,   610,   611,   614,   618,   624,   625,   626,   629,
     633,   645,   650,   654,   659,   662,   663,   666,   667,   670,
     671,   672,   673,   674,   675,   676,   677,   678,   679,   680,
     681,   682,   683,   684,   685,   686,   687,   688,   689,   690,
     691,   692,   693,   694,   695,   696,   697,   698,   699,   700,
     701,   702,   703,   704,   705,   706,   707,   709,   711,   712,
     715,   716,   719,   725,   731,   732,   735,   740,   747,   748,
     751,   752,   756,   757,   760,   764,   770,   778,   782,   787,
     788,   791,   792,   793,   796,   798,   801,   802,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   814,   815,   818,
     819,   820,   821,   822,   823,   824,   825,   826,   830,   831,
     831,   835,   836,   836,   839,   840,   848,   854,   858,   859,
     862,   863,   867,   870,   871,   874,   883,   884,   887,   888,
     891,   897,   903,   904,   907,   908,   911,   918,   927,   932,
     936,   937,   940,   941,   944,   949,   956,   957,   958,   962,
     966,   969,   970,   973,   974,   978,   979,   983,   984,   985,
     989,   991,   992,   996,   997,   998,   999,  1004,  1006,  1007,
    1012,  1014,  1018,  1019,  1024,  1025,  1026,  1027,  1031,  1039,
    1041,  1042,  1047,  1049,  1053,  1054,  1061,  1062,  1063,  1064,
    1065,  1069,  1076,  1077,  1080,  1081,  1084,  1091,  1092,  1097,
    1098,  1102,  1103,  1104,  1105,  1106,  1110,  1111,  1112,  1115,
    1118,  1119,  1120,  1121,  1122,  1123,  1124,  1125,  1126,  1127,
    1130,  1137,  1139,  1145,  1146,  1147,  1151,  1152,  1155,  1156,
    1159,  1164,  1172,  1173,  1176,  1177,  1180,  1181,  1182
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
  "enum_list", "enum_member", "enum", "enumdef", "m_exprs", "m_expr",
  "expr", "expr_list_int_const", "expr_int_const", "expr_const", "fields",
  "field", "ne_union_field", "ne_union_fields", "union_field", "s_field",
  "funcdef", "declaration", "m_ident", "t_ident", "ident", "base_type",
  "m_int", "int_std", "qualified_seq", "$@3", "qualified_type", "$@4",
  "coclass", "coclasshdr", "coclassdef", "namespacedef", "coclass_ints",
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

#define YYPACT_NINF (-559)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-413)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -559,    54,  1627,  -559,  -559,  -559,   -68,   -64,  -559,  -559,
    -559,   133,  -559,   -94,   204,  -559,   249,  -559,  -559,  -559,
    -559,    28,   138,  -559,  -559,  -559,  -559,  -559,   329,    28,
     165,   -19,  -559,     8,    28,   245,  -559,  -559,   330,   366,
     245,  -559,  -559,  2927,  -559,  -559,  -559,    -4,  -559,  -559,
    -559,  -559,  -559,    45,  2608,    18,    52,  -559,  -559,  -559,
      53,    26,  -559,    61,    63,    66,    73,    74,    59,  -559,
    -559,    87,  -559,    35,    35,    35,    80,  2774,    78,    35,
      88,    91,  -559,   151,  -559,   -64,   202,  -559,  -559,   300,
    -559,  -559,   162,  -559,   120,  -559,  -559,    95,  -559,  -559,
    -559,  -559,  -559,   334,  2774,  -559,  -559,   177,   139,   -88,
    -120,  -559,  -559,   130,  -559,  -559,   141,  -559,  -559,  -559,
     147,   148,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,   154,  -559,  -559,  -559,   155,  -559,  -559,  -559,
     171,   179,  -559,  -559,  -559,  -559,   184,   191,   195,   207,
     209,  -559,   211,  -559,  -559,   213,  -559,   214,  -559,  -559,
     215,   216,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,   217,  -559,  -559,  -559,   218,
     220,  -559,  -559,  -559,  -559,  -559,  -559,   221,  -559,  -559,
     222,  -559,  -559,  -559,   223,  -559,  -559,  -559,   224,   225,
     226,   228,  -559,  -559,  -559,   229,   230,  -559,  -559,   231,
     233,   234,  -110,  -559,  -559,  -559,  1757,   806,   208,   378,
     383,   386,   391,   402,   235,   236,  -559,  -559,  -559,  -559,
      80,   239,   241,  -559,  -559,  -559,  -559,  -559,   -20,  -559,
    -559,  -559,   173,   248,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,    80,    80,  -559,   240,
     -82,  -559,  -559,  -559,    35,  -559,  -559,  -559,   406,  -559,
    -559,  -559,   -99,  -559,  -559,   472,   267,   -26,  -559,   293,
     270,  -559,   272,  -559,   475,   175,   407,   665,   665,   476,
     477,   665,   665,   478,   479,   665,   481,   665,   665,  2140,
     665,   665,   482,   -77,   483,   665,  2774,   665,   665,  2774,
     196,  2774,  2774,   175,   232,   485,  2774,  2927,   291,  -559,
     288,  -559,  -559,  -559,   290,  -559,   294,  -559,  -559,  -559,
      73,  2653,  -559,   296,  -559,  -559,  -559,  -559,   296,  -109,
    -559,  -559,    16,  -559,   316,   -81,   297,   301,  -559,  -559,
    1163,    46,   298,  -559,   665,   560,  2140,  -559,  -559,   303,
    -559,  -559,   151,  -559,   312,  -559,   407,   302,   336,   309,
    -559,   516,  -559,    42,   208,    58,   313,  -559,  -559,   317,
     318,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
     320,  -559,   665,   665,   665,   665,   665,   665,   549,  2363,
    -105,  -559,  2363,   325,   328,  -559,   -69,   332,   335,   337,
     338,   339,   341,   352,  1397,   353,  2653,    31,   354,   -67,
    -559,  2363,   369,   370,   372,   347,   374,   -62,  2145,   381,
    -559,  -559,  -559,  -559,  -559,   384,   385,   398,   400,   319,
    -559,   401,   403,   404,  -559,  2927,   524,  -559,  -559,  -559,
      80,    73,    -8,  -559,  1044,  -559,   355,  2653,   331,  1476,
     405,   454,  1282,    73,  -559,  2653,  -559,  -559,  -559,  -559,
     632,  -559,   584,   410,   363,  -559,  -559,  -559,  -559,   425,
    -559,  -559,    62,   665,  -559,    24,  -559,  2653,  -559,   411,
    -559,   409,  -559,   415,  -559,  -559,  -559,  2653,    -1,    -1,
      -1,    -1,    -1,    -1,  2233,   295,   665,   665,   591,   665,
     665,   665,   665,   665,   665,   665,   665,   665,   665,   665,
     665,   665,   665,   665,   665,   665,   623,   665,   665,  -559,
    -559,  -559,   618,  -559,  -559,  -559,  -559,  -559,  -559,  -559,
    -559,  -559,  -559,    31,  -559,  1876,  -559,    31,  -559,  -559,
    -559,   -79,  -559,   665,  -559,  -559,  -559,  -559,   665,  -559,
    -559,  -559,  -559,  -559,  -559,  -559,  -559,   622,  -559,  -559,
    -559,  -559,   418,  -559,  -559,   448,  -559,  -559,  -559,  -559,
      80,   203,  -559,  -559,  2653,   426,  -559,  -559,  -559,    73,
    -559,  -559,  -559,  -559,  2052,   406,   431,   429,   425,  -559,
    -559,  -559,  -559,    31,   441,   407,  -559,  -559,   295,  -559,
    -559,  1964,  -559,   295,  -559,   442,   -60,    84,    84,  -559,
     382,   382,   322,   322,  2259,  2382,  2342,  2415,  2441,  2389,
     322,   322,    97,    97,    -1,    -1,    -1,  -559,  2303,  -559,
    -559,  -559,    38,  -559,   450,    31,   451,  -559,  2140,  -559,
    -559,   452,  -559,    73,   925,    80,  -559,  -559,  1401,  -559,
    -559,  -559,  -559,   648,  -559,  -559,   473,  -559,   -71,  -559,
     458,  -559,   467,    32,  -559,   469,    31,   470,  -559,   665,
    2140,  -559,   665,  -559,  -559,    38,  -559,  -559,  -559,   471,
    -559,  -559,  -559,  -559,    73,   460,   665,  -559,    31,  -559,
    -559,  -559,  -559,    38,  -559,  -559,  -559,    -1,   474,  2363,
    -559,  -559,  -559,  -559,  -559,  -559,    36,  -559,  -559,   665,
     497,  -559,  -559,   498,   -37,   -37,  -559,  -559,   480,  -559,
    -559
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       5,     0,     3,     1,    35,   291,     0,   406,   274,   266,
     285,     0,   330,     0,     0,   273,   261,   275,   326,   272,
     276,   277,     0,   329,   279,   286,   287,   284,     0,   277,
       0,     0,   328,     0,   277,     0,   281,   327,   261,   261,
     271,   390,   267,    76,     2,    14,    36,     0,    30,    15,
      33,    15,    13,     0,    69,   393,     0,   392,   268,   391,
       0,     0,    11,     0,     0,     0,    28,     0,   312,     9,
       8,     0,    12,   335,   335,   335,     0,     0,   395,   335,
       0,   397,   292,     0,     4,   406,     0,   294,   295,     0,
     303,   304,   394,   263,     0,   278,   283,     0,   314,   315,
     282,   298,   299,     0,     0,   280,   269,   396,     0,   398,
       0,   270,    77,     0,    79,    80,     0,    81,    82,    83,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,     0,    97,    98,    99,     0,   101,   102,   103,
       0,     0,   106,   107,   108,   109,     0,     0,     0,     0,
       0,   115,     0,   117,   118,     0,   120,     0,   122,   123,
     126,     0,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,     0,   141,   142,   143,     0,
       0,   146,   147,   148,   149,   388,   150,     0,   152,   386,
       0,   154,   155,   156,     0,   158,   159,   160,     0,     0,
       0,     0,   165,   387,   166,     0,     0,   170,   171,     0,
       0,     0,     0,    71,   175,    31,    68,    68,    68,   261,
       0,     0,   261,   261,     0,   393,   296,   305,   316,   324,
       0,   395,   397,    32,    10,   300,     6,   321,     0,    29,
     319,   320,     0,     0,    26,   339,   336,   338,   337,   264,
     265,   178,   179,   180,   181,   331,     0,     0,   343,   379,
     342,   258,   393,   395,   335,   397,   333,    34,     0,   417,
     416,   418,     0,   414,   407,     0,     0,    68,    50,     0,
       0,   244,     0,   250,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   197,     0,     0,     0,     0,     0,   197,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    70,    51,
       0,    23,    24,    25,     0,    21,     0,    19,    16,    22,
      28,     0,    69,   394,    53,    54,   322,   323,   396,   398,
      55,   257,    68,     5,     0,    68,     0,     0,   313,    26,
      68,     0,     0,   341,     0,     0,    57,   345,   334,     0,
     288,   293,     0,   413,     0,    49,     0,     0,   188,   193,
     189,     0,   399,    68,    68,    68,     0,   177,   176,     0,
       0,   208,   199,   200,   201,   205,   206,   207,   202,   203,
       0,   204,     0,     0,     0,     0,     0,     0,     0,   242,
       0,   240,   243,     0,     0,    74,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   364,     0,     0,
     195,   198,     0,     0,     0,     0,     0,     0,     0,     0,
     381,   382,   383,   384,   385,     0,     0,     0,     0,   403,
     405,     0,     0,     0,    72,    76,     0,    20,    17,    56,
       0,    28,     0,   301,    68,   306,     0,     0,     0,     0,
       0,     0,    68,    28,    27,    69,   332,   340,   344,   380,
       0,    67,     0,     0,    61,    58,    59,   289,   415,   408,
     191,   194,    68,     0,    38,     0,   389,     0,   245,     0,
     401,    69,   251,     0,    78,   169,    84,     0,   232,   231,
     230,   233,   228,   229,     0,   352,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      96,   100,     0,   104,   105,   110,   111,   112,   113,   114,
     116,   119,   121,   364,   331,    57,   369,   364,   366,   365,
      64,   361,   125,   197,   124,   140,   144,   145,     0,   153,
     157,   161,   162,   164,   163,   167,   168,     0,   172,   173,
     174,    73,     0,    15,   372,   400,   297,   302,     7,   308,
       0,   395,   307,   310,     0,     0,   256,   311,    26,    28,
     325,    66,    65,   346,     0,     0,   412,     0,   408,   190,
     192,    39,    37,     0,   397,   259,   249,   248,   352,   239,
     331,    57,   356,   352,   353,     0,   349,   221,   222,   234,
     215,   216,   219,   220,   210,   211,     0,   212,   213,   214,
     218,   217,   224,   223,   226,   227,   225,   235,     0,   241,
      75,    63,   364,   331,     0,   364,     0,   360,    57,   368,
     196,     0,   404,    28,    68,     0,   254,   309,    68,   317,
      62,    60,   290,     0,   411,   409,   374,   377,     0,   247,
       0,   260,     0,   352,   331,     0,   364,     0,   348,     0,
      57,   355,     0,   238,   359,   364,   370,   363,   367,     0,
     151,    52,    18,   373,    28,     0,     0,   376,     0,   246,
     182,   237,   347,   364,   357,   351,   354,   236,     0,   209,
     362,   371,   318,   410,   375,   378,     0,   350,   358,     0,
       0,   402,   183,     0,    68,    68,   253,   185,     0,   184,
     252
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -559,  -559,  -559,   344,  -559,   -47,  -559,  -322,  -293,     0,
    -559,  -559,  -559,  -559,  -559,   227,  -559,  -559,  -559,    10,
    -513,  -559,  -559,  -288,  -252,  -212,    -2,  -559,  -559,  -273,
     376,   -75,  -559,  -559,  -559,  -559,  -559,   210,    13,   387,
     140,  -198,  -559,  -272,  -277,  -559,  -559,  -559,  -559,   -30,
    -279,  -559,   243,  -559,     9,   -66,  -559,   118,   114,   104,
    -559,   463,  -559,     5,  -559,    11,    14,  -559,  -559,   652,
    -559,  -559,  -559,  -559,  -559,   -25,  -559,    20,    19,  -559,
    -559,    22,  -559,  -559,  -311,  -509,   -49,    -5,   -17,  -238,
    -559,  -559,  -559,  -545,  -559,  -558,  -559,  -501,  -559,  -559,
    -559,    12,  -559,   484,  -559,   412,     1,   -51,  -559,     7,
    -559,   624,   110,  -559,  -559,   116,  -559,   357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    44,     2,   343,   216,   573,   350,   240,   321,
      46,   485,    47,    48,    49,    50,   322,   224,    51,   323,
     473,   474,   475,   476,   546,    53,   332,   212,   406,   213,
     379,   547,   716,   722,   367,   368,   369,   370,   262,   419,
     420,   399,   400,   401,   403,   373,   488,   492,   375,   727,
     728,   585,    56,   670,    94,   548,    57,    96,    58,   361,
     595,    59,   268,   324,    61,   325,   326,   342,   453,    64,
      65,   345,   459,    66,   243,    67,    68,   327,   328,   229,
      71,   329,    73,    74,    75,   351,    76,   245,    77,   259,
     260,   614,   677,   615,   616,   549,   646,   550,   551,   575,
     697,   667,   668,   261,   435,   214,   263,    79,    80,   265,
     441,    84,   597,   598,    85,    86,   272,   273
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      54,   257,    45,    78,   217,   230,   331,    60,   357,    81,
     258,   415,    52,    62,   407,    55,    63,   508,   352,   353,
     408,    70,    69,   411,    72,   413,   264,   462,   418,   228,
     456,   601,   644,   425,   249,   642,   250,   449,  -412,   282,
     466,   249,   641,   250,   444,   666,   647,   108,   110,   249,
    -262,   250,    14,   280,     3,   231,   246,   246,   246,   226,
     185,   232,   246,   672,   189,   366,   458,   225,   678,   247,
     248,  -262,   251,   251,   266,   317,   719,   469,    12,   251,
     528,    12,    28,   249,    12,   250,   362,   251,   283,   720,
     402,   203,    12,   402,    28,   489,   493,   318,   675,  -262,
     414,   673,   508,   421,   252,   252,    18,   529,   363,   421,
     428,   252,   344,   467,   698,   508,   532,    89,   553,   252,
    -262,   251,   -45,   553,   355,    43,    95,   355,   702,   356,
     452,    23,   648,   457,   685,   689,    87,    82,    88,   699,
     666,   684,    83,   533,   687,   554,   355,   100,    97,   106,
     560,   680,   105,   252,   111,   257,   402,   472,   576,   253,
     253,   487,   457,   457,   258,   703,   253,   708,   101,    43,
     590,   102,   571,   726,   253,   705,   347,    32,     5,     6,
      43,   257,   257,  -186,   710,   377,   254,   254,   378,    37,
     258,   258,   103,   254,   498,   499,   500,   501,   502,   503,
     504,   254,   717,   269,   526,   527,   215,    90,   253,    91,
     218,   600,   574,   346,    54,    54,   270,    78,    78,   104,
     380,   271,    43,    81,    81,   451,   544,   610,   -40,    55,
      55,   108,   110,   544,   235,   254,   602,   355,   355,   439,
     440,   255,   545,   611,   355,   721,   242,   246,    43,   545,
     417,   486,    92,   612,    93,   426,   639,   256,   429,   358,
     436,   437,   233,   234,    43,   443,   658,   490,    43,   236,
     366,  -187,   501,   237,   238,   255,   257,   521,   522,   523,
     524,   525,   450,   239,   241,   258,   651,    10,   -42,   526,
     527,   256,   523,   524,   525,   244,   659,   416,   267,   649,
     480,   -44,   526,   527,   275,   278,   661,   417,   617,   618,
     276,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,   630,   631,   632,   633,   634,   635,   636,   277,   638,
      21,   466,    98,   107,    99,    93,   251,   279,   506,   507,
     508,   284,   656,    24,    25,    26,    27,   281,   465,   505,
     464,    78,   285,    29,   416,   421,   612,    81,   286,   287,
     691,   612,   466,    55,   681,   288,   289,   543,   252,   109,
    -262,    93,   -41,   491,   466,   257,   430,   431,   432,   433,
     434,   333,   290,    93,   258,  -262,   334,   -43,   335,   336,
     291,   337,   466,    34,   338,   292,    93,    36,   506,   507,
     508,   712,   293,   511,   512,   339,   294,    93,   580,   359,
     249,   360,   250,  -255,    43,  -255,   230,   693,   295,   714,
     296,   612,   297,   253,   298,   299,   300,   301,   302,   303,
     613,   304,   305,   306,   307,   308,   309,   310,   603,   311,
     312,   313,   314,   340,   315,   316,   -46,   723,   608,   -47,
     254,   -48,    54,   354,    45,    78,   349,   584,   581,    60,
     465,    81,   464,    78,    52,    62,   231,    55,    63,    81,
     645,   577,   232,    70,    69,    55,    72,   364,   225,   365,
     371,   707,   372,   374,   709,   376,   404,   405,   409,   410,
     610,   412,   422,   424,   604,   442,   417,   445,   402,   446,
     447,   355,   448,   455,  -262,   257,   611,   460,   477,   461,
     468,   481,   457,   457,   258,   521,   522,   523,   524,   525,
     479,   482,   483,   484,   567,   494,   654,   526,   527,   495,
     496,   497,   558,   613,   572,   230,   676,   530,   613,   671,
     531,   582,   579,   416,   534,   417,    22,   535,   594,   536,
     537,   538,   381,   539,     5,     6,   382,   383,   384,   385,
     386,   387,   417,   381,   540,   542,   552,   382,   383,   384,
     385,   386,   387,   519,   520,   521,   522,   523,   524,   525,
     257,   555,   556,     8,   557,     9,   559,   526,   527,   258,
     596,    10,   416,   562,   619,    12,   563,   564,   613,   417,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   416,
     565,    15,   566,   568,   587,   569,   570,   219,    17,   606,
      18,   388,   593,   605,    19,   607,   637,    20,   640,   652,
     653,   417,   388,   655,    21,   381,   657,    83,   664,   382,
     383,   384,   385,   386,   387,    23,   416,    24,    25,    26,
      27,   669,    54,   695,   679,    78,   465,    29,   464,    78,
     696,    81,   686,   688,   690,    81,   700,    55,   381,   389,
     713,    55,   382,   383,   384,   385,   386,   387,   416,   701,
     389,   704,   706,   711,   724,   725,   718,   454,   588,   438,
     730,    32,   599,   650,   427,   729,    33,    34,    35,   662,
     390,    36,   586,    37,   388,   348,   227,   222,   665,   274,
     715,   390,   663,   391,   341,   423,   223,     0,    40,   478,
       0,     0,     0,     0,   391,     0,    41,    42,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   388,     0,   392,
       0,     0,   393,   394,   395,     0,     0,   396,   397,     0,
     392,     0,   389,   393,   394,   470,     0,     0,   396,   397,
     398,     0,     0,     0,     0,     0,     0,   471,     0,     0,
     515,   398,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,     0,   390,     0,   389,     0,     0,     0,   526,
     527,   592,     0,     0,     0,     0,   391,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       4,     5,     6,     0,     0,     0,   390,     0,     0,     0,
       0,     0,   392,     0,     0,   393,   394,   395,     0,   391,
     396,   397,     0,     0,     0,     0,     0,     0,     0,   591,
       8,     0,     9,   398,     0,     0,     0,     0,    10,    11,
       0,     0,    12,     0,     0,   392,     0,    13,   393,   394,
     395,     0,     0,   396,   397,     0,    14,     0,    15,     0,
       0,     0,     0,     0,    16,    17,   398,    18,     0,     0,
       0,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,    22,   320,
       0,     0,    23,     0,    24,    25,    26,    27,    28,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     0,     0,     0,     0,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,    34,    35,     0,     0,    36,     8,
      37,     9,     0,     0,    38,     0,     0,    10,    11,     0,
       0,    12,     0,    39,     0,    40,    13,     0,     0,     0,
       0,     0,     0,    41,    42,    14,     0,    15,     0,     0,
       0,     0,     0,    16,    17,     0,    18,     0,     0,     0,
      19,     0,     0,    20,     0,     0,     0,     0,     0,     0,
      21,     0,    43,     0,     0,   330,     0,    22,   320,     0,
       0,    23,     0,    24,    25,    26,    27,    28,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     4,     5,
       6,     0,     0,     0,     0,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    32,     0,     0,
       0,     0,    33,    34,    35,     0,     0,    36,     8,    37,
       9,     0,     0,    38,     0,     0,    10,    11,     0,     0,
      12,     0,    39,     0,    40,    13,     0,     0,     0,     0,
       0,     0,    41,    42,    14,     0,    15,     0,     0,     0,
       0,     0,    16,    17,     0,    18,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,    43,     0,     0,   692,     0,    22,     0,     0,     0,
      23,     0,    24,    25,    26,    27,    28,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     5,     6,
       0,     0,     0,     0,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,    33,    34,    35,     0,     0,    36,     8,    37,     9,
       0,     0,    38,     0,     0,    10,     0,     0,     0,    12,
       0,    39,     0,    40,    13,     0,     0,     0,     0,     0,
       0,    41,    42,     0,     0,    15,     0,     0,     0,     0,
       0,    16,    17,     0,    18,     0,     0,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
      43,     0,     0,   578,     0,    22,     0,     0,     0,    23,
       0,    24,    25,    26,    27,     0,     0,     0,     0,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,    31,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,     0,     0,    36,     8,    37,     9,     0,
       0,    38,     0,     0,    10,     0,     0,     0,    12,     0,
      39,     0,    40,    13,     0,     0,     0,     0,     0,     0,
      41,    42,     0,     0,    15,     0,     0,     0,     0,     0,
      16,    17,     0,    18,     0,     0,     0,    19,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,    43,
       0,     0,   463,     0,    22,     0,     0,     0,    23,     0,
      24,    25,    26,    27,     0,     0,     0,     0,     0,     0,
      29,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     6,     0,     0,
       0,     0,    31,   506,   507,   508,   509,   510,   511,   512,
     513,   514,     0,     0,    32,     0,     0,     0,     0,    33,
      34,    35,     0,     0,    36,     8,    37,     9,     0,     0,
      38,     0,     0,    10,     0,     0,     0,    12,     0,    39,
       0,    40,    13,     0,     0,     0,     0,     0,     0,    41,
      42,     0,     0,    15,     0,     0,     0,     0,     0,    16,
      17,     0,    18,     0,     0,     0,    19,     0,     0,    20,
       0,     5,     6,     0,     0,     0,    21,     0,    43,     0,
       0,   589,     0,    22,     0,     0,     0,    23,     0,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,    29,
       8,     0,     9,     0,     0,     0,     0,     0,    10,     0,
       0,     0,    12,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,     0,     0,    15,     0,
       0,     0,     0,    32,   219,    17,     0,    18,    33,    34,
      35,    19,     0,    36,    20,    37,     0,     0,     0,    38,
       0,    21,     0,     0,     0,     0,     0,     0,    39,     0,
      40,     0,    23,     0,    24,    25,    26,    27,    41,    42,
       0,     0,     0,   515,    29,   516,   517,   518,   519,   520,
     521,   522,   523,   524,   525,     0,     0,     0,     0,     0,
       0,     0,   526,   527,     0,     0,     0,    43,     0,   541,
     694,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,    34,    35,     0,     0,    36,     0,
      37,     4,     5,     6,   222,     0,     0,     0,     0,     0,
       0,     0,     7,   223,     0,    40,     0,     0,     0,     0,
       0,     0,     0,    41,    42,     0,     0,     0,     0,     0,
       0,     8,     0,     9,     0,     0,     0,     0,     0,    10,
      11,     0,     0,    12,     0,     0,     0,     0,    13,     0,
       0,     0,    43,     0,     0,   583,     0,    14,     0,    15,
       0,     0,     0,     0,     0,    16,    17,     0,    18,     0,
       0,     0,    19,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,    23,     0,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,     0,
       0,     4,     5,     6,     0,     0,     0,     0,     0,    32,
       0,   319,     0,     0,    33,    34,    35,     0,     0,    36,
       0,    37,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     8,   -68,     9,    39,     0,    40,     0,     0,    10,
      11,     0,     0,    12,    41,    42,     0,     0,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    15,
       0,     0,     0,     0,     0,    16,    17,     0,    18,     0,
       0,     0,    19,    43,     0,    20,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
     320,     0,     0,    23,     0,    24,    25,    26,    27,    28,
       0,     0,     0,     0,     0,    29,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     0,     0,     0,     0,    31,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,     0,     0,     0,    33,    34,    35,     0,     0,    36,
       8,    37,     9,     0,     0,    38,     0,   251,    10,     0,
       0,     0,    12,     0,    39,     0,    40,     0,     0,     0,
       0,     0,     0,     0,    41,    42,     0,     0,    15,     0,
       0,     0,     0,     0,   219,    17,     0,    18,     0,   252,
       0,    19,     0,     0,    20,     0,     0,     0,     0,     0,
       0,    21,     0,    43,     0,     0,     0,     0,     0,     5,
       6,     0,    23,     0,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     8,     0,
       9,     0,     0,     0,   253,   251,    10,     0,     0,     0,
      12,     0,     0,     0,     0,     0,     0,     0,    32,     0,
       0,     0,     0,    33,    34,    35,    15,     0,    36,     0,
      37,   254,   219,    17,   222,    18,     0,   252,     0,    19,
       0,     0,    20,   223,     0,    40,     0,     0,     0,    21,
       0,     0,     0,    41,    42,     0,     0,     5,     6,     0,
      23,     0,    24,    25,    26,    27,     0,     0,     0,     0,
       0,   643,    29,     0,     0,     0,     0,   660,     0,     0,
       0,     0,    43,     0,     0,     0,     8,     0,     9,     0,
       0,     0,   253,     0,    10,     0,     0,     0,    12,     0,
       0,     0,     0,     0,     0,     0,    32,     0,     0,     0,
       0,    33,    34,    35,    15,     0,    36,     0,    37,   254,
     219,    17,   222,    18,     0,     0,     0,    19,     0,     0,
      20,   223,     0,    40,     0,     0,     0,    21,     0,     0,
       0,    41,    42,     0,     0,     5,     6,     0,    23,     0,
      24,    25,    26,    27,     0,     0,     0,     0,     0,   674,
      29,   506,   507,   508,   509,   510,   511,   512,   513,   514,
      43,     0,     0,     0,     8,     0,     9,     0,     0,     0,
       0,     0,    10,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,     0,    33,
      34,    35,    15,     0,    36,     0,    37,     0,   219,    17,
     222,    18,     0,     0,     0,    19,     0,     0,    20,   223,
       0,    40,     0,     0,     0,    21,     0,     0,     0,    41,
      42,     0,     0,     0,     0,     0,    23,     0,    24,    25,
      26,    27,     0,     0,     0,     0,     0,     0,    29,   506,
     507,   508,   509,   510,   511,   512,   513,   514,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   506,   507,   508,   509,   510,
     511,   512,    32,   514,     0,     0,     0,    33,    34,    35,
       0,     0,    36,     0,    37,     0,     0,     0,   222,     0,
       0,     0,     0,     0,     0,     0,     0,   223,     0,    40,
       0,     0,     0,     0,     0,     0,     0,    41,    42,   506,
     507,   508,   509,   510,   511,   512,   513,   514,     0,     0,
       0,   515,     0,   516,   517,   518,   519,   520,   521,   522,
     523,   524,   525,     0,     0,     0,    43,     0,     0,     0,
     526,   527,     0,     0,     0,     0,     0,   561,   506,   507,
     508,   509,   510,   511,   512,   513,   514,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   506,
     507,   508,   509,   510,   511,   512,   513,   514,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   506,   507,
     508,   509,   510,   511,   512,   506,   507,   508,   509,   510,
     511,   512,     0,     0,     0,     0,     0,     0,     0,   515,
       0,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,   506,   507,   508,   509,   510,   511,   512,   526,   527,
       0,     0,     0,     0,     0,   609,     0,   516,   517,   518,
     519,   520,   521,   522,   523,   524,   525,   506,   507,   508,
     509,   510,   511,   512,   526,   527,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   515,
       0,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,     0,     0,     0,     0,     0,     0,     0,   526,   527,
     683,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   515,   682,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
       0,     0,     0,     0,     0,     0,     0,   526,   527,   515,
       0,   516,   517,   518,   519,   520,   521,   522,   523,   524,
     525,     0,     0,     0,     0,     0,     0,     0,   526,   527,
     516,   517,   518,   519,   520,   521,   522,   523,   524,   525,
     519,   520,   521,   522,   523,   524,   525,   526,   527,     0,
       0,     0,     0,     0,   526,   527,     0,     0,     0,     0,
       0,     0,     0,     0,   517,   518,   519,   520,   521,   522,
     523,   524,   525,     5,     6,     0,     0,     0,     0,     0,
     526,   527,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   518,   519,   520,   521,   522,   523,   524,   525,     0,
       0,     0,     8,     0,     9,     0,   526,   527,     0,     0,
      10,    11,     0,     0,    12,     0,     0,     0,     5,     6,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,     0,     0,     0,     0,     0,   219,    17,     0,    18,
       0,     0,     0,    19,     0,     0,    20,     8,     0,     9,
       0,     0,     0,    21,     0,    10,     0,     0,     0,    12,
       0,     0,     0,     0,    23,     0,    24,    25,    26,    27,
      28,     0,     0,   220,     0,    15,    29,     0,     0,     0,
     221,   219,    17,     0,    18,     0,     0,     0,    19,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      32,    24,    25,    26,    27,    33,    34,    35,     0,     0,
      36,    29,    37,     0,     0,     0,   222,     0,     0,     0,
       0,     0,     0,     0,     0,   223,     0,    40,     0,     5,
       6,     0,     0,     0,     0,    41,    42,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,     0,     0,     0,
      33,    34,    35,     0,     0,    36,     0,    37,     8,     0,
       9,   222,     0,     0,     0,     0,    10,     0,     0,     0,
     223,     0,    40,     0,     0,     0,     0,     0,     0,     0,
      41,    42,     0,     0,     0,     0,    15,     0,     0,     0,
       0,     0,   219,    17,     0,     0,     0,     0,     0,    19,
       0,     0,    20,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,     0,     0,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    33,    34,    35,     0,     0,    36,     0,     0,     0,
       0,     0,   222,     0,     0,     0,     0,     0,     0,     0,
       0,   223,     0,    40,     0,     0,     0,     0,     0,     0,
       0,    41,    42,   112,     0,   113,   114,   115,   116,   117,
     118,     0,   119,     0,     0,   120,     0,   121,     0,     0,
       0,   122,   123,     0,   124,   125,   126,   127,     0,   128,
     129,   130,   131,   132,   133,   134,   135,     0,   136,     0,
     137,   138,   139,   140,   141,     0,     0,   142,     0,     0,
       0,   143,     0,   144,   145,     0,   146,   147,   148,   149,
     150,   151,     0,   152,   153,   154,   155,   156,   157,     0,
       0,   158,     0,     0,   159,     0,     0,     0,     0,     0,
     160,   161,     0,   162,   163,     0,   164,   165,     0,     0,
       0,   166,   167,   168,   169,   170,   171,     0,   172,   173,
     174,   175,   176,   177,   178,     0,   179,     0,   180,     0,
     181,   182,   183,   184,   185,   186,   187,   188,   189,     0,
     190,   191,   192,   193,     0,     0,     0,   194,     0,     0,
     195,     0,     0,   196,   197,     0,     0,   198,   199,   200,
     201,     0,     0,   202,     0,   203,     0,   204,   205,   206,
     207,   208,   209,   210,     0,     0,   211
};

static const yytype_int16 yycheck[] =
{
       2,    76,     2,     2,    51,    54,   218,     2,   260,     2,
      76,   299,     2,     2,   291,     2,     2,    18,   256,   257,
     292,     2,     2,   295,     2,   297,    77,   349,   300,    54,
     111,     7,   545,   305,     3,   544,     5,   330,   102,   159,
     351,     3,   543,     5,   317,   603,   547,    38,    39,     3,
     159,     5,    60,   104,     0,    54,    73,    74,    75,    54,
     137,    54,    79,   608,   141,   277,   345,    54,   613,    74,
      75,   159,    41,    41,    79,   185,    40,   354,    46,    41,
     185,    46,   102,     3,    46,     5,   185,    41,   208,    53,
     288,   168,    46,   291,   102,   374,   375,   207,   611,   208,
     298,   610,    18,   301,    73,    73,    71,   212,   207,   307,
     308,    73,   132,   351,   185,    18,   185,   211,   185,    73,
     208,    41,   210,   185,   206,   206,    98,   206,   673,   211,
     342,    96,   211,   345,   643,   648,     3,   205,     5,   210,
     698,   642,   206,   212,   645,   212,   206,    29,    10,    35,
     212,   211,    34,    73,    40,   230,   354,   355,   451,   128,
     128,   373,   374,   375,   230,   674,   128,   680,     3,   206,
     463,     6,   445,   210,   128,   676,     3,   142,     5,     6,
     206,   256,   257,   209,   685,    10,   155,   155,    13,   154,
     256,   257,   211,   155,   392,   393,   394,   395,   396,   397,
     398,   155,   703,    52,   205,   206,   210,     3,   128,     5,
     165,   483,   450,   238,   216,   217,    65,   216,   217,   211,
     286,    70,   206,   216,   217,   209,   195,   195,   210,   216,
     217,   222,   223,   195,   208,   155,   212,   206,   206,     7,
       8,   195,   211,   211,   206,   209,   187,   264,   206,   211,
     299,   209,     3,   505,     5,   306,   528,   211,   309,   264,
     311,   312,   210,   210,   206,   316,   588,   209,   206,   208,
     482,   209,   470,   210,   208,   195,   351,   193,   194,   195,
     196,   197,   331,   210,   210,   351,   558,    42,   210,   205,
     206,   211,   195,   196,   197,   208,   589,   299,   210,   551,
     366,   210,   205,   206,   102,   210,   594,   356,   506,   507,
      10,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     518,   519,   520,   521,   522,   523,   524,   525,   208,   527,
      85,   642,     3,     3,     5,     5,    41,     3,    16,    17,
      18,   211,   580,    98,    99,   100,   101,   208,   350,   398,
     350,   350,   211,   108,   356,   553,   608,   350,   211,   211,
     653,   613,   673,   350,   616,   211,   211,   416,    73,     3,
     208,     5,   210,   375,   685,   450,   180,   181,   182,   183,
     184,     3,   211,     5,   450,   208,     3,   210,     5,     3,
     211,     5,   703,   148,     3,   211,     5,   152,    16,    17,
      18,   694,   211,    21,    22,     3,   211,     5,   457,     3,
       3,     5,     5,   210,   206,   212,   465,   655,   211,   696,
     211,   673,   211,   128,   211,   211,   211,   211,   211,   211,
     505,   211,   211,   211,   211,   211,   211,   211,   487,   211,
     211,   211,   211,   208,   211,   211,   210,   719,   497,   210,
     155,   210,   454,   213,   454,   454,   208,   459,   457,   454,
     462,   454,   462,   462,   454,   454,   465,   454,   454,   462,
     545,   452,   465,   454,   454,   462,   454,     5,   465,   212,
     187,   679,   212,   211,   682,    10,    10,    10,    10,    10,
     195,    10,    10,    10,   487,    10,   545,   206,   696,   211,
     210,   206,   208,   187,   208,   580,   211,   210,   205,   208,
     212,   209,   724,   725,   580,   193,   194,   195,   196,   197,
     208,   185,   213,     7,   205,   212,   573,   205,   206,   212,
     212,   211,   185,   608,    10,   584,   611,   212,   613,   605,
     212,   210,   187,   545,   212,   594,    92,   212,   185,   212,
     212,   212,     3,   212,     5,     6,     7,     8,     9,    10,
      11,    12,   611,     3,   212,   212,   212,     7,     8,     9,
      10,    11,    12,   191,   192,   193,   194,   195,   196,   197,
     655,   212,   212,    34,   212,    36,   212,   205,   206,   655,
     165,    42,   594,   212,     3,    46,   212,   212,   673,   648,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   611,
     212,    62,   212,   212,   209,   212,   212,    68,    69,   210,
      71,    72,   212,   212,    75,   210,     3,    78,    10,     7,
     212,   680,    72,   185,    85,     3,   210,   206,   209,     7,
       8,     9,    10,    11,    12,    96,   648,    98,    99,   100,
     101,   210,   654,     5,   212,   654,   658,   108,   658,   658,
     187,   654,   212,   212,   212,   658,   208,   654,     3,   120,
     210,   658,     7,     8,     9,    10,    11,    12,   680,   212,
     120,   212,   212,   212,   187,   187,   212,   343,   461,   313,
     210,   142,   482,   553,   307,   725,   147,   148,   149,   595,
     151,   152,   459,   154,    72,   242,    54,   158,   598,    85,
     698,   151,   596,   164,   230,   303,   167,    -1,   169,   362,
      -1,    -1,    -1,    -1,   164,    -1,   177,   178,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,   190,
      -1,    -1,   193,   194,   195,    -1,    -1,   198,   199,    -1,
     190,    -1,   120,   193,   194,   195,    -1,    -1,   198,   199,
     211,    -1,    -1,    -1,    -1,    -1,    -1,   207,    -1,    -1,
     186,   211,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,   151,    -1,   120,    -1,    -1,    -1,   205,
     206,   207,    -1,    -1,    -1,    -1,   164,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       4,     5,     6,    -1,    -1,    -1,   151,    -1,    -1,    -1,
      -1,    -1,   190,    -1,    -1,   193,   194,   195,    -1,   164,
     198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      34,    -1,    36,   211,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    46,    -1,    -1,   190,    -1,    51,   193,   194,
     195,    -1,    -1,   198,   199,    -1,    60,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,   211,    71,    -1,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,    93,
      -1,    -1,    96,    -1,    98,    99,   100,   101,   102,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,   152,    34,
     154,    36,    -1,    -1,   158,    -1,    -1,    42,    43,    -1,
      -1,    46,    -1,   167,    -1,   169,    51,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,    60,    -1,    62,    -1,    -1,
      -1,    -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,   206,    -1,    -1,   209,    -1,    92,    93,    -1,
      -1,    96,    -1,    98,    99,   100,   101,   102,    -1,    -1,
      -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,   113,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,
       6,    -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,
      -1,    -1,   147,   148,   149,    -1,    -1,   152,    34,   154,
      36,    -1,    -1,   158,    -1,    -1,    42,    43,    -1,    -1,
      46,    -1,   167,    -1,   169,    51,    -1,    -1,    -1,    -1,
      -1,    -1,   177,   178,    60,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,   206,    -1,    -1,   209,    -1,    92,    -1,    -1,    -1,
      96,    -1,    98,    99,   100,   101,   102,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,   113,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
      -1,    -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,    -1,   152,    34,   154,    36,
      -1,    -1,   158,    -1,    -1,    42,    -1,    -1,    -1,    46,
      -1,   167,    -1,   169,    51,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,    -1,    -1,    62,    -1,    -1,    -1,    -1,
      -1,    68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
     206,    -1,    -1,   209,    -1,    92,    -1,    -1,    -1,    96,
      -1,    98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,
      -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,   152,    34,   154,    36,    -1,
      -1,   158,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,
     167,    -1,   169,    51,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,
      68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,   206,
      -1,    -1,   209,    -1,    92,    -1,    -1,    -1,    96,    -1,
      98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,
      -1,    -1,   130,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,   152,    34,   154,    36,    -1,    -1,
     158,    -1,    -1,    42,    -1,    -1,    -1,    46,    -1,   167,
      -1,   169,    51,    -1,    -1,    -1,    -1,    -1,    -1,   177,
     178,    -1,    -1,    62,    -1,    -1,    -1,    -1,    -1,    68,
      69,    -1,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,     5,     6,    -1,    -1,    -1,    85,    -1,   206,    -1,
      -1,   209,    -1,    92,    -1,    -1,    -1,    96,    -1,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,
      34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   130,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    -1,   142,    68,    69,    -1,    71,   147,   148,
     149,    75,    -1,   152,    78,   154,    -1,    -1,    -1,   158,
      -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,
     169,    -1,    96,    -1,    98,    99,   100,   101,   177,   178,
      -1,    -1,    -1,   186,   108,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   205,   206,    -1,    -1,    -1,   206,    -1,   212,
     209,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,   152,    -1,
     154,     4,     5,     6,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,   167,    -1,   169,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   177,   178,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    51,    -1,
      -1,    -1,   206,    -1,    -1,   209,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      -1,    -1,    -1,    96,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    14,    -1,    -1,   147,   148,   149,    -1,    -1,   152,
      -1,   154,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    34,   165,    36,   167,    -1,   169,    -1,    -1,    42,
      43,    -1,    -1,    46,   177,   178,    -1,    -1,    51,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    62,
      -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,
      -1,    -1,    75,   206,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    -1,    -1,    -1,    -1,    -1,    -1,    92,
      93,    -1,    -1,    96,    -1,    98,    99,   100,   101,   102,
      -1,    -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,
     113,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     5,     6,    -1,    -1,    -1,    -1,   130,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      -1,    -1,    -1,    -1,   147,   148,   149,    -1,    -1,   152,
      34,   154,    36,    -1,    -1,   158,    -1,    41,    42,    -1,
      -1,    -1,    46,    -1,   167,    -1,   169,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    62,    -1,
      -1,    -1,    -1,    -1,    68,    69,    -1,    71,    -1,    73,
      -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,   206,    -1,    -1,    -1,    -1,    -1,     5,
       6,    -1,    96,    -1,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    -1,
      36,    -1,    -1,    -1,   128,    41,    42,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,
      -1,    -1,    -1,   147,   148,   149,    62,    -1,   152,    -1,
     154,   155,    68,    69,   158,    71,    -1,    73,    -1,    75,
      -1,    -1,    78,   167,    -1,   169,    -1,    -1,    -1,    85,
      -1,    -1,    -1,   177,   178,    -1,    -1,     5,     6,    -1,
      96,    -1,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,   195,   108,    -1,    -1,    -1,    -1,    25,    -1,    -1,
      -1,    -1,   206,    -1,    -1,    -1,    34,    -1,    36,    -1,
      -1,    -1,   128,    -1,    42,    -1,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,
      -1,   147,   148,   149,    62,    -1,   152,    -1,   154,   155,
      68,    69,   158,    71,    -1,    -1,    -1,    75,    -1,    -1,
      78,   167,    -1,   169,    -1,    -1,    -1,    85,    -1,    -1,
      -1,   177,   178,    -1,    -1,     5,     6,    -1,    96,    -1,
      98,    99,   100,   101,    -1,    -1,    -1,    -1,    -1,   195,
     108,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     206,    -1,    -1,    -1,    34,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,   147,
     148,   149,    62,    -1,   152,    -1,   154,    -1,    68,    69,
     158,    71,    -1,    -1,    -1,    75,    -1,    -1,    78,   167,
      -1,   169,    -1,    -1,    -1,    85,    -1,    -1,    -1,   177,
     178,    -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,    -1,   108,    16,
      17,    18,    19,    20,    21,    22,    23,    24,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,   142,    24,    -1,    -1,    -1,   147,   148,   149,
      -1,    -1,   152,    -1,   154,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   167,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   177,   178,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,   186,    -1,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,   206,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,   212,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    16,    17,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    16,    17,    18,    19,    20,    21,    22,   205,   206,
      -1,    -1,    -1,    -1,    -1,   212,    -1,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    16,    17,    18,
      19,    20,    21,    22,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     207,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,   186,
      -1,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   205,   206,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     191,   192,   193,   194,   195,   196,   197,   205,   206,    -1,
      -1,    -1,    -1,    -1,   205,   206,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   189,   190,   191,   192,   193,   194,
     195,   196,   197,     5,     6,    -1,    -1,    -1,    -1,    -1,
     205,   206,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    34,    -1,    36,    -1,   205,   206,    -1,    -1,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    -1,    -1,    -1,    -1,    -1,    68,    69,    -1,    71,
      -1,    -1,    -1,    75,    -1,    -1,    78,    34,    -1,    36,
      -1,    -1,    -1,    85,    -1,    42,    -1,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    96,    -1,    98,    99,   100,   101,
     102,    -1,    -1,   105,    -1,    62,   108,    -1,    -1,    -1,
     112,    68,    69,    -1,    71,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
     142,    98,    99,   100,   101,   147,   148,   149,    -1,    -1,
     152,   108,   154,    -1,    -1,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   167,    -1,   169,    -1,     5,
       6,    -1,    -1,    -1,    -1,   177,   178,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,
     147,   148,   149,    -1,    -1,   152,    -1,   154,    34,    -1,
      36,   158,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
     167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     177,   178,    -1,    -1,    -1,    -1,    62,    -1,    -1,    -1,
      -1,    -1,    68,    69,    -1,    -1,    -1,    -1,    -1,    75,
      -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    98,    99,   100,   101,    -1,    -1,    -1,    -1,
      -1,    -1,   108,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   147,   148,   149,    -1,    -1,   152,    -1,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   167,    -1,   169,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   177,   178,    26,    -1,    28,    29,    30,    31,    32,
      33,    -1,    35,    -1,    -1,    38,    -1,    40,    -1,    -1,
      -1,    44,    45,    -1,    47,    48,    49,    50,    -1,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    70,    -1,    -1,
      -1,    74,    -1,    76,    77,    -1,    79,    80,    81,    82,
      83,    84,    -1,    86,    87,    88,    89,    90,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
     103,   104,    -1,   106,   107,    -1,   109,   110,    -1,    -1,
      -1,   114,   115,   116,   117,   118,   119,    -1,   121,   122,
     123,   124,   125,   126,   127,    -1,   129,    -1,   131,    -1,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    -1,
     143,   144,   145,   146,    -1,    -1,    -1,   150,    -1,    -1,
     153,    -1,    -1,   156,   157,    -1,    -1,   160,   161,   162,
     163,    -1,    -1,   166,    -1,   168,    -1,   170,   171,   172,
     173,   174,   175,   176,    -1,    -1,   179
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
     229,   232,   233,   239,   240,   252,   266,   270,   272,   275,
     277,   278,   279,   280,   283,   284,   287,   289,   290,   291,
     292,   294,   295,   296,   297,   298,   300,   302,   320,   321,
     322,   323,   205,   206,   325,   328,   329,     3,     5,   211,
       3,     5,     3,     5,   268,    98,   271,    10,     3,     5,
     271,     3,     6,   211,   211,   271,   272,     3,   268,     3,
     268,   272,    26,    28,    29,    30,    31,    32,    33,    35,
      38,    40,    44,    45,    47,    48,    49,    50,    52,    53,
      54,    55,    56,    57,    58,    59,    61,    63,    64,    65,
      66,    67,    70,    74,    76,    77,    79,    80,    81,    82,
      83,    84,    86,    87,    88,    89,    90,    91,    94,    97,
     103,   104,   106,   107,   109,   110,   114,   115,   116,   117,
     118,   119,   121,   122,   123,   124,   125,   126,   127,   129,
     131,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     143,   144,   145,   146,   150,   153,   156,   157,   160,   161,
     162,   163,   166,   168,   170,   171,   172,   173,   174,   175,
     176,   179,   241,   243,   319,   210,   219,   219,   165,    68,
     105,   112,   158,   167,   231,   252,   277,   283,   289,   293,
     300,   320,   323,   210,   210,   208,   208,   210,   208,   210,
     222,   210,   187,   288,   208,   301,   302,   301,   301,     3,
       5,    41,    73,   128,   155,   195,   211,   245,   269,   303,
     304,   317,   252,   320,   321,   323,   301,   210,   276,    52,
      65,    70,   330,   331,   325,   102,    10,   208,   210,     3,
     321,   208,   159,   208,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   185,   207,    14,
      93,   223,   230,   233,   277,   279,   280,   291,   292,   295,
     209,   239,   240,     3,     3,     5,     3,     5,     3,     3,
     208,   317,   281,   218,   132,   285,   289,     3,   275,   208,
     221,   299,   303,   303,   213,   206,   211,   238,   301,     3,
       5,   273,   185,   207,     5,   212,   239,   248,   249,   250,
     251,   187,   212,   259,   211,   262,    10,    10,    13,   244,
     269,     3,     7,     8,     9,    10,    11,    12,    72,   120,
     151,   164,   190,   193,   194,   195,   198,   199,   211,   255,
     256,   257,   255,   258,    10,    10,   242,   258,   257,    10,
      10,   257,    10,   257,   255,   237,   240,   300,   257,   253,
     254,   255,    10,   319,    10,   257,   321,   253,   255,   321,
     180,   181,   182,   183,   184,   318,   321,   321,   244,     7,
       8,   324,    10,   321,   243,   206,   211,   210,   208,   222,
     300,   209,   239,   282,   217,   187,   111,   239,   264,   286,
     210,   208,   221,   209,   223,   240,   298,   303,   212,   258,
     195,   207,   255,   234,   235,   236,   237,   205,   331,   208,
     269,   209,   185,   213,     7,   225,   209,   239,   260,   264,
     209,   240,   261,   264,   212,   212,   212,   211,   255,   255,
     255,   255,   255,   255,   255,   300,    16,    17,    18,    19,
      20,    21,    22,    23,    24,   186,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   205,   206,   185,   212,
     212,   212,   185,   212,   212,   212,   212,   212,   212,   212,
     212,   212,   212,   300,   195,   211,   238,   245,   269,   309,
     311,   312,   212,   185,   212,   212,   212,   212,   185,   212,
     212,   212,   212,   212,   212,   212,   212,   205,   212,   212,
     212,   243,    10,   220,   303,   313,   222,   292,   209,   187,
     300,   320,   210,   209,   240,   265,   266,   209,   229,   209,
     222,   207,   207,   212,   185,   274,   165,   326,   327,   251,
     257,     7,   212,   300,   323,   212,   210,   210,   300,   212,
     195,   211,   238,   245,   305,   307,   308,   255,   255,     3,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,     3,   255,   257,
      10,   311,   299,   195,   234,   245,   310,   311,   211,   238,
     254,   257,     7,   212,   219,   185,   303,   210,   221,   222,
      25,   237,   273,   329,   209,   326,   309,   315,   316,   210,
     267,   269,   307,   299,   195,   234,   245,   306,   307,   212,
     211,   238,   187,   207,   311,   299,   212,   311,   212,   234,
     212,   222,   209,   303,   209,     5,   187,   314,   185,   210,
     208,   212,   307,   299,   212,   311,   212,   255,   234,   255,
     311,   212,   222,   210,   258,   315,   246,   311,   212,    40,
      53,   209,   247,   257,   187,   187,   210,   263,   264,   263,
     210
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
     249,   250,   251,   251,   252,   253,   253,   254,   254,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     256,   256,   257,   258,   259,   259,   260,   260,   261,   261,
     262,   262,   263,   263,   264,   264,   265,   266,   266,   267,
     267,   268,   268,   268,   269,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   273,   274,
     273,   275,   276,   275,   277,   277,   278,   279,   280,   280,
     281,   281,   282,   283,   283,   284,   285,   285,   286,   286,
     287,   287,   288,   288,   289,   289,   290,   291,   291,   291,
     292,   292,   293,   293,   294,   295,   296,   296,   296,   297,
     298,   299,   299,   300,   300,   301,   301,   302,   302,   302,
     303,   303,   303,   304,   304,   304,   304,   305,   305,   305,
     306,   306,   307,   307,   308,   308,   308,   308,   308,   309,
     309,   309,   310,   310,   311,   311,   312,   312,   312,   312,
     312,   312,   313,   313,   314,   314,   315,   316,   316,   317,
     317,   318,   318,   318,   318,   318,   319,   319,   319,   320,
     321,   321,   321,   321,   321,   321,   321,   321,   321,   321,
     322,   323,   323,   324,   324,   324,   325,   325,   326,   326,
     327,   328,   329,   329,   330,   330,   331,   331,   331
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
       3,     2,     3,     1,     5,     1,     3,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     2,     3,     3,     5,     5,     4,     3,
       1,     3,     1,     1,     0,     2,     4,     3,     2,     2,
       0,     2,     2,     1,     3,     2,     1,     3,     2,     0,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     0,     1,     1,
       2,     1,     2,     2,     1,     1,     1,     1,     1,     0,
       4,     1,     0,     4,     2,     2,     2,     5,     2,     2,
       0,     2,     2,     2,     2,     2,     2,     3,     2,     3,
       5,     5,     0,     2,     2,     2,     2,     6,     8,     2,
       2,     2,     2,     2,     2,     5,     1,     1,     1,     1,
       1,     0,     2,     2,     3,     0,     1,     2,     2,     2,
       3,     2,     1,     1,     3,     2,     4,     3,     2,     1,
       3,     2,     0,     1,     3,     2,     1,     3,     4,     3,
       2,     1,     3,     2,     0,     1,     1,     3,     2,     1,
       3,     4,     1,     3,     0,     2,     2,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       1,     1,     1,     1,     2,     1,     2,     1,     2,     4,
       5,     5,    10,     1,     3,     1,     0,     2,     0,     2,
       4,     6,     0,     3,     1,     3,     1,     1,     1
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
#line 319 "tools/widl/parser.y"
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
#line 3133 "tools/widl/parser.tab.c"
    break;

  case 5: /* gbl_statements: %empty  */
#line 335 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3139 "tools/widl/parser.tab.c"
    break;

  case 6: /* $@1: %empty  */
#line 336 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3145 "tools/widl/parser.tab.c"
    break;

  case 7: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 337 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3151 "tools/widl/parser.tab.c"
    break;

  case 8: /* gbl_statements: gbl_statements interfacedec  */
#line 338 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3157 "tools/widl/parser.tab.c"
    break;

  case 9: /* gbl_statements: gbl_statements interfacedef  */
#line 339 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3163 "tools/widl/parser.tab.c"
    break;

  case 10: /* gbl_statements: gbl_statements coclass ';'  */
#line 340 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3171 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: gbl_statements coclassdef  */
#line 343 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3179 "tools/widl/parser.tab.c"
    break;

  case 12: /* gbl_statements: gbl_statements moduledef  */
#line 346 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3185 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements librarydef  */
#line 347 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3191 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements statement  */
#line 348 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3197 "tools/widl/parser.tab.c"
    break;

  case 15: /* imp_statements: %empty  */
#line 351 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3203 "tools/widl/parser.tab.c"
    break;

  case 16: /* imp_statements: imp_statements interfacedec  */
#line 352 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3209 "tools/widl/parser.tab.c"
    break;

  case 17: /* $@2: %empty  */
#line 353 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3215 "tools/widl/parser.tab.c"
    break;

  case 18: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 354 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3221 "tools/widl/parser.tab.c"
    break;

  case 19: /* imp_statements: imp_statements interfacedef  */
#line 355 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3227 "tools/widl/parser.tab.c"
    break;

  case 20: /* imp_statements: imp_statements coclass ';'  */
#line 356 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3233 "tools/widl/parser.tab.c"
    break;

  case 21: /* imp_statements: imp_statements coclassdef  */
#line 357 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3241 "tools/widl/parser.tab.c"
    break;

  case 22: /* imp_statements: imp_statements moduledef  */
#line 360 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3247 "tools/widl/parser.tab.c"
    break;

  case 23: /* imp_statements: imp_statements statement  */
#line 361 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3253 "tools/widl/parser.tab.c"
    break;

  case 24: /* imp_statements: imp_statements importlib  */
#line 362 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3259 "tools/widl/parser.tab.c"
    break;

  case 25: /* imp_statements: imp_statements librarydef  */
#line 363 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3265 "tools/widl/parser.tab.c"
    break;

  case 26: /* int_statements: %empty  */
#line 366 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3271 "tools/widl/parser.tab.c"
    break;

  case 27: /* int_statements: int_statements statement  */
#line 367 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3277 "tools/widl/parser.tab.c"
    break;

  case 30: /* statement: cppquote  */
#line 375 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3283 "tools/widl/parser.tab.c"
    break;

  case 31: /* statement: typedecl ';'  */
#line 376 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3289 "tools/widl/parser.tab.c"
    break;

  case 32: /* statement: declaration ';'  */
#line 377 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3295 "tools/widl/parser.tab.c"
    break;

  case 33: /* statement: import  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3301 "tools/widl/parser.tab.c"
    break;

  case 34: /* statement: typedef ';'  */
#line 379 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3307 "tools/widl/parser.tab.c"
    break;

  case 35: /* statement: aPRAGMA  */
#line 380 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3313 "tools/widl/parser.tab.c"
    break;

  case 36: /* statement: pragma_warning  */
#line 381 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3319 "tools/widl/parser.tab.c"
    break;

  case 37: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 385 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3331 "tools/widl/parser.tab.c"
    break;

  case 38: /* warnings: aNUM  */
#line 395 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3337 "tools/widl/parser.tab.c"
    break;

  case 39: /* warnings: warnings aNUM  */
#line 396 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3343 "tools/widl/parser.tab.c"
    break;

  case 41: /* typedecl: tENUM aIDENTIFIER  */
#line 401 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3349 "tools/widl/parser.tab.c"
    break;

  case 43: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3355 "tools/widl/parser.tab.c"
    break;

  case 45: /* typedecl: tUNION aIDENTIFIER  */
#line 405 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3361 "tools/widl/parser.tab.c"
    break;

  case 46: /* typedecl: attributes enumdef  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3367 "tools/widl/parser.tab.c"
    break;

  case 47: /* typedecl: attributes structdef  */
#line 407 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3373 "tools/widl/parser.tab.c"
    break;

  case 48: /* typedecl: attributes uniondef  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3379 "tools/widl/parser.tab.c"
    break;

  case 49: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3385 "tools/widl/parser.tab.c"
    break;

  case 50: /* import_start: tIMPORT aSTRING ';'  */
#line 413 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3396 "tools/widl/parser.tab.c"
    break;

  case 51: /* import: import_start imp_statements aEOF  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3405 "tools/widl/parser.tab.c"
    break;

  case 52: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 428 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3411 "tools/widl/parser.tab.c"
    break;

  case 53: /* libraryhdr: tLIBRARY aIDENTIFIER  */
#line 431 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3417 "tools/widl/parser.tab.c"
    break;

  case 54: /* libraryhdr: tLIBRARY aKNOWNTYPE  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3423 "tools/widl/parser.tab.c"
    break;

  case 55: /* library_start: attributes libraryhdr '{'  */
#line 434 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3431 "tools/widl/parser.tab.c"
    break;

  case 56: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3437 "tools/widl/parser.tab.c"
    break;

  case 57: /* m_args: %empty  */
#line 442 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3443 "tools/widl/parser.tab.c"
    break;

  case 59: /* arg_list: arg  */
#line 446 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3449 "tools/widl/parser.tab.c"
    break;

  case 60: /* arg_list: arg_list ',' arg  */
#line 447 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3455 "tools/widl/parser.tab.c"
    break;

  case 62: /* args: arg_list ',' ELLIPSIS  */
#line 451 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3461 "tools/widl/parser.tab.c"
    break;

  case 63: /* arg: attributes decl_spec m_any_declarator  */
#line 455 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3471 "tools/widl/parser.tab.c"
    break;

  case 64: /* arg: decl_spec m_any_declarator  */
#line 460 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3481 "tools/widl/parser.tab.c"
    break;

  case 65: /* array: '[' expr ']'  */
#line 467 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3490 "tools/widl/parser.tab.c"
    break;

  case 66: /* array: '[' '*' ']'  */
#line 471 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3496 "tools/widl/parser.tab.c"
    break;

  case 67: /* array: '[' ']'  */
#line 472 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3502 "tools/widl/parser.tab.c"
    break;

  case 68: /* m_attributes: %empty  */
#line 475 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3508 "tools/widl/parser.tab.c"
    break;

  case 70: /* attributes: '[' attrib_list ']'  */
#line 480 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3514 "tools/widl/parser.tab.c"
    break;

  case 71: /* attrib_list: attribute  */
#line 483 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3520 "tools/widl/parser.tab.c"
    break;

  case 72: /* attrib_list: attrib_list ',' attribute  */
#line 484 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3526 "tools/widl/parser.tab.c"
    break;

  case 73: /* attrib_list: attrib_list ']' '[' attribute  */
#line 485 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3532 "tools/widl/parser.tab.c"
    break;

  case 74: /* str_list: aSTRING  */
#line 488 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3538 "tools/widl/parser.tab.c"
    break;

  case 75: /* str_list: str_list ',' aSTRING  */
#line 489 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3544 "tools/widl/parser.tab.c"
    break;

  case 76: /* attribute: %empty  */
#line 492 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3550 "tools/widl/parser.tab.c"
    break;

  case 77: /* attribute: tAGGREGATABLE  */
#line 493 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3556 "tools/widl/parser.tab.c"
    break;

  case 78: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 494 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3562 "tools/widl/parser.tab.c"
    break;

  case 79: /* attribute: tAPPOBJECT  */
#line 495 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3568 "tools/widl/parser.tab.c"
    break;

  case 80: /* attribute: tASYNC  */
#line 496 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3574 "tools/widl/parser.tab.c"
    break;

  case 81: /* attribute: tAUTOHANDLE  */
#line 497 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3580 "tools/widl/parser.tab.c"
    break;

  case 82: /* attribute: tBINDABLE  */
#line 498 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3586 "tools/widl/parser.tab.c"
    break;

  case 83: /* attribute: tBROADCAST  */
#line 499 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3592 "tools/widl/parser.tab.c"
    break;

  case 84: /* attribute: tCALLAS '(' ident ')'  */
#line 500 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3598 "tools/widl/parser.tab.c"
    break;

  case 85: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 501 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3604 "tools/widl/parser.tab.c"
    break;

  case 86: /* attribute: tCODE  */
#line 502 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3610 "tools/widl/parser.tab.c"
    break;

  case 87: /* attribute: tCOMMSTATUS  */
#line 503 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3616 "tools/widl/parser.tab.c"
    break;

  case 88: /* attribute: tCONTEXTHANDLE  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3622 "tools/widl/parser.tab.c"
    break;

  case 89: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3628 "tools/widl/parser.tab.c"
    break;

  case 90: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 506 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3634 "tools/widl/parser.tab.c"
    break;

  case 91: /* attribute: tCONTROL  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3640 "tools/widl/parser.tab.c"
    break;

  case 92: /* attribute: tDECODE  */
#line 508 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3646 "tools/widl/parser.tab.c"
    break;

  case 93: /* attribute: tDEFAULT  */
#line 509 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3652 "tools/widl/parser.tab.c"
    break;

  case 94: /* attribute: tDEFAULTBIND  */
#line 510 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3658 "tools/widl/parser.tab.c"
    break;

  case 95: /* attribute: tDEFAULTCOLLELEM  */
#line 511 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3664 "tools/widl/parser.tab.c"
    break;

  case 96: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3670 "tools/widl/parser.tab.c"
    break;

  case 97: /* attribute: tDEFAULTVTABLE  */
#line 513 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3676 "tools/widl/parser.tab.c"
    break;

  case 98: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 514 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3682 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: tDISPLAYBIND  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3688 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 516 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3694 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tDUAL  */
#line 517 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3700 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tENABLEALLOCATE  */
#line 518 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3706 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tENCODE  */
#line 519 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3712 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tENDPOINT '(' str_list ')'  */
#line 520 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3718 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tENTRY '(' expr_const ')'  */
#line 521 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3724 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tEXPLICITHANDLE  */
#line 522 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3730 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tFAULTSTATUS  */
#line 523 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3736 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tFORCEALLOCATE  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3742 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tHANDLE  */
#line 525 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3748 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 526 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3754 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 527 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3760 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 528 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3766 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 529 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3772 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 530 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3778 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tHIDDEN  */
#line 531 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3784 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tID '(' expr_int_const ')'  */
#line 532 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3790 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tIDEMPOTENT  */
#line 533 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3796 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tIGNORE  */
#line 534 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3802 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tIIDIS '(' expr ')'  */
#line 535 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3808 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tIMMEDIATEBIND  */
#line 536 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3814 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 537 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3820 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tIN  */
#line 538 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 3826 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tINPUTSYNC  */
#line 539 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3832 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3838 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tLCID '(' expr_int_const ')'  */
#line 541 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3844 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tLCID  */
#line 542 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3850 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tLICENSED  */
#line 543 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3856 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tLOCAL  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3862 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tMAYBE  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3868 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tMESSAGE  */
#line 546 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3874 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tNOCODE  */
#line 547 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3880 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tNONBROWSABLE  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3886 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tNONCREATABLE  */
#line 549 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3892 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tNONEXTENSIBLE  */
#line 550 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3898 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tNOTIFY  */
#line 551 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3904 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tNOTIFYFLAG  */
#line 552 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3910 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tOBJECT  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3916 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tODL  */
#line 554 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3922 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tOLEAUTOMATION  */
#line 555 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3928 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3934 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tOPTIONAL  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3940 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tOUT  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3946 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tPARTIALIGNORE  */
#line 559 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3952 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 560 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3958 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tPROGID '(' aSTRING ')'  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3964 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tPROPGET  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3970 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tPROPPUT  */
#line 563 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3976 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tPROPPUTREF  */
#line 564 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3982 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tPROXY  */
#line 565 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 3988 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tPUBLIC  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 3994 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 568 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4002 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tREADONLY  */
#line 571 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4008 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tREPRESENTAS '(' type ')'  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4014 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tREQUESTEDIT  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4020 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tRESTRICTED  */
#line 574 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4026 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tRETVAL  */
#line 575 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4032 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 576 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4038 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tSOURCE  */
#line 577 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4044 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 578 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4050 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tSTRING  */
#line 579 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4056 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tSWITCHIS '(' expr ')'  */
#line 580 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4062 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 581 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4068 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tTRANSMITAS '(' type ')'  */
#line 582 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4074 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tTHREADING '(' threading_type ')'  */
#line 583 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4080 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tUIDEFAULT  */
#line 584 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4086 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tUSESGETLASTERROR  */
#line 585 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4092 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 586 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4098 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tUUID '(' uuid_string ')'  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4104 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4110 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tV1ENUM  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4116 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tVARARG  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4122 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tVERSION '(' version ')'  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4128 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4134 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4140 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: pointer_type  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4146 "tools/widl/parser.tab.c"
    break;

  case 177: /* uuid_string: aSTRING  */
#line 599 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4154 "tools/widl/parser.tab.c"
    break;

  case 178: /* callconv: tCDECL  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4160 "tools/widl/parser.tab.c"
    break;

  case 179: /* callconv: tFASTCALL  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4166 "tools/widl/parser.tab.c"
    break;

  case 180: /* callconv: tPASCAL  */
#line 606 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4172 "tools/widl/parser.tab.c"
    break;

  case 181: /* callconv: tSTDCALL  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4178 "tools/widl/parser.tab.c"
    break;

  case 182: /* cases: %empty  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4184 "tools/widl/parser.tab.c"
    break;

  case 183: /* cases: cases case  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4190 "tools/widl/parser.tab.c"
    break;

  case 184: /* case: tCASE expr_int_const ':' union_field  */
#line 614 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4199 "tools/widl/parser.tab.c"
    break;

  case 185: /* case: tDEFAULT ':' union_field  */
#line 618 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4208 "tools/widl/parser.tab.c"
    break;

  case 186: /* enums: %empty  */
#line 624 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4214 "tools/widl/parser.tab.c"
    break;

  case 187: /* enums: enum_list ','  */
#line 625 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4220 "tools/widl/parser.tab.c"
    break;

  case 189: /* enum_list: enum  */
#line 629 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4229 "tools/widl/parser.tab.c"
    break;

  case 190: /* enum_list: enum_list ',' enum  */
#line 633 "tools/widl/parser.y"
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
#line 4244 "tools/widl/parser.tab.c"
    break;

  case 191: /* enum_member: m_attributes ident  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4252 "tools/widl/parser.tab.c"
    break;

  case 192: /* enum: enum_member '=' expr_int_const  */
#line 650 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4261 "tools/widl/parser.tab.c"
    break;

  case 193: /* enum: enum_member  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4269 "tools/widl/parser.tab.c"
    break;

  case 194: /* enumdef: tENUM t_ident '{' enums '}'  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4275 "tools/widl/parser.tab.c"
    break;

  case 195: /* m_exprs: m_expr  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4281 "tools/widl/parser.tab.c"
    break;

  case 196: /* m_exprs: m_exprs ',' m_expr  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4287 "tools/widl/parser.tab.c"
    break;

  case 197: /* m_expr: %empty  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4293 "tools/widl/parser.tab.c"
    break;

  case 199: /* expr: aNUM  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4299 "tools/widl/parser.tab.c"
    break;

  case 200: /* expr: aHEXNUM  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4305 "tools/widl/parser.tab.c"
    break;

  case 201: /* expr: aDOUBLE  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4311 "tools/widl/parser.tab.c"
    break;

  case 202: /* expr: tFALSE  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4317 "tools/widl/parser.tab.c"
    break;

  case 203: /* expr: tNULL  */
#line 674 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4323 "tools/widl/parser.tab.c"
    break;

  case 204: /* expr: tTRUE  */
#line 675 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4329 "tools/widl/parser.tab.c"
    break;

  case 205: /* expr: aSTRING  */
#line 676 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4335 "tools/widl/parser.tab.c"
    break;

  case 206: /* expr: aWSTRING  */
#line 677 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4341 "tools/widl/parser.tab.c"
    break;

  case 207: /* expr: aSQSTRING  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4347 "tools/widl/parser.tab.c"
    break;

  case 208: /* expr: aIDENTIFIER  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4353 "tools/widl/parser.tab.c"
    break;

  case 209: /* expr: expr '?' expr ':' expr  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4359 "tools/widl/parser.tab.c"
    break;

  case 210: /* expr: expr LOGICALOR expr  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4365 "tools/widl/parser.tab.c"
    break;

  case 211: /* expr: expr LOGICALAND expr  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4371 "tools/widl/parser.tab.c"
    break;

  case 212: /* expr: expr '|' expr  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4377 "tools/widl/parser.tab.c"
    break;

  case 213: /* expr: expr '^' expr  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4383 "tools/widl/parser.tab.c"
    break;

  case 214: /* expr: expr '&' expr  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4389 "tools/widl/parser.tab.c"
    break;

  case 215: /* expr: expr EQUALITY expr  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4395 "tools/widl/parser.tab.c"
    break;

  case 216: /* expr: expr INEQUALITY expr  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4401 "tools/widl/parser.tab.c"
    break;

  case 217: /* expr: expr '>' expr  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4407 "tools/widl/parser.tab.c"
    break;

  case 218: /* expr: expr '<' expr  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4413 "tools/widl/parser.tab.c"
    break;

  case 219: /* expr: expr GREATEREQUAL expr  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4419 "tools/widl/parser.tab.c"
    break;

  case 220: /* expr: expr LESSEQUAL expr  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4425 "tools/widl/parser.tab.c"
    break;

  case 221: /* expr: expr SHL expr  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4431 "tools/widl/parser.tab.c"
    break;

  case 222: /* expr: expr SHR expr  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4437 "tools/widl/parser.tab.c"
    break;

  case 223: /* expr: expr '+' expr  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4443 "tools/widl/parser.tab.c"
    break;

  case 224: /* expr: expr '-' expr  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4449 "tools/widl/parser.tab.c"
    break;

  case 225: /* expr: expr '%' expr  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4455 "tools/widl/parser.tab.c"
    break;

  case 226: /* expr: expr '*' expr  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4461 "tools/widl/parser.tab.c"
    break;

  case 227: /* expr: expr '/' expr  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4467 "tools/widl/parser.tab.c"
    break;

  case 228: /* expr: '!' expr  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4473 "tools/widl/parser.tab.c"
    break;

  case 229: /* expr: '~' expr  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4479 "tools/widl/parser.tab.c"
    break;

  case 230: /* expr: '+' expr  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4485 "tools/widl/parser.tab.c"
    break;

  case 231: /* expr: '-' expr  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4491 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: '&' expr  */
#line 703 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4497 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: '*' expr  */
#line 704 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4503 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 705 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4509 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: expr '.' aIDENTIFIER  */
#line 706 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4515 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 708 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4521 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 710 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4527 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: expr '[' expr ']'  */
#line 711 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4533 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: '(' expr ')'  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4539 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr_list_int_const: expr_int_const  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4545 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 716 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4551 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr_int_const: expr  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4560 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr_const: expr  */
#line 725 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4569 "tools/widl/parser.tab.c"
    break;

  case 244: /* fields: %empty  */
#line 731 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4575 "tools/widl/parser.tab.c"
    break;

  case 245: /* fields: fields field  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4581 "tools/widl/parser.tab.c"
    break;

  case 246: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 736 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4590 "tools/widl/parser.tab.c"
    break;

  case 247: /* field: m_attributes uniondef ';'  */
#line 740 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4599 "tools/widl/parser.tab.c"
    break;

  case 248: /* ne_union_field: s_field ';'  */
#line 747 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4605 "tools/widl/parser.tab.c"
    break;

  case 249: /* ne_union_field: attributes ';'  */
#line 748 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4611 "tools/widl/parser.tab.c"
    break;

  case 250: /* ne_union_fields: %empty  */
#line 751 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4617 "tools/widl/parser.tab.c"
    break;

  case 251: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 752 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4623 "tools/widl/parser.tab.c"
    break;

  case 252: /* union_field: s_field ';'  */
#line 756 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4629 "tools/widl/parser.tab.c"
    break;

  case 253: /* union_field: ';'  */
#line 757 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4635 "tools/widl/parser.tab.c"
    break;

  case 254: /* s_field: m_attributes decl_spec declarator  */
#line 760 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4644 "tools/widl/parser.tab.c"
    break;

  case 255: /* s_field: m_attributes structdef  */
#line 764 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4653 "tools/widl/parser.tab.c"
    break;

  case 256: /* funcdef: declaration  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4663 "tools/widl/parser.tab.c"
    break;

  case 257: /* declaration: attributes decl_spec init_declarator  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4671 "tools/widl/parser.tab.c"
    break;

  case 258: /* declaration: decl_spec init_declarator  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4679 "tools/widl/parser.tab.c"
    break;

  case 259: /* m_ident: %empty  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4685 "tools/widl/parser.tab.c"
    break;

  case 261: /* t_ident: %empty  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 4691 "tools/widl/parser.tab.c"
    break;

  case 262: /* t_ident: aIDENTIFIER  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4697 "tools/widl/parser.tab.c"
    break;

  case 263: /* t_ident: aKNOWNTYPE  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4703 "tools/widl/parser.tab.c"
    break;

  case 264: /* ident: aIDENTIFIER  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4709 "tools/widl/parser.tab.c"
    break;

  case 265: /* ident: aKNOWNTYPE  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4715 "tools/widl/parser.tab.c"
    break;

  case 266: /* base_type: tBYTE  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4721 "tools/widl/parser.tab.c"
    break;

  case 267: /* base_type: tWCHAR  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4727 "tools/widl/parser.tab.c"
    break;

  case 269: /* base_type: tSIGNED int_std  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4733 "tools/widl/parser.tab.c"
    break;

  case 270: /* base_type: tUNSIGNED int_std  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4739 "tools/widl/parser.tab.c"
    break;

  case 271: /* base_type: tUNSIGNED  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4745 "tools/widl/parser.tab.c"
    break;

  case 272: /* base_type: tFLOAT  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4751 "tools/widl/parser.tab.c"
    break;

  case 273: /* base_type: tDOUBLE  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4757 "tools/widl/parser.tab.c"
    break;

  case 274: /* base_type: tBOOLEAN  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4763 "tools/widl/parser.tab.c"
    break;

  case 275: /* base_type: tERRORSTATUST  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4769 "tools/widl/parser.tab.c"
    break;

  case 276: /* base_type: tHANDLET  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4775 "tools/widl/parser.tab.c"
    break;

  case 279: /* int_std: tINT  */
#line 818 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4781 "tools/widl/parser.tab.c"
    break;

  case 280: /* int_std: tSHORT m_int  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4787 "tools/widl/parser.tab.c"
    break;

  case 281: /* int_std: tSMALL  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4793 "tools/widl/parser.tab.c"
    break;

  case 282: /* int_std: tLONG m_int  */
#line 821 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4799 "tools/widl/parser.tab.c"
    break;

  case 283: /* int_std: tHYPER m_int  */
#line 822 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4805 "tools/widl/parser.tab.c"
    break;

  case 284: /* int_std: tINT64  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4811 "tools/widl/parser.tab.c"
    break;

  case 285: /* int_std: tCHAR  */
#line 824 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4817 "tools/widl/parser.tab.c"
    break;

  case 286: /* int_std: tINT32  */
#line 825 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4823 "tools/widl/parser.tab.c"
    break;

  case 287: /* int_std: tINT3264  */
#line 826 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4829 "tools/widl/parser.tab.c"
    break;

  case 288: /* qualified_seq: aKNOWNTYPE  */
#line 830 "tools/widl/parser.y"
                      { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4835 "tools/widl/parser.tab.c"
    break;

  case 289: /* $@3: %empty  */
#line 831 "tools/widl/parser.y"
                      { push_lookup_namespace((yyvsp[-1].str)); }
#line 4841 "tools/widl/parser.tab.c"
    break;

  case 290: /* qualified_seq: aIDENTIFIER '.' $@3 qualified_seq  */
#line 831 "tools/widl/parser.y"
                                                                   { (yyval.type) = (yyvsp[0].type); }
#line 4847 "tools/widl/parser.tab.c"
    break;

  case 291: /* qualified_type: aKNOWNTYPE  */
#line 835 "tools/widl/parser.y"
                     { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4853 "tools/widl/parser.tab.c"
    break;

  case 292: /* $@4: %empty  */
#line 836 "tools/widl/parser.y"
                     { init_lookup_namespace((yyvsp[-1].str)); }
#line 4859 "tools/widl/parser.tab.c"
    break;

  case 293: /* qualified_type: aNAMESPACE '.' $@4 qualified_seq  */
#line 836 "tools/widl/parser.y"
                                                                  { (yyval.type) = (yyvsp[0].type); }
#line 4865 "tools/widl/parser.tab.c"
    break;

  case 294: /* coclass: tCOCLASS aIDENTIFIER  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4871 "tools/widl/parser.tab.c"
    break;

  case 295: /* coclass: tCOCLASS aKNOWNTYPE  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4882 "tools/widl/parser.tab.c"
    break;

  case 296: /* coclasshdr: attributes coclass  */
#line 848 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4891 "tools/widl/parser.tab.c"
    break;

  case 297: /* coclassdef: coclasshdr '{' coclass_ints '}' semicolon_opt  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4897 "tools/widl/parser.tab.c"
    break;

  case 298: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 858 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4903 "tools/widl/parser.tab.c"
    break;

  case 299: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4909 "tools/widl/parser.tab.c"
    break;

  case 300: /* coclass_ints: %empty  */
#line 862 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 4915 "tools/widl/parser.tab.c"
    break;

  case 301: /* coclass_ints: coclass_ints coclass_int  */
#line 863 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4921 "tools/widl/parser.tab.c"
    break;

  case 302: /* coclass_int: m_attributes interfacedec  */
#line 867 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4927 "tools/widl/parser.tab.c"
    break;

  case 303: /* dispinterface: tDISPINTERFACE aIDENTIFIER  */
#line 870 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4933 "tools/widl/parser.tab.c"
    break;

  case 304: /* dispinterface: tDISPINTERFACE aKNOWNTYPE  */
#line 871 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4939 "tools/widl/parser.tab.c"
    break;

  case 305: /* dispinterfacehdr: attributes dispinterface  */
#line 874 "tools/widl/parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4951 "tools/widl/parser.tab.c"
    break;

  case 306: /* dispint_props: tPROPERTIES ':'  */
#line 883 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4957 "tools/widl/parser.tab.c"
    break;

  case 307: /* dispint_props: dispint_props s_field ';'  */
#line 884 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4963 "tools/widl/parser.tab.c"
    break;

  case 308: /* dispint_meths: tMETHODS ':'  */
#line 887 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4969 "tools/widl/parser.tab.c"
    break;

  case 309: /* dispint_meths: dispint_meths funcdef ';'  */
#line 888 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4975 "tools/widl/parser.tab.c"
    break;

  case 310: /* dispinterfacedef: dispinterfacehdr '{' dispint_props dispint_meths '}'  */
#line 894 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4983 "tools/widl/parser.tab.c"
    break;

  case 311: /* dispinterfacedef: dispinterfacehdr '{' interface ';' '}'  */
#line 898 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4991 "tools/widl/parser.tab.c"
    break;

  case 312: /* inherit: %empty  */
#line 903 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 4997 "tools/widl/parser.tab.c"
    break;

  case 313: /* inherit: ':' qualified_type  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5003 "tools/widl/parser.tab.c"
    break;

  case 314: /* interface: tINTERFACE aIDENTIFIER  */
#line 907 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5009 "tools/widl/parser.tab.c"
    break;

  case 315: /* interface: tINTERFACE aKNOWNTYPE  */
#line 908 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5015 "tools/widl/parser.tab.c"
    break;

  case 316: /* interfacehdr: attributes interface  */
#line 911 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 5025 "tools/widl/parser.tab.c"
    break;

  case 317: /* interfacedef: interfacehdr inherit '{' int_statements '}' semicolon_opt  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 5036 "tools/widl/parser.tab.c"
    break;

  case 318: /* interfacedef: interfacehdr ':' aIDENTIFIER '{' import int_statements '}' semicolon_opt  */
#line 929 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 5044 "tools/widl/parser.tab.c"
    break;

  case 319: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 932 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5050 "tools/widl/parser.tab.c"
    break;

  case 320: /* interfacedec: interface ';'  */
#line 936 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5056 "tools/widl/parser.tab.c"
    break;

  case 321: /* interfacedec: dispinterface ';'  */
#line 937 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5062 "tools/widl/parser.tab.c"
    break;

  case 322: /* module: tMODULE aIDENTIFIER  */
#line 940 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5068 "tools/widl/parser.tab.c"
    break;

  case 323: /* module: tMODULE aKNOWNTYPE  */
#line 941 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5074 "tools/widl/parser.tab.c"
    break;

  case 324: /* modulehdr: attributes module  */
#line 944 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5082 "tools/widl/parser.tab.c"
    break;

  case 325: /* moduledef: modulehdr '{' int_statements '}' semicolon_opt  */
#line 950 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5090 "tools/widl/parser.tab.c"
    break;

  case 326: /* storage_cls_spec: tEXTERN  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5096 "tools/widl/parser.tab.c"
    break;

  case 327: /* storage_cls_spec: tSTATIC  */
#line 957 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5102 "tools/widl/parser.tab.c"
    break;

  case 328: /* storage_cls_spec: tREGISTER  */
#line 958 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5108 "tools/widl/parser.tab.c"
    break;

  case 329: /* function_specifier: tINLINE  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5114 "tools/widl/parser.tab.c"
    break;

  case 330: /* type_qualifier: tCONST  */
#line 966 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5120 "tools/widl/parser.tab.c"
    break;

  case 331: /* m_type_qual_list: %empty  */
#line 969 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5126 "tools/widl/parser.tab.c"
    break;

  case 332: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5132 "tools/widl/parser.tab.c"
    break;

  case 333: /* decl_spec: type m_decl_spec_no_type  */
#line 973 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5138 "tools/widl/parser.tab.c"
    break;

  case 334: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 975 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5144 "tools/widl/parser.tab.c"
    break;

  case 335: /* m_decl_spec_no_type: %empty  */
#line 978 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5150 "tools/widl/parser.tab.c"
    break;

  case 337: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 983 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5156 "tools/widl/parser.tab.c"
    break;

  case 338: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 984 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5162 "tools/widl/parser.tab.c"
    break;

  case 339: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 985 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5168 "tools/widl/parser.tab.c"
    break;

  case 340: /* declarator: '*' m_type_qual_list declarator  */
#line 990 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5174 "tools/widl/parser.tab.c"
    break;

  case 341: /* declarator: callconv declarator  */
#line 991 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5180 "tools/widl/parser.tab.c"
    break;

  case 343: /* direct_declarator: ident  */
#line 996 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5186 "tools/widl/parser.tab.c"
    break;

  case 344: /* direct_declarator: '(' declarator ')'  */
#line 997 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5192 "tools/widl/parser.tab.c"
    break;

  case 345: /* direct_declarator: direct_declarator array  */
#line 998 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5198 "tools/widl/parser.tab.c"
    break;

  case 346: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 999 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5204 "tools/widl/parser.tab.c"
    break;

  case 347: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1005 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5210 "tools/widl/parser.tab.c"
    break;

  case 348: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1006 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5216 "tools/widl/parser.tab.c"
    break;

  case 350: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1013 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5222 "tools/widl/parser.tab.c"
    break;

  case 351: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1014 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5228 "tools/widl/parser.tab.c"
    break;

  case 352: /* m_abstract_declarator: %empty  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5234 "tools/widl/parser.tab.c"
    break;

  case 354: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1024 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5240 "tools/widl/parser.tab.c"
    break;

  case 355: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1025 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5246 "tools/widl/parser.tab.c"
    break;

  case 356: /* abstract_direct_declarator: array  */
#line 1026 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5252 "tools/widl/parser.tab.c"
    break;

  case 357: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1028 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5260 "tools/widl/parser.tab.c"
    break;

  case 358: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1032 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5268 "tools/widl/parser.tab.c"
    break;

  case 359: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1040 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5274 "tools/widl/parser.tab.c"
    break;

  case 360: /* any_declarator: callconv m_any_declarator  */
#line 1041 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5280 "tools/widl/parser.tab.c"
    break;

  case 362: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1048 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5286 "tools/widl/parser.tab.c"
    break;

  case 363: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1049 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5292 "tools/widl/parser.tab.c"
    break;

  case 364: /* m_any_declarator: %empty  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5298 "tools/widl/parser.tab.c"
    break;

  case 366: /* any_direct_declarator: ident  */
#line 1061 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5304 "tools/widl/parser.tab.c"
    break;

  case 367: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5310 "tools/widl/parser.tab.c"
    break;

  case 368: /* any_direct_declarator: any_direct_declarator array  */
#line 1063 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5316 "tools/widl/parser.tab.c"
    break;

  case 369: /* any_direct_declarator: array  */
#line 1064 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5322 "tools/widl/parser.tab.c"
    break;

  case 370: /* any_direct_declarator: '(' m_args ')'  */
#line 1066 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5330 "tools/widl/parser.tab.c"
    break;

  case 371: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1070 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5338 "tools/widl/parser.tab.c"
    break;

  case 372: /* declarator_list: declarator  */
#line 1076 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5344 "tools/widl/parser.tab.c"
    break;

  case 373: /* declarator_list: declarator_list ',' declarator  */
#line 1077 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5350 "tools/widl/parser.tab.c"
    break;

  case 374: /* m_bitfield: %empty  */
#line 1080 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5356 "tools/widl/parser.tab.c"
    break;

  case 375: /* m_bitfield: ':' expr_const  */
#line 1081 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5362 "tools/widl/parser.tab.c"
    break;

  case 376: /* struct_declarator: any_declarator m_bitfield  */
#line 1084 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5371 "tools/widl/parser.tab.c"
    break;

  case 377: /* struct_declarator_list: struct_declarator  */
#line 1091 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5377 "tools/widl/parser.tab.c"
    break;

  case 378: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1093 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5383 "tools/widl/parser.tab.c"
    break;

  case 379: /* init_declarator: declarator  */
#line 1097 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5389 "tools/widl/parser.tab.c"
    break;

  case 380: /* init_declarator: declarator '=' expr_const  */
#line 1098 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5395 "tools/widl/parser.tab.c"
    break;

  case 381: /* threading_type: tAPARTMENT  */
#line 1102 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5401 "tools/widl/parser.tab.c"
    break;

  case 382: /* threading_type: tNEUTRAL  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5407 "tools/widl/parser.tab.c"
    break;

  case 383: /* threading_type: tSINGLE  */
#line 1104 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5413 "tools/widl/parser.tab.c"
    break;

  case 384: /* threading_type: tFREE  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5419 "tools/widl/parser.tab.c"
    break;

  case 385: /* threading_type: tBOTH  */
#line 1106 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5425 "tools/widl/parser.tab.c"
    break;

  case 386: /* pointer_type: tREF  */
#line 1110 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5431 "tools/widl/parser.tab.c"
    break;

  case 387: /* pointer_type: tUNIQUE  */
#line 1111 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5437 "tools/widl/parser.tab.c"
    break;

  case 388: /* pointer_type: tPTR  */
#line 1112 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5443 "tools/widl/parser.tab.c"
    break;

  case 389: /* structdef: tSTRUCT t_ident '{' fields '}'  */
#line 1115 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5449 "tools/widl/parser.tab.c"
    break;

  case 390: /* type: tVOID  */
#line 1118 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5455 "tools/widl/parser.tab.c"
    break;

  case 391: /* type: qualified_type  */
#line 1119 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5461 "tools/widl/parser.tab.c"
    break;

  case 392: /* type: base_type  */
#line 1120 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5467 "tools/widl/parser.tab.c"
    break;

  case 393: /* type: enumdef  */
#line 1121 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5473 "tools/widl/parser.tab.c"
    break;

  case 394: /* type: tENUM aIDENTIFIER  */
#line 1122 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5479 "tools/widl/parser.tab.c"
    break;

  case 395: /* type: structdef  */
#line 1123 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5485 "tools/widl/parser.tab.c"
    break;

  case 396: /* type: tSTRUCT aIDENTIFIER  */
#line 1124 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5491 "tools/widl/parser.tab.c"
    break;

  case 397: /* type: uniondef  */
#line 1125 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5497 "tools/widl/parser.tab.c"
    break;

  case 398: /* type: tUNION aIDENTIFIER  */
#line 1126 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5503 "tools/widl/parser.tab.c"
    break;

  case 399: /* type: tSAFEARRAY '(' type ')'  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5509 "tools/widl/parser.tab.c"
    break;

  case 400: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1131 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5518 "tools/widl/parser.tab.c"
    break;

  case 401: /* uniondef: tUNION t_ident '{' ne_union_fields '}'  */
#line 1138 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5524 "tools/widl/parser.tab.c"
    break;

  case 402: /* uniondef: tUNION t_ident tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1141 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5530 "tools/widl/parser.tab.c"
    break;

  case 403: /* version: aNUM  */
#line 1145 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5536 "tools/widl/parser.tab.c"
    break;

  case 404: /* version: aNUM '.' aNUM  */
#line 1146 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5542 "tools/widl/parser.tab.c"
    break;

  case 405: /* version: aHEXNUM  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5548 "tools/widl/parser.tab.c"
    break;

  case 410: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1160 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5556 "tools/widl/parser.tab.c"
    break;

  case 411: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1165 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5566 "tools/widl/parser.tab.c"
    break;

  case 412: /* acf_attributes: %empty  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5572 "tools/widl/parser.tab.c"
    break;

  case 413: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1173 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5578 "tools/widl/parser.tab.c"
    break;

  case 414: /* acf_attribute_list: acf_attribute  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5584 "tools/widl/parser.tab.c"
    break;

  case 415: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1177 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5590 "tools/widl/parser.tab.c"
    break;

  case 416: /* acf_attribute: tENCODE  */
#line 1180 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5596 "tools/widl/parser.tab.c"
    break;

  case 417: /* acf_attribute: tDECODE  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5602 "tools/widl/parser.tab.c"
    break;

  case 418: /* acf_attribute: tEXPLICITHANDLE  */
#line 1182 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5608 "tools/widl/parser.tab.c"
    break;


#line 5612 "tools/widl/parser.tab.c"

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

#line 1184 "tools/widl/parser.y"


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
    unsigned int on_enum_member : 1;
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
    /* attr                        { D ACF I Fn ARG T En Enm St Un Fi L  DI M  C  <display name> } */
    /* ATTR_AGGREGATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "aggregatable" },
    /* ATTR_ANNOTATION */          { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTROL */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, "control" },
    /* ATTR_DECODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MAYBE */               { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "source" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
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
