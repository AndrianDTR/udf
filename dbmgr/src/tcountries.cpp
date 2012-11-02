#include "tcountries.h"

#define	TABLE	TABLE_COUNTRIES

CCountriesTable::CCountriesTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CCountriesTable::~CCountriesTable(void)
{
}

std::string CCountriesTable::GetTableName()
{
	return TABLE;
}

std::string CCountriesTable::GetFilterString(const tDATA* const filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (!filter->name.empty())
	{
		sprintf(tmp, "%sand `name` like '%%%s%%' ", query, filter->name.c_str());
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CCountriesTable::Find(tTableMap& data, const tDATA* const filter)
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
		szQuery = GetQuery(GetTableName().c_str(), szFilter);
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

			el.id = qRes->getInt(1);
			el.name = qRes->getString(2);

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CCountriesTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`name`) values('%s')", TABLE, rec.name.c_str());
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();
	}while(0);

	return res;
}

long CCountriesTable::DelRow(unsigned int nId)
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

long CCountriesTable::GetRow(unsigned int nId, tDATA& data)
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
		data.id = qRes->getInt(1);
		data.name = qRes->getString(2);

		res = UDF_OK;
	}while(0);

	return res;
}

long CCountriesTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		sprintf(query, "update %s set `name`='%s' where id = %d", TABLE, data.name.c_str(), nId);
		res = m_pConnection->Execute(query);

	}while(0);

	return res;
}
