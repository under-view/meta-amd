FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
SRC_URI += "file://0001-init-install-efi-manage-partitioning-scheme-as-per-M.patch \
            file://0002-init-install-efi-do-not-blacklist-root-device-for-ud.patch \
            file://0003-init-install-efi-deploy-kernel-images-as-imageA.patch \
            file://0004-init-install-efi-pick-kernel-and-rootfs-from-grub.en.patch \
            file://0005-init-install-efi-create-fallback-entry.patch \
            file://0006-init-install-efi-don-t-unnecessarily-set-the-rootfs-.patch \
            file://0007-init-install-efi-grub-don-t-set-a-timeout.patch"
