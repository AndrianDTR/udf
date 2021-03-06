#include "tchampionshipteamcategories.h"

#define	TABLE	TABLE_CHAMPIONSHIPTEAMCATEGORIES

CChampionshipTeamCategoriesTable::CChampionshipTeamCategoriesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTeamCategoriesTable::~CChampionshipTeamCategoriesTable(void)
{
}

long CChampionshipTeamCategoriesTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CChampionshipTeamCategoriesTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter.teamId)
	{
		sprintf(tmp, "%sand `team_id` like %d ", query, filter.teamId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.csCatId)
	{
		sprintf(tmp, "%sand `category_id` like %d ", query, filter.csCatId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.lenght)
	{
		sprintf(tmp, "%sand `lenght` like %s ", query, time2str(filter.lenght).c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.compositionName.empty())
	{
		sprintf(tmp, "%sand `composition_name` like '%%%s%%' ", query, filter.compositionName.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipTeamCategoriesTable::Find(tTableMap& data, const tDATA& filter)
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

			el.id = qRes->getUInt(1);
			el.teamId = qRes->getUInt(2);
			el.csCatId = qRes->getUInt(3);
			el.compositionName = qRes->getString(4);
			el.lenght = str2time(qRes->getString(5));

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamCategoriesTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`team_id`, `category_id`, `composition_name`, `lenght`)"
			" values(%d, %d, '%s', '%s')"
			, TABLE
			, rec.teamId
			, rec.csCatId
			, rec.compositionName.c_str()
			, time2str(rec.lenght).c_str());
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CChampionshipTeamCategoriesTable::DelRow(unsigned int nId)
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

long CChampionshipTeamCategoriesTable::GetRow(unsigned int nId, tDATA& data)
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
		data.csCatId = qRes->getUInt(3);
		data.compositionName = qRes->getString(4);
		data.lenght = str2time(qRes->getString(5));

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamCategoriesTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.csCatId)
		{
			sprintf(tmp, "%s `category_id` = %d,", query, data.csCatId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.teamId)
		{
			sprintf(tmp, "%s `team_id` = %d,", query, data.teamId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.lenght)
		{
			sprintf(tmp, "%sand `lenght` like %s ", query, time2str(data.lenght).c_str());
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
