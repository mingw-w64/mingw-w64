// This is the mainpage file for doxygen
// See <http://www.doxygen.nl/commands.html>
// for command help.

/*! \mainpage Libmangle
  \author The mingw-w64 Dev Team
  \version 1.0
  \section intro_sec Introduction
 
  Libmangle is library for translating C++ symbols produced by Microsoft Visual Studio C++ suite of tools into human readable names.
  \subsection info_subsec Name Mangling
  Name mangling is a technique used by modern compilers to add addition information about a function, a structure or a datatype to a symbol name. Information can include call parameter type and return type, symbol namespace and etc. Often, the way the information is encoded in specific to a compiler vendor.
  \subsection cpp_subsec C++ and Name Mangling
  Languages such as the C++ language do not define a standard name decoration scheme, most often code produced by one compiler is also incompatible with another C++ compiler ABI wise. Name mangling prevents accidentally linking to code meant for another compiler.
  \subsection decde_subsec Deciphering Mangled Names
  Libmangle allows symbol names on objects created by Microsoft Visual C++ tools to be decoded into human readable names. In addition to easing debugging, it also allows the possibility of non-MSVC tools to examine the objects.
  \subsection external_subsec External Links
  For more information, see: http://en.wikipedia.org/wiki/Name_mangling
  \section install_sec Installation
   
  Use the shell script "configure" and pass "--help" for library build and install options.
 */
