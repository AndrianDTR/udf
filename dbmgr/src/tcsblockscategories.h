#ifndef __tCsBlockCategories_h__
#define __tCsBlockCategories_h__

#include "db.h"

class CCsBlockCategoriesTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	blockId;
		unsigned int	csCatId;
		std::string		name;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* 			m_pConnection;

public:
    CCsBlockCategoriesTable(CDbConnection* pCon);
    virtual ~CCsBlockCategoriesTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetFilterString(const tDATA& filter);
};

#endif //__tCsBlockCategories_h__
