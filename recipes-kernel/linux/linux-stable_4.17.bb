FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.17.8"
KBRANCH ?= "linux-4.17.y"
SRCREV ?= "5606f577a707aa4ccc391714dca815933aeba508"

require linux-stable.inc

SRC_URI_append = " file://odroid.scc"

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "openssl-native util-linux-native"

do_configure_prepend() {
    cp ${WORKDIR}/${O_KERNEL_CONFIG}/defconfig ${B}/.config
}
