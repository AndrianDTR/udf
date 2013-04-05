# SYNOPSIS
#
#   AC_PKG_BOOST
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_BOOST],[
	boostFileMask=$udf_3rdparty_srcdir/boost_*.tar.gz
	boostFile=`ls $boostFileMask` 
	boostDir=$udf_3rdparty_builddir/boost

	AS_IF([ test -f $boostFile ], [
		boostExtDir=`ls $boostFile | sed 's/.tar.gz/ /g'`
		boostVer=`echo $boostExtDir | sed 's/.*\///g' | sed 's/boost_//g'`

		AS_IF([ test -d $boostDir ], [], [			
			tar -xf $boostFile 
			mv "boost_$boostVer" $boostDir
		])
	
	], [ AC_MSG_ERROR([cannot find BOOST library package]) ])
	
	AM_CONDITIONAL([WITH_BOOST], [ test -d $boostDir ])
	
	AS_IF([ test -d $boostDir ], [
		AC_MSG_NOTICE([BOOST library])
		#cd $boostDir 
		#./bootstrap.sh
	])

	export BOOSTVER=`echo $boostVer | sed 's/\_/\./g'`
	export BOOSTROOT=$boostDir
	cd $curWD
])

