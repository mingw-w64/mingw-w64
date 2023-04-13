
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
nodist_sdkshead_HEADERS = _mingw_ddk.h
noinst_HEADERS = crt/sdks/_mingw_ddk.h.in

ddkheaddir = $(baseheaddir)/ddk
idlheaddir = $(baseheaddir)

ddkhead_HEADERS = @DDKHEAD_LIST@
idlhead_HEADERS = @IDLHEAD_LIST@

CLEANFILES = $(nodist_sdkshead_HEADERS)

DISTCHECK_CONFIGURE_FLAGS = --enable-crt --enable-sdk=all --enable-idl

EXTRA_DIST = $(srcdir)/ChangeLog.* include crt ddk tlb

dist-hook:
	find $(distdir) -name ".svn" -type d -delete

EXTRA_HEADERS = \
  include/*.c \
  include/*.dlg \
  include/*.h \
  include/*.h16 \
  include/*.hxx \
  include/*.idl \
  include/*.inl \
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
  include/amstream.idl \
  include/amvideo.idl \
  include/asyncinfo.idl \
  include/audioclient.idl \
  include/audioendpoints.idl \
  include/audiopolicy.idl \
  include/austream.idl \
  include/bdaiface.idl \
  include/bits.idl \
  include/bits1_5.idl \
  include/bits2_0.idl \
  include/bits2_5.idl \
  include/bits3_0.idl \
  include/bits5_0.idl \
  include/comadmin.idl \
  include/commoncontrols.idl \
  include/control.idl \
  include/credentialprovider.idl \
  include/ctfutb.idl \
  include/ctxtcall.idl \
  include/d3d10.idl \
  include/d3d10_1.idl \
  include/d3d10sdklayers.idl \
  include/d3d11.idl \
  include/d3d11_1.idl \
  include/d3d11_2.idl \
  include/d3d11_3.idl \
  include/d3d11_4.idl \
  include/d3d11on12.idl \
  include/d3d11sdklayers.idl \
  include/d3d12.idl \
  include/d3d12sdklayers.idl \
  include/d3d12shader.idl \
  include/d3dcommon.idl \
  include/dbgprop.idl \
  include/dcommon.idl \
  include/dcompanimation.idl \
  include/ddstream.idl \
  include/dinputd.idl \
  include/dimm.idl \
  include/directmanipulation.idl \
  include/dispex.idl \
  include/dmodshow.idl \
  include/docobj.idl \
  include/docobjectservice.idl \
  include/documenttarget.idl \
  include/devicetopology.idl \
  include/downloadmgr.idl \
  include/drmexternals.idl \
  include/dvdif.idl \
  include/dwrite.idl \
  include/dwrite_1.idl \
  include/dwrite_2.idl \
  include/dwrite_3.idl \
  include/dxgi.idl \
  include/dxgi1_2.idl \
  include/dxgi1_3.idl \
  include/dxgi1_4.idl \
  include/dxgi1_5.idl \
  include/dxgi1_6.idl \
  include/dxgicommon.idl \
  include/dxgidebug.idl \
  include/dxgiformat.idl \
  include/dxgitype.idl \
  include/dxva2api.idl \
  include/dxvahd.idl \
  include/endpointvolume.idl \
  include/eventtoken.idl \
  include/evr.idl \
  include/evr9.idl \
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
  include/ivectorchangedeventargs.idl \
  include/locationapi.idl \
  include/oaidl.idl \
  include/ocidl.idl \
  include/comcat.idl \
  include/mediaobj.idl \
  include/mfcaptureengine.idl \
  include/mfd3d12.idl \
  include/mfidl.idl \
  include/mfmediacapture.idl \
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
  include/msxml2.idl \
  include/msxml6.idl \
  include/napcertrelyingparty.idl \
  include/napcommon.idl \
  include/napenforcementclient.idl \
  include/napmanagement.idl \
  include/napprotocol.idl \
  include/napservermanagement.idl \
  include/napsystemhealthagent.idl \
  include/napsystemhealthvalidator.idl \
  include/naptypes.idl \
  include/netcfgn.idl \
  include/netcfgx.idl \
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
  include/rdpencomapi.idl \
  include/regbag.idl \
  include/sapi51.idl \
  include/sapi53.idl \
  include/sapi54.idl \
  include/sensorsapi.idl \
  include/servprov.idl \
  include/shldisp.idl \
  include/shobjidl.idl \
  include/shtypes.idl \
  include/spatialaudioclient.idl \
  include/spellcheck.idl \
  include/strmif.idl \
  include/structuredquerycondition.idl \
  include/systemmediatransportcontrolsinterop.idl \
  include/taskschd.idl \
  include/textstor.idl \
  include/thumbcache.idl \
  include/tlbref.idl \
  include/tlogstg.idl \
  include/tpcshrd.idl \
  include/tsvirtualchannels.idl \
  include/tuner.idl \
  include/uianimation.idl \
  include/uiautomationclient.idl \
  include/uiautomationcore.idl \
  include/uiviewsettingsinterop.idl \
  include/unknwn.idl \
  include/unknwnbase.idl \
  include/urlhist.idl \
  include/urlmon.idl \
  include/vdslun.idl \
  include/vidcap.idl \
  include/vsadmin.idl \
  include/vsbackup.idl \
  include/vsmgmt.idl \
  include/vsprov.idl \
  include/vss.idl \
  include/vswriter.idl \
  include/wbemads.idl \
  include/wbemcli.idl \
  include/wbemdisp.idl \
  include/wbemprov.idl \
  include/wbemtran.idl \
  include/wdstptmgmt.idl \
  include/mediaobj.idl \
  include/medparam.idl \
  include/mmstream.idl \
  include/proofofpossessioncookieinfo.idl \
  include/qedit.idl \
  include/qnetwork.idl \
  include/relogger.idl \
  include/robuffer.idl \
  include/rtworkq.idl \
  include/vmr9.idl \
  include/wincodec.idl \
  include/wincodecsdk.idl \
  include/wmcontainer.idl \
  include/wmp.idl \
  include/wmprealestate.idl \
  include/wmpservices.idl \
  include/wmsbuffer.idl \
  include/wmsdkidl.idl \
  include/wmsecure.idl \
  include/wsdattachment.idl \
  include/wsdbase.idl \
  include/wsdclient.idl \
  include/wsddisco.idl \
  include/wsdhost.idl \
  include/wsdxml.idl \
  include/wsmandisp.idl \
  include/wtypesbase.idl \
  include/windows.devices.enumeration.idl \
  include/windows.devices.haptics.idl \
  include/windows.devices.power.idl \
  include/windows.foundation.idl \
  include/windows.foundation.collections.idl \
  include/windows.foundation.metadata.idl \
  include/windows.foundation.numerics.idl \
  include/windows.gaming.input.idl \
  include/windows.gaming.input.custom.idl \
  include/windows.gaming.input.forcefeedback.idl \
  include/windows.gaming.ui.idl \
  include/windows.globalization.idl \
  include/windows.graphics.capture.idl \
  include/windows.graphics.directx.idl \
  include/windows.graphics.directx.direct3d11.idl \
  include/windows.graphics.effects.idl \
  include/windows.graphics.holographic.idl \
  include/windows.media.idl \
  include/windows.media.closedcaptioning.idl \
  include/windows.media.devices.idl \
  include/windows.media.speechrecognition.idl \
  include/windows.media.speechsynthesis.idl \
  include/windows.perception.spatial.idl \
  include/windows.perception.spatial.surfaces.idl \
  include/windows.security.credentials.idl \
  include/windows.security.cryptography.idl \
  include/windows.storage.idl \
  include/windows.storage.streams.idl \
  include/windows.system.idl \
  include/windows.system.power.idl \
  include/windows.system.profile.systemmanufacturers.idl \
  include/windows.system.threading.idl \
  include/windows.system.userprofile.idl \
  include/windows.ui.idl \
  include/windows.ui.composition.idl \
  include/windows.ui.composition.interop.idl \
  include/windows.ui.core.idl \
  include/windows.ui.viewmanagement.idl \
  include/windowscontracts.idl \
  include/wmcodecdsp.idl \
  include/wmdrmsdk.idl \
  include/wpcapi.idl \
  include/wtypes.idl \
  include/wuapi.idl \
  include/xapo.idl \
  include/xaudio2.idl \
  include/xaudio2fx.idl \
  include/xmllite.idl \
  include/xpsdigitalsignature.idl \
  include/xpsobjectmodel_1.idl \
  include/xpsrassvc.idl \
  include/xpsobjectmodel.idl \
  include/xpsprint.idl

TLB_SRCS = \
  tlb/oleacc.dll.idl \
  tlb/stdole2.idl

BUILT_SOURCES = $(IDL_SRCS:.idl=.h) $(TLB_SRCS:.idl=.tlb)

%.h: %.idl crt/_mingw.h
	$(WIDL) -DBOOL=WINBOOL -I$(srcdir)/include -Icrt -I$(srcdir)/crt -h -o $@ $<

%.tlb: %.idl
	$(WIDL) -I$(srcdir)/include -L$(srcdir)/tlb -t -o $@ $<

%_i.c: %.idl crt/_mingw.h
	$(WIDL) -DBOOL=WINBOOL -I$(srcdir)/include -Icrt -I$(srcdir)/crt -u -o $@ $<

# following headers are not meant to be generated from IDLs, so override default rule
include/prsht.h: ;
include/wincrypt.h: ;

endif

_mingw_ddk.h: $(srcdir)/crt/sdks/_mingw_ddk.h.in
	$(SED) s/MINGW_HAS_DDK$$/@MINGW_HAS_DDK@/ $< > $@
