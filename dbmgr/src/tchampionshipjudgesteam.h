#ifndef __tAgeCode_h__
#define __tAgeCode_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CChampionshipJudgesTeamTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	championshipId;
		unsigned int	judjeId;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableSet;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
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

#endif //__tAgeCode_h__
