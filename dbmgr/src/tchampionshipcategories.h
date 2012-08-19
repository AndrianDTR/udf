#ifndef __tChampionshipCategoties_h__
#define __tChampionshipCategoties_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipCategotiesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	championshipId;
		unsigned int	catId;
		bool operator< (const tDATA& _x) const{ return championshipId < _x.championshipId && catId < _x.catId;};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipCategotiesTable(CDbConnection* pCon);
    virtual ~CChampionshipCategotiesTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(const tDATA& filter);
    virtual long		GetRow(const tDATA& filter, tDATA& data);
};

#endif //__tChampionshipCategoties_h__
