/* A Bison parser, made by GNU Bison 3.6.2.  */

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
    tAGGREGATABLE = 280,           /* tAGGREGATABLE  */
    tALLOCATE = 281,               /* tALLOCATE  */
    tANNOTATION = 282,             /* tANNOTATION  */
    tAPPOBJECT = 283,              /* tAPPOBJECT  */
    tASYNC = 284,                  /* tASYNC  */
    tASYNCUUID = 285,              /* tASYNCUUID  */
    tAUTOHANDLE = 286,             /* tAUTOHANDLE  */
    tBINDABLE = 287,               /* tBINDABLE  */
    tBOOLEAN = 288,                /* tBOOLEAN  */
    tBROADCAST = 289,              /* tBROADCAST  */
    tBYTE = 290,                   /* tBYTE  */
    tBYTECOUNT = 291,              /* tBYTECOUNT  */
    tCALLAS = 292,                 /* tCALLAS  */
    tCALLBACK = 293,               /* tCALLBACK  */
    tCASE = 294,                   /* tCASE  */
    tCDECL = 295,                  /* tCDECL  */
    tCHAR = 296,                   /* tCHAR  */
    tCOCLASS = 297,                /* tCOCLASS  */
    tCODE = 298,                   /* tCODE  */
    tCOMMSTATUS = 299,             /* tCOMMSTATUS  */
    tCONST = 300,                  /* tCONST  */
    tCONTEXTHANDLE = 301,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 302, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 303, /* tCONTEXTHANDLESERIALIZE  */
    tCONTROL = 304,                /* tCONTROL  */
    tCPPQUOTE = 305,               /* tCPPQUOTE  */
    tDECODE = 306,                 /* tDECODE  */
    tDEFAULT = 307,                /* tDEFAULT  */
    tDEFAULTBIND = 308,            /* tDEFAULTBIND  */
    tDEFAULTCOLLELEM = 309,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 310,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 311,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 312, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 313,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 314,          /* tDISPINTERFACE  */
    tDLLNAME = 315,                /* tDLLNAME  */
    tDOUBLE = 316,                 /* tDOUBLE  */
    tDUAL = 317,                   /* tDUAL  */
    tENABLEALLOCATE = 318,         /* tENABLEALLOCATE  */
    tENCODE = 319,                 /* tENCODE  */
    tENDPOINT = 320,               /* tENDPOINT  */
    tENTRY = 321,                  /* tENTRY  */
    tENUM = 322,                   /* tENUM  */
    tERRORSTATUST = 323,           /* tERRORSTATUST  */
    tEXPLICITHANDLE = 324,         /* tEXPLICITHANDLE  */
    tEXTERN = 325,                 /* tEXTERN  */
    tFALSE = 326,                  /* tFALSE  */
    tFASTCALL = 327,               /* tFASTCALL  */
    tFAULTSTATUS = 328,            /* tFAULTSTATUS  */
    tFLOAT = 329,                  /* tFLOAT  */
    tFORCEALLOCATE = 330,          /* tFORCEALLOCATE  */
    tHANDLE = 331,                 /* tHANDLE  */
    tHANDLET = 332,                /* tHANDLET  */
    tHELPCONTEXT = 333,            /* tHELPCONTEXT  */
    tHELPFILE = 334,               /* tHELPFILE  */
    tHELPSTRING = 335,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 336,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 337,          /* tHELPSTRINGDLL  */
    tHIDDEN = 338,                 /* tHIDDEN  */
    tHYPER = 339,                  /* tHYPER  */
    tID = 340,                     /* tID  */
    tIDEMPOTENT = 341,             /* tIDEMPOTENT  */
    tIGNORE = 342,                 /* tIGNORE  */
    tIIDIS = 343,                  /* tIIDIS  */
    tIMMEDIATEBIND = 344,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 345,         /* tIMPLICITHANDLE  */
    tIMPORT = 346,                 /* tIMPORT  */
    tIMPORTLIB = 347,              /* tIMPORTLIB  */
    tIN = 348,                     /* tIN  */
    tIN_LINE = 349,                /* tIN_LINE  */
    tINLINE = 350,                 /* tINLINE  */
    tINPUTSYNC = 351,              /* tINPUTSYNC  */
    tINT = 352,                    /* tINT  */
    tINT32 = 353,                  /* tINT32  */
    tINT3264 = 354,                /* tINT3264  */
    tINT64 = 355,                  /* tINT64  */
    tINTERFACE = 356,              /* tINTERFACE  */
    tLCID = 357,                   /* tLCID  */
    tLENGTHIS = 358,               /* tLENGTHIS  */
    tLIBRARY = 359,                /* tLIBRARY  */
    tLICENSED = 360,               /* tLICENSED  */
    tLOCAL = 361,                  /* tLOCAL  */
    tLONG = 362,                   /* tLONG  */
    tMAYBE = 363,                  /* tMAYBE  */
    tMESSAGE = 364,                /* tMESSAGE  */
    tMETHODS = 365,                /* tMETHODS  */
    tMODULE = 366,                 /* tMODULE  */
    tNAMESPACE = 367,              /* tNAMESPACE  */
    tNOCODE = 368,                 /* tNOCODE  */
    tNONBROWSABLE = 369,           /* tNONBROWSABLE  */
    tNONCREATABLE = 370,           /* tNONCREATABLE  */
    tNONEXTENSIBLE = 371,          /* tNONEXTENSIBLE  */
    tNOTIFY = 372,                 /* tNOTIFY  */
    tNOTIFYFLAG = 373,             /* tNOTIFYFLAG  */
    tNULL = 374,                   /* tNULL  */
    tOBJECT = 375,                 /* tOBJECT  */
    tODL = 376,                    /* tODL  */
    tOLEAUTOMATION = 377,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 378,               /* tOPTIMIZE  */
    tOPTIONAL = 379,               /* tOPTIONAL  */
    tOUT = 380,                    /* tOUT  */
    tPARTIALIGNORE = 381,          /* tPARTIALIGNORE  */
    tPASCAL = 382,                 /* tPASCAL  */
    tPOINTERDEFAULT = 383,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 384,         /* tPRAGMA_WARNING  */
    tPROGID = 385,                 /* tPROGID  */
    tPROPERTIES = 386,             /* tPROPERTIES  */
    tPROPGET = 387,                /* tPROPGET  */
    tPROPPUT = 388,                /* tPROPPUT  */
    tPROPPUTREF = 389,             /* tPROPPUTREF  */
    tPROXY = 390,                  /* tPROXY  */
    tPTR = 391,                    /* tPTR  */
    tPUBLIC = 392,                 /* tPUBLIC  */
    tRANGE = 393,                  /* tRANGE  */
    tREADONLY = 394,               /* tREADONLY  */
    tREF = 395,                    /* tREF  */
    tREGISTER = 396,               /* tREGISTER  */
    tREPRESENTAS = 397,            /* tREPRESENTAS  */
    tREQUESTEDIT = 398,            /* tREQUESTEDIT  */
    tRESTRICTED = 399,             /* tRESTRICTED  */
    tRETVAL = 400,                 /* tRETVAL  */
    tSAFEARRAY = 401,              /* tSAFEARRAY  */
    tSHORT = 402,                  /* tSHORT  */
    tSIGNED = 403,                 /* tSIGNED  */
    tSIZEIS = 404,                 /* tSIZEIS  */
    tSIZEOF = 405,                 /* tSIZEOF  */
    tSMALL = 406,                  /* tSMALL  */
    tSOURCE = 407,                 /* tSOURCE  */
    tSTATIC = 408,                 /* tSTATIC  */
    tSTDCALL = 409,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 410,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 411,                 /* tSTRING  */
    tSTRUCT = 412,                 /* tSTRUCT  */
    tSWITCH = 413,                 /* tSWITCH  */
    tSWITCHIS = 414,               /* tSWITCHIS  */
    tSWITCHTYPE = 415,             /* tSWITCHTYPE  */
    tTHREADING = 416,              /* tTHREADING  */
    tTRANSMITAS = 417,             /* tTRANSMITAS  */
    tTRUE = 418,                   /* tTRUE  */
    tTYPEDEF = 419,                /* tTYPEDEF  */
    tUIDEFAULT = 420,              /* tUIDEFAULT  */
    tUNION = 421,                  /* tUNION  */
    tUNIQUE = 422,                 /* tUNIQUE  */
    tUNSIGNED = 423,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 424,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 425,            /* tUSERMARSHAL  */
    tUUID = 426,                   /* tUUID  */
    tV1ENUM = 427,                 /* tV1ENUM  */
    tVARARG = 428,                 /* tVARARG  */
    tVERSION = 429,                /* tVERSION  */
    tVIPROGID = 430,               /* tVIPROGID  */
    tVOID = 431,                   /* tVOID  */
    tWCHAR = 432,                  /* tWCHAR  */
    tWIREMARSHAL = 433,            /* tWIREMARSHAL  */
    tAPARTMENT = 434,              /* tAPARTMENT  */
    tNEUTRAL = 435,                /* tNEUTRAL  */
    tSINGLE = 436,                 /* tSINGLE  */
    tFREE = 437,                   /* tFREE  */
    tBOTH = 438,                   /* tBOTH  */
    CAST = 439,                    /* CAST  */
    PPTR = 440,                    /* PPTR  */
    POS = 441,                     /* POS  */
    NEG = 442,                     /* NEG  */
    ADDRESSOF = 443                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 129 "parser.y"

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

#line 281 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_PARSER_TAB_H_INCLUDED  */
