# SYNOPSIS
#
#   AC_PKG_MYSQLCPPCON
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_MYSQLCPPCON],[
	cppConFileMask=$udf_3rdparty_srcdir/mysql-connector-c++-*.tar.gz
	cppConFile=`ls $cppConFileMask` 
	cppConDir=$udf_3rdparty_builddir/mysql-connector-c++

	AS_IF([ test -f $cppConFile ], [
		cppConExtDir=`ls $cppConFile | sed 's/.tar.gz/ /g'`
		cppConVer=`echo $cppConExtDir | sed 's/.*\///g' | sed 's/mysql-connector-c++-//g'`

		AS_IF([ test -d $cppConDir ], [], [			
			tar -xf $cppConFile 
			mv "mysql-connector-c++-$cppConVer" $cppConDir
		])
	
	], [ AC_MSG_ERROR([cannot find a MySQL C++ Connector package]) ])
	
	AM_CONDITIONAL([WITH_MYSQLCPPCON], [ test -d $cppConDir ])
	
	AS_IF([ test -d $cppConDir ], [
		AC_MSG_NOTICE([MySQL C++ Connector library])
		#cd $cppConDir
		#cmake -DBOOST_ROOT=$BOOSTROOT ./
	])

	export CPPCONVER=$cppConVer
	export CPPCONDIR=$cppConDir
	cd $curWD
])


