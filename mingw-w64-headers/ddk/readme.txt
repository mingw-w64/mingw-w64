The DDK sdk.
----------------

Supported version for x86 and x64 platform

You can check for existance of this optional package by verifying the definition of
the macro MINGW_HAVE_DDK_H.

This is an optional SDK. Its license is LGPL and you can obtain the original source by the
ReactOS project. We base on the on the rev 40801 of ReactOS svn. You can find this via svn
by svn://svn.reactos.org/reactos/trunk/reactos/include/ddk.
For further details on license please read at the ReactOS project.

How to install this SDK
-----------------------
Please simply copy the content of the include directory within the include folder of our header-set.
Most of the needed import libraries are already generated within the crt build, so you shouldn't need
any further compilation.
