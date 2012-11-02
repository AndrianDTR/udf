#ifndef __tChampionshipType_h__
#define __tChampionshipType_h__

#include "db.h"

class CChampionshipTypeTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){};
		std::string		name;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CChampionshipTypeTable(CDbConnection* pCon);
    virtual ~CChampionshipTypeTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tChampionshipType_h____tChampionshipType_h__
