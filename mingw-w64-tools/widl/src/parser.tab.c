/* A Bison parser, made by GNU Bison 3.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.1"

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

/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

static typelib_t *current_typelib;


#line 203 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    aIDENTIFIER = 258,
    aPRAGMA = 259,
    aKNOWNTYPE = 260,
    aNUM = 261,
    aHEXNUM = 262,
    aDOUBLE = 263,
    aSTRING = 264,
    aWSTRING = 265,
    aSQSTRING = 266,
    aUUID = 267,
    aEOF = 268,
    aACF = 269,
    SHL = 270,
    SHR = 271,
    MEMBERPTR = 272,
    EQUALITY = 273,
    INEQUALITY = 274,
    GREATEREQUAL = 275,
    LESSEQUAL = 276,
    LOGICALOR = 277,
    LOGICALAND = 278,
    ELLIPSIS = 279,
    tAGGREGATABLE = 280,
    tALLOCATE = 281,
    tANNOTATION = 282,
    tAPPOBJECT = 283,
    tASYNC = 284,
    tASYNCUUID = 285,
    tAUTOHANDLE = 286,
    tBINDABLE = 287,
    tBOOLEAN = 288,
    tBROADCAST = 289,
    tBYTE = 290,
    tBYTECOUNT = 291,
    tCALLAS = 292,
    tCALLBACK = 293,
    tCASE = 294,
    tCDECL = 295,
    tCHAR = 296,
    tCOCLASS = 297,
    tCODE = 298,
    tCOMMSTATUS = 299,
    tCONST = 300,
    tCONTEXTHANDLE = 301,
    tCONTEXTHANDLENOSERIALIZE = 302,
    tCONTEXTHANDLESERIALIZE = 303,
    tCONTROL = 304,
    tCPPQUOTE = 305,
    tDECODE = 306,
    tDEFAULT = 307,
    tDEFAULTBIND = 308,
    tDEFAULTCOLLELEM = 309,
    tDEFAULTVALUE = 310,
    tDEFAULTVTABLE = 311,
    tDISABLECONSISTENCYCHECK = 312,
    tDISPLAYBIND = 313,
    tDISPINTERFACE = 314,
    tDLLNAME = 315,
    tDOUBLE = 316,
    tDUAL = 317,
    tENABLEALLOCATE = 318,
    tENCODE = 319,
    tENDPOINT = 320,
    tENTRY = 321,
    tENUM = 322,
    tERRORSTATUST = 323,
    tEXPLICITHANDLE = 324,
    tEXTERN = 325,
    tFALSE = 326,
    tFASTCALL = 327,
    tFAULTSTATUS = 328,
    tFLOAT = 329,
    tFORCEALLOCATE = 330,
    tHANDLE = 331,
    tHANDLET = 332,
    tHELPCONTEXT = 333,
    tHELPFILE = 334,
    tHELPSTRING = 335,
    tHELPSTRINGCONTEXT = 336,
    tHELPSTRINGDLL = 337,
    tHIDDEN = 338,
    tHYPER = 339,
    tID = 340,
    tIDEMPOTENT = 341,
    tIGNORE = 342,
    tIIDIS = 343,
    tIMMEDIATEBIND = 344,
    tIMPLICITHANDLE = 345,
    tIMPORT = 346,
    tIMPORTLIB = 347,
    tIN = 348,
    tIN_LINE = 349,
    tINLINE = 350,
    tINPUTSYNC = 351,
    tINT = 352,
    tINT32 = 353,
    tINT3264 = 354,
    tINT64 = 355,
    tINTERFACE = 356,
    tLCID = 357,
    tLENGTHIS = 358,
    tLIBRARY = 359,
    tLICENSED = 360,
    tLOCAL = 361,
    tLONG = 362,
    tMAYBE = 363,
    tMESSAGE = 364,
    tMETHODS = 365,
    tMODULE = 366,
    tNAMESPACE = 367,
    tNOCODE = 368,
    tNONBROWSABLE = 369,
    tNONCREATABLE = 370,
    tNONEXTENSIBLE = 371,
    tNOTIFY = 372,
    tNOTIFYFLAG = 373,
    tNULL = 374,
    tOBJECT = 375,
    tODL = 376,
    tOLEAUTOMATION = 377,
    tOPTIMIZE = 378,
    tOPTIONAL = 379,
    tOUT = 380,
    tPARTIALIGNORE = 381,
    tPASCAL = 382,
    tPOINTERDEFAULT = 383,
    tPRAGMA_WARNING = 384,
    tPROGID = 385,
    tPROPERTIES = 386,
    tPROPGET = 387,
    tPROPPUT = 388,
    tPROPPUTREF = 389,
    tPROXY = 390,
    tPTR = 391,
    tPUBLIC = 392,
    tRANGE = 393,
    tREADONLY = 394,
    tREF = 395,
    tREGISTER = 396,
    tREPRESENTAS = 397,
    tREQUESTEDIT = 398,
    tRESTRICTED = 399,
    tRETVAL = 400,
    tSAFEARRAY = 401,
    tSHORT = 402,
    tSIGNED = 403,
    tSIZEIS = 404,
    tSIZEOF = 405,
    tSMALL = 406,
    tSOURCE = 407,
    tSTATIC = 408,
    tSTDCALL = 409,
    tSTRICTCONTEXTHANDLE = 410,
    tSTRING = 411,
    tSTRUCT = 412,
    tSWITCH = 413,
    tSWITCHIS = 414,
    tSWITCHTYPE = 415,
    tTHREADING = 416,
    tTRANSMITAS = 417,
    tTRUE = 418,
    tTYPEDEF = 419,
    tUIDEFAULT = 420,
    tUNION = 421,
    tUNIQUE = 422,
    tUNSIGNED = 423,
    tUSESGETLASTERROR = 424,
    tUSERMARSHAL = 425,
    tUUID = 426,
    tV1ENUM = 427,
    tVARARG = 428,
    tVERSION = 429,
    tVIPROGID = 430,
    tVOID = 431,
    tWCHAR = 432,
    tWIREMARSHAL = 433,
    tAPARTMENT = 434,
    tNEUTRAL = 435,
    tSINGLE = 436,
    tFREE = 437,
    tBOTH = 438,
    CAST = 439,
    PPTR = 440,
    POS = 441,
    NEG = 442,
    ADDRESSOF = 443
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 129 "parser.y" /* yacc.c:355  */

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

#line 458 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);



/* Copy the second part of user declarations.  */

#line 475 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
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
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   3047

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  213
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  113
/* YYNRULES -- Number of rules.  */
#define YYNRULES  410
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  718

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   443

#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   197,     2,     2,     2,   196,   189,     2,
     210,   211,   194,   193,   184,   192,   204,   195,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   186,   209,
     190,   212,   191,   185,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   205,     2,   206,   188,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   207,   187,   208,   198,     2,     2,     2,
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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   199,
     200,   201,   202,   203
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   315,   315,   329,   329,   331,   332,   332,   334,   335,
     336,   339,   342,   343,   344,   347,   348,   349,   349,   351,
     352,   353,   356,   357,   358,   359,   362,   363,   366,   367,
     371,   372,   373,   374,   375,   376,   377,   380,   391,   392,
     396,   397,   398,   399,   400,   401,   402,   403,   404,   407,
     409,   417,   423,   427,   428,   430,   434,   438,   439,   442,
     443,   446,   447,   451,   456,   463,   467,   468,   471,   472,
     476,   479,   480,   481,   484,   485,   488,   489,   490,   491,
     492,   493,   494,   495,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   527,   528,   529,   530,   531,
     532,   533,   534,   535,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   567,   568,   569,   570,   571,   572,   573,   574,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   590,   594,   595,   600,   601,
     602,   603,   606,   607,   610,   614,   620,   621,   622,   625,
     629,   641,   645,   650,   653,   654,   657,   658,   661,   662,
     663,   664,   665,   666,   667,   668,   669,   670,   671,   672,
     673,   674,   675,   676,   677,   678,   679,   680,   681,   682,
     683,   684,   685,   686,   687,   688,   689,   690,   691,   692,
     693,   694,   695,   696,   697,   698,   700,   702,   703,   706,
     707,   710,   716,   722,   723,   726,   731,   738,   739,   742,
     743,   747,   748,   751,   755,   761,   769,   773,   778,   779,
     782,   783,   784,   787,   789,   792,   793,   794,   795,   796,
     797,   798,   799,   800,   801,   802,   805,   806,   809,   810,
     811,   812,   813,   814,   815,   816,   817,   820,   821,   829,
     835,   839,   842,   843,   847,   850,   851,   854,   863,   864,
     867,   868,   871,   877,   883,   884,   887,   888,   891,   898,
     907,   912,   916,   917,   920,   921,   924,   929,   936,   937,
     938,   942,   946,   949,   950,   953,   954,   958,   959,   963,
     964,   965,   969,   971,   972,   976,   977,   978,   979,   984,
     986,   987,   992,   994,   998,   999,  1004,  1005,  1006,  1007,
    1011,  1019,  1021,  1022,  1027,  1029,  1033,  1034,  1041,  1042,
    1043,  1044,  1045,  1049,  1056,  1057,  1060,  1061,  1064,  1071,
    1072,  1077,  1078,  1082,  1083,  1084,  1085,  1086,  1090,  1091,
    1092,  1095,  1098,  1099,  1100,  1101,  1102,  1103,  1104,  1105,
    1106,  1107,  1110,  1117,  1119,  1125,  1126,  1127,  1130,  1132,
    1134,  1136,  1139,  1144,  1152,  1153,  1156,  1157,  1160,  1161,
    1162
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "aIDENTIFIER", "aPRAGMA", "aKNOWNTYPE",
  "aNUM", "aHEXNUM", "aDOUBLE", "aSTRING", "aWSTRING", "aSQSTRING",
  "aUUID", "aEOF", "aACF", "SHL", "SHR", "MEMBERPTR", "EQUALITY",
  "INEQUALITY", "GREATEREQUAL", "LESSEQUAL", "LOGICALOR", "LOGICALAND",
  "ELLIPSIS", "tAGGREGATABLE", "tALLOCATE", "tANNOTATION", "tAPPOBJECT",
  "tASYNC", "tASYNCUUID", "tAUTOHANDLE", "tBINDABLE", "tBOOLEAN",
  "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS", "tCALLBACK", "tCASE",
  "tCDECL", "tCHAR", "tCOCLASS", "tCODE", "tCOMMSTATUS", "tCONST",
  "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE", "tCONTEXTHANDLESERIALIZE",
  "tCONTROL", "tCPPQUOTE", "tDECODE", "tDEFAULT", "tDEFAULTBIND",
  "tDEFAULTCOLLELEM", "tDEFAULTVALUE", "tDEFAULTVTABLE",
  "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND", "tDISPINTERFACE", "tDLLNAME",
  "tDOUBLE", "tDUAL", "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY",
  "tENUM", "tERRORSTATUST", "tEXPLICITHANDLE", "tEXTERN", "tFALSE",
  "tFASTCALL", "tFAULTSTATUS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE",
  "tHANDLET", "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING",
  "tHELPSTRINGCONTEXT", "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID",
  "tIDEMPOTENT", "tIGNORE", "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE",
  "tIMPORT", "tIMPORTLIB", "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC",
  "tINT", "tINT32", "tINT3264", "tINT64", "tINTERFACE", "tLCID",
  "tLENGTHIS", "tLIBRARY", "tLICENSED", "tLOCAL", "tLONG", "tMAYBE",
  "tMESSAGE", "tMETHODS", "tMODULE", "tNAMESPACE", "tNOCODE",
  "tNONBROWSABLE", "tNONCREATABLE", "tNONEXTENSIBLE", "tNOTIFY",
  "tNOTIFYFLAG", "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE",
  "tOPTIONAL", "tOUT", "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT",
  "tPRAGMA_WARNING", "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT",
  "tPROPPUTREF", "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY",
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tRESTRICTED",
  "tRETVAL", "tSAFEARRAY", "tSHORT", "tSIGNED", "tSIZEIS", "tSIZEOF",
  "tSMALL", "tSOURCE", "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE",
  "tSTRING", "tSTRUCT", "tSWITCH", "tSWITCHIS", "tSWITCHTYPE",
  "tTHREADING", "tTRANSMITAS", "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION",
  "tUNIQUE", "tUNSIGNED", "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID",
  "tV1ENUM", "tVARARG", "tVERSION", "tVIPROGID", "tVOID", "tWCHAR",
  "tWIREMARSHAL", "tAPARTMENT", "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH",
  "','", "'?'", "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'",
  "'*'", "'/'", "'%'", "'!'", "'~'", "CAST", "PPTR", "POS", "NEG",
  "ADDRESSOF", "'.'", "'['", "']'", "'{'", "'}'", "';'", "'('", "')'",
  "'='", "$accept", "input", "m_acf", "gbl_statements", "$@1",
  "imp_statements", "$@2", "int_statements", "semicolon_opt", "statement",
  "pragma_warning", "warnings", "typedecl", "cppquote", "import_start",
  "import", "importlib", "libraryhdr", "library_start", "librarydef",
  "m_args", "arg_list", "args", "arg", "array", "m_attributes",
  "attributes", "attrib_list", "str_list", "attribute", "uuid_string",
  "callconv", "cases", "case", "enums", "enum_list", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident", "t_ident",
  "ident", "base_type", "m_int", "int_std", "coclass", "coclasshdr",
  "coclassdef", "namespacedef", "coclass_ints", "coclass_int",
  "dispinterface", "dispinterfacehdr", "dispint_props", "dispint_meths",
  "dispinterfacedef", "inherit", "interface", "interfacehdr",
  "interfacedef", "interfacedec", "module", "modulehdr", "moduledef",
  "storage_cls_spec", "function_specifier", "type_qualifier",
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
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
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
     435,   436,   437,   438,    44,    63,    58,   124,    94,    38,
      60,    62,    45,    43,    42,    47,    37,    33,   126,   439,
     440,   441,   442,   443,    46,    91,    93,   123,   125,    59,
      40,    41,    61
};
# endif

