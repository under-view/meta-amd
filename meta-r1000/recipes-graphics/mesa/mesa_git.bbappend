FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRCREV_r1000 = "d2c170eb355a912586cb982858faac2fc85c4783"

SRC_URI_remove_r1000 = "file://0001-gallium-add-missing-PIPE_CAP_SURFACE_SAMPLE_COUNT-de.patch"
SRC_URI_append_r1000 = " file://0001-vl-dri3-remove-the-wait-before-getting-back-buffer.patch"

PACKAGECONFIG_append_r1000 = " dri3"
