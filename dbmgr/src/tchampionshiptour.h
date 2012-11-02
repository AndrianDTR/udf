#ifndef __tChampionshipTour_h__
#define __tChampionshipTour_h__

#include "db.h"

class CChampionshipToursTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	csCatId;
		unsigned int	typeId;
		int				limit;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipToursTable(CDbConnection* pCon);
    virtual ~CChampionshipToursTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	std::string				GetFilterString(const tDATA* const filter);
};

#endif //__tChampionshipTour_h__
