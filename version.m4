m4_define([VERSION_NUMBER],m4_esyscmd([if test -z $BUILDNUMBER ; then echo -n dev; else echo -n $REVISION.$BUILDNUMBER; fi]))
