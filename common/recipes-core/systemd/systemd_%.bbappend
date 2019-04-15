FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI_append_amd = " file://0001-dissect-Don-t-count-RPMB-and-boot-partitions-8609.patch"

pkg_postinst_udev-hwdb_amd () {
}
pkg_postinst_ontarget_udev-hwdb_amd () {
    udevadm hwdb --update
}
