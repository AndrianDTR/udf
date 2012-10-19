
#include "stdio.h"

#include "dberrors.h"
#include "tchampionshipcategories.h"

#include "common.h"

#define	TABLE	TABLE_CHAMPIONSHIPCATEGORIES

CChampionshipCategoriesTable::CChampionshipCategoriesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipCategoriesTable::~CChampionshipCategoriesTable(void)
{
}

long CChampionshipCategoriesTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipCategoriesTable::Find(tTableMap& data, const tDATA& filter)
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
		
		if (0 != filter.catId)
		{
			sprintf(tmp, "%sand `category_id` like %d ", query, filter.catId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (0 != filter.championshipId)
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
		
		data.clear();
		
		while( qRes && qRes->next())
		{
			tDATA el = {0};
			
			el.id = qRes->getUInt(1);
            el.championshipId = qRes->getUInt(2);
            el.catId = qRes->getUInt(3);
		
			data.insert(make_pair(el.id, el));
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipCategoriesTable::AddRow(tDATA& rec)
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
		
		sprintf(query, "insert into %s(`championship_id`,`category_id`) values(%d,%d)"
            , TABLE
            , rec.championshipId
            , rec.catId);
		res = m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
	}while(0);
	
	return res;
}

long CChampionshipCategoriesTable::DelRow(unsigned int nId)
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

long CChampionshipCategoriesTable::GetRow(unsigned int nId, tDATA& data)
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
		data.id = qRes->getUInt(1);
        data.championshipId = qRes->getUInt(2);
        data.catId = qRes->getUInt(3);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipCategoriesTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		
		if (0 != data.catId)
		{
			sprintf(tmp, "%s `category_id` = %d,", query, data.catId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (data.championshipId != -1)
		{
			sprintf(tmp, "%s `championship_id` = %d,", query, data.championshipId);
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

long CChampionshipCategoriesTable::GetRegisteredTeamsForCategory(unsigned int nId, int& count)
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
		
		sprintf(query, "select count(t2.team_id) as reg_teams from %s t1"
		" inner join %s t2 on t1.id=t2.category_id and t2.category_id=%ld group by t1.id", TABLE, TABLE_CHAMPIONSHIPTEAMCATEGORIES, nId);

		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}
		
		if(qRes->next())
			count = atoi(string(qRes->getString("reg_teams")).c_str());
		DEBUG_PRINTF("Count : %i", count);

	}while(0);
	
	return res;
}
