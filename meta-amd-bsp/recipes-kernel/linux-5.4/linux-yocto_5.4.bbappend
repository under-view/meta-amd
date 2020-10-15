require linux-yocto-common_5.4.inc

SRC_URI_append_amdgpu += "file://amdgpu-patches.scc \
			  file://misc-patches.scc"

include linux-yocto-${MACHINE}_5.4.inc
