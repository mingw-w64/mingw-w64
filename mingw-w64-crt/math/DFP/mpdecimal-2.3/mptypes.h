/*
 * Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */


#ifndef MPTYPES_H
#define MPTYPES_H

#if defined(_MSC_VER)
  #define PRIi64 "lld"
  #define PRIu64 "llu"
  #define PRIi32 "d"
  #define PRIu32 "u"
#endif

#if defined(CONFIG_64)
  #if defined(_MSC_VER) || defined(__OpenBSD__) || defined(__APPLE__) || defined(__MINGW32__)
    #define PRI_mpd_uint_t "I64u"
    #define PRI_mpd_size_t "I64u"
    #define PRI_mpd_ssize_t "I64d"
  #else
    #define PRI_mpd_uint_t "lu"
    #define PRI_mpd_size_t "lu"
    #define PRI_mpd_ssize_t "ld"
  #endif
  #define PRI_time_t "ld"
  #define CONV_mpd_ssize_t "L"
  #define ONE_UM 1ULL
#elif defined(CONFIG_32)
  #define PRI_mpd_uint_t "u"
  #define PRI_mpd_size_t "u"
  #define PRI_mpd_ssize_t "d"
  #if defined (__OpenBSD__)
    #undef PRI_mpd_size_t
    #define PRI_mpd_size_t "lu"
    #define PRI_time_t "d"
  #elif defined(__FreeBSD__)
    #if defined(__x86_64__)
      #define PRI_time_t "ld"
    #else
      #define PRI_time_t "d"
    #endif
  #else
    #define PRI_time_t "ld"
  #endif
  #if MPD_SSIZE_MAX != INT_MAX
    #error "define CONV_mpd_ssize_t"
  #endif
  #define CONV_mpd_ssize_t "i"
  #define ONE_UM 1UL
#else
  #error "define CONFIG_64 or CONFIG_32"
#endif

#endif


