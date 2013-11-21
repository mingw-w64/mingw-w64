/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_CODECAPI
#define _INC_CODECAPI

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

#endif /*_INC_CODECAPI*/
