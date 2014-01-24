#!/usr/bin/env python

#
# Copyright (c) 2008-2010 Stefan Krah. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS "AS IS" AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
# OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
# HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
# OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
# SUCH DAMAGE.
#


#
# The cdec (for "check decimal") class checks cdecimal.so against decimal.py.
# A cdec object consists of a cdecimal.Decimal and a decimal.Decimal. Every
# operation is carried out on both types. If the results don't match, an
# exception is raised.
#
# Usage: python deccheck.py [--short|--medium|--long|--all]
#


import cdecimal, decimal
import sys, inspect
import array
import random

from copy import copy
from randdec import *


EXIT_STATUS = 0
# Python 2.5 can require exorbitant amounts of memory for hashing integers.
PY25_HASH_HAVE_WARNED = 0
# Python 2.5 bug in _dlog10.
PY25_DLOG10_HAVE_WARNED = 0

py_minor = sys.version_info[1]
py_micro = sys.version_info[2]
if py_minor >= 7:
    from randfloat import *
HAVE_FORMATHELPER = True
try:
    from formathelper import rand_format, rand_locale
except:
    HAVE_FORMATHELPER = False

if py_minor == 5 and py_micro <= 4:
    # decimal.py has additional bugs, not worth sorting them out individually.
    sys.stderr.write("""
#
# Error: deccheck2.py tests cdecimal against decimal.py. For several Python
# versions, deccheck2.py suppresses known bugs in decimal.py in the output.
# In versions 2.5.0 through 2.5.4, decimal.py has additional bugs which are
# not discarded, so the output is too verbose to be useful.
#
# cdecimal should work fine, nevertheless it is recommended to upgrade
# Python to version 2.5.5 or 2.6.6.
#

""")
    sys.exit(1)


# Translate symbols.
deccond = {
        cdecimal.Clamped:             decimal.Clamped,
        cdecimal.ConversionSyntax:    decimal.ConversionSyntax,
        cdecimal.DivisionByZero:      decimal.DivisionByZero,
        cdecimal.DivisionImpossible:  decimal.InvalidOperation,
        cdecimal.DivisionUndefined:   decimal.DivisionUndefined,
        cdecimal.Inexact:             decimal.Inexact,
        cdecimal.InvalidContext:      decimal.InvalidContext,
        cdecimal.InvalidOperation:    decimal.InvalidOperation,
        cdecimal.Overflow:            decimal.Overflow,
        cdecimal.Rounded:             decimal.Rounded,
        cdecimal.Subnormal:           decimal.Subnormal,
        cdecimal.Underflow:           decimal.Underflow,
}

mpdcond = {
        decimal.Clamped:           cdecimal.Clamped,
        decimal.ConversionSyntax:  cdecimal.ConversionSyntax,
        decimal.DivisionByZero:    cdecimal.DivisionByZero,
        decimal.InvalidOperation:  cdecimal.DivisionImpossible,
        decimal.DivisionUndefined: cdecimal.DivisionUndefined,
        decimal.Inexact:           cdecimal.Inexact,
        decimal.InvalidContext:    cdecimal.InvalidContext,
        decimal.InvalidOperation:  cdecimal.InvalidOperation,
        decimal.Overflow:          cdecimal.Overflow,
        decimal.Rounded:           cdecimal.Rounded,
        decimal.Subnormal:         cdecimal.Subnormal,
        decimal.Underflow:         cdecimal.Underflow
}

decround = {
        cdecimal.ROUND_UP:           decimal.ROUND_UP,
        cdecimal.ROUND_DOWN:         decimal.ROUND_DOWN,
        cdecimal.ROUND_CEILING:      decimal.ROUND_CEILING,
        cdecimal.ROUND_FLOOR:        decimal.ROUND_FLOOR,
        cdecimal.ROUND_HALF_UP:      decimal.ROUND_HALF_UP,
        cdecimal.ROUND_HALF_DOWN:    decimal.ROUND_HALF_DOWN,
        cdecimal.ROUND_HALF_EVEN:    decimal.ROUND_HALF_EVEN,
        cdecimal.ROUND_05UP:         decimal.ROUND_05UP
}


class Context(object):
    """Provides a convenient way of syncing the cdecimal and decimal contexts"""

    __slots__ = ['f', 'd']

    def __init__(self, mpdctx=cdecimal.getcontext()):
        """Initialization is from the cdecimal context"""
        self.f = mpdctx
        self.d = decimal.getcontext()
        self.d.prec = self.f.prec
        self.d.Emin = self.f.Emin
        self.d.Emax = self.f.Emax
        self.d.rounding = decround[self.f.rounding]
        self.d.capitals = self.f.capitals
        self.settraps([sig for sig in self.f.traps if self.f.traps[sig]])
        self.setstatus([sig for sig in self.f.flags if self.f.flags[sig]])
        self.d._clamp = self.f._clamp

    def getprec(self):
        assert(self.f.prec == self.d.prec)
        return self.f.prec

    def setprec(self, val):
        self.f.prec = val
        self.d.prec = val

    def getemin(self):
        assert(self.f.Emin == self.d.Emin)
        return self.f.Emin

    def setemin(self, val):
        self.f.Emin = val
        self.d.Emin = val

    def getemax(self):
        assert(self.f.Emax == self.d.Emax)
        return self.f.Emax

    def setemax(self, val):
        self.f.Emax = val
        self.d.Emax = val

    def getround(self):
        return self.d.rounding

    def setround(self, val):
        self.f.rounding = val
        self.d.rounding = decround[val]

    def getcapitals(self):
        assert(self.f.capitals == self.d.capitals)
        return self.f.capitals

    def setcapitals(self, val):
        self.f.capitals = val
        self.d.capitals = val

    def getclamp(self):
        assert(self.f._clamp == self.d._clamp)
        return self.f._clamp

    def setclamp(self, val):
        self.f._clamp = val
        self.d._clamp = val

    prec = property(getprec, setprec)
    Emin = property(getemin, setemin)
    Emax = property(getemax, setemax)
    rounding = property(getround, setround)
    clamp = property(getclamp, setclamp)
    capitals = property(getcapitals, setcapitals)

    def clear_traps(self):
        self.f.clear_traps()
        for trap in self.d.traps:
            self.d.traps[trap] = False

    def clear_status(self):
        self.f.clear_flags()
        self.d.clear_flags()

    def settraps(self, lst): # cdecimal signal list
        self.clear_traps()
        for signal in lst:
            self.f.traps[signal] = True
            self.d.traps[deccond[signal]] = True

    def setstatus(self, lst): # cdecimal signal list
        self.clear_status()
        for signal in lst:
            self.f.flags[signal] = True
            self.d.flags[deccond[signal]] = True

    def assert_eq_status(self):
        """assert equality of cdecimal and decimal status"""
        for signal in self.f.flags:
            if signal == cdecimal.FloatOperation:
                continue
            if self.f.flags[signal] == (not self.d.flags[deccond[signal]]):
                return False
        return True


