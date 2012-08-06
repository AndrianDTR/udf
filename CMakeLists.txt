cmake_minimum_required(VERSION 2.6)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
cmake_policy(SET CMP0003 NEW)
#cmake_policy(SET CMP0016 NEW)

project(UDF)

option(WITH_WX_WIDGETS "Build wxWidgets libs."  no)
option(WITH_BOOST "Build BOOST lib."  no)
option(WITH_MYSQL_CONNECTOR "Build MySQL connector lib."  no)
         
##########################
#conf consts
##########################
set ( EXT_LIB_PATH "${UDF_SOURCE_DIR}/3rd_party")

set(MYSQL_CONN_FILE "mysql-connector-c++-1.1.0")
set(MYSQL_CONN_PATH "${EXT_LIB_PATH}/${MYSQL_CONN_FILE}")
set(MYSQL_CONN_INCLUDE "${MYSQL_CONN_PATH}/driver")

set(BOOST_LIB_FILE "boost_1_50_0")
set(BOOST_PATH "${EXT_LIB_PATH}/${BOOST_LIB_FILE}")
set(BOOST_INCLUDE "${BOOST_PATH}/boost")

set (WX_LIB_FILE "wxWidgets-2.9.3")
set (WX_PATH "${EXT_LIB_PATH}/${WX_LIB_FILE}" )

set(TARGZ_EXT "tar.gz")
set(TARBZ2_EXT "tar.bz2")
##########################

set ( WX_BUILD_PATH "${WX_PATH}" )
IF ( UNIX )
	set ( WX_BUILD_PATH "${WX_PATH}/buildgtk" )
ENDIF ( UNIX )

add_subdirectory( 3rd_party )

IF ( WIN32 )
	add_definitions(-DBUILD4WIN)
ELSE ( WIN32 )
	add_definitions(-DBUILD4LIN)
ENDIF ( WIN32 )

##########################
# Arch check
##########################
SET( OS_32_BITS 0 )
SET( OS_64_BITS 0 )

INCLUDE(CheckTypeSize)
CHECK_TYPE_SIZE(void*  SIZEOF_VOID_PTR)
IF( ${SIZEOF_VOID_PTR} MATCHES "^8$" )
SET( OS_64_BITS 1 )
SET( CMAKE_NATIVE_ARCH 64 )
ELSE( ${SIZEOF_VOID_PTR} MATCHES "^8$" )
SET( OS_32_BITS 1 )
SET( CMAKE_NATIVE_ARCH 32 )
ENDIF( ${SIZEOF_VOID_PTR} MATCHES "^8$" )

# Include necessary submodules
set(CMAKE_MODULE_PATH "${UDF_SOURCE_DIR}")
set(UDF_WORK_DIR ${UDF_BINARY_DIR})

#####################################################################
# Set up the basic build environment
#####################################################################

IF (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set( CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

if (NOT APPLE)
  # Create debug libraries with _d postfix
  set(CMAKE_DEBUG_POSTFIX "_d")
endif ()

# Set compiler specific build flags
if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-msse)
endif ()

# Add common include path
include_directories("${UDF_SOURCE_DIR}/common/src")

# Specify build paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/bin")

##################################################################
# Setup targets
##################################################################
# Setup gucef modules
add_subdirectory( common )
add_subdirectory( dbmgr )
add_subdirectory( gui )
