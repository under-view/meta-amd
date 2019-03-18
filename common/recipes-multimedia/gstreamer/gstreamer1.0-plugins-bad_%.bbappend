PACKAGECONFIG_append_amd = " faad"

EXTRA_OECONF_remove_amd = " --disable-vdpau"
EXTRA_OECONF_append_amd = " --enable-vdpau"

# we do not support wayland
PACKAGECONFIG_remove_amd = "wayland"

# enable build with no graphics
PACKAGECONFIG_GL_remove_mel = "${@bb.utils.contains('COMBINED_FEATURES', 'x11', '', 'gles2 egl', d)}"
PACKAGECONFIG_remove_mel = "${@bb.utils.contains('COMBINED_FEATURES', 'x11', '', 'egl vulkan', d)}"
