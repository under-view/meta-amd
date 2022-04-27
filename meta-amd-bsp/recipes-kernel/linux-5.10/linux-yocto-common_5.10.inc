INC_PR := "r0"

KMACHINE:amd ?= "common-pc-64"
SRCREV_meta:amd ?= "2278ed571c14df6e87d8e01ac26f649d98020623"
LINUX_VERSION:amd ?= "5.10.109"

FILESEXTRAPATHS:prepend := "${THISDIR}/linux-yocto-5.10:"

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
