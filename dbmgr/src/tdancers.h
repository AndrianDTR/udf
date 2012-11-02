#ifndef __tDancers_h__
#define __tDancers_h__

#include "db.h"

class CDancersTable : public CDbTable
{
public:
	struct tDATA:public CDbTable::tDATA{
		tDATA():CDbTable::tDATA(){clubId = 0; trainerId = 0; liga = 0; gender = 0; raiting = 0; bd = 0; reg_date = 0;};
		unsigned int	clubId;
		unsigned int	trainerId;
		int				liga;
		int 			gender;
		std::string		regBook;
		std::string		name;
		std::string 	additionalInfo;
		unsigned int	raiting;
		time_t			bd;
		time_t			reg_date;
	};

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CDancersTable(CDbConnection* pCon);
    virtual ~CDancersTable(void);

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

#endif //__tDancers_h__
