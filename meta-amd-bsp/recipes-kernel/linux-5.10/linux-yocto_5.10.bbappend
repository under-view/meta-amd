require linux-yocto-common_5.10.inc

KBRANCH:amd ?= "v5.10/standard/base"
SRCREV_machine:amd ?= "52bcc5b2342739bbfc8fc385d151616883c4425c"

SRC_URI:append:amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_5.10.inc
