cmake_minimum_required(VERSION 2.6)

#####################################################################
# Set up the basic build environment
#####################################################################

# determine UDF version numbers
set (VERSION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h)

# Add build version info
exec_program(
    "git"
    ${CMAKE_CURRENT_SOURCE_DIR}
    ARGS "rev-list --reverse HEAD | nl | tail -1 | awk '{print $1}'"
    OUTPUT_VARIABLE REPO_REV )

exec_program(
    "git"
    ${CMAKE_CURRENT_SOURCE_DIR}
    ARGS "rev-list --reverse HEAD | nl | tail -1 | awk '{print $2}'"
    OUTPUT_VARIABLE REPO_HASH )

CONFIGURE_FILE( ${VERSION_FILE}.in ${VERSION_FILE} )

#file (READ ${VERSION_FILE} OLD_CODE)
#foreach (LINE ${OLD_CODE})
#	MESSAGE(STATUS "LINE: ${LINE}")
#	string (REGEX MATCH ".*#define +UDF_VERSION_PATH +([0-9]+).*" BUILD_NUMBER ${LINE})
#	string (REGEX MATCH ".*#define UDF_VERSION_PATH +([0-9]+).*$" BUILD_NUMBER ${LINE})
#	if (${BUILD_NUMBER})
#		string (REGEX REPLACE "[0-9]+$" ${REPO_REV} LINE ${LINE})
#	endif ()
#	MESSAGE(STATUS "Ver: ${LINE}")
#
#	string (REGEX MATCH "^.*#define +UDF_VERSION_DESCR +([0-9a-fA-F]+).*$" BUILD_HASH ${LINE})
#	MESSAGE(STATUS "Ver: ${BUILD_HASH}")
#	if (${BUILD_HASH})
#		string (REGEX REPLACE "[0-9a-fA-F]+$" ${REPO_HASH} LINE ${LINE})
#	endif ()
#	
#	set (NEW_CODE ${NEW_CODE} ${LINE})
#endforeach (LINE)
#file (WRITE ${VERSION_FILE} "${NEW_CODE}")

MESSAGE(STATUS "Build rev. ${REPO_REV}, hash = ${REPO_HASH}.")

