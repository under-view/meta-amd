FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "file://xt-checksum.cfg \
            file://ebtables.cfg \
            file://vswitch.cfg \
            file://lxc.cfg \
            file://docker.cfg \
            "
