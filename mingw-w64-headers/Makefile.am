
baseheaddir = $(includedir)
sysheaddir = $(baseheaddir)/sys
secheaddir = $(baseheaddir)/sec_api
secsysheaddir = $(baseheaddir)/sec_api/sys
glheaddir = $(baseheaddir)/GL
gdiplusheaddir = $(baseheaddir)/gdiplus
mingwhelperheaddir = $(baseheaddir)/psdk_inc
sdksheaddir = $(baseheaddir)/sdks

basehead_HEADERS = @BASEHEAD_LIST@
syshead_HEADERS = @SYSHEAD_LIST@
sechead_HEADERS = @SECHEAD_LIST@
secsyshead_HEADERS = @SECSYSHEAD_LIST@
glhead_HEADERS = @GLHEAD_LIST@
gdiplushead_HEADERS = @GDIPLUSHEAD_LIST@
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

EXTRA_DIST = $(srcdir)/ChangeLog.* include crt direct-x ddk

dist-hook:
	find $(distdir) -name ".svn" -type d -delete

EXTRA_HEADERS = \
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
  crt/*.h \
  crt/*.inl \
  crt/sys/*.h \
  crt/sec_api/*.h \
  crt/sec_api/sys/*.h \
  direct-x/include/*.h \
  direct-x/include/*.idl \
  ddk/include/ddk/*.h

if HAVE_WIDL

IDL_SRCS = \
  include/activation.idl \
  include/activaut.idl \
  include/activprof.idl \
  include/activscp.idl \
  include/audioclient.idl \
  include/audioendpoints.idl \
  include/audiopolicy.idl \
  include/control.idl \
  include/ctfutb.idl \
  include/dbgprop.idl \
  include/docobj.idl \
  include/devicetopology.idl \
  include/downloadmgr.idl \
  include/dxva2api.idl \
  include/endpointvolume.idl \
  include/fusion.idl \
  include/fwptypes.idl \
  include/hstring.idl \
  include/icodecapi.idl \
  include/iketypes.idl \
  include/inputscope.idl \
  include/inspectable.idl \
  include/oaidl.idl \
  include/ocidl.idl \
  include/comcat.idl \
  include/mediaobj.idl \
  include/mfidl.idl \
  include/mfobjects.idl \
  include/mfreadwrite.idl \
  include/mftransform.idl \
  include/mmdeviceapi.idl \
  include/mscoree.idl \
  include/msctf.idl \
  include/msopc.idl \
  include/msxml.idl \
  include/objectarray.idl \
  include/objidl.idl \
  include/objidlbase.idl \
  include/oleidl.idl \
  include/optary.idl \
  include/portabledevicetypes.idl \
  include/propidl.idl \
  include/propsys.idl \
  include/sapi51.idl \
  include/sapi53.idl \
  include/sapi54.idl \
  include/sensorsapi.idl \
  include/servprov.idl \
  include/shobjidl.idl \
  include/shtypes.idl \
  include/strmif.idl \
  include/structuredquerycondition.idl \
  include/tpcshrd.idl \
  include/textstor.idl \
  include/uiautomationclient.idl \
  include/uiautomationcore.idl \
  include/unknwn.idl \
  include/unknwnbase.idl \
  include/urlmon.idl \
  include/wbemcli.idl \
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
  include/windows.system.threading.idl \
  include/wmcodecdsp.idl \
  include/wpcapi.idl \
  include/wtypes.idl \
  include/xmllite.idl \
  include/xpsdigitalsignature.idl \
  direct-x/include/amstream.idl \
  direct-x/include/amvideo.idl \
  direct-x/include/austream.idl \
  direct-x/include/d3d10.idl \
  direct-x/include/d3d10_1.idl \
  direct-x/include/d3d11.idl \
  direct-x/include/d3d11sdklayers.idl \
  direct-x/include/d3dcommon.idl \
  direct-x/include/ddstream.idl \
  direct-x/include/dmodshow.idl \
  direct-x/include/dxgi.idl \
  direct-x/include/mediaobj.idl \
  direct-x/include/medparam.idl \
  direct-x/include/mmstream.idl \
  direct-x/include/qedit.idl \
  direct-x/include/qnetwork.idl \
  direct-x/include/vmr9.idl

BUILT_SOURCES = $(IDL_SRCS:.idl=.h)

.idl.h: crt/_mingw.h
	$(WIDL) -DBOOL=WINBOOL -I$(srcdir)/include -I$(srcdir)/direct-x/include -Icrt -I$(srcdir)/crt -h -o $@ $<

endif

_mingw_directx.h: $(srcdir)/crt/sdks/_mingw_directx.h.in
	$(SED) s/MINGW_HAS_DX$$/@MINGW_HAS_DX@/ $< > $@

_mingw_ddk.h: $(srcdir)/crt/sdks/_mingw_ddk.h.in
	$(SED) s/MINGW_HAS_DDK$$/@MINGW_HAS_DDK@/ $< > $@
