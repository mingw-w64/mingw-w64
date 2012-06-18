/* dwmapi.h
 *
 * Some dwmapi.dll exported functions such as
 *   DwmFlush
 *   DwmAttachMilContent
 *   DwmDetachMilContent
 * are not declared in this header for not being documented by Microsoft
 */

#ifndef __WINAPI_DWMAPI_H
#define __WINAPI_DWMAPI_H

#include <wtypes.h>

/* for MARGINS structure declaration.  */
#include <uxtheme.h>

/*
 * This API is available only on Vista+ versions. It's not guarded by version check
 * because that would cause problems with Mozilla code (and MSVC doesn't seem to be
 * doing that as well).
 */

#ifdef __cplusplus
extern "C" {
#endif

/* FIXME: move to winuser.h */
/* DWM messages.  */
#define WM_DWMCOMPOSITIONCHANGED 0x031E
#define WM_DWMNCRENDERINGCHANGED 0x031F
#define WM_DWMCOLORIZATIONCOLORCHANGED 0x0320
#define WM_DWMWINDOWMAXIMIZEDCHANGE 0x0321
/* FIXME end */



#define DWM_EC_DISABLECOMPOSITION 0
#define DWM_EC_ENABLECOMPOSITION 1

#define DWM_BB_ENABLE     0x00000001
#define DWM_BB_BLURREGION 0x00000002
#define DWM_BB_TRANSITIONONMAXIMIZED 0x00000004

#include <pshpack1.h>

typedef struct _DWM_BLURBEHIND {
    DWORD dwFlags;
    BOOL fEnable;
    HRGN hRgnBlur;
    BOOL fTransitionOnMaximized;
} DWM_BLURBEHIND, *PDWM_BLURBEHIND;

typedef struct _UNSIGNED_RATIO {
    UINT32 uiNumerator;
    UINT32 uiDenominator;
} UNSIGNED_RATIO;

typedef enum _DWM_SOURCE_FRAME_SAMPLING {
    DWM_SOURCE_FRAME_SAMPLING_POINT = 1,
    DWM_SOURCE_FRAME_SAMPLING_COVERAGE,
    DWM_SOURCE_FRAME_SAMPLING_LAST
} DWM_SOURCE_FRAME_SAMPLING;

typedef ULONGLONG DWM_FRAME_COUNT;

typedef struct _DWM_PRESENT_PARAMETERS {
    UINT32 cbSize;
    BOOL fQueue;
    DWM_FRAME_COUNT cRefreshStart;
    UINT cBuffer;
    BOOL fUseSourceRate;
    UNSIGNED_RATIO rateSource;
    UINT cRefreshesPerFrame;
    DWM_SOURCE_FRAME_SAMPLING eSampling;
} DWM_PRESENT_PARAMETERS;

typedef ULONGLONG QPC_TIME;

typedef struct _DWM_TIMING_INFO {
    UINT32 cbSize;
    UNSIGNED_RATIO rateRefresh;
    QPC_TIME qpcRefreshPeriod;
    UNSIGNED_RATIO rateCompose;
    QPC_TIME qpcVBlank;
    DWM_FRAME_COUNT cRefresh;
    UINT cDXRefresh;
    QPC_TIME qpcCompose;
    DWM_FRAME_COUNT cFrame;
    UINT cDXPresent;
    DWM_FRAME_COUNT cRefreshFrame;
    DWM_FRAME_COUNT cFrameSubmitted;
    UINT cDXPresentSubmitted;
    DWM_FRAME_COUNT cFrameConfirmed;
    UINT cDXPresentConfirmed;
    DWM_FRAME_COUNT cRefreshConfirmed;
    UINT cDXRefreshConfirmed;
    DWM_FRAME_COUNT cFramesLate;
    UINT cFramesOutstanding;
    DWM_FRAME_COUNT cFrameDisplayed;
    QPC_TIME qpcFrameDisplayed;
    DWM_FRAME_COUNT cRefreshFrameDisplayed;
    DWM_FRAME_COUNT cFrameComplete;
    QPC_TIME qpcFrameComplete;
    DWM_FRAME_COUNT cFramePending;
    QPC_TIME qpcFramePending;
    DWM_FRAME_COUNT cFramesDisplayed;
    DWM_FRAME_COUNT cFramesComplete;
    DWM_FRAME_COUNT cFramesPending;
    DWM_FRAME_COUNT cFramesAvailable;
    DWM_FRAME_COUNT cFramesDropped;
    DWM_FRAME_COUNT cFramesMissed;
    DWM_FRAME_COUNT cRefreshNextDisplayed;
    DWM_FRAME_COUNT cRefreshNextPresented;
    DWM_FRAME_COUNT cRefreshesDisplayed;
    DWM_FRAME_COUNT cRefreshesPresented;
    DWM_FRAME_COUNT cRefreshStarted;
    ULONGLONG cPixelsReceived;
    ULONGLONG cPixelsDrawn;
    DWM_FRAME_COUNT cBuffersEmpty;
} DWM_TIMING_INFO;

typedef enum _DWMWINDOWATTRIBUTE {
    DWMWA_NCRENDERING_ENABLED = 1,
    DWMWA_NCRENDERING_POLICY,
    DWMWA_TRANSITIONS_FORCEDISABLED,
    DWMWA_ALLOW_NCPAINT,
    DWMWA_CAPTION_BUTTON_BOUNDS,
    DWMWA_NONCLIENT_RTL_LAYOUT,
    DWMWA_FORCE_ICONIC_REPRESENTATION,
    DWMWA_FLIP3D_POLICY,
    DWMWA_EXTENDED_FRAME_BOUNDS,
    DWMWA_LAST
} DWMWINDOWATTRIBUTE;

#define DWM_TNP_RECTDESTINATION 0x00000001
#define DWM_TNP_RECTSOURCE      0x00000002
#define DWM_TNP_OPACITY         0x00000004
#define DWM_TNP_VISIBLE         0x00000008
#define DWM_TNP_SOURCECLIENTAREAONLY 0x00000010

typedef struct _DWM_THUMBNAIL_PROPERTIES {
    DWORD dwFlags;
    RECT rcDestination;
    RECT rcSource;
    BYTE opacity;
    BOOL fVisible;
    BOOL fSourceClientAreaOnly;
} DWM_THUMBNAIL_PROPERTIES, *PDWM_THUMBNAIL_PROPERTIES;

typedef enum _DWMFLIP3DWINDOWPOLICY {
    DWMFLIP3D_DEFAULT,
    DWMFLIP3D_EXCLUDEBELOW,
    DWMFLIP3D_EXCLUDEABOVE
} DWMFLIP3DWINDOWPOLICY;

typedef enum _DWMNCRENDERINGPOLICY {
    DWMNCRP_USEWINDOWSTYLE,
    DWMNCRP_DISABLED,
    DWMNCRP_ENABLED,
    DWMNCRP_LAST
} DWMNCRENDERINGPOLICY;

#include <poppack.h>

typedef HANDLE HTHUMBNAIL;
typedef HTHUMBNAIL* PHTHUMBNAIL;

BOOL WINAPI DwmDefWindowProc(
    HWND hwnd,
    UINT msg,
    WPARAM wParam,
    LPARAM lParam,
    LRESULT *plResult
);

HRESULT WINAPI DwmEnableBlurBehindWindow(
    HWND hWnd,
    const DWM_BLURBEHIND *pBlurBehind
);

HRESULT WINAPI DwmEnableComposition(
    UINT uCompositionAction
);

HRESULT WINAPI DwmEnableMMCSS(
    BOOL fEnableMMCSS
);

HRESULT WINAPI DwmExtendFrameIntoClientArea(
    HWND hWnd,
    const MARGINS *pMarInset
);

HRESULT WINAPI DwmGetColorizationColor(
    DWORD *pcrColorization,
    BOOL *pfOpaqueBlend
);

HRESULT WINAPI DwmGetCompositionTimingInfo(
    HWND hwnd,
    DWM_TIMING_INFO *pTimingInfo
);

HRESULT WINAPI DwmGetWindowAttribute(
    HWND hwnd,
    DWORD dwAttribute,
    PVOID pvAttribute,
    DWORD cbAttribute
);

HRESULT WINAPI DwmIsCompositionEnabled(
    BOOL *pfEnabled
);

HRESULT WINAPI DwmModifyPreviousDxFrameDuration(
    HWND hwnd,
    INT cRefreshes,
    BOOL fRelative
);

HRESULT WINAPI DwmQueryThumbnailSourceSize(
    HTHUMBNAIL hThumbnail,
    PSIZE pSize
);

HRESULT WINAPI DwmRegisterThumbnail(
    HWND hwndDestination,
    HWND *hwndSource,
    PHTHUMBNAIL phThumbnailId
);

HRESULT WINAPI DwmSetDxFrameDuration(
    HWND hwnd,
    INT cRefreshes
);

HRESULT WINAPI DwmSetPresentParameters(
    HWND hwnd,
    DWM_PRESENT_PARAMETERS *pPresentParams
);

HRESULT WINAPI DwmSetWindowAttribute(
    HWND hwnd,
    DWORD dwAttribute,
    LPCVOID pvAttribute,
    DWORD cbAttribute
);

HRESULT WINAPI DwmUnregisterThumbnail(
    HTHUMBNAIL hThumbnailId
);

HRESULT WINAPI DwmUpdateThumbnailProperties(
    HTHUMBNAIL hThumbnailId,
    const DWM_THUMBNAIL_PROPERTIES *ptnProperties
);

#ifdef __cplusplus
}
#endif

#endif /* __WINAPI_DWMAPI_H */

