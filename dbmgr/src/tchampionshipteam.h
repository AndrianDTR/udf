#ifndef __tChampionshipTeams_h__
#define __tChampionshipTeams_h__

#include "db.h"

class CChampionshipTeamsTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	clubId;
		unsigned int	championshipId;
		std::string		name;
		unsigned int	startNumber;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipTeamsTable(CDbConnection* pCon);
    virtual ~CChampionshipTeamsTable(void);

public:
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tChampionshipTeams_h__
