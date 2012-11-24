cmake_minimum_required(VERSION 2.6)

include(ExternalProject)

#IF (UNIX)
	if(${WITH_MYSQL_CONNECTOR} STREQUAL ON)
		ExternalProject_Add(boost
			URL ${BOOST_PATH}.${TARGZ_EXT}
			CONFIGURE_COMMAND echo ""
			BUILD_COMMAND echo ""
			INSTALL_COMMAND echo ""
			BUILD_IN_SOURCE 1
		)
		SET(BOOST_INCLUDE_DIR ${UDF_BINARY_DIR}/3rd_party/boost-prefix/src/boost PARENT_SCOPE)
		SET(BOOST_INCLUDE_DIR_LOCAL ${UDF_BINARY_DIR}/3rd_party/boost-prefix/src/boost)
		IF (UNIX)
			ExternalProject_Add(mysql_connector
				DEPENDS	boost
				URL ${MYSQL_CONN_PATH}.${TARGZ_EXT}
				CONFIGURE_COMMAND cmake -DBOOST_ROOT=${BOOST_INCLUDE_DIR_LOCAL} ${UDF_BINARY_DIR}/3rd_party/mysql_connector-prefix/src/mysql_connector
				INSTALL_COMMAND echo ""
				BUILD_IN_SOURCE 1
			)
		else(UNIX)
			ExternalProject_Add(mysql_connector
				DEPENDS	boost
				URL ${MYSQL_CONN_PATH}.${TARGZ_EXT}
				CONFIGURE_COMMAND cmake -G "MinGW Makefiles" -DBOOST_ROOT=${BOOST_INCLUDE_DIR_LOCAL} ${UDF_BINARY_DIR}/3rd_party/mysql_connector-prefix/src/mysql_connector
				INSTALL_COMMAND echo ""
				BUILD_IN_SOURCE 1
			)
		endif()
		SET(MYSQL_INCLUDE_DIR ${UDF_BINARY_DIR}/3rd_party/mysql_connector-prefix/src/mysql_connector PARENT_SCOPE)
	endif()
	
	if(${WITH_WX_WIDGETS} STREQUAL ON)
		ExternalProject_Add(wx_widgets
			DOWNLOAD_COMMAND tar -xvf ${WX_PATH}.${TARBZ2_EXT}
			CONFIGURE_COMMAND ${UDF_BINARY_DIR}/3rd_party/wx_widgets-prefix/src/wxWidgets-2.9.4/configure --with-gtk --enable-utf8 --disable-shared --with-libpng=builtin --with-zlib=builtin --with-expat=builtin --enable-gif --enable-monolithic
			INSTALL_COMMAND echo ""
		)
	endif()
	SET(WX_INCLUDE_DIR ${UDF_BINARY_DIR}/3rd_party/wx_widgets-prefix/src/wxWidgets-2.9.4/include PARENT_SCOPE)
	SET(WX_LIB_DIR ${UDF_BINARY_DIR}/3rd_party/wx_widgets-prefix/src/wx_widgets-build/lib PARENT_SCOPE)
	
 	
	
#MESSAGE(FATAL_ERROR "Extract fail.")
#ELSE( WIN32 )
#	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
#ELSE( WIN64 )
#	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
#ENDIF()


