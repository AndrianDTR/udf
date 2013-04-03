m4_define([VERSION_NUMBER],m4_esyscmd([if test -z $BUILDNUMBER ; then echo -n dev; else echo -n $REVISION.$BUILDNUMBER; fi]))
m4_define([WXVER],m4_esyscmd([if test -z $WXVER ; then echo -n dev; else echo -n $WXVER; fi]))
