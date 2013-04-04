# SYNOPSIS
#
#   AC_PKG_WXWIDGETS
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_PKG_WXWIDGETS],[
	UDF_LOCAL_CPPFLAGS="\
		-I$udf_3rdparty_srcdir"

	UDF_LOCAL_LDFLAGS="\
		-L$udf_3rdparty_builddir/$wxDir/lib"

	# TODO: Modify next block
	PKG_CHECK_MODULES([wxWidgets], [wxWidgets], [
		UDF_WITH_CPPFLAGS="$UDF_WITH_CPPFLAGS $libwx_CFLAGS"
		UDF_WITH_LDFLAGS="$UDF_WITH_LDFLAGS $libwx_LIBS"
	], [
		UDF_WITH_CPPFLAGS="$UDF_LOCAL_CPPFLAGS $UDF_WITH_CPPFLAGS"
		UDF_WITH_LDFLAGS="$UDF_LOCAL_LDFLAGS $UDF_WITH_LDFLAGS"
	])
])

