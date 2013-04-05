# SYNOPSIS
#
#   AC_PKG_WXWIDGETS
#
# DESCRIPTION
#
#   This macro defines external libraries configuration.

AC_DEFUN([AC_BUILD_WXWIDGETS],[
	wxFileMask=$udf_3rdparty_srcdir/wxWidgets*.tar.bz2
	wxFile=`ls $wxFileMask` 
	wxDir=$udf_3rdparty_builddir/wxWidgets
	
	AS_IF([ test -f $wxFile ], [
		wxExtDir=`ls $wxFile | sed 's/.tar.bz2/ /g'`
		wxVer=`echo $wxExtDir | sed 's/.*\///g' | sed 's/wxWidgets-//g'`

		AS_IF([ test -d $wxDir ], [], [			
			tar -xf $wxFile 
			mv "wxWidgets-$wxVer" $wxDir
		])
	
	], [ AC_MSG_ERROR([cannot find wxWidgets package]) ])
	
	AM_CONDITIONAL([WITH_WXWIDGETS], [ test -d $wxDir ])
	
	AS_IF([ test -d $wxDir ], [
		AC_MSG_NOTICE([wxWidgets library])
		#cd $wxDir
		#./configure --disable-shared --enable-monolithic --enable-unicode --with-libpng=builtin --with-libxpm=builtin --with-zlib=builtin
	])
	export WXDIR=$wxDir
	export WXVER=$wxVer
	cd $curWD
])

