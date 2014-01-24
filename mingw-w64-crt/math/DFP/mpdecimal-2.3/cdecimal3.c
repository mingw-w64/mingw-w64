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


#include <Python.h>
#include "longintrepr.h"
#include "pythread.h"
#include "structmember.h"
#include "complexobject.h"
#include mpdecimal_header

#include <stdlib.h>

#include "docstrings.h"
#include "memory.h"
#include "mptypes.h"


#if PY_VERSION_HEX < 0x03000000
  #error "Python versions < 3.0 not supported."
#endif

#if defined(_MSC_VER)
  #define ALWAYS_INLINE __forceinline
#elif defined(LEGACY_COMPILER)
  #define ALWAYS_INLINE
  #undef inline
  #define inline
#else
  #ifdef TEST_COVERAGE
    #define ALWAYS_INLINE
  #else
    #define ALWAYS_INLINE inline __attribute__ ((always_inline))
  #endif
#endif

#if defined(_MSC_VER) && defined (CONFIG_64)
  #define _PyLong_AsMpdSsize PyLong_AsLongLong
  #define _PyLong_FromMpdSsize PyLong_FromSsize_t
#else
  #define _PyLong_AsMpdSsize PyLong_AsLong
  #define _PyLong_FromMpdSsize PyLong_FromLong
#endif

#define Dec_INCREF_TRUE (Py_INCREF(Py_True), Py_True)
#define Dec_INCREF_FALSE (Py_INCREF(Py_False), Py_False)

#define MPD_Float_operation MPD_Not_implemented

#define BOUNDS_CHECK(x, MIN, MAX) x = (x < MIN || MAX < x) ? MAX : x


typedef struct {
	PyObject_HEAD
	mpd_t *dec;
} PyDecObject;

typedef struct {
	PyDictObject dict;
	uint32_t *flags;
} PyDecSignalDictObject;

typedef struct {
	PyObject_HEAD
	mpd_context_t ctx;
	PyObject *traps;
	PyObject *flags;
	int capitals;
} PyDecContextObject;

typedef struct {
	PyObject_HEAD
	PyObject *local;
	PyObject *global;
} PyDecContextManagerObject;


#undef MPD
#undef CTX
static PyTypeObject PyDec_Type;
static PyTypeObject PyDecSignalDict_Type;
static PyTypeObject PyDecContext_Type;
static PyTypeObject PyDecContextManager_Type;
#define PyDec_CheckExact(v) (Py_TYPE(v) == &PyDec_Type)
#define PyDec_Check(v) PyObject_TypeCheck(v, &PyDec_Type)
#define PyDecSignalDict_Check(v) (Py_TYPE(v) == &PyDecSignalDict_Type)
#define PyDecContext_Check(v) (Py_TYPE(v) == &PyDecContext_Type)
#define MPD(v) (((PyDecObject *)v)->dec)
#define SdFlagAddr(v) (((PyDecSignalDictObject *)v)->flags)
#define SdFlags(v) (*((PyDecSignalDictObject *)v)->flags)
#define CTX(v) (&((PyDecContextObject *)v)->ctx)
#define CtxCaps(v) (((PyDecContextObject *)v)->capitals)


#ifdef WITHOUT_THREADS
/* Default module context */
static PyObject *module_context = NULL;
#else
/* Key for thread state dictionary */
static PyObject *tls_context_key = NULL;
#endif

/* Template for creating new thread contexts, calling Context() without
 * arguments and initializing the module_context on first access. */
static PyObject *default_context_template = NULL;
/* Basic and extended context templates */
static PyObject *basic_context_template = NULL;
static PyObject *extended_context_template = NULL;


typedef struct {
	const char *name;
	const char *fqname;
	uint32_t mpd_cond;
	PyObject *dec_cond;
} DecCondMap;

/* Top level Exception; inherits from ArithmeticError */
static PyObject *DecimalException = NULL;

/* Exceptions that correspond to IEEE signals; inherit from DecimalException */
static DecCondMap signal_map[] = {
  {"InvalidOperation", "cdecimal.InvalidOperation", MPD_IEEE_Invalid_operation, NULL},
  {"FloatOperation", "cdecimal.FloatOperation", MPD_Float_operation, NULL},
  {"DivisionByZero", "cdecimal.DivisionByZero", MPD_Division_by_zero, NULL},
  {"Overflow", "cdecimal.Overflow", MPD_Overflow, NULL},
  {"Underflow", "cdecimal.Underflow", MPD_Underflow, NULL},
  {"Subnormal", "cdecimal.Subnormal", MPD_Subnormal, NULL},
  {"Inexact", "cdecimal.Inexact", MPD_Inexact, NULL},
  {"Rounded", "cdecimal.Rounded", MPD_Rounded, NULL},
  {"Clamped", "cdecimal.Clamped", MPD_Clamped, NULL},
  {NULL}
};

/* Exceptions that inherit from InvalidOperation */
static DecCondMap cond_map[] = {
  {"InvalidOperation", "cdecimal.InvalidOperation", MPD_Invalid_operation, NULL},
  {"ConversionSyntax", "cdecimal.ConversionSyntax", MPD_Conversion_syntax, NULL},
  {"DivisionImpossible", "cdecimal.DivisionImpossible", MPD_Division_impossible, NULL},
  {"DivisionUndefined", "cdecimal.DivisionUndefined", MPD_Division_undefined, NULL},
  {"FpuError", "cdecimal.FpuError", MPD_Fpu_error, NULL},
  {"InvalidContext", "cdecimal.InvalidContext", MPD_Invalid_context, NULL},
  {"MallocError", "cdecimal.MallocError", MPD_Malloc_error, NULL},
  {NULL}
};

static const char *dec_signal_string[MPD_NUM_FLAGS] = {
	"Clamped",
	"InvalidOperation",
	"DivisionByZero",
	"InvalidOperation",
	"InvalidOperation",
	"InvalidOperation",
	"Inexact",
	"InvalidOperation",
	"InvalidOperation",
	"InvalidOperation",
	"FloatOperation",
	"Overflow",
	"Rounded",
	"Subnormal",
	"Underflow",
};

static const char *invalid_rounding_err =
"valid values for rounding are:\n\
  [ROUND_CEILING, ROUND_FLOOR, ROUND_UP, ROUND_DOWN,\n\
   ROUND_HALF_UP, ROUND_HALF_DOWN, ROUND_HALF_EVEN,\n\
   ROUND_05UP].";

static const char *invalid_signals_err =
"valid values for signals are:\n\
  [InvalidOperation, FloatOperation, DivisionByZero,\n\
   Overflow, Underflow, Subnormal, Inexact, Rounded,\n\
   Clamped].";

static const char *invalid_flags_err =
"valid values for _flags or _traps are:\n\
  signals:\n\
    [DecIEEEInvalidOperation, DecFloatOperation, DecDivisionByZero,\n\
     DecOverflow, DecUnderflow, DecSubnormal, DecInexact, DecRounded,\n\
     DecClamped]\n\
  conditions which trigger DecIEEEInvalidOperation:\n\
    [DecInvalidOperation, DecConversionSyntax, DecDivisionImpossible,\n\
     DecDivisionUndefined, DecFpuError, DecInvalidContext, DecMallocError]";

static int
value_error_int(const char *mesg)
{
	PyErr_SetString(PyExc_ValueError, mesg);
	return -1;
}

static int
type_error_int(const char *mesg)
{
	PyErr_SetString(PyExc_TypeError, mesg);
	return -1;
}

static PyObject *
type_error_ptr(const char *mesg)
{
	PyErr_SetString(PyExc_TypeError, mesg);
	return NULL;
}

static int
runtime_error_int(const char *mesg)
{
	PyErr_SetString(PyExc_RuntimeError, mesg);
	return -1;
}
#define INTERNAL_ERROR_INT(funcname) \
    return runtime_error_int("internal error in " funcname ".")

static PyObject *
runtime_error_ptr(const char *mesg)
{
	PyErr_SetString(PyExc_RuntimeError, mesg);
	return NULL;
}
#define INTERNAL_ERROR_PTR(funcname) \
    return runtime_error_ptr("internal error in " funcname ".")

static void
dec_traphandler(mpd_context_t *ctx UNUSED) /* GCOV_NOT_REACHED */
{ /* GCOV_NOT_REACHED */
	return; /* GCOV_NOT_REACHED */
}

static PyObject *
flags_as_exception(uint32_t flags)
{
	DecCondMap *cm;

	for (cm = signal_map; cm->name != NULL; cm++) {
		if (flags&cm->mpd_cond) {
			return cm->dec_cond;
		}
	}

	INTERNAL_ERROR_PTR("flags_as_exception"); /* GCOV_NOT_REACHED */
}

static uint32_t
exception_as_flags(PyObject *ex)
{
	DecCondMap *cm;

	for (cm = signal_map; cm->name != NULL; cm++) {
		if (cm->dec_cond == ex) {
			return cm->mpd_cond;
		}
	}

	PyErr_SetString(PyExc_TypeError, invalid_signals_err);
	return UINT32_MAX;
}

static PyObject *
flags_as_list(uint32_t flags)
{
	PyObject *list;
	DecCondMap *cm;

	if ((list = PyList_New(0)) == NULL) {
		return NULL;
	}

	for (cm = cond_map; cm->name != NULL; cm++) {
		if (flags&cm->mpd_cond) {
			if (PyList_Append(list, cm->dec_cond) < 0) {
				goto error;
			}
		}
	}
	for (cm = signal_map+1; cm->name != NULL; cm++) {
		if (flags&cm->mpd_cond) {
			if (PyList_Append(list, cm->dec_cond) < 0) {
				goto error;
			}
		}
	}

	return list;

error:
	Py_DECREF(list);
	return NULL;
}

static PyObject *
signals_as_list(uint32_t flags)
{
	PyObject *list;
	DecCondMap *cm;

	if ((list = PyList_New(0)) == NULL) {
		return NULL;
	}

	for (cm = signal_map; cm->name != NULL; cm++) {
		if (flags&cm->mpd_cond) {
			if (PyList_Append(list, cm->dec_cond) < 0) {
				goto error;
			}
		}
	}

	return list;

error:
	Py_DECREF(list);
	return NULL;
}

static uint32_t
list_as_flags(PyObject *list)
{
	PyObject *item;
	uint32_t flags, x;
	ssize_t n, j;

	if (!PyList_Check(list)) {
		PyErr_SetString(PyExc_TypeError,
		    "argument must be a list of signals.");
		return UINT32_MAX;
	}

	n = PyList_Size(list);
	flags = 0;
	for (j = 0; j < n; j++) {
		item = PyList_GetItem(list, j);
		if ((x = exception_as_flags(item)) == UINT32_MAX) {
			return UINT32_MAX;
		}
		flags |= x;
	}

	return flags;
}

static int
dict_as_flags(PyObject *val)
{
	PyObject *b;
	DecCondMap *cm;
	uint32_t flags = 0;
	int x;

	if (!PyDict_Check(val)) {
		PyErr_SetString(PyExc_TypeError,
		    "argument must be a signal dict.");
		return -1;
	}

	for (cm = signal_map; cm->name != NULL; cm++) {
		if ((b = PyDict_GetItemWithError(val, cm->dec_cond)) == NULL) {
			if (!PyErr_Occurred()) {
				PyErr_SetString(PyExc_TypeError,
		 		   "invalid signal dict.");
			}
			return UINT32_MAX;
		}

		if ((x = PyObject_IsTrue(b)) < 0) {
			return UINT32_MAX;
		}
		if (x == 1) {
			flags |= cm->mpd_cond;
		}
	}

	return flags;
}

static uint32_t
long_as_flags(PyObject *v)
{
	long x;

	x = PyLong_AsLong(v);
	if (PyErr_Occurred()) {
		return UINT32_MAX;
	}
	if (x < 0 || x > (long)MPD_Max_status) {
		PyErr_SetString(PyExc_TypeError, invalid_flags_err);
		return UINT32_MAX;
	}

	return x;
}

static mpd_ssize_t
long_as_mpd_ssize(PyObject *v)
{
	mpd_ssize_t x;

	if (!PyLong_Check(v)) {
		PyErr_SetString(PyExc_TypeError,
		    "integer argument required.");
		return MPD_SSIZE_MAX;
	}

	x = _PyLong_AsMpdSsize(v);
	if (PyErr_Occurred()) {
		return MPD_SSIZE_MAX;
	}

	return x;
}

static int
dec_addstatus(PyObject *context, uint32_t status)
{
	mpd_context_t *ctx = CTX(context);

	ctx->status |= status;
	if (ctx->traps&status) {
		PyObject *ex, *siglist;

		ex = flags_as_exception(ctx->traps&status);
		if (ex == NULL) {
			return 1; /* GCOV_NOT_REACHED */
		}
		siglist = flags_as_list(ctx->traps&status);
		if (siglist == NULL) {
			return 1;
		}

		PyErr_SetObject(ex, siglist);
		Py_DECREF(siglist);
		return 1;
	}
	return 0;
}


/******************************************************************************/
/*                            SignalDict Object                               */
/******************************************************************************/

static int
signaldict_init(PyObject *self, PyObject *args, PyObject *kwds)
{
	if (PyDict_Type.tp_init(self, args, kwds) < 0) {
		return -1;
	}

	SdFlagAddr(self) = NULL;
	return 0;
}

/* sync flags and dictionary, using the flags as the master */
static int
signaldict_update(PyObject *self)
{
	PyObject *b;
	DecCondMap *cm;
	uint32_t flags;

	flags = SdFlags(self);

	for (cm = signal_map; cm->name != NULL; cm++) {
		b = (flags&cm->mpd_cond) ? Py_True : Py_False;
		if (PyDict_SetItem(self, cm->dec_cond, b) < 0) {
			return -1;
		}
	}
	return 0;
}

/* set all flags to false */
static int
signaldict_clear_all(PyObject *self)
{
	DecCondMap *cm;

	SdFlags(self) = 0;

	for (cm = signal_map; cm->name != NULL; cm++) {
		if (PyDict_SetItem(self, cm->dec_cond, Py_False) < 0) {
			return -1;
		}
	}
	return 0;
}

static int
signaldict_setitem(PyObject *self, PyObject *key, PyObject *value)
{
	uint32_t flag;
	int x;

	if ((flag = exception_as_flags(key)) == UINT_MAX) {
		return -1;
	}

	if ((x = PyObject_IsTrue(value)) < 0) {
		return -1;
	}
	if (x == 1) {
		SdFlags(self) |= flag;
		if (PyDict_SetItem(self, key, Py_True) < 0) {
			return -1;
		}
		return 0;
	}
	else {
		SdFlags(self) &= ~flag;
		if (PyDict_SetItem(self, key, Py_False) < 0) {
			return -1;
		}
		return 0;
	}
}

static PyObject *
signaldict_call_unary(PyObject *self, char *name)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyObject_CallMethod((PyObject *)&PyDict_Type, name, "O", self);
}

static PyObject *
signaldict_richcompare(PyObject *a, PyObject *b, int op)
{
	if (PyDecSignalDict_Check(a)) {
		if (signaldict_update(a) < 0) {
			return NULL;
		}
	}
	if (PyDecSignalDict_Check(b)) {
		if (signaldict_update(b) < 0) {
			return NULL;
		}
	}
	return PyDict_Type.tp_richcompare(a, b, op);
}

static int
signaldict_contains(PyObject *self, PyObject *key)
{
	if (signaldict_update(self) < 0) {
		return -1;
	}
	return PyDict_Contains(self, key);
}

static PyObject *
signaldict_copy(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Copy(self);
}

static PyObject *
signaldict_get(PyObject *self, PyObject *args)
{
	PyObject *key = NULL, *failobj = NULL;
	if (!PyArg_ParseTuple(args, "O|O", &key, &failobj)) {
		return NULL; /* GCOV_NOT_REACHED (why?) */
	}
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	if (failobj) {
		return PyObject_CallMethod((PyObject *)&PyDict_Type, "get",
		                           "OOO", self, key, failobj);
	}
	return PyObject_CallMethod((PyObject *)&PyDict_Type, "get",
	                           "OO", self, key);
}

static PyObject *
signaldict_has_key(PyObject *self, PyObject *key)
{
	int ret;
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	ret = PyDict_Contains(self, key);
	return ret < 0 ? NULL : PyBool_FromLong(ret);
}

static PyObject *
signaldict_items(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Items(self);
}

static PyObject *
signaldict_iter(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Type.tp_iter(self);
}

static PyObject *
signaldict_keys(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Keys(self);
}

static Py_ssize_t
signaldict_length(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return -1;
	}
	return PyDict_Type.tp_as_mapping->mp_length(self);
}

static int
signaldict_print(PyObject *self, FILE *fp, int flags) /* GCOV_NOT_REACHED */
{
	if (signaldict_update(self) < 0) { /* GCOV_NOT_REACHED */
		return -1; /* GCOV_NOT_REACHED */
	}
	return PyDict_Type.tp_print(self, fp, flags); /* GCOV_NOT_REACHED */
}

static PyObject *
signaldict_repr(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Type.tp_repr(self);
}

static PyObject *
signaldict_sizeof(PyObject *self)
{
	return signaldict_call_unary(self, "__sizeof__");
}

static int
signaldict_ass_sub(PyObject *self, PyObject *v, PyObject *w)
{
	if (w == NULL) {
		return value_error_int("signal keys cannot be deleted.");
	}
	else {
		return signaldict_setitem(self, v, w);
	}
}

static PyObject *
signaldict_subscript(PyObject *self, PyObject *key)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Type.tp_as_mapping->mp_subscript(self, key);
}

static PyObject *
signaldict_values(PyObject *self)
{
	if (signaldict_update(self) < 0) {
		return NULL;
	}
	return PyDict_Values(self);
}


static PyMappingMethods signaldict_as_mapping = {
	(lenfunc)signaldict_length,        /*mp_length*/
	(binaryfunc)signaldict_subscript,  /*mp_subscript*/
	(objobjargproc)signaldict_ass_sub  /*mp_ass_subscript*/
};

static PySequenceMethods signaldict_as_sequence = {
	0,                      /* sq_length */
	0,                      /* sq_concat */
	0,                      /* sq_repeat */
	0,                      /* sq_item */
	0,                      /* sq_slice */
	0,                      /* sq_ass_item */
	0,                      /* sq_ass_slice */
	signaldict_contains,    /* sq_contains */
	0,                      /* sq_inplace_concat */
	0,                      /* sq_inplace_repeat */
};

static PyMethodDef mapp_methods[] = {
  {"__contains__", (PyCFunction)signaldict_contains,   METH_O|METH_COEXIST, NULL},
  {"__getitem__",  (PyCFunction)signaldict_subscript,  METH_O|METH_COEXIST, NULL},
  {"__sizeof__",   (PyCFunction)signaldict_sizeof,     METH_NOARGS,         NULL},
  {"has_key",      (PyCFunction)signaldict_has_key,    METH_O,              NULL},
  {"get",          (PyCFunction)signaldict_get,        METH_VARARGS,        NULL},
  {"keys",         (PyCFunction)signaldict_keys,       METH_NOARGS,         NULL},
  {"items",        (PyCFunction)signaldict_items,      METH_NOARGS,         NULL},
  {"values",       (PyCFunction)signaldict_values,     METH_NOARGS,         NULL},
  {"copy",         (PyCFunction)signaldict_copy,       METH_NOARGS,         NULL},
  {NULL, NULL}
};

static PyTypeObject PyDecSignalDict_Type =
{
	PyVarObject_HEAD_INIT(0, 0)
	"cdecimal.SignalDict",                    /* tp_name */
	sizeof(PyDecSignalDictObject),            /* tp_basicsize */
	0,                                        /* tp_itemsize */
	0,                                        /* tp_dealloc */
	(printfunc)signaldict_print,              /* tp_print */
	(getattrfunc) 0,                          /* tp_getattr */
	(setattrfunc) 0,                          /* tp_setattr */
	0,                                        /* tp_reserved */
	(reprfunc) signaldict_repr,               /* tp_repr */
	0,                                        /* tp_as_number */
	&signaldict_as_sequence,                  /* tp_as_sequence */
	&signaldict_as_mapping,                   /* tp_as_mapping */
	(hashfunc) PyObject_HashNotImplemented,   /* tp_hash */
	0,                                        /* tp_call */
	(reprfunc) 0,                             /* tp_str */
	(getattrofunc) PyObject_GenericGetAttr,   /* tp_getattro */
	(setattrofunc) 0,                         /* tp_setattro */
	(PyBufferProcs *) 0,                      /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,                       /* tp_flags */
	0,                                        /* tp_doc */
	0,                                        /* tp_traverse */
	0,                                        /* tp_clear */
	signaldict_richcompare,                   /* tp_richcompare */
	0,                                        /* tp_weaklistoffset */
	(getiterfunc)signaldict_iter,             /* tp_iter */
	0,                                        /* tp_iternext */
	mapp_methods,                             /* tp_methods */
	0,                                        /* tp_members */
	0,                                        /* tp_getset */
	0,                                        /* tp_base */
	0,                                        /* tp_dict */
	0,                                        /* tp_descr_get */
	0,                                        /* tp_descr_set */
	0,                                        /* tp_dictoffset */
	(initproc)signaldict_init,                /* tp_init */
};


/******************************************************************************/
/*                         Context Object, Part 1                             */
/******************************************************************************/

static PyObject *
context_getprec(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue(CONV_mpd_ssize_t, mpd_getprec(ctx));
}

