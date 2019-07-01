#!/bin/bash

set -e

WINE_DIR=$1

if test -z $WINE_DIR; then
    echo "Usage: wine-impot.sh wine_dir"
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
	corerror.h \
	mscat.h \
	propkey.h \
	propkeydef.h \
	rpcsal.h \
	t2embapi.h \
	uiautomation.h \
	uiautomationcoreapi.h \
	winhttp.h \
	winineti.h; do
    import_header $f include
done

# IDLs
for f in \
	ctfutb \
	devicetopology \
	downloadmgr \
	drmexternals \
	endpointvolume \
	fusion \
	icftypes \
	mmdeviceapi \
	mscoree \
	msctf \
	netfw \
	netlistmgr \
	objectarray \
	optary \
	taskschd \
	uiautomationclient \
	uiautomationcore \
	urlhist \
	wmdrmsdk \
	wmsbuffer \
	wmsdkidl \
	wpcapi \
	xmllite; do
    import_idl $f.idl include
done

# DirectX headers
for f in \
	amaudio.h \
	audevcod.h \
	d3d.h \
	d3d10_1shader.h \
	d3d10effect.h \
	d3d10misc.h \
	d3d10shader.h \
	d3d11shader.h \
	d3d8.h \
	d3d8caps.h \
	d3d8types.h \
	d3d9.h \
	d3d9caps.h \
	d3d9types.h \
	d3dcaps.h \
	d3dcompiler.h \
	d3dhal.h \
	d3drm.h \
	d3drmdef.h \
	d3drmobj.h \
	d3dtypes.h \
	d3dx9.h \
	d3dx9anim.h \
	d3dx9core.h \
	d3dx9effect.h \
	d3dx9math.h \
	d3dx9math.inl \
	d3dx9mesh.h \
	d3dx9shader.h \
	d3dx9shape.h \
	d3dx9tex.h \
	d3dx9xof.h \
	d3dvec.inl \
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
	dplay.h \
	dplay8.h \
	dplobby.h \
	dplobby8.h \
	dpnathlp.h \
	dshow.h \
	dvdmedia.h \
	dxdiag.h \
	dxerr8.h \
	dxerr9.h \
	dxfile.h \
	errors.h \
	evcode.h \
	mediaerr.h \
	vfwmsgs.h \
	xinput.h; do
    import_header $f direct-x/include
done

# DirectX IDLs
for f in \
	amstream \
	amvideo \
	austream \
	d3d10 \
	d3d10_1 \
	d3d10sdklayers \
	d3d11 \
	d3d11_1 \
	d3d11_2 \
	d3d11_3 \
	d3d11_4 \
	d3d11sdklayers \
	d3dcommon \
	ddstream \
	dxgi \
	dxgi1_2 \
	dxgi1_3 \
	dxgi1_4 \
	dxgi1_5 \
	dxgi1_6 \
	mediaobj \
	dxgicommon \
	dxgiformat \
	dxgitype \
	mmstream \
	qedit; do
    import_idl $f.idl direct-x/include
done

echo Import complete. You need to update headers generated from IDL files now:
echo $ ./configure --with-widl --host=i686-w64-mingw32
echo $ make
echo $ make distclean

