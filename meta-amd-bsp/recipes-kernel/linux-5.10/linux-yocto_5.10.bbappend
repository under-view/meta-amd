require linux-yocto-common_5.10.inc

KBRANCH:amd ?= "v5.10/standard/base"
SRCREV_machine:amd ?= "7dda2a9f69de7f80e572d38236896e97be79f39d"

SRC_URI:append:amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_5.10.inc
