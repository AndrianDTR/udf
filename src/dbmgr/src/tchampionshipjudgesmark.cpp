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

std::string CChampionshipJudgesMarkTable::GetTableName()
{
	return TABLE;
}

long CChampionshipJudgesMarkTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CChampionshipJudgesMarkTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter.tourId)
	{
		sprintf(tmp, "%sand `tour_id` like %d ", query, filter.tourId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.judgeId)
	{
		sprintf(tmp, "%sand `judge_id` like %d ", query, filter.judgeId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.teamId)
	{
		sprintf(tmp, "%sand `team_id` like %d ", query, filter.teamId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.nMark)
	{
		sprintf(tmp, "%sand `mark` = %d ", query, filter.nMark);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipJudgesMarkTable::Find(tTableMap& data, const tDATA& filter)
{
	long res = UDF_E_FAIL;

	do
	{
		std::string 		szQuery;
		std::string 		szFilter;
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		szFilter = GetFilterString(filter);
		szQuery = GetQuery(TABLE, szFilter);
		qRes = m_pConnection->ExecuteQuery(szQuery);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		data.clear();

		while( qRes && qRes->next())
		{
			tDATA el = {0};

			el.id = qRes->getUInt64("id");
            el.tourId = qRes->getUInt64("tour_id");
            el.judgeId = qRes->getUInt64("judge_id");
            el.teamId = qRes->getUInt64("team_id");
            el.nMark = qRes->getInt("mark");

			data.insert(make_pair(el.id, el));
		}

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

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

        sprintf(query, "insert into %s(`tour_id`, `judge_id`, `team_id`, `mark`)"
			" values(%d, %d, %d, %d)"
            , TABLE
            , rec.tourId
            , rec.judgeId
            , rec.teamId
            , rec.nMark
			);
        res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
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
		res = m_pConnection->Execute(query);
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
		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		data.id = qRes->getUInt64("id");
		data.tourId = qRes->getUInt64("tour_id");
		data.judgeId = qRes->getUInt64("judge_id");
		data.teamId = qRes->getUInt64("team_id");
		data.nMark = qRes->getInt("mark");

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

		if (0 != data.tourId)
		{
			sprintf(tmp, "%s `tour_id` = %d,", query, data.tourId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.judgeId)
		{
			sprintf(tmp, "%s `judge_id` = %d,", query, data.judgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.teamId)
		{
			sprintf(tmp, "%s `team_id` = %d,", query, data.teamId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.nMark)
		{
			sprintf(tmp, "%s `mark` = %d,", query, data.nMark);
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


long CChampionshipJudgesMarkTable::FindId(unsigned int& id, const tDATA& filter)
{
	long res = UDF_E_FAIL;

	do
	{
		std::string 		szQuery;
		std::string 		szFilter;
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		szFilter = GetFilterString(filter) + " limit 1";
		szQuery = GetQuery(TABLE, szFilter);
		qRes = m_pConnection->ExecuteQuery(szQuery);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		if(!qRes->next())
		{
			res = UDF_E_NOTFOUND;
			break;
		}

		id = qRes->getUInt("id");

		res = UDF_OK;
	}while(0);

	return res;
}
