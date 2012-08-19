#ifndef __tCities_h__
#define __tCities_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CCitiesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	countryId;
		std::string		Name;
		bool operator< (const tDATA& _x) const{ 
			return id < _x.id 
				&& countryId < _x.countryId;
		};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CCitiesTable(CDbConnection* pCon);
    virtual ~CCitiesTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tCities_h__
