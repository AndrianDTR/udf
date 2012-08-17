#ifndef __DBMANAGER_H__
#define __DBMANAGER_H__

#include "dberrors.h"
#include "dbconnection.h"

class CDbManager {
	
	CDbConnection* m_pCon;
		
	static CDbManager* ms_instance;

public:
	static CDbManager* Instance();
	static void Release();
	
	CDbConnection* GetConnection(){return m_pCon;}

private:
	CDbManager();
	virtual ~CDbManager();

};

#endif // __DBMANAGER_H__
