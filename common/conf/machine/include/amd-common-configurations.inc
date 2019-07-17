require conf/machine/include/amd-features.inc

POKY_DEFAULT_DISTRO_FEATURES_remove = "wayland"

PREFERRED_PROVIDER_jpeg ?= "jpeg"
PREFERRED_PROVIDER_jpeg-native ?= "jpeg-native"
PREFERRED_VERSION_linux-yocto ?= "4.4%"
PREFERRED_VERSION_libav ?= "9.18"
PREFERRED_PROVIDER_llvm ?= "llvm7"

# Components that depend on LLVM should set versions here
# so we know what needs to be changed/validated as LLVM moves
MESA_LLVM_RELEASE_amd = "7"
CLAMAV_LLVM_RELEASE_amd = "7"

MULTILIBS ?= ""
require conf/multilib.conf

MACHINE_FEATURES += "wifi efi alsa"

# QEMU does not support some of the enhanced instructions available
# on the AMD chips which causes some build time failures.
MACHINE_FEATURES_remove = "qemu-usermode"

MACHINE_EXTRA_RRECOMMENDS += "kernel-modules alsa-utils"
MACHINE_EXTRA_RRECOMMENDS += "${@bb.utils.contains("EXTRA_IMAGE_FEATURES", "graphics", "vdpauinfo", "", d)} grub parted util-linux-blkid"
MACHINE_EXTRA_RRECOMMENDS += "rtc-test watchdog-test spi-test smbus-test gpio-test"
MACHINE_EXTRA_RRECOMMENDS += "amd-wdt amd-spi"
MACHINE_EXTRA_RRECOMMENDS += "${@bb.utils.contains_any("DISTRO", "mel mel-lite", "firmware-wireless", "", d)}"

# Add serial consoles to kernel commandline, these should occur before the tty0
KERNEL_SERIAL_CONSOLE ??= ""
APPEND += "${KERNEL_SERIAL_CONSOLE}"

# Make sure the kernel messages go to the VGA console
APPEND += "console=tty0"

# Set a generic video mode, use gfxpayload=wxh for grub2
GRUB_OPTS_append = ";set gfxpayload=1024x768"

# We use ext4 rootfs normally so give it priority rather than trying other FS first
APPEND += "rootfstype=ext4,ext3,ext2"

APPEND_ADDITIONAL ??= ""
APPEND += "${APPEND_ADDITIONAL}"

EXTRA_OECONF_append_pn-matchbox-panel-2 = " --with-battery=acpi"

# IMAGE_FSTYPES "live" is enabled by default in oe-core which is
# responsible for building both "iso" & "hddimg". Although the 
# right way to specify which ones to build is using NOISO & NOHDD
# vars, there's a specific scenario where Toaster build artifacts
# collection mechanism depends on the IMAGE_FSTYPES variable to
# specify the image types explicitly (See: commit a5b1aa4).
# Also, "iso" doesn't get built even if specified explicitly
# because NOISO = "1" by default (See c787dcd in oe-core).
# Therefore, we do as follows:
IMAGE_FSTYPES += "wic iso"
NOISO = "0"
NOHDD = "1"

WKS_FILES ?= "amd-usbimage.wks"

# Contents of IMAGE_BOOT_FILES are deployed into "amd-usbimage.wks" wic image
IMAGE_BOOT_FILES = " \
        ${EFIIMGDIR}${EFIDIR}/*;EFI/BOOT/ \
        ${EFIIMGDIR}/startup.nsh;startup.nsh \
        ${KERNEL_IMAGETYPE} \
        ${INITRD_IMAGE_LIVE}-${MACHINE}.cpio.gz;initrd \
        ${ROOTFS};rootfs.img \
"

# This makes sure that boot files are deployed before do_image_wic starts execution
do_image_wic[depends] += "${IMAGE_BASENAME}:do_bootimg"

IMAGE_OVERHEAD_FACTOR = "1.1"

IOT_PACKAGES_mel ?= "packagegroup-xmpp \
                     packagegroup-mqtt \
                     packagegroup-ble \
                     packagegroup-http-restful"

MACHINE_FEATURES_append_amdgpu := " ${@bb.utils.contains("EXTRA_IMAGE_FEATURES", "graphics", "x11", "", d)}"
MACHINE_FEATURES_append_radeon := " ${@bb.utils.contains("EXTRA_IMAGE_FEATURES", "graphics", "x11", "", d)}"

# Add common feartures to be supported for all machines here
EXTRA_IMAGE_FEATURES += "amd-misc-pkgs"

# Add the basic features we know these overrides support
EXTRA_IMAGE_FEATURES_append_amdgpu := " ${@bb.utils.contains("EXTRA_IMAGE_FEATURES", "multimedia", "amd-feature-multimedia", "", d)} \
                                        ${@bb.utils.contains_any("EXTRA_IMAGE_FEATURES", "graphics", "amd-feature-graphics", "", d)}"
EXTRA_IMAGE_FEATURES_append_radeon := " ${@bb.utils.contains("EXTRA_IMAGE_FEATURES", "multimedia", "amd-feature-multimedia", "", d)} \
                                        ${@bb.utils.contains_any("EXTRA_IMAGE_FEATURES", "graphics", "amd-feature-graphics", "", d)}"

# Workaround for a MEL related issue
# revert as soon as the fixes are merged
# in the main layer.
dm-initramfs_mel ?= ""
