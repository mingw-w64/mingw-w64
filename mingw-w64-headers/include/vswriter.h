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

#endif /*_INC_VSWRITER*/
