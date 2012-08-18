
#include "stdio.h"

#include "dberrors.h"
#include "tchampionship.h"

#define	TABLE	TABLE_CHAMPIONSHIP

CChampionshipTable::CChampionshipTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTable::~CChampionshipTable(void)
{
}

long CChampionshipTable::GetTable(tTableMap** data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char				query[500] = {0};
		tTableMap*	table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableMap();
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
			
			el.id = qRes->getUInt(1);
			el.type = qRes->getInt(2);
			el.name = qRes->getString(3);
			el.aditionalInfo  = qRes->getString(4);
			el.city = qRes->getUInt(5);
			
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::Find(tTableMap** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[500] = {0};
		tTableMap*		table = NULL;
		sql::ResultSet*		qRes = NULL;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		table = new tTableMap();
		if(!table)
		{
			res = UDF_E_NOMEMORY;
			break;
		}
		
		sprintf(query, "select * from %s where `name` like '%%%s%%' or `aditional_info` like '%%%s%%' or `city` = %d or `type` = %d"
		, TABLE
		, filter.name.c_str()
		, filter.aditionalInfo.c_str()
		, filter.city
		, filter.type);
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
			
			el.id = qRes->getUInt(1);
			el.type = qRes->getInt(2);
			el.name = qRes->getString(3);
			el.aditionalInfo  = qRes->getString(4);
			el.city = qRes->getUInt(5);
			
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`type`, `name`, `aditional_info`, `city`) values(%d, '%s', '%s', %d)"
		, TABLE
		, rec.type
		, rec.name.c_str()
		, rec.aditionalInfo.c_str()
		, rec.city);
		m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::DelRow(unsigned int nId)
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
		
		sprintf(query, "delete from %s where id = %d", TABLE, nId);
		m_pConnection->Execute(query);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::GetRow(unsigned int nId, tDATA& data)
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
		
		sprintf(query, "select * from %s where id = %d", TABLE, nId);
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		qRes->next();
		data.id = qRes->getUInt(1);
		data.type = qRes->getInt(2);
		data.name = qRes->getString(3);
		data.aditionalInfo  = qRes->getString(4);
		data.city = qRes->getUInt(5);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}
