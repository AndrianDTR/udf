#ifndef __tAgeCode_h__
#define __tAgeCode_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CCategoriesTable : public CDbTable
{
public:
	typedef struct{
		unsigned long	id;
		unsigned int	dance;
		int				liga;
		int				gender;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CCategoriesTable(CDbConnection* pCon);
    virtual ~CCategoriesTable(void);

public:
    virtual long		GetTable(tTableMap** data);
    virtual long		Find(tTableMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned long nId);
    virtual long		GetRow(unsigned long nId, tDATA& data);
};

#endif //__tAgeCode_h__
