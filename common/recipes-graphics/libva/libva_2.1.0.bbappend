# Remove everything related to x11
# we provide that through libva-x11
PACKAGECONFIG_remove_amd = "x11"
EXTRA_OECONF_append_amd = " --disable-glx"
PACKAGES_remove_amd = "libva-x11 libva-glx"
# This package (without x11) is no more dependent on mesa
DEPENDS_remove_amd = "virtual/mesa"
