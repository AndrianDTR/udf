#ifndef __DbConnection_h__
#define __DbConnection_h__

#include "string"

#include "cppconn/connection.h"

class CDbConnection
{
protected:
	sql::Connection*	m_pConnection;
	sql::Statement*		m_pStatement;
	
public:
    CDbConnection();
    virtual ~CDbConnection(void);

public:
	long	Open(std::string url, std::string user, std::string pass, std::string schema);
	void	Close();
	
};

#endif //__DbConnection_h__
