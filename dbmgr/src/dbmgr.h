#ifndef __UDF_DBMGR_H__
#define __UDF_DBMGR_H__

#include "cdbconnection_base.h"



#include "cppconn/driver.h"
#include "cppconn/connection.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"
#include "cppconn/warning.h"

#include "map"

using namespace std;
using namespace sql;

#ifdef __cplusplus
extern "C" {
#endif

int dbmgr_test();

#ifdef __cplusplus
}
#endif

#endif //__UDF_DBMGR_H__