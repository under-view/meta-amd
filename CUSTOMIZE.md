# Customizing images with AMD Features

AMD supports various features and software components that can be
enabled by setting the corresponding configuration variable to a
valid value in the `local.conf`.

Following is a list of components that can be enabled if you want
them to be installed/available on your image, or can be configured:

* **VULKAN - Vulkan driver and Loader Layer.**

  It is required to run Vulkan based applications. Vulkan is a new
  generation graphics and compute API that provides high-efficiency,
  cross-platform access to modern GPUs.

* **MPV \* - Video player based on MPlayer/mplayer2**

  MPV is a movie player based on MPlayer and mplayer2. It supports a
  wide variety of video file formats, audio and video codecs, and
  subtitle types.

* **COMMERCIAL MULTIMEDIA \* - License restricted multimedia components**

  Certain multimedia formats require license restricted codecs and
  software components which are not included in build by default.

* **MULTI DISPLAY - Multiple display support**

  You can connect multiple displays with AMD machines. The display
  configuration/arrangement can be configured using this.

* **ON-TARGET DEVELOPMENT - SDK for on-target development**

  gcc, make, autotools, autoconf, build-essential etc.

* **ON-TARGET DEBUGGING - tools for on-target debugging**

  gdb, gdbserver, strace, mtrace

* **ON-TARGET PROFILING - tools for on-target profiling**

  lttng, babeltrace, systemtap, powertop, valgrind

---
#### Disclaimer

\* Using **MPV** & **COMMERCIAL MULTIMEDIA** requires use of
license-restricted algorithms or software.

\* AMD does not distribute or endorse sources for license-restricted
algorithms or software, and disclaims any liability for their use.

---
##### Note

Please set the required configuration variables as shown below in the
`local.conf` **before building an image or generating an SDK** (that
can be used to develop apps for these components (if applicable)).

Otherwise they will not be configured, and will not be available on the
target.

---

#### Supported Features

| Feature               | Configuration variable        | Configuration values                   | Default value | Supported BSPs |
|:----------------------|:------------------------------|:---------------------------------------|:--------------|:---------------|
| VULKAN                | INCLUDE_VULKAN                | yes, no                                | no            | r1000          |
| MPV                   | INCLUDE_MPV                   | yes, no                                | no            | r1000          |
| COMMERCIAL MULTIMEDIA | INCLUDE_COMMERCIAL_MULTIMEDIA | yes, no                                | no            | r1000          |
| MULTI DISPLAY         | MULTI_DISPLAY_MODE            | auto, mirrored, extended-v, extended-h | auto          | r1000          |
| ON-TARGET DEVELOPMENT | EXTRA_IMAGE_FEATURES_append   | tools-sdk                              |               | r1000          |
| ON-TARGET DEBUGGING   | EXTRA_IMAGE_FEATURES_append   | tools-debug                            |               | r1000          |
| ON-TARGET PROFILING   | EXTRA_IMAGE_FEATURES_append   | tools-profile                          |               | r1000          |

#### Example configuration in local.conf
```sh
INCLUDE_VULKAN = "yes"
INCLUDE_MPV = "yes"
INCLUDE_COMMERCIAL_MULTIMEDIA = "yes"

MULTI_DISPLAY_MODE = "auto"

EXTRA_IMAGE_FEATURES_append = " tools-sdk"
EXTRA_IMAGE_FEATURES_append = " tools-debug"
EXTRA_IMAGE_FEATURES_append = " tools-profile"
```

---
#### What's next

Continue to [section 2 - build](BUILD.md#23-start-the-build) and
restart the image build as `bitbake <image-name>`, and deploy the
new image to see the changes take effect.
