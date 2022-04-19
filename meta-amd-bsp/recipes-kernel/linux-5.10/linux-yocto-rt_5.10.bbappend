require linux-yocto-common_5.10.inc

KBRANCH:amd ?= "v5.10/standard/preempt-rt/base"
SRCREV_machine:amd ?= "42d1c4e85643d634bddd98e5c4d8a9bcc61b3e18"

include linux-yocto-${MACHINE}_5.10.inc
