#include "connection_data.h"

#include "cdbmanager.h"

#include "stdio.h"

#include "tagecategory.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
{
	long res = UDF_E_FAIL;
	do
	{
		m_pCon = new CDbConnection();
		res = m_pCon->Open(szUrl, szUser, szPass, szSchema);
		if(UDF_OK != res)
			break;
		
	}while(0);
	
}

CDbManager::~CDbManager()
{
	if(m_pCon)
	{
		delete m_pCon;
		m_pCon = NULL;
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

