# SYNOPSIS
#
#   AC_PKG_LIBCURL
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_LIBCURL],[
	AC_ARG_WITH([libcurl],
		[AS_HELP_STRING([--with-libcurl], [specify curl library (ARG = no|yes|local|<prefix-path>) @<:@default=yes@:>@])],
		[],
		[with_libcurl=no])

	AS_CASE(["$with_libcurl"],
		[yes], [
			PKG_CHECK_MODULES([libcurl], [libcurl], [
				AM_CONDITIONAL([BUILD_LIBCURL],false)
				build_libcurl="no"
			], [
				AM_CONDITIONAL([BUILD_LIBCURL],true)
				build_libcurl="yes"
			])
		],
		[no], [
			AM_CONDITIONAL([BUILD_LIBCURL],false)
			build_libcurl="no"
		],
		[local], [
			AM_CONDITIONAL([BUILD_LIBCURL],true)
			build_libcurl="yes"
		],
		[
			AM_CONDITIONAL([BUILD_LIBCURL],false)
			build_libcurl="no"
		])

        AS_IF([test "$build_libcurl" = "yes"], [
		ac_configure_args="$ac_configure_args --without-ldap-lib --without-lber-lib --without-krb4 --without-spnego --without-winssl --without-darwinssl --without-gnutls --without-polarssl --without-cyassl --without-nss --without-axtls --without-libmetalink --without-librtmp --without-winidn --without-libidn --without-ssl"
	])

	AC_CONFIG_SUBDIRS([curl])

])
