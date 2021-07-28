# Release notes

This is the release notes document for the AMD machine ETHANOLX. This document
contains information about the Yocto layers' git repos, their branches
and commit hashes, software versions, and known/fixed issues/limitations.

## Bitbake layers
| Layer             | Git Repo                                     | Branch    | Commit Hash/Tag                          |
|:------------------|:---------------------------------------------|:----------|:-----------------------------------------|
| poky              | git://git.yoctoproject.org/poky              | hardknott | tags/yocto-3.3                           |
| meta-openembedded | git://git.openembedded.org/meta-openembedded | hardknott | cf5bd6a8308108b4313a1e45ce8aa87e73125bf9 |
| meta-dpdk         | git://git.yoctoproject.org/meta-dpdk         | master    | c011004a49ffb1304f376f0fdc65066913102d5f |
| meta-amd          | git://git.yoctoproject.org/meta-amd          | hardknott | tags/hardknott-ethanolx-ga-202107                                     |

## Software versions
| Software        | Version  |
|:----------------|:---------|
| Yocto Poky base | 3.3      |
| grub            | 2.06-rc1 |
| linux-yocto     | 5.10.25  |
| linux-yocto-rt  | 5.10.25  |
| gcc             | 10.2.0   |
| util-linux      | 2.36.2   |
| lttng           | 2.12     |
| babeltrace      | 1.5.8    |
| connman         | 1.39     |
| gdb             | 10.1     |
| dpdk            | 20.11.1  |
| strongswan      | 5.9.2    |

## Fixed issues
| __ETHANOLX Fixed Issues__ |
|:--------------------------|
| None                      |

## Known issues
| __ETHANOLX Known Issues/Limitations__                                                       |
|:--------------------------------------------------------------------------------------------|
| Network is detected from only one NIC card when two NIC cards are connected on the platform |
| AMD SPI Kernel Driver fails to access the SPI ROM registers                                 |
| _** Workaround: Disable ‘Rom Armor’ setting under ‘Chipset’ tab in BIOS_                    |
