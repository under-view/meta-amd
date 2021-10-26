# Release notes

This is the release notes document for the AMD machine VERMEER. This document
contains information about the Yocto layers' git repos, their branches
and commit hashes, software versions, and known/fixed issues/limitations.

## Bitbake layers
| Layer             | Git Repo                                     | Branch    | Commit Hash/Tag                          |
|:------------------|:---------------------------------------------|:----------|:-----------------------------------------|
| poky              | git://git.yoctoproject.org/poky              | hardknott | tags/yocto-3.3.2                         |
| meta-openembedded | git://git.openembedded.org/meta-openembedded | hardknott | aaa1c12b2cdea197d420953c8df873e8af5cc507 |
| meta-dpdk         | git://git.yoctoproject.org/meta-dpdk         | hardknott | c011004a49ffb1304f376f0fdc65066913102d5f |
| meta-amd          | git://git.yoctoproject.org/meta-amd          | hardknott | tags/hardknott-vermeer-ga-202110                                     |

## Software versions
| Software        | Version  |
|:----------------|:---------|
| Yocto Poky base | 3.3.2    |
| grub            | 2.06-rc1 |
| linux-yocto     | 5.10.47  |
| linux-yocto-rt  | 5.10.47  |
| gcc             | 10.2.0   |
| util-linux      | 2.36.2   |
| lttng           | 2.12     |
| babeltrace      | 1.5.8    |
| connman         | 1.39     |
| gdb             | 10.1     |
| dpdk            | 20.11.1  |
| strongswan      | 5.9.2    |

## Fixed issues
| __VERMEER Fixed Issues__ |
|:-------------------------|
| None                     |

## Known issues
| __VERMEER Known Issues/Limitations__                                                                                                                                                                            |
|:----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| The Qogir board for Vermeer does not have an RS232/UART serial port/header.                                                                                                                                     |
| _** Workaround: Use an LPC to UART Adapter module for serial communication_                                                                                                                                     |
| The serial communication from a host machine with Vermeer using an LPC to UART Adapter module may not work properly with some hosts because the module lacks Hardware Flow Control signals such as CTS and RTS. |
| _** Workaround: Connect the RTS & CTS pins on the host side with each other in order to achieve a No Handshake based serial communication_                                                                      |
| Install option in the GRUB menu does not work by default using the serial interface and only works on the graphical console.                                                                                    |
| _** Workaround: Disable the graphical console by setting `MACHINE_FEATURES_remove = “screen-console”` in the `local.conf` and rebuild an image_                                                                 |
