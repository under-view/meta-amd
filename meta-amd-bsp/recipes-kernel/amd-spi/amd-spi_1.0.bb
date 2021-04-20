DESCRIPTION = "This kernel module provides support for AMD SPI ROM device"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://spirom.c;endline=21;md5=3d17290ed76805de10a58d20f793b7de"

inherit module kernel-openssl

SRC_URI = "file://Makefile \
           file://spirom.c \
           file://spirom.h \
          "

S = "${WORKDIR}"

# The inherit of module.bbclass will take care of the rest
