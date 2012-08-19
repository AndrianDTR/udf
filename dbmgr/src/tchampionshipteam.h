#ifndef __tChampionshipTeams_h__
#define __tChampionshipTeams_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipTeamsTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	dancerId;
		unsigned int	championshipId;
		std::string		compositionName;
		unsigned int	startNumber;
		
		bool operator< (const tDATA& _x) const{ 
			return id < _x.id 
				&& dancerId < _x.dancerId
				&& championshipId < _x.championshipId;};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipTeamsTable(CDbConnection* pCon);
    virtual ~CChampionshipTeamsTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tChampionshipTeams_h__
