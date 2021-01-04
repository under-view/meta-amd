# Features

This section lists the features supported for the AMD BSPs. In each
BSP column, a 'Y' represents that the feature in this row is supported
for this BSP.

| Category                        | Feature                                 | E3000 |
|:--------------------------------|:----------------------------------------|:-----:|
| Images                          |                                         |       |
|                                 | core-image-sato                         |       |
|                                 | core-image-base                         | Y     |
| Images Types                    |                                         |       |
|                                 | WIC                                     | Y     |
|                                 | ISO                                     | Y     |
| Board Devices                   |                                         |       |
|                                 | USB 2.0 Host                            | Y     |
|                                 | USB 3.0 Host (MSC)                      | Y     |
|                                 | USB 3.1 Host                            |       |
|                                 | M.2 SATA                                |       |
|                                 | I2C                                     | Y     |
|                                 | UART                                    | Y     |
|                                 | eMMC                                    | Y     |
|                                 | SMP                                     | Y     |
|                                 | SPI                                     | Y     |
| I/O                             |                                         |       |
|                                 | USB Host                                | Y     |
|                                 | USB Mass Storage                        | Y     |
|                                 | Audio                                   |       |
|                                 | UART                                    | Y     |
|                                 | Bluetooth                               |       |
|                                 | USB Wi-Fi                               | Y     |
|                                 | HDD/SATA                                | Y     |
|                                 | SD/MMC                                  | Y     |
| Networking                      |                                         |       |
|                                 | Ethernet                                | Y     |
|                                 | SGMII                                   | Y     |
|                                 | RGMII                                   | Y     |
| General Purpose Kernel Features |                                         |       |
|                                 | Control Groups                          | Y     |
|                                 | CPU Hot Plugging                        | Y     |
|                                 | High Resolution Timers (HRT)            | Y     |
|                                 | POSIX Message Queues & Semaphores       | Y     |
|                                 | Prioritized OOM Killer                  | Y     |
|                                 | Symmetric Multi-Processing (SMP)        | Y     |
|                                 | Native POSIX Thread Library             | Y     |
| Kernel Preemption               |                                         |       |
|                                 | Preemptive Kernel (Low-Latency Desktop) | Y     |
|                                 | Fully Preemptible Kernel (RT)           | Y     |
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
|                                 | Mouse Interface                         |       |
|                                 | Keyboards                               | Y     |
|                                 | Touchscreen                             |       |
| Display Device Support          |                                         |       |
|                                 | DP                                      |       |
|                                 | HDMI                                    |       |
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
|                                 | USB 3.1                                 |       |
|                                 | USB HS                                  | Y     |
| Sound Support                   |                                         |       |
|                                 | ALSA                                    |       |
| Multimedia Support              |                                         |       |
|                                 | Accelerated gstreamer                   |       |
|                                 | Unaccelerated gstreamer                 |       |
|                                 | OMX                                     |       |
|                                 | VDPAU                                   |       |
|                                 | VAAPI                                   |       |
|                                 | mesa (accelerated graphics)             |       |
|                                 | unaccelerated graphics                  |       |
|                                 | Vulkan                                  |       |
|                                 | multi-display                           |       |
|                                 | CodeXL                                  |       |
|                                 | RGP                                     |       |
|                                 | MP4                                     |       |
|                                 | MPEG2                                   |       |
|                                 | MPEG4                                   |       |
|                                 | VC-1                                    |       |
|                                 | H.264                                   |       |
|                                 | H.265                                   |       |
|                                 | ROCm-OpenCL                             |       |
| Network Security                |                                         |       |
|                                 | IPSEC (strongswan)                      | Y     |
|                                 | DPDK                                    | Y     |
| Kernel Virtualization           |                                         |       |
|                                 | KVM                                     | Y     |
