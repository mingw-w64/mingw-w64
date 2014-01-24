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


import sys, os, platform, re
from shutil import copy2
from glob import glob
from distutils import sysconfig
from distutils.core import setup, Extension


DESCRIPTION = """\
Fast arbitrary precision correctly-rounded decimal floating point arithmetic.\
"""

LONG_DESCRIPTION = """
Overview
--------

The ``cdecimal`` package is a fast drop-in replacement for the ``decimal`` module
in Python's standard library. Both modules provide complete implementations of
Mike Cowlishaw/IBM's ``General Decimal Arithmetic Specification``.

Testing
-------

Both ``cdecimal`` and the underlying library - ``libmpdec`` - are extremely
well tested. ``libmpdec`` is one of the few open source projects with 100%
code coverage. ``cdecimal`` is rigorously tested against ``decimal.py``.

Short benchmarks
----------------

Typical performance gains are between 30x for I/O heavy benchmarks
and 80x for numerical programs. In a database benchmark, cdecimal
exhibits a speedup of 12x over decimal.py.

+---------+-------------+--------------+-------------+
|         |   decimal   |   cdecimal   |   speedup   |
+=========+=============+==============+=============+
|   pi    |    42.75s   |    0.58s     |     74x     |
+---------+-------------+--------------+-------------+
| telco   |   172.19s   |    5.68s     |     30x     |
+---------+-------------+--------------+-------------+
| psycopg |     3.57s   |    0.29s     |     12x     |
+---------+-------------+--------------+-------------+

Documentation
-------------

Since ``cdecimal`` is compatible with ``decimal.py``, the official documentation
is valid. For the few remaining differences, refer to the second link.

* `Decimal module <http://docs.python.org/dev/py3k/library/decimal.html>`_
* `Differences between cdecimal and decimal <http://www.bytereef.org/mpdecimal/doc/cdecimal/index.html>`_

Linux Notes
-----------

The build process requires a working C compiler and a *full* Python install with
development headers. Linux distributions often ship the Python header files as
a separate package, called *python-dev* or *python-devel*.

Install headers on Debian/Ubuntu:

* ``sudo apt-get install python-dev``

Windows Notes
-------------

* `Binary installers <http://www.bytereef.org/mpdecimal/download.html>`_

Links
-----

* `cdecimal project homepage <http://www.bytereef.org/mpdecimal/index.html>`_
* `cdecimal benchmarks <http://www.bytereef.org/mpdecimal/benchmarks.html>`_

"""


PY_MAJOR = sys.version_info[0]
PY_MINOR = sys.version_info[1]
ARCH = platform.architecture()[0]
SYSTEM = sys.platform
MACHINE = None

def err_exit(mesg):
    sys.stderr.write("setup.py: error: %s\n" % mesg)
    sys.exit(1)

def uninstall():
    def check_file(name, again=False):
        inputfunc = input if PY_MAJOR >= 3 else raw_input
        if re.search('cdecimal.*\.(so|pyd|egg)', name):
            if again:
                ans = inputfunc("Please answer 'y' or 'n': ")
            else:
                print("Previously installed version detected: %s" % name)
                ans = inputfunc("Remove it [y/n]? ")
            ans = ans.lower()
            if ans == 'y':
                os.unlink(name)
            elif ans != 'n':
                check_file(name, True)
    for p in sys.path:
        if os.path.isdir(p):
            for item in os.listdir(p):
                f = os.path.join(p, item)
                check_file(f)
        elif os.path.isfile(p):
            check_file(p)


if not ((PY_MAJOR == 2 and PY_MINOR >= 5) or PY_MAJOR >= 3):
    err_exit("Python version >= 2.5 required.")
if not (ARCH == '64bit' or ARCH == '32bit'):
    err_exit("64-bit or 32-bit machine required.")

if 'uninstall' in sys.argv:
    uninstall()
    sys.exit(0)


define_macros = []
undef_macros = ['NDEBUG']
if 'build' in sys.argv or 'build_ext' in sys.argv:
    sys.argv.append('--force')
if '--without-threads' in sys.argv:
    # In mpdecimal-1.2, the speed penalty for thread local contexts
    # has been reduced to 8-16%. The default is now to enable thread
    # local contexts. To get the old default (faster), use this option.
    sys.argv.remove('--without-threads')
    define_macros.append(('WITHOUT_THREADS', 1))
else:
    if SYSTEM == 'win32': # also valid for 64-bit.
        try:
            import threading
        except ImportError:
            define_macros.append(('WITHOUT_THREADS', 1))
    elif not sysconfig.get_config_var('WITH_THREAD'):
        define_macros.append(('WITHOUT_THREADS', 1))

# Force specific configuration:
c = ('x64', 'uint128', 'ansi64', 'ppro', 'ansi32', 'ansi-legacy', 'universal')
for i, v in enumerate(sys.argv[:]):
    if '--with-machine=' in v:
        MACHINE = v.split('=')[1]
        sys.argv.pop(i)
        break
