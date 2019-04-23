SUMMARY = "Open Source multimedia player"
DESCRIPTION = "mpv is a fork of mplayer2 and MPlayer. It shares some features with the former projects while introducing many more."
SECTION = "multimedia"
HOMEPAGE = "http://www.mpv.io/"
DEPENDS = "zlib ffmpeg jpeg virtual/libx11 xsp libxv \
           libxscrnsaver libv4l libxinerama \
"

REQUIRED_DISTRO_FEATURES = "x11"

LICENSE = "GPLv2+"
LIC_FILES_CHKSUM = "file://LICENSE.GPL;md5=91f1cb870c1cc2d31351a4d2595441cb"

# While this item does not require it, it depends on ffmpeg which does
LICENSE_FLAGS = "commercial"

SRC_URI = " \
    https://github.com/mpv-player/mpv/archive/v${PV}.tar.gz;name=mpv \
    http://www.freehackers.org/~tnagy/release/waf-1.9.8;name=waf;downloadfilename=waf;subdir=${BPN}-${PV} \
"
SRC_URI[mpv.md5sum] = "b6538dec29a2a69574f4e3a3d688fb8b"
SRC_URI[mpv.sha256sum] = "aada14e025317b5b3e8e58ffaf7902e8b6e4ec347a93d25a7c10d3579426d795"
SRC_URI[waf.md5sum] = "fbb646eafa430f959743010c85e269be"
SRC_URI[waf.sha256sum] = "167dc42bab6d5bd823b798af195420319cb5c9b571e00db7d83df2a0fe1f4dbf"

inherit waf pkgconfig pythonnative distro_features_check

# Note: both lua and libass are required to get on-screen-display (controls)
PACKAGECONFIG ??= " \
    lua \
    libass \
    ${@bb.utils.filter('DISTRO_FEATURES', 'wayland', d)} \
"
PACKAGECONFIG[drm] = "--enable-drm,--disable-drm,libdrm"
PACKAGECONFIG[gbm] = "--enable-gbm,--disable-gbm,virtual/mesa"
PACKAGECONFIG[lua] = "--enable-lua,--disable-lua,lua luajit"
PACKAGECONFIG[libass] = "--enable-libass,--disable-libass,libass"
PACKAGECONFIG[libarchive] = "--enable-libarchive,--disable-libarchive,libarchive"
PACKAGECONFIG[jack] = "--enable-jack, --disable-jack, jack"
PACKAGECONFIG[vaapi] = "--enable-vaapi, --disable-vaapi,libva"
PACKAGECONFIG[vdpau] = "--enable-vdpau, --disable-vdpau,libvdpau"
PACKAGECONFIG[wayland] = "--enable-wayland, --disable-wayland,wayland libxkbcommon"

SIMPLE_TARGET_SYS = "${@'${TARGET_SYS}'.replace('${TARGET_VENDOR}', '')}"

EXTRA_OECONF = " \
    --prefix=${prefix} \
    --target=${SIMPLE_TARGET_SYS} \
    --confdir=${sysconfdir} \
    --datadir=${datadir} \
    --disable-manpage-build \
    --disable-gl \
    --disable-libsmbclient \
    --disable-encoding \
    --disable-libbluray \
    --disable-dvdread \
    --disable-dvdnav \
    --disable-cdda \
    --disable-uchardet \
    --disable-rubberband \
    --disable-lcms2 \
    --disable-vapoursynth \
    --disable-vapoursynth-lazy \
    ${PACKAGECONFIG_CONFARGS} \
"

adjust_waf_perms() {
    chmod +x ${S}/waf
}

do_patch[postfuncs] += "adjust_waf_perms"

FILES_${PN} += "${datadir}/icons"
