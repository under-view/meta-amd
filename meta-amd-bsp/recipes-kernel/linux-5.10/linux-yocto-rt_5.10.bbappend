require linux-yocto-common_5.10.inc

KBRANCH_amd ?= "v5.10/standard/preempt-rt/base"
SRCREV_machine_amd ?= "be2935bce35f9adb6d0e735d42651e81a5094adf"

include linux-yocto-${MACHINE}_5.10.inc
