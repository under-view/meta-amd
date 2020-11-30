inherit kernel-openssl

FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

SRC_URI += "\
    file://0001-Update-for-kernel-5.7-use-vmalloc_sync_mappings-on-k.patch \
    file://0002-Fix-missing-wrapper-rename-to-wrapper_vmalloc_sync_m.patch \
    file://0003-Fix-Use-vmalloc_sync_mappings-on-kernel-5.6-as-well.patch \
    file://0004-Update-Use-vmalloc_sync_mappings-for-stable-kernels.patch \
"
