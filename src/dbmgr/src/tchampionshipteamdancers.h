#ifndef __tCChampionshipTeamDancersTable_h__
#define __tCChampionshipTeamDancersTable_h__

#include "db.h"

class CChampionshipTeamDancersTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	teamId;
		unsigned int	dancerId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipTeamDancersTable(CDbConnection* pCon);
    virtual ~CChampionshipTeamDancersTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tCChampionshipTeamDancersTable_h__
