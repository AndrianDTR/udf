#ifndef __tCahmpionship_h__
#define __tCahmpionship_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CChampionshipTable : public CDbTable
{
public:
	typedef struct{
		unsigned long	id;
		unsigned int	type;
		std::string		name;
		std::string		additionalInfo;
		int				city;
		std::string		address;
		time_t			date;
		time_t			regOpenDate;
		time_t			regCloseDate;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CChampionshipTable(CDbConnection* pCon);
    virtual ~CChampionshipTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
	virtual long		Find(tTableMap& data, const tDATA& filter, const int* pOrderMap);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
	virtual long 		ExecuteQuery(string query, tTableMap& data);
	
	virtual long		ParseResult(void* pRes, tTableMap& data);
	virtual std::string GetTableName();
};

#endif //__tCahmpionship_h__