static PyObject *
context_getemax(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue(CONV_mpd_ssize_t, mpd_getemax(ctx));
}

static PyObject *
context_getemin(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue(CONV_mpd_ssize_t, mpd_getemin(ctx));
}

static PyObject *
context_getetiny(PyObject *self, PyObject *dummy UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue(CONV_mpd_ssize_t, mpd_etiny(ctx));
}

static PyObject *
context_getetop(PyObject *self, PyObject *dummy UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue(CONV_mpd_ssize_t, mpd_etop(ctx));
}

static PyObject *
context_getround(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue("i", mpd_getround(ctx));
}

static PyObject *
context_getcapitals(PyObject *self, void *closure UNUSED)
{
	return Py_BuildValue("i", CtxCaps(self));
}

static PyObject *
context_gettraps(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue("i", mpd_gettraps(ctx));
}

static PyObject *
context_getstatus(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue("i", mpd_getstatus(ctx));
}

static PyObject *
context_getclamp(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue("i", mpd_getclamp(ctx));
}

static PyObject *
context_getallcr(PyObject *self, void *closure UNUSED)
{
	mpd_context_t *ctx;

	ctx = CTX(self);
	return Py_BuildValue("i", mpd_getcr(ctx));
}

static int
context_setprec(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetprec(ctx, x)) {
		return value_error_int(
		    "valid range for prec is [1, MAX_PREC].");
	}

	return 0;
}

static int
context_setemin(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetemin(ctx, x)) {
		return value_error_int(
		    "valid range for Emin is [MIN_EMIN, 0].");
	}

	return 0;
}

static int
context_setemax(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetemax(ctx, x)) {
		return value_error_int(
		    "valid range for Emax is [0, MAX_EMAX].");
	}

	return 0;
}

static PyObject *
context_unsafe_setprec(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx = CTX(self);
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return NULL;
	}

	ctx->prec = x;
	Py_RETURN_NONE;
}

static PyObject *
context_unsafe_setemin(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx = CTX(self);
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return NULL;
	}

	ctx->emin = x;
	Py_RETURN_NONE;
}

static PyObject *
context_unsafe_setemax(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx = CTX(self);
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return NULL;
	}

	ctx->emax = x;
	Py_RETURN_NONE;
}

static int
context_setround(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}
	BOUNDS_CHECK(x, INT_MIN, INT_MAX);

	ctx = CTX(self);
	if (!mpd_qsetround(ctx, (int)x)) {
		return type_error_int(invalid_rounding_err);
	}

	return 0;
}

static int
context_setcapitals(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}
	BOUNDS_CHECK(x, INT_MIN, INT_MAX);

	if (x != 0 && x != 1) {
		return value_error_int(
		    "valid values for capitals are 0 or 1.");
	}
	CtxCaps(self) = (int)x;

	return 0;
}

static int
context_settraps(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = long_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsettraps(ctx, flags)) {
		INTERNAL_ERROR_INT("context_settraps");
	}

	return 0;
}

static int
context_settraps_list(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = list_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsettraps(ctx, flags)) {
		INTERNAL_ERROR_INT("context_settraps_list");
	}

	return 0;
}

static int
context_settraps_dict(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = dict_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsettraps(ctx, flags)) {
		INTERNAL_ERROR_INT("context_settraps_dict");
	}

	return 0;
}

static int
context_setstatus(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = long_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetstatus(ctx, flags)) {
		INTERNAL_ERROR_INT("context_setstatus");
	}

	return 0;
}

static int
context_setstatus_list(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = list_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetstatus(ctx, flags)) {
		INTERNAL_ERROR_INT("context_setstatus_list");
	}

	return 0;
}

static int
context_setstatus_dict(PyObject *self, PyObject *value)
{
	mpd_context_t *ctx;
	uint32_t flags;

	flags = dict_as_flags(value);
	if (flags == UINT32_MAX) {
		return -1;
	}

	ctx = CTX(self);
	if (!mpd_qsetstatus(ctx, flags)) {
		INTERNAL_ERROR_INT("context_setstatus_dict");
	}

	return 0;
}

static int
context_setclamp(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}
	BOUNDS_CHECK(x, INT_MIN, INT_MAX);

	ctx = CTX(self);
	if (!mpd_qsetclamp(ctx, (int)x)) {
		return value_error_int("valid values for clamp are 0 or 1.");
	}

	return 0;
}

static int
context_setallcr(PyObject *self, PyObject *value, void *closure UNUSED)
{
	mpd_context_t *ctx;
	mpd_ssize_t x;

	x = long_as_mpd_ssize(value);
	if (PyErr_Occurred()) {
		return -1;
	}
	BOUNDS_CHECK(x, INT_MIN, INT_MAX);

	ctx = CTX(self);
	if (!mpd_qsetcr(ctx, (int)x)) {
		return value_error_int("valid values for _allcr are 0 or 1.");
	}

	return 0;
}

static PyObject *
context_getattr(PyObject *self, PyObject *name)
{
	PyObject *retval;

	if (!PyUnicode_Check(name)) {
		PyErr_Format(PyExc_TypeError, /* GCOV_NOT_REACHED (why?) */
		             "attribute name must be string, not '%.200s'",
		             name->ob_type->tp_name); /* GCOV_NOT_REACHED */
		return NULL; /* GCOV_NOT_REACHED */
	}

	if (PyUnicode_CompareWithASCIIString(name, "traps") == 0) {
		retval = ((PyDecContextObject *)self)->traps;
		Py_INCREF(retval);
		return retval;
	}
	else if (PyUnicode_CompareWithASCIIString(name, "flags") == 0) {
		retval = ((PyDecContextObject *)self)->flags;
		Py_INCREF(retval);
		return retval;
	}
	else {
		return PyObject_GenericGetAttr(self, name);
	}
}

static int
context_setattr(PyObject *self, PyObject *name, PyObject *value)
{
	if (!PyUnicode_Check(name)) {
		PyErr_Format(PyExc_TypeError, /* GCOV_NOT_REACHED (why?) */
		             "attribute name must be string, not '%.200s'",
		             name->ob_type->tp_name); /* GCOV_NOT_REACHED */
		return -1; /* GCOV_NOT_REACHED */
	}
	if (value == NULL) {
		PyErr_SetString(PyExc_AttributeError,
		    "context attributes cannot be deleted.");
		return -1;
	}

	if (PyUnicode_CompareWithASCIIString(name, "traps") == 0) {
		return context_settraps_dict(self, value);
	}
	else if (PyUnicode_CompareWithASCIIString(name, "flags") == 0) {
		return context_setstatus_dict(self, value);
	}
	else {
		return PyObject_GenericSetAttr(self, name, value);
	}
}

static PyObject *
context_clear_traps(PyObject *self, PyObject *dummy UNUSED)
{
	PyDecContextObject *decctx = (PyDecContextObject *)self;

	if (signaldict_clear_all(decctx->traps) < 0) {
		return NULL;
	}
	Py_RETURN_NONE;
}

static PyObject *
context_clear_flags(PyObject *self, PyObject *dummy UNUSED)
{
	PyDecContextObject *decctx = (PyDecContextObject *)self;

	if (signaldict_clear_all(decctx->flags) < 0) {
		return NULL;
	}
	Py_RETURN_NONE;
}

static PyObject *
context_new(PyTypeObject *type UNUSED, PyObject *args UNUSED,
            PyObject *kwds UNUSED)
{
	PyDecContextObject *self = NULL;
	mpd_context_t *ctx;

	self = PyObject_New(PyDecContextObject, &PyDecContext_Type);
	if (self == NULL) {
		return NULL;
	}

	self->traps = PyObject_CallObject((PyObject *)&PyDecSignalDict_Type, NULL);
	if (self->traps == NULL) {
		self->flags = NULL;
		Py_DECREF(self);
		return NULL;
	}
	self->flags = PyObject_CallObject((PyObject *)&PyDecSignalDict_Type, NULL);
	if (self->flags == NULL) {
		Py_DECREF(self);
		return NULL;
	}

	ctx = CTX(self);
	SdFlagAddr(self->traps) = &ctx->traps;
	SdFlagAddr(self->flags) = &ctx->status;

	return (PyObject *)self;
}

static void
context_dealloc(PyDecContextObject *self)
{
	Py_XDECREF(self->traps);
	Py_XDECREF(self->flags);
	PyObject_Del(self);
}

#ifdef CONFIG_64
  #define DEC_DFLT_EMAX 999999999
  #define DEC_DFLT_EMIN -999999999
#else
  #define DEC_DFLT_EMAX MPD_MAX_EMAX
  #define DEC_DFLT_EMIN MPD_MIN_EMIN
#endif

static mpd_context_t dflt_ctx = {
  28, DEC_DFLT_EMAX, DEC_DFLT_EMIN,
  MPD_IEEE_Invalid_operation|MPD_Division_by_zero|MPD_Overflow,
  0, 0, MPD_ROUND_HALF_EVEN, 0, 1
};

static int
getround(PyObject *v)
{
	const char *s;
	long x;
	int i;

	if (PyLong_Check(v)) {
		x = PyLong_AsLong(v);
		if (PyErr_Occurred()) {
			return -1;
		}
		BOUNDS_CHECK(x, 0, INT_MAX);
		return (int)x;
	}
	else if (PyUnicode_Check(v)) {
		for (i = 0; i < MPD_ROUND_GUARD; i++) {
			s = mpd_round_string[i];
			if (PyUnicode_CompareWithASCIIString(v, s) == 0) {
				return i;
			}
		}
	}

	return type_error_int("invalid rounding mode.");
}

static int
context_init(PyObject *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = {
	  "prec", "rounding", "Emin", "Emax", "capitals", "clamp",
	  "flags", "traps", "_allcr", NULL
	};
	PyObject *rounding = NULL;
	PyObject *traps = NULL;
	PyObject *status = NULL;
	mpd_context_t *ctx, t=dflt_ctx;
	int capitals = 1;
	int ret;

	assert(PyTuple_Check(args));
	ctx = CTX(self);

	if (default_context_template) {
		t = *CTX(default_context_template);
	}
	if (!PyArg_ParseTupleAndKeywords(
	        args, kwds,
	        "|" CONV_mpd_ssize_t "O" CONV_mpd_ssize_t CONV_mpd_ssize_t "ii"
	        "OOi", kwlist,
	        &t.prec, &rounding, &t.emin, &t.emax, &capitals, &t.clamp,
	        &status, &traps, &t.allcr
	     )) {
		return -1;
	}
	if (rounding != NULL) {
		if ((t.round = getround(rounding)) < 0) {
			return -1;
		}
	}

	if (!mpd_qsetprec(ctx, t.prec) ||
	    !mpd_qsetemin(ctx, t.emin) ||
	    !mpd_qsetemax(ctx, t.emax) ||
	    !mpd_qsetclamp(ctx, t.clamp) ||
	    !mpd_qsetcr(ctx, t.allcr)) {
		return value_error_int("invalid context.");
	}
	if (!mpd_qsetround(ctx, t.round) ||
	    !mpd_qsettraps(ctx, t.traps) ||
	    !mpd_qsetstatus(ctx, t.status)) {
		return type_error_int("invalid context.");
	}

	if (capitals != 0 && capitals != 1) {
		return value_error_int("invalid context.");
	}
	CtxCaps(self) = capitals;

	if (traps != NULL) {
		if (PyLong_Check(traps)) {
			ret = context_settraps(self, traps, NULL);
		}
		else if (PyList_Check(traps)) {
			ret = context_settraps_list(self, traps);
		}
		else {
			ret = context_settraps_dict(self, traps);
		}
		if (ret < 0) {
			return ret;
		}
	}
	if (status != NULL) {
		if (PyLong_Check(status)) {
			ret = context_setstatus(self, status, NULL);
		}
		else if (PyList_Check(status)) {
			ret = context_setstatus_list(self, status);
		}
		else {
			ret = context_setstatus_dict(self, status);
		}
		if (ret < 0) {
			return ret;
		}
	}

	return 0;
}

#define FD_CTX_LEN 432
static PyObject *
context_repr(PyDecContextObject *self)
{
	mpd_context_t *ctx;
	char s[FD_CTX_LEN];
	char *cp;
	int n, mem;

	assert(PyDecContext_Check(self));
	ctx = CTX(self);

	cp = s; mem = FD_CTX_LEN;
	n = snprintf(cp, mem,
	             "Context(prec=%"PRI_mpd_ssize_t", rounding=%s, "
	             "Emin=%"PRI_mpd_ssize_t", Emax=%"PRI_mpd_ssize_t", "
	             "capitals=%d, clamp=%d, flags=",
	             ctx->prec, mpd_round_string[ctx->round],
	             ctx->emin, ctx->emax,
	             self->capitals, ctx->clamp);
	if (n < 0 || n >= mem) goto error;
	cp += n; mem -= n;

	n = mpd_lsnprint_signals(cp, mem, ctx->status, dec_signal_string);
	if (n < 0 || n >= mem) goto error;
	cp += n; mem -= n;

	n = snprintf(cp, mem, ", traps=");
	if (n < 0 || n >= mem) goto error;
	cp += n; mem -= n;

	n = mpd_lsnprint_signals(cp, mem, ctx->traps, dec_signal_string);
	if (n < 0 || n >= mem) goto error;
	cp += n; mem -= n;

	n = snprintf(cp, mem, ")");
	if (n < 0 || n >= mem) goto error;

	return PyUnicode_FromString(s);

error:
	INTERNAL_ERROR_PTR("context_repr");
}

static void
init_basic_context(PyObject *v)
{
	mpd_context_t ctx = dflt_ctx;

	ctx.prec = 9;
	ctx.traps |= (MPD_Underflow|MPD_Clamped);
	ctx.round = MPD_ROUND_HALF_UP;

	*CTX(v) = ctx;
	CtxCaps(v) = 1;
}

static void
init_extended_context(PyObject *v)
{
	mpd_context_t ctx = dflt_ctx;

	ctx.prec = 9;
	ctx.traps = 0;

	*CTX(v) = ctx;
	CtxCaps(v) = 1;
}

/* Factory function for creating IEEE interchange format contexts */
static PyObject *
ieee_context(PyObject *dummy UNUSED, PyObject *v)
{
	PyObject *context;
	mpd_ssize_t bits;
	mpd_context_t ctx;

	bits = long_as_mpd_ssize(v);
	if (PyErr_Occurred()) {
		return NULL;
	}
	if (bits <= 0 || bits > INT_MAX) {
		goto error;
	}
	if (mpd_ieee_context(&ctx, (int)bits) < 0) {
		goto error;
	}

	context = PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL);
	if (context == NULL) {
		return NULL;
	}
	*CTX(context) = ctx;

	return context;

error:
	PyErr_Format(PyExc_ValueError,
	    "argument must be a multiple of 32, with a maximum of %d.",
	    MPD_IEEE_CONTEXT_MAX_BITS);

	return NULL;
}

static PyObject *
context_copy(PyObject *self)
{
	PyObject *copy;

	copy = PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL);
	if (copy == NULL) {
		return NULL;
	}

	*CTX(copy) = *CTX(self);
	CTX(copy)->newtrap = 0;
	CtxCaps(copy) = CtxCaps(self);

	return copy;
}

static PyObject *
context_reduce(PyObject *self, PyObject *args UNUSED)
{
	PyObject *flags;
	PyObject *traps;
	PyObject *ret;
	mpd_context_t *ctx;

	ctx = CTX(self);

	if ((flags = signals_as_list(ctx->status)) == NULL) {
		return NULL;
	}
	if ((traps = signals_as_list(ctx->traps)) == NULL) {
		Py_DECREF(flags);
		return NULL;
	}

	ret = Py_BuildValue(
	        "O(" CONV_mpd_ssize_t "s" CONV_mpd_ssize_t CONV_mpd_ssize_t
	        "iiOO)",
	        Py_TYPE(self),
	        ctx->prec, mpd_round_string[ctx->round], ctx->emin, ctx->emax,
	        CtxCaps(self), ctx->clamp, flags, traps
	);

	Py_DECREF(flags);
	Py_DECREF(traps);
	return ret;
}

static PyObject *
PyDec_SetStatusFromList(PyObject *self, PyObject *value)
{
	if (context_setstatus_list(self, value) < 0) {
		return NULL;
	}
	Py_RETURN_NONE;
}

static PyObject *
PyDec_SetTrapsFromList(PyObject *self, PyObject *value)
{
	if (context_settraps_list(self, value) < 0) {
		return NULL;
	}
	Py_RETURN_NONE;
}


static PyGetSetDef context_getsets [] =
{
  { "prec", (getter)context_getprec, (setter)context_setprec, NULL, NULL},
  { "Emax", (getter)context_getemax, (setter)context_setemax, NULL, NULL},
  { "Emin", (getter)context_getemin, (setter)context_setemin, NULL, NULL},
  { "rounding", (getter)context_getround, (setter)context_setround, NULL, NULL},
  { "capitals", (getter)context_getcapitals, (setter)context_setcapitals, NULL, NULL},
  { "clamp", (getter)context_getclamp, (setter)context_setclamp, NULL, NULL},
  { "_clamp", (getter)context_getclamp, (setter)context_setclamp, NULL, NULL},
  { "_allcr", (getter)context_getallcr, (setter)context_setallcr, NULL, NULL},
  { "_traps", (getter)context_gettraps, (setter)context_settraps, NULL, NULL},
  { "_flags", (getter)context_getstatus, (setter)context_setstatus, NULL, NULL},
  {NULL}
};


#define CONTEXT_CHECK(obj) \
        if (!PyDecContext_Check(obj)) {             \
                PyErr_SetString(PyExc_TypeError,    \
                    "argument must be a context."); \
                return NULL;                        \
        }

#define CONTEXT_CHECK_VA(obj) \
        if (!PyDecContext_Check(obj)) {                      \
                PyErr_SetString(PyExc_TypeError,             \
                    "optional argument must be a context."); \
                return NULL;                                 \
        }


/******************************************************************************/
/*                Global, thread local and temporary contexts                 */
/******************************************************************************/

#ifdef WITHOUT_THREADS
/* Return borrowed reference to the current context. When compiled
 * without threads, this is always the module context. */
static int module_context_set = 0;
static PyObject *
current_context(void)
{
	/* In decimal.py, the module context is automatically initialized
	 * from the DefaultContext when it is first accessed. This
	 * complicates the code and has a speed penalty of 1-2%. */
	if (module_context_set) {
		return module_context;
	}

	*CTX(module_context) = *CTX(default_context_template);
	module_context_set = 1;
	return module_context;
}

/* ctxobj := borrowed reference to the current context */
#define CURRENT_CONTEXT(ctxobj) \
        ctxobj = current_context()

/* ctx := pointer to the mpd_context_t struct of the current context */
#define CURRENT_CONTEXT_ADDR(ctx) \
        ctx = CTX(current_context())

/* Return current context, increment reference */
static PyObject *
PyDec_GetCurrentContext(void)
{
	PyObject *context;

	CURRENT_CONTEXT(context);

	Py_INCREF(context);
	return context;
}

/* Set the module context to a new context, decrement old reference */
static PyObject *
PyDec_SetCurrentContext(PyObject *self UNUSED, PyObject *v)
{
	CONTEXT_CHECK(v);

	/* If the new context is one of the templates, make a copy.
	 * This is the current behavior of decimal.py. */
	if (v == default_context_template ||
	    v == basic_context_template ||
	    v == extended_context_template) {
		if ((v = context_copy(v)) == NULL) {
			return NULL;
		}
	}
	else {
		Py_INCREF(v);
	}

	Py_XDECREF(module_context);
	module_context = v;
	module_context_set = 1;
	Py_RETURN_NONE;
}
#else
/*
 * Thread local storage currently has a speed penalty of about 16%.
 * All functions that map Python's arithmetic operators to mpdecimal
 * functions have to look up the current context for each and every
 * operation.
 */

/* Return borrowed reference to thread local context. */
static PyObject *
current_context(void)
{
	PyObject *dict = NULL;
	PyObject *tl_context = NULL;

	dict = PyThreadState_GetDict();
	if (dict == NULL) {
		PyErr_SetString(PyExc_RuntimeError,
		    "cannot get thread state.");
		return NULL;
	}

	tl_context = PyDict_GetItemWithError(dict, tls_context_key);
	if (tl_context != NULL) {
		/* We already have a thread local context and
		 * return a borrowed reference. */
		CONTEXT_CHECK(tl_context);
		return tl_context;
	}
	if (PyErr_Occurred()) {
		return NULL;
	}

	/* Otherwise, set up a new thread local context. */
	tl_context = context_copy(default_context_template);
	if (tl_context == NULL) {
		return NULL;
	}
	if (PyDict_SetItem(dict, tls_context_key, tl_context) < 0) {
		Py_DECREF(tl_context);
		return NULL;
	}
	Py_DECREF(tl_context);

	/* refcount is 1 */
	return tl_context;
}

/* ctxobj := borrowed reference to the current context */
#define CURRENT_CONTEXT(ctxobj) \
        if ((ctxobj = current_context()) == NULL) { \
                return NULL;                        \
        }

/* ctx := pointer to the mpd_context_t struct of the current context */
#define CURRENT_CONTEXT_ADDR(ctx) { \
        PyObject *_c_t_x_o_b_j = current_context(); \
        if (_c_t_x_o_b_j == NULL) {                 \
                return NULL;                        \
        }                                           \
        ctx = CTX(_c_t_x_o_b_j);                    \
}

