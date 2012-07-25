cmake_minimum_required(VERSION 2.6)

IF (UNIX)
	add_custom_target(boost ALL
		COMMAND ${CMAKE_COMMAND} -E tar -C ${CMAKE_CURRENT_SOURCE_DIR} -xvzf ${CMAKE_CURRENT_SOURCE_DIR}/${BOOST_LIB_FILE}.${TARGZ_EXT}
		DEPENDS ${BOOST_LIB_FILE}.${TARGZ_EXT}
 	)
	
	add_custom_target(mysql ALL
		COMMAND ${CMAKE_COMMAND} -E tar -C ${CMAKE_CURRENT_SOURCE_DIR} -xvzf ${CMAKE_CURRENT_SOURCE_DIR}/${MYSQL_CONN_FILE}.${TARGZ_EXT}
		DEPENDS ${MYSQL_CONN_FILE}.${TARGZ_EXT}
 	)

ELSE( WIN32 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ELSE( WIN64 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ENDIF()


