#ifndef __tTariners_h__
#define __tTariners_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CTrainersTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){clubId = 0; bd = 0;};
		unsigned int	clubId;
		std::string		name;
		time_t			bd;
		std::string		phone;
		std::string		additionalInfo;
		std::string		email;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CTrainersTable(CDbConnection* pCon);
    virtual ~CTrainersTable(void);

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

#endif //__tTariners_h__
