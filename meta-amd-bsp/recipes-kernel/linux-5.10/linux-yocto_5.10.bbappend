require linux-yocto-common_5.10.inc

KBRANCH_amd ?= "v5.10/standard/base"
SRCREV_machine_amd ?= "cf5b0320cf4544d3db9ce3ddd6ddb7553a610651"

SRC_URI_append_amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_5.10.inc
