
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

long CChampionshipTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipTable::Find(tTableMap& data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		if (!filter.name.empty())
		{
			sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (!filter.additionalInfo.empty())
		{
			sprintf(tmp, "%sand `additional_info` like '%%%s%%' ", query, filter.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.city)
		{
			sprintf(tmp, "%sand `city` like %d ", query, filter.city);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.type)
		{
			sprintf(tmp, "%sand `type` like %d ", query, filter.type);
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
		
		data.clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.id = qRes->getUInt(1);
			el.type = qRes->getInt(2);
			el.name = qRes->getString(3);
			el.additionalInfo  = qRes->getString(4);
			el.city = qRes->getUInt(5);
			
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::AddRow(tDATA& rec)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
				
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "insert into %s(`type`, `name`, `additional_info`, `city`) values(%d, '%s', '%s', %d)"
		, TABLE
		, rec.type
		, rec.name.c_str()
		, rec.additionalInfo.c_str()
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
		char query[MAX_QUERY_LEN] = {0};
		
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
		char 				query[MAX_QUERY_LEN] = {0};
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
		data.additionalInfo  = qRes->getString(4);
		data.city = qRes->getUInt(5);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipTable::UpdateRow(unsigned int nId, const tDATA& data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		sprintf(query, "update %s set `name`='%s' where id = %d", TABLE, data.name.c_str(), nId);
		m_pConnection->Execute(query);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}