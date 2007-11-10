/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include "DelayImp.h"

static inline size_t __strlen(const char *sz) {
  const char *szEnd = sz;
  while(*szEnd++)
    ;
  return szEnd - sz - 1;
}

static inline int __memcmp(const void *pv1,const void *pv2,size_t cb) {
  if(!cb) return 0;
  while(--cb && *(char *)pv1==*(char *)pv2) {
    pv1 = (char *)pv1 + 1;
    pv2 = (char *)pv2 + 1;
  }
  return *((unsigned char *)pv1) - *((unsigned char *)pv2);
}

static inline void *__memcpy(void *pvDst,const void *pvSrc,size_t cb) {
  void *pvRet = pvDst;
  while(cb--) {
    *(char *)pvDst = *(char *)pvSrc;
    pvDst = (char *)pvDst + 1;
    pvSrc = (char *)pvSrc + 1;
  }
  return pvRet;
}

inline unsigned IndexFromPImgThunkData(PCImgThunkData pitdCur,PCImgThunkData pitdBase) { return (unsigned) (pitdCur - pitdBase);}

#define __ImageBase _image_base__

extern "C"
const IMAGE_DOS_HEADER __ImageBase;

template <class X>
X PFromRva(RVA rva) { return X(PBYTE(&__ImageBase) + rva);}

typedef struct UnloadInfo *PUnloadInfo;
typedef struct UnloadInfo {
  PUnloadInfo puiNext;
  PCImgDelayDescr pidd;
} UnloadInfo;

inline unsigned CountOfImports(PCImgThunkData pitdBase) {
  unsigned cRet = 0;
  PCImgThunkData pitd = pitdBase;
  while(pitd->u1.Function) {
    pitd++;
    cRet++;
  }
  return cRet;
}

extern "C"
PUnloadInfo __puiHead = 0;

struct ULI : public UnloadInfo {
  ULI(PCImgDelayDescr pidd_) {
    pidd = pidd_;
    Link();
  }
  ~ULI() {
    Unlink();
  }
  void *operator new(size_t cb) { return ::LocalAlloc(LPTR,cb);}
  void operator delete(void *pv) { ::LocalFree(pv);}
  void Unlink() {
    PUnloadInfo *ppui = &__puiHead;
    while(*ppui && *ppui!=this) {
      ppui = &((*ppui)->puiNext);
    }
    if(*ppui==this) *ppui = puiNext;
  }
  void Link() {
    puiNext = __puiHead;
    __puiHead = this;
  }
};

struct InternalImgDelayDescr {
  DWORD grAttrs;
  LPCSTR szName;
  HMODULE *phmod;
  PImgThunkData pIAT;
  PCImgThunkData pINT;
  PCImgThunkData pBoundIAT;
  PCImgThunkData pUnloadIAT;
  DWORD dwTimeStamp;
};

typedef InternalImgDelayDescr *PIIDD;
typedef const InternalImgDelayDescr *PCIIDD;

static inline PIMAGE_NT_HEADERS WINAPI PinhFromImageBase(HMODULE hmod) { return PIMAGE_NT_HEADERS(PBYTE(hmod) + PIMAGE_DOS_HEADER(hmod)->e_lfanew);}
static inline void WINAPI OverlayIAT(PImgThunkData pitdDst,PCImgThunkData pitdSrc) { __memcpy(pitdDst,pitdSrc,CountOfImports(pitdDst) *sizeof IMAGE_THUNK_DATA);}
static inline DWORD WINAPI TimeStampOfImage(PIMAGE_NT_HEADERS pinh) { return pinh->FileHeader.TimeDateStamp;}
static inline bool WINAPI FLoadedAtPreferredAddress(PIMAGE_NT_HEADERS pinh,HMODULE hmod) { return UINT_PTR(hmod)==pinh->OptionalHeader.ImageBase;}

