#include "tcsblocks.h"

#define	TABLE	TABLE_CHAMPIONSHIPBLOCKS

CCsBlocksTable::CCsBlocksTable(CDbConnection* pCon)
: CDbTable(pCon)
{
}

CCsBlocksTable::~CCsBlocksTable(void)
{
}

long CCsBlocksTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CCsBlocksTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter.csId)
	{
		sprintf(tmp, "%sand `championship_id` like %d ", query, filter.csId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.order)
	{
		sprintf(tmp, "%sand `order` like %d ", query, filter.order);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.startTime)
	{
		sprintf(tmp, "%sand `start_time` like %d ", query, time2str(filter.startTime).c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.name.empty())
	{
		sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CCsBlocksTable::Find(tTableMap& data, const tDATA& filter)
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

			el.id = qRes->getUInt("id");
			el.csId = qRes->getUInt("championship_id");
			el.order = qRes->getUInt("order");
			el.name = qRes->getString("name");
			el.startTime = str2time(qRes->getString("start_time"));

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CCsBlocksTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`championship_id`, `order`, `name`, `start_time`)"
			" values(%d, %d, '%s', '%s')"
			, TABLE
			, rec.csId
			, rec.order
			, rec.name.c_str()
			, time2str(rec.startTime).c_str());
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CCsBlocksTable::DelRow(unsigned int nId)
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

long CCsBlocksTable::GetRow(unsigned int nId, tDATA& data)
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
		data.id = qRes->getUInt("id");
		data.csId = qRes->getUInt("championship_id");
		data.order = qRes->getUInt("order");
		data.name = qRes->getString("name");
		data.startTime = str2time(qRes->getString("start_time"));

		res = UDF_OK;
	}while(0);

	return res;
}

long CCsBlocksTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.csId)
		{
			sprintf(tmp, "%s `championship_id` = %d,", query, data.csId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.order)
		{
			sprintf(tmp, "%s `order` = %d,", query, data.order);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.startTime)
		{
			sprintf(tmp, "%s `start_time` = '%s',", query, time2str(data.startTime).c_str());
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
