# Copyright (c) 2004 Python Software Foundation.
# All rights reserved.

# Written by Eric Price <eprice at tjhsst.edu>
#    and Facundo Batista <facundo at taniquetil.com.ar>
#    and Raymond Hettinger <python at rcn.com>
#    and Aahz (aahz at pobox.com)
#    and Tim Peters

"""
These are the test cases for the Decimal and Cdecimal modules.

There are two groups of tests, Arithmetic and Behaviour. The former test
the Decimal arithmetic using the tests provided by Mike Cowlishaw. The latter
test the pythonic behaviour according to PEP 327.

Cowlishaw's tests can be downloaded from:

   www2.hursley.ibm.com/decimal/dectest.zip

This test module can be called from command line with one parameter (Arithmetic
or Behaviour) to test each part, or without parameter to test both parts. If
you're working through IDLE, you can import this test module and call test_main()
with the corresponding argument.
"""

from __future__ import with_statement

import math
import os, sys
import pickle, copy
import unittest
from cdecimal import *
from test.test_support import (run_unittest, run_doctest, is_resource_enabled)
import random
try:
    import threading
except ImportError:
    threading = None

py_minor = sys.version_info[1]
assert py_minor == 5, "These tests are for version 2.5 only."
HAVE_CDECIMAL= True
HAVE_CONFIG_64 = (MAX_EMAX == 999999999999999999)

# Useful Test Constant
Signals = getcontext().flags.keys()

# Tests are built around these assumed context defaults.
# test_main() restores the original context.
def init():
    global ORIGINAL_CONTEXT
    ORIGINAL_CONTEXT = getcontext().copy()
    DefaultTestContext = Context(
        prec = 9,
        rounding = ROUND_HALF_EVEN,
        traps = dict.fromkeys(Signals, 0)
        )
    setcontext(DefaultTestContext)


# The official limits for the 32-bit version are -425000000
# and 425000000. The following values are safe for all tests
# in the test suite.
readcontext = Context()
readcontext.unsafe_setprec(1070000000)
readcontext.unsafe_setemax(1070000000)
readcontext.unsafe_setemin(-1070000000)
readcontext._traps = 0


TESTDATADIR = 'decimaltestdata'
if __name__ == '__main__':
    file = sys.argv[0]
else:
    file = __file__
testdir = os.path.dirname(file) or os.curdir
directory = testdir + os.sep + TESTDATADIR + os.sep

skip_expected = not os.path.isdir(directory)

# list of individual .decTest test ids that correspond to tests that
# we're skipping for one reason or another.
skipped_test_ids = [
    'scbx164',  # skipping apparently implementation-specific scaleb
    'scbx165',  # tests, pending clarification of scaleb rules.
]

# XXX: BEGIN FASTDEC SKIPS
status_cases = {}
if HAVE_CONFIG_64:
    # 64 bit version: With a reduced working precision in mpd_qpow()
    # the status matches.
    status_cases = {
        "pwsx803": ([Inexact, Rounded, Subnormal, Underflow], [Inexact, Rounded]),
        "pwsx805": ([Inexact, Rounded, Subnormal, Underflow], [Inexact, Rounded])
    }

# These are skipped for decNumber, too. They might as well be added to
# the ULP cases.
skip_cases = {
    "powx4302": ("1.000000", "1.000001"),
    "powx4303": ("1.000000", "1.000001"),
    "powx4342": ("1.000000", "0.9999999"),
    "powx4343": ("1.000000", "0.9999999")
}

# Disagreements:
# pwmx325 power 0 1 1234567890 -> NaN Invalid_operation -- got 0
disagree = ['pwmx325', 'pwmx326']
# END FASTDEC SKIPS


# Make sure it actually raises errors when not expected and caught in flags
# Slower, since it runs some things several times.
EXTENDEDERRORTEST = True

#Map the test cases' error names to the actual errors
ErrorNames = {'clamped' : Clamped,
              'conversion_syntax' : InvalidOperation,
              'division_by_zero' : DivisionByZero,
              'division_impossible' : InvalidOperation,
              'division_undefined' : InvalidOperation,
              'inexact' : Inexact,
              'invalid_context' : InvalidOperation,
              'invalid_operation' : InvalidOperation,
              'overflow' : Overflow,
              'rounded' : Rounded,
              'subnormal' : Subnormal,
              'underflow' : Underflow}


def Nonfunction(*args):
    """Doesn't do anything."""
    return None

RoundingDict = {'ceiling' : ROUND_CEILING, #Maps test-case names to roundings.
                'down' : ROUND_DOWN,
                'floor' : ROUND_FLOOR,
                'half_down' : ROUND_HALF_DOWN,
                'half_even' : ROUND_HALF_EVEN,
                'half_up' : ROUND_HALF_UP,
                'up' : ROUND_UP,
                '05up' : ROUND_05UP}

# Name adapter to be able to change the Decimal and Context
# interface without changing the test files from Cowlishaw
nameAdapter = {'and':'logical_and',
               'apply':'_apply',
               'class':'number_class',
               'comparesig':'compare_signal',
               'comparetotal':'compare_total',
               'comparetotmag':'compare_total_mag',
               'copy':'copy_decimal',
               'copyabs':'copy_abs',
               'copynegate':'copy_negate',
               'copysign':'copy_sign',
               'divideint':'divide_int',
               'invert':'logical_invert',
               'iscanonical':'is_canonical',
               'isfinite':'is_finite',
               'isinfinite':'is_infinite',
               'isnan':'is_nan',
               'isnormal':'is_normal',
               'isqnan':'is_qnan',
               'issigned':'is_signed',
               'issnan':'is_snan',
               'issubnormal':'is_subnormal',
               'iszero':'is_zero',
               'maxmag':'max_mag',
               'minmag':'min_mag',
               'nextminus':'next_minus',
               'nextplus':'next_plus',
               'nexttoward':'next_toward',
               'or':'logical_or',
               'reduce':'normalize',
               'remaindernear':'remainder_near',
               'samequantum':'same_quantum',
               'squareroot':'sqrt',
               'toeng':'to_eng_string',
               'tointegral':'to_integral_value',
               'tointegralx':'to_integral_exact',
               'tosci':'to_sci_string',
               'xor':'logical_xor',
              }

# The following functions return True/False rather than a Decimal instance

LOGICAL_FUNCTIONS = (
    'is_canonical',
    'is_finite',
    'is_infinite',
    'is_nan',
    'is_normal',
    'is_qnan',
    'is_signed',
    'is_snan',
    'is_subnormal',
    'is_zero',
    'same_quantum',
    )

# For some operations (currently exp, ln, log10, power), the decNumber
# reference implementation imposes additional restrictions on the
# context and operands.  These restrictions are not part of the
# specification; however, the effect of these restrictions does show
# up in some of the testcases.  We skip testcases that violate these
# restrictions, since Decimal behaves differently from decNumber for
# these testcases so these testcases would otherwise fail.

decNumberRestricted = ('power', 'ln', 'log10', 'exp')
DEC_MAX_MATH = 999999
def outside_decNumber_bounds(v, context):
    if (context.prec > DEC_MAX_MATH or
        context.Emax > DEC_MAX_MATH or
        -context.Emin > DEC_MAX_MATH):
        return True
    if not v.is_special() and v and (
        v.adjusted() > DEC_MAX_MATH or
        v.adjusted() < 1-2*DEC_MAX_MATH):
        return True
    return False

