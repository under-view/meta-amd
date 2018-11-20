PR := "${INC_PR}.1"

KMACHINE_amdx86 ?= "common-pc-64"
SRCREV_meta_amdx86 ?= "c35dd5cbbdb08dcc4fe35b8e9c0a62d1a157aeaf"
LINUX_VERSION_amdx86 ?= "4.14.71"

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-${LINUX_VERSION}:"

SRC_URI_append = " file://amd-xgbe-patches.scc"

KERNEL_FEATURES_append_amdx86 = " cfg/smp.scc"
