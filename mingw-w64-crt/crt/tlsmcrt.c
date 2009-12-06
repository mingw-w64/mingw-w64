/* We support TLS cleanup code in any case. If shared version of libgcc is used _CRT_MT has value 1,
 otherwise
   we do tls cleanup in runtime and _CRT_MT has value 2.  */
int _CRT_MT = 2;

