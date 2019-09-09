# 1. Setting up the build system

Running the following commands will setup the build system and will
enable us to build recipes & images for any of the supported AMD BSPs:

```sh
gitclonecheckout() {
  REPO="$1"; NAME="$2"; HASH="$3"

  git clone --single-branch --branch "${YOCTO_BRANCH}" "${REPO}" "${NAME}"
  cd "${NAME}"
  git checkout --quiet "${HASH}"
  cd ..
}

YOCTO_BRANCH="warrior"

gitclonecheckout "git://git.yoctoproject.org/poky" "poky-amd" "6d2e12e79211b31cdf5ea824fb9a8be54ba9a9eb"
cd "poky-amd"
gitclonecheckout "git://git.openembedded.org/meta-openembedded" "meta-openembedded" "3bdbf72e3a4bf18a4a2c7afbde4f7ab773aeded9"
gitclonecheckout "git://git.yoctoproject.org/meta-amd" "meta-amd" "HEAD"
gitclonecheckout "git://git.yoctoproject.org/meta-dpdk" "meta-dpdk" "c8c30c2c4e2f36b4a55a69a475fe774015423705"
```

---
#### What's next

Continue to "[section 2 - build](BUILD.md)" for instructions on how to
setup and start a build for a particular AMD BSP.
