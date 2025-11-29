# winstorecompat

This subdirectory contains `winstorecompat` and `windowsappcompat` libraries
which are intended to be used with mingw-w64 toolchains to produce code for
Windows 8/8.1 Store Apps and UWP Apps.

This document contains basic information on how to compile code for Windows
8/8.1 Store/UWP Apps with both mingw-w64 and MSVC. This document does not
describe how to package and release such apps, for this you will have to refer
to Microsoft Documentation.

When compiling code for Windows Store/UWP, you need to keep in mind that not all
CRT/Windows API functions are available for use. This is one reason why
`winstorecompat` and `windowsappcompat` exist - they provide stubs or simple
replacements for functions which are not available for use in such apps.

Documentation for each Windows API function documents whether it is available
to UWP apps or not. List of CRT functions which are not available to such apps
can be found here:

- <https://learn.microsoft.com/en-us/cpp/cppcx/crt-functions-not-supported-in-universal-windows-platform-apps>

## Windows 8/8.1 Store Apps

To compile code for Windows 8/8.1 Store:

- use `-DWINAPI_FAMILY=WINAPI_FAMILY_APP` when compiling.
- use `-lwinstorecompat` when linking.
- link with `msvcr120_app.dll`, which is a version of `msvcr120.dll` for use
  with Windows 8/8.1 Store apps.

Depending on whether you use gcc or clang, you need to use different options
in order to link with `msvcr120_app.dll`:

- gcc: `-mcrtdll=msvcr120_app`
- clang: `-lmsvcr120_app`

## UWP Apps

Microsoft Documentaion for UWP can be found here:

- <https://learn.microsoft.com/en-us/windows/uwp/>

To compile code for UWP:

- use `-DWINAPI_FAMILY=WINAPI_FAMILY_APP` when compiling.
- link with `windowsapp.lib` (`-lwindowsapp`, in case of mingw-w64).

When using mingw-w64, you also need:

- link with `libucrtapp.a` instead of `libucrt.a`.
- use `-lwindowsappcompat` when linking.

Depending on whether you use gcc or clang, you need to use different options
in order to link with `libucrtapp.a`:

- gcc: `-mcrtdll=ucrtapp`
- clang: `-lucrtapp`

## Current Limitations

Current mingw-w64 support for Windows 8/8.1 Store and UWP Apps is not perfect,
and you may encounter some issues depending on what toolchain you use.

### gcc

Using gcc with `-lwindowsapp` is not enough to produce valid code for UWP.

UWP code must be linked against api sets (`api-ms-win-*` assemblies), however
static mingw-w64 code that is linked into executables will end up referencing
symbols directly from `kernel32.dll`.

There are two ways to workaround this issue:

1. Get gcc specs with `gcc -dumpspecs`, modify them and pass modified specs
   file with `gcc -specs=`.

   You want to replace `-lkernel32` that follows mingw-w64's `-l` flags with
   `-lwindowsapp` and remove other `-l` flags for system Windows libraries.

2. Build mingw-w64 runtime, install it locally and replace import libraries for
   some system libraries (such as `libkernel32.a`) with `libwindowsapp.a`.

   This way `-lkernel32` and others will link with `libwindowsapp.a` disguised
   as `libkernel32.a`.

### clang

Using clang with `-lwindowsapp` works properly only with lld. You may want to
use `-fuse-ld=lld` when linking to ensure that clang invokes lld and not GNU ld.
