#ifndef __dberrors_h__
#define __dberrors_h__

#include "string"

typedef enum{
	UDF_CRASH = 0,
	UDF_CRITICAL,
	UDF_ERROR,
	UDF_STOP,
	UDF_WARNING,
	UDF_MESSAGE,
	UDF_DEBUG
} UDF_ERR_LEVEL;

typedef enum{
	UDF_OK = 0,
	UDF_E_FAIL = 10,
	
	UDF_E_INIT_DRIVER = 100,
	UDF_E_CONNECTION,
	UDF_E_NOSCHEMA,
	UDF_E_CREATE_STATEMENT,
	UDF_E_NOCONNECTION,
	UDF_E_NOMEMORY,
	UDF_E_EXECUTE_QUERY_FAILED,
	
	UDF_E_NOTFOUND,
	
} UDF_ERRORS;

void		FillErrorMap();
std::string GetErrorMsg(long code);

#endif //__dberrors_h__
