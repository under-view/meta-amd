INC_PR := "r0"
PR := "${INC_PR}.1"

KMACHINE:amd ?= "common-pc-64"
SRCREV_meta:amd ?= "82899c6a7119b9668be9ae508159f5ac96554cc2"
LINUX_VERSION:amd ?= "5.10.47"

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-yocto-${LINUX_VERSION}:"

SRC_URI:append:amd = " file://amd-xgbe-patches.scc \
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

KERNEL_FEATURES:append:amd = " cfg/smp.scc"
