FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
DEPENDS_append_mel-lite = " openssl"
SRC_URI_append_mel-lite = " file://ppp-2.4.7-DES-openssl.patch"
EXTRA_OEMAKE_append_mel-lite = ' COPTS="${CFLAGS} -I${STAGING_INCDIR}/openssl -I${S}/include"'
