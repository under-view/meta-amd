FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

LIC_FILES_CHKSUM = "file://LICENSE.TXT;md5=8a15a0759ef07f2682d2ba4b893c9afe"

SRCREV = "b8d352a08bc6530a9de442af8f55649199481f1b"

MAJOR_VERSION = "9"
MINOR_VERSION = "0"
PATCH_VERSION = "0"

EXTRA_OECMAKE += "-DLLVM_VERSION_SUFFIX=''"

PACKAGES =+ "${PN}-libremarks"

FILES_${PN}-libremarks = "\
    ${libdir}/${LLVM_DIR}/libRemarks.so* \
"

INSANE_SKIP_${PN}-libremarks += "dev-so"
