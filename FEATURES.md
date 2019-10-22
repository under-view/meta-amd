# Features

This document lists the features supported for the AMD BSPs. In each
BSP column, a "Y" represents that the feature in this row is supported
for this BSP.

| Category                        | Feature                                 | R1000 |
|:--------------------------------|:----------------------------------------|:-----:|
| Images                          |                                         |       |
|                                 | core-image-sato                         | Y     |
|                                 | core-image-base                         |       |
| Images Types                    |                                         |       |
|                                 | WIC                                     | Y     |
|                                 | ISO                                     | Y     |
| Board Devices                   |                                         |       |
|                                 | Ethernet                                | Y     |
|                                 | USB 2.0 Host                            | Y     |
|                                 | USB 3.0 Host (MSC)                      | Y     |
|                                 | USB 3.1 Host                            | Y     |
|                                 | M.2 SATA                                | Y     |
|                                 | I2C                                     | Y     |
|                                 | UART                                    | Y     |
|                                 | eMMC                                    | Y     |
|                                 | SMP                                     | Y     |
|                                 | SPI                                     | Y     |
| I/O                             |                                         |       |
|                                 | USB Host                                | Y     |
|                                 | USB Mass Storage                        | Y     |
|                                 | Audio                                   | Y     |
|                                 | Ethernet                                | Y     |
|                                 | UART                                    | Y     |
|                                 | Bluetooth                               | Y     |
|                                 | Wi-Fi                                   | Y     |
|                                 | HDD/SATA                                | Y     |
|                                 | SGMII                                   | Y     |
|                                 | RGMII                                   | Y     |
|                                 | SD/MMC                                  | Y     |
| General Purpose Kernel Features |                                         |       |
|                                 | Control Groups                          | Y     |
|                                 | CPU Hot Plugging                        | Y     |
|                                 | High Resolution Timers (HRT)            | Y     |
|                                 | POSIX Message Quese & Semaphores        | Y     |
|                                 | Prioritized OOM Killer                  | Y     |
|                                 | Symmetric Multi-Processing (SMP)        | Y     |
|                                 | Native POSIX Thread Library             | Y     |
| Kernel Preemption               |                                         |       |
|                                 | Preemptive Kernel (Low-Latency Desktop) | Y     |
|                                 | Fully Preemptible Kernel (RT)           |       |
| Filesystems                     |                                         |       |
|                                 | Devtmpfs                                | Y     |
|                                 | EXT2                                    | Y     |
|                                 | EXT3                                    | Y     |
|                                 | EXT4                                    | Y     |
|                                 | FAT                                     | Y     |
|                                 | NFSv3                                   | Y     |
|                                 | ProcFS                                  | Y     |
|                                 | RamFS                                   | Y     |
|                                 | SysFS                                   | Y     |
|                                 | tmpfs                                   | Y     |
| HID (Input Devices)             |                                         |       |
|                                 | Input Core (CONFIG_INPUT)               | Y     |
|                                 | Mouse Interface                         | Y     |
|                                 | Keyboards                               | Y     |
|                                 | Touchscreen                             | Y     |
| Display Device Support          |                                         |       |
|                                 | DP                                      | Y     |
|                                 | HDMI                                    | Y     |
| Network Protocols               |                                         |       |
|                                 | IPv4                                    | Y     |
|                                 | IPv6                                    | Y     |
| Kernel Debug/Trace              |                                         |       |
|                                 | KGDB                                    | Y     |
|                                 | LTTng - Kernel Tracing                  | Y     |
|                                 | LTTng - Userspace Tracing               | Y     |
| USB Protocols                   |                                         |       |
|                                 | USB 2.0                                 | Y     |
|                                 | USB 3.0                                 | Y     |
|                                 | USB 3.1                                 | Y     |
|                                 | USB HS                                  | Y     |
| Sound Support                   |                                         |       |
|                                 | ALSA                                    | Y     |
| Multimedia Support              |                                         |       |
|                                 | Accelerated gstreamer                   | Y     |
|                                 | Unaccelerated gstreamer                 | Y     |
|                                 | OMX                                     | Y     |
|                                 | VDPAU                                   | Y     |
|                                 | VAAPI                                   | Y     |
|                                 | mesa (accelerated graphics)             | Y     |
|                                 | unaccelerated graphics                  | Y     |
|                                 | Vulkan                                  | Y     |
|                                 | multi-display                           | Y     |
|                                 | CodeXL                                  |       |
|                                 | RGP                                     | Y     |
|                                 | MP4                                     | Y     |
|                                 | MPEG2                                   | Y     |
|                                 | MPEG4                                   | Y     |
|                                 | VC-1                                    | Y     |
|                                 | H.264                                   | Y     |
|                                 | H.265                                   | Y     |
|                                 | ROCm-OpenCL                             |       |
| Network Security                |                                         |       |
|                                 | IPSEC (strongswan)                      |       |
|                                 | DPDK                                    |       |
| Kernel Virtualization           |                                         |       |
|                                 | KVM                                     |       |
