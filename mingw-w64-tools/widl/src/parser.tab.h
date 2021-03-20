/* A Bison parser, made by GNU Bison 3.7.5.  */

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
    tPARTIALIGNORE = 398,          /* tPARTIALIGNORE  */
    tPASCAL = 399,                 /* tPASCAL  */
    tPOINTERDEFAULT = 400,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 401,         /* tPRAGMA_WARNING  */
    tPROGID = 402,                 /* tPROGID  */
    tPROPERTIES = 403,             /* tPROPERTIES  */
    tPROPGET = 404,                /* tPROPGET  */
    tPROPPUT = 405,                /* tPROPPUT  */
    tPROPPUTREF = 406,             /* tPROPPUTREF  */
    tPROXY = 407,                  /* tPROXY  */
    tPTR = 408,                    /* tPTR  */
    tPUBLIC = 409,                 /* tPUBLIC  */
    tRANGE = 410,                  /* tRANGE  */
    tREADONLY = 411,               /* tREADONLY  */
    tREF = 412,                    /* tREF  */
    tREGISTER = 413,               /* tREGISTER  */
    tREPRESENTAS = 414,            /* tREPRESENTAS  */
    tREQUESTEDIT = 415,            /* tREQUESTEDIT  */
    tREQUIRES = 416,               /* tREQUIRES  */
    tRESTRICTED = 417,             /* tRESTRICTED  */
    tRETVAL = 418,                 /* tRETVAL  */
    tRUNTIMECLASS = 419,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 420,              /* tSAFEARRAY  */
    tSHORT = 421,                  /* tSHORT  */
    tSIGNED = 422,                 /* tSIGNED  */
    tSINGLENODE = 423,             /* tSINGLENODE  */
    tSIZEIS = 424,                 /* tSIZEIS  */
    tSIZEOF = 425,                 /* tSIZEOF  */
    tSMALL = 426,                  /* tSMALL  */
    tSOURCE = 427,                 /* tSOURCE  */
    tSTANDARD = 428,               /* tSTANDARD  */
    tSTATIC = 429,                 /* tSTATIC  */
    tSTDCALL = 430,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 431,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 432,                 /* tSTRING  */
    tSTRUCT = 433,                 /* tSTRUCT  */
    tSWITCH = 434,                 /* tSWITCH  */
    tSWITCHIS = 435,               /* tSWITCHIS  */
    tSWITCHTYPE = 436,             /* tSWITCHTYPE  */
    tTHREADING = 437,              /* tTHREADING  */
    tTRANSMITAS = 438,             /* tTRANSMITAS  */
    tTRUE = 439,                   /* tTRUE  */
    tTYPEDEF = 440,                /* tTYPEDEF  */
    tUIDEFAULT = 441,              /* tUIDEFAULT  */
    tUNION = 442,                  /* tUNION  */
    tUNIQUE = 443,                 /* tUNIQUE  */
    tUNSIGNED = 444,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 445,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 446,            /* tUSERMARSHAL  */
    tUUID = 447,                   /* tUUID  */
    tV1ENUM = 448,                 /* tV1ENUM  */
    tVARARG = 449,                 /* tVARARG  */
    tVERSION = 450,                /* tVERSION  */
    tVIPROGID = 451,               /* tVIPROGID  */
    tVOID = 452,                   /* tVOID  */
    tWCHAR = 453,                  /* tWCHAR  */
    tWIREMARSHAL = 454,            /* tWIREMARSHAL  */
    tAPARTMENT = 455,              /* tAPARTMENT  */
    tNEUTRAL = 456,                /* tNEUTRAL  */
    tSINGLE = 457,                 /* tSINGLE  */
    tFREE = 458,                   /* tFREE  */
    tBOTH = 459,                   /* tBOTH  */
    CAST = 460,                    /* CAST  */
    PPTR = 461,                    /* PPTR  */
    POS = 462,                     /* POS  */
    NEG = 463,                     /* NEG  */
    ADDRESSOF = 464                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 123 "tools/widl/parser.y"

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

#line 303 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
