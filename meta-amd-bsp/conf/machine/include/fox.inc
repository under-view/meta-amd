# Setup a getty on all serial ports
SERIAL_CONSOLES = "115200;ttyS4"

# Enable the kernel console on ttyS0/COM0
KERNEL_SERIAL_CONSOLE ?= "console=ttyS4,115200n8"
