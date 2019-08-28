FILESEXTRAPATHS_prepend := "${THISDIR}/linux-yocto-${LINUX_VERSION}-${MACHINE}:"

SRC_URI_append_e3000 += "file://e3000-user-features.scc \
    file://e3000-user-patches.scc \
    file://e3000.cfg \
    file://e3000-user-config.cfg \
    file://e3000-extra-config.cfg \
    file://amd-xgbe.cfg \
    file://amd-ccp.cfg \
    file://kvm.cfg \
    file://afalg.cfg \
    file://disable-graphics.cfg \
    file://e3000-standard-only.cfg \
"

COMPATIBLE_MACHINE_e3000 = "e3000"

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
