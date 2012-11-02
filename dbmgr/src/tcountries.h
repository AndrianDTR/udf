#ifndef __tCountries_h__
#define __tCountries_h__

#include "db.h"

class CCountriesTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){};
		std::string		name;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CCountriesTable(CDbConnection* pCon);
    virtual ~CCountriesTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string 	GetFilterString(const tDATA* const filter);
};

#endif //__tCountries_h__
