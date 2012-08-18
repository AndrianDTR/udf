#ifndef __tAgeCode_h__
#define __tAgeCode_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

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

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipJudgesMarkTable(CDbConnection* pCon);
    virtual ~CChampionshipJudgesMarkTable(void);

public:
    virtual long		GetTable(tTableMap** data);
    virtual long		Find(tTableMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tAgeCode_h__
