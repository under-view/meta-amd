DEPENDS_append_amd = " libvdpau libomxil"

PACKAGECONFIG[va] = "-Dgallium-va=true,-Dgallium-va=false,libva"
PACKAGECONFIG_append_amd = " xvmc gallium r600 gallium-llvm xa osmesa"
PACKAGECONFIG_append_radeon = " va"
PACKAGECONFIG_append_amdgpu = " va"

PACKAGECONFIG_remove_amd = "vulkan"
PACKAGECONFIG_remove_amdfalconx86 = "xvmc"

LIBVA_PLATFORMS  = "libva"
LIBVA_PLATFORMS .= "${@bb.utils.contains('DISTRO_FEATURES', 'x11', ' libva-x11', '', d)}"
LIBVA_PLATFORMS .= "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', ' libva-wayland', '', d)}"
RDEPENDS_mesa-megadriver += "${@bb.utils.contains('PACKAGECONFIG', 'va', '${LIBVA_PLATFORMS}', '', d)}"

EXTRA_OEMESON_append_amd = " \
		 -Dgallium-vdpau=true \
		 -Dglx=dri \
		 -Dgallium-omx=bellagio \
		 -Domx-libs-path=${libdir}/bellagio"

# Package all the libXvMC gallium extensions together
# they provide the shared lib libXvMCGallium and splitting
# them up creates trouble in rpm packaging
#
# libXvMC files are non-versioned so we put *.so directly in the
# main package as opposed to the -dev package.
#
PACKAGES =+ "libxvmcgallium-${PN} libxvmcgallium-${PN}-dev"
FILES_libxvmcgallium-${PN} = "${libdir}/libXvMC*.so"
FILES_libxvmcgallium-${PN}-dev = "${libdir}/libXvMC*.la"


PACKAGES =+ "libvdpau-${PN} libvdpau-${PN}-dev"
FILES_libvdpau-${PN} = "${libdir}/vdpau/libvdpau*${SOLIBS}"
FILES_libvdpau-${PN}-dev = "${libdir}/vdpau/libvdpau*${SOLIBSDEV} \
                            ${libdir}/vdpau/libvdpau*.la"
FILES_${PN}-dbg += "${libdir}/vdpau/.debug"

#
# libomx files are non-versioned so we put *.so directly in the
# main package as opposed to the -dev package.
#
PACKAGES =+ "libomx-${PN} libomx-${PN}-dev ${PN}-driconfigs"
FILES_libomx-${PN} = "${libdir}/bellagio/libomx_*.so"
FILES_libomx-${PN}-dev = "${libdir}/bellagio/libomx_*.la"
FILES_${PN}-driconfigs = "${datadir}/drirc.d/*"
FILES_${PN}-dbg += "${libdir}/bellagio/.debug"

# Set GALLIUMDRIVERS with anonymous python so we can effectively
# override the _append_x86-64 assignement from mesa.inc.
python () {
    d.setVar("GALLIUMDRIVERS", "swrast,r300,r600,radeonsi,svga")
}

# meta/classes/meson.bbclass hardcodes llvm-config version to "8.0.0"
# lets set it to our MESA_LLVM_RELEASE that we set in amd-common-configurations.inc
do_write_config_append() {
    sed -i "/llvm-config/s/[0-9]\+\.[0-9]\+\.[0-9]\+/${MESA_LLVM_RELEASE}/" ${WORKDIR}/meson.cross
}