class DecimalTest(unittest.TestCase):
    """Class which tests the Decimal class against the test cases.

    Changed for unittest.
    """
    def setUp(self):
        self.context = Context()
        self.ignore_list = ['#']
        # Basically, a # means return NaN InvalidOperation.
        # Different from a sNaN in trim

        self.ChangeDict = {'precision' : self.change_precision,
                      'rounding' : self.change_rounding_method,
                      'maxexponent' : self.change_max_exponent,
                      'minexponent' : self.change_min_exponent,
                      'clamp' : self.change_clamp}

    def eval_file(self, file):
        global skip_expected
        if skip_expected:
            raise unittest.SkipTest
            return
        with open(file) as f:
            for line in f:
                line = line.replace('\r\n', '').replace('\n', '')
                #print line
                try:
                    t = self.eval_line(line)
                except DecimalException, exception:
                    #Exception raised where there shoudn't have been one.
                    self.fail('Exception "'+exception.__class__.__name__ + '" raised on line '+line)

        return

    def eval_line(self, s):
        if s.find(' -> ') >= 0 and s[:2] != '--' and not s.startswith('  --'):
            s = (s.split('->')[0] + '->' +
                 s.split('->')[1].split('--')[0]).strip()
        else:
            s = s.split('--')[0].strip()

        for ignore in self.ignore_list:
            if s.find(ignore) >= 0:
                #print s.split()[0], 'NotImplemented--', ignore
                return
        if not s:
            return
        elif ':' in s:
            return self.eval_directive(s)
        else:
            return self.eval_equation(s)

    def eval_directive(self, s):
        funct, value = map(lambda x: x.strip().lower(), s.split(':'))
        if funct == 'rounding':
            value = RoundingDict[value]
        else:
            try:
                value = int(value)
            except ValueError:
                pass

        funct = self.ChangeDict.get(funct, Nonfunction)
        funct(value)

    def eval_equation(self, s):
        #global DEFAULT_PRECISION
        #print DEFAULT_PRECISION

        if not TEST_ALL and random.random() < 0.90:
            return

        try:
            Sides = s.split('->')
            L = Sides[0].strip().split()
            id = L[0]
            if DEBUG:
                print "Test ", id,
            funct = L[1].lower()
            valstemp = L[2:]
            L = Sides[1].strip().split()
            ans = L[0]
            exceptions = L[1:]
        except (TypeError, AttributeError, IndexError):
            raise InvalidOperation
        def FixQuotes(val):
            val = val.replace("''", 'SingleQuote').replace('""', 'DoubleQuote')
            val = val.replace("'", '').replace('"', '')
            val = val.replace('SingleQuote', "'").replace('DoubleQuote', '"')
            return val

        if id in skipped_test_ids:
            return

        fname = nameAdapter.get(funct, funct)
        if fname == 'rescale':
            return
        funct = getattr(self.context, fname)


        vals = []
        conglomerate = ''
        quote = 0
        theirexceptions = [ErrorNames[x.lower()] for x in exceptions]
        # XXX STATUS CASES
        if status_cases.has_key(id):
            t = status_cases[id]
            theirexceptions = t[0]

        for exception in Signals:
            self.context.traps[exception] = 1 #Catch these bugs...
        for exception in theirexceptions:
            self.context.traps[exception] = 0
        for i, val in enumerate(valstemp):
            if val.count("'") % 2 == 1:
                quote = 1 - quote
            if quote:
                conglomerate = conglomerate + ' ' + val
                continue
            else:
                val = conglomerate + val
                conglomerate = ''
            v = FixQuotes(val)
            if fname in ('to_sci_string', 'to_eng_string'):
                if EXTENDEDERRORTEST:
                    for error in theirexceptions:
                        self.context.traps[error] = 1
                        try:
                            funct(self.context.create_decimal(v))
                        except error:
                            pass
                        except Signals, e:
                            self.fail("Raised %s in %s when %s disabled" % \
                                      (e, s, error))
                        else:
                            self.fail("Did not raise %s in %s" % (error, s))
                        self.context.traps[error] = 0
                v = self.context.create_decimal(v)
            else:
                # 32-bit version has limits +-425000000
                savetraps = self.context._traps
                self.context._traps = 0
                vv = v
                v = Decimal(vv, self.context)
                if self.context._flags & 0x100: # MPD_Invalid_operation
                    v = readcontext.create_decimal(vv)
                    self.context._flags = 0
                self.context._traps = savetraps
            vals.append(v)

        ans = FixQuotes(ans)

        # XXX: Shortcuts, disagreements between cdecimal and decimal
        if id in disagree:
            return
        if fname == 'power' and len(vals) == 3:
            # name is different
            fname = 'powmod'
            funct = getattr(self.context, fname)

        # skip tests that are related to bounds imposed in the decNumber
        # reference implementation
        if fname in decNumberRestricted:
            if fname == 'power':
                if not (vals[1].is_integer() and
                        -1999999997 <= vals[1] <= 999999999):
                    if outside_decNumber_bounds(vals[0], self.context) or \
                            outside_decNumber_bounds(vals[1], self.context):
                        #print "Skipping test %s" % s
                        return
            else:
                if outside_decNumber_bounds(vals[0], self.context):
                    #print "Skipping test %s" % s
                    return


        if EXTENDEDERRORTEST and fname not in ('to_sci_string', 'to_eng_string'):
            for error in theirexceptions:
                self.context.traps[error] = 1
                try:
                    funct(*vals)
                except error:
                    pass
                except Signals, e:
                    self.fail("Raised %s in %s when %s disabled" % \
                              (e, s, error))
                else:
                    self.fail("Did not raise %s in %s" % (error, s))
                self.context.traps[error] = 0
        if DEBUG:
            print "--", self.context
        try:
            result = str(funct(*vals))
            if fname in LOGICAL_FUNCTIONS:
                result = str(int(eval(result))) # 'True', 'False' -> '1', '0'
        except Signals, error:
            self.fail("Raised %s in %s" % (error, s))
        except: #Catch any error long enough to state the test case.
            print "ERROR:", s
            raise

        myexceptions = self.getexceptions()
        self.context.clear_flags()

        myexceptions.sort()
        theirexceptions.sort()

        # XXX SKIPS
        if skip_cases.has_key(id):
            t = skip_cases[id]
            self.assertTrue(result == t[0] and ans == t[1])
        else:
            self.assertEqual(result, ans,
                             'Incorrect answer for ' + s + ' -- got ' + result)

        self.assertEqual(myexceptions, theirexceptions,
              'Incorrect flags set in ' + s + ' -- got ' + str(myexceptions))
        return

    def getexceptions(self):
        return [e for e in Signals if self.context.flags[e]]

    def change_precision(self, prec):
        if HAVE_CONFIG_64:
            self.context.prec = prec
        else:
            self.context.unsafe_setprec(prec)
    def change_rounding_method(self, rounding):
        self.context.rounding = rounding
    def change_min_exponent(self, exp):
        if HAVE_CONFIG_64:
            self.context.Emin = exp
        else:
            self.context.unsafe_setemin(exp)
    def change_max_exponent(self, exp):
        if HAVE_CONFIG_64:
            self.context.Emax = exp
        else:
            self.context.unsafe_setemax(exp)
    def change_clamp(self, clamp):
        self.context._clamp = clamp



# The following classes test the behaviour of Decimal according to PEP 327

class DecimalExplicitConstructionTest(unittest.TestCase):
    '''Unit tests for Explicit Construction cases of Decimal.'''

    def test_explicit_empty(self):
        self.assertEqual(Decimal(), Decimal("0"))

    def test_explicit_from_None(self):
        self.assertRaises(TypeError, Decimal, None)

    def test_explicit_from_int(self):

        #positive
        d = Decimal(45)
        self.assertEqual(str(d), '45')

        #very large positive
        d = Decimal(500000123)
        self.assertEqual(str(d), '500000123')

        #negative
        d = Decimal(-45)
        self.assertEqual(str(d), '-45')

        #zero
        d = Decimal(0)
        self.assertEqual(str(d), '0')

    def test_explicit_from_string(self):

        #empty
        self.assertEqual(str(Decimal('')), 'NaN')

        #int
        self.assertEqual(str(Decimal('45')), '45')

        #float
        self.assertEqual(str(Decimal('45.34')), '45.34')

        #engineer notation
        self.assertEqual(str(Decimal('45e2')), '4.5E+3')

        #just not a number
        self.assertEqual(str(Decimal('ugly')), 'NaN')

        #leading and trailing whitespace permitted
        self.assertEqual(str(Decimal('1.3E4 \n')), '1.3E+4')
        self.assertEqual(str(Decimal('  -7.89')), '-7.89')

        #unicode strings should be permitted
        self.assertEqual(str(Decimal(u'0E-017')), '0E-17')
        self.assertEqual(str(Decimal(u'45')), '45')
        self.assertEqual(str(Decimal(u'-Inf')), '-Infinity')
        self.assertEqual(str(Decimal(u'NaN123')), 'NaN123')

    def test_explicit_from_tuples(self):

        #zero
        d = Decimal( (0, (0,), 0) )
        self.assertEqual(str(d), '0')

        #int
        d = Decimal( (1, (4, 5), 0) )
        self.assertEqual(str(d), '-45')

        #float
        d = Decimal( (0, (4, 5, 3, 4), -2) )
        self.assertEqual(str(d), '45.34')

        #weird
        d = Decimal( (1, (4, 3, 4, 9, 1, 3, 5, 3, 4), -25) )
        self.assertEqual(str(d), '-4.34913534E-17')

        #wrong number of items
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, 9, 1)) )

        #bad sign
        self.assertRaises(ValueError, Decimal, (8, (4, 3, 4, 9, 1), 2) )
        self.assertRaises(ValueError, Decimal, (0., (4, 3, 4, 9, 1), 2) )
        self.assertRaises(ValueError, Decimal, (Decimal(1), (4, 3, 4, 9, 1), 2))

        #bad exp
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, 9, 1), 'wrong!') )
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, 9, 1), 0.) )
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, 9, 1), '1') )

        #bad coefficients
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, None, 1), 2) )
        self.assertRaises(ValueError, Decimal, (1, (4, -3, 4, 9, 1), 2) )
        self.assertRaises(ValueError, Decimal, (1, (4, 10, 4, 9, 1), 2) )
        self.assertRaises(ValueError, Decimal, (1, (4, 3, 4, 'a', 1), 2) )

    def test_explicit_from_Decimal(self):

        #positive
        d = Decimal(45)
        e = Decimal(d)
        self.assertEqual(str(e), '45')
        # XXX cdecimal has behaviour of int()
        # self.assertNotEqual(id(d), id(e))
        self.assertEqual(id(d), id(e))

        #very large positive
        d = Decimal(500000123)
        e = Decimal(d)
        self.assertEqual(str(e), '500000123')
        self.assertEqual(id(d), id(e))

        #negative
        d = Decimal(-45)
        e = Decimal(d)
        self.assertEqual(str(e), '-45')
        self.assertEqual(id(d), id(e))

        #zero
        d = Decimal(0)
        e = Decimal(d)
        self.assertEqual(str(e), '0')
        self.assertEqual(id(d), id(e))

    def test_explicit_from_float(self):
        if not float.__getformat__("double").startswith("IEEE"):
            return
        if HAVE_CDECIMAL:
            if py_minor <= 6:
                with localcontext() as c:
                    # TypeError in 2.6
                    c.clear_flags()
                    self.assertRaises(TypeError, Decimal, 7.5)
                    self.assertFalse(c.flags[FloatOperation])

                    c.traps[FloatOperation] = True
                    self.assertRaises(TypeError, Decimal, 7.5)
                    self.assertFalse(c.flags[FloatOperation])
                    return
            else:
                with localcontext() as c:
                    c.clear_flags()
                    self.assertEqual(Decimal(7.5), 7.5)
                    self.assertTrue(c.flags[FloatOperation])

                    c.traps[FloatOperation] = True
                    self.assertRaises(FloatOperation, Decimal, 7.5)
                    self.assertTrue(c.flags[FloatOperation])

        r = Decimal(0.1)
        self.assertEqual(type(r), Decimal)
        self.assertEqual(str(r),
                '0.1000000000000000055511151231257827021181583404541015625')
        self.assertTrue(Decimal(float('nan')).is_qnan())
        self.assertTrue(Decimal(float('inf')).is_infinite())
        self.assertTrue(Decimal(float('-inf')).is_infinite())
        self.assertEqual(str(Decimal(float('nan'))),
                         str(Decimal('NaN')))
        self.assertEqual(str(Decimal(float('inf'))),
                         str(Decimal('Infinity')))
        self.assertEqual(str(Decimal(float('-inf'))),
                         str(Decimal('-Infinity')))
        self.assertEqual(str(Decimal(float('-0.0'))),
                         str(Decimal('-0')))
        for i in range(200):
            x = random.expovariate(0.01) * (random.random() * 2.0 - 1.0)
            self.assertEqual(x, float(Decimal(x))) # roundtrip

    def test_explicit_context_create_decimal(self):

        nc = copy.copy(getcontext())
        nc.prec = 3

        # empty
        d = Decimal()
        self.assertEqual(str(d), '0')
        d = nc.create_decimal()
        self.assertEqual(str(d), '0')

        # from None
        self.assertRaises(TypeError, nc.create_decimal, None)

        # from int
        d = nc.create_decimal(456)
        self.assertTrue(isinstance(d, Decimal))
        self.assertEqual(nc.create_decimal(45678),
                         nc.create_decimal('457E+2'))

        # from string
        d = Decimal('456789')
        self.assertEqual(str(d), '456789')
        d = nc.create_decimal('456789')
        self.assertEqual(str(d), '4.57E+5')
        # leading and trailing whitespace should result in a NaN;
        # spaces are already checked in Cowlishaw's test-suite, so
        # here we just check that a trailing newline results in a NaN
        self.assertEqual(str(nc.create_decimal('3.14\n')), 'NaN')

        # from tuples
        d = Decimal( (1, (4, 3, 4, 9, 1, 3, 5, 3, 4), -25) )
        self.assertEqual(str(d), '-4.34913534E-17')
        d = nc.create_decimal( (1, (4, 3, 4, 9, 1, 3, 5, 3, 4), -25) )
        self.assertEqual(str(d), '-4.35E-17')

        # from Decimal
        prevdec = Decimal(500000123)
        d = Decimal(prevdec)
        self.assertEqual(str(d), '500000123')
        d = nc.create_decimal(prevdec)
        self.assertEqual(str(d), '5.00E+8')

    def test_unicode_digits(self):
        test_values = {
            u'\uff11': '1',
            u'\u0660.\u0660\u0663\u0667\u0662e-\u0663' : '0.0000372',
            u'-nan\u0c68\u0c6a\u0c66\u0c66' : '-NaN2400',
            }
        for input, expected in test_values.items():
            self.assertEqual(str(Decimal(input)), expected)