# We don't want exceptions so that we can compare the status flags.
context = Context()
context.Emin = cdecimal.MIN_EMIN
context.Emax = cdecimal.MAX_EMAX
context.clear_traps()

# When creating decimals, cdecimal is ultimately limited by the maximum
# context values. We emulate this restriction for decimal.py.
maxcontext = decimal.Context(
    prec=cdecimal.MAX_PREC,
    Emin=cdecimal.MIN_EMIN,
    Emax=cdecimal.MAX_EMAX,
    rounding=decimal.ROUND_HALF_UP,
    capitals=1
)
maxcontext._clamp = 0

def decimal_new(value):
    maxcontext.traps = copy(context.d.traps)
    maxcontext.clear_flags()
    dec = maxcontext.create_decimal(value)
    if maxcontext.flags[decimal.Inexact] or \
       maxcontext.flags[decimal.Rounded]:
        dec = decimal.Decimal("NaN")
        context.d.flags[decimal.InvalidOperation] = True
    return dec


_exc_fmt = "\
cdecimal_sci: %s\n\
decimal_sci:  %s\n\
cdecimal_eng: %s\n\
decimal_eng:  %s\n"

_exc_fmt_tuple = "\
cdecimal_tuple: %s\n\
decimal_tuple: %s\n"

_exc_fmt_obj = "\
cdecimal: %s\n\
decimal:  %s\n\n"

class CdecException(ArithmeticError):
    def __init__(self, result, funcname, operands, fctxstr, dctxstr):
        self.errstring = "Error in %s(%s" % (funcname, operands[0])
        for op in operands[1:]:
            self.errstring += ", %s" % op
        self.errstring += "):\n\n"
        if isinstance(result, cdec):
            self.errstring += _exc_fmt % (str(result.mpd),
                                          str(result.dec),
                                          result.mpd.to_eng(),
                                          result.dec.to_eng_string())
            mpd_tuple = result.mpd.as_tuple()
            dec_tuple = result.dec.as_tuple()
            if mpd_tuple != dec_tuple:
                self.errstring += _exc_fmt_tuple % (str(mpd_tuple),
                                                    str(dec_tuple))
        else:
            self.errstring += _exc_fmt_obj % (str(result[0]), str(result[1]))
        self.errstring += "%s\n%s\n\n" % (fctxstr, dctxstr)
    def __str__(self):
        return self.errstring


