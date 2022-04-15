require linux-yocto-common_5.10.inc

KBRANCH:amd ?= "v5.10/standard/preempt-rt/base"
SRCREV_machine:amd ?= "42032770803ba26765376967cef09945f48abe04"

include linux-yocto-${MACHINE}_5.10.inc
