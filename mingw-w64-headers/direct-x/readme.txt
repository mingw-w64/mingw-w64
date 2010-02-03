The direct-x sdk.
----------------

Supported version 7

You can check for existance of this optional package by verifying the definition of
the macro MINGW_HAVE_DDRAW_H and the version can be obtained by the macro
MINGW_DDRAW_VERSION.

This is an optional SDK. Its license is LGPL and you can obtain the original source by the
wine project. We base on the released wine-w32api-0.9.14.zip from the wine project.
For further details on license please read at the wine project and the COPYING.LIB file
included here.

How to install this SDK
-----------------------
Please simply copy the content of the include directory within the include folder of our header-set.
Most of the needed import libraries are already generated within the crt build, so you shouldn't need
any further compilation.
