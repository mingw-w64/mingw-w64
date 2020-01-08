#!/bin/sh

sed s/@MINGW_HAS_DDK@/0/ crt/sdks/_mingw_ddk.h.in > defaults/include/sdks/_mingw_ddk.h
