# Autoconf
AC_PREREQ(2.61)
m4_include([version.m4])
AC_INIT([udf], VERSION_NUMBER)
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

# Check System
AC_C_BIGENDIAN
AC_CANONICAL_SYSTEM

# Automake
AM_INIT_AUTOMAKE([subdir-objects -Wall foreign tar-pax 1.11])
AM_SILENT_RULES([yes])

# Libtool
LTVER="1:0:0"
AC_SUBST(LTVER)
LT_INIT([shared])

export abs_builddir=`pwd`
export abs_srcdir=`cd $srcdir && pwd`

# Check CPU and CPU Endianness
AM_CONDITIONAL([TARGET_CPU_X86],[test "x$target_cpu" = "xi686" -o "x$target_cpu" = "xi386" -o "x$target_cpu" = "xx86_64"])
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
BB_ENABLE_DOXYGEN

# Modules
AM_CONDITIONAL([ENABLE_DOXYGEN],[test "x$enable_doxygen" = "xyes"])

# 3rd party build
AC_ARG_WITH([udf-3rd-party],
	[AS_HELP_STRING([--with-udf-3rd-party]
		, [include udf-3rd-party (yes|no) [default=yes]]
		)]
	, []
	, [with_udf_3rd_party=yes]
)
AM_CONDITIONAL([WITH_UDF_3RD_PARTY], [test "x$with_udf_3rd_party" != "xno"])

# build target
AC_ARG_WITH([udf-bin],
	[AS_HELP_STRING([--with-udb-bin],[include udf-bin (yes|no) [default=yes]])],
	[], [with_udf_bin=yes])
AM_CONDITIONAL([WITH_UDF_BIN], [test "x$with_udf_bin" != "xno"])

# build test
AC_ARG_WITH([udf-featuretest],
	[AS_HELP_STRING([--with-udf-featuretest],[include udf-featuretest (yes|no) [default=no]])],
	[], [with_udf_featuretest=no])
AM_CONDITIONAL([WITH_UDF_FEATURETEST], [test "x$with_udf_featuretest" != "xno"])
AS_IF([test "x$with_udf_featuretest" != "xno"],[
	AC_CONFIG_FILES([test/Makefile])
])

#AC_ARG_ENABLE([gcov],
#	[AC_HELP_STRING([--enable-gcov],[turn on code coverage analysis tools [default=no]])])
#AM_CONDITIONAL([ENABLE_GCOV],[test "x$enable_gcov" = "xyes"])
#
## Check progs
#AC_CHECK_PROGS([LCOV], [lcov], [false])
#AC_CHECK_PROGS([GENHTML], [genhtml], [false])
#AC_CHECK_PROGS([XMLLINT], [xmllint], [false])

## gcov
#dnl Check for --enable-gcov and add appropriate flags for gcc
#if test "x$enable_gcov" = "xyes"; then
#	if test "x$LCOV" = "xfalse"; then
#		AC_MSG_ERROR([lcov binary was not found])
#	fi
#	if test "x$GENHTML" = "xfalse";then
#		AC_MSG_ERROR([genhtml binary was not found])
#	fi
#	export COVFLAGS="--coverage"
#fi
#
## xmllint
#if test "x$XMLLINT" = "xfalse"; then
#	AC_MSG_ERROR([xmllint binary was not found])
#fi

# Configuration Files
#AC_CONFIG_SUBDIRS([src])
AS_IF([test "x$with_udf_3rd_party" != "xno"],[
	export udf_3rdparty_srcdir="$abs_srcdir/3rd_party"
	export udf_3rdparty_builddir="$abs_builddir/3rd_party"
	ac_configure_args="$ac_configure_args udf_3rdparty_srcdir='$udf_3rdparty_srcdir' udf_3rdparty_builddir='$udf_3rdparty_builddir'"

	AC_CONFIG_SUBDIRS([3rd_party])
])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	tools/Makefile
	])

#AC_CONFIG_FILES([
#	doc/Doxyfile
#	doc/Makefile
#	])

AC_OUTPUT

