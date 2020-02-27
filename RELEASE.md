# Release notes

This is the release notes document for the AMD BSP R1000. This document
contains information about the Yocto layers' git repos, their branches
and commit hashes, software versions, and known/fixed issues/limitations.

## Layers
| Layer             | Git Repo                                     | Branch  | Commit Hash                              |
|:------------------|:---------------------------------------------|:--------|:-----------------------------------------|
| poky              | git://git.yoctoproject.org/poky              | warrior | 023ff85a9ae94331926e923b346fd8a349881e63 |
| meta-openembedded | git://git.openembedded.org/meta-openembedded | warrior | a24acf94d48d635eca668ea34598c6e5c857e3f8 |
| meta-dpdk         | git://git.yoctoproject.org/meta-dpdk         | warrior | c8c30c2c4e2f36b4a55a69a475fe774015423705 |
| meta-amd          | git://git.yoctoproject.org/meta-amd          | warrior | tags/warrior-r1000-ga-202002                                     |

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
| R1000 Fixed Issues                                                                                                              |
|:--------------------------------------------------------------------------------------------------------------------------------|
| APU power consumption for static idle cases is on par with windows on Raven platforms.                                          |
| Heavy stutter and tearing observed with skype video conference on R1000 LP.                                                     |
| [XGBE]: Peer to Peer network is unstable with 1/10G SFP (FC).                                                                   |
| [XGBE]: RJ45 Hotplug of XGBE function is not working.                                                                           |
| [XGBE]: Ethernet Link is showing always up on RJ45 ports of Bilby platforms.                                                    |
| [XGBE]: Hot plug failures and stability issue with longer duration performance test on Bilby platforms with RG45 ports enabled. |

## Known Issues
| __* R1000 LP Known Issues/Limitations__                                                                                  |
|:-------------------------------------------------------------------------------------------------------------------------|
| Stutter and frame drops observed 4k video playback.                                                                      |
| Minor Tearing is observed while doing skype video calling in fullscreen.                                                 |
| Heavy stutters and framedrops observed after resuming from sleep.                                                        |
| Heavy stutter in slideshow presentation and Multimedia playback in dual monitor usecase.                                 |
| Randomly video playback with S3 fails while doing manually on R1000LP. Workaround mentioned in R1000 issues list below.  |
| __* R1000 Known Issues/Limitations__                                                                                     |
| 1. Randomly Network is disabled after every suspend and resume on Raven platforms.                                       |
| SFP Port-0 is not getting detected for 10G RJ45 SFP Transceiver on Raven Platforms.                                      |
| SFP Port-0 is not getting detected for 2.5G network usecases on Raven Platforms.                                         |
| Soft hang observed on Video Playback and S3 in MST (Daisy Chain).                                                        |
| Not showing GPU Load in amdgpu_pm_info sysfs entry on V1000 and R1000/LP.                                                |
| User experience is very poor after hotplug on mGPU config with more than 6 monitors.                                     |
| Stuttering is observed with vulkan hologram sample on 4k monitor full screen mode.                                       |
