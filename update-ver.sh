#! /bin/bash

VERFILE=$1

TAG=`git describe --abbrev=0 --always`
MAJOR=`echo $TAG | awk -F. '{print $1}'`
MINOR=`echo $TAG | awk -F. '{print $2}'`
EXT=`echo $TAG | awk -F. '{print $3}'`

if [ "x$MAJOR" = "x" ]; then
	MAJOR=0
fi

if [ "x$MINOR" = "x" ]; then
	MINOR=0
fi

if [ "x$EXT" = "x" ]; then
	EXT=0
fi

if [ ! -f $VERFILE ]; then
	touch $VERFILE
	
	EXT=$[EXT + 1]
	echo "Inctement GIT tag to $MAJOR.$MINOR.$EXT"
	git tag -a $MAJOR.$MINOR.$EXT -m "Auto TAG $MAJOR.$MINOR.$EXT"
	echo 0 > $VERFILE
fi

log=`git tag | grep $MAJOR.$MINOR.$EXT`
if [ $? -eq 1 ]; then
	echo "Create GIT tag $MAJOR.$MINOR.$EXT"
	git tag -a $MAJOR.$MINOR.$EXT -m "Auto TAG $MAJOR.$MINOR.$EXT" &>/dev/null
	echo 0 > $VERFILE
fi

BUILDNUMBER=`cat $VERFILE`
export BUILDNUMBER=$[BUILDNUMBER + 1]
echo $BUILDNUMBER > $VERFILE

