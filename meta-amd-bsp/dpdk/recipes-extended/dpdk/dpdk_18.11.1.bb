require recipes-extended/dpdk/dpdk.inc

DEPENDS += "openssl"

STABLE = "-stable"
BRANCH = "18.11"
SRCREV = "16ece46735c9b70b7033ca7ae095930e9038d9fd"

LICENSE = "BSD & LGPLv2 & GPLv2"
LIC_FILES_CHKSUM = "file://license/gpl-2.0.txt;md5=b234ee4d69f5fce4486a80fdaf4a4263 \
                    file://license/lgpl-2.1.txt;md5=4b54a1fd55a448865a0b32d41598759d \
                    file://license/bsd-3-clause.txt;md5=0f00d99239d922ffd13cabef83b33444"

# takes n or y
BUILD_SHARED = "n"
do_configure_prepend () {
	# enable the AMD CCP driver
	sed -e "s#CONFIG_RTE_LIBRTE_PMD_CCP=n#CONFIG_RTE_LIBRTE_PMD_CCP=y#" -i ${S}/config/common_base
	sed -e "s#CONFIG_RTE_LIBRTE_PMD_CCP_CPU_AUTH=n#CONFIG_RTE_LIBRTE_PMD_CCP_CPU_AUTH=y#" -i ${S}/config/common_base

	# shared libs are a more convenient way for development but then the user
	# has to load the PMD explicitly with the -d flag so be careful
	sed -e "s#CONFIG_RTE_BUILD_SHARED_LIB=n#CONFIG_RTE_BUILD_SHARED_LIB=${BUILD_SHARED}#" -i ${S}/config/common_base
}

COMPATIBLE_MACHINE_snowyowl = "snowyowl"
DPDK_TARGET_MACHINE_snowyowl = "znver1"
TUNE_FEATURES += "m64"
