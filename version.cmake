#-------------------------------------------------------------------
# This file is part of the CMake build system for GUCEF
#     (Galaxy Unlimited Framework)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

macro(UDF_get_version HEADER)
	#execute_process(git ARGS 'rev-list --reverse HEAD | nl -n rz -w 3|awk \'{print "build "$1", commit="$2}\'' OUTPUT_VARIABLE )
	#file(READ ${HEADER} TEMP_VAR_CONTENTS)
	#get_preprocessor_entry(TEMP_VAR_CONTENTS UDF_VERSION_MAJOR UDF_VERSION_MAJOR)
	#get_preprocessor_entry(TEMP_VAR_CONTENTS UDF_VERSION_MINOR UDF_VERSION_MINOR)
	#get_preprocessor_entry(TEMP_VAR_CONTENTS UDF_VERSION_PATCH UDF_VERSION_PATCH)
	#get_preprocessor_entry(TEMP_VAR_CONTENTS UDF_VERSION_NAME UDF_VERSION_NAME)
	#get_preprocessor_entry(TEMP_VAR_CONTENTS UDF_VERSION_SUFFIX UDF_VERSION_SUFFIX)
	#set(UDF_VERSION "${UDF_VERSION_MAJOR}.${UDF_VERSION_MINOR}.${UDF_VERSION_PATCH}")
endmacro()

