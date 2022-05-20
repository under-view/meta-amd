# 4. Customizing images with AMD Features

AMD supports various features and software components that can be
enabled by setting the corresponding configuration variable to a
valid value in the `local.conf`.

Following is a list of components that can be enabled if you want
them to be installed/available on your image, or can be configured:

* **ON-TARGET DEVELOPMENT - SDK for on-target development**

> gcc, make, autotools, autoconf, build-essential etc.

* **ON-TARGET DEBUGGING - tools for on-target debugging**

> gdb, gdbserver, strace, mtrace

* **ON-TARGET PROFILING - tools for on-target profiling**

> lttng, babeltrace, systemtap, powertop, valgrind

* **RT KERNEL - Realtime Kernel support**

> Linux kernel with PREEMPT_RT patch

---
##### Note

Please set the required configuration variables as shown below in the
`local.conf` **before building an image or generating an SDK** (that
can be used to develop apps for these components (if applicable)).

Otherwise they will not be configured, and will not be available on the
target.

---

#### Supported software features

| Software feature      | Configuration variable      | Configuration values | Default value | Supported machines   |
|:----------------------|:----------------------------|:---------------------|:--------------|:---------------------|
| ON-TARGET DEVELOPMENT | EXTRA_IMAGE_FEATURES:append | tools-sdk            |               | milan, rome          |
| ON-TARGET DEBUGGING   | EXTRA_IMAGE_FEATURES:append | tools-debug          |               | milan, rome          |
| ON-TARGET PROFILING   | EXTRA_IMAGE_FEATURES:append | tools-profile        |               | milan, rome          |
| RT KERNEL             | RT_KERNEL_AMD               | yes, no              | no            | milan, rome          |

#### Example configuration in local.conf
```sh
EXTRA_IMAGE_FEATURES:append = " tools-sdk"
EXTRA_IMAGE_FEATURES:append = " tools-debug"
EXTRA_IMAGE_FEATURES:append = " tools-profile"

# Please run 'bitbake -c clean virtual/kernel' everytime before
# configuring the RT_KERNEL_AMD variable
RT_KERNEL_AMD = "yes"
```

In case the user does not have a dGPU, and wants to interact with the
machine over the RS232 serial interface, the user needs to have an
`LPC to UART Adapter` module plugged into the LPC header on the
motherboard.

Using a serial cable connected between the host machine's RS232 port
and this module, the user will be able to interact with the machine
using the serial interface, but will still not be able to install the
OS to a harddrive using the serial interface. For that, the graphical
console has to be disabled. In order to achieve that, add the
following to the `local.conf` and rebuild an image.

```sh
MACHINE_FEATURES:remove = "screen-console"
```

The resulting image will have no graphical console support and will
only have the serial console support. After this, the user will also
be able to install the OS to a harddrive using the serial interface.

---
#### What's next

Continue to "Section 2 - Setting up and starting a build"
([BUILD.md](BUILD.md#23-start-the-build)) and restart the image build
as `bitbake <image-name>`, and deploy the new image to see the
changes take effect.