class dHandlerCdec:
    """For cdec return values:

       Handle known disagreements between decimal.py and cdecimal.so.
       This is just a temporary measure against cluttered output.
       Detection is crude and possibly unreliable."""

    def __init__(self):
        self.logb_round_if_gt_prec = 0
        self.ulpdiff = 0
        self.powmod_zeros = 0
        self.total_mag_nan = 0
        self.quantize_status = 0
        self.max_status = 0
        self.maxctx = decimal.Context(Emax=10**18, Emin=-10**18)

    def default(self, result, operands):
        return False

    def harrison_ulp(self, dec):
        """Harrison ULP: ftp://ftp.inria.fr/INRIA/publication/publi-pdf/RR/RR-5504.pdf"""
        a = dec.next_plus()
        b = dec.next_minus()
        return abs(a - b)

    def standard_ulp(self, dec, prec):
        return decimal._dec_from_triple(0, '1', dec._exp+len(dec._int)-prec)

    def rounding_direction(self, x, mode):
        """Determine the effective direction of the rounding when
           the exact result x is rounded according to mode.
           Return -1 for downwards, 0 for undirected, 1 for upwards,
           2 for ROUND_05UP."""
        d = decimal
        cmp = 1 if x.compare_total(d.Decimal("+0")) >= 0 else -1

        if mode in (d.ROUND_HALF_EVEN, d.ROUND_HALF_UP, d.ROUND_HALF_DOWN):
            return 0
        elif mode == d.ROUND_CEILING:
            return 1
        elif mode == d.ROUND_FLOOR:
            return -1
        elif mode == d.ROUND_UP:
            return cmp
        elif mode == d.ROUND_DOWN:
            return -cmp
        elif mode == d.ROUND_05UP:
            return 2
        else:
            raise ValueError("Unexpected rounding mode: %s" % mode)

    def check_ulpdiff(self, exact, rounded):
        # current precision
        p = context.d.prec

        # Convert infinities to the largest representable number + 1.
        x = exact
        if exact.is_infinite():
            x = decimal._dec_from_triple(exact._sign, '10', context.d.Emax)
        y = rounded
        if rounded.is_infinite():
            y = decimal._dec_from_triple(rounded._sign, '10', context.d.Emax)

        # err = (rounded - exact) / ulp(rounded)
        self.maxctx.prec = p * 2
        t = self.maxctx.subtract(y, x)
        if context.f._flags & cdecimal.DecClamped or \
           context.f._flags & cdecimal.DecUnderflow:
            # The standard ulp does not work in Underflow territory.
            ulp = self.harrison_ulp(y)
        else:
            ulp = self.standard_ulp(y, p)
        # Error in ulps.
        err = self.maxctx.divide(t, ulp)

        d = decimal
        dir = self.rounding_direction(x, context.d.rounding)
        if dir == 0:
            if d.Decimal("-0.6") < err < d.Decimal("0.6"):
                return True
        elif dir == 1: # directed, upwards
            if d.Decimal("-0.1") < err < d.Decimal("1.1"):
                return True
        elif dir == -1: # directed, downwards
            if d.Decimal("-1.1") < err < d.Decimal("0.1"):
                return True
        else: # ROUND_05UP
            if d.Decimal("-1.1") < err < d.Decimal("1.1"):
                return True

        print("ulp: %s  error: %s  exact: %s  mpd_rounded: %s"
              % (ulp, err, exact, rounded))
        return False

    def un_resolve_ulp(self, result, funcname, operands):
        """Check if results of cdecimal's exp, ln and log10 functions are
           within the allowed ulp ranges. This function is only called if
           context.f._allcr is 0."""
        # "exact" result, double precision, half_even
        self.maxctx.prec = context.d.prec * 2
        op = operands[0].dec
        exact = getattr(op, funcname)(context=self.maxctx)

        # cdecimal's rounded result
        s = str(result.mpd)
        rounded = decimal.Decimal(s)

        self.ulpdiff += 1
        return self.check_ulpdiff(exact, rounded)

    def bin_resolve_ulp(self, result, funcname, operands):
        """Check if results of cdecimal's power function are within the
           allowed ulp ranges."""
        # "exact" result, double precision, half_even
        self.maxctx.prec = context.d.prec * 2
        op1 = operands[0].dec
        op2 = operands[1].dec
        exact = getattr(op1, funcname)(op2, context=self.maxctx)

        # cdecimal's rounded result
        s = str(result.mpd)
        rounded = decimal.Decimal(s)

        self.ulpdiff += 1
        return self.check_ulpdiff(exact, rounded)

    def resolve_underflow(self, result):
        """In extremely rare cases where the infinite precision result is just
           below etiny, cdecimal does not set Subnormal/Underflow. Example:

           setcontext(Context(prec=21, rounding=ROUND_UP, Emin=-55, Emax=85))
           Decimal("1.00000000000000000000000000000000000000000000000"
                   "0000000100000000000000000000000000000000000000000"
                   "0000000000000025").ln()
        """
        if str(result.mpd) != str(result.dec):
            return False # Results must be identical.
        if context.f.flags[cdecimal.Rounded] and \
           context.f.flags[cdecimal.Inexact] and \
           context.d.flags[decimal.Rounded] and \
           context.d.flags[decimal.Inexact]:
            return True # Subnormal/Underflow may be missing.
        return False

    def exp(self, result, operands):
        if result.mpd.is_nan() or result.dec.is_nan():
            return False
        if context.f._allcr:
            return self.resolve_underflow(result)
        return self.un_resolve_ulp(result, "exp", operands)

    def log10(self, result, operands):
        if result.mpd.is_nan() or result.dec.is_nan():
            return False
        if context.f._allcr:
            return self.resolve_underflow(result)
        return self.un_resolve_ulp(result, "log10", operands)

    def ln(self, result, operands):
        if result.mpd.is_nan() or result.dec.is_nan():
            return False
        if context.f._allcr:
            return self.resolve_underflow(result)
        return self.un_resolve_ulp(result, "ln", operands)

    def __pow__(self, result, operands):
        if operands[2] is not None: # three argument __pow__
            # issue7049: third arg must fit into precision
            if (operands[0].mpd.is_zero() != operands[1].mpd.is_zero()):
                if (result.mpd == 0 or result.mpd == 1) and result.dec.is_nan():
                    if (not context.f.flags[cdecimal.InvalidOperation]) and \
                       context.d.flags[decimal.InvalidOperation]:
                        self.powmod_zeros += 1
                        return True
            # issue7049: ideal exponent
            if decimal.Decimal(str(result.mpd)) == result.dec:
                return True
        elif result.mpd.is_nan() or result.dec.is_nan():
            return False
        elif context.f.flags[cdecimal.Rounded] and \
             context.f.flags[cdecimal.Inexact] and \
             context.d.flags[decimal.Rounded] and \
             context.d.flags[decimal.Inexact]:
            # decimal.py: correctly-rounded pow()
            return self.bin_resolve_ulp(result, "__pow__", operands)
        else:
            return False
    power = __pow__

    def __radd__(self, result, operands):
        """decimal.py gives preference to the first nan"""
        if operands[0].mpd.is_nan() and operands[1].mpd.is_nan() and \
           result.mpd.is_nan() and result.dec.is_nan():
            return True
        return False
    __rmul__ = __radd__

    # Fixed in 2.7.2.
    def plus(self, result, operands):
        """special cases for zero/ROUND_FLOOR"""
        if context.f.rounding == cdecimal.ROUND_FLOOR:
            if operands[0].mpd.is_zero():
                return True
        return False
    minus = __neg__ = __pos__ = plus

    if py_minor <= 6:
        def rotate(self, result, operands):
            """truncate excess digits before the operation"""
            if len(operands[0].dec._int) > context.f.prec:
                return True
            return False
        shift = rotate

        def compare_total_mag(self, result, operands):
            """fixed in Python2.6.?"""
            if operands[0].mpd.is_nan() and operands[1].mpd.is_nan() and \
               abs(result.mpd) == 1 and abs(result.dec) == 1:
                self.total_mag_nan += 1
                return True
            return False
        compare_total = compare_total_mag

        def logb(self, result, operands):
            """fixed in Python2.6.?"""
            if context.f.flags[cdecimal.Rounded] and \
               (not context.d.flags[decimal.Rounded]):
                self.logb_round_if_gt_prec += 1
                return True
            return False

        def max(self, result, operands):
            if py_minor <= 5 or py_micro <= 1:
                # broken in multiple ways, fixed in 2.6.2
                return True
            # hack, since is_nan() appears to be broken on the result
            if (not result.mpd.is_nan()) and 'sNaN' in result.dec.to_eng_string():
                return True
            if context.f.flags[cdecimal.Subnormal] and \
               (not context.d.flags[decimal.Subnormal]):
                self.max_status += 1
                return True
            return False
        max_mag = max
        min = max
        min_mag = max


