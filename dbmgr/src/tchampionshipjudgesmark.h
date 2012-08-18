#ifndef __tAgeCode_h__
#define __tAgeCode_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipJudgesMarkTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	championshipId;
		unsigned int	judgeId;
		unsigned int	teamId;
		unsigned int	catId;
		int				mark;
	} tDATA;

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

#endif //__tAgeCode_h__
