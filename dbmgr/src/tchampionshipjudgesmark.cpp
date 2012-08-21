
#include "stdio.h"

#include "dberrors.h"
#include "tchampionshipjudgesmark.h"

#define	TABLE	TABLE_CHAMPIONSHIPJUDGESMARK

CChampionshipJudgesMarkTable::CChampionshipJudgesMarkTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipJudgesMarkTable::~CChampionshipJudgesMarkTable(void)
{
}

long CChampionshipJudgesMarkTable::GetTable(tTableMap** data)
{
	tDATA filter = {0};
	
	return Find(data, filter);
}

long CChampionshipJudgesMarkTable::Find(tTableMap** data, const tDATA& filter)
{
	long res = UDF_E_FAIL;
	
	do
	{
		char 				query[MAX_QUERY_LEN] = {0};
		char 				tmp[MAX_QUERY_LEN] = {0};
		tTableMap*			table = NULL;
		sql::ResultSet*		qRes = NULL;
		bool 				useFilter = false;
		
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
		
		if (filter.catId != -1)
		{
			sprintf(tmp, "%sand `category_id` like %d ", query, filter.catId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.championshipId != -1)
		{
			sprintf(tmp, "%sand `championship_id` like %d ", query, filter.championshipId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.judgeId != -1)
		{
			sprintf(tmp, "%sand `judge_id` like %d ", query, filter.judgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.teamId != -1)
		{
			sprintf(tmp, "%sand `team_id` like %d ", query, filter.teamId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (filter.nMark != -1)
		{
			sprintf(tmp, "%sand `mark` = %d ", query, filter.nMark);
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
			
			el.id = qRes->getUInt64(1);
            el.championshipId = qRes->getUInt64(2);
            el.judgeId = qRes->getUInt(3);
            el.teamId = qRes->getUInt(4);
            el.catId = qRes->getInt(5);
            el.nMark = qRes->getInt(6);
		
			table->insert(make_pair(el.id, el));
		}
		
		*data = table;
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipJudgesMarkTable::AddRow(tDATA& rec)
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
		
        sprintf(query, "insert into %s(`championship_id`,`judge_id`,`team_id`,`category_id`,`mark`) values(%d,%d,%d,%d,%d)"
            , TABLE
            , rec.championshipId
            , rec.judgeId
            , rec.teamId
            , rec.catId
            , rec.nMark);
        m_pConnection->Execute(query);
		
		rec.id = m_pConnection->GetLastInsertId();
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipJudgesMarkTable::DelRow(unsigned int nId)
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

long CChampionshipJudgesMarkTable::GetRow(unsigned int nId, tDATA& data)
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
        data.championshipId = qRes->getUInt64(1);
        data.judgeId = qRes->getUInt(2);
        data.teamId = qRes->getUInt(3);
        data.catId = qRes->getInt(4);
        data.nMark = qRes->getInt(5);
		
		res = UDF_OK;
	}while(0);
	
	return res;
}

long CChampionshipJudgesMarkTable::UpdateRow(unsigned int nId, const tDATA& data)
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
		
		if (data.catId != -1)
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
		
		if (data.judgeId != -1)
		{
			sprintf(tmp, "%s `judge_id` = %d,", query, data.judgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (data.teamId != -1)
		{
			sprintf(tmp, "%s `team_id` = %d,", query, data.teamId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if (data.nMark != -1)
		{
			sprintf(tmp, "%s `mark` = %d,", query, data.nMark);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}
		
		if(useFilter)
		{
			sprintf(tmp, "update %s set %s `id`=%d where `id`=%d", TABLE, query, nId, nId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			m_pConnection->Execute(query);
		}
		
		res = UDF_OK;
	}while(0);
	
	return res;
}