DESCRIPTION = "This kernel module provides support for AMD Watchdog driver"
LICENSE = "BSD | GPLv2"
LIC_FILES_CHKSUM = "file://amd_wdt.c;md5=3f729257c648a54237f3fc2fd7dac43f \
                    file://amd_wdt.h;md5=a9f4cbcd9c7179dbe5e1444bbf764a53 \
                    file://Makefile;md5=111ec65dfed99f6cd330ccb4957fb924 \
                   "

inherit module

SRC_URI = "file://Makefile \
           file://amd_wdt.c \
           file://amd_wdt.h \
          "

S = "${WORKDIR}"

# The inherit of module.bbclass will take care of the rest
