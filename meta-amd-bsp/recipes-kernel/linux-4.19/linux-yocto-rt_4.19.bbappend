require linux-yocto-common_4.19.inc

KBRANCH_amdx86 ?= "v4.19/standard/preempt-rt/base"
SRCREV_machine_amdx86 ?= "bd456d13d8bea4c416209a59f9e0bf50f8511c47"

include linux-yocto-${MACHINE}_4.19.inc
