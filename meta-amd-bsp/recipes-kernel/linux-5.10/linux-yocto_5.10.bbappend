require linux-yocto-common_5.10.inc

PR := "${INC_PR}.1"

KBRANCH:amd ?= "v5.10/standard/base"
SRCREV_machine:amd ?= "d2f7a595bf0b752275d503046494b668549cb151"

require linux-yocto-amdx86_5.10.inc
COMPATIBLE_MACHINE = "${MACHINE}"