class dHandlerObj():
    """For non-decimal return values:

       Handle known disagreements between decimal.py and cdecimal.so."""

    def __init__(self):
        pass

    def default(self, result, operands):
        return False
    __ge__ =  __gt__ = __le__ = __lt__ = __str__ = __repr__ = default

    if py_minor >= 7:
        __ne__ = __eq__ = default

    if py_minor <= 6:
        def __eq__(self, result, operands):
            """cdecimal raises for all sNaN comparisons"""
            if operands[0].mpd.is_snan() or operands[1].mpd.is_snan():
                return True
            return False
        __ne__ = __eq__

    if py_minor <= 6:
        # Fixed in release26-maint, but a lot of distributed
        # versions do not have the fix yet.
        def is_normal(self, result, operands):
            # Issue7099
            if operands[0].mpd.is_normal():
                return True
            return False

    if py_minor <= 5:
        """decimal.py uses double quotes instead of single quotes."""
        def __repr__(self, result, operands):
            return True


dhandler_cdec = dHandlerCdec()
def cdec_known_disagreement(result, funcname, operands):
    return getattr(dhandler_cdec, funcname, dhandler_cdec.default)(result, operands)

dhandler_obj = dHandlerObj()
def obj_known_disagreement(result, funcname, operands):
    return getattr(dhandler_obj, funcname, dhandler_obj.default)(result, operands)



def verify(result, funcname, operands):
    """Verifies that after operation 'funcname' with operand(s) 'operands'
       result[0] and result[1] as well as the context flags have the same
       values."""
    global EXIT_STATUS
    if result[0] != result[1] or not context.assert_eq_status():
        if obj_known_disagreement(result, funcname, operands):
            return # skip known disagreements
        EXIT_STATUS = 1
        raise CdecException(result, funcname, operands,
                            str(context.f), str(context.d))


