/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CODECAPI
#define _INC_CODECAPI

#ifdef UUID_GEN
#  define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) \
    OUR_GUID_ENTRY(CODECAPI_##name, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11)
#else
#  ifndef DEFINE_GUIDSTRUCT
#    ifdef __cplusplus
#      define DEFINE_GUIDSTRUCT(g, n) struct n
#      define DEFINE_GUIDNAMED(n) __uuidof(struct n)
#    else
#      define DEFINE_GUIDSTRUCT(g, n) DEFINE_GUIDEX(n)
#      define DEFINE_GUIDNAMED(n) n
#    endif
#  endif
#  ifdef __CRT_UUID_DECL
#    define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) \
       struct CODECAPI_##name; \
       __CRT_UUID_DECL(CODECAPI_##name, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11)
#    define DEFINE_CODECAPI_GUIDNAMED(name) __uuidof(CODECAPI_##name)
#  else
#    define DEFINE_CODECAPI_GUID(name, guidstr, g1,g2,g3,g4,g5,g6,g7,g8,g9,g10,g11) DEFINE_GUIDSTRUCT(guidstr, CODECAPI_##name);
#    define DEFINE_CODECAPI_GUIDNAMED(name) DEFINE_GUIDNAMED(CODECAPI_##name)
#  endif
#endif

  enum eAVEncH264VLevel {
    eAVEncH264VLevel1     = 10,
    eAVEncH264VLevel1_b   = 11,
    eAVEncH264VLevel1_1   = 11,
    eAVEncH264VLevel1_2   = 12,
    eAVEncH264VLevel1_3   = 13,
    eAVEncH264VLevel2     = 20,
    eAVEncH264VLevel2_1   = 21,
    eAVEncH264VLevel2_2   = 22,
    eAVEncH264VLevel3     = 30,
    eAVEncH264VLevel3_1   = 31,
    eAVEncH264VLevel3_2   = 32,
    eAVEncH264VLevel4     = 40,
    eAVEncH264VLevel4_1   = 41,
    eAVEncH264VLevel4_2   = 42,
    eAVEncH264VLevel5     = 50,
    eAVEncH264VLevel5_1   = 51 
  };

  enum eAVEncH264VProfile {
    eAVEncH264VProfile_unknown    = 0,
    eAVEncH264VProfile_Simple     = 66,
    eAVEncH264VProfile_Base       = 66,
    eAVEncH264VProfile_Main       = 77,
    eAVEncH264VProfile_High       = 100,
    eAVEncH264VProfile_422        = 122,
    eAVEncH264VProfile_High10     = 110,
    eAVEncH264VProfile_444        = 144,
    eAVEncH264VProfile_Extended   = 88 
  };

#define STATIC_CODECAPI_AVDecNumWorkerThreads  0x9561c3e8,0xea9e,0x4435,0x9b,0x1e,0xa9,0x3e,0x69,0x18,0x94,0xd8
DEFINE_CODECAPI_GUID(AVDecNumWorkerThreads, "9561c3e8-ea9e-4435-9b1e-a93e691894d8",
                     0x9561c3e8,0xea9e,0x4435,0x9b,0x1e,0xa9,0x3e,0x69,0x18,0x94,0xd8)

#ifndef UUID_GEN
#define CODECAPI_AVDecNumWorkerThreads  DEFINE_CODECAPI_GUIDNAMED(AVDecNumWorkerThreads)
#endif

#endif /*_INC_CODECAPI*/
