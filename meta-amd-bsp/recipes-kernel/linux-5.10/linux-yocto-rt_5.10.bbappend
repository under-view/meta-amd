require linux-yocto-common_5.10.inc

PR := "${INC_PR}.1"

KBRANCH:amd ?= "v5.10/standard/preempt-rt/base"
SRCREV_machine:amd ?= "40a6731993d406d6c9fed43cb20c6a4f178ff2cc"

require linux-yocto-amdx86_5.10.inc
COMPATIBLE_MACHINE = "${MACHINE}"