class cdec(object):
    """Joins cdecimal.so and decimal.py for redundant calculations
       with error checking."""

    __slots__ = ['mpd', 'dec']

    def __new__(cls, value=None):
        self = object.__new__(cls)
        self.mpd = None
        self.dec = None
        if value is not None:
            context.clear_status()
            if py_minor <= 6 and isinstance(value, float):
                self.mpd = cdecimal.Decimal.from_float(value)
                self.dec = decimal.Decimal.from_float(value)
            else:
                self.mpd = cdecimal.Decimal(value)
                self.dec = decimal_new(value)
            self.verify('__xnew__', (value,))
        return self

    def verify(self, funcname, operands):
        """Verifies that after operation 'funcname' with operand(s) 'operands'
           self.mpd and self.dec as well as the context flags have the same
           values."""
        global EXIT_STATUS
        mpdstr = str(self.mpd)
        decstr = str(self.dec)
        mpdstr_eng = self.mpd.to_eng_string()
        decstr_eng = self.dec.to_eng_string()
        mpd_tuple = self.mpd.as_tuple()
        dec_tuple = self.dec.as_tuple()
        if mpd_tuple != dec_tuple: # XXX
            if mpd_tuple[2] == 'F' and dec_tuple[2] == 'F' and \
               mpd_tuple[1] == () and dec_tuple[1] == (0,):
                return
        if mpdstr != decstr or mpdstr_eng != decstr_eng or mpd_tuple != dec_tuple \
           or not context.assert_eq_status():
            if cdec_known_disagreement(self, funcname, operands):
                return # skip known disagreements
            EXIT_STATUS = 1
            raise CdecException(self, funcname, operands,
                                str(context.f), str(context.d))

    def unaryfunc(self, funcname):
        "unary function returning a cdec"
        context.clear_status()
        c = cdec()
        c.mpd = getattr(self.mpd, funcname)()
        c.dec = getattr(self.dec, funcname)()
        c.verify(funcname, (self,))
        return c

    def unaryfunc_ctx(self, funcname):
        "unary function returning a cdec, uses the context methods of decimal.py"
        context.clear_status()
        c = cdec()
        c.mpd = getattr(self.mpd, funcname)()
        c.dec = getattr(context.d, funcname)(self.dec)
        c.verify(funcname, (self,))
        return c

    def obj_unaryfunc(self, funcname):
        "unary function returning an object other than a cdec"
        context.clear_status()
        r_mpd = getattr(self.mpd, funcname)()
        r_dec = getattr(self.dec, funcname)()
        verify((r_mpd, r_dec), funcname, (self,))
        return r_mpd

    def binaryfunc(self, other, funcname):
        "binary function returning a cdec"
        context.clear_status()
        c = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        c.mpd = getattr(self.mpd, funcname)(other_mpd)
        c.dec = getattr(self.dec, funcname)(other_dec)
        c.verify(funcname, (self, other))
        return c

    def binaryfunc_ctx(self, other, funcname):
        "binary function returning a cdec, uses the context methods of decimal.py"
        context.clear_status()
        c = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        c.mpd = getattr(self.mpd, funcname)(other_mpd)
        c.dec = getattr(context.d, funcname)(self.dec, other_dec)
        c.verify(funcname, (self, other))
        return c

    def obj_binaryfunc(self, other, funcname):
        "binary function returning an object other than a cdec"
        context.clear_status()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        r_mpd = getattr(self.mpd, funcname)(other_mpd)
        r_dec = getattr(self.dec, funcname)(other_dec)
        verify((r_mpd, r_dec), funcname, (self, other))
        return r_mpd

    def ternaryfunc(self, other, third, funcname):
        "ternary function returning a cdec"
        context.clear_status()
        c = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        third_mpd = third_dec = third
        if isinstance(third, cdec):
            third_mpd = third.mpd
            third_dec = third.dec
        c.mpd = getattr(self.mpd, funcname)(other_mpd, third_mpd)
        c.dec = getattr(self.dec, funcname)(other_dec, third_dec)
        c.verify(funcname, (self, other, third))
        return c

    def __abs__(self):
        return self.unaryfunc('__abs__')

    def __add__(self, other):
        return self.binaryfunc(other, '__add__')

    def __copy__(self):
        return self.unaryfunc('__copy__')

    def __deepcopy__(self, memo=None):
        context.clear_status()
        c = cdec()
        c.mpd = self.mpd.__deepcopy__(memo)
        c.dec = self.dec.__deepcopy__(memo)
        c.verify('__deepcopy__', (self,))
        return c

    def __div__(self, other):
        return self.binaryfunc(other, '__div__')

    def __divmod__(self, other):
        context.clear_status()
        q = cdec()
        r = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        q.mpd, r.mpd = self.mpd.__divmod__(other_mpd)
        q.dec, r.dec = self.dec.__divmod__(other_dec, context.d)
        q.verify('__divmod__', (self, other))
        r.verify('__divmod__', (self, other))
        return (q, r)

    def __eq__(self, other):
        return self.obj_binaryfunc(other, '__eq__')

    def __float__(self):
        if (self.mpd.is_nan() and self.dec.is_nan()):
            return float("NaN")
        try:
            return self.obj_unaryfunc('__float__')
        except ValueError:
            return None

    def __floordiv__(self, other):
        return self.binaryfunc(other, '__floordiv__')

    def __ge__(self, other):
        return self.obj_binaryfunc(other, '__ge__')

    def __gt__(self, other):
        return self.obj_binaryfunc(other, '__gt__')

    def __hash__(self):
        global PY25_HASH_HAVE_WARNED
        if self.mpd.is_snan() or (py_minor <= 6 and self.mpd.is_nan()):
            return None # for testing
            raise ValueError('Cannot hash a NaN value.')
        ret = None
        try: # Python 2.5 can use exorbitant amounts of memory
            ret = self.obj_unaryfunc('__hash__')
        except MemoryError:
            if not PY25_HASH_HAVE_WARNED:
                sys.stderr.write("Out of memory while hashing %s: upgrade to Python 2.6\n"
                                 % str(self.mpd))
                PY25_HASH_HAVE_WARNED = 1
        return ret

    def __int__(self):
        # ValueError or OverflowError
        if self.mpd.is_special():
            return (None, None)
        return self.obj_unaryfunc('__int__')

    def __le__(self, other):
        return self.obj_binaryfunc(other, '__le__')

    def __long__(self):
        # ValueError or OverflowError
        if self.mpd.is_special():
            return (None, None)
        return self.obj_unaryfunc('__long__')

    def __lt__(self, other):
        return self.obj_binaryfunc(other, '__lt__')

    def __mod__(self, other):
        return self.binaryfunc(other, '__mod__')

    def __mul__(self, other):
        return self.binaryfunc(other, '__mul__')

    def __ne__(self, other):
        return self.obj_binaryfunc(other, '__ne__')

    def __neg__(self):
        return self.unaryfunc('__neg__')

    def __nonzero__(self):
        return self.obj_unaryfunc('__nonzero__')

    def __pos__(self):
        return self.unaryfunc('__pos__')

    def __pow__(self, other, mod=None):
        return self.ternaryfunc(other, mod, '__pow__')

    def __radd__(self, other):
        return self.binaryfunc(other, '__radd__')

    def __rdiv__(self, other):
        return self.binaryfunc(other, '__rdiv__')

    def __rdivmod__(self, other):
        context.clear_status()
        q = cdec()
        r = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        q.mpd, r.mpd = self.mpd.__rdivmod__(other_mpd)
        q.dec, r.dec = self.dec.__rdivmod__(other_dec, context.d)
        q.verify('__rdivmod__', (self, other))
        r.verify('__rdivmod__', (self, other))
        return (q, r)

    # __reduce__

    def __repr__(self):
        self.obj_unaryfunc('__repr__')
        return "cdec('" + str(self.mpd) + "')"

    def __rfloordiv__(self, other):
        return self.binaryfunc(other, '__rfloordiv__')

    def __rmod__(self, other):
        return self.binaryfunc(other, '__rmod__')

    def __rmul__(self, other):
        return self.binaryfunc(other, '__rmul__')

    def __rsub__(self, other):
        return self.binaryfunc(other, '__rsub__')

    def __rtruediv__(self, other):
        return self.binaryfunc(other, '__rtruediv__')

    def __rpow__(self, other):
        return other.__pow__(self)

    def __str__(self):
        self.obj_unaryfunc('__str__')
        return str(self.mpd)

    def __sub__(self, other):
        return self.binaryfunc(other, '__sub__')

    def __truediv__(self, other):
        return self.binaryfunc(other, '__truediv__')

    def __trunc__(self):
        # ValueError or OverflowError
        if self.mpd.is_special():
            return (None, None)
        return self.obj_unaryfunc('__trunc__')

    def _apply(self):
        return self.unaryfunc('_apply')

    def abs(self):
        return self.unaryfunc_ctx('abs')

    def add(self, other):
        return self.binaryfunc_ctx(other, 'add')

    def adjusted(self):
        return self.obj_unaryfunc('adjusted')

    def canonical(self):
        return self.unaryfunc('canonical')

    def compare(self, other):
        return self.binaryfunc(other, 'compare')

    def compare_signal(self, other):
        return self.binaryfunc(other, 'compare_signal')

    def compare_total(self, other):
        return self.binaryfunc(other, 'compare_total')

    def compare_total_mag(self, other):
        return self.binaryfunc(other, 'compare_total_mag')

    def copy_abs(self):
        return self.unaryfunc('copy_abs')

    def copy_negate(self):
        return self.unaryfunc('copy_negate')

    def copy_sign(self, other):
        return self.binaryfunc(other, 'copy_sign')

    def divide(self, other):
        return self.binaryfunc_ctx(other, 'divide')

    def divide_int(self, other):
        return self.binaryfunc_ctx(other, 'divide_int')

    def divmod(self, other):
        context.clear_status()
        q = cdec()
        r = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        q.mpd, r.mpd = self.mpd.divmod(other_mpd)
        q.dec, r.dec = context.d.divmod(self.dec, other_dec)
        q.verify('divmod', (self, other))
        r.verify('divmod', (self, other))
        return (q, r)

    def exp(self):
        return self.unaryfunc('exp')

    def fma(self, other, third):
        return self.ternaryfunc(other, third, 'fma')

    # imag
    # invroot

    def is_canonical(self):
        return self.obj_unaryfunc('is_canonical')

    def is_finite(self):
        return self.obj_unaryfunc('is_finite')

    def is_infinite(self):
        return self.obj_unaryfunc('is_infinite')

    def is_nan(self):
        return self.obj_unaryfunc('is_nan')

    def is_normal(self):
        return self.obj_unaryfunc('is_normal')

    def is_qnan(self):
        return self.obj_unaryfunc('is_qnan')

    def is_signed(self):
        return self.obj_unaryfunc('is_signed')

    def is_snan(self):
        return self.obj_unaryfunc('is_snan')

    def is_subnormal(self):
        return self.obj_unaryfunc('is_subnormal')

    def is_zero(self):
        return self.obj_unaryfunc('is_zero')

    def ln(self):
        return self.unaryfunc('ln')

    def log10(self):
        global PY25_DLOG10_HAVE_WARNED
        try:
            return self.unaryfunc('log10')
        except NameError:
            if not PY25_DLOG10_HAVE_WARNED:
                sys.stderr.write(
                  "\n\n*** warning: detected known bug in decimal.py: "
                  "replace div_nearest with _div_nearest in _dlog10().\n\n\n")
                PY25_DLOG10_HAVE_WARNED = 1
            return None

    def logb(self):
        return self.unaryfunc('logb')

    def logical_and(self, other):
        return self.binaryfunc(other, 'logical_and')

    def logical_invert(self):
        return self.unaryfunc('logical_invert')

    def logical_or(self, other):
        return self.binaryfunc(other, 'logical_or')

    def logical_xor(self, other):
        return self.binaryfunc(other, 'logical_xor')

    def max(self, other):
        return self.binaryfunc(other, 'max')

    def max_mag(self, other):
        return self.binaryfunc(other, 'max_mag')

    def min(self, other):
        return self.binaryfunc(other, 'min_mag')

    def min_mag(self, other):
        return self.binaryfunc(other, 'min_mag')

    def minus(self):
        return self.unaryfunc_ctx('minus')

    def multiply(self, other):
        return self.binaryfunc_ctx(other, 'multiply')

    def next_minus(self):
        return self.unaryfunc('next_minus')

    def next_plus(self):
        return self.unaryfunc('next_plus')

    def next_toward(self, other):
        return self.binaryfunc(other, 'next_toward')

    def normalize(self):
        return self.unaryfunc('normalize')

    def number_class(self):
        return self.obj_unaryfunc('number_class')

    def plus(self):
        return self.unaryfunc_ctx('plus')

    def power(self, other, third=None):
        "ternary function returning a cdec, uses the context methods of decimal.py"
        context.clear_status()
        c = cdec()
        other_mpd = other_dec = other
        if isinstance(other, cdec):
            other_mpd = other.mpd
            other_dec = other.dec
        third_mpd = third_dec = third
        if isinstance(third, cdec):
            third_mpd = third.mpd
            third_dec = third.dec
        c.mpd = pow(self.mpd, other_mpd, third_mpd)
        c.dec = pow(self.dec, other_dec, third_dec)
        c.verify('power', (self, other, third))
        return c

    # powmod: same as __pow__ or power with three arguments

    def quantize(self, other):
        return self.binaryfunc(other, 'quantize')

    def radix(self):
        return self.unaryfunc('radix')

    # real
    # reduce: same as normalize

    def remainder(self, other):
        return self.binaryfunc_ctx(other, 'remainder')

    def remainder_near(self, other):
        return self.binaryfunc(other, 'remainder_near')

    def rotate(self, other):
        return self.binaryfunc(other, 'rotate')

    def same_quantum(self, other):
        return self.obj_binaryfunc(other, 'same_quantum')

    def scaleb(self, other):
        return self.binaryfunc(other, 'scaleb')

    def shift(self, other):
        return self.binaryfunc(other, 'shift')

    # sign

    def sqrt(self):
        return self.unaryfunc('sqrt')

    def subtract(self, other):
        return self.binaryfunc_ctx(other, 'subtract')

    def to_eng_string(self):
        return self.obj_unaryfunc('to_eng_string')

    def to_integral(self):
        return self.unaryfunc('to_integral')

    def to_integral_exact(self):
        return self.unaryfunc('to_integral_exact')

    def to_integral_value(self):
        return self.unaryfunc('to_integral_value')

    def to_sci_string(self):
        context.clear_status()
        r_mpd = self.mpd.to_sci_string()
        r_dec = context.d.to_sci_string(self.dec)
        verify((r_mpd, r_dec), 'to_sci_string', (self,))
        return r_mpd


