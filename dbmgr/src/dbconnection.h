#ifndef __DbConnection_h__
#define __DbConnection_h__

#include "string"

#include "cppconn/connection.h"
#include "cppconn/resultset.h"

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
	
	sql::Connection*	GetSqlConnection(){return m_pConnection;};
	sql::ResultSet*		ExecuteQuery(std::string query);
	void				Execute(std::string query);
	unsigned long long	GetLastInsertId();
};

#endif //__DbConnection_h__
