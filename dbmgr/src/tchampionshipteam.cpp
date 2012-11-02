#include "tchampionshipteam.h"

#define	TABLE	TABLE_CHAMPIONSHIPTEAM

CChampionshipTeamsTable::CChampionshipTeamsTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTeamsTable::~CChampionshipTeamsTable(void)
{
}

std::string CChampionshipTeamsTable::GetTableName()
{
	return TABLE;
}

std::string CChampionshipTeamsTable::GetFilterString(const tDATA* const filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter->championshipId)
	{
		sprintf(tmp, "%sand `championship_id` like %d ", query, filter->championshipId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->clubId)
	{
		sprintf(tmp, "%sand `club_id` like %d ", query, filter->clubId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->startNumber)
	{
		sprintf(tmp, "%sand `start_number` like %d ", query, filter->startNumber);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipTeamsTable::Find(tTableMap& data, const tDATA* const filter)
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
			el.championshipId = qRes->getUInt(2);
			el.clubId = qRes->getUInt(3);
			el.name = qRes->getString(4);
			el.startNumber = qRes->getUInt(5);

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamsTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`championship_id`,`club_id`,`name`,`start_number`) values(%d,%d,'%s',%d)"
		, TABLE
		, rec.championshipId
		, rec.clubId
		, rec.name.c_str()
		, rec.startNumber);
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CChampionshipTeamsTable::DelRow(unsigned int nId)
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

long CChampionshipTeamsTable::GetRow(unsigned int nId, tDATA& data)
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
		data.championshipId = qRes->getUInt(2);
		data.clubId = qRes->getUInt(3);
		data.name = qRes->getString(4);
		data.startNumber = qRes->getUInt(5);

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTeamsTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (data.clubId != -1)
		{
			sprintf(tmp, "%s `club_id` = %d,", query, data.clubId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (data.championshipId != -1)
		{
			sprintf(tmp, "%s `championship_id` = %d,", query, data.championshipId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (data.startNumber != -1)
		{
			sprintf(tmp, "%s `start_number` = %d,", query, data.startNumber);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
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

