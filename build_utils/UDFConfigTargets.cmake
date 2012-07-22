#-------------------------------------------------------------------
# This file is part of the CMake build system for UDF
#     (Galaxy Unlimited Framework)
# For the latest info, see http://www.VanvelzenSoftware.com/
#
# The contents of this file are placed in the public domain. Feel
# free to make use of it in any way you like.
#-------------------------------------------------------------------

# Configure settings and install targets

if (WIN32)
  set(UDF_RELEASE_PATH "/Release")
  set(UDF_DEBUG_PATH "/Debug")
  set(UDF_RELEASEWIN_PATH "/ReleaseWin")
elseif (UNIX)
  set(UDF_RELEASE_PATH "")
  set(UDF_DEBUG_PATH "")
  set(UDF_RELEASEWIN_PATH "")
  set(LINUX "1")
endif ()

# create vcproj.user file for Visual Studio to set debug working directory
function(UDF_create_vcproj_userfile TARGETNAME)
  if (MSVC)
    configure_file(
	  ${UDF_TEMPLATES_DIR}/VisualStudioUserFile.vcproj.user.in
	  ${CMAKE_CURRENT_BINARY_DIR}/${TARGETNAME}.vcproj.user
	  @ONLY
	)
  endif ()
endfunction(UDF_create_vcproj_userfile)

# install targets according to current build type
function(UDF_install_target TARGETNAME SUFFIX)
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${UDF_RELEASE_PATH}" CONFIGURATIONS Release None ""
    LIBRARY DESTINATION "lib${UDF_LIB_RELEASE_PATH}${SUFFIX}" CONFIGURATIONS Release None ""
    ARCHIVE DESTINATION "lib${UDF_LIB_RELEASE_PATH}${SUFFIX}" CONFIGURATIONS Release None ""
    FRAMEWORK DESTINATION "bin${UDF_RELEASE_PATH}" CONFIGURATIONS Release None ""
  )
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${UDF_DEBUG_PATH}" CONFIGURATIONS Debug
    LIBRARY DESTINATION "lib${UDF_LIB_DEBUG_PATH}${SUFFIX}" CONFIGURATIONS Debug
    ARCHIVE DESTINATION "lib${UDF_LIB_DEBUG_PATH}${SUFFIX}" CONFIGURATIONS Debug
    FRAMEWORK DESTINATION "bin${UDF_DEBUG_PATH}" CONFIGURATIONS Debug
  )
  install(TARGETS ${TARGETNAME}
    RUNTIME DESTINATION "bin${UDF_RELEASEWIN_PATH}" CONFIGURATIONS ReleaseWin
    LIBRARY DESTINATION "lib${UDF_LIB_RELEASEWIN_PATH}${SUFFIX}" CONFIGURATIONS ReleaseWin
    ARCHIVE DESTINATION "lib${UDF_LIB_RELEASEWIN_PATH}${SUFFIX}" CONFIGURATIONS ReleaseWin
    FRAMEWORK DESTINATION "bin${UDF_RELEASEWIN_PATH}" CONFIGURATIONS ReleaseWin
  )
endfunction(UDF_install_target)

# setup common target settings
function(UDF_config_common TARGETNAME)
  set_target_properties(${TARGETNAME} PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${UDF_BINARY_DIR}/lib
    LIBRARY_OUTPUT_DIRECTORY ${UDF_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${UDF_BINARY_DIR}/bin
  )
  
  UDF_create_vcproj_userfile(${TARGETNAME})

  if (MSVC)
    add_definitions( "/D_CRT_SECURE_NO_WARNINGS /wd4251 /nologo" )
  endif()

endfunction(UDF_config_common)

# setup library build
function(UDF_config_lib LIBNAME)
  UDF_config_common(${LIBNAME})
  if (UDF_STATIC)
    # add static prefix, if compiling static version
    set_target_properties(${LIBNAME} PROPERTIES OUTPUT_NAME ${LIBNAME}Static)
  else (UDF_STATIC)
    if (CMAKE_COMPILER_IS_GNUCXX)
      # add GCC visibility flags to shared library build
      set_target_properties(${LIBNAME} PROPERTIES COMPILE_FLAGS "${UDF_GCC_VISIBILITY_FLAGS}")
	endif (CMAKE_COMPILER_IS_GNUCXX)
  endif (UDF_STATIC)
  UDF_install_target(${LIBNAME} "")

  if (UDF_INSTALL_PDB)
    # install debug pdb files
    if (UDF_STATIC)
	  install(FILES ${UDF_BINARY_DIR}/lib${UDF_LIB_DEBUG_PATH}/${LIBNAME}Static_d.pdb
	    DESTINATION lib${UDF_LIB_DEBUG_PATH}
		CONFIGURATIONS Debug
	  )
	  install(FILES ${UDF_BINARY_DIR}/lib${UDF_LIB_RELWDBG_PATH}/${LIBNAME}Static.pdb
	    DESTINATION lib${UDF_LIB_RELWDBG_PATH}
		CONFIGURATIONS RelWithDebInfo
	  )
	else ()
	  install(FILES ${UDF_BINARY_DIR}/bin${UDF_DEBUG_PATH}/${LIBNAME}_d.pdb
	    DESTINATION bin${UDF_DEBUG_PATH}
		CONFIGURATIONS Debug
	  )
	  install(FILES ${UDF_BINARY_DIR}/bin${UDF_RELWDBG_PATH}/${LIBNAME}.pdb
	    DESTINATION bin${UDF_RELWDBG_PATH}
		CONFIGURATIONS RelWithDebInfo
	  )
	endif ()
  endif ()
endfunction(UDF_config_lib)