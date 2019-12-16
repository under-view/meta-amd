# Features

This section lists the features supported for the AMD BSPs. In each
BSP column, a 'Y' represents that the feature in this row is supported
for this BSP.

| Category                        | Feature                                 | R1000 | V1000 | E3000 |
|:--------------------------------|:----------------------------------------|:-----:|:-----:|:-----:|
| Images                          |                                         |       |       |       |
|                                 | core-image-sato                         | Y     | Y     |       |
|                                 | core-image-base                         |       |       | Y     |
| Images Types                    |                                         |       |       |       |
|                                 | WIC                                     | Y     | Y     | Y     |
|                                 | ISO                                     | Y     | Y     | Y     |
| Board Devices                   |                                         |       |       |       |
|                                 | Ethernet                                | Y     | Y     | Y     |
|                                 | USB 2.0 Host                            | Y     | Y     | Y     |
|                                 | USB 3.0 Host (MSC)                      | Y     | Y     | Y     |
|                                 | USB 3.1 Host                            | Y     | Y     |       |
|                                 | M.2 SATA                                | Y     | Y     |       |
|                                 | I2C                                     | Y     | Y     | Y     |
|                                 | UART                                    | Y     | Y     | Y     |
|                                 | eMMC                                    | Y     | Y     | Y     |
|                                 | SMP                                     | Y     | Y     | Y     |
|                                 | SPI                                     | Y     | Y     | Y     |
| I/O                             |                                         |       |       |       |
|                                 | USB Host                                | Y     | Y     | Y     |
|                                 | USB Mass Storage                        | Y     | Y     | Y     |
|                                 | Audio                                   | Y     | Y     |       |
|                                 | Ethernet                                | Y     | Y     | Y     |
|                                 | UART                                    | Y     | Y     | Y     |
|                                 | Bluetooth                               | Y     | Y     |       |
|                                 | Wi-Fi                                   | Y     | Y     | Y     |
|                                 | HDD/SATA                                | Y     | Y     | Y     |
|                                 | SGMII                                   | Y     | Y     | Y     |
|                                 | RGMII                                   | Y     | Y     | Y     |
|                                 | SD/MMC                                  | Y     | Y     | Y     |
| General Purpose Kernel Features |                                         |       |       |       |
|                                 | Control Groups                          | Y     | Y     | Y     |
|                                 | CPU Hot Plugging                        | Y     | Y     | Y     |
|                                 | High Resolution Timers (HRT)            | Y     | Y     | Y     |
|                                 | POSIX Message Quese & Semaphores        | Y     | Y     | Y     |
|                                 | Prioritized OOM Killer                  | Y     | Y     | Y     |
|                                 | Symmetric Multi-Processing (SMP)        | Y     | Y     | Y     |
|                                 | Native POSIX Thread Library             | Y     | Y     | Y     |
| Kernel Preemption               |                                         |       |       |       |
|                                 | Preemptive Kernel (Low-Latency Desktop) | Y     | Y     | Y     |
|                                 | Fully Preemptible Kernel (RT)           |       |       | Y     |
| Filesystems                     |                                         |       |       |       |
|                                 | Devtmpfs                                | Y     | Y     | Y     |
|                                 | EXT2                                    | Y     | Y     | Y     |
|                                 | EXT3                                    | Y     | Y     | Y     |
|                                 | EXT4                                    | Y     | Y     | Y     |
|                                 | FAT                                     | Y     | Y     | Y     |
|                                 | NFSv3                                   | Y     | Y     | Y     |
|                                 | ProcFS                                  | Y     | Y     | Y     |
|                                 | RamFS                                   | Y     | Y     | Y     |
|                                 | SysFS                                   | Y     | Y     | Y     |
|                                 | tmpfs                                   | Y     | Y     | Y     |
| HID (Input Devices)             |                                         |       |       |       |
|                                 | Input Core (CONFIG_INPUT)               | Y     | Y     | Y     |
|                                 | Mouse Interface                         | Y     | Y     |       |
|                                 | Keyboards                               | Y     | Y     | Y     |
|                                 | Touchscreen                             | Y     | Y     |       |
| Display Device Support          |                                         |       |       |       |
|                                 | DP                                      | Y     | Y     |       |
|                                 | HDMI                                    | Y     | Y     |       |
| Network Protocols               |                                         |       |       |       |
|                                 | IPv4                                    | Y     | Y     | Y     |
|                                 | IPv6                                    | Y     | Y     | Y     |
| Kernel Debug/Trace              |                                         |       |       |       |
|                                 | KGDB                                    | Y     | Y     | Y     |
|                                 | LTTng - Kernel Tracing                  | Y     | Y     | Y     |
|                                 | LTTng - Userspace Tracing               | Y     | Y     | Y     |
| USB Protocols                   |                                         |       |       |       |
|                                 | USB 2.0                                 | Y     | Y     | Y     |
|                                 | USB 3.0                                 | Y     | Y     | Y     |
|                                 | USB 3.1                                 | Y     | Y     |       |
|                                 | USB HS                                  | Y     | Y     | Y     |
| Sound Support                   |                                         |       |       |       |
|                                 | ALSA                                    | Y     | Y     |       |
| Multimedia Support              |                                         |       |       |       |
|                                 | Accelerated gstreamer                   | Y     | Y     |       |
|                                 | Unaccelerated gstreamer                 | Y     | Y     |       |
|                                 | OMX                                     | Y     | Y     |       |
|                                 | VDPAU                                   | Y     | Y     |       |
|                                 | VAAPI                                   | Y     | Y     |       |
|                                 | mesa (accelerated graphics)             | Y     | Y     |       |
|                                 | unaccelerated graphics                  | Y     | Y     |       |
|                                 | Vulkan                                  | Y     | Y     |       |
|                                 | multi-display                           | Y     | Y     |       |
|                                 | CodeXL                                  |       |       |       |
|                                 | RGP                                     | Y     | Y     |       |
|                                 | MP4                                     | Y     | Y     |       |
|                                 | MPEG2                                   | Y     | Y     |       |
|                                 | MPEG4                                   | Y     | Y     |       |
|                                 | VC-1                                    | Y     | Y     |       |
|                                 | H.264                                   | Y     | Y     |       |
|                                 | H.265                                   | Y     | Y     |       |
|                                 | ROCm-OpenCL                             |       |       |       |
| Network Security                |                                         |       |       |       |
|                                 | IPSEC (strongswan)                      |       |       | Y     |
|                                 | DPDK                                    |       |       | Y     |
| Kernel Virtualization           |                                         |       |       |       |
|                                 | KVM                                     |       |       | Y     |
