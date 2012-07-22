#-------------------------------------------------------------------
# This file is part of the CMake build system for OGRE
#     (Object-oriented Graphics Rendering Engine)
# For the latest info, see http://www.ogre3d.org/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

#######################################################################
# Core dependencies
#######################################################################

# Find zlib
#find_package(ZLIB)
#macro_log_feature(ZLIB_FOUND "zlib" "Simple data compression library" "http://www.zlib.net" FALSE "" "")

#if (ZLIB_FOUND)
#  # Find zziplib
#  find_package(ZZip)
#  macro_log_feature(ZZip_FOUND "zziplib" "Extract data from zip archives" "http://zziplib.sourceforge.net" FALSE "" "")
#endif ()

# Find FreeImage
#find_package(FreeImage)
#macro_log_feature(FreeImage_FOUND "freeimage" "Support for commonly used graphics image formats" "http://freeimage.sourceforge.net" FALSE "" "")

# Find FreeType
#find_package(Freetype)
#macro_log_feature(FREETYPE_FOUND "freetype" "Portable font engine" "http://www.freetype.org" TRUE "" "")

# Find X11
#if (UNIX)
#	find_package(X11)
#	macro_log_feature(X11_FOUND "X11" "X Window system" "http://www.x.org" TRUE "" "")
#	macro_log_feature(X11_Xt_FOUND "Xt" "X Toolkit" "http://www.x.org" TRUE "" "")
#	find_library(XAW_LIBRARY NAMES Xaw Xaw7 PATHS ${DEP_LIB_SEARCH_DIR} ${X11_LIB_SEARCH_PATH})
#	macro_log_feature(XAW_LIBRARY "Xaw" "X11 Athena widget set" "http://www.x.org" TRUE "" "")
#  mark_as_advanced(XAW_LIBRARY)
#endif ()

#######################################################################
# Tools
#######################################################################

find_package(Doxygen)
macro_log_feature(DOXYGEN_FOUND "Doxygen" "Tool for building API documentation" "http://doxygen.org" FALSE "" "")

#######################################################################
# Tests
#######################################################################

#find_package(CppUnit)
#macro_log_feature(CppUnit_FOUND "CppUnit" "Library for performing unit tests" "http://cppunit.sourceforge.net" FALSE "" "")

