dnl
dnl The following utility macros are covered by the following license:
dnl
dnl The files in this directory provide example uses of GNU M4.
dnl The following copyright notice applies to each of these
dnl description files.
dnl 
dnl Copyright (C) 2006 Free Software Foundation, Inc.
dnl This file is free software; the Free Software Foundation
dnl gives unlimited permission to copy and/or distribute it,
dnl with or without modifications, as long as this notice is preserved.
dnl 
divert(`-1')
define(`quote', `ifelse(`$#', `0', `', ``$*'')')
define(`dquote', ``$@'')
define(`dquote_elt', `ifelse(`$#', `0', `', `$#', `1', ```$1''',
                             ```$1'',$0(shift($@))')')

define(`foreach', `pushdef(`$1')_$0(`$1',
  (dquote(dquote_elt$2)), `$3')popdef(`$1')')
define(`_arg1', `$1')
define(`_foreach', `ifelse(`$2', `(`')', `',
  `define(`$1', _arg1$2)$3`'$0(`$1', (dquote(shift$2)), `$3')')')

# join(sep, args) - join each non-empty ARG into a single
# string, with each element separated by SEP
define(`join',
`ifelse(`$#', `2', ``$2'',
  `ifelse(`$2', `', `', ``$2'_')$0(`$1', shift(shift($@)))')')
define(`_join',
`ifelse(`$#$2', `2', `',
  `ifelse(`$2', `', `', ``$1$2'')$0(`$1', shift(shift($@)))')')
# joinall(sep, args) - join each ARG, including empty ones,
# into a single string, with each element separated by SEP
define(`joinall', ``$2'_$0(`$1', shift($@))')
define(`_joinall',
`ifelse(`$#', `2', `', ``$1$3'$0(`$1', shift(shift($@)))')')

define(`_cat', `$1$2')
define(`_x', `$1$2')
define(`nargs', `$#')

define(`fatal_error', `errprint(ifdef(`__program__', `__program__', ``m4'')'`:ifelse(__line__, `0', `', `__file__:__line__:')` fatal error: $*')m4exit(`1')')')

define(`_list_inline', `$@')
define(`_list_add', `(_list_inline$1, `$2')')
define(`list_add', `ifelse($1, list_create, (`$2'), _list_add($1, `$2'))')
define(`list_create', `')
define(`list_length', `nargs$1')
divert`'dnl
divert(`-1')
dnl
dnl Macros to enumerate argument lists
dnl
define(`_ARGTYPE_BASE', `$1')
define(`_ARGTYPE_ARRAY', `$3')
define(`_ARGTYPE', `$1$3')
define(`_ARGNAME', `$2')
define(`_ARG', `$1 $2$3')
define(`_ARGNAMES', `join(`, ', foreach(`arg', ($*), `_cat(`_ARGNAME', arg), '))')
define(`_ARGTYPES', `join(`, ', foreach(`arg', ($*), `_cat(`_ARGTYPE', arg), '))')
define(`_ARGS', `join(`, ', foreach(`arg', ($*), `_cat(`_ARG', arg), '))')

dnl
dnl Macro to define an intrinsic function, its return value and argument list
dnl
define(`INTRIN', `
	dnl Prevent redefinition
	ifdef(`_INTRIN_'_INTRIN_MACHINE`_$2',
		`fatal_error(`redefinition of intrinsic $2')',
		`define(`_INTRIN_'_INTRIN_MACHINE`_$2', `1')
	')

	dnl Add intrinsic name to the target list
	define(`_INTRIN_'_INTRIN_MACHINE, list_add(_cat(`_INTRIN_', _INTRIN_MACHINE), `$2'))

	dnl Remember the return type and arguments of the intrinsic
	define(`_INTRIN_'_INTRIN_MACHINE`_RET_$2', `$1')
	define(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$2', `$3')
')

define(`_INTRIN_GET_RET', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_RET_$1', _x(`_INTRIN_'_INTRIN_MACHINE`_RET_$1'), `fatal_error(`intrinsic $1 is not defined')')')
define(`_INTRIN_GET_ARGTYPES', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1', _cat(`_ARGTYPES', _x(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1')), `fatal_error(`intrinsic $1 is not defined')')')
define(`_INTRIN_GET_ARGNAMES', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1', _cat(`_ARGNAMES', _x(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1')), `fatal_error(`intrinsic $1 is not defined')')')
define(`_INTRIN_GET_ARGS', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1', _x(`_INTRIN_'_INTRIN_MACHINE`_ARGS_$1'), `fatal_error(`intrinsic $1 is not defined')')')

dnl
dnl Calling convention
dnl
define(`_INTRIN_GET_CALLCONV', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_CALLCONV_$1', `_INTRIN_CALLCONV_$1', `')')
define(`_INTRIN_SET_CALLCONV', `ifdef(`_INTRIN_'_INTRIN_MACHINE`_CALLCONV_$1', `fatal_error(`calling convention already defined for intrinsic $1')', `define(`_INTRIN_CALLCONV_$1', `$2')')')
define(`INTRIN_CDECL', `_INTRIN_SET_CALLCONV(`$1', `__cdecl')')
define(`INTRIN_STDCALL', `_INTRIN_SET_CALLCONV(`$1', `__stdcall')')

dnl
dnl Attributes
dnl
define(`INTRIN_SETJMP', `define(`_INTRIN_'_INTRIN_MACHINE`_SETJMP_$1', `')')
define(`INTRIN_DISCARDABLE', `define(`_INTRIN_'_INTRIN_MACHINE`_DISCARDABLE_$1', `')')
define(`INTRIN_PURE', `define(`_INTRIN_'_INTRIN_MACHINE`_PURE_$1', `')')
define(`INTRIN_CONST', `define(`_INTRIN_'_INTRIN_MACHINE`_CONST_$1', `')')

dnl
dnl Linkage
dnl
define(`INTRIN_IMPORT', `define(`_INTRIN_'_INTRIN_MACHINE`_IMPORT_$1', `')')

dnl
dnl List of targets
dnl
define(`_INTRIN_MACHINES', (`', `i', `ia32', `ia64', `x64', `w64', `iw64', `x86x_ia64', `x86x_x64', `sa', `cc', `ce'))
define(`_INTRIN_WITH_MACHINE', `pushdef(`_INTRIN_MACHINE', `$1')`'$2`'popdef(`_INTRIN_MACHINE')')
define(`_INTRIN', `_cat(`_INTRIN_', _INTRIN_MACHINE)')
define(`_INTRIN_FOREACH_MACHINE', `foreach(`target', _INTRIN_MACHINES, `_INTRIN_WITH_MACHINE(target, `$1')')')
define(`_INTRIN_FOREACH', `_INTRIN_FOREACH_MACHINE(`foreach(`$1', _INTRIN, `$2')')')

divert`'dnl
divert(`-1')
dnl
dnl Import the definitions for all intrinsics
dnl
foreach(`target', _INTRIN_MACHINES, `
	_INTRIN_WITH_MACHINE(target, `
		define(`_INTRIN_'_INTRIN_MACHINE, list_create)
		include(`intrin-machine'target`.m4')
	')
')
divert`'dnl

