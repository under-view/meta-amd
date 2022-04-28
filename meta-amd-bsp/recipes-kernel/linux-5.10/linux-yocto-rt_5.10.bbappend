require linux-yocto-common_5.10.inc

PR := "${INC_PR}.1"

KBRANCH:amd ?= "v5.10/standard/preempt-rt/base"
SRCREV_machine:amd ?= "42d1c4e85643d634bddd98e5c4d8a9bcc61b3e18"

require linux-yocto-amdx86_5.10.inc
COMPATIBLE_MACHINE = "${MACHINE}"
