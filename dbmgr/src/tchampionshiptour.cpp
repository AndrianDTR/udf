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

std::string CChampionshipToursTable::GetTableName()
{
	return TABLE;
}

std::string CChampionshipToursTable::GetFilterString(const tDATA* const filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter->csCatId)
	{
		sprintf(tmp, "%sand `cs_cat_id` like %d ", query, filter->csCatId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->typeId)
	{
		sprintf(tmp, "%sand `type_id` like %d ", query, filter->typeId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->limit)
	{
		sprintf(tmp, "%sand `limit` like %d ", query, filter->limit);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipToursTable::Find(tTableMap& data, const tDATA* const filter)
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
            el.csCatId = qRes->getUInt(2);
			el.typeId = qRes->getUInt(3);
			el.limit = qRes->getInt(4);

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
		char query[MAX_QUERY_LEN] = {0};

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		sprintf(query, "insert into %s(`cs_cat_id`,`type_id`,`limit`)"
		" values(%d, %d, %d)"
            , TABLE
            , rec.csCatId
            , rec.typeId
			, rec.limit
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
		data.csCatId = qRes->getUInt(2);
		data.typeId = qRes->getUInt(3);
		data.limit = qRes->getInt(4);

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

		if (0 != data.csCatId)
		{
			sprintf(tmp, "%s `cs_cat_id` = %d,", query, data.csCatId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.typeId)
		{
			sprintf(tmp, "%s `type_id` = %d,", query, data.typeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}


		if (0 != data.limit)
		{
			sprintf(tmp, "%s `limit` = %d,", query, data.limit);
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
