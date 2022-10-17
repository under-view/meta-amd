# 1. Setting up the build system

Building images for AMD machines requires setting up the Yocto Project
Build System. Please follow the guidelines on
[Yocto Project Overview and Concepts Manual](https://docs.yoctoproject.org/4.0/overview-manual/index.html)
and [Yocto Project Quick Build Guide](https://docs.yoctoproject.org/4.0/brief-yoctoprojectqs/index.html)
if you are not familiar with the Yocto Project and it's Build System.

Running the following commands will setup the build system and will
enable us to build recipes & images for any of the supported AMD machines (i.e `milan`, `rome` or `v3000`).

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
YOCTO_BRANCH="kirkstone"
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
git checkout --quiet tags/yocto-4.0
cd meta-openembedded
git checkout --quiet 64156a6f8f3b4527c4732c91936aee0a167acb48
cd ../meta-dpdk
git checkout --quiet 09098721b1c78ee812ee287f6b366a47f4b5be87
cd ../meta-amd
git checkout --quiet tags/kirkstone-v3000-ga-202210
cd ..
```

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md)) for instructions on how to setup and start a
build for a particular AMD machine.
