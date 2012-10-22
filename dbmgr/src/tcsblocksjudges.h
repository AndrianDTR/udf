#ifndef __tCsBlockJudges_h__
#define __tCsBlockJudges_h__

#include "db.h"

class CCsBlockJudgesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	blockId;
		unsigned int	csJudgeId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

public:
    CCsBlockJudgesTable(CDbConnection* pCon);
    virtual ~CCsBlockJudgesTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetFilterString(const tDATA& filter);
};

#endif //__tCsBlockJudges_h__
