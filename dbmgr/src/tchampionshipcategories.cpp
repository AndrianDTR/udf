
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
	long res = UDF_E_FAIL;
	
	do
	{
		char				query[500] = {0};
		tTableSet*	        table = NULL;
		sql::ResultSet*		qRes = NULL;
		
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
		
		sprintf(query, "select * from %s", TABLE);
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

long CChampionshipCategotiesTable::Find(tTableSet** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		tTableSet*		    table = NULL;
		sql::ResultSet*		qRes = NULL;
		
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
		
		sprintf(query, "select * from %s where `catId` = %d or `championship_id` = %d"
            , TABLE
            , filter.catId
            , filter.championshipId);
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
