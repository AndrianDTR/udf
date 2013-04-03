# SYNOPSIS
#
#   AC_PKG_WXWIDGETS
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_WXWIDGETS],[
	wxFile=`ls wxWidgets*`
	if [ ! -d $wxFile ]; then
		wxVer=2.9.4
		export WXVER=$wxVer
		svn http://svn.wxwidgets.org/svn/wx/wxWidgets/branches/WX_2_9_0_BRANCH/ wxWidgets-$wxVer
	fi
	
	AC_ARG_WITH([libcli],
		[AS_HELP_STRING([--with-libcli], [specify libcli library (ARG = no|yes|local|<prefix-path>) @<:@default=yes@:>@])],
		[],
		[with_libcli=yes])

	AS_CASE(["$with_libcli"],
		[yes], [
			PKG_CHECK_MODULES([libcli], [libcli], [
				AM_CONDITIONAL([BUILD_LIBCLI],false)
			], [
				AM_CONDITIONAL([BUILD_LIBCLI],true)
			])
		],
		[no], [
			AM_CONDITIONAL([BUILD_LIBCLI],false)
		],
		[local], [
			AM_CONDITIONAL([BUILD_LIBCLI],true)
		],
		[
			AM_CONDITIONAL([BUILD_LIBCLI],false)
		])
])

