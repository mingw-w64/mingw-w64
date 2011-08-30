/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     aIDENTIFIER = 258,
     aKNOWNTYPE = 259,
     aNUM = 260,
     aHEXNUM = 261,
     aDOUBLE = 262,
     aSTRING = 263,
     aWSTRING = 264,
     aSQSTRING = 265,
     aUUID = 266,
     aEOF = 267,
     SHL = 268,
     SHR = 269,
     MEMBERPTR = 270,
     EQUALITY = 271,
     INEQUALITY = 272,
     GREATEREQUAL = 273,
     LESSEQUAL = 274,
     LOGICALOR = 275,
     LOGICALAND = 276,
     ELLIPSIS = 277,
     tAGGREGATABLE = 278,
     tALLOCATE = 279,
     tANNOTATION = 280,
     tAPPOBJECT = 281,
     tASYNC = 282,
     tASYNCUUID = 283,
     tAUTOHANDLE = 284,
     tBINDABLE = 285,
     tBOOLEAN = 286,
     tBROADCAST = 287,
     tBYTE = 288,
     tBYTECOUNT = 289,
     tCALLAS = 290,
     tCALLBACK = 291,
     tCASE = 292,
     tCDECL = 293,
     tCHAR = 294,
     tCOCLASS = 295,
     tCODE = 296,
     tCOMMSTATUS = 297,
     tCONST = 298,
     tCONTEXTHANDLE = 299,
     tCONTEXTHANDLENOSERIALIZE = 300,
     tCONTEXTHANDLESERIALIZE = 301,
     tCONTROL = 302,
     tCPPQUOTE = 303,
     tDECODE = 304,
     tDEFAULT = 305,
     tDEFAULTBIND = 306,
     tDEFAULTCOLLELEM = 307,
     tDEFAULTVALUE = 308,
     tDEFAULTVTABLE = 309,
     tDISABLECONSISTENCYCHECK = 310,
     tDISPLAYBIND = 311,
     tDISPINTERFACE = 312,
     tDLLNAME = 313,
     tDOUBLE = 314,
     tDUAL = 315,
     tENABLEALLOCATE = 316,
     tENCODE = 317,
     tENDPOINT = 318,
     tENTRY = 319,
     tENUM = 320,
     tERRORSTATUST = 321,
     tEXPLICITHANDLE = 322,
     tEXTERN = 323,
     tFALSE = 324,
     tFASTCALL = 325,
     tFAULTSTATUS = 326,
     tFLOAT = 327,
     tFORCEALLOCATE = 328,
     tHANDLE = 329,
     tHANDLET = 330,
     tHELPCONTEXT = 331,
     tHELPFILE = 332,
     tHELPSTRING = 333,
     tHELPSTRINGCONTEXT = 334,
     tHELPSTRINGDLL = 335,
     tHIDDEN = 336,
     tHYPER = 337,
     tID = 338,
     tIDEMPOTENT = 339,
     tIGNORE = 340,
     tIIDIS = 341,
     tIMMEDIATEBIND = 342,
     tIMPLICITHANDLE = 343,
     tIMPORT = 344,
     tIMPORTLIB = 345,
     tIN = 346,
     tIN_LINE = 347,
     tINLINE = 348,
     tINPUTSYNC = 349,
     tINT = 350,
     tINT3264 = 351,
     tINT64 = 352,
     tINTERFACE = 353,
     tLCID = 354,
     tLENGTHIS = 355,
     tLIBRARY = 356,
     tLICENSED = 357,
     tLOCAL = 358,
     tLONG = 359,
     tMAYBE = 360,
     tMESSAGE = 361,
     tMETHODS = 362,
     tMODULE = 363,
     tNOCODE = 364,
     tNONBROWSABLE = 365,
     tNONCREATABLE = 366,
     tNONEXTENSIBLE = 367,
     tNOTIFY = 368,
     tNOTIFYFLAG = 369,
     tNULL = 370,
     tOBJECT = 371,
     tODL = 372,
     tOLEAUTOMATION = 373,
     tOPTIMIZE = 374,
     tOPTIONAL = 375,
     tOUT = 376,
     tPARTIALIGNORE = 377,
     tPASCAL = 378,
     tPOINTERDEFAULT = 379,
     tPROGID = 380,
     tPROPERTIES = 381,
     tPROPGET = 382,
     tPROPPUT = 383,
     tPROPPUTREF = 384,
     tPROXY = 385,
     tPTR = 386,
     tPUBLIC = 387,
     tRANGE = 388,
     tREADONLY = 389,
     tREF = 390,
     tREGISTER = 391,
     tREPRESENTAS = 392,
     tREQUESTEDIT = 393,
     tRESTRICTED = 394,
     tRETVAL = 395,
     tSAFEARRAY = 396,
     tSHORT = 397,
     tSIGNED = 398,
     tSIZEIS = 399,
     tSIZEOF = 400,
     tSMALL = 401,
     tSOURCE = 402,
     tSTATIC = 403,
     tSTDCALL = 404,
     tSTRICTCONTEXTHANDLE = 405,
     tSTRING = 406,
     tSTRUCT = 407,
     tSWITCH = 408,
     tSWITCHIS = 409,
     tSWITCHTYPE = 410,
     tTHREADING = 411,
     tTRANSMITAS = 412,
     tTRUE = 413,
     tTYPEDEF = 414,
     tUIDEFAULT = 415,
     tUNION = 416,
     tUNIQUE = 417,
     tUNSIGNED = 418,
     tUSESGETLASTERROR = 419,
     tUSERMARSHAL = 420,
     tUUID = 421,
     tV1ENUM = 422,
     tVARARG = 423,
     tVERSION = 424,
     tVIPROGID = 425,
     tVOID = 426,
     tWCHAR = 427,
     tWIREMARSHAL = 428,
     tAPARTMENT = 429,
     tNEUTRAL = 430,
     tSINGLE = 431,
     tFREE = 432,
     tBOTH = 433,
     ADDRESSOF = 434,
     NEG = 435,
     POS = 436,
     PPTR = 437,
     CAST = 438
   };
