#ifndef __tAgeCategory_h__
#define __tAgeCategory_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CAgeCategoryTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		descr;
	} tDATA;

	typedef map<unsigned int, tDATA> tAgeCategoryMap;
	typedef map<unsigned int, tDATA>::iterator tAgeCategoryMapIterator;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CAgeCategoryTable(CDbConnection* pCon);
    virtual ~CAgeCategoryTable(void);

public:
    virtual long		GetTable(tAgeCategoryMap** data);
    virtual long		Find(tAgeCategoryMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tAgeCategory_h__
