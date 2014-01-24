

libmpdec
========

libmpdec is a fast C/C++ library for correctly-rounded arbitrary precision
decimal floating point arithmetic. It is a complete implementation of
Mike Cowlishaw/IBM's General Decimal Arithmetic Specification. The full
specification is available here:

http://speleotrove.com/decimal/



libmpdec has been tested on the following platforms:

   amd64:  Linux, FreeBSD, OpenBSD, OpenSolaris, Windows

   ppc64:  AIX

   x86:    Linux, FreeBSD, OpenBSD, OpenSolaris, Windows

   mips32: Debian


cdecimal
========

cdecimal is a fast drop-in replacement for the decimal module in Python's
standard library. With some restrictions (See doc/cdecimal/index.html),
code written for decimal.py should work identically.


deccheck.py
===========

deccheck.py performs redundant calculations using both decimal.py and
cdecimal.so. For each calculation the results of both modules are compared
and an exception is raised if they differ.


Contact: Stefan Krah <skrah@bytereef.org>


