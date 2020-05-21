# 1. Setting up the build system

Building images for AMD BSPs requires setting up the Yocto Project
Build System. Please follow the guidelines on
[Yocto Project Overview and Concepts Manual](https://www.yoctoproject.org/docs/3.1/overview-manual/overview-manual.html)
and [Yocto Project Quick Build Guide](https://www.yoctoproject.org/docs/3.1/brief-yoctoprojectqs/brief-yoctoprojectqs.html)
if you are not familiar with the Yocto Project and it's Build System.

Running the following commands will setup the build system and will
enable us to build recipes & images for any of the
supported AMD BSPs (i.e `r1000`, `v1000` or `e3000`).

### 1.1 Prerequisites

Install the build system's dependencies:
```sh
sudo apt install -y gawk wget git-core diffstat unzip \
     texinfo gcc-multilib build-essential chrpath socat \
     cpio python3 python3-pip python3-pexpect xz-utils \
     debianutils iputils-ping python3-git python3-jinja2 \
     libegl1-mesa libsdl1.2-dev pylint3 xterm
```

### 1.2 Download the build system and the meta-data layers

Select the Yocto Project branch:
```sh
YOCTO_BRANCH="dunfell"
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
git checkout --quiet 2be7ce47d6919df1074e543924db8e4f7101d6b8
cd meta-openembedded
git checkout --quiet a62ad77973b16daac1cbaa03cbda3c6b9b91f2ff
cd ../meta-dpdk
git checkout --quiet 2b077a7ece9b4f2b9c5b3586149b4eef0e383e3e
cd ../meta-amd
git checkout --quiet HEAD
cd ..
```

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md)) for instructions on how to setup and start a
build for a particular AMD BSP.
