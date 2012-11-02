#include "dbtable.h"

void CDbTable::AddOrder(std::string szName, tSORT_TYPE sort /*= ST_NONE*/)
{
	tORDER	field = {szName, sort};
	m_OrderMap.push_back(field);
}

void CDbTable::ClearOrder()
{
	m_OrderMap.clear();
}

std::string CDbTable::GetOrderString()
{
	std::string res;

	do
	{
		if(m_OrderMap.size() == 0)
			break;

		res += " order by ";

		tOrderIt it = m_OrderMap.begin();

		while(it != m_OrderMap.end())
		{
			tORDER& data = *it;
			if(data.sort == ST_NONE)
				continue;

			res += "`" + data.szName + "`";
			res += data.sort == ST_ASCENDING ? " ASC, " : " DESC, ";
			it++;
		}
		res += " `id` ASC ";

	}while(0);
	return res;
}

std::string CDbTable::GetFieldList()
{
	std::string res;

	do
	{
		// This mechanism is not completed yet
		//if(m_OrderMap.size() == 0)
		{
			res = "*";
			break;
		}

		tOrderIt it = m_OrderMap.begin();
		res = "`id`";
		while(it != m_OrderMap.end())
		{
			tORDER& data = *it;
			res += ", `" + data.szName + "`";
		}

	}while(0);
	return res;
}

std::string CDbTable::GetQuery(const char* table, const std::string& szFilter)
{
		char 				query[MAX_QUERY_LEN] = {0};

		if(!szFilter.empty())
		{
			sprintf(query, "select %s from %s where 1=1 %s %s"
			, "*"	//GetFieldList().c_str()
			, table
			, szFilter.c_str()
			, GetOrderString().c_str());
		}
		else
		{
			sprintf(query, "select %s from %s %s"
			, "*"	//GetFieldList().c_str()
			, table
			, GetOrderString().c_str());
		}

		return std::string(query);
}

long CDbTable::FindId(unsigned int& id, const tDATA* const filter)
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
		szQuery = GetQuery(GetTableName().c_str(), szFilter);
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
