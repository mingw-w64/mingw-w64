/* unknwn-uuid.c */
/* Generate GUIDs for Unknown interfaces */

/* All IIDs defined in this file were extracted from
 * HKEY_LOCAL_MACHINE\SOFTWARE\Classes\Interface\ */

#define INITGUID
#include <basetyps.h>
DEFINE_OLEGUID(IID_IUnknown,0,0,0);		/* 0,0,0,0xc0,0,0,0,0,0,0,0x46 */
DEFINE_OLEGUID(IID_IClassFactory,0x1,0,0);	/* 1,0,0,0xc0,0,0,0,0,0,0,0x46 */

