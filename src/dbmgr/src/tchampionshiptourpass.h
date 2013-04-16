#ifndef __tCChampionshipTourPassTable_h__
#define __tCChampionshipTourPassTable_h__

#include "dbmgr.h"

class CChampionshipTourPassTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	tourId;
		unsigned int	teamId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* 			m_pConnection;

public:
    CChampionshipTourPassTable(CDbConnection* pCon);
    virtual ~CChampionshipTourPassTable(void);

protected:
	virtual std::string		GetFilterString(const tDATA& filter);
	
public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
	virtual long 			FindId(unsigned int& id, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long			UpdateRow(unsigned int nId, const tDATA& data);
	
	virtual std::string 	GetTableName();
};

#endif //__tCChampionshipTourPassTable_h__
