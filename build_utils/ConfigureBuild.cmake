#-------------------------------------------------------------------
# This file is part of the CMake build system for UDF
#     (Object-oriented Graphics Rendering Engine)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

#######################################################################
# This file takes care of configuring UDF to build with the settings
# given in CMake. It creates the necessary config.h file and will 
# also prepare package files for pkg-config and CMake.
#######################################################################

set(UDF_TEMPLATES_DIR ${UDF_SOURCE_DIR}/build_utils/templates)

# should we build static libs?
if (UDF_STATIC)
  set(UDF_LIB_TYPE STATIC)
else ()
  set(UDF_LIB_TYPE SHARED)
endif ()

# configure threading options
set(UDF_THREAD_PROVIDER 0)
if (UDF_CONFIG_THREADS)
	if (UNIX)
		add_definitions(-pthread)
	endif ()

	if (UDF_CONFIG_THREAD_PROVIDER STREQUAL "boost")
		set(UDF_THREAD_PROVIDER 1)
		include_directories(${Boost_INCLUDE_DIRS})
		# On MSVC Boost usually tries to autolink boost libraries. However since
		# this behaviour is not available on all compilers, we need to find the libraries
		# ourselves, anyway. Disable auto-linking to avoid mess-ups.
		add_definitions(-DBOOST_ALL_NO_LIB)
		set(UDF_THREAD_LIBRARIES ${Boost_LIBRARIES})
	endif ()

endif()


# determine config values depending on build options 
set(UDF_SET_DOUBLE 0)
set(UDF_SET_ALLOCATOR ${UDF_CONFIG_ALLOCATOR})
set(UDF_SET_CONTAINERS_USE_ALLOCATOR 0)
set(UDF_SET_STRING_USE_ALLOCATOR 0)
set(UDF_SET_MEMTRACK_DEBUG 0)
set(UDF_SET_MEMTRACK_RELEASE 0)
set(UDF_SET_THREADS ${UDF_CONFIG_THREADS})
set(UDF_SET_THREAD_PROVIDER ${UDF_THREAD_PROVIDER})
set(UDF_SET_DISABLE_FREEIMAGE 0)
set(UDF_SET_DISABLE_DDS 0)
set(UDF_SET_DISABLE_ZIP 0)
set(UDF_SET_NEW_COMPILERS 0)
set(UDF_STATIC_LIB 0)
set(UDF_SET_USE_BOOST 0)
if (UDF_CONFIG_DOUBLE)
  set(UDF_SET_DOUBLE 1)
endif()
if (UDF_CONFIG_CONTAINERS_USE_CUSTOM_ALLOCATOR)
  set(UDF_SET_CONTAINERS_USE_ALLOCATOR 1)
endif ()
if (UDF_CONFIG_STRING_USE_CUSTOM_ALLOCATOR)
  set(UDF_SET_STRING_USE_ALLOCATOR 1)
endif ()
if (UDF_CONFIG_MEMTRACK_DEBUG)
  set(UDF_SET_MEMTRACK_DEBUG 1)
endif()
if (UDF_CONFIG_MEMTRACK_RELEASE)
  set(UDF_SET_MEMTRACK_RELEASE 1)
endif()
if (UDF_CONFIG_DISABLE_FREEIMAGE)
  set(UDF_SET_DISABLE_FREEIMAGE 1)
endif()
if (UDF_CONFIG_DISABLE_DDS)
  set(UDF_SET_DISABLE_DDS 1)
endif()
if (UDF_CONFIG_DISABLE_ZIP)
  set(UDF_SET_DISABLE_ZIP 1)
endif()
if(UDF_CONFIG_NEW_COMPILERS)
  set(UDF_SET_NEW_COMPILERS 1)
endif()
if (UDF_STATIC)
  set(UDF_STATIC_LIB 1)
endif()
if (UDF_USE_BOOST)
  set(UDF_SET_USE_BOOST 1)
