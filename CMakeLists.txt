cmake_minimum_required(VERSION 2.6)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
cmake_policy(SET CMP0003 NEW)

project(UDF)

set ( wxWidgetsPath "${UDF_SOURCE_DIR}/3rd_party/wxWidgets-2.9.3")
set ( wxWidgetsBuild ${wxWidgetsPath} )

IF ( UNIX )
	set ( wxWidgetsBuild "${wxWidgetsPath}/buildgtk" )
ENDIF ( UNIX )

IF( NOT EXISTS ${wxWidgetsPath})
	MESSAGE(FATAL_ERROR "WxWidgets path not found.")
ENDIF()

IF ( WIN32 )
	add_definitions(-DBUILD4WIN)
ELSE ()
	add_definitions(-DBUILD4LIN)
ENDIF ()

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

# determine UDF version numbers
include(version)
#ADD_CUSTOM_COMMAND(
#    OUTPUT ${UDF_SOURCE_DIR}/common/src/version.h
#    COMMAND ${CMAKE_COMMAND} -P version.cmake
#    DEPENDS generate version.cmake
#    )
    
UDF_get_version(${UDF_SOURCE_DIR}/common/src/version.h)
message(STATUS "Configuring UDF ${UDF_VERSION}")

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
#add_subdirectory( 3rd_party )
add_subdirectory( dbmgr )
add_subdirectory( gui )
