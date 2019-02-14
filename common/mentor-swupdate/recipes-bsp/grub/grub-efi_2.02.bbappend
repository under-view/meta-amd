FILESEXTRAPATHS_prepend := "${THISDIR}/amd-wdt:"

SRC_URI_append = " file://Makefile.core.def \
                   file://amd_wdt.h \
                   file://amd_wdt.c"

# GRUB's autogen.sh uses GRUB_CONTRIB var to pick up
# out-of-tree modules/utils for building inside GRUB
export GRUB_CONTRIB = "${WORKDIR}/extra-modules"

do_configure_grub_extra_modules () {
        install -d ${GRUB_CONTRIB}
        install -d ${GRUB_CONTRIB}/grub-core
        install -d ${GRUB_CONTRIB}/grub-core/amd-wdt
        install -m 644 ${WORKDIR}/Makefile.core.def ${GRUB_CONTRIB}/grub-core/
        install -m 644 ${WORKDIR}/amd_wdt.h ${GRUB_CONTRIB}/grub-core/amd-wdt/
        install -m 644 ${WORKDIR}/amd_wdt.c ${GRUB_CONTRIB}/grub-core/amd-wdt/
}

do_configure_grub_extra_modules_class-native () {
        :
}

addtask do_configure_grub_extra_modules before do_configure after do_unpack

GRUB_BUILDIN += "amd-wdt"