def log(fmt, args=None):
    if args:
        sys.stdout.write(''.join((fmt, '\n')) % args)
    else:
        sys.stdout.write(''.join((str(fmt), '\n')))
    sys.stdout.flush()

def test_method(method, testspecs, testfunc):
    log("testing %s ...", method)
    for spec in testspecs:
        if 'samples' in spec:
            spec['prec'] = sorted(random.sample(range(1, 101), spec['samples']))
        for prec in spec['prec']:
            context.prec = prec
            for expts in spec['expts']:
                emin, emax = expts
                if emin == 'rand':
                    context.Emin = random.randrange(-1000, 0)
                    context.Emax = random.randrange(prec, 1000)
                else:
                    context.Emin, context.Emax = emin, emax
                if prec > context.Emax: continue
                log("    prec: %d  emin: %d  emax: %d",
                    (context.prec, context.Emin, context.Emax))
                restr_range = 9999 if context.Emax > 9999 else context.Emax+99
                for rounding in sorted(decround):
                    context.rounding = rounding
                    context.capitals = random.randrange(2)
                    if spec['clamp'] == 2:
                        context.clamp = random.randrange(2)
                    else:
                        context.clamp = spec['clamp']
                    exprange = context.f.Emax
                    testfunc(method, prec, exprange, restr_range, spec['iter'])

def test_unary(method, prec, exprange, restr_range, iter):
    if method in ['__int__', '__long__', '__trunc__', 'to_integral',
                  'to_integral_value', 'to_integral_value']:
        exprange = restr_range
    if py_minor == 5 and method == '__hash__':
        exprange = restr_range
    for a in un_close_to_pow10(prec, exprange, iter):
        try:
            x = cdec(a)
            getattr(x, method)()
        except CdecException, err:
            log(err)
    for a in un_close_numbers(prec, exprange, -exprange, iter):
        try:
            x = cdec(a)
            getattr(x, method)()
        except CdecException, err:
            log(err)
    for a in un_incr_digits_tuple(prec, exprange, iter):
        try:
            x = cdec(a)
            getattr(x, method)()
        except CdecException, err:
            log(err)
    if py_minor >= 7:
        for a in un_randfloat():
            try:
                x = cdec(a)
                getattr(x, method)()
            except CdecException, err:
                log(err)
    for i in range(1000):
        try:
            s = randdec(prec, exprange)
            x = cdec(s)
            getattr(x, method)()
        except CdecException, err:
            log(err)
        except OverflowError:
            pass
        try:
            s = randtuple(prec, exprange)
            x = cdec(s)
            getattr(x, method)()
        except CdecException, err:
            log(err)
        except OverflowError:
            pass

