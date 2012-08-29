#ifndef __dbconnection_h__
#define __dbconnection_h__

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
	long				Execute(std::string query);
	unsigned long long	GetLastInsertId();
};

#endif //__dbconnection_h__
