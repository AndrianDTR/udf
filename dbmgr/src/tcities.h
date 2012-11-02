#ifndef __tCities_h__
#define __tCities_h__

#include "db.h"

class CCitiesTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){countryId = 0;};
		unsigned int	countryId;
		std::string		Name;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CCitiesTable(CDbConnection* pCon);
    virtual ~CCitiesTable(void);

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

#endif //__tCities_h__
