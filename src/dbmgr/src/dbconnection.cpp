#include "dbconnection.h"
#include "dbmgr.h"

#include "cppconn/driver.h"
#include "cppconn/statement.h"
//#include "cppconn/prepared_statement.h"
#include "cppconn/exception.h"
//#include "cppconn/warning.h"

using namespace sql;

CDbConnection::CDbConnection()
: m_pConnection(NULL)
, m_pStatement(NULL)
{
	FillErrorMap();
}

CDbConnection::~CDbConnection(void)
{
	Close();
}

long CDbConnection::Open(std::string szUrl, std::string szUser, std::string szPass, std::string szSchema)
{
	Enter();
	long res = UDF_E_FAIL;

	do
	{
		sql::Driver* 		pDriver = NULL;
		sql::Connection* 	pCon = NULL;
		sql::Statement*		pStmt = NULL;
		
		pDriver = get_driver_instance();
		if(!pDriver)
		{
			res = UDF_E_INIT_DRIVER;
			__msg("No driver");
			break;
		}
		
		pCon = pDriver->connect(szUrl, szUser, szPass);
		if(!pCon)
		{
			res = UDF_E_CONNECTION;
			__msg("No connect");
			break;
		}
		
		try
		{
			pCon->setSchema(szSchema);
		}
		catch(...)
		{
			__msg("Set schema failed.");
			res = UDF_E_NOSCHEMA;
			break;
		}

		pStmt = pCon->createStatement();
		if(!pStmt)
		{
			res = UDF_E_CREATE_STATEMENT;
			__msg("No statement");
			break;
		}
		
		m_pConnection = pCon;
		m_pStatement = pStmt;
		res = UDF_OK;
	}while(0);

	Leave();
	return res;
}


void CDbConnection::Close()
{
	if(m_pStatement)
	{
		delete m_pStatement;
		m_pStatement = NULL;
	}

	if(m_pConnection)
	{
		delete m_pConnection;
		m_pConnection = NULL;
	}
}

sql::ResultSet* CDbConnection::ExecuteQuery(std::string query)
{
	sql::ResultSet* res = NULL;

	try
	{
		if(m_pStatement)
		{
			__debug("EXECUTE QUERY: %s \nResult %d", query.c_str(), res);
			res = m_pStatement->executeQuery(query);
		}
	}
	catch(sql::SQLException &e)
	{
		fprintf(stderr,"ERROR: %s\n", e.what());
		fprintf(stderr,"(MySQL error code: %d)\n",e.getErrorCode());
	}
	catch(std::runtime_error &e)
	{
		fprintf(stderr,"ERROR: Runtime error: %s\n", e.what());
	}
	return res;
}

long CDbConnection::Execute(std::string query)
{
	long res = UDF_E_EXECUTE_QUERY_FAILED;
	try
	{
		if(m_pStatement)
		{
			__debug("EXECUTE: %s \n", query.c_str());
			m_pStatement->execute(query);
		}
		res = UDF_OK;
	}
	catch(sql::SQLException &e)
	{
		fprintf(stderr,"ERROR: %s\n", e.what());
		fprintf(stderr,"(MySQL error code: %d)\n",e.getErrorCode());
	}
	catch(std::runtime_error &e)
	{
		fprintf(stderr,"ERROR: Runtime error: %s\n", e.what());
	}
	return res;
}

unsigned long long CDbConnection::GetLastInsertId()
{
	unsigned long long res = -1;
	do
	{
		if(m_pStatement)
		{
			sql::ResultSet* qRes = ExecuteQuery("select LAST_INSERT_ID() as id");
			if(!qRes)
			{
				break;
			}
			qRes->next();
			res = qRes->getUInt64(1);
			__debug("Get last insert id: %ld", res);
		}
	}while(0);

	return res;
}

