#ifndef __tCsBlockJ2C_h__
#define __tCsBlockJ2C_h__

#include "db.h"

class CCsBlockJ2CTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	blockId;
		unsigned int	csJudgeId;
		unsigned int	csCatId;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

public:
    CCsBlockJ2CTable(CDbConnection* pCon);
    virtual ~CCsBlockJ2CTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
	virtual long 			FindId(unsigned int& id, const tDATA& filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetFilterString(const tDATA& filter);
};

#endif //__tCsBlockJ2C_h__
