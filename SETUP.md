# 1. Setting up the build system

Building images for AMD BSPs requires setting up the Yocto Project
Build System. Please follow the guidelines on
[Yocto Project Overview and Concepts Manual](https://www.yoctoproject.org/docs/3.0.4/overview-manual/overview-manual.html)
and [Yocto Project Quick Build Guide](https://www.yoctoproject.org/docs/3.0.4/brief-yoctoprojectqs/brief-yoctoprojectqs.html)
if you are not familiar with the Yocto Project and it's Build System.

Running the following commands will setup the build system and will
enable us to build recipes & images for the `e3000` bsp.

### 1.1 Prerequisites

Install the build system's dependencies:
```sh
sudo apt install -y gawk wget git-core diffstat unzip texinfo \
     gcc-multilib build-essential chrpath socat cpio python3 \
     python3-pip python3-pexpect xz-utils debianutils iputils-ping \
     python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev pylint3 xterm
```

### 1.2 Download the build system and the meta-data layers

Select the Yocto Project branch:
```sh
YOCTO_BRANCH="zeus"
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
git checkout --quiet tags/yocto-3.0.4
cd meta-openembedded
git checkout --quiet 2b5dd1eb81cd08bc065bc76125f2856e9383e98b
cd ../meta-dpdk
git checkout --quiet 65861f98a8f88389963921f2d78de7e5a8881048
cd ../meta-amd
git checkout --quiet HEAD
cd ..
```

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md)) for instructions on how to setup and start a
build for a particular AMD BSP.
