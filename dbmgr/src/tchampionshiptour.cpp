
#include "stdio.h"

#include "common.h"
#include "dberrors.h"
#include "tchampionshiptour.h"

#define	TABLE	TABLE_CHAMPIONSHIPTOUR

CChampionshipToursTable::CChampionshipToursTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipToursTable::~CChampionshipToursTable(void)
{
}

long CChampionshipToursTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipToursTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.championshipId)
		{
			sprintf(tmp, "%sand `championship_id` like %d ", query, filter.championshipId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
	
		if (0 != filter.limit)
		{
			sprintf(tmp, "%sand `limit` like %d ", query, filter.limit);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.final)
		{
			sprintf(tmp, "%sand `final` like '%c' ", query, filter.final);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (! filter.name.empty())
		{
			sprintf(tmp, "%sand `name` like '%s' ", query, filter.name.c_str());
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
            el.championshipId = qRes->getUInt(2);
			el.name = qRes->getString(3);
			el.limit = qRes->getInt(4);
            el.final = qRes->getString(5)[0];
		
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipToursTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`championship_id`,`name`,`limit`,`final`)"
		" values(%d, '%s', %d, '%s')"
            , TABLE
            , rec.championshipId
            , rec.name.c_str()
			, rec.limit
			, rec.final
			);
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CChampionshipToursTable::DelRow(unsigned int nId)
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
		res = m_pConnection->Execute(query);
	}while(0);
	
	return res;
}

long CChampionshipToursTable::GetRow(unsigned int nId, tDATA& data)
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
		
		sprintf(query, "select * from %s where `id` = %d"
            , TABLE
            , nId);
		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		qRes->next();
        data.id = qRes->getInt(1);
		data.championshipId = qRes->getUInt(2);
		data.name = qRes->getString(3);
		data.limit = qRes->getInt(4);
        data.final = qRes->getString(5)[0];
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipToursTable::UpdateRow(unsigned int nId, const tDATA& data)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		bool 				useFilter = false;
		
		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}
		
		if (! data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.championshipId)
		{
			sprintf(tmp, "%s `championship_id` = %d,", query, data.championshipId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.limit)
		{
			sprintf(tmp, "%s `limit` = %d,", query, data.limit);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != data.final)
		{
			sprintf(tmp, "%s `final` = '%c',", query, data.final);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "update %s set %s `id`=%d where `id`=%d", TABLE, query, nId, nId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			res = m_pConnection->Execute(query);
		}

	}while(0);
	
	return res;
}