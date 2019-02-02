SRCREV_r1000 = "0144bbdb98f515cce31688fce57d769e7fd82d52"
LIC_FILES_CHKSUM_r1000 = "file://docs/license.html;md5=725f991a1cc322aa7a0cd3a2016621c4"
PV_r1000 = "19.0.0+git${SRCPV}"

MESA_LLVM_RELEASE_r1000 = "7"

SRC_URI_remove_r1000 = "git://anongit.freedesktop.org/mesa/mesa;branch=18.1"
SRC_URI_append_r1000 = " git://anongit.freedesktop.org/mesa/mesa;branch=master"

# mesa dri drivers fail to load with -O2
# which is what is used unless debug build
# is enabled.
DEBUG_BUILD = "1"

PACKAGECONFIG_append_r1000 = " dri3"

EXTRA_OECONF_remove_r1000 = "--enable-texture-float"

PACKAGES += "${PN}-driconfigs"
FILES_${PN}-driconfigs += "${datadir}/drirc.d/*"
