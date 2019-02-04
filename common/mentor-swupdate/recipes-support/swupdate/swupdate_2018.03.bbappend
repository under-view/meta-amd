FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://grub.cfg \
            file://bl-kernels"

do_install_append() {
    install -d ${D}${sysconfdir}
    install -d ${D}${sysconfdir}/swupdate
    install -m 644 ${WORKDIR}/bl-kernels ${D}${sysconfdir}/swupdate
}
