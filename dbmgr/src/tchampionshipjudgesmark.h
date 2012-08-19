#ifndef __tChampionshipJudgesMark_h__
#define __tChampionshipJudgesMark_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipJudgesMarkTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	championshipId;
		unsigned int	judgeId;
		unsigned int	teamId;
		unsigned int	catId;
		int				nMark;
			
		bool operator< (const tDATA& _x) const{
			return championshipId < _x.championshipId 
				&& judgeId < _x.judgeId
				&& teamId < _x.teamId
				&& catId < _x.catId;
		};
	};

	typedef set<tDATA> tTableSet;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipJudgesMarkTable(CDbConnection* pCon);
    virtual ~CChampionshipJudgesMarkTable(void);

public:
    virtual long		GetTable(tTableSet** data);
    virtual long		Find(tTableSet** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tChampionshipJudgesMark_h__
