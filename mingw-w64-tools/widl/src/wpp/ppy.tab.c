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
#define yyparse         ppy_parse
#define yylex           ppy_lex
#define yyerror         ppy_error
#define yydebug         ppy_debug
#define yynerrs         ppy_nerrs
#define yylval          ppy_lval
#define yychar          ppy_char

/* First part of user prologue.  */
#line 30 "libs/wpp/ppy.y"

#include "config.h"
#include "wine/port.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "wpp_private.h"


#define UNARY_OP(r, v, OP)					\
	switch(v.type)						\
	{							\
	case cv_sint:	r.val.si  = OP v.val.si; break;		\
	case cv_uint:	r.val.ui  = OP v.val.ui; break;		\
	case cv_slong:	r.val.sl  = OP v.val.sl; break;		\
	case cv_ulong:	r.val.ul  = OP v.val.ul; break;		\
	case cv_sll:	r.val.sll = OP v.val.sll; break;	\
	case cv_ull:	r.val.ull = OP v.val.ull; break;	\
	}

#define cv_signed(v)	((v.type & FLAG_SIGNED) != 0)

#define BIN_OP_INT(r, v1, v2, OP)			\
	r.type = v1.type;				\
	if(cv_signed(v1) && cv_signed(v2))		\
		r.val.si = v1.val.si OP v2.val.si;	\
	else if(cv_signed(v1) && !cv_signed(v2))	\
		r.val.si = v1.val.si OP (signed) v2.val.ui; \
	else if(!cv_signed(v1) && cv_signed(v2))	\
		r.val.si = (signed) v1.val.ui OP v2.val.si; \
	else						\
		r.val.ui = v1.val.ui OP v2.val.ui;

#define BIN_OP_LONG(r, v1, v2, OP)			\
	r.type = v1.type;				\
	if(cv_signed(v1) && cv_signed(v2))		\
		r.val.sl = v1.val.sl OP v2.val.sl;	\
	else if(cv_signed(v1) && !cv_signed(v2))	\
		r.val.sl = v1.val.sl OP (signed long) v2.val.ul; \
	else if(!cv_signed(v1) && cv_signed(v2))	\
		r.val.sl = (signed long) v1.val.ul OP v2.val.sl; \
	else						\
		r.val.ul = v1.val.ul OP v2.val.ul;

#define BIN_OP_LONGLONG(r, v1, v2, OP)			\
	r.type = v1.type;				\
	if(cv_signed(v1) && cv_signed(v2))		\
		r.val.sll = v1.val.sll OP v2.val.sll;	\
	else if(cv_signed(v1) && !cv_signed(v2))	\
		r.val.sll = v1.val.sll OP (__int64) v2.val.ull; \
	else if(!cv_signed(v1) && cv_signed(v2))	\
		r.val.sll = (__int64) v1.val.ull OP v2.val.sll; \
	else						\
		r.val.ull = v1.val.ull OP v2.val.ull;

#define BIN_OP(r, v1, v2, OP)						\
	switch(v1.type & SIZE_MASK)					\
	{								\
	case SIZE_INT:		BIN_OP_INT(r, v1, v2, OP); break;	\
	case SIZE_LONG:		BIN_OP_LONG(r, v1, v2, OP); break;	\
	case SIZE_LONGLONG:	BIN_OP_LONGLONG(r, v1, v2, OP); break;	\
	default: pp_internal_error(__FILE__, __LINE__, "Invalid type indicator (0x%04x)", v1.type);	\
	}


/*
 * Prototypes
 */
static int boolean(cval_t *v);
static void promote_equal_size(cval_t *v1, cval_t *v2);
static void cast_to_sint(cval_t *v);
static void cast_to_uint(cval_t *v);
static void cast_to_slong(cval_t *v);
static void cast_to_ulong(cval_t *v);
static void cast_to_sll(cval_t *v);
static void cast_to_ull(cval_t *v);
static char *add_new_marg(char *str);
static int marg_index(char *id);
static mtext_t *new_mtext(char *str, int idx, def_exp_t type);
static mtext_t *combine_mtext(mtext_t *tail, mtext_t *mtp);
static char *merge_text(char *s1, char *s2);

/*
 * Local variables
 */
static char   **macro_args;	/* Macro parameters array while parsing */
static int	nmacro_args;


