# Release notes

This is the release notes document for the AMD BSP E3000. This document
contains information about the Yocto layers' git repos, their branches
and commit hashes, software versions, and known/fixed issues/limitations.

## Layers
| Layer             | Git Repo                                     | Branch  | Commit Hash                              |
|:------------------|:---------------------------------------------|:--------|:-----------------------------------------|
| poky              | git://git.yoctoproject.org/poky              | warrior | 023ff85a9ae94331926e923b346fd8a349881e63 |
| meta-openembedded | git://git.openembedded.org/meta-openembedded | warrior | a24acf94d48d635eca668ea34598c6e5c857e3f8 |
| meta-dpdk         | git://git.yoctoproject.org/meta-dpdk         | warrior | c8c30c2c4e2f36b4a55a69a475fe774015423705 |
| meta-amd          | git://git.yoctoproject.org/meta-amd          | warrior | tags/warrior-e3000-ga-202002                                     |

## Softwares
| Software        | Version  |
|:----------------|:---------|
| BIOS            | RWB1100C |
| Yocto Poky Base | 2.7.2    |
| linux-yocto     | 4.19.8   |
| gcc             | 8.3.0    |
| util-linux      | 2.32.1   |
| grub            | 2.02     |
| lttng           | 2.10     |
| babeltrace      | 1.5.6    |
| connman         | 1.36     |
| gdb             | 8.2.1    |
| dpdk            | 18.11.1  |
| strongswan      | 5.7.1    |

## Fixed Issues
| # E3000 Fixed Issues #                                                                                   |
|:---------------------------------------------------------------------------------------------------------|
| SFP peer to peer between two EPYC 3000 is not working.                                                   |
| Reboot test fails at ~30 cycles.                                                                         |
| Transfer rate is very low (3.63Gb/sec) on both kernel for 10G peer to peer (Switch) scenario with iperf. |
| I2C3 fails to operate at FM+ (1000k) and 100k speeds.                                                    |
| Not able to install ubuntu 18.04.1 emmc server OS on eMMC (all modes).                                   |

## Known Issues
| # E3000 Known Issues/Limitations #                                                                                                                   |
|:-----------------------------------------------------------------------------------------------------------------------------------------------------|
| Bandwidth drop observed when running all ports simultaneously with default system configuration and the solution is system level tuning is required. |
| Peer to peer network between EPYC 3000 Series CPUs (using xgbe) is not working with few finisar SFP modules.                                         |
| FIO Sequential Read/Write ZE3351HAQCAAF_30Performs better than ZE3451HAQGAAF_30.                                                                     |
| FIO Random Read/write performance for QD32 BS4k is low compared with spec.                                                                           |
| S3 is not POR for Linux server OS.                                                                                                                   |
| DPDK does not work when IOMMU is enabled in BIOS.                                                                                                    |
