#ifndef __tChampionshipJudgesTeam_h__
#define __tChampionshipJudgesTeam_h__

#include "db.h"

class CChampionshipJudgesTeamTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){championshipId = 0; judgeId = 0;};
		unsigned int	championshipId;
		unsigned int	judgeId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipJudgesTeamTable(CDbConnection* pCon);
    virtual ~CChampionshipJudgesTeamTable(void);

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

#endif //__tChampionshipJudgesTeam_h__
