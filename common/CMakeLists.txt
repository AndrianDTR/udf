cmake_minimum_required(VERSION 2.6)

#####################################################################
# Set up the basic build environment
#####################################################################

# determine UDF version numbers
set (VERSION_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h)

set(REPO_REV 1)
set(REPO_HASH "Release")
# Add build version info
IF(UNIX)
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
ELSE(UNIX)
	MESSAGE(STATUS "Win build common")

	include_directories( ${UDF_SOURCE_DIR}/common/src src)
ENDIF(UNIX)
CONFIGURE_FILE( ${VERSION_FILE}.in ${VERSION_FILE} )

MESSAGE(STATUS "Build rev. ${REPO_REV}, hash = ${REPO_HASH}.")