endif()
add_definitions(-DHAVE_BUILDSETTINGS_H)

if (UDF_TEST_BIG_ENDIAN)
  set(UDF_CONFIG_BIG_ENDIAN 1)
else ()
  set(UDF_CONFIG_LITTLE_ENDIAN 1)
endif ()

# generate buildsettings.h 
configure_file(${UDF_TEMPLATES_DIR}/buildsettings.h.in ${UDF_BINARY_DIR}/src/buildsettings.h @ONLY)
install(FILES ${UDF_BINARY_DIR}/src/buildsettings.h DESTINATION src/UDF)

# Read contents of the UDF_Config.h file
file(READ "${UDF_SOURCE_DIR}/common/src/config.h" UDF_CONFIG_H)
# add HAVE_BUILDSETTINGS_H preprocessor define
file(WRITE ${UDF_BINARY_DIR}/src/config.h "#define HAVE_UDF_BUILDSETTINGS_H\n${UDF_CONFIG_H}")
install(FILES ${UDF_BINARY_DIR}/src/config.h DESTINATION src/UDF)


# # Create the pkg-config package files on Unix systems
# if (UNIX)
  # set(UDF_LIB_SUFFIX "")
  # set(UDF_PLUGIN_PREFIX "")
  # set(UDF_PLUGIN_EXT ".so")
  # if (UDF_STATIC)
    # set(UDF_LIB_SUFFIX "${UDF_LIB_SUFFIX}Static")
    # set(UDF_PLUGIN_PREFIX "lib")
    # set(UDF_PLUGIN_EXT ".a")
  # endif ()
  # string(TOLOWER "${CMAKE_BUILD_TYPE}" UDF_BUILD_TYPE)
  # if (UDF_BUILD_TYPE STREQUAL "debug")
    # set(UDF_LIB_SUFFIX "${UDF_LIB_SUFFIX}_d")
  # endif ()

  # set(UDF_ADDITIONAL_LIBS "")
  # set(UDF_CFLAGS "")
  # set(UDF_PREFIX_PATH ${CMAKE_INSTALL_PREFIX})
  # if (UDF_CONFIG_THREADS GREATER 0)
    # set(UDF_CFLAGS "-pthread")
    # set(UDF_ADDITIONAL_LIBS "${UDF_ADDITIONAL_LIBS} -lpthread")
  # endif ()
  # if (UDF_STATIC)
    # if (UDF_CONFIG_THREADS)
      # set(UDF_ADDITIONAL_LIBS "${UDF_ADDITIONAL_LIBS} -lboost-thread-mt")
    # endif ()
    # # there is no pkgconfig file for freeimage, so we need to add that lib manually
    # set(UDF_ADDITIONAL_LIBS "${UDF_ADDITIONAL_LIBS} -lfreeimage")
    # configure_file(${UDF_TEMPLATES_DIR}/UDFStatic.pc.in ${UDF_BINARY_DIR}/pkgconfig/UDF${UDF_LIB_SUFFIX}.pc @ONLY)
  # else ()
    # configure_file(${UDF_TEMPLATES_DIR}/UDF.pc.in ${UDF_BINARY_DIR}/pkgconfig/UDF${UDF_LIB_SUFFIX}.pc @ONLY)
  # endif ()
  # install(FILES ${UDF_BINARY_DIR}/pkgconfig/UDF${UDF_LIB_SUFFIX}.pc DESTINATION lib/pkgconfig)

  # # configure additional packages
  
# endif ()

if (UDF_STANDALONE_BUILD)
  set(CMAKE_USE_RELATIVE_PATHS true)
  set(CMAKE_SUPPRESS_REGENERATION true)
endif()

if (MSVC)
  # Enable intrinsics on MSVC in debug mode
  # Not actually necessary in release mode since /O2 implies /Oi but can't easily add this per build type?
  add_definitions(/Oi)
endif (MSVC)
