#ifndef __tCategories_h__
#define __tCategories_h__

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
		int				age_category;
		std::string		name;
		std::string		shortName;
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
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tCategories_h__
