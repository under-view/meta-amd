FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"
SRC_URI_append_amd = " file://0001-plugins-update-mesa-s-vendor-string-in-whitelist.patch"
DEPENDS_append_amd = " libva-x11"
