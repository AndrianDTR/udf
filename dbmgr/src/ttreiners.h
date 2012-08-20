#ifndef __tTariners_h__
#define __tTariners_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CTrainersTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		unsigned int	clubId;
		std::string		name;
		std::string		bd;
		std::string		phone;
		std::string		contactInfo;
		std::string		email;
		std::string		pay_date;
		std::string		exp_date;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CTrainersTable(CDbConnection* pCon);
    virtual ~CTrainersTable(void);

public:
    virtual long		GetTable(tTableMap** data);
    virtual long		Find(tTableMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);
};

#endif //__tTariners_h__
