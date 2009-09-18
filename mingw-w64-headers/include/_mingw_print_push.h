/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

/* Undefine __mingw_<printf> macros.  */
#if defined(__USE_MINGW_ANSI_STDIO) && ((__USE_MINGW_ANSI_STDIO + 0) != 0)
#undef fprintf
#undef printf
#undef sprintf
#undef snprintf
#undef vfprintf
#undef vprintf
#undef vsprintf
#undef vsnprintf

/* Redefine to MS specific PRI... and SCN... macros.  */
#if defined(_INTTYPES_H_) && defined(PRId64)
#undef PRId64
#undef PRIdLEAST64
#undef PRIdFAST64
#undef PRIdMAX
#undef PRIi64
#undef PRIiLEAST64
#undef PRIiFAST64
#undef PRIiMAX
#undef PRIo64
#undef PRIoLEAST64
#undef PRIoFAST64
#undef PRIoMAX
#undef PRIu64
#undef PRIuLEAST64
#undef PRIuFAST64
#undef PRIuMAX
#undef PRIx64
#undef PRIxLEAST64
#undef PRIxFAST64
#undef PRIxMAX
#undef PRIX64
#undef PRIXLEAST64
#undef PRIXFAST64
#undef PRIXMAX
#undef SCNd64
#undef SCNdLEAST64
#undef SCNdFAST64
#undef SCNdMAX
#undef SCNi64
#undef SCNiLEAST64
#undef SCNiFAST64
#undef SCNiMAX
#undef SCNo64
#undef SCNoLEAST64
#undef SCNoFAST64
#undef SCNoMAX
#undef SCNx64
#undef SCNxLEAST64
#undef SCNxFAST64
#undef SCNxMAX
#undef SCNu64
#undef SCNuLEAST64
#undef SCNuFAST64
#undef SCNuMAX
#ifdef _WIN64
#undef PRIdPTR
#undef PRIiPTR
#undef PRIoPTR
#undef PRIuPTR
#undef PRIxPTR
#undef PRIXPTR
#undef SCNdPTR
#undef SCNiPTR
#undef SCNoPTR
#undef SCNxPTR
#undef SCNuPTR
#endif

#define PRId64 "I64d"
#define PRIdLEAST64 "I64d"
#define PRIdFAST64 "I64d"
#define PRIdMAX "I64d"
#define PRIi64 "I64i"
#define PRIiLEAST64 "I64i"
#define PRIiFAST64 "I64i"
#define PRIiMAX "I64i"
#define PRIo64 "I64o"
#define PRIoLEAST64 "I64o"
#define PRIoFAST64 "I64o"
#define PRIoMAX "I64o"
#define PRIu64 "I64u"
#define PRIuLEAST64 "I64u"
#define PRIuFAST64 "I64u"
#define PRIuMAX "I64u"
#define PRIx64 "I64x"
#define PRIxLEAST64 "I64x"
#define PRIxFAST64 "I64x"
#define PRIxMAX "I64x"
#define PRIX64 "I64X"
#define PRIXLEAST64 "I64X"
#define PRIXFAST64 "I64X"
#define PRIXMAX "I64X"
#define SCNd64 "I64d"
#define SCNdLEAST64 "I64d"
#define SCNdFAST64 "I64d"
#define SCNdMAX "I64d"
#define SCNi64 "I64i"
#define SCNiLEAST64 "I64i"
#define SCNiFAST64 "I64i"
#define SCNiMAX "I64i"
#define SCNo64 "I64o"
#define SCNoLEAST64 "I64o"
#define SCNoFAST64 "I64o"
#define SCNoMAX "I64o"
#define SCNx64 "I64x"
#define SCNxLEAST64 "I64x"
#define SCNxFAST64 "I64x"
#define SCNxMAX "I64x"
#define SCNu64 "I64u"
#define SCNuLEAST64 "I64u"
#define SCNuFAST64 "I64u"
#define SCNuMAX "I64u"
#ifdef _WIN64
#define PRIdPTR "I64d"
#define PRIiPTR "I64i"
#define PRIoPTR "I64o"
#define PRIuPTR "I64u"
#define PRIxPTR "I64x"
#define PRIXPTR "I64X"
#define SCNdPTR "I64d"
#define SCNiPTR "I64i"
#define SCNoPTR "I64o"
#define SCNxPTR "I64x"
#define SCNuPTR "I64u"
#endif
#endif

#endif /* defined(__USE_MINGW_ANSI_STDIO) && __USE_MINGW_ANSI_STDIO != 0 */

