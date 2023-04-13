#!/bin/bash

set -e

WINE_DIR=$1

if test -z $WINE_DIR; then
    echo "Usage: wine-import.sh wine_dir"
    exit 1
fi

import_header() {
    dstfile=$2/$1
    srcfile=$WINE_DIR/include/$1
    rm -f $dstfile
    unicode_fix=
    if test -n "$(grep WINELIB_NAME_AW\\\|DECL_WINELIB_TYPE_AW $srcfile)"; then
        unicode_fix="yes"
        echo '#include <_mingw_unicode.h>' >>$dstfile
    fi
    if test -n "$(grep -w INTERFACE $srcfile)"; then
        echo '#undef INTERFACE' >>$dstfile
    fi
    cat $srcfile >>$dstfile
    if test -n "$(grep WINELIB_NAME_AW\\\|DECL_WINELIB_TYPE_AW $srcfile)"; then
        sed -i 's/\bWINELIB_NAME_AW\b/__MINGW_NAME_AW/g' $dstfile
        sed -i 's/\bDECL_WINELIB_TYPE_AW\b/__MINGW_TYPEDEF_AW/g' $dstfile
    fi
    sed -i 's/\bBOOL    /WINBOOL /g' $dstfile
    sed -i 's/\bBOOL\b/WINBOOL/g' $dstfile
    sed -i 's/DECLSPEC_HIDDEN//g' $dstfile
}

import_idl() {
    dstfile=$2/$1
    srcfile=$WINE_DIR/include/$1
    cp $srcfile $dstfile

    # HACK:
    sed -i 's/cpp_quote\(.*\)\bBOOL\b/cpp_quote\1WINBOOL/' $dstfile
    sed -i 's/cpp_quote\(.*\)\bBOOL\b/cpp_quote\1WINBOOL/' $dstfile
    sed -i 's/cpp_quote\(.*\)\bBOOL\b/cpp_quote\1WINBOOL/' $dstfile
}

# headers
for f in \
	amaudio.h \
	audevcod.h \
	corerror.h \
	d2dbasetypes.h \
	d3d10_1shader.h \
	d3d10effect.h \
	d3d10misc.h \
	d3d10shader.h \
	d3d11shader.h \
	d3d8caps.h \
	d3d8.h \
	d3d8types.h \
	d3d9caps.h \
	d3d9.h \
	d3d9types.h \
	d3dcaps.h \
	d3dcompiler.h \
	d3d.h \
	d3dhal.h \
	d3drmdef.h \
	d3drm.h \
	d3drmobj.h \
	d3dtypes.h \
	d3dvec.inl \
	d3dx9anim.h \
	d3dx9core.h \
	d3dx9effect.h \
	d3dx9.h \
	d3dx9math.h \
	d3dx9math.inl \
	d3dx9mesh.h \
	d3dx9shader.h \
	d3dx9shape.h \
	d3dx9tex.h \
	d3dx9xof.h \
	devpkey.h \
	dls1.h \
	dls2.h \
	dmerror.h \
	dmo.h \
	dmoreg.h \
	dmort.h \
	dmplugin.h \
	dmusbuff.h \
	dmusicc.h \
	dmusicf.h \
	dmusici.h \
	dmusics.h \
	dpaddr.h \
	dplay8.h \
	dplay.h \
	dplobby8.h \
	dplobby.h \
	dpnathlp.h \
	dsconf.h \
	dshow.h \
	dvdmedia.h \
	dxdiag.h \
	dxerr8.h \
	dxerr9.h \
	dxfile.h \
	dxva.h \
	errors.h \
	evcode.h \
	exdispid.h \
	fontsub.h \
	mediaerr.h \
	mscat.h \
	msxml2did.h \
	msxml6did.h \
	propkeydef.h \
	propkey.h \
	propvarutil.h \
	rpcsal.h \
	t2embapi.h \
	uiautomationcoreapi.h \
	uiautomation.h \
	vfwmsgs.h \
	winhttp.h \
	winineti.h \
	wmpids.h \
	xapofx.h \
	xinput.h; do
    import_header $f include
done

# IDLs
for f in \
	amstream \
	amvideo \
	asyncinfo \
	austream \
	bits \
	bits1_5 \
	bits2_0 \
	bits2_5 \
	bits3_0 \
	bits5_0 \
	ctfutb \
	ctxtcall \
	d3d10 \
	d3d10_1 \
	d3d10sdklayers \
	d3d11 \
	d3d11on12 \
	d3d11_1 \
	d3d11_2 \
	d3d11_3 \
	d3d11_4 \
	d3d11sdklayers \
	d3d12 \
	d3d12sdklayers \
	d3d12shader \
	d3dcommon \
	dcommon \
	ddstream \
	devicetopology \
	directmanipulation \
	downloadmgr \
	drmexternals \
	dvdif \
	dwrite \
	dwrite_1 \
	dwrite_2 \
	dwrite_3 \
	dxgi \
	dxgi1_2 \
	dxgi1_3 \
	dxgi1_4 \
	dxgi1_5 \
	dxgi1_6 \
	dxgicommon \
	dxgidebug \
	dxgiformat \
	dxgitype \
	dxva2api \
	endpointvolume \
	eventtoken \
	evr9 \
	exdisp \
	fusion \
	icftypes \
	ivectorchangedeventargs \
	mediaobj \
	mfreadwrite \
	mftransform \
	mmdeviceapi \
	mmstream \
	mscoree \
	msctf \
	msxml \
	msxml2 \
	msxml6 \
	mulres \
	netfw \
	netlistmgr \
	objectarray \
	optary \
	proofofpossessioncookieinfo \
	qedit \
	relogger \
	rtworkq \
	spatialaudioclient \
	taskschd \
	textstor \
	thumbcache \
	uiautomationclient \
	uiautomationcore \
	urlhist \
	vmr9 \
	wincodec \
	wincodecsdk \
	windowscontracts \
	windows.devices.enumeration \
	windows.devices.haptics \
	windows.devices.power \
	windows.foundation \
	windows.foundation.collections \
	windows.foundation.metadata \
	windows.foundation.numerics \
	windows.gaming.input \
	windows.gaming.input.custom \
	windows.gaming.input.forcefeedback \
	windows.gaming.ui \
	windows.globalization \
	windows.graphics.capture \
	windows.graphics.directx \
	windows.graphics.directx.direct3d11 \
	windows.graphics.effects \
	windows.graphics.holographic \
	windows.media \
	windows.media.closedcaptioning \
	windows.media.devices \
	windows.media.speechrecognition \
	windows.media.speechsynthesis \
	windows.perception.spatial \
	windows.perception.spatial.surfaces \
	windows.security.credentials \
	windows.security.cryptography \
	windows.storage.streams \
	windows.system \
	windows.system.power \
	windows.system.profile.systemmanufacturers \
	windows.system.threading \
	windows.system.userprofile \
	windows.ui \
	windows.ui.composition \
	windows.ui.composition.interop \
	windows.ui.core \
	windows.ui.viewmanagement \
	wmdrmsdk \
	wmp \
	wmprealestate \
	wmpservices \
	wmsbuffer \
	wmsdkidl \
	wmsecure \
	wpcapi \
	wuapi \
	xapo \
	xaudio2 \
	xaudio2fx \
	xmldom \
	xmldso \
	xmllite; do
    import_idl $f.idl include
done

echo Import complete. You need to update headers generated from IDL files now:
echo '$ ./configure --with-widl --host=i686-w64-mingw32 && make && make distclean'

