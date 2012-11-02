#include "tchampionshipteamdancers.h"

#define	TABLE	TABLE_CHAMPIONSHIPTEAMDANCERS

CChampionshipTeamDancersTable::CChampionshipTeamDancersTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTeamDancersTable::~CChampionshipTeamDancersTable(void)
{
}

std::string CChampionshipTeamDancersTable::GetTableName()
{
	return TABLE;
}

std::string CChampionshipTeamDancersTable::GetFilterString(const tDATA* const filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter->teamId)
	{
		sprintf(tmp, "%sand `team_id` like %d ", query, filter->teamId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->dancerId)
	{
		sprintf(tmp, "%sand `dancer_id` like %d ", query, filter->dancerId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipTeamDancersTable::Find(tTableMap& data, const tDATA* const filter)
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
			tDATA el;

			el.id = qRes->getUInt(1);
			el.teamId = qRes->getUInt(2);
			el.dancerId = qRes->getUInt(3);

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamDancersTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`team_id`, `dancer_id`) values(%d,%d)"
			, TABLE
			, rec.teamId
			, rec.dancerId);
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CChampionshipTeamDancersTable::DelRow(unsigned int nId)
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

long CChampionshipTeamDancersTable::GetRow(unsigned int nId, tDATA& data)
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
		data.teamId = qRes->getUInt(2);
		data.dancerId = qRes->getUInt(3);

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamDancersTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (data.dancerId != -1)
		{
			sprintf(tmp, "%s `dancer_id` = %d,", query, data.dancerId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (data.teamId != -1)
		{
			sprintf(tmp, "%s `team_id` = %d,", query, data.teamId);
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
