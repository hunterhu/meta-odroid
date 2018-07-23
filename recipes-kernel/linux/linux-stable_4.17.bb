FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}-${PV}:"

LINUX_VERSION ?= "4.17.8"
KBRANCH ?= "linux-4.17.y"
SRCREV ?= "5606f577a707aa4ccc391714dca815933aeba508"

require linux-stable.inc

SRCREV_meta ?= "d35642f0b65f7772a45e1457fd60de6d1bff8e58"

SRC_URI_append = " git://github.com/akuster/yocto-kernel-cache;type=kmeta;name=meta;branch=stable-4.17;destsuffix=${KMETA}"
SRC_URI_append = " file://odroid-kmeta;type=kmeta;name=odroid-kmeta;destsuffix=odroid-kmeta"

SRC_URI_append = " file://odroid.scc"

LIC_FILES_CHKSUM = "file://COPYING;md5=bbea815ee2795b2f4230826c0c6b8814"

DEPENDS += "openssl-native util-linux-native"

KMETA = "kernel-meta"
KMACHINE_odroid-hc1 = "odroid-hc1"
KMACHINE_odroid-xu3 = "odroid-xu3"
KMACHINE_odroid-xu3-lite = "odroid-xu3-lite"
KMACHINE_odroid-xu4 = "odroid-xu4"
KMACHINE_odroid-c2 = "odroid-c2"
KMACHINE_odroid-c1 = "odroid-c1"