def test_un_logical(method, prec, exprange, restr_range, iter):
    for a in logical_un_incr_digits(prec, iter):
        try:
            x = cdec(a)
            getattr(x, method)()
        except CdecException, err:
            log(err)
    for i in range(1000):
        try:
            s = randdec(prec, restr_range)
            x = cdec(s)
            getattr(x, method)()
        except CdecException, err:
            log(err)
        except OverflowError:
            pass

def test_binary(method, prec, exprange, restr_range, iter):
    if method in ['__pow__', '__rpow__', 'power']:
        exprange = restr_range
    for a, b in bin_close_to_pow10(prec, exprange, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)
    for a, b in bin_close_numbers(prec, exprange, -exprange, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)
    for a, b in bin_incr_digits(prec, exprange, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)
    if py_minor >= 7:
        for a, b in bin_randfloat():
            try:
                x = cdec(a)
                y = cdec(b)
                getattr(x, method)(y)
            except CdecException, err:
                log(err)
    for i in range(1000):
        s1 = randdec(prec, exprange)
        s2 = randdec(prec, exprange)
        try:
            x = cdec(s1)
            y = cdec(s2)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)

def test_bin_logical(method, prec, exprange, restr_range, iter):
    for a, b in logical_bin_incr_digits(prec, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)
    for i in range(1000):
        s1 = randdec(prec, restr_range)
        s2 = randdec(prec, restr_range)
        try:
            x = cdec(s1)
            y = cdec(s2)
            getattr(x, method)(y)
        except CdecException, err:
            log(err)

