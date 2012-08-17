#include "stdio.h"

#include "dberrors.h"
#include "dbconnection.h"

#include "cppconn/driver.h"
#include "cppconn/statement.h"
//#include "cppconn/prepared_statement.h"
//#include "cppconn/exception.h"
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
			break;
		}
		
		pCon = pDriver->connect(szUrl, szUser, szPass);
		if(!pCon)
		{
			res = UDF_E_CONNECTION;
			break;
		}

		pCon->setSchema(szSchema);
		
		pStmt = pCon->createStatement();
		if(!pStmt)
		{
			res = UDF_E_CREATE_STATEMENT;
			break;
		}
				
		m_pConnection = pCon;
		m_pStatement = pStmt;
		res = UDF_OK;
	}while(0);
	
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
	
	if(m_pStatement)
	{
		res = m_pStatement->executeQuery(query);	
		printf("EXECUTE QUERY: %s \nResult %d\n", query.c_str(), res);
	}
	
	return res;
}

void CDbConnection::Execute(std::string query)
{
	if(m_pStatement)
	{
		m_pStatement->execute(query);	
		printf("EXECUTE: %s \n", query.c_str());
	}
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
			
			printf("GetLast insert id: %ld \n", res);
		}
	}while(0);
	
	return res;
}
