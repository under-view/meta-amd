include boost-${PV}.inc
include recipes-support/boost/boost.inc

# poky/meta/recipes-support/boost/boost.inc for boost v1.69.0 in warrior branch
# changes the list of BOOST_LIBS. We change it back to previous settings as
# the library "contract" does not exist in boost v1.59.0, so the do_compile fails.
BOOST_LIBS_append = " signals"
BOOST_LIBS_remove = " contract"

SRC_URI += "\
    file://arm-intrinsics.patch \
    file://consider-hardfp.patch \
    file://boost-CVE-2012-2677.patch \
    file://0001-boost-asio-detail-socket_types.hpp-fix-poll.h-includ.patch \
    file://0002-boost-test-execution_monitor.hpp-fix-mips-soft-float.patch \
    file://0003-smart_ptr-mips-assembly-doesn-t-compile-in-mips16e-m.patch \
    file://0004-Use-atomic-by-default-when-BOOST_NO_CXX11_HDR_ATOMIC.patch \
    file://boost-math-disable-pch-for-gcc.patch \
    file://0001-boost-libs-python-converter-fix-build-with-gcc8.patch \
"

TARGET_CPPFLAGS += " -D_GLIBCXX_USE_CXX11_ABI=0"
