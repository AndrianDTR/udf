#ifndef __tPaymentHistory_h__
#define __tPaymentHistory_h__

#include "db.h"

class CPaymentHistoryTable : public CDbTable
{
public:
	typedef struct{
		unsigned long	id;
		unsigned long	personId;
		char			type;
		time_t			payDate;
		time_t			expDate;
		float			sum;
	} tDATA;

	typedef map<unsigned int, tDATA> tTableMap;
	typedef map<unsigned int, tDATA>::iterator tTableIt;

protected:
	CDbConnection* m_pConnection;

public:
    CPaymentHistoryTable(CDbConnection* pCon);
    virtual ~CPaymentHistoryTable(void);

public:
    virtual long		GetTable(tTableMap& data);
    virtual long		Find(tTableMap& data, const tDATA* const filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
	virtual long 		UpdateRow(unsigned int nId, const tDATA& data);

protected:
	std::string 		GetFilterString(const tDATA* const filter);
};

#endif //__tPaymentHistory_h__
