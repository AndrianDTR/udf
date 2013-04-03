# SYNOPSIS
#
#   AC_PKG_SQLITE
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_SQLITE],[
	AC_ARG_WITH([sqlite],
		[AS_HELP_STRING([--with-sqlite], [specify sqlite3 library (ARG = no|yes|local|<prefix-path>) @<:@default=yes@:>@])],
		[],
		[with_sqlite=yes])

	AS_CASE(["$with_sqlite"],
		[yes], [
			PKG_CHECK_MODULES([sqlite], [sqlite3], [
				AM_CONDITIONAL([BUILD_SQLITE],false)
			], [
				AM_CONDITIONAL([BUILD_SQLITE],true)
			])
		],
		[no], [
			AM_CONDITIONAL([BUILD_SQLITE],false)
		],
		[local], [
			AM_CONDITIONAL([BUILD_SQLITE],true)
		],
		[
			AM_CONDITIONAL([BUILD_SQLITE],false)
		])
])

