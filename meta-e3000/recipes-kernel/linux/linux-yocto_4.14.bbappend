require linux-yocto-e3000_4.14.inc

SRC_URI_append_e3000 += "file://e3000-standard-only.cfg"
SRC_URI_append_e3000 += "file://disable-graphics.cfg"

do_validate_branches_append() {
    # Droping configs related to sound generating spurious warnings
    sed -i '/kconf hardware snd_hda_intel.cfg/d' ${WORKDIR}/${KMETA}/features/sound/snd_hda_intel.scc

    # Droping configs related to graphics generating spurious warnings
    sed -i '/CONFIG_FB/d' ${WORKDIR}/${KMETA}/bsp/common-pc/common-pc-gfx.cfg
    sed -i '/CONFIG_DRM/d' ${WORKDIR}/${KMETA}/bsp/common-pc/common-pc-gfx.cfg
    sed -i '/CONFIG_FRAMEBUFFER_CONSOLE/d' ${WORKDIR}/${KMETA}/bsp/common-pc/common-pc-gfx.cfg
    sed -i '/kconf hardware i915.cfg/d' ${WORKDIR}/${KMETA}/features/i915/i915.scc
    sed -i '/CONFIG_FB/d' ${WORKDIR}/${KMETA}/cfg/efi-ext.cfg
    sed -i '/CONFIG_FRAMEBUFFER_CONSOLE/d' ${WORKDIR}/${KMETA}/cfg/efi-ext.cfg
}
