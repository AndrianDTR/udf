#ifndef __tJedges_h__
#define __tJedges_h__

#include "db.h"

class CJudgesTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		name;
		unsigned int	cityId;
		std::string		email;
		std::string		phone;
		std::string		additionalInfo;
		std::string		attestationInfo;
		char			practicer;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CJudgesTable(CDbConnection* pCon);
    virtual ~CJudgesTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tJedges_h__
