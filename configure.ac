#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
AC_PREREQ([2.68])
AC_INIT([udf], [0.01], [andrian.yablonsky@gmail.com])
AC_CANONICAL_SYSTEM

AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CPP

LT_INIT([disable-shared])

abs_builddir=`pwd`
abs_srcdir=`cd $srcdir && pwd`
abs_bin=$abs_srcdir/bin
mkdir -p $abs_bin

export abs_bin=$abs_bin
export abs_builddir=$abs_builddir
export abs_srcdir=$abs_srcdir

AC_ARG_WITH([wxWidgets],
            [AS_HELP_STRING([--with-wxWidgets],[Compile wxWidgets libraries [default=no]])],
            [],[with_wxWidgets=yes])

# Checks for library functions.
AC_CHECK_LIB([pthread], [pthread_create], [], [AC_MSG_ERROR([pthread library was not found])])

# Check packages installed
#AC_PKG_SQLITE

# Check headers
#AC_CHECK_HEADERS([gtk/gtk.h], [], [AC_MSG_ERROR([gtk/gtk.h header was not found. please install libgtk*-dev])])

######################################

AC_CONFIG_HEADERS([config.h])

######################################

AC_C_BIGENDIAN

######################################
target_os_windows=no
target_os_linux=no

case "$target_os" in
windows*)
        target_os_windows=yes
	AC_DEFINE([BUILD4WIN],[1],[BUILD4WIN])
	AC_MSG_CHECKING(compiling for windows)
	;;
linux*)
        target_os_linux=yes
	AC_MSG_CHECKING(compiling for Linux)
	AC_DEFINE([BUILD4LIN],[1],[BUILD4LIN])
	;;
esac

AM_CONDITIONAL([TARGET_OS_WINDOWS],[test "x$target_os_windows" = "xyes"])
AM_CONDITIONAL([TARGET_OS_LINUX],[test "x$target_os_linux" = "xyes"])

######################################
AC_SUBST(UDF_WITH_CPPFLAGS)
AC_SUBST(UDF_WITH_LDADD)
AC_SUBST(UDF_WITH_CXXFLAGS)
UDF_WITH_CXXFLAGS="$UDF_WITH_CXXFLAGS -I$abs_srcdir/common/src"

AM_CONDITIONAL([WITH_WXWIDGETS],[test "x$with_wxWidgets" = "xyes"])
AS_IF([test "x$with_wxWidgets" = "xyes"],[
    AC_DEFINE([CONFIG_WXWIDGETS],[1],[Compile wxWidgets libraries])
    wxTar=`ls $abs_srcdir/3rd_party/wxWidgets*.tar.*`
    wxSrc=`echo $wxTar|awk -F.tar '{print $1}'`
    wxVer=`echo wxWidgets-2.9.3|awk -F- '{print $2}'|awk -F. '{print $1"."$2}'`
    AS_IF([ ! test -d "$wxSrc/buildwx" ],[
    	echo ""
    	echo "Unpack wxWidgets sources..."
        `tar -xvf $wxTar -C $abs_srcdir/3rd_party/`
        AS_IF([ ! test -d "$wxSrc" ],[
            `echo "Error! wxWidgets-XXX dir not created." && exit 1`
        ])
        echo "Building wxWidgets libraries..."
        `mkdir -p $wxSrc/buildwx && cd $wxSrc/buildwx && ../configure --disable-shared --with-gtk && make -j8`
        echo "Finish"
    ])
    
    UDF_WITH_CXXFLAGS="$UDF_WITH_CXXFLAGS -L$wxSrc/buildwx/lib -I$wxSrc/buildwx/lib/wx/include/gtk2-unicode-static-$wxVer -I$wxSrc/include"
    UDF_WITH_CPPFLAGS="$UDF_WITH_CPPFLAGS -D_FILE_OFFSET_BITS=64 -D__WXGTK__"
])

export UDF_WITH_CPPFLAGS="$UDF_WITH_CPPFLAGS"
export UDF_WITH_LDADD="$UDF_WITH_LDADD"
export UDF_WITH_CXXFLAGS="-Wall $UDF_WITH_CXXFLAGS"

echo "AAAAAAAAAAAAAAAAA"$UDF_WITH_CPPFLAGS
echo "BBBBBBBBBBBBBBBBB"$UDF_WITH_CXXFLAGS
echo "CCCCCCCCCCCCCCCCC"$UDF_WITH_LDADD


AC_CONFIG_FILES([
	Makefile
	3rd_party/Makefile
	common/Makefile
	dbmgr/Makefile
	gui/Makefile
	])
	
AC_OUTPUT
