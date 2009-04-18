#!/bin/sh 
C_OBJS=$1

for i in ${C_OBJS}; do $i>./mingw.org/$i; done
for i in ${C_OBJS}; do diff -u expected/$i ./mingw.org/$i; done
