
baseheaddir = $(includedir)
sysheaddir = $(baseheaddir)/sys
secheaddir = $(baseheaddir)/sec_api
secsysheaddir = $(baseheaddir)/sec_api/sys
glheaddir = $(baseheaddir)/GL
khrheaddir = $(baseheaddir)/KHR
gdiplusheaddir = $(baseheaddir)/gdiplus
wrlheaddir = $(baseheaddir)/wrl
wrlwrappersheaddir = $(baseheaddir)/wrl/wrappers
mingwhelperheaddir = $(baseheaddir)/psdk_inc
sdksheaddir = $(baseheaddir)/sdks

basehead_HEADERS = @BASEHEAD_LIST@
syshead_HEADERS = @SYSHEAD_LIST@
sechead_HEADERS = @SECHEAD_LIST@
secsyshead_HEADERS = @SECSYSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@
khrhead_HEADERS = @KHRHEAD_LIST@
gdiplushead_HEADERS = @GDIPLUSHEAD_LIST@
wrlhead_HEADERS = @WRLHEAD_LIST@
wrlwrappershead_HEADERS = @WRLWRAPPERSHEAD_LIST@
mingwhelperhead_HEADERS = @MINGWHELPERHEAD_LIST@
nodist_sdkshead_HEADERS = _mingw_directx.h _mingw_ddk.h
noinst_HEADERS = crt/sdks/_mingw_directx.h.in crt/sdks/_mingw_ddk.h.in

ddkheaddir = $(baseheaddir)/ddk
dxheaddir = $(baseheaddir)
idlheaddir = $(baseheaddir)

ddkhead_HEADERS = @DDKHEAD_LIST@
dxhead_HEADERS = @DXHEAD_LIST@
idlhead_HEADERS = @IDLHEAD_LIST@

CLEANFILES = $(nodist_sdkshead_HEADERS)

DISTCHECK_CONFIGURE_FLAGS = --enable-crt --enable-sdk=all --enable-idl

EXTRA_DIST = $(srcdir)/ChangeLog.* include crt direct-x ddk tlb

dist-hook:
	find $(distdir) -name ".svn" -type d -delete

