#ifndef __tDancetypes_h__
#define __tDancetypes_h__

#include "dbmgr.h"

class CDanceTypesTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		unsigned int	code;
		std::string		name;
	} tDATA;

	typedef std::map<unsigned int, tDATA> tTableMap;
	typedef std::map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CDanceTypesTable(CDbConnection* pCon);
    virtual ~CDanceTypesTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tDancetypes_h__