if MACHINE and not MACHINE in c:
    err_exit("invalid machine: %s" % MACHINE)

if not MACHINE and 'darwin' in SYSTEM:
    # multi-arch support
    MACHINE = 'universal'

if SYSTEM == 'win32':
    # For automated testing: remove empty string
    sys.argv = [v for v in sys.argv if v != ""]


#
# Generally, it is also possible to build the static libmpdec.a and
# use that to build the Python module. There are systems where this
# approach leads to problems:
#
# Windows: Changes made by Python's setlocale() only affect the
#          state of the dynamically linked CRT. This means that
#          some features of the format() function will not work
#          properly.
#
# AIX:     If built with the static library, the gcc-internals
#          __multi3 and __udivti3 are undefined.
#
MULTILIB_ERR_64 = """
##
## Error: 64-bit Python detected, but ./configure generates 32-bit config.
##
## One of the following choices must be passed to setup.py:
##
##    --with-machine={x64,uint128,ansi64}
##
## OS X only, universal build:
##
##    --with-machine=universal
##
"""
MULTILIB_ERR_32 = """
##
## Error: 32-bit Python detected, but ./configure generates 64-bit config.
##
## One of the following choices must be passed to setup.py:
##
##    --with-machine={ppro,ansi32}
##
## OS X only, universal build:
##
##    --with-machine=universal
##
"""

def configure(machine, cc, py_size_t):
    os.chmod("./configure", 0x1ed) # pip removes execute permissions.
    if machine: # string has been validated.
        os.system("./configure MACHINE=%s" % machine)
    elif 'sunos' in SYSTEM and py_size_t == 8:
        # cc is from sysconfig.
        os.system("./configure CC='%s -m64'" % cc)
    else:
        os.system("./configure")
    f = open("config.h")
    config_vars = {}
    for line in f:
        if line.startswith("#define"):
            l = line.split()
            try:
                config_vars[l[1]] = int(l[2])
            except ValueError:
                pass
        elif line.startswith("/* #undef"):
            l = line.split()
            config_vars[l[2]] = 0
    f.close()
    return config_vars

