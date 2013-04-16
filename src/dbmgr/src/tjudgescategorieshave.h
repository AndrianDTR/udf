#ifndef __tJedgesCategoriesHave_h__
#define __tJedgesCategoriesHave_h__

#include "dbmgr.h"

class CJudgesCategoriesHaveTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	judgeId;
		unsigned int	judCatId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CJudgesCategoriesHaveTable(CDbConnection* pCon);
    virtual ~CJudgesCategoriesHaveTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tJedgesCategoriesHave_h__
