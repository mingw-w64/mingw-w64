#!/bin/sh

sed s/@MINGW_HAS_DX@/0/ crt/sdks/_mingw_directx.h.in > defaults/include/sdks/_mingw_directx.h
