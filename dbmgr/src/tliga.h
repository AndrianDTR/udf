#ifndef __tLiga_h__
#define __tLiga_h__

#include "db.h"

class CLigaTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){code = 0;};
		unsigned int	code;
		std::string		name;
	};

	typedef std::map<unsigned int, tDATA> tTableMap;
	typedef std::map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CLigaTable(CDbConnection* pCon);
    virtual ~CLigaTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA* const filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tLiga_h__
