require ${BPN}.inc

S = "${WORKDIR}/git"

SRCREV = "e9cf8c1d3010e9eada5a7921239ad7895f249b5c"
SRC_URI = "git://gitlab.freedesktop.org/mesa/mesa.git;branch=master;protocol=https \
           file://0001-meson.build-check-for-all-linux-host_os-combinations.patch \
           file://0002-meson.build-make-TLS-GLX-optional-again.patch \
           file://0003-Allow-enable-DRI-without-DRI-drivers.patch \
           file://0001-radeonsi-disabling-the-displayable-DCC-on-Raven-Ridg.patch \
          "

#because we cannot rely on the fact that all apps will use pkgconfig,
#make eglplatform.h independent of MESA_EGL_NO_X11_HEADER
do_install_append() {
    if ${@bb.utils.contains('PACKAGECONFIG', 'egl', 'true', 'false', d)}; then
        sed -i -e 's/^#if defined(MESA_EGL_NO_X11_HEADERS)$/#if defined(MESA_EGL_NO_X11_HEADERS) || ${@bb.utils.contains('PACKAGECONFIG', 'x11', '0', '1', d)}/' ${D}${includedir}/EGL/eglplatform.h
    fi
}