class DecimalImplicitConstructionTest(unittest.TestCase):
    '''Unit tests for Implicit Construction cases of Decimal.'''

    def test_implicit_from_None(self):
        self.assertRaises(TypeError, eval, 'Decimal(5) + None', globals())

    def test_implicit_from_int(self):
        #normal
        self.assertEqual(str(Decimal(5) + 45), '50')
        #exceeding precision
        self.assertEqual(Decimal(5) + 123456789000, Decimal(123456789000))

    def test_implicit_from_string(self):
        self.assertRaises(TypeError, eval, 'Decimal(5) + "3"', globals())

    def test_implicit_from_float(self):
        self.assertRaises(TypeError, eval, 'Decimal(5) + 2.2', globals())

    def test_implicit_from_Decimal(self):
        self.assertEqual(Decimal(5) + Decimal(45), Decimal(50))

    def test_rop(self):
        # Allow other classes to be trained to interact with Decimals
        class E:
            def __divmod__(self, other):
                return 'divmod ' + str(other)
            def __rdivmod__(self, other):
                return str(other) + ' rdivmod'
            def __lt__(self, other):
                return 'lt ' + str(other)
            def __gt__(self, other):
                return 'gt ' + str(other)
            def __le__(self, other):
                return 'le ' + str(other)
            def __ge__(self, other):
                return 'ge ' + str(other)
            def __eq__(self, other):
                return 'eq ' + str(other)
            def __ne__(self, other):
                return 'ne ' + str(other)

        self.assertEqual(divmod(E(), Decimal(10)), 'divmod 10')
        self.assertEqual(divmod(Decimal(10), E()), '10 rdivmod')
        self.assertEqual(eval('Decimal(10) < E()'), 'gt 10')
        self.assertEqual(eval('Decimal(10) > E()'), 'lt 10')
        self.assertEqual(eval('Decimal(10) <= E()'), 'ge 10')
        self.assertEqual(eval('Decimal(10) >= E()'), 'le 10')
        self.assertEqual(eval('Decimal(10) == E()'), 'eq 10')
        self.assertEqual(eval('Decimal(10) != E()'), 'ne 10')

        # insert operator methods and then exercise them
        oplist = [
            ('+', '__add__', '__radd__'),
            ('-', '__sub__', '__rsub__'),
            ('*', '__mul__', '__rmul__'),
            ('%', '__mod__', '__rmod__'),
            ('//', '__floordiv__', '__rfloordiv__'),
            ('**', '__pow__', '__rpow__')
        ]
        if 1/2 == 0:
            # testing with classic division, so add __div__
            oplist.append(('/', '__div__', '__rdiv__'))
        else:
            # testing with -Qnew, so add __truediv__
            oplist.append(('/', '__truediv__', '__rtruediv__'))

        for sym, lop, rop in oplist:
            setattr(E, lop, lambda self, other: 'str' + lop + str(other))
            setattr(E, rop, lambda self, other: str(other) + rop + 'str')
            self.assertEqual(eval('E()' + sym + 'Decimal(10)'),
                             'str' + lop + '10')
            self.assertEqual(eval('Decimal(10)' + sym + 'E()'),
                             '10' + rop + 'str')

