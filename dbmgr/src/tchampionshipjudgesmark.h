#ifndef __tChampionshipJudgesMark_h__
#define __tChampionshipJudgesMark_h__

#include "db.h"

class CChampionshipJudgesMarkTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	judgeId;
		unsigned int	teamId;
		unsigned int	tourId;
		int				nMark;
		char			passed;
	};

	typedef std::map<unsigned int, tDATA> tTableMap;
	typedef std::map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipJudgesMarkTable(CDbConnection* pCon);
    virtual ~CChampionshipJudgesMarkTable(void);

protected:
	std::string 			GetFilterString(const tDATA& filter);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();
};

#endif //__tChampionshipJudgesMark_h__
