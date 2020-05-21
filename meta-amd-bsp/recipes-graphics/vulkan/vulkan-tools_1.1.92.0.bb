SUMMARY = "Vulkan utilities"
DESCRIPTION = "Vulkan tools and utilities that can assist \
development by enabling developers to verify their applications \
correct use of the Vulkan API."
HOMEPAGE = "https://www.khronos.org/vulkan/"
BUGTRACKER = "https://github.com/KhronosGroup/Vulkan-Tools"

LICENSE = "Apache-2.0"
LIC_FILES_CHKSUM = "file://LICENSE.txt;md5=3b83ef96387f14655fc854ddc3c6bd57"

SRC_URI = "git://github.com/KhronosGroup/Vulkan-Tools.git;nobranch=1"
SRCREV = "9bbdd552f0fd62741aa1f1e02ab3eafc45cf3c1e"

S = "${WORKDIR}/git"

REQUIRED_DISTRO_FEATURES = "vulkan"

inherit cmake python3native distro_features_check
ANY_OF_DISTRO_FEATURES = "x11 wayland"

DEPENDS += "vulkan-loader vulkan-headers"

EXTRA_OECMAKE = "-DBUILD_CUBE=OFF -DBUILD_ICD=OFF"

# must choose x11 or wayland or both
PACKAGECONFIG ??= "${@bb.utils.contains('DISTRO_FEATURES', 'x11', 'x11', '' ,d)} \
                   ${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'wayland', '' ,d)}"
PACKAGECONFIG[x11] = "-DBUILD_WSI_XLIB_SUPPORT=ON -DBUILD_WSI_XCB_SUPPORT=ON, -DBUILD_WSI_XLIB_SUPPORT=OFF -DBUILD_WSI_XCB_SUPPORT=OFF, libxcb libx11 libxrandr"
PACKAGECONFIG[wayland] = "-DBUILD_WSI_WAYLAND_SUPPORT=ON, -DBUILD_WSI_WAYLAND_SUPPORT=OFF, wayland"

# Can't be built with ccache
CCACHE_DISABLE = "1"
