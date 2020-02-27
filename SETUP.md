# 1. Setting up the build system

Building images for AMD BSPs requires setting up the Yocto Project
Build System. Please follow the guidelines on
[Yocto Project Overview and Concepts Manual](https://www.yoctoproject.org/docs/2.7.2/overview-manual/overview-manual.html)
and [Yocto Project Quick Build Guide](https://www.yoctoproject.org/docs/2.7.2/brief-yoctoprojectqs/brief-yoctoprojectqs.html)
if you are not familiar with the Yocto Project and it's Build System.

Running the following commands will setup the build system and will
enable us to build recipes & images for any of the
supported AMD BSPs (i.e `r1000`, `v1000` or `e3000`).

### 1.1 Prerequisites

Install the build system's dependencies:
```sh
sudo apt install -y gawk wget git-core diffstat unzip texinfo \
     gcc-multilib build-essential chrpath socat cpio python python3 \
     python3-pip python3-pexpect xz-utils debianutils iputils-ping \
     python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev xterm
```

### 1.2 Download the build system and the meta-data layers

Select the Yocto Project branch:
```sh
YOCTO_BRANCH="warrior"
```

Clone the git repositories: 
```sh
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/poky" "poky-amd"
cd poky-amd
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.openembedded.org/meta-openembedded"
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/meta-dpdk"
git clone --single-branch --branch "${YOCTO_BRANCH}" \
    "git://git.yoctoproject.org/meta-amd"
```

Checkout commit hashes:
```sh
git checkout --quiet 023ff85a9ae94331926e923b346fd8a349881e63
cd meta-openembedded
git checkout --quiet a24acf94d48d635eca668ea34598c6e5c857e3f8
cd ../meta-dpdk
git checkout --quiet c8c30c2c4e2f36b4a55a69a475fe774015423705
cd ../meta-amd
git checkout --quiet tags/warrior-r1000-ga-202002
cd ..
```

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md)) for instructions on how to setup and start a
build for a particular AMD BSP.
