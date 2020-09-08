/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_PARSER_PARSER_TAB_H_INCLUDED
# define YY_PARSER_PARSER_TAB_H_INCLUDED
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

#line 282 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_PARSER_TAB_H_INCLUDED  */