#define YYPACT_NINF -560

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-560)))

#define YYTABLE_NINF -405

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -560,    94,  1606,  -560,  -560,  -560,   -57,  -560,  -560,  -560,
     147,  -560,   -89,   165,  -560,   169,  -560,  -560,  -560,  -560,
      35,   149,  -560,  -560,  -560,  -560,  -560,   172,    35,   164,
     -34,  -560,   -29,    35,   333,  -560,  -560,   192,   197,   333,
    -560,  -560,  2869,  -560,  -560,  -560,   -27,  -560,  -560,  -560,
    -560,  -560,    21,  2567,   -13,   -10,  -560,  -560,     9,   -36,
    -560,     2,    12,    38,    23,    46,    41,  -560,  -560,    57,
    -560,   128,   128,   128,   175,  2716,    76,   128,    81,    88,
      61,  -560,   -57,   219,  -560,  -560,   315,  -560,  -560,    15,
    -560,   121,  -560,  -560,   123,  -560,  -560,  -560,  -560,   331,
    2716,  -560,  -560,    58,   129,   -94,  -112,  -560,  -560,   130,
    -560,  -560,   131,  -560,  -560,  -560,   132,   134,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,   138,  -560,
    -560,  -560,   140,  -560,  -560,  -560,   141,   146,  -560,  -560,
    -560,  -560,   150,   151,   153,   157,   158,  -560,   160,  -560,
    -560,   161,  -560,   163,  -560,  -560,   166,   167,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   168,  -560,  -560,  -560,   170,   171,  -560,  -560,  -560,
    -560,  -560,  -560,   174,  -560,  -560,   185,  -560,  -560,  -560,
     187,  -560,  -560,  -560,   188,   189,   190,   191,  -560,  -560,
    -560,   195,   196,  -560,  -560,   206,   209,   211,  -132,  -560,
    -560,  -560,  1736,   851,   133,   267,   270,   273,   283,   286,
     220,   148,  -560,  -560,  -560,  -560,   175,   173,   216,  -560,
    -560,  -560,  -560,  -560,   -42,  -560,  -560,  -560,   290,   222,
    -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,   175,   175,  -560,   127,  -101,  -560,  -560,  -560,
     128,  -560,  -560,  -560,  -560,  -560,  -560,  -119,  -560,  -560,
     374,   215,   291,  -560,   249,   225,  -560,   227,  -560,   429,
      84,   291,   710,   710,   430,   432,   710,   710,   435,   458,
     710,   461,   710,   710,  2097,   710,   710,   463,   -68,   464,
     710,  2716,   710,   710,  2716,   -38,  2716,  2716,    84,   324,
     466,  2716,  2869,   271,  -560,   268,  -560,  -560,  -560,   272,
    -560,   278,  -560,  -560,  -560,    23,  2612,  -560,   279,  -560,
    -560,  -560,  -560,   279,   -91,  -560,  -560,  -122,  -560,   293,
     -65,   280,   284,  -560,  -560,  1193,    52,   266,  -560,   710,
     542,  2097,  -560,  -560,    61,  -560,   285,  -560,   282,   303,
    -560,   281,   488,  -560,   -49,   133,   -39,   294,  -560,  -560,
     295,   296,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,   305,  -560,   710,   710,   710,   710,   710,   710,   596,
    2299,  -135,  -560,  2299,   306,   307,  -560,  -111,   308,   309,
     314,   316,   317,   323,   326,   371,   327,  2612,    77,   328,
    -106,  -560,  2299,   329,   330,   332,   311,   335,  -100,  1397,
     343,  -560,  -560,  -560,  -560,  -560,   344,   346,   359,   360,
     292,  -560,   361,   362,   367,  -560,  2869,   492,  -560,  -560,
    -560,   175,    23,   -11,  -560,  1089,  -560,   340,  2612,   370,
    1476,   334,   413,  1297,    23,  -560,  2612,  -560,  -560,  -560,
    -560,   611,  -560,  2190,   377,   402,  -560,  -560,  -560,   380,
    -560,   291,   710,  -560,    18,  -560,  2612,  -560,   378,  -560,
     384,  -560,   389,  -560,  -560,  -560,  2612,    36,    36,    36,
      36,    36,    36,  2102,   496,   710,   710,   597,   710,   710,
     710,   710,   710,   710,   710,   710,   710,   710,   710,   710,
     710,   710,   710,   710,   710,   605,   710,   710,  -560,  -560,
    -560,   600,  -560,  -560,  -560,  -560,  -560,  -560,  -560,  -560,
    -560,  -560,    77,  -560,  1833,  -560,    77,  -560,  -560,  -560,
     -87,  -560,   710,  -560,  -560,  -560,  -560,   710,  -560,  -560,
    -560,  -560,  -560,  -560,  -560,  -560,   604,  -560,  -560,  -560,
    -560,   400,  -560,  -560,   428,  -560,  -560,  -560,  -560,   175,
     116,  -560,  -560,  2612,   407,  -560,  -560,  -560,    23,  -560,
    -560,  -560,  -560,  2009,   419,   417,   380,  -560,  -560,  -560,
    -560,    77,   418,   291,  -560,  -560,   496,  -560,  -560,  1921,
    -560,   496,  -560,   415,   -74,   318,   318,  -560,   575,   575,
     482,   482,  2318,  2337,  2260,  2372,  2394,   218,   482,   482,
      54,    54,    36,    36,    36,  -560,  2212,  -560,  -560,  -560,
      74,  -560,   421,    77,   422,  -560,  2097,  -560,  -560,   424,
    -560,    23,   970,   175,  -560,  -560,  1401,  -560,  -560,  -560,
     623,  -560,  -560,   444,  -560,  -103,  -560,   431,  -560,   425,
     375,  -560,   434,    77,   437,  -560,   710,  2097,  -560,   710,
    -560,  -560,    74,  -560,  -560,  -560,   440,  -560,  -560,  -560,
    -560,    23,   433,   710,  -560,    77,  -560,  -560,  -560,  -560,
      74,  -560,  -560,  -560,    36,   441,  2299,  -560,  -560,  -560,
    -560,  -560,  -560,    -1,  -560,  -560,   710,   453,  -560,  -560,
     468,   -58,   -58,  -560,  -560,   447,  -560,  -560
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       5,     0,     3,     1,    35,   383,   398,   273,   265,   284,
       0,   322,     0,     0,   272,   260,   274,   318,   271,   275,
     276,     0,   321,   278,   285,   286,   283,     0,   276,     0,
       0,   320,     0,   276,     0,   280,   319,   260,   260,   270,
     382,   266,    76,     2,    14,    36,     0,    30,    15,    33,
      15,    13,     0,    69,   385,     0,   384,   267,     0,     0,
      11,     0,     0,     0,    28,     0,   304,     9,     8,     0,
      12,   327,   327,   327,     0,     0,   387,   327,     0,   389,
       0,     4,   398,     0,   287,   288,     0,   295,   296,   386,
     262,     0,   277,   282,     0,   306,   307,   281,   291,     0,
       0,   279,   268,   388,     0,   390,     0,   269,    77,     0,
      79,    80,     0,    81,    82,    83,     0,     0,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     0,    97,
      98,    99,     0,   101,   102,   103,     0,     0,   106,   107,
     108,   109,     0,     0,     0,     0,     0,   115,     0,   117,
     118,     0,   120,     0,   122,   123,   126,     0,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,     0,   141,   142,   143,     0,     0,   146,   147,   148,
     149,   380,   150,     0,   152,   378,     0,   154,   155,   156,
       0,   158,   159,   160,     0,     0,     0,     0,   165,   379,
     166,     0,     0,   170,   171,     0,     0,     0,     0,    71,
     175,    31,    68,    68,    68,   260,     0,     0,   260,   260,
       0,   385,   289,   297,   308,   316,     0,   387,   389,    32,
      10,   292,     6,   313,     0,    29,   311,   312,     0,     0,
      26,   331,   328,   330,   329,   263,   264,   178,   179,   180,
     181,   323,     0,     0,   335,   371,   334,   257,   385,   387,
     327,   389,   325,    34,   409,   408,   410,     0,   406,   399,
       0,     0,   186,    50,     0,     0,   243,     0,   249,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,     0,     0,
       0,     0,   196,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    76,    70,    51,     0,    23,    24,    25,     0,
      21,     0,    19,    16,    22,    28,     0,    69,   386,    53,
      54,   314,   315,   388,   390,    55,   256,    68,     5,     0,
      68,     0,     0,   305,    26,    68,     0,     0,   333,     0,
       0,    57,   337,   326,     0,   405,     0,    49,     0,   188,
     189,   192,     0,   391,    68,    68,    68,     0,   177,   176,
       0,     0,   207,   198,   199,   200,   204,   205,   206,   201,
     202,     0,   203,     0,     0,     0,     0,     0,     0,     0,
     241,     0,   239,   242,     0,     0,    74,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     0,
       0,   194,   197,     0,     0,     0,     0,     0,     0,     0,
       0,   373,   374,   375,   376,   377,     0,     0,     0,     0,
     395,   397,     0,     0,     0,    72,    76,     0,    20,    17,
      56,     0,    28,     0,   293,    68,   298,     0,     0,     0,
       0,     0,     0,    68,    28,    27,    69,   324,   332,   336,
     372,     0,    67,     0,     0,    61,    58,    59,   407,   400,
     193,   187,     0,    38,     0,   381,     0,   244,     0,   393,
      69,   250,     0,    78,   169,    84,     0,   231,   230,   229,
     232,   227,   228,     0,   344,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    96,
     100,     0,   104,   105,   110,   111,   112,   113,   114,   116,
     119,   121,   356,   323,    57,   361,   356,   358,   357,    64,
     353,   125,   196,   124,   140,   144,   145,     0,   153,   157,
     161,   162,   164,   163,   167,   168,     0,   172,   173,   174,
      73,     0,    15,   364,   392,   290,   294,     7,   300,     0,
     387,   299,   302,     0,     0,   255,   303,    26,    28,   317,
      66,    65,   338,     0,   404,     0,   400,   190,   191,    39,
      37,     0,   389,   258,   248,   247,   344,   238,   323,    57,
     348,   344,   345,     0,   341,   220,   221,   233,   214,   215,
     218,   219,   209,   210,     0,   211,   212,   213,   217,   216,
     223,   222,   225,   226,   224,   234,     0,   240,    75,    63,
     356,   323,     0,   356,     0,   352,    57,   360,   195,     0,
     396,    28,    68,     0,   253,   301,    68,   309,    62,    60,
       0,   403,   401,   366,   369,     0,   246,     0,   259,     0,
     344,   323,     0,   356,     0,   340,     0,    57,   347,     0,
     237,   351,   356,   362,   355,   359,     0,   151,    52,    18,
     365,    28,     0,     0,   368,     0,   245,   182,   236,   339,
     356,   349,   343,   346,   235,     0,   208,   354,   363,   310,
     402,   367,   370,     0,   342,   350,     0,     0,   394,   183,
       0,    68,    68,   252,   185,     0,   184,   251
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -560,  -560,  -560,   320,  -560,   -46,  -560,  -317,  -315,     0,
    -560,  -560,  -560,  -560,  -560,   208,  -560,  -560,  -560,    10,
    -514,  -560,  -560,  -261,  -242,  -203,    -2,  -560,  -560,  -272,
     354,   -66,  -560,  -560,  -560,  -560,   198,    13,   366,   137,
    -195,  -560,  -264,  -280,  -560,  -560,  -560,  -560,   -41,  -237,
    -560,   233,  -560,    25,   -69,  -560,    42,    99,     5,  -560,
      11,    17,  -560,  -560,   619,  -560,  -560,  -560,  -560,  -560,
     -18,  -560,    19,    16,  -560,  -560,    20,  -560,  -560,  -307,
    -496,   -52,   -43,   -30,  -236,  -560,  -560,  -560,  -540,  -560,
    -559,  -560,    51,  -560,  -560,  -560,     3,  -560,   459,  -560,
     391,     1,   -50,  -560,     7,  -560,   615,   112,  -560,  -560,
     115,  -560,   348
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    43,     2,   338,   212,   562,   345,   236,   316,
      45,   474,    46,    47,    48,    49,   317,   220,    50,   318,
     464,   465,   466,   467,   535,    52,   327,   208,   397,   209,
     370,   536,   703,   709,   358,   359,   360,   258,   410,   411,
     390,   391,   392,   394,   364,   477,   481,   366,   714,   715,
     574,    55,   657,    91,   537,    56,    93,    57,   319,    59,
     320,   321,   337,   444,    62,    63,   340,   450,    64,   239,
      65,    66,   322,   323,   225,    69,   324,    71,    72,    73,
     346,    74,   241,    75,   255,   256,   602,   664,   603,   604,
     538,   634,   539,   540,   564,   684,   654,   655,   257,   426,
     210,   259,    77,    78,   261,   432,    81,   585,   586,    82,
      83,   267,   268
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,   226,    44,    76,   213,   254,   398,    58,   253,    79,
     440,   326,    51,    60,   352,    54,   347,   348,    68,    61,
     632,    67,    70,   399,   589,   260,   402,   453,   404,   243,
     244,   409,   653,   406,   262,   224,   416,   630,   706,   457,
     435,   242,   242,   242,  -404,   447,   277,   242,    13,   517,
     275,   707,   312,   497,   227,   245,   659,   246,   222,    27,
     228,   665,   104,   106,  -261,   354,   221,  -261,   181,   460,
      97,   497,   185,   521,   313,   101,   518,   245,   542,   246,
     245,   685,   246,    42,   542,   662,   442,   355,   393,   339,
      27,   393,   247,   368,     3,   278,   369,    11,   405,   199,
     522,   412,   660,   449,   350,   543,   686,   412,   419,   351,
     458,   549,   264,  -261,   247,   -45,  -261,   247,   350,    11,
     689,    86,   676,   636,   248,   265,   653,   565,   478,   482,
     266,   350,    92,   102,   443,   672,   667,   448,   107,   579,
      42,   421,   422,   423,   424,   425,   248,    42,    80,   248,
      84,   713,    85,   695,   393,   463,    42,   254,    94,   475,
     253,   476,   448,   448,   560,   690,    42,    98,    87,   479,
      88,   231,    89,    11,    90,    95,    99,    96,   245,   249,
     246,   100,   211,   254,   254,   214,   253,   253,   487,   488,
     489,   490,   491,   492,   493,   103,   -40,    90,    17,   229,
     105,   249,    90,   361,   249,   563,   250,   708,   588,   232,
      53,    53,   371,    76,    76,   247,   341,   353,   230,    79,
      79,   233,  -261,    22,   -41,    54,    54,   238,   250,   590,
     242,   250,   235,   495,   496,   497,   498,   499,   500,   501,
     515,   516,   408,   104,   106,   234,   251,   248,   512,   513,
     514,   417,   600,   627,   420,   237,   427,   428,   515,   516,
     646,   434,   252,   647,   240,  -261,   490,   -43,   533,    31,
     328,   533,    90,   329,   441,   330,   331,   254,   332,   350,
     253,    36,   350,   639,   534,   -42,   333,   534,    90,   334,
     263,    90,   407,   342,   245,   343,   246,   -44,   637,   408,
     605,   606,   249,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     270,   626,   649,   457,   271,  -254,   678,  -254,   272,   250,
     430,   431,   273,   644,   274,   497,   276,   494,    42,   349,
     279,   280,   281,   456,   282,   455,    76,   412,   283,   407,
     284,   285,    79,   457,   600,   532,   286,   -46,    54,   600,
     287,   288,   668,   289,   480,   457,   699,   290,   291,   251,
     292,   293,   254,   294,     9,   253,   295,   296,   297,   356,
     298,   299,   -47,   457,   300,   252,   495,   496,   497,   498,
     499,   500,   501,   502,   503,   301,   569,   302,   303,   304,
     305,   306,   361,   701,   226,   307,   308,   680,   508,   509,
     510,   511,   512,   513,   514,   247,   309,    20,   600,   310,
      11,   311,   515,   516,   591,   -48,   357,   335,   601,   344,
      23,    24,    25,    26,   596,   362,   363,   365,   367,   395,
      28,   396,   710,    53,   400,    44,    76,   248,   573,   570,
      58,   456,    79,   455,    76,    51,    60,   227,    54,   566,
      79,    68,    61,   228,    67,    70,    54,   401,   633,   221,
     403,   694,   413,   415,   696,   433,   436,   459,   437,   446,
      33,   438,   408,   592,    35,   439,  -261,   471,   393,   451,
     470,   452,   469,   472,   473,   547,   556,   495,   496,   497,
     254,   561,   249,   253,    21,   483,   484,   485,   448,   448,
     510,   511,   512,   513,   514,   486,   642,   519,   520,   523,
     524,   226,   515,   516,   658,   525,   568,   526,   527,   250,
     601,   408,   407,   663,   528,   601,   247,   529,   531,   541,
     544,   545,   576,   546,   584,   372,   548,   408,   373,   374,
     375,   376,   377,   378,   551,   552,   504,   553,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   248,   598,
     554,   555,   557,   558,   254,   515,   516,   253,   559,   571,
     350,   407,   530,   629,   408,   599,   583,   635,   582,   593,
     495,   496,   497,   594,   601,   500,   501,   407,   595,   372,
     607,     5,   373,   374,   375,   376,   377,   378,   625,   628,
     640,   641,   643,   379,   372,   408,   645,   373,   374,   375,
     376,   377,   378,   249,    80,   651,   666,   656,   682,     7,
     683,     8,   673,   675,   407,   677,   688,     9,   687,   711,
      53,    11,   700,    76,   456,   691,   455,    76,   693,    79,
     250,   698,   705,    79,   712,    54,   717,    14,   445,    54,
     577,   380,   429,   215,    16,   407,    17,   379,   418,   587,
      18,   716,   223,    19,   510,   511,   512,   513,   514,   638,
      20,   671,   379,   575,   674,   336,   515,   516,   702,   414,
     598,    22,   381,    23,    24,    25,    26,   269,   652,   650,
       0,   350,   468,    28,     0,   382,   599,     0,     0,     0,
       0,     0,     0,   372,   692,   380,   373,   374,   375,   376,
     377,   378,     0,   697,     0,     0,     0,     0,     0,     0,
     380,   383,     0,     0,   384,   385,   461,    31,     0,   387,
     388,   704,    32,    33,    34,     0,   381,    35,   462,    36,
       0,     0,   389,   218,     0,     0,     0,     0,     0,   382,
       0,   381,   219,     0,    39,   508,   509,   510,   511,   512,
     513,   514,    40,    41,   382,     0,     0,     0,     0,   515,
     516,   379,     0,     0,     0,   383,     0,     0,   384,   385,
     386,     0,     0,   387,   388,     0,     0,     0,     0,     0,
     383,     0,     0,   384,   385,   386,   389,     0,   387,   388,
       0,     0,     0,     0,     0,     0,     0,   580,     0,     0,
       0,   389,     0,     0,     0,     0,     0,     0,     0,   380,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     5,     0,     0,     0,
     381,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   382,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
       0,     0,     9,    10,     0,     0,    11,     0,     0,   383,
       0,    12,   384,   385,   386,     0,     0,   387,   388,     0,
      13,     0,    14,     0,     0,     0,     0,     0,    15,    16,
     389,    17,     0,     0,     0,    18,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,   315,     0,     0,    22,     0,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,    28,     0,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     4,     5,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
       0,     0,    35,     7,    36,     8,     0,     0,    37,     0,
       0,     9,    10,     0,     0,    11,     0,    38,     0,    39,
      12,     0,     0,     0,     0,     0,     0,    40,    41,    13,
       0,    14,     0,     0,     0,     0,     0,    15,    16,     0,
      17,     0,     0,     0,    18,     0,     0,    19,     0,     0,
       0,     0,     0,     0,    20,     0,    42,     0,     0,   325,
       0,    21,   315,     0,     0,    22,     0,    23,    24,    25,
      26,    27,     0,     0,     0,     0,     0,    28,     0,     0,
       0,     0,    29,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,     0,     0,     0,     0,    32,    33,    34,     0,
       0,    35,     7,    36,     8,     0,     0,    37,     0,     0,
       9,    10,     0,     0,    11,     0,    38,     0,    39,    12,
       0,     0,     0,     0,     0,     0,    40,    41,    13,     0,
      14,     0,     0,     0,     0,     0,    15,    16,     0,    17,
       0,     0,     0,    18,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    20,     0,    42,     0,     0,   679,     0,
      21,     0,     0,     0,    22,     0,    23,    24,    25,    26,
      27,     0,     0,     0,     0,     0,    28,     4,     5,     0,
       0,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,     7,     0,     8,     0,
      31,     0,     0,     0,     9,    32,    33,    34,    11,     0,
      35,     0,    36,    12,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,    14,    38,     0,    39,     0,     0,
      15,    16,     0,    17,     0,    40,    41,    18,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,     0,
      23,    24,    25,    26,    42,     0,     0,   567,     0,     0,
      28,     4,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       7,     0,     8,     0,    31,     0,     0,     0,     9,    32,
      33,    34,    11,     0,    35,     0,    36,    12,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,    14,    38,
       0,    39,     0,     0,    15,    16,     0,    17,     0,    40,
      41,    18,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,     0,    23,    24,    25,    26,    42,     0,
       0,   454,     0,     0,    28,     4,     5,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,   501,   502,
     503,     0,     0,     0,     0,     0,    30,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,    31,     0,
       0,     0,     9,    32,    33,    34,    11,     0,    35,     0,
      36,    12,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,    14,    38,     0,    39,     0,     0,    15,    16,
       0,    17,     0,    40,    41,    18,     0,     0,    19,     0,
       0,     5,     0,     0,     0,    20,     0,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,     0,    23,    24,
      25,    26,    42,     0,     0,   578,     0,     0,    28,     7,
       0,     8,     0,     0,     0,     0,     0,     9,     0,     0,
       0,    11,     0,     0,     0,     0,     0,     0,     0,     0,
      30,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,    31,   215,    16,     0,    17,    32,    33,    34,
      18,     0,    35,    19,    36,     0,     0,     0,    37,     0,
      20,     0,     0,     0,     0,     0,     0,    38,     0,    39,
       0,    22,     0,    23,    24,    25,    26,    40,    41,     0,
       0,     0,   504,    28,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,     0,     0,     0,     0,     0,     0,
       0,   515,   516,     0,     0,     0,    42,     0,   550,   681,
       4,     5,     0,     0,     0,     0,     0,    31,     0,     0,
       6,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     7,
       0,     8,   219,     0,    39,     0,     0,     9,    10,     0,
       0,    11,    40,    41,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
      18,    42,     0,    19,   572,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,     0,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       4,     5,     0,     0,     0,     0,     0,    31,     0,   314,
       0,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     7,
     -68,     8,    38,     0,    39,     0,     0,     9,    10,     0,
       0,    11,    40,    41,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,    15,    16,     0,    17,     0,     0,     0,
      18,    42,     0,    19,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    21,   315,     0,
       0,    22,     0,    23,    24,    25,    26,    27,     5,     0,
       0,     0,     0,    28,     0,     0,     0,     0,    29,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,     7,     0,     8,     0,
       0,     0,     0,   247,     9,     0,     0,    31,    11,     0,
       0,     0,    32,    33,    34,     0,     0,    35,     0,    36,
       0,     0,     0,    37,    14,     0,     0,     0,     0,     0,
     215,    16,    38,    17,    39,   248,     0,    18,     0,     0,
      19,     0,    40,    41,     0,     0,     0,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     5,     0,    22,     0,
      23,    24,    25,    26,     0,     0,     0,     0,     0,     0,
      28,    42,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     0,     8,     0,     0,     0,
     249,   247,     9,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,     0,    31,     0,     0,     0,     0,    32,
      33,    34,    14,     0,    35,     0,    36,   250,   215,    16,
     218,    17,     0,   248,     0,    18,     0,     0,    19,   219,
       0,    39,     0,     0,     0,    20,     0,     0,     0,    40,
      41,     0,     0,     0,     5,     0,    22,     0,    23,    24,
      25,    26,     0,     0,     0,     0,     0,   631,    28,     0,
       0,     0,     0,   648,     0,     0,     0,     0,    42,     0,
       0,     0,     7,     0,     8,     0,     0,     0,   249,     0,
       9,     0,     0,     0,    11,     0,     0,     0,     0,     0,
       0,     0,    31,     0,     0,     0,     0,    32,    33,    34,
      14,     0,    35,     0,    36,   250,   215,    16,   218,    17,
       0,     0,     0,    18,     0,     0,    19,   219,     0,    39,
       0,     0,     0,    20,     0,     0,     0,    40,    41,     0,
       0,     0,     5,     0,    22,     0,    23,    24,    25,    26,
       0,     0,     0,     0,     0,   661,    28,   495,   496,   497,
     498,   499,   500,   501,   502,   503,    42,     0,     0,     0,
       7,     0,     8,     0,     0,     0,     0,     0,     9,     0,
       0,     0,    11,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,     0,     0,    32,    33,    34,    14,     0,
      35,     0,    36,     0,   215,    16,   218,    17,     0,     0,
       0,    18,     0,     0,    19,   219,     0,    39,     0,     0,
       0,    20,     0,     0,     0,    40,    41,     0,     0,     0,
       0,     0,    22,     0,    23,    24,    25,    26,     0,     0,
       0,     0,     0,     0,    28,   495,   496,   497,   498,   499,
     500,   501,   502,   503,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   495,   496,   497,
     498,   499,   500,   501,   502,   503,     0,     0,    31,     0,
       0,     0,     0,    32,    33,    34,     0,     0,    35,     0,
      36,     0,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    41,   495,   496,   497,   498,   499,
     500,   501,   502,   503,     0,     0,     0,   504,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,     0,
       0,     0,    42,     0,     0,     0,   515,   516,     0,     0,
       0,     0,     0,   597,   495,   496,   497,   498,   499,   500,
     501,   502,   503,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   495,   496,   497,   498,   499,   500,   501,
       0,   503,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   495,   496,   497,   498,   499,   500,   501,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,     0,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   495,   496,   497,
     498,   499,   500,   501,   515,   516,   581,   504,     0,   505,
     506,   507,   508,   509,   510,   511,   512,   513,   514,   495,
     496,   497,   498,   499,   500,   501,   515,   516,   670,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   504,   669,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,     0,     0,     0,
       0,     0,     0,     0,   515,   516,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   504,     0,   505,   506,   507,   508,
     509,   510,   511,   512,   513,   514,     0,     0,     0,     0,
       0,     0,     0,   515,   516,   505,   506,   507,   508,   509,
     510,   511,   512,   513,   514,     0,     0,     0,     0,     0,
       0,     0,   515,   516,   505,   506,   507,   508,   509,   510,
     511,   512,   513,   514,     0,     0,     0,     0,     0,     0,
       0,   515,   516,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     506,   507,   508,   509,   510,   511,   512,   513,   514,     0,
       0,     0,     5,     0,     0,     0,   515,   516,     0,     0,
       0,     0,     0,   507,   508,   509,   510,   511,   512,   513,
     514,     0,     0,     0,     0,     0,     0,     0,   515,   516,
       7,     0,     8,     0,     0,     0,     0,     0,     9,    10,
       0,     0,    11,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,    13,     0,    14,     0,
       0,     0,     0,     0,   215,    16,     0,    17,     0,     0,
       0,    18,     0,     0,    19,     7,     0,     8,     0,     0,
       0,    20,     0,     9,     0,     0,     0,    11,     0,     0,
       0,     0,    22,     0,    23,    24,    25,    26,    27,     0,
       0,   216,     0,    14,    28,     0,     0,     0,   217,   215,
      16,     0,    17,     0,     0,     0,    18,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    20,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,    31,    23,
      24,    25,    26,    32,    33,    34,     0,     0,    35,    28,
      36,     5,     0,     0,   218,     0,     0,     0,     0,     0,
       0,     0,     0,   219,     0,    39,     0,     0,     0,     0,
       0,     0,     0,    40,    41,     0,     0,     0,     0,     7,
       0,     8,     0,    31,     0,     0,     0,     9,    32,    33,
      34,     0,     0,    35,     0,    36,     0,     0,     0,   218,
       0,     0,     0,     0,     0,     0,     0,    14,   219,     0,
      39,     0,     0,   215,    16,     0,     0,     0,    40,    41,
      18,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    24,    25,    26,     0,     0,     0,
       0,     0,     0,    28,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    32,    33,    34,     0,     0,    35,     0,     0,
       0,     0,     0,   218,     0,     0,     0,     0,     0,     0,
       0,     0,   219,     0,    39,     0,     0,     0,     0,     0,
       0,     0,    40,    41,   108,     0,   109,   110,   111,   112,
     113,   114,     0,   115,     0,     0,   116,     0,   117,     0,
       0,     0,   118,   119,     0,   120,   121,   122,   123,     0,
     124,   125,   126,   127,   128,   129,   130,   131,     0,   132,
       0,   133,   134,   135,   136,   137,     0,     0,   138,     0,
       0,     0,   139,     0,   140,   141,     0,   142,   143,   144,
     145,   146,   147,     0,   148,   149,   150,   151,   152,   153,
       0,     0,   154,     0,     0,   155,     0,     0,     0,     0,
       0,   156,   157,     0,   158,   159,     0,   160,   161,     0,
       0,     0,   162,   163,   164,   165,   166,   167,     0,   168,
     169,   170,   171,   172,   173,   174,     0,   175,     0,   176,
       0,   177,   178,   179,   180,   181,   182,   183,   184,   185,
       0,   186,   187,   188,   189,     0,     0,     0,   190,     0,
       0,   191,     0,     0,   192,   193,     0,     0,   194,   195,
     196,   197,     0,     0,   198,     0,   199,     0,   200,   201,
     202,   203,   204,   205,   206,     0,     0,   207
};