#line 173 "libs/wpp/ppy.tab.c"

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
extern int ppy_debug;
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
    tRCINCLUDE = 258,              /* tRCINCLUDE  */
    tIF = 259,                     /* tIF  */
    tIFDEF = 260,                  /* tIFDEF  */
    tIFNDEF = 261,                 /* tIFNDEF  */
    tELSE = 262,                   /* tELSE  */
    tELIF = 263,                   /* tELIF  */
    tENDIF = 264,                  /* tENDIF  */
    tDEFINED = 265,                /* tDEFINED  */
    tNL = 266,                     /* tNL  */
    tINCLUDE = 267,                /* tINCLUDE  */
    tLINE = 268,                   /* tLINE  */
    tGCCLINE = 269,                /* tGCCLINE  */
    tERROR = 270,                  /* tERROR  */
    tWARNING = 271,                /* tWARNING  */
    tPRAGMA = 272,                 /* tPRAGMA  */
    tPPIDENT = 273,                /* tPPIDENT  */
    tUNDEF = 274,                  /* tUNDEF  */
    tMACROEND = 275,               /* tMACROEND  */
    tCONCAT = 276,                 /* tCONCAT  */
    tELLIPSIS = 277,               /* tELLIPSIS  */
    tSTRINGIZE = 278,              /* tSTRINGIZE  */
    tIDENT = 279,                  /* tIDENT  */
    tLITERAL = 280,                /* tLITERAL  */
    tMACRO = 281,                  /* tMACRO  */
    tDEFINE = 282,                 /* tDEFINE  */
    tDQSTRING = 283,               /* tDQSTRING  */
    tSQSTRING = 284,               /* tSQSTRING  */
    tIQSTRING = 285,               /* tIQSTRING  */
    tUINT = 286,                   /* tUINT  */
    tSINT = 287,                   /* tSINT  */
    tULONG = 288,                  /* tULONG  */
    tSLONG = 289,                  /* tSLONG  */
    tULONGLONG = 290,              /* tULONGLONG  */
    tSLONGLONG = 291,              /* tSLONGLONG  */
    tRCINCLUDEPATH = 292,          /* tRCINCLUDEPATH  */
    tLOGOR = 293,                  /* tLOGOR  */
    tLOGAND = 294,                 /* tLOGAND  */
    tEQ = 295,                     /* tEQ  */
    tNE = 296,                     /* tNE  */
    tLTE = 297,                    /* tLTE  */
    tGTE = 298,                    /* tGTE  */
    tLSHIFT = 299,                 /* tLSHIFT  */
    tRSHIFT = 300                  /* tRSHIFT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 125 "libs/wpp/ppy.y"

	int		sint;
	unsigned int	uint;
	long		slong;
	unsigned long	ulong;
	__int64		sll;
	unsigned __int64 ull;
	int		*iptr;
	char		*cptr;
	cval_t		cval;
	char		*marg;
	mtext_t		*mtext;

#line 279 "libs/wpp/ppy.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE ppy_lval;

int ppy_parse (void);


/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_tRCINCLUDE = 3,                 /* tRCINCLUDE  */
  YYSYMBOL_tIF = 4,                        /* tIF  */
  YYSYMBOL_tIFDEF = 5,                     /* tIFDEF  */
  YYSYMBOL_tIFNDEF = 6,                    /* tIFNDEF  */
  YYSYMBOL_tELSE = 7,                      /* tELSE  */
  YYSYMBOL_tELIF = 8,                      /* tELIF  */
  YYSYMBOL_tENDIF = 9,                     /* tENDIF  */
  YYSYMBOL_tDEFINED = 10,                  /* tDEFINED  */
  YYSYMBOL_tNL = 11,                       /* tNL  */
  YYSYMBOL_tINCLUDE = 12,                  /* tINCLUDE  */
  YYSYMBOL_tLINE = 13,                     /* tLINE  */
  YYSYMBOL_tGCCLINE = 14,                  /* tGCCLINE  */
  YYSYMBOL_tERROR = 15,                    /* tERROR  */
  YYSYMBOL_tWARNING = 16,                  /* tWARNING  */
  YYSYMBOL_tPRAGMA = 17,                   /* tPRAGMA  */
  YYSYMBOL_tPPIDENT = 18,                  /* tPPIDENT  */
  YYSYMBOL_tUNDEF = 19,                    /* tUNDEF  */
  YYSYMBOL_tMACROEND = 20,                 /* tMACROEND  */
  YYSYMBOL_tCONCAT = 21,                   /* tCONCAT  */
  YYSYMBOL_tELLIPSIS = 22,                 /* tELLIPSIS  */
  YYSYMBOL_tSTRINGIZE = 23,                /* tSTRINGIZE  */
  YYSYMBOL_tIDENT = 24,                    /* tIDENT  */
  YYSYMBOL_tLITERAL = 25,                  /* tLITERAL  */
  YYSYMBOL_tMACRO = 26,                    /* tMACRO  */
  YYSYMBOL_tDEFINE = 27,                   /* tDEFINE  */
  YYSYMBOL_tDQSTRING = 28,                 /* tDQSTRING  */
  YYSYMBOL_tSQSTRING = 29,                 /* tSQSTRING  */
  YYSYMBOL_tIQSTRING = 30,                 /* tIQSTRING  */
  YYSYMBOL_tUINT = 31,                     /* tUINT  */
  YYSYMBOL_tSINT = 32,                     /* tSINT  */
  YYSYMBOL_tULONG = 33,                    /* tULONG  */
  YYSYMBOL_tSLONG = 34,                    /* tSLONG  */
  YYSYMBOL_tULONGLONG = 35,                /* tULONGLONG  */
  YYSYMBOL_tSLONGLONG = 36,                /* tSLONGLONG  */
  YYSYMBOL_tRCINCLUDEPATH = 37,            /* tRCINCLUDEPATH  */
  YYSYMBOL_38_ = 38,                       /* '?'  */
  YYSYMBOL_39_ = 39,                       /* ':'  */
  YYSYMBOL_tLOGOR = 40,                    /* tLOGOR  */
  YYSYMBOL_tLOGAND = 41,                   /* tLOGAND  */
  YYSYMBOL_42_ = 42,                       /* '|'  */
  YYSYMBOL_43_ = 43,                       /* '^'  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_tEQ = 45,                       /* tEQ  */
  YYSYMBOL_tNE = 46,                       /* tNE  */
  YYSYMBOL_47_ = 47,                       /* '<'  */
  YYSYMBOL_tLTE = 48,                      /* tLTE  */
  YYSYMBOL_49_ = 49,                       /* '>'  */
  YYSYMBOL_tGTE = 50,                      /* tGTE  */
  YYSYMBOL_tLSHIFT = 51,                   /* tLSHIFT  */
  YYSYMBOL_tRSHIFT = 52,                   /* tRSHIFT  */
  YYSYMBOL_53_ = 53,                       /* '+'  */
  YYSYMBOL_54_ = 54,                       /* '-'  */
  YYSYMBOL_55_ = 55,                       /* '*'  */
  YYSYMBOL_56_ = 56,                       /* '/'  */
  YYSYMBOL_57_ = 57,                       /* '~'  */
  YYSYMBOL_58_ = 58,                       /* '!'  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '('  */
  YYSYMBOL_61_ = 61,                       /* ')'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_pp_file = 63,                   /* pp_file  */
  YYSYMBOL_preprocessor = 64,              /* preprocessor  */
  YYSYMBOL_opt_text = 65,                  /* opt_text  */
  YYSYMBOL_text = 66,                      /* text  */
  YYSYMBOL_res_arg = 67,                   /* res_arg  */
  YYSYMBOL_allmargs = 68,                  /* allmargs  */
  YYSYMBOL_emargs = 69,                    /* emargs  */
  YYSYMBOL_margs = 70,                     /* margs  */
  YYSYMBOL_opt_mtexts = 71,                /* opt_mtexts  */
  YYSYMBOL_mtexts = 72,                    /* mtexts  */
  YYSYMBOL_mtext = 73,                     /* mtext  */
  YYSYMBOL_pp_expr = 74                    /* pp_expr  */
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
typedef yytype_uint8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   300


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    58,     2,     2,     2,     2,    44,     2,
      60,    61,    55,    53,    59,    54,     2,    56,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,     2,
      47,     2,    49,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    43,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    42,     2,    57,     2,     2,     2,
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
      35,    36,    37,    40,    41,    45,    46,    48,    50,    51,
      52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   181,   185,   186,   187,   188,   189,   209,
     233,   259,   276,   277,   278,   281,   282,   283,   285,   287,
     289,   291,   292,   293,   294,   295,   296,   303,   309,   310,
     313,   314,   315,   316,   317,   318,   321,   324,   325,   328,
     329,   332,   333,   337,   338,   344,   345,   348,   349,   350,
     351,   352,   359,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "tRCINCLUDE", "tIF",
  "tIFDEF", "tIFNDEF", "tELSE", "tELIF", "tENDIF", "tDEFINED", "tNL",
  "tINCLUDE", "tLINE", "tGCCLINE", "tERROR", "tWARNING", "tPRAGMA",
  "tPPIDENT", "tUNDEF", "tMACROEND", "tCONCAT", "tELLIPSIS", "tSTRINGIZE",
  "tIDENT", "tLITERAL", "tMACRO", "tDEFINE", "tDQSTRING", "tSQSTRING",
  "tIQSTRING", "tUINT", "tSINT", "tULONG", "tSLONG", "tULONGLONG",
  "tSLONGLONG", "tRCINCLUDEPATH", "'?'", "':'", "tLOGOR", "tLOGAND", "'|'",
  "'^'", "'&'", "tEQ", "tNE", "'<'", "tLTE", "'>'", "tGTE", "tLSHIFT",
  "tRSHIFT", "'+'", "'-'", "'*'", "'/'", "'~'", "'!'", "','", "'('", "')'",
  "$accept", "pp_file", "preprocessor", "opt_text", "text", "res_arg",
  "allmargs", "emargs", "margs", "opt_mtexts", "mtexts", "mtext",
  "pp_expr", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,    63,    58,
     293,   294,   124,    94,    38,   295,   296,    60,   297,    62,
     298,   299,   300,    43,    45,    42,    47,   126,    33,    44,
      40,    41
};
#endif

