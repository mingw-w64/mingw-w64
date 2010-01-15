/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#ifndef XA_H
#define XA_H

#define XIDDATASIZE 128
#define MAXGTRIDSIZE 64
#define MAXBQUALSIZE 64

#ifndef _XID_T_DEFINED
#define _XID_T_DEFINED
struct xid_t {
  long formatID;
  long gtrid_length;
  long bqual_length;
  char data[XIDDATASIZE];
};
#endif

typedef struct xid_t XID;

#ifdef _TMPROTOTYPES
extern int __cdecl ax_reg(int,XID *,long);
extern int __cdecl ax_unreg(int,long);
#else
extern int __cdecl ax_reg();
extern int __cdecl ax_unreg();
#endif

#define RMNAMESZ 32

#define MAXINFOSIZE 256

#ifndef _XA_SWITCH_T_DEFINED
#define _XA_SWITCH_T_DEFINED
struct xa_switch_t {
  char name[RMNAMESZ];
  long flags;
  long version;
  int (__cdecl *xa_open_entry)(char *,int,long);
  int (__cdecl *xa_close_entry)(char *,int,long);
  int (__cdecl *xa_start_entry)(XID *,int,long);
  int (__cdecl *xa_end_entry)(XID *,int,long);
  int (__cdecl *xa_rollback_entry)(XID *,int,long);
  int (__cdecl *xa_prepare_entry)(XID *,int,long);
  int (__cdecl *xa_commit_entry)(XID *,int,long);
  int (__cdecl *xa_recover_entry)(XID *,long,int,long);

  int (__cdecl *xa_forget_entry)(XID *,int,long);
  int (__cdecl *xa_complete_entry)(int *,int *,int,long);

};

typedef struct xa_switch_t xa_switch_t;
#endif

#define TMNOFLAGS 0x00000000L
#define TMREGISTER 0x00000001L
#define TMNOMIGRATE 0x00000002L
#define TMUSEASYNC 0x00000004L

#define TMASYNC 0x80000000L
#define TMONEPHASE 0x40000000L
#define TMFAIL 0x20000000L
#define TMNOWAIT 0x10000000L
#define TMRESUME 0x08000000L
#define TMSUCCESS 0x04000000L
#define TMSUSPEND 0x02000000L
#define TMSTARTRSCAN 0x01000000L
#define TMENDRSCAN 0x00800000L
#define TMMULTIPLE 0x00400000L
#define TMJOIN 0x00200000L
#define TMMIGRATE 0x00100000L

#define TM_JOIN 2
#define TM_RESUME 1
#define TM_OK 0
#define TMER_TMERR (-1)
#define TMER_INVAL (-2)
#define TMER_PROTO (-3)

#define XA_RBBASE 100
#define XA_RBROLLBACK XA_RBBASE
#define XA_RBCOMMFAIL XA_RBBASE+1
#define XA_RBDEADLOCK XA_RBBASE+2
#define XA_RBINTEGRITY XA_RBBASE+3
#define XA_RBOTHER XA_RBBASE+4
#define XA_RBPROTO XA_RBBASE+5
#define XA_RBTIMEOUT XA_RBBASE+6
#define XA_RBTRANSIENT XA_RBBASE+7
#define XA_RBEND XA_RBTRANSIENT

#define XA_NOMIGRATE 9
#define XA_HEURHAZ 8
#define XA_HEURCOM 7
#define XA_HEURRB 6
#define XA_HEURMIX 5
#define XA_RETRY 4
#define XA_RDONLY 3
#define XA_OK 0
#define XAER_ASYNC (-2)
#define XAER_RMERR (-3)
#define XAER_NOTA (-4)
#define XAER_INVAL (-5)
#define XAER_PROTO (-6)
#define XAER_RMFAIL (-7)
#define XAER_DUPID (-8)
#define XAER_OUTSIDE (-9)

typedef int (__cdecl *XA_OPEN_EPT)(char *,int,long);
typedef int (__cdecl *XA_CLOSE_EPT)(char *,int,long);
typedef int (__cdecl *XA_START_EPT)(XID *,int,long);
typedef int (__cdecl *XA_END_EPT)(XID *,int,long);
typedef int (__cdecl *XA_ROLLBACK_EPT)(XID *,int,long);
typedef int (__cdecl *XA_PREPARE_EPT)(XID *,int,long);
typedef int (__cdecl *XA_COMMIT_EPT)(XID *,int,long);
typedef int (__cdecl *XA_RECOVER_EPT)(XID *,long,int,long);
typedef int (__cdecl *XA_FORGET_EPT)(XID *,int,long);
typedef int (__cdecl *XA_COMPLETE_EPT)(int *,int *,int,long);

#endif
