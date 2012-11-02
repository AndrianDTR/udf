#ifndef __tJedges_h__
#define __tJedges_h__

#include "db.h"

class CJudgesTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){cityId = 0; practicer = udfNO;};
		std::string		name;
		unsigned int	cityId;
		std::string		email;
		std::string		phone;
		std::string		additionalInfo;
		std::string		attestationInfo;
		char			practicer;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CJudgesTable(CDbConnection* pCon);
    virtual ~CJudgesTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetTableName();

protected:
	virtual std::string		GetFilterString(const tDATA* const filter);
};

#endif //__tJedges_h__