/* Return current context, increment reference */
static PyObject *
PyDec_GetCurrentContext(void)
{
	PyObject *obj;

	if ((obj = current_context()) == NULL) {
		return NULL;
	}

	Py_INCREF(obj);
	return obj;
}

/* Set the thread local context to a new context, decrement old reference */
static PyObject *
PyDec_SetCurrentContext(PyObject *self UNUSED, PyObject *v)
{
	PyObject *dict;

	CONTEXT_CHECK(v);

	dict = PyThreadState_GetDict();
	if (dict == NULL) {
		PyErr_SetString(PyExc_RuntimeError,
		    "cannot get thread state.");
		return NULL;
	}

	/* If the new context is one of the templates, make a copy.
	 * This is the current behavior of decimal.py. */
	if (v == default_context_template ||
	    v == basic_context_template ||
	    v == extended_context_template) {
		if ((v = context_copy(v)) == NULL) {
			return NULL;
		}
	}
	else {
		Py_INCREF(v);
	}

	if (PyDict_SetItem(dict, tls_context_key, v) < 0) {
		Py_DECREF(v);
		return NULL;
	}

	Py_DECREF(v);
	Py_RETURN_NONE;
}
#endif

/* Context manager object for the 'with' statement. The manager
 * owns one reference to the global (outer) context and one
 * to the local (inner) context. */
static PyObject *
ctxmanager_new(PyTypeObject *type UNUSED, PyObject *args)
{
	PyDecContextManagerObject *self;
	PyObject *local;
	PyObject *global;

	CURRENT_CONTEXT(global);
	local = global;
	if (!PyArg_ParseTuple(args, "|O", &local)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(local);

	self = PyObject_New(PyDecContextManagerObject,
	                    &PyDecContextManager_Type);
	if (self == NULL) {
		return NULL;
	}

	self->local = context_copy(local);
	if (self->local == NULL) {
		self->global = NULL;
		Py_DECREF(self);
		return NULL;
	}
	self->global = global;
	Py_INCREF(self->global);

	return (PyObject *)self;
}

static void
ctxmanager_dealloc(PyDecContextManagerObject *self)
{
	Py_XDECREF(self->local);
	Py_XDECREF(self->global);
	PyObject_Del(self);
}

static PyObject *
ctxmanager_set_local(PyDecContextManagerObject *self, PyObject *args UNUSED)
{
	PyObject *ret;

	ret = PyDec_SetCurrentContext(NULL, self->local);
	if (ret == NULL) {
		return NULL;
	}
	Py_DECREF(ret);

	Py_INCREF(self->local);
	return self->local;
}

static PyObject *
ctxmanager_restore_global(PyDecContextManagerObject *self,
                          PyObject *args UNUSED)
{
	PyObject *ret;

	ret = PyDec_SetCurrentContext(NULL, self->global);
	if (ret == NULL) {
		return NULL;
	}
	Py_DECREF(ret);

	Py_RETURN_NONE;
}


static PyMethodDef ctxmanager_methods[] = {
  {"__enter__", (PyCFunction)ctxmanager_set_local, METH_NOARGS, NULL},
  {"__exit__", (PyCFunction)ctxmanager_restore_global, METH_VARARGS, NULL},
  {NULL, NULL}
};

static PyTypeObject PyDecContextManager_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"cdecimal.ContextManager",              /* tp_name */
	sizeof(PyDecContextManagerObject),      /* tp_basicsize */
	0,                                      /* tp_itemsize */
	(destructor) ctxmanager_dealloc,        /* tp_dealloc */
	0,                                      /* tp_print */
	(getattrfunc) 0,                        /* tp_getattr */
	(setattrfunc) 0,                        /* tp_setattr */
	0,                                      /* tp_compare */
	(reprfunc) 0,                           /* tp_repr */
	0,                                      /* tp_as_number */
	0,                                      /* tp_as_sequence */
	0,                                      /* tp_as_mapping */
	0,                                      /* tp_hash */
	0,                                      /* tp_call */
	0,                                      /* tp_str */
	(getattrofunc) PyObject_GenericGetAttr, /* tp_getattro */
	(setattrofunc) 0,                       /* tp_setattro */
	(PyBufferProcs *) 0,                    /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,                     /* tp_flags */
	0,                                      /* tp_doc */
	0,                                      /* tp_traverse */
	0,                                      /* tp_clear */
	0,                                      /* tp_richcompare */
	0,                                      /* tp_weaklistoffset */
	0,                                      /* tp_iter */
	0,                                      /* tp_iternext */
	ctxmanager_methods,                     /* tp_methods */
};


/******************************************************************************/
/*                           New Decimal Object                               */
/******************************************************************************/

static PyObject *
PyDecType_New(PyTypeObject *type)
{
	PyObject *dec;

	if (type == &PyDec_Type) {
		dec = (PyObject *)PyObject_New(PyDecObject, &PyDec_Type);
	}
	else {
		dec = type->tp_alloc(type, 0);
	}
	if (dec == NULL) {
		return NULL;
	}

	MPD(dec) = mpd_qnew();
	if (MPD(dec) == NULL) {
		Py_DECREF(dec);
		PyErr_NoMemory();
		return NULL;
	}

	return dec;
}
#define dec_alloc() PyDecType_New(&PyDec_Type)

static void
dec_dealloc(PyObject *dec)
{
	if (MPD(dec)) {
		mpd_del(MPD(dec));
	}
	Py_TYPE(dec)->tp_free(dec);
}


/******************************************************************************/
/*                           Conversions to Decimal                           */
/******************************************************************************/

/* Return a new PyDecObject or a subtype from a C string. Use the context
   during conversion. */
static PyObject *
PyDecType_FromCString(PyTypeObject *type, const char *s,
                      PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;

	dec = PyDecType_New(type);
	if (dec == NULL) {
		return NULL;
	}

	mpd_qset_string(MPD(dec), s, CTX(context), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}
	return dec;
}

/* Return a new PyDecObject or a subtype from a C string. Attempt exact
   conversion. If the operand cannot be converted exactly, set
   InvalidOperation. */
static PyObject *
PyDecType_FromCStringExact(PyTypeObject *type, const char *s,
                           PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;
	mpd_context_t maxctx;

	dec = PyDecType_New(type);
	if (dec == NULL) {
		return NULL;
	}

	mpd_maxcontext(&maxctx);

	mpd_qset_string(MPD(dec), s, &maxctx, &status);
	if (status & (MPD_Inexact|MPD_Rounded)) {
		/* we want exact results */
		mpd_seterror(MPD(dec), MPD_Invalid_operation, &status);
	}
	status &= MPD_Errors;
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}

	return dec;
}

/* Wrap PyUnicode_EncodeDecimal. */
static char *
dec_unicode_as_str(const PyObject *u)
{
	char *s;

	s = PyMem_Malloc(PyUnicode_GET_SIZE(u)+1);
	if (s == NULL) {
		PyErr_NoMemory();
		return NULL;
	}
	if (PyUnicode_EncodeDecimal(PyUnicode_AS_UNICODE(u),
	                            PyUnicode_GET_SIZE(u),
	                            s, NULL)) {
		PyMem_Free(s);
		return NULL;
	}

	return s;
}

/* Strip leading and trailing whitespace. Return x unchanged if no
   whitespace is found, otherwise return a newly allocated string
   with whitespace stripped. */
static char *
strip_ws(const char *x)
{
	char *s, *t;
	char *y;
	size_t n;

	s = (char *)x;
	while (isspace((unsigned char)*s))
		s++;

	t = y = s+strlen(s);
	while (t > s && isspace((unsigned char)*(t-1)))
		t--;

	if (s != x || t != y) {
		n = t-s;
		if ((y = PyMem_Malloc(n+1)) == NULL) {
			PyErr_NoMemory();
			return NULL;
		}
		strncpy(y, s, n);
		y[n] = '\0';
		return y;
	}

	return (char *)x;
}

/* Return a new PyDecObject or a subtype from a PyUnicodeObject. */
static PyObject *
PyDecType_FromUnicode(PyTypeObject *type, const PyObject *u,
                      PyObject *context)
{
	PyObject *dec;
	char *s;

	s = dec_unicode_as_str(u);
	if (s == NULL) {
		return NULL;
	}

	dec = PyDecType_FromCString(type, s, context);
	PyMem_Free(s);
	return dec;
}

/* Return a new PyDecObject or a subtype from a PyUnicodeObject. Attempt exact
 * conversion. If the conversion is not exact, fail with InvalidOperation.
 * Allow leading and trailing whitespace in the input operand. */
static PyObject *
PyDecType_FromUnicodeExactWS(PyTypeObject *type, const PyObject *u,
                             PyObject *context)
{
	PyObject *dec;
	char *s, *stripped;

	s = dec_unicode_as_str(u);
	if (s == NULL) {
		return NULL;
	}

	stripped = strip_ws(s);
	if (stripped == NULL) {
		PyMem_Free(s);
		return NULL;
	}

	dec = PyDecType_FromCStringExact(type, stripped, context);
	if (stripped != s) {
		PyMem_Free(stripped);
	}
	PyMem_Free(s);

	return dec;
}

/* Set PyDecObject from triple without any error checking. */
static ALWAYS_INLINE void
_dec_settriple(PyObject *dec, uint8_t sign, uint32_t v, mpd_ssize_t exp)
{

#ifdef CONFIG_64
	MPD(dec)->data[0] = v;
	MPD(dec)->len = 1;
#else
	uint32_t q, r;
	q = v / MPD_RADIX;
	r = v - q * MPD_RADIX;
	MPD(dec)->data[1] = q;
	MPD(dec)->data[0] = r;
	MPD(dec)->len = q ? 2 : 1;
#endif
	mpd_set_flags(MPD(dec), sign);
	MPD(dec)->exp = exp;
	mpd_setdigits(MPD(dec));
}

/* Return a new PyDecObject from an mpd_ssize_t. */
static PyObject *
PyDecType_FromSsize(PyTypeObject *type, mpd_ssize_t v, PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;

	dec = PyDecType_New(type);
	if (dec == NULL) {
		return NULL;
	}

	mpd_qset_ssize(MPD(dec), v, CTX(context), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}
	return dec;
}

/* Return a new PyDecObject from an mpd_ssize_t. Conversion is exact. */
static PyObject *
PyDecType_FromSsizeExact(PyTypeObject *type, mpd_ssize_t v, PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;
	mpd_context_t maxctx;

	dec = PyDecType_New(type);
	if (dec == NULL) {
		return NULL;
	}

	mpd_maxcontext(&maxctx);

	mpd_qset_ssize(MPD(dec), v, &maxctx, &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}
	return dec;
}

/* Convert from a PyLongObject. The context is not modified; flags set
   during conversion are accumulated in the status parameter. */
static PyObject *
dec_from_long(PyTypeObject *type, const PyObject *v,
              const mpd_context_t *ctx, uint32_t *status)
{
	PyObject *dec;
	PyLongObject *l = (PyLongObject *)v;
	Py_ssize_t ob_size;
	size_t len;
	uint8_t sign;

	dec = PyDecType_New(type);
	if (dec == NULL) {
		return NULL;
	}

	ob_size = Py_SIZE(l);
	if (ob_size == 0) {
		_dec_settriple(dec, MPD_POS, 0, 0);
		return dec;
	}

	if (ob_size < 0) {
		len = -ob_size;
		sign = MPD_NEG;
	}
	else {
		len = ob_size;
		sign = MPD_POS;
	}

	if (len == 1) {
		_dec_settriple(dec, sign, *l->ob_digit, 0);
		mpd_qfinalize(MPD(dec), ctx, status);
		return dec;
	}

#if PYLONG_BITS_IN_DIGIT == 30
	mpd_qimport_u32(MPD(dec), l->ob_digit, len, sign, PyLong_BASE,
	                ctx, status);
#elif PYLONG_BITS_IN_DIGIT == 15
	mpd_qimport_u16(MPD(dec), l->ob_digit, len, sign, PyLong_BASE,
	                ctx, status);
#else
  #error "PYLONG_BITS_IN_DIGIT should be 15 or 30."
#endif

	return dec;
}

/* Return a new PyDecObject from a PyLongObject. Use the context for
   conversion. */
static PyObject *
PyDecType_FromLong(PyTypeObject *type, const PyObject *pylong,
                   PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;

	dec = dec_from_long(type, pylong, CTX(context), &status);
	if (dec == NULL) {
		return NULL;
	}

	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}

	return dec;
}

/* Return a new PyDecObject from a PyLongObject. Use a maximum context
   for conversion. If the conversion is not exact, set InvalidOperation. */
static PyObject *
PyDecType_FromLongExact(PyTypeObject *type, const PyObject *pylong,
                        PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;
	mpd_context_t maxctx;

	mpd_maxcontext(&maxctx);
	dec = dec_from_long(type, pylong, &maxctx, &status);
	if (dec == NULL) {
		return NULL;
	}

	if (status & (MPD_Inexact|MPD_Rounded)) {
		/* we want exact results */
		mpd_seterror(MPD(dec), MPD_Invalid_operation, &status); /* GCOV_NOT_REACHED */
	}
	status &= MPD_Errors;
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}

	return dec;
}

/* Return a PyDecObject or a subtype from a PyFloatObject.
   Conversion is exact. */
static PyObject *
PyDecType_FromFloatExact(PyTypeObject *type, PyObject *v,
                         PyObject *context)
{
	PyObject *dec, *tmp;
	PyObject *n, *d, *n_d;
	mpd_ssize_t k;
	double x;
	int sign;
	mpd_t *d1, *d2;
	uint32_t status = 0;
	mpd_context_t maxctx;


	assert(PyType_IsSubtype(type, &PyDec_Type));

	if (PyLong_Check(v)) {
		return PyDecType_FromLongExact(type, v, context);
	}
	if (!PyFloat_Check(v)) {
		PyErr_SetString(PyExc_TypeError,
		    "argument must be int of float.");
		return NULL;
	}

	x = PyFloat_AsDouble(v);
	if (x == -1.0 && PyErr_Occurred()) {
		return NULL;
	}
	sign = (copysign(1.0, x) == 1.0) ? 0 : 1;

	if (Py_IS_NAN(x) || Py_IS_INFINITY(x)) {
		dec = PyDecType_New(type);
		if (dec == NULL) {
			return NULL;
		}
		if (Py_IS_NAN(x)) {
			/* decimal.py calls repr(float(+-nan)),
			 * which always gives a positive result. */
			mpd_setspecial(MPD(dec), MPD_POS, MPD_NAN);
		}
		else {
			mpd_setspecial(MPD(dec), sign, MPD_INF);
		}
		return dec;
	}

	/* absolute value of the float */
	tmp = PyObject_CallMethod(v, "__abs__", NULL);
	if (tmp == NULL) {
		return NULL;
	}

	/* float as integer ratio: numerator/denominator */
	n_d = PyObject_CallMethod(tmp, "as_integer_ratio", NULL);
	Py_DECREF(tmp);
	if (n_d == NULL) {
		return NULL;
	}
	n = PyTuple_GET_ITEM(n_d, 0);
	d = PyTuple_GET_ITEM(n_d, 1);

	tmp = PyObject_CallMethod(d, "bit_length", NULL);
	if (tmp == NULL) {
		Py_DECREF(n_d);
		return NULL;
	}
	k = long_as_mpd_ssize(tmp);
	Py_DECREF(tmp);
	if (k == MPD_SSIZE_MAX) {
		Py_DECREF(n_d);
		return NULL;
	}
	k--;

	dec = PyDecType_FromLongExact(type, n, context);
	Py_DECREF(n_d);
	if (dec == NULL) {
		return NULL;
	}

	d1 = mpd_qnew();
	if (d1 == NULL) {
		Py_DECREF(dec);
		PyErr_NoMemory();
		return NULL;
	}
	d2 = mpd_qnew();
	if (d2 == NULL) {
		mpd_del(d1);
		Py_DECREF(dec);
		PyErr_NoMemory();
		return NULL;
	}

	mpd_maxcontext(&maxctx);
	mpd_qset_uint(d1, 5, &maxctx, &status);
	mpd_qset_ssize(d2, k, &maxctx, &status);
	mpd_qpow(d1, d1, d2, &maxctx, &status);
	if (dec_addstatus(context, status)) {
		mpd_del(d1); /* GCOV_NOT_REACHED */
		mpd_del(d2); /* GCOV_NOT_REACHED */
		Py_DECREF(dec); /* GCOV_NOT_REACHED */
		return NULL; /* GCOV_NOT_REACHED */
	}

	/* result = n * 5**k */
	mpd_qmul(MPD(dec), MPD(dec), d1, &maxctx, &status);
	mpd_del(d1);
	mpd_del(d2);
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec); /* GCOV_NOT_REACHED */
		return NULL; /* GCOV_NOT_REACHED */
	}
	/* result = +- n * 5**k * 10**-k */
	mpd_set_sign(MPD(dec), sign);
	MPD(dec)->exp = -k;

	return dec;
}

static PyObject *
PyDecType_FromFloat(PyTypeObject *type, PyObject *v,
                    PyObject *context)
{
	PyObject *dec;
	uint32_t status = 0;

	dec = PyDecType_FromFloatExact(type, v, context);
	if (dec == NULL) {
		return NULL;
	}

	mpd_qfinalize(MPD(dec), CTX(context), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(dec);
		return NULL;
	}

	return dec;
}

/* Return a new C string representation of a DecimalTuple. */
static char *
dectuple_as_str(PyObject *dectuple)
{
	PyObject *digits, *tmp;
	char *decstring = NULL;
	char sign_special[6];
	char *cp;
	long sign, l;
	mpd_ssize_t exp = 0;
	Py_ssize_t i, mem, tsize;
	int n;

	assert(PyTuple_Check(dectuple));

	if (PyTuple_Size(dectuple) != 3) {
		PyErr_SetString(PyExc_ValueError,
		    "argument must be a sequence of length 3.");
		goto error;
	}

	/* sign */
	tmp = PyTuple_GET_ITEM(dectuple, 0);
	if (!PyLong_Check(tmp)) {
		PyErr_SetString(PyExc_ValueError,
		    "sign must be an integer with the value 0 or 1.");
		goto error;
	}
	sign = PyLong_AsLong(tmp);
	if (PyErr_Occurred()) {
		goto error;
	}
	if (sign != 0 && sign != 1) {
		PyErr_SetString(PyExc_ValueError,
		    "sign must be an integer with the value 0 or 1.");
		goto error;
	}
	sign_special[0] = sign ? '-' : '+';
	sign_special[1] = '\0';

	/* exponent or encoding for a special number */
	tmp = PyTuple_GET_ITEM(dectuple, 2);
	if (PyUnicode_Check(tmp)) {
		/* special */
		if (PyUnicode_CompareWithASCIIString(tmp, "F") == 0) {
			strcat(sign_special, "Inf");
		}
		else if (PyUnicode_CompareWithASCIIString(tmp, "n") == 0) {
			strcat(sign_special, "NaN");
		}
		else if (PyUnicode_CompareWithASCIIString(tmp, "N") == 0) {
			strcat(sign_special, "sNaN");
		}
		else {
			PyErr_SetString(PyExc_ValueError,
			    "string argument in the third position "
			    "must be 'F', 'n' or 'N'.");
			goto error;
		}
	}
	else {
		/* exponent */
		if (!PyLong_Check(tmp)) {
			PyErr_SetString(PyExc_ValueError,
			    "exponent must be an integer.");
			goto error;
		}
		exp = long_as_mpd_ssize(tmp);
		if (PyErr_Occurred()) {
			goto error;
		}
	}

	/* coefficient */
	digits = PyTuple_GET_ITEM(dectuple, 1);
	if (!PyTuple_Check(digits)) {
		PyErr_SetString(PyExc_ValueError,
		    "coefficient must be a tuple of digits.");
		goto error;
	}

	tsize = PyTuple_Size(digits);
	/* [sign][coeffdigits+1][E][-][expdigits+1]['\0'] */
	mem = 1 + tsize + 3 + MPD_EXPDIGITS + 2;
	cp = decstring = PyMem_Malloc(mem);
	if (decstring == NULL) {
		PyErr_NoMemory();
		goto error;
	}

	n = snprintf(cp, mem, "%s", sign_special);
	if (n < 0 || n >= mem) {
		PyErr_SetString(PyExc_RuntimeError,
		    "internal error in dec_sequence_as_str.");
		goto error;
	}
	cp += n;

	if (tsize == 0 && sign_special[1] == '\0') {
		/* empty tuple: zero coefficient, except for special numbers */
		*cp++ = '0';
	}
	for (i = 0; i < tsize; i++) {
		tmp = PyTuple_GET_ITEM(digits, i);
		if (!PyLong_Check(tmp)) {
			PyErr_SetString(PyExc_ValueError,
			    "coefficient must be a tuple of digits.");
			goto error;
		}
		l = PyLong_AsLong(tmp);
		if (PyErr_Occurred()) {
			goto error;
		}
		if (l < 0 || l > 9) {
			PyErr_SetString(PyExc_ValueError,
			    "coefficient must be a tuple of digits.");
			goto error;
		}
		*cp++ = (char)l + '0';
	}
	*cp = '\0';

	if (sign_special[1] == '\0') {
		/* not a special number */
		*cp++ = 'E';
		n = snprintf(cp, MPD_EXPDIGITS+1, "%" PRI_mpd_ssize_t, exp);
		if (n < 0 || n >= MPD_EXPDIGITS+1) {
			PyErr_SetString(PyExc_RuntimeError,
			    "internal error in dec_sequence_as_str.");
			goto error;
		}
	}

	return decstring;


error:
	if (decstring) PyMem_Free(decstring);
	return NULL;
}