#if(defined(_X86_) && !defined(__x86_64))
#undef InterlockedExchangePointer
#define InterlockedExchangePointer(Target,Value) (PVOID)(LONG_PTR)InterlockedExchange((PLONG)(Target),(LONG)(LONG_PTR)(Value))
typedef unsigned long *PULONG_PTR;
#endif

extern "C"
FARPROC WINAPI __delayLoadHelper2(PCImgDelayDescr pidd,FARPROC *ppfnIATEntry) {
  InternalImgDelayDescr idd = {
    pidd->grAttrs,PFromRva<LPCSTR>(pidd->rvaDLLName),PFromRva<HMODULE*>(pidd->rvaHmod),PFromRva<PImgThunkData>(pidd->rvaIAT),PFromRva<PCImgThunkData>(pidd->rvaINT),PFromRva<PCImgThunkData>(pidd->rvaBoundIAT),PFromRva<PCImgThunkData>(pidd->rvaUnloadIAT),pidd->dwTimeStamp
  };
  DelayLoadInfo dli = {
    sizeof DelayLoadInfo,pidd,ppfnIATEntry,idd.szName,{ 0},0,0,0
  };

  if(0==(idd.grAttrs & dlattrRva)) {
    PDelayLoadInfo rgpdli[1] = { &dli};
    RaiseException(VcppException(ERROR_SEVERITY_ERROR,ERROR_INVALID_PARAMETER),0,1,PULONG_PTR(rgpdli));
    return 0;
  }
  HMODULE hmod = *idd.phmod;
  const unsigned iIAT = IndexFromPImgThunkData(PCImgThunkData(ppfnIATEntry),idd.pIAT);
  const unsigned iINT = iIAT;
  PCImgThunkData pitd = &(idd.pINT[iINT]);

  dli.dlp.fImportByName = !IMAGE_SNAP_BY_ORDINAL(pitd->u1.Ordinal);
  if(dli.dlp.fImportByName) dli.dlp.szProcName = LPCSTR(PFromRva<PIMAGE_IMPORT_BY_NAME>(RVA(UINT_PTR(pitd->u1.AddressOfData)))->Name);
  else dli.dlp.dwOrdinal = DWORD(IMAGE_ORDINAL(pitd->u1.Ordinal));
  FARPROC pfnRet = NULL;
  if(__pfnDliNotifyHook2) {
    pfnRet = ((*__pfnDliNotifyHook2)(dliStartProcessing,&dli));
    if(pfnRet!=NULL) goto HookBypass;
  }
  if(hmod==0) {
    if(__pfnDliNotifyHook2) hmod = HMODULE(((*__pfnDliNotifyHook2)(dliNotePreLoadLibrary,&dli)));
    if(hmod==0) hmod = ::LoadLibrary(dli.szDll);
    if(hmod==0) {
      dli.dwLastError = ::GetLastError();
      if(__pfnDliFailureHook2) hmod = HMODULE((*__pfnDliFailureHook2)(dliFailLoadLib,&dli));
      if(hmod==0) {
	PDelayLoadInfo rgpdli[1] = { &dli};
	RaiseException(VcppException(ERROR_SEVERITY_ERROR,ERROR_MOD_NOT_FOUND),0,1,PULONG_PTR(rgpdli));
	return dli.pfnCur;
      }
    }
    HMODULE hmodT = HMODULE(InterlockedExchangePointer((PVOID *) idd.phmod,PVOID(hmod)));
    if(hmodT!=hmod) {
      if(pidd->rvaUnloadIAT) new ULI(pidd);
    } else ::FreeLibrary(hmod);
  }
  dli.hmodCur = hmod;
  if(__pfnDliNotifyHook2) pfnRet = (*__pfnDliNotifyHook2)(dliNotePreGetProcAddress,&dli);
  if(pfnRet==0) {
    if(pidd->rvaBoundIAT && pidd->dwTimeStamp) {
      PIMAGE_NT_HEADERS pinh(PinhFromImageBase(hmod));
      if(pinh->Signature==IMAGE_NT_SIGNATURE &&
	TimeStampOfImage(pinh)==idd.dwTimeStamp &&
	FLoadedAtPreferredAddress(pinh,hmod)) {
	  pfnRet = FARPROC(UINT_PTR(idd.pBoundIAT[iIAT].u1.Function));
	  if(pfnRet!=0) goto SetEntryHookBypass;
      }
    }
    pfnRet = ::GetProcAddress(hmod,dli.dlp.szProcName);
  }
  if(pfnRet==0) {
    dli.dwLastError = ::GetLastError();
    if(__pfnDliFailureHook2) pfnRet = (*__pfnDliFailureHook2)(dliFailGetProc,&dli);
    if(pfnRet==0) {
      PDelayLoadInfo rgpdli[1] = { &dli};
      RaiseException(VcppException(ERROR_SEVERITY_ERROR,ERROR_PROC_NOT_FOUND),0,1,PULONG_PTR(rgpdli));
      pfnRet = dli.pfnCur;
    }
  }
SetEntryHookBypass:
  *ppfnIATEntry = pfnRet;
HookBypass:
  if(__pfnDliNotifyHook2) {
    dli.dwLastError = 0;
    dli.hmodCur = hmod;
    dli.pfnCur = pfnRet;
    (*__pfnDliNotifyHook2)(dliNoteEndProcessing,&dli);
  }
  return pfnRet;
}

