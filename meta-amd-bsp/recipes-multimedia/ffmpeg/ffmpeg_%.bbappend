PACKAGECONFIG[vdpau] = "--enable-vdpau,--disable-vdpau,libvdpau"
PACKAGECONFIG_append_amdgpu = " vdpau vaapi"
PACKAGECONFIG_append_radeon = " vdpau"
