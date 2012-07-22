#include "cdbmanager.h"

#include "dbmgr.h"

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
{
	int a = 0;
	dbmgr_test();
}

CDbManager::~CDbManager()
{
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

