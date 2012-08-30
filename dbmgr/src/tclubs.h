#ifndef __tClubs_h__
#define __tClubs_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CClubsTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		name;
		unsigned int	city;
		std::string		login;
		std::string		pass;
		std::string		email;
		std::string		contacts;
		std::string		web;
		std::string		location;
		std::string		pay_date;
		std::string		exp_date;
		
		std::string		director;
		time_t			director_bd;
		std::string		director_phone;
		std::string		director_email;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CClubsTable(CDbConnection* pCon);
    virtual ~CClubsTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tClubs_h__