static const yytype_int16 yycheck[] =
{
       2,    53,     2,     2,    50,    74,   286,     2,    74,     2,
     325,   214,     2,     2,   256,     2,   252,   253,     2,     2,
     534,     2,     2,   287,     6,    75,   290,   344,   292,    72,
      73,   295,   591,   294,    77,    53,   300,   533,    39,   346,
     312,    71,    72,    73,   101,   110,   158,    77,    59,   184,
     100,    52,   184,    17,    53,     3,   596,     5,    53,   101,
      53,   601,    37,    38,   158,   184,    53,   158,   136,   349,
      28,    17,   140,   184,   206,    33,   211,     3,   184,     5,
       3,   184,     5,   205,   184,   599,   208,   206,   283,   131,
     101,   286,    40,     9,     0,   207,    12,    45,   293,   167,
     211,   296,   598,   340,   205,   211,   209,   302,   303,   210,
     346,   211,    51,   207,    40,   209,   207,    40,   205,    45,
     660,   210,   636,   210,    72,    64,   685,   442,   365,   366,
      69,   205,    97,    34,   337,   631,   210,   340,    39,   454,
     205,   179,   180,   181,   182,   183,    72,   205,   205,    72,
       3,   209,     5,   667,   349,   350,   205,   226,     9,   208,
     226,   364,   365,   366,   436,   661,   205,     3,     3,   208,
       5,   207,     3,    45,     5,     3,   210,     5,     3,   127,
       5,   210,   209,   252,   253,   164,   252,   253,   383,   384,
     385,   386,   387,   388,   389,     3,   209,     5,    70,   209,
       3,   127,     5,   272,   127,   441,   154,   208,   472,   207,
     212,   213,   281,   212,   213,    40,   234,   260,   209,   212,
     213,   209,   207,    95,   209,   212,   213,   186,   154,   211,
     260,   154,   209,    15,    16,    17,    18,    19,    20,    21,
     204,   205,   294,   218,   219,   207,   194,    72,   194,   195,
     196,   301,   494,   517,   304,   209,   306,   307,   204,   205,
     577,   311,   210,   578,   207,   207,   461,   209,   194,   141,
       3,   194,     5,     3,   326,     5,     3,   346,     5,   205,
     346,   153,   205,   547,   210,   209,     3,   210,     5,     3,
     209,     5,   294,     3,     3,     5,     5,   209,   540,   351,
     495,   496,   127,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     101,   516,   583,   630,     9,   209,   641,   211,   207,   154,
       6,     7,   209,   569,     3,    17,   207,   389,   205,   212,
     210,   210,   210,   345,   210,   345,   345,   542,   210,   351,
     210,   210,   345,   660,   596,   407,   210,   209,   345,   601,
     210,   210,   604,   210,   366,   672,   681,   210,   210,   194,
     210,   210,   441,   210,    41,   441,   210,   210,   210,     5,
     210,   210,   209,   690,   210,   210,    15,    16,    17,    18,
      19,    20,    21,    22,    23,   210,   448,   210,   210,   210,
     210,   210,   471,   683,   456,   210,   210,   643,   190,   191,
     192,   193,   194,   195,   196,    40,   210,    84,   660,   210,
      45,   210,   204,   205,   476,   209,   211,   207,   494,   207,
      97,    98,    99,   100,   486,   186,   211,   210,     9,     9,
     107,     9,   706,   445,     9,   445,   445,    72,   450,   448,
     445,   453,   445,   453,   453,   445,   445,   456,   445,   443,
     453,   445,   445,   456,   445,   445,   453,     9,   534,   456,
       9,   666,     9,     9,   669,     9,   205,   211,   210,   186,
     147,   209,   534,   476,   151,   207,   207,   184,   683,   209,
     208,   207,   207,   212,     6,   184,   204,    15,    16,    17,
     569,     9,   127,   569,    91,   211,   211,   211,   711,   712,
     192,   193,   194,   195,   196,   210,   562,   211,   211,   211,
     211,   573,   204,   205,   593,   211,   186,   211,   211,   154,
     596,   583,   534,   599,   211,   601,    40,   211,   211,   211,
     211,   211,   208,   211,   164,     3,   211,   599,     6,     7,
       8,     9,    10,    11,   211,   211,   185,   211,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,    72,   194,
     211,   211,   211,   211,   643,   204,   205,   643,   211,   209,
     205,   583,   211,   532,   636,   210,   184,   536,   211,   211,
      15,    16,    17,   209,   660,    20,    21,   599,   209,     3,
       3,     5,     6,     7,     8,     9,    10,    11,     3,     9,
       6,   211,   184,    71,     3,   667,   209,     6,     7,     8,
       9,    10,    11,   127,   205,   208,   211,   209,     5,    33,
     186,    35,   211,   211,   636,   211,   211,    41,   207,   186,
     642,    45,   209,   642,   646,   211,   646,   646,   211,   642,
     154,   211,   211,   646,   186,   642,   209,    61,   338,   646,
     452,   119,   308,    67,    68,   667,    70,    71,   302,   471,
      74,   712,    53,    77,   192,   193,   194,   195,   196,   542,
      84,   630,    71,   450,   633,   226,   204,   205,   685,   298,
     194,    95,   150,    97,    98,    99,   100,    82,   586,   584,
      -1,   205,   354,   107,    -1,   163,   210,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   663,   119,     6,     7,     8,     9,
      10,    11,    -1,   672,    -1,    -1,    -1,    -1,    -1,    -1,
     119,   189,    -1,    -1,   192,   193,   194,   141,    -1,   197,
     198,   690,   146,   147,   148,    -1,   150,   151,   206,   153,
      -1,    -1,   210,   157,    -1,    -1,    -1,    -1,    -1,   163,
      -1,   150,   166,    -1,   168,   190,   191,   192,   193,   194,
     195,   196,   176,   177,   163,    -1,    -1,    -1,    -1,   204,
     205,    71,    -1,    -1,    -1,   189,    -1,    -1,   192,   193,
     194,    -1,    -1,   197,   198,    -1,    -1,    -1,    -1,    -1,
     189,    -1,    -1,   192,   193,   194,   210,    -1,   197,   198,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   206,    -1,    -1,
      -1,   210,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   119,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,
     150,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   163,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    45,    -1,    -1,   189,
      -1,    50,   192,   193,   194,    -1,    -1,   197,   198,    -1,
      59,    -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
     210,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    -1,    -1,    95,    -1,    97,    98,
      99,   100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,
      -1,    -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,
      -1,    -1,   151,    33,   153,    35,    -1,    -1,   157,    -1,
      -1,    41,    42,    -1,    -1,    45,    -1,   166,    -1,   168,
      50,    -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    59,
      -1,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,
      70,    -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    -1,   205,    -1,    -1,   208,
      -1,    91,    92,    -1,    -1,    95,    -1,    97,    98,    99,
     100,   101,    -1,    -1,    -1,    -1,    -1,   107,    -1,    -1,
      -1,    -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,    -1,
      -1,   151,    33,   153,    35,    -1,    -1,   157,    -1,    -1,
      41,    42,    -1,    -1,    45,    -1,   166,    -1,   168,    50,
      -1,    -1,    -1,    -1,    -1,    -1,   176,   177,    59,    -1,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    -1,    70,
      -1,    -1,    -1,    74,    -1,    -1,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    -1,   205,    -1,    -1,   208,    -1,
      91,    -1,    -1,    -1,    95,    -1,    97,    98,    99,   100,
     101,    -1,    -1,    -1,    -1,    -1,   107,     4,     5,    -1,
      -1,   112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    35,    -1,
     141,    -1,    -1,    -1,    41,   146,   147,   148,    45,    -1,
     151,    -1,   153,    50,    -1,    -1,   157,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,   166,    -1,   168,    -1,    -1,
      67,    68,    -1,    70,    -1,   176,   177,    74,    -1,    -1,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    -1,    -1,    -1,    95,    -1,
      97,    98,    99,   100,   205,    -1,    -1,   208,    -1,    -1,
     107,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    -1,   141,    -1,    -1,    -1,    41,   146,
     147,   148,    45,    -1,   151,    -1,   153,    50,    -1,    -1,
     157,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,   166,
      -1,   168,    -1,    -1,    67,    68,    -1,    70,    -1,   176,
     177,    74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,   205,    -1,
      -1,   208,    -1,    -1,   107,     4,     5,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,   141,    -1,
      -1,    -1,    41,   146,   147,   148,    45,    -1,   151,    -1,
     153,    50,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,   166,    -1,   168,    -1,    -1,    67,    68,
      -1,    70,    -1,   176,   177,    74,    -1,    -1,    77,    -1,
      -1,     5,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    -1,    -1,    -1,    95,    -1,    97,    98,
      99,   100,   205,    -1,    -1,   208,    -1,    -1,   107,    33,
      -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    -1,   141,    67,    68,    -1,    70,   146,   147,   148,
      74,    -1,   151,    77,   153,    -1,    -1,    -1,   157,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,   166,    -1,   168,
      -1,    95,    -1,    97,    98,    99,   100,   176,   177,    -1,
      -1,    -1,   185,   107,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,   205,    -1,   211,   208,
       4,     5,    -1,    -1,    -1,    -1,    -1,   141,    -1,    -1,
      14,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    33,
      -1,    35,   166,    -1,   168,    -1,    -1,    41,    42,    -1,
      -1,    45,   176,   177,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,
      74,   205,    -1,    77,   208,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    -1,    -1,
      -1,    95,    -1,    97,    98,    99,   100,   101,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,
       4,     5,    -1,    -1,    -1,    -1,    -1,   141,    -1,    13,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    33,
     164,    35,   166,    -1,   168,    -1,    -1,    41,    42,    -1,
      -1,    45,   176,   177,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,    -1,
      -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,    -1,
      74,   205,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    -1,
      -1,    95,    -1,    97,    98,    99,   100,   101,     5,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,   112,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   129,    33,    -1,    35,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,   141,    45,    -1,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,   153,
      -1,    -1,    -1,   157,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,   166,    70,   168,    72,    -1,    74,    -1,    -1,
      77,    -1,   176,   177,    -1,    -1,    -1,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    -1,    95,    -1,
      97,    98,    99,   100,    -1,    -1,    -1,    -1,    -1,    -1,
     107,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    35,    -1,    -1,    -1,
     127,    40,    41,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   141,    -1,    -1,    -1,    -1,   146,
     147,   148,    61,    -1,   151,    -1,   153,   154,    67,    68,
     157,    70,    -1,    72,    -1,    74,    -1,    -1,    77,   166,
      -1,   168,    -1,    -1,    -1,    84,    -1,    -1,    -1,   176,
     177,    -1,    -1,    -1,     5,    -1,    95,    -1,    97,    98,
      99,   100,    -1,    -1,    -1,    -1,    -1,   194,   107,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    -1,   205,    -1,
      -1,    -1,    33,    -1,    35,    -1,    -1,    -1,   127,    -1,
      41,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   141,    -1,    -1,    -1,    -1,   146,   147,   148,
      61,    -1,   151,    -1,   153,   154,    67,    68,   157,    70,
      -1,    -1,    -1,    74,    -1,    -1,    77,   166,    -1,   168,
      -1,    -1,    -1,    84,    -1,    -1,    -1,   176,   177,    -1,
      -1,    -1,     5,    -1,    95,    -1,    97,    98,    99,   100,
      -1,    -1,    -1,    -1,    -1,   194,   107,    15,    16,    17,
      18,    19,    20,    21,    22,    23,   205,    -1,    -1,    -1,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,    -1,    -1,    -1,    -1,   146,   147,   148,    61,    -1,
     151,    -1,   153,    -1,    67,    68,   157,    70,    -1,    -1,
      -1,    74,    -1,    -1,    77,   166,    -1,   168,    -1,    -1,
      -1,    84,    -1,    -1,    -1,   176,   177,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,    -1,    -1,
      -1,    -1,    -1,    -1,   107,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   205,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    -1,    -1,   141,    -1,
      -1,    -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,
     153,    -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,   205,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,   211,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      -1,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    15,    16,    17,    18,    19,    20,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    15,    16,    17,
      18,    19,    20,    21,   204,   205,   206,   185,    -1,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    15,
      16,    17,    18,    19,    20,    21,   204,   205,   206,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   204,   205,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   185,    -1,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   204,   205,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   204,   205,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   204,   205,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     188,   189,   190,   191,   192,   193,   194,   195,   196,    -1,
      -1,    -1,     5,    -1,    -1,    -1,   204,   205,    -1,    -1,
      -1,    -1,    -1,   189,   190,   191,   192,   193,   194,   195,
     196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   204,   205,
      33,    -1,    35,    -1,    -1,    -1,    -1,    -1,    41,    42,
      -1,    -1,    45,    -1,    -1,    -1,    -1,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    -1,    70,    -1,    -1,
      -1,    74,    -1,    -1,    77,    33,    -1,    35,    -1,    -1,
      -1,    84,    -1,    41,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    95,    -1,    97,    98,    99,   100,   101,    -1,
      -1,   104,    -1,    61,   107,    -1,    -1,    -1,   111,    67,
      68,    -1,    70,    -1,    -1,    -1,    74,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,   141,    97,
      98,    99,   100,   146,   147,   148,    -1,    -1,   151,   107,
     153,     5,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   176,   177,    -1,    -1,    -1,    -1,    33,
      -1,    35,    -1,   141,    -1,    -1,    -1,    41,   146,   147,
     148,    -1,    -1,   151,    -1,   153,    -1,    -1,    -1,   157,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,   166,    -1,
     168,    -1,    -1,    67,    68,    -1,    -1,    -1,   176,   177,
      74,    -1,    -1,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    98,    99,   100,    -1,    -1,    -1,
      -1,    -1,    -1,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   146,   147,   148,    -1,    -1,   151,    -1,    -1,
      -1,    -1,    -1,   157,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   166,    -1,   168,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   176,   177,    25,    -1,    27,    28,    29,    30,
      31,    32,    -1,    34,    -1,    -1,    37,    -1,    39,    -1,
      -1,    -1,    43,    44,    -1,    46,    47,    48,    49,    -1,
      51,    52,    53,    54,    55,    56,    57,    58,    -1,    60,
      -1,    62,    63,    64,    65,    66,    -1,    -1,    69,    -1,
      -1,    -1,    73,    -1,    75,    76,    -1,    78,    79,    80,
      81,    82,    83,    -1,    85,    86,    87,    88,    89,    90,
      -1,    -1,    93,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,   102,   103,    -1,   105,   106,    -1,   108,   109,    -1,
      -1,    -1,   113,   114,   115,   116,   117,   118,    -1,   120,
     121,   122,   123,   124,   125,   126,    -1,   128,    -1,   130,
      -1,   132,   133,   134,   135,   136,   137,   138,   139,   140,
      -1,   142,   143,   144,   145,    -1,    -1,    -1,   149,    -1,
      -1,   152,    -1,    -1,   155,   156,    -1,    -1,   159,   160,
     161,   162,    -1,    -1,   165,    -1,   167,    -1,   169,   170,
     171,   172,   173,   174,   175,    -1,    -1,   178
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   214,   216,     0,     4,     5,    14,    33,    35,    41,
      42,    45,    50,    59,    61,    67,    68,    70,    74,    77,
      84,    91,    95,    97,    98,    99,   100,   101,   107,   112,
     129,   141,   146,   147,   148,   151,   153,   157,   166,   168,
     176,   177,   205,   215,   222,   223,   225,   226,   227,   228,
     231,   232,   238,   239,   250,   264,   268,   270,   271,   272,
     273,   274,   277,   278,   281,   283,   284,   285,   286,   288,
     289,   290,   291,   292,   294,   296,   314,   315,   316,   317,
     205,   319,   322,   323,     3,     5,   210,     3,     5,     3,
       5,   266,    97,   269,     9,     3,     5,   269,     3,   210,
     210,   269,   270,     3,   266,     3,   266,   270,    25,    27,
      28,    29,    30,    31,    32,    34,    37,    39,    43,    44,
      46,    47,    48,    49,    51,    52,    53,    54,    55,    56,
      57,    58,    60,    62,    63,    64,    65,    66,    69,    73,
      75,    76,    78,    79,    80,    81,    82,    83,    85,    86,
      87,    88,    89,    90,    93,    96,   102,   103,   105,   106,
     108,   109,   113,   114,   115,   116,   117,   118,   120,   121,
     122,   123,   124,   125,   126,   128,   130,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   142,   143,   144,   145,
     149,   152,   155,   156,   159,   160,   161,   162,   165,   167,
     169,   170,   171,   172,   173,   174,   175,   178,   240,   242,
     313,   209,   218,   218,   164,    67,   104,   111,   157,   166,
     230,   250,   271,   277,   283,   287,   294,   314,   317,   209,
     209,   207,   207,   209,   207,   209,   221,   209,   186,   282,
     207,   295,   296,   295,   295,     3,     5,    40,    72,   127,
     154,   194,   210,   244,   267,   297,   298,   311,   250,   314,
     315,   317,   295,   209,    51,    64,    69,   324,   325,   319,
     101,     9,   207,   209,     3,   315,   207,   158,   207,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   184,   206,    13,    92,   222,   229,   232,   271,
     273,   274,   285,   286,   289,   208,   238,   239,     3,     3,
       5,     3,     5,     3,     3,   207,   311,   275,   217,   131,
     279,   283,     3,     5,   207,   220,   293,   297,   297,   212,
     205,   210,   237,   295,   184,   206,     5,   211,   247,   248,
     249,   267,   186,   211,   257,   210,   260,     9,     9,    12,
     243,   267,     3,     6,     7,     8,     9,    10,    11,    71,
     119,   150,   163,   189,   192,   193,   194,   197,   198,   210,
     253,   254,   255,   253,   256,     9,     9,   241,   256,   255,
       9,     9,   255,     9,   255,   253,   236,   239,   294,   255,
     251,   252,   253,     9,   313,     9,   255,   315,   251,   253,
     315,   179,   180,   181,   182,   183,   312,   315,   315,   243,
       6,     7,   318,     9,   315,   242,   205,   210,   209,   207,
     221,   294,   208,   238,   276,   216,   186,   110,   238,   262,
     280,   209,   207,   220,   208,   222,   239,   292,   297,   211,
     256,   194,   206,   253,   233,   234,   235,   236,   325,   207,
     208,   184,   212,     6,   224,   208,   238,   258,   262,   208,
     239,   259,   262,   211,   211,   211,   210,   253,   253,   253,
     253,   253,   253,   253,   294,    15,    16,    17,    18,    19,
      20,    21,    22,    23,   185,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   204,   205,   184,   211,   211,
     211,   184,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   294,   194,   210,   237,   244,   267,   303,   305,
     306,   211,   184,   211,   211,   211,   211,   184,   211,   211,
     211,   211,   211,   211,   211,   211,   204,   211,   211,   211,
     242,     9,   219,   297,   307,   221,   286,   208,   186,   294,
     314,   209,   208,   239,   263,   264,   208,   228,   208,   221,
     206,   206,   211,   184,   164,   320,   321,   249,   255,     6,
     211,   294,   317,   211,   209,   209,   294,   211,   194,   210,
     237,   244,   299,   301,   302,   253,   253,     3,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,     3,   253,   255,     9,   305,
     293,   194,   233,   244,   304,   305,   210,   237,   252,   255,
       6,   211,   218,   184,   297,   209,   220,   221,    24,   236,
     323,   208,   320,   303,   309,   310,   209,   265,   267,   301,
     293,   194,   233,   244,   300,   301,   211,   210,   237,   186,
     206,   305,   293,   211,   305,   211,   233,   211,   221,   208,
     297,   208,     5,   186,   308,   184,   209,   207,   211,   301,
     293,   211,   305,   211,   253,   233,   253,   305,   211,   221,
     209,   256,   309,   245,   305,   211,    39,    52,   208,   246,
     255,   186,   186,   209,   261,   262,   261,   209
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   213,   214,   215,   215,   216,   217,   216,   216,   216,
     216,   216,   216,   216,   216,   218,   218,   219,   218,   218,
     218,   218,   218,   218,   218,   218,   220,   220,   221,   221,
     222,   222,   222,   222,   222,   222,   222,   223,   224,   224,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   226,
     227,   228,   229,   230,   230,   231,   232,   233,   233,   234,
     234,   235,   235,   236,   236,   237,   237,   237,   238,   238,
     239,   240,   240,   240,   241,   241,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   243,   243,   244,   244,
     244,   244,   245,   245,   246,   246,   247,   247,   247,   248,
     248,   249,   249,   250,   251,   251,   252,   252,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   254,
     254,   255,   256,   257,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   264,   264,   265,   265,
     266,   266,   266,   267,   267,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   269,   269,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   271,   271,   272,
     273,   274,   275,   275,   276,   277,   277,   278,   279,   279,
     280,   280,   281,   281,   282,   282,   283,   283,   284,   285,
     285,   285,   286,   286,   287,   287,   288,   289,   290,   290,
     290,   291,   292,   293,   293,   294,   294,   295,   295,   296,
     296,   296,   297,   297,   297,   298,   298,   298,   298,   299,
     299,   299,   300,   300,   301,   301,   302,   302,   302,   302,
     302,   303,   303,   303,   304,   304,   305,   305,   306,   306,
     306,   306,   306,   306,   307,   307,   308,   308,   309,   310,
     310,   311,   311,   312,   312,   312,   312,   312,   313,   313,
     313,   314,   315,   315,   315,   315,   315,   315,   315,   315,
     315,   315,   316,   317,   317,   318,   318,   318,   319,   319,
     320,   320,   321,   322,   323,   323,   324,   324,   325,   325,
     325
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
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
       1,     2,     2,     1,     1,     1,     1,     2,     2,     2,
       5,     2,     0,     2,     2,     2,     2,     2,     2,     3,
       2,     3,     5,     5,     0,     2,     2,     2,     2,     6,
       8,     2,     2,     2,     2,     2,     2,     5,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     0,     1,     2,
       2,     2,     3,     2,     1,     1,     3,     2,     4,     3,
       2,     1,     3,     2,     0,     1,     3,     2,     1,     3,
       4,     3,     2,     1,     3,     2,     0,     1,     1,     3,
       2,     1,     3,     4,     1,     3,     0,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     4,     5,     5,    10,     1,     3,     1,     0,     2,
       0,     2,     4,     6,     0,     3,     1,     3,     1,     1,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
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
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 315 "parser.y" /* yacc.c:1651  */
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
#line 2620 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 5:
#line 331 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = NULL; }
#line 2626 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 6:
#line 332 "parser.y" /* yacc.c:1651  */
    { push_namespace((yyvsp[-1].str)); }
#line 2632 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 7:
#line 333 "parser.y" /* yacc.c:1651  */
    { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2638 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 8:
#line 334 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2644 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 9:
#line 335 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2650 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 10:
#line 336 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 2658 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 11:
#line 339 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 2666 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 12:
#line 342 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2672 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 13:
#line 343 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2678 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 14:
#line 344 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2684 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 15:
#line 347 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = NULL; }
#line 2690 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 16:
#line 348 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 2696 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 17:
#line 349 "parser.y" /* yacc.c:1651  */
    { push_namespace((yyvsp[-1].str)); }
#line 2702 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 18:
#line 350 "parser.y" /* yacc.c:1651  */
    { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 2708 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 19:
#line 351 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 2714 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 20:
#line 352 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 2720 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 21:
#line 353 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 2728 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 22:
#line 356 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 2734 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 23:
#line 357 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2740 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 24:
#line 358 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 2746 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 25:
#line 359 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 2752 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 26:
#line 362 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = NULL; }
#line 2758 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 27:
#line 363 "parser.y" /* yacc.c:1651  */
    { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 2764 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 30:
#line 371 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 2770 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 31:
#line 372 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 2776 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 32:
#line 373 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 2782 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 33:
#line 374 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 2788 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 34:
#line 375 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 2794 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 35:
#line 376 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 2800 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 36:
#line 377 "parser.y" /* yacc.c:1651  */
    { (yyval.statement) = NULL; }
#line 2806 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 37:
#line 381 "parser.y" /* yacc.c:1651  */
    {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 2818 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 38:
#line 391 "parser.y" /* yacc.c:1651  */
    { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 2824 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 39:
#line 392 "parser.y" /* yacc.c:1651  */
    { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 2830 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 41:
#line 397 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 2836 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 43:
#line 399 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 2842 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 45:
#line 401 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 2848 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 46:
#line 402 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 2854 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 47:
#line 403 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 2860 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 48:
#line 404 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 2866 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 49:
#line 407 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[-1].str); }
#line 2872 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 50:
#line 409 "parser.y" /* yacc.c:1651  */
    { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 2883 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 51:
#line 417 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 2892 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 52:
#line 424 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 2898 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 53:
#line 427 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2904 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 54:
#line 428 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[0].str); }
#line 2910 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 55:
#line 430 "parser.y" /* yacc.c:1651  */
    { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 2918 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 56:
#line 435 "parser.y" /* yacc.c:1651  */
    { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 2924 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 57:
#line 438 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 2930 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 59:
#line 442 "parser.y" /* yacc.c:1651  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 2936 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 60:
#line 443 "parser.y" /* yacc.c:1651  */
    { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 2942 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 62:
#line 447 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 2948 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 63:
#line 451 "parser.y" /* yacc.c:1651  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2958 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 64:
#line 456 "parser.y" /* yacc.c:1651  */
    { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 2968 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 65:
#line 463 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 2977 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 66:
#line 467 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2983 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 67:
#line 468 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 2989 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 68:
#line 471 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = NULL; }
#line 2995 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 70:
#line 476 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3001 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 71:
#line 479 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3007 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 72:
#line 480 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3013 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 73:
#line 481 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3019 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 74:
#line 484 "parser.y" /* yacc.c:1651  */
    { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3025 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 75:
#line 485 "parser.y" /* yacc.c:1651  */
    { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3031 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 76:
#line 488 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = NULL; }
#line 3037 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 77:
#line 489 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3043 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 78:
#line 490 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3049 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 79:
#line 491 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3055 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 80:
#line 492 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3061 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 81:
#line 493 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3067 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 82:
#line 494 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3073 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 83:
#line 495 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3079 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 84:
#line 496 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3085 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 85:
#line 497 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3091 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 86:
#line 498 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3097 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 87:
#line 499 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3103 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 88:
#line 500 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3109 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 89:
#line 501 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3115 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 90:
#line 502 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3121 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 91:
#line 503 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3127 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 92:
#line 504 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3133 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 93:
#line 505 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3139 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 94:
#line 506 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3145 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 95:
#line 507 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3151 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 96:
#line 508 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3157 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 97:
#line 509 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3163 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 98:
#line 510 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3169 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 99:
#line 511 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3175 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 100:
#line 512 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3181 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 101:
#line 513 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3187 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 102:
#line 514 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3193 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 103:
#line 515 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3199 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 104:
#line 516 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3205 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 105:
#line 517 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3211 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 106:
#line 518 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3217 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 107:
#line 519 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3223 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 108:
#line 520 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3229 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 109:
#line 521 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3235 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 110:
#line 522 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3241 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 111:
#line 523 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3247 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 112:
#line 524 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3253 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 113:
#line 525 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3259 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 114:
#line 526 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3265 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 115:
#line 527 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3271 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 116:
#line 528 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3277 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 117:
#line 529 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3283 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 118:
#line 530 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3289 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 119:
#line 531 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3295 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 120:
#line 532 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3301 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 121:
#line 533 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3307 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 122:
#line 534 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_IN); }
#line 3313 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 123:
#line 535 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3319 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 124:
#line 536 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3325 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 125:
#line 537 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3331 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 126:
#line 538 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3337 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 127:
#line 539 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3343 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 128:
#line 540 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3349 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 129:
#line 541 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 3355 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 130:
#line 542 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 3361 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 131:
#line 543 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 3367 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 132:
#line 544 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 3373 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 133:
#line 545 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 3379 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 134:
#line 546 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 3385 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 135:
#line 547 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 3391 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 136:
#line 548 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 3397 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 137:
#line 549 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 3403 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 138:
#line 550 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_ODL); }
#line 3409 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 139:
#line 551 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 3415 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 140:
#line 552 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 3421 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 141:
#line 553 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 3427 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 142:
#line 554 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_OUT); }
#line 3433 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 143:
#line 555 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 3439 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 144:
#line 556 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 3445 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 145:
#line 557 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 3451 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 146:
#line 558 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 3457 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 147:
#line 559 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 3463 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 148:
#line 560 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 3469 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 149:
#line 561 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 3475 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 150:
#line 562 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 3481 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 151:
#line 564 "parser.y" /* yacc.c:1651  */
    { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 3489 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 152:
#line 567 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 3495 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 153:
#line 568 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 3501 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 154:
#line 569 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 3507 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 155:
#line 570 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 3513 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 156:
#line 571 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 3519 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 157:
#line 572 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 3525 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 158:
#line 573 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 3531 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 159:
#line 574 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 3537 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 160:
#line 575 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_STRING); }
#line 3543 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 161:
#line 576 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 3549 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 162:
#line 577 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 3555 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 163:
#line 578 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 3561 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 164:
#line 579 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 3567 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 165:
#line 580 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 3573 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 166:
#line 581 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 3579 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 167:
#line 582 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 3585 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 168:
#line 583 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 3591 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 169:
#line 584 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 3597 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 170:
#line 585 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 3603 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 171:
#line 586 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 3609 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 172:
#line 587 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 3615 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 173:
#line 588 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 3621 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 174:
#line 589 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 3627 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 175:
#line 590 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 3633 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 177:
#line 595 "parser.y" /* yacc.c:1651  */
    { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 3641 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 178:
#line 600 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = xstrdup("__cdecl"); }
#line 3647 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 179:
#line 601 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = xstrdup("__fastcall"); }
#line 3653 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 180:
#line 602 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = xstrdup("__pascal"); }
#line 3659 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 181:
#line 603 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = xstrdup("__stdcall"); }
#line 3665 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 182:
#line 606 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 3671 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 183:
#line 607 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 3677 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 184:
#line 610 "parser.y" /* yacc.c:1651  */
    { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3686 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 185:
#line 614 "parser.y" /* yacc.c:1651  */
    { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 3695 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 186:
#line 620 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 3701 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 187:
#line 621 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 3707 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 189:
#line 625 "parser.y" /* yacc.c:1651  */
    { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 3716 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 190:
#line 629 "parser.y" /* yacc.c:1651  */
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
#line 3731 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 191:
#line 641 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3740 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 192:
#line 645 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 3748 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 193:
#line 650 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 3754 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 194:
#line 653 "parser.y" /* yacc.c:1651  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 3760 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 195:
#line 654 "parser.y" /* yacc.c:1651  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 3766 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 196:
#line 657 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3772 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 198:
#line 661 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 3778 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 199:
#line 662 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 3784 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 200:
#line 663 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 3790 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 201:
#line 664 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 3796 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 202:
#line 665 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 3802 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 203:
#line 666 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 3808 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 204:
#line 667 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 3814 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 205:
#line 668 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 3820 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 206:
#line 669 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 3826 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 207:
#line 670 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 3832 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 208:
#line 671 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3838 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 209:
#line 672 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3844 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 210:
#line 673 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3850 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 211:
#line 674 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3856 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 212:
#line 675 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3862 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 213:
#line 676 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3868 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 214:
#line 677 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3874 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 215:
#line 678 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3880 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 216:
#line 679 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3886 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 217:
#line 680 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3892 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 218:
#line 681 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3898 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 219:
#line 682 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3904 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 220:
#line 683 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3910 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 221:
#line 684 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3916 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 222:
#line 685 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3922 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 223:
#line 686 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3928 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 224:
#line 687 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3934 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 225:
#line 688 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3940 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 226:
#line 689 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 3946 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 227:
#line 690 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 3952 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 228:
#line 691 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 3958 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 229:
#line 692 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 3964 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 230:
#line 693 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 3970 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 231:
#line 694 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 3976 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 232:
#line 695 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 3982 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 233:
#line 696 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3988 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 234:
#line 697 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 3994 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 235:
#line 699 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4000 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 236:
#line 701 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4006 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 237:
#line 702 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4012 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 238:
#line 703 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 4018 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 239:
#line 706 "parser.y" /* yacc.c:1651  */
    { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4024 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 240:
#line 707 "parser.y" /* yacc.c:1651  */
    { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4030 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 241:
#line 710 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4039 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 242:
#line 716 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4048 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 243:
#line 722 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 4054 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 244:
#line 723 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4060 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 245:
#line 727 "parser.y" /* yacc.c:1651  */
    { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4069 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 246:
#line 731 "parser.y" /* yacc.c:1651  */
    { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4078 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 247:
#line 738 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4084 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 248:
#line 739 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4090 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 249:
#line 742 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 4096 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 250:
#line 743 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4102 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 251:
#line 747 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = (yyvsp[-1].var); }
#line 4108 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 252:
#line 748 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = NULL; }
#line 4114 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 253:
#line 751 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4123 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 254:
#line 755 "parser.y" /* yacc.c:1651  */
    { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4132 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 255:
#line 761 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4142 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 256:
#line 770 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4150 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 257:
#line 773 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4158 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 258:
#line 778 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = NULL; }
#line 4164 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 260:
#line 782 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = NULL; }
#line 4170 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 261:
#line 783 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4176 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 262:
#line 784 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4182 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 263:
#line 787 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4188 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 264:
#line 789 "parser.y" /* yacc.c:1651  */
    { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4194 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 265:
#line 792 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4200 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 266:
#line 793 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4206 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 268:
#line 795 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4212 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 269:
#line 796 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4218 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 270:
#line 797 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4224 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 271:
#line 798 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4230 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 272:
#line 799 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4236 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 273:
#line 800 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4242 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 274:
#line 801 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4248 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 275:
#line 802 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4254 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 278:
#line 809 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4260 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 279:
#line 810 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4266 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 280:
#line 811 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4272 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 281:
#line 812 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4278 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 282:
#line 813 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4284 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 283:
#line 814 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4290 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 284:
#line 815 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4296 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 285:
#line 816 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4302 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 286:
#line 817 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4308 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 287:
#line 820 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 4314 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 288:
#line 821 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 4325 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 289:
#line 829 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4334 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 290:
#line 836 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 4340 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 291:
#line 839 "parser.y" /* yacc.c:1651  */
    { (yyval.str) = (yyvsp[0].str); }
#line 4346 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 292:
#line 842 "parser.y" /* yacc.c:1651  */
    { (yyval.ifref_list) = NULL; }
#line 4352 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 293:
#line 843 "parser.y" /* yacc.c:1651  */
    { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 4358 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 294:
#line 847 "parser.y" /* yacc.c:1651  */
    { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 4364 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 295:
#line 850 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4370 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 296:
#line 851 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4376 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 297:
#line 854 "parser.y" /* yacc.c:1651  */
    { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 4388 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 298:
#line 863 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 4394 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 299:
#line 864 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4400 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 300:
#line 867 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = NULL; }
#line 4406 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 301:
#line 868 "parser.y" /* yacc.c:1651  */
    { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 4412 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 302:
#line 874 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 4420 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 303:
#line 878 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 4428 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 304:
#line 883 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = NULL; }
#line 4434 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 305:
#line 884 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error2((yyvsp[0].str), 0); }
#line 4440 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 306:
#line 887 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4446 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 307:
#line 888 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 4452 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 308:
#line 891 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 4462 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 309:
#line 899 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-5].type);
						  if((yyval.type) == (yyvsp[-4].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						}
#line 4473 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 310:
#line 909 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-7].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-5].str), 0), (yyvsp[-2].stmt_list));
						}
#line 4481 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 311:
#line 912 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4487 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 312:
#line 916 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4493 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 313:
#line 917 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-1].type); }
#line 4499 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 314:
#line 920 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4505 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 315:
#line 921 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 4511 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 316:
#line 924 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 4519 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 317:
#line 930 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 4527 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 318:
#line 936 "parser.y" /* yacc.c:1651  */
    { (yyval.stgclass) = STG_EXTERN; }
#line 4533 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 319:
#line 937 "parser.y" /* yacc.c:1651  */
    { (yyval.stgclass) = STG_STATIC; }
#line 4539 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 320:
#line 938 "parser.y" /* yacc.c:1651  */
    { (yyval.stgclass) = STG_REGISTER; }
#line 4545 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 321:
#line 942 "parser.y" /* yacc.c:1651  */
    { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 4551 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 322:
#line 946 "parser.y" /* yacc.c:1651  */
    { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 4557 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 323:
#line 949 "parser.y" /* yacc.c:1651  */
    { (yyval.type_qualifier) = 0; }
#line 4563 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 324:
#line 950 "parser.y" /* yacc.c:1651  */
    { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 4569 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 325:
#line 953 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 4575 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 326:
#line 955 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 4581 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 327:
#line 958 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = NULL; }
#line 4587 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 329:
#line 963 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 4593 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 330:
#line 964 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 4599 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 331:
#line 965 "parser.y" /* yacc.c:1651  */
    { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 4605 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 332:
#line 970 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 4611 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 333:
#line 971 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 4617 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 335:
#line 976 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4623 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 336:
#line 977 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4629 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 337:
#line 978 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 4635 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 338:
#line 979 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 4641 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 339:
#line 985 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 4647 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 340:
#line 986 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 4653 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 342:
#line 993 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 4659 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 343:
#line 994 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 4665 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 344:
#line 998 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4671 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 346:
#line 1004 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4677 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 347:
#line 1005 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 4683 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 348:
#line 1006 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 4689 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 349:
#line 1008 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 4697 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 350:
#line 1012 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 4705 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 351:
#line 1020 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 4711 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 352:
#line 1021 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 4717 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 354:
#line 1028 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 4723 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 355:
#line 1029 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 4729 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 356:
#line 1033 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL); }
#line 4735 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 358:
#line 1041 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 4741 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 359:
#line 1042 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 4747 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 360:
#line 1043 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 4753 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 361:
#line 1044 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 4759 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 362:
#line 1046 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 4767 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 363:
#line 1050 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 4775 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 364:
#line 1056 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4781 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 365:
#line 1057 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4787 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 366:
#line 1060 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = NULL; }
#line 4793 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 367:
#line 1061 "parser.y" /* yacc.c:1651  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 4799 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 368:
#line 1064 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 4808 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 369:
#line 1071 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 4814 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 370:
#line 1073 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 4820 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 371:
#line 1077 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[0].declarator); }
#line 4826 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 372:
#line 1078 "parser.y" /* yacc.c:1651  */
    { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 4832 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 373:
#line 1082 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = THREADING_APARTMENT; }
#line 4838 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 374:
#line 1083 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = THREADING_NEUTRAL; }
#line 4844 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 375:
#line 1084 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = THREADING_SINGLE; }
#line 4850 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 376:
#line 1085 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = THREADING_FREE; }
#line 4856 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 377:
#line 1086 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = THREADING_BOTH; }
#line 4862 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 378:
#line 1090 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = FC_RP; }
#line 4868 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 379:
#line 1091 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = FC_UP; }
#line 4874 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 380:
#line 1092 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = FC_FP; }
#line 4880 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 381:
#line 1095 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4886 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 382:
#line 1098 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_void(); }
#line 4892 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 383:
#line 1099 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4898 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 384:
#line 1100 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4904 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 385:
#line 1101 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4910 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 386:
#line 1102 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 4916 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 387:
#line 1103 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4922 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 388:
#line 1104 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 4928 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 389:
#line 1105 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = (yyvsp[0].type); }
#line 4934 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 390:
#line 1106 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 4940 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 391:
#line 1107 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 4946 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 392:
#line 1111 "parser.y" /* yacc.c:1651  */
    { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 4955 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 393:
#line 1118 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 4961 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 394:
#line 1121 "parser.y" /* yacc.c:1651  */
    { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 4967 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 395:
#line 1125 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 4973 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 396:
#line 1126 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 4979 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 397:
#line 1127 "parser.y" /* yacc.c:1651  */
    { (yyval.num) = (yyvsp[0].num); }
#line 4985 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 402:
#line 1140 "parser.y" /* yacc.c:1651  */
    { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 4993 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 403:
#line 1145 "parser.y" /* yacc.c:1651  */
    {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5003 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 404:
#line 1152 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = NULL; }
#line 5009 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 405:
#line 1153 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5015 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 406:
#line 1156 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5021 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 407:
#line 1157 "parser.y" /* yacc.c:1651  */
    { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5027 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 408:
#line 1160 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5033 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 409:
#line 1161 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5039 "parser.tab.c" /* yacc.c:1651  */
    break;

  case 410:
#line 1162 "parser.y" /* yacc.c:1651  */
    { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5045 "parser.tab.c" /* yacc.c:1651  */
    break;


#line 5049 "parser.tab.c" /* yacc.c:1651  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1164 "parser.y" /* yacc.c:1910  */


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
  type_t *type = find_type(name, NULL, t);
  if (!type) {
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
  static const char format[] = "__WIDL_%s_generated_name_%08lX";
  static unsigned long n = 0;
  static const char *file_id;
  static size_t size;
  char *name;

  if (! file_id)
  {
    char *dst = dup_basename(input_idl_name, ".idl");
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';

    size = sizeof format - 7 + strlen(file_id) + 8;
  }

  name = xmalloc(size);
  sprintf(name, format, file_id, n++);
  return name;
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

static char *concat_str(const char *prefix, const char *str)
{
    char *ret = xmalloc(strlen(prefix) + strlen(str) + 1);
    strcpy(ret, prefix);
    strcat(ret, str);
    return ret;
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

    async_iface = get_type(TYPE_INTERFACE, concat_str("Async", iface->name), iface->namespace, 0);
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

        begin_func = copy_var(func, concat_str("Begin_", func->name), NULL);
        begin_func->declspec.type = type_new_function(begin_args);
        begin_func->declspec.type->attrs = func->attrs;
        begin_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(begin_func));

        finish_func = copy_var(func, concat_str("Finish_", func->name), NULL);
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
