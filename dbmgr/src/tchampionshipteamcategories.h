#ifndef __tChampionshipTeamCategories_h__
#define __tChampionshipTeamCategories_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipTeamCategoriesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	catId;
		bool operator< (const tDATA& _x) const{ return id < _x.id && catId < _x.catId;};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipTeamCategoriesTable(CDbConnection* pCon);
    virtual ~CChampionshipTeamCategoriesTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tChampionshipTeamCategories_h__
