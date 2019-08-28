FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-${LINUX_VERSION}:"

SRC_URI_append_e3000 += "file://e3000-user-features.scc \
    file://e3000-user-patches.scc \
    file://e3000.cfg \
    file://e3000-user-config.cfg \
    file://e3000-extra-config.cfg \
    file://amd-xgbe.cfg \
    file://amd-ccp.cfg \
    file://kvm.cfg \
    file://afalg.cfg \
"

COMPATIBLE_MACHINE_e3000 = "e3000"
