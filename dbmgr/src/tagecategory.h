#ifndef __tAgeCategory_h__
#define __tAgeCategory_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CAgeCategoryTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){code = 0;};
		unsigned int		code;
		std::string			name;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* 			m_pConnection;

public:
    CAgeCategoryTable(CDbConnection* pCon);
    virtual ~CAgeCategoryTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tAgeCategory_h__
