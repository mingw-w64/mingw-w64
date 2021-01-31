/* A Bison parser, made by GNU Bison 3.7.4.  */

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

#ifndef YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
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
    tEXCLUSIVETO = 332,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 333,         /* tEXPLICITHANDLE  */
    tEXTERN = 334,                 /* tEXTERN  */
    tFALSE = 335,                  /* tFALSE  */
    tFASTCALL = 336,               /* tFASTCALL  */
    tFAULTSTATUS = 337,            /* tFAULTSTATUS  */
    tFLOAT = 338,                  /* tFLOAT  */
    tFORCEALLOCATE = 339,          /* tFORCEALLOCATE  */
    tHANDLE = 340,                 /* tHANDLE  */
    tHANDLET = 341,                /* tHANDLET  */
    tHELPCONTEXT = 342,            /* tHELPCONTEXT  */
    tHELPFILE = 343,               /* tHELPFILE  */
    tHELPSTRING = 344,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 345,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 346,          /* tHELPSTRINGDLL  */
    tHIDDEN = 347,                 /* tHIDDEN  */
    tHYPER = 348,                  /* tHYPER  */
    tID = 349,                     /* tID  */
    tIDEMPOTENT = 350,             /* tIDEMPOTENT  */
    tIGNORE = 351,                 /* tIGNORE  */
    tIIDIS = 352,                  /* tIIDIS  */
    tIMMEDIATEBIND = 353,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 354,         /* tIMPLICITHANDLE  */
    tIMPORT = 355,                 /* tIMPORT  */
    tIMPORTLIB = 356,              /* tIMPORTLIB  */
    tIN = 357,                     /* tIN  */
    tIN_LINE = 358,                /* tIN_LINE  */
    tINLINE = 359,                 /* tINLINE  */
    tINPUTSYNC = 360,              /* tINPUTSYNC  */
    tINT = 361,                    /* tINT  */
    tINT32 = 362,                  /* tINT32  */
    tINT3264 = 363,                /* tINT3264  */
    tINT64 = 364,                  /* tINT64  */
    tINTERFACE = 365,              /* tINTERFACE  */
    tLCID = 366,                   /* tLCID  */
    tLENGTHIS = 367,               /* tLENGTHIS  */
    tLIBRARY = 368,                /* tLIBRARY  */
    tLICENSED = 369,               /* tLICENSED  */
    tLOCAL = 370,                  /* tLOCAL  */
    tLONG = 371,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 372,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 373,                  /* tMAYBE  */
    tMESSAGE = 374,                /* tMESSAGE  */
    tMETHODS = 375,                /* tMETHODS  */
    tMODULE = 376,                 /* tMODULE  */
    tMTA = 377,                    /* tMTA  */
    tNAMESPACE = 378,              /* tNAMESPACE  */
    tNOCODE = 379,                 /* tNOCODE  */
    tNONBROWSABLE = 380,           /* tNONBROWSABLE  */
    tNONCREATABLE = 381,           /* tNONCREATABLE  */
    tNONE = 382,                   /* tNONE  */
    tNONEXTENSIBLE = 383,          /* tNONEXTENSIBLE  */
    tNOTIFY = 384,                 /* tNOTIFY  */
    tNOTIFYFLAG = 385,             /* tNOTIFYFLAG  */
    tNULL = 386,                   /* tNULL  */
    tOBJECT = 387,                 /* tOBJECT  */
    tODL = 388,                    /* tODL  */
    tOLEAUTOMATION = 389,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 390,               /* tOPTIMIZE  */
    tOPTIONAL = 391,               /* tOPTIONAL  */
    tOUT = 392,                    /* tOUT  */
    tPARTIALIGNORE = 393,          /* tPARTIALIGNORE  */
    tPASCAL = 394,                 /* tPASCAL  */
    tPOINTERDEFAULT = 395,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 396,         /* tPRAGMA_WARNING  */
    tPROGID = 397,                 /* tPROGID  */
    tPROPERTIES = 398,             /* tPROPERTIES  */
    tPROPGET = 399,                /* tPROPGET  */
    tPROPPUT = 400,                /* tPROPPUT  */
    tPROPPUTREF = 401,             /* tPROPPUTREF  */
    tPROXY = 402,                  /* tPROXY  */
    tPTR = 403,                    /* tPTR  */
    tPUBLIC = 404,                 /* tPUBLIC  */
    tRANGE = 405,                  /* tRANGE  */
    tREADONLY = 406,               /* tREADONLY  */
    tREF = 407,                    /* tREF  */
    tREGISTER = 408,               /* tREGISTER  */
    tREPRESENTAS = 409,            /* tREPRESENTAS  */
    tREQUESTEDIT = 410,            /* tREQUESTEDIT  */
    tRESTRICTED = 411,             /* tRESTRICTED  */
    tRETVAL = 412,                 /* tRETVAL  */
    tRUNTIMECLASS = 413,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 414,              /* tSAFEARRAY  */
    tSHORT = 415,                  /* tSHORT  */
    tSIGNED = 416,                 /* tSIGNED  */
    tSINGLENODE = 417,             /* tSINGLENODE  */
    tSIZEIS = 418,                 /* tSIZEIS  */
    tSIZEOF = 419,                 /* tSIZEOF  */
    tSMALL = 420,                  /* tSMALL  */
    tSOURCE = 421,                 /* tSOURCE  */
    tSTANDARD = 422,               /* tSTANDARD  */
    tSTATIC = 423,                 /* tSTATIC  */
    tSTDCALL = 424,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 425,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 426,                 /* tSTRING  */
    tSTRUCT = 427,                 /* tSTRUCT  */
    tSWITCH = 428,                 /* tSWITCH  */
    tSWITCHIS = 429,               /* tSWITCHIS  */
    tSWITCHTYPE = 430,             /* tSWITCHTYPE  */
    tTHREADING = 431,              /* tTHREADING  */
    tTRANSMITAS = 432,             /* tTRANSMITAS  */
    tTRUE = 433,                   /* tTRUE  */
    tTYPEDEF = 434,                /* tTYPEDEF  */
    tUIDEFAULT = 435,              /* tUIDEFAULT  */
    tUNION = 436,                  /* tUNION  */
    tUNIQUE = 437,                 /* tUNIQUE  */
    tUNSIGNED = 438,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 439,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 440,            /* tUSERMARSHAL  */
    tUUID = 441,                   /* tUUID  */
    tV1ENUM = 442,                 /* tV1ENUM  */
    tVARARG = 443,                 /* tVARARG  */
    tVERSION = 444,                /* tVERSION  */
    tVIPROGID = 445,               /* tVIPROGID  */
    tVOID = 446,                   /* tVOID  */
    tWCHAR = 447,                  /* tWCHAR  */
    tWIREMARSHAL = 448,            /* tWIREMARSHAL  */
    tAPARTMENT = 449,              /* tAPARTMENT  */
    tNEUTRAL = 450,                /* tNEUTRAL  */
    tSINGLE = 451,                 /* tSINGLE  */
    tFREE = 452,                   /* tFREE  */
    tBOTH = 453,                   /* tBOTH  */
    CAST = 454,                    /* CAST  */
    PPTR = 455,                    /* PPTR  */
    POS = 456,                     /* POS  */
    NEG = 457,                     /* NEG  */
    ADDRESSOF = 458                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 136 "tools/widl/parser.y"

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

#line 296 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