class DecimalArithmeticOperatorsTest(unittest.TestCase):
    '''Unit tests for all arithmetic operators, binary and unary.'''

    def test_addition(self):

        d1 = Decimal('-11.1')
        d2 = Decimal('22.2')

        #two Decimals
        self.assertEqual(d1+d2, Decimal('11.1'))
        self.assertEqual(d2+d1, Decimal('11.1'))

        #with other type, left
        c = d1 + 5
        self.assertEqual(c, Decimal('-6.1'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 5 + d1
        self.assertEqual(c, Decimal('-6.1'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 += d2
        self.assertEqual(d1, Decimal('11.1'))

        #inline with other type
        d1 += 5
        self.assertEqual(d1, Decimal('16.1'))

    def test_subtraction(self):

        d1 = Decimal('-11.1')
        d2 = Decimal('22.2')

        #two Decimals
        self.assertEqual(d1-d2, Decimal('-33.3'))
        self.assertEqual(d2-d1, Decimal('33.3'))

        #with other type, left
        c = d1 - 5
        self.assertEqual(c, Decimal('-16.1'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 5 - d1
        self.assertEqual(c, Decimal('16.1'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 -= d2
        self.assertEqual(d1, Decimal('-33.3'))

        #inline with other type
        d1 -= 5
        self.assertEqual(d1, Decimal('-38.3'))

    def test_multiplication(self):

        d1 = Decimal('-5')
        d2 = Decimal('3')

        #two Decimals
        self.assertEqual(d1*d2, Decimal('-15'))
        self.assertEqual(d2*d1, Decimal('-15'))

        #with other type, left
        c = d1 * 5
        self.assertEqual(c, Decimal('-25'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 5 * d1
        self.assertEqual(c, Decimal('-25'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 *= d2
        self.assertEqual(d1, Decimal('-15'))

        #inline with other type
        d1 *= 5
        self.assertEqual(d1, Decimal('-75'))

    def test_division(self):

        d1 = Decimal('-5')
        d2 = Decimal('2')

        #two Decimals
        self.assertEqual(d1/d2, Decimal('-2.5'))
        self.assertEqual(d2/d1, Decimal('-0.4'))

        #with other type, left
        c = d1 / 4
        self.assertEqual(c, Decimal('-1.25'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 4 / d1
        self.assertEqual(c, Decimal('-0.8'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 /= d2
        self.assertEqual(d1, Decimal('-2.5'))

        #inline with other type
        d1 /= 4
        self.assertEqual(d1, Decimal('-0.625'))

    def test_floor_division(self):

        d1 = Decimal('5')
        d2 = Decimal('2')

        #two Decimals
        self.assertEqual(d1//d2, Decimal('2'))
        self.assertEqual(d2//d1, Decimal('0'))

        #with other type, left
        c = d1 // 4
        self.assertEqual(c, Decimal('1'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 7 // d1
        self.assertEqual(c, Decimal('1'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 //= d2
        self.assertEqual(d1, Decimal('2'))

        #inline with other type
        d1 //= 2
        self.assertEqual(d1, Decimal('1'))

    def test_powering(self):

        d1 = Decimal('5')
        d2 = Decimal('2')

        #two Decimals
        self.assertEqual(d1**d2, Decimal('25'))
        self.assertEqual(d2**d1, Decimal('32'))

        #with other type, left
        c = d1 ** 4
        self.assertEqual(c, Decimal('625'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 7 ** d1
        self.assertEqual(c, Decimal('16807'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 **= d2
        self.assertEqual(d1, Decimal('25'))

        #inline with other type
        d1 **= 4
        self.assertEqual(d1, Decimal('390625'))

    def test_module(self):

        d1 = Decimal('5')
        d2 = Decimal('2')

        #two Decimals
        self.assertEqual(d1%d2, Decimal('1'))
        self.assertEqual(d2%d1, Decimal('2'))

        #with other type, left
        c = d1 % 4
        self.assertEqual(c, Decimal('1'))
        self.assertEqual(type(c), type(d1))

        #with other type, right
        c = 7 % d1
        self.assertEqual(c, Decimal('2'))
        self.assertEqual(type(c), type(d1))

        #inline with decimal
        d1 %= d2
        self.assertEqual(d1, Decimal('1'))

        #inline with other type
        d1 %= 4
        self.assertEqual(d1, Decimal('1'))

    def test_floor_div_module(self):

        d1 = Decimal('5')
        d2 = Decimal('2')

        #two Decimals
        (p, q) = divmod(d1, d2)
        self.assertEqual(p, Decimal('2'))
        self.assertEqual(q, Decimal('1'))
        self.assertEqual(type(p), type(d1))
        self.assertEqual(type(q), type(d1))

        #with other type, left
        (p, q) = divmod(d1, 4)
        self.assertEqual(p, Decimal('1'))
        self.assertEqual(q, Decimal('1'))
        self.assertEqual(type(p), type(d1))
        self.assertEqual(type(q), type(d1))

        #with other type, right
        (p, q) = divmod(7, d1)
        self.assertEqual(p, Decimal('1'))
        self.assertEqual(q, Decimal('2'))
        self.assertEqual(type(p), type(d1))
        self.assertEqual(type(q), type(d1))

    def test_unary_operators(self):
        self.assertEqual(+Decimal(45), Decimal(+45))           #  +
        self.assertEqual(-Decimal(45), Decimal(-45))           #  -
        self.assertEqual(abs(Decimal(45)), abs(Decimal(-45)))  # abs

    def test_nan_comparisons(self):
        n = Decimal('NaN')
        s = Decimal('sNaN')
        i = Decimal('Inf')
        f = Decimal('2')
        for x, y in [(n, n), (n, i), (i, n), (n, f), (f, n),
                     (s, n), (n, s), (s, i), (i, s), (s, f), (f, s), (s, s)]:
            self.assertTrue(x != y)
            self.assertTrue(not (x == y))
            self.assertTrue(not (x < y))
            self.assertTrue(not (x <= y))
            self.assertTrue(not (x > y))
            self.assertTrue(not (x >= y))

    def test_copy_sign(self):
        d = Decimal(1).copy_sign(Decimal(-2))

        self.assertEqual(Decimal(1).copy_sign(-2), d)
        self.assertRaises(TypeError, Decimal(1).copy_sign, '-2')

# The following are two functions used to test threading in the next class

def thfunc1(cls):
    d1 = Decimal(1)
    d3 = Decimal(3)
    test1 = d1/d3

    cls.finish1.set()
    cls.synchro.wait()

    test2 = d1/d3
    with localcontext() as c2:
        cls.assertTrue(c2.flags[Inexact])
        cls.assertRaises(DivisionByZero, c2.divide, d1, 0)
        cls.assertTrue(c2.flags[DivisionByZero])
        with localcontext() as c3:
            cls.assertTrue(c3.flags[Inexact])
            cls.assertTrue(c3.flags[DivisionByZero])
            cls.assertRaises(InvalidOperation, c3.compare, d1, Decimal('sNaN'))
            cls.assertTrue(c3.flags[InvalidOperation])
            del c3
        cls.assertFalse(c2.flags[InvalidOperation])
        del c2

    cls.assertEqual(test1, Decimal('0.333333333333333333333333'))
    cls.assertEqual(test2, Decimal('0.333333333333333333333333'))

    c1 = getcontext()
    cls.assertTrue(c1.flags[Inexact])
    for sig in Overflow, Underflow, DivisionByZero, InvalidOperation:
        cls.assertFalse(c1.flags[sig])
    return

def thfunc2(cls):
    d1 = Decimal(1)
    d3 = Decimal(3)
    test1 = d1/d3

    thiscontext = getcontext()
    thiscontext.prec = 18
    test2 = d1/d3

    with localcontext() as c2:
        cls.assertTrue(c2.flags[Inexact])
        cls.assertRaises(Overflow, c2.multiply, Decimal('1e425000000'), 999)
        cls.assertTrue(c2.flags[Overflow])
        with localcontext(thiscontext) as c3:
            cls.assertTrue(c3.flags[Inexact])
            cls.assertFalse(c3.flags[Overflow])
            c3.traps[Underflow] = True
            cls.assertRaises(Underflow, c3.divide, Decimal('1e-425000000'), 999)
            cls.assertTrue(c3.flags[Underflow])
            del c3
        cls.assertFalse(c2.flags[Underflow])
        cls.assertFalse(c2.traps[Underflow])
        del c2

    cls.synchro.set()
    cls.finish2.set()

    cls.assertEqual(test1, Decimal('0.333333333333333333333333'))
    cls.assertEqual(test2, Decimal('0.333333333333333333'))

    cls.assertFalse(thiscontext.traps[Underflow])
    cls.assertTrue(thiscontext.flags[Inexact])
    for sig in Overflow, Underflow, DivisionByZero, InvalidOperation:
        cls.assertFalse(thiscontext.flags[sig])
    return

class DecimalUseOfContextTest(unittest.TestCase):
    '''Unit tests for Use of Context cases in Decimal.'''

    # Take care executing this test from IDLE, there's an issue in threading
    # that hangs IDLE and I couldn't find it

    def test_threading(self):
        if threading is None:
            return
        if not HAVE_THREADS:
            return
        # Test the "threading isolation" of a Context. Also test changing
        # the DefaultContext, which acts as a template for the thread-local
        # contexts.
        save_prec = DefaultContext.prec
        save_emax = DefaultContext.Emax
        save_emin = DefaultContext.Emin
        DefaultContext.prec = 24
        DefaultContext.Emax = 425000000
        DefaultContext.Emin = -425000000

        self.synchro = threading.Event()
        self.finish1 = threading.Event()
        self.finish2 = threading.Event()

        th1 = threading.Thread(target=thfunc1, args=(self,))
        th2 = threading.Thread(target=thfunc2, args=(self,))

        th1.start()
        th2.start()

        self.finish1.wait()
        self.finish2.wait()

        for sig in (Inexact, Overflow, Underflow, DivisionByZero,
                    InvalidOperation):
            self.assertFalse(DefaultContext.flags[sig])

        DefaultContext.prec = save_prec
        DefaultContext.Emax = save_emax
        DefaultContext.Emin = save_emin
        return

class DecimalUsabilityTest(unittest.TestCase):
    '''Unit tests for Usability cases of Decimal.'''

    def test_comparison_operators(self):

        da = Decimal('23.42')
        db = Decimal('23.42')
        dc = Decimal('45')

        #two Decimals
        self.assertTrue(dc > da)
        self.assertTrue(dc >= da)
        self.assertTrue(da < dc)
        self.assertTrue(da <= dc)
        self.assertTrue(da == db)
        self.assertTrue(da != dc)
        self.assertTrue(da <= db)
        self.assertTrue(da >= db)
        self.assertEqual(cmp(dc,da), 1)
        self.assertEqual(cmp(da,dc), -1)
        self.assertEqual(cmp(da,db), 0)

        #a Decimal and an int
        self.assertTrue(dc > 23)
        self.assertTrue(23 < dc)
        self.assertTrue(dc == 45)
        self.assertEqual(cmp(dc,23), 1)
        self.assertEqual(cmp(23,dc), -1)
        self.assertEqual(cmp(dc,45), 0)

        #a Decimal and uncomparable
        self.assertNotEqual(da, 'ugly')
        self.assertNotEqual(da, 32.7)
        self.assertNotEqual(da, object())
        self.assertNotEqual(da, object)

        # sortable
        a = map(Decimal, xrange(100))
        b =  a[:]
        random.shuffle(a)
        a.sort()
        self.assertEqual(a, b)

        # with None
        self.assertFalse(Decimal(1) < None)
        self.assertTrue(Decimal(1) > None)

    def test_decimal_float_comparison(self):
        def assert_attr(a, b, attr, context, signal=None):
            context.clear_flags()
            f = getattr(a, attr)
            if HAVE_CDECIMAL:
                if signal == FloatOperation:
                    self.assertRaises(signal, f, b)
                elif py_minor <= 6:
                    self.assertTrue(f(b) is NotImplemented)
                else:
                    self.assertTrue(f(b) is True)
                self.assertTrue(context.flags[FloatOperation])
            else:
                self.assertTrue(f(b) is True)

        small_d = Decimal('0.25')
        big_d = Decimal('3.0')
        small_f = 0.25
        big_f = 3.0

        zero_d = Decimal('0.0')
        neg_zero_d = Decimal('-0.0')
        zero_f = 0.0
        neg_zero_f = -0.0

        inf_d = Decimal('Infinity')
        neg_inf_d = Decimal('-Infinity')
        inf_f = float('inf')
        neg_inf_f = float('-inf')

        def doit(c, signal=None):
            # Order
            for attr in '__lt__', '__le__':
                assert_attr(small_d, big_f, attr, c, signal)

            for attr in '__gt__', '__ge__':
                assert_attr(big_d, small_f, attr, c, signal)

            # Equality
            assert_attr(small_d, small_f, '__eq__', c, None)

            assert_attr(neg_zero_d, neg_zero_f, '__eq__', c, None)
            assert_attr(neg_zero_d, zero_f, '__eq__', c, None)

            assert_attr(zero_d, neg_zero_f, '__eq__', c, None)
            assert_attr(zero_d, zero_f, '__eq__', c, None)

            assert_attr(neg_inf_d, neg_inf_f, '__eq__', c, None)
            assert_attr(inf_d, inf_f, '__eq__', c, None)

            # Inequality
            assert_attr(small_d, big_f, '__ne__', c, None)

            assert_attr(Decimal('0.1'), 0.1, '__ne__', c, None)

            assert_attr(neg_inf_d, inf_f, '__ne__', c, None)
            assert_attr(inf_d, neg_inf_f, '__ne__', c, None)

            assert_attr(Decimal('NaN'), float('nan'), '__ne__', c, None)

        def test_containers(c, signal):
           c.clear_flags()
           s = set([100.0, Decimal('100.0')])
           expected_len = 2 if py_minor <= 6 else 1
           self.assertEqual(len(s), expected_len)
           self.assertTrue(c.flags[FloatOperation])

           c.clear_flags()
           if signal:
               self.assertRaises(signal, sorted, [1.0, Decimal('10.0')])
           else:
               s = sorted([10.0, Decimal('10.0')])
           self.assertTrue(c.flags[FloatOperation])

           c.clear_flags()
           b = 10.0 in [Decimal('10.0'), 1.0]
           self.assertTrue(c.flags[FloatOperation])

           c.clear_flags()
           b = 10.0 in {Decimal('10.0'):'a', 1.0:'b'}
           self.assertTrue(c.flags[FloatOperation])

        if HAVE_CDECIMAL:
            nc = Context()
            if py_minor <= 6:
                with localcontext(nc) as c:
                    self.assertFalse(c.traps[FloatOperation])
                    doit(c, signal=None)
                    test_containers(c, None)

                    c.traps[FloatOperation] = True
                    doit(c, signal=FloatOperation)
                    test_containers(c, FloatOperation)
            else:
                with localcontext(nc) as c:
                    # In 3.2 the FloatOperation signal is off by default.
                    self.assertFalse(c.traps[FloatOperation])
                    doit(c, signal=None)
                    test_containers(c, None)

                    c.traps[FloatOperation] = True
                    doit(c, signal=FloatOperation)
                    test_containers(c, FloatOperation)
        else:
            # decimal.py does not have the FloatOperation signal.
            nc = Context()
            with localcontext(nc) as c:
                doit(c, signal=False)

    def test_copy_and_deepcopy_methods(self):
        d = Decimal('43.24')
        c = copy.copy(d)
        self.assertEqual(id(c), id(d))
        dc = copy.deepcopy(d)
        self.assertEqual(id(dc), id(d))

    def test_hash_method(self):
        def hashit(d):
            a = hash(d)
            b = d.__hash__()
            self.assertEqual(a, b)
            return a

        #just that it's hashable
        hashit(Decimal(23))
        hashit(Decimal('Infinity'))
        hashit(Decimal('-Infinity'))
        if py_minor >= 7:
            hashit(Decimal('nan123'))
            hashit(Decimal('-NaN'))

        test_values = [Decimal(sign*(2**m + n))
                       for m in [0, 14, 15, 16, 17, 30, 31,
                                 32, 33, 61, 62, 63, 64, 65, 66]
                       for n in range(-10, 10)
                       for sign in [-1, 1]]
        test_values.extend([
                Decimal("-1"), # ==> -2
                Decimal("-0"), # zeros
                Decimal("0.00"),
                Decimal("-0.000"),
                Decimal("0E10"),
                Decimal("-0E12"),
                Decimal("10.0"), # negative exponent
                Decimal("-23.00000"),
                Decimal("1230E100"), # positive exponent
                Decimal("-4.5678E50"),
                # a value for which hash(n) != hash(n % (2**64-1))
                # in Python pre-2.6
                Decimal(2**64 + 2**32 - 1),
                # selection of values which fail with the old (before
                # version 2.6) long.__hash__
                Decimal("1.634E100"),
                Decimal("90.697E100"),
                Decimal("188.83E100"),
                Decimal("1652.9E100"),
                Decimal("56531E100"),
                ])

        # check that hash(d) == hash(int(d)) for integral values
        for value in test_values:
            self.assertEqual(hashit(value), hashit(int(value)))

        #the same hash that to an int
        self.assertEqual(hashit(Decimal(23)), hashit(23))
        self.assertRaises(TypeError, hash, Decimal('sNaN'))
        self.assertTrue(hashit(Decimal('Inf')))
        self.assertTrue(hashit(Decimal('-Inf')))

        if py_minor >= 7:
            # check that the hashes of a Decimal float match when they
            # represent exactly the same values
            test_strings = ['inf', '-Inf', '0.0', '-.0e1',
                            '34.0', '2.5', '112390.625', '-0.515625']
            for s in test_strings:
                f = float(s)
                d = Decimal(s)
                self.assertEqual(hashit(f), hashit(d))

        # check that the value of the hash doesn't depend on the
        # current context (issue #1757)
        c = getcontext()
        old_precision = c.prec
        x = Decimal("123456789.1")

        c.prec = 6
        h1 = hashit(x)
        c.prec = 10
        h2 = hashit(x)
        c.prec = 16
        h3 = hashit(x)

        self.assertEqual(h1, h2)
        self.assertEqual(h1, h3)
        c.prec = old_precision

    def test_min_and_max_methods(self):

        d1 = Decimal('15.32')
        d2 = Decimal('28.5')
        l1 = 15
        l2 = 28

        #between Decimals
        self.assertTrue(min(d1,d2) is d1)
        self.assertTrue(min(d2,d1) is d1)
        self.assertTrue(max(d1,d2) is d2)
        self.assertTrue(max(d2,d1) is d2)

        #between Decimal and long
        self.assertTrue(min(d1,l2) is d1)
        self.assertTrue(min(l2,d1) is d1)
        self.assertTrue(max(l1,d2) is d2)
        self.assertTrue(max(d2,l1) is d2)

    def test_as_nonzero(self):
        #as false
        self.assertFalse(Decimal(0))
        #as true
        self.assertTrue(Decimal('0.372'))

    def test_tostring_methods(self):
        #Test str and repr methods.

        d = Decimal('15.32')
        self.assertEqual(str(d), '15.32')               # str
        self.assertEqual(repr(d), "Decimal('15.32')")   # repr

        # result type of string methods should be str, not unicode
        unicode_inputs = [u'123.4', u'0.5E2', u'Infinity', u'sNaN',
                          u'-0.0E100', u'-NaN001', u'-Inf']

        for u in unicode_inputs:
            d = Decimal(u)
            self.assertEqual(type(str(d)), str)
            self.assertEqual(type(repr(d)), str)
            self.assertEqual(type(d.to_eng_string()), str)

    def test_tonum_methods(self):
        #Test float, int and long methods.

        d1 = Decimal('66')
        d2 = Decimal('15.32')

        #int
        self.assertEqual(int(d1), 66)
        self.assertEqual(int(d2), 15)

        #long
        self.assertEqual(long(d1), 66)
        self.assertEqual(long(d2), 15)

        #float
        self.assertEqual(float(d1), 66)
        self.assertEqual(float(d2), 15.32)

    def test_eval_round_trip(self):

        #with zero
        d = Decimal( (0, (0,), 0) )
        self.assertEqual(d, eval(repr(d)))

        #int
        d = Decimal( (1, (4, 5), 0) )
        self.assertEqual(d, eval(repr(d)))

        #float
        d = Decimal( (0, (4, 5, 3, 4), -2) )
        self.assertEqual(d, eval(repr(d)))

        #weird
        d = Decimal( (1, (4, 3, 4, 9, 1, 3, 5, 3, 4), -25) )
        self.assertEqual(d, eval(repr(d)))

    def test_as_tuple(self):

        #with zero
        d = Decimal(0)
        self.assertEqual(d.as_tuple(), (0, (0,), 0) )

        #int
        d = Decimal(-45)
        self.assertEqual(d.as_tuple(), (1, (4, 5), 0) )

        #complicated string
        d = Decimal("-4.34913534E-17")
        self.assertEqual(d.as_tuple(), (1, (4, 3, 4, 9, 1, 3, 5, 3, 4), -25) )

        # XXX empty tuple, like in the NaN case
        d = Decimal("Infinity")
        self.assertEqual(d.as_tuple(), (0, (0,), 'F') )

        #leading zeros in coefficient should be stripped
        d = Decimal( (0, (0, 0, 4, 0, 5, 3, 4), -2) )
        self.assertEqual(d.as_tuple(), (0, (4, 0, 5, 3, 4), -2) )
        d = Decimal( (1, (0, 0, 0), 37) )
        self.assertEqual(d.as_tuple(), (1, (0,), 37))
        d = Decimal( (1, (), 37) )
        self.assertEqual(d.as_tuple(), (1, (0,), 37))

        #leading zeros in NaN diagnostic info should be stripped
        d = Decimal( (0, (0, 0, 4, 0, 5, 3, 4), 'n') )
        self.assertEqual(d.as_tuple(), (0, (4, 0, 5, 3, 4), 'n') )
        d = Decimal( (1, (0, 0, 0), 'N') )
        self.assertEqual(d.as_tuple(), (1, (), 'N') )
        d = Decimal( (1, (), 'n') )
        self.assertEqual(d.as_tuple(), (1, (), 'n') )

        # XXX coefficient in infinity should raise an error
        # d = Decimal( (0, (4, 5, 3, 4), 'F') )
        # self.assertEqual(d.as_tuple(), (0, (0,), 'F'))
        # d = Decimal( (1, (0, 2, 7, 1), 'F') )
        # self.assertEqual(d.as_tuple(), (1, (0,), 'F'))

    def XXX_test_immutability_operations(self):
        # XXX Checked extensively in the library runtest.
        # Do operations and check that it didn't change change internal objects.

        d1 = Decimal('-25e55')
        b1 = Decimal('-25e55')
        d2 = Decimal('33e+33')
        b2 = Decimal('33e+33')

        def checkSameDec(operation, useOther=False):
            if useOther:
                eval("d1." + operation + "(d2)")
                self.assertEqual(d1._sign, b1._sign)
                self.assertEqual(d1._int, b1._int)
                self.assertEqual(d1._exp, b1._exp)
                self.assertEqual(d2._sign, b2._sign)
                self.assertEqual(d2._int, b2._int)
                self.assertEqual(d2._exp, b2._exp)
            else:
                eval("d1." + operation + "()")
                self.assertEqual(d1._sign, b1._sign)
                self.assertEqual(d1._int, b1._int)
                self.assertEqual(d1._exp, b1._exp)
            return

        Decimal(d1)
        self.assertEqual(d1._sign, b1._sign)
        self.assertEqual(d1._int, b1._int)
        self.assertEqual(d1._exp, b1._exp)

        checkSameDec("__abs__")
        checkSameDec("__add__", True)
        checkSameDec("__div__", True)
        checkSameDec("__divmod__", True)
        checkSameDec("__eq__", True)
        checkSameDec("__ne__", True)
        checkSameDec("__le__", True)
        checkSameDec("__lt__", True)
        checkSameDec("__ge__", True)
        checkSameDec("__gt__", True)
        checkSameDec("__float__")
        checkSameDec("__floordiv__", True)
        checkSameDec("__hash__")
        checkSameDec("__int__")
        checkSameDec("__trunc__")
        checkSameDec("__long__")
        checkSameDec("__mod__", True)
        checkSameDec("__mul__", True)
        checkSameDec("__neg__")
        checkSameDec("__nonzero__")
        checkSameDec("__pos__")
        checkSameDec("__pow__", True)
        checkSameDec("__radd__", True)
        checkSameDec("__rdiv__", True)
        checkSameDec("__rdivmod__", True)
        checkSameDec("__repr__")
        checkSameDec("__rfloordiv__", True)
        checkSameDec("__rmod__", True)
        checkSameDec("__rmul__", True)
        checkSameDec("__rpow__", True)
        checkSameDec("__rsub__", True)
        checkSameDec("__str__")
        checkSameDec("__sub__", True)
        checkSameDec("__truediv__", True)
        checkSameDec("adjusted")
        checkSameDec("as_tuple")
        checkSameDec("compare", True)
        checkSameDec("max", True)
        checkSameDec("min", True)
        checkSameDec("normalize")
        checkSameDec("quantize", True)
        checkSameDec("remainder_near", True)
        checkSameDec("same_quantum", True)
        checkSameDec("sqrt")
        checkSameDec("to_eng_string")
        checkSameDec("to_integral")

    def test_subclassing(self):
        # Different behaviours when subclassing Decimal

        class MyDecimal(Decimal):
            pass

        d1 = MyDecimal(1)
        d2 = MyDecimal(2)
        d = d1 + d2
        self.assertTrue(type(d) is Decimal)

        d = d1.max(d2)
        self.assertTrue(type(d) is Decimal)

    def test_implicit_context(self):
        # Check results when context given implicitly.  (Issue 2478)
        c = getcontext()
        self.assertEqual(str(Decimal(0).sqrt()),
                         str(c.sqrt(Decimal(0))))

    def test_conversions_from_int(self):
        # Check that methods taking a second Decimal argument will
        # always accept an integer in place of a Decimal.
        self.assertEqual(Decimal(4).compare(3),
                         Decimal(4).compare(Decimal(3)))
        self.assertEqual(Decimal(4).compare_signal(3),
                         Decimal(4).compare_signal(Decimal(3)))
        self.assertEqual(Decimal(4).compare_total(3),
                         Decimal(4).compare_total(Decimal(3)))
        self.assertEqual(Decimal(4).compare_total_mag(3),
                         Decimal(4).compare_total_mag(Decimal(3)))
        self.assertEqual(Decimal(10101).logical_and(1001),
                         Decimal(10101).logical_and(Decimal(1001)))
        self.assertEqual(Decimal(10101).logical_or(1001),
                         Decimal(10101).logical_or(Decimal(1001)))
        self.assertEqual(Decimal(10101).logical_xor(1001),
                         Decimal(10101).logical_xor(Decimal(1001)))
        self.assertEqual(Decimal(567).max(123),
                         Decimal(567).max(Decimal(123)))
        self.assertEqual(Decimal(567).max_mag(123),
                         Decimal(567).max_mag(Decimal(123)))
        self.assertEqual(Decimal(567).min(123),
                         Decimal(567).min(Decimal(123)))
        self.assertEqual(Decimal(567).min_mag(123),
                         Decimal(567).min_mag(Decimal(123)))
        self.assertEqual(Decimal(567).next_toward(123),
                         Decimal(567).next_toward(Decimal(123)))
        self.assertEqual(Decimal(1234).quantize(100),
                         Decimal(1234).quantize(Decimal(100)))
        self.assertEqual(Decimal(768).remainder_near(1234),
                         Decimal(768).remainder_near(Decimal(1234)))
        self.assertEqual(Decimal(123).rotate(1),
                         Decimal(123).rotate(Decimal(1)))
        self.assertEqual(Decimal(1234).same_quantum(1000),
                         Decimal(1234).same_quantum(Decimal(1000)))
        self.assertEqual(Decimal('9.123').scaleb(-100),
                         Decimal('9.123').scaleb(Decimal(-100)))
        self.assertEqual(Decimal(456).shift(-1),
                         Decimal(456).shift(Decimal(-1)))

        self.assertEqual(Decimal(-12).fma(Decimal(45), 67),
                         Decimal(-12).fma(Decimal(45), Decimal(67)))
        self.assertEqual(Decimal(-12).fma(45, 67),
                         Decimal(-12).fma(Decimal(45), Decimal(67)))
        self.assertEqual(Decimal(-12).fma(45, Decimal(67)),
                         Decimal(-12).fma(Decimal(45), Decimal(67)))

class DecimalPythonAPItests(unittest.TestCase):

    def test_pickle(self):
        d = Decimal('-3.141590000')
        p = pickle.dumps(d)
        e = pickle.loads(p)
        self.assertEqual(d, e)

    def test_int(self):
        for x in range(-250, 250):
            s = '%0.2f' % (x / 100.0)
            # should work the same as for floats
            self.assertEqual(int(Decimal(s)), int(float(s)))
            # should work the same as to_integral in the ROUND_DOWN mode
            d = Decimal(s)
            r = d.to_integral(ROUND_DOWN)
            self.assertEqual(Decimal(int(d)), r)

        self.assertRaises(ValueError, int, Decimal('-nan'))
        self.assertRaises(ValueError, int, Decimal('snan'))
        self.assertRaises(OverflowError, int, Decimal('inf'))
        self.assertRaises(OverflowError, int, Decimal('-inf'))

        self.assertRaises(ValueError, long, Decimal('-nan'))
        self.assertRaises(ValueError, long, Decimal('snan'))
        self.assertRaises(OverflowError, long, Decimal('inf'))
        self.assertRaises(OverflowError, long, Decimal('-inf'))

    def test_quantize(self):
        c = Context(Emax=99999, Emin=-99999)
        self.assertEqual(
            Decimal('7.335').quantize(Decimal('.01')),
            Decimal('7.34')
        )
        self.assertEqual(
            Decimal('7.335').quantize(Decimal('.01'), rounding=ROUND_DOWN),
            Decimal('7.33')
        )
        self.assertRaises(
            InvalidOperation,
            Decimal("10e99999").quantize, Decimal('1e100000'), context=c
        )
        if HAVE_CDECIMAL:
            self.assertRaises(
                TypeError,
                Decimal("1.23456789").quantize, Decimal('1e-100000'), []
            )
            self.assertRaises(
                TypeError,
                Decimal("1.23456789").quantize, Decimal('1e-100000'), c
            )
            self.assertRaises(
                TypeError,
                Decimal("1.23456789").quantize, Decimal('1e-100000'), 10
            )
            self.assertRaises(
                TypeError,
                Decimal("1.23456789").quantize, Decimal('1e-100000'), ROUND_UP, 1000
            )

class ContextAPItests(unittest.TestCase):

    def test_pickle(self):
        c = Context()
        e = pickle.loads(pickle.dumps(c))
        # XXX some are getters/setters
        #for k in vars(c):
        #    v1 = vars(c)[k]
        #    v2 = vars(e)[k]
        #    self.assertEqual(v1, v2)
        self.assertEqual(c.prec, e.prec)
        self.assertEqual(c.Emin, e.Emin)
        self.assertEqual(c.Emax, e.Emax)
        self.assertEqual(c.rounding, e.rounding)
        self.assertEqual(c.capitals, e.capitals)
        self.assertEqual(c.traps, e.traps)
        self.assertEqual(c.flags, e.flags)
        self.assertEqual(c._clamp, e._clamp)

    def test_equality_with_other_types(self):
        self.assertTrue(Decimal(10) in ['a', 1.0, Decimal(10), (1,2), {}])
        self.assertTrue(Decimal(10) not in ['a', 1.0, (1,2), {}])

    def test_copy(self):
        # All copies should be deep
        c = Context()
        d = c.copy()
        self.assertNotEqual(id(c), id(d))
        self.assertNotEqual(id(c.flags), id(d.flags))
        self.assertNotEqual(id(c.traps), id(d.traps))
        self.assertEqual(c.flags, d.flags)

    def test_abs(self):
        c = Context()
        d = c.abs(Decimal(-1))
        self.assertEqual(c.abs(-1), d)
        self.assertRaises(TypeError, c.abs, '-1')

    def test_add(self):
        c = Context()
        d = c.add(Decimal(1), Decimal(1))
        self.assertEqual(c.add(1, 1), d)
        self.assertEqual(c.add(Decimal(1), 1), d)
        self.assertEqual(c.add(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.add, '1', 1)
        self.assertRaises(TypeError, c.add, 1, '1')

    def test_compare(self):
        c = Context()
        d = c.compare(Decimal(1), Decimal(1))
        self.assertEqual(c.compare(1, 1), d)
        self.assertEqual(c.compare(Decimal(1), 1), d)
        self.assertEqual(c.compare(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.compare, '1', 1)
        self.assertRaises(TypeError, c.compare, 1, '1')

    def test_compare_signal(self):
        c = Context()
        d = c.compare_signal(Decimal(1), Decimal(1))
        self.assertEqual(c.compare_signal(1, 1), d)
        self.assertEqual(c.compare_signal(Decimal(1), 1), d)
        self.assertEqual(c.compare_signal(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.compare_signal, '1', 1)
        self.assertRaises(TypeError, c.compare_signal, 1, '1')

    def test_compare_total(self):
        c = Context()
        d = c.compare_total(Decimal(1), Decimal(1))
        self.assertEqual(c.compare_total(1, 1), d)
        self.assertEqual(c.compare_total(Decimal(1), 1), d)
        self.assertEqual(c.compare_total(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.compare_total, '1', 1)
        self.assertRaises(TypeError, c.compare_total, 1, '1')

    def test_compare_total_mag(self):
        c = Context()
        d = c.compare_total_mag(Decimal(1), Decimal(1))
        self.assertEqual(c.compare_total_mag(1, 1), d)
        self.assertEqual(c.compare_total_mag(Decimal(1), 1), d)
        self.assertEqual(c.compare_total_mag(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.compare_total_mag, '1', 1)
        self.assertRaises(TypeError, c.compare_total_mag, 1, '1')

    def test_copy_abs(self):
        c = Context()
        d = c.copy_abs(Decimal(-1))
        self.assertEqual(c.copy_abs(-1), d)
        self.assertRaises(TypeError, c.copy_abs, '-1')

    def test_copy_decimal(self):
        c = Context()
        d = c.copy_decimal(Decimal(-1))
        self.assertEqual(c.copy_decimal(-1), d)
        self.assertRaises(TypeError, c.copy_decimal, '-1')

    def test_copy_negate(self):
        c = Context()
        d = c.copy_negate(Decimal(-1))
        self.assertEqual(c.copy_negate(-1), d)
        self.assertRaises(TypeError, c.copy_negate, '-1')

    def test_copy_sign(self):
        c = Context()
        d = c.copy_sign(Decimal(1), Decimal(-2))
        self.assertEqual(c.copy_sign(1, -2), d)
        self.assertEqual(c.copy_sign(Decimal(1), -2), d)
        self.assertEqual(c.copy_sign(1, Decimal(-2)), d)
        self.assertRaises(TypeError, c.copy_sign, '1', -2)
        self.assertRaises(TypeError, c.copy_sign, 1, '-2')

    def test_divide(self):
        c = Context()
        d = c.divide(Decimal(1), Decimal(2))
        self.assertEqual(c.divide(1, 2), d)
        self.assertEqual(c.divide(Decimal(1), 2), d)
        self.assertEqual(c.divide(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.divide, '1', 2)
        self.assertRaises(TypeError, c.divide, 1, '2')

    def test_divide_int(self):
        c = Context()
        d = c.divide_int(Decimal(1), Decimal(2))
        self.assertEqual(c.divide_int(1, 2), d)
        self.assertEqual(c.divide_int(Decimal(1), 2), d)
        self.assertEqual(c.divide_int(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.divide_int, '1', 2)
        self.assertRaises(TypeError, c.divide_int, 1, '2')

    def test_divmod(self):
        c = Context()
        d = c.divmod(Decimal(1), Decimal(2))
        self.assertEqual(c.divmod(1, 2), d)
        self.assertEqual(c.divmod(Decimal(1), 2), d)
        self.assertEqual(c.divmod(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.divmod, '1', 2)
        self.assertRaises(TypeError, c.divmod, 1, '2')

    def test_exp(self):
        c = Context()
        d = c.exp(Decimal(10))
        self.assertEqual(c.exp(10), d)
        self.assertRaises(TypeError, c.exp, '10')

    def test_fma(self):
        c = Context()
        d = c.fma(Decimal(2), Decimal(3), Decimal(4))
        self.assertEqual(c.fma(2, 3, 4), d)
        self.assertEqual(c.fma(Decimal(2), 3, 4), d)
        self.assertEqual(c.fma(2, Decimal(3), 4), d)
        self.assertEqual(c.fma(2, 3, Decimal(4)), d)
        self.assertEqual(c.fma(Decimal(2), Decimal(3), 4), d)
        self.assertRaises(TypeError, c.fma, '2', 3, 4)
        self.assertRaises(TypeError, c.fma, 2, '3', 4)
        self.assertRaises(TypeError, c.fma, 2, 3, '4')

    def test_is_finite(self):
        c = Context()
        d = c.is_finite(Decimal(10))
        self.assertEqual(c.is_finite(10), d)
        self.assertRaises(TypeError, c.is_finite, '10')

    def test_is_infinite(self):
        c = Context()
        d = c.is_infinite(Decimal(10))
        self.assertEqual(c.is_infinite(10), d)
        self.assertRaises(TypeError, c.is_infinite, '10')

    def test_is_nan(self):
        c = Context()
        d = c.is_nan(Decimal(10))
        self.assertEqual(c.is_nan(10), d)
        self.assertRaises(TypeError, c.is_nan, '10')

    def test_is_normal(self):
        c = Context()
        d = c.is_normal(Decimal(10))
        self.assertEqual(c.is_normal(10), d)
        self.assertRaises(TypeError, c.is_normal, '10')

    def test_is_qnan(self):
        c = Context()
        d = c.is_qnan(Decimal(10))
        self.assertEqual(c.is_qnan(10), d)
        self.assertRaises(TypeError, c.is_qnan, '10')

    def test_is_signed(self):
        c = Context()
        d = c.is_signed(Decimal(10))
        self.assertEqual(c.is_signed(10), d)
        self.assertRaises(TypeError, c.is_signed, '10')

    def test_is_snan(self):
        c = Context()
        d = c.is_snan(Decimal(10))
        self.assertEqual(c.is_snan(10), d)
        self.assertRaises(TypeError, c.is_snan, '10')

    def test_is_subnormal(self):
        c = Context()
        d = c.is_subnormal(Decimal(10))
        self.assertEqual(c.is_subnormal(10), d)
        self.assertRaises(TypeError, c.is_subnormal, '10')

    def test_is_zero(self):
        c = Context()
        d = c.is_zero(Decimal(10))
        self.assertEqual(c.is_zero(10), d)
        self.assertRaises(TypeError, c.is_zero, '10')

    def test_ln(self):
        c = Context()
        d = c.ln(Decimal(10))
        self.assertEqual(c.ln(10), d)
        self.assertRaises(TypeError, c.ln, '10')

    def test_log10(self):
        c = Context()
        d = c.log10(Decimal(10))
        self.assertEqual(c.log10(10), d)
        self.assertRaises(TypeError, c.log10, '10')

    def test_logb(self):
        c = Context()
        d = c.logb(Decimal(10))
        self.assertEqual(c.logb(10), d)
        self.assertRaises(TypeError, c.logb, '10')

    def test_logical_and(self):
        c = Context()
        d = c.logical_and(Decimal(1), Decimal(1))
        self.assertEqual(c.logical_and(1, 1), d)
        self.assertEqual(c.logical_and(Decimal(1), 1), d)
        self.assertEqual(c.logical_and(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.logical_and, '1', 1)
        self.assertRaises(TypeError, c.logical_and, 1, '1')

    def test_logical_invert(self):
        c = Context()
        d = c.logical_invert(Decimal(1000))
        self.assertEqual(c.logical_invert(1000), d)
        self.assertRaises(TypeError, c.logical_invert, '1000')

    def test_logical_or(self):
        c = Context()
        d = c.logical_or(Decimal(1), Decimal(1))
        self.assertEqual(c.logical_or(1, 1), d)
        self.assertEqual(c.logical_or(Decimal(1), 1), d)
        self.assertEqual(c.logical_or(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.logical_or, '1', 1)
        self.assertRaises(TypeError, c.logical_or, 1, '1')

    def test_logical_xor(self):
        c = Context()
        d = c.logical_xor(Decimal(1), Decimal(1))
        self.assertEqual(c.logical_xor(1, 1), d)
        self.assertEqual(c.logical_xor(Decimal(1), 1), d)
        self.assertEqual(c.logical_xor(1, Decimal(1)), d)
        self.assertRaises(TypeError, c.logical_xor, '1', 1)
        self.assertRaises(TypeError, c.logical_xor, 1, '1')

    def test_max(self):
        c = Context()
        d = c.max(Decimal(1), Decimal(2))
        self.assertEqual(c.max(1, 2), d)
        self.assertEqual(c.max(Decimal(1), 2), d)
        self.assertEqual(c.max(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.max, '1', 2)
        self.assertRaises(TypeError, c.max, 1, '2')

    def test_max_mag(self):
        c = Context()
        d = c.max_mag(Decimal(1), Decimal(2))
        self.assertEqual(c.max_mag(1, 2), d)
        self.assertEqual(c.max_mag(Decimal(1), 2), d)
        self.assertEqual(c.max_mag(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.max_mag, '1', 2)
        self.assertRaises(TypeError, c.max_mag, 1, '2')

    def test_min(self):
        c = Context()
        d = c.min(Decimal(1), Decimal(2))
        self.assertEqual(c.min(1, 2), d)
        self.assertEqual(c.min(Decimal(1), 2), d)
        self.assertEqual(c.min(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.min, '1', 2)
        self.assertRaises(TypeError, c.min, 1, '2')

    def test_min_mag(self):
        c = Context()
        d = c.min_mag(Decimal(1), Decimal(2))
        self.assertEqual(c.min_mag(1, 2), d)
        self.assertEqual(c.min_mag(Decimal(1), 2), d)
        self.assertEqual(c.min_mag(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.min_mag, '1', 2)
        self.assertRaises(TypeError, c.min_mag, 1, '2')

    def test_minus(self):
        c = Context()
        d = c.minus(Decimal(10))
        self.assertEqual(c.minus(10), d)
        self.assertRaises(TypeError, c.minus, '10')

    def test_multiply(self):
        c = Context()
        d = c.multiply(Decimal(1), Decimal(2))
        self.assertEqual(c.multiply(1, 2), d)
        self.assertEqual(c.multiply(Decimal(1), 2), d)
        self.assertEqual(c.multiply(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.multiply, '1', 2)
        self.assertRaises(TypeError, c.multiply, 1, '2')

    def test_next_minus(self):
        c = Context()
        d = c.next_minus(Decimal(10))
        self.assertEqual(c.next_minus(10), d)
        self.assertRaises(TypeError, c.next_minus, '10')

    def test_next_plus(self):
        c = Context()
        d = c.next_plus(Decimal(10))
        self.assertEqual(c.next_plus(10), d)
        self.assertRaises(TypeError, c.next_plus, '10')

    def test_next_toward(self):
        c = Context()
        d = c.next_toward(Decimal(1), Decimal(2))
        self.assertEqual(c.next_toward(1, 2), d)
        self.assertEqual(c.next_toward(Decimal(1), 2), d)
        self.assertEqual(c.next_toward(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.next_toward, '1', 2)
        self.assertRaises(TypeError, c.next_toward, 1, '2')

    def test_normalize(self):
        c = Context()
        d = c.normalize(Decimal(10))
        self.assertEqual(c.normalize(10), d)
        self.assertRaises(TypeError, c.normalize, '10')

    def test_number_class(self):
        c = Context()
        self.assertEqual(c.number_class(123), c.number_class(Decimal(123)))
        self.assertEqual(c.number_class(0), c.number_class(Decimal(0)))
        self.assertEqual(c.number_class(-45), c.number_class(Decimal(-45)))

    def test_powmod(self):
        c = Context()
        d = c.powmod(Decimal(1), Decimal(4), Decimal(2))
        self.assertEqual(c.powmod(1, 4, 2), d)
        self.assertEqual(c.powmod(Decimal(1), 4, 2), d)
        self.assertEqual(c.powmod(1, Decimal(4), 2), d)
        self.assertEqual(c.powmod(1, 4, Decimal(2)), d)
        self.assertEqual(c.powmod(Decimal(1), Decimal(4), 2), d)
        self.assertRaises(TypeError, c.powmod, '1', 4, 2)
        self.assertRaises(TypeError, c.powmod, 1, '4', 2)
        self.assertRaises(TypeError, c.powmod, 1, 4, '2')

    def test_plus(self):
        c = Context()
        d = c.plus(Decimal(10))
        self.assertEqual(c.plus(10), d)
        self.assertRaises(TypeError, c.plus, '10')

    def test_quantize(self):
        c = Context()
        d = c.quantize(Decimal(1), Decimal(2))
        self.assertEqual(c.quantize(1, 2), d)
        self.assertEqual(c.quantize(Decimal(1), 2), d)
        self.assertEqual(c.quantize(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.quantize, '1', 2)
        self.assertRaises(TypeError, c.quantize, 1, '2')

    def test_remainder(self):
        c = Context()
        d = c.remainder(Decimal(1), Decimal(2))
        self.assertEqual(c.remainder(1, 2), d)
        self.assertEqual(c.remainder(Decimal(1), 2), d)
        self.assertEqual(c.remainder(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.remainder, '1', 2)
        self.assertRaises(TypeError, c.remainder, 1, '2')

    def test_remainder_near(self):
        c = Context()
        d = c.remainder_near(Decimal(1), Decimal(2))
        self.assertEqual(c.remainder_near(1, 2), d)
        self.assertEqual(c.remainder_near(Decimal(1), 2), d)
        self.assertEqual(c.remainder_near(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.remainder_near, '1', 2)
        self.assertRaises(TypeError, c.remainder_near, 1, '2')

    def test_rotate(self):
        c = Context()
        d = c.rotate(Decimal(1), Decimal(2))
        self.assertEqual(c.rotate(1, 2), d)
        self.assertEqual(c.rotate(Decimal(1), 2), d)
        self.assertEqual(c.rotate(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.rotate, '1', 2)
        self.assertRaises(TypeError, c.rotate, 1, '2')

    def test_sqrt(self):
        c = Context()
        d = c.sqrt(Decimal(10))
        self.assertEqual(c.sqrt(10), d)
        self.assertRaises(TypeError, c.sqrt, '10')

    def test_same_quantum(self):
        c = Context()
        d = c.same_quantum(Decimal(1), Decimal(2))
        self.assertEqual(c.same_quantum(1, 2), d)
        self.assertEqual(c.same_quantum(Decimal(1), 2), d)
        self.assertEqual(c.same_quantum(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.same_quantum, '1', 2)
        self.assertRaises(TypeError, c.same_quantum, 1, '2')

    def test_scaleb(self):
        c = Context()
        d = c.scaleb(Decimal(1), Decimal(2))
        self.assertEqual(c.scaleb(1, 2), d)
        self.assertEqual(c.scaleb(Decimal(1), 2), d)
        self.assertEqual(c.scaleb(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.scaleb, '1', 2)
        self.assertRaises(TypeError, c.scaleb, 1, '2')

    def test_shift(self):
        c = Context()
        d = c.shift(Decimal(1), Decimal(2))
        self.assertEqual(c.shift(1, 2), d)
        self.assertEqual(c.shift(Decimal(1), 2), d)
        self.assertEqual(c.shift(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.shift, '1', 2)
        self.assertRaises(TypeError, c.shift, 1, '2')

    def test_subtract(self):
        c = Context()
        d = c.subtract(Decimal(1), Decimal(2))
        self.assertEqual(c.subtract(1, 2), d)
        self.assertEqual(c.subtract(Decimal(1), 2), d)
        self.assertEqual(c.subtract(1, Decimal(2)), d)
        self.assertRaises(TypeError, c.subtract, '1', 2)
        self.assertRaises(TypeError, c.subtract, 1, '2')

    def test_to_eng_string(self):
        c = Context()
        d = c.to_eng_string(Decimal(10))
        self.assertEqual(c.to_eng_string(10), d)
        self.assertRaises(TypeError, c.to_eng_string, '10')

    def test_to_sci_string(self):
        c = Context()
        d = c.to_sci_string(Decimal(10))
        self.assertEqual(c.to_sci_string(10), d)
        self.assertRaises(TypeError, c.to_sci_string, '10')

    def test_to_integral_exact(self):
        c = Context()
        d = c.to_integral_exact(Decimal(10))
        self.assertEqual(c.to_integral_exact(10), d)
        self.assertRaises(TypeError, c.to_integral_exact, '10')

    def test_to_integral_value(self):
        c = Context()
        d = c.to_integral_value(Decimal(10))
        self.assertEqual(c.to_integral_value(10), d)
        self.assertRaises(TypeError, c.to_integral_value, '10')

class WithStatementTest(unittest.TestCase):
    # Can't do these as docstrings until Python 2.6
    # as doctest can't handle __future__ statements

    def test_localcontext(self):
        # Use a copy of the current context in the block
        orig_ctx = getcontext()
        with localcontext() as enter_ctx:
            set_ctx = getcontext()
        final_ctx = getcontext()
        self.assertTrue(orig_ctx is final_ctx, 'did not restore context correctly')
        self.assertTrue(orig_ctx is not set_ctx, 'did not copy the context')
        self.assertTrue(set_ctx is enter_ctx, '__enter__ returned wrong context')

    def test_localcontextarg(self):
        # Use a copy of the supplied context in the block
        orig_ctx = getcontext()
        new_ctx = Context(prec=42)
        with localcontext(new_ctx) as enter_ctx:
            set_ctx = getcontext()
        final_ctx = getcontext()
        self.assertTrue(orig_ctx is final_ctx, 'did not restore context correctly')
        self.assertTrue(set_ctx.prec == new_ctx.prec, 'did not set correct context')
        self.assertTrue(new_ctx is not set_ctx, 'did not copy the context')
        self.assertTrue(set_ctx is enter_ctx, '__enter__ returned wrong context')

    def test_nested_with_statements(self):
        # Use a copy of the supplied context in the block
        orig_ctx = getcontext()
        orig_ctx.clear_flags()
        new_ctx = Context(Emax=384)
        with localcontext() as c1:
            self.assertEqual(c1.flags, orig_ctx.flags)
            self.assertEqual(c1.traps, orig_ctx.traps)
            c1.traps[Clamped] = True
            c1.Emin = -383
            self.assertRaises(Clamped, c1.create_decimal, '0e-999')
            self.assertTrue(c1.flags[Clamped])
            with localcontext(new_ctx) as c2:
                self.assertEqual(c2.flags, new_ctx.flags)
                self.assertEqual(c2.traps, new_ctx.traps)
                self.assertRaises(Overflow, c2.power, Decimal('3.4e200'), 2)
                self.assertFalse(c2.flags[Clamped])
                self.assertTrue(c2.flags[Overflow])
                del c2
            self.assertFalse(c1.flags[Overflow])
            del c1
        self.assertNotEqual(orig_ctx.Emin, -383)
        self.assertFalse(orig_ctx.flags[Clamped])
        self.assertFalse(orig_ctx.flags[Overflow])
        self.assertFalse(new_ctx.flags[Clamped])
        self.assertFalse(new_ctx.flags[Overflow])

    def test_with_statements_gc1(self):
        with localcontext() as c1:
            del c1
            with localcontext() as c2:
                del c2
                with localcontext() as c3:
                    del c3
                    with localcontext() as c4:
                        del c4

    def test_with_statements_gc2(self):
        with localcontext() as c1:
            with localcontext(c1) as c2:
                del c1
                with localcontext(c2) as c3:
                    del c2
                    with localcontext(c3) as c4:
                        del c3
                        del c4

    def test_with_statements_gc3(self):
        with localcontext() as c1:
            del c1
            n1 = Context(prec=1)
            setcontext(n1)
            with localcontext(n1) as c2:
                del n1
                self.assertEqual(c2.prec, 1)
                del c2
                n2 = Context(prec=2)
                setcontext(n2)
                del n2
                self.assertEqual(getcontext().prec, 2)
                n3 = Context(prec=3)
                setcontext(n3)
                self.assertEqual(getcontext().prec, 3)
                with localcontext(n3) as c3:
                    del n3
                    self.assertEqual(c3.prec, 3)
                    del c3
                    n4 = Context(prec=4)
                    setcontext(n4)
                    del n4
                    self.assertEqual(getcontext().prec, 4)
                    with localcontext() as c4:
                        self.assertEqual(c4.prec, 4)
                        del c4

class ContextFlags(unittest.TestCase):
    def test_flags_irrelevant(self):
        # check that the result (numeric result + flags raised) of an
        # arithmetic operation doesn't depend on the current flags

        # XXX 32-bit limits
        context = Context(prec=9, Emin=-425000000, Emax=425000000,
                    rounding=ROUND_HALF_EVEN, traps=[], flags=[])

        # operations that raise various flags, in the form (function, arglist)
        operations = [
            (context._apply, [Decimal("100E-425000010")]),
            (context.sqrt, [Decimal(2)]),
            (context.add, [Decimal("1.23456789"), Decimal("9.87654321")]),
            (context.multiply, [Decimal("1.23456789"), Decimal("9.87654321")]),
            (context.subtract, [Decimal("1.23456789"), Decimal("9.87654321")]),
            ]

        # try various flags individually, then a whole lot at once
        flagsets = [[Inexact], [Rounded], [Underflow], [Clamped], [Subnormal],
                    [Inexact, Rounded, Underflow, Clamped, Subnormal]]

        for fn, args in operations:
            # find answer and flags raised using a clean context
            context.clear_flags()
            ans = fn(*args)
            flags = [k for k, v in context.flags.items() if v]

            for extra_flags in flagsets:
                # set flags, before calling operation
                context.clear_flags()
                for flag in extra_flags:
                    # XXX _raise_error
                    # context._raise_error(flag)
                    context.flags[flag] = True
                new_ans = fn(*args)

                # flags that we expect to be set after the operation
                expected_flags = list(flags)
                for flag in extra_flags:
                    if flag not in expected_flags:
                        expected_flags.append(flag)
                expected_flags.sort()

                # flags we actually got
                new_flags = [k for k,v in context.flags.items() if v]
                new_flags.sort()

                self.assertEqual(ans, new_ans,
                                 "operation produces different answers depending on flags set: " +
                                 "expected %s, got %s." % (ans, new_ans))
                self.assertEqual(new_flags, expected_flags,
                                  "operation raises different flags depending on flags set: " +
                                  "expected %s, got %s" % (expected_flags, new_flags))

class SpecialContexts(unittest.TestCase):
    def test_context_templates(self):
        self.assertEqual(
            BasicContext._traps,
            DecIEEEInvalidOperation|DecDivisionByZero|DecOverflow|
            DecUnderflow|DecClamped
        )

        basic_context_prec = BasicContext.prec
        extended_context_prec = ExtendedContext.prec

        BasicContext.prec = ExtendedContext.prec = 441

        for template in BasicContext, ExtendedContext:
            setcontext(template)
            c = getcontext()
            self.assertFalse(c is template)
            self.assertEqual(c.prec, 441)

        BasicContext.prec = basic_context_prec
        ExtendedContext.prec = extended_context_prec

    def test_default_context(self):
        self.assertEqual(
            DefaultContext._traps,
            DecIEEEInvalidOperation|DecDivisionByZero|DecOverflow
        )

        default_context_prec = DefaultContext.prec

        c = getcontext()
        saveprec = c.prec

        DefaultContext.prec = 961
        c = getcontext()
        self.assertEqual(c.prec, saveprec)

        setcontext(DefaultContext)
        c = getcontext()
        self.assertFalse(c is DefaultContext)
        self.assertEqual(c.prec, 961)

        DefaultContext.prec = default_context_prec

    def test_ieee_context(self):
        def assert_rest(self, context):
            self.assertEqual(context.clamp, 1)
            for v in context.traps.values():
                self.assertFalse(v)
            for v in context.flags.values():
                self.assertFalse(v)

        c = IEEEContext(DECIMAL32)
        self.assertEqual(c.prec, 7)
        self.assertEqual(c.Emax, 96)
        self.assertEqual(c.Emin, -95)
        assert_rest(self, c)

        c = IEEEContext(DECIMAL64)
        self.assertEqual(c.prec, 16)
        self.assertEqual(c.Emax, 384)
        self.assertEqual(c.Emin, -383)
        assert_rest(self, c)

        c = IEEEContext(DECIMAL128)
        self.assertEqual(c.prec, 34)
        self.assertEqual(c.Emax, 6144)
        self.assertEqual(c.Emin, -6143)
        assert_rest(self, c)

class Coverage(unittest.TestCase):

    def test_bignum(self):
        b1 = 10**35
        b2 = 10**36
        with localcontext() as c:
            c.prec = 1000000
            for i in range(5):
                a = random.randrange(b1, b2)
                b = random.randrange(1000, 1200)
                x = a ** b
                y = Decimal(a) ** Decimal(b)
                self.assertEqual(x, y)

def test_main(arith=False, verbose=None, todo_tests=None, debug=None):
    """ Execute the tests.

    Runs all arithmetic tests if arith is True or if the "decimal" resource
    is enabled in regrtest.py
    """

    init()
    global TEST_ALL, DEBUG
    TEST_ALL = arith or is_resource_enabled('decimal')
    DEBUG = debug

    if todo_tests is None:
        test_classes = [
            DecimalExplicitConstructionTest,
            DecimalImplicitConstructionTest,
            DecimalArithmeticOperatorsTest,
            DecimalUseOfContextTest,
            DecimalUsabilityTest,
            DecimalPythonAPItests,
            ContextAPItests,
            DecimalTest,
            WithStatementTest,
            ContextFlags,
            SpecialContexts,
            Coverage
        ]
    else:
        test_classes = [DecimalTest]

    # Dynamically build custom test definition for each file in the test
    # directory and add the definitions to the DecimalTest class.  This
    # procedure insures that new files do not get skipped.
    for filename in os.listdir(directory):
        if '.decTest' not in filename or filename.startswith("."):
            continue
        head, tail = filename.split('.')
        if todo_tests is not None and head not in todo_tests:
            continue
        tester = lambda self, f=filename: self.eval_file(directory + f)
        setattr(DecimalTest, 'test_' + head, tester)
        del filename, head, tail, tester


    try:
        run_unittest(*test_classes)
        if todo_tests is None:
            import cdecimal as DecimalModule
    finally:
        setcontext(ORIGINAL_CONTEXT)

if __name__ == '__main__':
    import optparse
    p = optparse.OptionParser("test_decimal.py [--debug] [{--skip | test1 [test2 [...]]}]")
    p.add_option('--debug', '-d', action='store_true', help='shows the test number and context before each test')
    p.add_option('--skip',  '-s', action='store_true', help='skip over 90% of the arithmetic tests')
    (opt, args) = p.parse_args()

    if opt.skip:
        test_main(arith=False, verbose=True)
    elif args:
        test_main(arith=True, verbose=True, todo_tests=args, debug=opt.debug)
    else:
        test_main(arith=True, verbose=True)