static PyObject *
sequence_as_tuple(PyObject *v)
{
	if (PyTuple_Check(v)) {
		Py_INCREF(v);
		return v;
	}
	if (PyList_Check(v)) {
		return PyList_AsTuple(v);
	}

	return type_error_ptr("argument must be tuple or list."); /* GCOV_NOT_REACHED */
}

/* Currently accepts tuples and lists. */
static PyObject *
PyDecType_FromSequence(PyTypeObject *type, PyObject *v,
                       PyObject *context)
{
	PyObject *dectuple;
	PyObject *dec;
	char *s;

	dectuple = sequence_as_tuple(v);
	if (dectuple == NULL) {
		return NULL;
	}

	s = dectuple_as_str(dectuple);
	Py_DECREF(dectuple);
	if (s == NULL) {
		return NULL;
	}

	dec = PyDecType_FromCString(type, s, context);

	PyMem_Free(s);
	return dec;
}

/* Currently accepts tuples and lists. */
static PyObject *
PyDecType_FromSequenceExact(PyTypeObject *type, PyObject *v,
                            PyObject *context)
{
	PyObject *dectuple;
	PyObject *dec;
	char *s;

	dectuple = sequence_as_tuple(v);
	if (dectuple == NULL) {
		return NULL;
	}

	s = dectuple_as_str(dectuple);
	Py_DECREF(dectuple);
	if (s == NULL) {
		return NULL;
	}

	dec = PyDecType_FromCStringExact(type, s, context);

	PyMem_Free(s);
	return dec;
}

#define PyDec_FromCString(str, context) \
        PyDecType_FromCString(&PyDec_Type, str, context)
#define PyDec_FromCStringExact(str, context) \
        PyDecType_FromCStringExact(&PyDec_Type, str, context)

#define PyDec_FromUnicode(unicode, context) \
        PyDecType_FromUnicode(&PyDec_Type, unicode, context)
#define PyDec_FromUnicodeExact(unicode, context) \
        PyDecType_FromUnicodeExact(&PyDec_Type, unicode, context)
#define PyDec_FromUnicodeExactWS(unicode, context) \
        PyDecType_FromUnicodeExactWS(&PyDec_Type, unicode, context)

#define PyDec_FromSsize(v, context) \
        PyDecType_FromSsize(&PyDec_Type, v, context)
#define PyDec_FromSsizeExact(v, context) \
        PyDecType_FromSsizeExact(&PyDec_Type, v, context)

#define PyDec_FromLong(pylong, context) \
        PyDecType_FromLong(&PyDec_Type, pylong, context)
#define PyDec_FromLongExact(pylong, context) \
        PyDecType_FromLongExact(&PyDec_Type, pylong, context)

#define PyDec_FromFloat(pyfloat, context) \
        PyDecType_FromFloat(&PyDec_Type, pyfloat, context)
#define PyDec_FromFloatExact(pyfloat, context) \
        PyDecType_FromFloatExact(&PyDec_Type, pyfloat, context)

#define PyDec_FromSequence(sequence, context) \
        PyDecType_FromSequence(&PyDec_Type, sequence, context)
#define PyDec_FromSequenceExact(sequence, context) \
        PyDecType_FromSequenceExact(&PyDec_Type, sequence, context)

/* class method */
static PyObject *
dec_from_float(PyObject *dec, PyObject *pyfloat)
{
	PyObject *context;

	CURRENT_CONTEXT(context);
	return PyDecType_FromFloatExact((PyTypeObject *)dec, pyfloat, context);
}

/* create_decimal_from_float */
static PyObject *
ctx_from_float(PyObject *context, PyObject *v)
{
	return PyDec_FromFloat(v, context);
}

