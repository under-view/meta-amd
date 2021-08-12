FILESEXTRAPATHS_prepend := "${THISDIR}/files:"

DEPENDS += "openssl"

SRC_URI_append_v1000 = " file://0001-axgbe_ethdev.c-use-RV-AXGBE-as-pci_search_device-doe.patch"

RDEPENDS_dpdk-tools += "\
  python3-shell \
  python3-json \
  python3-pyelftools \
  python3-pprint \
  python3-debugger \
"

COMPATIBLE_MACHINE = "${MACHINE}"
DPDK_TARGET_MACHINE = "znver1"
TUNE_FEATURES += "m64"