#define YYPACT_NINF (-27)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   142,   -27,   -26,    -3,   -12,    -2,    30,    -3,    41,
      91,    21,     2,   -19,   -19,   -19,   -19,    32,   -27,   -19,
     -27,   -27,   -27,   -23,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,    -3,    -3,    -3,    -3,    -3,    38,    66,   109,   -27,
      85,   -27,   113,   133,   115,   -27,   124,   -27,   -27,   -27,
     179,    -9,   278,   280,   281,   282,   129,   283,   -27,   271,
     -10,   -10,   -27,   -27,    57,   -27,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,    -3,    -3,   -27,   -27,   -27,   -27,   -27,   285,
       3,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     277,   -27,   239,   -27,   238,   -27,   132,   167,   182,   196,
     209,   221,   231,   231,   111,   111,   111,   111,    61,    61,
     -10,   -10,   -27,   -27,   -27,   -27,     4,    19,   266,   -27,
      -3,   -27,     6,   -27,   276,   -27,   -27,   -27,   -27,   290,
      19,   -27,   -27,   -27,   151,   -27,     7,   -27,   -27,   -27,
     -27,   291,   -27
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    28,    28,    28,    28,     0,    36,    28,
       3,    27,    26,     0,    61,    54,    53,    56,    55,    58,
      57,     0,     0,     0,     0,     0,     0,     0,     0,    10,
       0,    11,     0,     0,     0,    21,     0,    30,    31,    32,
       0,    29,     0,     0,     0,     0,    37,     0,    59,     0,
      79,    80,    81,    82,     0,     6,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     7,     8,     9,     4,     5,     0,
       0,    22,    33,    34,    35,    23,    24,    25,    12,    42,
       0,    38,    39,    13,     0,    83,     0,    62,    63,    74,
      72,    73,    64,    65,    66,    68,    67,    69,    77,    78,
      70,    71,    75,    76,    15,    16,     0,    43,     0,    60,
       0,    17,     0,    50,     0,    52,    47,    48,    49,     0,
      44,    45,    40,    41,    84,    18,     0,    51,    14,    46,
      19,     0,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -27,   -27,   -27,   -11,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,   163,    -8
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,    20,    50,    51,    56,   100,   101,   102,   139,
     140,   141,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      40,    58,    21,    52,    53,    54,    47,    23,    57,    48,
      49,    22,    37,    45,   125,   131,    92,   145,   150,    93,
      94,    24,    38,    60,    61,    62,    63,    64,    25,    26,
      27,    28,    29,    30,    46,   126,   132,    59,   146,   151,
     133,    39,   134,   135,   136,    82,    83,   137,   138,    65,
      31,    32,    41,    44,    33,    34,    55,    35,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    66,    84,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    66,    86,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    80,    81,    82,    83,   105,    42,
      85,    43,   144,    66,    87,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,     2,    89,    88,     3,     4,     5,     6,     7,
       8,     9,    90,    99,    10,    11,    12,    13,    14,    15,
      16,    17,    78,    79,    80,    81,    82,    83,    18,    19,
      66,   130,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    66,
      91,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,   142,    95,
     143,    96,    97,    98,   103,   104,   124,   127,   128,   129,
     147,   148,   152,   149
};

