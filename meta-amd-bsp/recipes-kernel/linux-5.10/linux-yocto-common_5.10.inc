INC_PR := "r0"
PR := "${INC_PR}.1"

KMACHINE_amd ?= "common-pc-64"
SRCREV_meta_amd ?= "031f6c76e488a3563f35258c72ff1de3e25a512e"
LINUX_VERSION_amd ?= "5.10.25"

FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-${LINUX_VERSION}:"

SRC_URI_append_amd = " file://amd-xgbe-patches.scc \
                   file://amd-emmc-patches.scc \
                   file://amd-spi-patches.scc \
                   file://amd-usb-patches.scc \
                   file://amd-wdt-patches.scc \
                   file://logo.cfg \
                   file://console.cfg \
                   file://sound.cfg \
                   file://hid.cfg \
                   file://usb-serial.cfg \
                   file://spi-driver.cfg \
                   file://wdt-driver.cfg \
                   file://wifi-drivers.cfg \
                   file://disable-intel-graphics.cfg \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', 'file://enable-bluetooth.cfg', 'file://disable-bluetooth.cfg', d)} \
                   ${@bb.utils.contains('DISTRO', 'poky-amd', 'file://enable-kgdb.cfg', 'file://disable-kgdb.cfg', d)}"

KERNEL_FEATURES_append_amd = " cfg/smp.scc"
