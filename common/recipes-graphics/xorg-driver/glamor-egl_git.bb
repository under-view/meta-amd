require recipes-graphics/xorg-driver/xorg-driver-common.inc

DEPENDS += "libdrm virtual/mesa virtual/libgles1 virtual/libgles2 virtual/egl"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI = " \
	git://anongit.freedesktop.org/xorg/driver/glamor;branch=master \
	file://0001-Rework-pkgconfig-files-using-Requires.patch \
"
SRCREV = "347ef4f01edba49820eefaf4b25522fc260d118c"

LIC_FILES_CHKSUM = "file://COPYING;md5=c7f5e33031114ad132cb03949d73a8a8"

SRC_URI[md5sum] = "b3668594675f71a75153ee52dbd35535"
SRC_URI[sha256sum] = "66531b56e6054eb53daa7bd57eb6358a7ead1b84f63419606e69d1092365e5c9"

S = "${WORKDIR}/git"

inherit autotools pkgconfig

EXTRA_OECONF += "--prefix=${prefix} \
		 --sysconfdir=${sysconfdir} \
		 --localstatedir=${localstatedir} \
		 --enable-glx-tls"

FILES_${PN} += "${datadir}/X11/xorg.conf.d ${libdir}/xorg/modules/lib*${SOLIBSDEV}"
FILES_${PN}-dbg += "${libdir}/xorg/modules/.debug"