static const yytype_uint8 yycheck[] =
{
       8,    24,    28,    14,    15,    16,    25,    10,    19,    28,
      29,    37,    24,    11,    11,    11,    25,    11,    11,    28,
      29,    24,    24,    31,    32,    33,    34,    35,    31,    32,
      33,    34,    35,    36,    32,    32,    32,    60,    32,    32,
      21,    11,    23,    24,    25,    55,    56,    28,    29,    11,
      53,    54,    11,    32,    57,    58,    24,    60,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    38,    11,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    38,    11,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    53,    54,    55,    56,    61,    28,
      11,    30,   130,    38,    11,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     0,    28,    11,     3,     4,     5,     6,     7,
       8,     9,    28,    24,    12,    13,    14,    15,    16,    17,
      18,    19,    51,    52,    53,    54,    55,    56,    26,    27,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    38,
      11,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    22,    11,
      24,    11,    11,    11,    11,    24,    11,    20,    59,    61,
      24,    11,    11,   140
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    63,     0,     3,     4,     5,     6,     7,     8,     9,
      12,    13,    14,    15,    16,    17,    18,    19,    26,    27,
      64,    28,    37,    10,    24,    31,    32,    33,    34,    35,
      36,    53,    54,    57,    58,    60,    74,    24,    24,    11,
      74,    11,    28,    30,    32,    11,    32,    25,    28,    29,
      65,    66,    65,    65,    65,    24,    67,    65,    24,    60,
      74,    74,    74,    74,    74,    11,    38,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    11,    11,    11,    11,    11,    28,
      28,    11,    25,    28,    29,    11,    11,    11,    11,    24,
      68,    69,    70,    11,    24,    61,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    11,    11,    32,    20,    59,    61,
      39,    11,    32,    21,    23,    24,    25,    28,    29,    71,
      72,    73,    22,    24,    74,    11,    32,    24,    11,    73,
      11,    32,    11
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    65,
      66,    66,    66,    66,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     6,     4,     4,     5,     6,     7,
       8,     2,     3,     3,     3,     3,     2,     2,     0,     1,
       1,     1,     1,     2,     2,     2,     0,     0,     1,     1,
       3,     3,     1,     0,     1,     1,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     5
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
  case 4: /* preprocessor: tINCLUDE tDQSTRING tNL  */
#line 185 "libs/wpp/ppy.y"
                                        { pp_do_include((yyvsp[-1].cptr), 1); }
#line 1475 "libs/wpp/ppy.tab.c"
    break;

  case 5: /* preprocessor: tINCLUDE tIQSTRING tNL  */
#line 186 "libs/wpp/ppy.y"
                                        { pp_do_include((yyvsp[-1].cptr), 0); }
#line 1481 "libs/wpp/ppy.tab.c"
    break;

  case 6: /* preprocessor: tIF pp_expr tNL  */
#line 187 "libs/wpp/ppy.y"
                                { pp_next_if_state(boolean(&(yyvsp[-1].cval))); }
#line 1487 "libs/wpp/ppy.tab.c"
    break;

  case 7: /* preprocessor: tIFDEF tIDENT tNL  */
#line 188 "libs/wpp/ppy.y"
                                { pp_next_if_state(pplookup((yyvsp[-1].cptr)) != NULL); free((yyvsp[-1].cptr)); }
#line 1493 "libs/wpp/ppy.tab.c"
    break;

  case 8: /* preprocessor: tIFNDEF tIDENT tNL  */
#line 189 "libs/wpp/ppy.y"
                                {
		int t = pplookup((yyvsp[-1].cptr)) == NULL;
		if(pp_incl_state.state == 0 && t && !pp_incl_state.seen_junk)
		{
			pp_incl_state.state	= 1;
			pp_incl_state.ppp	= (yyvsp[-1].cptr);
			pp_incl_state.ifdepth	= pp_get_if_depth();
		}
		else if(pp_incl_state.state != 1)
		{
			pp_incl_state.state = -1;
			free((yyvsp[-1].cptr));
		}
		else
			free((yyvsp[-1].cptr));
		pp_next_if_state(t);
		if(pp_status.debug)
			fprintf(stderr, "tIFNDEF: %s:%d: include_state=%d, include_ppp='%s', include_ifdepth=%d\n",
                                pp_status.input, pp_status.line_number, pp_incl_state.state, pp_incl_state.ppp, pp_incl_state.ifdepth);
		}
#line 1518 "libs/wpp/ppy.tab.c"
    break;

  case 9: /* preprocessor: tELIF pp_expr tNL  */
#line 209 "libs/wpp/ppy.y"
                                {
		pp_if_state_t s = pp_pop_if();
		switch(s)
		{
		case if_true:
		case if_elif:
			pp_push_if(if_elif);
			break;
		case if_false:
			pp_push_if(boolean(&(yyvsp[-1].cval)) ? if_true : if_false);
			break;
		case if_ignore:
			pp_push_if(if_ignore);
			break;
		case if_elsetrue:
		case if_elsefalse:
			ppy_error("#elif cannot follow #else");
			break;
		case if_error:
			break;
		default:
			pp_internal_error(__FILE__, __LINE__, "Invalid pp_if_state (%d) in #elif directive", s);
		}
		}
#line 1547 "libs/wpp/ppy.tab.c"
    break;

  case 10: /* preprocessor: tELSE tNL  */
#line 233 "libs/wpp/ppy.y"
                                {
		pp_if_state_t s = pp_pop_if();
		switch(s)
		{
		case if_true:
			pp_push_if(if_elsefalse);
			break;
		case if_elif:
			pp_push_if(if_elif);
			break;
		case if_false:
			pp_push_if(if_elsetrue);
			break;
		case if_ignore:
			pp_push_if(if_ignore);
			break;
		case if_elsetrue:
		case if_elsefalse:
			ppy_error("#else clause already defined");
			break;
		case if_error:
			break;
		default:
			pp_internal_error(__FILE__, __LINE__, "Invalid pp_if_state (%d) in #else directive", s);
		}
		}
#line 1578 "libs/wpp/ppy.tab.c"
    break;

  case 11: /* preprocessor: tENDIF tNL  */
#line 259 "libs/wpp/ppy.y"
                                {
		if(pp_pop_if() != if_error)
		{
			if(pp_incl_state.ifdepth == pp_get_if_depth() && pp_incl_state.state == 1)
			{
				pp_incl_state.state = 2;
				pp_incl_state.seen_junk = 0;
			}
			else if(pp_incl_state.state != 1)
			{
				pp_incl_state.state = -1;
			}
			if(pp_status.debug)
				fprintf(stderr, "tENDIF: %s:%d: include_state=%d, include_ppp='%s', include_ifdepth=%d\n",
					pp_status.input, pp_status.line_number, pp_incl_state.state, pp_incl_state.ppp, pp_incl_state.ifdepth);
		}
		}
#line 1600 "libs/wpp/ppy.tab.c"
    break;

  case 12: /* preprocessor: tUNDEF tIDENT tNL  */
#line 276 "libs/wpp/ppy.y"
                                { pp_del_define((yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1606 "libs/wpp/ppy.tab.c"
    break;

  case 13: /* preprocessor: tDEFINE opt_text tNL  */
#line 277 "libs/wpp/ppy.y"
                                { pp_add_define((yyvsp[-2].cptr), (yyvsp[-1].cptr)); free((yyvsp[-2].cptr)); free((yyvsp[-1].cptr)); }
#line 1612 "libs/wpp/ppy.tab.c"
    break;

  case 14: /* preprocessor: tMACRO res_arg allmargs tMACROEND opt_mtexts tNL  */
#line 278 "libs/wpp/ppy.y"
                                                                {
		pp_add_macro((yyvsp[-5].cptr), macro_args, nmacro_args, (yyvsp[-1].mtext));
		}
#line 1620 "libs/wpp/ppy.tab.c"
    break;

  case 15: /* preprocessor: tLINE tSINT tDQSTRING tNL  */
#line 281 "libs/wpp/ppy.y"
                                        { if((yyvsp[-1].cptr)) pp_writestring("# %d %s\n", (yyvsp[-2].sint) , (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1626 "libs/wpp/ppy.tab.c"
    break;

  case 16: /* preprocessor: tGCCLINE tSINT tDQSTRING tNL  */
#line 282 "libs/wpp/ppy.y"
                                        { if((yyvsp[-1].cptr)) pp_writestring("# %d %s\n", (yyvsp[-2].sint) , (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1632 "libs/wpp/ppy.tab.c"
    break;

  case 17: /* preprocessor: tGCCLINE tSINT tDQSTRING tSINT tNL  */
#line 284 "libs/wpp/ppy.y"
                { if((yyvsp[-2].cptr)) pp_writestring("# %d %s %d\n", (yyvsp[-3].sint), (yyvsp[-2].cptr), (yyvsp[-1].sint)); free((yyvsp[-2].cptr)); }
#line 1638 "libs/wpp/ppy.tab.c"
    break;

  case 18: /* preprocessor: tGCCLINE tSINT tDQSTRING tSINT tSINT tNL  */
#line 286 "libs/wpp/ppy.y"
                { if((yyvsp[-3].cptr)) pp_writestring("# %d %s %d %d\n", (yyvsp[-4].sint) ,(yyvsp[-3].cptr), (yyvsp[-2].sint), (yyvsp[-1].sint)); free((yyvsp[-3].cptr)); }
#line 1644 "libs/wpp/ppy.tab.c"
    break;

  case 19: /* preprocessor: tGCCLINE tSINT tDQSTRING tSINT tSINT tSINT tNL  */
#line 288 "libs/wpp/ppy.y"
                { if((yyvsp[-4].cptr)) pp_writestring("# %d %s %d %d %d\n", (yyvsp[-5].sint) ,(yyvsp[-4].cptr) ,(yyvsp[-3].sint) ,(yyvsp[-2].sint), (yyvsp[-1].sint)); free((yyvsp[-4].cptr)); }
#line 1650 "libs/wpp/ppy.tab.c"
    break;

  case 20: /* preprocessor: tGCCLINE tSINT tDQSTRING tSINT tSINT tSINT tSINT tNL  */
#line 290 "libs/wpp/ppy.y"
                { if((yyvsp[-5].cptr)) pp_writestring("# %d %s %d %d %d %d\n", (yyvsp[-6].sint) ,(yyvsp[-5].cptr) ,(yyvsp[-4].sint) ,(yyvsp[-3].sint), (yyvsp[-2].sint), (yyvsp[-1].sint)); free((yyvsp[-5].cptr)); }
#line 1656 "libs/wpp/ppy.tab.c"
    break;

  case 22: /* preprocessor: tERROR opt_text tNL  */
#line 292 "libs/wpp/ppy.y"
                                { ppy_error("#error directive: '%s'", (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1662 "libs/wpp/ppy.tab.c"
    break;

  case 23: /* preprocessor: tWARNING opt_text tNL  */
#line 293 "libs/wpp/ppy.y"
                                { ppy_warning("#warning directive: '%s'", (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1668 "libs/wpp/ppy.tab.c"
    break;

  case 24: /* preprocessor: tPRAGMA opt_text tNL  */
#line 294 "libs/wpp/ppy.y"
                                { pp_writestring("#pragma %s\n", (yyvsp[-1].cptr) ? (yyvsp[-1].cptr) : ""); free((yyvsp[-1].cptr)); }
#line 1674 "libs/wpp/ppy.tab.c"
    break;

  case 25: /* preprocessor: tPPIDENT opt_text tNL  */
#line 295 "libs/wpp/ppy.y"
                                { if(pp_status.pedantic) ppy_warning("#ident ignored (arg: '%s')", (yyvsp[-1].cptr)); free((yyvsp[-1].cptr)); }
#line 1680 "libs/wpp/ppy.tab.c"
    break;

  case 26: /* preprocessor: tRCINCLUDE tRCINCLUDEPATH  */
#line 296 "libs/wpp/ppy.y"
                                    {
                int nl=strlen((yyvsp[0].cptr)) +3;
                char *fn=pp_xmalloc(nl);
                sprintf(fn,"\"%s\"",(yyvsp[0].cptr));
                pp_do_include(fn,1);
                free((yyvsp[0].cptr));
	}
#line 1692 "libs/wpp/ppy.tab.c"
    break;

  case 27: /* preprocessor: tRCINCLUDE tDQSTRING  */
#line 303 "libs/wpp/ppy.y"
                               {
		pp_do_include((yyvsp[0].cptr),1);
	}
#line 1700 "libs/wpp/ppy.tab.c"
    break;

  case 28: /* opt_text: %empty  */
#line 309 "libs/wpp/ppy.y"
                        { (yyval.cptr) = NULL; }
#line 1706 "libs/wpp/ppy.tab.c"
    break;

  case 29: /* opt_text: text  */
#line 310 "libs/wpp/ppy.y"
                        { (yyval.cptr) = (yyvsp[0].cptr); }
#line 1712 "libs/wpp/ppy.tab.c"
    break;

  case 30: /* text: tLITERAL  */
#line 313 "libs/wpp/ppy.y"
                                { (yyval.cptr) = (yyvsp[0].cptr); }
#line 1718 "libs/wpp/ppy.tab.c"
    break;

  case 31: /* text: tDQSTRING  */
#line 314 "libs/wpp/ppy.y"
                                { (yyval.cptr) = (yyvsp[0].cptr); }
#line 1724 "libs/wpp/ppy.tab.c"
    break;

  case 32: /* text: tSQSTRING  */
#line 315 "libs/wpp/ppy.y"
                                { (yyval.cptr) = (yyvsp[0].cptr); }
#line 1730 "libs/wpp/ppy.tab.c"
    break;

  case 33: /* text: text tLITERAL  */
#line 316 "libs/wpp/ppy.y"
                                { (yyval.cptr) = merge_text((yyvsp[-1].cptr), (yyvsp[0].cptr)); }
#line 1736 "libs/wpp/ppy.tab.c"
    break;

  case 34: /* text: text tDQSTRING  */
#line 317 "libs/wpp/ppy.y"
                                { (yyval.cptr) = merge_text((yyvsp[-1].cptr), (yyvsp[0].cptr)); }
#line 1742 "libs/wpp/ppy.tab.c"
    break;

  case 35: /* text: text tSQSTRING  */
#line 318 "libs/wpp/ppy.y"
                                { (yyval.cptr) = merge_text((yyvsp[-1].cptr), (yyvsp[0].cptr)); }
#line 1748 "libs/wpp/ppy.tab.c"
    break;

  case 36: /* res_arg: %empty  */
#line 321 "libs/wpp/ppy.y"
                        { macro_args = NULL; nmacro_args = 0; }
#line 1754 "libs/wpp/ppy.tab.c"
    break;

  case 37: /* allmargs: %empty  */
#line 324 "libs/wpp/ppy.y"
                                { (yyval.sint) = 0; macro_args = NULL; nmacro_args = 0; }
#line 1760 "libs/wpp/ppy.tab.c"
    break;

  case 38: /* allmargs: emargs  */
#line 325 "libs/wpp/ppy.y"
                                { (yyval.sint) = nmacro_args; }
#line 1766 "libs/wpp/ppy.tab.c"
    break;

  case 39: /* emargs: margs  */
#line 328 "libs/wpp/ppy.y"
                                { (yyval.marg) = (yyvsp[0].marg); }
#line 1772 "libs/wpp/ppy.tab.c"
    break;

  case 40: /* emargs: margs ',' tELLIPSIS  */
#line 329 "libs/wpp/ppy.y"
                                { nmacro_args *= -1; }
#line 1778 "libs/wpp/ppy.tab.c"
    break;

  case 41: /* margs: margs ',' tIDENT  */
#line 332 "libs/wpp/ppy.y"
                                { (yyval.marg) = add_new_marg((yyvsp[0].cptr)); }
#line 1784 "libs/wpp/ppy.tab.c"
    break;

  case 42: /* margs: tIDENT  */
#line 333 "libs/wpp/ppy.y"
                                { (yyval.marg) = add_new_marg((yyvsp[0].cptr)); }
#line 1790 "libs/wpp/ppy.tab.c"
    break;

  case 43: /* opt_mtexts: %empty  */
#line 337 "libs/wpp/ppy.y"
                        { (yyval.mtext) = NULL; }
#line 1796 "libs/wpp/ppy.tab.c"
    break;

  case 44: /* opt_mtexts: mtexts  */
#line 338 "libs/wpp/ppy.y"
                        {
		for((yyval.mtext) = (yyvsp[0].mtext); (yyval.mtext) && (yyval.mtext)->prev; (yyval.mtext) = (yyval.mtext)->prev)
			;
		}
#line 1805 "libs/wpp/ppy.tab.c"
    break;

  case 45: /* mtexts: mtext  */
#line 344 "libs/wpp/ppy.y"
                        { (yyval.mtext) = (yyvsp[0].mtext); }
#line 1811 "libs/wpp/ppy.tab.c"
    break;

  case 46: /* mtexts: mtexts mtext  */
#line 345 "libs/wpp/ppy.y"
                        { (yyval.mtext) = combine_mtext((yyvsp[-1].mtext), (yyvsp[0].mtext)); }
#line 1817 "libs/wpp/ppy.tab.c"
    break;

  case 47: /* mtext: tLITERAL  */
#line 348 "libs/wpp/ppy.y"
                        { (yyval.mtext) = new_mtext((yyvsp[0].cptr), 0, exp_text); }
#line 1823 "libs/wpp/ppy.tab.c"
    break;

  case 48: /* mtext: tDQSTRING  */
#line 349 "libs/wpp/ppy.y"
                        { (yyval.mtext) = new_mtext((yyvsp[0].cptr), 0, exp_text); }
#line 1829 "libs/wpp/ppy.tab.c"
    break;

  case 49: /* mtext: tSQSTRING  */
#line 350 "libs/wpp/ppy.y"
                        { (yyval.mtext) = new_mtext((yyvsp[0].cptr), 0, exp_text); }
#line 1835 "libs/wpp/ppy.tab.c"
    break;

  case 50: /* mtext: tCONCAT  */
#line 351 "libs/wpp/ppy.y"
                        { (yyval.mtext) = new_mtext(NULL, 0, exp_concat); }
#line 1841 "libs/wpp/ppy.tab.c"
    break;

  case 51: /* mtext: tSTRINGIZE tIDENT  */
#line 352 "libs/wpp/ppy.y"
                                {
		int mat = marg_index((yyvsp[0].cptr));
		if(mat < 0)
			ppy_error("Stringification identifier must be an argument parameter");
		else
			(yyval.mtext) = new_mtext(NULL, mat, exp_stringize);
		}
#line 1853 "libs/wpp/ppy.tab.c"
    break;

  case 52: /* mtext: tIDENT  */
#line 359 "libs/wpp/ppy.y"
                        {
		int mat = marg_index((yyvsp[0].cptr));
		if(mat >= 0)
			(yyval.mtext) = new_mtext(NULL, mat, exp_subst);
		else if((yyvsp[0].cptr))
			(yyval.mtext) = new_mtext((yyvsp[0].cptr), 0, exp_text);
		}
#line 1865 "libs/wpp/ppy.tab.c"
    break;

  case 53: /* pp_expr: tSINT  */
#line 368 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint;  (yyval.cval).val.si = (yyvsp[0].sint); }
#line 1871 "libs/wpp/ppy.tab.c"
    break;

  case 54: /* pp_expr: tUINT  */
#line 369 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_uint;  (yyval.cval).val.ui = (yyvsp[0].uint); }
#line 1877 "libs/wpp/ppy.tab.c"
    break;

  case 55: /* pp_expr: tSLONG  */
#line 370 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_slong; (yyval.cval).val.sl = (yyvsp[0].slong); }
#line 1883 "libs/wpp/ppy.tab.c"
    break;

  case 56: /* pp_expr: tULONG  */
#line 371 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_ulong; (yyval.cval).val.ul = (yyvsp[0].ulong); }
#line 1889 "libs/wpp/ppy.tab.c"
    break;

  case 57: /* pp_expr: tSLONGLONG  */
#line 372 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sll;   (yyval.cval).val.sll = (yyvsp[0].sll); }
#line 1895 "libs/wpp/ppy.tab.c"
    break;

  case 58: /* pp_expr: tULONGLONG  */
#line 373 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_ull;   (yyval.cval).val.ull = (yyvsp[0].ull); }
#line 1901 "libs/wpp/ppy.tab.c"
    break;

  case 59: /* pp_expr: tDEFINED tIDENT  */
#line 374 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint;  (yyval.cval).val.si = pplookup((yyvsp[0].cptr)) != NULL; }
#line 1907 "libs/wpp/ppy.tab.c"
    break;

  case 60: /* pp_expr: tDEFINED '(' tIDENT ')'  */
#line 375 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint;  (yyval.cval).val.si = pplookup((yyvsp[-1].cptr)) != NULL; }
#line 1913 "libs/wpp/ppy.tab.c"
    break;

  case 61: /* pp_expr: tIDENT  */
#line 376 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint;  (yyval.cval).val.si = 0; }
#line 1919 "libs/wpp/ppy.tab.c"
    break;

  case 62: /* pp_expr: pp_expr tLOGOR pp_expr  */
#line 377 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint; (yyval.cval).val.si = boolean(&(yyvsp[-2].cval)) || boolean(&(yyvsp[0].cval)); }
#line 1925 "libs/wpp/ppy.tab.c"
    break;

  case 63: /* pp_expr: pp_expr tLOGAND pp_expr  */
#line 378 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint; (yyval.cval).val.si = boolean(&(yyvsp[-2].cval)) && boolean(&(yyvsp[0].cval)); }
#line 1931 "libs/wpp/ppy.tab.c"
    break;

  case 64: /* pp_expr: pp_expr tEQ pp_expr  */
#line 379 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), ==); }
#line 1937 "libs/wpp/ppy.tab.c"
    break;

  case 65: /* pp_expr: pp_expr tNE pp_expr  */
#line 380 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), !=); }
#line 1943 "libs/wpp/ppy.tab.c"
    break;

  case 66: /* pp_expr: pp_expr '<' pp_expr  */
#line 381 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  <); }
#line 1949 "libs/wpp/ppy.tab.c"
    break;

  case 67: /* pp_expr: pp_expr '>' pp_expr  */
#line 382 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  >); }
#line 1955 "libs/wpp/ppy.tab.c"
    break;

  case 68: /* pp_expr: pp_expr tLTE pp_expr  */
#line 383 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), <=); }
#line 1961 "libs/wpp/ppy.tab.c"
    break;

  case 69: /* pp_expr: pp_expr tGTE pp_expr  */
#line 384 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), >=); }
#line 1967 "libs/wpp/ppy.tab.c"
    break;

  case 70: /* pp_expr: pp_expr '+' pp_expr  */
#line 385 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  +); }
#line 1973 "libs/wpp/ppy.tab.c"
    break;

  case 71: /* pp_expr: pp_expr '-' pp_expr  */
#line 386 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  -); }
#line 1979 "libs/wpp/ppy.tab.c"
    break;

  case 72: /* pp_expr: pp_expr '^' pp_expr  */
#line 387 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  ^); }
#line 1985 "libs/wpp/ppy.tab.c"
    break;

  case 73: /* pp_expr: pp_expr '&' pp_expr  */
#line 388 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  &); }
#line 1991 "libs/wpp/ppy.tab.c"
    break;

  case 74: /* pp_expr: pp_expr '|' pp_expr  */
#line 389 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  |); }
#line 1997 "libs/wpp/ppy.tab.c"
    break;

  case 75: /* pp_expr: pp_expr '*' pp_expr  */
#line 390 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  *); }
#line 2003 "libs/wpp/ppy.tab.c"
    break;

  case 76: /* pp_expr: pp_expr '/' pp_expr  */
#line 391 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval),  /); }
#line 2009 "libs/wpp/ppy.tab.c"
    break;

  case 77: /* pp_expr: pp_expr tLSHIFT pp_expr  */
#line 392 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), <<); }
#line 2015 "libs/wpp/ppy.tab.c"
    break;

  case 78: /* pp_expr: pp_expr tRSHIFT pp_expr  */
#line 393 "libs/wpp/ppy.y"
                                        { promote_equal_size(&(yyvsp[-2].cval), &(yyvsp[0].cval)); BIN_OP((yyval.cval), (yyvsp[-2].cval), (yyvsp[0].cval), >>); }
#line 2021 "libs/wpp/ppy.tab.c"
    break;

  case 79: /* pp_expr: '+' pp_expr  */
#line 394 "libs/wpp/ppy.y"
                                        { (yyval.cval) =  (yyvsp[0].cval); }
#line 2027 "libs/wpp/ppy.tab.c"
    break;

  case 80: /* pp_expr: '-' pp_expr  */
#line 395 "libs/wpp/ppy.y"
                                        { UNARY_OP((yyval.cval), (yyvsp[0].cval), -); }
#line 2033 "libs/wpp/ppy.tab.c"
    break;

  case 81: /* pp_expr: '~' pp_expr  */
#line 396 "libs/wpp/ppy.y"
                                        { UNARY_OP((yyval.cval), (yyvsp[0].cval), ~); }
#line 2039 "libs/wpp/ppy.tab.c"
    break;

  case 82: /* pp_expr: '!' pp_expr  */
#line 397 "libs/wpp/ppy.y"
                                        { (yyval.cval).type = cv_sint; (yyval.cval).val.si = !boolean(&(yyvsp[0].cval)); }
#line 2045 "libs/wpp/ppy.tab.c"
    break;

  case 83: /* pp_expr: '(' pp_expr ')'  */
#line 398 "libs/wpp/ppy.y"
                                        { (yyval.cval) =  (yyvsp[-1].cval); }
#line 2051 "libs/wpp/ppy.tab.c"
    break;

  case 84: /* pp_expr: pp_expr '?' pp_expr ':' pp_expr  */
#line 399 "libs/wpp/ppy.y"
                                          { (yyval.cval) = boolean(&(yyvsp[-4].cval)) ? (yyvsp[-2].cval) : (yyvsp[0].cval); }
#line 2057 "libs/wpp/ppy.tab.c"
    break;


#line 2061 "libs/wpp/ppy.tab.c"

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
      yyerror (YY_("syntax error"));
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


#if !defined yyoverflow
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

  return yyresult;
}

#line 402 "libs/wpp/ppy.y"


/*
 **************************************************************************
 * Support functions
 **************************************************************************
 */

static void cast_to_sint(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	break;
	case cv_uint:	break;
	case cv_slong:	v->val.si = v->val.sl;	break;
	case cv_ulong:	v->val.si = v->val.ul;	break;
	case cv_sll:	v->val.si = v->val.sll;	break;
	case cv_ull:	v->val.si = v->val.ull;	break;
	}
	v->type = cv_sint;
}

static void cast_to_uint(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	break;
	case cv_uint:	break;
	case cv_slong:	v->val.ui = v->val.sl;	break;
	case cv_ulong:	v->val.ui = v->val.ul;	break;
	case cv_sll:	v->val.ui = v->val.sll;	break;
	case cv_ull:	v->val.ui = v->val.ull;	break;
	}
	v->type = cv_uint;
}

static void cast_to_slong(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	v->val.sl = v->val.si;	break;
	case cv_uint:	v->val.sl = v->val.ui;	break;
	case cv_slong:	break;
	case cv_ulong:	break;
	case cv_sll:	v->val.sl = v->val.sll;	break;
	case cv_ull:	v->val.sl = v->val.ull;	break;
	}
	v->type = cv_slong;
}

static void cast_to_ulong(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	v->val.ul = v->val.si;	break;
	case cv_uint:	v->val.ul = v->val.ui;	break;
	case cv_slong:	break;
	case cv_ulong:	break;
	case cv_sll:	v->val.ul = v->val.sll;	break;
	case cv_ull:	v->val.ul = v->val.ull;	break;
	}
	v->type = cv_ulong;
}

static void cast_to_sll(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	v->val.sll = v->val.si;	break;
	case cv_uint:	v->val.sll = v->val.ui;	break;
	case cv_slong:	v->val.sll = v->val.sl;	break;
	case cv_ulong:	v->val.sll = v->val.ul;	break;
	case cv_sll:	break;
	case cv_ull:	break;
	}
	v->type = cv_sll;
}

static void cast_to_ull(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	v->val.ull = v->val.si;	break;
	case cv_uint:	v->val.ull = v->val.ui;	break;
	case cv_slong:	v->val.ull = v->val.sl;	break;
	case cv_ulong:	v->val.ull = v->val.ul;	break;
	case cv_sll:	break;
	case cv_ull:	break;
	}
	v->type = cv_ull;
}


static void promote_equal_size(cval_t *v1, cval_t *v2)
{
#define cv_sizeof(v)	((int)(v->type & SIZE_MASK))
	int s1 = cv_sizeof(v1);
	int s2 = cv_sizeof(v2);
#undef cv_sizeof

	if(s1 == s2)
		return;
	else if(s1 > s2)
	{
		switch(v1->type)
		{
		case cv_sint:	cast_to_sint(v2); break;
		case cv_uint:	cast_to_uint(v2); break;
		case cv_slong:	cast_to_slong(v2); break;
		case cv_ulong:	cast_to_ulong(v2); break;
		case cv_sll:	cast_to_sll(v2); break;
		case cv_ull:	cast_to_ull(v2); break;
		}
	}
	else
	{
		switch(v2->type)
		{
		case cv_sint:	cast_to_sint(v1); break;
		case cv_uint:	cast_to_uint(v1); break;
		case cv_slong:	cast_to_slong(v1); break;
		case cv_ulong:	cast_to_ulong(v1); break;
		case cv_sll:	cast_to_sll(v1); break;
		case cv_ull:	cast_to_ull(v1); break;
		}
	}
}


static int boolean(cval_t *v)
{
	switch(v->type)
	{
	case cv_sint:	return v->val.si != 0;
	case cv_uint:	return v->val.ui != 0;
	case cv_slong:	return v->val.sl != 0;
	case cv_ulong:	return v->val.ul != 0;
	case cv_sll:	return v->val.sll != 0;
	case cv_ull:	return v->val.ull != 0;
	}
	return 0;
}

static char *add_new_marg(char *str)
{
	char *ma;
	macro_args = pp_xrealloc(macro_args, (nmacro_args+1) * sizeof(macro_args[0]));
	macro_args[nmacro_args++] = ma = pp_xstrdup(str);
	return ma;
}

static int marg_index(char *id)
{
	int t;
	if(!id)
		return -1;
	for(t = 0; t < nmacro_args; t++)
	{
		if(!strcmp(id, macro_args[t]))
			break;
	}
	return t < nmacro_args ? t : -1;
}

static mtext_t *new_mtext(char *str, int idx, def_exp_t type)
{
	mtext_t *mt = pp_xmalloc(sizeof(mtext_t));

	if(str == NULL)
		mt->subst.argidx = idx;
	else
		mt->subst.text = str;
	mt->type = type;
	mt->next = mt->prev = NULL;
	return mt;
}

static mtext_t *combine_mtext(mtext_t *tail, mtext_t *mtp)
{
	if(!tail)
		return mtp;

	if(!mtp)
		return tail;

	if(tail->type == exp_text && mtp->type == exp_text)
	{
		tail->subst.text = pp_xrealloc(tail->subst.text, strlen(tail->subst.text)+strlen(mtp->subst.text)+1);
		strcat(tail->subst.text, mtp->subst.text);
		free(mtp->subst.text);
		free(mtp);
		return tail;
	}

	if(tail->type == exp_concat && mtp->type == exp_concat)
	{
		free(mtp);
		return tail;
	}

	if(tail->type == exp_concat && mtp->type == exp_text)
	{
		int len = strlen(mtp->subst.text);
		while(len)
		{
/* FIXME: should delete space from head of string */
			if(isspace(mtp->subst.text[len-1] & 0xff))
				mtp->subst.text[--len] = '\0';
			else
				break;
		}

		if(!len)
		{
			free(mtp->subst.text);
			free(mtp);
			return tail;
		}
	}

	if(tail->type == exp_text && mtp->type == exp_concat)
	{
		int len = strlen(tail->subst.text);
		while(len)
		{
			if(isspace(tail->subst.text[len-1] & 0xff))
				tail->subst.text[--len] = '\0';
			else
				break;
		}

		if(!len)
		{
			mtp->prev = tail->prev;
			mtp->next = tail->next;
			if(tail->prev)
				tail->prev->next = mtp;
			free(tail->subst.text);
			free(tail);
			return mtp;
		}
	}

	tail->next = mtp;
	mtp->prev = tail;

	return mtp;
}

static char *merge_text(char *s1, char *s2)
{
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	s1 = pp_xrealloc(s1, l1+l2+1);
	memcpy(s1+l1, s2, l2+1);
	free(s2);
	return s1;
}
