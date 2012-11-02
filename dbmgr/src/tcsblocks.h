#ifndef __tCsBlocks_h__
#define __tCsBlocks_h__

#include "db.h"

class CCsBlocksTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	csId;
		unsigned int	order;
		std::string		name;
		time_t			startTime;
		int				pause;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

public:
    CCsBlocksTable(CDbConnection* pCon);
    virtual ~CCsBlocksTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA& filter);
	virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetFilterString(const tDATA& filter);
};

#endif //__tCsBlocks_h__
