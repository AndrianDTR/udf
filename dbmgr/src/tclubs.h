#ifndef __tClubs_h__
#define __tClubs_h__

#include "db.h"

class CClubsTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){city = 0; director_bd = 0;};
		std::string		name;
		unsigned int	city;
		std::string		login;
		std::string		pass;
		std::string		email;
		std::string		contacts;
		std::string		web;
		std::string		additionalInfo;

		std::string		director;
		time_t			director_bd;
		std::string		director_phone;
		std::string		director_email;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CClubsTable(CDbConnection* pCon);
    virtual ~CClubsTable(void);

public:
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tClubs_h__
