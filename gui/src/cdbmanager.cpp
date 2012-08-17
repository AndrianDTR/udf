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
		
		CAgeCategoryTable tbl(m_pCon);
		CAgeCategoryTable::tAgeCategoryMap* m;
		
		res = tbl.GetTable(&m);
		if(UDF_OK != res)
			break;
			
		CAgeCategoryTable::tAgeCategoryMapIterator it = m->begin();
		while(it != m->end())
		{
			printf("%d = %s\n", it->first, it->second.descr.c_str());
			it++;
		}
		
	}while(0);
	
	printf("Open OK, res = %d, %s\n", res, GetErrorMsg(res).c_str());
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