#endif
/* Tokens.  */
#define aIDENTIFIER 258
#define aKNOWNTYPE 259
#define aNUM 260
#define aHEXNUM 261
#define aDOUBLE 262
#define aSTRING 263
#define aWSTRING 264
#define aSQSTRING 265
#define aUUID 266
#define aEOF 267
#define SHL 268
#define SHR 269
#define MEMBERPTR 270
#define EQUALITY 271
#define INEQUALITY 272
#define GREATEREQUAL 273
#define LESSEQUAL 274
#define LOGICALOR 275
#define LOGICALAND 276
#define ELLIPSIS 277
#define tAGGREGATABLE 278
#define tALLOCATE 279
#define tANNOTATION 280
#define tAPPOBJECT 281
#define tASYNC 282
#define tASYNCUUID 283
#define tAUTOHANDLE 284
#define tBINDABLE 285
#define tBOOLEAN 286
#define tBROADCAST 287
#define tBYTE 288
#define tBYTECOUNT 289
#define tCALLAS 290
#define tCALLBACK 291
#define tCASE 292
#define tCDECL 293
#define tCHAR 294
#define tCOCLASS 295
#define tCODE 296
#define tCOMMSTATUS 297
#define tCONST 298
#define tCONTEXTHANDLE 299
#define tCONTEXTHANDLENOSERIALIZE 300
#define tCONTEXTHANDLESERIALIZE 301
#define tCONTROL 302
#define tCPPQUOTE 303
#define tDECODE 304
#define tDEFAULT 305
#define tDEFAULTBIND 306
#define tDEFAULTCOLLELEM 307
#define tDEFAULTVALUE 308
#define tDEFAULTVTABLE 309
#define tDISABLECONSISTENCYCHECK 310
#define tDISPLAYBIND 311
#define tDISPINTERFACE 312
#define tDLLNAME 313
#define tDOUBLE 314
#define tDUAL 315
#define tENABLEALLOCATE 316
#define tENCODE 317
#define tENDPOINT 318
#define tENTRY 319
#define tENUM 320
#define tERRORSTATUST 321
#define tEXPLICITHANDLE 322
#define tEXTERN 323
#define tFALSE 324
#define tFASTCALL 325
#define tFAULTSTATUS 326
#define tFLOAT 327
#define tFORCEALLOCATE 328
#define tHANDLE 329
#define tHANDLET 330
#define tHELPCONTEXT 331
#define tHELPFILE 332
#define tHELPSTRING 333
#define tHELPSTRINGCONTEXT 334
#define tHELPSTRINGDLL 335
#define tHIDDEN 336
#define tHYPER 337
#define tID 338
#define tIDEMPOTENT 339
#define tIGNORE 340
#define tIIDIS 341
#define tIMMEDIATEBIND 342
#define tIMPLICITHANDLE 343
#define tIMPORT 344
#define tIMPORTLIB 345
#define tIN 346
#define tIN_LINE 347
#define tINLINE 348
#define tINPUTSYNC 349
#define tINT 350
#define tINT3264 351
#define tINT64 352
#define tINTERFACE 353
#define tLCID 354
#define tLENGTHIS 355
#define tLIBRARY 356
#define tLICENSED 357
#define tLOCAL 358
#define tLONG 359
#define tMAYBE 360
#define tMESSAGE 361
#define tMETHODS 362
#define tMODULE 363
#define tNOCODE 364
#define tNONBROWSABLE 365
#define tNONCREATABLE 366
#define tNONEXTENSIBLE 367
#define tNOTIFY 368
#define tNOTIFYFLAG 369
#define tNULL 370
#define tOBJECT 371
#define tODL 372
#define tOLEAUTOMATION 373
#define tOPTIMIZE 374
#define tOPTIONAL 375
#define tOUT 376
#define tPARTIALIGNORE 377
#define tPASCAL 378
#define tPOINTERDEFAULT 379
#define tPROGID 380
#define tPROPERTIES 381
#define tPROPGET 382
#define tPROPPUT 383
#define tPROPPUTREF 384
#define tPROXY 385
#define tPTR 386
#define tPUBLIC 387
#define tRANGE 388
#define tREADONLY 389
#define tREF 390
#define tREGISTER 391
#define tREPRESENTAS 392
#define tREQUESTEDIT 393
#define tRESTRICTED 394
#define tRETVAL 395
#define tSAFEARRAY 396
#define tSHORT 397
#define tSIGNED 398
#define tSIZEIS 399
#define tSIZEOF 400
#define tSMALL 401
#define tSOURCE 402
#define tSTATIC 403
#define tSTDCALL 404
#define tSTRICTCONTEXTHANDLE 405
#define tSTRING 406
#define tSTRUCT 407
#define tSWITCH 408
#define tSWITCHIS 409
#define tSWITCHTYPE 410
#define tTHREADING 411
#define tTRANSMITAS 412
#define tTRUE 413
#define tTYPEDEF 414
#define tUIDEFAULT 415
#define tUNION 416
#define tUNIQUE 417
#define tUNSIGNED 418
#define tUSESGETLASTERROR 419
#define tUSERMARSHAL 420
#define tUUID 421
#define tV1ENUM 422
#define tVARARG 423
#define tVERSION 424
#define tVIPROGID 425
#define tVOID 426
#define tWCHAR 427
#define tWIREMARSHAL 428
#define tAPARTMENT 429
#define tNEUTRAL 430
#define tSINGLE 431
#define tFREE 432
#define tBOTH 433
#define ADDRESSOF 434
#define NEG 435
#define POS 436
#define PPTR 437
#define CAST 438




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 153 "parser.y"
{
	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	array_dims_t *array_dims;
	type_t *type;
	var_t *var;
	var_list_t *var_list;
	declarator_t *declarator;
	declarator_list_t *declarator_list;
	statement_t *statement;
	statement_list_t *stmt_list;
	ifref_t *ifref;
	ifref_list_t *ifref_list;
	char *str;
	UUID *uuid;
	unsigned int num;
	double dbl;
	interface_info_t ifinfo;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
}
/* Line 1529 of yacc.c.  */
#line 442 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE parser_lval;

