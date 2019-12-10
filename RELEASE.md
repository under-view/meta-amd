# Release notes

This is the release notes document for the AMD BSP V1000. This document
contains information about the Yocto layers' git repos, their branches
and commit hashes, software versions, and known/fixed issues/limitations.

## Layers
| Layer             | Git Repo                                     | Branch  | Commit Hash                              |
|:------------------|:---------------------------------------------|:--------|:-----------------------------------------|
| poky              | git://git.yoctoproject.org/poky              | warrior | 79a850a10a4b88a6d20d607b322542f947874323 |
| meta-openembedded | git://git.openembedded.org/meta-openembedded | warrior | f4ccdf2bc3fe4f00778629088baab840c868e36b |
| meta-dpdk         | git://git.yoctoproject.org/meta-dpdk         | warrior | c8c30c2c4e2f36b4a55a69a475fe774015423705 |
| meta-amd          | git://git.yoctoproject.org/meta-amd          | warrior | tags/warrior-v1000-ga-201912                                     |

## Softwares
| Software       | Version      |
|:---------------|:-------------|
| BIOS           | RBB1202B     |
| linux-yocto    | 4.19.8       |
| gcc            | 8.3.0        |
| util-linux     | 2.32.1       |
| grub           | 2.02         |
| pulseaudio     | 12.2         |
| xf86-video-amd | 19.0.1       |
| xserver        | 1.20.4       |
| mesa           | 19.2.0-devel |
| libdrm         | 2.4.99       |
| llvm           | 9.0.0        |
| vulkan         | 1.1.92.1     |
| libomxil       | 0.9.3        |
| libva          | 2.4.0        |
| libvdpau       | 1.1.1        |
| gstreamer      | 1.14.4       |
| mpv            | 0.28.2       |
| ffmpeg         | 4.0.2        |
| lttng          | 2.10         |
| babeltrace     | 1.5.6        |
| connman        | 1.36         |
| gdb            | 8.2.1        |
| rgp            | 1.5.1        |

## Fixed Issues
| # V1000 Fixed Issues #                                                              |
|:------------------------------------------------------------------------------------|
| Hard hang with mpv vaapi-vappi configuration in fullscreen mode on V1000            |
| Stutter observed with 4k@60 video playback on V1000                                 |
| Display goes blank after hotplug of third monitor on V1000                          |
| Glmark2 overnight hang                                                              |
| I2S Audio one side of headset is not audible while playing i2S audio on V1000/R1000 |

## Known Issues
| # V1000 Known Issues/Limitations #                                                                                    |
|:----------------------------------------------------------------------------------------------------------------------|
| Stuttering is observed with vulkan hologram sample on 4k monitor full screen mode                                     |
| S3 fails at 25th cycle on Dibbler V1000 due to PSP bug                                                                |
| Display artifacts while doing S3 with max 4k monitors on APU’s                                                        |
| __* XGBE__                                                                                                            |
| SFP wont work on V1807 platforms after few hours                                                                      |
| Ethernet link is showing always up on RJ45 ports of Bilby platforms                                                   |
| _** Workaround: Disable the port which is not connected the ethernet cable_                                           |
| Hotplug failures and stability issue with longer duration performance test on Bilby platforms with RJ45 ports enabled |
| _** Workaround: Disable the port which is not connected the ethernet cable_                                           |
| Can’t concurrently enable SFP+ and RJ45 interfaces                                                                    |
| Peer to Peer network is unstable with 1/10G SFP (FC)                                                                  |
| No IEEE 1588 Timestamp support                                                                                        |
| No receive split header support                                                                                       |
| __* Following features should be functional but have not been fully validated:__                                      |
| *** Priority and VLAN (VLAN Priority Control)                                                                         |
| *** RMON Counter                                                                                                      |
| *** VLAN support and Receive-Side scaling                                                                             |
| *** 2.5G TCP/IP offload (duplex) and 2.5G jumbo frames (duplex)                                                       |
