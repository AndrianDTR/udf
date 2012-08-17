#ifndef __tAgeCode_h__
#define __tAgeCode_h__

#include "dbconnection.h"
#include "dbtable.h"

#include "map"

using namespace std;

class CAgeCodeTable : public CDbTable
{
public:
	typedef struct{
		unsigned int	id;
		std::string		descr;
	} tDATA;

	typedef map<unsigned int, tDATA> tAgeCodeMap;
	typedef map<unsigned int, tDATA>::iterator tAgeCodeMapIterator;
	
protected:
	CDbConnection* m_pConnection;
	
public:
    CAgeCodeTable(CDbConnection* pCon);
    virtual ~CAgeCodeTable(void);

public:
    virtual long		GetTable(tAgeCodeMap** data);
    virtual long		Find(tAgeCodeMap** data, const tDATA& filter);
    virtual long		AddRow(tDATA& rec);
    virtual long		DelRow(unsigned int nId);
    virtual long		GetRow(unsigned int nId, tDATA& data);
};

#endif //__tAgeCode_h__
