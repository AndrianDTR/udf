#include "tjudgescategorieshave.h"

#define	TABLE	TABLE_JUDGESCATEGORIESHAVE

CJudgesCategoriesHaveTable::CJudgesCategoriesHaveTable(CDbConnection* pCon)
: CDbTable(pCon)
, m_pConnection(pCon)
{
}

CJudgesCategoriesHaveTable::~CJudgesCategoriesHaveTable(void)
{
}

std::string CJudgesCategoriesHaveTable::GetTableName()
{
	return TABLE;
}

std::string CJudgesCategoriesHaveTable::GetFilterString(const tDATA* const filter)
{
	char 				query[MAX_QUERY_LEN] = {0};
	char 				tmp[MAX_QUERY_LEN] = {0};

	if (0 != filter->judgeId)
	{
		sprintf(tmp, "%sand `judge_id` like %d ", query, filter->judgeId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	if (0 != filter->judCatId)
	{
		sprintf(tmp, "%sand `cat_id` like %d ", query, filter->judCatId);
		strncpy(query, tmp, MAX_QUERY_LEN-1);
	}

	return string(query);
}

long CJudgesCategoriesHaveTable::Find(tTableMap& data, const tDATA* const filter)
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

			el.id = qRes->getUInt("id");
			el.judgeId = qRes->getUInt("judge_id");
			el.judCatId = qRes->getUInt("cat_id");

			data.insert(make_pair(el.id, el));
		}

		res = UDF_OK;
	}while(0);

	return res;
}

long CJudgesCategoriesHaveTable::AddRow(tDATA& rec)
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

		sprintf(query, "insert into %s(`judge_id`,`cat_id`) values(%d, %d)"
			, TABLE
			, rec.judgeId
			, rec.judCatId);
		res = m_pConnection->Execute(query);

		rec.id = m_pConnection->GetLastInsertId();

	}while(0);

	return res;
}

long CJudgesCategoriesHaveTable::DelRow(unsigned int nId)
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

long CJudgesCategoriesHaveTable::GetRow(unsigned int nId, tDATA& data)
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
		data.judgeId = qRes->getUInt("judge_id");
		data.judCatId = qRes->getUInt("cat_id");

		res = UDF_OK;
	}while(0);

	return res;
}

long CJudgesCategoriesHaveTable::UpdateRow(unsigned int nId, const tDATA& data)
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

		if (data.judgeId != -1)
		{
			sprintf(tmp, "%s `judge_id` = %d,", query, data.judgeId);
			strncpy(query, tmp, MAX_QUERY_LEN-1);
			useFilter = true;
		}

		if (data.judCatId != -1)
		{
			sprintf(tmp, "%s `cat_id` = %d,", query, data.judCatId);
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
