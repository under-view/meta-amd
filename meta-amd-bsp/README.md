# meta-amd/meta-amd-bsp

This layer contains metadata that is appropriate for all
AMD-based platforms.

Settings in this layer should use appropriate variable suffixes
to ensure they only apply to expected boards.

## Machines

This layer contains meta-data for the following AMD BSPs:

* r1000
* v1000
* e3000

Please see the README file contained in the root meta-amd directory
for general information and usage details.

## Dependencies

This layer depends on:

[bitbake](https://github.com/openembedded/bitbake) layer,
[oe-core](https://github.com/openembedded/openembedded-core) layer,
[meta-oe](https://github.com/openembedded/meta-openembedded) layer,
[meta-python](https://github.com/openembedded/meta-openembedded/meta-python) layer
