require linux-yocto-common_5.10.inc

PR := "${INC_PR}.1"

KBRANCH:amd ?= "v5.10/standard/base"
SRCREV_machine:amd ?= "7dda2a9f69de7f80e572d38236896e97be79f39d"

require linux-yocto-amdx86_5.10.inc
COMPATIBLE_MACHINE = "${MACHINE}"
