#include "cdbmanager.h"

#include "cdbconnection_base.h"

#include "iostream"
using namespace std;

CDbManager* CDbManager::ms_instance = 0;

CDbManager::CDbManager()
{
	try
	{
		CDbConnection* con = getConnection();
		con->Connect("192.169.10.17","udf","andrian","dataNet");
		cout<< con->GetName() <<endl<<con->GetVersion()<<endl;
		con->GetAgeCategoryList(NULL);
	}
	catch (CDbException &e)
	{
		cout << "File: "<< __FILE__<<":"<<__LINE__<<endl;
		cout << "ERROR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << ")" << endl;

		if (e.getErrorCode() == 1047) {
			/*
			Error: 1047 SQLSTATE: 08S01 (ER_UNKNOWN_COM_ERROR)
			Message: Unknown command
			*/
			cout << "\nYour server does not seem to support Prepared Statements at all. ";
			cout << "Perhaps MYSQL < 4.1?" << endl;
		}
	} 
	catch (std::runtime_error &e) 
	{
		cout << "File: "<< __FILE__<<":"<<__LINE__<<endl;
		cout << "ERROR: " << e.what() << endl;
	}
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