/* Apply the context to the input operand. Return a new PyDecObject. */
static PyObject *
dec_apply(PyObject *v, PyObject *context)
{
	PyObject *result;
	uint32_t status = 0;

	result = dec_alloc();
	if (result == NULL) {
		return NULL;
	}

	mpd_qcopy(MPD(result), MPD(v), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	mpd_qfinalize(MPD(result), CTX(context), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

/* 'v' can have any type accepted by the Decimal constructor. Attempt
   an exact conversion. If the result does not meet the restrictions
   for an mpd_t, fail with InvalidOperation. */
static PyObject *
PyDecType_FromObjectExact(PyTypeObject *type, PyObject *v, PyObject *context)
{
	if (v == NULL) {
		return PyDecType_FromSsizeExact(type, 0, context);
	}
	else if (PyDec_Check(v)) {
		Py_INCREF(v);
		return v;
	}
	else if (PyUnicode_Check(v)) {
		return PyDecType_FromUnicodeExactWS(type, v, context);
	}
	else if (PyLong_Check(v)) {
		return PyDecType_FromLongExact(type, v, context);
	}
	else if (PyTuple_Check(v) || PyList_Check(v)) {
		return PyDecType_FromSequenceExact(type, v, context);
	}
#if PY_VERSION_HEX >= 0x03020000
	else if (PyFloat_Check(v)) {
		if (dec_addstatus(context, MPD_Float_operation)) {
			return NULL;
		}
		return PyDecType_FromFloatExact(type, v, context);
	}
#endif
	else {
		PyErr_Format(PyExc_TypeError,
		    "conversion from %s to Decimal is not supported.",
		    v->ob_type->tp_name);
		return NULL;
	}
}

/* The context is used during conversion. This function is the
   equivalent of context.create_decimal(). */
static PyObject *
PyDec_FromObject(PyObject *v, PyObject *context)
{
	if (v == NULL) {
		return PyDec_FromSsize(0, context);
	}
	else if (PyDec_Check(v)) {
		mpd_context_t *ctx = CTX(context);
		if (mpd_isnan(MPD(v)) &&
		    MPD(v)->digits > ctx->prec - ctx->clamp) {
			/* Special case: too many NaN payload digits */
			PyObject *result;
			if (dec_addstatus(context, MPD_Conversion_syntax)) {
				return NULL;
			}
			result = dec_alloc();
			if (result == NULL) {
				return NULL;
			}
			mpd_setspecial(MPD(result), MPD_POS, MPD_NAN);
			return result;
		}
		return dec_apply(v, context);
	}
	else if (PyUnicode_Check(v)) {
		return PyDec_FromUnicode(v, context);
	}
	else if (PyLong_Check(v)) {
		return PyDec_FromLong(v, context);
	}
	else if (PyTuple_Check(v) || PyList_Check(v)) {
		return PyDec_FromSequence(v, context);
	}
#if PY_VERSION_HEX >= 0x03020000
	else if (PyFloat_Check(v)) {
		if (dec_addstatus(context, MPD_Float_operation)) {
			return NULL;
		}
		return PyDec_FromFloat(v, context);
	}
#endif
	else {
		PyErr_Format(PyExc_TypeError,
		    "conversion from %s to Decimal is not supported.",
		    v->ob_type->tp_name);
		return NULL;
	}
}

static PyObject *
dec_new(PyTypeObject *type, PyObject *args, PyObject *kwds UNUSED)
{
	PyObject *v = NULL;
	PyObject *context;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|OO", &v, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	return PyDecType_FromObjectExact(type, v, context);
}

static PyObject *
ctx_create_decimal(PyObject *context, PyObject *args)
{
	PyObject *v = NULL;

	if (!PyArg_ParseTuple(args, "|O", &v)) {
		return NULL;
	}

	return PyDec_FromObject(v, context);
}


/******************************************************************************/
/*                        Implicit conversions to Decimal                     */ 
/******************************************************************************/

/* Try to convert PyObject v to a new PyDecObject conv. If the conversion
   fails, set conv to NULL (exception is set). If the conversion is not
   implemented, set conv to Py_NotImplemented.  */
#define NOT_IMPL 0
#define TYPE_ERR 1
static inline int
convert_op(int type_err, PyObject **conv, PyObject *v, PyObject *context)
{

	if (PyDec_Check(v)) {
		*conv = v;
		Py_INCREF(v);
		return 1;
	}
	if (PyLong_Check(v)) {
		*conv = PyDec_FromLongExact(v, context);
		if (*conv == NULL) {
			return 0;
		}
		return 1;
	}

	if (type_err) {
		PyErr_Format(PyExc_TypeError,
		    "conversion from %s to Decimal is not supported.",
		    v->ob_type->tp_name);
	}
	else {
		Py_INCREF(Py_NotImplemented);
		*conv = Py_NotImplemented;
	}
	return 0;
}

/* Return NotImplemented for unsupported types. */
#define CONVERT_OP(a, v, context) \
        if (!convert_op(NOT_IMPL, a, v, context)) { \
                return *(a);                        \
        }

#define CONVERT_BINOP(a, b, v, w, context) \
        if (!convert_op(NOT_IMPL, a, v, context)) { \
                return *(a);                        \
        }                                           \
        if (!convert_op(NOT_IMPL, b, w, context)) { \
                Py_DECREF(*(a));                    \
                return *(b);                        \
        }

#define CONVERT_TERNOP(a, b, c, v, w, x, context) \
        if (!convert_op(NOT_IMPL, a, v, context)) { \
                return *(a);                        \
        }                                           \
        if (!convert_op(NOT_IMPL, b, w, context)) { \
                Py_DECREF(*(a));                    \
                return *(b);                        \
        }                                           \
        if (!convert_op(NOT_IMPL, c, x, context)) { \
                Py_DECREF(*(a));                    \
                Py_DECREF(*(b));                    \
                return *(c);                        \
        }

/* Raise TypeError for unsupported types. */
#define CONVERT_OP_RAISE(a, v, context) \
        if (!convert_op(TYPE_ERR, a, v, context)) { \
                return NULL;                        \
        }

#define CONVERT_BINOP_RAISE(a, b, v, w, context) \
        if (!convert_op(TYPE_ERR, a, v, context)) { \
                return NULL;                        \
        }                                           \
        if (!convert_op(TYPE_ERR, b, w, context)) { \
                Py_DECREF(*(a));                    \
                return NULL;                        \
        }

#define CONVERT_TERNOP_RAISE(a, b, c, v, w, x, context) \
        if (!convert_op(TYPE_ERR, a, v, context)) {     \
                return NULL;                            \
        }                                               \
        if (!convert_op(TYPE_ERR, b, w, context)) {     \
                Py_DECREF(*(a));                        \
                return NULL;                            \
        }                                               \
        if (!convert_op(TYPE_ERR, c, x, context)) {     \
                Py_DECREF(*(a));                        \
                Py_DECREF(*(b));                        \
                return NULL;                            \
        }


/******************************************************************************/
/*              Implicit conversions to Decimal for comparison                */ 
/******************************************************************************/

#if PY_VERSION_HEX >= 0x03020000
/* Convert rationals for comparison */
static PyObject *_Rational = NULL;
static PyObject *
multiply_by_denominator(PyObject *v, PyObject *r, PyObject *context)
{
	PyObject *result;
	PyObject *tmp = NULL;
	PyObject *denom = NULL;
	uint32_t status = 0;
	mpd_context_t maxctx;
	mpd_ssize_t exp;
	mpd_t *vv;

	/* v is not special, r is a rational */
	tmp = PyObject_GetAttrString(r, "denominator");
	if (tmp == NULL) {
		return NULL;
	}
	denom = PyDec_FromLongExact(tmp, context);
	Py_DECREF(tmp);
	if (denom == NULL) {
		return NULL;
	}

	vv = mpd_qncopy(MPD(v));
	if (vv == NULL) {
		Py_DECREF(denom);
		PyErr_NoMemory();
		return NULL;
	}
	result = dec_alloc();
	if (result == NULL) {
		Py_DECREF(denom);
		mpd_del(vv);
		return NULL;
	}

	mpd_maxcontext(&maxctx);
	/* Prevent Overflow in the following multiplication. The result of
	   the multiplication is only used in mpd_qcmp, which can handle
	   values that are technically out of bounds, like (for 32-bit)
	   99999999999999999999...99999999e+425000000. */
	exp = vv->exp;
	vv->exp = 0;
	mpd_qmul(MPD(result), vv, MPD(denom), &maxctx, &status);
	MPD(result)->exp = exp;

	Py_DECREF(denom);
	mpd_del(vv);
	/* If any status has been accumulated during the multiplication,
	   the result is invalid. This is very unlikely, since even the
	   32-bit version supports 425000000 digits. */
	if (status) {
		PyErr_SetString(PyExc_ValueError, /* GCOV_NOT_REACHED */
		  "exact conversion for comparison failed."); /* GCOV_NOT_REACHED */
		Py_DECREF(result); /* GCOV_NOT_REACHED */
		return NULL; /* GCOV_NOT_REACHED */
	}

	return result;
}

static PyObject *
numerator_as_decimal(PyObject *r, PyObject *context)
{
	PyObject *tmp, *num;

	tmp = PyObject_GetAttrString(r, "numerator");
	if (tmp == NULL) {
		return NULL;
	}

	num = PyDec_FromLongExact(tmp, context);
	Py_DECREF(tmp);
	return num;
}
#endif

/* Convert v and w for comparison. v is a Decimal. If w is a Rational, both
   v and w have to be transformed. Return 1 for success, with new references
   to the converted objects in vcmp and wcmp. Return 0 for failure. In that
   case wcmp is either NULL or Py_NotImplemented (new reference) and vcmp
   is undefined. */
static int
convert_op_cmp(PyObject **vcmp, PyObject **wcmp, PyObject *v, PyObject *w,
               int op, PyObject *context)
{
	mpd_context_t *ctx = CTX(context);

	*vcmp = v;

	if (PyDec_Check(w)) {
		Py_INCREF(w);
		*wcmp = w;
	}
	else if (PyLong_Check(w)) {
		*wcmp = PyDec_FromLongExact(w, context);
	}
	else if (PyFloat_Check(w)) {
		if (op != Py_EQ && op != Py_NE &&
		    dec_addstatus(context, MPD_Float_operation)) {
			*wcmp = NULL;
		}
		else {
			ctx->status |= MPD_Float_operation;
		#if PY_VERSION_HEX >= 0x03020000
			*wcmp = PyDec_FromFloatExact(w, context);
		#else
			Py_INCREF(Py_NotImplemented);
			*wcmp = Py_NotImplemented;
		#endif
		}
	}
#if PY_VERSION_HEX >= 0x03020000
	else if (PyComplex_Check(w) && (op == Py_EQ || op == Py_NE)) {
		Py_complex c = PyComplex_AsCComplex(w);
		if (PyErr_Occurred()) {
			*wcmp = NULL;
		}
		else if (c.imag == 0.0) {
			PyObject *tmp = PyFloat_FromDouble(c.real);
			if (tmp == NULL) {
				*wcmp = NULL;
			}
			else {
				ctx->status |= MPD_Float_operation;
				*wcmp = PyDec_FromFloatExact(tmp, context);
				Py_DECREF(tmp);
			}
		}
		else {
			Py_INCREF(Py_NotImplemented);
			*wcmp = Py_NotImplemented;
		}
	}
	else if (PyObject_IsInstance(w, _Rational)) {
		*wcmp = numerator_as_decimal(w, context);
		if (*wcmp && !mpd_isspecial(MPD(v))) {
			*vcmp = multiply_by_denominator(v, w, context);
			if (*vcmp == NULL) {
				Py_CLEAR(*wcmp);
			}
		}
	}
#endif
	else {
		Py_INCREF(Py_NotImplemented);
		*wcmp = Py_NotImplemented;
	}

	if (*wcmp == NULL || *wcmp == Py_NotImplemented) {
		return 0;
	}
	if (*vcmp == v) {
		Py_INCREF(v);
	}
	return 1;
}

#define CONVERT_BINOP_CMP(vcmp, wcmp, v, w, op, ctx) \
        if (!convert_op_cmp(vcmp, wcmp, v, w, op, ctx)) {  \
                return *(wcmp);                            \
        }                                                  \


/******************************************************************************/
/*                          Conversions from decimal                          */
/******************************************************************************/

/* PyDecObject as a string. The default module context is only used for
   the value of 'capitals'. */
static PyObject *
dec_str(PyObject *dec)
{
	PyObject *s, *c;
	char *res;

	CURRENT_CONTEXT(c);
	res = mpd_to_sci(MPD(dec), CtxCaps(c));
	if (res == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	s = PyUnicode_FromString(res);
	mpd_free(res);

	return s;
}

static const char *dtag = "Decimal('";
static const size_t dtaglen = 9; /* without NUL terminator */

/* Representation of a PyDecObject. */
static PyObject *
dec_repr(PyObject *dec)
{
	PyObject *s, *c;
	uint8_t err;
	char *cp;
	size_t declen;

	CURRENT_CONTEXT(c);
	cp = mpd_to_sci(MPD(dec), CtxCaps(c));
	if (cp == NULL) {
		PyErr_NoMemory();
		return NULL;
	}
	declen = strlen(cp);

	err = 0;
	cp = mpd_realloc(cp, (mpd_size_t)(declen+dtaglen+3), sizeof *cp, &err);
	if (err) {
		mpd_free(cp);
		PyErr_NoMemory();
		return NULL;
	}

	memmove(cp+dtaglen, cp, declen);
	memcpy(cp, dtag, dtaglen);
	cp[declen+dtaglen] = '\'';
	cp[declen+dtaglen+1] = ')';
	cp[declen+dtaglen+2] = '\0';

	s = PyUnicode_FromString(cp);

	mpd_free(cp);
	return s;
}

/* Formatted representation of a PyDecObject. */
static PyObject *
dec_format(PyObject *dec, PyObject *args)
{
	PyObject *result = NULL;
	PyObject *override = NULL;
	PyObject *dot = NULL;
	PyObject *sep = NULL;
	PyObject *grouping = NULL;
	PyObject *fmt = NULL;
	PyObject *fmtarg;
	PyObject *tmp;
	PyObject *context;
	mpd_spec_t spec;
	wchar_t buf[2];
	char *decstring= NULL;
	uint32_t status = 0;
	size_t n;


	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "O|O", &fmtarg, &override)) {
		return NULL;
	}

	if (PyUnicode_Check(fmtarg)) {
		if ((fmt = PyUnicode_AsUTF8String(fmtarg)) == NULL) {
			return NULL;
		}
	}
	else {
		PyErr_SetString(PyExc_TypeError,
		    "format arg must be str.");
		return NULL;
	}

	if (!mpd_parse_fmt_str(&spec, PyBytes_AS_STRING(fmt),
	                       CtxCaps(context))) {
		PyErr_SetString(PyExc_ValueError,
		    "invalid format string.");
		goto finish;
	}
	if (override) {
		if (!PyDict_Check(override)) {
			PyErr_SetString(PyExc_TypeError,
			    "optional argument must be a dict.");
			goto finish;
		}
		if ((dot = PyDict_GetItemString(override, "decimal_point"))) {
			if ((dot = PyUnicode_AsUTF8String(dot)) == NULL) {
				goto finish;
			}
			spec.dot = PyBytes_AS_STRING(dot);
		}
		if ((sep = PyDict_GetItemString(override, "thousands_sep"))) {
			if ((sep = PyUnicode_AsUTF8String(sep)) == NULL) {
				goto finish;
			}
			spec.sep = PyBytes_AS_STRING(sep);
		}
		if ((grouping = PyDict_GetItemString(override, "grouping"))) {
			if ((grouping = PyUnicode_AsUTF8String(grouping)) == NULL) {
				goto finish;
			}
			spec.grouping = PyBytes_AS_STRING(grouping);
		}
	}
	else {
		n = strlen(spec.dot);
		if (n > 1 || (n == 1 && !isascii((uchar)spec.dot[0]))) {
			n = mbstowcs(buf, spec.dot, 2);
			if (n != 1) {
				PyErr_SetString(PyExc_ValueError,
				    "invalid decimal point or unsupported "
				    "combination of LC_CTYPE and LC_NUMERIC.");
				goto finish;
			}
			if ((tmp = PyUnicode_FromWideChar(buf, n)) == NULL) {
				goto finish;
			}
			if ((dot = PyUnicode_AsUTF8String(tmp)) == NULL) {
				Py_DECREF(tmp);
				goto finish;
			}
			spec.dot = PyBytes_AS_STRING(dot);
			Py_DECREF(tmp);
		}
		n = strlen(spec.sep);
		if (n > 1 || (n == 1 && !isascii((uchar)spec.sep[0]))) {
			n = mbstowcs(buf, spec.sep, 2);
			if (n != 1) {
				PyErr_SetString(PyExc_ValueError,
				    "invalid thousands separator or unsupported "
				    "combination of LC_CTYPE and LC_NUMERIC.");
				goto finish;
			}
			if ((tmp = PyUnicode_FromWideChar(buf, n)) == NULL) {
				goto finish;
			}
			if ((sep = PyUnicode_AsUTF8String(tmp)) == NULL) {
				Py_DECREF(tmp);
				goto finish;
			}
			spec.sep = PyBytes_AS_STRING(sep);
			Py_DECREF(tmp);
		}
	}


	decstring = mpd_qformat_spec(MPD(dec), &spec, CTX(context), &status);
	if (decstring == NULL) {
		dec_addstatus(context, status);
		goto finish;
	}
	result = PyUnicode_DecodeUTF8(decstring, strlen(decstring), NULL);


finish:
	Py_XDECREF(grouping);
	Py_XDECREF(sep);
	Py_XDECREF(dot);
	Py_XDECREF(fmt);
	if (decstring) mpd_free(decstring);
	return result;
}

/* Return a PyLongObject from a PyDecObject, using the specified rounding
 * mode. The context precision is not observed. */
static PyObject *
dec_as_long(PyObject *dec, PyObject *context, int round)
{
	PyLongObject *pylong;
	size_t maxsize, n;
	Py_ssize_t i;
	mpd_t *x;
	mpd_context_t workctx;
	uint32_t status = 0;

	if (mpd_isspecial(MPD(dec))) {
		if (mpd_isnan(MPD(dec))) {
			PyErr_SetString(PyExc_ValueError,
			    "cannot convert NaN to integer.");
		}
		else {
			PyErr_SetString(PyExc_OverflowError,
			    "cannot convert Infinity to integer.");
		}
		return NULL;
	}

	if ((x = mpd_qnew()) == NULL) {
		PyErr_NoMemory();
		return NULL;
	}
	workctx = *CTX(context);
	workctx.round = round;
	mpd_qround_to_int(x, MPD(dec), &workctx, &status);
	if (dec_addstatus(context, status)) {
		mpd_del(x);
		return NULL;
	}

	maxsize = mpd_sizeinbase(x, PyLong_BASE);
	if (maxsize > PY_SSIZE_T_MAX) {
		mpd_del(x);
		PyErr_NoMemory();
		return NULL;
	}
	if ((pylong = _PyLong_New(maxsize)) == NULL) {
		mpd_del(x);
		return NULL;
	}

	status = 0;
#if PYLONG_BITS_IN_DIGIT == 30
	n = mpd_qexport_u32(pylong->ob_digit, maxsize, PyLong_BASE, x, &status);
#elif PYLONG_BITS_IN_DIGIT == 15
	n = mpd_qexport_u16(pylong->ob_digit, maxsize, PyLong_BASE, x, &status);
#else
  #error "PYLONG_BITS_IN_DIGIT should be 15 or 30."
#endif
	if (dec_addstatus(context, status)) {
		Py_DECREF((PyObject *) pylong);
		mpd_del(x);
		return NULL;
	}

	i = n;
	while ((i > 0) && (pylong->ob_digit[i-1] == 0)) {
		i--;
	}

	Py_SIZE(pylong) = i;
	if (mpd_isnegative(x) && !mpd_iszero(x)) {
		Py_SIZE(pylong) = -i;
	}

	mpd_del(x);
	return (PyObject *) pylong;
}

static PyObject *
PyDec_ToIntegralValue(PyObject *dec, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = {"rounding", "context", NULL};
	PyObject *result;
	PyObject *context;
	uint32_t status = 0;
	mpd_context_t workctx;
	int round = -1;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|iO", kwlist,
	                                 &round, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	workctx = *CTX(context);
	if (round >= 0) {
		if (!mpd_qsetround(&workctx, round)) {
			return type_error_ptr(invalid_rounding_err);
		}
	}

	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	mpd_qround_to_int(MPD(result), MPD(dec), &workctx, &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

static PyObject *
PyDec_ToIntegralExact(PyObject *dec, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = {"rounding", "context", NULL};
	PyObject *result;
	PyObject *context;
	uint32_t status = 0;
	mpd_context_t workctx;
	int round = -1;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|iO", kwlist,
	                                 &round, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	workctx = *CTX(context);
	if (round >= 0) {
		if (!mpd_qsetround(&workctx, round)) {
			return type_error_ptr(invalid_rounding_err);
		}
	}

	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	mpd_qround_to_intx(MPD(result), MPD(dec), &workctx, &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

static PyObject *
PyDec_AsFloat(PyObject *dec)
{
	PyObject *f, *s;

	if ((s = dec_str(dec)) == NULL) {
		return NULL;
	}

	f = PyFloat_FromString(s);
	Py_DECREF(s);

	return f;
}

static PyObject *
PyDec_Round(PyObject *dec, PyObject *args)
{
	PyObject *result;
	PyObject *x = NULL;
	uint32_t status = 0;
	PyObject *context;


	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|O", &x)) {
		return NULL;
	}

	if (x) {
		mpd_uint_t dq[1] = {1};
		mpd_t q = {MPD_STATIC|MPD_CONST_DATA,0,1,1,1,dq};
		mpd_ssize_t y;

		if (!PyLong_Check(x)) {
			PyErr_SetString(PyExc_TypeError,
			    "optional arg must be an integer.");
			return NULL;
		}

		y = long_as_mpd_ssize(x);
		if (PyErr_Occurred()) {
			return NULL;
		}
		if ((result = dec_alloc()) == NULL) {
			return NULL;
		}

		q.exp = (y == MPD_SSIZE_MIN) ? MPD_SSIZE_MAX : -y;
		mpd_qquantize(MPD(result), MPD(dec), &q, CTX(context), &status);
		if (dec_addstatus(context, status)) {
			Py_DECREF(result);
			return NULL;
		}

		return result;
	}
	else {
		return dec_as_long(dec, context, MPD_ROUND_HALF_EVEN);
	}
}

PyObject *DecimalTuple = NULL;
/* Return the DecimalTuple representation of a PyDecObject. */
static PyObject *
PyDec_AsTuple(PyObject *dec, PyObject *dummy UNUSED)
{
	PyObject *result = NULL;
	PyObject *sign = NULL;
	PyObject *coeff = NULL;
	PyObject *expt = NULL;
	PyObject *tmp = NULL;
	mpd_t *x = NULL;
	char *intstring = NULL;
	Py_ssize_t intlen, i;


	if ((x = mpd_qncopy(MPD(dec))) == NULL) {
		PyErr_NoMemory();
		goto out;
	}

	sign = Py_BuildValue("i", mpd_sign(MPD(dec)));
	if (sign == NULL) goto out;

	if (mpd_isinfinite(x)) {
		if ((expt = Py_BuildValue("s", "F")) == NULL) {
			goto out;
		}
		/* decimal.py has non-compliant infinity payloads. */
		if ((coeff = Py_BuildValue("(i)", 0)) == NULL) {
			goto out;
		}
	}
	else {
		if (mpd_isnan(x)) {
			expt = Py_BuildValue("s", mpd_isqnan(x)?"n":"N");
		}
		else {
			expt = Py_BuildValue(CONV_mpd_ssize_t, MPD(dec)->exp);
		}
		if (expt == NULL) goto out;

		/* coefficient is defined */
		if (x->len > 0) {

			/* make an integer */
			x->exp = 0;
			/* clear NaN and sign */
			mpd_clear_flags(x);
			intstring = mpd_to_sci(x, 1);
			if (intstring == NULL) {
				PyErr_NoMemory();
				goto out;
			}

			intlen = strlen(intstring);
			if ((coeff = PyTuple_New(intlen)) == NULL) {
				goto out;
			}

			for (i = 0; i < intlen; i++) {
				tmp = Py_BuildValue("i", intstring[i]-'0');
				if (tmp == NULL) goto out;
				PyTuple_SET_ITEM(coeff, i, tmp);
			}
		}
		else {
			if ((coeff = PyTuple_New(0)) == NULL) {
				goto out;
			}
		}
	}

	result = PyObject_CallFunctionObjArgs(DecimalTuple,
	                                      sign, coeff, expt, NULL);

out:
	if (x) mpd_del(x);
	if (intstring) mpd_free(intstring);
	Py_XDECREF(sign);
	Py_XDECREF(coeff);
	Py_XDECREF(expt);
	return result;
}


/******************************************************************************/
/*         Macros for converting mpdecimal functions to Decimal methods       */
/******************************************************************************/

/* Unary number method that uses the default module context. */
#define Dec_UnaryNumberMethod(MPDFUNC) \
static PyObject *                                               \
nm_##MPDFUNC(PyObject *self)                                    \
{                                                               \
        PyObject *result;                                       \
        PyObject *context;                                      \
        uint32_t status = 0;                                    \
                                                                \
        CURRENT_CONTEXT(context);                               \
        if ((result = dec_alloc()) == NULL) {                   \
                return NULL;                                    \
        }                                                       \
                                                                \
        MPDFUNC(MPD(result), MPD(self), CTX(context), &status); \
        if (dec_addstatus(context, status)) {                   \
                Py_DECREF(result);                              \
                return NULL;                                    \
        }                                                       \
                                                                \
        return result;                                          \
}

/* Binary number method that uses default module context. */
#define Dec_BinaryNumberMethod(MPDFUNC) \
static PyObject *                                                    \
nm_##MPDFUNC(PyObject *v, PyObject *w)                               \
{                                                                    \
        PyObject *a, *b;                                             \
        PyObject *result;                                            \
        PyObject *context;                                           \
        uint32_t status = 0;                                         \
                                                                     \
        CURRENT_CONTEXT(context) ;                                   \
        CONVERT_BINOP(&a, &b, v, w, context);                        \
                                                                     \
        if ((result = dec_alloc()) == NULL) {                        \
                Py_DECREF(a);                                        \
                Py_DECREF(b);                                        \
                return NULL;                                         \
        }                                                            \
                                                                     \
        MPDFUNC(MPD(result), MPD(a), MPD(b), CTX(context), &status); \
        Py_DECREF(a);                                                \
        Py_DECREF(b);                                                \
        if (dec_addstatus(context, status)) {                        \
                Py_DECREF(result);                                   \
                return NULL;                                         \
        }                                                            \
                                                                     \
        return result;                                               \
}

/* Boolean function without a context arg. */
#define Dec_BoolFunc(MPDFUNC) \
static PyObject *                                                       \
dec_##MPDFUNC(PyObject *self, PyObject *dummy UNUSED)                   \
{                                                                       \
        return MPDFUNC(MPD(self)) ? Dec_INCREF_TRUE : Dec_INCREF_FALSE; \
}

/* Boolean function with an optional context arg. */
#define Dec_BoolFuncVA(MPDFUNC) \
static PyObject *                                      \
dec_##MPDFUNC(PyObject *self, PyObject *args)          \
{                                                      \
        PyObject *context;                             \
                                                       \
        CURRENT_CONTEXT(context);                      \
        if (!PyArg_ParseTuple(args, "|O", &context)) { \
                return NULL;                           \
        }                                              \
        CONTEXT_CHECK_VA(context);                     \
                                                       \
        return MPDFUNC(MPD(self), CTX(context))        \
            ? Dec_INCREF_TRUE : Dec_INCREF_FALSE;      \
}

/* Unary function with an optional context arg. */
#define Dec_UnaryFuncVA(MPDFUNC) \
static PyObject *                                               \
dec_##MPDFUNC(PyObject *self, PyObject *args)                   \
{                                                               \
        PyObject *result;                                       \
        PyObject *context;                                      \
        uint32_t status = 0;                                    \
                                                                \
        CURRENT_CONTEXT(context);                               \
        if (!PyArg_ParseTuple(args, "|O", &context)) {          \
                return NULL;                                    \
        }                                                       \
        CONTEXT_CHECK_VA(context);                              \
                                                                \
        if ((result = dec_alloc()) == NULL) {                   \
                return NULL;                                    \
        }                                                       \
                                                                \
        MPDFUNC(MPD(result), MPD(self), CTX(context), &status); \
        if (dec_addstatus(context, status)) {                   \
                Py_DECREF(result);                              \
                return NULL;                                    \
        }                                                       \
                                                                \
        return result;                                          \
}

/* Binary function with an optional context arg. */
#define Dec_BinaryFuncVA(MPDFUNC) \
static PyObject *                                                    \
dec_##MPDFUNC(PyObject *v, PyObject *args)                           \
{                                                                    \
        PyObject *w, *context;                                       \
        PyObject *a, *b;                                             \
        PyObject *result;                                            \
        uint32_t status = 0;                                         \
                                                                     \
        CURRENT_CONTEXT(context);                                    \
        if (!PyArg_ParseTuple(args, "O|O", &w, &context)) {          \
                return NULL;                                         \
        }                                                            \
        CONTEXT_CHECK_VA(context);                                   \
        CONVERT_BINOP_RAISE(&a, &b, v, w, context);                  \
                                                                     \
        if ((result = dec_alloc()) == NULL) {                        \
                Py_DECREF(a);                                        \
                Py_DECREF(b);                                        \
                return NULL;                                         \
        }                                                            \
                                                                     \
        MPDFUNC(MPD(result), MPD(a), MPD(b), CTX(context), &status); \
        Py_DECREF(a);                                                \
        Py_DECREF(b);                                                \
        if (dec_addstatus(context, status)) {                        \
                Py_DECREF(result);                                   \
                return NULL;                                         \
        }                                                            \
                                                                     \
        return result;                                               \
}

/* Binary function with an optional context arg. Actual MPDFUNC does
   NOT take a context. Uses optional context for conversion only. */
#define Dec_BinaryFuncVA_NO_CTX(MPDFUNC) \
static PyObject *                                           \
dec_##MPDFUNC(PyObject *v, PyObject *args)                  \
{                                                           \
        PyObject *w, *context;                              \
        PyObject *a, *b;                                    \
        PyObject *result;                                   \
                                                            \
        CURRENT_CONTEXT(context);                           \
        if (!PyArg_ParseTuple(args, "O|O", &w, &context)) { \
                return NULL;                                \
        }                                                   \
        CONTEXT_CHECK_VA(context);                          \
        CONVERT_BINOP_RAISE(&a, &b, v, w, context);         \
                                                            \
        if ((result = dec_alloc()) == NULL) {               \
                Py_DECREF(a);                               \
                Py_DECREF(b);                               \
                return NULL;                                \
        }                                                   \
                                                            \
        MPDFUNC(MPD(result), MPD(a), MPD(b));               \
        Py_DECREF(a);                                       \
        Py_DECREF(b);                                       \
                                                            \
        return result;                                      \
}

/* Ternary function with an optional context arg. */
#define Dec_TernaryFuncVA(MPDFUNC) \
static PyObject *                                                            \
dec_##MPDFUNC(PyObject *v, PyObject *args)                                   \
{                                                                            \
        PyObject *w, *x, *context;                                           \
        PyObject *a, *b, *c;                                                 \
        PyObject *result;                                                    \
        uint32_t status = 0;                                                 \
                                                                             \
        CURRENT_CONTEXT(context);                                            \
        if (!PyArg_ParseTuple(args, "OO|O", &w, &x, &context)) {             \
                return NULL;                                                 \
        }                                                                    \
        CONTEXT_CHECK_VA(context);                                           \
        CONVERT_TERNOP_RAISE(&a, &b, &c, v, w, x, context);                  \
                                                                             \
        if ((result = dec_alloc()) == NULL) {                                \
                Py_DECREF(a);                                                \
                Py_DECREF(b);                                                \
                Py_DECREF(c);                                                \
                return NULL;                                                 \
        }                                                                    \
                                                                             \
        MPDFUNC(MPD(result), MPD(a), MPD(b), MPD(c), CTX(context), &status); \
        Py_DECREF(a);                                                        \
        Py_DECREF(b);                                                        \
        Py_DECREF(c);                                                        \
        if (dec_addstatus(context, status)) {                                \
                Py_DECREF(result);                                           \
                return NULL;                                                 \
        }                                                                    \
                                                                             \
        return result;                                                       \
}


/**********************************************/
/*              Number methods                */
/**********************************************/

Dec_UnaryNumberMethod(mpd_qminus)
Dec_UnaryNumberMethod(mpd_qplus)
Dec_UnaryNumberMethod(mpd_qabs)

Dec_BinaryNumberMethod(mpd_qadd)
Dec_BinaryNumberMethod(mpd_qsub)
Dec_BinaryNumberMethod(mpd_qmul)
Dec_BinaryNumberMethod(mpd_qdiv)
Dec_BinaryNumberMethod(mpd_qrem)
Dec_BinaryNumberMethod(mpd_qdivint)

static PyObject *
nm_dec_as_long(PyObject *dec)
{
	PyObject *context;

	CURRENT_CONTEXT(context);
	return dec_as_long(dec, context, MPD_ROUND_DOWN);
}

static int
nm_nonzero(PyDecObject *v)
{
	return !mpd_iszero(v->dec);
}

static PyObject *
nm_mpd_qdivmod(PyObject *v, PyObject *w)
{
	PyObject *a, *b;
	PyObject *q, *r;
	PyObject *context;
	uint32_t status = 0;
	PyObject *ret;

	CURRENT_CONTEXT(context);
	CONVERT_BINOP(&a, &b, v, w, context);

	if ((q = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}
	if ((r = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		Py_DECREF(q);
		return NULL;
	}

	mpd_qdivmod(MPD(q), MPD(r), MPD(a), MPD(b), CTX(context), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(r);
		Py_DECREF(q);
		return NULL;
	}

	ret = Py_BuildValue("(OO)", q, r);
	Py_DECREF(r);
	Py_DECREF(q);
	return ret;
}

static PyObject *
nm_mpd_qpow(PyObject *base, PyObject *exp, PyObject *mod)
{
	PyObject *a, *b, *c = NULL;
	PyObject *result;
	PyObject *context;
	uint32_t status = 0;

	CURRENT_CONTEXT(context);
	CONVERT_BINOP(&a, &b, base, exp, context);

	if (mod != Py_None) {
		if (!convert_op(NOT_IMPL, &c, mod, context)) {
			Py_DECREF(a);
			Py_DECREF(b);
			return c;
		}
	}

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		Py_XDECREF(c);
		return NULL;
	}

	if (c == NULL) {
		mpd_qpow(MPD(result), MPD(a), MPD(b),
		         CTX(context), &status);
	}
	else {
		mpd_qpowmod(MPD(result), MPD(a), MPD(b), MPD(c),
		            CTX(context), &status);
		Py_DECREF(c);
	}
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}


/******************************************************************************/
/*                             Decimal Methods                                */
/******************************************************************************/

/* Arithmetic operations */
Dec_UnaryFuncVA(mpd_qabs)
Dec_UnaryFuncVA(mpd_qexp)
Dec_UnaryFuncVA(mpd_qinvroot)
Dec_UnaryFuncVA(mpd_qln)
Dec_UnaryFuncVA(mpd_qlog10)
Dec_UnaryFuncVA(mpd_qminus)
Dec_UnaryFuncVA(mpd_qnext_minus)
Dec_UnaryFuncVA(mpd_qnext_plus)
Dec_UnaryFuncVA(mpd_qplus)
Dec_UnaryFuncVA(mpd_qreduce)
Dec_UnaryFuncVA(mpd_qsqrt)

Dec_BinaryFuncVA(mpd_qadd)
Dec_BinaryFuncVA(mpd_qcompare)
Dec_BinaryFuncVA(mpd_qcompare_signal)
Dec_BinaryFuncVA(mpd_qdiv)
Dec_BinaryFuncVA(mpd_qdivint)
Dec_BinaryFuncVA(mpd_qmax)
Dec_BinaryFuncVA(mpd_qmax_mag)
Dec_BinaryFuncVA(mpd_qmin)
Dec_BinaryFuncVA(mpd_qmin_mag)
Dec_BinaryFuncVA(mpd_qmul)
Dec_BinaryFuncVA(mpd_qnext_toward)
Dec_BinaryFuncVA(mpd_qpow)
Dec_BinaryFuncVA(mpd_qrem)
Dec_BinaryFuncVA(mpd_qrem_near)
Dec_BinaryFuncVA(mpd_qsub)

Dec_TernaryFuncVA(mpd_qfma)
Dec_TernaryFuncVA(mpd_qpowmod)

/* Miscellaneous */
Dec_BoolFunc(mpd_iscanonical)
Dec_BoolFunc(mpd_isfinite)
Dec_BoolFunc(mpd_isinfinite)
Dec_BoolFunc(mpd_isinteger)
Dec_BoolFunc(mpd_isnan)
Dec_BoolFunc(mpd_isqnan)
Dec_BoolFunc(mpd_issnan)
Dec_BoolFunc(mpd_issigned)
Dec_BoolFunc(mpd_isspecial)
Dec_BoolFunc(mpd_iszero)

Dec_BoolFuncVA(mpd_isnormal)
Dec_BoolFuncVA(mpd_issubnormal)

static PyObject *
dec_mpd_adjexp(PyObject *self, PyObject *dummy UNUSED)
{
	mpd_ssize_t retval;

	if (mpd_isspecial(MPD(self))) {
		retval = 0;
	}
	else {
		retval = mpd_adjexp(MPD(self));
	}

	return _PyLong_FromMpdSsize(retval);
}

/* Apply either the current context or the context provided as an optional
   argument. */
static PyObject *
PyDec_Apply(PyObject *dec, PyObject *args)
{
	PyObject *context;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|O", &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	return dec_apply(dec, context);
}

static PyObject *
dec_mpd_qcopy_abs(PyObject *self, PyObject *dummy UNUSED)
{
	PyObject *result;
	PyObject *context;
	uint32_t status = 0;

	CURRENT_CONTEXT(context);
	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	mpd_qcopy_abs(MPD(result), MPD(self), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

static PyObject *
dec_mpd_qcopy_negate(PyObject *self, PyObject *dummy UNUSED)
{
	PyObject *result;
	PyObject *context;
	uint32_t status = 0;

	CURRENT_CONTEXT(context);
	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	mpd_qcopy_negate(MPD(result), MPD(self), &status);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

Dec_UnaryFuncVA(mpd_qinvert)
Dec_UnaryFuncVA(mpd_qlogb)

Dec_BinaryFuncVA_NO_CTX(mpd_compare_total)
Dec_BinaryFuncVA_NO_CTX(mpd_compare_total_mag)

static PyObject *
dec_mpd_qcopy_sign(PyObject *v, PyObject *w)
{
	PyObject *result;
	PyObject *a, *b;
	PyObject *context;
	uint32_t status = 0;

	CURRENT_CONTEXT(context);
	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}

	mpd_qcopy_sign(MPD(result), MPD(a), MPD(b), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

Dec_BinaryFuncVA(mpd_qand)
Dec_BinaryFuncVA(mpd_qor)
Dec_BinaryFuncVA(mpd_qxor)

Dec_BinaryFuncVA(mpd_qrotate)
Dec_BinaryFuncVA(mpd_qscaleb)
Dec_BinaryFuncVA(mpd_qshift)

static PyObject *
dec_mpd_class(PyObject *self, PyObject *args)
{
	PyObject *context;
	const char *cp;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|O", &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	cp = mpd_class(MPD(self), CTX(context));
	return Py_BuildValue("s", cp);
}

static PyObject *
dec_canonical(PyObject *self, PyObject *dummy UNUSED)
{
	Py_INCREF(self);
	return self;
}

static PyObject *
dec_copy(PyObject *self, PyObject *dummy UNUSED)
{
	Py_INCREF(self);
	return self;
}

static PyObject *
dec_mpd_qdivmod(PyObject *v, PyObject *args)
{
	PyObject *w, *context;
	PyObject *a, *b;
	PyObject *q, *r;
	uint32_t status = 0;
	PyObject *ret;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "O|O", &w, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);
	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	if ((q = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}
	if ((r = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		Py_DECREF(q);
		return NULL;
	}

	mpd_qdivmod(MPD(q), MPD(r), MPD(a), MPD(b), CTX(context), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(r);
		Py_DECREF(q);
		return NULL;
	}

	ret = Py_BuildValue("(OO)", q, r);
	Py_DECREF(r);
	Py_DECREF(q);
	return ret;
}

static PyObject *
dec_mpd_qquantize(PyObject *v, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = {"exp", "rounding", "context", NULL};
	PyObject *w, *context;
	PyObject *a, *b;
	PyObject *result;
	uint32_t status = 0;
	mpd_context_t workctx;
	int round = -1;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "O|iO", kwlist,
	                                 &w, &round, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	workctx = *CTX(context);
	if (round >= 0) {
		if (!mpd_qsetround(&workctx, round)) {
			return type_error_ptr(invalid_rounding_err);
		}
	}

	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}

	mpd_qquantize(MPD(result), MPD(a), MPD(b), &workctx, &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

static PyObject *
dec_mpd_radix(PyObject *self UNUSED, PyObject *dummy UNUSED)
{
	PyObject *result;

	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	_dec_settriple(result, MPD_POS, 10, 0);
	return result;
}

static PyObject *
dec_mpd_same_quantum(PyObject *v, PyObject *args)
{
	PyObject *result;
	PyObject *w, *context;
	PyObject *a, *b;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "O|O", &w, &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);
	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	result = mpd_same_quantum(MPD(a), MPD(b)) ?
	             Dec_INCREF_TRUE : Dec_INCREF_FALSE;
	Py_DECREF(a);
	Py_DECREF(b);

	return result;
}

static PyObject *
dec_mpd_sign(PyObject *self, PyObject *dummy UNUSED)
{
	return Py_BuildValue("i", mpd_arith_sign(MPD(self)));
}

static PyObject *
dec_mpd_to_sci(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *context;
	char *s;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|O", &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	s = mpd_to_sci(MPD(self), CtxCaps(context));
	if (s == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	result = PyUnicode_FromString(s);
	mpd_free(s);

	return result;
}

static PyObject *
dec_mpd_to_eng(PyObject *self, PyObject *args)
{
	PyObject *result;
	PyObject *context;
	char *s;

	CURRENT_CONTEXT(context);
	if (!PyArg_ParseTuple(args, "|O", &context)) {
		return NULL;
	}
	CONTEXT_CHECK_VA(context);

	s = mpd_to_eng(MPD(self), CtxCaps(context));
	if (s == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	result = PyUnicode_FromString(s);
	mpd_free(s);

	return result;
}

static PyObject *
dec_richcompare(PyObject *v, PyObject *w, int op)
{
	PyObject *a;
	PyObject *b;
	PyObject *context;
	uint32_t status = 0;
	int a_issnan, b_issnan;
	int r;

	assert(PyDec_Check(v));

	CURRENT_CONTEXT(context);
	CONVERT_BINOP_CMP(&a, &b, v, w, op, context);

	a_issnan = mpd_issnan(MPD(a));
	b_issnan = mpd_issnan(MPD(b));

	r = mpd_qcmp(MPD(a), MPD(b), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (r == INT_MAX) {
		/* sNaNs or op={le,ge,lt,gt} always signal. */
		if (a_issnan || b_issnan || (op != Py_EQ && op != Py_NE)) {
			if (dec_addstatus(context, status)) {
				return NULL;
			}
		}
		/* qNaN comparison with op={eq,ne} or comparison
		 * with InvalidOperation disabled. */
		return (op == Py_NE) ? Dec_INCREF_TRUE : Dec_INCREF_FALSE;
	}

	switch (op) {
	case Py_EQ:
		r = (r == 0);
		break;
	case Py_NE:
		r = (r != 0);
		break;
	case Py_LE:
		r = (r <= 0);
		break;
	case Py_GE:
		r = (r >= 0);
		break;
	case Py_LT:
		r = (r == -1);
		break;
	case Py_GT:
		r = (r == 1);
		break;
	}

	return PyBool_FromLong(r);
}

#if PY_VERSION_HEX < 0x03020000
/* Always uses the module context */
static long
dec_hash(PyObject *v)
{
#if defined(CONFIG_64)
	mpd_uint_t data_two64m1[2] = {8446744073709551615ULL, 1ULL};
	mpd_t two64m1 = {MPD_POS|MPD_STATIC|MPD_CONST_DATA, 0, 20, 2, 2,
	                 data_two64m1};
#elif defined(CONFIG_32)
	mpd_uint_t data_two64m1[3] = {709551615UL, 446744073UL, 18UL};
	mpd_t two64m1 = {MPD_POS|MPD_STATIC|MPD_CONST_DATA, 0, 20, 3, 2,
	                 data_two64m1};
#else
	#error "CONFIG_64 or CONFIG_32 must be defined."
#endif
	mpd_uint_t data_ten[1] = {10};
	mpd_t ten = {MPD_POS|MPD_STATIC|MPD_CONST_DATA, 0, 2, 1, 1, data_ten};

	PyObject *a;
	PyObject *obj = NULL;
	mpd_t *tmp = NULL;
	char *cp = NULL;
	uint32_t status = 0;
	mpd_context_t maxcontext;
	long result;

	if ((a = dec_alloc()) == NULL) {
		PyErr_NoMemory();
		return -1;
	}
	if (!mpd_qcopy(MPD(a), MPD(v), &status)) {
		PyErr_NoMemory();
		result = -1;
		goto finish;
	}

	if (mpd_isspecial(MPD(a))) {
		if (mpd_isnan(MPD(a))) {
			PyErr_SetString(PyExc_TypeError,
			    "cannot hash a NaN value");
			result = -1;
		}
		else {
			if ((obj = dec_str(a)) == NULL) {
				result = -1;
				goto finish;
			}
			result = PyObject_Hash(obj);
		}
	}
	else if (mpd_iszero(MPD(a))) {
		result = 0;
	}
	else if (mpd_isinteger(MPD(a))) {
		PyObject *context = current_context();
		if (context == NULL) {
			result = -1;
			goto finish;
		}
		mpd_maxcontext(&maxcontext);

		if ((tmp = mpd_qnew()) == NULL) {
			PyErr_NoMemory();
			result = -1;
			goto finish;
		}

		/* clobbering a function scope object */
		mpd_qround_to_int(MPD(a), MPD(a), CTX(context), &status);
		mpd_qset_ssize(tmp, MPD(a)->exp, &maxcontext, &status);
		mpd_qpowmod(tmp, &ten, tmp, &two64m1, &maxcontext, &status);
		MPD(a)->exp = 0;
		mpd_qmul(MPD(a), MPD(a), tmp, &maxcontext, &status);

		if (status&MPD_Errors) {
			if (dec_addstatus(context, status)) {
				result = -1;
				goto finish;
			}
		}

		obj = dec_as_long(a, context, MPD_ROUND_DOWN);
		if (obj == NULL) {
			result = -1;
			goto finish;
		}
		result = PyObject_Hash(obj);
	}
	else {
		mpd_ssize_t tz;
		mpd_ssize_t exp;
		int sign;

		mpd_maxcontext(&maxcontext);
		tz = mpd_trail_zeros(MPD(a));
		exp = MPD(a)->exp + MPD(a)->digits;
		sign = mpd_sign(MPD(a));

		mpd_qshiftr_inplace(MPD(a), tz);
		MPD(a)->exp = 0;
		mpd_set_flags(MPD(a), MPD_POS);

		cp = mpd_to_sci(MPD(a), 1);
		if (cp == NULL) {
			PyErr_NoMemory();
			result = -1;
			goto finish;
		}

		obj = Py_BuildValue("(i"CONV_mpd_ssize_t"s)", sign, exp, cp);
		if (obj == NULL) {
			result = -1;
			goto finish;
		}
		result = PyObject_Hash(obj);
	}


finish:
	Py_DECREF(a);
	Py_XDECREF(obj);
	if (tmp) mpd_del(tmp);
	if (cp) mpd_free(cp);
	return result;
}
#else
/* Always uses the module context */
static Py_hash_t
dec_hash(PyObject *v)
{
#if defined(CONFIG_64) && _PyHASH_BITS == 61
	/* 2**61 - 1 */
	mpd_uint_t p_data[1] = {2305843009213693951ULL};
	mpd_t p = {MPD_POS|MPD_STATIC|MPD_CONST_DATA, 0, 19, 1, 1, p_data};
	/* Inverse of 10 modulo p */
	mpd_uint_t inv10_p_data[2] = {2075258708292324556ULL};
	mpd_t inv10_p = {MPD_POS|MPD_STATIC|MPD_CONST_DATA,
	                 0, 19, 1, 1, inv10_p_data};
#elif defined(CONFIG_32) && _PyHASH_BITS == 31
	/* 2**31 - 1 */
	mpd_uint_t p_data[2] = {147483647UL, 2};
	mpd_t p = {MPD_POS|MPD_STATIC|MPD_CONST_DATA, 0, 10, 2, 2, p_data};
	/* Inverse of 10 modulo p */
	mpd_uint_t inv10_p_data[2] = {503238553UL, 1};
	mpd_t inv10_p = {MPD_POS|MPD_STATIC|MPD_CONST_DATA,
	                 0, 10, 2, 2, inv10_p_data};
#else
	#error "No valid combination of CONFIG_64, CONFIG_32 and _PyHASH_BITS."
#endif
	const Py_hash_t py_hash_inf = 314159;
	const Py_hash_t py_hash_nan = 0;
	mpd_uint_t ten_data[1] = {10};
	mpd_t ten = {MPD_POS|MPD_STATIC|MPD_CONST_DATA,
	             0, 2, 1, 1, ten_data};
	Py_hash_t result;
	mpd_t *exp_hash = NULL;
	mpd_t *tmp = NULL;
	mpd_ssize_t exp;
	uint32_t status = 0;
	mpd_context_t maxctx;
	PyObject *context;


	context = current_context();
	if (context == NULL) {
		return -1;
	}

	if (mpd_isspecial(MPD(v))) {
		if (mpd_issnan(MPD(v))) {
			PyErr_SetString(PyExc_TypeError,
			    "Cannot hash a signaling NaN value.");
			return -1;
		}
		else if (mpd_isnan(MPD(v))) {
			return py_hash_nan;
		}
		else {
			return py_hash_inf * mpd_arith_sign(MPD(v));
		}
	}

	mpd_maxcontext(&maxctx);
	if ((exp_hash = mpd_qnew()) == NULL) {
		goto malloc_error;
	}
	if ((tmp = mpd_qnew()) == NULL) {
		goto malloc_error;
	}

	/*
	 * exp(v): exponent of v
	 * int(v): coefficient of v
	 */
	exp = MPD(v)->exp;
	if (exp >= 0) {
		/* 10**exp(v) % p */
		mpd_qsset_ssize(tmp, exp, &maxctx, &status);
		mpd_qpowmod(exp_hash, &ten, tmp, &p, &maxctx, &status);
	}
	else {
		/* inv10_p**(-exp(v)) % p */
		mpd_qsset_ssize(tmp, -exp, &maxctx, &status);
		mpd_qpowmod(exp_hash, &inv10_p, tmp, &p, &maxctx, &status);
	}

	/* hash = (int(v) * exp_hash) % p */
	if (!mpd_qcopy(tmp, MPD(v), &status)) {
		goto malloc_error;
	}
	tmp->exp = 0;
	mpd_set_positive(tmp);
	mpd_qmul(tmp, tmp, exp_hash, &maxctx, &status);
	mpd_qrem(tmp, tmp, &p, &maxctx, &status);

	result = mpd_qget_ssize(tmp, &status);
	result = mpd_ispositive(MPD(v)) ? result : -result;
	result = (result == -1) ? -2 : result;

	if (status != 0) {
		status |= MPD_Invalid_operation; /* GCOV_NOT_REACHED */
		if (dec_addstatus(context, status)) { /* GCOV_NOT_REACHED */
			result = -1; /* GCOV_NOT_REACHED */
			goto finish; /* GCOV_NOT_REACHED */
		} /* GCOV_NOT_REACHED */
	}


finish:
	if (exp_hash) mpd_del(exp_hash);
	if (tmp) mpd_del(tmp);
	return result;

malloc_error:
	PyErr_NoMemory();
	result = -1;
	goto finish;
}
#endif

static PyObject *
dec_reduce(PyObject *self, PyObject *dummy UNUSED)
{
	PyObject *result, *str;

	if ((str = dec_str(self)) == NULL) {
		return NULL;
	}

	result = Py_BuildValue("O(O)", Py_TYPE(self), str);
	Py_DECREF(str);

	return result;
}

static PyObject *
dec_real(PyObject *self, void *closure UNUSED)
{
	Py_INCREF(self);
	return self;
}

static PyObject *
dec_imag(PyObject *self UNUSED, void *closure UNUSED)
{
	PyObject *result;

	if ((result = dec_alloc()) == NULL) {
		return NULL;
	}

	_dec_settriple(result, MPD_POS, 0, 0);
	return result;
}

static PyObject *
dec_conjugate(PyObject *self, PyObject *dummy UNUSED)
{
	Py_INCREF(self);
	return self;
}

static PyObject *
dec_complex(PyObject *self, PyObject *dummy UNUSED)
{
	PyObject *f;
	double x;

	if ((f = PyDec_AsFloat(self)) == NULL) {
		return NULL;
	}

	x = PyFloat_AsDouble(f);
	Py_DECREF(f);
	if (PyErr_Occurred()) {
		return NULL;
	}

	return PyComplex_FromDoubles(x, 0);
}

static PyObject *
dec_trunc(PyObject *dec, PyObject *dummy UNUSED)
{
	PyObject *context;

	CURRENT_CONTEXT(context);
	return dec_as_long(dec, context, MPD_ROUND_DOWN);
}


static PyGetSetDef dec_getsets [] =
{
  { "real", (getter)dec_real, NULL, NULL, NULL},
  { "imag", (getter)dec_imag, NULL, NULL, NULL},
  {NULL}
};

static PyNumberMethods dec_number_methods =
{
	(binaryfunc) nm_mpd_qadd,
	(binaryfunc) nm_mpd_qsub,
	(binaryfunc) nm_mpd_qmul,
	(binaryfunc) nm_mpd_qrem,
	(binaryfunc) nm_mpd_qdivmod,
	(ternaryfunc) nm_mpd_qpow,
	(unaryfunc) nm_mpd_qminus,
	(unaryfunc) nm_mpd_qplus,
	(unaryfunc) nm_mpd_qabs,
	(inquiry) nm_nonzero,
	(unaryfunc) 0,   /* no bit-complement */
	(binaryfunc) 0,  /* no shiftl */
	(binaryfunc) 0,  /* no shiftr */
	(binaryfunc) 0,  /* no bit-and */
	(binaryfunc) 0,  /* no bit-xor */
	(binaryfunc) 0,  /* no bit-ior */
	(unaryfunc) nm_dec_as_long,
	0,               /* nb_reserved */
	(unaryfunc) PyDec_AsFloat,
	0,               /* binaryfunc nb_inplace_add; */
	0,               /* binaryfunc nb_inplace_subtract; */
	0,               /* binaryfunc nb_inplace_multiply; */
	0,               /* binaryfunc nb_inplace_remainder; */
	0,               /* ternaryfunc nb_inplace_power; */
	0,               /* binaryfunc nb_inplace_lshift; */
	0,               /* binaryfunc nb_inplace_rshift; */
	0,               /* binaryfunc nb_inplace_and; */
	0,               /* binaryfunc nb_inplace_xor; */
	0,               /* binaryfunc nb_inplace_or; */
	(binaryfunc) nm_mpd_qdivint,  /* binaryfunc nb_floor_divide; */
	(binaryfunc) nm_mpd_qdiv,     /* binaryfunc nb_true_divide; */
	0,               /* binaryfunc nb_inplace_floor_divide; */
	0,               /* binaryfunc nb_inplace_true_divide; */
};

static PyMethodDef dec_methods [] =
{
  /* Unary arithmetic functions */
  { "abs", dec_mpd_qabs, METH_VARARGS, doc_abs },
  { "exp", dec_mpd_qexp, METH_VARARGS, doc_exp },
  { "invroot", dec_mpd_qinvroot, METH_VARARGS, doc_invroot },
  { "ln", dec_mpd_qln, METH_VARARGS, doc_ln },
  { "log10", dec_mpd_qlog10, METH_VARARGS, doc_log10 },
  { "minus", dec_mpd_qminus, METH_VARARGS, doc_minus },
  { "next_minus", dec_mpd_qnext_minus, METH_VARARGS, doc_next_minus },
  { "next_plus", dec_mpd_qnext_plus, METH_VARARGS, doc_next_plus },
  { "normalize", dec_mpd_qreduce, METH_VARARGS, doc_normalize }, /* alias for reduce */
  { "plus", dec_mpd_qplus, METH_VARARGS, doc_plus },
  { "reduce", dec_mpd_qreduce, METH_VARARGS, doc_reduce },
  { "to_integral", (PyCFunction)PyDec_ToIntegralValue, METH_VARARGS|METH_KEYWORDS, doc_to_integral },
  { "to_integral_exact", (PyCFunction)PyDec_ToIntegralExact, METH_VARARGS|METH_KEYWORDS, doc_to_integral_exact },
  { "to_integral_value", (PyCFunction)PyDec_ToIntegralValue, METH_VARARGS|METH_KEYWORDS, doc_to_integral_value },
  { "sqrt", dec_mpd_qsqrt, METH_VARARGS, doc_sqrt },

  /* Binary arithmetic functions */
  { "add", dec_mpd_qadd, METH_VARARGS, doc_add },
  { "compare", dec_mpd_qcompare, METH_VARARGS, doc_compare },
  { "compare_signal", dec_mpd_qcompare_signal, METH_VARARGS, doc_compare_signal },
  { "div", dec_mpd_qdiv, METH_VARARGS, doc_div }, /* alias for divide */
  { "divide", dec_mpd_qdiv, METH_VARARGS, doc_divide },
  { "divide_int", dec_mpd_qdivint, METH_VARARGS, doc_divide_int },
  { "divint", dec_mpd_qdivint, METH_VARARGS, doc_divint }, /* alias for divide_int */
  { "divmod", dec_mpd_qdivmod, METH_VARARGS, doc_divmod },
  { "max", dec_mpd_qmax, METH_VARARGS, doc_max },
  { "max_mag", dec_mpd_qmax_mag, METH_VARARGS, doc_max_mag },
  { "min", dec_mpd_qmin, METH_VARARGS, doc_min },
  { "min_mag", dec_mpd_qmin_mag, METH_VARARGS, doc_min_mag },
  { "mul", dec_mpd_qmul, METH_VARARGS, doc_mul }, /* alias for multiply */
  { "multiply", dec_mpd_qmul, METH_VARARGS, doc_multiply },
  { "next_toward", dec_mpd_qnext_toward, METH_VARARGS, doc_next_toward },
  { "pow", dec_mpd_qpow, METH_VARARGS, doc_pow }, /* alias for power */
  { "power", dec_mpd_qpow, METH_VARARGS, doc_power },
  { "quantize", (PyCFunction)dec_mpd_qquantize, METH_VARARGS|METH_KEYWORDS, doc_quantize },
  { "rem", dec_mpd_qrem, METH_VARARGS, doc_rem }, /* alias for remainder */
  { "remainder", dec_mpd_qrem, METH_VARARGS, doc_remainder },
  { "remainder_near", dec_mpd_qrem_near, METH_VARARGS, doc_remainder_near },
  { "sub", dec_mpd_qsub, METH_VARARGS, doc_sub }, /* alias for subtract */
  { "subtract", dec_mpd_qsub, METH_VARARGS, doc_subtract },

  /* Ternary arithmetic functions */
  { "fma", dec_mpd_qfma, METH_VARARGS, doc_fma },
  { "powmod", dec_mpd_qpowmod, METH_VARARGS, doc_powmod },

  /* Boolean functions, no context arg */
  { "is_canonical", dec_mpd_iscanonical, METH_NOARGS, doc_is_canonical },
  { "is_finite", dec_mpd_isfinite, METH_NOARGS, doc_is_finite },
  { "is_infinite", dec_mpd_isinfinite, METH_NOARGS, doc_is_infinite },
  { "is_integer", dec_mpd_isinteger, METH_NOARGS, doc_is_integer },
  { "is_nan", dec_mpd_isnan, METH_NOARGS, doc_is_nan },
  { "is_qnan", dec_mpd_isqnan, METH_NOARGS, doc_is_qnan },
  { "is_snan", dec_mpd_issnan, METH_NOARGS, doc_is_snan },
  { "is_signed", dec_mpd_issigned, METH_NOARGS, doc_is_signed },
  { "is_special", dec_mpd_isspecial, METH_NOARGS, doc_is_special },
  { "is_zero", dec_mpd_iszero, METH_NOARGS, doc_is_zero },

  /* Boolean functions, optional context arg */
  { "is_normal", dec_mpd_isnormal, METH_VARARGS, doc_is_normal },
  { "is_subnormal", dec_mpd_issubnormal, METH_VARARGS, doc_is_subnormal },

  /* Unary functions, no context arg */
  { "adjusted", dec_mpd_adjexp, METH_NOARGS, doc_adjusted },
  { "canonical", dec_canonical, METH_NOARGS, doc_canonical },
  { "conjugate", dec_conjugate, METH_NOARGS, doc_conjugate },
  { "copy_abs", dec_mpd_qcopy_abs, METH_NOARGS, doc_copy_abs },
  { "copy_negate", dec_mpd_qcopy_negate, METH_NOARGS, doc_copy_negate },
  { "radix", dec_mpd_radix, METH_NOARGS, doc_radix },
  { "sign", dec_mpd_sign, METH_NOARGS, doc_sign },

  /* Unary functions, optional context arg */
  { "apply", PyDec_Apply, METH_VARARGS, doc_apply },
  { "logb", dec_mpd_qlogb, METH_VARARGS, doc_logb },
  { "logical_invert", dec_mpd_qinvert, METH_VARARGS, doc_logical_invert },
  { "number_class", dec_mpd_class, METH_VARARGS, doc_number_class },
  { "to_sci", dec_mpd_to_sci, METH_VARARGS, doc_to_sci }, /* alias for to_sci_string */
  { "to_sci_string", dec_mpd_to_sci, METH_VARARGS, doc_to_sci_string },
  { "to_eng", dec_mpd_to_eng, METH_VARARGS, doc_to_eng }, /* alias for to_eng_string */
  { "to_eng_string", dec_mpd_to_eng, METH_VARARGS, doc_to_eng_string },

  /* Binary functions, optional context arg */
  { "compare_total", dec_mpd_compare_total, METH_VARARGS, doc_compare_total },
  { "compare_total_mag", dec_mpd_compare_total_mag, METH_VARARGS, doc_compare_total_mag },
  { "copy_sign", dec_mpd_qcopy_sign, METH_O, doc_copy_sign },
  { "logical_and", dec_mpd_qand, METH_VARARGS, doc_logical_and },
  { "logical_or", dec_mpd_qor, METH_VARARGS, doc_logical_or },
  { "logical_xor", dec_mpd_qxor, METH_VARARGS, doc_logical_xor },
  { "rotate", dec_mpd_qrotate, METH_VARARGS, doc_rotate },
  { "same_quantum", dec_mpd_same_quantum, METH_VARARGS, doc_same_quantum },
  { "scaleb", dec_mpd_qscaleb, METH_VARARGS, doc_scaleb },
  { "shift", dec_mpd_qshift, METH_VARARGS, doc_shift },

  /* Miscellaneous */
  { "from_float", dec_from_float, METH_O|METH_CLASS, doc_from_float },
  { "as_tuple", PyDec_AsTuple, METH_NOARGS, doc_as_tuple },

  /* Generic stuff */
  { "__copy__", dec_copy, METH_NOARGS, NULL },
  { "__deepcopy__", dec_copy, METH_O, NULL },
  { "__format__", dec_format, METH_VARARGS, NULL },
  { "__reduce__", dec_reduce, METH_NOARGS, NULL },
  { "__round__", PyDec_Round, METH_VARARGS, NULL },
  { "__trunc__", dec_trunc, METH_NOARGS, NULL },
  { "__complex__", dec_complex, METH_NOARGS, NULL },

  { NULL, NULL, 1 }
};

static PyTypeObject PyDec_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"cdecimal.Decimal",                     /* tp_name */
	sizeof(PyDecObject),                    /* tp_basicsize */
	0,                                      /* tp_itemsize */
	(destructor) dec_dealloc,               /* tp_dealloc */
	0,                                      /* tp_print */
	(getattrfunc) 0,                        /* tp_getattr */
	(setattrfunc) 0,                        /* tp_setattr */
	0,                                      /* tp_reserved */
	(reprfunc) dec_repr,                    /* tp_repr */
	&dec_number_methods,                    /* tp_as_number */
	0,                                      /* tp_as_sequence */
	0,                                      /* tp_as_mapping */
	(hashfunc) dec_hash,                    /* tp_hash */
	0,                                      /* tp_call */
	(reprfunc) dec_str,                     /* tp_str */
	(getattrofunc) PyObject_GenericGetAttr, /* tp_getattro */
	(setattrofunc) 0,                       /* tp_setattro */
	(PyBufferProcs *) 0,                    /* tp_as_buffer */
	(Py_TPFLAGS_DEFAULT|
	 Py_TPFLAGS_BASETYPE),                  /* tp_flags */
	doc_decimal,                            /* tp_doc */
	0,                                      /* tp_traverse */
	0,                                      /* tp_clear */
	dec_richcompare,                        /* tp_richcompare */
	0,                                      /* tp_weaklistoffset */
	0,                                      /* tp_iter */
	0,                                      /* tp_iternext */
	dec_methods,                            /* tp_methods */
	0,                                      /* tp_members */
	dec_getsets,                            /* tp_getset */
	0,                                      /* tp_base */
	0,                                      /* tp_dict */
	0,                                      /* tp_descr_get */
	0,                                      /* tp_descr_set */
	0,                                      /* tp_dictoffset */
	0,                                      /* tp_init */
	0,                                      /* tp_alloc */
	dec_new,                                /* tp_new */
	PyObject_Del,                           /* tp_free */
};


/******************************************************************************/
/*                         Context Object, Part 2                             */
/******************************************************************************/


/************************************************************************/
/*     Macros for converting mpdecimal functions to Context methods     */
/************************************************************************/

/* Boolean context method. */
#define DecCtx_BoolFunc(MPDFUNC) \
static PyObject *                                 \
ctx_##MPDFUNC(PyObject *context, PyObject *v)     \
{                                                 \
        PyObject *ret;                            \
        PyObject *a;                              \
                                                  \
        CONVERT_OP_RAISE(&a, v, context);         \
                                                  \
        ret = MPDFUNC(MPD(a), CTX(context))       \
            ? Dec_INCREF_TRUE : Dec_INCREF_FALSE; \
        Py_DECREF(a);                             \
        return ret;                               \
}

/* Boolean context method. MPDFUNC does NOT use a context. */
#define DecCtx_BoolFunc_NO_CTX(MPDFUNC) \
static PyObject *                                                   \
ctx_##MPDFUNC(PyObject *context, PyObject *v)                       \
{                                                                   \
        PyObject *ret;                                              \
        PyObject *a;                                                \
                                                                    \
        CONVERT_OP_RAISE(&a, v, context);                           \
                                                                    \
        ret = MPDFUNC(MPD(a)) ? Dec_INCREF_TRUE : Dec_INCREF_FALSE; \
        Py_DECREF(a);                                               \
        return ret;                                                 \
}

/* Unary context method. */
#define DecCtx_UnaryFunc(MPDFUNC) \
static PyObject *                                            \
ctx_##MPDFUNC(PyObject *context, PyObject *v)                \
{                                                            \
        PyObject *result, *a;                                \
        uint32_t status = 0;                                 \
                                                             \
        CONVERT_OP_RAISE(&a, v, context);                    \
                                                             \
        if ((result = dec_alloc()) == NULL) {                \
                Py_DECREF(a);                                \
                return NULL;                                 \
        }                                                    \
                                                             \
        MPDFUNC(MPD(result), MPD(a), CTX(context), &status); \
        Py_DECREF(a);                                        \
        if (dec_addstatus(context, status)) {                \
                Py_DECREF(result);                           \
                return NULL;                                 \
        }                                                    \
                                                             \
        return result;                                       \
}

/* Binary context method. */
#define DecCtx_BinaryFunc(MPDFUNC) \
static PyObject *                                                    \
ctx_##MPDFUNC(PyObject *context, PyObject *args)                     \
{                                                                    \
        PyObject *v, *w;                                             \
        PyObject *a, *b;                                             \
        PyObject *result;                                            \
        uint32_t status = 0;                                         \
                                                                     \
        if (!PyArg_ParseTuple(args, "OO", &v, &w)) {                 \
                return NULL;                                         \
        }                                                            \
                                                                     \
        CONVERT_BINOP_RAISE(&a, &b, v, w, context);                  \
                                                                     \
        if ((result = dec_alloc()) == NULL) {                        \
                Py_DECREF(a);                                        \
                Py_DECREF(b);                                        \
                return NULL;                                         \
        }                                                            \
                                                                     \
        MPDFUNC(MPD(result), MPD(a), MPD(b), CTX(context), &status); \
        Py_DECREF(a);                                                \
        Py_DECREF(b);                                                \
        if (dec_addstatus(context, status)) {                        \
                Py_DECREF(result);                                   \
                return NULL;                                         \
        }                                                            \
                                                                     \
        return result;                                               \
}

/*
 * Binary context method. The context is only used for conversion.
 * The actual MPDFUNC does NOT take a context arg.
 */
#define DecCtx_BinaryFunc_NO_CTX(MPDFUNC) \
static PyObject *                                    \
ctx_##MPDFUNC(PyObject *context, PyObject *args)     \
{                                                    \
        PyObject *v, *w;                             \
        PyObject *a, *b;                             \
        PyObject *result;                            \
                                                     \
        if (!PyArg_ParseTuple(args, "OO", &v, &w)) { \
                return NULL;                         \
        }                                            \
                                                     \
        CONVERT_BINOP_RAISE(&a, &b, v, w, context);  \
                                                     \
        if ((result = dec_alloc()) == NULL) {        \
                Py_DECREF(a);                        \
                Py_DECREF(b);                        \
                return NULL;                         \
        }                                            \
                                                     \
        MPDFUNC(MPD(result), MPD(a), MPD(b));        \
        Py_DECREF(a);                                \
        Py_DECREF(b);                                \
                                                     \
        return result;                               \
}

/* Ternary context method. */
#define DecCtx_TernaryFunc(MPDFUNC) \
static PyObject *                                                            \
ctx_##MPDFUNC(PyObject *context, PyObject *args)                             \
{                                                                            \
        PyObject *v, *w, *x;                                                 \
        PyObject *a, *b, *c;                                                 \
        PyObject *result;                                                    \
        uint32_t status = 0;                                                 \
                                                                             \
        if (!PyArg_ParseTuple(args, "OOO", &v, &w, &x)) {                    \
                return NULL;                                                 \
        }                                                                    \
                                                                             \
        CONVERT_TERNOP_RAISE(&a, &b, &c, v, w, x, context);                  \
                                                                             \
        if ((result = dec_alloc()) == NULL) {                                \
                Py_DECREF(a);                                                \
                Py_DECREF(b);                                                \
                Py_DECREF(c);                                                \
                return NULL;                                                 \
        }                                                                    \
                                                                             \
        MPDFUNC(MPD(result), MPD(a), MPD(b), MPD(c), CTX(context), &status); \
        Py_DECREF(a);                                                        \
        Py_DECREF(b);                                                        \
        Py_DECREF(c);                                                        \
        if (dec_addstatus(context, status)) {                                \
                Py_DECREF(result);                                           \
                return NULL;                                                 \
        }                                                                    \
                                                                             \
        return result;                                                       \
}

static PyObject *
ctx_copy_decimal(PyObject *context, PyObject *v)
{
	PyObject *result;

	CONVERT_OP_RAISE(&result, v, context);
	return  result;
}

/* Arithmetic operations */
DecCtx_UnaryFunc(mpd_qabs)
DecCtx_UnaryFunc(mpd_qexp)
DecCtx_UnaryFunc(mpd_qinvroot)
DecCtx_UnaryFunc(mpd_qln)
DecCtx_UnaryFunc(mpd_qlog10)
DecCtx_UnaryFunc(mpd_qminus)
DecCtx_UnaryFunc(mpd_qnext_minus)
DecCtx_UnaryFunc(mpd_qnext_plus)
DecCtx_UnaryFunc(mpd_qplus)
DecCtx_UnaryFunc(mpd_qreduce)
DecCtx_UnaryFunc(mpd_qround_to_int)
DecCtx_UnaryFunc(mpd_qround_to_intx)
DecCtx_UnaryFunc(mpd_qsqrt)

DecCtx_BinaryFunc(mpd_qadd)
DecCtx_BinaryFunc(mpd_qcompare)
DecCtx_BinaryFunc(mpd_qcompare_signal)
DecCtx_BinaryFunc(mpd_qdiv)
DecCtx_BinaryFunc(mpd_qdivint)
DecCtx_BinaryFunc(mpd_qmax)
DecCtx_BinaryFunc(mpd_qmax_mag)
DecCtx_BinaryFunc(mpd_qmin)
DecCtx_BinaryFunc(mpd_qmin_mag)
DecCtx_BinaryFunc(mpd_qmul)
DecCtx_BinaryFunc(mpd_qnext_toward)
DecCtx_BinaryFunc(mpd_qpow)
DecCtx_BinaryFunc(mpd_qquantize)
DecCtx_BinaryFunc(mpd_qrem)
DecCtx_BinaryFunc(mpd_qrem_near)
DecCtx_BinaryFunc(mpd_qsub)

DecCtx_TernaryFunc(mpd_qfma)
DecCtx_TernaryFunc(mpd_qpowmod)

/* Miscellaneous */
DecCtx_BoolFunc(mpd_isnormal)
DecCtx_BoolFunc(mpd_issubnormal)
DecCtx_BoolFunc_NO_CTX(mpd_isfinite)
DecCtx_BoolFunc_NO_CTX(mpd_isinfinite)
DecCtx_BoolFunc_NO_CTX(mpd_isnan)
DecCtx_BoolFunc_NO_CTX(mpd_isqnan)
DecCtx_BoolFunc_NO_CTX(mpd_issigned)
DecCtx_BoolFunc_NO_CTX(mpd_issnan)
DecCtx_BoolFunc_NO_CTX(mpd_iszero)

static PyObject *
ctx_mpd_qcopy_abs(PyObject *context, PyObject *v)
{
	PyObject *result, *a;
	uint32_t status = 0;

	CONVERT_OP_RAISE(&a, v, context);

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		return NULL;
	}

	mpd_qcopy_abs(MPD(result), MPD(a), &status);
	Py_DECREF(a);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

/* apply() as a context method. */
static PyObject *
PyDecContext_Apply(PyObject *context, PyObject *v)
{
	PyObject *result, *a;

	CONVERT_OP_RAISE(&a, v, context);

	result = dec_apply(a, context);
	Py_DECREF(a);
	return result;
}

static PyObject *
ctx_mpd_qcopy_negate(PyObject *context, PyObject *v)
{
	PyObject *result, *a;
	uint32_t status = 0;

	CONVERT_OP_RAISE(&a, v, context);

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		return NULL;
	}

	mpd_qcopy_negate(MPD(result), MPD(a), &status);
	Py_DECREF(a);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

DecCtx_UnaryFunc(mpd_qinvert)
DecCtx_UnaryFunc(mpd_qlogb)

DecCtx_BinaryFunc_NO_CTX(mpd_compare_total)
DecCtx_BinaryFunc_NO_CTX(mpd_compare_total_mag)

static PyObject *
ctx_mpd_qcopy_sign(PyObject *context, PyObject *args)
{
	PyObject *v, *w;
	PyObject *a, *b;
	PyObject *result;
	uint32_t status = 0;

	if (!PyArg_ParseTuple(args, "OO", &v, &w)) {
		return NULL;
	}

	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	if ((result = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}

	mpd_qcopy_sign(MPD(result), MPD(a), MPD(b), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(result);
		return NULL;
	}

	return result;
}

DecCtx_BinaryFunc(mpd_qand)
DecCtx_BinaryFunc(mpd_qor)
DecCtx_BinaryFunc(mpd_qxor)

DecCtx_BinaryFunc(mpd_qrotate)
DecCtx_BinaryFunc(mpd_qscaleb)
DecCtx_BinaryFunc(mpd_qshift)

static PyObject *
ctx_iscanonical(PyObject *context UNUSED, PyObject *v)
{
	if (!PyDec_Check(v)) {
		PyErr_SetString(PyExc_TypeError,
		    "argument must be a Decimal.");
		return NULL;
	}

	return mpd_iscanonical(MPD(v)) ? Dec_INCREF_TRUE : Dec_INCREF_FALSE;
}

static PyObject *
ctx_canonical(PyObject *context UNUSED, PyObject *v)
{
	if (!PyDec_Check(v)) {
		PyErr_SetString(PyExc_TypeError,
		    "argument must be a Decimal.");
		return NULL;
	}

	Py_INCREF(v);
	return v;
}

static PyObject *
ctx_mpd_class(PyObject *context, PyObject *v)
{
	PyObject *a;
	const char *cp;

	CONVERT_OP_RAISE(&a, v, context);

	cp = mpd_class(MPD(a), CTX(context));
	Py_DECREF(a);

	return Py_BuildValue("s", cp);
}

static PyObject *
ctx_mpd_qdivmod(PyObject *context, PyObject *args)
{
	PyObject *v, *w;
	PyObject *a, *b;
	PyObject *q, *r;
	uint32_t status = 0;
	PyObject *ret;

	if (!PyArg_ParseTuple(args, "OO", &v, &w)) {
		return NULL;
	}

	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	if ((q = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		return NULL;
	}
	if ((r = dec_alloc()) == NULL) {
		Py_DECREF(a);
		Py_DECREF(b);
		Py_DECREF(q);
		return NULL;
	}

	mpd_qdivmod(MPD(q), MPD(r), MPD(a), MPD(b), CTX(context), &status);
	Py_DECREF(a);
	Py_DECREF(b);
	if (dec_addstatus(context, status)) {
		Py_DECREF(r);
		Py_DECREF(q);
		return NULL;
	}

	ret = Py_BuildValue("(OO)", q, r);
	Py_DECREF(r);
	Py_DECREF(q);
	return ret;
}

static PyObject *
ctx_mpd_to_sci(PyObject *context, PyObject *v)
{
	PyObject *result;
	PyObject *a;
	char *s;

	CONVERT_OP_RAISE(&a, v, context);

	s = mpd_to_sci(MPD(a), CtxCaps(context));
	Py_DECREF(a);
	if (s == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	result = PyUnicode_FromString(s);
	mpd_free(s);

	return result;
}

static PyObject *
ctx_mpd_to_eng(PyObject *context, PyObject *v)
{
	PyObject *result;
	PyObject *a;
	char *s;

	CONVERT_OP_RAISE(&a, v, context);

	s = mpd_to_eng(MPD(a), CtxCaps(context));
	Py_DECREF(a);
	if (s == NULL) {
		PyErr_NoMemory();
		return NULL;
	}

	result = PyUnicode_FromString(s);
	mpd_free(s);

	return result;
}

static PyObject *
ctx_mpd_radix(PyObject *context UNUSED, PyObject *dummy UNUSED)
{
	return dec_mpd_radix(context, dummy);
}

static PyObject *
ctx_mpd_same_quantum(PyObject *context, PyObject *args)
{
	PyObject *v, *w;
	PyObject *a, *b;
	PyObject *result;

	if (!PyArg_ParseTuple(args, "OO", &v, &w)) {
		return NULL;
	}

	CONVERT_BINOP_RAISE(&a, &b, v, w, context);

	result = mpd_same_quantum(MPD(a), MPD(b)) ?
	             Dec_INCREF_TRUE : Dec_INCREF_FALSE;
	Py_DECREF(a);
	Py_DECREF(b);

	return result;
}


static PyMethodDef context_methods [] =
{
  /* Unary arithmetic functions */
  { "abs", ctx_mpd_qabs, METH_O, doc_ctx_abs },
  { "exp", ctx_mpd_qexp, METH_O, doc_ctx_exp },
  { "invroot", ctx_mpd_qinvroot, METH_O, doc_ctx_invroot },
  { "ln", ctx_mpd_qln, METH_O, doc_ctx_ln },
  { "log10", ctx_mpd_qlog10, METH_O, doc_ctx_log10 },
  { "minus", ctx_mpd_qminus, METH_O, doc_ctx_minus },
  { "next_minus", ctx_mpd_qnext_minus, METH_O, doc_ctx_next_minus },
  { "next_plus", ctx_mpd_qnext_plus, METH_O, doc_ctx_next_plus },
  { "normalize", ctx_mpd_qreduce, METH_O, doc_ctx_normalize }, /* alias for reduce */
  { "plus", ctx_mpd_qplus, METH_O, doc_ctx_plus },
  { "reduce", ctx_mpd_qreduce, METH_O, doc_ctx_reduce },
  { "to_integral", ctx_mpd_qround_to_int, METH_O, doc_ctx_to_integral },
  { "to_integral_exact", ctx_mpd_qround_to_intx, METH_O, doc_ctx_to_integral_exact },
  { "to_integral_value", ctx_mpd_qround_to_int, METH_O, doc_ctx_to_integral_value },
  { "sqrt", ctx_mpd_qsqrt, METH_O, doc_ctx_sqrt },

  /* Binary arithmetic functions */
  { "add", ctx_mpd_qadd, METH_VARARGS, doc_ctx_add },
  { "compare", ctx_mpd_qcompare, METH_VARARGS, doc_ctx_compare },
  { "compare_signal", ctx_mpd_qcompare_signal, METH_VARARGS, doc_ctx_compare_signal },
  { "div", ctx_mpd_qdiv, METH_VARARGS, doc_ctx_div }, /* alias for divide */
  { "divide", ctx_mpd_qdiv, METH_VARARGS, doc_ctx_divide },
  { "divide_int", ctx_mpd_qdivint, METH_VARARGS, doc_ctx_divide_int },
  { "divint", ctx_mpd_qdivint, METH_VARARGS, doc_ctx_divint }, /* alias for divide_int */
  { "divmod", ctx_mpd_qdivmod, METH_VARARGS, doc_ctx_divmod },
  { "max", ctx_mpd_qmax, METH_VARARGS, doc_ctx_max },
  { "max_mag", ctx_mpd_qmax_mag, METH_VARARGS, doc_ctx_max_mag },
  { "min", ctx_mpd_qmin, METH_VARARGS, doc_ctx_min },
  { "min_mag", ctx_mpd_qmin_mag, METH_VARARGS, doc_ctx_min_mag },
  { "mul", ctx_mpd_qmul, METH_VARARGS, doc_ctx_mul }, /* alias for multiply */
  { "multiply", ctx_mpd_qmul, METH_VARARGS, doc_ctx_multiply },
  { "next_toward", ctx_mpd_qnext_toward, METH_VARARGS, doc_ctx_next_toward },
  { "pow", ctx_mpd_qpow, METH_VARARGS, doc_ctx_pow }, /* alias for power */
  { "power", ctx_mpd_qpow, METH_VARARGS, doc_ctx_power },
  { "quantize", ctx_mpd_qquantize, METH_VARARGS, doc_ctx_quantize },
  { "rem", ctx_mpd_qrem, METH_VARARGS, doc_ctx_rem }, /* alias for remainder */
  { "remainder", ctx_mpd_qrem, METH_VARARGS, doc_ctx_remainder },
  { "remainder_near", ctx_mpd_qrem_near, METH_VARARGS, doc_ctx_remainder_near },
  { "sub", ctx_mpd_qsub, METH_VARARGS, doc_ctx_sub }, /* alias for subtract */
  { "subtract", ctx_mpd_qsub, METH_VARARGS, doc_ctx_subtract },

  /* Ternary arithmetic functions */
  { "fma", ctx_mpd_qfma, METH_VARARGS, doc_ctx_fma },
  { "powmod", ctx_mpd_qpowmod, METH_VARARGS, doc_ctx_powmod },

  /* No argument */
  { "Etiny", context_getetiny, METH_NOARGS, doc_ctx_Etiny },
  { "Etop", context_getetop, METH_NOARGS, doc_ctx_Etop },
  { "radix", ctx_mpd_radix, METH_NOARGS, doc_ctx_radix },

  /* Boolean functions */
  { "is_canonical", ctx_iscanonical, METH_O, doc_ctx_is_canonical },
  { "is_finite", ctx_mpd_isfinite, METH_O, doc_ctx_is_finite },
  { "is_infinite", ctx_mpd_isinfinite, METH_O, doc_ctx_is_infinite },
  { "is_nan", ctx_mpd_isnan, METH_O, doc_ctx_is_nan },
  { "is_normal", ctx_mpd_isnormal, METH_O, doc_ctx_is_normal },
  { "is_qnan", ctx_mpd_isqnan, METH_O, doc_ctx_is_qnan },
  { "is_signed", ctx_mpd_issigned, METH_O, doc_ctx_is_signed },
  { "is_snan", ctx_mpd_issnan, METH_O, doc_ctx_is_snan },
  { "is_subnormal", ctx_mpd_issubnormal, METH_O, doc_ctx_is_subnormal },
  { "is_zero", ctx_mpd_iszero, METH_O, doc_ctx_is_zero },

  /* Functions with a single decimal argument */
  { "_apply", PyDecContext_Apply, METH_O, NULL }, /* alias for apply */
  { "apply", PyDecContext_Apply, METH_O, doc_ctx_apply },
  { "canonical", ctx_canonical, METH_O, doc_ctx_canonical },
  { "copy_abs", ctx_mpd_qcopy_abs, METH_O, doc_ctx_copy_abs },
  { "copy_decimal", ctx_copy_decimal, METH_O, doc_ctx_copy_decimal },
  { "copy_negate", ctx_mpd_qcopy_negate, METH_O, doc_ctx_copy_negate },
  { "logb", ctx_mpd_qlogb, METH_O, doc_ctx_logb },
  { "logical_invert", ctx_mpd_qinvert, METH_O, doc_ctx_logical_invert },
  { "number_class", ctx_mpd_class, METH_O, doc_ctx_number_class },
  { "to_sci", ctx_mpd_to_sci, METH_O, doc_ctx_to_sci }, /* alias for to_sci_string */
  { "to_sci_string", ctx_mpd_to_sci, METH_O, doc_ctx_to_sci_string },
  { "to_eng", ctx_mpd_to_eng, METH_O, doc_ctx_to_eng }, /* alias for to_eng_string */
  { "to_eng_string", ctx_mpd_to_eng, METH_O, doc_ctx_to_eng_string },

  /* Functions with two decimal arguments */
  { "compare_total", ctx_mpd_compare_total, METH_VARARGS, doc_ctx_compare_total },
  { "compare_total_mag", ctx_mpd_compare_total_mag, METH_VARARGS, doc_ctx_compare_total_mag },
  { "copy_sign", ctx_mpd_qcopy_sign, METH_VARARGS, doc_ctx_copy_sign },
  { "logical_and", ctx_mpd_qand, METH_VARARGS, doc_ctx_logical_and },
  { "logical_or", ctx_mpd_qor, METH_VARARGS, doc_ctx_logical_or },
  { "logical_xor", ctx_mpd_qxor, METH_VARARGS, doc_ctx_logical_xor },
  { "rotate", ctx_mpd_qrotate, METH_VARARGS, doc_ctx_rotate },
  { "same_quantum", ctx_mpd_same_quantum, METH_VARARGS, doc_ctx_same_quantum },
  { "scaleb", ctx_mpd_qscaleb, METH_VARARGS, doc_ctx_scaleb },
  { "shift", ctx_mpd_qshift, METH_VARARGS, doc_ctx_shift },

  /* Set context values */
  { "setflags", PyDec_SetStatusFromList, METH_O, doc_ctx_setflags },
  { "settraps", PyDec_SetTrapsFromList, METH_O, doc_ctx_settraps },
  { "clear_flags", context_clear_flags, METH_NOARGS, doc_ctx_clear_flags },
  { "clear_traps", context_clear_traps, METH_NOARGS, doc_ctx_clear_traps },

  /* Unsafe set functions with no range checks */
  { "unsafe_setprec", context_unsafe_setprec, METH_O, NULL },
  { "unsafe_setemin", context_unsafe_setemin, METH_O, NULL },
  { "unsafe_setemax", context_unsafe_setemax, METH_O, NULL },

  /* Miscellaneous */
  { "__copy__", (PyCFunction)context_copy, METH_NOARGS, NULL },
  { "__reduce__", context_reduce, METH_NOARGS, NULL },
  { "copy", (PyCFunction)context_copy, METH_NOARGS, doc_ctx_copy },
  { "create_decimal", ctx_create_decimal, METH_VARARGS, doc_ctx_create_decimal },
  { "create_decimal_from_float", ctx_from_float, METH_O, doc_ctx_create_decimal_from_float },

  { NULL, NULL, 1 }
};

static PyTypeObject PyDecContext_Type =
{
	PyVarObject_HEAD_INIT(NULL, 0)
	"cdecimal.Context",                        /* tp_name */
	sizeof(PyDecContextObject),                /* tp_basicsize */
	0,                                         /* tp_itemsize */
	(destructor) context_dealloc,              /* tp_dealloc */
	0,                                         /* tp_print */
	(getattrfunc) 0,                           /* tp_getattr */
	(setattrfunc) 0,                           /* tp_setattr */
	0,                                         /* tp_reserved */
	(reprfunc) context_repr,                   /* tp_repr */
	0,                                         /* tp_as_number */
	0,                                         /* tp_as_sequence */
	0,                                         /* tp_as_mapping */
	(hashfunc) 0,                              /* tp_hash */
	0,                                         /* tp_call */
	(reprfunc) context_repr,                   /* tp_str */
	(getattrofunc) context_getattr,            /* tp_getattro */
	(setattrofunc) context_setattr,            /* tp_setattro */
	(PyBufferProcs *) 0,                       /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,                        /* tp_flags */
	doc_context,                               /* tp_doc */
	0,                                         /* tp_traverse */
	0,                                         /* tp_clear */
	0,                                         /* tp_richcompare */
	0,                                         /* tp_weaklistoffset */
	0,                                         /* tp_iter */
	0,                                         /* tp_iternext */
	context_methods,                           /* tp_methods */
	0,                                         /* tp_members */
	context_getsets,                           /* tp_getset */
	0,                                         /* tp_base */
	0,                                         /* tp_dict */
	0,                                         /* tp_descr_get */
	0,                                         /* tp_descr_set */
	0,                                         /* tp_dictoffset */
	context_init,                              /* tp_init */
	0,                                         /* tp_alloc */
	context_new,                               /* tp_new */
	0                                          /* tp_free */
};


static PyMethodDef cdecimal_methods [] =
{
  { "getcontext", (PyCFunction)PyDec_GetCurrentContext, METH_NOARGS, doc_getcontext},
  { "setcontext", (PyCFunction)PyDec_SetCurrentContext, METH_O, doc_setcontext},
  { "localcontext", (PyCFunction)ctxmanager_new, METH_VARARGS, doc_localcontext},
  { "IEEEContext", (PyCFunction)ieee_context, METH_O, doc_ieee_context},
  { NULL, NULL, 1, NULL }
};

static struct PyModuleDef cdecimal_module = {
	PyModuleDef_HEAD_INIT,
	"cdecimal",
	doc_cdecimal,
	-1,
	cdecimal_methods,
	NULL,
	NULL,
	NULL,
	NULL
};

struct ssize_constmap { const char *name; mpd_ssize_t val; };
static struct ssize_constmap ssize_constants [] = {
	{"MAX_PREC", MPD_MAX_PREC},
	{"MAX_EMAX", MPD_MAX_EMAX},
	{"MIN_EMIN",  MPD_MIN_EMIN},
	{"MIN_ETINY", MPD_MIN_ETINY},
	{NULL}
};

struct int_constmap { const char *name; int val; };
static struct int_constmap int_constants [] = {
	/* int constants */
	{"DECIMAL32", MPD_DECIMAL32},
	{"DECIMAL64", MPD_DECIMAL64},
	{"DECIMAL128", MPD_DECIMAL128},
	{"IEEE_CONTEXT_MAX_BITS", MPD_IEEE_CONTEXT_MAX_BITS},
	{"ROUND_CEILING", MPD_ROUND_CEILING},
	{"ROUND_FLOOR", MPD_ROUND_FLOOR},
	{"ROUND_UP", MPD_ROUND_UP},
	{"ROUND_DOWN", MPD_ROUND_DOWN},
	{"ROUND_HALF_UP", MPD_ROUND_HALF_UP},
	{"ROUND_HALF_DOWN", MPD_ROUND_HALF_DOWN},
	{"ROUND_HALF_EVEN", MPD_ROUND_HALF_EVEN},
	{"ROUND_05UP", MPD_ROUND_05UP},
	{"ROUND_TRUNC", MPD_ROUND_TRUNC},
	/* int condition flags */
	{"DecClamped", MPD_Clamped},
	{"DecConversionSyntax", MPD_Conversion_syntax},
	{"DecDivisionByZero", MPD_Division_by_zero},
	{"DecDivisionImpossible", MPD_Division_impossible},
	{"DecDivisionUndefined", MPD_Division_undefined},
	{"DecFpuError", MPD_Fpu_error},
	{"DecInexact", MPD_Inexact},
	{"DecInvalidContext", MPD_Invalid_context},
	{"DecInvalidOperation", MPD_Invalid_operation},
	{"DecIEEEInvalidOperation", MPD_IEEE_Invalid_operation},
	{"DecMallocError", MPD_Malloc_error},
	{"DecFloatOperation", MPD_Float_operation},
	{"DecOverflow", MPD_Overflow},
	{"DecRounded", MPD_Rounded},
	{"DecSubnormal", MPD_Subnormal},
	{"DecUnderflow", MPD_Underflow},
	{"DecErrors", MPD_Errors},
	{"DecTraps", MPD_Traps},
	{NULL}
};


#define CHECK_INT(expr) \
    do { if ((expr) < 0) goto error; } while (0)
#define ASSIGN_PTR(result, expr) \
    do { result = (expr); if (result == NULL) goto error; } while (0)
#define CHECK_PTR(expr) \
    do { if ((expr) == NULL) goto error; } while (0)

PyMODINIT_FUNC
PyInit_cdecimal(void)
{
	PyObject *m = NULL;
	PyObject *_numbers = NULL;
	PyObject *_Number = NULL;
	PyObject *_collections = NULL;
	PyObject *obj = NULL;
	PyObject *ret = NULL;
	PyObject *str1 = NULL;
	PyObject *str2 = NULL;
	PyObject *str3 = NULL;
	DecCondMap *cm;
	struct ssize_constmap *ssize_cm;
	struct int_constmap *int_cm;


	/* Init libmpdec */
	mpd_traphandler = dec_traphandler;
	mpd_mallocfunc = PyMem_Malloc;
	mpd_reallocfunc = PyMem_Realloc;
	mpd_callocfunc = mpd_callocfunc_em;
	mpd_free = PyMem_Free;
	mpd_setminalloc(4);


	/* Init types */
	PyDec_Type.tp_base = &PyBaseObject_Type;
	PyDecContext_Type.tp_base = &PyBaseObject_Type;
	PyDecSignalDict_Type.tp_base = &PyDict_Type;
	PyDecContextManager_Type.tp_base = &PyBaseObject_Type;

	CHECK_INT(PyType_Ready(&PyDec_Type));
	CHECK_INT(PyType_Ready(&PyDecContext_Type));
	CHECK_INT(PyType_Ready(&PyDecSignalDict_Type));
	CHECK_INT(PyType_Ready(&PyDecContextManager_Type));

	ASSIGN_PTR(obj, PyUnicode_FromString("cdecimal"));
	CHECK_INT(PyDict_SetItemString(PyDec_Type.tp_dict, "__module__", obj));
	CHECK_INT(PyDict_SetItemString(PyDecContext_Type.tp_dict,
	                               "__module__", obj));
	Py_CLEAR(obj);


	/* Imports from other modules */
	ASSIGN_PTR(_numbers, PyImport_ImportModule("numbers"));
	ASSIGN_PTR(_Number, PyObject_GetAttrString(_numbers, "Number"));
#if PY_VERSION_HEX >= 0x03020000
	ASSIGN_PTR(_Rational, PyObject_GetAttrString(_numbers, "Rational"));
#endif
	ASSIGN_PTR(str1, Py_BuildValue("s", "register"));
	ASSIGN_PTR(obj, Py_BuildValue("O", &PyDec_Type));
	ASSIGN_PTR(ret, PyObject_CallMethodObjArgs(_Number, str1, obj, NULL));
	Py_CLEAR(str1);
	Py_CLEAR(obj);
	Py_CLEAR(ret);

	ASSIGN_PTR(_collections, PyImport_ImportModule("collections"));
	ASSIGN_PTR(str1, Py_BuildValue("s", "namedtuple"));
	ASSIGN_PTR(str2, Py_BuildValue("s", "DecimalTuple"));
	ASSIGN_PTR(str3, Py_BuildValue("s", "sign digits exponent"));
	ASSIGN_PTR(DecimalTuple, PyObject_CallMethodObjArgs(
	                             _collections, str1, str2, str3, NULL));
	Py_CLEAR(str1);
	Py_CLEAR(str2);
	Py_CLEAR(str3);


	/* Create the module */
	ASSIGN_PTR(m, PyModule_Create(&cdecimal_module));


	/* Add types to the module */
	Py_INCREF(&PyDec_Type);
	CHECK_INT(PyModule_AddObject(m, "Decimal", (PyObject *)&PyDec_Type));
	Py_INCREF(&PyDecContext_Type);
	CHECK_INT(PyModule_AddObject(m, "Context",
	                             (PyObject *)&PyDecContext_Type));


	/* Create top level exception */
	ASSIGN_PTR(DecimalException, PyErr_NewException(
	                                 "cdecimal.DecimalException",
	                                 PyExc_ArithmeticError, NULL));
	Py_INCREF(DecimalException);
	CHECK_INT(PyModule_AddObject(m, "DecimalException", DecimalException));

	/* Add exceptions that correspond to IEEE signals */
	for (cm = signal_map; cm->name != NULL; cm++) {
		cm->dec_cond = PyErr_NewException((char *)cm->fqname,
		                                  DecimalException, NULL);
		Py_INCREF(cm->dec_cond);
		CHECK_INT(PyModule_AddObject(m, cm->name, cm->dec_cond));
	}

	/*
	 * Unfortunately, InvalidOperation is a signal that comprises
	 * several conditions, including InvalidOperation! Naming the
	 * signal IEEEInvalidOperation would prevent the confusion.
	 */
	cond_map[0].dec_cond = signal_map[0].dec_cond;

	/* Add remaining exceptions, inherit from InvalidOperation */
	for (cm = cond_map+1; cm->name != NULL; cm++) {
		cm->dec_cond = PyErr_NewException((char *)cm->fqname,
		                                  signal_map[0].dec_cond, NULL);
		Py_INCREF(cm->dec_cond);
		CHECK_INT(PyModule_AddObject(m, cm->name, cm->dec_cond));
	}


	/* Init default context template first */
	ASSIGN_PTR(default_context_template,
	           PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL));
	Py_INCREF(default_context_template);
	CHECK_INT(PyModule_AddObject(m, "DefaultContext",
	                             default_context_template));

#ifdef WITHOUT_THREADS
	/* Init module context */
	ASSIGN_PTR(module_context,
	           PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL));
	CHECK_INT(PyModule_AddIntConstant(m, "HAVE_THREADS", 0));
#else
	ASSIGN_PTR(tls_context_key, Py_BuildValue("s", "___DECIMAL_CTX__"));
	CHECK_INT(PyModule_AddIntConstant(m, "HAVE_THREADS", 1));
#endif

	/* Init basic context template */
	ASSIGN_PTR(basic_context_template,
	           PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL));
	init_basic_context(basic_context_template);
	Py_INCREF(basic_context_template);
	CHECK_INT(PyModule_AddObject(m, "BasicContext",
	                             basic_context_template));

	/* Init extended context template */
	ASSIGN_PTR(extended_context_template,
	           PyObject_CallObject((PyObject *)&PyDecContext_Type, NULL));
	init_extended_context(extended_context_template);
	Py_INCREF(extended_context_template);
	CHECK_INT(PyModule_AddObject(m, "ExtendedContext",
	                             extended_context_template));


	/* Init mpd_ssize_t constants */
	for (ssize_cm = ssize_constants; ssize_cm->name != NULL; ssize_cm++) {
		ASSIGN_PTR(obj, Py_BuildValue(CONV_mpd_ssize_t, ssize_cm->val));
		CHECK_INT(PyModule_AddObject(m, ssize_cm->name, obj));
	}

	/* Init int constants */
	for (int_cm = int_constants; int_cm->name != NULL; int_cm++) {
		CHECK_INT(PyModule_AddIntConstant(m, int_cm->name,
		                                  int_cm->val));
	}


	return m;


error:
	Py_XDECREF(_numbers); /* GCOV_NOT_REACHED */
	Py_XDECREF(_Number); /* GCOV_NOT_REACHED */
#if PY_VERSION_HEX >= 0x03020000
	Py_XDECREF(_Rational); /* GCOV_NOT_REACHED */
#endif
	Py_XDECREF(_collections); /* GCOV_NOT_REACHED */
	Py_XDECREF(DecimalTuple); /* GCOV_NOT_REACHED */
#ifdef WITHOUT_THREADS
	Py_XDECREF(module_context); /* GCOV_NOT_REACHED */
#else
	Py_XDECREF(default_context_template); /* GCOV_NOT_REACHED */
	Py_XDECREF(tls_context_key); /* GCOV_NOT_REACHED */
#endif
	Py_XDECREF(basic_context_template); /* GCOV_NOT_REACHED */
	Py_XDECREF(extended_context_template); /* GCOV_NOT_REACHED */
	Py_XDECREF(m); /* GCOV_NOT_REACHED */

	return NULL; /* GCOV_NOT_REACHED */
}


