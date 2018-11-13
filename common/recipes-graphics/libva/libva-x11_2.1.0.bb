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

SRC_URI[md5sum] = "9d6e4f1d36c407566343e9dde5a972b8"
SRC_URI[sha256sum] = "f3fa953a11d3210c3a4ee79031abdbe0863d5ce13d9b3f93f315f1eec60a4b0f"

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
