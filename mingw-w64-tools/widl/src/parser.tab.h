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

#line 302 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */
