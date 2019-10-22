require linux-yocto-common_4.19.inc

KBRANCH_amdx86 ?= "v4.19/standard/base"
SRCREV_machine_amdx86 ?= "e727c70583a78cf1dc53e8e219722e2f9d1bc858"

SRC_URI_append_amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_4.19.inc
