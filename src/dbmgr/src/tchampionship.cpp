#include "tchampionship.h"

#define	TABLE	TABLE_CHAMPIONSHIP

CChampionshipTable::CChampionshipTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CChampionshipTable::~CChampionshipTable(void)
{
}

std::string CChampionshipTable::GetTableName()
{
	return TABLE;
}

long CChampionshipTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CChampionshipTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (!filter.name.empty())
	{
		sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.date)
	{
		sprintf(tmp, "%sand `date` like '%%%s%%' ", query, date2str(filter.date).c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.regOpenDate)
	{
		sprintf(tmp, "%sand `reg_open` like '%%%s%%' ", query, date2str(filter.regOpenDate).c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.regCloseDate)
	{
		sprintf(tmp, "%sand `reg_close` like '%%%s%%' ", query, date2str(filter.regCloseDate).c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.additionalInfo.empty())
	{
		sprintf(tmp, "%sand `additional_info` like '%%%s%%' ", query, filter.additionalInfo.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.address.empty())
	{
		sprintf(tmp, "%sand `address` like '%%%s%%' ", query, filter.address.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.city)
	{
		sprintf(tmp, "%sand `city` like %d ", query, filter.city);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter.type)
	{
		sprintf(tmp, "%sand `type` like %d ", query, filter.type);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CChampionshipTable::Find(tTableMap& data, const tDATA& filter)
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

		res = ParseResult(qRes, data);
	}while(0);

	return res;
}

long CChampionshipTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`type`, `name`, `additional_info`, `city`, \
		`address`, `date`, `reg_open`, `reg_close`) values(%d, '%s', '%s', %d, '%s','%s','%s','%s')"
		, TABLE
		, rec.type
		, rec.name.c_str()
		, rec.additionalInfo.c_str()
		, rec.city
		, rec.address.c_str()
		, date2str(rec.date).c_str()
		, date2str(rec.regOpenDate).c_str()
		, date2str(rec.regCloseDate).c_str()
		);
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();

	}while(0);

	return res;
}

long CChampionshipTable::DelRow(unsigned int nId)
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

long CChampionshipTable::GetRow(unsigned int nId, tDATA& data)
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
		data.type = qRes->getInt(2);
		data.name = qRes->getString(3);
		data.additionalInfo  = qRes->getString(4);
		data.city = qRes->getUInt(5);
		data.address = qRes->getString(6);
		data.date = str2date(qRes->getString(7));
		data.regOpenDate = str2date(qRes->getString(8));
		data.regCloseDate = str2date(qRes->getString(9));

		res = UDF_OK;
	}while(0);

	return res;
}

long CChampionshipTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.type)
		{
			sprintf(tmp, "%s `type` = %d,", query, data.type);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.city)
		{
			sprintf(tmp, "%s `city` = %d,", query, data.city);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.additionalInfo.empty())
		{
			sprintf(tmp, "%s `additional_info` = '%s',", query, data.additionalInfo.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.address.empty())
		{
			sprintf(tmp, "%s `address` = '%s',", query, data.address.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.date)
		{
			sprintf(tmp, "%s `date` = '%s',", query, date2str(data.date).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.regOpenDate)
		{
			sprintf(tmp, "%s `reg_open` = '%s',", query, date2str(data.regOpenDate).c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (0 != data.regCloseDate)
		{
			sprintf(tmp, "%s `reg_close` = '%s',", query, date2str(data.regCloseDate).c_str());
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

long CChampionshipTable::ExecuteQuery(string query, tTableMap& data)
{
	long res = UDF_E_FAIL;

	do
	{
		sql::ResultSet*		qRes = NULL;

		if(! m_pConnection)
		{
			res = UDF_E_NOCONNECTION;
			break;
		}

		qRes = m_pConnection->ExecuteQuery(query);
		if(!qRes)
		{
			res = UDF_E_EXECUTE_QUERY_FAILED;
			break;
		}

		res = ParseResult(qRes, data);

	}while(0);

	return res;
}

long CChampionshipTable::ParseResult(void* pRes, tTableMap& data)
{
	long res = UDF_E_FAIL;

	do
	{
		sql::ResultSet* qRes = (sql::ResultSet*)pRes;
		data.clear();

		while( qRes && qRes->next())
		{
			tDATA el = {0};

			el.id = qRes->getUInt(1);
			el.type = qRes->getInt(2);
			el.name = qRes->getString(3);
			el.additionalInfo  = qRes->getString(4);
			el.city = qRes->getUInt(5);
			el.address  = qRes->getString(6);
			el.date = str2date(qRes->getString(7));
			el.regOpenDate = str2date(qRes->getString(8));
			el.regCloseDate = str2date(qRes->getString(9));

			data.insert(make_pair(el.id, el));
		}
		res = UDF_OK;
	}while(0);

	return res;
}
