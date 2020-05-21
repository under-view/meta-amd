require linux-yocto-common_5.4.inc

KBRANCH_amdx86 ?= "v5.4/standard/base"
SRCREV_machine_amdx86 ?= "5f8bc2bb0e0f456e2217bbd1caac2acf211431c9"

SRC_URI_append_amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_5.4.inc
