#ifndef __tChampionshipCategoties_h__
#define __tChampionshipCategoties_h__

#include "db.h"

class CChampionshipCategoriesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	championshipId;
		unsigned int	catId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipCategoriesTable(CDbConnection* pCon);
    virtual ~CChampionshipCategoriesTable(void);

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

#endif //__tChampionshipCategoties_h__
