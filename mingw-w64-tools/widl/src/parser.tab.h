/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
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


#line 63 "tools/widl/parser.tab.h"

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

#line 322 "tools/widl/parser.tab.h"

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


#line 362 "tools/widl/parser.tab.h"

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
