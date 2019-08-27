# AMD provides the functionality to build packages with license-restricted
# algorithms or software. Their configuration variables can be set to
# "yes" or "no" in the local.conf file to enable or disable the
# functionality to include them in the build. The option to build these
# packages is NOT enabled in the default configuration. After enabling the
# option to build, when you build your target image, the BitBake utility
# fetches package sources from the canonical upstream location. If you do
# not have an active network connection, your build with these packages
# will fail.
#
# Building packages with license-restricted algorithms or software may add
# proprietary IP or functionality with other restrictions to your output.
# AMD has no connection with or responsibility for such
# license-restricted algorithms or software, and failure to abide by the
# relevant license terms may have legal consequences.
#
# AMD does not distribute or endorse sources for license-restricted
# algorithms or software, and disclaims any liability for their use.

# Using mpv requires the use of license-restricted algorithms
# or software.
INCLUDE_MPV ??= "no"

COMMERCIAL_LIC_FLAGS_MPV = "commercial_mpv commercial_ffmpeg commercial_x264"
LICENSE_FLAGS_WHITELIST_append = "${@' ${COMMERCIAL_LIC_FLAGS_MPV}' if bb.utils.to_boolean('${INCLUDE_MPV}') else ''}"
CORE_IMAGE_EXTRA_INSTALL_append = "${@' mpv' if bb.utils.to_boolean('${INCLUDE_MPV}') else ''}"

# Certain multimedia formats also require license restricted codecs and
# software components which are not included in build by default.
INCLUDE_COMMERCIAL_MULTIMEDIA ??= "no"

COMMERCIAL_LIC_FLAGS_MULTIMEDIA = "\
	commercial_gstreamer1.0-plugins-ugly \
	commercial_gstreamer1.0-libav \
	commercial_mpeg2dec \
	commercial_ffmpeg \
	commercial_x264 \
	commercial_faad2 \
"

LICENSE_FLAGS_WHITELIST_append = "${@' ${COMMERCIAL_LIC_FLAGS_MULTIMEDIA}' if bb.utils.to_boolean('${INCLUDE_COMMERCIAL_MULTIMEDIA}') else ''}"
CORE_IMAGE_EXTRA_INSTALL_append = "${@' packagegroup-multimedia-risky' if bb.utils.to_boolean('${INCLUDE_COMMERCIAL_MULTIMEDIA}') else ''}"

# To fix the following error:
# Missing or unbuildable dependency chain was: ['core-image-sato', 'gstreamer1.0-vaapi', 'gstreamer1.0-plugins-bad', 'faad2']
GSTREAMER_PKGS_remove = "${@' gstreamer1.0-vaapi' if not bb.utils.to_boolean('${INCLUDE_COMMERCIAL_MULTIMEDIA}') else ''}"
