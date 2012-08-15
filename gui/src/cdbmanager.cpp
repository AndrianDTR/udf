#include "cdbmanager.h"



#include "stdio.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
{
	try
	{
		m_pDBCon = getConnection();
		m_pDBCon->Connect("192.169.10.17","udf","andrian","dataNet");
		
		printf("DB Driver: %s, ver: %s\n", m_pDBCon->GetName().c_str(), m_pDBCon->GetVersion().c_str());
		
	}
	catch (CDbException &e)
	{
		printf("File: %s:%d\n", __FILE__, __LINE__);
		printf("Error! %s\n", e.what());
		printf("MySQL error code: %d, SQLState: %s\n\n", e.getErrorCode(), e.getSQLState().c_str());

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			printf("Your server does not seem to support Prepared Statements at all.\n");
			printf("Perhaps MYSQL < 4.1?\n\n");
		}
	} 
	catch (std::runtime_error &e) 
	{
		printf("File: %s:%d\n", __FILE__, __LINE__);
		printf("Runtime error %s\n\n", e.what());
	}
}

CDbManager::~CDbManager()
{
	if(m_pDBCon)
	{
		m_pDBCon->Close();
		delete m_pDBCon;
		m_pDBCon = NULL;
	}
}

CDbManager* CDbManager::Instance()
{
	if(ms_instance == 0){
		ms_instance = new CDbManager();
	}
	return ms_instance;
}

void CDbManager::Release()
{
	if(ms_instance){
		delete ms_instance;
	}
	ms_instance = 0;
}

