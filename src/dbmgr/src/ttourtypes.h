#ifndef __tTourTypes_h__
#define __tTourTypes_h__

#include "dbmgr.h"

class CTourTypesTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		name;
		unsigned int	min;
		unsigned int	max;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CTourTypesTable(CDbConnection* pCon);
    virtual ~CTourTypesTable(void);

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

#endif //__tTourTypes_h__
