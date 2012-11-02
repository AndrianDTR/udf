#ifndef __tStaff_h__
#define __tStaff_h__

#include "db.h"

class CStaffTable : public CDbTable
{
public:
	struct tDATA{
		unsigned int	id;
		unsigned int	roleId;
		std::string		name;
		std::string		login;
		std::string		pass;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* 			m_pConnection;

public:
    CStaffTable(CDbConnection* pCon);
    virtual ~CStaffTable(void);

public:
    virtual long			GetTable(tTableMap& data);
    virtual long			Find(tTableMap& data, const tDATA* const filter);
    virtual long			AddRow(tDATA& rec);
    virtual long			DelRow(unsigned int nId);
    virtual long			GetRow(unsigned int nId, tDATA& data);
	virtual long 			UpdateRow(unsigned int nId, const tDATA& data);

	virtual std::string 	GetFilterString(const tDATA* const filter);
};

#endif //__tStaff_h__
