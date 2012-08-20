#ifndef __tCities_h__
#define __tCities_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CCitiesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
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
    virtual long		GetTable(tTableMap** data);
    virtual long		Find(tTableMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tCities_h__
