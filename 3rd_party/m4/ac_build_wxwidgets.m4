# SYNOPSIS
#
#   AC_PKG_WXWIDGETS
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_WXWIDGETS],[
	wxFile=wxWidgets*.bz2
	useWx=no
	AS_IF([ test -f $wxFile ], [
		wxDir=`ls $wxFile | sed s/.bz2/ /g | awk '{print $1}'`
		wxVer=`echo $wxDir | sed s/-/ /g | awk '{print $2}'`
		echo $wxFile
		echo $wxDir
		echo $wxVer

		AS_IF([ test -d $wxDir ], [
			tar -xf $wxFile
			useWx=yes
		])
	
	], [ AC_MSG_ERROR([cannot find a wxWidgets package]) ])
	
	AM_CONDITIONAL([WITH_WXWIDGETS], [ test "$useWx" = "yes" ])
])

