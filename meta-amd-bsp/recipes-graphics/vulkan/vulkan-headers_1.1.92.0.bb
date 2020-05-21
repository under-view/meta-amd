SUMMARY = "Vulkan API headers"
DESCRIPTION = "Vulkan spec API headers"
HOMEPAGE = "https://www.khronos.org/vulkan/"
BUGTRACKER = "https://github.com/KhronosGroup/Vulkan-Headers"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/KhronosGroup/Vulkan-Headers.git;nobranch=1"
SRCREV = "114c3546e195819bd53a34b39f5194b2989a5b12"

S = "${WORKDIR}/git"

REQUIRED_DISTRO_FEATURES = "vulkan"

inherit cmake features_check

PACKAGES += "vulkan-registry"
FILES_vulkan-registry = "${datadir}/vulkan/registry"
