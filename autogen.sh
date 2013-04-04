#!/bin/bash

config_subdirs=`find . -name "configure.??" -printf "%h "`

for subdir in $config_subdirs
do
	if [ -d "$subdir" ]; then
		mkdir -p $subdir/m4
		mkdir -p $subdir/config
	fi
done

branch="unknown"
VERFILE="version.num"

if [ ! -f $VERFILE ]; then
	touch $VERFILE
fi

if [ "$REVISION" == "" ] && [ "$BUILDNUMBER" == "" ]; then
	tag=`git describe --abbrev=0 --always`
	BRANCH=`git rev-parse --abbrev-ref HEAD`

	if [ "$tag" != "" ]; then
		REVISION=$tag
		BUILDNUMBER=`cat $VERFILE`
		BUILDNUMBER=$[$BUILDNUMBER + 1]
	fi

	if [ "$REVISION" == "" ]; then
		REVISION="unknown"
	fi

	if [ "$BUILDNUMBER" == "" ]; then
		BUILDNUMBER="1"
	fi

	echo $BUILDNUMBER > $VERFILE
	
	export BRANCH
	export REVISION
	export BUILDNUMBER
fi

echo "PWD     = $PWD"
echo "BRANCH  = $BRANCH"
echo "VERSION = $REVISION.$BUILDNUMBER"

# update generated configuration files
autoreconf --force --install -I config -I m4 -I `pwd`/m4-extra

