FILESEXTRAPATHS:prepend := "${THISDIR}/linux-yocto-5.15:"

KMACHINE:amd ?= "common-pc-64"
SRCREV_meta:amd ?= "63e25b5717751b4b33685bd5991d10c52934a4c6"
LINUX_VERSION:amd ?= "5.15.32"
LINUX_VERSION_EXTENSION:amd ?= "-amd-${LINUX_KERNEL_TYPE}"

COMPATIBLE_MACHINE = "${MACHINE}"

INC_PR := "r0"

SRC_URI:append:amd = " \
      file://amdx86.cfg \
      file://amdx86-user-config.cfg \
      file://amdx86-extra-config.cfg \
      file://amd-xgbe.cfg \
      file://kvm.cfg \
      file://afalg.cfg \
      file://amdx86-standard-only.cfg \
      file://logo.cfg \
      file://console.cfg \
      file://sound.cfg \
      file://hid.cfg \
      file://usb-serial.cfg \
      file://spi-driver.cfg \
      file://wdt-driver.cfg \
      file://wifi-drivers.cfg \
      file://fragment.cfg \
      ${@bb.utils.contains('MACHINE_FEATURES', 'ccp', 'file://amd-ccp.cfg', '', d)} \
      ${@bb.utils.contains('MACHINE_FEATURES', 'screen', 'file://enable-graphics.cfg', 'file://disable-graphics.cfg', d)} \
      ${@bb.utils.contains('MACHINE_FEATURES', 'screen-console', 'file://enable-screen-console.cfg', 'file://disable-screen-console.cfg', d)} \
      ${@bb.utils.contains('DISTRO_FEATURES', 'bluetooth', 'file://enable-bluetooth.cfg', 'file://disable-bluetooth.cfg', d)} \
      ${@bb.utils.contains('DISTRO', 'poky-amd', 'file://enable-kgdb.cfg', 'file://disable-kgdb.cfg', d)} \
      ${@bb.utils.contains('EXTRA_IMAGE_FEATURES', 'amd-feature-networking', 'file://dpdk.cfg', '', d)} \
      file://core.scc \
      file://spi.scc \
      file://smbus.scc \
      file://ucsi.scc \
      file://wdt.scc \
      file://usb.scc \
      file://net-phy.scc \
      file://xgbe.scc \
    "
