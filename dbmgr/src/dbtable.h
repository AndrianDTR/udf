#ifndef __DbTable_h__
#define __DbTable_h__

#include "dbconnection.h"

class CDbTable
{
public:
    CDbTable(CDbConnection* pCon){};
    virtual ~CDbTable(void){};

public:
	virtual long		CreateTable(){};
	virtual long		DropTable(){};
	
	virtual long		Reload(){};
    /*
	virtual long		GetTable(CDbTable* data, const CDbTable& pFilter) = 0;
    virtual long		Find(CDbTable* data, const CDbTable& pFilter) = 0;
    virtual long		AddRow(const CDbTable& rec) = 0;
    virtual long		DelRow(const CDbTable& rec) = 0;
    virtual long		GetRow(CDbTable& rec) = 0;
	 */
};

#endif //__DbTable_h__
