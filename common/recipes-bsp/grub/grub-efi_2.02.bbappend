FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI_append_mel-lite = " file://0001-x86-64-Treat-R_X86_64_PLT32-as-R_X86_64_PC32.patch"
RDEPENDS_${PN}_class-target_append = " efibootmgr"
