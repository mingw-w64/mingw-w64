/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the mingw-w64 runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef _INC_TASKSCHD
#define _INC_TASKSCHD
#if (_WIN32_WINNT >= 0x0600)

#ifdef __cplusplus
extern "C" {
#endif

  typedef enum _TASK_COMPATIBILITY {
    TASK_COMPATIBILITY_AT   = 0,
    TASK_COMPATIBILITY_V1   = 1,
    TASK_COMPATIBILITY_V2   = 2 
  } TASK_COMPATIBILITY;

  typedef enum _TASK_CREATION {
    TASK_VALIDATE_ONLY                  = 0x1,
    TASK_CREATE                         = 0x2,
    TASK_UPDATE                         = 0x4,
    TASK_CREATE_OR_UPDATE               = 0x6,
    TASK_DISABLE                        = 0x8,
    TASK_DONT_ADD_PRINCIPAL_ACE         = 0x10,
    TASK_IGNORE_REGISTRATION_TRIGGERS   = 0x20 
  } TASK_CREATION;

  typedef enum _TASK_ENUM_HIDDEN {
    TASK_ENUM_HIDDEN   = 0x1 
  } TASK_ENUM_FLAGS;

  typedef enum _TASK_INSTANCES_POLICY {
    TASK_INSTANCES_PARALLEL        = 0,
    TASK_INSTANCES_QUEUE           = 1,
    TASK_INSTANCES_IGNORE_NEW      = 2,
    TASK_INSTANCES_STOP_EXISTING   = 3 
  } TASK_INSTANCES_POLICY;

  typedef enum _TASK_LOGON_TYPE {
    TASK_LOGON_NONE                            = 0,
    TASK_LOGON_PASSWORD                        = 1,
    TASK_LOGON_S4U                             = 2,
    TASK_LOGON_INTERACTIVE_TOKEN               = 3,
    TASK_LOGON_GROUP                           = 4,
    TASK_LOGON_SERVICE_ACCOUNT                 = 5,
    TASK_LOGON_INTERACTIVE_TOKEN_OR_PASSWORD   = 6 
  } TASK_LOGON_TYPE;

  typedef enum _TASK_RUN_FLAGS {
    TASK_RUN_NO_FLAGS              = 0x0,
    TASK_RUN_AS_SELF               = 0x1,
    TASK_RUN_IGNORE_CONSTRAINTS    = 0x2,
    TASK_RUN_USE_SESSION_ID        = 0x4,
    TASK_RUN_USER_SID              = 0x8 
  } TASK_RUN_FLAGS;

  typedef enum _TASK_RUNLEVEL_TYPE {
    TASK_RUNLEVEL_LUA       = 0,
    TASK_RUNLEVEL_HIGHEST   = 1 
  } TASK_RUNLEVEL_TYPE;

  typedef enum _TASK_SESSION_STATE_CHANGE_TYPE {
    TASK_CONSOLE_CONNECT      = 1,
    TASK_CONSOLE_DISCONNECT   = 2,
    TASK_REMOTE_CONNECT       = 3,
    TASK_REMOTE_DISCONNECT    = 4,
    TASK_SESSION_LOCK         = 7,
    TASK_SESSION_UNLOCK       = 8 
  } TASK_SESSION_STATE_CHANGE_TYPE;

  typedef enum _TASK_STATE {
    TASK_STATE_UNKNOWN    = 0,
    TASK_STATE_DISABLED   = 1,
    TASK_STATE_QUEUED     = 2,
    TASK_STATE_READY      = 3,
    TASK_STATE_RUNNING    = 4 
  } TASK_STATE;

  typedef enum _TASK_TRIGGER_TYPE2 {
    TASK_TRIGGER_EVENT                  = 0,
    TASK_TRIGGER_TIME                   = 1,
    TASK_TRIGGER_DAILY                  = 2,
    TASK_TRIGGER_WEEKLY                 = 3,
    TASK_TRIGGER_MONTHLY                = 4,
    TASK_TRIGGER_MONTHLYDOW             = 5,
    TASK_TRIGGER_IDLE                   = 6,
    TASK_TRIGGER_REGISTRATION           = 7,
    TASK_TRIGGER_BOOT                   = 8,
    TASK_TRIGGER_LOGON                  = 9,
    TASK_TRIGGER_SESSION_STATE_CHANGE   = 11 
  } TASK_TRIGGER_TYPE2;

#ifdef __cplusplus
}
#endif

#endif /*(_WIN32_WINNT >= 0x0600)*/
#endif /*_INC_TASKSCHD*/
