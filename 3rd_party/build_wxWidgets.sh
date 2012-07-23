#!/bin/bash

echo '*********************************************************************'
echo '* Build wxWidgets libraries, please wait'
echo '*********************************************************************'

wxNAME=wxWidgets
wxVER_MAJ=2
wxVER_MIN=9
wxVER_BUILD=3
wxARCH_EXT=tar.bz2
wxBuildDir=buildgtk
wxBuildShared=x$1
wxBuildUnicode=x$2
wxBuildMono=x$3

wxDir=`pwd`/$wxNAME-$wxVER_MAJ.$wxVER_MIN.$wxVER_BUILD
wxBuildPath=$wxDir/$wxBuildDir

if [ ! -d $wxDir ]; then 
	if [ ! -f $wxDir.$wxARCH_EXT ]; then 
		echo '* WxWidgets archive not found!'
		exit 1
	fi
	
	echo '* UNTAR wxWidgets .....'
	tar -xvf $wxDir.$wxARCH_EXT
fi

if [ ! -d $wxBuildPath ]; then
	mkdir $wxBuildPath
fi

if [ ! -d $wxBuildPath ]; then
	echo "* WxWidgets build folder ($wxBuildPath) couldn't be found!"
	exit 1
else
	echo '*********************************************************************'
	echo '* Configure build of wxWidgets.'
	echo '*********************************************************************'

	cd $wxBuildPath
	config=''
	
	if [ ! "$wxBuildShared" = "x1" ]; then
		config="$config --disable-shared"
	fi
	if [ "$wxBuildUnicode" = "x1" ]; then
		config="$config --enable-utf8"
	fi
	if [ "$wxBuildMono" = "x1" ]; then
		config="$config --enable-monolithic"
	fi

	../configure --with-gtk $config

	echo '*********************************************************************'
	echo '* Make of wxWidgets.'
	echo '*********************************************************************'

	make -j8
fi

echo '*********************************************************************'
echo '* Build wxWidgets are finished'
echo '*********************************************************************'

exit 0
