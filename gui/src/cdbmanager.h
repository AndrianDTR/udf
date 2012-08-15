#ifndef __DBMANAGER_H__
#define __DBMANAGER_H__

#include "datatypes.h"
#include "cdbconnection_base.h"

class CDbManager {
	
	CDbConnection* m_pDBCon;
		
	static CDbManager* ms_instance;

public:
	static CDbManager* Instance();
	static void Release();

private:
	CDbManager();
	virtual ~CDbManager();

};

#endif // __DBMANAGER_H__
