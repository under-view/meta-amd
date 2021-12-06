# Features

This section lists the features supported on the AMD machines. In each
machine column, a 'Y' represents that the feature in this row is supported
on this machine.

| Category                        | Feature                                 | MILAN | ROME | VERMEER |
|:--------------------------------|:----------------------------------------|:-----:|:----:|:-------:|
| Images                          |                                         |       |      |         |
|                                 | core-image-sato                         |       |      |         |
|                                 | core-image-base                         | Y     | Y    | Y       |
| Images Types                    |                                         |       |      |         |
|                                 | WIC                                     | Y     | Y    | Y       |
|                                 | ISO                                     | Y     | Y    | Y       |
| Board Devices                   |                                         |       |      |         |
|                                 | USB 2.0 Host                            | Y     | Y    | Y       |
|                                 | USB 3.0 Host (MSC)                      | Y     | Y    | Y       |
|                                 | USB 3.1 Host                            |       |      | Y       |
|                                 | USB Type C                              |       |      | Y       |
|                                 | NVMe                                    | Y     | Y    | Y       |
|                                 | M.2 SATA                                |       |      | Y       |
|                                 | I2C                                     | Y     | Y    | Y       |
|                                 | UART                                    | Y     | Y    |         |
|                                 | eMMC                                    |       |      |         |
|                                 | SMP                                     | Y     | Y    | Y       |
|                                 | SPI                                     | Y     | Y    | Y       |
| I/O                             |                                         |       |      |         |
|                                 | USB Host                                | Y     | Y    | Y       |
|                                 | USB Mass Storage                        | Y     | Y    | Y       |
|                                 | Audio                                   |       |      |         |
|                                 | UART                                    | Y     | Y    | Y*      |
|                                 | _* via LPC to UART Adapter module_      |       |      |         |
|                                 | Bluetooth                               |       |      |         |
|                                 | USB Wi-Fi                               |       |      |         |
|                                 | HDD/SATA                                | Y     | Y    | Y       |
|                                 | SD/MMC                                  |       |      |         |
| Networking                      |                                         |       |      |         |
|                                 | Ethernet                                |       |      | Y       |
|                                 | SGMII                                   |       |      | Y       |
|                                 | RGMII                                   |       |      | Y       |
| Network Protocols               |                                         |       |      |         |
|                                 | IPv4                                    | Y     | Y    | Y       |
|                                 | IPv6                                    | Y     | Y    | Y       |
| General Purpose Kernel Features |                                         |       |      |         |
|                                 | Control Groups                          | Y     | Y    | Y       |
|                                 | CPU Hot Plugging                        | Y     | Y    | Y       |
|                                 | High Resolution Timers (HRT)            | Y     | Y    | Y       |
|                                 | POSIX Message Queues & Semaphores       | Y     | Y    | Y       |
|                                 | Prioritized OOM Killer                  | Y     | Y    | Y       |
|                                 | Symmetric Multi-Processing (SMP)        | Y     | Y    | Y       |
|                                 | Native POSIX Thread Library             | Y     | Y    | Y       |
| Kernel Preemption               |                                         |       |      |         |
|                                 | Preemptive Kernel (Low-Latency Desktop) | Y     | Y    | Y       |
|                                 | Fully Preemptible Kernel (RT)           | Y     | Y    | Y       |
| Filesystems                     |                                         |       |      |         |
|                                 | Devtmpfs                                | Y     | Y    | Y       |
|                                 | EXT2                                    | Y     | Y    | Y       |
|                                 | EXT3                                    | Y     | Y    | Y       |
|                                 | EXT4                                    | Y     | Y    | Y       |
|                                 | FAT                                     | Y     | Y    | Y       |
|                                 | NFSv3                                   | Y     | Y    | Y       |
|                                 | ProcFS                                  | Y     | Y    | Y       |
|                                 | RamFS                                   | Y     | Y    | Y       |
|                                 | SysFS                                   | Y     | Y    | Y       |
|                                 | tmpfs                                   | Y     | Y    | Y       |
| HID (Input Devices)             |                                         |       |      |         |
|                                 | Input Core (CONFIG_INPUT)               | Y     | Y    | Y       |
|                                 | Mouse Interface                         |       |      |         |
|                                 | Keyboards                               | Y     | Y    | Y       |
|                                 | Touchscreen                             |       |      |         |
| Display Device Support          |                                         |       |      |         |
|                                 | DP                                      |       |      |         |
|                                 | HDMI                                    |       |      |         |
| Kernel Debug/Trace              |                                         |       |      |         |
|                                 | KGDB                                    | Y     | Y    | Y       |
|                                 | LTTng - Kernel Tracing                  | Y     | Y    | Y       |
|                                 | LTTng - Userspace Tracing               | Y     | Y    | Y       |
| USB Protocols                   |                                         |       |      |         |
|                                 | USB 2.0                                 | Y     | Y    | Y       |
|                                 | USB 3.0                                 | Y     | Y    | Y       |
|                                 | USB 3.1                                 |       |      | Y       |
| Sound Support                   |                                         |       |      |         |
|                                 | ALSA                                    |       |      |         |
| Multimedia Support              |                                         |       |      |         |
|                                 | Accelerated gstreamer                   |       |      |         |
|                                 | Unaccelerated gstreamer                 |       |      |         |
|                                 | OMX                                     |       |      |         |
|                                 | VDPAU                                   |       |      |         |
|                                 | VAAPI                                   |       |      |         |
|                                 | mesa (accelerated graphics)             |       |      |         |
|                                 | unaccelerated graphics                  |       |      |         |
|                                 | Vulkan                                  |       |      |         |
|                                 | multi-display                           |       |      |         |
|                                 | CodeXL                                  |       |      |         |
|                                 | RGP                                     |       |      |         |
|                                 | MP4                                     |       |      |         |
|                                 | MPEG2                                   |       |      |         |
|                                 | MPEG4                                   |       |      |         |
|                                 | VC-1                                    |       |      |         |
|                                 | H.264                                   |       |      |         |
|                                 | H.265                                   |       |      |         |
|                                 | ROCm-OpenCL                             |       |      |         |
| Network Security                |                                         |       |      |         |
|                                 | IPSEC (strongswan)                      |       |      |         |
|                                 | DPDK                                    |       |      |         |
| Kernel Virtualization           |                                         |       |      |         |
|                                 | KVM                                     | Y     | Y    | Y       |
