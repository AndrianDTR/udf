#include "dberrors.h"
#include "map"

#include "stdio.h"

typedef std::map<long, std::string> tErrorMap;
typedef std::map<long, std::string>::iterator tErrorMapIter;

tErrorMap gErrMap;

#define RegErrMsg(CODE, MSG)	gErrMap.insert(std::make_pair(CODE, MSG))

void FillErrorMap()
{
	RegErrMsg(UDF_OK, "OK");
	RegErrMsg(UDF_E_FAIL, "Internal error happend.");
	
	RegErrMsg(UDF_E_INIT_DRIVER, "MySQL initialize driver instance failed.");
	RegErrMsg(UDF_E_CONNECTION, "MySQL connection failed.");
	RegErrMsg(UDF_E_NOSCHEMA, "MySQL set schema failed.");
	RegErrMsg(UDF_E_CREATE_STATEMENT, "MySQL create statement failed.");
	RegErrMsg(UDF_E_NOCONNECTION, "MySQL connection not opened.");
	RegErrMsg(UDF_E_NOMEMORY, "No enougth memory.");
	RegErrMsg(UDF_E_EXECUTE_QUERY_FAILED, "Execute query failed.");
}

std::string GetErrorMsg(long code)
{
	std::string msg("Unknown error.");
	
	tErrorMapIter it = gErrMap.find(code);
	if(it != gErrMap.end())
	{
		msg = it->second;
	}
	
	return msg;
}