extern "C"
WINBOOL WINAPI __FUnloadDelayLoadedDLL2(LPCSTR szDll) {
  WINBOOL fRet = FALSE;
  PUnloadInfo pui = __puiHead;

  for(pui = __puiHead;pui;pui = pui->puiNext) {
    LPCSTR szName = PFromRva<LPCSTR>(pui->pidd->rvaDLLName);
    size_t cbName = __strlen(szName);
    if(cbName==__strlen(szDll) && __memcmp(szDll,szName,cbName)==0) break;
  }
  if(pui && pui->pidd->rvaUnloadIAT) {
    PCImgDelayDescr pidd = pui->pidd;
    HMODULE *phmod = PFromRva<HMODULE*>(pidd->rvaHmod);
    HMODULE hmod = *phmod;
    OverlayIAT(PFromRva<PImgThunkData>(pidd->rvaIAT),PFromRva<PCImgThunkData>(pidd->rvaUnloadIAT));
    ::FreeLibrary(hmod);
    *phmod = NULL;
    delete reinterpret_cast<ULI*> (pui);
    fRet = TRUE;
  }
  return fRet;
}

extern "C"
HRESULT WINAPI __HrLoadAllImportsForDll(LPCSTR szDll) {
  HRESULT hrRet = HRESULT_FROM_WIN32(ERROR_MOD_NOT_FOUND);
  PIMAGE_NT_HEADERS pinh = PinhFromImageBase(HMODULE(&__ImageBase));
  if(pinh->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].Size) {
    PCImgDelayDescr pidd;
    pidd = PFromRva<PCImgDelayDescr>(pinh->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT].VirtualAddress);
    while(pidd->rvaDLLName) {
      LPCSTR szDllCur = PFromRva<LPCSTR>(pidd->rvaDLLName);
      size_t cchDllCur = __strlen(szDllCur);
      if(cchDllCur==__strlen(szDll) && __memcmp(szDll,szDllCur,cchDllCur)==0) break;
      pidd++;
    }
    if(pidd->rvaDLLName) {
      FARPROC *ppfnIATEntry = PFromRva<FARPROC*>(pidd->rvaIAT);
      size_t cpfnIATEntries = CountOfImports(PCImgThunkData(ppfnIATEntry));
      FARPROC *ppfnIATEntryMax = ppfnIATEntry + cpfnIATEntries;
      for(;ppfnIATEntry < ppfnIATEntryMax;ppfnIATEntry++) {
	__delayLoadHelper2(pidd,ppfnIATEntry);
      }
      hrRet = S_OK;
    }
  }
  return hrRet;
}
