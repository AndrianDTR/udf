#ifndef __tChampionshipJudgesTeam_h__
#define __tChampionshipJudgesTeam_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipJudgesTeamTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	championshipId;
		unsigned int	judjeId;
		bool operator< (const tDATA& _x) const{ return championshipId < _x.championshipId && judjeId < _x.judjeId;};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipJudgesTeamTable(CDbConnection* pCon);
    virtual ~CChampionshipJudgesTeamTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tChampionshipJudgesTeam_h__
