#include "tstaff.h"

#define	TABLE	TABLE_STAFF

CStaffTable::CStaffTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CStaffTable::~CStaffTable(void)
{
}

long CStaffTable::GetTable(tTableMap& data)
{
	tDATA filter = {0};

	return Find(data, filter);
}

std::string CStaffTable::GetFilterString(const tDATA& filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};


	if (0 != filter.roleId)
	{
		sprintf(tmp, "%sand `role_id` like %d ", query, filter.roleId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.name.empty())
	{
		sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter.name.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.login.empty())
	{
		sprintf(tmp, "%sand `login` like '%%%s%%' ", query, filter.login.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (!filter.pass.empty())
	{
		sprintf(tmp, "%sand `pass` like '%%%s%%' ", query, filter.pass.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CStaffTable::Find(tTableMap& data, const tDATA& filter)
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
			el.roleId = qRes->getUInt("role_id");
			el.name = qRes->getString("name");
			el.login = qRes->getString("login");
			el.pass = qRes->getString("pass");

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CStaffTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`role_id`,`name`,`login`, `pass`)"
			" values(%d, '%s', '%s', '%s')"
			, TABLE
			, rec.roleId
			, rec.name.c_str()
			, rec.login.c_str()
			, rec.pass.c_str());
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CStaffTable::DelRow(unsigned int nId)
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

long CStaffTable::GetRow(unsigned int nId, tDATA& data)
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
		data.roleId = qRes->getUInt("role_id");
		data.name = qRes->getString("name");
		data.login = qRes->getString("login");
		data.pass = qRes->getString("pass");

		res = UDF_OK;
	}while(0);

	return res;
}

long CStaffTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (0 != data.roleId)
		{
			sprintf(tmp, "%s `role_id` = %d,", query, data.roleId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.name.empty())
		{
			sprintf(tmp, "%s `name` = '%s',", query, data.name.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.login.empty())
		{
			sprintf(tmp, "%s `login` = '%s',", query, data.login.c_str());
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (!data.pass.empty())
		{
			sprintf(tmp, "%s `pass` = '%s',", query, data.pass.c_str());
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
