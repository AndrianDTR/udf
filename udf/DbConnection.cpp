#include "DbConnection.h"

#include "cppconn/driver.h"
#include "cppconn/statement.h"
#include "cppconn/prepared_statement.h"
#include "cppconn/resultset.h"
#include "cppconn/exception.h"
#include "cppconn/warning.h"

CDbConnection::CDbConnection()
: m_pConnection(NULL)
, m_pStatement(NULL)
{
}

CDbConnection::~CDbConnection(void)
{
	Close();
}

long Open(std::string szUrl, std::string szUser, std::string szPass, std::string szSchema)
{
	long res = 0;
	
	do
	{
		sql::Driver* 		pDriver = NULL;
		sql::Connection* 	pCon = NULL;
		sql::Statement*		pStmt = NULL;	
		
		pDriver = sql::mysql::get_driver_instance();
		if(!pDriver)
		{
			res = 1;
			break;
		}
		
		pCon = pDriver->Connect(szUrl, szUser, szPass);
		if(!pCon)
		{
			res = 2;
			break;
		}

		pCon->setSchema(szSchema);
		
		pStmt = pCon->createStatement();
		if(!pStmt)
		{
			res = 3;
			break;
		}
				
		m_pConnection = pCon;
		m_pStatement = pStmt;
	}
	
	return res;
}


void Close()
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
