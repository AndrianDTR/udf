#ifndef __tChampionshipTeamCategories_h__
#define __tChampionshipTeamCategories_h__

#include "dbmgr.h"

class CChampionshipTeamCategoriesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	teamId;
		unsigned int	csCatId;
		std::string		compositionName;
		time_t			lenght;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipTeamCategoriesTable(CDbConnection* pCon);
    virtual ~CChampionshipTeamCategoriesTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long			UpdateRow(unsigned int nId, const tDATA& data);
	
	virtual std::string 	GetFilterString(const tDATA& filter);
};

#endif //__tChampionshipTeamCategories_h__
