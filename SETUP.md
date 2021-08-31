# 1. Setting up the build system

Building images for AMD machines requires setting up the Yocto Project
Build System. Please follow the guidelines on
[Yocto Project Overview and Concepts Manual](https://docs.yoctoproject.org/3.3.2/overview-manual/index.html)
and [Yocto Project Quick Build Guide](https://docs.yoctoproject.org/3.3.2/brief-yoctoprojectqs/index.html)
if you are not familiar with the Yocto Project and it's Build System.

Running the following commands will setup the build system and will
enable us to build recipes & images for the `ethanolx` bsp.

### 1.1 Prerequisites

Install the build system's dependencies:
```sh
sudo apt install -y gawk wget git diffstat unzip texinfo gcc \
     build-essential chrpath socat cpio python3 python3-pip \
     python3-pexpect xz-utils debianutils iputils-ping python3-git \
     python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm \
     python3-subunit mesa-common-dev
```

### 1.2 Download the build system and the meta-data layers

Select the Yocto Project branch:
```sh
YOCTO_BRANCH="hardknott"
```

Clone the git repositories: 
```sh
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/poky" "poky-amd-${YOCTO_BRANCH}"
cd poky-amd-${YOCTO_BRANCH}
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.openembedded.org/meta-openembedded"
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/meta-dpdk"
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/meta-amd"
```

Checkout commit hashes:
```sh
git checkout --quiet tags/yocto-3.3.2
cd meta-openembedded
git checkout --quiet aaa1c12b2cdea197d420953c8df873e8af5cc507
cd ../meta-dpdk
git checkout --quiet c011004a49ffb1304f376f0fdc65066913102d5f
cd ../meta-amd
git checkout --quiet HEAD
cd ..
```

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md)) for instructions on how to setup and start a
build for a particular AMD machine.
