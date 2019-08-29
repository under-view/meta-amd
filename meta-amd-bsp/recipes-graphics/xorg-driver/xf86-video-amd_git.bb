SUMMARY = "X.Org X server -- AMD graphics chipsets driver"

DESCRIPTION = "xf86-video-amd is an Xorg driver for AMD integrated	\
graphics chipsets. The driver supports depths 8, 15, 16 and 24. On	\
some chipsets, the driver supports hardware accelerated 3D via the	\
Direct Rendering Infrastructure (DRI)."

require recipes-graphics/xorg-driver/xorg-driver-video.inc

LIC_FILES_CHKSUM = "file://COPYING;md5=aabff1606551f9461ccf567739af63dc"

DEPENDS += "virtual/libx11 drm xorgproto \
	    virtual/libgl libpciaccess \
"

PACKAGECONFIG[udev] = "--enable-udev,--disable-udev,udev"
PACKAGECONFIG[glamor] = "--enable-glamor,--disable-glamor"

SRC_URI_radeon = "git://anongit.freedesktop.org/git/xorg/driver/xf86-video-ati"
SRCREV_radeon = "5cbe1ee8e499e1b6b2646e341946292721d07e69"
PV_radeon = "radeon-7.8.0"
PACKAGECONFIG_append_radeon = " udev glamor"

SRC_URI_amdgpu = "git://anongit.freedesktop.org/xorg/driver/xf86-video-amdgpu"
SRCREV_amdgpu = "98f172eb2d2353e19edd8167f22215ce596811f8"
PV_amdgpu = "amdgpu-19.0.1"
PACKAGECONFIG_append_amdgpu = " udev glamor"

PV = "git${SRCPV}"

S = "${WORKDIR}/git"

RDEPENDS_${PN} += "mesa-driver-radeon \
		   mesa-driver-radeonsi \
		   mesa-driver-swrast \
"

COMPATIBLE_HOST = '(i.86|x86_64).*-linux'

PACKAGES += "${PN}-conf"
FILES_${PN}-conf = "${datadir}/X11"
