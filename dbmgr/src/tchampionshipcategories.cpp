
#include "stdio.h"

#include "dberrors.h"
#include "tchampionshipcategories.h"

#define	TABLE	TABLE_CHAMPIONSHIPCATEGORIES

CChampionshipCategotiesTable::CChampionshipCategotiesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipCategotiesTable::~CChampionshipCategotiesTable(void)
{
}

long CChampionshipCategotiesTable::GetTable(tTableSet** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipCategotiesTable::Find(tTableSet** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		tTableSet*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableSet();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		if (filter.catId != -1)
		{
			sprintf(tmp, "%sand `cat_id` like %d ", query, filter.catId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.championshipId != -1)
		{
			sprintf(tmp, "%sand `championship_id` like %d ", query, filter.championshipId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "select * from %s where 1=1 %s", TABLE, query);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
		}
		else
		{
			sprintf(query, "select * from %s", TABLE);
		}
		
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		
		table->clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
            el.championshipId = qRes->getInt(1);
            el.catId = qRes->getInt(2);
		
			table->insert(el);
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipCategotiesTable::AddRow(tDATA& rec)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into %s(`championshipId`,`catId`) values(%d,%d)"
            , TABLE
            , rec.championshipId
            , rec.catId);
		m_pConnection->Execute(query);
		
		rec.championshipId = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipCategotiesTable::DelRow(const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char query[500] = {0};
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "delete from %s where `championshipId` = %d and `cat_id` = %d"
            , TABLE
            , filter.championshipId
            , filter.catId);
		m_pConnection->Execute(query);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipCategotiesTable::GetRow(const tDATA& filter, tDATA& data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "select * from %s where `championshipId` = %d and `cat_id` = %d"
            , TABLE
            , filter.championshipId
            , filter.catId);
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		qRes->next();
        data.championshipId = qRes->getInt(1);
        data.catId = qRes->getInt(2);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}
