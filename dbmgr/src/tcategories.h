#ifndef __tCategories_h__
#define __tCategories_h__

#include "db.h"

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
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned long nId);
    virtual long			GetRow(unsigned long nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tCategories_h__
