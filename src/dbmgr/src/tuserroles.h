#ifndef __tUserRoles_h__
#define __tUserRoles_h__

#include "dbmgr.h"

class CUserRolesTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		name;
		std::string		url;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CUserRolesTable(CDbConnection* pCon);
    virtual ~CUserRolesTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);

protected:
	std::string 		GetFilterString(const tDATA& filter);
};

#endif //__tUserRoles_h__
