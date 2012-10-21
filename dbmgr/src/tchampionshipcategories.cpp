
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

std::string CChampionshipCategoriesTable::GetTableName()
{
	return TABLE;
}

long CChampionshipCategoriesTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CChampionshipCategoriesTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter.catId)
	{
		sprintf(tmp, "%sand `category_id` like %d ", query, filter.catId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.championshipId)
	{
		sprintf(tmp, "%sand `championship_id` like %d ", query, filter.championshipId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipCategoriesTable::Find(tTableMap& data, const tDATA& filter)
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