def test_ternary(method, prec, exprange, restr_range, iter):
    if method in ['__pow__', 'power']:
        exprange = restr_range
    for a, b, c in tern_close_numbers(prec, exprange, -exprange, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            z = cdec(c)
            getattr(x, method)(y, z)
        except CdecException, err:
            log(err)
    for a, b, c in tern_incr_digits(prec, exprange, iter):
        try:
            x = cdec(a)
            y = cdec(b)
            z = cdec(c)
            getattr(x, method)(y, z)
        except CdecException, err:
            log(err)
    if py_minor >= 7:
        for a, b, c in tern_randfloat():
            try:
                x = cdec(a)
                y = cdec(b)
                z = cdec(c)
                getattr(x, method)(y, z)
            except CdecException, err:
                log(err)
    for i in range(1000):
        s1 = randdec(prec, 2*exprange)
        s2 = randdec(prec, 2*exprange)
        s3 = randdec(prec, 2*exprange)
        try:
            x = cdec(s1)
            y = cdec(s2)
            z = cdec(s3)
            getattr(x, method)(y, z)
        except CdecException, err:
            log(err)

def test_format(method, prec, exprange, restr_range, iter):
    for a in un_incr_digits_tuple(prec, restr_range, iter):
        context.clear_status()
        try:
            fmt = rand_format(chr(random.randrange(32, 128)))
            x = format(context.f.create_decimal(a), fmt)
            y = format(context.d.create_decimal(a), fmt)
        except Exception, err:
            print err, fmt
            continue
        if x != y:
            print context.f
            print context.d
            print "\n%s  %s" % (a, fmt)
            print "%s  %s\n" % (x, y)
    for i in range(1000):
        context.clear_status()
        try:
            a = randdec(99, 9999)
            fmt = rand_format(chr(random.randrange(32, 128)))
            x = format(context.f.create_decimal(a), fmt)
            y = format(context.d.create_decimal(a), fmt)
        except Exception, err:
            print err, fmt
            continue
        if x != y:
            print context.f
            print context.d
            print "\n%s  %s" % (a, fmt)
            print "%s  %s\n" % (x, y)

def test_locale(method, prec, exprange, restr_range, iter):
    for a in un_incr_digits_tuple(prec, restr_range, iter):
        context.clear_status()
        try:
            fmt = rand_locale()
            x = format(context.f.create_decimal(a), fmt)
            y = format(context.d.create_decimal(a), fmt)
        except Exception, err:
            print err, fmt
            continue
        if x != y:
            print context.f
            print context.d
            print locale.getlocale(locale.LC_NUMERIC)
            print "%s  %s" % (a, fmt)
            print array.array('b', x)
            print array.array('b', y)
    for i in range(1000):
        context.clear_status()
        try:
            a = randdec(99, 9999)
            fmt = rand_locale()
            x = format(context.f.create_decimal(a), fmt)
            y = format(context.d.create_decimal(a), fmt)
        except Exception, err:
            print err, fmt
            continue
        if x != y:
            print context.f
            print context.d
            print locale.getlocale(locale.LC_NUMERIC)
            print "%s  %s" % (a, fmt)
            print array.array('b', x)
            print array.array('b', y)

def test_from_float(method, prec, exprange, restr_range, iter):
    exprange = 384
    for i in range(1000):
        context.clear_status()
        intpart = str(random.randrange(100000000000000000000000000000000000000))
        fracpart = str(random.randrange(100000000000000000000000000000000000000))
        exp = str(random.randrange(-384, 384))
        fstring = intpart + '.' + fracpart + 'e' + exp
        f = float(fstring)
        try:
            c = cdec(f)
        except CdecException, err:
            log(err)

def assert_eq_status(c, d):
    """assert equality of cdecimal and decimal status"""
    for signal in c.flags:
        if signal == cdecimal.FloatOperation:
            continue
        if c.flags[signal] == (not d.flags[deccond[signal]]):
            return False
    return True

def test_quantize_api(method, prec, exprange, restr_range, iter):
    for a in un_incr_digits(prec, restr_range, 1):
        emax = random.randrange(exprange)
        emin = random.randrange(-exprange, 0)
        clamp = random.randrange(2)
        exp = randdec(2*prec, exprange)
        for rounding in sorted(decround):
            try:
                c = cdecimal.Context(prec=prec, Emax=emax, Emin=emin, clamp=clamp, traps=[])
                d = decimal.Context(prec=prec, Emax=emax, Emin=emin, _clamp=clamp, traps=[])

                x = cdecimal.Decimal(a)
                y = cdecimal.Decimal(exp)
                cresult = x.quantize(y, rounding, c)

                u = decimal.Decimal(a)
                v = decimal.Decimal(exp)
                dresult = u.quantize(v, decround[rounding], d)
            except Exception, err:
                print(err)
                continue
            if str(cresult) != str(dresult) or \
               not assert_eq_status(c, d):
                print("%s\n%s\n" % (c, d))
                print("x: %s\ny: %s\nu: %s\nv: %s\n" % (x, y, u, v))
                print("a: %s  exp: %s\n" % (a, exp))
                print("cresult: %s\ndresult: %s\n" % (cresult, dresult))
    for i in range(1000):
        a = randdec(prec, 9999)
        prec = random.randrange(1, 50)
        emax = random.randrange(exprange)
        emin = random.randrange(-exprange, 0)
        clamp = random.randrange(2)
        exp = randdec(2*prec, exprange)
        for rounding in sorted(decround):
            try:
                c = cdecimal.Context(prec=prec, Emax=emax, Emin=emin, clamp=clamp, traps=[])
                d = decimal.Context(prec=prec, Emax=emax, Emin=emin, _clamp=clamp, traps=[])

                x = cdecimal.Decimal(a)
                y = cdecimal.Decimal(exp)
                cresult = x.quantize(context=c, exp=y, rounding=rounding)

                u = decimal.Decimal(a)
                v = decimal.Decimal(exp)
                dresult = u.quantize(context=d, exp=v, rounding=decround[rounding])
            except Exception, err:
                print(err)
                continue
            if str(cresult) != str(dresult) or \
               not assert_eq_status(c, d):
                print("%s\n%s\n" % (c, d))
                print("x: %s\ny: %s\nu: %s\nv: %s\n" % (x, y, u, v))
                print("a: %s  exp: %s\n" % (a, exp))
                print("cresult: %s\ndresult: %s\n" % (cresult, dresult))


if __name__ == '__main__':

    import time

    randseed = int(time.time())
    random.seed(randseed)

    base_expts = [(cdecimal.MIN_EMIN, cdecimal.MAX_EMAX)]
    if cdecimal.MAX_EMAX == 999999999999999999:
        base_expts.append((-999999999, 999999999))

    base = {
        'name': 'base',
        'expts': base_expts,
        'prec': [],
        'clamp': 2,
        'iter': None,
        'samples': None,
    }
    small = {
        'name': 'small',
        'prec': [1, 2, 3, 4, 5],
        'expts': [(-1,1), (-2,2), (-3,3), (-4,4), (-5,5)],
        'clamp': 2,
        'iter': None
    }
    ieee = [
        {'name': 'decimal32', 'prec': [7], 'expts': [(-95, 96)], 'clamp': 1, 'iter': None},
        {'name': 'decimal64', 'prec': [16], 'expts': [(-383, 384)], 'clamp': 1, 'iter': None},
        {'name': 'decimal128', 'prec': [34], 'expts': [(-6143, 6144)], 'clamp': 1, 'iter': None}
    ]

    if '--medium' in sys.argv:
        base['expts'].append(('rand', 'rand'))
        base['samples'] = None
        testspecs = [small] + ieee + [base]
    if '--long' in sys.argv:
        base['expts'].append(('rand', 'rand'))
        base['samples'] = 5
        testspecs = [small] + ieee + [base]
    elif '--all' in sys.argv:
        base['expts'].append(('rand', 'rand'))
        base['samples'] = 100
        testspecs = [small] + ieee + [base]
    else: # --short
        rand_ieee = random.choice(ieee)
        base['iter'] = small['iter'] = rand_ieee['iter'] = 1
        base['samples'] = 1
        base['expts'] = [random.choice(base_expts)]
        prec = random.randrange(1, 6)
        small['prec'] = [prec]
        small['expts'] = [(-prec, prec)]
        testspecs = [small, rand_ieee, base]


    all_decimal_methods = set(dir(cdecimal.Decimal) + dir(decimal.Decimal))
    all_cdec_methods = [m for m in dir(cdec) if m in all_decimal_methods]
    untested_methods = [m for m in all_decimal_methods if not (m in all_cdec_methods)]

    unary_methods = []
    binary_methods = []
    ternary_methods = []
    for m in all_cdec_methods:
        try:
            l = len(inspect.getargspec(getattr(cdec, m))[0])
        except TypeError:
            continue
        if   l == 1:
            unary_methods.append(m)
        elif l == 2:
            binary_methods.append(m)
        elif l == 3:
            ternary_methods.append(m)
        else:
            raise ValueError((m, l))

    unary_methods.append('__deepcopy__')
    binary_methods.remove('__deepcopy__')
    binary_methods.remove('__new__')
    binary_methods.append('power')
    untested_methods.remove('from_float')
    if py_minor < 6:
        unary_methods.remove('__trunc__')
        for elem in ['__ge__', '__gt__', '__le__', '__lt__']:
            binary_methods.remove(elem)

    untested_methods.sort()
    unary_methods.sort()
    binary_methods.sort()
    ternary_methods.sort()


    log("\nRandom seed: %d\n\n", randseed)
    log("Skipping tests: \n\n%s\n", untested_methods)


    for method in unary_methods:
        test_method(method, testspecs, test_unary)

    for method in binary_methods:
        test_method(method, testspecs, test_binary)

    for method in ternary_methods:
        test_method(method, testspecs, test_ternary)

    test_method('logical_invert', testspecs, test_un_logical)

    for method in ['logical_and', 'logical_or', 'logical_xor']:
        test_method(method, testspecs, test_bin_logical)

    test_method('quantize_api', testspecs, test_quantize_api)


    if HAVE_FORMATHELPER and py_minor >= 7:
        # Some tests will fail with 2.6, since alignment has been changed
        # in decimal.py 2.7.
        test_method('format', testspecs, test_format)
        test_method('locale', testspecs, test_locale)
        test_method('from_float', testspecs, test_from_float)


    sys.exit(EXIT_STATUS)