def cdecimal_ext(machine):
    depends = [
        'basearith.h', 'bits.h', 'constants.h', 'convolute.h', 'crt.h',
        'difradix2.h', 'docstrings.h', 'fnt.h', 'fourstep.h', 'io.h',
        'memory.h', 'mpdecimal.h', 'mpdecimal32.h', 'mpdecimal64.h',
        'mptypes.h', 'numbertheory.h', 'sixstep.h', 'transpose.h',
        'typearith.h', 'umodarith.h'
    ]
    sources = [
        'basearith.c', 'constants.c', 'context.c', 'convolute.c',
        'crt.c', 'difradix2.c', 'fnt.c', 'fourstep.c', 'io.c', 'memory.c',
        'mpdecimal.c', 'numbertheory.c', 'sixstep.c', 'transpose.c'
    ]
    sources.append('cdecimal2.c' if PY_MAJOR == 2 else 'cdecimal3.c')
    extra_compile_args = []
    extra_link_args = []
    extra_objects = []


    if SYSTEM == 'win32':
        define_macros.append(('_CRT_SECURE_NO_WARNINGS', '1'))
        if not machine: # command line option
            if ARCH == '64bit':
                machine = 'x64'
            else:
                machine = 'ppro'

        if machine == 'x64':
            if not (PY_MAJOR == 2 and PY_MINOR == 5):
                # set the build environment for ml64
                from distutils.msvc9compiler import MSVCCompiler
                cc = MSVCCompiler()
                cc.initialize()
                del cc
            define_macros.extend([('CONFIG_64', '1'), ('MASM', '1')])
            extra_objects = ['vcdiv64.obj']
            os.system("ml64 /c /Cx vcdiv64.asm")
            copy2("mpdecimal64vc.h", "mpdecimal.h")
        elif machine == 'ansi64':
            define_macros.extend([('CONFIG_64', '1'), ('ANSI', '1')])
            copy2("mpdecimal64vc.h", "mpdecimal.h")
        elif machine == 'ppro':
            define_macros.extend([('CONFIG_32', '1'), ('PPRO', '1'),
                                  ('MASM', '1')])
            copy2("mpdecimal32vc.h", "mpdecimal.h")
        elif machine == 'ansi32':
            define_macros.extend([('CONFIG_32', '1'), ('ANSI', '1')])
            copy2("mpdecimal32vc.h", "mpdecimal.h")
        elif machine == 'ansi-legacy':
            define_macros.extend([('CONFIG_32', '1'), ('ANSI', '1'),
                                  ('LEGACY_COMPILER', '1')])
            copy2("mpdecimal32vc.h", "mpdecimal.h")
        else:
            err_exit("unsupported machine: %s" % machine)

    else:
        cc = sysconfig.get_config_var('CC')
        py_size_t = sysconfig.get_config_var('SIZEOF_SIZE_T')
        if py_size_t != 8 and py_size_t != 4:
            err_exit("unsupported architecture: sizeof(size_t) must be 8 or 4")

        depends.append('config.h')
        config_vars = configure(machine, cc, py_size_t)
        if config_vars['SIZEOF_SIZE_T'] != 8 and \
           config_vars['SIZEOF_SIZE_T'] != 4:
            err_exit("unsupported architecture: sizeof(size_t) must be 8 or 4")

        if not machine and py_size_t != config_vars['SIZEOF_SIZE_T']:
            if py_size_t == 8:
                print(MULTILIB_ERR_64)
            elif py_size_t == 4:
                print(MULTILIB_ERR_32)
            sys.exit(1)

        if not machine:
            if config_vars['HAVE_GCC_ASM_FOR_X64']:
                machine = 'x64'
            elif config_vars['HAVE_UINT128_T']:
                machine = 'uint128'
            elif config_vars['HAVE_GCC_ASM_FOR_X87']:
                machine = 'ppro'

        if machine == 'universal':
            add_macros = [('UNIVERSAL', '1')]
        elif py_size_t == 8:
            if machine == 'x64':
                add_macros = [('CONFIG_64', '1'), ('ASM', '1')]
            elif machine == 'uint128':
                add_macros = [('CONFIG_64', '1'), ('ANSI', '1'),
                              ('HAVE_UINT128_T', '1')]
            else:
                add_macros = [('CONFIG_64', '1'), ('ANSI', '1')]
        else:
            if machine == 'ppro' and ('gcc' in cc or 'clang' in cc):
                # suncc: register allocator cannot deal with the inline asm.
                # icc >= 11.0 works as well.
                add_macros = [('CONFIG_32', '1'), ('PPRO', '1'), ('ASM', '1')]
                if config_vars['HAVE_IPA_PURE_CONST_BUG']:
                    # Some versions of gcc miscompile inline asm:
                    # http://gcc.gnu.org/bugzilla/show_bug.cgi?id=46491
                    # http://gcc.gnu.org/ml/gcc/2010-11/msg00366.html
                    extra_compile_args.extend(['-fno-ipa-pure-const'])
            else: # ansi32
                add_macros = [('CONFIG_32', '1'), ('ANSI', '1')]
                if machine == 'ansi-legacy':
                    add_macros.append(('LEGACY_COMPILER', '1'))

        # Uncomment for warnings:
        # extra_compile_args.extend(['-Wall', '-W', '-Wno-missing-field-initializers'])

        # Uncomment for a debug build:
        # extra_compile_args.extend(['-O0', '-g'])

        if os.environ.get("CFLAGS"):
            # Distutils drops -fno-strict-aliasing if CFLAGS are set:
            # http://bugs.python.org/issue10847
            if 'xlc' in cc:
                extra_compile_args.append('-qnoansialias')
            else:
                extra_compile_args.append('-fno-strict-aliasing')

        define_macros.extend(add_macros)

        if config_vars['HAVE_GLIBC_MEMMOVE_BUG']:
            # _FORTIFY_SOURCE wrappers for memmove and bcopy are incorrect:
            # http://sourceware.org/ml/libc-alpha/2010-12/msg00009.html
            undef_macros.append('_FORTIFY_SOURCE')

    ext = Extension (
        'cdecimal',
        define_macros=define_macros,
        undef_macros=undef_macros,
        depends=depends,
        extra_compile_args=extra_compile_args,
        extra_link_args=extra_link_args,
        sources=sources,
        extra_objects=extra_objects
    )
    return ext


setup (
    name = 'cdecimal',
    version = '2.3',
    description = DESCRIPTION,
    long_description = LONG_DESCRIPTION,
    url = 'http://www.bytereef.org/mpdecimal/index.html',
    author = 'Stefan Krah',
    author_email = 'skrah@bytereef.org',
    license = 'BSD License',
    download_url = 'http://www.bytereef.org/software/mpdecimal/releases/cdecimal-2.3.tar.gz',
    keywords = ["decimal", "floating point", "correctly-rounded",
                "arithmetic", "arbitrary precision"],
    platforms = ["Many"],
    classifiers = [
        "Development Status :: 5 - Production/Stable",
        "Intended Audience :: Developers",
        "Intended Audience :: Education",
        "Intended Audience :: End Users/Desktop",
        "Intended Audience :: Financial and Insurance Industry",
        "Intended Audience :: Science/Research",
        "License :: OSI Approved :: BSD License",
        "Programming Language :: C",
        "Programming Language :: Python :: 2.5",
        "Programming Language :: Python :: 2.6",
        "Programming Language :: Python :: 2.7",
        "Programming Language :: Python :: 3",
        "Programming Language :: Python :: 3.1",
        "Programming Language :: Python :: 3.2",
        "Operating System :: OS Independent",
        "Topic :: Scientific/Engineering :: Mathematics",
        "Topic :: Software Development"
    ],
    ext_modules = [cdecimal_ext(MACHINE)]
)


PATHLIST = glob("build/lib.*/cdecimal*")
if PATHLIST:
    CDECIMAL = PATHLIST[0]
    copy2(CDECIMAL, "python")



