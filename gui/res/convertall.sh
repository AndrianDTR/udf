#!/bin/bash

for pic in `ls *.png | awk -F. '{print $1}'`
do
	lpic=`echo $pic | awk '{print tolower($0)}'`
	upic=`echo $pic | awk '{print toupper($0)}'`

	echo "$pic.png -> $lpic.xpm"
	convert $pic.png $lpic.xpm
	sed -i 's/'$lpic'/'$lpic'_xpm/g' $lpic.xpm
done

