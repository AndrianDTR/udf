#ifndef __DBMANAGER_H__
#define __DBMANAGER_H__

#include "dberrors.h"
#include "dbconnection.h"
#include "wx/string.h"

class CDbManager
{
	bool				m_ok;
	CDbConnection* 		m_pCon;

	static CDbManager* 	ms_instance;

public:
	static CDbManager* Instance();
	static void Release();

	CDbConnection* 	GetConnection(){return m_pCon;}

	bool			Open(std::string host, std::string db, std::string user, std::string pass );
	bool			IsOk();

private:
	CDbManager();
	virtual ~CDbManager();

};

#endif // __DBMANAGER_H__
