cmake_minimum_required(VERSION 2.6)
set(CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS TRUE)
cmake_policy(SET CMP0003 NEW)

project(UDF)

set(wxWidgetsPath "${UDF_SOURCE_DIR}/3rd_party/wxWidgets-2.9.3")

if(WIN32)
	set(wxWidgetsBuild "${wxWidgetsPath}")
elseif(LINUX)
	set(wxWidgetsBuild "${wxWidgetsPath}/buildgtk")
endif(WIN32)

if( NOT EXISTS ${wxWidgetsPath})
	MESSAGE(FATAL_ERROR "WxWidgets path not found.")
endif()

if ( WIN32 )
	add_definitions(-DBUILD4WIN)
else ()
	add_definitions(-DBUILD4LIN)
endif ()

# Include necessary submodules
set(CMAKE_MODULE_PATH "${UDF_SOURCE_DIR}/build_utils")
include(UDFConfigTargets)
include(PreprocessorUtils)
set(UDF_WORK_DIR ${UDF_BINARY_DIR})

#####################################################################
# Set up the basic build environment
#####################################################################

if (CMAKE_BUILD_TYPE STREQUAL "")
  # CMake defaults to leaving CMAKE_BUILD_TYPE empty. This screws up
  # differentiation between debug and release builds.
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif ()

# determine UDF version numbers
include(UDFGetVersion)
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

if (CMAKE_COMPILER_IS_GNUCXX)
  # Test for GCC visibility
  include(CheckCXXCompilerFlag)
  check_cxx_compiler_flag(-fvisibility=hidden UDF_GCC_VISIBILITY)
  if (UDF_GCC_VISIBILITY)
    # determine gcc version
    execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion
      OUTPUT_VARIABLE UDF_GCC_VERSION)
    message(STATUS "Detected g++ ${UDF_GCC_VERSION}")
    message(STATUS "Enabling GCC visibility flags")
    set(UDF_GCC_VISIBILITY_FLAGS "-DUDF_GCC_VISIBILITY -fvisibility=hidden")

    # check if we can safely add -fvisibility-inlines-hidden
    string(TOLOWER "${CMAKE_BUILD_TYPE}" UDF_BUILD_TYPE)
    if (UDF_BUILD_TYPE STREQUAL "debug" AND UDF_GCC_VERSION VERSION_LESS "4.2")
      message(STATUS "Skipping -fvisibility-inlines-hidden due to possible bug in g++ < 4.2")
    else ()
      set(UDF_GCC_VISIBILITY_FLAGS "${UDF_GCC_VISIBILITY_FLAGS} -fvisibility-inlines-hidden")
    endif ()
  endif (UDF_GCC_VISIBILITY)
endif (CMAKE_COMPILER_IS_GNUCXX)

# determine system endianess
include(TestBigEndian)
test_big_endian(UDF_TEST_BIG_ENDIAN)

# Add common include path
include_directories("${UDF_SOURCE_DIR}/common/src")
include_directories("${wxWidgetsPath}/include")

# Find dependencies
include(MacroLogFeature)
include(Dependencies)

# definitions for samples
#set(UDF_LIBRARIES UDFCORE )

# Specify build paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${UDF_BINARY_DIR}/bin")
if (WIN32)
  if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    # We don't want to install in default system location, install is really for the SDK, so call it that
    set(CMAKE_INSTALL_PREFIX
	  "${UDF_BINARY_DIR}/sdk" CACHE PATH "UDF install prefix" FORCE
    )
  endif (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
endif(WIN32)

include(ConfigureBuild)

##################################################################
# Setup targets
##################################################################

# Setup gucef modules
#add_subdirectory( 3rd_party )
add_subdirectory( dbmgr )
add_subdirectory( gui )
