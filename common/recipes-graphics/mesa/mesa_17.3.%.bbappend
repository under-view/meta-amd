FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

DEPENDS_append_amd = " libvdpau libomxil"

PACKAGECONFIG[va] = "--enable-va,--disable-va,libva"
PACKAGECONFIG_append_amd = " xvmc gallium r600 gallium-llvm xa osmesa"
PACKAGECONFIG_append_radeon = " va"
PACKAGECONFIG_append_amdgpu = " va"
PACKAGECONFIG_remove_amdfalconx86 = "xvmc"
PACKAGECONFIG_remove_amd = "vulkan"

LIBVA_PLATFORMS  = "libva"
LIBVA_PLATFORMS .= "${@bb.utils.contains('DISTRO_FEATURES', 'x11', ' libva-x11', '', d)}"
LIBVA_PLATFORMS .= "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', ' libva-wayland', '', d)}"
LIBVA_PLATFORMS .= "${@bb.utils.contains('DISTRO_FEATURES', 'opengl', ' libva-gl', '', d)}"
RDEPENDS_mesa-megadriver += "${@bb.utils.contains('PACKAGECONFIG', 'va', '${LIBVA_PLATFORMS}', '', d)}"

SRC_URI_append_amd = "\
			file://0001-fix-building-with-flex-2.6.2.patch \
			file://0001-configure.ac-for-llvm-config-to-report-correct-libdi.patch \
			file://0002-configure.ac-fix-the-llvm-version-correctly.patch \
			file://0003-strip-llvm-ldflags.patch \
			file://0004-egd_tables.py-fix-compatibility-with-python-versions.patch \
"

EXTRA_OECONF_append_amd = " \
		 --enable-vdpau \
		 --enable-glx \
		 --enable-texture-float \
		 --enable-omx-bellagio \
		 --with-omx-bellagio-libdir=${libdir}/bellagio \
		"

# Package all the libXvMC gallium extensions together
# they provide the shared lib libXvMCGallium and splitting
# them up creates trouble in rpm packaging
PACKAGES =+ "libxvmcgallium-${PN} libxvmcgallium-${PN}-dev"
FILES_libxvmcgallium-${PN} = "${libdir}/libXvMC*${SOLIBS}"
FILES_libxvmcgallium-${PN}-dev = "${libdir}/libXvMC*${SOLIBSDEV} \
                               ${libdir}/libXvMC*.la"

PACKAGES =+ "libvdpau-${PN} libvdpau-${PN}-dev"
FILES_libvdpau-${PN} = "${libdir}/vdpau/libvdpau*${SOLIBS}"
FILES_libvdpau-${PN}-dev = "${libdir}/vdpau/libvdpau*${SOLIBSDEV} \
                            ${libdir}/vdpau/libvdpau*.la"
FILES_${PN}-dbg += "${libdir}/vdpau/.debug"

#
# libomx files are non-versioned so we put *.so directly in the
# main package as opposed to the -dev package.
#
PACKAGES =+ "libomx-${PN} libomx-${PN}-dev"
FILES_libomx-${PN} = "${libdir}/bellagio/libomx_*.so"
FILES_libomx-${PN}-dev = "${libdir}/bellagio/libomx_*.la"
FILES_${PN}-dbg += "${libdir}/bellagio/.debug"

# Set DRIDRIVERS with anonymous python so we can effectively
# override the _append_x86-64 assignement from mesa.inc.
python () {
    d.setVar("DRIDRIVERS", "swrast,radeon")
    d.setVar("GALLIUMDRIVERS", "swrast,r300,r600,radeonsi")
}