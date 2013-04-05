#!/bin/bash

config_subdirs=`find . -name "configure.??" -printf "%h "`

for subdir in $config_subdirs
do
	if [ -d "$subdir" ]; then
		mkdir -p $subdir/m4
		mkdir -p $subdir/config
	fi
done

BRANCH=`git rev-parse --abbrev-ref HEAD`
TAG=`git describe --abbrev=0 --always`
MAJOR=`echo $TAG | awk -F. '{print $1}'`
MINOR=`echo $TAG | awk -F. '{print $2}'`
EXT=`echo $TAG | awk -F. '{print $3}'`
BUILDNUMBER=0
if [ "x$MAJOR" = "x" ]; then
	MAJOR=0
fi

if [ "x$MINOR" = "x" ]; then
	MINOR=0
fi

if [ "x$EXT" = "x" ]; then
	EXT=0
fi

bld=`cat version.num`
if [ $? -eq 0 ]; then
	BUILDNUMBER=$bld
fi

export BRANCH
export REVISION=$MAJOR.$MINOR.$EXT
export BUILDNUMBER
export VERSION="$MAJOR.$MINOR.$EXT b$BUILDNUMBER"
echo
echo "PWD     = $PWD"
echo "BRANCH  = $BRANCH"
echo "VERSION = $VERSION"
echo

# update generated configuration files
autoreconf --force --install -I config -I m4 -I `pwd`/m4-extra

