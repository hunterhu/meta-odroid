# Odroid BSP default settings

PREFERRED_PROVIDER_virtual/xserver ?= "xserver-xorg"
XSERVER ?= "xserver-xorg \
           xf86-input-evdev \
           xf86-input-mouse \
           xf86-video-fbdev \
           xf86-input-keyboard"

PREFERRED_PROVIDER_virtual/kernel ?= "linux-stable"
PREFERRED_VERSION_linux-stable ?= "4.17%"
LINUX_VERSION_EXTENSION ?= "-odroid"

KERNEL_IMAGETYPE ?= "zImage"

PREFERRED_PROVIDER_virtual/bootloader ?= "u-boot"
PREFERRED_PROVIDER_u-boot ?= "u-boot"
PREFERRED_VERSION_u-boot ?= "2018.07"

USE_BOOTSRC ?= "1"
UBOOT_ENV  ?= "boot"
UBOOT_BINARY ?= "u-boot-dtb.bin"
UBOOT_ENV_SUFFIX ?= "scr"
UBOOT_SCRIPT ?= "boot.${UBOOT_ENV_SUFFIX}"
UBOOT_LOAD_CMD ?= "ext4load"
UBOOT_BOOT_CMD ?= "bootz"

UBOOT_BOOTDEV  ?= "0"
UBOOT_BOOTPART ?= "2"
UBOOT_ROOTDEV ?= "1"
UBOOT_ROOTPART ?= "2"
UBOOT_BOOTTYPE ?= "mmc"
UBOOT_ROOTTYPE ?= "mmcblk${UBOOT_ROOTDEV}p"
BOOT_PREFIX ?= "boot/"

UBOOT_EXTRA_ENV ?= ""
UBOOT_FILE_TITLE ?= "#"
BOOT_PREFIX ?= ""
UBOOT_VIDEO ?= "${@bb.utils.contains("DISTRO_FEATURES", "x11", "drm_kms_helper.edid_firmware=edid/1024x768.bin", " ", d)}"

IMAGE_BOOT_FILES ?= "${UBOOT_SCRIPT}"

# Do not update fstab file when using wic images
WIC_CREATE_EXTRA_ARGS ?= "--no-fstab-update"

# wic default support
WKS_FILE_DEPENDS ?= " \
    e2fsprogs-native \
    bmap-tools-native \
"

MACHINE_FEATURES_append = " serial usbgadget usbhost vfat ext2"

MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"

EXTRA_IMAGEDEPENDS_append = " u-boot"
EXTRA_IMAGEDEPENDS_append = "${@bb.utils.contains("DISTRO_FEATURES", "x11", " odroid-edid", " ", d)}"
IMAGE_INSTALL_append = " kernel-image kernel-modules kernel-devicetree"

IMAGE_FSTYPES ?= " ext4 wic wic.xz"

IMAGE_CLASSES += "image_types_odroid"
