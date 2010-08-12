/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_VSWRITER
#define _INC_VSWRITER

  typedef enum VSS_COMPONENT_FLAGS {
    VSS_CF_BACKUP_RECOVERY         = 0x00000001,
    VSS_CF_APP_ROLLBACK_RECOVERY   = 0x00000002,
    VSS_CF_NOT_SYSTEM_STATE        = 0x00000004 
  } VSS_COMPONENT_FLAGS;

  /* http://msdn.microsoft.com/en-us/library/aa384976%28v=VS.85%29.aspx */
  typedef enum VSS_USAGE_TYPE {
    VSS_UT_UNDEFINED             = 0,
    VSS_UT_BOOTABLESYSTEMSTATE   = 1,
    VSS_UT_SYSTEMSERVICE         = 2,
    VSS_UT_USERDATA              = 3,
    VSS_UT_OTHER                 = 4 
  } VSS_USAGE_TYPE;

#endif /*_INC_VSWRITER*/
