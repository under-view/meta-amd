SUMMARY = "Package for dependency resolution between Mesa and Libva"
DESCRIPTION = "There exists a cyclic dependency between Mesa and Libva \
	       when libva is built with glx enabled and mesa \
	       is enabling its vaapi backend. This package strives \
	       to cover up the dependency chain, by building the x11 components \
               of libva separately. So, libva-x11 -> mesa -> libva"

HOMEPAGE = "https://01.org/linuxmedia/vaapi"
BUGTRACKER = "https://github.com/intel/libva/issues"

SECTION = "x11"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=2e48940f94acb0af582e5ef03537800f"

inherit autotools pkgconfig

SRC_URI = "https://github.com/intel/${BPN}/releases/download/libva/libva-${PV}.tar.bz2"

SRC_URI[md5sum] = "cfc69c2a5f526dd1858e098fb8eebfa6"
SRC_URI[sha256sum] = "99263056c21593a26f2ece812aee6fe60142b49e6cd46cb33c8dddf18fc19391"

S = "${WORKDIR}/libva-${PV}"

DEPENDS = "libdrm virtual/mesa virtual/libx11 libxext libxfixes"

EXTRA_OECONF = "--disable-wayland --disable-drm --enable-x11 --enable-glx"

FILES_${PN}-dbg += "${libdir}/dri/.debug"

do_install_append(){
    # Remove all the additional components that can cause a conflict with the
    # actual libva package.
    rm -rf ${D}${libdir}/libva.*
    rm -rf ${D}${libdir}/pkgconfig/libva.*
    cd ${D}${includedir}/va
    rm -f va_dec_hevc.h va_enc_h264.h va_enc_vp8.h va_fei_hevc.h \
          va_tpi.h va_backend.h va_dec_jpeg.h va_enc_hevc.h \
          va_enc_vp9.h va_version.h va_backend_vpp.h va_dec_vp8.h \
          va_drmcommon.h va_enc_jpeg.h va_fei.h va.h va_vpp.h \
          va_compat.h va_dec_vp9.h va_egl.h va_enc_mpeg2.h \
          va_fei_h264.h va_str.h
    cd -
}
