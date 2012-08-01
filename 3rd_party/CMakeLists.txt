cmake_minimum_required(VERSION 2.6)

IF (UNIX)
	
	ADD_CUSTOM_TARGET(boost
		DEPENDS ${BOOST_PATH}.${TARGZ_EXT}
		COMMAND ${CMAKE_COMMAND} -E tar	-xvzf ${BOOST_PATH}.${TARGZ_EXT}
		WORKING_DIRECTORY ${EXT_LIB_PATH}
		COMMENT "Unpacking ${BOOST_PATH}.${TARGZ_EXT}"
		VERBATIM
	)

	ADD_CUSTOM_TARGET(mysql_connector
		DEPENDS	boost ${MYSQL_CONN_PATH}.${TARGZ_EXT}
		COMMAND	${CMAKE_COMMAND} -E tar	-xvzf ${MYSQL_CONN_PATH}.${TARGZ_EXT}
		WORKING_DIRECTORY ${EXT_LIB_PATH}
		COMMENT "Unpacking ${MYSQL_CONN_PATH}.${TARGZ_EXT}"
		VERBATIM
	)

	ADD_CUSTOM_TARGET(mysql_connector_lib
		DEPENDS	mysql_connector
		COMMAND	cmake -DBOOST_ROOT=${BOOST_PATH} . && make -j8
		WORKING_DIRECTORY ${MYSQL_CONN_PATH}
		COMMENT "Build connector lib"
		VERBATIM
	)
	
	ADD_CUSTOM_TARGET(wx_unpack
		DEPENDS	${WX_PATH}.${TARBZ2_EXT}
		COMMAND	${CMAKE_COMMAND} -E tar	-xvf ${WX_PATH}.${TARBZ2_EXT} && mkdir -p ${WX_BUILD_PATH}
		WORKING_DIRECTORY ${EXT_LIB_PATH}
		COMMENT "Unpacking ${WX_PATH}.${TARBZ2_EXT}"
		VERBATIM
	)
	
	ADD_CUSTOM_TARGET(wx_build
		DEPENDS	wx_unpack ${WX_PATH}
		COMMAND	../configure --with-gtk --enable-utf8 --disable-shared --with-libpng=builtin --with-zlib=builtin --with-expat=builtin && make -j8
		WORKING_DIRECTORY ${WX_BUILD_PATH}
		COMMENT "Unpacking ${WX_PATH}.${TARGZ_EXT}"
		VERBATIM
	)
	
 	
	
#MESSAGE(FATAL_ERROR "Extract fail.")
ELSE( WIN32 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ELSE( WIN64 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ENDIF()


