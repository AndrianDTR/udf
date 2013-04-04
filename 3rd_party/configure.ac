# Autoconf
AC_PREREQ(2.61)
AC_INIT([udf-3rd-party], [trunk])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

# Check System
AC_C_BIGENDIAN
AC_CANONICAL_SYSTEM

# Automake
AM_INIT_AUTOMAKE([subdir-objects -Wall foreign tar-ustar 1.11])
AM_SILENT_RULES([yes])

# Libtool
LTVER="1:0:0"
AC_SUBST(LTVER)
LT_INIT([shared])

AC_SUBST(UDF_WITH_CPPFLAGS)
AC_SUBST(UDF_WITH_LDFLAGS)
AC_SUBST(UDF_WITH_LDADD)

# Check CPU and CPU Endianness
AM_CONDITIONAL([TARGET_CPU_X86],[test "x$target_cpu" = "xi686" -o "x$target_cpu" = "xi386"])
AM_CONDITIONAL([TARGET_CPU_LE], [test "x$ac_cv_c_bigendian" = "xno"])

# Check OS
target_os_linux=no
target_os_windows=no

case "$target_os" in
linux*)
	target_os_linux=yes
	AC_MSG_CHECKING(compiling for Linux)
	AC_DEFINE([OS_LINUX],[1],[OS_LINUX])
	;;
windows*)
	target_os_windows=yes
	AC_MSG_CHECKING(compiling for Windows)
	AC_DEFINE([OS_WINDOWS],[1],[OS_WINDOWS])
	;;
esac

AM_CONDITIONAL([TARGET_OS_LINUX],[test "x$target_os_linux" = "xyes"])
AM_CONDITIONAL([TARGET_OS_WINDOWS],[test "x$target_os_windows" = "xyes"])

# Check Programs
AC_PROG_CC
AC_PROG_CXX

# More configure flags
export CXXFLAGS="$CXXFLAGS -DNDEBUG -g0 -O2"
export CFLAGS="$CFLAGS -DNDEBUG -g0 -O2"

# Packages
AC_BUILD_WXWIDGETS
AC_BUILD_BOOST
AC_BUILD_MYSQLCPPCON
echo "3rd All0 QQQQQQQQQ" `pwd`
# Configuration Files
AC_CONFIG_FILES([
	Makefile
])

echo "3rd All QQQQQQQQQ" `pwd`
AC_OUTPUT

