

bench.py:
=========

A reasonably quick benchmark that times native Python calculations,
decimal.py, cdecimal.so and gmpy.so.


randdec.py:
===========

Functions for creating random decimals and corner cases. Add your
own testcases if you think that something has not been addressed!


randfloat.py:
=============

More random test cases.


deccheck2.py, deccheck3.py:
===========================

A module that introduces the cdec (for "check decimal") type. The main
purpose is to check cdecimal.so against decimal.py. It supports (almost)
all methods of decimal.py.


ctx-deccheck2.py:
=================

Same as above, but always uses the context methods. deccheck3.py now
test both Decimal and Context methods, so the separate ctx-deccheck3.py
has been removed.


Verification:
-------------

Each calculation involving cdecs is carried out redundantly and the
results are verified. Example:

  c = a + b translates to:

    1. c.dec = a.dec + b.dec

    2. c.mpd = a.mpd + b.mpd

    3. Convert c.dec, c.mpd to strings using both to_sci and to_eng.

    4. Convert c.dec, c.mpd to tuples using as_tuple.

    5. Compare all results and raise an error if they differ.

    6. Compare both contexts and raise an error if they differ.


Known differences:
------------------

In order to have uncluttered output, known differences between
decimal.py and cdecimal.so are silently passed over.


Longer tests:
--------------

deccheck.py takes the arguments --short (default), --medium, --long or
--all.


runall.sh, runall-amd64.bat, runall-i386.bat:
=============================================

Run tests for all installed Python versions. Edit the script if not
all versions from 2.5 through 3.3 are installed.


Valgrind + refleak tests:
=========================

Create the following directory structure. The branch repositories can be
created by using get_all_branches.sh:

hgdir/2.5
hgdir/2.6
hgdir/2.7
hgdir/3.1
hgdir/3.2
hgdir/py3k
hgdir/mpdecimal/python


Change into hgdir/mpdecimal/python and run:

./runall-memorydebugger.sh


[1] See http://docs.python.org/devguide/ for mercurial checkout instructions.


