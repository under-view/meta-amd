FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://blacklist-ccp.conf"

do_install_append_ethanolx () {
    install -m755 ${WORKDIR}/blacklist-ccp.conf \
                  ${D}${sysconfdir}/modprobe.d/blacklist-ccp.conf
}

do_install_append_vermeer () {
    install -m755 ${WORKDIR}/blacklist-ccp.conf \
                  ${D}${sysconfdir}/modprobe.d/blacklist-ccp.conf
}
