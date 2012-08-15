#ifndef __DbTable_h__
#define __DbTable_h__

#include "connection"

class CDbTable
{
public:
    CDbTable(CDbConnection* pCon);
    virtual ~CDbTable(void);

public:
    virtual CDbTable*   GetTable(CDbTable* pFilter) = 0;
    virtual CDbTable*   Find(CDbTable* pFilter) = 0;
    virtual long        AddRow(const CDbTable& rec) = 0;
    virtual long        DelRow(const CDbTable& rec) = 0;
};

#endif //__DbTable_h__