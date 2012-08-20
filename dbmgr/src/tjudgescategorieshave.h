#ifndef __tJedgesCategoriesHave_h__
#define __tJedgesCategoriesHave_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "set"

using namespace std;

class CJudgesCategoriesHaveTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	judgeId;
		unsigned int	judCatId;
		bool operator< (const tDATA& _x) const{ 
			return judgeId < _x.judgeId 
				&& judCatId < _x.judCatId;
		};
	};

	typedef set<tDATA> tTableMap;
	typedef set<tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CJudgesCategoriesHaveTable(CDbConnection* pCon);
    virtual ~CJudgesCategoriesHaveTable(void);

public:
    virtual long		GetTable(tTableMap** data);
    virtual long		Find(tTableMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tJedgesCategoriesHave_h__
