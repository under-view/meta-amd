PREFERRED_PROVIDER_virtual/kernel ?= "${@bb.utils.contains('RT_KERNEL_AMD', 'yes', "linux-yocto-rt", "linux-yocto", d)}"
PREFERRED_VERSION_linux-yocto ?= "5.10%"
PREFERRED_VERSION_linux-yocto-rt ?= "5.10%"

require conf/machine/include/amd-common-configurations.inc
include conf/machine/include/amd-customer-configurations.inc

# Add machine specific AMD features and feature pkgs here
DPDK_PKGS = "${@bb.utils.contains("BBFILE_COLLECTIONS", "dpdk", "dpdk dpdk-examples dpdk-tools dpdk-module", "", d)}"

MACHINE_FEATURES_remove = "screen alsa"
MACHINE_EXTRA_RRECOMMENDS_remove = " rtc-test alsa-utils"

# Drop features we do not need
DISTRO_FEATURES_remove="opengl x11 alsa pulseaudio"

# Disable the graphical console when machine does not have a screen.
# This allows the serial console to be used for installation.
APPEND_remove="${@bb.utils.contains('MACHINE_FEATURES', 'screen-console', '', 'console=tty0', d)}"

MACHINEOVERRIDES =. "amd:amdx86:"

# Mask out recipes for packages we do not support for
# amdx86 but may be required by others. Use '|' sign
# between the patterns.
BBMASK = "\
.*/meta-amd/common/recipes-support/libtinyxml\
"
