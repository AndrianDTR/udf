#ifndef __tDancers_h__
#define __tDancers_h__

#include "dbmgr.h"

class CDancersTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
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
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CDancersTable(CDbConnection* pCon);
    virtual ~CDancersTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tDancers_h__
