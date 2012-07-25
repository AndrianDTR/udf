cmake_minimum_required(VERSION 2.6)

IF (UNIX)

	exec_program(
		tar 
		ARGS "-C ${CMAKE_CURRENT_SOURCE_DIR} -xvzf ${CMAKE_CURRENT_SOURCE_DIR}/${BOOST_LIB_FILE}.${TARGZ_EXT}"
 	)
	
	exec_program(
		tar 
		ARGS "-C ${CMAKE_CURRENT_SOURCE_DIR} -xvzf ${CMAKE_CURRENT_SOURCE_DIR}/${MYSQL_CONN_FILE}.${TARGZ_EXT}"
 	)
 	
 	exec_program(
 	   cd 
 	   ARGS "${MYSQL_CONN_PATH} && cmake -DBOOST_ROOT=${BOOST_PATH} . && make"
	)
 	
#MESSAGE(FATAL_ERROR "Extract fail.")
ELSE( WIN32 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ELSE( WIN64 )
	MESSAGE(FATAL_ERROR "Extract MySQL connector for win32 not implemented yet.")
ENDIF()