EXTRA_HEADERS = \
  include/*.c \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.idl \
  include/*.rh \
  include/*.ver \
  include/GL/*.h \
  include/psdk_inc/*.h \
  include/gdiplus/*.h \
  include/wrl/*.h \
  include/wrl/wrappers/*.h \
  crt/*.h \
  crt/*.inl \
  crt/sys/*.h \
  crt/sec_api/*.h \
  crt/sec_api/sys/*.h \
  direct-x/include/*.h \
  direct-x/include/*.idl \
  ddk/include/ddk/*.h \
  tlb/*.tlb

if HAVE_WIDL

IDL_SRCS = \
  include/activation.idl \
  include/activaut.idl \
  include/activdbg.idl \
  include/activdbg100.idl \
  include/activprof.idl \
  include/activscp.idl \
  include/adhoc.idl \
  include/alg.idl \
  include/audioclient.idl \
  include/audioendpoints.idl \
  include/audiopolicy.idl \
  include/bdaiface.idl \
  include/comadmin.idl \
  include/commoncontrols.idl \
  include/control.idl \
  include/ctfutb.idl \
  include/dbgprop.idl \
  include/dcompanimation.idl \
  include/dimm.idl \
  include/dispex.idl \
  include/docobj.idl \
  include/docobjectservice.idl \
  include/documenttarget.idl \
  include/devicetopology.idl \
  include/downloadmgr.idl \
  include/drmexternals.idl \
  include/dxva2api.idl \
  include/endpointvolume.idl \
  include/evr.idl \
  include/exdisp.idl \
  include/filter.idl \
  include/fsrm.idl \
  include/fsrmenums.idl \
  include/fsrmquota.idl \
  include/fsrmreports.idl \
  include/fsrmscreen.idl \
  include/fusion.idl \
  include/fwptypes.idl \
  include/hstring.idl \
  include/icftypes.idl \
  include/icodecapi.idl \
  include/iketypes.idl \
  include/inputscope.idl \
  include/inspectable.idl \
  include/locationapi.idl \
  include/oaidl.idl \
  include/ocidl.idl \
  include/comcat.idl \
  include/mediaobj.idl \
  include/mfidl.idl \
  include/mfobjects.idl \
  include/mfplay.idl \
  include/mfreadwrite.idl \
  include/mftransform.idl \
  include/mmdeviceapi.idl \
  include/mscoree.idl \
  include/msctf.idl \
  include/msinkaut.idl \
  include/mshtml.idl \
  include/mshtmhst.idl \
  include/msopc.idl \
  include/msxml.idl \
  include/napcertrelyingparty.idl \
  include/napcommon.idl \
  include/napenforcementclient.idl \
  include/napmanagement.idl \
  include/napprotocol.idl \
  include/napservermanagement.idl \
  include/napsystemhealthagent.idl \
  include/napsystemhealthvalidator.idl \
  include/naptypes.idl \
  include/netfw.idl \
  include/netlistmgr.idl \
  include/objectarray.idl \
  include/objidl.idl \
  include/objidlbase.idl \
  include/oleidl.idl \
  include/optary.idl \
  include/portabledevicetypes.idl \
  include/propidl.idl \
  include/propsys.idl \
  include/regbag.idl \
  include/sapi51.idl \
  include/sapi53.idl \
  include/sapi54.idl \
  include/sensorsapi.idl \
  include/servprov.idl \
  include/shldisp.idl \
  include/shobjidl.idl \
  include/shtypes.idl \
  include/strmif.idl \
  include/structuredquerycondition.idl \
  include/taskschd.idl \
  include/tpcshrd.idl \
  include/textstor.idl \
  include/tuner.idl \
  include/uianimation.idl \
  include/uiautomationclient.idl \
  include/uiautomationcore.idl \
  include/uiviewsettingsinterop.idl \
  include/unknwn.idl \
  include/unknwnbase.idl \
  include/urlmon.idl \
  include/wbemads.idl \
  include/wbemcli.idl \
  include/wbemdisp.idl \
  include/wbemprov.idl \
  include/wbemtran.idl \
  include/wdstptmgmt.idl \
  include/wincodec.idl \
  include/wmcontainer.idl \
  include/wmsbuffer.idl \
  include/wmsdkidl.idl \
  include/wsdattachment.idl \
  include/wsdbase.idl \
  include/wsdclient.idl \
  include/wsddisco.idl \
  include/wsdhost.idl \
  include/wsdxml.idl \
  include/wsmandisp.idl \
  include/wtypesbase.idl \
  include/windows.foundation.idl \
  include/windows.security.cryptography.idl \
  include/windows.storage.idl \
  include/windows.storage.streams.idl \
  include/windows.system.idl \
  include/windows.system.threading.idl \
  include/wmcodecdsp.idl \
  include/wmdrmsdk.idl \
  include/wpcapi.idl \
  include/wtypes.idl \
  include/xmllite.idl \
  include/xpsdigitalsignature.idl \
  include/xpsobjectmodel_1.idl \
  include/xpsrassvc.idl \
  include/xpsobjectmodel.idl \
  include/xpsprint.idl \
  direct-x/include/amstream.idl \
  direct-x/include/amvideo.idl \
  direct-x/include/austream.idl \
  direct-x/include/d3d10.idl \
  direct-x/include/d3d10_1.idl \
  direct-x/include/d3d10sdklayers.idl \
  direct-x/include/d3d11.idl \
  direct-x/include/d3d11_1.idl \
  direct-x/include/d3d11_2.idl \
  direct-x/include/d3d11_3.idl \
  direct-x/include/d3d11_4.idl \
  direct-x/include/d3d11sdklayers.idl \
  direct-x/include/d3dcommon.idl \
  direct-x/include/ddstream.idl \
  direct-x/include/dmodshow.idl \
  direct-x/include/dxgi.idl \
  direct-x/include/dxgi1_2.idl \
  direct-x/include/dxgi1_3.idl \
  direct-x/include/dxgi1_4.idl \
  direct-x/include/dxgi1_5.idl \
  direct-x/include/dxgi1_6.idl \
  direct-x/include/dxgicommon.idl \
  direct-x/include/dxgiformat.idl \
  direct-x/include/dxgitype.idl \
  direct-x/include/mediaobj.idl \
  direct-x/include/medparam.idl \
  direct-x/include/mmstream.idl \
  direct-x/include/qedit.idl \
  direct-x/include/qnetwork.idl \
  direct-x/include/vmr9.idl

TLB_SRCS = \
  tlb/oleacc.idl \
  tlb/stdole2.idl

BUILT_SOURCES = $(IDL_SRCS:.idl=.h) $(TLB_SRCS:.idl=.tlb)

.idl.h: crt/_mingw.h
	$(WIDL) -DBOOL=WINBOOL -I$(srcdir)/include -I$(srcdir)/direct-x/include -Icrt -I$(srcdir)/crt -h -o $@ $<

.idl.tlb:
	$(WIDL) -I$(srcdir)/include -t -o $@ $<

endif

_mingw_directx.h: $(srcdir)/crt/sdks/_mingw_directx.h.in
	$(SED) s/MINGW_HAS_DX$$/@MINGW_HAS_DX@/ $< > $@

_mingw_ddk.h: $(srcdir)/crt/sdks/_mingw_ddk.h.in
	$(SED) s/MINGW_HAS_DDK$$/@MINGW_HAS_DDK@/ $< > $@
